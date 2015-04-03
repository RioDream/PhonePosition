function Utils_compare_write(mat, timestamp)

fname = '/Users/riodream/workspace/MSCKF/cplusplus/MSCKF/debugDir/compare_M2.txt';

fid = fopen(fname, 'a+');

Utils_writeMat( fid, mat)

fprintf( fid, '#%f\n', timestamp);
fclose(fid);


end