%% Output Overrides
TEST_Output_Override_Flag = 0;
TEST_Transfer_Motor_DC_OV = 0;
TEST_Feeder_Motor_DC_OV = 0;
TEST_Desired_Shooter_Speed_OV = 0;
TEST_Desired_Shooter_FF_DC_OV = 0;
TEST_Desired_Hood_Enable_OV = 0;
TEST_Desired_Hood_Pos_OV = 0.05;
TEST_Intake_Arm_Motor_DC_OV = 0;
TEST_Intake_Roller_Motor_DC_OV = 0;

%% Field Element Position Data
Field_BlueAllianceZoneX = 182.11*0.0254;             % Meters
Field_RedAllianceZoneX  = (651.22-182.11)*0.0254;    % Meters
Field_Blue_Hub_X        = 182.11*0.0254;             % Meters
Field_Hub_Y             = 158.84*0.0254;             % Meters
Field_Red_Hub_X         = (651.22-182.11)*0.0254;    % Meters
Field_Pass_Y_Top        = (317.69-(96))*0.0254;
Field_Pass_Y_Bottom     = (96)*0.0254;
Field_Blue_Pass_X       = (156.61/2)*0.0254;
Field_Red_Pass_X        = (651.22-((156.61/2)))*0.0254;
Blue_Hub_LeftX = 5.1717;
Blue_Hub_RightX = 5.1717;
Blue_Hub_RightY = 4.548;
Blue_Hub_LeftY = 3.354;
Red_Hub_LeftX = 11.369;
Red_Hub_RightX = 11.369;
Red_Hub_RightY = 3.354;
Red_Hub_LeftY = 4.548;
Field_Width = 317.69 * 0.0254;
Field_Length = 691.22 * 0.0254;
%% Shooting Control Data
% Targets
Rebuilt_Transfer_Minimum_Factor = 0.8;
Rebuilt_Target_Transfer_Speed = 4000;   % rpm
Rebuilt_Negative_Feeder_Speed = -3000;  % this was -1000 with a 1:1 gear ratio
Rebuilt_Target_Feeder_Speed = 3*Rebuilt_Target_Transfer_Speed*0.84;  % rpm
% The 3 factor is for the 3:1 gear box.
% The 0.84 factor sets feeder belt linear speed to match transfer wheel surface linear speed
% Assumes 4 inch diameter transfer wheels and 24 tooth pulleys driving the belts

Rebuilt_Shot_Init_Time = 0.4; % Seconds

% Condition Checks
Rebuilt_Shoot_Robot_Velocity_Max = 1.7;   % meter/second
Rebuilt_Shoot_Motor_Max_Error = 100;    % rpm
Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;    % pwm position
Feeder_Max_Pulsetime = 1000; % seconds

% Check if Hub is Active for Scoring
Rebuilt_Match_Time_Transition  = 10; 
Rebuilt_Match_Time_Shift_1  = 35; 
Rebuilt_Match_Time_Shift_2  = 60; 
Rebuilt_Match_Time_Shift_3  = 85;
Rebuilt_Match_Time_Shift_4  = 110;
Rebuilt_Match_Time_Auto_Timer  = 30;
Rebuilt_Match_Time_Shift_Timer  = 25;
Rebuilt_Match_Time_End_Game_Timer = 30; 
Rebuilt_Match_Time_Shoot_Early = 2;

% Iteration error target threshold
Rebuilt_Shoot_Target_Error_Thresh = 0.1;    % Meters

Rebuilt_Des_Gyro_Shoot_Offset = 0;  % Degrees

% Distance (m)
Rebuilt_Shoot_Dist_0 = 1.370;
Rebuilt_Shoot_Dist_1 = 2.120;
Rebuilt_Shoot_Dist_2 = 3.115;
Rebuilt_Shoot_Dist_3 = 3.692;
Rebuilt_Shoot_Dist_4 = 4.353;
Rebuilt_Shoot_Dist_5 = 4.884;
Rebuilt_Shoot_Dist_6 = 5.6;
Rebuilt_Shoot_Dist_7 = 9.0;

