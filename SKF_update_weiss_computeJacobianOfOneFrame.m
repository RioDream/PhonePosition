function SKF_update_weiss_computeJacobianOfOneFrame()

%{
Usage:
    weiss 中的观测模型
        Zp = R_G2S * (p_IinG + R_I2G * p_CinI)*lambda + np
        Zq = q_I2C * q_G2I * q_S2G
%}



%% Hp
J_theta = -R_G2S * lambda_* skew_symmetric(R_I2G * p_CinI);
J_p = R_G2S * lambda_;
J_lambda = R_G2S * (p_IinG + R_I2G * p_CinI);
Hp = [J_theta, J_p, zeros(3,3), zeros(3,3), zeros(3,3), J_lambda];

%% Hq
Hq = ;

end