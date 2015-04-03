function smat = MAKE_SYMMETRIC(mat)
%{
    这个函数是为了消除 Matlab中的数值计算造成的原本应该对称的矩阵不对称的情况

    这个方法很不合理，会导致突然位置的跳变

    开始要判断是不是接近
    做完变换之后判断是不是已经对称
%}

USE_SVD_METHOD = 0;

Debug_assertNearlyEqual(mat, transpose(mat), 'RioError: 不是接近对称的');

if USE_SVD_METHOD
    
    [U,S,V] = svd(mat);
    UV = (U + V)/2;
    smat = UV*S*UV.';
    smat = ( smat+transpose(smat) )/2;

else 
    smat = ( mat+transpose(mat) )/2;
end

Debug_assertSymmetric(smat);

end

