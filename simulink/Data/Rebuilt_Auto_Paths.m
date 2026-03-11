
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width  = 317.69 * 0.0254;
field_length = 651.22 * 0.0254;

%Chooser

Auto_Path_Chooser = 1; % default chooser path sequence number
Auto_Shoot_Time = 3;   % seconds

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

% Start Location:  Left Trench
% Middle Location: Neutral Zone
% Finish Location: Right Hub
Path_LT_NZ_RH = [
    3.51, 7.20, 2.0,   0 *D2R, 0, 0;
    7.00, 7.31, 1.5, -60 *D2R, 0, 3;
    7.70, 4.77, 1.5, -90 *D2R, 0, 3;
    7.60, 2.00, 1.5, -90 *D2R, 0, 3;
    6.00, 0.90, 2.0, 180 *D2R, 0, 0;
    3.50, 0.90, 2.0, 180 *D2R, 0, 1;
    3.20, 3.10, 1.0,  30 *D2R, 2, 0;
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

% Start Location:  Left Hub
% Middle Location: Neutral Zone Close to Hub
% Finish Location: Right Hub
Path_LH_NZ_RH = [
    3.20, 4.97, 2.0, -30 *D2R, 0, 0;
    3.20, 7.20, 2.0,   0 *D2R, 0, 0;
    5.50, 7.31, 1.5, -60 *D2R, 0, 3;
    5.90, 5.00, 1.5, -90 *D2R, 0, 3;
    5.90, 2.40, 1.5, -90 *D2R, 0, 3;
    5.50, 0.90, 2.0, 180 *D2R, 0, 0;
    3.50, 0.90, 2.0, 180 *D2R, 0, 1;
    3.20, 3.10, 1.0,  30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location:  Right Hub
% Middle Location: Neutral Zone Close to Hub
% Finish Location: Left Hub
Path_RH_NZ_LH = MirrorPathSameSide(Path_LH_NZ_RH,field_width);
Path_RH_NZ_LH(1,4) = 30 *D2R;
Path_RH_NZ_LH(2,4) =  0 *D2R;
Path_RH_NZ_LH(3,4) =  0 *D2R;
Path_RH_NZ_LH(4,4) = 90 *D2R;
Path_RH_NZ_LH(5,4) = 90 *D2R;
Path_RH_NZ_LH(6,4) = 180 *D2R;
Path_RH_NZ_LH(7,4) = 180 *D2R;
Path_RH_NZ_LH(8,4) = -30 *D2R;


% Start Location: Left Trench
% Middle Location: Neutral Zone Loop Back
% Finish Location: Left Hub
Path_LT_NZ_LH = [
    3.51, 7.20, 2.0,   0 *D2R, 0, 0;
    7.00, 7.31, 1.5, -60 *D2R, 0, 3;
    7.70, 4.77, 1.5, -90 *D2R, 0, 3;
    6.00, 4.77, 1.5,  90 *D2R, 0, 3;
    6.00, 7.17, 2.0, 180 *D2R, 0, 3;
    3.50, 7.17, 2.0, 180 *D2R, 0, 3;
    3.20, 4.97, 1.0, -30 *D2R, 2, 0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location: Left Hub
% Middle Location: Neutral Zone Loop Back
% Finish Location: Left Hub
Path_LH_NZ_LH = [
    3.20, 4.97, 1.0, -30 *D2R, 0, 0;    
    3.20, 7.20, 2.0,   0 *D2R, 0, 3;
    7.00, 7.31, 1.5, -60 *D2R, 0, 3;
    7.70, 4.77, 1.5, -90 *D2R, 0, 3;
    6.00, 4.77, 1.5,  90 *D2R, 0, 3;
    6.00, 7.17, 2.0, 180 *D2R, 0, 3;
    3.50, 7.17, 2.0, 180 *D2R, 0, 3;
    3.20, 4.97, 1.0, -30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location: Right Trench
% Middle Location: Neutral Zone Loop Back
% Finish Location: Right Hub
Path_RT_NZ_RH = MirrorPathSameSide(Path_LT_NZ_LH,field_width);
Path_RT_NZ_RH(1,4) =   0 *D2R;
Path_RT_NZ_RH(2,4) =  60 *D2R;
Path_RT_NZ_RH(3,4) =  90 *D2R;
Path_RT_NZ_RH(4,4) = -90 *D2R;
Path_RT_NZ_RH(5,4) = 180 *D2R;
Path_RT_NZ_RH(6,4) = 180 *D2R;
Path_RT_NZ_RH(7,4) =  30 *D2R;

% Start Location: Right Hub
% Middle Location: Neutral Zone Loop Back
% Finish Location: Right Hub
Path_RH_NZ_RH = MirrorPathSameSide(Path_LH_NZ_LH,field_width);
Path_RH_NZ_RH(1,4) =  30 *D2R;
Path_RH_NZ_RH(2,4) =   0 *D2R;
Path_RH_NZ_RH(3,4) =  60 *D2R;
Path_RH_NZ_RH(4,4) =  90 *D2R;
Path_RH_NZ_RH(5,4) = -90 *D2R;
Path_RH_NZ_RH(6,4) = 180 *D2R;
Path_RH_NZ_RH(7,4) = 180 *D2R;
Path_RH_NZ_RH(8,4) =  30 *D2R;

% Start Location: Right Trench
% Finish Location: Outpost
Path_RT_OP = [
    3.51, 0.62, 1.5, 180 *D2R, 0, 0;
    0.75, 0.73, 1.0, 180 *D2R, 0, 3;
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
    0.75, 0.73, 1.5, 180 *D2R, 0, 0;
    1.30, 1.30, 1.5, 180 *D2R, 0, 3;
    3.10, 3.90, 1.0, 0   *D2R, 2, 0;
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
    3.75, 5.90, 1.5, 180 *D2R, 0, 0;
    0.71, 5.97, 1.0, 180 *D2R, 0, 3;
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
    0.71, 5.97, 1.5, 180 *D2R, 0, 0;
    1.35, 5.97, 1.5, 180 *D2R, 0, 3;
    3.10, 3.90, 1.0, 0   *D2R, 2, 0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

% Start Location: Depot
% Finish Location: Outpost
Path_DP_OP = [
    0.71, 5.97, 1.5, 180 *D2R, 0, 0;
    2.50, 4.50, 1.5, -90 *D2R, 0, 3;
    2.50, 1.50, 1.5, 180 *D2R, 0, 3;
    0.75, 0.73, 1.0, 180 *D2R, 0, 3;    
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
    Path_RT_NZ_LH, ...   % 2
    Path_LH_NZ_RH, ...   % 3
    Path_RH_NZ_LH, ...   % 4  
    Path_LT_NZ_LH, ...   % 5
    Path_LH_NZ_LH, ...   % 6  
    Path_RT_NZ_RH, ...   % 7
    Path_RH_NZ_RH, ...   % 8
    Path_RT_OP, ...      % 9
    Path_OP_RH, ...      % 10
    Path_LR_DP, ...      % 11
    Path_DP_LH, ...      % 12
    Path_DP_OP ...       % 13
  ); 

% Run this function to mirron paths from blue to red sides of the field
% Path_1_Red = MirrorPath(Path_1_Blue, field_width, field_length);

All_Paths_Ref_Poses_Red = cat(3, ...
    MirrorPath(Path_LT_NZ_RH, field_width, field_length), ...   % 1
    MirrorPath(Path_RT_NZ_LH, field_width, field_length), ...   % 2
    MirrorPath(Path_LH_NZ_RH, field_width, field_length), ...   % 3
    MirrorPath(Path_RH_NZ_LH, field_width, field_length), ...   % 4  
    MirrorPath(Path_LT_NZ_LH, field_width, field_length), ...   % 5
    MirrorPath(Path_LH_NZ_LH, field_width, field_length), ...   % 6   
    MirrorPath(Path_RT_NZ_RH, field_width, field_length), ...   % 7
    MirrorPath(Path_RH_NZ_RH, field_width, field_length), ...   % 8     
    MirrorPath(Path_RT_OP, field_width, field_length), ...      % 9
    MirrorPath(Path_OP_RH, field_width, field_length), ...      % 10
    MirrorPath(Path_LR_DP, field_width, field_length), ...      % 11
    MirrorPath(Path_DP_LH, field_width, field_length), ...      % 12
    MirrorPath(Path_DP_OP, field_width, field_length) ...       % 13
  ); 

clear field_width field_length

% collect the number of poses in each path
All_Paths_Num_Poses = [
    nnz(Path_LT_NZ_RH(:,1));    % 1
    nnz(Path_RT_NZ_LH(:,1));    % 2
    nnz(Path_LH_NZ_RH(:,1));    % 3
    nnz(Path_RH_NZ_LH(:,1));    % 4  
    nnz(Path_LT_NZ_LH(:,1));    % 5
    nnz(Path_LH_NZ_LH(:,1));    % 6    
    nnz(Path_RT_NZ_RH(:,1));    % 7
    nnz(Path_RH_NZ_RH(:,1));    % 8     
    nnz(Path_RT_OP(:,1));       % 9
    nnz(Path_OP_RH(:,1));       % 10
    nnz(Path_LR_DP(:,1));       % 11
    nnz(Path_DP_LH(:,1));       % 12
    nnz(Path_DP_OP(:,1));       % 13
    ];

clear Path_LT_NZ_RH Path_RT_NZ_LH Path_LH_NZ_RH Path_RH_NZ_LH Path_LT_NZ_LH
clear Path_LH_NZ_LH Path_RT_NZ_RH Path_RH_NZ_RH Path_RT_OP Path_OP_RH
clear Path_LR_DP Path_DP_LH Path_DP_OP

% Define complete auto paths (fill with zeros so all are the same length)
Auto_Path_01 = [1,4,0];
Auto_Path_02 = [2,3,0];
Auto_Path_03 = [5,6,0];
Auto_Path_04 = [7,8,0];
Auto_Path_05 = [9,10,0];
Auto_Path_06 = [11,12,0];
Auto_Path_07 = [11,13,10];


