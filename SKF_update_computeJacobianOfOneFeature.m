function [J, z_] = SKF_update_computeJacobianOfOneFeature(p_finS, X, K, q_I2C, R_S2G, p_GinS) 
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
    z_ = SKF_update_getEstimateMeasure(p_finC, K);

 
    %% 计算Jacobian
    Jh =  SKF_update_getJh(p_finC, K);
 
    J_theta = R_I2C * R_G2I * skew_symmetric(p_finG-p_IinG);
    %J_theta = R_I2C * skew_symmetric(R_G2I * (p_finG-p_IinG));
    J_p = -R_I2C * R_G2I;
    J_pic = eye(3); 
    J_lambda = R_I2C * R_G2I * R_S2G *(p_finS - p_GinS);
    
    J_f = [J_theta, J_p, zeros(3,3), zeros(3,3), zeros(3,3), J_pic , J_lambda];

    J = Jh * J_f;
 

end