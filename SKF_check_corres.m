function SKF_check_corres(features, ms, dess, room, frameInfo, gt_q, gt_p, K)

nof_corres = size(features,1);

for i=1:nof_corres
    des = dess(i);
    p_finG = features(i,:);
    m = ms(i,:) ;
    assert(room(des ,4)==des);
    
    %feature
    gt_p_finG = room(des, 1:3);
    assert(isequal(p_finG, gt_p_finG ));
    %measure
    idx = find(frameInfo.des==des);
    gt_m = [frameInfo.loc(idx,2), frameInfo.loc(idx,1)];
    assert(isequal( m,  gt_m));
    
    noise = [frameInfo.noise(idx, 2), frameInfo.noise(idx, 1)].';
    
    %check proj
    q_I2C = [-1 0 0 0];
    q_G2C = Quater_multi(q_I2C, gt_q);
    p_IinG = gt_p;
    p_CinG = p_IinG;
    R_G2C = Quater_2Mat(q_G2C);
    p_finC = R_G2C*(gt_p_finG.' - p_CinG);
    z = K*p_finC;
    z = z(1:2)/z(3);
    diff = z+noise - m.';
    assert(norm(diff)<0.0000001);
end

end