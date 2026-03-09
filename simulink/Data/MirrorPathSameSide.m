function [MirroredPath] = MirrorPathSameSide(InputPath, field_width)
%This function outputs the mirror of an autonomous path
% Assumes the path has 10 poses, some of which may be empty.
% Mirrors all poses.

% Initialize New Path with First Pose
MirroredPath = zeros(10,6);

% Find number of nonzero poses
NNZ = nnz(InputPath(:,1));

for i = 1:NNZ
    MirroredPath(i,:) = [InputPath(i,1),  field_width-InputPath(i,2),  InputPath(i,3),  InputPath(i,4),  InputPath(i,5),  InputPath(i,6)];
end