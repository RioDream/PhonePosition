function scale = SF_getScaleFactor(idx)


USE_SEQ_INDICES = 1;

close all;
infoDir = ['./data/',num2str(idx),'/'];
t2f_filePath = [infoDir, 'img2time.txt'];
attitudeFilePath = [infoDir, 'sensor_attitude.txt'];
dim = 3; %dim= 1，2，3 分别代表以 x轴，y轴, z轴为准
gVal = 9.81;
%% 0. 预处理， 计算出所有frame的pose
%!python ./script.py (自动运行会出错)
%手动运行 script.py 

%% 1. 得到在world中的translates

%1.1 load IMU 数据
[timestamps, linaccs] = Utils_loadIMUdata(infoDir);
[timestamps, linaccs ] = SF_getNeatTimeSensorInfoByInterpolation(linaccs, timestamps);

%得到初始的attitude, sensor_attitude.txt 中记载的R就是, 一直所理解的 R_G2I
init_R_G2I = Utils_loadFirst_R_G2I(attitudeFilePath);
linaccs = Utils_convertWorldAcc2InertialAcc(init_R_G2I, linaccs);

%1.2 进行积分和滤波， 得到比较 position 信息
[linVelHP, linPosHP] = SF_getLinPosHP(linaccs, gVal);

%1.3 得到比较好的波峰和波谷对

[maxAndminPairs, maxAndzeroPairs, zeroAndminPairs, seq_maxAndminPairs] = SF_getGoodIndexPairs(linVelHP, linPosHP);
    
if USE_SEQ_INDICES
    %1.4 得到每个波峰和波谷对，所产生的translate
    translates_in_world = SF_getWorldTranslateByPairs(seq_maxAndminPairs, linPosHP);
else
    translates_in_world_maxAndmin = SF_getWorldTranslateByPairs(maxAndminPairs, linPosHP);
    translates_in_world_maxAndzero = SF_getWorldTranslateByPairs(maxAndzeroPairs, linPosHP);
    translates_in_world = [translates_in_world_maxAndmin, translates_in_world_maxAndzero];
end


%translates_in_world = SF_getWorldTranslateByPairs(maxAndzeroPairs, linPosHP);


%% 2. 得到在点云坐标系中的 translates

%2.1 得到 timestamp和frameIdx 之间的对应信息, 便于查阅
t2fs = Utils_loadTimestamp2Frameidx(t2f_filePath);

if USE_SEQ_INDICES
    translates_in_pointcloud = SF_getSceneTranslateByPairs(seq_maxAndminPairs,timestamps, infoDir, t2fs );
else
    translates_in_pointcloud_maxAndmin = SF_getSceneTranslateByPairs(maxAndminPairs,timestamps, infoDir, t2fs );
    translates_in_pointcloud_maxAndzero = SF_getSceneTranslateByPairs(maxAndzeroPairs,timestamps, infoDir, t2fs );
    translates_in_pointcloud = [translates_in_pointcloud_maxAndmin, translates_in_pointcloud_maxAndzero];
end




%% 3. 得到 scales
scales = translates_in_world./translates_in_pointcloud;
scale = median(scales);


end