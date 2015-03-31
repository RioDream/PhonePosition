%{
Usage:
    estimate scale factor 

    X: p phi v w lambda
%}

%% Init
p_init = [0,0,0];
phi_init = 0;
v_init = [0,0,0];
w_init = 0;
lambda_init = 1 ; 


p_cov_init = [1,1,1];
phi_cov_init = 1;
v_cov_init = [1,1,1];
w_cov_init = 1;
lambda_cov_init = 1;

sigma_nv = 1;
sigma_nw = 1;

X = [p_init, phi_init, v_init, w_init, lambda_init].' ;
P = blkdiag(p_cov_init(1), p_cov_init(2), p_cov_init(3), phi_cov_init, v_cov_init(1), v_cov_init(2), v_cov_init(3), w_cov_init, lambda_cov_init);

%% main flow
frameDir = '';
IMUPath = '';
%load data
frames = SKF_loadFrames(frameDir);
IMUs= SKF_loadIMUs(IMUPath);

imuIdx = 1;
frameIdx = 1;
while True
    
    %if imuIdx or frameIdx is invalid
    %   break
    
    frameInfo  = SKF_getFrameInfoByIdx(frames, frameIdx);
    IMUInfo = SKF_getImuInfoByIdx(IMUs, imuIdx);
    
    frame_timestamp  = frameInfo.timestamp;
    IMU_timestamp = IMUInfo.timestamp;
    
    %propagate
    if( IMU_timestamp < frame_stamp)
        X = SKF_propagate_State(X); %不需要输入
        P = SKF_propagate_Cov(P, sigma_nv, sigma_nw); %需要输入两个噪声的cov
        imuIdx = imuIdx + 1;
    end
    
    %update
    if(abs(IMU_timestamp - frame_stamp)<0.000001)
         
        H = SKF_update_computeJacobian();
        S = SKF_update_getInnovation();
        K = SKF_update_getKalmanGain();
         
         X = SKF_update_State(X, K);
         P = SKF_update_Cov(P, K);
         
         frameIdx = frameIdx + 1;
    end

    
end



