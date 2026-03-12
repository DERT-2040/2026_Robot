% All boundaries are in meters
% All time limits are in seconds

% Field dimensions
field_width = 317.69 * 0.0254;
field_length = 691.22 * 0.0254;

blue_trench_x = 4.619;
red_trench_x = MirrorPoint(blue_trench_x, field_length, field_width, true);

% Warning Threshold for Lower Blue Trench
Blue_Warning_Trench_AZ_Max_X = 3.279;
Blue_Warning_Trench_AZ_Min_X = 2.581;
Blue_Warning_Trench_NZ_Max_X = MirrorPointTrench(Blue_Warning_Trench_AZ_Max_X, red_trench_x, blue_trench_x, true);
Blue_Warning_Trench_NZ_Min_X = MirrorPointTrench(Blue_Warning_Trench_AZ_Min_X, red_trench_x, blue_trench_x, true);
Lower_Trench_Max_Y = 1.266;
Lower_Trench_Min_Y = 0;
Warning_Trench_Time = .5; 

% Approaching Threshold for Lower Blue Trench
Blue_Approaching_Trench_AZ_Max_X = 3.978; 
Blue_Approaching_Trench_AZ_Min_X = Blue_Warning_Trench_AZ_Max_X;
Blue_Approaching_Trench_NZ_Max_X = MirrorPointTrench(Blue_Approaching_Trench_AZ_Max_X, red_trench_x, blue_trench_x, true);
Blue_Approaching_Trench_NZ_Min_X = MirrorPointTrench(Blue_Approaching_Trench_AZ_Min_X, red_trench_x, blue_trench_x, true);
Approaching_Trench_Time = .25; 

% Final Threshold for Lower Blue Trench
Blue_Final_Trench_Max_X = 5.260;
Blue_Final_Trench_Min_X = Blue_Approaching_Trench_AZ_Max_X;
Final_Trench_Time = .2; 

% Higher Blue Trench
Higher_Trench_Min_Y = MirrorPoint(Lower_Trench_Max_Y, field_length, field_width, false);
Higher_Trench_Max_Y = MirrorPoint(Lower_Trench_Min_Y, field_length, field_width, false);


% Warning Threshold for Lower Red Trench
Red_Warning_Trench_AZ_Max_X = MirrorPoint(Blue_Warning_Trench_AZ_Max_X, field_length, field_width, true);
MirrorPoint(Blue_Warning_Trench_AZ_Max_X, field_length, field_width, true)
Red_Warning_Trench_AZ_Min_X = MirrorPoint(Blue_Warning_Trench_AZ_Min_X, field_length, field_width, true);
Red_Warning_Trench_NZ_Max_X = MirrorPoint(Blue_Warning_Trench_NZ_Max_X, field_length, field_width, true);
MirrorPoint(Blue_Warning_Trench_NZ_Max_X, field_length, field_width, true)
Red_Warning_Trench_NZ_Min_X = MirrorPoint(Blue_Warning_Trench_NZ_Min_X, field_length, field_width, true);

% Approaching Threshold for Lower Red Trench
Red_Approaching_Trench_AZ_Max_X = MirrorPoint(Blue_Approaching_Trench_AZ_Max_X, field_length, field_width, true);
MirrorPoint(Blue_Approaching_Trench_AZ_Max_X, field_length, field_width, true)
Red_Approaching_Trench_AZ_Min_X = Red_Warning_Trench_AZ_Max_X;
Red_Approaching_Trench_NZ_Max_X = MirrorPoint(Blue_Approaching_Trench_NZ_Max_X, field_length, field_width, true);
MirrorPoint(Blue_Approaching_Trench_NZ_Max_X, field_length, field_width, true)
Red_Approach_Trench_NZ_Min_X = MirrorPoint(Blue_Approaching_Trench_NZ_Min_X, field_length, field_width, true);

% Final Threshold for Lower Red Trench
Red_Final_Trench_Max_X = MirrorPoint(Blue_Final_Trench_Max_X, field_length, field_width, true);
Red_Final_Trench_Min_X = Red_Approaching_Trench_AZ_Max_X;

