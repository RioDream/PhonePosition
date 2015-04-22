function Plot_drawCovWithError(covs, errors)
%{
Usage:
    画出模拟实验中的cov和error的图像
    
    errors:
        errors的格式是这样的
        18 x nof_samples
    covs:
        covs的格式也是类似的

    error 和 cov：
    1~3行 ： q error
    4~6行 : p error
    7~9行 ： v error
    10~12行 : bg error
    13~15行 : ba error
    16~18行 : P_IinC error 

    注意和 error state vector 的顺序不一样
%}

stds = sqrt(covs);


%% attitude
figure('Number', 'off');
hold on;
plot(stds(1,:), 'r');
plot(stds(2,:), 'g');
plot(stds(3,:), 'b');
plot(errors(1, :), 'r.');
plot(errors(2, :), 'g.');
plot(errors(3, :), 'b.');

plot(3*stds(1,:), 'r:');
plot(-3*stds(1,:), 'r:');

plot(3*stds(2,:), 'g:');
plot(-3*stds(2,:), 'g:');

plot(3*stds(3,:), 'b:');
plot(-3*stds(3,:), 'b:');

xlabel('IMU frame');
ylabel('cov');
title('attitude error cov');
legend('X std', 'Y std', 'Z std', 'X error', 'Y error', 'Z error');


%% position
figure('Number', 'off');
hold on;
plot(stds(4,:), 'r');
plot(stds(5,:), 'g');
plot(stds(6,:), 'b');
plot(errors(4, :), 'r.');
plot(errors(5, :), 'g.');
plot(errors(6, :), 'b.');

plot(3*stds(4,:), 'r:');
plot(-3*stds(4,:), 'r:');

plot(3*stds(5,:), 'g:');
plot(-3*stds(5,:), 'g:');

plot(3*stds(6,:), 'b:');
plot(-3*stds(6,:), 'b:');


xlabel('IMU frame');
ylabel('cov');
title('position error cov');
legend('X std', 'Y std', 'Z std', 'X error', 'Y error', 'Z error');


%% velocity
figure('Number', 'off');
hold on;
plot(stds(7,:), 'r');
plot(stds(8,:), 'g');
plot(stds(9,:), 'b');

plot(errors(7, :), 'r.');
plot(errors(8, :), 'g.');
plot(errors(9, :), 'b.');

plot(3*stds(7,:), 'r:');
plot(-3*stds(7,:), 'r:');

plot(3*stds(8,:), 'g:');
plot(-3*stds(8,:), 'g:');

plot(3*stds(9,:), 'b:');
plot(-3*stds(9,:), 'b:');

xlabel('IMU frame');
ylabel('cov');
title('velocity error cov');
legend('X std', 'Y std', 'Z std', 'X error', 'Y error', 'Z error');

%bias_G
figure('Number', 'off');
hold on;
plot(stds(10,:), 'r');
plot(stds(11,:), 'g');
plot(stds(12,:), 'b');

plot(errors(10, :), 'r.');
plot(errors(11, :), 'g.');
plot(errors(12, :), 'b.');

plot(3*stds(10,:), 'r:');
plot(-3*stds(10,:), 'r:');

plot(3*stds(11,:), 'g:');
plot(-3*stds(11,:), 'g:');

plot(3*stds(12,:), 'b:');
plot(-3*stds(12,:), 'b:');

xlabel('IMU frame');
ylabel('cov');
title('bias_G error cov');
legend('X std', 'Y std', 'Z std', 'X error', 'Y error', 'Z error');


%bias_A
figure('Number', 'off');
hold on;
plot(stds(13,:), 'r');
plot(stds(14,:), 'g');
plot(stds(15,:), 'b');

plot(errors(13, :), 'r.');
plot(errors(14, :), 'g.');
plot(errors(15, :), 'b.');

plot(3*stds(13,:), 'r:');
plot(-3*stds(13,:), 'r:');

plot(3*stds(14,:), 'g:');
plot(-3*stds(14,:), 'g:');

plot(3*stds(15,:), 'b:');
plot(-3*stds(15,:), 'b:');

xlabel('IMU frame');
ylabel('cov');
title('bias_A error cov');
legend('X std', 'Y std', 'Z std', 'X error', 'Y error', 'Z error');



%Calibrate
figure('Number', 'off');
hold on;
plot(stds(16,:), 'r');
plot(stds(17,:), 'g');
plot(stds(18,:), 'b');

plot(errors(16, :), 'r.');
plot(errors(17, :), 'g.');
plot(errors(18, :), 'b.');

plot(3*stds(16,:), 'r:');
plot(-3*stds(16,:), 'r:');

plot(3*stds(17,:), 'g:');
plot(-3*stds(17,:), 'g:');

plot(3*stds(18,:), 'b:');
plot(-3*stds(18,:), 'b:');

xlabel('IMU frame');
ylabel('cov');
title('P_IinC error cov');
legend('X std', 'Y std', 'Z std', 'X error', 'Y error', 'Z error');

title('p_IinC error cov');


%% lambda 
figure('Number', 'off');
hold on;
x = 1:length(errors);

plot(errors(19, :), 'b.');
ylim([-0.5,0.5]);
plot(3*stds(19,:), 'b:');
plot(-3*stds(19,:), 'b:');

set(gca,'xtick',1:500:length(errors),'xticklabel',1:5:60) %xtick就是你要在哪些地方显示刻度，xticklabel就是显示什么

xlabel('时间/秒');
ylabel('误差');
title('尺度因子误差变化');
legend('尺度因子误差', '尺度因子方差的3std边界');




end