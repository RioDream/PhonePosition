function [X, P] = SKF_doIterEKFupdate(X, P, features, ms, K, q_I2C, im_sigma)

MAX_ITER = 5;

assert(size(features,1)==size(ms, 1));
nof_corres = size(features,1);

%chisquare
[q_G2I, p_IinG, v_IinG, bias_G, bias_A ] = SKF_X_getIMUpart(X);
[p_IinC, lambda] = SKF_getOtherPart(X);
R_I2C = Quater_2Mat(q_I2C);
R_G2I = Quater_2Mat(q_G2I);

nof_chisquare_fail  = 0;
passed_features = [];
passed_z = [];
for i=1:nof_corres
    zi = ms(i, :).';
    %convert to f_inC
    p_finG = features(i, :).';
    p_finC = R_I2C * R_G2I * (p_finG - p_IinG) + p_IinC;
 
    %% 计算 Jacobian
    Ji_h =  IN_getJh(p_finC, K);

    Ji_theta = R_I2C * R_G2I * skew_symmetric(p_finG-p_IinG);
    Ji_p = -R_I2C * R_G2I;
    Ji_pic = eye(3);

    %组合
    Ji_f = [Ji_theta, Ji_p, zeros(3,3), zeros(3,3), zeros(3,3), Ji_pic];
    Hi = Ji_h * Ji_f;
        
    %% 计算 \hat{z}
    Zi = K * p_finC;
    zi_ = Zi(1:2)/Zi(3);
    ri = zi - zi_;
    
    
    isInlier = SKF_chiSquareTest(ri, Hi, P, im_sigma);
    if isInlier
        passed_features = [passed_features; features(i,:)];
        passed_z = [passed_z; zi];
    else
        nof_chisquare_fail = nof_chisquare_fail + 1;
    end
end

nof_passed_corres = size(passed_features,1);
R = eye(2*nof_passed_corres)*im_sigma;

if nof_chisquare_fail > 0 
    disp(['*卡方失败：', num2str(nof_chisquare_fail)]);
end

%
X_0 = X;
deltaX_0 = zeros(18,1);

X_j = X_0;
deltaX_j = deltaX_0;

j = 1;
J_j_1 = 0; % J_{j-1}
while 1

    % get H by X_j
    H_j = SKF_Update_computeJacobians(X_j, passed_features, K, q_I2C);
    
    % get eta_j 
    z_j_ = SKF_Update_getEstimateZ(X_j, passed_features, K, q_I2C);
    r_j = passed_z - z_j_;
    eta_j = r_j + H_j * deltaX_j;
    
    %(3) 计算 kalman gain
    S_j = H_j * P * transpose(H_j) + R;
    K_j = P * transpose(H_j) / S_j;
    
    %(4) correct X
    deltaX_j = K_j * eta_j;
    X_j = IN_correctX(X, deltaX_j, 1);

    
    %evalute whether to break
    deltax = IN_getDelta(X, X_j);
    J_j = transpose(deltax) * inv(P) * deltax + transpose(r_j) * inv(R) * r_j;
    

    
    disp(J_j);
    if J_j<max([0.01, 0.001*J_j_1]) || j>=MAX_ITER %不论如何，要保证退出的时候 X和P都是由Sj和Kj导出的
        X = X_j;
        
        S = S_j;
        K = K_j;
        P = P - K*S*transpose(K);
        break
    end
    
    J_j_1 = J_j;
    j = j+1;
end



end %main function

function eta = IN_calcEta(H_j, r_j, deltaX_j )
    eta = r_j + H_j * deltaX_j;
end


function deltax = IN_getDelta(X, X_j)
    [q, p, v, bg, ba] = SKF_X_getIMUpart(X);
    [qj, pj, vj, bgj, baj ] = SKF_X_getIMUpart(X_j);
    [pic, lambda] = SKF_getOtherPart(X);
    [pic_j, lambda] = SKF_getOtherPart(X_j);
    
    deltaQ = Quater_multi( qj , Quater_conj(q));
    
    assert(abs(deltaQ(4)-1)<0.0001, num2str(deltaQ(4)) );
    
    theta = 2*deltaQ(1:3);
    delta_p = p - pj;
    delta_v = v - vj;
    delta_bg = bg - bgj;
    delta_ba = ba - baj;
    delta_pic = pic - pic_j;
    
    deltax = [theta; delta_p; delta_v; delta_bg; delta_ba; delta_pic];
end



function X = IN_correctX(X, deltaX, NO_LAMBDA)

if NO_LAMBDA
    assert(length(deltaX)==18);
else
    assert(length(deltaX)==19);
end

[q, p, v, bg, ba] = SKF_X_getIMUpart(X);
[pic , lambda] = SKF_getOtherPart(X);

theta = deltaX(1:3);
delta_p = deltaX(4:6);
delta_v = deltaX(7:9);
delta_bg = deltaX(10:12);
delta_ba = deltaX(13:15);
delta_pic = deltaX(16:18);

if NO_LAMBDA
    delta_lambda = 0;
else
    delta_lambda = deltaX(19);
end

%convert theta to deltaQ
bq = 0.5*theta;
if norm(bq)<1.0
    deltaQ =  [bq; sqrt(1.0 - norm(bq))] ;
else
    deltaQ = [bq; 1];
    deltaQ = deltaQ/norm(deltaQ);
end
q = Quater_multi(q, deltaQ);
p = p + delta_p;
v = v + delta_v;
bg = bg + delta_bg;
ba = ba + delta_ba;
pic = pic + delta_pic;
lambda = lambda + delta_lambda;


X = SKF_X_setIMUpart(X, q,  p, v, bg, ba);
X = SKF_setOtherPart(X, pic, lambda);
end


function Jh = IN_getJh(p_finG, K)
%{
得到 J_h
%}
    fx = K(1,1);
    fy = K(2,2);
    x = p_finG(1);
    y = p_finG(2);
    z = p_finG(3);
    left = [fx, 0; 0, fy] ;
    right = [1/z, 0, -x/(z*z); 0 , 1/z, -y/(z*z)];
    Jh = left * right; 
end







