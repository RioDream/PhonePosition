clear;
m_filename  = '/Users/riodream/workspace/MSCKF/cplusplus/MSCKF/debugDir/compare_M.txt';
c_filename = '/Users/riodream/workspace/MSCKF/cplusplus/MSCKF/debugDir/compare_M2.txt';

fid_matlab = fopen(m_filename);
fid_c = fopen(c_filename);


THRESHOLD = 1e-10;


m_mat = -1;
c_mat = -1;

while ~isempty(m_mat) && ~isempty(c_mat)
    [m_mat, m_timestamp] = Utils_get_a_Matrix(fid_matlab);
    [c_mat, c_timestamp] = Utils_get_a_Matrix(fid_c);
    
    [m_m, m_n] = size(m_mat);
    [c_m, c_n] = size(c_mat);
    
    %判断结束
    end_flag = 0;
    if (Utils_isNumber(m_mat) && m_mat ==-1) 
        end_flag = 1;
        disp('Matlab is over !');
    end
    if (Utils_isNumber(c_mat) && c_mat ==-1)
        end_flag = 1;
        disp('C++ is over !');
    end
    if end_flag
        return;
    end
    
    if m_timestamp-c_timestamp<1e-10
        ;
    else
        disp('Error');
    end
    
    disp(' - ');
    disp(['Matlab: size: ', num2str(m_m), ' x ', num2str(m_n), ' norm: ', num2str(norm(m_mat))] );
    disp(['C++:    size: ', num2str(c_m), ' x ', num2str(c_n), ' norm: ', num2str(norm(c_mat))] );
    
    diff_norm = norm(m_mat - c_mat);
    if diff_norm>THRESHOLD
        disp( ['Warning: ', num2str(m_timestamp) ,'  diff norm is', num2str(diff_norm)] );
    else
        disp( ['OK: ', num2str(m_timestamp) ,'  diff norm is', num2str(diff_norm)] );
    end
end



