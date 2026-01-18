#pragma once

//local
#include "include/Constants.h"
#include "Robot_Control_ert_rtw\Robot_Control.h"
#include "DertLib/include/Component.h"
//frc
#include <frc/Joystick.h>
#include <frc/GenericHID.h>

namespace HID = Constants::HID;

class HIDs : public dlib::Component
{
public:
    void PreStepCallback() override;
    void PostStepCallback() override;
private:
    /**
     * The gamepad used for robot implements.
     * Axis:
     *    0: Left X
     *    1: Left Y
     *    2: Left Trigger
     *    3: Right Trigger
     *    4: Right X
     *    5: Right Y
     * Buttons:
     *    1: A
     *    2: B
     *    3: X
     *    4: Y
     *    5: Left Bumper
     *    6: Right Bumper
     *    7: Back
     *    8: Start
     *    9: Left Joystick
     *    10: Right Joystick
     */
    frc::GenericHID m_Gamepad{HID::k_Gamepad_Port};

    /**
     * Joystick that is on the index of k_Drive_Joystick_Port
     */
    frc::Joystick m_Left_Joystick{HID::k_Right_Joystick_Port};

    /**
     * Joystick that is on the index of k_Steer_Joystick_Port
     */
    frc::Joystick m_Right_Joystick{HID::k_Left_Joystick_Port};
};
