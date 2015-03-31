function translates_in_pointcloud = SF_getSceneTranslateByPairs(IndexPairs,timestamps,infoDir, t2fs )
%{
    由timestampPairs 获得 在 scene 中的 translate
%2.2 由 IndexPairs 得到 TimestampPairs
%2.3 得到 camera 在 点云坐标系中的 translate


%}
TimestampPairs = SF_getTimestampPairsFromIndexPairs(timestamps, IndexPairs);
translates_in_pointcloud = [];
nof_pairs = size(TimestampPairs,1);
FrameidxPairs = [];
for i=1:nof_pairs
    timestampPair = TimestampPairs(i, :);
    
    maxTimestamp = timestampPair(1);
    minTimestamp = timestampPair(2);
    
    %这里找到和 给定的 timestamp 最接近的 frame 的 index
    maxFrameIdx = T2F_findClosestFrameIdx(t2fs, maxTimestamp);
    minFrameIdx = T2F_findClosestFrameIdx(t2fs, minTimestamp);

    FrameidxPairs = [FrameidxPairs; maxFrameIdx, minFrameIdx];
    
    [R1, T1] = Utils_loadFramePoseByIdx(infoDir, maxFrameIdx);
    [R2, T2] = Utils_loadFramePoseByIdx(infoDir, minFrameIdx);
    
    %T1 是 p_GinC， 将其转换为 p_CinG, 然后计算translate
    translate_in_pointcloud = SF_calcTranslateByRanT(R1, T1, R2, T2);
    
    translates_in_pointcloud = [translates_in_pointcloud, translate_in_pointcloud];
end

end