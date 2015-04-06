function frames = Utils_loadFrameData(frameDir)
%{
Usage:
    载入frame
%}

frames = {};

%get frame number
summaryPath = [frameDir, 'summary.txt'];
fid = fopen(summaryPath, 'r');
tline = fgetl(fid);
nof_frames = fix(str2double(tline));
fclose(fid);

for idx=1:nof_frames
    frameInfo = IN_loadSingleFrame(frameDir, idx);
    frames = [frames, {frameInfo}];
end


end

function frameInfo = IN_loadSingleFrame(frameDir, idx)
%{
    载入一个 frameInfo
%}

framePath = [frameDir,'frame_', num2str(idx)];
timePath = [frameDir,'frame_', num2str(idx), '.time'];

fid = fopen(framePath, 'r');
des =  [];
locs = [];
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    [trainIdx, mx, my] = IN_parseFrameLine(tline);
    des = [des; trainIdx];
    loc = [my, mx];
    locs = [locs; loc];
end
fclose(fid);

fid = fopen(timePath, 'r');
timestamp = -1;
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    timestamp = str2double(tline);
end
fclose(fid);



frameInfo = struct( 'name', ['synthesis_',num2str(idx)], ...
                        'timestamp', timestamp, ...
                        'des', des , ...
                        'loc', locs);

end


function [trainIdx, mx, my] = IN_parseFrameLine(line)
    b = regexp(line, ',', 'split');
    trainIdx = str2double(b{1});
    mx = str2double(b{2}); %注意次序
    my = str2double(b{3});
end