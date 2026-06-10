classdef DERT_2040_Path_Planner_App < handle
    % DERT_2040_Path_Planner_App
    % A MATLAB app skeleton for DERT 2040 path planning.
    %
    % This app manages waypoint position, velocity, and heading for path segments (multiple segments make up a complete path).
    %
    % Waypoints can be added by clicking on the field or inserted/deleted by using the table.
    % Waypoint position can be modified by dragged around the field using a mouse.
    % Waypoint heading can be modified by dragging the heading arrow using a mouse.
    % The app provides a rectangular robot representation with a configurable rotation pivot to help visualize the robot.
    % 
    % Segments (made up of multiple waypoints) can be added, deleted, saved to Matlab workspace, or loaded from Matlab workspace.
    %    Segments are saved to the Matlab workspace as a matrix with 10 rows and 6 columns (rows are padded with 0's as needed).
    %    Segments can only be loaded from the Matlab workspace if they contain 10 rows and 6 columns.
    % Segments can be shown or hidden using a check box (waypoints and robot rectangle).
    % Segments can be simulated to show the true path that the robot will attempt to follow on the field (dashed lines).
    %
    % The properties below this description may need to be adjusted each season
    % The function named 'drawFieldBackground' will need to be modified each season
    %
    % Initially created by Randy Anderson on June 6, 2026 with the help of GitHub Copilot followed by manual modification.

    % These properties may need to be adjusted for each season
    properties
        RobotLength = 1.1
        RobotWidth = 0.9
        RobotOffset_Length = -0.1
        RobotOffset_Width = 0;
        Field = struct('length', 16.541, 'width', 8.06933)
        SimulationCommand = 'out = sim(''Catmull_Rom_2026'');'
    end

    properties
        UIFigure matlab.ui.Figure
        UIAxes matlab.ui.control.UIAxes
        SegmentList matlab.ui.control.Table
        AddSegmentButton matlab.ui.control.Button
        DeleteSegmentButton matlab.ui.control.Button
        WaypointTable matlab.ui.control.Table
        RobotWidthField matlab.ui.control.NumericEditField
        RobotLengthField matlab.ui.control.NumericEditField
        PivotXField matlab.ui.control.NumericEditField
        PivotYField matlab.ui.control.NumericEditField
        AddWaypointButton matlab.ui.control.Button
        DeleteWaypointButton matlab.ui.control.Button
        ConfigToggleButton matlab.ui.control.Button
        ConfigPanel matlab.ui.container.Panel
        LoadButton matlab.ui.control.Button
        SaveButton matlab.ui.control.Button
        RunSimulationButton matlab.ui.control.Button
        StatusLabel matlab.ui.control.Label
    end

    properties
        Segments = struct('name', {}, 'waypoints', {}, 'color', {}, 'visible', {})
        SimulationPaths = struct('x', {}, 'y', {}, 'color', {})
        CurrentSegmentIndex = 0
        Robot = struct('width', 1.0, 'length', 1.0, 'pivotOffset', [0, 0])
        Settings = struct('gridOn', true, 'snapToGrid', false, 'displayHeadings', true)
        SelectedWaypoint = []
        SelectedRow = []
        InsertedWaypointRow = []
        HeadingAdjusting = false
        HeadingAdjustRow = []
        Mode = 'select'  % select, addWaypoint
        Dragging = false
        DraggedRow = []
        AxisImages = struct('background', [])
    end

    methods
        function app = DERT_2040_Path_Planner_App()
            app.createComponents();
            app.initializeData();
            app.updateSegmentList();
            app.updatePlot();
        end

        % This function will need to be modified each year to represent the specific field
        function drawFieldBackground(app)
            % FIELD DIMENSIONS
            in2m = 0.0254;

            fieldL = app.Field.length;          % Provided by your app (should be ~651.22*in2m)
            fieldW = 317.69 * in2m;             % Fixed width

            % CLEAR AXES
            cla(app.UIAxes);
            hold(app.UIAxes, 'on');

            % FIELD SURFACE
            patch(app.UIAxes, ...
                [0 fieldL fieldL 0], ...
                [0 0 fieldW fieldW], ...
                [0.255, 0.706, 0.361], ... % artificial turf green
                'FaceAlpha', 1.0, ...
                'EdgeColor', 'none', ...
                'HitTest', 'off', ...
                'PickableParts', 'none');

            % FIELD BORDER
            plot(app.UIAxes, [0 fieldL], [0 0], '-w', 'LineWidth', 4);
            plot(app.UIAxes, [0 fieldL], [fieldW fieldW], '-w', 'LineWidth', 4);
            plot(app.UIAxes, [0 0], [0 fieldW], '-w', 'LineWidth', 4);
            plot(app.UIAxes, [fieldL fieldL], [0 fieldW], '-w', 'LineWidth', 4);

            % CENTER LINE
            plot(app.UIAxes, [fieldL/2 fieldL/2], [0 fieldW], '--w', 'LineWidth', 2);

            % -----------------------------
            %  HUBS (2026 FRC – Blue + Red)
            % -----------------------------
            % Blue hub – exact 2026 coordinates (meters)
            blue_x1 = 3.97789;
            blue_y1 = 3.35382;
            blue_w  = 5.17169 - 3.97789;   % 1.1938 m
            blue_h  = 4.54762 - 3.35382;   % 1.1938 m

            rectangle(app.UIAxes, ...
                'Position', [blue_x1 blue_y1 blue_w blue_h], ...
                'EdgeColor', 'b', ...
                'LineWidth', 3, ...
                'Curvature', 0.15);

            % Red hub – mirrored across field length
            red_x1 = fieldL - 5.17169;     % mirror the right edge of blue hub
            red_y1 = blue_y1;
            red_w  = blue_w;
            red_h  = blue_h;

            rectangle(app.UIAxes, ...
                'Position', [red_x1 red_y1 red_w red_h], ...
                'EdgeColor', 'r', ...
                'LineWidth', 3, ...
                'Curvature', 0.15);

            % -----------------------------
            %  LEGACY HUB Y (used by trench)
            % -----------------------------
            % Keep this so your trench/bump math still works
            hub_y = (317.69 - 65.65 - 73) * in2m;

            % -----------------------------
            %  TRENCH + BUMP
            % -----------------------------
            trench_x_blue = 156.61 * in2m;
            trench_len    = 44.40 * in2m;
            bump_x_offset = 22.2 * in2m;

            % Blue trench
            plot(app.UIAxes, [trench_x_blue trench_x_blue+trench_len], [hub_y hub_y], 'b');
            plot(app.UIAxes, [trench_x_blue trench_x_blue+trench_len], [hub_y+73*in2m hub_y+73*in2m], 'b');
            plot(app.UIAxes, [trench_x_blue trench_x_blue+trench_len], [65.65*in2m 65.65*in2m], 'b');

            % Blue bump
            plot(app.UIAxes, [trench_x_blue+bump_x_offset trench_x_blue+bump_x_offset], ...
                [0 fieldW], 'b');

            % Red trench
            trench_x_red = (651.22 - 156.61) * in2m;
            plot(app.UIAxes, [trench_x_red trench_x_red - trench_len], [hub_y hub_y], 'r');
            plot(app.UIAxes, [trench_x_red trench_x_red - trench_len], [hub_y+73*in2m hub_y+73*in2m], 'r');
            plot(app.UIAxes, [trench_x_red trench_x_red - trench_len], [65.65*in2m 65.65*in2m], 'r');

            % Red bump
            plot(app.UIAxes, [trench_x_red - bump_x_offset trench_x_red - bump_x_offset], ...
                [0 fieldW], 'r');

            % -----------------------------
            %  CLIMBER
            % -----------------------------
            climb_w    = (40 + 3.510) * in2m;
            climb_half = 23.5 * in2m;

            % Blue climber
            cy_blue = (26.62 + 121.24) * in2m;
            plot(app.UIAxes, [climb_w climb_w], [cy_blue - climb_half, cy_blue + climb_half], 'b');
            plot(app.UIAxes, [0 climb_w], [cy_blue + climb_half, cy_blue + climb_half], 'b');
            plot(app.UIAxes, [0 climb_w], [cy_blue - climb_half, cy_blue - climb_half], 'b');

            % Red climber
            climb_x_red = (650.12 - 40 - 3.510) * in2m;
            cy_red      = (82.42 + 87.46) * in2m;
            plot(app.UIAxes, [climb_x_red climb_x_red], [cy_red - climb_half, cy_red + climb_half], 'r');
            plot(app.UIAxes, [650.12*in2m climb_x_red], [cy_red - climb_half, cy_red - climb_half], 'r');
            plot(app.UIAxes, [650.12*in2m climb_x_red], [cy_red + climb_half, cy_red + climb_half], 'r');

            % -----------------------------
            %  DEPOT
            % -----------------------------
            depot_half = 21 * in2m;

            % Blue depot
            dx_blue = 27 * in2m;
            dy_blue = (158.84 + 75.93) * in2m;
            plot(app.UIAxes, [dx_blue dx_blue], [dy_blue - depot_half, dy_blue + depot_half], 'b');
            plot(app.UIAxes, [0 dx_blue], [dy_blue + depot_half, dy_blue + depot_half], 'b');
            plot(app.UIAxes, [0 dx_blue], [dy_blue - depot_half, dy_blue - depot_half], 'b');

            % Red depot
            dx_red = (650.12 - 27) * in2m;
            dy_red = (158.84 - 75.93) * in2m;
            plot(app.UIAxes, [dx_red dx_red], [dy_red - depot_half, dy_red + depot_half], 'r');
            plot(app.UIAxes, [650.12*in2m dx_red], [dy_red + depot_half, dy_red + depot_half], 'r');
            plot(app.UIAxes, [650.12*in2m dx_red], [dy_red - depot_half, dy_red - depot_half], 'r');

            % -----------------------------
            %  HUMAN PLAYER STATIONS
            % -----------------------------
            plot(app.UIAxes, [0 0], [0 49.32*in2m], 'b', 'LineWidth', 3);
            plot(app.UIAxes, [650.12*in2m 650.12*in2m], ...
                [316.69*in2m 316.69*in2m - 49.32*in2m], 'r', 'LineWidth', 3);

            % AXIS LIMITS
            xlim(app.UIAxes, [0 fieldL]);
            ylim(app.UIAxes, [0 fieldW]);
            axis(app.UIAxes, 'equal');
        end

        function createComponents(app)
            % Main figure
            app.UIFigure = uifigure('Name', 'DERT 2040 Path Planner', 'Position', [100 100 1200 700]);

            % UI axes with background support
            app.UIAxes = uiaxes(app.UIFigure, 'Position', [380 50 800 620]);
            app.UIAxes.ButtonDownFcn = @(src, evt) app.handleCanvasClick(evt);
            % Figure-level motion/up callbacks for dragging
            app.UIFigure.WindowButtonMotionFcn = @(src, evt) app.handleMouseMotion(src, evt);
            app.UIFigure.WindowButtonUpFcn = @(src, evt) app.endDrag();
            app.UIAxes.PlotBoxAspectRatio = [1 1 1];
            app.UIAxes.XGrid = 'on';
            app.UIAxes.YGrid = 'on';
            app.UIAxes.NextPlot = 'add';
            xlabel(app.UIAxes, 'X (m)');
            ylabel(app.UIAxes, 'Y (m)');

            % Load/Save controls
            app.LoadButton = uibutton(app.UIFigure, 'Text', 'Load Segments', 'Position', [20 600 120 30], 'ButtonPushedFcn', @(src, evt) app.loadSegments());
            app.SaveButton = uibutton(app.UIFigure, 'Text', 'Save Segments', 'Position', [150 600 120 30], 'ButtonPushedFcn', @(src, evt) app.saveState());
            app.RunSimulationButton = uibutton(app.UIFigure, 'Text', 'Run Simulation to Show Generated Paths', 'Position', [20 380 250 30], 'ButtonPushedFcn', @(src, evt) app.runSimulation());

            % Segment controls
            app.AddSegmentButton = uibutton(app.UIFigure, 'Text', 'Add Segment', 'Position', [20 640 120 30], 'ButtonPushedFcn', @(src, evt) app.createNewSegment());
            app.DeleteSegmentButton = uibutton(app.UIFigure, 'Text', 'Delete Segment', 'Position', [150 640 120 30], 'ButtonPushedFcn', @(src, evt) app.deleteCurrentSegment());
            app.SegmentList = uitable(app.UIFigure, ...
                'Position', [20 420 350 160], ...
                'ColumnName', {'Show', 'Segment'}, ...
                'ColumnWidth', {60, 350}, ...
                'ColumnEditable', [true true], ...
                'ColumnFormat', {'logical', 'char'}, ...
                'RowName', [], ...
                'CellEditCallback', @(src, evt) app.segmentTableEdited(evt), ...
                'CellSelectionCallback', @(src, evt) app.segmentTableSelectionChanged(evt));
            
            % Robot configuration controls
            app.ConfigToggleButton = uibutton(app.UIFigure, 'Text', 'Robot Config', 'Position', [20 680 120 30], 'ButtonPushedFcn', @(src, evt) app.toggleConfigPanel());
            app.ConfigPanel = uipanel(app.UIFigure, 'Title', 'Robot Configuration', 'Position', [20 480 350 180], 'Visible', 'off');
            uilabel(app.ConfigPanel, 'Text', 'Robot Width (m)', 'Position', [10 130 100 20]);
            app.RobotWidthField = uieditfield(app.ConfigPanel, 'numeric', 'Position', [150 130 80 22], 'Limits', [0 Inf], 'ValueChangedFcn', @(src, evt) app.updateRobotProperties());
            uilabel(app.ConfigPanel, 'Text', 'Robot Length (m)', 'Position', [10 90 100 20]);
            app.RobotLengthField = uieditfield(app.ConfigPanel, 'numeric', 'Position', [150 90 80 22], 'Limits', [0 Inf], 'ValueChangedFcn', @(src, evt) app.updateRobotProperties());
            uilabel(app.ConfigPanel, 'Text', 'Center Offset X (m)', 'Position', [10 50 120 20]);
            app.PivotXField = uieditfield(app.ConfigPanel, 'numeric', 'Position', [150 50 80 22], 'Limits', [-5 5], 'ValueChangedFcn', @(src, evt) app.updateRobotProperties());
            uilabel(app.ConfigPanel, 'Text', 'Center Offset Y (m)', 'Position', [10 10 120 20]);
            app.PivotYField = uieditfield(app.ConfigPanel, 'numeric', 'Position', [150 10 80 22], 'Limits', [-5 5], 'ValueChangedFcn', @(src, evt) app.updateRobotProperties());

            % Mode buttons
            app.AddWaypointButton = uibutton(app.UIFigure, 'Text', 'Add Waypoint', 'Position', [20 310 120 30], 'ButtonPushedFcn', @(src, evt) app.addWaypointButtonPressed());
            app.DeleteWaypointButton = uibutton(app.UIFigure, 'Text', 'Delete Waypoint', 'Position', [150 310 120 30], 'ButtonPushedFcn', @(src, evt) app.deleteSelectedObject());

            % Waypoint table (editable) - hide ID column (row index used)
            app.WaypointTable = uitable(app.UIFigure, ...
                'Position', [20 30 350 250], ...
                'ColumnName', {'X', 'Y', 'Velocity', 'Heading', 'Static Action', 'Dynamic Action'}, ...
                'ColumnWidth', {70, 70, 70, 70, 70, 70}, ...
                'ColumnEditable', true, ...
                'ColumnFormat', {'numeric','numeric','numeric','numeric','numeric','numeric'}, ...
                'CellEditCallback', @(src, evt) app.tableEdited(evt), ...
                'CellSelectionCallback', @(src, evt) app.tableSelectionChanged(evt));

            % Status label
            app.StatusLabel = uilabel(app.UIFigure, 'Text', 'Mode: Select', 'Position', [20 280 350 20]);
        end

        function initializeData(app)
            app.Robot.length = app.RobotLength;
            app.Robot.width = app.RobotWidth;
            app.Robot.pivotOffset = [app.RobotOffset_Length, app.RobotOffset_Width];
            app.RobotLengthField.Value = app.Robot.length;
            app.RobotWidthField.Value = app.Robot.width;
            app.PivotXField.Value = app.Robot.pivotOffset(1);
            app.PivotYField.Value = app.Robot.pivotOffset(2);
            app.addDefaultSegment();
        end

        function addDefaultSegment(app)
            segment.name = 'Segment_01';
            segment.waypoints = table([], [], [], [], [], [], [], 'VariableNames', {'id','x','y','heading','velocity','actionStatic','actionDynamic'});
            segment.color = [1,1,1];
            segment.visible = true;
            app.Segments(1) = segment;
            app.CurrentSegmentIndex = 1;
        end

        function createNewSegment(app)
            newName = sprintf('Segment_%02d', numel(app.Segments)+1);
            segment.name = newName;
            segment.waypoints = table([], [], [], [], [], [], [], 'VariableNames', {'id','x','y','heading','velocity','actionStatic','actionDynamic'});
            for i = 1:numel(app.Segments)+1
                if i == 1
                    segment.color = [1,1,1]; % white for first segment
                elseif i == 2
                    segment.color = [0,0,0]; % black for second segment
                elseif i == 3
                    segment.color = [0.5,0.5,0.5]; % gray for third segment
                elseif i == 4
                    segment.color = [0.1,0.1,0.7]; % blue for fourth segment
                else
                    segment.color = rand(1,3); % random color for additional segments
                end
            end
            segment.visible = true;
            app.Segments(end+1) = segment;
            app.CurrentSegmentIndex = numel(app.Segments);
            app.SelectedRow = [];
            app.SelectedWaypoint = [];
            app.InsertedWaypointRow = [];
            app.Dragging = false;
            app.DraggedRow = [];
            app.Mode = 'select';
            app.updateSegmentList();
            app.updatePlot();
        end

        function deleteCurrentSegment(app)
            if numel(app.Segments) <= 1
                uialert(app.UIFigure, 'At least one segment must exist.', 'Cannot Delete');
                return;
            end
            app.Segments(app.CurrentSegmentIndex) = [];
            app.CurrentSegmentIndex = max(1, app.CurrentSegmentIndex-1);
            app.updateSegmentList();
            app.updatePlot();
        end

        function addWaypointButtonPressed(app)
            segment = app.Segments(app.CurrentSegmentIndex);
            if ~isempty(app.SelectedRow) && app.SelectedRow < height(segment.waypoints)
                app.addWaypoint([], app.SelectedRow);
                app.Mode = 'select';
                app.StatusLabel.Text = sprintf('Inserted waypoint after row %d', app.SelectedRow);
            else
                app.setMode('addWaypoint');
            end
        end

        function setMode(app, newMode)
            app.Mode = newMode;
            app.StatusLabel.Text = ['Mode: ' upper(newMode)];
        end

        function handleCanvasClick(app, evt)
            coords = app.UIAxes.CurrentPoint(1,1:2);
            idx = app.findHeadingArrowIndex(coords);
            if ~isempty(idx)
                app.startHeadingAdjust(coords, idx);
                return;
            end
            idx = app.findWaypointIndex(coords);
            if ~isempty(idx)
                if ~isempty(app.InsertedWaypointRow) && idx == app.InsertedWaypointRow
                    app.selectWaypoint(coords, idx, true);
                    app.InsertedWaypointRow = [];
                else
                    app.selectWaypoint(coords, idx);
                end
            elseif strcmp(app.Mode, 'addWaypoint')
                app.addWaypoint(coords);
            end
        end

        function idx = findHeadingArrowIndex(app, coords)
            segment = app.Segments(app.CurrentSegmentIndex);
            idx = [];
            if isempty(segment.waypoints) || height(segment.waypoints) == 0
                return;
            end
            arrowLength = 0.6;
            axLimits = [diff(xlim(app.UIAxes)), diff(ylim(app.UIAxes))];
            threshold = max(0.25, 0.03 * max(axLimits));
            distances = inf(height(segment.waypoints), 1);
            for i = 1:height(segment.waypoints)
                theta = deg2rad(segment.waypoints.heading(i));
                tipX = segment.waypoints.x(i) + cos(theta)*arrowLength;
                tipY = segment.waypoints.y(i) + sin(theta)*arrowLength;
                distances(i) = hypot(tipX - coords(1), tipY - coords(2));
            end
            [minDist, minIdx] = min(distances);
            if minDist < threshold
                idx = minIdx;
            end
        end

        function startHeadingAdjust(app, ~, idx)
            segment = app.Segments(app.CurrentSegmentIndex);
            if isempty(segment.waypoints) || height(segment.waypoints) == 0 || idx < 1 || idx > height(segment.waypoints)
                return;
            end
            app.SelectedRow = idx;
            app.SelectedWaypoint = segment.waypoints.id(idx);
            app.HeadingAdjusting = true;
            app.HeadingAdjustRow = idx;
            app.StatusLabel.Text = 'Adjusting heading...';
            app.updatePlot();
        end

        function idx = findWaypointIndex(app, coords)
            segment = app.Segments(app.CurrentSegmentIndex);
            idx = [];
            if isempty(segment.waypoints) || height(segment.waypoints) == 0
                return;
            end
            distances = hypot(segment.waypoints.x - coords(1), segment.waypoints.y - coords(2));
            [minDist, minIdx] = min(distances);
            axLimits = [diff(xlim(app.UIAxes)), diff(ylim(app.UIAxes))];
            threshold = max(0.3, 0.05 * max(axLimits));
            if minDist < threshold
                idx = minIdx;
                return;
            end
            if ~isempty(app.SelectedRow) && app.SelectedRow <= height(segment.waypoints)
                selectedDist = hypot(segment.waypoints.x(app.SelectedRow) - coords(1), segment.waypoints.y(app.SelectedRow) - coords(2));
                if selectedDist < max(threshold, 0.4)
                    idx = app.SelectedRow;
                end
            end
        end

        function addWaypoint(app, coords, insertAfterRow)
            segment = app.Segments(app.CurrentSegmentIndex);
            if nargin < 3
                insertAfterRow = [];
            end

            % If a row is selected and it's not the final row, insert a midpoint.
            if isempty(insertAfterRow) && ~isempty(app.SelectedRow) && app.SelectedRow < height(segment.waypoints)
                insertAfterRow = app.SelectedRow;
            end

            if ~isempty(insertAfterRow)
                beforeIdx = insertAfterRow;
                afterIdx = insertAfterRow + 1;
                if isempty(coords)
                    coords = [
                        (segment.waypoints.x(beforeIdx) + segment.waypoints.x(afterIdx)) / 2,
                        (segment.waypoints.y(beforeIdx) + segment.waypoints.y(afterIdx)) / 2];
                end
                headingVal = app.averageHeading(segment.waypoints.heading(beforeIdx), segment.waypoints.heading(afterIdx));
                velocityVal = mean([segment.waypoints.velocity(beforeIdx), segment.waypoints.velocity(afterIdx)]);
                actionStaticVal = mean([segment.waypoints.actionStatic(beforeIdx), segment.waypoints.actionStatic(afterIdx)]);
                actionDynamicVal = mean([segment.waypoints.actionDynamic(beforeIdx), segment.waypoints.actionDynamic(afterIdx)]);
                app.StatusLabel.Text = sprintf('Inserted waypoint between rows %d and %d', beforeIdx, afterIdx);
            else
                if isempty(coords)
                    coords = [0, 0];
                end
                if ~isempty(app.SelectedRow)
                    headingVal = segment.waypoints.heading(app.SelectedRow);
                    velocityVal = segment.waypoints.velocity(app.SelectedRow);
                    actionStaticVal = segment.waypoints.actionStatic(app.SelectedRow);
                    actionDynamicVal = segment.waypoints.actionDynamic(app.SelectedRow);
                else
                    headingVal = 0;
                    velocityVal = 1;
                    actionStaticVal = 0;
                    actionDynamicVal = 0;
                end
            end

            if isempty(insertAfterRow) || isempty(segment.waypoints)
                newRow = table(height(segment.waypoints)+1, coords(1), coords(2), headingVal, velocityVal, actionStaticVal, actionDynamicVal, ...
                    'VariableNames', {'id','x','y','heading','velocity','actionStatic','actionDynamic'});
                segment.waypoints = [segment.waypoints; newRow];
            else
                newRow = table(0, coords(1), coords(2), headingVal, velocityVal, actionStaticVal, actionDynamicVal, ...
                    'VariableNames', {'id','x','y','heading','velocity','actionStatic','actionDynamic'});
                segment.waypoints = [segment.waypoints(1:insertAfterRow,:); newRow; segment.waypoints(insertAfterRow+1:end,:)];
            end

            % Keep waypoint IDs sequential and consistent with row order.
            segment.waypoints.id = (1:height(segment.waypoints))';
            app.Segments(app.CurrentSegmentIndex) = segment;
            if isempty(insertAfterRow)
                app.SelectedRow = height(segment.waypoints);
            else
                app.SelectedRow = insertAfterRow + 1;
            end
            app.selectWaypoint([], app.SelectedRow, false);
            app.Dragging = false;
            app.DraggedRow = [];
            app.InsertedWaypointRow = app.SelectedRow;
            app.StatusLabel.Text = 'Waypoint inserted. Click it to drag.';
            app.updateWaypointTable();
            app.updatePlot();
        end

        function avg = averageHeading(app, a, b)
            a = mod(a, 360);
            b = mod(b, 360);
            diff = mod(b - a + 180, 360) - 180;
            avg = mod(a + diff/2, 360);
        end


        function updateRobotProperties(app)
            app.Robot.width = app.RobotWidthField.Value;
            app.Robot.length = app.RobotLengthField.Value;
            app.Robot.pivotOffset = [app.PivotXField.Value, app.PivotYField.Value];
            app.updatePlot();
        end

        function toggleConfigPanel(app)
            if strcmp(app.ConfigPanel.Visible, 'on')
                app.ConfigPanel.Visible = 'off';
                app.ConfigToggleButton.Text = 'Robot Config';
            else
                app.ConfigPanel.Visible = 'on';
                app.ConfigToggleButton.Text = 'Hide Config';
            end
        end

        function updateWaypointTable(app)
            segment = app.Segments(app.CurrentSegmentIndex);
            if isempty(segment.waypoints) || height(segment.waypoints)==0
                app.WaypointTable.Data = {};
            else
                % Only display X, Y, Velocity, Heading, Action Static, Action Dynamic (hide ID)
                sub = segment.waypoints(:, {'x','y','velocity','heading','actionStatic','actionDynamic'});
                app.WaypointTable.Data = table2cell(sub);
            end
        end

        function updateSegmentList(app)
            tableData = cell(numel(app.Segments), 2);
            for i = 1:numel(app.Segments)
                tableData{i,1} = logical(app.Segments(i).visible);
                tableData{i,2} = app.Segments(i).name;
            end
            app.SegmentList.Data = tableData;
            app.updateWaypointTable();
        end

        function segmentTableEdited(app, evt)
            if isempty(evt.Indices)
                return;
            end
            row = evt.Indices(1,1);
            col = evt.Indices(1,2);
            if row < 1 || row > numel(app.Segments)
                return;
            end
            if col == 1
                app.Segments(row).visible = logical(evt.NewData);
                app.updatePlot();
                return;
            end
            if col == 2
                newName = string(evt.NewData);
                if isempty(newName)
                    return;
                end
                app.Segments(row).name = char(newName);
                app.updateSegmentList();
                return;
            end
        end

        function segmentVisibilityChanged(app, evt)
            if isempty(evt.Indices)
                return;
            end
            row = evt.Indices(1,1);
            if row < 1 || row > numel(app.Segments)
                return;
            end
            app.Segments(row).visible = logical(evt.NewData);
            app.updatePlot();
        end

        function segmentTableSelectionChanged(app, evt)
            if isempty(evt.Indices)
                return;
            end
            row = evt.Indices(1,1);
            if row < 1 || row > numel(app.Segments)
                return;
            end
            app.CurrentSegmentIndex = row;
            app.SelectedRow = [];
            app.SelectedWaypoint = [];
            app.InsertedWaypointRow = [];
            app.Dragging = false;
            app.DraggedRow = [];
            app.Mode = 'select';
            app.StatusLabel.Text = sprintf('Segment: %s', app.Segments(row).name);
            app.updateWaypointTable();
            app.updatePlot();
        end

        function updatePlot(app)
            try
                cla(app.UIAxes);
                hold(app.UIAxes, 'on');

            app.drawFieldBackground();

            % Draw visible segments
            for pi = 1:numel(app.Segments)
                segment = app.Segments(pi);
                if ~segment.visible || isempty(segment.waypoints)
                    continue;
                end
                x = segment.waypoints.x;
                y = segment.waypoints.y;
                if pi == app.CurrentSegmentIndex
                    lineColor = segment.color;
                    lineWidth = 1;
                    markerSize = 6;
                    markerFace = segment.color;
                    rectColor = [0.7 0.7 0.7];
                    rectAlpha = 0.5;
                else
                    lineColor = segment.color;
                    lineWidth = 1;
                    markerSize = 4;
                    markerFace = 'none';
                    rectColor = segment.color;
                    rectAlpha = 0.06;
                end
                hLine = plot(app.UIAxes, x, y, '-o', 'Color', lineColor, 'LineWidth', lineWidth, 'MarkerSize', markerSize, 'MarkerFaceColor', markerFace, 'HitTest', 'off');
                set(hLine, 'PickableParts', 'none');
                if app.Settings.displayHeadings
                    for i = 1:height(segment.waypoints)
                        theta = deg2rad(segment.waypoints.heading(i));
                        dx = cos(theta) * 0.6;
                        dy = sin(theta) * 0.6;
                        hq = quiver(app.UIAxes, x(i), y(i), dx, dy, 0, 'Color', [0 0 0], 'MaxHeadSize', 2);
                        try
                            set(hq, 'HitTest', 'off', 'PickableParts', 'none');
                        catch
                        end
                    end
                end
                for i = 1:height(segment.waypoints)
                    pose = [segment.waypoints.x(i), segment.waypoints.y(i), segment.waypoints.heading(i)];
                    app.drawRobotRectangle(pose, rectColor, rectAlpha);
                end
            end

            % Draw simulation paths
            for si = 1:numel(app.SimulationPaths)
                simData = app.SimulationPaths(si);
                plot(app.UIAxes, simData.x, simData.y, '--', 'Color', simData.color, 'LineWidth', 2, 'DisplayName', sprintf('Sim %d', si));
            end

            % Draw robot rectangle at selected waypoint if any
            if ~isempty(app.SelectedWaypoint)
                segment = app.Segments(app.CurrentSegmentIndex);
                idx = find(segment.waypoints.id == app.SelectedWaypoint, 1);
                if ~isempty(idx)
                    pose = [segment.waypoints.x(idx), segment.waypoints.y(idx), segment.waypoints.heading(idx)];
                    app.drawRobotRectangle(pose, [0.2 0.6 0.2], 0.4);
                end
            end

                xlim(app.UIAxes, [0 app.Field.length]);
                ylim(app.UIAxes, [0 app.Field.width]);

                hold(app.UIAxes, 'off');
                axis(app.UIAxes, 'equal');
            catch ME
                % Show concise error in status and ensure axes state
                try
                    app.StatusLabel.Text = ['Error: ' ME.message(1:min(end,120))];
                catch
                end
                try
                    hold(app.UIAxes, 'off');
                    axis(app.UIAxes, 'equal');
                catch
                end
            end
        end

        function drawRobotRectangle(app, pose, faceColor, faceAlpha)
            if nargin < 4 || isempty(faceAlpha)
                faceAlpha = 0.4;
            end
            if nargin < 3 || isempty(faceColor)
                faceColor = [0.2 0.6 0.2];
            end
            waypointX = pose(1);
            waypointY = pose(2);
            heading = pose(3);
            halfW = app.Robot.width / 2;
            halfL = app.Robot.length / 2;

            pivotBody = app.Robot.pivotOffset(:);
            R = [cosd(heading), -sind(heading); sind(heading), cosd(heading)];
            centerWorld = [waypointX, waypointY] - (R * pivotBody)';

            corners = [ -halfL, -halfW;
                         -halfL,  halfW;
                          halfL,  halfW;
                          halfL, -halfW];
            rotated = (R * corners')';
            worldCorners = rotated + centerWorld;

            patch(app.UIAxes, worldCorners(:,1), worldCorners(:,2), faceColor, 'FaceAlpha', faceAlpha, 'EdgeColor', max(faceColor*0.5, 0), 'HitTest', 'off', 'PickableParts', 'none');

            hMarker = plot(app.UIAxes, waypointX, waypointY, 'kx', 'MarkerSize', 8, 'LineWidth', 2);
            set(hMarker, 'HitTest', 'off', 'PickableParts', 'none');
            hLine = plot(app.UIAxes, [centerWorld(1), waypointX], [centerWorld(2), waypointY], '-k', 'LineWidth', 1);
            set(hLine, 'HitTest', 'off', 'PickableParts', 'none');
        end

        function selectWaypoint(app, coords, idx, startDrag)
            segment = app.Segments(app.CurrentSegmentIndex);
            if nargin < 3
                idx = app.findWaypointIndex(coords);
            end
            if nargin < 4
                startDrag = true;
            end
            if isempty(segment.waypoints) || height(segment.waypoints)==0 || isempty(idx)
                return;
            end
            try
                app.SelectedWaypoint = segment.waypoints.id(idx);
                app.SelectedRow = idx;
                if startDrag
                    app.Dragging = true;
                    app.DraggedRow = idx;
                    app.StatusLabel.Text = 'Dragging waypoint...';
                else
                    app.StatusLabel.Text = sprintf('Selected waypoint %d', idx);
                end
                app.updatePlot();
            catch ME
                app.StatusLabel.Text = ['Select error: ' ME.message(1:min(end,120))];
            end
        end

        function deleteSelectedObject(app)
            segment = app.Segments(app.CurrentSegmentIndex);
            idx = [];
            if ~isempty(app.SelectedWaypoint)
                idx = find(segment.waypoints.id == app.SelectedWaypoint, 1);
            end
            if isempty(idx) && ~isempty(app.SelectedRow)
                idx = app.SelectedRow;
            end
            if isempty(idx)
                return;
            end
            if idx > 0 && idx <= height(segment.waypoints)
                segment.waypoints(idx,:) = [];
                app.Segments(app.CurrentSegmentIndex) = segment;
                app.SelectedWaypoint = [];
                app.SelectedRow = [];
                app.updateWaypointTable();
                app.updatePlot();
            end
        end

        function tableSelectionChanged(app, evt)
            if isempty(evt.Indices)
                app.SelectedRow = [];
                return;
            end
            row = evt.Indices(1,1);
            segment = app.Segments(app.CurrentSegmentIndex);
            if row < 1 || row > height(segment.waypoints)
                return;
            end
            app.SelectedRow = row;
            app.SelectedWaypoint = segment.waypoints.id(row);
            app.StatusLabel.Text = sprintf('Selected waypoint %d', row);
            app.updatePlot();
        end

        function handleMouseMotion(app, src, evt)
            if app.HeadingAdjusting && ~isempty(app.HeadingAdjustRow)
                try
                    coords = app.UIAxes.CurrentPoint(1,1:2);
                    segment = app.Segments(app.CurrentSegmentIndex);
                    idx = app.HeadingAdjustRow;
                    center = [segment.waypoints.x(idx), segment.waypoints.y(idx)];
                    angle = atan2d(coords(2) - center(2), coords(1) - center(1));
                    if angle < 0
                        angle = angle + 360;
                    end
                    segment.waypoints.heading(idx) = angle;
                    app.Segments(app.CurrentSegmentIndex) = segment;
                    app.updateWaypointTable();
                    app.updatePlot();
                catch ME
                    app.StatusLabel.Text = ['Heading drag error: ' ME.message(1:min(end,120))];
                end
                return;
            end
            if ~app.Dragging || isempty(app.DraggedRow)
                return;
            end
            try
                coords = app.UIAxes.CurrentPoint(1,1:2);
                segment = app.Segments(app.CurrentSegmentIndex);
                % update the dragged waypoint position (by row index)
                segment.waypoints.x(app.DraggedRow) = coords(1);
                segment.waypoints.y(app.DraggedRow) = coords(2);
                app.Segments(app.CurrentSegmentIndex) = segment;
                app.updateWaypointTable();
                app.updatePlot();
            catch ME
                app.StatusLabel.Text = ['Drag error: ' ME.message(1:min(end,120))];
            end
        end

        function endDrag(app)
            if app.HeadingAdjusting
                app.HeadingAdjusting = false;
                app.HeadingAdjustRow = [];
                app.StatusLabel.Text = 'Heading set.';
                app.updatePlot();
                return;
            end
            if app.Dragging
                app.Dragging = false;
                app.DraggedRow = [];
                app.StatusLabel.Text = 'Mode: SELECT';
                app.updatePlot();
            end
        end

        function tableEdited(app, evt)
            % Map edited table column to waypoint variable name (ID hidden)
            segment = app.Segments(app.CurrentSegmentIndex);
            row = evt.Indices(1);
            col = evt.Indices(2);
            colNames = {'x','y','velocity','heading','actionStatic','actionDynamic'}; % visible columns
            if col < 1 || col > numel(colNames)
                return;
            end
            varName = colNames{col};
            newVal = evt.NewData;
            % Convert string to numeric if necessary
            if ischar(newVal)
                num = str2double(newVal);
                if ~isnan(num)
                    newVal = num;
                end
            end
            % write into the correct variable column
            segment.waypoints.(varName)(row) = newVal;
            app.Segments(app.CurrentSegmentIndex) = segment;

            % If edited row corresponds to the selected waypoint, sync editors
            editedId = segment.waypoints.id(row);
            % Keep selected waypoint consistent when editing the table
            if ~isempty(app.SelectedWaypoint) && app.SelectedWaypoint == editedId
                idx = find(segment.waypoints.id==app.SelectedWaypoint,1);
                if ~isempty(idx)
                    app.SelectedRow = idx;
                end
            end

            app.updatePlot();
            app.updateWaypointTable();
        end

        function saveState(app)
            assignedNames = string.empty(1,0);
            for i = 1:numel(app.Segments)
                rawName = app.Segments(i).name;
                sanitized = matlab.lang.makeValidName(rawName, 'ReplacementStyle', 'delete');
                if isempty(sanitized)
                    sanitized = sprintf('Segment_%02d', i);
                end
                varName = sanitized;
                suffix = 1;
                while ismember(varName, assignedNames)
                    varName = sprintf('%s_%d', sanitized, suffix); 
                    suffix = suffix + 1;
                end
                assignedNames(end+1) = varName; %#ok<AGROW>

                matrix = app.waypointMatrixFromTable(app.Segments(i).waypoints);
                assignin('base', varName, matrix);
            end

            info = struct();
            for i = 1:numel(app.Segments)
                info(i).name = app.Segments(i).name; 
                info(i).variableName = char(assignedNames(i));
                info(i).color = app.Segments(i).color;
                info(i).visible = app.Segments(i).visible;
            end
            assignin('base', 'SegmentPlannerSavedSegments', info);
            app.StatusLabel.Text = sprintf('Saved %d segment matrices to base workspace.', numel(app.Segments));
        end

        function loadSegments(app)
            vars = evalin('base', 'whos');
            validNames = {};
            for i = 1:numel(vars)
                if isnumeric(evalin('base', vars(i).name)) && numel(vars(i).size) == 2 && isequal(vars(i).size, [10 6])
                    validNames{end+1,1} = vars(i).name; %#ok<AGROW>
                end
            end
            if isempty(validNames)
                uialert(app.UIFigure, 'No valid 10x6 numeric matrices found in the workspace.', 'Load Segments');
                return;
            end
            [selection, ok] = listdlg('Name', 'Load Segments', 'PromptString', 'Select workspace variables to load as segments:', 'ListString', validNames, 'SelectionMode', 'multiple', 'ListSize', [300 300]);
            if ~ok || isempty(selection)
                return;
            end
            loaded = 0;
            for idx = selection(:)'
                varName = validNames{idx};
                matrix = evalin('base', varName);
                if ~app.isValidSegmentMatrix(matrix)
                    continue;
                end
                segment.name = varName;
                segment.waypoints = app.waypointTableFromMatrix(matrix);
                segment.color = [0.5,0.5,0.5];
                segment.visible = true;
                existingIndex = find(strcmp({app.Segments.name}, varName), 1);
                if isempty(existingIndex)
                    app.Segments(end+1) = segment; 
                else
                    app.Segments(existingIndex) = segment;
                end
                loaded = loaded + 1;
            end
            if loaded > 0
                app.CurrentSegmentIndex = numel(app.Segments);
                app.updateSegmentList();
                app.updatePlot();
                app.StatusLabel.Text = sprintf('Loaded %d segment(s) from workspace.', loaded);
                figure(app.UIFigure);
            else
                uialert(app.UIFigure, 'Selected variables were not valid 10x6 numeric matrices.', 'Load Segments');
            end
        end

        function runSimulation(app)
            if isempty(app.Segments)
                return;
            end
            app.SimulationPaths = struct('x', {}, 'y', {}, 'color', {});
            app.StatusLabel.Text = 'Running simulation...';
            drawnow;
            for i = 1:numel(app.Segments)
                Segment = app.waypointMatrixFromTable(app.Segments(i).waypoints);
                assignin('base', 'Spline_Ref_Poses', Segment);
                assignin('base', 'Spline_Num_Poses', nnz(Segment(:,1)));
                assignin('base', 'sim_IC_x', Segment(1,1));
                assignin('base', 'sim_IC_y', Segment(1,2));
                evalin('base', 'clear out');
                try
                    evalin('base', app.SimulationCommand);
                    out = evalin('base', 'out');
                catch ME
                    app.StatusLabel.Text = ['Simulation failed: ' ME.message(1:min(end,120))];
                    return;
                end
                if exist('out','var')
                    plot_X = out.Sim_X.signals.values;
                    plot_Y = out.Sim_Y.signals.values;
                    if i == 1
                        app.SimulationPaths(end+1) = struct('x', plot_X(:), 'y', plot_Y(:), 'color', [1,1,1]); % white for first segment
                    elseif i == 2
                        app.SimulationPaths(end+1) = struct('x', plot_X(:), 'y', plot_Y(:), 'color', [0,0,0]); % black for second segment
                    elseif i == 3
                        app.SimulationPaths(end+1) = struct('x', plot_X(:), 'y', plot_Y(:), 'color', [0.5,0.5,0.5]); % gray for third segment
                    elseif i == 4
                        app.SimulationPaths(end+1) = struct('x', plot_X(:), 'y', plot_Y(:), 'color', [0.1,0.1,0.7]); % blue for fourth segment
                    else
                        app.SimulationPaths(end+1) = struct('x', plot_X(:), 'y', plot_Y(:), 'color', rand(1,3));  % random color for additional segments
                    end
                else
                    app.StatusLabel.Text = sprintf('Simulation output missing for segment %d.', i);
                    return;
                end
            end
            app.updatePlot();
            app.StatusLabel.Text = sprintf('Simulation completed for %d segment(s).', numel(app.Segments));
        end

        function valid = isValidSegmentMatrix(app, matrix)
            valid = isnumeric(matrix) && ismatrix(matrix) && size(matrix,1) == 10 && size(matrix,2) == 6;
        end

        function matrix = waypointMatrixFromTable(app, tableData)
            targetRows = 10;
            if isempty(tableData) || height(tableData) == 0
                matrix = zeros(targetRows, 6);
                return;
            end
            matrix = [tableData{:,'x'}, tableData{:,'y'}, tableData{:,'velocity'}, tableData{:,'heading'}, tableData{:,'actionStatic'}, tableData{:,'actionDynamic'}];
            if size(matrix, 1) < targetRows
                matrix(end+1:targetRows, :) = 0; 
            elseif size(matrix, 1) > targetRows
                matrix = matrix(1:targetRows, :);
            end
        end

        function tableData = waypointTableFromMatrix(app, matrix)
            if isempty(matrix)
                tableData = table([], [], [], [], [], [], 'VariableNames', {'id','x','y','heading','velocity','actionStatic','actionDynamic'});
                return;
            end
            if size(matrix,2) ~= 6
                error('Waypoint matrix must have 6 columns: x,y,velocity,heading,actionStatic,actionDynamic');
            end
            % Remove trailing zero-padding rows before loading waypoints.
            lastNonZeroRow = find(any(matrix ~= 0, 2), 1, 'last');
            if isempty(lastNonZeroRow)
                tableData = table([], [], [], [], [], [], 'VariableNames', {'id','x','y','heading','velocity','actionStatic','actionDynamic'});
                return;
            end
            matrix = matrix(1:lastNonZeroRow, :);
            tableData = table((1:size(matrix,1))', matrix(:,1), matrix(:,2), matrix(:,4), matrix(:,3), matrix(:,5), matrix(:,6), ...
                'VariableNames', {'id','x','y','heading','velocity','actionStatic','actionDynamic'});

        end
    end
end
