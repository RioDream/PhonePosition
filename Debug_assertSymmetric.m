function Debug_assertSymmetric(mat)

assert( isequal(transpose(mat),  mat), ['RioError: 矩阵不是对称的, gap norm is: ', num2str(norm(mat-transpose(mat)) ) ]);

end