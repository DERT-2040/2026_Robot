function [MirroredPoint] = MirrorPoint(InputPoint, field_length, field_width, Is_X)

if Is_X
    MirroredPoint = field_length - InputPoint;
else
    MirroredPoint = field_width - InputPoint;
end