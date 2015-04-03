function isNumber = Utils_isNumber( x )

[m,n] = size(x);

if m==1 && n==1
    isNumber = true;
else
    isNumber = false;
end

end