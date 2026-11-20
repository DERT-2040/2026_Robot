//Local
#include "include/SeasonSpecific.h"
#include <units/time.h>

SeasonSpecific::SeasonSpecific()
{}

void SeasonSpecific::PreStepCallback()
{
    Wrist_Motors.SendSensorDataToSL();
}

void SeasonSpecific::PostStepCallback()
{
    Wrist_Motors.FetchMotorCommandsFromSL();
}