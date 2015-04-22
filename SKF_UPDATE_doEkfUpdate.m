function [X, P] = SKF_UPDATE_doEkfUpdate(X, P, features, ms, K, q_I2C, R_S2G, p_GinS, im_sigma)
%{
Usage:
    使用推导的观测模型进行update
    后面四个参数是系统参数
%}

%debug

assert(size(features,1)==size(ms, 1));

nof_corres = size(features,1);

nof_chisquare_fail = 0;
r = [];
H = [];
for i=1:nof_corres
    p_finS_i = features(i,:).';
    zi = ms(i, : ).';
    [H_fi, zi_] = SKF_update_computeJacobianOfOneFeature(p_finS_i, X, K, q_I2C, R_S2G, p_GinS);
    ri = zi-zi_;
    
    isInlier = SKF_chiSquareTest(ri, H_fi, P, im_sigma);
    if ~isInlier
        nof_chisquare_fail = nof_chisquare_fail + 1;
        continue;
    end
    
    %stack
    r = [r; ri];
    H = [H; H_fi];
end

%disp(X);
disp( ['nof_chisquare_fail:', num2str(nof_chisquare_fail) ] );

n = size(H,1);
R = eye(n)*im_sigma^2;

if  n==0
    if nof_corres>100
        disp('【Waring】');
        %assert(1==2);
    end
    return;
end
% r = Hx + noise

S = H*P*transpose(H) + R;
S = MAKE_SYMMETRIC(S);

KK = P * transpose(H) / S;
deltaX = KK*r;
disp(deltaX);
X = SKF_update_correctX(X, deltaX);

sof_dx = size(P,1);
temp = eye(sof_dx) - KK*H;
P = (temp)*P*transpose(temp) + KK*R*transpose(KK);
P = MAKE_SYMMETRIC(P);


end





