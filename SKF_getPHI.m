function PHI = SKF_getPHI(X_,  X_fl, acc_IMU, g, deltaT)


[q_G2I_fl , p_fl, v_fl, bias_G_fl, bias_A_fl ] = SKF_X_getIMUpart( X_fl );
[q_G2I_ , p_, v_, bias_G_, bias_A_ ] = SKF_X_getIMUpart( X_ );

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