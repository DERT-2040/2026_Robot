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
        {"Left Trench - Right Trench - Hub", 1},
        {"Right Trench - Left Trench - Hub", 2},
        {"Left Trench - Left Trench - Hub", 3},
        {"Right Trench - Right Trench - Hub", 4},
        {"Left Trench - Left Ramp - Hub", 5},
        {"Right Trench - Right Ramp - Hub", 6},  
        {"Left Trench - Left Trench - Long Shoot", 7},
        {"Right Trench - Right Trench - Long Shoot", 8}                
      },
    &Auto_Path_Chooser //Simulink parameter name
  };
};

