function P_ = SKF_propagate_cov(P, X_, X_fl, imuInfo, last_imuInfo, Nc, g_inG)
%{
Propgate Cov
%}

deltaT = imuInfo.timestamp - last_imuInfo.timestamp;

acc_IMU = [imuInfo.accX; imuInfo.accY; imuInfo.accZ] ;

PHI = SKF_getPHI(X_,  X_fl, acc_IMU, g_inG, deltaT);

Qd = IN_getQd(PHI, Nc, deltaT);
Qd = SKF_MATH_makeSymmetric(Qd);

P_ = IN_doPropagate(P, PHI, Qd);

end

function Qd = IN_getQd(PHI, Nc, deltaT)
    Qd = deltaT/2 *( PHI*Nc*transpose(PHI) + Nc );
end


function P_ = IN_doPropagate(P_l, PHI, Qd)
    [P_l_II, P_l_IC, P_l_CC] = IN_partitionP(P_l);
    
    P_ = [PHI*P_l_II*transpose(PHI) + Qd      PHI*P_l_IC
     transpose(P_l_IC)*transpose(PHI)       P_l_CC];
 
    P_ = MAKE_SYMMETRIC(P_);

end


function [P_II, P_IC, P_CC] = IN_partitionP(P)
    %将IMU部分的cov和其他部分分开，IMU部分的cov对应着p左上角的 15x15

    Istart = 1;
    Iend = 15;

    P_II = P( Istart:Iend , Istart:Iend ); %15X15
    P_IC = P(Istart:Iend,  (Iend+1):end);
    P_CC = P( (Iend+1):end, (Iend+1):end);
    
end
