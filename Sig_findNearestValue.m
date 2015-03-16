function nearest_value_idx = Sig_findNearestValue(values, target)
%{
Usage:  
    找到 values中 和target 最接近的一个value的 idx
%}

    diffs = abs(values - target);
    nearest_value_idx = find(diffs == min(diffs) );
    assert(length(nearest_value_idx)==1);
end