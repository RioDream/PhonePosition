function [X, P] = SKF_UPDATE_doEkfUpdate(X, P, features, ms, K, q_I2C, R_S2G, p_GinS, im_sigma)
%{
Usage:
    使用推导的观测模型进行update
    后面四个参数是系统参数
%}

%debug
    %初始化参数
    init_q = Quater_conj(q_I2C); %R_C2I
    init_p = [0 0 0].'; % == init_pic
    init_v = [0, 0, 0].';
    init_bg = [0 0 0].';
    init_ba = [0 0 0].';
    init_pic = [0, 0, 0].';
    init_lambda = (0.187/9.81)/2; %2个单位对应 0.135m,0.135/9.81个g
    init_X = [init_q; init_p; init_v; init_bg; init_ba; init_pic;init_lambda];
    X - init_X
mod_X = X;
mod_X(1:4) = [1;0;0;0];

assert(size(features,1)==size(ms, 1));

nof_corres = size(features,1);

nof_chisquare_fail = 0;
r = [];
H = [];
for i=1:nof_corres
    p_finS_i = features(i,:).';
    zi = ms(i, : ).';
    [H_fi, zi_] = IN_computeJacobianOfOneFeature(p_finS_i, X, K, q_I2C, R_S2G, p_GinS);
    ri = zi-zi_;
    
    isInlier = SKF_chiSquareTest(ri, H_fi, P, im_sigma);
    %if ~isInlier
    %    nof_chisquare_fail = nof_chisquare_fail + 1;
    %    continue;
    %end
    
    %stack
    r = [r; ri];
    H = [H; H_fi];
end

%disp(X);
disp( ['nof_chisquare_fail:', num2str(nof_chisquare_fail) ] );

n = size(H,1);
R = eye(n)*im_sigma^2;

if  n==0
    assert(1==2);
end
% r = Hx + noise

S = H*P*transpose(H) + R;
S = MAKE_SYMMETRIC(S);

KK = P * transpose(H) / S;
deltaX = KK*r;
disp(deltaX);
X = IN_correctX(X, deltaX);

sof_dx = size(P,1);
temp = eye(sof_dx) - KK*H;
P = (temp)*P*transpose(temp) + KK*R*transpose(KK);
P = MAKE_SYMMETRIC(P);


end



function [J, z_] = IN_computeJacobianOfOneFeature(p_finS, X, K, q_I2C, R_S2G, p_GinS) 
%{
Usage:
    计算一个feature的观测对于 \tilde{X} 的Jabocain 
    大小为 2x19

    后面4个都是系统参数
%}


     [q_G2I, p_IinG, v_IinG, bias_G, bias_A ] = SKF_X_getIMUpart(X);
     [p_IinC, lambda] = SKF_getOtherPart(X);

    R_I2C = Quater_2Mat(q_I2C);
    R_G2I = Quater_2Mat(q_G2I);

    %% feature转换到camera坐标系下
    p_finG = lambda*R_S2G*(p_finS - p_GinS);
    p_finC = R_I2C * R_G2I * (p_finG - p_IinG) + p_IinC;

    %% 计算 \hat{z}
    z_ = IN_getEstimateMeasure(p_finC, K);

 
    %% 计算Jacobian
    Jh =  IN_getJh(p_finC, K);
 
    J_theta = R_I2C * R_G2I * skew_symmetric(p_finG-p_IinG);
    %J_theta = R_I2C * skew_symmetric(R_G2I * (p_finG-p_IinG));
    J_p = -R_I2C * R_G2I;
    J_pic = eye(3); 
    J_lambda = R_I2C * R_G2I * R_S2G *(p_finS - p_GinS);
    
    J_f = [J_theta, J_p, zeros(3,3), zeros(3,3), zeros(3,3), J_pic , J_lambda];

    J = Jh * J_f;
 

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

function z_ = IN_getEstimateMeasure(p_finC, K)
%{
Usage：
    由投影模型， 计算估计的z
%}
fx = K(1,1);
fy = K(2,2);
ox = K(1,3);
oy = K(2,3);

X = p_finC(1);
Y = p_finC(2);
Z = p_finC(3);

z_ = [ox; oy] + [fx, 0; 0, fy] * [X/Z; Y/Z];
end

function X = IN_correctX(X, deltaX)

    assert(length(deltaX)==19);

    [q, p, v, bg, ba] = SKF_X_getIMUpart(X);
    [pic , lambda] = SKF_getOtherPart(X);

    theta = deltaX(1:3);
    delta_p = deltaX(4:6);
    delta_v = deltaX(7:9);
    delta_bg = deltaX(10:12);
    delta_ba = deltaX(13:15);
    delta_pic = deltaX(16:18);
    delta_lambda = deltaX(19);

    %convert theta to deltaQ
    bq = 0.5*theta;
    if norm(bq)<1.0
        deltaQ =  [bq; sqrt(1.0 - bq.'*bq)] ; %!! bq.'*bq 不是norm(bq)，而是其平方
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



