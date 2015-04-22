close all;

idx = 6;

infoDir = ['./SKF_data/',num2str(idx),'/'];
t2f_filePath = [infoDir, 'img2time.txt'];
load([infoDir, 'IMUdata.mat']);
IMU_timestamps = [];
for i=1:length(IMUdata)
    IMUinfo = IMUdata(i);
    IMU_timestamps = [IMU_timestamps, IMUinfo.timestamp];
end
IMU_timestamps = IMU_timestamps - IMU_timestamps(1);
t2fs = Utils_loadTimestamp2Frameidx(t2f_filePath);
frame_timestamps = t2fs(:,1);
frame_timestamps = frame_timestamps - frame_timestamps(1); 

nof_frames = 1325;

MAKE_LAMBDA_ONE_SCALE = 0.019062181447503; 
[pCinSs, R_S2Cs] = Utils_load_pCinSs(infoDir, nof_frames);
pCinSs = pCinSs*MAKE_LAMBDA_ONE_SCALE;

R_I2C = Quater_2Mat([-1 0 0 0]);
p_IinC = [0, 0.00656, 0].';

pIinSs_V = [];
for i=1:nof_frames
    p_CinS = pCinSs(:,i);
    R_C2S = transpose(R_S2Cs{i});
    p_IinS = p_CinS + R_C2S*p_IinC;
    pIinSs_V = [pIinSs_V, p_IinS];
end

load('./EX_data/pIinSs.mat');



pIinSs_V = pIinSs_V.';
ps = ps.';

ratio = 5.1; %frames / imus
num = 4300/ratio;
pIinSs_V_ = pIinSs_V(1:num,:);
frame_timestamps = frame_timestamps(1:num);

ps_ = ps(1:ratio*num,:);

%% plot traj
EX_plotBothTraj(pIinSs_V_, ps_ );
IMU_timestamps = IMU_timestamps(1:ratio*num);

%% plot axis 
clr = [0.8 0.3 0];

%% X
figure;
plot(frame_timestamps, pIinSs_V_(:,1), 'x','Color', clr,'MarkerSize',5);
hold on;
plot(IMU_timestamps, ps_(:,1), 'r');
legend('求解PNP获取的轨迹x坐标', '所设计的滤波器生成的轨迹x坐标');
xlabel('时间/秒');
ylabel('幅值');

%% Y
figure;
plot(frame_timestamps, pIinSs_V_(:,2), 'x','Color',clr,'MarkerSize',5);
hold on;
plot(IMU_timestamps, ps_(:,2), 'g');
legend('求解PNP获取的轨迹y坐标', '所设计的滤波器生成的轨迹y坐标');
xlabel('时间/秒');
ylabel('幅值');


%% Z
figure;
plot(frame_timestamps, pIinSs_V_(:,3), 'x','Color',clr,'MarkerSize',5);
hold on;
plot(IMU_timestamps, ps_(:,3), 'b');
legend('求解PNP获取的轨迹z坐标', '所设计的滤波器生成的轨迹z坐标');
xlabel('时间/秒');
ylabel('幅值');

