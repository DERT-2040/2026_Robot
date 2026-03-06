function [MirroredPointTrench] = MirrorPointTrench(InputPoint, red_trench_x, blue_trench_x, Is_Blue)

if Is_Blue
    MirroredPointTrench = (blue_trench_x - InputPoint) + blue_trench_x;
else
    MirroredPointTrench = (red_trench_x - InputPoint) + red_trench_x;
end