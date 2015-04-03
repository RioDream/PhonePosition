function [X, P] = SKF_PROP_propagate(X, P, last_firstEstimated_X, IMUInfo, last_IMUInfo, Nc, g_inG)


X = SKF_propagate_state(X, IMUInfo, last_IMUInfo, g_inG);
P = SKF_propagate_cov(P, X, last_firstEstimated_X, IMUInfo, last_IMUInfo, Nc, g_inG);

end