
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width  = 317.69 * 0.0254;
field_length = 651.22 * 0.0254;

%Chooser

Auto_Path_Chooser = 1; % default chooser path sequence number
Auto_Shoot_Time = 4;   % seconds

% [x, y, velocity, angle, action at path point, action during path segment]
%     Column 5 action defined in the current row is the action taken
%     at this point until it is completed.
%
%     Column 6 action defined in the current row is the action taken
%     between the previous row point and the current row point and ends when
%     the robot reaches the destination point in the next row.
%
% Legend for columns 5 and 6
% 0 = Travel only (no other action)
% 1 = Spin up before shooting
% 2 = Shooting
% 3 = Gather Fuel from Floor
% 4 = Climb

% Start Location:  Left Trench
% Middle Location: Neutral Zone
% Finish Location: Right Hub
Path_LT_NZ_RH = [
    3.51, 7.11, 2,   0 *D2R, 0, 0;
    7.00, 7.31, 2, -60 *D2R, 0, 3;
    7.70, 4.77, 2, -90 *D2R, 0, 3;
    7.30, 3.15, 2, -90 *D2R, 0, 3;
    5.26, 2.4,  1,  45 *D2R, 0, 0;
    3.78, 2.4,  1,  45 *D2R, 0, 1;
    3.20, 3.10, 1,  30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location:  Right Hub
% Finish Location: Right Climb
Path_RH_RC = [
    3.20, 3.10, 1,  30 *D2R, 0, 0;
    2.17, 3.16, 1, -90 *D2R, 0, 0;
    1.53, 3.16, 1, -90 *D2R, 4, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;    
    0,0,0,0,0,0];

% Start Location:  Right Hub
% Finish Location: Left Climb
Path_RH_LC = [
    3.20, 3.10, 1,  30 *D2R, 0, 0;
    2.70, 4.25, 1, -90 *D2R, 0, 0;
    1.53, 4.35, 1, -90 *D2R, 4, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;    
    0,0,0,0,0,0];

% Start Location:  Right Trench
% Middle Location: Neutral Zone
% Finish Location: Left Hub
Path_RT_NZ_LH = [
    3.51, 0.96, 2,   0 *D2R, 0, 0;
    7.00, 0.76, 2,  60 *D2R, 0, 3;
    7.70, 3.30, 2,  90 *D2R, 0, 3;
    7.30, 4.92, 2,  90 *D2R, 0, 3;
    5.26, 5.66, 2, -45 *D2R, 0, 0;
    3.78, 5.66, 1, -45 *D2R, 0, 1;
    3.20, 4.97, 1, -30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0];

% Start Location:  Left Hub
% Finish Location: Left Climb
Path_LH_LC = [
    3.20, 4.97, 1, -30 *D2R, 0, 0;
    2.70, 4.40, 1, -90 *D2R, 0, 0;
    1.53, 4.35, 1, -90 *D2R, 4, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0;     
    0,0,0,0,0,0];

% Start Location:  Left Hub
% Finish Location: Right Climb
Path_LH_RC = [
    3.20, 4.97, 1, -30 *D2R, 0, 0;
    2.70, 3.35, 1, -90 *D2R, 0, 0;
    1.53, 3.16, 1, -90 *D2R, 4, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0;     
    0,0,0,0,0,0];

% Start Location: Right Trench
% Finish Location: Outpost
Path_RT_OP = [
    3.51, 0.62, 1, 180 *D2R, 0, 0;
    0.75, 0.73, 1, 180 *D2R, 0, 3;
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location: Outpost
% Finish Location: Right Hub
Path_OP_RH = [
    0.75, 0.73, 1, 180 *D2R, 0, 0;
    1.30, 1.30, 1, 180 *D2R, 0, 3;
    3.20, 3.10, 1, 30  *D2R, 2, 0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location: Left Ramp
% Finish Location: Depot
Path_LR_DP = [
    3.75, 5.9, 1,  180 *D2R, 0, 0;
    0.71, 5.97, 1, 180 *D2R, 0, 3;
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location: Depot 
% Finish Location: Left Hub
Path_DP_LH = [
    0.71, 5.97, 1, 180 *D2R, 0, 0;
    1.35, 5.97, 1, 180 *D2R, 0, 3;
    3.20, 4.97, 1, -30 *D2R, 2, 0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

clear D2R

% concatenate all of the paths into one multi-dimensional matrix
All_Paths_Ref_Poses_Blue = cat(3, ...
    Path_LT_NZ_RH, ...   % 1
    Path_RH_RC, ...      % 2
    Path_RH_LC, ...      % 3
    Path_RT_NZ_LH, ...   % 4
    Path_LH_LC, ...      % 5
    Path_LH_RC, ...      % 6
    Path_RT_OP, ...      % 7
    Path_OP_RH, ...      % 8
    Path_LR_DP, ...      % 9
    Path_DP_LH ...       % 10
  ); 

% Run this function to mirron paths from blue to red sides of the field
% Path_1_Red = MirrorPath(Path_1_Blue, field_width, field_length);

All_Paths_Ref_Poses_Red = cat(3, ...
    MirrorPath(Path_LT_NZ_RH, field_width, field_length), ...   % 1
    MirrorPath(Path_RH_RC, field_width, field_length), ...      % 2
    MirrorPath(Path_RH_LC, field_width, field_length), ...      % 3
    MirrorPath(Path_RT_NZ_LH, field_width, field_length), ...   % 4
    MirrorPath(Path_LH_LC, field_width, field_length), ...      % 5
    MirrorPath(Path_LH_RC, field_width, field_length), ...      % 6
    MirrorPath(Path_RT_OP, field_width, field_length), ...      % 7
    MirrorPath(Path_OP_RH, field_width, field_length), ...      % 8
    MirrorPath(Path_LR_DP, field_width, field_length), ...      % 9
    MirrorPath(Path_DP_LH, field_width, field_length) ...       % 10
  ); 

clear field_width field_length

% collect the number of poses in each path
All_Paths_Num_Poses = [
    nnz(Path_LT_NZ_RH(:,1));    % 1
    nnz(Path_RH_RC(:,1));       % 2
    nnz(Path_RH_LC(:,1));       % 3
    nnz(Path_RT_NZ_LH(:,1));    % 4
    nnz(Path_LH_LC(:,1));       % 5
    nnz(Path_LH_RC(:,1));       % 6
    nnz(Path_RT_OP(:,1));       % 7
    nnz(Path_OP_RH(:,1));       % 8
    nnz(Path_LR_DP(:,1));       % 9
    nnz(Path_DP_LH(:,1))        % 10
    ];

clear Path_LT_NZ_RH Path_RH_RC Path_RH_LC Path_RT_NZ_LH Path_LH_LC
clear Path_LH_RC Path_RT_OP Path_OP_RH Path_LR_DP Path_DP_LH

% Define complete auto paths
Auto_Path_01 = [1,2,0];
Auto_Path_02 = [1,3,0];
Auto_Path_03 = [4,5,0];
Auto_Path_04 = [4,6,0];
Auto_Path_05 = [7,8,2];
Auto_Path_06 = [7,8,3];
Auto_Path_07 = [9,10,5];
Auto_Path_08 = [9,10,6];