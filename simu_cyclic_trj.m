%% useage: a script using windows phone API to get the attitude and position of the phone


% Intro: 
% This is very hard tjo get position from IMU, because the IMU is only able to provide a direct measurement of acceleration (from the accelerometer) and the position must be derived from this through ¡®double integration¡¯; the accelerometer is first integrated to yield a velocity and then again to yield the position. 
% This process is called 'dead reckoning'.  The double integrate means that even the smallest measurement errors result in an exponentially increasing error in the position.

% Steps
% 1. read IMU data £¬ including the attitude and the acceleration in the
% phone frame 
% 2. get the acceleration in world frame 
% 3. double integrate

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

useVelocityVerlet = 1;
usePositionVerlet = 1;

useDecayingModel = 1;
decayingLamda = 1.0;

useZeroRecorrect = 1;

%the mean of acceleration of the phone from API
useManualCalibrate = 1;
xMean = -0.001405488948695;
yMean = -0.004510544296988;
zMean = -0.011079017214859;


%% get imu data
%data = getIMUdata('./imu_newdata_translation05_to_north.dat');
data = getIMUdata('./newdata_boya04.dat');

quatation_raw = data(:,1:4);  % 4 col
acc_raw = data(:,5:7);
rot_raw = data(:,8:10);
gravity_raw = data(:,11:13);
time_raw = data(:,14);

sampleNum = length(time_raw) ;  
sampleTime = sum(diff(time_raw))/sampleNum;

samplePeriod = 1/50.0;

%% calibrate the accelerometer
acc = acc_raw;
%xMean = sum(acc(:,1))/num;
%yMean = sum(acc(:,2))/num;
%zMean = sum(acc(:,3))/num;

if useManualCalibrate
    accCalibMat = zeros(size(acc));
    accCalibMat(:,1) = xMean;
    accCalibMat(:,2) = yMean;
    accCalibMat(:,3) = zMean;
    acc = acc-accCalibMat;
end

%% prepare for  zero recorrect 
if useZeroRecorrect
    
    thresh = 0.02;  % important threshhold 
    accX_thresh = thresh;
    accY_thresh = thresh;
    accZ_thresh = thresh;
    lastZeroThresh = 5;

    lastZeroCount = zeros(sampleNum,1);
    counter_temp = 0;

    % must start quietly !!!
    % make the first 
    for i = 1:lastZeroThresh % if start quietly 
        if acc(i,1)<accX_thresh && acc(i,2)<accY_thresh && acc(i,3)<accZ_thresh
            lastZeroCount(i) = lastZeroThresh + 1; 
            counter_temp = counter_temp + 1;
        end
    end
    
    for i = lastZeroThresh:sampleNum
        if acc(i,1)<accX_thresh && acc(i,2)<accY_thresh && acc(i,3)<accZ_thresh % get the number of zero happened before 
            counter_temp = counter_temp + 1;
            lastZeroCount(i) = counter_temp;
        else
            counter_temp = 0;
            lastZeroCount(i) = counter_temp; % not neceressary
        end
    end
end

%% get rot matrix from quad
R = zeros(3,3,sampleNum);     % rotation matrix describing sensor relative to Earth

for i = 1:sampleNum
    R(:,:,i) = quatern2rotMat(quatation_raw(i,:))';    % attention !   transpose because ahrs provides Earth relative to sensor
end

%% Calculate 'tilt-compensated' accelerometer

tcAcc = zeros(size(acc));  % accelerometer in Earth frame
for i = 1:sampleNum
    tcAcc(i,:) = R(:,:,i) * acc(i,:)'; 
end

%% Calculate linear acceleration in Earth frame

linAcc = tcAcc;
linAcc = linAcc * 9.81;

% Plot
figure('Number', 'off', 'Name', 'Linear acceleration');
hold on;
plot(linAcc(:,1), 'r');
plot(linAcc(:,2), 'g');
plot(linAcc(:,3), 'b');
xlabel('sample');
ylabel('g');
title('Linear acc');
legend('X', 'Y', 'Z');


