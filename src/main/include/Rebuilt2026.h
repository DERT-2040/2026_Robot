#pragma once

//Local
#include "DertLib/include/Component.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "DertLib/include/TalonFX/TalonFXMotorGroup.h"
#include "Constants.h"
#include "DertLib/include/Chooser.h"

//FRC
#include <frc/Servo.h>
#include <frc/DutyCycleEncoder.h>

namespace nsShooter = Constants::ShooterCreateInfo;
namespace nsFeeder = Constants::FeederCreateInfo;
namespace nsTransfer = Constants::TransferCreateInfo;
namespace nsHood = Constants::HoodServo;
namespace nsIntake = Constants::IntakeCreateInfo;
namespace nsIntakeAngle = Constants::IntakeArmAngle;

class Rebuilt2026 : public dlib::Component
{
public:
	Rebuilt2026();
	void HoodServoSetPulseWidth();
	void PreStepCallback() override;
	void PostStepCallback() override;

private:
  // Servos for hood linear actuator  
  frc::Servo HoodServo_Left{nsHood::Hood_Servo_PWM_Left_ID};
  frc::Servo HoodServo_Right{nsHood::Hood_Servo_PWM_Right_ID};
    dlib::TalonFX::TalonFXMotorGroup ShooterMotors
  {
    {
      nsShooter::Left, nsShooter::Center, nsShooter::Right
    }
  };

  dlib::TalonFX::TalonFXMotorGroup FeederMotors
  {
    {
      nsFeeder::Feeder
    }
  };
   
  dlib::TalonFX::TalonFXMotorGroup TransferMotors
  {
    {
      nsTransfer::Transfer
    }
  };
  
  dlib::TalonFX::TalonFXMotorGroup IntakeMotors
  {
    {
      nsIntake::Intake_Roller, nsIntake::Intake_Arm
    }
  };

  frc::DutyCycleEncoder IntakeArmAngle
  {
    nsIntakeAngle::armThroughBoreEncoderID, 
    360, 
    nsIntakeAngle::armThroughBoreEncoderOffset
  };

  dlib::Chooser Auto_Path_Starting_Position_Chooser {
    "Auto Path Starting Position",
      {
        {"01 - Left - NZ - Left - Hub - Left - NZ - Left - Hub", 3},
        {"02 - Left - NZ - Left - Long - Left - NZ - Left - Long", 7},
        {"03 - Left - NZ - Ramp - Hub - Left - NZ - Ramp - Hub", 9},
        {"04 - Left - NZ - Ramp - Hub - Ramp - NZ (beached!) - Ramp - Hub", 5},
        {"05 - Left - NZ - Right - Hub - Right - NZ - Left - Hub", 1},
        {"06 - Right - NZ - Right - Hub - Right - NZ - Right - Hub", 4},
        {"07 - Right - NZ - Right - Long - Right - NZ - Right - Long", 8},
        {"08 - Right - NZ - Ramp - Hub - Right - NZ - Ramp - Hub", 10},
        {"09 - Right - NZ - Ramp - Hub - Ramp - NZ (beached!) - Ramp - Hub", 6}, 
        {"10 - Right - NZ - Left - Hub - Left - NZ - Right - Hub", 2}     
      },
    &Auto_Path_Chooser //Simulink parameter name
  };
};

