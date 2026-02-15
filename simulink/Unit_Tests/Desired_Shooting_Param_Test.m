figure
hold on
DrawField;

%% Create Necessary Constants
Rebuilt_Shooter_Test_data

%% Set Input Parameters
isBlueAllianceTest = true;
Robot_X_Test  = Blue_Hub_X-2; % [0:~] acceptable
Robot_Y_Test  = Blue_Hub_Y-2; % [0:~] acceptable
Robot_Xv_Test = 0; % [0:~] acceptable
Robot_Yv_Test = 0; % [0:~] acceptable

for iterations = 10:10
    %% Run Simulation
    out = sim("Desired_Shooting_Param_Calc.slx");

    %% Plot Output
    plot(out.Desired_Target_X,out.Desired_Target_Y,"o","LineWidth",5)
    text(out.Desired_Target_X,out.Desired_Target_Y,int2str(iterations))
end

% add the robot to the plot
Robot_Translated = RobotRotation(Robot_X_Test,Robot_Y_Test,out.Gyro_Angle_Test*pi/180);
plot([Robot_Translated(1,1:4),Robot_Translated(1,1)],[Robot_Translated(2,1:4),Robot_Translated(2,1)],'b-')  % outside boundary
plot(Robot_Translated(1,5:6),Robot_Translated(2,5:6),'o')                                                   % center and front points
plot(Robot_Translated(1,5)+[0 Robot_Xv_Test],Robot_Translated(2,5)+[0 Robot_Yv_Test],'-')                   % velocity vector
plot(Blue_Hub_X,Blue_Hub_Y,"o","LineWidth",5)

