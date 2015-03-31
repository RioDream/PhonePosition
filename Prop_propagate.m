function Prop_propagate_state()
%{

%}


%X
[q_G2I_l , p_l, v_l, bias_G_l, bias_A_l ] = X_getIMUpart(X);


% 1. propagate bias
bias_G_ = bias_G_l;
bias_A_ = bias_A_l;

% 2. get turn rate   W in l+1|l
w_ = w_IMU - bias_G_; %w: l+1, 根据[MARS](215)

% 3. propagate quaternion
deltaQ = Prop_getDeltaQ(deltaT, w_l, w_);
q_G2I_ = Quater_multi(deltaQ, q_G2I_l);

% 4. propagate v
R_I2G_ = transpose( Quater_2Mat(q_G2I_) );
R_G2I_l = Quater_2Mat(q_G2I_l);
R_I2G_l = transpose(R_G2I_l);
v_ = Prop_propagate_v(v_l, R_I2G_l,R_I2G_, acc_IMU_l, acc_IMU,bias_A_l, bias_A_, g, deltaT); %这里 bias_A_ 和 bias_A_l 数值实际是一样的， 只是在概念上需要区分

% 5. propagate p
p_ = Prop_propagate_p(p_l, v_l, R_I2G_l, R_I2G_, acc_IMU_l, acc_IMU,bias_A_l, bias_A_, g, deltaT);

X = X_setIMUpart(X, q_G2I_,  p_, v_, bias_G_, bias_A_); %propagate 的成果




end