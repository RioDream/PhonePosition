syms qx qy qz qw;
syms px py pz pw;

q = [qx, qy, qz, qw];
p = [px, py, pz, pw];

res = Quater_multiSym(q, p);

J = jacobian(res, q);