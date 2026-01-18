addpath Resources

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% THIS IS WHERE TO SET THE START AND END POINTS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
start_xy = [2.5 4];
end_xy = [15 4.9];

MapCreation;

points = {...
           {0,  1,  1};
           {5,  4,  2};
           {10, 7,  3};
           {15, 10, 4};
           {20, 13, 5};
           {25, 16, 6}
         };


fig = uifigure('Name', 'Path Planning Display',...
               'Position',[75 300 1000 500],...
               'Visible','off');

TopGL = uigridlayout(fig,[3 2]);
TopGL.ColumnWidth = {'10x', '3x'}; TopGL.RowHeight = {'2x','15x','1x'};
TopGL.ColumnSpacing = 5;

RightGL = uigridlayout(TopGL, [3 1]);
RightGL.Layout.Row = [1 3]; RightGL.Layout.Column = 2;
RightGL.RowHeight = {'fit', '2x', '3x'};

ButtonArray = uigridlayout(RightGL, [3 2]);
ButtonArray.Layout.Row = 2; ButtonArray.Layout.Column = 1;

PlaybackControlsGL = uigridlayout(TopGL, [1,2]);
PlaybackControlsGL.Layout.Row = 3; PlaybackControlsGL.Layout.Column = 1;
PlaybackControlsGL.ColumnWidth = {'1x', '20x'};

% Left Side
Title = uipanel(TopGL, 'Title', "Motion Planning Debugger", ...
    'FontSize', 36, ...
    'BackgroundColor', '#F0F0F0', ...
    'BorderType','none', ...
    'BorderWidth', 0, ...
    'TitlePosition','centertop');
Title.Layout.Column = 1; Title.Layout.Row = 1;

PlaySpace = uiaxes(TopGL,'Visible','on', ...
    'Interactions', []);
axis(PlaySpace, 'equal');
PlaySpace.Layout.Column = 1; PlaySpace.Layout.Row = 2;
PlaySpace.XLim = [0, map_width];
PlaySpace.YLim = [0, map_height];

PlayPauseButton = uibutton(PlaybackControlsGL,'Visible','on');
PlayPauseButton.Layout.Column = 1; PlayPauseButton.Layout.Row = 1;

TimeScrubberSlider = uislider(PlaybackControlsGL,'Visible','on');
TimeScrubberSlider.Layout.Column = 2; TimeScrubberSlider.Layout.Row = 1;

% Right Side
MapButton = uibutton(ButtonArray, 'State','Visible','on', ...
    'Text','Map', ...
    'Icon', 'Map_Icon.png', ...
    'IconAlignment','top', ...
    'BackgroundColor','white');
MapButton.Layout.Row = 1; MapButton.Layout.Column = 1;

OccupencyButton = uibutton(ButtonArray, 'State','Visible','on', ...
    'Text','Occupency', ...
    'Icon', 'Occupency_Icon.png', ...
    'IconAlignment','top', ...
    'BackgroundColor','white');
OccupencyButton.Layout.Row = 1; OccupencyButton.Layout.Column = 2;

OccupencyCollisonButton = uibutton(ButtonArray, 'State','Visible','on', ...
    'Text','Collison', ...
    'Icon', 'Occupency_Collision_Icon.png', ...
    'IconAlignment','top', ...
    'BackgroundColor','white');
OccupencyCollisonButton.Layout.Row = 1; OccupencyCollisonButton.Layout.Column = 3;

NodeGraphButton = uibutton(ButtonArray, 'State','Visible','on', ...
    'Text','Node Graph', ...
    'Icon', 'Node_Graph_Icon.png', ...
    'IconAlignment','top', ...
    'BackgroundColor','white');
NodeGraphButton.Layout.Row = 2; NodeGraphButton.Layout.Column = 1;

GraphWeightsButton = uibutton(ButtonArray, 'State','Visible','on', ...
    'Text','Graph Weights', ...
    'Icon', 'Node_Graph_Weights_Icon.png', ...
    'IconAlignment','top', ...
    'BackgroundColor','white');
GraphWeightsButton.Layout.Row = 2; GraphWeightsButton.Layout.Column = 2;

PathButton = uibutton(ButtonArray, 'State','Visible','on', ...
    'Text','Path', ...
    'Icon', 'Node_Graph_Path_Icon.png', ...
    'IconAlignment','top', ...
    'BackgroundColor','white');
PathButton.Layout.Row = 2; PathButton.Layout.Column = 3;

AlgorithmDropdown = uidropdown(RightGL,'Visible','on');
AlgorithmDropdown.Layout.Row = 1; AlgorithmDropdown.Layout.Column = 1;

set(fig, 'Visible','on');
set(fig, 'WindowState','maximized');


show(map, Parent=PlaySpace);

for i = 2:size(Objects,2)
    obj = cell2mat(Objects(i));
    mapshow(PlaySpace, obj(:, 1), obj(:, 2), 'DisplayType','polygon');
end

hold(PlaySpace,"on");
plot(PlaySpace, path(:,2)/resolution, map_height-path(:,1)/resolution, 'Color', '#08E8DE', 'LineWidth', 2);
plot(PlaySpace, out(:,1),out(:,2), 'Color', ' #FF8C00', 'LineWidth', 2);

state = RobotState(1,1,0,0,0,0,1);
drawRobot(state, PlaySpace);





function state = RobotState(x,y,dx,dy,theta,dtheta, l)
    state.r = (l/2)*sqrt(2);
    state.x = x;
    state.y = y;
    state.dx = dx;
    state.dy = dy;
    state.theta = theta;
    state.dtheta = dtheta;
end

function drawRobot(state, ax)
    lin = linspace(0,2*pi, 40);
    plot(ax, state.x + state.r * cos(lin), state.y + state.r * sin(lin));
end