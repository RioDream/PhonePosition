function v = Prop_propagate_v(vl, R_I2G_l,R_I2G_, acc_IMU_l, acc_IMU,bias_A_l, bias_A_, g, deltaT)

%{
    
    [IJRR](28) 使用 Simpson积分
    借鉴 [TUM] 6.30  式

    这里 bias_A 没有区分 l和 l+1时刻， 也是借鉴了 [TUM]6.30 , 
    应该是因为 l+1 时刻的先验估计和l时刻是一样的。

    应该要明确的一点是 [IJRR](28)中使用的 l和l+1等时刻的状态是先验的还是后验的
    l+1时刻的状态都是先验的，因为还没有后验状态

    另外， 这里 bias_A_ 和 bias_A_l 数值实际是一样的， 只是在概念上需要区分
%}


%有这个简单公式 R_Il+1_2_Il = R_G_2_Il * R_Il+1_2_G;

sl_a = eye(3)  *  (acc_IMU_l-bias_A_l);  % l时刻
sl_b = transpose(R_I2G_l)*R_I2G_   *   (acc_IMU-bias_A_); % R_I2G_是l+1时刻的， R_I2G_l是l时刻的, acc_IMU、bias_A_是 l+1时刻的

sl =  simpson_integrate2(deltaT,sl_a,sl_b); %Trapezoidal

v_old = vl + R_I2G_l*sl + g*deltaT;

v = vl + deltaT/2 * ( R_I2G_l*(acc_IMU_l-bias_A_l) + R_I2G_*(acc_IMU-bias_A_) )+ g*deltaT;

assert( abs(v(1)-v_old(1))<1e-10, 'RioError: 两种方法计算的v不一样');

end