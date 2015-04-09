%Scale Kalman Filter
%{
    状态向量：(和MSCKF前面保持一致)
        X = [q p v bg ba pic lambda]
        一共 20 x 1
    Error-State:
        X = [theta \tilde{p}  \tilde{v} \tilde{bg} \tilde{ba} \tilde{lambda} ]
        一共 19x1
        
     模拟实验中，{G}和{S}关系如下
    初始情况下 
            {I} 就是Z轴往上， 也就是说{G}也是这样， {C}Z轴往下
            {G}和{S}旋转一致

            可以这样理解，
                {S}是平铺在地上的pattern，z轴往上
                开始情况下，相机也是往下的
                
                {S}虚拟大小为 1x1
                lambda 为 1.5, 也就是说 {S}的实际大小为 1.5 x 1.5 米
                p_GinS = [0 0 -1] 就是说camera开始比{S}高1.5米 
        
%}
clear;
close all;
PLOT_ENV_configFigure;

MAKE_LAMBDA_ONE_SCALE = 0.019062181447503;

PLOT_SCALE = 1;
PLOT_ANIMATION = 1;
PLOT_PATTERN = 1;
if PLOT_PATTERN
    scale = MAKE_LAMBDA_ONE_SCALE ;
    fill3(scale*[0 1 1 0],scale*[0 0 0.95 0.95],[0 0 0 0],'c');
    s_ = 0.5*scale;
    quiver3(0, 0, 0, s_, 0, 0,  'r', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    quiver3(0, 0, 0, 0, s_, 0,  'g', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    quiver3(0, 0, 0, 0, 0, s_,  'b', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
end

ANALYSE_ERROR = 1;
USE_FIRST = 0;
DEBUG_ONLY_IMU = 0;
EPS = 0.00000000001;
USE_ITER_UPDATE = 0;
USE_REAL_DATA = 1;
RECORD_VALUES = 1;

if USE_REAL_DATA
    infoDir = '/Users/riodream/workspace/PhonePosition/SKF_data/2/';
    [R_S2C, p_SinC] = Utils_loadInitRandT(infoDir);
    
    %{
    IMUdata = Utils_loadIMUdata_SKF(infoDir);
    frames = Utils_loadFrameData(infoDir);
    room = Utils_loadRoom(infoDir);
    save([infoDir,'IMUdata.mat'], 'IMUdata');
    save([infoDir,'frames.mat'], 'frames');
    save([infoDir,'room.mat'], 'room');
    %}
    
    load([infoDir, 'IMUdata.mat']);
    load([infoDir, 'frames.mat']);
    load([infoDir, 'room.mat']);
    
    IMUdata(1).rateX = 0;
    IMUdata(1).rateY = 0;
    IMUdata(1).rateZ = 0;
    
    room(:,1:3) = room(:,1:3)*MAKE_LAMBDA_ONE_SCALE ; %转换到g坐标，这样lambda为1
    p_SinC = p_SinC*MAKE_LAMBDA_ONE_SCALE ;
    raw_room = room;
    
    
    %系统参数
    %开始得到的R和T分别是，R*x+t,  R_S2C, p_SinC(使用S的单位)， 需要转换得到 R_S2G, p_GinS
    R_S2G = R_S2C;
    p_GinS = -transpose(R_S2C) * p_SinC;
    q_I2C = [-1 0 0 0].';
    R_I2C = Quater_2Mat(q_I2C);
    %g_inG = R_I2C * [-0.015028, -0.639265, -0.768840].'; %1
    g_inG = R_I2C * [0.010955,-0.781036,-0.624389].'; %2
    K = [582.14339,         0,        245.61315;
                0,          587.28613 , 349.09467;
                0 ,             0 ,              1 ];
    
    %初始化参数
    init_q = Quater_conj(q_I2C); %R_C2I
    init_p = [0 0 0].'; % == init_pic
    init_v = [0, 0, 0].';
    init_bg = [0 0 0].';
    init_ba = [0 0 0].';
    init_pic = [0, 0, 0].';
    %1
    init_lambda = (0.135/9.81)/2; %2个单位对应 0.135m,0.135/9.81个g
    %2
    %init_lambda = (0.187/9.81)/1; %1个单位对应 0.187m,0.135/9.81个g
    init_lambda = 1;
    
    init_q_cov = 0.001;
    init_p_cov = 0.005;
    init_v_cov = 0.01;
    init_bg_cov = 0.01;
    init_ba_cov = 0.01;
    init_pic_cov = 0.005;
    init_lambda_cov = 0.0001;

    ratio = 5.0;
    sigma_gc = 0.001;
    sigma_ac = 0.008 * ratio;
    sigma_wgc = 0.0001;
    sigma_wac = 0.0001;
    im_sigma = 0.5;
    
else
    %load data
    load('../MSCKF/data_synthesis/IMU.mat');  % synthesis IMU
    load('../MSCKF/data_synthesis/room.mat')
    load('../MSCKF/data_synthesis/frames.mat')
    load('../MSCKF/data_synthesis/ground_truth.mat'); 

    %将room的点的坐标从 {G}转换到 {S}
    raw_room= room;
    room(:,3) = room(:,3) + 0.75;
    room(:,1:3) = 1/1.5 * room(:,1:3); %注意别把第四列的描述子搞进去
    frames(1) = [];


    %系统参数
    q_I2C = [-1 0 0 0].';
    g_inG = [0 0 -1].';
    R_S2G = eye(3);
    p_GinS = [0 0 0.5].';
    K = [584.4537400000000               0   232.8303600000000
                       0   585.9839900000000   328.5745800000000
                       0                   0                1];

    %初始化参数
    init_q = [0 0 0 1].';
    %init_p = [0.3 0 0].';
    init_p = [0 0 0].';
    %init_v = [0, 0.942477796076938, 0.450000000000000].';
    init_v = [0, 0, 0].';
    init_bg = [0 0 0].';
    init_ba = [0 0 0].';
    init_pic = [0.001, 0.001, 0].';
    init_lambda = 1.55;


    init_q_cov = 0.1;
    init_p_cov = 0.001;
    init_v_cov = 0.01;
    init_bg_cov = 0.01;
    init_ba_cov = 0.01;
    init_pic_cov = 0.01;
    init_lambda_cov = 0.03;

    ratio = 1.0;
    sigma_gc = 0.001 * ratio;
    sigma_ac = 0.008 * 1;
    sigma_wgc = 1.00000000000000e-04;
    sigma_wac = 1.00000000000000e-04;
    im_sigma = 1.1;
end

    Nc = zeros(15,15);
    Nc(1:3,   1:3) = sigma_gc^2*eye(3);
    Nc(7:9,   7:9) = sigma_ac^2*eye(3);
    Nc(10:12, 10:12) = sigma_wgc^2*eye(3);
    Nc(13:15, 13:15) = sigma_wac^2*eye(3);

%% 初始化
%初始化状态
X = [init_q; init_p; init_v; init_bg; init_ba; init_pic;init_lambda];

%初始化协方差
P = blkdiag(init_q_cov*eye(3), init_p_cov*eye(3), init_v_cov*eye(3), init_bg_cov*eye(3), init_ba_cov*eye(3), init_pic_cov*eye(3), init_lambda_cov);


%开始前的准备
init_IMUInfo = IMUdata(1);
last_IMUInfo = init_IMUInfo;

last_firstEstimated_X = X;

Nof_frames = length(frames);
Nof_IMU_frames = length(IMUdata);
frame_idx = 1;
IMU_idx = 2; %从第二个IMU帧开始, 第一个已经作为初始值了


lambdas = [];
covs = [];
errors = [];
updateFlag = false;
%Nof_IMU_frames = 1200;

while IMU_idx < Nof_IMU_frames || frame_idx<Nof_frames
 
    IMUInfo = IMUdata(IMU_idx);
    frameInfo = frames{frame_idx};

    IMU_timestamp = IMUInfo.timestamp;
    frame_timestamp = frameInfo.timestamp;
    
    Utils_compare_write(transpose(X), IMU_timestamp);
    Utils_compare_write(P, IMU_timestamp);
        

    if IMU_timestamp < frame_timestamp || Debug_isNearlyEqual(IMU_timestamp, frame_timestamp) || DEBUG_ONLY_IMU
        disp(['propagate...', num2str(IMU_idx),'  timestamp:', num2str(IMU_timestamp)]);
        if USE_FIRST
            [X, P] = SKF_PROP_propagate(X, P, last_firstEstimated_X, IMUInfo, last_IMUInfo, Nc, g_inG);
        else
            [X, P] = SKF_PROP_propagate(X, P, X, IMUInfo, last_IMUInfo, Nc, g_inG);
        end
        

        last_IMUInfo = IMUInfo;
        last_firstEstimated_X = X;
        IMU_idx = IMU_idx + 1;
    end
    
        [t_q_G2I, t_p_IinG,t_v, t_bias_G, t_bias_A ] = SKF_X_getIMUpart(X);
        t_p_IinS = (p_GinS + transpose(R_S2G)*t_p_IinG/init_lambda); %
        Plot_scalePlot(t_p_IinS, 'ro', PLOT_SCALE);
        

    if Debug_isNearlyEqual(IMU_timestamp, frame_timestamp) && ~DEBUG_ONLY_IMU 
        frameInfo = frames{frame_idx}; 
        disp( [' #', num2str(frame_idx),' @ ', num2str(frame_timestamp), ': use frame ', frameInfo.name ,' to update...']);

        %first 
        %[t_q_G2I, t_p,t_v, t_bias_G, t_bias_A ] = SKF_X_getIMUpart(X);
        %firstEstimated_PIinG_arr = FE_appendPosePosition(firstEstimated_PIinG_arr, t_p);
        
        %[features, ms, dess, gt_pfinGs] = Proc_getCorrespondences(raw_room, frameInfo, raw_room);
        [features, ms, dess, gt_pfinGs] = Proc_getCorrespondences(room, frameInfo, raw_room);

        
        %SKF_checkState(X, gt_qs(:,IMU_idx-1) ,gt_ps(:,IMU_idx-1))
        %SKF_check_corres(features, ms, dess, raw_room, frameInfo, gt_qs(:,IMU_idx-1) ,gt_ps(:,IMU_idx-1), K);
        
    
        disp(['-feature number ', num2str(size(ms,1))]);
        
        if USE_ITER_UPDATE
            %old_X= old_X(1:19);
            [X, P ] = SKF_doIterEKFupdate(X, P, features, ms, K, q_I2C, im_sigma);
        else
            %X(1:4) = gt_qs(:,IMU_idx-1) ;
            %X(5:7) = gt_ps(:,IMU_idx-1) ;
            [X, P] = SKF_UPDATE_doEkfUpdate(X, P, features, ms, K, q_I2C, R_S2G, p_GinS, im_sigma);
        end
        

        updateFlag = true;
        frame_idx = frame_idx + 1; 
    end
    

        if ANALYSE_ERROR
            %记录误差和误差协方差
            covs = ANA_extractCovFromP_And_append(covs, P);
            if ~USE_REAL_DATA
                idx = IMU_idx - 1; %idx其实是从2开始
                gt_q = [gt_qs(1, idx), gt_qs(2, idx), gt_qs(3, idx), gt_qs(4, idx)];
                gt_p = [gt_ps(1, idx), gt_ps(2, idx) ,gt_ps(3, idx)];
                gt_v = [gt_vs(1, idx), gt_vs(2, idx) ,gt_vs(3, idx)];
                gt_bg= [gt_gyro_bias(1, idx), gt_gyro_bias(2, idx) ,gt_gyro_bias(3, idx)];
                gt_ba = [gt_acc_bias(1, idx), gt_acc_bias(2, idx) ,gt_acc_bias(3, idx)];
            else
                gt_q = [0 0 0 0];
                gt_p = [0 0 0];
                gt_v = [0 0 0];
                gt_bg = [0 0 0];
                gt_ba = [0 0 0];
            end
            errors = ANA_computeErrorAndAppend(errors,  X,  gt_q, gt_p, gt_v, gt_bg, gt_ba);
            
            
        end
        
        step = 5;
        if PLOT_ANIMATION && mod(IMU_idx,step)==0
            PLOT_SCALE = 1;
            [t_q_G2I, t_p_IinG,t_v, t_bias_G, t_bias_A ] = SKF_X_getIMUpart(X);
            
            %pointHandle = pointHandles(1);
            %set(pointHandle , 'Xdata', t_p(1))
            %'Ydata', t_p(2), 'zdata', t_p(3));

            q_S2G= Quater_mat2q(R_S2G);
            t_q_S2I = Quater_multi(t_q_G2I, q_S2G); %参考坐标系转换到{S}

            t_p_IinS = (p_GinS + transpose(R_S2G)*t_p_IinG/init_lambda); %
            
            Plot_scalePlot(t_p_IinS, 'ro', PLOT_SCALE);
            if updateFlag
                Plot_scalePlot(t_p_IinS, 'g*', PLOT_SCALE);
            end
            
            quiverHandles = Plot_drawPose_useQuiverHandles(Quater_conj(t_q_S2I), PLOT_SCALE*t_p_IinS, 0, 0, 0, [], quiverHandles);

            updateFlag = false;
        end
        
    
end

disp('----')

