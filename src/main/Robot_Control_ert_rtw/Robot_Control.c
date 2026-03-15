/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.477
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Mar 15 14:11:08 2026
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

/* Named constants for Chart: '<S353>/Add dither' */
#define Robot_Control_IN_Dither        ((uint8_T)1U)
#define Robot_Control_IN_High          ((uint8_T)1U)
#define Robot_Control_IN_No_Dither     ((uint8_T)2U)
#define Robot_Control_IN_Off           ((uint8_T)2U)

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
                                      * Referenced by: '<S426>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S422>/Constant'
                                        *   '<S422>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S426>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S422>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S256>/Constant3'
                                        *   '<S277>/Constant3'
                                        *   '<S298>/Constant3'
                                        *   '<S319>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S256>/Constant2'
                                   *   '<S277>/Constant2'
                                   *   '<S298>/Constant2'
                                   *   '<S319>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S256>/Saturation'
                                        *   '<S277>/Saturation'
                                        *   '<S298>/Saturation'
                                        *   '<S319>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S256>/Saturation'
                                        *   '<S277>/Saturation'
                                        *   '<S298>/Saturation'
                                        *   '<S319>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S256>/Gain'
                                            *   '<S277>/Gain'
                                            *   '<S298>/Gain'
                                            *   '<S319>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S256>/Gain2'
                                        *   '<S277>/Gain2'
                                        *   '<S298>/Gain2'
                                        *   '<S319>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S256>/Saturation1'
                                         *   '<S277>/Saturation1'
                                         *   '<S298>/Saturation1'
                                         *   '<S319>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S256>/Saturation1'
                                        *   '<S277>/Saturation1'
                                        *   '<S298>/Saturation1'
                                        *   '<S319>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S256>/Gain1'
                                        *   '<S277>/Gain1'
                                        *   '<S298>/Gain1'
                                        *   '<S319>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S261>/Constant'
                            *   '<S282>/Constant'
                            *   '<S303>/Constant'
                            *   '<S324>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 2.0;     /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S175>/BlueAllianceZoneX'
                                         *   '<S177>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S144>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S144>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S144>/Constant1'
                                        *   '<S144>/Switch3'
                                        */
real_T Field_Pass_Y_Bottom = 0.63297;  /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S144>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 7.4364;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S144>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S176>/RedAllianceZoneX'
                                         *   '<S178>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S144>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S144>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S412>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S412>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rate_Limit_X = 0.02;            /* Variable: Rate_Limit_X
                                        * Referenced by: '<S36>/Constant3'
                                        */
real_T Rate_Limit_Y = 0.02;            /* Variable: Rate_Limit_Y
                                        * Referenced by: '<S37>/Constant3'
                                        */
real_T Rate_Limit_Z = 0.02;            /* Variable: Rate_Limit_Z
                                        * Referenced by: '<S38>/Constant3'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = 0.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S139>/Constant'
                                       */
real_T Rebuilt_Feeder_Motor_Gain_FF = 0.00016534;/* Variable: Rebuilt_Feeder_Motor_Gain_FF
                                                  * Referenced by: '<S12>/Constant'
                                                  */
real_T Rebuilt_Hood_Servo_Pos_Max = 1.0;/* Variable: Rebuilt_Hood_Servo_Pos_Max
                                         * Referenced by: '<S10>/Saturation'
                                         */
real_T Rebuilt_Hood_Servo_Pos_Min = 0.05;/* Variable: Rebuilt_Hood_Servo_Pos_Min
                                          * Referenced by:
                                          *   '<S10>/Saturation'
                                          *   '<S137>/Constant3'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S124>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S124>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S58>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.005;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                          * Referenced by: '<S58>/Gain1'
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
                                            *   '<S54>/Constant'
                                            */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S55>/Constant'
                                            */
real_T Rebuilt_Intake_Meas_In_Disable = -20.0;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S56>/Constant'
                                      */
real_T Rebuilt_Intake_Meas_Out_Disable = 80.0;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S57>/Constant'
                                     */
real_T Rebuilt_Intake_RL_Dec = -2.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S52>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 2.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S52>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 30.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S162>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by: '<S167>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S158>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S159>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S160>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S161>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S163>/Unit Delay'
                                      *   '<S164>/Unit Delay'
                                      *   '<S165>/Unit Delay'
                                      *   '<S166>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 3.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S168>/Constant'
                                      *   '<S169>/Constant'
                                      *   '<S170>/Constant'
                                      *   '<S171>/Constant'
                                      */
real_T Rebuilt_Match_Time_TeleOp = 140.0;/* Variable: Rebuilt_Match_Time_TeleOp
                                          * Referenced by: '<S130>/Constant'
                                          */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S156>/Constant'
                                       */
real_T Rebuilt_Negative_Feeder_Speed = -3000.0;
                                      /* Variable: Rebuilt_Negative_Feeder_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Roller_Desired_Speed = 4500.0;/* Variable: Rebuilt_Roller_Desired_Speed
                                              * Referenced by: '<S6>/Constant'
                                              */
real_T Rebuilt_Roller_Error_Integral_Enable = 300.0;
                               /* Variable: Rebuilt_Roller_Error_Integral_Enable
                                * Referenced by: '<S53>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00016534;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                                  * Referenced by: '<S66>/Gain'
                                                  */
real_T Rebuilt_Roller_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                             * Referenced by: '<S66>/Gain2'
                                             */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0001;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                             * Referenced by: '<S66>/Gain1'
                                             */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S145>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S145>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S145>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S145>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S145>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S145>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S145>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S145>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S141>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S141>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S141>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 2.7; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S141>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S141>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S141>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S141>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S141>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S142>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S142>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S142>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S142>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S142>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S142>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S142>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S142>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S132>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S132>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S132>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2700.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S155>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2900.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S155>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3150.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S155>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3300.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S155>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S155>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3650.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S155>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3850.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S155>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S155>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S154>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S154>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3450.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S154>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3600.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S154>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3800.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S154>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3950.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S154>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S154>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S154>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S148>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S148>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S148>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S148>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S148>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S148>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S148>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S148>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S152>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S133>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S180>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S180>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.001;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                             * Referenced by: '<S180>/Gain1'
                                             */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S143>/Constant2'
                                        */
real_T Rebuilt_Target_Feeder_Speed = 10080.0;/* Variable: Rebuilt_Target_Feeder_Speed
                                              * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                              */
real_T Rebuilt_Target_Transfer_Speed = 4000.0;
                                      /* Variable: Rebuilt_Target_Transfer_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Transfer_Error_Integral_Enable = 300.0;
                             /* Variable: Rebuilt_Transfer_Error_Integral_Enable
                              * Referenced by: '<S135>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S185>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S185>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S185>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S411>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S409>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S411>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S412>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S412>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S245>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S245>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S192>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S205>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S245>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S352>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S352>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S352>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S352>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S352>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S352>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S370>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S370>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S370>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S370>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S369>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S370>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S370>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S370>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S370>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S370>/Constant1'
                                   *   '<S370>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S370>/Constant'
                                   *   '<S370>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S353>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S353>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S353>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S353>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S259>/Constant3'
                                        *   '<S280>/Constant3'
                                        *   '<S301>/Constant3'
                                        *   '<S322>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S259>/Constant2'
                                *   '<S280>/Constant2'
                                *   '<S301>/Constant2'
                                *   '<S322>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S259>/Saturation'
                                           *   '<S280>/Saturation'
                                           *   '<S301>/Saturation'
                                           *   '<S322>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S259>/Saturation'
                                          *   '<S280>/Saturation'
                                          *   '<S301>/Saturation'
                                          *   '<S322>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S259>/Gain2'
                                         *   '<S280>/Gain2'
                                         *   '<S301>/Gain2'
                                         *   '<S322>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S259>/Saturation1'
                                             *   '<S280>/Saturation1'
                                             *   '<S301>/Saturation1'
                                             *   '<S322>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S259>/Saturation1'
                                            *   '<S280>/Saturation1'
                                            *   '<S301>/Saturation1'
                                            *   '<S322>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S259>/Gain1'
                                        *   '<S280>/Gain1'
                                        *   '<S301>/Gain1'
                                        *   '<S322>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S351>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S351>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S351>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S351>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S351>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S351>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S411>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S411>/Constant1'
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
                                      * Referenced by: '<S410>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S410>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S410>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S339>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S339>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S339>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S339>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S339>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S339>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S412>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S411>/Dead Zone'
                                        *   '<S412>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S411>/Dead Zone'
                                        *   '<S412>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S409>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S409>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S409>/Constant4'
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
                                        * Referenced by: '<S409>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S409>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S409>/Constant5'
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
                                        *   '<S409>/Constant11'
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
 *    '<S130>/If Action Subsystem1'
 *    '<S130>/If Action Subsystem3'
 */
void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S163>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S130>/If Action Subsystem1'
 *    '<S130>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  boolean_T rtb_Compare_pp;

  /* RelationalOperator: '<S168>/Compare' incorporates:
   *  Constant: '<S163>/Constant1'
   *  Constant: '<S168>/Constant'
   *  Sum: '<S163>/Sum'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  rtb_Compare_pp = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S163>/Logical Operator' incorporates:
   *  Logic: '<S163>/NOT'
   */
  *rty_IsBlueActive = ((!rtu_IsBlueInactiveFirst) || rtb_Compare_pp);

  /* Logic: '<S163>/Logical Operator1' */
  *rty_IsRedActive = (rtu_IsBlueInactiveFirst || rtb_Compare_pp);

  /* SignalConversion: '<S163>/Signal Copy' incorporates:
   *  Constant: '<S163>/Constant1'
   *  Sum: '<S163>/Sum'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S163>/Unit Delay' incorporates:
   *  Constant: '<S163>/Constant1'
   *  Sum: '<S163>/Sum'
   */
  localDW->UnitDelay_DSTATE -= 0.02;
}

/*
 * System initialize for action system:
 *    '<S130>/If Action Subsystem2'
 *    '<S130>/If Action Subsystem4'
 */
