PHI = Prop_getPHI(X, last_firstEstimated_X , acc_IMU, g, deltaT);

Qd = Prop_getQd(PHI, sigma_gc, sigma_ac, sigma_wgc, sigma_wac, deltaT);
Qd = MAKE_SYMMETRIC(Qd);


%{
    P = [PHI*P_II*transpose(PHI)+Qd      PHI*P_IC
        transpose(P_IC)*transpose(PHI)  P_CC];

    lI 前者是 L后者是 i
%}
[P_l_II, P_l_IC, P_l_CC] = Prop_partitionP(P_l);
P_ = [PHI*P_l_II*transpose(PHI) + Qd      PHI*P_l_IC
     transpose(P_l_IC)*transpose(PHI)       P_l_CC];
 
P_ = MAKE_SYMMETRIC(P_);