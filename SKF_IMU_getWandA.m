function [w_IMU, acc_IMU] = IMU_getWandA(IMUinfo)

    w_IMU = [IMUinfo.rateX, IMUinfo.rateY, IMUinfo.rateZ]';
    acc_IMU = [IMUinfo.accX, IMUinfo.accY, IMUinfo.accZ]';

end