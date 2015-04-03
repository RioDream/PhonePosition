function [mat, timestamp]= Utils_get_a_Matrix(fid)
%{
Usage:
得到形如
    1 2 3
    4 5 6
    7 8 9
    #
    3 4 5
    2 3 4
    #
中的一个矩阵 
1 2 3 
4 5 6
7 8 9
即从当前行到 # 或者行尾 为止的矩阵
%}
    
    mat = [];
    
    line=[];
    
    
    while isempty(line) || ~strcmp(line(1),'#')
        eval(['mat = [mat;',  line,'];' ] );
        
        line = fgetl(fid);
        if ~ischar(line)
            fclose(fid);
            break
        end
    end
    
    %有两种原因会导致退出while
    if strcmp(line(1),'#')
        timestamp = str2double(line(2:end) );
    else %到行尾了
        mat = -1;
        timestamp = -1;
        disp('EOF.');
    end
    
end