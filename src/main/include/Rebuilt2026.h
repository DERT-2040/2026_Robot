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
        {"Auto 1 - Left  (1)", 1},
        {"Auto 1 - Right (2)", 2},
        {"Auto 2 - Left  (3)", 3},
        {"Auto 2 - Right (4)", 4},
        {"Auto 3 - Left  (5)", 5},
        {"Auto 3 - Right (6)", 6},
        {"Auto 4 - Left  (7)", 7},
        {"Auto 4 - Right (8)", 8},
        {"Auto 5 - Left  (9)", 9},
        {"Auto 5 - Right (10)", 10},
        {"Auto 6 - Center Hub-Depot-Trench-Trench-Hub (11)", 11},
        {"Auto 7 - Center Hub-Depot-Hub Shoot-Backup (12)", 12}        
      },
    &Auto_Path_Chooser //Simulink parameter name
  };
};

