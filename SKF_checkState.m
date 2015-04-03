function SKF_checkState(X, gt_q, gt_p)
q = X(1:4);
assert( norm(q-gt_q)<0.000001 );
p = X(5:7);
assert( norm(p-gt_p)<0.000001 );
end