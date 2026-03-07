/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.468
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Mar  5 23:15:44 2026
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
real_T Auto_Shoot_Time = 4.0;          /* Variable: Auto_Shoot_Time
                                        * Referenced by: '<S24>/Constant'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S404>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S400>/Constant'
                                        *   '<S400>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S404>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S400>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S236>/Constant3'
                                        *   '<S257>/Constant3'
                                        *   '<S278>/Constant3'
                                        *   '<S299>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S236>/Constant2'
                                   *   '<S257>/Constant2'
                                   *   '<S278>/Constant2'
                                   *   '<S299>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S236>/Saturation'
                                        *   '<S257>/Saturation'
                                        *   '<S278>/Saturation'
                                        *   '<S299>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S236>/Saturation'
                                        *   '<S257>/Saturation'
                                        *   '<S278>/Saturation'
                                        *   '<S299>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S236>/Gain'
                                            *   '<S257>/Gain'
                                            *   '<S278>/Gain'
                                            *   '<S299>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S236>/Gain2'
                                        *   '<S257>/Gain2'
                                        *   '<S278>/Gain2'
                                        *   '<S299>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S236>/Saturation1'
                                         *   '<S257>/Saturation1'
                                         *   '<S278>/Saturation1'
                                         *   '<S299>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S236>/Saturation1'
                                        *   '<S257>/Saturation1'
                                        *   '<S278>/Saturation1'
                                        *   '<S299>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S236>/Gain1'
                                        *   '<S257>/Gain1'
                                        *   '<S278>/Gain1'
                                        *   '<S299>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S241>/Constant'
                            *   '<S262>/Constant'
                            *   '<S283>/Constant'
                            *   '<S304>/Constant'
                            */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S155>/BlueAllianceZoneX'
                                         *   '<S157>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S128>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S128>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S128>/Constant1'
                                        *   '<S128>/Switch3'
                                        */
real_T Field_Pass_Y_Bottom = 0.63297;  /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S128>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 7.4364;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S128>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S156>/RedAllianceZoneX'
                                         *   '<S158>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S128>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S128>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S390>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S390>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = -1.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S123>/Constant'
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
                                   * Referenced by: '<S108>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S108>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S42>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_I = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_I
                                        * Referenced by: '<S42>/Gain2'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                        * Referenced by: '<S42>/Gain1'
                                        */
real_T Rebuilt_Intake_Arm_Integral_Enable = 0.0;
                                 /* Variable: Rebuilt_Intake_Arm_Integral_Enable
                                  * Referenced by: '<S38>/Constant1'
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
                                        * Referenced by: '<S39>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 1.8;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S39>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 27.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S146>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 33.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by: '<S151>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 32.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S142>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 57.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S143>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 82.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S144>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 107.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S145>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S147>/Unit Delay'
                                      *   '<S148>/Unit Delay'
                                      *   '<S149>/Unit Delay'
                                      *   '<S150>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_TeleOp = 140.0;/* Variable: Rebuilt_Match_Time_TeleOp
                                          * Referenced by: '<S114>/Constant'
                                          */
real_T Rebuilt_Match_Time_Transition = 7.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S140>/Constant'
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
                                * Referenced by: '<S40>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                           * Referenced by: '<S50>/Gain'
                                           */
real_T Rebuilt_Roller_Motor_Gain_I = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                          * Referenced by: '<S50>/Gain2'
                                          */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                          * Referenced by: '<S50>/Gain1'
                                          */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S129>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S129>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S129>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S129>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S129>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S129>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S129>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S129>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S125>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S125>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S125>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 4.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S125>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 3.4; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S125>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 3.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S125>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 2.8; /* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S125>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S125>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S126>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S126>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S126>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S126>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S126>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S126>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S126>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S126>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S116>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S116>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S116>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2900.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S139>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 3000.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S139>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3250.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S139>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3400.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S139>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3575.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S139>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3700.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S139>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3850.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S139>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S139>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S138>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3000.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S138>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3250.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S138>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3400.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S138>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3575.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S138>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3700.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S138>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 3850.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S138>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S138>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S132>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S132>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S132>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S132>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S132>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S132>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S132>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S132>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S136>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S117>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S160>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S160>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.0005;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                              * Referenced by: '<S160>/Gain1'
                                              */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S127>/Constant2'
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
                              * Referenced by: '<S119>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S165>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S165>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S165>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S389>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S387>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S389>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S390>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S390>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S225>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S225>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S172>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S185>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S225>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S332>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S332>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S332>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S332>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S332>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S332>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S349>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S349>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S349>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S349>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S348>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S349>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S349>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S349>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S349>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S349>/Constant1'
                                   *   '<S349>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S349>/Constant'
                                   *   '<S349>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S239>/Constant3'
                                        *   '<S260>/Constant3'
                                        *   '<S281>/Constant3'
                                        *   '<S302>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S239>/Constant2'
                                *   '<S260>/Constant2'
                                *   '<S281>/Constant2'
                                *   '<S302>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S239>/Saturation'
                                           *   '<S260>/Saturation'
                                           *   '<S281>/Saturation'
                                           *   '<S302>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S239>/Saturation'
                                          *   '<S260>/Saturation'
                                          *   '<S281>/Saturation'
                                          *   '<S302>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S239>/Gain2'
                                         *   '<S260>/Gain2'
                                         *   '<S281>/Gain2'
                                         *   '<S302>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S239>/Saturation1'
                                             *   '<S260>/Saturation1'
                                             *   '<S281>/Saturation1'
                                             *   '<S302>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S239>/Saturation1'
                                            *   '<S260>/Saturation1'
                                            *   '<S281>/Saturation1'
                                            *   '<S302>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S239>/Gain1'
                                        *   '<S260>/Gain1'
                                        *   '<S281>/Gain1'
                                        *   '<S302>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S331>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S331>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S331>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S331>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S331>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S331>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S389>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S389>/Constant1'
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
                                      * Referenced by: '<S388>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S388>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S388>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S319>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S319>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S319>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S319>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S319>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S319>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S390>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S389>/Dead Zone'
                                        *   '<S390>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S389>/Dead Zone'
                                        *   '<S390>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S387>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S387>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S387>/Constant4'
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
                                        * Referenced by: '<S387>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S387>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S387>/Constant5'
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
                                        *   '<S387>/Constant11'
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
 *    '<S114>/If Action Subsystem1'
 *    '<S114>/If Action Subsystem3'
 */
void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S147>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S114>/If Action Subsystem1'
 *    '<S114>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* Logic: '<S147>/NOT' incorporates:
   *  SignalConversion generated from: '<S147>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S147>/IsRedActive' */
  *rty_IsRedActive = rtu_IsBlueInactiveFirst;

  /* SignalConversion: '<S147>/Signal Copy' incorporates:
   *  Constant: '<S147>/Constant1'
   *  Sum: '<S147>/Sum'
   *  UnitDelay: '<S147>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S147>/Unit Delay' incorporates:
   *  Constant: '<S147>/Constant1'
   *  Sum: '<S147>/Sum'
   */
  localDW->UnitDelay_DSTATE -= 0.02;
}

/*
 * System initialize for action system:
 *    '<S114>/If Action Subsystem2'
 *    '<S114>/If Action Subsystem4'
 */
