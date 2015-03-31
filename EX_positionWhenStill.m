function EX_positionWhenStill()
%{
Usage:
    利用在静止状态下获得的加速度信息进行积分，获得位移
%}
infoDir = './EX_data/still/';
[timestamps, linaccs] = Utils_loadIMUdata(infoDir);

%
g = zeros(size(linaccs));
g(:,3) = 1;
linaccs = linaccs  + g;
linaccs = -linaccs;

PLOT = 1;
samplePeriod = 0.01;

%% 绘制直接得到的加速度信息
linAcc = linaccs;
if PLOT
    % Plot
    figure('Number', 'off', 'Name', 'linAcc');
    hold on;
    plot(linAcc(:,1), 'r');
    plot(linAcc(:,2), 'g');
    plot(linAcc(:,3), 'b');
    xlabel('sample');
    ylabel('g');
    title('linAcc');
    legend('X', 'Y', 'Z');
end

%%二重积分，得到position
linVel = zeros(size(linAcc)); %初始速度是0
for i = 2:length(linAcc)
    linVel(i,:) = linVel(i-1,:) + linAcc(i,:) * samplePeriod;
end

linVelHP = linVel;
linPos = zeros(size(linVelHP));

for i = 2:length(linVelHP)
    linPos(i,:) = linPos(i-1,:) + linVelHP(i,:) * samplePeriod;
end

%% 绘制得到的position
linPosHP = linPos;
if PLOT
    % Plot
    figure('Number', 'off', 'Name', 'High-pass filtered Linear Position');
    hold on;
    plot(linPosHP(:,1), 'r');
    plot(linPosHP(:,2), 'g');
    plot(linPosHP(:,3), 'b');
    xlabel('sample');
    ylabel('g');
    title('High-pass filtered linear position');
    legend('X', 'Y', 'Z');
end



    
end