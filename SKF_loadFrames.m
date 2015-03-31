function frames = SKF_loadFrames(framesDir)
%{
framesDir 里 每一个frame都有一个

每行都有如下格式

mx,my:sx,sy,sz


%}

frames = [];

allFrameNameFilePath = [framesDir, '/allFrameNames'];

names_fid = fopen(allFrameNameFilePath);

while 1
    name_line = fgetl(names_fid);
    if ~ischar(name_line), break, end
    [frameName, timestamp] = parse_name_line(name_line);
    
    framePath = [framesDir, frameName];
    [ms, ps] = load_single_frame(framePath);
    
    frameInfo = struct('timestamp', timestamp,  ...
                'ms', ms, ...
                'ps', ps);
    
    frames = [frames, frameInfo];
end

fclose(names_fid);

end

function [frameName, timestamp] = parse_name_line()
%{
Usage:
   parse name:timestamp 这样的line 
%}

s = regexp(line, ':', 'split');
frameName = s{1};
timestamp = str2double(s{2});

end


function [ms, ps] = loadSingleFrame(framePath)
%{
Usage:
    load frame 文件
    其每一行格式是这样：
        mx,my,sx,sy,sz
%}
    
names_fid = fopen(framePath);

ms = []; %每一行都是一个mesaurement: mx,my
ps = [];  %每一行都和 ms中的一行对应，  sx,sy,sz 

while 1
    line = fgetl(names_fid);
    if ~ischar(line), break, end
    [mx, my, sx, sy, sz]  = parse_frame_line(line);
    ms = [ms; mx, my];
    ps = [ps; sx, sy, sz];
end

fclose(names_fid);

end
    
function [mx, my, sx, sy, sz] = parse_frame_line(line)
%{
Usage:
        其每一行格式是这样：
        mx,my,sx,sy,sz
    其中 mx my 是图像上的特征点的位置
    sx sy sz 是场景中对应该特征点的场景坐标
%}
eval['m = ',line,';'];
mx = m(1);
my = m(2);
sx = m(3);
sy = m(4);
sz = m(5);

end
    
    


