function EX_do()

scales = [];
%scale = SF_getScaleFactor(13);

%5 

for i=7
    close all;
    scale = SF_getScaleFactor(i);
    scales = [scales, scale];    
end

end