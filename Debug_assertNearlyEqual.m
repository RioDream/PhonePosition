function Debug_assertNearlyEqual(trueVal, targetVal, errMsg)

minGap = 1e-7;
%minGap = 0;
gap = norm(targetVal-trueVal);
assert( gap<=minGap, errMsg);

end