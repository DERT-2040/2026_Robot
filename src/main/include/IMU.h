#pragma once

//local
#include "DertLib/include/HighFrequencyComponent.h"
#include "include/Constants.h"

//crte
#include <ctre/phoenix6/Pigeon2.hpp>
//Simulink
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "Odometry_ert_rtw/Odometry.h"

namespace kIMU = Constants::IMU;

class IMU : public dlib::HighFrequencyComponent
{
public:
    IMU();
    void PreStepCallback() override;
    void PostStepCallback() override;
    void HighFrequencyPreStepCallback() override;
    void HighFrequencyPostStepCallback() override;
private:
    /**
     * Pigeon 2 IMU from CRTE
    */
    ctre::phoenix6::hardware::Pigeon2 m_Pigeon2{kIMU::k_Pigeon2_Device_ID, kIMU::IMU_CANBus};

};