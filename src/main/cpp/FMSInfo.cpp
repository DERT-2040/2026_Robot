// Local
#include "include/FMSInfo.h"

void FMSInfo::PreStepCallback()
{
	Robot_Control_U.MatchTime = frc::DriverStation::GetMatchTime().value();
	if(hasIntChanged(static_cast<int>(Robot_Control_U.GameState), previous))
	{
		if(frc::DriverStation::GetAlliance().has_value())
			Robot_Control_U.IsBlueAlliance = frc::DriverStation::GetAlliance().value();
		else
			Robot_Control_U.IsBlueAlliance = 1;
		Odometry_U.IsBlueAlliance = Robot_Control_U.IsBlueAlliance;
	}
}

void FMSInfo::PostStepCallback() {}

bool FMSInfo::hasIntChanged(int current, int& previous)
{
	if(current == previous) return false;
	previous = current;
	return true;
}