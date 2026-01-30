function [MirroredPath] = MirrorPath(InputPath, field_width, field_length)
%This function outputs the mirror of an autonomous path
% Assumes the path has at LEAST 2 poses and at MAX 10 poses
% Mirrors all poses

% Initialize New Path with First Pose
MirroredPath = [field_length-InputPath(1,1),  field_width-InputPath(1,2),  InputPath(1,3),  InputPath(1,4)-pi];

% Find number of nonzero poses
NNZ = nnz(InputPath(:,1));
NZ  = 10 - NNZ;

for i = 2:10
    if i <= NNZ
    newPose = [field_length-InputPath(i,1),  field_width-InputPath(i,2),  InputPath(i,3),  InputPath(i,4)-pi]
        MirroredPath = [MirroredPath ; newPose];
    else
        MirroredPath = [MirroredPath ; 0,0,0,0];
    end
end