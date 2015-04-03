function qHandles = Plot_drawPose_useQuiverHandle(q, p, rectangle_in_z, rectangle_w, rectangle_h, points, quivXhandle, quivYhandle, quivZhandle)
%{
    Usage:
        画 camera pose， 连同视景体

        drawPose函数的变形版，只是用有限的 quiverHandlers去画最近的几个pose，避免资源浪费

        用于在 MSCKF系统进行的过程中去画
    
        画一个矩形，垂直于z轴， rectangle_in_z 是这个矩形在z轴上平移的距离
        rectangle_in_z==0 的时候， 画的是IMU坐标系，矩形代表手机平面
        rectangle_in_z~=0 的时候， 画的是相机坐标系，矩形代表成像平面

        #1. 画原点和坐标轴
        #2. 画成像平面
        #3. 画四条射线 和 三角形
        
%}

    %% #1 得到旋转后的坐标轴的 原点 x y z轴
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

    
    set(quivXhandle, 'xdata', ox, 'ydata', oy, 'zdata', oz,'udata', ux, 'vdata', vx, 'wdata', wx);
    set(quivYhandle, 'xdata', ox, 'ydata', oy, 'zdata', oz,'udata', uy, 'vdata', vy, 'wdata', wy);
    set(quivZhandle, 'xdata', ox, 'ydata', oy, 'zdata', oz,'udata', uz, 'vdata', vz, 'wdata', wz);

    %% #2 确定 成像平面的位置 (垂直于z轴)
    z_vec = [uz, vz, wz];
    z_vec  = z_vec / norm(z_vec );
    rectangle_in_z_vec = rectangle_in_z*z_vec;
    rect_ox = ox + rectangle_in_z_vec(1);
    rect_oy = oy + rectangle_in_z_vec(2);
    rect_oz = oz + rectangle_in_z_vec(3);
    [qHandles, rectPoints] = Plot_drawRectangle(rect_ox, rect_oy , rect_oz, ux, vx, wx, uy, vy, wy, rectangle_w, rectangle_h, points);
    
    
    %% #2 画四条射线
    
    ul = rectPoints(1,:);
    ur = rectPoints(2,:);
    br = rectPoints(3,:);
    bl = rectPoints(4,:);
    
    v_ul = ul - [ox oy oz];
    v_ur = ur - [ox oy oz];
    v_br = br - [ox oy oz];
    v_bl = bl - [ox oy oz];
    
    % 将射线延伸到z=-1这个平面上
    z_ = -1;
    ul = extendVector(ul, v_ul, z_); %ul作为起始点， v_ul 是方向， 延伸到 z_=-1这个平面
    ur = extendVector(ur, v_ur, z_);
    br = extendVector(br, v_br, z_);
    bl = extendVector(bl, v_bl, z_);
    % ul 等4个点, 是4条射线的端点
    
    %plot 4 line
    line_qh1 = quiver3(ox, oy, oz, ul(1)-ox, ul(2)-oy , ul(3)-oz, 'c', 'ShowArrowHead', 'off', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    line_qh2 = quiver3(ox, oy, oz, ur(1)-ox, ur(2)-oy , ur(3)-oz, 'c', 'ShowArrowHead', 'off', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    line_qh3 = quiver3(ox, oy, oz, br(1)-ox, br(2)-oy , br(3)-oz, 'c', 'ShowArrowHead', 'off', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    line_qh4 = quiver3(ox, oy, oz, bl(1)-ox, bl(2)-oy , bl(3)-oz, 'c', 'ShowArrowHead', 'off', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    
    %plot 4 三角形
    endPoints = [ul; ur; br; bl];
    for i=1:4
        p1 = endPoints(i,:);
        j = i+1;
        if j==5 j=1; end
        p2 = endPoints(j,:);
        xs = [ox p1(1) p2(1)];  
        ys = [oy p1(2) p2(2)];
        zs = [oz p1(3) p2(3)];
        %画四个三角形
        fillHandle = fill3(xs, ys, zs,'c');
        
        alpha(fillHandle, 0.2);
        qHandles = [qHandles, fillHandle];
    end

    
    qHandles = [qHandles, line_qh1, line_qh2, line_qh3, line_qh4 ];

    drawnow;

end


function endPoint = extendVector(startPoint,  vecDirection, endPoint_z)
    endPoint = startPoint + (endPoint_z - startPoint(3))/ vecDirection(3) * vecDirection;
end