% Desired_Shooter_Motor_Speed (rpm)
Rebuilt_Shoot_Shooter_Spd_0 = 2725;
Rebuilt_Shoot_Shooter_Spd_1 = 2975;
Rebuilt_Shoot_Shooter_Spd_2 = 3265;
Rebuilt_Shoot_Shooter_Spd_3 = 3425;
Rebuilt_Shoot_Shooter_Spd_4 = 3625;
Rebuilt_Shoot_Shooter_Spd_5 = 3775;
Rebuilt_Shoot_Shooter_Spd_6 = 3975;
Rebuilt_Shoot_Shooter_Spd_7 = 4500;

delta = 100;
% Desired_Shooter_Motor_Speed Init (rpm)
Rebuilt_Shoot_Shooter_Spd_I_0 = Rebuilt_Shoot_Shooter_Spd_0+delta;
Rebuilt_Shoot_Shooter_Spd_I_1 = Rebuilt_Shoot_Shooter_Spd_1+delta;
Rebuilt_Shoot_Shooter_Spd_I_2 = Rebuilt_Shoot_Shooter_Spd_2+delta;
Rebuilt_Shoot_Shooter_Spd_I_3 = Rebuilt_Shoot_Shooter_Spd_3+delta;
Rebuilt_Shoot_Shooter_Spd_I_4 = Rebuilt_Shoot_Shooter_Spd_4+delta;
Rebuilt_Shoot_Shooter_Spd_I_5 = Rebuilt_Shoot_Shooter_Spd_5+delta;
Rebuilt_Shoot_Shooter_Spd_I_6 = Rebuilt_Shoot_Shooter_Spd_6+delta;
Rebuilt_Shoot_Shooter_Spd_I_7 = Rebuilt_Shoot_Shooter_Spd_7;
clear delta

% Desired Hood Position (pwm)
Rebuilt_Shoot_Hood_Pos_0 = 0.05;
Rebuilt_Shoot_Hood_Pos_1 = 0.20;
Rebuilt_Shoot_Hood_Pos_2 = 0.35;
Rebuilt_Shoot_Hood_Pos_3 = 0.4;
Rebuilt_Shoot_Hood_Pos_4 = 0.45;
Rebuilt_Shoot_Hood_Pos_5 = 0.5;
Rebuilt_Shoot_Hood_Pos_6 = 0.58;
Rebuilt_Shoot_Hood_Pos_7 = 1;

% Time of Flight (sec)
Rebuilt_Shoot_TOF_0 = 0.943;
Rebuilt_Shoot_TOF_1 = 1.092;
Rebuilt_Shoot_TOF_2 = 1.167;
Rebuilt_Shoot_TOF_3 = 1.185;
Rebuilt_Shoot_TOF_4 = 1.250;
Rebuilt_Shoot_TOF_5 = 1.337;
Rebuilt_Shoot_TOF_6 = 1.4;
Rebuilt_Shoot_TOF_7 = 1.5;

% Allowed Gyro Error (degrees ... convert to radians in model)
Rebuilt_Shoot_Gyro_Err_0 = 5;
Rebuilt_Shoot_Gyro_Err_1 = 5;
Rebuilt_Shoot_Gyro_Err_2 = 3.5;
Rebuilt_Shoot_Gyro_Err_3 = 2.7;
Rebuilt_Shoot_Gyro_Err_4 = 2;
Rebuilt_Shoot_Gyro_Err_5 = 2;
Rebuilt_Shoot_Gyro_Err_6 = 10;
Rebuilt_Shoot_Gyro_Err_7 = 10;

