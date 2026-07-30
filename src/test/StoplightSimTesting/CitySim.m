% Clear
clear all
clc

% Initialize Variables
% Person | x | y | dx | dy | StartTime |
%   #1   |  |  |  |  |  
people = [ 0, 1, 1, 0, 0;...
           2, 4, 0,-1, 2];

% Run Simulations


% Display Results
figure
hold on

%% For Each Frame...
% Draw Streets
DrawStreets;

% Draw Lights
drawLight(1,0,2)
drawLight(2,1,0)
drawLight(3,0,2)
drawLight(4,0,0)
drawLight(5,2,0)
drawLight(6,0,0)
drawLight(7,2,0)
drawLight(8,0,1)
drawLight(9,0,0)

% Draw Walks

% Draw People

% Draw Cars

