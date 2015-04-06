function [R_S2C, p_SinC] = Utils_loadInitRandT(infoDir)

%% load R
R =[];
R_Path = [infoDir, '0_R.txt'];

fid=fopen(R_Path);
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    eval(['row =[',tline, '];']);
    R = [R; row];
end
assert(size(R,1)==3 && size(R,2)==3);
fclose(fid);
R_S2C = R;

%% load T
T_Path = [infoDir, '0_T.txt'];
T = [];

fid=fopen(T_Path);
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    eval(['row =[',tline, '];']);
    T = [T; row];
end
assert(size(T,1)==1 && size(T,2)==3);
fclose(fid);
p_SinC = transpose(T);


end