function cameraTranslate_inG = SF_calcTranslateByRanT(R_max, T_max, R_min, T_min)
%{
Usage:
    通过
        R：R_G2C,  t： p_GinC
%}

    p_CinG_max = getCameraPositioninG(R_max, T_max);
    p_CinG_min = getCameraPositioninG(R_min, T_min);
    
    cameraTranslate_inG = norm(p_CinG_max - p_CinG_min);
    
end


function p_CinG = getCameraPositioninG(R_G2C, p_GinC)
%{
Usage:
    得到 p_CinG
%}
    p_CinG = -transpose(R_G2C)*p_GinC;
end