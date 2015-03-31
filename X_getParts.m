function [p, phi, v, w, lambda] = X_getParts(X)
%{
X: p phi v w lambda
%}

p = X(1:3);
phi = X(4);
v = X(5:7);
w = X(8);
lambda = X(9);

end