function [max_value, max_value_idx] = Sig_findMaxima(values)
%{
Usage: 
    得到values中的最大的 value， 返回其值 和 index
%}
    nof_samples = length(values);
    max_value = values(1);
    max_value_idx = 1;
    for i=2:nof_samples
        value = values(i);
        if value > max_value
            max_value = value;
            max_value_idx = i;
        end
    end
    
end
