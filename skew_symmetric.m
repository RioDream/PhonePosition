function ssMat = skew_symmetric(v)

x = v(1);
y = v(2);
z = v(3);

ssMat = [0 -z y
         z 0 -x
        -y x  0];


end