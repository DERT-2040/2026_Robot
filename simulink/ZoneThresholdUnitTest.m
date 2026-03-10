
% Create Test Points
delta = 0.5;
TestPoints_X = [0:delta:16.54];
TestPoints_Y = [0:delta:8.07];

% Draw Initial Field
DrawField;

% Simulate at each test point
for x = TestPoints_X
    for y = TestPoints_Y
        % Simulate At Point
        
        
        % Display Result on Map
        if(out == trench)
            plot(x,y,"v");
        elseif(out == ramp)
            plot(x,y,"^")
        else
            plot(x,y,".")
        end
    end
end