//local
#include "include/Robot.h"

void Robot::RobotInit()
{
  Robot_Control_U.GameState = -1;

  Robot_Control_initialize();
  Odometry_initialize();

  AddPeriodic([&](){
    static size_t HighFrequencyCount = 0;
    if(HighFrequencyCount != 0)
    {
      HighFrequencyPreStep();
      Odometry_step();
      HighFrequencyPostStep();
    }
    if(HighFrequencyCount == 2)
    {
      for (auto group : dlib::TalonFXMotorGroup::allTalonFXMotorGroups)
      {
        group->UpdateMotorCANConnectionAlerts();
      }
      
      for (auto group : dlib::SparkMaxMotorGroup::allSparkMaxMotorGroups)
      {
        group->UpdateMotorCANConnectionAlerts();
      }
    }
    if(HighFrequencyCount == 4)
      HighFrequencyCount = 0;
    else
      HighFrequencyCount++;
  },
  4_ms,
  0_ms);
}
void Robot::DisabledInit()   {Robot_Control_U.GameState = 0;}
void Robot::AutonomousInit() {Robot_Control_U.GameState = 1;}
void Robot::TeleopInit()     {Robot_Control_U.GameState = 2;}
void Robot::TestInit()       {Robot_Control_U.GameState = 3;}
void Robot::SimulationInit() {Robot_Control_U.GameState = 4;}

void Robot::RobotPeriodic() 
{  
  HighFrequencyPreStep();
  Odometry_step();      //Step the model
  HighFrequencyPostStep();

  Odometry_to_Robot_Control_Transfer();

  PreStep();
  Robot_Control_step(); //Step the model
  PostStep();
}

void Robot::Odometry_to_Robot_Control_Transfer()
{
  Robot_Control_U.Gyro_Angle_Field_rad  = Odometry_Y.Gyro_Angle_Field_rad;
  Robot_Control_U.Gyro_Angle_rad        = Odometry_Y.Gyro_Angle_rad;
  Robot_Control_U.FL_Steer_Module_Angle = Odometry_Y.FL_Steer_Module_Angle;
  Robot_Control_U.FR_Steer_Module_Angle = Odometry_Y.FR_Steer_Module_Angle;
  Robot_Control_U.BL_Steer_Module_Angle = Odometry_Y.BL_Steer_Module_Angle;
  Robot_Control_U.BR_Steer_Module_Angle = Odometry_Y.BR_Steer_Module_Angle;
  Robot_Control_U.Odom_Position_X       = Odometry_Y.Odom_Position_X;
  Robot_Control_U.Odom_Position_Y       = Odometry_Y.Odom_Position_Y;
  Robot_Control_U.Odom_Delta_X          = Odometry_Y.Odom_Delta_X;
  Robot_Control_U.Odom_Delta_Y          = Odometry_Y.Odom_Delta_Y;
  Robot_Control_U.Auto_Start_Position   = Odometry_Y.Auto_Start_Position;
}

#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Robot>();
}
#endif