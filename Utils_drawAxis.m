function Utils_drawAxis(R, p)

 
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
hold on;
quiver3(ox, oy, oz, uy, vy, wy,  'g', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');
hold on;
quiver3(ox, oy, oz, uz, vz, wz,  'b', 'ShowArrowHead', 'on', 'MaxHeadSize', 0.999999, 'AutoScale', 'off');

drawnow;

end