    nof_features = size(features,1);
    q = gt_qs(:,1597);
    p = gt_ps(:,1597);
    zs = [];
    for i=1:nof_features
        des = dess(i);
        diff = room(des,1:3)-features(i,:);
        p_finG = features(i,:)*1.5 - [0,0,0.75];
        R_I2C = Quater_2Mat(q_I2C);
        R_G2C = R_I2C * Quater_2Mat(q);
        p_CinG = p;
        p_finC = R_G2C * (p_finG.' - p_CinG);
        Z = K*p_finC;
        z = Z(1:2).'/Z(3);
        zs = [zs; z];
    end
    
    disp('ok');