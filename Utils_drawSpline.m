close all;
ps_ = ps(:,1:30:end);

%plot pattern
scale = MAKE_LAMBDA_ONE_SCALE ;
fill3(scale*[0 1 1 0],scale*[0 0 0.95 0.95],[0 0 0 0],'c');
hold on;
s_ = 0.5*scale;
quiver3(0, 0, 0, s_, 0, 0,  'r', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
quiver3(0, 0, 0, 0, s_, 0,  'g', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
quiver3(0, 0, 0, 0, 0, s_,  'b', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');


npts = 13;
xyz = ps_;
plot3(xyz(1,:),xyz(2,:),xyz(3,:),'r.','LineWidth',0.1);
axis equal;

ax = gca;
axis([-0.03 0.04 -0.03 0.03]);
ax.XTick = [-1:0.1:1];
ax.YTick = [-1,1];
ax.ZTick = [-1,1];

hold on
fnplt(cscvn(xyz(:,[1:end 1])),'r',1)
hold off

