function sm = SKF_MATH_makeSymmetric(sm)
%{
a simple method to make mat symmetric
%}


sm = (sm + transpose(sm))/2;

end