function [H, z_] = SKF_update_computeJacobianOfAllFeature(passed_features, ms, X, K, q_I2C, R_S2G, p_GinS)
%{
用于iter update中，为所有通过卡方检验的feature计算jacobian和z_
%}

z_ = [];
H = [];
nof_corres = size(passed_features,1);
for i=1:nof_corres
    p_finS_i = passed_features(i,:).';
    
    [H_fi, zi_] = SKF_update_computeJacobianOfOneFeature(p_finS_i, X, K, q_I2C, R_S2G, p_GinS);
    
    %stack
    z_ = [z_; zi_];
    H = [H; H_fi];
end

end