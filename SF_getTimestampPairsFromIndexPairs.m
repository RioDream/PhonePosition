function TimestampPairs = SF_getTimestampPairsFromIndexPairs(timestamps, IndexPairs)
%{
   Usage:
        从 IndexPairs 中提取出 timePair, 便于下一步找到对应的 image
%}

nof_pairs = size(IndexPairs,1);

TimestampPairs = [];

for i=1:nof_pairs 
    indexPair = IndexPairs(i,:);
    maxIdx = indexPair(1);
    minIdx = indexPair(2);
    
    maxTimestamp = timestamps(maxIdx);
    minTimestamp = timestamps(minIdx);
    
    TimestampPairs = [TimestampPairs; maxTimestamp, minTimestamp];
end



end