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
 * C/C++ source code generated on : Tue Mar 17 22:52:33 2026
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

/* Named constants for Chart: '<S358>/Add dither' */
#define Robot_Control_IN_Dither        ((uint8_T)1U)
#define Robot_Control_IN_High          ((uint8_T)1U)
#define Robot_Control_IN_No_Dither     ((uint8_T)2U)
#define Robot_Control_IN_Off           ((uint8_T)2U)

/* Named constants for Chart: '<S20>/Chart' */
#define Robot_Control_IN_End_Action    ((uint8_T)1U)
#define Robot_Control_IN_Follow_Path   ((uint8_T)2U)
#define Robot_Control_IN_Start_Action  ((uint8_T)3U)

/* Exported block parameters */
real_T Auto_Deploy_Intake_Time = 1.0;  /* Variable: Auto_Deploy_Intake_Time
                                        * Referenced by: '<S26>/Constant'
                                        */
real_T Auto_Intake_Arm_Cycle_Delay_Time = 2.0;
                                   /* Variable: Auto_Intake_Arm_Cycle_Delay_Time
                                    * Referenced by: '<S30>/Constant'
                                    */
real_T Auto_Path_Chooser = 1.0;        /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S21>/Constant17'
                                        */
real_T Auto_Shoot_Time = 4.5;          /* Variable: Auto_Shoot_Time
                                        * Referenced by: '<S24>/Constant'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S431>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S427>/Constant'
                                        *   '<S427>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S431>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S427>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S261>/Constant3'
                                        *   '<S282>/Constant3'
                                        *   '<S303>/Constant3'
                                        *   '<S324>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S261>/Constant2'
                                   *   '<S282>/Constant2'
                                   *   '<S303>/Constant2'
                                   *   '<S324>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S261>/Saturation'
                                        *   '<S282>/Saturation'
                                        *   '<S303>/Saturation'
                                        *   '<S324>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S261>/Saturation'
                                        *   '<S282>/Saturation'
                                        *   '<S303>/Saturation'
                                        *   '<S324>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S261>/Gain'
                                            *   '<S282>/Gain'
                                            *   '<S303>/Gain'
                                            *   '<S324>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S261>/Gain2'
                                        *   '<S282>/Gain2'
                                        *   '<S303>/Gain2'
                                        *   '<S324>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S261>/Saturation1'
                                         *   '<S282>/Saturation1'
                                         *   '<S303>/Saturation1'
                                         *   '<S324>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S261>/Saturation1'
                                        *   '<S282>/Saturation1'
                                        *   '<S303>/Saturation1'
                                        *   '<S324>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S261>/Gain1'
                                        *   '<S282>/Gain1'
                                        *   '<S303>/Gain1'
                                        *   '<S324>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S266>/Constant'
                            *   '<S287>/Constant'
                            *   '<S308>/Constant'
                            *   '<S329>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S180>/BlueAllianceZoneX'
                                         *   '<S182>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S149>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S149>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S149>/Constant1'
                                        *   '<S149>/Switch3'
                                        */
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S149>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S149>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S181>/RedAllianceZoneX'
                                         *   '<S183>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S149>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S149>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S417>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S417>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rate_Limit_X = 1000.0;          /* Variable: Rate_Limit_X
                                        * Referenced by: '<S41>/Constant3'
                                        */
real_T Rate_Limit_Y = 1000.0;          /* Variable: Rate_Limit_Y
                                        * Referenced by: '<S42>/Constant3'
                                        */
real_T Rate_Limit_Z = 1000.0;          /* Variable: Rate_Limit_Z
                                        * Referenced by: '<S43>/Constant3'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = 0.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S144>/Constant'
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
                                          *   '<S142>/Constant3'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S129>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S129>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S63>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.008;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                          * Referenced by: '<S63>/Gain1'
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
                                            *   '<S59>/Constant'
                                            */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S60>/Constant'
                                            */
real_T Rebuilt_Intake_Meas_In_Disable = -20.0;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S61>/Constant'
                                      */
real_T Rebuilt_Intake_Meas_Out_Disable = 80.0;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S62>/Constant'
                                     */
real_T Rebuilt_Intake_RL_Dec = -3.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S57>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 3.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S57>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 30.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S167>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S171>/Constant3'
                                   *   '<S172>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S163>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S164>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S165>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S166>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S168>/Unit Delay'
                                      *   '<S169>/Unit Delay'
                                      *   '<S170>/Unit Delay'
                                      *   '<S171>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 3.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S168>/Constant2'
                                      *   '<S169>/Constant2'
                                      *   '<S170>/Constant2'
                                      *   '<S171>/Constant2'
                                      *   '<S173>/Constant'
                                      *   '<S174>/Constant'
                                      *   '<S175>/Constant'
                                      *   '<S176>/Constant'
                                      */
real_T Rebuilt_Match_Time_TeleOp = 140.0;/* Variable: Rebuilt_Match_Time_TeleOp
                                          * Referenced by: '<S135>/Constant'
                                          */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S161>/Constant'
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
                                * Referenced by: '<S58>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00016534;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                                  * Referenced by: '<S71>/Gain'
                                                  */
real_T Rebuilt_Roller_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                             * Referenced by: '<S71>/Gain2'
                                             */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0001;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                             * Referenced by: '<S71>/Gain1'
                                             */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S150>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S150>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S150>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S150>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S150>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S150>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S150>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S150>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S146>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S146>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S146>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 2.7; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S146>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S146>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S146>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S146>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S146>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S147>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S147>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S147>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S147>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S147>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S147>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S147>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S147>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S137>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S137>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S137>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2725.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S160>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S160>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3265.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S160>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3425.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S160>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3625.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S160>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3775.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S160>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S160>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S160>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S159>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S159>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3450.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S159>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3600.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S159>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3800.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S159>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3950.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S159>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S159>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S159>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S153>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S153>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S153>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S153>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S153>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S153>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S153>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S153>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S157>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S138>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S185>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S185>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.001;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                             * Referenced by: '<S185>/Gain1'
                                             */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S148>/Constant2'
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
                              * Referenced by: '<S140>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S190>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S190>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S190>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S416>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S414>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S416>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S417>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S417>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S250>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S250>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S197>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S210>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S250>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S357>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S357>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S357>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S357>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S357>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S357>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S375>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S375>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S375>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S375>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S374>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S375>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S375>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S375>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S375>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S375>/Constant1'
                                   *   '<S375>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S375>/Constant'
                                   *   '<S375>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S358>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S358>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S358>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S358>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S264>/Constant3'
                                        *   '<S285>/Constant3'
                                        *   '<S306>/Constant3'
                                        *   '<S327>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S264>/Constant2'
                                *   '<S285>/Constant2'
                                *   '<S306>/Constant2'
                                *   '<S327>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S264>/Saturation'
                                           *   '<S285>/Saturation'
                                           *   '<S306>/Saturation'
                                           *   '<S327>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S264>/Saturation'
                                          *   '<S285>/Saturation'
                                          *   '<S306>/Saturation'
                                          *   '<S327>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S264>/Gain2'
                                         *   '<S285>/Gain2'
                                         *   '<S306>/Gain2'
                                         *   '<S327>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S264>/Saturation1'
                                             *   '<S285>/Saturation1'
                                             *   '<S306>/Saturation1'
                                             *   '<S327>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S264>/Saturation1'
                                            *   '<S285>/Saturation1'
                                            *   '<S306>/Saturation1'
                                            *   '<S327>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S264>/Gain1'
                                        *   '<S285>/Gain1'
                                        *   '<S306>/Gain1'
                                        *   '<S327>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S356>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S356>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S356>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S356>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S356>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S356>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S416>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S416>/Constant1'
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
                                      * Referenced by: '<S415>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S415>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S415>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S344>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S344>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S344>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S344>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S344>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S344>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S417>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S416>/Dead Zone'
                                        *   '<S417>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S416>/Dead Zone'
                                        *   '<S417>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S414>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S414>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S414>/Constant4'
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
                                        * Referenced by: '<S414>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S414>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S414>/Constant5'
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
                                        *   '<S414>/Constant11'
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
 *    '<S135>/If Action Subsystem1'
 *    '<S135>/If Action Subsystem3'
 */
