% Create Test Points
delta = 1;
TestPoints_X = [0:delta:16.54];
TestPoints_Y = [0:delta:8.07];
Angle = 1;

% Draw Initial Field
DrawField;

% Simulate at each test point
for x = TestPoints_X
    for y = TestPoints_Y
        % Simulate At Point
        out = sim('Trench_Zone');

        % Display Result on Map
        if(out.Des_Trench_Angle_Adj ~= 0)
            plot(x,y,"x");
        end
    end
end