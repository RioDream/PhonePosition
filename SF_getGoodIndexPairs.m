function IndexPairs = SF_getGoodIndexPairs(values)
%{
Usage:
    利用 之前 得到的 linPosHP中的 某一维坐标 , 进行梳子处理等， 
    得到梳子的一个个点, 比如 t1 t2 t3,   这三个点分别是 波峰， 波谷， 波峰
    他们在 linPosHP 和 timestamps 之中的 index，分别是 idx1, idx2, idx3
    那么就应该返回  [idx1, idx2],  [idx2, idx3]  这样两个pair, 存放结构如下

        [idx1, idx2]
        [idx2, idx3]
    
    ===

    linPosHP:  Nx3 ， 每一行是一个 position
    timestamp: N x1 ， 和 linPosHP 中每一行一一对应
    
    time2position 
    time2image: 时间对应的image name
%}

PLOT = 0;

%% 1. 获取周期信号的频率
%获取周期信号的频率有两种方法，
    %1. 傅里叶变换 
    %2.  a. 找零点，利用中值得到周期

mainFrequency = Sig_getMainFrequency(values);  %尽量使用3d的信息，而不只是1d
mainCycle = 1/mainFrequency; %周期

[zero_pts , zero_pts_idx] = Sig_findZeroPoints(values);


if PLOT
    hold on;
    plot(zero_pts_idx*0.01, zero_pts, 'o');
end


%% 得到符合条件的零点的x坐标值
zero_pts_idx_time = zero_pts_idx*0.01; %将index转换为时间， 近似
tooth_dis = mainCycle*0.5; %取半个周期作为齿距
max_tooth_zero_pts_time = Sig_findLongestComb(zero_pts_idx_time, mainCycle*0.5);

if PLOT
    hold on;
    plot(max_tooth_zero_pts_time, 0, 'ro');
end

IndexPairs = [];
for i=2:length(max_tooth_zero_pts_time)-1 %掐头去尾
    zeroIdx = fix(max_tooth_zero_pts_time(i)*100); %不够鲁邦
    [maxIdx, minIdx] = Sig_findMaxMinIdxAroundZeroPoint(values, zeroIdx);
    
    IndexPairs = [IndexPairs ; maxIdx, minIdx];
    
    hold on;
    plot(maxIdx*0.01, values(maxIdx) , 'go');
    hold on;
    plot(minIdx*0.01, values(minIdx) , 'bo');
end

hold on

end







