%% Define Data
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width = 317 * 0.0254;
field_length = 691 * 0.0254;

Spline_Tension = 0.5;

% [x, y, velocity, angle]


%% Run simulation

% Create figure
figure(1), clf
subplot(2,1,1)
hold on

% Field
plot([0 0]*0.0254,[0 317.5]*0.0254,'k','LineWidth',3)
plot([0 297.7*2+95.9]*0.0254,[0 0]*0.0254,'k','LineWidth',3)
plot([0 297.7*2+95.9]*0.0254,[317.5 317.5]*0.0254,'k','LineWidth',3)
plot([297.7*2+95.9, 297.7*2+95.9]*0.0254,[0 317.5]*0.0254,'k','LineWidth',3)

plot([0, 65.276]*0.0254,[47.745, 0]*0.0254,'b','LineWidth',3)
plot([0, 65.276]*0.0254,[317.5-47.745, 317.5]*0.0254,'b','LineWidth',3)
plot([297.679*2 + 95.894 - 65.276, 297.679*2 + 95.894]*0.0254,[0, 47.745]*0.0254,'r','LineWidth',3)
plot([297.679*2 + 95.894 - 65.276, 297.679*2 + 95.894]*0.0254,[317.5, 317.5 - 47.745]*0.0254,'r','LineWidth',3)

plot([297.679, 297.679]*0.0254,[0, 317.5]*0.0254,'b','LineWidth',3)
plot([297.679+95.894, 297.679+95.894]*0.0254,[0, 317.5]*0.0254,'r','LineWidth',3)
plot([297.679+47.947, 297.679+47.947]*0.0254,[0, 317.5]*0.0254,'k','LineWidth',3)

plot([144 144 177 209 209 177 144]*0.0254,[139 177 196 177 139 120 139]*0.0254,'b','LineWidth',3)
plot((297.7*2+95.9)*0.0254-[144 144 177 209 209 177 144]*0.0254,[139 177 196 177 139 120 139]*0.0254,'r','LineWidth',3)

axis([-20*0.0254, (297.7*2+95.9+20)*0.0254, -20*0.0254, (317.5+20)*0.0254])
axis equal

subplot(2,2,3)
hold on
subplot(2,2,4)
hold on

% test_cases = [1:16];  % normal cases
% test_cases = [1, 17, 4, 18, 9, 19, 12, 20]; % end early cases

% individual symmetry checks
% test_cases = [1 4 9 12]+0;  % add 0 for A, add 1 for B, add 2 for C
% test_cases = [1 4 9 12]+1;  % add 0 for A, add 1 for B, add 2 for C
% test_cases = [1 4 9 12]+2;  % add 0 for A, add 1 for B, add 2 for C
% test_cases = [7 15]+0;  % add 0 for A, add 1 for B
 test_cases = [7 15]+1;  % add 0 for A, add 1 for B

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
    out = sim('Catmull_Rom_2025');


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

