%{
用于比较初步估计时候的轨迹
%}

close all;

idx = 7;

infoDir = ['./data/',num2str(idx),'/'];
t2f_filePath = [infoDir, 'img2time.txt'];
attitudeFilePath = [infoDir, 'sensor_attitude.txt'];

[R_S2C0, p_SinC0] = Utils_loadFramePoseByIdx(infoDir,3);
p_C0inS = -transpose(R_S2C0)*p_SinC0;

init_R_G2I = Utils_loadFirst_R_G2I(attitudeFilePath);

[pCinSs, R_S2Cs] = Utils_load_pCinSs(infoDir);

nof_frames = length(pCinSs);

p_IinGs = [];
for i=1:nof_frames
    p_CinS = pCinSs(:,i);
    R_S2C = R_S2Cs{i};
    p_IinG = EX_convert_pCinS_2_G(R_S2C, p_CinS, R_S2C0,p_C0inS);
    p_IinGs = [p_IinGs , p_IinG];
end

load('./EX_data_linPosHp7.mat');
EX_plotBothTraj(p_IinGs, linPosHP)

