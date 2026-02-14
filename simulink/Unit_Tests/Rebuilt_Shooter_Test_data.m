Target_Feeder_Speed = 2000;
Transfer_Minimum_Factor = 0.8;

Target_Transfer_Speed = 2000;

BlueAllianceZoneX = 182.11*0.0254;
RedAllianceZoneX = (651.22-182.11)*0.0254;

Robot_Velocity_Maximum_Shooter = 1;

Heading_Max_Error_Shoot = 5;

Shooter_Motor_Max_Error_Shoot = 100;

Hood_Servo_Rate_Limit_Inc = 32/50*0.02;   % no load 32 mm/sec, total stroke 50 mm
Hood_Servo_Rate_Limit_Dec = -Hood_Servo_Rate_Limit_Inc;

Hood_Pos_Max_Error_Shoot = 0.03;

Feeder_Motor_DC_Gain = 1/7000;

Transfer_Motor_Gain_FF = 1/7000;
Transfer_Motor_Gain_P = 0;
Transfer_Motor_Gain_I = 0;
Transfer_Motor_Gain_D = 0;

Shooter_Error_Integral_Enable = 300;