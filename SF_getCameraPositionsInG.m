function SF_getCameraPositionsInG()


%[R, t] = Utils_load;
X = [-1.000000000000000
  -0.950000000000000
                   0];
K = [1041           0         320
           0        1136         240
           0           0           1];
R = [0.018854000000000   0.999679000000000  -0.016897900000000
  -0.907455000000000   0.010014800000000  -0.420029000000000
  -0.419725000000000   0.023253300000000   0.907353000000000];
t = [0.219606000000000
   0.087381500000000
   9.677180000000000];

x = K*(R*X+t)
%原来得到的是 inverted的， 通过下面这两句变回来
%R_G2C = transpose(R);
%t = -t;
R_G2C = R;
p_GinC = t;




%到这里 x = K*(R*X + t), 也就是 R：R_G2C,  t： p_GinC

p_CinG = -transpose(R_G2C)*p_GinC;

figure;
axis equal;
Utils_drawAxis(eye(3), zeros(3,1)); %G
hold on;
Utils_drawAxis(R_G2C.', p_CinG); %C
axis equal;
end