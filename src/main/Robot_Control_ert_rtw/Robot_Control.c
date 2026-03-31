/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.481
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Mar 29 20:12:44 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Robot_Control.h"
#include "rtwtypes.h"
#include "Robot_Control_private.h"
#include "rt_modd_snf.h"
#include <math.h>
#include "rt_powd_snf.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "rt_hypotd_snf.h"
#include "rt_atan2d_snf.h"
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

/* Named constants for Chart: '<S363>/Add dither' */
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
real_T Blue_Hub_LeftX = 5.1717;        /* Variable: Blue_Hub_LeftX
                                        * Referenced by:
                                        *   '<S147>/Constant2'
                                        *   '<S147>/Constant6'
                                        */
real_T Blue_Hub_LeftY = 3.354;         /* Variable: Blue_Hub_LeftY
                                        * Referenced by:
                                        *   '<S147>/Constant3'
                                        *   '<S147>/Constant7'
                                        */
real_T Blue_Hub_RightX = 5.1717;       /* Variable: Blue_Hub_RightX
                                        * Referenced by:
                                        *   '<S147>/Constant4'
                                        *   '<S147>/Constant8'
                                        */
real_T Blue_Hub_RightY = 4.548;        /* Variable: Blue_Hub_RightY
                                        * Referenced by:
                                        *   '<S147>/Constant5'
                                        *   '<S147>/Constant9'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S437>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S433>/Constant'
                                        *   '<S433>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S437>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S433>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S266>/Constant3'
                                        *   '<S287>/Constant3'
                                        *   '<S308>/Constant3'
                                        *   '<S329>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S266>/Constant2'
                                   *   '<S287>/Constant2'
                                   *   '<S308>/Constant2'
                                   *   '<S329>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S266>/Saturation'
                                        *   '<S287>/Saturation'
                                        *   '<S308>/Saturation'
                                        *   '<S329>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S266>/Saturation'
                                        *   '<S287>/Saturation'
                                        *   '<S308>/Saturation'
                                        *   '<S329>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S266>/Gain'
                                            *   '<S287>/Gain'
                                            *   '<S308>/Gain'
                                            *   '<S329>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S266>/Gain2'
                                        *   '<S287>/Gain2'
                                        *   '<S308>/Gain2'
                                        *   '<S329>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S266>/Saturation1'
                                         *   '<S287>/Saturation1'
                                         *   '<S308>/Saturation1'
                                         *   '<S329>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S266>/Saturation1'
                                        *   '<S287>/Saturation1'
                                        *   '<S308>/Saturation1'
                                        *   '<S329>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S266>/Gain1'
                                        *   '<S287>/Gain1'
                                        *   '<S308>/Gain1'
                                        *   '<S329>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S271>/Constant'
                            *   '<S292>/Constant'
                            *   '<S313>/Constant'
                            *   '<S334>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S190>/BlueAllianceZoneX'
                                         *   '<S192>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S148>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S148>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S148>/Constant1'
                                        *   '<S148>/Switch3'
                                        */
real_T Field_Length = 17.557;          /* Variable: Field_Length
                                        * Referenced by: '<S147>/Constant10'
                                        */
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S148>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S148>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S191>/RedAllianceZoneX'
                                         *   '<S193>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S148>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S148>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S423>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S423>/Constant5'
                                          */
real_T Field_Width = 8.0693;           /* Variable: Field_Width
                                        * Referenced by: '<S147>/Constant11'
                                        */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rate_Limit_X = 1000.0;          /* Variable: Rate_Limit_X
                                        * Referenced by: '<S38>/Constant3'
                                        */
real_T Rate_Limit_Y = 1000.0;          /* Variable: Rate_Limit_Y
                                        * Referenced by: '<S39>/Constant3'
                                        */
real_T Rate_Limit_Z = 1000.0;          /* Variable: Rate_Limit_Z
                                        * Referenced by: '<S40>/Constant3'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = 0.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S163>/Constant'
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
                                          *   '<S141>/Constant3'
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
real_T Rebuilt_Intake_Arm_Gain_P = 0.008;/* Variable: Rebuilt_Intake_Arm_Gain_P
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
real_T Rebuilt_Intake_RL_Dec = -3.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S55>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 3.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S55>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 30.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S175>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S179>/Constant3'
                                   *   '<S180>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S170>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S171>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S172>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S173>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S176>/Unit Delay'
                                      *   '<S177>/Unit Delay'
                                      *   '<S178>/Unit Delay'
                                      *   '<S179>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S176>/Constant2'
                                      *   '<S177>/Constant2'
                                      *   '<S178>/Constant2'
                                      *   '<S179>/Constant2'
                                      *   '<S183>/Constant'
                                      *   '<S184>/Constant'
                                      *   '<S185>/Constant'
                                      *   '<S186>/Constant'
                                      */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S167>/Constant'
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
                                * Referenced by: '<S56>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00016534;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                                  * Referenced by: '<S69>/Gain'
                                                  */
real_T Rebuilt_Roller_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                             * Referenced by: '<S69>/Gain2'
                                             */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0001;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                             * Referenced by: '<S69>/Gain1'
                                             */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S149>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S149>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S149>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S149>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S149>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S149>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S149>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S149>/Constant1'
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
real_T Rebuilt_Shoot_Gyro_Err_6 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S144>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_7
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
                                             * Referenced by: '<S158>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S158>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3265.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S158>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3425.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S158>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3625.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S158>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3775.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S158>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S158>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S158>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2825.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S157>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S157>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3365.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S157>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3525.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S157>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3725.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S157>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3875.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S157>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4075.0;
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
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00015;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S12>/Constant1'
                                       */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S146>/Constant2'
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
                              * Referenced by: '<S139>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S195>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S195>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S195>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S422>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S420>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S422>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S423>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S423>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S255>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S255>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S202>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S215>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S255>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S362>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S362>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S362>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S362>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S362>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S362>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S380>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S380>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S380>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S380>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S379>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S380>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S380>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S380>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S380>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S380>/Constant1'
                                   *   '<S380>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S380>/Constant'
                                   *   '<S380>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S363>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S363>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S363>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S363>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S269>/Constant3'
                                        *   '<S290>/Constant3'
                                        *   '<S311>/Constant3'
                                        *   '<S332>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S269>/Constant2'
                                *   '<S290>/Constant2'
                                *   '<S311>/Constant2'
                                *   '<S332>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S269>/Saturation'
                                           *   '<S290>/Saturation'
                                           *   '<S311>/Saturation'
                                           *   '<S332>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S269>/Saturation'
                                          *   '<S290>/Saturation'
                                          *   '<S311>/Saturation'
                                          *   '<S332>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S269>/Gain2'
                                         *   '<S290>/Gain2'
                                         *   '<S311>/Gain2'
                                         *   '<S332>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S269>/Saturation1'
                                             *   '<S290>/Saturation1'
                                             *   '<S311>/Saturation1'
                                             *   '<S332>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S269>/Saturation1'
                                            *   '<S290>/Saturation1'
                                            *   '<S311>/Saturation1'
                                            *   '<S332>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S269>/Gain1'
                                        *   '<S290>/Gain1'
                                        *   '<S311>/Gain1'
                                        *   '<S332>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S361>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S361>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S361>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S361>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S361>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S361>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S422>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S422>/Constant1'
                                        */
real_T TEST_Desired_Hood_Enable_OV = 0.0;/* Variable: TEST_Desired_Hood_Enable_OV
                                          * Referenced by: '<S10>/Constant7'
                                          */
real_T TEST_Desired_Hood_Pos_OV = 0.05;/* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S10>/Constant6'
                                        */
real_T TEST_Desired_Shooter_FF_DC_OV = 0.0;
                                      /* Variable: TEST_Desired_Shooter_FF_DC_OV
                                       * Referenced by: '<S10>/Constant4'
                                       */
real_T TEST_Desired_Shooter_Speed_OV = 0.0;
                                      /* Variable: TEST_Desired_Shooter_Speed_OV
                                       * Referenced by: '<S10>/Constant3'
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
real_T TEST_Swerve_Mode_Override_Flag = 0.0;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S421>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S421>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S421>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S349>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S349>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S349>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S349>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S349>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S349>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S423>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S422>/Dead Zone'
                                        *   '<S423>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S422>/Dead Zone'
                                        *   '<S423>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S420>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S420>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S420>/Constant4'
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
                                        * Referenced by: '<S420>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S420>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S420>/Constant5'
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
                                        *   '<S420>/Constant11'
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
  /* InitializeConditions for UnitDelay: '<S176>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * System reset for action system:
 *    '<S133>/If Action Subsystem1'
 *    '<S133>/If Action Subsystem3'
 */
