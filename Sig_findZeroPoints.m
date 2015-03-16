function [zero_pts, zero_pts_idx] = Sig_findZeroPoints(values)
%{
Usage:
    values 是一个信号随时间变化的值
    从 values 中找到近似的零点
    所谓近似， 是说这个点不一定是严格的零点， 而是说这个点的左右两个点一个大于0， 一个小于0， 具体来说，
    比如有连续的 a b c d,    a b >0, c d <0  那么选择 b c 都作为零点
%}
    nof_samples = length(values);
    
    zero_pts = [];
    zero_pts_idx = [];
    
    for i=2:nof_samples-1
        value_prev = values(i-1);
        value = values(i);
        value_next = values(i+1);

        if value_prev * value_next<0 && abs(value<0.01) %异号
            zero_pts_idx = [zero_pts_idx, i];
            zero_pts = [zero_pts, value];
        end
    end
end