function PHI = Prop_getPHI(X_,  X_fl, acc_IMU, g, deltaT)
%{

PHI 是 IMU error-state vector 的 error-transition  matrix， 所以 大小是 15x15
使用 firstEstimateState计算 [IJRR] (54)


由MSCKF2.0中的 PHI的解析形式，计算除PHI
包含，bias的版本，见 IJRR Appendix A中的 （60）（61）

为何包含了bias的PHI
有积分？

严格按照 Appendix A中的式子来。

其中如果遇到多重积分的情况， 依照这样一个规则
从外到内，积分号内的部分依次以函数 G F来表示，
simpson积分的起始点和结束点都以 a,b来表示
如G在a处的取值就是 Ga， 在b处就是Gb

这里的 l1代表 l+1， 例如 p_ 代表 l+1时刻的位置p
或者使用 如果一个变量不跟 l， 就代表l+1时刻

参考[TUM] Appendix B

%}

[q_G2I_fl , p_fl, v_fl, bias_G_fl, bias_A_fl ] = X_getIMUpart( X_fl );
[q_G2I_ , p_, v_, bias_G_, bias_A_ ] = X_getIMUpart( X_ );

v_l = v_fl;
p_l = p_fl;
R_I2G_fl = transpose( Quater_2Mat(q_G2I_fl) );
R_I2G_ = transpose( Quater_2Mat(q_G2I_) ); % l+1|l

%PHI_pq & PHI_vq 直接利用 IJRR(38)式子就可以
PHI_pq = -skew_symmetric(p_ - p_l - v_l*deltaT - 0.5*g*deltaT*deltaT);
PHI_vq = -skew_symmetric(v_ - v_l - g*deltaT);


%[TUM] Appendix B
temp = R_I2G_fl  + R_I2G_;
A_inG_ = R_I2G_ * (acc_IMU - bias_A_) + g; %l+1时刻的global坐标系下的acc，  [IJRR](26)

% 1. PHI_qbg
PHI_qbg = - deltaT/2 * temp;

% 2. PHI_vbg  
PHI_vbg = deltaT*deltaT/4 * skew_symmetric(A_inG_ - g)*temp;

% 3. PHI_pbg
PHI_pbg =  deltaT/2 * PHI_vbg;

% 4. PHI_vba 就是 [IJRR]中的va
PHI_vba = PHI_qbg;

% 5. PHI_pba 就是 [IJRR]中的pa
PHI_pba = deltaT/2 * PHI_vba;


%把这些block都填到PHI中去
PHI = eye(15);
PHI(4:6,1:3) = PHI_pq;
PHI(7:9,1:3) = PHI_vq;
PHI(4:6,7:9) = deltaT*eye(3);
PHI(1:3,10:12) = PHI_qbg;
PHI(4:6,10:12) = PHI_pbg;
PHI(7:9,10:12) = PHI_vbg;
PHI(4:6,13:15) = PHI_pba;
PHI(7:9,13:15) = PHI_vba;

end