function Quater_res = Quater_multiSym(q,p)
%{
    Usage:
        使用这个乘法形式， 
        输入是坐标旋转矩阵
        输出得到的也是坐标旋转矩阵
%}


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


Quater_res = [
        x
        y
        z
        w
    ];

Quater_res = Quater_res/norm(Quater_res);

end