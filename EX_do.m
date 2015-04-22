function EX_do()

scales = [];
%scale = SF_getScaleFactor(13);

%5 

for idx=1:16
    close all;
    disp(idx);
    i = 4+idx;
    scale = SF_getScaleFactor(i);
    scales = [scales, scale];  
    
    print(1, '-dpng', num2str(idx));
end


end