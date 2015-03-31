function [linVelHP, linPosHP] = SF_getLinPosHP(linaccs, gVal)
    %{
    Usage:
        得到linPosHP,  也就是经过高通滤波的pos信息

    主要的变量：
        linAcc: 线性加速度， 有两种获取方法， 
                    1. 直接通过 api获得 linacc
                    2. 通过api 获得 accs 和 qs， 然后通过公式， 得到转化而来的 linAcc
        linVel:      linAcc 经过积分而来的 velocity
        linVelHP:  linVel 经过 高通滤波之后
        linPos:     linVelHP 经过积分得到
        linPosHP: linPos 经过高通滤波, 得到最终的位置

        以上这几个变量都是 N*3 的， 即每一行代表一个信息。


    %}

    %% config
    samplePeriod = 0.01;
    PLOT = 1;
    PLOT_ANIMATION = 0;

    %% 1. load data


    %% 2. 利用linaccs 积分得到在世界坐标系中的 linVel

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
    order = 1;
    filtCutOff = 0.1;
    [b, a] = butter(order, (2*filtCutOff)/(1/samplePeriod), 'low');
    linAccLP = filtfilt(b, a, linAcc);
    [b, a] = butter(order, (2*filtCutOff)/(1/samplePeriod), 'high');
    linAccLP = filtfilt(b, a, linAccLP);
    
    if 0
        % Plot
        figure('Number', 'off', 'Name', 'linAccLP');
        hold on;
        plot(linAccLP(:,1), 'r');
        plot(linAccLP(:,2), 'g');
        plot(linAccLP(:,3), 'b');
        xlabel('sample');
        ylabel('g');
        title('linAccLP');
        legend('X', 'Y', 'Z');
    end
    
    %=====================
        
    
    
    linVel = zeros(size(linAcc)); %初始速度是0
    for i = 2:length(linAcc)
        linVel(i,:) = linVel(i-1,:) + linAcc(i,:) * samplePeriod;
    end
    
    

    %% 3. 对linVel 进行滤波, 得到 linVelHp

    if 0
        % Plot
        figure('Number', 'off', 'Name', 'High-pass filtered Linear Velocity');
        hold on;
        plot(linVel(:,1), 'r');
        plot(linVel(:,2), 'g');
        plot(linVel(:,3), 'b');
        xlabel('sample');
        ylabel('g');
        title('linear velocity');
        legend('X', 'Y', 'Z');
    end
    
    order = 1;
    filtCutOff = 0.1;
    [b, a] = butter(order, (2*filtCutOff)/(1/samplePeriod), 'high');
    linVelHP = filtfilt(b, a, linVel);


    if PLOT
        % Plot
        figure('Number', 'off', 'Name', 'High-pass filtered Linear Velocity');
        hold on;
        plot(linVelHP(:,1), 'r');
        plot(linVelHP(:,2), 'g');
        plot(linVelHP(:,3), 'b');
        xlabel('sample');
        ylabel('g');
        title('High-pass filtered linear velocity');
        legend('X', 'Y', 'Z');
    end

    %% 4. 对 linVelHp 进行积分， 得到 linPos

    linPos = zeros(size(linVelHP));

    for i = 2:length(linVelHP)
        linPos(i,:) = linPos(i-1,:) + linVelHP(i,:) * samplePeriod;
    end

    %% 5. 对 linPos 进行滤波，得到 linPosHP

    if 0
        % Plot
        figure('Number', 'off', 'Name', 'High-pass filtered Linear Position');
        hold on;
        plot(linPos(:,1), 'r');
        plot(linPos(:,2), 'g');
        plot(linPos(:,3), 'b');
        xlabel('sample');
        ylabel('g');
        title('linear position');
        legend('X', 'Y', 'Z');
    end
    
    order = 1;
    filtCutOff = 0.1;
    [b, a] = butter(order, (2*filtCutOff)/(1/samplePeriod), 'high');
    linPosHP = filtfilt(b, a, linPos);

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

    %% Play animation

    %单位转换成 m
    linPosHP = gVal * linPosHP;

    %Use fake rotation
    R = zeros(3,3,length(linPosHP));
    for i=1:length(linPosHP)
        R(:,:,i) = eye(3);
    end


    if PLOT_ANIMATION 
        SamplePlotFreq = 8;

        SixDOFanimation(linPosHP, R, ...
                        'SamplePlotFreq', SamplePlotFreq, 'Trail', 'Off', ...
                        'Position', [9 39 1280 720], ...
                        'AxisLength', 0.1, 'ShowArrowHead', false, ...
                        'Xlabel', 'X (m)', 'Ylabel', 'Y (m)', 'Zlabel', 'Z (m)', 'ShowLegend', false, 'Title', 'Unfiltered',...
                        'CreateAVI', true, 'AVIfileNameEnum', false, 'AVIfps', ((1/samplePeriod) / SamplePlotFreq)); 
    end

end