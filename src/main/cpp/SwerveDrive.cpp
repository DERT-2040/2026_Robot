#include "include/SwerveDrive.h"

SwerveDrive::SwerveDrive()
{
  //Wheel Offset
    Initalize_Wheel_Offset();   
    swerveDriveMotors.SetBrakeModeWhenIdle(true); //brake mode
    swerveSteerMotors.SetBrakeModeWhenIdle(true); //brake mode
}
 
void SwerveDrive::PreStepCallback() 
{
  swerveDriveMotors.SendVelocityValuesToSL();
}

void SwerveDrive::PostStepCallback()
{
   /**
   * Wheel calibration procedure:
   * 1. Go into 'Test' game state
   * 2. Push the Disable_Wheels button (Left B13).  This sets steering duty cycle to 0 and puts them into coast mode.
   * 3. Align the wheels with gears facing RIGHT.  If this is done backwards then robot will steer in the opposite directions.
   * 4. Push the Reset_Wheel_Offsets button (Left B12).
   * 5. (optional) Push the Enable_Wheels button (Left B11).  
   */
  if(Robot_Control_Y.Enable_Wheels)
  { // Wheels On
    swerveDriveMotors.SetBrakeModeWhenIdle(true); //brake mode
    swerveSteerMotors.SetBrakeModeWhenIdle(true); //brake mode
  }
  else if(Robot_Control_Y.Disable_Wheels)
  { //Wheels Off
    swerveDriveMotors.Stop();
    swerveSteerMotors.Stop();
    swerveDriveMotors.SetBrakeModeWhenIdle(false); //coast mode
    swerveSteerMotors.SetBrakeModeWhenIdle(false); //coast mode    
  }
  else if(Robot_Control_Y.Reset_Wheel_Offsets)
  { //Recal Wheels
    frc::Preferences::SetDouble(SwerveInfo::k_FrontLeft_Wheel_Offset_Key, Odometry_U.FrontLeft_Steer_Rev);
    frc::Preferences::SetDouble(SwerveInfo::k_FrontRight_Wheel_Offset_Key, Odometry_U.FrontRight_Steer_Rev);
    frc::Preferences::SetDouble(SwerveInfo::k_BackLeft_Wheel_Offset_Key, Odometry_U.BackLeft_Steer_Rev);
    frc::Preferences::SetDouble(SwerveInfo::k_BackRight_Wheel_Offset_Key, Odometry_U.BackRight_Steer_Rev);
    SwerveDrive::Set_Wheel_Offset();
  }

  if(!Robot_Control_Y.Swerve_Motors_Disabled)
  {
    swerveDriveMotors.FetchMotorCommandsFromSL();
    swerveSteerMotors.FetchMotorCommandsFromSL();
  }
}

void SwerveDrive::Initalize_Wheel_Offset() 
{
  if(!frc::Preferences::ContainsKey(SwerveInfo::k_FrontLeft_Wheel_Offset_Key))
    frc::Preferences::SetDouble(SwerveInfo::k_FrontLeft_Wheel_Offset_Key, 0.0);
  if(!frc::Preferences::ContainsKey(SwerveInfo::k_FrontRight_Wheel_Offset_Key))
    frc::Preferences::SetDouble(SwerveInfo::k_FrontRight_Wheel_Offset_Key, 0.0);
  if(!frc::Preferences::ContainsKey(SwerveInfo::k_BackLeft_Wheel_Offset_Key))
    frc::Preferences::SetDouble(SwerveInfo::k_BackLeft_Wheel_Offset_Key, 0.0);
  if(!frc::Preferences::ContainsKey(SwerveInfo::k_BackRight_Wheel_Offset_Key))
    frc::Preferences::SetDouble(SwerveInfo::k_BackRight_Wheel_Offset_Key, 0.0);
  SwerveDrive::Set_Wheel_Offset();
}

void SwerveDrive::Set_Wheel_Offset() 
{
  Odometry_U.BackLeft_Turn_Offset = frc::Preferences::GetDouble(SwerveInfo::k_BackLeft_Wheel_Offset_Key, 0.0);
  Odometry_U.BackRight_Turn_Offset = frc::Preferences::GetDouble(SwerveInfo::k_BackRight_Wheel_Offset_Key, 0.0);
  Odometry_U.FrontLeft_Turn_Offset = frc::Preferences::GetDouble(SwerveInfo::k_FrontLeft_Wheel_Offset_Key, 0.0);
  Odometry_U.FrontRight_Turn_Offset = frc::Preferences::GetDouble(SwerveInfo::k_FrontRight_Wheel_Offset_Key, 0.0);
}

void SwerveDrive::HighFrequencyPreStepCallback()
{
  swerveDriveMotors.SendPositionValuesToSL();
  Odometry_U.FrontLeft_Steer_Rev = m_FrontLeft_Steer_Encoder.GetPosition().GetValue().value();
  Odometry_U.FrontRight_Steer_Rev = m_FrontRight_Steer_Encoder.GetPosition().GetValue().value();
  Odometry_U.BackLeft_Steer_Rev = m_BackLeft_Steer_Encoder.GetPosition().GetValue().value();
  Odometry_U.BackRight_Steer_Rev = m_BackRight_Steer_Encoder.GetPosition().GetValue().value();
}

void SwerveDrive::HighFrequencyPostStepCallback() {}