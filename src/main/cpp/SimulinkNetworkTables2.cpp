// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
// Janelyn <3
#include "include/SimulinkNetworkTables2.h"
 
SimulinkNetworkTables2::SimulinkNetworkTables2()
{
    nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();
    auto NTtable_Tune = NTinst.GetTable("Simulink Tunable Params");
    auto NTtable_Inport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_Outport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_TPoint = NTinst.GetTable("Simulink Test Points");
 
    P__Gyro_Calibration_Default__Entry = NTtable_Tune->GetEntry("Gyro_Calibration_Default");
    NTinst.AddListener(P__Gyro_Calibration_Default__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Gyro_Calibration_Default = event.GetValueEventData()->value.GetDouble();});
    P__Gyro_Calibration_Default__Entry.SetDouble(0);
 
    P__Gyro_Calibration_Reset_Flag__Entry = NTtable_Tune->GetEntry("Gyro_Calibration_Reset_Flag");
    NTinst.AddListener(P__Gyro_Calibration_Reset_Flag__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Gyro_Calibration_Reset_Flag = event.GetValueEventData()->value.GetDouble();});
    P__Gyro_Calibration_Reset_Flag__Entry.SetDouble(0);
 
    P__Odometry_IC_X__Entry = NTtable_Tune->GetEntry("Odometry_IC_X");
    NTinst.AddListener(P__Odometry_IC_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Odometry_IC_X = event.GetValueEventData()->value.GetDouble();});
    P__Odometry_IC_X__Entry.SetDouble(0);
 
    P__Odometry_IC_Y__Entry = NTtable_Tune->GetEntry("Odometry_IC_Y");
    NTinst.AddListener(P__Odometry_IC_Y__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Odometry_IC_Y = event.GetValueEventData()->value.GetDouble();});
    P__Odometry_IC_Y__Entry.SetDouble(0);
 
    P__Odometry_Reset_IC__Entry = NTtable_Tune->GetEntry("Odometry_Reset_IC");
    NTinst.AddListener(P__Odometry_Reset_IC__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Odometry_Reset_IC = event.GetValueEventData()->value.GetDouble();});
    P__Odometry_Reset_IC__Entry.SetDouble(0);
 
    P__Odometry_X_Y_TEAR__Entry = NTtable_Tune->GetEntry("Odometry_X_Y_TEAR");
    NTinst.AddListener(P__Odometry_X_Y_TEAR__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Odometry_X_Y_TEAR = event.GetValueEventData()->value.GetDouble();});
    P__Odometry_X_Y_TEAR__Entry.SetDouble(0);
 
    P__RobotMaxV_GyroReset__Entry = NTtable_Tune->GetEntry("RobotMaxV_GyroReset");
    NTinst.AddListener(P__RobotMaxV_GyroReset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {RobotMaxV_GyroReset = event.GetValueEventData()->value.GetDouble();});
    P__RobotMaxV_GyroReset__Entry.SetDouble(1);
 
// Inports
    I__BackLeft_Drive_Motor_Rev__Entry = NTtable_Inport->GetEntry("BackLeft_Drive_Motor_Rev");
    I__BackLeft_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("BackLeft_Drive_Motor_Speed");
    I__BackLeft_Steer_Rev__Entry = NTtable_Inport->GetEntry("BackLeft_Steer_Rev");
    I__BackLeft_Turn_Offset__Entry = NTtable_Inport->GetEntry("BackLeft_Turn_Offset");
    I__BackRight_Drive_Motor_Rev__Entry = NTtable_Inport->GetEntry("BackRight_Drive_Motor_Rev");
    I__BackRight_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("BackRight_Drive_Motor_Speed");
    I__BackRight_Steer_Rev__Entry = NTtable_Inport->GetEntry("BackRight_Steer_Rev");
    I__BackRight_Turn_Offset__Entry = NTtable_Inport->GetEntry("BackRight_Turn_Offset");
    I__FrontLeft_Drive_Motor_Rev__Entry = NTtable_Inport->GetEntry("FrontLeft_Drive_Motor_Rev");
    I__FrontLeft_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("FrontLeft_Drive_Motor_Speed");
    I__FrontLeft_Steer_Rev__Entry = NTtable_Inport->GetEntry("FrontLeft_Steer_Rev");
    I__FrontLeft_Turn_Offset__Entry = NTtable_Inport->GetEntry("FrontLeft_Turn_Offset");
    I__FrontRight_Drive_Motor_Rev__Entry = NTtable_Inport->GetEntry("FrontRight_Drive_Motor_Rev");
    I__FrontRight_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("FrontRight_Drive_Motor_Speed");
    I__FrontRight_Steer_Rev__Entry = NTtable_Inport->GetEntry("FrontRight_Steer_Rev");
    I__FrontRight_Turn_Offset__Entry = NTtable_Inport->GetEntry("FrontRight_Turn_Offset");
    I__Gyro_Angle__Entry = NTtable_Inport->GetEntry("Gyro_Angle");
    I__IsBlueAlliance__Entry = NTtable_Inport->GetEntry("IsBlueAlliance");
    I__Vision_Gyro_Angle__Entry = NTtable_Inport->GetEntry("Vision_Gyro_Angle");
    I__Vision_Gyro_Angle_Status__Entry = NTtable_Inport->GetEntry("Vision_Gyro_Angle_Status");
 
