function [] = drawLight(lightNum,xLightColor,yLightColor)
% Plots a Light

% Determine RGB Colors
    % X
xColor = [1 0 0];
if (xLightColor == 1)
    xColor = [1 1 0];
elseif (xLightColor == 2)
    xColor = [0 1 0];
end
    % X
yColor = [1 0 0];
if (yLightColor == 1)
    yColor = [1 1 0];
elseif (yLightColor == 2)
    yColor = [0 1 0];
end

x = (mod(lightNum-1,3)+1)*7;
y = (idivide(int8(lightNum-1),3)+1)*7;

% Plot X First unless Green
if (xLightColor ~= 2)
    rectangle('Position', [x-2,y-1, 3, 1],'FaceColor',xColor,'EdgeColor',"none");
    rectangle('Position', [x-1,y-2, 1, 3],'FaceColor',yColor,'EdgeColor',"none");
else
    rectangle('Position', [x-1,y-2, 1, 3],'FaceColor',yColor,'EdgeColor',"none");
    rectangle('Position', [x-2,y-1, 3, 1],'FaceColor',xColor,'EdgeColor',"none");
end


end