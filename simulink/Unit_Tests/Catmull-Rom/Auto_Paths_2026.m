
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width  = 317.69 * 0.0254;
field_length = 651.22 * 0.0254;

% [x, y, velocity, angle, Action during path]
%     Column 5 action defined in the current row is the action taken
%     between the current row point and the next row point if 
%     next row point is not the last point in the list.
%
%     Column 5 action defined in the current row is the action taken
%     at the end of path if the point is the last point in the list.
%
% Legend for column 5
% 0 = Travel only
% 1 = Shooting
% 2 = Gather fuel floor
% 3 = Gather Fuel Depot
% 4 = Gather Fuel Human(outpost) 
% 5 = Climb


% Start Location: Left Start
% Finish Location: Depot
Path_1 = [
    3.75, 5.9,  1, 180 *D2R, 2;
    0.71, 5.97, 1, 180 *D2R, 3;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

% Start Location: Depot 
% Finish Location: Left Shoot
Path_2 = [
    0.71, 5.97, 1, 180 *D2R, 0;
    1.35, 5.97, 1, 180 *D2R, 2;
    2.80, 5.35, 1, -50 *D2R, 1;
   0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];
% Start Location: Left Shoot
% Finish Location: Climb Middle
Path_3 = [
    2.80, 5.35, 1, -50 *D2R, 0;
    2.30, 3.79, 1, -90 *D2R, 0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

% Start Location: Left trench Start
% Finish Location: Human
Path_4 = [
    3.51, 0.62, 1, 180 *D2R, 2;
    0.75, 0.73, 1, 180 *D2R, 4;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

% Start Location: Human
% Finish Location: Right Shoot 
Path_5 = [
    0.75, 0.73, 1, 180 *D2R, 0;
    1.83, 1.87, 1, 45  *D2R, 2;
    2.80, 2.68, 1, 50  *D2R, 1;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

% Start Location: Right Shoot
% Finish Location: Climb Middle
Path_6 = [
    2.80, 2.68, 1,  50 *D2R, 0;
    2.30, 3.79, 1, -90 *D2R, 0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];


% Start Location: Start Left Trench
% Finish Location: Left Neutral
Path_7 = [
    3.51, 7.11, 1,   0 *D2R, 2;
    7.00, 7.31, 1, -90 *D2R, 2;
    7.50, 4.77, 1, -90 *D2R, 2;
  0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];
% Start Location: Left Neutral
% Finish Location: Right Shoot
Path_8 = [
    7.5, 4.77,  1,  -90 *D2R, 2;
    7.09, 3.15, 1,  -22 *D2R, 0;
    5.26, 2.4,  1,   45 *D2R, 0;
    3.78, 2.4,  0.5, 45 *D2R, 0;
    2.80, 2.68, 0.5, 50 *D2R, 1;
     0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

% Start Location: Right Trench
% Finish Location: Right Neutral
Path_9 = [
    3.51, 0.62, 1, 0  *D2R, 2;
    7,    0.7,  1, 90 *D2R, 2;
    7.5,  3.38, 1, 90 *D2R, 2;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

% Start Location: Right Neutral 
% Finish Location: Left Shoot 
Path_10 = [
    7.5,  3.38, 1,  90 *D2R, 0;
    7.00, 5.00, 1,  22 *D2R, 0;
    5.43, 5.55, 1, -45 *D2R, 0;
    3.78, 5.56, 1, -45 *D2R, 0;
    2.80, 5.35, 1, -50 *D2R, 1;
     0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

% Start Location: Left Shoot
% Finish Location: Climb Middle
Path_11 = [
    2.80, 5.35, 1, -50 *D2R, 0;
    2.30, 3.79, 1, -90 *D2R, 0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

% Start Location: climb middle
% Finish Location: climb right/bottom side 
Path_12 = [
    2.30, 3.79, 1, -90 *D2R, 0;
    2.15, 3.30, 1, -90 *D2R, 0;
    1.53, 3.16, 1, -90 *D2R, 5;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];


%start location climb middle
%end location climb left/top side
Path_13 = [
    2.30, 3.79, 1, -90 *D2R, 0;
    2.15, 4.10, 1, -90 *D2R, 0;
    1.53, 4.35, 1, -90 *D2R, 5;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

%start location:depot
%End location: Shoot depot side
% reverse of path 5
Path_14 =[
    2.80, 2.68, 1, 50  *D2R, 1;
    1.83, 1.87, 1, 45  *D2R, 2;
    0.75, 0.73, 1, 180 *D2R, 0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];

%Start location:shoot left
%End location depot
%reverse of path 2
Path_15 =[
    2.80, 5.35, 1, -50  *D2R, 1;
    1.35, 5.97, 1,  180 *D2R, 2;
    0.71, 5.97, 1,  180 *D2R, 0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0;
    0,0,0,0,0];


% Run this function to mirron paths from blue to red sides of the field
% Path_1_Red = MirrorPath(Path_1, field_width, field_length);

% concatenate all of the paths into one multi-dimensional matrix
All_Paths_Ref_Poses = cat(3, ...
    Path_1(:,1:4), ...
    Path_2(:,1:4), ...
    Path_3(:,1:4), ...
    Path_4(:,1:4), ...
    Path_5(:,1:4), ...
    Path_6(:,1:4), ...
    Path_7(:,1:4), ...
    Path_8(:,1:4), ...
    Path_9(:,1:4), ...
    Path_10(:,1:4), ...
    Path_11(:,1:4), ...
    Path_12(:,1:4), ...
    Path_13(:,1:4), ...
    Path_14(:,1:4), ...
    Path_15(:,1:4) ...
    );
   
% collect the number of poses in each path
All_Paths_Num_Poses = [
    nnz(Path_1(:,1));
    nnz(Path_2(:,1));
    nnz(Path_3(:,1));
    nnz(Path_4(:,1));
    nnz(Path_5(:,1));
    nnz(Path_6(:,1));
    nnz(Path_7(:,1));
    nnz(Path_8(:,1));
    nnz(Path_9(:,1));
    nnz(Path_10(:,1));
    nnz(Path_11(:,1));
    nnz(Path_12(:,1));
    nnz(Path_13(:,1));
    nnz(Path_14(:,1));
    nnz(Path_15(:,1));
    ];

clear D2R field_width field_length