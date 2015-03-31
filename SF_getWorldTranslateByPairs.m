function translates_in_world = SF_getWorldTranslateByPairs(IndexPairs, linPosHP)
%{
Usage:
    由index的pairs获得每个pair的translate
%}

translates_in_world = [];
nof_pairs = size(IndexPairs, 1);
for i=1:nof_pairs
    maxIdx = IndexPairs(i, 1);
    minIdx = IndexPairs(i, 2);
    
    maxPos = linPosHP(maxIdx,:);
    minPos = linPosHP(minIdx,:);
    
    translate = norm(maxPos - minPos);
    translates_in_world = [translates_in_world , translate];
end

end