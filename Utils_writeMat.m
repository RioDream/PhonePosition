function Utils_writeMat( fid,source_matrix )
%TEST Summary of this function goes here
%  write matrix to file


[x,y]=size(source_matrix);


for i=1:x
    for j=1:y-1
        fprintf(fid,'%f\t',source_matrix(i,j));
    end
    fprintf(fid,'%f\n',source_matrix(i,y));%每一行回车\n
end




end
