function z_ = SKF_Update_getEstimateZ(X, features, K, q_I2C)
%{
由状态X，得到当前的z
%}
nof_features = size(features, 1);

z_ = [];

for i=1:nof_features
    %get current state
    [q_G2I, p_IinG, v_IinG, bias_G, bias_A ] = SKF_X_getIMUpart(X);
    [p_IinC, lambda] = SKF_getOtherPart(X);
 
    R_I2C = Quater_2Mat(q_I2C);
    R_G2I = Quater_2Mat(q_G2I);
    
    %convert to f_inC
    p_finG = features(i, :).';
    p_finC = R_I2C * R_G2I * (p_finG - p_IinG) + p_IinC;

 
 
    %% 计算 \hat{z}
    Zi = K * p_finC;
    zi_ = Zi(1:2)/Zi(3);
    
    z_ = [z_; zi_];
end

end