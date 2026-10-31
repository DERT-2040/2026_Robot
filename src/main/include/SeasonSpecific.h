#pragma once

//Local
#include "Constants.h"
#include "DertLib/include/Component.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
// #include "DertLib/include/TalonFX/TalonFXMotorGroup.h"
#include "DertLib/include/Chooser.h"

class SeasonSpecific : public dlib::Component
{
public:
	SeasonSpecific();
	void PreStepCallback() override;
	void PostStepCallback() override;

private:
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

