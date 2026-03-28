/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.479
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Mar 27 20:54:56 2026
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

/* Named constants for Chart: '<S373>/Add dither' */
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
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S447>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S443>/Constant'
                                        *   '<S443>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S447>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S443>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S276>/Constant3'
                                        *   '<S297>/Constant3'
                                        *   '<S318>/Constant3'
                                        *   '<S339>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S276>/Constant2'
                                   *   '<S297>/Constant2'
                                   *   '<S318>/Constant2'
                                   *   '<S339>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S276>/Saturation'
                                        *   '<S297>/Saturation'
                                        *   '<S318>/Saturation'
                                        *   '<S339>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S276>/Saturation'
                                        *   '<S297>/Saturation'
                                        *   '<S318>/Saturation'
                                        *   '<S339>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S276>/Gain'
                                            *   '<S297>/Gain'
                                            *   '<S318>/Gain'
                                            *   '<S339>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S276>/Gain2'
                                        *   '<S297>/Gain2'
                                        *   '<S318>/Gain2'
                                        *   '<S339>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S276>/Saturation1'
                                         *   '<S297>/Saturation1'
                                         *   '<S318>/Saturation1'
                                         *   '<S339>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S276>/Saturation1'
                                        *   '<S297>/Saturation1'
                                        *   '<S318>/Saturation1'
                                        *   '<S339>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S276>/Gain1'
                                        *   '<S297>/Gain1'
                                        *   '<S318>/Gain1'
                                        *   '<S339>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S281>/Constant'
                            *   '<S302>/Constant'
                            *   '<S323>/Constant'
                            *   '<S344>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S185>/BlueAllianceZoneX'
                                         *   '<S187>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S150>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S150>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S150>/Constant1'
                                        *   '<S150>/Switch3'
                                        */
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S150>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S150>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S186>/RedAllianceZoneX'
                                         *   '<S188>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S150>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S150>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S433>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S433>/Constant5'
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
                                       * Referenced by: '<S145>/Constant'
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
                                          *   '<S143>/Constant3'
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
                                       * Referenced by: '<S170>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S174>/Constant3'
                                   *   '<S175>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S165>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S166>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S167>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S168>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S171>/Unit Delay'
                                      *   '<S172>/Unit Delay'
                                      *   '<S173>/Unit Delay'
                                      *   '<S174>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S171>/Constant2'
                                      *   '<S172>/Constant2'
                                      *   '<S173>/Constant2'
                                      *   '<S174>/Constant2'
                                      *   '<S178>/Constant'
                                      *   '<S179>/Constant'
                                      *   '<S180>/Constant'
                                      *   '<S181>/Constant'
                                      */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S162>/Constant'
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
                                        * Referenced by: '<S151>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S151>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S151>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S151>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S151>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S151>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S151>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S151>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S147>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S147>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S147>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 2.7; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S147>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S147>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S147>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S147>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S147>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S148>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S148>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S148>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S148>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S148>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S148>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S148>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S148>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S136>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S136>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S136>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2725.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S161>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S161>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3265.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S161>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3425.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S161>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3625.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S161>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3775.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S161>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S161>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S161>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S160>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S160>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3450.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S160>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3600.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S160>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3800.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S160>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3950.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S160>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S160>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S160>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S154>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S154>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S154>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S154>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S154>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S154>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S154>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S154>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S158>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by:
                               *   '<S137>/Constant1'
                               *   '<S138>/Constant1'
                               *   '<S139>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by:
                                       *   '<S190>/Gain'
                                       *   '<S195>/Gain'
                                       *   '<S200>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by:
                                              *   '<S190>/Gain2'
                                              *   '<S195>/Gain2'
                                              *   '<S200>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.001;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                             * Referenced by:
                                             *   '<S190>/Gain1'
                                             *   '<S195>/Gain1'
                                             *   '<S200>/Gain1'
                                             */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S149>/Constant2'
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
                              * Referenced by: '<S141>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S205>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S205>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S205>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S432>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S430>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S432>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S433>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S433>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S265>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S265>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S212>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S225>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S265>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S372>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S372>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S372>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S372>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S372>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S372>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S390>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S390>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S390>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S390>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S389>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S390>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S390>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S390>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S390>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S390>/Constant1'
                                   *   '<S390>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S390>/Constant'
                                   *   '<S390>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S373>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S373>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S373>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S373>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S279>/Constant3'
                                        *   '<S300>/Constant3'
                                        *   '<S321>/Constant3'
                                        *   '<S342>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S279>/Constant2'
                                *   '<S300>/Constant2'
                                *   '<S321>/Constant2'
                                *   '<S342>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S279>/Saturation'
                                           *   '<S300>/Saturation'
                                           *   '<S321>/Saturation'
                                           *   '<S342>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S279>/Saturation'
                                          *   '<S300>/Saturation'
                                          *   '<S321>/Saturation'
                                          *   '<S342>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S279>/Gain2'
                                         *   '<S300>/Gain2'
                                         *   '<S321>/Gain2'
                                         *   '<S342>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S279>/Saturation1'
                                             *   '<S300>/Saturation1'
                                             *   '<S321>/Saturation1'
                                             *   '<S342>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S279>/Saturation1'
                                            *   '<S300>/Saturation1'
                                            *   '<S321>/Saturation1'
                                            *   '<S342>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S279>/Gain1'
                                        *   '<S300>/Gain1'
                                        *   '<S321>/Gain1'
                                        *   '<S342>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S371>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S371>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S371>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S371>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S371>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S371>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S432>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S432>/Constant1'
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
                                      * Referenced by: '<S431>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S431>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S431>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S359>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S359>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S359>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S359>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S359>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S359>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S433>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S432>/Dead Zone'
                                        *   '<S433>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S432>/Dead Zone'
                                        *   '<S433>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S430>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S430>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S430>/Constant4'
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
                                        * Referenced by: '<S430>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S430>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S430>/Constant5'
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
                                        *   '<S430>/Constant11'
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
  /* InitializeConditions for UnitDelay: '<S171>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * System reset for action system:
 *    '<S133>/If Action Subsystem1'
 *    '<S133>/If Action Subsystem3'
 */
