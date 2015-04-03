function [qHandles, rectPoints] = Plot_drawRectangle(ox, oy , oz, ux, vx, wx, uy, vy, wy, w, h, points)
%{

Usage:

    给定一个原点和 x轴y轴方向的矢量
    画一个 xoy 平面上 以o为中心的矩形

    ox, oy oz => ux, vx, wx
    ox, oy oz => uy, vy, wy
    ox, oy oz => uz, vz, wz
    
    points 是 image平面上 的二维坐标

    rectPoints 以左上 右上 右下 左下 的顺序搞的， 每行一个
%}

qHandles = [];
rectPoints = [];


%w = 2; %沿着x
%h = 1; %沿着y
axisX = [ux, vx, wx]; % - [ox, oy, oz];
vX = w*axisX/norm(axisX);
axisY = [uy, vy, wy]; % - [ox, oy, oz];
vY = h*axisY/norm(axisY);

uCenter = [ox, oy, oz] + vY/2;
bCenter = [ox, oy, oz] - vY/2;
ul = uCenter - vX/2;
bl =  bCenter -vX/2;

rectPoints = [ul; ul+vX; bl+vX; bl];

nof_points = size(points, 1);
if nof_points ~= 0
    for i=1:nof_points
        xy = points(i, :);
        point = ul + xy(1)*[vX(1),vX(2),vX(3)] + xy(2)*[-vY(1),-vY(2),-vY(3)];
        hold on;
        plot3( point(1), point(2) , point(3) ,'.','MarkerSize',20,'color',[1,0,0]);
    end
end

%从左上=》右上
qh1 = quiver3(ul(1),ul(2),ul(3),vX(1),vX(2),vX(3),  'c', 'ShowArrowHead', 'off', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
%从左下=》右下
qh2 = quiver3(bl(1),bl(2),bl(3),vX(1),vX(2),vX(3),  'c',  'ShowArrowHead', 'off','MaxHeadSize', 0.999999, 'AutoScale', 'off');


rCenter = [ox, oy, oz] + vX/2;
lCenter = [ox, oy, oz] - vX/2;
rb = rCenter - vY/2;
lb =  lCenter - vY/2;
%从右下=》右上
qh3 = quiver3(rb(1),rb(2),rb(3), vY(1),vY(2),vY(3), 'c', 'ShowArrowHead', 'off', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
%从左下=》左上
qh4 = quiver3(lb(1),lb(2),lb(3), vY(1),vY(2),vY(3), 'c','ShowArrowHead', 'off',  'MaxHeadSize', 0.999999, 'AutoScale', 'off');

qHandles = [qh1, qh2, qh3, qh4];

end