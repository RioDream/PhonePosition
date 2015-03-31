%Scale Kalman Filter
%{
    状态向量：(和MSCKF前面保持一致)
        X = [q p v bg ba pic lambda]
%}

%load data
IMUdata = {};
frames = {};


%系统参数
q_I2C = [-1 0 0 0].';


%初始化参数
init_q = [0 0 0 1].';
init_p = [0 0 0].';
init_v = [0 0 0].';
init_bg = [0 0 0].';
init_ba = [0 0 0].';
init_pic = [0 0 0].';
init_lambda = 1;


init_q_cov = 0.01;
init_p_cov = 0.01;
init_v_cov = 0.01;
init_bg_cov = 0.01;
init_ba_cov = 0.01;
init_pic_cov = 0.01;
init_lambda_cov = 0.01;

%% 初始化
%初始化状态
X = [init_q; init_p; init_v; init_bg; init_ba; init_pic; init_lambda];
%初始化协方差
P = blkdiag(init_q_cov*eye(3), init_p_cov*eye(3), init_v_cov*eye(3), init_bg_cov*eye(3), init_ba_cov*eye(3), init_pic_cov*eye(3), init_lambda_cov*eye(3));



%开始前的准备
init_IMUinfo = IMUdata(1);
IMU_timestamp_l = init_IMUinfo.timestamp;
[w_IMU_l, acc_IMU_l] = IMU_getWandA(init_IMUinfo);

w_l = w_IMU_l-bias_G_l;  %这个应该是 l时刻 w的后验值，不在状态变量中，但是对于计算有用, 见 [MARS](242)

Nof_frames = length(frames);
Nof_IMU_frames = length(IMUdata);
frame_idx = 1;
IMU_idx = 2; %从第二个IMU帧开始, 第一个已经作为初始值了

IMU_timestamp = IMUdata(1).timestamp;

while IMU_idx < Nof_IMU_frames
    IMUInfo = IMUdata(IMU_idx);

    IMU_timestamp = IMUInfo.timestamp;

    if IMU_timestamp <= frame_timestamp
        [w_IMU, acc_IMU]   = IMU_getWandA(IMUInfo);
        deltaT = IMU_timestamp - IMU_timestamp_l ;   
        assert( Debug_isNearlyEqual(deltaT, 0.01) ); %确保时间每次都更新了
        
        SKF_PROP_propagate();

    end


    if Debug_isNearlyEqual(IMU_timestamp, frame_timestamp)%IMU_timestamp == frame_timestamp %如果还等于， 就需要进行更新
        
       
        disp( [' #', num2str(frame_idx),' @ ', num2str(frame_timestamp), ': use frame ', frameInfo.name ,' to update...']);
        
        frameInfo = frames{frame_idx}; 

        %first 
        [t_q_G2I, t_p,t_v, t_bias_G, t_bias_A ] = X_getIMUpart(X);
        firstEstimated_PIinG_arr = FE_appendPosePosition(firstEstimated_PIinG_arr, t_p);

        [features, ms] = Proc_getCorrespondences();

        [X, P] = SKF_UPDATE_doEkfUpdate(X, P, features, ms);
    end

end

