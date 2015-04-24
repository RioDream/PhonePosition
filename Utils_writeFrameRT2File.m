function Utils_writeFrameRT2File()

load('./EX_data/frame_pIinSs.mat');
load('./EX_data/frame_R_I2Ss.mat');

outDir = './EX_data/FrameRT/';
R_I2C = Quater_2Mat([-1 0 0 0]);
p_IinC = [0, 0.00656, 0].'; %%%%%%%%

MAKE_LAMBDA_ONE_SCALE = 0.019062181447503; 
nof_samples = length(frame_ps);
assert(nof_samples == length(frame_Rs));
for i=1:nof_samples
    
    p_IinS = frame_ps(: , i);
    R_I2S = frame_Rs{i};
    R_C2S = R_I2S*transpose(R_I2C);
    p_CinS = p_IinS - R_C2S*p_IinC;
    
    R = transpose(R_C2S);
    T = -R * p_CinS / MAKE_LAMBDA_ONE_SCALE ;
    
    R_path = [outDir, 'R_' , num2str(i),'.txt'];
    T_path = [outDir, 'T_' , num2str(i),'.txt'];
    IN_writeR(R_path, R)
    IN_writeT(T_path, T)
end



end

function IN_writeR(path, R)
    fid = fopen(path,'wt'); 
    fprintf(fid,'%d\n',R(1,1));
    fprintf(fid,'%d\n',R(1,2));
    fprintf(fid,'%d\n',R(1,3));
    fprintf(fid,'%d\n',R(2,1));
    fprintf(fid,'%d\n',R(2,2));
    fprintf(fid,'%d\n',R(2,3));
    fprintf(fid,'%d\n',R(3,1));
    fprintf(fid,'%d\n',R(3,2));       
    fprintf(fid,'%d\n',R(3,3));       
    fclose(fid);
end

function IN_writeT(path, T)
    fid = fopen(path,'wt'); 
    fprintf(fid,'%d\n',T(1));
    fprintf(fid,'%d\n',T(2));
    fprintf(fid,'%d\n',T(3)) ;  
    fclose(fid);
end