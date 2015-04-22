function errors = ANA_computeErrorAndAppend(errors,  X, gt_q, gt_p, gt_v, gt_bg, gt_ba)
%{
    Usage:
        计算出当前一个state vector和 ground truth 之间的error, 并且 append到 errors当中

        X中包含着估计的state
        gt_q, gt_p, gt_v 分别是 ground_truth 的 q p v 

        errors的格式是这样的
        18 x nof_samples
%}

%% get estimate state
[q_G2I, p, v, bias_G, bias_A ] = SKF_X_getIMUpart(X);
[p_IinC, lambda] = SKF_getOtherPart(X);

nof_rows = size(errors, 1);
errors = [errors,  zeros(nof_rows, 1)];

%% 将quaternion转换为 欧拉角
[gt_a , gt_b, gt_c] = Quater_2Euler(gt_q);
[a , b, c] = Quater_2Euler(q_G2I);


%% 计算error
%误差定义是 error = 真值 - 估计值
errors(1, end) = gt_a - a ; %!!!
errors(2, end) = gt_b - b; %!!!
errors(3, end) = gt_c - c; %!!!
errors(4, end) = gt_p(1) - p(1);
errors(5, end) = gt_p(2) - p(2);
errors(6, end) = gt_p(3) - p(3);
errors(7, end) = gt_v(1) - v(1);
errors(8, end) = gt_v(2) - v(2);
errors(9, end) = gt_v(3) - v(3);
errors(10, end) = gt_bg(1) - bias_G(1); 
errors(11, end) = gt_bg(2) - bias_G(2);
errors(12, end) = gt_bg(3) - bias_G(3);
errors(13, end) = gt_ba(1) - bias_A(1);
errors(14, end) = gt_ba(2) - bias_A(2);
errors(15, end) = gt_ba(3) - bias_A(3);
errors(16, end) = 0 - p_IinC(1);
errors(17, end) = 0 - p_IinC(2);
errors(18, end) = 0 - p_IinC(3);
errors(19, end) = 1 - lambda;


end