//local
#include "include/IMU.h"

IMU::IMU()
{
    m_Pigeon2.Reset();
}

void IMU::PreStepCallback() {}

void IMU::PostStepCallback() {}

void IMU::HighFrequencyPreStepCallback()
{
    Odometry_U.Gyro_Angle = m_Pigeon2.GetRotation2d().Degrees().value();
}

void IMU::HighFrequencyPostStepCallback() {}