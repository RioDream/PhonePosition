function res = Debug_isNearlyEqual(num1, num2)
%{
 Usage:
    检测两个浮点数是不是相等
%}
res = abs(num1-num2)<1e-6; %!!!
