function EX_plotBothTraj(Ts, p_IinGs)
%{
Usage:
    Ts: 是用visual方法获得的轨迹 每一列是一个坐标
    p_CinSs：是用ekf获得的轨迹 每一列是一个坐标
%}

close all;

%% plot ekf traj
ps_ = p_IinGs;
plot3(ps_(:,1), ps_(:,2), ps_(:,3), 'r-' , 'LineWidth',0.05)
axis equal;
hold on;

xlim([-0.02 0.035]);
ylim([0 0.02]);
zlim([-0.05 0.01]);

%% plot visual traj
ps_ = Ts;

%plot pattern
scale = 0.135/9.81 ;
fill3(scale*[0 1 1 0],scale*[0 0 0.95 0.95],[0 0 0 0],'c');
hold on;
s_ = 0.5*scale;
quiver3(0, 0, 0, s_, 0, 0,  'r', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
quiver3(0, 0, 0, 0, s_, 0,  'g', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
quiver3(0, 0, 0, 0, 0, s_,  'b', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');

%{
npts = 13;
xyz = ps_;
plot3(xyz(:,1),xyz(:,2),xyz(:,3),'r.','LineWidth',0.05);
axis equal;

ax = gca;
axis([-0.03 0.04 -0.03 0.03]);
ax.XTick = [-1:0.1:1];
ax.YTick = [-1,1];
ax.ZTick = [-1,1];

hold on
%fnplt(cscvn(xyz(:,[1:end 1])),'r',1)
hold off
%}

end