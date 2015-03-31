function H = SKF_update_computeJacobian(X, cameraK, R_I2C, roll, pitch)
%{
Usage:
    计算 EKF 的 Jacobian 矩阵
%}

[p_, phi_, v_, w_, lambda_] = X_getParts(X);

%!!!
R_w2I = Utils_RotationMatrix('x', roll) * Utils_RotationMatrix('y', pitch) * Utils_RotationMatrix('z', phi_);

%计算 R_w2I 相对于 phi 的Jacobian
 R3 = [-sin(phi) cos(phi) 0;
     -cos(phi) -sin(phi) 0;
     0      0       0];
J_Rw2i_phi =  Utils_RotationMatrix('x', roll) * Utils_RotationMatrix('y', pitch) * R3;

H_p = - cameraK * R_I2C * R_w2I_;
H_lambda = cameraK * R_I2C * R_w2I_ * R_s2w*( - p_w_inS +  p_fi_inS);
H_phi = cameraK * R_I2C * J_Rw2i_phi * (lambda_* R_s2w*( - p_w_inS +  p_fi_inS) - p_c_inW);

%!!! add j

H = [H_p, H_phi,  0,0,0 , 0, H_lambda];


end