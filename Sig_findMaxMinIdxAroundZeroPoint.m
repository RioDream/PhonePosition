function [maxIdx, minIdx] = Sig_findMaxMinIdxAroundZeroPoint(values, zeroIdx)
%{
Usage:
    对于一个 zero point， 往左或者右，找到一个波峰和波谷， 返回这两个 idx
%}
nof_samples = length(values);
minVal = values(zeroIdx);
maxVal = values(zeroIdx);
minIdx = zeroIdx;
maxIdx = zeroIdx;

assert(zeroIdx~=1);
assert(zeroIdx~=nof_samples);

%上坡
if values(zeroIdx-1)<values(zeroIdx) && values(zeroIdx)<values(zeroIdx+1)
    %往右找最大
    for i = zeroIdx+1:nof_samples 
        if values(i)>values(i-1)
            continue;
        else %遇到一个value(i) 比前面的值小，证明刚刚错过最大的
            maxIdx = i-1;
            break;
        end
    end
    
    %往左找最小
    for i = zeroIdx-1:-1:1
        if values(i)<values(i+1)
            continue;
        else %遇到一个value(i) 比后面的值大
            minIdx = i+1;
            break;
        end
    end
    
elseif values(zeroIdx-1)>values(zeroIdx) && values(zeroIdx)>values(zeroIdx+1) %下坡
    %往右找最小
    for i = zeroIdx+1:nof_samples 
        if values(i)<values(i-1)
            continue;
        else %遇到一个value(i) 比前面的值大
            minIdx = i-1;
            break;
        end
    end
    
    %往左找最大
    for i = zeroIdx-1:-1:1
        if values(i)>values(i+1)
            continue;
        else %遇到一个value(i) 比后面的值小
            maxIdx = i+1;
            break;
        end
    end
else
    assert(1==0, 'zero点错了');
end

end