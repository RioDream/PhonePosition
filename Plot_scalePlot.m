function Obs_scalePlot(p, style, scale)

%{
用于增大比例，画的清楚些
%}

p = scale*p;
plot3(p(1), p(2), p(3), style);

end