/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.471
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Mar  8 10:06:43 2026
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
                                      * Referenced by: '<S409>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S405>/Constant'
                                        *   '<S405>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S409>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S405>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S240>/Constant3'
                                        *   '<S261>/Constant3'
                                        *   '<S282>/Constant3'
                                        *   '<S303>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S240>/Constant2'
                                   *   '<S261>/Constant2'
                                   *   '<S282>/Constant2'
                                   *   '<S303>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S240>/Saturation'
                                        *   '<S261>/Saturation'
                                        *   '<S282>/Saturation'
                                        *   '<S303>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S240>/Saturation'
                                        *   '<S261>/Saturation'
                                        *   '<S282>/Saturation'
                                        *   '<S303>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S240>/Gain'
                                            *   '<S261>/Gain'
                                            *   '<S282>/Gain'
                                            *   '<S303>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S240>/Gain2'
                                        *   '<S261>/Gain2'
                                        *   '<S282>/Gain2'
                                        *   '<S303>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S240>/Saturation1'
                                         *   '<S261>/Saturation1'
                                         *   '<S282>/Saturation1'
                                         *   '<S303>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S240>/Saturation1'
                                        *   '<S261>/Saturation1'
                                        *   '<S282>/Saturation1'
                                        *   '<S303>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S240>/Gain1'
                                        *   '<S261>/Gain1'
                                        *   '<S282>/Gain1'
                                        *   '<S303>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S245>/Constant'
                            *   '<S266>/Constant'
                            *   '<S287>/Constant'
                            *   '<S308>/Constant'
                            */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S159>/BlueAllianceZoneX'
                                         *   '<S161>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S132>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S132>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S132>/Constant1'
                                        *   '<S132>/Switch3'
                                        */
real_T Field_Pass_Y_Bottom = 0.63297;  /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S132>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 7.4364;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S132>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S160>/RedAllianceZoneX'
                                         *   '<S162>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S132>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S132>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S395>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S395>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = 0.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S127>/Constant'
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
                                   * Referenced by: '<S112>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S112>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S46>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                        * Referenced by: '<S46>/Gain1'
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
                                            *   '<S42>/Constant'
                                            */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S43>/Constant'
                                            */
real_T Rebuilt_Intake_Meas_In_Disable = -20.0;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S44>/Constant'
                                      */
real_T Rebuilt_Intake_Meas_Out_Disable = 80.0;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S45>/Constant'
                                     */
real_T Rebuilt_Intake_RL_Dec = -3.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S40>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 3.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S40>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 27.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S150>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 33.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by: '<S155>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 32.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S146>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 57.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S147>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 82.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S148>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 107.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S149>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S151>/Unit Delay'
                                      *   '<S152>/Unit Delay'
                                      *   '<S153>/Unit Delay'
                                      *   '<S154>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_TeleOp = 140.0;/* Variable: Rebuilt_Match_Time_TeleOp
                                          * Referenced by: '<S118>/Constant'
                                          */
real_T Rebuilt_Match_Time_Transition = 7.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S144>/Constant'
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
                                * Referenced by: '<S41>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00012732;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                                  * Referenced by: '<S54>/Gain'
                                                  */
real_T Rebuilt_Roller_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                             * Referenced by: '<S54>/Gain2'
                                             */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0001;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                             * Referenced by: '<S54>/Gain1'
                                             */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S133>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S133>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S133>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S133>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S133>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S133>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S133>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S133>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S129>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S129>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S129>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 2.7; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S129>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S129>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S129>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S129>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S129>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S130>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S130>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S130>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S130>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S130>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S130>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S130>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S130>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S120>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S120>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S120>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2700.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S143>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2900.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S143>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3150.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S143>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3300.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S143>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S143>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3650.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S143>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3850.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S143>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S143>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S142>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3200.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S142>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3450.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S142>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3600.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S142>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3800.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S142>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3950.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S142>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S142>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S142>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S136>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S136>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S136>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S136>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S136>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S136>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S136>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S136>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S140>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S121>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S164>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S164>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.001;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                             * Referenced by: '<S164>/Gain1'
                                             */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S131>/Constant2'
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
                              * Referenced by: '<S123>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S169>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S169>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S169>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S394>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S392>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S394>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S395>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S395>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S229>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S229>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S176>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S189>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S229>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S336>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S336>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S336>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S336>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S336>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S336>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S353>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S353>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S353>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S353>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S352>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S353>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S353>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S353>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S353>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S353>/Constant1'
                                   *   '<S353>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S353>/Constant'
                                   *   '<S353>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S243>/Constant3'
                                        *   '<S264>/Constant3'
                                        *   '<S285>/Constant3'
                                        *   '<S306>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S243>/Constant2'
                                *   '<S264>/Constant2'
                                *   '<S285>/Constant2'
                                *   '<S306>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S243>/Saturation'
                                           *   '<S264>/Saturation'
                                           *   '<S285>/Saturation'
                                           *   '<S306>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S243>/Saturation'
                                          *   '<S264>/Saturation'
                                          *   '<S285>/Saturation'
                                          *   '<S306>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S243>/Gain2'
                                         *   '<S264>/Gain2'
                                         *   '<S285>/Gain2'
                                         *   '<S306>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S243>/Saturation1'
                                             *   '<S264>/Saturation1'
                                             *   '<S285>/Saturation1'
                                             *   '<S306>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S243>/Saturation1'
                                            *   '<S264>/Saturation1'
                                            *   '<S285>/Saturation1'
                                            *   '<S306>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S243>/Gain1'
                                        *   '<S264>/Gain1'
                                        *   '<S285>/Gain1'
                                        *   '<S306>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S335>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S335>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S335>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S335>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S335>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S335>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S394>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S394>/Constant1'
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
                                      * Referenced by: '<S393>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S393>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S393>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S323>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S323>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S323>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S323>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S323>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S323>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S395>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S394>/Dead Zone'
                                        *   '<S395>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S394>/Dead Zone'
                                        *   '<S395>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S392>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S392>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S392>/Constant4'
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
                                        * Referenced by: '<S392>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S392>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S392>/Constant5'
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
                                        *   '<S392>/Constant11'
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
 *    '<S118>/If Action Subsystem1'
 *    '<S118>/If Action Subsystem3'
 */
void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S151>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S118>/If Action Subsystem1'
 *    '<S118>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* Logic: '<S151>/NOT' incorporates:
   *  SignalConversion generated from: '<S151>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S151>/IsRedActive' */
  *rty_IsRedActive = rtu_IsBlueInactiveFirst;

  /* SignalConversion: '<S151>/Signal Copy' incorporates:
   *  Constant: '<S151>/Constant1'
   *  Sum: '<S151>/Sum'
   *  UnitDelay: '<S151>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S151>/Unit Delay' incorporates:
   *  Constant: '<S151>/Constant1'
   *  Sum: '<S151>/Sum'
   */
  localDW->UnitDelay_DSTATE -= 0.02;
}

/*
 * System initialize for action system:
 *    '<S118>/If Action Subsystem2'
 *    '<S118>/If Action Subsystem4'
 */
