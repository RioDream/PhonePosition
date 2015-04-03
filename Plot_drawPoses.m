function Plot_drawPoses(X, paps)
%{

Obsolete

    根据 paps中的 poseId 和 mx my, 画出一个个 IMU的pose
%}
    nof_poses = PAPS_getPapNum(paps);

    ENV_configFigure;

    for i=1:nof_poses
        [q, p] = X_getJthPose(X, paps(i, 1));
        
        drawPose(q, p, 0, 2, 1);
    end
end