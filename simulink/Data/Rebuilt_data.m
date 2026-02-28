%% Output Overrides
TEST_Output_Override_Flag = 0;
TEST_Transfer_Motor_DC_OV = 0;
TEST_Feeder_Motor_DC_OV = 0;
TEST_Shooter_Motor_DC_Left_OV = 0;
TEST_Shooter_Motor_DC_Center_OV = 0;
TEST_Shooter_Motor_DC_Right_OV = 0;
TEST_Desired_Hood_Enable_OV = 0;
TEST_Desired_Hood_Pos_OV = 0.05;
TEST_Intake_Arm_Motor_DC_OV = 0;
TEST_Intake_Roller_Motor_DC_OV = 0;

%% Field Element Position Data
Field_BlueAllianceZoneX = 182.11*0.0254;            % Meters
Field_RedAllianceZoneX = (651.22-182.11)*0.0254;    % Meters
Field_Blue_Hub_X = 182.11*0.0254;             % Meters
Field_Blue_Hub_Y = 158.84*0.0254;             % Meters
Field_Red_Hub_X =  (651.22-182.11)*0.0254;    % Meters
Field_Red_Hub_Y =  158.84*0.0254;             % Meters

%% Shooting Control Data
% Targets
Rebuilt_Transfer_Minimum_Factor = 0.8;
Rebuilt_Target_Transfer_Speed = 4000;   % rpm
Rebuilt_Negative_Feeder_Speed = -1000;
Rebuilt_Target_Feeder_Speed = Rebuilt_Target_Transfer_Speed*0.84;  % rpm
% (the 0.84 factor sets feeder belt linear speed to match transfer wheel surface linear speed)
% Assumes 4 inch diameter transfer wheels and 24 tooth pulleys driving the belts

% Condition Checks
Rebuilt_Shoot_Robot_Velocity_Max = 1;   % meter/second
Rebuilt_Shoot_Motor_Max_Error = 100;    % rpm
Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;    % pwm position

% Iteration error target threshold
Rebuilt_Shoot_Target_Error_Thresh = 0.1;    % Meters

Rebuilt_Des_Gyro_Shoot_Offset = -1;  % Degrees

% Distance (m)
Rebuilt_Shoot_Dist_0 = 1.370;
Rebuilt_Shoot_Dist_1 = 2.120;
Rebuilt_Shoot_Dist_2 = 3.115;
Rebuilt_Shoot_Dist_3 = 3.692;
Rebuilt_Shoot_Dist_4 = 4.353;
Rebuilt_Shoot_Dist_5 = 4.884;
Rebuilt_Shoot_Dist_6 = 5.6;
Rebuilt_Shoot_Dist_7 = 6.5;

% Desired_Shooter_Motor_Speed (rpm)
Rebuilt_Shoot_Shooter_Spd_0 = 2900;
Rebuilt_Shoot_Shooter_Spd_1 = 3000;
Rebuilt_Shoot_Shooter_Spd_2 = 3250;
Rebuilt_Shoot_Shooter_Spd_3 = 3425;
Rebuilt_Shoot_Shooter_Spd_4 = 3575;
Rebuilt_Shoot_Shooter_Spd_5 = 3700;
Rebuilt_Shoot_Shooter_Spd_6 = 3850;
Rebuilt_Shoot_Shooter_Spd_7 = 4000;

% Desired Hood Position (pwm)
Rebuilt_Shoot_Hood_Pos_0 = 0.05;
Rebuilt_Shoot_Hood_Pos_1 = 0.20;
Rebuilt_Shoot_Hood_Pos_2 = 0.35;
Rebuilt_Shoot_Hood_Pos_3 = 0.4;
Rebuilt_Shoot_Hood_Pos_4 = 0.45;
Rebuilt_Shoot_Hood_Pos_5 = 0.5;
Rebuilt_Shoot_Hood_Pos_6 = 0.58;
Rebuilt_Shoot_Hood_Pos_7 = 0.62;

% Time of Flight (sec)
Rebuilt_Shoot_TOF_0 = 0.943;
Rebuilt_Shoot_TOF_1 = 1.092;
Rebuilt_Shoot_TOF_2 = 1.167;
Rebuilt_Shoot_TOF_3 = 1.185;
Rebuilt_Shoot_TOF_4 = 1.250;
Rebuilt_Shoot_TOF_5 = 1.337;
Rebuilt_Shoot_TOF_6 = 1.337;
Rebuilt_Shoot_TOF_7 = 1.337;

% Allowed Gyro Error (degrees ... convert to radians in model)
Rebuilt_Shoot_Gyro_Err_0 = 5;
Rebuilt_Shoot_Gyro_Err_1 = 5;
Rebuilt_Shoot_Gyro_Err_2 = 5;
Rebuilt_Shoot_Gyro_Err_3 = 4;
Rebuilt_Shoot_Gyro_Err_4 = 3;
Rebuilt_Shoot_Gyro_Err_5 = 2;
Rebuilt_Shoot_Gyro_Err_6 = 2;
Rebuilt_Shoot_Gyro_Err_7 = 2;

