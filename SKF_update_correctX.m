function X = SKF_update_correctX(X, deltaX)

    assert(length(deltaX)==19);

    [q, p, v, bg, ba] = SKF_X_getIMUpart(X);
    [pic , lambda] = SKF_getOtherPart(X);

    theta = deltaX(1:3);
    delta_p = deltaX(4:6);
    delta_v = deltaX(7:9);
    delta_bg = deltaX(10:12);
    delta_ba = deltaX(13:15);
    delta_pic = deltaX(16:18);
    delta_lambda = deltaX(19);

    %convert theta to deltaQ
    bq = 0.5*theta;
    if norm(bq)<1.0
        deltaQ =  [bq; sqrt(1.0 - bq.'*bq)] ; %!! bq.'*bq 不是norm(bq)，而是其平方
    else
        deltaQ = [bq; 1];
        deltaQ = deltaQ/norm(deltaQ);
    end
    q = Quater_multi(q, deltaQ);
    p = p + delta_p;
    v = v + delta_v;
    bg = bg + delta_bg;
    ba = ba + delta_ba;
    pic = pic + delta_pic;
    lambda = lambda + delta_lambda;

    X = SKF_X_setIMUpart(X, q,  p, v, bg, ba);
    X = SKF_setOtherPart(X, pic, lambda);
end
