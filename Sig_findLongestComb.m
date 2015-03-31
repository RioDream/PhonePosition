function max_tooth_zero_pts_time = Sig_findLongestComb(zero_pts_time, period, threshold)
%{
Usage:
    zero_pts：是一堆零点
    period：是半个周期， 是梳子的齿距

    给定齿距，以及所有的零点，
    找到齿数最多的一个梳子
%}

max_tooth_zero_pts_time  = [];
nof_max_tooth = 0;

%中间变量
tooth_zero_pts_time = [];
cost = 0;

nof_zeros = length(zero_pts_time);
for i=1:nof_zeros %遍历选择其中一个作为齿， 向两边扩散
    
    center = zero_pts_time(i);
    tooth_zero_pts_time = [center];
    cost = 0;
    
    %左边
    j = 1;
    while 1
        tooth = center - j*period;
        candidate_idx = Sig_findNearestValue(zero_pts_time, tooth);
        distance = tooth_distance(zero_pts_time(candidate_idx), tooth);
        if distance>threshold*period
            break;
        end
        cost = cost + distance;
        tooth_zero_pts_time = [zero_pts_time(candidate_idx), tooth_zero_pts_time];
        j = j+1;
    end
    
    %右边
    j=1;
    while 1
        tooth = center + j*period;
        candidate_idx = Sig_findNearestValue(zero_pts_time, tooth);
        distance = tooth_distance(zero_pts_time(candidate_idx), tooth);
        if distance>threshold*period
            break;
        end
        cost = cost + distance;
        tooth_zero_pts_time = [tooth_zero_pts_time, zero_pts_time(candidate_idx)];
        j = j+1;
    end
    
    nof_tooth = length(tooth_zero_pts_time);
    if nof_tooth>nof_max_tooth
        max_tooth_zero_pts_time = tooth_zero_pts_time;
        nof_max_tooth = nof_tooth;
    end
    
end

end

%% Helpers

function distance = tooth_distance(x1, x2)
    distance = abs(x1-x2);
end


