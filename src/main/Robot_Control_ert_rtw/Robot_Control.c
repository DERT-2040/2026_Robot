/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.474
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Mar 15 13:17:52 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Robot_Control.h"
#include "rtwtypes.h"
#include "Robot_Control_private.h"
#include "rt_powd_snf.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "rt_hypotd_snf.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "LookUp_real_T_real_T.h"
#include "look1_binlcpw.h"
#include "plook_u32d_evencka.h"

/* Named constants for Chart: '<S6>/Chart' */
#define Robot_Co_IN_Move_Intake_Arm_Out ((uint8_T)2U)
#define Robot_Con_IN_Move_Intake_Arm_In ((uint8_T)1U)
#define Robot_Contro_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Robot_Contro_IN_Wait_for_Button ((uint8_T)3U)

/* Named constants for Chart: '<S11>/Chart' */
#define Robot_Control_IN_Disabled      ((uint8_T)1U)
#define Robot_Control_IN_Not_Disabled  ((uint8_T)2U)

/* Named constants for Chart: '<S12>/Shooter_Transfer_Feeder Chart' */
#define Robot_Control_IN_Feeder        ((uint8_T)1U)
#define Robot_Control_IN_Not_Shooting  ((uint8_T)1U)
#define Robot_Control_IN_Shooting      ((uint8_T)2U)
#define Robot_Control_IN_Spinning_Up   ((uint8_T)2U)
#define Robot_Control_IN_Transfer      ((uint8_T)3U)

/* Named constants for Chart: '<S20>/Chart' */
#define Robot_Control_IN_End_Action    ((uint8_T)1U)
#define Robot_Control_IN_Follow_Path   ((uint8_T)2U)
#define Robot_Control_IN_Start_Action  ((uint8_T)3U)

/* Exported block parameters */
real_T Auto_Path_Chooser = 1.0;        /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S21>/Constant17'
                                        */
real_T Auto_Shoot_Time = 3.0;          /* Variable: Auto_Shoot_Time
                                        * Referenced by: '<S24>/Constant'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S428>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S424>/Constant'
                                        *   '<S424>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S428>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S424>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S259>/Constant3'
                                        *   '<S280>/Constant3'
                                        *   '<S301>/Constant3'
                                        *   '<S322>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S259>/Constant2'
                                   *   '<S280>/Constant2'
                                   *   '<S301>/Constant2'
                                   *   '<S322>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S259>/Saturation'
                                        *   '<S280>/Saturation'
                                        *   '<S301>/Saturation'
                                        *   '<S322>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S259>/Saturation'
                                        *   '<S280>/Saturation'
                                        *   '<S301>/Saturation'
                                        *   '<S322>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S259>/Gain'
                                            *   '<S280>/Gain'
                                            *   '<S301>/Gain'
                                            *   '<S322>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S259>/Gain2'
                                        *   '<S280>/Gain2'
                                        *   '<S301>/Gain2'
                                        *   '<S322>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S259>/Saturation1'
                                         *   '<S280>/Saturation1'
                                         *   '<S301>/Saturation1'
                                         *   '<S322>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S259>/Saturation1'
                                        *   '<S280>/Saturation1'
                                        *   '<S301>/Saturation1'
                                        *   '<S322>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S259>/Gain1'
                                        *   '<S280>/Gain1'
                                        *   '<S301>/Gain1'
                                        *   '<S322>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S264>/Constant'
                            *   '<S285>/Constant'
                            *   '<S306>/Constant'
                            *   '<S327>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 2.0;     /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S178>/BlueAllianceZoneX'
                                         *   '<S180>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S147>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S147>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S147>/Constant1'
                                        *   '<S147>/Switch3'
                                        */
real_T Field_Pass_Y_Bottom = 0.63297;  /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S147>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 7.4364;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S147>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S179>/RedAllianceZoneX'
                                         *   '<S181>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S147>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S147>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S414>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S414>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rate_Limit_Max_X = 0.02;        /* Variable: Rate_Limit_Max_X
                                        * Referenced by: '<S39>/Constant3'
                                        */
real_T Rate_Limit_Max_Y = 0.02;        /* Variable: Rate_Limit_Max_Y
                                        * Referenced by: '<S43>/Constant3'
                                        */
real_T Rate_Limit_Max_Z = 0.02;        /* Variable: Rate_Limit_Max_Z
                                        * Referenced by: '<S47>/Constant3'
                                        */
real_T Rate_Limit_Min_X = -0.02;       /* Variable: Rate_Limit_Min_X
                                        * Referenced by: '<S39>/Constant1'
                                        */
real_T Rate_Limit_Min_Y = -0.02;       /* Variable: Rate_Limit_Min_Y
                                        * Referenced by: '<S43>/Constant1'
                                        */
real_T Rate_Limit_Min_Z = -0.02;       /* Variable: Rate_Limit_Min_Z
                                        * Referenced by: '<S47>/Constant1'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = 0.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S142>/Constant'
                                       */
real_T Rebuilt_Feeder_Motor_Gain_FF = 0.00012732;/* Variable: Rebuilt_Feeder_Motor_Gain_FF
                                                  * Referenced by: '<S12>/Constant'
                                                  */
real_T Rebuilt_Hood_Servo_Pos_Max = 1.0;/* Variable: Rebuilt_Hood_Servo_Pos_Max
                                         * Referenced by: '<S10>/Saturation'
                                         */
real_T Rebuilt_Hood_Servo_Pos_Min = 0.05;/* Variable: Rebuilt_Hood_Servo_Pos_Min
                                          * Referenced by:
                                          *   '<S10>/Saturation'
                                          *   '<S140>/Constant3'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S127>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S127>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S61>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.005;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                          * Referenced by: '<S61>/Gain1'
                                          */
real_T Rebuilt_Intake_Cycle_Angle_In = -10.0;
                                      /* Variable: Rebuilt_Intake_Cycle_Angle_In
                                       * Referenced by: '<S6>/Chart'
                                       */
real_T Rebuilt_Intake_Cycle_Angle_Out = 10.0;
                                     /* Variable: Rebuilt_Intake_Cycle_Angle_Out
                                      * Referenced by: '<S6>/Chart'
                                      */
real_T Rebuilt_Intake_Des_Angle_In = -40.0;/* Variable: Rebuilt_Intake_Des_Angle_In
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S57>/Constant'
                                            */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S58>/Constant'
                                            */
real_T Rebuilt_Intake_Meas_In_Disable = -20.0;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S59>/Constant'
                                      */
real_T Rebuilt_Intake_Meas_Out_Disable = 80.0;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S60>/Constant'
                                     */
real_T Rebuilt_Intake_RL_Dec = -2.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S55>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 2.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S55>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 30.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S165>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by: '<S170>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S161>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S162>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S163>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S164>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S166>/Unit Delay'
                                      *   '<S167>/Unit Delay'
                                      *   '<S168>/Unit Delay'
                                      *   '<S169>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 3.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S171>/Constant'
                                      *   '<S172>/Constant'
                                      *   '<S173>/Constant'
                                      *   '<S174>/Constant'
                                      */
real_T Rebuilt_Match_Time_TeleOp = 140.0;/* Variable: Rebuilt_Match_Time_TeleOp
                                          * Referenced by: '<S133>/Constant'
                                          */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S159>/Constant'
                                       */
real_T Rebuilt_Negative_Feeder_Speed = -1000.0;
                                      /* Variable: Rebuilt_Negative_Feeder_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Roller_Desired_Speed = 4500.0;/* Variable: Rebuilt_Roller_Desired_Speed
                                              * Referenced by: '<S6>/Constant'
                                              */
real_T Rebuilt_Roller_Error_Integral_Enable = 300.0;
                               /* Variable: Rebuilt_Roller_Error_Integral_Enable
                                * Referenced by: '<S56>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00012732;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                                  * Referenced by: '<S69>/Gain'
                                                  */
real_T Rebuilt_Roller_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                             * Referenced by: '<S69>/Gain2'
                                             */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0001;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                             * Referenced by: '<S69>/Gain1'
                                             */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S148>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S148>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S148>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S148>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S148>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S148>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S148>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S148>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S144>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S144>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S144>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 2.7; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S144>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S144>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S144>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S144>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S144>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S145>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S145>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S145>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S145>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S145>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S145>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S145>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S145>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S135>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S135>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S135>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2700.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S158>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2900.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S158>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3150.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S158>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3300.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S158>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S158>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3650.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S158>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3850.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S158>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S158>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S157>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S157>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3450.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S157>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3600.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S157>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3800.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S157>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3950.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S157>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S157>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S157>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S151>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S151>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S151>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S151>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S151>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S151>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S151>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S151>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S155>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S136>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S183>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S183>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.001;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                             * Referenced by: '<S183>/Gain1'
                                             */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S146>/Constant2'
                                        */
real_T Rebuilt_Target_Feeder_Speed = 3360.0;/* Variable: Rebuilt_Target_Feeder_Speed
                                             * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                             */
real_T Rebuilt_Target_Transfer_Speed = 4000.0;
                                      /* Variable: Rebuilt_Target_Transfer_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Transfer_Error_Integral_Enable = 300.0;
                             /* Variable: Rebuilt_Transfer_Error_Integral_Enable
                              * Referenced by: '<S138>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S188>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S188>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S188>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S413>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S411>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S413>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S414>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S414>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S248>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S248>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S195>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S208>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S248>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S355>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S355>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S355>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S355>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S355>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S355>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S372>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S372>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S372>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S372>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S371>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S372>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S372>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S372>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S372>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S372>/Constant1'
                                   *   '<S372>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S372>/Constant'
                                   *   '<S372>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S262>/Constant3'
                                        *   '<S283>/Constant3'
                                        *   '<S304>/Constant3'
                                        *   '<S325>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S262>/Constant2'
                                *   '<S283>/Constant2'
                                *   '<S304>/Constant2'
                                *   '<S325>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S262>/Saturation'
                                           *   '<S283>/Saturation'
                                           *   '<S304>/Saturation'
                                           *   '<S325>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S262>/Saturation'
                                          *   '<S283>/Saturation'
                                          *   '<S304>/Saturation'
                                          *   '<S325>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S262>/Gain2'
                                         *   '<S283>/Gain2'
                                         *   '<S304>/Gain2'
                                         *   '<S325>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S262>/Saturation1'
                                             *   '<S283>/Saturation1'
                                             *   '<S304>/Saturation1'
                                             *   '<S325>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S262>/Saturation1'
                                            *   '<S283>/Saturation1'
                                            *   '<S304>/Saturation1'
                                            *   '<S325>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S262>/Gain1'
                                        *   '<S283>/Gain1'
                                        *   '<S304>/Gain1'
                                        *   '<S325>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S354>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S354>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S354>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S354>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S354>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S354>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S413>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S413>/Constant1'
                                        */
real_T TEST_Desired_Hood_Enable_OV = 0.0;/* Variable: TEST_Desired_Hood_Enable_OV
                                          * Referenced by: '<S10>/Constant7'
                                          */
real_T TEST_Desired_Hood_Pos_OV = 0.05;/* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S10>/Constant6'
                                        */
real_T TEST_Feeder_Motor_DC_OV = 0.0;  /* Variable: TEST_Feeder_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant2'
                                        */
real_T TEST_Intake_Arm_Motor_DC_OV = 0.0;/* Variable: TEST_Intake_Arm_Motor_DC_OV
                                          * Referenced by: '<S10>/Constant9'
                                          */
real_T TEST_Intake_Roller_Motor_DC_OV = 0.0;
                                     /* Variable: TEST_Intake_Roller_Motor_DC_OV
                                      * Referenced by: '<S10>/Constant10'
                                      */
real_T TEST_Output_Override_Flag = 0.0;/* Variable: TEST_Output_Override_Flag
                                        * Referenced by: '<S10>/Constant'
                                        */
real_T TEST_Shooter_Motor_DC_Center_OV = 0.0;
                                    /* Variable: TEST_Shooter_Motor_DC_Center_OV
                                     * Referenced by: '<S10>/Constant4'
                                     */
real_T TEST_Shooter_Motor_DC_Left_OV = 0.0;
                                      /* Variable: TEST_Shooter_Motor_DC_Left_OV
                                       * Referenced by: '<S10>/Constant3'
                                       */
real_T TEST_Shooter_Motor_DC_Right_OV = 0.0;
                                     /* Variable: TEST_Shooter_Motor_DC_Right_OV
                                      * Referenced by: '<S10>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Override_Flag = 0.0;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S412>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S412>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S412>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S342>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S342>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S342>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S342>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S342>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S342>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S414>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S413>/Dead Zone'
                                        *   '<S414>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S413>/Dead Zone'
                                        *   '<S414>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S411>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S411>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S411>/Constant4'
                                        */
real_T Vision_Object_X_Offset = 0.0;   /* Variable: Vision_Object_X_Offset
                                        * Referenced by: '<S17>/Constant4'
                                        */
real_T Vision_Object_Y_Offset = 0.0;   /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S17>/Constant8'
                                        */
real_T Vision_Tag_Angle_Offset = 0.0;  /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S17>/Constant5'
                                        */
real_T Vision_Tag_Target_Angle = 0.0;  /* Variable: Vision_Tag_Target_Angle
                                        * Referenced by: '<S411>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S411>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S411>/Constant5'
                                        */
real_T Vision_Tag_X_Offset = 0.0;      /* Variable: Vision_Tag_X_Offset
                                        * Referenced by: '<S17>/Constant3'
                                        */
real_T Vision_Tag_Y_Offset = 0.0;      /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S17>/Constant7'
                                        */
uint8_T TEST_Pipeline = 0U;            /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S16>/Constant22'
                                        *   '<S411>/Constant11'
                                        */

/* Block signals (default storage) */
B_Robot_Control_T Robot_Control_B;

/* Block states (default storage) */
DW_Robot_Control_T Robot_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Robot_Control_T Robot_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Robot_Control_T Robot_Control_Y;

/* Real-time model */
static RT_MODEL_Robot_Control_T Robot_Control_M_;
RT_MODEL_Robot_Control_T *const Robot_Control_M = &Robot_Control_M_;

/*
 * System initialize for action system:
 *    '<S133>/If Action Subsystem1'
 *    '<S133>/If Action Subsystem3'
 */
void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S166>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S133>/If Action Subsystem1'
 *    '<S133>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  boolean_T rtb_Compare_pp;

  /* RelationalOperator: '<S171>/Compare' incorporates:
   *  Constant: '<S166>/Constant1'
   *  Constant: '<S171>/Constant'
   *  Sum: '<S166>/Sum'
   *  UnitDelay: '<S166>/Unit Delay'
   */
  rtb_Compare_pp = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S166>/Logical Operator' incorporates:
   *  Logic: '<S166>/NOT'
   */
  *rty_IsBlueActive = ((!rtu_IsBlueInactiveFirst) || rtb_Compare_pp);

  /* Logic: '<S166>/Logical Operator1' */
  *rty_IsRedActive = (rtu_IsBlueInactiveFirst || rtb_Compare_pp);

  /* SignalConversion: '<S166>/Signal Copy' incorporates:
   *  Constant: '<S166>/Constant1'
   *  Sum: '<S166>/Sum'
   *  UnitDelay: '<S166>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S166>/Unit Delay' incorporates:
   *  Constant: '<S166>/Constant1'
   *  Sum: '<S166>/Sum'
   */
  localDW->UnitDelay_DSTATE -= 0.02;
}

/*
 * System initialize for action system:
 *    '<S133>/If Action Subsystem2'
 *    '<S133>/If Action Subsystem4'
 */
void Robot_C_IfActionSubsystem2_Init(DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S133>/If Action Subsystem2'
 *    '<S133>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  boolean_T rtb_Compare_cb;

  /* RelationalOperator: '<S172>/Compare' incorporates:
   *  Constant: '<S167>/Constant1'
   *  Constant: '<S172>/Constant'
   *  Sum: '<S167>/Sum'
   *  UnitDelay: '<S167>/Unit Delay'
   */
  rtb_Compare_cb = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S167>/Logical Operator' */
  *rty_IsBlueActive = (rtu_IsBlueInactiveFirst || rtb_Compare_cb);

  /* Logic: '<S167>/Logical Operator1' incorporates:
   *  Logic: '<S167>/NOT1'
   */
  *rty_IsRedActive = ((!rtu_IsBlueInactiveFirst) || rtb_Compare_cb);

  /* SignalConversion: '<S167>/Signal Copy' incorporates:
   *  Constant: '<S167>/Constant1'
   *  Sum: '<S167>/Sum'
   *  UnitDelay: '<S167>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S167>/Unit Delay' incorporates:
   *  Constant: '<S167>/Constant1'
   *  Sum: '<S167>/Sum'
   */
  localDW->UnitDelay_DSTATE -= 0.02;
}

