function IMUdata = Utils_loadIMUdata_SKF(infoDir)
%{
Usage:
    load IMUdata.txt 中的数据
%}

IMUpath = [infoDir, 'IMUdata.txt'];

IMUdata = [];

fid=fopen(IMUpath);
while 1
    tline = fgetl(fid);
    if ~ischar(tline), break, end
    s = regexp(tline, ':', 'split');
    timestamp = str2double(s{1});
    eval(['items = [', s{2},'];']);
    
    ax = items(1);
    ay = items(2);
    az = items(3);
    gx = items(4);
    gy = items(5);
    gz = items(6);
    
    motion = struct('timestamp', timestamp,  ...
            'rateX', gx, ...
            'rateY', gy, ...
            'rateZ', gz, ...
            'accX', ax, ...
            'accY', ay, ...
            'accZ', az ...
            );
        
     IMUdata = [IMUdata, motion];
end

fclose(fid);


end

