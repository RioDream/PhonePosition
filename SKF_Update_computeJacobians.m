function J = SKF_Update_computeJacobians(X, features, K, q_I2C)
%{
Usage:
    计算jacobian
没有 pic的版本
%}

    nof_features = size(features, 1);
    J = [];
    for i=1:nof_features
        [q_G2I, p_IinG, v_IinG, bias_G, bias_A ] = SKF_X_getIMUpart(X);
        [p_IinC, lambda] = SKF_getOtherPart(X);
        
        R_I2C = Quater_2Mat(q_I2C);
        R_G2I = Quater_2Mat(q_G2I);

        p_finG = features(i, :).';
        p_finC = R_I2C * R_G2I * (p_finG - p_IinG) + p_IinC;

        Ji_h =  IN_getJh(p_finC, K);

        Ji_theta = R_I2C * R_G2I * skew_symmetric(p_finG-p_IinG);
        Ji_p = -R_I2C * R_G2I;
        Ji_pic = eye(3);

        %组合
        Ji_f = [Ji_theta, Ji_p, zeros(3,3), zeros(3,3), zeros(3,3), Ji_pic];
        Ji = Ji_h * Ji_f;
        J = [J; Ji];
    end
    
    
    
    
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