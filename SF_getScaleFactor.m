function SF_getScaleFactor()

close all;
infoDir = './data/2/';
t2f_filePath = [infoDir, 'img2time.txt'];
dim = 3; %dim= 1，2，3 分别代表以 x轴，y轴, z轴为准

%% 1. 得到在world中的translates

%1.1 load IMU 数据
[timestamps, linaccs] = Utils_loadIMUdata(infoDir);
[timestamps, linaccs ] = SF_getNeatTimeSensorInfoByInterpolation(linaccs, timestamps);

%1.2 进行积分和滤波， 得到比较 position 信息
linPosHP = SF_getLinPosHP(linaccs);

%1.3 得到比较好的波峰和波谷对
IndexPairs = SF_getGoodIndexPairs(linPosHP(:,dim));

%1.4 得到每个波峰和波谷对，所产生的translate
translates_in_world = [];
nof_pairs = size(IndexPairs, 1);
for i=1:nof_pairs
    maxIdx = IndexPairs(i, 1);
    minIdx = IndexPairs(i, 2);
    
    maxPos = linPosHP(maxIdx,:);
    minPos = linPosHP(minIdx,:);
    
    translate = norm(maxPos - minPos);
    translates_in_world = [translates_in_world , translate];
end

%% 2. 得到在点云坐标系中的 translates

%2.1 得到 timestamp和frameIdx 之间的对应信息, 便于查阅
t2fs = Utils_loadTimestamp2Frameidx(t2f_filePath);

%2.2 由 IndexPairs 得到 TimestampPairs
TimestampPairs = SF_getTimestampPairsFromIndexPairs(timestamps, IndexPairs);

%2.3 得到 camera 在 点云坐标系中的 translate
translates_in_pointcloud = [];
nof_pairs = size(TimestampPairs,1);
for i=1:nof_pairs
    timestampPair = TimestampPairs(i, :);
    
    maxTimestamp = timestampPair(1);
    minTimestamp = timestampPair(2);
    
    %这里找到和 给定的 timestamp 最接近的 frame 的 index
    maxFrameIdx = T2F_findClosestFrameIdx(t2fs, maxTimestamp);
    minFrameIdx = T2F_findClosestFrameIdx(t2fs, minTimestamp);
    
    [R1, T1] = Utils_loadFramePoseByIdx(infoDir, maxFrameIdx);
    [R2, T2] = Utils_loadFramePoseByIdx(infoDir, minFrameIdx);
    
    %T1 是 p_GinC， 将其转换为 p_CinG, 然后计算translate
    translate_in_pointcloud = SF_calcTranslateByRanT(R1, T1, R2, T2);
    
    translates_in_pointcloud = [translates_in_pointcloud, translate_in_pointcloud];
end

%% 3. 得到 scales
scales = translates_in_world./translates_in_pointcloud;
scale = median(scales);


end