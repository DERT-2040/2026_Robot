% Parameters to exclude from being tunable.
% This is used in the 'Build_Extern.m' file
Not_Tunable_List = {'t_sample_fast','Motor_Rev_to_Wheel_Distance'};

% sample time model
t_sample_fast = 0.004;

% Load data files
Common_data  % common to Robot_Controls and Odometry

% Swerve Geometry
Motor_Rev_to_Wheel_Distance = wheel_diameter*pi/gear_ratio; % m/rev
clear gear_ratio wheel_diameter

% Gyro calibration for each starting position
Auto_Starting_Position = 2;  % 1 = left, 2 = center, 3 = right
Gyro_Calibration_Reset_Flag = 0;  % when this value increases then reset the degree value
Gyro_Calibration_Default = 0; % degrees
Gyro_Calibration_Auto_Left = 210;
Gyro_Calibration_Auto_Center = 180;
Gyro_Calibration_Auto_Right = 125;

%% Odometry rotation matrix
% robot rotation matrix to obtain: 
%   Vx and Vy for each module from the robot center Vx, Vy, and Omega
%   Dx and Dy for each module from the robot center Dx, Dy, and Theta
Rotation_Local =  [1 0 -Distance_FL_y;
                   0 1  Distance_FL_x;
                   1 0 -Distance_FR_y;
                   0 1  Distance_FR_x;
                   1 0 -Distance_BL_y;
                   0 1  Distance_BL_x;
                   1 0 -Distance_BR_y;
                   0 1  Distance_BR_x];

clear Distance_FL_y Distance_FL_x Distance_FR_y Distance_FR_x
clear Distance_BL_y Distance_BL_x Distance_BR_y Distance_BR_x

% pseudo inverse of the rotation matrix
temp = pinv(Rotation_Local);

% only keep first two rows since we don't need to estimate Theta
Rotation_Local_Inv = temp(1:2,:);
clear temp

% reset the odometry estimate to the IC
% write to this in Smart Dashboard to reset (rising edge)
Odometry_Reset_IC = 0;

% only used for validation testing
% set to 1 to tear the X and Y measurement
% set to 0 to let the X and Y measurements accumulate since the last tear
Odometry_X_Y_TEAR = 0;

Odometry_IC_X = 0;
Odometry_IC_Y = 0;