% PLOT TABLES
    plot_dist     = [Rebuilt_Shoot_Dist_0 Rebuilt_Shoot_Dist_1 Rebuilt_Shoot_Dist_2 Rebuilt_Shoot_Dist_3 Rebuilt_Shoot_Dist_4 Rebuilt_Shoot_Dist_5 Rebuilt_Shoot_Dist_6 Rebuilt_Shoot_Dist_7];
    plot_shooter  = [Rebuilt_Shoot_Shooter_Spd_0 Rebuilt_Shoot_Shooter_Spd_1 Rebuilt_Shoot_Shooter_Spd_2 Rebuilt_Shoot_Shooter_Spd_3 Rebuilt_Shoot_Shooter_Spd_4 Rebuilt_Shoot_Shooter_Spd_5 Rebuilt_Shoot_Shooter_Spd_6 Rebuilt_Shoot_Shooter_Spd_7];
    plot_hood     = [Rebuilt_Shoot_Hood_Pos_0 Rebuilt_Shoot_Hood_Pos_1 Rebuilt_Shoot_Hood_Pos_2 Rebuilt_Shoot_Hood_Pos_3 Rebuilt_Shoot_Hood_Pos_4 Rebuilt_Shoot_Hood_Pos_5 Rebuilt_Shoot_Hood_Pos_6 Rebuilt_Shoot_Hood_Pos_7];
    plot_tof      = [Rebuilt_Shoot_TOF_0 Rebuilt_Shoot_TOF_1 Rebuilt_Shoot_TOF_2 Rebuilt_Shoot_TOF_3 Rebuilt_Shoot_TOF_4 Rebuilt_Shoot_TOF_5 Rebuilt_Shoot_TOF_6 Rebuilt_Shoot_TOF_7];
    plot_gyro_err = [Rebuilt_Shoot_Gyro_Err_0 Rebuilt_Shoot_Gyro_Err_1 Rebuilt_Shoot_Gyro_Err_2 Rebuilt_Shoot_Gyro_Err_3 Rebuilt_Shoot_Gyro_Err_4 Rebuilt_Shoot_Gyro_Err_5 Rebuilt_Shoot_Gyro_Err_6 Rebuilt_Shoot_Gyro_Err_7];
    
    figure(1)
    subplot(2,2,1)
    plot(plot_dist,plot_shooter,'-o')
    xlabel('Shot Distance (m)')
    ylabel('Shooter Speed (rpm)')
    grid on
    
    subplot(2,2,2)
    plot(plot_dist,plot_hood,'-o')
    xlabel('Shot Distance (m)')
    ylabel('Hood Position (pwm)')
    grid on
    
    subplot(2,2,3)
    plot(plot_dist,plot_tof,'-o')
    xlabel('Shot Distance (m)')
    ylabel('Time of Flight (sec)')
    grid on
    
    subplot(2,2,4)
    plot(plot_dist,plot_gyro_err,'-o')
    xlabel('Shot Distance (m)')
    ylabel('Allowed Gyro Error (deg)')
    grid on
    
    % need to clear from workspace so not included in code generation
    clear plot_dist plot_shooter plot_hood plot_tof plot_gyro_err

% Control Parameters to Calculate Duty Cycle
Rebuilt_Feeder_Motor_Gain_FF = 1/7854;

Rebuilt_Transfer_Motor_Gain_FF = 1/7854;
Rebuilt_Transfer_Motor_Gain_P = 0.0001;
Rebuilt_Transfer_Motor_Gain_I = 0.001*0.02;
Rebuilt_Transfer_Error_Integral_Enable = 300;

Rebuilt_Shooter_Motor_Gain_FF = 1/6048;
Rebuilt_Shooter_Motor_Gain_P = 0.0005;
Rebuilt_Shooter_Motor_Gain_I = 0.001*0.02;
Rebuilt_Shooter_Error_Integral_Enable = 300;

% Hood Position Servo Properties
Rebuilt_Hood_Servo_Pos_Min = 0.05;
Rebuilt_Hood_Servo_Pos_Max = 1;
Rebuilt_Hood_Servo_Rate_Limit_Inc = 32/50*0.02;   % no load 32 mm/sec, total stroke 50 mm
Rebuilt_Hood_Servo_Rate_Limit_Dec = -Rebuilt_Hood_Servo_Rate_Limit_Inc;

%% Intake
Rebuilt_Intake_Des_Angle_In = 0;
Rebuilt_Intake_Des_Angle_Out = 90;
Rebuilt_Intake_Cycle_Angle_In = 20;
Rebuilt_Intake_Cycle_Angle_Out = 70;

Rebuilt_Intake_Arm_Gain_P = 0;
Rebuilt_Intake_Arm_Gain_I = 0;
Rebuilt_Intake_Arm_Gain_D = 0;
Rebuilt_Intake_Arm_Integral_Enable = 0;

Rebuilt_Roller_Desired_Speed = 0;
Rebuilt_Roller_Motor_Gain_FF = 0;
Rebuilt_Roller_Motor_Gain_P = 0;
Rebuilt_Roller_Motor_Gain_I = 0;
Rebuilt_Roller_Error_Integral_Enable = 0;

