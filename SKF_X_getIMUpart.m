function [q, p, v, bias_G, bias_A ] = SKF_X_getIMUpart(X)
%{
Usage:
    得到 X的 IMU 部分，其中 q p v bg ba
%}

    %按照 IMU部分的顺序, IMU部分的长度是 16，按照 q p v bg ba 的顺序
    q = X(1:4);
    p = X(5:7);
    v = X(8:10);
    bias_G = X(11:13);
    bias_A = X(14:16);

end