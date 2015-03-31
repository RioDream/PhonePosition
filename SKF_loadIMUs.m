function atts = SKF_loadIMUs(IMUPath)
%{
Usage:
    load attitude 信息
%}

atts = [];

fid = fopen(IMUPath);

while 1
    line = fgetl(fid);
    if ~ischar(line), break, end

    IMUinfo = parse_att_line(line);
    
    atts = [atts, IMUinfo];

end

fclose(fid);

end



function IMUinfo = parse_att_line(line)
%{
Usage:
    parse line like : timestamp: roll, pitch, yaw
%}

s = regexp(line, ':', 'split');
timestamp = str2double(s{1});
b = regexp(s{2}, ',', 'split');

roll = str2double(b{1});
pitch = str2double(b{2});
yaw = str2double(b{3});

IMUinfo = struct('timestamp', timestamp,  ...
            'roll', roll, ...
            'pitch', pitch, ...
            'yaw', yaw);

end

            