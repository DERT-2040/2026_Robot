% Plot the field elements onto first subplot
Catmull_Rom_2026_field

% Define paths from another file
Auto_Paths_2026

% Create additional subplots
subplot(2,2,3)
hold on
subplot(2,2,4)
hold on

% Spline tuning parameter
Spline_Tension = 0.5;

% Define which paths to run
test_cases = [1:16];  % normal cases

% Plot all of the paths
for m = 1:length(test_cases)

    k = test_cases(m);

    % Define data used by simulation (defined by Code_Gen_Model_data.m)
    Spline_Ref_Poses = All_Paths_Ref_Poses(:,:,k);
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

    subplot(2,1,1)
    plot(plot_X,plot_Y)

    subplot(2,2,3)
    plot(plot_Distance,plot_Velocity)

    subplot(2,2,4)
    plot(plot_Distance,plot_Field_Angle)

end

subplot(2,1,1)
axis equal
grid on
xlabel('X (m)')
ylabel('Y (m)')

subplot(2,2,3)
grid on
xlabel('Distance Traveled')
ylabel('Velocity (m/s)')

subplot(2,2,4)
grid on
xlabel('Distance Traveled')
ylabel('Field Angle (deg)')

