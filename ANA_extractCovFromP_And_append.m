function covs = ANA_extractCovFromP_And_append(covs, P, NO_LAMBDA)
%{
    Usage:
        将协方差矩阵中的 state vector中的各个状态的协方差提取出来(主对角线上的元素)
        然后 append 到 covs当中

        covs是这样一个结构 
        18 x nof_samples
%}



    nof_cov = size(covs, 1);
    
    covs = [covs, zeros(nof_cov, 1)];

    cov_roll = P(1,1);
    cov_yaw = P(2,2);
    cov_pitch = P(3,3);
    cov_px = P(4,4);
    cov_py = P(5,5);
    cov_pz = P(6,6);
    cov_vx = P(7,7);
    cov_vy = P(8,8);
    cov_vz = P(9,9);
    cov_bgx = P(10,10);
    cov_bgy = P(11,11);
    cov_bgz = P(12,12);
    cov_bax = P(13,13);
    cov_bay = P(14,14);
    cov_baz = P(15,15);
    cov_picx = P(16,16);
    cov_picy = P(17,17);
    cov_picz = P(18,18);
    
if NO_LAMBDA
    ;
else
    cov_lambda = P(19,19);
end
    
    covs(1, end) = cov_roll;
    covs(2, end) = cov_yaw;
    covs(3, end) = cov_pitch;
    covs(4, end) = cov_px;
    covs(5, end) = cov_py;
    covs(6, end) = cov_pz;
    covs(7, end) = cov_vx;
    covs(8, end) = cov_vy;
    covs(9, end) = cov_vz;
    covs(10, end) = cov_bgx;
    covs(11, end) = cov_bgy;
    covs(12, end) = cov_bgz;
    covs(13, end) = cov_bax;
    covs(14, end) = cov_bay;
    covs(15, end) = cov_baz;
    covs(16, end) = cov_picx;
    covs(17, end) = cov_picy;
    covs(18, end) = cov_picz;
    
if NO_LAMBDA
    ;
else
    covs(19, end) = cov_lambda;
end
   

end