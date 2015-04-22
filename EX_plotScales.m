function EX_plotScales(scales)


%permute
bad_idx= [9,10,11,12,14,15];
bad_scales = scales(bad_idx);
scales(bad_idx)= [];
scales = [scales, bad_scales];

trueVal = 1;
errRatio = 0.05;

scales = scales*1.0;
nof_trials = length(scales);

figure;
plot(1:10, scales(1:10), 'o');
hold on;
plot(11:16, scales(11:end), '*');
ylim([0.6,1.3]);
legend('运动周期性较显著的实验结果','运动周期性较弱的实验结果')
xlabel('实验次数');
ylabel('估计结果');
hold on;

trueLineX = 0:nof_trials;
trueLineY =  ones(nof_trials+1,1) * trueVal;
plot(trueLineX,  trueLineY , '-g');

%% plot error
upperLineY =  ones(nof_trials+1,1) * trueVal*(1+errRatio);
plot(trueLineX,  upperLineY, '-r');

lowerLineY =  ones(nof_trials+1,1) * trueVal*(1-errRatio);
plot(trueLineX,  lowerLineY, '-r');

end