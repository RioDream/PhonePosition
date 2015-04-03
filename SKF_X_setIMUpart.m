function X = SKF_X_setIMUpart(X, q,  p, v, bias_G, bias_A)

    new_X_IMU = [q; p; v; bias_G; bias_A];
    X(1:16) = new_X_IMU;

end