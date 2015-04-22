function z_ = SKF_update_getEstimateMeasure(p_finC, K)
%{
Usage：
    由投影模型， 计算估计的z
%}
fx = K(1,1);
fy = K(2,2);
ox = K(1,3);
oy = K(2,3);

X = p_finC(1);
Y = p_finC(2);
Z = p_finC(3);

z_ = [ox; oy] + [fx, 0; 0, fy] * [X/Z; Y/Z];
end
