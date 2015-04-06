function X = SKF_propagate_state(X, IMUinfo, last_IMUinfo, g_inG)
%{
Usage:
    X: q p v bg ba pic lambda
%}



%last state
[q_G2I_l , p_l,  v_l,  bias_G_l, bias_A_l ] = SKF_X_getIMUpart(X);
[w_IMU_l, acc_IMU_l]   = SKF_IMU_getWandA(last_IMUinfo);
w_l = w_IMU_l - bias_G_l;

[w_IMU, acc_IMU]   = SKF_IMU_getWandA(IMUinfo);

deltaT = IMUinfo.timestamp - last_IMUinfo.timestamp;



% 1. propagate bias
bias_G_ = bias_G_l;
bias_A_ = bias_A_l;

% 2. get turn rate   W in l+1|l
w_ = w_IMU - bias_G_; %w: l+1, 根据[MARS](215)

% 3. propagate quaternion
deltaQ = IN_getDeltaQ(deltaT, w_l, w_);
q_G2I_ = Quater_multi(deltaQ, q_G2I_l);

% 4. propagate v
R_I2G_ = transpose( Quater_2Mat(q_G2I_) );
R_G2I_l = Quater_2Mat(q_G2I_l);
R_I2G_l = transpose(R_G2I_l);

a_inG = R_I2G_*(acc_IMU-bias_A_) + g_inG

v_ = v_l + deltaT/2 * ( R_I2G_l*(acc_IMU_l-bias_A_l) + R_I2G_*(acc_IMU-bias_A_) )+ g_inG*deltaT; %这里 bias_A_ 和 bias_A_l 数值实际是一样的， 只是在概念上需要区分

% 5. propagate p
p_ = p_l + v_l*deltaT + deltaT^2/4 *( R_I2G_l*(acc_IMU_l-bias_A_l) + R_I2G_*(acc_IMU-bias_A_) ) + 0.5*g_inG*deltaT*deltaT;


%set propagated X
X = SKF_X_setIMUpart(X, q_G2I_,  p_, v_, bias_G_, bias_A_); %propagate 的成果
end


function deltaQ = IN_getDeltaQ(deltaT, w_l, w_)

%借鉴[TUM] 6.11中的 Runge-Kutta方法（其实就是直接拿来用）
q0 = [0 0 0 1]'; %deltaQ的初始值
k1 = 1/2 * Quater_omega(w_l)*q0;
k2 = 1/2 * Quater_omega( (w_l+w_)/2 )*(q0+deltaT/2*k1);
k3 = 1/2 * Quater_omega( (w_l+w_)/2 )*(q0+deltaT/2*k2);
k4 = 1/2 * Quater_omega(w_)*(q0+deltaT*k3);

deltaQ = q0 + deltaT/6 * (k1 + 2*k2 + 2*k3 + k4);

deltaQ = Quater_normalize(deltaQ);

end