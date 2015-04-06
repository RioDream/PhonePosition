function room = Utils_loadRoom(infoDir)

%{
Usage:
    load imu 数据
%}

RoomPath = [infoDir, 'room.txt'];


room = [];

fid=fopen(RoomPath);
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    [idx, x, y, z] = parseRoomLine(tline);
    room = [room; [x,y,z,idx]];
end

fclose(fid);


end

function [idx, x, y, z] = parseRoomLine(line)
%{
    a ios version
%}


b = regexp(line, ',', 'split');

idx = str2double(b{1});
x = str2double(b{2});
y = str2double(b{3});
z = str2double(b{4});


end