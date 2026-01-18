%% Wheel Locations from Center of Rotation
% distances between swerve modules
FrontBack = (20.000 - 0.125 - 2*2.625)*0.0254;  % meters
LeftRight = (20.000 - 0.125 - 2*2.625)*0.0254;  % meters

% swerve module distances from center to x and y coordinates
% Front Left
Distance_FL_x = FrontBack/2;
Distance_FL_y = LeftRight/2;

% Front Right
Distance_FR_x = FrontBack/2;
Distance_FR_y = -LeftRight/2;

% Back Left
Distance_BL_x = -FrontBack/2;
Distance_BL_y = LeftRight/2;

% Back Right
Distance_BR_x = -FrontBack/2;
Distance_BR_y = -LeftRight/2;

clear FrontBack LeftRight

%% Wheel Gear Ratio
gear_ratio = 6.12;  % L1 gear ratio = 8.14,  L3 gear ratio = 6.12
wheel_diameter = 3.80*0.0254;