figure
hold on
DrawField;

%% Create Necessary Constants
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


%% Set Input Parameters
isBlueAllianceTest = true;
Robot_X_Test  = 1; % [0:~] acceptable
Robot_Xv_Test = 1; % [0:~] acceptable
Robot_Y_Test  = 7; % [0:~] acceptable
Robot_Yv_Test = 0; % [0:~] acceptable

for iterations = 10:10
    %% Run Simulation
    out = sim("Desired_Shooting_Param_Calc.slx");

    %% Plot Output
    plot(out.Desired_Target_X,out.Desired_Target_Y,"o","LineWidth",5)
    text(out.Desired_Target_X,out.Desired_Target_Y,int2str(iterations))
end

% add the robot to the plot
Robot_Translated = RobotRotation(Robot_X_Test,Robot_Y_Test,out.Gyro_Angle_Test);
plot([Robot_Translated(1,1:4),Robot_Translated(1,1)],[Robot_Translated(2,1:4),Robot_Translated(2,1)],'b-')  % outside boundary
plot(Robot_Translated(1,5:6),Robot_Translated(2,5:6),'o')  % center and front points
plot(Blue_Hub_X,Blue_Hub_Y,"o","LineWidth",5)

