/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.467
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Mar  5 20:21:30 2026
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

/* Named constants for Chart: '<S19>/Chart' */
#define Robot_Control_IN_End_Action    ((uint8_T)1U)
#define Robot_Control_IN_Follow_Path   ((uint8_T)2U)
#define Robot_Control_IN_Start_Action  ((uint8_T)3U)

/* Exported block parameters */
real_T Auto_Path_Chooser = 1.0;        /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S20>/Constant17'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S397>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S393>/Constant'
                                        *   '<S393>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S397>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S393>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S231>/Constant3'
                                        *   '<S252>/Constant3'
                                        *   '<S273>/Constant3'
                                        *   '<S294>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S231>/Constant2'
                                   *   '<S252>/Constant2'
                                   *   '<S273>/Constant2'
                                   *   '<S294>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S231>/Saturation'
                                        *   '<S252>/Saturation'
                                        *   '<S273>/Saturation'
                                        *   '<S294>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S231>/Saturation'
                                        *   '<S252>/Saturation'
                                        *   '<S273>/Saturation'
                                        *   '<S294>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S231>/Gain'
                                            *   '<S252>/Gain'
                                            *   '<S273>/Gain'
                                            *   '<S294>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S231>/Gain2'
                                        *   '<S252>/Gain2'
                                        *   '<S273>/Gain2'
                                        *   '<S294>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S231>/Saturation1'
                                         *   '<S252>/Saturation1'
                                         *   '<S273>/Saturation1'
                                         *   '<S294>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S231>/Saturation1'
                                        *   '<S252>/Saturation1'
                                        *   '<S273>/Saturation1'
                                        *   '<S294>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S231>/Gain1'
                                        *   '<S252>/Gain1'
                                        *   '<S273>/Gain1'
                                        *   '<S294>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S236>/Constant'
                            *   '<S257>/Constant'
                            *   '<S278>/Constant'
                            *   '<S299>/Constant'
                            */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S150>/BlueAllianceZoneX'
                                         *   '<S152>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S123>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S123>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S123>/Constant1'
                                        *   '<S123>/Switch3'
                                        */
real_T Field_Pass_Y_Bottom = 0.63297;  /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S123>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 7.4364;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S123>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S151>/RedAllianceZoneX'
                                         *   '<S153>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S123>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S123>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S383>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S383>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = -1.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S118>/Constant'
                                       */
real_T Rebuilt_Feeder_Motor_Gain_FF = 0.00012732;/* Variable: Rebuilt_Feeder_Motor_Gain_FF
                                                  * Referenced by: '<S12>/Constant'
                                                  */
real_T Rebuilt_Hood_Servo_Pos_Max = 1.0;/* Variable: Rebuilt_Hood_Servo_Pos_Max
                                         * Referenced by: '<S10>/Saturation'
                                         */
real_T Rebuilt_Hood_Servo_Pos_Min = 0.05;/* Variable: Rebuilt_Hood_Servo_Pos_Min
                                          * Referenced by: '<S10>/Saturation'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S103>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S103>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S37>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_I = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_I
                                        * Referenced by: '<S37>/Gain2'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                        * Referenced by: '<S37>/Gain1'
                                        */
real_T Rebuilt_Intake_Arm_Integral_Enable = 0.0;
                                 /* Variable: Rebuilt_Intake_Arm_Integral_Enable
                                  * Referenced by: '<S33>/Constant1'
                                  */
real_T Rebuilt_Intake_Cycle_Angle_In = 20.0;
                                      /* Variable: Rebuilt_Intake_Cycle_Angle_In
                                       * Referenced by: '<S6>/Chart'
                                       */
real_T Rebuilt_Intake_Cycle_Angle_Out = 70.0;
                                     /* Variable: Rebuilt_Intake_Cycle_Angle_Out
                                      * Referenced by: '<S6>/Chart'
                                      */
real_T Rebuilt_Intake_Des_Angle_In = 0.0;/* Variable: Rebuilt_Intake_Des_Angle_In
                                          * Referenced by: '<S6>/Chart'
                                          */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by: '<S6>/Chart'
                                            */
real_T Rebuilt_Intake_RL_Dec = -1.8;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S34>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 1.8;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S34>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 27.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S141>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 33.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by: '<S146>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 32.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S137>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 57.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S138>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 82.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S139>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 107.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S140>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S142>/Unit Delay'
                                      *   '<S143>/Unit Delay'
                                      *   '<S144>/Unit Delay'
                                      *   '<S145>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_TeleOp = 140.0;/* Variable: Rebuilt_Match_Time_TeleOp
                                          * Referenced by: '<S109>/Constant'
                                          */
real_T Rebuilt_Match_Time_Transition = 7.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S135>/Constant'
                                       */
real_T Rebuilt_Negative_Feeder_Speed = -1000.0;
                                      /* Variable: Rebuilt_Negative_Feeder_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Roller_Desired_Speed = 0.0;/* Variable: Rebuilt_Roller_Desired_Speed
                                           * Referenced by: '<S6>/Constant'
                                           */
real_T Rebuilt_Roller_Error_Integral_Enable = 0.0;
                               /* Variable: Rebuilt_Roller_Error_Integral_Enable
                                * Referenced by: '<S35>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                           * Referenced by: '<S45>/Gain'
                                           */
real_T Rebuilt_Roller_Motor_Gain_I = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                          * Referenced by: '<S45>/Gain2'
                                          */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                          * Referenced by: '<S45>/Gain1'
                                          */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S124>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S124>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S124>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S124>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S124>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S124>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S124>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S124>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S120>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S120>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S120>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 4.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S120>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 3.4; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S120>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 3.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S120>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 2.8; /* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S120>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S120>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S121>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S121>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S121>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S121>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S121>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S121>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S121>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S121>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S111>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S111>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S111>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2900.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S134>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 3000.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S134>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3250.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S134>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3400.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S134>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3575.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S134>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3700.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S134>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3850.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S134>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S134>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S133>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3000.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S133>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3250.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S133>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3400.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S133>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3575.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S133>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3700.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S133>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 3850.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S133>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S133>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S127>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S127>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S127>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S127>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S127>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S127>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S127>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S127>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S131>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S112>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S155>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S155>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.0005;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                              * Referenced by: '<S155>/Gain1'
                                              */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S122>/Constant2'
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
                              * Referenced by: '<S114>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S160>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S160>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S160>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S382>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S380>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S382>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S383>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S383>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S220>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S220>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S167>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S180>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S220>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S327>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S327>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S327>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S327>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S327>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S327>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S344>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S344>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S344>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S344>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S343>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S344>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S344>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S344>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S344>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S344>/Constant1'
                                   *   '<S344>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S344>/Constant'
                                   *   '<S344>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S234>/Constant3'
                                        *   '<S255>/Constant3'
                                        *   '<S276>/Constant3'
                                        *   '<S297>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S234>/Constant2'
                                *   '<S255>/Constant2'
                                *   '<S276>/Constant2'
                                *   '<S297>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S234>/Saturation'
                                           *   '<S255>/Saturation'
                                           *   '<S276>/Saturation'
                                           *   '<S297>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S234>/Saturation'
                                          *   '<S255>/Saturation'
                                          *   '<S276>/Saturation'
                                          *   '<S297>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S234>/Gain2'
                                         *   '<S255>/Gain2'
                                         *   '<S276>/Gain2'
                                         *   '<S297>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S234>/Saturation1'
                                             *   '<S255>/Saturation1'
                                             *   '<S276>/Saturation1'
                                             *   '<S297>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S234>/Saturation1'
                                            *   '<S255>/Saturation1'
                                            *   '<S276>/Saturation1'
                                            *   '<S297>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S234>/Gain1'
                                        *   '<S255>/Gain1'
                                        *   '<S276>/Gain1'
                                        *   '<S297>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S326>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S326>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S326>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S326>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S326>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S326>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S382>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S382>/Constant1'
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
                                      * Referenced by: '<S381>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S381>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S381>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S314>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S314>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S314>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S314>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S314>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S314>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S383>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S382>/Dead Zone'
                                        *   '<S383>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S382>/Dead Zone'
                                        *   '<S383>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S380>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S380>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S380>/Constant4'
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
                                        * Referenced by: '<S380>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S380>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S380>/Constant5'
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
                                        *   '<S380>/Constant11'
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
 *    '<S109>/If Action Subsystem1'
 *    '<S109>/If Action Subsystem3'
 */
void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S142>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S109>/If Action Subsystem1'
 *    '<S109>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* Logic: '<S142>/NOT' incorporates:
   *  SignalConversion generated from: '<S142>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S142>/IsRedActive' */
  *rty_IsRedActive = rtu_IsBlueInactiveFirst;

  /* SignalConversion: '<S142>/Signal Copy' incorporates:
   *  Constant: '<S142>/Constant1'
   *  Sum: '<S142>/Sum'
   *  UnitDelay: '<S142>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S142>/Unit Delay' incorporates:
   *  Constant: '<S142>/Constant1'
   *  Sum: '<S142>/Sum'
   */
  localDW->UnitDelay_DSTATE -= 0.02;
}

/*
 * System initialize for action system:
 *    '<S109>/If Action Subsystem2'
 *    '<S109>/If Action Subsystem4'
 */
