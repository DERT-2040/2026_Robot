% Parameters to exclude from being tunable.
% This is used in the 'Build_Extern.m' file
Not_Tunable_List = {'t_sample',...
    'Distance_FL_x','Distance_FL_y','Distance_FR_x','Distance_FR_y',...
    'Distance_BL_x','Distance_BL_y','Distance_BR_x','Distance_BR_y',...
    'Wheel_Speed_to_Motor_Speed','Drive_Wheel_Max_Speed',...
    'KF_Odom_Covariance','KF_Vision_Covariance',...
    'Spline_Num_Samples','Spline_Num_Samples_3x','Spline_Samples_Per_Pass',...
    'Spline_Max_Num_RefPoses','Spline_Tension',...
    'Spline_Velocity_Axis','Spline_Capture_Radius','Spline_Lookahead_Dist',...
    'Spline_Num_Poses_default','Spline_Ref_Poses_default'...
};

% sample time model
t_sample = 0.020;

% Test Mode for swerve drive
% Setting override to 1 will use constants for translation and steering modes
TEST_Swerve_Mode_Override_Flag = 0;
TEST_Swerve_Mode_Translation = 0; 
TEST_Swerve_Mode_Steering = 0;

% Pipeline for Test Mode
TEST_Pipeline = uint8(0);

%% Kalman Filter
KF_Enable = 1;
KF_Odom_Covariance = 0.001*eye(2);
KF_Vision_Covariance = 0.1*eye(2);

%% Run data scripts
Common_data  % common to Robot_Controls and Odometry
Swerve_Drive
Spline_Path_Following
Vision_Data


