
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
    3.51, 7.20, 2,   0 *D2R, 0, 0;
    7.00, 7.31, 1.5, -60 *D2R, 0, 3;
    7.70, 4.77, 1.5, -90 *D2R, 0, 3;
    7.60, 2.00, 1.5, -90 *D2R, 0, 3;
    6.00, 0.90, 1.5, 180 *D2R, 0, 0;
    3.50, 0.90, 1.5, 180 *D2R, 0, 1;
    3.20, 3.10, 1,  30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location:  Right Trench
% Middle Location: Neutral Zone
% Finish Location: Left Hub
Path_RT_NZ_LH = MirrorPathSameSide(Path_LT_NZ_RH,field_width);
Path_RT_NZ_LH(1,4) = 0 *D2R;
Path_RT_NZ_LH(2,4) = 60 *D2R;
Path_RT_NZ_LH(3,4) = 90 *D2R;
Path_RT_NZ_LH(4,4) = 90 *D2R;
Path_RT_NZ_LH(5,4) = 180 *D2R;
Path_RT_NZ_LH(6,4) = 180 *D2R;
Path_RT_NZ_LH(7,4) = -30 *D2R;


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

%Start Location: Left ramp
% Finish Location: Right Hub
Path_LR_RH = [
    3.75, 5.9, 1,  180 *D2R, 0, 0;
    0.71, 5.97, 1, 180 *D2R, 0, 0;
    2.00, 4.00, 1, -90 *D2R, 0, 3;
    0.75, 0.73, 1, 180 *D2R, 0, 0;
    3.20, 3.10, 1, 30  *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%Start Location: left trench
% Finish Location: NZ
Path_LT_NZ = [
  3.51, 7.20, 2,   0 *D2R, 0, 0;
    7.00, 7.31, 1.5, -60 *D2R, 0, 3;
    7.70, 4.77, 1.5, -90 *D2R, 0, 3;
   0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];
%Start Location:NZ 
% Finish Location: Left hub
Path_NZ_LH = [
 7.70, 4.77, 1.5, -90 *D2R, 0, 3;
    7.00, 7.31, 1.5, -60 *D2R, 0, 3;
    3.51, 7.20, 2,   0 *D2R, 0, 0;
    3.00, 5.50, 1, 90 *D2R, 0, 0;
  3.20, 4.97, 1, -30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

clear D2R

% concatenate all of the paths into one multi-dimensional matrix
All_Paths_Ref_Poses_Blue = cat(3, ...
    Path_LT_NZ_RH, ...   % 1
    Path_RT_NZ_LH, ...   % 2
    Path_RT_OP, ...      % 3
    Path_OP_RH, ...      % 4
    Path_LR_DP, ...      % 5
    Path_DP_LH, ...      % 6
    Path_LR_RH, ...      % 7
    Path_LT_NZ, ...       %8
    Path_NZ_LH ...       %9
  ); 

% Run this function to mirron paths from blue to red sides of the field
% Path_1_Red = MirrorPath(Path_1_Blue, field_width, field_length);

All_Paths_Ref_Poses_Red = cat(3, ...
    MirrorPath(Path_LT_NZ_RH, field_width, field_length), ...   % 1
    MirrorPath(Path_RT_NZ_LH, field_width, field_length), ...   % 2
    MirrorPath(Path_RT_OP, field_width, field_length), ...      % 3
    MirrorPath(Path_OP_RH, field_width, field_length), ...      % 4
    MirrorPath(Path_LR_DP, field_width, field_length), ...      % 5
    MirrorPath(Path_DP_LH, field_width, field_length), ...      % 6
    MirrorPath(Path_LR_RH, field_width, field_length), ...       % 7
    MirrorPath(Path_LT_NZ, field_width, field_length), ...       % 8
     MirrorPath(Path_NZ_LH, field_width, field_length) ...       % 8
  ); 

clear field_width field_length

% collect the number of poses in each path
All_Paths_Num_Poses = [
    nnz(Path_LT_NZ_RH(:,1));    % 1
    nnz(Path_RT_NZ_LH(:,1));    % 2
    nnz(Path_RT_OP(:,1));       % 3
    nnz(Path_OP_RH(:,1));       % 4
    nnz(Path_LR_DP(:,1));       % 5
    nnz(Path_DP_LH(:,1));       % 6
    nnz(Path_LR_RH(:,1))        % 7
     nnz(Path_LT_NZ(:,1))        % 8
     nnz(Path_NZ_LH(:,1))        % 8
    ];

clear Path_LT_NZ_RH Path_RH_RC Path_RH_LC Path_RT_NZ_LH Path_LH_LC
clear Path_LH_RC Path_RT_OP Path_OP_RH Path_LR_DP Path_DP_LH Path_LR_RH Path_LT_NZ Path_NZ_LH

% Define complete auto paths (fill with zeros so all are the same length)
Auto_Path_01 = [1,0,0];
Auto_Path_02 = [2,0,0];
Auto_Path_03 = [3,4,0];
Auto_Path_04 = [5,6,0];
