close all;

idx = 6;
infoDir = ['./SKF_data/',num2str(idx),'/'];

%load IMU timestamps
t2f_filePath = [infoDir, 'img2time.txt'];
load([infoDir, 'IMUdata.mat']);
IMU_timestamps = [];
for i=1:length(IMUdata)
    IMUinfo = IMUdata(i);
    IMU_timestamps = [IMU_timestamps, IMUinfo.timestamp];
end
IMU_timestamps = IMU_timestamps - IMU_timestamps(1);

%load frame timestamps
t2fs = Utils_loadTimestamp2Frameidx(t2f_filePath);
frame_timestamps = t2fs(:,1);
frame_timestamps = frame_timestamps - frame_timestamps(1); 

%% load visual result 
nof_frames = 1325;
MAKE_LAMBDA_ONE_SCALE = 0.019062181447503; 
[pCinSs, R_S2Cs] = Utils_load_pCinSs(infoDir, nof_frames);
pCinSs = pCinSs*MAKE_LAMBDA_ONE_SCALE;
pCinSs_V = pCinSs; 

%cut 
ratio = 5.1; %frames / imus
SAMPLES = size(ps,2);
num = SAMPLES /ratio;
pCinSs_V_ = pCinSs_V(:,1:num);
frame_timestamps = frame_timestamps(1:num);
IMU_timestamps = IMU_timestamps(1:SAMPLES);

%% load IMU result 
load('./EX_data/pIinSs.mat');
load('./EX_data/R_I2Ss.mat');
R_I2C = Quater_2Mat([-1 0 0 0]);
p_IinC = [0, 0.00656, 0].';

ps_ = ps(:,1:end);
nof_ps = size(ps_, 2);
pCinSs_I_ = [];
for i=1:nof_ps
    p_IinS = ps_(: , i);
    R_I2S = Rs{i};
    R_C2S = R_I2S*transpose(R_I2C);
    p_CinS = p_IinS - R_C2S*p_IinC;
    pCinSs_I_ = [pCinSs_I_,  p_CinS];
end

%% plot both traj
%EX_plotBothTraj(pIinSs_V_, ps_ );


%% plot axis 
clr = [0.8 0.3 0];

%% X
figure;
plot(frame_timestamps, pCinSs_V_(1,:), 'x','Color', clr,'MarkerSize',5);
hold on;
plot(IMU_timestamps, pCinSs_I_(1,:), 'r');
legend('求解PNP获取的轨迹x坐标', '所设计的滤波器生成的轨迹x坐标');
xlabel('时间/秒');
ylabel('幅值');

%% Y
figure;
plot(frame_timestamps, pCinSs_V_(2,:), 'x','Color',clr,'MarkerSize',5);
hold on;
plot(IMU_timestamps, pCinSs_I_(2,:), 'g');
legend('求解PNP获取的轨迹y坐标', '所设计的滤波器生成的轨迹y坐标');
xlabel('时间/秒');
ylabel('幅值');
ylim = ([-0.025, 0.005]);

%% Z
figure;
plot(frame_timestamps, pCinSs_V_(3,:), 'x','Color',clr,'MarkerSize',5);
hold on;
plot(IMU_timestamps, pCinSs_I_(3,:), 'b');
legend('求解PNP获取的轨迹z坐标', '所设计的滤波器生成的轨迹z坐标');
xlabel('时间/秒');
ylabel('幅值');

