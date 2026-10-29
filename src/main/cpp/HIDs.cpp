//local
#include "include\HIDs.h"

void HIDs::PreStepCallback() {
    // Steer and Drive Joysticks
    Robot_Control_U.Xbox_Driver_Stick_Left_X = -m_DriverXbox.GetLeftY(); 
    Robot_Control_U.Xbox_Driver_Stick_Left_Y = -m_DriverXbox.GetLeftX();

    Robot_Control_U.Xbox_Driver_Stick_Right_X = -m_DriverXbox.GetRightY();
    Robot_Control_U.Xbox_Driver_Stick_Right_Y = -m_DriverXbox.GetRightX();
  
    Robot_Control_U.Xbox_Driver_Bumper_Left = m_DriverXbox.GetLeftBumperButton(); 
    Robot_Control_U.Xbox_Driver_Bumper_Right = m_DriverXbox.GetRightBumperButton();

    Robot_Control_U.Xbox_Driver_Trigger_Left = m_DriverXbox.GetLeftTriggerAxis(); 
    Robot_Control_U.Xbox_Driver_Trigger_Right = m_DriverXbox.GetRightTriggerAxis();

    Robot_Control_U.Xbox_Driver_ButtonY = m_DriverXbox.GetYButton();          
    Robot_Control_U.Xbox_Driver_ButtonX = m_DriverXbox.GetXButton();    
    Robot_Control_U.Xbox_Driver_ButtonB = m_DriverXbox.GetBButton();
    Robot_Control_U.Xbox_Driver_ButtonA = m_DriverXbox.GetAButton();

    // Gamepad
    Robot_Control_U.Gamepad_Stick_Left_X = m_Gamepad.GetRawAxis(0);
    Robot_Control_U.Gamepad_Stick_Left_Y = -m_Gamepad.GetRawAxis(1);
       
    Robot_Control_U.Gamepad_Stick_Right_X = m_Gamepad.GetRawAxis(4);
    Robot_Control_U.Gamepad_Stick_Right_Y = -m_Gamepad.GetRawAxis(5);  

    Robot_Control_U.Gamepad_B1_A = m_Gamepad.GetRawButton(1);
    Robot_Control_U.Gamepad_B2_B = m_Gamepad.GetRawButton(2);
    Robot_Control_U.Gamepad_B3_X = m_Gamepad.GetRawButton(3);
    Robot_Control_U.Gamepad_B4_Y = m_Gamepad.GetRawButton(4);    
    Robot_Control_U.Gamepad_LB = m_Gamepad.GetRawButton(5);
    Robot_Control_U.Gamepad_RB = m_Gamepad.GetRawButton(6);
    Robot_Control_U.Gamepad_Back = m_Gamepad.GetRawButton(7);
    Robot_Control_U.Gamepad_Start = m_Gamepad.GetRawButton(8);

    Robot_Control_U.Gamepad_POV = m_Gamepad.GetPOV();  // POV = left side D-Pad

    Robot_Control_U.Gamepad_LT = m_Gamepad.GetRawAxis(2);
    Robot_Control_U.Gamepad_RT = m_Gamepad.GetRawAxis(3);

}

void HIDs::PostStepCallback()
{

}