void Robot_C_IfActionSubsystem2_Init(DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S148>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S114>/If Action Subsystem2'
 *    '<S114>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  /* Logic: '<S148>/NOT1' incorporates:
   *  SignalConversion generated from: '<S148>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S148>/IsBlueActive' */
  *rty_IsBlueActive = rtu_IsBlueInactiveFirst;

  /* SignalConversion: '<S148>/Signal Copy' incorporates:
   *  Constant: '<S148>/Constant1'
   *  Sum: '<S148>/Sum'
   *  UnitDelay: '<S148>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S148>/Unit Delay' incorporates:
   *  Constant: '<S148>/Constant1'
   *  Sum: '<S148>/Sum'
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
  int32_T s197_iter;
  uint16_T s222_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T Iteration_Number;
  uint8_T rtb_Desired_Pipeline;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4;
  boolean_T rtb_Button_Shoot_Enable;
  boolean_T rtb_Button_Spinup_Enable;
  boolean_T rtb_Compare_ik;
  boolean_T rtb_Disable_Wheels;
  boolean_T rtb_Enable_Wheels;
  boolean_T rtb_Intake_Arm_Cycle;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation_g;
  boolean_T rtb_LogicalOperator1_n;
  boolean_T rtb_Reset_Wheel_Offsets;
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
  Robot_Control_B.Drive_Joystick_X = Robot_Control_U.Joystick_Left_X;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y = Robot_Control_U.Joystick_Left_Y;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z = Robot_Control_U.Joystick_Left_Z;

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

  /* If: '<S416>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S416>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S419>/Action Port'
     */
    /* Product: '<S419>/Product' incorporates:
     *  Constant: '<S419>/Constant1'
     *  Constant: '<S419>/Constant2'
     *  Math: '<S419>/Math Function'
     */
    rtb_Init_o = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495)
      * 111.0;

    /* End of Outputs for SubSystem: '<S416>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S416>/Subsystem' incorporates:
     *  ActionPort: '<S420>/Action Port'
     */
    /* SignalConversion generated from: '<S420>/Out1' incorporates:
     *  Constant: '<S420>/Constant'
     */
    rtb_Init_o = 0.0;

    /* End of Outputs for SubSystem: '<S416>/Subsystem' */
  }

  /* End of If: '<S416>/If' */

  /* Gain: '<S417>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S418>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Init_o * cos(rtb_Sin4)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S418>/theta->y'
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

    /* SignalConversion generated from: '<S4>/Enable_Wheels' incorporates:
     *  Constant: '<S4>/Constant18'
     */
    rtb_Enable_Wheels = false;

    /* SignalConversion generated from: '<S4>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S4>/Constant13'
     */
    rtb_Reset_Wheel_Offsets = false;

    /* SignalConversion generated from: '<S4>/Disable_Wheels' incorporates:
     *  Constant: '<S4>/Constant14'
     */
    rtb_Disable_Wheels = false;

    /* SignalConversion generated from: '<S4>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S4>/Constant12'
     */
    rtb_Swerve_Motors_Disabled = true;

    /* Merge: '<S9>/Merge23' incorporates:
     *  Constant: '<S4>/Constant23'
     *  SignalConversion generated from: '<S4>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* SignalConversion generated from: '<S4>/Desired_Pipeline' incorporates:
     *  Constant: '<S4>/Constant25'
     */
    rtb_Desired_Pipeline = 0U;

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
     *  Constant: '<S21>/Constant13'
     *  Constant: '<S21>/Constant14'
     *  Constant: '<S21>/Constant15'
     *  Constant: '<S21>/Constant16'
     *  Constant: '<S21>/Constant17'
     *  Constant: '<S21>/Constant9'
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

    /* End of MultiPortSwitch: '<S21>/Multiport Switch1' */

    /* Saturate: '<S20>/Saturation' incorporates:
     *  UnitDelay: '<S7>/Unit Delay2'
     */
    if (Robot_Control_DW.UnitDelay2_DSTATE > 10.0) {
      rtb_Saturation_h = 10.0;
    } else if (Robot_Control_DW.UnitDelay2_DSTATE < 1.0) {
      rtb_Saturation_h = 1.0;
    } else {
      rtb_Saturation_h = Robot_Control_DW.UnitDelay2_DSTATE;
    }

    /* End of Saturate: '<S20>/Saturation' */

    /* RelationalOperator: '<S23>/Compare' incorporates:
     *  Constant: '<S23>/Constant'
     *  UnitDelay: '<S19>/Unit Delay1'
     */
    rtb_Compare_ik = (Robot_Control_DW.UnitDelay1_DSTATE_k == 2.0);

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
    if (((int32_T)rtb_Compare_ik) > ((int32_T)
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
    if (rtb_Compare_ik) {
      rtb_Swerve_Motors_Disabled = (rtb_Init_o >= Auto_Shoot_Time);
    } else {
      rtb_Swerve_Motors_Disabled = false;
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
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) + 39];
      Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
    } else {
      switch (Robot_Control_DW.is_c6_Robot_Control) {
       case Robot_Control_IN_End_Action:
        Robot_Control_B.Auto_Spline_Enable = false;
        if (((Robot_Control_B.Auto_Desired_Static_Action == 0.0) ||
             rtb_Swerve_Motors_Disabled) && (Robot_Control_B.Auto_Path_Counter <
             Robot_Control_ConstB.Width)) {
          rtb_Swerve_Motors_Disabled = (rtb_MultiportSwitch1[((int32_T)
            (Robot_Control_B.Auto_Path_Counter + 1.0)) - 1] != 0);
        } else {
          rtb_Swerve_Motors_Disabled = false;
        }

        if (rtb_Swerve_Motors_Disabled) {
          Robot_Control_B.Auto_Path_Counter++;
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Start_Action;
          Robot_Control_B.Auto_Spline_Enable = true;
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        }
        break;

       case Robot_Control_IN_Follow_Path:
        if (Robot_Control_DW.UnitDelay_DSTATE_lly) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_End_Action;
          Robot_Control_B.Auto_Spline_Enable = false;
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        } else if (rtb_Saturation_h > Robot_Control_DW.UnitDelay_DSTATE_e3) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            49];
        }
        break;

       default:
        /* case IN_Start_Action: */
        Robot_Control_B.Auto_Spline_Enable = true;
        if ((Robot_Control_B.Auto_Desired_Static_Action == 0.0) ||
            rtb_Swerve_Motors_Disabled) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
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

    /* Merge: '<S9>/Merge9' incorporates:
     *  Lookup_n-D: '<S20>/1-D Lookup Table'
     *  Lookup_n-D: '<S20>/1-D Lookup Table1'
     */
    Robot_Control_B.Spline_Num_Poses =
      rtCP_uDLookupTable_tableData[plook_u32d_evencka
      (Robot_Control_B.Auto_Path_ID, 1.0, 1.0, 9U)];

    /* Merge: '<S9>/Merge7' incorporates:
     *  SignalConversion: '<S18>/Signal Copy'
     */
    Robot_Control_B.Spline_Enable = Robot_Control_B.Auto_Spline_Enable;

    /* Switch: '<S22>/Switch' */
    if (Robot_Control_B.Auto_Desired_Static_Action != 0.0) {
      rtb_Add_nt = Robot_Control_B.Auto_Desired_Static_Action;
    } else {
      rtb_Add_nt = Robot_Control_B.Auto_Desired_Dynamic_Action;
    }

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     *  Switch: '<S22>/Switch'
     */
    switch ((int32_T)rtb_Add_nt) {
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
      rtb_Intake_Arm_Cycle = false;

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
      rtb_Intake_Arm_Cycle = false;

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
      rtb_Intake_Arm_Cycle = true;

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
      rtb_Intake_Arm_Cycle = false;

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
      rtb_Intake_Arm_Cycle = false;

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

    /* SignalConversion generated from: '<S2>/Enable_Wheels' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    rtb_Enable_Wheels = false;

    /* SignalConversion generated from: '<S2>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S2>/Constant13'
     */
    rtb_Reset_Wheel_Offsets = false;

    /* SignalConversion generated from: '<S2>/Disable_Wheels' incorporates:
     *  Constant: '<S2>/Constant14'
     */
    rtb_Disable_Wheels = false;

    /* SignalConversion generated from: '<S2>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S2>/Constant4'
     */
    rtb_Swerve_Motors_Disabled = false;

    /* SignalConversion generated from: '<S2>/Desired_Pipeline' incorporates:
     *  Constant: '<S2>/Constant'
     */
    rtb_Desired_Pipeline = 0U;

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
    Robot_Control_DW.DelayInput1_DSTATE_kb = rtb_Compare_ik;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Init_o;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Saturation_h;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S389>/Unit Delay1'
       *  UnitDelay: '<S389>/Unit Delay2'
       *  UnitDelay: '<S389>/Unit Delay3'
       *  UnitDelay: '<S389>/Unit Delay4'
       *  UnitDelay: '<S392>/Delay Input1'
       *  UnitDelay: '<S393>/Delay Input1'
       *  UnitDelay: '<S394>/Delay Input1'
       *  UnitDelay: '<S395>/Delay Input1'
       *  UnitDelay: '<S397>/Delay Input1'
       *  UnitDelay: '<S403>/Unit Delay'
       *  UnitDelay: '<S403>/Unit Delay1'
       *  UnitDelay: '<S407>/FixPt Unit Delay1'
       *  UnitDelay: '<S407>/FixPt Unit Delay2'
       *
       * Block description for '<S392>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S393>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S394>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S395>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S397>/Delay Input1':
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

    /* Switch: '<S387>/Switch4' incorporates:
     *  Constant: '<S412>/Constant'
     *  Constant: '<S415>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S412>/Compare'
     *  RelationalOperator: '<S415>/Compare'
     *  Switch: '<S387>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S387>/Switch4' incorporates:
       *  Constant: '<S387>/Constant8'
       *  Sum: '<S387>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S387>/Switch5' incorporates:
       *  Constant: '<S387>/Constant7'
       *  Gain: '<S387>/Gain'
       *  Sum: '<S387>/Subtract5'
       *  Switch: '<S387>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S387>/Switch4' incorporates:
       *  Constant: '<S387>/Constant6'
       *  Switch: '<S387>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S387>/Switch4' */

    /* Logic: '<S387>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S387>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S389>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_nt = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_nt = 0.0;
    } else {
      rtb_Add_nt = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S389>/Add' incorporates:
     *  Constant: '<S389>/Constant'
     *  Constant: '<S389>/Constant1'
     *  DeadZone: '<S389>/Dead Zone'
     *  Lookup_n-D: '<S389>/Modulation_Str_Y_Rel'
     *  Product: '<S389>/Product'
     *  Product: '<S389>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Saturation_h = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                        Steering_Relative_Gain) + (rtb_Add_nt *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S391>/Compare' incorporates:
     *  Constant: '<S391>/Constant'
     */
    rtb_Compare_ik = (rtb_Saturation_h == 0.0);

    /* Logic: '<S389>/AND2' incorporates:
     *  RelationalOperator: '<S392>/FixPt Relational Operator'
     *  RelationalOperator: '<S393>/FixPt Relational Operator'
     *  RelationalOperator: '<S394>/FixPt Relational Operator'
     *  RelationalOperator: '<S395>/FixPt Relational Operator'
     *  UnitDelay: '<S392>/Delay Input1'
     *  UnitDelay: '<S393>/Delay Input1'
     *  UnitDelay: '<S394>/Delay Input1'
     *  UnitDelay: '<S395>/Delay Input1'
     *
     * Block description for '<S392>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S393>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S394>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S395>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Intake_Arm_Cycle = ((((((int32_T)Robot_Control_B.Face_Away_Driver) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)
      Robot_Control_B.Face_Left_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      Robot_Control_B.Face_Toward_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g))) || (((int32_T)
      Robot_Control_B.Face_Right_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S389>/AND1' incorporates:
     *  Logic: '<S389>/AND3'
     *  UnitDelay: '<S389>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_ik && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S389>/AND4' incorporates:
     *  Logic: '<S389>/AND8'
     *  UnitDelay: '<S389>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_ik && (!rtb_Intake_Arm_Cycle)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S389>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S389>/Switch8' incorporates:
     *  Constant: '<S398>/Constant'
     *  Logic: '<S389>/AND9'
     *  RelationalOperator: '<S397>/FixPt Relational Operator'
     *  RelationalOperator: '<S398>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S397>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S397>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_ik) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S389>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S389>/Switch8' incorporates:
       *  UnitDelay: '<S389>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S389>/Switch8' */

    /* Switch: '<S389>/Switch4' incorporates:
     *  Constant: '<S389>/Constant5'
     *  Switch: '<S389>/Switch1'
     *  Switch: '<S389>/Switch5'
     *  Switch: '<S389>/Switch6'
     *  Switch: '<S389>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Init_o = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S389>/Switch5' incorporates:
       *  Constant: '<S389>/Constant6'
       */
      rtb_Init_o = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S389>/Switch6' incorporates:
       *  Constant: '<S389>/Constant7'
       *  Switch: '<S389>/Switch5'
       */
      rtb_Init_o = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S389>/Switch7' incorporates:
       *  Constant: '<S389>/Constant8'
       *  Switch: '<S389>/Switch5'
       *  Switch: '<S389>/Switch6'
       */
      rtb_Init_o = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S389>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S389>/Switch5'
       *  Switch: '<S389>/Switch6'
       *  Switch: '<S389>/Switch7'
       */
      rtb_Init_o = 0.0;
    } else {
      /* Switch: '<S389>/Switch6' incorporates:
       *  Switch: '<S389>/Switch5'
       *  Switch: '<S389>/Switch7'
       *  UnitDelay: '<S389>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S389>/Switch4' */

    /* Switch: '<S389>/Switch2' incorporates:
     *  Switch: '<S389>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S389>/Switch2' incorporates:
       *  Constant: '<S389>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S389>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Init_o;
    } else {
      /* Switch: '<S389>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S389>/Switch3' incorporates:
       *  Constant: '<S389>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S389>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S389>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S388>/Switch1' incorporates:
     *  Constant: '<S388>/Constant5'
     *  Constant: '<S388>/Constant8'
     *  DataTypeConversion: '<S388>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_ik;
    }

    /* End of Switch: '<S388>/Switch1' */

    /* Lookup_n-D: '<S390>/Modulation_Drv' incorporates:
     *  Math: '<S390>/Magnitude'
     */
    rtb_Sin4 = look1_binlcpw(rt_hypotd_snf(Robot_Control_B.Drive_Joystick_X,
      Robot_Control_B.Drive_Joystick_Y), rtCP_Modulation_Drv_bp01Data,
      rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S401>/Compare' incorporates:
     *  Constant: '<S401>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Sin4 == 0.0);

    /* DeadZone: '<S390>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S390>/Dead Zone' */

    /* Logic: '<S390>/Logical Operator' incorporates:
     *  Constant: '<S402>/Constant'
     *  RelationalOperator: '<S402>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_DeadZone != 0.0) && rtb_Swerve_Motors_Disabled);

    /* Switch: '<S388>/Switch' incorporates:
     *  Constant: '<S388>/Constant5'
     *  Constant: '<S388>/Constant7'
     *  DataTypeConversion: '<S388>/Data Type Conversion'
     *  Logic: '<S390>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S388>/Switch' */

    /* Switch: '<S387>/Switch2' incorporates:
     *  Constant: '<S387>/Constant2'
     *  Constant: '<S411>/Constant'
     *  Constant: '<S414>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S411>/Compare'
     *  RelationalOperator: '<S414>/Compare'
     *  Sum: '<S387>/Subtract'
     *  Switch: '<S387>/Switch'
     *  Switch: '<S387>/Switch1'
     *  Switch: '<S387>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S387>/Switch2' incorporates:
       *  Constant: '<S387>/Constant5'
       *  Sum: '<S387>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S387>/Switch2' incorporates:
       *  Constant: '<S387>/Constant4'
       *  Sum: '<S387>/Subtract2'
       *  Switch: '<S387>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S387>/Switch1' incorporates:
       *  Constant: '<S387>/Constant1'
       *  Sum: '<S387>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S387>/Switch2' incorporates:
       *  Constant: '<S387>/Constant3'
       *  Switch: '<S387>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S387>/Switch1' incorporates:
       *  Constant: '<S387>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S387>/Switch2' */

    /* UnaryMinus: '<S387>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S403>/Switch1' incorporates:
     *  Constant: '<S408>/Constant'
     *  Constant: '<S409>/Constant'
     *  Logic: '<S403>/AND'
     *  RelationalOperator: '<S408>/Compare'
     *  RelationalOperator: '<S409>/Compare'
     *  Switch: '<S403>/Switch2'
     *  UnitDelay: '<S403>/Unit Delay'
     *  UnitDelay: '<S403>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_lw;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S403>/Switch1' */

    /* Switch: '<S390>/Switch1' incorporates:
     *  Logic: '<S390>/Logical Operator1'
     *  Switch: '<S390>/Switch4'
     *  Switch: '<S390>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S390>/Sign' */
      if (rtIsNaN(rtb_DeadZone)) {
        rtb_Add_nt = (rtNaN);
      } else if (rtb_DeadZone < 0.0) {
        rtb_Add_nt = -1.0;
      } else {
        rtb_Add_nt = (rtb_DeadZone > 0.0);
      }

      /* Switch: '<S390>/Switch5' incorporates:
       *  Constant: '<S390>/Constant3'
       *  Constant: '<S390>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S390>/Gain3'
       *  Signum: '<S390>/Sign'
       *  Sum: '<S390>/Add'
       *  Switch: '<S390>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_nt) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Switch: '<S390>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S390>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S390>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S390>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S390>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S390>/Switch4'
       *  Trigonometry: '<S390>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S390>/Switch1' */

    /* Switch: '<S400>/Switch1' incorporates:
     *  Constant: '<S400>/Constant'
     *  Constant: '<S400>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S400>/Switch1' */

    /* Switch: '<S407>/Init' incorporates:
     *  UnitDelay: '<S407>/FixPt Unit Delay1'
     *  UnitDelay: '<S407>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S407>/Init' */

    /* Sum: '<S405>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S406>/Switch2' incorporates:
     *  Constant: '<S404>/Constant1'
     *  Constant: '<S404>/Constant3'
     *  RelationalOperator: '<S406>/LowerRelop1'
     *  RelationalOperator: '<S406>/UpperRelop'
     *  Switch: '<S406>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S406>/Switch' incorporates:
       *  Constant: '<S404>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S406>/Switch2' */

    /* Sum: '<S405>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S390>/Switch8' incorporates:
     *  Logic: '<S390>/Logical Operator1'
     *  Switch: '<S390>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S390>/Switch' incorporates:
       *  Gain: '<S390>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_DeadZone;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S390>/Constant5'
       *  Gain: '<S390>/Gain2'
       *  Math: '<S390>/Magnitude1'
       *  MinMax: '<S390>/Min'
       *  Switch: '<S390>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S400>/Product' incorporates:
       *  Switch: '<S390>/Switch2'
       */
      rtb_Add_nt = rtb_Sin4 * rtb_Init;

      /* Saturate: '<S400>/Saturation' incorporates:
       *  Switch: '<S390>/Switch2'
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

      /* End of Saturate: '<S400>/Saturation' */
    }

    /* End of Switch: '<S390>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S389>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Saturation_h;

    /* Switch: '<S387>/Switch6' incorporates:
     *  Constant: '<S387>/Constant11'
     *  Switch: '<S387>/Switch7'
     */
    rtb_Desired_Pipeline = TEST_Pipeline;

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

    /* SignalConversion generated from: '<S15>/Enable_Wheels' incorporates:
     *  Constant: '<S15>/Constant6'
     */
    rtb_Enable_Wheels = false;

    /* SignalConversion generated from: '<S15>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S15>/Constant13'
     */
    rtb_Reset_Wheel_Offsets = false;

    /* SignalConversion generated from: '<S15>/Disable_Wheels' incorporates:
     *  Constant: '<S15>/Constant14'
     */
    rtb_Disable_Wheels = false;

    /* SignalConversion generated from: '<S15>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S15>/Constant2'
     */
    rtb_Swerve_Motors_Disabled = false;

    /* RelationalOperator: '<S384>/Compare' incorporates:
     *  Constant: '<S384>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S385>/Compare' incorporates:
     *  Constant: '<S385>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S380>/Compare' incorporates:
     *  Constant: '<S380>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S383>/Compare' incorporates:
     *  Constant: '<S383>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S382>/Compare' incorporates:
     *  Constant: '<S382>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S381>/Compare' incorporates:
     *  Constant: '<S381>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* Update for UnitDelay: '<S397>/Delay Input1'
     *
     * Block description for '<S397>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_ik;

    /* Update for UnitDelay: '<S396>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S396>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S392>/Delay Input1'
     *
     * Block description for '<S392>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S393>/Delay Input1'
     *
     * Block description for '<S393>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S394>/Delay Input1'
     *
     * Block description for '<S394>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S395>/Delay Input1'
     *
     * Block description for '<S395>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S389>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S389>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S389>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S389>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Init_o;

    /* Update for UnitDelay: '<S403>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_lw = rtb_Switch1;

    /* Update for UnitDelay: '<S403>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S407>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S407>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S407>/FixPt Unit Delay1' */
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
    rtb_Intake_Arm_Cycle = false;

    /* SignalConversion generated from: '<S16>/Desired_Pipeline' incorporates:
     *  Constant: '<S16>/Constant22'
     */
    rtb_Desired_Pipeline = TEST_Pipeline;

    /* SignalConversion generated from: '<S16>/Intake_Roller_On' incorporates:
     *  Constant: '<S16>/Constant20'
     */
    rtb_LogicalOperator1_n = false;

    /* SignalConversion: '<S16>/Signal Copy' */
    rtb_Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* SignalConversion: '<S16>/Signal Copy2' */
    rtb_Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* SignalConversion: '<S16>/Signal Copy1' */
    rtb_Reset_Wheel_Offsets = Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_Swerve_Motors_Disabled;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Reshape: '<S54>/Reshapey' incorporates:
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

  /* Delay: '<S54>/MemoryX' incorporates:
   *  Constant: '<S54>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S81>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S107>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S74>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S105>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S105>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S54>/C'
     *  Delay: '<S54>/MemoryX'
     *  Product: '<S107>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Init_o;

    /* Sum: '<S105>/Sum' incorporates:
     *  Constant: '<S54>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S105>/C[k]*xhat[k|k-1]'
     *  Product: '<S105>/D[k]*u[k]'
     *  Sum: '<S105>/Add1'
     */
    rtb_Sin4 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Saturation_h = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Init_o);

    /* Product: '<S105>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S54>/C'
     *  Delay: '<S54>/MemoryX'
     *  Product: '<S107>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Init_o;

    /* Sum: '<S105>/Sum' incorporates:
     *  Constant: '<S54>/D'
     *  Product: '<S105>/C[k]*xhat[k|k-1]'
     *  Product: '<S105>/D[k]*u[k]'
     *  Sum: '<S105>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Init_o);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S105>/Product3' incorporates:
     *  Constant: '<S55>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Saturation_h) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S107>/Add1' incorporates:
     *  Product: '<S107>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S105>/Product3' incorporates:
     *  Constant: '<S55>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Saturation_h) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S107>/Add1' incorporates:
     *  Product: '<S107>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S107>/Product2' incorporates:
     *  Constant: '<S55>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S105>/Product3' incorporates:
       *  Outport: '<S105>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S107>/Product2' incorporates:
       *  Outport: '<S107>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S74>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S81>/Enabled Subsystem' */

  /* Sum: '<S81>/Add' incorporates:
   *  Delay: '<S54>/MemoryX'
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
   *  Constant: '<S222>/Constant'
   *  Logic: '<S222>/AND'
   *  MATLAB Function: '<S172>/Find closest index to curve'
   *  Product: '<S222>/Product'
   *  RelationalOperator: '<S222>/Relational Operator'
   *  RelationalOperator: '<S222>/Relational Operator1'
   *  Selector: '<S222>/Selector'
   *  Selector: '<S222>/Selector1'
   *  Selector: '<S223>/Selector'
   *  Sum: '<S222>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S175>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_hk == 0) {
      /* Disable for If: '<S178>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S180>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_hk = -1;

    /* End of Disable for If: '<S175>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S170>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S170>/Unit Delay'
       *  UnitDelay: '<S171>/Unit Delay'
       *  UnitDelay: '<S173>/Unit Delay'
       *  UnitDelay: '<S173>/Unit Delay1'
       *  UnitDelay: '<S223>/Unit Delay'
       *  UnitDelay: '<S223>/Unit Delay1'
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
     *  ActionPort: '<S170>/Action Port'
     */
    /* Selector: '<S171>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S171>/Selector1' */

    /* Lookup_n-D: '<S170>/Capture Radius' incorporates:
     *  UnitDelay: '<S170>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S171>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S171>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S175>/If' incorporates:
     *  RelationalOperator: '<S175>/ '
     *  UnitDelay: '<S171>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_hk;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_hk = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S178>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S180>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S175>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      /* InitializeConditions for If: '<S175>/If' incorporates:
       *  UnitDelay: '<S178>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S175>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S175>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S178>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
      /* If: '<S178>/If' incorporates:
       *  Selector: '<S171>/Selector1'
       *  Selector: '<S178>/Selector'
       *  Selector: '<S181>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S178>/Increment_If_Rectangle_Check' */

      /* Sum: '<S178>/Minus' incorporates:
       *  Concatenate: '<S171>/Matrix Concatenate2'
       *  Selector: '<S178>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S178>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
      /* If: '<S178>/If' incorporates:
       *  Selector: '<S171>/Selector1'
       *  Selector: '<S178>/Selector'
       *  Selector: '<S181>/Selector'
       *  Sum: '<S178>/Minus'
       */
      rtb_DeadZone = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S178>/Increment_If_Rectangle_Check' */

      /* Sum: '<S178>/Minus' incorporates:
       *  Concatenate: '<S171>/Matrix Concatenate2'
       *  Selector: '<S178>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_DeadZone;

      /* Math: '<S178>/Hypot' */
      rtb_Init_o = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S178>/Equal' */
      rtb_AND1_c = (Robot_Control_B.Spline_Num_Poses ==
                    Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S178>/Switch' incorporates:
       *  Logic: '<S178>/AND'
       *  Logic: '<S178>/OR'
       *  RelationalOperator: '<S178>/Relational Operator'
       *  UnitDelay: '<S178>/Unit Delay'
       */
      rtb_Compare_ik = ((Robot_Control_DW.UnitDelay_DSTATE_e4) || ((rtb_Init_o <=
        rtb_Saturation_h) && rtb_AND1_c));

      /* If: '<S178>/If' */
      rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_o;
      if (!rtb_Compare_ik) {
        if (!rtb_AND1_c) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Robot_Control_DW.If_ActiveSubsystem_o = rtAction;
      if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
        /* Disable for If: '<S180>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S178>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S180>/Action Port'
         */
        /* If: '<S180>/If' incorporates:
         *  RelationalOperator: '<S180>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S180>/Is_Last_Point' incorporates:
           *  ActionPort: '<S183>/Action Port'
           */
          /* InitializeConditions for If: '<S180>/If' incorporates:
           *  UnitDelay: '<S183>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S180>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S180>/Is_Last_Point' incorporates:
           *  ActionPort: '<S183>/Action Port'
           */
          /* Switch: '<S183>/Switch' incorporates:
           *  Constant: '<S185>/Constant'
           *  Logic: '<S183>/OR'
           *  RelationalOperator: '<S185>/Compare'
           *  UnitDelay: '<S183>/Unit Delay'
           */
          rtb_Is_Absolute_Steering = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
            (rtb_Init_o <= Spline_Stop_Radius));

          /* If: '<S183>/If' */
          if (rtb_Is_Absolute_Steering) {
            /* Outputs for IfAction SubSystem: '<S183>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S186>/Action Port'
             */
            /* Merge: '<S175>/Merge2' incorporates:
             *  Constant: '<S186>/Constant'
             *  SignalConversion generated from: '<S186>/Robot_Reached_Destination'
             */
            rtb_AND1_c = true;

            /* SignalConversion generated from: '<S186>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S186>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = false;

            /* End of Outputs for SubSystem: '<S183>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S183>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S187>/Action Port'
             */
            /* Merge: '<S175>/Merge2' incorporates:
             *  Constant: '<S187>/Constant'
             *  SignalConversion generated from: '<S187>/Robot_Reached_Destination'
             */
            rtb_AND1_c = false;

            /* SignalConversion generated from: '<S187>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S187>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = true;

            /* End of Outputs for SubSystem: '<S183>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S183>/If' */

          /* Merge: '<S175>/Merge4' incorporates:
           *  SignalConversion: '<S183>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S183>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Is_Absolute_Steering;

          /* End of Outputs for SubSystem: '<S180>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S180>/Increment_Search' incorporates:
           *  ActionPort: '<S182>/Action Port'
           */
          /* Merge: '<S175>/Merge2' incorporates:
           *  Constant: '<S182>/Constant'
           *  SignalConversion generated from: '<S182>/Robot_Reached_Destination'
           */
          rtb_AND1_c = false;

          /* SignalConversion generated from: '<S182>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S182>/Constant1'
           */
          rtb_Is_Absolute_Translation_g = false;

          /* Merge: '<S175>/Merge4' incorporates:
           *  Constant: '<S184>/FixPt Constant'
           *  SignalConversion: '<S182>/Signal Copy'
           *  Sum: '<S184>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S180>/Increment_Search' */
        }

        /* End of If: '<S180>/If' */
        /* End of Outputs for SubSystem: '<S178>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S178>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S181>/Action Port'
         */
        /* Sum: '<S188>/FixPt Sum1' incorporates:
         *  Constant: '<S188>/FixPt Constant'
         */
        rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S181>/Selector1' incorporates:
         *  Selector: '<S171>/Selector1'
         */
        rtb_Switch2_p2 = rtb_Ref_Poses[((int32_T)rtb_Init_o) - 1];

        /* Sum: '<S189>/Subtract' incorporates:
         *  Selector: '<S181>/Selector1'
         *  Sum: '<S189>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_p2 - rtb_Init;

        /* Selector: '<S181>/Selector1' incorporates:
         *  Selector: '<S171>/Selector1'
         */
        rtb_Switch1 = rtb_Ref_Poses[((int32_T)rtb_Init_o) + 9];

        /* Sum: '<S189>/Subtract' incorporates:
         *  Selector: '<S181>/Selector1'
         *  Sum: '<S189>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1 - rtb_DeadZone;

        /* Math: '<S189>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S189>/Divide' */
        rtb_Init_o = rtb_Minus_n[1];

        /* UnaryMinus: '<S189>/Unary Minus' */
        rtb_Switch2_nf = rtb_Minus_n[0];

        /* Product: '<S189>/Product' incorporates:
         *  Product: '<S189>/Divide'
         *  UnaryMinus: '<S189>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Init_o / rtb_Sin4) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Switch2_nf) / rtb_Sin4) * rtb_Saturation_h;

        /* Sum: '<S189>/Add1' incorporates:
         *  Sum: '<S189>/Add2'
         *  Sum: '<S189>/Minus'
         */
        rtb_Switch2_nf = rtb_Switch2_p2 - rtb_Minus_n[0];

        /* Sum: '<S189>/Minus4' incorporates:
         *  Sum: '<S189>/Add2'
         *  Sum: '<S189>/Minus'
         */
        rtb_Switch2_p2 = (rtb_Switch2_p2 + rtb_Minus_n[0]) - rtb_Switch2_nf;

        /* Sum: '<S189>/Minus5' incorporates:
         *  Concatenate: '<S171>/Matrix Concatenate2'
         *  Sum: '<S189>/Minus'
         */
        rtb_Switch2 = rtb_Reshapey[0] - rtb_Switch2_nf;

        /* Sum: '<S189>/Add' incorporates:
         *  Sum: '<S189>/Add2'
         *  Sum: '<S189>/Minus1'
         */
        rtb_Init_o = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S189>/Minus' incorporates:
         *  Sum: '<S189>/Minus1'
         */
        rtb_Switch2_nf -= rtb_Init_o;

        /* DotProduct: '<S189>/Dot Product' incorporates:
         *  Concatenate: '<S171>/Matrix Concatenate2'
         *  Sum: '<S189>/Minus'
         *  Sum: '<S189>/Minus1'
         *  Sum: '<S189>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Init_o) * rtb_Switch2_nf;

        /* DotProduct: '<S189>/Dot Product1' incorporates:
         *  Sum: '<S189>/Minus'
         */
        rtb_Init = rtb_Switch2_nf * rtb_Switch2_nf;

        /* DotProduct: '<S189>/Dot Product2' incorporates:
         *  Sum: '<S189>/Minus4'
         *  Sum: '<S189>/Minus5'
         */
        rtb_Minus_k_idx_1 = rtb_Switch2_p2 * rtb_Switch2;

        /* DotProduct: '<S189>/Dot Product3' incorporates:
         *  Sum: '<S189>/Minus4'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2 * rtb_Switch2_p2;

        /* Sum: '<S189>/Add1' incorporates:
         *  Sum: '<S189>/Add2'
         *  Sum: '<S189>/Minus'
         */
        rtb_Switch2_nf = rtb_Switch1 - rtb_Minus_n[1];

        /* Sum: '<S189>/Minus4' incorporates:
         *  Sum: '<S189>/Add2'
         *  Sum: '<S189>/Minus'
         */
        rtb_Switch2_p2 = (rtb_Switch1 + rtb_Minus_n[1]) - rtb_Switch2_nf;

        /* Sum: '<S189>/Minus5' incorporates:
         *  Concatenate: '<S171>/Matrix Concatenate2'
         *  Sum: '<S189>/Minus'
         */
        rtb_Switch2 = rtb_Reshapey[1] - rtb_Switch2_nf;

        /* Sum: '<S189>/Add' incorporates:
         *  Sum: '<S189>/Add2'
         *  Sum: '<S189>/Minus1'
         */
        rtb_Init_o = rtb_DeadZone - rtb_Minus_n[1];

        /* Sum: '<S189>/Minus' incorporates:
         *  Sum: '<S189>/Minus1'
         */
        rtb_Switch2_nf -= rtb_Init_o;

        /* DotProduct: '<S189>/Dot Product' incorporates:
         *  Concatenate: '<S171>/Matrix Concatenate2'
         *  Sum: '<S189>/Minus'
         *  Sum: '<S189>/Minus1'
         *  Sum: '<S189>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Init_o) * rtb_Switch2_nf;

        /* RelationalOperator: '<S190>/Compare' incorporates:
         *  Constant: '<S190>/Constant'
         */
        rtb_AND1_c = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S189>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S189>/Dot Product1'
         *  Sum: '<S189>/Minus'
         */
        rtb_Is_Absolute_Translation_g = (rtb_Sin4 <= ((rtb_Switch2_nf *
          rtb_Switch2_nf) + rtb_Init));

        /* DotProduct: '<S189>/Dot Product2' incorporates:
         *  Sum: '<S189>/Minus4'
         *  Sum: '<S189>/Minus5'
         */
        rtb_Sin4 = (rtb_Switch2_p2 * rtb_Switch2) + rtb_Minus_k_idx_1;

        /* Merge: '<S175>/Merge4' incorporates:
         *  Constant: '<S191>/Constant'
         *  DataTypeConversion: '<S181>/Data Type Conversion'
         *  DotProduct: '<S189>/Dot Product3'
         *  Logic: '<S189>/AND'
         *  RelationalOperator: '<S189>/LessThanOrEqual1'
         *  RelationalOperator: '<S191>/Compare'
         *  Sum: '<S181>/Add'
         *  Sum: '<S189>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_AND1_c &&
          rtb_Is_Absolute_Translation_g) && (rtb_Sin4 >= 0.0)) && (rtb_Sin4 <=
          ((rtb_Switch2_p2 * rtb_Switch2_p2) + rtb_MatrixConcatenate_b_idx_0))))
          + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S175>/Merge2' incorporates:
         *  Constant: '<S181>/Constant2'
         *  SignalConversion generated from: '<S181>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S181>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S181>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* End of Outputs for SubSystem: '<S178>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S178>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S179>/Action Port'
         */
        /* Merge: '<S175>/Merge2' incorporates:
         *  Constant: '<S179>/Constant2'
         *  SignalConversion generated from: '<S179>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S179>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S179>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* Merge: '<S175>/Merge4' incorporates:
         *  SignalConversion generated from: '<S179>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S178>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S175>/Merge1' incorporates:
       *  Constant: '<S178>/Constant'
       *  SignalConversion generated from: '<S178>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S178>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_Compare_ik;

      /* End of Outputs for SubSystem: '<S175>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S175>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* Merge: '<S175>/Merge1' incorporates:
       *  Constant: '<S177>/Constant'
       *  SignalConversion generated from: '<S177>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S175>/Merge2' incorporates:
       *  Constant: '<S177>/Constant1'
       *  SignalConversion generated from: '<S177>/Robot_Reached_Destination'
       */
      rtb_AND1_c = false;

      /* SignalConversion generated from: '<S177>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S177>/Constant2'
       */
      rtb_Is_Absolute_Translation_g = false;

      /* Merge: '<S175>/Merge4' incorporates:
       *  SignalConversion generated from: '<S177>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S175>/Escape_Auto_Driving' */
    }

    /* End of If: '<S175>/If' */

    /* If: '<S171>/If1' */
    if (!rtb_Is_Absolute_Translation_g) {
      /* Outputs for IfAction SubSystem: '<S171>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* Bias: '<S192>/Add Constant' incorporates:
       *  Bias: '<S192>/Bias'
       *  Sum: '<S192>/Subtract'
       */
      rtb_Init_o = ((Robot_Control_B.Spline_Num_Poses -
                     Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S192>/Selector4' incorporates:
       *  Bias: '<S192>/Bias1'
       *  Constant: '<S194>/FixPt Constant'
       *  Sum: '<S194>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S192>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S192>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s197_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S192>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S192>/Selector5' incorporates:
       *  Concatenate: '<S192>/Matrix Concatenate'
       *  Gain: '<S196>/Gain'
       *  Selector: '<S171>/Selector1'
       *  Selector: '<S192>/Selector2'
       *  Selector: '<S192>/Selector3'
       *  Sum: '<S196>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s197_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S192>/Matrix Concatenate' incorporates:
       *  Bias: '<S192>/Add Constant1'
       *  Gain: '<S195>/Gain'
       *  Selector: '<S171>/Selector1'
       *  Selector: '<S192>/Selector'
       *  Selector: '<S192>/Selector1'
       *  Selector: '<S192>/Selector5'
       *  Sum: '<S195>/Subtract'
       */
      s197_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s197_iter;
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

      /* Selector: '<S192>/Selector4' */
      s197_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s197_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S192>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S192>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S192>/Assignment' incorporates:
       *  Concatenate: '<S192>/Matrix Concatenate'
       *  Selector: '<S192>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s197_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S193>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S197>/While Iterator'
       */
      s197_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s197_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s197_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s197_iter] - rtb_Assignment[s197_iter + 2];
        rtb_Switch2_p2 = rtb_Init - rtb_Assignment[s197_iter];
        rtb_Init = rtb_Assignment[s197_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s197_iter + 11];
        rtb_Switch2_nf = rtb_Assignment[s197_iter + 12];
        rtb_Add2[1] = rtb_Switch2_nf - rtb_Assignment[s197_iter + 14];
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
            rtb_Assignment[s197_iter];
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

        if (s197_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s197_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Init_o - ((real_T)s197_iter);
        rtb_Num_Segments = s197_iter;
        s197_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s197_iter <= 3));

      /* End of Outputs for SubSystem: '<S193>/Sampling_Loop' */

      /* SignalConversion generated from: '<S176>/Position_and_Curvature' incorporates:
       *  Assignment: '<S197>/Assignment'
       *  Merge: '<S171>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S171>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S171>/If Action Subsystem' incorporates:
       *  ActionPort: '<S174>/Action Port'
       */
      /* Product: '<S174>/Product' incorporates:
       *  Selector: '<S171>/Selector'
       *  Selector: '<S171>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1];

      /* Product: '<S174>/Product1' incorporates:
       *  Selector: '<S171>/Selector'
       *  Selector: '<S171>/Selector1'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S174>/Product' incorporates:
         *  Constant: '<S174>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S174>/Product1' incorporates:
         *  Constant: '<S174>/Constant2'
         *  Product: '<S174>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Init_o;
      }

      /* Assignment: '<S174>/Assignment' incorporates:
       *  Concatenate: '<S174>/Matrix Concatenate'
       *  Merge: '<S171>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S174>/Assignment' */

      /* SignalConversion generated from: '<S174>/Num_Segments' incorporates:
       *  Constant: '<S174>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S171>/If Action Subsystem' */
    }

    /* End of If: '<S171>/If1' */

    /* Concatenate: '<S172>/Matrix Concatenate' incorporates:
     *  Merge: '<S171>/Merge'
     *  Selector: '<S172>/Selector'
     *  Selector: '<S172>/Selector1'
     *  Selector: '<S172>/Selector3'
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

    /* End of Concatenate: '<S172>/Matrix Concatenate' */

    /* MATLAB Function: '<S172>/Distance Along Curve' incorporates:
     *  Concatenate: '<S172>/Matrix Concatenate'
     *  Selector: '<S172>/Selector4'
     *  Selector: '<S172>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s197_iter = 0; s197_iter < 149; s197_iter++) {
      /* Outputs for Iterator SubSystem: '<S193>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S197>/While Iterator'
       */
      rtb_Assignment_d[s197_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s197_iter + 1] -
         rtb_MatrixConcatenate_o[s197_iter], rtb_MatrixConcatenate_o[s197_iter +
         151] - rtb_MatrixConcatenate_o[s197_iter + 150]) +
        rtb_Assignment_d[s197_iter];

      /* End of Outputs for SubSystem: '<S193>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S172>/Distance Along Curve' */

    /* MATLAB Function: '<S172>/Find closest index to curve' incorporates:
     *  Concatenate: '<S172>/Matrix Concatenate'
     *  Selector: '<S172>/Selector4'
     *  Selector: '<S172>/Selector5'
     *  Selector: '<S223>/Selector'
     */
    for (s197_iter = 0; s197_iter < 150; s197_iter++) {
      /* Outputs for Iterator SubSystem: '<S193>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S197>/While Iterator'
       */
      distance_from_robot[s197_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s197_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s197_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S193>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s197_iter = 1;
    } else {
      s197_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s197_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s197_iter == 0) {
      rtb_Init_o = distance_from_robot[0];
    } else {
      rtb_Init_o = distance_from_robot[s197_iter - 1];
      for (rtb_Bias1_p = s197_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Init_o > rtb_Sin4) {
          rtb_Init_o = rtb_Sin4;
        }
      }
    }

    s197_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s197_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Init_o) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S223>/Selector' incorporates:
     *  Constant: '<S223>/Constant'
     *  MATLAB Function: '<S172>/Find closest index to curve'
     *  MinMax: '<S223>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s197_iter)) - 1];

    /* If: '<S223>/If' incorporates:
     *  RelationalOperator: '<S223>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S223>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S226>/Action Port'
       */
      /* SignalConversion generated from: '<S226>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S228>/FixPt Sum1' incorporates:
       *  Constant: '<S228>/FixPt Constant'
       */
      rtb_Init_o = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S226>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S226>/Selector11'
       *  Selector: '<S226>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S226>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S226>/Selector1'
       *  Selector: '<S226>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S226>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S226>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Init_o), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S226>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S226>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S226>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S223>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S223>/Latch' incorporates:
       *  ActionPort: '<S227>/Action Port'
       */
      /* SignalConversion generated from: '<S227>/In1' incorporates:
       *  UnitDelay: '<S223>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S227>/In2' incorporates:
       *  UnitDelay: '<S223>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S223>/Latch' */
    }

    /* End of If: '<S223>/If' */

    /* MinMax: '<S170>/Min' incorporates:
     *  Lookup_n-D: '<S170>/Lookahead Distance'
     *  UnitDelay: '<S170>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S172>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S222>/While Iterator'
     */
    s222_iter = 1U;
    rtb_Compare_ik = true;
    while (rtb_Compare_ik && (s222_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S172>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S222>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s222_iter;
      rtb_Compare_ik = ((rtb_Assignment_d[Robot_Control_B.WhileIterator - 1] <=
                         (rtb_Assignment_d[s197_iter - 1] + rtb_Saturation_h)) &&
                        (Robot_Control_B.WhileIterator < (((real_T)
        rtb_Num_Segments) * 50.0)));
      s222_iter++;
    }

    /* End of Outputs for SubSystem: '<S172>/Find first index that meets distance target' */

    /* Switch: '<S225>/Switch' incorporates:
     *  Concatenate: '<S172>/Matrix Concatenate'
     *  Constant: '<S172>/Constant'
     *  Constant: '<S222>/Constant'
     *  Constant: '<S225>/Constant'
     *  Constant: '<S225>/Constant1'
     *  Constant: '<S225>/Constant2'
     *  Constant: '<S225>/Constant3'
     *  Logic: '<S222>/AND'
     *  MATLAB Function: '<S172>/Find closest index to curve'
     *  Math: '<S225>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S225>/Max'
     *  MinMax: '<S225>/Min'
     *  MinMax: '<S225>/Min1'
     *  Product: '<S222>/Product'
     *  Product: '<S225>/Divide'
     *  Product: '<S225>/Product'
     *  Product: '<S225>/Product1'
     *  RelationalOperator: '<S172>/Relational Operator'
     *  RelationalOperator: '<S222>/Relational Operator'
     *  RelationalOperator: '<S222>/Relational Operator1'
     *  Selector: '<S172>/Selector10'
     *  Selector: '<S172>/Selector7'
     *  Selector: '<S172>/Selector8'
     *  Selector: '<S172>/Selector9'
     *  Selector: '<S222>/Selector'
     *  Selector: '<S222>/Selector1'
     *  Selector: '<S223>/Selector'
     *  Sqrt: '<S225>/Sqrt'
     *  Sum: '<S172>/Subtract'
     *  Sum: '<S222>/Add'
     *  Sum: '<S225>/Subtract'
     *  Sum: '<S225>/Subtract1'
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

    /* End of Switch: '<S225>/Switch' */

    /* Logic: '<S173>/OR' */
    rtb_Is_Absolute_Translation_g = (rtb_AND1_c ||
      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S173>/Switch1' incorporates:
     *  Switch: '<S173>/Switch'
     *  UnitDelay: '<S173>/Unit Delay'
     */
    if (rtb_Is_Absolute_Translation_g) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S173>/Constant3'
       *  SignalConversion: '<S173>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S173>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S173>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S173>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S172>/Selector6' incorporates:
     *  Concatenate: '<S172>/Matrix Concatenate'
     *  Selector: '<S172>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S172>/Selector2' incorporates:
     *  Concatenate: '<S172>/Matrix Concatenate'
     *  Selector: '<S172>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S173>/Switch2' incorporates:
     *  Sum: '<S229>/Subtract'
     *  Sum: '<S229>/Subtract1'
     *  Trigonometry: '<S229>/Atan2'
     *  UnitDelay: '<S173>/Unit Delay1'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_DeadZone = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_DeadZone = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S173>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S173>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_DeadZone;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S170>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_AND1_c;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S170>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S173>/Constant2'
     *  SignalConversion generated from: '<S170>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S173>/Constant5'
     *  SignalConversion generated from: '<S170>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S173>/Constant6'
     *  SignalConversion generated from: '<S170>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S170>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S171>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S170>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S223>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Init_o;

    /* Update for UnitDelay: '<S223>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S173>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S173>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_DeadZone;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S169>/Constant1'
     *  SignalConversion generated from: '<S169>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S169>/Constant'
     *  SignalConversion generated from: '<S169>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S169>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S169>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S169>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S169>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S169>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S169>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S169>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S319>/Sign2' incorporates:
   *  UnitDelay: '<S319>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_nt = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S319>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S319>/Product1' incorporates:
   *  Signum: '<S319>/Sign1'
   *  Signum: '<S319>/Sign2'
   */
  rtb_Add_nt *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_nt)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_nt, 256.0);
  }

  /* Switch: '<S319>/Switch' incorporates:
   *  Constant: '<S319>/Constant'
   *  Constant: '<S324>/Constant'
   *  Constant: '<S325>/Constant'
   *  Logic: '<S319>/or'
   *  Product: '<S319>/Product1'
   *  RelationalOperator: '<S324>/Compare'
   *  RelationalOperator: '<S325>/Compare'
   *  UnitDelay: '<S319>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S319>/Switch' */

  /* Switch: '<S330>/Init' incorporates:
   *  UnitDelay: '<S330>/FixPt Unit Delay1'
   *  UnitDelay: '<S330>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S330>/Init' */

  /* RelationalOperator: '<S326>/Compare' incorporates:
   *  Constant: '<S326>/Constant'
   */
  rtb_Compare_ik = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S327>/Compare' incorporates:
   *  Constant: '<S327>/Constant'
   */
  rtb_AND1_c = (rtb_Sin4 > 0.0);

  /* Abs: '<S319>/Abs' incorporates:
   *  Sum: '<S319>/Subtract'
   *  UnitDelay: '<S319>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S319>/Switch5' incorporates:
   *  Constant: '<S319>/Constant1'
   *  Switch: '<S319>/Switch1'
   *  UnaryMinus: '<S319>/Unary Minus'
   */
  if (rtb_Compare_ik) {
    /* SignalConversion generated from: '<S319>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S319>/Constant4'
     *  Constant: '<S319>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S319>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S319>/Constant2'
     *  Constant: '<S319>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S319>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S319>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S319>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S319>/Constant10'
     *  Constant: '<S319>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S319>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S319>/Constant7'
     *  Constant: '<S319>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S319>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S319>/Lookup Table Dynamic1'
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

    /* Switch: '<S319>/Switch3' incorporates:
     *  Constant: '<S319>/Constant1'
     *  Constant: '<S319>/Constant3'
     *  UnaryMinus: '<S319>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_nt = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_nt = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S319>/Switch3' */
  }

  /* End of Switch: '<S319>/Switch5' */

  /* Product: '<S319>/Product' incorporates:
   *  Switch: '<S319>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_nt * rtb_Merge1;

  /* Sum: '<S328>/Sum1' */
  rtb_Saturation_h = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S329>/Switch2' incorporates:
   *  RelationalOperator: '<S329>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S319>/Switch2' incorporates:
     *  Constant: '<S319>/Constant1'
     *  Switch: '<S319>/Switch4'
     */
    if (rtb_Compare_ik) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S319>/Switch4' incorporates:
       *  Constant: '<S319>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S319>/Switch4' incorporates:
       *  Constant: '<S319>/Constant3'
       *  UnaryMinus: '<S319>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S319>/Switch2' */

    /* Product: '<S319>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S329>/Switch' incorporates:
     *  RelationalOperator: '<S329>/UpperRelop'
     */
    if (rtb_Saturation_h < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Saturation_h;
    }

    /* End of Switch: '<S329>/Switch' */
  }

  /* End of Switch: '<S329>/Switch2' */

  /* Sum: '<S328>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S322>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S322>/Switch' incorporates:
     *  Constant: '<S354>/Constant3'
     *  Constant: '<S354>/Constant4'
     *  Math: '<S354>/Math Function'
     *  Sum: '<S322>/Subtract'
     *  Sum: '<S354>/Add1'
     *  Sum: '<S354>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S322>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S322>/Switch' */

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

  /* Sum: '<S114>/Subtract' incorporates:
   *  Constant: '<S114>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Sin4 = Rebuilt_Match_Time_TeleOp - Robot_Control_U.MatchTime;

  /* If: '<S114>/If' incorporates:
   *  Constant: '<S140>/Constant'
   *  Constant: '<S141>/Constant'
   *  Constant: '<S142>/Constant'
   *  Constant: '<S143>/Constant'
   *  Constant: '<S144>/Constant'
   *  Constant: '<S145>/Constant'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S140>/Compare'
   *  RelationalOperator: '<S141>/Compare'
   *  RelationalOperator: '<S142>/Compare'
   *  RelationalOperator: '<S143>/Compare'
   *  RelationalOperator: '<S144>/Compare'
   *  RelationalOperator: '<S145>/Compare'
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
      /* InitializeConditions for IfAction SubSystem: '<S114>/If Action Subsystem' incorporates:
       *  ActionPort: '<S146>/Action Port'
       */
      /* InitializeConditions for If: '<S114>/If' incorporates:
       *  UnitDelay: '<S146>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_ll = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S114>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem' incorporates:
     *  ActionPort: '<S146>/Action Port'
     */
    /* Merge: '<S114>/Merge' incorporates:
     *  Constant: '<S146>/Constant'
     *  SignalConversion generated from: '<S146>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S114>/Merge1' incorporates:
     *  Constant: '<S146>/Constant'
     *  SignalConversion generated from: '<S146>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S146>/Sum' incorporates:
     *  Constant: '<S146>/Constant1'
     *  UnitDelay: '<S146>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_ll - 0.02;

    /* Merge: '<S114>/Merge2' incorporates:
     *  SignalConversion: '<S146>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S146>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ll = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S147>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S148>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    /* Merge: '<S114>/Merge' incorporates:
     *  Constant: '<S151>/Constant'
     *  SignalConversion generated from: '<S151>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S114>/Merge1' incorporates:
     *  Constant: '<S151>/Constant'
     *  SignalConversion generated from: '<S151>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S151>/Sum' incorporates:
     *  Constant: '<S151>/Constant1'
     *  UnitDelay: '<S151>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_n - 0.02;

    /* Merge: '<S114>/Merge2' incorporates:
     *  SignalConversion: '<S151>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S151>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S114>/If' */

  /* If: '<S153>/If' incorporates:
   *  If: '<S154>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S153>/Blue' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* Merge: '<S153>/Merge' incorporates:
     *  Constant: '<S155>/BlueAllianceZoneX'
     *  Logic: '<S155>/AND'
     *  RelationalOperator: '<S155>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S153>/Blue' */

    /* Outputs for IfAction SubSystem: '<S154>/Blue' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    /* Merge: '<S154>/Merge' incorporates:
     *  Constant: '<S157>/BlueAllianceZoneX'
     *  RelationalOperator: '<S157>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S154>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S153>/Red' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    /* Merge: '<S153>/Merge' incorporates:
     *  Constant: '<S156>/RedAllianceZoneX'
     *  Logic: '<S156>/AND'
     *  RelationalOperator: '<S156>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S153>/Red' */

    /* Outputs for IfAction SubSystem: '<S154>/Red' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    /* Merge: '<S154>/Merge' incorporates:
     *  Constant: '<S158>/RedAllianceZoneX'
     *  RelationalOperator: '<S158>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S154>/Red' */
  }

  /* End of If: '<S153>/If' */

  /* RelationalOperator: '<S116>/GreaterThan' incorporates:
   *  Constant: '<S116>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S116>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S116>/Relational Operator' incorporates:
   *  Abs: '<S116>/Abs'
   *  Constant: '<S152>/Constant3'
   *  Constant: '<S152>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S152>/Math Function'
   *  Sum: '<S116>/Subtract'
   *  Sum: '<S152>/Add1'
   *  Sum: '<S152>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S115>/Max' incorporates:
   *  Abs: '<S115>/Abs1'
   *  Abs: '<S115>/Abs2'
   *  Abs: '<S115>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S116>/Relational Operator1' incorporates:
   *  Abs: '<S116>/Abs1'
   *  Constant: '<S116>/Constant2'
   *  Sum: '<S116>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S116>/Relational Operator4' incorporates:
   *  Abs: '<S116>/Abs4'
   *  Constant: '<S116>/Constant1'
   *  Sum: '<S116>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S116>/AND' */
  rtb_Compare_ik = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S116>/AND2' incorporates:
   *  Logic: '<S116>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_ik);

  /* SignalConversion: '<S116>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S116>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Compare_ik);

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
        if (rtb_Is_Absolute_Translation_g) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        }
        break;

       case Robot_Control_IN_Spinning_Up:
        Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        if (rtb_Button_Shoot_Enable && ((Robot_Control_B.RB_Ready_to_Score) ||
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
        } else if (rtb_Is_Absolute_Translation_g) {
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
    /* Outputs for IfAction SubSystem: '<S113>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S122>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S124>/While Iterator'
     */
    /* If: '<S113>/If' incorporates:
     *  Constant: '<S122>/Constant'
     *  Constant: '<S123>/Constant'
     *  Constant: '<S125>/Constant1'
     *  Constant: '<S125>/Constant10'
     *  Constant: '<S125>/Constant2'
     *  Constant: '<S125>/Constant5'
     *  Constant: '<S125>/Constant6'
     *  Constant: '<S125>/Constant7'
     *  Constant: '<S125>/Constant8'
     *  Constant: '<S125>/Constant9'
     *  Constant: '<S126>/Constant1'
     *  Constant: '<S126>/Constant10'
     *  Constant: '<S126>/Constant2'
     *  Constant: '<S126>/Constant5'
     *  Constant: '<S126>/Constant6'
     *  Constant: '<S126>/Constant7'
     *  Constant: '<S126>/Constant8'
     *  Constant: '<S126>/Constant9'
     *  Constant: '<S127>/Constant'
     *  Constant: '<S127>/Constant1'
     *  Constant: '<S127>/Constant2'
     *  Constant: '<S129>/Constant1'
     *  Constant: '<S129>/Constant10'
     *  Constant: '<S129>/Constant2'
     *  Constant: '<S129>/Constant5'
     *  Constant: '<S129>/Constant6'
     *  Constant: '<S129>/Constant7'
     *  Constant: '<S129>/Constant8'
     *  Constant: '<S129>/Constant9'
     *  Constant: '<S132>/Constant'
     *  Constant: '<S132>/Constant1'
     *  Constant: '<S132>/Constant11'
     *  Constant: '<S132>/Constant2'
     *  Constant: '<S132>/Constant3'
     *  Constant: '<S132>/Constant4'
     *  Constant: '<S132>/Constant5'
     *  Constant: '<S132>/Constant6'
     *  Constant: '<S138>/Constant1'
     *  Constant: '<S138>/Constant10'
     *  Constant: '<S138>/Constant2'
     *  Constant: '<S138>/Constant5'
     *  Constant: '<S138>/Constant6'
     *  Constant: '<S138>/Constant7'
     *  Constant: '<S138>/Constant8'
     *  Constant: '<S138>/Constant9'
     *  Constant: '<S139>/Constant1'
     *  Constant: '<S139>/Constant10'
     *  Constant: '<S139>/Constant2'
     *  Constant: '<S139>/Constant5'
     *  Constant: '<S139>/Constant6'
     *  Constant: '<S139>/Constant7'
     *  Constant: '<S139>/Constant8'
     *  Constant: '<S139>/Constant9'
     *  Gain: '<S130>/Gain1'
     *  Gain: '<S137>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S124>/Memory'
     *  Memory: '<S124>/Memory1'
     *  Memory: '<S124>/Memory2'
     *  Memory: '<S124>/Memory3'
     *  Merge: '<S113>/Merge'
     *  Merge: '<S113>/Merge2'
     *  Merge: '<S113>/Merge3'
     *  RelationalOperator: '<S127>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S125>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S126>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S127>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S127>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S125>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S132>/Lookup Table Dynamic'
     *  Sum: '<S123>/Add'
     *  Sum: '<S123>/Subtract'
     *  Sum: '<S123>/Subtract1'
     *  Sum: '<S127>/Add'
     *  Switch: '<S127>/Switch'
     *  Switch: '<S127>/Switch1'
     *  Switch: '<S128>/Switch4'
     *  Switch: '<S128>/Switch5'
     *  Switch: '<S128>/Switch6'
     *  Trigonometry: '<S123>/Tanh'
     *  UnitDelay: '<S127>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S122>/Iterate_Shot_Target' */
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
      /* Switch: '<S128>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S128>/Switch4' incorporates:
         *  Constant: '<S128>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S128>/Switch4' incorporates:
         *  Constant: '<S128>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S128>/Switch2' */

      /* Switch: '<S128>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S128>/Switch6' incorporates:
         *  Constant: '<S128>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S128>/Switch6' incorporates:
         *  Constant: '<S128>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S128>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S128>/Switch5' incorporates:
         *  Constant: '<S128>/Constant8'
         *  Switch: '<S128>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S128>/Switch4' incorporates:
         *  Constant: '<S128>/Constant9'
         *  Switch: '<S128>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S128>/Switch6' incorporates:
       *  Constant: '<S128>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S122>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S124>/While Iterator'
     */
    Iteration_Number = 1U;
    rtb_Merge1 = 0.0;
    rtb_Saturation_h = 0.0;
    rtb_Init_o = 0.0;
    rtb_Button_Spinup_Enable = true;
    rtb_Compare_ik = true;
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_Compare_ik && (Iteration_Number <= 10)) {
      /* Switch: '<S133>/Switch' incorporates:
       *  Memory: '<S124>/Memory1'
       *  Memory: '<S124>/Memory2'
       *  Switch: '<S133>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_DeadZone = rtb_Saturation_h;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_DeadZone = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S133>/Switch' */

      /* Math: '<S131>/Hypot' incorporates:
       *  Sum: '<S131>/Subtract'
       *  Sum: '<S131>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_DeadZone -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S132>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S132>/Lookup Table Dynamic'
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

      /* Sum: '<S134>/Subtract' incorporates:
       *  Memory: '<S124>/Memory3'
       *  Sum: '<S134>/Subtract1'
       */
      rtb_Merge1 = rtb_TOF - rtb_Init_o;

      /* Sum: '<S134>/Add' incorporates:
       *  Gain: '<S134>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S134>/Product'
       *  Sum: '<S134>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S134>/Add1' incorporates:
       *  Gain: '<S134>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S134>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_DeadZone;

      /* Memory: '<S124>/Memory' */
      rtb_Compare_ik = rtb_Button_Spinup_Enable;

      /* Update for Memory: '<S124>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S124>/Memory2' */
      rtb_Saturation_h = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S124>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S124>/Memory' incorporates:
       *  Constant: '<S136>/Constant'
       *  Math: '<S135>/Hypot'
       *  RelationalOperator: '<S136>/Compare'
       *  Sum: '<S135>/Subtract'
       *  Sum: '<S135>/Subtract1'
       */
      rtb_Button_Spinup_Enable = (rt_hypotd_snf
        (Robot_Control_B.RB_Desired_Target_X - rtb_Sin4,
         Robot_Control_B.RB_Desired_Target_Y - rtb_DeadZone) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S122>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S126>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S125>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S127>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S127>/Lookup Table Dynamic1'
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
      /* Merge: '<S113>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S113>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_LookupTableDynamic_b;
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S113>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_nt = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Minus_k_idx_1 = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S113>/Shooter Not Active' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    /* If: '<S113>/If' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S121>/Constant1'
     *  Constant: '<S121>/Constant2'
     *  Merge: '<S113>/Merge'
     *  Merge: '<S113>/Merge1'
     *  Merge: '<S113>/Merge2'
     *  Merge: '<S113>/Merge3'
     *  SignalConversion generated from: '<S121>/Desired_Gyro_Angle'
     *  UnitDelay: '<S113>/Unit Delay'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot =
      Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S113>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_nt = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S350>/Add1' incorporates:
   *  Constant: '<S350>/Constant3'
   *  Constant: '<S350>/Constant4'
   *  Math: '<S350>/Math Function'
   *  Sum: '<S349>/Sum'
   *  Sum: '<S350>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_nt - rtb_Minus_k_idx_1) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S352>/Sum1' incorporates:
   *  Constant: '<S349>/Constant2'
   *  Product: '<S352>/Product'
   *  Sum: '<S352>/Sum'
   *  UnitDelay: '<S352>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Optimized_Module_Angle_p -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S349>/Product' incorporates:
   *  Constant: '<S349>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S351>/Diff' incorporates:
   *  UnitDelay: '<S351>/UD'
   *
   * Block description for '<S351>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S351>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S349>/Saturation' */
  if (rtb_Add_nt > Steering_Heading_Control_D_UL) {
    rtb_Add_nt = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Heading_Control_D_LL) {
    rtb_Add_nt = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S349>/Add' incorporates:
   *  Gain: '<S349>/Gain1'
   *  Saturate: '<S349>/Saturation'
   */
  rtb_Init_o = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_nt;

  /* Sum: '<S349>/Subtract' incorporates:
   *  Constant: '<S349>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Init_o;

  /* Sum: '<S349>/Sum2' incorporates:
   *  Gain: '<S349>/Gain2'
   *  UnitDelay: '<S349>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p)
    + Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S353>/Switch2' incorporates:
   *  RelationalOperator: '<S353>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Sin4)) {
    /* Sum: '<S349>/Subtract1' incorporates:
     *  Constant: '<S349>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Init_o;

    /* Switch: '<S353>/Switch' incorporates:
     *  RelationalOperator: '<S353>/UpperRelop'
     */
    if (!(rtb_Saturation_h < rtb_Sin4)) {
      rtb_Sin4 = rtb_Saturation_h;
    }

    /* End of Switch: '<S353>/Switch' */
  }

  /* End of Switch: '<S353>/Switch2' */

  /* Saturate: '<S349>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Saturation_h = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Saturation_h = Steering_Heading_Control_I_LL;
  } else {
    rtb_Saturation_h = rtb_Sin4;
  }

  /* End of Saturate: '<S349>/Saturation1' */

  /* Sum: '<S349>/Add1' */
  rtb_Add_nt = rtb_Init_o + rtb_Saturation_h;

  /* Saturate: '<S349>/Saturation2' */
  if (rtb_Add_nt > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S349>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_nt < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S349>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S349>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_nt;
  }

  /* End of Saturate: '<S349>/Saturation2' */

  /* Switch: '<S333>/Switch' incorporates:
   *  Abs: '<S333>/Abs'
   *  Constant: '<S333>/Constant'
   *  Constant: '<S348>/Constant'
   *  RelationalOperator: '<S348>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Optimized_Module_Angle_p = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Optimized_Module_Angle_p = 0.0;
  }

  /* End of Switch: '<S333>/Switch' */

  /* Signum: '<S332>/Sign2' incorporates:
   *  UnitDelay: '<S332>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_nt = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S332>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S332>/Product1' incorporates:
   *  Signum: '<S332>/Sign1'
   *  Signum: '<S332>/Sign2'
   */
  rtb_Add_nt *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_nt)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_nt, 256.0);
  }

  /* Switch: '<S332>/Switch' incorporates:
   *  Constant: '<S332>/Constant'
   *  Constant: '<S341>/Constant'
   *  Constant: '<S342>/Constant'
   *  Logic: '<S332>/or'
   *  Product: '<S332>/Product1'
   *  RelationalOperator: '<S341>/Compare'
   *  RelationalOperator: '<S342>/Compare'
   *  UnitDelay: '<S332>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_nf = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_nf = 0.0;
  }

  /* End of Switch: '<S332>/Switch' */

  /* Switch: '<S347>/Init' incorporates:
   *  UnitDelay: '<S347>/FixPt Unit Delay1'
   *  UnitDelay: '<S347>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Switch2_nf;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S347>/Init' */

  /* RelationalOperator: '<S343>/Compare' incorporates:
   *  Constant: '<S343>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Switch2_nf == 0.0);

  /* RelationalOperator: '<S344>/Compare' incorporates:
   *  Constant: '<S344>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Switch2_nf > 0.0);

  /* Abs: '<S332>/Abs' incorporates:
   *  Sum: '<S332>/Subtract'
   *  UnitDelay: '<S332>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S332>/Switch5' incorporates:
   *  Constant: '<S332>/Constant1'
   *  Switch: '<S332>/Switch1'
   *  UnaryMinus: '<S332>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    /* SignalConversion generated from: '<S332>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S332>/Constant4'
     *  Constant: '<S332>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S332>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S332>/Constant2'
     *  Constant: '<S332>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S332>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S332>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S332>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S332>/Constant10'
     *  Constant: '<S332>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S332>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S332>/Constant7'
     *  Constant: '<S332>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S332>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S332>/Lookup Table Dynamic1'
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

    /* Switch: '<S332>/Switch3' incorporates:
     *  Constant: '<S332>/Constant1'
     *  Constant: '<S332>/Constant3'
     *  UnaryMinus: '<S332>/Unary Minus'
     */
    if (rtb_Button_Shoot_Enable) {
      rtb_Add_nt = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_nt = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S332>/Switch3' */
  }

  /* End of Switch: '<S332>/Switch5' */

  /* Product: '<S332>/Product' incorporates:
   *  Switch: '<S332>/Switch1'
   */
  rtb_Init = rtb_Add_nt * rtb_Sin4;

  /* Sum: '<S345>/Sum1' */
  rtb_DeadZone = rtb_Switch2_nf - rtb_Init_o;

  /* Switch: '<S346>/Switch2' incorporates:
   *  RelationalOperator: '<S346>/LowerRelop1'
   */
  if (!(rtb_DeadZone > rtb_Init)) {
    /* Switch: '<S332>/Switch2' incorporates:
     *  Constant: '<S332>/Constant1'
     *  Constant: '<S332>/Constant3'
     *  Switch: '<S332>/Switch4'
     *  UnaryMinus: '<S332>/Unary Minus1'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Add_nt = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S332>/Switch4' incorporates:
       *  Constant: '<S332>/Constant1'
       */
      rtb_Add_nt = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_nt = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S332>/Product2' incorporates:
     *  Switch: '<S332>/Switch2'
     */
    rtb_Switch1 = rtb_Add_nt * rtb_Sin4;

    /* Switch: '<S346>/Switch' incorporates:
     *  RelationalOperator: '<S346>/UpperRelop'
     */
    if (rtb_DeadZone < rtb_Switch1) {
      rtb_Init = rtb_Switch1;
    } else {
      rtb_Init = rtb_DeadZone;
    }

    /* End of Switch: '<S346>/Switch' */
  }

  /* End of Switch: '<S346>/Switch2' */

  /* Sum: '<S345>/Sum' */
  rtb_Init_o += rtb_Init;

  /* Signum: '<S331>/Sign2' incorporates:
   *  UnitDelay: '<S331>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_nt = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S331>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S331>/Product1' incorporates:
   *  Signum: '<S331>/Sign1'
   *  Signum: '<S331>/Sign2'
   */
  rtb_Add_nt *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_nt)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_nt, 256.0);
  }

  /* Switch: '<S331>/Switch' incorporates:
   *  Constant: '<S331>/Constant'
   *  Constant: '<S334>/Constant'
   *  Constant: '<S335>/Constant'
   *  Logic: '<S331>/or'
   *  Product: '<S331>/Product1'
   *  RelationalOperator: '<S334>/Compare'
   *  RelationalOperator: '<S335>/Compare'
   *  UnitDelay: '<S331>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_nf = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_nf = 0.0;
  }

  /* End of Switch: '<S331>/Switch' */

  /* Switch: '<S340>/Init' incorporates:
   *  UnitDelay: '<S340>/FixPt Unit Delay1'
   *  UnitDelay: '<S340>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_nf;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S340>/Init' */

  /* RelationalOperator: '<S336>/Compare' incorporates:
   *  Constant: '<S336>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Switch2_nf == 0.0);

  /* RelationalOperator: '<S337>/Compare' incorporates:
   *  Constant: '<S337>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Switch2_nf > 0.0);

  /* Abs: '<S331>/Abs' incorporates:
   *  Sum: '<S331>/Subtract'
   *  UnitDelay: '<S331>/Unit Delay'
   */
  rtb_DeadZone = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                      Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S331>/Switch1' incorporates:
   *  Constant: '<S331>/Constant1'
   *  Switch: '<S331>/Switch3'
   *  Switch: '<S331>/Switch5'
   *  UnaryMinus: '<S331>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S331>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S331>/Constant1'
     *  Constant: '<S331>/Constant4'
     *  Constant: '<S331>/Constant6'
     *  UnaryMinus: '<S331>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S331>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S331>/Constant2'
     *  Constant: '<S331>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S331>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S331>/Lookup Table Dynamic'
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
      /* Switch: '<S331>/Switch3' incorporates:
       *  Constant: '<S331>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S331>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S331>/Constant1'
     *  Constant: '<S331>/Constant10'
     *  Constant: '<S331>/Constant8'
     *  UnaryMinus: '<S331>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S331>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S331>/Constant7'
     *  Constant: '<S331>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S331>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S331>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S331>/Switch1' */

  /* Product: '<S331>/Product' */
  rtb_Sin4 *= rtb_DeadZone;

  /* Sum: '<S338>/Sum1' */
  rtb_Switch1 = rtb_Switch2_nf - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S339>/Switch2' incorporates:
   *  RelationalOperator: '<S339>/LowerRelop1'
   */
  if (!(rtb_Switch1 > rtb_Sin4)) {
    /* Switch: '<S331>/Switch2' incorporates:
     *  Constant: '<S331>/Constant1'
     *  Switch: '<S331>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S331>/Switch4' incorporates:
       *  Constant: '<S331>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S331>/Switch4' incorporates:
       *  Constant: '<S331>/Constant3'
       *  UnaryMinus: '<S331>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S331>/Switch2' */

    /* Product: '<S331>/Product2' */
    rtb_Sin4 *= rtb_DeadZone;

    /* Switch: '<S339>/Switch' incorporates:
     *  RelationalOperator: '<S339>/UpperRelop'
     */
    if (!(rtb_Switch1 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1;
    }

    /* End of Switch: '<S339>/Switch' */
  }

  /* End of Switch: '<S339>/Switch2' */

  /* Sum: '<S338>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S321>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S321>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S321>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S321>/Switch' */

  /* Fcn: '<S362>/r->x' incorporates:
   *  Fcn: '<S367>/r->x'
   *  Fcn: '<S372>/r->x'
   *  Fcn: '<S377>/r->x'
   */
  rtb_Switch1 = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S356>/Add' incorporates:
   *  Fcn: '<S362>/r->x'
   *  Fcn: '<S363>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1;

  /* Fcn: '<S362>/theta->y' incorporates:
   *  Fcn: '<S367>/theta->y'
   *  Fcn: '<S372>/theta->y'
   *  Fcn: '<S377>/theta->y'
   */
  rtb_DeadZone = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S356>/Add' incorporates:
   *  Fcn: '<S362>/theta->y'
   *  Fcn: '<S363>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S357>/Add' incorporates:
   *  Fcn: '<S368>/r->x'
   *  Fcn: '<S368>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S358>/Add' incorporates:
   *  Fcn: '<S373>/r->x'
   *  Fcn: '<S373>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S359>/Add' incorporates:
   *  Fcn: '<S378>/r->x'
   *  Fcn: '<S378>/theta->y'
   */
  rtb_Switch2_p2 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_DeadZone;

  /* Fcn: '<S376>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Switch2_p2, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S379>/Compare' incorporates:
   *  Constant: '<S379>/Constant'
   */
  rtb_Compare_ik = (rtb_Init == 0.0);

  /* Switch: '<S375>/Switch1' */
  if (rtb_Compare_ik) {
    /* Switch: '<S375>/Switch1' incorporates:
     *  Constant: '<S375>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S375>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S375>/Switch1' */

  /* Fcn: '<S361>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S364>/Compare' incorporates:
   *  Constant: '<S364>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Init == 0.0);

  /* Switch: '<S360>/Switch1' */
  if (rtb_Button_Spinup_Enable) {
    /* Switch: '<S360>/Switch1' incorporates:
     *  Constant: '<S360>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S360>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S360>/Switch1' */

  /* Fcn: '<S366>/x->r' */
  rtb_Switch2_nf = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S369>/Compare' incorporates:
   *  Constant: '<S369>/Constant'
   */
  rtb_AND1_c = (rtb_Switch2_nf == 0.0);

  /* Switch: '<S365>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S365>/Switch1' incorporates:
     *  Constant: '<S365>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S365>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_nf;
  }

  /* End of Switch: '<S365>/Switch1' */

  /* Fcn: '<S371>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S374>/Compare' incorporates:
   *  Constant: '<S374>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S370>/Switch1' */
  if (rtb_Button_Shoot_Enable) {
    /* Switch: '<S370>/Switch1' incorporates:
     *  Constant: '<S370>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S370>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S370>/Switch1' */

  /* Product: '<S355>/Divide' incorporates:
   *  Abs: '<S355>/Abs'
   *  Abs: '<S355>/Abs1'
   *  Abs: '<S355>/Abs2'
   *  Abs: '<S355>/Abs3'
   *  Constant: '<S355>/Constant'
   *  MinMax: '<S355>/Max'
   */
  rtb_Init = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S355>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S375>/Switch' */
  if (!rtb_Compare_ik) {
    /* Switch: '<S375>/Switch' incorporates:
     *  Fcn: '<S376>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Switch2_p2);
  }

  /* End of Switch: '<S375>/Switch' */

  /* Trigonometry: '<S311>/Cos4' incorporates:
   *  Switch: '<S300>/Angle_Switch'
   *  Trigonometry: '<S310>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S311>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S309>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S311>/Sin4' incorporates:
   *  Switch: '<S300>/Angle_Switch'
   *  Trigonometry: '<S310>/Sin4'
   */
  rtb_DeadZone = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S311>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S309>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S311>/Subtract1' incorporates:
   *  Product: '<S311>/Product2'
   *  Product: '<S311>/Product3'
   *  Trigonometry: '<S311>/Cos4'
   *  Trigonometry: '<S311>/Sin4'
   */
  rtb_Switch1 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) + (rtb_DeadZone
    * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S311>/Subtract' incorporates:
   *  Product: '<S311>/Product'
   *  Product: '<S311>/Product1'
   *  Trigonometry: '<S311>/Cos4'
   *  Trigonometry: '<S311>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_DeadZone * rtb_Optimized_Module_Angle);

  /* Math: '<S311>/Hypot' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

  /* Switch: '<S311>/Switch' incorporates:
   *  Constant: '<S311>/Constant'
   *  Constant: '<S311>/Constant1'
   *  Constant: '<S312>/Constant'
   *  Product: '<S311>/Divide'
   *  Product: '<S311>/Divide1'
   *  RelationalOperator: '<S312>/Compare'
   *  Switch: '<S311>/Switch1'
   */
  if (rtb_Switch2_p2 > 1.0E-6) {
    rtb_Switch2_nf = rtb_Switch1 / rtb_Switch2_p2;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Switch2_p2;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S311>/Switch' */

  /* Switch: '<S300>/Speed_Switch' incorporates:
   *  Abs: '<S300>/Abs'
   *  Constant: '<S308>/Constant'
   *  RelationalOperator: '<S308>/Compare'
   *  Switch: '<S300>/Angle_Switch'
   *  Trigonometry: '<S310>/Atan1'
   *  Trigonometry: '<S311>/Atan1'
   *  UnaryMinus: '<S300>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_nt = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S310>/Subtract1' incorporates:
     *  Product: '<S310>/Product2'
     *  Product: '<S310>/Product3'
     *  UnaryMinus: '<S300>/Unary Minus'
     */
    rtb_Switch1 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_DeadZone * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S310>/Subtract' incorporates:
     *  Product: '<S310>/Product'
     *  Product: '<S310>/Product1'
     */
    rtb_Switch2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_DeadZone * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S310>/Hypot' */
    rtb_DeadZone = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

    /* Switch: '<S310>/Switch1' incorporates:
     *  Constant: '<S310>/Constant'
     *  Constant: '<S310>/Constant1'
     *  Constant: '<S313>/Constant'
     *  Product: '<S310>/Divide'
     *  Product: '<S310>/Divide1'
     *  RelationalOperator: '<S313>/Compare'
     *  Switch: '<S310>/Switch'
     */
    if (rtb_DeadZone > 1.0E-6) {
      rtb_Switch2 /= rtb_DeadZone;
      rtb_DeadZone = rtb_Switch1 / rtb_DeadZone;
    } else {
      rtb_Switch2 = 1.0;
      rtb_DeadZone = 0.0;
    }

    /* End of Switch: '<S310>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_DeadZone, rtb_Switch2);
  } else {
    rtb_Add_nt = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S303>/Product2' incorporates:
   *  Constant: '<S303>/Constant'
   *  Switch: '<S300>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_nt * 1154.7574092481445;

  /* Signum: '<S298>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_nt = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S298>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S301>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S302>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S233>/Product' incorporates:
   *  Abs: '<S298>/Abs'
   *  Abs: '<S301>/Abs'
   *  Constant: '<S304>/Constant'
   *  Constant: '<S314>/Constant3'
   *  Constant: '<S314>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S298>/OR'
   *  Lookup_n-D: '<S301>/1-D Lookup Table'
   *  Math: '<S314>/Math Function'
   *  RelationalOperator: '<S298>/Equal1'
   *  RelationalOperator: '<S304>/Compare'
   *  Signum: '<S298>/Sign'
   *  Signum: '<S298>/Sign1'
   *  Sum: '<S301>/Add'
   *  Sum: '<S314>/Add1'
   *  Sum: '<S314>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_nt == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S299>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2 = rtb_Switch2_nf - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S306>/Sum1' incorporates:
   *  Constant: '<S299>/Constant2'
   *  Product: '<S306>/Product'
   *  Sum: '<S306>/Sum'
   *  UnitDelay: '<S306>/Unit Delay1'
   */
  rtb_DeadZone = ((rtb_Switch2 - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S299>/Product' incorporates:
   *  Constant: '<S299>/Constant3'
   */
  rtb_Switch1 = rtb_DeadZone * Drive_Motor_Control_D;

  /* Sum: '<S305>/Diff' incorporates:
   *  UnitDelay: '<S305>/UD'
   *
   * Block description for '<S305>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S305>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Switch1 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S299>/Saturation' */
  if (rtb_Add_nt > Drive_Motor_Control_D_UL) {
    rtb_Add_nt = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Drive_Motor_Control_D_LL) {
    rtb_Add_nt = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S299>/Add' incorporates:
   *  Gain: '<S299>/Gain'
   *  Gain: '<S299>/Gain1'
   *  Saturate: '<S299>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
                    (Drive_Motor_Control_P * rtb_Switch2)) + rtb_Add_nt;

  /* Saturate: '<S299>/Saturation2' incorporates:
   *  Sum: '<S299>/Add1'
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

  /* End of Saturate: '<S299>/Saturation2' */

  /* Switch: '<S360>/Switch' */
  if (!rtb_Button_Spinup_Enable) {
    /* Switch: '<S360>/Switch' incorporates:
     *  Fcn: '<S361>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S360>/Switch' */

  /* Trigonometry: '<S248>/Cos4' incorporates:
   *  Switch: '<S237>/Angle_Switch'
   *  Trigonometry: '<S247>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S248>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S246>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S248>/Sin4' incorporates:
   *  Switch: '<S237>/Angle_Switch'
   *  Trigonometry: '<S247>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S248>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S246>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S248>/Subtract1' incorporates:
   *  Product: '<S248>/Product2'
   *  Product: '<S248>/Product3'
   *  Trigonometry: '<S248>/Cos4'
   *  Trigonometry: '<S248>/Sin4'
   */
  rtb_Switch2_p2 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S248>/Subtract' incorporates:
   *  Product: '<S248>/Product'
   *  Product: '<S248>/Product1'
   *  Trigonometry: '<S248>/Cos4'
   *  Trigonometry: '<S248>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S248>/Hypot' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Switch2, rtb_Switch2_p2);

  /* Switch: '<S248>/Switch' incorporates:
   *  Constant: '<S248>/Constant'
   *  Constant: '<S248>/Constant1'
   *  Constant: '<S249>/Constant'
   *  Product: '<S248>/Divide'
   *  Product: '<S248>/Divide1'
   *  RelationalOperator: '<S249>/Compare'
   *  Switch: '<S248>/Switch1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
    rtb_Switch2_nf = rtb_Switch2_p2 / rtb_MatrixConcatenate_b_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S248>/Switch' */

  /* Product: '<S355>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S237>/Speed_Switch' incorporates:
   *  Abs: '<S237>/Abs'
   *  Constant: '<S245>/Constant'
   *  RelationalOperator: '<S245>/Compare'
   *  Switch: '<S237>/Angle_Switch'
   *  Trigonometry: '<S247>/Atan1'
   *  Trigonometry: '<S248>/Atan1'
   *  UnaryMinus: '<S237>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_nt = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S247>/Subtract1' incorporates:
     *  Product: '<S247>/Product2'
     *  Product: '<S247>/Product3'
     *  UnaryMinus: '<S237>/Unary Minus'
     */
    rtb_Switch2_p2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S247>/Subtract' incorporates:
     *  Product: '<S247>/Product'
     *  Product: '<S247>/Product1'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Cos5) - (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Sin5);

    /* Math: '<S247>/Hypot' */
    rtb_Switch2 = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Switch2_p2);

    /* Switch: '<S247>/Switch1' incorporates:
     *  Constant: '<S247>/Constant'
     *  Constant: '<S247>/Constant1'
     *  Constant: '<S250>/Constant'
     *  Product: '<S247>/Divide'
     *  Product: '<S247>/Divide1'
     *  RelationalOperator: '<S250>/Compare'
     *  Switch: '<S247>/Switch'
     */
    if (rtb_Switch2 > 1.0E-6) {
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Switch2;
      rtb_Switch2_p2 /= rtb_Switch2;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = 1.0;
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S247>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Switch2_p2,
      rtb_MatrixConcatenate_b_idx_0);
  } else {
    rtb_Add_nt = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S240>/Product2' incorporates:
   *  Constant: '<S240>/Constant'
   *  Switch: '<S237>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_nt * 1154.7574092481445;

  /* Signum: '<S235>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_nt = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S235>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S238>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S239>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S230>/Product' incorporates:
   *  Abs: '<S235>/Abs'
   *  Abs: '<S238>/Abs'
   *  Constant: '<S241>/Constant'
   *  Constant: '<S251>/Constant3'
   *  Constant: '<S251>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S235>/OR'
   *  Lookup_n-D: '<S238>/1-D Lookup Table'
   *  Math: '<S251>/Math Function'
   *  RelationalOperator: '<S235>/Equal1'
   *  RelationalOperator: '<S241>/Compare'
   *  Signum: '<S235>/Sign'
   *  Signum: '<S235>/Sign1'
   *  Sum: '<S238>/Add'
   *  Sum: '<S251>/Add1'
   *  Sum: '<S251>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_nt == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j,
                  1U);

  /* Sum: '<S236>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_nf -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S243>/Sum1' incorporates:
   *  Constant: '<S236>/Constant2'
   *  Product: '<S243>/Product'
   *  Sum: '<S243>/Sum'
   *  UnitDelay: '<S243>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_MatrixConcatenate_b_idx_0 -
                     Robot_Control_DW.UnitDelay1_DSTATE_f) *
                    Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S236>/Product' incorporates:
   *  Constant: '<S236>/Constant3'
   */
  rtb_Switch2 = rtb_Switch2_p2 * Drive_Motor_Control_D;

  /* Sum: '<S242>/Diff' incorporates:
   *  UnitDelay: '<S242>/UD'
   *
   * Block description for '<S242>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S242>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S236>/Saturation' */
  if (rtb_Add_nt > Drive_Motor_Control_D_UL) {
    rtb_Add_nt = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Drive_Motor_Control_D_LL) {
    rtb_Add_nt = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S236>/Add' incorporates:
   *  Gain: '<S236>/Gain'
   *  Gain: '<S236>/Gain1'
   *  Saturate: '<S236>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
    (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_nt;

  /* Saturate: '<S236>/Saturation2' incorporates:
   *  Sum: '<S236>/Add1'
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

  /* End of Saturate: '<S236>/Saturation2' */

  /* Sum: '<S252>/Add1' incorporates:
   *  Constant: '<S252>/Constant3'
   *  Constant: '<S252>/Constant4'
   *  Math: '<S252>/Math Function'
   *  Sum: '<S252>/Add2'
   */
  rtb_Switch2_nf = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S254>/Sum1' incorporates:
   *  Constant: '<S239>/Constant2'
   *  Product: '<S254>/Product'
   *  Sum: '<S254>/Sum'
   *  UnitDelay: '<S254>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((rtb_Switch2_nf -
    Robot_Control_DW.UnitDelay1_DSTATE_b) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S239>/Product' incorporates:
   *  Constant: '<S239>/Constant3'
   */
  rtb_Switch2_ow = rtb_MatrixConcatenate_b_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S253>/Diff' incorporates:
   *  UnitDelay: '<S253>/UD'
   *
   * Block description for '<S253>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S253>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Switch2_ow - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S239>/Saturation' */
  if (rtb_Add_nt > Steering_Motor_Control_D_UL) {
    rtb_Add_nt = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Motor_Control_D_LL) {
    rtb_Add_nt = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S239>/Add' incorporates:
   *  Gain: '<S239>/Gain1'
   *  Saturate: '<S239>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P * rtb_Switch2_nf) +
    rtb_Add_nt;

  /* Sum: '<S239>/Subtract' incorporates:
   *  Constant: '<S239>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S239>/Sum2' incorporates:
   *  Gain: '<S239>/Gain2'
   *  UnitDelay: '<S239>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Switch2_nf) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S255>/Switch2' incorporates:
   *  Constant: '<S239>/Constant'
   *  RelationalOperator: '<S255>/LowerRelop1'
   *  Sum: '<S239>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S255>/Switch' incorporates:
     *  Constant: '<S239>/Constant1'
     *  RelationalOperator: '<S255>/UpperRelop'
     *  Sum: '<S239>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S255>/Switch' */
  }

  /* End of Switch: '<S255>/Switch2' */

  /* Saturate: '<S239>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S239>/Saturation1' */

  /* Sum: '<S239>/Add1' */
  rtb_Add_nt = rtb_MatrixConcatenate_idx_0 + rtb_Sum2_e;

  /* Saturate: '<S239>/Saturation2' */
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

  /* End of Saturate: '<S239>/Saturation2' */

  /* Switch: '<S365>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S365>/Switch' incorporates:
     *  Fcn: '<S366>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S365>/Switch' */

  /* Trigonometry: '<S269>/Cos4' incorporates:
   *  Switch: '<S258>/Angle_Switch'
   *  Trigonometry: '<S268>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S269>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S267>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S269>/Sin4' incorporates:
   *  Switch: '<S258>/Angle_Switch'
   *  Trigonometry: '<S268>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S269>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S267>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S269>/Subtract1' incorporates:
   *  Product: '<S269>/Product2'
   *  Product: '<S269>/Product3'
   *  Trigonometry: '<S269>/Cos4'
   *  Trigonometry: '<S269>/Sin4'
   */
  rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S269>/Subtract' incorporates:
   *  Product: '<S269>/Product'
   *  Product: '<S269>/Product1'
   *  Trigonometry: '<S269>/Cos4'
   *  Trigonometry: '<S269>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S269>/Hypot' */
  rtb_Hypot_bl = rt_hypotd_snf(rtb_Subtract1_la, rtb_MatrixConcatenate_idx_0);

  /* Switch: '<S269>/Switch' incorporates:
   *  Constant: '<S269>/Constant'
   *  Constant: '<S269>/Constant1'
   *  Constant: '<S270>/Constant'
   *  Product: '<S269>/Divide'
   *  Product: '<S269>/Divide1'
   *  RelationalOperator: '<S270>/Compare'
   *  Switch: '<S269>/Switch1'
   */
  if (rtb_Hypot_bl > 1.0E-6) {
    rtb_Switch2_nf = rtb_MatrixConcatenate_idx_0 / rtb_Hypot_bl;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_bl;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S269>/Switch' */

  /* Product: '<S355>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S258>/Speed_Switch' incorporates:
   *  Abs: '<S258>/Abs'
   *  Constant: '<S266>/Constant'
   *  RelationalOperator: '<S266>/Compare'
   *  Switch: '<S258>/Angle_Switch'
   *  Trigonometry: '<S268>/Atan1'
   *  Trigonometry: '<S269>/Atan1'
   *  UnaryMinus: '<S258>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_nt = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S268>/Subtract1' incorporates:
     *  Product: '<S268>/Product2'
     *  Product: '<S268>/Product3'
     *  UnaryMinus: '<S258>/Unary Minus'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_m) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S268>/Subtract' incorporates:
     *  Product: '<S268>/Product'
     *  Product: '<S268>/Product1'
     */
    rtb_Hypot_bl = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S268>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_bl, rtb_MatrixConcatenate_idx_0);

    /* Switch: '<S268>/Switch1' incorporates:
     *  Constant: '<S268>/Constant'
     *  Constant: '<S268>/Constant1'
     *  Constant: '<S271>/Constant'
     *  Product: '<S268>/Divide'
     *  Product: '<S268>/Divide1'
     *  RelationalOperator: '<S271>/Compare'
     *  Switch: '<S268>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_bl /= rtb_Subtract1_la;
      rtb_MatrixConcatenate_idx_0 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_bl = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S268>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0, rtb_Hypot_bl);
  } else {
    rtb_Add_nt = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S261>/Product2' incorporates:
   *  Constant: '<S261>/Constant'
   *  Switch: '<S258>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_nt * 1154.7574092481445;

  /* Signum: '<S256>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_nt = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S256>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S259>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S260>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S231>/Product' incorporates:
   *  Abs: '<S256>/Abs'
   *  Abs: '<S259>/Abs'
   *  Constant: '<S262>/Constant'
   *  Constant: '<S272>/Constant3'
   *  Constant: '<S272>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S256>/OR'
   *  Lookup_n-D: '<S259>/1-D Lookup Table'
   *  Math: '<S272>/Math Function'
   *  RelationalOperator: '<S256>/Equal1'
   *  RelationalOperator: '<S262>/Compare'
   *  Signum: '<S256>/Sign'
   *  Signum: '<S256>/Sign1'
   *  Sum: '<S259>/Add'
   *  Sum: '<S272>/Add1'
   *  Sum: '<S272>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_nt == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_gs,
                  1U);

  /* Sum: '<S257>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_bl = rtb_Switch2_nf - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S264>/Sum1' incorporates:
   *  Constant: '<S257>/Constant2'
   *  Product: '<S264>/Product'
   *  Sum: '<S264>/Sum'
   *  UnitDelay: '<S264>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Hypot_bl -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S257>/Product' incorporates:
   *  Constant: '<S257>/Constant3'
   */
  rtb_Subtract1_la = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S263>/Diff' incorporates:
   *  UnitDelay: '<S263>/UD'
   *
   * Block description for '<S263>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S263>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S257>/Saturation' */
  if (rtb_Add_nt > Drive_Motor_Control_D_UL) {
    rtb_Add_nt = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Drive_Motor_Control_D_LL) {
    rtb_Add_nt = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S257>/Add' incorporates:
   *  Gain: '<S257>/Gain'
   *  Gain: '<S257>/Gain1'
   *  Saturate: '<S257>/Saturation'
   */
  rtb_Hypot_bl = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
                  (Drive_Motor_Control_P * rtb_Hypot_bl)) + rtb_Add_nt;

  /* Saturate: '<S257>/Saturation2' incorporates:
   *  Sum: '<S257>/Add1'
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

  /* End of Saturate: '<S257>/Saturation2' */

  /* Sum: '<S273>/Add1' incorporates:
   *  Constant: '<S273>/Constant3'
   *  Constant: '<S273>/Constant4'
   *  Math: '<S273>/Math Function'
   *  Sum: '<S273>/Add2'
   */
  rtb_Switch2_nf = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S275>/Sum1' incorporates:
   *  Constant: '<S260>/Constant2'
   *  Product: '<S275>/Product'
   *  Sum: '<S275>/Sum'
   *  UnitDelay: '<S275>/Unit Delay1'
   */
  rtb_Hypot_bl = ((rtb_Switch2_nf - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S260>/Product' incorporates:
   *  Constant: '<S260>/Constant3'
   */
  rtb_Switch2_cw = rtb_Hypot_bl * Steering_Motor_Control_D;

  /* Sum: '<S274>/Diff' incorporates:
   *  UnitDelay: '<S274>/UD'
   *
   * Block description for '<S274>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S274>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Switch2_cw - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S260>/Saturation' */
  if (rtb_Add_nt > Steering_Motor_Control_D_UL) {
    rtb_Add_nt = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Motor_Control_D_LL) {
    rtb_Add_nt = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S260>/Add' incorporates:
   *  Gain: '<S260>/Gain1'
   *  Saturate: '<S260>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_nf) + rtb_Add_nt;

  /* Sum: '<S260>/Subtract' incorporates:
   *  Constant: '<S260>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S260>/Sum2' incorporates:
   *  Gain: '<S260>/Gain2'
   *  UnitDelay: '<S260>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_Switch2_nf) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S276>/Switch2' incorporates:
   *  Constant: '<S260>/Constant'
   *  RelationalOperator: '<S276>/LowerRelop1'
   *  Sum: '<S260>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S276>/Switch' incorporates:
     *  Constant: '<S260>/Constant1'
     *  RelationalOperator: '<S276>/UpperRelop'
     *  Sum: '<S260>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S276>/Switch' */
  }

  /* End of Switch: '<S276>/Switch2' */

  /* Saturate: '<S260>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S260>/Saturation1' */

  /* Sum: '<S260>/Add1' */
  rtb_Add_nt = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S260>/Saturation2' */
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

  /* End of Saturate: '<S260>/Saturation2' */

  /* Switch: '<S370>/Switch' */
  if (!rtb_Button_Shoot_Enable) {
    /* Switch: '<S370>/Switch' incorporates:
     *  Fcn: '<S371>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S370>/Switch' */

  /* Trigonometry: '<S290>/Cos4' incorporates:
   *  Switch: '<S279>/Angle_Switch'
   *  Trigonometry: '<S289>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S290>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S288>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S290>/Sin4' incorporates:
   *  Switch: '<S279>/Angle_Switch'
   *  Trigonometry: '<S289>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S290>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S288>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S290>/Subtract1' incorporates:
   *  Product: '<S290>/Product2'
   *  Product: '<S290>/Product3'
   *  Trigonometry: '<S290>/Cos4'
   *  Trigonometry: '<S290>/Sin4'
   */
  rtb_Switch2_nf = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S290>/Subtract' incorporates:
   *  Product: '<S290>/Product'
   *  Product: '<S290>/Product1'
   *  Trigonometry: '<S290>/Cos4'
   *  Trigonometry: '<S290>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S290>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_nf);

  /* Switch: '<S290>/Switch' incorporates:
   *  Constant: '<S290>/Constant'
   *  Constant: '<S290>/Constant1'
   *  Constant: '<S291>/Constant'
   *  Product: '<S290>/Divide'
   *  Product: '<S290>/Divide1'
   *  RelationalOperator: '<S291>/Compare'
   *  Switch: '<S290>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Switch2_nf /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S290>/Switch' */

  /* Product: '<S355>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S279>/Speed_Switch' incorporates:
   *  Abs: '<S279>/Abs'
   *  Constant: '<S287>/Constant'
   *  RelationalOperator: '<S287>/Compare'
   *  Switch: '<S279>/Angle_Switch'
   *  Trigonometry: '<S289>/Atan1'
   *  Trigonometry: '<S290>/Atan1'
   *  UnaryMinus: '<S279>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_nt = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S289>/Subtract1' incorporates:
     *  Product: '<S289>/Product2'
     *  Product: '<S289>/Product3'
     *  UnaryMinus: '<S279>/Unary Minus'
     */
    rtb_Switch2_nf = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S289>/Subtract' incorporates:
     *  Product: '<S289>/Product'
     *  Product: '<S289>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S289>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_nf);

    /* Switch: '<S289>/Switch1' incorporates:
     *  Constant: '<S289>/Constant'
     *  Constant: '<S289>/Constant1'
     *  Constant: '<S292>/Constant'
     *  Product: '<S289>/Divide'
     *  Product: '<S289>/Divide1'
     *  RelationalOperator: '<S292>/Compare'
     *  Switch: '<S289>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_Switch2_nf /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Switch2_nf = 0.0;
    }

    /* End of Switch: '<S289>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Switch2_nf,
      rtb_uDLookupTable);
  } else {
    rtb_Add_nt = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S282>/Product2' incorporates:
   *  Constant: '<S282>/Constant'
   *  Switch: '<S279>/Speed_Switch'
   */
  rtb_Init = rtb_Add_nt * 1154.7574092481445;

  /* Signum: '<S277>/Sign' */
  if (rtIsNaN(rtb_Init)) {
    rtb_Add_nt = (rtNaN);
  } else if (rtb_Init < 0.0) {
    rtb_Add_nt = -1.0;
  } else {
    rtb_Add_nt = (rtb_Init > 0.0);
  }

  /* Signum: '<S277>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S280>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S281>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S232>/Product' incorporates:
   *  Abs: '<S277>/Abs'
   *  Abs: '<S280>/Abs'
   *  Constant: '<S283>/Constant'
   *  Constant: '<S293>/Constant3'
   *  Constant: '<S293>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S277>/OR'
   *  Lookup_n-D: '<S280>/1-D Lookup Table'
   *  Math: '<S293>/Math Function'
   *  RelationalOperator: '<S277>/Equal1'
   *  RelationalOperator: '<S283>/Compare'
   *  Signum: '<S277>/Sign'
   *  Signum: '<S277>/Sign1'
   *  Sum: '<S280>/Add'
   *  Sum: '<S293>/Add1'
   *  Sum: '<S293>/Add2'
   */
  rtb_Init = (((real_T)((rtb_Add_nt == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init) * look1_binlcpw(fabs
    (rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                 3.1415926535897931) - 1.5707963267948966),
    rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S278>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_nf = rtb_Init - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S285>/Sum1' incorporates:
   *  Constant: '<S278>/Constant2'
   *  Product: '<S285>/Product'
   *  Sum: '<S285>/Sum'
   *  UnitDelay: '<S285>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_Switch2_nf - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S278>/Product' incorporates:
   *  Constant: '<S278>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S284>/Diff' incorporates:
   *  UnitDelay: '<S284>/UD'
   *
   * Block description for '<S284>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S284>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S278>/Saturation' */
  if (rtb_Add_nt > Drive_Motor_Control_D_UL) {
    rtb_Add_nt = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Drive_Motor_Control_D_LL) {
    rtb_Add_nt = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S278>/Add' incorporates:
   *  Gain: '<S278>/Gain'
   *  Gain: '<S278>/Gain1'
   *  Saturate: '<S278>/Saturation'
   */
  rtb_Init = ((Drive_Motor_Control_FF * rtb_Init) + (Drive_Motor_Control_P *
    rtb_Switch2_nf)) + rtb_Add_nt;

  /* Saturate: '<S278>/Saturation2' incorporates:
   *  Sum: '<S278>/Add1'
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

  /* End of Saturate: '<S278>/Saturation2' */

  /* Sum: '<S294>/Add1' incorporates:
   *  Constant: '<S294>/Constant3'
   *  Constant: '<S294>/Constant4'
   *  Math: '<S294>/Math Function'
   *  Sum: '<S294>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S296>/Sum1' incorporates:
   *  Constant: '<S281>/Constant2'
   *  Product: '<S296>/Product'
   *  Sum: '<S296>/Sum'
   *  UnitDelay: '<S296>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Init -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S281>/Product' incorporates:
   *  Constant: '<S281>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S295>/Diff' incorporates:
   *  UnitDelay: '<S295>/UD'
   *
   * Block description for '<S295>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S295>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S281>/Saturation' */
  if (rtb_Add_nt > Steering_Motor_Control_D_UL) {
    rtb_Add_nt = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Motor_Control_D_LL) {
    rtb_Add_nt = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S281>/Add' incorporates:
   *  Gain: '<S281>/Gain1'
   *  Saturate: '<S281>/Saturation'
   */
  rtb_Add_ec = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_nt;

  /* Sum: '<S281>/Subtract' incorporates:
   *  Constant: '<S281>/Constant'
   */
  rtb_Switch2_nf = 1.0 - rtb_Add_ec;

  /* Sum: '<S281>/Sum2' incorporates:
   *  Gain: '<S281>/Gain2'
   *  UnitDelay: '<S281>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S297>/Switch2' incorporates:
   *  Constant: '<S281>/Constant'
   *  RelationalOperator: '<S297>/LowerRelop1'
   *  Sum: '<S281>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_ec))) {
    /* Sum: '<S281>/Subtract1' incorporates:
     *  Constant: '<S281>/Constant1'
     */
    rtb_Switch2_nf = -1.0 - rtb_Add_ec;

    /* Switch: '<S297>/Switch' incorporates:
     *  Constant: '<S281>/Constant1'
     *  RelationalOperator: '<S297>/UpperRelop'
     *  Sum: '<S281>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_ec))) {
      rtb_Switch2_nf = rtb_Init;
    }

    /* End of Switch: '<S297>/Switch' */
  }

  /* End of Switch: '<S297>/Switch2' */

  /* Saturate: '<S281>/Saturation1' */
  if (rtb_Switch2_nf > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_nf < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Switch2_nf;
  }

  /* End of Saturate: '<S281>/Saturation1' */

  /* Sum: '<S281>/Add1' */
  rtb_Add_nt = rtb_Add_ec + rtb_Integral_ga;

  /* Saturate: '<S281>/Saturation2' */
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

  /* End of Saturate: '<S281>/Saturation2' */

  /* Sum: '<S315>/Add1' incorporates:
   *  Constant: '<S315>/Constant3'
   *  Constant: '<S315>/Constant4'
   *  Math: '<S315>/Math Function'
   *  Sum: '<S315>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Integral_d + 3.1415926535897931, 6.2831853071795862)
    - 3.1415926535897931;

  /* Sum: '<S317>/Sum1' incorporates:
   *  Constant: '<S302>/Constant2'
   *  Product: '<S317>/Product'
   *  Sum: '<S317>/Sum'
   *  UnitDelay: '<S317>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_i)
    * Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S302>/Product' incorporates:
   *  Constant: '<S302>/Constant3'
   */
  rtb_Add_ec = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S316>/Diff' incorporates:
   *  UnitDelay: '<S316>/UD'
   *
   * Block description for '<S316>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S316>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Add_ec - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S302>/Saturation' */
  if (rtb_Add_nt > Steering_Motor_Control_D_UL) {
    rtb_Add_nt = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_nt < Steering_Motor_Control_D_LL) {
    rtb_Add_nt = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S302>/Add' incorporates:
   *  Gain: '<S302>/Gain1'
   *  Saturate: '<S302>/Saturation'
   */
  rtb_Add_os = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_nt;

  /* Sum: '<S302>/Subtract' incorporates:
   *  Constant: '<S302>/Constant'
   */
  rtb_Switch2_nf = 1.0 - rtb_Add_os;

  /* Sum: '<S302>/Sum2' incorporates:
   *  Gain: '<S302>/Gain2'
   *  UnitDelay: '<S302>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S318>/Switch2' incorporates:
   *  Constant: '<S302>/Constant'
   *  RelationalOperator: '<S318>/LowerRelop1'
   *  Sum: '<S302>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_os))) {
    /* Sum: '<S302>/Subtract1' incorporates:
     *  Constant: '<S302>/Constant1'
     */
    rtb_Switch2_nf = -1.0 - rtb_Add_os;

    /* Switch: '<S318>/Switch' incorporates:
     *  Constant: '<S302>/Constant1'
     *  RelationalOperator: '<S318>/UpperRelop'
     *  Sum: '<S302>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_os))) {
      rtb_Switch2_nf = rtb_Init;
    }

    /* End of Switch: '<S318>/Switch' */
  }

  /* End of Switch: '<S318>/Switch2' */

  /* Saturate: '<S302>/Saturation1' */
  if (rtb_Switch2_nf > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_nf < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Switch2_nf;
  }

  /* End of Saturate: '<S302>/Saturation1' */

  /* Sum: '<S302>/Add1' */
  rtb_Add_nt = rtb_Add_os + rtb_Integral_bj;

  /* Saturate: '<S302>/Saturation2' */
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

  /* End of Saturate: '<S302>/Saturation2' */

  /* Sum: '<S165>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S119>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S167>/Sum1' incorporates:
   *  Constant: '<S165>/Constant2'
   *  Product: '<S167>/Product'
   *  Sum: '<S165>/Sum'
   *  Sum: '<S167>/Sum'
   *  UnitDelay: '<S167>/Unit Delay1'
   */
  rtb_Add_os = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S165>/Product' incorporates:
   *  Constant: '<S165>/Constant3'
   */
  rtb_Product_lo = rtb_Add_os * 0.0;

  /* Sum: '<S166>/Diff' incorporates:
   *  UnitDelay: '<S166>/UD'
   *
   * Block description for '<S166>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S166>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S165>/Saturation' */
  if (rtb_Add_nt > 0.1) {
    rtb_Add_nt = 0.1;
  } else if (rtb_Add_nt < -0.1) {
    rtb_Add_nt = -0.1;
  }

  /* Sum: '<S165>/Add' incorporates:
   *  Gain: '<S165>/Gain'
   *  Gain: '<S165>/Gain1'
   *  Saturate: '<S165>/Saturation'
   *  Sum: '<S165>/Sum'
   */
  rtb_Init = ((Rebuilt_Transfer_Motor_Gain_FF *
               Robot_Control_B.RB_Desired_Transfer_Speed) +
              (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_nt;

  /* Logic: '<S119>/Logical Operator1' incorporates:
   *  Constant: '<S164>/Constant'
   *  RelationalOperator: '<S164>/Compare'
   */
  rtb_Button_Shoot_Enable = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S119>/Switch1' incorporates:
   *  Abs: '<S119>/Abs'
   *  Constant: '<S119>/Constant1'
   *  Constant: '<S119>/Constant2'
   *  Logic: '<S119>/Logical Operator'
   *  Logic: '<S119>/Logical Operator1'
   *  RelationalOperator: '<S119>/LessThan'
   *  UnitDelay: '<S119>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Button_Shoot_Enable) {
    rtb_Button_Spinup_Enable = true;
  } else {
    rtb_Button_Spinup_Enable = (rtb_Button_Shoot_Enable &&
      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S119>/Switch1' */

  /* Switch: '<S165>/Switch' incorporates:
   *  Constant: '<S165>/Constant4'
   */
  if (rtb_Button_Spinup_Enable) {
    /* Sum: '<S165>/Sum2' incorporates:
     *  Gain: '<S165>/Gain2'
     *  Sum: '<S165>/Sum'
     *  UnitDelay: '<S165>/Unit Delay'
     */
    rtb_Switch2_nf = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S165>/Subtract' incorporates:
     *  Constant: '<S165>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Init;

    /* Switch: '<S168>/Switch2' incorporates:
     *  Constant: '<S165>/Constant'
     *  RelationalOperator: '<S168>/LowerRelop1'
     *  Sum: '<S165>/Subtract'
     */
    if (!(rtb_Switch2_nf > (1.0 - rtb_Init))) {
      /* Sum: '<S165>/Subtract1' incorporates:
       *  Constant: '<S165>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Init;

      /* Switch: '<S168>/Switch' incorporates:
       *  Constant: '<S165>/Constant1'
       *  RelationalOperator: '<S168>/UpperRelop'
       *  Sum: '<S165>/Subtract1'
       */
      if (!(rtb_Switch2_nf < (-1.0 - rtb_Init))) {
        rtb_Integral_d = rtb_Switch2_nf;
      }

      /* End of Switch: '<S168>/Switch' */
    }

    /* End of Switch: '<S168>/Switch2' */

    /* Saturate: '<S165>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S165>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S165>/Switch' */

  /* Switch: '<S119>/Switch2' incorporates:
   *  Logic: '<S119>/Logical Operator1'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S165>/Add1' */
    rtb_Add_nt = rtb_Init + rtb_Integral_d;

    /* Saturate: '<S165>/Saturation2' */
    if (rtb_Add_nt > 1.0) {
      /* Switch: '<S119>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_nt < -1.0) {
      /* Switch: '<S119>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S119>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_nt;
    }

    /* End of Saturate: '<S165>/Saturation2' */
  } else {
    /* Switch: '<S119>/Switch2' incorporates:
     *  Constant: '<S119>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S119>/Switch2' */

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

  /* Switch: '<S111>/Init' incorporates:
   *  UnitDelay: '<S111>/FixPt Unit Delay1'
   *  UnitDelay: '<S111>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Switch2_nf = rtb_Init;
  } else {
    rtb_Switch2_nf = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S111>/Init' */

  /* Sum: '<S109>/Sum1' */
  rtb_Init -= rtb_Switch2_nf;

  /* Switch: '<S110>/Switch2' incorporates:
   *  Constant: '<S108>/Constant1'
   *  Constant: '<S108>/Constant3'
   *  RelationalOperator: '<S110>/LowerRelop1'
   *  RelationalOperator: '<S110>/UpperRelop'
   *  Switch: '<S110>/Switch'
   */
  if (rtb_Init > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Init < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S110>/Switch' incorporates:
     *  Constant: '<S108>/Constant1'
     */
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S110>/Switch2' */

  /* Sum: '<S109>/Sum' */
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

  /* Logic: '<S40>/Logical Operator1' incorporates:
   *  Constant: '<S49>/Constant'
   *  RelationalOperator: '<S49>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Init == 0.0);

  /* Sum: '<S50>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S40>/Subtract'
   */
  rtb_Error_n = rtb_Init - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S52>/Sum1' incorporates:
   *  Constant: '<S50>/Constant2'
   *  Product: '<S52>/Product'
   *  Sum: '<S50>/Sum'
   *  Sum: '<S52>/Sum'
   *  UnitDelay: '<S52>/Unit Delay1'
   */
  rtb_Sum1_fh = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S50>/Product' incorporates:
   *  Constant: '<S50>/Constant3'
   */
  rtb_Product_hm = rtb_Sum1_fh * 0.0;

  /* Sum: '<S51>/Diff' incorporates:
   *  UnitDelay: '<S51>/UD'
   *
   * Block description for '<S51>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S51>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_hm - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S50>/Saturation' */
  if (rtb_Add_nt > 0.1) {
    rtb_Add_nt = 0.1;
  } else if (rtb_Add_nt < -0.1) {
    rtb_Add_nt = -0.1;
  }

  /* Sum: '<S50>/Add' incorporates:
   *  Gain: '<S50>/Gain'
   *  Gain: '<S50>/Gain1'
   *  Saturate: '<S50>/Saturation'
   *  Sum: '<S50>/Sum'
   */
  rtb_Switch2_nf = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Init) +
                    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_nt;

  /* Switch: '<S40>/Switch1' incorporates:
   *  Abs: '<S40>/Abs'
   *  Constant: '<S40>/Constant1'
   *  Constant: '<S40>/Constant2'
   *  Logic: '<S40>/Logical Operator'
   *  Logic: '<S40>/Logical Operator1'
   *  RelationalOperator: '<S40>/LessThan'
   *  UnitDelay: '<S40>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Button_Shoot_Enable = true;
  } else {
    rtb_Button_Shoot_Enable = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_nh));
  }

  /* End of Switch: '<S40>/Switch1' */

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant4'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S50>/Sum2' incorporates:
     *  Gain: '<S50>/Gain2'
     *  Sum: '<S50>/Sum'
     *  UnitDelay: '<S50>/Unit Delay'
     */
    rtb_Init = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S50>/Subtract' incorporates:
     *  Constant: '<S50>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Switch2_nf;

    /* Switch: '<S53>/Switch2' incorporates:
     *  Constant: '<S50>/Constant'
     *  RelationalOperator: '<S53>/LowerRelop1'
     *  Sum: '<S50>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Switch2_nf))) {
      /* Sum: '<S50>/Subtract1' incorporates:
       *  Constant: '<S50>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Switch2_nf;

      /* Switch: '<S53>/Switch' incorporates:
       *  Constant: '<S50>/Constant1'
       *  RelationalOperator: '<S53>/UpperRelop'
       *  Sum: '<S50>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Switch2_nf))) {
        rtb_Error_n = rtb_Init;
      }

      /* End of Switch: '<S53>/Switch' */
    }

    /* End of Switch: '<S53>/Switch2' */

    /* Saturate: '<S50>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Error_n = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Error_n = -0.1;
    }

    /* End of Saturate: '<S50>/Saturation1' */
  } else {
    rtb_Error_n = 0.0;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Switch: '<S40>/Switch2' incorporates:
   *  Logic: '<S40>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S50>/Add1' */
    rtb_Add_nt = rtb_Switch2_nf + rtb_Error_n;

    /* Saturate: '<S50>/Saturation2' */
    if (rtb_Add_nt > 1.0) {
      /* Switch: '<S40>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_nt < -1.0) {
      /* Switch: '<S40>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S40>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_nt;
    }

    /* End of Saturate: '<S50>/Saturation2' */
  } else {
    /* Switch: '<S40>/Switch2' incorporates:
     *  Constant: '<S40>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S40>/Switch2' */

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
   *  RelationalOperator: '<S37>/FixPt Relational Operator'
   *  UnitDelay: '<S37>/Delay Input1'
   *
   * Block description for '<S37>/Delay Input1':
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

  /* Switch: '<S48>/Init' incorporates:
   *  UnitDelay: '<S48>/FixPt Unit Delay1'
   *  UnitDelay: '<S48>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S48>/Init' */

  /* Sum: '<S46>/Sum1' */
  rtb_Switch2_nf = Robot_Control_B.RB_Des_Intake_Arm_Angle - rtb_Init;

  /* Switch: '<S47>/Switch2' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Constant: '<S39>/Constant3'
   *  RelationalOperator: '<S47>/LowerRelop1'
   *  RelationalOperator: '<S47>/UpperRelop'
   *  Switch: '<S47>/Switch'
   */
  if (rtb_Switch2_nf > Rebuilt_Intake_RL_Inc) {
    rtb_Switch2_nf = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Switch2_nf < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S39>/Constant1'
     */
    rtb_Switch2_nf = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S47>/Switch2' */

  /* Sum: '<S46>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Switch2_nf + rtb_Init;

  /* Logic: '<S38>/Logical Operator1' incorporates:
   *  Constant: '<S41>/Constant'
   *  RelationalOperator: '<S41>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Des_Intake_Arm_Angle_RL == 0.0);

  /* Sum: '<S42>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Sum: '<S38>/Subtract'
   */
  rtb_Error_e = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_U.Measured_Intake_Arm_Angle;

  /* Sum: '<S44>/Sum1' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Product: '<S44>/Product'
   *  Sum: '<S42>/Sum'
   *  Sum: '<S44>/Sum'
   *  UnitDelay: '<S44>/Unit Delay1'
   */
  rtb_Switch2_nf = ((rtb_Error_e - Robot_Control_DW.UnitDelay1_DSTATE_l) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_l;

  /* Product: '<S42>/Product' incorporates:
   *  Constant: '<S42>/Constant3'
   */
  rtb_Product_di = rtb_Switch2_nf * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S43>/Diff' incorporates:
   *  UnitDelay: '<S43>/UD'
   *
   * Block description for '<S43>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S43>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_nt = rtb_Product_di - Robot_Control_DW.UD_DSTATE_d;

  /* Saturate: '<S42>/Saturation' */
  if (rtb_Add_nt > 0.1) {
    rtb_Add_nt = 0.1;
  } else if (rtb_Add_nt < -0.1) {
    rtb_Add_nt = -0.1;
  }

  /* Sum: '<S42>/Add' incorporates:
   *  Gain: '<S42>/Gain'
   *  Gain: '<S42>/Gain1'
   *  Saturate: '<S42>/Saturation'
   *  Sum: '<S42>/Sum'
   */
  rtb_Init = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
              (Rebuilt_Intake_Arm_Gain_P * rtb_Error_e)) + rtb_Add_nt;

  /* Switch: '<S38>/Switch1' incorporates:
   *  Abs: '<S38>/Abs'
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S38>/Constant2'
   *  Logic: '<S38>/Logical Operator'
   *  Logic: '<S38>/Logical Operator1'
   *  RelationalOperator: '<S38>/LessThan'
   *  UnitDelay: '<S38>/Unit Delay'
   */
  if ((fabs(rtb_Error_e) < Rebuilt_Intake_Arm_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_dvn));
  }

  /* End of Switch: '<S38>/Switch1' */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant4'
   */
  if (rtb_Intake_Arm_Move_In) {
    /* Sum: '<S42>/Sum2' incorporates:
     *  Gain: '<S42>/Gain2'
     *  Sum: '<S42>/Sum'
     *  UnitDelay: '<S42>/Unit Delay'
     */
    rtb_Error_e = (Rebuilt_Intake_Arm_Gain_I * rtb_Error_e) +
      Robot_Control_DW.UnitDelay_DSTATE_ej;

    /* Sum: '<S42>/Subtract' incorporates:
     *  Constant: '<S42>/Constant'
     */
    rtb_Switch2_p0 = 1.0 - rtb_Init;

    /* Switch: '<S45>/Switch2' incorporates:
     *  Constant: '<S42>/Constant'
     *  RelationalOperator: '<S45>/LowerRelop1'
     *  Sum: '<S42>/Subtract'
     */
    if (!(rtb_Error_e > (1.0 - rtb_Init))) {
      /* Sum: '<S42>/Subtract1' incorporates:
       *  Constant: '<S42>/Constant1'
       */
      rtb_Switch2_p0 = -1.0 - rtb_Init;

      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S42>/Constant1'
       *  RelationalOperator: '<S45>/UpperRelop'
       *  Sum: '<S42>/Subtract1'
       */
      if (!(rtb_Error_e < (-1.0 - rtb_Init))) {
        rtb_Switch2_p0 = rtb_Error_e;
      }

      /* End of Switch: '<S45>/Switch' */
    }

    /* End of Switch: '<S45>/Switch2' */

    /* Saturate: '<S42>/Saturation1' */
    if (rtb_Switch2_p0 > 0.1) {
      rtb_Error_e = 0.1;
    } else if (rtb_Switch2_p0 < -0.1) {
      rtb_Error_e = -0.1;
    } else {
      rtb_Error_e = rtb_Switch2_p0;
    }

    /* End of Saturate: '<S42>/Saturation1' */
  } else {
    rtb_Error_e = 0.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Switch: '<S38>/Switch2' incorporates:
   *  Logic: '<S38>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S42>/Add1' */
    rtb_Add_nt = rtb_Init + rtb_Error_e;

    /* Saturate: '<S42>/Saturation2' */
    if (rtb_Add_nt > 1.0) {
      /* Switch: '<S38>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_nt < -1.0) {
      /* Switch: '<S38>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S38>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_nt;
    }

    /* End of Saturate: '<S42>/Saturation2' */
  } else {
    /* Switch: '<S38>/Switch2' incorporates:
     *  Constant: '<S38>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S38>/Switch2' */

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

  /* Logic: '<S117>/Logical Operator1' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S160>/Sum' incorporates:
   *  Sum: '<S117>/Subtract'
   */
  rtb_Init = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S162>/Sum1' incorporates:
   *  Constant: '<S160>/Constant2'
   *  Product: '<S162>/Product'
   *  Sum: '<S160>/Sum'
   *  Sum: '<S162>/Sum'
   *  UnitDelay: '<S162>/Unit Delay1'
   */
  rtb_Switch2_p0 = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S160>/Product' incorporates:
   *  Constant: '<S160>/Constant3'
   */
  rtb_Product_i = rtb_Switch2_p0 * 0.0;

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
  rtb_Add_nt = rtb_Product_i - Robot_Control_DW.UD_DSTATE_kz;

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
  rtb_Add_nt += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Init);

  /* Switch: '<S117>/Switch4' incorporates:
   *  Constant: '<S117>/Constant6'
   *  Constant: '<S117>/Constant7'
   *  Logic: '<S117>/Logical Operator1'
   *  Logic: '<S117>/Logical Operator2'
   *  RelationalOperator: '<S117>/LessThan2'
   *  UnitDelay: '<S117>/Unit Delay1'
   */
  if ((rtb_Init < 0.0) && rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay1_DSTATE_ea));
  }

  /* End of Switch: '<S117>/Switch4' */

  /* Switch: '<S117>/Switch1' incorporates:
   *  Constant: '<S117>/Constant1'
   *  Constant: '<S117>/Constant2'
   *  Logic: '<S117>/Logical Operator'
   *  Logic: '<S117>/Logical Operator1'
   *  RelationalOperator: '<S117>/LessThan'
   *  UnitDelay: '<S117>/Unit Delay'
   */
  if ((rtb_Init < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Compare_ik = true;
  } else {
    rtb_Compare_ik = (rtb_LogicalOperator1_n &&
                      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S117>/Switch1' */

  /* Switch: '<S160>/Switch' incorporates:
   *  Constant: '<S160>/Constant4'
   */
  if (rtb_Compare_ik) {
    /* Sum: '<S160>/Sum2' incorporates:
     *  Gain: '<S160>/Gain2'
     *  Product: '<S160>/Product1'
     *  Sum: '<S160>/Sum'
     *  Switch: '<S160>/Switch1'
     *  UnitDelay: '<S160>/Unit Delay'
     */
    rtb_Init = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Init) * ((real_T)
      (!rtb_Intake_Arm_Move_Out))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S160>/Subtract' incorporates:
     *  Constant: '<S160>/Constant'
     */
    rtb_Error_h = 1.0 - rtb_Add_nt;

    /* Switch: '<S163>/Switch2' incorporates:
     *  Constant: '<S160>/Constant'
     *  RelationalOperator: '<S163>/LowerRelop1'
     *  Sum: '<S160>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Add_nt))) {
      /* Sum: '<S160>/Subtract1' incorporates:
       *  Constant: '<S160>/Constant1'
       */
      rtb_Error_h = -1.0 - rtb_Add_nt;

      /* Switch: '<S163>/Switch' incorporates:
       *  Constant: '<S160>/Constant1'
       *  RelationalOperator: '<S163>/UpperRelop'
       *  Sum: '<S160>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Add_nt))) {
        rtb_Error_h = rtb_Init;
      }

      /* End of Switch: '<S163>/Switch' */
    }

    /* End of Switch: '<S163>/Switch2' */

    /* Saturate: '<S160>/Saturation1' */
    if (rtb_Error_h > 0.1) {
      rtb_Init = 0.1;
    } else if (rtb_Error_h < -0.1) {
      rtb_Init = -0.1;
    } else {
      rtb_Init = rtb_Error_h;
    }

    /* End of Saturate: '<S160>/Saturation1' */
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S160>/Switch' */

  /* Switch: '<S117>/Switch2' incorporates:
   *  Logic: '<S117>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S160>/Add1' */
    rtb_Add_nt += rtb_Init;

    /* Saturate: '<S160>/Saturation2' */
    if (rtb_Add_nt > 1.0) {
      /* Switch: '<S117>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_nt < -1.0) {
      /* Switch: '<S117>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S117>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_nt;
    }

    /* End of Saturate: '<S160>/Saturation2' */
  } else {
    /* Switch: '<S117>/Switch2' incorporates:
     *  Constant: '<S117>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S117>/Switch2' */

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

  /* Outport: '<Root>/Enable_Wheels' */
  Robot_Control_Y.Enable_Wheels = rtb_Enable_Wheels;

  /* Outport: '<Root>/Reset_Wheel_Offsets' */
  Robot_Control_Y.Reset_Wheel_Offsets = rtb_Reset_Wheel_Offsets;

  /* Outport: '<Root>/Disable_Wheels' */
  Robot_Control_Y.Disable_Wheels = rtb_Disable_Wheels;

  /* Outport: '<Root>/Swerve_Motors_Disabled' */
  Robot_Control_Y.Swerve_Motors_Disabled = rtb_Swerve_Motors_Disabled;

  /* Outport: '<Root>/Vision_Desired_Pipeline' */
  Robot_Control_Y.Vision_Desired_Pipeline = rtb_Desired_Pipeline;

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

  /* Update for Delay: '<S54>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S74>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S54>/A'
   *  Delay: '<S54>/MemoryX'
   */
  rtb_Add_nt = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Error_h = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S54>/MemoryX' incorporates:
   *  Constant: '<S54>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S74>/A[k]*xhat[k|k-1]'
   *  Product: '<S74>/B[k]*u[k]'
   *  Sum: '<S74>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Add_nt) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Error_h) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S330>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S330>/FixPt Constant'
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

  /* Update for UnitDelay: '<S113>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S352>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S351>/UD'
   *
   * Block description for '<S351>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S349>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Saturation_h;

  /* Update for UnitDelay: '<S332>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Init_o;

  /* Update for UnitDelay: '<S347>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S347>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S347>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S331>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S340>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S340>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S340>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S306>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_DeadZone;

  /* Update for UnitDelay: '<S305>/UD'
   *
   * Block description for '<S305>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S299>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S243>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S242>/UD'
   *
   * Block description for '<S242>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Switch2;

  /* Update for UnitDelay: '<S236>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S254>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S253>/UD'
   *
   * Block description for '<S253>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_ow;

  /* Update for UnitDelay: '<S239>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S264>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S263>/UD'
   *
   * Block description for '<S263>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S257>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S275>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_bl;

  /* Update for UnitDelay: '<S274>/UD'
   *
   * Block description for '<S274>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_cw;

  /* Update for UnitDelay: '<S260>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S285>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S284>/UD'
   *
   * Block description for '<S284>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S278>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S296>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S295>/UD'
   *
   * Block description for '<S295>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S281>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S317>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S316>/UD'
   *
   * Block description for '<S316>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_ec;

  /* Update for UnitDelay: '<S302>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S167>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_os;

  /* Update for UnitDelay: '<S166>/UD'
   *
   * Block description for '<S166>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S165>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S119>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Button_Spinup_Enable;

  /* Update for UnitDelay: '<S111>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S111>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S52>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_fh;

  /* Update for UnitDelay: '<S51>/UD'
   *
   * Block description for '<S51>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_hm;

  /* Update for UnitDelay: '<S50>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S40>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_nh = rtb_Button_Shoot_Enable;

  /* Update for UnitDelay: '<S37>/Delay Input1'
   *
   * Block description for '<S37>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S48>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S48>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S44>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch2_nf;

  /* Update for UnitDelay: '<S43>/UD'
   *
   * Block description for '<S43>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_d = rtb_Product_di;

  /* Update for UnitDelay: '<S42>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ej = rtb_Error_e;

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dvn = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S162>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Switch2_p0;

  /* Update for UnitDelay: '<S161>/UD'
   *
   * Block description for '<S161>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_i;

  /* Update for UnitDelay: '<S117>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_Out;

  /* Update for UnitDelay: '<S160>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Init;

  /* Update for UnitDelay: '<S117>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_db = rtb_Compare_ik;
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

  /* Start for If: '<S114>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S54>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S330>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S347>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S340>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S111>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S48>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S407>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S175>/If' */
  Robot_Control_DW.If_ActiveSubsystem_hk = -1;

  /* InitializeConditions for UnitDelay: '<S171>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S175>/Robot_Index_Is_Valid' */
  /* Start for If: '<S178>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S178>/Circle_Check_Valid' */
  /* Start for If: '<S180>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S178>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S175>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S114>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S146>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ll = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S114>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S114>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S114>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S114>/If Action Subsystem2' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem2);

  /* End of SystemInitialize for SubSystem: '<S114>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S114>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S114>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S114>/If Action Subsystem4' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem4);

  /* End of SystemInitialize for SubSystem: '<S114>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S114>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S151>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S114>/If Action Subsystem5' */
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
