function Rotation = Quater_eular2mat(phi, theta, psi)
%{
Usage:
    类似于 quaternion library 中的 eular2rotmat.m 
    ZYX convention 的意思就是 RotationAxisZ * RotationAxisY * RotationAxisX
    
    这个脚本在 Verify_Quater2Eular.m 中有验证
%}

phi_degree = phi*180 / pi ;
theta_degree = theta*180 / pi ;
psi_degree = psi*180 / pi ;

RotationAxisX = Utils_RotationMatrix('x', phi_degree);
RotationAxisY = Utils_RotationMatrix('y', theta_degree);
RotationAxisZ = Utils_RotationMatrix('z', psi_degree);

%Z-Y-X convention
Rotation = RotationAxisZ * RotationAxisY * RotationAxisX;

end