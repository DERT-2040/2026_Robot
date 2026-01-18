#pragma once

// Local
#include "DertLib/include/Component.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "Odometry_ert_rtw/Odometry.h"

//frc
#include <frc/DriverStation.h>

class FMSInfo : public dlib::Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;
	void FastPreStepCallback();
	void FastPostStepCallback();
private:
	bool hasIntChanged(int current, int& previous);
	int previous = -1; 
};
