
D2R = pi/180;

% Field Size 317 in. x 691 in.
field_width  = 317.69 * 0.0254;
field_length = 651.22 * 0.0254;

% [x, y, velocity, angle]

% Start Location:
% Finish Location:
Path_1 = [
    3.75, 5.97, 1, 180.00 *D2R;
    0.71, 5.97, 1, 180.00 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Start Location:
% Finish Location:
Path_2 = [
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

% Start Location:
% Finish Location:
Path_3 = [
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

% Start Location:
% Finish Location:
Path_4 = [
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

% Start Location:
% Finish Location:
Path_5 = [
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


% Start Location:
% Finish Location:
Path_6 = [
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

% Start Location:
% Finish Location:
Path_7 = [
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

% Start Location:
% Finish Location:
Path_8 = [
    7.77, 5.77, 1, -104.35 *D2R;
    7.09, 3.09, 1, -125.46 *D2R;
    4.37, 2.19, 1, -170.00 *D2R;
    2.67, 2.68, 1, 88.85 *D2R;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0;
    0,0,0,0];

% Start Location:
% Finish Location:
Path_9 = [
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

% Start Location:
% Finish Location:
Path_10 = [
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

% Start Location:
% Finish Location:
Path_11 = [
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

% Start Location:
% Finish Location:
Path_12 = [
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

% Run this function to mirron paths from blue to red sides of the field
% Path_1_Red = MirrorPath(Path_1, field_width, field_length);

% concatenate all of the paths into one multi-dimensional matrix
All_Paths_Ref_Poses = cat(3, ...
    Path_1, ...
    Path_2, ...
    Path_3, ...
    Path_4, ...
    Path_5, ...
    Path_6, ...
    Path_7, ...
    Path_8, ...
    Path_9, ...
    Path_10, ...
    Path_11, ...
    Path_12 ...
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
    ];

clear D2R field_width field_length