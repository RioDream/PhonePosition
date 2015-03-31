function new_linaccs = Utils_convertWorldAcc2InertialAcc(init_R_G2I, linaccs)
%{
Usage:
    将所有的 linaccs 都转换到 第一帧的 IMU的坐标系下
%}

new_linaccs = [];

nof_samples = size(linaccs,1);
for i=1:nof_samples
    linacc = init_R_G2I * linaccs(i,:).';
    linacc = linacc.';
    new_linaccs = [new_linaccs; linacc];
end


end