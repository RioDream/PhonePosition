function [pic , lambda] = SKF_getOtherPart(X)
pic = X(17:19);
lambda = X(20);
end