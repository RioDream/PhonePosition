function p_CinSs = EX_convert2Scene(qs, ps, R_S2G, p_GinS, lambda, p_IinC, R_I2C)
%{
Usage:
    
%}

nof_samples = length(qs);
assert(nof_samples == length(ps));

p_CinI = -transpose(R_I2C) * p_IinC;

for i=1:nof_samples
    q_G2I = qs(i,:);
    p_IinG = ps(i,:);
    
    R_G2I = Quater_2Mat(q_G2I);
    p_CinS = p_GinS + 1/lambda * transpose(R_S2G) * (p_IinG + transpose(R_G2I)*p_CinI);
    
    p_CinSs = [p_CinSs, p_CinS];
end

end