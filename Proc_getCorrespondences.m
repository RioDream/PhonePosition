function [features, ms, dess, gt_pfinGs] = Proc_getCorrespondences(PointCloud, frameInfo, pointCloud_inG)
%{
Usage:
    得到2D-3D 对应点对

    features: Nx3 , 每一行是一个 feature的3D坐标
    ms: Nx2，每一行一个2D图像坐标

    featues 和 ms 按照行对应 
%}

        features = [];
        ms = [];
        dess = [];
        gt_pfinGs = [];
        
		des = frameInfo.des;
		loc = frameInfo.loc;
		nof_mesaure_inFrame = size(des, 1);
        
        for i=1:nof_mesaure_inFrame
            targetDes = des(i,:);
            idx = IN_findMatchFeatureByDes(targetDes , PointCloud);
            if idx>0
                p_f = PointCloud(idx, 1:3);
                mx =  loc(i,2); %swap
                my = loc(i,1);
                
                
                dess = [dess; des];
                features = [features; p_f];
                ms = [ms; [mx,my]];
                gt_pfinGs = [gt_pfinGs; pointCloud_inG(idx, 1:3)];
            end
        end

end


function idx = IN_findMatchFeatureByDes(targetDes , PointCloud)
%{
Usage:
    PointCloud实际是一个 Nx4 的矩阵
    每一行 是这么存放的  [X, Y, Z, des]
%}

idx = -1;
sof_PointCloud = size(PointCloud, 1);
for i=1:sof_PointCloud 
    currDes  = PointCloud(i,4);
    if currDes==targetDes
        idx = i;
        return;
    end
end

end