void Robot__IfActionSubsystem1_Reset(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S176>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S133>/If Action Subsystem1'
 *    '<S133>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(real_T rtu_IsBlueInactiveFirst, real_T
  rtu_IsBlueAlliance, boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive,
  real_T *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  boolean_T rtb_Compare_cf;

  /* RelationalOperator: '<S183>/Compare' incorporates:
   *  Constant: '<S176>/Constant1'
   *  Constant: '<S183>/Constant'
   *  Sum: '<S176>/Sum'
   *  UnitDelay: '<S176>/Unit Delay'
   */
  rtb_Compare_cf = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S176>/Logical Operator' incorporates:
   *  Logic: '<S176>/NOT'
   */
  *rty_IsBlueActive = ((!(rtu_IsBlueInactiveFirst != 0.0)) || rtb_Compare_cf);

  /* Logic: '<S176>/Logical Operator1' */
  *rty_IsRedActive = ((rtu_IsBlueInactiveFirst != 0.0) || rtb_Compare_cf);

  /* Switch: '<S176>/Switch' incorporates:
   *  Constant: '<S176>/Constant1'
   *  Constant: '<S176>/Constant2'
   *  Logic: '<S176>/Logical Operator2'
   *  Sum: '<S176>/Subtract'
   *  Sum: '<S176>/Sum'
   *  UnitDelay: '<S176>/Unit Delay'
   */
  if ((boolean_T)((rtu_IsBlueInactiveFirst != 0.0) ^ (rtu_IsBlueAlliance != 0.0)))
  {
    *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;
  } else {
    *rty_Time_Remaining = (localDW->UnitDelay_DSTATE - 0.02) -
      Rebuilt_Match_Time_Shoot_Early;
  }

  /* End of Switch: '<S176>/Switch' */

  /* Update for UnitDelay: '<S176>/Unit Delay' incorporates:
   *  Constant: '<S176>/Constant1'
   *  Sum: '<S176>/Sum'
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
  real_T rtb_Abs2;
  real_T rtb_Add_e3;
  real_T rtb_Add_i;
  real_T rtb_Add_jp;
  real_T rtb_Add_lu;
  real_T rtb_Add_pv;
  real_T rtb_Error_n;
  real_T rtb_Init;
  real_T rtb_Init_o;
  real_T rtb_Integral_bj;
  real_T rtb_Integral_d;
  real_T rtb_Integral_ga;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_MatrixConcatenate_idx_0;
  real_T rtb_Merge1;
  real_T rtb_Minus_f;
  real_T rtb_Minus_k_idx_0;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_ej;
  real_T rtb_Product_hi;
  real_T rtb_Product_ih;
  real_T rtb_Product_k;
  real_T rtb_Product_ld;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_kg;
  real_T rtb_Subtract1_la;
  real_T rtb_Sum1;
  real_T rtb_Sum1_dj;
  real_T rtb_Sum1_fh;
  real_T rtb_Sum2_e;
  real_T rtb_Switch1_h;
  real_T rtb_Switch1_hb;
  real_T rtb_Switch1_m;
  real_T rtb_Switch1_n;
  real_T rtb_Switch2;
  real_T rtb_Switch2_dp;
  real_T rtb_Switch2_ee;
  real_T rtb_Switch2_h;
  real_T rtb_Switch2_hw;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s227_iter;
  uint16_T s252_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T Iteration_Number;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4_j;
  boolean_T rtb_Button_Spinup_Enable;
  boolean_T rtb_Compare_ky;
  boolean_T rtb_Compare_lk;
  boolean_T rtb_Compare_mq;
  boolean_T rtb_Compare_pb;
  boolean_T rtb_Intake_Arm_Cycle;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_ms;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_Shooter_Active_prev;

  /* RelationalOperator: '<S35>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *  UnitDelay: '<S35>/Delay Input1'
   *
   * Block description for '<S35>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Joystick_Left_B11 >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S36>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *  UnitDelay: '<S36>/Delay Input1'
   *
   * Block description for '<S36>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets =
    (Robot_Control_U.Joystick_Left_B12 > Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S37>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *  UnitDelay: '<S37>/Delay Input1'
   *
   * Block description for '<S37>/Delay Input1':
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
    rtb_Init_o = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S44>/Init' */

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Constant: '<S38>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Sin4 = Rate_Limit_X;
  } else {
    rtb_Sin4 = 1000.0;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Sum: '<S42>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Init_o;

  /* Switch: '<S43>/Switch2' incorporates:
   *  RelationalOperator: '<S43>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Sin4)) {
    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S38>/Constant'
     *  Constant: '<S38>/Constant3'
     *  UnaryMinus: '<S38>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_hb = -Rate_Limit_X;
    } else {
      rtb_Switch1_hb = -1000.0;
    }

    /* End of Switch: '<S38>/Switch1' */

    /* Switch: '<S43>/Switch' incorporates:
     *  RelationalOperator: '<S43>/UpperRelop'
     */
    if (rtb_Sum1 < rtb_Switch1_hb) {
      rtb_Sin4 = rtb_Switch1_hb;
    } else {
      rtb_Sin4 = rtb_Sum1;
    }

    /* End of Switch: '<S43>/Switch' */
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Sum: '<S42>/Sum' */
  rtb_Sum1 = rtb_Sin4 + rtb_Init_o;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S47>/Init' incorporates:
   *  UnitDelay: '<S47>/FixPt Unit Delay1'
   *  UnitDelay: '<S47>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_j != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_a;
  }

  /* End of Switch: '<S47>/Init' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant2'
   *  Constant: '<S39>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Y;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Sum: '<S45>/Sum1' */
  rtb_Switch1_hb = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Sin4;

  /* Switch: '<S46>/Switch2' incorporates:
   *  RelationalOperator: '<S46>/LowerRelop1'
   */
  if (!(rtb_Switch1_hb > rtb_Init_o)) {
    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant'
     *  Constant: '<S39>/Constant3'
     *  UnaryMinus: '<S39>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_h = -Rate_Limit_Y;
    } else {
      rtb_Switch1_h = -1000.0;
    }

    /* End of Switch: '<S39>/Switch1' */

    /* Switch: '<S46>/Switch' incorporates:
     *  RelationalOperator: '<S46>/UpperRelop'
     */
    if (rtb_Switch1_hb < rtb_Switch1_h) {
      rtb_Init_o = rtb_Switch1_h;
    } else {
      rtb_Init_o = rtb_Switch1_hb;
    }

    /* End of Switch: '<S46>/Switch' */
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Sum: '<S45>/Sum' */
  rtb_Switch1_hb = rtb_Init_o + rtb_Sin4;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S50>/Init' incorporates:
   *  UnitDelay: '<S50>/FixPt Unit Delay1'
   *  UnitDelay: '<S50>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Sin4 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S50>/Init' */

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Constant2'
   *  Constant: '<S40>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Z;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Sum: '<S48>/Sum1' */
  rtb_Switch1_h = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Sin4;

  /* Switch: '<S49>/Switch2' incorporates:
   *  RelationalOperator: '<S49>/LowerRelop1'
   */
  if (!(rtb_Switch1_h > rtb_Init_o)) {
    /* Switch: '<S40>/Switch1' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant3'
     *  UnaryMinus: '<S40>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_m = -Rate_Limit_Z;
    } else {
      rtb_Switch1_m = -1000.0;
    }

    /* End of Switch: '<S40>/Switch1' */

    /* Switch: '<S49>/Switch' incorporates:
     *  RelationalOperator: '<S49>/UpperRelop'
     */
    if (rtb_Switch1_h < rtb_Switch1_m) {
      rtb_Init_o = rtb_Switch1_m;
    } else {
      rtb_Init_o = rtb_Switch1_h;
    }

    /* End of Switch: '<S49>/Switch' */
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Sum: '<S48>/Sum' */
  rtb_Switch1_h = rtb_Init_o + rtb_Sin4;

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
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

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S34>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* Sum: '<S32>/Add1' incorporates:
   *  Constant: '<S32>/Constant3'
   *  Constant: '<S32>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Math: '<S32>/Math Function'
   *  Sum: '<S32>/Add2'
   */
  rtb_Sin4 = rt_modd_snf(Robot_Control_U.Gyro_Angle_rad + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* RelationalOperator: '<S41>/GreaterThan' incorporates:
   *  Abs: '<S41>/Abs'
   *  Constant: '<S41>/Constant2'
   */
  rtb_Compare_ky = (fabs(rtb_Sin4) > 1.5707963267948966);

  /* Logic: '<S41>/Logical Operator1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   */
  rtb_LogicalOperator1 = ((Robot_Control_U.Joystick_Left_B2) && rtb_Compare_ky);

  /* Logic: '<S41>/Logical Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B3'
   *  Inport: '<Root>/Joystick_Left_B4'
   */
  rtb_Compare_mq = ((Robot_Control_U.Joystick_Left_B3) ||
                    (Robot_Control_U.Joystick_Left_B4));

  /* RelationalOperator: '<S41>/GreaterThan1' incorporates:
   *  Constant: '<S41>/Constant1'
   */
  rtb_Compare_pb = (rtb_Sin4 > 0.0);

  /* Logic: '<S41>/Logical Operator5' incorporates:
   *  Logic: '<S41>/Logical Operator6'
   */
  rtb_LogicalOperator5 = (rtb_Compare_mq && (!rtb_Compare_pb));

  /* Logic: '<S41>/Logical Operator3' */
  rtb_LogicalOperator3 = (rtb_Compare_mq && rtb_Compare_pb);

  /* Logic: '<S41>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   *  Logic: '<S41>/Logical Operator4'
   */
  rtb_LogicalOperator2 = ((Robot_Control_U.Joystick_Left_B2) && (!rtb_Compare_ky));

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

  /* If: '<S449>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S449>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S452>/Action Port'
     */
    /* Product: '<S452>/Product' incorporates:
     *  Constant: '<S452>/Constant1'
     *  Constant: '<S452>/Constant2'
     *  Math: '<S452>/Math Function'
     */
    rtb_Sin4 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495) *
      111.0;

    /* End of Outputs for SubSystem: '<S449>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S449>/Subsystem' incorporates:
     *  ActionPort: '<S453>/Action Port'
     */
    /* SignalConversion generated from: '<S453>/Out1' incorporates:
     *  Constant: '<S453>/Constant'
     */
    rtb_Sin4 = 0.0;

    /* End of Outputs for SubSystem: '<S449>/Subsystem' */
  }

  /* End of If: '<S449>/If' */

  /* Gain: '<S450>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Init_o = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S451>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Sin4 * cos(rtb_Init_o)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S451>/theta->y'
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
  rtb_Minus_f = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Minus_f)) || (rtIsInf(rtb_Minus_f))) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = fmod(rtb_Minus_f, 4.294967296E+9);
  }

  switch ((rtb_Minus_f < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Minus_f)))) :
          ((int32_T)((uint32_T)rtb_Minus_f))) {
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
    rtb_Compare_pb = false;

    /* SignalConversion generated from: '<S4>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S4>/Constant6'
     */
    rtb_Compare_mq = false;

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
    rtb_Compare_ky = false;

    /* SignalConversion generated from: '<S4>/Intake_Arm_Move_In' incorporates:
     *  Constant: '<S4>/Constant16'
     */
    rtb_Shooter_Active_prev = false;

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
    rtb_LogicalOperator1_ms = false;

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
    rtb_LogicalOperator1 = (Robot_Control_DW.UnitDelay1_DSTATE_k == 2.0);

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
    if (((int32_T)rtb_LogicalOperator1) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_kb)) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
    }

    /* End of Switch: '<S19>/Switch1' */

    /* RelationalOperator: '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     *  UnitDelay: '<S19>/Unit Delay1'
     */
    rtb_LogicalOperator5 = (Robot_Control_DW.UnitDelay1_DSTATE_k == 4.0);

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
    if (((int32_T)rtb_LogicalOperator5) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_h)) {
      rtb_Switch2_hw = 0.0;
    } else {
      rtb_Switch2_hw = Robot_Control_DW.UnitDelay2_DSTATE_d + 0.02;
    }

    /* End of Switch: '<S19>/Switch2' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     *  Switch: '<S19>/Switch3'
     */
    if (rtb_LogicalOperator1) {
      rtb_Shooter_Active_prev = (rtb_Switch1_n >= Auto_Shoot_Time);
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S19>/Switch3' incorporates:
       *  Constant: '<S26>/Constant'
       *  RelationalOperator: '<S26>/Compare'
       */
      rtb_Shooter_Active_prev = (rtb_Switch2_hw >= Auto_Deploy_Intake_Time);
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
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 39];
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
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 39];
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
        Robot_Control_B.Auto_Spline_Enable = false;
        if ((Robot_Control_DW.counter > 1.0) &&
            ((Robot_Control_B.Auto_Desired_Static_Action == 0.0) ||
             rtb_Shooter_Active_prev)) {
          Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Spline_Enable = true;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 49];
        } else {
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Switch1_m) + 39];
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
    rtb_Compare_mq = (Robot_Control_U.IsBlueAlliance != 0.0);

    /* Selector: '<S20>/Selector' */
    i = ((int32_T)Robot_Control_B.Auto_Path_ID) - 1;
    for (rtb_Num_Segments = 0; rtb_Num_Segments < 60; rtb_Num_Segments++) {
      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S20>/Constant1'
       *  Selector: '<S20>/Selector'
       */
      if (rtb_Compare_mq) {
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
      rtb_Init_o = Robot_Control_B.Auto_Desired_Static_Action;
    } else {
      rtb_Init_o = Robot_Control_B.Auto_Desired_Dynamic_Action;
    }

    /* End of Switch: '<S22>/Switch' */

    /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
     *  Constant: '<S22>/Constant20'
     *  Constant: '<S22>/Constant21'
     *  Constant: '<S22>/Constant22'
     *  Constant: '<S22>/Constant23'
     *  Constant: '<S22>/Constant24'
     */
    switch ((int32_T)rtb_Init_o) {
     case 0:
      rtb_LogicalOperator3 = false;
      break;

     case 1:
      rtb_LogicalOperator3 = false;
      break;

     case 2:
      rtb_LogicalOperator3 = true;
      break;

     case 3:
      rtb_LogicalOperator3 = false;
      break;

     default:
      rtb_LogicalOperator3 = false;
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
    if (((int32_T)rtb_LogicalOperator3) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_gf)) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_hk + 0.02;
    }

    /* End of Switch: '<S22>/Switch1' */

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S30>/Constant'
     *  RelationalOperator: '<S30>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Sin4 >= Auto_Intake_Arm_Cycle_Delay_Time) &&
      rtb_LogicalOperator3);

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     */
    switch ((int32_T)rtb_Init_o) {
     case 0:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant'
       *  Constant: '<S22>/Constant4'
       */
      rtb_Compare_ky = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant9'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant19'
       */
      rtb_Intake_Arm_Move_Out = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant29'
       */
      rtb_LogicalOperator1_ms = false;
      break;

     case 1:
      rtb_Button_Spinup_Enable = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant1'
       *  Constant: '<S22>/Constant5'
       */
      rtb_Compare_ky = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant10'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant14'
       */
      rtb_Intake_Arm_Move_Out = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant25'
       */
      rtb_LogicalOperator1_ms = false;
      break;

     case 2:
      rtb_Button_Spinup_Enable = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant2'
       *  Constant: '<S22>/Constant7'
       */
      rtb_Compare_ky = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant12'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant16'
       */
      rtb_Intake_Arm_Move_Out = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant27'
       */
      rtb_LogicalOperator1_ms = false;
      break;

     case 3:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant18'
       *  Constant: '<S22>/Constant6'
       */
      rtb_Compare_ky = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant11'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant15'
       */
      rtb_Intake_Arm_Move_Out = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant26'
       */
      rtb_LogicalOperator1_ms = true;
      break;

     default:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant3'
       *  Constant: '<S22>/Constant8'
       */
      rtb_Compare_ky = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch2' incorporates:
       *  Constant: '<S22>/Constant13'
       */
      rtb_Shooter_Active_prev = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch3' incorporates:
       *  Constant: '<S22>/Constant17'
       */
      rtb_Intake_Arm_Move_Out = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch5' incorporates:
       *  Constant: '<S22>/Constant28'
       */
      rtb_LogicalOperator1_ms = false;
      break;
    }

    /* End of MultiPortSwitch: '<S22>/Multiport Switch' */

    /* SignalConversion generated from: '<S2>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S18>/Constant6'
     */
    rtb_Compare_mq = false;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S18>/Constant1'
     *  SignalConversion generated from: '<S2>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S18>/Constant5'
     */
    rtb_Compare_pb = false;

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

    /* Update for UnitDelay: '<S27>/Delay Input1'
     *
     * Block description for '<S27>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_kb = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Switch1_n;

    /* Update for UnitDelay: '<S28>/Delay Input1'
     *
     * Block description for '<S28>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_h = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S19>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_d = rtb_Switch2_hw;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Switch1_m;

    /* Update for UnitDelay: '<S31>/Delay Input1'
     *
     * Block description for '<S31>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_gf = rtb_LogicalOperator3;

    /* Update for UnitDelay: '<S22>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hk = rtb_Sin4;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S422>/Unit Delay1'
       *  UnitDelay: '<S422>/Unit Delay2'
       *  UnitDelay: '<S422>/Unit Delay3'
       *  UnitDelay: '<S422>/Unit Delay4'
       *  UnitDelay: '<S425>/Delay Input1'
       *  UnitDelay: '<S426>/Delay Input1'
       *  UnitDelay: '<S427>/Delay Input1'
       *  UnitDelay: '<S428>/Delay Input1'
       *  UnitDelay: '<S430>/Delay Input1'
       *  UnitDelay: '<S436>/Unit Delay'
       *  UnitDelay: '<S436>/Unit Delay1'
       *  UnitDelay: '<S440>/FixPt Unit Delay1'
       *  UnitDelay: '<S440>/FixPt Unit Delay2'
       *
       * Block description for '<S425>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S426>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S427>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S428>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S430>/Delay Input1':
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

    /* Switch: '<S420>/Switch4' incorporates:
     *  Constant: '<S445>/Constant'
     *  Constant: '<S448>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S445>/Compare'
     *  RelationalOperator: '<S448>/Compare'
     *  Switch: '<S420>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S420>/Switch4' incorporates:
       *  Constant: '<S420>/Constant8'
       *  Sum: '<S420>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S420>/Switch5' incorporates:
       *  Constant: '<S420>/Constant7'
       *  Gain: '<S420>/Gain'
       *  Sum: '<S420>/Subtract5'
       *  Switch: '<S420>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S420>/Switch4' incorporates:
       *  Constant: '<S420>/Constant6'
       *  Switch: '<S420>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S420>/Switch4' */

    /* Logic: '<S420>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S420>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S422>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Minus_f = 0.0;
    } else {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S422>/Add' incorporates:
     *  Constant: '<S422>/Constant'
     *  Constant: '<S422>/Constant1'
     *  DeadZone: '<S422>/Dead Zone'
     *  Lookup_n-D: '<S422>/Modulation_Str_Y_Rel'
     *  Product: '<S422>/Product'
     *  Product: '<S422>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Minus_f *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S424>/Compare' incorporates:
     *  Constant: '<S424>/Constant'
     */
    rtb_Compare_lk = (rtb_Switch1_m == 0.0);

    /* Logic: '<S422>/AND2' incorporates:
     *  RelationalOperator: '<S425>/FixPt Relational Operator'
     *  RelationalOperator: '<S426>/FixPt Relational Operator'
     *  RelationalOperator: '<S427>/FixPt Relational Operator'
     *  RelationalOperator: '<S428>/FixPt Relational Operator'
     *  UnitDelay: '<S425>/Delay Input1'
     *  UnitDelay: '<S426>/Delay Input1'
     *  UnitDelay: '<S427>/Delay Input1'
     *  UnitDelay: '<S428>/Delay Input1'
     *
     * Block description for '<S425>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S426>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S427>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S428>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Intake_Arm_Move_Out = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_LogicalOperator3)
      > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S422>/AND1' incorporates:
     *  Logic: '<S422>/AND3'
     *  UnitDelay: '<S422>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_lk && (rtb_Intake_Arm_Move_Out ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S422>/AND4' incorporates:
     *  Logic: '<S422>/AND8'
     *  UnitDelay: '<S422>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_lk && (!rtb_Intake_Arm_Move_Out)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S422>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* Switch: '<S422>/Switch8' incorporates:
     *  Constant: '<S431>/Constant'
     *  Logic: '<S422>/AND9'
     *  RelationalOperator: '<S430>/FixPt Relational Operator'
     *  RelationalOperator: '<S431>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S430>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S430>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_lk) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_DW.UnitDelay1_DSTATE_nl)) {
      /* Switch: '<S422>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S422>/Switch8' incorporates:
       *  UnitDelay: '<S422>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S422>/Switch8' */

    /* Switch: '<S422>/Switch4' incorporates:
     *  Constant: '<S422>/Constant5'
     *  Switch: '<S422>/Switch1'
     *  Switch: '<S422>/Switch5'
     *  Switch: '<S422>/Switch6'
     *  Switch: '<S422>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Switch1_n = 0.0;
    } else if (rtb_LogicalOperator3) {
      /* Switch: '<S422>/Switch5' incorporates:
       *  Constant: '<S422>/Constant6'
       */
      rtb_Switch1_n = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S422>/Switch6' incorporates:
       *  Constant: '<S422>/Constant7'
       *  Switch: '<S422>/Switch5'
       */
      rtb_Switch1_n = 3.1415926535897931;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S422>/Switch7' incorporates:
       *  Constant: '<S422>/Constant8'
       *  Switch: '<S422>/Switch5'
       *  Switch: '<S422>/Switch6'
       */
      rtb_Switch1_n = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S422>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S422>/Switch5'
       *  Switch: '<S422>/Switch6'
       *  Switch: '<S422>/Switch7'
       */
      rtb_Switch1_n = 0.0;
    } else {
      /* Switch: '<S422>/Switch6' incorporates:
       *  Switch: '<S422>/Switch5'
       *  Switch: '<S422>/Switch7'
       *  UnitDelay: '<S422>/Unit Delay1'
       */
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S422>/Switch4' */

    /* Switch: '<S422>/Switch2' incorporates:
     *  Switch: '<S422>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S422>/Switch2' incorporates:
       *  Constant: '<S422>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S422>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Switch1_n;
    } else {
      /* Switch: '<S422>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S422>/Switch3' incorporates:
       *  Constant: '<S422>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S422>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S422>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S421>/Switch1' incorporates:
     *  Constant: '<S421>/Constant5'
     *  Constant: '<S421>/Constant8'
     *  DataTypeConversion: '<S421>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_mq = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Compare_mq = rtb_Compare_lk;
    }

    /* End of Switch: '<S421>/Switch1' */

    /* Lookup_n-D: '<S423>/Modulation_Drv' incorporates:
     *  Math: '<S423>/Magnitude'
     */
    rtb_Switch2_hw = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S434>/Compare' incorporates:
     *  Constant: '<S434>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Switch2_hw == 0.0);

    /* DeadZone: '<S423>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_Init_o = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_Init_o = 0.0;
    } else {
      rtb_Init_o = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S423>/Dead Zone' */

    /* Logic: '<S423>/Logical Operator' incorporates:
     *  Constant: '<S435>/Constant'
     *  RelationalOperator: '<S435>/Compare'
     */
    rtb_Intake_Arm_Move_Out = ((rtb_Init_o != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S421>/Switch' incorporates:
     *  Constant: '<S421>/Constant5'
     *  Constant: '<S421>/Constant7'
     *  DataTypeConversion: '<S421>/Data Type Conversion'
     *  Logic: '<S423>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_pb = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Compare_pb = !rtb_Intake_Arm_Move_Out;
    }

    /* End of Switch: '<S421>/Switch' */

    /* Switch: '<S420>/Switch2' incorporates:
     *  Constant: '<S420>/Constant2'
     *  Constant: '<S444>/Constant'
     *  Constant: '<S447>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S444>/Compare'
     *  RelationalOperator: '<S447>/Compare'
     *  Sum: '<S420>/Subtract'
     *  Switch: '<S420>/Switch'
     *  Switch: '<S420>/Switch1'
     *  Switch: '<S420>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S420>/Switch2' incorporates:
       *  Constant: '<S420>/Constant5'
       *  Sum: '<S420>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_h = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S420>/Switch2' incorporates:
       *  Constant: '<S420>/Constant4'
       *  Sum: '<S420>/Subtract2'
       *  Switch: '<S420>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S420>/Switch1' incorporates:
       *  Constant: '<S420>/Constant1'
       *  Sum: '<S420>/Subtract3'
       */
      rtb_Switch2_h = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S420>/Switch2' incorporates:
       *  Constant: '<S420>/Constant3'
       *  Switch: '<S420>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S420>/Switch1' incorporates:
       *  Constant: '<S420>/Constant'
       */
      rtb_Switch2_h = 0.0;
    }

    /* End of Switch: '<S420>/Switch2' */

    /* UnaryMinus: '<S420>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_h;

    /* Switch: '<S436>/Switch1' incorporates:
     *  Constant: '<S441>/Constant'
     *  Constant: '<S442>/Constant'
     *  Logic: '<S436>/AND'
     *  RelationalOperator: '<S441>/Compare'
     *  RelationalOperator: '<S442>/Compare'
     *  Switch: '<S436>/Switch2'
     *  UnitDelay: '<S436>/Unit Delay'
     *  UnitDelay: '<S436>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Sin4 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Sin4 = rtb_Switch1_hb;
      rtb_Switch2 = rtb_Sum1;
    }

    /* End of Switch: '<S436>/Switch1' */

    /* Switch: '<S423>/Switch1' incorporates:
     *  Logic: '<S423>/Logical Operator1'
     *  Switch: '<S423>/Switch4'
     *  Switch: '<S423>/Switch9'
     */
    if (rtb_Intake_Arm_Move_Out) {
      /* Signum: '<S423>/Sign' */
      if (rtIsNaN(rtb_Init_o)) {
        rtb_Minus_f = (rtNaN);
      } else if (rtb_Init_o < 0.0) {
        rtb_Minus_f = -1.0;
      } else {
        rtb_Minus_f = (rtb_Init_o > 0.0);
      }

      /* Switch: '<S423>/Switch5' incorporates:
       *  Constant: '<S423>/Constant3'
       *  Constant: '<S423>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_pv = -1.5707963267948966;
      } else {
        rtb_Add_pv = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S423>/Gain3'
       *  Signum: '<S423>/Sign'
       *  Sum: '<S423>/Add'
       *  Switch: '<S423>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Minus_f) +
        rtb_Add_pv;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S423>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S423>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S423>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S423>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S423>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S423>/Switch4'
       *  Trigonometry: '<S423>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Sin4, rtb_Switch2);
    }

    /* End of Switch: '<S423>/Switch1' */

    /* Switch: '<S433>/Switch1' incorporates:
     *  Constant: '<S433>/Constant'
     *  Constant: '<S433>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_h = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_h = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S433>/Switch1' */

    /* Switch: '<S440>/Init' incorporates:
     *  UnitDelay: '<S440>/FixPt Unit Delay1'
     *  UnitDelay: '<S440>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_h;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S440>/Init' */

    /* Sum: '<S438>/Sum1' */
    rtb_Switch2_h -= rtb_Init;

    /* Switch: '<S439>/Switch2' incorporates:
     *  Constant: '<S437>/Constant1'
     *  Constant: '<S437>/Constant3'
     *  RelationalOperator: '<S439>/LowerRelop1'
     *  RelationalOperator: '<S439>/UpperRelop'
     *  Switch: '<S439>/Switch'
     */
    if (rtb_Switch2_h > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_h = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_h < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S439>/Switch' incorporates:
       *  Constant: '<S437>/Constant1'
       */
      rtb_Switch2_h = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S439>/Switch2' */

    /* Sum: '<S438>/Sum' */
    rtb_Init += rtb_Switch2_h;

    /* Switch: '<S423>/Switch8' incorporates:
     *  Logic: '<S423>/Logical Operator1'
     *  Switch: '<S423>/Switch2'
     */
    if (rtb_Intake_Arm_Move_Out) {
      /* Switch: '<S423>/Switch' incorporates:
       *  Gain: '<S423>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Init_o;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S423>/Constant5'
       *  Gain: '<S423>/Gain2'
       *  Math: '<S423>/Magnitude1'
       *  MinMax: '<S423>/Min'
       *  Switch: '<S423>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S433>/Product' incorporates:
       *  Switch: '<S423>/Switch2'
       */
      rtb_Add_pv = rtb_Switch2_hw * rtb_Init;

      /* Saturate: '<S433>/Saturation' incorporates:
       *  Switch: '<S423>/Switch2'
       */
      if (rtb_Add_pv > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_pv < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_pv;
      }

      /* End of Saturate: '<S433>/Saturation' */
    }

    /* End of Switch: '<S423>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S422>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S420>/Constant11'
     *  Switch: '<S420>/Switch6'
     *  Switch: '<S420>/Switch7'
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

    /* RelationalOperator: '<S416>/Compare' incorporates:
     *  Constant: '<S416>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S417>/Compare' incorporates:
     *  Constant: '<S417>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Compare_ky = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S412>/Compare' incorporates:
     *  Constant: '<S412>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Shooter_Active_prev = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S415>/Compare' incorporates:
     *  Constant: '<S415>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S414>/Compare' incorporates:
     *  Constant: '<S414>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Constant: '<S413>/Constant'
     *  Constant: '<S418>/Constant'
     *  Inport: '<Root>/Gamepad_LT'
     *  Inport: '<Root>/Joystick_Right_B1'
     *  RelationalOperator: '<S413>/Compare'
     *  RelationalOperator: '<S418>/Compare'
     */
    rtb_LogicalOperator1_ms = ((Robot_Control_U.Joystick_Right_B1 != 0.0) ||
      (Robot_Control_U.Gamepad_LT != 0.0));

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     *  SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Update for UnitDelay: '<S430>/Delay Input1'
     *
     * Block description for '<S430>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_lk;

    /* Update for UnitDelay: '<S429>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S429>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S425>/Delay Input1'
     *
     * Block description for '<S425>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S426>/Delay Input1'
     *
     * Block description for '<S426>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_LogicalOperator3;

    /* Update for UnitDelay: '<S427>/Delay Input1'
     *
     * Block description for '<S427>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S428>/Delay Input1'
     *
     * Block description for '<S428>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S422>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S422>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S422>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S422>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Switch1_n;

    /* Update for UnitDelay: '<S436>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Sin4;

    /* Update for UnitDelay: '<S436>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S440>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S440>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S440>/FixPt Unit Delay1' */
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
    rtb_Compare_pb = false;

    /* SignalConversion generated from: '<S16>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S16>/Constant6'
     */
    rtb_Compare_mq = false;

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
      rtb_LogicalOperator1 = true;
    } else {
      rtb_LogicalOperator1 = ((!Robot_Control_B.Button_Enable_Wheels) &&
        (Robot_Control_DW.UnitDelay_DSTATE_ir));
    }

    /* End of Switch: '<S16>/Switch' */

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  SignalConversion generated from: '<S16>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = rtb_LogicalOperator1;

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
    rtb_Compare_ky = false;

    /* SignalConversion generated from: '<S16>/Intake_Arm_Move_In' incorporates:
     *  Constant: '<S16>/Constant16'
     */
    rtb_Shooter_Active_prev = false;

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
    rtb_LogicalOperator1_ms = false;

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
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_LogicalOperator1;

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
    rtb_Init_o = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Switch2_hw = rtb_Reshapey[0] - (rtb_Init_o + rtb_Switch1_n);

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
    rtb_Switch1_n = rtb_Reshapey[1] - (rtb_Init_o + rtb_Switch1_n);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S124>/Product3' incorporates:
     *  Constant: '<S74>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Switch2_hw) +
      (-2.0601714451538746E-17 * rtb_Switch1_n);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S124>/Product3' incorporates:
     *  Constant: '<S74>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Switch2_hw) +
      (0.095124921972504 * rtb_Switch1_n);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Product'
     */
    rtb_Switch1_n = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S126>/Product2' incorporates:
     *  Constant: '<S74>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Switch1_n);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Switch1_n);
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
   *  Constant: '<S252>/Constant'
   *  Logic: '<S252>/AND'
   *  MATLAB Function: '<S202>/Find closest index to curve'
   *  Product: '<S252>/Product'
   *  RelationalOperator: '<S252>/Relational Operator'
   *  RelationalOperator: '<S252>/Relational Operator1'
   *  Selector: '<S252>/Selector'
   *  Selector: '<S252>/Selector1'
   *  Selector: '<S253>/Selector'
   *  Sum: '<S252>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S205>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S208>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S210>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S205>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S200>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S200>/Unit Delay'
       *  UnitDelay: '<S201>/Unit Delay'
       *  UnitDelay: '<S203>/Unit Delay'
       *  UnitDelay: '<S203>/Unit Delay1'
       *  UnitDelay: '<S253>/Unit Delay'
       *  UnitDelay: '<S253>/Unit Delay1'
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
     *  ActionPort: '<S200>/Action Port'
     */
    /* Selector: '<S201>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S201>/Selector1' */

    /* Lookup_n-D: '<S200>/Capture Radius' incorporates:
     *  UnitDelay: '<S200>/Unit Delay'
     */
    rtb_Switch1_m = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S201>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S201>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S205>/If' incorporates:
     *  RelationalOperator: '<S205>/ '
     *  UnitDelay: '<S201>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S208>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S210>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S205>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S208>/Action Port'
       */
      /* InitializeConditions for If: '<S205>/If' incorporates:
       *  UnitDelay: '<S208>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S205>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S205>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S208>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S208>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S211>/Action Port'
       */
      /* If: '<S208>/If' incorporates:
       *  Selector: '<S201>/Selector1'
       *  Selector: '<S208>/Selector'
       *  Selector: '<S211>/Selector'
       */
      rtb_Switch2 = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh)
        - 1];

      /* End of Outputs for SubSystem: '<S208>/Increment_If_Rectangle_Check' */

      /* Sum: '<S208>/Minus' incorporates:
       *  Concatenate: '<S201>/Matrix Concatenate2'
       *  Selector: '<S208>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Switch2;

      /* Outputs for IfAction SubSystem: '<S208>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S211>/Action Port'
       */
      /* If: '<S208>/If' incorporates:
       *  Selector: '<S201>/Selector1'
       *  Selector: '<S208>/Selector'
       *  Selector: '<S211>/Selector'
       *  Sum: '<S208>/Minus'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh)
        + 9];

      /* End of Outputs for SubSystem: '<S208>/Increment_If_Rectangle_Check' */

      /* Sum: '<S208>/Minus' incorporates:
       *  Concatenate: '<S201>/Matrix Concatenate2'
       *  Selector: '<S208>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Init_o;

      /* Math: '<S208>/Hypot' */
      rtb_Switch1_n = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S208>/Equal' */
      rtb_LogicalOperator5 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S208>/Switch' incorporates:
       *  Logic: '<S208>/AND'
       *  Logic: '<S208>/OR'
       *  RelationalOperator: '<S208>/Relational Operator'
       *  UnitDelay: '<S208>/Unit Delay'
       */
      rtb_LogicalOperator1 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Switch1_n <= rtb_Switch1_m) && rtb_LogicalOperator5));

      /* If: '<S208>/If' */
      rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_o;
      if (!rtb_LogicalOperator1) {
        if (!rtb_LogicalOperator5) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Robot_Control_DW.If_ActiveSubsystem_o = rtAction;
      if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
        /* Disable for If: '<S210>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S208>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S210>/Action Port'
         */
        /* If: '<S210>/If' incorporates:
         *  RelationalOperator: '<S210>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S210>/Is_Last_Point' incorporates:
           *  ActionPort: '<S213>/Action Port'
           */
          /* InitializeConditions for If: '<S210>/If' incorporates:
           *  UnitDelay: '<S213>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S210>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S210>/Is_Last_Point' incorporates:
           *  ActionPort: '<S213>/Action Port'
           */
          /* Switch: '<S213>/Switch' incorporates:
           *  Constant: '<S215>/Constant'
           *  Logic: '<S213>/OR'
           *  RelationalOperator: '<S215>/Compare'
           *  UnitDelay: '<S213>/Unit Delay'
           */
          rtb_Compare_mq = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
                            (rtb_Switch1_n <= Spline_Stop_Radius));

          /* If: '<S213>/If' */
          if (rtb_Compare_mq) {
            /* Outputs for IfAction SubSystem: '<S213>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S216>/Action Port'
             */
            /* Merge: '<S205>/Merge2' incorporates:
             *  Constant: '<S216>/Constant'
             *  SignalConversion generated from: '<S216>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = true;

            /* SignalConversion generated from: '<S216>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S216>/Constant1'
             */
            rtb_Compare_pb = false;

            /* End of Outputs for SubSystem: '<S213>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S213>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S217>/Action Port'
             */
            /* Merge: '<S205>/Merge2' incorporates:
             *  Constant: '<S217>/Constant'
             *  SignalConversion generated from: '<S217>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = false;

            /* SignalConversion generated from: '<S217>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S217>/Constant1'
             */
            rtb_Compare_pb = true;

            /* End of Outputs for SubSystem: '<S213>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S213>/If' */

          /* Merge: '<S205>/Merge4' incorporates:
           *  SignalConversion: '<S213>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S213>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Compare_mq;

          /* End of Outputs for SubSystem: '<S210>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S210>/Increment_Search' incorporates:
           *  ActionPort: '<S212>/Action Port'
           */
          /* Merge: '<S205>/Merge2' incorporates:
           *  Constant: '<S212>/Constant'
           *  SignalConversion generated from: '<S212>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator5 = false;

          /* SignalConversion generated from: '<S212>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S212>/Constant1'
           */
          rtb_Compare_pb = false;

          /* Merge: '<S205>/Merge4' incorporates:
           *  Constant: '<S214>/FixPt Constant'
           *  SignalConversion: '<S212>/Signal Copy'
           *  Sum: '<S214>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S210>/Increment_Search' */
        }

        /* End of If: '<S210>/If' */
        /* End of Outputs for SubSystem: '<S208>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S208>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S211>/Action Port'
         */
        /* Sum: '<S218>/FixPt Sum1' incorporates:
         *  Constant: '<S218>/FixPt Constant'
         */
        rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S211>/Selector1' incorporates:
         *  Selector: '<S201>/Selector1'
         */
        rtb_Init = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) - 1];

        /* Sum: '<S219>/Subtract' incorporates:
         *  Selector: '<S211>/Selector1'
         *  Sum: '<S219>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Init - rtb_Switch2;

        /* Selector: '<S211>/Selector1' incorporates:
         *  Selector: '<S201>/Selector1'
         */
        rtb_Sin4 = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) + 9];

        /* Sum: '<S219>/Subtract' incorporates:
         *  Selector: '<S211>/Selector1'
         *  Sum: '<S219>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Sin4 - rtb_Init_o;

        /* Math: '<S219>/Hypot' */
        rtb_Switch2_hw = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S219>/Divide' */
        rtb_Switch1_n = rtb_Minus_n[1];

        /* UnaryMinus: '<S219>/Unary Minus' */
        rtb_Minus_f = rtb_Minus_n[0];

        /* Product: '<S219>/Product' incorporates:
         *  Product: '<S219>/Divide'
         *  UnaryMinus: '<S219>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch1_n / rtb_Switch2_hw) * rtb_Switch1_m;
        rtb_Minus_n[1] = ((-rtb_Minus_f) / rtb_Switch2_hw) * rtb_Switch1_m;

        /* Sum: '<S219>/Add1' incorporates:
         *  Sum: '<S219>/Add2'
         *  Sum: '<S219>/Minus'
         */
        rtb_Minus_f = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S219>/Minus4' incorporates:
         *  Sum: '<S219>/Add2'
         *  Sum: '<S219>/Minus'
         */
        rtb_Init = (rtb_Init + rtb_Minus_n[0]) - rtb_Minus_f;

        /* Sum: '<S219>/Minus5' incorporates:
         *  Concatenate: '<S201>/Matrix Concatenate2'
         *  Sum: '<S219>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[0] - rtb_Minus_f;

        /* Sum: '<S219>/Add' incorporates:
         *  Sum: '<S219>/Add2'
         *  Sum: '<S219>/Minus1'
         */
        rtb_Switch1_n = rtb_Switch2 - rtb_Minus_n[0];

        /* Sum: '<S219>/Minus' incorporates:
         *  Sum: '<S219>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S219>/Dot Product' incorporates:
         *  Concatenate: '<S201>/Matrix Concatenate2'
         *  Sum: '<S219>/Minus'
         *  Sum: '<S219>/Minus1'
         *  Sum: '<S219>/Minus5'
         */
        rtb_Switch2_hw = (rtb_Reshapey[0] - rtb_Switch1_n) * rtb_Minus_f;

        /* DotProduct: '<S219>/Dot Product1' incorporates:
         *  Sum: '<S219>/Minus'
         */
        rtb_Switch2 = rtb_Minus_f * rtb_Minus_f;

        /* DotProduct: '<S219>/Dot Product2' incorporates:
         *  Sum: '<S219>/Minus4'
         *  Sum: '<S219>/Minus5'
         */
        rtb_Minus_k_idx_0 = rtb_Init * rtb_MatrixConcatenate_b_idx_0;

        /* DotProduct: '<S219>/Dot Product3' incorporates:
         *  Sum: '<S219>/Minus4'
         */
        rtb_Switch2_h = rtb_Init * rtb_Init;

        /* Sum: '<S219>/Add1' incorporates:
         *  Sum: '<S219>/Add2'
         *  Sum: '<S219>/Minus'
         */
        rtb_Minus_f = rtb_Sin4 - rtb_Minus_n[1];

        /* Sum: '<S219>/Minus4' incorporates:
         *  Sum: '<S219>/Add2'
         *  Sum: '<S219>/Minus'
         */
        rtb_Init = (rtb_Sin4 + rtb_Minus_n[1]) - rtb_Minus_f;

        /* Sum: '<S219>/Minus5' incorporates:
         *  Concatenate: '<S201>/Matrix Concatenate2'
         *  Sum: '<S219>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[1] - rtb_Minus_f;

        /* Sum: '<S219>/Add' incorporates:
         *  Sum: '<S219>/Add2'
         *  Sum: '<S219>/Minus1'
         */
        rtb_Switch1_n = rtb_Init_o - rtb_Minus_n[1];

        /* Sum: '<S219>/Minus' incorporates:
         *  Sum: '<S219>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S219>/Dot Product' incorporates:
         *  Concatenate: '<S201>/Matrix Concatenate2'
         *  Sum: '<S219>/Minus'
         *  Sum: '<S219>/Minus1'
         *  Sum: '<S219>/Minus5'
         */
        rtb_Switch2_hw += (rtb_Reshapey[1] - rtb_Switch1_n) * rtb_Minus_f;

        /* RelationalOperator: '<S220>/Compare' incorporates:
         *  Constant: '<S220>/Constant'
         */
        rtb_LogicalOperator5 = (rtb_Switch2_hw >= 0.0);

        /* RelationalOperator: '<S219>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S219>/Dot Product1'
         *  Sum: '<S219>/Minus'
         */
        rtb_Compare_pb = (rtb_Switch2_hw <= ((rtb_Minus_f * rtb_Minus_f) +
          rtb_Switch2));

        /* DotProduct: '<S219>/Dot Product2' incorporates:
         *  Sum: '<S219>/Minus4'
         *  Sum: '<S219>/Minus5'
         */
        rtb_Switch2_hw = (rtb_Init * rtb_MatrixConcatenate_b_idx_0) +
          rtb_Minus_k_idx_0;

        /* Merge: '<S205>/Merge4' incorporates:
         *  Constant: '<S221>/Constant'
         *  DataTypeConversion: '<S211>/Data Type Conversion'
         *  DotProduct: '<S219>/Dot Product3'
         *  Logic: '<S219>/AND'
         *  RelationalOperator: '<S219>/LessThanOrEqual1'
         *  RelationalOperator: '<S221>/Compare'
         *  Sum: '<S211>/Add'
         *  Sum: '<S219>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_LogicalOperator5 &&
          rtb_Compare_pb) && (rtb_Switch2_hw >= 0.0)) && (rtb_Switch2_hw <=
          ((rtb_Init * rtb_Init) + rtb_Switch2_h)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S205>/Merge2' incorporates:
         *  Constant: '<S211>/Constant2'
         *  SignalConversion generated from: '<S211>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S211>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S211>/Constant1'
         */
        rtb_Compare_pb = false;

        /* End of Outputs for SubSystem: '<S208>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S208>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S209>/Action Port'
         */
        /* Merge: '<S205>/Merge2' incorporates:
         *  Constant: '<S209>/Constant2'
         *  SignalConversion generated from: '<S209>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S209>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S209>/Constant1'
         */
        rtb_Compare_pb = false;

        /* Merge: '<S205>/Merge4' incorporates:
         *  SignalConversion generated from: '<S209>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S208>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S205>/Merge1' incorporates:
       *  Constant: '<S208>/Constant'
       *  SignalConversion generated from: '<S208>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S208>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator1;

      /* End of Outputs for SubSystem: '<S205>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S205>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S207>/Action Port'
       */
      /* Merge: '<S205>/Merge1' incorporates:
       *  Constant: '<S207>/Constant'
       *  SignalConversion generated from: '<S207>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S205>/Merge2' incorporates:
       *  Constant: '<S207>/Constant1'
       *  SignalConversion generated from: '<S207>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator5 = false;

      /* SignalConversion generated from: '<S207>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S207>/Constant2'
       */
      rtb_Compare_pb = false;

      /* Merge: '<S205>/Merge4' incorporates:
       *  SignalConversion generated from: '<S207>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S205>/Escape_Auto_Driving' */
    }

    /* End of If: '<S205>/If' */

    /* If: '<S201>/If1' */
    if (!rtb_Compare_pb) {
      /* Outputs for IfAction SubSystem: '<S201>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S206>/Action Port'
       */
      /* Bias: '<S222>/Add Constant' incorporates:
       *  Bias: '<S222>/Bias'
       *  Sum: '<S222>/Subtract'
       */
      rtb_Switch1_n = ((Robot_Control_B.Spline_Num_Poses -
                        Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S222>/Selector4' incorporates:
       *  Bias: '<S222>/Bias1'
       *  Constant: '<S224>/FixPt Constant'
       *  Sum: '<S224>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S222>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S222>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s227_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S222>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S222>/Selector5' incorporates:
       *  Concatenate: '<S222>/Matrix Concatenate'
       *  Gain: '<S226>/Gain'
       *  Selector: '<S201>/Selector1'
       *  Selector: '<S222>/Selector2'
       *  Selector: '<S222>/Selector3'
       *  Sum: '<S226>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s227_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S222>/Matrix Concatenate' incorporates:
       *  Bias: '<S222>/Add Constant1'
       *  Gain: '<S225>/Gain'
       *  Selector: '<S201>/Selector1'
       *  Selector: '<S222>/Selector'
       *  Selector: '<S222>/Selector1'
       *  Selector: '<S222>/Selector5'
       *  Sum: '<S225>/Subtract'
       */
      s227_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s227_iter;
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

      /* Selector: '<S222>/Selector4' */
      s227_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s227_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S222>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S222>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S222>/Assignment' incorporates:
       *  Concatenate: '<S222>/Matrix Concatenate'
       *  Selector: '<S222>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s227_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S223>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S227>/While Iterator'
       */
      s227_iter = 1;
      do {
        rtb_Switch2 = rtb_Assignment[s227_iter + 1];
        rtb_Minus_n[0] = rtb_Switch2 - rtb_Assignment[s227_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s227_iter] - rtb_Assignment[s227_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Switch2 - rtb_Assignment[s227_iter];
        rtb_Switch2 = rtb_Assignment[s227_iter + 13];
        rtb_Minus_n[1] = rtb_Switch2 - rtb_Assignment[s227_iter + 11];
        rtb_Minus_f = rtb_Assignment[s227_iter + 12];
        rtb_Add2[1] = rtb_Minus_f - rtb_Assignment[s227_iter + 14];
        rtb_Switch2_h = rtb_Switch2 - rtb_Minus_f;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Switch2_hw = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Init_o = rt_powd_snf(rtb_Switch2_hw, 2.0);
          rtb_Init = rt_powd_snf(rtb_Switch2_hw, 3.0);
          rtb_Sin4 = (rtb_Switch2_hw - (2.0 * rtb_Init_o)) + rtb_Init;
          rtb_Switch2 = rtb_Init_o - rtb_Init;
          rtb_Init = (3.0 * rtb_Init_o) - (2.0 * rtb_Init);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Sin4) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Init))
            + rtb_Assignment[s227_iter];
          rtb_Init = ((((rtb_Minus_n[1] * rtb_Sin4) + (rtb_Add2[1] * rtb_Switch2))
                       * 0.5) + (rtb_Switch2_h * rtb_Init)) + rtb_Minus_f;
          rtb_Sin4 = ((3.0 * rtb_Init_o) - (4.0 * rtb_Switch2_hw)) + 1.0;
          rtb_Switch2 = (2.0 * rtb_Switch2_hw) - (3.0 * rtb_Init_o);
          rtb_Init_o = (rtb_Switch2_hw - rtb_Init_o) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Sin4) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Init_o);
          rtb_Add_i = (((rtb_Minus_n[1] * rtb_Sin4) + (rtb_Add2[1] * rtb_Switch2))
                       * 0.5) + (rtb_Switch2_h * rtb_Init_o);
          rtb_Init_o = (6.0 * rtb_Switch2_hw) - 4.0;
          rtb_Sin4 = (-6.0 * rtb_Switch2_hw) + 2.0;
          rtb_Switch2_hw = (-12.0 * rtb_Switch2_hw) + 6.0;
          rtb_Switch2 = (((rtb_Minus_n[0] * rtb_Init_o) + (rtb_Add2[0] *
            rtb_Sin4)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Switch2_hw);
          rtb_Sin4 = (((rtb_Minus_n[1] * rtb_Init_o) + (rtb_Add2[1] * rtb_Sin4))
                      * 0.5) + (rtb_Switch2_h * rtb_Switch2_hw);
          rtb_Init_o = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Add_i), 3.0);
          rtb_Switch2_hw = fmax(1.0E-10, rtb_Init_o);
          Robot_Control_DW.Relay_Mode = ((rtb_Init_o >= 2.2204460492503131E-16) ||
            (Robot_Control_DW.Relay_Mode));
          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Init;
          if (Robot_Control_DW.Relay_Mode) {
            i = 1;
          } else {
            i = -1;
          }

          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Sin4) - (rtb_Switch2 * rtb_Add_i))
            / (rtb_Switch2_hw * ((real_T)i));
        }

        if (s227_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s227_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Switch2_hw = rtb_Switch1_n - ((real_T)s227_iter);
        rtb_Num_Segments = s227_iter;
        s227_iter++;
      } while ((rtb_Switch2_hw >= 4.0) && (s227_iter <= 3));

      /* End of Outputs for SubSystem: '<S223>/Sampling_Loop' */

      /* SignalConversion generated from: '<S206>/Position_and_Curvature' incorporates:
       *  Assignment: '<S227>/Assignment'
       *  Merge: '<S201>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S201>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S201>/If Action Subsystem' incorporates:
       *  ActionPort: '<S204>/Action Port'
       */
      /* Product: '<S204>/Product' incorporates:
       *  Selector: '<S201>/Selector'
       *  Selector: '<S201>/Selector1'
       */
      rtb_Switch2_hw = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S204>/Product1' incorporates:
       *  Selector: '<S201>/Selector'
       *  Selector: '<S201>/Selector1'
       */
      rtb_Switch1_n = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S204>/Product' incorporates:
         *  Constant: '<S204>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Switch2_hw;

        /* Product: '<S204>/Product1' incorporates:
         *  Constant: '<S204>/Constant2'
         *  Product: '<S204>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch1_n;
      }

      /* Assignment: '<S204>/Assignment' incorporates:
       *  Concatenate: '<S204>/Matrix Concatenate'
       *  Merge: '<S201>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S204>/Assignment' */

      /* SignalConversion generated from: '<S204>/Num_Segments' incorporates:
       *  Constant: '<S204>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S201>/If Action Subsystem' */
    }

    /* End of If: '<S201>/If1' */

    /* Concatenate: '<S202>/Matrix Concatenate' incorporates:
     *  Merge: '<S201>/Merge'
     *  Selector: '<S202>/Selector'
     *  Selector: '<S202>/Selector1'
     *  Selector: '<S202>/Selector3'
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

    /* End of Concatenate: '<S202>/Matrix Concatenate' */

    /* MATLAB Function: '<S202>/Distance Along Curve' incorporates:
     *  Concatenate: '<S202>/Matrix Concatenate'
     *  Selector: '<S202>/Selector4'
     *  Selector: '<S202>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s227_iter = 0; s227_iter < 149; s227_iter++) {
      /* Outputs for Iterator SubSystem: '<S223>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S227>/While Iterator'
       */
      rtb_Assignment_d[s227_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s227_iter + 1] -
         rtb_MatrixConcatenate_o[s227_iter], rtb_MatrixConcatenate_o[s227_iter +
         151] - rtb_MatrixConcatenate_o[s227_iter + 150]) +
        rtb_Assignment_d[s227_iter];

      /* End of Outputs for SubSystem: '<S223>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S202>/Distance Along Curve' */

    /* MATLAB Function: '<S202>/Find closest index to curve' incorporates:
     *  Concatenate: '<S202>/Matrix Concatenate'
     *  Selector: '<S202>/Selector4'
     *  Selector: '<S202>/Selector5'
     *  Selector: '<S253>/Selector'
     */
    for (s227_iter = 0; s227_iter < 150; s227_iter++) {
      /* Outputs for Iterator SubSystem: '<S223>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S227>/While Iterator'
       */
      distance_from_robot[s227_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s227_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s227_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S223>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s227_iter = 1;
    } else {
      s227_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s227_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s227_iter == 0) {
      rtb_Switch1_n = distance_from_robot[0];
    } else {
      rtb_Switch1_n = distance_from_robot[s227_iter - 1];
      for (rtb_Bias1_p = s227_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Switch2_hw = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_n > rtb_Switch2_hw) {
          rtb_Switch1_n = rtb_Switch2_hw;
        }
      }
    }

    s227_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s227_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_n) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S253>/Selector' incorporates:
     *  Constant: '<S253>/Constant'
     *  MATLAB Function: '<S202>/Find closest index to curve'
     *  MinMax: '<S253>/Min'
     */
    rtb_Switch2_hw = rtb_Assignment_d[((int32_T)fmin(50.0, s227_iter)) - 1];

    /* If: '<S253>/If' incorporates:
     *  RelationalOperator: '<S253>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S253>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S256>/Action Port'
       */
      /* SignalConversion generated from: '<S256>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S258>/FixPt Sum1' incorporates:
       *  Constant: '<S258>/FixPt Constant'
       */
      rtb_Switch1_n = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S256>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S256>/Selector11'
       *  Selector: '<S256>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S256>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S256>/Selector1'
       *  Selector: '<S256>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S256>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S256>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_n), &rtb_Minus_n[0], rtb_Switch2_hw,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S256>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S256>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S256>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Switch2_hw,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S253>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S253>/Latch' incorporates:
       *  ActionPort: '<S257>/Action Port'
       */
      /* SignalConversion generated from: '<S257>/In1' incorporates:
       *  UnitDelay: '<S253>/Unit Delay1'
       */
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S257>/In2' incorporates:
       *  UnitDelay: '<S253>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S253>/Latch' */
    }

    /* End of If: '<S253>/If' */

    /* MinMax: '<S200>/Min' incorporates:
     *  Lookup_n-D: '<S200>/Lookahead Distance'
     *  UnitDelay: '<S200>/Unit Delay'
     */
    rtb_Switch1_m = fmin(rtb_Switch1_m, look1_binlcpw
                         (Robot_Control_DW.UnitDelay_DSTATE_hn,
                          rtCP_LookaheadDistance_bp01Data,
                          rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S202>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S252>/While Iterator'
     */
    s252_iter = 1U;
    rtb_LogicalOperator1 = true;
    while (rtb_LogicalOperator1 && (s252_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S202>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S252>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s252_iter;
      rtb_LogicalOperator1 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s227_iter - 1] + rtb_Switch1_m)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s252_iter++;
    }

    /* End of Outputs for SubSystem: '<S202>/Find first index that meets distance target' */

    /* Switch: '<S255>/Switch' incorporates:
     *  Concatenate: '<S202>/Matrix Concatenate'
     *  Constant: '<S202>/Constant'
     *  Constant: '<S252>/Constant'
     *  Constant: '<S255>/Constant'
     *  Constant: '<S255>/Constant1'
     *  Constant: '<S255>/Constant2'
     *  Constant: '<S255>/Constant3'
     *  Logic: '<S252>/AND'
     *  MATLAB Function: '<S202>/Find closest index to curve'
     *  Math: '<S255>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S255>/Max'
     *  MinMax: '<S255>/Min'
     *  MinMax: '<S255>/Min1'
     *  Product: '<S252>/Product'
     *  Product: '<S255>/Divide'
     *  Product: '<S255>/Product'
     *  Product: '<S255>/Product1'
     *  RelationalOperator: '<S202>/Relational Operator'
     *  RelationalOperator: '<S252>/Relational Operator'
     *  RelationalOperator: '<S252>/Relational Operator1'
     *  Selector: '<S202>/Selector10'
     *  Selector: '<S202>/Selector7'
     *  Selector: '<S202>/Selector8'
     *  Selector: '<S202>/Selector9'
     *  Selector: '<S252>/Selector'
     *  Selector: '<S252>/Selector1'
     *  Selector: '<S253>/Selector'
     *  Sqrt: '<S255>/Sqrt'
     *  Sum: '<S202>/Subtract'
     *  Sum: '<S252>/Add'
     *  Sum: '<S255>/Subtract'
     *  Sum: '<S255>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Switch1_m = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
                           Spline_Last_Pose_Distance_to_Velocity_Gain, fmin
                           (rtb_Switch1_n * Spline_Velocity_Multiplier_TEST,
                            sqrt(Spline_Max_Centripital_Acceleration / fmax
        (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Switch1_m = fmin(rtb_Switch1_n * Spline_Velocity_Multiplier_TEST, sqrt
                           (Spline_Max_Centripital_Acceleration / fmax
                            (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator
        + 299], 1.0E-5)));
    }

    /* End of Switch: '<S255>/Switch' */

    /* Logic: '<S203>/OR' */
    rtb_Compare_pb = (rtb_LogicalOperator5 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S203>/Switch1' incorporates:
     *  Switch: '<S203>/Switch'
     *  UnitDelay: '<S203>/Unit Delay'
     */
    if (rtb_Compare_pb) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S203>/Constant3'
       *  SignalConversion: '<S203>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Switch2_hw = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S203>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Switch1_m;
      rtb_Switch2_hw = rtb_Merge1;
    }

    /* End of Switch: '<S203>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S203>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Switch2_hw;

    /* Selector: '<S202>/Selector6' incorporates:
     *  Concatenate: '<S202>/Matrix Concatenate'
     *  Selector: '<S202>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S202>/Selector2' incorporates:
     *  Concatenate: '<S202>/Matrix Concatenate'
     *  Selector: '<S202>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S203>/Switch2' incorporates:
     *  Sum: '<S259>/Subtract'
     *  Sum: '<S259>/Subtract1'
     *  Trigonometry: '<S259>/Atan2'
     *  UnitDelay: '<S203>/Unit Delay1'
     */
    if (rtb_Compare_pb) {
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Init_o = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S203>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S203>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Init_o;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S200>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator5;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S200>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S203>/Constant2'
     *  SignalConversion generated from: '<S200>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S203>/Constant5'
     *  SignalConversion generated from: '<S200>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S203>/Constant6'
     *  SignalConversion generated from: '<S200>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S200>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S201>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S200>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Switch1_m;

    /* Update for UnitDelay: '<S253>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_n;

    /* Update for UnitDelay: '<S253>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S203>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Switch2_hw;

    /* Update for UnitDelay: '<S203>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Init_o;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S199>/Constant1'
     *  SignalConversion generated from: '<S199>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S199>/Constant'
     *  SignalConversion generated from: '<S199>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S199>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S199>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S199>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S199>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S199>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Compare_pb;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S199>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Compare_mq;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S199>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S349>/Sign2' incorporates:
   *  UnitDelay: '<S349>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Minus_f = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Minus_f = -1.0;
  } else {
    rtb_Minus_f = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S349>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_pv = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S349>/Product1' incorporates:
   *  Signum: '<S349>/Sign1'
   *  Signum: '<S349>/Sign2'
   */
  rtb_Minus_f *= rtb_Add_pv;
  if (rtIsNaN(rtb_Minus_f)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_f, 256.0);
  }

  /* Switch: '<S349>/Switch' incorporates:
   *  Constant: '<S349>/Constant'
   *  Constant: '<S354>/Constant'
   *  Constant: '<S355>/Constant'
   *  Logic: '<S349>/or'
   *  Product: '<S349>/Product1'
   *  RelationalOperator: '<S354>/Compare'
   *  RelationalOperator: '<S355>/Compare'
   *  UnitDelay: '<S349>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S349>/Switch' */

  /* Switch: '<S360>/Init' incorporates:
   *  UnitDelay: '<S360>/FixPt Unit Delay1'
   *  UnitDelay: '<S360>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S360>/Init' */

  /* RelationalOperator: '<S356>/Compare' incorporates:
   *  Constant: '<S356>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S357>/Compare' incorporates:
   *  Constant: '<S357>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Sin4 > 0.0);

  /* Abs: '<S349>/Abs' incorporates:
   *  Sum: '<S349>/Subtract'
   *  UnitDelay: '<S349>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S349>/Switch5' incorporates:
   *  Constant: '<S349>/Constant1'
   *  Switch: '<S349>/Switch1'
   *  UnaryMinus: '<S349>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S349>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S349>/Constant4'
     *  Constant: '<S349>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S349>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S349>/Constant2'
     *  Constant: '<S349>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S349>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S349>/Lookup Table Dynamic'
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
    rtb_Minus_f = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S349>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S349>/Constant10'
     *  Constant: '<S349>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S349>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S349>/Constant7'
     *  Constant: '<S349>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S349>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S349>/Lookup Table Dynamic1'
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

    /* Switch: '<S349>/Switch3' incorporates:
     *  Constant: '<S349>/Constant1'
     *  Constant: '<S349>/Constant3'
     *  UnaryMinus: '<S349>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      rtb_Minus_f = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Minus_f = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S349>/Switch3' */
  }

  /* End of Switch: '<S349>/Switch5' */

  /* Product: '<S349>/Product' incorporates:
   *  Switch: '<S349>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Minus_f * rtb_Merge1;

  /* Sum: '<S358>/Sum1' */
  rtb_Switch1_m = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S359>/Switch2' incorporates:
   *  RelationalOperator: '<S359>/LowerRelop1'
   */
  if (!(rtb_Switch1_m > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S349>/Switch2' incorporates:
     *  Constant: '<S349>/Constant1'
     *  Switch: '<S349>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S349>/Switch4' incorporates:
       *  Constant: '<S349>/Constant1'
       */
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S349>/Switch4' incorporates:
       *  Constant: '<S349>/Constant3'
       *  UnaryMinus: '<S349>/Unary Minus1'
       */
      rtb_Switch1_n = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S349>/Switch2' */

    /* Product: '<S349>/Product2' */
    rtb_Switch1_n *= rtb_Merge1;

    /* Switch: '<S359>/Switch' incorporates:
     *  RelationalOperator: '<S359>/UpperRelop'
     */
    if (rtb_Switch1_m < rtb_Switch1_n) {
      rtb_Optimized_Module_Angle = rtb_Switch1_n;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch1_m;
    }

    /* End of Switch: '<S359>/Switch' */
  }

  /* End of Switch: '<S359>/Switch2' */

  /* Sum: '<S358>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S352>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S352>/Switch' incorporates:
     *  Constant: '<S386>/Constant3'
     *  Constant: '<S386>/Constant4'
     *  Math: '<S386>/Math Function'
     *  Sum: '<S352>/Subtract'
     *  Sum: '<S386>/Add1'
     *  Sum: '<S386>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S352>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S352>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Minus_f = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Minus_f)) || (rtIsInf(rtb_Minus_f))) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = fmod(rtb_Minus_f, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Minus_f < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Minus_f)))))) : ((int32_T)((uint8_T)rtb_Minus_f)));

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* Switch: '<S181>/Switch' incorporates:
   *  Constant: '<S169>/Constant'
   *  Constant: '<S181>/Constant'
   *  RelationalOperator: '<S169>/Compare'
   *  UnitDelay: '<S181>/Unit Delay'
   */
  if (rtb_GameState != 1) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_o;
  }

  /* Sum: '<S181>/Sum' incorporates:
   *  Constant: '<S181>/Constant4'
   *  Switch: '<S181>/Switch'
   */
  rtb_Merge1 = rtb_Minus_f + 0.02;

  /* Switch: '<S182>/Switch' incorporates:
   *  Constant: '<S174>/Constant'
   *  Constant: '<S182>/Constant'
   *  RelationalOperator: '<S174>/Compare'
   *  UnitDelay: '<S182>/Unit Delay'
   */
  if (rtb_GameState != 2) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_m;
  }

  /* MultiPortSwitch: '<S133>/Multiport Switch' incorporates:
   *  Constant: '<S133>/Constant1'
   *  Constant: '<S133>/Constant3'
   *  Constant: '<S182>/Constant4'
   *  Sum: '<S182>/Sum'
   *  Switch: '<S182>/Switch'
   */
  switch (rtb_GameState) {
   case 0:
    rtb_Sin4 = 0.0;
    break;

   case 1:
    rtb_Sin4 = rtb_Merge1;
    break;

   case 2:
    rtb_Sin4 = rtb_Minus_f + 0.02;
    break;

   default:
    rtb_Sin4 = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S133>/Multiport Switch' */

  /* If: '<S133>/If' incorporates:
   *  Constant: '<S167>/Constant'
   *  Constant: '<S168>/Constant'
   *  Constant: '<S170>/Constant'
   *  Constant: '<S171>/Constant'
   *  Constant: '<S172>/Constant'
   *  Constant: '<S173>/Constant'
   *  Inport: '<Root>/IsBlueAlliance'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S167>/Compare'
   *  RelationalOperator: '<S168>/Compare'
   *  RelationalOperator: '<S170>/Compare'
   *  RelationalOperator: '<S171>/Compare'
   *  RelationalOperator: '<S172>/Compare'
   *  RelationalOperator: '<S173>/Compare'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_n;
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

  Robot_Control_DW.If_ActiveSubsystem_n = rtAction;
  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
       *  ActionPort: '<S175>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S175>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
     *  ActionPort: '<S175>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S175>/Constant'
     *  SignalConversion generated from: '<S175>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S133>/Merge1' incorporates:
     *  Constant: '<S175>/Constant'
     *  SignalConversion generated from: '<S175>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S175>/Sum' incorporates:
     *  Constant: '<S175>/Constant1'
     *  UnitDelay: '<S175>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hb - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S175>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S175>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* SystemReset for If: '<S133>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem1);

      /* End of SystemReset for SubSystem: '<S133>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S176>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem1' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S177>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem2' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    /* Sum: '<S177>/Sum' incorporates:
     *  Constant: '<S177>/Constant1'
     *  UnitDelay: '<S177>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hz - 0.02;

    /* RelationalOperator: '<S184>/Compare' incorporates:
     *  Constant: '<S184>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S133>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S177>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S133>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S177>/Logical Operator1'
     *  Logic: '<S177>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S177>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S177>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S177>/Constant2'
       *  Sum: '<S177>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S133>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;
    }

    /* End of Switch: '<S177>/Switch' */

    /* Update for UnitDelay: '<S177>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hz = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem2' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      /* SystemReset for If: '<S133>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem3);

      /* End of SystemReset for SubSystem: '<S133>/If Action Subsystem3' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem3' */
    break;

   case 4:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S179>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S179>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem4' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    /* Sum: '<S179>/Sum' incorporates:
     *  Constant: '<S179>/Constant1'
     *  UnitDelay: '<S179>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_di - 0.02;

    /* RelationalOperator: '<S186>/Compare' incorporates:
     *  Constant: '<S186>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S133>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S179>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S133>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S179>/Logical Operator1'
     *  Logic: '<S179>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S179>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S179>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S179>/Constant2'
       *  Sum: '<S179>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S179>/Constant3'
       *  Sum: '<S179>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S179>/Switch' */

    /* Update for UnitDelay: '<S179>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem4' */
    break;

   default:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S180>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S180>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem5' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S180>/Constant'
     *  SignalConversion generated from: '<S180>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S133>/Merge1' incorporates:
     *  Constant: '<S180>/Constant'
     *  SignalConversion generated from: '<S180>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S180>/Sum' incorporates:
     *  Constant: '<S180>/Constant1'
     *  UnitDelay: '<S180>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_du - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S180>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S180>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_du = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S133>/If' */

  /* If: '<S188>/If' incorporates:
   *  If: '<S189>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S188>/Blue' incorporates:
     *  ActionPort: '<S190>/Action Port'
     */
    /* Merge: '<S188>/Merge' incorporates:
     *  Constant: '<S190>/BlueAllianceZoneX'
     *  Logic: '<S190>/AND'
     *  RelationalOperator: '<S190>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S188>/Blue' */

    /* Outputs for IfAction SubSystem: '<S189>/Blue' incorporates:
     *  ActionPort: '<S192>/Action Port'
     */
    /* Merge: '<S189>/Merge' incorporates:
     *  Constant: '<S192>/BlueAllianceZoneX'
     *  RelationalOperator: '<S192>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S189>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S188>/Red' incorporates:
     *  ActionPort: '<S191>/Action Port'
     */
    /* Merge: '<S188>/Merge' incorporates:
     *  Constant: '<S191>/RedAllianceZoneX'
     *  Logic: '<S191>/AND'
     *  RelationalOperator: '<S191>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S188>/Red' */

    /* Outputs for IfAction SubSystem: '<S189>/Red' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    /* Merge: '<S189>/Merge' incorporates:
     *  Constant: '<S193>/RedAllianceZoneX'
     *  RelationalOperator: '<S193>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S189>/Red' */
  }

  /* End of If: '<S188>/If' */

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
   *  Constant: '<S187>/Constant3'
   *  Constant: '<S187>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S187>/Math Function'
   *  Sum: '<S137>/Subtract'
   *  Sum: '<S187>/Add1'
   *  Sum: '<S187>/Add2'
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
  rtb_Compare_pb = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S137>/AND2' incorporates:
   *  Logic: '<S137>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_pb);

  /* RelationalOperator: '<S134>/Compare' incorporates:
   *  Constant: '<S134>/Constant'
   *  Inport: '<Root>/Gamepad_RT'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_RT != 0.0);

  /* SignalConversion: '<S137>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S137>/AND3' incorporates:
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Ready_to_Pass = (((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Compare_pb) && (Robot_Control_DW.UnitDelay_5_DSTATE != 0.0));

  /* Chart: '<S12>/Shooter_Transfer_Feeder Chart' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Logic: '<S137>/AND4'
   */
  if (Robot_Control_DW.is_active_c2_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c2_Robot_Control = 1U;
    Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Not_Shooting;
    Robot_Control_B.RB_Shooter_Active = false;
    Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
    Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
    Robot_Control_B.RB_Transfer_Init = 0.0;
  } else if (Robot_Control_DW.is_c2_Robot_Control ==
             Robot_Control_IN_Not_Shooting) {
    Robot_Control_B.RB_Shooter_Active = false;
    Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
    Robot_Control_B.RB_Transfer_Init = 0.0;
    if ((rtb_Button_Spinup_Enable || rtb_Compare_ky) || rtb_LogicalOperator1) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.RB_Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
      Robot_Control_B.RB_Transfer_Init = 1.0;
    }
  } else {
    /* case IN_Shooting: */
    Robot_Control_B.RB_Shooter_Active = true;
    rtb_Compare_mq = !rtb_Compare_ky;
    rtb_LogicalOperator5 = !rtb_LogicalOperator1;
    if (((!rtb_Button_Spinup_Enable) && rtb_Compare_mq) && rtb_LogicalOperator5)
    {
      Robot_Control_DW.is_Shooting = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Not_Shooting;
      Robot_Control_B.RB_Shooter_Active = false;
      Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
      Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
      Robot_Control_B.RB_Transfer_Init = 0.0;
    } else {
      switch (Robot_Control_DW.is_Shooting) {
       case Robot_Control_IN_Feeder:
        Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
        Robot_Control_B.RB_Transfer_Init = 0.0;
        if ((rtb_Compare_mq && rtb_LogicalOperator5) ||
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
        if ((rtb_Compare_ky && ((Robot_Control_B.RB_Ready_to_Score) ||
                                (Robot_Control_B.RB_Ready_to_Pass))) ||
            (rtb_LogicalOperator1 && ((Robot_Control_B.RB_Logic_Shooter_Speed) &&
              (Robot_Control_B.RB_Logic_Hood_Pos)))) {
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
        } else if ((rtb_Compare_mq && rtb_LogicalOperator5) ||
                   ((Robot_Control_DW.Feeder_Loops_Shooting * 0.02) >
                    Feeder_Max_Pulsetime)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
          Robot_Control_B.RB_Transfer_Init = 1.0;
        }
        break;
      }
    }
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* RelationalOperator: '<S135>/Compare' incorporates:
   *  Constant: '<S135>/Constant'
   *  Inport: '<Root>/Gamepad_B2_B'
   */
  rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_B2_B != 0.0);

  /* If: '<S132>/If' incorporates:
   *  Constant: '<S142>/Constant'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Outputs for IfAction SubSystem: '<S132>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S142>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S143>/While Iterator'
     */
    /* SignalConversion generated from: '<S144>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S149>/Constant1'
     *  Constant: '<S149>/Constant10'
     *  Constant: '<S149>/Constant2'
     *  Constant: '<S149>/Constant5'
     *  Constant: '<S149>/Constant6'
     *  Constant: '<S149>/Constant7'
     *  Constant: '<S149>/Constant8'
     *  Constant: '<S149>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S142>/Iterate_Shot_Target' */

    /* SignalConversion generated from: '<S145>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S145>/Constant1'
     *  Constant: '<S145>/Constant10'
     *  Constant: '<S145>/Constant2'
     *  Constant: '<S145>/Constant5'
     *  Constant: '<S145>/Constant6'
     *  Constant: '<S145>/Constant7'
     *  Constant: '<S145>/Constant8'
     *  Constant: '<S145>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_o3[0] = Rebuilt_Shoot_Hood_Pos_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Rebuilt_Shoot_Hood_Pos_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Rebuilt_Shoot_Hood_Pos_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Rebuilt_Shoot_Hood_Pos_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Rebuilt_Shoot_Hood_Pos_4;
    rtb_TmpSignalConversionAtLoo_o3[5] = Rebuilt_Shoot_Hood_Pos_5;
    rtb_TmpSignalConversionAtLoo_o3[6] = Rebuilt_Shoot_Hood_Pos_6;
    rtb_TmpSignalConversionAtLoo_o3[7] = Rebuilt_Shoot_Hood_Pos_7;

    /* SignalConversion generated from: '<S144>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S144>/Constant1'
     *  Constant: '<S144>/Constant10'
     *  Constant: '<S144>/Constant2'
     *  Constant: '<S144>/Constant5'
     *  Constant: '<S144>/Constant6'
     *  Constant: '<S144>/Constant7'
     *  Constant: '<S144>/Constant8'
     *  Constant: '<S144>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ov[0] = Rebuilt_Shoot_Gyro_Err_0;
    rtb_TmpSignalConversionAtLoo_ov[1] = Rebuilt_Shoot_Gyro_Err_1;
    rtb_TmpSignalConversionAtLoo_ov[2] = Rebuilt_Shoot_Gyro_Err_2;
    rtb_TmpSignalConversionAtLoo_ov[3] = Rebuilt_Shoot_Gyro_Err_3;
    rtb_TmpSignalConversionAtLoo_ov[4] = Rebuilt_Shoot_Gyro_Err_4;
    rtb_TmpSignalConversionAtLoo_ov[5] = Rebuilt_Shoot_Gyro_Err_5;
    rtb_TmpSignalConversionAtLoo_ov[6] = Rebuilt_Shoot_Gyro_Err_6;
    rtb_TmpSignalConversionAtLoo_ov[7] = Rebuilt_Shoot_Gyro_Err_7;

    /* SignalConversion generated from: '<S146>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S158>/Constant1'
     *  Constant: '<S158>/Constant10'
     *  Constant: '<S158>/Constant2'
     *  Constant: '<S158>/Constant5'
     *  Constant: '<S158>/Constant6'
     *  Constant: '<S158>/Constant7'
     *  Constant: '<S158>/Constant8'
     *  Constant: '<S158>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_lg[0] = Rebuilt_Shoot_Shooter_Spd_0;
    rtb_TmpSignalConversionAtLoo_lg[1] = Rebuilt_Shoot_Shooter_Spd_1;
    rtb_TmpSignalConversionAtLoo_lg[2] = Rebuilt_Shoot_Shooter_Spd_2;
    rtb_TmpSignalConversionAtLoo_lg[3] = Rebuilt_Shoot_Shooter_Spd_3;
    rtb_TmpSignalConversionAtLoo_lg[4] = Rebuilt_Shoot_Shooter_Spd_4;
    rtb_TmpSignalConversionAtLoo_lg[5] = Rebuilt_Shoot_Shooter_Spd_5;
    rtb_TmpSignalConversionAtLoo_lg[6] = Rebuilt_Shoot_Shooter_Spd_6;
    rtb_TmpSignalConversionAtLoo_lg[7] = Rebuilt_Shoot_Shooter_Spd_7;

    /* SignalConversion generated from: '<S146>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S157>/Constant1'
     *  Constant: '<S157>/Constant10'
     *  Constant: '<S157>/Constant2'
     *  Constant: '<S157>/Constant5'
     *  Constant: '<S157>/Constant6'
     *  Constant: '<S157>/Constant7'
     *  Constant: '<S157>/Constant8'
     *  Constant: '<S157>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ix[0] = Rebuilt_Shoot_Shooter_Spd_I_0;
    rtb_TmpSignalConversionAtLoo_ix[1] = Rebuilt_Shoot_Shooter_Spd_I_1;
    rtb_TmpSignalConversionAtLoo_ix[2] = Rebuilt_Shoot_Shooter_Spd_I_2;
    rtb_TmpSignalConversionAtLoo_ix[3] = Rebuilt_Shoot_Shooter_Spd_I_3;
    rtb_TmpSignalConversionAtLoo_ix[4] = Rebuilt_Shoot_Shooter_Spd_I_4;
    rtb_TmpSignalConversionAtLoo_ix[5] = Rebuilt_Shoot_Shooter_Spd_I_5;
    rtb_TmpSignalConversionAtLoo_ix[6] = Rebuilt_Shoot_Shooter_Spd_I_6;
    rtb_TmpSignalConversionAtLoo_ix[7] = Rebuilt_Shoot_Shooter_Spd_I_7;

    /* Switch: '<S148>/Switch4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S148>/Logical Operator'
     *  Switch: '<S148>/Switch5'
     *  Switch: '<S148>/Switch6'
     */
    if ((Robot_Control_B.Is_Outside_Alliance_Zone) || rtb_LogicalOperator1) {
      /* Switch: '<S148>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S148>/Switch4' incorporates:
         *  Constant: '<S148>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S148>/Switch4' incorporates:
         *  Constant: '<S148>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S148>/Switch2' */

      /* Switch: '<S148>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S148>/Switch6' incorporates:
         *  Constant: '<S148>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S148>/Switch6' incorporates:
         *  Constant: '<S148>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S148>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S148>/Switch5' incorporates:
         *  Constant: '<S148>/Constant8'
         *  Switch: '<S148>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S148>/Switch4' incorporates:
         *  Constant: '<S148>/Constant9'
         *  Switch: '<S148>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S148>/Switch6' incorporates:
       *  Constant: '<S148>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* End of Switch: '<S148>/Switch4' */

    /* Outputs for Iterator SubSystem: '<S142>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S143>/While Iterator'
     */
    Iteration_Number = 1U;

    /* InitializeConditions for Memory: '<S143>/Memory1' */
    rtb_Switch1_n = 0.0;

    /* InitializeConditions for Memory: '<S143>/Memory2' */
    rtb_Switch2_hw = 0.0;

    /* InitializeConditions for Memory: '<S143>/Memory3' */
    rtb_Init_o = 0.0;

    /* InitializeConditions for Memory: '<S143>/Memory' */
    rtb_Compare_ky = true;
    rtb_LogicalOperator1 = true;

    /* SignalConversion generated from: '<S151>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S142>/Constant'
     *  Constant: '<S151>/Constant'
     *  Constant: '<S151>/Constant1'
     *  Constant: '<S151>/Constant11'
     *  Constant: '<S151>/Constant2'
     *  Constant: '<S151>/Constant3'
     *  Constant: '<S151>/Constant4'
     *  Constant: '<S151>/Constant5'
     *  Constant: '<S151>/Constant6'
     */
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;

    /* SignalConversion generated from: '<S151>/Lookup Table Dynamic' */
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_LogicalOperator1 && (Iteration_Number <= 10)) {
      /* Switch: '<S152>/Switch' incorporates:
       *  Memory: '<S143>/Memory1'
       *  Memory: '<S143>/Memory2'
       *  Switch: '<S152>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Switch1_n;
        rtb_Switch2 = rtb_Switch2_hw;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Switch2 = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S152>/Switch' */

      /* Math: '<S150>/Hypot' incorporates:
       *  Sum: '<S150>/Subtract'
       *  Sum: '<S150>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_Switch2 -
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
      rtb_Switch2_hw = rtb_TOF - rtb_Init_o;

      /* Sum: '<S153>/Add' incorporates:
       *  Gain: '<S153>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S153>/Product'
       *  Sum: '<S153>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Switch2_hw *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S153>/Add1' incorporates:
       *  Gain: '<S153>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S153>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Switch2_hw *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Switch2;

      /* Memory: '<S143>/Memory' */
      rtb_LogicalOperator1 = rtb_Compare_ky;

      /* Update for Memory: '<S143>/Memory1' */
      rtb_Switch1_n = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S143>/Memory2' */
      rtb_Switch2_hw = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S143>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S143>/Memory' incorporates:
       *  Constant: '<S155>/Constant'
       *  Math: '<S154>/Hypot'
       *  RelationalOperator: '<S155>/Compare'
       *  Sum: '<S154>/Subtract'
       *  Sum: '<S154>/Subtract1'
       */
      rtb_Compare_ky = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X -
        rtb_Sin4, Robot_Control_B.RB_Desired_Target_Y - rtb_Switch2) >=
                        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S142>/Iterate_Shot_Target' */

    /* Merge: '<S132>/Merge2' incorporates:
     *  S-Function (sfix_look1_dyn): '<S145>/Lookup Table Dynamic'
     */
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

    /* S-Function (sfix_look1_dyn): '<S144>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S144>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_Abs2), &rtb_TmpSignalConversionAtLoo_ov[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);

    /* S-Function (sfix_look1_dyn): '<S146>/Lookup Table Dynamic' */
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

    /* S-Function (sfix_look1_dyn): '<S146>/Lookup Table Dynamic1' */
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

    /* Switch: '<S146>/Switch' incorporates:
     *  Constant: '<S146>/Constant'
     *  Constant: '<S146>/Constant1'
     *  Sum: '<S146>/Add'
     *  UnitDelay: '<S146>/Unit Delay'
     */
    if (Robot_Control_B.RB_Transfer_Init != 0.0) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    /* End of Switch: '<S146>/Switch' */

    /* Switch: '<S146>/Switch1' incorporates:
     *  Constant: '<S146>/Constant2'
     *  RelationalOperator: '<S146>/GreaterThan'
     */
    if (rtb_Switch1_n < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S132>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S132>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    /* End of Switch: '<S146>/Switch1' */

    /* Merge: '<S132>/Merge3' incorporates:
     *  Gain: '<S156>/Gain1'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 * rtb_Abs2;

    /* Merge: '<S132>/Merge' incorporates:
     *  Constant: '<S163>/Constant'
     *  Constant: '<S163>/Shooter Assembly Offset in Robot'
     *  Constant: '<S163>/Shooter Assembly Offset in Robot1'
     *  Gain: '<S166>/Gain1'
     *  MinMax: '<S163>/Max'
     *  Product: '<S163>/Divide'
     *  Sum: '<S163>/Add'
     *  Sum: '<S163>/Subtract1'
     *  Sum: '<S163>/Subtract2'
     *  Trigonometry: '<S163>/Atan2'
     *  Trigonometry: '<S163>/Tanh1'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = (rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      atan(-0.074675999999999992 / fmax(Robot_Control_B.RB_Desired_Shot_Distance,
      0.001))) + (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);

    /* Abs: '<S147>/Abs2' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Abs2 = fabs(Robot_Control_U.Gyro_Angle_Field_rad);

    /* If: '<S161>/If' incorporates:
     *  Abs: '<S147>/Abs'
     *  Constant: '<S159>/Constant'
     *  Constant: '<S159>/Constant1'
     *  Sum: '<S159>/Subtract3'
     *  Sum: '<S159>/Subtract4'
     *  Switch: '<S165>/Switch'
     *  Trigonometry: '<S159>/Atan1'
     */
    if (Robot_Control_B.RB_Desired_Target_Y > 4.0) {
      /* Outputs for IfAction SubSystem: '<S161>/If Action Subsystem' incorporates:
       *  ActionPort: '<S164>/Action Port'
       */
      /* Switch: '<S164>/Switch' incorporates:
       *  Constant: '<S147>/Constant10'
       *  Constant: '<S147>/Constant11'
       *  Constant: '<S159>/Constant3'
       *  Sum: '<S159>/Subtract5'
       *  Sum: '<S159>/Subtract6'
       *  Sum: '<S159>/Subtract7'
       *  Sum: '<S159>/Subtract8'
       *  Trigonometry: '<S159>/Atan3'
       *  Trigonometry: '<S159>/Atan4'
       */
      if (Robot_Control_B.RB_Desired_Target_X > 8.0) {
        rtb_Add_pv = rt_atan2d_snf(Field_Width - Robot_Control_B.KF_Position_Y,
          Field_Length - Robot_Control_B.KF_Position_X);
      } else {
        rtb_Add_pv = rt_atan2d_snf(Field_Width - Robot_Control_B.KF_Position_Y,
          0.0 - Robot_Control_B.KF_Position_X);
      }

      /* End of Switch: '<S164>/Switch' */
      /* End of Outputs for SubSystem: '<S161>/If Action Subsystem' */

      /* Outputs for IfAction SubSystem: '<S161>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S165>/Action Port'
       */
    } else if (Robot_Control_B.RB_Desired_Target_X > 8.0) {
      /* Switch: '<S165>/Switch' incorporates:
       *  Constant: '<S147>/Constant10'
       *  Constant: '<S159>/Constant2'
       *  Sum: '<S159>/Subtract1'
       *  Sum: '<S159>/Subtract2'
       *  Trigonometry: '<S159>/Atan2'
       */
      rtb_Add_pv = rt_atan2d_snf(0.0 - Robot_Control_B.KF_Position_Y,
        Field_Length - Robot_Control_B.KF_Position_X);
    } else {
      rtb_Add_pv = rt_atan2d_snf(0.0 - Robot_Control_B.KF_Position_Y, 0.0 -
        Robot_Control_B.KF_Position_X);

      /* End of Outputs for SubSystem: '<S161>/If Action Subsystem1' */
    }

    rtb_Switch2_hw = fabs(rtb_Add_pv);

    /* End of If: '<S161>/If' */

    /* Trigonometry: '<S160>/Atan1' incorporates:
     *  Constant: '<S147>/Constant2'
     *  Constant: '<S147>/Constant3'
     *  Sum: '<S160>/Subtract3'
     *  Sum: '<S160>/Subtract4'
     *  Switch: '<S162>/Switch'
     *  Switch: '<S162>/Switch1'
     */
    rtb_Init_o = rt_atan2d_snf(Blue_Hub_LeftY - Robot_Control_B.KF_Position_Y,
      Blue_Hub_LeftX - Robot_Control_B.KF_Position_X);

    /* Trigonometry: '<S160>/Atan2' incorporates:
     *  Constant: '<S147>/Constant4'
     *  Constant: '<S147>/Constant5'
     *  Sum: '<S160>/Subtract1'
     *  Sum: '<S160>/Subtract2'
     *  Switch: '<S162>/Switch2'
     *  Switch: '<S162>/Switch3'
     */
    rtb_Sin4 = rt_atan2d_snf(Blue_Hub_RightX - Robot_Control_B.KF_Position_Y,
      Blue_Hub_RightY - Robot_Control_B.KF_Position_X);

    /* Switch: '<S160>/Switch' incorporates:
     *  Abs: '<S160>/Abs'
     *  Abs: '<S160>/Abs1'
     *  RelationalOperator: '<S160>/GreaterThan'
     */
    if (fabs(rtb_Init_o) < fabs(rtb_Sin4)) {
      rtb_Sin4 = rtb_Init_o;
    }

    /* Abs: '<S147>/Abs1' incorporates:
     *  Switch: '<S160>/Switch'
     */
    rtb_Init_o = fabs(rtb_Sin4);

    /* Switch: '<S147>/Switch' incorporates:
     *  RelationalOperator: '<S147>/Less Than'
     */
    if (rtb_Switch2_hw < rtb_Init_o) {
      rtb_Init_o = rtb_Switch2_hw;
    }

    /* Merge: '<S132>/Merge4' incorporates:
     *  DataTypeConversion: '<S147>/Cast To Double'
     *  Logic: '<S147>/NOT'
     *  Logic: '<S147>/OR'
     *  RelationalOperator: '<S147>/GreaterThan'
     *  Switch: '<S147>/Switch'
     */
    Robot_Control_B.Can_Pass = ((rtb_Init_o < rtb_Abs2) ||
      (!rtb_Button_Spinup_Enable));

    /* Update for UnitDelay: '<S146>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S132>/Desired Shooting Parameters Math' */
  } else {
    /* Outputs for IfAction SubSystem: '<S132>/Shooter Not Active' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    /* Merge: '<S132>/Merge' incorporates:
     *  Constant: '<S141>/Constant2'
     *  SignalConversion generated from: '<S141>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;

    /* Merge: '<S132>/Merge1' incorporates:
     *  Constant: '<S141>/Constant'
     *  SignalConversion generated from: '<S141>/Desired_Shooter_Speed'
     */
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;

    /* Merge: '<S132>/Merge2' incorporates:
     *  Constant: '<S141>/Constant3'
     *  SignalConversion generated from: '<S141>/Desired_Hood_Pos'
     */
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;

    /* Merge: '<S132>/Merge3' incorporates:
     *  Constant: '<S141>/Constant1'
     *  SignalConversion generated from: '<S141>/Allowed_Shoot_Gyro_Error_rad'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* Merge: '<S132>/Merge4' incorporates:
     *  Constant: '<S141>/Constant4'
     *  SignalConversion generated from: '<S141>/Can_Pass'
     */
    Robot_Control_B.Can_Pass = 1.0;

    /* End of Outputs for SubSystem: '<S132>/Shooter Not Active' */
  }

  /* End of If: '<S132>/If' */

  /* Logic: '<S12>/AND' incorporates:
   *  Logic: '<S12>/NOT'
   */
  rtb_Button_Spinup_Enable = ((Robot_Control_B.RB_Shooter_Active) &&
    (!rtb_Button_Spinup_Enable));

  /* Switch: '<S3>/Switch1' incorporates:
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Switch: '<S3>/Switch3'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Add_pv = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;
    rtb_Add_i = Robot_Control_U.Gyro_Angle_Field_rad;
  } else {
    rtb_Add_pv = Robot_Control_B.Steering_Abs_Cmd_SPF;
    rtb_Add_i = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* Sum: '<S381>/Add1' incorporates:
   *  Constant: '<S381>/Constant3'
   *  Constant: '<S381>/Constant4'
   *  Math: '<S381>/Math Function'
   *  Sum: '<S380>/Sum'
   *  Sum: '<S381>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_pv - rtb_Add_i) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Gain: '<S384>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle_p;

  /* Abs: '<S363>/Abs1' */
  rtb_Init_o = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S383>/Sum1' incorporates:
   *  Constant: '<S380>/Constant2'
   *  Product: '<S383>/Product'
   *  Sum: '<S383>/Sum'
   *  UnitDelay: '<S383>/Unit Delay1'
   */
  rtb_Abs2 = ((rtb_Optimized_Module_Angle_p - Robot_Control_DW.UnitDelay1_DSTATE)
              * Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S380>/Product' incorporates:
   *  Constant: '<S380>/Constant3'
   */
  rtb_Switch1_n = rtb_Abs2 * Steering_Heading_Control_D;

  /* Sum: '<S382>/Diff' incorporates:
   *  UnitDelay: '<S382>/UD'
   *
   * Block description for '<S382>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S382>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Switch1_n - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S380>/Saturation' */
  if (rtb_Add_pv > Steering_Heading_Control_D_UL) {
    rtb_Add_pv = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Heading_Control_D_LL) {
    rtb_Add_pv = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S380>/Add' incorporates:
   *  Gain: '<S380>/Gain1'
   *  Saturate: '<S380>/Saturation'
   */
  rtb_Switch2 = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_pv;

  /* Sum: '<S380>/Subtract' incorporates:
   *  Constant: '<S380>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Switch2;

  /* Sum: '<S380>/Sum2' incorporates:
   *  Gain: '<S380>/Gain2'
   *  UnitDelay: '<S380>/Unit Delay'
   */
  rtb_Switch2_hw = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S385>/Switch2' incorporates:
   *  RelationalOperator: '<S385>/LowerRelop1'
   */
  if (!(rtb_Switch2_hw > rtb_Sin4)) {
    /* Sum: '<S380>/Subtract1' incorporates:
     *  Constant: '<S380>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Switch2;

    /* Switch: '<S385>/Switch' incorporates:
     *  RelationalOperator: '<S385>/UpperRelop'
     */
    if (!(rtb_Switch2_hw < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2_hw;
    }

    /* End of Switch: '<S385>/Switch' */
  }

  /* End of Switch: '<S385>/Switch2' */

  /* Saturate: '<S380>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Switch2_hw = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Switch2_hw = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch2_hw = rtb_Sin4;
  }

  /* End of Saturate: '<S380>/Saturation1' */

  /* Sum: '<S380>/Add1' */
  rtb_Add_pv = rtb_Switch2 + rtb_Switch2_hw;

  /* Saturate: '<S380>/Saturation2' */
  if (rtb_Add_pv > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S380>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_pv < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S380>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S380>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_pv;
  }

  /* End of Saturate: '<S380>/Saturation2' */

  /* Abs: '<S363>/Abs' */
  rtb_Sin4 = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S363>/Add dither' */
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

  /* End of Chart: '<S363>/Add dither' */

  /* Switch: '<S363>/Switch' incorporates:
   *  Constant: '<S363>/Constant'
   *  Constant: '<S379>/Constant'
   *  Product: '<S363>/Product'
   *  RelationalOperator: '<S379>/Compare'
   *  Signum: '<S363>/Sign'
   */
  if (rtb_Sin4 > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S363>/Sign' */
    if (rtIsNaN(Robot_Control_B.Steering_Heading_PID)) {
      rtb_Add_pv = (rtNaN);
    } else if (Robot_Control_B.Steering_Heading_PID < 0.0) {
      rtb_Add_pv = -1.0;
    } else {
      rtb_Add_pv = (Robot_Control_B.Steering_Heading_PID > 0.0);
    }

    rtb_Optimized_Module_Angle_p = Robot_Control_B.abs_Cmd_Out * rtb_Add_pv;
  } else {
    rtb_Optimized_Module_Angle_p = 0.0;
  }

  /* End of Switch: '<S363>/Switch' */

  /* Signum: '<S362>/Sign2' incorporates:
   *  UnitDelay: '<S362>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_pv = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S362>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Add_i = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S362>/Product1' incorporates:
   *  Signum: '<S362>/Sign1'
   *  Signum: '<S362>/Sign2'
   */
  rtb_Add_pv *= rtb_Add_i;
  if (rtIsNaN(rtb_Add_pv)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_pv, 256.0);
  }

  /* Switch: '<S362>/Switch' incorporates:
   *  Constant: '<S362>/Constant'
   *  Constant: '<S371>/Constant'
   *  Constant: '<S372>/Constant'
   *  Logic: '<S362>/or'
   *  Product: '<S362>/Product1'
   *  RelationalOperator: '<S371>/Compare'
   *  RelationalOperator: '<S372>/Compare'
   *  UnitDelay: '<S362>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S362>/Switch' */

  /* Switch: '<S377>/Init' incorporates:
   *  UnitDelay: '<S377>/FixPt Unit Delay1'
   *  UnitDelay: '<S377>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S377>/Init' */

  /* RelationalOperator: '<S373>/Compare' incorporates:
   *  Constant: '<S373>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S374>/Compare' incorporates:
   *  Constant: '<S374>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S362>/Abs' incorporates:
   *  Sum: '<S362>/Subtract'
   *  UnitDelay: '<S362>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S362>/Switch5' incorporates:
   *  Constant: '<S362>/Constant1'
   *  Switch: '<S362>/Switch1'
   *  UnaryMinus: '<S362>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    /* SignalConversion generated from: '<S362>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S362>/Constant4'
     *  Constant: '<S362>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S362>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S362>/Constant2'
     *  Constant: '<S362>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S362>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S362>/Lookup Table Dynamic'
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
    rtb_Add_pv = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S362>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S362>/Constant10'
     *  Constant: '<S362>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S362>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S362>/Constant7'
     *  Constant: '<S362>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S362>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S362>/Lookup Table Dynamic1'
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

    /* Switch: '<S362>/Switch3' incorporates:
     *  Constant: '<S362>/Constant1'
     *  Constant: '<S362>/Constant3'
     *  UnaryMinus: '<S362>/Unary Minus'
     */
    if (rtb_LogicalOperator1) {
      rtb_Add_pv = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_pv = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S362>/Switch3' */
  }

  /* End of Switch: '<S362>/Switch5' */

  /* Product: '<S362>/Product' incorporates:
   *  Switch: '<S362>/Switch1'
   */
  rtb_Switch1_m = rtb_Add_pv * rtb_Sin4;

  /* Sum: '<S375>/Sum1' */
  rtb_Switch2 = rtb_MatrixConcatenate_b_idx_0 - rtb_Init_o;

  /* Switch: '<S376>/Switch2' incorporates:
   *  RelationalOperator: '<S376>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_Switch1_m)) {
    /* Switch: '<S362>/Switch2' incorporates:
     *  Constant: '<S362>/Constant1'
     *  Constant: '<S362>/Constant3'
     *  Switch: '<S362>/Switch4'
     *  UnaryMinus: '<S362>/Unary Minus1'
     */
    if (rtb_Compare_ky) {
      rtb_Add_pv = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S362>/Switch4' incorporates:
       *  Constant: '<S362>/Constant1'
       */
      rtb_Add_pv = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_pv = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S362>/Product2' incorporates:
     *  Switch: '<S362>/Switch2'
     */
    rtb_Init = rtb_Add_pv * rtb_Sin4;

    /* Switch: '<S376>/Switch' incorporates:
     *  RelationalOperator: '<S376>/UpperRelop'
     */
    if (rtb_Switch2 < rtb_Init) {
      rtb_Switch1_m = rtb_Init;
    } else {
      rtb_Switch1_m = rtb_Switch2;
    }

    /* End of Switch: '<S376>/Switch' */
  }

  /* End of Switch: '<S376>/Switch2' */

  /* Sum: '<S375>/Sum' */
  rtb_Init_o += rtb_Switch1_m;

  /* Signum: '<S361>/Sign2' incorporates:
   *  UnitDelay: '<S361>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_pv = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S361>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S361>/Product1' incorporates:
   *  Signum: '<S361>/Sign1'
   *  Signum: '<S361>/Sign2'
   */
  rtb_Add_pv *= rtb_Add_i;
  if (rtIsNaN(rtb_Add_pv)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_pv, 256.0);
  }

  /* Switch: '<S361>/Switch' incorporates:
   *  Constant: '<S361>/Constant'
   *  Constant: '<S364>/Constant'
   *  Constant: '<S365>/Constant'
   *  Logic: '<S361>/or'
   *  Product: '<S361>/Product1'
   *  RelationalOperator: '<S364>/Compare'
   *  RelationalOperator: '<S365>/Compare'
   *  UnitDelay: '<S361>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S361>/Switch' */

  /* Switch: '<S370>/Init' incorporates:
   *  UnitDelay: '<S370>/FixPt Unit Delay1'
   *  UnitDelay: '<S370>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S370>/Init' */

  /* RelationalOperator: '<S366>/Compare' incorporates:
   *  Constant: '<S366>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S367>/Compare' incorporates:
   *  Constant: '<S367>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S361>/Abs' incorporates:
   *  Sum: '<S361>/Subtract'
   *  UnitDelay: '<S361>/Unit Delay'
   */
  rtb_Switch2 = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                     Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S361>/Switch1' incorporates:
   *  Constant: '<S361>/Constant1'
   *  Switch: '<S361>/Switch3'
   *  Switch: '<S361>/Switch5'
   *  UnaryMinus: '<S361>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S361>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S361>/Constant1'
     *  Constant: '<S361>/Constant4'
     *  Constant: '<S361>/Constant6'
     *  UnaryMinus: '<S361>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S361>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S361>/Constant2'
     *  Constant: '<S361>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S361>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S361>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_Switch2, &rtb_Minus_n[0], 1U);
    rtb_Switch2 = rtb_LookupTableDynamic_p;
  } else {
    if (rtb_LogicalOperator1) {
      /* Switch: '<S361>/Switch3' incorporates:
       *  Constant: '<S361>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S361>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S361>/Constant1'
     *  Constant: '<S361>/Constant10'
     *  Constant: '<S361>/Constant8'
     *  UnaryMinus: '<S361>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S361>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S361>/Constant7'
     *  Constant: '<S361>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S361>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S361>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_Switch2, &rtb_Minus_n[0], 1U);
    rtb_Switch2 = rtb_LookupTableDynamic1_g;
  }

  /* End of Switch: '<S361>/Switch1' */

  /* Product: '<S361>/Product' */
  rtb_Sin4 *= rtb_Switch2;

  /* Sum: '<S368>/Sum1' */
  rtb_Init = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S369>/Switch2' incorporates:
   *  RelationalOperator: '<S369>/LowerRelop1'
   */
  if (!(rtb_Init > rtb_Sin4)) {
    /* Switch: '<S361>/Switch2' incorporates:
     *  Constant: '<S361>/Constant1'
     *  Switch: '<S361>/Switch4'
     */
    if (rtb_Compare_ky) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S361>/Switch4' incorporates:
       *  Constant: '<S361>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S361>/Switch4' incorporates:
       *  Constant: '<S361>/Constant3'
       *  UnaryMinus: '<S361>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S361>/Switch2' */

    /* Product: '<S361>/Product2' */
    rtb_Sin4 *= rtb_Switch2;

    /* Switch: '<S369>/Switch' incorporates:
     *  RelationalOperator: '<S369>/UpperRelop'
     */
    if (!(rtb_Init < rtb_Sin4)) {
      rtb_Sin4 = rtb_Init;
    }

    /* End of Switch: '<S369>/Switch' */
  }

  /* End of Switch: '<S369>/Switch2' */

  /* Sum: '<S368>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S351>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (rtb_Button_Spinup_Enable || (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S351>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S351>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S351>/Switch' */

  /* Fcn: '<S394>/r->x' incorporates:
   *  Fcn: '<S399>/r->x'
   *  Fcn: '<S404>/r->x'
   *  Fcn: '<S409>/r->x'
   */
  rtb_Init = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S388>/Add' incorporates:
   *  Fcn: '<S394>/r->x'
   *  Fcn: '<S395>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Init;

  /* Fcn: '<S394>/theta->y' incorporates:
   *  Fcn: '<S399>/theta->y'
   *  Fcn: '<S404>/theta->y'
   *  Fcn: '<S409>/theta->y'
   */
  rtb_Switch2 = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S388>/Add' incorporates:
   *  Fcn: '<S394>/theta->y'
   *  Fcn: '<S395>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2;

  /* Sum: '<S389>/Add' incorporates:
   *  Fcn: '<S400>/r->x'
   *  Fcn: '<S400>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Init;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2;

  /* Sum: '<S390>/Add' incorporates:
   *  Fcn: '<S405>/r->x'
   *  Fcn: '<S405>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Init;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2;

  /* Sum: '<S391>/Add' incorporates:
   *  Fcn: '<S410>/r->x'
   *  Fcn: '<S410>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Init;
  rtb_Switch2_h = (Robot_Control_B.Steering_Localized_Cmd * sin
                   (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2;

  /* Fcn: '<S408>/x->r' */
  rtb_Switch1_m = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Switch2_h);

  /* RelationalOperator: '<S411>/Compare' incorporates:
   *  Constant: '<S411>/Constant'
   */
  rtb_Compare_pb = (rtb_Switch1_m == 0.0);

  /* Switch: '<S407>/Switch1' */
  if (rtb_Compare_pb) {
    /* Switch: '<S407>/Switch1' incorporates:
     *  Constant: '<S407>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S407>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch1_m;
  }

  /* End of Switch: '<S407>/Switch1' */

  /* Fcn: '<S393>/x->r' */
  rtb_Switch1_m = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S396>/Compare' incorporates:
   *  Constant: '<S396>/Constant'
   */
  rtb_Compare_mq = (rtb_Switch1_m == 0.0);

  /* Switch: '<S392>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S392>/Switch1' incorporates:
     *  Constant: '<S392>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S392>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch1_m;
  }

  /* End of Switch: '<S392>/Switch1' */

  /* Fcn: '<S398>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S401>/Compare' incorporates:
   *  Constant: '<S401>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S397>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S397>/Switch1' incorporates:
     *  Constant: '<S397>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S397>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S397>/Switch1' */

  /* Fcn: '<S403>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S406>/Compare' incorporates:
   *  Constant: '<S406>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S402>/Switch1' */
  if (rtb_LogicalOperator1) {
    /* Switch: '<S402>/Switch1' incorporates:
     *  Constant: '<S402>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S402>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S402>/Switch1' */

  /* Product: '<S387>/Divide' incorporates:
   *  Abs: '<S387>/Abs'
   *  Abs: '<S387>/Abs1'
   *  Abs: '<S387>/Abs2'
   *  Abs: '<S387>/Abs3'
   *  Constant: '<S387>/Constant'
   *  MinMax: '<S387>/Max'
   */
  rtb_Switch1_m = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S387>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch1_m;

  /* Switch: '<S407>/Switch' */
  if (!rtb_Compare_pb) {
    /* Switch: '<S407>/Switch' incorporates:
     *  Fcn: '<S408>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Switch2_h,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S407>/Switch' */

  /* Trigonometry: '<S341>/Cos4' incorporates:
   *  Switch: '<S330>/Angle_Switch'
   *  Trigonometry: '<S340>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S341>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S339>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S341>/Sin4' incorporates:
   *  Switch: '<S330>/Angle_Switch'
   *  Trigonometry: '<S340>/Sin4'
   */
  rtb_Switch2 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S341>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S339>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S341>/Subtract1' incorporates:
   *  Product: '<S341>/Product2'
   *  Product: '<S341>/Product3'
   *  Trigonometry: '<S341>/Cos4'
   *  Trigonometry: '<S341>/Sin4'
   */
  rtb_Init = (rtb_Add_i * rtb_Optimized_Module_Angle) + (rtb_Switch2 *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S341>/Subtract' incorporates:
   *  Product: '<S341>/Product'
   *  Product: '<S341>/Product1'
   *  Trigonometry: '<S341>/Cos4'
   *  Trigonometry: '<S341>/Sin4'
   */
  rtb_Switch2_h = (rtb_Add_i * rtb_Optimized_Module_Angle_p) - (rtb_Switch2 *
    rtb_Optimized_Module_Angle);

  /* Math: '<S341>/Hypot' */
  rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Switch2_h, rtb_Init);

  /* Switch: '<S341>/Switch' incorporates:
   *  Constant: '<S341>/Constant'
   *  Constant: '<S341>/Constant1'
   *  Constant: '<S342>/Constant'
   *  Product: '<S341>/Divide'
   *  Product: '<S341>/Divide1'
   *  RelationalOperator: '<S342>/Compare'
   *  Switch: '<S341>/Switch1'
   */
  if (rtb_Minus_k_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Init / rtb_Minus_k_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Switch2_h / rtb_Minus_k_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S341>/Switch' */

  /* Switch: '<S330>/Speed_Switch' incorporates:
   *  Abs: '<S330>/Abs'
   *  Constant: '<S338>/Constant'
   *  RelationalOperator: '<S338>/Compare'
   *  Switch: '<S330>/Angle_Switch'
   *  Trigonometry: '<S340>/Atan1'
   *  Trigonometry: '<S341>/Atan1'
   *  UnaryMinus: '<S330>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_pv = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S340>/Subtract1' incorporates:
     *  Product: '<S340>/Product2'
     *  Product: '<S340>/Product3'
     *  UnaryMinus: '<S330>/Unary Minus'
     */
    rtb_Init = (rtb_Add_i * Robot_Control_ConstB.Sin5_c) + (rtb_Switch2 *
      Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S340>/Subtract' incorporates:
     *  Product: '<S340>/Product'
     *  Product: '<S340>/Product1'
     */
    rtb_Switch2_h = (rtb_Add_i * Robot_Control_ConstB.Cos5_b) - (rtb_Switch2 *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S340>/Hypot' */
    rtb_Switch2 = rt_hypotd_snf(rtb_Switch2_h, rtb_Init);

    /* Switch: '<S340>/Switch1' incorporates:
     *  Constant: '<S340>/Constant'
     *  Constant: '<S340>/Constant1'
     *  Constant: '<S343>/Constant'
     *  Product: '<S340>/Divide'
     *  Product: '<S340>/Divide1'
     *  RelationalOperator: '<S343>/Compare'
     *  Switch: '<S340>/Switch'
     */
    if (rtb_Switch2 > 1.0E-6) {
      rtb_Switch2_h /= rtb_Switch2;
      rtb_Switch2 = rtb_Init / rtb_Switch2;
    } else {
      rtb_Switch2_h = 1.0;
      rtb_Switch2 = 0.0;
    }

    /* End of Switch: '<S340>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch2, rtb_Switch2_h);
  } else {
    rtb_Add_pv = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S333>/Product2' incorporates:
   *  Constant: '<S333>/Constant'
   *  Switch: '<S330>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pv * 1154.7574092481445;

  /* Signum: '<S328>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_pv = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S328>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S331>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S332>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S263>/Product' incorporates:
   *  Abs: '<S328>/Abs'
   *  Abs: '<S331>/Abs'
   *  Constant: '<S334>/Constant'
   *  Constant: '<S344>/Constant3'
   *  Constant: '<S344>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S328>/OR'
   *  Lookup_n-D: '<S331>/1-D Lookup Table'
   *  Math: '<S344>/Math Function'
   *  RelationalOperator: '<S328>/Equal1'
   *  RelationalOperator: '<S334>/Compare'
   *  Signum: '<S328>/Sign'
   *  Signum: '<S328>/Sign1'
   *  Sum: '<S331>/Add'
   *  Sum: '<S344>/Add1'
   *  Sum: '<S344>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_pv == rtb_Add_i) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                    rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S329>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2_h = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S336>/Sum1' incorporates:
   *  Constant: '<S329>/Constant2'
   *  Product: '<S336>/Product'
   *  Sum: '<S336>/Sum'
   *  UnitDelay: '<S336>/Unit Delay1'
   */
  rtb_Switch2 = ((rtb_Switch2_h - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                 Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S329>/Product' incorporates:
   *  Constant: '<S329>/Constant3'
   */
  rtb_Init = rtb_Switch2 * Drive_Motor_Control_D;

  /* Sum: '<S335>/Diff' incorporates:
   *  UnitDelay: '<S335>/UD'
   *
   * Block description for '<S335>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S335>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Init - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S329>/Saturation' */
  if (rtb_Add_pv > Drive_Motor_Control_D_UL) {
    rtb_Add_pv = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Drive_Motor_Control_D_LL) {
    rtb_Add_pv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S329>/Add' incorporates:
   *  Gain: '<S329>/Gain'
   *  Gain: '<S329>/Gain1'
   *  Saturate: '<S329>/Saturation'
   */
  rtb_Minus_k_idx_0 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0)
                       + (Drive_Motor_Control_P * rtb_Switch2_h)) + rtb_Add_pv;

  /* Saturate: '<S329>/Saturation2' incorporates:
   *  Sum: '<S329>/Add1'
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

  /* End of Saturate: '<S329>/Saturation2' */

  /* Switch: '<S392>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S392>/Switch' incorporates:
     *  Fcn: '<S393>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S392>/Switch' */

  /* Trigonometry: '<S278>/Cos4' incorporates:
   *  Switch: '<S267>/Angle_Switch'
   *  Trigonometry: '<S277>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S278>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S276>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S278>/Sin4' incorporates:
   *  Switch: '<S267>/Angle_Switch'
   *  Trigonometry: '<S277>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S278>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S276>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S278>/Subtract1' incorporates:
   *  Product: '<S278>/Product2'
   *  Product: '<S278>/Product3'
   *  Trigonometry: '<S278>/Cos4'
   *  Trigonometry: '<S278>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_Add_i * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S278>/Subtract' incorporates:
   *  Product: '<S278>/Product'
   *  Product: '<S278>/Product1'
   *  Trigonometry: '<S278>/Cos4'
   *  Trigonometry: '<S278>/Sin4'
   */
  rtb_Switch2_h = (rtb_Add_i * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S278>/Hypot' */
  rtb_MatrixConcatenate_idx_0 = rt_hypotd_snf(rtb_Switch2_h, rtb_Minus_k_idx_0);

  /* Switch: '<S278>/Switch' incorporates:
   *  Constant: '<S278>/Constant'
   *  Constant: '<S278>/Constant1'
   *  Constant: '<S279>/Constant'
   *  Product: '<S278>/Divide'
   *  Product: '<S278>/Divide1'
   *  RelationalOperator: '<S279>/Compare'
   *  Switch: '<S278>/Switch1'
   */
  if (rtb_MatrixConcatenate_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0 /
      rtb_MatrixConcatenate_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Switch2_h / rtb_MatrixConcatenate_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S278>/Switch' */

  /* Product: '<S387>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch1_m;

  /* Switch: '<S267>/Speed_Switch' incorporates:
   *  Abs: '<S267>/Abs'
   *  Constant: '<S275>/Constant'
   *  RelationalOperator: '<S275>/Compare'
   *  Switch: '<S267>/Angle_Switch'
   *  Trigonometry: '<S277>/Atan1'
   *  Trigonometry: '<S278>/Atan1'
   *  UnaryMinus: '<S267>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_pv = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S277>/Subtract1' incorporates:
     *  Product: '<S277>/Product2'
     *  Product: '<S277>/Product3'
     *  UnaryMinus: '<S267>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_Add_i * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S277>/Subtract' incorporates:
     *  Product: '<S277>/Product'
     *  Product: '<S277>/Product1'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Add_i * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S277>/Hypot' */
    rtb_Switch2_h = rt_hypotd_snf(rtb_MatrixConcatenate_idx_0, rtb_Minus_k_idx_0);

    /* Switch: '<S277>/Switch1' incorporates:
     *  Constant: '<S277>/Constant'
     *  Constant: '<S277>/Constant1'
     *  Constant: '<S280>/Constant'
     *  Product: '<S277>/Divide'
     *  Product: '<S277>/Divide1'
     *  RelationalOperator: '<S280>/Compare'
     *  Switch: '<S277>/Switch'
     */
    if (rtb_Switch2_h > 1.0E-6) {
      rtb_MatrixConcatenate_idx_0 /= rtb_Switch2_h;
      rtb_Minus_k_idx_0 /= rtb_Switch2_h;
    } else {
      rtb_MatrixConcatenate_idx_0 = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S277>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_0,
      rtb_MatrixConcatenate_idx_0);
  } else {
    rtb_Add_pv = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S270>/Product2' incorporates:
   *  Constant: '<S270>/Constant'
   *  Switch: '<S267>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pv * 1154.7574092481445;

  /* Signum: '<S265>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_pv = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S265>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S268>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S269>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S260>/Product' incorporates:
   *  Abs: '<S265>/Abs'
   *  Abs: '<S268>/Abs'
   *  Constant: '<S271>/Constant'
   *  Constant: '<S281>/Constant3'
   *  Constant: '<S281>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S265>/OR'
   *  Lookup_n-D: '<S268>/1-D Lookup Table'
   *  Math: '<S281>/Math Function'
   *  RelationalOperator: '<S265>/Equal1'
   *  RelationalOperator: '<S271>/Compare'
   *  Signum: '<S265>/Sign'
   *  Signum: '<S265>/Sign1'
   *  Sum: '<S268>/Add'
   *  Sum: '<S281>/Add1'
   *  Sum: '<S281>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_pv == rtb_Add_i) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S266>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_idx_0 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S273>/Sum1' incorporates:
   *  Constant: '<S266>/Constant2'
   *  Product: '<S273>/Product'
   *  Sum: '<S273>/Sum'
   *  UnitDelay: '<S273>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_MatrixConcatenate_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_f) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S266>/Product' incorporates:
   *  Constant: '<S266>/Constant3'
   */
  rtb_Switch2_h = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S272>/Diff' incorporates:
   *  UnitDelay: '<S272>/UD'
   *
   * Block description for '<S272>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S272>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Switch2_h - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S266>/Saturation' */
  if (rtb_Add_pv > Drive_Motor_Control_D_UL) {
    rtb_Add_pv = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Drive_Motor_Control_D_LL) {
    rtb_Add_pv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S266>/Add' incorporates:
   *  Gain: '<S266>/Gain'
   *  Gain: '<S266>/Gain1'
   *  Saturate: '<S266>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = ((Drive_Motor_Control_FF *
    rtb_MatrixConcatenate_b_idx_0) + (Drive_Motor_Control_P *
    rtb_MatrixConcatenate_idx_0)) + rtb_Add_pv;

  /* Saturate: '<S266>/Saturation2' incorporates:
   *  Sum: '<S266>/Add1'
   */
  if (rtb_MatrixConcatenate_idx_0 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_MatrixConcatenate_idx_0 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = rtb_MatrixConcatenate_idx_0;
  }

  /* End of Saturate: '<S266>/Saturation2' */

  /* Sum: '<S282>/Add1' incorporates:
   *  Constant: '<S282>/Constant3'
   *  Constant: '<S282>/Constant4'
   *  Math: '<S282>/Math Function'
   *  Sum: '<S282>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S284>/Sum1' incorporates:
   *  Constant: '<S269>/Constant2'
   *  Product: '<S284>/Product'
   *  Sum: '<S284>/Sum'
   *  UnitDelay: '<S284>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_b) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S269>/Product' incorporates:
   *  Constant: '<S269>/Constant3'
   */
  rtb_Switch2_dp = rtb_MatrixConcatenate_idx_0 * Steering_Motor_Control_D;

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
  rtb_Add_pv = rtb_Switch2_dp - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S269>/Saturation' */
  if (rtb_Add_pv > Steering_Motor_Control_D_UL) {
    rtb_Add_pv = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Motor_Control_D_LL) {
    rtb_Add_pv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S269>/Add' incorporates:
   *  Gain: '<S269>/Gain1'
   *  Saturate: '<S269>/Saturation'
   */
  rtb_Add_e3 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_pv;

  /* Sum: '<S269>/Subtract' incorporates:
   *  Constant: '<S269>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_e3;

  /* Sum: '<S269>/Sum2' incorporates:
   *  Gain: '<S269>/Gain2'
   *  UnitDelay: '<S269>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S285>/Switch2' incorporates:
   *  Constant: '<S269>/Constant'
   *  RelationalOperator: '<S285>/LowerRelop1'
   *  Sum: '<S269>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_e3))) {
    /* Switch: '<S285>/Switch' incorporates:
     *  Constant: '<S269>/Constant1'
     *  RelationalOperator: '<S285>/UpperRelop'
     *  Sum: '<S269>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_e3)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_e3;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S285>/Switch' */
  }

  /* End of Switch: '<S285>/Switch2' */

  /* Saturate: '<S269>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S269>/Saturation1' */

  /* Sum: '<S269>/Add1' */
  rtb_Add_pv = rtb_Add_e3 + rtb_Sum2_e;

  /* Saturate: '<S269>/Saturation2' */
  if (rtb_Add_pv > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_pv < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_pv;
  }

  /* End of Saturate: '<S269>/Saturation2' */

  /* Switch: '<S397>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S397>/Switch' incorporates:
     *  Fcn: '<S398>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S397>/Switch' */

  /* Trigonometry: '<S299>/Cos4' incorporates:
   *  Switch: '<S288>/Angle_Switch'
   *  Trigonometry: '<S298>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S299>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S297>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S299>/Sin4' incorporates:
   *  Switch: '<S288>/Angle_Switch'
   *  Trigonometry: '<S298>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S299>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S297>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S299>/Subtract1' incorporates:
   *  Product: '<S299>/Product2'
   *  Product: '<S299>/Product3'
   *  Trigonometry: '<S299>/Cos4'
   *  Trigonometry: '<S299>/Sin4'
   */
  rtb_Add_e3 = (rtb_Add_i * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S299>/Subtract' incorporates:
   *  Product: '<S299>/Product'
   *  Product: '<S299>/Product1'
   *  Trigonometry: '<S299>/Cos4'
   *  Trigonometry: '<S299>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Add_i * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S299>/Hypot' */
  rtb_uDLookupTable = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_e3);

  /* Switch: '<S299>/Switch' incorporates:
   *  Constant: '<S299>/Constant'
   *  Constant: '<S299>/Constant1'
   *  Constant: '<S300>/Constant'
   *  Product: '<S299>/Divide'
   *  Product: '<S299>/Divide1'
   *  RelationalOperator: '<S300>/Compare'
   *  Switch: '<S299>/Switch1'
   */
  if (rtb_uDLookupTable > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_e3 / rtb_uDLookupTable;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_uDLookupTable;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S299>/Switch' */

  /* Product: '<S387>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch1_m;

  /* Switch: '<S288>/Speed_Switch' incorporates:
   *  Abs: '<S288>/Abs'
   *  Constant: '<S296>/Constant'
   *  RelationalOperator: '<S296>/Compare'
   *  Switch: '<S288>/Angle_Switch'
   *  Trigonometry: '<S298>/Atan1'
   *  Trigonometry: '<S299>/Atan1'
   *  UnaryMinus: '<S288>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_pv = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S298>/Subtract1' incorporates:
     *  Product: '<S298>/Product2'
     *  Product: '<S298>/Product3'
     *  UnaryMinus: '<S288>/Unary Minus'
     */
    rtb_Add_e3 = (rtb_Add_i * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S298>/Subtract' incorporates:
     *  Product: '<S298>/Product'
     *  Product: '<S298>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_i * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S298>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_uDLookupTable, rtb_Add_e3);

    /* Switch: '<S298>/Switch1' incorporates:
     *  Constant: '<S298>/Constant'
     *  Constant: '<S298>/Constant1'
     *  Constant: '<S301>/Constant'
     *  Product: '<S298>/Divide'
     *  Product: '<S298>/Divide1'
     *  RelationalOperator: '<S301>/Compare'
     *  Switch: '<S298>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Subtract1_la;
      rtb_Add_e3 /= rtb_Subtract1_la;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Add_e3 = 0.0;
    }

    /* End of Switch: '<S298>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_e3, rtb_uDLookupTable);
  } else {
    rtb_Add_pv = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S291>/Product2' incorporates:
   *  Constant: '<S291>/Constant'
   *  Switch: '<S288>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pv * 1154.7574092481445;

  /* Signum: '<S286>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_pv = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S286>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S289>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S290>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S261>/Product' incorporates:
   *  Abs: '<S286>/Abs'
   *  Abs: '<S289>/Abs'
   *  Constant: '<S292>/Constant'
   *  Constant: '<S302>/Constant3'
   *  Constant: '<S302>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S286>/OR'
   *  Lookup_n-D: '<S289>/1-D Lookup Table'
   *  Math: '<S302>/Math Function'
   *  RelationalOperator: '<S286>/Equal1'
   *  RelationalOperator: '<S292>/Compare'
   *  Signum: '<S286>/Sign'
   *  Signum: '<S286>/Sign1'
   *  Sum: '<S289>/Add'
   *  Sum: '<S302>/Add1'
   *  Sum: '<S302>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_pv == rtb_Add_i) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Sum: '<S287>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_uDLookupTable = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S294>/Sum1' incorporates:
   *  Constant: '<S287>/Constant2'
   *  Product: '<S294>/Product'
   *  Sum: '<S294>/Sum'
   *  UnitDelay: '<S294>/Unit Delay1'
   */
  rtb_Add_e3 = ((rtb_uDLookupTable - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S287>/Product' incorporates:
   *  Constant: '<S287>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_e3 * Drive_Motor_Control_D;

  /* Sum: '<S293>/Diff' incorporates:
   *  UnitDelay: '<S293>/UD'
   *
   * Block description for '<S293>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S293>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S287>/Saturation' */
  if (rtb_Add_pv > Drive_Motor_Control_D_UL) {
    rtb_Add_pv = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Drive_Motor_Control_D_LL) {
    rtb_Add_pv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S287>/Add' incorporates:
   *  Gain: '<S287>/Gain'
   *  Gain: '<S287>/Gain1'
   *  Saturate: '<S287>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF *
    rtb_MatrixConcatenate_b_idx_0) + (Drive_Motor_Control_P * rtb_uDLookupTable))
    + rtb_Add_pv;

  /* Saturate: '<S287>/Saturation2' incorporates:
   *  Sum: '<S287>/Add1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S287>/Saturation2' */

  /* Sum: '<S303>/Add1' incorporates:
   *  Constant: '<S303>/Constant3'
   *  Constant: '<S303>/Constant4'
   *  Math: '<S303>/Math Function'
   *  Sum: '<S303>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S305>/Sum1' incorporates:
   *  Constant: '<S290>/Constant2'
   *  Product: '<S305>/Product'
   *  Sum: '<S305>/Sum'
   *  UnitDelay: '<S305>/Unit Delay1'
   */
  rtb_Switch2_ee = ((rtb_MatrixConcatenate_b_idx_0 -
                     Robot_Control_DW.UnitDelay1_DSTATE_n) *
                    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S290>/Product' incorporates:
   *  Constant: '<S290>/Constant3'
   */
  rtb_Product_hi = rtb_Switch2_ee * Steering_Motor_Control_D;

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
  rtb_Add_pv = rtb_Product_hi - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S290>/Saturation' */
  if (rtb_Add_pv > Steering_Motor_Control_D_UL) {
    rtb_Add_pv = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Motor_Control_D_LL) {
    rtb_Add_pv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S290>/Add' incorporates:
   *  Gain: '<S290>/Gain1'
   *  Saturate: '<S290>/Saturation'
   */
  rtb_Add_i = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_pv;

  /* Sum: '<S290>/Subtract' incorporates:
   *  Constant: '<S290>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_i;

  /* Sum: '<S290>/Sum2' incorporates:
   *  Gain: '<S290>/Gain2'
   *  UnitDelay: '<S290>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S306>/Switch2' incorporates:
   *  Constant: '<S290>/Constant'
   *  RelationalOperator: '<S306>/LowerRelop1'
   *  Sum: '<S290>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_i))) {
    /* Switch: '<S306>/Switch' incorporates:
     *  Constant: '<S290>/Constant1'
     *  RelationalOperator: '<S306>/UpperRelop'
     *  Sum: '<S290>/Subtract1'
     */
    if (rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_i)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_i;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S306>/Switch' */
  }

  /* End of Switch: '<S306>/Switch2' */

  /* Saturate: '<S290>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S290>/Saturation1' */

  /* Sum: '<S290>/Add1' */
  rtb_Add_pv = rtb_Add_i + rtb_Subtract1_kg;

  /* Saturate: '<S290>/Saturation2' */
  if (rtb_Add_pv > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_pv < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_pv;
  }

  /* End of Saturate: '<S290>/Saturation2' */

  /* Switch: '<S402>/Switch' */
  if (!rtb_LogicalOperator1) {
    /* Switch: '<S402>/Switch' incorporates:
     *  Fcn: '<S403>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S402>/Switch' */

  /* Trigonometry: '<S320>/Cos4' incorporates:
   *  Switch: '<S309>/Angle_Switch'
   *  Trigonometry: '<S319>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S320>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S318>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S320>/Sin4' incorporates:
   *  Switch: '<S309>/Angle_Switch'
   *  Trigonometry: '<S319>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S320>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S318>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S320>/Subtract1' incorporates:
   *  Product: '<S320>/Product2'
   *  Product: '<S320>/Product3'
   *  Trigonometry: '<S320>/Cos4'
   *  Trigonometry: '<S320>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Add_i * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S320>/Subtract' incorporates:
   *  Product: '<S320>/Product'
   *  Product: '<S320>/Product1'
   *  Trigonometry: '<S320>/Cos4'
   *  Trigonometry: '<S320>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Add_i * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S320>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S320>/Switch' incorporates:
   *  Constant: '<S320>/Constant'
   *  Constant: '<S320>/Constant1'
   *  Constant: '<S321>/Constant'
   *  Product: '<S320>/Divide'
   *  Product: '<S320>/Divide1'
   *  RelationalOperator: '<S321>/Compare'
   *  Switch: '<S320>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S320>/Switch' */

  /* Product: '<S387>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch1_m;

  /* Switch: '<S309>/Speed_Switch' incorporates:
   *  Abs: '<S309>/Abs'
   *  Constant: '<S317>/Constant'
   *  RelationalOperator: '<S317>/Compare'
   *  Switch: '<S309>/Angle_Switch'
   *  Trigonometry: '<S319>/Atan1'
   *  Trigonometry: '<S320>/Atan1'
   *  UnaryMinus: '<S309>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_pv = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S319>/Subtract1' incorporates:
     *  Product: '<S319>/Product2'
     *  Product: '<S319>/Product3'
     *  UnaryMinus: '<S309>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Add_i * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S319>/Subtract' incorporates:
     *  Product: '<S319>/Product'
     *  Product: '<S319>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_i * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S319>/Hypot' */
    rtb_Add_i = rt_hypotd_snf(rtb_uDLookupTable, rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S319>/Switch1' incorporates:
     *  Constant: '<S319>/Constant'
     *  Constant: '<S319>/Constant1'
     *  Constant: '<S322>/Constant'
     *  Product: '<S319>/Divide'
     *  Product: '<S319>/Divide1'
     *  RelationalOperator: '<S322>/Compare'
     *  Switch: '<S319>/Switch'
     */
    if (rtb_Add_i > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Add_i;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Add_i;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S319>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_uDLookupTable);
  } else {
    rtb_Add_pv = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S312>/Product2' incorporates:
   *  Constant: '<S312>/Constant'
   *  Switch: '<S309>/Speed_Switch'
   */
  rtb_Switch1_m = rtb_Add_pv * 1154.7574092481445;

  /* Signum: '<S307>/Sign' */
  if (rtIsNaN(rtb_Switch1_m)) {
    rtb_Add_pv = (rtNaN);
  } else if (rtb_Switch1_m < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (rtb_Switch1_m > 0.0);
  }

  /* Signum: '<S307>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S310>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S311>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S262>/Product' incorporates:
   *  Abs: '<S307>/Abs'
   *  Abs: '<S310>/Abs'
   *  Constant: '<S313>/Constant'
   *  Constant: '<S323>/Constant3'
   *  Constant: '<S323>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S307>/OR'
   *  Lookup_n-D: '<S310>/1-D Lookup Table'
   *  Math: '<S323>/Math Function'
   *  RelationalOperator: '<S307>/Equal1'
   *  RelationalOperator: '<S313>/Compare'
   *  Signum: '<S307>/Sign'
   *  Signum: '<S307>/Sign1'
   *  Sum: '<S310>/Add'
   *  Sum: '<S323>/Add1'
   *  Sum: '<S323>/Add2'
   */
  rtb_Switch1_m = (((real_T)((rtb_Add_pv == rtb_Add_i) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch1_m) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S308>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_m -
    Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S315>/Sum1' incorporates:
   *  Constant: '<S308>/Constant2'
   *  Product: '<S315>/Product'
   *  Sum: '<S315>/Sum'
   *  UnitDelay: '<S315>/Unit Delay1'
   */
  rtb_Add_i = ((rtb_MatrixConcatenate_b_idx_0 -
                Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S308>/Product' incorporates:
   *  Constant: '<S308>/Constant3'
   */
  rtb_uDLookupTable = rtb_Add_i * Drive_Motor_Control_D;

  /* Sum: '<S314>/Diff' incorporates:
   *  UnitDelay: '<S314>/UD'
   *
   * Block description for '<S314>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S314>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S308>/Saturation' */
  if (rtb_Add_pv > Drive_Motor_Control_D_UL) {
    rtb_Add_pv = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Drive_Motor_Control_D_LL) {
    rtb_Add_pv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S308>/Add' incorporates:
   *  Gain: '<S308>/Gain'
   *  Gain: '<S308>/Gain1'
   *  Saturate: '<S308>/Saturation'
   */
  rtb_Switch1_m = ((Drive_Motor_Control_FF * rtb_Switch1_m) +
                   (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) +
    rtb_Add_pv;

  /* Saturate: '<S308>/Saturation2' incorporates:
   *  Sum: '<S308>/Add1'
   */
  if (rtb_Switch1_m > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch1_m < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Switch1_m;
  }

  /* End of Saturate: '<S308>/Saturation2' */

  /* Sum: '<S324>/Add1' incorporates:
   *  Constant: '<S324>/Constant3'
   *  Constant: '<S324>/Constant4'
   *  Math: '<S324>/Math Function'
   *  Sum: '<S324>/Add2'
   */
  rtb_Switch1_m = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S326>/Sum1' incorporates:
   *  Constant: '<S311>/Constant2'
   *  Product: '<S326>/Product'
   *  Sum: '<S326>/Sum'
   *  UnitDelay: '<S326>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch1_m -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S311>/Product' incorporates:
   *  Constant: '<S311>/Constant3'
   */
  rtb_Product_k = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

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
  rtb_Add_pv = rtb_Product_k - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S311>/Saturation' */
  if (rtb_Add_pv > Steering_Motor_Control_D_UL) {
    rtb_Add_pv = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Motor_Control_D_LL) {
    rtb_Add_pv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S311>/Add' incorporates:
   *  Gain: '<S311>/Gain1'
   *  Saturate: '<S311>/Saturation'
   */
  rtb_Add_lu = (Steering_Motor_Control_P * rtb_Switch1_m) + rtb_Add_pv;

  /* Sum: '<S311>/Subtract' incorporates:
   *  Constant: '<S311>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_lu;

  /* Sum: '<S311>/Sum2' incorporates:
   *  Gain: '<S311>/Gain2'
   *  UnitDelay: '<S311>/Unit Delay'
   */
  rtb_Switch1_m = (Steering_Motor_Control_I * rtb_Switch1_m) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S327>/Switch2' incorporates:
   *  Constant: '<S311>/Constant'
   *  RelationalOperator: '<S327>/LowerRelop1'
   *  Sum: '<S311>/Subtract'
   */
  if (!(rtb_Switch1_m > (1.0 - rtb_Add_lu))) {
    /* Sum: '<S311>/Subtract1' incorporates:
     *  Constant: '<S311>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_lu;

    /* Switch: '<S327>/Switch' incorporates:
     *  Constant: '<S311>/Constant1'
     *  RelationalOperator: '<S327>/UpperRelop'
     *  Sum: '<S311>/Subtract1'
     */
    if (!(rtb_Switch1_m < (-1.0 - rtb_Add_lu))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_m;
    }

    /* End of Switch: '<S327>/Switch' */
  }

  /* End of Switch: '<S327>/Switch2' */

  /* Saturate: '<S311>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S311>/Saturation1' */

  /* Sum: '<S311>/Add1' */
  rtb_Add_pv = rtb_Add_lu + rtb_Integral_ga;

  /* Saturate: '<S311>/Saturation2' */
  if (rtb_Add_pv > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_pv < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_pv;
  }

  /* End of Saturate: '<S311>/Saturation2' */

  /* Sum: '<S345>/Add1' incorporates:
   *  Constant: '<S345>/Constant3'
   *  Constant: '<S345>/Constant4'
   *  Math: '<S345>/Math Function'
   *  Sum: '<S345>/Add2'
   */
  rtb_Switch1_m = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S347>/Sum1' incorporates:
   *  Constant: '<S332>/Constant2'
   *  Product: '<S347>/Product'
   *  Sum: '<S347>/Sum'
   *  UnitDelay: '<S347>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch1_m -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S332>/Product' incorporates:
   *  Constant: '<S332>/Constant3'
   */
  rtb_Add_lu = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

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
  rtb_Add_pv = rtb_Add_lu - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S332>/Saturation' */
  if (rtb_Add_pv > Steering_Motor_Control_D_UL) {
    rtb_Add_pv = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Motor_Control_D_LL) {
    rtb_Add_pv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S332>/Add' incorporates:
   *  Gain: '<S332>/Gain1'
   *  Saturate: '<S332>/Saturation'
   */
  rtb_Add_jp = (Steering_Motor_Control_P * rtb_Switch1_m) + rtb_Add_pv;

  /* Sum: '<S332>/Subtract' incorporates:
   *  Constant: '<S332>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_jp;

  /* Sum: '<S332>/Sum2' incorporates:
   *  Gain: '<S332>/Gain2'
   *  UnitDelay: '<S332>/Unit Delay'
   */
  rtb_Switch1_m = (Steering_Motor_Control_I * rtb_Switch1_m) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S348>/Switch2' incorporates:
   *  Constant: '<S332>/Constant'
   *  RelationalOperator: '<S348>/LowerRelop1'
   *  Sum: '<S332>/Subtract'
   */
  if (!(rtb_Switch1_m > (1.0 - rtb_Add_jp))) {
    /* Sum: '<S332>/Subtract1' incorporates:
     *  Constant: '<S332>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_jp;

    /* Switch: '<S348>/Switch' incorporates:
     *  Constant: '<S332>/Constant1'
     *  RelationalOperator: '<S348>/UpperRelop'
     *  Sum: '<S332>/Subtract1'
     */
    if (!(rtb_Switch1_m < (-1.0 - rtb_Add_jp))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_m;
    }

    /* End of Switch: '<S348>/Switch' */
  }

  /* End of Switch: '<S348>/Switch2' */

  /* Saturate: '<S332>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S332>/Saturation1' */

  /* Sum: '<S332>/Add1' */
  rtb_Add_pv = rtb_Add_jp + rtb_Integral_bj;

  /* Saturate: '<S332>/Saturation2' */
  if (rtb_Add_pv > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_pv < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_pv;
  }

  /* End of Saturate: '<S332>/Saturation2' */

  /* Sum: '<S195>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S139>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S197>/Sum1' incorporates:
   *  Constant: '<S195>/Constant2'
   *  Product: '<S197>/Product'
   *  Sum: '<S195>/Sum'
   *  Sum: '<S197>/Sum'
   *  UnitDelay: '<S197>/Unit Delay1'
   */
  rtb_Add_jp = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S195>/Product' incorporates:
   *  Constant: '<S195>/Constant3'
   */
  rtb_Product_ih = rtb_Add_jp * 0.0;

  /* Sum: '<S196>/Diff' incorporates:
   *  UnitDelay: '<S196>/UD'
   *
   * Block description for '<S196>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S196>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Product_ih - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S195>/Saturation' */
  if (rtb_Add_pv > 0.1) {
    rtb_Add_pv = 0.1;
  } else if (rtb_Add_pv < -0.1) {
    rtb_Add_pv = -0.1;
  }

  /* Sum: '<S195>/Add' incorporates:
   *  Gain: '<S195>/Gain'
   *  Gain: '<S195>/Gain1'
   *  Saturate: '<S195>/Saturation'
   *  Sum: '<S195>/Sum'
   */
  rtb_Switch1_m = ((Rebuilt_Transfer_Motor_Gain_FF *
                    Robot_Control_B.RB_Desired_Transfer_Speed) +
                   (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) +
    rtb_Add_pv;

  /* Logic: '<S139>/Logical Operator1' incorporates:
   *  Constant: '<S194>/Constant'
   *  RelationalOperator: '<S194>/Compare'
   */
  rtb_LogicalOperator1 = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S139>/Switch1' incorporates:
   *  Abs: '<S139>/Abs'
   *  Constant: '<S139>/Constant1'
   *  Constant: '<S139>/Constant2'
   *  Logic: '<S139>/Logical Operator'
   *  Logic: '<S139>/Logical Operator1'
   *  RelationalOperator: '<S139>/LessThan'
   *  UnitDelay: '<S139>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_LogicalOperator1) {
    rtb_Compare_ky = true;
  } else {
    rtb_Compare_ky = (rtb_LogicalOperator1 &&
                      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S139>/Switch1' */

  /* Switch: '<S195>/Switch' incorporates:
   *  Constant: '<S195>/Constant4'
   */
  if (rtb_Compare_ky) {
    /* Sum: '<S195>/Sum2' incorporates:
     *  Gain: '<S195>/Gain2'
     *  Sum: '<S195>/Sum'
     *  UnitDelay: '<S195>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Transfer_Motor_Gain_I *
      rtb_Integral_d) + Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S195>/Subtract' incorporates:
     *  Constant: '<S195>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Switch1_m;

    /* Switch: '<S198>/Switch2' incorporates:
     *  Constant: '<S195>/Constant'
     *  RelationalOperator: '<S198>/LowerRelop1'
     *  Sum: '<S195>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Switch1_m))) {
      /* Sum: '<S195>/Subtract1' incorporates:
       *  Constant: '<S195>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Switch1_m;

      /* Switch: '<S198>/Switch' incorporates:
       *  Constant: '<S195>/Constant1'
       *  RelationalOperator: '<S198>/UpperRelop'
       *  Sum: '<S195>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Switch1_m))) {
        rtb_Integral_d = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S198>/Switch' */
    }

    /* End of Switch: '<S198>/Switch2' */

    /* Saturate: '<S195>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S195>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S195>/Switch' */

  /* Switch: '<S139>/Switch2' incorporates:
   *  Logic: '<S139>/Logical Operator1'
   */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S195>/Add1' */
    rtb_Add_pv = rtb_Switch1_m + rtb_Integral_d;

    /* Saturate: '<S195>/Saturation2' */
    if (rtb_Add_pv > 1.0) {
      /* Switch: '<S139>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_pv < -1.0) {
      /* Switch: '<S139>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S139>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_pv;
    }

    /* End of Saturate: '<S195>/Saturation2' */
  } else {
    /* Switch: '<S139>/Switch2' incorporates:
     *  Constant: '<S139>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S139>/Switch2' */

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
  rtb_Add_pv = Robot_Control_B.RB_Desired_Feeder_Speed *
    Rebuilt_Feeder_Motor_Gain_FF;

  /* Saturate: '<S12>/Saturation' */
  if (rtb_Add_pv > 1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = 1.0;
  } else if (rtb_Add_pv < -1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = -1.0;
  } else {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = rtb_Add_pv;
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant6'
   *  Switch: '<S10>/Switch2'
   *  Switch: '<S10>/Switch3'
   *  Switch: '<S10>/Switch5'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Feeder_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    Robot_Control_Y.Feeder_Motor_DC = TEST_Feeder_Motor_DC_OV;

    /* Outport: '<Root>/Desired_Shooter_Speed' incorporates:
     *  Constant: '<S10>/Constant3'
     */
    Robot_Control_Y.Desired_Shooter_Speed = TEST_Desired_Shooter_Speed_OV;

    /* Outport: '<Root>/Desired_Shooter_FF_DC' incorporates:
     *  Constant: '<S10>/Constant4'
     */
    Robot_Control_Y.Desired_Shooter_FF_DC = TEST_Desired_Shooter_FF_DC_OV;
    rtb_Switch1_m = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Shooter_Speed' */
    Robot_Control_Y.Desired_Shooter_Speed =
      Robot_Control_B.RB_Desired_Shooter_Speed;

    /* Outport: '<Root>/Desired_Shooter_FF_DC' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Product: '<S12>/Product1'
     */
    Robot_Control_Y.Desired_Shooter_FF_DC =
      Robot_Control_B.RB_Desired_Shooter_Speed * Rebuilt_Shooter_Motor_Gain_FF;
    rtb_Switch1_m = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_Switch1_m > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Switch1_m = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Switch1_m < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Switch1_m = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Switch1_m;

  /* Switch: '<S130>/Init' incorporates:
   *  UnitDelay: '<S130>/FixPt Unit Delay1'
   *  UnitDelay: '<S130>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_m;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S130>/Init' */

  /* Sum: '<S128>/Sum1' */
  rtb_Switch1_m -= rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S129>/Switch2' incorporates:
   *  Constant: '<S127>/Constant1'
   *  Constant: '<S127>/Constant3'
   *  RelationalOperator: '<S129>/LowerRelop1'
   *  RelationalOperator: '<S129>/UpperRelop'
   *  Switch: '<S129>/Switch'
   */
  if (rtb_Switch1_m > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch1_m = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch1_m < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     */
    rtb_Switch1_m = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S129>/Switch2' */

  /* Sum: '<S128>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Switch1_m +
    rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Logic: '<S6>/Logical Operator'
   */
  if (rtb_Intake_Arm_Cycle || rtb_LogicalOperator1_ms) {
    rtb_Switch1_m = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Switch1_m = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S56>/Logical Operator1' incorporates:
   *  Constant: '<S68>/Constant'
   *  RelationalOperator: '<S68>/Compare'
   */
  rtb_LogicalOperator1_ms = !(rtb_Switch1_m == 0.0);

  /* Sum: '<S69>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S56>/Subtract'
   */
  rtb_Error_n = rtb_Switch1_m - Robot_Control_U.Measured_Intake_Roller_Speed;

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
  rtb_Product_ld = rtb_Sum1_fh * 0.0;

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
  rtb_Add_pv = rtb_Product_ld - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S69>/Saturation' */
  if (rtb_Add_pv > 0.1) {
    rtb_Add_pv = 0.1;
  } else if (rtb_Add_pv < -0.1) {
    rtb_Add_pv = -0.1;
  }

  /* Sum: '<S69>/Add' incorporates:
   *  Gain: '<S69>/Gain'
   *  Gain: '<S69>/Gain1'
   *  Saturate: '<S69>/Saturation'
   *  Sum: '<S69>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Switch1_m)
    + (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_pv;

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
      rtb_LogicalOperator1_ms) {
    rtb_LogicalOperator1 = true;
  } else {
    rtb_LogicalOperator1 = (rtb_LogicalOperator1_ms &&
      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S56>/Switch1' */

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/Constant4'
   */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S69>/Sum2' incorporates:
     *  Gain: '<S69>/Gain2'
     *  Sum: '<S69>/Sum'
     *  UnitDelay: '<S69>/Unit Delay'
     */
    rtb_Switch1_m = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
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
    if (!(rtb_Switch1_m > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S69>/Subtract1' incorporates:
       *  Constant: '<S69>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S72>/Switch' incorporates:
       *  Constant: '<S69>/Constant1'
       *  RelationalOperator: '<S72>/UpperRelop'
       *  Sum: '<S69>/Subtract1'
       */
      if (!(rtb_Switch1_m < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Error_n = rtb_Switch1_m;
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
  if (rtb_LogicalOperator1_ms) {
    /* Sum: '<S69>/Add1' */
    rtb_Add_pv = rtb_MatrixConcatenate_b_idx_0 + rtb_Error_n;

    /* Saturate: '<S69>/Saturation2' */
    if (rtb_Add_pv > 1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_pv < -1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_pv;
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
      if ((rtb_Intake_Arm_Move_Out || (rtb_Intake_Arm_Cycle &&
            (Robot_Control_B.RB_Intake_Arm_Angle_Mod <
             Rebuilt_Intake_Cycle_Angle_In))) || (((int32_T)rtb_Intake_Arm_Cycle)
           < ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_c))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      if (rtb_Shooter_Active_prev || (rtb_Intake_Arm_Cycle &&
           (Robot_Control_B.RB_Intake_Arm_Angle_Mod >
            Rebuilt_Intake_Cycle_Angle_Out))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
      }
      break;

     default:
      /* case IN_Wait_for_Button: */
      if (rtb_Shooter_Active_prev || rtb_Intake_Arm_Cycle) {
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
    rtb_Switch1_m = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Switch1_m = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S67>/Init' */

  /* Sum: '<S65>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_Switch1_m;

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
    rtb_Switch1_m;

  /* Sum: '<S61>/Sum' */
  rtb_Switch1_m = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S63>/Sum1' incorporates:
   *  Constant: '<S61>/Constant2'
   *  Product: '<S63>/Product'
   *  Sum: '<S63>/Sum'
   *  UnitDelay: '<S63>/Unit Delay1'
   */
  rtb_Sum1_dj = ((rtb_Switch1_m - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S61>/Product' incorporates:
   *  Constant: '<S61>/Constant3'
   */
  rtb_Product_ej = rtb_Sum1_dj * Rebuilt_Intake_Arm_Gain_D;

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
  rtb_Add_pv = rtb_Product_ej - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S61>/Saturation' */
  if (rtb_Add_pv > 0.1) {
    rtb_Add_pv = 0.1;
  } else if (rtb_Add_pv < -0.1) {
    rtb_Add_pv = -0.1;
  }

  /* Sum: '<S61>/Add' incorporates:
   *  Gain: '<S61>/Gain'
   *  Gain: '<S61>/Gain1'
   *  Saturate: '<S61>/Saturation'
   */
  rtb_Add_pv += (0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
    (Rebuilt_Intake_Arm_Gain_P * rtb_Switch1_m);

  /* Sum: '<S61>/Subtract' incorporates:
   *  Constant: '<S61>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_pv;

  /* Sum: '<S61>/Sum2' incorporates:
   *  Gain: '<S61>/Gain2'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  rtb_Switch1_m = (0.0 * rtb_Switch1_m) + Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S64>/Switch2' incorporates:
   *  Constant: '<S61>/Constant'
   *  RelationalOperator: '<S64>/LowerRelop1'
   *  Sum: '<S61>/Subtract'
   */
  if (!(rtb_Switch1_m > (1.0 - rtb_Add_pv))) {
    /* Sum: '<S61>/Subtract1' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_pv;

    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S61>/Constant1'
     *  RelationalOperator: '<S64>/UpperRelop'
     *  Sum: '<S61>/Subtract1'
     */
    if (!(rtb_Switch1_m < (-1.0 - rtb_Add_pv))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_m;
    }

    /* End of Switch: '<S64>/Switch' */
  }

  /* End of Switch: '<S64>/Switch2' */

  /* Saturate: '<S61>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > 0.1) {
    rtb_Switch1_m = 0.1;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -0.1) {
    rtb_Switch1_m = -0.1;
  } else {
    rtb_Switch1_m = rtb_MatrixConcatenate_b_idx_0;
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
    rtb_Add_pv += rtb_Switch1_m;

    /* Saturate: '<S61>/Saturation2' */
    if (rtb_Add_pv > 1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_pv < -1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_pv;
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

  /* Update for UnitDelay: '<S35>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *
   * Block description for '<S35>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Joystick_Left_B11;

  /* Update for UnitDelay: '<S36>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *
   * Block description for '<S36>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Joystick_Left_B12;

  /* Update for UnitDelay: '<S37>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *
   * Block description for '<S37>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Joystick_Left_B13;

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nl = rtb_Button_Spinup_Enable;

  /* Update for UnitDelay: '<S44>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S44>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S44>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S47>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S47>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 0U;

  /* Update for UnitDelay: '<S47>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_a = rtb_Switch1_hb;

  /* Update for UnitDelay: '<S50>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S50>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S50>/FixPt Unit Delay1' */
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

  /* Update for UnitDelay: '<S360>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S360>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S181>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_o = rtb_Merge1;

  /* Update for UnitDelay: '<S182>/Unit Delay' incorporates:
   *  Constant: '<S182>/Constant4'
   *  Sum: '<S182>/Sum'
   *  Switch: '<S182>/Switch'
   */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Minus_f + 0.02;

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

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_5_DSTATE = Robot_Control_B.Can_Pass;

  /* Update for UnitDelay: '<S383>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Abs2;

  /* Update for UnitDelay: '<S382>/UD'
   *
   * Block description for '<S382>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Switch1_n;

  /* Update for UnitDelay: '<S380>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch2_hw;

  /* Update for UnitDelay: '<S362>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Init_o;

  /* Update for UnitDelay: '<S377>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S377>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S377>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S361>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S370>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S370>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S370>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S336>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch2;

  /* Update for UnitDelay: '<S335>/UD'
   *
   * Block description for '<S335>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Init;

  /* Update for UnitDelay: '<S329>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S273>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S272>/UD'
   *
   * Block description for '<S272>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Switch2_h;

  /* Update for UnitDelay: '<S266>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S284>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S283>/UD'
   *
   * Block description for '<S283>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_dp;

  /* Update for UnitDelay: '<S269>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S294>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_e3;

  /* Update for UnitDelay: '<S293>/UD'
   *
   * Block description for '<S293>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S287>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S305>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Switch2_ee;

  /* Update for UnitDelay: '<S304>/UD'
   *
   * Block description for '<S304>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_hi;

  /* Update for UnitDelay: '<S290>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S315>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_i;

  /* Update for UnitDelay: '<S314>/UD'
   *
   * Block description for '<S314>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S308>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S326>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S325>/UD'
   *
   * Block description for '<S325>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_k;

  /* Update for UnitDelay: '<S311>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S347>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S346>/UD'
   *
   * Block description for '<S346>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_lu;

  /* Update for UnitDelay: '<S332>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S197>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_jp;

  /* Update for UnitDelay: '<S196>/UD'
   *
   * Block description for '<S196>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_ih;

  /* Update for UnitDelay: '<S195>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S139>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Compare_ky;

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
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_ld;

  /* Update for UnitDelay: '<S69>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S56>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S53>/Delay Input1'
   *
   * Block description for '<S53>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

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
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_ej;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_Switch1_m;
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
  Robot_Control_DW.If_ActiveSubsystem_n = -1;

  /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S47>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S50>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S73>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S360>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S377>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S370>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S130>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S67>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S440>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S205>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S201>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S205>/Robot_Index_Is_Valid' */
  /* Start for If: '<S208>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S208>/Circle_Check_Valid' */
  /* Start for If: '<S210>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S208>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S205>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S177>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S179>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S180>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

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