% Warning Threshold for Lower Blue Ramp
Blue_Warning_Ramp_AZ_Max_X = 3;
Blue_Warning_Ramp_AZ_Min_X = 2.5;
Blue_Warning_Ramp_NZ_Max_X = MirrorPointTrench(Blue_Warning_Ramp_AZ_Max_X, red_trench_x, blue_trench_x, true);
Blue_Warning_Ramp_NZ_Min_X = MirrorPointTrench(Blue_Warning_Ramp_AZ_Min_X, red_trench_x, blue_trench_x, true);
Lower_Ramp_Max_Y = 4.03;
Lower_Ramp_Min_Y = Lower_Trench_Max_Y;
Warning_Ramp_Time = .2; 

% Approaching Threshold for Lower Blue Ramp
Blue_Approaching_Ramp_AZ_Max_X = 3.5; 
Blue_Approaching_Ramp_AZ_Min_X = Blue_Warning_Ramp_AZ_Max_X;
Blue_Approaching_Ramp_NZ_Max_X = MirrorPointTrench(Blue_Approaching_Ramp_AZ_Max_X, red_trench_x, blue_trench_x, true);
Blue_Approaching_Ramp_NZ_Min_X = MirrorPointTrench(Blue_Approaching_Ramp_AZ_Min_X, red_trench_x, blue_trench_x, true);
Approaching_Ramp_Time = .15; 

% Final Threshold for Lwr Blue Ramp
Blue_Final_Ramp_Max_X = 5.5;
Blue_Final_Ramp_Min_X = Blue_Approaching_Ramp_AZ_Max_X;
Final_Ramp_Time = .1; 

% Warning Threshold for Higher Blue Ramp
Higher_Ramp_Max_Y = MirrorPoint(Lower_Ramp_Min_Y, field_length, field_width, false);
Higher_Ramp_Min_Y = MirrorPoint(Lower_Ramp_Max_Y, field_length, field_width, false);

% Warning Threshold for Lower Red Ramp
Red_Warning_Ramp_AZ_Max_X = MirrorPoint(Blue_Warning_Ramp_AZ_Max_X, field_length, field_width, true);
MirrorPoint(Blue_Warning_Ramp_AZ_Max_X, field_length, field_width, true)
Red_Warning_Ramp_AZ_Min_X = MirrorPoint(Blue_Warning_Ramp_AZ_Min_X, field_length, field_width, true);

Red_Warning_Ramp_NZ_Max_X = MirrorPoint(Blue_Warning_Ramp_NZ_Max_X, field_length, field_width, true);
MirrorPoint(Blue_Warning_Ramp_NZ_Max_X, field_length, field_width, true)
Red_Warning_Ramp_NZ_Min_X = MirrorPoint(Blue_Warning_Ramp_NZ_Min_X, field_length, field_width, true);

% Approaching Threshold for Lower Red Ramp
Red_Approaching_Ramp_AZ_Max_X = MirrorPoint(Blue_Approaching_Ramp_AZ_Max_X, field_length, field_width, true);%14.056988
MirrorPoint(Blue_Approaching_Ramp_AZ_Max_X, field_length, field_width, true)
Red_Approaching_Ramp_AZ_Min_X = Red_Warning_Ramp_AZ_Max_X;

Red_Approaching_Ramp_NZ_Max_X = MirrorPoint(Blue_Approaching_Ramp_NZ_Max_X, field_length, field_width, true);
MirrorPoint(Blue_Approaching_Ramp_NZ_Max_X, field_length, field_width, true)
Red_Approach_Ramp_NZ_Min_X = MirrorPoint(Blue_Approaching_Ramp_NZ_Min_X, field_length, field_width, true);

% Final Threshold for Lower Red Ramp
Red_Final_Ramp_Max_X = MirrorPoint(Blue_Final_Ramp_Max_X, field_length, field_width, true);%12.056988
Red_Final_Ramp_Min_X = Red_Approaching_Ramp_AZ_Max_X;%14.056988
