function Robot_Translated = RobotRotation(x_r,y_r,angle_r)
% Inputs:
%   x_r     = x position of robot frame center
%   y_r     = y position of robot frame center
%   angle_r = heading angle of robot in radians
%
% Outputs:
%   Robot_Translated = matrix of robot points of interest as decribed
%                      below in this function

% Robot dimensions
frame_width = 27.25;
frame_length = 27.5;
bumper = 4;
intake_extension = 12;  % from the frame, not from the bumper
w   = (frame_width  + bumper*2)*0.0254;                    % width of robot including bumpers
l   = (frame_length + bumper + intake_extension)*0.0254;   % length of robot including bumpers and deployed intake
l_r = (frame_length/2 + bumper)*0.0254;                    % length from center of robot frame to rear bumper
l_f = l-l_r;                                               % length from center of robot from to deployed intake

% points on robot to be plotted
%   1 = front left
%   2 = front right
%   3 = rear right
%   4 = rear left
%   5 = center of robot frame
%   6 = front-center of deployed intake

y_1 =  w/2;
y_2 = -w/2;
y_3 = -w/2;
y_4 =  w/2;
y_5 =  0;
y_6 =  0;

x_1 =  l_f;
x_2 =  l_f;
x_3 = -l_r;
x_4 = -l_r;
x_5 =  0;
x_6 =  l_f;

% Arrange the robot points into a matrix
Robot=[x_1 x_2 x_3 x_4 x_5 x_6;
       y_1 y_2 y_3 y_4 y_5 y_6];

% Transformation matrix R
R = [cos(angle_r), -sin(angle_r);
     sin(angle_r),  cos(angle_r)];

% Perform the matrix multiplication to rotate the robot points
Robot_Rotated = R*Robot;

% Move the rotated robot to the desired location in the field
Robot_Translated = Robot_Rotated + [x_r; y_r];

end

