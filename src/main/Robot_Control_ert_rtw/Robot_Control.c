/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.473
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Mar 11 22:37:03 2026
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
                                      * Referenced by: '<S421>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S417>/Constant'
                                        *   '<S417>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S421>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S417>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S252>/Constant3'
                                        *   '<S273>/Constant3'
                                        *   '<S294>/Constant3'
                                        *   '<S315>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S252>/Constant2'
                                   *   '<S273>/Constant2'
                                   *   '<S294>/Constant2'
                                   *   '<S315>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S252>/Saturation'
                                        *   '<S273>/Saturation'
                                        *   '<S294>/Saturation'
                                        *   '<S315>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S252>/Saturation'
                                        *   '<S273>/Saturation'
                                        *   '<S294>/Saturation'
                                        *   '<S315>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S252>/Gain'
                                            *   '<S273>/Gain'
                                            *   '<S294>/Gain'
                                            *   '<S315>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S252>/Gain2'
                                        *   '<S273>/Gain2'
                                        *   '<S294>/Gain2'
                                        *   '<S315>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S252>/Saturation1'
                                         *   '<S273>/Saturation1'
                                         *   '<S294>/Saturation1'
                                         *   '<S315>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S252>/Saturation1'
                                        *   '<S273>/Saturation1'
                                        *   '<S294>/Saturation1'
                                        *   '<S315>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S252>/Gain1'
                                        *   '<S273>/Gain1'
                                        *   '<S294>/Gain1'
                                        *   '<S315>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S257>/Constant'
                            *   '<S278>/Constant'
                            *   '<S299>/Constant'
                            *   '<S320>/Constant'
                            */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S171>/BlueAllianceZoneX'
                                         *   '<S173>/BlueAllianceZoneX'
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
                                         *   '<S172>/RedAllianceZoneX'
                                         *   '<S174>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S144>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S144>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S407>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S407>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rate_Limit_Max_X = 0.02;        /* Variable: Rate_Limit_Max_X
                                        * Referenced by: '<S37>/Constant3'
                                        */
real_T Rate_Limit_Max_Y = 0.02;        /* Variable: Rate_Limit_Max_Y
                                        * Referenced by: '<S38>/Constant3'
                                        */
real_T Rate_Limit_Max_Z = 0.02;        /* Variable: Rate_Limit_Max_Z
                                        * Referenced by: '<S36>/Constant3'
                                        */
real_T Rate_Limit_Min_X = -0.02;       /* Variable: Rate_Limit_Min_X
                                        * Referenced by: '<S37>/Constant1'
                                        */
real_T Rate_Limit_Min_Y = -0.02;       /* Variable: Rate_Limit_Min_Y
                                        * Referenced by: '<S38>/Constant1'
                                        */
real_T Rate_Limit_Min_Z = -0.02;       /* Variable: Rate_Limit_Min_Z
                                        * Referenced by: '<S36>/Constant1'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = 0.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S139>/Constant'
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
                                   * Referenced by: '<S124>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S124>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S58>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                        * Referenced by: '<S58>/Gain1'
                                        */
real_T Rebuilt_Intake_Cycle_Angle_In = 0.0;
                                      /* Variable: Rebuilt_Intake_Cycle_Angle_In
                                       * Referenced by: '<S6>/Chart'
                                       */
real_T Rebuilt_Intake_Cycle_Angle_Out = 70.0;
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
real_T Rebuilt_Intake_RL_Dec = -3.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S52>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 3.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S52>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 27.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S162>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 33.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by: '<S167>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 32.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S158>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 57.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S159>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 82.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S160>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 107.0;/* Variable: Rebuilt_Match_Time_Shift_4
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
real_T Rebuilt_Match_Time_TeleOp = 140.0;/* Variable: Rebuilt_Match_Time_TeleOp
                                          * Referenced by: '<S130>/Constant'
                                          */
