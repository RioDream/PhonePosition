function R = Quater_2Mat(q)

%{
    输入的是坐标变换四元数
    输出的也是坐标变换矩阵

    反之，如果

    输入的是坐标系变换四元数
    输出的也是坐标系变换矩阵
%}

assert(Debug_isNearlyEqual(norm(q), 1.0), ['RioError: 四元数norm不为 1， gap为', num2str(norm(q)-1.0)] );

q1 = q(1);
q2 = q(2);
q3 = q(3);
q4 = q(4);


R = [ q1^2 - q2^2 - q3^2 + q4^2 ,   2*q1*q2 + 2*q3*q4,          2*q1*q3 - 2*q2*q4;
        2*q1*q2 - 2*q3*q4,  -q1^2+q2^2-q3^2+q4^2,        2*q1*q4 + 2*q2*q3;
       2*q1*q3 + 2*q2*q4,      2*q2*q3 - 2*q1*q4,            -q1^2 - q2^2 + q3^2 + q4^2];


end