
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width  = 317.69 * 0.0254;
field_length = 651.22 * 0.0254;

% [x, y, velocity, angle]

% Blue NZ 
% Start Location: Depot Side
    % Setup Notes:
% Finish Location: Climb
Path_Blue_Left_NZ = [
    3.506,  7.259,  1,  19.983  *D2R;
    2.642,  6.876,  1,  8.746   *D2R;
    4.883,  7.560,  1,  0.000   *D2R;
    7.713,  5.303,  1, -75.104  *D2R;
    7.713,  3.503,  1, -75.104  *D2R;
    4.576,  2.702,  1,  0.000   *D2R;
    2.111,  2.942,  1,  108.853 *D2R;
    1.615,  3.882,  1, -173.059 *D2R;
    0,0,0,0;
    0,0,0,0];

Path_Red_Left_NZ = MirrorPath(Path_Blue_Left_NZ, field_width, field_length);

Path_Blue_Right_NZ = MirrorPathSameSide(Path_Blue_Left_NZ, field_width);
Path_Red_Right_NZ  = MirrorPathSameSide(Path_Red_Left_NZ,  field_width);


% Blue Depot 
% Start Location: Depot Side
    % Setup Notes:
% Finish Location: Climb
Path_Blue_Left_Depot = [
    3.75,  5.97,  1,  178.94 *D2R;
    2.06,  5.97,  1,  180.00 *D2R;
    %2.06,  5.97,  1,  174.33 *D2R;
    0.47,  5.97,  1,  177.98 *D2R;
    0.72,  5.97,  1,  116.57 *D2R;
    2.02,  4.95,  1, -125.96 *D2R;
    %2.02,  4.94,  1,  -27.41 *D2R;
    2.54,  4.18,  1,  -99.22 *D2R;
    1.61,  3.64,  1, -170.30 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

Path_Red_Left_Depot = MirrorPath(Path_Blue_Left_Depot, field_width, field_length);

% Blue Human Player 
% Start Location: Human Player Side
    % Setup Notes:
% Finish Location: Climb
Path_Blue_Right_HS = [
    3.80,  0.63,  1,  178.79 *D2R;
    0.16,  0.66,  1, -141.20 *D2R;
    3.06,  2.32,  1,   35.54 *D2R;
    1.64,  3.74,  1,  167.74 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

Path_Red_Right_HS = MirrorPath(Path_Blue_Right_HS, field_width, field_length);


% Blue Middle Human Player
% Start Location: Middle
    % Setup Notes:
% Finish Location: Climb
Path_Blue_Center_HS = [
    2.34,  4.03,  1,  000.00 *D2R;
    1.34,  2.03,  1,   90.00 *D2R;
    0.57,  0.66,  1,  180.00 *D2R;
    2.25,  2.44,  1,  180.00 *D2R;
    1.63,  3.81,  1,  180.00 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

Path_Red_Center_HS = MirrorPath(Path_Blue_Center_HS, field_width, field_length);

% Blue Middle Depot
% Start Location: Middle
    % Setup Notes:
% Finish Location: Climb
Path_Blue_Center_Depot = [
    2.34,  4.03,  1,  000.00 *D2R;
    1.85,  5.96,  1, -177.61 *D2R;
    0.62,  5.96,  1,  000.00 *D2R;
    2.12,  5.60,  1,  006.68 *D2R;
    1.59,  3.75,  1, -148.02 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

Path_Red_Center_Depot = MirrorPath(Path_Blue_Center_Depot, field_width, field_length);

% concatenate all of the paths into one multi-dimensional matrix
All_Paths_Ref_Poses = cat(3, ...
    Path_Blue_Left_NZ, ...
    Path_Red_Left_NZ, ...
    Path_Blue_Right_NZ, ...
    Path_Red_Right_NZ, ...
    Path_Blue_Left_Depot, ...
    Path_Red_Left_Depot, ...
    Path_Blue_Right_HS, ...
    Path_Red_Right_HS, ...
    Path_Blue_Center_HS, ...
    Path_Red_Center_HS, ...
    Path_Blue_Center_Depot, ...
    Path_Red_Center_Depot ...
    );
   

% collect the number of poses in each path
All_Paths_Num_Poses = [
    nnz(Path_Blue_Left_NZ(:,1));     % 1
    nnz(Path_Red_Left_NZ(:,1));      % 2
    nnz(Path_Blue_Left_NZ(:,1));     % 3
    nnz(Path_Red_Left_NZ(:,1));      % 4
    nnz(Path_Blue_Left_Depot(:,1));  % 5
    nnz(Path_Red_Left_Depot(:,1));   % 6
    nnz(Path_Blue_Right_HS(:,1));    % 7
    nnz(Path_Red_Right_HS(:,1));     % 8
    nnz(Path_Blue_Center_HS(:,1));   % 9
    nnz(Path_Red_Center_HS(:,1));    % 10
    nnz(Path_Blue_Center_Depot(:,1));% 11
    nnz(Path_Red_Center_Depot(:,1)); % 12

    ];

clear D2R field_width field_length
clear Path_Blue_Left_NZ 