%% Calculate linear velocity (integrate acceleartion)

linVel = zeros(size(linAcc));

for i = 2:length(linAcc)
    %samplePeriod = time_raw(i)-time_raw(i-1);
    %samplePeriod_sum  = samplePeriod_sum+ samplePeriod ;
    if useVelocityVerlet
        if useDecayingModel
            if useZeroRecorrect %use zero recorrect 
                if(lastZeroCount(i)>lastZeroThresh)
                    linVel(i,:) = 0;
                else
                    linVel(i,:) = linVel(i-1,:) + decayingLamda*0.5*(linAcc(i,:)+linAcc(i-1,:)) * samplePeriod;
                end
            else % no zero recorrect
                linVel(i,:) = linVel(i-1,:) + decayingLamda*0.5*(linAcc(i,:)+linAcc(i-1,:)) * samplePeriod;
            end
        else
            linVel(i,:) = linVel(i-1,:) + 0.5*(linAcc(i,:)+linAcc(i-1,:)) * samplePeriod;
        end
    else
        linVel(i,:) = linVel(i-1,:) + linAcc(i,:) * samplePeriod;
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
title('Linear velocity');
legend('X', 'Y', 'Z');

%% remove velocity drift 
if useZeroRecorrect
 
    stationary = lastZeroCount > lastZeroThresh;
    velDrift = zeros(size(linVel));
    stationaryStart = find([0; diff(stationary)] == -1); % stationary£º1-> 0  before start to move
    stationaryEnd = find([0; diff(stationary)] == 1); % stationary£º0-> 1 after move 
    %make every step linear
    for i = 1:numel(stationaryEnd) %traverse all stationaryEnd vector 
        % the drift per sample while stationary 
        driftRate = linVel(stationaryEnd(i)-1, :) / (stationaryEnd(i) - stationaryStart(i));
        % stationary enum 
        enum = 1:(stationaryEnd(i) - stationaryStart(i));
        % get every drift of per sample 
        drift = [enum'*driftRate(1) enum'*driftRate(2) enum'*driftRate(3)];
        % assign dirift to velDrift
        velDrift(stationaryStart(i):stationaryEnd(i)-1, :) = drift;
    end
end


%% High-pass filter linear velocity to remove drift

order = 1;
filtCutOff = 0.1;
[b, a] = butter(order, (2*filtCutOff)/(1/samplePeriod), 'high');
linVelHP = filtfilt(b, a, linVel);

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



%% Calculate linear position (integrate velocity)
%linVelHP = linVel;


linPos = zeros(size(linVelHP));

for i = 2:length(linVelHP)
    if usePositionVerlet
         if useDecayingModel
            linPos(i,:) = linPos(i-1,:) + decayingLamda*0.5*(linVelHP(i-1,:)+linVelHP(i,:)) * samplePeriod; 
         else
            linPos(i,:) = linPos(i-1,:) + 0.5*(linVelHP(i-1,:)+linVelHP(i,:)) * samplePeriod;
         end
    else
        linPos(i,:) = linPos(i-1,:) + linVelHP(i,:) * samplePeriod;
    end
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


%% High-pass filter linear position to remove drift

order = 1;
filtCutOff = 0.1;
[b, a] = butter(order, (2*filtCutOff)/(1/samplePeriod), 'high');
linPosHP = filtfilt(b, a, linPos);

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
    

%linPosHP = linPos;

%% Play animation


%linPosHP = zeros(size(linPosHP));

SamplePlotFreq = 8;


SixDOFanimation(linPosHP, R, ...
                'SamplePlotFreq', SamplePlotFreq, 'Trail', 'Off', ...
                'Position', [9 39 1280 720], ...
                'AxisLength', 0.1, 'ShowArrowHead', false, ...
                'Xlabel', 'X (m)', 'Ylabel', 'Y (m)', 'Zlabel', 'Z (m)', 'ShowLegend', false, 'Title', 'Unfiltered',...
                'CreateAVI', true, 'AVIfileNameEnum', false, 'AVIfps', ((1/samplePeriod) / SamplePlotFreq));            








