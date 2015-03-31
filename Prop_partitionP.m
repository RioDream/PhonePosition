function [P_II, P_IC, P_CC] = Prop_partitionP(P)

Debug_assertSymmetric(P);

%P = eye(15+6*N);
%P_l P包含4个部分， 由以下3个部分构成

[IMU_range,  calib_range, poses_range] = DX_getRanges();

Istart = IMU_range(1); %1
Iend = IMU_range(2); %15

P_II = P( Istart:Iend , Istart:Iend ); %15X15
P_IC = P(Istart:Iend,  (Iend+1):end);
P_CC = P( (Iend+1):end, (Iend+1):end);

end