void Robot_C_IfActionSubsystem2_Init(DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S152>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S118>/If Action Subsystem2'
 *    '<S118>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive, real_T
  *rty_Time_Remaining, DW_IfActionSubsystem2_Robot_C_T *localDW)
{
  /* Logic: '<S152>/NOT1' incorporates:
   *  SignalConversion generated from: '<S152>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S152>/IsBlueActive' */
  *rty_IsBlueActive = rtu_IsBlueInactiveFirst;

  /* SignalConversion: '<S152>/Signal Copy' incorporates:
   *  Constant: '<S152>/Constant1'
   *  Sum: '<S152>/Sum'
   *  UnitDelay: '<S152>/Unit Delay'
   */
  *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;

  /* Update for UnitDelay: '<S152>/Unit Delay' incorporates:
   *  Constant: '<S152>/Constant1'
   *  Sum: '<S152>/Sum'
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
  real_T rtb_Sum1_fh;
  real_T rtb_Sum1_l;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1;
  real_T rtb_Switch1_b0;
  real_T rtb_Switch2;
  real_T rtb_Switch2_be;
  real_T rtb_Switch2_p2;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s201_iter;
  uint16_T s226_iter;
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

  /* If: '<S421>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S421>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S424>/Action Port'
     */
    /* Product: '<S424>/Product' incorporates:
     *  Constant: '<S424>/Constant1'
     *  Constant: '<S424>/Constant2'
     *  Math: '<S424>/Math Function'
     */
    rtb_Subtract_c3 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S421>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S421>/Subsystem' incorporates:
     *  ActionPort: '<S425>/Action Port'
     */
    /* SignalConversion generated from: '<S425>/Out1' incorporates:
     *  Constant: '<S425>/Constant'
     */
    rtb_Subtract_c3 = 0.0;

    /* End of Outputs for SubSystem: '<S421>/Subsystem' */
  }

  /* End of If: '<S421>/If' */

  /* Gain: '<S422>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S423>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Subtract_c3 * cos(rtb_Sin4))
    + Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S423>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Subtract_c3 * sin(rtb_Sin4))
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
      rtb_Swerve_Motors_Disabled = (rtb_Switch1_b0 >= Auto_Shoot_Time);
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
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) + 39];
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
            rtb_Swerve_Motors_Disabled) {
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
       *  UnitDelay: '<S394>/Unit Delay1'
       *  UnitDelay: '<S394>/Unit Delay2'
       *  UnitDelay: '<S394>/Unit Delay3'
       *  UnitDelay: '<S394>/Unit Delay4'
       *  UnitDelay: '<S397>/Delay Input1'
       *  UnitDelay: '<S398>/Delay Input1'
       *  UnitDelay: '<S399>/Delay Input1'
       *  UnitDelay: '<S400>/Delay Input1'
       *  UnitDelay: '<S402>/Delay Input1'
       *  UnitDelay: '<S408>/Unit Delay'
       *  UnitDelay: '<S408>/Unit Delay1'
       *  UnitDelay: '<S412>/FixPt Unit Delay1'
       *  UnitDelay: '<S412>/FixPt Unit Delay2'
       *
       * Block description for '<S397>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S398>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S399>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S400>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S402>/Delay Input1':
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

    /* Switch: '<S392>/Switch4' incorporates:
     *  Constant: '<S417>/Constant'
     *  Constant: '<S420>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S417>/Compare'
     *  RelationalOperator: '<S420>/Compare'
     *  Switch: '<S392>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S392>/Switch4' incorporates:
       *  Constant: '<S392>/Constant8'
       *  Sum: '<S392>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S392>/Switch5' incorporates:
       *  Constant: '<S392>/Constant7'
       *  Gain: '<S392>/Gain'
       *  Sum: '<S392>/Subtract5'
       *  Switch: '<S392>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S392>/Switch4' incorporates:
       *  Constant: '<S392>/Constant6'
       *  Switch: '<S392>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S392>/Switch4' */

    /* Logic: '<S392>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S392>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S394>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_a5 = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_a5 = 0.0;
    } else {
      rtb_Add_a5 = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S394>/Add' incorporates:
     *  Constant: '<S394>/Constant'
     *  Constant: '<S394>/Constant1'
     *  DeadZone: '<S394>/Dead Zone'
     *  Lookup_n-D: '<S394>/Modulation_Str_Y_Rel'
     *  Product: '<S394>/Product'
     *  Product: '<S394>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Subtract_c3 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                       Steering_Relative_Gain) + (rtb_Add_a5 *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S396>/Compare' incorporates:
     *  Constant: '<S396>/Constant'
     */
    rtb_Compare_ik = (rtb_Subtract_c3 == 0.0);

    /* Logic: '<S394>/AND2' incorporates:
     *  RelationalOperator: '<S397>/FixPt Relational Operator'
     *  RelationalOperator: '<S398>/FixPt Relational Operator'
     *  RelationalOperator: '<S399>/FixPt Relational Operator'
     *  RelationalOperator: '<S400>/FixPt Relational Operator'
     *  UnitDelay: '<S397>/Delay Input1'
     *  UnitDelay: '<S398>/Delay Input1'
     *  UnitDelay: '<S399>/Delay Input1'
     *  UnitDelay: '<S400>/Delay Input1'
     *
     * Block description for '<S397>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S398>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S399>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S400>/Delay Input1':
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

    /* Logic: '<S394>/AND1' incorporates:
     *  Logic: '<S394>/AND3'
     *  UnitDelay: '<S394>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_ik && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S394>/AND4' incorporates:
     *  Logic: '<S394>/AND8'
     *  UnitDelay: '<S394>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_ik && (!rtb_Intake_Arm_Cycle)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S394>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S394>/Switch8' incorporates:
     *  Constant: '<S403>/Constant'
     *  Logic: '<S394>/AND9'
     *  RelationalOperator: '<S402>/FixPt Relational Operator'
     *  RelationalOperator: '<S403>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S402>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S402>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_ik) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S394>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S394>/Switch8' incorporates:
       *  UnitDelay: '<S394>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S394>/Switch8' */

    /* Switch: '<S394>/Switch4' incorporates:
     *  Constant: '<S394>/Constant5'
     *  Switch: '<S394>/Switch1'
     *  Switch: '<S394>/Switch5'
     *  Switch: '<S394>/Switch6'
     *  Switch: '<S394>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Switch1_b0 = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S394>/Switch5' incorporates:
       *  Constant: '<S394>/Constant6'
       */
      rtb_Switch1_b0 = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S394>/Switch6' incorporates:
       *  Constant: '<S394>/Constant7'
       *  Switch: '<S394>/Switch5'
       */
      rtb_Switch1_b0 = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S394>/Switch7' incorporates:
       *  Constant: '<S394>/Constant8'
       *  Switch: '<S394>/Switch5'
       *  Switch: '<S394>/Switch6'
       */
      rtb_Switch1_b0 = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S394>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S394>/Switch5'
       *  Switch: '<S394>/Switch6'
       *  Switch: '<S394>/Switch7'
       */
      rtb_Switch1_b0 = 0.0;
    } else {
      /* Switch: '<S394>/Switch6' incorporates:
       *  Switch: '<S394>/Switch5'
       *  Switch: '<S394>/Switch7'
       *  UnitDelay: '<S394>/Unit Delay1'
       */
      rtb_Switch1_b0 = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S394>/Switch4' */

    /* Switch: '<S394>/Switch2' incorporates:
     *  Switch: '<S394>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S394>/Switch2' incorporates:
       *  Constant: '<S394>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S394>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Switch1_b0;
    } else {
      /* Switch: '<S394>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S394>/Switch3' incorporates:
       *  Constant: '<S394>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S394>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S394>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S393>/Switch1' incorporates:
     *  Constant: '<S393>/Constant5'
     *  Constant: '<S393>/Constant8'
     *  DataTypeConversion: '<S393>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_ik;
    }

    /* End of Switch: '<S393>/Switch1' */

    /* Lookup_n-D: '<S395>/Modulation_Drv' incorporates:
     *  Math: '<S395>/Magnitude'
     */
    rtb_Sin4 = look1_binlcpw(rt_hypotd_snf(Robot_Control_B.Drive_Joystick_X,
      Robot_Control_B.Drive_Joystick_Y), rtCP_Modulation_Drv_bp01Data,
      rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S406>/Compare' incorporates:
     *  Constant: '<S406>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Sin4 == 0.0);

    /* DeadZone: '<S395>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S395>/Dead Zone' */

    /* Logic: '<S395>/Logical Operator' incorporates:
     *  Constant: '<S407>/Constant'
     *  RelationalOperator: '<S407>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_DeadZone != 0.0) && rtb_Swerve_Motors_Disabled);

    /* Switch: '<S393>/Switch' incorporates:
     *  Constant: '<S393>/Constant5'
     *  Constant: '<S393>/Constant7'
     *  DataTypeConversion: '<S393>/Data Type Conversion'
     *  Logic: '<S395>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S393>/Switch' */

    /* Switch: '<S392>/Switch2' incorporates:
     *  Constant: '<S392>/Constant2'
     *  Constant: '<S416>/Constant'
     *  Constant: '<S419>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S416>/Compare'
     *  RelationalOperator: '<S419>/Compare'
     *  Sum: '<S392>/Subtract'
     *  Switch: '<S392>/Switch'
     *  Switch: '<S392>/Switch1'
     *  Switch: '<S392>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S392>/Switch2' incorporates:
       *  Constant: '<S392>/Constant5'
       *  Sum: '<S392>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S392>/Switch2' incorporates:
       *  Constant: '<S392>/Constant4'
       *  Sum: '<S392>/Subtract2'
       *  Switch: '<S392>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S392>/Switch1' incorporates:
       *  Constant: '<S392>/Constant1'
       *  Sum: '<S392>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S392>/Switch2' incorporates:
       *  Constant: '<S392>/Constant3'
       *  Switch: '<S392>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S392>/Switch1' incorporates:
       *  Constant: '<S392>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S392>/Switch2' */

    /* UnaryMinus: '<S392>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S408>/Switch1' incorporates:
     *  Constant: '<S413>/Constant'
     *  Constant: '<S414>/Constant'
     *  Logic: '<S408>/AND'
     *  RelationalOperator: '<S413>/Compare'
     *  RelationalOperator: '<S414>/Compare'
     *  Switch: '<S408>/Switch2'
     *  UnitDelay: '<S408>/Unit Delay'
     *  UnitDelay: '<S408>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S408>/Switch1' */

    /* Switch: '<S395>/Switch1' incorporates:
     *  Logic: '<S395>/Logical Operator1'
     *  Switch: '<S395>/Switch4'
     *  Switch: '<S395>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S395>/Sign' */
      if (rtIsNaN(rtb_DeadZone)) {
        rtb_Add_a5 = (rtNaN);
      } else if (rtb_DeadZone < 0.0) {
        rtb_Add_a5 = -1.0;
      } else {
        rtb_Add_a5 = (rtb_DeadZone > 0.0);
      }

      /* Switch: '<S395>/Switch5' incorporates:
       *  Constant: '<S395>/Constant3'
       *  Constant: '<S395>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S395>/Gain3'
       *  Signum: '<S395>/Sign'
       *  Sum: '<S395>/Add'
       *  Switch: '<S395>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_a5) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Switch: '<S395>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S395>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S395>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S395>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S395>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S395>/Switch4'
       *  Trigonometry: '<S395>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S395>/Switch1' */

    /* Switch: '<S405>/Switch1' incorporates:
     *  Constant: '<S405>/Constant'
     *  Constant: '<S405>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S405>/Switch1' */

    /* Switch: '<S412>/Init' incorporates:
     *  UnitDelay: '<S412>/FixPt Unit Delay1'
     *  UnitDelay: '<S412>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S412>/Init' */

    /* Sum: '<S410>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S411>/Switch2' incorporates:
     *  Constant: '<S409>/Constant1'
     *  Constant: '<S409>/Constant3'
     *  RelationalOperator: '<S411>/LowerRelop1'
     *  RelationalOperator: '<S411>/UpperRelop'
     *  Switch: '<S411>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S411>/Switch' incorporates:
       *  Constant: '<S409>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S411>/Switch2' */

    /* Sum: '<S410>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S395>/Switch8' incorporates:
     *  Logic: '<S395>/Logical Operator1'
     *  Switch: '<S395>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S395>/Switch' incorporates:
       *  Gain: '<S395>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_DeadZone;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S395>/Constant5'
       *  Gain: '<S395>/Gain2'
       *  Math: '<S395>/Magnitude1'
       *  MinMax: '<S395>/Min'
       *  Switch: '<S395>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S405>/Product' incorporates:
       *  Switch: '<S395>/Switch2'
       */
      rtb_Add_a5 = rtb_Sin4 * rtb_Init;

      /* Saturate: '<S405>/Saturation' incorporates:
       *  Switch: '<S395>/Switch2'
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

      /* End of Saturate: '<S405>/Saturation' */
    }

    /* End of Switch: '<S395>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S394>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Subtract_c3;

    /* Switch: '<S392>/Switch6' incorporates:
     *  Constant: '<S392>/Constant11'
     *  Switch: '<S392>/Switch7'
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

    /* RelationalOperator: '<S389>/Compare' incorporates:
     *  Constant: '<S389>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S390>/Compare' incorporates:
     *  Constant: '<S390>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S385>/Compare' incorporates:
     *  Constant: '<S385>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S388>/Compare' incorporates:
     *  Constant: '<S388>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S387>/Compare' incorporates:
     *  Constant: '<S387>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S386>/Compare' incorporates:
     *  Constant: '<S386>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* Update for UnitDelay: '<S402>/Delay Input1'
     *
     * Block description for '<S402>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_ik;

    /* Update for UnitDelay: '<S401>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S401>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S397>/Delay Input1'
     *
     * Block description for '<S397>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S398>/Delay Input1'
     *
     * Block description for '<S398>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S399>/Delay Input1'
     *
     * Block description for '<S399>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S400>/Delay Input1'
     *
     * Block description for '<S400>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S394>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S394>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S394>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S394>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Switch1_b0;

    /* Update for UnitDelay: '<S408>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1;

    /* Update for UnitDelay: '<S408>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S412>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S412>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S412>/FixPt Unit Delay1' */
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

  /* Reshape: '<S58>/Reshapey' incorporates:
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

  /* Delay: '<S58>/MemoryX' incorporates:
   *  Constant: '<S58>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S85>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S111>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S78>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S109>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S109>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S58>/C'
     *  Delay: '<S58>/MemoryX'
     *  Product: '<S111>/Product'
     */
    rtb_Switch1_b0 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Switch1_b0;

    /* Sum: '<S109>/Sum' incorporates:
     *  Constant: '<S58>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S109>/C[k]*xhat[k|k-1]'
     *  Product: '<S109>/D[k]*u[k]'
     *  Sum: '<S109>/Add1'
     */
    rtb_Sin4 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Subtract_c3 = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Switch1_b0);

    /* Product: '<S109>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S58>/C'
     *  Delay: '<S58>/MemoryX'
     *  Product: '<S111>/Product'
     */
    rtb_Switch1_b0 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Switch1_b0;

    /* Sum: '<S109>/Sum' incorporates:
     *  Constant: '<S58>/D'
     *  Product: '<S109>/C[k]*xhat[k|k-1]'
     *  Product: '<S109>/D[k]*u[k]'
     *  Sum: '<S109>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Switch1_b0);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S109>/Product3' incorporates:
     *  Constant: '<S59>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Subtract_c3) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S111>/Add1' incorporates:
     *  Product: '<S111>/Product'
     */
    rtb_Switch1_b0 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S109>/Product3' incorporates:
     *  Constant: '<S59>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Subtract_c3) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S111>/Add1' incorporates:
     *  Product: '<S111>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S111>/Product2' incorporates:
     *  Constant: '<S59>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Switch1_b0) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Switch1_b0) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S109>/Product3' incorporates:
       *  Outport: '<S109>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S111>/Product2' incorporates:
       *  Outport: '<S111>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S78>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S85>/Enabled Subsystem' */

  /* Sum: '<S85>/Add' incorporates:
   *  Delay: '<S58>/MemoryX'
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
   *  Constant: '<S226>/Constant'
   *  Logic: '<S226>/AND'
   *  MATLAB Function: '<S176>/Find closest index to curve'
   *  Product: '<S226>/Product'
   *  RelationalOperator: '<S226>/Relational Operator'
   *  RelationalOperator: '<S226>/Relational Operator1'
   *  Selector: '<S226>/Selector'
   *  Selector: '<S226>/Selector1'
   *  Selector: '<S227>/Selector'
   *  Sum: '<S226>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S179>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_hk == 0) {
      /* Disable for If: '<S182>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S184>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_hk = -1;

    /* End of Disable for If: '<S179>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S174>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S174>/Unit Delay'
       *  UnitDelay: '<S175>/Unit Delay'
       *  UnitDelay: '<S177>/Unit Delay'
       *  UnitDelay: '<S177>/Unit Delay1'
       *  UnitDelay: '<S227>/Unit Delay'
       *  UnitDelay: '<S227>/Unit Delay1'
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
     *  ActionPort: '<S174>/Action Port'
     */
    /* Selector: '<S175>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S175>/Selector1' */

    /* Lookup_n-D: '<S174>/Capture Radius' incorporates:
     *  UnitDelay: '<S174>/Unit Delay'
     */
    rtb_Subtract_c3 = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S175>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S175>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S179>/If' incorporates:
     *  RelationalOperator: '<S179>/ '
     *  UnitDelay: '<S175>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_hk;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_hk = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S182>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S184>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S179>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S182>/Action Port'
       */
      /* InitializeConditions for If: '<S179>/If' incorporates:
       *  UnitDelay: '<S182>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S179>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S179>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S182>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S182>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S185>/Action Port'
       */
      /* If: '<S182>/If' incorporates:
       *  Selector: '<S175>/Selector1'
       *  Selector: '<S182>/Selector'
       *  Selector: '<S185>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S182>/Increment_If_Rectangle_Check' */

      /* Sum: '<S182>/Minus' incorporates:
       *  Concatenate: '<S175>/Matrix Concatenate2'
       *  Selector: '<S182>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S182>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S185>/Action Port'
       */
      /* If: '<S182>/If' incorporates:
       *  Selector: '<S175>/Selector1'
       *  Selector: '<S182>/Selector'
       *  Selector: '<S185>/Selector'
       *  Sum: '<S182>/Minus'
       */
      rtb_DeadZone = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S182>/Increment_If_Rectangle_Check' */

      /* Sum: '<S182>/Minus' incorporates:
       *  Concatenate: '<S175>/Matrix Concatenate2'
       *  Selector: '<S182>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_DeadZone;

      /* Math: '<S182>/Hypot' */
      rtb_Switch1_b0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S182>/Equal' */
      rtb_AND1_c = (Robot_Control_B.Spline_Num_Poses ==
                    Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S182>/Switch' incorporates:
       *  Logic: '<S182>/AND'
       *  Logic: '<S182>/OR'
       *  RelationalOperator: '<S182>/Relational Operator'
       *  UnitDelay: '<S182>/Unit Delay'
       */
      rtb_Compare_ik = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
                        ((rtb_Switch1_b0 <= rtb_Subtract_c3) && rtb_AND1_c));

      /* If: '<S182>/If' */
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
        /* Disable for If: '<S184>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S182>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S184>/Action Port'
         */
        /* If: '<S184>/If' incorporates:
         *  RelationalOperator: '<S184>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S184>/Is_Last_Point' incorporates:
           *  ActionPort: '<S187>/Action Port'
           */
          /* InitializeConditions for If: '<S184>/If' incorporates:
           *  UnitDelay: '<S187>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S184>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S184>/Is_Last_Point' incorporates:
           *  ActionPort: '<S187>/Action Port'
           */
          /* Switch: '<S187>/Switch' incorporates:
           *  Constant: '<S189>/Constant'
           *  Logic: '<S187>/OR'
           *  RelationalOperator: '<S189>/Compare'
           *  UnitDelay: '<S187>/Unit Delay'
           */
          rtb_Is_Absolute_Steering = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
            (rtb_Switch1_b0 <= Spline_Stop_Radius));

          /* If: '<S187>/If' */
          if (rtb_Is_Absolute_Steering) {
            /* Outputs for IfAction SubSystem: '<S187>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S190>/Action Port'
             */
            /* Merge: '<S179>/Merge2' incorporates:
             *  Constant: '<S190>/Constant'
             *  SignalConversion generated from: '<S190>/Robot_Reached_Destination'
             */
            rtb_AND1_c = true;

            /* SignalConversion generated from: '<S190>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S190>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = false;

            /* End of Outputs for SubSystem: '<S187>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S187>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S191>/Action Port'
             */
            /* Merge: '<S179>/Merge2' incorporates:
             *  Constant: '<S191>/Constant'
             *  SignalConversion generated from: '<S191>/Robot_Reached_Destination'
             */
            rtb_AND1_c = false;

            /* SignalConversion generated from: '<S191>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S191>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = true;

            /* End of Outputs for SubSystem: '<S187>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S187>/If' */

          /* Merge: '<S179>/Merge4' incorporates:
           *  SignalConversion: '<S187>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S187>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Is_Absolute_Steering;

          /* End of Outputs for SubSystem: '<S184>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S184>/Increment_Search' incorporates:
           *  ActionPort: '<S186>/Action Port'
           */
          /* Merge: '<S179>/Merge2' incorporates:
           *  Constant: '<S186>/Constant'
           *  SignalConversion generated from: '<S186>/Robot_Reached_Destination'
           */
          rtb_AND1_c = false;

          /* SignalConversion generated from: '<S186>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S186>/Constant1'
           */
          rtb_Is_Absolute_Translation_g = false;

          /* Merge: '<S179>/Merge4' incorporates:
           *  Constant: '<S188>/FixPt Constant'
           *  SignalConversion: '<S186>/Signal Copy'
           *  Sum: '<S188>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S184>/Increment_Search' */
        }

        /* End of If: '<S184>/If' */
        /* End of Outputs for SubSystem: '<S182>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S182>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S185>/Action Port'
         */
        /* Sum: '<S192>/FixPt Sum1' incorporates:
         *  Constant: '<S192>/FixPt Constant'
         */
        rtb_Switch1_b0 = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S185>/Selector1' incorporates:
         *  Selector: '<S175>/Selector1'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Ref_Poses[((int32_T)rtb_Switch1_b0)
          - 1];

        /* Sum: '<S193>/Subtract' incorporates:
         *  Selector: '<S185>/Selector1'
         *  Sum: '<S193>/Minus1'
         */
        rtb_Minus_n[0] = rtb_MatrixConcatenate_b_idx_0 - rtb_Init;

        /* Selector: '<S185>/Selector1' incorporates:
         *  Selector: '<S175>/Selector1'
         */
        rtb_Switch1 = rtb_Ref_Poses[((int32_T)rtb_Switch1_b0) + 9];

        /* Sum: '<S193>/Subtract' incorporates:
         *  Selector: '<S185>/Selector1'
         *  Sum: '<S193>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1 - rtb_DeadZone;

        /* Math: '<S193>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S193>/Divide' */
        rtb_Switch1_b0 = rtb_Minus_n[1];

        /* UnaryMinus: '<S193>/Unary Minus' */
        rtb_Switch2_p2 = rtb_Minus_n[0];

        /* Product: '<S193>/Product' incorporates:
         *  Product: '<S193>/Divide'
         *  UnaryMinus: '<S193>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch1_b0 / rtb_Sin4) * rtb_Subtract_c3;
        rtb_Minus_n[1] = ((-rtb_Switch2_p2) / rtb_Sin4) * rtb_Subtract_c3;

        /* Sum: '<S193>/Add1' incorporates:
         *  Sum: '<S193>/Add2'
         *  Sum: '<S193>/Minus'
         */
        rtb_Switch2_p2 = rtb_MatrixConcatenate_b_idx_0 - rtb_Minus_n[0];

        /* Sum: '<S193>/Minus4' incorporates:
         *  Sum: '<S193>/Add2'
         *  Sum: '<S193>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = (rtb_MatrixConcatenate_b_idx_0 +
          rtb_Minus_n[0]) - rtb_Switch2_p2;

        /* Sum: '<S193>/Minus5' incorporates:
         *  Concatenate: '<S175>/Matrix Concatenate2'
         *  Sum: '<S193>/Minus'
         */
        rtb_Minus_k_idx_0 = rtb_Reshapey[0] - rtb_Switch2_p2;

        /* Sum: '<S193>/Add' incorporates:
         *  Sum: '<S193>/Add2'
         *  Sum: '<S193>/Minus1'
         */
        rtb_Switch1_b0 = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S193>/Minus' incorporates:
         *  Sum: '<S193>/Minus1'
         */
        rtb_Switch2_p2 -= rtb_Switch1_b0;

        /* DotProduct: '<S193>/Dot Product' incorporates:
         *  Concatenate: '<S175>/Matrix Concatenate2'
         *  Sum: '<S193>/Minus'
         *  Sum: '<S193>/Minus1'
         *  Sum: '<S193>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Switch1_b0) * rtb_Switch2_p2;

        /* DotProduct: '<S193>/Dot Product1' incorporates:
         *  Sum: '<S193>/Minus'
         */
        rtb_Init = rtb_Switch2_p2 * rtb_Switch2_p2;

        /* DotProduct: '<S193>/Dot Product2' incorporates:
         *  Sum: '<S193>/Minus4'
         *  Sum: '<S193>/Minus5'
         */
        rtb_Switch2 = rtb_MatrixConcatenate_b_idx_0 * rtb_Minus_k_idx_0;

        /* DotProduct: '<S193>/Dot Product3' incorporates:
         *  Sum: '<S193>/Minus4'
         */
        rtb_Minus_k_idx_1 = rtb_MatrixConcatenate_b_idx_0 *
          rtb_MatrixConcatenate_b_idx_0;

        /* Sum: '<S193>/Add1' incorporates:
         *  Sum: '<S193>/Add2'
         *  Sum: '<S193>/Minus'
         */
        rtb_Switch2_p2 = rtb_Switch1 - rtb_Minus_n[1];

        /* Sum: '<S193>/Minus4' incorporates:
         *  Sum: '<S193>/Add2'
         *  Sum: '<S193>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = (rtb_Switch1 + rtb_Minus_n[1]) -
          rtb_Switch2_p2;

        /* Sum: '<S193>/Minus5' incorporates:
         *  Concatenate: '<S175>/Matrix Concatenate2'
         *  Sum: '<S193>/Minus'
         */
        rtb_Minus_k_idx_0 = rtb_Reshapey[1] - rtb_Switch2_p2;

        /* Sum: '<S193>/Add' incorporates:
         *  Sum: '<S193>/Add2'
         *  Sum: '<S193>/Minus1'
         */
        rtb_Switch1_b0 = rtb_DeadZone - rtb_Minus_n[1];

        /* Sum: '<S193>/Minus' incorporates:
         *  Sum: '<S193>/Minus1'
         */
        rtb_Switch2_p2 -= rtb_Switch1_b0;

        /* DotProduct: '<S193>/Dot Product' incorporates:
         *  Concatenate: '<S175>/Matrix Concatenate2'
         *  Sum: '<S193>/Minus'
         *  Sum: '<S193>/Minus1'
         *  Sum: '<S193>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Switch1_b0) * rtb_Switch2_p2;

        /* RelationalOperator: '<S194>/Compare' incorporates:
         *  Constant: '<S194>/Constant'
         */
        rtb_AND1_c = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S193>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S193>/Dot Product1'
         *  Sum: '<S193>/Minus'
         */
        rtb_Is_Absolute_Translation_g = (rtb_Sin4 <= ((rtb_Switch2_p2 *
          rtb_Switch2_p2) + rtb_Init));

        /* DotProduct: '<S193>/Dot Product2' incorporates:
         *  Sum: '<S193>/Minus4'
         *  Sum: '<S193>/Minus5'
         */
        rtb_Sin4 = (rtb_MatrixConcatenate_b_idx_0 * rtb_Minus_k_idx_0) +
          rtb_Switch2;

        /* Merge: '<S179>/Merge4' incorporates:
         *  Constant: '<S195>/Constant'
         *  DataTypeConversion: '<S185>/Data Type Conversion'
         *  DotProduct: '<S193>/Dot Product3'
         *  Logic: '<S193>/AND'
         *  RelationalOperator: '<S193>/LessThanOrEqual1'
         *  RelationalOperator: '<S195>/Compare'
         *  Sum: '<S185>/Add'
         *  Sum: '<S193>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_AND1_c &&
          rtb_Is_Absolute_Translation_g) && (rtb_Sin4 >= 0.0)) && (rtb_Sin4 <=
          ((rtb_MatrixConcatenate_b_idx_0 * rtb_MatrixConcatenate_b_idx_0) +
           rtb_Minus_k_idx_1)))) + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S179>/Merge2' incorporates:
         *  Constant: '<S185>/Constant2'
         *  SignalConversion generated from: '<S185>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S185>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S185>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* End of Outputs for SubSystem: '<S182>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S182>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S183>/Action Port'
         */
        /* Merge: '<S179>/Merge2' incorporates:
         *  Constant: '<S183>/Constant2'
         *  SignalConversion generated from: '<S183>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S183>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S183>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* Merge: '<S179>/Merge4' incorporates:
         *  SignalConversion generated from: '<S183>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S182>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S179>/Merge1' incorporates:
       *  Constant: '<S182>/Constant'
       *  SignalConversion generated from: '<S182>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S182>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_Compare_ik;

      /* End of Outputs for SubSystem: '<S179>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S179>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
      /* Merge: '<S179>/Merge1' incorporates:
       *  Constant: '<S181>/Constant'
       *  SignalConversion generated from: '<S181>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S179>/Merge2' incorporates:
       *  Constant: '<S181>/Constant1'
       *  SignalConversion generated from: '<S181>/Robot_Reached_Destination'
       */
      rtb_AND1_c = false;

      /* SignalConversion generated from: '<S181>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S181>/Constant2'
       */
      rtb_Is_Absolute_Translation_g = false;

      /* Merge: '<S179>/Merge4' incorporates:
       *  SignalConversion generated from: '<S181>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S179>/Escape_Auto_Driving' */
    }

    /* End of If: '<S179>/If' */

    /* If: '<S175>/If1' */
    if (!rtb_Is_Absolute_Translation_g) {
      /* Outputs for IfAction SubSystem: '<S175>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S180>/Action Port'
       */
      /* Bias: '<S196>/Add Constant' incorporates:
       *  Bias: '<S196>/Bias'
       *  Sum: '<S196>/Subtract'
       */
      rtb_Switch1_b0 = ((Robot_Control_B.Spline_Num_Poses -
                         Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S196>/Selector4' incorporates:
       *  Bias: '<S196>/Bias1'
       *  Constant: '<S198>/FixPt Constant'
       *  Sum: '<S198>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S196>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S196>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s201_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S196>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S196>/Selector5' incorporates:
       *  Concatenate: '<S196>/Matrix Concatenate'
       *  Gain: '<S200>/Gain'
       *  Selector: '<S175>/Selector1'
       *  Selector: '<S196>/Selector2'
       *  Selector: '<S196>/Selector3'
       *  Sum: '<S200>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s201_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S196>/Matrix Concatenate' incorporates:
       *  Bias: '<S196>/Add Constant1'
       *  Gain: '<S199>/Gain'
       *  Selector: '<S175>/Selector1'
       *  Selector: '<S196>/Selector'
       *  Selector: '<S196>/Selector1'
       *  Selector: '<S196>/Selector5'
       *  Sum: '<S199>/Subtract'
       */
      s201_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s201_iter;
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

      /* Selector: '<S196>/Selector4' */
      s201_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s201_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S196>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S196>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S196>/Assignment' incorporates:
       *  Concatenate: '<S196>/Matrix Concatenate'
       *  Selector: '<S196>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s201_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S197>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S201>/While Iterator'
       */
      s201_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s201_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s201_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s201_iter] - rtb_Assignment[s201_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Init - rtb_Assignment[s201_iter];
        rtb_Init = rtb_Assignment[s201_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s201_iter + 11];
        rtb_Switch2_p2 = rtb_Assignment[s201_iter + 12];
        rtb_Add2[1] = rtb_Switch2_p2 - rtb_Assignment[s201_iter + 14];
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
            + rtb_Assignment[s201_iter];
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

        if (s201_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s201_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Switch1_b0 - ((real_T)s201_iter);
        rtb_Num_Segments = s201_iter;
        s201_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s201_iter <= 3));

      /* End of Outputs for SubSystem: '<S197>/Sampling_Loop' */

      /* SignalConversion generated from: '<S180>/Position_and_Curvature' incorporates:
       *  Assignment: '<S201>/Assignment'
       *  Merge: '<S175>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S175>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S175>/If Action Subsystem' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      /* Product: '<S178>/Product' incorporates:
       *  Selector: '<S175>/Selector'
       *  Selector: '<S175>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1];

      /* Product: '<S178>/Product1' incorporates:
       *  Selector: '<S175>/Selector'
       *  Selector: '<S175>/Selector1'
       */
      rtb_Switch1_b0 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S178>/Product' incorporates:
         *  Constant: '<S178>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S178>/Product1' incorporates:
         *  Constant: '<S178>/Constant2'
         *  Product: '<S178>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch1_b0;
      }

      /* Assignment: '<S178>/Assignment' incorporates:
       *  Concatenate: '<S178>/Matrix Concatenate'
       *  Merge: '<S175>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S178>/Assignment' */

      /* SignalConversion generated from: '<S178>/Num_Segments' incorporates:
       *  Constant: '<S178>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S175>/If Action Subsystem' */
    }

    /* End of If: '<S175>/If1' */

    /* Concatenate: '<S176>/Matrix Concatenate' incorporates:
     *  Merge: '<S175>/Merge'
     *  Selector: '<S176>/Selector'
     *  Selector: '<S176>/Selector1'
     *  Selector: '<S176>/Selector3'
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

    /* End of Concatenate: '<S176>/Matrix Concatenate' */

    /* MATLAB Function: '<S176>/Distance Along Curve' incorporates:
     *  Concatenate: '<S176>/Matrix Concatenate'
     *  Selector: '<S176>/Selector4'
     *  Selector: '<S176>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s201_iter = 0; s201_iter < 149; s201_iter++) {
      /* Outputs for Iterator SubSystem: '<S197>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S201>/While Iterator'
       */
      rtb_Assignment_d[s201_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s201_iter + 1] -
         rtb_MatrixConcatenate_o[s201_iter], rtb_MatrixConcatenate_o[s201_iter +
         151] - rtb_MatrixConcatenate_o[s201_iter + 150]) +
        rtb_Assignment_d[s201_iter];

      /* End of Outputs for SubSystem: '<S197>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S176>/Distance Along Curve' */

    /* MATLAB Function: '<S176>/Find closest index to curve' incorporates:
     *  Concatenate: '<S176>/Matrix Concatenate'
     *  Selector: '<S176>/Selector4'
     *  Selector: '<S176>/Selector5'
     *  Selector: '<S227>/Selector'
     */
    for (s201_iter = 0; s201_iter < 150; s201_iter++) {
      /* Outputs for Iterator SubSystem: '<S197>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S201>/While Iterator'
       */
      distance_from_robot[s201_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s201_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s201_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S197>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s201_iter = 1;
    } else {
      s201_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s201_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s201_iter == 0) {
      rtb_Switch1_b0 = distance_from_robot[0];
    } else {
      rtb_Switch1_b0 = distance_from_robot[s201_iter - 1];
      for (rtb_Bias1_p = s201_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_b0 > rtb_Sin4) {
          rtb_Switch1_b0 = rtb_Sin4;
        }
      }
    }

    s201_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s201_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_b0) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S227>/Selector' incorporates:
     *  Constant: '<S227>/Constant'
     *  MATLAB Function: '<S176>/Find closest index to curve'
     *  MinMax: '<S227>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s201_iter)) - 1];

    /* If: '<S227>/If' incorporates:
     *  RelationalOperator: '<S227>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S227>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S230>/Action Port'
       */
      /* SignalConversion generated from: '<S230>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S232>/FixPt Sum1' incorporates:
       *  Constant: '<S232>/FixPt Constant'
       */
      rtb_Switch1_b0 = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S230>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S230>/Selector11'
       *  Selector: '<S230>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_b0) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S230>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S230>/Selector1'
       *  Selector: '<S230>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_b0) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S230>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S230>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_b0), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S230>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S230>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S230>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S227>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S227>/Latch' incorporates:
       *  ActionPort: '<S231>/Action Port'
       */
      /* SignalConversion generated from: '<S231>/In1' incorporates:
       *  UnitDelay: '<S227>/Unit Delay1'
       */
      rtb_Switch1_b0 = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S231>/In2' incorporates:
       *  UnitDelay: '<S227>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S227>/Latch' */
    }

    /* End of If: '<S227>/If' */

    /* MinMax: '<S174>/Min' incorporates:
     *  Lookup_n-D: '<S174>/Lookahead Distance'
     *  UnitDelay: '<S174>/Unit Delay'
     */
    rtb_Subtract_c3 = fmin(rtb_Subtract_c3, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S176>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S226>/While Iterator'
     */
    s226_iter = 1U;
    rtb_Compare_ik = true;
    while (rtb_Compare_ik && (s226_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S176>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S226>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s226_iter;
      rtb_Compare_ik = ((rtb_Assignment_d[Robot_Control_B.WhileIterator - 1] <=
                         (rtb_Assignment_d[s201_iter - 1] + rtb_Subtract_c3)) &&
                        (Robot_Control_B.WhileIterator < (((real_T)
        rtb_Num_Segments) * 50.0)));
      s226_iter++;
    }

    /* End of Outputs for SubSystem: '<S176>/Find first index that meets distance target' */

    /* Switch: '<S229>/Switch' incorporates:
     *  Concatenate: '<S176>/Matrix Concatenate'
     *  Constant: '<S176>/Constant'
     *  Constant: '<S226>/Constant'
     *  Constant: '<S229>/Constant'
     *  Constant: '<S229>/Constant1'
     *  Constant: '<S229>/Constant2'
     *  Constant: '<S229>/Constant3'
     *  Logic: '<S226>/AND'
     *  MATLAB Function: '<S176>/Find closest index to curve'
     *  Math: '<S229>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S229>/Max'
     *  MinMax: '<S229>/Min'
     *  MinMax: '<S229>/Min1'
     *  Product: '<S226>/Product'
     *  Product: '<S229>/Divide'
     *  Product: '<S229>/Product'
     *  Product: '<S229>/Product1'
     *  RelationalOperator: '<S176>/Relational Operator'
     *  RelationalOperator: '<S226>/Relational Operator'
     *  RelationalOperator: '<S226>/Relational Operator1'
     *  Selector: '<S176>/Selector10'
     *  Selector: '<S176>/Selector7'
     *  Selector: '<S176>/Selector8'
     *  Selector: '<S176>/Selector9'
     *  Selector: '<S226>/Selector'
     *  Selector: '<S226>/Selector1'
     *  Selector: '<S227>/Selector'
     *  Sqrt: '<S229>/Sqrt'
     *  Sum: '<S176>/Subtract'
     *  Sum: '<S226>/Add'
     *  Sum: '<S229>/Subtract'
     *  Sum: '<S229>/Subtract1'
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

    /* End of Switch: '<S229>/Switch' */

    /* Logic: '<S177>/OR' */
    rtb_Is_Absolute_Translation_g = (rtb_AND1_c ||
      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S177>/Switch1' incorporates:
     *  Switch: '<S177>/Switch'
     *  UnitDelay: '<S177>/Unit Delay'
     */
    if (rtb_Is_Absolute_Translation_g) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S177>/Constant3'
       *  SignalConversion: '<S177>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S177>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Subtract_c3;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S177>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S177>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S176>/Selector6' incorporates:
     *  Concatenate: '<S176>/Matrix Concatenate'
     *  Selector: '<S176>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S176>/Selector2' incorporates:
     *  Concatenate: '<S176>/Matrix Concatenate'
     *  Selector: '<S176>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S177>/Switch2' incorporates:
     *  Sum: '<S233>/Subtract'
     *  Sum: '<S233>/Subtract1'
     *  Trigonometry: '<S233>/Atan2'
     *  UnitDelay: '<S177>/Unit Delay1'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_DeadZone = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_DeadZone = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S177>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S177>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_DeadZone;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S174>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_AND1_c;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S174>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S177>/Constant2'
     *  SignalConversion generated from: '<S174>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S177>/Constant5'
     *  SignalConversion generated from: '<S174>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S177>/Constant6'
     *  SignalConversion generated from: '<S174>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S174>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S175>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S174>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S227>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_b0;

    /* Update for UnitDelay: '<S227>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S177>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S177>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_DeadZone;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S173>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S173>/Constant1'
     *  SignalConversion generated from: '<S173>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S173>/Constant'
     *  SignalConversion generated from: '<S173>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S173>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S173>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S173>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S173>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S173>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S173>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S173>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S323>/Sign2' incorporates:
   *  UnitDelay: '<S323>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S323>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S323>/Product1' incorporates:
   *  Signum: '<S323>/Sign1'
   *  Signum: '<S323>/Sign2'
   */
  rtb_Add_a5 *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_a5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_a5, 256.0);
  }

  /* Switch: '<S323>/Switch' incorporates:
   *  Constant: '<S323>/Constant'
   *  Constant: '<S328>/Constant'
   *  Constant: '<S329>/Constant'
   *  Logic: '<S323>/or'
   *  Product: '<S323>/Product1'
   *  RelationalOperator: '<S328>/Compare'
   *  RelationalOperator: '<S329>/Compare'
   *  UnitDelay: '<S323>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S323>/Switch' */

  /* Switch: '<S334>/Init' incorporates:
   *  UnitDelay: '<S334>/FixPt Unit Delay1'
   *  UnitDelay: '<S334>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Subtract_c3 = rtb_Sin4;
  } else {
    rtb_Subtract_c3 = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S334>/Init' */

  /* RelationalOperator: '<S330>/Compare' incorporates:
   *  Constant: '<S330>/Constant'
   */
  rtb_Compare_ik = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S331>/Compare' incorporates:
   *  Constant: '<S331>/Constant'
   */
  rtb_AND1_c = (rtb_Sin4 > 0.0);

  /* Abs: '<S323>/Abs' incorporates:
   *  Sum: '<S323>/Subtract'
   *  UnitDelay: '<S323>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S323>/Switch5' incorporates:
   *  Constant: '<S323>/Constant1'
   *  Switch: '<S323>/Switch1'
   *  UnaryMinus: '<S323>/Unary Minus'
   */
  if (rtb_Compare_ik) {
    /* SignalConversion generated from: '<S323>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S323>/Constant4'
     *  Constant: '<S323>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S323>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S323>/Constant2'
     *  Constant: '<S323>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S323>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S323>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S323>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S323>/Constant10'
     *  Constant: '<S323>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S323>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S323>/Constant7'
     *  Constant: '<S323>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S323>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S323>/Lookup Table Dynamic1'
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

    /* Switch: '<S323>/Switch3' incorporates:
     *  Constant: '<S323>/Constant1'
     *  Constant: '<S323>/Constant3'
     *  UnaryMinus: '<S323>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_a5 = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_a5 = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S323>/Switch3' */
  }

  /* End of Switch: '<S323>/Switch5' */

  /* Product: '<S323>/Product' incorporates:
   *  Switch: '<S323>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_a5 * rtb_Merge1;

  /* Sum: '<S332>/Sum1' */
  rtb_Switch1_b0 = rtb_Sin4 - rtb_Subtract_c3;

  /* Switch: '<S333>/Switch2' incorporates:
   *  RelationalOperator: '<S333>/LowerRelop1'
   */
  if (!(rtb_Switch1_b0 > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S323>/Switch2' incorporates:
     *  Constant: '<S323>/Constant1'
     *  Switch: '<S323>/Switch4'
     */
    if (rtb_Compare_ik) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S323>/Switch4' incorporates:
       *  Constant: '<S323>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S323>/Switch4' incorporates:
       *  Constant: '<S323>/Constant3'
       *  UnaryMinus: '<S323>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S323>/Switch2' */

    /* Product: '<S323>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S333>/Switch' incorporates:
     *  RelationalOperator: '<S333>/UpperRelop'
     */
    if (rtb_Switch1_b0 < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch1_b0;
    }

    /* End of Switch: '<S333>/Switch' */
  }

  /* End of Switch: '<S333>/Switch2' */

  /* Sum: '<S332>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle +
    rtb_Subtract_c3;

  /* Switch: '<S326>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S326>/Switch' incorporates:
     *  Constant: '<S359>/Constant3'
     *  Constant: '<S359>/Constant4'
     *  Math: '<S359>/Math Function'
     *  Sum: '<S326>/Subtract'
     *  Sum: '<S359>/Add1'
     *  Sum: '<S359>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S326>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S326>/Switch' */

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

  /* Sum: '<S118>/Subtract' incorporates:
   *  Constant: '<S118>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Sin4 = Rebuilt_Match_Time_TeleOp - Robot_Control_U.MatchTime;

  /* If: '<S118>/If' incorporates:
   *  Constant: '<S144>/Constant'
   *  Constant: '<S145>/Constant'
   *  Constant: '<S146>/Constant'
   *  Constant: '<S147>/Constant'
   *  Constant: '<S148>/Constant'
   *  Constant: '<S149>/Constant'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S144>/Compare'
   *  RelationalOperator: '<S145>/Compare'
   *  RelationalOperator: '<S146>/Compare'
   *  RelationalOperator: '<S147>/Compare'
   *  RelationalOperator: '<S148>/Compare'
   *  RelationalOperator: '<S149>/Compare'
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
      /* InitializeConditions for IfAction SubSystem: '<S118>/If Action Subsystem' incorporates:
       *  ActionPort: '<S150>/Action Port'
       */
      /* InitializeConditions for If: '<S118>/If' incorporates:
       *  UnitDelay: '<S150>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_ll = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S118>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    /* Merge: '<S118>/Merge' incorporates:
     *  Constant: '<S150>/Constant'
     *  SignalConversion generated from: '<S150>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S118>/Merge1' incorporates:
     *  Constant: '<S150>/Constant'
     *  SignalConversion generated from: '<S150>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S150>/Sum' incorporates:
     *  Constant: '<S150>/Constant1'
     *  UnitDelay: '<S150>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_ll - 0.02;

    /* Merge: '<S118>/Merge2' incorporates:
     *  SignalConversion: '<S150>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S150>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ll = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive,
      &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* Merge: '<S118>/Merge' incorporates:
     *  Constant: '<S155>/Constant'
     *  SignalConversion generated from: '<S155>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S118>/Merge1' incorporates:
     *  Constant: '<S155>/Constant'
     *  SignalConversion generated from: '<S155>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S155>/Sum' incorporates:
     *  Constant: '<S155>/Constant1'
     *  UnitDelay: '<S155>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_n - 0.02;

    /* Merge: '<S118>/Merge2' incorporates:
     *  SignalConversion: '<S155>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S155>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S118>/If' */

  /* If: '<S157>/If' incorporates:
   *  If: '<S158>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S157>/Blue' incorporates:
     *  ActionPort: '<S159>/Action Port'
     */
    /* Merge: '<S157>/Merge' incorporates:
     *  Constant: '<S159>/BlueAllianceZoneX'
     *  Logic: '<S159>/AND'
     *  RelationalOperator: '<S159>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S157>/Blue' */

    /* Outputs for IfAction SubSystem: '<S158>/Blue' incorporates:
     *  ActionPort: '<S161>/Action Port'
     */
    /* Merge: '<S158>/Merge' incorporates:
     *  Constant: '<S161>/BlueAllianceZoneX'
     *  RelationalOperator: '<S161>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S158>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S157>/Red' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    /* Merge: '<S157>/Merge' incorporates:
     *  Constant: '<S160>/RedAllianceZoneX'
     *  Logic: '<S160>/AND'
     *  RelationalOperator: '<S160>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S157>/Red' */

    /* Outputs for IfAction SubSystem: '<S158>/Red' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    /* Merge: '<S158>/Merge' incorporates:
     *  Constant: '<S162>/RedAllianceZoneX'
     *  RelationalOperator: '<S162>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S158>/Red' */
  }

  /* End of If: '<S157>/If' */

  /* RelationalOperator: '<S120>/GreaterThan' incorporates:
   *  Constant: '<S120>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S120>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S120>/Relational Operator' incorporates:
   *  Abs: '<S120>/Abs'
   *  Constant: '<S156>/Constant3'
   *  Constant: '<S156>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S156>/Math Function'
   *  Sum: '<S120>/Subtract'
   *  Sum: '<S156>/Add1'
   *  Sum: '<S156>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S119>/Max' incorporates:
   *  Abs: '<S119>/Abs1'
   *  Abs: '<S119>/Abs2'
   *  Abs: '<S119>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S120>/Relational Operator1' incorporates:
   *  Abs: '<S120>/Abs1'
   *  Constant: '<S120>/Constant2'
   *  Sum: '<S120>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S120>/Relational Operator4' incorporates:
   *  Abs: '<S120>/Abs4'
   *  Constant: '<S120>/Constant1'
   *  Sum: '<S120>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S120>/AND' */
  rtb_Compare_ik = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S120>/AND2' incorporates:
   *  Logic: '<S120>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_ik);

  /* SignalConversion: '<S120>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S120>/AND3' */
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
    /* Outputs for IfAction SubSystem: '<S117>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S126>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S128>/While Iterator'
     */
    /* If: '<S117>/If' incorporates:
     *  Constant: '<S126>/Constant'
     *  Constant: '<S127>/Constant'
     *  Constant: '<S127>/Shooter Assembly Offset in Robot'
     *  Constant: '<S127>/Shooter Assembly Offset in Robot1'
     *  Constant: '<S129>/Constant1'
     *  Constant: '<S129>/Constant10'
     *  Constant: '<S129>/Constant2'
     *  Constant: '<S129>/Constant5'
     *  Constant: '<S129>/Constant6'
     *  Constant: '<S129>/Constant7'
     *  Constant: '<S129>/Constant8'
     *  Constant: '<S129>/Constant9'
     *  Constant: '<S130>/Constant1'
     *  Constant: '<S130>/Constant10'
     *  Constant: '<S130>/Constant2'
     *  Constant: '<S130>/Constant5'
     *  Constant: '<S130>/Constant6'
     *  Constant: '<S130>/Constant7'
     *  Constant: '<S130>/Constant8'
     *  Constant: '<S130>/Constant9'
     *  Constant: '<S131>/Constant'
     *  Constant: '<S131>/Constant1'
     *  Constant: '<S131>/Constant2'
     *  Constant: '<S133>/Constant1'
     *  Constant: '<S133>/Constant10'
     *  Constant: '<S133>/Constant2'
     *  Constant: '<S133>/Constant5'
     *  Constant: '<S133>/Constant6'
     *  Constant: '<S133>/Constant7'
     *  Constant: '<S133>/Constant8'
     *  Constant: '<S133>/Constant9'
     *  Constant: '<S136>/Constant'
     *  Constant: '<S136>/Constant1'
     *  Constant: '<S136>/Constant11'
     *  Constant: '<S136>/Constant2'
     *  Constant: '<S136>/Constant3'
     *  Constant: '<S136>/Constant4'
     *  Constant: '<S136>/Constant5'
     *  Constant: '<S136>/Constant6'
     *  Constant: '<S142>/Constant1'
     *  Constant: '<S142>/Constant10'
     *  Constant: '<S142>/Constant2'
     *  Constant: '<S142>/Constant5'
     *  Constant: '<S142>/Constant6'
     *  Constant: '<S142>/Constant7'
     *  Constant: '<S142>/Constant8'
     *  Constant: '<S142>/Constant9'
     *  Constant: '<S143>/Constant1'
     *  Constant: '<S143>/Constant10'
     *  Constant: '<S143>/Constant2'
     *  Constant: '<S143>/Constant5'
     *  Constant: '<S143>/Constant6'
     *  Constant: '<S143>/Constant7'
     *  Constant: '<S143>/Constant8'
     *  Constant: '<S143>/Constant9'
     *  Gain: '<S134>/Gain1'
     *  Gain: '<S141>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S128>/Memory'
     *  Memory: '<S128>/Memory1'
     *  Memory: '<S128>/Memory2'
     *  Memory: '<S128>/Memory3'
     *  Merge: '<S117>/Merge'
     *  Merge: '<S117>/Merge2'
     *  Merge: '<S117>/Merge3'
     *  MinMax: '<S127>/Max'
     *  Product: '<S127>/Divide'
     *  RelationalOperator: '<S131>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S129>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S130>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S131>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S131>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S129>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S136>/Lookup Table Dynamic'
     *  Sum: '<S127>/Add'
     *  Sum: '<S127>/Subtract'
     *  Sum: '<S127>/Subtract1'
     *  Sum: '<S131>/Add'
     *  Switch: '<S131>/Switch'
     *  Switch: '<S131>/Switch1'
     *  Switch: '<S132>/Switch4'
     *  Switch: '<S132>/Switch5'
     *  Switch: '<S132>/Switch6'
     *  Trigonometry: '<S127>/Tanh'
     *  Trigonometry: '<S127>/Tanh1'
     *  UnitDelay: '<S131>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S126>/Iterate_Shot_Target' */
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
      /* Switch: '<S132>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S132>/Switch4' incorporates:
         *  Constant: '<S132>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S132>/Switch4' incorporates:
         *  Constant: '<S132>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S132>/Switch2' */

      /* Switch: '<S132>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S132>/Switch6' incorporates:
         *  Constant: '<S132>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S132>/Switch6' incorporates:
         *  Constant: '<S132>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S132>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S132>/Switch5' incorporates:
         *  Constant: '<S132>/Constant8'
         *  Switch: '<S132>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S132>/Switch4' incorporates:
         *  Constant: '<S132>/Constant9'
         *  Switch: '<S132>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S132>/Switch6' incorporates:
       *  Constant: '<S132>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S126>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S128>/While Iterator'
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
      /* Switch: '<S137>/Switch' incorporates:
       *  Memory: '<S128>/Memory1'
       *  Memory: '<S128>/Memory2'
       *  Switch: '<S137>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_DeadZone = rtb_Subtract_c3;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_DeadZone = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S137>/Switch' */

      /* Math: '<S135>/Hypot' incorporates:
       *  Sum: '<S135>/Subtract'
       *  Sum: '<S135>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_DeadZone -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S136>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S136>/Lookup Table Dynamic'
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

      /* Sum: '<S138>/Subtract' incorporates:
       *  Memory: '<S128>/Memory3'
       *  Sum: '<S138>/Subtract1'
       */
      rtb_Merge1 = rtb_TOF - rtb_Switch1_b0;

      /* Sum: '<S138>/Add' incorporates:
       *  Gain: '<S138>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S138>/Product'
       *  Sum: '<S138>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S138>/Add1' incorporates:
       *  Gain: '<S138>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S138>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_DeadZone;

      /* Memory: '<S128>/Memory' */
      rtb_Compare_ik = rtb_Button_Spinup_Enable;

      /* Update for Memory: '<S128>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S128>/Memory2' */
      rtb_Subtract_c3 = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S128>/Memory3' */
      rtb_Switch1_b0 = rtb_TOF;

      /* Update for Memory: '<S128>/Memory' incorporates:
       *  Constant: '<S140>/Constant'
       *  Math: '<S139>/Hypot'
       *  RelationalOperator: '<S140>/Compare'
       *  Sum: '<S139>/Subtract'
       *  Sum: '<S139>/Subtract1'
       */
      rtb_Button_Spinup_Enable = (rt_hypotd_snf
        (Robot_Control_B.RB_Desired_Target_X - rtb_Sin4,
         Robot_Control_B.RB_Desired_Target_Y - rtb_DeadZone) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S126>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S130>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S129>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S131>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S131>/Lookup Table Dynamic1'
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
      /* Merge: '<S117>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S117>/Merge1' */
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

    /* End of Outputs for SubSystem: '<S117>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_a5 = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Minus_k_idx_1 = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S117>/Shooter Not Active' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* If: '<S117>/If' incorporates:
     *  Constant: '<S125>/Constant'
     *  Constant: '<S125>/Constant1'
     *  Constant: '<S125>/Constant2'
     *  Merge: '<S117>/Merge'
     *  Merge: '<S117>/Merge1'
     *  Merge: '<S117>/Merge2'
     *  Merge: '<S117>/Merge3'
     *  SignalConversion generated from: '<S125>/Desired_Gyro_Angle'
     *  UnitDelay: '<S117>/Unit Delay'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot =
      Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S117>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_a5 = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S354>/Add1' incorporates:
   *  Constant: '<S354>/Constant3'
   *  Constant: '<S354>/Constant4'
   *  Math: '<S354>/Math Function'
   *  Sum: '<S353>/Sum'
   *  Sum: '<S354>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Switch2_p2 = rt_modd_snf((rtb_Add_a5 - rtb_Minus_k_idx_1) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S356>/Sum1' incorporates:
   *  Constant: '<S353>/Constant2'
   *  Product: '<S356>/Product'
   *  Sum: '<S356>/Sum'
   *  UnitDelay: '<S356>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S353>/Product' incorporates:
   *  Constant: '<S353>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S355>/Diff' incorporates:
   *  UnitDelay: '<S355>/UD'
   *
   * Block description for '<S355>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S355>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S353>/Saturation' */
  if (rtb_Add_a5 > Steering_Heading_Control_D_UL) {
    rtb_Add_a5 = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Heading_Control_D_LL) {
    rtb_Add_a5 = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S353>/Add' incorporates:
   *  Gain: '<S353>/Gain1'
   *  Saturate: '<S353>/Saturation'
   */
  rtb_Switch1_b0 = (Steering_Heading_Control_P * rtb_Switch2_p2) + rtb_Add_a5;

  /* Sum: '<S353>/Subtract' incorporates:
   *  Constant: '<S353>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Switch1_b0;

  /* Sum: '<S353>/Sum2' incorporates:
   *  Gain: '<S353>/Gain2'
   *  UnitDelay: '<S353>/Unit Delay'
   */
  rtb_Subtract_c3 = (Steering_Heading_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S358>/Switch2' incorporates:
   *  RelationalOperator: '<S358>/LowerRelop1'
   */
  if (!(rtb_Subtract_c3 > rtb_Sin4)) {
    /* Sum: '<S353>/Subtract1' incorporates:
     *  Constant: '<S353>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Switch1_b0;

    /* Switch: '<S358>/Switch' incorporates:
     *  RelationalOperator: '<S358>/UpperRelop'
     */
    if (!(rtb_Subtract_c3 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Subtract_c3;
    }

    /* End of Switch: '<S358>/Switch' */
  }

  /* End of Switch: '<S358>/Switch2' */

  /* Saturate: '<S353>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_LL;
  } else {
    rtb_Subtract_c3 = rtb_Sin4;
  }

  /* End of Saturate: '<S353>/Saturation1' */

  /* Sum: '<S353>/Add1' */
  rtb_Add_a5 = rtb_Switch1_b0 + rtb_Subtract_c3;

  /* Saturate: '<S353>/Saturation2' */
  if (rtb_Add_a5 > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S353>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_a5 < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S353>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S353>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_a5;
  }

  /* End of Saturate: '<S353>/Saturation2' */

  /* Switch: '<S337>/Switch' incorporates:
   *  Abs: '<S337>/Abs'
   *  Constant: '<S337>/Constant'
   *  Constant: '<S352>/Constant'
   *  RelationalOperator: '<S352>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Sin4 = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S337>/Switch' */

  /* Signum: '<S336>/Sign2' incorporates:
   *  UnitDelay: '<S336>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S336>/Sign1' */
  if (rtIsNaN(rtb_Sin4)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Sin4 < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Sin4 > 0.0);
  }

  /* Product: '<S336>/Product1' incorporates:
   *  Signum: '<S336>/Sign1'
   *  Signum: '<S336>/Sign2'
   */
  rtb_Add_a5 *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_a5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_a5, 256.0);
  }

  /* Switch: '<S336>/Switch' incorporates:
   *  Constant: '<S336>/Constant'
   *  Constant: '<S345>/Constant'
   *  Constant: '<S346>/Constant'
   *  Logic: '<S336>/or'
   *  Product: '<S336>/Product1'
   *  RelationalOperator: '<S345>/Compare'
   *  RelationalOperator: '<S346>/Compare'
   *  UnitDelay: '<S336>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Sin4;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S336>/Switch' */

  /* Switch: '<S351>/Init' incorporates:
   *  UnitDelay: '<S351>/FixPt Unit Delay1'
   *  UnitDelay: '<S351>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S351>/Init' */

  /* RelationalOperator: '<S347>/Compare' incorporates:
   *  Constant: '<S347>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S348>/Compare' incorporates:
   *  Constant: '<S348>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S336>/Abs' incorporates:
   *  Sum: '<S336>/Subtract'
   *  UnitDelay: '<S336>/Unit Delay'
   */
  rtb_Switch1_b0 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d - rtb_Sin4);

  /* Switch: '<S336>/Switch5' incorporates:
   *  Constant: '<S336>/Constant1'
   *  Switch: '<S336>/Switch1'
   *  UnaryMinus: '<S336>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    /* SignalConversion generated from: '<S336>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S336>/Constant4'
     *  Constant: '<S336>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S336>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S336>/Constant2'
     *  Constant: '<S336>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S336>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S336>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S336>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S336>/Constant10'
     *  Constant: '<S336>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S336>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S336>/Constant7'
     *  Constant: '<S336>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S336>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S336>/Lookup Table Dynamic1'
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

    /* Switch: '<S336>/Switch3' incorporates:
     *  Constant: '<S336>/Constant1'
     *  Constant: '<S336>/Constant3'
     *  UnaryMinus: '<S336>/Unary Minus'
     */
    if (rtb_Button_Shoot_Enable) {
      rtb_Add_a5 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_a5 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S336>/Switch3' */
  }

  /* End of Switch: '<S336>/Switch5' */

  /* Product: '<S336>/Product' incorporates:
   *  Switch: '<S336>/Switch1'
   */
  rtb_Init = rtb_Add_a5 * rtb_Switch1_b0;

  /* Sum: '<S349>/Sum1' */
  rtb_Sin4 = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S350>/Switch2' incorporates:
   *  RelationalOperator: '<S350>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Init)) {
    /* Switch: '<S336>/Switch2' incorporates:
     *  Constant: '<S336>/Constant1'
     *  Switch: '<S336>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_DeadZone = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S336>/Switch4' incorporates:
       *  Constant: '<S336>/Constant1'
       */
      rtb_DeadZone = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S336>/Switch4' incorporates:
       *  Constant: '<S336>/Constant3'
       *  UnaryMinus: '<S336>/Unary Minus1'
       */
      rtb_DeadZone = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S336>/Switch2' */

    /* Product: '<S336>/Product2' */
    rtb_DeadZone *= rtb_Switch1_b0;

    /* Switch: '<S350>/Switch' incorporates:
     *  RelationalOperator: '<S350>/UpperRelop'
     */
    if (rtb_Sin4 < rtb_DeadZone) {
      rtb_Init = rtb_DeadZone;
    } else {
      rtb_Init = rtb_Sin4;
    }

    /* End of Switch: '<S350>/Switch' */
  }

  /* End of Switch: '<S350>/Switch2' */

  /* Sum: '<S349>/Sum' */
  rtb_Switch1_b0 = rtb_Init + rtb_Optimized_Module_Angle_p;

  /* Signum: '<S335>/Sign2' incorporates:
   *  UnitDelay: '<S335>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_a5 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S335>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
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
   *  Constant: '<S338>/Constant'
   *  Constant: '<S339>/Constant'
   *  Logic: '<S335>/or'
   *  Product: '<S335>/Product1'
   *  RelationalOperator: '<S338>/Compare'
   *  RelationalOperator: '<S339>/Compare'
   *  UnitDelay: '<S335>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S335>/Switch' */

  /* Switch: '<S344>/Init' incorporates:
   *  UnitDelay: '<S344>/FixPt Unit Delay1'
   *  UnitDelay: '<S344>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S344>/Init' */

  /* RelationalOperator: '<S340>/Compare' incorporates:
   *  Constant: '<S340>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S341>/Compare' incorporates:
   *  Constant: '<S341>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S335>/Abs' incorporates:
   *  Sum: '<S335>/Subtract'
   *  UnitDelay: '<S335>/Unit Delay'
   */
  rtb_DeadZone = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                      Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S335>/Switch1' incorporates:
   *  Constant: '<S335>/Constant1'
   *  Switch: '<S335>/Switch3'
   *  Switch: '<S335>/Switch5'
   *  UnaryMinus: '<S335>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S335>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S335>/Constant1'
     *  Constant: '<S335>/Constant4'
     *  Constant: '<S335>/Constant6'
     *  UnaryMinus: '<S335>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S335>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S335>/Constant2'
     *  Constant: '<S335>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S335>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S335>/Lookup Table Dynamic'
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
      /* Switch: '<S335>/Switch3' incorporates:
       *  Constant: '<S335>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S335>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S335>/Constant1'
     *  Constant: '<S335>/Constant10'
     *  Constant: '<S335>/Constant8'
     *  UnaryMinus: '<S335>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S335>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S335>/Constant7'
     *  Constant: '<S335>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S335>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S335>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S335>/Switch1' */

  /* Product: '<S335>/Product' */
  rtb_Sin4 *= rtb_DeadZone;

  /* Sum: '<S342>/Sum1' */
  rtb_Switch1 = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S343>/Switch2' incorporates:
   *  RelationalOperator: '<S343>/LowerRelop1'
   */
  if (!(rtb_Switch1 > rtb_Sin4)) {
    /* Switch: '<S335>/Switch2' incorporates:
     *  Constant: '<S335>/Constant1'
     *  Switch: '<S335>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S335>/Switch4' incorporates:
       *  Constant: '<S335>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S335>/Switch4' incorporates:
       *  Constant: '<S335>/Constant3'
       *  UnaryMinus: '<S335>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S335>/Switch2' */

    /* Product: '<S335>/Product2' */
    rtb_Sin4 *= rtb_DeadZone;

    /* Switch: '<S343>/Switch' incorporates:
     *  RelationalOperator: '<S343>/UpperRelop'
     */
    if (!(rtb_Switch1 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1;
    }

    /* End of Switch: '<S343>/Switch' */
  }

  /* End of Switch: '<S343>/Switch2' */

  /* Sum: '<S342>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S325>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S325>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch1_b0;
  } else {
    /* Switch: '<S325>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S325>/Switch' */

  /* Fcn: '<S367>/r->x' incorporates:
   *  Fcn: '<S372>/r->x'
   *  Fcn: '<S377>/r->x'
   *  Fcn: '<S382>/r->x'
   */
  rtb_Switch1 = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S361>/Add' incorporates:
   *  Fcn: '<S367>/r->x'
   *  Fcn: '<S368>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1;

  /* Fcn: '<S367>/theta->y' incorporates:
   *  Fcn: '<S372>/theta->y'
   *  Fcn: '<S377>/theta->y'
   *  Fcn: '<S382>/theta->y'
   */
  rtb_DeadZone = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S361>/Add' incorporates:
   *  Fcn: '<S367>/theta->y'
   *  Fcn: '<S368>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S362>/Add' incorporates:
   *  Fcn: '<S373>/r->x'
   *  Fcn: '<S373>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S363>/Add' incorporates:
   *  Fcn: '<S378>/r->x'
   *  Fcn: '<S378>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S364>/Add' incorporates:
   *  Fcn: '<S383>/r->x'
   *  Fcn: '<S383>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_DeadZone;

  /* Fcn: '<S381>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S384>/Compare' incorporates:
   *  Constant: '<S384>/Constant'
   */
  rtb_Compare_ik = (rtb_Init == 0.0);

  /* Switch: '<S380>/Switch1' */
  if (rtb_Compare_ik) {
    /* Switch: '<S380>/Switch1' incorporates:
     *  Constant: '<S380>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S380>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S380>/Switch1' */

  /* Fcn: '<S366>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S369>/Compare' incorporates:
   *  Constant: '<S369>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Init == 0.0);

  /* Switch: '<S365>/Switch1' */
  if (rtb_Button_Spinup_Enable) {
    /* Switch: '<S365>/Switch1' incorporates:
     *  Constant: '<S365>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S365>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S365>/Switch1' */

  /* Fcn: '<S371>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S374>/Compare' incorporates:
   *  Constant: '<S374>/Constant'
   */
  rtb_AND1_c = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S370>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S370>/Switch1' incorporates:
     *  Constant: '<S370>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S370>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S370>/Switch1' */

  /* Fcn: '<S376>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S379>/Compare' incorporates:
   *  Constant: '<S379>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S375>/Switch1' */
  if (rtb_Button_Shoot_Enable) {
    /* Switch: '<S375>/Switch1' incorporates:
     *  Constant: '<S375>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S375>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S375>/Switch1' */

  /* Product: '<S360>/Divide' incorporates:
   *  Abs: '<S360>/Abs'
   *  Abs: '<S360>/Abs1'
   *  Abs: '<S360>/Abs2'
   *  Abs: '<S360>/Abs3'
   *  Constant: '<S360>/Constant'
   *  MinMax: '<S360>/Max'
   */
  rtb_Init = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S360>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S380>/Switch' */
  if (!rtb_Compare_ik) {
    /* Switch: '<S380>/Switch' incorporates:
     *  Fcn: '<S381>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S380>/Switch' */

  /* Trigonometry: '<S315>/Cos4' incorporates:
   *  Switch: '<S304>/Angle_Switch'
   *  Trigonometry: '<S314>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S315>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S313>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S315>/Sin4' incorporates:
   *  Switch: '<S304>/Angle_Switch'
   *  Trigonometry: '<S314>/Sin4'
   */
  rtb_DeadZone = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S315>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S313>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S315>/Subtract1' incorporates:
   *  Product: '<S315>/Product2'
   *  Product: '<S315>/Product3'
   *  Trigonometry: '<S315>/Cos4'
   *  Trigonometry: '<S315>/Sin4'
   */
  rtb_Switch1 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) + (rtb_DeadZone
    * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S315>/Subtract' incorporates:
   *  Product: '<S315>/Product'
   *  Product: '<S315>/Product1'
   *  Trigonometry: '<S315>/Cos4'
   *  Trigonometry: '<S315>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_DeadZone * rtb_Optimized_Module_Angle);

  /* Math: '<S315>/Hypot' */
  rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

  /* Switch: '<S315>/Switch' incorporates:
   *  Constant: '<S315>/Constant'
   *  Constant: '<S315>/Constant1'
   *  Constant: '<S316>/Constant'
   *  Product: '<S315>/Divide'
   *  Product: '<S315>/Divide1'
   *  RelationalOperator: '<S316>/Compare'
   *  Switch: '<S315>/Switch1'
   */
  if (rtb_Minus_k_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1 / rtb_Minus_k_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Minus_k_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S315>/Switch' */

  /* Switch: '<S304>/Speed_Switch' incorporates:
   *  Abs: '<S304>/Abs'
   *  Constant: '<S312>/Constant'
   *  RelationalOperator: '<S312>/Compare'
   *  Switch: '<S304>/Angle_Switch'
   *  Trigonometry: '<S314>/Atan1'
   *  Trigonometry: '<S315>/Atan1'
   *  UnaryMinus: '<S304>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S314>/Subtract1' incorporates:
     *  Product: '<S314>/Product2'
     *  Product: '<S314>/Product3'
     *  UnaryMinus: '<S304>/Unary Minus'
     */
    rtb_Switch1 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_DeadZone * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S314>/Subtract' incorporates:
     *  Product: '<S314>/Product'
     *  Product: '<S314>/Product1'
     */
    rtb_Switch2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_DeadZone * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S314>/Hypot' */
    rtb_DeadZone = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

    /* Switch: '<S314>/Switch1' incorporates:
     *  Constant: '<S314>/Constant'
     *  Constant: '<S314>/Constant1'
     *  Constant: '<S317>/Constant'
     *  Product: '<S314>/Divide'
     *  Product: '<S314>/Divide1'
     *  RelationalOperator: '<S317>/Compare'
     *  Switch: '<S314>/Switch'
     */
    if (rtb_DeadZone > 1.0E-6) {
      rtb_Switch2 /= rtb_DeadZone;
      rtb_DeadZone = rtb_Switch1 / rtb_DeadZone;
    } else {
      rtb_Switch2 = 1.0;
      rtb_DeadZone = 0.0;
    }

    /* End of Switch: '<S314>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_DeadZone, rtb_Switch2);
  } else {
    rtb_Add_a5 = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S307>/Product2' incorporates:
   *  Constant: '<S307>/Constant'
   *  Switch: '<S304>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S302>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S302>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S305>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S306>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S237>/Product' incorporates:
   *  Abs: '<S302>/Abs'
   *  Abs: '<S305>/Abs'
   *  Constant: '<S308>/Constant'
   *  Constant: '<S318>/Constant3'
   *  Constant: '<S318>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S302>/OR'
   *  Lookup_n-D: '<S305>/1-D Lookup Table'
   *  Math: '<S318>/Math Function'
   *  RelationalOperator: '<S302>/Equal1'
   *  RelationalOperator: '<S308>/Compare'
   *  Signum: '<S302>/Sign'
   *  Signum: '<S302>/Sign1'
   *  Sum: '<S305>/Add'
   *  Sum: '<S318>/Add1'
   *  Sum: '<S318>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.BackRight_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                    rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S303>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S310>/Sum1' incorporates:
   *  Constant: '<S303>/Constant2'
   *  Product: '<S310>/Product'
   *  Sum: '<S310>/Sum'
   *  UnitDelay: '<S310>/Unit Delay1'
   */
  rtb_DeadZone = ((rtb_Switch2 - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S303>/Product' incorporates:
   *  Constant: '<S303>/Constant3'
   */
  rtb_Switch1 = rtb_DeadZone * Drive_Motor_Control_D;

  /* Sum: '<S309>/Diff' incorporates:
   *  UnitDelay: '<S309>/UD'
   *
   * Block description for '<S309>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S309>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Switch1 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S303>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S303>/Add' incorporates:
   *  Gain: '<S303>/Gain'
   *  Gain: '<S303>/Gain1'
   *  Saturate: '<S303>/Saturation'
   */
  rtb_Minus_k_idx_0 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0)
                       + (Drive_Motor_Control_P * rtb_Switch2)) + rtb_Add_a5;

  /* Saturate: '<S303>/Saturation2' incorporates:
   *  Sum: '<S303>/Add1'
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

  /* End of Saturate: '<S303>/Saturation2' */

  /* Switch: '<S365>/Switch' */
  if (!rtb_Button_Spinup_Enable) {
    /* Switch: '<S365>/Switch' incorporates:
     *  Fcn: '<S366>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S365>/Switch' */

  /* Trigonometry: '<S252>/Cos4' incorporates:
   *  Switch: '<S241>/Angle_Switch'
   *  Trigonometry: '<S251>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S252>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S250>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S252>/Sin4' incorporates:
   *  Switch: '<S241>/Angle_Switch'
   *  Trigonometry: '<S251>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S252>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S250>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S252>/Subtract1' incorporates:
   *  Product: '<S252>/Product2'
   *  Product: '<S252>/Product3'
   *  Trigonometry: '<S252>/Cos4'
   *  Trigonometry: '<S252>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S252>/Subtract' incorporates:
   *  Product: '<S252>/Product'
   *  Product: '<S252>/Product1'
   *  Trigonometry: '<S252>/Cos4'
   *  Trigonometry: '<S252>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S252>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Switch2, rtb_Minus_k_idx_0);

  /* Switch: '<S252>/Switch' incorporates:
   *  Constant: '<S252>/Constant'
   *  Constant: '<S252>/Constant1'
   *  Constant: '<S253>/Constant'
   *  Product: '<S252>/Divide'
   *  Product: '<S252>/Divide1'
   *  RelationalOperator: '<S253>/Compare'
   *  Switch: '<S252>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0 / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Hypot_g5;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S252>/Switch' */

  /* Product: '<S360>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S241>/Speed_Switch' incorporates:
   *  Abs: '<S241>/Abs'
   *  Constant: '<S249>/Constant'
   *  RelationalOperator: '<S249>/Compare'
   *  Switch: '<S241>/Angle_Switch'
   *  Trigonometry: '<S251>/Atan1'
   *  Trigonometry: '<S252>/Atan1'
   *  UnaryMinus: '<S241>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S251>/Subtract1' incorporates:
     *  Product: '<S251>/Product2'
     *  Product: '<S251>/Product3'
     *  UnaryMinus: '<S241>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S251>/Subtract' incorporates:
     *  Product: '<S251>/Product'
     *  Product: '<S251>/Product1'
     */
    rtb_Hypot_g5 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S251>/Hypot' */
    rtb_Switch2 = rt_hypotd_snf(rtb_Hypot_g5, rtb_Minus_k_idx_0);

    /* Switch: '<S251>/Switch1' incorporates:
     *  Constant: '<S251>/Constant'
     *  Constant: '<S251>/Constant1'
     *  Constant: '<S254>/Constant'
     *  Product: '<S251>/Divide'
     *  Product: '<S251>/Divide1'
     *  RelationalOperator: '<S254>/Compare'
     *  Switch: '<S251>/Switch'
     */
    if (rtb_Switch2 > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Switch2;
      rtb_Minus_k_idx_0 /= rtb_Switch2;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S251>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_0, rtb_Hypot_g5);
  } else {
    rtb_Add_a5 = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S244>/Product2' incorporates:
   *  Constant: '<S244>/Constant'
   *  Switch: '<S241>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S239>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S239>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S242>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S243>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S234>/Product' incorporates:
   *  Abs: '<S239>/Abs'
   *  Abs: '<S242>/Abs'
   *  Constant: '<S245>/Constant'
   *  Constant: '<S255>/Constant3'
   *  Constant: '<S255>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S239>/OR'
   *  Lookup_n-D: '<S242>/1-D Lookup Table'
   *  Math: '<S255>/Math Function'
   *  RelationalOperator: '<S239>/Equal1'
   *  RelationalOperator: '<S245>/Compare'
   *  Signum: '<S239>/Sign'
   *  Signum: '<S239>/Sign1'
   *  Sum: '<S242>/Add'
   *  Sum: '<S255>/Add1'
   *  Sum: '<S255>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S240>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_g5 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S247>/Sum1' incorporates:
   *  Constant: '<S240>/Constant2'
   *  Product: '<S247>/Product'
   *  Sum: '<S247>/Sum'
   *  UnitDelay: '<S247>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_Hypot_g5 - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S240>/Product' incorporates:
   *  Constant: '<S240>/Constant3'
   */
  rtb_Switch2 = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S246>/Diff' incorporates:
   *  UnitDelay: '<S246>/UD'
   *
   * Block description for '<S246>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S246>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S240>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S240>/Add' incorporates:
   *  Gain: '<S240>/Gain'
   *  Gain: '<S240>/Gain1'
   *  Saturate: '<S240>/Saturation'
   */
  rtb_Hypot_g5 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0) +
                  (Drive_Motor_Control_P * rtb_Hypot_g5)) + rtb_Add_a5;

  /* Saturate: '<S240>/Saturation2' incorporates:
   *  Sum: '<S240>/Add1'
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

  /* End of Saturate: '<S240>/Saturation2' */

  /* Sum: '<S256>/Add1' incorporates:
   *  Constant: '<S256>/Constant3'
   *  Constant: '<S256>/Constant4'
   *  Math: '<S256>/Math Function'
   *  Sum: '<S256>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S258>/Sum1' incorporates:
   *  Constant: '<S243>/Constant2'
   *  Product: '<S258>/Product'
   *  Sum: '<S258>/Sum'
   *  UnitDelay: '<S258>/Unit Delay1'
   */
  rtb_Hypot_g5 = ((rtb_MatrixConcatenate_b_idx_0 -
                   Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S243>/Product' incorporates:
   *  Constant: '<S243>/Constant3'
   */
  rtb_MatrixConcatenate_idx_0 = rtb_Hypot_g5 * Steering_Motor_Control_D;

  /* Sum: '<S257>/Diff' incorporates:
   *  UnitDelay: '<S257>/UD'
   *
   * Block description for '<S257>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S257>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_MatrixConcatenate_idx_0 - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S243>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S243>/Add' incorporates:
   *  Gain: '<S243>/Gain1'
   *  Saturate: '<S243>/Saturation'
   */
  rtb_Add_e3 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_a5;

  /* Sum: '<S243>/Subtract' incorporates:
   *  Constant: '<S243>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_e3;

  /* Sum: '<S243>/Sum2' incorporates:
   *  Gain: '<S243>/Gain2'
   *  UnitDelay: '<S243>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S259>/Switch2' incorporates:
   *  Constant: '<S243>/Constant'
   *  RelationalOperator: '<S259>/LowerRelop1'
   *  Sum: '<S243>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_e3))) {
    /* Switch: '<S259>/Switch' incorporates:
     *  Constant: '<S243>/Constant1'
     *  RelationalOperator: '<S259>/UpperRelop'
     *  Sum: '<S243>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_e3)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_e3;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S259>/Switch' */
  }

  /* End of Switch: '<S259>/Switch2' */

  /* Saturate: '<S243>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S243>/Saturation1' */

  /* Sum: '<S243>/Add1' */
  rtb_Add_a5 = rtb_Add_e3 + rtb_Sum2_e;

  /* Saturate: '<S243>/Saturation2' */
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

  /* End of Saturate: '<S243>/Saturation2' */

  /* Switch: '<S370>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S370>/Switch' incorporates:
     *  Fcn: '<S371>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S370>/Switch' */

  /* Trigonometry: '<S273>/Cos4' incorporates:
   *  Switch: '<S262>/Angle_Switch'
   *  Trigonometry: '<S272>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S273>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S271>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S273>/Sin4' incorporates:
   *  Switch: '<S262>/Angle_Switch'
   *  Trigonometry: '<S272>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S273>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S271>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S273>/Subtract1' incorporates:
   *  Product: '<S273>/Product2'
   *  Product: '<S273>/Product3'
   *  Trigonometry: '<S273>/Cos4'
   *  Trigonometry: '<S273>/Sin4'
   */
  rtb_Add_e3 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S273>/Subtract' incorporates:
   *  Product: '<S273>/Product'
   *  Product: '<S273>/Product1'
   *  Trigonometry: '<S273>/Cos4'
   *  Trigonometry: '<S273>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S273>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_e3);

  /* Switch: '<S273>/Switch' incorporates:
   *  Constant: '<S273>/Constant'
   *  Constant: '<S273>/Constant1'
   *  Constant: '<S274>/Constant'
   *  Product: '<S273>/Divide'
   *  Product: '<S273>/Divide1'
   *  RelationalOperator: '<S274>/Compare'
   *  Switch: '<S273>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_e3 / rtb_Hypot_b;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_b;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S273>/Switch' */

  /* Product: '<S360>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S262>/Speed_Switch' incorporates:
   *  Abs: '<S262>/Abs'
   *  Constant: '<S270>/Constant'
   *  RelationalOperator: '<S270>/Compare'
   *  Switch: '<S262>/Angle_Switch'
   *  Trigonometry: '<S272>/Atan1'
   *  Trigonometry: '<S273>/Atan1'
   *  UnaryMinus: '<S262>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S272>/Subtract1' incorporates:
     *  Product: '<S272>/Product2'
     *  Product: '<S272>/Product3'
     *  UnaryMinus: '<S262>/Unary Minus'
     */
    rtb_Add_e3 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S272>/Subtract' incorporates:
     *  Product: '<S272>/Product'
     *  Product: '<S272>/Product1'
     */
    rtb_Hypot_b = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S272>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_b, rtb_Add_e3);

    /* Switch: '<S272>/Switch1' incorporates:
     *  Constant: '<S272>/Constant'
     *  Constant: '<S272>/Constant1'
     *  Constant: '<S275>/Constant'
     *  Product: '<S272>/Divide'
     *  Product: '<S272>/Divide1'
     *  RelationalOperator: '<S275>/Compare'
     *  Switch: '<S272>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_b /= rtb_Subtract1_la;
      rtb_Add_e3 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_b = 1.0;
      rtb_Add_e3 = 0.0;
    }

    /* End of Switch: '<S272>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_e3, rtb_Hypot_b);
  } else {
    rtb_Add_a5 = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S265>/Product2' incorporates:
   *  Constant: '<S265>/Constant'
   *  Switch: '<S262>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S260>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S260>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S263>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S264>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S235>/Product' incorporates:
   *  Abs: '<S260>/Abs'
   *  Abs: '<S263>/Abs'
   *  Constant: '<S266>/Constant'
   *  Constant: '<S276>/Constant3'
   *  Constant: '<S276>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S260>/OR'
   *  Lookup_n-D: '<S263>/1-D Lookup Table'
   *  Math: '<S276>/Math Function'
   *  RelationalOperator: '<S260>/Equal1'
   *  RelationalOperator: '<S266>/Compare'
   *  Signum: '<S260>/Sign'
   *  Signum: '<S260>/Sign1'
   *  Sum: '<S263>/Add'
   *  Sum: '<S276>/Add1'
   *  Sum: '<S276>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) ||
    (fabs(Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Sum: '<S261>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_b = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S268>/Sum1' incorporates:
   *  Constant: '<S261>/Constant2'
   *  Product: '<S268>/Product'
   *  Sum: '<S268>/Sum'
   *  UnitDelay: '<S268>/Unit Delay1'
   */
  rtb_Add_e3 = ((rtb_Hypot_b - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S261>/Product' incorporates:
   *  Constant: '<S261>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_e3 * Drive_Motor_Control_D;

  /* Sum: '<S267>/Diff' incorporates:
   *  UnitDelay: '<S267>/UD'
   *
   * Block description for '<S267>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S267>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S261>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S261>/Add' incorporates:
   *  Gain: '<S261>/Gain'
   *  Gain: '<S261>/Gain1'
   *  Saturate: '<S261>/Saturation'
   */
  rtb_Hypot_b = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0) +
                 (Drive_Motor_Control_P * rtb_Hypot_b)) + rtb_Add_a5;

  /* Saturate: '<S261>/Saturation2' incorporates:
   *  Sum: '<S261>/Add1'
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

  /* End of Saturate: '<S261>/Saturation2' */

  /* Sum: '<S277>/Add1' incorporates:
   *  Constant: '<S277>/Constant3'
   *  Constant: '<S277>/Constant4'
   *  Math: '<S277>/Math Function'
   *  Sum: '<S277>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S279>/Sum1' incorporates:
   *  Constant: '<S264>/Constant2'
   *  Product: '<S279>/Product'
   *  Sum: '<S279>/Sum'
   *  UnitDelay: '<S279>/Unit Delay1'
   */
  rtb_Hypot_b = ((rtb_MatrixConcatenate_b_idx_0 -
                  Robot_Control_DW.UnitDelay1_DSTATE_n) *
                 Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S264>/Product' incorporates:
   *  Constant: '<S264>/Constant3'
   */
  rtb_Switch2_be = rtb_Hypot_b * Steering_Motor_Control_D;

  /* Sum: '<S278>/Diff' incorporates:
   *  UnitDelay: '<S278>/UD'
   *
   * Block description for '<S278>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S278>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Switch2_be - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S264>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S264>/Add' incorporates:
   *  Gain: '<S264>/Gain1'
   *  Saturate: '<S264>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)
    + rtb_Add_a5;

  /* Sum: '<S264>/Subtract' incorporates:
   *  Constant: '<S264>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S264>/Sum2' incorporates:
   *  Gain: '<S264>/Gain2'
   *  UnitDelay: '<S264>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S280>/Switch2' incorporates:
   *  Constant: '<S264>/Constant'
   *  RelationalOperator: '<S280>/LowerRelop1'
   *  Sum: '<S264>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S264>/Constant1'
     *  RelationalOperator: '<S280>/UpperRelop'
     *  Sum: '<S264>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S280>/Switch' */
  }

  /* End of Switch: '<S280>/Switch2' */

  /* Saturate: '<S264>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S264>/Saturation1' */

  /* Sum: '<S264>/Add1' */
  rtb_Add_a5 = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S264>/Saturation2' */
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

  /* End of Saturate: '<S264>/Saturation2' */

  /* Switch: '<S375>/Switch' */
  if (!rtb_Button_Shoot_Enable) {
    /* Switch: '<S375>/Switch' incorporates:
     *  Fcn: '<S376>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S375>/Switch' */

  /* Trigonometry: '<S294>/Cos4' incorporates:
   *  Switch: '<S283>/Angle_Switch'
   *  Trigonometry: '<S293>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S294>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S292>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S294>/Sin4' incorporates:
   *  Switch: '<S283>/Angle_Switch'
   *  Trigonometry: '<S293>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S294>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S292>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S294>/Subtract1' incorporates:
   *  Product: '<S294>/Product2'
   *  Product: '<S294>/Product3'
   *  Trigonometry: '<S294>/Cos4'
   *  Trigonometry: '<S294>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S294>/Subtract' incorporates:
   *  Product: '<S294>/Product'
   *  Product: '<S294>/Product1'
   *  Trigonometry: '<S294>/Cos4'
   *  Trigonometry: '<S294>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S294>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S294>/Switch' incorporates:
   *  Constant: '<S294>/Constant'
   *  Constant: '<S294>/Constant1'
   *  Constant: '<S295>/Constant'
   *  Product: '<S294>/Divide'
   *  Product: '<S294>/Divide1'
   *  RelationalOperator: '<S295>/Compare'
   *  Switch: '<S294>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S294>/Switch' */

  /* Product: '<S360>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S283>/Speed_Switch' incorporates:
   *  Abs: '<S283>/Abs'
   *  Constant: '<S291>/Constant'
   *  RelationalOperator: '<S291>/Compare'
   *  Switch: '<S283>/Angle_Switch'
   *  Trigonometry: '<S293>/Atan1'
   *  Trigonometry: '<S294>/Atan1'
   *  UnaryMinus: '<S283>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_a5 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S293>/Subtract1' incorporates:
     *  Product: '<S293>/Product2'
     *  Product: '<S293>/Product3'
     *  UnaryMinus: '<S283>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_e) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S293>/Subtract' incorporates:
     *  Product: '<S293>/Product'
     *  Product: '<S293>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S293>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable,
      rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S293>/Switch1' incorporates:
     *  Constant: '<S293>/Constant'
     *  Constant: '<S293>/Constant1'
     *  Constant: '<S296>/Constant'
     *  Product: '<S293>/Divide'
     *  Product: '<S293>/Divide1'
     *  RelationalOperator: '<S296>/Compare'
     *  Switch: '<S293>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S293>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_uDLookupTable);
  } else {
    rtb_Add_a5 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S286>/Product2' incorporates:
   *  Constant: '<S286>/Constant'
   *  Switch: '<S283>/Speed_Switch'
   */
  rtb_Init = rtb_Add_a5 * 1154.7574092481445;

  /* Signum: '<S281>/Sign' */
  if (rtIsNaN(rtb_Init)) {
    rtb_Add_a5 = (rtNaN);
  } else if (rtb_Init < 0.0) {
    rtb_Add_a5 = -1.0;
  } else {
    rtb_Add_a5 = (rtb_Init > 0.0);
  }

  /* Signum: '<S281>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S284>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S285>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S236>/Product' incorporates:
   *  Abs: '<S281>/Abs'
   *  Abs: '<S284>/Abs'
   *  Constant: '<S287>/Constant'
   *  Constant: '<S297>/Constant3'
   *  Constant: '<S297>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S281>/OR'
   *  Lookup_n-D: '<S284>/1-D Lookup Table'
   *  Math: '<S297>/Math Function'
   *  RelationalOperator: '<S281>/Equal1'
   *  RelationalOperator: '<S287>/Compare'
   *  Signum: '<S281>/Sign'
   *  Signum: '<S281>/Sign1'
   *  Sum: '<S284>/Add'
   *  Sum: '<S297>/Add1'
   *  Sum: '<S297>/Add2'
   */
  rtb_Init = (((real_T)((rtb_Add_a5 == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init) * look1_binlcpw(fabs
    (rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                 3.1415926535897931) - 1.5707963267948966),
    rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S282>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Init -
    Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S289>/Sum1' incorporates:
   *  Constant: '<S282>/Constant2'
   *  Product: '<S289>/Product'
   *  Sum: '<S289>/Sum'
   *  UnitDelay: '<S289>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_MatrixConcatenate_b_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S282>/Product' incorporates:
   *  Constant: '<S282>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S288>/Diff' incorporates:
   *  UnitDelay: '<S288>/UD'
   *
   * Block description for '<S288>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S288>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S282>/Saturation' */
  if (rtb_Add_a5 > Drive_Motor_Control_D_UL) {
    rtb_Add_a5 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Drive_Motor_Control_D_LL) {
    rtb_Add_a5 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S282>/Add' incorporates:
   *  Gain: '<S282>/Gain'
   *  Gain: '<S282>/Gain1'
   *  Saturate: '<S282>/Saturation'
   */
  rtb_Init = ((Drive_Motor_Control_FF * rtb_Init) + (Drive_Motor_Control_P *
    rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_a5;

  /* Saturate: '<S282>/Saturation2' incorporates:
   *  Sum: '<S282>/Add1'
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

  /* End of Saturate: '<S282>/Saturation2' */

  /* Sum: '<S298>/Add1' incorporates:
   *  Constant: '<S298>/Constant3'
   *  Constant: '<S298>/Constant4'
   *  Math: '<S298>/Math Function'
   *  Sum: '<S298>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S300>/Sum1' incorporates:
   *  Constant: '<S285>/Constant2'
   *  Product: '<S300>/Product'
   *  Sum: '<S300>/Sum'
   *  UnitDelay: '<S300>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Init -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S285>/Product' incorporates:
   *  Constant: '<S285>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S299>/Diff' incorporates:
   *  UnitDelay: '<S299>/UD'
   *
   * Block description for '<S299>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S299>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S285>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S285>/Add' incorporates:
   *  Gain: '<S285>/Gain1'
   *  Saturate: '<S285>/Saturation'
   */
  rtb_Add_f1 = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_a5;

  /* Sum: '<S285>/Subtract' incorporates:
   *  Constant: '<S285>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_f1;

  /* Sum: '<S285>/Sum2' incorporates:
   *  Gain: '<S285>/Gain2'
   *  UnitDelay: '<S285>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S301>/Switch2' incorporates:
   *  Constant: '<S285>/Constant'
   *  RelationalOperator: '<S301>/LowerRelop1'
   *  Sum: '<S285>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_f1))) {
    /* Sum: '<S285>/Subtract1' incorporates:
     *  Constant: '<S285>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_f1;

    /* Switch: '<S301>/Switch' incorporates:
     *  Constant: '<S285>/Constant1'
     *  RelationalOperator: '<S301>/UpperRelop'
     *  Sum: '<S285>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_f1))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
    }

    /* End of Switch: '<S301>/Switch' */
  }

  /* End of Switch: '<S301>/Switch2' */

  /* Saturate: '<S285>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S285>/Saturation1' */

  /* Sum: '<S285>/Add1' */
  rtb_Add_a5 = rtb_Add_f1 + rtb_Integral_ga;

  /* Saturate: '<S285>/Saturation2' */
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

  /* End of Saturate: '<S285>/Saturation2' */

  /* Sum: '<S319>/Add1' incorporates:
   *  Constant: '<S319>/Constant3'
   *  Constant: '<S319>/Constant4'
   *  Math: '<S319>/Math Function'
   *  Sum: '<S319>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Integral_d + 3.1415926535897931, 6.2831853071795862)
    - 3.1415926535897931;

  /* Sum: '<S321>/Sum1' incorporates:
   *  Constant: '<S306>/Constant2'
   *  Product: '<S321>/Product'
   *  Sum: '<S321>/Sum'
   *  UnitDelay: '<S321>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_i)
    * Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S306>/Product' incorporates:
   *  Constant: '<S306>/Constant3'
   */
  rtb_Add_f1 = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S320>/Diff' incorporates:
   *  UnitDelay: '<S320>/UD'
   *
   * Block description for '<S320>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S320>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Add_f1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S306>/Saturation' */
  if (rtb_Add_a5 > Steering_Motor_Control_D_UL) {
    rtb_Add_a5 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_a5 < Steering_Motor_Control_D_LL) {
    rtb_Add_a5 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S306>/Add' incorporates:
   *  Gain: '<S306>/Gain1'
   *  Saturate: '<S306>/Saturation'
   */
  rtb_Add_fd = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_a5;

  /* Sum: '<S306>/Subtract' incorporates:
   *  Constant: '<S306>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_fd;

  /* Sum: '<S306>/Sum2' incorporates:
   *  Gain: '<S306>/Gain2'
   *  UnitDelay: '<S306>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S322>/Switch2' incorporates:
   *  Constant: '<S306>/Constant'
   *  RelationalOperator: '<S322>/LowerRelop1'
   *  Sum: '<S306>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_fd))) {
    /* Sum: '<S306>/Subtract1' incorporates:
     *  Constant: '<S306>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_fd;

    /* Switch: '<S322>/Switch' incorporates:
     *  Constant: '<S306>/Constant1'
     *  RelationalOperator: '<S322>/UpperRelop'
     *  Sum: '<S306>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_fd))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
    }

    /* End of Switch: '<S322>/Switch' */
  }

  /* End of Switch: '<S322>/Switch2' */

  /* Saturate: '<S306>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S306>/Saturation1' */

  /* Sum: '<S306>/Add1' */
  rtb_Add_a5 = rtb_Add_fd + rtb_Integral_bj;

  /* Saturate: '<S306>/Saturation2' */
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

  /* End of Saturate: '<S306>/Saturation2' */

  /* Gain: '<S357>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Switch2_p2;

  /* Sum: '<S169>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S123>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S171>/Sum1' incorporates:
   *  Constant: '<S169>/Constant2'
   *  Product: '<S171>/Product'
   *  Sum: '<S169>/Sum'
   *  Sum: '<S171>/Sum'
   *  UnitDelay: '<S171>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) *
                    0.1) + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S169>/Product' incorporates:
   *  Constant: '<S169>/Constant3'
   */
  rtb_Add_fd = rtb_Switch2_p2 * 0.0;

  /* Sum: '<S170>/Diff' incorporates:
   *  UnitDelay: '<S170>/UD'
   *
   * Block description for '<S170>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S170>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Add_fd - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S169>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S169>/Add' incorporates:
   *  Gain: '<S169>/Gain'
   *  Gain: '<S169>/Gain1'
   *  Saturate: '<S169>/Saturation'
   *  Sum: '<S169>/Sum'
   */
  rtb_Init = ((Rebuilt_Transfer_Motor_Gain_FF *
               Robot_Control_B.RB_Desired_Transfer_Speed) +
              (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_a5;

  /* Logic: '<S123>/Logical Operator1' incorporates:
   *  Constant: '<S168>/Constant'
   *  RelationalOperator: '<S168>/Compare'
   */
  rtb_Button_Shoot_Enable = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S123>/Switch1' incorporates:
   *  Abs: '<S123>/Abs'
   *  Constant: '<S123>/Constant1'
   *  Constant: '<S123>/Constant2'
   *  Logic: '<S123>/Logical Operator'
   *  Logic: '<S123>/Logical Operator1'
   *  RelationalOperator: '<S123>/LessThan'
   *  UnitDelay: '<S123>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Button_Shoot_Enable) {
    rtb_Button_Spinup_Enable = true;
  } else {
    rtb_Button_Spinup_Enable = (rtb_Button_Shoot_Enable &&
      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S123>/Switch1' */

  /* Switch: '<S169>/Switch' incorporates:
   *  Constant: '<S169>/Constant4'
   */
  if (rtb_Button_Spinup_Enable) {
    /* Sum: '<S169>/Sum2' incorporates:
     *  Gain: '<S169>/Gain2'
     *  Sum: '<S169>/Sum'
     *  UnitDelay: '<S169>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Transfer_Motor_Gain_I *
      rtb_Integral_d) + Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S169>/Subtract' incorporates:
     *  Constant: '<S169>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Init;

    /* Switch: '<S172>/Switch2' incorporates:
     *  Constant: '<S169>/Constant'
     *  RelationalOperator: '<S172>/LowerRelop1'
     *  Sum: '<S169>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Init))) {
      /* Sum: '<S169>/Subtract1' incorporates:
       *  Constant: '<S169>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Init;

      /* Switch: '<S172>/Switch' incorporates:
       *  Constant: '<S169>/Constant1'
       *  RelationalOperator: '<S172>/UpperRelop'
       *  Sum: '<S169>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Init))) {
        rtb_Integral_d = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S172>/Switch' */
    }

    /* End of Switch: '<S172>/Switch2' */

    /* Saturate: '<S169>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S169>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S169>/Switch' */

  /* Switch: '<S123>/Switch2' incorporates:
   *  Logic: '<S123>/Logical Operator1'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S169>/Add1' */
    rtb_Add_a5 = rtb_Init + rtb_Integral_d;

    /* Saturate: '<S169>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S123>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S123>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S123>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S169>/Saturation2' */
  } else {
    /* Switch: '<S123>/Switch2' incorporates:
     *  Constant: '<S123>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S123>/Switch2' */

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

  /* Switch: '<S115>/Init' incorporates:
   *  UnitDelay: '<S115>/FixPt Unit Delay1'
   *  UnitDelay: '<S115>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S115>/Init' */

  /* Sum: '<S113>/Sum1' */
  rtb_Init -= rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S114>/Switch2' incorporates:
   *  Constant: '<S112>/Constant1'
   *  Constant: '<S112>/Constant3'
   *  RelationalOperator: '<S114>/LowerRelop1'
   *  RelationalOperator: '<S114>/UpperRelop'
   *  Switch: '<S114>/Switch'
   */
  if (rtb_Init > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Init < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S114>/Switch' incorporates:
     *  Constant: '<S112>/Constant1'
     */
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S114>/Switch2' */

  /* Sum: '<S113>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Init + rtb_MatrixConcatenate_b_idx_0;

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

  /* Logic: '<S41>/Logical Operator1' incorporates:
   *  Constant: '<S53>/Constant'
   *  RelationalOperator: '<S53>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Init == 0.0);

  /* Sum: '<S54>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S41>/Subtract'
   */
  rtb_Error_n = rtb_Init - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S56>/Sum1' incorporates:
   *  Constant: '<S54>/Constant2'
   *  Product: '<S56>/Product'
   *  Sum: '<S54>/Sum'
   *  Sum: '<S56>/Sum'
   *  UnitDelay: '<S56>/Unit Delay1'
   */
  rtb_Sum1_fh = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S54>/Product' incorporates:
   *  Constant: '<S54>/Constant3'
   */
  rtb_Product_m5 = rtb_Sum1_fh * 0.0;

  /* Sum: '<S55>/Diff' incorporates:
   *  UnitDelay: '<S55>/UD'
   *
   * Block description for '<S55>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S55>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_m5 - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S54>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S54>/Add' incorporates:
   *  Gain: '<S54>/Gain'
   *  Gain: '<S54>/Gain1'
   *  Saturate: '<S54>/Saturation'
   *  Sum: '<S54>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Init) +
    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_a5;

  /* Switch: '<S41>/Switch1' incorporates:
   *  Abs: '<S41>/Abs'
   *  Constant: '<S41>/Constant1'
   *  Constant: '<S41>/Constant2'
   *  Logic: '<S41>/Logical Operator'
   *  Logic: '<S41>/Logical Operator1'
   *  RelationalOperator: '<S41>/LessThan'
   *  UnitDelay: '<S41>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Button_Shoot_Enable = true;
  } else {
    rtb_Button_Shoot_Enable = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_nh));
  }

  /* End of Switch: '<S41>/Switch1' */

  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S54>/Constant4'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S54>/Sum2' incorporates:
     *  Gain: '<S54>/Gain2'
     *  Sum: '<S54>/Sum'
     *  UnitDelay: '<S54>/Unit Delay'
     */
    rtb_Init = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S54>/Subtract' incorporates:
     *  Constant: '<S54>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_MatrixConcatenate_b_idx_0;

    /* Switch: '<S57>/Switch2' incorporates:
     *  Constant: '<S54>/Constant'
     *  RelationalOperator: '<S57>/LowerRelop1'
     *  Sum: '<S54>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S54>/Subtract1' incorporates:
       *  Constant: '<S54>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S54>/Constant1'
       *  RelationalOperator: '<S57>/UpperRelop'
       *  Sum: '<S54>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Error_n = rtb_Init;
      }

      /* End of Switch: '<S57>/Switch' */
    }

    /* End of Switch: '<S57>/Switch2' */

    /* Saturate: '<S54>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Error_n = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Error_n = -0.1;
    }

    /* End of Saturate: '<S54>/Saturation1' */
  } else {
    rtb_Error_n = 0.0;
  }

  /* End of Switch: '<S54>/Switch' */

  /* Switch: '<S41>/Switch2' incorporates:
   *  Logic: '<S41>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S54>/Add1' */
    rtb_Add_a5 = rtb_MatrixConcatenate_b_idx_0 + rtb_Error_n;

    /* Saturate: '<S54>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S41>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S41>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S41>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S54>/Saturation2' */
  } else {
    /* Switch: '<S41>/Switch2' incorporates:
     *  Constant: '<S41>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S41>/Switch2' */

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

  /* Sum: '<S36>/Add1' incorporates:
   *  Constant: '<S36>/Constant3'
   *  Constant: '<S36>/Constant4'
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Math: '<S36>/Math Function'
   *  Sum: '<S36>/Add2'
   */
  Robot_Control_B.RB_Intake_Arm_Angle_Mod = rt_modd_snf
    (Robot_Control_U.Measured_Intake_Arm_Angle + 180.0, 360.0) - 180.0;

  /* Chart: '<S6>/Chart' incorporates:
   *  RelationalOperator: '<S38>/FixPt Relational Operator'
   *  UnitDelay: '<S38>/Delay Input1'
   *
   * Block description for '<S38>/Delay Input1':
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

  /* Switch: '<S52>/Init' incorporates:
   *  UnitDelay: '<S52>/FixPt Unit Delay1'
   *  UnitDelay: '<S52>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S52>/Init' */

  /* Sum: '<S50>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_Init;

  /* Switch: '<S51>/Switch2' incorporates:
   *  Constant: '<S40>/Constant1'
   *  Constant: '<S40>/Constant3'
   *  RelationalOperator: '<S51>/LowerRelop1'
   *  RelationalOperator: '<S51>/UpperRelop'
   *  Switch: '<S51>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Intake_RL_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S40>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S51>/Switch2' */

  /* Sum: '<S50>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Init;

  /* Sum: '<S46>/Sum' */
  rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S48>/Sum1' incorporates:
   *  Constant: '<S46>/Constant2'
   *  Product: '<S48>/Product'
   *  Sum: '<S48>/Sum'
   *  UnitDelay: '<S48>/Unit Delay1'
   */
  rtb_Sum1_l = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S46>/Product' incorporates:
   *  Constant: '<S46>/Constant3'
   */
  rtb_Product_aa = rtb_Sum1_l * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S47>/Diff' incorporates:
   *  UnitDelay: '<S47>/UD'
   *
   * Block description for '<S47>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S47>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_aa - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S46>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S46>/Add' incorporates:
   *  Gain: '<S46>/Gain'
   *  Gain: '<S46>/Gain1'
   *  Saturate: '<S46>/Saturation'
   */
  rtb_Add_i = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
               (Rebuilt_Intake_Arm_Gain_P * rtb_Init)) + rtb_Add_a5;

  /* Sum: '<S46>/Subtract' incorporates:
   *  Constant: '<S46>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_i;

  /* Sum: '<S46>/Sum2' incorporates:
   *  Gain: '<S46>/Gain2'
   *  UnitDelay: '<S46>/Unit Delay'
   */
  rtb_Init = (0.0 * rtb_Init) + Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S49>/Switch2' incorporates:
   *  Constant: '<S46>/Constant'
   *  RelationalOperator: '<S49>/LowerRelop1'
   *  Sum: '<S46>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_i))) {
    /* Sum: '<S46>/Subtract1' incorporates:
     *  Constant: '<S46>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_i;

    /* Switch: '<S49>/Switch' incorporates:
     *  Constant: '<S46>/Constant1'
     *  RelationalOperator: '<S49>/UpperRelop'
     *  Sum: '<S46>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_i))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
    }

    /* End of Switch: '<S49>/Switch' */
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Saturate: '<S46>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > 0.1) {
    rtb_MatrixConcatenate_b_idx_0 = 0.1;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -0.1) {
    rtb_MatrixConcatenate_b_idx_0 = -0.1;
  }

  /* End of Saturate: '<S46>/Saturation1' */

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  Logic: '<S39>/Logical Operator1'
   *  Logic: '<S39>/Logical Operator2'
   *  Logic: '<S39>/Logical Operator3'
   *  RelationalOperator: '<S42>/Compare'
   *  RelationalOperator: '<S43>/Compare'
   *  RelationalOperator: '<S44>/Compare'
   *  RelationalOperator: '<S45>/Compare'
   */
  if (((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_In) && (Robot_Control_B.RB_Intake_Arm_Angle_Mod
        <= Rebuilt_Intake_Meas_In_Disable)) ||
      ((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_Out) &&
       (Robot_Control_B.RB_Intake_Arm_Angle_Mod >=
        Rebuilt_Intake_Meas_Out_Disable))) {
    /* Switch: '<S39>/Switch2' incorporates:
     *  Constant: '<S39>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  } else {
    /* Sum: '<S46>/Add1' */
    rtb_Add_a5 = rtb_Add_i + rtb_MatrixConcatenate_b_idx_0;

    /* Saturate: '<S46>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S39>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S39>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S39>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S46>/Saturation2' */
  }

  /* End of Switch: '<S39>/Switch2' */

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

  /* Logic: '<S121>/Logical Operator1' incorporates:
   *  Constant: '<S163>/Constant'
   *  RelationalOperator: '<S163>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S164>/Sum' incorporates:
   *  Sum: '<S121>/Subtract'
   */
  rtb_Init = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S166>/Sum1' incorporates:
   *  Constant: '<S164>/Constant2'
   *  Product: '<S166>/Product'
   *  Sum: '<S164>/Sum'
   *  Sum: '<S166>/Sum'
   *  UnitDelay: '<S166>/Unit Delay1'
   */
  rtb_Add_i = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S164>/Product' incorporates:
   *  Constant: '<S164>/Constant3'
   */
  rtb_Product_bg = rtb_Add_i * 0.0;

  /* Sum: '<S165>/Diff' incorporates:
   *  UnitDelay: '<S165>/UD'
   *
   * Block description for '<S165>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S165>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a5 = rtb_Product_bg - Robot_Control_DW.UD_DSTATE_kz;

  /* Saturate: '<S164>/Saturation' */
  if (rtb_Add_a5 > 0.1) {
    rtb_Add_a5 = 0.1;
  } else if (rtb_Add_a5 < -0.1) {
    rtb_Add_a5 = -0.1;
  }

  /* Sum: '<S164>/Add' incorporates:
   *  Gain: '<S164>/Gain'
   *  Gain: '<S164>/Gain1'
   *  Saturate: '<S164>/Saturation'
   *  Sum: '<S164>/Sum'
   */
  rtb_Add_a5 += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Init);

  /* Switch: '<S121>/Switch4' incorporates:
   *  Constant: '<S121>/Constant6'
   *  Constant: '<S121>/Constant7'
   *  Logic: '<S121>/Logical Operator1'
   *  Logic: '<S121>/Logical Operator2'
   *  RelationalOperator: '<S121>/LessThan2'
   *  UnitDelay: '<S121>/Unit Delay1'
   */
  if ((rtb_Init < 0.0) && rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay1_DSTATE_ea));
  }

  /* End of Switch: '<S121>/Switch4' */

  /* Switch: '<S121>/Switch1' incorporates:
   *  Constant: '<S121>/Constant1'
   *  Constant: '<S121>/Constant2'
   *  Logic: '<S121>/Logical Operator'
   *  Logic: '<S121>/Logical Operator1'
   *  RelationalOperator: '<S121>/LessThan'
   *  UnitDelay: '<S121>/Unit Delay'
   */
  if ((rtb_Init < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S121>/Switch1' */

  /* Switch: '<S164>/Switch' incorporates:
   *  Constant: '<S164>/Constant4'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S164>/Sum2' incorporates:
     *  Gain: '<S164>/Gain2'
     *  Product: '<S164>/Product1'
     *  Sum: '<S164>/Sum'
     *  Switch: '<S164>/Switch1'
     *  UnitDelay: '<S164>/Unit Delay'
     */
    rtb_Init = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Init) * ((real_T)
      (!rtb_Intake_Arm_Move_In))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S164>/Subtract' incorporates:
     *  Constant: '<S164>/Constant'
     */
    rtb_Error_c5 = 1.0 - rtb_Add_a5;

    /* Switch: '<S167>/Switch2' incorporates:
     *  Constant: '<S164>/Constant'
     *  RelationalOperator: '<S167>/LowerRelop1'
     *  Sum: '<S164>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Add_a5))) {
      /* Sum: '<S164>/Subtract1' incorporates:
       *  Constant: '<S164>/Constant1'
       */
      rtb_Error_c5 = -1.0 - rtb_Add_a5;

      /* Switch: '<S167>/Switch' incorporates:
       *  Constant: '<S164>/Constant1'
       *  RelationalOperator: '<S167>/UpperRelop'
       *  Sum: '<S164>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Add_a5))) {
        rtb_Error_c5 = rtb_Init;
      }

      /* End of Switch: '<S167>/Switch' */
    }

    /* End of Switch: '<S167>/Switch2' */

    /* Saturate: '<S164>/Saturation1' */
    if (rtb_Error_c5 > 0.1) {
      rtb_Init = 0.1;
    } else if (rtb_Error_c5 < -0.1) {
      rtb_Init = -0.1;
    } else {
      rtb_Init = rtb_Error_c5;
    }

    /* End of Saturate: '<S164>/Saturation1' */
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S164>/Switch' */

  /* Switch: '<S121>/Switch2' incorporates:
   *  Logic: '<S121>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S164>/Add1' */
    rtb_Add_a5 += rtb_Init;

    /* Saturate: '<S164>/Saturation2' */
    if (rtb_Add_a5 > 1.0) {
      /* Switch: '<S121>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_a5 < -1.0) {
      /* Switch: '<S121>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S121>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_a5;
    }

    /* End of Saturate: '<S164>/Saturation2' */
  } else {
    /* Switch: '<S121>/Switch2' incorporates:
     *  Constant: '<S121>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S121>/Switch2' */

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

  /* Update for Delay: '<S58>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S78>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S58>/A'
   *  Delay: '<S58>/MemoryX'
   */
  rtb_Add_a5 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Error_c5 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S58>/MemoryX' incorporates:
   *  Constant: '<S58>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S78>/A[k]*xhat[k|k-1]'
   *  Product: '<S78>/B[k]*u[k]'
   *  Sum: '<S78>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Add_a5) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Error_c5) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S334>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S334>/FixPt Constant'
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

  /* Update for UnitDelay: '<S117>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S356>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S355>/UD'
   *
   * Block description for '<S355>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S353>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Subtract_c3;

  /* Update for UnitDelay: '<S336>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch1_b0;

  /* Update for UnitDelay: '<S351>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S351>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S351>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Switch1_b0;

  /* Update for UnitDelay: '<S335>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S344>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S344>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S344>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S310>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_DeadZone;

  /* Update for UnitDelay: '<S309>/UD'
   *
   * Block description for '<S309>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S303>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S247>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S246>/UD'
   *
   * Block description for '<S246>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Switch2;

  /* Update for UnitDelay: '<S240>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S258>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S257>/UD'
   *
   * Block description for '<S257>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S243>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S268>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_e3;

  /* Update for UnitDelay: '<S267>/UD'
   *
   * Block description for '<S267>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S261>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S279>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_b;

  /* Update for UnitDelay: '<S278>/UD'
   *
   * Block description for '<S278>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_be;

  /* Update for UnitDelay: '<S264>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S289>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S288>/UD'
   *
   * Block description for '<S288>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S282>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S300>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S299>/UD'
   *
   * Block description for '<S299>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S285>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S321>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S320>/UD'
   *
   * Block description for '<S320>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_f1;

  /* Update for UnitDelay: '<S306>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S171>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S170>/UD'
   *
   * Block description for '<S170>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Add_fd;

  /* Update for UnitDelay: '<S169>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S123>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Button_Spinup_Enable;

  /* Update for UnitDelay: '<S115>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S115>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S56>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_fh;

  /* Update for UnitDelay: '<S55>/UD'
   *
   * Block description for '<S55>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_m5;

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S41>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_nh = rtb_Button_Shoot_Enable;

  /* Update for UnitDelay: '<S38>/Delay Input1'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S52>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S52>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S48>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_l;

  /* Update for UnitDelay: '<S47>/UD'
   *
   * Block description for '<S47>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_aa;

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S166>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Add_i;

  /* Update for UnitDelay: '<S165>/UD'
   *
   * Block description for '<S165>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_bg;

  /* Update for UnitDelay: '<S121>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S164>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Init;

  /* Update for UnitDelay: '<S121>/Unit Delay' */
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

  /* Start for If: '<S118>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S58>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S334>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S351>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S344>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S115>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S52>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S412>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S179>/If' */
  Robot_Control_DW.If_ActiveSubsystem_hk = -1;

  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S179>/Robot_Index_Is_Valid' */
  /* Start for If: '<S182>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S182>/Circle_Check_Valid' */
  /* Start for If: '<S184>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S182>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S179>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S118>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S150>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ll = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S118>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S118>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S118>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S118>/If Action Subsystem2' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem2);

  /* End of SystemInitialize for SubSystem: '<S118>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S118>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S118>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S118>/If Action Subsystem4' */
  Robot_C_IfActionSubsystem2_Init(&Robot_Control_DW.IfActionSubsystem4);

  /* End of SystemInitialize for SubSystem: '<S118>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S118>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S155>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S118>/If Action Subsystem5' */
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
