// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
// Janelyn <3
#include "include/SimulinkNetworkTables1.h"
 
SimulinkNetworkTables1::SimulinkNetworkTables1()
{
    nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();
    auto NTtable_Tune = NTinst.GetTable("Simulink Tunable Params");
    auto NTtable_Inport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_Outport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_TPoint = NTinst.GetTable("Simulink Test Points");
 
    P__Boost_Trigger_Decreasing_Limit__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Decreasing_Limit");
    NTinst.AddListener(P__Boost_Trigger_Decreasing_Limit__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Decreasing_Limit = event.GetValueEventData()->value.GetDouble();});
    P__Boost_Trigger_Decreasing_Limit__Entry.SetDouble(-0.28);
 
    P__Boost_Trigger_High_Speed__Entry = NTtable_Tune->GetEntry("Boost_Trigger_High_Speed");
    NTinst.AddListener(P__Boost_Trigger_High_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_High_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Boost_Trigger_High_Speed__Entry.SetDouble(5);
 
    P__Boost_Trigger_Increasing_Limit__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Increasing_Limit");
    NTinst.AddListener(P__Boost_Trigger_Increasing_Limit__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Increasing_Limit = event.GetValueEventData()->value.GetDouble();});
    P__Boost_Trigger_Increasing_Limit__Entry.SetDouble(3.5);
 
    P__Boost_Trigger_Low_Speed__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Low_Speed");
    NTinst.AddListener(P__Boost_Trigger_Low_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Low_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Boost_Trigger_Low_Speed__Entry.SetDouble(1.5);
 
    P__Drive_Motor_Control_D__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_D");
    NTinst.AddListener(P__Drive_Motor_Control_D__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_D = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_D__Entry.SetDouble(0.0001);
 
    P__Drive_Motor_Control_D_FilterCoeff__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_D_FilterCoeff");
    NTinst.AddListener(P__Drive_Motor_Control_D_FilterCoeff__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_D_FilterCoeff = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_D_FilterCoeff__Entry.SetDouble(0.22223);
 
    P__Drive_Motor_Control_D_LL__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_D_LL");
    NTinst.AddListener(P__Drive_Motor_Control_D_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_D_LL = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_D_LL__Entry.SetDouble(-0.2);
 
    P__Drive_Motor_Control_D_UL__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_D_UL");
    NTinst.AddListener(P__Drive_Motor_Control_D_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_D_UL = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_D_UL__Entry.SetDouble(0.2);
 
    P__Drive_Motor_Control_FF__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_FF");
    NTinst.AddListener(P__Drive_Motor_Control_FF__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_FF = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_FF__Entry.SetDouble(0.00016129);
 
    P__Drive_Motor_Control_I__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_I");
    NTinst.AddListener(P__Drive_Motor_Control_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_I = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_I__Entry.SetDouble(1e-06);
 
    P__Drive_Motor_Control_I_LL__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_I_LL");
    NTinst.AddListener(P__Drive_Motor_Control_I_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_I_LL = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_I_LL__Entry.SetDouble(-0.03);
 
    P__Drive_Motor_Control_I_UL__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_I_UL");
    NTinst.AddListener(P__Drive_Motor_Control_I_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_I_UL = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_I_UL__Entry.SetDouble(0.03);
 
    P__Drive_Motor_Control_P__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_P");
    NTinst.AddListener(P__Drive_Motor_Control_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_P = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_P__Entry.SetDouble(5e-06);
 
    P__Drive_Motor_Control_Sign_Change_Deadband__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_Sign_Change_Deadband");
    NTinst.AddListener(P__Drive_Motor_Control_Sign_Change_Deadband__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_Sign_Change_Deadband = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_Sign_Change_Deadband__Entry.SetDouble(7000);
 
    P__Field_Translation_Control_Gain__Entry = NTtable_Tune->GetEntry("Field_Translation_Control_Gain");
    NTinst.AddListener(P__Field_Translation_Control_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Translation_Control_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Field_Translation_Control_Gain__Entry.SetDouble(10);
 
    P__Field_Translation_Speed_Max__Entry = NTtable_Tune->GetEntry("Field_Translation_Speed_Max");
    NTinst.AddListener(P__Field_Translation_Speed_Max__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Translation_Speed_Max = event.GetValueEventData()->value.GetDouble();});
    P__Field_Translation_Speed_Max__Entry.SetDouble(5);
 
    P__KF_Enable__Entry = NTtable_Tune->GetEntry("KF_Enable");
    NTinst.AddListener(P__KF_Enable__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {KF_Enable = event.GetValueEventData()->value.GetDouble();});
    P__KF_Enable__Entry.SetDouble(1);
 
    P__Relative_Steering_Error_Angle_Gain__Entry = NTtable_Tune->GetEntry("Relative_Steering_Error_Angle_Gain");
    NTinst.AddListener(P__Relative_Steering_Error_Angle_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Relative_Steering_Error_Angle_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Relative_Steering_Error_Angle_Gain__Entry.SetDouble(0.05);
 
    P__Relative_Steering_Error_Angle_Gain_Object_Factor__Entry = NTtable_Tune->GetEntry("Relative_Steering_Error_Angle_Gain_Object_Factor");
    NTinst.AddListener(P__Relative_Steering_Error_Angle_Gain_Object_Factor__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Relative_Steering_Error_Angle_Gain_Object_Factor = event.GetValueEventData()->value.GetDouble();});
    P__Relative_Steering_Error_Angle_Gain_Object_Factor__Entry.SetDouble(0.1);
 
    P__Relative_Steering_Speed_Max__Entry = NTtable_Tune->GetEntry("Relative_Steering_Speed_Max");
    NTinst.AddListener(P__Relative_Steering_Speed_Max__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Relative_Steering_Speed_Max = event.GetValueEventData()->value.GetDouble();});
    P__Relative_Steering_Speed_Max__Entry.SetDouble(0.3);
 
    P__Relative_Translation_Control_Gain__Entry = NTtable_Tune->GetEntry("Relative_Translation_Control_Gain");
    NTinst.AddListener(P__Relative_Translation_Control_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Relative_Translation_Control_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Relative_Translation_Control_Gain__Entry.SetDouble(0.05);
 
    P__Relative_Translation_Speed_Max__Entry = NTtable_Tune->GetEntry("Relative_Translation_Speed_Max");
    NTinst.AddListener(P__Relative_Translation_Speed_Max__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Relative_Translation_Speed_Max = event.GetValueEventData()->value.GetDouble();});
    P__Relative_Translation_Speed_Max__Entry.SetDouble(2);
 
    P__Spline_Last_Pose_Distance_to_Velocity_Gain__Entry = NTtable_Tune->GetEntry("Spline_Last_Pose_Distance_to_Velocity_Gain");
    NTinst.AddListener(P__Spline_Last_Pose_Distance_to_Velocity_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Last_Pose_Distance_to_Velocity_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Spline_Last_Pose_Distance_to_Velocity_Gain__Entry.SetDouble(2);
 
    P__Spline_Max_Centripital_Acceleration__Entry = NTtable_Tune->GetEntry("Spline_Max_Centripital_Acceleration");
    NTinst.AddListener(P__Spline_Max_Centripital_Acceleration__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Max_Centripital_Acceleration = event.GetValueEventData()->value.GetDouble();});
    P__Spline_Max_Centripital_Acceleration__Entry.SetDouble(10);
 
    P__Spline_Pose_Num_Before_End_Reduce_Speed__Entry = NTtable_Tune->GetEntry("Spline_Pose_Num_Before_End_Reduce_Speed");
    NTinst.AddListener(P__Spline_Pose_Num_Before_End_Reduce_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Pose_Num_Before_End_Reduce_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Spline_Pose_Num_Before_End_Reduce_Speed__Entry.SetDouble(1);
 
    P__Spline_Stop_Radius__Entry = NTtable_Tune->GetEntry("Spline_Stop_Radius");
    NTinst.AddListener(P__Spline_Stop_Radius__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Stop_Radius = event.GetValueEventData()->value.GetDouble();});
    P__Spline_Stop_Radius__Entry.SetDouble(0.1);
 
    P__Spline_Velocity_Multiplier_TEST__Entry = NTtable_Tune->GetEntry("Spline_Velocity_Multiplier_TEST");
    NTinst.AddListener(P__Spline_Velocity_Multiplier_TEST__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Velocity_Multiplier_TEST = event.GetValueEventData()->value.GetDouble();});
    P__Spline_Velocity_Multiplier_TEST__Entry.SetDouble(1);
 
    P__Steering_Absolute_Cmd_Approach_Zero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Absolute_Cmd_Approach_Zero_Error_Thresh");
    NTinst.AddListener(P__Steering_Absolute_Cmd_Approach_Zero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Absolute_Cmd_Approach_Zero_Error_Thresh__Entry.SetDouble(0.2);
 
    P__Steering_Absolute_Cmd_Approach_Zero_Final_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Absolute_Cmd_Approach_Zero_Final_Thresh");
    NTinst.AddListener(P__Steering_Absolute_Cmd_Approach_Zero_Final_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Absolute_Cmd_Approach_Zero_Final_Thresh__Entry.SetDouble(0.01);
 
    P__Steering_Absolute_Cmd_NonZero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Absolute_Cmd_NonZero_Error_Thresh");
    NTinst.AddListener(P__Steering_Absolute_Cmd_NonZero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Absolute_Cmd_NonZero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Absolute_Cmd_NonZero_Error_Thresh__Entry.SetDouble(0.2);
 
    P__Steering_Absolute_Cmd_NonZero_Final_Scale_Factor__Entry = NTtable_Tune->GetEntry("Steering_Absolute_Cmd_NonZero_Final_Scale_Factor");
    NTinst.AddListener(P__Steering_Absolute_Cmd_NonZero_Final_Scale_Factor__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Absolute_Cmd_NonZero_Final_Scale_Factor__Entry.SetDouble(0.1);
 
    P__Steering_Absolute_Cmd_Rate_Limit_Dec__Entry = NTtable_Tune->GetEntry("Steering_Absolute_Cmd_Rate_Limit_Dec");
    NTinst.AddListener(P__Steering_Absolute_Cmd_Rate_Limit_Dec__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Absolute_Cmd_Rate_Limit_Dec = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Absolute_Cmd_Rate_Limit_Dec__Entry.SetDouble(-1);
 
    P__Steering_Absolute_Cmd_Rate_Limit_Inc__Entry = NTtable_Tune->GetEntry("Steering_Absolute_Cmd_Rate_Limit_Inc");
    NTinst.AddListener(P__Steering_Absolute_Cmd_Rate_Limit_Inc__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Absolute_Cmd_Rate_Limit_Inc = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Absolute_Cmd_Rate_Limit_Inc__Entry.SetDouble(1);
 
    P__Steering_Heading_Control_D__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_D");
    NTinst.AddListener(P__Steering_Heading_Control_D__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_D = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_D__Entry.SetDouble(0);
 
    P__Steering_Heading_Control_D_FilterCoeff__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_D_FilterCoeff");
    NTinst.AddListener(P__Steering_Heading_Control_D_FilterCoeff__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_D_FilterCoeff = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_D_FilterCoeff__Entry.SetDouble(0.22223);
 
    P__Steering_Heading_Control_D_LL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_D_LL");
    NTinst.AddListener(P__Steering_Heading_Control_D_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_D_LL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_D_LL__Entry.SetDouble(0);
 
    P__Steering_Heading_Control_D_UL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_D_UL");
    NTinst.AddListener(P__Steering_Heading_Control_D_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_D_UL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_D_UL__Entry.SetDouble(0);
 
    P__Steering_Heading_Control_Deadzone__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_Deadzone");
    NTinst.AddListener(P__Steering_Heading_Control_Deadzone__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_Deadzone = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_Deadzone__Entry.SetDouble(0.1);
 
    P__Steering_Heading_Control_I__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_I");
    NTinst.AddListener(P__Steering_Heading_Control_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_I = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_I__Entry.SetDouble(0);
 
    P__Steering_Heading_Control_I_LL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_I_LL");
    NTinst.AddListener(P__Steering_Heading_Control_I_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_I_LL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_I_LL__Entry.SetDouble(-0.1);
 
    P__Steering_Heading_Control_I_UL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_I_UL");
    NTinst.AddListener(P__Steering_Heading_Control_I_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_I_UL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_I_UL__Entry.SetDouble(0.1);
 
    P__Steering_Heading_Control_P__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_P");
    NTinst.AddListener(P__Steering_Heading_Control_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_P = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_P__Entry.SetDouble(2.5);
 
    P__Steering_Heading_Control_Total_LL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_Total_LL");
    NTinst.AddListener(P__Steering_Heading_Control_Total_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_Total_LL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_Total_LL__Entry.SetDouble(-2.5);
 
    P__Steering_Heading_Control_Total_UL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_Total_UL");
    NTinst.AddListener(P__Steering_Heading_Control_Total_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_Total_UL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Control_Total_UL__Entry.SetDouble(2.5);
 
    P__Steering_Motor_Control_D__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_D");
    NTinst.AddListener(P__Steering_Motor_Control_D__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_D = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Motor_Control_D__Entry.SetDouble(0.5);
 
    P__Steering_Motor_Control_D_FilterCoeff__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_D_FilterCoeff");
    NTinst.AddListener(P__Steering_Motor_Control_D_FilterCoeff__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_D_FilterCoeff = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Motor_Control_D_FilterCoeff__Entry.SetDouble(0.22223);
 
    P__Steering_Motor_Control_D_LL__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_D_LL");
    NTinst.AddListener(P__Steering_Motor_Control_D_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_D_LL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Motor_Control_D_LL__Entry.SetDouble(-0.2);
 
    P__Steering_Motor_Control_D_UL__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_D_UL");
    NTinst.AddListener(P__Steering_Motor_Control_D_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_D_UL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Motor_Control_D_UL__Entry.SetDouble(0.2);
 
    P__Steering_Motor_Control_I__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_I");
    NTinst.AddListener(P__Steering_Motor_Control_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_I = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Motor_Control_I__Entry.SetDouble(0.005);
 
    P__Steering_Motor_Control_I_LL__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_I_LL");
    NTinst.AddListener(P__Steering_Motor_Control_I_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_I_LL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Motor_Control_I_LL__Entry.SetDouble(-0.005);
 
    P__Steering_Motor_Control_I_UL__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_I_UL");
    NTinst.AddListener(P__Steering_Motor_Control_I_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_I_UL = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Motor_Control_I_UL__Entry.SetDouble(0.005);
 
    P__Steering_Motor_Control_P__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_P");
    NTinst.AddListener(P__Steering_Motor_Control_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_P = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Motor_Control_P__Entry.SetDouble(0.15);
 
    P__Steering_Relative_Cmd_Approach_Zero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Relative_Cmd_Approach_Zero_Error_Thresh");
    NTinst.AddListener(P__Steering_Relative_Cmd_Approach_Zero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Relative_Cmd_Approach_Zero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Relative_Cmd_Approach_Zero_Error_Thresh__Entry.SetDouble(0.2);
 
    P__Steering_Relative_Cmd_Approach_Zero_Final_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Relative_Cmd_Approach_Zero_Final_Thresh");
    NTinst.AddListener(P__Steering_Relative_Cmd_Approach_Zero_Final_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Relative_Cmd_Approach_Zero_Final_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Relative_Cmd_Approach_Zero_Final_Thresh__Entry.SetDouble(0.01);
 
    P__Steering_Relative_Cmd_NonZero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Relative_Cmd_NonZero_Error_Thresh");
    NTinst.AddListener(P__Steering_Relative_Cmd_NonZero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Relative_Cmd_NonZero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Relative_Cmd_NonZero_Error_Thresh__Entry.SetDouble(0.2);
 
    P__Steering_Relative_Cmd_NonZero_Final_Scale_Factor__Entry = NTtable_Tune->GetEntry("Steering_Relative_Cmd_NonZero_Final_Scale_Factor");
    NTinst.AddListener(P__Steering_Relative_Cmd_NonZero_Final_Scale_Factor__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Relative_Cmd_NonZero_Final_Scale_Factor = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Relative_Cmd_NonZero_Final_Scale_Factor__Entry.SetDouble(1);
 
    P__Steering_Relative_Cmd_Rate_Limit_Dec__Entry = NTtable_Tune->GetEntry("Steering_Relative_Cmd_Rate_Limit_Dec");
    NTinst.AddListener(P__Steering_Relative_Cmd_Rate_Limit_Dec__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Relative_Cmd_Rate_Limit_Dec = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Relative_Cmd_Rate_Limit_Dec__Entry.SetDouble(-10);
 
    P__Steering_Relative_Cmd_Rate_Limit_Inc__Entry = NTtable_Tune->GetEntry("Steering_Relative_Cmd_Rate_Limit_Inc");
    NTinst.AddListener(P__Steering_Relative_Cmd_Rate_Limit_Inc__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Relative_Cmd_Rate_Limit_Inc = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Relative_Cmd_Rate_Limit_Inc__Entry.SetDouble(10);
 
    P__Steering_Relative_Gain__Entry = NTtable_Tune->GetEntry("Steering_Relative_Gain");
    NTinst.AddListener(P__Steering_Relative_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Relative_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Relative_Gain__Entry.SetDouble(5);
 
    P__Steering_Twist_Gain__Entry = NTtable_Tune->GetEntry("Steering_Twist_Gain");
    NTinst.AddListener(P__Steering_Twist_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Twist_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Twist_Gain__Entry.SetDouble(-0.5);
 
    P__TEST_Pipeline__Entry = NTtable_Tune->GetEntry("TEST_Pipeline");
    NTinst.AddListener(P__TEST_Pipeline__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Pipeline = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Pipeline__Entry.SetDouble(0);
 
    P__TEST_Swerve_Mode_Override_Flag__Entry = NTtable_Tune->GetEntry("TEST_Swerve_Mode_Override_Flag");
    NTinst.AddListener(P__TEST_Swerve_Mode_Override_Flag__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Swerve_Mode_Override_Flag = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Swerve_Mode_Override_Flag__Entry.SetDouble(0);
 
    P__TEST_Swerve_Mode_Steering__Entry = NTtable_Tune->GetEntry("TEST_Swerve_Mode_Steering");
    NTinst.AddListener(P__TEST_Swerve_Mode_Steering__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Swerve_Mode_Steering = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Swerve_Mode_Steering__Entry.SetDouble(0);
 
    P__TEST_Swerve_Mode_Translation__Entry = NTtable_Tune->GetEntry("TEST_Swerve_Mode_Translation");
    NTinst.AddListener(P__TEST_Swerve_Mode_Translation__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Swerve_Mode_Translation = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Swerve_Mode_Translation__Entry.SetDouble(0);
 
    P__Translation_Speed_Approach_Zero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Translation_Speed_Approach_Zero_Error_Thresh");
    NTinst.AddListener(P__Translation_Speed_Approach_Zero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_Approach_Zero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Translation_Speed_Approach_Zero_Error_Thresh__Entry.SetDouble(0.2);
 
    P__Translation_Speed_Approach_Zero_Final_Thresh__Entry = NTtable_Tune->GetEntry("Translation_Speed_Approach_Zero_Final_Thresh");
    NTinst.AddListener(P__Translation_Speed_Approach_Zero_Final_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_Approach_Zero_Final_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Translation_Speed_Approach_Zero_Final_Thresh__Entry.SetDouble(0.01);
 
    P__Translation_Speed_NonZero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Translation_Speed_NonZero_Error_Thresh");
    NTinst.AddListener(P__Translation_Speed_NonZero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_NonZero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Translation_Speed_NonZero_Error_Thresh__Entry.SetDouble(0.15);
 
    P__Translation_Speed_NonZero_Final_Scale_Factor__Entry = NTtable_Tune->GetEntry("Translation_Speed_NonZero_Final_Scale_Factor");
    NTinst.AddListener(P__Translation_Speed_NonZero_Final_Scale_Factor__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_NonZero_Final_Scale_Factor = event.GetValueEventData()->value.GetDouble();});
    P__Translation_Speed_NonZero_Final_Scale_Factor__Entry.SetDouble(0.05);
 
    P__Translation_Speed_Rate_Limit_Dec__Entry = NTtable_Tune->GetEntry("Translation_Speed_Rate_Limit_Dec");
    NTinst.AddListener(P__Translation_Speed_Rate_Limit_Dec__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_Rate_Limit_Dec = event.GetValueEventData()->value.GetDouble();});
    P__Translation_Speed_Rate_Limit_Dec__Entry.SetDouble(-4);
 
    P__Translation_Speed_Rate_Limit_Inc__Entry = NTtable_Tune->GetEntry("Translation_Speed_Rate_Limit_Inc");
    NTinst.AddListener(P__Translation_Speed_Rate_Limit_Inc__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_Rate_Limit_Inc = event.GetValueEventData()->value.GetDouble();});
    P__Translation_Speed_Rate_Limit_Inc__Entry.SetDouble(4);
 
    P__Translation_Twist_Gain__Entry = NTtable_Tune->GetEntry("Translation_Twist_Gain");
    NTinst.AddListener(P__Translation_Twist_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Twist_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Translation_Twist_Gain__Entry.SetDouble(-0.5);
 
    P__Twist_Deadzone_neg__Entry = NTtable_Tune->GetEntry("Twist_Deadzone_neg");
    NTinst.AddListener(P__Twist_Deadzone_neg__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Twist_Deadzone_neg = event.GetValueEventData()->value.GetDouble();});
    P__Twist_Deadzone_neg__Entry.SetDouble(-0.01);
 
    P__Twist_Deadzone_pos__Entry = NTtable_Tune->GetEntry("Twist_Deadzone_pos");
    NTinst.AddListener(P__Twist_Deadzone_pos__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Twist_Deadzone_pos = event.GetValueEventData()->value.GetDouble();});
    P__Twist_Deadzone_pos__Entry.SetDouble(0.01);
 
    P__Vision_Object_Angle_Offset__Entry = NTtable_Tune->GetEntry("Vision_Object_Angle_Offset");
    NTinst.AddListener(P__Vision_Object_Angle_Offset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Object_Angle_Offset = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Object_Angle_Offset__Entry.SetDouble(0);
 
    P__Vision_Object_Target_Angle__Entry = NTtable_Tune->GetEntry("Vision_Object_Target_Angle");
    NTinst.AddListener(P__Vision_Object_Target_Angle__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Object_Target_Angle = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Object_Target_Angle__Entry.SetDouble(0);
 
    P__Vision_Object_Target_X__Entry = NTtable_Tune->GetEntry("Vision_Object_Target_X");
    NTinst.AddListener(P__Vision_Object_Target_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Object_Target_X = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Object_Target_X__Entry.SetDouble(35);
 
    P__Vision_Object_Target_Y__Entry = NTtable_Tune->GetEntry("Vision_Object_Target_Y");
    NTinst.AddListener(P__Vision_Object_Target_Y__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Object_Target_Y = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Object_Target_Y__Entry.SetDouble(0);
 
    P__Vision_Object_X_Offset__Entry = NTtable_Tune->GetEntry("Vision_Object_X_Offset");
    NTinst.AddListener(P__Vision_Object_X_Offset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Object_X_Offset = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Object_X_Offset__Entry.SetDouble(0);
 
    P__Vision_Object_Y_Offset__Entry = NTtable_Tune->GetEntry("Vision_Object_Y_Offset");
    NTinst.AddListener(P__Vision_Object_Y_Offset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Object_Y_Offset = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Object_Y_Offset__Entry.SetDouble(0);
 
    P__Vision_Tag_Angle_Offset__Entry = NTtable_Tune->GetEntry("Vision_Tag_Angle_Offset");
    NTinst.AddListener(P__Vision_Tag_Angle_Offset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Tag_Angle_Offset = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Tag_Angle_Offset__Entry.SetDouble(0);
 
    P__Vision_Tag_Target_Angle__Entry = NTtable_Tune->GetEntry("Vision_Tag_Target_Angle");
    NTinst.AddListener(P__Vision_Tag_Target_Angle__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Tag_Target_Angle = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Tag_Target_Angle__Entry.SetDouble(0);
 
    P__Vision_Tag_Target_X__Entry = NTtable_Tune->GetEntry("Vision_Tag_Target_X");
    NTinst.AddListener(P__Vision_Tag_Target_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Tag_Target_X = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Tag_Target_X__Entry.SetDouble(30);
 
    P__Vision_Tag_Target_Y__Entry = NTtable_Tune->GetEntry("Vision_Tag_Target_Y");
    NTinst.AddListener(P__Vision_Tag_Target_Y__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Tag_Target_Y = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Tag_Target_Y__Entry.SetDouble(0);
 
    P__Vision_Tag_X_Offset__Entry = NTtable_Tune->GetEntry("Vision_Tag_X_Offset");
    NTinst.AddListener(P__Vision_Tag_X_Offset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Tag_X_Offset = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Tag_X_Offset__Entry.SetDouble(0);
 
    P__Vision_Tag_Y_Offset__Entry = NTtable_Tune->GetEntry("Vision_Tag_Y_Offset");
    NTinst.AddListener(P__Vision_Tag_Y_Offset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Vision_Tag_Y_Offset = event.GetValueEventData()->value.GetDouble();});
    P__Vision_Tag_Y_Offset__Entry.SetDouble(0);
 
// Inports
    I__Auto_Start_Position__Entry = NTtable_Inport->GetEntry("Auto_Start_Position");
    I__BL_Steer_Module_Angle__Entry = NTtable_Inport->GetEntry("BL_Steer_Module_Angle");
    I__BR_Steer_Module_Angle__Entry = NTtable_Inport->GetEntry("BR_Steer_Module_Angle");
    I__BackLeft_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("BackLeft_Drive_Motor_Speed");
    I__BackRight_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("BackRight_Drive_Motor_Speed");
    I__FL_Steer_Module_Angle__Entry = NTtable_Inport->GetEntry("FL_Steer_Module_Angle");
    I__FR_Steer_Module_Angle__Entry = NTtable_Inport->GetEntry("FR_Steer_Module_Angle");
    I__FrontLeft_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("FrontLeft_Drive_Motor_Speed");
    I__FrontRight_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("FrontRight_Drive_Motor_Speed");
    I__GameState__Entry = NTtable_Inport->GetEntry("GameState");
    I__Gamepad_B1_A__Entry = NTtable_Inport->GetEntry("Gamepad_B1_A");
    I__Gamepad_B2_B__Entry = NTtable_Inport->GetEntry("Gamepad_B2_B");
    I__Gamepad_B3_X__Entry = NTtable_Inport->GetEntry("Gamepad_B3_X");
    I__Gamepad_B4_Y__Entry = NTtable_Inport->GetEntry("Gamepad_B4_Y");
    I__Gamepad_Back__Entry = NTtable_Inport->GetEntry("Gamepad_Back");
    I__Gamepad_LB__Entry = NTtable_Inport->GetEntry("Gamepad_LB");
    I__Gamepad_LT__Entry = NTtable_Inport->GetEntry("Gamepad_LT");
    I__Gamepad_POV__Entry = NTtable_Inport->GetEntry("Gamepad_POV");
    I__Gamepad_RB__Entry = NTtable_Inport->GetEntry("Gamepad_RB");
    I__Gamepad_RT__Entry = NTtable_Inport->GetEntry("Gamepad_RT");
    I__Gamepad_Start__Entry = NTtable_Inport->GetEntry("Gamepad_Start");
    I__Gamepad_Stick_Left_X__Entry = NTtable_Inport->GetEntry("Gamepad_Stick_Left_X");
    I__Gamepad_Stick_Left_Y__Entry = NTtable_Inport->GetEntry("Gamepad_Stick_Left_Y");
    I__Gamepad_Stick_Right_X__Entry = NTtable_Inport->GetEntry("Gamepad_Stick_Right_X");
    I__Gamepad_Stick_Right_Y__Entry = NTtable_Inport->GetEntry("Gamepad_Stick_Right_Y");
    I__Gyro_Angle_Field_rad__Entry = NTtable_Inport->GetEntry("Gyro_Angle_Field_rad");
    I__Gyro_Angle_rad__Entry = NTtable_Inport->GetEntry("Gyro_Angle_rad");
    I__IsBlueAlliance__Entry = NTtable_Inport->GetEntry("IsBlueAlliance");
    I__Joystick_Left_B1__Entry = NTtable_Inport->GetEntry("Joystick_Left_B1");
    I__Joystick_Left_B10__Entry = NTtable_Inport->GetEntry("Joystick_Left_B10");
    I__Joystick_Left_B11__Entry = NTtable_Inport->GetEntry("Joystick_Left_B11");
    I__Joystick_Left_B12__Entry = NTtable_Inport->GetEntry("Joystick_Left_B12");
    I__Joystick_Left_B13__Entry = NTtable_Inport->GetEntry("Joystick_Left_B13");
    I__Joystick_Left_B14__Entry = NTtable_Inport->GetEntry("Joystick_Left_B14");
    I__Joystick_Left_B15__Entry = NTtable_Inport->GetEntry("Joystick_Left_B15");
    I__Joystick_Left_B16__Entry = NTtable_Inport->GetEntry("Joystick_Left_B16");
    I__Joystick_Left_B2__Entry = NTtable_Inport->GetEntry("Joystick_Left_B2");
    I__Joystick_Left_B3__Entry = NTtable_Inport->GetEntry("Joystick_Left_B3");
    I__Joystick_Left_B4__Entry = NTtable_Inport->GetEntry("Joystick_Left_B4");
    I__Joystick_Left_B5__Entry = NTtable_Inport->GetEntry("Joystick_Left_B5");
    I__Joystick_Left_B6__Entry = NTtable_Inport->GetEntry("Joystick_Left_B6");
    I__Joystick_Left_B7__Entry = NTtable_Inport->GetEntry("Joystick_Left_B7");
    I__Joystick_Left_B8__Entry = NTtable_Inport->GetEntry("Joystick_Left_B8");
    I__Joystick_Left_B9__Entry = NTtable_Inport->GetEntry("Joystick_Left_B9");
    I__Joystick_Left_POV__Entry = NTtable_Inport->GetEntry("Joystick_Left_POV");
    I__Joystick_Left_X__Entry = NTtable_Inport->GetEntry("Joystick_Left_X");
    I__Joystick_Left_Y__Entry = NTtable_Inport->GetEntry("Joystick_Left_Y");
    I__Joystick_Left_Z__Entry = NTtable_Inport->GetEntry("Joystick_Left_Z");
    I__Joystick_Right_B1__Entry = NTtable_Inport->GetEntry("Joystick_Right_B1");
    I__Joystick_Right_B10__Entry = NTtable_Inport->GetEntry("Joystick_Right_B10");
    I__Joystick_Right_B11__Entry = NTtable_Inport->GetEntry("Joystick_Right_B11");
    I__Joystick_Right_B12__Entry = NTtable_Inport->GetEntry("Joystick_Right_B12");
    I__Joystick_Right_B13__Entry = NTtable_Inport->GetEntry("Joystick_Right_B13");
    I__Joystick_Right_B14__Entry = NTtable_Inport->GetEntry("Joystick_Right_B14");
    I__Joystick_Right_B15__Entry = NTtable_Inport->GetEntry("Joystick_Right_B15");
    I__Joystick_Right_B16__Entry = NTtable_Inport->GetEntry("Joystick_Right_B16");
    I__Joystick_Right_B2__Entry = NTtable_Inport->GetEntry("Joystick_Right_B2");
    I__Joystick_Right_B3__Entry = NTtable_Inport->GetEntry("Joystick_Right_B3");
    I__Joystick_Right_B4__Entry = NTtable_Inport->GetEntry("Joystick_Right_B4");
    I__Joystick_Right_B5__Entry = NTtable_Inport->GetEntry("Joystick_Right_B5");
    I__Joystick_Right_B6__Entry = NTtable_Inport->GetEntry("Joystick_Right_B6");
    I__Joystick_Right_B7__Entry = NTtable_Inport->GetEntry("Joystick_Right_B7");
    I__Joystick_Right_B8__Entry = NTtable_Inport->GetEntry("Joystick_Right_B8");
    I__Joystick_Right_B9__Entry = NTtable_Inport->GetEntry("Joystick_Right_B9");
    I__Joystick_Right_POV__Entry = NTtable_Inport->GetEntry("Joystick_Right_POV");
    I__Joystick_Right_X__Entry = NTtable_Inport->GetEntry("Joystick_Right_X");
    I__Joystick_Right_Y__Entry = NTtable_Inport->GetEntry("Joystick_Right_Y");
    I__Joystick_Right_Z__Entry = NTtable_Inport->GetEntry("Joystick_Right_Z");
    I__MatchTime__Entry = NTtable_Inport->GetEntry("MatchTime");
    I__Odom_Delta_X__Entry = NTtable_Inport->GetEntry("Odom_Delta_X");
    I__Odom_Delta_Y__Entry = NTtable_Inport->GetEntry("Odom_Delta_Y");
    I__Odom_Position_X__Entry = NTtable_Inport->GetEntry("Odom_Position_X");
    I__Odom_Position_Y__Entry = NTtable_Inport->GetEntry("Odom_Position_Y");
    I__Vision_Current_Pipeline__Entry = NTtable_Inport->GetEntry("Vision_Current_Pipeline");
    I__Vision_Num_Tags_Detected__Entry = NTtable_Inport->GetEntry("Vision_Num_Tags_Detected");
    I__Vision_RobotPoseFieldSpace_X__Entry = NTtable_Inport->GetEntry("Vision_RobotPoseFieldSpace_X");
    I__Vision_RobotPoseFieldSpace_Y__Entry = NTtable_Inport->GetEntry("Vision_RobotPoseFieldSpace_Y");
    I__Vision_c1_AprilTag_Valid__Entry = NTtable_Inport->GetEntry("Vision_c1_AprilTag_Valid");
    I__Vision_c1_AprilTag_X_m__Entry = NTtable_Inport->GetEntry("Vision_c1_AprilTag_X_m");
    I__Vision_c1_AprilTag_Y_m__Entry = NTtable_Inport->GetEntry("Vision_c1_AprilTag_Y_m");
    I__Vision_c1_AprilTag_Yaw_deg__Entry = NTtable_Inport->GetEntry("Vision_c1_AprilTag_Yaw_deg");
    I__Vision_c1_Object_Area_pct__Entry = NTtable_Inport->GetEntry("Vision_c1_Object_Area_pct");
    I__Vision_c1_Object_Hor_deg__Entry = NTtable_Inport->GetEntry("Vision_c1_Object_Hor_deg");
    I__Vision_c1_Object_Valid__Entry = NTtable_Inport->GetEntry("Vision_c1_Object_Valid");
    I__Vision_c1_Object_Ver_deg__Entry = NTtable_Inport->GetEntry("Vision_c1_Object_Ver_deg");
 
// Outports
    O__BackLeft_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("BackLeft_Drive_DutyCycle");
    O__BackLeft_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("BackLeft_Steer_DutyCycle");
    O__BackRight_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("BackRight_Drive_DutyCycle");
    O__BackRight_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("BackRight_Steer_DutyCycle");
    O__Disable_Wheels__Entry = NTtable_Outport->GetEntry("Disable_Wheels");
    O__Enable_Wheels__Entry = NTtable_Outport->GetEntry("Enable_Wheels");
    O__FrontLeft_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontLeft_Drive_DutyCycle");
    O__FrontLeft_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontLeft_Steer_DutyCycle");
    O__FrontRight_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontRight_Drive_DutyCycle");
    O__FrontRight_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontRight_Steer_DutyCycle");
    O__Reset_Wheel_Offsets__Entry = NTtable_Outport->GetEntry("Reset_Wheel_Offsets");
    O__Swerve_Motors_Disabled__Entry = NTtable_Outport->GetEntry("Swerve_Motors_Disabled");
    O__Vision_Desired_Pipeline__Entry = NTtable_Outport->GetEntry("Vision_Desired_Pipeline");
 
// Test Points
    T__Active_GameState__Entry = NTtable_TPoint->GetEntry("Active_GameState");
    T__Actuator_Cmd__Entry = NTtable_TPoint->GetEntry("Actuator_Cmd");
    T__Align_Center__Entry = NTtable_TPoint->GetEntry("Align_Center");
    T__Align_Left__Entry = NTtable_TPoint->GetEntry("Align_Left");
    T__Align_Right__Entry = NTtable_TPoint->GetEntry("Align_Right");
    T__BL_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("BL_Desired_Module_Angle");
    T__BL_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("BL_Desired_Wheel_Speed");
    T__BL_Desired_Wheel_Speed_in__Entry = NTtable_TPoint->GetEntry("BL_Desired_Wheel_Speed_in");
    T__BR_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("BR_Desired_Module_Angle");
    T__BR_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("BR_Desired_Wheel_Speed");
    T__BR_Desired_Wheel_Speed_in__Entry = NTtable_TPoint->GetEntry("BR_Desired_Wheel_Speed_in");
    T__Button_Disable_Wheels__Entry = NTtable_TPoint->GetEntry("Button_Disable_Wheels");
    T__Button_Enable_Wheels__Entry = NTtable_TPoint->GetEntry("Button_Enable_Wheels");
    T__Button_Reset_Wheel_Offsets__Entry = NTtable_TPoint->GetEntry("Button_Reset_Wheel_Offsets");
    T__Drive_Engage_Hook__Entry = NTtable_TPoint->GetEntry("Drive_Engage_Hook");
    T__Drive_Joystick_X__Entry = NTtable_TPoint->GetEntry("Drive_Joystick_X");
    T__Drive_Joystick_Y__Entry = NTtable_TPoint->GetEntry("Drive_Joystick_Y");
    T__Drive_Joystick_Z__Entry = NTtable_TPoint->GetEntry("Drive_Joystick_Z");
    T__Drive_Joystick_Z_Mode__Entry = NTtable_TPoint->GetEntry("Drive_Joystick_Z_Mode");
    T__FL_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("FL_Desired_Module_Angle");
    T__FL_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("FL_Desired_Wheel_Speed");
    T__FL_Desired_Wheel_Speed_in__Entry = NTtable_TPoint->GetEntry("FL_Desired_Wheel_Speed_in");
    T__FR_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("FR_Desired_Module_Angle");
    T__FR_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("FR_Desired_Wheel_Speed");
    T__FR_Desired_Wheel_Speed_in__Entry = NTtable_TPoint->GetEntry("FR_Desired_Wheel_Speed_in");
    T__Face_Away_Driver__Entry = NTtable_TPoint->GetEntry("Face_Away_Driver");
    T__Face_Left_Driver__Entry = NTtable_TPoint->GetEntry("Face_Left_Driver");
    T__Face_Right_Driver__Entry = NTtable_TPoint->GetEntry("Face_Right_Driver");
    T__Face_Toward_Driver__Entry = NTtable_TPoint->GetEntry("Face_Toward_Driver");
    T__Gamepad_POV_Down__Entry = NTtable_TPoint->GetEntry("Gamepad_POV_Down");
    T__Gamepad_POV_Left__Entry = NTtable_TPoint->GetEntry("Gamepad_POV_Left");
    T__Gamepad_POV_Right__Entry = NTtable_TPoint->GetEntry("Gamepad_POV_Right");
    T__Gamepad_POV_Up__Entry = NTtable_TPoint->GetEntry("Gamepad_POV_Up");
    T__Gyro_Angle_SPF__Entry = NTtable_TPoint->GetEntry("Gyro_Angle_SPF");
    T__Is_Absolute_Steering_SPF__Entry = NTtable_TPoint->GetEntry("Is_Absolute_Steering_SPF");
    T__Is_Absolute_Translation_SPF__Entry = NTtable_TPoint->GetEntry("Is_Absolute_Translation_SPF");
    T__Is_Boosting__Entry = NTtable_TPoint->GetEntry("Is_Boosting");
    T__KF_Position_X__Entry = NTtable_TPoint->GetEntry("KF_Position_X");
    T__KF_Position_Y__Entry = NTtable_TPoint->GetEntry("KF_Position_Y");
    T__Relative_Enable__Entry = NTtable_TPoint->GetEntry("Relative_Enable");
    T__Relative_Error_Angle__Entry = NTtable_TPoint->GetEntry("Relative_Error_Angle");
    T__Relative_Error_X__Entry = NTtable_TPoint->GetEntry("Relative_Error_X");
    T__Relative_Error_Y__Entry = NTtable_TPoint->GetEntry("Relative_Error_Y");
    T__Robot_Reached_Destination__Entry = NTtable_TPoint->GetEntry("Robot_Reached_Destination");
    T__Spline_Enable__Entry = NTtable_TPoint->GetEntry("Spline_Enable");
    T__Spline_Follow_Index__Entry = NTtable_TPoint->GetEntry("Spline_Follow_Index");
    T__Spline_Num_Poses__Entry = NTtable_TPoint->GetEntry("Spline_Num_Poses");
    T__Spline_Out_Of_Bounds__Entry = NTtable_TPoint->GetEntry("Spline_Out_Of_Bounds");
    T__Spline_Target_X__Entry = NTtable_TPoint->GetEntry("Spline_Target_X");
    T__Spline_Target_Y__Entry = NTtable_TPoint->GetEntry("Spline_Target_Y");
    T__Steer_Joystick_X__Entry = NTtable_TPoint->GetEntry("Steer_Joystick_X");
    T__Steer_Joystick_Y__Entry = NTtable_TPoint->GetEntry("Steer_Joystick_Y");
    T__Steer_Joystick_Z__Entry = NTtable_TPoint->GetEntry("Steer_Joystick_Z");
    T__Steering_Abs_Angle__Entry = NTtable_TPoint->GetEntry("Steering_Abs_Angle");
    T__Steering_Abs_Angle_Active__Entry = NTtable_TPoint->GetEntry("Steering_Abs_Angle_Active");
    T__Steering_Abs_Cmd__Entry = NTtable_TPoint->GetEntry("Steering_Abs_Cmd");
    T__Steering_Abs_Cmd_SPF__Entry = NTtable_TPoint->GetEntry("Steering_Abs_Cmd_SPF");
    T__Steering_Abs_Gyro__Entry = NTtable_TPoint->GetEntry("Steering_Abs_Gyro");
    T__Steering_Abs_Gyro_Latch__Entry = NTtable_TPoint->GetEntry("Steering_Abs_Gyro_Latch");
    T__Steering_Localized_Cmd__Entry = NTtable_TPoint->GetEntry("Steering_Localized_Cmd");
    T__Steering_Localized_PID__Entry = NTtable_TPoint->GetEntry("Steering_Localized_PID");
    T__Steering_Rel_Cmd__Entry = NTtable_TPoint->GetEntry("Steering_Rel_Cmd");
    T__Steering_Rel_Cmd_SPF__Entry = NTtable_TPoint->GetEntry("Steering_Rel_Cmd_SPF");
    T__Swerve_Drive_Integral_Enable__Entry = NTtable_TPoint->GetEntry("Swerve_Drive_Integral_Enable");
    T__Test_Mode__Entry = NTtable_TPoint->GetEntry("Test_Mode");
    T__Translation_Angle__Entry = NTtable_TPoint->GetEntry("Translation_Angle");
    T__Translation_Angle_SPF__Entry = NTtable_TPoint->GetEntry("Translation_Angle_SPF");
    T__Translation_Speed__Entry = NTtable_TPoint->GetEntry("Translation_Speed");
    T__Translation_Speed_RL__Entry = NTtable_TPoint->GetEntry("Translation_Speed_RL");
    T__Translation_Speed_SPF__Entry = NTtable_TPoint->GetEntry("Translation_Speed_SPF");
    T__Translation_Steering_Cmd__Entry = NTtable_TPoint->GetEntry("Translation_Steering_Cmd");
    T__Vision_c1_AprilTag_Corr_X_inch__Entry = NTtable_TPoint->GetEntry("Vision_c1_AprilTag_Corr_X_inch");
    T__Vision_c1_AprilTag_Corr_Y_inch__Entry = NTtable_TPoint->GetEntry("Vision_c1_AprilTag_Corr_Y_inch");
    T__Vision_c1_AprilTag_Corr_Yaw_deg__Entry = NTtable_TPoint->GetEntry("Vision_c1_AprilTag_Corr_Yaw_deg");
    T__Vision_c1_Object_Corr_X_inch__Entry = NTtable_TPoint->GetEntry("Vision_c1_Object_Corr_X_inch");
    T__Vision_c1_Object_Corr_Y_inch__Entry = NTtable_TPoint->GetEntry("Vision_c1_Object_Corr_Y_inch");
    T__Vision_c1_Object_Corr_Yaw_deg__Entry = NTtable_TPoint->GetEntry("Vision_c1_Object_Corr_Yaw_deg");
    T__Winch_Cmd__Entry = NTtable_TPoint->GetEntry("Winch_Cmd");
    T__loop_counter_robot_control__Entry = NTtable_TPoint->GetEntry("loop_counter_robot_control");
}
 
void SimulinkNetworkTables1::PreStepCallback() {}
 
void SimulinkNetworkTables1::PostStepCallback()
{
    // Tunable Parameters
    P__Boost_Trigger_Decreasing_Limit__Entry.SetDouble(Boost_Trigger_Decreasing_Limit);
    P__Boost_Trigger_High_Speed__Entry.SetDouble(Boost_Trigger_High_Speed);
    P__Boost_Trigger_Increasing_Limit__Entry.SetDouble(Boost_Trigger_Increasing_Limit);
    P__Boost_Trigger_Low_Speed__Entry.SetDouble(Boost_Trigger_Low_Speed);
    P__Drive_Motor_Control_D__Entry.SetDouble(Drive_Motor_Control_D);
    P__Drive_Motor_Control_D_FilterCoeff__Entry.SetDouble(Drive_Motor_Control_D_FilterCoeff);
    P__Drive_Motor_Control_D_LL__Entry.SetDouble(Drive_Motor_Control_D_LL);
    P__Drive_Motor_Control_D_UL__Entry.SetDouble(Drive_Motor_Control_D_UL);
    P__Drive_Motor_Control_FF__Entry.SetDouble(Drive_Motor_Control_FF);
    P__Drive_Motor_Control_I__Entry.SetDouble(Drive_Motor_Control_I);
    P__Drive_Motor_Control_I_LL__Entry.SetDouble(Drive_Motor_Control_I_LL);
    P__Drive_Motor_Control_I_UL__Entry.SetDouble(Drive_Motor_Control_I_UL);
    P__Drive_Motor_Control_P__Entry.SetDouble(Drive_Motor_Control_P);
    P__Drive_Motor_Control_Sign_Change_Deadband__Entry.SetDouble(Drive_Motor_Control_Sign_Change_Deadband);
    P__Field_Translation_Control_Gain__Entry.SetDouble(Field_Translation_Control_Gain);
    P__Field_Translation_Speed_Max__Entry.SetDouble(Field_Translation_Speed_Max);
    P__KF_Enable__Entry.SetDouble(KF_Enable);
    P__Relative_Steering_Error_Angle_Gain__Entry.SetDouble(Relative_Steering_Error_Angle_Gain);
    P__Relative_Steering_Error_Angle_Gain_Object_Factor__Entry.SetDouble(Relative_Steering_Error_Angle_Gain_Object_Factor);
    P__Relative_Steering_Speed_Max__Entry.SetDouble(Relative_Steering_Speed_Max);
    P__Relative_Translation_Control_Gain__Entry.SetDouble(Relative_Translation_Control_Gain);
    P__Relative_Translation_Speed_Max__Entry.SetDouble(Relative_Translation_Speed_Max);
    P__Spline_Last_Pose_Distance_to_Velocity_Gain__Entry.SetDouble(Spline_Last_Pose_Distance_to_Velocity_Gain);
    P__Spline_Max_Centripital_Acceleration__Entry.SetDouble(Spline_Max_Centripital_Acceleration);
    P__Spline_Pose_Num_Before_End_Reduce_Speed__Entry.SetDouble(Spline_Pose_Num_Before_End_Reduce_Speed);
    P__Spline_Stop_Radius__Entry.SetDouble(Spline_Stop_Radius);
    P__Spline_Velocity_Multiplier_TEST__Entry.SetDouble(Spline_Velocity_Multiplier_TEST);
    P__Steering_Absolute_Cmd_Approach_Zero_Error_Thresh__Entry.SetDouble(Steering_Absolute_Cmd_Approach_Zero_Error_Thresh);
    P__Steering_Absolute_Cmd_Approach_Zero_Final_Thresh__Entry.SetDouble(Steering_Absolute_Cmd_Approach_Zero_Final_Thresh);
    P__Steering_Absolute_Cmd_NonZero_Error_Thresh__Entry.SetDouble(Steering_Absolute_Cmd_NonZero_Error_Thresh);
    P__Steering_Absolute_Cmd_NonZero_Final_Scale_Factor__Entry.SetDouble(Steering_Absolute_Cmd_NonZero_Final_Scale_Factor);
    P__Steering_Absolute_Cmd_Rate_Limit_Dec__Entry.SetDouble(Steering_Absolute_Cmd_Rate_Limit_Dec);
    P__Steering_Absolute_Cmd_Rate_Limit_Inc__Entry.SetDouble(Steering_Absolute_Cmd_Rate_Limit_Inc);
    P__Steering_Heading_Control_D__Entry.SetDouble(Steering_Heading_Control_D);
    P__Steering_Heading_Control_D_FilterCoeff__Entry.SetDouble(Steering_Heading_Control_D_FilterCoeff);
    P__Steering_Heading_Control_D_LL__Entry.SetDouble(Steering_Heading_Control_D_LL);
    P__Steering_Heading_Control_D_UL__Entry.SetDouble(Steering_Heading_Control_D_UL);
    P__Steering_Heading_Control_Deadzone__Entry.SetDouble(Steering_Heading_Control_Deadzone);
    P__Steering_Heading_Control_I__Entry.SetDouble(Steering_Heading_Control_I);
    P__Steering_Heading_Control_I_LL__Entry.SetDouble(Steering_Heading_Control_I_LL);
    P__Steering_Heading_Control_I_UL__Entry.SetDouble(Steering_Heading_Control_I_UL);
    P__Steering_Heading_Control_P__Entry.SetDouble(Steering_Heading_Control_P);
    P__Steering_Heading_Control_Total_LL__Entry.SetDouble(Steering_Heading_Control_Total_LL);
    P__Steering_Heading_Control_Total_UL__Entry.SetDouble(Steering_Heading_Control_Total_UL);
    P__Steering_Motor_Control_D__Entry.SetDouble(Steering_Motor_Control_D);
    P__Steering_Motor_Control_D_FilterCoeff__Entry.SetDouble(Steering_Motor_Control_D_FilterCoeff);
    P__Steering_Motor_Control_D_LL__Entry.SetDouble(Steering_Motor_Control_D_LL);
    P__Steering_Motor_Control_D_UL__Entry.SetDouble(Steering_Motor_Control_D_UL);
    P__Steering_Motor_Control_I__Entry.SetDouble(Steering_Motor_Control_I);
    P__Steering_Motor_Control_I_LL__Entry.SetDouble(Steering_Motor_Control_I_LL);
    P__Steering_Motor_Control_I_UL__Entry.SetDouble(Steering_Motor_Control_I_UL);
    P__Steering_Motor_Control_P__Entry.SetDouble(Steering_Motor_Control_P);
    P__Steering_Relative_Cmd_Approach_Zero_Error_Thresh__Entry.SetDouble(Steering_Relative_Cmd_Approach_Zero_Error_Thresh);
    P__Steering_Relative_Cmd_Approach_Zero_Final_Thresh__Entry.SetDouble(Steering_Relative_Cmd_Approach_Zero_Final_Thresh);
    P__Steering_Relative_Cmd_NonZero_Error_Thresh__Entry.SetDouble(Steering_Relative_Cmd_NonZero_Error_Thresh);
    P__Steering_Relative_Cmd_NonZero_Final_Scale_Factor__Entry.SetDouble(Steering_Relative_Cmd_NonZero_Final_Scale_Factor);
    P__Steering_Relative_Cmd_Rate_Limit_Dec__Entry.SetDouble(Steering_Relative_Cmd_Rate_Limit_Dec);
    P__Steering_Relative_Cmd_Rate_Limit_Inc__Entry.SetDouble(Steering_Relative_Cmd_Rate_Limit_Inc);
    P__Steering_Relative_Gain__Entry.SetDouble(Steering_Relative_Gain);
    P__Steering_Twist_Gain__Entry.SetDouble(Steering_Twist_Gain);
    P__TEST_Pipeline__Entry.SetDouble(TEST_Pipeline);
    P__TEST_Swerve_Mode_Override_Flag__Entry.SetDouble(TEST_Swerve_Mode_Override_Flag);
    P__TEST_Swerve_Mode_Steering__Entry.SetDouble(TEST_Swerve_Mode_Steering);
    P__TEST_Swerve_Mode_Translation__Entry.SetDouble(TEST_Swerve_Mode_Translation);
    P__Translation_Speed_Approach_Zero_Error_Thresh__Entry.SetDouble(Translation_Speed_Approach_Zero_Error_Thresh);
    P__Translation_Speed_Approach_Zero_Final_Thresh__Entry.SetDouble(Translation_Speed_Approach_Zero_Final_Thresh);
    P__Translation_Speed_NonZero_Error_Thresh__Entry.SetDouble(Translation_Speed_NonZero_Error_Thresh);
    P__Translation_Speed_NonZero_Final_Scale_Factor__Entry.SetDouble(Translation_Speed_NonZero_Final_Scale_Factor);
    P__Translation_Speed_Rate_Limit_Dec__Entry.SetDouble(Translation_Speed_Rate_Limit_Dec);
    P__Translation_Speed_Rate_Limit_Inc__Entry.SetDouble(Translation_Speed_Rate_Limit_Inc);
    P__Translation_Twist_Gain__Entry.SetDouble(Translation_Twist_Gain);
    P__Twist_Deadzone_neg__Entry.SetDouble(Twist_Deadzone_neg);
    P__Twist_Deadzone_pos__Entry.SetDouble(Twist_Deadzone_pos);
    P__Vision_Object_Angle_Offset__Entry.SetDouble(Vision_Object_Angle_Offset);
    P__Vision_Object_Target_Angle__Entry.SetDouble(Vision_Object_Target_Angle);
    P__Vision_Object_Target_X__Entry.SetDouble(Vision_Object_Target_X);
    P__Vision_Object_Target_Y__Entry.SetDouble(Vision_Object_Target_Y);
    P__Vision_Object_X_Offset__Entry.SetDouble(Vision_Object_X_Offset);
    P__Vision_Object_Y_Offset__Entry.SetDouble(Vision_Object_Y_Offset);
    P__Vision_Tag_Angle_Offset__Entry.SetDouble(Vision_Tag_Angle_Offset);
    P__Vision_Tag_Target_Angle__Entry.SetDouble(Vision_Tag_Target_Angle);
    P__Vision_Tag_Target_X__Entry.SetDouble(Vision_Tag_Target_X);
    P__Vision_Tag_Target_Y__Entry.SetDouble(Vision_Tag_Target_Y);
    P__Vision_Tag_X_Offset__Entry.SetDouble(Vision_Tag_X_Offset);
    P__Vision_Tag_Y_Offset__Entry.SetDouble(Vision_Tag_Y_Offset);
    // Inports
    I__Auto_Start_Position__Entry.SetDouble(Robot_Control_U.Auto_Start_Position);
    I__BL_Steer_Module_Angle__Entry.SetDouble(Robot_Control_U.BL_Steer_Module_Angle);
    I__BR_Steer_Module_Angle__Entry.SetDouble(Robot_Control_U.BR_Steer_Module_Angle);
    I__BackLeft_Drive_Motor_Speed__Entry.SetDouble(Robot_Control_U.BackLeft_Drive_Motor_Speed);
    I__BackRight_Drive_Motor_Speed__Entry.SetDouble(Robot_Control_U.BackRight_Drive_Motor_Speed);
    I__FL_Steer_Module_Angle__Entry.SetDouble(Robot_Control_U.FL_Steer_Module_Angle);
    I__FR_Steer_Module_Angle__Entry.SetDouble(Robot_Control_U.FR_Steer_Module_Angle);
    I__FrontLeft_Drive_Motor_Speed__Entry.SetDouble(Robot_Control_U.FrontLeft_Drive_Motor_Speed);
    I__FrontRight_Drive_Motor_Speed__Entry.SetDouble(Robot_Control_U.FrontRight_Drive_Motor_Speed);
    I__GameState__Entry.SetDouble(Robot_Control_U.GameState);
    I__Gamepad_B1_A__Entry.SetDouble(Robot_Control_U.Gamepad_B1_A);
    I__Gamepad_B2_B__Entry.SetDouble(Robot_Control_U.Gamepad_B2_B);
    I__Gamepad_B3_X__Entry.SetDouble(Robot_Control_U.Gamepad_B3_X);
    I__Gamepad_B4_Y__Entry.SetDouble(Robot_Control_U.Gamepad_B4_Y);
    I__Gamepad_Back__Entry.SetDouble(Robot_Control_U.Gamepad_Back);
    I__Gamepad_LB__Entry.SetDouble(Robot_Control_U.Gamepad_LB);
    I__Gamepad_LT__Entry.SetDouble(Robot_Control_U.Gamepad_LT);
    I__Gamepad_POV__Entry.SetDouble(Robot_Control_U.Gamepad_POV);
    I__Gamepad_RB__Entry.SetDouble(Robot_Control_U.Gamepad_RB);
    I__Gamepad_RT__Entry.SetDouble(Robot_Control_U.Gamepad_RT);
    I__Gamepad_Start__Entry.SetDouble(Robot_Control_U.Gamepad_Start);
    I__Gamepad_Stick_Left_X__Entry.SetDouble(Robot_Control_U.Gamepad_Stick_Left_X);
    I__Gamepad_Stick_Left_Y__Entry.SetDouble(Robot_Control_U.Gamepad_Stick_Left_Y);
    I__Gamepad_Stick_Right_X__Entry.SetDouble(Robot_Control_U.Gamepad_Stick_Right_X);
    I__Gamepad_Stick_Right_Y__Entry.SetDouble(Robot_Control_U.Gamepad_Stick_Right_Y);
    I__Gyro_Angle_Field_rad__Entry.SetDouble(Robot_Control_U.Gyro_Angle_Field_rad);
    I__Gyro_Angle_rad__Entry.SetDouble(Robot_Control_U.Gyro_Angle_rad);
    I__IsBlueAlliance__Entry.SetDouble(Robot_Control_U.IsBlueAlliance);
    I__Joystick_Left_B1__Entry.SetDouble(Robot_Control_U.Joystick_Left_B1);
    I__Joystick_Left_B10__Entry.SetDouble(Robot_Control_U.Joystick_Left_B10);
    I__Joystick_Left_B11__Entry.SetDouble(Robot_Control_U.Joystick_Left_B11);
    I__Joystick_Left_B12__Entry.SetDouble(Robot_Control_U.Joystick_Left_B12);
    I__Joystick_Left_B13__Entry.SetDouble(Robot_Control_U.Joystick_Left_B13);
    I__Joystick_Left_B14__Entry.SetDouble(Robot_Control_U.Joystick_Left_B14);
    I__Joystick_Left_B15__Entry.SetDouble(Robot_Control_U.Joystick_Left_B15);
    I__Joystick_Left_B16__Entry.SetDouble(Robot_Control_U.Joystick_Left_B16);
    I__Joystick_Left_B2__Entry.SetDouble(Robot_Control_U.Joystick_Left_B2);
    I__Joystick_Left_B3__Entry.SetDouble(Robot_Control_U.Joystick_Left_B3);
    I__Joystick_Left_B4__Entry.SetDouble(Robot_Control_U.Joystick_Left_B4);
    I__Joystick_Left_B5__Entry.SetDouble(Robot_Control_U.Joystick_Left_B5);
    I__Joystick_Left_B6__Entry.SetDouble(Robot_Control_U.Joystick_Left_B6);
    I__Joystick_Left_B7__Entry.SetDouble(Robot_Control_U.Joystick_Left_B7);
    I__Joystick_Left_B8__Entry.SetDouble(Robot_Control_U.Joystick_Left_B8);
    I__Joystick_Left_B9__Entry.SetDouble(Robot_Control_U.Joystick_Left_B9);
    I__Joystick_Left_POV__Entry.SetDouble(Robot_Control_U.Joystick_Left_POV);
    I__Joystick_Left_X__Entry.SetDouble(Robot_Control_U.Joystick_Left_X);
    I__Joystick_Left_Y__Entry.SetDouble(Robot_Control_U.Joystick_Left_Y);
    I__Joystick_Left_Z__Entry.SetDouble(Robot_Control_U.Joystick_Left_Z);
    I__Joystick_Right_B1__Entry.SetDouble(Robot_Control_U.Joystick_Right_B1);
    I__Joystick_Right_B10__Entry.SetDouble(Robot_Control_U.Joystick_Right_B10);
    I__Joystick_Right_B11__Entry.SetDouble(Robot_Control_U.Joystick_Right_B11);
    I__Joystick_Right_B12__Entry.SetDouble(Robot_Control_U.Joystick_Right_B12);
    I__Joystick_Right_B13__Entry.SetDouble(Robot_Control_U.Joystick_Right_B13);
    I__Joystick_Right_B14__Entry.SetDouble(Robot_Control_U.Joystick_Right_B14);
    I__Joystick_Right_B15__Entry.SetDouble(Robot_Control_U.Joystick_Right_B15);
    I__Joystick_Right_B16__Entry.SetDouble(Robot_Control_U.Joystick_Right_B16);
    I__Joystick_Right_B2__Entry.SetDouble(Robot_Control_U.Joystick_Right_B2);
    I__Joystick_Right_B3__Entry.SetDouble(Robot_Control_U.Joystick_Right_B3);
    I__Joystick_Right_B4__Entry.SetDouble(Robot_Control_U.Joystick_Right_B4);
    I__Joystick_Right_B5__Entry.SetDouble(Robot_Control_U.Joystick_Right_B5);
    I__Joystick_Right_B6__Entry.SetDouble(Robot_Control_U.Joystick_Right_B6);
    I__Joystick_Right_B7__Entry.SetDouble(Robot_Control_U.Joystick_Right_B7);
    I__Joystick_Right_B8__Entry.SetDouble(Robot_Control_U.Joystick_Right_B8);
    I__Joystick_Right_B9__Entry.SetDouble(Robot_Control_U.Joystick_Right_B9);
    I__Joystick_Right_POV__Entry.SetDouble(Robot_Control_U.Joystick_Right_POV);
    I__Joystick_Right_X__Entry.SetDouble(Robot_Control_U.Joystick_Right_X);
    I__Joystick_Right_Y__Entry.SetDouble(Robot_Control_U.Joystick_Right_Y);
    I__Joystick_Right_Z__Entry.SetDouble(Robot_Control_U.Joystick_Right_Z);
    I__MatchTime__Entry.SetDouble(Robot_Control_U.MatchTime);
    I__Odom_Delta_X__Entry.SetDouble(Robot_Control_U.Odom_Delta_X);
    I__Odom_Delta_Y__Entry.SetDouble(Robot_Control_U.Odom_Delta_Y);
    I__Odom_Position_X__Entry.SetDouble(Robot_Control_U.Odom_Position_X);
    I__Odom_Position_Y__Entry.SetDouble(Robot_Control_U.Odom_Position_Y);
    I__Vision_Current_Pipeline__Entry.SetDouble(Robot_Control_U.Vision_Current_Pipeline);
    I__Vision_Num_Tags_Detected__Entry.SetDouble(Robot_Control_U.Vision_Num_Tags_Detected);
    I__Vision_RobotPoseFieldSpace_X__Entry.SetDouble(Robot_Control_U.Vision_RobotPoseFieldSpace_X);
    I__Vision_RobotPoseFieldSpace_Y__Entry.SetDouble(Robot_Control_U.Vision_RobotPoseFieldSpace_Y);
    I__Vision_c1_AprilTag_Valid__Entry.SetDouble(Robot_Control_U.Vision_c1_AprilTag_Valid);
    I__Vision_c1_AprilTag_X_m__Entry.SetDouble(Robot_Control_U.Vision_c1_AprilTag_X_m);
    I__Vision_c1_AprilTag_Y_m__Entry.SetDouble(Robot_Control_U.Vision_c1_AprilTag_Y_m);
    I__Vision_c1_AprilTag_Yaw_deg__Entry.SetDouble(Robot_Control_U.Vision_c1_AprilTag_Yaw_deg);
    I__Vision_c1_Object_Area_pct__Entry.SetDouble(Robot_Control_U.Vision_c1_Object_Area_pct);
    I__Vision_c1_Object_Hor_deg__Entry.SetDouble(Robot_Control_U.Vision_c1_Object_Hor_deg);
    I__Vision_c1_Object_Valid__Entry.SetDouble(Robot_Control_U.Vision_c1_Object_Valid);
    I__Vision_c1_Object_Ver_deg__Entry.SetDouble(Robot_Control_U.Vision_c1_Object_Ver_deg);
    // Outports
    O__BackLeft_Drive_DutyCycle__Entry.SetDouble(Robot_Control_Y.BackLeft_Drive_DutyCycle);
    O__BackLeft_Steer_DutyCycle__Entry.SetDouble(Robot_Control_Y.BackLeft_Steer_DutyCycle);
    O__BackRight_Drive_DutyCycle__Entry.SetDouble(Robot_Control_Y.BackRight_Drive_DutyCycle);
    O__BackRight_Steer_DutyCycle__Entry.SetDouble(Robot_Control_Y.BackRight_Steer_DutyCycle);
    O__Disable_Wheels__Entry.SetDouble(Robot_Control_Y.Disable_Wheels);
    O__Enable_Wheels__Entry.SetDouble(Robot_Control_Y.Enable_Wheels);
    O__FrontLeft_Drive_DutyCycle__Entry.SetDouble(Robot_Control_Y.FrontLeft_Drive_DutyCycle);
    O__FrontLeft_Steer_DutyCycle__Entry.SetDouble(Robot_Control_Y.FrontLeft_Steer_DutyCycle);
    O__FrontRight_Drive_DutyCycle__Entry.SetDouble(Robot_Control_Y.FrontRight_Drive_DutyCycle);
    O__FrontRight_Steer_DutyCycle__Entry.SetDouble(Robot_Control_Y.FrontRight_Steer_DutyCycle);
    O__Reset_Wheel_Offsets__Entry.SetDouble(Robot_Control_Y.Reset_Wheel_Offsets);
    O__Swerve_Motors_Disabled__Entry.SetDouble(Robot_Control_Y.Swerve_Motors_Disabled);
    O__Vision_Desired_Pipeline__Entry.SetDouble(Robot_Control_Y.Vision_Desired_Pipeline);
    // Test Points
    T__Active_GameState__Entry.SetDouble(Robot_Control_B.Active_GameState);
    T__Actuator_Cmd__Entry.SetDouble(Robot_Control_B.Actuator_Cmd);
    T__Align_Center__Entry.SetDouble(Robot_Control_B.Align_Center);
    T__Align_Left__Entry.SetDouble(Robot_Control_B.Align_Left);
    T__Align_Right__Entry.SetDouble(Robot_Control_B.Align_Right);
    T__BL_Desired_Module_Angle__Entry.SetDouble(Robot_Control_B.BL_Desired_Module_Angle);
    T__BL_Desired_Wheel_Speed__Entry.SetDouble(Robot_Control_B.BL_Desired_Wheel_Speed);
    T__BL_Desired_Wheel_Speed_in__Entry.SetDouble(Robot_Control_B.BL_Desired_Wheel_Speed_in);
    T__BR_Desired_Module_Angle__Entry.SetDouble(Robot_Control_B.BR_Desired_Module_Angle);
    T__BR_Desired_Wheel_Speed__Entry.SetDouble(Robot_Control_B.BR_Desired_Wheel_Speed);
    T__BR_Desired_Wheel_Speed_in__Entry.SetDouble(Robot_Control_B.BR_Desired_Wheel_Speed_in);
    T__Button_Disable_Wheels__Entry.SetDouble(Robot_Control_B.Button_Disable_Wheels);
    T__Button_Enable_Wheels__Entry.SetDouble(Robot_Control_B.Button_Enable_Wheels);
    T__Button_Reset_Wheel_Offsets__Entry.SetDouble(Robot_Control_B.Button_Reset_Wheel_Offsets);
    T__Drive_Engage_Hook__Entry.SetDouble(Robot_Control_B.Drive_Engage_Hook);
    T__Drive_Joystick_X__Entry.SetDouble(Robot_Control_B.Drive_Joystick_X);
    T__Drive_Joystick_Y__Entry.SetDouble(Robot_Control_B.Drive_Joystick_Y);
    T__Drive_Joystick_Z__Entry.SetDouble(Robot_Control_B.Drive_Joystick_Z);
    T__Drive_Joystick_Z_Mode__Entry.SetDouble(Robot_Control_B.Drive_Joystick_Z_Mode);
    T__FL_Desired_Module_Angle__Entry.SetDouble(Robot_Control_B.FL_Desired_Module_Angle);
    T__FL_Desired_Wheel_Speed__Entry.SetDouble(Robot_Control_B.FL_Desired_Wheel_Speed);
    T__FL_Desired_Wheel_Speed_in__Entry.SetDouble(Robot_Control_B.FL_Desired_Wheel_Speed_in);
    T__FR_Desired_Module_Angle__Entry.SetDouble(Robot_Control_B.FR_Desired_Module_Angle);
    T__FR_Desired_Wheel_Speed__Entry.SetDouble(Robot_Control_B.FR_Desired_Wheel_Speed);
    T__FR_Desired_Wheel_Speed_in__Entry.SetDouble(Robot_Control_B.FR_Desired_Wheel_Speed_in);
    T__Face_Away_Driver__Entry.SetDouble(Robot_Control_B.Face_Away_Driver);
    T__Face_Left_Driver__Entry.SetDouble(Robot_Control_B.Face_Left_Driver);
    T__Face_Right_Driver__Entry.SetDouble(Robot_Control_B.Face_Right_Driver);
    T__Face_Toward_Driver__Entry.SetDouble(Robot_Control_B.Face_Toward_Driver);
    T__Gamepad_POV_Down__Entry.SetDouble(Robot_Control_B.Gamepad_POV_Down);
    T__Gamepad_POV_Left__Entry.SetDouble(Robot_Control_B.Gamepad_POV_Left);
    T__Gamepad_POV_Right__Entry.SetDouble(Robot_Control_B.Gamepad_POV_Right);
    T__Gamepad_POV_Up__Entry.SetDouble(Robot_Control_B.Gamepad_POV_Up);
    T__Gyro_Angle_SPF__Entry.SetDouble(Robot_Control_B.Gyro_Angle_SPF);
    T__Is_Absolute_Steering_SPF__Entry.SetDouble(Robot_Control_B.Is_Absolute_Steering_SPF);
    T__Is_Absolute_Translation_SPF__Entry.SetDouble(Robot_Control_B.Is_Absolute_Translation_SPF);
    T__Is_Boosting__Entry.SetDouble(Robot_Control_B.Is_Boosting);
    T__KF_Position_X__Entry.SetDouble(Robot_Control_B.KF_Position_X);
    T__KF_Position_Y__Entry.SetDouble(Robot_Control_B.KF_Position_Y);
    T__Relative_Enable__Entry.SetDouble(Robot_Control_B.Relative_Enable);
    T__Relative_Error_Angle__Entry.SetDouble(Robot_Control_B.Relative_Error_Angle);
    T__Relative_Error_X__Entry.SetDouble(Robot_Control_B.Relative_Error_X);
    T__Relative_Error_Y__Entry.SetDouble(Robot_Control_B.Relative_Error_Y);
    T__Robot_Reached_Destination__Entry.SetDouble(Robot_Control_B.Robot_Reached_Destination);
    T__Spline_Enable__Entry.SetDouble(Robot_Control_B.Spline_Enable);
    T__Spline_Follow_Index__Entry.SetDouble(Robot_Control_B.Spline_Follow_Index);
    T__Spline_Num_Poses__Entry.SetDouble(Robot_Control_B.Spline_Num_Poses);
    T__Spline_Out_Of_Bounds__Entry.SetDouble(Robot_Control_B.Spline_Out_Of_Bounds);
    T__Spline_Target_X__Entry.SetDouble(Robot_Control_B.Spline_Target_X);
    T__Spline_Target_Y__Entry.SetDouble(Robot_Control_B.Spline_Target_Y);
    T__Steer_Joystick_X__Entry.SetDouble(Robot_Control_B.Steer_Joystick_X);
    T__Steer_Joystick_Y__Entry.SetDouble(Robot_Control_B.Steer_Joystick_Y);
    T__Steer_Joystick_Z__Entry.SetDouble(Robot_Control_B.Steer_Joystick_Z);
    T__Steering_Abs_Angle__Entry.SetDouble(Robot_Control_B.Steering_Abs_Angle);
    T__Steering_Abs_Angle_Active__Entry.SetDouble(Robot_Control_B.Steering_Abs_Angle_Active);
    T__Steering_Abs_Cmd__Entry.SetDouble(Robot_Control_B.Steering_Abs_Cmd);
    T__Steering_Abs_Cmd_SPF__Entry.SetDouble(Robot_Control_B.Steering_Abs_Cmd_SPF);
    T__Steering_Abs_Gyro__Entry.SetDouble(Robot_Control_B.Steering_Abs_Gyro);
    T__Steering_Abs_Gyro_Latch__Entry.SetDouble(Robot_Control_B.Steering_Abs_Gyro_Latch);
    T__Steering_Localized_Cmd__Entry.SetDouble(Robot_Control_B.Steering_Localized_Cmd);
    T__Steering_Localized_PID__Entry.SetDouble(Robot_Control_B.Steering_Localized_PID);
    T__Steering_Rel_Cmd__Entry.SetDouble(Robot_Control_B.Steering_Rel_Cmd);
    T__Steering_Rel_Cmd_SPF__Entry.SetDouble(Robot_Control_B.Steering_Rel_Cmd_SPF);
    T__Swerve_Drive_Integral_Enable__Entry.SetDouble(Robot_Control_B.Swerve_Drive_Integral_Enable);
    T__Test_Mode__Entry.SetDouble(Robot_Control_B.Test_Mode);
    T__Translation_Angle__Entry.SetDouble(Robot_Control_B.Translation_Angle);
    T__Translation_Angle_SPF__Entry.SetDouble(Robot_Control_B.Translation_Angle_SPF);
    T__Translation_Speed__Entry.SetDouble(Robot_Control_B.Translation_Speed);
    T__Translation_Speed_RL__Entry.SetDouble(Robot_Control_B.Translation_Speed_RL);
    T__Translation_Speed_SPF__Entry.SetDouble(Robot_Control_B.Translation_Speed_SPF);
    T__Translation_Steering_Cmd__Entry.SetDouble(Robot_Control_B.Translation_Steering_Cmd);
    T__Vision_c1_AprilTag_Corr_X_inch__Entry.SetDouble(Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch);
    T__Vision_c1_AprilTag_Corr_Y_inch__Entry.SetDouble(Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch);
    T__Vision_c1_AprilTag_Corr_Yaw_deg__Entry.SetDouble(Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg);
    T__Vision_c1_Object_Corr_X_inch__Entry.SetDouble(Robot_Control_B.Vision_c1_Object_Corr_X_inch);
    T__Vision_c1_Object_Corr_Y_inch__Entry.SetDouble(Robot_Control_B.Vision_c1_Object_Corr_Y_inch);
    T__Vision_c1_Object_Corr_Yaw_deg__Entry.SetDouble(Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg);
    T__Winch_Cmd__Entry.SetDouble(Robot_Control_B.Winch_Cmd);
    T__loop_counter_robot_control__Entry.SetDouble(Robot_Control_B.loop_counter_robot_control);
}
// Why are you reading to the bottom of an autogen file?
// Get a life...
