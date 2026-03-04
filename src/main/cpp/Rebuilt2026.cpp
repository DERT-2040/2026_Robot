//Local
#include "include/Rebuilt2026.h"
#include <units/time.h>

Rebuilt2026::Rebuilt2026()
{
    HoodServoSetPulseWidth();   
    //change this with testing 
    IntakeArmAngle.SetInverted(true);
}

void Rebuilt2026::HoodServoSetPulseWidth()
{
	// Set servo pulse widths in microseconds
	HoodServo_Left.SetBounds(
    units::time::microsecond_t(2000), // full forward (extend)
    units::time::microsecond_t(1550), // deadband max
    units::time::microsecond_t(1500), // center
    units::time::microsecond_t(1450), // deadband min
    units::time::microsecond_t(1000)  // full reverse (retract)
	);

	// Set servo pulse widths in microseconds
	HoodServo_Right.SetBounds(
    units::time::microsecond_t(2000), // full forward (extend)
    units::time::microsecond_t(1550), // deadband max
    units::time::microsecond_t(1500), // center
    units::time::microsecond_t(1450), // deadband min
    units::time::microsecond_t(1000)  // full reverse (retract)
	);
}

void Rebuilt2026::PreStepCallback()
{
	ShooterMotors.SendVelocityValuesToSL();
    FeederMotors.SendVelocityValuesToSL();
    TransferMotors.SendVelocityValuesToSL();
    IntakeMotors.SendVelocityValuesToSL();
    Robot_Control_U.Measured_Intake_Arm_Angle = IntakeArmAngle.Get();
}

void Rebuilt2026::PostStepCallback()
{
	ShooterMotors.FetchMotorCommandsFromSL();
    FeederMotors.FetchMotorCommandsFromSL();
    TransferMotors.FetchMotorCommandsFromSL();
    IntakeMotors.FetchMotorCommandsFromSL();

    // Only set the servo positions if enabled from Simulink
    if(Robot_Control_Y.Desired_Hood_Enable)  // boolean from Simulink
    {
        HoodServo_Left.Set(Robot_Control_Y.Desired_Hood_Pos);
        HoodServo_Right.Set(Robot_Control_Y.Desired_Hood_Pos);
    }
}