% PLOT TABLES
    plot_dist     = [Rebuilt_Shoot_Dist_0 Rebuilt_Shoot_Dist_1 Rebuilt_Shoot_Dist_2 Rebuilt_Shoot_Dist_3 Rebuilt_Shoot_Dist_4 Rebuilt_Shoot_Dist_5 Rebuilt_Shoot_Dist_6 Rebuilt_Shoot_Dist_7];
    plot_shooter_i= [Rebuilt_Shoot_Shooter_Spd_I_0 Rebuilt_Shoot_Shooter_Spd_I_1 Rebuilt_Shoot_Shooter_Spd_I_2 Rebuilt_Shoot_Shooter_Spd_I_3 Rebuilt_Shoot_Shooter_Spd_I_4 Rebuilt_Shoot_Shooter_Spd_I_5 Rebuilt_Shoot_Shooter_Spd_I_6 Rebuilt_Shoot_Shooter_Spd_I_7];
    plot_shooter  = [Rebuilt_Shoot_Shooter_Spd_0 Rebuilt_Shoot_Shooter_Spd_1 Rebuilt_Shoot_Shooter_Spd_2 Rebuilt_Shoot_Shooter_Spd_3 Rebuilt_Shoot_Shooter_Spd_4 Rebuilt_Shoot_Shooter_Spd_5 Rebuilt_Shoot_Shooter_Spd_6 Rebuilt_Shoot_Shooter_Spd_7];
    plot_hood     = [Rebuilt_Shoot_Hood_Pos_0 Rebuilt_Shoot_Hood_Pos_1 Rebuilt_Shoot_Hood_Pos_2 Rebuilt_Shoot_Hood_Pos_3 Rebuilt_Shoot_Hood_Pos_4 Rebuilt_Shoot_Hood_Pos_5 Rebuilt_Shoot_Hood_Pos_6 Rebuilt_Shoot_Hood_Pos_7];
    plot_tof      = [Rebuilt_Shoot_TOF_0 Rebuilt_Shoot_TOF_1 Rebuilt_Shoot_TOF_2 Rebuilt_Shoot_TOF_3 Rebuilt_Shoot_TOF_4 Rebuilt_Shoot_TOF_5 Rebuilt_Shoot_TOF_6 Rebuilt_Shoot_TOF_7];
    plot_gyro_err = [Rebuilt_Shoot_Gyro_Err_0 Rebuilt_Shoot_Gyro_Err_1 Rebuilt_Shoot_Gyro_Err_2 Rebuilt_Shoot_Gyro_Err_3 Rebuilt_Shoot_Gyro_Err_4 Rebuilt_Shoot_Gyro_Err_5 Rebuilt_Shoot_Gyro_Err_6 Rebuilt_Shoot_Gyro_Err_7];
    
    figure(1)
    subplot(2,2,1), hold off
    plot(plot_dist,plot_shooter_i,'-^')
    hold on
    plot(plot_dist,plot_shooter,'-o')
    xlabel('Shot Distance (m)')
    ylabel('Shooter Speed (rpm)')
    grid on
    legend('Initial','Final','Location','northwest')
    
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
Rebuilt_Feeder_Motor_Gain_FF = 1/6048;

Rebuilt_Transfer_Motor_Gain_FF = 1/7854;
Rebuilt_Transfer_Motor_Gain_P = 0.0001;
Rebuilt_Transfer_Motor_Gain_I = 0.001*0.02;
Rebuilt_Transfer_Error_Integral_Enable = 300;

Rebuilt_Shooter_Motor_Gain_FF = 1.5e-4; %1/6048;
% Rebuilt_Shooter_Motor_Gain_P = 0.001;
% Rebuilt_Shooter_Motor_Gain_I = 0.001*0.02;
% Rebuilt_Shooter_Error_Integral_Enable = 300;

% Hood Position Servo Properties
Rebuilt_Hood_Servo_Pos_Min = 0.05;
Rebuilt_Hood_Servo_Pos_Max = 1;
Rebuilt_Hood_Servo_Rate_Limit_Inc = 32/50*0.02;   % no load 32 mm/sec, total stroke 50 mm
Rebuilt_Hood_Servo_Rate_Limit_Dec = -Rebuilt_Hood_Servo_Rate_Limit_Inc;

%% Intake
Rebuilt_Intake_Des_Angle_In = -40;
Rebuilt_Intake_Meas_In_Disable = -20;   % disable motor when angle is less than this value and the desired anle is the in angle
Rebuilt_Intake_Meas_Out_Disable = 80;   % disable motor when angle is more than this value and the desired anle is the out angle
Rebuilt_Intake_Des_Angle_Out = 90;

Rebuilt_Intake_Cycle_Angle_In = -10;
Rebuilt_Intake_Cycle_Angle_Out = 10;

Rebuilt_Intake_RL_Inc =  3;
Rebuilt_Intake_RL_Dec = -3;

Rebuilt_Intake_Arm_Gain_P = 0.008;
Rebuilt_Intake_Arm_Gain_D = 0;

Rebuilt_Roller_Desired_Speed = 4500;
Rebuilt_Roller_Motor_Gain_FF = 1/6048;
Rebuilt_Roller_Motor_Gain_P = 0.0001;
Rebuilt_Roller_Motor_Gain_I = 0.001*0.02;
Rebuilt_Roller_Error_Integral_Enable = 300;

