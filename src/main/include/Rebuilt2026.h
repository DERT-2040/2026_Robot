#pragma once

//Local
#include "DertLib/include/Component.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "DertLib/include/TalonFXMotorGroup.h"
#include "Constants.h"

namespace nsShooter = Constants::ShooterCreateInfo;
namespace nsFeeder = Constants::FeederCreateInfo;
namespace nsTransfer = Constants::TransferCreateInfo;

class Rebuilt2026 : public dlib::Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;

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
  
private:
};

