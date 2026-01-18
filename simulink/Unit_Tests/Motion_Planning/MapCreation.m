clc;

Boarder = [164.989375, 21.656250 ;
           723.010625, 21.656250 ;
           790.500479, 70.670000 ;
           790.500479, 289.330000;
           723.010625, 338.343750;
           164.989375, 338.343750;
           97.499521 , 289.330000;
           97.499521 , 70.670000];
Boarder(:,1) = 0.0254*(Boarder(:,1) - 97.499521);
Boarder(:,2) = 0.0254*(Boarder(:,2) - 21.656250);

Blue_Reef = [275.309848 142.908391 ;
             307.555197 161.455735 ;
             307.532920 198.614236 ;
             275.367770 217.198057 ;  
             243.122420 198.650713 ;
             243.187217 161.451766];
Blue_Reef(:,1) = 0.0254*(Blue_Reef(:,1) - 97.499521);
Blue_Reef(:,2) = 0.0254*(Blue_Reef(:,2) - 21.656250);


Red_Reef = [(337.3849 + 275.309848) 142.908391 ;
            (337.3849 + 307.555197) 161.455735 ;
            (337.3849 + 307.532920) 198.614236 ;
            (337.3849 + 275.367770) 217.198057 ;  
            (337.3849 + 243.122420) 198.650713 ;
            (337.3849 + 243.187217) 161.451766];
Red_Reef(:,1) = 0.0254*(Red_Reef(:,1) - 97.499521);
Red_Reef(:,2) = 0.0254*(Red_Reef(:,2) - 21.656250);

Center_Pillar = [455.510000 192.0 ;
                 455.510000 168.0 ;
                 432.510000 168.0 ;
                 432.510000 192.0];
Center_Pillar(:,1) = 0.0254*(Center_Pillar(:,1) - 97.499521);
Center_Pillar(:,2) = 0.0254*(Center_Pillar(:,2) - 21.656250);

Blue_Dive_Zone = [467.000000 338.343750 ;
                  467.000000 192.000000 ;
                  421.000000 192.000000 ;
                  421.000000 338.343750];
Blue_Dive_Zone(:,1) = 0.0254*(Blue_Dive_Zone(:,1) - 97.499521);
Blue_Dive_Zone(:,2) = 0.0254*(Blue_Dive_Zone(:,2) - 21.656250);

Objects = {Boarder, Blue_Reef, Center_Pillar, Blue_Dive_Zone, Red_Reef};


resolution = 10; %samples per meter
map_width = 1755/100;
map_height = 805/100;
map = occupancyMap(map_width, map_height, resolution);
grid = getOccupancy(map);
grid(:) = 0;
setOccupancy(map, grid);

map = fillpolygon(Blue_Reef, resolution, map);
map = fillpolygon(Center_Pillar, resolution, map);
map = fillpolygon(Blue_Dive_Zone, resolution, map);
map = fillpolygon(Red_Reef, resolution, map);
inflate(map, 0.55);

planner = plannerAStarGrid(map);

path = plan(planner, world2grid(map,start_xy), world2grid(map,end_xy));

pathWorld = grid2world(map, path);


pathoptions = optimizePathOptions;
pathoptions.ObstacleSafetyMargin = 0.1;
[out, traj] = optimizePath(pathWorld, map, pathoptions);
% figure(1);
% show(map);
% hold on
% plot(path(:,2)/resolution, map_height-path(:,1)/resolution, 'Color', '#08E8DE', 'LineWidth', 2);
% plot(out(:,1),out(:,2), 'Color', ' #FF8C00', 'LineWidth', 2)

% figure(2);
% plot(traj.TimeStamps(2:size(traj.TimeStamps,1)), traj.Velocity);

% figure(3);
% show(planner);


function newmap = fillpolygon(points, resolution, map)
    dx = 1/resolution;
    xv = min(points(:,1)) : dx : max(points(:,1));
    yv = min(points(:,2)) : dx : max(points(:,2));

    [X, Y] = meshgrid(xv, yv);
    in = inpolygon(X,Y, points(:,1), points(:,2));
    setOccupancy(map, [X(in), Y(in)], 1);
    newmap = map;
end