%% useage: a script using AHRS algorithm to get the attitude and position of the phone


% Intro: 
% This is very hard tjo get position from IMU, because the IMU is only able to provide a direct measurement of acceleration (from the accelerometer) and the position must be derived from this through ¡®double integration¡¯; the accelerometer is first integrated to yield a velocity and then again to yield the position. 
% This process is called 'dead reckoning'.  The double integrate means that even the smallest measurement errors result in an exponentially increasing error in the position.

% Steps
% 1. read IMU data 
% 2. use AHRS algorithm to get the attitude of the phone 
% 3. get the acceleration in world frame 
% 4. double integrate

% Tricks
% 1. velocity-verlet
% 2. decayingModel
% 3. zeroVelocityRecorrect
% 4. manualCalibrate



%% housekeeping 
addpath('quaternion_library');	% include quatenrion library
close all;                     	% close all figures
clear;                         	% clear all variables
clc;                          	% clear the command terminal

%% flags

%useVelocityVerlet = 1;
%usePositionVerlet = 1;

decayingLamda = 0.7;

useAccZeroRecorrect = 0; % recorrect the acceleration in the phone frame
useGyrZeroRecorrect = 0;
useEarthAccZeroRecorrect = 1; % recorrect the acceleration in the world frame


% this is calulated from the still phone data 
useManualCalibrate = 1;
gra_x_mean =  -6.4107e-04;
gra_y_mean = -0.0392;
gra_z_mean = -0.9992;

%this flag decides use acc_raw or gravity  as the acceleration in phone frame
use_acc_raw = 0;

%% get imu data

%data = getIMUdata('./imu_newdata_stationary05.dat');
%data = getIMUdata('./imu_newdata_translation06_to_east.dat');
%data = getIMUdata('./imu_newdata_translation05_to_north.dat');
data = getIMUdata('./imu_newdata_rotate01.dat');

quatation_raw = data(:,1:4);  % 4 col
acc_raw = data(:,5:7);
rot_raw = data(:,8:10);
gravity_raw = data(:,11:13);
time_raw = data(:,14);

sampleNum = length(time_raw) ;
samplePeriod= sum(diff(time_raw))/sampleNum;

%gra_x_mean = sum(gravity_raw(:,1))/sampleNum
%gra_y_mean = sum(gravity_raw(:,2))/sampleNum
%gra_z_mean = sum(gravity_raw(:,3))/sampleNum

%% fix acc and gyr  rename variables

gyr = rot_raw;
if useManualCalibrate %make the data's mean be zero£¨or one£©
    gravity_raw(:,1) = gravity_raw(:,1) - gra_x_mean;
    gravity_raw(:,2) = gravity_raw(:,2) - gra_y_mean;
    gravity_raw(:,3) = gravity_raw(:,3) - gra_z_mean -1;
end
acc = [-gravity_raw(:,1),  -gravity_raw(:,2),  -gravity_raw(:,3)];

%{
if useAccZeroRecorrect
    
    thresh = 0.01;  % important threshhold 
    accX_thresh = thresh;
    accY_thresh = thresh;
    accZ_thresh = thresh;
    lastZeroThresh = 5;

    lastAccZeroCount = zeros(sampleNum,1);
    counter_temp = 0;

    % must start quietly !!!
    % make the first 
    for i = 1:lastZeroThresh % if start quietly 
        if acc(i,1)<accX_thresh && acc(i,2)<accY_thresh && acc(i,3)<accZ_thresh
            lastAccZeroCount(i) = lastZeroThresh + 1; 
            counter_temp = counter_temp + 1;
        end
    end
    
    for i = lastZeroThresh:sampleNum
        if acc(i,1)<accX_thresh && acc(i,2)<accY_thresh && (acc(i,3)-1)<accZ_thresh % get the number of zero happened before 
            counter_temp = counter_temp + 1;
            lastAccZeroCount(i) = counter_temp;
        else
            counter_temp = 0;
            lastAccZeroCount(i) = counter_temp; % not neceressary
        end
    end

end
%}

