%% Spline Path Following
% Not tunable while running
Spline_Num_Samples = 50;
Spline_Num_Samples_3x = Spline_Num_Samples*3;
Spline_Samples_Per_Pass = 10; % must be an even number
Spline_Max_Num_RefPoses = 10;
% Spline_Num_Poses_default = Spline_Max_Num_RefPoses;
% Spline_Ref_Poses_default = zeros(Spline_Max_Num_RefPoses,4);
Spline_Tension = 0.5;
Spline_Velocity_Axis  = [0.50 1.50 2.50 3.50]; % m/s
Spline_Capture_Radius = [0.20 0.30 0.40 0.50]; % m
Spline_Lookahead_Dist = [0.20 0.20 0.20 0.40]; % m

D2R = pi/180;
Spline_Ref_Poses_default = [
   13.0310    0.9593    2.0000    3.1416         0    2.0000;
    9.5410    0.7593    2.0000    2.0944         0    2.0000;
    8.8410    3.2993    2.0000    1.5708         0    2.0000;
    9.2410    4.9193    2.0000    1.5708         0         0;
   11.2810    5.6693    2.0000    3.9270         0         0;
   12.7610    5.6693    1.0000    3.9270         0         0;
   13.3410    4.9693    1.0000    3.6652    1.0000         0;
   14.3710    4.9093    1.0000    1.5708         0         0;
   15.0110    4.9093    1.0000    1.5708    3.0000         0;
         0         0         0         0         0         0
];
Spline_Num_Poses_default = 9;
clear D2R;


% % Tunable while running
Spline_Stop_Radius = 0.1; % m
Spline_Max_Centripital_Acceleration = 10; % m/sec^2
Spline_Pose_Num_Before_End_Reduce_Speed = 1;  % index count
Spline_Last_Pose_Distance_to_Velocity_Gain = 2; % (m/sec) / (m)
Spline_Velocity_Multiplier_TEST = 1.0;  % velocity scaling for test purposes only