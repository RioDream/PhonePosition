function  [pCinSs,R_S2Cs] = Utils_load_pCinSs(infoDir, nof_frames)
%{
    load 所有的 T
%}

pCinSs = [];
R_S2Cs ={};
for idx=0:nof_frames
    [R_S2C, p_SinC] = load_single_RT(infoDir , idx);

    p_CinS = -transpose(R_S2C) * p_SinC;

    pCinSs = [pCinSs,p_CinS];
    R_S2Cs{idx+1} = R_S2C;
end

end

function [R_S2C, p_SinC] = load_single_RT(infoDir , idx)
%% load R
R =[];
R_Path = [infoDir, num2str(idx) ,'_R.txt'];

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
T_Path = [infoDir, num2str(idx) ,'_T.txt'];
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