%{
if useGyrZeroRecorrect
    
    thresh = 0.01;  % important threshhold 
    gyrX_thresh = thresh;
    gyrY_thresh = thresh;
    gyrZ_thresh = thresh*2;  % the error in z-axis is a little bigger
    lastZeroThresh = 5;

    lastGyrZeroCount = zeros(sampleNum,1);
    counter_temp = 0;

    % must start quietly !!!
    % make the first 
    for i = 1:lastZeroThresh % if start quietly 
        if gyr(i,1)<gyrX_thresh && gyr(i,2)<gyrY_thresh && gyr(i,3)<gyrZ_thresh
            lastGyrZeroCount(i) = lastZeroThresh + 1; 
            counter_temp = counter_temp + 1;
        end
    end
    
    for i = lastZeroThresh:sampleNum
        if gyr(i,1)<gyrX_thresh && gyr(i,2)<gyrY_thresh && gyr(i,3)<gyrZ_thresh % get the number of zero happened before 
            counter_temp = counter_temp + 1;
            lastGyrZeroCount(i) = counter_temp;
        else
            counter_temp = 0;
            lastGyrZeroCount(i) = counter_temp; % not neceressary
        end
    end

end

mag = quatation_raw;
%}

%% Process data through AHRS algorithm (calcualte orientation)
% See: http://www.x-io.co.uk/open-source-imu-and-ahrs-algorithms/

R = zeros(3,3,length(gyr));     % rotation matrix describing sensor relative to Earth

%{
if useGyrZeroRecorrect
    for i = 1:length(gyr)
        if(lastGyrZeroCount(i)>lastZeroThresh)
            gyr(i,:) = zeros(1,3);  %£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿
        end
    end
end
%}

ahrs = MahonyAHRS('SamplePeriod', samplePeriod, 'Kp',1 );  %###

for i = 1:length(gyr)
    ahrs.UpdateIMU(gyr(i,:), acc(i,:));	% gyroscope units must be radians
    R(:,:,i) = quatern2rotMat(ahrs.Quaternion)';    % transpose because ahrs provides Earth relative to sensor
end

%{
if useAccZeroRecorrect && useGyrZeroRecorrect
    for i = 1:length(gyr)
        if (lastGyrZeroCount(i)>lastZeroThresh)
            R(:,:,i) = eye(3);
        end
    end
end
%}

%% Calculate 'tilt-compensated' accelerometer( get the acceleration in the world frame£¨with gravity£©)
% Plot
figure('Number', 'off', 'Name', 'acc in Phone frame');
hold on;
plot(acc(:,1), 'r');
plot(acc(:,2), 'g');
plot(acc(:,3), 'b');
xlabel('sample');
ylabel('g');
title('acc in Phone frame');
legend('X', 'Y', 'Z');

tcAcc = zeros(size(acc));  % accelerometer in Earth frame

if use_acc_raw
    acc = acc_raw; %for debugging
end

for i = 1:length(acc)
    tcAcc(i,:) = R(:,:,i) * acc(i,:)';
end


%% prepare for zero recorrect by analyzing the tcAcc
%lastAccZeroCount records how many accelerations in a row before is near zero
if useEarthAccZeroRecorrect
    thresh = 0.05;  % important threshhold 
    accX_thresh = thresh;
    accY_thresh = thresh;
    accZ_thresh = thresh;
    lastZeroThresh = 5;

    lastAccZeroCount = zeros(sampleNum,1);
    counter_temp = 0;

    % must start quietly !!!
    % make the first 
    for i = 1:lastZeroThresh % if start quietly 
        if tcAcc(i,1)<accX_thresh && tcAcc(i,2)<accY_thresh && tcAcc(i,3)<accZ_thresh
            lastAccZeroCount(i) = lastZeroThresh + 1; 
            counter_temp = counter_temp + 1;
        end
    end
    
    for i = lastZeroThresh:sampleNum
        if tcAcc(i,1)<accX_thresh && tcAcc(i,2)<accY_thresh && tcAcc(i,3)<accZ_thresh % get the number of zero happened before 
            counter_temp = counter_temp + 1;
            lastAccZeroCount(i) = counter_temp;
        else
            counter_temp = 0;
            lastAccZeroCount(i) = counter_temp; % not neceressary
        end
    end
    
