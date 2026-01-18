#pragma once

// Local
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "Odometry_ert_rtw/Odometry.h"
#include "LimelightHelpers.h"
#include "DertLib/include/Component.h"
#include "include/Constants.h"

//wpilib
#include <networktables/NetworkTable.h>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <frc/Alert.h>

namespace LimelightNameSpace = Constants::Limelight;

class Limelight : public dlib::Component {
    public: 
     Limelight();
     void PreStepCallback() override;
     void PostStepCallback() override;
    private:

    // Limelight Data Objects
    LimelightHelpers::PoseEstimate CameraOneLLMeasurement;
    LimelightHelpers::PoseEstimate CameraTwoLLMeasurement;

    // Limelight Alerts
    frc::Alert CameraOneDisconnectedAlert {"ALARM PANIC", "Limelight One Disconnecred", frc::Alert::AlertType::kError};
    //frc::Alert CameraTwoDisconnectedAlert {"Limelight Two Disconnecred", frc::Alert::AlertType::kError};  
 
};