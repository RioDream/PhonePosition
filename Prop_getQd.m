function Qd = Prop_getQd(PHI,  sigma_gc, sigma_ac, sigma_wgc, sigma_wac, deltaT)
%{
    借鉴 [TUM] 6.44, 需要推导一个和 MSCKF2.0匹配的式子

% q v p bg ba版

    Nc = 
        [ sigma_gc^2,      0,        0,         0,                   0]
        [        0,      sigma_ac^2,  0,         0,                   0]
        [        0,             0,          0,         0,                   0]
        [        0,             0,          0,      sigma_wgc^2,         0]
        [        0,             0,          0,         0,           sigma_wac^2]

Nc = zeros(15,15);
Nc(1:3,   1:3) = sigma_gc^2*eye(3);
Nc(4:6,   4:6) = sigma_ac^2*eye(3);
Nc(10:12, 10:12) = sigma_wgc^2*eye(3);
Nc(13:15, 13:15) = sigma_wac^2*eye(3);

%}

%{
q p v bg ba 版

[ sigma_gc^2, 0,            0,                   0,                      0]
[        0,         0,             0,                   0,                    0]
[        0,         0,      sigma_ac^2,         0,                      0]
[        0,         0,             0,           sigma_wgc^2,         0]
[        0,         0,             0,                   0,              sigma_wac^2]

    参见 sym_Nc.m 和 verify_Nc.m , 记得脑补 ^2

%}

Nc = zeros(15,15);
Nc(1:3,   1:3) = sigma_gc^2*eye(3);
Nc(7:9,   7:9) = sigma_ac^2*eye(3);
Nc(10:12, 10:12) = sigma_wgc^2*eye(3);
Nc(13:15, 13:15) = sigma_wac^2*eye(3);

assert( isequal(transpose(Nc), Nc), 'Nc不是对称矩阵');

Qd = deltaT/2 *( PHI*Nc*transpose(PHI) + Nc );

%如果简单一点应该有这个式子
%Qd = deltaT*Nc;

%assert_symmetric(Qd);

end