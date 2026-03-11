#pragma once

//Local
#include "DertLib/include/Component.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "DertLib/include/TalonFXMotorGroup.h"
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
    dlib::TalonFXMotorGroup ShooterMotors
  {
    {
      nsShooter::Left, nsShooter::Center, nsShooter::Right
    }
  };

  dlib::TalonFXMotorGroup FeederMotors
  {
    {
      nsFeeder::Feeder
    }
  };
   
  dlib::TalonFXMotorGroup TransferMotors
  {
    {
      nsTransfer::Transfer
    }
  };
  
  dlib::TalonFXMotorGroup IntakeMotors
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
        {"Auto_Path_01", 1},
        {"Auto_Path_02", 2},
        {"Auto_Path_03", 3},
        {"Auto_Path_04", 4},
        {"Auto_Path_06", 5},
        {"Auto_Path_06", 6},
        {"Auto_Path_07", 7}        
      },
    &Auto_Path_Chooser //Simulink parameter name
  };
};

