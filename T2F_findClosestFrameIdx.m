function frameIdx = T2F_findClosestFrameIdx(t2frame, targetTimestamp)
%{
Usage:
    从 t2frame 中找到一个和 targetTimestamp 的时间最为接近的 frame的name

    t2frame 是这样一种结构：
        t1, frameId1
        t2, frameId2
        ...
        t3, frameId3
%}

timestamps = t2frame(:,1);
diffs = abs(timestamps - targetTimestamp);
[minVal, minIdx] = min(diffs);
frameIdx = t2frame(minIdx, 2);

end