function quiverHandles = Plot_drawPose_useQuiverHandles(q, p, rectangle_in_z, rectangle_w, rectangle_h, points, quiverHandles)
%{
    Usage:
        Plot_drawPose_useQuiverHandle.m 函数的变形版，只是用有限的 quiverHandlers去画最近的几个pose，避免资源浪费

        用于在 MSCKF系统进行的过程中去画
    
        画一个矩形，垂直于z轴， rectangle_in_z 是这个矩形在z轴上平移的距离
        rectangle_in_z==0 的时候， 画的是IMU坐标系，矩形代表手机平面
        rectangle_in_z~=0 的时候， 画的是相机坐标系，矩形代表成像平面
        
        
%}

    R = Quater_2Mat(q);
    %origin
    ox(1) = p(1);
    oy(1) = p(2);
    oz(1) = p(3);
    % axis x
    ux(1) = R(1,1);
    vx(1) = R(2,1);
    wx(1) = R(3,1);
    % axis y
    uy(1) = R(1,2);
    vy(1) = R(2,2);
    wy(1) = R(3,2);
    % axis z
    uz(1) = R(1,3);
    vz(1) = R(2,3);
    wz(1) = R(3,3);

        
    %pop queue head
    quivXhandle = quiverHandles(1,1);
    quivYhandle = quiverHandles(2,1);
    quivZhandle = quiverHandles(3,1);
    quiverHandles(:,1)=[];
    
    scale = 0.05; 
    set(quivXhandle, 'xdata', ox, 'ydata', oy, 'zdata', oz,'udata', scale*ux, 'vdata', scale*vx, 'wdata', scale*wx);
    set(quivYhandle, 'xdata', ox, 'ydata', oy, 'zdata', oz,'udata', scale*uy, 'vdata', scale*vy, 'wdata', scale*wy);
    set(quivZhandle, 'xdata', ox, 'ydata', oy, 'zdata', oz,'udata', scale*uz, 'vdata', scale*vz, 'wdata', scale*wz);

    %append to queue tail
    quiverHandles = [quiverHandles , [quivXhandle;quivYhandle;quivZhandle] ];

    Plot_drawRectangle(ox, oy , oz+rectangle_in_z, ux, vx, wx, uy, vy, wy, rectangle_w, rectangle_h, points);
    

    drawnow;

end