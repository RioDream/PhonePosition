%{
Usage:
    为3D动画创建并设置 fig
%}

%default set
View = [30 20];
Xlabel = 'X';
Ylabel = 'Y';
Zlabel = 'Z';

%set
fig = figure('Number', 'off', 'Name', 'Monitor');
set(gca, 'drawmode', 'fast');
lighting phong;
set(gcf, 'Renderer', 'zbuffer');
hold on;
axis equal;
grid on;
view(View(1, 1), View(1, 2));
xlabel(Xlabel);
ylabel(Ylabel);
zlabel(Zlabel);


%init quiver pool
nof_quivers = 5;
quiverHandles =[];
for i=1:nof_quivers
    qx = quiver3(0, 0, 0, 0, 0, 0,  'r', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    qy = quiver3(0, 0, 0, 0, 0, 0,  'g', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    qz = quiver3(0, 0, 0, 0, 0, 0,  'b', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
    quiverHandles = [ quiverHandles, [qx;qy;qz] ];
end

nof_points = 30;
pointHandles =[];
for i=1:nof_points
    %handl = plot3(0,0,0,'ro');
    %pointHandles = [pointHandles ,0];
end



    