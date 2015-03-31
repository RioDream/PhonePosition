function [max_value, max_value_idx, sec_max_value, sec_max_value_idx] = Sig_findMaxima(values, f, minThresh)
%{
Usage: 
    得到values中的最大的 value， 返回其值 和 index
    minThresh 是一个阈值 ，找到的频率不能低于这个数
%}
    nof_samples = length(values);
    max_value = -1;
    max_value_idx = -1;
    sec_max_value = -1;
    sec_max_value_idx = -1;
    for i=1:nof_samples
        value = values(i);
        if value > sec_max_value && f(i)>minThresh
            sec_max_value = value;
            sec_max_value_idx = i;
            if sec_max_value > max_value %swap
                temp_val = max_value;
                temp_idx = max_value_idx;
                
                max_value = sec_max_value;
                max_value_idx = sec_max_value_idx;
                
                sec_max_value = temp_val;
                sec_max_value_idx = temp_idx;
            end
        end
    end
    
end
