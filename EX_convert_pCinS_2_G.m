function p_IinG = EX_convert_pCinS_2_G(R_S2C, p_CinS, R_S2C0, p_C0inS)
%{
Usage:
    将{S}中的C转换到{G}

    T : p_CinS
    G:  t0 时刻的 C
%}

p_IinC = [0, 0.00656, 0].';
R_I2C = Quater_2Mat([-1 0 0 0]);
R_C2I = transpose(R_I2C);
lambda = 0.135/2;
R_C02G = R_C2I;
R_S2G = R_C02G * R_S2C0;

p_CinI = -R_C2I*p_IinC;
p_SinC0 = -lambda*R_S2C0 * p_C0inS;
p_SinG = R_C02G*(p_SinC0 - p_IinC);

R_C2I = transpose(R_I2C);


p_IinS = p_CinS + 1/lambda * transpose(R_S2C) * p_IinC;
p_IinG = p_SinG + lambda * R_S2G*p_IinS;


end