end

%{
% Plot
figure('Number', 'off', 'Name', 'acc in Earth frame');
hold on;
plot(tcAcc(:,1), 'r');
plot(tcAcc(:,2), 'g');
plot(tcAcc(:,3), 'b');
xlabel('sample');
ylabel('g');
title('acc in Earth frame (with gravity)');
legend('X', 'Y', 'Z');
%}
%% Calculate linear acceleration in Earth frame (subtracting gravity)

linAcc = tcAcc - [zeros(length(tcAcc), 1), zeros(length(tcAcc), 1), ones(length(tcAcc), 1)];
if use_acc_raw
    linAcc = tcAcc; % for debugging
end
linAcc = linAcc * 9.81;     % convert from 'g' to m/s/s

% Plot
figure('Number', 'off', 'Name', 'linacc in Earth frame');
hold on;
plot(linAcc(:,1), 'r');
plot(linAcc(:,2), 'g');
plot(linAcc(:,3), 'b');
xlabel('sample');
ylabel('g');
title('linacc in Earth frame (without gravity)');
legend('X', 'Y', 'Z');

%% Calculate linear velocity (integrate acceleartion)

linVel = zeros(size(linAcc));

for i = 2:length(linAcc)
    if useEarthAccZeroRecorrect %use zero recorrect 
                if(lastAccZeroCount(i)>lastZeroThresh)
                    linVel(i,:) = 0;
                else
                    linVel(i,:) = linVel(i-1,:) + 0.5*decayingLamda*(linAcc(i,:)+linAcc(i-1,:)) * samplePeriod;
                    %linVel(i,:) = linVel(i-1,:) + decayingLamda*0.5*(linAcc(i,:)+linAcc(i-1,:)) * samplePeriod;
                end
    else % no zero recorrect
        inVel(i,:) = linVel(i-1,:) + 0.5*decayingLamda*(linAcc(i,:)+linAcc(i-1,:)) * samplePeriod;
                %linVel(i,:) = linVel(i-1,:) + decayingLamda*0.5*(linAcc(i,:)+linAcc(i-1,:)) * samplePeriod;
    end

end


% Plot
figure('Number', 'off', 'Name', 'Linear Velocity');
hold on;
plot(linVel(:,1), 'r');
plot(linVel(:,2), 'g');
plot(linVel(:,3), 'b');
xlabel('sample');
ylabel('g');
title('linear velocity');
legend('X', 'Y', 'Z');

%% Calculate linear position (integrate velocity)
linVelHP = linVel;
linPos = zeros(size(linVelHP));

% use position-verlet 
for i = 2:length(linVelHP)
    linPos(i,:) = linPos(i-1,:) + 0.5*decayingLamda*(linVelHP(i-1,:)+linVelHP(i,:) )* samplePeriod;
end

% Plot
figure('Number', 'off', 'Name', 'Linear Position');
hold on;
plot(linPos(:,1), 'r');
plot(linPos(:,2), 'g');
plot(linPos(:,3), 'b');
xlabel('sample');
ylabel('g');
title('Linear position');
legend('X', 'Y', 'Z');


%% Play animation

SamplePlotFreq = 8;
linPosHP = linPos;
%linPosHP = zeros(size(linPos)); % for debugging
SixDOFanimation(linPosHP, R, ...
                'SamplePlotFreq', SamplePlotFreq, 'Trail', 'Off', ...
                'Position', [9 39 1280 720], ...
                'AxisLength', 0.1, 'ShowArrowHead', false, ...
                'Xlabel', 'X (m)', 'Ylabel', 'Y (m)', 'Zlabel', 'Z (m)', 'ShowLegend', false, 'Title', 'Unfiltered',...
                'CreateAVI', true, 'AVIfileNameEnum', false, 'AVIfps', ((1/samplePeriod) / SamplePlotFreq));        






















