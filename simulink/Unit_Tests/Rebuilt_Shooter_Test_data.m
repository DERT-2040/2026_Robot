Target_Feeder_Speed = 2000;
Transfer_Minimum_Factor = 0.8;

Target_Transfer_Speed = 2000;

BlueAllianceZoneX = 182.11*0.0254;
RedAllianceZoneX = (651.22-182.11)*0.0254;

Robot_Velocity_Maximum_Shooter = 1;

Heading_Max_Error_Shoot = 5;

Shooter_Motor_Max_Error_Shoot = 100;

Hood_Servo_Rate_Limit_Inc = 32/50*0.02;   % no load 32 mm/sec, total stroke 50 mm
Hood_Servo_Rate_Limit_Dec = -Hood_Servo_Rate_Limit_Inc;

Hood_Pos_Max_Error_Shoot = 0.03;

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

%% Shooting Data
Shot_Target_Error_Thresh = 0.1; % Meters
Blue_Hub_X = 4.6; %ISH - Please Update
Blue_Hub_Y = 3.9; %ISH - Please Update
Red_Hub_X =  4.6; %ISH - Please Update
Red_Hub_Y =  3.9; %ISH - Please Update

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
Shooter_Spd_0 = 300;
Shooter_Spd_1 = 320;
Shooter_Spd_2 = 350;
Shooter_Spd_3 = 350;
Shooter_Spd_4 = 350;

% Desired Hood Angle (Degrees converted to Radians)
Hood_Angle_0 = 77 * 0.01745329;
Hood_Angle_1 = 75 * 0.01745329;
Hood_Angle_2 = 70 * 0.01745329;
Hood_Angle_3 = 55 * 0.01745329;
Hood_Angle_4 = 45 * 0.01745329;

% Allowed Gyro Error (Degrees converted to Radians)
Gyro_Err_Arr_0 = 10  * 0.01745329;
Gyro_Err_Arr_1 = 5   * 0.01745329;
Gyro_Err_Arr_2 = 3   * 0.01745329;
Gyro_Err_Arr_3 = 1   * 0.01745329;
Gyro_Err_Arr_4 = 0.5 * 0.01745329;
