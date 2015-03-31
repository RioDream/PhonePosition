function init_R_G2I = Utils_loadFirst_R_G2I(attitudeFilePath)
%{
Usage:
    读取 attitudeFile ， 获取第一行， 
    得到一个 R_G2I

Todo:
    不一定要获取第一行， 可以更鲁棒
%}

ignore = 50;

R = [];
i=0;
fid=fopen(attitudeFilePath);
while 1
    tline = fgetl(fid);
    i= i+1;
    if ~ischar(tline), break, end
    if i<ignore
        continue;
    end
    [timestamp, R_G2I] = parse_attitude_line(tline);
    break; %todo
end
fclose(fid);

init_R_G2I = R_G2I;
end

function [timestamp, R_G2I] = parse_attitude_line(line)
%{
Usage:
    得到 R_G2I
%}
s = regexp(line, ':', 'split');
timestamp = str2double(s{1});

s = regexp(s{2}, ',', 'split');
R_G2I = [str2double(s{1}), str2double(s{2}), str2double(s{3});
            str2double(s{4}), str2double(s{5}), str2double(s{6});
            str2double(s{7}), str2double(s{8}), str2double(s{9})];        

end