function [timestamps, linaccs] = Utils_loadIMUdata(infoDir)
%{
Usage:
    load imu 数据
%}

IMUpath = [infoDir, 'sensor_linacc.txt'];

linaccs = [];
timestamps = [];

fid=fopen(IMUpath);
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    [timestamp, x, y, z] = parseIMUline_ios(tline);
    timestamps = [timestamps; timestamp];
    linaccs = [linaccs; x,y,z];
end

fclose(fid);


end

function [timestamp, x, y, z] = parseIMUline_ios(line)
%{
    a ios version
%}

s = regexp(line, ':', 'split');
timestamp = str2double(s{1});
b = regexp(s{2}, ',', 'split');

%这里不进行negate
x = str2double(b{1});
y = str2double(b{2});
z = str2double(b{3});


end