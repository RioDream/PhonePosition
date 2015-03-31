function [maxAndminPairs, maxAndzeroPairs, zeroAndminPairs, seq_maxAndminIndices] = SF_getGoodIndexPairs(linVelHP,linPosHP)
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

PLOT = 1;

%% 1. 获取周期信号的频率
%获取周期信号的频率有两种方法，
    %1. 傅里叶变换 
    %2.  a. 找零点，利用中值得到周期
values = linPosHP(:,3);

%高通滤波再次滤除偏移
order = 1;
filtCutOff = 0.15;
[b, a] = butter(order, (2*filtCutOff)/(1/0.01), 'high');
filtered_values= filtfilt(b, a, values);

mainFrequency = Sig_getMainFrequency(values);  %尽量使用3d的信息，而不只是1d
mainCycle = 1/mainFrequency; %周期





[zero_pts , zero_pts_idx] = Sig_findZeroPoints(filtered_values);



if 1
    fs=100;
    nof_samples = length(values);
    n = 0:nof_samples-1;
    t=n/fs; %采样时间
    
    % Plot
    figure('Number', 'off', 'Name', 'filtered linPosHP');
    hold on;
    plot(t,filtered_values, 'r');
    xlabel('sample');
    ylabel('g');
    title('low filtered values');
    legend('X', 'Y', 'Z');
end

if PLOT
    
    hold on;
    plot(zero_pts_idx*0.01, zero_pts, 'o');
end

if 1
    % Plot
    figure('Number', 'off', 'Name', 'linPosHP-Z');
    hold on;
    plot(t,values, 'r');
    xlabel('sample');
    ylabel('g');
    title('values');
    legend('X', 'Y', 'Z');
end
    



%% 得到符合条件的零点的x坐标值
zero_pts_idx_time = zero_pts_idx*0.01; %将index转换为时间， 近似
tooth_dis = mainCycle*0.5; %取半个周期作为齿距
threshold = 0.25;
max_tooth_zero_pts_time = Sig_findLongestComb(zero_pts_idx_time, mainCycle*0.5, threshold);

if PLOT
    hold on;
    plot(max_tooth_zero_pts_time, 0, 'ro');
end



IndexPairs = [];
maxIndices = [];
minIndices = [];
zeroIndices = [];
seq_maxAndminIndices = []
for i=2:length(max_tooth_zero_pts_time)-1 %掐头去尾
    zeroIdx = fix(max_tooth_zero_pts_time(i)*100); %不够鲁邦
    zeroIndices = [zeroIndices, zeroIdx];
    [maxIdx, minIdx] = Sig_findMaxMinIdxAroundZeroPoint(values, zeroIdx);
    
    seq_maxAndminIndices = [seq_maxAndminIndices; maxIdx, minIdx];
    maxIndices = [maxIndices, maxIdx];
    minIndices = [minIndices, minIdx];
    
    hold on;
    plot(maxIdx*0.01, values(maxIdx) , 'go');
    
    hold on;
    plot(minIdx*0.01, values(minIdx) , 'bo');
end

hold on

%获得的maxIndices 和 minIndices 中有重复，消除重复


maxIndices = uniq(maxIndices);
minIndices = uniq(minIndices);


%三个pairs
%波峰和波谷
maxAndminPairs = SetProduct(maxIndices, minIndices);
maxAndzeroPairs = SetProduct(maxIndices, zeroIndices);
zeroAndminPairs = SetProduct(zeroIndices, minIndices);
 

end


function productSet = SetProduct(set1, set2)
%{
Usage:
    计算两个集合的笛卡尔乘积
%}

productSet = [];

for i=1:length(set1)
    for j = 1:length(set2)
        productSet = [productSet; set1(i), set2(j)];
    end
end

end

function set_uniq = uniq(set)
%{
功能类似于 linux 下的 uniq
%}
lastIdx = -1;
set_uniq = [];
for i=1:length(set)
    currIdx = set(i);
    if currIdx~=lastIdx
        set_uniq = [set_uniq, currIdx];
    end
    lastIdx = currIdx;
end

end