void Robot_C_IfActionSubsystem2_Init(DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S164>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S130>/If Action Subsystem2'
 *    '<S130>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  boolean_T rtb_Compare_cb;

  /* RelationalOperator: '<S169>/Compare' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Constant: '<S169>/Constant'
   *  Sum: '<S164>/Sum'
   *  UnitDelay: '<S164>/Unit Delay'
   */
  rtb_Compare_cb = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S164>/Logical Operator' */
  *rty_IsBlueActive = (rtu_IsBlueInactiveFirst || rtb_Compare_cb);

  /* Logic: '<S164>/Logical Operator1' incorporates:
   *  Logic: '<S164>/NOT1'
   */
  *rty_IsRedActive = ((!rtu_IsBlueInactiveFirst) || rtb_Compare_cb);

  /* SignalConversion: '<S164>/Signal Copy' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Sum: '<S164>/Sum'
   *  UnitDelay: '<S164>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S164>/Unit Delay' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Sum: '<S164>/Sum'
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
  real_T rtb_Add_ec;
  real_T rtb_Add_ir;
  real_T rtb_Add_os;
  real_T rtb_Add_oy;
  real_T rtb_DeadZone;
  real_T rtb_Error_c5;
  real_T rtb_Error_n;
  real_T rtb_Hypot_bl;
  real_T rtb_Init;
  real_T rtb_Init_o;
  real_T rtb_Integral_bj;
  real_T rtb_Integral_d;
  real_T rtb_Integral_ga;
  real_T rtb_LookupTableDynamic_b;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_MatrixConcatenate_idx_0;
  real_T rtb_Merge1;
  real_T rtb_Minus_k_idx_1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_hm;
  real_T rtb_Product_i;
  real_T rtb_Product_lf;
  real_T rtb_Product_lo;
  real_T rtb_Product_ov;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_la;
  real_T rtb_Sum1;
  real_T rtb_Sum1_dj;
  real_T rtb_Sum1_fh;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1;
  real_T rtb_Switch1_h;
  real_T rtb_Switch1_hb;
  real_T rtb_Switch1_m;
  real_T rtb_Switch2;
  real_T rtb_Switch2_ee;
  real_T rtb_Switch2_i;
  real_T rtb_Switch2_o;
  real_T rtb_Switch2_p2;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s217_iter;
  uint16_T s242_iter;
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

  /* Switch: '<S41>/Init' incorporates:
   *  UnitDelay: '<S41>/FixPt Unit Delay1'
   *  UnitDelay: '<S41>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_o = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S41>/Init' */

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/Constant2'
   *  Constant: '<S36>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Sin4 = Rate_Limit_X;
  } else {
    rtb_Sin4 = 1000.0;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Sum: '<S39>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Init_o;

  /* Switch: '<S40>/Switch2' incorporates:
   *  RelationalOperator: '<S40>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Sin4)) {
    /* Switch: '<S36>/Switch1' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant3'
     *  UnaryMinus: '<S36>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_hb = -Rate_Limit_X;
    } else {
      rtb_Switch1_hb = -1000.0;
    }

    /* End of Switch: '<S36>/Switch1' */

    /* Switch: '<S40>/Switch' incorporates:
     *  RelationalOperator: '<S40>/UpperRelop'
     */
    if (rtb_Sum1 < rtb_Switch1_hb) {
      rtb_Sin4 = rtb_Switch1_hb;
    } else {
      rtb_Sin4 = rtb_Sum1;
    }

    /* End of Switch: '<S40>/Switch' */
  }

  /* End of Switch: '<S40>/Switch2' */

  /* Sum: '<S39>/Sum' */
  rtb_Sum1 = rtb_Sin4 + rtb_Init_o;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S44>/Init' incorporates:
   *  UnitDelay: '<S44>/FixPt Unit Delay1'
   *  UnitDelay: '<S44>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_j != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_a;
  }

  /* End of Switch: '<S44>/Init' */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Constant: '<S37>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Y;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Sum: '<S42>/Sum1' */
  rtb_Switch1_hb = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Sin4;

  /* Switch: '<S43>/Switch2' incorporates:
   *  RelationalOperator: '<S43>/LowerRelop1'
   */
  if (!(rtb_Switch1_hb > rtb_Init_o)) {
    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant'
     *  Constant: '<S37>/Constant3'
     *  UnaryMinus: '<S37>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_h = -Rate_Limit_Y;
    } else {
      rtb_Switch1_h = -1000.0;
    }

    /* End of Switch: '<S37>/Switch1' */

    /* Switch: '<S43>/Switch' incorporates:
     *  RelationalOperator: '<S43>/UpperRelop'
     */
    if (rtb_Switch1_hb < rtb_Switch1_h) {
      rtb_Init_o = rtb_Switch1_h;
    } else {
      rtb_Init_o = rtb_Switch1_hb;
    }

    /* End of Switch: '<S43>/Switch' */
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Sum: '<S42>/Sum' */
  rtb_Switch1_hb = rtb_Init_o + rtb_Sin4;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S47>/Init' incorporates:
   *  UnitDelay: '<S47>/FixPt Unit Delay1'
   *  UnitDelay: '<S47>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S47>/Init' */

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Constant: '<S38>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Z;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Sum: '<S45>/Sum1' */
  rtb_Switch1_h = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Sin4;

  /* Switch: '<S46>/Switch2' incorporates:
   *  RelationalOperator: '<S46>/LowerRelop1'
   */
  if (!(rtb_Switch1_h > rtb_Init_o)) {
    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S38>/Constant'
     *  Constant: '<S38>/Constant3'
     *  UnaryMinus: '<S38>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_m = -Rate_Limit_Z;
    } else {
      rtb_Switch1_m = -1000.0;
    }

    /* End of Switch: '<S38>/Switch1' */

    /* Switch: '<S46>/Switch' incorporates:
     *  RelationalOperator: '<S46>/UpperRelop'
     */
    if (rtb_Switch1_h < rtb_Switch1_m) {
      rtb_Init_o = rtb_Switch1_m;
    } else {
      rtb_Init_o = rtb_Switch1_h;
    }

    /* End of Switch: '<S46>/Switch' */
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Sum: '<S45>/Sum' */
  rtb_Switch1_h = rtb_Init_o + rtb_Sin4;

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

  /* If: '<S438>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S438>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S441>/Action Port'
     */
    /* Product: '<S441>/Product' incorporates:
     *  Constant: '<S441>/Constant1'
     *  Constant: '<S441>/Constant2'
     *  Math: '<S441>/Math Function'
     */
    rtb_Sin4 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495) *
      111.0;

    /* End of Outputs for SubSystem: '<S438>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S438>/Subsystem' incorporates:
     *  ActionPort: '<S442>/Action Port'
     */
    /* SignalConversion generated from: '<S442>/Out1' incorporates:
     *  Constant: '<S442>/Constant'
     */
    rtb_Sin4 = 0.0;

    /* End of Outputs for SubSystem: '<S438>/Subsystem' */
  }

  /* End of If: '<S438>/If' */

  /* Gain: '<S439>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Init_o = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S440>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Sin4 * cos(rtb_Init_o)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S440>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Sin4 * sin(rtb_Init_o)) +
    Vision_Object_Y_Offset;

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
  rtb_Add_oy = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_oy)) || (rtIsInf(rtb_Add_oy))) {
    rtb_Add_oy = 0.0;
  } else {
    rtb_Add_oy = fmod(rtb_Add_oy, 4.294967296E+9);
  }

  switch ((rtb_Add_oy < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_oy)))) :
          ((int32_T)((uint32_T)rtb_Add_oy))) {
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
      rtb_Switch1_m = 10.0;
    } else if (Robot_Control_DW.UnitDelay2_DSTATE < 1.0) {
      rtb_Switch1_m = 1.0;
    } else {
      rtb_Switch1_m = Robot_Control_DW.UnitDelay2_DSTATE;
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
      rtb_Init_o = 0.0;
    } else {
      rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
    }

    /* End of Switch: '<S19>/Switch1' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     */
    if (rtb_Swerve_Motors_Disabled) {
      rtb_Shooter_Active_prev = (rtb_Init_o >= Auto_Shoot_Time);
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
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 39];
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
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        }
        break;

       case Robot_Control_IN_Follow_Path:
        if (Robot_Control_DW.UnitDelay_DSTATE_ll) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_End_Action;
          Robot_Control_B.Auto_Spline_Enable = false;
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        } else if (rtb_Switch1_m > Robot_Control_DW.UnitDelay_DSTATE_e3) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 49];
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
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 49];
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
      rtb_Add_oy = Robot_Control_B.Auto_Desired_Static_Action;
    } else {
      rtb_Add_oy = Robot_Control_B.Auto_Desired_Dynamic_Action;
    }

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     *  Switch: '<S22>/Switch'
     */
    switch ((int32_T)rtb_Add_oy) {
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
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Init_o;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Switch1_m;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S411>/Unit Delay1'
       *  UnitDelay: '<S411>/Unit Delay2'
       *  UnitDelay: '<S411>/Unit Delay3'
       *  UnitDelay: '<S411>/Unit Delay4'
       *  UnitDelay: '<S414>/Delay Input1'
       *  UnitDelay: '<S415>/Delay Input1'
       *  UnitDelay: '<S416>/Delay Input1'
       *  UnitDelay: '<S417>/Delay Input1'
       *  UnitDelay: '<S419>/Delay Input1'
       *  UnitDelay: '<S425>/Unit Delay'
       *  UnitDelay: '<S425>/Unit Delay1'
       *  UnitDelay: '<S429>/FixPt Unit Delay1'
       *  UnitDelay: '<S429>/FixPt Unit Delay2'
       *
       * Block description for '<S414>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S415>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S416>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S417>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S419>/Delay Input1':
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

    /* Switch: '<S409>/Switch4' incorporates:
     *  Constant: '<S434>/Constant'
     *  Constant: '<S437>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S434>/Compare'
     *  RelationalOperator: '<S437>/Compare'
     *  Switch: '<S409>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S409>/Switch4' incorporates:
       *  Constant: '<S409>/Constant8'
       *  Sum: '<S409>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S409>/Switch5' incorporates:
       *  Constant: '<S409>/Constant7'
       *  Gain: '<S409>/Gain'
       *  Sum: '<S409>/Subtract5'
       *  Switch: '<S409>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S409>/Switch4' incorporates:
       *  Constant: '<S409>/Constant6'
       *  Switch: '<S409>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S409>/Switch4' */

    /* Logic: '<S409>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S409>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S411>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_oy = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_oy = 0.0;
    } else {
      rtb_Add_oy = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S411>/Add' incorporates:
     *  Constant: '<S411>/Constant'
     *  Constant: '<S411>/Constant1'
     *  DeadZone: '<S411>/Dead Zone'
     *  Lookup_n-D: '<S411>/Modulation_Str_Y_Rel'
     *  Product: '<S411>/Product'
     *  Product: '<S411>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Add_oy * Steering_Twist_Gain);

    /* RelationalOperator: '<S413>/Compare' incorporates:
     *  Constant: '<S413>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Switch1_m == 0.0);

    /* Logic: '<S411>/AND2' incorporates:
     *  RelationalOperator: '<S414>/FixPt Relational Operator'
     *  RelationalOperator: '<S415>/FixPt Relational Operator'
     *  RelationalOperator: '<S416>/FixPt Relational Operator'
     *  RelationalOperator: '<S417>/FixPt Relational Operator'
     *  UnitDelay: '<S414>/Delay Input1'
     *  UnitDelay: '<S415>/Delay Input1'
     *  UnitDelay: '<S416>/Delay Input1'
     *  UnitDelay: '<S417>/Delay Input1'
     *
     * Block description for '<S414>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S415>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S416>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S417>/Delay Input1':
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

    /* Logic: '<S411>/AND1' incorporates:
     *  Logic: '<S411>/AND3'
     *  UnitDelay: '<S411>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Swerve_Motors_Disabled && (rtb_LogicalOperator1_n ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S411>/AND4' incorporates:
     *  Logic: '<S411>/AND8'
     *  UnitDelay: '<S411>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Swerve_Motors_Disabled && (!rtb_LogicalOperator1_n)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S411>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S411>/Switch8' incorporates:
     *  Constant: '<S420>/Constant'
     *  Logic: '<S411>/AND9'
     *  RelationalOperator: '<S419>/FixPt Relational Operator'
     *  RelationalOperator: '<S420>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S419>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S419>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Swerve_Motors_Disabled) > ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_j))) ||
         (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S411>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S411>/Switch8' incorporates:
       *  UnitDelay: '<S411>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S411>/Switch8' */

    /* Switch: '<S411>/Switch4' incorporates:
     *  Constant: '<S411>/Constant5'
     *  Switch: '<S411>/Switch1'
     *  Switch: '<S411>/Switch5'
     *  Switch: '<S411>/Switch6'
     *  Switch: '<S411>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Init_o = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S411>/Switch5' incorporates:
       *  Constant: '<S411>/Constant6'
       */
      rtb_Init_o = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S411>/Switch6' incorporates:
       *  Constant: '<S411>/Constant7'
       *  Switch: '<S411>/Switch5'
       */
      rtb_Init_o = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S411>/Switch7' incorporates:
       *  Constant: '<S411>/Constant8'
       *  Switch: '<S411>/Switch5'
       *  Switch: '<S411>/Switch6'
       */
      rtb_Init_o = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S411>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S411>/Switch5'
       *  Switch: '<S411>/Switch6'
       *  Switch: '<S411>/Switch7'
       */
      rtb_Init_o = 0.0;
    } else {
      /* Switch: '<S411>/Switch6' incorporates:
       *  Switch: '<S411>/Switch5'
       *  Switch: '<S411>/Switch7'
       *  UnitDelay: '<S411>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S411>/Switch4' */

    /* Switch: '<S411>/Switch2' incorporates:
     *  Switch: '<S411>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S411>/Switch2' incorporates:
       *  Constant: '<S411>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S411>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Init_o;
    } else {
      /* Switch: '<S411>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S411>/Switch3' incorporates:
       *  Constant: '<S411>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S411>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S411>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S410>/Switch1' incorporates:
     *  Constant: '<S410>/Constant5'
     *  Constant: '<S410>/Constant8'
     *  DataTypeConversion: '<S410>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Swerve_Motors_Disabled;
    }

    /* End of Switch: '<S410>/Switch1' */

    /* Lookup_n-D: '<S412>/Modulation_Drv' incorporates:
     *  Math: '<S412>/Magnitude'
     */
    rtb_Sin4 = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S423>/Compare' incorporates:
     *  Constant: '<S423>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Sin4 == 0.0);

    /* DeadZone: '<S412>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_DeadZone = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S412>/Dead Zone' */

    /* Logic: '<S412>/Logical Operator' incorporates:
     *  Constant: '<S424>/Constant'
     *  RelationalOperator: '<S424>/Compare'
     */
    rtb_LogicalOperator1_n = ((rtb_DeadZone != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S410>/Switch' incorporates:
     *  Constant: '<S410>/Constant5'
     *  Constant: '<S410>/Constant7'
     *  DataTypeConversion: '<S410>/Data Type Conversion'
     *  Logic: '<S412>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_LogicalOperator1_n;
    }

    /* End of Switch: '<S410>/Switch' */

    /* Switch: '<S409>/Switch2' incorporates:
     *  Constant: '<S409>/Constant2'
     *  Constant: '<S433>/Constant'
     *  Constant: '<S436>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S433>/Compare'
     *  RelationalOperator: '<S436>/Compare'
     *  Sum: '<S409>/Subtract'
     *  Switch: '<S409>/Switch'
     *  Switch: '<S409>/Switch1'
     *  Switch: '<S409>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S409>/Switch2' incorporates:
       *  Constant: '<S409>/Constant5'
       *  Sum: '<S409>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S409>/Switch2' incorporates:
       *  Constant: '<S409>/Constant4'
       *  Sum: '<S409>/Subtract2'
       *  Switch: '<S409>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S409>/Switch1' incorporates:
       *  Constant: '<S409>/Constant1'
       *  Sum: '<S409>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S409>/Switch2' incorporates:
       *  Constant: '<S409>/Constant3'
       *  Switch: '<S409>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S409>/Switch1' incorporates:
       *  Constant: '<S409>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S409>/Switch2' */

    /* UnaryMinus: '<S409>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S425>/Switch1' incorporates:
     *  Constant: '<S430>/Constant'
     *  Constant: '<S431>/Constant'
     *  Logic: '<S425>/AND'
     *  RelationalOperator: '<S430>/Compare'
     *  RelationalOperator: '<S431>/Compare'
     *  Switch: '<S425>/Switch2'
     *  UnitDelay: '<S425>/Unit Delay'
     *  UnitDelay: '<S425>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = rtb_Switch1_hb;
      rtb_Switch2 = rtb_Sum1;
    }

    /* End of Switch: '<S425>/Switch1' */

    /* Switch: '<S412>/Switch1' incorporates:
     *  Logic: '<S412>/Logical Operator1'
     *  Switch: '<S412>/Switch4'
     *  Switch: '<S412>/Switch9'
     */
    if (rtb_LogicalOperator1_n) {
      /* Signum: '<S412>/Sign' */
      if (rtIsNaN(rtb_DeadZone)) {
        rtb_Add_oy = (rtNaN);
      } else if (rtb_DeadZone < 0.0) {
        rtb_Add_oy = -1.0;
      } else {
        rtb_Add_oy = (rtb_DeadZone > 0.0);
      }

      /* Switch: '<S412>/Switch5' incorporates:
       *  Constant: '<S412>/Constant3'
       *  Constant: '<S412>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S412>/Gain3'
       *  Signum: '<S412>/Sign'
       *  Sum: '<S412>/Add'
       *  Switch: '<S412>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_oy) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S412>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S412>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S412>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S412>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S412>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S412>/Switch4'
       *  Trigonometry: '<S412>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S412>/Switch1' */

    /* Switch: '<S422>/Switch1' incorporates:
     *  Constant: '<S422>/Constant'
     *  Constant: '<S422>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S422>/Switch1' */

    /* Switch: '<S429>/Init' incorporates:
     *  UnitDelay: '<S429>/FixPt Unit Delay1'
     *  UnitDelay: '<S429>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S429>/Init' */

    /* Sum: '<S427>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S428>/Switch2' incorporates:
     *  Constant: '<S426>/Constant1'
     *  Constant: '<S426>/Constant3'
     *  RelationalOperator: '<S428>/LowerRelop1'
     *  RelationalOperator: '<S428>/UpperRelop'
     *  Switch: '<S428>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S428>/Switch' incorporates:
       *  Constant: '<S426>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S428>/Switch2' */

    /* Sum: '<S427>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S412>/Switch8' incorporates:
     *  Logic: '<S412>/Logical Operator1'
     *  Switch: '<S412>/Switch2'
     */
    if (rtb_LogicalOperator1_n) {
      /* Switch: '<S412>/Switch' incorporates:
       *  Gain: '<S412>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_DeadZone;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S412>/Constant5'
       *  Gain: '<S412>/Gain2'
       *  Math: '<S412>/Magnitude1'
       *  MinMax: '<S412>/Min'
       *  Switch: '<S412>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S422>/Product' incorporates:
       *  Switch: '<S412>/Switch2'
       */
      rtb_Add_oy = rtb_Sin4 * rtb_Init;

      /* Saturate: '<S422>/Saturation' incorporates:
       *  Switch: '<S412>/Switch2'
       */
      if (rtb_Add_oy > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_oy < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_oy;
      }

      /* End of Saturate: '<S422>/Saturation' */
    }

    /* End of Switch: '<S412>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S411>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S409>/Constant11'
     *  Switch: '<S409>/Switch6'
     *  Switch: '<S409>/Switch7'
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

    /* RelationalOperator: '<S406>/Compare' incorporates:
     *  Constant: '<S406>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S407>/Compare' incorporates:
     *  Constant: '<S407>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S402>/Compare' incorporates:
     *  Constant: '<S402>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S405>/Compare' incorporates:
     *  Constant: '<S405>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S404>/Compare' incorporates:
     *  Constant: '<S404>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Shooter_Active_prev = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S403>/Compare' incorporates:
     *  Constant: '<S403>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     *  SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Update for UnitDelay: '<S419>/Delay Input1'
     *
     * Block description for '<S419>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Swerve_Motors_Disabled;

    /* Update for UnitDelay: '<S418>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S418>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S414>/Delay Input1'
     *
     * Block description for '<S414>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S415>/Delay Input1'
     *
     * Block description for '<S415>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S416>/Delay Input1'
     *
     * Block description for '<S416>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S417>/Delay Input1'
     *
     * Block description for '<S417>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S411>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S411>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S411>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S411>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Init_o;

    /* Update for UnitDelay: '<S425>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1;

    /* Update for UnitDelay: '<S425>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S429>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S429>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S429>/FixPt Unit Delay1' */
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

  /* Reshape: '<S70>/Reshapey' incorporates:
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

  /* Delay: '<S70>/MemoryX' incorporates:
   *  Constant: '<S70>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S97>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S123>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S90>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S121>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S121>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S70>/C'
     *  Delay: '<S70>/MemoryX'
     *  Product: '<S123>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Init_o;

    /* Sum: '<S121>/Sum' incorporates:
     *  Constant: '<S70>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S121>/C[k]*xhat[k|k-1]'
     *  Product: '<S121>/D[k]*u[k]'
     *  Sum: '<S121>/Add1'
     */
    rtb_Sin4 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Switch1_m = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Init_o);

    /* Product: '<S121>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S70>/C'
     *  Delay: '<S70>/MemoryX'
     *  Product: '<S123>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Init_o;

    /* Sum: '<S121>/Sum' incorporates:
     *  Constant: '<S70>/D'
     *  Product: '<S121>/C[k]*xhat[k|k-1]'
     *  Product: '<S121>/D[k]*u[k]'
     *  Sum: '<S121>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Init_o);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S121>/Product3' incorporates:
     *  Constant: '<S71>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Switch1_m) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S123>/Add1' incorporates:
     *  Product: '<S123>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S121>/Product3' incorporates:
     *  Constant: '<S71>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Switch1_m) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S123>/Add1' incorporates:
     *  Product: '<S123>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S123>/Product2' incorporates:
     *  Constant: '<S71>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S121>/Product3' incorporates:
       *  Outport: '<S121>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S123>/Product2' incorporates:
       *  Outport: '<S123>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S90>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S97>/Enabled Subsystem' */

  /* Sum: '<S97>/Add' incorporates:
   *  Delay: '<S70>/MemoryX'
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
   *  Constant: '<S242>/Constant'
   *  Logic: '<S242>/AND'
   *  MATLAB Function: '<S192>/Find closest index to curve'
   *  Product: '<S242>/Product'
   *  RelationalOperator: '<S242>/Relational Operator'
   *  RelationalOperator: '<S242>/Relational Operator1'
   *  Selector: '<S242>/Selector'
   *  Selector: '<S242>/Selector1'
   *  Selector: '<S243>/Selector'
   *  Sum: '<S242>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S195>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_hk == 0) {
      /* Disable for If: '<S198>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S200>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_hk = -1;

    /* End of Disable for If: '<S195>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S190>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S190>/Unit Delay'
       *  UnitDelay: '<S191>/Unit Delay'
       *  UnitDelay: '<S193>/Unit Delay'
       *  UnitDelay: '<S193>/Unit Delay1'
       *  UnitDelay: '<S243>/Unit Delay'
       *  UnitDelay: '<S243>/Unit Delay1'
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
     *  ActionPort: '<S190>/Action Port'
     */
    /* Selector: '<S191>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S191>/Selector1' */

    /* Lookup_n-D: '<S190>/Capture Radius' incorporates:
     *  UnitDelay: '<S190>/Unit Delay'
     */
    rtb_Switch1_m = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S191>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S191>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S195>/If' incorporates:
     *  RelationalOperator: '<S195>/ '
     *  UnitDelay: '<S191>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_hk;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_hk = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S198>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S200>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S195>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S198>/Action Port'
       */
      /* InitializeConditions for If: '<S195>/If' incorporates:
       *  UnitDelay: '<S198>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S195>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S195>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S198>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S198>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      /* If: '<S198>/If' incorporates:
       *  Selector: '<S191>/Selector1'
       *  Selector: '<S198>/Selector'
       *  Selector: '<S201>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S198>/Increment_If_Rectangle_Check' */

      /* Sum: '<S198>/Minus' incorporates:
       *  Concatenate: '<S191>/Matrix Concatenate2'
       *  Selector: '<S198>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S198>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      /* If: '<S198>/If' incorporates:
       *  Selector: '<S191>/Selector1'
       *  Selector: '<S198>/Selector'
       *  Selector: '<S201>/Selector'
       *  Sum: '<S198>/Minus'
       */
      rtb_DeadZone = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S198>/Increment_If_Rectangle_Check' */

      /* Sum: '<S198>/Minus' incorporates:
       *  Concatenate: '<S191>/Matrix Concatenate2'
       *  Selector: '<S198>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_DeadZone;

      /* Math: '<S198>/Hypot' */
      rtb_Init_o = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S198>/Equal' */
      rtb_Is_Absolute_Steering = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S198>/Switch' incorporates:
       *  Logic: '<S198>/AND'
       *  Logic: '<S198>/OR'
       *  RelationalOperator: '<S198>/Relational Operator'
       *  UnitDelay: '<S198>/Unit Delay'
       */
      rtb_Is_Absolute_Translation_g = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Init_o <= rtb_Switch1_m) && rtb_Is_Absolute_Steering));

      /* If: '<S198>/If' */
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
        /* Disable for If: '<S200>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S198>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S200>/Action Port'
         */
        /* If: '<S200>/If' incorporates:
         *  RelationalOperator: '<S200>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S200>/Is_Last_Point' incorporates:
           *  ActionPort: '<S203>/Action Port'
           */
          /* InitializeConditions for If: '<S200>/If' incorporates:
           *  UnitDelay: '<S203>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S200>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S200>/Is_Last_Point' incorporates:
           *  ActionPort: '<S203>/Action Port'
           */
          /* Switch: '<S203>/Switch' incorporates:
           *  Constant: '<S205>/Constant'
           *  Logic: '<S203>/OR'
           *  RelationalOperator: '<S205>/Compare'
           *  UnitDelay: '<S203>/Unit Delay'
           */
          rtb_AND1_c = ((Robot_Control_DW.UnitDelay_DSTATE_nu) || (rtb_Init_o <=
            Spline_Stop_Radius));

          /* If: '<S203>/If' */
          if (rtb_AND1_c) {
            /* Outputs for IfAction SubSystem: '<S203>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S206>/Action Port'
             */
            /* Merge: '<S195>/Merge2' incorporates:
             *  Constant: '<S206>/Constant'
             *  SignalConversion generated from: '<S206>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = true;

            /* SignalConversion generated from: '<S206>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S206>/Constant1'
             */
            rtb_Swerve_Motors_Disabled = false;

            /* End of Outputs for SubSystem: '<S203>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S203>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S207>/Action Port'
             */
            /* Merge: '<S195>/Merge2' incorporates:
             *  Constant: '<S207>/Constant'
             *  SignalConversion generated from: '<S207>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = false;

            /* SignalConversion generated from: '<S207>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S207>/Constant1'
             */
            rtb_Swerve_Motors_Disabled = true;

            /* End of Outputs for SubSystem: '<S203>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S203>/If' */

          /* Merge: '<S195>/Merge4' incorporates:
           *  SignalConversion: '<S203>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S203>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_AND1_c;

          /* End of Outputs for SubSystem: '<S200>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S200>/Increment_Search' incorporates:
           *  ActionPort: '<S202>/Action Port'
           */
          /* Merge: '<S195>/Merge2' incorporates:
           *  Constant: '<S202>/Constant'
           *  SignalConversion generated from: '<S202>/Robot_Reached_Destination'
           */
          rtb_Is_Absolute_Steering = false;

          /* SignalConversion generated from: '<S202>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S202>/Constant1'
           */
          rtb_Swerve_Motors_Disabled = false;

          /* Merge: '<S195>/Merge4' incorporates:
           *  Constant: '<S204>/FixPt Constant'
           *  SignalConversion: '<S202>/Signal Copy'
           *  Sum: '<S204>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S200>/Increment_Search' */
        }

        /* End of If: '<S200>/If' */
        /* End of Outputs for SubSystem: '<S198>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S198>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S201>/Action Port'
         */
        /* Sum: '<S208>/FixPt Sum1' incorporates:
         *  Constant: '<S208>/FixPt Constant'
         */
        rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S201>/Selector1' incorporates:
         *  Selector: '<S191>/Selector1'
         */
        rtb_Switch2_p2 = rtb_Ref_Poses[((int32_T)rtb_Init_o) - 1];

        /* Sum: '<S209>/Subtract' incorporates:
         *  Selector: '<S201>/Selector1'
         *  Sum: '<S209>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_p2 - rtb_Init;

        /* Selector: '<S201>/Selector1' incorporates:
         *  Selector: '<S191>/Selector1'
         */
        rtb_Switch1 = rtb_Ref_Poses[((int32_T)rtb_Init_o) + 9];

        /* Sum: '<S209>/Subtract' incorporates:
         *  Selector: '<S201>/Selector1'
         *  Sum: '<S209>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1 - rtb_DeadZone;

        /* Math: '<S209>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S209>/Divide' */
        rtb_Init_o = rtb_Minus_n[1];

        /* UnaryMinus: '<S209>/Unary Minus' */
        rtb_Switch2_o = rtb_Minus_n[0];

        /* Product: '<S209>/Product' incorporates:
         *  Product: '<S209>/Divide'
         *  UnaryMinus: '<S209>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Init_o / rtb_Sin4) * rtb_Switch1_m;
        rtb_Minus_n[1] = ((-rtb_Switch2_o) / rtb_Sin4) * rtb_Switch1_m;

        /* Sum: '<S209>/Add1' incorporates:
         *  Sum: '<S209>/Add2'
         *  Sum: '<S209>/Minus'
         */
        rtb_Switch2_o = rtb_Switch2_p2 - rtb_Minus_n[0];

        /* Sum: '<S209>/Minus4' incorporates:
         *  Sum: '<S209>/Add2'
         *  Sum: '<S209>/Minus'
         */
        rtb_Switch2_p2 = (rtb_Switch2_p2 + rtb_Minus_n[0]) - rtb_Switch2_o;

        /* Sum: '<S209>/Minus5' incorporates:
         *  Concatenate: '<S191>/Matrix Concatenate2'
         *  Sum: '<S209>/Minus'
         */
        rtb_Switch2 = rtb_Reshapey[0] - rtb_Switch2_o;

        /* Sum: '<S209>/Add' incorporates:
         *  Sum: '<S209>/Add2'
         *  Sum: '<S209>/Minus1'
         */
        rtb_Init_o = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S209>/Minus' incorporates:
         *  Sum: '<S209>/Minus1'
         */
        rtb_Switch2_o -= rtb_Init_o;

        /* DotProduct: '<S209>/Dot Product' incorporates:
         *  Concatenate: '<S191>/Matrix Concatenate2'
         *  Sum: '<S209>/Minus'
         *  Sum: '<S209>/Minus1'
         *  Sum: '<S209>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Init_o) * rtb_Switch2_o;

        /* DotProduct: '<S209>/Dot Product1' incorporates:
         *  Sum: '<S209>/Minus'
         */
        rtb_Init = rtb_Switch2_o * rtb_Switch2_o;

        /* DotProduct: '<S209>/Dot Product2' incorporates:
         *  Sum: '<S209>/Minus4'
         *  Sum: '<S209>/Minus5'
         */
        rtb_Minus_k_idx_1 = rtb_Switch2_p2 * rtb_Switch2;

        /* DotProduct: '<S209>/Dot Product3' incorporates:
         *  Sum: '<S209>/Minus4'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2 * rtb_Switch2_p2;

        /* Sum: '<S209>/Add1' incorporates:
         *  Sum: '<S209>/Add2'
         *  Sum: '<S209>/Minus'
         */
        rtb_Switch2_o = rtb_Switch1 - rtb_Minus_n[1];

        /* Sum: '<S209>/Minus4' incorporates:
         *  Sum: '<S209>/Add2'
         *  Sum: '<S209>/Minus'
         */
        rtb_Switch2_p2 = (rtb_Switch1 + rtb_Minus_n[1]) - rtb_Switch2_o;

        /* Sum: '<S209>/Minus5' incorporates:
         *  Concatenate: '<S191>/Matrix Concatenate2'
         *  Sum: '<S209>/Minus'
         */
        rtb_Switch2 = rtb_Reshapey[1] - rtb_Switch2_o;

        /* Sum: '<S209>/Add' incorporates:
         *  Sum: '<S209>/Add2'
         *  Sum: '<S209>/Minus1'
         */
        rtb_Init_o = rtb_DeadZone - rtb_Minus_n[1];

        /* Sum: '<S209>/Minus' incorporates:
         *  Sum: '<S209>/Minus1'
         */
        rtb_Switch2_o -= rtb_Init_o;

        /* DotProduct: '<S209>/Dot Product' incorporates:
         *  Concatenate: '<S191>/Matrix Concatenate2'
         *  Sum: '<S209>/Minus'
         *  Sum: '<S209>/Minus1'
         *  Sum: '<S209>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Init_o) * rtb_Switch2_o;

        /* RelationalOperator: '<S210>/Compare' incorporates:
         *  Constant: '<S210>/Constant'
         */
        rtb_Is_Absolute_Steering = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S209>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S209>/Dot Product1'
         *  Sum: '<S209>/Minus'
         */
        rtb_Swerve_Motors_Disabled = (rtb_Sin4 <= ((rtb_Switch2_o *
          rtb_Switch2_o) + rtb_Init));

        /* DotProduct: '<S209>/Dot Product2' incorporates:
         *  Sum: '<S209>/Minus4'
         *  Sum: '<S209>/Minus5'
         */
        rtb_Sin4 = (rtb_Switch2_p2 * rtb_Switch2) + rtb_Minus_k_idx_1;

        /* Merge: '<S195>/Merge4' incorporates:
         *  Constant: '<S211>/Constant'
         *  DataTypeConversion: '<S201>/Data Type Conversion'
         *  DotProduct: '<S209>/Dot Product3'
         *  Logic: '<S209>/AND'
         *  RelationalOperator: '<S209>/LessThanOrEqual1'
         *  RelationalOperator: '<S211>/Compare'
         *  Sum: '<S201>/Add'
         *  Sum: '<S209>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)
          (((rtb_Is_Absolute_Steering && rtb_Swerve_Motors_Disabled) &&
            (rtb_Sin4 >= 0.0)) && (rtb_Sin4 <= ((rtb_Switch2_p2 * rtb_Switch2_p2)
          + rtb_MatrixConcatenate_b_idx_0)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S195>/Merge2' incorporates:
         *  Constant: '<S201>/Constant2'
         *  SignalConversion generated from: '<S201>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S201>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S201>/Constant1'
         */
        rtb_Swerve_Motors_Disabled = false;

        /* End of Outputs for SubSystem: '<S198>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S198>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S199>/Action Port'
         */
        /* Merge: '<S195>/Merge2' incorporates:
         *  Constant: '<S199>/Constant2'
         *  SignalConversion generated from: '<S199>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S199>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S199>/Constant1'
         */
        rtb_Swerve_Motors_Disabled = false;

        /* Merge: '<S195>/Merge4' incorporates:
         *  SignalConversion generated from: '<S199>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S198>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S195>/Merge1' incorporates:
       *  Constant: '<S198>/Constant'
       *  SignalConversion generated from: '<S198>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S198>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_Is_Absolute_Translation_g;

      /* End of Outputs for SubSystem: '<S195>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S195>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S197>/Action Port'
       */
      /* Merge: '<S195>/Merge1' incorporates:
       *  Constant: '<S197>/Constant'
       *  SignalConversion generated from: '<S197>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S195>/Merge2' incorporates:
       *  Constant: '<S197>/Constant1'
       *  SignalConversion generated from: '<S197>/Robot_Reached_Destination'
       */
      rtb_Is_Absolute_Steering = false;

      /* SignalConversion generated from: '<S197>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S197>/Constant2'
       */
      rtb_Swerve_Motors_Disabled = false;

      /* Merge: '<S195>/Merge4' incorporates:
       *  SignalConversion generated from: '<S197>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S195>/Escape_Auto_Driving' */
    }

    /* End of If: '<S195>/If' */

    /* If: '<S191>/If1' */
    if (!rtb_Swerve_Motors_Disabled) {
      /* Outputs for IfAction SubSystem: '<S191>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S196>/Action Port'
       */
      /* Bias: '<S212>/Add Constant' incorporates:
       *  Bias: '<S212>/Bias'
       *  Sum: '<S212>/Subtract'
       */
      rtb_Init_o = ((Robot_Control_B.Spline_Num_Poses -
                     Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S212>/Selector4' incorporates:
       *  Bias: '<S212>/Bias1'
       *  Constant: '<S214>/FixPt Constant'
       *  Sum: '<S214>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S212>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S212>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s217_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S212>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S212>/Selector5' incorporates:
       *  Concatenate: '<S212>/Matrix Concatenate'
       *  Gain: '<S216>/Gain'
       *  Selector: '<S191>/Selector1'
       *  Selector: '<S212>/Selector2'
       *  Selector: '<S212>/Selector3'
       *  Sum: '<S216>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s217_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S212>/Matrix Concatenate' incorporates:
       *  Bias: '<S212>/Add Constant1'
       *  Gain: '<S215>/Gain'
       *  Selector: '<S191>/Selector1'
       *  Selector: '<S212>/Selector'
       *  Selector: '<S212>/Selector1'
       *  Selector: '<S212>/Selector5'
       *  Sum: '<S215>/Subtract'
       */
      s217_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s217_iter;
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

      /* Selector: '<S212>/Selector4' */
      s217_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s217_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S212>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S212>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S212>/Assignment' incorporates:
       *  Concatenate: '<S212>/Matrix Concatenate'
       *  Selector: '<S212>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s217_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S213>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S217>/While Iterator'
       */
      s217_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s217_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s217_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s217_iter] - rtb_Assignment[s217_iter + 2];
        rtb_Switch2_p2 = rtb_Init - rtb_Assignment[s217_iter];
        rtb_Init = rtb_Assignment[s217_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s217_iter + 11];
        rtb_Switch2_o = rtb_Assignment[s217_iter + 12];
        rtb_Add2[1] = rtb_Switch2_o - rtb_Assignment[s217_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Init - rtb_Switch2_o;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Sin4 = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_DeadZone = rt_powd_snf(rtb_Sin4, 2.0);
          rtb_Init = rt_powd_snf(rtb_Sin4, 3.0);
          rtb_Switch1 = (rtb_Sin4 - (2.0 * rtb_DeadZone)) + rtb_Init;
          rtb_Switch2 = rtb_DeadZone - rtb_Init;
          rtb_Init = (3.0 * rtb_DeadZone) - (2.0 * rtb_Init);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch1) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Switch2_p2 * rtb_Init)) +
            rtb_Assignment[s217_iter];
          rtb_Init = ((((rtb_Minus_n[1] * rtb_Switch1) + (rtb_Add2[1] *
            rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Init)) +
            rtb_Switch2_o;
          rtb_Switch1 = ((3.0 * rtb_DeadZone) - (4.0 * rtb_Sin4)) + 1.0;
          rtb_Switch2 = (2.0 * rtb_Sin4) - (3.0 * rtb_DeadZone);
          rtb_DeadZone = (rtb_Sin4 - rtb_DeadZone) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch1) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Switch2_p2 * rtb_DeadZone);
          rtb_Switch2_i = (((rtb_Minus_n[1] * rtb_Switch1) + (rtb_Add2[1] *
            rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_DeadZone);
          rtb_DeadZone = (6.0 * rtb_Sin4) - 4.0;
          rtb_Switch1 = (-6.0 * rtb_Sin4) + 2.0;
          rtb_Sin4 = (-12.0 * rtb_Sin4) + 6.0;
          rtb_Switch2 = (((rtb_Minus_n[0] * rtb_DeadZone) + (rtb_Add2[0] *
            rtb_Switch1)) * 0.5) + (rtb_Switch2_p2 * rtb_Sin4);
          rtb_Switch1 = (((rtb_Minus_n[1] * rtb_DeadZone) + (rtb_Add2[1] *
            rtb_Switch1)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Sin4);
          rtb_DeadZone = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Switch2_i), 3.0);
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
              rtb_Switch2_i)) / (rtb_Sin4 * rtb_DeadZone);
        }

        if (s217_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s217_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Init_o - ((real_T)s217_iter);
        rtb_Num_Segments = s217_iter;
        s217_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s217_iter <= 3));

      /* End of Outputs for SubSystem: '<S213>/Sampling_Loop' */

      /* SignalConversion generated from: '<S196>/Position_and_Curvature' incorporates:
       *  Assignment: '<S217>/Assignment'
       *  Merge: '<S191>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S191>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S191>/If Action Subsystem' incorporates:
       *  ActionPort: '<S194>/Action Port'
       */
      /* Product: '<S194>/Product' incorporates:
       *  Selector: '<S191>/Selector'
       *  Selector: '<S191>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1];

      /* Product: '<S194>/Product1' incorporates:
       *  Selector: '<S191>/Selector'
       *  Selector: '<S191>/Selector1'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S194>/Product' incorporates:
         *  Constant: '<S194>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S194>/Product1' incorporates:
         *  Constant: '<S194>/Constant2'
         *  Product: '<S194>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Init_o;
      }

      /* Assignment: '<S194>/Assignment' incorporates:
       *  Concatenate: '<S194>/Matrix Concatenate'
       *  Merge: '<S191>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S194>/Assignment' */

      /* SignalConversion generated from: '<S194>/Num_Segments' incorporates:
       *  Constant: '<S194>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S191>/If Action Subsystem' */
    }

    /* End of If: '<S191>/If1' */

    /* Concatenate: '<S192>/Matrix Concatenate' incorporates:
     *  Merge: '<S191>/Merge'
     *  Selector: '<S192>/Selector'
     *  Selector: '<S192>/Selector1'
     *  Selector: '<S192>/Selector3'
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

    /* End of Concatenate: '<S192>/Matrix Concatenate' */

    /* MATLAB Function: '<S192>/Distance Along Curve' incorporates:
     *  Concatenate: '<S192>/Matrix Concatenate'
     *  Selector: '<S192>/Selector4'
     *  Selector: '<S192>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s217_iter = 0; s217_iter < 149; s217_iter++) {
      /* Outputs for Iterator SubSystem: '<S213>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S217>/While Iterator'
       */
      rtb_Assignment_d[s217_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s217_iter + 1] -
         rtb_MatrixConcatenate_o[s217_iter], rtb_MatrixConcatenate_o[s217_iter +
         151] - rtb_MatrixConcatenate_o[s217_iter + 150]) +
        rtb_Assignment_d[s217_iter];

      /* End of Outputs for SubSystem: '<S213>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S192>/Distance Along Curve' */

    /* MATLAB Function: '<S192>/Find closest index to curve' incorporates:
     *  Concatenate: '<S192>/Matrix Concatenate'
     *  Selector: '<S192>/Selector4'
     *  Selector: '<S192>/Selector5'
     *  Selector: '<S243>/Selector'
     */
    for (s217_iter = 0; s217_iter < 150; s217_iter++) {
      /* Outputs for Iterator SubSystem: '<S213>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S217>/While Iterator'
       */
      distance_from_robot[s217_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s217_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s217_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S213>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s217_iter = 1;
    } else {
      s217_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s217_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s217_iter == 0) {
      rtb_Init_o = distance_from_robot[0];
    } else {
      rtb_Init_o = distance_from_robot[s217_iter - 1];
      for (rtb_Bias1_p = s217_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Init_o > rtb_Sin4) {
          rtb_Init_o = rtb_Sin4;
        }
      }
    }

    s217_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s217_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Init_o) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S243>/Selector' incorporates:
     *  Constant: '<S243>/Constant'
     *  MATLAB Function: '<S192>/Find closest index to curve'
     *  MinMax: '<S243>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s217_iter)) - 1];

    /* If: '<S243>/If' incorporates:
     *  RelationalOperator: '<S243>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S243>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S246>/Action Port'
       */
      /* SignalConversion generated from: '<S246>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S248>/FixPt Sum1' incorporates:
       *  Constant: '<S248>/FixPt Constant'
       */
      rtb_Init_o = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S246>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S246>/Selector11'
       *  Selector: '<S246>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S246>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S246>/Selector1'
       *  Selector: '<S246>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S246>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S246>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Init_o), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S246>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S246>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S246>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S243>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S243>/Latch' incorporates:
       *  ActionPort: '<S247>/Action Port'
       */
      /* SignalConversion generated from: '<S247>/In1' incorporates:
       *  UnitDelay: '<S243>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S247>/In2' incorporates:
       *  UnitDelay: '<S243>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S243>/Latch' */
    }

    /* End of If: '<S243>/If' */

    /* MinMax: '<S190>/Min' incorporates:
     *  Lookup_n-D: '<S190>/Lookahead Distance'
     *  UnitDelay: '<S190>/Unit Delay'
     */
    rtb_Switch1_m = fmin(rtb_Switch1_m, look1_binlcpw
                         (Robot_Control_DW.UnitDelay_DSTATE_hn,
                          rtCP_LookaheadDistance_bp01Data,
                          rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S192>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S242>/While Iterator'
     */
    s242_iter = 1U;
    rtb_Is_Absolute_Translation_g = true;
    while (rtb_Is_Absolute_Translation_g && (s242_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S192>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S242>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s242_iter;
      rtb_Is_Absolute_Translation_g =
        ((rtb_Assignment_d[Robot_Control_B.WhileIterator - 1] <=
          (rtb_Assignment_d[s217_iter - 1] + rtb_Switch1_m)) &&
         (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s242_iter++;
    }

    /* End of Outputs for SubSystem: '<S192>/Find first index that meets distance target' */

    /* Switch: '<S245>/Switch' incorporates:
     *  Concatenate: '<S192>/Matrix Concatenate'
     *  Constant: '<S192>/Constant'
     *  Constant: '<S242>/Constant'
     *  Constant: '<S245>/Constant'
     *  Constant: '<S245>/Constant1'
     *  Constant: '<S245>/Constant2'
     *  Constant: '<S245>/Constant3'
     *  Logic: '<S242>/AND'
     *  MATLAB Function: '<S192>/Find closest index to curve'
     *  Math: '<S245>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S245>/Max'
     *  MinMax: '<S245>/Min'
     *  MinMax: '<S245>/Min1'
     *  Product: '<S242>/Product'
     *  Product: '<S245>/Divide'
     *  Product: '<S245>/Product'
     *  Product: '<S245>/Product1'
     *  RelationalOperator: '<S192>/Relational Operator'
     *  RelationalOperator: '<S242>/Relational Operator'
     *  RelationalOperator: '<S242>/Relational Operator1'
     *  Selector: '<S192>/Selector10'
     *  Selector: '<S192>/Selector7'
     *  Selector: '<S192>/Selector8'
     *  Selector: '<S192>/Selector9'
     *  Selector: '<S242>/Selector'
     *  Selector: '<S242>/Selector1'
     *  Selector: '<S243>/Selector'
     *  Sqrt: '<S245>/Sqrt'
     *  Sum: '<S192>/Subtract'
     *  Sum: '<S242>/Add'
     *  Sum: '<S245>/Subtract'
     *  Sum: '<S245>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Switch1_m = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
                           Spline_Last_Pose_Distance_to_Velocity_Gain, fmin
                           (rtb_Init_o * Spline_Velocity_Multiplier_TEST, sqrt
                            (Spline_Max_Centripital_Acceleration / fmax
        (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Switch1_m = fmin(rtb_Init_o * Spline_Velocity_Multiplier_TEST, sqrt
                           (Spline_Max_Centripital_Acceleration / fmax
                            (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator
        + 299], 1.0E-5)));
    }

    /* End of Switch: '<S245>/Switch' */

    /* Logic: '<S193>/OR' */
    rtb_Swerve_Motors_Disabled = (rtb_Is_Absolute_Steering ||
      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S193>/Switch1' incorporates:
     *  Switch: '<S193>/Switch'
     *  UnitDelay: '<S193>/Unit Delay'
     */
    if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S193>/Constant3'
       *  SignalConversion: '<S193>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S193>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Switch1_m;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S193>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S193>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S192>/Selector6' incorporates:
     *  Concatenate: '<S192>/Matrix Concatenate'
     *  Selector: '<S192>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S192>/Selector2' incorporates:
     *  Concatenate: '<S192>/Matrix Concatenate'
     *  Selector: '<S192>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S193>/Switch2' incorporates:
     *  Sum: '<S249>/Subtract'
     *  Sum: '<S249>/Subtract1'
     *  Trigonometry: '<S249>/Atan2'
     *  UnitDelay: '<S193>/Unit Delay1'
     */
    if (rtb_Swerve_Motors_Disabled) {
      rtb_DeadZone = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_DeadZone = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S193>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S193>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_DeadZone;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S190>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S190>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S193>/Constant2'
     *  SignalConversion generated from: '<S190>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S193>/Constant5'
     *  SignalConversion generated from: '<S190>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S193>/Constant6'
     *  SignalConversion generated from: '<S190>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S190>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S191>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S190>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Switch1_m;

    /* Update for UnitDelay: '<S243>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Init_o;

    /* Update for UnitDelay: '<S243>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S193>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S193>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_DeadZone;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S189>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S189>/Constant1'
     *  SignalConversion generated from: '<S189>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S189>/Constant'
     *  SignalConversion generated from: '<S189>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S189>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S189>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S189>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S189>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S189>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S189>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S189>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S339>/Sign2' incorporates:
   *  UnitDelay: '<S339>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S339>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S339>/Product1' incorporates:
   *  Signum: '<S339>/Sign1'
   *  Signum: '<S339>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S339>/Switch' incorporates:
   *  Constant: '<S339>/Constant'
   *  Constant: '<S344>/Constant'
   *  Constant: '<S345>/Constant'
   *  Logic: '<S339>/or'
   *  Product: '<S339>/Product1'
   *  RelationalOperator: '<S344>/Compare'
   *  RelationalOperator: '<S345>/Compare'
   *  UnitDelay: '<S339>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S339>/Switch' */

  /* Switch: '<S350>/Init' incorporates:
   *  UnitDelay: '<S350>/FixPt Unit Delay1'
   *  UnitDelay: '<S350>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S350>/Init' */

  /* RelationalOperator: '<S346>/Compare' incorporates:
   *  Constant: '<S346>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S347>/Compare' incorporates:
   *  Constant: '<S347>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Sin4 > 0.0);

  /* Abs: '<S339>/Abs' incorporates:
   *  Sum: '<S339>/Subtract'
   *  UnitDelay: '<S339>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S339>/Switch5' incorporates:
   *  Constant: '<S339>/Constant1'
   *  Switch: '<S339>/Switch1'
   *  UnaryMinus: '<S339>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* SignalConversion generated from: '<S339>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S339>/Constant4'
     *  Constant: '<S339>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S339>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S339>/Constant2'
     *  Constant: '<S339>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S339>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S339>/Lookup Table Dynamic'
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
    rtb_Add_oy = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S339>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S339>/Constant10'
     *  Constant: '<S339>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S339>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S339>/Constant7'
     *  Constant: '<S339>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S339>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S339>/Lookup Table Dynamic1'
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

    /* Switch: '<S339>/Switch3' incorporates:
     *  Constant: '<S339>/Constant1'
     *  Constant: '<S339>/Constant3'
     *  UnaryMinus: '<S339>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_oy = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_oy = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S339>/Switch3' */
  }

  /* End of Switch: '<S339>/Switch5' */

  /* Product: '<S339>/Product' incorporates:
   *  Switch: '<S339>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_oy * rtb_Merge1;

  /* Sum: '<S348>/Sum1' */
  rtb_Switch1_m = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S349>/Switch2' incorporates:
   *  RelationalOperator: '<S349>/LowerRelop1'
   */
  if (!(rtb_Switch1_m > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S339>/Switch2' incorporates:
     *  Constant: '<S339>/Constant1'
     *  Switch: '<S339>/Switch4'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S339>/Switch4' incorporates:
       *  Constant: '<S339>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S339>/Switch4' incorporates:
       *  Constant: '<S339>/Constant3'
       *  UnaryMinus: '<S339>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S339>/Switch2' */

    /* Product: '<S339>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S349>/Switch' incorporates:
     *  RelationalOperator: '<S349>/UpperRelop'
     */
    if (rtb_Switch1_m < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch1_m;
    }

    /* End of Switch: '<S349>/Switch' */
  }

  /* End of Switch: '<S349>/Switch2' */

  /* Sum: '<S348>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S342>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S342>/Switch' incorporates:
     *  Constant: '<S376>/Constant3'
     *  Constant: '<S376>/Constant4'
     *  Math: '<S376>/Math Function'
     *  Sum: '<S342>/Subtract'
     *  Sum: '<S376>/Add1'
     *  Sum: '<S376>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S342>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S342>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_oy = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_oy)) || (rtIsInf(rtb_Add_oy))) {
    rtb_Add_oy = 0.0;
  } else {
    rtb_Add_oy = fmod(rtb_Add_oy, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Add_oy < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Add_oy)))))) : ((int32_T)((uint8_T)rtb_Add_oy)));

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* Sum: '<S130>/Subtract' incorporates:
   *  Constant: '<S130>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Sin4 = Rebuilt_Match_Time_TeleOp - Robot_Control_U.MatchTime;

  /* If: '<S130>/If' incorporates:
   *  Constant: '<S156>/Constant'
   *  Constant: '<S157>/Constant'
   *  Constant: '<S158>/Constant'
   *  Constant: '<S159>/Constant'
   *  Constant: '<S160>/Constant'
   *  Constant: '<S161>/Constant'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S156>/Compare'
   *  RelationalOperator: '<S157>/Compare'
   *  RelationalOperator: '<S158>/Compare'
   *  RelationalOperator: '<S159>/Compare'
   *  RelationalOperator: '<S160>/Compare'
   *  RelationalOperator: '<S161>/Compare'
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
      /* InitializeConditions for IfAction SubSystem: '<S130>/If Action Subsystem' incorporates:
       *  ActionPort: '<S162>/Action Port'
       */
      /* InitializeConditions for If: '<S130>/If' incorporates:
       *  UnitDelay: '<S162>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_lc = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S130>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    /* Merge: '<S130>/Merge' incorporates:
     *  Constant: '<S162>/Constant'
     *  SignalConversion generated from: '<S162>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S130>/Merge1' incorporates:
     *  Constant: '<S162>/Constant'
     *  SignalConversion generated from: '<S162>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S162>/Sum' incorporates:
     *  Constant: '<S162>/Constant1'
     *  UnitDelay: '<S162>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_lc - 0.02;

    /* Merge: '<S130>/Merge2' incorporates:
     *  SignalConversion: '<S162>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S162>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_lc = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S163>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S166>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    /* Merge: '<S130>/Merge' incorporates:
     *  Constant: '<S167>/Constant'
     *  SignalConversion generated from: '<S167>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S130>/Merge1' incorporates:
     *  Constant: '<S167>/Constant'
     *  SignalConversion generated from: '<S167>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S167>/Sum' incorporates:
     *  Constant: '<S167>/Constant1'
     *  UnitDelay: '<S167>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_c - 0.02;

    /* Merge: '<S130>/Merge2' incorporates:
     *  SignalConversion: '<S167>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S167>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_c = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S130>/If' */

  /* If: '<S173>/If' incorporates:
   *  If: '<S174>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S173>/Blue' incorporates:
     *  ActionPort: '<S175>/Action Port'
     */
    /* Merge: '<S173>/Merge' incorporates:
     *  Constant: '<S175>/BlueAllianceZoneX'
     *  Logic: '<S175>/AND'
     *  RelationalOperator: '<S175>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S173>/Blue' */

    /* Outputs for IfAction SubSystem: '<S174>/Blue' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    /* Merge: '<S174>/Merge' incorporates:
     *  Constant: '<S177>/BlueAllianceZoneX'
     *  RelationalOperator: '<S177>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S174>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S173>/Red' incorporates:
     *  ActionPort: '<S176>/Action Port'
     */
    /* Merge: '<S173>/Merge' incorporates:
     *  Constant: '<S176>/RedAllianceZoneX'
     *  Logic: '<S176>/AND'
     *  RelationalOperator: '<S176>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S173>/Red' */

    /* Outputs for IfAction SubSystem: '<S174>/Red' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Merge: '<S174>/Merge' incorporates:
     *  Constant: '<S178>/RedAllianceZoneX'
     *  RelationalOperator: '<S178>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S174>/Red' */
  }

  /* End of If: '<S173>/If' */

  /* RelationalOperator: '<S132>/GreaterThan' incorporates:
   *  Constant: '<S132>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S132>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S132>/Relational Operator' incorporates:
   *  Abs: '<S132>/Abs'
   *  Constant: '<S172>/Constant3'
   *  Constant: '<S172>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S172>/Math Function'
   *  Sum: '<S132>/Subtract'
   *  Sum: '<S172>/Add1'
   *  Sum: '<S172>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S131>/Max' incorporates:
   *  Abs: '<S131>/Abs1'
   *  Abs: '<S131>/Abs2'
   *  Abs: '<S131>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S132>/Relational Operator1' incorporates:
   *  Abs: '<S132>/Abs1'
   *  Constant: '<S132>/Constant2'
   *  Sum: '<S132>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S132>/Relational Operator4' incorporates:
   *  Abs: '<S132>/Abs4'
   *  Constant: '<S132>/Constant1'
   *  Sum: '<S132>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S132>/AND' */
  rtb_Is_Absolute_Translation_g = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
    (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S132>/AND2' incorporates:
   *  Logic: '<S132>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Is_Absolute_Translation_g);

  /* SignalConversion: '<S132>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S132>/AND3' */
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
    /* Outputs for IfAction SubSystem: '<S129>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S136>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S138>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S140>/While Iterator'
     */
    /* If: '<S129>/If' incorporates:
     *  Constant: '<S138>/Constant'
     *  Constant: '<S139>/Constant'
     *  Constant: '<S139>/Shooter Assembly Offset in Robot'
     *  Constant: '<S139>/Shooter Assembly Offset in Robot1'
     *  Constant: '<S141>/Constant1'
     *  Constant: '<S141>/Constant10'
     *  Constant: '<S141>/Constant2'
     *  Constant: '<S141>/Constant5'
     *  Constant: '<S141>/Constant6'
     *  Constant: '<S141>/Constant7'
     *  Constant: '<S141>/Constant8'
     *  Constant: '<S141>/Constant9'
     *  Constant: '<S142>/Constant1'
     *  Constant: '<S142>/Constant10'
     *  Constant: '<S142>/Constant2'
     *  Constant: '<S142>/Constant5'
     *  Constant: '<S142>/Constant6'
     *  Constant: '<S142>/Constant7'
     *  Constant: '<S142>/Constant8'
     *  Constant: '<S142>/Constant9'
     *  Constant: '<S143>/Constant'
     *  Constant: '<S143>/Constant1'
     *  Constant: '<S143>/Constant2'
     *  Constant: '<S145>/Constant1'
     *  Constant: '<S145>/Constant10'
     *  Constant: '<S145>/Constant2'
     *  Constant: '<S145>/Constant5'
     *  Constant: '<S145>/Constant6'
     *  Constant: '<S145>/Constant7'
     *  Constant: '<S145>/Constant8'
     *  Constant: '<S145>/Constant9'
     *  Constant: '<S148>/Constant'
     *  Constant: '<S148>/Constant1'
     *  Constant: '<S148>/Constant11'
     *  Constant: '<S148>/Constant2'
     *  Constant: '<S148>/Constant3'
     *  Constant: '<S148>/Constant4'
     *  Constant: '<S148>/Constant5'
     *  Constant: '<S148>/Constant6'
     *  Constant: '<S154>/Constant1'
     *  Constant: '<S154>/Constant10'
     *  Constant: '<S154>/Constant2'
     *  Constant: '<S154>/Constant5'
     *  Constant: '<S154>/Constant6'
     *  Constant: '<S154>/Constant7'
     *  Constant: '<S154>/Constant8'
     *  Constant: '<S154>/Constant9'
     *  Constant: '<S155>/Constant1'
     *  Constant: '<S155>/Constant10'
     *  Constant: '<S155>/Constant2'
     *  Constant: '<S155>/Constant5'
     *  Constant: '<S155>/Constant6'
     *  Constant: '<S155>/Constant7'
     *  Constant: '<S155>/Constant8'
     *  Constant: '<S155>/Constant9'
     *  Gain: '<S146>/Gain1'
     *  Gain: '<S153>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S140>/Memory'
     *  Memory: '<S140>/Memory1'
     *  Memory: '<S140>/Memory2'
     *  Memory: '<S140>/Memory3'
     *  Merge: '<S129>/Merge'
     *  Merge: '<S129>/Merge2'
     *  Merge: '<S129>/Merge3'
     *  MinMax: '<S139>/Max'
     *  Product: '<S139>/Divide'
     *  RelationalOperator: '<S143>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S141>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S142>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S143>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S143>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S141>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S148>/Lookup Table Dynamic'
     *  Sum: '<S139>/Add'
     *  Sum: '<S139>/Subtract'
     *  Sum: '<S139>/Subtract1'
     *  Sum: '<S143>/Add'
     *  Switch: '<S143>/Switch'
     *  Switch: '<S143>/Switch1'
     *  Switch: '<S144>/Switch4'
     *  Switch: '<S144>/Switch5'
     *  Switch: '<S144>/Switch6'
     *  Trigonometry: '<S139>/Tanh'
     *  Trigonometry: '<S139>/Tanh1'
     *  UnitDelay: '<S143>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S138>/Iterate_Shot_Target' */
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
      /* Switch: '<S144>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S144>/Switch4' incorporates:
         *  Constant: '<S144>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S144>/Switch4' incorporates:
         *  Constant: '<S144>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S144>/Switch2' */

      /* Switch: '<S144>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S144>/Switch6' incorporates:
         *  Constant: '<S144>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S144>/Switch6' incorporates:
         *  Constant: '<S144>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S144>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S144>/Switch5' incorporates:
         *  Constant: '<S144>/Constant8'
         *  Switch: '<S144>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S144>/Switch4' incorporates:
         *  Constant: '<S144>/Constant9'
         *  Switch: '<S144>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S144>/Switch6' incorporates:
       *  Constant: '<S144>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S138>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S140>/While Iterator'
     */
    Iteration_Number = 1U;
    rtb_Merge1 = 0.0;
    rtb_Switch1_m = 0.0;
    rtb_Init_o = 0.0;
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
      /* Switch: '<S149>/Switch' incorporates:
       *  Memory: '<S140>/Memory1'
       *  Memory: '<S140>/Memory2'
       *  Switch: '<S149>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_DeadZone = rtb_Switch1_m;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_DeadZone = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S149>/Switch' */

      /* Math: '<S147>/Hypot' incorporates:
       *  Sum: '<S147>/Subtract'
       *  Sum: '<S147>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_DeadZone -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S148>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S148>/Lookup Table Dynamic'
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

      /* Sum: '<S150>/Subtract' incorporates:
       *  Memory: '<S140>/Memory3'
       *  Sum: '<S150>/Subtract1'
       */
      rtb_Merge1 = rtb_TOF - rtb_Init_o;

      /* Sum: '<S150>/Add' incorporates:
       *  Gain: '<S150>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S150>/Product'
       *  Sum: '<S150>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S150>/Add1' incorporates:
       *  Gain: '<S150>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S150>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_DeadZone;

      /* Memory: '<S140>/Memory' */
      rtb_Is_Absolute_Translation_g = rtb_Button_Spinup_Enable;

      /* Update for Memory: '<S140>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S140>/Memory2' */
      rtb_Switch1_m = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S140>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S140>/Memory' incorporates:
       *  Constant: '<S152>/Constant'
       *  Math: '<S151>/Hypot'
       *  RelationalOperator: '<S152>/Compare'
       *  Sum: '<S151>/Subtract'
       *  Sum: '<S151>/Subtract1'
       */
      rtb_Button_Spinup_Enable = (rt_hypotd_snf
        (Robot_Control_B.RB_Desired_Target_X - rtb_Sin4,
         Robot_Control_B.RB_Desired_Target_Y - rtb_DeadZone) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S138>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S142>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S141>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S143>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S143>/Lookup Table Dynamic1'
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
      /* Merge: '<S129>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S129>/Merge1' */
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

    /* End of Outputs for SubSystem: '<S129>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_oy = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Minus_k_idx_1 = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S129>/Shooter Not Active' incorporates:
     *  ActionPort: '<S137>/Action Port'
     */
    /* If: '<S129>/If' incorporates:
     *  Constant: '<S137>/Constant'
     *  Constant: '<S137>/Constant1'
     *  Constant: '<S137>/Constant2'
     *  Constant: '<S137>/Constant3'
     *  Merge: '<S129>/Merge'
     *  Merge: '<S129>/Merge1'
     *  Merge: '<S129>/Merge2'
     *  Merge: '<S129>/Merge3'
     *  SignalConversion generated from: '<S137>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* End of Outputs for SubSystem: '<S129>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_oy = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S371>/Add1' incorporates:
   *  Constant: '<S371>/Constant3'
   *  Constant: '<S371>/Constant4'
   *  Math: '<S371>/Math Function'
   *  Sum: '<S370>/Sum'
   *  Sum: '<S371>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_oy - rtb_Minus_k_idx_1) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Gain: '<S374>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle_p;

  /* Abs: '<S353>/Abs1' */
  rtb_Init_o = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S373>/Sum1' incorporates:
   *  Constant: '<S370>/Constant2'
   *  Product: '<S373>/Product'
   *  Sum: '<S373>/Sum'
   *  UnitDelay: '<S373>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Optimized_Module_Angle_p -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S370>/Product' incorporates:
   *  Constant: '<S370>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S372>/Diff' incorporates:
   *  UnitDelay: '<S372>/UD'
   *
   * Block description for '<S372>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S372>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S370>/Saturation' */
  if (rtb_Add_oy > Steering_Heading_Control_D_UL) {
    rtb_Add_oy = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Heading_Control_D_LL) {
    rtb_Add_oy = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S370>/Add' incorporates:
   *  Gain: '<S370>/Gain1'
   *  Saturate: '<S370>/Saturation'
   */
  rtb_DeadZone = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_oy;

  /* Sum: '<S370>/Subtract' incorporates:
   *  Constant: '<S370>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_DeadZone;

  /* Sum: '<S370>/Sum2' incorporates:
   *  Gain: '<S370>/Gain2'
   *  UnitDelay: '<S370>/Unit Delay'
   */
  rtb_Switch1_m = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S375>/Switch2' incorporates:
   *  RelationalOperator: '<S375>/LowerRelop1'
   */
  if (!(rtb_Switch1_m > rtb_Sin4)) {
    /* Sum: '<S370>/Subtract1' incorporates:
     *  Constant: '<S370>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_DeadZone;

    /* Switch: '<S375>/Switch' incorporates:
     *  RelationalOperator: '<S375>/UpperRelop'
     */
    if (!(rtb_Switch1_m < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1_m;
    }

    /* End of Switch: '<S375>/Switch' */
  }

  /* End of Switch: '<S375>/Switch2' */

  /* Saturate: '<S370>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Switch1_m = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Switch1_m = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch1_m = rtb_Sin4;
  }

  /* End of Saturate: '<S370>/Saturation1' */

  /* Sum: '<S370>/Add1' */
  rtb_Add_oy = rtb_DeadZone + rtb_Switch1_m;

  /* Saturate: '<S370>/Saturation2' */
  if (rtb_Add_oy > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S370>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_oy < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S370>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S370>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_oy;
  }

  /* End of Saturate: '<S370>/Saturation2' */

  /* Abs: '<S353>/Abs' */
  rtb_Sin4 = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S353>/Add dither' */
  if (Robot_Control_DW.is_active_c7_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c7_Robot_Control = 1U;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Sin4;
  } else if (Robot_Control_DW.is_c7_Robot_Control == Robot_Control_IN_Dither) {
    if ((!Robot_Control_B.RB_Shooter_Active) || (rtb_Init_o <
         Steering_Heading_Dither_Thresh_Off)) {
      Robot_Control_DW.is_Dither = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
      Robot_Control_B.abs_Cmd_Out = rtb_Sin4;
    } else if (Robot_Control_DW.is_Dither == Robot_Control_IN_High) {
      if (Robot_Control_DW.timer >= Steering_Heading_Dither_Period) {
        Robot_Control_DW.is_Dither = Robot_Control_IN_Off;
        Robot_Control_B.abs_Cmd_Out = 0.0;
        Robot_Control_DW.timer = 0.0;
      } else {
        Robot_Control_B.abs_Cmd_Out = rtb_Sin4 * Steering_Heading_Dither_Gain;
        Robot_Control_DW.timer += 0.02;
      }

      /* case IN_Off: */
    } else if (Robot_Control_DW.timer >= Steering_Heading_Dither_Period) {
      Robot_Control_DW.is_Dither = Robot_Control_IN_High;
      Robot_Control_B.abs_Cmd_Out = rtb_Sin4 * Steering_Heading_Dither_Gain;
      Robot_Control_DW.timer = 0.0;
    } else {
      Robot_Control_DW.timer += 0.02;
    }

    /* case IN_No_Dither: */
  } else if ((Robot_Control_B.RB_Shooter_Active) && (rtb_Init_o >
              Steering_Heading_Dither_Thresh_On)) {
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_Dither;
    Robot_Control_DW.is_Dither = Robot_Control_IN_High;
    Robot_Control_B.abs_Cmd_Out = rtb_Sin4 * Steering_Heading_Dither_Gain;
    Robot_Control_DW.timer = 0.0;
  } else {
    Robot_Control_B.abs_Cmd_Out = rtb_Sin4;
  }

  /* End of Chart: '<S353>/Add dither' */

  /* Switch: '<S353>/Switch' incorporates:
   *  Constant: '<S353>/Constant'
   *  Constant: '<S369>/Constant'
   *  Product: '<S353>/Product'
   *  RelationalOperator: '<S369>/Compare'
   *  Signum: '<S353>/Sign'
   */
  if (rtb_Sin4 > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S353>/Sign' */
    if (rtIsNaN(Robot_Control_B.Steering_Heading_PID)) {
      rtb_Add_oy = (rtNaN);
    } else if (Robot_Control_B.Steering_Heading_PID < 0.0) {
      rtb_Add_oy = -1.0;
    } else {
      rtb_Add_oy = (Robot_Control_B.Steering_Heading_PID > 0.0);
    }

    rtb_Optimized_Module_Angle_p = Robot_Control_B.abs_Cmd_Out * rtb_Add_oy;
  } else {
    rtb_Optimized_Module_Angle_p = 0.0;
  }

  /* End of Switch: '<S353>/Switch' */

  /* Signum: '<S352>/Sign2' incorporates:
   *  UnitDelay: '<S352>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S352>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S352>/Product1' incorporates:
   *  Signum: '<S352>/Sign1'
   *  Signum: '<S352>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S352>/Switch' incorporates:
   *  Constant: '<S352>/Constant'
   *  Constant: '<S361>/Constant'
   *  Constant: '<S362>/Constant'
   *  Logic: '<S352>/or'
   *  Product: '<S352>/Product1'
   *  RelationalOperator: '<S361>/Compare'
   *  RelationalOperator: '<S362>/Compare'
   *  UnitDelay: '<S352>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_o = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_o = 0.0;
  }

  /* End of Switch: '<S352>/Switch' */

  /* Switch: '<S367>/Init' incorporates:
   *  UnitDelay: '<S367>/FixPt Unit Delay1'
   *  UnitDelay: '<S367>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Switch2_o;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S367>/Init' */

  /* RelationalOperator: '<S363>/Compare' incorporates:
   *  Constant: '<S363>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Switch2_o == 0.0);

  /* RelationalOperator: '<S364>/Compare' incorporates:
   *  Constant: '<S364>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Switch2_o > 0.0);

  /* Abs: '<S352>/Abs' incorporates:
   *  Sum: '<S352>/Subtract'
   *  UnitDelay: '<S352>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S352>/Switch5' incorporates:
   *  Constant: '<S352>/Constant1'
   *  Switch: '<S352>/Switch1'
   *  UnaryMinus: '<S352>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    /* SignalConversion generated from: '<S352>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S352>/Constant4'
     *  Constant: '<S352>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S352>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S352>/Constant2'
     *  Constant: '<S352>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S352>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S352>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Reshapey[0], rtb_Sin4,
                         &rtb_Minus_n[0], 1U);
    rtb_Sin4 = rtb_LookupTableDynamic;
    rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S352>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S352>/Constant10'
     *  Constant: '<S352>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S352>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S352>/Constant7'
     *  Constant: '<S352>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S352>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S352>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Reshapey[0], rtb_Sin4,
                         &rtb_Minus_n[0], 1U);
    rtb_Sin4 = rtb_LookupTableDynamic1;

    /* Switch: '<S352>/Switch3' incorporates:
     *  Constant: '<S352>/Constant1'
     *  Constant: '<S352>/Constant3'
     *  UnaryMinus: '<S352>/Unary Minus'
     */
    if (rtb_Button_Shoot_Enable) {
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S352>/Switch3' */
  }

  /* End of Switch: '<S352>/Switch5' */

  /* Product: '<S352>/Product' incorporates:
   *  Switch: '<S352>/Switch1'
   */
  rtb_Init = rtb_Add_oy * rtb_Sin4;

  /* Sum: '<S365>/Sum1' */
  rtb_DeadZone = rtb_Switch2_o - rtb_Init_o;

  /* Switch: '<S366>/Switch2' incorporates:
   *  RelationalOperator: '<S366>/LowerRelop1'
   */
  if (!(rtb_DeadZone > rtb_Init)) {
    /* Switch: '<S352>/Switch2' incorporates:
     *  Constant: '<S352>/Constant1'
     *  Constant: '<S352>/Constant3'
     *  Switch: '<S352>/Switch4'
     *  UnaryMinus: '<S352>/Unary Minus1'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S352>/Switch4' incorporates:
       *  Constant: '<S352>/Constant1'
       */
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S352>/Product2' incorporates:
     *  Switch: '<S352>/Switch2'
     */
    rtb_Switch1 = rtb_Add_oy * rtb_Sin4;

    /* Switch: '<S366>/Switch' incorporates:
     *  RelationalOperator: '<S366>/UpperRelop'
     */
    if (rtb_DeadZone < rtb_Switch1) {
      rtb_Init = rtb_Switch1;
    } else {
      rtb_Init = rtb_DeadZone;
    }

    /* End of Switch: '<S366>/Switch' */
  }

  /* End of Switch: '<S366>/Switch2' */

  /* Sum: '<S365>/Sum' */
  rtb_Init_o += rtb_Init;

  /* Signum: '<S351>/Sign2' incorporates:
   *  UnitDelay: '<S351>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S351>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S351>/Product1' incorporates:
   *  Signum: '<S351>/Sign1'
   *  Signum: '<S351>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S351>/Switch' incorporates:
   *  Constant: '<S351>/Constant'
   *  Constant: '<S354>/Constant'
   *  Constant: '<S355>/Constant'
   *  Logic: '<S351>/or'
   *  Product: '<S351>/Product1'
   *  RelationalOperator: '<S354>/Compare'
   *  RelationalOperator: '<S355>/Compare'
   *  UnitDelay: '<S351>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_o = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_o = 0.0;
  }

  /* End of Switch: '<S351>/Switch' */

  /* Switch: '<S360>/Init' incorporates:
   *  UnitDelay: '<S360>/FixPt Unit Delay1'
   *  UnitDelay: '<S360>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_o;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S360>/Init' */

  /* RelationalOperator: '<S356>/Compare' incorporates:
   *  Constant: '<S356>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Switch2_o == 0.0);

  /* RelationalOperator: '<S357>/Compare' incorporates:
   *  Constant: '<S357>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Switch2_o > 0.0);

  /* Abs: '<S351>/Abs' incorporates:
   *  Sum: '<S351>/Subtract'
   *  UnitDelay: '<S351>/Unit Delay'
   */
  rtb_DeadZone = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                      Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S351>/Switch1' incorporates:
   *  Constant: '<S351>/Constant1'
   *  Switch: '<S351>/Switch3'
   *  Switch: '<S351>/Switch5'
   *  UnaryMinus: '<S351>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S351>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S351>/Constant1'
     *  Constant: '<S351>/Constant4'
     *  Constant: '<S351>/Constant6'
     *  UnaryMinus: '<S351>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S351>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S351>/Constant2'
     *  Constant: '<S351>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S351>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S351>/Lookup Table Dynamic'
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
      /* Switch: '<S351>/Switch3' incorporates:
       *  Constant: '<S351>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S351>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S351>/Constant1'
     *  Constant: '<S351>/Constant10'
     *  Constant: '<S351>/Constant8'
     *  UnaryMinus: '<S351>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S351>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S351>/Constant7'
     *  Constant: '<S351>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S351>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S351>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S351>/Switch1' */

  /* Product: '<S351>/Product' */
  rtb_Sin4 *= rtb_DeadZone;

  /* Sum: '<S358>/Sum1' */
  rtb_Switch1 = rtb_Switch2_o - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S359>/Switch2' incorporates:
   *  RelationalOperator: '<S359>/LowerRelop1'
   */
  if (!(rtb_Switch1 > rtb_Sin4)) {
    /* Switch: '<S351>/Switch2' incorporates:
     *  Constant: '<S351>/Constant1'
     *  Switch: '<S351>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S351>/Switch4' incorporates:
       *  Constant: '<S351>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S351>/Switch4' incorporates:
       *  Constant: '<S351>/Constant3'
       *  UnaryMinus: '<S351>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S351>/Switch2' */

    /* Product: '<S351>/Product2' */
    rtb_Sin4 *= rtb_DeadZone;

    /* Switch: '<S359>/Switch' incorporates:
     *  RelationalOperator: '<S359>/UpperRelop'
     */
    if (!(rtb_Switch1 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1;
    }

    /* End of Switch: '<S359>/Switch' */
  }

  /* End of Switch: '<S359>/Switch2' */

  /* Sum: '<S358>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S341>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S341>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S341>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S341>/Switch' */

  /* Fcn: '<S384>/r->x' incorporates:
   *  Fcn: '<S389>/r->x'
   *  Fcn: '<S394>/r->x'
   *  Fcn: '<S399>/r->x'
   */
  rtb_Switch1 = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S378>/Add' incorporates:
   *  Fcn: '<S384>/r->x'
   *  Fcn: '<S385>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1;

  /* Fcn: '<S384>/theta->y' incorporates:
   *  Fcn: '<S389>/theta->y'
   *  Fcn: '<S394>/theta->y'
   *  Fcn: '<S399>/theta->y'
   */
  rtb_DeadZone = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S378>/Add' incorporates:
   *  Fcn: '<S384>/theta->y'
   *  Fcn: '<S385>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S379>/Add' incorporates:
   *  Fcn: '<S390>/r->x'
   *  Fcn: '<S390>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S380>/Add' incorporates:
   *  Fcn: '<S395>/r->x'
   *  Fcn: '<S395>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S381>/Add' incorporates:
   *  Fcn: '<S400>/r->x'
   *  Fcn: '<S400>/theta->y'
   */
  rtb_Switch2_p2 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_DeadZone;

  /* Fcn: '<S398>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Switch2_p2, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S401>/Compare' incorporates:
   *  Constant: '<S401>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Init == 0.0);

  /* Switch: '<S397>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S397>/Switch1' incorporates:
     *  Constant: '<S397>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S397>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S397>/Switch1' */

  /* Fcn: '<S383>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S386>/Compare' incorporates:
   *  Constant: '<S386>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Init == 0.0);

  /* Switch: '<S382>/Switch1' */
  if (rtb_Button_Spinup_Enable) {
    /* Switch: '<S382>/Switch1' incorporates:
     *  Constant: '<S382>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S382>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S382>/Switch1' */

  /* Fcn: '<S388>/x->r' */
  rtb_Switch2_o = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S391>/Compare' incorporates:
   *  Constant: '<S391>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Switch2_o == 0.0);

  /* Switch: '<S387>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S387>/Switch1' incorporates:
     *  Constant: '<S387>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S387>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_o;
  }

  /* End of Switch: '<S387>/Switch1' */

  /* Fcn: '<S393>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S396>/Compare' incorporates:
   *  Constant: '<S396>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S392>/Switch1' */
  if (rtb_Button_Shoot_Enable) {
    /* Switch: '<S392>/Switch1' incorporates:
     *  Constant: '<S392>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S392>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S392>/Switch1' */

  /* Product: '<S377>/Divide' incorporates:
   *  Abs: '<S377>/Abs'
   *  Abs: '<S377>/Abs1'
   *  Abs: '<S377>/Abs2'
   *  Abs: '<S377>/Abs3'
   *  Constant: '<S377>/Constant'
   *  MinMax: '<S377>/Max'
   */
  rtb_Init = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S377>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S397>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S397>/Switch' incorporates:
     *  Fcn: '<S398>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Switch2_p2);
  }

  /* End of Switch: '<S397>/Switch' */

  /* Trigonometry: '<S331>/Cos4' incorporates:
   *  Switch: '<S320>/Angle_Switch'
   *  Trigonometry: '<S330>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S331>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S329>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S331>/Sin4' incorporates:
   *  Switch: '<S320>/Angle_Switch'
   *  Trigonometry: '<S330>/Sin4'
   */
  rtb_DeadZone = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S331>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S329>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S331>/Subtract1' incorporates:
   *  Product: '<S331>/Product2'
   *  Product: '<S331>/Product3'
   *  Trigonometry: '<S331>/Cos4'
   *  Trigonometry: '<S331>/Sin4'
   */
  rtb_Switch1 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) + (rtb_DeadZone
    * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S331>/Subtract' incorporates:
   *  Product: '<S331>/Product'
   *  Product: '<S331>/Product1'
   *  Trigonometry: '<S331>/Cos4'
   *  Trigonometry: '<S331>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_DeadZone * rtb_Optimized_Module_Angle);

  /* Math: '<S331>/Hypot' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

  /* Switch: '<S331>/Switch' incorporates:
   *  Constant: '<S331>/Constant'
   *  Constant: '<S331>/Constant1'
   *  Constant: '<S332>/Constant'
   *  Product: '<S331>/Divide'
   *  Product: '<S331>/Divide1'
   *  RelationalOperator: '<S332>/Compare'
   *  Switch: '<S331>/Switch1'
   */
  if (rtb_Switch2_p2 > 1.0E-6) {
    rtb_Switch2_o = rtb_Switch1 / rtb_Switch2_p2;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Switch2_p2;
  } else {
    rtb_Switch2_o = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S331>/Switch' */

  /* Switch: '<S320>/Speed_Switch' incorporates:
   *  Abs: '<S320>/Abs'
   *  Constant: '<S328>/Constant'
   *  RelationalOperator: '<S328>/Compare'
   *  Switch: '<S320>/Angle_Switch'
   *  Trigonometry: '<S330>/Atan1'
   *  Trigonometry: '<S331>/Atan1'
   *  UnaryMinus: '<S320>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_o, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S330>/Subtract1' incorporates:
     *  Product: '<S330>/Product2'
     *  Product: '<S330>/Product3'
     *  UnaryMinus: '<S320>/Unary Minus'
     */
    rtb_Switch1 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_DeadZone * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S330>/Subtract' incorporates:
     *  Product: '<S330>/Product'
     *  Product: '<S330>/Product1'
     */
    rtb_Switch2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_DeadZone * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S330>/Hypot' */
    rtb_DeadZone = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

    /* Switch: '<S330>/Switch1' incorporates:
     *  Constant: '<S330>/Constant'
     *  Constant: '<S330>/Constant1'
     *  Constant: '<S333>/Constant'
     *  Product: '<S330>/Divide'
     *  Product: '<S330>/Divide1'
     *  RelationalOperator: '<S333>/Compare'
     *  Switch: '<S330>/Switch'
     */
    if (rtb_DeadZone > 1.0E-6) {
      rtb_Switch2 /= rtb_DeadZone;
      rtb_DeadZone = rtb_Switch1 / rtb_DeadZone;
    } else {
      rtb_Switch2 = 1.0;
      rtb_DeadZone = 0.0;
    }

    /* End of Switch: '<S330>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_DeadZone, rtb_Switch2);
  } else {
    rtb_Add_oy = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S323>/Product2' incorporates:
   *  Constant: '<S323>/Constant'
   *  Switch: '<S320>/Speed_Switch'
   */
  rtb_Switch2_o = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S318>/Sign' */
  if (rtIsNaN(rtb_Switch2_o)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_o < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_o > 0.0);
  }

  /* Signum: '<S318>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S321>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S322>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S253>/Product' incorporates:
   *  Abs: '<S318>/Abs'
   *  Abs: '<S321>/Abs'
   *  Constant: '<S324>/Constant'
   *  Constant: '<S334>/Constant3'
   *  Constant: '<S334>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S318>/OR'
   *  Lookup_n-D: '<S321>/1-D Lookup Table'
   *  Math: '<S334>/Math Function'
   *  RelationalOperator: '<S318>/Equal1'
   *  RelationalOperator: '<S324>/Compare'
   *  Signum: '<S318>/Sign'
   *  Signum: '<S318>/Sign1'
   *  Sum: '<S321>/Add'
   *  Sum: '<S334>/Add1'
   *  Sum: '<S334>/Add2'
   */
  rtb_Switch2_o = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_o) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966, 3.1415926535897931) -
          1.5707963267948966), rtCP_uDLookupTable_bp01Data,
     rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S319>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2 = rtb_Switch2_o - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S326>/Sum1' incorporates:
   *  Constant: '<S319>/Constant2'
   *  Product: '<S326>/Product'
   *  Sum: '<S326>/Sum'
   *  UnitDelay: '<S326>/Unit Delay1'
   */
  rtb_DeadZone = ((rtb_Switch2 - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S319>/Product' incorporates:
   *  Constant: '<S319>/Constant3'
   */
  rtb_Switch1 = rtb_DeadZone * Drive_Motor_Control_D;

  /* Sum: '<S325>/Diff' incorporates:
   *  UnitDelay: '<S325>/UD'
   *
   * Block description for '<S325>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S325>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch1 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S319>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S319>/Add' incorporates:
   *  Gain: '<S319>/Gain'
   *  Gain: '<S319>/Gain1'
   *  Saturate: '<S319>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_o) +
                    (Drive_Motor_Control_P * rtb_Switch2)) + rtb_Add_oy;

  /* Saturate: '<S319>/Saturation2' incorporates:
   *  Sum: '<S319>/Add1'
   */
  if (rtb_Switch2_p2 > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch2_p2 < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_Switch2_p2;
  }

  /* End of Saturate: '<S319>/Saturation2' */

  /* Switch: '<S382>/Switch' */
  if (!rtb_Button_Spinup_Enable) {
    /* Switch: '<S382>/Switch' incorporates:
     *  Fcn: '<S383>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S382>/Switch' */

  /* Trigonometry: '<S268>/Cos4' incorporates:
   *  Switch: '<S257>/Angle_Switch'
   *  Trigonometry: '<S267>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S268>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S266>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S268>/Sin4' incorporates:
   *  Switch: '<S257>/Angle_Switch'
   *  Trigonometry: '<S267>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S268>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S266>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S268>/Subtract1' incorporates:
   *  Product: '<S268>/Product2'
   *  Product: '<S268>/Product3'
   *  Trigonometry: '<S268>/Cos4'
   *  Trigonometry: '<S268>/Sin4'
   */
  rtb_Switch2_p2 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S268>/Subtract' incorporates:
   *  Product: '<S268>/Product'
   *  Product: '<S268>/Product1'
   *  Trigonometry: '<S268>/Cos4'
   *  Trigonometry: '<S268>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S268>/Hypot' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Switch2, rtb_Switch2_p2);

  /* Switch: '<S268>/Switch' incorporates:
   *  Constant: '<S268>/Constant'
   *  Constant: '<S268>/Constant1'
   *  Constant: '<S269>/Constant'
   *  Product: '<S268>/Divide'
   *  Product: '<S268>/Divide1'
   *  RelationalOperator: '<S269>/Compare'
   *  Switch: '<S268>/Switch1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
    rtb_Switch2_o = rtb_Switch2_p2 / rtb_MatrixConcatenate_b_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Switch2_o = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S268>/Switch' */

  /* Product: '<S377>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S257>/Speed_Switch' incorporates:
   *  Abs: '<S257>/Abs'
   *  Constant: '<S265>/Constant'
   *  RelationalOperator: '<S265>/Compare'
   *  Switch: '<S257>/Angle_Switch'
   *  Trigonometry: '<S267>/Atan1'
   *  Trigonometry: '<S268>/Atan1'
   *  UnaryMinus: '<S257>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_o, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S267>/Subtract1' incorporates:
     *  Product: '<S267>/Product2'
     *  Product: '<S267>/Product3'
     *  UnaryMinus: '<S257>/Unary Minus'
     */
    rtb_Switch2_p2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S267>/Subtract' incorporates:
     *  Product: '<S267>/Product'
     *  Product: '<S267>/Product1'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Cos5) - (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Sin5);

    /* Math: '<S267>/Hypot' */
    rtb_Switch2 = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Switch2_p2);

    /* Switch: '<S267>/Switch1' incorporates:
     *  Constant: '<S267>/Constant'
     *  Constant: '<S267>/Constant1'
     *  Constant: '<S270>/Constant'
     *  Product: '<S267>/Divide'
     *  Product: '<S267>/Divide1'
     *  RelationalOperator: '<S270>/Compare'
     *  Switch: '<S267>/Switch'
     */
    if (rtb_Switch2 > 1.0E-6) {
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Switch2;
      rtb_Switch2_p2 /= rtb_Switch2;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = 1.0;
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S267>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Switch2_p2,
      rtb_MatrixConcatenate_b_idx_0);
  } else {
    rtb_Add_oy = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S260>/Product2' incorporates:
   *  Constant: '<S260>/Constant'
   *  Switch: '<S257>/Speed_Switch'
   */
  rtb_Switch2_o = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S255>/Sign' */
  if (rtIsNaN(rtb_Switch2_o)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_o < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_o > 0.0);
  }

  /* Signum: '<S255>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S258>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S259>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S250>/Product' incorporates:
   *  Abs: '<S255>/Abs'
   *  Abs: '<S258>/Abs'
   *  Constant: '<S261>/Constant'
   *  Constant: '<S271>/Constant3'
   *  Constant: '<S271>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S255>/OR'
   *  Lookup_n-D: '<S258>/1-D Lookup Table'
   *  Math: '<S271>/Math Function'
   *  RelationalOperator: '<S255>/Equal1'
   *  RelationalOperator: '<S261>/Compare'
   *  Signum: '<S255>/Sign'
   *  Signum: '<S255>/Sign1'
   *  Sum: '<S258>/Add'
   *  Sum: '<S271>/Add1'
   *  Sum: '<S271>/Add2'
   */
  rtb_Switch2_o = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_o) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S256>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_o -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S263>/Sum1' incorporates:
   *  Constant: '<S256>/Constant2'
   *  Product: '<S263>/Product'
   *  Sum: '<S263>/Sum'
   *  UnitDelay: '<S263>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_MatrixConcatenate_b_idx_0 -
                     Robot_Control_DW.UnitDelay1_DSTATE_f) *
                    Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S256>/Product' incorporates:
   *  Constant: '<S256>/Constant3'
   */
  rtb_Switch2 = rtb_Switch2_p2 * Drive_Motor_Control_D;

  /* Sum: '<S262>/Diff' incorporates:
   *  UnitDelay: '<S262>/UD'
   *
   * Block description for '<S262>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S262>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S256>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S256>/Add' incorporates:
   *  Gain: '<S256>/Gain'
   *  Gain: '<S256>/Gain1'
   *  Saturate: '<S256>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_o) +
    (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_oy;

  /* Saturate: '<S256>/Saturation2' incorporates:
   *  Sum: '<S256>/Add1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S256>/Saturation2' */

  /* Sum: '<S272>/Add1' incorporates:
   *  Constant: '<S272>/Constant3'
   *  Constant: '<S272>/Constant4'
   *  Math: '<S272>/Math Function'
   *  Sum: '<S272>/Add2'
   */
  rtb_Switch2_o = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S274>/Sum1' incorporates:
   *  Constant: '<S259>/Constant2'
   *  Product: '<S274>/Product'
   *  Sum: '<S274>/Sum'
   *  UnitDelay: '<S274>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((rtb_Switch2_o -
    Robot_Control_DW.UnitDelay1_DSTATE_b) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S259>/Product' incorporates:
   *  Constant: '<S259>/Constant3'
   */
  rtb_Switch2_i = rtb_MatrixConcatenate_b_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S273>/Diff' incorporates:
   *  UnitDelay: '<S273>/UD'
   *
   * Block description for '<S273>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S273>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch2_i - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S259>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S259>/Add' incorporates:
   *  Gain: '<S259>/Gain1'
   *  Saturate: '<S259>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P * rtb_Switch2_o) +
    rtb_Add_oy;

  /* Sum: '<S259>/Subtract' incorporates:
   *  Constant: '<S259>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S259>/Sum2' incorporates:
   *  Gain: '<S259>/Gain2'
   *  UnitDelay: '<S259>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Switch2_o) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S275>/Switch2' incorporates:
   *  Constant: '<S259>/Constant'
   *  RelationalOperator: '<S275>/LowerRelop1'
   *  Sum: '<S259>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S275>/Switch' incorporates:
     *  Constant: '<S259>/Constant1'
     *  RelationalOperator: '<S275>/UpperRelop'
     *  Sum: '<S259>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S275>/Switch' */
  }

  /* End of Switch: '<S275>/Switch2' */

  /* Saturate: '<S259>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S259>/Saturation1' */

  /* Sum: '<S259>/Add1' */
  rtb_Add_oy = rtb_MatrixConcatenate_idx_0 + rtb_Sum2_e;

  /* Saturate: '<S259>/Saturation2' */
  if (rtb_Add_oy > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_oy < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_oy;
  }

  /* End of Saturate: '<S259>/Saturation2' */

  /* Switch: '<S387>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S387>/Switch' incorporates:
     *  Fcn: '<S388>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S387>/Switch' */

  /* Trigonometry: '<S289>/Cos4' incorporates:
   *  Switch: '<S278>/Angle_Switch'
   *  Trigonometry: '<S288>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S289>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S287>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S289>/Sin4' incorporates:
   *  Switch: '<S278>/Angle_Switch'
   *  Trigonometry: '<S288>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S289>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S287>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S289>/Subtract1' incorporates:
   *  Product: '<S289>/Product2'
   *  Product: '<S289>/Product3'
   *  Trigonometry: '<S289>/Cos4'
   *  Trigonometry: '<S289>/Sin4'
   */
  rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S289>/Subtract' incorporates:
   *  Product: '<S289>/Product'
   *  Product: '<S289>/Product1'
   *  Trigonometry: '<S289>/Cos4'
   *  Trigonometry: '<S289>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S289>/Hypot' */
  rtb_Hypot_bl = rt_hypotd_snf(rtb_Subtract1_la, rtb_MatrixConcatenate_idx_0);

  /* Switch: '<S289>/Switch' incorporates:
   *  Constant: '<S289>/Constant'
   *  Constant: '<S289>/Constant1'
   *  Constant: '<S290>/Constant'
   *  Product: '<S289>/Divide'
   *  Product: '<S289>/Divide1'
   *  RelationalOperator: '<S290>/Compare'
   *  Switch: '<S289>/Switch1'
   */
  if (rtb_Hypot_bl > 1.0E-6) {
    rtb_Switch2_o = rtb_MatrixConcatenate_idx_0 / rtb_Hypot_bl;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_bl;
  } else {
    rtb_Switch2_o = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S289>/Switch' */

  /* Product: '<S377>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S278>/Speed_Switch' incorporates:
   *  Abs: '<S278>/Abs'
   *  Constant: '<S286>/Constant'
   *  RelationalOperator: '<S286>/Compare'
   *  Switch: '<S278>/Angle_Switch'
   *  Trigonometry: '<S288>/Atan1'
   *  Trigonometry: '<S289>/Atan1'
   *  UnaryMinus: '<S278>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_o, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S288>/Subtract1' incorporates:
     *  Product: '<S288>/Product2'
     *  Product: '<S288>/Product3'
     *  UnaryMinus: '<S278>/Unary Minus'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_m) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S288>/Subtract' incorporates:
     *  Product: '<S288>/Product'
     *  Product: '<S288>/Product1'
     */
    rtb_Hypot_bl = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S288>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_bl, rtb_MatrixConcatenate_idx_0);

    /* Switch: '<S288>/Switch1' incorporates:
     *  Constant: '<S288>/Constant'
     *  Constant: '<S288>/Constant1'
     *  Constant: '<S291>/Constant'
     *  Product: '<S288>/Divide'
     *  Product: '<S288>/Divide1'
     *  RelationalOperator: '<S291>/Compare'
     *  Switch: '<S288>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_bl /= rtb_Subtract1_la;
      rtb_MatrixConcatenate_idx_0 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_bl = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S288>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0, rtb_Hypot_bl);
  } else {
    rtb_Add_oy = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S281>/Product2' incorporates:
   *  Constant: '<S281>/Constant'
   *  Switch: '<S278>/Speed_Switch'
   */
  rtb_Switch2_o = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S276>/Sign' */
  if (rtIsNaN(rtb_Switch2_o)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_o < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_o > 0.0);
  }

  /* Signum: '<S276>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S279>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S280>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S251>/Product' incorporates:
   *  Abs: '<S276>/Abs'
   *  Abs: '<S279>/Abs'
   *  Constant: '<S282>/Constant'
   *  Constant: '<S292>/Constant3'
   *  Constant: '<S292>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S276>/OR'
   *  Lookup_n-D: '<S279>/1-D Lookup Table'
   *  Math: '<S292>/Math Function'
   *  RelationalOperator: '<S276>/Equal1'
   *  RelationalOperator: '<S282>/Compare'
   *  Signum: '<S276>/Sign'
   *  Signum: '<S276>/Sign1'
   *  Sum: '<S279>/Add'
   *  Sum: '<S292>/Add1'
   *  Sum: '<S292>/Add2'
   */
  rtb_Switch2_o = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_o) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_gs, 1U);

  /* Sum: '<S277>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_bl = rtb_Switch2_o - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S284>/Sum1' incorporates:
   *  Constant: '<S277>/Constant2'
   *  Product: '<S284>/Product'
   *  Sum: '<S284>/Sum'
   *  UnitDelay: '<S284>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Hypot_bl -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S277>/Product' incorporates:
   *  Constant: '<S277>/Constant3'
   */
  rtb_Subtract1_la = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S283>/Diff' incorporates:
   *  UnitDelay: '<S283>/UD'
   *
   * Block description for '<S283>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S283>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S277>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S277>/Add' incorporates:
   *  Gain: '<S277>/Gain'
   *  Gain: '<S277>/Gain1'
   *  Saturate: '<S277>/Saturation'
   */
  rtb_Hypot_bl = ((Drive_Motor_Control_FF * rtb_Switch2_o) +
                  (Drive_Motor_Control_P * rtb_Hypot_bl)) + rtb_Add_oy;

  /* Saturate: '<S277>/Saturation2' incorporates:
   *  Sum: '<S277>/Add1'
   */
  if (rtb_Hypot_bl > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Hypot_bl < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = rtb_Hypot_bl;
  }

  /* End of Saturate: '<S277>/Saturation2' */

  /* Sum: '<S293>/Add1' incorporates:
   *  Constant: '<S293>/Constant3'
   *  Constant: '<S293>/Constant4'
   *  Math: '<S293>/Math Function'
   *  Sum: '<S293>/Add2'
   */
  rtb_Switch2_o = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S295>/Sum1' incorporates:
   *  Constant: '<S280>/Constant2'
   *  Product: '<S295>/Product'
   *  Sum: '<S295>/Sum'
   *  UnitDelay: '<S295>/Unit Delay1'
   */
  rtb_Hypot_bl = ((rtb_Switch2_o - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S280>/Product' incorporates:
   *  Constant: '<S280>/Constant3'
   */
  rtb_Switch2_ee = rtb_Hypot_bl * Steering_Motor_Control_D;

  /* Sum: '<S294>/Diff' incorporates:
   *  UnitDelay: '<S294>/UD'
   *
   * Block description for '<S294>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S294>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch2_ee - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S280>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S280>/Add' incorporates:
   *  Gain: '<S280>/Gain1'
   *  Saturate: '<S280>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_o) + rtb_Add_oy;

  /* Sum: '<S280>/Subtract' incorporates:
   *  Constant: '<S280>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S280>/Sum2' incorporates:
   *  Gain: '<S280>/Gain2'
   *  UnitDelay: '<S280>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_Switch2_o) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S296>/Switch2' incorporates:
   *  Constant: '<S280>/Constant'
   *  RelationalOperator: '<S296>/LowerRelop1'
   *  Sum: '<S280>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S296>/Switch' incorporates:
     *  Constant: '<S280>/Constant1'
     *  RelationalOperator: '<S296>/UpperRelop'
     *  Sum: '<S280>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S296>/Switch' */
  }

  /* End of Switch: '<S296>/Switch2' */

  /* Saturate: '<S280>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S280>/Saturation1' */

  /* Sum: '<S280>/Add1' */
  rtb_Add_oy = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S280>/Saturation2' */
  if (rtb_Add_oy > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_oy < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_oy;
  }

  /* End of Saturate: '<S280>/Saturation2' */

  /* Switch: '<S392>/Switch' */
  if (!rtb_Button_Shoot_Enable) {
    /* Switch: '<S392>/Switch' incorporates:
     *  Fcn: '<S393>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S392>/Switch' */

  /* Trigonometry: '<S310>/Cos4' incorporates:
   *  Switch: '<S299>/Angle_Switch'
   *  Trigonometry: '<S309>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S310>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S308>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S310>/Sin4' incorporates:
   *  Switch: '<S299>/Angle_Switch'
   *  Trigonometry: '<S309>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S310>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S308>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S310>/Subtract1' incorporates:
   *  Product: '<S310>/Product2'
   *  Product: '<S310>/Product3'
   *  Trigonometry: '<S310>/Cos4'
   *  Trigonometry: '<S310>/Sin4'
   */
  rtb_Switch2_o = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S310>/Subtract' incorporates:
   *  Product: '<S310>/Product'
   *  Product: '<S310>/Product1'
   *  Trigonometry: '<S310>/Cos4'
   *  Trigonometry: '<S310>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S310>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_o);

  /* Switch: '<S310>/Switch' incorporates:
   *  Constant: '<S310>/Constant'
   *  Constant: '<S310>/Constant1'
   *  Constant: '<S311>/Constant'
   *  Product: '<S310>/Divide'
   *  Product: '<S310>/Divide1'
   *  RelationalOperator: '<S311>/Compare'
   *  Switch: '<S310>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Switch2_o /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_o = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S310>/Switch' */

  /* Product: '<S377>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S299>/Speed_Switch' incorporates:
   *  Abs: '<S299>/Abs'
   *  Constant: '<S307>/Constant'
   *  RelationalOperator: '<S307>/Compare'
   *  Switch: '<S299>/Angle_Switch'
   *  Trigonometry: '<S309>/Atan1'
   *  Trigonometry: '<S310>/Atan1'
   *  UnaryMinus: '<S299>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_o, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S309>/Subtract1' incorporates:
     *  Product: '<S309>/Product2'
     *  Product: '<S309>/Product3'
     *  UnaryMinus: '<S299>/Unary Minus'
     */
    rtb_Switch2_o = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S309>/Subtract' incorporates:
     *  Product: '<S309>/Product'
     *  Product: '<S309>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S309>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_o);

    /* Switch: '<S309>/Switch1' incorporates:
     *  Constant: '<S309>/Constant'
     *  Constant: '<S309>/Constant1'
     *  Constant: '<S312>/Constant'
     *  Product: '<S309>/Divide'
     *  Product: '<S309>/Divide1'
     *  RelationalOperator: '<S312>/Compare'
     *  Switch: '<S309>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_Switch2_o /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Switch2_o = 0.0;
    }

    /* End of Switch: '<S309>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Switch2_o,
      rtb_uDLookupTable);
  } else {
    rtb_Add_oy = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S302>/Product2' incorporates:
   *  Constant: '<S302>/Constant'
   *  Switch: '<S299>/Speed_Switch'
   */
  rtb_Init = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S297>/Sign' */
  if (rtIsNaN(rtb_Init)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Init < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Init > 0.0);
  }

  /* Signum: '<S297>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S300>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S301>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S252>/Product' incorporates:
   *  Abs: '<S297>/Abs'
   *  Abs: '<S300>/Abs'
   *  Constant: '<S303>/Constant'
   *  Constant: '<S313>/Constant3'
   *  Constant: '<S313>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S297>/OR'
   *  Lookup_n-D: '<S300>/1-D Lookup Table'
   *  Math: '<S313>/Math Function'
   *  RelationalOperator: '<S297>/Equal1'
   *  RelationalOperator: '<S303>/Compare'
   *  Signum: '<S297>/Sign'
   *  Signum: '<S297>/Sign1'
   *  Sum: '<S300>/Add'
   *  Sum: '<S313>/Add1'
   *  Sum: '<S313>/Add2'
   */
  rtb_Init = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init) * look1_binlcpw(fabs
    (rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                 3.1415926535897931) - 1.5707963267948966),
    rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S298>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_o = rtb_Init - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S305>/Sum1' incorporates:
   *  Constant: '<S298>/Constant2'
   *  Product: '<S305>/Product'
   *  Sum: '<S305>/Sum'
   *  UnitDelay: '<S305>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_Switch2_o - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S298>/Product' incorporates:
   *  Constant: '<S298>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S304>/Diff' incorporates:
   *  UnitDelay: '<S304>/UD'
   *
   * Block description for '<S304>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S304>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S298>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S298>/Add' incorporates:
   *  Gain: '<S298>/Gain'
   *  Gain: '<S298>/Gain1'
   *  Saturate: '<S298>/Saturation'
   */
  rtb_Init = ((Drive_Motor_Control_FF * rtb_Init) + (Drive_Motor_Control_P *
    rtb_Switch2_o)) + rtb_Add_oy;

  /* Saturate: '<S298>/Saturation2' incorporates:
   *  Sum: '<S298>/Add1'
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

  /* End of Saturate: '<S298>/Saturation2' */

  /* Sum: '<S314>/Add1' incorporates:
   *  Constant: '<S314>/Constant3'
   *  Constant: '<S314>/Constant4'
   *  Math: '<S314>/Math Function'
   *  Sum: '<S314>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S316>/Sum1' incorporates:
   *  Constant: '<S301>/Constant2'
   *  Product: '<S316>/Product'
   *  Sum: '<S316>/Sum'
   *  UnitDelay: '<S316>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Init -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S301>/Product' incorporates:
   *  Constant: '<S301>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S315>/Diff' incorporates:
   *  UnitDelay: '<S315>/UD'
   *
   * Block description for '<S315>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S315>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S301>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S301>/Add' incorporates:
   *  Gain: '<S301>/Gain1'
   *  Saturate: '<S301>/Saturation'
   */
  rtb_Add_ec = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_oy;

  /* Sum: '<S301>/Subtract' incorporates:
   *  Constant: '<S301>/Constant'
   */
  rtb_Switch2_o = 1.0 - rtb_Add_ec;

  /* Sum: '<S301>/Sum2' incorporates:
   *  Gain: '<S301>/Gain2'
   *  UnitDelay: '<S301>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S317>/Switch2' incorporates:
   *  Constant: '<S301>/Constant'
   *  RelationalOperator: '<S317>/LowerRelop1'
   *  Sum: '<S301>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_ec))) {
    /* Sum: '<S301>/Subtract1' incorporates:
     *  Constant: '<S301>/Constant1'
     */
    rtb_Switch2_o = -1.0 - rtb_Add_ec;

    /* Switch: '<S317>/Switch' incorporates:
     *  Constant: '<S301>/Constant1'
     *  RelationalOperator: '<S317>/UpperRelop'
     *  Sum: '<S301>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_ec))) {
      rtb_Switch2_o = rtb_Init;
    }

    /* End of Switch: '<S317>/Switch' */
  }

  /* End of Switch: '<S317>/Switch2' */

  /* Saturate: '<S301>/Saturation1' */
  if (rtb_Switch2_o > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_o < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Switch2_o;
  }

  /* End of Saturate: '<S301>/Saturation1' */

  /* Sum: '<S301>/Add1' */
  rtb_Add_oy = rtb_Add_ec + rtb_Integral_ga;

  /* Saturate: '<S301>/Saturation2' */
  if (rtb_Add_oy > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_oy < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_oy;
  }

  /* End of Saturate: '<S301>/Saturation2' */

  /* Sum: '<S335>/Add1' incorporates:
   *  Constant: '<S335>/Constant3'
   *  Constant: '<S335>/Constant4'
   *  Math: '<S335>/Math Function'
   *  Sum: '<S335>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Integral_d + 3.1415926535897931, 6.2831853071795862)
    - 3.1415926535897931;

  /* Sum: '<S337>/Sum1' incorporates:
   *  Constant: '<S322>/Constant2'
   *  Product: '<S337>/Product'
   *  Sum: '<S337>/Sum'
   *  UnitDelay: '<S337>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_i)
    * Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S322>/Product' incorporates:
   *  Constant: '<S322>/Constant3'
   */
  rtb_Add_ec = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S336>/Diff' incorporates:
   *  UnitDelay: '<S336>/UD'
   *
   * Block description for '<S336>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S336>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Add_ec - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S322>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S322>/Add' incorporates:
   *  Gain: '<S322>/Gain1'
   *  Saturate: '<S322>/Saturation'
   */
  rtb_Add_os = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_oy;

  /* Sum: '<S322>/Subtract' incorporates:
   *  Constant: '<S322>/Constant'
   */
  rtb_Switch2_o = 1.0 - rtb_Add_os;

  /* Sum: '<S322>/Sum2' incorporates:
   *  Gain: '<S322>/Gain2'
   *  UnitDelay: '<S322>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S338>/Switch2' incorporates:
   *  Constant: '<S322>/Constant'
   *  RelationalOperator: '<S338>/LowerRelop1'
   *  Sum: '<S322>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_os))) {
    /* Sum: '<S322>/Subtract1' incorporates:
     *  Constant: '<S322>/Constant1'
     */
    rtb_Switch2_o = -1.0 - rtb_Add_os;

    /* Switch: '<S338>/Switch' incorporates:
     *  Constant: '<S322>/Constant1'
     *  RelationalOperator: '<S338>/UpperRelop'
     *  Sum: '<S322>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_os))) {
      rtb_Switch2_o = rtb_Init;
    }

    /* End of Switch: '<S338>/Switch' */
  }

  /* End of Switch: '<S338>/Switch2' */

  /* Saturate: '<S322>/Saturation1' */
  if (rtb_Switch2_o > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_o < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Switch2_o;
  }

  /* End of Saturate: '<S322>/Saturation1' */

  /* Sum: '<S322>/Add1' */
  rtb_Add_oy = rtb_Add_os + rtb_Integral_bj;

  /* Saturate: '<S322>/Saturation2' */
  if (rtb_Add_oy > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_oy < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_oy;
  }

  /* End of Saturate: '<S322>/Saturation2' */

  /* Sum: '<S185>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S135>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S187>/Sum1' incorporates:
   *  Constant: '<S185>/Constant2'
   *  Product: '<S187>/Product'
   *  Sum: '<S185>/Sum'
   *  Sum: '<S187>/Sum'
   *  UnitDelay: '<S187>/Unit Delay1'
   */
  rtb_Add_os = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S185>/Product' incorporates:
   *  Constant: '<S185>/Constant3'
   */
  rtb_Product_lo = rtb_Add_os * 0.0;

  /* Sum: '<S186>/Diff' incorporates:
   *  UnitDelay: '<S186>/UD'
   *
   * Block description for '<S186>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S186>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S185>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S185>/Add' incorporates:
   *  Gain: '<S185>/Gain'
   *  Gain: '<S185>/Gain1'
   *  Saturate: '<S185>/Saturation'
   *  Sum: '<S185>/Sum'
   */
  rtb_Init = ((Rebuilt_Transfer_Motor_Gain_FF *
               Robot_Control_B.RB_Desired_Transfer_Speed) +
              (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_oy;

  /* Logic: '<S135>/Logical Operator1' incorporates:
   *  Constant: '<S184>/Constant'
   *  RelationalOperator: '<S184>/Compare'
   */
  rtb_Button_Shoot_Enable = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S135>/Switch1' incorporates:
   *  Abs: '<S135>/Abs'
   *  Constant: '<S135>/Constant1'
   *  Constant: '<S135>/Constant2'
   *  Logic: '<S135>/Logical Operator'
   *  Logic: '<S135>/Logical Operator1'
   *  RelationalOperator: '<S135>/LessThan'
   *  UnitDelay: '<S135>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Button_Shoot_Enable) {
    rtb_Button_Spinup_Enable = true;
  } else {
    rtb_Button_Spinup_Enable = (rtb_Button_Shoot_Enable &&
      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S135>/Switch1' */

  /* Switch: '<S185>/Switch' incorporates:
   *  Constant: '<S185>/Constant4'
   */
  if (rtb_Button_Spinup_Enable) {
    /* Sum: '<S185>/Sum2' incorporates:
     *  Gain: '<S185>/Gain2'
     *  Sum: '<S185>/Sum'
     *  UnitDelay: '<S185>/Unit Delay'
     */
    rtb_Switch2_o = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S185>/Subtract' incorporates:
     *  Constant: '<S185>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Init;

    /* Switch: '<S188>/Switch2' incorporates:
     *  Constant: '<S185>/Constant'
     *  RelationalOperator: '<S188>/LowerRelop1'
     *  Sum: '<S185>/Subtract'
     */
    if (!(rtb_Switch2_o > (1.0 - rtb_Init))) {
      /* Sum: '<S185>/Subtract1' incorporates:
       *  Constant: '<S185>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Init;

      /* Switch: '<S188>/Switch' incorporates:
       *  Constant: '<S185>/Constant1'
       *  RelationalOperator: '<S188>/UpperRelop'
       *  Sum: '<S185>/Subtract1'
       */
      if (!(rtb_Switch2_o < (-1.0 - rtb_Init))) {
        rtb_Integral_d = rtb_Switch2_o;
      }

      /* End of Switch: '<S188>/Switch' */
    }

    /* End of Switch: '<S188>/Switch2' */

    /* Saturate: '<S185>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S185>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S185>/Switch' */

  /* Switch: '<S135>/Switch2' incorporates:
   *  Logic: '<S135>/Logical Operator1'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S185>/Add1' */
    rtb_Add_oy = rtb_Init + rtb_Integral_d;

    /* Saturate: '<S185>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S135>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S135>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S135>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S185>/Saturation2' */
  } else {
    /* Switch: '<S135>/Switch2' incorporates:
     *  Constant: '<S135>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S135>/Switch2' */

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
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
  } else {
    /* Outport: '<Root>/Transfer_Motor_DC' */
    Robot_Control_Y.Transfer_Motor_DC = Robot_Control_B.RB_Transfer_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S10>/Constant8'
     */
    Robot_Control_Y.Desired_Hood_Enable = true;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Product: '<S12>/Product' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Add_oy = Robot_Control_B.RB_Desired_Feeder_Speed *
    Rebuilt_Feeder_Motor_Gain_FF;

  /* Saturate: '<S12>/Saturation' */
  if (rtb_Add_oy > 1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = 1.0;
  } else if (rtb_Add_oy < -1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = -1.0;
  } else {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = rtb_Add_oy;
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant6'
   *  Switch: '<S10>/Switch5'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Feeder_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    Robot_Control_Y.Feeder_Motor_DC = TEST_Feeder_Motor_DC_OV;
    rtb_Init = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;
    rtb_Init = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch1' */

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

  /* Switch: '<S127>/Init' incorporates:
   *  UnitDelay: '<S127>/FixPt Unit Delay1'
   *  UnitDelay: '<S127>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Switch2_o = rtb_Init;
  } else {
    rtb_Switch2_o = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S127>/Init' */

  /* Sum: '<S125>/Sum1' */
  rtb_Init -= rtb_Switch2_o;

  /* Switch: '<S126>/Switch2' incorporates:
   *  Constant: '<S124>/Constant1'
   *  Constant: '<S124>/Constant3'
   *  RelationalOperator: '<S126>/LowerRelop1'
   *  RelationalOperator: '<S126>/UpperRelop'
   *  Switch: '<S126>/Switch'
   */
  if (rtb_Init > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Init < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S124>/Constant1'
     */
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S126>/Switch2' */

  /* Sum: '<S125>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Init + rtb_Switch2_o;

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

  /* Logic: '<S53>/Logical Operator1' incorporates:
   *  Constant: '<S65>/Constant'
   *  RelationalOperator: '<S65>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Init == 0.0);

  /* Sum: '<S66>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S53>/Subtract'
   */
  rtb_Error_n = rtb_Init - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S68>/Sum1' incorporates:
   *  Constant: '<S66>/Constant2'
   *  Product: '<S68>/Product'
   *  Sum: '<S66>/Sum'
   *  Sum: '<S68>/Sum'
   *  UnitDelay: '<S68>/Unit Delay1'
   */
  rtb_Sum1_fh = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S66>/Product' incorporates:
   *  Constant: '<S66>/Constant3'
   */
  rtb_Product_hm = rtb_Sum1_fh * 0.0;

  /* Sum: '<S67>/Diff' incorporates:
   *  UnitDelay: '<S67>/UD'
   *
   * Block description for '<S67>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S67>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_hm - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S66>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S66>/Add' incorporates:
   *  Gain: '<S66>/Gain'
   *  Gain: '<S66>/Gain1'
   *  Saturate: '<S66>/Saturation'
   *  Sum: '<S66>/Sum'
   */
  rtb_Switch2_o = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Init) +
                   (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_oy;

  /* Switch: '<S53>/Switch1' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S53>/Constant1'
   *  Constant: '<S53>/Constant2'
   *  Logic: '<S53>/Logical Operator'
   *  Logic: '<S53>/Logical Operator1'
   *  RelationalOperator: '<S53>/LessThan'
   *  UnitDelay: '<S53>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Button_Shoot_Enable = true;
  } else {
    rtb_Button_Shoot_Enable = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S53>/Switch1' */

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Constant4'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S66>/Sum2' incorporates:
     *  Gain: '<S66>/Gain2'
     *  Sum: '<S66>/Sum'
     *  UnitDelay: '<S66>/Unit Delay'
     */
    rtb_Init = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S66>/Subtract' incorporates:
     *  Constant: '<S66>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Switch2_o;

    /* Switch: '<S69>/Switch2' incorporates:
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S69>/LowerRelop1'
     *  Sum: '<S66>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Switch2_o))) {
      /* Sum: '<S66>/Subtract1' incorporates:
       *  Constant: '<S66>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Switch2_o;

      /* Switch: '<S69>/Switch' incorporates:
       *  Constant: '<S66>/Constant1'
       *  RelationalOperator: '<S69>/UpperRelop'
       *  Sum: '<S66>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Switch2_o))) {
        rtb_Error_n = rtb_Init;
      }

      /* End of Switch: '<S69>/Switch' */
    }

    /* End of Switch: '<S69>/Switch2' */

    /* Saturate: '<S66>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Error_n = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Error_n = -0.1;
    }

    /* End of Saturate: '<S66>/Saturation1' */
  } else {
    rtb_Error_n = 0.0;
  }

  /* End of Switch: '<S66>/Switch' */

  /* Switch: '<S53>/Switch2' incorporates:
   *  Logic: '<S53>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S66>/Add1' */
    rtb_Add_oy = rtb_Switch2_o + rtb_Error_n;

    /* Saturate: '<S66>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S53>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S53>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S53>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S66>/Saturation2' */
  } else {
    /* Switch: '<S53>/Switch2' incorporates:
     *  Constant: '<S53>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S53>/Switch2' */

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

  /* Sum: '<S48>/Add1' incorporates:
   *  Constant: '<S48>/Constant3'
   *  Constant: '<S48>/Constant4'
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Math: '<S48>/Math Function'
   *  Sum: '<S48>/Add2'
   */
  Robot_Control_B.RB_Intake_Arm_Angle_Mod = rt_modd_snf
    (Robot_Control_U.Measured_Intake_Arm_Angle + 180.0, 360.0) - 180.0;

  /* Chart: '<S6>/Chart' incorporates:
   *  RelationalOperator: '<S50>/FixPt Relational Operator'
   *  UnitDelay: '<S50>/Delay Input1'
   *
   * Block description for '<S50>/Delay Input1':
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

  /* Switch: '<S64>/Init' incorporates:
   *  UnitDelay: '<S64>/FixPt Unit Delay1'
   *  UnitDelay: '<S64>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S64>/Init' */

  /* Sum: '<S62>/Sum1' */
  rtb_Switch2_o = Robot_Control_B.RB_Des_Intake_Arm_Angle - rtb_Init;

  /* Switch: '<S63>/Switch2' incorporates:
   *  Constant: '<S52>/Constant1'
   *  Constant: '<S52>/Constant3'
   *  RelationalOperator: '<S63>/LowerRelop1'
   *  RelationalOperator: '<S63>/UpperRelop'
   *  Switch: '<S63>/Switch'
   */
  if (rtb_Switch2_o > Rebuilt_Intake_RL_Inc) {
    rtb_Switch2_o = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Switch2_o < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    rtb_Switch2_o = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S63>/Switch2' */

  /* Sum: '<S62>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Switch2_o + rtb_Init;

  /* Sum: '<S58>/Sum' */
  rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S60>/Sum1' incorporates:
   *  Constant: '<S58>/Constant2'
   *  Product: '<S60>/Product'
   *  Sum: '<S60>/Sum'
   *  UnitDelay: '<S60>/Unit Delay1'
   */
  rtb_Sum1_dj = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S58>/Product' incorporates:
   *  Constant: '<S58>/Constant3'
   */
  rtb_Product_ov = rtb_Sum1_dj * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S59>/Diff' incorporates:
   *  UnitDelay: '<S59>/UD'
   *
   * Block description for '<S59>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S59>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_ov - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S58>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S58>/Add' incorporates:
   *  Gain: '<S58>/Gain'
   *  Gain: '<S58>/Gain1'
   *  Saturate: '<S58>/Saturation'
   */
  rtb_Add_ir = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
                (Rebuilt_Intake_Arm_Gain_P * rtb_Init)) + rtb_Add_oy;

  /* Sum: '<S58>/Subtract' incorporates:
   *  Constant: '<S58>/Constant'
   */
  rtb_Switch2_o = 1.0 - rtb_Add_ir;

  /* Sum: '<S58>/Sum2' incorporates:
   *  Gain: '<S58>/Gain2'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  rtb_Init = (0.0 * rtb_Init) + Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S61>/Switch2' incorporates:
   *  Constant: '<S58>/Constant'
   *  RelationalOperator: '<S61>/LowerRelop1'
   *  Sum: '<S58>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_ir))) {
    /* Sum: '<S58>/Subtract1' incorporates:
     *  Constant: '<S58>/Constant1'
     */
    rtb_Switch2_o = -1.0 - rtb_Add_ir;

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S58>/Constant1'
     *  RelationalOperator: '<S61>/UpperRelop'
     *  Sum: '<S58>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_ir))) {
      rtb_Switch2_o = rtb_Init;
    }

    /* End of Switch: '<S61>/Switch' */
  }

  /* End of Switch: '<S61>/Switch2' */

  /* Saturate: '<S58>/Saturation1' */
  if (rtb_Switch2_o > 0.1) {
    rtb_Switch2_o = 0.1;
  } else if (rtb_Switch2_o < -0.1) {
    rtb_Switch2_o = -0.1;
  }

  /* End of Saturate: '<S58>/Saturation1' */

  /* Switch: '<S51>/Switch2' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant'
   *  Logic: '<S51>/Logical Operator1'
   *  Logic: '<S51>/Logical Operator2'
   *  Logic: '<S51>/Logical Operator3'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S55>/Compare'
   *  RelationalOperator: '<S56>/Compare'
   *  RelationalOperator: '<S57>/Compare'
   */
  if (((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_In) && (Robot_Control_B.RB_Intake_Arm_Angle_Mod
        <= Rebuilt_Intake_Meas_In_Disable)) ||
      ((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_Out) &&
       (Robot_Control_B.RB_Intake_Arm_Angle_Mod >=
        Rebuilt_Intake_Meas_Out_Disable))) {
    /* Switch: '<S51>/Switch2' incorporates:
     *  Constant: '<S51>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  } else {
    /* Sum: '<S58>/Add1' */
    rtb_Add_oy = rtb_Add_ir + rtb_Switch2_o;

    /* Saturate: '<S58>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S51>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S51>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S51>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S58>/Saturation2' */
  }

  /* End of Switch: '<S51>/Switch2' */

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

  /* Logic: '<S133>/Logical Operator1' incorporates:
   *  Constant: '<S179>/Constant'
   *  RelationalOperator: '<S179>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S180>/Sum' incorporates:
   *  Sum: '<S133>/Subtract'
   */
  rtb_Init = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S182>/Sum1' incorporates:
   *  Constant: '<S180>/Constant2'
   *  Product: '<S182>/Product'
   *  Sum: '<S180>/Sum'
   *  Sum: '<S182>/Sum'
   *  UnitDelay: '<S182>/Unit Delay1'
   */
  rtb_Add_ir = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S180>/Product' incorporates:
   *  Constant: '<S180>/Constant3'
   */
  rtb_Product_i = rtb_Add_ir * 0.0;

  /* Sum: '<S181>/Diff' incorporates:
   *  UnitDelay: '<S181>/UD'
   *
   * Block description for '<S181>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S181>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_i - Robot_Control_DW.UD_DSTATE_kz;

  /* Saturate: '<S180>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S180>/Add' incorporates:
   *  Gain: '<S180>/Gain'
   *  Gain: '<S180>/Gain1'
   *  Saturate: '<S180>/Saturation'
   *  Sum: '<S180>/Sum'
   */
  rtb_Add_oy += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Init);

  /* Switch: '<S133>/Switch4' incorporates:
   *  Constant: '<S133>/Constant6'
   *  Constant: '<S133>/Constant7'
   *  Logic: '<S133>/Logical Operator1'
   *  Logic: '<S133>/Logical Operator2'
   *  RelationalOperator: '<S133>/LessThan2'
   *  UnitDelay: '<S133>/Unit Delay1'
   */
  if ((rtb_Init < 0.0) && rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay1_DSTATE_ea));
  }

  /* End of Switch: '<S133>/Switch4' */

  /* Switch: '<S133>/Switch1' incorporates:
   *  Constant: '<S133>/Constant1'
   *  Constant: '<S133>/Constant2'
   *  Logic: '<S133>/Logical Operator'
   *  Logic: '<S133>/Logical Operator1'
   *  RelationalOperator: '<S133>/LessThan'
   *  UnitDelay: '<S133>/Unit Delay'
   */
  if ((rtb_Init < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S133>/Switch1' */

  /* Switch: '<S180>/Switch' incorporates:
   *  Constant: '<S180>/Constant4'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S180>/Sum2' incorporates:
     *  Gain: '<S180>/Gain2'
     *  Product: '<S180>/Product1'
     *  Sum: '<S180>/Sum'
     *  Switch: '<S180>/Switch1'
     *  UnitDelay: '<S180>/Unit Delay'
     */
    rtb_Init = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Init) * ((real_T)
      (!rtb_Intake_Arm_Move_In))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S180>/Subtract' incorporates:
     *  Constant: '<S180>/Constant'
     */
    rtb_Error_c5 = 1.0 - rtb_Add_oy;

    /* Switch: '<S183>/Switch2' incorporates:
     *  Constant: '<S180>/Constant'
     *  RelationalOperator: '<S183>/LowerRelop1'
     *  Sum: '<S180>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Add_oy))) {
      /* Sum: '<S180>/Subtract1' incorporates:
       *  Constant: '<S180>/Constant1'
       */
      rtb_Error_c5 = -1.0 - rtb_Add_oy;

      /* Switch: '<S183>/Switch' incorporates:
       *  Constant: '<S180>/Constant1'
       *  RelationalOperator: '<S183>/UpperRelop'
       *  Sum: '<S180>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Add_oy))) {
        rtb_Error_c5 = rtb_Init;
      }

      /* End of Switch: '<S183>/Switch' */
    }

    /* End of Switch: '<S183>/Switch2' */

    /* Saturate: '<S180>/Saturation1' */
    if (rtb_Error_c5 > 0.1) {
      rtb_Init = 0.1;
    } else if (rtb_Error_c5 < -0.1) {
      rtb_Init = -0.1;
    } else {
      rtb_Init = rtb_Error_c5;
    }

    /* End of Saturate: '<S180>/Saturation1' */
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S180>/Switch' */

  /* Switch: '<S133>/Switch2' incorporates:
   *  Logic: '<S133>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S180>/Add1' */
    rtb_Add_oy += rtb_Init;

    /* Saturate: '<S180>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S133>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S133>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S133>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S180>/Saturation2' */
  } else {
    /* Switch: '<S133>/Switch2' incorporates:
     *  Constant: '<S133>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S133>/Switch2' */

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

  /* Update for UnitDelay: '<S41>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S41>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S41>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S44>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S44>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 0U;

  /* Update for UnitDelay: '<S44>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_a = rtb_Switch1_hb;

  /* Update for UnitDelay: '<S47>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S47>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S47>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_j = rtb_Switch1_h;

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

  /* Update for Delay: '<S70>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S90>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S70>/A'
   *  Delay: '<S70>/MemoryX'
   */
  rtb_Sum1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Switch1_hb = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S70>/MemoryX' incorporates:
   *  Constant: '<S70>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S90>/A[k]*xhat[k|k-1]'
   *  Product: '<S90>/B[k]*u[k]'
   *  Sum: '<S90>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Sum1) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Switch1_hb) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S350>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S350>/FixPt Constant'
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

  /* Update for UnitDelay: '<S373>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S372>/UD'
   *
   * Block description for '<S372>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S370>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch1_m;

  /* Update for UnitDelay: '<S352>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Init_o;

  /* Update for UnitDelay: '<S367>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S367>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S367>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S351>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S360>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S360>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S360>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S326>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_DeadZone;

  /* Update for UnitDelay: '<S325>/UD'
   *
   * Block description for '<S325>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S319>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S263>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S262>/UD'
   *
   * Block description for '<S262>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Switch2;

  /* Update for UnitDelay: '<S256>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S274>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S273>/UD'
   *
   * Block description for '<S273>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_i;

  /* Update for UnitDelay: '<S259>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S284>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S283>/UD'
   *
   * Block description for '<S283>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S277>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S295>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_bl;

  /* Update for UnitDelay: '<S294>/UD'
   *
   * Block description for '<S294>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_ee;

  /* Update for UnitDelay: '<S280>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S305>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S304>/UD'
   *
   * Block description for '<S304>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S298>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S316>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S315>/UD'
   *
   * Block description for '<S315>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S301>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S337>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S336>/UD'
   *
   * Block description for '<S336>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_ec;

  /* Update for UnitDelay: '<S322>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S187>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_os;

  /* Update for UnitDelay: '<S186>/UD'
   *
   * Block description for '<S186>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S185>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S135>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Button_Spinup_Enable;

  /* Update for UnitDelay: '<S127>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S127>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S68>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_fh;

  /* Update for UnitDelay: '<S67>/UD'
   *
   * Block description for '<S67>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_hm;

  /* Update for UnitDelay: '<S66>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Button_Shoot_Enable;

  /* Update for UnitDelay: '<S50>/Delay Input1'
   *
   * Block description for '<S50>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Shooter_Active_prev;

  /* Update for UnitDelay: '<S64>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S64>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S60>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_dj;

  /* Update for UnitDelay: '<S59>/UD'
   *
   * Block description for '<S59>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_ov;

  /* Update for UnitDelay: '<S58>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_Switch2_o;

  /* Update for UnitDelay: '<S182>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Add_ir;

  /* Update for UnitDelay: '<S181>/UD'
   *
   * Block description for '<S181>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_i;

  /* Update for UnitDelay: '<S133>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S180>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Init;

  /* Update for UnitDelay: '<S133>/Unit Delay' */
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

  /* Start for If: '<S130>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S41>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S47>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S70>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S350>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S367>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S360>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S127>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S64>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S429>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S195>/If' */
  Robot_Control_DW.If_ActiveSubsystem_hk = -1;

  /* InitializeConditions for UnitDelay: '<S191>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S195>/Robot_Index_Is_Valid' */
  /* Start for If: '<S198>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S198>/Circle_Check_Valid' */
  /* Start for If: '<S200>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S198>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S195>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S130>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S162>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lc = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S130>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S130>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S130>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S130>/If Action Subsystem2' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem2);

  /* End of SystemInitialize for SubSystem: '<S130>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S130>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S130>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S130>/If Action Subsystem4' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem4);

  /* End of SystemInitialize for SubSystem: '<S130>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S130>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S130>/If Action Subsystem5' */
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