void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S168>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S135>/If Action Subsystem1'
 *    '<S135>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(real_T rtu_IsBlueInactiveFirst, real_T
  rtu_IsBlueAlliance, boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive,
  real_T *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  boolean_T rtb_Compare_nn;

  /* RelationalOperator: '<S173>/Compare' incorporates:
   *  Constant: '<S168>/Constant1'
   *  Constant: '<S173>/Constant'
   *  Sum: '<S168>/Sum'
   *  UnitDelay: '<S168>/Unit Delay'
   */
  rtb_Compare_nn = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S168>/Logical Operator' incorporates:
   *  Logic: '<S168>/NOT'
   */
  *rty_IsBlueActive = ((!(rtu_IsBlueInactiveFirst != 0.0)) || rtb_Compare_nn);

  /* Logic: '<S168>/Logical Operator1' */
  *rty_IsRedActive = ((rtu_IsBlueInactiveFirst != 0.0) || rtb_Compare_nn);

  /* Switch: '<S168>/Switch' incorporates:
   *  Constant: '<S168>/Constant1'
   *  Constant: '<S168>/Constant2'
   *  Logic: '<S168>/Logical Operator2'
   *  Sum: '<S168>/Subtract'
   *  Sum: '<S168>/Sum'
   *  UnitDelay: '<S168>/Unit Delay'
   */
  if ((boolean_T)((rtu_IsBlueInactiveFirst != 0.0) ^ (rtu_IsBlueAlliance != 0.0)))
  {
    *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;
  } else {
    *rty_Time_Remaining = (localDW->UnitDelay_DSTATE - 0.02) -
      Rebuilt_Match_Time_Shoot_Early;
  }

  /* End of Switch: '<S168>/Switch' */

  /* Update for UnitDelay: '<S168>/Unit Delay' incorporates:
   *  Constant: '<S168>/Constant1'
   *  Sum: '<S168>/Sum'
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
  real_T rtb_Minus_k_idx_0;
  real_T rtb_Minus_k_idx_1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_hm;
  real_T rtb_Product_i;
  real_T rtb_Product_lf;
  real_T rtb_Product_lo;
  real_T rtb_Product_ov;
  real_T rtb_Saturation_h;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_la;
  real_T rtb_Sum1;
  real_T rtb_Sum1_dj;
  real_T rtb_Sum1_fh;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1_h;
  real_T rtb_Switch1_hb;
  real_T rtb_Switch1_m;
  real_T rtb_Switch1_n;
  real_T rtb_Switch2_bq;
  real_T rtb_Switch2_c3;
  real_T rtb_Switch2_fl;
  real_T rtb_Switch2_p2;
  real_T rtb_Switch_hs;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s222_iter;
  uint16_T s247_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T Iteration_Number;
  uint8_T rtb_Desired_Pipeline;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T rtb_Button_Shoot_Enable;
  boolean_T rtb_Button_Spinup_Enable;
  boolean_T rtb_Compare_lq;
  boolean_T rtb_Compare_ps;
  boolean_T rtb_Disable_Wheels;
  boolean_T rtb_Enable_Wheels;
  boolean_T rtb_Intake_Arm_Cycle;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation_g;
  boolean_T rtb_LogicalOperator1_n;
  boolean_T rtb_MultiportSwitch4;
  boolean_T rtb_Reset_Wheel_Offsets;
  boolean_T rtb_Shooter_Active_prev;

  /* RelationalOperator: '<S38>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *  UnitDelay: '<S38>/Delay Input1'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Joystick_Left_B11 >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S39>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *  UnitDelay: '<S39>/Delay Input1'
   *
   * Block description for '<S39>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets =
    (Robot_Control_U.Joystick_Left_B12 > Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S40>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *  UnitDelay: '<S40>/Delay Input1'
   *
   * Block description for '<S40>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Joystick_Left_B13 >
    Robot_Control_DW.DelayInput1_DSTATE_n);

  /* SignalConversion: '<S5>/Signal Copy1' incorporates:
   *  Inport: '<Root>/Joystick_Left_X'
   */
  Robot_Control_B.Drive_Joystick_X_preRL = Robot_Control_U.Joystick_Left_X;

  /* Switch: '<S46>/Init' incorporates:
   *  UnitDelay: '<S46>/FixPt Unit Delay1'
   *  UnitDelay: '<S46>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_o = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S46>/Init' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant2'
   *  Constant: '<S41>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Sin4 = Rate_Limit_X;
  } else {
    rtb_Sin4 = 1000.0;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Sum: '<S44>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Init_o;

  /* Switch: '<S45>/Switch2' incorporates:
   *  RelationalOperator: '<S45>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Sin4)) {
    /* Switch: '<S41>/Switch1' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/Constant3'
     *  UnaryMinus: '<S41>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_hb = -Rate_Limit_X;
    } else {
      rtb_Switch1_hb = -1000.0;
    }

    /* End of Switch: '<S41>/Switch1' */

    /* Switch: '<S45>/Switch' incorporates:
     *  RelationalOperator: '<S45>/UpperRelop'
     */
    if (rtb_Sum1 < rtb_Switch1_hb) {
      rtb_Sin4 = rtb_Switch1_hb;
    } else {
      rtb_Sin4 = rtb_Sum1;
    }

    /* End of Switch: '<S45>/Switch' */
  }

  /* End of Switch: '<S45>/Switch2' */

  /* Sum: '<S44>/Sum' */
  rtb_Sum1 = rtb_Sin4 + rtb_Init_o;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S49>/Init' incorporates:
   *  UnitDelay: '<S49>/FixPt Unit Delay1'
   *  UnitDelay: '<S49>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_j != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_a;
  }

  /* End of Switch: '<S49>/Init' */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Constant: '<S42>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Y;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Sum: '<S47>/Sum1' */
  rtb_Switch1_hb = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Sin4;

  /* Switch: '<S48>/Switch2' incorporates:
   *  RelationalOperator: '<S48>/LowerRelop1'
   */
  if (!(rtb_Switch1_hb > rtb_Init_o)) {
    /* Switch: '<S42>/Switch1' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant3'
     *  UnaryMinus: '<S42>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_h = -Rate_Limit_Y;
    } else {
      rtb_Switch1_h = -1000.0;
    }

    /* End of Switch: '<S42>/Switch1' */

    /* Switch: '<S48>/Switch' incorporates:
     *  RelationalOperator: '<S48>/UpperRelop'
     */
    if (rtb_Switch1_hb < rtb_Switch1_h) {
      rtb_Init_o = rtb_Switch1_h;
    } else {
      rtb_Init_o = rtb_Switch1_hb;
    }

    /* End of Switch: '<S48>/Switch' */
  }

  /* End of Switch: '<S48>/Switch2' */

  /* Sum: '<S47>/Sum' */
  rtb_Switch1_hb = rtb_Init_o + rtb_Sin4;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S52>/Init' incorporates:
   *  UnitDelay: '<S52>/FixPt Unit Delay1'
   *  UnitDelay: '<S52>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S52>/Init' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Z;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Sum: '<S50>/Sum1' */
  rtb_Switch1_h = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Sin4;

  /* Switch: '<S51>/Switch2' incorporates:
   *  RelationalOperator: '<S51>/LowerRelop1'
   */
  if (!(rtb_Switch1_h > rtb_Init_o)) {
    /* Switch: '<S43>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant3'
     *  UnaryMinus: '<S43>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_m = -Rate_Limit_Z;
    } else {
      rtb_Switch1_m = -1000.0;
    }

    /* End of Switch: '<S43>/Switch1' */

    /* Switch: '<S51>/Switch' incorporates:
     *  RelationalOperator: '<S51>/UpperRelop'
     */
    if (rtb_Switch1_h < rtb_Switch1_m) {
      rtb_Init_o = rtb_Switch1_m;
    } else {
      rtb_Init_o = rtb_Switch1_h;
    }

    /* End of Switch: '<S51>/Switch' */
  }

  /* End of Switch: '<S51>/Switch2' */

  /* Sum: '<S50>/Sum' */
  rtb_Switch1_h = rtb_Init_o + rtb_Sin4;

  /* RelationalOperator: '<S35>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
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

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Toward_Driver = (Robot_Control_U.Joystick_Right_POV ==
    180.0);

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S34>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Right_Driver = (Robot_Control_U.Joystick_Right_POV ==
    90.0);

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S36>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Left_Driver = (Robot_Control_U.Joystick_Right_POV ==
    270.0);

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Constant: '<S32>/Constant'
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

  /* If: '<S443>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S443>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S446>/Action Port'
     */
    /* Product: '<S446>/Product' incorporates:
     *  Constant: '<S446>/Constant1'
     *  Constant: '<S446>/Constant2'
     *  Math: '<S446>/Math Function'
     */
    rtb_Sin4 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495) *
      111.0;

    /* End of Outputs for SubSystem: '<S443>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S443>/Subsystem' incorporates:
     *  ActionPort: '<S447>/Action Port'
     */
    /* SignalConversion generated from: '<S447>/Out1' incorporates:
     *  Constant: '<S447>/Constant'
     */
    rtb_Sin4 = 0.0;

    /* End of Outputs for SubSystem: '<S443>/Subsystem' */
  }

  /* End of If: '<S443>/If' */

  /* Gain: '<S444>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Init_o = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S445>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Sin4 * cos(rtb_Init_o)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S445>/theta->y'
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
    rtb_Switch1_m = 0.0;

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
       *  UnitDelay: '<S19>/Unit Delay2'
       *  UnitDelay: '<S20>/Unit Delay'
       *  UnitDelay: '<S20>/Unit Delay1'
       *  UnitDelay: '<S22>/Unit Delay'
       *  UnitDelay: '<S27>/Delay Input1'
       *  UnitDelay: '<S28>/Delay Input1'
       *  UnitDelay: '<S31>/Delay Input1'
       *
       * Block description for '<S27>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S28>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S31>/Delay Input1':
       *
       *  Store in Global RAM
       */
      memset(&Robot_Control_DW.UnitDelay1_DSTATE_iz[0], 0, 60U * (sizeof(real_T)));
      Robot_Control_DW.UnitDelay1_DSTATE_k = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_kb = false;
      Robot_Control_DW.UnitDelay_DSTATE_b = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_h = false;
      Robot_Control_DW.UnitDelay2_DSTATE_d = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_e3 = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_gf = false;
      Robot_Control_DW.UnitDelay_DSTATE_hk = 0.0;

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
      Robot_Control_DW.counter = 0.0;

      /* End of SystemReset for SubSystem: '<S1>/Autonomous' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MultiPortSwitch: '<S21>/Multiport Switch1' incorporates:
     *  Constant: '<S21>/Constant1'
     *  Constant: '<S21>/Constant10'
     *  Constant: '<S21>/Constant11'
     *  Constant: '<S21>/Constant12'
     *  Constant: '<S21>/Constant17'
     *  Constant: '<S21>/Constant2'
     *  Constant: '<S21>/Constant3'
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

     case 4:
      rtb_MultiportSwitch1[0] = 7;
      rtb_MultiportSwitch1[1] = 8;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 5:
      rtb_MultiportSwitch1[0] = 9;
      rtb_MultiportSwitch1[1] = 10;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 6:
      rtb_MultiportSwitch1[0] = 11;
      rtb_MultiportSwitch1[1] = 12;
      rtb_MultiportSwitch1[2] = 0;
      break;

     default:
      rtb_MultiportSwitch1[0] = 11;
      rtb_MultiportSwitch1[1] = 13;
      rtb_MultiportSwitch1[2] = 10;
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
    rtb_Compare_ps = (Robot_Control_DW.UnitDelay1_DSTATE_k == 2.0);

    /* Switch: '<S19>/Switch1' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S19>/Constant2'
     *  RelationalOperator: '<S27>/FixPt Relational Operator'
     *  Sum: '<S19>/Sum'
     *  UnitDelay: '<S19>/Unit Delay'
     *  UnitDelay: '<S27>/Delay Input1'
     *
     * Block description for '<S27>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_ps) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_kb)) {
      rtb_Init_o = 0.0;
    } else {
      rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
    }

    /* End of Switch: '<S19>/Switch1' */

    /* RelationalOperator: '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     *  UnitDelay: '<S19>/Unit Delay1'
     */
    rtb_Compare_lq = (Robot_Control_DW.UnitDelay1_DSTATE_k == 4.0);

    /* Switch: '<S19>/Switch2' incorporates:
     *  Constant: '<S19>/Constant3'
     *  Constant: '<S19>/Constant4'
     *  RelationalOperator: '<S28>/FixPt Relational Operator'
     *  Sum: '<S19>/Sum1'
     *  UnitDelay: '<S19>/Unit Delay2'
     *  UnitDelay: '<S28>/Delay Input1'
     *
     * Block description for '<S28>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_lq) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_h)) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = Robot_Control_DW.UnitDelay2_DSTATE_d + 0.02;
    }

    /* End of Switch: '<S19>/Switch2' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     *  Switch: '<S19>/Switch3'
     */
    if (rtb_Compare_ps) {
      rtb_Shooter_Active_prev = (rtb_Init_o >= Auto_Shoot_Time);
    } else if (rtb_Compare_lq) {
      /* Switch: '<S19>/Switch3' incorporates:
       *  Constant: '<S26>/Constant'
       *  RelationalOperator: '<S26>/Compare'
       */
      rtb_Shooter_Active_prev = (rtb_Sin4 >= Auto_Deploy_Intake_Time);
    } else {
      /* Switch: '<S19>/Switch3' incorporates:
       *  Constant: '<S19>/Constant'
       */
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
      Robot_Control_B.Auto_Spline_Enable = false;
      Robot_Control_B.Auto_Desired_Static_Action =
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) + 39];
      Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
      Robot_Control_DW.counter = 0.0;
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
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
          Robot_Control_DW.counter = 0.0;
        }
        break;

       case Robot_Control_IN_Follow_Path:
        Robot_Control_B.Auto_Spline_Enable = true;
        if (Robot_Control_DW.UnitDelay_DSTATE_ll) {
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
        Robot_Control_B.Auto_Spline_Enable = false;
        if ((Robot_Control_DW.counter > 1.0) &&
            ((Robot_Control_B.Auto_Desired_Static_Action == 0.0) ||
             rtb_Shooter_Active_prev)) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Spline_Enable = true;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            49];
        } else {
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            39];
          Robot_Control_DW.counter++;
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
    rtb_Switch1_m = rtb_Spline_Ref_Poses_h[30];

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
      rtb_Switch_hs = Robot_Control_B.Auto_Desired_Static_Action;
    } else {
      rtb_Switch_hs = Robot_Control_B.Auto_Desired_Dynamic_Action;
    }

    /* End of Switch: '<S22>/Switch' */

    /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
     *  Constant: '<S22>/Constant20'
     *  Constant: '<S22>/Constant21'
     *  Constant: '<S22>/Constant22'
     *  Constant: '<S22>/Constant23'
     *  Constant: '<S22>/Constant24'
     */
    switch ((int32_T)rtb_Switch_hs) {
     case 0:
      rtb_MultiportSwitch4 = false;
      break;

     case 1:
      rtb_MultiportSwitch4 = false;
      break;

     case 2:
      rtb_MultiportSwitch4 = true;
      break;

     case 3:
      rtb_MultiportSwitch4 = false;
      break;

     default:
      rtb_MultiportSwitch4 = false;
      break;
    }

    /* End of MultiPortSwitch: '<S22>/Multiport Switch4' */

    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/Constant30'
     *  Constant: '<S22>/Constant31'
     *  RelationalOperator: '<S31>/FixPt Relational Operator'
     *  Sum: '<S22>/Sum'
     *  UnitDelay: '<S22>/Unit Delay'
     *  UnitDelay: '<S31>/Delay Input1'
     *
     * Block description for '<S31>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_MultiportSwitch4) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_gf)) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hk + 0.02;
    }

    /* End of Switch: '<S22>/Switch1' */

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S30>/Constant'
     *  RelationalOperator: '<S30>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Switch1_n >= Auto_Intake_Arm_Cycle_Delay_Time) &&
      rtb_MultiportSwitch4);

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     */
    switch ((int32_T)rtb_Switch_hs) {
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
      rtb_Intake_Arm_Move_In = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant19'
       */
      rtb_Intake_Arm_Move_Out = false;

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
      rtb_Intake_Arm_Move_In = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant17'
       */
      rtb_Intake_Arm_Move_Out = true;

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

    /* Update for UnitDelay: '<S27>/Delay Input1'
     *
     * Block description for '<S27>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_kb = rtb_Compare_ps;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Init_o;

    /* Update for UnitDelay: '<S28>/Delay Input1'
     *
     * Block description for '<S28>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_h = rtb_Compare_lq;

    /* Update for UnitDelay: '<S19>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_d = rtb_Sin4;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S31>/Delay Input1'
     *
     * Block description for '<S31>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_gf = rtb_MultiportSwitch4;

    /* Update for UnitDelay: '<S22>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hk = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S416>/Unit Delay1'
       *  UnitDelay: '<S416>/Unit Delay2'
       *  UnitDelay: '<S416>/Unit Delay3'
       *  UnitDelay: '<S416>/Unit Delay4'
       *  UnitDelay: '<S419>/Delay Input1'
       *  UnitDelay: '<S420>/Delay Input1'
       *  UnitDelay: '<S421>/Delay Input1'
       *  UnitDelay: '<S422>/Delay Input1'
       *  UnitDelay: '<S424>/Delay Input1'
       *  UnitDelay: '<S430>/Unit Delay'
       *  UnitDelay: '<S430>/Unit Delay1'
       *  UnitDelay: '<S434>/FixPt Unit Delay1'
       *  UnitDelay: '<S434>/FixPt Unit Delay2'
       *
       * Block description for '<S419>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S420>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S421>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S422>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S424>/Delay Input1':
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

    /* Switch: '<S414>/Switch4' incorporates:
     *  Constant: '<S439>/Constant'
     *  Constant: '<S442>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S439>/Compare'
     *  RelationalOperator: '<S442>/Compare'
     *  Switch: '<S414>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S414>/Switch4' incorporates:
       *  Constant: '<S414>/Constant8'
       *  Sum: '<S414>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S414>/Switch5' incorporates:
       *  Constant: '<S414>/Constant7'
       *  Gain: '<S414>/Gain'
       *  Sum: '<S414>/Subtract5'
       *  Switch: '<S414>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S414>/Switch4' incorporates:
       *  Constant: '<S414>/Constant6'
       *  Switch: '<S414>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S414>/Switch4' */

    /* Logic: '<S414>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S414>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S416>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_oy = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_oy = 0.0;
    } else {
      rtb_Add_oy = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S416>/Add' incorporates:
     *  Constant: '<S416>/Constant'
     *  Constant: '<S416>/Constant1'
     *  DeadZone: '<S416>/Dead Zone'
     *  Lookup_n-D: '<S416>/Modulation_Str_Y_Rel'
     *  Product: '<S416>/Product'
     *  Product: '<S416>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Add_oy * Steering_Twist_Gain);

    /* RelationalOperator: '<S418>/Compare' incorporates:
     *  Constant: '<S418>/Constant'
     */
    rtb_Compare_ps = (rtb_Switch1_m == 0.0);

    /* Logic: '<S416>/AND2' incorporates:
     *  RelationalOperator: '<S419>/FixPt Relational Operator'
     *  RelationalOperator: '<S420>/FixPt Relational Operator'
     *  RelationalOperator: '<S421>/FixPt Relational Operator'
     *  RelationalOperator: '<S422>/FixPt Relational Operator'
     *  UnitDelay: '<S419>/Delay Input1'
     *  UnitDelay: '<S420>/Delay Input1'
     *  UnitDelay: '<S421>/Delay Input1'
     *  UnitDelay: '<S422>/Delay Input1'
     *
     * Block description for '<S419>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S420>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S421>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S422>/Delay Input1':
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

    /* Logic: '<S416>/AND1' incorporates:
     *  Logic: '<S416>/AND3'
     *  UnitDelay: '<S416>/Unit Delay2'
     */
    rtb_Compare_lq = (rtb_Compare_ps && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S416>/AND4' incorporates:
     *  Logic: '<S416>/AND8'
     *  UnitDelay: '<S416>/Unit Delay4'
     */
    rtb_MultiportSwitch4 = ((rtb_Compare_ps && (!rtb_Intake_Arm_Cycle)) &&
      (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S416>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_Compare_lq ||
      rtb_MultiportSwitch4);

    /* Switch: '<S416>/Switch8' incorporates:
     *  Constant: '<S425>/Constant'
     *  Logic: '<S416>/AND9'
     *  RelationalOperator: '<S424>/FixPt Relational Operator'
     *  RelationalOperator: '<S425>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S424>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S424>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_ps) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S416>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S416>/Switch8' incorporates:
       *  UnitDelay: '<S416>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S416>/Switch8' */

    /* Switch: '<S416>/Switch4' incorporates:
     *  Constant: '<S416>/Constant5'
     *  Switch: '<S416>/Switch1'
     *  Switch: '<S416>/Switch5'
     *  Switch: '<S416>/Switch6'
     *  Switch: '<S416>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Saturation_h = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S416>/Switch5' incorporates:
       *  Constant: '<S416>/Constant6'
       */
      rtb_Saturation_h = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S416>/Switch6' incorporates:
       *  Constant: '<S416>/Constant7'
       *  Switch: '<S416>/Switch5'
       */
      rtb_Saturation_h = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S416>/Switch7' incorporates:
       *  Constant: '<S416>/Constant8'
       *  Switch: '<S416>/Switch5'
       *  Switch: '<S416>/Switch6'
       */
      rtb_Saturation_h = 4.71238898038469;
    } else if (rtb_MultiportSwitch4) {
      /* Switch: '<S416>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S416>/Switch5'
       *  Switch: '<S416>/Switch6'
       *  Switch: '<S416>/Switch7'
       */
      rtb_Saturation_h = 0.0;
    } else {
      /* Switch: '<S416>/Switch6' incorporates:
       *  Switch: '<S416>/Switch5'
       *  Switch: '<S416>/Switch7'
       *  UnitDelay: '<S416>/Unit Delay1'
       */
      rtb_Saturation_h = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S416>/Switch4' */

    /* Switch: '<S416>/Switch2' incorporates:
     *  Switch: '<S416>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S416>/Switch2' incorporates:
       *  Constant: '<S416>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S416>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Saturation_h;
    } else {
      /* Switch: '<S416>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S416>/Switch3' incorporates:
       *  Constant: '<S416>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S416>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S416>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S415>/Switch1' incorporates:
     *  Constant: '<S415>/Constant5'
     *  Constant: '<S415>/Constant8'
     *  DataTypeConversion: '<S415>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_ps;
    }

    /* End of Switch: '<S415>/Switch1' */

    /* Lookup_n-D: '<S417>/Modulation_Drv' incorporates:
     *  Math: '<S417>/Magnitude'
     */
    rtb_Switch_hs = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S428>/Compare' incorporates:
     *  Constant: '<S428>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Switch_hs == 0.0);

    /* DeadZone: '<S417>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_Switch1_n = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S417>/Dead Zone' */

    /* Logic: '<S417>/Logical Operator' incorporates:
     *  Constant: '<S429>/Constant'
     *  RelationalOperator: '<S429>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Switch1_n != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S415>/Switch' incorporates:
     *  Constant: '<S415>/Constant5'
     *  Constant: '<S415>/Constant7'
     *  DataTypeConversion: '<S415>/Data Type Conversion'
     *  Logic: '<S417>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S415>/Switch' */

    /* Switch: '<S414>/Switch2' incorporates:
     *  Constant: '<S414>/Constant2'
     *  Constant: '<S438>/Constant'
     *  Constant: '<S441>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S438>/Compare'
     *  RelationalOperator: '<S441>/Compare'
     *  Sum: '<S414>/Subtract'
     *  Switch: '<S414>/Switch'
     *  Switch: '<S414>/Switch1'
     *  Switch: '<S414>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S414>/Switch2' incorporates:
       *  Constant: '<S414>/Constant5'
       *  Sum: '<S414>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S414>/Switch2' incorporates:
       *  Constant: '<S414>/Constant4'
       *  Sum: '<S414>/Subtract2'
       *  Switch: '<S414>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S414>/Switch1' incorporates:
       *  Constant: '<S414>/Constant1'
       *  Sum: '<S414>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S414>/Switch2' incorporates:
       *  Constant: '<S414>/Constant3'
       *  Switch: '<S414>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S414>/Switch1' incorporates:
       *  Constant: '<S414>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S414>/Switch2' */

    /* UnaryMinus: '<S414>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S430>/Switch1' incorporates:
     *  Constant: '<S435>/Constant'
     *  Constant: '<S436>/Constant'
     *  Logic: '<S430>/AND'
     *  RelationalOperator: '<S435>/Compare'
     *  RelationalOperator: '<S436>/Compare'
     *  Switch: '<S430>/Switch2'
     *  UnitDelay: '<S430>/Unit Delay'
     *  UnitDelay: '<S430>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Init_o = rtb_Switch1_hb;
      rtb_Sin4 = rtb_Sum1;
    }

    /* End of Switch: '<S430>/Switch1' */

    /* Switch: '<S417>/Switch1' incorporates:
     *  Logic: '<S417>/Logical Operator1'
     *  Switch: '<S417>/Switch4'
     *  Switch: '<S417>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S417>/Sign' */
      if (rtIsNaN(rtb_Switch1_n)) {
        rtb_Add_oy = (rtNaN);
      } else if (rtb_Switch1_n < 0.0) {
        rtb_Add_oy = -1.0;
      } else {
        rtb_Add_oy = (rtb_Switch1_n > 0.0);
      }

      /* Switch: '<S417>/Switch5' incorporates:
       *  Constant: '<S417>/Constant3'
       *  Constant: '<S417>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S417>/Gain3'
       *  Signum: '<S417>/Sign'
       *  Sum: '<S417>/Add'
       *  Switch: '<S417>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_oy) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S417>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S417>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S417>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S417>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S417>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S417>/Switch4'
       *  Trigonometry: '<S417>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Init_o, rtb_Sin4);
    }

    /* End of Switch: '<S417>/Switch1' */

    /* Switch: '<S427>/Switch1' incorporates:
     *  Constant: '<S427>/Constant'
     *  Constant: '<S427>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S427>/Switch1' */

    /* Switch: '<S434>/Init' incorporates:
     *  UnitDelay: '<S434>/FixPt Unit Delay1'
     *  UnitDelay: '<S434>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S434>/Init' */

    /* Sum: '<S432>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S433>/Switch2' incorporates:
     *  Constant: '<S431>/Constant1'
     *  Constant: '<S431>/Constant3'
     *  RelationalOperator: '<S433>/LowerRelop1'
     *  RelationalOperator: '<S433>/UpperRelop'
     *  Switch: '<S433>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S433>/Switch' incorporates:
       *  Constant: '<S431>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S433>/Switch2' */

    /* Sum: '<S432>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S417>/Switch8' incorporates:
     *  Logic: '<S417>/Logical Operator1'
     *  Switch: '<S417>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S417>/Switch' incorporates:
       *  Gain: '<S417>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Switch1_n;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S417>/Constant5'
       *  Gain: '<S417>/Gain2'
       *  Math: '<S417>/Magnitude1'
       *  MinMax: '<S417>/Min'
       *  Switch: '<S417>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S427>/Product' incorporates:
       *  Switch: '<S417>/Switch2'
       */
      rtb_Add_oy = rtb_Switch_hs * rtb_Init;

      /* Saturate: '<S427>/Saturation' incorporates:
       *  Switch: '<S417>/Switch2'
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

      /* End of Saturate: '<S427>/Saturation' */
    }

    /* End of Switch: '<S417>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S416>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Switch: '<S414>/Switch6' incorporates:
     *  Constant: '<S414>/Constant11'
     *  Switch: '<S414>/Switch7'
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

    /* RelationalOperator: '<S411>/Compare' incorporates:
     *  Constant: '<S411>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S412>/Compare' incorporates:
     *  Constant: '<S412>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S407>/Compare' incorporates:
     *  Constant: '<S407>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S410>/Compare' incorporates:
     *  Constant: '<S410>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S409>/Compare' incorporates:
     *  Constant: '<S409>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S408>/Compare' incorporates:
     *  Constant: '<S408>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     */
    rtb_Switch1_m = 0.0;

    /* Update for UnitDelay: '<S424>/Delay Input1'
     *
     * Block description for '<S424>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_ps;

    /* Update for UnitDelay: '<S423>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S423>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S419>/Delay Input1'
     *
     * Block description for '<S419>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S420>/Delay Input1'
     *
     * Block description for '<S420>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S421>/Delay Input1'
     *
     * Block description for '<S421>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S422>/Delay Input1'
     *
     * Block description for '<S422>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S416>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_Compare_lq;

    /* Update for UnitDelay: '<S416>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_MultiportSwitch4;

    /* Update for UnitDelay: '<S416>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S416>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S430>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Init_o;

    /* Update for UnitDelay: '<S430>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Sin4;

    /* Update for UnitDelay: '<S434>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S434>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S434>/FixPt Unit Delay1' */
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
    rtb_Switch1_m = 0.0;

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

  /* Reshape: '<S75>/Reshapey' incorporates:
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

  /* Delay: '<S75>/MemoryX' incorporates:
   *  Constant: '<S75>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S102>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S128>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S95>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S126>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S126>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S75>/C'
     *  Delay: '<S75>/MemoryX'
     *  Product: '<S128>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Init_o;

    /* Sum: '<S126>/Sum' incorporates:
     *  Constant: '<S75>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S126>/C[k]*xhat[k|k-1]'
     *  Product: '<S126>/D[k]*u[k]'
     *  Sum: '<S126>/Add1'
     */
    rtb_Sin4 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Saturation_h = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Init_o);

    /* Product: '<S126>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S75>/C'
     *  Delay: '<S75>/MemoryX'
     *  Product: '<S128>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Init_o;

    /* Sum: '<S126>/Sum' incorporates:
     *  Constant: '<S75>/D'
     *  Product: '<S126>/C[k]*xhat[k|k-1]'
     *  Product: '<S126>/D[k]*u[k]'
     *  Sum: '<S126>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Init_o);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S126>/Product3' incorporates:
     *  Constant: '<S76>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Saturation_h) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S128>/Add1' incorporates:
     *  Product: '<S128>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S126>/Product3' incorporates:
     *  Constant: '<S76>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Saturation_h) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S128>/Add1' incorporates:
     *  Product: '<S128>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S128>/Product2' incorporates:
     *  Constant: '<S76>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S126>/Product3' incorporates:
       *  Outport: '<S126>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S128>/Product2' incorporates:
       *  Outport: '<S128>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S95>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S102>/Enabled Subsystem' */

  /* Sum: '<S102>/Add' incorporates:
   *  Delay: '<S75>/MemoryX'
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
   *  Constant: '<S247>/Constant'
   *  Logic: '<S247>/AND'
   *  MATLAB Function: '<S197>/Find closest index to curve'
   *  Product: '<S247>/Product'
   *  RelationalOperator: '<S247>/Relational Operator'
   *  RelationalOperator: '<S247>/Relational Operator1'
   *  Selector: '<S247>/Selector'
   *  Selector: '<S247>/Selector1'
   *  Selector: '<S248>/Selector'
   *  Sum: '<S247>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S200>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S203>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S205>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d0 = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S200>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S195>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S195>/Unit Delay'
       *  UnitDelay: '<S196>/Unit Delay'
       *  UnitDelay: '<S198>/Unit Delay'
       *  UnitDelay: '<S198>/Unit Delay1'
       *  UnitDelay: '<S248>/Unit Delay'
       *  UnitDelay: '<S248>/Unit Delay1'
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
     *  ActionPort: '<S195>/Action Port'
     */
    /* Selector: '<S196>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S196>/Selector1' */

    /* Lookup_n-D: '<S195>/Capture Radius' incorporates:
     *  UnitDelay: '<S195>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S196>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S196>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S200>/If' incorporates:
     *  RelationalOperator: '<S200>/ '
     *  UnitDelay: '<S196>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S203>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S205>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d0 = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S200>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S203>/Action Port'
       */
      /* InitializeConditions for If: '<S200>/If' incorporates:
       *  UnitDelay: '<S203>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S200>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S200>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S203>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S203>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S206>/Action Port'
       */
      /* If: '<S203>/If' incorporates:
       *  Selector: '<S196>/Selector1'
       *  Selector: '<S203>/Selector'
       *  Selector: '<S206>/Selector'
       */
      rtb_Switch2_p2 = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S203>/Increment_If_Rectangle_Check' */

      /* Sum: '<S203>/Minus' incorporates:
       *  Concatenate: '<S196>/Matrix Concatenate2'
       *  Selector: '<S203>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Switch2_p2;

      /* Outputs for IfAction SubSystem: '<S203>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S206>/Action Port'
       */
      /* If: '<S203>/If' incorporates:
       *  Selector: '<S196>/Selector1'
       *  Selector: '<S203>/Selector'
       *  Selector: '<S206>/Selector'
       *  Sum: '<S203>/Minus'
       */
      rtb_Switch_hs = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S203>/Increment_If_Rectangle_Check' */

      /* Sum: '<S203>/Minus' incorporates:
       *  Concatenate: '<S196>/Matrix Concatenate2'
       *  Selector: '<S203>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Switch_hs;

      /* Math: '<S203>/Hypot' */
      rtb_Init_o = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S203>/Equal' */
      rtb_Is_Absolute_Steering = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S203>/Switch' incorporates:
       *  Logic: '<S203>/AND'
       *  Logic: '<S203>/OR'
       *  RelationalOperator: '<S203>/Relational Operator'
       *  UnitDelay: '<S203>/Unit Delay'
       */
      rtb_Is_Absolute_Translation_g = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Init_o <= rtb_Saturation_h) && rtb_Is_Absolute_Steering));

      /* If: '<S203>/If' */
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
        /* Disable for If: '<S205>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d0 = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S203>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S205>/Action Port'
         */
        /* If: '<S205>/If' incorporates:
         *  RelationalOperator: '<S205>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d0;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d0 = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S205>/Is_Last_Point' incorporates:
           *  ActionPort: '<S208>/Action Port'
           */
          /* InitializeConditions for If: '<S205>/If' incorporates:
           *  UnitDelay: '<S208>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S205>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S205>/Is_Last_Point' incorporates:
           *  ActionPort: '<S208>/Action Port'
           */
          /* Switch: '<S208>/Switch' incorporates:
           *  Constant: '<S210>/Constant'
           *  Logic: '<S208>/OR'
           *  RelationalOperator: '<S210>/Compare'
           *  UnitDelay: '<S208>/Unit Delay'
           */
          rtb_Compare_lq = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
                            (rtb_Init_o <= Spline_Stop_Radius));

          /* If: '<S208>/If' */
          if (rtb_Compare_lq) {
            /* Outputs for IfAction SubSystem: '<S208>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S211>/Action Port'
             */
            /* Merge: '<S200>/Merge2' incorporates:
             *  Constant: '<S211>/Constant'
             *  SignalConversion generated from: '<S211>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = true;

            /* SignalConversion generated from: '<S211>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S211>/Constant1'
             */
            rtb_Compare_ps = false;

            /* End of Outputs for SubSystem: '<S208>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S208>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S212>/Action Port'
             */
            /* Merge: '<S200>/Merge2' incorporates:
             *  Constant: '<S212>/Constant'
             *  SignalConversion generated from: '<S212>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = false;

            /* SignalConversion generated from: '<S212>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S212>/Constant1'
             */
            rtb_Compare_ps = true;

            /* End of Outputs for SubSystem: '<S208>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S208>/If' */

          /* Merge: '<S200>/Merge4' incorporates:
           *  SignalConversion: '<S208>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S208>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Compare_lq;

          /* End of Outputs for SubSystem: '<S205>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S205>/Increment_Search' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          /* Merge: '<S200>/Merge2' incorporates:
           *  Constant: '<S207>/Constant'
           *  SignalConversion generated from: '<S207>/Robot_Reached_Destination'
           */
          rtb_Is_Absolute_Steering = false;

          /* SignalConversion generated from: '<S207>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S207>/Constant1'
           */
          rtb_Compare_ps = false;

          /* Merge: '<S200>/Merge4' incorporates:
           *  Constant: '<S209>/FixPt Constant'
           *  SignalConversion: '<S207>/Signal Copy'
           *  Sum: '<S209>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S205>/Increment_Search' */
        }

        /* End of If: '<S205>/If' */
        /* End of Outputs for SubSystem: '<S203>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S203>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S206>/Action Port'
         */
        /* Sum: '<S213>/FixPt Sum1' incorporates:
         *  Constant: '<S213>/FixPt Constant'
         */
        rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S206>/Selector1' incorporates:
         *  Selector: '<S196>/Selector1'
         */
        rtb_Minus_k_idx_0 = rtb_Ref_Poses[((int32_T)rtb_Init_o) - 1];

        /* Sum: '<S214>/Subtract' incorporates:
         *  Selector: '<S206>/Selector1'
         *  Sum: '<S214>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Minus_k_idx_0 - rtb_Switch2_p2;

        /* Selector: '<S206>/Selector1' incorporates:
         *  Selector: '<S196>/Selector1'
         */
        rtb_Switch1_n = rtb_Ref_Poses[((int32_T)rtb_Init_o) + 9];

        /* Sum: '<S214>/Subtract' incorporates:
         *  Selector: '<S206>/Selector1'
         *  Sum: '<S214>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1_n - rtb_Switch_hs;

        /* Math: '<S214>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S214>/Divide' */
        rtb_Init_o = rtb_Minus_n[1];

        /* UnaryMinus: '<S214>/Unary Minus' */
        rtb_Switch2_c3 = rtb_Minus_n[0];

        /* Product: '<S214>/Product' incorporates:
         *  Product: '<S214>/Divide'
         *  UnaryMinus: '<S214>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Init_o / rtb_Sin4) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Switch2_c3) / rtb_Sin4) * rtb_Saturation_h;

        /* Sum: '<S214>/Add1' incorporates:
         *  Sum: '<S214>/Add2'
         *  Sum: '<S214>/Minus'
         */
        rtb_Switch2_c3 = rtb_Minus_k_idx_0 - rtb_Minus_n[0];

        /* Sum: '<S214>/Minus4' incorporates:
         *  Sum: '<S214>/Add2'
         *  Sum: '<S214>/Minus'
         */
        rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_0 + rtb_Minus_n[0]) -
          rtb_Switch2_c3;

        /* Sum: '<S214>/Minus5' incorporates:
         *  Concatenate: '<S196>/Matrix Concatenate2'
         *  Sum: '<S214>/Minus'
         */
        rtb_Init = rtb_Reshapey[0] - rtb_Switch2_c3;

        /* Sum: '<S214>/Add' incorporates:
         *  Sum: '<S214>/Add2'
         *  Sum: '<S214>/Minus1'
         */
        rtb_Init_o = rtb_Switch2_p2 - rtb_Minus_n[0];

        /* Sum: '<S214>/Minus' incorporates:
         *  Sum: '<S214>/Minus1'
         */
        rtb_Switch2_c3 -= rtb_Init_o;

        /* DotProduct: '<S214>/Dot Product' incorporates:
         *  Concatenate: '<S196>/Matrix Concatenate2'
         *  Sum: '<S214>/Minus'
         *  Sum: '<S214>/Minus1'
         *  Sum: '<S214>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Init_o) * rtb_Switch2_c3;

        /* DotProduct: '<S214>/Dot Product1' incorporates:
         *  Sum: '<S214>/Minus'
         */
        rtb_Switch2_p2 = rtb_Switch2_c3 * rtb_Switch2_c3;

        /* DotProduct: '<S214>/Dot Product2' incorporates:
         *  Sum: '<S214>/Minus4'
         *  Sum: '<S214>/Minus5'
         */
        rtb_Minus_k_idx_1 = rtb_Minus_k_idx_0 * rtb_Init;

        /* DotProduct: '<S214>/Dot Product3' incorporates:
         *  Sum: '<S214>/Minus4'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0 * rtb_Minus_k_idx_0;

        /* Sum: '<S214>/Add1' incorporates:
         *  Sum: '<S214>/Add2'
         *  Sum: '<S214>/Minus'
         */
        rtb_Switch2_c3 = rtb_Switch1_n - rtb_Minus_n[1];

        /* Sum: '<S214>/Minus4' incorporates:
         *  Sum: '<S214>/Add2'
         *  Sum: '<S214>/Minus'
         */
        rtb_Minus_k_idx_0 = (rtb_Switch1_n + rtb_Minus_n[1]) - rtb_Switch2_c3;

        /* Sum: '<S214>/Minus5' incorporates:
         *  Concatenate: '<S196>/Matrix Concatenate2'
         *  Sum: '<S214>/Minus'
         */
        rtb_Init = rtb_Reshapey[1] - rtb_Switch2_c3;

        /* Sum: '<S214>/Add' incorporates:
         *  Sum: '<S214>/Add2'
         *  Sum: '<S214>/Minus1'
         */
        rtb_Init_o = rtb_Switch_hs - rtb_Minus_n[1];

        /* Sum: '<S214>/Minus' incorporates:
         *  Sum: '<S214>/Minus1'
         */
        rtb_Switch2_c3 -= rtb_Init_o;

        /* DotProduct: '<S214>/Dot Product' incorporates:
         *  Concatenate: '<S196>/Matrix Concatenate2'
         *  Sum: '<S214>/Minus'
         *  Sum: '<S214>/Minus1'
         *  Sum: '<S214>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Init_o) * rtb_Switch2_c3;

        /* RelationalOperator: '<S215>/Compare' incorporates:
         *  Constant: '<S215>/Constant'
         */
        rtb_Is_Absolute_Steering = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S214>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S214>/Dot Product1'
         *  Sum: '<S214>/Minus'
         */
        rtb_Compare_ps = (rtb_Sin4 <= ((rtb_Switch2_c3 * rtb_Switch2_c3) +
          rtb_Switch2_p2));

        /* DotProduct: '<S214>/Dot Product2' incorporates:
         *  Sum: '<S214>/Minus4'
         *  Sum: '<S214>/Minus5'
         */
        rtb_Sin4 = (rtb_Minus_k_idx_0 * rtb_Init) + rtb_Minus_k_idx_1;

        /* Merge: '<S200>/Merge4' incorporates:
         *  Constant: '<S216>/Constant'
         *  DataTypeConversion: '<S206>/Data Type Conversion'
         *  DotProduct: '<S214>/Dot Product3'
         *  Logic: '<S214>/AND'
         *  RelationalOperator: '<S214>/LessThanOrEqual1'
         *  RelationalOperator: '<S216>/Compare'
         *  Sum: '<S206>/Add'
         *  Sum: '<S214>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)
          (((rtb_Is_Absolute_Steering && rtb_Compare_ps) && (rtb_Sin4 >= 0.0)) &&
           (rtb_Sin4 <= ((rtb_Minus_k_idx_0 * rtb_Minus_k_idx_0) +
                         rtb_MatrixConcatenate_b_idx_0)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S200>/Merge2' incorporates:
         *  Constant: '<S206>/Constant2'
         *  SignalConversion generated from: '<S206>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S206>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S206>/Constant1'
         */
        rtb_Compare_ps = false;

        /* End of Outputs for SubSystem: '<S203>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S203>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S204>/Action Port'
         */
        /* Merge: '<S200>/Merge2' incorporates:
         *  Constant: '<S204>/Constant2'
         *  SignalConversion generated from: '<S204>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S204>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S204>/Constant1'
         */
        rtb_Compare_ps = false;

        /* Merge: '<S200>/Merge4' incorporates:
         *  SignalConversion generated from: '<S204>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S203>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S200>/Merge1' incorporates:
       *  Constant: '<S203>/Constant'
       *  SignalConversion generated from: '<S203>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S203>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_Is_Absolute_Translation_g;

      /* End of Outputs for SubSystem: '<S200>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S200>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S202>/Action Port'
       */
      /* Merge: '<S200>/Merge1' incorporates:
       *  Constant: '<S202>/Constant'
       *  SignalConversion generated from: '<S202>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S200>/Merge2' incorporates:
       *  Constant: '<S202>/Constant1'
       *  SignalConversion generated from: '<S202>/Robot_Reached_Destination'
       */
      rtb_Is_Absolute_Steering = false;

      /* SignalConversion generated from: '<S202>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S202>/Constant2'
       */
      rtb_Compare_ps = false;

      /* Merge: '<S200>/Merge4' incorporates:
       *  SignalConversion generated from: '<S202>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S200>/Escape_Auto_Driving' */
    }

    /* End of If: '<S200>/If' */

    /* If: '<S196>/If1' */
    if (!rtb_Compare_ps) {
      /* Outputs for IfAction SubSystem: '<S196>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      /* Bias: '<S217>/Add Constant' incorporates:
       *  Bias: '<S217>/Bias'
       *  Sum: '<S217>/Subtract'
       */
      rtb_Init_o = ((Robot_Control_B.Spline_Num_Poses -
                     Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S217>/Selector4' incorporates:
       *  Bias: '<S217>/Bias1'
       *  Constant: '<S219>/FixPt Constant'
       *  Sum: '<S219>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S217>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S217>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s222_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S217>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S217>/Selector5' incorporates:
       *  Concatenate: '<S217>/Matrix Concatenate'
       *  Gain: '<S221>/Gain'
       *  Selector: '<S196>/Selector1'
       *  Selector: '<S217>/Selector2'
       *  Selector: '<S217>/Selector3'
       *  Sum: '<S221>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s222_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S217>/Matrix Concatenate' incorporates:
       *  Bias: '<S217>/Add Constant1'
       *  Gain: '<S220>/Gain'
       *  Selector: '<S196>/Selector1'
       *  Selector: '<S217>/Selector'
       *  Selector: '<S217>/Selector1'
       *  Selector: '<S217>/Selector5'
       *  Sum: '<S220>/Subtract'
       */
      s222_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s222_iter;
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

      /* Selector: '<S217>/Selector4' */
      s222_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s222_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S217>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S217>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S217>/Assignment' incorporates:
       *  Concatenate: '<S217>/Matrix Concatenate'
       *  Selector: '<S217>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s222_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S218>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S222>/While Iterator'
       */
      s222_iter = 1;
      do {
        rtb_Switch2_p2 = rtb_Assignment[s222_iter + 1];
        rtb_Minus_n[0] = rtb_Switch2_p2 - rtb_Assignment[s222_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s222_iter] - rtb_Assignment[s222_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Switch2_p2 - rtb_Assignment[s222_iter];
        rtb_Switch2_p2 = rtb_Assignment[s222_iter + 13];
        rtb_Minus_n[1] = rtb_Switch2_p2 - rtb_Assignment[s222_iter + 11];
        rtb_Switch2_c3 = rtb_Assignment[s222_iter + 12];
        rtb_Add2[1] = rtb_Switch2_c3 - rtb_Assignment[s222_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Switch2_p2 - rtb_Switch2_c3;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Sin4 = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Switch_hs = rt_powd_snf(rtb_Sin4, 2.0);
          rtb_Switch2_p2 = rt_powd_snf(rtb_Sin4, 3.0);
          rtb_Switch1_n = (rtb_Sin4 - (2.0 * rtb_Switch_hs)) + rtb_Switch2_p2;
          rtb_Init = rtb_Switch_hs - rtb_Switch2_p2;
          rtb_Switch2_p2 = (3.0 * rtb_Switch_hs) - (2.0 * rtb_Switch2_p2);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch1_n) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Switch2_p2)) + rtb_Assignment[s222_iter];
          rtb_Switch2_p2 = ((((rtb_Minus_n[1] * rtb_Switch1_n) + (rtb_Add2[1] *
            rtb_Init)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_p2)) +
            rtb_Switch2_c3;
          rtb_Switch1_n = ((3.0 * rtb_Switch_hs) - (4.0 * rtb_Sin4)) + 1.0;
          rtb_Init = (2.0 * rtb_Sin4) - (3.0 * rtb_Switch_hs);
          rtb_Switch_hs = (rtb_Sin4 - rtb_Switch_hs) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch1_n) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Switch_hs);
          rtb_Switch2_bq = (((rtb_Minus_n[1] * rtb_Switch1_n) + (rtb_Add2[1] *
            rtb_Init)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch_hs);
          rtb_Switch_hs = (6.0 * rtb_Sin4) - 4.0;
          rtb_Switch1_n = (-6.0 * rtb_Sin4) + 2.0;
          rtb_Sin4 = (-12.0 * rtb_Sin4) + 6.0;
          rtb_Init = (((rtb_Minus_n[0] * rtb_Switch_hs) + (rtb_Add2[0] *
            rtb_Switch1_n)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Sin4);
          rtb_Switch1_n = (((rtb_Minus_n[1] * rtb_Switch_hs) + (rtb_Add2[1] *
            rtb_Switch1_n)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Sin4);
          rtb_Switch_hs = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Switch2_bq), 3.0);
          rtb_Sin4 = fmax(1.0E-10, rtb_Switch_hs);
          Robot_Control_DW.Relay_Mode = ((rtb_Switch_hs >=
            2.2204460492503131E-16) || (Robot_Control_DW.Relay_Mode));
          if (Robot_Control_DW.Relay_Mode) {
            rtb_Switch_hs = 1.0;
          } else {
            rtb_Switch_hs = -1.0;
          }

          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Switch2_p2;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch1_n) - (rtb_Init *
              rtb_Switch2_bq)) / (rtb_Sin4 * rtb_Switch_hs);
        }

        if (s222_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s222_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Init_o - ((real_T)s222_iter);
        rtb_Num_Segments = s222_iter;
        s222_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s222_iter <= 3));

      /* End of Outputs for SubSystem: '<S218>/Sampling_Loop' */

      /* SignalConversion generated from: '<S201>/Position_and_Curvature' incorporates:
       *  Assignment: '<S222>/Assignment'
       *  Merge: '<S196>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S196>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S196>/If Action Subsystem' incorporates:
       *  ActionPort: '<S199>/Action Port'
       */
      /* Product: '<S199>/Product' incorporates:
       *  Selector: '<S196>/Selector'
       *  Selector: '<S196>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1];

      /* Product: '<S199>/Product1' incorporates:
       *  Selector: '<S196>/Selector'
       *  Selector: '<S196>/Selector1'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S199>/Product' incorporates:
         *  Constant: '<S199>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S199>/Product1' incorporates:
         *  Constant: '<S199>/Constant2'
         *  Product: '<S199>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Init_o;
      }

      /* Assignment: '<S199>/Assignment' incorporates:
       *  Concatenate: '<S199>/Matrix Concatenate'
       *  Merge: '<S196>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S199>/Assignment' */

      /* SignalConversion generated from: '<S199>/Num_Segments' incorporates:
       *  Constant: '<S199>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S196>/If Action Subsystem' */
    }

    /* End of If: '<S196>/If1' */

    /* Concatenate: '<S197>/Matrix Concatenate' incorporates:
     *  Merge: '<S196>/Merge'
     *  Selector: '<S197>/Selector'
     *  Selector: '<S197>/Selector1'
     *  Selector: '<S197>/Selector3'
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

    /* End of Concatenate: '<S197>/Matrix Concatenate' */

    /* MATLAB Function: '<S197>/Distance Along Curve' incorporates:
     *  Concatenate: '<S197>/Matrix Concatenate'
     *  Selector: '<S197>/Selector4'
     *  Selector: '<S197>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s222_iter = 0; s222_iter < 149; s222_iter++) {
      /* Outputs for Iterator SubSystem: '<S218>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S222>/While Iterator'
       */
      rtb_Assignment_d[s222_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s222_iter + 1] -
         rtb_MatrixConcatenate_o[s222_iter], rtb_MatrixConcatenate_o[s222_iter +
         151] - rtb_MatrixConcatenate_o[s222_iter + 150]) +
        rtb_Assignment_d[s222_iter];

      /* End of Outputs for SubSystem: '<S218>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S197>/Distance Along Curve' */

    /* MATLAB Function: '<S197>/Find closest index to curve' incorporates:
     *  Concatenate: '<S197>/Matrix Concatenate'
     *  Selector: '<S197>/Selector4'
     *  Selector: '<S197>/Selector5'
     *  Selector: '<S248>/Selector'
     */
    for (s222_iter = 0; s222_iter < 150; s222_iter++) {
      /* Outputs for Iterator SubSystem: '<S218>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S222>/While Iterator'
       */
      distance_from_robot[s222_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s222_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s222_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S218>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s222_iter = 1;
    } else {
      s222_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s222_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s222_iter == 0) {
      rtb_Init_o = distance_from_robot[0];
    } else {
      rtb_Init_o = distance_from_robot[s222_iter - 1];
      for (rtb_Bias1_p = s222_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Init_o > rtb_Sin4) {
          rtb_Init_o = rtb_Sin4;
        }
      }
    }

    s222_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s222_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Init_o) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S248>/Selector' incorporates:
     *  Constant: '<S248>/Constant'
     *  MATLAB Function: '<S197>/Find closest index to curve'
     *  MinMax: '<S248>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s222_iter)) - 1];

    /* If: '<S248>/If' incorporates:
     *  RelationalOperator: '<S248>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S248>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S251>/Action Port'
       */
      /* SignalConversion generated from: '<S251>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S253>/FixPt Sum1' incorporates:
       *  Constant: '<S253>/FixPt Constant'
       */
      rtb_Init_o = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S251>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S251>/Selector11'
       *  Selector: '<S251>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S251>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S251>/Selector1'
       *  Selector: '<S251>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S251>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S251>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Init_o), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S251>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S251>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S251>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S248>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S248>/Latch' incorporates:
       *  ActionPort: '<S252>/Action Port'
       */
      /* SignalConversion generated from: '<S252>/In1' incorporates:
       *  UnitDelay: '<S248>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S252>/In2' incorporates:
       *  UnitDelay: '<S248>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S248>/Latch' */
    }

    /* End of If: '<S248>/If' */

    /* MinMax: '<S195>/Min' incorporates:
     *  Lookup_n-D: '<S195>/Lookahead Distance'
     *  UnitDelay: '<S195>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S197>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S247>/While Iterator'
     */
    s247_iter = 1U;
    rtb_Is_Absolute_Translation_g = true;
    while (rtb_Is_Absolute_Translation_g && (s247_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S197>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S247>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s247_iter;
      rtb_Is_Absolute_Translation_g =
        ((rtb_Assignment_d[Robot_Control_B.WhileIterator - 1] <=
          (rtb_Assignment_d[s222_iter - 1] + rtb_Saturation_h)) &&
         (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s247_iter++;
    }

    /* End of Outputs for SubSystem: '<S197>/Find first index that meets distance target' */

    /* Switch: '<S250>/Switch' incorporates:
     *  Concatenate: '<S197>/Matrix Concatenate'
     *  Constant: '<S197>/Constant'
     *  Constant: '<S247>/Constant'
     *  Constant: '<S250>/Constant'
     *  Constant: '<S250>/Constant1'
     *  Constant: '<S250>/Constant2'
     *  Constant: '<S250>/Constant3'
     *  Logic: '<S247>/AND'
     *  MATLAB Function: '<S197>/Find closest index to curve'
     *  Math: '<S250>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S250>/Max'
     *  MinMax: '<S250>/Min'
     *  MinMax: '<S250>/Min1'
     *  Product: '<S247>/Product'
     *  Product: '<S250>/Divide'
     *  Product: '<S250>/Product'
     *  Product: '<S250>/Product1'
     *  RelationalOperator: '<S197>/Relational Operator'
     *  RelationalOperator: '<S247>/Relational Operator'
     *  RelationalOperator: '<S247>/Relational Operator1'
     *  Selector: '<S197>/Selector10'
     *  Selector: '<S197>/Selector7'
     *  Selector: '<S197>/Selector8'
     *  Selector: '<S197>/Selector9'
     *  Selector: '<S247>/Selector'
     *  Selector: '<S247>/Selector1'
     *  Selector: '<S248>/Selector'
     *  Sqrt: '<S250>/Sqrt'
     *  Sum: '<S197>/Subtract'
     *  Sum: '<S247>/Add'
     *  Sum: '<S250>/Subtract'
     *  Sum: '<S250>/Subtract1'
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

    /* End of Switch: '<S250>/Switch' */

    /* Logic: '<S198>/OR' */
    rtb_Compare_ps = (rtb_Is_Absolute_Steering ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S198>/Switch1' incorporates:
     *  Switch: '<S198>/Switch'
     *  UnitDelay: '<S198>/Unit Delay'
     */
    if (rtb_Compare_ps) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S198>/Constant3'
       *  SignalConversion: '<S198>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S198>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S198>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S198>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S197>/Selector6' incorporates:
     *  Concatenate: '<S197>/Matrix Concatenate'
     *  Selector: '<S197>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S197>/Selector2' incorporates:
     *  Concatenate: '<S197>/Matrix Concatenate'
     *  Selector: '<S197>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S198>/Switch2' incorporates:
     *  Sum: '<S254>/Subtract'
     *  Sum: '<S254>/Subtract1'
     *  Trigonometry: '<S254>/Atan2'
     *  UnitDelay: '<S198>/Unit Delay1'
     */
    if (rtb_Compare_ps) {
      rtb_Switch_hs = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Switch_hs = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S198>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S198>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Switch_hs;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S195>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S195>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S198>/Constant2'
     *  SignalConversion generated from: '<S195>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S198>/Constant5'
     *  SignalConversion generated from: '<S195>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S198>/Constant6'
     *  SignalConversion generated from: '<S195>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S195>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S196>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S195>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S248>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Init_o;

    /* Update for UnitDelay: '<S248>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S198>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S198>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Switch_hs;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S194>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S194>/Constant1'
     *  SignalConversion generated from: '<S194>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S194>/Constant'
     *  SignalConversion generated from: '<S194>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S194>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S194>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S194>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S194>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S194>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S194>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S194>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S344>/Sign2' incorporates:
   *  UnitDelay: '<S344>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S344>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S344>/Product1' incorporates:
   *  Signum: '<S344>/Sign1'
   *  Signum: '<S344>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S344>/Switch' incorporates:
   *  Constant: '<S344>/Constant'
   *  Constant: '<S349>/Constant'
   *  Constant: '<S350>/Constant'
   *  Logic: '<S344>/or'
   *  Product: '<S344>/Product1'
   *  RelationalOperator: '<S349>/Compare'
   *  RelationalOperator: '<S350>/Compare'
   *  UnitDelay: '<S344>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S344>/Switch' */

  /* Switch: '<S355>/Init' incorporates:
   *  UnitDelay: '<S355>/FixPt Unit Delay1'
   *  UnitDelay: '<S355>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S355>/Init' */

  /* RelationalOperator: '<S351>/Compare' incorporates:
   *  Constant: '<S351>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S352>/Compare' incorporates:
   *  Constant: '<S352>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Sin4 > 0.0);

  /* Abs: '<S344>/Abs' incorporates:
   *  Sum: '<S344>/Subtract'
   *  UnitDelay: '<S344>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S344>/Switch5' incorporates:
   *  Constant: '<S344>/Constant1'
   *  Switch: '<S344>/Switch1'
   *  UnaryMinus: '<S344>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* SignalConversion generated from: '<S344>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S344>/Constant4'
     *  Constant: '<S344>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S344>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S344>/Constant2'
     *  Constant: '<S344>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S344>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S344>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S344>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S344>/Constant10'
     *  Constant: '<S344>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S344>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S344>/Constant7'
     *  Constant: '<S344>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S344>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S344>/Lookup Table Dynamic1'
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

    /* Switch: '<S344>/Switch3' incorporates:
     *  Constant: '<S344>/Constant1'
     *  Constant: '<S344>/Constant3'
     *  UnaryMinus: '<S344>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_oy = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_oy = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S344>/Switch3' */
  }

  /* End of Switch: '<S344>/Switch5' */

  /* Product: '<S344>/Product' incorporates:
   *  Switch: '<S344>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_oy * rtb_Merge1;

  /* Sum: '<S353>/Sum1' */
  rtb_Saturation_h = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S354>/Switch2' incorporates:
   *  RelationalOperator: '<S354>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S344>/Switch2' incorporates:
     *  Constant: '<S344>/Constant1'
     *  Switch: '<S344>/Switch4'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S344>/Switch4' incorporates:
       *  Constant: '<S344>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S344>/Switch4' incorporates:
       *  Constant: '<S344>/Constant3'
       *  UnaryMinus: '<S344>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S344>/Switch2' */

    /* Product: '<S344>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S354>/Switch' incorporates:
     *  RelationalOperator: '<S354>/UpperRelop'
     */
    if (rtb_Saturation_h < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Saturation_h;
    }

    /* End of Switch: '<S354>/Switch' */
  }

  /* End of Switch: '<S354>/Switch2' */

  /* Sum: '<S353>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S347>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S347>/Switch' incorporates:
     *  Constant: '<S381>/Constant3'
     *  Constant: '<S381>/Constant4'
     *  Math: '<S381>/Math Function'
     *  Sum: '<S347>/Subtract'
     *  Sum: '<S381>/Add1'
     *  Sum: '<S381>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S347>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S347>/Switch' */

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

  /* Sum: '<S135>/Subtract' incorporates:
   *  Constant: '<S135>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Sin4 = Rebuilt_Match_Time_TeleOp - Robot_Control_U.MatchTime;

  /* If: '<S135>/If' incorporates:
   *  Constant: '<S161>/Constant'
   *  Constant: '<S162>/Constant'
   *  Constant: '<S163>/Constant'
   *  Constant: '<S164>/Constant'
   *  Constant: '<S165>/Constant'
   *  Constant: '<S166>/Constant'
   *  Inport: '<Root>/IsBlueAlliance'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S161>/Compare'
   *  RelationalOperator: '<S162>/Compare'
   *  RelationalOperator: '<S163>/Compare'
   *  RelationalOperator: '<S164>/Compare'
   *  RelationalOperator: '<S165>/Compare'
   *  RelationalOperator: '<S166>/Compare'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
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

  Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S135>/If Action Subsystem' incorporates:
       *  ActionPort: '<S167>/Action Port'
       */
      /* InitializeConditions for If: '<S135>/If' incorporates:
       *  UnitDelay: '<S167>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_ms = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S135>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    /* Merge: '<S135>/Merge' incorporates:
     *  Constant: '<S167>/Constant'
     *  SignalConversion generated from: '<S167>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S135>/Merge1' incorporates:
     *  Constant: '<S167>/Constant'
     *  SignalConversion generated from: '<S167>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S167>/Sum' incorporates:
     *  Constant: '<S167>/Constant1'
     *  UnitDelay: '<S167>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_ms - 0.02;

    /* Merge: '<S135>/Merge2' incorporates:
     *  SignalConversion: '<S167>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S167>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ms = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S168>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    /* Sum: '<S169>/Sum' incorporates:
     *  Constant: '<S169>/Constant1'
     *  UnitDelay: '<S169>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_m - 0.02;

    /* RelationalOperator: '<S174>/Compare' incorporates:
     *  Constant: '<S174>/Constant'
     */
    rtb_Is_Absolute_Translation_g = (rtb_Merge1 <=
      Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S135>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S169>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_Is_Absolute_Translation_g);

    /* Merge: '<S135>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S169>/Logical Operator1'
     *  Logic: '<S169>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_Is_Absolute_Translation_g);

    /* Switch: '<S169>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S169>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S135>/Merge2' incorporates:
       *  Constant: '<S169>/Constant2'
       *  Sum: '<S169>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1 -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S135>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;
    }

    /* End of Switch: '<S169>/Switch' */

    /* Update for UnitDelay: '<S169>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    /* Sum: '<S171>/Sum' incorporates:
     *  Constant: '<S171>/Constant1'
     *  UnitDelay: '<S171>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_n - 0.02;

    /* RelationalOperator: '<S176>/Compare' incorporates:
     *  Constant: '<S176>/Constant'
     */
    rtb_Is_Absolute_Translation_g = (rtb_Merge1 <=
      Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S135>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S171>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_Is_Absolute_Translation_g);

    /* Merge: '<S135>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S171>/Logical Operator1'
     *  Logic: '<S171>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_Is_Absolute_Translation_g);

    /* Switch: '<S171>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S171>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S135>/Merge2' incorporates:
       *  Constant: '<S171>/Constant2'
       *  Sum: '<S171>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1 -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S135>/Merge2' incorporates:
       *  Constant: '<S171>/Constant3'
       *  Sum: '<S171>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1 +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S171>/Switch' */

    /* Update for UnitDelay: '<S171>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S172>/Action Port'
     */
    /* Merge: '<S135>/Merge' incorporates:
     *  Constant: '<S172>/Constant'
     *  SignalConversion generated from: '<S172>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S135>/Merge1' incorporates:
     *  Constant: '<S172>/Constant'
     *  SignalConversion generated from: '<S172>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S172>/Sum' incorporates:
     *  Constant: '<S172>/Constant1'
     *  UnitDelay: '<S172>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_ht - 0.02;

    /* Merge: '<S135>/Merge2' incorporates:
     *  SignalConversion: '<S172>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S172>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ht = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S135>/If' */

  /* If: '<S178>/If' incorporates:
   *  If: '<S179>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S178>/Blue' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* Merge: '<S178>/Merge' incorporates:
     *  Constant: '<S180>/BlueAllianceZoneX'
     *  Logic: '<S180>/AND'
     *  RelationalOperator: '<S180>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S178>/Blue' */

    /* Outputs for IfAction SubSystem: '<S179>/Blue' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    /* Merge: '<S179>/Merge' incorporates:
     *  Constant: '<S182>/BlueAllianceZoneX'
     *  RelationalOperator: '<S182>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S179>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S178>/Red' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    /* Merge: '<S178>/Merge' incorporates:
     *  Constant: '<S181>/RedAllianceZoneX'
     *  Logic: '<S181>/AND'
     *  RelationalOperator: '<S181>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S178>/Red' */

    /* Outputs for IfAction SubSystem: '<S179>/Red' incorporates:
     *  ActionPort: '<S183>/Action Port'
     */
    /* Merge: '<S179>/Merge' incorporates:
     *  Constant: '<S183>/RedAllianceZoneX'
     *  RelationalOperator: '<S183>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S179>/Red' */
  }

  /* End of If: '<S178>/If' */

  /* RelationalOperator: '<S137>/GreaterThan' incorporates:
   *  Constant: '<S137>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S137>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S137>/Relational Operator' incorporates:
   *  Abs: '<S137>/Abs'
   *  Constant: '<S177>/Constant3'
   *  Constant: '<S177>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S177>/Math Function'
   *  Sum: '<S137>/Subtract'
   *  Sum: '<S177>/Add1'
   *  Sum: '<S177>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S136>/Max' incorporates:
   *  Abs: '<S136>/Abs1'
   *  Abs: '<S136>/Abs2'
   *  Abs: '<S136>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S137>/Relational Operator1' incorporates:
   *  Abs: '<S137>/Abs1'
   *  Constant: '<S137>/Constant2'
   *  Sum: '<S137>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S137>/Relational Operator4' incorporates:
   *  Abs: '<S137>/Abs4'
   *  Constant: '<S137>/Constant1'
   *  Sum: '<S137>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S137>/AND' */
  rtb_Is_Absolute_Translation_g = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
    (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S137>/AND2' incorporates:
   *  Logic: '<S137>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Is_Absolute_Translation_g);

  /* SignalConversion: '<S137>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S137>/AND3' */
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
    /* Outputs for IfAction SubSystem: '<S134>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S143>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S145>/While Iterator'
     */
    /* If: '<S134>/If' incorporates:
     *  Constant: '<S143>/Constant'
     *  Constant: '<S144>/Constant'
     *  Constant: '<S144>/Shooter Assembly Offset in Robot'
     *  Constant: '<S144>/Shooter Assembly Offset in Robot1'
     *  Constant: '<S146>/Constant1'
     *  Constant: '<S146>/Constant10'
     *  Constant: '<S146>/Constant2'
     *  Constant: '<S146>/Constant5'
     *  Constant: '<S146>/Constant6'
     *  Constant: '<S146>/Constant7'
     *  Constant: '<S146>/Constant8'
     *  Constant: '<S146>/Constant9'
     *  Constant: '<S147>/Constant1'
     *  Constant: '<S147>/Constant10'
     *  Constant: '<S147>/Constant2'
     *  Constant: '<S147>/Constant5'
     *  Constant: '<S147>/Constant6'
     *  Constant: '<S147>/Constant7'
     *  Constant: '<S147>/Constant8'
     *  Constant: '<S147>/Constant9'
     *  Constant: '<S148>/Constant'
     *  Constant: '<S148>/Constant1'
     *  Constant: '<S148>/Constant2'
     *  Constant: '<S150>/Constant1'
     *  Constant: '<S150>/Constant10'
     *  Constant: '<S150>/Constant2'
     *  Constant: '<S150>/Constant5'
     *  Constant: '<S150>/Constant6'
     *  Constant: '<S150>/Constant7'
     *  Constant: '<S150>/Constant8'
     *  Constant: '<S150>/Constant9'
     *  Constant: '<S153>/Constant'
     *  Constant: '<S153>/Constant1'
     *  Constant: '<S153>/Constant11'
     *  Constant: '<S153>/Constant2'
     *  Constant: '<S153>/Constant3'
     *  Constant: '<S153>/Constant4'
     *  Constant: '<S153>/Constant5'
     *  Constant: '<S153>/Constant6'
     *  Constant: '<S159>/Constant1'
     *  Constant: '<S159>/Constant10'
     *  Constant: '<S159>/Constant2'
     *  Constant: '<S159>/Constant5'
     *  Constant: '<S159>/Constant6'
     *  Constant: '<S159>/Constant7'
     *  Constant: '<S159>/Constant8'
     *  Constant: '<S159>/Constant9'
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant10'
     *  Constant: '<S160>/Constant2'
     *  Constant: '<S160>/Constant5'
     *  Constant: '<S160>/Constant6'
     *  Constant: '<S160>/Constant7'
     *  Constant: '<S160>/Constant8'
     *  Constant: '<S160>/Constant9'
     *  Gain: '<S151>/Gain1'
     *  Gain: '<S158>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S145>/Memory'
     *  Memory: '<S145>/Memory1'
     *  Memory: '<S145>/Memory2'
     *  Memory: '<S145>/Memory3'
     *  Merge: '<S134>/Merge'
     *  Merge: '<S134>/Merge2'
     *  Merge: '<S134>/Merge3'
     *  MinMax: '<S144>/Max'
     *  Product: '<S144>/Divide'
     *  RelationalOperator: '<S148>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S146>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S147>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S148>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S148>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S146>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S153>/Lookup Table Dynamic'
     *  Sum: '<S144>/Add'
     *  Sum: '<S144>/Subtract'
     *  Sum: '<S144>/Subtract1'
     *  Sum: '<S148>/Add'
     *  Switch: '<S148>/Switch'
     *  Switch: '<S148>/Switch1'
     *  Switch: '<S149>/Switch4'
     *  Switch: '<S149>/Switch5'
     *  Switch: '<S149>/Switch6'
     *  Trigonometry: '<S144>/Tanh'
     *  Trigonometry: '<S144>/Tanh1'
     *  UnitDelay: '<S148>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S143>/Iterate_Shot_Target' */
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
      /* Switch: '<S149>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S149>/Switch4' incorporates:
         *  Constant: '<S149>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S149>/Switch4' incorporates:
         *  Constant: '<S149>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S149>/Switch2' */

      /* Switch: '<S149>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S149>/Switch6' incorporates:
         *  Constant: '<S149>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S149>/Switch6' incorporates:
         *  Constant: '<S149>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S149>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S149>/Switch5' incorporates:
         *  Constant: '<S149>/Constant8'
         *  Switch: '<S149>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S149>/Switch4' incorporates:
         *  Constant: '<S149>/Constant9'
         *  Switch: '<S149>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S149>/Switch6' incorporates:
       *  Constant: '<S149>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S143>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S145>/While Iterator'
     */
    Iteration_Number = 1U;
    rtb_Merge1 = 0.0;
    rtb_Saturation_h = 0.0;
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
      /* Switch: '<S154>/Switch' incorporates:
       *  Memory: '<S145>/Memory1'
       *  Memory: '<S145>/Memory2'
       *  Switch: '<S154>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_Switch_hs = rtb_Saturation_h;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Switch_hs = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S154>/Switch' */

      /* Math: '<S152>/Hypot' incorporates:
       *  Sum: '<S152>/Subtract'
       *  Sum: '<S152>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_Switch_hs -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S153>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S153>/Lookup Table Dynamic'
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

      /* Sum: '<S155>/Subtract' incorporates:
       *  Memory: '<S145>/Memory3'
       *  Sum: '<S155>/Subtract1'
       */
      rtb_Merge1 = rtb_TOF - rtb_Init_o;

      /* Sum: '<S155>/Add' incorporates:
       *  Gain: '<S155>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S155>/Product'
       *  Sum: '<S155>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S155>/Add1' incorporates:
       *  Gain: '<S155>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S155>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Switch_hs;

      /* Memory: '<S145>/Memory' */
      rtb_Is_Absolute_Translation_g = rtb_Button_Spinup_Enable;

      /* Update for Memory: '<S145>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S145>/Memory2' */
      rtb_Saturation_h = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S145>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S145>/Memory' incorporates:
       *  Constant: '<S157>/Constant'
       *  Math: '<S156>/Hypot'
       *  RelationalOperator: '<S157>/Compare'
       *  Sum: '<S156>/Subtract'
       *  Sum: '<S156>/Subtract1'
       */
      rtb_Button_Spinup_Enable = (rt_hypotd_snf
        (Robot_Control_B.RB_Desired_Target_X - rtb_Sin4,
         Robot_Control_B.RB_Desired_Target_Y - rtb_Switch_hs) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S143>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S147>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S146>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S148>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S148>/Lookup Table Dynamic1'
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
      /* Merge: '<S134>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S134>/Merge1' */
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

    /* End of Outputs for SubSystem: '<S134>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_oy = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Minus_k_idx_1 = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S134>/Shooter Not Active' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    /* If: '<S134>/If' incorporates:
     *  Constant: '<S142>/Constant'
     *  Constant: '<S142>/Constant1'
     *  Constant: '<S142>/Constant2'
     *  Constant: '<S142>/Constant3'
     *  Merge: '<S134>/Merge'
     *  Merge: '<S134>/Merge1'
     *  Merge: '<S134>/Merge2'
     *  Merge: '<S134>/Merge3'
     *  SignalConversion generated from: '<S142>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* End of Outputs for SubSystem: '<S134>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_oy = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S376>/Add1' incorporates:
   *  Constant: '<S376>/Constant3'
   *  Constant: '<S376>/Constant4'
   *  Math: '<S376>/Math Function'
   *  Sum: '<S375>/Sum'
   *  Sum: '<S376>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_oy - rtb_Minus_k_idx_1) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Gain: '<S379>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle_p;

  /* Abs: '<S358>/Abs1' */
  rtb_Init_o = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S378>/Sum1' incorporates:
   *  Constant: '<S375>/Constant2'
   *  Product: '<S378>/Product'
   *  Sum: '<S378>/Sum'
   *  UnitDelay: '<S378>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Optimized_Module_Angle_p -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S375>/Product' incorporates:
   *  Constant: '<S375>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S377>/Diff' incorporates:
   *  UnitDelay: '<S377>/UD'
   *
   * Block description for '<S377>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S377>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S375>/Saturation' */
  if (rtb_Add_oy > Steering_Heading_Control_D_UL) {
    rtb_Add_oy = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Heading_Control_D_LL) {
    rtb_Add_oy = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S375>/Add' incorporates:
   *  Gain: '<S375>/Gain1'
   *  Saturate: '<S375>/Saturation'
   */
  rtb_Switch_hs = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_oy;

  /* Sum: '<S375>/Subtract' incorporates:
   *  Constant: '<S375>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Switch_hs;

  /* Sum: '<S375>/Sum2' incorporates:
   *  Gain: '<S375>/Gain2'
   *  UnitDelay: '<S375>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p)
    + Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S380>/Switch2' incorporates:
   *  RelationalOperator: '<S380>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Sin4)) {
    /* Sum: '<S375>/Subtract1' incorporates:
     *  Constant: '<S375>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Switch_hs;

    /* Switch: '<S380>/Switch' incorporates:
     *  RelationalOperator: '<S380>/UpperRelop'
     */
    if (!(rtb_Saturation_h < rtb_Sin4)) {
      rtb_Sin4 = rtb_Saturation_h;
    }

    /* End of Switch: '<S380>/Switch' */
  }

  /* End of Switch: '<S380>/Switch2' */

  /* Saturate: '<S375>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Saturation_h = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Saturation_h = Steering_Heading_Control_I_LL;
  } else {
    rtb_Saturation_h = rtb_Sin4;
  }

  /* End of Saturate: '<S375>/Saturation1' */

  /* Sum: '<S375>/Add1' */
  rtb_Add_oy = rtb_Switch_hs + rtb_Saturation_h;

  /* Saturate: '<S375>/Saturation2' */
  if (rtb_Add_oy > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S375>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_oy < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S375>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S375>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_oy;
  }

  /* End of Saturate: '<S375>/Saturation2' */

  /* Abs: '<S358>/Abs' */
  rtb_Sin4 = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S358>/Add dither' */
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

  /* End of Chart: '<S358>/Add dither' */

  /* Switch: '<S358>/Switch' incorporates:
   *  Constant: '<S358>/Constant'
   *  Constant: '<S374>/Constant'
   *  Product: '<S358>/Product'
   *  RelationalOperator: '<S374>/Compare'
   *  Signum: '<S358>/Sign'
   */
  if (rtb_Sin4 > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S358>/Sign' */
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

  /* End of Switch: '<S358>/Switch' */

  /* Signum: '<S357>/Sign2' incorporates:
   *  UnitDelay: '<S357>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S357>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S357>/Product1' incorporates:
   *  Signum: '<S357>/Sign1'
   *  Signum: '<S357>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S357>/Switch' incorporates:
   *  Constant: '<S357>/Constant'
   *  Constant: '<S366>/Constant'
   *  Constant: '<S367>/Constant'
   *  Logic: '<S357>/or'
   *  Product: '<S357>/Product1'
   *  RelationalOperator: '<S366>/Compare'
   *  RelationalOperator: '<S367>/Compare'
   *  UnitDelay: '<S357>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_c3 = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_c3 = 0.0;
  }

  /* End of Switch: '<S357>/Switch' */

  /* Switch: '<S372>/Init' incorporates:
   *  UnitDelay: '<S372>/FixPt Unit Delay1'
   *  UnitDelay: '<S372>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Switch2_c3;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S372>/Init' */

  /* RelationalOperator: '<S368>/Compare' incorporates:
   *  Constant: '<S368>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Switch2_c3 == 0.0);

  /* RelationalOperator: '<S369>/Compare' incorporates:
   *  Constant: '<S369>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Switch2_c3 > 0.0);

  /* Abs: '<S357>/Abs' incorporates:
   *  Sum: '<S357>/Subtract'
   *  UnitDelay: '<S357>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S357>/Switch5' incorporates:
   *  Constant: '<S357>/Constant1'
   *  Switch: '<S357>/Switch1'
   *  UnaryMinus: '<S357>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    /* SignalConversion generated from: '<S357>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S357>/Constant4'
     *  Constant: '<S357>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S357>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S357>/Constant2'
     *  Constant: '<S357>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S357>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S357>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S357>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S357>/Constant10'
     *  Constant: '<S357>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S357>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S357>/Constant7'
     *  Constant: '<S357>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S357>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S357>/Lookup Table Dynamic1'
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

    /* Switch: '<S357>/Switch3' incorporates:
     *  Constant: '<S357>/Constant1'
     *  Constant: '<S357>/Constant3'
     *  UnaryMinus: '<S357>/Unary Minus'
     */
    if (rtb_Button_Shoot_Enable) {
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S357>/Switch3' */
  }

  /* End of Switch: '<S357>/Switch5' */

  /* Product: '<S357>/Product' incorporates:
   *  Switch: '<S357>/Switch1'
   */
  rtb_Switch2_p2 = rtb_Add_oy * rtb_Sin4;

  /* Sum: '<S370>/Sum1' */
  rtb_Switch_hs = rtb_Switch2_c3 - rtb_Init_o;

  /* Switch: '<S371>/Switch2' incorporates:
   *  RelationalOperator: '<S371>/LowerRelop1'
   */
  if (!(rtb_Switch_hs > rtb_Switch2_p2)) {
    /* Switch: '<S357>/Switch2' incorporates:
     *  Constant: '<S357>/Constant1'
     *  Constant: '<S357>/Constant3'
     *  Switch: '<S357>/Switch4'
     *  UnaryMinus: '<S357>/Unary Minus1'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S357>/Switch4' incorporates:
       *  Constant: '<S357>/Constant1'
       */
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S357>/Product2' incorporates:
     *  Switch: '<S357>/Switch2'
     */
    rtb_Switch1_n = rtb_Add_oy * rtb_Sin4;

    /* Switch: '<S371>/Switch' incorporates:
     *  RelationalOperator: '<S371>/UpperRelop'
     */
    if (rtb_Switch_hs < rtb_Switch1_n) {
      rtb_Switch2_p2 = rtb_Switch1_n;
    } else {
      rtb_Switch2_p2 = rtb_Switch_hs;
    }

    /* End of Switch: '<S371>/Switch' */
  }

  /* End of Switch: '<S371>/Switch2' */

  /* Sum: '<S370>/Sum' */
  rtb_Init_o += rtb_Switch2_p2;

  /* Signum: '<S356>/Sign2' incorporates:
   *  UnitDelay: '<S356>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S356>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S356>/Product1' incorporates:
   *  Signum: '<S356>/Sign1'
   *  Signum: '<S356>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S356>/Switch' incorporates:
   *  Constant: '<S356>/Constant'
   *  Constant: '<S359>/Constant'
   *  Constant: '<S360>/Constant'
   *  Logic: '<S356>/or'
   *  Product: '<S356>/Product1'
   *  RelationalOperator: '<S359>/Compare'
   *  RelationalOperator: '<S360>/Compare'
   *  UnitDelay: '<S356>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_c3 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_c3 = 0.0;
  }

  /* End of Switch: '<S356>/Switch' */

  /* Switch: '<S365>/Init' incorporates:
   *  UnitDelay: '<S365>/FixPt Unit Delay1'
   *  UnitDelay: '<S365>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_c3;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S365>/Init' */

  /* RelationalOperator: '<S361>/Compare' incorporates:
   *  Constant: '<S361>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Switch2_c3 == 0.0);

  /* RelationalOperator: '<S362>/Compare' incorporates:
   *  Constant: '<S362>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Switch2_c3 > 0.0);

  /* Abs: '<S356>/Abs' incorporates:
   *  Sum: '<S356>/Subtract'
   *  UnitDelay: '<S356>/Unit Delay'
   */
  rtb_Switch_hs = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                       Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S356>/Switch1' incorporates:
   *  Constant: '<S356>/Constant1'
   *  Switch: '<S356>/Switch3'
   *  Switch: '<S356>/Switch5'
   *  UnaryMinus: '<S356>/Unary Minus'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S356>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S356>/Constant1'
     *  Constant: '<S356>/Constant4'
     *  Constant: '<S356>/Constant6'
     *  UnaryMinus: '<S356>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S356>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S356>/Constant2'
     *  Constant: '<S356>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S356>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S356>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_Switch_hs, &rtb_Minus_n[0], 1U);
    rtb_Switch_hs = rtb_LookupTableDynamic_p;
  } else {
    if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S356>/Switch3' incorporates:
       *  Constant: '<S356>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S356>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S356>/Constant1'
     *  Constant: '<S356>/Constant10'
     *  Constant: '<S356>/Constant8'
     *  UnaryMinus: '<S356>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S356>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S356>/Constant7'
     *  Constant: '<S356>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S356>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S356>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_Switch_hs, &rtb_Minus_n[0], 1U);
    rtb_Switch_hs = rtb_LookupTableDynamic1_g;
  }

  /* End of Switch: '<S356>/Switch1' */

  /* Product: '<S356>/Product' */
  rtb_Sin4 *= rtb_Switch_hs;

  /* Sum: '<S363>/Sum1' */
  rtb_Switch1_n = rtb_Switch2_c3 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S364>/Switch2' incorporates:
   *  RelationalOperator: '<S364>/LowerRelop1'
   */
  if (!(rtb_Switch1_n > rtb_Sin4)) {
    /* Switch: '<S356>/Switch2' incorporates:
     *  Constant: '<S356>/Constant1'
     *  Switch: '<S356>/Switch4'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Button_Shoot_Enable) {
      /* Switch: '<S356>/Switch4' incorporates:
       *  Constant: '<S356>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S356>/Switch4' incorporates:
       *  Constant: '<S356>/Constant3'
       *  UnaryMinus: '<S356>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S356>/Switch2' */

    /* Product: '<S356>/Product2' */
    rtb_Sin4 *= rtb_Switch_hs;

    /* Switch: '<S364>/Switch' incorporates:
     *  RelationalOperator: '<S364>/UpperRelop'
     */
    if (!(rtb_Switch1_n < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1_n;
    }

    /* End of Switch: '<S364>/Switch' */
  }

  /* End of Switch: '<S364>/Switch2' */

  /* Sum: '<S363>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S346>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S346>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S346>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S346>/Switch' */

  /* Fcn: '<S389>/r->x' incorporates:
   *  Fcn: '<S394>/r->x'
   *  Fcn: '<S399>/r->x'
   *  Fcn: '<S404>/r->x'
   */
  rtb_Switch1_n = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S383>/Add' incorporates:
   *  Fcn: '<S389>/r->x'
   *  Fcn: '<S390>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1_n;

  /* Fcn: '<S389>/theta->y' incorporates:
   *  Fcn: '<S394>/theta->y'
   *  Fcn: '<S399>/theta->y'
   *  Fcn: '<S404>/theta->y'
   */
  rtb_Switch_hs = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S383>/Add' incorporates:
   *  Fcn: '<S389>/theta->y'
   *  Fcn: '<S390>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch_hs;

  /* Sum: '<S384>/Add' incorporates:
   *  Fcn: '<S395>/r->x'
   *  Fcn: '<S395>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1_n;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch_hs;

  /* Sum: '<S385>/Add' incorporates:
   *  Fcn: '<S400>/r->x'
   *  Fcn: '<S400>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1_n;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch_hs;

  /* Sum: '<S386>/Add' incorporates:
   *  Fcn: '<S405>/r->x'
   *  Fcn: '<S405>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1_n;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch_hs;

  /* Fcn: '<S403>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S406>/Compare' incorporates:
   *  Constant: '<S406>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S402>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S402>/Switch1' incorporates:
     *  Constant: '<S402>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S402>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S402>/Switch1' */

  /* Fcn: '<S388>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S391>/Compare' incorporates:
   *  Constant: '<S391>/Constant'
   */
  rtb_Button_Spinup_Enable = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S387>/Switch1' */
  if (rtb_Button_Spinup_Enable) {
    /* Switch: '<S387>/Switch1' incorporates:
     *  Constant: '<S387>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S387>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S387>/Switch1' */

  /* Fcn: '<S393>/x->r' */
  rtb_Switch2_c3 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S396>/Compare' incorporates:
   *  Constant: '<S396>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Switch2_c3 == 0.0);

  /* Switch: '<S392>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S392>/Switch1' incorporates:
     *  Constant: '<S392>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S392>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_c3;
  }

  /* End of Switch: '<S392>/Switch1' */

  /* Fcn: '<S398>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S401>/Compare' incorporates:
   *  Constant: '<S401>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S397>/Switch1' */
  if (rtb_Button_Shoot_Enable) {
    /* Switch: '<S397>/Switch1' incorporates:
     *  Constant: '<S397>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S397>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S397>/Switch1' */

  /* Product: '<S382>/Divide' incorporates:
   *  Abs: '<S382>/Abs'
   *  Abs: '<S382>/Abs1'
   *  Abs: '<S382>/Abs2'
   *  Abs: '<S382>/Abs3'
   *  Constant: '<S382>/Constant'
   *  MinMax: '<S382>/Max'
   */
  rtb_Switch2_p2 = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S382>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S402>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S402>/Switch' incorporates:
     *  Fcn: '<S403>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S402>/Switch' */

  /* Trigonometry: '<S336>/Cos4' incorporates:
   *  Switch: '<S325>/Angle_Switch'
   *  Trigonometry: '<S335>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S336>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S334>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S336>/Sin4' incorporates:
   *  Switch: '<S325>/Angle_Switch'
   *  Trigonometry: '<S335>/Sin4'
   */
  rtb_Switch_hs = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S336>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S334>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S336>/Subtract1' incorporates:
   *  Product: '<S336>/Product2'
   *  Product: '<S336>/Product3'
   *  Trigonometry: '<S336>/Cos4'
   *  Trigonometry: '<S336>/Sin4'
   */
  rtb_Switch1_n = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) +
    (rtb_Switch_hs * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S336>/Subtract' incorporates:
   *  Product: '<S336>/Product'
   *  Product: '<S336>/Product1'
   *  Trigonometry: '<S336>/Cos4'
   *  Trigonometry: '<S336>/Sin4'
   */
  rtb_Init = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) - (rtb_Switch_hs
    * rtb_Optimized_Module_Angle);

  /* Math: '<S336>/Hypot' */
  rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Init, rtb_Switch1_n);

  /* Switch: '<S336>/Switch' incorporates:
   *  Constant: '<S336>/Constant'
   *  Constant: '<S336>/Constant1'
   *  Constant: '<S337>/Constant'
   *  Product: '<S336>/Divide'
   *  Product: '<S336>/Divide1'
   *  RelationalOperator: '<S337>/Compare'
   *  Switch: '<S336>/Switch1'
   */
  if (rtb_Minus_k_idx_0 > 1.0E-6) {
    rtb_Switch2_c3 = rtb_Switch1_n / rtb_Minus_k_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Minus_k_idx_0;
  } else {
    rtb_Switch2_c3 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S336>/Switch' */

  /* Switch: '<S325>/Speed_Switch' incorporates:
   *  Abs: '<S325>/Abs'
   *  Constant: '<S333>/Constant'
   *  RelationalOperator: '<S333>/Compare'
   *  Switch: '<S325>/Angle_Switch'
   *  Trigonometry: '<S335>/Atan1'
   *  Trigonometry: '<S336>/Atan1'
   *  UnaryMinus: '<S325>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_c3, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S335>/Subtract1' incorporates:
     *  Product: '<S335>/Product2'
     *  Product: '<S335>/Product3'
     *  UnaryMinus: '<S325>/Unary Minus'
     */
    rtb_Switch1_n = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_Switch_hs * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S335>/Subtract' incorporates:
     *  Product: '<S335>/Product'
     *  Product: '<S335>/Product1'
     */
    rtb_Init = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_Switch_hs * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S335>/Hypot' */
    rtb_Switch_hs = rt_hypotd_snf(rtb_Init, rtb_Switch1_n);

    /* Switch: '<S335>/Switch1' incorporates:
     *  Constant: '<S335>/Constant'
     *  Constant: '<S335>/Constant1'
     *  Constant: '<S338>/Constant'
     *  Product: '<S335>/Divide'
     *  Product: '<S335>/Divide1'
     *  RelationalOperator: '<S338>/Compare'
     *  Switch: '<S335>/Switch'
     */
    if (rtb_Switch_hs > 1.0E-6) {
      rtb_Init /= rtb_Switch_hs;
      rtb_Switch_hs = rtb_Switch1_n / rtb_Switch_hs;
    } else {
      rtb_Init = 1.0;
      rtb_Switch_hs = 0.0;
    }

    /* End of Switch: '<S335>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch_hs, rtb_Init);
  } else {
    rtb_Add_oy = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S328>/Product2' incorporates:
   *  Constant: '<S328>/Constant'
   *  Switch: '<S325>/Speed_Switch'
   */
  rtb_Switch2_c3 = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S323>/Sign' */
  if (rtIsNaN(rtb_Switch2_c3)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_c3 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_c3 > 0.0);
  }

  /* Signum: '<S323>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S326>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S327>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S258>/Product' incorporates:
   *  Abs: '<S323>/Abs'
   *  Abs: '<S326>/Abs'
   *  Constant: '<S329>/Constant'
   *  Constant: '<S339>/Constant3'
   *  Constant: '<S339>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S323>/OR'
   *  Lookup_n-D: '<S326>/1-D Lookup Table'
   *  Math: '<S339>/Math Function'
   *  RelationalOperator: '<S323>/Equal1'
   *  RelationalOperator: '<S329>/Compare'
   *  Signum: '<S323>/Sign'
   *  Signum: '<S323>/Sign1'
   *  Sum: '<S326>/Add'
   *  Sum: '<S339>/Add1'
   *  Sum: '<S339>/Add2'
   */
  rtb_Switch2_c3 = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_c3) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S324>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Init = rtb_Switch2_c3 - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S331>/Sum1' incorporates:
   *  Constant: '<S324>/Constant2'
   *  Product: '<S331>/Product'
   *  Sum: '<S331>/Sum'
   *  UnitDelay: '<S331>/Unit Delay1'
   */
  rtb_Switch_hs = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                   Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S324>/Product' incorporates:
   *  Constant: '<S324>/Constant3'
   */
  rtb_Switch1_n = rtb_Switch_hs * Drive_Motor_Control_D;

  /* Sum: '<S330>/Diff' incorporates:
   *  UnitDelay: '<S330>/UD'
   *
   * Block description for '<S330>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S330>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch1_n - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S324>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S324>/Add' incorporates:
   *  Gain: '<S324>/Gain'
   *  Gain: '<S324>/Gain1'
   *  Saturate: '<S324>/Saturation'
   */
  rtb_Minus_k_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_c3) +
                       (Drive_Motor_Control_P * rtb_Init)) + rtb_Add_oy;

  /* Saturate: '<S324>/Saturation2' incorporates:
   *  Sum: '<S324>/Add1'
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

  /* End of Saturate: '<S324>/Saturation2' */

  /* Switch: '<S387>/Switch' */
  if (!rtb_Button_Spinup_Enable) {
    /* Switch: '<S387>/Switch' incorporates:
     *  Fcn: '<S388>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S387>/Switch' */

  /* Trigonometry: '<S273>/Cos4' incorporates:
   *  Switch: '<S262>/Angle_Switch'
   *  Trigonometry: '<S272>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S273>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S271>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S273>/Sin4' incorporates:
   *  Switch: '<S262>/Angle_Switch'
   *  Trigonometry: '<S272>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S273>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S271>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S273>/Subtract1' incorporates:
   *  Product: '<S273>/Product2'
   *  Product: '<S273>/Product3'
   *  Trigonometry: '<S273>/Cos4'
   *  Trigonometry: '<S273>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S273>/Subtract' incorporates:
   *  Product: '<S273>/Product'
   *  Product: '<S273>/Product1'
   *  Trigonometry: '<S273>/Cos4'
   *  Trigonometry: '<S273>/Sin4'
   */
  rtb_Init = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S273>/Hypot' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Init, rtb_Minus_k_idx_0);

  /* Switch: '<S273>/Switch' incorporates:
   *  Constant: '<S273>/Constant'
   *  Constant: '<S273>/Constant1'
   *  Constant: '<S274>/Constant'
   *  Product: '<S273>/Divide'
   *  Product: '<S273>/Divide1'
   *  RelationalOperator: '<S274>/Compare'
   *  Switch: '<S273>/Switch1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
    rtb_Switch2_c3 = rtb_Minus_k_idx_0 / rtb_MatrixConcatenate_b_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Switch2_c3 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S273>/Switch' */

  /* Product: '<S382>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S262>/Speed_Switch' incorporates:
   *  Abs: '<S262>/Abs'
   *  Constant: '<S270>/Constant'
   *  RelationalOperator: '<S270>/Compare'
   *  Switch: '<S262>/Angle_Switch'
   *  Trigonometry: '<S272>/Atan1'
   *  Trigonometry: '<S273>/Atan1'
   *  UnaryMinus: '<S262>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_c3, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S272>/Subtract1' incorporates:
     *  Product: '<S272>/Product2'
     *  Product: '<S272>/Product3'
     *  UnaryMinus: '<S262>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S272>/Subtract' incorporates:
     *  Product: '<S272>/Product'
     *  Product: '<S272>/Product1'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Cos5) - (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Sin5);

    /* Math: '<S272>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Minus_k_idx_0);

    /* Switch: '<S272>/Switch1' incorporates:
     *  Constant: '<S272>/Constant'
     *  Constant: '<S272>/Constant1'
     *  Constant: '<S275>/Constant'
     *  Product: '<S272>/Divide'
     *  Product: '<S272>/Divide1'
     *  RelationalOperator: '<S275>/Compare'
     *  Switch: '<S272>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Init;
      rtb_Minus_k_idx_0 /= rtb_Init;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S272>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_0,
      rtb_MatrixConcatenate_b_idx_0);
  } else {
    rtb_Add_oy = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S265>/Product2' incorporates:
   *  Constant: '<S265>/Constant'
   *  Switch: '<S262>/Speed_Switch'
   */
  rtb_Switch2_c3 = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S260>/Sign' */
  if (rtIsNaN(rtb_Switch2_c3)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_c3 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_c3 > 0.0);
  }

  /* Signum: '<S260>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S263>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S264>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S255>/Product' incorporates:
   *  Abs: '<S260>/Abs'
   *  Abs: '<S263>/Abs'
   *  Constant: '<S266>/Constant'
   *  Constant: '<S276>/Constant3'
   *  Constant: '<S276>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
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
  rtb_Switch2_c3 = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_c3) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j,
                  1U);

  /* Sum: '<S261>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_c3 -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S268>/Sum1' incorporates:
   *  Constant: '<S261>/Constant2'
   *  Product: '<S268>/Product'
   *  Sum: '<S268>/Sum'
   *  UnitDelay: '<S268>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_MatrixConcatenate_b_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_f) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S261>/Product' incorporates:
   *  Constant: '<S261>/Constant3'
   */
  rtb_Init = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

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
  rtb_Add_oy = rtb_Init - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S261>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S261>/Add' incorporates:
   *  Gain: '<S261>/Gain'
   *  Gain: '<S261>/Gain1'
   *  Saturate: '<S261>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_c3) +
    (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_oy;

  /* Saturate: '<S261>/Saturation2' incorporates:
   *  Sum: '<S261>/Add1'
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

  /* End of Saturate: '<S261>/Saturation2' */

  /* Sum: '<S277>/Add1' incorporates:
   *  Constant: '<S277>/Constant3'
   *  Constant: '<S277>/Constant4'
   *  Math: '<S277>/Math Function'
   *  Sum: '<S277>/Add2'
   */
  rtb_Switch2_c3 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S279>/Sum1' incorporates:
   *  Constant: '<S264>/Constant2'
   *  Product: '<S279>/Product'
   *  Sum: '<S279>/Sum'
   *  UnitDelay: '<S279>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((rtb_Switch2_c3 -
    Robot_Control_DW.UnitDelay1_DSTATE_b) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S264>/Product' incorporates:
   *  Constant: '<S264>/Constant3'
   */
  rtb_Switch2_bq = rtb_MatrixConcatenate_b_idx_0 * Steering_Motor_Control_D;

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
  rtb_Add_oy = rtb_Switch2_bq - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S264>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S264>/Add' incorporates:
   *  Gain: '<S264>/Gain1'
   *  Saturate: '<S264>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P * rtb_Switch2_c3) +
    rtb_Add_oy;

  /* Sum: '<S264>/Subtract' incorporates:
   *  Constant: '<S264>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S264>/Sum2' incorporates:
   *  Gain: '<S264>/Gain2'
   *  UnitDelay: '<S264>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Switch2_c3) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S280>/Switch2' incorporates:
   *  Constant: '<S264>/Constant'
   *  RelationalOperator: '<S280>/LowerRelop1'
   *  Sum: '<S264>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S264>/Constant1'
     *  RelationalOperator: '<S280>/UpperRelop'
     *  Sum: '<S264>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S280>/Switch' */
  }

  /* End of Switch: '<S280>/Switch2' */

  /* Saturate: '<S264>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S264>/Saturation1' */

  /* Sum: '<S264>/Add1' */
  rtb_Add_oy = rtb_MatrixConcatenate_idx_0 + rtb_Sum2_e;

  /* Saturate: '<S264>/Saturation2' */
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

  /* End of Saturate: '<S264>/Saturation2' */

  /* Switch: '<S392>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S392>/Switch' incorporates:
     *  Fcn: '<S393>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S392>/Switch' */

  /* Trigonometry: '<S294>/Cos4' incorporates:
   *  Switch: '<S283>/Angle_Switch'
   *  Trigonometry: '<S293>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S294>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S292>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S294>/Sin4' incorporates:
   *  Switch: '<S283>/Angle_Switch'
   *  Trigonometry: '<S293>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S294>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S292>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S294>/Subtract1' incorporates:
   *  Product: '<S294>/Product2'
   *  Product: '<S294>/Product3'
   *  Trigonometry: '<S294>/Cos4'
   *  Trigonometry: '<S294>/Sin4'
   */
  rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S294>/Subtract' incorporates:
   *  Product: '<S294>/Product'
   *  Product: '<S294>/Product1'
   *  Trigonometry: '<S294>/Cos4'
   *  Trigonometry: '<S294>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S294>/Hypot' */
  rtb_Hypot_bl = rt_hypotd_snf(rtb_Subtract1_la, rtb_MatrixConcatenate_idx_0);

  /* Switch: '<S294>/Switch' incorporates:
   *  Constant: '<S294>/Constant'
   *  Constant: '<S294>/Constant1'
   *  Constant: '<S295>/Constant'
   *  Product: '<S294>/Divide'
   *  Product: '<S294>/Divide1'
   *  RelationalOperator: '<S295>/Compare'
   *  Switch: '<S294>/Switch1'
   */
  if (rtb_Hypot_bl > 1.0E-6) {
    rtb_Switch2_c3 = rtb_MatrixConcatenate_idx_0 / rtb_Hypot_bl;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_bl;
  } else {
    rtb_Switch2_c3 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S294>/Switch' */

  /* Product: '<S382>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S283>/Speed_Switch' incorporates:
   *  Abs: '<S283>/Abs'
   *  Constant: '<S291>/Constant'
   *  RelationalOperator: '<S291>/Compare'
   *  Switch: '<S283>/Angle_Switch'
   *  Trigonometry: '<S293>/Atan1'
   *  Trigonometry: '<S294>/Atan1'
   *  UnaryMinus: '<S283>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_c3, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S293>/Subtract1' incorporates:
     *  Product: '<S293>/Product2'
     *  Product: '<S293>/Product3'
     *  UnaryMinus: '<S283>/Unary Minus'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_m) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S293>/Subtract' incorporates:
     *  Product: '<S293>/Product'
     *  Product: '<S293>/Product1'
     */
    rtb_Hypot_bl = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S293>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_bl, rtb_MatrixConcatenate_idx_0);

    /* Switch: '<S293>/Switch1' incorporates:
     *  Constant: '<S293>/Constant'
     *  Constant: '<S293>/Constant1'
     *  Constant: '<S296>/Constant'
     *  Product: '<S293>/Divide'
     *  Product: '<S293>/Divide1'
     *  RelationalOperator: '<S296>/Compare'
     *  Switch: '<S293>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_bl /= rtb_Subtract1_la;
      rtb_MatrixConcatenate_idx_0 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_bl = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S293>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0, rtb_Hypot_bl);
  } else {
    rtb_Add_oy = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S286>/Product2' incorporates:
   *  Constant: '<S286>/Constant'
   *  Switch: '<S283>/Speed_Switch'
   */
  rtb_Switch2_c3 = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S281>/Sign' */
  if (rtIsNaN(rtb_Switch2_c3)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_c3 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_c3 > 0.0);
  }

  /* Signum: '<S281>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S284>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S285>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S256>/Product' incorporates:
   *  Abs: '<S281>/Abs'
   *  Abs: '<S284>/Abs'
   *  Constant: '<S287>/Constant'
   *  Constant: '<S297>/Constant3'
   *  Constant: '<S297>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
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
  rtb_Switch2_c3 = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_c3) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_gs,
                  1U);

  /* Sum: '<S282>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_bl = rtb_Switch2_c3 - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S289>/Sum1' incorporates:
   *  Constant: '<S282>/Constant2'
   *  Product: '<S289>/Product'
   *  Sum: '<S289>/Sum'
   *  UnitDelay: '<S289>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Hypot_bl -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S282>/Product' incorporates:
   *  Constant: '<S282>/Constant3'
   */
  rtb_Subtract1_la = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

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
  rtb_Add_oy = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S282>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S282>/Add' incorporates:
   *  Gain: '<S282>/Gain'
   *  Gain: '<S282>/Gain1'
   *  Saturate: '<S282>/Saturation'
   */
  rtb_Hypot_bl = ((Drive_Motor_Control_FF * rtb_Switch2_c3) +
                  (Drive_Motor_Control_P * rtb_Hypot_bl)) + rtb_Add_oy;

  /* Saturate: '<S282>/Saturation2' incorporates:
   *  Sum: '<S282>/Add1'
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

  /* End of Saturate: '<S282>/Saturation2' */

  /* Sum: '<S298>/Add1' incorporates:
   *  Constant: '<S298>/Constant3'
   *  Constant: '<S298>/Constant4'
   *  Math: '<S298>/Math Function'
   *  Sum: '<S298>/Add2'
   */
  rtb_Switch2_c3 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S300>/Sum1' incorporates:
   *  Constant: '<S285>/Constant2'
   *  Product: '<S300>/Product'
   *  Sum: '<S300>/Sum'
   *  UnitDelay: '<S300>/Unit Delay1'
   */
  rtb_Hypot_bl = ((rtb_Switch2_c3 - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S285>/Product' incorporates:
   *  Constant: '<S285>/Constant3'
   */
  rtb_Switch2_fl = rtb_Hypot_bl * Steering_Motor_Control_D;

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
  rtb_Add_oy = rtb_Switch2_fl - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S285>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S285>/Add' incorporates:
   *  Gain: '<S285>/Gain1'
   *  Saturate: '<S285>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_c3) + rtb_Add_oy;

  /* Sum: '<S285>/Subtract' incorporates:
   *  Constant: '<S285>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S285>/Sum2' incorporates:
   *  Gain: '<S285>/Gain2'
   *  UnitDelay: '<S285>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_Switch2_c3) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S301>/Switch2' incorporates:
   *  Constant: '<S285>/Constant'
   *  RelationalOperator: '<S301>/LowerRelop1'
   *  Sum: '<S285>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S301>/Switch' incorporates:
     *  Constant: '<S285>/Constant1'
     *  RelationalOperator: '<S301>/UpperRelop'
     *  Sum: '<S285>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S301>/Switch' */
  }

  /* End of Switch: '<S301>/Switch2' */

  /* Saturate: '<S285>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S285>/Saturation1' */

  /* Sum: '<S285>/Add1' */
  rtb_Add_oy = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S285>/Saturation2' */
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

  /* End of Saturate: '<S285>/Saturation2' */

  /* Switch: '<S397>/Switch' */
  if (!rtb_Button_Shoot_Enable) {
    /* Switch: '<S397>/Switch' incorporates:
     *  Fcn: '<S398>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S397>/Switch' */

  /* Trigonometry: '<S315>/Cos4' incorporates:
   *  Switch: '<S304>/Angle_Switch'
   *  Trigonometry: '<S314>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S315>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S313>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S315>/Sin4' incorporates:
   *  Switch: '<S304>/Angle_Switch'
   *  Trigonometry: '<S314>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S315>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S313>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S315>/Subtract1' incorporates:
   *  Product: '<S315>/Product2'
   *  Product: '<S315>/Product3'
   *  Trigonometry: '<S315>/Cos4'
   *  Trigonometry: '<S315>/Sin4'
   */
  rtb_Switch2_c3 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S315>/Subtract' incorporates:
   *  Product: '<S315>/Product'
   *  Product: '<S315>/Product1'
   *  Trigonometry: '<S315>/Cos4'
   *  Trigonometry: '<S315>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S315>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_c3);

  /* Switch: '<S315>/Switch' incorporates:
   *  Constant: '<S315>/Constant'
   *  Constant: '<S315>/Constant1'
   *  Constant: '<S316>/Constant'
   *  Product: '<S315>/Divide'
   *  Product: '<S315>/Divide1'
   *  RelationalOperator: '<S316>/Compare'
   *  Switch: '<S315>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Switch2_c3 /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_c3 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S315>/Switch' */

  /* Product: '<S382>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S304>/Speed_Switch' incorporates:
   *  Abs: '<S304>/Abs'
   *  Constant: '<S312>/Constant'
   *  RelationalOperator: '<S312>/Compare'
   *  Switch: '<S304>/Angle_Switch'
   *  Trigonometry: '<S314>/Atan1'
   *  Trigonometry: '<S315>/Atan1'
   *  UnaryMinus: '<S304>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_c3, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S314>/Subtract1' incorporates:
     *  Product: '<S314>/Product2'
     *  Product: '<S314>/Product3'
     *  UnaryMinus: '<S304>/Unary Minus'
     */
    rtb_Switch2_c3 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S314>/Subtract' incorporates:
     *  Product: '<S314>/Product'
     *  Product: '<S314>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S314>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_c3);

    /* Switch: '<S314>/Switch1' incorporates:
     *  Constant: '<S314>/Constant'
     *  Constant: '<S314>/Constant1'
     *  Constant: '<S317>/Constant'
     *  Product: '<S314>/Divide'
     *  Product: '<S314>/Divide1'
     *  RelationalOperator: '<S317>/Compare'
     *  Switch: '<S314>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_Switch2_c3 /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Switch2_c3 = 0.0;
    }

    /* End of Switch: '<S314>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Switch2_c3,
      rtb_uDLookupTable);
  } else {
    rtb_Add_oy = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S307>/Product2' incorporates:
   *  Constant: '<S307>/Constant'
   *  Switch: '<S304>/Speed_Switch'
   */
  rtb_Switch2_p2 = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S302>/Sign' */
  if (rtIsNaN(rtb_Switch2_p2)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_p2 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_p2 > 0.0);
  }

  /* Signum: '<S302>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S305>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S306>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S257>/Product' incorporates:
   *  Abs: '<S302>/Abs'
   *  Abs: '<S305>/Abs'
   *  Constant: '<S308>/Constant'
   *  Constant: '<S318>/Constant3'
   *  Constant: '<S318>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
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
  rtb_Switch2_p2 = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p2) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Sum: '<S303>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_c3 = rtb_Switch2_p2 - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S310>/Sum1' incorporates:
   *  Constant: '<S303>/Constant2'
   *  Product: '<S310>/Product'
   *  Sum: '<S310>/Sum'
   *  UnitDelay: '<S310>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_Switch2_c3 - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S303>/Product' incorporates:
   *  Constant: '<S303>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

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
  rtb_Add_oy = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S303>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S303>/Add' incorporates:
   *  Gain: '<S303>/Gain'
   *  Gain: '<S303>/Gain1'
   *  Saturate: '<S303>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_p2) +
                    (Drive_Motor_Control_P * rtb_Switch2_c3)) + rtb_Add_oy;

  /* Saturate: '<S303>/Saturation2' incorporates:
   *  Sum: '<S303>/Add1'
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

  /* End of Saturate: '<S303>/Saturation2' */

  /* Sum: '<S319>/Add1' incorporates:
   *  Constant: '<S319>/Constant3'
   *  Constant: '<S319>/Constant4'
   *  Math: '<S319>/Math Function'
   *  Sum: '<S319>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S321>/Sum1' incorporates:
   *  Constant: '<S306>/Constant2'
   *  Product: '<S321>/Product'
   *  Sum: '<S321>/Sum'
   *  UnitDelay: '<S321>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S306>/Product' incorporates:
   *  Constant: '<S306>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

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
  rtb_Add_oy = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S306>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S306>/Add' incorporates:
   *  Gain: '<S306>/Gain1'
   *  Saturate: '<S306>/Saturation'
   */
  rtb_Add_ec = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_oy;

  /* Sum: '<S306>/Subtract' incorporates:
   *  Constant: '<S306>/Constant'
   */
  rtb_Switch2_c3 = 1.0 - rtb_Add_ec;

  /* Sum: '<S306>/Sum2' incorporates:
   *  Gain: '<S306>/Gain2'
   *  UnitDelay: '<S306>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S322>/Switch2' incorporates:
   *  Constant: '<S306>/Constant'
   *  RelationalOperator: '<S322>/LowerRelop1'
   *  Sum: '<S306>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_ec))) {
    /* Sum: '<S306>/Subtract1' incorporates:
     *  Constant: '<S306>/Constant1'
     */
    rtb_Switch2_c3 = -1.0 - rtb_Add_ec;

    /* Switch: '<S322>/Switch' incorporates:
     *  Constant: '<S306>/Constant1'
     *  RelationalOperator: '<S322>/UpperRelop'
     *  Sum: '<S306>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_ec))) {
      rtb_Switch2_c3 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S322>/Switch' */
  }

  /* End of Switch: '<S322>/Switch2' */

  /* Saturate: '<S306>/Saturation1' */
  if (rtb_Switch2_c3 > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_c3 < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Switch2_c3;
  }

  /* End of Saturate: '<S306>/Saturation1' */

  /* Sum: '<S306>/Add1' */
  rtb_Add_oy = rtb_Add_ec + rtb_Integral_ga;

  /* Saturate: '<S306>/Saturation2' */
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

  /* End of Saturate: '<S306>/Saturation2' */

  /* Sum: '<S340>/Add1' incorporates:
   *  Constant: '<S340>/Constant3'
   *  Constant: '<S340>/Constant4'
   *  Math: '<S340>/Math Function'
   *  Sum: '<S340>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S342>/Sum1' incorporates:
   *  Constant: '<S327>/Constant2'
   *  Product: '<S342>/Product'
   *  Sum: '<S342>/Sum'
   *  UnitDelay: '<S342>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S327>/Product' incorporates:
   *  Constant: '<S327>/Constant3'
   */
  rtb_Add_ec = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S341>/Diff' incorporates:
   *  UnitDelay: '<S341>/UD'
   *
   * Block description for '<S341>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S341>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Add_ec - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S327>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S327>/Add' incorporates:
   *  Gain: '<S327>/Gain1'
   *  Saturate: '<S327>/Saturation'
   */
  rtb_Add_os = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_oy;

  /* Sum: '<S327>/Subtract' incorporates:
   *  Constant: '<S327>/Constant'
   */
  rtb_Switch2_c3 = 1.0 - rtb_Add_os;

  /* Sum: '<S327>/Sum2' incorporates:
   *  Gain: '<S327>/Gain2'
   *  UnitDelay: '<S327>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S343>/Switch2' incorporates:
   *  Constant: '<S327>/Constant'
   *  RelationalOperator: '<S343>/LowerRelop1'
   *  Sum: '<S327>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_os))) {
    /* Sum: '<S327>/Subtract1' incorporates:
     *  Constant: '<S327>/Constant1'
     */
    rtb_Switch2_c3 = -1.0 - rtb_Add_os;

    /* Switch: '<S343>/Switch' incorporates:
     *  Constant: '<S327>/Constant1'
     *  RelationalOperator: '<S343>/UpperRelop'
     *  Sum: '<S327>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_os))) {
      rtb_Switch2_c3 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S343>/Switch' */
  }

  /* End of Switch: '<S343>/Switch2' */

  /* Saturate: '<S327>/Saturation1' */
  if (rtb_Switch2_c3 > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_c3 < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Switch2_c3;
  }

  /* End of Saturate: '<S327>/Saturation1' */

  /* Sum: '<S327>/Add1' */
  rtb_Add_oy = rtb_Add_os + rtb_Integral_bj;

  /* Saturate: '<S327>/Saturation2' */
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

  /* End of Saturate: '<S327>/Saturation2' */

  /* Sum: '<S190>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S140>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S192>/Sum1' incorporates:
   *  Constant: '<S190>/Constant2'
   *  Product: '<S192>/Product'
   *  Sum: '<S190>/Sum'
   *  Sum: '<S192>/Sum'
   *  UnitDelay: '<S192>/Unit Delay1'
   */
  rtb_Add_os = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S190>/Product' incorporates:
   *  Constant: '<S190>/Constant3'
   */
  rtb_Product_lo = rtb_Add_os * 0.0;

  /* Sum: '<S191>/Diff' incorporates:
   *  UnitDelay: '<S191>/UD'
   *
   * Block description for '<S191>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S191>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S190>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S190>/Add' incorporates:
   *  Gain: '<S190>/Gain'
   *  Gain: '<S190>/Gain1'
   *  Saturate: '<S190>/Saturation'
   *  Sum: '<S190>/Sum'
   */
  rtb_Switch2_p2 = ((Rebuilt_Transfer_Motor_Gain_FF *
                     Robot_Control_B.RB_Desired_Transfer_Speed) +
                    (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) +
    rtb_Add_oy;

  /* Logic: '<S140>/Logical Operator1' incorporates:
   *  Constant: '<S189>/Constant'
   *  RelationalOperator: '<S189>/Compare'
   */
  rtb_Button_Shoot_Enable = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S140>/Switch1' incorporates:
   *  Abs: '<S140>/Abs'
   *  Constant: '<S140>/Constant1'
   *  Constant: '<S140>/Constant2'
   *  Logic: '<S140>/Logical Operator'
   *  Logic: '<S140>/Logical Operator1'
   *  RelationalOperator: '<S140>/LessThan'
   *  UnitDelay: '<S140>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Button_Shoot_Enable) {
    rtb_Button_Spinup_Enable = true;
  } else {
    rtb_Button_Spinup_Enable = (rtb_Button_Shoot_Enable &&
      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S140>/Switch1' */

  /* Switch: '<S190>/Switch' incorporates:
   *  Constant: '<S190>/Constant4'
   */
  if (rtb_Button_Spinup_Enable) {
    /* Sum: '<S190>/Sum2' incorporates:
     *  Gain: '<S190>/Gain2'
     *  Sum: '<S190>/Sum'
     *  UnitDelay: '<S190>/Unit Delay'
     */
    rtb_Switch2_c3 = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S190>/Subtract' incorporates:
     *  Constant: '<S190>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Switch2_p2;

    /* Switch: '<S193>/Switch2' incorporates:
     *  Constant: '<S190>/Constant'
     *  RelationalOperator: '<S193>/LowerRelop1'
     *  Sum: '<S190>/Subtract'
     */
    if (!(rtb_Switch2_c3 > (1.0 - rtb_Switch2_p2))) {
      /* Sum: '<S190>/Subtract1' incorporates:
       *  Constant: '<S190>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Switch2_p2;

      /* Switch: '<S193>/Switch' incorporates:
       *  Constant: '<S190>/Constant1'
       *  RelationalOperator: '<S193>/UpperRelop'
       *  Sum: '<S190>/Subtract1'
       */
      if (!(rtb_Switch2_c3 < (-1.0 - rtb_Switch2_p2))) {
        rtb_Integral_d = rtb_Switch2_c3;
      }

      /* End of Switch: '<S193>/Switch' */
    }

    /* End of Switch: '<S193>/Switch2' */

    /* Saturate: '<S190>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S190>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S190>/Switch' */

  /* Switch: '<S140>/Switch2' incorporates:
   *  Logic: '<S140>/Logical Operator1'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S190>/Add1' */
    rtb_Add_oy = rtb_Switch2_p2 + rtb_Integral_d;

    /* Saturate: '<S190>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S140>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S140>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S140>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S190>/Saturation2' */
  } else {
    /* Switch: '<S140>/Switch2' incorporates:
     *  Constant: '<S140>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S140>/Switch2' */

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
    rtb_Switch2_p2 = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;
    rtb_Switch2_p2 = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch1' */

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

  /* Switch: '<S132>/Init' incorporates:
   *  UnitDelay: '<S132>/FixPt Unit Delay1'
   *  UnitDelay: '<S132>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Switch2_c3 = rtb_Switch2_p2;
  } else {
    rtb_Switch2_c3 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S132>/Init' */

  /* Sum: '<S130>/Sum1' */
  rtb_Switch2_p2 -= rtb_Switch2_c3;

  /* Switch: '<S131>/Switch2' incorporates:
   *  Constant: '<S129>/Constant1'
   *  Constant: '<S129>/Constant3'
   *  RelationalOperator: '<S131>/LowerRelop1'
   *  RelationalOperator: '<S131>/UpperRelop'
   *  Switch: '<S131>/Switch'
   */
  if (rtb_Switch2_p2 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch2_p2 < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S131>/Switch' incorporates:
     *  Constant: '<S129>/Constant1'
     */
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S131>/Switch2' */

  /* Sum: '<S130>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Switch2_p2 + rtb_Switch2_c3;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Logic: '<S6>/Logical Operator'
   */
  if (rtb_Intake_Arm_Cycle || rtb_LogicalOperator1_n) {
    rtb_Switch2_p2 = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Switch2_p2 = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S58>/Logical Operator1' incorporates:
   *  Constant: '<S70>/Constant'
   *  RelationalOperator: '<S70>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Switch2_p2 == 0.0);

  /* Sum: '<S71>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S58>/Subtract'
   */
  rtb_Error_n = rtb_Switch2_p2 - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S73>/Sum1' incorporates:
   *  Constant: '<S71>/Constant2'
   *  Product: '<S73>/Product'
   *  Sum: '<S71>/Sum'
   *  Sum: '<S73>/Sum'
   *  UnitDelay: '<S73>/Unit Delay1'
   */
  rtb_Sum1_fh = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S71>/Product' incorporates:
   *  Constant: '<S71>/Constant3'
   */
  rtb_Product_hm = rtb_Sum1_fh * 0.0;

  /* Sum: '<S72>/Diff' incorporates:
   *  UnitDelay: '<S72>/UD'
   *
   * Block description for '<S72>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S72>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_hm - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S71>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S71>/Add' incorporates:
   *  Gain: '<S71>/Gain'
   *  Gain: '<S71>/Gain1'
   *  Saturate: '<S71>/Saturation'
   *  Sum: '<S71>/Sum'
   */
  rtb_Switch2_c3 = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Switch2_p2) +
                    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_oy;

  /* Switch: '<S58>/Switch1' incorporates:
   *  Abs: '<S58>/Abs'
   *  Constant: '<S58>/Constant1'
   *  Constant: '<S58>/Constant2'
   *  Logic: '<S58>/Logical Operator'
   *  Logic: '<S58>/Logical Operator1'
   *  RelationalOperator: '<S58>/LessThan'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Button_Shoot_Enable = true;
  } else {
    rtb_Button_Shoot_Enable = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_nh));
  }

  /* End of Switch: '<S58>/Switch1' */

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S71>/Constant4'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S71>/Sum2' incorporates:
     *  Gain: '<S71>/Gain2'
     *  Sum: '<S71>/Sum'
     *  UnitDelay: '<S71>/Unit Delay'
     */
    rtb_Switch2_p2 = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S71>/Subtract' incorporates:
     *  Constant: '<S71>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Switch2_c3;

    /* Switch: '<S74>/Switch2' incorporates:
     *  Constant: '<S71>/Constant'
     *  RelationalOperator: '<S74>/LowerRelop1'
     *  Sum: '<S71>/Subtract'
     */
    if (!(rtb_Switch2_p2 > (1.0 - rtb_Switch2_c3))) {
      /* Sum: '<S71>/Subtract1' incorporates:
       *  Constant: '<S71>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Switch2_c3;

      /* Switch: '<S74>/Switch' incorporates:
       *  Constant: '<S71>/Constant1'
       *  RelationalOperator: '<S74>/UpperRelop'
       *  Sum: '<S71>/Subtract1'
       */
      if (!(rtb_Switch2_p2 < (-1.0 - rtb_Switch2_c3))) {
        rtb_Error_n = rtb_Switch2_p2;
      }

      /* End of Switch: '<S74>/Switch' */
    }

    /* End of Switch: '<S74>/Switch2' */

    /* Saturate: '<S71>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Error_n = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Error_n = -0.1;
    }

    /* End of Saturate: '<S71>/Saturation1' */
  } else {
    rtb_Error_n = 0.0;
  }

  /* End of Switch: '<S71>/Switch' */

  /* Switch: '<S58>/Switch2' incorporates:
   *  Logic: '<S58>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S71>/Add1' */
    rtb_Add_oy = rtb_Switch2_c3 + rtb_Error_n;

    /* Saturate: '<S71>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S58>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S58>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S58>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S71>/Saturation2' */
  } else {
    /* Switch: '<S58>/Switch2' incorporates:
     *  Constant: '<S58>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S58>/Switch2' */

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

  /* Sum: '<S53>/Add1' incorporates:
   *  Constant: '<S53>/Constant3'
   *  Constant: '<S53>/Constant4'
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Math: '<S53>/Math Function'
   *  Sum: '<S53>/Add2'
   */
  Robot_Control_B.RB_Intake_Arm_Angle_Mod = rt_modd_snf
    (Robot_Control_U.Measured_Intake_Arm_Angle + 180.0, 360.0) - 180.0;

  /* Chart: '<S6>/Chart' incorporates:
   *  RelationalOperator: '<S55>/FixPt Relational Operator'
   *  UnitDelay: '<S55>/Delay Input1'
   *
   * Block description for '<S55>/Delay Input1':
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
      if ((rtb_Intake_Arm_Move_Out || (rtb_Intake_Arm_Cycle &&
            (Robot_Control_B.RB_Intake_Arm_Angle_Mod <
             Rebuilt_Intake_Cycle_Angle_In))) || (((int32_T)rtb_Intake_Arm_Cycle)
           < ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_c))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      if (rtb_Intake_Arm_Move_In || (rtb_Intake_Arm_Cycle &&
           (Robot_Control_B.RB_Intake_Arm_Angle_Mod >
            Rebuilt_Intake_Cycle_Angle_Out))) {
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

  /* Switch: '<S69>/Init' incorporates:
   *  UnitDelay: '<S69>/FixPt Unit Delay1'
   *  UnitDelay: '<S69>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S69>/Init' */

  /* Sum: '<S67>/Sum1' */
  rtb_Switch2_c3 = Robot_Control_B.RB_Des_Intake_Arm_Angle - rtb_Switch2_p2;

  /* Switch: '<S68>/Switch2' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Constant3'
   *  RelationalOperator: '<S68>/LowerRelop1'
   *  RelationalOperator: '<S68>/UpperRelop'
   *  Switch: '<S68>/Switch'
   */
  if (rtb_Switch2_c3 > Rebuilt_Intake_RL_Inc) {
    rtb_Switch2_c3 = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Switch2_c3 < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S68>/Switch' incorporates:
     *  Constant: '<S57>/Constant1'
     */
    rtb_Switch2_c3 = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S68>/Switch2' */

  /* Sum: '<S67>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Switch2_c3 + rtb_Switch2_p2;

  /* Sum: '<S63>/Sum' */
  rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S65>/Sum1' incorporates:
   *  Constant: '<S63>/Constant2'
   *  Product: '<S65>/Product'
   *  Sum: '<S65>/Sum'
   *  UnitDelay: '<S65>/Unit Delay1'
   */
  rtb_Sum1_dj = ((rtb_Switch2_p2 - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S63>/Product' incorporates:
   *  Constant: '<S63>/Constant3'
   */
  rtb_Product_ov = rtb_Sum1_dj * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S64>/Diff' incorporates:
   *  UnitDelay: '<S64>/UD'
   *
   * Block description for '<S64>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S64>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_ov - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S63>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S63>/Add' incorporates:
   *  Gain: '<S63>/Gain'
   *  Gain: '<S63>/Gain1'
   *  Saturate: '<S63>/Saturation'
   */
  rtb_Add_ir = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
                (Rebuilt_Intake_Arm_Gain_P * rtb_Switch2_p2)) + rtb_Add_oy;

  /* Sum: '<S63>/Subtract' incorporates:
   *  Constant: '<S63>/Constant'
   */
  rtb_Switch2_c3 = 1.0 - rtb_Add_ir;

  /* Sum: '<S63>/Sum2' incorporates:
   *  Gain: '<S63>/Gain2'
   *  UnitDelay: '<S63>/Unit Delay'
   */
  rtb_Switch2_p2 = (0.0 * rtb_Switch2_p2) + Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S66>/Switch2' incorporates:
   *  Constant: '<S63>/Constant'
   *  RelationalOperator: '<S66>/LowerRelop1'
   *  Sum: '<S63>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_ir))) {
    /* Sum: '<S63>/Subtract1' incorporates:
     *  Constant: '<S63>/Constant1'
     */
    rtb_Switch2_c3 = -1.0 - rtb_Add_ir;

    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S63>/Constant1'
     *  RelationalOperator: '<S66>/UpperRelop'
     *  Sum: '<S63>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_ir))) {
      rtb_Switch2_c3 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S66>/Switch' */
  }

  /* End of Switch: '<S66>/Switch2' */

  /* Saturate: '<S63>/Saturation1' */
  if (rtb_Switch2_c3 > 0.1) {
    rtb_Switch2_c3 = 0.1;
  } else if (rtb_Switch2_c3 < -0.1) {
    rtb_Switch2_c3 = -0.1;
  }

  /* End of Saturate: '<S63>/Saturation1' */

  /* Switch: '<S56>/Switch2' incorporates:
   *  Constant: '<S59>/Constant'
   *  Constant: '<S60>/Constant'
   *  Constant: '<S61>/Constant'
   *  Constant: '<S62>/Constant'
   *  Logic: '<S56>/Logical Operator1'
   *  Logic: '<S56>/Logical Operator2'
   *  Logic: '<S56>/Logical Operator3'
   *  RelationalOperator: '<S59>/Compare'
   *  RelationalOperator: '<S60>/Compare'
   *  RelationalOperator: '<S61>/Compare'
   *  RelationalOperator: '<S62>/Compare'
   */
  if (((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_In) && (Robot_Control_B.RB_Intake_Arm_Angle_Mod
        <= Rebuilt_Intake_Meas_In_Disable)) ||
      ((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_Out) &&
       (Robot_Control_B.RB_Intake_Arm_Angle_Mod >=
        Rebuilt_Intake_Meas_Out_Disable))) {
    /* Switch: '<S56>/Switch2' incorporates:
     *  Constant: '<S56>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  } else {
    /* Sum: '<S63>/Add1' */
    rtb_Add_oy = rtb_Add_ir + rtb_Switch2_c3;

    /* Saturate: '<S63>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S63>/Saturation2' */
  }

  /* End of Switch: '<S56>/Switch2' */

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

  /* Logic: '<S138>/Logical Operator1' incorporates:
   *  Constant: '<S184>/Constant'
   *  RelationalOperator: '<S184>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S185>/Sum' incorporates:
   *  Sum: '<S138>/Subtract'
   */
  rtb_Switch2_p2 = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S187>/Sum1' incorporates:
   *  Constant: '<S185>/Constant2'
   *  Product: '<S187>/Product'
   *  Sum: '<S185>/Sum'
   *  Sum: '<S187>/Sum'
   *  UnitDelay: '<S187>/Unit Delay1'
   */
  rtb_Add_ir = ((rtb_Switch2_p2 - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S185>/Product' incorporates:
   *  Constant: '<S185>/Constant3'
   */
  rtb_Product_i = rtb_Add_ir * 0.0;

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
  rtb_Add_oy = rtb_Product_i - Robot_Control_DW.UD_DSTATE_kz;

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
  rtb_Add_oy += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Switch2_p2);

  /* Switch: '<S138>/Switch4' incorporates:
   *  Constant: '<S138>/Constant6'
   *  Constant: '<S138>/Constant7'
   *  Logic: '<S138>/Logical Operator1'
   *  Logic: '<S138>/Logical Operator2'
   *  RelationalOperator: '<S138>/LessThan2'
   *  UnitDelay: '<S138>/Unit Delay1'
   */
  if ((rtb_Switch2_p2 < 0.0) && rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay1_DSTATE_ea));
  }

  /* End of Switch: '<S138>/Switch4' */

  /* Switch: '<S138>/Switch1' incorporates:
   *  Constant: '<S138>/Constant1'
   *  Constant: '<S138>/Constant2'
   *  Logic: '<S138>/Logical Operator'
   *  Logic: '<S138>/Logical Operator1'
   *  RelationalOperator: '<S138>/LessThan'
   *  UnitDelay: '<S138>/Unit Delay'
   */
  if ((rtb_Switch2_p2 < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S138>/Switch1' */

  /* Switch: '<S185>/Switch' incorporates:
   *  Constant: '<S185>/Constant4'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S185>/Sum2' incorporates:
     *  Gain: '<S185>/Gain2'
     *  Product: '<S185>/Product1'
     *  Sum: '<S185>/Sum'
     *  Switch: '<S185>/Switch1'
     *  UnitDelay: '<S185>/Unit Delay'
     */
    rtb_Switch2_p2 = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Switch2_p2) * ((real_T)
      (!rtb_Intake_Arm_Move_In))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S185>/Subtract' incorporates:
     *  Constant: '<S185>/Constant'
     */
    rtb_Error_c5 = 1.0 - rtb_Add_oy;

    /* Switch: '<S188>/Switch2' incorporates:
     *  Constant: '<S185>/Constant'
     *  RelationalOperator: '<S188>/LowerRelop1'
     *  Sum: '<S185>/Subtract'
     */
    if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_oy))) {
      /* Sum: '<S185>/Subtract1' incorporates:
       *  Constant: '<S185>/Constant1'
       */
      rtb_Error_c5 = -1.0 - rtb_Add_oy;

      /* Switch: '<S188>/Switch' incorporates:
       *  Constant: '<S185>/Constant1'
       *  RelationalOperator: '<S188>/UpperRelop'
       *  Sum: '<S185>/Subtract1'
       */
      if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_oy))) {
        rtb_Error_c5 = rtb_Switch2_p2;
      }

      /* End of Switch: '<S188>/Switch' */
    }

    /* End of Switch: '<S188>/Switch2' */

    /* Saturate: '<S185>/Saturation1' */
    if (rtb_Error_c5 > 0.1) {
      rtb_Switch2_p2 = 0.1;
    } else if (rtb_Error_c5 < -0.1) {
      rtb_Switch2_p2 = -0.1;
    } else {
      rtb_Switch2_p2 = rtb_Error_c5;
    }

    /* End of Saturate: '<S185>/Saturation1' */
  } else {
    rtb_Switch2_p2 = 0.0;
  }

  /* End of Switch: '<S185>/Switch' */

  /* Switch: '<S138>/Switch2' incorporates:
   *  Logic: '<S138>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S185>/Add1' */
    rtb_Add_oy += rtb_Switch2_p2;

    /* Saturate: '<S185>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S185>/Saturation2' */
  } else {
    /* Switch: '<S138>/Switch2' incorporates:
     *  Constant: '<S138>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S138>/Switch2' */

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
  Robot_Control_Y.Auto_Initial_Gyro_Angle = rtb_Switch1_m;

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

  /* Update for UnitDelay: '<S38>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Joystick_Left_B11;

  /* Update for UnitDelay: '<S39>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *
   * Block description for '<S39>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Joystick_Left_B12;

  /* Update for UnitDelay: '<S40>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *
   * Block description for '<S40>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Joystick_Left_B13;

  /* Update for UnitDelay: '<S46>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S46>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S46>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S49>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S49>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 0U;

  /* Update for UnitDelay: '<S49>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_a = rtb_Switch1_hb;

  /* Update for UnitDelay: '<S52>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S52>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S52>/FixPt Unit Delay1' */
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

  /* Update for Delay: '<S75>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S95>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S75>/A'
   *  Delay: '<S75>/MemoryX'
   */
  rtb_Sum1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Switch1_hb = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S75>/MemoryX' incorporates:
   *  Constant: '<S75>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S95>/A[k]*xhat[k|k-1]'
   *  Product: '<S95>/B[k]*u[k]'
   *  Sum: '<S95>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Sum1) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Switch1_hb) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S355>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S355>/FixPt Constant'
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

  /* Update for UnitDelay: '<S378>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S377>/UD'
   *
   * Block description for '<S377>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S375>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Saturation_h;

  /* Update for UnitDelay: '<S357>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Init_o;

  /* Update for UnitDelay: '<S372>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S372>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S372>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S356>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S365>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S365>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S365>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S331>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch_hs;

  /* Update for UnitDelay: '<S330>/UD'
   *
   * Block description for '<S330>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch1_n;

  /* Update for UnitDelay: '<S324>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S268>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S267>/UD'
   *
   * Block description for '<S267>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Init;

  /* Update for UnitDelay: '<S261>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S279>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S278>/UD'
   *
   * Block description for '<S278>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_bq;

  /* Update for UnitDelay: '<S264>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S289>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S288>/UD'
   *
   * Block description for '<S288>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S282>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S300>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_bl;

  /* Update for UnitDelay: '<S299>/UD'
   *
   * Block description for '<S299>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_fl;

  /* Update for UnitDelay: '<S285>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S310>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S309>/UD'
   *
   * Block description for '<S309>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S303>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S321>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S320>/UD'
   *
   * Block description for '<S320>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S306>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S342>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S341>/UD'
   *
   * Block description for '<S341>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_ec;

  /* Update for UnitDelay: '<S327>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S192>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_os;

  /* Update for UnitDelay: '<S191>/UD'
   *
   * Block description for '<S191>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S190>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S140>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Button_Spinup_Enable;

  /* Update for UnitDelay: '<S132>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S132>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S73>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_fh;

  /* Update for UnitDelay: '<S72>/UD'
   *
   * Block description for '<S72>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_hm;

  /* Update for UnitDelay: '<S71>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S58>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_nh = rtb_Button_Shoot_Enable;

  /* Update for UnitDelay: '<S55>/Delay Input1'
   *
   * Block description for '<S55>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S69>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S69>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S65>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_dj;

  /* Update for UnitDelay: '<S64>/UD'
   *
   * Block description for '<S64>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_ov;

  /* Update for UnitDelay: '<S63>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_Switch2_c3;

  /* Update for UnitDelay: '<S187>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Add_ir;

  /* Update for UnitDelay: '<S186>/UD'
   *
   * Block description for '<S186>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_i;

  /* Update for UnitDelay: '<S138>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S185>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S138>/Unit Delay' */
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

  /* Start for If: '<S135>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S49>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S52>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S75>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S355>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S372>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S365>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S132>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S69>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S434>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S200>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S196>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S200>/Robot_Index_Is_Valid' */
  /* Start for If: '<S203>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S203>/Circle_Check_Valid' */
  /* Start for If: '<S205>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d0 = -1;

  /* End of SystemInitialize for SubSystem: '<S203>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S200>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ms = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S169>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S171>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S172>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ht = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem5' */
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