// Outports
    O__BL_Steer_Module_Angle__Entry = NTtable_Outport->GetEntry("BL_Steer_Module_Angle");
    O__BR_Steer_Module_Angle__Entry = NTtable_Outport->GetEntry("BR_Steer_Module_Angle");
    O__FL_Steer_Module_Angle__Entry = NTtable_Outport->GetEntry("FL_Steer_Module_Angle");
    O__FR_Steer_Module_Angle__Entry = NTtable_Outport->GetEntry("FR_Steer_Module_Angle");
    O__Gyro_Angle_Field_rad__Entry = NTtable_Outport->GetEntry("Gyro_Angle_Field_rad");
    O__Gyro_Angle_rad__Entry = NTtable_Outport->GetEntry("Gyro_Angle_rad");
    O__Odom_Delta_X__Entry = NTtable_Outport->GetEntry("Odom_Delta_X");
    O__Odom_Delta_Y__Entry = NTtable_Outport->GetEntry("Odom_Delta_Y");
    O__Odom_Position_X__Entry = NTtable_Outport->GetEntry("Odom_Position_X");
    O__Odom_Position_Y__Entry = NTtable_Outport->GetEntry("Odom_Position_Y");
    O__Robot_Velocity_X__Entry = NTtable_Outport->GetEntry("Robot_Velocity_X");
    O__Robot_Velocity_Y__Entry = NTtable_Outport->GetEntry("Robot_Velocity_Y");
 
// Test Points
    T__BL_Steer_Module_Angle__Entry = NTtable_TPoint->GetEntry("BL_Steer_Module_Angle");
    T__BR_Steer_Module_Angle__Entry = NTtable_TPoint->GetEntry("BR_Steer_Module_Angle");
    T__FL_Steer_Module_Angle__Entry = NTtable_TPoint->GetEntry("FL_Steer_Module_Angle");
    T__FR_Steer_Module_Angle__Entry = NTtable_TPoint->GetEntry("FR_Steer_Module_Angle");
    T__Gyro_Angle_Calibrated_deg__Entry = NTtable_TPoint->GetEntry("Gyro_Angle_Calibrated_deg");
    T__Gyro_Angle_Field_rad__Entry = NTtable_TPoint->GetEntry("Gyro_Angle_Field_rad");
    T__Gyro_Angle_rad__Entry = NTtable_TPoint->GetEntry("Gyro_Angle_rad");
    T__Odom_Position_X__Entry = NTtable_TPoint->GetEntry("Odom_Position_X");
    T__Odom_Position_Y__Entry = NTtable_TPoint->GetEntry("Odom_Position_Y");
    T__Odometry_X_global_TEAR_ft__Entry = NTtable_TPoint->GetEntry("Odometry_X_global_TEAR_ft");
    T__Odometry_X_global_est_ft__Entry = NTtable_TPoint->GetEntry("Odometry_X_global_est_ft");
    T__Odometry_Y_global_TEAR_ft__Entry = NTtable_TPoint->GetEntry("Odometry_Y_global_TEAR_ft");
    T__Odometry_Y_global_est_ft__Entry = NTtable_TPoint->GetEntry("Odometry_Y_global_est_ft");
    T__loop_counter_odometry__Entry = NTtable_TPoint->GetEntry("loop_counter_odometry");
}
 
void SimulinkNetworkTables2::PreStepCallback() {}
 
