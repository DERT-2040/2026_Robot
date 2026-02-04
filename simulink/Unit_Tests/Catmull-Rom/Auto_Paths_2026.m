
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width = 317 * 0.0254;
field_length = 691 * 0.0254;

% [x, y, velocity, angle]

% Blue
% Start:  Starting Line on Left
% Finish: Reef Face I-J
Path_Blue_Left_A = [
    7.582,  6.528,  3.5, -150  *D2R;  % robot centered on black line, robot center is 60.0 inches from wall
    6.899,  6.243,  3.5, -140  *D2R;
    6.273,  5.948,  2.0, -130  *D2R;
    5.682,  5.558,  0.5, -120  *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Reef Face I-J
% Finish: Coral Left
Path_Blue_Left_B = [
    5.575,  5.575,  5.0, -120    *D2R;
    4.072,  6.241,  5.0,   -98     *D2R;
    2.629,  6.512,  3.0,   -76     *D2R;
    1.277,  6.857,  1.0,   -54     *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Reef Face I-J
% Finish: Coral Left
Path_Blue_Left_B_end_early = [
    5.575,  5.806,  2.0, -120    *D2R;
    4.072,  6.241,  2.0, -98     *D2R;
    2.828,  6.365,  2.0, -76     *D2R;
    1.638,  6.512,  0,   -54     *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Coral Left
% Finish: Reef Face L-K
Path_Blue_Left_C = [
    1.209,  6.940,  3.5, -54    *D2R;
    1.941,  6.507,  3.5,   -57    *D2R;
    2.633,  6.169,  2.0,   -60    *D2R;
    3.365,  5.828,  0.5,   -60    *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Starting Line on Right
% Finish: Reef Face E-F
Path_Blue_Right_A = [
    7.582,  1.524,  Path_Blue_Left_A(1,3),  125  *D2R;
    6.806,  1.708,  Path_Blue_Left_A(2,3),  122  *D2R;
    6.039,  2.004,  Path_Blue_Left_A(3,3),  120  *D2R;
    5.365,  2.306,  Path_Blue_Left_A(4,3),  120  *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Reef Face E-F
% Finish: Coral Right
Path_Blue_Right_B = [
    5.236,  2.221,  Path_Blue_Left_B(1,3),  120  *D2R;
    4.072,  1.811,  Path_Blue_Left_B(2,3),  87  *D2R;
    2.681,  1.490,  Path_Blue_Left_B(3,3),  54  *D2R;
    1.277,  1.195,  Path_Blue_Left_B(4,3),  54  *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Reef Face E-F
% Finish: Coral Right
Path_Blue_Right_B_end_early = [
    5.236,  2.221,  Path_Blue_Left_B_end_early(1,3),  -Path_Blue_Left_B_end_early(1,4);
    4.072,  1.811,  Path_Blue_Left_B_end_early(2,3),  -Path_Blue_Left_B_end_early(2,4);
    2.828,  1.687,  Path_Blue_Left_B_end_early(3,3),  -Path_Blue_Left_B_end_early(3,4);
    1.638,  1.540,  Path_Blue_Left_B_end_early(4,3),  -Path_Blue_Left_B_end_early(4,4);
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Coral Right
% Finish: Reef Face C-D
Path_Blue_Right_C = [
    1.209,  1.112,  Path_Blue_Left_C(1,3),  -Path_Blue_Left_C(1,4);
    1.889,  1.541,  Path_Blue_Left_C(2,3),  -Path_Blue_Left_C(2,4);
    2.594,  1.929,  Path_Blue_Left_C(3,3),  -Path_Blue_Left_C(3,4);
    3.256,  2.280,  Path_Blue_Left_C(4,3),  -Path_Blue_Left_C(4,4);
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Starting Line on Center
% Finish: Reef Face G-H
Path_Blue_Center_A = [
    7.582,  field_width/2,  2.0, -180    *D2R;
    6.225,  field_width/2,  0.5,   -180    *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue
% Start:  Reef Face G-H
% Finish: Processor
Path_Blue_Center_B = [
    6.927,  field_width/2,  3,   -180    *D2R;
    6.630,  2.962,          3,   -150    *D2R;
    6.299,  1.792,          1.5, -120    *D2R;
    5.995,  0.731,          0,    -90    *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Starting Line on Right
% Finish: Reef Face E-F
Path_Red_Right_A = [
    field_length-Path_Blue_Right_A(1,1),  field_width-Path_Blue_Right_A(1,2),  Path_Blue_Right_A(1,3),  Path_Blue_Right_A(1,4)-pi;
    field_length-Path_Blue_Right_A(2,1),  field_width-Path_Blue_Right_A(2,2),  Path_Blue_Right_A(2,3),  Path_Blue_Right_A(2,4)-pi;
    field_length-Path_Blue_Right_A(3,1),  field_width-Path_Blue_Right_A(3,2),  Path_Blue_Right_A(3,3),  Path_Blue_Right_A(3,4)-pi;
    field_length-Path_Blue_Right_A(4,1),  field_width-Path_Blue_Right_A(4,2),  Path_Blue_Right_A(4,3),  Path_Blue_Right_A(4,4)-pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Reef Face E-F
% Finish: Coral Right
Path_Red_Right_B = [
    field_length-Path_Blue_Right_B(1,1),  field_width-Path_Blue_Right_B(1,2),  Path_Blue_Right_B(1,3),  Path_Blue_Right_B(1,4)-pi;
    field_length-Path_Blue_Right_B(2,1),  field_width-Path_Blue_Right_B(2,2),  Path_Blue_Right_B(2,3),  Path_Blue_Right_B(2,4)-pi;
    field_length-Path_Blue_Right_B(3,1),  field_width-Path_Blue_Right_B(3,2),  Path_Blue_Right_B(3,3),  Path_Blue_Right_B(3,4)-pi;
    field_length-Path_Blue_Right_B(4,1),  field_width-Path_Blue_Right_B(4,2),  Path_Blue_Right_B(4,3),  Path_Blue_Right_B(4,4)-pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Reef Face E-F
% Finish: Coral Right
Path_Red_Right_B_end_early = [
    field_length-Path_Blue_Right_B_end_early(1,1),  field_width-Path_Blue_Right_B_end_early(1,2),  Path_Blue_Right_B_end_early(1,3),  Path_Blue_Right_B_end_early(1,4)-pi;
    field_length-Path_Blue_Right_B_end_early(2,1),  field_width-Path_Blue_Right_B_end_early(2,2),  Path_Blue_Right_B_end_early(2,3),  Path_Blue_Right_B_end_early(2,4)-pi;
    field_length-Path_Blue_Right_B_end_early(3,1),  field_width-Path_Blue_Right_B_end_early(3,2),  Path_Blue_Right_B_end_early(3,3),  Path_Blue_Right_B_end_early(3,4)-pi;
    field_length-Path_Blue_Right_B_end_early(4,1),  field_width-Path_Blue_Right_B_end_early(4,2),  Path_Blue_Right_B_end_early(4,3),  Path_Blue_Right_B_end_early(4,4)-pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];


% Red
% Start:  Coral Right
% Finish: Reef Face E-F
Path_Red_Right_C = [
    field_length-Path_Blue_Right_C(1,1),  field_width-Path_Blue_Right_C(1,2),  Path_Blue_Right_C(1,3),  Path_Blue_Right_C(1,4)-pi;
    field_length-Path_Blue_Right_C(2,1),  field_width-Path_Blue_Right_C(2,2),  Path_Blue_Right_C(2,3),  Path_Blue_Right_C(2,4)-pi;
    field_length-Path_Blue_Right_C(3,1),  field_width-Path_Blue_Right_C(3,2),  Path_Blue_Right_C(3,3),  Path_Blue_Right_C(3,4)-pi;
    field_length-Path_Blue_Right_C(4,1),  field_width-Path_Blue_Right_C(4,2),  Path_Blue_Right_C(4,3),  Path_Blue_Right_C(4,4)-pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Starting Line on Left
% Finish: Reef Face E-F
Path_Red_Left_A = [
    field_length-Path_Blue_Left_A(1,1),  field_width-Path_Blue_Left_A(1,2),  Path_Blue_Left_A(1,3),  Path_Blue_Left_A(1,4)+pi;
    field_length-Path_Blue_Left_A(2,1),  field_width-Path_Blue_Left_A(2,2),  Path_Blue_Left_A(2,3),  Path_Blue_Left_A(2,4)+pi;
    field_length-Path_Blue_Left_A(3,1),  field_width-Path_Blue_Left_A(3,2),  Path_Blue_Left_A(3,3),  Path_Blue_Left_A(3,4)+pi;
    field_length-Path_Blue_Left_A(4,1),  field_width-Path_Blue_Left_A(4,2),  Path_Blue_Left_A(4,3),  Path_Blue_Left_A(4,4)+pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Reef Face E-F
% Finish: Coral Left
Path_Red_Left_B = [
    field_length-Path_Blue_Left_B(1,1),  field_width-Path_Blue_Left_B(1,2),  Path_Blue_Left_B(1,3),  Path_Blue_Left_B(1,4)+pi;
    field_length-Path_Blue_Left_B(2,1),  field_width-Path_Blue_Left_B(2,2),  Path_Blue_Left_B(2,3),  Path_Blue_Left_B(2,4)+pi;
    field_length-Path_Blue_Left_B(3,1),  field_width-Path_Blue_Left_B(3,2),  Path_Blue_Left_B(3,3),  Path_Blue_Left_B(3,4)+pi;
    field_length-Path_Blue_Left_B(4,1),  field_width-Path_Blue_Left_B(4,2),  Path_Blue_Left_B(4,3),  Path_Blue_Left_B(4,4)+pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Reef Face E-F
% Finish: Coral Left
Path_Red_Left_B_end_early = [
    field_length-Path_Blue_Left_B_end_early(1,1),  field_width-Path_Blue_Left_B_end_early(1,2),  Path_Blue_Left_B_end_early(1,3),  Path_Blue_Left_B_end_early(1,4)+pi;
    field_length-Path_Blue_Left_B_end_early(2,1),  field_width-Path_Blue_Left_B_end_early(2,2),  Path_Blue_Left_B_end_early(2,3),  Path_Blue_Left_B_end_early(2,4)+pi;
    field_length-Path_Blue_Left_B_end_early(3,1),  field_width-Path_Blue_Left_B_end_early(3,2),  Path_Blue_Left_B_end_early(3,3),  Path_Blue_Left_B_end_early(3,4)+pi;
    field_length-Path_Blue_Left_B_end_early(4,1),  field_width-Path_Blue_Left_B_end_early(4,2),  Path_Blue_Left_B_end_early(4,3),  Path_Blue_Left_B_end_early(4,4)+pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];


% Red
% Start:  Coral Left
% Finish: Reef Face E-F
Path_Red_Left_C = [
    field_length-Path_Blue_Left_C(1,1),  field_width-Path_Blue_Left_C(1,2),  Path_Blue_Left_C(1,3),  Path_Blue_Left_C(1,4)+pi;
    field_length-Path_Blue_Left_C(2,1),  field_width-Path_Blue_Left_C(2,2),  Path_Blue_Left_C(2,3),  Path_Blue_Left_C(2,4)+pi;
    field_length-Path_Blue_Left_C(3,1),  field_width-Path_Blue_Left_C(3,2),  Path_Blue_Left_C(3,3),  Path_Blue_Left_C(3,4)+pi;
    field_length-Path_Blue_Left_C(4,1),  field_width-Path_Blue_Left_C(4,2),  Path_Blue_Left_C(4,3),  Path_Blue_Left_C(4,4)+pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Starting Line on Center
% Finish: Reef Face G-H
Path_Red_Center_A = [
    field_length-Path_Blue_Center_A(1,1),  field_width-Path_Blue_Center_A(1,2),  Path_Blue_Center_A(1,3), Path_Blue_Center_A(1,4)+pi;
    field_length-Path_Blue_Center_A(2,1),  field_width-Path_Blue_Center_A(2,2),  Path_Blue_Center_A(2,3), Path_Blue_Center_A(1,4)+pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Reef Face G-H
% Finish: Starting Line on Center
Path_Red_Center_B = [
    field_length-Path_Blue_Center_B(1,1),  field_width-Path_Blue_Center_B(1,2),  Path_Blue_Center_B(1,3), Path_Blue_Center_B(1,4)+pi;
    field_length-Path_Blue_Center_B(2,1),  field_width-Path_Blue_Center_B(2,2),  Path_Blue_Center_B(2,3), Path_Blue_Center_B(2,4)+pi;
    field_length-Path_Blue_Center_B(3,1),  field_width-Path_Blue_Center_B(3,2),  Path_Blue_Center_B(3,3), Path_Blue_Center_B(3,4)+pi;
    field_length-Path_Blue_Center_B(4,1),  field_width-Path_Blue_Center_B(4,2),  Path_Blue_Center_B(4,3), Path_Blue_Center_B(4,4)+pi;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% concatenate all of the paths into one multi-dimensional matrix
All_Paths_Ref_Poses = cat(3, ...
    Path_Blue_Left_A, ...
    Path_Blue_Left_B, ...
    Path_Blue_Left_C, ...
    Path_Blue_Right_A, ...
    Path_Blue_Right_B, ...
    Path_Blue_Right_C, ...
    Path_Blue_Center_A, ...
    Path_Blue_Center_B, ...
    Path_Red_Left_A, ...
    Path_Red_Left_B, ...
    Path_Red_Left_C, ...
    Path_Red_Right_A, ...
    Path_Red_Right_B, ...
    Path_Red_Right_C, ...
    Path_Red_Center_A, ...
    Path_Red_Center_B, ...
    Path_Blue_Left_B_end_early, ...
    Path_Blue_Right_B_end_early, ...
    Path_Red_Left_B_end_early, ...
    Path_Red_Right_B_end_early ...
    );

% collect the number of poses in each path
All_Paths_Num_Poses = [
    nnz(Path_Blue_Left_A(:,1));     % 1
    nnz(Path_Blue_Left_B(:,1));     % 2
    nnz(Path_Blue_Left_C(:,1));     % 3
    nnz(Path_Blue_Right_A(:,1));    % 4
    nnz(Path_Blue_Right_B(:,1));    % 5
    nnz(Path_Blue_Right_C(:,1));    % 6
    nnz(Path_Blue_Center_A(:,1));   % 7
    nnz(Path_Blue_Center_B(:,1));   % 8
    nnz(Path_Red_Left_A(:,1));      % 9
    nnz(Path_Red_Left_B(:,1));      % 10
    nnz(Path_Red_Left_C(:,1));      % 11
    nnz(Path_Red_Right_A(:,1));     % 12
    nnz(Path_Red_Right_B(:,1));     % 13
    nnz(Path_Red_Right_C(:,1));     % 14
    nnz(Path_Red_Center_A(:,1));    % 15
    nnz(Path_Red_Center_B(:,1));    % 16
    nnz(Path_Blue_Left_B_end_early(:,1));  % 17
    nnz(Path_Blue_Right_B_end_early(:,1)); % 18
    nnz(Path_Red_Left_B_end_early(:,1));   % 19  
    nnz(Path_Red_Right_B_end_early(:,1));  % 20
    ];

clear D2R field_width field_length
clear Path_Blue_Left_A Path_Blue_Left_B Path_Blue_Left_C Path_Blue_Left_D 
clear Path_Blue_Right_A Path_Blue_Right_B Path_Blue_Right_C Path_Blue_Right_D
clear Path_Blue_Center_A Path_Blue_Center_B 
clear Path_Red_Right_A Path_Red_Right_B Path_Red_Right_C Path_Red_Right_D
clear Path_Red_Left_A Path_Red_Left_B Path_Red_Left_C Path_Red_Left_D
clear Path_Blue_Left_B_end_early Path_Blue_Right_B_end_early Path_Red_Right_B_end_early Path_Red_Left_B_end_early
clear Path_Red_Center_A Path_Red_Center_B
