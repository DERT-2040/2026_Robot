//local
#include "include\HIDs.h"

void HIDs::PreStepCallback() {
    // Steer and Drive Joysticks
    Robot_Control_U.Joystick_Left_X = -m_DriverXbox.GetLeftY(); 
    Robot_Control_U.Joystick_Left_Y = -m_DriverXbox.GetLeftX();
    Robot_Control_U.Joystick_Left_Z = 0;

    Robot_Control_U.Joystick_Right_X = -m_DriverXbox.GetRightY();
    Robot_Control_U.Joystick_Right_Y = -m_DriverXbox.GetRightX();
    Robot_Control_U.Joystick_Right_Z = 0;
// left trigger  and right trigger (add those and replace R/L B1)
// B2 maps to Y button (middle and center wall)
// B3 is to X button (side wall)
// B4 is to B button (side wall)
    // Joystick Buttons
    Robot_Control_U.Joystick_Left_B1 = m_DriverXbox.GetRightTriggerAxis(); //m_Left_Joystick.GetRawButton(1);
    Robot_Control_U.Joystick_Left_B2 = m_DriverXbox.GetYButton(); //m_Left_Joystick.GetRawButton(2);            
    Robot_Control_U.Joystick_Left_B3 = m_DriverXbox.GetXButton(); //m_Left_Joystick.GetRawButton(3);           
    Robot_Control_U.Joystick_Left_B4 = m_DriverXbox.GetBButton(); //m_Left_Joystick.GetRawButton(4);   
    Robot_Control_U.Joystick_Left_B5 = m_DriverXbox.GetAButton();; //m_Left_Joystick.GetRawButton(5);
    Robot_Control_U.Joystick_Left_B6 = 0; //m_Left_Joystick.GetRawButton(6);
    Robot_Control_U.Joystick_Left_B7 = 0; //m_Left_Joystick.GetRawButton(7); 
    Robot_Control_U.Joystick_Left_B8 = 0; //m_Left_Joystick.GetRawButton(8);    
    Robot_Control_U.Joystick_Left_B9 = 0; //m_Left_Joystick.GetRawButton(9);
    Robot_Control_U.Joystick_Left_B10 = 0; //m_Left_Joystick.GetRawButton(10);
    Robot_Control_U.Joystick_Left_B11 = 0; //m_Left_Joystick.GetRawButton(11);
    Robot_Control_U.Joystick_Left_B12 = 0; //m_Left_Joystick.GetRawButton(12);
    Robot_Control_U.Joystick_Left_B13 = 0; //m_Left_Joystick.GetRawButton(13);  
    Robot_Control_U.Joystick_Left_B14 = 0; //m_Left_Joystick.GetRawButton(14); 
    Robot_Control_U.Joystick_Left_B15 = 0; //m_Left_Joystick.GetRawButton(15);
    Robot_Control_U.Joystick_Left_B16 = 0; //m_Left_Joystick.GetRawButton(16);
    Robot_Control_U.Joystick_Left_POV = 0; //m_Left_Joystick.GetPOV();    

    Robot_Control_U.Joystick_Right_B1 = m_DriverXbox.GetLeftTriggerAxis(); //m_Right_Joystick.GetRawButton(1);         
    Robot_Control_U.Joystick_Right_B2 = 0; //m_Right_Joystick.GetRawButton(2);    
    Robot_Control_U.Joystick_Right_B3 = 0; //m_Right_Joystick.GetRawButton(3);        
    Robot_Control_U.Joystick_Right_B4 = 0; //m_Right_Joystick.GetRawButton(4);   
    Robot_Control_U.Joystick_Right_B5 = 0; //m_Right_Joystick.GetRawButton(5);
    Robot_Control_U.Joystick_Right_B6 = 0; //m_Right_Joystick.GetRawButton(6);
    Robot_Control_U.Joystick_Right_B7 = 0; //m_Right_Joystick.GetRawButton(7);
    Robot_Control_U.Joystick_Right_B8 = 0; //m_Right_Joystick.GetRawButton(8);  
    Robot_Control_U.Joystick_Right_B9 = 0; //m_Right_Joystick.GetRawButton(9);
    Robot_Control_U.Joystick_Right_B10 = 0; //m_Right_Joystick.GetRawButton(10);
    Robot_Control_U.Joystick_Right_B11 = 0; //m_Right_Joystick.GetRawButton(11);
    Robot_Control_U.Joystick_Right_B12 = 0; //m_Right_Joystick.GetRawButton(12);
    Robot_Control_U.Joystick_Right_B13 = 0; //m_Right_Joystick.GetRawButton(13);
    Robot_Control_U.Joystick_Right_B14 = 0; //m_Right_Joystick.GetRawButton(14);   
    Robot_Control_U.Joystick_Right_B15 = 0; //m_Right_Joystick.GetRawButton(15);
    Robot_Control_U.Joystick_Right_B16 = 0; //m_Right_Joystick.GetRawButton(16);
    Robot_Control_U.Joystick_Right_POV = 0; //m_Right_Joystick.GetPOV();

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