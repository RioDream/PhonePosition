function [neat_timestamps, neat_sensorInfos] = SF_getNeatTimeSensorInfoByInterpolation(sensorInfos, timestamps)
%{
Usage:

    通过插值， 得到频率为 0.01 的 sensorInfos 

    sensorInfos: N*3 每一行都是一个sensorInfo
    timestamps; N*1
%}

nof_samples = length(timestamps);

neat_timestamps = [];
minCost = -1;
%%1. 选取比较合适的timestamps, 采用暴力法， O(n^2) 的复杂度
for i=1:nof_samples 
    t = timestamps(i);
    t_left = t - 0.01*(i-1);
    t_right = t + 0.01*(nof_samples-i);
    
    temp_neat_timestamps = [t_left:0.01:t_right].';
    cost = norm(timestamps - temp_neat_timestamps);
    if minCost<0 || cost < minCost
        minCost = cost;
        neat_timestamps = temp_neat_timestamps;
    end
end

%%2. trim neat_timstamps
neat_timestamps = trimTimestamps(neat_timestamps, timestamps(1), timestamps(end));

%%2. 利用得到的timestamps 插值
neat_sensorInfos = [];
nof_neat_samples = length(neat_timestamps);
%实际上就是 neat_timestamp 插入排序到 timestamps中
for i=1:nof_neat_samples
    neat_t = neat_timestamps(i);
    
    got_first_bigger = false;
    for j = 1:nof_neat_samples
        if neat_t<timestamps(j) %找到第一个比 neat_t 大的timestamp 
            got_first_bigger = true;
            break;
        end
    end
    
    assert(got_first_bigger);
    neat_sensorInfo = doLinearInterpolation(neat_t, timestamps(j-1), timestamps(j), sensorInfos(j-1,:), sensorInfos(j, :));
    
    neat_sensorInfos = [neat_sensorInfos; neat_sensorInfo];
    
end

end



%% 
function trimed_timestamps = trimTimestamps(timestamps, startTime, endTime)
%{
Usage:
    对 timestamps 进行 trim， 令其都在 (startTime, endTime) 这个开区间内
%}
new_start = -1;
new_stop = -1;

nof_samples = length(timestamps);

%从前往后， 找到第一个比 startTime 大的 timestamp
for i=1:nof_samples
    if timestamps(i)>startTime
        new_start = i;
        break;
    end
end
%从后往前， 找到第一个比 endTime 小的 neat_timestamp
for i=nof_samples:-1:1
    if timestamps(i) < endTime
        new_end = i;
        break;
    end
end

trimed_timestamps = timestamps(new_start: new_end);

end



%% 
function target_sensorInfo = doLinearInterpolation(targetTime, prevTime, nextTime, prev_sensorInfo, next_sensorInfo)
    ratio = (targetTime - prevTime)/(nextTime-prevTime);
    
    target_sensorInfo = prev_sensorInfo + ratio*(next_sensorInfo - prev_sensorInfo);

end