
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width  = 317.69 * 0.0254;
field_length = 651.22 * 0.0254;

%Chooser

Auto_Path_Chooser = 3; % default chooser path sequence number
Auto_Deploy_Intake_Time = 1.0; % seconds (part 1 of auto)
Auto_Deploy_Intake_Time2 = 0;  % seconds (part 2 of auto)
Auto_Shoot_Time = 4.5;   % seconds
Auto_Intake_Arm_Cycle_Delay_Time = 2.0;  % seconds

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
% 4 = Startup delay to deploy intake - first path
% 5 = Startup delay to deploy intake - second path

%% Segment 1
% Start Location:  Left Trench
% Middle Location: Neutral Zone
% Finish Location: Right Hub
Segment_01 = [
    3.51, 7.45, 3.5,   0 *D2R, 4, 0;
    5.50, 7.45, 3.5,   0 *D2R, 4, 3;
    7.00, 7.31, 3.0, -60 *D2R, 0, 3;
    7.70, 4.77, 2.0, -90 *D2R, 0, 3;
    7.60, 2.00, 2.0, -90 *D2R, 0, 3;
    6.40, 0.70, 2.0,   0 *D2R, 0, 0;
    3.50, 0.70, 2.0,   0 *D2R, 0, 0;
    3.20, 3.10, 3.5,  30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 2
% Start Location:  Right Trench
% Middle Location: Neutral Zone
% Finish Location: Left Hub
Segment_02 = MirrorPathSameSide(Segment_01,field_width);
Segment_02(1,4) =   0 *D2R;
Segment_02(2,4) =   0 *D2R;
Segment_02(3,4) =  60 *D2R;
Segment_02(4,4) =  90 *D2R;
Segment_02(5,4) =  90 *D2R;
Segment_02(6,4) =   0 *D2R;
Segment_02(7,4) =   0 *D2R;
Segment_02(8,4) = -30 *D2R;

%% Segment 3
% Start Location:  Left Hub
% Middle Location: Neutral Zone Close to Hub
% Finish Location: Right Hub
Segment_03 = [
    3.20, 4.97, 3.5, -30 *D2R, 0, 0;
    3.20, 7.45, 2.0,   0 *D2R, 0, 0;
    6.00, 7.45, 2.0, -60 *D2R, 0, 3;
    6.30, 5.00, 2.0, -90 *D2R, 0, 3;
    6.30, 2.40, 2.0, -90 *D2R, 0, 3;
    6.30, 0.70, 2.0,   0 *D2R, 0, 0;
    3.50, 0.70, 2.0,   0 *D2R, 0, 0;
    3.20, 3.10, 3.5,  30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 4
% Start Location:  Right Hub
% Middle Location: Neutral Zone Close to Hub
% Finish Location: Left Hub
Segment_04 = MirrorPathSameSide(Segment_03,field_width);
Segment_04(1,4) =  30 *D2R;
Segment_04(2,4) =   0 *D2R;
Segment_04(3,4) =  60 *D2R;
Segment_04(4,4) =  90 *D2R;
Segment_04(5,4) =  90 *D2R;
Segment_04(6,4) =   0 *D2R;
Segment_04(7,4) =   0 *D2R;
Segment_04(8,4) = -30 *D2R;

%% Segment 5
% Start Location: Left Trench
% Middle Location: Neutral Zone Loop Back
% Finish Location: Left Hub
Segment_05 = [
    3.51, 7.35, 3.5,   0 *D2R, 4, 0;
    5.50, 7.35, 3.5,   0 *D2R, 0, 3;    
    7.50, 7.31, 3.0, -60 *D2R, 0, 3;
    7.70, 4.77, 2.0, -90 *D2R, 0, 3;
    6.50, 5.00, 2.0,  90 *D2R, 0, 3;
    6.00, 7.35, 2.0,   0 *D2R, 0, 3;
    3.50, 7.35, 2.0,   0 *D2R, 0, 3;
    3.20, 4.97, 3.5, -30 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 6
% Start Location: Left Hub
% Middle Location: Neutral Zone Loop Back
% Finish Location: Left Hub
Segment_06 = [
    3.20, 4.97, 3.5, -30 *D2R, 0, 0;  
    3.20, 7.35, 2.0,   0 *D2R, 0, 3;
    5.20, 7.35, 2.0,   0 *D2R, 0, 3;      
    7.50, 7.10, 2.0, -60 *D2R, 0, 3;
    7.70, 4.77, 2.0, -90 *D2R, 0, 3;
    6.50, 5.00, 2.0,  90 *D2R, 0, 3;
    6.00, 7.35, 2.0,   0 *D2R, 0, 3;
    3.50, 7.35, 2.0,   0 *D2R, 0, 3;
    3.20, 4.97, 3.5, -30 *D2R, 2, 0;
    0,0,0,0,0,0];

%% Segment 7
% Start Location: Right Trench
% Middle Location: Neutral Zone Loop Back
% Finish Location: Right Hub
Segment_07 = MirrorPathSameSide(Segment_05,field_width);
Segment_07(1,4) =   0 *D2R;
Segment_07(2,4) =   0 *D2R;
Segment_07(3,4) =  60 *D2R;
Segment_07(4,4) =  90 *D2R;
Segment_07(5,4) = -90 *D2R;
Segment_07(6,4) =   0 *D2R;
Segment_07(7,4) =   0 *D2R;
Segment_07(8,4) =  30 *D2R;


%% Segment 8
% Start Location: Right Hub
% Middle Location: Neutral Zone Loop Back
% Finish Location: Right Hub
Segment_08 = MirrorPathSameSide(Segment_06,field_width);
Segment_08(1,4) =  30 *D2R;
Segment_08(2,4) =   0 *D2R;
Segment_08(3,4) =   0 *D2R;
Segment_08(4,4) =  60 *D2R;
Segment_08(5,4) =  90 *D2R;
Segment_08(6,4) = -90 *D2R;
Segment_08(7,4) =   0 *D2R;
Segment_08(8,4) =   0 *D2R;
Segment_08(9,4) =  30 *D2R;

%% Segment 9
% Start Location: Right Ramp
% Finish Location: Outpost
Segment_09 = [
    3.51, 2.50, 2.0, -150 *D2R, 0, 0;
    2.50, 0.80, 2.0, 180 *D2R, 0, 3;
    0.75, 0.73, 2.0, 180 *D2R, 0, 3;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 10
% Start Location: Outpost
% Finish Location: Center Hub
Segment_10 = [
    0.75, 0.73, 2.0, 180 *D2R, 0, 0;
    1.30, 1.30, 2.0, 180 *D2R, 0, 3;
    2.90, 3.90, 2.0, 0   *D2R, 2, 0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 11
% Start Location: Left Ramp
% Finish Location: Depot
Segment_11 = [
    3.55, 3.95, 2.0, 180 *D2R, 0, 3;
    2.20, 5.90, 2.0, 180 *D2R, 0, 3;
    0.50, 5.97, 1.0, 180 *D2R, 0, 3;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 12
% Start Location: Depot
% Middle Location: Neutral Zone Loop Back
% Finish Location: Left Hub
Segment_12 = [
    0.71, 5.97, 2.0, 180 *D2R, 0, 0;
    1.50, 5.97, 2.0, 180 *D2R, 0, 0;
    2.20, 7.35, 1.0,   0 *D2R, 0, 3;
    5.50, 7.35, 3.5,   0 *D2R, 0, 3;    
    7.00, 7.31, 3.5, -60 *D2R, 0, 3;
    8.00, 4.50, 3.5, -120 *D2R, 0, 3;
    6.20, 4.50, 3.5, -255 *D2R, 0, 3;
    6.00, 7.35, 2.0, -360 *D2R, 0, 3;
    3.50, 7.35, 2.0, -360 *D2R, 0, 3;
    1.50, 4.97, 3.5, -390 *D2R, 2, 0];

%% Segment 13
% Start Location: Depot
% Finish Location: Outpost
Segment_13 = [
    0.71, 5.97, 2.0, 180 *D2R, 0, 0;
    2.00, 5.70, 2.0, 180 *D2R, 0, 0;
    2.50, 3.70, 2.0, 180 *D2R, 0, 0;
    2.50, 1.50, 2.0, 180 *D2R, 0, 3;
    0.75, 0.73, 2.0, 180 *D2R, 0, 3;    
    0,0,0,0,0,0; 
    0,0,0,0,0,0;
    0,0,0,0,0,0;     
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 14
% Start Location: Left Trench
% Middle Location: Neutral Zone to Ramp
% Finish Location: Left Hub
Segment_14 = [
    3.51, 7.35, 3.5,   0 *D2R, 4, 0;
    5.50, 7.35, 3.5,   0 *D2R, 0, 3;    
    7.50, 7.31, 3.5, -60 *D2R, 0, 3;
    7.90, 4.77, 3.5, -90 *D2R, 0, 3;
    6.50, 5.00, 3.5, -60 *D2R, 0, 3;
    5.50, 5.55, 3.0, -45 *D2R, 0, 3;
    2.50, 5.55, 3.0, -45 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 15
% Start Location: Left Hub
% Middle Location: Neutral Zone to Ramp to Neutral Zone
% Finish Location: Left Hub
Segment_15 = [
    2.50, 5.55,2.5, -135 *D2R, 0, 0;
    5.80, 5.7, 2.5, -135 *D2R, 0, 3;   
    6.00, 4.0, 2.0,  -90 *D2R, 0, 3;
    7.00, 4.0, 2.0,   90 *D2R, 0, 3;
    7.00, 5.5, 2.0,   90 *D2R, 0, 3;
    5.50, 5.55,2.5,  -45 *D2R, 0, 3;
    2.50, 5.55,2.5,  -45 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;    
    0,0,0,0,0,0];

%% Segment 16
% Start Location: Right Trench
% Middle Location: Neutral Zone to Ramp
% Finish Location: Right Hub
Segment_16 = MirrorPathSameSide(Segment_14,field_width);
Segment_16(1,4) =   0 *D2R;
Segment_16(2,4) =   0 *D2R;
Segment_16(3,4) =  60 *D2R;
Segment_16(4,4) =  90 *D2R;
Segment_16(5,4) =  60 *D2R;
Segment_16(6,4) =  45 *D2R;
Segment_16(7,4) =  45 *D2R;

%% Segment 17
% Start Location: Right Hub
% Middle Location: Neutral Zone to Ramp to Neutral Zone
% Finish Location: Right Hub
Segment_17 = MirrorPathSameSide(Segment_15,field_width);
Segment_17(1,4) = 135 *D2R;
Segment_17(2,4) = 135 *D2R;
Segment_17(3,4) =  90 *D2R;
Segment_17(4,4) = -90 *D2R;
Segment_17(5,4) = -90 *D2R;
Segment_17(6,4) =  45 *D2R;
Segment_17(7,4) =  45 *D2R;

%% Segment 18
% Start Location: Left Trench
% Middle Location: Neutral Zone Loop Back
% Finish Location: Left Trench
Segment_18 = [
    3.51, 7.35, 3.5,   0 *D2R, 4, 0;
    5.50, 7.35, 3.5,   0 *D2R, 0, 3;    
    7.50, 7.31, 3.0, -60 *D2R, 0, 3;
    7.70, 4.77, 2.0, -90 *D2R, 0, 3;
    6.50, 5.00, 2.0,  90 *D2R, 0, 3;
    6.00, 7.35, 2.0,   0 *D2R, 0, 3;
    3.00, 7.20, 2.0,   0 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 19
% Start Location: Right Trench
% Middle Location: Neutral Zone Loop Back
% Finish Location: Right Trench
Segment_19 = MirrorPathSameSide(Segment_18,field_width);
Segment_19(1,4) =   0 *D2R;
Segment_19(2,4) =   0 *D2R;
Segment_19(3,4) =  60 *D2R;
Segment_19(4,4) =  90 *D2R;
Segment_19(5,4) = -90 *D2R;
Segment_19(6,4) =   0 *D2R;
Segment_19(7,4) =   0 *D2R;

%% Segment 20
% Start Location: Left Hub to Left Trench
% Middle Location: Neutral Zone Over Ramp
% Finish Location: Left Hub
Segment_20 = [
    2.50, 5.55, 3.5, -45 *D2R, 0, 0;    
    2.50, 7.35, 2.5,   0 *D2R, 0, 3;
    5.00, 7.35, 2.5,   0 *D2R, 0, 3;    
    6.50, 7.31, 3.5, -90 *D2R, 0, 3;
    6.50, 5.70, 3.5, -60 *D2R, 0, 3;
    5.50, 5.55, 3.0, -45 *D2R, 0, 3;
    2.50, 5.55, 3.0, -45 *D2R, 2, 0;   
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 21
% Start Location: Left Hub to Left Trench
% Middle Location: Neutral Zone Over Ramp
% Finish Location: Left Hub
Segment_21 = MirrorPathSameSide(Segment_20,field_width);
Segment_21(1,4) = 45 *D2R;
Segment_21(2,4) =  0 *D2R;
Segment_21(3,4) =  0 *D2R;
Segment_21(4,4) = 90 *D2R;
Segment_21(5,4) = 60 *D2R;
Segment_21(6,4) = 45 *D2R;
Segment_21(7,4) = 45 *D2R;

%% Segment 22
% Start Location: Left Trench
% Middle Location: Neutral Zone Loop Back
% Finish Location: Left Trench
Segment_22 = [
    3.51, 7.35, 3.5,   0 *D2R, 4, 0;
    5.50, 7.35, 3.5,   0 *D2R, 0, 3;    
    7.50, 7.31, 3.0, -60 *D2R, 0, 3;
    7.70, 4.77, 2.0, -90 *D2R, 0, 3;
    6.50, 5.00, 2.0,  90 *D2R, 0, 3;
    6.00, 7.35, 2.0,   0 *D2R, 0, 3;
    3.00, 7.20, 2.0,   0 *D2R, 2, 0;
    0,0,0,0,0,0;
    0,0,0,0,0,0;
    0,0,0,0,0,0];

%% Segment 23
% Start Location: Right Trench
% Middle Location: Neutral Zone Loop Back
% Finish Location: Right Trench
Segment_23 = MirrorPathSameSide(Segment_22,field_width);
Segment_23(1,4) =   0 *D2R;
Segment_23(2,4) =   0 *D2R;
Segment_23(3,4) =  60 *D2R;
Segment_23(4,4) =  90 *D2R;
Segment_23(5,4) = -90 *D2R;
Segment_23(6,4) =   0 *D2R;
Segment_23(7,4) =   0 *D2R;

clear D2R

% concatenate all of the paths into one multi-dimensional matrix
All_Paths_Ref_Poses_Blue = cat(3, ...
    Segment_01, ...
    Segment_02, ...
    Segment_03, ...
    Segment_04, ...
    Segment_05, ...
    Segment_06, ...
    Segment_07, ...
    Segment_08, ...
    Segment_09, ...
    Segment_10, ...
    Segment_11, ...
    Segment_12, ...
    Segment_13, ...
    Segment_14, ...
    Segment_15, ...
    Segment_16, ...
    Segment_17, ...  
    Segment_18, ...
    Segment_19, ...  
    Segment_20, ...
    Segment_21, ...
    Segment_22, ...
    Segment_23 ...
  ); 

% Run this function to mirron paths from blue to red sides of the field
% Path_1_Red = MirrorPath(Path_1_Blue, field_width, field_length);

All_Paths_Ref_Poses_Red = cat(3, ...
    MirrorPath(Segment_01, field_width, field_length), ...
    MirrorPath(Segment_02, field_width, field_length), ...
    MirrorPath(Segment_03, field_width, field_length), ...
    MirrorPath(Segment_04, field_width, field_length), ...
    MirrorPath(Segment_05, field_width, field_length), ...
    MirrorPath(Segment_06, field_width, field_length), ...
    MirrorPath(Segment_07, field_width, field_length), ...
    MirrorPath(Segment_08, field_width, field_length), ... 
    MirrorPath(Segment_09, field_width, field_length), ...
    MirrorPath(Segment_10, field_width, field_length), ...
    MirrorPath(Segment_11, field_width, field_length), ...
    MirrorPath(Segment_12, field_width, field_length), ...
    MirrorPath(Segment_13, field_width, field_length), ...
    MirrorPath(Segment_14, field_width, field_length), ...
    MirrorPath(Segment_15, field_width, field_length), ...
    MirrorPath(Segment_16, field_width, field_length), ...
    MirrorPath(Segment_17, field_width, field_length), ...
    MirrorPath(Segment_18, field_width, field_length), ...
    MirrorPath(Segment_19, field_width, field_length), ...
    MirrorPath(Segment_20, field_width, field_length), ...
    MirrorPath(Segment_21, field_width, field_length), ...
    MirrorPath(Segment_22, field_width, field_length), ...
    MirrorPath(Segment_23, field_width, field_length) ...
  ); 

clear field_width field_length

% collect the number of poses in each path
All_Paths_Num_Poses = [
    nnz(Segment_01(:,1));
    nnz(Segment_02(:,1));
    nnz(Segment_03(:,1));
    nnz(Segment_04(:,1));
    nnz(Segment_05(:,1));
    nnz(Segment_06(:,1));
    nnz(Segment_07(:,1));
    nnz(Segment_08(:,1));
    nnz(Segment_09(:,1));
    nnz(Segment_10(:,1));
    nnz(Segment_11(:,1));
    nnz(Segment_12(:,1));
    nnz(Segment_13(:,1));
    nnz(Segment_14(:,1));
    nnz(Segment_15(:,1));
    nnz(Segment_16(:,1));
    nnz(Segment_17(:,1));
    nnz(Segment_18(:,1));
    nnz(Segment_19(:,1));
    nnz(Segment_20(:,1));
    nnz(Segment_21(:,1));
    nnz(Segment_22(:,1));
    nnz(Segment_23(:,1));      
    ];

clear Segment_01 Segment_02 Segment_03 Segment_04 Segment_05
clear Segment_06 Segment_07 Segment_08 Segment_09 Segment_10
clear Segment_11 Segment_12 Segment_13 Segment_14 Segment_15 
clear Segment_16 Segment_17 Segment_18 Segment_19 Segment_20
clear Segment_21 Segment_22 Segment_23

% Define complete auto paths (fill with zeros so all are the same length)
Auto_Path_01 = [1,4,0];     % Chooser 1 Left  (using the full field)
Auto_Path_02 = [2,3,0];     % Chooser 1 Right (using the full field)
Auto_Path_03 = [5,6,0];     % Chooser 2 Left  (similar to CIR)
Auto_Path_04 = [7,8,0];     % Chooser 2 Right (similar to CIR)
Auto_Path_05 = [14,15,0];   % Chooser 3 Left  (trench start then ramp only)
Auto_Path_06 = [16,17,0];   % Chooser 3 Right (trench start then ramp only)
Auto_Path_07 = [18,22,0];   % Chooser 4 Left  (long shot)
Auto_Path_08 = [19,23,0];   % Chooser 4 Right (long shot)
Auto_Path_09 = [14,20,0];   % Chooser 5 Left  (Kansas City practice day)
Auto_Path_10 = [16,21,0];   % Chooser 5 Right (Kansas City practice day)
Auto_Path_11 = [11,12,0];   % Chooser 6 Center Hub-Depot-Trench-Trench-Hub
Auto_Path_12 = [9,10,0];    % Chooser 7 Right Ramp-Outpost-Hub
Auto_Path_13 = [11,13,10];  % CHooser 8 Left  Ramp-Depot-Outpost-Hub
