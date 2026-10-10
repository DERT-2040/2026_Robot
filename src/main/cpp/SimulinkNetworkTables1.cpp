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
 
    P__Auto_Deploy_Intake_Time__Entry = NTtable_Tune->GetEntry("Auto_Deploy_Intake_Time");
    NTinst.AddListener(P__Auto_Deploy_Intake_Time__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Auto_Deploy_Intake_Time = event.GetValueEventData()->value.GetDouble();});
    P__Auto_Deploy_Intake_Time__Entry.SetDouble(1);
 
    P__Auto_Deploy_Intake_Time2__Entry = NTtable_Tune->GetEntry("Auto_Deploy_Intake_Time2");
    NTinst.AddListener(P__Auto_Deploy_Intake_Time2__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Auto_Deploy_Intake_Time2 = event.GetValueEventData()->value.GetDouble();});
    P__Auto_Deploy_Intake_Time2__Entry.SetDouble(0);
 
    P__Auto_Intake_Arm_Cycle_Delay_Time__Entry = NTtable_Tune->GetEntry("Auto_Intake_Arm_Cycle_Delay_Time");
    NTinst.AddListener(P__Auto_Intake_Arm_Cycle_Delay_Time__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Auto_Intake_Arm_Cycle_Delay_Time = event.GetValueEventData()->value.GetDouble();});
    P__Auto_Intake_Arm_Cycle_Delay_Time__Entry.SetDouble(2);
 
    P__Auto_Path_Chooser__Entry = NTtable_Tune->GetEntry("Auto_Path_Chooser");
    NTinst.AddListener(P__Auto_Path_Chooser__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Auto_Path_Chooser = event.GetValueEventData()->value.GetDouble();});
    P__Auto_Path_Chooser__Entry.SetDouble(3);
 
    P__Auto_Shoot_Time__Entry = NTtable_Tune->GetEntry("Auto_Shoot_Time");
    NTinst.AddListener(P__Auto_Shoot_Time__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Auto_Shoot_Time = event.GetValueEventData()->value.GetDouble();});
    P__Auto_Shoot_Time__Entry.SetDouble(4.5);
 
    P__Blue_Hub_LeftX__Entry = NTtable_Tune->GetEntry("Blue_Hub_LeftX");
    NTinst.AddListener(P__Blue_Hub_LeftX__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Blue_Hub_LeftX = event.GetValueEventData()->value.GetDouble();});
    P__Blue_Hub_LeftX__Entry.SetDouble(5.1717);
 
    P__Blue_Hub_LeftY__Entry = NTtable_Tune->GetEntry("Blue_Hub_LeftY");
    NTinst.AddListener(P__Blue_Hub_LeftY__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Blue_Hub_LeftY = event.GetValueEventData()->value.GetDouble();});
    P__Blue_Hub_LeftY__Entry.SetDouble(3.354);
 
    P__Blue_Hub_RightX__Entry = NTtable_Tune->GetEntry("Blue_Hub_RightX");
    NTinst.AddListener(P__Blue_Hub_RightX__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Blue_Hub_RightX = event.GetValueEventData()->value.GetDouble();});
    P__Blue_Hub_RightX__Entry.SetDouble(5.1717);
 
    P__Blue_Hub_RightY__Entry = NTtable_Tune->GetEntry("Blue_Hub_RightY");
    NTinst.AddListener(P__Blue_Hub_RightY__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Blue_Hub_RightY = event.GetValueEventData()->value.GetDouble();});
    P__Blue_Hub_RightY__Entry.SetDouble(4.548);
 
    P__Boost_Trigger_Decreasing_Limit__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Decreasing_Limit");
    NTinst.AddListener(P__Boost_Trigger_Decreasing_Limit__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Decreasing_Limit = event.GetValueEventData()->value.GetDouble();});
    P__Boost_Trigger_Decreasing_Limit__Entry.SetDouble(-0.24);
 
    P__Boost_Trigger_High_Speed__Entry = NTtable_Tune->GetEntry("Boost_Trigger_High_Speed");
    NTinst.AddListener(P__Boost_Trigger_High_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_High_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Boost_Trigger_High_Speed__Entry.SetDouble(5);
 
    P__Boost_Trigger_Increasing_Limit__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Increasing_Limit");
    NTinst.AddListener(P__Boost_Trigger_Increasing_Limit__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Increasing_Limit = event.GetValueEventData()->value.GetDouble();});
    P__Boost_Trigger_Increasing_Limit__Entry.SetDouble(3);
 
    P__Boost_Trigger_Low_Speed__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Low_Speed");
    NTinst.AddListener(P__Boost_Trigger_Low_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Low_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Boost_Trigger_Low_Speed__Entry.SetDouble(2);
 
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
 
    P__Drive_Motor_Control_P__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_P");
    NTinst.AddListener(P__Drive_Motor_Control_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_P = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_P__Entry.SetDouble(5e-06);
 
    P__Drive_Motor_Control_Sign_Change_Deadband__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_Sign_Change_Deadband");
    NTinst.AddListener(P__Drive_Motor_Control_Sign_Change_Deadband__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_Sign_Change_Deadband = event.GetValueEventData()->value.GetDouble();});
    P__Drive_Motor_Control_Sign_Change_Deadband__Entry.SetDouble(7000);
 
    P__Feeder_Max_Pulsetime__Entry = NTtable_Tune->GetEntry("Feeder_Max_Pulsetime");
    NTinst.AddListener(P__Feeder_Max_Pulsetime__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Feeder_Max_Pulsetime = event.GetValueEventData()->value.GetDouble();});
    P__Feeder_Max_Pulsetime__Entry.SetDouble(1000);
 
    P__Field_BlueAllianceZoneX__Entry = NTtable_Tune->GetEntry("Field_BlueAllianceZoneX");
    NTinst.AddListener(P__Field_BlueAllianceZoneX__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_BlueAllianceZoneX = event.GetValueEventData()->value.GetDouble();});
    P__Field_BlueAllianceZoneX__Entry.SetDouble(4.6256);
 
    P__Field_Blue_Hub_X__Entry = NTtable_Tune->GetEntry("Field_Blue_Hub_X");
    NTinst.AddListener(P__Field_Blue_Hub_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Blue_Hub_X = event.GetValueEventData()->value.GetDouble();});
    P__Field_Blue_Hub_X__Entry.SetDouble(4.6256);
 
    P__Field_Blue_Pass_X__Entry = NTtable_Tune->GetEntry("Field_Blue_Pass_X");
    NTinst.AddListener(P__Field_Blue_Pass_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Blue_Pass_X = event.GetValueEventData()->value.GetDouble();});
    P__Field_Blue_Pass_X__Entry.SetDouble(1.9889);
 
    P__Field_Hub_Y__Entry = NTtable_Tune->GetEntry("Field_Hub_Y");
    NTinst.AddListener(P__Field_Hub_Y__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Hub_Y = event.GetValueEventData()->value.GetDouble();});
    P__Field_Hub_Y__Entry.SetDouble(4.0345);
 
    P__Field_Length__Entry = NTtable_Tune->GetEntry("Field_Length");
    NTinst.AddListener(P__Field_Length__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Length = event.GetValueEventData()->value.GetDouble();});
    P__Field_Length__Entry.SetDouble(17.557);
 
    P__Field_Length_Half__Entry = NTtable_Tune->GetEntry("Field_Length_Half");
    NTinst.AddListener(P__Field_Length_Half__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Length_Half = event.GetValueEventData()->value.GetDouble();});
    P__Field_Length_Half__Entry.SetDouble(8.7785);
 
    P__Field_Pass_Y_Bottom__Entry = NTtable_Tune->GetEntry("Field_Pass_Y_Bottom");
    NTinst.AddListener(P__Field_Pass_Y_Bottom__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Pass_Y_Bottom = event.GetValueEventData()->value.GetDouble();});
    P__Field_Pass_Y_Bottom__Entry.SetDouble(2.4384);
 
    P__Field_Pass_Y_Top__Entry = NTtable_Tune->GetEntry("Field_Pass_Y_Top");
    NTinst.AddListener(P__Field_Pass_Y_Top__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Pass_Y_Top = event.GetValueEventData()->value.GetDouble();});
    P__Field_Pass_Y_Top__Entry.SetDouble(5.6309);
 
    P__Field_RedAllianceZoneX__Entry = NTtable_Tune->GetEntry("Field_RedAllianceZoneX");
    NTinst.AddListener(P__Field_RedAllianceZoneX__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_RedAllianceZoneX = event.GetValueEventData()->value.GetDouble();});
    P__Field_RedAllianceZoneX__Entry.SetDouble(11.9154);
 
    P__Field_Red_Hub_X__Entry = NTtable_Tune->GetEntry("Field_Red_Hub_X");
    NTinst.AddListener(P__Field_Red_Hub_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Red_Hub_X = event.GetValueEventData()->value.GetDouble();});
    P__Field_Red_Hub_X__Entry.SetDouble(11.9154);
 
    P__Field_Red_Pass_X__Entry = NTtable_Tune->GetEntry("Field_Red_Pass_X");
    NTinst.AddListener(P__Field_Red_Pass_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Red_Pass_X = event.GetValueEventData()->value.GetDouble();});
    P__Field_Red_Pass_X__Entry.SetDouble(14.552);
 
    P__Field_Translation_Control_Gain__Entry = NTtable_Tune->GetEntry("Field_Translation_Control_Gain");
    NTinst.AddListener(P__Field_Translation_Control_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Translation_Control_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Field_Translation_Control_Gain__Entry.SetDouble(10);
 
    P__Field_Translation_Speed_Max__Entry = NTtable_Tune->GetEntry("Field_Translation_Speed_Max");
    NTinst.AddListener(P__Field_Translation_Speed_Max__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Translation_Speed_Max = event.GetValueEventData()->value.GetDouble();});
    P__Field_Translation_Speed_Max__Entry.SetDouble(5);
 
    P__Field_Width_Pass__Entry = NTtable_Tune->GetEntry("Field_Width_Pass");
    NTinst.AddListener(P__Field_Width_Pass__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Field_Width_Pass = event.GetValueEventData()->value.GetDouble();});
    P__Field_Width_Pass__Entry.SetDouble(7.0692);
 
    P__KF_Enable__Entry = NTtable_Tune->GetEntry("KF_Enable");
    NTinst.AddListener(P__KF_Enable__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {KF_Enable = event.GetValueEventData()->value.GetDouble();});
    P__KF_Enable__Entry.SetDouble(1);
 
    P__Rate_Limit_X__Entry = NTtable_Tune->GetEntry("Rate_Limit_X");
    NTinst.AddListener(P__Rate_Limit_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rate_Limit_X = event.GetValueEventData()->value.GetDouble();});
    P__Rate_Limit_X__Entry.SetDouble(1000);
 
    P__Rate_Limit_Y__Entry = NTtable_Tune->GetEntry("Rate_Limit_Y");
    NTinst.AddListener(P__Rate_Limit_Y__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rate_Limit_Y = event.GetValueEventData()->value.GetDouble();});
    P__Rate_Limit_Y__Entry.SetDouble(1000);
 
    P__Rate_Limit_Z__Entry = NTtable_Tune->GetEntry("Rate_Limit_Z");
    NTinst.AddListener(P__Rate_Limit_Z__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rate_Limit_Z = event.GetValueEventData()->value.GetDouble();});
    P__Rate_Limit_Z__Entry.SetDouble(1000);
 
    P__Rebuilt_Des_Gyro_Shoot_Offset__Entry = NTtable_Tune->GetEntry("Rebuilt_Des_Gyro_Shoot_Offset");
    NTinst.AddListener(P__Rebuilt_Des_Gyro_Shoot_Offset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Des_Gyro_Shoot_Offset = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Des_Gyro_Shoot_Offset__Entry.SetDouble(0);
 
    P__Rebuilt_Feeder_Motor_Gain_FF__Entry = NTtable_Tune->GetEntry("Rebuilt_Feeder_Motor_Gain_FF");
    NTinst.AddListener(P__Rebuilt_Feeder_Motor_Gain_FF__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Feeder_Motor_Gain_FF = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Feeder_Motor_Gain_FF__Entry.SetDouble(0.00016534);
 
    P__Rebuilt_Feeder_Time_FWD__Entry = NTtable_Tune->GetEntry("Rebuilt_Feeder_Time_FWD");
    NTinst.AddListener(P__Rebuilt_Feeder_Time_FWD__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Feeder_Time_FWD = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Feeder_Time_FWD__Entry.SetDouble(0.5);
 
    P__Rebuilt_Feeder_Time_REV__Entry = NTtable_Tune->GetEntry("Rebuilt_Feeder_Time_REV");
    NTinst.AddListener(P__Rebuilt_Feeder_Time_REV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Feeder_Time_REV = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Feeder_Time_REV__Entry.SetDouble(0.5);
 
    P__Rebuilt_Hood_Servo_Pos_Max__Entry = NTtable_Tune->GetEntry("Rebuilt_Hood_Servo_Pos_Max");
    NTinst.AddListener(P__Rebuilt_Hood_Servo_Pos_Max__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Hood_Servo_Pos_Max = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Hood_Servo_Pos_Max__Entry.SetDouble(1);
 
    P__Rebuilt_Hood_Servo_Pos_Min__Entry = NTtable_Tune->GetEntry("Rebuilt_Hood_Servo_Pos_Min");
    NTinst.AddListener(P__Rebuilt_Hood_Servo_Pos_Min__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Hood_Servo_Pos_Min = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Hood_Servo_Pos_Min__Entry.SetDouble(0.05);
 
    P__Rebuilt_Hood_Servo_Rate_Limit_Dec__Entry = NTtable_Tune->GetEntry("Rebuilt_Hood_Servo_Rate_Limit_Dec");
    NTinst.AddListener(P__Rebuilt_Hood_Servo_Rate_Limit_Dec__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Hood_Servo_Rate_Limit_Dec = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Hood_Servo_Rate_Limit_Dec__Entry.SetDouble(-0.0128);
 
    P__Rebuilt_Hood_Servo_Rate_Limit_Inc__Entry = NTtable_Tune->GetEntry("Rebuilt_Hood_Servo_Rate_Limit_Inc");
    NTinst.AddListener(P__Rebuilt_Hood_Servo_Rate_Limit_Inc__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Hood_Servo_Rate_Limit_Inc = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Hood_Servo_Rate_Limit_Inc__Entry.SetDouble(0.0128);
 
    P__Rebuilt_Intake_Arm_Gain_D__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_Arm_Gain_D");
    NTinst.AddListener(P__Rebuilt_Intake_Arm_Gain_D__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_Arm_Gain_D = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_Arm_Gain_D__Entry.SetDouble(0);
 
    P__Rebuilt_Intake_Arm_Gain_P__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_Arm_Gain_P");
    NTinst.AddListener(P__Rebuilt_Intake_Arm_Gain_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_Arm_Gain_P = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_Arm_Gain_P__Entry.SetDouble(0.008);
 
    P__Rebuilt_Intake_Cycle_Angle_In__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_Cycle_Angle_In");
    NTinst.AddListener(P__Rebuilt_Intake_Cycle_Angle_In__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_Cycle_Angle_In = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_Cycle_Angle_In__Entry.SetDouble(-10);
 
    P__Rebuilt_Intake_Cycle_Angle_Out__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_Cycle_Angle_Out");
    NTinst.AddListener(P__Rebuilt_Intake_Cycle_Angle_Out__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_Cycle_Angle_Out = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_Cycle_Angle_Out__Entry.SetDouble(10);
 
    P__Rebuilt_Intake_Des_Angle_In__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_Des_Angle_In");
    NTinst.AddListener(P__Rebuilt_Intake_Des_Angle_In__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_Des_Angle_In = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_Des_Angle_In__Entry.SetDouble(-40);
 
    P__Rebuilt_Intake_Des_Angle_Out__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_Des_Angle_Out");
    NTinst.AddListener(P__Rebuilt_Intake_Des_Angle_Out__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_Des_Angle_Out = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_Des_Angle_Out__Entry.SetDouble(90);
 
    P__Rebuilt_Intake_Meas_In_Disable__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_Meas_In_Disable");
    NTinst.AddListener(P__Rebuilt_Intake_Meas_In_Disable__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_Meas_In_Disable = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_Meas_In_Disable__Entry.SetDouble(-20);
 
    P__Rebuilt_Intake_Meas_Out_Disable__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_Meas_Out_Disable");
    NTinst.AddListener(P__Rebuilt_Intake_Meas_Out_Disable__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_Meas_Out_Disable = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_Meas_Out_Disable__Entry.SetDouble(40);
 
    P__Rebuilt_Intake_RL_Dec__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_RL_Dec");
    NTinst.AddListener(P__Rebuilt_Intake_RL_Dec__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_RL_Dec = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_RL_Dec__Entry.SetDouble(-3);
 
    P__Rebuilt_Intake_RL_Inc__Entry = NTtable_Tune->GetEntry("Rebuilt_Intake_RL_Inc");
    NTinst.AddListener(P__Rebuilt_Intake_RL_Inc__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Intake_RL_Inc = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Intake_RL_Inc__Entry.SetDouble(3);
 
    P__Rebuilt_Match_Time_Auto_Timer__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_Auto_Timer");
    NTinst.AddListener(P__Rebuilt_Match_Time_Auto_Timer__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_Auto_Timer = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_Auto_Timer__Entry.SetDouble(30);
 
    P__Rebuilt_Match_Time_End_Game_Timer__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_End_Game_Timer");
    NTinst.AddListener(P__Rebuilt_Match_Time_End_Game_Timer__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_End_Game_Timer = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_End_Game_Timer__Entry.SetDouble(30);
 
    P__Rebuilt_Match_Time_Shift_1__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_Shift_1");
    NTinst.AddListener(P__Rebuilt_Match_Time_Shift_1__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_Shift_1 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_Shift_1__Entry.SetDouble(35);
 
    P__Rebuilt_Match_Time_Shift_2__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_Shift_2");
    NTinst.AddListener(P__Rebuilt_Match_Time_Shift_2__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_Shift_2 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_Shift_2__Entry.SetDouble(60);
 
    P__Rebuilt_Match_Time_Shift_3__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_Shift_3");
    NTinst.AddListener(P__Rebuilt_Match_Time_Shift_3__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_Shift_3 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_Shift_3__Entry.SetDouble(85);
 
    P__Rebuilt_Match_Time_Shift_4__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_Shift_4");
    NTinst.AddListener(P__Rebuilt_Match_Time_Shift_4__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_Shift_4 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_Shift_4__Entry.SetDouble(110);
 
    P__Rebuilt_Match_Time_Shift_Timer__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_Shift_Timer");
    NTinst.AddListener(P__Rebuilt_Match_Time_Shift_Timer__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_Shift_Timer = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_Shift_Timer__Entry.SetDouble(25);
 
    P__Rebuilt_Match_Time_Shoot_Early__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_Shoot_Early");
    NTinst.AddListener(P__Rebuilt_Match_Time_Shoot_Early__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_Shoot_Early = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_Shoot_Early__Entry.SetDouble(2);
 
    P__Rebuilt_Match_Time_Transition__Entry = NTtable_Tune->GetEntry("Rebuilt_Match_Time_Transition");
    NTinst.AddListener(P__Rebuilt_Match_Time_Transition__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Match_Time_Transition = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Match_Time_Transition__Entry.SetDouble(10);
 
    P__Rebuilt_Negative_Feeder_Speed__Entry = NTtable_Tune->GetEntry("Rebuilt_Negative_Feeder_Speed");
    NTinst.AddListener(P__Rebuilt_Negative_Feeder_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Negative_Feeder_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Negative_Feeder_Speed__Entry.SetDouble(-3000);
 
    P__Rebuilt_Roller_Desired_Speed__Entry = NTtable_Tune->GetEntry("Rebuilt_Roller_Desired_Speed");
    NTinst.AddListener(P__Rebuilt_Roller_Desired_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Roller_Desired_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Roller_Desired_Speed__Entry.SetDouble(6000);
 
    P__Rebuilt_Roller_Error_Integral_Enable__Entry = NTtable_Tune->GetEntry("Rebuilt_Roller_Error_Integral_Enable");
    NTinst.AddListener(P__Rebuilt_Roller_Error_Integral_Enable__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Roller_Error_Integral_Enable = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Roller_Error_Integral_Enable__Entry.SetDouble(300);
 
    P__Rebuilt_Roller_Intake_In_Delay__Entry = NTtable_Tune->GetEntry("Rebuilt_Roller_Intake_In_Delay");
    NTinst.AddListener(P__Rebuilt_Roller_Intake_In_Delay__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Roller_Intake_In_Delay = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Roller_Intake_In_Delay__Entry.SetDouble(2);
 
    P__Rebuilt_Roller_Motor_Gain_FF__Entry = NTtable_Tune->GetEntry("Rebuilt_Roller_Motor_Gain_FF");
    NTinst.AddListener(P__Rebuilt_Roller_Motor_Gain_FF__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Roller_Motor_Gain_FF = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Roller_Motor_Gain_FF__Entry.SetDouble(0.00016534);
 
    P__Rebuilt_Roller_Motor_Gain_I__Entry = NTtable_Tune->GetEntry("Rebuilt_Roller_Motor_Gain_I");
    NTinst.AddListener(P__Rebuilt_Roller_Motor_Gain_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Roller_Motor_Gain_I = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Roller_Motor_Gain_I__Entry.SetDouble(2e-05);
 
    P__Rebuilt_Roller_Motor_Gain_P__Entry = NTtable_Tune->GetEntry("Rebuilt_Roller_Motor_Gain_P");
    NTinst.AddListener(P__Rebuilt_Roller_Motor_Gain_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Roller_Motor_Gain_P = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Roller_Motor_Gain_P__Entry.SetDouble(0.0001);
 
    P__Rebuilt_Shoot_Dist_0__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Dist_0");
    NTinst.AddListener(P__Rebuilt_Shoot_Dist_0__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Dist_0 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Dist_0__Entry.SetDouble(1.37);
 
    P__Rebuilt_Shoot_Dist_1__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Dist_1");
    NTinst.AddListener(P__Rebuilt_Shoot_Dist_1__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Dist_1 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Dist_1__Entry.SetDouble(2.12);
 
    P__Rebuilt_Shoot_Dist_2__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Dist_2");
    NTinst.AddListener(P__Rebuilt_Shoot_Dist_2__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Dist_2 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Dist_2__Entry.SetDouble(3.115);
 
    P__Rebuilt_Shoot_Dist_3__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Dist_3");
    NTinst.AddListener(P__Rebuilt_Shoot_Dist_3__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Dist_3 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Dist_3__Entry.SetDouble(3.692);
 
    P__Rebuilt_Shoot_Dist_4__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Dist_4");
    NTinst.AddListener(P__Rebuilt_Shoot_Dist_4__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Dist_4 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Dist_4__Entry.SetDouble(4.353);
 
    P__Rebuilt_Shoot_Dist_5__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Dist_5");
    NTinst.AddListener(P__Rebuilt_Shoot_Dist_5__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Dist_5 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Dist_5__Entry.SetDouble(4.884);
 
    P__Rebuilt_Shoot_Dist_6__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Dist_6");
    NTinst.AddListener(P__Rebuilt_Shoot_Dist_6__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Dist_6 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Dist_6__Entry.SetDouble(5.6);
 
    P__Rebuilt_Shoot_Dist_7__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Dist_7");
    NTinst.AddListener(P__Rebuilt_Shoot_Dist_7__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Dist_7 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Dist_7__Entry.SetDouble(9);
 
    P__Rebuilt_Shoot_Gyro_Err_0__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Gyro_Err_0");
    NTinst.AddListener(P__Rebuilt_Shoot_Gyro_Err_0__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Gyro_Err_0 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Gyro_Err_0__Entry.SetDouble(5);
 
    P__Rebuilt_Shoot_Gyro_Err_1__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Gyro_Err_1");
    NTinst.AddListener(P__Rebuilt_Shoot_Gyro_Err_1__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Gyro_Err_1 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Gyro_Err_1__Entry.SetDouble(5);
 
    P__Rebuilt_Shoot_Gyro_Err_2__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Gyro_Err_2");
    NTinst.AddListener(P__Rebuilt_Shoot_Gyro_Err_2__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Gyro_Err_2 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Gyro_Err_2__Entry.SetDouble(3.5);
 
    P__Rebuilt_Shoot_Gyro_Err_3__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Gyro_Err_3");
    NTinst.AddListener(P__Rebuilt_Shoot_Gyro_Err_3__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Gyro_Err_3 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Gyro_Err_3__Entry.SetDouble(3);
 
    P__Rebuilt_Shoot_Gyro_Err_4__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Gyro_Err_4");
    NTinst.AddListener(P__Rebuilt_Shoot_Gyro_Err_4__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Gyro_Err_4 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Gyro_Err_4__Entry.SetDouble(2.5);
 
    P__Rebuilt_Shoot_Gyro_Err_5__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Gyro_Err_5");
    NTinst.AddListener(P__Rebuilt_Shoot_Gyro_Err_5__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Gyro_Err_5 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Gyro_Err_5__Entry.SetDouble(2.5);
 
    P__Rebuilt_Shoot_Gyro_Err_6__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Gyro_Err_6");
    NTinst.AddListener(P__Rebuilt_Shoot_Gyro_Err_6__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Gyro_Err_6 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Gyro_Err_6__Entry.SetDouble(10);
 
    P__Rebuilt_Shoot_Gyro_Err_7__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Gyro_Err_7");
    NTinst.AddListener(P__Rebuilt_Shoot_Gyro_Err_7__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Gyro_Err_7 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Gyro_Err_7__Entry.SetDouble(10);
 
    P__Rebuilt_Shoot_Hood_Pos_0__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_0");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_0__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_0 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_0__Entry.SetDouble(0.05);
 
    P__Rebuilt_Shoot_Hood_Pos_1__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_1");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_1__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_1 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_1__Entry.SetDouble(0.2);
 
    P__Rebuilt_Shoot_Hood_Pos_2__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_2");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_2__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_2 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_2__Entry.SetDouble(0.35);
 
    P__Rebuilt_Shoot_Hood_Pos_3__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_3");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_3__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_3 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_3__Entry.SetDouble(0.4);
 
    P__Rebuilt_Shoot_Hood_Pos_4__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_4");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_4__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_4 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_4__Entry.SetDouble(0.45);
 
    P__Rebuilt_Shoot_Hood_Pos_5__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_5");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_5__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_5 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_5__Entry.SetDouble(0.5);
 
    P__Rebuilt_Shoot_Hood_Pos_6__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_6");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_6__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_6 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_6__Entry.SetDouble(0.58);
 
    P__Rebuilt_Shoot_Hood_Pos_7__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_7");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_7__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_7 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_7__Entry.SetDouble(1);
 
    P__Rebuilt_Shoot_Hood_Pos_Max_Error__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Hood_Pos_Max_Error");
    NTinst.AddListener(P__Rebuilt_Shoot_Hood_Pos_Max_Error__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Hood_Pos_Max_Error = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Hood_Pos_Max_Error__Entry.SetDouble(0.03);
 
    P__Rebuilt_Shoot_Motor_Max_Error__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Motor_Max_Error");
    NTinst.AddListener(P__Rebuilt_Shoot_Motor_Max_Error__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Motor_Max_Error = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Motor_Max_Error__Entry.SetDouble(100);
 
    P__Rebuilt_Shoot_Robot_Velocity_Max__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Robot_Velocity_Max");
    NTinst.AddListener(P__Rebuilt_Shoot_Robot_Velocity_Max__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Robot_Velocity_Max = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Robot_Velocity_Max__Entry.SetDouble(1.7);
 
    P__Rebuilt_Shoot_Shooter_Spd_0__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_0");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_0__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_0 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_0__Entry.SetDouble(2725);
 
    P__Rebuilt_Shoot_Shooter_Spd_1__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_1");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_1__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_1 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_1__Entry.SetDouble(2975);
 
    P__Rebuilt_Shoot_Shooter_Spd_2__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_2");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_2__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_2 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_2__Entry.SetDouble(3265);
 
    P__Rebuilt_Shoot_Shooter_Spd_3__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_3");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_3__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_3 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_3__Entry.SetDouble(3425);
 
    P__Rebuilt_Shoot_Shooter_Spd_4__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_4");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_4__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_4 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_4__Entry.SetDouble(3625);
 
    P__Rebuilt_Shoot_Shooter_Spd_5__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_5");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_5__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_5 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_5__Entry.SetDouble(3775);
 
    P__Rebuilt_Shoot_Shooter_Spd_6__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_6");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_6__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_6 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_6__Entry.SetDouble(3975);
 
    P__Rebuilt_Shoot_Shooter_Spd_7__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_7");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_7__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_7 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_7__Entry.SetDouble(4500);
 
    P__Rebuilt_Shoot_Shooter_Spd_I_0__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_I_0");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_I_0__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_I_0 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_I_0__Entry.SetDouble(2825);
 
    P__Rebuilt_Shoot_Shooter_Spd_I_1__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_I_1");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_I_1__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_I_1 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_I_1__Entry.SetDouble(3075);
 
    P__Rebuilt_Shoot_Shooter_Spd_I_2__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_I_2");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_I_2__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_I_2 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_I_2__Entry.SetDouble(3365);
 
    P__Rebuilt_Shoot_Shooter_Spd_I_3__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_I_3");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_I_3__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_I_3 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_I_3__Entry.SetDouble(3525);
 
    P__Rebuilt_Shoot_Shooter_Spd_I_4__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_I_4");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_I_4__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_I_4 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_I_4__Entry.SetDouble(3725);
 
    P__Rebuilt_Shoot_Shooter_Spd_I_5__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_I_5");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_I_5__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_I_5 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_I_5__Entry.SetDouble(3875);
 
    P__Rebuilt_Shoot_Shooter_Spd_I_6__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_I_6");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_I_6__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_I_6 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_I_6__Entry.SetDouble(4075);
 
    P__Rebuilt_Shoot_Shooter_Spd_I_7__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Shooter_Spd_I_7");
    NTinst.AddListener(P__Rebuilt_Shoot_Shooter_Spd_I_7__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Shooter_Spd_I_7 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Shooter_Spd_I_7__Entry.SetDouble(4500);
 
    P__Rebuilt_Shoot_TOF_0__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_TOF_0");
    NTinst.AddListener(P__Rebuilt_Shoot_TOF_0__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_TOF_0 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_TOF_0__Entry.SetDouble(0.943);
 
    P__Rebuilt_Shoot_TOF_1__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_TOF_1");
    NTinst.AddListener(P__Rebuilt_Shoot_TOF_1__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_TOF_1 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_TOF_1__Entry.SetDouble(1.092);
 
    P__Rebuilt_Shoot_TOF_2__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_TOF_2");
    NTinst.AddListener(P__Rebuilt_Shoot_TOF_2__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_TOF_2 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_TOF_2__Entry.SetDouble(1.167);
 
    P__Rebuilt_Shoot_TOF_3__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_TOF_3");
    NTinst.AddListener(P__Rebuilt_Shoot_TOF_3__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_TOF_3 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_TOF_3__Entry.SetDouble(1.185);
 
    P__Rebuilt_Shoot_TOF_4__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_TOF_4");
    NTinst.AddListener(P__Rebuilt_Shoot_TOF_4__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_TOF_4 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_TOF_4__Entry.SetDouble(1.25);
 
    P__Rebuilt_Shoot_TOF_5__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_TOF_5");
    NTinst.AddListener(P__Rebuilt_Shoot_TOF_5__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_TOF_5 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_TOF_5__Entry.SetDouble(1.337);
 
    P__Rebuilt_Shoot_TOF_6__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_TOF_6");
    NTinst.AddListener(P__Rebuilt_Shoot_TOF_6__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_TOF_6 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_TOF_6__Entry.SetDouble(1.4);
 
    P__Rebuilt_Shoot_TOF_7__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_TOF_7");
    NTinst.AddListener(P__Rebuilt_Shoot_TOF_7__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_TOF_7 = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_TOF_7__Entry.SetDouble(1.5);
 
    P__Rebuilt_Shoot_Target_Error_Thresh__Entry = NTtable_Tune->GetEntry("Rebuilt_Shoot_Target_Error_Thresh");
    NTinst.AddListener(P__Rebuilt_Shoot_Target_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shoot_Target_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shoot_Target_Error_Thresh__Entry.SetDouble(0.1);
 
    P__Rebuilt_Shooter_Error_Integral_Enable__Entry = NTtable_Tune->GetEntry("Rebuilt_Shooter_Error_Integral_Enable");
    NTinst.AddListener(P__Rebuilt_Shooter_Error_Integral_Enable__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shooter_Error_Integral_Enable = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shooter_Error_Integral_Enable__Entry.SetDouble(300);
 
    P__Rebuilt_Shooter_Motor_Gain_FF__Entry = NTtable_Tune->GetEntry("Rebuilt_Shooter_Motor_Gain_FF");
    NTinst.AddListener(P__Rebuilt_Shooter_Motor_Gain_FF__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shooter_Motor_Gain_FF = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shooter_Motor_Gain_FF__Entry.SetDouble(0.00015);
 
    P__Rebuilt_Shooter_Motor_Gain_I__Entry = NTtable_Tune->GetEntry("Rebuilt_Shooter_Motor_Gain_I");
    NTinst.AddListener(P__Rebuilt_Shooter_Motor_Gain_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shooter_Motor_Gain_I = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shooter_Motor_Gain_I__Entry.SetDouble(0.03);
 
    P__Rebuilt_Shooter_Motor_Gain_I_Low__Entry = NTtable_Tune->GetEntry("Rebuilt_Shooter_Motor_Gain_I_Low");
    NTinst.AddListener(P__Rebuilt_Shooter_Motor_Gain_I_Low__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shooter_Motor_Gain_I_Low = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shooter_Motor_Gain_I_Low__Entry.SetDouble(0);
 
    P__Rebuilt_Shooter_Motor_Gain_P__Entry = NTtable_Tune->GetEntry("Rebuilt_Shooter_Motor_Gain_P");
    NTinst.AddListener(P__Rebuilt_Shooter_Motor_Gain_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shooter_Motor_Gain_P = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shooter_Motor_Gain_P__Entry.SetDouble(0.06);
 
    P__Rebuilt_Shot_Init_Time__Entry = NTtable_Tune->GetEntry("Rebuilt_Shot_Init_Time");
    NTinst.AddListener(P__Rebuilt_Shot_Init_Time__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Shot_Init_Time = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Shot_Init_Time__Entry.SetDouble(0.4);
 
    P__Rebuilt_Target_Feeder_Speed__Entry = NTtable_Tune->GetEntry("Rebuilt_Target_Feeder_Speed");
    NTinst.AddListener(P__Rebuilt_Target_Feeder_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Target_Feeder_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Target_Feeder_Speed__Entry.SetDouble(10080);
 
    P__Rebuilt_Target_Transfer_Speed__Entry = NTtable_Tune->GetEntry("Rebuilt_Target_Transfer_Speed");
    NTinst.AddListener(P__Rebuilt_Target_Transfer_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Target_Transfer_Speed = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Target_Transfer_Speed__Entry.SetDouble(4000);
 
    P__Rebuilt_Transfer_Error_Integral_Enable__Entry = NTtable_Tune->GetEntry("Rebuilt_Transfer_Error_Integral_Enable");
    NTinst.AddListener(P__Rebuilt_Transfer_Error_Integral_Enable__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Transfer_Error_Integral_Enable = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Transfer_Error_Integral_Enable__Entry.SetDouble(300);
 
    P__Rebuilt_Transfer_Minimum_Factor__Entry = NTtable_Tune->GetEntry("Rebuilt_Transfer_Minimum_Factor");
    NTinst.AddListener(P__Rebuilt_Transfer_Minimum_Factor__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Transfer_Minimum_Factor = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Transfer_Minimum_Factor__Entry.SetDouble(0.8);
 
    P__Rebuilt_Transfer_Motor_Gain_FF__Entry = NTtable_Tune->GetEntry("Rebuilt_Transfer_Motor_Gain_FF");
    NTinst.AddListener(P__Rebuilt_Transfer_Motor_Gain_FF__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Transfer_Motor_Gain_FF = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Transfer_Motor_Gain_FF__Entry.SetDouble(0.00012732);
 
    P__Rebuilt_Transfer_Motor_Gain_I__Entry = NTtable_Tune->GetEntry("Rebuilt_Transfer_Motor_Gain_I");
    NTinst.AddListener(P__Rebuilt_Transfer_Motor_Gain_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Transfer_Motor_Gain_I = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Transfer_Motor_Gain_I__Entry.SetDouble(2e-05);
 
    P__Rebuilt_Transfer_Motor_Gain_P__Entry = NTtable_Tune->GetEntry("Rebuilt_Transfer_Motor_Gain_P");
    NTinst.AddListener(P__Rebuilt_Transfer_Motor_Gain_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Rebuilt_Transfer_Motor_Gain_P = event.GetValueEventData()->value.GetDouble();});
    P__Rebuilt_Transfer_Motor_Gain_P__Entry.SetDouble(0.0001);
 
    P__Red_Hub_LeftX__Entry = NTtable_Tune->GetEntry("Red_Hub_LeftX");
    NTinst.AddListener(P__Red_Hub_LeftX__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Red_Hub_LeftX = event.GetValueEventData()->value.GetDouble();});
    P__Red_Hub_LeftX__Entry.SetDouble(11.369);
 
    P__Red_Hub_LeftY__Entry = NTtable_Tune->GetEntry("Red_Hub_LeftY");
    NTinst.AddListener(P__Red_Hub_LeftY__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Red_Hub_LeftY = event.GetValueEventData()->value.GetDouble();});
    P__Red_Hub_LeftY__Entry.SetDouble(4.548);
 
    P__Red_Hub_RightX__Entry = NTtable_Tune->GetEntry("Red_Hub_RightX");
    NTinst.AddListener(P__Red_Hub_RightX__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Red_Hub_RightX = event.GetValueEventData()->value.GetDouble();});
    P__Red_Hub_RightX__Entry.SetDouble(11.369);
 
    P__Red_Hub_RightY__Entry = NTtable_Tune->GetEntry("Red_Hub_RightY");
    NTinst.AddListener(P__Red_Hub_RightY__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Red_Hub_RightY = event.GetValueEventData()->value.GetDouble();});
    P__Red_Hub_RightY__Entry.SetDouble(3.354);
 
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
    P__Steering_Heading_Control_Deadzone__Entry.SetDouble(0.01);
 
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
 
    P__Steering_Heading_Dither_Gain__Entry = NTtable_Tune->GetEntry("Steering_Heading_Dither_Gain");
    NTinst.AddListener(P__Steering_Heading_Dither_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Dither_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Dither_Gain__Entry.SetDouble(2);
 
    P__Steering_Heading_Dither_Period__Entry = NTtable_Tune->GetEntry("Steering_Heading_Dither_Period");
    NTinst.AddListener(P__Steering_Heading_Dither_Period__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Dither_Period = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Dither_Period__Entry.SetDouble(0.1);
 
    P__Steering_Heading_Dither_Thresh_Off__Entry = NTtable_Tune->GetEntry("Steering_Heading_Dither_Thresh_Off");
    NTinst.AddListener(P__Steering_Heading_Dither_Thresh_Off__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Dither_Thresh_Off = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Dither_Thresh_Off__Entry.SetDouble(1);
 
    P__Steering_Heading_Dither_Thresh_On__Entry = NTtable_Tune->GetEntry("Steering_Heading_Dither_Thresh_On");
    NTinst.AddListener(P__Steering_Heading_Dither_Thresh_On__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Dither_Thresh_On = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Heading_Dither_Thresh_On__Entry.SetDouble(5);
 
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
    P__Steering_Relative_Gain__Entry.SetDouble(2.5);
 
    P__Steering_Twist_Gain__Entry = NTtable_Tune->GetEntry("Steering_Twist_Gain");
    NTinst.AddListener(P__Steering_Twist_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Twist_Gain = event.GetValueEventData()->value.GetDouble();});
    P__Steering_Twist_Gain__Entry.SetDouble(-0.5);
 
    P__TEST_Desired_Hood_Enable_OV__Entry = NTtable_Tune->GetEntry("TEST_Desired_Hood_Enable_OV");
    NTinst.AddListener(P__TEST_Desired_Hood_Enable_OV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Desired_Hood_Enable_OV = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Desired_Hood_Enable_OV__Entry.SetDouble(0);
 
    P__TEST_Desired_Hood_Pos_OV__Entry = NTtable_Tune->GetEntry("TEST_Desired_Hood_Pos_OV");
    NTinst.AddListener(P__TEST_Desired_Hood_Pos_OV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Desired_Hood_Pos_OV = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Desired_Hood_Pos_OV__Entry.SetDouble(0.05);
 
    P__TEST_Desired_Shooter_FF_DC_OV__Entry = NTtable_Tune->GetEntry("TEST_Desired_Shooter_FF_DC_OV");
    NTinst.AddListener(P__TEST_Desired_Shooter_FF_DC_OV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Desired_Shooter_FF_DC_OV = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Desired_Shooter_FF_DC_OV__Entry.SetDouble(0);
 
    P__TEST_Desired_Shooter_Speed_OV__Entry = NTtable_Tune->GetEntry("TEST_Desired_Shooter_Speed_OV");
    NTinst.AddListener(P__TEST_Desired_Shooter_Speed_OV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Desired_Shooter_Speed_OV = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Desired_Shooter_Speed_OV__Entry.SetDouble(0);
 
    P__TEST_Feeder_Motor_DC_OV__Entry = NTtable_Tune->GetEntry("TEST_Feeder_Motor_DC_OV");
    NTinst.AddListener(P__TEST_Feeder_Motor_DC_OV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Feeder_Motor_DC_OV = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Feeder_Motor_DC_OV__Entry.SetDouble(0);
 
    P__TEST_Intake_Arm_Motor_DC_OV__Entry = NTtable_Tune->GetEntry("TEST_Intake_Arm_Motor_DC_OV");
    NTinst.AddListener(P__TEST_Intake_Arm_Motor_DC_OV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Intake_Arm_Motor_DC_OV = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Intake_Arm_Motor_DC_OV__Entry.SetDouble(0);
 
    P__TEST_Intake_Roller_Motor_DC_OV__Entry = NTtable_Tune->GetEntry("TEST_Intake_Roller_Motor_DC_OV");
    NTinst.AddListener(P__TEST_Intake_Roller_Motor_DC_OV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Intake_Roller_Motor_DC_OV = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Intake_Roller_Motor_DC_OV__Entry.SetDouble(0);
 
    P__TEST_Output_Override_Flag__Entry = NTtable_Tune->GetEntry("TEST_Output_Override_Flag");
    NTinst.AddListener(P__TEST_Output_Override_Flag__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Output_Override_Flag = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Output_Override_Flag__Entry.SetDouble(0);
 
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
 
    P__TEST_Transfer_Motor_DC_OV__Entry = NTtable_Tune->GetEntry("TEST_Transfer_Motor_DC_OV");
    NTinst.AddListener(P__TEST_Transfer_Motor_DC_OV__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {TEST_Transfer_Motor_DC_OV = event.GetValueEventData()->value.GetDouble();});
    P__TEST_Transfer_Motor_DC_OV__Entry.SetDouble(0);
 
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
    I__IsBlueInactiveFirst__Entry = NTtable_Inport->GetEntry("IsBlueInactiveFirst");
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
    I__Measured_Feeder_Speed__Entry = NTtable_Inport->GetEntry("Measured_Feeder_Speed");
    I__Measured_Intake_Arm_Angle__Entry = NTtable_Inport->GetEntry("Measured_Intake_Arm_Angle");
    I__Measured_Intake_Roller_Speed__Entry = NTtable_Inport->GetEntry("Measured_Intake_Roller_Speed");
    I__Measured_Shooter_Speed_Center__Entry = NTtable_Inport->GetEntry("Measured_Shooter_Speed_Center");
    I__Measured_Shooter_Speed_Left__Entry = NTtable_Inport->GetEntry("Measured_Shooter_Speed_Left");
    I__Measured_Shooter_Speed_Right__Entry = NTtable_Inport->GetEntry("Measured_Shooter_Speed_Right");
    I__Measured_Transfer_Speed__Entry = NTtable_Inport->GetEntry("Measured_Transfer_Speed");
    I__Odom_Delta_X__Entry = NTtable_Inport->GetEntry("Odom_Delta_X");
    I__Odom_Delta_Y__Entry = NTtable_Inport->GetEntry("Odom_Delta_Y");
    I__Odom_Position_X__Entry = NTtable_Inport->GetEntry("Odom_Position_X");
    I__Odom_Position_Y__Entry = NTtable_Inport->GetEntry("Odom_Position_Y");
    I__Robot_Velocity_X__Entry = NTtable_Inport->GetEntry("Robot_Velocity_X");
    I__Robot_Velocity_Y__Entry = NTtable_Inport->GetEntry("Robot_Velocity_Y");
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
    O__Auto_Initial_Gyro_Angle__Entry = NTtable_Outport->GetEntry("Auto_Initial_Gyro_Angle");
    O__BackLeft_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("BackLeft_Drive_DutyCycle");
    O__BackLeft_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("BackLeft_Steer_DutyCycle");
    O__BackRight_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("BackRight_Drive_DutyCycle");
    O__BackRight_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("BackRight_Steer_DutyCycle");
    O__Desired_Hood_Enable__Entry = NTtable_Outport->GetEntry("Desired_Hood_Enable");
    O__Desired_Hood_Pos__Entry = NTtable_Outport->GetEntry("Desired_Hood_Pos");
    O__Desired_Shooter_FF_DC__Entry = NTtable_Outport->GetEntry("Desired_Shooter_FF_DC");
    O__Desired_Shooter_Speed__Entry = NTtable_Outport->GetEntry("Desired_Shooter_Speed");
    O__Disable_Wheels__Entry = NTtable_Outport->GetEntry("Disable_Wheels");
    O__Enable_Wheels__Entry = NTtable_Outport->GetEntry("Enable_Wheels");
    O__Feeder_Motor_DC__Entry = NTtable_Outport->GetEntry("Feeder_Motor_DC");
    O__FrontLeft_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontLeft_Drive_DutyCycle");
    O__FrontLeft_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontLeft_Steer_DutyCycle");
    O__FrontRight_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontRight_Drive_DutyCycle");
    O__FrontRight_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontRight_Steer_DutyCycle");
    O__Intake_Arm_Motor_DC__Entry = NTtable_Outport->GetEntry("Intake_Arm_Motor_DC");
    O__Intake_Roller_Motor_DC__Entry = NTtable_Outport->GetEntry("Intake_Roller_Motor_DC");
    O__Reset_Wheel_Offsets__Entry = NTtable_Outport->GetEntry("Reset_Wheel_Offsets");
    O__Shooter_Motor_Gain_Change__Entry = NTtable_Outport->GetEntry("Shooter_Motor_Gain_Change");
    O__Shooter_Motor_Gain_Ki__Entry = NTtable_Outport->GetEntry("Shooter_Motor_Gain_Ki");
    O__Shooter_Motor_Gain_Kp__Entry = NTtable_Outport->GetEntry("Shooter_Motor_Gain_Kp");
    O__Swerve_Motors_Disabled__Entry = NTtable_Outport->GetEntry("Swerve_Motors_Disabled");
    O__Transfer_Motor_DC__Entry = NTtable_Outport->GetEntry("Transfer_Motor_DC");
    O__Vision_Desired_Pipeline__Entry = NTtable_Outport->GetEntry("Vision_Desired_Pipeline");
 
// Test Points
    T__Active_GameState__Entry = NTtable_TPoint->GetEntry("Active_GameState");
    T__Auto_Desired_Dynamic_Action__Entry = NTtable_TPoint->GetEntry("Auto_Desired_Dynamic_Action");
    T__Auto_Desired_Static_Action__Entry = NTtable_TPoint->GetEntry("Auto_Desired_Static_Action");
    T__Auto_Path_Counter__Entry = NTtable_TPoint->GetEntry("Auto_Path_Counter");
    T__Auto_Path_ID__Entry = NTtable_TPoint->GetEntry("Auto_Path_ID");
    T__Auto_Spline_Enable__Entry = NTtable_TPoint->GetEntry("Auto_Spline_Enable");
    T__BL_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("BL_Desired_Module_Angle");
    T__BL_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("BL_Desired_Wheel_Speed");
    T__BL_Desired_Wheel_Speed_in__Entry = NTtable_TPoint->GetEntry("BL_Desired_Wheel_Speed_in");
    T__BR_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("BR_Desired_Module_Angle");
    T__BR_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("BR_Desired_Wheel_Speed");
    T__BR_Desired_Wheel_Speed_in__Entry = NTtable_TPoint->GetEntry("BR_Desired_Wheel_Speed_in");
    T__Button_Disable_Wheels__Entry = NTtable_TPoint->GetEntry("Button_Disable_Wheels");
    T__Button_Enable_Wheels__Entry = NTtable_TPoint->GetEntry("Button_Enable_Wheels");
    T__Button_Reset_Wheel_Offsets__Entry = NTtable_TPoint->GetEntry("Button_Reset_Wheel_Offsets");
    T__Can_Pass__Entry = NTtable_TPoint->GetEntry("Can_Pass");
    T__Desired_Feeder_Speed_Out__Entry = NTtable_TPoint->GetEntry("Desired_Feeder_Speed_Out");
    T__Drive_Joystick_X_preRL__Entry = NTtable_TPoint->GetEntry("Drive_Joystick_X_preRL");
    T__Drive_Joystick_Y_preRL__Entry = NTtable_TPoint->GetEntry("Drive_Joystick_Y_preRL");
    T__Drive_Joystick_Z_Mode__Entry = NTtable_TPoint->GetEntry("Drive_Joystick_Z_Mode");
    T__Drive_Joystick_Z_preRL__Entry = NTtable_TPoint->GetEntry("Drive_Joystick_Z_preRL");
    T__Estimated_Hood_Pos__Entry = NTtable_TPoint->GetEntry("Estimated_Hood_Pos");
    T__FL_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("FL_Desired_Module_Angle");
    T__FL_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("FL_Desired_Wheel_Speed");
    T__FL_Desired_Wheel_Speed_in__Entry = NTtable_TPoint->GetEntry("FL_Desired_Wheel_Speed_in");
    T__FR_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("FR_Desired_Module_Angle");
    T__FR_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("FR_Desired_Wheel_Speed");
    T__FR_Desired_Wheel_Speed_in__Entry = NTtable_TPoint->GetEntry("FR_Desired_Wheel_Speed_in");
    T__Feeder_Motor_Speed_tp__Entry = NTtable_TPoint->GetEntry("Feeder_Motor_Speed_tp");
    T__Gyro_Angle_SPF__Entry = NTtable_TPoint->GetEntry("Gyro_Angle_SPF");
    T__Is_Absolute_Steering_SPF__Entry = NTtable_TPoint->GetEntry("Is_Absolute_Steering_SPF");
    T__Is_Absolute_Translation_SPF__Entry = NTtable_TPoint->GetEntry("Is_Absolute_Translation_SPF");
    T__Is_Outside_Alliance_Zone__Entry = NTtable_TPoint->GetEntry("Is_Outside_Alliance_Zone");
    T__KF_Position_X__Entry = NTtable_TPoint->GetEntry("KF_Position_X");
    T__KF_Position_Y__Entry = NTtable_TPoint->GetEntry("KF_Position_Y");
    T__RB_Allow_Shoot_Gyro_Error__Entry = NTtable_TPoint->GetEntry("RB_Allow_Shoot_Gyro_Error");
    T__RB_Des_Init_Shoot_Motor_Spd__Entry = NTtable_TPoint->GetEntry("RB_Des_Init_Shoot_Motor_Spd");
    T__RB_Des_Intake_Arm_Angle__Entry = NTtable_TPoint->GetEntry("RB_Des_Intake_Arm_Angle");
    T__RB_Des_Intake_Arm_Angle_RL__Entry = NTtable_TPoint->GetEntry("RB_Des_Intake_Arm_Angle_RL");
    T__RB_Des_SS_Shoot_Motor_Spd__Entry = NTtable_TPoint->GetEntry("RB_Des_SS_Shoot_Motor_Spd");
    T__RB_Desired_Feeder_Speed__Entry = NTtable_TPoint->GetEntry("RB_Desired_Feeder_Speed");
    T__RB_Desired_Hood_Pos_Shoot__Entry = NTtable_TPoint->GetEntry("RB_Desired_Hood_Pos_Shoot");
    T__RB_Desired_Shoot_Gyro_Ang__Entry = NTtable_TPoint->GetEntry("RB_Desired_Shoot_Gyro_Ang");
    T__RB_Desired_Shooter_Speed__Entry = NTtable_TPoint->GetEntry("RB_Desired_Shooter_Speed");
    T__RB_Desired_Shot_Distance__Entry = NTtable_TPoint->GetEntry("RB_Desired_Shot_Distance");
    T__RB_Desired_Target_X__Entry = NTtable_TPoint->GetEntry("RB_Desired_Target_X");
    T__RB_Desired_Target_Y__Entry = NTtable_TPoint->GetEntry("RB_Desired_Target_Y");
    T__RB_Desired_Transfer_Speed__Entry = NTtable_TPoint->GetEntry("RB_Desired_Transfer_Speed");
    T__RB_Feeder_Motor_PID_DC__Entry = NTtable_TPoint->GetEntry("RB_Feeder_Motor_PID_DC");
    T__RB_Intake_Arm_Angle_Mod__Entry = NTtable_TPoint->GetEntry("RB_Intake_Arm_Angle_Mod");
    T__RB_Intake_Arm_Motor_PID_DC__Entry = NTtable_TPoint->GetEntry("RB_Intake_Arm_Motor_PID_DC");
    T__RB_Intake_Roller_Motor_PID_DC__Entry = NTtable_TPoint->GetEntry("RB_Intake_Roller_Motor_PID_DC");
    T__RB_IsBlueActive__Entry = NTtable_TPoint->GetEntry("RB_IsBlueActive");
    T__RB_IsRedActive__Entry = NTtable_TPoint->GetEntry("RB_IsRedActive");
    T__RB_Logic_Gyro_Angle__Entry = NTtable_TPoint->GetEntry("RB_Logic_Gyro_Angle");
    T__RB_Logic_Hood_Pos__Entry = NTtable_TPoint->GetEntry("RB_Logic_Hood_Pos");
    T__RB_Logic_Outside_Zone__Entry = NTtable_TPoint->GetEntry("RB_Logic_Outside_Zone");
    T__RB_Logic_Score_In_Zone__Entry = NTtable_TPoint->GetEntry("RB_Logic_Score_In_Zone");
    T__RB_Logic_Shooter_Speed__Entry = NTtable_TPoint->GetEntry("RB_Logic_Shooter_Speed");
    T__RB_Logic_Velocity__Entry = NTtable_TPoint->GetEntry("RB_Logic_Velocity");
    T__RB_Meas_Shooter_Speed_Max__Entry = NTtable_TPoint->GetEntry("RB_Meas_Shooter_Speed_Max");
    T__RB_Ready_to_Pass__Entry = NTtable_TPoint->GetEntry("RB_Ready_to_Pass");
    T__RB_Ready_to_Score__Entry = NTtable_TPoint->GetEntry("RB_Ready_to_Score");
    T__RB_Shift_Time_Remaining__Entry = NTtable_TPoint->GetEntry("RB_Shift_Time_Remaining");
    T__RB_Shoot_Target_X__Entry = NTtable_TPoint->GetEntry("RB_Shoot_Target_X");
    T__RB_Shoot_Target_Y__Entry = NTtable_TPoint->GetEntry("RB_Shoot_Target_Y");
    T__RB_Shooter_Active__Entry = NTtable_TPoint->GetEntry("RB_Shooter_Active");
    T__RB_Transfer_Init__Entry = NTtable_TPoint->GetEntry("RB_Transfer_Init");
    T__RB_Transfer_Motor_PID_DC__Entry = NTtable_TPoint->GetEntry("RB_Transfer_Motor_PID_DC");
    T__Relative_Enable__Entry = NTtable_TPoint->GetEntry("Relative_Enable");
    T__Relative_Error_Angle__Entry = NTtable_TPoint->GetEntry("Relative_Error_Angle");
    T__Relative_Error_X__Entry = NTtable_TPoint->GetEntry("Relative_Error_X");
    T__Relative_Error_Y__Entry = NTtable_TPoint->GetEntry("Relative_Error_Y");
    T__Robot_Reached_Destination__Entry = NTtable_TPoint->GetEntry("Robot_Reached_Destination");
    T__Spline_Enable__Entry = NTtable_TPoint->GetEntry("Spline_Enable");
    T__Spline_Follow_Index__Entry = NTtable_TPoint->GetEntry("Spline_Follow_Index");
    T__Spline_Index__Entry = NTtable_TPoint->GetEntry("Spline_Index");
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
    T__Steering_Heading_Error_deg__Entry = NTtable_TPoint->GetEntry("Steering_Heading_Error_deg");
    T__Steering_Heading_PID__Entry = NTtable_TPoint->GetEntry("Steering_Heading_PID");
    T__Steering_Localized_Cmd__Entry = NTtable_TPoint->GetEntry("Steering_Localized_Cmd");
    T__Steering_Rel_Cmd__Entry = NTtable_TPoint->GetEntry("Steering_Rel_Cmd");
    T__Steering_Rel_Cmd_SPF__Entry = NTtable_TPoint->GetEntry("Steering_Rel_Cmd_SPF");
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
    T__WhileIterator__Entry = NTtable_TPoint->GetEntry("WhileIterator");
    T__abs_Cmd_Out__Entry = NTtable_TPoint->GetEntry("abs_Cmd_Out");
    T__loop_counter_robot_control__Entry = NTtable_TPoint->GetEntry("loop_counter_robot_control");
}
 
void SimulinkNetworkTables1::PreStepCallback() {}
 
void SimulinkNetworkTables1::PostStepCallback()
{
    // Tunable Parameters
    P__Auto_Deploy_Intake_Time__Entry.SetDouble(Auto_Deploy_Intake_Time);
    P__Auto_Deploy_Intake_Time2__Entry.SetDouble(Auto_Deploy_Intake_Time2);
    P__Auto_Intake_Arm_Cycle_Delay_Time__Entry.SetDouble(Auto_Intake_Arm_Cycle_Delay_Time);
    P__Auto_Path_Chooser__Entry.SetDouble(Auto_Path_Chooser);
    P__Auto_Shoot_Time__Entry.SetDouble(Auto_Shoot_Time);
    P__Blue_Hub_LeftX__Entry.SetDouble(Blue_Hub_LeftX);
    P__Blue_Hub_LeftY__Entry.SetDouble(Blue_Hub_LeftY);
    P__Blue_Hub_RightX__Entry.SetDouble(Blue_Hub_RightX);
    P__Blue_Hub_RightY__Entry.SetDouble(Blue_Hub_RightY);
    P__Boost_Trigger_Decreasing_Limit__Entry.SetDouble(Boost_Trigger_Decreasing_Limit);
    P__Boost_Trigger_High_Speed__Entry.SetDouble(Boost_Trigger_High_Speed);
    P__Boost_Trigger_Increasing_Limit__Entry.SetDouble(Boost_Trigger_Increasing_Limit);
    P__Boost_Trigger_Low_Speed__Entry.SetDouble(Boost_Trigger_Low_Speed);
    P__Drive_Motor_Control_D__Entry.SetDouble(Drive_Motor_Control_D);
    P__Drive_Motor_Control_D_FilterCoeff__Entry.SetDouble(Drive_Motor_Control_D_FilterCoeff);
    P__Drive_Motor_Control_D_LL__Entry.SetDouble(Drive_Motor_Control_D_LL);
    P__Drive_Motor_Control_D_UL__Entry.SetDouble(Drive_Motor_Control_D_UL);
    P__Drive_Motor_Control_FF__Entry.SetDouble(Drive_Motor_Control_FF);
    P__Drive_Motor_Control_P__Entry.SetDouble(Drive_Motor_Control_P);
    P__Drive_Motor_Control_Sign_Change_Deadband__Entry.SetDouble(Drive_Motor_Control_Sign_Change_Deadband);
    P__Feeder_Max_Pulsetime__Entry.SetDouble(Feeder_Max_Pulsetime);
    P__Field_BlueAllianceZoneX__Entry.SetDouble(Field_BlueAllianceZoneX);
    P__Field_Blue_Hub_X__Entry.SetDouble(Field_Blue_Hub_X);
    P__Field_Blue_Pass_X__Entry.SetDouble(Field_Blue_Pass_X);
    P__Field_Hub_Y__Entry.SetDouble(Field_Hub_Y);
    P__Field_Length__Entry.SetDouble(Field_Length);
    P__Field_Length_Half__Entry.SetDouble(Field_Length_Half);
    P__Field_Pass_Y_Bottom__Entry.SetDouble(Field_Pass_Y_Bottom);
    P__Field_Pass_Y_Top__Entry.SetDouble(Field_Pass_Y_Top);
    P__Field_RedAllianceZoneX__Entry.SetDouble(Field_RedAllianceZoneX);
    P__Field_Red_Hub_X__Entry.SetDouble(Field_Red_Hub_X);
    P__Field_Red_Pass_X__Entry.SetDouble(Field_Red_Pass_X);
    P__Field_Translation_Control_Gain__Entry.SetDouble(Field_Translation_Control_Gain);
    P__Field_Translation_Speed_Max__Entry.SetDouble(Field_Translation_Speed_Max);
    P__Field_Width_Pass__Entry.SetDouble(Field_Width_Pass);
    P__KF_Enable__Entry.SetDouble(KF_Enable);
    P__Rate_Limit_X__Entry.SetDouble(Rate_Limit_X);
    P__Rate_Limit_Y__Entry.SetDouble(Rate_Limit_Y);
    P__Rate_Limit_Z__Entry.SetDouble(Rate_Limit_Z);
    P__Rebuilt_Des_Gyro_Shoot_Offset__Entry.SetDouble(Rebuilt_Des_Gyro_Shoot_Offset);
    P__Rebuilt_Feeder_Motor_Gain_FF__Entry.SetDouble(Rebuilt_Feeder_Motor_Gain_FF);
    P__Rebuilt_Feeder_Time_FWD__Entry.SetDouble(Rebuilt_Feeder_Time_FWD);
    P__Rebuilt_Feeder_Time_REV__Entry.SetDouble(Rebuilt_Feeder_Time_REV);
    P__Rebuilt_Hood_Servo_Pos_Max__Entry.SetDouble(Rebuilt_Hood_Servo_Pos_Max);
    P__Rebuilt_Hood_Servo_Pos_Min__Entry.SetDouble(Rebuilt_Hood_Servo_Pos_Min);
    P__Rebuilt_Hood_Servo_Rate_Limit_Dec__Entry.SetDouble(Rebuilt_Hood_Servo_Rate_Limit_Dec);
    P__Rebuilt_Hood_Servo_Rate_Limit_Inc__Entry.SetDouble(Rebuilt_Hood_Servo_Rate_Limit_Inc);
    P__Rebuilt_Intake_Arm_Gain_D__Entry.SetDouble(Rebuilt_Intake_Arm_Gain_D);
    P__Rebuilt_Intake_Arm_Gain_P__Entry.SetDouble(Rebuilt_Intake_Arm_Gain_P);
    P__Rebuilt_Intake_Cycle_Angle_In__Entry.SetDouble(Rebuilt_Intake_Cycle_Angle_In);
    P__Rebuilt_Intake_Cycle_Angle_Out__Entry.SetDouble(Rebuilt_Intake_Cycle_Angle_Out);
    P__Rebuilt_Intake_Des_Angle_In__Entry.SetDouble(Rebuilt_Intake_Des_Angle_In);
    P__Rebuilt_Intake_Des_Angle_Out__Entry.SetDouble(Rebuilt_Intake_Des_Angle_Out);
    P__Rebuilt_Intake_Meas_In_Disable__Entry.SetDouble(Rebuilt_Intake_Meas_In_Disable);
    P__Rebuilt_Intake_Meas_Out_Disable__Entry.SetDouble(Rebuilt_Intake_Meas_Out_Disable);
    P__Rebuilt_Intake_RL_Dec__Entry.SetDouble(Rebuilt_Intake_RL_Dec);
    P__Rebuilt_Intake_RL_Inc__Entry.SetDouble(Rebuilt_Intake_RL_Inc);
    P__Rebuilt_Match_Time_Auto_Timer__Entry.SetDouble(Rebuilt_Match_Time_Auto_Timer);
    P__Rebuilt_Match_Time_End_Game_Timer__Entry.SetDouble(Rebuilt_Match_Time_End_Game_Timer);
    P__Rebuilt_Match_Time_Shift_1__Entry.SetDouble(Rebuilt_Match_Time_Shift_1);
    P__Rebuilt_Match_Time_Shift_2__Entry.SetDouble(Rebuilt_Match_Time_Shift_2);
    P__Rebuilt_Match_Time_Shift_3__Entry.SetDouble(Rebuilt_Match_Time_Shift_3);
    P__Rebuilt_Match_Time_Shift_4__Entry.SetDouble(Rebuilt_Match_Time_Shift_4);
    P__Rebuilt_Match_Time_Shift_Timer__Entry.SetDouble(Rebuilt_Match_Time_Shift_Timer);
    P__Rebuilt_Match_Time_Shoot_Early__Entry.SetDouble(Rebuilt_Match_Time_Shoot_Early);
    P__Rebuilt_Match_Time_Transition__Entry.SetDouble(Rebuilt_Match_Time_Transition);
    P__Rebuilt_Negative_Feeder_Speed__Entry.SetDouble(Rebuilt_Negative_Feeder_Speed);
    P__Rebuilt_Roller_Desired_Speed__Entry.SetDouble(Rebuilt_Roller_Desired_Speed);
    P__Rebuilt_Roller_Error_Integral_Enable__Entry.SetDouble(Rebuilt_Roller_Error_Integral_Enable);
    P__Rebuilt_Roller_Intake_In_Delay__Entry.SetDouble(Rebuilt_Roller_Intake_In_Delay);
    P__Rebuilt_Roller_Motor_Gain_FF__Entry.SetDouble(Rebuilt_Roller_Motor_Gain_FF);
    P__Rebuilt_Roller_Motor_Gain_I__Entry.SetDouble(Rebuilt_Roller_Motor_Gain_I);
    P__Rebuilt_Roller_Motor_Gain_P__Entry.SetDouble(Rebuilt_Roller_Motor_Gain_P);
    P__Rebuilt_Shoot_Dist_0__Entry.SetDouble(Rebuilt_Shoot_Dist_0);
    P__Rebuilt_Shoot_Dist_1__Entry.SetDouble(Rebuilt_Shoot_Dist_1);
    P__Rebuilt_Shoot_Dist_2__Entry.SetDouble(Rebuilt_Shoot_Dist_2);
    P__Rebuilt_Shoot_Dist_3__Entry.SetDouble(Rebuilt_Shoot_Dist_3);
    P__Rebuilt_Shoot_Dist_4__Entry.SetDouble(Rebuilt_Shoot_Dist_4);
    P__Rebuilt_Shoot_Dist_5__Entry.SetDouble(Rebuilt_Shoot_Dist_5);
    P__Rebuilt_Shoot_Dist_6__Entry.SetDouble(Rebuilt_Shoot_Dist_6);
    P__Rebuilt_Shoot_Dist_7__Entry.SetDouble(Rebuilt_Shoot_Dist_7);
    P__Rebuilt_Shoot_Gyro_Err_0__Entry.SetDouble(Rebuilt_Shoot_Gyro_Err_0);
    P__Rebuilt_Shoot_Gyro_Err_1__Entry.SetDouble(Rebuilt_Shoot_Gyro_Err_1);
    P__Rebuilt_Shoot_Gyro_Err_2__Entry.SetDouble(Rebuilt_Shoot_Gyro_Err_2);
    P__Rebuilt_Shoot_Gyro_Err_3__Entry.SetDouble(Rebuilt_Shoot_Gyro_Err_3);
    P__Rebuilt_Shoot_Gyro_Err_4__Entry.SetDouble(Rebuilt_Shoot_Gyro_Err_4);
    P__Rebuilt_Shoot_Gyro_Err_5__Entry.SetDouble(Rebuilt_Shoot_Gyro_Err_5);
    P__Rebuilt_Shoot_Gyro_Err_6__Entry.SetDouble(Rebuilt_Shoot_Gyro_Err_6);
    P__Rebuilt_Shoot_Gyro_Err_7__Entry.SetDouble(Rebuilt_Shoot_Gyro_Err_7);
    P__Rebuilt_Shoot_Hood_Pos_0__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_0);
    P__Rebuilt_Shoot_Hood_Pos_1__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_1);
    P__Rebuilt_Shoot_Hood_Pos_2__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_2);
    P__Rebuilt_Shoot_Hood_Pos_3__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_3);
    P__Rebuilt_Shoot_Hood_Pos_4__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_4);
    P__Rebuilt_Shoot_Hood_Pos_5__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_5);
    P__Rebuilt_Shoot_Hood_Pos_6__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_6);
    P__Rebuilt_Shoot_Hood_Pos_7__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_7);
    P__Rebuilt_Shoot_Hood_Pos_Max_Error__Entry.SetDouble(Rebuilt_Shoot_Hood_Pos_Max_Error);
    P__Rebuilt_Shoot_Motor_Max_Error__Entry.SetDouble(Rebuilt_Shoot_Motor_Max_Error);
    P__Rebuilt_Shoot_Robot_Velocity_Max__Entry.SetDouble(Rebuilt_Shoot_Robot_Velocity_Max);
    P__Rebuilt_Shoot_Shooter_Spd_0__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_0);
    P__Rebuilt_Shoot_Shooter_Spd_1__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_1);
    P__Rebuilt_Shoot_Shooter_Spd_2__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_2);
    P__Rebuilt_Shoot_Shooter_Spd_3__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_3);
    P__Rebuilt_Shoot_Shooter_Spd_4__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_4);
    P__Rebuilt_Shoot_Shooter_Spd_5__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_5);
    P__Rebuilt_Shoot_Shooter_Spd_6__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_6);
    P__Rebuilt_Shoot_Shooter_Spd_7__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_7);
    P__Rebuilt_Shoot_Shooter_Spd_I_0__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_I_0);
    P__Rebuilt_Shoot_Shooter_Spd_I_1__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_I_1);
    P__Rebuilt_Shoot_Shooter_Spd_I_2__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_I_2);
    P__Rebuilt_Shoot_Shooter_Spd_I_3__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_I_3);
    P__Rebuilt_Shoot_Shooter_Spd_I_4__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_I_4);
    P__Rebuilt_Shoot_Shooter_Spd_I_5__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_I_5);
    P__Rebuilt_Shoot_Shooter_Spd_I_6__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_I_6);
    P__Rebuilt_Shoot_Shooter_Spd_I_7__Entry.SetDouble(Rebuilt_Shoot_Shooter_Spd_I_7);
    P__Rebuilt_Shoot_TOF_0__Entry.SetDouble(Rebuilt_Shoot_TOF_0);
    P__Rebuilt_Shoot_TOF_1__Entry.SetDouble(Rebuilt_Shoot_TOF_1);
    P__Rebuilt_Shoot_TOF_2__Entry.SetDouble(Rebuilt_Shoot_TOF_2);
    P__Rebuilt_Shoot_TOF_3__Entry.SetDouble(Rebuilt_Shoot_TOF_3);
    P__Rebuilt_Shoot_TOF_4__Entry.SetDouble(Rebuilt_Shoot_TOF_4);
    P__Rebuilt_Shoot_TOF_5__Entry.SetDouble(Rebuilt_Shoot_TOF_5);
    P__Rebuilt_Shoot_TOF_6__Entry.SetDouble(Rebuilt_Shoot_TOF_6);
    P__Rebuilt_Shoot_TOF_7__Entry.SetDouble(Rebuilt_Shoot_TOF_7);
    P__Rebuilt_Shoot_Target_Error_Thresh__Entry.SetDouble(Rebuilt_Shoot_Target_Error_Thresh);
    P__Rebuilt_Shooter_Error_Integral_Enable__Entry.SetDouble(Rebuilt_Shooter_Error_Integral_Enable);
    P__Rebuilt_Shooter_Motor_Gain_FF__Entry.SetDouble(Rebuilt_Shooter_Motor_Gain_FF);
    P__Rebuilt_Shooter_Motor_Gain_I__Entry.SetDouble(Rebuilt_Shooter_Motor_Gain_I);
    P__Rebuilt_Shooter_Motor_Gain_I_Low__Entry.SetDouble(Rebuilt_Shooter_Motor_Gain_I_Low);
    P__Rebuilt_Shooter_Motor_Gain_P__Entry.SetDouble(Rebuilt_Shooter_Motor_Gain_P);
    P__Rebuilt_Shot_Init_Time__Entry.SetDouble(Rebuilt_Shot_Init_Time);
    P__Rebuilt_Target_Feeder_Speed__Entry.SetDouble(Rebuilt_Target_Feeder_Speed);
    P__Rebuilt_Target_Transfer_Speed__Entry.SetDouble(Rebuilt_Target_Transfer_Speed);
    P__Rebuilt_Transfer_Error_Integral_Enable__Entry.SetDouble(Rebuilt_Transfer_Error_Integral_Enable);
    P__Rebuilt_Transfer_Minimum_Factor__Entry.SetDouble(Rebuilt_Transfer_Minimum_Factor);
    P__Rebuilt_Transfer_Motor_Gain_FF__Entry.SetDouble(Rebuilt_Transfer_Motor_Gain_FF);
    P__Rebuilt_Transfer_Motor_Gain_I__Entry.SetDouble(Rebuilt_Transfer_Motor_Gain_I);
    P__Rebuilt_Transfer_Motor_Gain_P__Entry.SetDouble(Rebuilt_Transfer_Motor_Gain_P);
    P__Red_Hub_LeftX__Entry.SetDouble(Red_Hub_LeftX);
    P__Red_Hub_LeftY__Entry.SetDouble(Red_Hub_LeftY);
    P__Red_Hub_RightX__Entry.SetDouble(Red_Hub_RightX);
    P__Red_Hub_RightY__Entry.SetDouble(Red_Hub_RightY);
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
    P__Steering_Heading_Dither_Gain__Entry.SetDouble(Steering_Heading_Dither_Gain);
    P__Steering_Heading_Dither_Period__Entry.SetDouble(Steering_Heading_Dither_Period);
    P__Steering_Heading_Dither_Thresh_Off__Entry.SetDouble(Steering_Heading_Dither_Thresh_Off);
    P__Steering_Heading_Dither_Thresh_On__Entry.SetDouble(Steering_Heading_Dither_Thresh_On);
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
    P__TEST_Desired_Hood_Enable_OV__Entry.SetDouble(TEST_Desired_Hood_Enable_OV);
    P__TEST_Desired_Hood_Pos_OV__Entry.SetDouble(TEST_Desired_Hood_Pos_OV);
    P__TEST_Desired_Shooter_FF_DC_OV__Entry.SetDouble(TEST_Desired_Shooter_FF_DC_OV);
    P__TEST_Desired_Shooter_Speed_OV__Entry.SetDouble(TEST_Desired_Shooter_Speed_OV);
    P__TEST_Feeder_Motor_DC_OV__Entry.SetDouble(TEST_Feeder_Motor_DC_OV);
    P__TEST_Intake_Arm_Motor_DC_OV__Entry.SetDouble(TEST_Intake_Arm_Motor_DC_OV);
    P__TEST_Intake_Roller_Motor_DC_OV__Entry.SetDouble(TEST_Intake_Roller_Motor_DC_OV);
    P__TEST_Output_Override_Flag__Entry.SetDouble(TEST_Output_Override_Flag);
    P__TEST_Pipeline__Entry.SetDouble(TEST_Pipeline);
    P__TEST_Swerve_Mode_Override_Flag__Entry.SetDouble(TEST_Swerve_Mode_Override_Flag);
    P__TEST_Swerve_Mode_Steering__Entry.SetDouble(TEST_Swerve_Mode_Steering);
    P__TEST_Swerve_Mode_Translation__Entry.SetDouble(TEST_Swerve_Mode_Translation);
    P__TEST_Transfer_Motor_DC_OV__Entry.SetDouble(TEST_Transfer_Motor_DC_OV);
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
    I__IsBlueInactiveFirst__Entry.SetDouble(Robot_Control_U.IsBlueInactiveFirst);
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
    I__Measured_Feeder_Speed__Entry.SetDouble(Robot_Control_U.Measured_Feeder_Speed);
    I__Measured_Intake_Arm_Angle__Entry.SetDouble(Robot_Control_U.Measured_Intake_Arm_Angle);
    I__Measured_Intake_Roller_Speed__Entry.SetDouble(Robot_Control_U.Measured_Intake_Roller_Speed);
    I__Measured_Shooter_Speed_Center__Entry.SetDouble(Robot_Control_U.Measured_Shooter_Speed_Center);
    I__Measured_Shooter_Speed_Left__Entry.SetDouble(Robot_Control_U.Measured_Shooter_Speed_Left);
    I__Measured_Shooter_Speed_Right__Entry.SetDouble(Robot_Control_U.Measured_Shooter_Speed_Right);
    I__Measured_Transfer_Speed__Entry.SetDouble(Robot_Control_U.Measured_Transfer_Speed);
    I__Odom_Delta_X__Entry.SetDouble(Robot_Control_U.Odom_Delta_X);
    I__Odom_Delta_Y__Entry.SetDouble(Robot_Control_U.Odom_Delta_Y);
    I__Odom_Position_X__Entry.SetDouble(Robot_Control_U.Odom_Position_X);
    I__Odom_Position_Y__Entry.SetDouble(Robot_Control_U.Odom_Position_Y);
    I__Robot_Velocity_X__Entry.SetDouble(Robot_Control_U.Robot_Velocity_X);
    I__Robot_Velocity_Y__Entry.SetDouble(Robot_Control_U.Robot_Velocity_Y);
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
    O__Auto_Initial_Gyro_Angle__Entry.SetDouble(Robot_Control_Y.Auto_Initial_Gyro_Angle);
    O__BackLeft_Drive_DutyCycle__Entry.SetDouble(Robot_Control_Y.BackLeft_Drive_DutyCycle);
    O__BackLeft_Steer_DutyCycle__Entry.SetDouble(Robot_Control_Y.BackLeft_Steer_DutyCycle);
    O__BackRight_Drive_DutyCycle__Entry.SetDouble(Robot_Control_Y.BackRight_Drive_DutyCycle);
    O__BackRight_Steer_DutyCycle__Entry.SetDouble(Robot_Control_Y.BackRight_Steer_DutyCycle);
    O__Desired_Hood_Enable__Entry.SetDouble(Robot_Control_Y.Desired_Hood_Enable);
    O__Desired_Hood_Pos__Entry.SetDouble(Robot_Control_Y.Desired_Hood_Pos);
    O__Desired_Shooter_FF_DC__Entry.SetDouble(Robot_Control_Y.Desired_Shooter_FF_DC);
    O__Desired_Shooter_Speed__Entry.SetDouble(Robot_Control_Y.Desired_Shooter_Speed);
    O__Disable_Wheels__Entry.SetDouble(Robot_Control_Y.Disable_Wheels);
    O__Enable_Wheels__Entry.SetDouble(Robot_Control_Y.Enable_Wheels);
    O__Feeder_Motor_DC__Entry.SetDouble(Robot_Control_Y.Feeder_Motor_DC);
    O__FrontLeft_Drive_DutyCycle__Entry.SetDouble(Robot_Control_Y.FrontLeft_Drive_DutyCycle);
    O__FrontLeft_Steer_DutyCycle__Entry.SetDouble(Robot_Control_Y.FrontLeft_Steer_DutyCycle);
    O__FrontRight_Drive_DutyCycle__Entry.SetDouble(Robot_Control_Y.FrontRight_Drive_DutyCycle);
    O__FrontRight_Steer_DutyCycle__Entry.SetDouble(Robot_Control_Y.FrontRight_Steer_DutyCycle);
    O__Intake_Arm_Motor_DC__Entry.SetDouble(Robot_Control_Y.Intake_Arm_Motor_DC);
    O__Intake_Roller_Motor_DC__Entry.SetDouble(Robot_Control_Y.Intake_Roller_Motor_DC);
    O__Reset_Wheel_Offsets__Entry.SetDouble(Robot_Control_Y.Reset_Wheel_Offsets);
    O__Shooter_Motor_Gain_Change__Entry.SetDouble(Robot_Control_Y.Shooter_Motor_Gain_Change);
    O__Shooter_Motor_Gain_Ki__Entry.SetDouble(Robot_Control_Y.Shooter_Motor_Gain_Ki);
    O__Shooter_Motor_Gain_Kp__Entry.SetDouble(Robot_Control_Y.Shooter_Motor_Gain_Kp);
    O__Swerve_Motors_Disabled__Entry.SetDouble(Robot_Control_Y.Swerve_Motors_Disabled);
    O__Transfer_Motor_DC__Entry.SetDouble(Robot_Control_Y.Transfer_Motor_DC);
    O__Vision_Desired_Pipeline__Entry.SetDouble(Robot_Control_Y.Vision_Desired_Pipeline);
    // Test Points
    T__Active_GameState__Entry.SetDouble(Robot_Control_B.Active_GameState);
    T__Auto_Desired_Dynamic_Action__Entry.SetDouble(Robot_Control_B.Auto_Desired_Dynamic_Action);
    T__Auto_Desired_Static_Action__Entry.SetDouble(Robot_Control_B.Auto_Desired_Static_Action);
    T__Auto_Path_Counter__Entry.SetDouble(Robot_Control_B.Auto_Path_Counter);
    T__Auto_Path_ID__Entry.SetDouble(Robot_Control_B.Auto_Path_ID);
    T__Auto_Spline_Enable__Entry.SetDouble(Robot_Control_B.Auto_Spline_Enable);
    T__BL_Desired_Module_Angle__Entry.SetDouble(Robot_Control_B.BL_Desired_Module_Angle);
    T__BL_Desired_Wheel_Speed__Entry.SetDouble(Robot_Control_B.BL_Desired_Wheel_Speed);
    T__BL_Desired_Wheel_Speed_in__Entry.SetDouble(Robot_Control_B.BL_Desired_Wheel_Speed_in);
    T__BR_Desired_Module_Angle__Entry.SetDouble(Robot_Control_B.BR_Desired_Module_Angle);
    T__BR_Desired_Wheel_Speed__Entry.SetDouble(Robot_Control_B.BR_Desired_Wheel_Speed);
    T__BR_Desired_Wheel_Speed_in__Entry.SetDouble(Robot_Control_B.BR_Desired_Wheel_Speed_in);
    T__Button_Disable_Wheels__Entry.SetDouble(Robot_Control_B.Button_Disable_Wheels);
    T__Button_Enable_Wheels__Entry.SetDouble(Robot_Control_B.Button_Enable_Wheels);
    T__Button_Reset_Wheel_Offsets__Entry.SetDouble(Robot_Control_B.Button_Reset_Wheel_Offsets);
    T__Can_Pass__Entry.SetDouble(Robot_Control_B.Can_Pass);
    T__Desired_Feeder_Speed_Out__Entry.SetDouble(Robot_Control_B.Desired_Feeder_Speed_Out);
    T__Drive_Joystick_X_preRL__Entry.SetDouble(Robot_Control_B.Drive_Joystick_X_preRL);
    T__Drive_Joystick_Y_preRL__Entry.SetDouble(Robot_Control_B.Drive_Joystick_Y_preRL);
    T__Drive_Joystick_Z_Mode__Entry.SetDouble(Robot_Control_B.Drive_Joystick_Z_Mode);
    T__Drive_Joystick_Z_preRL__Entry.SetDouble(Robot_Control_B.Drive_Joystick_Z_preRL);
    T__Estimated_Hood_Pos__Entry.SetDouble(Robot_Control_B.Estimated_Hood_Pos);
    T__FL_Desired_Module_Angle__Entry.SetDouble(Robot_Control_B.FL_Desired_Module_Angle);
    T__FL_Desired_Wheel_Speed__Entry.SetDouble(Robot_Control_B.FL_Desired_Wheel_Speed);
    T__FL_Desired_Wheel_Speed_in__Entry.SetDouble(Robot_Control_B.FL_Desired_Wheel_Speed_in);
    T__FR_Desired_Module_Angle__Entry.SetDouble(Robot_Control_B.FR_Desired_Module_Angle);
    T__FR_Desired_Wheel_Speed__Entry.SetDouble(Robot_Control_B.FR_Desired_Wheel_Speed);
    T__FR_Desired_Wheel_Speed_in__Entry.SetDouble(Robot_Control_B.FR_Desired_Wheel_Speed_in);
    T__Feeder_Motor_Speed_tp__Entry.SetDouble(Robot_Control_B.Feeder_Motor_Speed_tp);
    T__Gyro_Angle_SPF__Entry.SetDouble(Robot_Control_B.Gyro_Angle_SPF);
    T__Is_Absolute_Steering_SPF__Entry.SetDouble(Robot_Control_B.Is_Absolute_Steering_SPF);
    T__Is_Absolute_Translation_SPF__Entry.SetDouble(Robot_Control_B.Is_Absolute_Translation_SPF);
    T__Is_Outside_Alliance_Zone__Entry.SetDouble(Robot_Control_B.Is_Outside_Alliance_Zone);
    T__KF_Position_X__Entry.SetDouble(Robot_Control_B.KF_Position_X);
    T__KF_Position_Y__Entry.SetDouble(Robot_Control_B.KF_Position_Y);
    T__RB_Allow_Shoot_Gyro_Error__Entry.SetDouble(Robot_Control_B.RB_Allow_Shoot_Gyro_Error);
    T__RB_Des_Init_Shoot_Motor_Spd__Entry.SetDouble(Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd);
    T__RB_Des_Intake_Arm_Angle__Entry.SetDouble(Robot_Control_B.RB_Des_Intake_Arm_Angle);
    T__RB_Des_Intake_Arm_Angle_RL__Entry.SetDouble(Robot_Control_B.RB_Des_Intake_Arm_Angle_RL);
    T__RB_Des_SS_Shoot_Motor_Spd__Entry.SetDouble(Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd);
    T__RB_Desired_Feeder_Speed__Entry.SetDouble(Robot_Control_B.RB_Desired_Feeder_Speed);
    T__RB_Desired_Hood_Pos_Shoot__Entry.SetDouble(Robot_Control_B.RB_Desired_Hood_Pos_Shoot);
    T__RB_Desired_Shoot_Gyro_Ang__Entry.SetDouble(Robot_Control_B.RB_Desired_Shoot_Gyro_Ang);
    T__RB_Desired_Shooter_Speed__Entry.SetDouble(Robot_Control_B.RB_Desired_Shooter_Speed);
    T__RB_Desired_Shot_Distance__Entry.SetDouble(Robot_Control_B.RB_Desired_Shot_Distance);
    T__RB_Desired_Target_X__Entry.SetDouble(Robot_Control_B.RB_Desired_Target_X);
    T__RB_Desired_Target_Y__Entry.SetDouble(Robot_Control_B.RB_Desired_Target_Y);
    T__RB_Desired_Transfer_Speed__Entry.SetDouble(Robot_Control_B.RB_Desired_Transfer_Speed);
    T__RB_Feeder_Motor_PID_DC__Entry.SetDouble(Robot_Control_B.RB_Feeder_Motor_PID_DC);
    T__RB_Intake_Arm_Angle_Mod__Entry.SetDouble(Robot_Control_B.RB_Intake_Arm_Angle_Mod);
    T__RB_Intake_Arm_Motor_PID_DC__Entry.SetDouble(Robot_Control_B.RB_Intake_Arm_Motor_PID_DC);
    T__RB_Intake_Roller_Motor_PID_DC__Entry.SetDouble(Robot_Control_B.RB_Intake_Roller_Motor_PID_DC);
    T__RB_IsBlueActive__Entry.SetDouble(Robot_Control_B.RB_IsBlueActive);
    T__RB_IsRedActive__Entry.SetDouble(Robot_Control_B.RB_IsRedActive);
    T__RB_Logic_Gyro_Angle__Entry.SetDouble(Robot_Control_B.RB_Logic_Gyro_Angle);
    T__RB_Logic_Hood_Pos__Entry.SetDouble(Robot_Control_B.RB_Logic_Hood_Pos);
    T__RB_Logic_Outside_Zone__Entry.SetDouble(Robot_Control_B.RB_Logic_Outside_Zone);
    T__RB_Logic_Score_In_Zone__Entry.SetDouble(Robot_Control_B.RB_Logic_Score_In_Zone);
    T__RB_Logic_Shooter_Speed__Entry.SetDouble(Robot_Control_B.RB_Logic_Shooter_Speed);
    T__RB_Logic_Velocity__Entry.SetDouble(Robot_Control_B.RB_Logic_Velocity);
    T__RB_Meas_Shooter_Speed_Max__Entry.SetDouble(Robot_Control_B.RB_Meas_Shooter_Speed_Max);
    T__RB_Ready_to_Pass__Entry.SetDouble(Robot_Control_B.RB_Ready_to_Pass);
    T__RB_Ready_to_Score__Entry.SetDouble(Robot_Control_B.RB_Ready_to_Score);
    T__RB_Shift_Time_Remaining__Entry.SetDouble(Robot_Control_B.RB_Shift_Time_Remaining);
    T__RB_Shoot_Target_X__Entry.SetDouble(Robot_Control_B.RB_Shoot_Target_X);
    T__RB_Shoot_Target_Y__Entry.SetDouble(Robot_Control_B.RB_Shoot_Target_Y);
    T__RB_Shooter_Active__Entry.SetDouble(Robot_Control_B.RB_Shooter_Active);
    T__RB_Transfer_Init__Entry.SetDouble(Robot_Control_B.RB_Transfer_Init);
    T__RB_Transfer_Motor_PID_DC__Entry.SetDouble(Robot_Control_B.RB_Transfer_Motor_PID_DC);
    T__Relative_Enable__Entry.SetDouble(Robot_Control_B.Relative_Enable);
    T__Relative_Error_Angle__Entry.SetDouble(Robot_Control_B.Relative_Error_Angle);
    T__Relative_Error_X__Entry.SetDouble(Robot_Control_B.Relative_Error_X);
    T__Relative_Error_Y__Entry.SetDouble(Robot_Control_B.Relative_Error_Y);
    T__Robot_Reached_Destination__Entry.SetDouble(Robot_Control_B.Robot_Reached_Destination);
    T__Spline_Enable__Entry.SetDouble(Robot_Control_B.Spline_Enable);
    T__Spline_Follow_Index__Entry.SetDouble(Robot_Control_B.Spline_Follow_Index);
    T__Spline_Index__Entry.SetDouble(Robot_Control_B.Spline_Index);
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
    T__Steering_Heading_Error_deg__Entry.SetDouble(Robot_Control_B.Steering_Heading_Error_deg);
    T__Steering_Heading_PID__Entry.SetDouble(Robot_Control_B.Steering_Heading_PID);
    T__Steering_Localized_Cmd__Entry.SetDouble(Robot_Control_B.Steering_Localized_Cmd);
    T__Steering_Rel_Cmd__Entry.SetDouble(Robot_Control_B.Steering_Rel_Cmd);
    T__Steering_Rel_Cmd_SPF__Entry.SetDouble(Robot_Control_B.Steering_Rel_Cmd_SPF);
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
    T__WhileIterator__Entry.SetDouble(Robot_Control_B.WhileIterator);
    T__abs_Cmd_Out__Entry.SetDouble(Robot_Control_B.abs_Cmd_Out);
    T__loop_counter_robot_control__Entry.SetDouble(Robot_Control_B.loop_counter_robot_control);
}
// Why are you reading to the bottom of an autogen file?
// Get a life...
