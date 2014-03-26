function data = getIMUdata(fname)

fid = fopen(fname,'r');
%imu data
data = [];
data_ = [];

%read
while 1
    %get a line 
    tline=fgetl(fid);
    
    %EOF
    if tline == -1
        break;
    end
    
    %get right line
    pos1 = strfind(tline,'Point3');
    pos2 = strfind(tline,',');
    

    if strcmp(tline, '---')  %new time
        data = [data;data_];
        data_ = [];
    else
        data_ = [data_ , str2double(tline)];
    end

end
fclose(fid);