void Robot_C_IfActionSubsystem2_Init(DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S143>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S109>/If Action Subsystem2'
 *    '<S109>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  /* Logic: '<S143>/NOT1' incorporates:
   *  SignalConversion generated from: '<S143>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S143>/IsBlueActive' */
  *rty_IsBlueActive = rtu_IsBlueInactiveFirst;

  /* SignalConversion: '<S143>/Signal Copy' incorporates:
   *  Constant: '<S143>/Constant1'
   *  Sum: '<S143>/Sum'
   *  UnitDelay: '<S143>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S143>/Unit Delay' incorporates:
   *  Constant: '<S143>/Constant1'
   *  Sum: '<S143>/Sum'
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
  real_T rtb_Add_nt;
  real_T rtb_Add_os;
  real_T rtb_DeadZone;
  real_T rtb_Error_e;
  real_T rtb_Error_h;
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
  real_T rtb_Product_di;
  real_T rtb_Product_hm;
  real_T rtb_Product_i;
  real_T rtb_Product_lf;
  real_T rtb_Product_lo;
  real_T rtb_Saturation_h;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_la;
  real_T rtb_Sum1_fh;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1;
  real_T rtb_Switch2;
  real_T rtb_Switch2_cw;
  real_T rtb_Switch2_nf;
  real_T rtb_Switch2_ow;
  real_T rtb_Switch2_p0;
  real_T rtb_Switch2_p2;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s192_iter;
  uint16_T s217_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T rtb_Button_Shoot_Enable;
  uint8_T rtb_Button_Spinup_Enable;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4;
  boolean_T rtb_Intake_Arm_Cycle;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation_g;
  boolean_T rtb_LogicalOperator1_n;
  boolean_T rtb_Swerve_Motors_Disabled;

  /* RelationalOperator: '<S28>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *  UnitDelay: '<S28>/Delay Input1'
   *
   * Block description for '<S28>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Joystick_Left_B11 >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S29>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *  UnitDelay: '<S29>/Delay Input1'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets =
    (Robot_Control_U.Joystick_Left_B12 > Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S30>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *  UnitDelay: '<S30>/Delay Input1'
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Joystick_Left_B13 >
    Robot_Control_DW.DelayInput1_DSTATE_n);

  /* SignalConversion: '<S5>/Signal Copy1' incorporates:
   *  Inport: '<Root>/Joystick_Left_X'
   */
  Robot_Control_B.Drive_Joystick_X = Robot_Control_U.Joystick_Left_X;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y = Robot_Control_U.Joystick_Left_Y;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z = Robot_Control_U.Joystick_Left_Z;

  /* RelationalOperator: '<S25>/Compare' incorporates:
   *  Constant: '<S25>/Constant'
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

  /* RelationalOperator: '<S27>/Compare' incorporates:
   *  Constant: '<S27>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Toward_Driver = (Robot_Control_U.Joystick_Right_POV ==
    180.0);

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Right_Driver = (Robot_Control_U.Joystick_Right_POV ==
    90.0);

  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Left_Driver = (Robot_Control_U.Joystick_Right_POV ==
    270.0);

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
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

  /* If: '<S409>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S409>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S412>/Action Port'
     */
    /* Product: '<S412>/Product' incorporates:
     *  Constant: '<S412>/Constant1'
     *  Constant: '<S412>/Constant2'
     *  Math: '<S412>/Math Function'
     */
    rtb_Init_o = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495)
      * 111.0;

    /* End of Outputs for SubSystem: '<S409>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S409>/Subsystem' incorporates:
     *  ActionPort: '<S413>/Action Port'
     */
    /* SignalConversion generated from: '<S413>/Out1' incorporates:
     *  Constant: '<S413>/Constant'
     */
    rtb_Init_o = 0.0;

    /* End of Outputs for SubSystem: '<S409>/Subsystem' */
  }

  /* End of If: '<S409>/If' */

  /* Gain: '<S410>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S411>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Init_o * cos(rtb_Sin4)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S411>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Init_o * sin(rtb_Sin4)) +
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
  rtb_Add_nt = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_nt)) || (rtIsInf(rtb_Add_nt))) {
    rtb_Add_nt = 0.0;
  } else {
    rtb_Add_nt = fmod(rtb_Add_nt, 4.294967296E+9);
  }

  switch ((rtb_Add_nt < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_nt)))) :
          ((int32_T)((uint32_T)rtb_Add_nt))) {
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
    rtb_Button_Spinup_Enable = 0U;

    /* SignalConversion generated from: '<S4>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S4>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

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
    rtb_Intake_Arm_Cycle = false;

    /* SignalConversion generated from: '<S4>/Intake_Roller_On' incorporates:
     *  Constant: '<S4>/Constant20'
     */
    rtb_LogicalOperator1_n = false;

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
       */
      memset(&Robot_Control_DW.UnitDelay1_DSTATE_iz[0], 0, 60U * (sizeof(real_T)));
      Robot_Control_DW.UnitDelay_DSTATE_e3 = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Autonomous' */

      /* SystemReset for IfAction SubSystem: '<S1>/Autonomous' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S19>/Chart'
       */
      Robot_Control_DW.is_active_c6_Robot_Control = 0U;
      Robot_Control_DW.is_c6_Robot_Control = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_B.Desired_Static_Action = 0.0;
      Robot_Control_B.Path_Counter = 0.0;
      Robot_Control_B.Spline_Enable_j = false;

      /* End of SystemReset for SubSystem: '<S1>/Autonomous' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MultiPortSwitch: '<S20>/Multiport Switch1' incorporates:
     *  Constant: '<S20>/Constant10'
     *  Constant: '<S20>/Constant11'
     *  Constant: '<S20>/Constant12'
     *  Constant: '<S20>/Constant13'
     *  Constant: '<S20>/Constant14'
     *  Constant: '<S20>/Constant15'
     *  Constant: '<S20>/Constant16'
     *  Constant: '<S20>/Constant17'
     *  Constant: '<S20>/Constant9'
     */
    switch ((int32_T)Auto_Path_Chooser) {
     case 1:
      rtb_MultiportSwitch1[0] = 1;
      rtb_MultiportSwitch1[1] = 2;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 2:
      rtb_MultiportSwitch1[0] = 1;
      rtb_MultiportSwitch1[1] = 3;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 3:
      rtb_MultiportSwitch1[0] = 4;
      rtb_MultiportSwitch1[1] = 5;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 4:
      rtb_MultiportSwitch1[0] = 4;
      rtb_MultiportSwitch1[1] = 6;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 5:
      rtb_MultiportSwitch1[0] = 7;
      rtb_MultiportSwitch1[1] = 8;
      rtb_MultiportSwitch1[2] = 2;
      break;

     case 6:
      rtb_MultiportSwitch1[0] = 7;
      rtb_MultiportSwitch1[1] = 8;
      rtb_MultiportSwitch1[2] = 3;
      break;

     case 7:
      rtb_MultiportSwitch1[0] = 9;
      rtb_MultiportSwitch1[1] = 10;
      rtb_MultiportSwitch1[2] = 5;
      break;

     default:
      rtb_MultiportSwitch1[0] = 9;
      rtb_MultiportSwitch1[1] = 10;
      rtb_MultiportSwitch1[2] = 6;
      break;
    }

    /* End of MultiPortSwitch: '<S20>/Multiport Switch1' */

    /* Saturate: '<S19>/Saturation' incorporates:
     *  UnitDelay: '<S7>/Unit Delay2'
     */
    if (Robot_Control_DW.UnitDelay2_DSTATE > 10.0) {
      rtb_Saturation_h = 10.0;
    } else if (Robot_Control_DW.UnitDelay2_DSTATE < 1.0) {
      rtb_Saturation_h = 1.0;
    } else {
      rtb_Saturation_h = Robot_Control_DW.UnitDelay2_DSTATE;
    }

    /* End of Saturate: '<S19>/Saturation' */

    /* Chart: '<S19>/Chart' incorporates:
     *  Selector: '<S19>/Selector1'
     *  UnitDelay: '<S19>/Unit Delay'
     *  UnitDelay: '<S19>/Unit Delay1'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    if (Robot_Control_DW.is_active_c6_Robot_Control == 0U) {
      Robot_Control_DW.is_active_c6_Robot_Control = 1U;
      Robot_Control_B.Path_Counter = 1.0;
      Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Start_Action;
      Robot_Control_B.Spline_Enable_j = true;
      Robot_Control_B.Desired_Static_Action =
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) + 39];
    } else {
      switch (Robot_Control_DW.is_c6_Robot_Control) {
       case Robot_Control_IN_End_Action:
        Robot_Control_B.Spline_Enable_j = false;
        if ((Robot_Control_B.Desired_Static_Action == 0.0) &&
            (Robot_Control_B.Path_Counter < Robot_Control_ConstB.Width)) {
          rtb_Intake_Arm_Cycle = (rtb_MultiportSwitch1[((int32_T)
            (Robot_Control_B.Path_Counter + 1.0)) - 1] != 0);
        } else {
          rtb_Intake_Arm_Cycle = false;
        }

        if (rtb_Intake_Arm_Cycle) {
          Robot_Control_B.Path_Counter++;
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Start_Action;
          Robot_Control_B.Spline_Enable_j = true;
          Robot_Control_B.Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            39];
        }
        break;

       case Robot_Control_IN_Follow_Path:
        if (Robot_Control_DW.UnitDelay_DSTATE_lly) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_End_Action;
          Robot_Control_B.Spline_Enable_j = false;
          Robot_Control_B.Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            39];
        } else if (rtb_Saturation_h > Robot_Control_DW.UnitDelay_DSTATE_e3) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Desired_Static_Action = 0.0;
        }
        break;

       default:
        /* case IN_Start_Action: */
        Robot_Control_B.Spline_Enable_j = true;
        if (Robot_Control_B.Desired_Static_Action == 0.0) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Desired_Static_Action = 0.0;
        }
        break;
      }
    }

    /* End of Chart: '<S19>/Chart' */

    /* Lookup_n-D: '<S19>/1-D Lookup Table1' incorporates:
     *  MultiPortSwitch: '<S20>/Multiport Switch1'
     */
    rtb_Init_o = rtb_MultiportSwitch1[plook_u32d_evencka
      (Robot_Control_B.Path_Counter, 1.0, 1.0, 2U)];

    /* Switch: '<S19>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     */
    rtb_Swerve_Motors_Disabled = (Robot_Control_U.IsBlueAlliance != 0.0);

    /* Selector: '<S19>/Selector' */
    rtb_Num_Segments = ((int32_T)rtb_Init_o) - 1;

    /* Merge: '<S9>/Merge9' incorporates:
     *  Lookup_n-D: '<S19>/1-D Lookup Table'
     *  Lookup_n-D: '<S19>/1-D Lookup Table1'
     */
    Robot_Control_B.Spline_Num_Poses =
      rtCP_uDLookupTable_tableData[plook_u32d_evencka(rtb_Init_o, 1.0, 1.0, 9U)];

    /* Merge: '<S9>/Merge7' incorporates:
     *  SignalConversion generated from: '<S2>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = Robot_Control_B.Spline_Enable_j;

    /* SignalConversion generated from: '<S2>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S18>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S18>/Constant1'
     *  SignalConversion generated from: '<S2>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Button_Spinup_Enable' incorporates:
     *  Constant: '<S18>/Constant11'
     */
    rtb_Button_Spinup_Enable = 0U;

    /* Merge: '<S9>/Merge2' incorporates:
     *  Constant: '<S18>/Constant2'
     *  SignalConversion generated from: '<S2>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Intake_Arm_Move_Cycle' incorporates:
     *  Constant: '<S18>/Constant19'
     */
    rtb_Intake_Arm_Cycle = false;

    /* Merge: '<S9>/Merge3' incorporates:
     *  Constant: '<S18>/Constant3'
     *  SignalConversion generated from: '<S2>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* SignalConversion generated from: '<S2>/Intake_Arm_Move_In' incorporates:
     *  Constant: '<S18>/Constant16'
     */
    rtb_Intake_Arm_Move_In = false;

    /* Merge: '<S9>/Merge4' incorporates:
     *  Constant: '<S18>/Constant4'
     *  SignalConversion generated from: '<S2>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* SignalConversion generated from: '<S2>/Intake_Arm_Move_Out' incorporates:
     *  Constant: '<S18>/Constant17'
     */
    rtb_Intake_Arm_Move_Out = false;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S18>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* SignalConversion generated from: '<S2>/Intake_Roller_On' incorporates:
     *  Constant: '<S18>/Constant20'
     */
    rtb_LogicalOperator1_n = false;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S18>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

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
    for (i = 0; i < 60; i++) {
      /* Switch: '<S19>/Switch' */
      if (rtb_Swerve_Motors_Disabled) {
        /* Selector: '<S19>/Selector' incorporates:
         *  Constant: '<S19>/Constant'
         */
        rtb_Sin4 = rtCP_Constant_Value_c[(rtb_Num_Segments * 60) + i];
        rtb_Spline_Ref_Poses_h[i] = rtb_Sin4;
      } else {
        /* Selector: '<S19>/Selector' incorporates:
         *  Constant: '<S19>/Constant1'
         */
        rtb_Sin4 = rtCP_Constant1_Value_b[(rtb_Num_Segments * 60) + i];
        rtb_Spline_Ref_Poses_h[i] = rtb_Sin4;
      }

      /* Update for UnitDelay: '<S19>/Unit Delay1' incorporates:
       *  Selector: '<S19>/Selector'
       */
      Robot_Control_DW.UnitDelay1_DSTATE_iz[i] = rtb_Sin4;
    }

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Saturation_h;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S382>/Unit Delay1'
       *  UnitDelay: '<S382>/Unit Delay2'
       *  UnitDelay: '<S382>/Unit Delay3'
       *  UnitDelay: '<S382>/Unit Delay4'
       *  UnitDelay: '<S385>/Delay Input1'
       *  UnitDelay: '<S386>/Delay Input1'
       *  UnitDelay: '<S387>/Delay Input1'
       *  UnitDelay: '<S388>/Delay Input1'
       *  UnitDelay: '<S390>/Delay Input1'
       *  UnitDelay: '<S396>/Unit Delay'
       *  UnitDelay: '<S396>/Unit Delay1'
       *  UnitDelay: '<S400>/FixPt Unit Delay1'
       *  UnitDelay: '<S400>/FixPt Unit Delay2'
       *
       * Block description for '<S385>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S386>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S387>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S388>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S390>/Delay Input1':
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
      Robot_Control_DW.UnitDelay1_DSTATE_lw = 0.0;
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

    /* Switch: '<S380>/Switch4' incorporates:
     *  Constant: '<S405>/Constant'
     *  Constant: '<S408>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S405>/Compare'
     *  RelationalOperator: '<S408>/Compare'
     *  Switch: '<S380>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S380>/Switch4' incorporates:
       *  Constant: '<S380>/Constant8'
       *  Sum: '<S380>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S380>/Switch5' incorporates:
       *  Constant: '<S380>/Constant7'
       *  Gain: '<S380>/Gain'
       *  Sum: '<S380>/Subtract5'
       *  Switch: '<S380>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S380>/Switch4' incorporates:
       *  Constant: '<S380>/Constant6'
       *  Switch: '<S380>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S380>/Switch4' */

    /* Logic: '<S380>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S380>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S382>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_nt = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_nt = 0.0;
    } else {
      rtb_Add_nt = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S382>/Add' incorporates:
     *  Constant: '<S382>/Constant'
     *  Constant: '<S382>/Constant1'
     *  DeadZone: '<S382>/Dead Zone'
     *  Lookup_n-D: '<S382>/Modulation_Str_Y_Rel'
     *  Product: '<S382>/Product'
     *  Product: '<S382>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Saturation_h = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                        Steering_Relative_Gain) + (rtb_Add_nt *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S384>/Compare' incorporates:
     *  Constant: '<S384>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Saturation_h == 0.0);

    /* Logic: '<S382>/AND2' incorporates:
     *  RelationalOperator: '<S385>/FixPt Relational Operator'
     *  RelationalOperator: '<S386>/FixPt Relational Operator'
     *  RelationalOperator: '<S387>/FixPt Relational Operator'
     *  RelationalOperator: '<S388>/FixPt Relational Operator'
     *  UnitDelay: '<S385>/Delay Input1'
     *  UnitDelay: '<S386>/Delay Input1'
     *  UnitDelay: '<S387>/Delay Input1'
     *  UnitDelay: '<S388>/Delay Input1'
     *
     * Block description for '<S385>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S386>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S387>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S388>/Delay Input1':
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

    /* Logic: '<S382>/AND1' incorporates:
     *  Logic: '<S382>/AND3'
     *  UnitDelay: '<S382>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Swerve_Motors_Disabled && (rtb_LogicalOperator1_n ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S382>/AND4' incorporates:
     *  Logic: '<S382>/AND8'
     *  UnitDelay: '<S382>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Swerve_Motors_Disabled && (!rtb_LogicalOperator1_n)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S382>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S382>/Switch8' incorporates:
     *  Constant: '<S391>/Constant'
     *  Logic: '<S382>/AND9'
     *  RelationalOperator: '<S390>/FixPt Relational Operator'
     *  RelationalOperator: '<S391>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S390>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S390>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Swerve_Motors_Disabled) > ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_j))) ||
         (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S382>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S382>/Switch8' incorporates:
       *  UnitDelay: '<S382>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S382>/Switch8' */

    /* Switch: '<S382>/Switch4' incorporates:
     *  Constant: '<S382>/Constant5'
     *  Switch: '<S382>/Switch1'
     *  Switch: '<S382>/Switch5'
     *  Switch: '<S382>/Switch6'
     *  Switch: '<S382>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Init_o = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S382>/Switch5' incorporates:
       *  Constant: '<S382>/Constant6'
       */
      rtb_Init_o = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S382>/Switch6' incorporates:
       *  Constant: '<S382>/Constant7'
       *  Switch: '<S382>/Switch5'
       */
      rtb_Init_o = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S382>/Switch7' incorporates:
       *  Constant: '<S382>/Constant8'
       *  Switch: '<S382>/Switch5'
       *  Switch: '<S382>/Switch6'
       */
      rtb_Init_o = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S382>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S382>/Switch5'
       *  Switch: '<S382>/Switch6'
       *  Switch: '<S382>/Switch7'
       */
      rtb_Init_o = 0.0;
    } else {
      /* Switch: '<S382>/Switch6' incorporates:
       *  Switch: '<S382>/Switch5'
       *  Switch: '<S382>/Switch7'
       *  UnitDelay: '<S382>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S382>/Switch4' */

    /* Switch: '<S382>/Switch2' incorporates:
     *  Switch: '<S382>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S382>/Switch2' incorporates:
       *  Constant: '<S382>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S382>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Init_o;
    } else {
      /* Switch: '<S382>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S382>/Switch3' incorporates:
       *  Constant: '<S382>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S382>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S382>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S381>/Switch1' incorporates:
     *  Constant: '<S381>/Constant5'
     *  Constant: '<S381>/Constant8'
     *  DataTypeConversion: '<S381>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Swerve_Motors_Disabled;
    }

    /* End of Switch: '<S381>/Switch1' */

    /* Lookup_n-D: '<S383>/Modulation_Drv' incorporates:
     *  Math: '<S383>/Magnitude'
     */
    rtb_Sin4 = look1_binlcpw(rt_hypotd_snf(Robot_Control_B.Drive_Joystick_X,
      Robot_Control_B.Drive_Joystick_Y), rtCP_Modulation_Drv_bp01Data,
      rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S394>/Compare' incorporates:
     *  Constant: '<S394>/Constant'
     */
    rtb_Intake_Arm_Cycle = (rtb_Sin4 == 0.0);

    /* DeadZone: '<S383>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S383>/Dead Zone' */

    /* Logic: '<S383>/Logical Operator' incorporates:
     *  Constant: '<S395>/Constant'
     *  RelationalOperator: '<S395>/Compare'
     */
    rtb_LogicalOperator1_n = ((rtb_DeadZone != 0.0) && rtb_Intake_Arm_Cycle);

    /* Switch: '<S381>/Switch' incorporates:
     *  Constant: '<S381>/Constant5'
     *  Constant: '<S381>/Constant7'
     *  DataTypeConversion: '<S381>/Data Type Conversion'
     *  Logic: '<S383>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_LogicalOperator1_n;
    }

    /* End of Switch: '<S381>/Switch' */

    /* Switch: '<S380>/Switch2' incorporates:
     *  Constant: '<S380>/Constant2'
     *  Constant: '<S404>/Constant'
     *  Constant: '<S407>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S404>/Compare'
     *  RelationalOperator: '<S407>/Compare'
     *  Sum: '<S380>/Subtract'
     *  Switch: '<S380>/Switch'
     *  Switch: '<S380>/Switch1'
     *  Switch: '<S380>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S380>/Switch2' incorporates:
       *  Constant: '<S380>/Constant5'
       *  Sum: '<S380>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S380>/Switch2' incorporates:
       *  Constant: '<S380>/Constant4'
       *  Sum: '<S380>/Subtract2'
       *  Switch: '<S380>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S380>/Switch1' incorporates:
       *  Constant: '<S380>/Constant1'
       *  Sum: '<S380>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S380>/Switch2' incorporates:
       *  Constant: '<S380>/Constant3'
       *  Switch: '<S380>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S380>/Switch1' incorporates:
       *  Constant: '<S380>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S380>/Switch2' */

    /* UnaryMinus: '<S380>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S396>/Switch1' incorporates:
     *  Constant: '<S401>/Constant'
     *  Constant: '<S402>/Constant'
     *  Logic: '<S396>/AND'
     *  RelationalOperator: '<S401>/Compare'
     *  RelationalOperator: '<S402>/Compare'
     *  Switch: '<S396>/Switch2'
     *  UnitDelay: '<S396>/Unit Delay'
     *  UnitDelay: '<S396>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_lw;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S396>/Switch1' */

    /* Switch: '<S383>/Switch1' incorporates:
     *  Logic: '<S383>/Logical Operator1'
     *  Switch: '<S383>/Switch4'
     *  Switch: '<S383>/Switch9'
     */
    if (rtb_LogicalOperator1_n) {
      /* Signum: '<S383>/Sign' */
      if (rtIsNaN(rtb_DeadZone)) {
        rtb_Add_nt = (rtNaN);
      } else if (rtb_DeadZone < 0.0) {
        rtb_Add_nt = -1.0;
      } else {
        rtb_Add_nt = (rtb_DeadZone > 0.0);
      }

      /* Switch: '<S383>/Switch5' incorporates:
       *  Constant: '<S383>/Constant3'
       *  Constant: '<S383>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S383>/Gain3'
       *  Signum: '<S383>/Sign'
       *  Sum: '<S383>/Add'
       *  Switch: '<S383>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_nt) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S383>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S383>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S383>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S383>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S383>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S383>/Switch4'
       *  Trigonometry: '<S383>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S383>/Switch1' */

    /* Switch: '<S393>/Switch1' incorporates:
     *  Constant: '<S393>/Constant'
     *  Constant: '<S393>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S393>/Switch1' */

    /* Switch: '<S400>/Init' incorporates:
     *  UnitDelay: '<S400>/FixPt Unit Delay1'
     *  UnitDelay: '<S400>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S400>/Init' */

    /* Sum: '<S398>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S399>/Switch2' incorporates:
     *  Constant: '<S397>/Constant1'
     *  Constant: '<S397>/Constant3'
     *  RelationalOperator: '<S399>/LowerRelop1'
     *  RelationalOperator: '<S399>/UpperRelop'
     *  Switch: '<S399>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S399>/Switch' incorporates:
       *  Constant: '<S397>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S399>/Switch2' */

    /* Sum: '<S398>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S383>/Switch8' incorporates:
     *  Logic: '<S383>/Logical Operator1'
     *  Switch: '<S383>/Switch2'
     */
    if (rtb_LogicalOperator1_n) {
      /* Switch: '<S383>/Switch' incorporates:
       *  Gain: '<S383>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_DeadZone;
    } else if (rtb_Intake_Arm_Cycle) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S383>/Constant5'
       *  Gain: '<S383>/Gain2'
       *  Math: '<S383>/Magnitude1'
       *  MinMax: '<S383>/Min'
       *  Switch: '<S383>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S393>/Product' incorporates:
       *  Switch: '<S383>/Switch2'
       */
      rtb_Add_nt = rtb_Sin4 * rtb_Init;

      /* Saturate: '<S393>/Saturation' incorporates:
       *  Switch: '<S383>/Switch2'
       */
      if (rtb_Add_nt > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_nt < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_nt;
      }

      /* End of Saturate: '<S393>/Saturation' */
    }

    /* End of Switch: '<S383>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S382>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Saturation_h;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S380>/Constant11'
     *  Switch: '<S380>/Switch6'
     *  Switch: '<S380>/Switch7'
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

    /* RelationalOperator: '<S375>/Compare' incorporates:
     *  Constant: '<S375>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S378>/Compare' incorporates:
     *  Constant: '<S378>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S377>/Compare' incorporates:
     *  Constant: '<S377>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S376>/Compare' incorporates:
     *  Constant: '<S376>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* SignalConversion: '<S15>/Signal Copy' incorporates:
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = Robot_Control_U.Gamepad_LB;

    /* SignalConversion: '<S15>/Signal Copy1' incorporates:
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = Robot_Control_U.Gamepad_RB;

    /* Update for UnitDelay: '<S390>/Delay Input1'
     *
     * Block description for '<S390>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Swerve_Motors_Disabled;

    /* Update for UnitDelay: '<S389>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S389>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S385>/Delay Input1'
     *
     * Block description for '<S385>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S386>/Delay Input1'
     *
     * Block description for '<S386>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S387>/Delay Input1'
     *
     * Block description for '<S387>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S388>/Delay Input1'
     *
     * Block description for '<S388>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S382>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S382>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S382>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S382>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Init_o;

    /* Update for UnitDelay: '<S396>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_lw = rtb_Switch1;

    /* Update for UnitDelay: '<S396>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S400>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S400>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S400>/FixPt Unit Delay1' */
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
    rtb_Button_Spinup_Enable = 0U;

    /* SignalConversion generated from: '<S16>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S16>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

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
    rtb_Intake_Arm_Cycle = false;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S16>/Constant22'
     *  SignalConversion generated from: '<S16>/Desired_Pipeline'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = TEST_Pipeline;

    /* SignalConversion generated from: '<S16>/Intake_Roller_On' incorporates:
     *  Constant: '<S16>/Constant20'
     */
    rtb_LogicalOperator1_n = false;

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

  /* Reshape: '<S49>/Reshapey' incorporates:
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

  /* Delay: '<S49>/MemoryX' incorporates:
   *  Constant: '<S49>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S76>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S102>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S69>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S100>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S100>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S49>/C'
     *  Delay: '<S49>/MemoryX'
     *  Product: '<S102>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Init_o;

    /* Sum: '<S100>/Sum' incorporates:
     *  Constant: '<S49>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S100>/C[k]*xhat[k|k-1]'
     *  Product: '<S100>/D[k]*u[k]'
     *  Sum: '<S100>/Add1'
     */
    rtb_Sin4 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Saturation_h = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Init_o);

    /* Product: '<S100>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S49>/C'
     *  Delay: '<S49>/MemoryX'
     *  Product: '<S102>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Init_o;

    /* Sum: '<S100>/Sum' incorporates:
     *  Constant: '<S49>/D'
     *  Product: '<S100>/C[k]*xhat[k|k-1]'
     *  Product: '<S100>/D[k]*u[k]'
     *  Sum: '<S100>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Init_o);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S100>/Product3' incorporates:
     *  Constant: '<S50>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Saturation_h) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S102>/Add1' incorporates:
     *  Product: '<S102>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S100>/Product3' incorporates:
     *  Constant: '<S50>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Saturation_h) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S102>/Add1' incorporates:
     *  Product: '<S102>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S102>/Product2' incorporates:
     *  Constant: '<S50>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S100>/Product3' incorporates:
       *  Outport: '<S100>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S102>/Product2' incorporates:
       *  Outport: '<S102>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S69>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem' */

  /* Sum: '<S76>/Add' incorporates:
   *  Delay: '<S49>/MemoryX'
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
   *  Constant: '<S217>/Constant'
   *  Logic: '<S217>/AND'
   *  MATLAB Function: '<S167>/Find closest index to curve'
   *  Product: '<S217>/Product'
   *  RelationalOperator: '<S217>/Relational Operator'
   *  RelationalOperator: '<S217>/Relational Operator1'
   *  Selector: '<S217>/Selector'
   *  Selector: '<S217>/Selector1'
   *  Selector: '<S218>/Selector'
   *  Sum: '<S217>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S170>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_hk == 0) {
      /* Disable for If: '<S173>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S175>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_hk = -1;

    /* End of Disable for If: '<S170>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S165>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S165>/Unit Delay'
       *  UnitDelay: '<S166>/Unit Delay'
       *  UnitDelay: '<S168>/Unit Delay'
       *  UnitDelay: '<S168>/Unit Delay1'
       *  UnitDelay: '<S218>/Unit Delay'
       *  UnitDelay: '<S218>/Unit Delay1'
       */
      Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;
      Robot_Control_DW.UnitDelay_DSTATE_hn = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_f4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_g4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_le = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_k = 0.0;

      /* End of InitializeConditions for SubSystem: '<S13>/Spline Path Following Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    /* Selector: '<S166>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S166>/Selector1' */

    /* Lookup_n-D: '<S165>/Capture Radius' incorporates:
     *  UnitDelay: '<S165>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S166>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S166>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S170>/If' incorporates:
     *  RelationalOperator: '<S170>/ '
     *  UnitDelay: '<S166>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_hk;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_hk = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S173>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S175>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S170>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S173>/Action Port'
       */
      /* InitializeConditions for If: '<S170>/If' incorporates:
       *  UnitDelay: '<S173>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S170>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S170>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S173>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S173>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* If: '<S173>/If' incorporates:
       *  Selector: '<S166>/Selector1'
       *  Selector: '<S173>/Selector'
       *  Selector: '<S176>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S173>/Increment_If_Rectangle_Check' */

      /* Sum: '<S173>/Minus' incorporates:
       *  Concatenate: '<S166>/Matrix Concatenate2'
       *  Selector: '<S173>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S173>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* If: '<S173>/If' incorporates:
       *  Selector: '<S166>/Selector1'
       *  Selector: '<S173>/Selector'
       *  Selector: '<S176>/Selector'
       *  Sum: '<S173>/Minus'
       */
      rtb_DeadZone = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S173>/Increment_If_Rectangle_Check' */

      /* Sum: '<S173>/Minus' incorporates:
       *  Concatenate: '<S166>/Matrix Concatenate2'
       *  Selector: '<S173>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_DeadZone;

      /* Math: '<S173>/Hypot' */
      rtb_Init_o = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S173>/Equal' */
      rtb_AND1_c = (Robot_Control_B.Spline_Num_Poses ==
                    Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S173>/Switch' incorporates:
       *  Logic: '<S173>/AND'
       *  Logic: '<S173>/OR'
       *  RelationalOperator: '<S173>/Relational Operator'
       *  UnitDelay: '<S173>/Unit Delay'
       */
      rtb_Swerve_Motors_Disabled = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Init_o <= rtb_Saturation_h) && rtb_AND1_c));

      /* If: '<S173>/If' */
      rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_o;
      if (!rtb_Swerve_Motors_Disabled) {
        if (!rtb_AND1_c) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Robot_Control_DW.If_ActiveSubsystem_o = rtAction;
      if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
        /* Disable for If: '<S175>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S173>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S175>/Action Port'
         */
        /* If: '<S175>/If' incorporates:
         *  RelationalOperator: '<S175>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S175>/Is_Last_Point' incorporates:
           *  ActionPort: '<S178>/Action Port'
           */
          /* InitializeConditions for If: '<S175>/If' incorporates:
           *  UnitDelay: '<S178>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S175>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S175>/Is_Last_Point' incorporates:
           *  ActionPort: '<S178>/Action Port'
           */
          /* Switch: '<S178>/Switch' incorporates:
           *  Constant: '<S180>/Constant'
           *  Logic: '<S178>/OR'
           *  RelationalOperator: '<S180>/Compare'
           *  UnitDelay: '<S178>/Unit Delay'
           */
          rtb_Is_Absolute_Steering = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
            (rtb_Init_o <= Spline_Stop_Radius));

          /* If: '<S178>/If' */
          if (rtb_Is_Absolute_Steering) {
            /* Outputs for IfAction SubSystem: '<S178>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S181>/Action Port'
             */
            /* Merge: '<S170>/Merge2' incorporates:
             *  Constant: '<S181>/Constant'
             *  SignalConversion generated from: '<S181>/Robot_Reached_Destination'
             */
            rtb_AND1_c = true;

            /* SignalConversion generated from: '<S181>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S181>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = false;

            /* End of Outputs for SubSystem: '<S178>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S178>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S182>/Action Port'
             */
            /* Merge: '<S170>/Merge2' incorporates:
             *  Constant: '<S182>/Constant'
             *  SignalConversion generated from: '<S182>/Robot_Reached_Destination'
             */
            rtb_AND1_c = false;

            /* SignalConversion generated from: '<S182>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S182>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = true;

            /* End of Outputs for SubSystem: '<S178>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S178>/If' */

          /* Merge: '<S170>/Merge4' incorporates:
           *  SignalConversion: '<S178>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S178>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Is_Absolute_Steering;

          /* End of Outputs for SubSystem: '<S175>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S175>/Increment_Search' incorporates:
           *  ActionPort: '<S177>/Action Port'
           */
          /* Merge: '<S170>/Merge2' incorporates:
           *  Constant: '<S177>/Constant'
           *  SignalConversion generated from: '<S177>/Robot_Reached_Destination'
           */
          rtb_AND1_c = false;

          /* SignalConversion generated from: '<S177>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S177>/Constant1'
           */
          rtb_Is_Absolute_Translation_g = false;

          /* Merge: '<S170>/Merge4' incorporates:
           *  Constant: '<S179>/FixPt Constant'
           *  SignalConversion: '<S177>/Signal Copy'
           *  Sum: '<S179>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S175>/Increment_Search' */
        }

        /* End of If: '<S175>/If' */
        /* End of Outputs for SubSystem: '<S173>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S173>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S176>/Action Port'
         */
        /* Sum: '<S183>/FixPt Sum1' incorporates:
         *  Constant: '<S183>/FixPt Constant'
         */
        rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S176>/Selector1' incorporates:
         *  Selector: '<S166>/Selector1'
         */
        rtb_Switch2_p2 = rtb_Ref_Poses[((int32_T)rtb_Init_o) - 1];

        /* Sum: '<S184>/Subtract' incorporates:
         *  Selector: '<S176>/Selector1'
         *  Sum: '<S184>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_p2 - rtb_Init;

        /* Selector: '<S176>/Selector1' incorporates:
         *  Selector: '<S166>/Selector1'
         */
        rtb_Switch1 = rtb_Ref_Poses[((int32_T)rtb_Init_o) + 9];

        /* Sum: '<S184>/Subtract' incorporates:
         *  Selector: '<S176>/Selector1'
         *  Sum: '<S184>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1 - rtb_DeadZone;

        /* Math: '<S184>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S184>/Divide' */
        rtb_Init_o = rtb_Minus_n[1];

        /* UnaryMinus: '<S184>/Unary Minus' */
        rtb_Switch2_nf = rtb_Minus_n[0];

        /* Product: '<S184>/Product' incorporates:
         *  Product: '<S184>/Divide'
         *  UnaryMinus: '<S184>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Init_o / rtb_Sin4) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Switch2_nf) / rtb_Sin4) * rtb_Saturation_h;

        /* Sum: '<S184>/Add1' incorporates:
         *  Sum: '<S184>/Add2'
         *  Sum: '<S184>/Minus'
         */
        rtb_Switch2_nf = rtb_Switch2_p2 - rtb_Minus_n[0];

        /* Sum: '<S184>/Minus4' incorporates:
         *  Sum: '<S184>/Add2'
         *  Sum: '<S184>/Minus'
         */
        rtb_Switch2_p2 = (rtb_Switch2_p2 + rtb_Minus_n[0]) - rtb_Switch2_nf;

        /* Sum: '<S184>/Minus5' incorporates:
         *  Concatenate: '<S166>/Matrix Concatenate2'
         *  Sum: '<S184>/Minus'
         */
        rtb_Switch2 = rtb_Reshapey[0] - rtb_Switch2_nf;

        /* Sum: '<S184>/Add' incorporates:
         *  Sum: '<S184>/Add2'
         *  Sum: '<S184>/Minus1'
         */
        rtb_Init_o = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S184>/Minus' incorporates:
         *  Sum: '<S184>/Minus1'
         */
        rtb_Switch2_nf -= rtb_Init_o;

        /* DotProduct: '<S184>/Dot Product' incorporates:
         *  Concatenate: '<S166>/Matrix Concatenate2'
         *  Sum: '<S184>/Minus'
         *  Sum: '<S184>/Minus1'
         *  Sum: '<S184>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Init_o) * rtb_Switch2_nf;

        /* DotProduct: '<S184>/Dot Product1' incorporates:
         *  Sum: '<S184>/Minus'
         */
        rtb_Init = rtb_Switch2_nf * rtb_Switch2_nf;

        /* DotProduct: '<S184>/Dot Product2' incorporates:
         *  Sum: '<S184>/Minus4'
         *  Sum: '<S184>/Minus5'
         */
        rtb_Minus_k_idx_1 = rtb_Switch2_p2 * rtb_Switch2;

        /* DotProduct: '<S184>/Dot Product3' incorporates:
         *  Sum: '<S184>/Minus4'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2 * rtb_Switch2_p2;

        /* Sum: '<S184>/Add1' incorporates:
         *  Sum: '<S184>/Add2'
         *  Sum: '<S184>/Minus'
         */
        rtb_Switch2_nf = rtb_Switch1 - rtb_Minus_n[1];

        /* Sum: '<S184>/Minus4' incorporates:
         *  Sum: '<S184>/Add2'
         *  Sum: '<S184>/Minus'
         */
        rtb_Switch2_p2 = (rtb_Switch1 + rtb_Minus_n[1]) - rtb_Switch2_nf;

        /* Sum: '<S184>/Minus5' incorporates:
         *  Concatenate: '<S166>/Matrix Concatenate2'
         *  Sum: '<S184>/Minus'
         */
        rtb_Switch2 = rtb_Reshapey[1] - rtb_Switch2_nf;

        /* Sum: '<S184>/Add' incorporates:
         *  Sum: '<S184>/Add2'
         *  Sum: '<S184>/Minus1'
         */
        rtb_Init_o = rtb_DeadZone - rtb_Minus_n[1];

        /* Sum: '<S184>/Minus' incorporates:
         *  Sum: '<S184>/Minus1'
         */
        rtb_Switch2_nf -= rtb_Init_o;

        /* DotProduct: '<S184>/Dot Product' incorporates:
         *  Concatenate: '<S166>/Matrix Concatenate2'
         *  Sum: '<S184>/Minus'
         *  Sum: '<S184>/Minus1'
         *  Sum: '<S184>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Init_o) * rtb_Switch2_nf;

        /* RelationalOperator: '<S185>/Compare' incorporates:
         *  Constant: '<S185>/Constant'
         */
        rtb_AND1_c = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S184>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S184>/Dot Product1'
         *  Sum: '<S184>/Minus'
         */
        rtb_Is_Absolute_Translation_g = (rtb_Sin4 <= ((rtb_Switch2_nf *
          rtb_Switch2_nf) + rtb_Init));

        /* DotProduct: '<S184>/Dot Product2' incorporates:
         *  Sum: '<S184>/Minus4'
         *  Sum: '<S184>/Minus5'
         */
        rtb_Sin4 = (rtb_Switch2_p2 * rtb_Switch2) + rtb_Minus_k_idx_1;

        /* Merge: '<S170>/Merge4' incorporates:
         *  Constant: '<S186>/Constant'
         *  DataTypeConversion: '<S176>/Data Type Conversion'
         *  DotProduct: '<S184>/Dot Product3'
         *  Logic: '<S184>/AND'
         *  RelationalOperator: '<S184>/LessThanOrEqual1'
         *  RelationalOperator: '<S186>/Compare'
         *  Sum: '<S176>/Add'
         *  Sum: '<S184>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_AND1_c &&
          rtb_Is_Absolute_Translation_g) && (rtb_Sin4 >= 0.0)) && (rtb_Sin4 <=
          ((rtb_Switch2_p2 * rtb_Switch2_p2) + rtb_MatrixConcatenate_b_idx_0))))
          + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S170>/Merge2' incorporates:
         *  Constant: '<S176>/Constant2'
         *  SignalConversion generated from: '<S176>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S176>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S176>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* End of Outputs for SubSystem: '<S173>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S173>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S174>/Action Port'
         */
        /* Merge: '<S170>/Merge2' incorporates:
         *  Constant: '<S174>/Constant2'
         *  SignalConversion generated from: '<S174>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S174>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S174>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* Merge: '<S170>/Merge4' incorporates:
         *  SignalConversion generated from: '<S174>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S173>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S170>/Merge1' incorporates:
       *  Constant: '<S173>/Constant'
       *  SignalConversion generated from: '<S173>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S173>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_Swerve_Motors_Disabled;

      /* End of Outputs for SubSystem: '<S170>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S170>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S172>/Action Port'
       */
      /* Merge: '<S170>/Merge1' incorporates:
       *  Constant: '<S172>/Constant'
       *  SignalConversion generated from: '<S172>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S170>/Merge2' incorporates:
       *  Constant: '<S172>/Constant1'
       *  SignalConversion generated from: '<S172>/Robot_Reached_Destination'
       */
      rtb_AND1_c = false;

      /* SignalConversion generated from: '<S172>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S172>/Constant2'
       */
      rtb_Is_Absolute_Translation_g = false;

      /* Merge: '<S170>/Merge4' incorporates:
       *  SignalConversion generated from: '<S172>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S170>/Escape_Auto_Driving' */
    }

    /* End of If: '<S170>/If' */

    /* If: '<S166>/If1' */
    if (!rtb_Is_Absolute_Translation_g) {
      /* Outputs for IfAction SubSystem: '<S166>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S171>/Action Port'
       */
      /* Bias: '<S187>/Add Constant' incorporates:
       *  Bias: '<S187>/Bias'
       *  Sum: '<S187>/Subtract'
       */
      rtb_Init_o = ((Robot_Control_B.Spline_Num_Poses -
                     Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S187>/Selector4' incorporates:
       *  Bias: '<S187>/Bias1'
       *  Constant: '<S189>/FixPt Constant'
       *  Sum: '<S189>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S187>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S187>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s192_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S187>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S187>/Selector5' incorporates:
       *  Concatenate: '<S187>/Matrix Concatenate'
       *  Gain: '<S191>/Gain'
       *  Selector: '<S166>/Selector1'
       *  Selector: '<S187>/Selector2'
       *  Selector: '<S187>/Selector3'
       *  Sum: '<S191>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s192_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S187>/Matrix Concatenate' incorporates:
       *  Bias: '<S187>/Add Constant1'
       *  Gain: '<S190>/Gain'
       *  Selector: '<S166>/Selector1'
       *  Selector: '<S187>/Selector'
       *  Selector: '<S187>/Selector1'
       *  Selector: '<S187>/Selector5'
       *  Sum: '<S190>/Subtract'
       */
      s192_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s192_iter;
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

      /* Selector: '<S187>/Selector4' */
      s192_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s192_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S187>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S187>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S187>/Assignment' incorporates:
       *  Concatenate: '<S187>/Matrix Concatenate'
       *  Selector: '<S187>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s192_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S188>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S192>/While Iterator'
       */
      s192_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s192_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s192_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s192_iter] - rtb_Assignment[s192_iter + 2];
        rtb_Switch2_p2 = rtb_Init - rtb_Assignment[s192_iter];
        rtb_Init = rtb_Assignment[s192_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s192_iter + 11];
        rtb_Switch2_nf = rtb_Assignment[s192_iter + 12];
        rtb_Add2[1] = rtb_Switch2_nf - rtb_Assignment[s192_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Init - rtb_Switch2_nf;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Sin4 = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_DeadZone = rt_powd_snf(rtb_Sin4, 2.0);
          rtb_Init = rt_powd_snf(rtb_Sin4, 3.0);
          rtb_Switch1 = (rtb_Sin4 - (2.0 * rtb_DeadZone)) + rtb_Init;
          rtb_Switch2 = rtb_DeadZone - rtb_Init;
          rtb_Init = (3.0 * rtb_DeadZone) - (2.0 * rtb_Init);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch1) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Switch2_p2 * rtb_Init)) +
            rtb_Assignment[s192_iter];
          rtb_Init = ((((rtb_Minus_n[1] * rtb_Switch1) + (rtb_Add2[1] *
            rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Init)) +
            rtb_Switch2_nf;
          rtb_Switch1 = ((3.0 * rtb_DeadZone) - (4.0 * rtb_Sin4)) + 1.0;
          rtb_Switch2 = (2.0 * rtb_Sin4) - (3.0 * rtb_DeadZone);
          rtb_DeadZone = (rtb_Sin4 - rtb_DeadZone) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch1) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Switch2_p2 * rtb_DeadZone);
          rtb_Switch2_ow = (((rtb_Minus_n[1] * rtb_Switch1) + (rtb_Add2[1] *
            rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_DeadZone);
          rtb_DeadZone = (6.0 * rtb_Sin4) - 4.0;
          rtb_Switch1 = (-6.0 * rtb_Sin4) + 2.0;
          rtb_Sin4 = (-12.0 * rtb_Sin4) + 6.0;
          rtb_Switch2 = (((rtb_Minus_n[0] * rtb_DeadZone) + (rtb_Add2[0] *
            rtb_Switch1)) * 0.5) + (rtb_Switch2_p2 * rtb_Sin4);
          rtb_Switch1 = (((rtb_Minus_n[1] * rtb_DeadZone) + (rtb_Add2[1] *
            rtb_Switch1)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Sin4);
          rtb_DeadZone = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Switch2_ow), 3.0);
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
              rtb_Switch2_ow)) / (rtb_Sin4 * rtb_DeadZone);
        }

        if (s192_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s192_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Init_o - ((real_T)s192_iter);
        rtb_Num_Segments = s192_iter;
        s192_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s192_iter <= 3));

      /* End of Outputs for SubSystem: '<S188>/Sampling_Loop' */

      /* SignalConversion generated from: '<S171>/Position_and_Curvature' incorporates:
       *  Assignment: '<S192>/Assignment'
       *  Merge: '<S166>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S166>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem' incorporates:
       *  ActionPort: '<S169>/Action Port'
       */
      /* Product: '<S169>/Product' incorporates:
       *  Selector: '<S166>/Selector'
       *  Selector: '<S166>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1];

      /* Product: '<S169>/Product1' incorporates:
       *  Selector: '<S166>/Selector'
       *  Selector: '<S166>/Selector1'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S169>/Product' incorporates:
         *  Constant: '<S169>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S169>/Product1' incorporates:
         *  Constant: '<S169>/Constant2'
         *  Product: '<S169>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Init_o;
      }

      /* Assignment: '<S169>/Assignment' incorporates:
       *  Concatenate: '<S169>/Matrix Concatenate'
       *  Merge: '<S166>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S169>/Assignment' */

      /* SignalConversion generated from: '<S169>/Num_Segments' incorporates:
       *  Constant: '<S169>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S166>/If Action Subsystem' */
    }

    /* End of If: '<S166>/If1' */

    /* Concatenate: '<S167>/Matrix Concatenate' incorporates:
     *  Merge: '<S166>/Merge'
     *  Selector: '<S167>/Selector'
     *  Selector: '<S167>/Selector1'
     *  Selector: '<S167>/Selector3'
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

    /* End of Concatenate: '<S167>/Matrix Concatenate' */

    /* MATLAB Function: '<S167>/Distance Along Curve' incorporates:
     *  Concatenate: '<S167>/Matrix Concatenate'
     *  Selector: '<S167>/Selector4'
     *  Selector: '<S167>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s192_iter = 0; s192_iter < 149; s192_iter++) {
      /* Outputs for Iterator SubSystem: '<S188>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S192>/While Iterator'
       */
      rtb_Assignment_d[s192_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s192_iter + 1] -
         rtb_MatrixConcatenate_o[s192_iter], rtb_MatrixConcatenate_o[s192_iter +
         151] - rtb_MatrixConcatenate_o[s192_iter + 150]) +
        rtb_Assignment_d[s192_iter];

      /* End of Outputs for SubSystem: '<S188>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S167>/Distance Along Curve' */

    /* MATLAB Function: '<S167>/Find closest index to curve' incorporates:
     *  Concatenate: '<S167>/Matrix Concatenate'
     *  Selector: '<S167>/Selector4'
     *  Selector: '<S167>/Selector5'
     *  Selector: '<S218>/Selector'
     */
    for (s192_iter = 0; s192_iter < 150; s192_iter++) {
      /* Outputs for Iterator SubSystem: '<S188>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S192>/While Iterator'
       */
      distance_from_robot[s192_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s192_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s192_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S188>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s192_iter = 1;
    } else {
      s192_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s192_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s192_iter == 0) {
      rtb_Init_o = distance_from_robot[0];
    } else {
      rtb_Init_o = distance_from_robot[s192_iter - 1];
      for (rtb_Bias1_p = s192_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Init_o > rtb_Sin4) {
          rtb_Init_o = rtb_Sin4;
        }
      }
    }

    s192_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s192_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Init_o) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S218>/Selector' incorporates:
     *  Constant: '<S218>/Constant'
     *  MATLAB Function: '<S167>/Find closest index to curve'
     *  MinMax: '<S218>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s192_iter)) - 1];

    /* If: '<S218>/If' incorporates:
     *  RelationalOperator: '<S218>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S218>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S221>/Action Port'
       */
      /* SignalConversion generated from: '<S221>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S223>/FixPt Sum1' incorporates:
       *  Constant: '<S223>/FixPt Constant'
       */
      rtb_Init_o = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S221>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S221>/Selector11'
       *  Selector: '<S221>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S221>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S221>/Selector1'
       *  Selector: '<S221>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S221>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S221>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Init_o), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S221>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S221>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S221>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S218>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S218>/Latch' incorporates:
       *  ActionPort: '<S222>/Action Port'
       */
      /* SignalConversion generated from: '<S222>/In1' incorporates:
       *  UnitDelay: '<S218>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S222>/In2' incorporates:
       *  UnitDelay: '<S218>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S218>/Latch' */
    }

    /* End of If: '<S218>/If' */

    /* MinMax: '<S165>/Min' incorporates:
     *  Lookup_n-D: '<S165>/Lookahead Distance'
     *  UnitDelay: '<S165>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S167>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S217>/While Iterator'
     */
    s217_iter = 1U;
    rtb_Swerve_Motors_Disabled = true;
    while (rtb_Swerve_Motors_Disabled && (s217_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S167>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S217>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s217_iter;
      rtb_Swerve_Motors_Disabled =
        ((rtb_Assignment_d[Robot_Control_B.WhileIterator - 1] <=
          (rtb_Assignment_d[s192_iter - 1] + rtb_Saturation_h)) &&
         (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s217_iter++;
    }

    /* End of Outputs for SubSystem: '<S167>/Find first index that meets distance target' */

    /* Switch: '<S220>/Switch' incorporates:
     *  Concatenate: '<S167>/Matrix Concatenate'
     *  Constant: '<S167>/Constant'
     *  Constant: '<S217>/Constant'
     *  Constant: '<S220>/Constant'
     *  Constant: '<S220>/Constant1'
     *  Constant: '<S220>/Constant2'
     *  Constant: '<S220>/Constant3'
     *  Logic: '<S217>/AND'
     *  MATLAB Function: '<S167>/Find closest index to curve'
     *  Math: '<S220>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S220>/Max'
     *  MinMax: '<S220>/Min'
     *  MinMax: '<S220>/Min1'
     *  Product: '<S217>/Product'
     *  Product: '<S220>/Divide'
     *  Product: '<S220>/Product'
     *  Product: '<S220>/Product1'
     *  RelationalOperator: '<S167>/Relational Operator'
     *  RelationalOperator: '<S217>/Relational Operator'
     *  RelationalOperator: '<S217>/Relational Operator1'
     *  Selector: '<S167>/Selector10'
     *  Selector: '<S167>/Selector7'
     *  Selector: '<S167>/Selector8'
     *  Selector: '<S167>/Selector9'
     *  Selector: '<S217>/Selector'
     *  Selector: '<S217>/Selector1'
     *  Selector: '<S218>/Selector'
     *  Sqrt: '<S220>/Sqrt'
     *  Sum: '<S167>/Subtract'
     *  Sum: '<S217>/Add'
     *  Sum: '<S220>/Subtract'
     *  Sum: '<S220>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Saturation_h = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Init_o *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Saturation_h = fmin(rtb_Init_o * Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5)));
    }

    /* End of Switch: '<S220>/Switch' */

    /* Logic: '<S168>/OR' */
    rtb_Is_Absolute_Translation_g = (rtb_AND1_c ||
      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S168>/Switch1' incorporates:
     *  Switch: '<S168>/Switch'
     *  UnitDelay: '<S168>/Unit Delay'
     */
    if (rtb_Is_Absolute_Translation_g) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S168>/Constant3'
       *  SignalConversion: '<S168>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S168>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S168>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S168>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S167>/Selector6' incorporates:
     *  Concatenate: '<S167>/Matrix Concatenate'
     *  Selector: '<S167>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S167>/Selector2' incorporates:
     *  Concatenate: '<S167>/Matrix Concatenate'
     *  Selector: '<S167>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S168>/Switch2' incorporates:
     *  Sum: '<S224>/Subtract'
     *  Sum: '<S224>/Subtract1'
     *  Trigonometry: '<S224>/Atan2'
     *  UnitDelay: '<S168>/Unit Delay1'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_DeadZone = Robot_Control_DW.UnitDelay1_DSTATE_k;
    } else {
      rtb_DeadZone = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S168>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S168>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_DeadZone;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S165>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_AND1_c;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S165>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S168>/Constant2'
     *  SignalConversion generated from: '<S165>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S168>/Constant5'
     *  SignalConversion generated from: '<S165>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S168>/Constant6'
     *  SignalConversion generated from: '<S165>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S165>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S166>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S165>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S218>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Init_o;

    /* Update for UnitDelay: '<S218>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S168>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S168>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_k = rtb_DeadZone;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S164>/Constant1'
     *  SignalConversion generated from: '<S164>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S164>/Constant'
     *  SignalConversion generated from: '<S164>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S164>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S164>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S164>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S164>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S164>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S164>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S164>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S314>/Sign2' incorporates:
   *  UnitDelay: '<S314>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_nt = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S314>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S314>/Product1' incorporates:
   *  Signum: '<S314>/Sign1'
   *  Signum: '<S314>/Sign2'
   */
  rtb_Add_nt *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_nt)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_nt, 256.0);
  }

  /* Switch: '<S314>/Switch' incorporates:
   *  Constant: '<S314>/Constant'
   *  Constant: '<S319>/Constant'
   *  Constant: '<S320>/Constant'
   *  Logic: '<S314>/or'
   *  Product: '<S314>/Product1'
   *  RelationalOperator: '<S319>/Compare'
   *  RelationalOperator: '<S320>/Compare'
   *  UnitDelay: '<S314>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S314>/Switch' */

  /* Switch: '<S325>/Init' incorporates:
   *  UnitDelay: '<S325>/FixPt Unit Delay1'
   *  UnitDelay: '<S325>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S325>/Init' */

  /* RelationalOperator: '<S321>/Compare' incorporates:
   *  Constant: '<S321>/Constant'
   */
  rtb_Swerve_Motors_Disabled = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S322>/Compare' incorporates:
   *  Constant: '<S322>/Constant'
   */
  rtb_AND1_c = (rtb_Sin4 > 0.0);

  /* Abs: '<S314>/Abs' incorporates:
   *  Sum: '<S314>/Subtract'
   *  UnitDelay: '<S314>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S314>/Switch5' incorporates:
   *  Constant: '<S314>/Constant1'
   *  Switch: '<S314>/Switch1'
   *  UnaryMinus: '<S314>/Unary Minus'
   */
  if (rtb_Swerve_Motors_Disabled) {
    /* SignalConversion generated from: '<S314>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S314>/Constant4'
     *  Constant: '<S314>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S314>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S314>/Constant2'
     *  Constant: '<S314>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S314>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S314>/Lookup Table Dynamic'
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
    rtb_Add_nt = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S314>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S314>/Constant10'
     *  Constant: '<S314>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S314>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S314>/Constant7'
     *  Constant: '<S314>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S314>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S314>/Lookup Table Dynamic1'
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

    /* Switch: '<S314>/Switch3' incorporates:
     *  Constant: '<S314>/Constant1'
     *  Constant: '<S314>/Constant3'
     *  UnaryMinus: '<S314>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_nt = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_nt = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S314>/Switch3' */
  }

  /* End of Switch: '<S314>/Switch5' */

  /* Product: '<S314>/Product' incorporates:
   *  Switch: '<S314>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_nt * rtb_Merge1;

  /* Sum: '<S323>/Sum1' */
  rtb_Saturation_h = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S324>/Switch2' incorporates:
   *  RelationalOperator: '<S324>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S314>/Switch2' incorporates:
     *  Constant: '<S314>/Constant1'
     *  Switch: '<S314>/Switch4'
     */
    if (rtb_Swerve_Motors_Disabled) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S314>/Switch4' incorporates:
       *  Constant: '<S314>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S314>/Switch4' incorporates:
       *  Constant: '<S314>/Constant3'
       *  UnaryMinus: '<S314>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S314>/Switch2' */

    /* Product: '<S314>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S324>/Switch' incorporates:
     *  RelationalOperator: '<S324>/UpperRelop'
     */
    if (rtb_Saturation_h < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Saturation_h;
    }

    /* End of Switch: '<S324>/Switch' */
  }

  /* End of Switch: '<S324>/Switch2' */

  /* Sum: '<S323>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S317>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S317>/Switch' incorporates:
     *  Constant: '<S349>/Constant3'
     *  Constant: '<S349>/Constant4'
     *  Math: '<S349>/Math Function'
     *  Sum: '<S317>/Subtract'
     *  Sum: '<S349>/Add1'
     *  Sum: '<S349>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S317>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S317>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_nt = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_nt)) || (rtIsInf(rtb_Add_nt))) {
    rtb_Add_nt = 0.0;
  } else {
    rtb_Add_nt = fmod(rtb_Add_nt, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Add_nt < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Add_nt)))))) : ((int32_T)((uint8_T)rtb_Add_nt)));

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* Sum: '<S109>/Subtract' incorporates:
   *  Constant: '<S109>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Sin4 = Rebuilt_Match_Time_TeleOp - Robot_Control_U.MatchTime;

  /* If: '<S109>/If' incorporates:
   *  Constant: '<S135>/Constant'
   *  Constant: '<S136>/Constant'
   *  Constant: '<S137>/Constant'
   *  Constant: '<S138>/Constant'
   *  Constant: '<S139>/Constant'
   *  Constant: '<S140>/Constant'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S135>/Compare'
   *  RelationalOperator: '<S136>/Compare'
   *  RelationalOperator: '<S137>/Compare'
   *  RelationalOperator: '<S138>/Compare'
   *  RelationalOperator: '<S139>/Compare'
   *  RelationalOperator: '<S140>/Compare'
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
      /* InitializeConditions for IfAction SubSystem: '<S109>/If Action Subsystem' incorporates:
       *  ActionPort: '<S141>/Action Port'
       */
      /* InitializeConditions for If: '<S109>/If' incorporates:
       *  UnitDelay: '<S141>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_ll = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S109>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    /* Merge: '<S109>/Merge' incorporates:
     *  Constant: '<S141>/Constant'
     *  SignalConversion generated from: '<S141>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S109>/Merge1' incorporates:
     *  Constant: '<S141>/Constant'
     *  SignalConversion generated from: '<S141>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S141>/Sum' incorporates:
     *  Constant: '<S141>/Constant1'
     *  UnitDelay: '<S141>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_ll - 0.02;

    /* Merge: '<S109>/Merge2' incorporates:
     *  SignalConversion: '<S141>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S141>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ll = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S145>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S146>/Action Port'
     */
    /* Merge: '<S109>/Merge' incorporates:
     *  Constant: '<S146>/Constant'
     *  SignalConversion generated from: '<S146>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S109>/Merge1' incorporates:
     *  Constant: '<S146>/Constant'
     *  SignalConversion generated from: '<S146>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S146>/Sum' incorporates:
     *  Constant: '<S146>/Constant1'
     *  UnitDelay: '<S146>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_n - 0.02;

    /* Merge: '<S109>/Merge2' incorporates:
     *  SignalConversion: '<S146>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S146>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S109>/If' */

  /* If: '<S148>/If' incorporates:
   *  If: '<S149>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S148>/Blue' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    /* Merge: '<S148>/Merge' incorporates:
     *  Constant: '<S150>/BlueAllianceZoneX'
     *  Logic: '<S150>/AND'
     *  RelationalOperator: '<S150>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S148>/Blue' */

    /* Outputs for IfAction SubSystem: '<S149>/Blue' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    /* Merge: '<S149>/Merge' incorporates:
     *  Constant: '<S152>/BlueAllianceZoneX'
     *  RelationalOperator: '<S152>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S149>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S148>/Red' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    /* Merge: '<S148>/Merge' incorporates:
     *  Constant: '<S151>/RedAllianceZoneX'
     *  Logic: '<S151>/AND'
     *  RelationalOperator: '<S151>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S148>/Red' */

    /* Outputs for IfAction SubSystem: '<S149>/Red' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    /* Merge: '<S149>/Merge' incorporates:
     *  Constant: '<S153>/RedAllianceZoneX'
     *  RelationalOperator: '<S153>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S149>/Red' */
  }

  /* End of If: '<S148>/If' */

  /* RelationalOperator: '<S111>/GreaterThan' incorporates:
   *  Constant: '<S111>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S111>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S111>/Relational Operator' incorporates:
   *  Abs: '<S111>/Abs'
   *  Constant: '<S147>/Constant3'
   *  Constant: '<S147>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S147>/Math Function'
   *  Sum: '<S111>/Subtract'
   *  Sum: '<S147>/Add1'
   *  Sum: '<S147>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S110>/Max' incorporates:
   *  Abs: '<S110>/Abs1'
   *  Abs: '<S110>/Abs2'
   *  Abs: '<S110>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S111>/Relational Operator1' incorporates:
   *  Abs: '<S111>/Abs1'
   *  Constant: '<S111>/Constant2'
   *  Sum: '<S111>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S111>/Relational Operator4' incorporates:
   *  Abs: '<S111>/Abs4'
   *  Constant: '<S111>/Constant1'
   *  Sum: '<S111>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S111>/AND' */
  rtb_Swerve_Motors_Disabled = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
    (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S111>/AND2' incorporates:
   *  Logic: '<S111>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Swerve_Motors_Disabled);

  /* SignalConversion: '<S111>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S111>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Swerve_Motors_Disabled);

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
    if ((rtb_Button_Spinup_Enable != 0) || (rtb_Button_Shoot_Enable != 0)) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.RB_Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
      guard2 = true;
    } else {
      guard1 = true;
    }
  } else {
    /* case IN_Shooting: */
    Robot_Control_B.RB_Shooter_Active = true;
    if ((rtb_Button_Spinup_Enable == 0) && (rtb_Button_Shoot_Enable == 0)) {
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
        if (rtb_Button_Shoot_Enable == 0) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        }
        break;

       case Robot_Control_IN_Spinning_Up:
        Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        if ((rtb_Button_Shoot_Enable != 0) &&
            ((Robot_Control_B.RB_Ready_to_Score) ||
             (Robot_Control_B.RB_Ready_to_Pass))) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Transfer;
          Robot_Control_B.RB_Desired_Feeder_Speed =
            Rebuilt_Negative_Feeder_Speed;
          Robot_Control_B.RB_Desired_Transfer_Speed =
            Rebuilt_Target_Transfer_Speed;
          Robot_Control_B.RB_Transfer_Init = 1.0;
        }
        break;

       default:
        /* case IN_Transfer: */
        Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Negative_Feeder_Speed;
        Robot_Control_B.RB_Transfer_Init = 1.0;
        if (Robot_Control_U.Measured_Transfer_Speed >
            (Robot_Control_B.RB_Desired_Transfer_Speed *
             Rebuilt_Transfer_Minimum_Factor)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Feeder;
          Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
          Robot_Control_B.RB_Transfer_Init = 0.0;
        } else if (rtb_Button_Shoot_Enable == 0) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        }
        break;
      }

      guard2 = true;
    }
  }

  if (guard2) {
    /* Outputs for IfAction SubSystem: '<S108>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S117>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S119>/While Iterator'
     */
    /* If: '<S108>/If' incorporates:
     *  Constant: '<S117>/Constant'
     *  Constant: '<S118>/Constant'
     *  Constant: '<S120>/Constant1'
     *  Constant: '<S120>/Constant10'
     *  Constant: '<S120>/Constant2'
     *  Constant: '<S120>/Constant5'
     *  Constant: '<S120>/Constant6'
     *  Constant: '<S120>/Constant7'
     *  Constant: '<S120>/Constant8'
     *  Constant: '<S120>/Constant9'
     *  Constant: '<S121>/Constant1'
     *  Constant: '<S121>/Constant10'
     *  Constant: '<S121>/Constant2'
     *  Constant: '<S121>/Constant5'
     *  Constant: '<S121>/Constant6'
     *  Constant: '<S121>/Constant7'
     *  Constant: '<S121>/Constant8'
     *  Constant: '<S121>/Constant9'
     *  Constant: '<S122>/Constant'
     *  Constant: '<S122>/Constant1'
     *  Constant: '<S122>/Constant2'
     *  Constant: '<S124>/Constant1'
     *  Constant: '<S124>/Constant10'
     *  Constant: '<S124>/Constant2'
     *  Constant: '<S124>/Constant5'
     *  Constant: '<S124>/Constant6'
     *  Constant: '<S124>/Constant7'
     *  Constant: '<S124>/Constant8'
     *  Constant: '<S124>/Constant9'
     *  Constant: '<S127>/Constant'
     *  Constant: '<S127>/Constant1'
     *  Constant: '<S127>/Constant11'
     *  Constant: '<S127>/Constant2'
     *  Constant: '<S127>/Constant3'
     *  Constant: '<S127>/Constant4'
     *  Constant: '<S127>/Constant5'
     *  Constant: '<S127>/Constant6'
     *  Constant: '<S133>/Constant1'
     *  Constant: '<S133>/Constant10'
     *  Constant: '<S133>/Constant2'
     *  Constant: '<S133>/Constant5'
     *  Constant: '<S133>/Constant6'
     *  Constant: '<S133>/Constant7'
     *  Constant: '<S133>/Constant8'
     *  Constant: '<S133>/Constant9'
     *  Constant: '<S134>/Constant1'
     *  Constant: '<S134>/Constant10'
     *  Constant: '<S134>/Constant2'
     *  Constant: '<S134>/Constant5'
     *  Constant: '<S134>/Constant6'
     *  Constant: '<S134>/Constant7'
     *  Constant: '<S134>/Constant8'
     *  Constant: '<S134>/Constant9'
     *  Gain: '<S125>/Gain1'
     *  Gain: '<S132>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S119>/Memory'
     *  Memory: '<S119>/Memory1'
     *  Memory: '<S119>/Memory2'
     *  Memory: '<S119>/Memory3'
     *  Merge: '<S108>/Merge'
     *  Merge: '<S108>/Merge2'
     *  Merge: '<S108>/Merge3'
     *  RelationalOperator: '<S122>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S120>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S121>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S122>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S122>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S120>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S127>/Lookup Table Dynamic'
     *  Sum: '<S118>/Add'
     *  Sum: '<S118>/Subtract'
     *  Sum: '<S118>/Subtract1'
     *  Sum: '<S122>/Add'
     *  Switch: '<S122>/Switch'
     *  Switch: '<S122>/Switch1'
     *  Switch: '<S123>/Switch4'
     *  Switch: '<S123>/Switch5'
     *  Switch: '<S123>/Switch6'
     *  Trigonometry: '<S118>/Tanh'
     *  UnitDelay: '<S122>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S117>/Iterate_Shot_Target' */
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
      /* Switch: '<S123>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S123>/Switch4' incorporates:
         *  Constant: '<S123>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S123>/Switch4' incorporates:
         *  Constant: '<S123>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S123>/Switch2' */

      /* Switch: '<S123>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S123>/Switch6' incorporates:
         *  Constant: '<S123>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S123>/Switch6' incorporates:
         *  Constant: '<S123>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S123>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S123>/Switch5' incorporates:
         *  Constant: '<S123>/Constant8'
         *  Switch: '<S123>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S123>/Switch4' incorporates:
         *  Constant: '<S123>/Constant9'
         *  Switch: '<S123>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S123>/Switch6' incorporates:
       *  Constant: '<S123>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S117>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S119>/While Iterator'
     */
    rtb_Button_Spinup_Enable = 1U;
    rtb_Merge1 = 0.0;
    rtb_Saturation_h = 0.0;
    rtb_Init_o = 0.0;
    rtb_AND1_c = true;
    rtb_Swerve_Motors_Disabled = true;
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_Swerve_Motors_Disabled && (rtb_Button_Spinup_Enable <= 10)) {
      /* Switch: '<S128>/Switch' incorporates:
       *  Memory: '<S119>/Memory1'
       *  Memory: '<S119>/Memory2'
       *  Switch: '<S128>/Switch1'
       */
      if (rtb_Button_Spinup_Enable > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_DeadZone = rtb_Saturation_h;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_DeadZone = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S128>/Switch' */

      /* Math: '<S126>/Hypot' incorporates:
       *  Sum: '<S126>/Subtract'
       *  Sum: '<S126>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_DeadZone -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S127>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S127>/Lookup Table Dynamic'
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

      /* Sum: '<S129>/Subtract' incorporates:
       *  Memory: '<S119>/Memory3'
       *  Sum: '<S129>/Subtract1'
       */
      rtb_Merge1 = rtb_TOF - rtb_Init_o;

      /* Sum: '<S129>/Add' incorporates:
       *  Gain: '<S129>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S129>/Product'
       *  Sum: '<S129>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S129>/Add1' incorporates:
       *  Gain: '<S129>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S129>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_DeadZone;

      /* Memory: '<S119>/Memory' */
      rtb_Swerve_Motors_Disabled = rtb_AND1_c;

      /* Update for Memory: '<S119>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S119>/Memory2' */
      rtb_Saturation_h = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S119>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S119>/Memory' incorporates:
       *  Constant: '<S131>/Constant'
       *  Math: '<S130>/Hypot'
       *  RelationalOperator: '<S131>/Compare'
       *  Sum: '<S130>/Subtract'
       *  Sum: '<S130>/Subtract1'
       */
      rtb_AND1_c = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X - rtb_Sin4,
        Robot_Control_B.RB_Desired_Target_Y - rtb_DeadZone) >=
                    Rebuilt_Shoot_Target_Error_Thresh);
      rtb_Button_Spinup_Enable++;
    }

    /* End of Outputs for SubSystem: '<S117>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S121>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S120>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S122>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S122>/Lookup Table Dynamic1'
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
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
    }

    if (rtb_Merge1 < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S108>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S108>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_LookupTableDynamic_b;
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S108>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_nt = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Minus_k_idx_1 = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S108>/Shooter Not Active' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    /* If: '<S108>/If' incorporates:
     *  Constant: '<S116>/Constant'
     *  Constant: '<S116>/Constant1'
     *  Constant: '<S116>/Constant2'
     *  Merge: '<S108>/Merge'
     *  Merge: '<S108>/Merge1'
     *  Merge: '<S108>/Merge2'
     *  Merge: '<S108>/Merge3'
     *  SignalConversion generated from: '<S116>/Desired_Gyro_Angle'
     *  UnitDelay: '<S108>/Unit Delay'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot =
      Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S108>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_nt = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S345>/Add1' incorporates:
   *  Constant: '<S345>/Constant3'
   *  Constant: '<S345>/Constant4'
   *  Math: '<S345>/Math Function'
   *  Sum: '<S344>/Sum'
   *  Sum: '<S345>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_nt - rtb_Minus_k_idx_1) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S347>/Sum1' incorporates:
   *  Constant: '<S344>/Constant2'
   *  Product: '<S347>/Product'
   *  Sum: '<S347>/Sum'
   *  UnitDelay: '<S347>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Optimized_Module_Angle_p -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S344>/Product' incorporates:
   *  Constant: '<S344>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S346>/Diff' incorporates:
   *  UnitDelay: '<S346>/UD'
   *
   * Block description for '<S346>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S346>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S344>/Saturation' */
  if (rtb_Add_nt > Steering_Heading_Control_D_UL) {
    rtb_Add_nt = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Heading_Control_D_LL) {
    rtb_Add_nt = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S344>/Add' incorporates:
   *  Gain: '<S344>/Gain1'
   *  Saturate: '<S344>/Saturation'
   */
  rtb_Init_o = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_nt;

  /* Sum: '<S344>/Subtract' incorporates:
   *  Constant: '<S344>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Init_o;

  /* Sum: '<S344>/Sum2' incorporates:
   *  Gain: '<S344>/Gain2'
   *  UnitDelay: '<S344>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p)
    + Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S348>/Switch2' incorporates:
   *  RelationalOperator: '<S348>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Sin4)) {
    /* Sum: '<S344>/Subtract1' incorporates:
     *  Constant: '<S344>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Init_o;

    /* Switch: '<S348>/Switch' incorporates:
     *  RelationalOperator: '<S348>/UpperRelop'
     */
    if (!(rtb_Saturation_h < rtb_Sin4)) {
      rtb_Sin4 = rtb_Saturation_h;
    }

    /* End of Switch: '<S348>/Switch' */
  }

  /* End of Switch: '<S348>/Switch2' */

  /* Saturate: '<S344>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Saturation_h = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Saturation_h = Steering_Heading_Control_I_LL;
  } else {
    rtb_Saturation_h = rtb_Sin4;
  }

  /* End of Saturate: '<S344>/Saturation1' */

  /* Sum: '<S344>/Add1' */
  rtb_Add_nt = rtb_Init_o + rtb_Saturation_h;

  /* Saturate: '<S344>/Saturation2' */
  if (rtb_Add_nt > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S344>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_nt < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S344>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S344>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_nt;
  }

  /* End of Saturate: '<S344>/Saturation2' */

  /* Switch: '<S328>/Switch' incorporates:
   *  Abs: '<S328>/Abs'
   *  Constant: '<S328>/Constant'
   *  Constant: '<S343>/Constant'
   *  RelationalOperator: '<S343>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Optimized_Module_Angle_p = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Optimized_Module_Angle_p = 0.0;
  }

  /* End of Switch: '<S328>/Switch' */

  /* Signum: '<S327>/Sign2' incorporates:
   *  UnitDelay: '<S327>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_nt = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S327>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S327>/Product1' incorporates:
   *  Signum: '<S327>/Sign1'
   *  Signum: '<S327>/Sign2'
   */
  rtb_Add_nt *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_nt)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_nt, 256.0);
  }

  /* Switch: '<S327>/Switch' incorporates:
   *  Constant: '<S327>/Constant'
   *  Constant: '<S336>/Constant'
   *  Constant: '<S337>/Constant'
   *  Logic: '<S327>/or'
   *  Product: '<S327>/Product1'
   *  RelationalOperator: '<S336>/Compare'
   *  RelationalOperator: '<S337>/Compare'
   *  UnitDelay: '<S327>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_nf = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_nf = 0.0;
  }

  /* End of Switch: '<S327>/Switch' */

  /* Switch: '<S342>/Init' incorporates:
   *  UnitDelay: '<S342>/FixPt Unit Delay1'
   *  UnitDelay: '<S342>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Switch2_nf;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S342>/Init' */

  /* RelationalOperator: '<S338>/Compare' incorporates:
   *  Constant: '<S338>/Constant'
   */
  rtb_Swerve_Motors_Disabled = (rtb_Switch2_nf == 0.0);

  /* RelationalOperator: '<S339>/Compare' incorporates:
   *  Constant: '<S339>/Constant'
   */
  rtb_AND1_c = (rtb_Switch2_nf > 0.0);

  /* Abs: '<S327>/Abs' incorporates:
   *  Sum: '<S327>/Subtract'
   *  UnitDelay: '<S327>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S327>/Switch5' incorporates:
   *  Constant: '<S327>/Constant1'
   *  Switch: '<S327>/Switch1'
   *  UnaryMinus: '<S327>/Unary Minus'
   */
  if (rtb_Swerve_Motors_Disabled) {
    /* SignalConversion generated from: '<S327>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S327>/Constant4'
     *  Constant: '<S327>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S327>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S327>/Constant2'
     *  Constant: '<S327>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S327>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S327>/Lookup Table Dynamic'
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
    rtb_Add_nt = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S327>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S327>/Constant10'
     *  Constant: '<S327>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S327>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S327>/Constant7'
     *  Constant: '<S327>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S327>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S327>/Lookup Table Dynamic1'
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

    /* Switch: '<S327>/Switch3' incorporates:
     *  Constant: '<S327>/Constant1'
     *  Constant: '<S327>/Constant3'
     *  UnaryMinus: '<S327>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_nt = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_nt = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S327>/Switch3' */
  }

  /* End of Switch: '<S327>/Switch5' */

  /* Product: '<S327>/Product' incorporates:
   *  Switch: '<S327>/Switch1'
   */
  rtb_Init = rtb_Add_nt * rtb_Sin4;

  /* Sum: '<S340>/Sum1' */
  rtb_DeadZone = rtb_Switch2_nf - rtb_Init_o;

  /* Switch: '<S341>/Switch2' incorporates:
   *  RelationalOperator: '<S341>/LowerRelop1'
   */
  if (!(rtb_DeadZone > rtb_Init)) {
    /* Switch: '<S327>/Switch2' incorporates:
     *  Constant: '<S327>/Constant1'
     *  Constant: '<S327>/Constant3'
     *  Switch: '<S327>/Switch4'
     *  UnaryMinus: '<S327>/Unary Minus1'
     */
    if (rtb_Swerve_Motors_Disabled) {
      rtb_Add_nt = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S327>/Switch4' incorporates:
       *  Constant: '<S327>/Constant1'
       */
      rtb_Add_nt = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_nt = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S327>/Product2' incorporates:
     *  Switch: '<S327>/Switch2'
     */
    rtb_Switch1 = rtb_Add_nt * rtb_Sin4;

    /* Switch: '<S341>/Switch' incorporates:
     *  RelationalOperator: '<S341>/UpperRelop'
     */
    if (rtb_DeadZone < rtb_Switch1) {
      rtb_Init = rtb_Switch1;
    } else {
      rtb_Init = rtb_DeadZone;
    }

    /* End of Switch: '<S341>/Switch' */
  }

  /* End of Switch: '<S341>/Switch2' */

  /* Sum: '<S340>/Sum' */
  rtb_Init_o += rtb_Init;

  /* Signum: '<S326>/Sign2' incorporates:
   *  UnitDelay: '<S326>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_nt = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S326>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S326>/Product1' incorporates:
   *  Signum: '<S326>/Sign1'
   *  Signum: '<S326>/Sign2'
   */
  rtb_Add_nt *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_nt)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_nt, 256.0);
  }

  /* Switch: '<S326>/Switch' incorporates:
   *  Constant: '<S326>/Constant'
   *  Constant: '<S329>/Constant'
   *  Constant: '<S330>/Constant'
   *  Logic: '<S326>/or'
   *  Product: '<S326>/Product1'
   *  RelationalOperator: '<S329>/Compare'
   *  RelationalOperator: '<S330>/Compare'
   *  UnitDelay: '<S326>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_nf = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_nf = 0.0;
  }

  /* End of Switch: '<S326>/Switch' */

  /* Switch: '<S335>/Init' incorporates:
   *  UnitDelay: '<S335>/FixPt Unit Delay1'
   *  UnitDelay: '<S335>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_nf;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S335>/Init' */

  /* RelationalOperator: '<S331>/Compare' incorporates:
   *  Constant: '<S331>/Constant'
   */
  rtb_Swerve_Motors_Disabled = (rtb_Switch2_nf == 0.0);

  /* RelationalOperator: '<S332>/Compare' incorporates:
   *  Constant: '<S332>/Constant'
   */
  rtb_AND1_c = (rtb_Switch2_nf > 0.0);

  /* Abs: '<S326>/Abs' incorporates:
   *  Sum: '<S326>/Subtract'
   *  UnitDelay: '<S326>/Unit Delay'
   */
  rtb_DeadZone = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                      Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S326>/Switch1' incorporates:
   *  Constant: '<S326>/Constant1'
   *  Switch: '<S326>/Switch3'
   *  Switch: '<S326>/Switch5'
   *  UnaryMinus: '<S326>/Unary Minus'
   */
  if (rtb_Swerve_Motors_Disabled) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S326>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S326>/Constant1'
     *  Constant: '<S326>/Constant4'
     *  Constant: '<S326>/Constant6'
     *  UnaryMinus: '<S326>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S326>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S326>/Constant2'
     *  Constant: '<S326>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S326>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S326>/Lookup Table Dynamic'
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
    if (rtb_AND1_c) {
      /* Switch: '<S326>/Switch3' incorporates:
       *  Constant: '<S326>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S326>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S326>/Constant1'
     *  Constant: '<S326>/Constant10'
     *  Constant: '<S326>/Constant8'
     *  UnaryMinus: '<S326>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S326>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S326>/Constant7'
     *  Constant: '<S326>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S326>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S326>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S326>/Switch1' */

  /* Product: '<S326>/Product' */
  rtb_Sin4 *= rtb_DeadZone;

  /* Sum: '<S333>/Sum1' */
  rtb_Switch1 = rtb_Switch2_nf - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S334>/Switch2' incorporates:
   *  RelationalOperator: '<S334>/LowerRelop1'
   */
  if (!(rtb_Switch1 > rtb_Sin4)) {
    /* Switch: '<S326>/Switch2' incorporates:
     *  Constant: '<S326>/Constant1'
     *  Switch: '<S326>/Switch4'
     */
    if (rtb_Swerve_Motors_Disabled) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S326>/Switch4' incorporates:
       *  Constant: '<S326>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S326>/Switch4' incorporates:
       *  Constant: '<S326>/Constant3'
       *  UnaryMinus: '<S326>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S326>/Switch2' */

    /* Product: '<S326>/Product2' */
    rtb_Sin4 *= rtb_DeadZone;

    /* Switch: '<S334>/Switch' incorporates:
     *  RelationalOperator: '<S334>/UpperRelop'
     */
    if (!(rtb_Switch1 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1;
    }

    /* End of Switch: '<S334>/Switch' */
  }

  /* End of Switch: '<S334>/Switch2' */

  /* Sum: '<S333>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S316>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S316>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S316>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S316>/Switch' */

  /* Fcn: '<S357>/r->x' incorporates:
   *  Fcn: '<S362>/r->x'
   *  Fcn: '<S367>/r->x'
   *  Fcn: '<S372>/r->x'
   */
  rtb_Switch1 = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S351>/Add' incorporates:
   *  Fcn: '<S357>/r->x'
   *  Fcn: '<S358>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1;

  /* Fcn: '<S357>/theta->y' incorporates:
   *  Fcn: '<S362>/theta->y'
   *  Fcn: '<S367>/theta->y'
   *  Fcn: '<S372>/theta->y'
   */
  rtb_DeadZone = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S351>/Add' incorporates:
   *  Fcn: '<S357>/theta->y'
   *  Fcn: '<S358>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S352>/Add' incorporates:
   *  Fcn: '<S363>/r->x'
   *  Fcn: '<S363>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S353>/Add' incorporates:
   *  Fcn: '<S368>/r->x'
   *  Fcn: '<S368>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S354>/Add' incorporates:
   *  Fcn: '<S373>/r->x'
   *  Fcn: '<S373>/theta->y'
   */
  rtb_Switch2_p2 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_DeadZone;

  /* Fcn: '<S371>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Switch2_p2, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S374>/Compare' incorporates:
   *  Constant: '<S374>/Constant'
   */
  rtb_Swerve_Motors_Disabled = (rtb_Init == 0.0);

  /* Switch: '<S370>/Switch1' */
  if (rtb_Swerve_Motors_Disabled) {
    /* Switch: '<S370>/Switch1' incorporates:
     *  Constant: '<S370>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S370>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S370>/Switch1' */

  /* Fcn: '<S356>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S359>/Compare' incorporates:
   *  Constant: '<S359>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Init == 0.0);

  /* Switch: '<S355>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S355>/Switch1' incorporates:
     *  Constant: '<S355>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S355>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S355>/Switch1' */

  /* Fcn: '<S361>/x->r' */
  rtb_Switch2_nf = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S364>/Compare' incorporates:
   *  Constant: '<S364>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Switch2_nf == 0.0);

  /* Switch: '<S360>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S360>/Switch1' incorporates:
     *  Constant: '<S360>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S360>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_nf;
  }

  /* End of Switch: '<S360>/Switch1' */

  /* Fcn: '<S366>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S369>/Compare' incorporates:
   *  Constant: '<S369>/Constant'
   */
  rtb_AND1_c = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S365>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S365>/Switch1' incorporates:
     *  Constant: '<S365>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S365>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S365>/Switch1' */

  /* Product: '<S350>/Divide' incorporates:
   *  Abs: '<S350>/Abs'
   *  Abs: '<S350>/Abs1'
   *  Abs: '<S350>/Abs2'
   *  Abs: '<S350>/Abs3'
   *  Constant: '<S350>/Constant'
   *  MinMax: '<S350>/Max'
   */
  rtb_Init = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S350>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S370>/Switch' */
  if (!rtb_Swerve_Motors_Disabled) {
    /* Switch: '<S370>/Switch' incorporates:
     *  Fcn: '<S371>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Switch2_p2);
  }

  /* End of Switch: '<S370>/Switch' */

  /* Trigonometry: '<S306>/Cos4' incorporates:
   *  Switch: '<S295>/Angle_Switch'
   *  Trigonometry: '<S305>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S306>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S304>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S306>/Sin4' incorporates:
   *  Switch: '<S295>/Angle_Switch'
   *  Trigonometry: '<S305>/Sin4'
   */
  rtb_DeadZone = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S306>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S304>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S306>/Subtract1' incorporates:
   *  Product: '<S306>/Product2'
   *  Product: '<S306>/Product3'
   *  Trigonometry: '<S306>/Cos4'
   *  Trigonometry: '<S306>/Sin4'
   */
  rtb_Switch1 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) + (rtb_DeadZone
    * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S306>/Subtract' incorporates:
   *  Product: '<S306>/Product'
   *  Product: '<S306>/Product1'
   *  Trigonometry: '<S306>/Cos4'
   *  Trigonometry: '<S306>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_DeadZone * rtb_Optimized_Module_Angle);

  /* Math: '<S306>/Hypot' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

  /* Switch: '<S306>/Switch' incorporates:
   *  Constant: '<S306>/Constant'
   *  Constant: '<S306>/Constant1'
   *  Constant: '<S307>/Constant'
   *  Product: '<S306>/Divide'
   *  Product: '<S306>/Divide1'
   *  RelationalOperator: '<S307>/Compare'
   *  Switch: '<S306>/Switch1'
   */
  if (rtb_Switch2_p2 > 1.0E-6) {
    rtb_Switch2_nf = rtb_Switch1 / rtb_Switch2_p2;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Switch2_p2;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S306>/Switch' */

  /* Switch: '<S295>/Speed_Switch' incorporates:
   *  Abs: '<S295>/Abs'
   *  Constant: '<S303>/Constant'
   *  RelationalOperator: '<S303>/Compare'
   *  Switch: '<S295>/Angle_Switch'
   *  Trigonometry: '<S305>/Atan1'
   *  Trigonometry: '<S306>/Atan1'
   *  UnaryMinus: '<S295>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_nt = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S305>/Subtract1' incorporates:
     *  Product: '<S305>/Product2'
     *  Product: '<S305>/Product3'
     *  UnaryMinus: '<S295>/Unary Minus'
     */
    rtb_Switch1 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_DeadZone * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S305>/Subtract' incorporates:
     *  Product: '<S305>/Product'
     *  Product: '<S305>/Product1'
     */
    rtb_Switch2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_DeadZone * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S305>/Hypot' */
    rtb_DeadZone = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

    /* Switch: '<S305>/Switch1' incorporates:
     *  Constant: '<S305>/Constant'
     *  Constant: '<S305>/Constant1'
     *  Constant: '<S308>/Constant'
     *  Product: '<S305>/Divide'
     *  Product: '<S305>/Divide1'
     *  RelationalOperator: '<S308>/Compare'
     *  Switch: '<S305>/Switch'
     */
    if (rtb_DeadZone > 1.0E-6) {
      rtb_Switch2 /= rtb_DeadZone;
      rtb_DeadZone = rtb_Switch1 / rtb_DeadZone;
    } else {
      rtb_Switch2 = 1.0;
      rtb_DeadZone = 0.0;
    }

    /* End of Switch: '<S305>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_DeadZone, rtb_Switch2);
  } else {
    rtb_Add_nt = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S298>/Product2' incorporates:
   *  Constant: '<S298>/Constant'
   *  Switch: '<S295>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_nt * 1154.7574092481445;

  /* Signum: '<S293>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_nt = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S293>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S296>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S297>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S228>/Product' incorporates:
   *  Abs: '<S293>/Abs'
   *  Abs: '<S296>/Abs'
   *  Constant: '<S299>/Constant'
   *  Constant: '<S309>/Constant3'
   *  Constant: '<S309>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S293>/OR'
   *  Lookup_n-D: '<S296>/1-D Lookup Table'
   *  Math: '<S309>/Math Function'
   *  RelationalOperator: '<S293>/Equal1'
   *  RelationalOperator: '<S299>/Compare'
   *  Signum: '<S293>/Sign'
   *  Signum: '<S293>/Sign1'
   *  Sum: '<S296>/Add'
   *  Sum: '<S309>/Add1'
   *  Sum: '<S309>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_nt == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S294>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2 = rtb_Switch2_nf - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S301>/Sum1' incorporates:
   *  Constant: '<S294>/Constant2'
   *  Product: '<S301>/Product'
   *  Sum: '<S301>/Sum'
   *  UnitDelay: '<S301>/Unit Delay1'
   */
  rtb_DeadZone = ((rtb_Switch2 - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S294>/Product' incorporates:
   *  Constant: '<S294>/Constant3'
   */
  rtb_Switch1 = rtb_DeadZone * Drive_Motor_Control_D;

  /* Sum: '<S300>/Diff' incorporates:
   *  UnitDelay: '<S300>/UD'
   *
   * Block description for '<S300>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S300>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Switch1 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S294>/Saturation' */
  if (rtb_Add_nt > Drive_Motor_Control_D_UL) {
    rtb_Add_nt = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Drive_Motor_Control_D_LL) {
    rtb_Add_nt = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S294>/Add' incorporates:
   *  Gain: '<S294>/Gain'
   *  Gain: '<S294>/Gain1'
   *  Saturate: '<S294>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
                    (Drive_Motor_Control_P * rtb_Switch2)) + rtb_Add_nt;

  /* Saturate: '<S294>/Saturation2' incorporates:
   *  Sum: '<S294>/Add1'
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

  /* End of Saturate: '<S294>/Saturation2' */

  /* Switch: '<S355>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S355>/Switch' incorporates:
     *  Fcn: '<S356>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S355>/Switch' */

  /* Trigonometry: '<S243>/Cos4' incorporates:
   *  Switch: '<S232>/Angle_Switch'
   *  Trigonometry: '<S242>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S243>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S241>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S243>/Sin4' incorporates:
   *  Switch: '<S232>/Angle_Switch'
   *  Trigonometry: '<S242>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S243>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S241>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S243>/Subtract1' incorporates:
   *  Product: '<S243>/Product2'
   *  Product: '<S243>/Product3'
   *  Trigonometry: '<S243>/Cos4'
   *  Trigonometry: '<S243>/Sin4'
   */
  rtb_Switch2_p2 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S243>/Subtract' incorporates:
   *  Product: '<S243>/Product'
   *  Product: '<S243>/Product1'
   *  Trigonometry: '<S243>/Cos4'
   *  Trigonometry: '<S243>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S243>/Hypot' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Switch2, rtb_Switch2_p2);

  /* Switch: '<S243>/Switch' incorporates:
   *  Constant: '<S243>/Constant'
   *  Constant: '<S243>/Constant1'
   *  Constant: '<S244>/Constant'
   *  Product: '<S243>/Divide'
   *  Product: '<S243>/Divide1'
   *  RelationalOperator: '<S244>/Compare'
   *  Switch: '<S243>/Switch1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
    rtb_Switch2_nf = rtb_Switch2_p2 / rtb_MatrixConcatenate_b_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S243>/Switch' */

  /* Product: '<S350>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S232>/Speed_Switch' incorporates:
   *  Abs: '<S232>/Abs'
   *  Constant: '<S240>/Constant'
   *  RelationalOperator: '<S240>/Compare'
   *  Switch: '<S232>/Angle_Switch'
   *  Trigonometry: '<S242>/Atan1'
   *  Trigonometry: '<S243>/Atan1'
   *  UnaryMinus: '<S232>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_nt = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S242>/Subtract1' incorporates:
     *  Product: '<S242>/Product2'
     *  Product: '<S242>/Product3'
     *  UnaryMinus: '<S232>/Unary Minus'
     */
    rtb_Switch2_p2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S242>/Subtract' incorporates:
     *  Product: '<S242>/Product'
     *  Product: '<S242>/Product1'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Cos5) - (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Sin5);

    /* Math: '<S242>/Hypot' */
    rtb_Switch2 = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Switch2_p2);

    /* Switch: '<S242>/Switch1' incorporates:
     *  Constant: '<S242>/Constant'
     *  Constant: '<S242>/Constant1'
     *  Constant: '<S245>/Constant'
     *  Product: '<S242>/Divide'
     *  Product: '<S242>/Divide1'
     *  RelationalOperator: '<S245>/Compare'
     *  Switch: '<S242>/Switch'
     */
    if (rtb_Switch2 > 1.0E-6) {
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Switch2;
      rtb_Switch2_p2 /= rtb_Switch2;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = 1.0;
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S242>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Switch2_p2,
      rtb_MatrixConcatenate_b_idx_0);
  } else {
    rtb_Add_nt = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S235>/Product2' incorporates:
   *  Constant: '<S235>/Constant'
   *  Switch: '<S232>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_nt * 1154.7574092481445;

  /* Signum: '<S230>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_nt = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S230>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S233>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S234>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S225>/Product' incorporates:
   *  Abs: '<S230>/Abs'
   *  Abs: '<S233>/Abs'
   *  Constant: '<S236>/Constant'
   *  Constant: '<S246>/Constant3'
   *  Constant: '<S246>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S230>/OR'
   *  Lookup_n-D: '<S233>/1-D Lookup Table'
   *  Math: '<S246>/Math Function'
   *  RelationalOperator: '<S230>/Equal1'
   *  RelationalOperator: '<S236>/Compare'
   *  Signum: '<S230>/Sign'
   *  Signum: '<S230>/Sign1'
   *  Sum: '<S233>/Add'
   *  Sum: '<S246>/Add1'
   *  Sum: '<S246>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_nt == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j,
                  1U);

  /* Sum: '<S231>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_nf -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S238>/Sum1' incorporates:
   *  Constant: '<S231>/Constant2'
   *  Product: '<S238>/Product'
   *  Sum: '<S238>/Sum'
   *  UnitDelay: '<S238>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_MatrixConcatenate_b_idx_0 -
                     Robot_Control_DW.UnitDelay1_DSTATE_f) *
                    Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S231>/Product' incorporates:
   *  Constant: '<S231>/Constant3'
   */
  rtb_Switch2 = rtb_Switch2_p2 * Drive_Motor_Control_D;

  /* Sum: '<S237>/Diff' incorporates:
   *  UnitDelay: '<S237>/UD'
   *
   * Block description for '<S237>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S237>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S231>/Saturation' */
  if (rtb_Add_nt > Drive_Motor_Control_D_UL) {
    rtb_Add_nt = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Drive_Motor_Control_D_LL) {
    rtb_Add_nt = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S231>/Add' incorporates:
   *  Gain: '<S231>/Gain'
   *  Gain: '<S231>/Gain1'
   *  Saturate: '<S231>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
    (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_nt;

  /* Saturate: '<S231>/Saturation2' incorporates:
   *  Sum: '<S231>/Add1'
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

  /* End of Saturate: '<S231>/Saturation2' */

  /* Sum: '<S247>/Add1' incorporates:
   *  Constant: '<S247>/Constant3'
   *  Constant: '<S247>/Constant4'
   *  Math: '<S247>/Math Function'
   *  Sum: '<S247>/Add2'
   */
  rtb_Switch2_nf = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S249>/Sum1' incorporates:
   *  Constant: '<S234>/Constant2'
   *  Product: '<S249>/Product'
   *  Sum: '<S249>/Sum'
   *  UnitDelay: '<S249>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((rtb_Switch2_nf -
    Robot_Control_DW.UnitDelay1_DSTATE_b) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S234>/Product' incorporates:
   *  Constant: '<S234>/Constant3'
   */
  rtb_Switch2_ow = rtb_MatrixConcatenate_b_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S248>/Diff' incorporates:
   *  UnitDelay: '<S248>/UD'
   *
   * Block description for '<S248>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S248>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Switch2_ow - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S234>/Saturation' */
  if (rtb_Add_nt > Steering_Motor_Control_D_UL) {
    rtb_Add_nt = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Motor_Control_D_LL) {
    rtb_Add_nt = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S234>/Add' incorporates:
   *  Gain: '<S234>/Gain1'
   *  Saturate: '<S234>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P * rtb_Switch2_nf) +
    rtb_Add_nt;

  /* Sum: '<S234>/Subtract' incorporates:
   *  Constant: '<S234>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S234>/Sum2' incorporates:
   *  Gain: '<S234>/Gain2'
   *  UnitDelay: '<S234>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Switch2_nf) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S250>/Switch2' incorporates:
   *  Constant: '<S234>/Constant'
   *  RelationalOperator: '<S250>/LowerRelop1'
   *  Sum: '<S234>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S250>/Switch' incorporates:
     *  Constant: '<S234>/Constant1'
     *  RelationalOperator: '<S250>/UpperRelop'
     *  Sum: '<S234>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S250>/Switch' */
  }

  /* End of Switch: '<S250>/Switch2' */

  /* Saturate: '<S234>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S234>/Saturation1' */

  /* Sum: '<S234>/Add1' */
  rtb_Add_nt = rtb_MatrixConcatenate_idx_0 + rtb_Sum2_e;

  /* Saturate: '<S234>/Saturation2' */
  if (rtb_Add_nt > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_nt < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_nt;
  }

  /* End of Saturate: '<S234>/Saturation2' */

  /* Switch: '<S360>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S360>/Switch' incorporates:
     *  Fcn: '<S361>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S360>/Switch' */

  /* Trigonometry: '<S264>/Cos4' incorporates:
   *  Switch: '<S253>/Angle_Switch'
   *  Trigonometry: '<S263>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S264>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S262>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S264>/Sin4' incorporates:
   *  Switch: '<S253>/Angle_Switch'
   *  Trigonometry: '<S263>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S264>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S262>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S264>/Subtract1' incorporates:
   *  Product: '<S264>/Product2'
   *  Product: '<S264>/Product3'
   *  Trigonometry: '<S264>/Cos4'
   *  Trigonometry: '<S264>/Sin4'
   */
  rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S264>/Subtract' incorporates:
   *  Product: '<S264>/Product'
   *  Product: '<S264>/Product1'
   *  Trigonometry: '<S264>/Cos4'
   *  Trigonometry: '<S264>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S264>/Hypot' */
  rtb_Hypot_bl = rt_hypotd_snf(rtb_Subtract1_la, rtb_MatrixConcatenate_idx_0);

  /* Switch: '<S264>/Switch' incorporates:
   *  Constant: '<S264>/Constant'
   *  Constant: '<S264>/Constant1'
   *  Constant: '<S265>/Constant'
   *  Product: '<S264>/Divide'
   *  Product: '<S264>/Divide1'
   *  RelationalOperator: '<S265>/Compare'
   *  Switch: '<S264>/Switch1'
   */
  if (rtb_Hypot_bl > 1.0E-6) {
    rtb_Switch2_nf = rtb_MatrixConcatenate_idx_0 / rtb_Hypot_bl;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_bl;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S264>/Switch' */

  /* Product: '<S350>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S253>/Speed_Switch' incorporates:
   *  Abs: '<S253>/Abs'
   *  Constant: '<S261>/Constant'
   *  RelationalOperator: '<S261>/Compare'
   *  Switch: '<S253>/Angle_Switch'
   *  Trigonometry: '<S263>/Atan1'
   *  Trigonometry: '<S264>/Atan1'
   *  UnaryMinus: '<S253>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_nt = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S263>/Subtract1' incorporates:
     *  Product: '<S263>/Product2'
     *  Product: '<S263>/Product3'
     *  UnaryMinus: '<S253>/Unary Minus'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_m) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S263>/Subtract' incorporates:
     *  Product: '<S263>/Product'
     *  Product: '<S263>/Product1'
     */
    rtb_Hypot_bl = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S263>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_bl, rtb_MatrixConcatenate_idx_0);

    /* Switch: '<S263>/Switch1' incorporates:
     *  Constant: '<S263>/Constant'
     *  Constant: '<S263>/Constant1'
     *  Constant: '<S266>/Constant'
     *  Product: '<S263>/Divide'
     *  Product: '<S263>/Divide1'
     *  RelationalOperator: '<S266>/Compare'
     *  Switch: '<S263>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_bl /= rtb_Subtract1_la;
      rtb_MatrixConcatenate_idx_0 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_bl = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S263>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0, rtb_Hypot_bl);
  } else {
    rtb_Add_nt = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S256>/Product2' incorporates:
   *  Constant: '<S256>/Constant'
   *  Switch: '<S253>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_nt * 1154.7574092481445;

  /* Signum: '<S251>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_nt = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S251>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S254>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S255>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S226>/Product' incorporates:
   *  Abs: '<S251>/Abs'
   *  Abs: '<S254>/Abs'
   *  Constant: '<S257>/Constant'
   *  Constant: '<S267>/Constant3'
   *  Constant: '<S267>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S251>/OR'
   *  Lookup_n-D: '<S254>/1-D Lookup Table'
   *  Math: '<S267>/Math Function'
   *  RelationalOperator: '<S251>/Equal1'
   *  RelationalOperator: '<S257>/Compare'
   *  Signum: '<S251>/Sign'
   *  Signum: '<S251>/Sign1'
   *  Sum: '<S254>/Add'
   *  Sum: '<S267>/Add1'
   *  Sum: '<S267>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_nt == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_gs,
                  1U);

  /* Sum: '<S252>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_bl = rtb_Switch2_nf - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S259>/Sum1' incorporates:
   *  Constant: '<S252>/Constant2'
   *  Product: '<S259>/Product'
   *  Sum: '<S259>/Sum'
   *  UnitDelay: '<S259>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Hypot_bl -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S252>/Product' incorporates:
   *  Constant: '<S252>/Constant3'
   */
  rtb_Subtract1_la = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S258>/Diff' incorporates:
   *  UnitDelay: '<S258>/UD'
   *
   * Block description for '<S258>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S258>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S252>/Saturation' */
  if (rtb_Add_nt > Drive_Motor_Control_D_UL) {
    rtb_Add_nt = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Drive_Motor_Control_D_LL) {
    rtb_Add_nt = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S252>/Add' incorporates:
   *  Gain: '<S252>/Gain'
   *  Gain: '<S252>/Gain1'
   *  Saturate: '<S252>/Saturation'
   */
  rtb_Hypot_bl = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
                  (Drive_Motor_Control_P * rtb_Hypot_bl)) + rtb_Add_nt;

  /* Saturate: '<S252>/Saturation2' incorporates:
   *  Sum: '<S252>/Add1'
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

  /* End of Saturate: '<S252>/Saturation2' */

  /* Sum: '<S268>/Add1' incorporates:
   *  Constant: '<S268>/Constant3'
   *  Constant: '<S268>/Constant4'
   *  Math: '<S268>/Math Function'
   *  Sum: '<S268>/Add2'
   */
  rtb_Switch2_nf = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S270>/Sum1' incorporates:
   *  Constant: '<S255>/Constant2'
   *  Product: '<S270>/Product'
   *  Sum: '<S270>/Sum'
   *  UnitDelay: '<S270>/Unit Delay1'
   */
  rtb_Hypot_bl = ((rtb_Switch2_nf - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S255>/Product' incorporates:
   *  Constant: '<S255>/Constant3'
   */
  rtb_Switch2_cw = rtb_Hypot_bl * Steering_Motor_Control_D;

  /* Sum: '<S269>/Diff' incorporates:
   *  UnitDelay: '<S269>/UD'
   *
   * Block description for '<S269>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S269>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Switch2_cw - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S255>/Saturation' */
  if (rtb_Add_nt > Steering_Motor_Control_D_UL) {
    rtb_Add_nt = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Motor_Control_D_LL) {
    rtb_Add_nt = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S255>/Add' incorporates:
   *  Gain: '<S255>/Gain1'
   *  Saturate: '<S255>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_nf) + rtb_Add_nt;

  /* Sum: '<S255>/Subtract' incorporates:
   *  Constant: '<S255>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S255>/Sum2' incorporates:
   *  Gain: '<S255>/Gain2'
   *  UnitDelay: '<S255>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_Switch2_nf) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S271>/Switch2' incorporates:
   *  Constant: '<S255>/Constant'
   *  RelationalOperator: '<S271>/LowerRelop1'
   *  Sum: '<S255>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S271>/Switch' incorporates:
     *  Constant: '<S255>/Constant1'
     *  RelationalOperator: '<S271>/UpperRelop'
     *  Sum: '<S255>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S271>/Switch' */
  }

  /* End of Switch: '<S271>/Switch2' */

  /* Saturate: '<S255>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S255>/Saturation1' */

  /* Sum: '<S255>/Add1' */
  rtb_Add_nt = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S255>/Saturation2' */
  if (rtb_Add_nt > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_nt < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_nt;
  }

  /* End of Saturate: '<S255>/Saturation2' */

  /* Switch: '<S365>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S365>/Switch' incorporates:
     *  Fcn: '<S366>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S365>/Switch' */

  /* Trigonometry: '<S285>/Cos4' incorporates:
   *  Switch: '<S274>/Angle_Switch'
   *  Trigonometry: '<S284>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S285>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S283>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S285>/Sin4' incorporates:
   *  Switch: '<S274>/Angle_Switch'
   *  Trigonometry: '<S284>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S285>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S283>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S285>/Subtract1' incorporates:
   *  Product: '<S285>/Product2'
   *  Product: '<S285>/Product3'
   *  Trigonometry: '<S285>/Cos4'
   *  Trigonometry: '<S285>/Sin4'
   */
  rtb_Switch2_nf = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S285>/Subtract' incorporates:
   *  Product: '<S285>/Product'
   *  Product: '<S285>/Product1'
   *  Trigonometry: '<S285>/Cos4'
   *  Trigonometry: '<S285>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S285>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_nf);

  /* Switch: '<S285>/Switch' incorporates:
   *  Constant: '<S285>/Constant'
   *  Constant: '<S285>/Constant1'
   *  Constant: '<S286>/Constant'
   *  Product: '<S285>/Divide'
   *  Product: '<S285>/Divide1'
   *  RelationalOperator: '<S286>/Compare'
   *  Switch: '<S285>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Switch2_nf /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S285>/Switch' */

  /* Product: '<S350>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S274>/Speed_Switch' incorporates:
   *  Abs: '<S274>/Abs'
   *  Constant: '<S282>/Constant'
   *  RelationalOperator: '<S282>/Compare'
   *  Switch: '<S274>/Angle_Switch'
   *  Trigonometry: '<S284>/Atan1'
   *  Trigonometry: '<S285>/Atan1'
   *  UnaryMinus: '<S274>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_nt = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S284>/Subtract1' incorporates:
     *  Product: '<S284>/Product2'
     *  Product: '<S284>/Product3'
     *  UnaryMinus: '<S274>/Unary Minus'
     */
    rtb_Switch2_nf = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S284>/Subtract' incorporates:
     *  Product: '<S284>/Product'
     *  Product: '<S284>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S284>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_nf);

    /* Switch: '<S284>/Switch1' incorporates:
     *  Constant: '<S284>/Constant'
     *  Constant: '<S284>/Constant1'
     *  Constant: '<S287>/Constant'
     *  Product: '<S284>/Divide'
     *  Product: '<S284>/Divide1'
     *  RelationalOperator: '<S287>/Compare'
     *  Switch: '<S284>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_Switch2_nf /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Switch2_nf = 0.0;
    }

    /* End of Switch: '<S284>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Switch2_nf,
      rtb_uDLookupTable);
  } else {
    rtb_Add_nt = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S277>/Product2' incorporates:
   *  Constant: '<S277>/Constant'
   *  Switch: '<S274>/Speed_Switch'
   */
  rtb_Init = rtb_Add_nt * 1154.7574092481445;

  /* Signum: '<S272>/Sign' */
  if (rtIsNaN(rtb_Init)) {
    rtb_Add_nt = (rtNaN);
  } else if (rtb_Init < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (rtb_Init > 0.0);
  }

  /* Signum: '<S272>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S275>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S276>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S227>/Product' incorporates:
   *  Abs: '<S272>/Abs'
   *  Abs: '<S275>/Abs'
   *  Constant: '<S278>/Constant'
   *  Constant: '<S288>/Constant3'
   *  Constant: '<S288>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S272>/OR'
   *  Lookup_n-D: '<S275>/1-D Lookup Table'
   *  Math: '<S288>/Math Function'
   *  RelationalOperator: '<S272>/Equal1'
   *  RelationalOperator: '<S278>/Compare'
   *  Signum: '<S272>/Sign'
   *  Signum: '<S272>/Sign1'
   *  Sum: '<S275>/Add'
   *  Sum: '<S288>/Add1'
   *  Sum: '<S288>/Add2'
   */
  rtb_Init = (((real_T)((rtb_Add_nt == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init) * look1_binlcpw(fabs
    (rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                 3.1415926535897931) - 1.5707963267948966),
    rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S273>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_nf = rtb_Init - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S280>/Sum1' incorporates:
   *  Constant: '<S273>/Constant2'
   *  Product: '<S280>/Product'
   *  Sum: '<S280>/Sum'
   *  UnitDelay: '<S280>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_Switch2_nf - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S273>/Product' incorporates:
   *  Constant: '<S273>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S279>/Diff' incorporates:
   *  UnitDelay: '<S279>/UD'
   *
   * Block description for '<S279>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S279>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S273>/Saturation' */
  if (rtb_Add_nt > Drive_Motor_Control_D_UL) {
    rtb_Add_nt = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Drive_Motor_Control_D_LL) {
    rtb_Add_nt = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S273>/Add' incorporates:
   *  Gain: '<S273>/Gain'
   *  Gain: '<S273>/Gain1'
   *  Saturate: '<S273>/Saturation'
   */
  rtb_Init = ((Drive_Motor_Control_FF * rtb_Init) + (Drive_Motor_Control_P *
    rtb_Switch2_nf)) + rtb_Add_nt;

  /* Saturate: '<S273>/Saturation2' incorporates:
   *  Sum: '<S273>/Add1'
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

  /* End of Saturate: '<S273>/Saturation2' */

  /* Sum: '<S289>/Add1' incorporates:
   *  Constant: '<S289>/Constant3'
   *  Constant: '<S289>/Constant4'
   *  Math: '<S289>/Math Function'
   *  Sum: '<S289>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S291>/Sum1' incorporates:
   *  Constant: '<S276>/Constant2'
   *  Product: '<S291>/Product'
   *  Sum: '<S291>/Sum'
   *  UnitDelay: '<S291>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Init -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S276>/Product' incorporates:
   *  Constant: '<S276>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S290>/Diff' incorporates:
   *  UnitDelay: '<S290>/UD'
   *
   * Block description for '<S290>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S290>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S276>/Saturation' */
  if (rtb_Add_nt > Steering_Motor_Control_D_UL) {
    rtb_Add_nt = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Motor_Control_D_LL) {
    rtb_Add_nt = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S276>/Add' incorporates:
   *  Gain: '<S276>/Gain1'
   *  Saturate: '<S276>/Saturation'
   */
  rtb_Add_ec = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_nt;

  /* Sum: '<S276>/Subtract' incorporates:
   *  Constant: '<S276>/Constant'
   */
  rtb_Switch2_nf = 1.0 - rtb_Add_ec;

  /* Sum: '<S276>/Sum2' incorporates:
   *  Gain: '<S276>/Gain2'
   *  UnitDelay: '<S276>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S292>/Switch2' incorporates:
   *  Constant: '<S276>/Constant'
   *  RelationalOperator: '<S292>/LowerRelop1'
   *  Sum: '<S276>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_ec))) {
    /* Sum: '<S276>/Subtract1' incorporates:
     *  Constant: '<S276>/Constant1'
     */
    rtb_Switch2_nf = -1.0 - rtb_Add_ec;

    /* Switch: '<S292>/Switch' incorporates:
     *  Constant: '<S276>/Constant1'
     *  RelationalOperator: '<S292>/UpperRelop'
     *  Sum: '<S276>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_ec))) {
      rtb_Switch2_nf = rtb_Init;
    }

    /* End of Switch: '<S292>/Switch' */
  }

  /* End of Switch: '<S292>/Switch2' */

  /* Saturate: '<S276>/Saturation1' */
  if (rtb_Switch2_nf > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_nf < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Switch2_nf;
  }

  /* End of Saturate: '<S276>/Saturation1' */

  /* Sum: '<S276>/Add1' */
  rtb_Add_nt = rtb_Add_ec + rtb_Integral_ga;

  /* Saturate: '<S276>/Saturation2' */
  if (rtb_Add_nt > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_nt < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_nt;
  }

  /* End of Saturate: '<S276>/Saturation2' */

  /* Sum: '<S310>/Add1' incorporates:
   *  Constant: '<S310>/Constant3'
   *  Constant: '<S310>/Constant4'
   *  Math: '<S310>/Math Function'
   *  Sum: '<S310>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Integral_d + 3.1415926535897931, 6.2831853071795862)
    - 3.1415926535897931;

  /* Sum: '<S312>/Sum1' incorporates:
   *  Constant: '<S297>/Constant2'
   *  Product: '<S312>/Product'
   *  Sum: '<S312>/Sum'
   *  UnitDelay: '<S312>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_i)
    * Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S297>/Product' incorporates:
   *  Constant: '<S297>/Constant3'
   */
  rtb_Add_ec = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S311>/Diff' incorporates:
   *  UnitDelay: '<S311>/UD'
   *
   * Block description for '<S311>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S311>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Add_ec - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S297>/Saturation' */
  if (rtb_Add_nt > Steering_Motor_Control_D_UL) {
    rtb_Add_nt = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Motor_Control_D_LL) {
    rtb_Add_nt = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S297>/Add' incorporates:
   *  Gain: '<S297>/Gain1'
   *  Saturate: '<S297>/Saturation'
   */
  rtb_Add_os = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_nt;

  /* Sum: '<S297>/Subtract' incorporates:
   *  Constant: '<S297>/Constant'
   */
  rtb_Switch2_nf = 1.0 - rtb_Add_os;

  /* Sum: '<S297>/Sum2' incorporates:
   *  Gain: '<S297>/Gain2'
   *  UnitDelay: '<S297>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S313>/Switch2' incorporates:
   *  Constant: '<S297>/Constant'
   *  RelationalOperator: '<S313>/LowerRelop1'
   *  Sum: '<S297>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_os))) {
    /* Sum: '<S297>/Subtract1' incorporates:
     *  Constant: '<S297>/Constant1'
     */
    rtb_Switch2_nf = -1.0 - rtb_Add_os;

    /* Switch: '<S313>/Switch' incorporates:
     *  Constant: '<S297>/Constant1'
     *  RelationalOperator: '<S313>/UpperRelop'
     *  Sum: '<S297>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_os))) {
      rtb_Switch2_nf = rtb_Init;
    }

    /* End of Switch: '<S313>/Switch' */
  }

  /* End of Switch: '<S313>/Switch2' */

  /* Saturate: '<S297>/Saturation1' */
  if (rtb_Switch2_nf > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_nf < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Switch2_nf;
  }

  /* End of Saturate: '<S297>/Saturation1' */

  /* Sum: '<S297>/Add1' */
  rtb_Add_nt = rtb_Add_os + rtb_Integral_bj;

  /* Saturate: '<S297>/Saturation2' */
  if (rtb_Add_nt > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_nt < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_nt;
  }

  /* End of Saturate: '<S297>/Saturation2' */

  /* Sum: '<S160>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S114>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S162>/Sum1' incorporates:
   *  Constant: '<S160>/Constant2'
   *  Product: '<S162>/Product'
   *  Sum: '<S160>/Sum'
   *  Sum: '<S162>/Sum'
   *  UnitDelay: '<S162>/Unit Delay1'
   */
  rtb_Add_os = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S160>/Product' incorporates:
   *  Constant: '<S160>/Constant3'
   */
  rtb_Product_lo = rtb_Add_os * 0.0;

  /* Sum: '<S161>/Diff' incorporates:
   *  UnitDelay: '<S161>/UD'
   *
   * Block description for '<S161>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S161>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S160>/Saturation' */
  if (rtb_Add_nt > 0.1) {
    rtb_Add_nt = 0.1;
  } else if (rtb_Add_nt < -0.1) {
    rtb_Add_nt = -0.1;
  }

  /* Sum: '<S160>/Add' incorporates:
   *  Gain: '<S160>/Gain'
   *  Gain: '<S160>/Gain1'
   *  Saturate: '<S160>/Saturation'
   *  Sum: '<S160>/Sum'
   */
  rtb_Init = ((Rebuilt_Transfer_Motor_Gain_FF *
               Robot_Control_B.RB_Desired_Transfer_Speed) +
              (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_nt;

  /* Logic: '<S114>/Logical Operator1' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   */
  rtb_Is_Absolute_Translation_g = !(Robot_Control_B.RB_Desired_Transfer_Speed ==
    0.0);

  /* Switch: '<S114>/Switch1' incorporates:
   *  Abs: '<S114>/Abs'
   *  Constant: '<S114>/Constant1'
   *  Constant: '<S114>/Constant2'
   *  Logic: '<S114>/Logical Operator'
   *  Logic: '<S114>/Logical Operator1'
   *  RelationalOperator: '<S114>/LessThan'
   *  UnitDelay: '<S114>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Is_Absolute_Translation_g) {
    rtb_Swerve_Motors_Disabled = true;
  } else {
    rtb_Swerve_Motors_Disabled = (rtb_Is_Absolute_Translation_g &&
      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S114>/Switch1' */

  /* Switch: '<S160>/Switch' incorporates:
   *  Constant: '<S160>/Constant4'
   */
  if (rtb_Swerve_Motors_Disabled) {
    /* Sum: '<S160>/Sum2' incorporates:
     *  Gain: '<S160>/Gain2'
     *  Sum: '<S160>/Sum'
     *  UnitDelay: '<S160>/Unit Delay'
     */
    rtb_Switch2_nf = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S160>/Subtract' incorporates:
     *  Constant: '<S160>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Init;

    /* Switch: '<S163>/Switch2' incorporates:
     *  Constant: '<S160>/Constant'
     *  RelationalOperator: '<S163>/LowerRelop1'
     *  Sum: '<S160>/Subtract'
     */
    if (!(rtb_Switch2_nf > (1.0 - rtb_Init))) {
      /* Sum: '<S160>/Subtract1' incorporates:
       *  Constant: '<S160>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Init;

      /* Switch: '<S163>/Switch' incorporates:
       *  Constant: '<S160>/Constant1'
       *  RelationalOperator: '<S163>/UpperRelop'
       *  Sum: '<S160>/Subtract1'
       */
      if (!(rtb_Switch2_nf < (-1.0 - rtb_Init))) {
        rtb_Integral_d = rtb_Switch2_nf;
      }

      /* End of Switch: '<S163>/Switch' */
    }

    /* End of Switch: '<S163>/Switch2' */

    /* Saturate: '<S160>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S160>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S160>/Switch' */

  /* Switch: '<S114>/Switch2' incorporates:
   *  Logic: '<S114>/Logical Operator1'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* Sum: '<S160>/Add1' */
    rtb_Add_nt = rtb_Init + rtb_Integral_d;

    /* Saturate: '<S160>/Saturation2' */
    if (rtb_Add_nt > 1.0) {
      /* Switch: '<S114>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_nt < -1.0) {
      /* Switch: '<S114>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S114>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_nt;
    }

    /* End of Saturate: '<S160>/Saturation2' */
  } else {
    /* Switch: '<S114>/Switch2' incorporates:
     *  Constant: '<S114>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S114>/Switch2' */

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

  /* Switch: '<S106>/Init' incorporates:
   *  UnitDelay: '<S106>/FixPt Unit Delay1'
   *  UnitDelay: '<S106>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Switch2_nf = rtb_Init;
  } else {
    rtb_Switch2_nf = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S106>/Init' */

  /* Sum: '<S104>/Sum1' */
  rtb_Init -= rtb_Switch2_nf;

  /* Switch: '<S105>/Switch2' incorporates:
   *  Constant: '<S103>/Constant1'
   *  Constant: '<S103>/Constant3'
   *  RelationalOperator: '<S105>/LowerRelop1'
   *  RelationalOperator: '<S105>/UpperRelop'
   *  Switch: '<S105>/Switch'
   */
  if (rtb_Init > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Init < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S103>/Constant1'
     */
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S105>/Switch2' */

  /* Sum: '<S104>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Init + rtb_Switch2_nf;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  if (rtb_LogicalOperator1_n) {
    rtb_Init = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S35>/Logical Operator1' incorporates:
   *  Constant: '<S44>/Constant'
   *  RelationalOperator: '<S44>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Init == 0.0);

  /* Sum: '<S45>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S35>/Subtract'
   */
  rtb_Error_n = rtb_Init - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S47>/Sum1' incorporates:
   *  Constant: '<S45>/Constant2'
   *  Product: '<S47>/Product'
   *  Sum: '<S45>/Sum'
   *  Sum: '<S47>/Sum'
   *  UnitDelay: '<S47>/Unit Delay1'
   */
  rtb_Sum1_fh = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S45>/Product' incorporates:
   *  Constant: '<S45>/Constant3'
   */
  rtb_Product_hm = rtb_Sum1_fh * 0.0;

  /* Sum: '<S46>/Diff' incorporates:
   *  UnitDelay: '<S46>/UD'
   *
   * Block description for '<S46>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S46>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_hm - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S45>/Saturation' */
  if (rtb_Add_nt > 0.1) {
    rtb_Add_nt = 0.1;
  } else if (rtb_Add_nt < -0.1) {
    rtb_Add_nt = -0.1;
  }

  /* Sum: '<S45>/Add' incorporates:
   *  Gain: '<S45>/Gain'
   *  Gain: '<S45>/Gain1'
   *  Saturate: '<S45>/Saturation'
   *  Sum: '<S45>/Sum'
   */
  rtb_Switch2_nf = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Init) +
                    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_nt;

  /* Switch: '<S35>/Switch1' incorporates:
   *  Abs: '<S35>/Abs'
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S35>/Constant2'
   *  Logic: '<S35>/Logical Operator'
   *  Logic: '<S35>/Logical Operator1'
   *  RelationalOperator: '<S35>/LessThan'
   *  UnitDelay: '<S35>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_AND1_c = true;
  } else {
    rtb_AND1_c = (rtb_LogicalOperator1_n &&
                  (Robot_Control_DW.UnitDelay_DSTATE_nh));
  }

  /* End of Switch: '<S35>/Switch1' */

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Constant4'
   */
  if (rtb_AND1_c) {
    /* Sum: '<S45>/Sum2' incorporates:
     *  Gain: '<S45>/Gain2'
     *  Sum: '<S45>/Sum'
     *  UnitDelay: '<S45>/Unit Delay'
     */
    rtb_Init = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S45>/Subtract' incorporates:
     *  Constant: '<S45>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Switch2_nf;

    /* Switch: '<S48>/Switch2' incorporates:
     *  Constant: '<S45>/Constant'
     *  RelationalOperator: '<S48>/LowerRelop1'
     *  Sum: '<S45>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Switch2_nf))) {
      /* Sum: '<S45>/Subtract1' incorporates:
       *  Constant: '<S45>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Switch2_nf;

      /* Switch: '<S48>/Switch' incorporates:
       *  Constant: '<S45>/Constant1'
       *  RelationalOperator: '<S48>/UpperRelop'
       *  Sum: '<S45>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Switch2_nf))) {
        rtb_Error_n = rtb_Init;
      }

      /* End of Switch: '<S48>/Switch' */
    }

    /* End of Switch: '<S48>/Switch2' */

    /* Saturate: '<S45>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Error_n = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Error_n = -0.1;
    }

    /* End of Saturate: '<S45>/Saturation1' */
  } else {
    rtb_Error_n = 0.0;
  }

  /* End of Switch: '<S45>/Switch' */

  /* Switch: '<S35>/Switch2' incorporates:
   *  Logic: '<S35>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S45>/Add1' */
    rtb_Add_nt = rtb_Switch2_nf + rtb_Error_n;

    /* Saturate: '<S45>/Saturation2' */
    if (rtb_Add_nt > 1.0) {
      /* Switch: '<S35>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_nt < -1.0) {
      /* Switch: '<S35>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S35>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_nt;
    }

    /* End of Saturate: '<S45>/Saturation2' */
  } else {
    /* Switch: '<S35>/Switch2' incorporates:
     *  Constant: '<S35>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S35>/Switch2' */

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

  /* Chart: '<S6>/Chart' incorporates:
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  RelationalOperator: '<S32>/FixPt Relational Operator'
   *  UnitDelay: '<S32>/Delay Input1'
   *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Robot_Control_DW.is_active_c4_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c4_Robot_Control = 1U;
    Robot_Control_DW.is_c4_Robot_Control = Robot_Contro_IN_Wait_for_Button;
    Robot_Control_B.RB_Des_Intake_Arm_Angle =
      Robot_Control_U.Measured_Intake_Arm_Angle;
  } else {
    switch (Robot_Control_DW.is_c4_Robot_Control) {
     case Robot_Con_IN_Move_Intake_Arm_In:
      if (rtb_Intake_Arm_Move_Out || (rtb_Intake_Arm_Cycle &&
           (Robot_Control_U.Measured_Intake_Arm_Angle <
            Rebuilt_Intake_Cycle_Angle_In))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      if ((rtb_Intake_Arm_Move_In || (rtb_Intake_Arm_Cycle &&
            (Robot_Control_U.Measured_Intake_Arm_Angle >
             Rebuilt_Intake_Cycle_Angle_Out))) || (((int32_T)
            rtb_Intake_Arm_Cycle) < ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_c))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
      }
      break;

     default:
      /* case IN_Wait_for_Button: */
      if (rtb_Intake_Arm_Move_In || rtb_Intake_Arm_Cycle) {
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

  /* Switch: '<S43>/Init' incorporates:
   *  UnitDelay: '<S43>/FixPt Unit Delay1'
   *  UnitDelay: '<S43>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S43>/Init' */

  /* Sum: '<S41>/Sum1' */
  rtb_Switch2_nf = Robot_Control_B.RB_Des_Intake_Arm_Angle - rtb_Init;

  /* Switch: '<S42>/Switch2' incorporates:
   *  Constant: '<S34>/Constant1'
   *  Constant: '<S34>/Constant3'
   *  RelationalOperator: '<S42>/LowerRelop1'
   *  RelationalOperator: '<S42>/UpperRelop'
   *  Switch: '<S42>/Switch'
   */
  if (rtb_Switch2_nf > Rebuilt_Intake_RL_Inc) {
    rtb_Switch2_nf = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Switch2_nf < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S34>/Constant1'
     */
    rtb_Switch2_nf = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S42>/Switch2' */

  /* Sum: '<S41>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Switch2_nf + rtb_Init;

  /* Logic: '<S33>/Logical Operator1' incorporates:
   *  Constant: '<S36>/Constant'
   *  RelationalOperator: '<S36>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Des_Intake_Arm_Angle_RL == 0.0);

  /* Sum: '<S37>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Sum: '<S33>/Subtract'
   */
  rtb_Error_e = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_U.Measured_Intake_Arm_Angle;

  /* Sum: '<S39>/Sum1' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Product: '<S39>/Product'
   *  Sum: '<S37>/Sum'
   *  Sum: '<S39>/Sum'
   *  UnitDelay: '<S39>/Unit Delay1'
   */
  rtb_Switch2_nf = ((rtb_Error_e - Robot_Control_DW.UnitDelay1_DSTATE_l) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_l;

  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant3'
   */
  rtb_Product_di = rtb_Switch2_nf * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S38>/Diff' incorporates:
   *  UnitDelay: '<S38>/UD'
   *
   * Block description for '<S38>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S38>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_di - Robot_Control_DW.UD_DSTATE_d;

  /* Saturate: '<S37>/Saturation' */
  if (rtb_Add_nt > 0.1) {
    rtb_Add_nt = 0.1;
  } else if (rtb_Add_nt < -0.1) {
    rtb_Add_nt = -0.1;
  }

  /* Sum: '<S37>/Add' incorporates:
   *  Gain: '<S37>/Gain'
   *  Gain: '<S37>/Gain1'
   *  Saturate: '<S37>/Saturation'
   *  Sum: '<S37>/Sum'
   */
  rtb_Init = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
              (Rebuilt_Intake_Arm_Gain_P * rtb_Error_e)) + rtb_Add_nt;

  /* Switch: '<S33>/Switch1' incorporates:
   *  Abs: '<S33>/Abs'
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S33>/Constant2'
   *  Logic: '<S33>/Logical Operator'
   *  Logic: '<S33>/Logical Operator1'
   *  RelationalOperator: '<S33>/LessThan'
   *  UnitDelay: '<S33>/Unit Delay'
   */
  if ((fabs(rtb_Error_e) < Rebuilt_Intake_Arm_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_dvn));
  }

  /* End of Switch: '<S33>/Switch1' */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Constant4'
   */
  if (rtb_Intake_Arm_Move_In) {
    /* Sum: '<S37>/Sum2' incorporates:
     *  Gain: '<S37>/Gain2'
     *  Sum: '<S37>/Sum'
     *  UnitDelay: '<S37>/Unit Delay'
     */
    rtb_Error_e = (Rebuilt_Intake_Arm_Gain_I * rtb_Error_e) +
      Robot_Control_DW.UnitDelay_DSTATE_ej;

    /* Sum: '<S37>/Subtract' incorporates:
     *  Constant: '<S37>/Constant'
     */
    rtb_Switch2_p0 = 1.0 - rtb_Init;

    /* Switch: '<S40>/Switch2' incorporates:
     *  Constant: '<S37>/Constant'
     *  RelationalOperator: '<S40>/LowerRelop1'
     *  Sum: '<S37>/Subtract'
     */
    if (!(rtb_Error_e > (1.0 - rtb_Init))) {
      /* Sum: '<S37>/Subtract1' incorporates:
       *  Constant: '<S37>/Constant1'
       */
      rtb_Switch2_p0 = -1.0 - rtb_Init;

      /* Switch: '<S40>/Switch' incorporates:
       *  Constant: '<S37>/Constant1'
       *  RelationalOperator: '<S40>/UpperRelop'
       *  Sum: '<S37>/Subtract1'
       */
      if (!(rtb_Error_e < (-1.0 - rtb_Init))) {
        rtb_Switch2_p0 = rtb_Error_e;
      }

      /* End of Switch: '<S40>/Switch' */
    }

    /* End of Switch: '<S40>/Switch2' */

    /* Saturate: '<S37>/Saturation1' */
    if (rtb_Switch2_p0 > 0.1) {
      rtb_Error_e = 0.1;
    } else if (rtb_Switch2_p0 < -0.1) {
      rtb_Error_e = -0.1;
    } else {
      rtb_Error_e = rtb_Switch2_p0;
    }

    /* End of Saturate: '<S37>/Saturation1' */
  } else {
    rtb_Error_e = 0.0;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Switch: '<S33>/Switch2' incorporates:
   *  Logic: '<S33>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S37>/Add1' */
    rtb_Add_nt = rtb_Init + rtb_Error_e;

    /* Saturate: '<S37>/Saturation2' */
    if (rtb_Add_nt > 1.0) {
      /* Switch: '<S33>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_nt < -1.0) {
      /* Switch: '<S33>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S33>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_nt;
    }

    /* End of Saturate: '<S37>/Saturation2' */
  } else {
    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S33>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S33>/Switch2' */

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

  /* Logic: '<S112>/Logical Operator1' incorporates:
   *  Constant: '<S154>/Constant'
   *  RelationalOperator: '<S154>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S155>/Sum' incorporates:
   *  Sum: '<S112>/Subtract'
   */
  rtb_Init = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S157>/Sum1' incorporates:
   *  Constant: '<S155>/Constant2'
   *  Product: '<S157>/Product'
   *  Sum: '<S155>/Sum'
   *  Sum: '<S157>/Sum'
   *  UnitDelay: '<S157>/Unit Delay1'
   */
  rtb_Switch2_p0 = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S155>/Product' incorporates:
   *  Constant: '<S155>/Constant3'
   */
  rtb_Product_i = rtb_Switch2_p0 * 0.0;

  /* Sum: '<S156>/Diff' incorporates:
   *  UnitDelay: '<S156>/UD'
   *
   * Block description for '<S156>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S156>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_i - Robot_Control_DW.UD_DSTATE_kz;

  /* Saturate: '<S155>/Saturation' */
  if (rtb_Add_nt > 0.1) {
    rtb_Add_nt = 0.1;
  } else if (rtb_Add_nt < -0.1) {
    rtb_Add_nt = -0.1;
  }

  /* Sum: '<S155>/Add' incorporates:
   *  Gain: '<S155>/Gain'
   *  Gain: '<S155>/Gain1'
   *  Saturate: '<S155>/Saturation'
   *  Sum: '<S155>/Sum'
   */
  rtb_Add_nt += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Init);

  /* Switch: '<S112>/Switch4' incorporates:
   *  Constant: '<S112>/Constant6'
   *  Constant: '<S112>/Constant7'
   *  Logic: '<S112>/Logical Operator1'
   *  Logic: '<S112>/Logical Operator2'
   *  RelationalOperator: '<S112>/LessThan2'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  if ((rtb_Init < 0.0) && rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay1_DSTATE_ea));
  }

  /* End of Switch: '<S112>/Switch4' */

  /* Switch: '<S112>/Switch1' incorporates:
   *  Constant: '<S112>/Constant1'
   *  Constant: '<S112>/Constant2'
   *  Logic: '<S112>/Logical Operator'
   *  Logic: '<S112>/Logical Operator1'
   *  RelationalOperator: '<S112>/LessThan'
   *  UnitDelay: '<S112>/Unit Delay'
   */
  if ((rtb_Init < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Is_Absolute_Translation_g = true;
  } else {
    rtb_Is_Absolute_Translation_g = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S112>/Switch1' */

  /* Switch: '<S155>/Switch' incorporates:
   *  Constant: '<S155>/Constant4'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* Sum: '<S155>/Sum2' incorporates:
     *  Gain: '<S155>/Gain2'
     *  Product: '<S155>/Product1'
     *  Sum: '<S155>/Sum'
     *  Switch: '<S155>/Switch1'
     *  UnitDelay: '<S155>/Unit Delay'
     */
    rtb_Init = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Init) * ((real_T)
      (!rtb_Intake_Arm_Move_Out))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S155>/Subtract' incorporates:
     *  Constant: '<S155>/Constant'
     */
    rtb_Error_h = 1.0 - rtb_Add_nt;

    /* Switch: '<S158>/Switch2' incorporates:
     *  Constant: '<S155>/Constant'
     *  RelationalOperator: '<S158>/LowerRelop1'
     *  Sum: '<S155>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Add_nt))) {
      /* Sum: '<S155>/Subtract1' incorporates:
       *  Constant: '<S155>/Constant1'
       */
      rtb_Error_h = -1.0 - rtb_Add_nt;

      /* Switch: '<S158>/Switch' incorporates:
       *  Constant: '<S155>/Constant1'
       *  RelationalOperator: '<S158>/UpperRelop'
       *  Sum: '<S155>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Add_nt))) {
        rtb_Error_h = rtb_Init;
      }

      /* End of Switch: '<S158>/Switch' */
    }

    /* End of Switch: '<S158>/Switch2' */

    /* Saturate: '<S155>/Saturation1' */
    if (rtb_Error_h > 0.1) {
      rtb_Init = 0.1;
    } else if (rtb_Error_h < -0.1) {
      rtb_Init = -0.1;
    } else {
      rtb_Init = rtb_Error_h;
    }

    /* End of Saturate: '<S155>/Saturation1' */
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S155>/Switch' */

  /* Switch: '<S112>/Switch2' incorporates:
   *  Logic: '<S112>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S155>/Add1' */
    rtb_Add_nt += rtb_Init;

    /* Saturate: '<S155>/Saturation2' */
    if (rtb_Add_nt > 1.0) {
      /* Switch: '<S112>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_nt < -1.0) {
      /* Switch: '<S112>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S112>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_nt;
    }

    /* End of Saturate: '<S155>/Saturation2' */
  } else {
    /* Switch: '<S112>/Switch2' incorporates:
     *  Constant: '<S112>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S112>/Switch2' */

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

  /* Update for UnitDelay: '<S28>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *
   * Block description for '<S28>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Joystick_Left_B11;

  /* Update for UnitDelay: '<S29>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Joystick_Left_B12;

  /* Update for UnitDelay: '<S30>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Joystick_Left_B13;

  /* Update for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = Robot_Control_B.Spline_Index;

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lly =
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

  /* Update for Delay: '<S49>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S69>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S49>/A'
   *  Delay: '<S49>/MemoryX'
   */
  rtb_Add_nt = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Error_h = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S49>/MemoryX' incorporates:
   *  Constant: '<S49>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S69>/A[k]*xhat[k|k-1]'
   *  Product: '<S69>/B[k]*u[k]'
   *  Sum: '<S69>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Add_nt) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Error_h) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S325>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S325>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

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

  /* Update for UnitDelay: '<S108>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S347>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S346>/UD'
   *
   * Block description for '<S346>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S344>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Saturation_h;

  /* Update for UnitDelay: '<S327>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Init_o;

  /* Update for UnitDelay: '<S342>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S342>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S342>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S326>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S335>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S335>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S335>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S301>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_DeadZone;

  /* Update for UnitDelay: '<S300>/UD'
   *
   * Block description for '<S300>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S294>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S238>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S237>/UD'
   *
   * Block description for '<S237>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Switch2;

  /* Update for UnitDelay: '<S231>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S249>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S248>/UD'
   *
   * Block description for '<S248>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_ow;

  /* Update for UnitDelay: '<S234>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S259>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S258>/UD'
   *
   * Block description for '<S258>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S252>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S270>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_bl;

  /* Update for UnitDelay: '<S269>/UD'
   *
   * Block description for '<S269>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_cw;

  /* Update for UnitDelay: '<S255>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S280>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S279>/UD'
   *
   * Block description for '<S279>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S273>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S291>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S290>/UD'
   *
   * Block description for '<S290>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S276>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S312>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S311>/UD'
   *
   * Block description for '<S311>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_ec;

  /* Update for UnitDelay: '<S297>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S162>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_os;

  /* Update for UnitDelay: '<S161>/UD'
   *
   * Block description for '<S161>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S160>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S114>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Swerve_Motors_Disabled;

  /* Update for UnitDelay: '<S106>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S106>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S47>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_fh;

  /* Update for UnitDelay: '<S46>/UD'
   *
   * Block description for '<S46>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_hm;

  /* Update for UnitDelay: '<S45>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_nh = rtb_AND1_c;

  /* Update for UnitDelay: '<S32>/Delay Input1'
   *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S43>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S43>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S39>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch2_nf;

  /* Update for UnitDelay: '<S38>/UD'
   *
   * Block description for '<S38>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_d = rtb_Product_di;

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ej = rtb_Error_e;

  /* Update for UnitDelay: '<S33>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dvn = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S157>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Switch2_p0;

  /* Update for UnitDelay: '<S156>/UD'
   *
   * Block description for '<S156>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_i;

  /* Update for UnitDelay: '<S112>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_Out;

  /* Update for UnitDelay: '<S155>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Init;

  /* Update for UnitDelay: '<S112>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_db = rtb_Is_Absolute_Translation_g;
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

  /* Start for If: '<S109>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S49>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S325>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S342>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S335>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S106>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S43>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S400>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S170>/If' */
  Robot_Control_DW.If_ActiveSubsystem_hk = -1;

  /* InitializeConditions for UnitDelay: '<S166>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S170>/Robot_Index_Is_Valid' */
  /* Start for If: '<S173>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S173>/Circle_Check_Valid' */
  /* Start for If: '<S175>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S173>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S170>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S141>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ll = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S109>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S109>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/If Action Subsystem2' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem2);

  /* End of SystemInitialize for SubSystem: '<S109>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S109>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/If Action Subsystem4' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem4);

  /* End of SystemInitialize for SubSystem: '<S109>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S146>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S109>/If Action Subsystem5' */
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
