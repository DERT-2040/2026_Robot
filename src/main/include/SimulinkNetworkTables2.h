// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
// Janelyn <3
#pragma once
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/RawTopic.h>
#include <networktables/NetworkTableInstance.h>
#include "Odometry_ert_rtw\Odometry.h"
#include "DertLib/include/Component.h"
 
class SimulinkNetworkTables2 : public dlib::Component
{
public:
    SimulinkNetworkTables2();
    void PreStepCallback() override ;
    void PostStepCallback() override;
private:
        // Parameters
        nt::NetworkTableEntry P__Auto_Starting_Position__Entry;
        nt::NetworkTableEntry P__Gyro_Calibration_Auto_Center__Entry;
        nt::NetworkTableEntry P__Gyro_Calibration_Auto_Left__Entry;
        nt::NetworkTableEntry P__Gyro_Calibration_Auto_Right__Entry;
        nt::NetworkTableEntry P__Gyro_Calibration_Default__Entry;
        nt::NetworkTableEntry P__Gyro_Calibration_Reset_Flag__Entry;
        nt::NetworkTableEntry P__Odometry_IC_X__Entry;
        nt::NetworkTableEntry P__Odometry_IC_Y__Entry;
        nt::NetworkTableEntry P__Odometry_Reset_IC__Entry;
        nt::NetworkTableEntry P__Odometry_X_Y_TEAR__Entry;
 
        // Inports
        nt::NetworkTableEntry I__BackLeft_Drive_Motor_Rev__Entry;
        nt::NetworkTableEntry I__BackLeft_Steer_Rev__Entry;
        nt::NetworkTableEntry I__BackLeft_Turn_Offset__Entry;
        nt::NetworkTableEntry I__BackRight_Drive_Motor_Rev__Entry;
        nt::NetworkTableEntry I__BackRight_Steer_Rev__Entry;
        nt::NetworkTableEntry I__BackRight_Turn_Offset__Entry;
        nt::NetworkTableEntry I__FrontLeft_Drive_Motor_Rev__Entry;
        nt::NetworkTableEntry I__FrontLeft_Steer_Rev__Entry;
        nt::NetworkTableEntry I__FrontLeft_Turn_Offset__Entry;
        nt::NetworkTableEntry I__FrontRight_Drive_Motor_Rev__Entry;
        nt::NetworkTableEntry I__FrontRight_Steer_Rev__Entry;
        nt::NetworkTableEntry I__FrontRight_Turn_Offset__Entry;
        nt::NetworkTableEntry I__Gyro_Angle__Entry;
        nt::NetworkTableEntry I__IsBlueAlliance__Entry;
        // Outports
        nt::NetworkTableEntry O__Auto_Start_Position__Entry;
        nt::NetworkTableEntry O__BL_Steer_Module_Angle__Entry;
        nt::NetworkTableEntry O__BR_Steer_Module_Angle__Entry;
        nt::NetworkTableEntry O__FL_Steer_Module_Angle__Entry;
        nt::NetworkTableEntry O__FR_Steer_Module_Angle__Entry;
        nt::NetworkTableEntry O__Gyro_Angle_Field_rad__Entry;
        nt::NetworkTableEntry O__Gyro_Angle_rad__Entry;
        nt::NetworkTableEntry O__Odom_Delta_X__Entry;
        nt::NetworkTableEntry O__Odom_Delta_Y__Entry;
        nt::NetworkTableEntry O__Odom_Position_X__Entry;
        nt::NetworkTableEntry O__Odom_Position_Y__Entry;
 
        // Test Points
        nt::NetworkTableEntry T__BL_Steer_Module_Angle__Entry;
        nt::NetworkTableEntry T__BR_Steer_Module_Angle__Entry;
        nt::NetworkTableEntry T__FL_Steer_Module_Angle__Entry;
        nt::NetworkTableEntry T__FR_Steer_Module_Angle__Entry;
        nt::NetworkTableEntry T__Gyro_Angle_Calibrated_deg__Entry;
        nt::NetworkTableEntry T__Gyro_Angle_Field_rad__Entry;
        nt::NetworkTableEntry T__Gyro_Angle_rad__Entry;
        nt::NetworkTableEntry T__Odom_Position_X__Entry;
        nt::NetworkTableEntry T__Odom_Position_Y__Entry;
        nt::NetworkTableEntry T__Odometry_X_global_TEAR_ft__Entry;
        nt::NetworkTableEntry T__Odometry_X_global_est_ft__Entry;
        nt::NetworkTableEntry T__Odometry_Y_global_TEAR_ft__Entry;
        nt::NetworkTableEntry T__Odometry_Y_global_est_ft__Entry;
        nt::NetworkTableEntry T__loop_counter_odometry__Entry;
};
