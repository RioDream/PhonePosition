function EX_plotScales(scales)

trueVal = 0.135;
errRatio = 0.05;

scales = scales*2.0;
nof_trials = length(scales);

figure;
plot(1:nof_trials, scales, 'o');
ylim([0.08,0.18]);
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