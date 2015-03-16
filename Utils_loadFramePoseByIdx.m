function [R, T] = Utils_loadFramePoseByIdx(framePoseDir, frameIdx)
%{
Usage:
    根据 idx load frame 的pose
%}

filePath_R = [framePoseDir, num2str(frameIdx), '_R.txt'];
filePath_T = [framePoseDir, num2str(frameIdx), '_T.txt'];

%% load R
R = [];
fid=fopen(filePath_R);
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    eval(['R=[R;', tline ,'];']);
end
fclose(fid);

%% load T
T = [];
fid=fopen(filePath_T);
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    eval(['T=[', tline ,'];']);
end

T = T.';

fclose(fid);

end