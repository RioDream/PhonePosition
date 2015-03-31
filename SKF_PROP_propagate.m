function [X, P] = SKF_PROP_propagate(X, P)


SKF_propagate_state(X, IMUInfo, last_IMUinfo, g_inG);
SKF_propagate_cov(P, X, last_firstEstimated_X, imuInfo, last_imuInfo);


end