void SimulinkNetworkTables2::PostStepCallback()
{
    // Tunable Parameters
    P__Gyro_Calibration_Default__Entry.SetDouble(Gyro_Calibration_Default);
    P__Gyro_Calibration_Reset_Flag__Entry.SetDouble(Gyro_Calibration_Reset_Flag);
    P__Odometry_IC_X__Entry.SetDouble(Odometry_IC_X);
    P__Odometry_IC_Y__Entry.SetDouble(Odometry_IC_Y);
    P__Odometry_Reset_IC__Entry.SetDouble(Odometry_Reset_IC);
    P__Odometry_X_Y_TEAR__Entry.SetDouble(Odometry_X_Y_TEAR);
    P__RobotMaxV_GyroReset__Entry.SetDouble(RobotMaxV_GyroReset);
    // Inports
    I__BackLeft_Drive_Motor_Rev__Entry.SetDouble(Odometry_U.BackLeft_Drive_Motor_Rev);
    I__BackLeft_Drive_Motor_Speed__Entry.SetDouble(Odometry_U.BackLeft_Drive_Motor_Speed);
    I__BackLeft_Steer_Rev__Entry.SetDouble(Odometry_U.BackLeft_Steer_Rev);
    I__BackLeft_Turn_Offset__Entry.SetDouble(Odometry_U.BackLeft_Turn_Offset);
    I__BackRight_Drive_Motor_Rev__Entry.SetDouble(Odometry_U.BackRight_Drive_Motor_Rev);
    I__BackRight_Drive_Motor_Speed__Entry.SetDouble(Odometry_U.BackRight_Drive_Motor_Speed);
    I__BackRight_Steer_Rev__Entry.SetDouble(Odometry_U.BackRight_Steer_Rev);
    I__BackRight_Turn_Offset__Entry.SetDouble(Odometry_U.BackRight_Turn_Offset);
    I__FrontLeft_Drive_Motor_Rev__Entry.SetDouble(Odometry_U.FrontLeft_Drive_Motor_Rev);
    I__FrontLeft_Drive_Motor_Speed__Entry.SetDouble(Odometry_U.FrontLeft_Drive_Motor_Speed);
    I__FrontLeft_Steer_Rev__Entry.SetDouble(Odometry_U.FrontLeft_Steer_Rev);
    I__FrontLeft_Turn_Offset__Entry.SetDouble(Odometry_U.FrontLeft_Turn_Offset);
    I__FrontRight_Drive_Motor_Rev__Entry.SetDouble(Odometry_U.FrontRight_Drive_Motor_Rev);
    I__FrontRight_Drive_Motor_Speed__Entry.SetDouble(Odometry_U.FrontRight_Drive_Motor_Speed);
    I__FrontRight_Steer_Rev__Entry.SetDouble(Odometry_U.FrontRight_Steer_Rev);
    I__FrontRight_Turn_Offset__Entry.SetDouble(Odometry_U.FrontRight_Turn_Offset);
    I__Gyro_Angle__Entry.SetDouble(Odometry_U.Gyro_Angle);
    I__IsBlueAlliance__Entry.SetDouble(Odometry_U.IsBlueAlliance);
    I__Vision_Gyro_Angle__Entry.SetDouble(Odometry_U.Vision_Gyro_Angle);
    I__Vision_Gyro_Angle_Status__Entry.SetDouble(Odometry_U.Vision_Gyro_Angle_Status);
    // Outports
    O__BL_Steer_Module_Angle__Entry.SetDouble(Odometry_Y.BL_Steer_Module_Angle);
    O__BR_Steer_Module_Angle__Entry.SetDouble(Odometry_Y.BR_Steer_Module_Angle);
    O__FL_Steer_Module_Angle__Entry.SetDouble(Odometry_Y.FL_Steer_Module_Angle);
    O__FR_Steer_Module_Angle__Entry.SetDouble(Odometry_Y.FR_Steer_Module_Angle);
    O__Gyro_Angle_Field_rad__Entry.SetDouble(Odometry_Y.Gyro_Angle_Field_rad);
    O__Gyro_Angle_rad__Entry.SetDouble(Odometry_Y.Gyro_Angle_rad);
    O__Odom_Delta_X__Entry.SetDouble(Odometry_Y.Odom_Delta_X);
    O__Odom_Delta_Y__Entry.SetDouble(Odometry_Y.Odom_Delta_Y);
    O__Odom_Position_X__Entry.SetDouble(Odometry_Y.Odom_Position_X);
    O__Odom_Position_Y__Entry.SetDouble(Odometry_Y.Odom_Position_Y);
    O__Robot_Velocity_X__Entry.SetDouble(Odometry_Y.Robot_Velocity_X);
    O__Robot_Velocity_Y__Entry.SetDouble(Odometry_Y.Robot_Velocity_Y);
    // Test Points
    T__BL_Steer_Module_Angle__Entry.SetDouble(Odometry_B.BL_Steer_Module_Angle);
    T__BR_Steer_Module_Angle__Entry.SetDouble(Odometry_B.BR_Steer_Module_Angle);
    T__FL_Steer_Module_Angle__Entry.SetDouble(Odometry_B.FL_Steer_Module_Angle);
    T__FR_Steer_Module_Angle__Entry.SetDouble(Odometry_B.FR_Steer_Module_Angle);
    T__Gyro_Angle_Calibrated_deg__Entry.SetDouble(Odometry_B.Gyro_Angle_Calibrated_deg);
    T__Gyro_Angle_Field_rad__Entry.SetDouble(Odometry_B.Gyro_Angle_Field_rad);
    T__Gyro_Angle_rad__Entry.SetDouble(Odometry_B.Gyro_Angle_rad);
    T__Odom_Position_X__Entry.SetDouble(Odometry_B.Odom_Position_X);
    T__Odom_Position_Y__Entry.SetDouble(Odometry_B.Odom_Position_Y);
    T__Odometry_X_global_TEAR_ft__Entry.SetDouble(Odometry_B.Odometry_X_global_TEAR_ft);
    T__Odometry_X_global_est_ft__Entry.SetDouble(Odometry_B.Odometry_X_global_est_ft);
    T__Odometry_Y_global_TEAR_ft__Entry.SetDouble(Odometry_B.Odometry_Y_global_TEAR_ft);
    T__Odometry_Y_global_est_ft__Entry.SetDouble(Odometry_B.Odometry_Y_global_est_ft);
    T__loop_counter_odometry__Entry.SetDouble(Odometry_B.loop_counter_odometry);
}
// Why are you reading to the bottom of an autogen file?
// Get a life...
