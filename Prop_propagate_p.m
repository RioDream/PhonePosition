function p = Prop_propagate_p(pl, vl, R_I2G_l, R_I2G_, acc_IMU_l, acc_IMU,bias_A_l, bias_A_, g, deltaT)
%{
	和 propagate_v 相比 参数就多了一个 vl
    [IJRR](29) + Simpson
%}

%和 [TUM]6.30保持一致，以及之前的 propagate一致
sl_a = eye(3)  *  (acc_IMU_l-bias_A_l);  % l时刻
sl_b = transpose(R_I2G_l)*R_I2G_   *   (acc_IMU-bias_A_); % R_I2G_是l+1时刻的， R_I2G_l是l时刻的, acc_IMU、bias_A_是 l+1时刻的
sl =  simpson_integrate2(deltaT,sl_a,sl_b); %Trapezoidal

%这里和 [TUM] 6.30 一致
Ga = 0;
Gb = sl;
yl = simpson_integrate2(deltaT,Ga, Gb);

p_old = pl + vl*deltaT + R_I2G_l*yl + 0.5*g*deltaT*deltaT;

p = pl + vl*deltaT + deltaT^2/4 *( R_I2G_l*(acc_IMU_l-bias_A_l) + R_I2G_*(acc_IMU-bias_A_) ) + 0.5*g*deltaT*deltaT;

assert( abs(p(1)-p_old(1))<1e-10, 'RioError: 两种方法计算的p不一样');

end