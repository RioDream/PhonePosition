function mat_res =  Quater_omega(w)

wx = w(1);
wy = w(2);
wz = w(3);

mat_res = [
          0   wz  -wy  wx
        -wz    0   wx  wy
         wy  -wx    0  wz
        -wx  -wy  -wz  0
    ];

end