real_T Rebuilt_Match_Time_Transition = 7.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S156>/Constant'
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
                                * Referenced by: '<S53>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00012732;/* Variable: Rebuilt_Roller_Motor_Gain_FF
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
                                       * Referenced by: '<S176>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S176>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.001;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                             * Referenced by: '<S176>/Gain1'
                                             */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S143>/Constant2'
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
                              * Referenced by: '<S135>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S181>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S181>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S181>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S406>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S404>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S406>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S407>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S407>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S241>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S241>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S188>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S201>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S241>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S348>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S348>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S348>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S348>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S348>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S348>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S365>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S365>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S365>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S365>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S364>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S365>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S365>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S365>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S365>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S365>/Constant1'
                                   *   '<S365>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S365>/Constant'
                                   *   '<S365>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S255>/Constant3'
                                        *   '<S276>/Constant3'
                                        *   '<S297>/Constant3'
                                        *   '<S318>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S255>/Constant2'
                                *   '<S276>/Constant2'
                                *   '<S297>/Constant2'
                                *   '<S318>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S255>/Saturation'
                                           *   '<S276>/Saturation'
                                           *   '<S297>/Saturation'
                                           *   '<S318>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S255>/Saturation'
                                          *   '<S276>/Saturation'
                                          *   '<S297>/Saturation'
                                          *   '<S318>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S255>/Gain2'
                                         *   '<S276>/Gain2'
                                         *   '<S297>/Gain2'
                                         *   '<S318>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S255>/Saturation1'
                                             *   '<S276>/Saturation1'
                                             *   '<S297>/Saturation1'
                                             *   '<S318>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S255>/Saturation1'
                                            *   '<S276>/Saturation1'
                                            *   '<S297>/Saturation1'
                                            *   '<S318>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S255>/Gain1'
                                        *   '<S276>/Gain1'
                                        *   '<S297>/Gain1'
                                        *   '<S318>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S347>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S347>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S347>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S347>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S347>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S347>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S406>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S406>/Constant1'
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
                                      * Referenced by: '<S405>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S405>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S405>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S335>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S335>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S335>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S335>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S335>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S335>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S407>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S406>/Dead Zone'
                                        *   '<S407>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S406>/Dead Zone'
                                        *   '<S407>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S404>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S404>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S404>/Constant4'
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
                                        * Referenced by: '<S404>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S404>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S404>/Constant5'
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
                                        *   '<S404>/Constant11'
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
  /* Logic: '<S163>/NOT' incorporates:
   *  SignalConversion generated from: '<S163>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S163>/IsRedActive' */
  *rty_IsRedActive = rtu_IsBlueInactiveFirst;

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
  /* Logic: '<S164>/NOT1' incorporates:
   *  SignalConversion generated from: '<S164>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S164>/IsBlueActive' */
  *rty_IsBlueActive = rtu_IsBlueInactiveFirst;

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
  real_T rtb_Add1_l;
  real_T rtb_Add_a5;
  real_T rtb_Add_e3;
  real_T rtb_Add_f1;
  real_T rtb_Add_fd;
  real_T rtb_Add_i;
  real_T rtb_Auto_Initial_Gyro_Angle;
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
  real_T rtb_Modulation_Drv;
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
  real_T rtb_Sum1_cd;
  real_T rtb_Sum1_hc;
  real_T rtb_Sum1_p1;
  real_T rtb_Sum1_pi;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1_b0;
  real_T rtb_Switch2_ee;
  real_T rtb_Switch2_p2;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s213_iter;
  uint16_T s238_iter;
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
  boolean_T rtb_Shooter_Active_prev;

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

  /* Switch: '<S44>/Init' incorporates:
   *  UnitDelay: '<S44>/FixPt Unit Delay1'
   *  UnitDelay: '<S44>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Subtract_c3 = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Subtract_c3 = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S44>/Init' */

  /* Sum: '<S42>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Subtract_c3;

  /* Switch: '<S43>/Switch2' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Constant: '<S37>/Constant3'
   *  RelationalOperator: '<S43>/LowerRelop1'
   *  RelationalOperator: '<S43>/UpperRelop'
   *  Switch: '<S43>/Switch'
   */
  if (rtb_Sum1 > Rate_Limit_Max_X) {
    rtb_Sin4 = Rate_Limit_Max_X;
  } else if (rtb_Sum1 < Rate_Limit_Min_X) {
    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S37>/Constant1'
     */
    rtb_Sin4 = Rate_Limit_Min_X;
  } else {
    rtb_Sin4 = rtb_Sum1;
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Sum: '<S42>/Sum' */
  rtb_Sum1 = rtb_Sin4 + rtb_Subtract_c3;

  /* Switch: '<S5>/Switch' incorporates:
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Switch: '<S5>/Switch' */
    Robot_Control_B.Drive_Joystick_X = rtb_Sum1;
  } else {
    /* Switch: '<S5>/Switch' */
    Robot_Control_B.Drive_Joystick_X = Robot_Control_B.Drive_Joystick_X_preRL;
  }

  /* End of Switch: '<S5>/Switch' */

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S47>/Init' incorporates:
   *  UnitDelay: '<S47>/FixPt Unit Delay1'
   *  UnitDelay: '<S47>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S47>/Init' */

  /* Sum: '<S45>/Sum1' */
  rtb_Sum1_p1 = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Sin4;

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S38>/Constant3'
   *  RelationalOperator: '<S46>/LowerRelop1'
   *  RelationalOperator: '<S46>/UpperRelop'
   *  Switch: '<S46>/Switch'
   */
  if (rtb_Sum1_p1 > Rate_Limit_Max_Y) {
    rtb_Sum1_p1 = Rate_Limit_Max_Y;
  } else if (rtb_Sum1_p1 < Rate_Limit_Min_Y) {
    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S38>/Constant1'
     */
    rtb_Sum1_p1 = Rate_Limit_Min_Y;
  }

  /* Sum: '<S45>/Sum' incorporates:
   *  Switch: '<S46>/Switch2'
   */
  rtb_Sum1_p1 += rtb_Sin4;

  /* Switch: '<S5>/Switch1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Switch: '<S5>/Switch1' */
    Robot_Control_B.Drive_Joystick_Y = rtb_Sum1_p1;
  } else {
    /* Switch: '<S5>/Switch1' */
    Robot_Control_B.Drive_Joystick_Y = Robot_Control_B.Drive_Joystick_Y_preRL;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S41>/Init' incorporates:
   *  UnitDelay: '<S41>/FixPt Unit Delay1'
   *  UnitDelay: '<S41>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S41>/Init' */

  /* Sum: '<S39>/Sum1' */
  rtb_Sum1_cd = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Sin4;

  /* Switch: '<S40>/Switch2' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S36>/Constant3'
   *  RelationalOperator: '<S40>/LowerRelop1'
   *  RelationalOperator: '<S40>/UpperRelop'
   *  Switch: '<S40>/Switch'
   */
  if (rtb_Sum1_cd > Rate_Limit_Max_Z) {
    rtb_Sum1_cd = Rate_Limit_Max_Z;
  } else if (rtb_Sum1_cd < Rate_Limit_Min_Z) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S36>/Constant1'
     */
    rtb_Sum1_cd = Rate_Limit_Min_Z;
  }

  /* Sum: '<S39>/Sum' incorporates:
   *  Switch: '<S40>/Switch2'
   */
  rtb_Sum1_cd += rtb_Sin4;

  /* Switch: '<S5>/Switch2' incorporates:
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Switch: '<S5>/Switch2' */
    Robot_Control_B.Drive_Joystick_Z = rtb_Sum1_cd;
  } else {
    /* Switch: '<S5>/Switch2' */
    Robot_Control_B.Drive_Joystick_Z = Robot_Control_B.Drive_Joystick_Z_preRL;
  }

  /* End of Switch: '<S5>/Switch2' */

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

  /* If: '<S433>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S433>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S436>/Action Port'
     */
    /* Product: '<S436>/Product' incorporates:
     *  Constant: '<S436>/Constant1'
     *  Constant: '<S436>/Constant2'
     *  Math: '<S436>/Math Function'
     */
    rtb_Sin4 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495) *
      111.0;

    /* End of Outputs for SubSystem: '<S433>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S433>/Subsystem' incorporates:
     *  ActionPort: '<S437>/Action Port'
     */
    /* SignalConversion generated from: '<S437>/Out1' incorporates:
     *  Constant: '<S437>/Constant'
     */
    rtb_Sin4 = 0.0;

    /* End of Outputs for SubSystem: '<S433>/Subsystem' */
  }

  /* End of If: '<S433>/If' */

  /* Gain: '<S434>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Subtract_c3 = 0.017453292519943295 *
    Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S435>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Sin4 * cos(rtb_Subtract_c3))
    + Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S435>/theta->y'
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
    rtb_Shooter_Active_prev = true;

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

    /* SignalConversion generated from: '<S4>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S4>/Constant21'
     */
    rtb_Auto_Initial_Gyro_Angle = 0.0;

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
      rtb_Switch1_b0 = 0.0;
    } else {
      rtb_Switch1_b0 = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
    }

    /* End of Switch: '<S19>/Switch1' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     */
    if (rtb_Compare_ik) {
      rtb_Shooter_Active_prev = (rtb_Switch1_b0 >= Auto_Shoot_Time);
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
        if (Robot_Control_DW.UnitDelay_DSTATE_lly) {
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

    /* Selector: '<S18>/Select heading angle from first row' incorporates:
     *  Selector: '<S20>/Selector'
     */
    rtb_Auto_Initial_Gyro_Angle = rtb_Spline_Ref_Poses_h[30];

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
    rtb_Shooter_Active_prev = false;

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
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Switch1_b0;

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
       *  UnitDelay: '<S406>/Unit Delay1'
       *  UnitDelay: '<S406>/Unit Delay2'
       *  UnitDelay: '<S406>/Unit Delay3'
       *  UnitDelay: '<S406>/Unit Delay4'
       *  UnitDelay: '<S409>/Delay Input1'
       *  UnitDelay: '<S410>/Delay Input1'
       *  UnitDelay: '<S411>/Delay Input1'
       *  UnitDelay: '<S412>/Delay Input1'
       *  UnitDelay: '<S414>/Delay Input1'
       *  UnitDelay: '<S420>/Unit Delay'
       *  UnitDelay: '<S420>/Unit Delay1'
       *  UnitDelay: '<S424>/FixPt Unit Delay1'
       *  UnitDelay: '<S424>/FixPt Unit Delay2'
       *
       * Block description for '<S409>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S410>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S411>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S412>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S414>/Delay Input1':
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
      Robot_Control_DW.FixPtUnitDelay2_DSTATE_af = 1U;
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

    /* Switch: '<S404>/Switch4' incorporates:
     *  Constant: '<S429>/Constant'
     *  Constant: '<S432>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S429>/Compare'
     *  RelationalOperator: '<S432>/Compare'
     *  Switch: '<S404>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S404>/Switch4' incorporates:
       *  Constant: '<S404>/Constant8'
       *  Sum: '<S404>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S404>/Switch5' incorporates:
       *  Constant: '<S404>/Constant7'
       *  Gain: '<S404>/Gain'
       *  Sum: '<S404>/Subtract5'
       *  Switch: '<S404>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S404>/Switch4' incorporates:
       *  Constant: '<S404>/Constant6'
       *  Switch: '<S404>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S404>/Switch4' */

    /* Logic: '<S404>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S404>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S406>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_a5 = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_a5 = 0.0;
    } else {
      rtb_Add_a5 = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S406>/Add' incorporates:
     *  Constant: '<S406>/Constant'
     *  Constant: '<S406>/Constant1'
     *  DeadZone: '<S406>/Dead Zone'
     *  Lookup_n-D: '<S406>/Modulation_Str_Y_Rel'
     *  Product: '<S406>/Product'
     *  Product: '<S406>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Auto_Initial_Gyro_Angle = (look1_binlcpw
      (Robot_Control_B.Steer_Joystick_Y, rtCP_Modulation_Str_Y_Rel_bp01D,
       rtCP_Modulation_Str_Y_Rel_table, 20U) * Steering_Relative_Gain) +
      (rtb_Add_a5 * Steering_Twist_Gain);

    /* RelationalOperator: '<S408>/Compare' incorporates:
     *  Constant: '<S408>/Constant'
     */
    rtb_Compare_ik = (rtb_Auto_Initial_Gyro_Angle == 0.0);

    /* Logic: '<S406>/AND2' incorporates:
     *  RelationalOperator: '<S409>/FixPt Relational Operator'
     *  RelationalOperator: '<S410>/FixPt Relational Operator'
     *  RelationalOperator: '<S411>/FixPt Relational Operator'
     *  RelationalOperator: '<S412>/FixPt Relational Operator'
     *  UnitDelay: '<S409>/Delay Input1'
     *  UnitDelay: '<S410>/Delay Input1'
     *  UnitDelay: '<S411>/Delay Input1'
     *  UnitDelay: '<S412>/Delay Input1'
     *
     * Block description for '<S409>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S410>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S411>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S412>/Delay Input1':
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

    /* Logic: '<S406>/AND1' incorporates:
     *  Logic: '<S406>/AND3'
     *  UnitDelay: '<S406>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_ik && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S406>/AND4' incorporates:
     *  Logic: '<S406>/AND8'
     *  UnitDelay: '<S406>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_ik && (!rtb_Intake_Arm_Cycle)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S406>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S406>/Switch8' incorporates:
     *  Constant: '<S415>/Constant'
     *  Logic: '<S406>/AND9'
     *  RelationalOperator: '<S414>/FixPt Relational Operator'
     *  RelationalOperator: '<S415>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S414>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S414>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_ik) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S406>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S406>/Switch8' incorporates:
       *  UnitDelay: '<S406>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S406>/Switch8' */

    /* Switch: '<S406>/Switch4' incorporates:
     *  Constant: '<S406>/Constant5'
     *  Switch: '<S406>/Switch1'
     *  Switch: '<S406>/Switch5'
     *  Switch: '<S406>/Switch6'
     *  Switch: '<S406>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Subtract_c3 = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S406>/Switch5' incorporates:
       *  Constant: '<S406>/Constant6'
       */
      rtb_Subtract_c3 = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S406>/Switch6' incorporates:
       *  Constant: '<S406>/Constant7'
       *  Switch: '<S406>/Switch5'
       */
      rtb_Subtract_c3 = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S406>/Switch7' incorporates:
       *  Constant: '<S406>/Constant8'
       *  Switch: '<S406>/Switch5'
       *  Switch: '<S406>/Switch6'
       */
      rtb_Subtract_c3 = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S406>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S406>/Switch5'
       *  Switch: '<S406>/Switch6'
       *  Switch: '<S406>/Switch7'
       */
      rtb_Subtract_c3 = 0.0;
    } else {
      /* Switch: '<S406>/Switch6' incorporates:
       *  Switch: '<S406>/Switch5'
       *  Switch: '<S406>/Switch7'
       *  UnitDelay: '<S406>/Unit Delay1'
       */
      rtb_Subtract_c3 = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S406>/Switch4' */

    /* Switch: '<S406>/Switch2' incorporates:
     *  Switch: '<S406>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S406>/Switch2' incorporates:
       *  Constant: '<S406>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S406>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Subtract_c3;
    } else {
      /* Switch: '<S406>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S406>/Switch3' incorporates:
       *  Constant: '<S406>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S406>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S406>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S405>/Switch1' incorporates:
     *  Constant: '<S405>/Constant5'
     *  Constant: '<S405>/Constant8'
     *  DataTypeConversion: '<S405>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_ik;
    }

    /* End of Switch: '<S405>/Switch1' */

    /* Lookup_n-D: '<S407>/Modulation_Drv' incorporates:
     *  Math: '<S407>/Magnitude'
     */
    rtb_Modulation_Drv = look1_binlcpw(rt_hypotd_snf
      (Robot_Control_B.Drive_Joystick_X, Robot_Control_B.Drive_Joystick_Y),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S418>/Compare' incorporates:
     *  Constant: '<S418>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Modulation_Drv == 0.0);

    /* DeadZone: '<S407>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S407>/Dead Zone' */

    /* Logic: '<S407>/Logical Operator' incorporates:
     *  Constant: '<S419>/Constant'
     *  RelationalOperator: '<S419>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_DeadZone != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S405>/Switch' incorporates:
     *  Constant: '<S405>/Constant5'
     *  Constant: '<S405>/Constant7'
     *  DataTypeConversion: '<S405>/Data Type Conversion'
     *  Logic: '<S407>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S405>/Switch' */

    /* Switch: '<S404>/Switch2' incorporates:
     *  Constant: '<S404>/Constant2'
     *  Constant: '<S428>/Constant'
     *  Constant: '<S431>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S428>/Compare'
     *  RelationalOperator: '<S431>/Compare'
     *  Sum: '<S404>/Subtract'
     *  Switch: '<S404>/Switch'
     *  Switch: '<S404>/Switch1'
     *  Switch: '<S404>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S404>/Switch2' incorporates:
       *  Constant: '<S404>/Constant5'
       *  Sum: '<S404>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S404>/Switch2' incorporates:
       *  Constant: '<S404>/Constant4'
       *  Sum: '<S404>/Subtract2'
       *  Switch: '<S404>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S404>/Switch1' incorporates:
       *  Constant: '<S404>/Constant1'
       *  Sum: '<S404>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S404>/Switch2' incorporates:
       *  Constant: '<S404>/Constant3'
       *  Switch: '<S404>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S404>/Switch1' incorporates:
       *  Constant: '<S404>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S404>/Switch2' */

    /* UnaryMinus: '<S404>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S420>/Switch1' incorporates:
     *  Constant: '<S425>/Constant'
     *  Constant: '<S426>/Constant'
     *  Logic: '<S420>/AND'
     *  RelationalOperator: '<S425>/Compare'
     *  RelationalOperator: '<S426>/Compare'
     *  Switch: '<S420>/Switch2'
     *  UnitDelay: '<S420>/Unit Delay'
     *  UnitDelay: '<S420>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1_b0 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1_b0 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S420>/Switch1' */

    /* Switch: '<S407>/Switch1' incorporates:
     *  Logic: '<S407>/Logical Operator1'
     *  Switch: '<S407>/Switch4'
     *  Switch: '<S407>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S407>/Sign' */
      if (rtIsNaN(rtb_DeadZone)) {
        rtb_Add_a5 = (rtNaN);
      } else if (rtb_DeadZone < 0.0) {
        rtb_Add_a5 = -1.0;
      } else {
        rtb_Add_a5 = (rtb_DeadZone > 0.0);
      }

      /* Switch: '<S407>/Switch5' incorporates:
       *  Constant: '<S407>/Constant3'
       *  Constant: '<S407>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S407>/Gain3'
       *  Signum: '<S407>/Sign'
       *  Sum: '<S407>/Add'
       *  Switch: '<S407>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_a5) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S407>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S407>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S407>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S407>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S407>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S407>/Switch4'
       *  Trigonometry: '<S407>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1_b0, rtb_Sin4);
    }

    /* End of Switch: '<S407>/Switch1' */

    /* Switch: '<S417>/Switch1' incorporates:
     *  Constant: '<S417>/Constant'
     *  Constant: '<S417>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S417>/Switch1' */

    /* Switch: '<S424>/Init' incorporates:
     *  UnitDelay: '<S424>/FixPt Unit Delay1'
     *  UnitDelay: '<S424>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_af != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S424>/Init' */

    /* Sum: '<S422>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S423>/Switch2' incorporates:
     *  Constant: '<S421>/Constant1'
     *  Constant: '<S421>/Constant3'
     *  RelationalOperator: '<S423>/LowerRelop1'
     *  RelationalOperator: '<S423>/UpperRelop'
     *  Switch: '<S423>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S423>/Switch' incorporates:
       *  Constant: '<S421>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S423>/Switch2' */

    /* Sum: '<S422>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S407>/Switch8' incorporates:
     *  Logic: '<S407>/Logical Operator1'
     *  Switch: '<S407>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S407>/Switch' incorporates:
       *  Gain: '<S407>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_DeadZone;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S407>/Constant5'
       *  Gain: '<S407>/Gain2'
       *  Math: '<S407>/Magnitude1'
       *  MinMax: '<S407>/Min'
       *  Switch: '<S407>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S417>/Product' incorporates:
       *  Switch: '<S407>/Switch2'
       */
      rtb_Add_a5 = rtb_Modulation_Drv * rtb_Init;

      /* Saturate: '<S417>/Saturation' incorporates:
       *  Switch: '<S407>/Switch2'
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

      /* End of Saturate: '<S417>/Saturation' */
    }

    /* End of Switch: '<S407>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S406>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Auto_Initial_Gyro_Angle;

    /* Switch: '<S404>/Switch6' incorporates:
     *  Constant: '<S404>/Constant11'
     *  Switch: '<S404>/Switch7'
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
    rtb_Shooter_Active_prev = false;

    /* RelationalOperator: '<S401>/Compare' incorporates:
     *  Constant: '<S401>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S402>/Compare' incorporates:
     *  Constant: '<S402>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S397>/Compare' incorporates:
     *  Constant: '<S397>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S400>/Compare' incorporates:
     *  Constant: '<S400>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S399>/Compare' incorporates:
     *  Constant: '<S399>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S398>/Compare' incorporates:
     *  Constant: '<S398>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     */
    rtb_Auto_Initial_Gyro_Angle = 0.0;

    /* Update for UnitDelay: '<S414>/Delay Input1'
     *
     * Block description for '<S414>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_ik;

    /* Update for UnitDelay: '<S413>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S413>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S409>/Delay Input1'
     *
     * Block description for '<S409>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S410>/Delay Input1'
     *
     * Block description for '<S410>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S411>/Delay Input1'
     *
     * Block description for '<S411>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S412>/Delay Input1'
     *
     * Block description for '<S412>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S406>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S406>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S406>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S406>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S420>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1_b0;

    /* Update for UnitDelay: '<S420>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Sin4;

    /* Update for UnitDelay: '<S424>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S424>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_af = 0U;

    /* Update for UnitDelay: '<S424>/FixPt Unit Delay1' */
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
      rtb_Shooter_Active_prev = true;
    } else {
      rtb_Shooter_Active_prev = ((!Robot_Control_B.Button_Enable_Wheels) &&
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

    /* SignalConversion generated from: '<S16>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S16>/Constant10'
     */
    rtb_Auto_Initial_Gyro_Angle = 0.0;

    /* SignalConversion: '<S16>/Signal Copy' */
    rtb_Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* SignalConversion: '<S16>/Signal Copy2' */
    rtb_Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* SignalConversion: '<S16>/Signal Copy1' */
    rtb_Reset_Wheel_Offsets = Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_Shooter_Active_prev;

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
    rtb_Switch1_b0 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Switch1_b0;

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
    rtb_Subtract_c3 = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Switch1_b0);

    /* Product: '<S121>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S70>/C'
     *  Delay: '<S70>/MemoryX'
     *  Product: '<S123>/Product'
     */
    rtb_Switch1_b0 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Switch1_b0;

    /* Sum: '<S121>/Sum' incorporates:
     *  Constant: '<S70>/D'
     *  Product: '<S121>/C[k]*xhat[k|k-1]'
     *  Product: '<S121>/D[k]*u[k]'
     *  Sum: '<S121>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Switch1_b0);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S121>/Product3' incorporates:
     *  Constant: '<S71>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Subtract_c3) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S123>/Add1' incorporates:
     *  Product: '<S123>/Product'
     */
    rtb_Switch1_b0 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S121>/Product3' incorporates:
     *  Constant: '<S71>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Subtract_c3) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S123>/Add1' incorporates:
     *  Product: '<S123>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S123>/Product2' incorporates:
     *  Constant: '<S71>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Switch1_b0) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Switch1_b0) +
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
   *  Constant: '<S238>/Constant'
   *  Logic: '<S238>/AND'
   *  MATLAB Function: '<S188>/Find closest index to curve'
   *  Product: '<S238>/Product'
   *  RelationalOperator: '<S238>/Relational Operator'
   *  RelationalOperator: '<S238>/Relational Operator1'
   *  Selector: '<S238>/Selector'
   *  Selector: '<S238>/Selector1'
   *  Selector: '<S239>/Selector'
   *  Sum: '<S238>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S191>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_hk == 0) {
      /* Disable for If: '<S194>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S196>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_hk = -1;

    /* End of Disable for If: '<S191>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S186>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S186>/Unit Delay'
       *  UnitDelay: '<S187>/Unit Delay'
       *  UnitDelay: '<S189>/Unit Delay'
       *  UnitDelay: '<S189>/Unit Delay1'
       *  UnitDelay: '<S239>/Unit Delay'
       *  UnitDelay: '<S239>/Unit Delay1'
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
     *  ActionPort: '<S186>/Action Port'
     */
    /* Selector: '<S187>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S187>/Selector1' */

    /* Lookup_n-D: '<S186>/Capture Radius' incorporates:
     *  UnitDelay: '<S186>/Unit Delay'
     */
    rtb_Subtract_c3 = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S187>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S187>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S191>/If' incorporates:
     *  RelationalOperator: '<S191>/ '
     *  UnitDelay: '<S187>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_hk;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_hk = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S194>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S196>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S191>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S194>/Action Port'
       */
      /* InitializeConditions for If: '<S191>/If' incorporates:
       *  UnitDelay: '<S194>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S191>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S191>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S194>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S194>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S197>/Action Port'
       */
      /* If: '<S194>/If' incorporates:
       *  Selector: '<S187>/Selector1'
       *  Selector: '<S194>/Selector'
       *  Selector: '<S197>/Selector'
       */
      rtb_Switch2_p2 = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S194>/Increment_If_Rectangle_Check' */

      /* Sum: '<S194>/Minus' incorporates:
       *  Concatenate: '<S187>/Matrix Concatenate2'
       *  Selector: '<S194>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Switch2_p2;

      /* Outputs for IfAction SubSystem: '<S194>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S197>/Action Port'
       */
      /* If: '<S194>/If' incorporates:
       *  Selector: '<S187>/Selector1'
       *  Selector: '<S194>/Selector'
       *  Selector: '<S197>/Selector'
       *  Sum: '<S194>/Minus'
       */
      rtb_Modulation_Drv = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S194>/Increment_If_Rectangle_Check' */

      /* Sum: '<S194>/Minus' incorporates:
       *  Concatenate: '<S187>/Matrix Concatenate2'
       *  Selector: '<S194>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Modulation_Drv;

      /* Math: '<S194>/Hypot' */
      rtb_Switch1_b0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S194>/Equal' */
      rtb_AND1_c = (Robot_Control_B.Spline_Num_Poses ==
                    Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S194>/Switch' incorporates:
       *  Logic: '<S194>/AND'
       *  Logic: '<S194>/OR'
       *  RelationalOperator: '<S194>/Relational Operator'
       *  UnitDelay: '<S194>/Unit Delay'
       */
      rtb_Compare_ik = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
                        ((rtb_Switch1_b0 <= rtb_Subtract_c3) && rtb_AND1_c));

      /* If: '<S194>/If' */
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
        /* Disable for If: '<S196>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S194>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S196>/Action Port'
         */
        /* If: '<S196>/If' incorporates:
         *  RelationalOperator: '<S196>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S196>/Is_Last_Point' incorporates:
           *  ActionPort: '<S199>/Action Port'
           */
          /* InitializeConditions for If: '<S196>/If' incorporates:
           *  UnitDelay: '<S199>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S196>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S196>/Is_Last_Point' incorporates:
           *  ActionPort: '<S199>/Action Port'
           */
          /* Switch: '<S199>/Switch' incorporates:
           *  Constant: '<S201>/Constant'
           *  Logic: '<S199>/OR'
           *  RelationalOperator: '<S201>/Compare'
           *  UnitDelay: '<S199>/Unit Delay'
           */
          rtb_Is_Absolute_Steering = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
            (rtb_Switch1_b0 <= Spline_Stop_Radius));

          /* If: '<S199>/If' */
          if (rtb_Is_Absolute_Steering) {
            /* Outputs for IfAction SubSystem: '<S199>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S202>/Action Port'
             */
            /* Merge: '<S191>/Merge2' incorporates:
             *  Constant: '<S202>/Constant'
             *  SignalConversion generated from: '<S202>/Robot_Reached_Destination'
             */
            rtb_AND1_c = true;

            /* SignalConversion generated from: '<S202>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S202>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = false;

            /* End of Outputs for SubSystem: '<S199>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S199>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S203>/Action Port'
             */
            /* Merge: '<S191>/Merge2' incorporates:
             *  Constant: '<S203>/Constant'
             *  SignalConversion generated from: '<S203>/Robot_Reached_Destination'
             */
            rtb_AND1_c = false;

            /* SignalConversion generated from: '<S203>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S203>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = true;

            /* End of Outputs for SubSystem: '<S199>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S199>/If' */

          /* Merge: '<S191>/Merge4' incorporates:
           *  SignalConversion: '<S199>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S199>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Is_Absolute_Steering;

          /* End of Outputs for SubSystem: '<S196>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S196>/Increment_Search' incorporates:
           *  ActionPort: '<S198>/Action Port'
           */
          /* Merge: '<S191>/Merge2' incorporates:
           *  Constant: '<S198>/Constant'
           *  SignalConversion generated from: '<S198>/Robot_Reached_Destination'
           */
          rtb_AND1_c = false;

          /* SignalConversion generated from: '<S198>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S198>/Constant1'
           */
          rtb_Is_Absolute_Translation_g = false;

          /* Merge: '<S191>/Merge4' incorporates:
           *  Constant: '<S200>/FixPt Constant'
           *  SignalConversion: '<S198>/Signal Copy'
           *  Sum: '<S200>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S196>/Increment_Search' */
        }

        /* End of If: '<S196>/If' */
        /* End of Outputs for SubSystem: '<S194>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S194>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S197>/Action Port'
         */
        /* Sum: '<S204>/FixPt Sum1' incorporates:
         *  Constant: '<S204>/FixPt Constant'
         */
        rtb_Switch1_b0 = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S197>/Selector1' incorporates:
         *  Selector: '<S187>/Selector1'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Ref_Poses[((int32_T)rtb_Switch1_b0)
          - 1];

        /* Sum: '<S205>/Subtract' incorporates:
         *  Selector: '<S197>/Selector1'
         *  Sum: '<S205>/Minus1'
         */
        rtb_Minus_n[0] = rtb_MatrixConcatenate_b_idx_0 - rtb_Switch2_p2;

        /* Selector: '<S197>/Selector1' incorporates:
         *  Selector: '<S187>/Selector1'
         */
        rtb_DeadZone = rtb_Ref_Poses[((int32_T)rtb_Switch1_b0) + 9];

        /* Sum: '<S205>/Subtract' incorporates:
         *  Selector: '<S197>/Selector1'
         *  Sum: '<S205>/Minus1'
         */
        rtb_Minus_n[1] = rtb_DeadZone - rtb_Modulation_Drv;

        /* Math: '<S205>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S205>/Divide' */
        rtb_Switch1_b0 = rtb_Minus_n[1];

        /* UnaryMinus: '<S205>/Unary Minus' */
        rtb_Add1_l = rtb_Minus_n[0];

        /* Product: '<S205>/Product' incorporates:
         *  Product: '<S205>/Divide'
         *  UnaryMinus: '<S205>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch1_b0 / rtb_Sin4) * rtb_Subtract_c3;
        rtb_Minus_n[1] = ((-rtb_Add1_l) / rtb_Sin4) * rtb_Subtract_c3;

        /* Sum: '<S205>/Add1' incorporates:
         *  Sum: '<S205>/Add2'
         *  Sum: '<S205>/Minus'
         */
        rtb_Add1_l = rtb_MatrixConcatenate_b_idx_0 - rtb_Minus_n[0];

        /* Sum: '<S205>/Minus4' incorporates:
         *  Sum: '<S205>/Add2'
         *  Sum: '<S205>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = (rtb_MatrixConcatenate_b_idx_0 +
          rtb_Minus_n[0]) - rtb_Add1_l;

        /* Sum: '<S205>/Minus5' incorporates:
         *  Concatenate: '<S187>/Matrix Concatenate2'
         *  Sum: '<S205>/Minus'
         */
        rtb_Minus_k_idx_0 = rtb_Reshapey[0] - rtb_Add1_l;

        /* Sum: '<S205>/Add' incorporates:
         *  Sum: '<S205>/Add2'
         *  Sum: '<S205>/Minus1'
         */
        rtb_Switch1_b0 = rtb_Switch2_p2 - rtb_Minus_n[0];

        /* Sum: '<S205>/Minus' incorporates:
         *  Sum: '<S205>/Minus1'
         */
        rtb_Add1_l -= rtb_Switch1_b0;

        /* DotProduct: '<S205>/Dot Product' incorporates:
         *  Concatenate: '<S187>/Matrix Concatenate2'
         *  Sum: '<S205>/Minus'
         *  Sum: '<S205>/Minus1'
         *  Sum: '<S205>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Switch1_b0) * rtb_Add1_l;

        /* DotProduct: '<S205>/Dot Product1' incorporates:
         *  Sum: '<S205>/Minus'
         */
        rtb_Switch2_p2 = rtb_Add1_l * rtb_Add1_l;

        /* DotProduct: '<S205>/Dot Product2' incorporates:
         *  Sum: '<S205>/Minus4'
         *  Sum: '<S205>/Minus5'
         */
        rtb_Init = rtb_MatrixConcatenate_b_idx_0 * rtb_Minus_k_idx_0;

        /* DotProduct: '<S205>/Dot Product3' incorporates:
         *  Sum: '<S205>/Minus4'
         */
        rtb_Minus_k_idx_1 = rtb_MatrixConcatenate_b_idx_0 *
          rtb_MatrixConcatenate_b_idx_0;

        /* Sum: '<S205>/Add1' incorporates:
         *  Sum: '<S205>/Add2'
         *  Sum: '<S205>/Minus'
         */
        rtb_Add1_l = rtb_DeadZone - rtb_Minus_n[1];

        /* Sum: '<S205>/Minus4' incorporates:
         *  Sum: '<S205>/Add2'
         *  Sum: '<S205>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = (rtb_DeadZone + rtb_Minus_n[1]) -
          rtb_Add1_l;

        /* Sum: '<S205>/Minus5' incorporates:
         *  Concatenate: '<S187>/Matrix Concatenate2'
         *  Sum: '<S205>/Minus'
         */
        rtb_Minus_k_idx_0 = rtb_Reshapey[1] - rtb_Add1_l;

        /* Sum: '<S205>/Add' incorporates:
         *  Sum: '<S205>/Add2'
         *  Sum: '<S205>/Minus1'
         */
        rtb_Switch1_b0 = rtb_Modulation_Drv - rtb_Minus_n[1];

        /* Sum: '<S205>/Minus' incorporates:
         *  Sum: '<S205>/Minus1'
         */
        rtb_Add1_l -= rtb_Switch1_b0;

        /* DotProduct: '<S205>/Dot Product' incorporates:
         *  Concatenate: '<S187>/Matrix Concatenate2'
         *  Sum: '<S205>/Minus'
         *  Sum: '<S205>/Minus1'
         *  Sum: '<S205>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Switch1_b0) * rtb_Add1_l;

        /* RelationalOperator: '<S206>/Compare' incorporates:
         *  Constant: '<S206>/Constant'
         */
        rtb_AND1_c = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S205>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S205>/Dot Product1'
         *  Sum: '<S205>/Minus'
         */
        rtb_Is_Absolute_Translation_g = (rtb_Sin4 <= ((rtb_Add1_l * rtb_Add1_l)
          + rtb_Switch2_p2));

        /* DotProduct: '<S205>/Dot Product2' incorporates:
         *  Sum: '<S205>/Minus4'
         *  Sum: '<S205>/Minus5'
         */
        rtb_Sin4 = (rtb_MatrixConcatenate_b_idx_0 * rtb_Minus_k_idx_0) +
          rtb_Init;

        /* Merge: '<S191>/Merge4' incorporates:
         *  Constant: '<S207>/Constant'
         *  DataTypeConversion: '<S197>/Data Type Conversion'
         *  DotProduct: '<S205>/Dot Product3'
         *  Logic: '<S205>/AND'
         *  RelationalOperator: '<S205>/LessThanOrEqual1'
         *  RelationalOperator: '<S207>/Compare'
         *  Sum: '<S197>/Add'
         *  Sum: '<S205>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_AND1_c &&
          rtb_Is_Absolute_Translation_g) && (rtb_Sin4 >= 0.0)) && (rtb_Sin4 <=
          ((rtb_MatrixConcatenate_b_idx_0 * rtb_MatrixConcatenate_b_idx_0) +
           rtb_Minus_k_idx_1)))) + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S191>/Merge2' incorporates:
         *  Constant: '<S197>/Constant2'
         *  SignalConversion generated from: '<S197>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S197>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S197>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* End of Outputs for SubSystem: '<S194>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S194>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S195>/Action Port'
         */
        /* Merge: '<S191>/Merge2' incorporates:
         *  Constant: '<S195>/Constant2'
         *  SignalConversion generated from: '<S195>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S195>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S195>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* Merge: '<S191>/Merge4' incorporates:
         *  SignalConversion generated from: '<S195>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S194>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S191>/Merge1' incorporates:
       *  Constant: '<S194>/Constant'
       *  SignalConversion generated from: '<S194>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S194>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_Compare_ik;

      /* End of Outputs for SubSystem: '<S191>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S191>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S193>/Action Port'
       */
      /* Merge: '<S191>/Merge1' incorporates:
       *  Constant: '<S193>/Constant'
       *  SignalConversion generated from: '<S193>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S191>/Merge2' incorporates:
       *  Constant: '<S193>/Constant1'
       *  SignalConversion generated from: '<S193>/Robot_Reached_Destination'
       */
      rtb_AND1_c = false;

      /* SignalConversion generated from: '<S193>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S193>/Constant2'
       */
      rtb_Is_Absolute_Translation_g = false;

      /* Merge: '<S191>/Merge4' incorporates:
       *  SignalConversion generated from: '<S193>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S191>/Escape_Auto_Driving' */
    }

    /* End of If: '<S191>/If' */

    /* If: '<S187>/If1' */
    if (!rtb_Is_Absolute_Translation_g) {
      /* Outputs for IfAction SubSystem: '<S187>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S192>/Action Port'
       */
      /* Bias: '<S208>/Add Constant' incorporates:
       *  Bias: '<S208>/Bias'
       *  Sum: '<S208>/Subtract'
       */
      rtb_Switch1_b0 = ((Robot_Control_B.Spline_Num_Poses -
                         Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S208>/Selector4' incorporates:
       *  Bias: '<S208>/Bias1'
       *  Constant: '<S210>/FixPt Constant'
       *  Sum: '<S210>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S208>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S208>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s213_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S208>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S208>/Selector5' incorporates:
       *  Concatenate: '<S208>/Matrix Concatenate'
       *  Gain: '<S212>/Gain'
       *  Selector: '<S187>/Selector1'
       *  Selector: '<S208>/Selector2'
       *  Selector: '<S208>/Selector3'
       *  Sum: '<S212>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s213_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S208>/Matrix Concatenate' incorporates:
       *  Bias: '<S208>/Add Constant1'
       *  Gain: '<S211>/Gain'
       *  Selector: '<S187>/Selector1'
       *  Selector: '<S208>/Selector'
       *  Selector: '<S208>/Selector1'
       *  Selector: '<S208>/Selector5'
       *  Sum: '<S211>/Subtract'
       */
      s213_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s213_iter;
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

      /* Selector: '<S208>/Selector4' */
      s213_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s213_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S208>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S208>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S208>/Assignment' incorporates:
       *  Concatenate: '<S208>/Matrix Concatenate'
       *  Selector: '<S208>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s213_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S209>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S213>/While Iterator'
       */
      s213_iter = 1;
      do {
        rtb_Switch2_p2 = rtb_Assignment[s213_iter + 1];
        rtb_Minus_n[0] = rtb_Switch2_p2 - rtb_Assignment[s213_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s213_iter] - rtb_Assignment[s213_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Switch2_p2 - rtb_Assignment[s213_iter];
        rtb_Switch2_p2 = rtb_Assignment[s213_iter + 13];
        rtb_Minus_n[1] = rtb_Switch2_p2 - rtb_Assignment[s213_iter + 11];
        rtb_Add1_l = rtb_Assignment[s213_iter + 12];
        rtb_Add2[1] = rtb_Add1_l - rtb_Assignment[s213_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Switch2_p2 - rtb_Add1_l;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Sin4 = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Modulation_Drv = rt_powd_snf(rtb_Sin4, 2.0);
          rtb_Switch2_p2 = rt_powd_snf(rtb_Sin4, 3.0);
          rtb_DeadZone = (rtb_Sin4 - (2.0 * rtb_Modulation_Drv)) +
            rtb_Switch2_p2;
          rtb_Init = rtb_Modulation_Drv - rtb_Switch2_p2;
          rtb_Switch2_p2 = (3.0 * rtb_Modulation_Drv) - (2.0 * rtb_Switch2_p2);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_DeadZone) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Switch2_p2)) + rtb_Assignment[s213_iter];
          rtb_Switch2_p2 = ((((rtb_Minus_n[1] * rtb_DeadZone) + (rtb_Add2[1] *
            rtb_Init)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_p2)) +
            rtb_Add1_l;
          rtb_DeadZone = ((3.0 * rtb_Modulation_Drv) - (4.0 * rtb_Sin4)) + 1.0;
          rtb_Init = (2.0 * rtb_Sin4) - (3.0 * rtb_Modulation_Drv);
          rtb_Modulation_Drv = (rtb_Sin4 - rtb_Modulation_Drv) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_DeadZone) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Modulation_Drv);
          rtb_Hypot_g5 = (((rtb_Minus_n[1] * rtb_DeadZone) + (rtb_Add2[1] *
            rtb_Init)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Modulation_Drv);
          rtb_Modulation_Drv = (6.0 * rtb_Sin4) - 4.0;
          rtb_DeadZone = (-6.0 * rtb_Sin4) + 2.0;
          rtb_Sin4 = (-12.0 * rtb_Sin4) + 6.0;
          rtb_Init = (((rtb_Minus_n[0] * rtb_Modulation_Drv) + (rtb_Add2[0] *
            rtb_DeadZone)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Sin4);
          rtb_DeadZone = (((rtb_Minus_n[1] * rtb_Modulation_Drv) + (rtb_Add2[1] *
            rtb_DeadZone)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Sin4);
          rtb_Modulation_Drv = rt_powd_snf(rt_hypotd_snf
            (rtb_MatrixConcatenate_idx_0, rtb_Hypot_g5), 3.0);
          rtb_Sin4 = fmax(1.0E-10, rtb_Modulation_Drv);
          Robot_Control_DW.Relay_Mode = ((rtb_Modulation_Drv >=
            2.2204460492503131E-16) || (Robot_Control_DW.Relay_Mode));
          if (Robot_Control_DW.Relay_Mode) {
            rtb_Modulation_Drv = 1.0;
          } else {
            rtb_Modulation_Drv = -1.0;
          }

          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Switch2_p2;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_DeadZone) - (rtb_Init *
              rtb_Hypot_g5)) / (rtb_Sin4 * rtb_Modulation_Drv);
        }

        if (s213_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s213_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Switch1_b0 - ((real_T)s213_iter);
        rtb_Num_Segments = s213_iter;
        s213_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s213_iter <= 3));

      /* End of Outputs for SubSystem: '<S209>/Sampling_Loop' */

      /* SignalConversion generated from: '<S192>/Position_and_Curvature' incorporates:
       *  Assignment: '<S213>/Assignment'
       *  Merge: '<S187>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S187>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem' incorporates:
       *  ActionPort: '<S190>/Action Port'
       */
      /* Product: '<S190>/Product' incorporates:
       *  Selector: '<S187>/Selector'
       *  Selector: '<S187>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1];

      /* Product: '<S190>/Product1' incorporates:
       *  Selector: '<S187>/Selector'
       *  Selector: '<S187>/Selector1'
       */
      rtb_Switch1_b0 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S190>/Product' incorporates:
         *  Constant: '<S190>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S190>/Product1' incorporates:
         *  Constant: '<S190>/Constant2'
         *  Product: '<S190>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch1_b0;
      }

      /* Assignment: '<S190>/Assignment' incorporates:
       *  Concatenate: '<S190>/Matrix Concatenate'
       *  Merge: '<S187>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S190>/Assignment' */

      /* SignalConversion generated from: '<S190>/Num_Segments' incorporates:
       *  Constant: '<S190>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S187>/If Action Subsystem' */
    }

    /* End of If: '<S187>/If1' */

    /* Concatenate: '<S188>/Matrix Concatenate' incorporates:
     *  Merge: '<S187>/Merge'
     *  Selector: '<S188>/Selector'
     *  Selector: '<S188>/Selector1'
     *  Selector: '<S188>/Selector3'
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

    /* End of Concatenate: '<S188>/Matrix Concatenate' */

    /* MATLAB Function: '<S188>/Distance Along Curve' incorporates:
     *  Concatenate: '<S188>/Matrix Concatenate'
     *  Selector: '<S188>/Selector4'
     *  Selector: '<S188>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s213_iter = 0; s213_iter < 149; s213_iter++) {
      /* Outputs for Iterator SubSystem: '<S209>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S213>/While Iterator'
       */
      rtb_Assignment_d[s213_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s213_iter + 1] -
         rtb_MatrixConcatenate_o[s213_iter], rtb_MatrixConcatenate_o[s213_iter +
         151] - rtb_MatrixConcatenate_o[s213_iter + 150]) +
        rtb_Assignment_d[s213_iter];

      /* End of Outputs for SubSystem: '<S209>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S188>/Distance Along Curve' */

    /* MATLAB Function: '<S188>/Find closest index to curve' incorporates:
     *  Concatenate: '<S188>/Matrix Concatenate'
     *  Selector: '<S188>/Selector4'
     *  Selector: '<S188>/Selector5'
     *  Selector: '<S239>/Selector'
     */
    for (s213_iter = 0; s213_iter < 150; s213_iter++) {
      /* Outputs for Iterator SubSystem: '<S209>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S213>/While Iterator'
       */
      distance_from_robot[s213_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s213_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s213_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S209>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s213_iter = 1;
    } else {
      s213_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s213_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s213_iter == 0) {
      rtb_Switch1_b0 = distance_from_robot[0];
    } else {
      rtb_Switch1_b0 = distance_from_robot[s213_iter - 1];
      for (rtb_Bias1_p = s213_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_b0 > rtb_Sin4) {
          rtb_Switch1_b0 = rtb_Sin4;
        }
      }
    }

    s213_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s213_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_b0) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S239>/Selector' incorporates:
     *  Constant: '<S239>/Constant'
     *  MATLAB Function: '<S188>/Find closest index to curve'
     *  MinMax: '<S239>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s213_iter)) - 1];

    /* If: '<S239>/If' incorporates:
     *  RelationalOperator: '<S239>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S239>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S242>/Action Port'
       */
      /* SignalConversion generated from: '<S242>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S244>/FixPt Sum1' incorporates:
       *  Constant: '<S244>/FixPt Constant'
       */
      rtb_Switch1_b0 = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S242>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S242>/Selector11'
       *  Selector: '<S242>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_b0) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S242>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S242>/Selector1'
       *  Selector: '<S242>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_b0) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S242>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S242>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_b0), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S242>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S242>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S242>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S239>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S239>/Latch' incorporates:
       *  ActionPort: '<S243>/Action Port'
       */
      /* SignalConversion generated from: '<S243>/In1' incorporates:
       *  UnitDelay: '<S239>/Unit Delay1'
       */
      rtb_Switch1_b0 = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S243>/In2' incorporates:
       *  UnitDelay: '<S239>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S239>/Latch' */
    }

    /* End of If: '<S239>/If' */

    /* MinMax: '<S186>/Min' incorporates:
     *  Lookup_n-D: '<S186>/Lookahead Distance'
     *  UnitDelay: '<S186>/Unit Delay'
     */
    rtb_Subtract_c3 = fmin(rtb_Subtract_c3, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S188>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S238>/While Iterator'
     */
    s238_iter = 1U;
    rtb_Compare_ik = true;
    while (rtb_Compare_ik && (s238_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S188>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S238>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s238_iter;
      rtb_Compare_ik = ((rtb_Assignment_d[Robot_Control_B.WhileIterator - 1] <=
                         (rtb_Assignment_d[s213_iter - 1] + rtb_Subtract_c3)) &&
                        (Robot_Control_B.WhileIterator < (((real_T)
        rtb_Num_Segments) * 50.0)));
      s238_iter++;
    }

    /* End of Outputs for SubSystem: '<S188>/Find first index that meets distance target' */

    /* Switch: '<S241>/Switch' incorporates:
     *  Concatenate: '<S188>/Matrix Concatenate'
     *  Constant: '<S188>/Constant'
     *  Constant: '<S238>/Constant'
     *  Constant: '<S241>/Constant'
     *  Constant: '<S241>/Constant1'
     *  Constant: '<S241>/Constant2'
     *  Constant: '<S241>/Constant3'
     *  Logic: '<S238>/AND'
     *  MATLAB Function: '<S188>/Find closest index to curve'
     *  Math: '<S241>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S241>/Max'
     *  MinMax: '<S241>/Min'
     *  MinMax: '<S241>/Min1'
     *  Product: '<S238>/Product'
     *  Product: '<S241>/Divide'
     *  Product: '<S241>/Product'
     *  Product: '<S241>/Product1'
     *  RelationalOperator: '<S188>/Relational Operator'
     *  RelationalOperator: '<S238>/Relational Operator'
     *  RelationalOperator: '<S238>/Relational Operator1'
     *  Selector: '<S188>/Selector10'
     *  Selector: '<S188>/Selector7'
     *  Selector: '<S188>/Selector8'
     *  Selector: '<S188>/Selector9'
     *  Selector: '<S238>/Selector'
     *  Selector: '<S238>/Selector1'
     *  Selector: '<S239>/Selector'
     *  Sqrt: '<S241>/Sqrt'
     *  Sum: '<S188>/Subtract'
     *  Sum: '<S238>/Add'
     *  Sum: '<S241>/Subtract'
     *  Sum: '<S241>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Subtract_c3 = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Switch1_b0 *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Subtract_c3 = fmin(rtb_Switch1_b0 * Spline_Velocity_Multiplier_TEST,
        sqrt(Spline_Max_Centripital_Acceleration / fmax
             (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299],
              1.0E-5)));
    }

    /* End of Switch: '<S241>/Switch' */

    /* Logic: '<S189>/OR' */
    rtb_Is_Absolute_Translation_g = (rtb_AND1_c ||
      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S189>/Switch1' incorporates:
     *  Switch: '<S189>/Switch'
     *  UnitDelay: '<S189>/Unit Delay'
     */
    if (rtb_Is_Absolute_Translation_g) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S189>/Constant3'
       *  SignalConversion: '<S189>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S189>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Subtract_c3;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S189>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S189>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S188>/Selector6' incorporates:
     *  Concatenate: '<S188>/Matrix Concatenate'
     *  Selector: '<S188>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S188>/Selector2' incorporates:
     *  Concatenate: '<S188>/Matrix Concatenate'
     *  Selector: '<S188>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S189>/Switch2' incorporates:
     *  Sum: '<S245>/Subtract'
     *  Sum: '<S245>/Subtract1'
     *  Trigonometry: '<S245>/Atan2'
     *  UnitDelay: '<S189>/Unit Delay1'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_Modulation_Drv = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Modulation_Drv = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S189>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S189>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Modulation_Drv;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S186>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_AND1_c;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S186>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S189>/Constant2'
     *  SignalConversion generated from: '<S186>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S189>/Constant5'
     *  SignalConversion generated from: '<S186>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S189>/Constant6'
     *  SignalConversion generated from: '<S186>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S186>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S187>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S186>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S239>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_b0;

    /* Update for UnitDelay: '<S239>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S189>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S189>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Modulation_Drv;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S185>/Constant1'
     *  SignalConversion generated from: '<S185>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S185>/Constant'
     *  SignalConversion generated from: '<S185>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S185>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S185>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S185>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S185>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S185>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S185>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S185>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S335>/Sign2' incorporates:
   *  UnitDelay: '<S335>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S335>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S335>/Product1' incorporates:
   *  Signum: '<S335>/Sign1'
   *  Signum: '<S335>/Sign2'
   */
  rtb_Add_a5 *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_a5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_a5, 256.0);
  }

  /* Switch: '<S335>/Switch' incorporates:
   *  Constant: '<S335>/Constant'
   *  Constant: '<S340>/Constant'
   *  Constant: '<S341>/Constant'
   *  Logic: '<S335>/or'
   *  Product: '<S335>/Product1'
   *  RelationalOperator: '<S340>/Compare'
   *  RelationalOperator: '<S341>/Compare'
   *  UnitDelay: '<S335>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S335>/Switch' */

  /* Switch: '<S346>/Init' incorporates:
   *  UnitDelay: '<S346>/FixPt Unit Delay1'
   *  UnitDelay: '<S346>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_ob != 0) {
    rtb_Subtract_c3 = rtb_Sin4;
  } else {
    rtb_Subtract_c3 = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S346>/Init' */

  /* RelationalOperator: '<S342>/Compare' incorporates:
   *  Constant: '<S342>/Constant'
   */
  rtb_Compare_ik = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S343>/Compare' incorporates:
   *  Constant: '<S343>/Constant'
   */
  rtb_AND1_c = (rtb_Sin4 > 0.0);

  /* Abs: '<S335>/Abs' incorporates:
   *  Sum: '<S335>/Subtract'
   *  UnitDelay: '<S335>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S335>/Switch5' incorporates:
   *  Constant: '<S335>/Constant1'
   *  Switch: '<S335>/Switch1'
   *  UnaryMinus: '<S335>/Unary Minus'
   */
  if (rtb_Compare_ik) {
    /* SignalConversion generated from: '<S335>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S335>/Constant4'
     *  Constant: '<S335>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S335>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S335>/Constant2'
     *  Constant: '<S335>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S335>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S335>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S335>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S335>/Constant10'
     *  Constant: '<S335>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S335>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S335>/Constant7'
     *  Constant: '<S335>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S335>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S335>/Lookup Table Dynamic1'
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

    /* Switch: '<S335>/Switch3' incorporates:
     *  Constant: '<S335>/Constant1'
     *  Constant: '<S335>/Constant3'
     *  UnaryMinus: '<S335>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_a5 = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_a5 = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S335>/Switch3' */
  }

  /* End of Switch: '<S335>/Switch5' */

  /* Product: '<S335>/Product' incorporates:
   *  Switch: '<S335>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_a5 * rtb_Merge1;

  /* Sum: '<S344>/Sum1' */
  rtb_Switch1_b0 = rtb_Sin4 - rtb_Subtract_c3;

  /* Switch: '<S345>/Switch2' incorporates:
   *  RelationalOperator: '<S345>/LowerRelop1'
   */
  if (!(rtb_Switch1_b0 > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S335>/Switch2' incorporates:
     *  Constant: '<S335>/Constant1'
     *  Switch: '<S335>/Switch4'
     */
    if (rtb_Compare_ik) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S335>/Switch4' incorporates:
       *  Constant: '<S335>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S335>/Switch4' incorporates:
       *  Constant: '<S335>/Constant3'
       *  UnaryMinus: '<S335>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S335>/Switch2' */

    /* Product: '<S335>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S345>/Switch' incorporates:
     *  RelationalOperator: '<S345>/UpperRelop'
     */
    if (rtb_Switch1_b0 < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch1_b0;
    }

    /* End of Switch: '<S345>/Switch' */
  }

  /* End of Switch: '<S345>/Switch2' */

  /* Sum: '<S344>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle +
    rtb_Subtract_c3;

  /* Switch: '<S338>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S338>/Switch' incorporates:
     *  Constant: '<S371>/Constant3'
     *  Constant: '<S371>/Constant4'
     *  Math: '<S371>/Math Function'
     *  Sum: '<S338>/Subtract'
     *  Sum: '<S371>/Add1'
     *  Sum: '<S371>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S338>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S338>/Switch' */

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
      Robot_Control_DW.UnitDelay_DSTATE_ll = Rebuilt_Match_Time_Auto_Timer;

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
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_ll - 0.02;

    /* Merge: '<S130>/Merge2' incorporates:
     *  SignalConversion: '<S162>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S162>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ll = rtb_Merge1;

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
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_n - 0.02;

    /* Merge: '<S130>/Merge2' incorporates:
     *  SignalConversion: '<S167>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S167>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S130>/If' */

  /* If: '<S169>/If' incorporates:
   *  If: '<S170>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S169>/Blue' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    /* Merge: '<S169>/Merge' incorporates:
     *  Constant: '<S171>/BlueAllianceZoneX'
     *  Logic: '<S171>/AND'
     *  RelationalOperator: '<S171>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S169>/Blue' */

    /* Outputs for IfAction SubSystem: '<S170>/Blue' incorporates:
     *  ActionPort: '<S173>/Action Port'
     */
    /* Merge: '<S170>/Merge' incorporates:
     *  Constant: '<S173>/BlueAllianceZoneX'
     *  RelationalOperator: '<S173>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S170>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S169>/Red' incorporates:
     *  ActionPort: '<S172>/Action Port'
     */
    /* Merge: '<S169>/Merge' incorporates:
     *  Constant: '<S172>/RedAllianceZoneX'
     *  Logic: '<S172>/AND'
     *  RelationalOperator: '<S172>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S169>/Red' */

    /* Outputs for IfAction SubSystem: '<S170>/Red' incorporates:
     *  ActionPort: '<S174>/Action Port'
     */
    /* Merge: '<S170>/Merge' incorporates:
     *  Constant: '<S174>/RedAllianceZoneX'
     *  RelationalOperator: '<S174>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S170>/Red' */
  }

  /* End of If: '<S169>/If' */

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
   *  Constant: '<S168>/Constant3'
   *  Constant: '<S168>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S168>/Math Function'
   *  Sum: '<S132>/Subtract'
   *  Sum: '<S168>/Add1'
   *  Sum: '<S168>/Add2'
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
  rtb_Compare_ik = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S132>/AND2' incorporates:
   *  Logic: '<S132>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_ik);

  /* SignalConversion: '<S132>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S132>/AND3' */
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
        if (rtb_Is_Absolute_Translation_g) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
          Robot_Control_B.RB_Transfer_Init = 1.0;
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
        } else if (rtb_Is_Absolute_Translation_g) {
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
    rtb_Subtract_c3 = 0.0;
    rtb_Switch1_b0 = 0.0;
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
      /* Switch: '<S149>/Switch' incorporates:
       *  Memory: '<S140>/Memory1'
       *  Memory: '<S140>/Memory2'
       *  Switch: '<S149>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_Modulation_Drv = rtb_Subtract_c3;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Modulation_Drv = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S149>/Switch' */

      /* Math: '<S147>/Hypot' incorporates:
       *  Sum: '<S147>/Subtract'
       *  Sum: '<S147>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_Modulation_Drv -
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
      rtb_Merge1 = rtb_TOF - rtb_Switch1_b0;

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
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Modulation_Drv;

      /* Memory: '<S140>/Memory' */
      rtb_Compare_ik = rtb_Button_Spinup_Enable;

      /* Update for Memory: '<S140>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S140>/Memory2' */
      rtb_Subtract_c3 = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S140>/Memory3' */
      rtb_Switch1_b0 = rtb_TOF;

      /* Update for Memory: '<S140>/Memory' incorporates:
       *  Constant: '<S152>/Constant'
       *  Math: '<S151>/Hypot'
       *  RelationalOperator: '<S152>/Compare'
       *  Sum: '<S151>/Subtract'
       *  Sum: '<S151>/Subtract1'
       */
      rtb_Button_Spinup_Enable = (rt_hypotd_snf
        (Robot_Control_B.RB_Desired_Target_X - rtb_Sin4,
         Robot_Control_B.RB_Desired_Target_Y - rtb_Modulation_Drv) >=
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
    rtb_Add_a5 = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

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
     *  Merge: '<S129>/Merge'
     *  Merge: '<S129>/Merge1'
     *  Merge: '<S129>/Merge2'
     *  Merge: '<S129>/Merge3'
     *  SignalConversion generated from: '<S137>/Desired_Gyro_Angle'
     *  UnitDelay: '<S129>/Unit Delay'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot =
      Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S129>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_a5 = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S366>/Add1' incorporates:
   *  Constant: '<S366>/Constant3'
   *  Constant: '<S366>/Constant4'
   *  Math: '<S366>/Math Function'
   *  Sum: '<S365>/Sum'
   *  Sum: '<S366>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Add1_l = rt_modd_snf((rtb_Add_a5 - rtb_Minus_k_idx_1) + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S368>/Sum1' incorporates:
   *  Constant: '<S365>/Constant2'
   *  Product: '<S368>/Product'
   *  Sum: '<S368>/Sum'
   *  UnitDelay: '<S368>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Add1_l - Robot_Control_DW.UnitDelay1_DSTATE) *
    Steering_Heading_Control_D_FilterCoeff) + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S365>/Product' incorporates:
   *  Constant: '<S365>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S367>/Diff' incorporates:
   *  UnitDelay: '<S367>/UD'
   *
   * Block description for '<S367>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S367>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S365>/Saturation' */
  if (rtb_Add_a5 > Steering_Heading_Control_D_UL) {
    rtb_Add_a5 = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Heading_Control_D_LL) {
    rtb_Add_a5 = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S365>/Add' incorporates:
   *  Gain: '<S365>/Gain1'
   *  Saturate: '<S365>/Saturation'
   */
  rtb_Switch1_b0 = (Steering_Heading_Control_P * rtb_Add1_l) + rtb_Add_a5;

  /* Sum: '<S365>/Subtract' incorporates:
   *  Constant: '<S365>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Switch1_b0;

  /* Sum: '<S365>/Sum2' incorporates:
   *  Gain: '<S365>/Gain2'
   *  UnitDelay: '<S365>/Unit Delay'
   */
  rtb_Subtract_c3 = (Steering_Heading_Control_I * rtb_Add1_l) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S370>/Switch2' incorporates:
   *  RelationalOperator: '<S370>/LowerRelop1'
   */
  if (!(rtb_Subtract_c3 > rtb_Sin4)) {
    /* Sum: '<S365>/Subtract1' incorporates:
     *  Constant: '<S365>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Switch1_b0;

    /* Switch: '<S370>/Switch' incorporates:
     *  RelationalOperator: '<S370>/UpperRelop'
     */
    if (!(rtb_Subtract_c3 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Subtract_c3;
    }

    /* End of Switch: '<S370>/Switch' */
  }

  /* End of Switch: '<S370>/Switch2' */

  /* Saturate: '<S365>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_LL;
  } else {
    rtb_Subtract_c3 = rtb_Sin4;
  }

  /* End of Saturate: '<S365>/Saturation1' */

  /* Sum: '<S365>/Add1' */
  rtb_Add_a5 = rtb_Switch1_b0 + rtb_Subtract_c3;

  /* Saturate: '<S365>/Saturation2' */
  if (rtb_Add_a5 > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S365>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_a5 < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S365>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S365>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_a5;
  }

  /* End of Saturate: '<S365>/Saturation2' */

  /* Switch: '<S349>/Switch' incorporates:
   *  Abs: '<S349>/Abs'
   *  Constant: '<S349>/Constant'
   *  Constant: '<S364>/Constant'
   *  RelationalOperator: '<S364>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Sin4 = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S349>/Switch' */

  /* Signum: '<S348>/Sign2' incorporates:
   *  UnitDelay: '<S348>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S348>/Sign1' */
  if (rtIsNaN(rtb_Sin4)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Sin4 < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Sin4 > 0.0);
  }

  /* Product: '<S348>/Product1' incorporates:
   *  Signum: '<S348>/Sign1'
   *  Signum: '<S348>/Sign2'
   */
  rtb_Add_a5 *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_a5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_a5, 256.0);
  }

  /* Switch: '<S348>/Switch' incorporates:
   *  Constant: '<S348>/Constant'
   *  Constant: '<S357>/Constant'
   *  Constant: '<S358>/Constant'
   *  Logic: '<S348>/or'
   *  Product: '<S348>/Product1'
   *  RelationalOperator: '<S357>/Compare'
   *  RelationalOperator: '<S358>/Compare'
   *  UnitDelay: '<S348>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Sin4;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S348>/Switch' */

  /* Switch: '<S363>/Init' incorporates:
   *  UnitDelay: '<S363>/FixPt Unit Delay1'
   *  UnitDelay: '<S363>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
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

  /* Abs: '<S348>/Abs' incorporates:
   *  Sum: '<S348>/Subtract'
   *  UnitDelay: '<S348>/Unit Delay'
   */
  rtb_Switch1_b0 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d - rtb_Sin4);

  /* Switch: '<S348>/Switch5' incorporates:
   *  Constant: '<S348>/Constant1'
   *  Switch: '<S348>/Switch1'
   *  UnaryMinus: '<S348>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    /* SignalConversion generated from: '<S348>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S348>/Constant4'
     *  Constant: '<S348>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S348>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S348>/Constant2'
     *  Constant: '<S348>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S348>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S348>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Reshapey[0],
                         rtb_Switch1_b0, &rtb_Minus_n[0], 1U);
    rtb_Switch1_b0 = rtb_LookupTableDynamic;
    rtb_Add_a5 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S348>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S348>/Constant10'
     *  Constant: '<S348>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S348>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S348>/Constant7'
     *  Constant: '<S348>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S348>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S348>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Reshapey[0],
                         rtb_Switch1_b0, &rtb_Minus_n[0], 1U);
    rtb_Switch1_b0 = rtb_LookupTableDynamic1;

    /* Switch: '<S348>/Switch3' incorporates:
     *  Constant: '<S348>/Constant1'
     *  Constant: '<S348>/Constant3'
     *  UnaryMinus: '<S348>/Unary Minus'
     */
    if (rtb_Button_Shoot_Enable) {
      rtb_Add_a5 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_a5 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S348>/Switch3' */
  }

  /* End of Switch: '<S348>/Switch5' */

  /* Product: '<S348>/Product' incorporates:
   *  Switch: '<S348>/Switch1'
   */
  rtb_Switch2_p2 = rtb_Add_a5 * rtb_Switch1_b0;

  /* Sum: '<S361>/Sum1' */
  rtb_Sin4 = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S362>/Switch2' incorporates:
   *  RelationalOperator: '<S362>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Switch2_p2)) {
    /* Switch: '<S348>/Switch2' incorporates:
     *  Constant: '<S348>/Constant1'
     *  Switch: '<S348>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Modulation_Drv = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S348>/Switch4' incorporates:
       *  Constant: '<S348>/Constant1'
       */
      rtb_Modulation_Drv = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S348>/Switch4' incorporates:
       *  Constant: '<S348>/Constant3'
       *  UnaryMinus: '<S348>/Unary Minus1'
       */
      rtb_Modulation_Drv = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S348>/Switch2' */

    /* Product: '<S348>/Product2' */
    rtb_Modulation_Drv *= rtb_Switch1_b0;

    /* Switch: '<S362>/Switch' incorporates:
     *  RelationalOperator: '<S362>/UpperRelop'
     */
    if (rtb_Sin4 < rtb_Modulation_Drv) {
      rtb_Switch2_p2 = rtb_Modulation_Drv;
    } else {
      rtb_Switch2_p2 = rtb_Sin4;
    }

    /* End of Switch: '<S362>/Switch' */
  }

  /* End of Switch: '<S362>/Switch2' */

  /* Sum: '<S361>/Sum' */
  rtb_Switch1_b0 = rtb_Switch2_p2 + rtb_Optimized_Module_Angle_p;

  /* Signum: '<S347>/Sign2' incorporates:
   *  UnitDelay: '<S347>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S347>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S347>/Product1' incorporates:
   *  Signum: '<S347>/Sign1'
   *  Signum: '<S347>/Sign2'
   */
  rtb_Add_a5 *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_a5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_a5, 256.0);
  }

  /* Switch: '<S347>/Switch' incorporates:
   *  Constant: '<S347>/Constant'
   *  Constant: '<S350>/Constant'
   *  Constant: '<S351>/Constant'
   *  Logic: '<S347>/or'
   *  Product: '<S347>/Product1'
   *  RelationalOperator: '<S350>/Compare'
   *  RelationalOperator: '<S351>/Compare'
   *  UnitDelay: '<S347>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S347>/Switch' */

  /* Switch: '<S356>/Init' incorporates:
   *  UnitDelay: '<S356>/FixPt Unit Delay1'
   *  UnitDelay: '<S356>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S356>/Init' */

  /* RelationalOperator: '<S352>/Compare' incorporates:
   *  Constant: '<S352>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S353>/Compare' incorporates:
   *  Constant: '<S353>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S347>/Abs' incorporates:
   *  Sum: '<S347>/Subtract'
   *  UnitDelay: '<S347>/Unit Delay'
   */
  rtb_Modulation_Drv = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
    Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S347>/Switch1' incorporates:
   *  Constant: '<S347>/Constant1'
   *  Switch: '<S347>/Switch3'
   *  Switch: '<S347>/Switch5'
   *  UnaryMinus: '<S347>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S347>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S347>/Constant1'
     *  Constant: '<S347>/Constant4'
     *  Constant: '<S347>/Constant6'
     *  UnaryMinus: '<S347>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S347>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S347>/Constant2'
     *  Constant: '<S347>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S347>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S347>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_Modulation_Drv, &rtb_Minus_n[0], 1U);
    rtb_Modulation_Drv = rtb_LookupTableDynamic_p;
  } else {
    if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S347>/Switch3' incorporates:
       *  Constant: '<S347>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S347>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S347>/Constant1'
     *  Constant: '<S347>/Constant10'
     *  Constant: '<S347>/Constant8'
     *  UnaryMinus: '<S347>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S347>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S347>/Constant7'
     *  Constant: '<S347>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S347>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S347>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_Modulation_Drv, &rtb_Minus_n[0], 1U);
    rtb_Modulation_Drv = rtb_LookupTableDynamic1_g;
  }

  /* End of Switch: '<S347>/Switch1' */

  /* Product: '<S347>/Product' */
  rtb_Sin4 *= rtb_Modulation_Drv;

  /* Sum: '<S354>/Sum1' */
  rtb_DeadZone = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S355>/Switch2' incorporates:
   *  RelationalOperator: '<S355>/LowerRelop1'
   */
  if (!(rtb_DeadZone > rtb_Sin4)) {
    /* Switch: '<S347>/Switch2' incorporates:
     *  Constant: '<S347>/Constant1'
     *  Switch: '<S347>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S347>/Switch4' incorporates:
       *  Constant: '<S347>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S347>/Switch4' incorporates:
       *  Constant: '<S347>/Constant3'
       *  UnaryMinus: '<S347>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S347>/Switch2' */

    /* Product: '<S347>/Product2' */
    rtb_Sin4 *= rtb_Modulation_Drv;

    /* Switch: '<S355>/Switch' incorporates:
     *  RelationalOperator: '<S355>/UpperRelop'
     */
    if (!(rtb_DeadZone < rtb_Sin4)) {
      rtb_Sin4 = rtb_DeadZone;
    }

    /* End of Switch: '<S355>/Switch' */
  }

  /* End of Switch: '<S355>/Switch2' */

  /* Sum: '<S354>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S337>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S337>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch1_b0;
  } else {
    /* Switch: '<S337>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S337>/Switch' */

  /* Fcn: '<S379>/r->x' incorporates:
   *  Fcn: '<S384>/r->x'
   *  Fcn: '<S389>/r->x'
   *  Fcn: '<S394>/r->x'
   */
  rtb_DeadZone = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S373>/Add' incorporates:
   *  Fcn: '<S379>/r->x'
   *  Fcn: '<S380>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_DeadZone;

  /* Fcn: '<S379>/theta->y' incorporates:
   *  Fcn: '<S384>/theta->y'
   *  Fcn: '<S389>/theta->y'
   *  Fcn: '<S394>/theta->y'
   */
  rtb_Modulation_Drv = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S373>/Add' incorporates:
   *  Fcn: '<S379>/theta->y'
   *  Fcn: '<S380>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) +
    rtb_Modulation_Drv;

  /* Sum: '<S374>/Add' incorporates:
   *  Fcn: '<S385>/r->x'
   *  Fcn: '<S385>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_DeadZone;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) +
    rtb_Modulation_Drv;

  /* Sum: '<S375>/Add' incorporates:
   *  Fcn: '<S390>/r->x'
   *  Fcn: '<S390>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_DeadZone;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Modulation_Drv;

  /* Sum: '<S376>/Add' incorporates:
   *  Fcn: '<S395>/r->x'
   *  Fcn: '<S395>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_DeadZone;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) +
    rtb_Modulation_Drv;

  /* Fcn: '<S393>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S396>/Compare' incorporates:
   *  Constant: '<S396>/Constant'
   */
  rtb_Compare_ik = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S392>/Switch1' */
  if (rtb_Compare_ik) {
    /* Switch: '<S392>/Switch1' incorporates:
     *  Constant: '<S392>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S392>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S392>/Switch1' */

  /* Fcn: '<S378>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S381>/Compare' incorporates:
   *  Constant: '<S381>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S377>/Switch1' */
  if (rtb_Button_Spinup_Enable) {
    /* Switch: '<S377>/Switch1' incorporates:
     *  Constant: '<S377>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S377>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S377>/Switch1' */

  /* Fcn: '<S383>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S386>/Compare' incorporates:
   *  Constant: '<S386>/Constant'
   */
  rtb_AND1_c = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S382>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S382>/Switch1' incorporates:
     *  Constant: '<S382>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S382>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S382>/Switch1' */

  /* Fcn: '<S388>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S391>/Compare' incorporates:
   *  Constant: '<S391>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S387>/Switch1' */
  if (rtb_Button_Shoot_Enable) {
    /* Switch: '<S387>/Switch1' incorporates:
     *  Constant: '<S387>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S387>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S387>/Switch1' */

  /* Product: '<S372>/Divide' incorporates:
   *  Abs: '<S372>/Abs'
   *  Abs: '<S372>/Abs1'
   *  Abs: '<S372>/Abs2'
   *  Abs: '<S372>/Abs3'
   *  Constant: '<S372>/Constant'
   *  MinMax: '<S372>/Max'
   */
  rtb_Switch2_p2 = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S372>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S392>/Switch' */
  if (!rtb_Compare_ik) {
    /* Switch: '<S392>/Switch' incorporates:
     *  Fcn: '<S393>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S392>/Switch' */

  /* Trigonometry: '<S327>/Cos4' incorporates:
   *  Switch: '<S316>/Angle_Switch'
   *  Trigonometry: '<S326>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S327>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S325>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S327>/Sin4' incorporates:
   *  Switch: '<S316>/Angle_Switch'
   *  Trigonometry: '<S326>/Sin4'
   */
  rtb_Modulation_Drv = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S327>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S325>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S327>/Subtract1' incorporates:
   *  Product: '<S327>/Product2'
   *  Product: '<S327>/Product3'
   *  Trigonometry: '<S327>/Cos4'
   *  Trigonometry: '<S327>/Sin4'
   */
  rtb_DeadZone = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) +
    (rtb_Modulation_Drv * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S327>/Subtract' incorporates:
   *  Product: '<S327>/Product'
   *  Product: '<S327>/Product1'
   *  Trigonometry: '<S327>/Cos4'
   *  Trigonometry: '<S327>/Sin4'
   */
  rtb_Init = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Modulation_Drv * rtb_Optimized_Module_Angle);

  /* Math: '<S327>/Hypot' */
  rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Init, rtb_DeadZone);

  /* Switch: '<S327>/Switch' incorporates:
   *  Constant: '<S327>/Constant'
   *  Constant: '<S327>/Constant1'
   *  Constant: '<S328>/Constant'
   *  Product: '<S327>/Divide'
   *  Product: '<S327>/Divide1'
   *  RelationalOperator: '<S328>/Compare'
   *  Switch: '<S327>/Switch1'
   */
  if (rtb_Minus_k_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_DeadZone / rtb_Minus_k_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Minus_k_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S327>/Switch' */

  /* Switch: '<S316>/Speed_Switch' incorporates:
   *  Abs: '<S316>/Abs'
   *  Constant: '<S324>/Constant'
   *  RelationalOperator: '<S324>/Compare'
   *  Switch: '<S316>/Angle_Switch'
   *  Trigonometry: '<S326>/Atan1'
   *  Trigonometry: '<S327>/Atan1'
   *  UnaryMinus: '<S316>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S326>/Subtract1' incorporates:
     *  Product: '<S326>/Product2'
     *  Product: '<S326>/Product3'
     *  UnaryMinus: '<S316>/Unary Minus'
     */
    rtb_DeadZone = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_Modulation_Drv * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S326>/Subtract' incorporates:
     *  Product: '<S326>/Product'
     *  Product: '<S326>/Product1'
     */
    rtb_Init = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_Modulation_Drv * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S326>/Hypot' */
    rtb_Modulation_Drv = rt_hypotd_snf(rtb_Init, rtb_DeadZone);

    /* Switch: '<S326>/Switch1' incorporates:
     *  Constant: '<S326>/Constant'
     *  Constant: '<S326>/Constant1'
     *  Constant: '<S329>/Constant'
     *  Product: '<S326>/Divide'
     *  Product: '<S326>/Divide1'
     *  RelationalOperator: '<S329>/Compare'
     *  Switch: '<S326>/Switch'
     */
    if (rtb_Modulation_Drv > 1.0E-6) {
      rtb_Init /= rtb_Modulation_Drv;
      rtb_Modulation_Drv = rtb_DeadZone / rtb_Modulation_Drv;
    } else {
      rtb_Init = 1.0;
      rtb_Modulation_Drv = 0.0;
    }

    /* End of Switch: '<S326>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Modulation_Drv, rtb_Init);
  } else {
    rtb_Add_a5 = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S319>/Product2' incorporates:
   *  Constant: '<S319>/Constant'
   *  Switch: '<S316>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S314>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S314>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S317>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S318>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S249>/Product' incorporates:
   *  Abs: '<S314>/Abs'
   *  Abs: '<S317>/Abs'
   *  Constant: '<S320>/Constant'
   *  Constant: '<S330>/Constant3'
   *  Constant: '<S330>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S314>/OR'
   *  Lookup_n-D: '<S317>/1-D Lookup Table'
   *  Math: '<S330>/Math Function'
   *  RelationalOperator: '<S314>/Equal1'
   *  RelationalOperator: '<S320>/Compare'
   *  Signum: '<S314>/Sign'
   *  Signum: '<S314>/Sign1'
   *  Sum: '<S317>/Add'
   *  Sum: '<S330>/Add1'
   *  Sum: '<S330>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.BackRight_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                    rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S315>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Init = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S322>/Sum1' incorporates:
   *  Constant: '<S315>/Constant2'
   *  Product: '<S322>/Product'
   *  Sum: '<S322>/Sum'
   *  UnitDelay: '<S322>/Unit Delay1'
   */
  rtb_Modulation_Drv = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                        Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S315>/Product' incorporates:
   *  Constant: '<S315>/Constant3'
   */
  rtb_DeadZone = rtb_Modulation_Drv * Drive_Motor_Control_D;

  /* Sum: '<S321>/Diff' incorporates:
   *  UnitDelay: '<S321>/UD'
   *
   * Block description for '<S321>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S321>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_DeadZone - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S315>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S315>/Add' incorporates:
   *  Gain: '<S315>/Gain'
   *  Gain: '<S315>/Gain1'
   *  Saturate: '<S315>/Saturation'
   */
  rtb_Minus_k_idx_0 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0)
                       + (Drive_Motor_Control_P * rtb_Init)) + rtb_Add_a5;

  /* Saturate: '<S315>/Saturation2' incorporates:
   *  Sum: '<S315>/Add1'
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

  /* End of Saturate: '<S315>/Saturation2' */

  /* Switch: '<S377>/Switch' */
  if (!rtb_Button_Spinup_Enable) {
    /* Switch: '<S377>/Switch' incorporates:
     *  Fcn: '<S378>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S377>/Switch' */

  /* Trigonometry: '<S264>/Cos4' incorporates:
   *  Switch: '<S253>/Angle_Switch'
   *  Trigonometry: '<S263>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S264>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S262>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S264>/Sin4' incorporates:
   *  Switch: '<S253>/Angle_Switch'
   *  Trigonometry: '<S263>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S264>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S262>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S264>/Subtract1' incorporates:
   *  Product: '<S264>/Product2'
   *  Product: '<S264>/Product3'
   *  Trigonometry: '<S264>/Cos4'
   *  Trigonometry: '<S264>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S264>/Subtract' incorporates:
   *  Product: '<S264>/Product'
   *  Product: '<S264>/Product1'
   *  Trigonometry: '<S264>/Cos4'
   *  Trigonometry: '<S264>/Sin4'
   */
  rtb_Init = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S264>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Init, rtb_Minus_k_idx_0);

  /* Switch: '<S264>/Switch' incorporates:
   *  Constant: '<S264>/Constant'
   *  Constant: '<S264>/Constant1'
   *  Constant: '<S265>/Constant'
   *  Product: '<S264>/Divide'
   *  Product: '<S264>/Divide1'
   *  RelationalOperator: '<S265>/Compare'
   *  Switch: '<S264>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0 / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Hypot_g5;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S264>/Switch' */

  /* Product: '<S372>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S253>/Speed_Switch' incorporates:
   *  Abs: '<S253>/Abs'
   *  Constant: '<S261>/Constant'
   *  RelationalOperator: '<S261>/Compare'
   *  Switch: '<S253>/Angle_Switch'
   *  Trigonometry: '<S263>/Atan1'
   *  Trigonometry: '<S264>/Atan1'
   *  UnaryMinus: '<S253>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S263>/Subtract1' incorporates:
     *  Product: '<S263>/Product2'
     *  Product: '<S263>/Product3'
     *  UnaryMinus: '<S253>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S263>/Subtract' incorporates:
     *  Product: '<S263>/Product'
     *  Product: '<S263>/Product1'
     */
    rtb_Hypot_g5 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S263>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Hypot_g5, rtb_Minus_k_idx_0);

    /* Switch: '<S263>/Switch1' incorporates:
     *  Constant: '<S263>/Constant'
     *  Constant: '<S263>/Constant1'
     *  Constant: '<S266>/Constant'
     *  Product: '<S263>/Divide'
     *  Product: '<S263>/Divide1'
     *  RelationalOperator: '<S266>/Compare'
     *  Switch: '<S263>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Init;
      rtb_Minus_k_idx_0 /= rtb_Init;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S263>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_0, rtb_Hypot_g5);
  } else {
    rtb_Add_a5 = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S256>/Product2' incorporates:
   *  Constant: '<S256>/Constant'
   *  Switch: '<S253>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S251>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S251>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S254>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S255>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S246>/Product' incorporates:
   *  Abs: '<S251>/Abs'
   *  Abs: '<S254>/Abs'
   *  Constant: '<S257>/Constant'
   *  Constant: '<S267>/Constant3'
   *  Constant: '<S267>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
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
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S252>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_g5 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S259>/Sum1' incorporates:
   *  Constant: '<S252>/Constant2'
   *  Product: '<S259>/Product'
   *  Sum: '<S259>/Sum'
   *  UnitDelay: '<S259>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_Hypot_g5 - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S252>/Product' incorporates:
   *  Constant: '<S252>/Constant3'
   */
  rtb_Init = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

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
  rtb_Add_a5 = rtb_Init - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S252>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S252>/Add' incorporates:
   *  Gain: '<S252>/Gain'
   *  Gain: '<S252>/Gain1'
   *  Saturate: '<S252>/Saturation'
   */
  rtb_Hypot_g5 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0) +
                  (Drive_Motor_Control_P * rtb_Hypot_g5)) + rtb_Add_a5;

  /* Saturate: '<S252>/Saturation2' incorporates:
   *  Sum: '<S252>/Add1'
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

  /* End of Saturate: '<S252>/Saturation2' */

  /* Sum: '<S268>/Add1' incorporates:
   *  Constant: '<S268>/Constant3'
   *  Constant: '<S268>/Constant4'
   *  Math: '<S268>/Math Function'
   *  Sum: '<S268>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S270>/Sum1' incorporates:
   *  Constant: '<S255>/Constant2'
   *  Product: '<S270>/Product'
   *  Sum: '<S270>/Sum'
   *  UnitDelay: '<S270>/Unit Delay1'
   */
  rtb_Hypot_g5 = ((rtb_MatrixConcatenate_b_idx_0 -
                   Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S255>/Product' incorporates:
   *  Constant: '<S255>/Constant3'
   */
  rtb_MatrixConcatenate_idx_0 = rtb_Hypot_g5 * Steering_Motor_Control_D;

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
  rtb_Add_a5 = rtb_MatrixConcatenate_idx_0 - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S255>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S255>/Add' incorporates:
   *  Gain: '<S255>/Gain1'
   *  Saturate: '<S255>/Saturation'
   */
  rtb_Add_e3 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_a5;

  /* Sum: '<S255>/Subtract' incorporates:
   *  Constant: '<S255>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_e3;

  /* Sum: '<S255>/Sum2' incorporates:
   *  Gain: '<S255>/Gain2'
   *  UnitDelay: '<S255>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S271>/Switch2' incorporates:
   *  Constant: '<S255>/Constant'
   *  RelationalOperator: '<S271>/LowerRelop1'
   *  Sum: '<S255>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_e3))) {
    /* Switch: '<S271>/Switch' incorporates:
     *  Constant: '<S255>/Constant1'
     *  RelationalOperator: '<S271>/UpperRelop'
     *  Sum: '<S255>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_e3)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_e3;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S271>/Switch' */
  }

  /* End of Switch: '<S271>/Switch2' */

  /* Saturate: '<S255>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S255>/Saturation1' */

  /* Sum: '<S255>/Add1' */
  rtb_Add_a5 = rtb_Add_e3 + rtb_Sum2_e;

  /* Saturate: '<S255>/Saturation2' */
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

  /* End of Saturate: '<S255>/Saturation2' */

  /* Switch: '<S382>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S382>/Switch' incorporates:
     *  Fcn: '<S383>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S382>/Switch' */

  /* Trigonometry: '<S285>/Cos4' incorporates:
   *  Switch: '<S274>/Angle_Switch'
   *  Trigonometry: '<S284>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S285>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S283>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S285>/Sin4' incorporates:
   *  Switch: '<S274>/Angle_Switch'
   *  Trigonometry: '<S284>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S285>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S283>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S285>/Subtract1' incorporates:
   *  Product: '<S285>/Product2'
   *  Product: '<S285>/Product3'
   *  Trigonometry: '<S285>/Cos4'
   *  Trigonometry: '<S285>/Sin4'
   */
  rtb_Add_e3 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S285>/Subtract' incorporates:
   *  Product: '<S285>/Product'
   *  Product: '<S285>/Product1'
   *  Trigonometry: '<S285>/Cos4'
   *  Trigonometry: '<S285>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S285>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_e3);

  /* Switch: '<S285>/Switch' incorporates:
   *  Constant: '<S285>/Constant'
   *  Constant: '<S285>/Constant1'
   *  Constant: '<S286>/Constant'
   *  Product: '<S285>/Divide'
   *  Product: '<S285>/Divide1'
   *  RelationalOperator: '<S286>/Compare'
   *  Switch: '<S285>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_e3 / rtb_Hypot_b;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_b;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S285>/Switch' */

  /* Product: '<S372>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S274>/Speed_Switch' incorporates:
   *  Abs: '<S274>/Abs'
   *  Constant: '<S282>/Constant'
   *  RelationalOperator: '<S282>/Compare'
   *  Switch: '<S274>/Angle_Switch'
   *  Trigonometry: '<S284>/Atan1'
   *  Trigonometry: '<S285>/Atan1'
   *  UnaryMinus: '<S274>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S284>/Subtract1' incorporates:
     *  Product: '<S284>/Product2'
     *  Product: '<S284>/Product3'
     *  UnaryMinus: '<S274>/Unary Minus'
     */
    rtb_Add_e3 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S284>/Subtract' incorporates:
     *  Product: '<S284>/Product'
     *  Product: '<S284>/Product1'
     */
    rtb_Hypot_b = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S284>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_b, rtb_Add_e3);

    /* Switch: '<S284>/Switch1' incorporates:
     *  Constant: '<S284>/Constant'
     *  Constant: '<S284>/Constant1'
     *  Constant: '<S287>/Constant'
     *  Product: '<S284>/Divide'
     *  Product: '<S284>/Divide1'
     *  RelationalOperator: '<S287>/Compare'
     *  Switch: '<S284>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_b /= rtb_Subtract1_la;
      rtb_Add_e3 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_b = 1.0;
      rtb_Add_e3 = 0.0;
    }

    /* End of Switch: '<S284>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_e3, rtb_Hypot_b);
  } else {
    rtb_Add_a5 = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S277>/Product2' incorporates:
   *  Constant: '<S277>/Constant'
   *  Switch: '<S274>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S272>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S272>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S275>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S276>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S247>/Product' incorporates:
   *  Abs: '<S272>/Abs'
   *  Abs: '<S275>/Abs'
   *  Constant: '<S278>/Constant'
   *  Constant: '<S288>/Constant3'
   *  Constant: '<S288>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
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
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Sum: '<S273>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_b = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S280>/Sum1' incorporates:
   *  Constant: '<S273>/Constant2'
   *  Product: '<S280>/Product'
   *  Sum: '<S280>/Sum'
   *  UnitDelay: '<S280>/Unit Delay1'
   */
  rtb_Add_e3 = ((rtb_Hypot_b - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S273>/Product' incorporates:
   *  Constant: '<S273>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_e3 * Drive_Motor_Control_D;

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
  rtb_Add_a5 = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S273>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S273>/Add' incorporates:
   *  Gain: '<S273>/Gain'
   *  Gain: '<S273>/Gain1'
   *  Saturate: '<S273>/Saturation'
   */
  rtb_Hypot_b = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0) +
                 (Drive_Motor_Control_P * rtb_Hypot_b)) + rtb_Add_a5;

  /* Saturate: '<S273>/Saturation2' incorporates:
   *  Sum: '<S273>/Add1'
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

  /* End of Saturate: '<S273>/Saturation2' */

  /* Sum: '<S289>/Add1' incorporates:
   *  Constant: '<S289>/Constant3'
   *  Constant: '<S289>/Constant4'
   *  Math: '<S289>/Math Function'
   *  Sum: '<S289>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S291>/Sum1' incorporates:
   *  Constant: '<S276>/Constant2'
   *  Product: '<S291>/Product'
   *  Sum: '<S291>/Sum'
   *  UnitDelay: '<S291>/Unit Delay1'
   */
  rtb_Hypot_b = ((rtb_MatrixConcatenate_b_idx_0 -
                  Robot_Control_DW.UnitDelay1_DSTATE_n) *
                 Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S276>/Product' incorporates:
   *  Constant: '<S276>/Constant3'
   */
  rtb_Switch2_ee = rtb_Hypot_b * Steering_Motor_Control_D;

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
  rtb_Add_a5 = rtb_Switch2_ee - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S276>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S276>/Add' incorporates:
   *  Gain: '<S276>/Gain1'
   *  Saturate: '<S276>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)
    + rtb_Add_a5;

  /* Sum: '<S276>/Subtract' incorporates:
   *  Constant: '<S276>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S276>/Sum2' incorporates:
   *  Gain: '<S276>/Gain2'
   *  UnitDelay: '<S276>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S292>/Switch2' incorporates:
   *  Constant: '<S276>/Constant'
   *  RelationalOperator: '<S292>/LowerRelop1'
   *  Sum: '<S276>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S292>/Switch' incorporates:
     *  Constant: '<S276>/Constant1'
     *  RelationalOperator: '<S292>/UpperRelop'
     *  Sum: '<S276>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S292>/Switch' */
  }

  /* End of Switch: '<S292>/Switch2' */

  /* Saturate: '<S276>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S276>/Saturation1' */

  /* Sum: '<S276>/Add1' */
  rtb_Add_a5 = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S276>/Saturation2' */
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

  /* End of Saturate: '<S276>/Saturation2' */

  /* Switch: '<S387>/Switch' */
  if (!rtb_Button_Shoot_Enable) {
    /* Switch: '<S387>/Switch' incorporates:
     *  Fcn: '<S388>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S387>/Switch' */

  /* Trigonometry: '<S306>/Cos4' incorporates:
   *  Switch: '<S295>/Angle_Switch'
   *  Trigonometry: '<S305>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S306>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S304>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S306>/Sin4' incorporates:
   *  Switch: '<S295>/Angle_Switch'
   *  Trigonometry: '<S305>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S306>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S304>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S306>/Subtract1' incorporates:
   *  Product: '<S306>/Product2'
   *  Product: '<S306>/Product3'
   *  Trigonometry: '<S306>/Cos4'
   *  Trigonometry: '<S306>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S306>/Subtract' incorporates:
   *  Product: '<S306>/Product'
   *  Product: '<S306>/Product1'
   *  Trigonometry: '<S306>/Cos4'
   *  Trigonometry: '<S306>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S306>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S306>/Switch' incorporates:
   *  Constant: '<S306>/Constant'
   *  Constant: '<S306>/Constant1'
   *  Constant: '<S307>/Constant'
   *  Product: '<S306>/Divide'
   *  Product: '<S306>/Divide1'
   *  RelationalOperator: '<S307>/Compare'
   *  Switch: '<S306>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S306>/Switch' */

  /* Product: '<S372>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S295>/Speed_Switch' incorporates:
   *  Abs: '<S295>/Abs'
   *  Constant: '<S303>/Constant'
   *  RelationalOperator: '<S303>/Compare'
   *  Switch: '<S295>/Angle_Switch'
   *  Trigonometry: '<S305>/Atan1'
   *  Trigonometry: '<S306>/Atan1'
   *  UnaryMinus: '<S295>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S305>/Subtract1' incorporates:
     *  Product: '<S305>/Product2'
     *  Product: '<S305>/Product3'
     *  UnaryMinus: '<S295>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_e) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S305>/Subtract' incorporates:
     *  Product: '<S305>/Product'
     *  Product: '<S305>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S305>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable,
      rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S305>/Switch1' incorporates:
     *  Constant: '<S305>/Constant'
     *  Constant: '<S305>/Constant1'
     *  Constant: '<S308>/Constant'
     *  Product: '<S305>/Divide'
     *  Product: '<S305>/Divide1'
     *  RelationalOperator: '<S308>/Compare'
     *  Switch: '<S305>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S305>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_uDLookupTable);
  } else {
    rtb_Add_a5 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S298>/Product2' incorporates:
   *  Constant: '<S298>/Constant'
   *  Switch: '<S295>/Speed_Switch'
   */
  rtb_Switch2_p2 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S293>/Sign' */
  if (rtIsNaN(rtb_Switch2_p2)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_Switch2_p2 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_Switch2_p2 > 0.0);
  }

  /* Signum: '<S293>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S296>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S297>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S248>/Product' incorporates:
   *  Abs: '<S293>/Abs'
   *  Abs: '<S296>/Abs'
   *  Constant: '<S299>/Constant'
   *  Constant: '<S309>/Constant3'
   *  Constant: '<S309>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
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
  rtb_Switch2_p2 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p2) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Sum: '<S294>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2 -
    Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S301>/Sum1' incorporates:
   *  Constant: '<S294>/Constant2'
   *  Product: '<S301>/Product'
   *  Sum: '<S301>/Sum'
   *  UnitDelay: '<S301>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_MatrixConcatenate_b_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S294>/Product' incorporates:
   *  Constant: '<S294>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

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
  rtb_Add_a5 = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S294>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S294>/Add' incorporates:
   *  Gain: '<S294>/Gain'
   *  Gain: '<S294>/Gain1'
   *  Saturate: '<S294>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_p2) +
                    (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) +
    rtb_Add_a5;

  /* Saturate: '<S294>/Saturation2' incorporates:
   *  Sum: '<S294>/Add1'
   */
  if (rtb_Switch2_p2 > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch2_p2 < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Switch2_p2;
  }

  /* End of Saturate: '<S294>/Saturation2' */

  /* Sum: '<S310>/Add1' incorporates:
   *  Constant: '<S310>/Constant3'
   *  Constant: '<S310>/Constant4'
   *  Math: '<S310>/Math Function'
   *  Sum: '<S310>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S312>/Sum1' incorporates:
   *  Constant: '<S297>/Constant2'
   *  Product: '<S312>/Product'
   *  Sum: '<S312>/Sum'
   *  UnitDelay: '<S312>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S297>/Product' incorporates:
   *  Constant: '<S297>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

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
  rtb_Add_a5 = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S297>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S297>/Add' incorporates:
   *  Gain: '<S297>/Gain1'
   *  Saturate: '<S297>/Saturation'
   */
  rtb_Add_f1 = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_a5;

  /* Sum: '<S297>/Subtract' incorporates:
   *  Constant: '<S297>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_f1;

  /* Sum: '<S297>/Sum2' incorporates:
   *  Gain: '<S297>/Gain2'
   *  UnitDelay: '<S297>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S313>/Switch2' incorporates:
   *  Constant: '<S297>/Constant'
   *  RelationalOperator: '<S313>/LowerRelop1'
   *  Sum: '<S297>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_f1))) {
    /* Sum: '<S297>/Subtract1' incorporates:
     *  Constant: '<S297>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_f1;

    /* Switch: '<S313>/Switch' incorporates:
     *  Constant: '<S297>/Constant1'
     *  RelationalOperator: '<S313>/UpperRelop'
     *  Sum: '<S297>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_f1))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S313>/Switch' */
  }

  /* End of Switch: '<S313>/Switch2' */

  /* Saturate: '<S297>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S297>/Saturation1' */

  /* Sum: '<S297>/Add1' */
  rtb_Add_a5 = rtb_Add_f1 + rtb_Integral_ga;

  /* Saturate: '<S297>/Saturation2' */
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

  /* End of Saturate: '<S297>/Saturation2' */

  /* Sum: '<S331>/Add1' incorporates:
   *  Constant: '<S331>/Constant3'
   *  Constant: '<S331>/Constant4'
   *  Math: '<S331>/Math Function'
   *  Sum: '<S331>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S333>/Sum1' incorporates:
   *  Constant: '<S318>/Constant2'
   *  Product: '<S333>/Product'
   *  Sum: '<S333>/Sum'
   *  UnitDelay: '<S333>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S318>/Product' incorporates:
   *  Constant: '<S318>/Constant3'
   */
  rtb_Add_f1 = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S332>/Diff' incorporates:
   *  UnitDelay: '<S332>/UD'
   *
   * Block description for '<S332>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S332>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Add_f1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S318>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S318>/Add' incorporates:
   *  Gain: '<S318>/Gain1'
   *  Saturate: '<S318>/Saturation'
   */
  rtb_Add_fd = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_a5;

  /* Sum: '<S318>/Subtract' incorporates:
   *  Constant: '<S318>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_fd;

  /* Sum: '<S318>/Sum2' incorporates:
   *  Gain: '<S318>/Gain2'
   *  UnitDelay: '<S318>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S334>/Switch2' incorporates:
   *  Constant: '<S318>/Constant'
   *  RelationalOperator: '<S334>/LowerRelop1'
   *  Sum: '<S318>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_fd))) {
    /* Sum: '<S318>/Subtract1' incorporates:
     *  Constant: '<S318>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_fd;

    /* Switch: '<S334>/Switch' incorporates:
     *  Constant: '<S318>/Constant1'
     *  RelationalOperator: '<S334>/UpperRelop'
     *  Sum: '<S318>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_fd))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S334>/Switch' */
  }

  /* End of Switch: '<S334>/Switch2' */

  /* Saturate: '<S318>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S318>/Saturation1' */

  /* Sum: '<S318>/Add1' */
  rtb_Add_a5 = rtb_Add_fd + rtb_Integral_bj;

  /* Saturate: '<S318>/Saturation2' */
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

  /* End of Saturate: '<S318>/Saturation2' */

  /* Gain: '<S369>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 * rtb_Add1_l;

  /* Sum: '<S181>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S135>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S183>/Sum1' incorporates:
   *  Constant: '<S181>/Constant2'
   *  Product: '<S183>/Product'
   *  Sum: '<S181>/Sum'
   *  Sum: '<S183>/Sum'
   *  UnitDelay: '<S183>/Unit Delay1'
   */
  rtb_Add1_l = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S181>/Product' incorporates:
   *  Constant: '<S181>/Constant3'
   */
  rtb_Add_fd = rtb_Add1_l * 0.0;

  /* Sum: '<S182>/Diff' incorporates:
   *  UnitDelay: '<S182>/UD'
   *
   * Block description for '<S182>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S182>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Add_fd - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S181>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S181>/Add' incorporates:
   *  Gain: '<S181>/Gain'
   *  Gain: '<S181>/Gain1'
   *  Saturate: '<S181>/Saturation'
   *  Sum: '<S181>/Sum'
   */
  rtb_Switch2_p2 = ((Rebuilt_Transfer_Motor_Gain_FF *
                     Robot_Control_B.RB_Desired_Transfer_Speed) +
                    (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) +
    rtb_Add_a5;

  /* Logic: '<S135>/Logical Operator1' incorporates:
   *  Constant: '<S180>/Constant'
   *  RelationalOperator: '<S180>/Compare'
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

  /* Switch: '<S181>/Switch' incorporates:
   *  Constant: '<S181>/Constant4'
   */
  if (rtb_Button_Spinup_Enable) {
    /* Sum: '<S181>/Sum2' incorporates:
     *  Gain: '<S181>/Gain2'
     *  Sum: '<S181>/Sum'
     *  UnitDelay: '<S181>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Transfer_Motor_Gain_I *
      rtb_Integral_d) + Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S181>/Subtract' incorporates:
     *  Constant: '<S181>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Switch2_p2;

    /* Switch: '<S184>/Switch2' incorporates:
     *  Constant: '<S181>/Constant'
     *  RelationalOperator: '<S184>/LowerRelop1'
     *  Sum: '<S181>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Switch2_p2))) {
      /* Sum: '<S181>/Subtract1' incorporates:
       *  Constant: '<S181>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Switch2_p2;

      /* Switch: '<S184>/Switch' incorporates:
       *  Constant: '<S181>/Constant1'
       *  RelationalOperator: '<S184>/UpperRelop'
       *  Sum: '<S181>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Switch2_p2))) {
        rtb_Integral_d = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S184>/Switch' */
    }

    /* End of Switch: '<S184>/Switch2' */

    /* Saturate: '<S181>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S181>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S181>/Switch' */

  /* Switch: '<S135>/Switch2' incorporates:
   *  Logic: '<S135>/Logical Operator1'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S181>/Add1' */
    rtb_Add_a5 = rtb_Switch2_p2 + rtb_Integral_d;

    /* Saturate: '<S181>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S135>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S135>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S135>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S181>/Saturation2' */
  } else {
    /* Switch: '<S135>/Switch2' incorporates:
     *  Constant: '<S135>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S135>/Switch2' */

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
    rtb_Switch2_p2 = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Transfer_Motor_DC' */
    Robot_Control_Y.Transfer_Motor_DC = Robot_Control_B.RB_Transfer_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S10>/Constant8'
     */
    Robot_Control_Y.Desired_Hood_Enable = true;

    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;
    rtb_Switch2_p2 = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_Switch2_p2 > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Switch2_p2 < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Switch2_p2;

  /* Switch: '<S127>/Init' incorporates:
   *  UnitDelay: '<S127>/FixPt Unit Delay1'
   *  UnitDelay: '<S127>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S127>/Init' */

  /* Sum: '<S125>/Sum1' */
  rtb_Switch2_p2 -= rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S126>/Switch2' incorporates:
   *  Constant: '<S124>/Constant1'
   *  Constant: '<S124>/Constant3'
   *  RelationalOperator: '<S126>/LowerRelop1'
   *  RelationalOperator: '<S126>/UpperRelop'
   *  Switch: '<S126>/Switch'
   */
  if (rtb_Switch2_p2 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch2_p2 < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S124>/Constant1'
     */
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S126>/Switch2' */

  /* Sum: '<S125>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Switch2_p2 +
    rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  if (rtb_LogicalOperator1_n) {
    rtb_Switch2_p2 = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Switch2_p2 = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S53>/Logical Operator1' incorporates:
   *  Constant: '<S65>/Constant'
   *  RelationalOperator: '<S65>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Switch2_p2 == 0.0);

  /* Sum: '<S66>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S53>/Subtract'
   */
  rtb_Error_n = rtb_Switch2_p2 - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S68>/Sum1' incorporates:
   *  Constant: '<S66>/Constant2'
   *  Product: '<S68>/Product'
   *  Sum: '<S66>/Sum'
   *  Sum: '<S68>/Sum'
   *  UnitDelay: '<S68>/Unit Delay1'
   */
  rtb_Sum1_hc = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S66>/Product' incorporates:
   *  Constant: '<S66>/Constant3'
   */
  rtb_Product_m5 = rtb_Sum1_hc * 0.0;

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
  rtb_Add_a5 = rtb_Product_m5 - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S66>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S66>/Add' incorporates:
   *  Gain: '<S66>/Gain'
   *  Gain: '<S66>/Gain1'
   *  Saturate: '<S66>/Saturation'
   *  Sum: '<S66>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Roller_Motor_Gain_FF *
    rtb_Switch2_p2) + (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_a5;

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
      (Robot_Control_DW.UnitDelay_DSTATE_nh));
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
    rtb_Switch2_p2 = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S66>/Subtract' incorporates:
     *  Constant: '<S66>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_MatrixConcatenate_b_idx_0;

    /* Switch: '<S69>/Switch2' incorporates:
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S69>/LowerRelop1'
     *  Sum: '<S66>/Subtract'
     */
    if (!(rtb_Switch2_p2 > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S66>/Subtract1' incorporates:
       *  Constant: '<S66>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S69>/Switch' incorporates:
       *  Constant: '<S66>/Constant1'
       *  RelationalOperator: '<S69>/UpperRelop'
       *  Sum: '<S66>/Subtract1'
       */
      if (!(rtb_Switch2_p2 < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Error_n = rtb_Switch2_p2;
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
    rtb_Add_a5 = rtb_MatrixConcatenate_b_idx_0 + rtb_Error_n;

    /* Saturate: '<S66>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S53>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S53>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S53>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_a5;
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
      if (rtb_Intake_Arm_Move_Out || (rtb_Intake_Arm_Cycle &&
           (Robot_Control_B.RB_Intake_Arm_Angle_Mod <
            Rebuilt_Intake_Cycle_Angle_In))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      if ((rtb_Intake_Arm_Move_In || (rtb_Intake_Arm_Cycle &&
            (Robot_Control_B.RB_Intake_Arm_Angle_Mod >
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

  /* Switch: '<S64>/Init' incorporates:
   *  UnitDelay: '<S64>/FixPt Unit Delay1'
   *  UnitDelay: '<S64>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S64>/Init' */

  /* Sum: '<S62>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_Switch2_p2;

  /* Switch: '<S63>/Switch2' incorporates:
   *  Constant: '<S52>/Constant1'
   *  Constant: '<S52>/Constant3'
   *  RelationalOperator: '<S63>/LowerRelop1'
   *  RelationalOperator: '<S63>/UpperRelop'
   *  Switch: '<S63>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Intake_RL_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S63>/Switch2' */

  /* Sum: '<S62>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Switch2_p2;

  /* Sum: '<S58>/Sum' */
  rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S60>/Sum1' incorporates:
   *  Constant: '<S58>/Constant2'
   *  Product: '<S60>/Product'
   *  Sum: '<S60>/Sum'
   *  UnitDelay: '<S60>/Unit Delay1'
   */
  rtb_Sum1_pi = ((rtb_Switch2_p2 - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S58>/Product' incorporates:
   *  Constant: '<S58>/Constant3'
   */
  rtb_Product_aa = rtb_Sum1_pi * Rebuilt_Intake_Arm_Gain_D;

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
  rtb_Add_a5 = rtb_Product_aa - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S58>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S58>/Add' incorporates:
   *  Gain: '<S58>/Gain'
   *  Gain: '<S58>/Gain1'
   *  Saturate: '<S58>/Saturation'
   */
  rtb_Add_i = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
               (Rebuilt_Intake_Arm_Gain_P * rtb_Switch2_p2)) + rtb_Add_a5;

  /* Sum: '<S58>/Subtract' incorporates:
   *  Constant: '<S58>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_i;

  /* Sum: '<S58>/Sum2' incorporates:
   *  Gain: '<S58>/Gain2'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  rtb_Switch2_p2 = (0.0 * rtb_Switch2_p2) + Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S61>/Switch2' incorporates:
   *  Constant: '<S58>/Constant'
   *  RelationalOperator: '<S61>/LowerRelop1'
   *  Sum: '<S58>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_i))) {
    /* Sum: '<S58>/Subtract1' incorporates:
     *  Constant: '<S58>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_i;

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S58>/Constant1'
     *  RelationalOperator: '<S61>/UpperRelop'
     *  Sum: '<S58>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_i))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S61>/Switch' */
  }

  /* End of Switch: '<S61>/Switch2' */

  /* Saturate: '<S58>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > 0.1) {
    rtb_MatrixConcatenate_b_idx_0 = 0.1;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -0.1) {
    rtb_MatrixConcatenate_b_idx_0 = -0.1;
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
    rtb_Add_a5 = rtb_Add_i + rtb_MatrixConcatenate_b_idx_0;

    /* Saturate: '<S58>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S51>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S51>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S51>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_a5;
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
   *  Constant: '<S175>/Constant'
   *  RelationalOperator: '<S175>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S176>/Sum' incorporates:
   *  Sum: '<S133>/Subtract'
   */
  rtb_Switch2_p2 = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S178>/Sum1' incorporates:
   *  Constant: '<S176>/Constant2'
   *  Product: '<S178>/Product'
   *  Sum: '<S176>/Sum'
   *  Sum: '<S178>/Sum'
   *  UnitDelay: '<S178>/Unit Delay1'
   */
  rtb_Add_i = ((rtb_Switch2_p2 - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S176>/Product' incorporates:
   *  Constant: '<S176>/Constant3'
   */
  rtb_Product_bg = rtb_Add_i * 0.0;

  /* Sum: '<S177>/Diff' incorporates:
   *  UnitDelay: '<S177>/UD'
   *
   * Block description for '<S177>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S177>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_bg - Robot_Control_DW.UD_DSTATE_kz;

  /* Saturate: '<S176>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S176>/Add' incorporates:
   *  Gain: '<S176>/Gain'
   *  Gain: '<S176>/Gain1'
   *  Saturate: '<S176>/Saturation'
   *  Sum: '<S176>/Sum'
   */
  rtb_Add_a5 += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Switch2_p2);

  /* Switch: '<S133>/Switch4' incorporates:
   *  Constant: '<S133>/Constant6'
   *  Constant: '<S133>/Constant7'
   *  Logic: '<S133>/Logical Operator1'
   *  Logic: '<S133>/Logical Operator2'
   *  RelationalOperator: '<S133>/LessThan2'
   *  UnitDelay: '<S133>/Unit Delay1'
   */
  if ((rtb_Switch2_p2 < 0.0) && rtb_LogicalOperator1_n) {
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
  if ((rtb_Switch2_p2 < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S133>/Switch1' */

  /* Switch: '<S176>/Switch' incorporates:
   *  Constant: '<S176>/Constant4'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S176>/Sum2' incorporates:
     *  Gain: '<S176>/Gain2'
     *  Product: '<S176>/Product1'
     *  Sum: '<S176>/Sum'
     *  Switch: '<S176>/Switch1'
     *  UnitDelay: '<S176>/Unit Delay'
     */
    rtb_Switch2_p2 = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Switch2_p2) * ((real_T)
      (!rtb_Intake_Arm_Move_In))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S176>/Subtract' incorporates:
     *  Constant: '<S176>/Constant'
     */
    rtb_Error_c5 = 1.0 - rtb_Add_a5;

    /* Switch: '<S179>/Switch2' incorporates:
     *  Constant: '<S176>/Constant'
     *  RelationalOperator: '<S179>/LowerRelop1'
     *  Sum: '<S176>/Subtract'
     */
    if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_a5))) {
      /* Sum: '<S176>/Subtract1' incorporates:
       *  Constant: '<S176>/Constant1'
       */
      rtb_Error_c5 = -1.0 - rtb_Add_a5;

      /* Switch: '<S179>/Switch' incorporates:
       *  Constant: '<S176>/Constant1'
       *  RelationalOperator: '<S179>/UpperRelop'
       *  Sum: '<S176>/Subtract1'
       */
      if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_a5))) {
        rtb_Error_c5 = rtb_Switch2_p2;
      }

      /* End of Switch: '<S179>/Switch' */
    }

    /* End of Switch: '<S179>/Switch2' */

    /* Saturate: '<S176>/Saturation1' */
    if (rtb_Error_c5 > 0.1) {
      rtb_Switch2_p2 = 0.1;
    } else if (rtb_Error_c5 < -0.1) {
      rtb_Switch2_p2 = -0.1;
    } else {
      rtb_Switch2_p2 = rtb_Error_c5;
    }

    /* End of Saturate: '<S176>/Saturation1' */
  } else {
    rtb_Switch2_p2 = 0.0;
  }

  /* End of Switch: '<S176>/Switch' */

  /* Switch: '<S133>/Switch2' incorporates:
   *  Logic: '<S133>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S176>/Add1' */
    rtb_Add_a5 += rtb_Switch2_p2;

    /* Saturate: '<S176>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S133>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S133>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S133>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S176>/Saturation2' */
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

  /* Outport: '<Root>/Enable_Wheels' */
  Robot_Control_Y.Enable_Wheels = rtb_Enable_Wheels;

  /* Outport: '<Root>/Reset_Wheel_Offsets' */
  Robot_Control_Y.Reset_Wheel_Offsets = rtb_Reset_Wheel_Offsets;

  /* Outport: '<Root>/Disable_Wheels' */
  Robot_Control_Y.Disable_Wheels = rtb_Disable_Wheels;

  /* Outport: '<Root>/Swerve_Motors_Disabled' */
  Robot_Control_Y.Swerve_Motors_Disabled = rtb_Shooter_Active_prev;

  /* Outport: '<Root>/Vision_Desired_Pipeline' */
  Robot_Control_Y.Vision_Desired_Pipeline = rtb_Desired_Pipeline;

  /* Outport: '<Root>/Auto_Initial_Gyro_Angle' */
  Robot_Control_Y.Auto_Initial_Gyro_Angle = rtb_Auto_Initial_Gyro_Angle;

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

  /* Update for UnitDelay: '<S44>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S44>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S44>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S47>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S47>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S47>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_j = rtb_Sum1_p1;

  /* Update for UnitDelay: '<S41>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S41>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

  /* Update for UnitDelay: '<S41>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_d = rtb_Sum1_cd;

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

  /* Update for Delay: '<S70>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S90>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S70>/A'
   *  Delay: '<S70>/MemoryX'
   */
  rtb_Sum1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Sum1_p1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
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
    Robot_Control_U.Odom_Delta_Y) + rtb_Sum1_p1) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S346>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S346>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_ob = 0U;

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

  /* Update for UnitDelay: '<S129>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S368>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S367>/UD'
   *
   * Block description for '<S367>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S365>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Subtract_c3;

  /* Update for UnitDelay: '<S348>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch1_b0;

  /* Update for UnitDelay: '<S363>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S363>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S363>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Switch1_b0;

  /* Update for UnitDelay: '<S347>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S356>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S356>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S356>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S322>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S321>/UD'
   *
   * Block description for '<S321>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_DeadZone;

  /* Update for UnitDelay: '<S315>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S259>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S258>/UD'
   *
   * Block description for '<S258>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Init;

  /* Update for UnitDelay: '<S252>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S270>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S269>/UD'
   *
   * Block description for '<S269>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S255>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S280>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_e3;

  /* Update for UnitDelay: '<S279>/UD'
   *
   * Block description for '<S279>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S273>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S291>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_b;

  /* Update for UnitDelay: '<S290>/UD'
   *
   * Block description for '<S290>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_ee;

  /* Update for UnitDelay: '<S276>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S301>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S300>/UD'
   *
   * Block description for '<S300>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S294>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S312>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S311>/UD'
   *
   * Block description for '<S311>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S297>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S333>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S332>/UD'
   *
   * Block description for '<S332>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_f1;

  /* Update for UnitDelay: '<S318>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S183>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add1_l;

  /* Update for UnitDelay: '<S182>/UD'
   *
   * Block description for '<S182>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Add_fd;

  /* Update for UnitDelay: '<S181>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S135>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Button_Spinup_Enable;

  /* Update for UnitDelay: '<S127>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S127>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S68>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_hc;

  /* Update for UnitDelay: '<S67>/UD'
   *
   * Block description for '<S67>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_m5;

  /* Update for UnitDelay: '<S66>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_nh = rtb_Button_Shoot_Enable;

  /* Update for UnitDelay: '<S50>/Delay Input1'
   *
   * Block description for '<S50>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S64>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S64>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S60>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_pi;

  /* Update for UnitDelay: '<S59>/UD'
   *
   * Block description for '<S59>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_aa;

  /* Update for UnitDelay: '<S58>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S178>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Add_i;

  /* Update for UnitDelay: '<S177>/UD'
   *
   * Block description for '<S177>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_bg;

  /* Update for UnitDelay: '<S133>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S176>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Switch2_p2;

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

  /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S47>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S41>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S70>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S346>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_ob = 1U;

  /* InitializeConditions for UnitDelay: '<S363>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S356>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S127>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S64>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S424>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_af = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S191>/If' */
  Robot_Control_DW.If_ActiveSubsystem_hk = -1;

  /* InitializeConditions for UnitDelay: '<S187>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S191>/Robot_Index_Is_Valid' */
  /* Start for If: '<S194>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S194>/Circle_Check_Valid' */
  /* Start for If: '<S196>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S194>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S191>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S130>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S162>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ll = Rebuilt_Match_Time_Auto_Timer;

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
  Robot_Control_DW.UnitDelay_DSTATE_n = Rebuilt_Match_Time_End_Game_Timer;

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
