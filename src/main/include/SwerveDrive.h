#pragma once

//local
#include "include/Constants.h"
#include "DertLib/include/HighFrequencyComponent.h"
#include "DertLib/include/TalonFXMotorGroup.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "Odometry_ert_rtw/Odometry.h"
//frc
#include <frc/DutyCycleEncoder.h>
#include <frc/Preferences.h>
#include <frc/smartdashboard/SmartDashboard.h> 
//ctr
#include <ctre/phoenix6/CANcoder.hpp>
//etc
#include <frc/smartdashboard/SmartDashboard.h>

namespace Drive = Constants::SwerveMotorsCreateInfo::Drive;
namespace Steer = Constants::SwerveMotorsCreateInfo::Steer;
namespace SwerveInfo = Constants::SwerveInfo;

class SwerveDrive : public dlib::HighFrequencyComponent
{
public:
  SwerveDrive();
  void PreStepCallback() override;
  void PostStepCallback() override;
  void HighFrequencyPreStepCallback() override;
  void HighFrequencyPostStepCallback() override;

  dlib::TalonFXMotorGroup swerveDriveMotors
  {
    {
      Drive::frontLeft, Drive::frontRight,
      Drive::backLeft, Drive::backRight,
    }
  };
  
  dlib::TalonFXMotorGroup swerveSteerMotors
  {
    {
      Steer::frontLeft, Steer::frontRight,
      Steer::backLeft, Steer::backRight
    }
  };

private:
  /** Creates the wheel offset preferences if they have not been created */
  void Initalize_Wheel_Offset();

  /** Sets the simulink variables for wheel offsets to what is in the robot preferences */
  void Set_Wheel_Offset();

  

  //Steer Absolute Encoders
    ctre::phoenix6::hardware::CANcoder m_FrontLeft_Steer_Encoder{SwerveInfo::k_FrontLeft_Steer_Encoder_ID, *Constants::SwerveInfo::CANcoder_CANBus};
    ctre::phoenix6::hardware::CANcoder m_FrontRight_Steer_Encoder{SwerveInfo::k_FrontRight_Steer_Encoder_ID, *Constants::SwerveInfo::CANcoder_CANBus};
    ctre::phoenix6::hardware::CANcoder m_BackLeft_Steer_Encoder{SwerveInfo::k_BackLeft_Steer_Encoder_ID, *Constants::SwerveInfo::CANcoder_CANBus};
    ctre::phoenix6::hardware::CANcoder m_BackRight_Steer_Encoder{SwerveInfo::k_BackRight_Steer_Encoder_ID, *Constants::SwerveInfo::CANcoder_CANBus};
};

