
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width  = 317.69 * 0.0254;
field_length = 651.22 * 0.0254;

% [x, y, velocity, angle]

% Depot strat DP Start to DP 
% Start Location: Depot Side
    % Setup Notes:
% Finish Location: Depot
Path_Blue_Left_DP = [
    3.75, 5.97, 1, 178.94 *D2R;
    0.71, 5.97, 1, 180.00 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue Depot strat DP to Shoot
% Start Location: Depot Side
    % Setup Notes:
% Finish Location: shooting position
Path_Blue_Left_Depot = [
    0.71, 5.97, 1, 116.57 *D2R;
    2.02, 4.95, 1, -125.96 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue Depot strat shoot to climb
% Start Location: Depot side
    % Setup Notes:
% Finish Location: Climb
Path_Blue_Right_HS = [
    2.02, 4.95, 1, -27.41 *D2R;
    2.54, 4.18, 1, -99.23 *D2R;
    1.61, 3.64, 1, -170.30 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue HP start start to HP
% Start Location: human side
    % Setup Notes:
% Finish Location: HP
Path_Blue_Center_HS = [
    3.51, 0.62, 1, 0.00 *D2R;
    0.49, 0.73, 1, 0.00 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue HP strat Hp to shoot
% Start Location: HP
    % Setup Notes:
% Finish Location: shoot
Path_Blue_Center_Depot = [
    0.49, 0.73, 1, 0.00 *D2R;
    2.27, 2.32, 1, 13.04 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];


% Blue HP strat shoot to climb
% Start Location: Shoot 
    % Setup Notes:
% Finish Location: climb
Path_Blue_Center_Depot = [
    2.27, 2.32, 1, 73.34 *D2R;
    1.60, 3.77, 1, -171.08 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue DP to Neutral zone strat
% Start Location: Left side
    % Setup Notes:
% Finish Location: NZ
Path_Blue_Center_Depot = [
    2.48, 7.11, 1, 10.10 *D2R;
    5.54, 7.31, 1, -12.04 *D2R;
    7.77, 5.77, 1, -89.38 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue DP to Neutral zone strat
% Start Location: NZ 
    % Setup Notes:
% Finish Location: shoot 
Path_Blue_Center_Depot = [
    7.77, 5.77, 1, -104.35 *D2R;
    7.09, 3,09, 1, -125.46 *D2R;
    4.37, 2.19, 1, -170.00 *D2R;
    2.67, 2.68, 1, 88.85 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue DP to Neutral zone strat
% Start Location: shoot
    % Setup Notes:
% Finish Location: climb 
Path_Blue_Center_Depot = [
    2.67, 2.68, 1, 88.85 *D2R;
    1.61, 3.77, 1, 131.52 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue HP to NZ  Strat
% Start Location: start Right
    % Setup Notes:
% Finish Location: NZ 
Path_Blue_Center_Depot = [
    3.05, 0.88, 1, 0.00 *D2R;
    6.27, 0.68, 1, 16.54 *D2R;
    7.81, 3.38, 1, 99.81 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue HP to NZ  Strat
% Start Location: NZ
    % Setup Notes:
% Finish Location: Shoot left side 
Path_Blue_Center_Depot = [
    7.81, 3.38, 1, 102.72 *D2R;
    4.93, 7.55, 1, 176.79 *D2R;
    2.80, 6.34, 1, -112.93 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Blue HP to NZ  Strat
% Start Location: shoot
    % Setup Notes:
% Finish Location: climb 
Path_Blue_Center_Depot = [
    2.80, 6.34, 1, -112.93 *D2R;
    1.57, 3.79, 1, 0.00 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Path_Red_Center_Depot = MirrorPath(Path_Blue_Center_Depot, field_width, field_length);

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