void Robot__IfActionSubsystem1_Reset(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S171>/Unit Delay' */
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

  /* RelationalOperator: '<S178>/Compare' incorporates:
   *  Constant: '<S171>/Constant1'
   *  Constant: '<S178>/Constant'
   *  Sum: '<S171>/Sum'
   *  UnitDelay: '<S171>/Unit Delay'
   */
  rtb_Compare_cf = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S171>/Logical Operator' incorporates:
   *  Logic: '<S171>/NOT'
   */
  *rty_IsBlueActive = ((!(rtu_IsBlueInactiveFirst != 0.0)) || rtb_Compare_cf);

  /* Logic: '<S171>/Logical Operator1' */
  *rty_IsRedActive = ((rtu_IsBlueInactiveFirst != 0.0) || rtb_Compare_cf);

  /* Switch: '<S171>/Switch' incorporates:
   *  Constant: '<S171>/Constant1'
   *  Constant: '<S171>/Constant2'
   *  Logic: '<S171>/Logical Operator2'
   *  Sum: '<S171>/Subtract'
   *  Sum: '<S171>/Sum'
   *  UnitDelay: '<S171>/Unit Delay'
   */
  if ((boolean_T)((rtu_IsBlueInactiveFirst != 0.0) ^ (rtu_IsBlueAlliance != 0.0)))
  {
    *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;
  } else {
    *rty_Time_Remaining = (localDW->UnitDelay_DSTATE - 0.02) -
      Rebuilt_Match_Time_Shoot_Early;
  }

  /* End of Switch: '<S171>/Switch' */

  /* Update for UnitDelay: '<S171>/Unit Delay' incorporates:
   *  Constant: '<S171>/Constant1'
   *  Sum: '<S171>/Sum'
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
  real_T rtb_Add_du;
  real_T rtb_Add_fn;
  real_T rtb_Add_fp;
  real_T rtb_Add_gj;
  real_T rtb_Add_i;
  real_T rtb_Add_ir;
  real_T rtb_Add_k;
  real_T rtb_Add_l;
  real_T rtb_Add_md;
  real_T rtb_Error_c5;
  real_T rtb_Error_j;
  real_T rtb_Error_mx;
  real_T rtb_Error_n;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
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
  real_T rtb_Product_f;
  real_T rtb_Product_lu;
  real_T rtb_Product_ob;
  real_T rtb_Saturation_h;
  real_T rtb_Subtract1_gx;
  real_T rtb_Subtract1_la;
  real_T rtb_Subtract_ai;
  real_T rtb_Subtract_j3;
  real_T rtb_Subtract_ow;
  real_T rtb_Sum1;
  real_T rtb_Sum1_dj;
  real_T rtb_Sum1_fh;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1_h;
  real_T rtb_Switch1_hb;
  real_T rtb_Switch1_m;
  real_T rtb_Switch1_n;
  real_T rtb_Switch2_cc;
  real_T rtb_Switch2_hw;
  real_T rtb_Switch2_im;
  real_T rtb_Switch2_iq;
  real_T rtb_Switch2_kg;
  real_T rtb_Switch_hs;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s237_iter;
  uint16_T s262_iter;
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
  boolean_T rtb_AND4_j;
  boolean_T rtb_Compare_ky;
  boolean_T rtb_Compare_lk;
  boolean_T rtb_Compare_mq;
  boolean_T rtb_Compare_pb;
  boolean_T rtb_Disable_Wheels;
  boolean_T rtb_Enable_Wheels;
  boolean_T rtb_Intake_Arm_Cycle;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation_g;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_ms;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_Reset_Wheel_Offsets;
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
    rtb_Subtract_j3 = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Subtract_j3 = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S44>/Init' */

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Constant: '<S38>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_ai = Rate_Limit_X;
  } else {
    rtb_Subtract_ai = 1000.0;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Sum: '<S42>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Subtract_j3;

  /* Switch: '<S43>/Switch2' incorporates:
   *  RelationalOperator: '<S43>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Subtract_ai)) {
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
      rtb_Subtract_ai = rtb_Switch1_hb;
    } else {
      rtb_Subtract_ai = rtb_Sum1;
    }

    /* End of Switch: '<S43>/Switch' */
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Sum: '<S42>/Sum' */
  rtb_Sum1 = rtb_Subtract_ai + rtb_Subtract_j3;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S47>/Init' incorporates:
   *  UnitDelay: '<S47>/FixPt Unit Delay1'
   *  UnitDelay: '<S47>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_j != 0) {
    rtb_Subtract_ai = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Subtract_ai = Robot_Control_DW.FixPtUnitDelay1_DSTATE_a;
  }

  /* End of Switch: '<S47>/Init' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant2'
   *  Constant: '<S39>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_j3 = Rate_Limit_Y;
  } else {
    rtb_Subtract_j3 = 1000.0;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Sum: '<S45>/Sum1' */
  rtb_Switch1_hb = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Subtract_ai;

  /* Switch: '<S46>/Switch2' incorporates:
   *  RelationalOperator: '<S46>/LowerRelop1'
   */
  if (!(rtb_Switch1_hb > rtb_Subtract_j3)) {
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
      rtb_Subtract_j3 = rtb_Switch1_h;
    } else {
      rtb_Subtract_j3 = rtb_Switch1_hb;
    }

    /* End of Switch: '<S46>/Switch' */
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Sum: '<S45>/Sum' */
  rtb_Switch1_hb = rtb_Subtract_j3 + rtb_Subtract_ai;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S50>/Init' incorporates:
   *  UnitDelay: '<S50>/FixPt Unit Delay1'
   *  UnitDelay: '<S50>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Subtract_ai = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Subtract_ai = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S50>/Init' */

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Constant2'
   *  Constant: '<S40>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_j3 = Rate_Limit_Z;
  } else {
    rtb_Subtract_j3 = 1000.0;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Sum: '<S48>/Sum1' */
  rtb_Switch1_h = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Subtract_ai;

  /* Switch: '<S49>/Switch2' incorporates:
   *  RelationalOperator: '<S49>/LowerRelop1'
   */
  if (!(rtb_Switch1_h > rtb_Subtract_j3)) {
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
      rtb_Subtract_j3 = rtb_Switch1_m;
    } else {
      rtb_Subtract_j3 = rtb_Switch1_h;
    }

    /* End of Switch: '<S49>/Switch' */
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Sum: '<S48>/Sum' */
  rtb_Switch1_h = rtb_Subtract_j3 + rtb_Subtract_ai;

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
  rtb_Subtract_ai = rt_modd_snf(Robot_Control_U.Gyro_Angle_rad +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* RelationalOperator: '<S41>/GreaterThan' incorporates:
   *  Abs: '<S41>/Abs'
   *  Constant: '<S41>/Constant2'
   */
  rtb_Compare_ky = (fabs(rtb_Subtract_ai) > 1.5707963267948966);

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
  rtb_Compare_pb = (rtb_Subtract_ai > 0.0);

  /* Logic: '<S41>/Logical Operator5' incorporates:
   *  Logic: '<S41>/Logical Operator6'
   */
  rtb_LogicalOperator5 = (rtb_Compare_mq && (!rtb_Compare_pb));

  /* Logic: '<S41>/Logical Operator3' */
  rtb_Compare_pb = (rtb_Compare_mq && rtb_Compare_pb);

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

  /* If: '<S459>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S459>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S462>/Action Port'
     */
    /* Product: '<S462>/Product' incorporates:
     *  Constant: '<S462>/Constant1'
     *  Constant: '<S462>/Constant2'
     *  Math: '<S462>/Math Function'
     */
    rtb_Subtract_ai = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S459>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S459>/Subsystem' incorporates:
     *  ActionPort: '<S463>/Action Port'
     */
    /* SignalConversion generated from: '<S463>/Out1' incorporates:
     *  Constant: '<S463>/Constant'
     */
    rtb_Subtract_ai = 0.0;

    /* End of Outputs for SubSystem: '<S459>/Subsystem' */
  }

  /* End of If: '<S459>/If' */

  /* Gain: '<S460>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Subtract_j3 = 0.017453292519943295 *
    Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S461>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Subtract_ai * cos
    (rtb_Subtract_j3)) + Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S461>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Subtract_ai * sin
    (rtb_Subtract_j3)) + Vision_Object_Y_Offset;

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
  rtb_Add_fp = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_fp)) || (rtIsInf(rtb_Add_fp))) {
    rtb_Add_fp = 0.0;
  } else {
    rtb_Add_fp = fmod(rtb_Add_fp, 4.294967296E+9);
  }

  switch ((rtb_Add_fp < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_fp)))) :
          ((int32_T)((uint32_T)rtb_Add_fp))) {
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
    rtb_Compare_ky = false;

    /* SignalConversion generated from: '<S4>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S4>/Constant15'
     */
    rtb_Compare_mq = false;

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
    rtb_LogicalOperator1_ms = false;

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
      rtb_Subtract_j3 = 0.0;
    } else {
      rtb_Subtract_j3 = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
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
      rtb_Shooter_Active_prev = (rtb_Subtract_j3 >= Auto_Shoot_Time);
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
    rtb_Compare_pb = (Robot_Control_U.IsBlueAlliance != 0.0);

    /* Selector: '<S20>/Selector' */
    i = ((int32_T)Robot_Control_B.Auto_Path_ID) - 1;
    for (rtb_Num_Segments = 0; rtb_Num_Segments < 60; rtb_Num_Segments++) {
      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S20>/Constant1'
       *  Selector: '<S20>/Selector'
       */
      if (rtb_Compare_pb) {
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
      rtb_Compare_pb = false;
      break;

     case 1:
      rtb_Compare_pb = false;
      break;

     case 2:
      rtb_Compare_pb = true;
      break;

     case 3:
      rtb_Compare_pb = false;
      break;

     default:
      rtb_Compare_pb = false;
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
    if (((int32_T)rtb_Compare_pb) > ((int32_T)
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
      rtb_Compare_pb);

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     */
    switch ((int32_T)rtb_Switch_hs) {
     case 0:
      rtb_Compare_ky = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant'
       *  Constant: '<S22>/Constant4'
       */
      rtb_Compare_mq = false;

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
      rtb_LogicalOperator1_ms = false;
      break;

     case 1:
      rtb_Compare_ky = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant1'
       *  Constant: '<S22>/Constant5'
       */
      rtb_Compare_mq = false;

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
      rtb_LogicalOperator1_ms = false;
      break;

     case 2:
      rtb_Compare_ky = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant2'
       *  Constant: '<S22>/Constant7'
       */
      rtb_Compare_mq = true;

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
      rtb_LogicalOperator1_ms = false;
      break;

     case 3:
      rtb_Compare_ky = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant18'
       *  Constant: '<S22>/Constant6'
       */
      rtb_Compare_mq = false;

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
      rtb_LogicalOperator1_ms = true;
      break;

     default:
      rtb_Compare_ky = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant3'
       *  Constant: '<S22>/Constant8'
       */
      rtb_Compare_mq = false;

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
      rtb_LogicalOperator1_ms = false;
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
    Robot_Control_DW.DelayInput1_DSTATE_kb = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Subtract_j3;

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
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S31>/Delay Input1'
     *
     * Block description for '<S31>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_gf = rtb_Compare_pb;

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
       *  UnitDelay: '<S432>/Unit Delay1'
       *  UnitDelay: '<S432>/Unit Delay2'
       *  UnitDelay: '<S432>/Unit Delay3'
       *  UnitDelay: '<S432>/Unit Delay4'
       *  UnitDelay: '<S435>/Delay Input1'
       *  UnitDelay: '<S436>/Delay Input1'
       *  UnitDelay: '<S437>/Delay Input1'
       *  UnitDelay: '<S438>/Delay Input1'
       *  UnitDelay: '<S440>/Delay Input1'
       *  UnitDelay: '<S446>/Unit Delay'
       *  UnitDelay: '<S446>/Unit Delay1'
       *  UnitDelay: '<S450>/FixPt Unit Delay1'
       *  UnitDelay: '<S450>/FixPt Unit Delay2'
       *
       * Block description for '<S435>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S436>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S437>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S438>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S440>/Delay Input1':
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

    /* Switch: '<S430>/Switch4' incorporates:
     *  Constant: '<S455>/Constant'
     *  Constant: '<S458>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S455>/Compare'
     *  RelationalOperator: '<S458>/Compare'
     *  Switch: '<S430>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S430>/Switch4' incorporates:
       *  Constant: '<S430>/Constant8'
       *  Sum: '<S430>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S430>/Switch5' incorporates:
       *  Constant: '<S430>/Constant7'
       *  Gain: '<S430>/Gain'
       *  Sum: '<S430>/Subtract5'
       *  Switch: '<S430>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S430>/Switch4' incorporates:
       *  Constant: '<S430>/Constant6'
       *  Switch: '<S430>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S430>/Switch4' */

    /* Logic: '<S430>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S430>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S432>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_fp = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_fp = 0.0;
    } else {
      rtb_Add_fp = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S432>/Add' incorporates:
     *  Constant: '<S432>/Constant'
     *  Constant: '<S432>/Constant1'
     *  DeadZone: '<S432>/Dead Zone'
     *  Lookup_n-D: '<S432>/Modulation_Str_Y_Rel'
     *  Product: '<S432>/Product'
     *  Product: '<S432>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Add_fp * Steering_Twist_Gain);

    /* RelationalOperator: '<S434>/Compare' incorporates:
     *  Constant: '<S434>/Constant'
     */
    rtb_Compare_lk = (rtb_Switch1_m == 0.0);

    /* Logic: '<S432>/AND2' incorporates:
     *  RelationalOperator: '<S435>/FixPt Relational Operator'
     *  RelationalOperator: '<S436>/FixPt Relational Operator'
     *  RelationalOperator: '<S437>/FixPt Relational Operator'
     *  RelationalOperator: '<S438>/FixPt Relational Operator'
     *  UnitDelay: '<S435>/Delay Input1'
     *  UnitDelay: '<S436>/Delay Input1'
     *  UnitDelay: '<S437>/Delay Input1'
     *  UnitDelay: '<S438>/Delay Input1'
     *
     * Block description for '<S435>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S436>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S437>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S438>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Intake_Arm_Cycle = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_Compare_pb) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S432>/AND1' incorporates:
     *  Logic: '<S432>/AND3'
     *  UnitDelay: '<S432>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_lk && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S432>/AND4' incorporates:
     *  Logic: '<S432>/AND8'
     *  UnitDelay: '<S432>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_lk && (!rtb_Intake_Arm_Cycle)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S432>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* Switch: '<S432>/Switch8' incorporates:
     *  Constant: '<S441>/Constant'
     *  Logic: '<S432>/AND9'
     *  RelationalOperator: '<S440>/FixPt Relational Operator'
     *  RelationalOperator: '<S441>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S440>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S440>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_lk) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S432>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S432>/Switch8' incorporates:
       *  UnitDelay: '<S432>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S432>/Switch8' */

    /* Switch: '<S432>/Switch4' incorporates:
     *  Constant: '<S432>/Constant5'
     *  Switch: '<S432>/Switch1'
     *  Switch: '<S432>/Switch5'
     *  Switch: '<S432>/Switch6'
     *  Switch: '<S432>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Saturation_h = 0.0;
    } else if (rtb_Compare_pb) {
      /* Switch: '<S432>/Switch5' incorporates:
       *  Constant: '<S432>/Constant6'
       */
      rtb_Saturation_h = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S432>/Switch6' incorporates:
       *  Constant: '<S432>/Constant7'
       *  Switch: '<S432>/Switch5'
       */
      rtb_Saturation_h = 3.1415926535897931;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S432>/Switch7' incorporates:
       *  Constant: '<S432>/Constant8'
       *  Switch: '<S432>/Switch5'
       *  Switch: '<S432>/Switch6'
       */
      rtb_Saturation_h = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S432>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S432>/Switch5'
       *  Switch: '<S432>/Switch6'
       *  Switch: '<S432>/Switch7'
       */
      rtb_Saturation_h = 0.0;
    } else {
      /* Switch: '<S432>/Switch6' incorporates:
       *  Switch: '<S432>/Switch5'
       *  Switch: '<S432>/Switch7'
       *  UnitDelay: '<S432>/Unit Delay1'
       */
      rtb_Saturation_h = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S432>/Switch4' */

    /* Switch: '<S432>/Switch2' incorporates:
     *  Switch: '<S432>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S432>/Switch2' incorporates:
       *  Constant: '<S432>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S432>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Saturation_h;
    } else {
      /* Switch: '<S432>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S432>/Switch3' incorporates:
       *  Constant: '<S432>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S432>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S432>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S431>/Switch1' incorporates:
     *  Constant: '<S431>/Constant5'
     *  Constant: '<S431>/Constant8'
     *  DataTypeConversion: '<S431>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_lk;
    }

    /* End of Switch: '<S431>/Switch1' */

    /* Lookup_n-D: '<S433>/Modulation_Drv' incorporates:
     *  Math: '<S433>/Magnitude'
     */
    rtb_Switch_hs = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S444>/Compare' incorporates:
     *  Constant: '<S444>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Switch_hs == 0.0);

    /* DeadZone: '<S433>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_Switch1_n = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S433>/Dead Zone' */

    /* Logic: '<S433>/Logical Operator' incorporates:
     *  Constant: '<S445>/Constant'
     *  RelationalOperator: '<S445>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Switch1_n != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S431>/Switch' incorporates:
     *  Constant: '<S431>/Constant5'
     *  Constant: '<S431>/Constant7'
     *  DataTypeConversion: '<S431>/Data Type Conversion'
     *  Logic: '<S433>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S431>/Switch' */

    /* Switch: '<S430>/Switch2' incorporates:
     *  Constant: '<S430>/Constant2'
     *  Constant: '<S454>/Constant'
     *  Constant: '<S457>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S454>/Compare'
     *  RelationalOperator: '<S457>/Compare'
     *  Sum: '<S430>/Subtract'
     *  Switch: '<S430>/Switch'
     *  Switch: '<S430>/Switch1'
     *  Switch: '<S430>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S430>/Switch2' incorporates:
       *  Constant: '<S430>/Constant5'
       *  Sum: '<S430>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_iq = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S430>/Switch2' incorporates:
       *  Constant: '<S430>/Constant4'
       *  Sum: '<S430>/Subtract2'
       *  Switch: '<S430>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S430>/Switch1' incorporates:
       *  Constant: '<S430>/Constant1'
       *  Sum: '<S430>/Subtract3'
       */
      rtb_Switch2_iq = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S430>/Switch2' incorporates:
       *  Constant: '<S430>/Constant3'
       *  Switch: '<S430>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S430>/Switch1' incorporates:
       *  Constant: '<S430>/Constant'
       */
      rtb_Switch2_iq = 0.0;
    }

    /* End of Switch: '<S430>/Switch2' */

    /* UnaryMinus: '<S430>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_iq;

    /* Switch: '<S446>/Switch1' incorporates:
     *  Constant: '<S451>/Constant'
     *  Constant: '<S452>/Constant'
     *  Logic: '<S446>/AND'
     *  RelationalOperator: '<S451>/Compare'
     *  RelationalOperator: '<S452>/Compare'
     *  Switch: '<S446>/Switch2'
     *  UnitDelay: '<S446>/Unit Delay'
     *  UnitDelay: '<S446>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Subtract_j3 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_hw = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Subtract_j3 = rtb_Switch1_hb;
      rtb_Switch2_hw = rtb_Sum1;
    }

    /* End of Switch: '<S446>/Switch1' */

    /* Switch: '<S433>/Switch1' incorporates:
     *  Logic: '<S433>/Logical Operator1'
     *  Switch: '<S433>/Switch4'
     *  Switch: '<S433>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S433>/Sign' */
      if (rtIsNaN(rtb_Switch1_n)) {
        rtb_Add_fp = (rtNaN);
      } else if (rtb_Switch1_n < 0.0) {
        rtb_Add_fp = -1.0;
      } else {
        rtb_Add_fp = (rtb_Switch1_n > 0.0);
      }

      /* Switch: '<S433>/Switch5' incorporates:
       *  Constant: '<S433>/Constant3'
       *  Constant: '<S433>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_k = -1.5707963267948966;
      } else {
        rtb_Add_k = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S433>/Gain3'
       *  Signum: '<S433>/Sign'
       *  Sum: '<S433>/Add'
       *  Switch: '<S433>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_fp) +
        rtb_Add_k;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S433>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S433>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S433>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S433>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S433>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S433>/Switch4'
       *  Trigonometry: '<S433>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Subtract_j3,
        rtb_Switch2_hw);
    }

    /* End of Switch: '<S433>/Switch1' */

    /* Switch: '<S443>/Switch1' incorporates:
     *  Constant: '<S443>/Constant'
     *  Constant: '<S443>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_iq = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_iq = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S443>/Switch1' */

    /* Switch: '<S450>/Init' incorporates:
     *  UnitDelay: '<S450>/FixPt Unit Delay1'
     *  UnitDelay: '<S450>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Subtract_ai = rtb_Switch2_iq;
    } else {
      rtb_Subtract_ai = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S450>/Init' */

    /* Sum: '<S448>/Sum1' */
    rtb_Switch2_iq -= rtb_Subtract_ai;

    /* Switch: '<S449>/Switch2' incorporates:
     *  Constant: '<S447>/Constant1'
     *  Constant: '<S447>/Constant3'
     *  RelationalOperator: '<S449>/LowerRelop1'
     *  RelationalOperator: '<S449>/UpperRelop'
     *  Switch: '<S449>/Switch'
     */
    if (rtb_Switch2_iq > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_iq = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_iq < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S449>/Switch' incorporates:
       *  Constant: '<S447>/Constant1'
       */
      rtb_Switch2_iq = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S449>/Switch2' */

    /* Sum: '<S448>/Sum' */
    rtb_Subtract_ai += rtb_Switch2_iq;

    /* Switch: '<S433>/Switch8' incorporates:
     *  Logic: '<S433>/Logical Operator1'
     *  Switch: '<S433>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S433>/Switch' incorporates:
       *  Gain: '<S433>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Switch1_n;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S433>/Constant5'
       *  Gain: '<S433>/Gain2'
       *  Math: '<S433>/Magnitude1'
       *  MinMax: '<S433>/Min'
       *  Switch: '<S433>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S443>/Product' incorporates:
       *  Switch: '<S433>/Switch2'
       */
      rtb_Add_fp = rtb_Switch_hs * rtb_Subtract_ai;

      /* Saturate: '<S443>/Saturation' incorporates:
       *  Switch: '<S433>/Switch2'
       */
      if (rtb_Add_fp > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_fp < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_fp;
      }

      /* End of Saturate: '<S443>/Saturation' */
    }

    /* End of Switch: '<S433>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S432>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Switch: '<S430>/Switch6' incorporates:
     *  Constant: '<S430>/Constant11'
     *  Switch: '<S430>/Switch7'
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

    /* RelationalOperator: '<S426>/Compare' incorporates:
     *  Constant: '<S426>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Compare_ky = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S427>/Compare' incorporates:
     *  Constant: '<S427>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Compare_mq = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S422>/Compare' incorporates:
     *  Constant: '<S422>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S425>/Compare' incorporates:
     *  Constant: '<S425>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S424>/Compare' incorporates:
     *  Constant: '<S424>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Constant: '<S423>/Constant'
     *  Constant: '<S428>/Constant'
     *  Inport: '<Root>/Gamepad_LT'
     *  Inport: '<Root>/Joystick_Right_B1'
     *  RelationalOperator: '<S423>/Compare'
     *  RelationalOperator: '<S428>/Compare'
     */
    rtb_LogicalOperator1_ms = ((Robot_Control_U.Joystick_Right_B1 != 0.0) ||
      (Robot_Control_U.Gamepad_LT != 0.0));

    /* SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     */
    rtb_Switch1_m = 0.0;

    /* Update for UnitDelay: '<S440>/Delay Input1'
     *
     * Block description for '<S440>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_lk;

    /* Update for UnitDelay: '<S439>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S439>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S435>/Delay Input1'
     *
     * Block description for '<S435>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S436>/Delay Input1'
     *
     * Block description for '<S436>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_Compare_pb;

    /* Update for UnitDelay: '<S437>/Delay Input1'
     *
     * Block description for '<S437>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S438>/Delay Input1'
     *
     * Block description for '<S438>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S432>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S432>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S432>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S432>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S446>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Subtract_j3;

    /* Update for UnitDelay: '<S446>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2_hw;

    /* Update for UnitDelay: '<S450>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S450>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S450>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Subtract_ai;

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
    rtb_Compare_ky = false;

    /* SignalConversion generated from: '<S16>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S16>/Constant15'
     */
    rtb_Compare_mq = false;

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
    rtb_LogicalOperator1_ms = false;

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
    rtb_Subtract_j3 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Subtract_j3;

    /* Sum: '<S124>/Sum' incorporates:
     *  Constant: '<S73>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S124>/C[k]*xhat[k|k-1]'
     *  Product: '<S124>/D[k]*u[k]'
     *  Sum: '<S124>/Add1'
     */
    rtb_Switch2_hw = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Saturation_h = rtb_Reshapey[0] - (rtb_Switch2_hw + rtb_Subtract_j3);

    /* Product: '<S124>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S73>/C'
     *  Delay: '<S73>/MemoryX'
     *  Product: '<S126>/Product'
     */
    rtb_Subtract_j3 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Subtract_j3;

    /* Sum: '<S124>/Sum' incorporates:
     *  Constant: '<S73>/D'
     *  Product: '<S124>/C[k]*xhat[k|k-1]'
     *  Product: '<S124>/D[k]*u[k]'
     *  Sum: '<S124>/Add1'
     */
    rtb_Switch2_hw = rtb_Reshapey[1] - (rtb_Switch2_hw + rtb_Subtract_j3);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S124>/Product3' incorporates:
     *  Constant: '<S74>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Saturation_h) +
      (-2.0601714451538746E-17 * rtb_Switch2_hw);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Product'
     */
    rtb_Subtract_j3 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S124>/Product3' incorporates:
     *  Constant: '<S74>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Saturation_h) +
      (0.095124921972504 * rtb_Switch2_hw);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Product'
     */
    rtb_Switch2_hw = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S126>/Product2' incorporates:
     *  Constant: '<S74>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Subtract_j3) +
      (5.9896845167210271E-17 * rtb_Switch2_hw);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Subtract_j3) +
      (0.095124921972503981 * rtb_Switch2_hw);
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
   *  Constant: '<S262>/Constant'
   *  Logic: '<S262>/AND'
   *  MATLAB Function: '<S212>/Find closest index to curve'
   *  Product: '<S262>/Product'
   *  RelationalOperator: '<S262>/Relational Operator'
   *  RelationalOperator: '<S262>/Relational Operator1'
   *  Selector: '<S262>/Selector'
   *  Selector: '<S262>/Selector1'
   *  Selector: '<S263>/Selector'
   *  Sum: '<S262>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S215>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S218>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S220>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S215>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S210>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S210>/Unit Delay'
       *  UnitDelay: '<S211>/Unit Delay'
       *  UnitDelay: '<S213>/Unit Delay'
       *  UnitDelay: '<S213>/Unit Delay1'
       *  UnitDelay: '<S263>/Unit Delay'
       *  UnitDelay: '<S263>/Unit Delay1'
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
     *  ActionPort: '<S210>/Action Port'
     */
    /* Selector: '<S211>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S211>/Selector1' */

    /* Lookup_n-D: '<S210>/Capture Radius' incorporates:
     *  UnitDelay: '<S210>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S211>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S211>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S215>/If' incorporates:
     *  RelationalOperator: '<S215>/ '
     *  UnitDelay: '<S211>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S218>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S220>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S215>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S218>/Action Port'
       */
      /* InitializeConditions for If: '<S215>/If' incorporates:
       *  UnitDelay: '<S218>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S215>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S215>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S218>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S218>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S221>/Action Port'
       */
      /* If: '<S218>/If' incorporates:
       *  Selector: '<S211>/Selector1'
       *  Selector: '<S218>/Selector'
       *  Selector: '<S221>/Selector'
       */
      rtb_Subtract_ai = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S218>/Increment_If_Rectangle_Check' */

      /* Sum: '<S218>/Minus' incorporates:
       *  Concatenate: '<S211>/Matrix Concatenate2'
       *  Selector: '<S218>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Subtract_ai;

      /* Outputs for IfAction SubSystem: '<S218>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S221>/Action Port'
       */
      /* If: '<S218>/If' incorporates:
       *  Selector: '<S211>/Selector1'
       *  Selector: '<S218>/Selector'
       *  Selector: '<S221>/Selector'
       *  Sum: '<S218>/Minus'
       */
      rtb_Switch_hs = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S218>/Increment_If_Rectangle_Check' */

      /* Sum: '<S218>/Minus' incorporates:
       *  Concatenate: '<S211>/Matrix Concatenate2'
       *  Selector: '<S218>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Switch_hs;

      /* Math: '<S218>/Hypot' */
      rtb_Subtract_j3 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S218>/Equal' */
      rtb_LogicalOperator5 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S218>/Switch' incorporates:
       *  Logic: '<S218>/AND'
       *  Logic: '<S218>/OR'
       *  RelationalOperator: '<S218>/Relational Operator'
       *  UnitDelay: '<S218>/Unit Delay'
       */
      rtb_LogicalOperator1 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Subtract_j3 <= rtb_Saturation_h) && rtb_LogicalOperator5));

      /* If: '<S218>/If' */
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
        /* Disable for If: '<S220>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S218>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S220>/Action Port'
         */
        /* If: '<S220>/If' incorporates:
         *  RelationalOperator: '<S220>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S220>/Is_Last_Point' incorporates:
           *  ActionPort: '<S223>/Action Port'
           */
          /* InitializeConditions for If: '<S220>/If' incorporates:
           *  UnitDelay: '<S223>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S220>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S220>/Is_Last_Point' incorporates:
           *  ActionPort: '<S223>/Action Port'
           */
          /* Switch: '<S223>/Switch' incorporates:
           *  Constant: '<S225>/Constant'
           *  Logic: '<S223>/OR'
           *  RelationalOperator: '<S225>/Compare'
           *  UnitDelay: '<S223>/Unit Delay'
           */
          rtb_Is_Absolute_Translation_g = ((Robot_Control_DW.UnitDelay_DSTATE_nu)
            || (rtb_Subtract_j3 <= Spline_Stop_Radius));

          /* If: '<S223>/If' */
          if (rtb_Is_Absolute_Translation_g) {
            /* Outputs for IfAction SubSystem: '<S223>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S226>/Action Port'
             */
            /* Merge: '<S215>/Merge2' incorporates:
             *  Constant: '<S226>/Constant'
             *  SignalConversion generated from: '<S226>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = true;

            /* SignalConversion generated from: '<S226>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S226>/Constant1'
             */
            rtb_Compare_pb = false;

            /* End of Outputs for SubSystem: '<S223>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S223>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S227>/Action Port'
             */
            /* Merge: '<S215>/Merge2' incorporates:
             *  Constant: '<S227>/Constant'
             *  SignalConversion generated from: '<S227>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = false;

            /* SignalConversion generated from: '<S227>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S227>/Constant1'
             */
            rtb_Compare_pb = true;

            /* End of Outputs for SubSystem: '<S223>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S223>/If' */

          /* Merge: '<S215>/Merge4' incorporates:
           *  SignalConversion: '<S223>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S223>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Is_Absolute_Translation_g;

          /* End of Outputs for SubSystem: '<S220>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S220>/Increment_Search' incorporates:
           *  ActionPort: '<S222>/Action Port'
           */
          /* Merge: '<S215>/Merge2' incorporates:
           *  Constant: '<S222>/Constant'
           *  SignalConversion generated from: '<S222>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator5 = false;

          /* SignalConversion generated from: '<S222>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S222>/Constant1'
           */
          rtb_Compare_pb = false;

          /* Merge: '<S215>/Merge4' incorporates:
           *  Constant: '<S224>/FixPt Constant'
           *  SignalConversion: '<S222>/Signal Copy'
           *  Sum: '<S224>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S220>/Increment_Search' */
        }

        /* End of If: '<S220>/If' */
        /* End of Outputs for SubSystem: '<S218>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S218>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S221>/Action Port'
         */
        /* Sum: '<S228>/FixPt Sum1' incorporates:
         *  Constant: '<S228>/FixPt Constant'
         */
        rtb_Subtract_j3 = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S221>/Selector1' incorporates:
         *  Selector: '<S211>/Selector1'
         */
        rtb_Add_md = rtb_Ref_Poses[((int32_T)rtb_Subtract_j3) - 1];

        /* Sum: '<S229>/Subtract' incorporates:
         *  Selector: '<S221>/Selector1'
         *  Sum: '<S229>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Add_md - rtb_Subtract_ai;

        /* Selector: '<S221>/Selector1' incorporates:
         *  Selector: '<S211>/Selector1'
         */
        rtb_Switch1_n = rtb_Ref_Poses[((int32_T)rtb_Subtract_j3) + 9];

        /* Sum: '<S229>/Subtract' incorporates:
         *  Selector: '<S221>/Selector1'
         *  Sum: '<S229>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1_n - rtb_Switch_hs;

        /* Math: '<S229>/Hypot' */
        rtb_Switch2_hw = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S229>/Divide' */
        rtb_Subtract_j3 = rtb_Minus_n[1];

        /* UnaryMinus: '<S229>/Unary Minus' */
        rtb_Switch2_iq = rtb_Minus_n[0];

        /* Product: '<S229>/Product' incorporates:
         *  Product: '<S229>/Divide'
         *  UnaryMinus: '<S229>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Subtract_j3 / rtb_Switch2_hw) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Switch2_iq) / rtb_Switch2_hw) * rtb_Saturation_h;

        /* Sum: '<S229>/Add1' incorporates:
         *  Sum: '<S229>/Add2'
         *  Sum: '<S229>/Minus'
         */
        rtb_Switch2_iq = rtb_Add_md - rtb_Minus_n[0];

        /* Sum: '<S229>/Minus4' incorporates:
         *  Sum: '<S229>/Add2'
         *  Sum: '<S229>/Minus'
         */
        rtb_Add_md = (rtb_Add_md + rtb_Minus_n[0]) - rtb_Switch2_iq;

        /* Sum: '<S229>/Minus5' incorporates:
         *  Concatenate: '<S211>/Matrix Concatenate2'
         *  Sum: '<S229>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[0] - rtb_Switch2_iq;

        /* Sum: '<S229>/Add' incorporates:
         *  Sum: '<S229>/Add2'
         *  Sum: '<S229>/Minus1'
         */
        rtb_Subtract_j3 = rtb_Subtract_ai - rtb_Minus_n[0];

        /* Sum: '<S229>/Minus' incorporates:
         *  Sum: '<S229>/Minus1'
         */
        rtb_Switch2_iq -= rtb_Subtract_j3;

        /* DotProduct: '<S229>/Dot Product' incorporates:
         *  Concatenate: '<S211>/Matrix Concatenate2'
         *  Sum: '<S229>/Minus'
         *  Sum: '<S229>/Minus1'
         *  Sum: '<S229>/Minus5'
         */
        rtb_Switch2_hw = (rtb_Reshapey[0] - rtb_Subtract_j3) * rtb_Switch2_iq;

        /* DotProduct: '<S229>/Dot Product1' incorporates:
         *  Sum: '<S229>/Minus'
         */
        rtb_Subtract_ai = rtb_Switch2_iq * rtb_Switch2_iq;

        /* DotProduct: '<S229>/Dot Product2' incorporates:
         *  Sum: '<S229>/Minus4'
         *  Sum: '<S229>/Minus5'
         */
        rtb_Minus_k_idx_0 = rtb_Add_md * rtb_MatrixConcatenate_b_idx_0;

        /* DotProduct: '<S229>/Dot Product3' incorporates:
         *  Sum: '<S229>/Minus4'
         */
        rtb_Switch2_cc = rtb_Add_md * rtb_Add_md;

        /* Sum: '<S229>/Add1' incorporates:
         *  Sum: '<S229>/Add2'
         *  Sum: '<S229>/Minus'
         */
        rtb_Switch2_iq = rtb_Switch1_n - rtb_Minus_n[1];

        /* Sum: '<S229>/Minus4' incorporates:
         *  Sum: '<S229>/Add2'
         *  Sum: '<S229>/Minus'
         */
        rtb_Add_md = (rtb_Switch1_n + rtb_Minus_n[1]) - rtb_Switch2_iq;

        /* Sum: '<S229>/Minus5' incorporates:
         *  Concatenate: '<S211>/Matrix Concatenate2'
         *  Sum: '<S229>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[1] - rtb_Switch2_iq;

        /* Sum: '<S229>/Add' incorporates:
         *  Sum: '<S229>/Add2'
         *  Sum: '<S229>/Minus1'
         */
        rtb_Subtract_j3 = rtb_Switch_hs - rtb_Minus_n[1];

        /* Sum: '<S229>/Minus' incorporates:
         *  Sum: '<S229>/Minus1'
         */
        rtb_Switch2_iq -= rtb_Subtract_j3;

        /* DotProduct: '<S229>/Dot Product' incorporates:
         *  Concatenate: '<S211>/Matrix Concatenate2'
         *  Sum: '<S229>/Minus'
         *  Sum: '<S229>/Minus1'
         *  Sum: '<S229>/Minus5'
         */
        rtb_Switch2_hw += (rtb_Reshapey[1] - rtb_Subtract_j3) * rtb_Switch2_iq;

        /* RelationalOperator: '<S230>/Compare' incorporates:
         *  Constant: '<S230>/Constant'
         */
        rtb_LogicalOperator5 = (rtb_Switch2_hw >= 0.0);

        /* RelationalOperator: '<S229>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S229>/Dot Product1'
         *  Sum: '<S229>/Minus'
         */
        rtb_Compare_pb = (rtb_Switch2_hw <= ((rtb_Switch2_iq * rtb_Switch2_iq) +
          rtb_Subtract_ai));

        /* DotProduct: '<S229>/Dot Product2' incorporates:
         *  Sum: '<S229>/Minus4'
         *  Sum: '<S229>/Minus5'
         */
        rtb_Switch2_hw = (rtb_Add_md * rtb_MatrixConcatenate_b_idx_0) +
          rtb_Minus_k_idx_0;

        /* Merge: '<S215>/Merge4' incorporates:
         *  Constant: '<S231>/Constant'
         *  DataTypeConversion: '<S221>/Data Type Conversion'
         *  DotProduct: '<S229>/Dot Product3'
         *  Logic: '<S229>/AND'
         *  RelationalOperator: '<S229>/LessThanOrEqual1'
         *  RelationalOperator: '<S231>/Compare'
         *  Sum: '<S221>/Add'
         *  Sum: '<S229>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_LogicalOperator5 &&
          rtb_Compare_pb) && (rtb_Switch2_hw >= 0.0)) && (rtb_Switch2_hw <=
          ((rtb_Add_md * rtb_Add_md) + rtb_Switch2_cc)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S215>/Merge2' incorporates:
         *  Constant: '<S221>/Constant2'
         *  SignalConversion generated from: '<S221>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S221>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S221>/Constant1'
         */
        rtb_Compare_pb = false;

        /* End of Outputs for SubSystem: '<S218>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S218>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S219>/Action Port'
         */
        /* Merge: '<S215>/Merge2' incorporates:
         *  Constant: '<S219>/Constant2'
         *  SignalConversion generated from: '<S219>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S219>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S219>/Constant1'
         */
        rtb_Compare_pb = false;

        /* Merge: '<S215>/Merge4' incorporates:
         *  SignalConversion generated from: '<S219>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S218>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S215>/Merge1' incorporates:
       *  Constant: '<S218>/Constant'
       *  SignalConversion generated from: '<S218>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S218>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator1;

      /* End of Outputs for SubSystem: '<S215>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S215>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S217>/Action Port'
       */
      /* Merge: '<S215>/Merge1' incorporates:
       *  Constant: '<S217>/Constant'
       *  SignalConversion generated from: '<S217>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S215>/Merge2' incorporates:
       *  Constant: '<S217>/Constant1'
       *  SignalConversion generated from: '<S217>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator5 = false;

      /* SignalConversion generated from: '<S217>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S217>/Constant2'
       */
      rtb_Compare_pb = false;

      /* Merge: '<S215>/Merge4' incorporates:
       *  SignalConversion generated from: '<S217>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S215>/Escape_Auto_Driving' */
    }

    /* End of If: '<S215>/If' */

    /* If: '<S211>/If1' */
    if (!rtb_Compare_pb) {
      /* Outputs for IfAction SubSystem: '<S211>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S216>/Action Port'
       */
      /* Bias: '<S232>/Add Constant' incorporates:
       *  Bias: '<S232>/Bias'
       *  Sum: '<S232>/Subtract'
       */
      rtb_Subtract_j3 = ((Robot_Control_B.Spline_Num_Poses -
                          Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S232>/Selector4' incorporates:
       *  Bias: '<S232>/Bias1'
       *  Constant: '<S234>/FixPt Constant'
       *  Sum: '<S234>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S232>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S232>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s237_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S232>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S232>/Selector5' incorporates:
       *  Concatenate: '<S232>/Matrix Concatenate'
       *  Gain: '<S236>/Gain'
       *  Selector: '<S211>/Selector1'
       *  Selector: '<S232>/Selector2'
       *  Selector: '<S232>/Selector3'
       *  Sum: '<S236>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s237_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S232>/Matrix Concatenate' incorporates:
       *  Bias: '<S232>/Add Constant1'
       *  Gain: '<S235>/Gain'
       *  Selector: '<S211>/Selector1'
       *  Selector: '<S232>/Selector'
       *  Selector: '<S232>/Selector1'
       *  Selector: '<S232>/Selector5'
       *  Sum: '<S235>/Subtract'
       */
      s237_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s237_iter;
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

      /* Selector: '<S232>/Selector4' */
      s237_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s237_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S232>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S232>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S232>/Assignment' incorporates:
       *  Concatenate: '<S232>/Matrix Concatenate'
       *  Selector: '<S232>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s237_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S233>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S237>/While Iterator'
       */
      s237_iter = 1;
      do {
        rtb_Subtract_ai = rtb_Assignment[s237_iter + 1];
        rtb_Minus_n[0] = rtb_Subtract_ai - rtb_Assignment[s237_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s237_iter] - rtb_Assignment[s237_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Subtract_ai - rtb_Assignment[s237_iter];
        rtb_Subtract_ai = rtb_Assignment[s237_iter + 13];
        rtb_Minus_n[1] = rtb_Subtract_ai - rtb_Assignment[s237_iter + 11];
        rtb_Add_md = rtb_Assignment[s237_iter + 12];
        rtb_Add2[1] = rtb_Add_md - rtb_Assignment[s237_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Subtract_ai - rtb_Add_md;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Switch2_hw = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Switch_hs = rt_powd_snf(rtb_Switch2_hw, 2.0);
          rtb_Switch2_iq = rt_powd_snf(rtb_Switch2_hw, 3.0);
          rtb_Switch1_n = (rtb_Switch2_hw - (2.0 * rtb_Switch_hs)) +
            rtb_Switch2_iq;
          rtb_Subtract_ai = rtb_Switch_hs - rtb_Switch2_iq;
          rtb_Switch2_iq = (3.0 * rtb_Switch_hs) - (2.0 * rtb_Switch2_iq);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch1_n) +
            (rtb_Add2[0] * rtb_Subtract_ai)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Switch2_iq)) + rtb_Assignment[s237_iter];
          rtb_Switch2_iq = ((((rtb_Minus_n[1] * rtb_Switch1_n) + (rtb_Add2[1] *
            rtb_Subtract_ai)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_iq)) +
            rtb_Add_md;
          rtb_Switch1_n = ((3.0 * rtb_Switch_hs) - (4.0 * rtb_Switch2_hw)) + 1.0;
          rtb_Subtract_ai = (2.0 * rtb_Switch2_hw) - (3.0 * rtb_Switch_hs);
          rtb_Switch_hs = (rtb_Switch2_hw - rtb_Switch_hs) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch1_n) +
            (rtb_Add2[0] * rtb_Subtract_ai)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Switch_hs);
          rtb_Switch2_cc = (((rtb_Minus_n[1] * rtb_Switch1_n) + (rtb_Add2[1] *
            rtb_Subtract_ai)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch_hs);
          rtb_Switch_hs = (6.0 * rtb_Switch2_hw) - 4.0;
          rtb_Switch1_n = (-6.0 * rtb_Switch2_hw) + 2.0;
          rtb_Switch2_hw = (-12.0 * rtb_Switch2_hw) + 6.0;
          rtb_Subtract_ai = (((rtb_Minus_n[0] * rtb_Switch_hs) + (rtb_Add2[0] *
            rtb_Switch1_n)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Switch2_hw);
          rtb_Switch1_n = (((rtb_Minus_n[1] * rtb_Switch_hs) + (rtb_Add2[1] *
            rtb_Switch1_n)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_hw);
          rtb_Switch_hs = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Switch2_cc), 3.0);
          rtb_Switch2_hw = fmax(1.0E-10, rtb_Switch_hs);
          Robot_Control_DW.Relay_Mode = ((rtb_Switch_hs >=
            2.2204460492503131E-16) || (Robot_Control_DW.Relay_Mode));
          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Switch2_iq;
          if (Robot_Control_DW.Relay_Mode) {
            i = 1;
          } else {
            i = -1;
          }

          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch1_n) - (rtb_Subtract_ai *
              rtb_Switch2_cc)) / (rtb_Switch2_hw * ((real_T)i));
        }

        if (s237_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s237_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Switch2_hw = rtb_Subtract_j3 - ((real_T)s237_iter);
        rtb_Num_Segments = s237_iter;
        s237_iter++;
      } while ((rtb_Switch2_hw >= 4.0) && (s237_iter <= 3));

      /* End of Outputs for SubSystem: '<S233>/Sampling_Loop' */

      /* SignalConversion generated from: '<S216>/Position_and_Curvature' incorporates:
       *  Assignment: '<S237>/Assignment'
       *  Merge: '<S211>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S211>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S211>/If Action Subsystem' incorporates:
       *  ActionPort: '<S214>/Action Port'
       */
      /* Product: '<S214>/Product' incorporates:
       *  Selector: '<S211>/Selector'
       *  Selector: '<S211>/Selector1'
       */
      rtb_Switch2_hw = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S214>/Product1' incorporates:
       *  Selector: '<S211>/Selector'
       *  Selector: '<S211>/Selector1'
       */
      rtb_Subtract_j3 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S214>/Product' incorporates:
         *  Constant: '<S214>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Switch2_hw;

        /* Product: '<S214>/Product1' incorporates:
         *  Constant: '<S214>/Constant2'
         *  Product: '<S214>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Subtract_j3;
      }

      /* Assignment: '<S214>/Assignment' incorporates:
       *  Concatenate: '<S214>/Matrix Concatenate'
       *  Merge: '<S211>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S214>/Assignment' */

      /* SignalConversion generated from: '<S214>/Num_Segments' incorporates:
       *  Constant: '<S214>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S211>/If Action Subsystem' */
    }

    /* End of If: '<S211>/If1' */

    /* Concatenate: '<S212>/Matrix Concatenate' incorporates:
     *  Merge: '<S211>/Merge'
     *  Selector: '<S212>/Selector'
     *  Selector: '<S212>/Selector1'
     *  Selector: '<S212>/Selector3'
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

    /* End of Concatenate: '<S212>/Matrix Concatenate' */

    /* MATLAB Function: '<S212>/Distance Along Curve' incorporates:
     *  Concatenate: '<S212>/Matrix Concatenate'
     *  Selector: '<S212>/Selector4'
     *  Selector: '<S212>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s237_iter = 0; s237_iter < 149; s237_iter++) {
      /* Outputs for Iterator SubSystem: '<S233>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S237>/While Iterator'
       */
      rtb_Assignment_d[s237_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s237_iter + 1] -
         rtb_MatrixConcatenate_o[s237_iter], rtb_MatrixConcatenate_o[s237_iter +
         151] - rtb_MatrixConcatenate_o[s237_iter + 150]) +
        rtb_Assignment_d[s237_iter];

      /* End of Outputs for SubSystem: '<S233>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S212>/Distance Along Curve' */

    /* MATLAB Function: '<S212>/Find closest index to curve' incorporates:
     *  Concatenate: '<S212>/Matrix Concatenate'
     *  Selector: '<S212>/Selector4'
     *  Selector: '<S212>/Selector5'
     *  Selector: '<S263>/Selector'
     */
    for (s237_iter = 0; s237_iter < 150; s237_iter++) {
      /* Outputs for Iterator SubSystem: '<S233>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S237>/While Iterator'
       */
      distance_from_robot[s237_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s237_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s237_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S233>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s237_iter = 1;
    } else {
      s237_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s237_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s237_iter == 0) {
      rtb_Subtract_j3 = distance_from_robot[0];
    } else {
      rtb_Subtract_j3 = distance_from_robot[s237_iter - 1];
      for (rtb_Bias1_p = s237_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Switch2_hw = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Subtract_j3 > rtb_Switch2_hw) {
          rtb_Subtract_j3 = rtb_Switch2_hw;
        }
      }
    }

    s237_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s237_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Subtract_j3) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S263>/Selector' incorporates:
     *  Constant: '<S263>/Constant'
     *  MATLAB Function: '<S212>/Find closest index to curve'
     *  MinMax: '<S263>/Min'
     */
    rtb_Switch2_hw = rtb_Assignment_d[((int32_T)fmin(50.0, s237_iter)) - 1];

    /* If: '<S263>/If' incorporates:
     *  RelationalOperator: '<S263>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S263>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S266>/Action Port'
       */
      /* SignalConversion generated from: '<S266>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S268>/FixPt Sum1' incorporates:
       *  Constant: '<S268>/FixPt Constant'
       */
      rtb_Subtract_j3 = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S266>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S266>/Selector11'
       *  Selector: '<S266>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Subtract_j3) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S266>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S266>/Selector1'
       *  Selector: '<S266>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Subtract_j3) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S266>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S266>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Subtract_j3), &rtb_Minus_n[0], rtb_Switch2_hw,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S266>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S266>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S266>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Switch2_hw,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S263>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S263>/Latch' incorporates:
       *  ActionPort: '<S267>/Action Port'
       */
      /* SignalConversion generated from: '<S267>/In1' incorporates:
       *  UnitDelay: '<S263>/Unit Delay1'
       */
      rtb_Subtract_j3 = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S267>/In2' incorporates:
       *  UnitDelay: '<S263>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S263>/Latch' */
    }

    /* End of If: '<S263>/If' */

    /* MinMax: '<S210>/Min' incorporates:
     *  Lookup_n-D: '<S210>/Lookahead Distance'
     *  UnitDelay: '<S210>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S212>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S262>/While Iterator'
     */
    s262_iter = 1U;
    rtb_LogicalOperator1 = true;
    while (rtb_LogicalOperator1 && (s262_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S212>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S262>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s262_iter;
      rtb_LogicalOperator1 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s237_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s262_iter++;
    }

    /* End of Outputs for SubSystem: '<S212>/Find first index that meets distance target' */

    /* Switch: '<S265>/Switch' incorporates:
     *  Concatenate: '<S212>/Matrix Concatenate'
     *  Constant: '<S212>/Constant'
     *  Constant: '<S262>/Constant'
     *  Constant: '<S265>/Constant'
     *  Constant: '<S265>/Constant1'
     *  Constant: '<S265>/Constant2'
     *  Constant: '<S265>/Constant3'
     *  Logic: '<S262>/AND'
     *  MATLAB Function: '<S212>/Find closest index to curve'
     *  Math: '<S265>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S265>/Max'
     *  MinMax: '<S265>/Min'
     *  MinMax: '<S265>/Min1'
     *  Product: '<S262>/Product'
     *  Product: '<S265>/Divide'
     *  Product: '<S265>/Product'
     *  Product: '<S265>/Product1'
     *  RelationalOperator: '<S212>/Relational Operator'
     *  RelationalOperator: '<S262>/Relational Operator'
     *  RelationalOperator: '<S262>/Relational Operator1'
     *  Selector: '<S212>/Selector10'
     *  Selector: '<S212>/Selector7'
     *  Selector: '<S212>/Selector8'
     *  Selector: '<S212>/Selector9'
     *  Selector: '<S262>/Selector'
     *  Selector: '<S262>/Selector1'
     *  Selector: '<S263>/Selector'
     *  Sqrt: '<S265>/Sqrt'
     *  Sum: '<S212>/Subtract'
     *  Sum: '<S262>/Add'
     *  Sum: '<S265>/Subtract'
     *  Sum: '<S265>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Saturation_h = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Subtract_j3 *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Saturation_h = fmin(rtb_Subtract_j3 * Spline_Velocity_Multiplier_TEST,
        sqrt(Spline_Max_Centripital_Acceleration / fmax
             (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299],
              1.0E-5)));
    }

    /* End of Switch: '<S265>/Switch' */

    /* Logic: '<S213>/OR' */
    rtb_Compare_pb = (rtb_LogicalOperator5 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S213>/Switch1' incorporates:
     *  Switch: '<S213>/Switch'
     *  UnitDelay: '<S213>/Unit Delay'
     */
    if (rtb_Compare_pb) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S213>/Constant3'
       *  SignalConversion: '<S213>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Switch2_hw = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S213>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Switch2_hw = rtb_Merge1;
    }

    /* End of Switch: '<S213>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S213>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Switch2_hw;

    /* Selector: '<S212>/Selector6' incorporates:
     *  Concatenate: '<S212>/Matrix Concatenate'
     *  Selector: '<S212>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S212>/Selector2' incorporates:
     *  Concatenate: '<S212>/Matrix Concatenate'
     *  Selector: '<S212>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S213>/Switch2' incorporates:
     *  Sum: '<S269>/Subtract'
     *  Sum: '<S269>/Subtract1'
     *  Trigonometry: '<S269>/Atan2'
     *  UnitDelay: '<S213>/Unit Delay1'
     */
    if (rtb_Compare_pb) {
      rtb_Switch_hs = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Switch_hs = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S213>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S213>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Switch_hs;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S210>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator5;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S210>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S213>/Constant2'
     *  SignalConversion generated from: '<S210>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S213>/Constant5'
     *  SignalConversion generated from: '<S210>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S213>/Constant6'
     *  SignalConversion generated from: '<S210>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S210>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S211>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S210>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S263>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Subtract_j3;

    /* Update for UnitDelay: '<S263>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S213>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Switch2_hw;

    /* Update for UnitDelay: '<S213>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Switch_hs;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S209>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S209>/Constant1'
     *  SignalConversion generated from: '<S209>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S209>/Constant'
     *  SignalConversion generated from: '<S209>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S209>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S209>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S209>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S209>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S209>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S209>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S209>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* UnitDelay: '<S359>/Unit Delay' */
  rtb_Saturation_h = Robot_Control_B.Translation_Speed_RL;

  /* Signum: '<S359>/Sign2' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Add_fp = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Add_fp = -1.0;
  } else {
    rtb_Add_fp = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S359>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S359>/Product1' incorporates:
   *  Signum: '<S359>/Sign1'
   *  Signum: '<S359>/Sign2'
   */
  rtb_Add_fp *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_fp)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_fp, 256.0);
  }

  /* Switch: '<S359>/Switch' incorporates:
   *  Constant: '<S359>/Constant'
   *  Constant: '<S364>/Constant'
   *  Constant: '<S365>/Constant'
   *  Logic: '<S359>/or'
   *  Product: '<S359>/Product1'
   *  RelationalOperator: '<S364>/Compare'
   *  RelationalOperator: '<S365>/Compare'
   */
  if ((rtb_Saturation_h == 0.0) || (((i < 0) ? ((int32_T)((int8_T)(-((int8_T)
            ((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Subtract_ai = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Subtract_ai = 0.0;
  }

  /* End of Switch: '<S359>/Switch' */

  /* Switch: '<S370>/Init' incorporates:
   *  UnitDelay: '<S370>/FixPt Unit Delay1'
   *  UnitDelay: '<S370>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Subtract_j3 = rtb_Subtract_ai;
  } else {
    rtb_Subtract_j3 = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S370>/Init' */

  /* RelationalOperator: '<S366>/Compare' incorporates:
   *  Constant: '<S366>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Subtract_ai == 0.0);

  /* RelationalOperator: '<S367>/Compare' incorporates:
   *  Constant: '<S367>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Subtract_ai > 0.0);

  /* Abs: '<S359>/Abs' incorporates:
   *  Sum: '<S359>/Subtract'
   */
  rtb_Saturation_h = fabs(rtb_Saturation_h -
    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S359>/Switch1' incorporates:
   *  Constant: '<S359>/Constant1'
   *  Switch: '<S359>/Switch3'
   *  Switch: '<S359>/Switch5'
   *  UnaryMinus: '<S359>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    rtb_Merge1 = -Translation_Speed_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S359>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S359>/Constant1'
     *  Constant: '<S359>/Constant4'
     *  Constant: '<S359>/Constant6'
     *  UnaryMinus: '<S359>/Unary Minus'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S359>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S359>/Constant2'
     *  Constant: '<S359>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S359>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S359>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_j), &rtb_Reshapey[0],
                         rtb_Saturation_h, &rtb_Minus_n[0], 1U);
    rtb_Saturation_h = rtb_LookupTableDynamic_j;
  } else {
    if (rtb_LogicalOperator5) {
      /* Switch: '<S359>/Switch3' incorporates:
       *  Constant: '<S359>/Constant3'
       */
      rtb_Merge1 = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Merge1 = -Translation_Speed_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S359>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S359>/Constant1'
     *  Constant: '<S359>/Constant10'
     *  Constant: '<S359>/Constant8'
     *  UnaryMinus: '<S359>/Unary Minus'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S359>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S359>/Constant7'
     *  Constant: '<S359>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S359>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S359>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_i), &rtb_Reshapey[0],
                         rtb_Saturation_h, &rtb_Minus_n[0], 1U);
    rtb_Saturation_h = rtb_LookupTableDynamic1_i;
  }

  /* End of Switch: '<S359>/Switch1' */

  /* Product: '<S359>/Product' */
  rtb_Merge1 *= rtb_Saturation_h;

  /* Sum: '<S368>/Sum1' */
  rtb_Switch2_hw = rtb_Subtract_ai - rtb_Subtract_j3;

  /* Switch: '<S369>/Switch2' incorporates:
   *  RelationalOperator: '<S369>/LowerRelop1'
   */
  if (!(rtb_Switch2_hw > rtb_Merge1)) {
    /* Switch: '<S359>/Switch2' incorporates:
     *  Constant: '<S359>/Constant1'
     *  Switch: '<S359>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Merge1 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S359>/Switch4' incorporates:
       *  Constant: '<S359>/Constant1'
       */
      rtb_Merge1 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S359>/Switch4' incorporates:
       *  Constant: '<S359>/Constant3'
       *  UnaryMinus: '<S359>/Unary Minus1'
       */
      rtb_Merge1 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S359>/Switch2' */

    /* Product: '<S359>/Product2' */
    rtb_Merge1 *= rtb_Saturation_h;

    /* Switch: '<S369>/Switch' incorporates:
     *  RelationalOperator: '<S369>/UpperRelop'
     */
    if (!(rtb_Switch2_hw < rtb_Merge1)) {
      rtb_Merge1 = rtb_Switch2_hw;
    }

    /* End of Switch: '<S369>/Switch' */
  }

  /* End of Switch: '<S369>/Switch2' */

  /* Sum: '<S368>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Merge1 + rtb_Subtract_j3;

  /* Switch: '<S362>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S362>/Switch' incorporates:
     *  Constant: '<S396>/Constant3'
     *  Constant: '<S396>/Constant4'
     *  Math: '<S396>/Math Function'
     *  Sum: '<S362>/Subtract'
     *  Sum: '<S396>/Add1'
     *  Sum: '<S396>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S362>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S362>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_fp = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_fp)) || (rtIsInf(rtb_Add_fp))) {
    rtb_Add_fp = 0.0;
  } else {
    rtb_Add_fp = fmod(rtb_Add_fp, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Add_fp < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Add_fp)))))) : ((int32_T)((uint8_T)rtb_Add_fp)));

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* Switch: '<S176>/Switch' incorporates:
   *  Constant: '<S164>/Constant'
   *  Constant: '<S176>/Constant'
   *  RelationalOperator: '<S164>/Compare'
   *  UnitDelay: '<S176>/Unit Delay'
   */
  if (rtb_GameState != 1) {
    rtb_Add_fp = 0.0;
  } else {
    rtb_Add_fp = Robot_Control_DW.UnitDelay_DSTATE_o;
  }

  /* Sum: '<S176>/Sum' incorporates:
   *  Constant: '<S176>/Constant4'
   *  Switch: '<S176>/Switch'
   */
  rtb_Merge1 = rtb_Add_fp + 0.02;

  /* Switch: '<S177>/Switch' incorporates:
   *  Constant: '<S169>/Constant'
   *  Constant: '<S177>/Constant'
   *  RelationalOperator: '<S169>/Compare'
   *  UnitDelay: '<S177>/Unit Delay'
   */
  if (rtb_GameState != 2) {
    rtb_Add_fp = 0.0;
  } else {
    rtb_Add_fp = Robot_Control_DW.UnitDelay_DSTATE_m;
  }

  /* Sum: '<S177>/Sum' incorporates:
   *  Constant: '<S177>/Constant4'
   *  Switch: '<S177>/Switch'
   */
  rtb_Saturation_h = rtb_Add_fp + 0.02;

  /* MultiPortSwitch: '<S133>/Multiport Switch' incorporates:
   *  Constant: '<S133>/Constant1'
   *  Constant: '<S133>/Constant3'
   */
  switch (rtb_GameState) {
   case 0:
    rtb_Subtract_ai = 0.0;
    break;

   case 1:
    rtb_Subtract_ai = rtb_Merge1;
    break;

   case 2:
    rtb_Subtract_ai = rtb_Saturation_h;
    break;

   default:
    rtb_Subtract_ai = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S133>/Multiport Switch' */

  /* If: '<S133>/If' incorporates:
   *  Constant: '<S162>/Constant'
   *  Constant: '<S163>/Constant'
   *  Constant: '<S165>/Constant'
   *  Constant: '<S166>/Constant'
   *  Constant: '<S167>/Constant'
   *  Constant: '<S168>/Constant'
   *  Inport: '<Root>/IsBlueAlliance'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S162>/Compare'
   *  RelationalOperator: '<S163>/Compare'
   *  RelationalOperator: '<S165>/Compare'
   *  RelationalOperator: '<S166>/Compare'
   *  RelationalOperator: '<S167>/Compare'
   *  RelationalOperator: '<S168>/Compare'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_n;
  if ((rtb_GameState == 1) || (rtb_Subtract_ai <= Rebuilt_Match_Time_Transition))
  {
    rtAction = 0;
  } else if (rtb_Subtract_ai <= Rebuilt_Match_Time_Shift_1) {
    rtAction = 1;
  } else if (rtb_Subtract_ai <= Rebuilt_Match_Time_Shift_2) {
    rtAction = 2;
  } else if (rtb_Subtract_ai <= Rebuilt_Match_Time_Shift_3) {
    rtAction = 3;
  } else if (rtb_Subtract_ai <= Rebuilt_Match_Time_Shift_4) {
    rtAction = 4;
  } else {
    rtAction = 5;
  }

  Robot_Control_DW.If_ActiveSubsystem_n = rtAction;
  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
       *  ActionPort: '<S170>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S170>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
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
    rtb_Subtract_j3 = Robot_Control_DW.UnitDelay_DSTATE_hb - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S170>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_j3;

    /* Update for UnitDelay: '<S170>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hb = rtb_Subtract_j3;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S171>/Action Port'
       */
      /* SystemReset for If: '<S133>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem1);

      /* End of SystemReset for SubSystem: '<S133>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S171>/Action Port'
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
       *  ActionPort: '<S172>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S172>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem2' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S172>/Action Port'
     */
    /* Sum: '<S172>/Sum' incorporates:
     *  Constant: '<S172>/Constant1'
     *  UnitDelay: '<S172>/Unit Delay'
     */
    rtb_Subtract_j3 = Robot_Control_DW.UnitDelay_DSTATE_hz - 0.02;

    /* RelationalOperator: '<S179>/Compare' incorporates:
     *  Constant: '<S179>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Subtract_j3 <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S133>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S172>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S133>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S172>/Logical Operator1'
     *  Logic: '<S172>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S172>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S172>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S172>/Constant2'
       *  Sum: '<S172>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_j3 -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S133>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_j3;
    }

    /* End of Switch: '<S172>/Switch' */

    /* Update for UnitDelay: '<S172>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hz = rtb_Subtract_j3;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem2' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S173>/Action Port'
       */
      /* SystemReset for If: '<S133>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem3);

      /* End of SystemReset for SubSystem: '<S133>/If Action Subsystem3' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S173>/Action Port'
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
       *  ActionPort: '<S174>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S174>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem4' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S174>/Action Port'
     */
    /* Sum: '<S174>/Sum' incorporates:
     *  Constant: '<S174>/Constant1'
     *  UnitDelay: '<S174>/Unit Delay'
     */
    rtb_Subtract_j3 = Robot_Control_DW.UnitDelay_DSTATE_di - 0.02;

    /* RelationalOperator: '<S181>/Compare' incorporates:
     *  Constant: '<S181>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Subtract_j3 <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S133>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S174>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S133>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S174>/Logical Operator1'
     *  Logic: '<S174>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S174>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S174>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S174>/Constant2'
       *  Sum: '<S174>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_j3 -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S174>/Constant3'
       *  Sum: '<S174>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_j3 +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S174>/Switch' */

    /* Update for UnitDelay: '<S174>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Subtract_j3;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem4' */
    break;

   default:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S175>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S175>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem5' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem5' incorporates:
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
    rtb_Subtract_j3 = Robot_Control_DW.UnitDelay_DSTATE_du - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S175>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_j3;

    /* Update for UnitDelay: '<S175>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_du = rtb_Subtract_j3;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S133>/If' */

  /* If: '<S183>/If' incorporates:
   *  If: '<S184>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S183>/Blue' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    /* Merge: '<S183>/Merge' incorporates:
     *  Constant: '<S185>/BlueAllianceZoneX'
     *  Logic: '<S185>/AND'
     *  RelationalOperator: '<S185>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S183>/Blue' */

    /* Outputs for IfAction SubSystem: '<S184>/Blue' incorporates:
     *  ActionPort: '<S187>/Action Port'
     */
    /* Merge: '<S184>/Merge' incorporates:
     *  Constant: '<S187>/BlueAllianceZoneX'
     *  RelationalOperator: '<S187>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S184>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S183>/Red' incorporates:
     *  ActionPort: '<S186>/Action Port'
     */
    /* Merge: '<S183>/Merge' incorporates:
     *  Constant: '<S186>/RedAllianceZoneX'
     *  Logic: '<S186>/AND'
     *  RelationalOperator: '<S186>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S183>/Red' */

    /* Outputs for IfAction SubSystem: '<S184>/Red' incorporates:
     *  ActionPort: '<S188>/Action Port'
     */
    /* Merge: '<S184>/Merge' incorporates:
     *  Constant: '<S188>/RedAllianceZoneX'
     *  RelationalOperator: '<S188>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S184>/Red' */
  }

  /* End of If: '<S183>/If' */

  /* RelationalOperator: '<S136>/GreaterThan' incorporates:
   *  Constant: '<S136>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S136>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S136>/Relational Operator' incorporates:
   *  Abs: '<S136>/Abs'
   *  Constant: '<S182>/Constant3'
   *  Constant: '<S182>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S182>/Math Function'
   *  Sum: '<S136>/Subtract'
   *  Sum: '<S182>/Add1'
   *  Sum: '<S182>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* Abs: '<S135>/Abs2' incorporates:
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   */
  rtb_Subtract_ai = fabs(Robot_Control_U.Measured_Shooter_Speed_Left);

  /* Abs: '<S135>/Abs1' incorporates:
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   */
  rtb_Subtract_j3 = fabs(Robot_Control_U.Measured_Shooter_Speed_Center);

  /* Abs: '<S135>/Abs3' incorporates:
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  rtb_Switch2_hw = fabs(Robot_Control_U.Measured_Shooter_Speed_Right);

  /* MinMax: '<S135>/Max' */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(rtb_Subtract_ai,
    rtb_Subtract_j3), rtb_Switch2_hw);

  /* RelationalOperator: '<S136>/Relational Operator1' incorporates:
   *  Abs: '<S136>/Abs1'
   *  Constant: '<S136>/Constant2'
   *  Sum: '<S136>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S136>/Relational Operator4' incorporates:
   *  Abs: '<S136>/Abs4'
   *  Constant: '<S136>/Constant1'
   *  Sum: '<S136>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S136>/AND' */
  rtb_Compare_pb = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S136>/AND2' incorporates:
   *  Logic: '<S136>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_pb);

  /* RelationalOperator: '<S134>/Compare' incorporates:
   *  Constant: '<S134>/Constant'
   *  Inport: '<Root>/Gamepad_RT'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_RT != 0.0);

  /* SignalConversion: '<S136>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S136>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Compare_pb);

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
    if ((rtb_Compare_ky || rtb_Compare_mq) || rtb_LogicalOperator1) {
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
    rtb_Compare_pb = !rtb_Compare_mq;
    rtb_LogicalOperator5 = !rtb_LogicalOperator1;
    if (((!rtb_Compare_ky) && rtb_Compare_pb) && rtb_LogicalOperator5) {
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
        if ((rtb_Compare_pb && rtb_LogicalOperator5) ||
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
        if ((rtb_Compare_mq && ((Robot_Control_B.RB_Ready_to_Score) ||
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
        } else if ((rtb_Compare_pb && rtb_LogicalOperator5) ||
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
     *  ActionPort: '<S142>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S144>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S146>/While Iterator'
     */
    /* If: '<S132>/If' incorporates:
     *  Constant: '<S144>/Constant'
     *  Constant: '<S145>/Constant'
     *  Constant: '<S145>/Shooter Assembly Offset in Robot'
     *  Constant: '<S145>/Shooter Assembly Offset in Robot1'
     *  Constant: '<S147>/Constant1'
     *  Constant: '<S147>/Constant10'
     *  Constant: '<S147>/Constant2'
     *  Constant: '<S147>/Constant5'
     *  Constant: '<S147>/Constant6'
     *  Constant: '<S147>/Constant7'
     *  Constant: '<S147>/Constant8'
     *  Constant: '<S147>/Constant9'
     *  Constant: '<S148>/Constant1'
     *  Constant: '<S148>/Constant10'
     *  Constant: '<S148>/Constant2'
     *  Constant: '<S148>/Constant5'
     *  Constant: '<S148>/Constant6'
     *  Constant: '<S148>/Constant7'
     *  Constant: '<S148>/Constant8'
     *  Constant: '<S148>/Constant9'
     *  Constant: '<S149>/Constant'
     *  Constant: '<S149>/Constant1'
     *  Constant: '<S149>/Constant2'
     *  Constant: '<S151>/Constant1'
     *  Constant: '<S151>/Constant10'
     *  Constant: '<S151>/Constant2'
     *  Constant: '<S151>/Constant5'
     *  Constant: '<S151>/Constant6'
     *  Constant: '<S151>/Constant7'
     *  Constant: '<S151>/Constant8'
     *  Constant: '<S151>/Constant9'
     *  Constant: '<S154>/Constant'
     *  Constant: '<S154>/Constant1'
     *  Constant: '<S154>/Constant11'
     *  Constant: '<S154>/Constant2'
     *  Constant: '<S154>/Constant3'
     *  Constant: '<S154>/Constant4'
     *  Constant: '<S154>/Constant5'
     *  Constant: '<S154>/Constant6'
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant10'
     *  Constant: '<S160>/Constant2'
     *  Constant: '<S160>/Constant5'
     *  Constant: '<S160>/Constant6'
     *  Constant: '<S160>/Constant7'
     *  Constant: '<S160>/Constant8'
     *  Constant: '<S160>/Constant9'
     *  Constant: '<S161>/Constant1'
     *  Constant: '<S161>/Constant10'
     *  Constant: '<S161>/Constant2'
     *  Constant: '<S161>/Constant5'
     *  Constant: '<S161>/Constant6'
     *  Constant: '<S161>/Constant7'
     *  Constant: '<S161>/Constant8'
     *  Constant: '<S161>/Constant9'
     *  Gain: '<S152>/Gain1'
     *  Gain: '<S159>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S150>/Logical Operator'
     *  Memory: '<S146>/Memory'
     *  Memory: '<S146>/Memory1'
     *  Memory: '<S146>/Memory2'
     *  Memory: '<S146>/Memory3'
     *  Merge: '<S132>/Merge'
     *  Merge: '<S132>/Merge2'
     *  Merge: '<S132>/Merge3'
     *  MinMax: '<S145>/Max'
     *  Product: '<S145>/Divide'
     *  RelationalOperator: '<S149>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S147>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S148>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S149>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S149>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S147>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S154>/Lookup Table Dynamic'
     *  Sum: '<S145>/Add'
     *  Sum: '<S145>/Subtract'
     *  Sum: '<S145>/Subtract1'
     *  Sum: '<S149>/Add'
     *  Switch: '<S149>/Switch'
     *  Switch: '<S149>/Switch1'
     *  Switch: '<S150>/Switch4'
     *  Switch: '<S150>/Switch5'
     *  Switch: '<S150>/Switch6'
     *  Trigonometry: '<S145>/Tanh'
     *  Trigonometry: '<S145>/Tanh1'
     *  UnitDelay: '<S149>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S144>/Iterate_Shot_Target' */
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
    if ((Robot_Control_B.Is_Outside_Alliance_Zone) || rtb_LogicalOperator1) {
      /* Switch: '<S150>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S150>/Switch4' incorporates:
         *  Constant: '<S150>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S150>/Switch4' incorporates:
         *  Constant: '<S150>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S150>/Switch2' */

      /* Switch: '<S150>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S150>/Switch6' incorporates:
         *  Constant: '<S150>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S150>/Switch6' incorporates:
         *  Constant: '<S150>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S150>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S150>/Switch5' incorporates:
         *  Constant: '<S150>/Constant8'
         *  Switch: '<S150>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S150>/Switch4' incorporates:
         *  Constant: '<S150>/Constant9'
         *  Switch: '<S150>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S150>/Switch6' incorporates:
       *  Constant: '<S150>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S144>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S146>/While Iterator'
     */
    Iteration_Number = 1U;
    rtb_Switch_hs = 0.0;
    rtb_Switch1_n = 0.0;
    rtb_Switch2_iq = 0.0;
    rtb_Compare_ky = true;
    rtb_LogicalOperator1 = true;
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_LogicalOperator1 && (Iteration_Number <= 10)) {
      /* Switch: '<S155>/Switch' incorporates:
       *  Memory: '<S146>/Memory1'
       *  Memory: '<S146>/Memory2'
       *  Switch: '<S155>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Add_md = rtb_Switch_hs;
        rtb_Minus_k_idx_0 = rtb_Switch1_n;
      } else {
        rtb_Add_md = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Minus_k_idx_0 = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S155>/Switch' */

      /* Math: '<S153>/Hypot' incorporates:
       *  Sum: '<S153>/Subtract'
       *  Sum: '<S153>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Add_md -
        Robot_Control_B.KF_Position_X, rtb_Minus_k_idx_0 -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S154>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S154>/Lookup Table Dynamic'
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

      /* Sum: '<S156>/Subtract' incorporates:
       *  Memory: '<S146>/Memory3'
       *  Sum: '<S156>/Subtract1'
       */
      rtb_Switch_hs = rtb_TOF - rtb_Switch2_iq;

      /* Sum: '<S156>/Add' incorporates:
       *  Gain: '<S156>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S156>/Product'
       *  Sum: '<S156>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Switch_hs *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Add_md;

      /* Sum: '<S156>/Add1' incorporates:
       *  Gain: '<S156>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S156>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Switch_hs *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Minus_k_idx_0;

      /* Memory: '<S146>/Memory' */
      rtb_LogicalOperator1 = rtb_Compare_ky;

      /* Update for Memory: '<S146>/Memory1' */
      rtb_Switch_hs = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S146>/Memory2' */
      rtb_Switch1_n = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S146>/Memory3' */
      rtb_Switch2_iq = rtb_TOF;

      /* Update for Memory: '<S146>/Memory' incorporates:
       *  Constant: '<S158>/Constant'
       *  Math: '<S157>/Hypot'
       *  RelationalOperator: '<S158>/Compare'
       *  Sum: '<S157>/Subtract'
       *  Sum: '<S157>/Subtract1'
       */
      rtb_Compare_ky = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X -
        rtb_Add_md, Robot_Control_B.RB_Desired_Target_Y - rtb_Minus_k_idx_0) >=
                        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S144>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S148>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S147>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S149>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S149>/Lookup Table Dynamic1'
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
      rtb_Switch_hs = 0.0;
    } else {
      rtb_Switch_hs = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    if (rtb_Switch_hs < Rebuilt_Shot_Init_Time) {
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
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Switch_hs;

    /* End of Outputs for SubSystem: '<S132>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_fp = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Add_k = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S132>/Shooter Not Active' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    /* If: '<S132>/If' incorporates:
     *  Constant: '<S143>/Constant'
     *  Constant: '<S143>/Constant1'
     *  Constant: '<S143>/Constant2'
     *  Constant: '<S143>/Constant3'
     *  Merge: '<S132>/Merge'
     *  Merge: '<S132>/Merge1'
     *  Merge: '<S132>/Merge2'
     *  Merge: '<S132>/Merge3'
     *  SignalConversion generated from: '<S143>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* End of Outputs for SubSystem: '<S132>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_fp = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Add_k = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S391>/Add1' incorporates:
   *  Constant: '<S391>/Constant3'
   *  Constant: '<S391>/Constant4'
   *  Math: '<S391>/Math Function'
   *  Sum: '<S390>/Sum'
   *  Sum: '<S391>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf((rtb_Add_fp - rtb_Add_k) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Gain: '<S394>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle;

  /* Abs: '<S373>/Abs1' */
  rtb_Switch2_iq = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S393>/Sum1' incorporates:
   *  Constant: '<S390>/Constant2'
   *  Product: '<S393>/Product'
   *  Sum: '<S393>/Sum'
   *  UnitDelay: '<S393>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Optimized_Module_Angle -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S390>/Product' incorporates:
   *  Constant: '<S390>/Constant3'
   */
  rtb_Switch_hs = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S392>/Diff' incorporates:
   *  UnitDelay: '<S392>/UD'
   *
   * Block description for '<S392>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S392>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_fp = rtb_Switch_hs - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S390>/Saturation' */
  if (rtb_Add_fp > Steering_Heading_Control_D_UL) {
    rtb_Add_fp = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_fp < Steering_Heading_Control_D_LL) {
    rtb_Add_fp = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S390>/Add' incorporates:
   *  Gain: '<S390>/Gain1'
   *  Saturate: '<S390>/Saturation'
   */
  rtb_Add_md = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle) +
    rtb_Add_fp;

  /* Sum: '<S390>/Subtract' incorporates:
   *  Constant: '<S390>/Constant'
   */
  rtb_uDLookupTable = Steering_Heading_Control_Total_UL - rtb_Add_md;

  /* Sum: '<S390>/Sum2' incorporates:
   *  Gain: '<S390>/Gain2'
   *  UnitDelay: '<S390>/Unit Delay'
   */
  rtb_Switch1_n = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S395>/Switch2' incorporates:
   *  RelationalOperator: '<S395>/LowerRelop1'
   */
  if (!(rtb_Switch1_n > rtb_uDLookupTable)) {
    /* Sum: '<S390>/Subtract1' incorporates:
     *  Constant: '<S390>/Constant1'
     */
    rtb_Minus_k_idx_0 = Steering_Heading_Control_Total_LL - rtb_Add_md;

    /* Switch: '<S395>/Switch' incorporates:
     *  RelationalOperator: '<S395>/UpperRelop'
     */
    if (rtb_Switch1_n < rtb_Minus_k_idx_0) {
      rtb_uDLookupTable = rtb_Minus_k_idx_0;
    } else {
      rtb_uDLookupTable = rtb_Switch1_n;
    }

    /* End of Switch: '<S395>/Switch' */
  }

  /* End of Switch: '<S395>/Switch2' */

  /* Saturate: '<S390>/Saturation1' */
  if (rtb_uDLookupTable > Steering_Heading_Control_I_UL) {
    rtb_Switch1_n = Steering_Heading_Control_I_UL;
  } else if (rtb_uDLookupTable < Steering_Heading_Control_I_LL) {
    rtb_Switch1_n = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch1_n = rtb_uDLookupTable;
  }

  /* End of Saturate: '<S390>/Saturation1' */

  /* Sum: '<S390>/Add1' */
  rtb_Add_fp = rtb_Add_md + rtb_Switch1_n;

  /* Saturate: '<S390>/Saturation2' */
  if (rtb_Add_fp > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S390>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_fp < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S390>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S390>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_fp;
  }

  /* End of Saturate: '<S390>/Saturation2' */

  /* Abs: '<S373>/Abs' */
  rtb_Add_md = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S373>/Add dither' */
  if (Robot_Control_DW.is_active_c7_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c7_Robot_Control = 1U;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Add_md;
  } else if (Robot_Control_DW.is_c7_Robot_Control == Robot_Control_IN_Dither) {
    if ((!Robot_Control_B.RB_Shooter_Active) || (rtb_Switch2_iq <
         Steering_Heading_Dither_Thresh_Off)) {
      Robot_Control_DW.is_Dither = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
      Robot_Control_B.abs_Cmd_Out = rtb_Add_md;
    } else if (Robot_Control_DW.is_Dither == Robot_Control_IN_High) {
      if (Robot_Control_DW.timer >= Steering_Heading_Dither_Period) {
        Robot_Control_DW.is_Dither = Robot_Control_IN_Off;
        Robot_Control_B.abs_Cmd_Out = 0.0;
        Robot_Control_DW.timer = 0.0;
      } else {
        Robot_Control_B.abs_Cmd_Out = rtb_Add_md * Steering_Heading_Dither_Gain;
        Robot_Control_DW.timer += 0.02;
      }

      /* case IN_Off: */
    } else if (Robot_Control_DW.timer >= Steering_Heading_Dither_Period) {
      Robot_Control_DW.is_Dither = Robot_Control_IN_High;
      Robot_Control_B.abs_Cmd_Out = rtb_Add_md * Steering_Heading_Dither_Gain;
      Robot_Control_DW.timer = 0.0;
    } else {
      Robot_Control_DW.timer += 0.02;
    }

    /* case IN_No_Dither: */
  } else if ((Robot_Control_B.RB_Shooter_Active) && (rtb_Switch2_iq >
              Steering_Heading_Dither_Thresh_On)) {
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_Dither;
    Robot_Control_DW.is_Dither = Robot_Control_IN_High;
    Robot_Control_B.abs_Cmd_Out = rtb_Add_md * Steering_Heading_Dither_Gain;
    Robot_Control_DW.timer = 0.0;
  } else {
    Robot_Control_B.abs_Cmd_Out = rtb_Add_md;
  }

  /* End of Chart: '<S373>/Add dither' */

  /* Switch: '<S373>/Switch' incorporates:
   *  Constant: '<S373>/Constant'
   *  Constant: '<S389>/Constant'
   *  Product: '<S373>/Product'
   *  RelationalOperator: '<S389>/Compare'
   *  Signum: '<S373>/Sign'
   */
  if (rtb_Add_md > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S373>/Sign' */
    if (rtIsNaN(Robot_Control_B.Steering_Heading_PID)) {
      rtb_Add_fp = (rtNaN);
    } else if (Robot_Control_B.Steering_Heading_PID < 0.0) {
      rtb_Add_fp = -1.0;
    } else {
      rtb_Add_fp = (Robot_Control_B.Steering_Heading_PID > 0.0);
    }

    rtb_Optimized_Module_Angle = Robot_Control_B.abs_Cmd_Out * rtb_Add_fp;
  } else {
    rtb_Optimized_Module_Angle = 0.0;
  }

  /* End of Switch: '<S373>/Switch' */

  /* Signum: '<S372>/Sign2' incorporates:
   *  UnitDelay: '<S372>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_fp = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_fp = -1.0;
  } else {
    rtb_Add_fp = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S372>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Add_k = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (rtb_Optimized_Module_Angle > 0.0);
  }

  /* Product: '<S372>/Product1' incorporates:
   *  Signum: '<S372>/Sign1'
   *  Signum: '<S372>/Sign2'
   */
  rtb_Add_fp *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_fp)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_fp, 256.0);
  }

  /* Switch: '<S372>/Switch' incorporates:
   *  Constant: '<S372>/Constant'
   *  Constant: '<S381>/Constant'
   *  Constant: '<S382>/Constant'
   *  Logic: '<S372>/or'
   *  Product: '<S372>/Product1'
   *  RelationalOperator: '<S381>/Compare'
   *  RelationalOperator: '<S382>/Compare'
   *  UnitDelay: '<S372>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_cc = rtb_Optimized_Module_Angle;
  } else {
    rtb_Switch2_cc = 0.0;
  }

  /* End of Switch: '<S372>/Switch' */

  /* Switch: '<S387>/Init' incorporates:
   *  UnitDelay: '<S387>/FixPt Unit Delay1'
   *  UnitDelay: '<S387>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_cc;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S387>/Init' */

  /* RelationalOperator: '<S383>/Compare' incorporates:
   *  Constant: '<S383>/Constant'
   */
  rtb_Compare_ky = (rtb_Switch2_cc == 0.0);

  /* RelationalOperator: '<S384>/Compare' incorporates:
   *  Constant: '<S384>/Constant'
   */
  rtb_Compare_mq = (rtb_Switch2_cc > 0.0);

  /* Abs: '<S372>/Abs' incorporates:
   *  Sum: '<S372>/Subtract'
   *  UnitDelay: '<S372>/Unit Delay'
   */
  rtb_Switch2_iq = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                        rtb_Optimized_Module_Angle);

  /* Switch: '<S372>/Switch5' incorporates:
   *  Constant: '<S372>/Constant1'
   *  Switch: '<S372>/Switch1'
   *  UnaryMinus: '<S372>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    /* SignalConversion generated from: '<S372>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S372>/Constant4'
     *  Constant: '<S372>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S372>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S372>/Constant2'
     *  Constant: '<S372>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S372>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S372>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Reshapey[0],
                         rtb_Switch2_iq, &rtb_Minus_n[0], 1U);
    rtb_Switch2_iq = rtb_LookupTableDynamic;
    rtb_Add_fp = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S372>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S372>/Constant10'
     *  Constant: '<S372>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S372>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S372>/Constant7'
     *  Constant: '<S372>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S372>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S372>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Reshapey[0],
                         rtb_Switch2_iq, &rtb_Minus_n[0], 1U);
    rtb_Switch2_iq = rtb_LookupTableDynamic1;

    /* Switch: '<S372>/Switch3' incorporates:
     *  Constant: '<S372>/Constant1'
     *  Constant: '<S372>/Constant3'
     *  UnaryMinus: '<S372>/Unary Minus'
     */
    if (rtb_Compare_mq) {
      rtb_Add_fp = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_fp = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S372>/Switch3' */
  }

  /* End of Switch: '<S372>/Switch5' */

  /* Product: '<S372>/Product' incorporates:
   *  Switch: '<S372>/Switch1'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_fp * rtb_Switch2_iq;

  /* Sum: '<S385>/Sum1' */
  rtb_Add_md = rtb_Switch2_cc - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S386>/Switch2' incorporates:
   *  RelationalOperator: '<S386>/LowerRelop1'
   */
  if (!(rtb_Add_md > rtb_MatrixConcatenate_b_idx_0)) {
    /* Switch: '<S372>/Switch2' incorporates:
     *  Constant: '<S372>/Constant1'
     *  Constant: '<S372>/Constant3'
     *  Switch: '<S372>/Switch4'
     *  UnaryMinus: '<S372>/Unary Minus1'
     */
    if (rtb_Compare_ky) {
      rtb_Add_fp = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Compare_mq) {
      /* Switch: '<S372>/Switch4' incorporates:
       *  Constant: '<S372>/Constant1'
       */
      rtb_Add_fp = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_fp = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S372>/Product2' incorporates:
     *  Switch: '<S372>/Switch2'
     */
    rtb_Minus_k_idx_0 = rtb_Add_fp * rtb_Switch2_iq;

    /* Switch: '<S386>/Switch' incorporates:
     *  RelationalOperator: '<S386>/UpperRelop'
     */
    if (rtb_Add_md < rtb_Minus_k_idx_0) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Add_md;
    }

    /* End of Switch: '<S386>/Switch' */
  }

  /* End of Switch: '<S386>/Switch2' */

  /* Sum: '<S385>/Sum' */
  rtb_Switch2_iq = rtb_MatrixConcatenate_b_idx_0 + rtb_Optimized_Module_Angle_p;

  /* Signum: '<S371>/Sign2' incorporates:
   *  UnitDelay: '<S371>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_fp = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_fp = -1.0;
  } else {
    rtb_Add_fp = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S371>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S371>/Product1' incorporates:
   *  Signum: '<S371>/Sign1'
   *  Signum: '<S371>/Sign2'
   */
  rtb_Add_fp *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_fp)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_fp, 256.0);
  }

  /* Switch: '<S371>/Switch' incorporates:
   *  Constant: '<S371>/Constant'
   *  Constant: '<S374>/Constant'
   *  Constant: '<S375>/Constant'
   *  Logic: '<S371>/or'
   *  Product: '<S371>/Product1'
   *  RelationalOperator: '<S374>/Compare'
   *  RelationalOperator: '<S375>/Compare'
   *  UnitDelay: '<S371>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_cc = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_cc = 0.0;
  }

  /* End of Switch: '<S371>/Switch' */

  /* Switch: '<S380>/Init' incorporates:
   *  UnitDelay: '<S380>/FixPt Unit Delay1'
   *  UnitDelay: '<S380>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_cc;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S380>/Init' */

  /* RelationalOperator: '<S376>/Compare' incorporates:
   *  Constant: '<S376>/Constant'
   */
  rtb_Compare_ky = (rtb_Switch2_cc == 0.0);

  /* RelationalOperator: '<S377>/Compare' incorporates:
   *  Constant: '<S377>/Constant'
   */
  rtb_Compare_mq = (rtb_Switch2_cc > 0.0);

  /* Abs: '<S371>/Abs' incorporates:
   *  Sum: '<S371>/Subtract'
   *  UnitDelay: '<S371>/Unit Delay'
   */
  rtb_Add_md = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                    Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S371>/Switch5' incorporates:
   *  Constant: '<S371>/Constant1'
   *  Switch: '<S371>/Switch1'
   *  UnaryMinus: '<S371>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    /* SignalConversion generated from: '<S371>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S371>/Constant4'
     *  Constant: '<S371>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S371>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S371>/Constant2'
     *  Constant: '<S371>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S371>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S371>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_Add_md, &rtb_Minus_n[0], 1U);
    rtb_Add_md = rtb_LookupTableDynamic_p;
    rtb_Add_fp = -Steering_Relative_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S371>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S371>/Constant10'
     *  Constant: '<S371>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S371>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S371>/Constant7'
     *  Constant: '<S371>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S371>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S371>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_Add_md, &rtb_Minus_n[0], 1U);
    rtb_Add_md = rtb_LookupTableDynamic1_g;

    /* Switch: '<S371>/Switch3' incorporates:
     *  Constant: '<S371>/Constant1'
     *  Constant: '<S371>/Constant3'
     *  UnaryMinus: '<S371>/Unary Minus'
     */
    if (rtb_Compare_mq) {
      rtb_Add_fp = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_fp = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S371>/Switch3' */
  }

  /* End of Switch: '<S371>/Switch5' */

  /* Product: '<S371>/Product' incorporates:
   *  Switch: '<S371>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_fp * rtb_Add_md;

  /* Sum: '<S378>/Sum1' */
  rtb_Minus_k_idx_0 = rtb_Switch2_cc - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S379>/Switch2' incorporates:
   *  RelationalOperator: '<S379>/LowerRelop1'
   */
  if (!(rtb_Minus_k_idx_0 > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S371>/Switch2' incorporates:
     *  Constant: '<S371>/Constant1'
     *  Constant: '<S371>/Constant3'
     *  Switch: '<S371>/Switch4'
     *  UnaryMinus: '<S371>/Unary Minus1'
     */
    if (rtb_Compare_ky) {
      rtb_Add_fp = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Compare_mq) {
      /* Switch: '<S371>/Switch4' incorporates:
       *  Constant: '<S371>/Constant1'
       */
      rtb_Add_fp = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_fp = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S371>/Product2' incorporates:
     *  Switch: '<S371>/Switch2'
     */
    rtb_Minus_k_idx_1 = rtb_Add_fp * rtb_Add_md;

    /* Switch: '<S379>/Switch' incorporates:
     *  RelationalOperator: '<S379>/UpperRelop'
     */
    if (rtb_Minus_k_idx_0 < rtb_Minus_k_idx_1) {
      rtb_Optimized_Module_Angle = rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle = rtb_Minus_k_idx_0;
    }

    /* End of Switch: '<S379>/Switch' */
  }

  /* End of Switch: '<S379>/Switch2' */

  /* Sum: '<S378>/Sum' */
  rtb_Add_md = rtb_Optimized_Module_Angle + rtb_Optimized_Module_Angle_p;

  /* Switch: '<S361>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S361>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch2_iq;
  } else {
    /* Switch: '<S361>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Add_md;
  }

  /* End of Switch: '<S361>/Switch' */

  /* Fcn: '<S404>/r->x' incorporates:
   *  Fcn: '<S409>/r->x'
   *  Fcn: '<S414>/r->x'
   *  Fcn: '<S419>/r->x'
   */
  rtb_Minus_k_idx_0 = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S398>/Add' incorporates:
   *  Fcn: '<S404>/r->x'
   *  Fcn: '<S405>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) +
    rtb_Minus_k_idx_0;

  /* Fcn: '<S404>/theta->y' incorporates:
   *  Fcn: '<S409>/theta->y'
   *  Fcn: '<S414>/theta->y'
   *  Fcn: '<S419>/theta->y'
   */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S398>/Add' incorporates:
   *  Fcn: '<S404>/theta->y'
   *  Fcn: '<S405>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) +
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S399>/Add' incorporates:
   *  Fcn: '<S410>/r->x'
   *  Fcn: '<S410>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Minus_k_idx_0;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) +
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S400>/Add' incorporates:
   *  Fcn: '<S415>/r->x'
   *  Fcn: '<S415>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Minus_k_idx_0;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) +
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S401>/Add' incorporates:
   *  Fcn: '<S420>/r->x'
   *  Fcn: '<S420>/theta->y'
   */
  rtb_Minus_k_idx_0 += Robot_Control_B.Steering_Localized_Cmd * cos
    (Robot_Control_ConstB.BR_Tangent_Angle);
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) +
    rtb_MatrixConcatenate_b_idx_0;

  /* Fcn: '<S418>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_k_idx_0,
    rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S421>/Compare' incorporates:
   *  Constant: '<S421>/Constant'
   */
  rtb_Compare_pb = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S417>/Switch1' */
  if (rtb_Compare_pb) {
    /* Switch: '<S417>/Switch1' incorporates:
     *  Constant: '<S417>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S417>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S417>/Switch1' */

  /* Fcn: '<S403>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S406>/Compare' incorporates:
   *  Constant: '<S406>/Constant'
   */
  rtb_Compare_mq = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S402>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S402>/Switch1' incorporates:
     *  Constant: '<S402>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S402>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S402>/Switch1' */

  /* Fcn: '<S408>/x->r' */
  rtb_Switch2_cc = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S411>/Compare' incorporates:
   *  Constant: '<S411>/Constant'
   */
  rtb_Compare_ky = (rtb_Switch2_cc == 0.0);

  /* Switch: '<S407>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S407>/Switch1' incorporates:
     *  Constant: '<S407>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S407>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_cc;
  }

  /* End of Switch: '<S407>/Switch1' */

  /* Fcn: '<S413>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S416>/Compare' incorporates:
   *  Constant: '<S416>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S412>/Switch1' */
  if (rtb_LogicalOperator1) {
    /* Switch: '<S412>/Switch1' incorporates:
     *  Constant: '<S412>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S412>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S412>/Switch1' */

  /* Product: '<S397>/Divide' incorporates:
   *  Abs: '<S397>/Abs'
   *  Abs: '<S397>/Abs1'
   *  Abs: '<S397>/Abs2'
   *  Abs: '<S397>/Abs3'
   *  Constant: '<S397>/Constant'
   *  MinMax: '<S397>/Max'
   */
  rtb_MatrixConcatenate_b_idx_0 = 5.3690930669470935 / fmax(fmax(fmax(fmax
    (5.3690930669470935, Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S397>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S417>/Switch' */
  if (!rtb_Compare_pb) {
    /* Switch: '<S417>/Switch' incorporates:
     *  Fcn: '<S418>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S417>/Switch' */

  /* Trigonometry: '<S351>/Cos4' incorporates:
   *  Switch: '<S340>/Angle_Switch'
   *  Trigonometry: '<S350>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S351>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S349>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S351>/Sin4' incorporates:
   *  Switch: '<S340>/Angle_Switch'
   *  Trigonometry: '<S350>/Sin4'
   */
  rtb_Minus_k_idx_0 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S351>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S349>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S351>/Subtract1' incorporates:
   *  Product: '<S351>/Product2'
   *  Product: '<S351>/Product3'
   *  Trigonometry: '<S351>/Cos4'
   *  Trigonometry: '<S351>/Sin4'
   */
  rtb_Minus_k_idx_1 = (rtb_Add_k * rtb_Optimized_Module_Angle) +
    (rtb_Minus_k_idx_0 * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S351>/Subtract' incorporates:
   *  Product: '<S351>/Product'
   *  Product: '<S351>/Product1'
   *  Trigonometry: '<S351>/Cos4'
   *  Trigonometry: '<S351>/Sin4'
   */
  rtb_Subtract_ow = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Minus_k_idx_0 * rtb_Optimized_Module_Angle);

  /* Math: '<S351>/Hypot' */
  rtb_MatrixConcatenate_idx_0 = rt_hypotd_snf(rtb_Subtract_ow, rtb_Minus_k_idx_1);

  /* Switch: '<S351>/Switch' incorporates:
   *  Constant: '<S351>/Constant'
   *  Constant: '<S351>/Constant1'
   *  Constant: '<S352>/Constant'
   *  Product: '<S351>/Divide'
   *  Product: '<S351>/Divide1'
   *  RelationalOperator: '<S352>/Compare'
   *  Switch: '<S351>/Switch1'
   */
  if (rtb_MatrixConcatenate_idx_0 > 1.0E-6) {
    rtb_Switch2_cc = rtb_Minus_k_idx_1 / rtb_MatrixConcatenate_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Subtract_ow / rtb_MatrixConcatenate_idx_0;
  } else {
    rtb_Switch2_cc = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S351>/Switch' */

  /* Switch: '<S340>/Speed_Switch' incorporates:
   *  Abs: '<S340>/Abs'
   *  Constant: '<S348>/Constant'
   *  RelationalOperator: '<S348>/Compare'
   *  Switch: '<S340>/Angle_Switch'
   *  Trigonometry: '<S350>/Atan1'
   *  Trigonometry: '<S351>/Atan1'
   *  UnaryMinus: '<S340>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_cc, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_fp = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S350>/Subtract1' incorporates:
     *  Product: '<S350>/Product2'
     *  Product: '<S350>/Product3'
     *  UnaryMinus: '<S340>/Unary Minus'
     */
    rtb_Minus_k_idx_1 = (rtb_Add_k * Robot_Control_ConstB.Sin5_c) +
      (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S350>/Subtract' incorporates:
     *  Product: '<S350>/Product'
     *  Product: '<S350>/Product1'
     */
    rtb_Subtract_ow = (rtb_Add_k * Robot_Control_ConstB.Cos5_b) -
      (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S350>/Hypot' */
    rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Subtract_ow, rtb_Minus_k_idx_1);

    /* Switch: '<S350>/Switch1' incorporates:
     *  Constant: '<S350>/Constant'
     *  Constant: '<S350>/Constant1'
     *  Constant: '<S353>/Constant'
     *  Product: '<S350>/Divide'
     *  Product: '<S350>/Divide1'
     *  RelationalOperator: '<S353>/Compare'
     *  Switch: '<S350>/Switch'
     */
    if (rtb_Minus_k_idx_0 > 1.0E-6) {
      rtb_Subtract_ow /= rtb_Minus_k_idx_0;
      rtb_Minus_k_idx_0 = rtb_Minus_k_idx_1 / rtb_Minus_k_idx_0;
    } else {
      rtb_Subtract_ow = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S350>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_0,
      rtb_Subtract_ow);
  } else {
    rtb_Add_fp = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S343>/Product2' incorporates:
   *  Constant: '<S343>/Constant'
   *  Switch: '<S340>/Speed_Switch'
   */
  rtb_Switch2_cc = rtb_Add_fp * 1154.7574092481445;

  /* Signum: '<S338>/Sign' */
  if (rtIsNaN(rtb_Switch2_cc)) {
    rtb_Add_fp = (rtNaN);
  } else if (rtb_Switch2_cc < 0.0) {
    rtb_Add_fp = -1.0;
  } else {
    rtb_Add_fp = (rtb_Switch2_cc > 0.0);
  }

  /* Signum: '<S338>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S341>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S342>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S273>/Product' incorporates:
   *  Abs: '<S338>/Abs'
   *  Abs: '<S341>/Abs'
   *  Constant: '<S344>/Constant'
   *  Constant: '<S354>/Constant3'
   *  Constant: '<S354>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S338>/OR'
   *  Lookup_n-D: '<S341>/1-D Lookup Table'
   *  Math: '<S354>/Math Function'
   *  RelationalOperator: '<S338>/Equal1'
   *  RelationalOperator: '<S344>/Compare'
   *  Signum: '<S338>/Sign'
   *  Signum: '<S338>/Sign1'
   *  Sum: '<S341>/Add'
   *  Sum: '<S354>/Add1'
   *  Sum: '<S354>/Add2'
   */
  rtb_Switch2_cc = (((real_T)((rtb_Add_fp == rtb_Add_k) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_cc) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S339>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Subtract_ow = rtb_Switch2_cc - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S346>/Sum1' incorporates:
   *  Constant: '<S339>/Constant2'
   *  Product: '<S346>/Product'
   *  Sum: '<S346>/Sum'
   *  UnitDelay: '<S346>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_Subtract_ow - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S339>/Product' incorporates:
   *  Constant: '<S339>/Constant3'
   */
  rtb_Minus_k_idx_1 = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S345>/Diff' incorporates:
   *  UnitDelay: '<S345>/UD'
   *
   * Block description for '<S345>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S345>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_fp = rtb_Minus_k_idx_1 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S339>/Saturation' */
  if (rtb_Add_fp > Drive_Motor_Control_D_UL) {
    rtb_Add_fp = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_fp < Drive_Motor_Control_D_LL) {
    rtb_Add_fp = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S339>/Add' incorporates:
   *  Gain: '<S339>/Gain'
   *  Gain: '<S339>/Gain1'
   *  Saturate: '<S339>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_cc) +
    (Drive_Motor_Control_P * rtb_Subtract_ow)) + rtb_Add_fp;

  /* Saturate: '<S339>/Saturation2' incorporates:
   *  Sum: '<S339>/Add1'
   */
  if (rtb_MatrixConcatenate_idx_0 > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_MatrixConcatenate_idx_0 < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_MatrixConcatenate_idx_0;
  }

  /* End of Saturate: '<S339>/Saturation2' */

  /* Switch: '<S402>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S402>/Switch' incorporates:
     *  Fcn: '<S403>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S402>/Switch' */

  /* Trigonometry: '<S288>/Cos4' incorporates:
   *  Switch: '<S277>/Angle_Switch'
   *  Trigonometry: '<S287>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S288>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S286>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S288>/Sin4' incorporates:
   *  Switch: '<S277>/Angle_Switch'
   *  Trigonometry: '<S287>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S288>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S286>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S288>/Subtract1' incorporates:
   *  Product: '<S288>/Product2'
   *  Product: '<S288>/Product3'
   *  Trigonometry: '<S288>/Cos4'
   *  Trigonometry: '<S288>/Sin4'
   */
  rtb_MatrixConcatenate_idx_0 = (rtb_Add_k * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S288>/Subtract' incorporates:
   *  Product: '<S288>/Product'
   *  Product: '<S288>/Product1'
   *  Trigonometry: '<S288>/Cos4'
   *  Trigonometry: '<S288>/Sin4'
   */
  rtb_Subtract_ow = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S288>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract_ow, rtb_MatrixConcatenate_idx_0);

  /* Switch: '<S288>/Switch' incorporates:
   *  Constant: '<S288>/Constant'
   *  Constant: '<S288>/Constant1'
   *  Constant: '<S289>/Constant'
   *  Product: '<S288>/Divide'
   *  Product: '<S288>/Divide1'
   *  RelationalOperator: '<S289>/Compare'
   *  Switch: '<S288>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_Switch2_cc = rtb_MatrixConcatenate_idx_0 / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle_p = rtb_Subtract_ow / rtb_Hypot_g5;
  } else {
    rtb_Switch2_cc = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S288>/Switch' */

  /* Product: '<S397>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S277>/Speed_Switch' incorporates:
   *  Abs: '<S277>/Abs'
   *  Constant: '<S285>/Constant'
   *  RelationalOperator: '<S285>/Compare'
   *  Switch: '<S277>/Angle_Switch'
   *  Trigonometry: '<S287>/Atan1'
   *  Trigonometry: '<S288>/Atan1'
   *  UnaryMinus: '<S277>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_cc, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_fp = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S287>/Subtract1' incorporates:
     *  Product: '<S287>/Product2'
     *  Product: '<S287>/Product3'
     *  UnaryMinus: '<S277>/Unary Minus'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Add_k * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S287>/Subtract' incorporates:
     *  Product: '<S287>/Product'
     *  Product: '<S287>/Product1'
     */
    rtb_Hypot_g5 = (rtb_Add_k * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S287>/Hypot' */
    rtb_Subtract_ow = rt_hypotd_snf(rtb_Hypot_g5, rtb_MatrixConcatenate_idx_0);

    /* Switch: '<S287>/Switch1' incorporates:
     *  Constant: '<S287>/Constant'
     *  Constant: '<S287>/Constant1'
     *  Constant: '<S290>/Constant'
     *  Product: '<S287>/Divide'
     *  Product: '<S287>/Divide1'
     *  RelationalOperator: '<S290>/Compare'
     *  Switch: '<S287>/Switch'
     */
    if (rtb_Subtract_ow > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Subtract_ow;
      rtb_MatrixConcatenate_idx_0 /= rtb_Subtract_ow;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S287>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0, rtb_Hypot_g5);
  } else {
    rtb_Add_fp = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S280>/Product2' incorporates:
   *  Constant: '<S280>/Constant'
   *  Switch: '<S277>/Speed_Switch'
   */
  rtb_Switch2_cc = rtb_Add_fp * 1154.7574092481445;

  /* Signum: '<S275>/Sign' */
  if (rtIsNaN(rtb_Switch2_cc)) {
    rtb_Add_fp = (rtNaN);
  } else if (rtb_Switch2_cc < 0.0) {
    rtb_Add_fp = -1.0;
  } else {
    rtb_Add_fp = (rtb_Switch2_cc > 0.0);
  }

  /* Signum: '<S275>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S278>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S279>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S270>/Product' incorporates:
   *  Abs: '<S275>/Abs'
   *  Abs: '<S278>/Abs'
   *  Constant: '<S281>/Constant'
   *  Constant: '<S291>/Constant3'
   *  Constant: '<S291>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S275>/OR'
   *  Lookup_n-D: '<S278>/1-D Lookup Table'
   *  Math: '<S291>/Math Function'
   *  RelationalOperator: '<S275>/Equal1'
   *  RelationalOperator: '<S281>/Compare'
   *  Signum: '<S275>/Sign'
   *  Signum: '<S275>/Sign1'
   *  Sum: '<S278>/Add'
   *  Sum: '<S291>/Add1'
   *  Sum: '<S291>/Add2'
   */
  rtb_Switch2_cc = (((real_T)((rtb_Add_fp == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_cc) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j,
                  1U);

  /* Sum: '<S276>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_g5 = rtb_Switch2_cc - Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S283>/Sum1' incorporates:
   *  Constant: '<S276>/Constant2'
   *  Product: '<S283>/Product'
   *  Sum: '<S283>/Sum'
   *  UnitDelay: '<S283>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Hypot_g5 -
    Robot_Control_DW.UnitDelay1_DSTATE_f) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S276>/Product' incorporates:
   *  Constant: '<S276>/Constant3'
   */
  rtb_Subtract_ow = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S282>/Diff' incorporates:
   *  UnitDelay: '<S282>/UD'
   *
   * Block description for '<S282>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S282>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_fp = rtb_Subtract_ow - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S276>/Saturation' */
  if (rtb_Add_fp > Drive_Motor_Control_D_UL) {
    rtb_Add_fp = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_fp < Drive_Motor_Control_D_LL) {
    rtb_Add_fp = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S276>/Add' incorporates:
   *  Gain: '<S276>/Gain'
   *  Gain: '<S276>/Gain1'
   *  Saturate: '<S276>/Saturation'
   */
  rtb_Hypot_g5 = ((Drive_Motor_Control_FF * rtb_Switch2_cc) +
                  (Drive_Motor_Control_P * rtb_Hypot_g5)) + rtb_Add_fp;

  /* Saturate: '<S276>/Saturation2' incorporates:
   *  Sum: '<S276>/Add1'
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

  /* End of Saturate: '<S276>/Saturation2' */

  /* Sum: '<S292>/Add1' incorporates:
   *  Constant: '<S292>/Constant3'
   *  Constant: '<S292>/Constant4'
   *  Math: '<S292>/Math Function'
   *  Sum: '<S292>/Add2'
   */
  rtb_Switch2_cc = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S294>/Sum1' incorporates:
   *  Constant: '<S279>/Constant2'
   *  Product: '<S294>/Product'
   *  Sum: '<S294>/Sum'
   *  UnitDelay: '<S294>/Unit Delay1'
   */
  rtb_Hypot_g5 = ((rtb_Switch2_cc - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S279>/Product' incorporates:
   *  Constant: '<S279>/Constant3'
   */
  rtb_Switch2_im = rtb_Hypot_g5 * Steering_Motor_Control_D;

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
  rtb_Add_fp = rtb_Switch2_im - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S279>/Saturation' */
  if (rtb_Add_fp > Steering_Motor_Control_D_UL) {
    rtb_Add_fp = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_fp < Steering_Motor_Control_D_LL) {
    rtb_Add_fp = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S279>/Add' incorporates:
   *  Gain: '<S279>/Gain1'
   *  Saturate: '<S279>/Saturation'
   */
  rtb_Add_fn = (Steering_Motor_Control_P * rtb_Switch2_cc) + rtb_Add_fp;

  /* Sum: '<S279>/Subtract' incorporates:
   *  Constant: '<S279>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_fn;

  /* Sum: '<S279>/Sum2' incorporates:
   *  Gain: '<S279>/Gain2'
   *  UnitDelay: '<S279>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Switch2_cc) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S295>/Switch2' incorporates:
   *  Constant: '<S279>/Constant'
   *  RelationalOperator: '<S295>/LowerRelop1'
   *  Sum: '<S279>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_fn))) {
    /* Switch: '<S295>/Switch' incorporates:
     *  Constant: '<S279>/Constant1'
     *  RelationalOperator: '<S295>/UpperRelop'
     *  Sum: '<S279>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_fn)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_fn;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S295>/Switch' */
  }

  /* End of Switch: '<S295>/Switch2' */

  /* Saturate: '<S279>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S279>/Saturation1' */

  /* Sum: '<S279>/Add1' */
  rtb_Add_fp = rtb_Add_fn + rtb_Sum2_e;

  /* Saturate: '<S279>/Saturation2' */
  if (rtb_Add_fp > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_fp < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_fp;
  }

  /* End of Saturate: '<S279>/Saturation2' */

  /* Switch: '<S407>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S407>/Switch' incorporates:
     *  Fcn: '<S408>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S407>/Switch' */

  /* Trigonometry: '<S309>/Cos4' incorporates:
   *  Switch: '<S298>/Angle_Switch'
   *  Trigonometry: '<S308>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S309>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S307>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S309>/Sin4' incorporates:
   *  Switch: '<S298>/Angle_Switch'
   *  Trigonometry: '<S308>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S309>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S307>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S309>/Subtract1' incorporates:
   *  Product: '<S309>/Product2'
   *  Product: '<S309>/Product3'
   *  Trigonometry: '<S309>/Cos4'
   *  Trigonometry: '<S309>/Sin4'
   */
  rtb_Add_fn = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S309>/Subtract' incorporates:
   *  Product: '<S309>/Product'
   *  Product: '<S309>/Product1'
   *  Trigonometry: '<S309>/Cos4'
   *  Trigonometry: '<S309>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S309>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_fn);

  /* Switch: '<S309>/Switch' incorporates:
   *  Constant: '<S309>/Constant'
   *  Constant: '<S309>/Constant1'
   *  Constant: '<S310>/Constant'
   *  Product: '<S309>/Divide'
   *  Product: '<S309>/Divide1'
   *  RelationalOperator: '<S310>/Compare'
   *  Switch: '<S309>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_Switch2_cc = rtb_Add_fn / rtb_Hypot_b;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_b;
  } else {
    rtb_Switch2_cc = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S309>/Switch' */

  /* Product: '<S397>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S298>/Speed_Switch' incorporates:
   *  Abs: '<S298>/Abs'
   *  Constant: '<S306>/Constant'
   *  RelationalOperator: '<S306>/Compare'
   *  Switch: '<S298>/Angle_Switch'
   *  Trigonometry: '<S308>/Atan1'
   *  Trigonometry: '<S309>/Atan1'
   *  UnaryMinus: '<S298>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_cc, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_fp = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S308>/Subtract1' incorporates:
     *  Product: '<S308>/Product2'
     *  Product: '<S308>/Product3'
     *  UnaryMinus: '<S298>/Unary Minus'
     */
    rtb_Add_fn = (rtb_Add_k * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S308>/Subtract' incorporates:
     *  Product: '<S308>/Product'
     *  Product: '<S308>/Product1'
     */
    rtb_Hypot_b = (rtb_Add_k * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S308>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_b, rtb_Add_fn);

    /* Switch: '<S308>/Switch1' incorporates:
     *  Constant: '<S308>/Constant'
     *  Constant: '<S308>/Constant1'
     *  Constant: '<S311>/Constant'
     *  Product: '<S308>/Divide'
     *  Product: '<S308>/Divide1'
     *  RelationalOperator: '<S311>/Compare'
     *  Switch: '<S308>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_b /= rtb_Subtract1_la;
      rtb_Add_fn /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_b = 1.0;
      rtb_Add_fn = 0.0;
    }

    /* End of Switch: '<S308>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_fn, rtb_Hypot_b);
  } else {
    rtb_Add_fp = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S301>/Product2' incorporates:
   *  Constant: '<S301>/Constant'
   *  Switch: '<S298>/Speed_Switch'
   */
  rtb_Switch2_cc = rtb_Add_fp * 1154.7574092481445;

  /* Signum: '<S296>/Sign' */
  if (rtIsNaN(rtb_Switch2_cc)) {
    rtb_Add_fp = (rtNaN);
  } else if (rtb_Switch2_cc < 0.0) {
    rtb_Add_fp = -1.0;
  } else {
    rtb_Add_fp = (rtb_Switch2_cc > 0.0);
  }

  /* Signum: '<S296>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S299>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S300>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S271>/Product' incorporates:
   *  Abs: '<S296>/Abs'
   *  Abs: '<S299>/Abs'
   *  Constant: '<S302>/Constant'
   *  Constant: '<S312>/Constant3'
   *  Constant: '<S312>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S296>/OR'
   *  Lookup_n-D: '<S299>/1-D Lookup Table'
   *  Math: '<S312>/Math Function'
   *  RelationalOperator: '<S296>/Equal1'
   *  RelationalOperator: '<S302>/Compare'
   *  Signum: '<S296>/Sign'
   *  Signum: '<S296>/Sign1'
   *  Sum: '<S299>/Add'
   *  Sum: '<S312>/Add1'
   *  Sum: '<S312>/Add2'
   */
  rtb_Switch2_cc = (((real_T)((rtb_Add_fp == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_cc) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_gs,
                  1U);

  /* Sum: '<S297>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_b = rtb_Switch2_cc - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S304>/Sum1' incorporates:
   *  Constant: '<S297>/Constant2'
   *  Product: '<S304>/Product'
   *  Sum: '<S304>/Sum'
   *  UnitDelay: '<S304>/Unit Delay1'
   */
  rtb_Add_fn = ((rtb_Hypot_b - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S297>/Product' incorporates:
   *  Constant: '<S297>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_fn * Drive_Motor_Control_D;

  /* Sum: '<S303>/Diff' incorporates:
   *  UnitDelay: '<S303>/UD'
   *
   * Block description for '<S303>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S303>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_fp = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S297>/Saturation' */
  if (rtb_Add_fp > Drive_Motor_Control_D_UL) {
    rtb_Add_fp = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_fp < Drive_Motor_Control_D_LL) {
    rtb_Add_fp = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S297>/Add' incorporates:
   *  Gain: '<S297>/Gain'
   *  Gain: '<S297>/Gain1'
   *  Saturate: '<S297>/Saturation'
   */
  rtb_Hypot_b = ((Drive_Motor_Control_FF * rtb_Switch2_cc) +
                 (Drive_Motor_Control_P * rtb_Hypot_b)) + rtb_Add_fp;

  /* Saturate: '<S297>/Saturation2' incorporates:
   *  Sum: '<S297>/Add1'
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

  /* End of Saturate: '<S297>/Saturation2' */

  /* Sum: '<S313>/Add1' incorporates:
   *  Constant: '<S313>/Constant3'
   *  Constant: '<S313>/Constant4'
   *  Math: '<S313>/Math Function'
   *  Sum: '<S313>/Add2'
   */
  rtb_Switch2_cc = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S315>/Sum1' incorporates:
   *  Constant: '<S300>/Constant2'
   *  Product: '<S315>/Product'
   *  Sum: '<S315>/Sum'
   *  UnitDelay: '<S315>/Unit Delay1'
   */
  rtb_Hypot_b = ((rtb_Switch2_cc - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                 Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S300>/Product' incorporates:
   *  Constant: '<S300>/Constant3'
   */
  rtb_Switch2_kg = rtb_Hypot_b * Steering_Motor_Control_D;

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
  rtb_Add_fp = rtb_Switch2_kg - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S300>/Saturation' */
  if (rtb_Add_fp > Steering_Motor_Control_D_UL) {
    rtb_Add_fp = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_fp < Steering_Motor_Control_D_LL) {
    rtb_Add_fp = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S300>/Add' incorporates:
   *  Gain: '<S300>/Gain1'
   *  Saturate: '<S300>/Saturation'
   */
  rtb_Add_k = (Steering_Motor_Control_P * rtb_Switch2_cc) + rtb_Add_fp;

  /* Sum: '<S300>/Subtract' incorporates:
   *  Constant: '<S300>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_k;

  /* Sum: '<S300>/Sum2' incorporates:
   *  Gain: '<S300>/Gain2'
   *  UnitDelay: '<S300>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_Switch2_cc) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S316>/Switch2' incorporates:
   *  Constant: '<S300>/Constant'
   *  RelationalOperator: '<S316>/LowerRelop1'
   *  Sum: '<S300>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Add_k))) {
    /* Switch: '<S316>/Switch' incorporates:
     *  Constant: '<S300>/Constant1'
     *  RelationalOperator: '<S316>/UpperRelop'
     *  Sum: '<S300>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Add_k)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_k;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S316>/Switch' */
  }

  /* End of Switch: '<S316>/Switch2' */

  /* Saturate: '<S300>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S300>/Saturation1' */

  /* Sum: '<S300>/Add1' */
  rtb_Add_fp = rtb_Add_k + rtb_Sum2_oc;

  /* Saturate: '<S300>/Saturation2' */
  if (rtb_Add_fp > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_fp < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_fp;
  }

  /* End of Saturate: '<S300>/Saturation2' */

  /* Switch: '<S412>/Switch' */
  if (!rtb_LogicalOperator1) {
    /* Switch: '<S412>/Switch' incorporates:
     *  Fcn: '<S413>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S412>/Switch' */

  /* Trigonometry: '<S330>/Cos4' incorporates:
   *  Switch: '<S319>/Angle_Switch'
   *  Trigonometry: '<S329>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S330>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S328>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S330>/Sin4' incorporates:
   *  Switch: '<S319>/Angle_Switch'
   *  Trigonometry: '<S329>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S330>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S328>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S330>/Subtract1' incorporates:
   *  Product: '<S330>/Product2'
   *  Product: '<S330>/Product3'
   *  Trigonometry: '<S330>/Cos4'
   *  Trigonometry: '<S330>/Sin4'
   */
  rtb_Subtract1_gx = (rtb_Add_k * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S330>/Subtract' incorporates:
   *  Product: '<S330>/Product'
   *  Product: '<S330>/Product1'
   *  Trigonometry: '<S330>/Cos4'
   *  Trigonometry: '<S330>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S330>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable,
    rtb_Subtract1_gx);

  /* Switch: '<S330>/Switch' incorporates:
   *  Constant: '<S330>/Constant'
   *  Constant: '<S330>/Constant1'
   *  Constant: '<S331>/Constant'
   *  Product: '<S330>/Divide'
   *  Product: '<S330>/Divide1'
   *  RelationalOperator: '<S331>/Compare'
   *  Switch: '<S330>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Switch2_cc = rtb_Subtract1_gx / rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_cc = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S330>/Switch' */

  /* Product: '<S397>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S319>/Speed_Switch' incorporates:
   *  Abs: '<S319>/Abs'
   *  Constant: '<S327>/Constant'
   *  RelationalOperator: '<S327>/Compare'
   *  Switch: '<S319>/Angle_Switch'
   *  Trigonometry: '<S329>/Atan1'
   *  Trigonometry: '<S330>/Atan1'
   *  UnaryMinus: '<S319>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_cc, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_fp = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S329>/Subtract1' incorporates:
     *  Product: '<S329>/Product2'
     *  Product: '<S329>/Product3'
     *  UnaryMinus: '<S319>/Unary Minus'
     */
    rtb_uDLookupTable = (rtb_Add_k * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S329>/Subtract' incorporates:
     *  Product: '<S329>/Product'
     *  Product: '<S329>/Product1'
     */
    rtb_Optimized_Module_Angle = (rtb_Add_k * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S329>/Hypot' */
    rtb_Add_k = rt_hypotd_snf(rtb_Optimized_Module_Angle, rtb_uDLookupTable);

    /* Switch: '<S329>/Switch1' incorporates:
     *  Constant: '<S329>/Constant'
     *  Constant: '<S329>/Constant1'
     *  Constant: '<S332>/Constant'
     *  Product: '<S329>/Divide'
     *  Product: '<S329>/Divide1'
     *  RelationalOperator: '<S332>/Compare'
     *  Switch: '<S329>/Switch'
     */
    if (rtb_Add_k > 1.0E-6) {
      rtb_Optimized_Module_Angle /= rtb_Add_k;
      rtb_Add_k = rtb_uDLookupTable / rtb_Add_k;
    } else {
      rtb_Optimized_Module_Angle = 1.0;
      rtb_Add_k = 0.0;
    }

    /* End of Switch: '<S329>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Add_k,
      rtb_Optimized_Module_Angle);
  } else {
    rtb_Add_fp = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S322>/Product2' incorporates:
   *  Constant: '<S322>/Constant'
   *  Switch: '<S319>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_fp * 1154.7574092481445;

  /* Signum: '<S317>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_fp = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_fp = -1.0;
  } else {
    rtb_Add_fp = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S317>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S320>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S321>/Sum'
   */
  rtb_Switch2_cc = rtb_Optimized_Module_Angle_p -
    Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S272>/Product' incorporates:
   *  Abs: '<S317>/Abs'
   *  Abs: '<S320>/Abs'
   *  Constant: '<S323>/Constant'
   *  Constant: '<S333>/Constant3'
   *  Constant: '<S333>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S317>/OR'
   *  Lookup_n-D: '<S320>/1-D Lookup Table'
   *  Math: '<S333>/Math Function'
   *  RelationalOperator: '<S317>/Equal1'
   *  RelationalOperator: '<S323>/Compare'
   *  Signum: '<S317>/Sign'
   *  Signum: '<S317>/Sign1'
   *  Sum: '<S320>/Add'
   *  Sum: '<S333>/Add1'
   *  Sum: '<S333>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_fp == rtb_Add_k) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Switch2_cc + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_j,
                    rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S318>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S325>/Sum1' incorporates:
   *  Constant: '<S318>/Constant2'
   *  Product: '<S325>/Product'
   *  Sum: '<S325>/Sum'
   *  UnitDelay: '<S325>/Unit Delay1'
   */
  rtb_Add_k = ((rtb_Optimized_Module_Angle -
                Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S318>/Product' incorporates:
   *  Constant: '<S318>/Constant3'
   */
  rtb_uDLookupTable = rtb_Add_k * Drive_Motor_Control_D;

  /* Sum: '<S324>/Diff' incorporates:
   *  UnitDelay: '<S324>/UD'
   *
   * Block description for '<S324>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S324>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_fp = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S318>/Saturation' */
  if (rtb_Add_fp > Drive_Motor_Control_D_UL) {
    rtb_Add_fp = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_fp < Drive_Motor_Control_D_LL) {
    rtb_Add_fp = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S318>/Add' incorporates:
   *  Gain: '<S318>/Gain'
   *  Gain: '<S318>/Gain1'
   *  Saturate: '<S318>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF *
    rtb_MatrixConcatenate_b_idx_0) + (Drive_Motor_Control_P *
    rtb_Optimized_Module_Angle)) + rtb_Add_fp;

  /* Saturate: '<S318>/Saturation2' incorporates:
   *  Sum: '<S318>/Add1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S318>/Saturation2' */

  /* Sum: '<S334>/Add1' incorporates:
   *  Constant: '<S334>/Constant3'
   *  Constant: '<S334>/Constant4'
   *  Math: '<S334>/Math Function'
   *  Sum: '<S334>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Switch2_cc +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S336>/Sum1' incorporates:
   *  Constant: '<S321>/Constant2'
   *  Product: '<S336>/Product'
   *  Sum: '<S336>/Sum'
   *  UnitDelay: '<S336>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S321>/Product' incorporates:
   *  Constant: '<S321>/Constant3'
   */
  rtb_Subtract1_gx = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

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
  rtb_Add_fp = rtb_Subtract1_gx - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S321>/Saturation' */
  if (rtb_Add_fp > Steering_Motor_Control_D_UL) {
    rtb_Add_fp = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_fp < Steering_Motor_Control_D_LL) {
    rtb_Add_fp = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S321>/Add' incorporates:
   *  Gain: '<S321>/Gain1'
   *  Saturate: '<S321>/Saturation'
   */
  rtb_Add_gj = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_fp;

  /* Sum: '<S321>/Subtract' incorporates:
   *  Constant: '<S321>/Constant'
   */
  rtb_Switch2_cc = 1.0 - rtb_Add_gj;

  /* Sum: '<S321>/Sum2' incorporates:
   *  Gain: '<S321>/Gain2'
   *  UnitDelay: '<S321>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S337>/Switch2' incorporates:
   *  Constant: '<S321>/Constant'
   *  RelationalOperator: '<S337>/LowerRelop1'
   *  Sum: '<S321>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_gj))) {
    /* Sum: '<S321>/Subtract1' incorporates:
     *  Constant: '<S321>/Constant1'
     */
    rtb_Switch2_cc = -1.0 - rtb_Add_gj;

    /* Switch: '<S337>/Switch' incorporates:
     *  Constant: '<S321>/Constant1'
     *  RelationalOperator: '<S337>/UpperRelop'
     *  Sum: '<S321>/Subtract1'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_gj))) {
      rtb_Switch2_cc = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S337>/Switch' */
  }

  /* End of Switch: '<S337>/Switch2' */

  /* Saturate: '<S321>/Saturation1' */
  if (rtb_Switch2_cc > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_cc < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Switch2_cc;
  }

  /* End of Saturate: '<S321>/Saturation1' */

  /* Sum: '<S321>/Add1' */
  rtb_Add_fp = rtb_Add_gj + rtb_Integral_ga;

  /* Saturate: '<S321>/Saturation2' */
  if (rtb_Add_fp > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_fp < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_fp;
  }

  /* End of Saturate: '<S321>/Saturation2' */

  /* Sum: '<S355>/Add1' incorporates:
   *  Constant: '<S355>/Constant3'
   *  Constant: '<S355>/Constant4'
   *  Math: '<S355>/Math Function'
   *  Sum: '<S355>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Integral_d +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S357>/Sum1' incorporates:
   *  Constant: '<S342>/Constant2'
   *  Product: '<S357>/Product'
   *  Sum: '<S357>/Sum'
   *  UnitDelay: '<S357>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S342>/Product' incorporates:
   *  Constant: '<S342>/Constant3'
   */
  rtb_Add_gj = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S356>/Diff' incorporates:
   *  UnitDelay: '<S356>/UD'
   *
   * Block description for '<S356>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S356>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_fp = rtb_Add_gj - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S342>/Saturation' */
  if (rtb_Add_fp > Steering_Motor_Control_D_UL) {
    rtb_Add_fp = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_fp < Steering_Motor_Control_D_LL) {
    rtb_Add_fp = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S342>/Add' incorporates:
   *  Gain: '<S342>/Gain1'
   *  Saturate: '<S342>/Saturation'
   */
  rtb_Add_du = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_fp;

  /* Sum: '<S342>/Subtract' incorporates:
   *  Constant: '<S342>/Constant'
   */
  rtb_Switch2_cc = 1.0 - rtb_Add_du;

  /* Sum: '<S342>/Sum2' incorporates:
   *  Gain: '<S342>/Gain2'
   *  UnitDelay: '<S342>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S358>/Switch2' incorporates:
   *  Constant: '<S342>/Constant'
   *  RelationalOperator: '<S358>/LowerRelop1'
   *  Sum: '<S342>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_du))) {
    /* Sum: '<S342>/Subtract1' incorporates:
     *  Constant: '<S342>/Constant1'
     */
    rtb_Switch2_cc = -1.0 - rtb_Add_du;

    /* Switch: '<S358>/Switch' incorporates:
     *  Constant: '<S342>/Constant1'
     *  RelationalOperator: '<S358>/UpperRelop'
     *  Sum: '<S342>/Subtract1'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_du))) {
      rtb_Switch2_cc = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S358>/Switch' */
  }

  /* End of Switch: '<S358>/Switch2' */

  /* Saturate: '<S342>/Saturation1' */
  if (rtb_Switch2_cc > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_cc < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Switch2_cc;
  }

  /* End of Saturate: '<S342>/Saturation1' */

  /* Sum: '<S342>/Add1' */
  rtb_Add_fp = rtb_Add_du + rtb_Integral_bj;

  /* Saturate: '<S342>/Saturation2' */
  if (rtb_Add_fp > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_fp < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_fp;
  }

  /* End of Saturate: '<S342>/Saturation2' */

  /* Sum: '<S205>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S141>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S207>/Sum1' incorporates:
   *  Constant: '<S205>/Constant2'
   *  Product: '<S207>/Product'
   *  Sum: '<S205>/Sum'
   *  Sum: '<S207>/Sum'
   *  UnitDelay: '<S207>/Unit Delay1'
   */
  rtb_Add_du = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S205>/Product' incorporates:
   *  Constant: '<S205>/Constant3'
   */
  rtb_Product_lu = rtb_Add_du * 0.0;

  /* Sum: '<S206>/Diff' incorporates:
   *  UnitDelay: '<S206>/UD'
   *
   * Block description for '<S206>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S206>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_fp = rtb_Product_lu - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S205>/Saturation' */
  if (rtb_Add_fp > 0.1) {
    rtb_Add_fp = 0.1;
  } else if (rtb_Add_fp < -0.1) {
    rtb_Add_fp = -0.1;
  }

  /* Sum: '<S205>/Add' incorporates:
   *  Gain: '<S205>/Gain'
   *  Gain: '<S205>/Gain1'
   *  Saturate: '<S205>/Saturation'
   *  Sum: '<S205>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Transfer_Motor_Gain_FF *
    Robot_Control_B.RB_Desired_Transfer_Speed) + (Rebuilt_Transfer_Motor_Gain_P *
    rtb_Integral_d)) + rtb_Add_fp;

  /* Logic: '<S141>/Logical Operator1' incorporates:
   *  Constant: '<S204>/Constant'
   *  RelationalOperator: '<S204>/Compare'
   */
  rtb_Compare_mq = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S141>/Switch1' incorporates:
   *  Abs: '<S141>/Abs'
   *  Constant: '<S141>/Constant1'
   *  Constant: '<S141>/Constant2'
   *  Logic: '<S141>/Logical Operator'
   *  Logic: '<S141>/Logical Operator1'
   *  RelationalOperator: '<S141>/LessThan'
   *  UnitDelay: '<S141>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Compare_mq) {
    rtb_Compare_ky = true;
  } else {
    rtb_Compare_ky = (rtb_Compare_mq && (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S141>/Switch1' */

  /* Switch: '<S205>/Switch' incorporates:
   *  Constant: '<S205>/Constant4'
   */
  if (rtb_Compare_ky) {
    /* Sum: '<S205>/Sum2' incorporates:
     *  Gain: '<S205>/Gain2'
     *  Sum: '<S205>/Sum'
     *  UnitDelay: '<S205>/Unit Delay'
     */
    rtb_Switch2_cc = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S205>/Subtract' incorporates:
     *  Constant: '<S205>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_MatrixConcatenate_b_idx_0;

    /* Switch: '<S208>/Switch2' incorporates:
     *  Constant: '<S205>/Constant'
     *  RelationalOperator: '<S208>/LowerRelop1'
     *  Sum: '<S205>/Subtract'
     */
    if (!(rtb_Switch2_cc > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S205>/Subtract1' incorporates:
       *  Constant: '<S205>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S208>/Switch' incorporates:
       *  Constant: '<S205>/Constant1'
       *  RelationalOperator: '<S208>/UpperRelop'
       *  Sum: '<S205>/Subtract1'
       */
      if (!(rtb_Switch2_cc < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Integral_d = rtb_Switch2_cc;
      }

      /* End of Switch: '<S208>/Switch' */
    }

    /* End of Switch: '<S208>/Switch2' */

    /* Saturate: '<S205>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S205>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S205>/Switch' */

  /* Switch: '<S141>/Switch2' incorporates:
   *  Logic: '<S141>/Logical Operator1'
   */
  if (rtb_Compare_mq) {
    /* Sum: '<S205>/Add1' */
    rtb_Add_fp = rtb_MatrixConcatenate_b_idx_0 + rtb_Integral_d;

    /* Saturate: '<S205>/Saturation2' */
    if (rtb_Add_fp > 1.0) {
      /* Switch: '<S141>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_fp < -1.0) {
      /* Switch: '<S141>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S141>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_fp;
    }

    /* End of Saturate: '<S205>/Saturation2' */
  } else {
    /* Switch: '<S141>/Switch2' incorporates:
     *  Constant: '<S141>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S141>/Switch2' */

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
  rtb_Add_fp = Robot_Control_B.RB_Desired_Feeder_Speed *
    Rebuilt_Feeder_Motor_Gain_FF;

  /* Saturate: '<S12>/Saturation' */
  if (rtb_Add_fp > 1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = 1.0;
  } else if (rtb_Add_fp < -1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = -1.0;
  } else {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = rtb_Add_fp;
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
    rtb_MatrixConcatenate_b_idx_0 = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S130>/Init' incorporates:
   *  UnitDelay: '<S130>/FixPt Unit Delay1'
   *  UnitDelay: '<S130>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Switch2_cc = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Switch2_cc = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S130>/Init' */

  /* Sum: '<S128>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 -= rtb_Switch2_cc;

  /* Switch: '<S129>/Switch2' incorporates:
   *  Constant: '<S127>/Constant1'
   *  Constant: '<S127>/Constant3'
   *  RelationalOperator: '<S129>/LowerRelop1'
   *  RelationalOperator: '<S129>/UpperRelop'
   *  Switch: '<S129>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Hood_Servo_Rate_Limit_Dec)
  {
    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S129>/Switch2' */

  /* Sum: '<S128>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Switch2_cc;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Logic: '<S6>/Logical Operator'
   */
  if (rtb_Intake_Arm_Cycle || rtb_LogicalOperator1_ms) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S56>/Logical Operator1' incorporates:
   *  Constant: '<S68>/Constant'
   *  RelationalOperator: '<S68>/Compare'
   */
  rtb_LogicalOperator1_ms = !(rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Sum: '<S69>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S56>/Subtract'
   */
  rtb_Error_n = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.Measured_Intake_Roller_Speed;

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
  rtb_Product_f = rtb_Sum1_fh * 0.0;

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
  rtb_Add_fp = rtb_Product_f - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S69>/Saturation' */
  if (rtb_Add_fp > 0.1) {
    rtb_Add_fp = 0.1;
  } else if (rtb_Add_fp < -0.1) {
    rtb_Add_fp = -0.1;
  }

  /* Sum: '<S69>/Add' incorporates:
   *  Gain: '<S69>/Gain'
   *  Gain: '<S69>/Gain1'
   *  Saturate: '<S69>/Saturation'
   *  Sum: '<S69>/Sum'
   */
  rtb_Switch2_cc = ((Rebuilt_Roller_Motor_Gain_FF *
                     rtb_MatrixConcatenate_b_idx_0) +
                    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_fp;

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
    rtb_Compare_mq = true;
  } else {
    rtb_Compare_mq = (rtb_LogicalOperator1_ms &&
                      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S56>/Switch1' */

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/Constant4'
   */
  if (rtb_Compare_mq) {
    /* Sum: '<S69>/Sum2' incorporates:
     *  Gain: '<S69>/Gain2'
     *  Sum: '<S69>/Sum'
     *  UnitDelay: '<S69>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n)
      + Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S69>/Subtract' incorporates:
     *  Constant: '<S69>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Switch2_cc;

    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S69>/Constant'
     *  RelationalOperator: '<S72>/LowerRelop1'
     *  Sum: '<S69>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Switch2_cc))) {
      /* Sum: '<S69>/Subtract1' incorporates:
       *  Constant: '<S69>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Switch2_cc;

      /* Switch: '<S72>/Switch' incorporates:
       *  Constant: '<S69>/Constant1'
       *  RelationalOperator: '<S72>/UpperRelop'
       *  Sum: '<S69>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Switch2_cc))) {
        rtb_Error_n = rtb_MatrixConcatenate_b_idx_0;
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
    rtb_Add_fp = rtb_Switch2_cc + rtb_Error_n;

    /* Saturate: '<S69>/Saturation2' */
    if (rtb_Add_fp > 1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_fp < -1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_fp;
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

  /* Switch: '<S67>/Init' incorporates:
   *  UnitDelay: '<S67>/FixPt Unit Delay1'
   *  UnitDelay: '<S67>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S67>/Init' */

  /* Sum: '<S65>/Sum1' */
  rtb_Switch2_cc = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S66>/Switch2' incorporates:
   *  Constant: '<S55>/Constant1'
   *  Constant: '<S55>/Constant3'
   *  RelationalOperator: '<S66>/LowerRelop1'
   *  RelationalOperator: '<S66>/UpperRelop'
   *  Switch: '<S66>/Switch'
   */
  if (rtb_Switch2_cc > Rebuilt_Intake_RL_Inc) {
    rtb_Switch2_cc = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Switch2_cc < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    rtb_Switch2_cc = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S66>/Switch2' */

  /* Sum: '<S65>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Switch2_cc +
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S61>/Sum' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S63>/Sum1' incorporates:
   *  Constant: '<S61>/Constant2'
   *  Product: '<S63>/Product'
   *  Sum: '<S63>/Sum'
   *  UnitDelay: '<S63>/Unit Delay1'
   */
  rtb_Sum1_dj = ((rtb_MatrixConcatenate_b_idx_0 -
                  Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S61>/Product' incorporates:
   *  Constant: '<S61>/Constant3'
   */
  rtb_Product_ob = rtb_Sum1_dj * Rebuilt_Intake_Arm_Gain_D;

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
  rtb_Add_fp = rtb_Product_ob - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S61>/Saturation' */
  if (rtb_Add_fp > 0.1) {
    rtb_Add_fp = 0.1;
  } else if (rtb_Add_fp < -0.1) {
    rtb_Add_fp = -0.1;
  }

  /* Sum: '<S61>/Add' incorporates:
   *  Gain: '<S61>/Gain'
   *  Gain: '<S61>/Gain1'
   *  Saturate: '<S61>/Saturation'
   */
  rtb_Add_i = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
               (Rebuilt_Intake_Arm_Gain_P * rtb_MatrixConcatenate_b_idx_0)) +
    rtb_Add_fp;

  /* Sum: '<S61>/Subtract' incorporates:
   *  Constant: '<S61>/Constant'
   */
  rtb_Switch2_cc = 1.0 - rtb_Add_i;

  /* Sum: '<S61>/Sum2' incorporates:
   *  Gain: '<S61>/Gain2'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (0.0 * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S64>/Switch2' incorporates:
   *  Constant: '<S61>/Constant'
   *  RelationalOperator: '<S64>/LowerRelop1'
   *  Sum: '<S61>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_i))) {
    /* Sum: '<S61>/Subtract1' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    rtb_Switch2_cc = -1.0 - rtb_Add_i;

    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S61>/Constant1'
     *  RelationalOperator: '<S64>/UpperRelop'
     *  Sum: '<S61>/Subtract1'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_i))) {
      rtb_Switch2_cc = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S64>/Switch' */
  }

  /* End of Switch: '<S64>/Switch2' */

  /* Saturate: '<S61>/Saturation1' */
  if (rtb_Switch2_cc > 0.1) {
    rtb_MatrixConcatenate_b_idx_0 = 0.1;
  } else if (rtb_Switch2_cc < -0.1) {
    rtb_MatrixConcatenate_b_idx_0 = -0.1;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_cc;
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
    rtb_Add_fp = rtb_Add_i + rtb_MatrixConcatenate_b_idx_0;

    /* Saturate: '<S61>/Saturation2' */
    if (rtb_Add_fp > 1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_fp < -1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_fp;
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

  /* Logic: '<S137>/Logical Operator1' incorporates:
   *  Constant: '<S189>/Constant'
   *  RelationalOperator: '<S189>/Compare'
   */
  rtb_LogicalOperator1_ms = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S190>/Sum' incorporates:
   *  Sum: '<S137>/Subtract'
   */
  rtb_Subtract_ai = Robot_Control_B.RB_Desired_Shooter_Speed - rtb_Subtract_ai;

  /* Sum: '<S192>/Sum1' incorporates:
   *  Constant: '<S190>/Constant2'
   *  Product: '<S192>/Product'
   *  Sum: '<S190>/Sum'
   *  Sum: '<S192>/Sum'
   *  UnitDelay: '<S192>/Unit Delay1'
   */
  rtb_Switch2_cc = ((rtb_Subtract_ai - Robot_Control_DW.UnitDelay1_DSTATE_in) *
                    0.1) + Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S190>/Product' incorporates:
   *  Constant: '<S190>/Constant3'
   */
  rtb_Add_i = rtb_Switch2_cc * 0.0;

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
  rtb_Add_fp = rtb_Add_i - Robot_Control_DW.UD_DSTATE_kz;

  /* Saturate: '<S190>/Saturation' */
  if (rtb_Add_fp > 0.1) {
    rtb_Add_fp = 0.1;
  } else if (rtb_Add_fp < -0.1) {
    rtb_Add_fp = -0.1;
  }

  /* Gain: '<S190>/Gain' incorporates:
   *  Gain: '<S195>/Gain'
   *  Gain: '<S200>/Gain'
   */
  rtb_Error_j = Rebuilt_Shooter_Motor_Gain_FF *
    Robot_Control_B.RB_Desired_Shooter_Speed;

  /* Sum: '<S190>/Add' incorporates:
   *  Gain: '<S190>/Gain'
   *  Gain: '<S190>/Gain1'
   *  Saturate: '<S190>/Saturation'
   *  Sum: '<S190>/Sum'
   */
  rtb_Add_ir = ((Rebuilt_Shooter_Motor_Gain_P * rtb_Subtract_ai) + rtb_Error_j)
    + rtb_Add_fp;

  /* Switch: '<S137>/Switch4' incorporates:
   *  Constant: '<S137>/Constant6'
   *  Constant: '<S137>/Constant7'
   *  Logic: '<S137>/Logical Operator1'
   *  Logic: '<S137>/Logical Operator2'
   *  RelationalOperator: '<S137>/LessThan2'
   *  UnitDelay: '<S137>/Unit Delay1'
   */
  if ((rtb_Subtract_ai < 0.0) && rtb_LogicalOperator1_ms) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_ms &&
      (Robot_Control_DW.UnitDelay1_DSTATE_ea));
  }

  /* End of Switch: '<S137>/Switch4' */

  /* Switch: '<S137>/Switch1' incorporates:
   *  Constant: '<S137>/Constant1'
   *  Constant: '<S137>/Constant2'
   *  Logic: '<S137>/Logical Operator'
   *  Logic: '<S137>/Logical Operator1'
   *  RelationalOperator: '<S137>/LessThan'
   *  UnitDelay: '<S137>/Unit Delay'
   */
  if ((rtb_Subtract_ai < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_ms) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_ms &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S137>/Switch1' */

  /* Switch: '<S190>/Switch' incorporates:
   *  Constant: '<S190>/Constant4'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S190>/Sum2' incorporates:
     *  Gain: '<S190>/Gain2'
     *  Product: '<S190>/Product1'
     *  Sum: '<S190>/Sum'
     *  Switch: '<S190>/Switch1'
     *  UnitDelay: '<S190>/Unit Delay'
     */
    rtb_Subtract_ai = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Subtract_ai) *
                       ((real_T)(!rtb_Intake_Arm_Move_In))) +
      Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S190>/Subtract' incorporates:
     *  Constant: '<S190>/Constant'
     */
    rtb_Error_c5 = 1.0 - rtb_Add_ir;

    /* Switch: '<S193>/Switch2' incorporates:
     *  Constant: '<S190>/Constant'
     *  RelationalOperator: '<S193>/LowerRelop1'
     *  Sum: '<S190>/Subtract'
     */
    if (!(rtb_Subtract_ai > (1.0 - rtb_Add_ir))) {
      /* Sum: '<S190>/Subtract1' incorporates:
       *  Constant: '<S190>/Constant1'
       */
      rtb_Error_c5 = -1.0 - rtb_Add_ir;

      /* Switch: '<S193>/Switch' incorporates:
       *  Constant: '<S190>/Constant1'
       *  RelationalOperator: '<S193>/UpperRelop'
       *  Sum: '<S190>/Subtract1'
       */
      if (!(rtb_Subtract_ai < (-1.0 - rtb_Add_ir))) {
        rtb_Error_c5 = rtb_Subtract_ai;
      }

      /* End of Switch: '<S193>/Switch' */
    }

    /* End of Switch: '<S193>/Switch2' */

    /* Saturate: '<S190>/Saturation1' */
    if (rtb_Error_c5 > 0.1) {
      rtb_Subtract_ai = 0.1;
    } else if (rtb_Error_c5 < -0.1) {
      rtb_Subtract_ai = -0.1;
    } else {
      rtb_Subtract_ai = rtb_Error_c5;
    }

    /* End of Saturate: '<S190>/Saturation1' */
  } else {
    rtb_Subtract_ai = 0.0;
  }

  /* End of Switch: '<S190>/Switch' */

  /* Switch: '<S10>/Switch2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Logic: '<S137>/Logical Operator1'
   *  Switch: '<S137>/Switch2'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Shooter_Motor_DC_Left' incorporates:
     *  Constant: '<S10>/Constant3'
     */
    Robot_Control_Y.Shooter_Motor_DC_Left = TEST_Shooter_Motor_DC_Left_OV;
  } else if (rtb_LogicalOperator1_ms) {
    /* Sum: '<S190>/Add1' incorporates:
     *  Switch: '<S137>/Switch2'
     */
    rtb_Add_fp = rtb_Add_ir + rtb_Subtract_ai;

    /* Saturate: '<S190>/Saturation2' incorporates:
     *  Switch: '<S137>/Switch2'
     */
    if (rtb_Add_fp > 1.0) {
      /* Outport: '<Root>/Shooter_Motor_DC_Left' */
      Robot_Control_Y.Shooter_Motor_DC_Left = 1.0;
    } else if (rtb_Add_fp < -1.0) {
      /* Outport: '<Root>/Shooter_Motor_DC_Left' */
      Robot_Control_Y.Shooter_Motor_DC_Left = -1.0;
    } else {
      /* Outport: '<Root>/Shooter_Motor_DC_Left' */
      Robot_Control_Y.Shooter_Motor_DC_Left = rtb_Add_fp;
    }

    /* End of Saturate: '<S190>/Saturation2' */
  } else {
    /* Outport: '<Root>/Shooter_Motor_DC_Left' incorporates:
     *  Constant: '<S137>/Constant3'
     *  Switch: '<S137>/Switch2'
     */
    Robot_Control_Y.Shooter_Motor_DC_Left = 0.0;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Sum: '<S195>/Sum' incorporates:
   *  Sum: '<S138>/Subtract'
   */
  rtb_Subtract_j3 = Robot_Control_B.RB_Desired_Shooter_Speed - rtb_Subtract_j3;

  /* Sum: '<S197>/Sum1' incorporates:
   *  Constant: '<S195>/Constant2'
   *  Product: '<S197>/Product'
   *  Sum: '<S195>/Sum'
   *  Sum: '<S197>/Sum'
   *  UnitDelay: '<S197>/Unit Delay1'
   */
  rtb_Add_ir = ((rtb_Subtract_j3 - Robot_Control_DW.UnitDelay1_DSTATE_fw) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_fw;

  /* Product: '<S195>/Product' incorporates:
   *  Constant: '<S195>/Constant3'
   */
  rtb_Error_c5 = rtb_Add_ir * 0.0;

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
  rtb_Add_fp = rtb_Error_c5 - Robot_Control_DW.UD_DSTATE_gz;

  /* Saturate: '<S195>/Saturation' */
  if (rtb_Add_fp > 0.1) {
    rtb_Add_fp = 0.1;
  } else if (rtb_Add_fp < -0.1) {
    rtb_Add_fp = -0.1;
  }

  /* Sum: '<S195>/Add' incorporates:
   *  Gain: '<S195>/Gain1'
   *  Saturate: '<S195>/Saturation'
   *  Sum: '<S195>/Sum'
   */
  rtb_Add_l = ((Rebuilt_Shooter_Motor_Gain_P * rtb_Subtract_j3) + rtb_Error_j) +
    rtb_Add_fp;

  /* Logic: '<S138>/Logical Operator1' incorporates:
   *  Constant: '<S194>/Constant'
   *  RelationalOperator: '<S194>/Compare'
   */
  rtb_LogicalOperator5 = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Switch: '<S138>/Switch4' incorporates:
   *  Constant: '<S138>/Constant6'
   *  Constant: '<S138>/Constant7'
   *  Logic: '<S138>/Logical Operator1'
   *  Logic: '<S138>/Logical Operator2'
   *  RelationalOperator: '<S138>/LessThan2'
   *  UnitDelay: '<S138>/Unit Delay1'
   */
  if ((rtb_Subtract_j3 < 0.0) && rtb_LogicalOperator5) {
    rtb_LogicalOperator1_ms = true;
  } else {
    rtb_LogicalOperator1_ms = (rtb_LogicalOperator5 &&
      (Robot_Control_DW.UnitDelay1_DSTATE_m));
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
  if ((rtb_Subtract_j3 < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator5) {
    rtb_LogicalOperator1 = true;
  } else {
    rtb_LogicalOperator1 = (rtb_LogicalOperator5 &&
      (Robot_Control_DW.UnitDelay_DSTATE_kn));
  }

  /* End of Switch: '<S138>/Switch1' */

  /* Switch: '<S195>/Switch' incorporates:
   *  Constant: '<S195>/Constant4'
   */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S195>/Sum2' incorporates:
     *  Gain: '<S195>/Gain2'
     *  Product: '<S195>/Product1'
     *  Sum: '<S195>/Sum'
     *  Switch: '<S195>/Switch1'
     *  UnitDelay: '<S195>/Unit Delay'
     */
    rtb_Subtract_j3 = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Subtract_j3) *
                       ((real_T)(!rtb_LogicalOperator1_ms))) +
      Robot_Control_DW.UnitDelay_DSTATE_a;

    /* Sum: '<S195>/Subtract' incorporates:
     *  Constant: '<S195>/Constant'
     */
    rtb_Error_mx = 1.0 - rtb_Add_l;

    /* Switch: '<S198>/Switch2' incorporates:
     *  Constant: '<S195>/Constant'
     *  RelationalOperator: '<S198>/LowerRelop1'
     *  Sum: '<S195>/Subtract'
     */
    if (!(rtb_Subtract_j3 > (1.0 - rtb_Add_l))) {
      /* Sum: '<S195>/Subtract1' incorporates:
       *  Constant: '<S195>/Constant1'
       */
      rtb_Error_mx = -1.0 - rtb_Add_l;

      /* Switch: '<S198>/Switch' incorporates:
       *  Constant: '<S195>/Constant1'
       *  RelationalOperator: '<S198>/UpperRelop'
       *  Sum: '<S195>/Subtract1'
       */
      if (!(rtb_Subtract_j3 < (-1.0 - rtb_Add_l))) {
        rtb_Error_mx = rtb_Subtract_j3;
      }

      /* End of Switch: '<S198>/Switch' */
    }

    /* End of Switch: '<S198>/Switch2' */

    /* Saturate: '<S195>/Saturation1' */
    if (rtb_Error_mx > 0.1) {
      rtb_Subtract_j3 = 0.1;
    } else if (rtb_Error_mx < -0.1) {
      rtb_Subtract_j3 = -0.1;
    } else {
      rtb_Subtract_j3 = rtb_Error_mx;
    }

    /* End of Saturate: '<S195>/Saturation1' */
  } else {
    rtb_Subtract_j3 = 0.0;
  }

  /* End of Switch: '<S195>/Switch' */

  /* Switch: '<S10>/Switch3' incorporates:
   *  Constant: '<S10>/Constant'
   *  Logic: '<S138>/Logical Operator1'
   *  Switch: '<S138>/Switch2'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Shooter_Motor_DC_Center' incorporates:
     *  Constant: '<S10>/Constant4'
     */
    Robot_Control_Y.Shooter_Motor_DC_Center = TEST_Shooter_Motor_DC_Center_OV;
  } else if (rtb_LogicalOperator5) {
    /* Sum: '<S195>/Add1' incorporates:
     *  Switch: '<S138>/Switch2'
     */
    rtb_Add_fp = rtb_Add_l + rtb_Subtract_j3;

    /* Saturate: '<S195>/Saturation2' incorporates:
     *  Switch: '<S138>/Switch2'
     */
    if (rtb_Add_fp > 1.0) {
      /* Outport: '<Root>/Shooter_Motor_DC_Center' */
      Robot_Control_Y.Shooter_Motor_DC_Center = 1.0;
    } else if (rtb_Add_fp < -1.0) {
      /* Outport: '<Root>/Shooter_Motor_DC_Center' */
      Robot_Control_Y.Shooter_Motor_DC_Center = -1.0;
    } else {
      /* Outport: '<Root>/Shooter_Motor_DC_Center' */
      Robot_Control_Y.Shooter_Motor_DC_Center = rtb_Add_fp;
    }

    /* End of Saturate: '<S195>/Saturation2' */
  } else {
    /* Outport: '<Root>/Shooter_Motor_DC_Center' incorporates:
     *  Constant: '<S138>/Constant3'
     *  Switch: '<S138>/Switch2'
     */
    Robot_Control_Y.Shooter_Motor_DC_Center = 0.0;
  }

  /* End of Switch: '<S10>/Switch3' */

  /* Sum: '<S200>/Sum' incorporates:
   *  Sum: '<S139>/Subtract'
   */
  rtb_Switch2_hw = Robot_Control_B.RB_Desired_Shooter_Speed - rtb_Switch2_hw;

  /* Sum: '<S202>/Sum1' incorporates:
   *  Constant: '<S200>/Constant2'
   *  Product: '<S202>/Product'
   *  Sum: '<S200>/Sum'
   *  Sum: '<S202>/Sum'
   *  UnitDelay: '<S202>/Unit Delay1'
   */
  rtb_Add_l = ((rtb_Switch2_hw - Robot_Control_DW.UnitDelay1_DSTATE_h) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_h;

  /* Product: '<S200>/Product' incorporates:
   *  Constant: '<S200>/Constant3'
   */
  rtb_Error_mx = rtb_Add_l * 0.0;

  /* Sum: '<S201>/Diff' incorporates:
   *  UnitDelay: '<S201>/UD'
   *
   * Block description for '<S201>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S201>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_fp = rtb_Error_mx - Robot_Control_DW.UD_DSTATE_p;

  /* Saturate: '<S200>/Saturation' */
  if (rtb_Add_fp > 0.1) {
    rtb_Add_fp = 0.1;
  } else if (rtb_Add_fp < -0.1) {
    rtb_Add_fp = -0.1;
  }

  /* Sum: '<S200>/Add' incorporates:
   *  Gain: '<S200>/Gain1'
   *  Saturate: '<S200>/Saturation'
   *  Sum: '<S200>/Sum'
   */
  rtb_Add_fp += (Rebuilt_Shooter_Motor_Gain_P * rtb_Switch2_hw) + rtb_Error_j;

  /* Logic: '<S139>/Logical Operator1' incorporates:
   *  Constant: '<S199>/Constant'
   *  RelationalOperator: '<S199>/Compare'
   */
  rtb_LogicalOperator5 = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Switch: '<S139>/Switch4' incorporates:
   *  Constant: '<S139>/Constant6'
   *  Constant: '<S139>/Constant7'
   *  Logic: '<S139>/Logical Operator1'
   *  Logic: '<S139>/Logical Operator2'
   *  RelationalOperator: '<S139>/LessThan2'
   *  UnitDelay: '<S139>/Unit Delay1'
   */
  if ((rtb_Switch2_hw < 0.0) && rtb_LogicalOperator5) {
    rtb_Compare_pb = true;
  } else {
    rtb_Compare_pb = (rtb_LogicalOperator5 &&
                      (Robot_Control_DW.UnitDelay1_DSTATE_ck));
  }

  /* End of Switch: '<S139>/Switch4' */

  /* Switch: '<S139>/Switch1' incorporates:
   *  Constant: '<S139>/Constant1'
   *  Constant: '<S139>/Constant2'
   *  Logic: '<S139>/Logical Operator'
   *  Logic: '<S139>/Logical Operator1'
   *  RelationalOperator: '<S139>/LessThan'
   *  UnitDelay: '<S139>/Unit Delay'
   */
  if ((rtb_Switch2_hw < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator5) {
    rtb_Is_Absolute_Translation_g = true;
  } else {
    rtb_Is_Absolute_Translation_g = (rtb_LogicalOperator5 &&
      (Robot_Control_DW.UnitDelay_DSTATE_ek));
  }

  /* End of Switch: '<S139>/Switch1' */

  /* Switch: '<S200>/Switch' incorporates:
   *  Constant: '<S200>/Constant4'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* Sum: '<S200>/Sum2' incorporates:
     *  Gain: '<S200>/Gain2'
     *  Product: '<S200>/Product1'
     *  Sum: '<S200>/Sum'
     *  Switch: '<S200>/Switch1'
     *  UnitDelay: '<S200>/Unit Delay'
     */
    rtb_Switch2_hw = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Switch2_hw) * ((real_T)
      (!rtb_Compare_pb))) + Robot_Control_DW.UnitDelay_DSTATE_dr;

    /* Sum: '<S200>/Subtract' incorporates:
     *  Constant: '<S200>/Constant'
     */
    rtb_Error_j = 1.0 - rtb_Add_fp;

    /* Switch: '<S203>/Switch2' incorporates:
     *  Constant: '<S200>/Constant'
     *  RelationalOperator: '<S203>/LowerRelop1'
     *  Sum: '<S200>/Subtract'
     */
    if (!(rtb_Switch2_hw > (1.0 - rtb_Add_fp))) {
      /* Sum: '<S200>/Subtract1' incorporates:
       *  Constant: '<S200>/Constant1'
       */
      rtb_Error_j = -1.0 - rtb_Add_fp;

      /* Switch: '<S203>/Switch' incorporates:
       *  Constant: '<S200>/Constant1'
       *  RelationalOperator: '<S203>/UpperRelop'
       *  Sum: '<S200>/Subtract1'
       */
      if (!(rtb_Switch2_hw < (-1.0 - rtb_Add_fp))) {
        rtb_Error_j = rtb_Switch2_hw;
      }

      /* End of Switch: '<S203>/Switch' */
    }

    /* End of Switch: '<S203>/Switch2' */

    /* Saturate: '<S200>/Saturation1' */
    if (rtb_Error_j > 0.1) {
      rtb_Switch2_hw = 0.1;
    } else if (rtb_Error_j < -0.1) {
      rtb_Switch2_hw = -0.1;
    } else {
      rtb_Switch2_hw = rtb_Error_j;
    }

    /* End of Saturate: '<S200>/Saturation1' */
  } else {
    rtb_Switch2_hw = 0.0;
  }

  /* End of Switch: '<S200>/Switch' */

  /* Switch: '<S10>/Switch4' incorporates:
   *  Constant: '<S10>/Constant'
   *  Logic: '<S139>/Logical Operator1'
   *  Switch: '<S139>/Switch2'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Shooter_Motor_DC_Right' incorporates:
     *  Constant: '<S10>/Constant5'
     */
    Robot_Control_Y.Shooter_Motor_DC_Right = TEST_Shooter_Motor_DC_Right_OV;
  } else if (rtb_LogicalOperator5) {
    /* Sum: '<S200>/Add1' incorporates:
     *  Switch: '<S139>/Switch2'
     */
    rtb_Add_fp += rtb_Switch2_hw;

    /* Saturate: '<S200>/Saturation2' incorporates:
     *  Switch: '<S139>/Switch2'
     */
    if (rtb_Add_fp > 1.0) {
      /* Outport: '<Root>/Shooter_Motor_DC_Right' */
      Robot_Control_Y.Shooter_Motor_DC_Right = 1.0;
    } else if (rtb_Add_fp < -1.0) {
      /* Outport: '<Root>/Shooter_Motor_DC_Right' */
      Robot_Control_Y.Shooter_Motor_DC_Right = -1.0;
    } else {
      /* Outport: '<Root>/Shooter_Motor_DC_Right' */
      Robot_Control_Y.Shooter_Motor_DC_Right = rtb_Add_fp;
    }

    /* End of Saturate: '<S200>/Saturation2' */
  } else {
    /* Outport: '<Root>/Shooter_Motor_DC_Right' incorporates:
     *  Constant: '<S139>/Constant3'
     *  Switch: '<S139>/Switch2'
     */
    Robot_Control_Y.Shooter_Motor_DC_Right = 0.0;
  }

  /* End of Switch: '<S10>/Switch4' */

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

  /* Update for UnitDelay: '<S370>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S370>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S176>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_o = rtb_Merge1;

  /* Update for UnitDelay: '<S177>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Saturation_h;

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

  /* Update for UnitDelay: '<S393>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S392>/UD'
   *
   * Block description for '<S392>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Switch_hs;

  /* Update for UnitDelay: '<S390>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch1_n;

  /* Update for UnitDelay: '<S372>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Switch2_iq;

  /* Update for UnitDelay: '<S387>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S387>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S387>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Switch2_iq;

  /* Update for UnitDelay: '<S371>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Add_md;

  /* Update for UnitDelay: '<S380>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S380>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S380>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Add_md;

  /* Update for UnitDelay: '<S346>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S345>/UD'
   *
   * Block description for '<S345>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S339>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S283>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S282>/UD'
   *
   * Block description for '<S282>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Subtract_ow;

  /* Update for UnitDelay: '<S276>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S294>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S293>/UD'
   *
   * Block description for '<S293>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_im;

  /* Update for UnitDelay: '<S279>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S304>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_fn;

  /* Update for UnitDelay: '<S303>/UD'
   *
   * Block description for '<S303>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S297>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S315>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_b;

  /* Update for UnitDelay: '<S314>/UD'
   *
   * Block description for '<S314>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_kg;

  /* Update for UnitDelay: '<S300>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S325>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_k;

  /* Update for UnitDelay: '<S324>/UD'
   *
   * Block description for '<S324>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S318>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S336>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S335>/UD'
   *
   * Block description for '<S335>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Subtract1_gx;

  /* Update for UnitDelay: '<S321>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S357>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S356>/UD'
   *
   * Block description for '<S356>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_gj;

  /* Update for UnitDelay: '<S342>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S207>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_du;

  /* Update for UnitDelay: '<S206>/UD'
   *
   * Block description for '<S206>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lu;

  /* Update for UnitDelay: '<S205>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S141>/Unit Delay' */
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
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_f;

  /* Update for UnitDelay: '<S69>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S56>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Compare_mq;

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
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_ob;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S192>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Switch2_cc;

  /* Update for UnitDelay: '<S191>/UD'
   *
   * Block description for '<S191>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Add_i;

  /* Update for UnitDelay: '<S137>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S190>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Subtract_ai;

  /* Update for UnitDelay: '<S137>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_db = rtb_Intake_Arm_Move_Out;

  /* Update for UnitDelay: '<S197>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_fw = rtb_Add_ir;

  /* Update for UnitDelay: '<S196>/UD'
   *
   * Block description for '<S196>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_gz = rtb_Error_c5;

  /* Update for UnitDelay: '<S138>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_m = rtb_LogicalOperator1_ms;

  /* Update for UnitDelay: '<S195>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_a = rtb_Subtract_j3;

  /* Update for UnitDelay: '<S138>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kn = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S202>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_h = rtb_Add_l;

  /* Update for UnitDelay: '<S201>/UD'
   *
   * Block description for '<S201>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_p = rtb_Error_mx;

  /* Update for UnitDelay: '<S139>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ck = rtb_Compare_pb;

  /* Update for UnitDelay: '<S200>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dr = rtb_Switch2_hw;

  /* Update for UnitDelay: '<S139>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ek = rtb_Is_Absolute_Translation_g;
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

  /* InitializeConditions for UnitDelay: '<S370>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S387>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S380>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S130>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S67>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S450>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S215>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S211>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S215>/Robot_Index_Is_Valid' */
  /* Start for If: '<S218>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S218>/Circle_Check_Valid' */
  /* Start for If: '<S220>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S218>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S215>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S170>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S172>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S174>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay' */
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
