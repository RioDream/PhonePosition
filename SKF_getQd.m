function SKF_getQd(PHI, Nc, deltaT)



Qd = deltaT/2 *( PHI*Nc*transpose(PHI) + Nc );

end