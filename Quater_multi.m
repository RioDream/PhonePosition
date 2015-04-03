function Quater_res = Quater_multi(q,p)
%{
    Usage:
        使用这个乘法形式， 
        输入是坐标旋转矩阵
        输出得到的也是坐标旋转矩阵
%}

assert(Debug_isNearlyEqual(norm(q), 1.0), ['RioError: 四元数q norm不为 1， gap为', num2str(norm(q)-1.0)] );
assert(Debug_isNearlyEqual(norm(p), 1.0), ['RioError: 四元数p norm不为 1， gap为', num2str(norm(p)-1.0)] );

ax = q(1);
ay = q(2);
az = q(3);
aw = q(4);

bx = p(1);
by = p(2);
bz = p(3);
bw = p(4);

%JPL  [MARS]  坐标转换 B->C * 坐标转换 A->B  =>  坐标转换 A->C
x = aw*bx + ax*bw - ay*bz + az*by ;
y = aw*by + ax*bz + ay*bw -az*bx ;
z =  aw*bz - ax*by + ay*bx + az*bw;
w = -ax*bx - ay*by - az*bz + aw*bw;


%others
%{
    这种形式适用于当 q和p以及结果代表的是坐标系之间的变换的时候
    比如：
        q 表示 从 I->C 这两个坐标系之间的变换
        p 表示 从 G->I 这两个坐标系之间的变换

    如果将 
    q 取共轭 (得到的是 I->C 这两个坐标系中的 vector的坐标变换)
    p 取共轭 (得到的是 G->I 这两个坐标系中的 vector的坐标变换)
    利用 JPL 形式， 就可以得到 res为 G->C 这两个坐标系中的 vector的坐标变换
    然后再将 结果 res取共轭, 就是 G->C的坐标系变换
    得到的结果就是对的

    x1 = aw * bx  +  ax * bw  +  ay * bz  -  az*by;
    y1 = aw * by  -  ax * bz  +  ay * bw  +  az*bx;
    z1 = aw * bz  +  ax * by  -  ay * bx  +  az*bw;
%}

Quater_res = [
        x
        y
        z
        w
    ];

Quater_res = Quater_res/norm(Quater_res);

end