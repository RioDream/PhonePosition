function testWeiss()

syms x y z w;
syms dx dy dz dw;

q = [x y z w].';
dq = [dx dy dz dw].';

tmp  = Quater_multiSym(Quater_conj(q), dq);
res = Quater_multiSym(tmp, q);

res
%jacobian(res, dx)

end