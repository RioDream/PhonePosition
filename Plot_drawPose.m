function Plot_drawPose(q, p, rectangle_in_z, rectangle_w, rectangle_h, points)
%{
    Usage:
        
        Obsolete

        用于在 MSCKF系统进行的过程中去画
    
        画一个矩形，垂直于z轴， rectangle_in_z 是这个矩形在z轴上平移的距离
        rectangle_in_z==0 的时候， 画的是IMU坐标系，矩形代表手机平面
        rectangle_in_z~=0 的时候， 画的是相机坐标系，矩形代表成像平面

%}

    R = Quater_2Mat(q);
    ox(1) = p(1);
    oy(1) = p(2);
    oz(1) = p(3);
    ux(1) = R(1,1);
    vx(1) = R(2,1);
    wx(1) = R(3,1);
    uy(1) = R(1,2);
    vy(1) = R(2,2);
    wy(1) = R(3,2);
    uz(1) = R(1,3);
    vz(1) = R(2,3);
    wz(1) = R(3,3);

    quiver3(ox, oy, oz, ux, vx, wx,  'r', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    quiver3(ox, oy, oz, uy, vy, wy,  'g', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    quiver3(ox, oy, oz, uz, vz, wz,  'b', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');

    drawRectangle(ox, oy , oz+rectangle_in_z, ux, vx, wx, uy, vy, wy, rectangle_w, rectangle_h, points);

    drawnow;

end