%% Field Element Position Data
BlueAllianceZoneX = 182.11*0.0254;
RedAllianceZoneX = (651.22-182.11)*0.0254;
Blue_Hub_X = 182.11*0.0254;             % Meters
Blue_Hub_Y = 158.84*0.0254;             % Meters
Red_Hub_X =  (651.22-182.11)*0.0254;    % Meters
Red_Hub_Y =  158.84*0.0254;             % Meters

%% Shooting Control Data
% Targets
Target_Feeder_Speed = 2000;
Transfer_Minimum_Factor = 0.8;
Target_Transfer_Speed = 2000;

% Condition Checks
Robot_Velocity_Maximum_Shooter = 1;
Shooter_Motor_Max_Error_Shoot = 100;
Hood_Servo_Rate_Limit_Inc = 32/50*0.02;   % no load 32 mm/sec, total stroke 50 mm
Hood_Servo_Rate_Limit_Dec = -Hood_Servo_Rate_Limit_Inc;
Hood_Pos_Max_Error_Shoot = 0.03;

% Iteration error target threshold
Shot_Target_Error_Thresh = 0.1;         % Meters

% Distance (m)
Dist_Arr_0 = 0;
Dist_Arr_1 = 2.5;
Dist_Arr_2 = 5;
Dist_Arr_3 = 7.5;
Dist_Arr_4 = 10;

% Time of Flight (s)
TOF_Arr_0 = 2;
TOF_Arr_1 = 3;
TOF_Arr_2 = 3.5;
TOF_Arr_3 = 3.8;
TOF_Arr_4 = 4;

% Desired_Shooter_Motor_Speed (rpm?)
Shooter_Spd_0 = 3000;
Shooter_Spd_1 = 3200;
Shooter_Spd_2 = 3500;
Shooter_Spd_3 = 3500;
Shooter_Spd_4 = 3500;

% Desired Hood Position
Hood_Position_0 = 0.8;
Hood_Position_1 = 0.6;
Hood_Position_2 = 0.4;
Hood_Position_3 = 0.3;
Hood_Position_4 = 0.2;

% Allowed Gyro Error (Radians)
Gyro_Err_Arr_0 = deg2rad(10);
Gyro_Err_Arr_1 = deg2rad(5);
Gyro_Err_Arr_2 = deg2rad(3);
Gyro_Err_Arr_3 = deg2rad(1);
Gyro_Err_Arr_4 = deg2rad(0.5);

% Control Parameters to Calculate Duty Cycle
Feeder_Motor_DC_Gain = 1/7000;

Transfer_Motor_Gain_FF = 1/7000;
Transfer_Motor_Gain_P = 0;
Transfer_Motor_Gain_I = 0;
Transfer_Motor_Gain_D = 0;
Transfer_Error_Integral_Enable = 300;

Shooter_Motor_Gain_FF = 1/7000;
Shooter_Motor_Gain_P = 0;
Shooter_Motor_Gain_I = 0;
Shooter_Motor_Gain_D = 0;
Shooter_Error_Integral_Enable = 300;

