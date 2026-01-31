//Local
#include "include/Rebuilt2026.h"

void Rebuilt2026::PreStepCallback()
{
	ShooterMotors.SendVelocityValuesToSL();
    FeederMotors.SendVelocityValuesToSL();
    TransferMotors.SendVelocityValuesToSL();
}


void Rebuilt2026::PostStepCallback()
{
	ShooterMotors.FetchMotorCommandsFromSL();
    FeederMotors.FetchMotorCommandsFromSL();
    TransferMotors.FetchMotorCommandsFromSL();
}
