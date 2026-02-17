// Local
#include "include/FMSInfo.h"

void FMSInfo::PreStepCallback()
{
	gameData = frc::DriverStation::GetGameSpecificMessage();
	Robot_Control_U.MatchTime = frc::DriverStation::GetMatchTime().value();

	if(gameData.length() > 0) 
	{
		switch (gameData[0])
		{
		case 'B' :
		Robot_Control_U.IsBlueInactiveFirst = 1;
		break;
		case 'R' :
		Robot_Control_U.IsBlueInactiveFirst = 0;
		break;
		default :
		//This is corrupt data
		break;
		}
	}
	else 
	{
		Robot_Control_U.IsBlueInactiveFirst = 0;
	}

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