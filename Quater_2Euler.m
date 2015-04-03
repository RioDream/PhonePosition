function [phi, theta, psi] = Quater_2Euler(q)
%{
    Usage:
        %   Converts a quaternion orientation to ZYX Euler angles where phi is a
        %   rotation around X, theta around Y and psi around Z.
%}


q1 = q(4);
q2 = q(1);
q3 = q(2);
q4 = q(3);


R(1,1) = 2.*q1.^2-1+2.*q2.^2;
R(2,1) = 2.*(q2.*q3-q1.*q4);
R(3,1) = 2.*(q2*q4+q1.*q3);
R(3,2) = 2.*(q3*q4-q1.*q2);
R(3,3) = 2.*q1.^2-1+2.*q4.^2;

%{
    根据 http://mathworld.wolfram.com/EulerAngles.html
    theta is pitch, psi is roll, and phi is yaw. it seems that they are  not
    here
    
    %z - y - x convention
%}

phi = atan2(R(3,2), R(3,3) ); % axis x
theta = -atan(R(3,1) ./ sqrt(1-R(3,1).^2) ); % axis y
psi = atan2(R(2,1), R(1,1) ); % axis z

end