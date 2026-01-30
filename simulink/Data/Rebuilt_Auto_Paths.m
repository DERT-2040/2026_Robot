
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width = 317 * 0.0254;
field_length = 691 * 0.0254;
All_Paths_Num_Poses = [];


% Path Point Definition
% [x, y, velocity, angle]

% Blue
% Start Location:
    % Setup Notes:
% Finish Location:
Path_Blue_Left_A = [
    x,  y,  v, theta * D2R;
    3.506,7.259,19.983,0;
    2.642,6.876,8.746,0;
    4.883,7.560,0.000,0;
    7.713,5.303,-75.104,0;
    4.576,2.702,0.000,0;
    2.111,2.942,108.853,0;
    1.615,3.882,-173.059,0;
    0,0,0,0;
    0,0,0,0];

% Red
% Start:  Starting Line on Right
% Finish: Reef Face E-F
Path_Red_Right_A = MirrorPath(Path_Blue_Right_A, field_width, field_length)

% concatenate all of the paths into one multi-dimensional matrix
All_Paths_Ref_Poses = cat(3, ...
    Path_Blue_Left_A ...%, ...
    ... % Path_Blue_Left_B, ...
    ... % Path_Blue_Left_C, ...
    ... % Path_Blue_Right_A, ...
    ... % Path_Blue_Right_B, ...
    ... % Path_Blue_Right_C, ...
    ... % Path_Blue_Center_A, ...
    ... % Path_Blue_Center_B, ...
    ... % Path_Red_Left_A, ...
    ... % Path_Red_Left_B, ...
    ... % Path_Red_Left_C, ...
    ... % Path_Red_Right_A, ...
    ... % Path_Red_Right_B, ...
    ... % Path_Red_Right_C, ...
    ... % Path_Red_Center_A, ...
    ... % Path_Red_Center_B, ...
    ... % Path_Blue_Left_B_end_early, ...
    ... % Path_Blue_Right_B_end_early, ...
    ... % Path_Red_Left_B_end_early, ...
    ... % Path_Red_Right_B_end_early ...
    );

% collect the number of poses in each path
All_Paths_Num_Poses = [
    nnz(Path_Blue_Left_A(:,1));     % 1
    % nnz(Path_Blue_Left_B(:,1));     % 2
    % nnz(Path_Blue_Left_C(:,1));     % 3
    % nnz(Path_Blue_Right_A(:,1));    % 4
    % nnz(Path_Blue_Right_B(:,1));    % 5
    % nnz(Path_Blue_Right_C(:,1));    % 6
    % nnz(Path_Blue_Center_A(:,1));   % 7
    % nnz(Path_Blue_Center_B(:,1));   % 8
    % nnz(Path_Red_Left_A(:,1));      % 9
    % nnz(Path_Red_Left_B(:,1));      % 10
    % nnz(Path_Red_Left_C(:,1));      % 11
    % nnz(Path_Red_Right_A(:,1));     % 12
    % nnz(Path_Red_Right_B(:,1));     % 13
    % nnz(Path_Red_Right_C(:,1));     % 14
    % nnz(Path_Red_Center_A(:,1));    % 15
    % nnz(Path_Red_Center_B(:,1));    % 16
    % nnz(Path_Blue_Left_B_end_early(:,1));  % 17
    % nnz(Path_Blue_Right_B_end_early(:,1)); % 18
    % nnz(Path_Red_Left_B_end_early(:,1));   % 19  
    % nnz(Path_Red_Right_B_end_early(:,1));  % 20
    ];

clear D2R field_width field_length
% clear Path_Blue_Left_A    % Path_Blue_Left_B Path_Blue_Left_C Path_Blue_Left_D 
% clear Path_Blue_Right_A   % Path_Blue_Right_B Path_Blue_Right_C Path_Blue_Right_D
% clear Path_Blue_Center_A  % Path_Blue_Center_B 
% clear Path_Red_Right_A    % Path_Red_Right_B Path_Red_Right_C Path_Red_Right_D
% clear Path_Red_Left_A     % Path_Red_Left_B Path_Red_Left_C Path_Red_Left_D
% clear Path_Blue_Left_B_end_early % Path_Blue_Right_B_end_early Path_Red_Right_B_end_early Path_Red_Left_B_end_early
% clear Path_Red_Center_A   % Path_Red_Center_B