/* Model step function */
void Robot_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_LookupTableDynamic1;
  real_T rtb_LookupTableDynamic;
  real_T rtb_LookupTableDynamic1_g;
  real_T rtb_LookupTableDynamic_p;
  real_T rtb_LookupTableDynamic1_i;
  real_T rtb_LookupTableDynamic_j;
  real_T rtb_TOF;
  real_T rtb_MatrixConcatenate_o[450];
  real_T rtb_Position_and_Curvature[450];
  real_T distance_from_robot[150];
  real_T rtb_Assignment_d[150];
  real_T rtb_MatrixConcatenate_h[100];
  real_T rtb_Spline_Ref_Poses_h[60];
  real_T rtb_Assignment[24];
  real_T rtb_MatrixConcatenate_p[24];
  real_T rtb_Ref_Poses[20];
  real_T rtb_Selector5[20];
  real_T rtb_TOF_g[8];
  real_T rtb_TmpSignalConversionAtLoo_ix[8];
  real_T rtb_TmpSignalConversionAtLoo_lg[8];
  real_T rtb_TmpSignalConversionAtLoo_o3[8];
  real_T rtb_TmpSignalConversionAtLoo_ov[8];
  real_T rtb_TmpSignalConversionAtLook_o[8];
  real_T rtb_Add2[2];
  real_T rtb_Minus_n[2];
  real_T rtb_Reshapey[2];
  real_T rtb_Add_a5;
  real_T rtb_Add_e3;
  real_T rtb_Add_f1;
  real_T rtb_Add_fd;
  real_T rtb_Add_i;
  real_T rtb_DeadZone;
  real_T rtb_Error_c5;
  real_T rtb_Error_n;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Init;
  real_T rtb_Integral_bj;
  real_T rtb_Integral_d;
  real_T rtb_Integral_ga;
  real_T rtb_LookupTableDynamic_b;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_MatrixConcatenate_idx_0;
  real_T rtb_Merge1;
  real_T rtb_Minus_k_idx_0;
  real_T rtb_Minus_k_idx_1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_aa;
  real_T rtb_Product_bg;
  real_T rtb_Product_lf;
  real_T rtb_Product_m5;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_la;
  real_T rtb_Subtract_c3;
  real_T rtb_Sum1;
  real_T rtb_Sum1_dj;
  real_T rtb_Sum1_fh;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1;
  real_T rtb_Switch1_ae;
  real_T rtb_Switch1_hb;
  real_T rtb_Switch1_n;
  real_T rtb_Switch2;
  real_T rtb_Switch2_be;
  real_T rtb_Switch2_p2;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s220_iter;
  uint16_T s245_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T Iteration_Number;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4;
  boolean_T rtb_Button_Shoot_Enable;
  boolean_T rtb_Button_Spinup_Enable;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation_g;
  boolean_T rtb_LogicalOperator1_n;
  boolean_T rtb_Shooter_Active_prev;
  boolean_T rtb_Swerve_Motors_Disabled;

  /* RelationalOperator: '<S33>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *  UnitDelay: '<S33>/Delay Input1'
   *
   * Block description for '<S33>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Joystick_Left_B11 >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S34>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *  UnitDelay: '<S34>/Delay Input1'
   *
   * Block description for '<S34>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets =
    (Robot_Control_U.Joystick_Left_B12 > Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S35>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *  UnitDelay: '<S35>/Delay Input1'
   *
   * Block description for '<S35>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Joystick_Left_B13 >
    Robot_Control_DW.DelayInput1_DSTATE_n);

  /* SignalConversion: '<S5>/Signal Copy1' incorporates:
   *  Inport: '<Root>/Joystick_Left_X'
   */
  Robot_Control_B.Drive_Joystick_X_preRL = Robot_Control_U.Joystick_Left_X;

  /* Switch: '<S42>/Init' incorporates:
   *  UnitDelay: '<S42>/FixPt Unit Delay1'
   *  UnitDelay: '<S42>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Subtract_c3 = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Subtract_c3 = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S42>/Init' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant2'
   *  Constant: '<S39>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Sin4 = Rate_Limit_Max_X;
  } else {
    rtb_Sin4 = 1000.0;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Sum: '<S40>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Subtract_c3;

  /* Switch: '<S41>/Switch2' incorporates:
   *  RelationalOperator: '<S41>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Sin4)) {
    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant'
     *  Constant: '<S39>/Constant1'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_hb = Rate_Limit_Min_X;
    } else {
      rtb_Switch1_hb = -1000.0;
    }

    /* End of Switch: '<S39>/Switch1' */

    /* Switch: '<S41>/Switch' incorporates:
     *  RelationalOperator: '<S41>/UpperRelop'
     */
    if (rtb_Sum1 < rtb_Switch1_hb) {
      rtb_Sin4 = rtb_Switch1_hb;
    } else {
      rtb_Sin4 = rtb_Sum1;
    }

    /* End of Switch: '<S41>/Switch' */
  }

  /* End of Switch: '<S41>/Switch2' */

  /* Sum: '<S40>/Sum' */
  rtb_Sum1 = rtb_Sin4 + rtb_Subtract_c3;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S46>/Init' incorporates:
   *  UnitDelay: '<S46>/FixPt Unit Delay1'
   *  UnitDelay: '<S46>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_n != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_o;
  }

  /* End of Switch: '<S46>/Init' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_c3 = Rate_Limit_Max_Y;
  } else {
    rtb_Subtract_c3 = 1000.0;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Sum: '<S44>/Sum1' */
  rtb_Switch1_hb = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Sin4;

  /* Switch: '<S45>/Switch2' incorporates:
   *  RelationalOperator: '<S45>/LowerRelop1'
   */
  if (!(rtb_Switch1_hb > rtb_Subtract_c3)) {
    /* Switch: '<S43>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant1'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_ae = Rate_Limit_Min_Y;
    } else {
      rtb_Switch1_ae = -1000.0;
    }

    /* End of Switch: '<S43>/Switch1' */

    /* Switch: '<S45>/Switch' incorporates:
     *  RelationalOperator: '<S45>/UpperRelop'
     */
    if (rtb_Switch1_hb < rtb_Switch1_ae) {
      rtb_Subtract_c3 = rtb_Switch1_ae;
    } else {
      rtb_Subtract_c3 = rtb_Switch1_hb;
    }

    /* End of Switch: '<S45>/Switch' */
  }

  /* End of Switch: '<S45>/Switch2' */

  /* Sum: '<S44>/Sum' */
  rtb_Switch1_hb = rtb_Subtract_c3 + rtb_Sin4;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S50>/Init' incorporates:
   *  UnitDelay: '<S50>/FixPt Unit Delay1'
   *  UnitDelay: '<S50>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_k != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_i;
  }

  /* End of Switch: '<S50>/Init' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/Constant2'
   *  Constant: '<S47>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_c3 = Rate_Limit_Max_Z;
  } else {
    rtb_Subtract_c3 = 1000.0;
  }

  /* End of Switch: '<S47>/Switch' */

  /* Sum: '<S48>/Sum1' */
  rtb_Switch1_ae = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Sin4;

  /* Switch: '<S49>/Switch2' incorporates:
   *  RelationalOperator: '<S49>/LowerRelop1'
   */
  if (!(rtb_Switch1_ae > rtb_Subtract_c3)) {
    /* Switch: '<S47>/Switch1' incorporates:
     *  Constant: '<S47>/Constant'
     *  Constant: '<S47>/Constant1'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Subtract_c3 = Rate_Limit_Min_Z;
    } else {
      rtb_Subtract_c3 = -1000.0;
    }

    /* End of Switch: '<S47>/Switch1' */

    /* Switch: '<S49>/Switch' incorporates:
     *  RelationalOperator: '<S49>/UpperRelop'
     */
    if (!(rtb_Switch1_ae < rtb_Subtract_c3)) {
      rtb_Subtract_c3 = rtb_Switch1_ae;
    }

    /* End of Switch: '<S49>/Switch' */
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Sum: '<S48>/Sum' */
  rtb_Switch1_ae = rtb_Subtract_c3 + rtb_Sin4;

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   *  Inport: '<Root>/Joystick_Left_POV'
   */
  Robot_Control_B.Drive_Joystick_Z_Mode = (Robot_Control_U.Joystick_Left_POV !=
    -1.0);

  /* SignalConversion: '<S5>/Signal Copy5' incorporates:
   *  Inport: '<Root>/Joystick_Right_Y'
   */
  Robot_Control_B.Steer_Joystick_Y = Robot_Control_U.Joystick_Right_Y;

  /* SignalConversion: '<S5>/Signal Copy6' incorporates:
   *  Inport: '<Root>/Joystick_Right_Z'
   */
  Robot_Control_B.Steer_Joystick_Z = Robot_Control_U.Joystick_Right_Z;

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Constant: '<S32>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Toward_Driver = (Robot_Control_U.Joystick_Right_POV ==
    180.0);

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Right_Driver = (Robot_Control_U.Joystick_Right_POV ==
    90.0);

  /* RelationalOperator: '<S31>/Compare' incorporates:
   *  Constant: '<S31>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Left_Driver = (Robot_Control_U.Joystick_Right_POV ==
    270.0);

  /* RelationalOperator: '<S27>/Compare' incorporates:
   *  Constant: '<S27>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Away_Driver = (Robot_Control_U.Joystick_Right_POV == 0.0);

  /* Sum: '<S17>/Add' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Gain: '<S17>/Convert meters to inches1'
   *  Inport: '<Root>/Vision_c1_AprilTag_X_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_X_m) + Vision_Tag_X_Offset;

  /* Sum: '<S17>/Add1' incorporates:
   *  Constant: '<S17>/Constant7'
   *  Gain: '<S17>/Convert meters to inches'
   *  Inport: '<Root>/Vision_c1_AprilTag_Y_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_Y_m) + Vision_Tag_Y_Offset;

  /* Sum: '<S17>/Add2' incorporates:
   *  Constant: '<S17>/Constant5'
   *  Inport: '<Root>/Vision_c1_AprilTag_Yaw_deg'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_AprilTag_Yaw_deg + Vision_Tag_Angle_Offset;

  /* If: '<S440>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S440>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S443>/Action Port'
     */
    /* Product: '<S443>/Product' incorporates:
     *  Constant: '<S443>/Constant1'
     *  Constant: '<S443>/Constant2'
     *  Math: '<S443>/Math Function'
     */
    rtb_Sin4 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495) *
      111.0;

    /* End of Outputs for SubSystem: '<S440>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S440>/Subsystem' incorporates:
     *  ActionPort: '<S444>/Action Port'
     */
    /* SignalConversion generated from: '<S444>/Out1' incorporates:
     *  Constant: '<S444>/Constant'
     */
    rtb_Sin4 = 0.0;

    /* End of Outputs for SubSystem: '<S440>/Subsystem' */
  }

  /* End of If: '<S440>/If' */

  /* Gain: '<S441>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Subtract_c3 = 0.017453292519943295 *
    Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S442>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Sin4 * cos(rtb_Subtract_c3))
    + Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S442>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Sin4 * sin(rtb_Subtract_c3))
    + Vision_Object_Y_Offset;

  /* Sum: '<S17>/Add5' incorporates:
   *  Constant: '<S17>/Constant6'
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_Object_Hor_deg + Vision_Object_Angle_Offset;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Robot_Control_DW.SwitchCase_ActiveSubsystem;
  rtb_Add_a5 = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_a5)) || (rtIsInf(rtb_Add_a5))) {
    rtb_Add_a5 = 0.0;
  } else {
    rtb_Add_a5 = fmod(rtb_Add_a5, 4.294967296E+9);
  }

  switch ((rtb_Add_a5 < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_a5)))) :
          ((int32_T)((uint32_T)rtb_Add_a5))) {
   case 0:
    rtAction = 0;
    break;

   case 1:
    rtAction = 1;
    break;

   case 2:
    rtAction = 2;
    break;

   default:
    rtAction = 3;
    break;
  }

  Robot_Control_DW.SwitchCase_ActiveSubsystem = rtAction;
  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* SignalConversion generated from: '<S4>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  SignalConversion generated from: '<S4>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* Merge: '<S9>/Merge2' incorporates:
     *  Constant: '<S4>/Constant2'
     *  SignalConversion generated from: '<S4>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S9>/Merge3' incorporates:
     *  Constant: '<S4>/Constant3'
     *  SignalConversion generated from: '<S4>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S9>/Merge4' incorporates:
     *  Constant: '<S4>/Constant4'
     *  SignalConversion generated from: '<S4>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* SignalConversion generated from: '<S4>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S4>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* SignalConversion generated from: '<S4>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S4>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S9>/Merge7' incorporates:
     *  Constant: '<S4>/Constant7'
     *  SignalConversion generated from: '<S4>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S9>/Merge9' incorporates:
     *  Constant: '<S4>/Constant9'
     *  SignalConversion generated from: '<S4>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S9>/Merge10' incorporates:
     *  Constant: '<S4>/Constant10'
     *  SignalConversion generated from: '<S4>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  Constant: '<S4>/Constant18'
     *  SignalConversion generated from: '<S4>/Enable_Wheels'
     */
    Robot_Control_Y.Enable_Wheels = false;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S4>/Constant13'
     *  SignalConversion generated from: '<S4>/Reset_Wheel_Offsets'
     */
    Robot_Control_Y.Reset_Wheel_Offsets = false;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  Constant: '<S4>/Constant14'
     *  SignalConversion generated from: '<S4>/Disable_Wheels'
     */
    Robot_Control_Y.Disable_Wheels = false;

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S4>/Constant12'
     *  SignalConversion generated from: '<S4>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = true;

    /* Merge: '<S9>/Merge23' incorporates:
     *  Constant: '<S4>/Constant23'
     *  SignalConversion generated from: '<S4>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S4>/Constant25'
     *  SignalConversion generated from: '<S4>/Desired_Pipeline'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = 0U;

    /* SignalConversion generated from: '<S4>/Button_Spinup_Enable' incorporates:
     *  Constant: '<S4>/Constant11'
     */
    rtb_Button_Spinup_Enable = false;

    /* SignalConversion generated from: '<S4>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S4>/Constant15'
     */
    rtb_Button_Shoot_Enable = false;

    /* SignalConversion generated from: '<S4>/Intake_Arm_Move_In' incorporates:
     *  Constant: '<S4>/Constant16'
     */
    rtb_Intake_Arm_Move_In = false;

    /* SignalConversion generated from: '<S4>/Intake_Arm_Move_Out' incorporates:
     *  Constant: '<S4>/Constant17'
     */
    rtb_Intake_Arm_Move_Out = false;

    /* SignalConversion generated from: '<S4>/Intake_Arm_Move_Cycle' incorporates:
     *  Constant: '<S4>/Constant19'
     */
    rtb_Shooter_Active_prev = false;

    /* SignalConversion generated from: '<S4>/Intake_Roller_On' incorporates:
     *  Constant: '<S4>/Constant20'
     */
    rtb_LogicalOperator1_n = false;

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S4>/Constant21'
     *  SignalConversion generated from: '<S4>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Autonomous' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S19>/Unit Delay'
       *  UnitDelay: '<S19>/Unit Delay1'
       *  UnitDelay: '<S20>/Unit Delay'
       *  UnitDelay: '<S20>/Unit Delay1'
       *  UnitDelay: '<S25>/Delay Input1'
       *
       * Block description for '<S25>/Delay Input1':
       *
       *  Store in Global RAM
       */
      memset(&Robot_Control_DW.UnitDelay1_DSTATE_iz[0], 0, 60U * (sizeof(real_T)));
      Robot_Control_DW.UnitDelay1_DSTATE_k = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_kb = false;
      Robot_Control_DW.UnitDelay_DSTATE_b = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_e3 = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Autonomous' */

      /* SystemReset for IfAction SubSystem: '<S1>/Autonomous' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S20>/Chart'
       */
      Robot_Control_DW.is_active_c6_Robot_Control = 0U;
      Robot_Control_DW.is_c6_Robot_Control = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_B.Auto_Desired_Static_Action = 0.0;
      Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
      Robot_Control_B.Auto_Path_Counter = 0.0;
      Robot_Control_B.Auto_Spline_Enable = false;

      /* End of SystemReset for SubSystem: '<S1>/Autonomous' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MultiPortSwitch: '<S21>/Multiport Switch1' incorporates:
     *  Constant: '<S21>/Constant10'
     *  Constant: '<S21>/Constant11'
     *  Constant: '<S21>/Constant12'
     *  Constant: '<S21>/Constant17'
     *  Constant: '<S21>/Constant9'
     */
    switch ((int32_T)Auto_Path_Chooser) {
     case 1:
      rtb_MultiportSwitch1[0] = 1;
      rtb_MultiportSwitch1[1] = 4;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 2:
      rtb_MultiportSwitch1[0] = 2;
      rtb_MultiportSwitch1[1] = 3;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 3:
      rtb_MultiportSwitch1[0] = 5;
      rtb_MultiportSwitch1[1] = 6;
      rtb_MultiportSwitch1[2] = 0;
      break;

     default:
      rtb_MultiportSwitch1[0] = 7;
      rtb_MultiportSwitch1[1] = 8;
      rtb_MultiportSwitch1[2] = 0;
      break;
    }

    /* End of MultiPortSwitch: '<S21>/Multiport Switch1' */

    /* Saturate: '<S20>/Saturation' incorporates:
     *  UnitDelay: '<S7>/Unit Delay2'
     */
    if (Robot_Control_DW.UnitDelay2_DSTATE > 10.0) {
      rtb_Subtract_c3 = 10.0;
    } else if (Robot_Control_DW.UnitDelay2_DSTATE < 1.0) {
      rtb_Subtract_c3 = 1.0;
    } else {
      rtb_Subtract_c3 = Robot_Control_DW.UnitDelay2_DSTATE;
    }

    /* End of Saturate: '<S20>/Saturation' */

    /* RelationalOperator: '<S23>/Compare' incorporates:
     *  Constant: '<S23>/Constant'
     *  UnitDelay: '<S19>/Unit Delay1'
     */
    rtb_Swerve_Motors_Disabled = (Robot_Control_DW.UnitDelay1_DSTATE_k == 2.0);

    /* Switch: '<S19>/Switch1' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S19>/Constant2'
     *  RelationalOperator: '<S25>/FixPt Relational Operator'
     *  Sum: '<S19>/Sum'
     *  UnitDelay: '<S19>/Unit Delay'
     *  UnitDelay: '<S25>/Delay Input1'
     *
     * Block description for '<S25>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Swerve_Motors_Disabled) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_kb)) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
    }

    /* End of Switch: '<S19>/Switch1' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     */
    if (rtb_Swerve_Motors_Disabled) {
      rtb_Shooter_Active_prev = (rtb_Switch1_n >= Auto_Shoot_Time);
    } else {
      rtb_Shooter_Active_prev = false;
    }

    /* End of Switch: '<S19>/Switch' */

    /* Chart: '<S20>/Chart' incorporates:
     *  Selector: '<S20>/Selector1'
     *  Selector: '<S20>/Selector2'
     *  UnitDelay: '<S20>/Unit Delay'
     *  UnitDelay: '<S20>/Unit Delay1'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    if (Robot_Control_DW.is_active_c6_Robot_Control == 0U) {
      Robot_Control_DW.is_active_c6_Robot_Control = 1U;
      Robot_Control_B.Auto_Path_Counter = 1.0;
      Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Start_Action;
      Robot_Control_B.Auto_Spline_Enable = true;
      Robot_Control_B.Auto_Desired_Static_Action =
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) + 39];
      Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
    } else {
      switch (Robot_Control_DW.is_c6_Robot_Control) {
       case Robot_Control_IN_End_Action:
        Robot_Control_B.Auto_Spline_Enable = false;
        if (((Robot_Control_B.Auto_Desired_Static_Action == 0.0) ||
             rtb_Shooter_Active_prev) && (Robot_Control_B.Auto_Path_Counter <
             Robot_Control_ConstB.Width)) {
          rtb_Shooter_Active_prev = (rtb_MultiportSwitch1[((int32_T)
            (Robot_Control_B.Auto_Path_Counter + 1.0)) - 1] != 0);
        } else {
          rtb_Shooter_Active_prev = false;
        }

        if (rtb_Shooter_Active_prev) {
          Robot_Control_B.Auto_Path_Counter++;
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Start_Action;
          Robot_Control_B.Auto_Spline_Enable = true;
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        }
        break;

       case Robot_Control_IN_Follow_Path:
        if (Robot_Control_DW.UnitDelay_DSTATE_ll) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_End_Action;
          Robot_Control_B.Auto_Spline_Enable = false;
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        } else if (rtb_Subtract_c3 > Robot_Control_DW.UnitDelay_DSTATE_e3) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            49];
        }
        break;

       default:
        /* case IN_Start_Action: */
        Robot_Control_B.Auto_Spline_Enable = true;
        if ((Robot_Control_B.Auto_Desired_Static_Action == 0.0) ||
            rtb_Shooter_Active_prev) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            49];
        }
        break;
      }
    }

    /* End of Chart: '<S20>/Chart' */

    /* Lookup_n-D: '<S20>/1-D Lookup Table1' incorporates:
     *  MultiPortSwitch: '<S21>/Multiport Switch1'
     */
    Robot_Control_B.Auto_Path_ID = rtb_MultiportSwitch1[plook_u32d_evencka
      (Robot_Control_B.Auto_Path_Counter, 1.0, 1.0, 2U)];

    /* Switch: '<S20>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     */
    rtb_Is_Absolute_Translation_g = (Robot_Control_U.IsBlueAlliance != 0.0);

    /* Selector: '<S20>/Selector' */
    i = ((int32_T)Robot_Control_B.Auto_Path_ID) - 1;
    for (rtb_Num_Segments = 0; rtb_Num_Segments < 60; rtb_Num_Segments++) {
      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S20>/Constant1'
       *  Selector: '<S20>/Selector'
       */
      if (rtb_Is_Absolute_Translation_g) {
        rtb_Spline_Ref_Poses_h[rtb_Num_Segments] = rtCP_Constant_Value_c[(i * 60)
          + rtb_Num_Segments];
      } else {
        rtb_Spline_Ref_Poses_h[rtb_Num_Segments] = rtCP_Constant1_Value_bc[(i *
          60) + rtb_Num_Segments];
      }
    }

    /* End of Selector: '<S20>/Selector' */

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Selector: '<S18>/Select heading angle from first row'
     *  Selector: '<S20>/Selector'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = rtb_Spline_Ref_Poses_h[30];

    /* Merge: '<S9>/Merge9' incorporates:
     *  Lookup_n-D: '<S20>/1-D Lookup Table'
     *  Lookup_n-D: '<S20>/1-D Lookup Table1'
     */
    Robot_Control_B.Spline_Num_Poses =
      rtCP_uDLookupTable_tableData[plook_u32d_evencka
      (Robot_Control_B.Auto_Path_ID, 1.0, 1.0, 12U)];

    /* Merge: '<S9>/Merge7' incorporates:
     *  SignalConversion: '<S18>/Signal Copy'
     */
    Robot_Control_B.Spline_Enable = Robot_Control_B.Auto_Spline_Enable;

    /* Switch: '<S22>/Switch' */
    if (Robot_Control_B.Auto_Desired_Static_Action != 0.0) {
      rtb_Add_a5 = Robot_Control_B.Auto_Desired_Static_Action;
    } else {
      rtb_Add_a5 = Robot_Control_B.Auto_Desired_Dynamic_Action;
    }

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     *  Switch: '<S22>/Switch'
     */
    switch ((int32_T)rtb_Add_a5) {
     case 0:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant'
       *  Constant: '<S22>/Constant4'
       */
      rtb_Button_Shoot_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant9'
       */
      rtb_Intake_Arm_Move_In = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant19'
       */
      rtb_Intake_Arm_Move_Out = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
       *  Constant: '<S22>/Constant24'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant29'
       */
      rtb_LogicalOperator1_n = false;
      break;

     case 1:
      rtb_Button_Spinup_Enable = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant1'
       *  Constant: '<S22>/Constant5'
       */
      rtb_Button_Shoot_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant10'
       */
      rtb_Intake_Arm_Move_In = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant14'
       */
      rtb_Intake_Arm_Move_Out = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
       *  Constant: '<S22>/Constant20'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant25'
       */
      rtb_LogicalOperator1_n = false;
      break;

     case 2:
      rtb_Button_Spinup_Enable = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant2'
       *  Constant: '<S22>/Constant7'
       */
      rtb_Button_Shoot_Enable = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant12'
       */
      rtb_Intake_Arm_Move_In = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant16'
       */
      rtb_Intake_Arm_Move_Out = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
       *  Constant: '<S22>/Constant22'
       */
      rtb_Shooter_Active_prev = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant27'
       */
      rtb_LogicalOperator1_n = false;
      break;

     case 3:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant18'
       *  Constant: '<S22>/Constant6'
       */
      rtb_Button_Shoot_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant11'
       */
      rtb_Intake_Arm_Move_In = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant15'
       */
      rtb_Intake_Arm_Move_Out = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
       *  Constant: '<S22>/Constant21'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant26'
       */
      rtb_LogicalOperator1_n = true;
      break;

     default:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant3'
       *  Constant: '<S22>/Constant8'
       */
      rtb_Button_Shoot_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant13'
       */
      rtb_Intake_Arm_Move_In = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant17'
       */
      rtb_Intake_Arm_Move_Out = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
       *  Constant: '<S22>/Constant23'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant28'
       */
      rtb_LogicalOperator1_n = false;
      break;
    }

    /* End of MultiPortSwitch: '<S22>/Multiport Switch' */

    /* SignalConversion generated from: '<S2>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S18>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S18>/Constant1'
     *  SignalConversion generated from: '<S2>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S18>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* Merge: '<S9>/Merge2' incorporates:
     *  Constant: '<S18>/Constant2'
     *  SignalConversion generated from: '<S2>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S9>/Merge3' incorporates:
     *  Constant: '<S18>/Constant3'
     *  SignalConversion generated from: '<S2>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S9>/Merge4' incorporates:
     *  Constant: '<S18>/Constant4'
     *  SignalConversion generated from: '<S2>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* Merge: '<S9>/Merge23' incorporates:
     *  Constant: '<S18>/Constant10'
     *  SignalConversion generated from: '<S2>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* Merge: '<S9>/Merge10' incorporates:
     *  Constant: '<S2>/Constant3'
     *  SignalConversion generated from: '<S2>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  Constant: '<S2>/Constant1'
     *  SignalConversion generated from: '<S2>/Enable_Wheels'
     */
    Robot_Control_Y.Enable_Wheels = false;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S2>/Constant13'
     *  SignalConversion generated from: '<S2>/Reset_Wheel_Offsets'
     */
    Robot_Control_Y.Reset_Wheel_Offsets = false;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  Constant: '<S2>/Constant14'
     *  SignalConversion generated from: '<S2>/Disable_Wheels'
     */
    Robot_Control_Y.Disable_Wheels = false;

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S2>/Constant4'
     *  SignalConversion generated from: '<S2>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = false;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S2>/Constant'
     *  SignalConversion generated from: '<S2>/Desired_Pipeline'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = 0U;

    /* Update for UnitDelay: '<S20>/Unit Delay1' incorporates:
     *  Selector: '<S20>/Selector'
     */
    memcpy(&Robot_Control_DW.UnitDelay1_DSTATE_iz[0], &rtb_Spline_Ref_Poses_h[0],
           60U * (sizeof(real_T)));

    /* Update for UnitDelay: '<S19>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_k =
      Robot_Control_B.Auto_Desired_Static_Action;

    /* Update for UnitDelay: '<S25>/Delay Input1'
     *
     * Block description for '<S25>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_kb = rtb_Swerve_Motors_Disabled;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Switch1_n;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Subtract_c3;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S413>/Unit Delay1'
       *  UnitDelay: '<S413>/Unit Delay2'
       *  UnitDelay: '<S413>/Unit Delay3'
       *  UnitDelay: '<S413>/Unit Delay4'
       *  UnitDelay: '<S416>/Delay Input1'
       *  UnitDelay: '<S417>/Delay Input1'
       *  UnitDelay: '<S418>/Delay Input1'
       *  UnitDelay: '<S419>/Delay Input1'
       *  UnitDelay: '<S421>/Delay Input1'
       *  UnitDelay: '<S427>/Unit Delay'
       *  UnitDelay: '<S427>/Unit Delay1'
       *  UnitDelay: '<S431>/FixPt Unit Delay1'
       *  UnitDelay: '<S431>/FixPt Unit Delay2'
       *
       * Block description for '<S416>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S417>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S418>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S419>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S421>/Delay Input1':
       *
       *  Store in Global RAM
       */
      Robot_Control_DW.DelayInput1_DSTATE_j = false;
      Robot_Control_DW.DelayInput1_DSTATE_m = false;
      Robot_Control_DW.DelayInput1_DSTATE_k = false;
      Robot_Control_DW.DelayInput1_DSTATE_g = false;
      Robot_Control_DW.DelayInput1_DSTATE_g2 = false;
      Robot_Control_DW.UnitDelay2_DSTATE_l = false;
      Robot_Control_DW.UnitDelay4_DSTATE = false;
      Robot_Control_DW.UnitDelay3_DSTATE = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_j2 = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_l = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_p = 0.0;
      Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;
      Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Teleop' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* SignalConversion generated from: '<S15>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

    /* Switch: '<S411>/Switch4' incorporates:
     *  Constant: '<S436>/Constant'
     *  Constant: '<S439>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S436>/Compare'
     *  RelationalOperator: '<S439>/Compare'
     *  Switch: '<S411>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S411>/Switch4' incorporates:
       *  Constant: '<S411>/Constant8'
       *  Sum: '<S411>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S411>/Switch5' incorporates:
       *  Constant: '<S411>/Constant7'
       *  Gain: '<S411>/Gain'
       *  Sum: '<S411>/Subtract5'
       *  Switch: '<S411>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S411>/Switch4' incorporates:
       *  Constant: '<S411>/Constant6'
       *  Switch: '<S411>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S411>/Switch4' */

    /* Logic: '<S411>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S411>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S413>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_a5 = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_a5 = 0.0;
    } else {
      rtb_Add_a5 = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S413>/Add' incorporates:
     *  Constant: '<S413>/Constant'
     *  Constant: '<S413>/Constant1'
     *  DeadZone: '<S413>/Dead Zone'
     *  Lookup_n-D: '<S413>/Modulation_Str_Y_Rel'
     *  Product: '<S413>/Product'
     *  Product: '<S413>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Subtract_c3 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                       Steering_Relative_Gain) + (rtb_Add_a5 *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S415>/Compare' incorporates:
     *  Constant: '<S415>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Subtract_c3 == 0.0);

    /* Logic: '<S413>/AND2' incorporates:
     *  RelationalOperator: '<S416>/FixPt Relational Operator'
     *  RelationalOperator: '<S417>/FixPt Relational Operator'
     *  RelationalOperator: '<S418>/FixPt Relational Operator'
     *  RelationalOperator: '<S419>/FixPt Relational Operator'
     *  UnitDelay: '<S416>/Delay Input1'
     *  UnitDelay: '<S417>/Delay Input1'
     *  UnitDelay: '<S418>/Delay Input1'
     *  UnitDelay: '<S419>/Delay Input1'
     *
     * Block description for '<S416>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S417>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S418>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S419>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_LogicalOperator1_n = ((((((int32_T)Robot_Control_B.Face_Away_Driver) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)
      Robot_Control_B.Face_Left_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      Robot_Control_B.Face_Toward_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g))) || (((int32_T)
      Robot_Control_B.Face_Right_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S413>/AND1' incorporates:
     *  Logic: '<S413>/AND3'
     *  UnitDelay: '<S413>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Swerve_Motors_Disabled && (rtb_LogicalOperator1_n ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S413>/AND4' incorporates:
     *  Logic: '<S413>/AND8'
     *  UnitDelay: '<S413>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Swerve_Motors_Disabled && (!rtb_LogicalOperator1_n)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S413>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S413>/Switch8' incorporates:
     *  Constant: '<S422>/Constant'
     *  Logic: '<S413>/AND9'
     *  RelationalOperator: '<S421>/FixPt Relational Operator'
     *  RelationalOperator: '<S422>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S421>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S421>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Swerve_Motors_Disabled) > ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_j))) ||
         (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S413>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S413>/Switch8' incorporates:
       *  UnitDelay: '<S413>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S413>/Switch8' */

    /* Switch: '<S413>/Switch4' incorporates:
     *  Constant: '<S413>/Constant5'
     *  Switch: '<S413>/Switch1'
     *  Switch: '<S413>/Switch5'
     *  Switch: '<S413>/Switch6'
     *  Switch: '<S413>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Switch1_n = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S413>/Switch5' incorporates:
       *  Constant: '<S413>/Constant6'
       */
      rtb_Switch1_n = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S413>/Switch6' incorporates:
       *  Constant: '<S413>/Constant7'
       *  Switch: '<S413>/Switch5'
       */
      rtb_Switch1_n = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S413>/Switch7' incorporates:
       *  Constant: '<S413>/Constant8'
       *  Switch: '<S413>/Switch5'
       *  Switch: '<S413>/Switch6'
       */
      rtb_Switch1_n = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S413>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S413>/Switch5'
       *  Switch: '<S413>/Switch6'
       *  Switch: '<S413>/Switch7'
       */
      rtb_Switch1_n = 0.0;
    } else {
      /* Switch: '<S413>/Switch6' incorporates:
       *  Switch: '<S413>/Switch5'
       *  Switch: '<S413>/Switch7'
       *  UnitDelay: '<S413>/Unit Delay1'
       */
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S413>/Switch4' */

    /* Switch: '<S413>/Switch2' incorporates:
     *  Switch: '<S413>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S413>/Switch2' incorporates:
       *  Constant: '<S413>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S413>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Switch1_n;
    } else {
      /* Switch: '<S413>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S413>/Switch3' incorporates:
       *  Constant: '<S413>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S413>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S413>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S412>/Switch1' incorporates:
     *  Constant: '<S412>/Constant5'
     *  Constant: '<S412>/Constant8'
     *  DataTypeConversion: '<S412>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Swerve_Motors_Disabled;
    }

    /* End of Switch: '<S412>/Switch1' */

    /* Lookup_n-D: '<S414>/Modulation_Drv' incorporates:
     *  Math: '<S414>/Magnitude'
     */
    rtb_Sin4 = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S425>/Compare' incorporates:
     *  Constant: '<S425>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Sin4 == 0.0);

    /* DeadZone: '<S414>/Dead Zone' */
    if (rtb_Switch1_ae > Twist_Deadzone_pos) {
      rtb_DeadZone = rtb_Switch1_ae - Twist_Deadzone_pos;
    } else if (rtb_Switch1_ae >= Twist_Deadzone_neg) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = rtb_Switch1_ae - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S414>/Dead Zone' */

    /* Logic: '<S414>/Logical Operator' incorporates:
     *  Constant: '<S426>/Constant'
     *  RelationalOperator: '<S426>/Compare'
     */
    rtb_LogicalOperator1_n = ((rtb_DeadZone != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S412>/Switch' incorporates:
     *  Constant: '<S412>/Constant5'
     *  Constant: '<S412>/Constant7'
     *  DataTypeConversion: '<S412>/Data Type Conversion'
     *  Logic: '<S414>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_LogicalOperator1_n;
    }

    /* End of Switch: '<S412>/Switch' */

    /* Switch: '<S411>/Switch2' incorporates:
     *  Constant: '<S411>/Constant2'
     *  Constant: '<S435>/Constant'
     *  Constant: '<S438>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S435>/Compare'
     *  RelationalOperator: '<S438>/Compare'
     *  Sum: '<S411>/Subtract'
     *  Switch: '<S411>/Switch'
     *  Switch: '<S411>/Switch1'
     *  Switch: '<S411>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S411>/Switch2' incorporates:
       *  Constant: '<S411>/Constant5'
       *  Sum: '<S411>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S411>/Switch2' incorporates:
       *  Constant: '<S411>/Constant4'
       *  Sum: '<S411>/Subtract2'
       *  Switch: '<S411>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S411>/Switch1' incorporates:
       *  Constant: '<S411>/Constant1'
       *  Sum: '<S411>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S411>/Switch2' incorporates:
       *  Constant: '<S411>/Constant3'
       *  Switch: '<S411>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S411>/Switch1' incorporates:
       *  Constant: '<S411>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S411>/Switch2' */

    /* UnaryMinus: '<S411>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S427>/Switch1' incorporates:
     *  Constant: '<S432>/Constant'
     *  Constant: '<S433>/Constant'
     *  Logic: '<S427>/AND'
     *  RelationalOperator: '<S432>/Compare'
     *  RelationalOperator: '<S433>/Compare'
     *  Switch: '<S427>/Switch2'
     *  UnitDelay: '<S427>/Unit Delay'
     *  UnitDelay: '<S427>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = rtb_Switch1_hb;
      rtb_Switch2 = rtb_Sum1;
    }

    /* End of Switch: '<S427>/Switch1' */

    /* Switch: '<S414>/Switch1' incorporates:
     *  Logic: '<S414>/Logical Operator1'
     *  Switch: '<S414>/Switch4'
     *  Switch: '<S414>/Switch9'
     */
    if (rtb_LogicalOperator1_n) {
      /* Signum: '<S414>/Sign' */
      if (rtIsNaN(rtb_DeadZone)) {
        rtb_Add_a5 = (rtNaN);
      } else if (rtb_DeadZone < 0.0) {
        rtb_Add_a5 = -1.0;
      } else {
        rtb_Add_a5 = (rtb_DeadZone > 0.0);
      }

      /* Switch: '<S414>/Switch5' incorporates:
       *  Constant: '<S414>/Constant3'
       *  Constant: '<S414>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S414>/Gain3'
       *  Signum: '<S414>/Sign'
       *  Sum: '<S414>/Add'
       *  Switch: '<S414>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_a5) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S414>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S414>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S414>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S414>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S414>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S414>/Switch4'
       *  Trigonometry: '<S414>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S414>/Switch1' */

    /* Switch: '<S424>/Switch1' incorporates:
     *  Constant: '<S424>/Constant'
     *  Constant: '<S424>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S424>/Switch1' */

    /* Switch: '<S431>/Init' incorporates:
     *  UnitDelay: '<S431>/FixPt Unit Delay1'
     *  UnitDelay: '<S431>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S431>/Init' */

    /* Sum: '<S429>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S430>/Switch2' incorporates:
     *  Constant: '<S428>/Constant1'
     *  Constant: '<S428>/Constant3'
     *  RelationalOperator: '<S430>/LowerRelop1'
     *  RelationalOperator: '<S430>/UpperRelop'
     *  Switch: '<S430>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S430>/Switch' incorporates:
       *  Constant: '<S428>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S430>/Switch2' */

    /* Sum: '<S429>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S414>/Switch8' incorporates:
     *  Logic: '<S414>/Logical Operator1'
     *  Switch: '<S414>/Switch2'
     */
    if (rtb_LogicalOperator1_n) {
      /* Switch: '<S414>/Switch' incorporates:
       *  Gain: '<S414>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_DeadZone;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S414>/Constant5'
       *  Gain: '<S414>/Gain2'
       *  Math: '<S414>/Magnitude1'
       *  MinMax: '<S414>/Min'
       *  Switch: '<S414>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S424>/Product' incorporates:
       *  Switch: '<S414>/Switch2'
       */
      rtb_Add_a5 = rtb_Sin4 * rtb_Init;

      /* Saturate: '<S424>/Saturation' incorporates:
       *  Switch: '<S414>/Switch2'
       */
      if (rtb_Add_a5 > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_a5 < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_a5;
      }

      /* End of Saturate: '<S424>/Saturation' */
    }

    /* End of Switch: '<S414>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S413>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Subtract_c3;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S411>/Constant11'
     *  Switch: '<S411>/Switch6'
     *  Switch: '<S411>/Switch7'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = TEST_Pipeline;

    /* Merge: '<S9>/Merge23' incorporates:
     *  Constant: '<S15>/Constant'
     *  SignalConversion generated from: '<S15>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* Merge: '<S9>/Merge7' incorporates:
     *  Constant: '<S15>/Constant3'
     *  SignalConversion generated from: '<S15>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S9>/Merge9' incorporates:
     *  Constant: '<S15>/Constant9'
     *  SignalConversion generated from: '<S15>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S9>/Merge10' incorporates:
     *  Constant: '<S15>/Constant1'
     *  SignalConversion generated from: '<S15>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  Constant: '<S15>/Constant6'
     *  SignalConversion generated from: '<S15>/Enable_Wheels'
     */
    Robot_Control_Y.Enable_Wheels = false;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S15>/Constant13'
     *  SignalConversion generated from: '<S15>/Reset_Wheel_Offsets'
     */
    Robot_Control_Y.Reset_Wheel_Offsets = false;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  Constant: '<S15>/Constant14'
     *  SignalConversion generated from: '<S15>/Disable_Wheels'
     */
    Robot_Control_Y.Disable_Wheels = false;

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S15>/Constant2'
     *  SignalConversion generated from: '<S15>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = false;

    /* RelationalOperator: '<S408>/Compare' incorporates:
     *  Constant: '<S408>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S409>/Compare' incorporates:
     *  Constant: '<S409>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S404>/Compare' incorporates:
     *  Constant: '<S404>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S407>/Compare' incorporates:
     *  Constant: '<S407>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S406>/Compare' incorporates:
     *  Constant: '<S406>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Shooter_Active_prev = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S405>/Compare' incorporates:
     *  Constant: '<S405>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     *  SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Update for UnitDelay: '<S421>/Delay Input1'
     *
     * Block description for '<S421>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Swerve_Motors_Disabled;

    /* Update for UnitDelay: '<S420>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S420>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S416>/Delay Input1'
     *
     * Block description for '<S416>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S417>/Delay Input1'
     *
     * Block description for '<S417>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S418>/Delay Input1'
     *
     * Block description for '<S418>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S419>/Delay Input1'
     *
     * Block description for '<S419>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S413>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S413>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S413>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S413>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Switch1_n;

    /* Update for UnitDelay: '<S427>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1;

    /* Update for UnitDelay: '<S427>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S431>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S431>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S431>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Init;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* InitializeConditions for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
     *  UnitDelay: '<S16>/Unit Delay'
     */
    Robot_Control_DW.UnitDelay_DSTATE_ir = ((rtAction == rtPrevAction) &&
      (Robot_Control_DW.UnitDelay_DSTATE_ir));

    /* End of InitializeConditions for SubSystem: '<S1>/Test' */

    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* SignalConversion generated from: '<S16>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S16>/Constant1'
     *  SignalConversion generated from: '<S16>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* Merge: '<S9>/Merge2' incorporates:
     *  Constant: '<S16>/Constant2'
     *  SignalConversion generated from: '<S16>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S9>/Merge3' incorporates:
     *  Constant: '<S16>/Constant3'
     *  SignalConversion generated from: '<S16>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S9>/Merge4' incorporates:
     *  Constant: '<S16>/Constant4'
     *  SignalConversion generated from: '<S16>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* SignalConversion generated from: '<S16>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S16>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* SignalConversion generated from: '<S16>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S16>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S9>/Merge7' incorporates:
     *  Constant: '<S16>/Constant7'
     *  SignalConversion generated from: '<S16>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S9>/Merge9' incorporates:
     *  Constant: '<S16>/Constant9'
     *  SignalConversion generated from: '<S16>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S9>/Merge10' incorporates:
     *  Constant: '<S16>/Constant12'
     *  SignalConversion generated from: '<S16>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = true;

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant14'
     *  Switch: '<S16>/Switch1'
     *  UnitDelay: '<S16>/Unit Delay'
     */
    if (Robot_Control_B.Button_Disable_Wheels) {
      rtb_Swerve_Motors_Disabled = true;
    } else {
      rtb_Swerve_Motors_Disabled = ((!Robot_Control_B.Button_Enable_Wheels) &&
        (Robot_Control_DW.UnitDelay_DSTATE_ir));
    }

    /* End of Switch: '<S16>/Switch' */

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  SignalConversion generated from: '<S16>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = rtb_Swerve_Motors_Disabled;

    /* Merge: '<S9>/Merge23' incorporates:
     *  Constant: '<S16>/Constant21'
     *  SignalConversion generated from: '<S16>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* SignalConversion generated from: '<S16>/Button_Spinup_Enable' incorporates:
     *  Constant: '<S16>/Constant11'
     */
    rtb_Button_Spinup_Enable = false;

    /* SignalConversion generated from: '<S16>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S16>/Constant15'
     */
    rtb_Button_Shoot_Enable = false;

    /* SignalConversion generated from: '<S16>/Intake_Arm_Move_In' incorporates:
     *  Constant: '<S16>/Constant16'
     */
    rtb_Intake_Arm_Move_In = false;

    /* SignalConversion generated from: '<S16>/Intake_Arm_Move_Out' incorporates:
     *  Constant: '<S16>/Constant17'
     */
    rtb_Intake_Arm_Move_Out = false;

    /* SignalConversion generated from: '<S16>/Intake_Arm_Move_Cycle' incorporates:
     *  Constant: '<S16>/Constant19'
     */
    rtb_Shooter_Active_prev = false;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S16>/Constant22'
     *  SignalConversion generated from: '<S16>/Desired_Pipeline'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = TEST_Pipeline;

    /* SignalConversion generated from: '<S16>/Intake_Roller_On' incorporates:
     *  Constant: '<S16>/Constant20'
     */
    rtb_LogicalOperator1_n = false;

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S16>/Constant10'
     *  SignalConversion generated from: '<S16>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  SignalConversion: '<S16>/Signal Copy'
     */
    Robot_Control_Y.Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  SignalConversion: '<S16>/Signal Copy2'
     */
    Robot_Control_Y.Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  SignalConversion: '<S16>/Signal Copy1'
     */
    Robot_Control_Y.Reset_Wheel_Offsets =
      Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_Swerve_Motors_Disabled;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Reshape: '<S73>/Reshapey' incorporates:
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_X'
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_Y'
   *  S-Function (sfix_udelay): '<S8>/Tapped Delay'
   *  S-Function (sfix_udelay): '<S8>/Tapped Delay1'
   *  Sum: '<S8>/Add'
   *  Sum: '<S8>/Add1'
   */
  rtb_Reshapey[0] = (Robot_Control_U.Vision_RobotPoseFieldSpace_X +
                     Robot_Control_DW.TappedDelay_X[0]) +
    Robot_Control_DW.TappedDelay_X[1];
  rtb_Reshapey[1] = (Robot_Control_U.Vision_RobotPoseFieldSpace_Y +
                     Robot_Control_DW.TappedDelay1_X[0]) +
    Robot_Control_DW.TappedDelay1_X[1];

  /* Delay: '<S73>/MemoryX' incorporates:
   *  Constant: '<S73>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S100>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S126>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S93>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S124>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S124>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S73>/C'
     *  Delay: '<S73>/MemoryX'
     *  Product: '<S126>/Product'
     */
    rtb_Switch1_n = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Switch1_n;

    /* Sum: '<S124>/Sum' incorporates:
     *  Constant: '<S73>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S124>/C[k]*xhat[k|k-1]'
     *  Product: '<S124>/D[k]*u[k]'
     *  Sum: '<S124>/Add1'
     */
    rtb_Sin4 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Subtract_c3 = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Switch1_n);

    /* Product: '<S124>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S73>/C'
     *  Delay: '<S73>/MemoryX'
     *  Product: '<S126>/Product'
     */
    rtb_Switch1_n = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Switch1_n;

    /* Sum: '<S124>/Sum' incorporates:
     *  Constant: '<S73>/D'
     *  Product: '<S124>/C[k]*xhat[k|k-1]'
     *  Product: '<S124>/D[k]*u[k]'
     *  Sum: '<S124>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Switch1_n);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S124>/Product3' incorporates:
     *  Constant: '<S74>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Subtract_c3) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Product'
     */
    rtb_Switch1_n = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S124>/Product3' incorporates:
     *  Constant: '<S74>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Subtract_c3) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S126>/Product2' incorporates:
     *  Constant: '<S74>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Switch1_n) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Switch1_n) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S124>/Product3' incorporates:
       *  Outport: '<S124>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S126>/Product2' incorporates:
       *  Outport: '<S126>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S93>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S100>/Enabled Subsystem' */

  /* Sum: '<S100>/Add' incorporates:
   *  Delay: '<S73>/MemoryX'
   */
  rtb_Reshapey[0] = Robot_Control_B.Product2[0] +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Reshapey[1] = Robot_Control_B.Product2[1] +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Switch: '<S8>/Switch1'
   */
  if (KF_Enable != 0.0) {
    /* Switch: '<S8>/Switch' */
    Robot_Control_B.KF_Position_X = rtb_Reshapey[0];

    /* Switch: '<S8>/Switch1' */
    Robot_Control_B.KF_Position_Y = rtb_Reshapey[1];
  } else {
    /* Switch: '<S8>/Switch' incorporates:
     *  Inport: '<Root>/Odom_Position_X'
     */
    Robot_Control_B.KF_Position_X = Robot_Control_U.Odom_Position_X;

    /* Switch: '<S8>/Switch1' incorporates:
     *  Inport: '<Root>/Odom_Position_Y'
     */
    Robot_Control_B.KF_Position_Y = Robot_Control_U.Odom_Position_Y;
  }

  /* End of Switch: '<S8>/Switch' */

  /* If: '<S13>/If' incorporates:
   *  Constant: '<S245>/Constant'
   *  Logic: '<S245>/AND'
   *  MATLAB Function: '<S195>/Find closest index to curve'
   *  Product: '<S245>/Product'
   *  RelationalOperator: '<S245>/Relational Operator'
   *  RelationalOperator: '<S245>/Relational Operator1'
   *  Selector: '<S245>/Selector'
   *  Selector: '<S245>/Selector1'
   *  Selector: '<S246>/Selector'
   *  Sum: '<S245>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S198>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_hk == 0) {
      /* Disable for If: '<S201>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S203>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_hk = -1;

    /* End of Disable for If: '<S198>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S193>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S193>/Unit Delay'
       *  UnitDelay: '<S194>/Unit Delay'
       *  UnitDelay: '<S196>/Unit Delay'
       *  UnitDelay: '<S196>/Unit Delay1'
       *  UnitDelay: '<S246>/Unit Delay'
       *  UnitDelay: '<S246>/Unit Delay1'
       */
      Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;
      Robot_Control_DW.UnitDelay_DSTATE_hn = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_f4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_g4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_le = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_kc = 0.0;

      /* End of InitializeConditions for SubSystem: '<S13>/Spline Path Following Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    /* Selector: '<S194>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S194>/Selector1' */

    /* Lookup_n-D: '<S193>/Capture Radius' incorporates:
     *  UnitDelay: '<S193>/Unit Delay'
     */
    rtb_Subtract_c3 = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S194>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S194>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S198>/If' incorporates:
     *  RelationalOperator: '<S198>/ '
     *  UnitDelay: '<S194>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_hk;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_hk = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S201>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S203>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S198>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      /* InitializeConditions for If: '<S198>/If' incorporates:
       *  UnitDelay: '<S201>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S198>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S198>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S201>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S204>/Action Port'
       */
      /* If: '<S201>/If' incorporates:
       *  Selector: '<S194>/Selector1'
       *  Selector: '<S201>/Selector'
       *  Selector: '<S204>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S201>/Increment_If_Rectangle_Check' */

      /* Sum: '<S201>/Minus' incorporates:
       *  Concatenate: '<S194>/Matrix Concatenate2'
       *  Selector: '<S201>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S201>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S204>/Action Port'
       */
      /* If: '<S201>/If' incorporates:
       *  Selector: '<S194>/Selector1'
       *  Selector: '<S201>/Selector'
       *  Selector: '<S204>/Selector'
       *  Sum: '<S201>/Minus'
       */
      rtb_DeadZone = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S201>/Increment_If_Rectangle_Check' */

      /* Sum: '<S201>/Minus' incorporates:
       *  Concatenate: '<S194>/Matrix Concatenate2'
       *  Selector: '<S201>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_DeadZone;

      /* Math: '<S201>/Hypot' */
      rtb_Switch1_n = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S201>/Equal' */
      rtb_Is_Absolute_Steering = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S201>/Switch' incorporates:
       *  Logic: '<S201>/AND'
       *  Logic: '<S201>/OR'
       *  RelationalOperator: '<S201>/Relational Operator'
       *  UnitDelay: '<S201>/Unit Delay'
       */
      rtb_Is_Absolute_Translation_g = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Switch1_n <= rtb_Subtract_c3) && rtb_Is_Absolute_Steering));

      /* If: '<S201>/If' */
      rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_o;
      if (!rtb_Is_Absolute_Translation_g) {
        if (!rtb_Is_Absolute_Steering) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Robot_Control_DW.If_ActiveSubsystem_o = rtAction;
      if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
        /* Disable for If: '<S203>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S201>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S203>/Action Port'
         */
        /* If: '<S203>/If' incorporates:
         *  RelationalOperator: '<S203>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S203>/Is_Last_Point' incorporates:
           *  ActionPort: '<S206>/Action Port'
           */
          /* InitializeConditions for If: '<S203>/If' incorporates:
           *  UnitDelay: '<S206>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S203>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S203>/Is_Last_Point' incorporates:
           *  ActionPort: '<S206>/Action Port'
           */
          /* Switch: '<S206>/Switch' incorporates:
           *  Constant: '<S208>/Constant'
           *  Logic: '<S206>/OR'
           *  RelationalOperator: '<S208>/Compare'
           *  UnitDelay: '<S206>/Unit Delay'
           */
          rtb_AND1_c = ((Robot_Control_DW.UnitDelay_DSTATE_nu) || (rtb_Switch1_n
            <= Spline_Stop_Radius));

          /* If: '<S206>/If' */
          if (rtb_AND1_c) {
            /* Outputs for IfAction SubSystem: '<S206>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S209>/Action Port'
             */
            /* Merge: '<S198>/Merge2' incorporates:
             *  Constant: '<S209>/Constant'
             *  SignalConversion generated from: '<S209>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = true;

            /* SignalConversion generated from: '<S209>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S209>/Constant1'
             */
            rtb_Swerve_Motors_Disabled = false;

            /* End of Outputs for SubSystem: '<S206>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S206>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S210>/Action Port'
             */
            /* Merge: '<S198>/Merge2' incorporates:
             *  Constant: '<S210>/Constant'
             *  SignalConversion generated from: '<S210>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = false;

            /* SignalConversion generated from: '<S210>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S210>/Constant1'
             */
            rtb_Swerve_Motors_Disabled = true;

            /* End of Outputs for SubSystem: '<S206>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S206>/If' */

          /* Merge: '<S198>/Merge4' incorporates:
           *  SignalConversion: '<S206>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S206>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_AND1_c;

          /* End of Outputs for SubSystem: '<S203>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S203>/Increment_Search' incorporates:
           *  ActionPort: '<S205>/Action Port'
           */
          /* Merge: '<S198>/Merge2' incorporates:
           *  Constant: '<S205>/Constant'
           *  SignalConversion generated from: '<S205>/Robot_Reached_Destination'
           */
          rtb_Is_Absolute_Steering = false;

          /* SignalConversion generated from: '<S205>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S205>/Constant1'
           */
          rtb_Swerve_Motors_Disabled = false;

          /* Merge: '<S198>/Merge4' incorporates:
           *  Constant: '<S207>/FixPt Constant'
           *  SignalConversion: '<S205>/Signal Copy'
           *  Sum: '<S207>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S203>/Increment_Search' */
        }

        /* End of If: '<S203>/If' */
        /* End of Outputs for SubSystem: '<S201>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S201>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S204>/Action Port'
         */
        /* Sum: '<S211>/FixPt Sum1' incorporates:
         *  Constant: '<S211>/FixPt Constant'
         */
        rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S204>/Selector1' incorporates:
         *  Selector: '<S194>/Selector1'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) -
          1];

        /* Sum: '<S212>/Subtract' incorporates:
         *  Selector: '<S204>/Selector1'
         *  Sum: '<S212>/Minus1'
         */
        rtb_Minus_n[0] = rtb_MatrixConcatenate_b_idx_0 - rtb_Init;

        /* Selector: '<S204>/Selector1' incorporates:
         *  Selector: '<S194>/Selector1'
         */
        rtb_Switch1 = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) + 9];

        /* Sum: '<S212>/Subtract' incorporates:
         *  Selector: '<S204>/Selector1'
         *  Sum: '<S212>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1 - rtb_DeadZone;

        /* Math: '<S212>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S212>/Divide' */
        rtb_Switch1_n = rtb_Minus_n[1];

        /* UnaryMinus: '<S212>/Unary Minus' */
        rtb_Switch2_p2 = rtb_Minus_n[0];

        /* Product: '<S212>/Product' incorporates:
         *  Product: '<S212>/Divide'
         *  UnaryMinus: '<S212>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch1_n / rtb_Sin4) * rtb_Subtract_c3;
        rtb_Minus_n[1] = ((-rtb_Switch2_p2) / rtb_Sin4) * rtb_Subtract_c3;

        /* Sum: '<S212>/Add1' incorporates:
         *  Sum: '<S212>/Add2'
         *  Sum: '<S212>/Minus'
         */
        rtb_Switch2_p2 = rtb_MatrixConcatenate_b_idx_0 - rtb_Minus_n[0];

        /* Sum: '<S212>/Minus4' incorporates:
         *  Sum: '<S212>/Add2'
         *  Sum: '<S212>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = (rtb_MatrixConcatenate_b_idx_0 +
          rtb_Minus_n[0]) - rtb_Switch2_p2;

        /* Sum: '<S212>/Minus5' incorporates:
         *  Concatenate: '<S194>/Matrix Concatenate2'
         *  Sum: '<S212>/Minus'
         */
        rtb_Minus_k_idx_0 = rtb_Reshapey[0] - rtb_Switch2_p2;

        /* Sum: '<S212>/Add' incorporates:
         *  Sum: '<S212>/Add2'
         *  Sum: '<S212>/Minus1'
         */
        rtb_Switch1_n = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S212>/Minus' incorporates:
         *  Sum: '<S212>/Minus1'
         */
        rtb_Switch2_p2 -= rtb_Switch1_n;

        /* DotProduct: '<S212>/Dot Product' incorporates:
         *  Concatenate: '<S194>/Matrix Concatenate2'
         *  Sum: '<S212>/Minus'
         *  Sum: '<S212>/Minus1'
         *  Sum: '<S212>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Switch1_n) * rtb_Switch2_p2;

        /* DotProduct: '<S212>/Dot Product1' incorporates:
         *  Sum: '<S212>/Minus'
         */
        rtb_Init = rtb_Switch2_p2 * rtb_Switch2_p2;

        /* DotProduct: '<S212>/Dot Product2' incorporates:
         *  Sum: '<S212>/Minus4'
         *  Sum: '<S212>/Minus5'
         */
        rtb_Switch2 = rtb_MatrixConcatenate_b_idx_0 * rtb_Minus_k_idx_0;

        /* DotProduct: '<S212>/Dot Product3' incorporates:
         *  Sum: '<S212>/Minus4'
         */
        rtb_Minus_k_idx_1 = rtb_MatrixConcatenate_b_idx_0 *
          rtb_MatrixConcatenate_b_idx_0;

        /* Sum: '<S212>/Add1' incorporates:
         *  Sum: '<S212>/Add2'
         *  Sum: '<S212>/Minus'
         */
        rtb_Switch2_p2 = rtb_Switch1 - rtb_Minus_n[1];

        /* Sum: '<S212>/Minus4' incorporates:
         *  Sum: '<S212>/Add2'
         *  Sum: '<S212>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = (rtb_Switch1 + rtb_Minus_n[1]) -
          rtb_Switch2_p2;

        /* Sum: '<S212>/Minus5' incorporates:
         *  Concatenate: '<S194>/Matrix Concatenate2'
         *  Sum: '<S212>/Minus'
         */
        rtb_Minus_k_idx_0 = rtb_Reshapey[1] - rtb_Switch2_p2;

        /* Sum: '<S212>/Add' incorporates:
         *  Sum: '<S212>/Add2'
         *  Sum: '<S212>/Minus1'
         */
        rtb_Switch1_n = rtb_DeadZone - rtb_Minus_n[1];

        /* Sum: '<S212>/Minus' incorporates:
         *  Sum: '<S212>/Minus1'
         */
        rtb_Switch2_p2 -= rtb_Switch1_n;

        /* DotProduct: '<S212>/Dot Product' incorporates:
         *  Concatenate: '<S194>/Matrix Concatenate2'
         *  Sum: '<S212>/Minus'
         *  Sum: '<S212>/Minus1'
         *  Sum: '<S212>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Switch1_n) * rtb_Switch2_p2;

        /* RelationalOperator: '<S213>/Compare' incorporates:
         *  Constant: '<S213>/Constant'
         */
        rtb_Is_Absolute_Steering = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S212>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S212>/Dot Product1'
         *  Sum: '<S212>/Minus'
         */
        rtb_Swerve_Motors_Disabled = (rtb_Sin4 <= ((rtb_Switch2_p2 *
          rtb_Switch2_p2) + rtb_Init));

        /* DotProduct: '<S212>/Dot Product2' incorporates:
         *  Sum: '<S212>/Minus4'
         *  Sum: '<S212>/Minus5'
         */
        rtb_Sin4 = (rtb_MatrixConcatenate_b_idx_0 * rtb_Minus_k_idx_0) +
          rtb_Switch2;

        /* Merge: '<S198>/Merge4' incorporates:
         *  Constant: '<S214>/Constant'
         *  DataTypeConversion: '<S204>/Data Type Conversion'
         *  DotProduct: '<S212>/Dot Product3'
         *  Logic: '<S212>/AND'
         *  RelationalOperator: '<S212>/LessThanOrEqual1'
         *  RelationalOperator: '<S214>/Compare'
         *  Sum: '<S204>/Add'
         *  Sum: '<S212>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)
          (((rtb_Is_Absolute_Steering && rtb_Swerve_Motors_Disabled) &&
            (rtb_Sin4 >= 0.0)) && (rtb_Sin4 <= ((rtb_MatrixConcatenate_b_idx_0 *
          rtb_MatrixConcatenate_b_idx_0) + rtb_Minus_k_idx_1)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S198>/Merge2' incorporates:
         *  Constant: '<S204>/Constant2'
         *  SignalConversion generated from: '<S204>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S204>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S204>/Constant1'
         */
        rtb_Swerve_Motors_Disabled = false;

        /* End of Outputs for SubSystem: '<S201>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S201>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S202>/Action Port'
         */
        /* Merge: '<S198>/Merge2' incorporates:
         *  Constant: '<S202>/Constant2'
         *  SignalConversion generated from: '<S202>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S202>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S202>/Constant1'
         */
        rtb_Swerve_Motors_Disabled = false;

        /* Merge: '<S198>/Merge4' incorporates:
         *  SignalConversion generated from: '<S202>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S201>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S198>/Merge1' incorporates:
       *  Constant: '<S201>/Constant'
       *  SignalConversion generated from: '<S201>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S201>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_Is_Absolute_Translation_g;

      /* End of Outputs for SubSystem: '<S198>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S198>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S200>/Action Port'
       */
      /* Merge: '<S198>/Merge1' incorporates:
       *  Constant: '<S200>/Constant'
       *  SignalConversion generated from: '<S200>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S198>/Merge2' incorporates:
       *  Constant: '<S200>/Constant1'
       *  SignalConversion generated from: '<S200>/Robot_Reached_Destination'
       */
      rtb_Is_Absolute_Steering = false;

      /* SignalConversion generated from: '<S200>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S200>/Constant2'
       */
      rtb_Swerve_Motors_Disabled = false;

      /* Merge: '<S198>/Merge4' incorporates:
       *  SignalConversion generated from: '<S200>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S198>/Escape_Auto_Driving' */
    }

    /* End of If: '<S198>/If' */

    /* If: '<S194>/If1' */
    if (!rtb_Swerve_Motors_Disabled) {
      /* Outputs for IfAction SubSystem: '<S194>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S199>/Action Port'
       */
      /* Bias: '<S215>/Add Constant' incorporates:
       *  Bias: '<S215>/Bias'
       *  Sum: '<S215>/Subtract'
       */
      rtb_Switch1_n = ((Robot_Control_B.Spline_Num_Poses -
                        Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S215>/Selector4' incorporates:
       *  Bias: '<S215>/Bias1'
       *  Constant: '<S217>/FixPt Constant'
       *  Sum: '<S217>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S215>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S215>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s220_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S215>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S215>/Selector5' incorporates:
       *  Concatenate: '<S215>/Matrix Concatenate'
       *  Gain: '<S219>/Gain'
       *  Selector: '<S194>/Selector1'
       *  Selector: '<S215>/Selector2'
       *  Selector: '<S215>/Selector3'
       *  Sum: '<S219>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s220_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S215>/Matrix Concatenate' incorporates:
       *  Bias: '<S215>/Add Constant1'
       *  Gain: '<S218>/Gain'
       *  Selector: '<S194>/Selector1'
       *  Selector: '<S215>/Selector'
       *  Selector: '<S215>/Selector1'
       *  Selector: '<S215>/Selector5'
       *  Sum: '<S218>/Subtract'
       */
      s220_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s220_iter;
             rtb_Num_Segments++) {
          rtb_MatrixConcatenate_p[(rtb_Num_Segments +
            (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) + 1] =
            rtb_Selector5[(Robot_Control_DW.Selector5_DIMS1[0] * i) +
            rtb_Num_Segments];
        }
      }

      rtb_MatrixConcatenate_p[Robot_Control_DW.Selector5_DIMS1[0] + 1] =
        (rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1] * 2.0) -
        rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) - 1];
      rtb_MatrixConcatenate_p[(Robot_Control_DW.Selector5_DIMS1[0] +
        Robot_Control_DW.MatrixConcatenate_DIMS1[0]) + 1] = (rtb_Ref_Poses
        [((int32_T)Robot_Control_B.Spline_Num_Poses) + 9] * 2.0) -
        rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) + 9];

      /* Selector: '<S215>/Selector4' */
      s220_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s220_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S215>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S215>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S215>/Assignment' incorporates:
       *  Concatenate: '<S215>/Matrix Concatenate'
       *  Selector: '<S215>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s220_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S216>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S220>/While Iterator'
       */
      s220_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s220_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s220_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s220_iter] - rtb_Assignment[s220_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Init - rtb_Assignment[s220_iter];
        rtb_Init = rtb_Assignment[s220_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s220_iter + 11];
        rtb_Switch2_p2 = rtb_Assignment[s220_iter + 12];
        rtb_Add2[1] = rtb_Switch2_p2 - rtb_Assignment[s220_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Init - rtb_Switch2_p2;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Sin4 = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_DeadZone = rt_powd_snf(rtb_Sin4, 2.0);
          rtb_Init = rt_powd_snf(rtb_Sin4, 3.0);
          rtb_Switch1 = (rtb_Sin4 - (2.0 * rtb_DeadZone)) + rtb_Init;
          rtb_Switch2 = rtb_DeadZone - rtb_Init;
          rtb_Init = (3.0 * rtb_DeadZone) - (2.0 * rtb_Init);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch1) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Init))
            + rtb_Assignment[s220_iter];
          rtb_Init = ((((rtb_Minus_n[1] * rtb_Switch1) + (rtb_Add2[1] *
            rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Init)) +
            rtb_Switch2_p2;
          rtb_Switch1 = ((3.0 * rtb_DeadZone) - (4.0 * rtb_Sin4)) + 1.0;
          rtb_Switch2 = (2.0 * rtb_Sin4) - (3.0 * rtb_DeadZone);
          rtb_DeadZone = (rtb_Sin4 - rtb_DeadZone) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch1) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_DeadZone);
          rtb_Hypot_g5 = (((rtb_Minus_n[1] * rtb_Switch1) + (rtb_Add2[1] *
            rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_DeadZone);
          rtb_DeadZone = (6.0 * rtb_Sin4) - 4.0;
          rtb_Switch1 = (-6.0 * rtb_Sin4) + 2.0;
          rtb_Sin4 = (-12.0 * rtb_Sin4) + 6.0;
          rtb_Switch2 = (((rtb_Minus_n[0] * rtb_DeadZone) + (rtb_Add2[0] *
            rtb_Switch1)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Sin4);
          rtb_Switch1 = (((rtb_Minus_n[1] * rtb_DeadZone) + (rtb_Add2[1] *
            rtb_Switch1)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Sin4);
          rtb_DeadZone = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Hypot_g5), 3.0);
          rtb_Sin4 = fmax(1.0E-10, rtb_DeadZone);
          Robot_Control_DW.Relay_Mode = ((rtb_DeadZone >= 2.2204460492503131E-16)
            || (Robot_Control_DW.Relay_Mode));
          if (Robot_Control_DW.Relay_Mode) {
            rtb_DeadZone = 1.0;
          } else {
            rtb_DeadZone = -1.0;
          }

          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Init;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch1) - (rtb_Switch2 *
              rtb_Hypot_g5)) / (rtb_Sin4 * rtb_DeadZone);
        }

        if (s220_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s220_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Switch1_n - ((real_T)s220_iter);
        rtb_Num_Segments = s220_iter;
        s220_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s220_iter <= 3));

      /* End of Outputs for SubSystem: '<S216>/Sampling_Loop' */

      /* SignalConversion generated from: '<S199>/Position_and_Curvature' incorporates:
       *  Assignment: '<S220>/Assignment'
       *  Merge: '<S194>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S194>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S194>/If Action Subsystem' incorporates:
       *  ActionPort: '<S197>/Action Port'
       */
      /* Product: '<S197>/Product' incorporates:
       *  Selector: '<S194>/Selector'
       *  Selector: '<S194>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1];

      /* Product: '<S197>/Product1' incorporates:
       *  Selector: '<S194>/Selector'
       *  Selector: '<S194>/Selector1'
       */
      rtb_Switch1_n = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S197>/Product' incorporates:
         *  Constant: '<S197>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S197>/Product1' incorporates:
         *  Constant: '<S197>/Constant2'
         *  Product: '<S197>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch1_n;
      }

      /* Assignment: '<S197>/Assignment' incorporates:
       *  Concatenate: '<S197>/Matrix Concatenate'
       *  Merge: '<S194>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S197>/Assignment' */

      /* SignalConversion generated from: '<S197>/Num_Segments' incorporates:
       *  Constant: '<S197>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S194>/If Action Subsystem' */
    }

    /* End of If: '<S194>/If1' */

    /* Concatenate: '<S195>/Matrix Concatenate' incorporates:
     *  Merge: '<S194>/Merge'
     *  Selector: '<S195>/Selector'
     *  Selector: '<S195>/Selector1'
     *  Selector: '<S195>/Selector3'
     */
    for (i = 0; i < 50; i++) {
      rtb_MatrixConcatenate_o[i] = rtb_Position_and_Curvature[i];
      rtb_MatrixConcatenate_o[i + 50] = rtb_Position_and_Curvature[i + 150];
      rtb_MatrixConcatenate_o[i + 100] = rtb_Position_and_Curvature[i + 300];
      rtb_MatrixConcatenate_o[i + 150] = rtb_Position_and_Curvature[i + 50];
      rtb_MatrixConcatenate_o[i + 200] = rtb_Position_and_Curvature[i + 200];
      rtb_MatrixConcatenate_o[i + 250] = rtb_Position_and_Curvature[i + 350];
      rtb_MatrixConcatenate_o[i + 300] = rtb_Position_and_Curvature[i + 100];
      rtb_MatrixConcatenate_o[i + 350] = rtb_Position_and_Curvature[i + 250];
      rtb_MatrixConcatenate_o[i + 400] = rtb_Position_and_Curvature[i + 400];
    }

    /* End of Concatenate: '<S195>/Matrix Concatenate' */

    /* MATLAB Function: '<S195>/Distance Along Curve' incorporates:
     *  Concatenate: '<S195>/Matrix Concatenate'
     *  Selector: '<S195>/Selector4'
     *  Selector: '<S195>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s220_iter = 0; s220_iter < 149; s220_iter++) {
      /* Outputs for Iterator SubSystem: '<S216>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S220>/While Iterator'
       */
      rtb_Assignment_d[s220_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s220_iter + 1] -
         rtb_MatrixConcatenate_o[s220_iter], rtb_MatrixConcatenate_o[s220_iter +
         151] - rtb_MatrixConcatenate_o[s220_iter + 150]) +
        rtb_Assignment_d[s220_iter];

      /* End of Outputs for SubSystem: '<S216>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S195>/Distance Along Curve' */

    /* MATLAB Function: '<S195>/Find closest index to curve' incorporates:
     *  Concatenate: '<S195>/Matrix Concatenate'
     *  Selector: '<S195>/Selector4'
     *  Selector: '<S195>/Selector5'
     *  Selector: '<S246>/Selector'
     */
    for (s220_iter = 0; s220_iter < 150; s220_iter++) {
      /* Outputs for Iterator SubSystem: '<S216>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S220>/While Iterator'
       */
      distance_from_robot[s220_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s220_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s220_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S216>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s220_iter = 1;
    } else {
      s220_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s220_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s220_iter == 0) {
      rtb_Switch1_n = distance_from_robot[0];
    } else {
      rtb_Switch1_n = distance_from_robot[s220_iter - 1];
      for (rtb_Bias1_p = s220_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_n > rtb_Sin4) {
          rtb_Switch1_n = rtb_Sin4;
        }
      }
    }

    s220_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s220_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_n) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S246>/Selector' incorporates:
     *  Constant: '<S246>/Constant'
     *  MATLAB Function: '<S195>/Find closest index to curve'
     *  MinMax: '<S246>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s220_iter)) - 1];

    /* If: '<S246>/If' incorporates:
     *  RelationalOperator: '<S246>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S246>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S249>/Action Port'
       */
      /* SignalConversion generated from: '<S249>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S251>/FixPt Sum1' incorporates:
       *  Constant: '<S251>/FixPt Constant'
       */
      rtb_Switch1_n = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S249>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S249>/Selector11'
       *  Selector: '<S249>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S249>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S249>/Selector1'
       *  Selector: '<S249>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S249>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S249>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_n), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S249>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S249>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S249>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S246>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S246>/Latch' incorporates:
       *  ActionPort: '<S250>/Action Port'
       */
      /* SignalConversion generated from: '<S250>/In1' incorporates:
       *  UnitDelay: '<S246>/Unit Delay1'
       */
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S250>/In2' incorporates:
       *  UnitDelay: '<S246>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S246>/Latch' */
    }

    /* End of If: '<S246>/If' */

    /* MinMax: '<S193>/Min' incorporates:
     *  Lookup_n-D: '<S193>/Lookahead Distance'
     *  UnitDelay: '<S193>/Unit Delay'
     */
    rtb_Subtract_c3 = fmin(rtb_Subtract_c3, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S195>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S245>/While Iterator'
     */
    s245_iter = 1U;
    rtb_Is_Absolute_Translation_g = true;
    while (rtb_Is_Absolute_Translation_g && (s245_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S195>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S245>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s245_iter;
      rtb_Is_Absolute_Translation_g =
        ((rtb_Assignment_d[Robot_Control_B.WhileIterator - 1] <=
          (rtb_Assignment_d[s220_iter - 1] + rtb_Subtract_c3)) &&
         (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s245_iter++;
    }

    /* End of Outputs for SubSystem: '<S195>/Find first index that meets distance target' */

    /* Switch: '<S248>/Switch' incorporates:
     *  Concatenate: '<S195>/Matrix Concatenate'
     *  Constant: '<S195>/Constant'
     *  Constant: '<S245>/Constant'
     *  Constant: '<S248>/Constant'
     *  Constant: '<S248>/Constant1'
     *  Constant: '<S248>/Constant2'
     *  Constant: '<S248>/Constant3'
     *  Logic: '<S245>/AND'
     *  MATLAB Function: '<S195>/Find closest index to curve'
     *  Math: '<S248>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S248>/Max'
     *  MinMax: '<S248>/Min'
     *  MinMax: '<S248>/Min1'
     *  Product: '<S245>/Product'
     *  Product: '<S248>/Divide'
     *  Product: '<S248>/Product'
     *  Product: '<S248>/Product1'
     *  RelationalOperator: '<S195>/Relational Operator'
     *  RelationalOperator: '<S245>/Relational Operator'
     *  RelationalOperator: '<S245>/Relational Operator1'
     *  Selector: '<S195>/Selector10'
     *  Selector: '<S195>/Selector7'
     *  Selector: '<S195>/Selector8'
     *  Selector: '<S195>/Selector9'
     *  Selector: '<S245>/Selector'
     *  Selector: '<S245>/Selector1'
     *  Selector: '<S246>/Selector'
     *  Sqrt: '<S248>/Sqrt'
     *  Sum: '<S195>/Subtract'
     *  Sum: '<S245>/Add'
     *  Sum: '<S248>/Subtract'
     *  Sum: '<S248>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Subtract_c3 = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Switch1_n *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Subtract_c3 = fmin(rtb_Switch1_n * Spline_Velocity_Multiplier_TEST,
        sqrt(Spline_Max_Centripital_Acceleration / fmax
             (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299],
              1.0E-5)));
    }

    /* End of Switch: '<S248>/Switch' */

    /* Logic: '<S196>/OR' */
    rtb_Swerve_Motors_Disabled = (rtb_Is_Absolute_Steering ||
      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S196>/Switch1' incorporates:
     *  Switch: '<S196>/Switch'
     *  UnitDelay: '<S196>/Unit Delay'
     */
    if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S196>/Constant3'
       *  SignalConversion: '<S196>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S196>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Subtract_c3;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S196>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S196>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S195>/Selector6' incorporates:
     *  Concatenate: '<S195>/Matrix Concatenate'
     *  Selector: '<S195>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S195>/Selector2' incorporates:
     *  Concatenate: '<S195>/Matrix Concatenate'
     *  Selector: '<S195>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S196>/Switch2' incorporates:
     *  Sum: '<S252>/Subtract'
     *  Sum: '<S252>/Subtract1'
     *  Trigonometry: '<S252>/Atan2'
     *  UnitDelay: '<S196>/Unit Delay1'
     */
    if (rtb_Swerve_Motors_Disabled) {
      rtb_DeadZone = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_DeadZone = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S196>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S196>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_DeadZone;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S193>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S193>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S196>/Constant2'
     *  SignalConversion generated from: '<S193>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S196>/Constant5'
     *  SignalConversion generated from: '<S193>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S196>/Constant6'
     *  SignalConversion generated from: '<S193>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S193>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S194>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S193>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S246>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_n;

    /* Update for UnitDelay: '<S246>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S196>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S196>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_DeadZone;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S192>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S192>/Constant1'
     *  SignalConversion generated from: '<S192>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S192>/Constant'
     *  SignalConversion generated from: '<S192>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S192>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S192>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S192>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S192>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S192>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S192>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S192>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S342>/Sign2' incorporates:
   *  UnitDelay: '<S342>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S342>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S342>/Product1' incorporates:
   *  Signum: '<S342>/Sign1'
   *  Signum: '<S342>/Sign2'
   */
  rtb_Add_a5 *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_a5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_a5, 256.0);
  }

  /* Switch: '<S342>/Switch' incorporates:
   *  Constant: '<S342>/Constant'
   *  Constant: '<S347>/Constant'
   *  Constant: '<S348>/Constant'
   *  Logic: '<S342>/or'
   *  Product: '<S342>/Product1'
   *  RelationalOperator: '<S347>/Compare'
   *  RelationalOperator: '<S348>/Compare'
   *  UnitDelay: '<S342>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S342>/Switch' */

  /* Switch: '<S353>/Init' incorporates:
   *  UnitDelay: '<S353>/FixPt Unit Delay1'
   *  UnitDelay: '<S353>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Subtract_c3 = rtb_Sin4;
  } else {
    rtb_Subtract_c3 = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S353>/Init' */

  /* RelationalOperator: '<S349>/Compare' incorporates:
   *  Constant: '<S349>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S350>/Compare' incorporates:
   *  Constant: '<S350>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Sin4 > 0.0);

  /* Abs: '<S342>/Abs' incorporates:
   *  Sum: '<S342>/Subtract'
   *  UnitDelay: '<S342>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S342>/Switch5' incorporates:
   *  Constant: '<S342>/Constant1'
   *  Switch: '<S342>/Switch1'
   *  UnaryMinus: '<S342>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* SignalConversion generated from: '<S342>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S342>/Constant4'
     *  Constant: '<S342>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S342>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S342>/Constant2'
     *  Constant: '<S342>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S342>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S342>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_j), &rtb_Reshapey[0],
                         rtb_Merge1, &rtb_Minus_n[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic_j;
    rtb_Add_a5 = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S342>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S342>/Constant10'
     *  Constant: '<S342>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S342>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S342>/Constant7'
     *  Constant: '<S342>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S342>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S342>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_i), &rtb_Reshapey[0],
                         rtb_Merge1, &rtb_Minus_n[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic1_i;

    /* Switch: '<S342>/Switch3' incorporates:
     *  Constant: '<S342>/Constant1'
     *  Constant: '<S342>/Constant3'
     *  UnaryMinus: '<S342>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_a5 = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_a5 = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S342>/Switch3' */
  }

  /* End of Switch: '<S342>/Switch5' */

  /* Product: '<S342>/Product' incorporates:
   *  Switch: '<S342>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_a5 * rtb_Merge1;

  /* Sum: '<S351>/Sum1' */
  rtb_Switch1_n = rtb_Sin4 - rtb_Subtract_c3;

  /* Switch: '<S352>/Switch2' incorporates:
   *  RelationalOperator: '<S352>/LowerRelop1'
   */
  if (!(rtb_Switch1_n > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S342>/Switch2' incorporates:
     *  Constant: '<S342>/Constant1'
     *  Switch: '<S342>/Switch4'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S342>/Switch4' incorporates:
       *  Constant: '<S342>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S342>/Switch4' incorporates:
       *  Constant: '<S342>/Constant3'
       *  UnaryMinus: '<S342>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S342>/Switch2' */

    /* Product: '<S342>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S352>/Switch' incorporates:
     *  RelationalOperator: '<S352>/UpperRelop'
     */
    if (rtb_Switch1_n < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch1_n;
    }

    /* End of Switch: '<S352>/Switch' */
  }

  /* End of Switch: '<S352>/Switch2' */

  /* Sum: '<S351>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle +
    rtb_Subtract_c3;

  /* Switch: '<S345>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S345>/Switch' incorporates:
     *  Constant: '<S378>/Constant3'
     *  Constant: '<S378>/Constant4'
     *  Math: '<S378>/Math Function'
     *  Sum: '<S345>/Subtract'
     *  Sum: '<S378>/Add1'
     *  Sum: '<S378>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S345>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S345>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_a5 = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_a5)) || (rtIsInf(rtb_Add_a5))) {
    rtb_Add_a5 = 0.0;
  } else {
    rtb_Add_a5 = fmod(rtb_Add_a5, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Add_a5 < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Add_a5)))))) : ((int32_T)((uint8_T)rtb_Add_a5)));

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* Sum: '<S133>/Subtract' incorporates:
   *  Constant: '<S133>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Sin4 = Rebuilt_Match_Time_TeleOp - Robot_Control_U.MatchTime;

  /* If: '<S133>/If' incorporates:
   *  Constant: '<S159>/Constant'
   *  Constant: '<S160>/Constant'
   *  Constant: '<S161>/Constant'
   *  Constant: '<S162>/Constant'
   *  Constant: '<S163>/Constant'
   *  Constant: '<S164>/Constant'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S159>/Compare'
   *  RelationalOperator: '<S160>/Compare'
   *  RelationalOperator: '<S161>/Compare'
   *  RelationalOperator: '<S162>/Compare'
   *  RelationalOperator: '<S163>/Compare'
   *  RelationalOperator: '<S164>/Compare'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
  if ((rtb_GameState == 1) || (rtb_Sin4 <= Rebuilt_Match_Time_Transition)) {
    rtAction = 0;
  } else if (rtb_Sin4 <= Rebuilt_Match_Time_Shift_1) {
    rtAction = 1;
  } else if (rtb_Sin4 <= Rebuilt_Match_Time_Shift_2) {
    rtAction = 2;
  } else if (rtb_Sin4 <= Rebuilt_Match_Time_Shift_3) {
    rtAction = 3;
  } else if (rtb_Sin4 <= Rebuilt_Match_Time_Shift_4) {
    rtAction = 4;
  } else {
    rtAction = 5;
  }

  Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
       *  ActionPort: '<S165>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S165>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_lc = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S165>/Constant'
     *  SignalConversion generated from: '<S165>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S133>/Merge1' incorporates:
     *  Constant: '<S165>/Constant'
     *  SignalConversion generated from: '<S165>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S165>/Sum' incorporates:
     *  Constant: '<S165>/Constant1'
     *  UnitDelay: '<S165>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_lc - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S165>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S165>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_lc = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S166>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S168>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S170>/Constant'
     *  SignalConversion generated from: '<S170>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S133>/Merge1' incorporates:
     *  Constant: '<S170>/Constant'
     *  SignalConversion generated from: '<S170>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S170>/Sum' incorporates:
     *  Constant: '<S170>/Constant1'
     *  UnitDelay: '<S170>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_c - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S170>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S170>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_c = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S133>/If' */

  /* If: '<S176>/If' incorporates:
   *  If: '<S177>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S176>/Blue' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Merge: '<S176>/Merge' incorporates:
     *  Constant: '<S178>/BlueAllianceZoneX'
     *  Logic: '<S178>/AND'
     *  RelationalOperator: '<S178>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S176>/Blue' */

    /* Outputs for IfAction SubSystem: '<S177>/Blue' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* Merge: '<S177>/Merge' incorporates:
     *  Constant: '<S180>/BlueAllianceZoneX'
     *  RelationalOperator: '<S180>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S177>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S176>/Red' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    /* Merge: '<S176>/Merge' incorporates:
     *  Constant: '<S179>/RedAllianceZoneX'
     *  Logic: '<S179>/AND'
     *  RelationalOperator: '<S179>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S176>/Red' */

    /* Outputs for IfAction SubSystem: '<S177>/Red' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    /* Merge: '<S177>/Merge' incorporates:
     *  Constant: '<S181>/RedAllianceZoneX'
     *  RelationalOperator: '<S181>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S177>/Red' */
  }

  /* End of If: '<S176>/If' */

  /* RelationalOperator: '<S135>/GreaterThan' incorporates:
   *  Constant: '<S135>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S135>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S135>/Relational Operator' incorporates:
   *  Abs: '<S135>/Abs'
   *  Constant: '<S175>/Constant3'
   *  Constant: '<S175>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S175>/Math Function'
   *  Sum: '<S135>/Subtract'
   *  Sum: '<S175>/Add1'
   *  Sum: '<S175>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S134>/Max' incorporates:
   *  Abs: '<S134>/Abs1'
   *  Abs: '<S134>/Abs2'
   *  Abs: '<S134>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S135>/Relational Operator1' incorporates:
   *  Abs: '<S135>/Abs1'
   *  Constant: '<S135>/Constant2'
   *  Sum: '<S135>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S135>/Relational Operator4' incorporates:
   *  Abs: '<S135>/Abs4'
   *  Constant: '<S135>/Constant1'
   *  Sum: '<S135>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S135>/AND' */
  rtb_Is_Absolute_Translation_g = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
    (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S135>/AND2' incorporates:
   *  Logic: '<S135>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Is_Absolute_Translation_g);

  /* SignalConversion: '<S135>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S135>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Is_Absolute_Translation_g);

  /* Chart: '<S12>/Shooter_Transfer_Feeder Chart' */
  guard1 = false;
  guard2 = false;
  if (Robot_Control_DW.is_active_c2_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c2_Robot_Control = 1U;
    Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Not_Shooting;
    Robot_Control_B.RB_Shooter_Active = false;
    Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
    Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
    Robot_Control_B.RB_Transfer_Init = 0.0;
    guard1 = true;
  } else if (Robot_Control_DW.is_c2_Robot_Control ==
             Robot_Control_IN_Not_Shooting) {
    Robot_Control_B.RB_Shooter_Active = false;
    Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
    Robot_Control_B.RB_Transfer_Init = 0.0;
    if (rtb_Button_Spinup_Enable || rtb_Button_Shoot_Enable) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.RB_Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
      Robot_Control_B.RB_Transfer_Init = 1.0;
      guard2 = true;
    } else {
      guard1 = true;
    }
  } else {
    /* case IN_Shooting: */
    Robot_Control_B.RB_Shooter_Active = true;
    rtb_Is_Absolute_Translation_g = !rtb_Button_Shoot_Enable;
    if ((!rtb_Button_Spinup_Enable) && rtb_Is_Absolute_Translation_g) {
      Robot_Control_DW.is_Shooting = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Not_Shooting;
      Robot_Control_B.RB_Shooter_Active = false;
      Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
      Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
      Robot_Control_B.RB_Transfer_Init = 0.0;
      guard1 = true;
    } else {
      switch (Robot_Control_DW.is_Shooting) {
       case Robot_Control_IN_Feeder:
        Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
        Robot_Control_B.RB_Transfer_Init = 0.0;
        if (rtb_Is_Absolute_Translation_g ||
            ((Robot_Control_DW.Feeder_Loops_Shooting * 0.02) >
             Feeder_Max_Pulsetime)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
          Robot_Control_B.RB_Transfer_Init = 1.0;
        } else {
          Robot_Control_DW.Feeder_Loops_Shooting++;
        }
        break;

       case Robot_Control_IN_Spinning_Up:
        Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        Robot_Control_B.RB_Transfer_Init = 1.0;
        if (rtb_Button_Shoot_Enable && ((Robot_Control_B.RB_Ready_to_Score) ||
             (Robot_Control_B.RB_Ready_to_Pass))) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Transfer;
          Robot_Control_B.RB_Desired_Feeder_Speed =
            Rebuilt_Negative_Feeder_Speed;
          Robot_Control_B.RB_Desired_Transfer_Speed =
            Rebuilt_Target_Transfer_Speed;
        }
        break;

       default:
        /* case IN_Transfer: */
        Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Negative_Feeder_Speed;
        if (Robot_Control_U.Measured_Transfer_Speed >
            (Robot_Control_B.RB_Desired_Transfer_Speed *
             Rebuilt_Transfer_Minimum_Factor)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Feeder;
          Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
          Robot_Control_B.RB_Transfer_Init = 0.0;
          Robot_Control_DW.Feeder_Loops_Shooting = 0.0;
        } else if (rtb_Is_Absolute_Translation_g ||
                   ((Robot_Control_DW.Feeder_Loops_Shooting * 0.02) >
                    Feeder_Max_Pulsetime)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
          Robot_Control_B.RB_Transfer_Init = 1.0;
        }
        break;
      }

      guard2 = true;
    }
  }

  if (guard2) {
    /* Outputs for IfAction SubSystem: '<S132>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S139>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S141>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S143>/While Iterator'
     */
    /* If: '<S132>/If' incorporates:
     *  Constant: '<S141>/Constant'
     *  Constant: '<S142>/Constant'
     *  Constant: '<S142>/Shooter Assembly Offset in Robot'
     *  Constant: '<S142>/Shooter Assembly Offset in Robot1'
     *  Constant: '<S144>/Constant1'
     *  Constant: '<S144>/Constant10'
     *  Constant: '<S144>/Constant2'
     *  Constant: '<S144>/Constant5'
     *  Constant: '<S144>/Constant6'
     *  Constant: '<S144>/Constant7'
     *  Constant: '<S144>/Constant8'
     *  Constant: '<S144>/Constant9'
     *  Constant: '<S145>/Constant1'
     *  Constant: '<S145>/Constant10'
     *  Constant: '<S145>/Constant2'
     *  Constant: '<S145>/Constant5'
     *  Constant: '<S145>/Constant6'
     *  Constant: '<S145>/Constant7'
     *  Constant: '<S145>/Constant8'
     *  Constant: '<S145>/Constant9'
     *  Constant: '<S146>/Constant'
     *  Constant: '<S146>/Constant1'
     *  Constant: '<S146>/Constant2'
     *  Constant: '<S148>/Constant1'
     *  Constant: '<S148>/Constant10'
     *  Constant: '<S148>/Constant2'
     *  Constant: '<S148>/Constant5'
     *  Constant: '<S148>/Constant6'
     *  Constant: '<S148>/Constant7'
     *  Constant: '<S148>/Constant8'
     *  Constant: '<S148>/Constant9'
     *  Constant: '<S151>/Constant'
     *  Constant: '<S151>/Constant1'
     *  Constant: '<S151>/Constant11'
     *  Constant: '<S151>/Constant2'
     *  Constant: '<S151>/Constant3'
     *  Constant: '<S151>/Constant4'
     *  Constant: '<S151>/Constant5'
     *  Constant: '<S151>/Constant6'
     *  Constant: '<S157>/Constant1'
     *  Constant: '<S157>/Constant10'
     *  Constant: '<S157>/Constant2'
     *  Constant: '<S157>/Constant5'
     *  Constant: '<S157>/Constant6'
     *  Constant: '<S157>/Constant7'
     *  Constant: '<S157>/Constant8'
     *  Constant: '<S157>/Constant9'
     *  Constant: '<S158>/Constant1'
     *  Constant: '<S158>/Constant10'
     *  Constant: '<S158>/Constant2'
     *  Constant: '<S158>/Constant5'
     *  Constant: '<S158>/Constant6'
     *  Constant: '<S158>/Constant7'
     *  Constant: '<S158>/Constant8'
     *  Constant: '<S158>/Constant9'
     *  Gain: '<S149>/Gain1'
     *  Gain: '<S156>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S143>/Memory'
     *  Memory: '<S143>/Memory1'
     *  Memory: '<S143>/Memory2'
     *  Memory: '<S143>/Memory3'
     *  Merge: '<S132>/Merge'
     *  Merge: '<S132>/Merge2'
     *  Merge: '<S132>/Merge3'
     *  MinMax: '<S142>/Max'
     *  Product: '<S142>/Divide'
     *  RelationalOperator: '<S146>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S144>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S145>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S146>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S146>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S144>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S151>/Lookup Table Dynamic'
     *  Sum: '<S142>/Add'
     *  Sum: '<S142>/Subtract'
     *  Sum: '<S142>/Subtract1'
     *  Sum: '<S146>/Add'
     *  Switch: '<S146>/Switch'
     *  Switch: '<S146>/Switch1'
     *  Switch: '<S147>/Switch4'
     *  Switch: '<S147>/Switch5'
     *  Switch: '<S147>/Switch6'
     *  Trigonometry: '<S142>/Tanh'
     *  Trigonometry: '<S142>/Tanh1'
     *  UnitDelay: '<S146>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S141>/Iterate_Shot_Target' */
    rtb_TmpSignalConversionAtLoo_o3[0] = Rebuilt_Shoot_Hood_Pos_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Rebuilt_Shoot_Hood_Pos_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Rebuilt_Shoot_Hood_Pos_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Rebuilt_Shoot_Hood_Pos_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Rebuilt_Shoot_Hood_Pos_4;
    rtb_TmpSignalConversionAtLoo_o3[5] = Rebuilt_Shoot_Hood_Pos_5;
    rtb_TmpSignalConversionAtLoo_o3[6] = Rebuilt_Shoot_Hood_Pos_6;
    rtb_TmpSignalConversionAtLoo_o3[7] = Rebuilt_Shoot_Hood_Pos_7;
    rtb_TmpSignalConversionAtLoo_ov[0] = Rebuilt_Shoot_Gyro_Err_0;
    rtb_TmpSignalConversionAtLoo_ov[1] = Rebuilt_Shoot_Gyro_Err_1;
    rtb_TmpSignalConversionAtLoo_ov[2] = Rebuilt_Shoot_Gyro_Err_2;
    rtb_TmpSignalConversionAtLoo_ov[3] = Rebuilt_Shoot_Gyro_Err_3;
    rtb_TmpSignalConversionAtLoo_ov[4] = Rebuilt_Shoot_Gyro_Err_4;
    rtb_TmpSignalConversionAtLoo_ov[5] = Rebuilt_Shoot_Gyro_Err_5;
    rtb_TmpSignalConversionAtLoo_ov[6] = Rebuilt_Shoot_Gyro_Err_6;
    rtb_TmpSignalConversionAtLoo_ov[7] = Rebuilt_Shoot_Gyro_Err_7;
    rtb_TmpSignalConversionAtLoo_lg[0] = Rebuilt_Shoot_Shooter_Spd_0;
    rtb_TmpSignalConversionAtLoo_lg[1] = Rebuilt_Shoot_Shooter_Spd_1;
    rtb_TmpSignalConversionAtLoo_lg[2] = Rebuilt_Shoot_Shooter_Spd_2;
    rtb_TmpSignalConversionAtLoo_lg[3] = Rebuilt_Shoot_Shooter_Spd_3;
    rtb_TmpSignalConversionAtLoo_lg[4] = Rebuilt_Shoot_Shooter_Spd_4;
    rtb_TmpSignalConversionAtLoo_lg[5] = Rebuilt_Shoot_Shooter_Spd_5;
    rtb_TmpSignalConversionAtLoo_lg[6] = Rebuilt_Shoot_Shooter_Spd_6;
    rtb_TmpSignalConversionAtLoo_lg[7] = Rebuilt_Shoot_Shooter_Spd_7;
    rtb_TmpSignalConversionAtLoo_ix[0] = Rebuilt_Shoot_Shooter_Spd_I_0;
    rtb_TmpSignalConversionAtLoo_ix[1] = Rebuilt_Shoot_Shooter_Spd_I_1;
    rtb_TmpSignalConversionAtLoo_ix[2] = Rebuilt_Shoot_Shooter_Spd_I_2;
    rtb_TmpSignalConversionAtLoo_ix[3] = Rebuilt_Shoot_Shooter_Spd_I_3;
    rtb_TmpSignalConversionAtLoo_ix[4] = Rebuilt_Shoot_Shooter_Spd_I_4;
    rtb_TmpSignalConversionAtLoo_ix[5] = Rebuilt_Shoot_Shooter_Spd_I_5;
    rtb_TmpSignalConversionAtLoo_ix[6] = Rebuilt_Shoot_Shooter_Spd_I_6;
    rtb_TmpSignalConversionAtLoo_ix[7] = Rebuilt_Shoot_Shooter_Spd_I_7;
    if (Robot_Control_B.Is_Outside_Alliance_Zone) {
      /* Switch: '<S147>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S147>/Switch4' incorporates:
         *  Constant: '<S147>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S147>/Switch4' incorporates:
         *  Constant: '<S147>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S147>/Switch2' */

      /* Switch: '<S147>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S147>/Switch6' incorporates:
         *  Constant: '<S147>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S147>/Switch6' incorporates:
         *  Constant: '<S147>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S147>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S147>/Switch5' incorporates:
         *  Constant: '<S147>/Constant8'
         *  Switch: '<S147>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S147>/Switch4' incorporates:
         *  Constant: '<S147>/Constant9'
         *  Switch: '<S147>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S147>/Switch6' incorporates:
       *  Constant: '<S147>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S141>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S143>/While Iterator'
     */
    Iteration_Number = 1U;
    rtb_Merge1 = 0.0;
    rtb_Subtract_c3 = 0.0;
    rtb_Switch1_n = 0.0;
    rtb_Button_Spinup_Enable = true;
    rtb_Is_Absolute_Translation_g = true;
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_Is_Absolute_Translation_g && (Iteration_Number <= 10)) {
      /* Switch: '<S152>/Switch' incorporates:
       *  Memory: '<S143>/Memory1'
       *  Memory: '<S143>/Memory2'
       *  Switch: '<S152>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_DeadZone = rtb_Subtract_c3;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_DeadZone = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S152>/Switch' */

      /* Math: '<S150>/Hypot' incorporates:
       *  Sum: '<S150>/Subtract'
       *  Sum: '<S150>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_DeadZone -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S151>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S151>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_TOF), &rtb_TOF_g[0],
                           Robot_Control_B.RB_Desired_Shot_Distance,
                           &rtb_TmpSignalConversionAtLoo__0[0], 7U);

      /* Sum: '<S153>/Subtract' incorporates:
       *  Memory: '<S143>/Memory3'
       *  Sum: '<S153>/Subtract1'
       */
      rtb_Merge1 = rtb_TOF - rtb_Switch1_n;

      /* Sum: '<S153>/Add' incorporates:
       *  Gain: '<S153>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S153>/Product'
       *  Sum: '<S153>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S153>/Add1' incorporates:
       *  Gain: '<S153>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S153>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_DeadZone;

      /* Memory: '<S143>/Memory' */
      rtb_Is_Absolute_Translation_g = rtb_Button_Spinup_Enable;

      /* Update for Memory: '<S143>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S143>/Memory2' */
      rtb_Subtract_c3 = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S143>/Memory3' */
      rtb_Switch1_n = rtb_TOF;

      /* Update for Memory: '<S143>/Memory' incorporates:
       *  Constant: '<S155>/Constant'
       *  Math: '<S154>/Hypot'
       *  RelationalOperator: '<S155>/Compare'
       *  Sum: '<S154>/Subtract'
       *  Sum: '<S154>/Subtract1'
       */
      rtb_Button_Spinup_Enable = (rt_hypotd_snf
        (Robot_Control_B.RB_Desired_Target_X - rtb_Sin4,
         Robot_Control_B.RB_Desired_Target_Y - rtb_DeadZone) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S141>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S145>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Desired_Hood_Pos_Shoot),
                         &rtb_TmpSignalConversionAtLoo_o3[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);

    /* Dynamic Look-Up Table Block: '<S144>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_b),
                         &rtb_TmpSignalConversionAtLoo_ov[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);

    /* Dynamic Look-Up Table Block: '<S146>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd),
                         &rtb_TmpSignalConversionAtLoo_lg[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);

    /* Dynamic Look-Up Table Block: '<S146>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd),
                         &rtb_TmpSignalConversionAtLoo_ix[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);
    if (Robot_Control_B.RB_Transfer_Init != 0.0) {
      rtb_Merge1 = 0.0;
    } else {
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    if (rtb_Merge1 < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S132>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S132>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_LookupTableDynamic_b;
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = (rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      atan(-0.074675999999999992 / fmax(Robot_Control_B.RB_Desired_Shot_Distance,
      0.001))) + (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S132>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_a5 = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Minus_k_idx_1 = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S132>/Shooter Not Active' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    /* If: '<S132>/If' incorporates:
     *  Constant: '<S140>/Constant'
     *  Constant: '<S140>/Constant1'
     *  Constant: '<S140>/Constant2'
     *  Constant: '<S140>/Constant3'
     *  Merge: '<S132>/Merge'
     *  Merge: '<S132>/Merge1'
     *  Merge: '<S132>/Merge2'
     *  Merge: '<S132>/Merge3'
     *  SignalConversion generated from: '<S140>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* End of Outputs for SubSystem: '<S132>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_a5 = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S373>/Add1' incorporates:
   *  Constant: '<S373>/Constant3'
   *  Constant: '<S373>/Constant4'
   *  Math: '<S373>/Math Function'
   *  Sum: '<S372>/Sum'
   *  Sum: '<S373>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Switch2_p2 = rt_modd_snf((rtb_Add_a5 - rtb_Minus_k_idx_1) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S375>/Sum1' incorporates:
   *  Constant: '<S372>/Constant2'
   *  Product: '<S375>/Product'
   *  Sum: '<S375>/Sum'
   *  UnitDelay: '<S375>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S372>/Product' incorporates:
   *  Constant: '<S372>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S374>/Diff' incorporates:
   *  UnitDelay: '<S374>/UD'
   *
   * Block description for '<S374>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S374>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S372>/Saturation' */
  if (rtb_Add_a5 > Steering_Heading_Control_D_UL) {
    rtb_Add_a5 = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Heading_Control_D_LL) {
    rtb_Add_a5 = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S372>/Add' incorporates:
   *  Gain: '<S372>/Gain1'
   *  Saturate: '<S372>/Saturation'
   */
  rtb_Switch1_n = (Steering_Heading_Control_P * rtb_Switch2_p2) + rtb_Add_a5;

  /* Sum: '<S372>/Subtract' incorporates:
   *  Constant: '<S372>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Switch1_n;

  /* Sum: '<S372>/Sum2' incorporates:
   *  Gain: '<S372>/Gain2'
   *  UnitDelay: '<S372>/Unit Delay'
   */
  rtb_Subtract_c3 = (Steering_Heading_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S377>/Switch2' incorporates:
   *  RelationalOperator: '<S377>/LowerRelop1'
   */
  if (!(rtb_Subtract_c3 > rtb_Sin4)) {
    /* Sum: '<S372>/Subtract1' incorporates:
     *  Constant: '<S372>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Switch1_n;

    /* Switch: '<S377>/Switch' incorporates:
     *  RelationalOperator: '<S377>/UpperRelop'
     */
    if (!(rtb_Subtract_c3 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Subtract_c3;
    }

    /* End of Switch: '<S377>/Switch' */
  }

  /* End of Switch: '<S377>/Switch2' */

  /* Saturate: '<S372>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_LL;
  } else {
    rtb_Subtract_c3 = rtb_Sin4;
  }

  /* End of Saturate: '<S372>/Saturation1' */

  /* Sum: '<S372>/Add1' */
  rtb_Add_a5 = rtb_Switch1_n + rtb_Subtract_c3;

  /* Saturate: '<S372>/Saturation2' */
  if (rtb_Add_a5 > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S372>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_a5 < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S372>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S372>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_a5;
  }

  /* End of Saturate: '<S372>/Saturation2' */

  /* Switch: '<S356>/Switch' incorporates:
   *  Abs: '<S356>/Abs'
   *  Constant: '<S356>/Constant'
   *  Constant: '<S371>/Constant'
   *  RelationalOperator: '<S371>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Sin4 = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S356>/Switch' */

  /* Signum: '<S355>/Sign2' incorporates:
   *  UnitDelay: '<S355>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S355>/Sign1' */
  if (rtIsNaN(rtb_Sin4)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Sin4 < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Sin4 > 0.0);
  }

  /* Product: '<S355>/Product1' incorporates:
   *  Signum: '<S355>/Sign1'
   *  Signum: '<S355>/Sign2'
   */
  rtb_Add_a5 *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_a5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_a5, 256.0);
  }

  /* Switch: '<S355>/Switch' incorporates:
   *  Constant: '<S355>/Constant'
   *  Constant: '<S364>/Constant'
   *  Constant: '<S365>/Constant'
   *  Logic: '<S355>/or'
   *  Product: '<S355>/Product1'
   *  RelationalOperator: '<S364>/Compare'
   *  RelationalOperator: '<S365>/Compare'
   *  UnitDelay: '<S355>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Sin4;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S355>/Switch' */

  /* Switch: '<S370>/Init' incorporates:
   *  UnitDelay: '<S370>/FixPt Unit Delay1'
   *  UnitDelay: '<S370>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S370>/Init' */

  /* RelationalOperator: '<S366>/Compare' incorporates:
   *  Constant: '<S366>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S367>/Compare' incorporates:
   *  Constant: '<S367>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S355>/Abs' incorporates:
   *  Sum: '<S355>/Subtract'
   *  UnitDelay: '<S355>/Unit Delay'
   */
  rtb_Switch1_n = fabs(Robot_Control_DW.UnitDelay_DSTATE_d - rtb_Sin4);

  /* Switch: '<S355>/Switch5' incorporates:
   *  Constant: '<S355>/Constant1'
   *  Switch: '<S355>/Switch1'
   *  UnaryMinus: '<S355>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    /* SignalConversion generated from: '<S355>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S355>/Constant4'
     *  Constant: '<S355>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S355>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S355>/Constant2'
     *  Constant: '<S355>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S355>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S355>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Reshapey[0],
                         rtb_Switch1_n, &rtb_Minus_n[0], 1U);
    rtb_Switch1_n = rtb_LookupTableDynamic;
    rtb_Add_a5 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S355>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S355>/Constant10'
     *  Constant: '<S355>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S355>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S355>/Constant7'
     *  Constant: '<S355>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S355>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S355>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Reshapey[0],
                         rtb_Switch1_n, &rtb_Minus_n[0], 1U);
    rtb_Switch1_n = rtb_LookupTableDynamic1;

    /* Switch: '<S355>/Switch3' incorporates:
     *  Constant: '<S355>/Constant1'
     *  Constant: '<S355>/Constant3'
     *  UnaryMinus: '<S355>/Unary Minus'
     */
    if (rtb_Button_Shoot_Enable) {
      rtb_Add_a5 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_a5 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S355>/Switch3' */
  }

  /* End of Switch: '<S355>/Switch5' */

  /* Product: '<S355>/Product' incorporates:
   *  Switch: '<S355>/Switch1'
   */
  rtb_Init = rtb_Add_a5 * rtb_Switch1_n;

  /* Sum: '<S368>/Sum1' */
  rtb_Sin4 = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S369>/Switch2' incorporates:
   *  RelationalOperator: '<S369>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Init)) {
    /* Switch: '<S355>/Switch2' incorporates:
     *  Constant: '<S355>/Constant1'
     *  Switch: '<S355>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_DeadZone = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S355>/Switch4' incorporates:
       *  Constant: '<S355>/Constant1'
       */
      rtb_DeadZone = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S355>/Switch4' incorporates:
       *  Constant: '<S355>/Constant3'
       *  UnaryMinus: '<S355>/Unary Minus1'
       */
      rtb_DeadZone = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S355>/Switch2' */

    /* Product: '<S355>/Product2' */
    rtb_DeadZone *= rtb_Switch1_n;

    /* Switch: '<S369>/Switch' incorporates:
     *  RelationalOperator: '<S369>/UpperRelop'
     */
    if (rtb_Sin4 < rtb_DeadZone) {
      rtb_Init = rtb_DeadZone;
    } else {
      rtb_Init = rtb_Sin4;
    }

    /* End of Switch: '<S369>/Switch' */
  }

  /* End of Switch: '<S369>/Switch2' */

  /* Sum: '<S368>/Sum' */
  rtb_Switch1_n = rtb_Init + rtb_Optimized_Module_Angle_p;

  /* Signum: '<S354>/Sign2' incorporates:
   *  UnitDelay: '<S354>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S354>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S354>/Product1' incorporates:
   *  Signum: '<S354>/Sign1'
   *  Signum: '<S354>/Sign2'
   */
  rtb_Add_a5 *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_a5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_a5, 256.0);
  }

  /* Switch: '<S354>/Switch' incorporates:
   *  Constant: '<S354>/Constant'
   *  Constant: '<S357>/Constant'
   *  Constant: '<S358>/Constant'
   *  Logic: '<S354>/or'
   *  Product: '<S354>/Product1'
   *  RelationalOperator: '<S357>/Compare'
   *  RelationalOperator: '<S358>/Compare'
   *  UnitDelay: '<S354>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S354>/Switch' */

  /* Switch: '<S363>/Init' incorporates:
   *  UnitDelay: '<S363>/FixPt Unit Delay1'
   *  UnitDelay: '<S363>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S363>/Init' */

  /* RelationalOperator: '<S359>/Compare' incorporates:
   *  Constant: '<S359>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S360>/Compare' incorporates:
   *  Constant: '<S360>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S354>/Abs' incorporates:
   *  Sum: '<S354>/Subtract'
   *  UnitDelay: '<S354>/Unit Delay'
   */
  rtb_DeadZone = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                      Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S354>/Switch1' incorporates:
   *  Constant: '<S354>/Constant1'
   *  Switch: '<S354>/Switch3'
   *  Switch: '<S354>/Switch5'
   *  UnaryMinus: '<S354>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S354>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S354>/Constant1'
     *  Constant: '<S354>/Constant4'
     *  Constant: '<S354>/Constant6'
     *  UnaryMinus: '<S354>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S354>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S354>/Constant2'
     *  Constant: '<S354>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S354>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S354>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_DeadZone, &rtb_Minus_n[0], 1U);
    rtb_DeadZone = rtb_LookupTableDynamic_p;
  } else {
    if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S354>/Switch3' incorporates:
       *  Constant: '<S354>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S354>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S354>/Constant1'
     *  Constant: '<S354>/Constant10'
     *  Constant: '<S354>/Constant8'
     *  UnaryMinus: '<S354>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S354>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S354>/Constant7'
     *  Constant: '<S354>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S354>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S354>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_DeadZone, &rtb_Minus_n[0], 1U);
    rtb_DeadZone = rtb_LookupTableDynamic1_g;
  }

  /* End of Switch: '<S354>/Switch1' */

  /* Product: '<S354>/Product' */
  rtb_Sin4 *= rtb_DeadZone;

  /* Sum: '<S361>/Sum1' */
  rtb_Switch1 = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S362>/Switch2' incorporates:
   *  RelationalOperator: '<S362>/LowerRelop1'
   */
  if (!(rtb_Switch1 > rtb_Sin4)) {
    /* Switch: '<S354>/Switch2' incorporates:
     *  Constant: '<S354>/Constant1'
     *  Switch: '<S354>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S354>/Switch4' incorporates:
       *  Constant: '<S354>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S354>/Switch4' incorporates:
       *  Constant: '<S354>/Constant3'
       *  UnaryMinus: '<S354>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S354>/Switch2' */

    /* Product: '<S354>/Product2' */
    rtb_Sin4 *= rtb_DeadZone;

    /* Switch: '<S362>/Switch' incorporates:
     *  RelationalOperator: '<S362>/UpperRelop'
     */
    if (!(rtb_Switch1 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1;
    }

    /* End of Switch: '<S362>/Switch' */
  }

  /* End of Switch: '<S362>/Switch2' */

  /* Sum: '<S361>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S344>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S344>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch1_n;
  } else {
    /* Switch: '<S344>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S344>/Switch' */

  /* Fcn: '<S386>/r->x' incorporates:
   *  Fcn: '<S391>/r->x'
   *  Fcn: '<S396>/r->x'
   *  Fcn: '<S401>/r->x'
   */
  rtb_Switch1 = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S380>/Add' incorporates:
   *  Fcn: '<S386>/r->x'
   *  Fcn: '<S387>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1;

  /* Fcn: '<S386>/theta->y' incorporates:
   *  Fcn: '<S391>/theta->y'
   *  Fcn: '<S396>/theta->y'
   *  Fcn: '<S401>/theta->y'
   */
  rtb_DeadZone = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S380>/Add' incorporates:
   *  Fcn: '<S386>/theta->y'
   *  Fcn: '<S387>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S381>/Add' incorporates:
   *  Fcn: '<S392>/r->x'
   *  Fcn: '<S392>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S382>/Add' incorporates:
   *  Fcn: '<S397>/r->x'
   *  Fcn: '<S397>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S383>/Add' incorporates:
   *  Fcn: '<S402>/r->x'
   *  Fcn: '<S402>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_DeadZone;

  /* Fcn: '<S400>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S403>/Compare' incorporates:
   *  Constant: '<S403>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Init == 0.0);

  /* Switch: '<S399>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S399>/Switch1' incorporates:
     *  Constant: '<S399>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S399>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S399>/Switch1' */

  /* Fcn: '<S385>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S388>/Compare' incorporates:
   *  Constant: '<S388>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Init == 0.0);

  /* Switch: '<S384>/Switch1' */
  if (rtb_Button_Spinup_Enable) {
    /* Switch: '<S384>/Switch1' incorporates:
     *  Constant: '<S384>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S384>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S384>/Switch1' */

  /* Fcn: '<S390>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S393>/Compare' incorporates:
   *  Constant: '<S393>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S389>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S389>/Switch1' incorporates:
     *  Constant: '<S389>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S389>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S389>/Switch1' */

  /* Fcn: '<S395>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S398>/Compare' incorporates:
   *  Constant: '<S398>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S394>/Switch1' */
  if (rtb_Button_Shoot_Enable) {
    /* Switch: '<S394>/Switch1' incorporates:
     *  Constant: '<S394>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S394>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S394>/Switch1' */

  /* Product: '<S379>/Divide' incorporates:
   *  Abs: '<S379>/Abs'
   *  Abs: '<S379>/Abs1'
   *  Abs: '<S379>/Abs2'
   *  Abs: '<S379>/Abs3'
   *  Constant: '<S379>/Constant'
   *  MinMax: '<S379>/Max'
   */
  rtb_Init = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S379>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S399>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S399>/Switch' incorporates:
     *  Fcn: '<S400>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S399>/Switch' */

  /* Trigonometry: '<S334>/Cos4' incorporates:
   *  Switch: '<S323>/Angle_Switch'
   *  Trigonometry: '<S333>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S334>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S332>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S334>/Sin4' incorporates:
   *  Switch: '<S323>/Angle_Switch'
   *  Trigonometry: '<S333>/Sin4'
   */
  rtb_DeadZone = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S334>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S332>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S334>/Subtract1' incorporates:
   *  Product: '<S334>/Product2'
   *  Product: '<S334>/Product3'
   *  Trigonometry: '<S334>/Cos4'
   *  Trigonometry: '<S334>/Sin4'
   */
  rtb_Switch1 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) + (rtb_DeadZone
    * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S334>/Subtract' incorporates:
   *  Product: '<S334>/Product'
   *  Product: '<S334>/Product1'
   *  Trigonometry: '<S334>/Cos4'
   *  Trigonometry: '<S334>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_DeadZone * rtb_Optimized_Module_Angle);

  /* Math: '<S334>/Hypot' */
  rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

  /* Switch: '<S334>/Switch' incorporates:
   *  Constant: '<S334>/Constant'
   *  Constant: '<S334>/Constant1'
   *  Constant: '<S335>/Constant'
   *  Product: '<S334>/Divide'
   *  Product: '<S334>/Divide1'
   *  RelationalOperator: '<S335>/Compare'
   *  Switch: '<S334>/Switch1'
   */
  if (rtb_Minus_k_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1 / rtb_Minus_k_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Minus_k_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S334>/Switch' */

  /* Switch: '<S323>/Speed_Switch' incorporates:
   *  Abs: '<S323>/Abs'
   *  Constant: '<S331>/Constant'
   *  RelationalOperator: '<S331>/Compare'
   *  Switch: '<S323>/Angle_Switch'
   *  Trigonometry: '<S333>/Atan1'
   *  Trigonometry: '<S334>/Atan1'
   *  UnaryMinus: '<S323>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S333>/Subtract1' incorporates:
     *  Product: '<S333>/Product2'
     *  Product: '<S333>/Product3'
     *  UnaryMinus: '<S323>/Unary Minus'
     */
    rtb_Switch1 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_DeadZone * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S333>/Subtract' incorporates:
     *  Product: '<S333>/Product'
     *  Product: '<S333>/Product1'
     */
    rtb_Switch2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_DeadZone * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S333>/Hypot' */
    rtb_DeadZone = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

    /* Switch: '<S333>/Switch1' incorporates:
     *  Constant: '<S333>/Constant'
     *  Constant: '<S333>/Constant1'
     *  Constant: '<S336>/Constant'
     *  Product: '<S333>/Divide'
     *  Product: '<S333>/Divide1'
     *  RelationalOperator: '<S336>/Compare'
     *  Switch: '<S333>/Switch'
     */
    if (rtb_DeadZone > 1.0E-6) {
      rtb_Switch2 /= rtb_DeadZone;
      rtb_DeadZone = rtb_Switch1 / rtb_DeadZone;
    } else {
      rtb_Switch2 = 1.0;
      rtb_DeadZone = 0.0;
    }

    /* End of Switch: '<S333>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_DeadZone, rtb_Switch2);
  } else {
    rtb_Add_a5 = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S326>/Product2' incorporates:
   *  Constant: '<S326>/Constant'
   *  Switch: '<S323>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S321>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S321>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S324>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S325>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S256>/Product' incorporates:
   *  Abs: '<S321>/Abs'
   *  Abs: '<S324>/Abs'
   *  Constant: '<S327>/Constant'
   *  Constant: '<S337>/Constant3'
   *  Constant: '<S337>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S321>/OR'
   *  Lookup_n-D: '<S324>/1-D Lookup Table'
   *  Math: '<S337>/Math Function'
   *  RelationalOperator: '<S321>/Equal1'
   *  RelationalOperator: '<S327>/Compare'
   *  Signum: '<S321>/Sign'
   *  Signum: '<S321>/Sign1'
   *  Sum: '<S324>/Add'
   *  Sum: '<S337>/Add1'
   *  Sum: '<S337>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.BackRight_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                    rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S322>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S329>/Sum1' incorporates:
   *  Constant: '<S322>/Constant2'
   *  Product: '<S329>/Product'
   *  Sum: '<S329>/Sum'
   *  UnitDelay: '<S329>/Unit Delay1'
   */
  rtb_DeadZone = ((rtb_Switch2 - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S322>/Product' incorporates:
   *  Constant: '<S322>/Constant3'
   */
  rtb_Switch1 = rtb_DeadZone * Drive_Motor_Control_D;

  /* Sum: '<S328>/Diff' incorporates:
   *  UnitDelay: '<S328>/UD'
   *
   * Block description for '<S328>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S328>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Switch1 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S322>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S322>/Add' incorporates:
   *  Gain: '<S322>/Gain'
   *  Gain: '<S322>/Gain1'
   *  Saturate: '<S322>/Saturation'
   */
  rtb_Minus_k_idx_0 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0)
                       + (Drive_Motor_Control_P * rtb_Switch2)) + rtb_Add_a5;

  /* Saturate: '<S322>/Saturation2' incorporates:
   *  Sum: '<S322>/Add1'
   */
  if (rtb_Minus_k_idx_0 > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Minus_k_idx_0 < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_Minus_k_idx_0;
  }

  /* End of Saturate: '<S322>/Saturation2' */

  /* Switch: '<S384>/Switch' */
  if (!rtb_Button_Spinup_Enable) {
    /* Switch: '<S384>/Switch' incorporates:
     *  Fcn: '<S385>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S384>/Switch' */

  /* Trigonometry: '<S271>/Cos4' incorporates:
   *  Switch: '<S260>/Angle_Switch'
   *  Trigonometry: '<S270>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S271>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S269>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S271>/Sin4' incorporates:
   *  Switch: '<S260>/Angle_Switch'
   *  Trigonometry: '<S270>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S271>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S269>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S271>/Subtract1' incorporates:
   *  Product: '<S271>/Product2'
   *  Product: '<S271>/Product3'
   *  Trigonometry: '<S271>/Cos4'
   *  Trigonometry: '<S271>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S271>/Subtract' incorporates:
   *  Product: '<S271>/Product'
   *  Product: '<S271>/Product1'
   *  Trigonometry: '<S271>/Cos4'
   *  Trigonometry: '<S271>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S271>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Switch2, rtb_Minus_k_idx_0);

  /* Switch: '<S271>/Switch' incorporates:
   *  Constant: '<S271>/Constant'
   *  Constant: '<S271>/Constant1'
   *  Constant: '<S272>/Constant'
   *  Product: '<S271>/Divide'
   *  Product: '<S271>/Divide1'
   *  RelationalOperator: '<S272>/Compare'
   *  Switch: '<S271>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0 / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Hypot_g5;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S271>/Switch' */

  /* Product: '<S379>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S260>/Speed_Switch' incorporates:
   *  Abs: '<S260>/Abs'
   *  Constant: '<S268>/Constant'
   *  RelationalOperator: '<S268>/Compare'
   *  Switch: '<S260>/Angle_Switch'
   *  Trigonometry: '<S270>/Atan1'
   *  Trigonometry: '<S271>/Atan1'
   *  UnaryMinus: '<S260>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S270>/Subtract1' incorporates:
     *  Product: '<S270>/Product2'
     *  Product: '<S270>/Product3'
     *  UnaryMinus: '<S260>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S270>/Subtract' incorporates:
     *  Product: '<S270>/Product'
     *  Product: '<S270>/Product1'
     */
    rtb_Hypot_g5 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S270>/Hypot' */
    rtb_Switch2 = rt_hypotd_snf(rtb_Hypot_g5, rtb_Minus_k_idx_0);

    /* Switch: '<S270>/Switch1' incorporates:
     *  Constant: '<S270>/Constant'
     *  Constant: '<S270>/Constant1'
     *  Constant: '<S273>/Constant'
     *  Product: '<S270>/Divide'
     *  Product: '<S270>/Divide1'
     *  RelationalOperator: '<S273>/Compare'
     *  Switch: '<S270>/Switch'
     */
    if (rtb_Switch2 > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Switch2;
      rtb_Minus_k_idx_0 /= rtb_Switch2;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S270>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_0, rtb_Hypot_g5);
  } else {
    rtb_Add_a5 = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S263>/Product2' incorporates:
   *  Constant: '<S263>/Constant'
   *  Switch: '<S260>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S258>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S258>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S261>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S262>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S253>/Product' incorporates:
   *  Abs: '<S258>/Abs'
   *  Abs: '<S261>/Abs'
   *  Constant: '<S264>/Constant'
   *  Constant: '<S274>/Constant3'
   *  Constant: '<S274>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S258>/OR'
   *  Lookup_n-D: '<S261>/1-D Lookup Table'
   *  Math: '<S274>/Math Function'
   *  RelationalOperator: '<S258>/Equal1'
   *  RelationalOperator: '<S264>/Compare'
   *  Signum: '<S258>/Sign'
   *  Signum: '<S258>/Sign1'
   *  Sum: '<S261>/Add'
   *  Sum: '<S274>/Add1'
   *  Sum: '<S274>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S259>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_g5 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S266>/Sum1' incorporates:
   *  Constant: '<S259>/Constant2'
   *  Product: '<S266>/Product'
   *  Sum: '<S266>/Sum'
   *  UnitDelay: '<S266>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_Hypot_g5 - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S259>/Product' incorporates:
   *  Constant: '<S259>/Constant3'
   */
  rtb_Switch2 = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S265>/Diff' incorporates:
   *  UnitDelay: '<S265>/UD'
   *
   * Block description for '<S265>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S265>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S259>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S259>/Add' incorporates:
   *  Gain: '<S259>/Gain'
   *  Gain: '<S259>/Gain1'
   *  Saturate: '<S259>/Saturation'
   */
  rtb_Hypot_g5 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0) +
                  (Drive_Motor_Control_P * rtb_Hypot_g5)) + rtb_Add_a5;

  /* Saturate: '<S259>/Saturation2' incorporates:
   *  Sum: '<S259>/Add1'
   */
  if (rtb_Hypot_g5 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Hypot_g5 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = rtb_Hypot_g5;
  }

  /* End of Saturate: '<S259>/Saturation2' */

  /* Sum: '<S275>/Add1' incorporates:
   *  Constant: '<S275>/Constant3'
   *  Constant: '<S275>/Constant4'
   *  Math: '<S275>/Math Function'
   *  Sum: '<S275>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S277>/Sum1' incorporates:
   *  Constant: '<S262>/Constant2'
   *  Product: '<S277>/Product'
   *  Sum: '<S277>/Sum'
   *  UnitDelay: '<S277>/Unit Delay1'
   */
  rtb_Hypot_g5 = ((rtb_MatrixConcatenate_b_idx_0 -
                   Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S262>/Product' incorporates:
   *  Constant: '<S262>/Constant3'
   */
  rtb_MatrixConcatenate_idx_0 = rtb_Hypot_g5 * Steering_Motor_Control_D;

  /* Sum: '<S276>/Diff' incorporates:
   *  UnitDelay: '<S276>/UD'
   *
   * Block description for '<S276>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S276>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_MatrixConcatenate_idx_0 - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S262>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S262>/Add' incorporates:
   *  Gain: '<S262>/Gain1'
   *  Saturate: '<S262>/Saturation'
   */
  rtb_Add_e3 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_a5;

  /* Sum: '<S262>/Subtract' incorporates:
   *  Constant: '<S262>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_e3;

  /* Sum: '<S262>/Sum2' incorporates:
   *  Gain: '<S262>/Gain2'
   *  UnitDelay: '<S262>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S278>/Switch2' incorporates:
   *  Constant: '<S262>/Constant'
   *  RelationalOperator: '<S278>/LowerRelop1'
   *  Sum: '<S262>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_e3))) {
    /* Switch: '<S278>/Switch' incorporates:
     *  Constant: '<S262>/Constant1'
     *  RelationalOperator: '<S278>/UpperRelop'
     *  Sum: '<S262>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_e3)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_e3;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S278>/Switch' */
  }

  /* End of Switch: '<S278>/Switch2' */

  /* Saturate: '<S262>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S262>/Saturation1' */

  /* Sum: '<S262>/Add1' */
  rtb_Add_a5 = rtb_Add_e3 + rtb_Sum2_e;

  /* Saturate: '<S262>/Saturation2' */
  if (rtb_Add_a5 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_a5 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_a5;
  }

  /* End of Saturate: '<S262>/Saturation2' */

  /* Switch: '<S389>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S389>/Switch' incorporates:
     *  Fcn: '<S390>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S389>/Switch' */

  /* Trigonometry: '<S292>/Cos4' incorporates:
   *  Switch: '<S281>/Angle_Switch'
   *  Trigonometry: '<S291>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S292>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S290>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S292>/Sin4' incorporates:
   *  Switch: '<S281>/Angle_Switch'
   *  Trigonometry: '<S291>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S292>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S290>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S292>/Subtract1' incorporates:
   *  Product: '<S292>/Product2'
   *  Product: '<S292>/Product3'
   *  Trigonometry: '<S292>/Cos4'
   *  Trigonometry: '<S292>/Sin4'
   */
  rtb_Add_e3 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S292>/Subtract' incorporates:
   *  Product: '<S292>/Product'
   *  Product: '<S292>/Product1'
   *  Trigonometry: '<S292>/Cos4'
   *  Trigonometry: '<S292>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S292>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_e3);

  /* Switch: '<S292>/Switch' incorporates:
   *  Constant: '<S292>/Constant'
   *  Constant: '<S292>/Constant1'
   *  Constant: '<S293>/Constant'
   *  Product: '<S292>/Divide'
   *  Product: '<S292>/Divide1'
   *  RelationalOperator: '<S293>/Compare'
   *  Switch: '<S292>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_e3 / rtb_Hypot_b;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_b;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S292>/Switch' */

  /* Product: '<S379>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S281>/Speed_Switch' incorporates:
   *  Abs: '<S281>/Abs'
   *  Constant: '<S289>/Constant'
   *  RelationalOperator: '<S289>/Compare'
   *  Switch: '<S281>/Angle_Switch'
   *  Trigonometry: '<S291>/Atan1'
   *  Trigonometry: '<S292>/Atan1'
   *  UnaryMinus: '<S281>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S291>/Subtract1' incorporates:
     *  Product: '<S291>/Product2'
     *  Product: '<S291>/Product3'
     *  UnaryMinus: '<S281>/Unary Minus'
     */
    rtb_Add_e3 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S291>/Subtract' incorporates:
     *  Product: '<S291>/Product'
     *  Product: '<S291>/Product1'
     */
    rtb_Hypot_b = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S291>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_b, rtb_Add_e3);

    /* Switch: '<S291>/Switch1' incorporates:
     *  Constant: '<S291>/Constant'
     *  Constant: '<S291>/Constant1'
     *  Constant: '<S294>/Constant'
     *  Product: '<S291>/Divide'
     *  Product: '<S291>/Divide1'
     *  RelationalOperator: '<S294>/Compare'
     *  Switch: '<S291>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_b /= rtb_Subtract1_la;
      rtb_Add_e3 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_b = 1.0;
      rtb_Add_e3 = 0.0;
    }

    /* End of Switch: '<S291>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_e3, rtb_Hypot_b);
  } else {
    rtb_Add_a5 = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S284>/Product2' incorporates:
   *  Constant: '<S284>/Constant'
   *  Switch: '<S281>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S279>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S279>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S282>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S283>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S254>/Product' incorporates:
   *  Abs: '<S279>/Abs'
   *  Abs: '<S282>/Abs'
   *  Constant: '<S285>/Constant'
   *  Constant: '<S295>/Constant3'
   *  Constant: '<S295>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S279>/OR'
   *  Lookup_n-D: '<S282>/1-D Lookup Table'
   *  Math: '<S295>/Math Function'
   *  RelationalOperator: '<S279>/Equal1'
   *  RelationalOperator: '<S285>/Compare'
   *  Signum: '<S279>/Sign'
   *  Signum: '<S279>/Sign1'
   *  Sum: '<S282>/Add'
   *  Sum: '<S295>/Add1'
   *  Sum: '<S295>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Sum: '<S280>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_b = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S287>/Sum1' incorporates:
   *  Constant: '<S280>/Constant2'
   *  Product: '<S287>/Product'
   *  Sum: '<S287>/Sum'
   *  UnitDelay: '<S287>/Unit Delay1'
   */
  rtb_Add_e3 = ((rtb_Hypot_b - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S280>/Product' incorporates:
   *  Constant: '<S280>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_e3 * Drive_Motor_Control_D;

  /* Sum: '<S286>/Diff' incorporates:
   *  UnitDelay: '<S286>/UD'
   *
   * Block description for '<S286>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S286>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S280>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S280>/Add' incorporates:
   *  Gain: '<S280>/Gain'
   *  Gain: '<S280>/Gain1'
   *  Saturate: '<S280>/Saturation'
   */
  rtb_Hypot_b = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0) +
                 (Drive_Motor_Control_P * rtb_Hypot_b)) + rtb_Add_a5;

  /* Saturate: '<S280>/Saturation2' incorporates:
   *  Sum: '<S280>/Add1'
   */
  if (rtb_Hypot_b > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Hypot_b < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = rtb_Hypot_b;
  }

  /* End of Saturate: '<S280>/Saturation2' */

  /* Sum: '<S296>/Add1' incorporates:
   *  Constant: '<S296>/Constant3'
   *  Constant: '<S296>/Constant4'
   *  Math: '<S296>/Math Function'
   *  Sum: '<S296>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S298>/Sum1' incorporates:
   *  Constant: '<S283>/Constant2'
   *  Product: '<S298>/Product'
   *  Sum: '<S298>/Sum'
   *  UnitDelay: '<S298>/Unit Delay1'
   */
  rtb_Hypot_b = ((rtb_MatrixConcatenate_b_idx_0 -
                  Robot_Control_DW.UnitDelay1_DSTATE_n) *
                 Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S283>/Product' incorporates:
   *  Constant: '<S283>/Constant3'
   */
  rtb_Switch2_be = rtb_Hypot_b * Steering_Motor_Control_D;

  /* Sum: '<S297>/Diff' incorporates:
   *  UnitDelay: '<S297>/UD'
   *
   * Block description for '<S297>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S297>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Switch2_be - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S283>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S283>/Add' incorporates:
   *  Gain: '<S283>/Gain1'
   *  Saturate: '<S283>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)
    + rtb_Add_a5;

  /* Sum: '<S283>/Subtract' incorporates:
   *  Constant: '<S283>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S283>/Sum2' incorporates:
   *  Gain: '<S283>/Gain2'
   *  UnitDelay: '<S283>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S299>/Switch2' incorporates:
   *  Constant: '<S283>/Constant'
   *  RelationalOperator: '<S299>/LowerRelop1'
   *  Sum: '<S283>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S299>/Switch' incorporates:
     *  Constant: '<S283>/Constant1'
     *  RelationalOperator: '<S299>/UpperRelop'
     *  Sum: '<S283>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S299>/Switch' */
  }

  /* End of Switch: '<S299>/Switch2' */

  /* Saturate: '<S283>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S283>/Saturation1' */

  /* Sum: '<S283>/Add1' */
  rtb_Add_a5 = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S283>/Saturation2' */
  if (rtb_Add_a5 > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_a5 < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_a5;
  }

  /* End of Saturate: '<S283>/Saturation2' */

  /* Switch: '<S394>/Switch' */
  if (!rtb_Button_Shoot_Enable) {
    /* Switch: '<S394>/Switch' incorporates:
     *  Fcn: '<S395>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S394>/Switch' */

  /* Trigonometry: '<S313>/Cos4' incorporates:
   *  Switch: '<S302>/Angle_Switch'
   *  Trigonometry: '<S312>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S313>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S311>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S313>/Sin4' incorporates:
   *  Switch: '<S302>/Angle_Switch'
   *  Trigonometry: '<S312>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S313>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S311>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S313>/Subtract1' incorporates:
   *  Product: '<S313>/Product2'
   *  Product: '<S313>/Product3'
   *  Trigonometry: '<S313>/Cos4'
   *  Trigonometry: '<S313>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S313>/Subtract' incorporates:
   *  Product: '<S313>/Product'
   *  Product: '<S313>/Product1'
   *  Trigonometry: '<S313>/Cos4'
   *  Trigonometry: '<S313>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S313>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S313>/Switch' incorporates:
   *  Constant: '<S313>/Constant'
   *  Constant: '<S313>/Constant1'
   *  Constant: '<S314>/Constant'
   *  Product: '<S313>/Divide'
   *  Product: '<S313>/Divide1'
   *  RelationalOperator: '<S314>/Compare'
   *  Switch: '<S313>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S313>/Switch' */

  /* Product: '<S379>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S302>/Speed_Switch' incorporates:
   *  Abs: '<S302>/Abs'
   *  Constant: '<S310>/Constant'
   *  RelationalOperator: '<S310>/Compare'
   *  Switch: '<S302>/Angle_Switch'
   *  Trigonometry: '<S312>/Atan1'
   *  Trigonometry: '<S313>/Atan1'
   *  UnaryMinus: '<S302>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S312>/Subtract1' incorporates:
     *  Product: '<S312>/Product2'
     *  Product: '<S312>/Product3'
     *  UnaryMinus: '<S302>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_e) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S312>/Subtract' incorporates:
     *  Product: '<S312>/Product'
     *  Product: '<S312>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S312>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable,
      rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S312>/Switch1' incorporates:
     *  Constant: '<S312>/Constant'
     *  Constant: '<S312>/Constant1'
     *  Constant: '<S315>/Constant'
     *  Product: '<S312>/Divide'
     *  Product: '<S312>/Divide1'
     *  RelationalOperator: '<S315>/Compare'
     *  Switch: '<S312>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S312>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_uDLookupTable);
  } else {
    rtb_Add_a5 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S305>/Product2' incorporates:
   *  Constant: '<S305>/Constant'
   *  Switch: '<S302>/Speed_Switch'
   */
  rtb_Init = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S300>/Sign' */
  if (rtIsNaN(rtb_Init)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_Init < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_Init > 0.0);
  }

  /* Signum: '<S300>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S303>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S304>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S255>/Product' incorporates:
   *  Abs: '<S300>/Abs'
   *  Abs: '<S303>/Abs'
   *  Constant: '<S306>/Constant'
   *  Constant: '<S316>/Constant3'
   *  Constant: '<S316>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S300>/OR'
   *  Lookup_n-D: '<S303>/1-D Lookup Table'
   *  Math: '<S316>/Math Function'
   *  RelationalOperator: '<S300>/Equal1'
   *  RelationalOperator: '<S306>/Compare'
   *  Signum: '<S300>/Sign'
   *  Signum: '<S300>/Sign1'
   *  Sum: '<S303>/Add'
   *  Sum: '<S316>/Add1'
   *  Sum: '<S316>/Add2'
   */
  rtb_Init = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init) * look1_binlcpw(fabs
    (rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                 3.1415926535897931) - 1.5707963267948966),
    rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S301>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Init -
    Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S308>/Sum1' incorporates:
   *  Constant: '<S301>/Constant2'
   *  Product: '<S308>/Product'
   *  Sum: '<S308>/Sum'
   *  UnitDelay: '<S308>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_MatrixConcatenate_b_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S301>/Product' incorporates:
   *  Constant: '<S301>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S307>/Diff' incorporates:
   *  UnitDelay: '<S307>/UD'
   *
   * Block description for '<S307>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S307>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S301>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S301>/Add' incorporates:
   *  Gain: '<S301>/Gain'
   *  Gain: '<S301>/Gain1'
   *  Saturate: '<S301>/Saturation'
   */
  rtb_Init = ((Drive_Motor_Control_FF * rtb_Init) + (Drive_Motor_Control_P *
    rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_a5;

  /* Saturate: '<S301>/Saturation2' incorporates:
   *  Sum: '<S301>/Add1'
   */
  if (rtb_Init > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Init < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Init;
  }

  /* End of Saturate: '<S301>/Saturation2' */

  /* Sum: '<S317>/Add1' incorporates:
   *  Constant: '<S317>/Constant3'
   *  Constant: '<S317>/Constant4'
   *  Math: '<S317>/Math Function'
   *  Sum: '<S317>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S319>/Sum1' incorporates:
   *  Constant: '<S304>/Constant2'
   *  Product: '<S319>/Product'
   *  Sum: '<S319>/Sum'
   *  UnitDelay: '<S319>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Init -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S304>/Product' incorporates:
   *  Constant: '<S304>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S318>/Diff' incorporates:
   *  UnitDelay: '<S318>/UD'
   *
   * Block description for '<S318>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S318>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S304>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S304>/Add' incorporates:
   *  Gain: '<S304>/Gain1'
   *  Saturate: '<S304>/Saturation'
   */
  rtb_Add_f1 = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_a5;

  /* Sum: '<S304>/Subtract' incorporates:
   *  Constant: '<S304>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_f1;

  /* Sum: '<S304>/Sum2' incorporates:
   *  Gain: '<S304>/Gain2'
   *  UnitDelay: '<S304>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S320>/Switch2' incorporates:
   *  Constant: '<S304>/Constant'
   *  RelationalOperator: '<S320>/LowerRelop1'
   *  Sum: '<S304>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_f1))) {
    /* Sum: '<S304>/Subtract1' incorporates:
     *  Constant: '<S304>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_f1;

    /* Switch: '<S320>/Switch' incorporates:
     *  Constant: '<S304>/Constant1'
     *  RelationalOperator: '<S320>/UpperRelop'
     *  Sum: '<S304>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_f1))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
    }

    /* End of Switch: '<S320>/Switch' */
  }

  /* End of Switch: '<S320>/Switch2' */

  /* Saturate: '<S304>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S304>/Saturation1' */

  /* Sum: '<S304>/Add1' */
  rtb_Add_a5 = rtb_Add_f1 + rtb_Integral_ga;

  /* Saturate: '<S304>/Saturation2' */
  if (rtb_Add_a5 > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_a5 < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_a5;
  }

  /* End of Saturate: '<S304>/Saturation2' */

  /* Sum: '<S338>/Add1' incorporates:
   *  Constant: '<S338>/Constant3'
   *  Constant: '<S338>/Constant4'
   *  Math: '<S338>/Math Function'
   *  Sum: '<S338>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Integral_d + 3.1415926535897931, 6.2831853071795862)
    - 3.1415926535897931;

  /* Sum: '<S340>/Sum1' incorporates:
   *  Constant: '<S325>/Constant2'
   *  Product: '<S340>/Product'
   *  Sum: '<S340>/Sum'
   *  UnitDelay: '<S340>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_i)
    * Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S325>/Product' incorporates:
   *  Constant: '<S325>/Constant3'
   */
  rtb_Add_f1 = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S339>/Diff' incorporates:
   *  UnitDelay: '<S339>/UD'
   *
   * Block description for '<S339>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S339>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Add_f1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S325>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S325>/Add' incorporates:
   *  Gain: '<S325>/Gain1'
   *  Saturate: '<S325>/Saturation'
   */
  rtb_Add_fd = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_a5;

  /* Sum: '<S325>/Subtract' incorporates:
   *  Constant: '<S325>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_fd;

  /* Sum: '<S325>/Sum2' incorporates:
   *  Gain: '<S325>/Gain2'
   *  UnitDelay: '<S325>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S341>/Switch2' incorporates:
   *  Constant: '<S325>/Constant'
   *  RelationalOperator: '<S341>/LowerRelop1'
   *  Sum: '<S325>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_fd))) {
    /* Sum: '<S325>/Subtract1' incorporates:
     *  Constant: '<S325>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_fd;

    /* Switch: '<S341>/Switch' incorporates:
     *  Constant: '<S325>/Constant1'
     *  RelationalOperator: '<S341>/UpperRelop'
     *  Sum: '<S325>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_fd))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
    }

    /* End of Switch: '<S341>/Switch' */
  }

  /* End of Switch: '<S341>/Switch2' */

  /* Saturate: '<S325>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S325>/Saturation1' */

  /* Sum: '<S325>/Add1' */
  rtb_Add_a5 = rtb_Add_fd + rtb_Integral_bj;

  /* Saturate: '<S325>/Saturation2' */
  if (rtb_Add_a5 > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_a5 < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_a5;
  }

  /* End of Saturate: '<S325>/Saturation2' */

  /* Gain: '<S376>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Switch2_p2;

  /* Sum: '<S188>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S138>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S190>/Sum1' incorporates:
   *  Constant: '<S188>/Constant2'
   *  Product: '<S190>/Product'
   *  Sum: '<S188>/Sum'
   *  Sum: '<S190>/Sum'
   *  UnitDelay: '<S190>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) *
                    0.1) + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S188>/Product' incorporates:
   *  Constant: '<S188>/Constant3'
   */
  rtb_Add_fd = rtb_Switch2_p2 * 0.0;

  /* Sum: '<S189>/Diff' incorporates:
   *  UnitDelay: '<S189>/UD'
   *
   * Block description for '<S189>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S189>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Add_fd - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S188>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S188>/Add' incorporates:
   *  Gain: '<S188>/Gain'
   *  Gain: '<S188>/Gain1'
   *  Saturate: '<S188>/Saturation'
   *  Sum: '<S188>/Sum'
   */
  rtb_Init = ((Rebuilt_Transfer_Motor_Gain_FF *
               Robot_Control_B.RB_Desired_Transfer_Speed) +
              (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_a5;

  /* Logic: '<S138>/Logical Operator1' incorporates:
   *  Constant: '<S187>/Constant'
   *  RelationalOperator: '<S187>/Compare'
   */
  rtb_Button_Shoot_Enable = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S138>/Switch1' incorporates:
   *  Abs: '<S138>/Abs'
   *  Constant: '<S138>/Constant1'
   *  Constant: '<S138>/Constant2'
   *  Logic: '<S138>/Logical Operator'
   *  Logic: '<S138>/Logical Operator1'
   *  RelationalOperator: '<S138>/LessThan'
   *  UnitDelay: '<S138>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Button_Shoot_Enable) {
    rtb_Button_Spinup_Enable = true;
  } else {
    rtb_Button_Spinup_Enable = (rtb_Button_Shoot_Enable &&
      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S138>/Switch1' */

  /* Switch: '<S188>/Switch' incorporates:
   *  Constant: '<S188>/Constant4'
   */
  if (rtb_Button_Spinup_Enable) {
    /* Sum: '<S188>/Sum2' incorporates:
     *  Gain: '<S188>/Gain2'
     *  Sum: '<S188>/Sum'
     *  UnitDelay: '<S188>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Transfer_Motor_Gain_I *
      rtb_Integral_d) + Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S188>/Subtract' incorporates:
     *  Constant: '<S188>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Init;

    /* Switch: '<S191>/Switch2' incorporates:
     *  Constant: '<S188>/Constant'
     *  RelationalOperator: '<S191>/LowerRelop1'
     *  Sum: '<S188>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Init))) {
      /* Sum: '<S188>/Subtract1' incorporates:
       *  Constant: '<S188>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Init;

      /* Switch: '<S191>/Switch' incorporates:
       *  Constant: '<S188>/Constant1'
       *  RelationalOperator: '<S191>/UpperRelop'
       *  Sum: '<S188>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Init))) {
        rtb_Integral_d = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S191>/Switch' */
    }

    /* End of Switch: '<S191>/Switch2' */

    /* Saturate: '<S188>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S188>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S188>/Switch' */

  /* Switch: '<S138>/Switch2' incorporates:
   *  Logic: '<S138>/Logical Operator1'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S188>/Add1' */
    rtb_Add_a5 = rtb_Init + rtb_Integral_d;

    /* Saturate: '<S188>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S188>/Saturation2' */
  } else {
    /* Switch: '<S138>/Switch2' incorporates:
     *  Constant: '<S138>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S138>/Switch2' */

  /* Product: '<S12>/Product' incorporates:
   *  Constant: '<S12>/Constant'
   */
  Robot_Control_B.RB_Feeder_Motor_PID_DC =
    Robot_Control_B.RB_Desired_Feeder_Speed * Rebuilt_Feeder_Motor_Gain_FF;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant6'
   *  Switch: '<S10>/Switch1'
   *  Switch: '<S10>/Switch5'
   *  Switch: '<S10>/Switch6'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Transfer_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    Robot_Control_Y.Transfer_Motor_DC = TEST_Transfer_Motor_DC_OV;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S10>/Constant7'
     *  DataTypeConversion: '<S10>/Data Type Conversion'
     */
    Robot_Control_Y.Desired_Hood_Enable = (TEST_Desired_Hood_Enable_OV != 0.0);

    /* Outport: '<Root>/Feeder_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    Robot_Control_Y.Feeder_Motor_DC = TEST_Feeder_Motor_DC_OV;
    rtb_Init = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Transfer_Motor_DC' */
    Robot_Control_Y.Transfer_Motor_DC = Robot_Control_B.RB_Transfer_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S10>/Constant8'
     */
    Robot_Control_Y.Desired_Hood_Enable = true;

    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;
    rtb_Init = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_Init > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Init = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Init < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Init = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Init;

  /* Switch: '<S130>/Init' incorporates:
   *  UnitDelay: '<S130>/FixPt Unit Delay1'
   *  UnitDelay: '<S130>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S130>/Init' */

  /* Sum: '<S128>/Sum1' */
  rtb_Init -= rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S129>/Switch2' incorporates:
   *  Constant: '<S127>/Constant1'
   *  Constant: '<S127>/Constant3'
   *  RelationalOperator: '<S129>/LowerRelop1'
   *  RelationalOperator: '<S129>/UpperRelop'
   *  Switch: '<S129>/Switch'
   */
  if (rtb_Init > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Init < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     */
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S129>/Switch2' */

  /* Sum: '<S128>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Init + rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Logic: '<S6>/Logical Operator'
   */
  if (rtb_Shooter_Active_prev || rtb_LogicalOperator1_n) {
    rtb_Init = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S56>/Logical Operator1' incorporates:
   *  Constant: '<S68>/Constant'
   *  RelationalOperator: '<S68>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Init == 0.0);

  /* Sum: '<S69>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S56>/Subtract'
   */
  rtb_Error_n = rtb_Init - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S71>/Sum1' incorporates:
   *  Constant: '<S69>/Constant2'
   *  Product: '<S71>/Product'
   *  Sum: '<S69>/Sum'
   *  Sum: '<S71>/Sum'
   *  UnitDelay: '<S71>/Unit Delay1'
   */
  rtb_Sum1_fh = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S69>/Product' incorporates:
   *  Constant: '<S69>/Constant3'
   */
  rtb_Product_m5 = rtb_Sum1_fh * 0.0;

  /* Sum: '<S70>/Diff' incorporates:
   *  UnitDelay: '<S70>/UD'
   *
   * Block description for '<S70>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S70>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_m5 - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S69>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S69>/Add' incorporates:
   *  Gain: '<S69>/Gain'
   *  Gain: '<S69>/Gain1'
   *  Saturate: '<S69>/Saturation'
   *  Sum: '<S69>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Init) +
    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_a5;

  /* Switch: '<S56>/Switch1' incorporates:
   *  Abs: '<S56>/Abs'
   *  Constant: '<S56>/Constant1'
   *  Constant: '<S56>/Constant2'
   *  Logic: '<S56>/Logical Operator'
   *  Logic: '<S56>/Logical Operator1'
   *  RelationalOperator: '<S56>/LessThan'
   *  UnitDelay: '<S56>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Button_Shoot_Enable = true;
  } else {
    rtb_Button_Shoot_Enable = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S56>/Switch1' */

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/Constant4'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S69>/Sum2' incorporates:
     *  Gain: '<S69>/Gain2'
     *  Sum: '<S69>/Sum'
     *  UnitDelay: '<S69>/Unit Delay'
     */
    rtb_Init = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S69>/Subtract' incorporates:
     *  Constant: '<S69>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_MatrixConcatenate_b_idx_0;

    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S69>/Constant'
     *  RelationalOperator: '<S72>/LowerRelop1'
     *  Sum: '<S69>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S69>/Subtract1' incorporates:
       *  Constant: '<S69>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S72>/Switch' incorporates:
       *  Constant: '<S69>/Constant1'
       *  RelationalOperator: '<S72>/UpperRelop'
       *  Sum: '<S69>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Error_n = rtb_Init;
      }

      /* End of Switch: '<S72>/Switch' */
    }

    /* End of Switch: '<S72>/Switch2' */

    /* Saturate: '<S69>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Error_n = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Error_n = -0.1;
    }

    /* End of Saturate: '<S69>/Saturation1' */
  } else {
    rtb_Error_n = 0.0;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Switch: '<S56>/Switch2' incorporates:
   *  Logic: '<S56>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S69>/Add1' */
    rtb_Add_a5 = rtb_MatrixConcatenate_b_idx_0 + rtb_Error_n;

    /* Saturate: '<S69>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S69>/Saturation2' */
  } else {
    /* Switch: '<S56>/Switch2' incorporates:
     *  Constant: '<S56>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S56>/Switch2' */

  /* Switch: '<S10>/Switch8' incorporates:
   *  Constant: '<S10>/Constant'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Intake_Roller_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant10'
     */
    Robot_Control_Y.Intake_Roller_Motor_DC = TEST_Intake_Roller_Motor_DC_OV;
  } else {
    /* Outport: '<Root>/Intake_Roller_Motor_DC' */
    Robot_Control_Y.Intake_Roller_Motor_DC =
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC;
  }

  /* End of Switch: '<S10>/Switch8' */

  /* Sum: '<S51>/Add1' incorporates:
   *  Constant: '<S51>/Constant3'
   *  Constant: '<S51>/Constant4'
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Math: '<S51>/Math Function'
   *  Sum: '<S51>/Add2'
   */
  Robot_Control_B.RB_Intake_Arm_Angle_Mod = rt_modd_snf
    (Robot_Control_U.Measured_Intake_Arm_Angle + 180.0, 360.0) - 180.0;

  /* Chart: '<S6>/Chart' incorporates:
   *  RelationalOperator: '<S53>/FixPt Relational Operator'
   *  UnitDelay: '<S53>/Delay Input1'
   *
   * Block description for '<S53>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Robot_Control_DW.is_active_c4_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c4_Robot_Control = 1U;
    Robot_Control_DW.is_c4_Robot_Control = Robot_Contro_IN_Wait_for_Button;
    Robot_Control_B.RB_Des_Intake_Arm_Angle =
      Robot_Control_B.RB_Intake_Arm_Angle_Mod;
  } else {
    switch (Robot_Control_DW.is_c4_Robot_Control) {
     case Robot_Con_IN_Move_Intake_Arm_In:
      if ((rtb_Intake_Arm_Move_Out || (rtb_Shooter_Active_prev &&
            (Robot_Control_B.RB_Intake_Arm_Angle_Mod <
             Rebuilt_Intake_Cycle_Angle_In))) || (((int32_T)
            rtb_Shooter_Active_prev) < ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_c))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      if (rtb_Intake_Arm_Move_In || (rtb_Shooter_Active_prev &&
           (Robot_Control_B.RB_Intake_Arm_Angle_Mod >
            Rebuilt_Intake_Cycle_Angle_Out))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
      }
      break;

     default:
      /* case IN_Wait_for_Button: */
      if (rtb_Intake_Arm_Move_In || rtb_Shooter_Active_prev) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
      } else if (rtb_Intake_Arm_Move_Out) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* Switch: '<S67>/Init' incorporates:
   *  UnitDelay: '<S67>/FixPt Unit Delay1'
   *  UnitDelay: '<S67>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S67>/Init' */

  /* Sum: '<S65>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_Init;

  /* Switch: '<S66>/Switch2' incorporates:
   *  Constant: '<S55>/Constant1'
   *  Constant: '<S55>/Constant3'
   *  RelationalOperator: '<S66>/LowerRelop1'
   *  RelationalOperator: '<S66>/UpperRelop'
   *  Switch: '<S66>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Intake_RL_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S66>/Switch2' */

  /* Sum: '<S65>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Init;

  /* Sum: '<S61>/Sum' */
  rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S63>/Sum1' incorporates:
   *  Constant: '<S61>/Constant2'
   *  Product: '<S63>/Product'
   *  Sum: '<S63>/Sum'
   *  UnitDelay: '<S63>/Unit Delay1'
   */
  rtb_Sum1_dj = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S61>/Product' incorporates:
   *  Constant: '<S61>/Constant3'
   */
  rtb_Product_aa = rtb_Sum1_dj * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S62>/Diff' incorporates:
   *  UnitDelay: '<S62>/UD'
   *
   * Block description for '<S62>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S62>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_aa - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S61>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S61>/Add' incorporates:
   *  Gain: '<S61>/Gain'
   *  Gain: '<S61>/Gain1'
   *  Saturate: '<S61>/Saturation'
   */
  rtb_Add_i = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
               (Rebuilt_Intake_Arm_Gain_P * rtb_Init)) + rtb_Add_a5;

  /* Sum: '<S61>/Subtract' incorporates:
   *  Constant: '<S61>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_i;

  /* Sum: '<S61>/Sum2' incorporates:
   *  Gain: '<S61>/Gain2'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  rtb_Init = (0.0 * rtb_Init) + Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S64>/Switch2' incorporates:
   *  Constant: '<S61>/Constant'
   *  RelationalOperator: '<S64>/LowerRelop1'
   *  Sum: '<S61>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_i))) {
    /* Sum: '<S61>/Subtract1' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_i;

    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S61>/Constant1'
     *  RelationalOperator: '<S64>/UpperRelop'
     *  Sum: '<S61>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_i))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
    }

    /* End of Switch: '<S64>/Switch' */
  }

  /* End of Switch: '<S64>/Switch2' */

  /* Saturate: '<S61>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > 0.1) {
    rtb_MatrixConcatenate_b_idx_0 = 0.1;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -0.1) {
    rtb_MatrixConcatenate_b_idx_0 = -0.1;
  }

  /* End of Saturate: '<S61>/Saturation1' */

  /* Switch: '<S54>/Switch2' incorporates:
   *  Constant: '<S57>/Constant'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S59>/Constant'
   *  Constant: '<S60>/Constant'
   *  Logic: '<S54>/Logical Operator1'
   *  Logic: '<S54>/Logical Operator2'
   *  Logic: '<S54>/Logical Operator3'
   *  RelationalOperator: '<S57>/Compare'
   *  RelationalOperator: '<S58>/Compare'
   *  RelationalOperator: '<S59>/Compare'
   *  RelationalOperator: '<S60>/Compare'
   */
  if (((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_In) && (Robot_Control_B.RB_Intake_Arm_Angle_Mod
        <= Rebuilt_Intake_Meas_In_Disable)) ||
      ((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_Out) &&
       (Robot_Control_B.RB_Intake_Arm_Angle_Mod >=
        Rebuilt_Intake_Meas_Out_Disable))) {
    /* Switch: '<S54>/Switch2' incorporates:
     *  Constant: '<S54>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  } else {
    /* Sum: '<S61>/Add1' */
    rtb_Add_a5 = rtb_Add_i + rtb_MatrixConcatenate_b_idx_0;

    /* Saturate: '<S61>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S61>/Saturation2' */
  }

  /* End of Switch: '<S54>/Switch2' */

  /* Switch: '<S10>/Switch7' incorporates:
   *  Constant: '<S10>/Constant'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Intake_Arm_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant9'
     */
    Robot_Control_Y.Intake_Arm_Motor_DC = TEST_Intake_Arm_Motor_DC_OV;
  } else {
    /* Outport: '<Root>/Intake_Arm_Motor_DC' */
    Robot_Control_Y.Intake_Arm_Motor_DC =
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC;
  }

  /* End of Switch: '<S10>/Switch7' */

  /* Logic: '<S136>/Logical Operator1' incorporates:
   *  Constant: '<S182>/Constant'
   *  RelationalOperator: '<S182>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S183>/Sum' incorporates:
   *  Sum: '<S136>/Subtract'
   */
  rtb_Init = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S185>/Sum1' incorporates:
   *  Constant: '<S183>/Constant2'
   *  Product: '<S185>/Product'
   *  Sum: '<S183>/Sum'
   *  Sum: '<S185>/Sum'
   *  UnitDelay: '<S185>/Unit Delay1'
   */
  rtb_Add_i = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S183>/Product' incorporates:
   *  Constant: '<S183>/Constant3'
   */
  rtb_Product_bg = rtb_Add_i * 0.0;

  /* Sum: '<S184>/Diff' incorporates:
   *  UnitDelay: '<S184>/UD'
   *
   * Block description for '<S184>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S184>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_bg - Robot_Control_DW.UD_DSTATE_kz;

  /* Saturate: '<S183>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S183>/Add' incorporates:
   *  Gain: '<S183>/Gain'
   *  Gain: '<S183>/Gain1'
   *  Saturate: '<S183>/Saturation'
   *  Sum: '<S183>/Sum'
   */
  rtb_Add_a5 += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Init);

  /* Switch: '<S136>/Switch4' incorporates:
   *  Constant: '<S136>/Constant6'
   *  Constant: '<S136>/Constant7'
   *  Logic: '<S136>/Logical Operator1'
   *  Logic: '<S136>/Logical Operator2'
   *  RelationalOperator: '<S136>/LessThan2'
   *  UnitDelay: '<S136>/Unit Delay1'
   */
  if ((rtb_Init < 0.0) && rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay1_DSTATE_ea));
  }

  /* End of Switch: '<S136>/Switch4' */

  /* Switch: '<S136>/Switch1' incorporates:
   *  Constant: '<S136>/Constant1'
   *  Constant: '<S136>/Constant2'
   *  Logic: '<S136>/Logical Operator'
   *  Logic: '<S136>/Logical Operator1'
   *  RelationalOperator: '<S136>/LessThan'
   *  UnitDelay: '<S136>/Unit Delay'
   */
  if ((rtb_Init < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S136>/Switch1' */

  /* Switch: '<S183>/Switch' incorporates:
   *  Constant: '<S183>/Constant4'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S183>/Sum2' incorporates:
     *  Gain: '<S183>/Gain2'
     *  Product: '<S183>/Product1'
     *  Sum: '<S183>/Sum'
     *  Switch: '<S183>/Switch1'
     *  UnitDelay: '<S183>/Unit Delay'
     */
    rtb_Init = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Init) * ((real_T)
      (!rtb_Intake_Arm_Move_In))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S183>/Subtract' incorporates:
     *  Constant: '<S183>/Constant'
     */
    rtb_Error_c5 = 1.0 - rtb_Add_a5;

    /* Switch: '<S186>/Switch2' incorporates:
     *  Constant: '<S183>/Constant'
     *  RelationalOperator: '<S186>/LowerRelop1'
     *  Sum: '<S183>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Add_a5))) {
      /* Sum: '<S183>/Subtract1' incorporates:
       *  Constant: '<S183>/Constant1'
       */
      rtb_Error_c5 = -1.0 - rtb_Add_a5;

      /* Switch: '<S186>/Switch' incorporates:
       *  Constant: '<S183>/Constant1'
       *  RelationalOperator: '<S186>/UpperRelop'
       *  Sum: '<S183>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Add_a5))) {
        rtb_Error_c5 = rtb_Init;
      }

      /* End of Switch: '<S186>/Switch' */
    }

    /* End of Switch: '<S186>/Switch2' */

    /* Saturate: '<S183>/Saturation1' */
    if (rtb_Error_c5 > 0.1) {
      rtb_Init = 0.1;
    } else if (rtb_Error_c5 < -0.1) {
      rtb_Init = -0.1;
    } else {
      rtb_Init = rtb_Error_c5;
    }

    /* End of Saturate: '<S183>/Saturation1' */
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S183>/Switch' */

  /* Switch: '<S136>/Switch2' incorporates:
   *  Logic: '<S136>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S183>/Add1' */
    rtb_Add_a5 += rtb_Init;

    /* Saturate: '<S183>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S136>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S136>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S136>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S183>/Saturation2' */
  } else {
    /* Switch: '<S136>/Switch2' incorporates:
     *  Constant: '<S136>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S136>/Switch2' */

  /* Switch: '<S10>/Switch2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Switch: '<S10>/Switch3'
   *  Switch: '<S10>/Switch4'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Shooter_Motor_DC_Left' incorporates:
     *  Constant: '<S10>/Constant3'
     */
    Robot_Control_Y.Shooter_Motor_DC_Left = TEST_Shooter_Motor_DC_Left_OV;

    /* Outport: '<Root>/Shooter_Motor_DC_Center' incorporates:
     *  Constant: '<S10>/Constant4'
     */
    Robot_Control_Y.Shooter_Motor_DC_Center = TEST_Shooter_Motor_DC_Center_OV;

    /* Outport: '<Root>/Shooter_Motor_DC_Right' incorporates:
     *  Constant: '<S10>/Constant5'
     */
    Robot_Control_Y.Shooter_Motor_DC_Right = TEST_Shooter_Motor_DC_Right_OV;
  } else {
    /* Outport: '<Root>/Shooter_Motor_DC_Left' */
    Robot_Control_Y.Shooter_Motor_DC_Left =
      Robot_Control_B.RB_Shooter_Motor_PID_DC;

    /* Outport: '<Root>/Shooter_Motor_DC_Center' */
    Robot_Control_Y.Shooter_Motor_DC_Center =
      Robot_Control_B.RB_Shooter_Motor_PID_DC;

    /* Outport: '<Root>/Shooter_Motor_DC_Right' */
    Robot_Control_Y.Shooter_Motor_DC_Right =
      Robot_Control_B.RB_Shooter_Motor_PID_DC;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Chart: '<S11>/Chart' */
  if (Robot_Control_DW.is_active_c9_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c9_Robot_Control = 1U;
    Robot_Control_B.Active_GameState = 0U;
    Robot_Control_DW.is_c9_Robot_Control = Robot_Control_IN_Disabled;
  } else if (Robot_Control_DW.is_c9_Robot_Control == Robot_Control_IN_Disabled)
  {
    if (rtb_GameState != 0) {
      Robot_Control_DW.is_c9_Robot_Control = Robot_Control_IN_Not_Disabled;
      Robot_Control_B.Active_GameState = rtb_GameState;
    }

    /* case IN_Not_Disabled: */
  } else if (rtb_GameState == 0) {
    Robot_Control_DW.is_c9_Robot_Control = Robot_Control_IN_Disabled;
  } else {
    Robot_Control_B.Active_GameState = rtb_GameState;
  }

  /* End of Chart: '<S11>/Chart' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant2'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  Robot_Control_B.loop_counter_robot_control++;

  /* SignalConversion: '<S5>/Signal Copy4' incorporates:
   *  Inport: '<Root>/Joystick_Right_X'
   */
  Robot_Control_B.Steer_Joystick_X = Robot_Control_U.Joystick_Right_X;

  /* SignalConversion: '<Root>/Signal Copy' incorporates:
   *  Inport: '<Root>/Measured_Feeder_Speed'
   */
  Robot_Control_B.Feeder_Motor_Speed_tp = Robot_Control_U.Measured_Feeder_Speed;

  /* Update for UnitDelay: '<S33>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *
   * Block description for '<S33>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Joystick_Left_B11;

  /* Update for UnitDelay: '<S34>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *
   * Block description for '<S34>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Joystick_Left_B12;

  /* Update for UnitDelay: '<S35>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *
   * Block description for '<S35>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Joystick_Left_B13;

  /* Update for UnitDelay: '<S42>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S42>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S42>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S46>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S46>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_n = 0U;

  /* Update for UnitDelay: '<S46>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_o = rtb_Switch1_hb;

  /* Update for UnitDelay: '<S50>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S50>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_k = 0U;

  /* Update for UnitDelay: '<S50>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_i = rtb_Switch1_ae;

  /* Update for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = Robot_Control_B.Spline_Index;

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ll =
    Robot_Control_B.Robot_Reached_Destination;

  /* Update for S-Function (sfix_udelay): '<S8>/Tapped Delay' incorporates:
   *  Inport: '<Root>/Odom_Delta_X'
   */
  Robot_Control_DW.TappedDelay_X[0] = Robot_Control_DW.TappedDelay_X[1];
  Robot_Control_DW.TappedDelay_X[1] = Robot_Control_U.Odom_Delta_X;

  /* Update for S-Function (sfix_udelay): '<S8>/Tapped Delay1' incorporates:
   *  Inport: '<Root>/Odom_Delta_Y'
   */
  Robot_Control_DW.TappedDelay1_X[0] = Robot_Control_DW.TappedDelay1_X[1];
  Robot_Control_DW.TappedDelay1_X[1] = Robot_Control_U.Odom_Delta_Y;

  /* Update for Delay: '<S73>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S93>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S73>/A'
   *  Delay: '<S73>/MemoryX'
   */
  rtb_Sum1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Switch1_hb = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S73>/MemoryX' incorporates:
   *  Constant: '<S73>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S93>/A[k]*xhat[k|k-1]'
   *  Product: '<S93>/B[k]*u[k]'
   *  Sum: '<S93>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Sum1) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Switch1_hb) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S353>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S353>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_1_DSTATE =
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_4_DSTATE =
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_2_DSTATE = Robot_Control_B.RB_Desired_Shooter_Speed;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_3_DSTATE =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S375>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S374>/UD'
   *
   * Block description for '<S374>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S372>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Subtract_c3;

  /* Update for UnitDelay: '<S355>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch1_n;

  /* Update for UnitDelay: '<S370>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S370>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S370>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Switch1_n;

  /* Update for UnitDelay: '<S354>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S363>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S363>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S363>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S329>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_DeadZone;

  /* Update for UnitDelay: '<S328>/UD'
   *
   * Block description for '<S328>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S322>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S266>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S265>/UD'
   *
   * Block description for '<S265>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Switch2;

  /* Update for UnitDelay: '<S259>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S277>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S276>/UD'
   *
   * Block description for '<S276>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S262>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S287>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_e3;

  /* Update for UnitDelay: '<S286>/UD'
   *
   * Block description for '<S286>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S280>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S298>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_b;

  /* Update for UnitDelay: '<S297>/UD'
   *
   * Block description for '<S297>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_be;

  /* Update for UnitDelay: '<S283>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S308>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S307>/UD'
   *
   * Block description for '<S307>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S301>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S319>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S318>/UD'
   *
   * Block description for '<S318>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S304>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S340>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S339>/UD'
   *
   * Block description for '<S339>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_f1;

  /* Update for UnitDelay: '<S325>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S190>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S189>/UD'
   *
   * Block description for '<S189>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Add_fd;

  /* Update for UnitDelay: '<S188>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S138>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Button_Spinup_Enable;

  /* Update for UnitDelay: '<S130>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S130>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S71>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_fh;

  /* Update for UnitDelay: '<S70>/UD'
   *
   * Block description for '<S70>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_m5;

  /* Update for UnitDelay: '<S69>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S56>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Button_Shoot_Enable;

  /* Update for UnitDelay: '<S53>/Delay Input1'
   *
   * Block description for '<S53>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Shooter_Active_prev;

  /* Update for UnitDelay: '<S67>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S67>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S63>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_dj;

  /* Update for UnitDelay: '<S62>/UD'
   *
   * Block description for '<S62>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_aa;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S185>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Add_i;

  /* Update for UnitDelay: '<S184>/UD'
   *
   * Block description for '<S184>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_bg;

  /* Update for UnitDelay: '<S136>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S183>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Init;

  /* Update for UnitDelay: '<S136>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_db = rtb_Intake_Arm_Move_Out;
}

/* Model initialize function */
void Robot_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  Robot_Control_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S13>/If' */
  Robot_Control_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S133>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S42>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_n = 1U;

  /* InitializeConditions for UnitDelay: '<S50>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_k = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S73>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S353>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S370>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S363>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S130>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S67>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S431>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S198>/If' */
  Robot_Control_DW.If_ActiveSubsystem_hk = -1;

  /* InitializeConditions for UnitDelay: '<S194>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S198>/Robot_Index_Is_Valid' */
  /* Start for If: '<S201>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S201>/Circle_Check_Valid' */
  /* Start for If: '<S203>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S201>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S198>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S165>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lc = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem2' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem2);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem4' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem4);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S170>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem5' */
}

/* Model terminate function */
void Robot_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
