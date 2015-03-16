function t2fs = Utils_loadTimestamp2Frameidx(filePath)
%{
Usage:
    从 img2time.txt 中读取 timestamp 和 对应的 frameIdx
%}

t2fs = [];


fid=fopen(filePath);
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    [timestamp, frameIdx] = parse_i2t_line(tline);
    
    t2fs = [t2fs; timestamp, frameIdx];
end
fclose(fid);


end



function [timestamp, frameIdx] = parse_i2t_line(line)
%{
    i2t means img2time
%}

s = regexp(line, ':', 'split');

frameIdx = fix(str2double(s{1}));
timestamp = str2double(s{2});
end