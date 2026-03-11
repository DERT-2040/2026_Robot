% Plot the field elements onto first subplot
Catmull_Rom_2026_field

% Define paths from another file
Rebuilt_Auto_Paths

% Create additional subplots
subplot(2,4,4)
hold on
subplot(2,4,8)
hold on

% Spline tuning parameter
Spline_Tension = 0.5;

% Enable or Disable plotting the robot rectangle at the Poses
plot_robot_rectangle = 1;  % 0 = off, 1 = on

% Define which paths to run
%test_cases = [1,4];
%test_cases = [2,3];
%test_cases = [5,6];
%test_cases = [7,8];
%test_cases = [9,10];
%test_cases = [11,12];
test_cases = [11,13,10];

%test_cases = 6;

for m = 1:length(test_cases)

    k = test_cases(m);

    % Define data used by simulation (defined by Code_Gen_Model_data.m)
    Spline_Ref_Poses = All_Paths_Ref_Poses_Blue(:,:,k);
    Spline_Num_Poses = All_Paths_Num_Poses(k);

    % Initial conditions
    sim_IC_x = Spline_Ref_Poses(1,1);
    sim_IC_y = Spline_Ref_Poses(1,2);

    % clear prior simulation data
    clear out

    % run simulation model and assign results to 'out'
    out = sim('Catmull_Rom_2026');


    %% Plot Results
    clear plot_X plot_Y plot_Velocity plot_Field_Angle plot_Distance

    plot_X(:) = out.Sim_X.signals.values;
    plot_Y(:) = out.Sim_Y.signals.values;
    plot_Velocity(:) = out.Sim_Velocity.signals.values;
    plot_Field_Angle(:) = out.Sim_Field_Angle.signals.values;
    plot_Distance(:) = out.Sim_Distance.signals.values;

    subplot(1,4,1:3)
    plot(plot_X,plot_Y)

    % add the robot to the plot
    if plot_robot_rectangle == 1
        for p = 1:Spline_Num_Poses
            Robot_Translated = RobotRotation(Spline_Ref_Poses(p,1),Spline_Ref_Poses(p,2),Spline_Ref_Poses(p,4));  % run the function at the selected pose
            plot([Robot_Translated(1,1:4),Robot_Translated(1,1)],[Robot_Translated(2,1:4),Robot_Translated(2,1)],'b-')  % outside boundary
            plot(Robot_Translated(1,5:6),Robot_Translated(2,5:6),'o')  % center and front points
            text(sum(Robot_Translated(1,5:6))/2,sum(Robot_Translated(2,5:6))/2,num2str(p))  % add point number to the plot
        end
    end

    subplot(2,4,4)
    plot(plot_Distance,plot_Velocity)

    subplot(2,4,8)
    plot(plot_Distance,plot_Field_Angle)

end

subplot(1,4,1:3)
axis equal
grid on
xlabel('X (m)')
ylabel('Y (m)')

subplot(2,4,4)
grid on
xlabel('Distance Traveled')
ylabel('Velocity (m/s)')

subplot(2,4,8)
grid on
xlabel('Distance Traveled')
ylabel('Field Angle (deg)')

