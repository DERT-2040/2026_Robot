/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.478
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Mar 26 21:53:31 2026
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

/* Named constants for Chart: '<S357>/Add dither' */
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
                                      * Referenced by: '<S430>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S426>/Constant'
                                        *   '<S426>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S430>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S426>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S260>/Constant3'
                                        *   '<S281>/Constant3'
                                        *   '<S302>/Constant3'
                                        *   '<S323>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S260>/Constant2'
                                   *   '<S281>/Constant2'
                                   *   '<S302>/Constant2'
                                   *   '<S323>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S260>/Saturation'
                                        *   '<S281>/Saturation'
                                        *   '<S302>/Saturation'
                                        *   '<S323>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S260>/Saturation'
                                        *   '<S281>/Saturation'
                                        *   '<S302>/Saturation'
                                        *   '<S323>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S260>/Gain'
                                            *   '<S281>/Gain'
                                            *   '<S302>/Gain'
                                            *   '<S323>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S260>/Gain2'
                                        *   '<S281>/Gain2'
                                        *   '<S302>/Gain2'
                                        *   '<S323>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S260>/Saturation1'
                                         *   '<S281>/Saturation1'
                                         *   '<S302>/Saturation1'
                                         *   '<S323>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S260>/Saturation1'
                                        *   '<S281>/Saturation1'
                                        *   '<S302>/Saturation1'
                                        *   '<S323>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S260>/Gain1'
                                        *   '<S281>/Gain1'
                                        *   '<S302>/Gain1'
                                        *   '<S323>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S265>/Constant'
                            *   '<S286>/Constant'
                            *   '<S307>/Constant'
                            *   '<S328>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S179>/BlueAllianceZoneX'
                                         *   '<S181>/BlueAllianceZoneX'
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
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S148>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S148>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S180>/RedAllianceZoneX'
                                         *   '<S182>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S148>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S148>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S416>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S416>/Constant5'
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
                                       * Referenced by: '<S143>/Constant'
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
                                       * Referenced by: '<S166>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S170>/Constant3'
                                   *   '<S171>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S162>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S163>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S164>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S165>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S167>/Unit Delay'
                                      *   '<S168>/Unit Delay'
                                      *   '<S169>/Unit Delay'
                                      *   '<S170>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S167>/Constant2'
                                      *   '<S168>/Constant2'
                                      *   '<S169>/Constant2'
                                      *   '<S170>/Constant2'
                                      *   '<S172>/Constant'
                                      *   '<S173>/Constant'
                                      *   '<S174>/Constant'
                                      *   '<S175>/Constant'
                                      */
real_T Rebuilt_Match_Time_TeleOp = 140.0;/* Variable: Rebuilt_Match_Time_TeleOp
                                          * Referenced by: '<S133>/Constant'
                                          */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S160>/Constant'
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
                                        * Referenced by: '<S145>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S145>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S145>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 2.7; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S145>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S145>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S145>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S145>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S145>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S146>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S146>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S146>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S146>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S146>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S146>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S146>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S146>/Constant1'
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
                                             * Referenced by: '<S159>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S159>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3265.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S159>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3425.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S159>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3625.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S159>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3775.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S159>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S159>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S159>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S158>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S158>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3450.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S158>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3600.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S158>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3800.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S158>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3950.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S158>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4150.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S158>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S158>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S152>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S152>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S152>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S152>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S152>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S152>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S152>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S152>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S156>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S137>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S184>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S184>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.001;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                             * Referenced by: '<S184>/Gain1'
                                             */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S147>/Constant2'
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
                                      * Referenced by: '<S189>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S189>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S189>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S415>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S413>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S415>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S416>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S416>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S249>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S249>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S196>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S209>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S249>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S356>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S356>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S356>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S356>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S356>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S356>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S374>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S374>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S374>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S374>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S373>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S374>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S374>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S374>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S374>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S374>/Constant1'
                                   *   '<S374>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S374>/Constant'
                                   *   '<S374>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S357>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S357>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S357>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S357>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S263>/Constant3'
                                        *   '<S284>/Constant3'
                                        *   '<S305>/Constant3'
                                        *   '<S326>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S263>/Constant2'
                                *   '<S284>/Constant2'
                                *   '<S305>/Constant2'
                                *   '<S326>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S263>/Saturation'
                                           *   '<S284>/Saturation'
                                           *   '<S305>/Saturation'
                                           *   '<S326>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S263>/Saturation'
                                          *   '<S284>/Saturation'
                                          *   '<S305>/Saturation'
                                          *   '<S326>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S263>/Gain2'
                                         *   '<S284>/Gain2'
                                         *   '<S305>/Gain2'
                                         *   '<S326>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S263>/Saturation1'
                                             *   '<S284>/Saturation1'
                                             *   '<S305>/Saturation1'
                                             *   '<S326>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S263>/Saturation1'
                                            *   '<S284>/Saturation1'
                                            *   '<S305>/Saturation1'
                                            *   '<S326>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S263>/Gain1'
                                        *   '<S284>/Gain1'
                                        *   '<S305>/Gain1'
                                        *   '<S326>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S355>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S355>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S355>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S355>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S355>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S355>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S415>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S415>/Constant1'
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
                                      * Referenced by: '<S414>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S414>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S414>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S343>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S343>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S343>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S343>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S343>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S343>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S416>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S415>/Dead Zone'
                                        *   '<S416>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S415>/Dead Zone'
                                        *   '<S416>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S413>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S413>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S413>/Constant4'
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
                                        * Referenced by: '<S413>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S413>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S413>/Constant5'
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
                                        *   '<S413>/Constant11'
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
  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay' */
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
  boolean_T rtb_Compare_nn;

  /* RelationalOperator: '<S172>/Compare' incorporates:
   *  Constant: '<S167>/Constant1'
   *  Constant: '<S172>/Constant'
   *  Sum: '<S167>/Sum'
   *  UnitDelay: '<S167>/Unit Delay'
   */
  rtb_Compare_nn = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S167>/Logical Operator' incorporates:
   *  Logic: '<S167>/NOT'
   */
  *rty_IsBlueActive = ((!(rtu_IsBlueInactiveFirst != 0.0)) || rtb_Compare_nn);

  /* Logic: '<S167>/Logical Operator1' */
  *rty_IsRedActive = ((rtu_IsBlueInactiveFirst != 0.0) || rtb_Compare_nn);

  /* Switch: '<S167>/Switch' incorporates:
   *  Constant: '<S167>/Constant1'
   *  Constant: '<S167>/Constant2'
   *  Logic: '<S167>/Logical Operator2'
   *  Sum: '<S167>/Subtract'
   *  Sum: '<S167>/Sum'
   *  UnitDelay: '<S167>/Unit Delay'
   */
  if ((boolean_T)((rtu_IsBlueInactiveFirst != 0.0) ^ (rtu_IsBlueAlliance != 0.0)))
  {
    *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;
  } else {
    *rty_Time_Remaining = (localDW->UnitDelay_DSTATE - 0.02) -
      Rebuilt_Match_Time_Shoot_Early;
  }

  /* End of Switch: '<S167>/Switch' */

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
  int32_T s221_iter;
  uint16_T s246_iter;
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
  boolean_T rtb_LogicalOperator1_n;
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

  /* If: '<S442>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S442>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S445>/Action Port'
     */
    /* Product: '<S445>/Product' incorporates:
     *  Constant: '<S445>/Constant1'
     *  Constant: '<S445>/Constant2'
     *  Math: '<S445>/Math Function'
     */
    rtb_Sin4 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495) *
      111.0;

    /* End of Outputs for SubSystem: '<S442>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S442>/Subsystem' incorporates:
     *  ActionPort: '<S446>/Action Port'
     */
    /* SignalConversion generated from: '<S446>/Out1' incorporates:
     *  Constant: '<S446>/Constant'
     */
    rtb_Sin4 = 0.0;

    /* End of Outputs for SubSystem: '<S442>/Subsystem' */
  }

  /* End of If: '<S442>/If' */

  /* Gain: '<S443>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Init_o = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S444>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Sin4 * cos(rtb_Init_o)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S444>/theta->y'
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
      rtb_Init_o = 0.0;
    } else {
      rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
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
    if (rtb_LogicalOperator1) {
      rtb_Shooter_Active_prev = (rtb_Init_o >= Auto_Shoot_Time);
    } else if (rtb_LogicalOperator5) {
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
      rtb_LogicalOperator1_n = false;
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
      rtb_LogicalOperator1_n = false;
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
      rtb_LogicalOperator1_n = false;
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
      rtb_LogicalOperator1_n = true;
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
    Robot_Control_DW.DelayInput1_DSTATE_kb = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Init_o;

    /* Update for UnitDelay: '<S28>/Delay Input1'
     *
     * Block description for '<S28>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_h = rtb_LogicalOperator5;

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
       *  UnitDelay: '<S415>/Unit Delay1'
       *  UnitDelay: '<S415>/Unit Delay2'
       *  UnitDelay: '<S415>/Unit Delay3'
       *  UnitDelay: '<S415>/Unit Delay4'
       *  UnitDelay: '<S418>/Delay Input1'
       *  UnitDelay: '<S419>/Delay Input1'
       *  UnitDelay: '<S420>/Delay Input1'
       *  UnitDelay: '<S421>/Delay Input1'
       *  UnitDelay: '<S423>/Delay Input1'
       *  UnitDelay: '<S429>/Unit Delay'
       *  UnitDelay: '<S429>/Unit Delay1'
       *  UnitDelay: '<S433>/FixPt Unit Delay1'
       *  UnitDelay: '<S433>/FixPt Unit Delay2'
       *
       * Block description for '<S418>/Delay Input1':
       *
       *  Store in Global RAM
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
       * Block description for '<S423>/Delay Input1':
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

    /* Switch: '<S413>/Switch4' incorporates:
     *  Constant: '<S438>/Constant'
     *  Constant: '<S441>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S438>/Compare'
     *  RelationalOperator: '<S441>/Compare'
     *  Switch: '<S413>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S413>/Switch4' incorporates:
       *  Constant: '<S413>/Constant8'
       *  Sum: '<S413>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S413>/Switch5' incorporates:
       *  Constant: '<S413>/Constant7'
       *  Gain: '<S413>/Gain'
       *  Sum: '<S413>/Subtract5'
       *  Switch: '<S413>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S413>/Switch4' incorporates:
       *  Constant: '<S413>/Constant6'
       *  Switch: '<S413>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S413>/Switch4' */

    /* Logic: '<S413>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S413>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S415>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_oy = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_oy = 0.0;
    } else {
      rtb_Add_oy = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S415>/Add' incorporates:
     *  Constant: '<S415>/Constant'
     *  Constant: '<S415>/Constant1'
     *  DeadZone: '<S415>/Dead Zone'
     *  Lookup_n-D: '<S415>/Modulation_Str_Y_Rel'
     *  Product: '<S415>/Product'
     *  Product: '<S415>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Add_oy * Steering_Twist_Gain);

    /* RelationalOperator: '<S417>/Compare' incorporates:
     *  Constant: '<S417>/Constant'
     */
    rtb_Compare_lk = (rtb_Switch1_m == 0.0);

    /* Logic: '<S415>/AND2' incorporates:
     *  RelationalOperator: '<S418>/FixPt Relational Operator'
     *  RelationalOperator: '<S419>/FixPt Relational Operator'
     *  RelationalOperator: '<S420>/FixPt Relational Operator'
     *  RelationalOperator: '<S421>/FixPt Relational Operator'
     *  UnitDelay: '<S418>/Delay Input1'
     *  UnitDelay: '<S419>/Delay Input1'
     *  UnitDelay: '<S420>/Delay Input1'
     *  UnitDelay: '<S421>/Delay Input1'
     *
     * Block description for '<S418>/Delay Input1':
     *
     *  Store in Global RAM
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
     */
    rtb_Intake_Arm_Cycle = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_Compare_pb) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S415>/AND1' incorporates:
     *  Logic: '<S415>/AND3'
     *  UnitDelay: '<S415>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_lk && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S415>/AND4' incorporates:
     *  Logic: '<S415>/AND8'
     *  UnitDelay: '<S415>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_lk && (!rtb_Intake_Arm_Cycle)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S415>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* Switch: '<S415>/Switch8' incorporates:
     *  Constant: '<S424>/Constant'
     *  Logic: '<S415>/AND9'
     *  RelationalOperator: '<S423>/FixPt Relational Operator'
     *  RelationalOperator: '<S424>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S423>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S423>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_lk) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S415>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S415>/Switch8' incorporates:
       *  UnitDelay: '<S415>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S415>/Switch8' */

    /* Switch: '<S415>/Switch4' incorporates:
     *  Constant: '<S415>/Constant5'
     *  Switch: '<S415>/Switch1'
     *  Switch: '<S415>/Switch5'
     *  Switch: '<S415>/Switch6'
     *  Switch: '<S415>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Saturation_h = 0.0;
    } else if (rtb_Compare_pb) {
      /* Switch: '<S415>/Switch5' incorporates:
       *  Constant: '<S415>/Constant6'
       */
      rtb_Saturation_h = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S415>/Switch6' incorporates:
       *  Constant: '<S415>/Constant7'
       *  Switch: '<S415>/Switch5'
       */
      rtb_Saturation_h = 3.1415926535897931;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S415>/Switch7' incorporates:
       *  Constant: '<S415>/Constant8'
       *  Switch: '<S415>/Switch5'
       *  Switch: '<S415>/Switch6'
       */
      rtb_Saturation_h = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S415>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S415>/Switch5'
       *  Switch: '<S415>/Switch6'
       *  Switch: '<S415>/Switch7'
       */
      rtb_Saturation_h = 0.0;
    } else {
      /* Switch: '<S415>/Switch6' incorporates:
       *  Switch: '<S415>/Switch5'
       *  Switch: '<S415>/Switch7'
       *  UnitDelay: '<S415>/Unit Delay1'
       */
      rtb_Saturation_h = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S415>/Switch4' */

    /* Switch: '<S415>/Switch2' incorporates:
     *  Switch: '<S415>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S415>/Switch2' incorporates:
       *  Constant: '<S415>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S415>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Saturation_h;
    } else {
      /* Switch: '<S415>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S415>/Switch3' incorporates:
       *  Constant: '<S415>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S415>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S415>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S414>/Switch1' incorporates:
     *  Constant: '<S414>/Constant5'
     *  Constant: '<S414>/Constant8'
     *  DataTypeConversion: '<S414>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_lk;
    }

    /* End of Switch: '<S414>/Switch1' */

    /* Lookup_n-D: '<S416>/Modulation_Drv' incorporates:
     *  Math: '<S416>/Magnitude'
     */
    rtb_Switch_hs = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S427>/Compare' incorporates:
     *  Constant: '<S427>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Switch_hs == 0.0);

    /* DeadZone: '<S416>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_Switch1_n = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S416>/Dead Zone' */

    /* Logic: '<S416>/Logical Operator' incorporates:
     *  Constant: '<S428>/Constant'
     *  RelationalOperator: '<S428>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Switch1_n != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S414>/Switch' incorporates:
     *  Constant: '<S414>/Constant5'
     *  Constant: '<S414>/Constant7'
     *  DataTypeConversion: '<S414>/Data Type Conversion'
     *  Logic: '<S416>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S414>/Switch' */

    /* Switch: '<S413>/Switch2' incorporates:
     *  Constant: '<S413>/Constant2'
     *  Constant: '<S437>/Constant'
     *  Constant: '<S440>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S437>/Compare'
     *  RelationalOperator: '<S440>/Compare'
     *  Sum: '<S413>/Subtract'
     *  Switch: '<S413>/Switch'
     *  Switch: '<S413>/Switch1'
     *  Switch: '<S413>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S413>/Switch2' incorporates:
       *  Constant: '<S413>/Constant5'
       *  Sum: '<S413>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S413>/Switch2' incorporates:
       *  Constant: '<S413>/Constant4'
       *  Sum: '<S413>/Subtract2'
       *  Switch: '<S413>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S413>/Switch1' incorporates:
       *  Constant: '<S413>/Constant1'
       *  Sum: '<S413>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S413>/Switch2' incorporates:
       *  Constant: '<S413>/Constant3'
       *  Switch: '<S413>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S413>/Switch1' incorporates:
       *  Constant: '<S413>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S413>/Switch2' */

    /* UnaryMinus: '<S413>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S429>/Switch1' incorporates:
     *  Constant: '<S434>/Constant'
     *  Constant: '<S435>/Constant'
     *  Logic: '<S429>/AND'
     *  RelationalOperator: '<S434>/Compare'
     *  RelationalOperator: '<S435>/Compare'
     *  Switch: '<S429>/Switch2'
     *  UnitDelay: '<S429>/Unit Delay'
     *  UnitDelay: '<S429>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Init_o = rtb_Switch1_hb;
      rtb_Sin4 = rtb_Sum1;
    }

    /* End of Switch: '<S429>/Switch1' */

    /* Switch: '<S416>/Switch1' incorporates:
     *  Logic: '<S416>/Logical Operator1'
     *  Switch: '<S416>/Switch4'
     *  Switch: '<S416>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S416>/Sign' */
      if (rtIsNaN(rtb_Switch1_n)) {
        rtb_Add_oy = (rtNaN);
      } else if (rtb_Switch1_n < 0.0) {
        rtb_Add_oy = -1.0;
      } else {
        rtb_Add_oy = (rtb_Switch1_n > 0.0);
      }

      /* Switch: '<S416>/Switch5' incorporates:
       *  Constant: '<S416>/Constant3'
       *  Constant: '<S416>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S416>/Gain3'
       *  Signum: '<S416>/Sign'
       *  Sum: '<S416>/Add'
       *  Switch: '<S416>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_oy) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S416>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S416>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S416>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S416>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S416>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S416>/Switch4'
       *  Trigonometry: '<S416>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Init_o, rtb_Sin4);
    }

    /* End of Switch: '<S416>/Switch1' */

    /* Switch: '<S426>/Switch1' incorporates:
     *  Constant: '<S426>/Constant'
     *  Constant: '<S426>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S426>/Switch1' */

    /* Switch: '<S433>/Init' incorporates:
     *  UnitDelay: '<S433>/FixPt Unit Delay1'
     *  UnitDelay: '<S433>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S433>/Init' */

    /* Sum: '<S431>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S432>/Switch2' incorporates:
     *  Constant: '<S430>/Constant1'
     *  Constant: '<S430>/Constant3'
     *  RelationalOperator: '<S432>/LowerRelop1'
     *  RelationalOperator: '<S432>/UpperRelop'
     *  Switch: '<S432>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S432>/Switch' incorporates:
       *  Constant: '<S430>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S432>/Switch2' */

    /* Sum: '<S431>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S416>/Switch8' incorporates:
     *  Logic: '<S416>/Logical Operator1'
     *  Switch: '<S416>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S416>/Switch' incorporates:
       *  Gain: '<S416>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Switch1_n;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S416>/Constant5'
       *  Gain: '<S416>/Gain2'
       *  Math: '<S416>/Magnitude1'
       *  MinMax: '<S416>/Min'
       *  Switch: '<S416>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S426>/Product' incorporates:
       *  Switch: '<S416>/Switch2'
       */
      rtb_Add_oy = rtb_Switch_hs * rtb_Init;

      /* Saturate: '<S426>/Saturation' incorporates:
       *  Switch: '<S416>/Switch2'
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

      /* End of Saturate: '<S426>/Saturation' */
    }

    /* End of Switch: '<S416>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S415>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Switch: '<S413>/Switch6' incorporates:
     *  Constant: '<S413>/Constant11'
     *  Switch: '<S413>/Switch7'
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

    /* RelationalOperator: '<S410>/Compare' incorporates:
     *  Constant: '<S410>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Compare_ky = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S411>/Compare' incorporates:
     *  Constant: '<S411>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Compare_mq = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S406>/Compare' incorporates:
     *  Constant: '<S406>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S409>/Compare' incorporates:
     *  Constant: '<S409>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S408>/Compare' incorporates:
     *  Constant: '<S408>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S407>/Compare' incorporates:
     *  Constant: '<S407>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     */
    rtb_Switch1_m = 0.0;

    /* Update for UnitDelay: '<S423>/Delay Input1'
     *
     * Block description for '<S423>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_lk;

    /* Update for UnitDelay: '<S422>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S422>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S418>/Delay Input1'
     *
     * Block description for '<S418>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S419>/Delay Input1'
     *
     * Block description for '<S419>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_Compare_pb;

    /* Update for UnitDelay: '<S420>/Delay Input1'
     *
     * Block description for '<S420>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S421>/Delay Input1'
     *
     * Block description for '<S421>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S415>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S415>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S415>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S415>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S429>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Init_o;

    /* Update for UnitDelay: '<S429>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Sin4;

    /* Update for UnitDelay: '<S433>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S433>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S433>/FixPt Unit Delay1' */
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
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Init_o;

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
    rtb_Saturation_h = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Init_o);

    /* Product: '<S124>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S73>/C'
     *  Delay: '<S73>/MemoryX'
     *  Product: '<S126>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Init_o;

    /* Sum: '<S124>/Sum' incorporates:
     *  Constant: '<S73>/D'
     *  Product: '<S124>/C[k]*xhat[k|k-1]'
     *  Product: '<S124>/D[k]*u[k]'
     *  Sum: '<S124>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Init_o);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S124>/Product3' incorporates:
     *  Constant: '<S74>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Saturation_h) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S124>/Product3' incorporates:
     *  Constant: '<S74>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Saturation_h) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S126>/Product2' incorporates:
     *  Constant: '<S74>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
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
   *  Constant: '<S246>/Constant'
   *  Logic: '<S246>/AND'
   *  MATLAB Function: '<S196>/Find closest index to curve'
   *  Product: '<S246>/Product'
   *  RelationalOperator: '<S246>/Relational Operator'
   *  RelationalOperator: '<S246>/Relational Operator1'
   *  Selector: '<S246>/Selector'
   *  Selector: '<S246>/Selector1'
   *  Selector: '<S247>/Selector'
   *  Sum: '<S246>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S199>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S202>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S204>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d0 = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S199>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S194>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S194>/Unit Delay'
       *  UnitDelay: '<S195>/Unit Delay'
       *  UnitDelay: '<S197>/Unit Delay'
       *  UnitDelay: '<S197>/Unit Delay1'
       *  UnitDelay: '<S247>/Unit Delay'
       *  UnitDelay: '<S247>/Unit Delay1'
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
     *  ActionPort: '<S194>/Action Port'
     */
    /* Selector: '<S195>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S195>/Selector1' */

    /* Lookup_n-D: '<S194>/Capture Radius' incorporates:
     *  UnitDelay: '<S194>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S195>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S195>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S199>/If' incorporates:
     *  RelationalOperator: '<S199>/ '
     *  UnitDelay: '<S195>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S202>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S204>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d0 = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S199>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S202>/Action Port'
       */
      /* InitializeConditions for If: '<S199>/If' incorporates:
       *  UnitDelay: '<S202>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S199>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S199>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S202>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S202>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S205>/Action Port'
       */
      /* If: '<S202>/If' incorporates:
       *  Selector: '<S195>/Selector1'
       *  Selector: '<S202>/Selector'
       *  Selector: '<S205>/Selector'
       */
      rtb_Switch2_p2 = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S202>/Increment_If_Rectangle_Check' */

      /* Sum: '<S202>/Minus' incorporates:
       *  Concatenate: '<S195>/Matrix Concatenate2'
       *  Selector: '<S202>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Switch2_p2;

      /* Outputs for IfAction SubSystem: '<S202>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S205>/Action Port'
       */
      /* If: '<S202>/If' incorporates:
       *  Selector: '<S195>/Selector1'
       *  Selector: '<S202>/Selector'
       *  Selector: '<S205>/Selector'
       *  Sum: '<S202>/Minus'
       */
      rtb_Switch_hs = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S202>/Increment_If_Rectangle_Check' */

      /* Sum: '<S202>/Minus' incorporates:
       *  Concatenate: '<S195>/Matrix Concatenate2'
       *  Selector: '<S202>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Switch_hs;

      /* Math: '<S202>/Hypot' */
      rtb_Init_o = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S202>/Equal' */
      rtb_LogicalOperator5 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S202>/Switch' incorporates:
       *  Logic: '<S202>/AND'
       *  Logic: '<S202>/OR'
       *  RelationalOperator: '<S202>/Relational Operator'
       *  UnitDelay: '<S202>/Unit Delay'
       */
      rtb_LogicalOperator1 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Init_o <= rtb_Saturation_h) && rtb_LogicalOperator5));

      /* If: '<S202>/If' */
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
        /* Disable for If: '<S204>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d0 = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S202>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S204>/Action Port'
         */
        /* If: '<S204>/If' incorporates:
         *  RelationalOperator: '<S204>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d0;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d0 = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S204>/Is_Last_Point' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          /* InitializeConditions for If: '<S204>/If' incorporates:
           *  UnitDelay: '<S207>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S204>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S204>/Is_Last_Point' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          /* Switch: '<S207>/Switch' incorporates:
           *  Constant: '<S209>/Constant'
           *  Logic: '<S207>/OR'
           *  RelationalOperator: '<S209>/Compare'
           *  UnitDelay: '<S207>/Unit Delay'
           */
          rtb_Is_Absolute_Translation_g = ((Robot_Control_DW.UnitDelay_DSTATE_nu)
            || (rtb_Init_o <= Spline_Stop_Radius));

          /* If: '<S207>/If' */
          if (rtb_Is_Absolute_Translation_g) {
            /* Outputs for IfAction SubSystem: '<S207>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S210>/Action Port'
             */
            /* Merge: '<S199>/Merge2' incorporates:
             *  Constant: '<S210>/Constant'
             *  SignalConversion generated from: '<S210>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = true;

            /* SignalConversion generated from: '<S210>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S210>/Constant1'
             */
            rtb_Compare_pb = false;

            /* End of Outputs for SubSystem: '<S207>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S207>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S211>/Action Port'
             */
            /* Merge: '<S199>/Merge2' incorporates:
             *  Constant: '<S211>/Constant'
             *  SignalConversion generated from: '<S211>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = false;

            /* SignalConversion generated from: '<S211>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S211>/Constant1'
             */
            rtb_Compare_pb = true;

            /* End of Outputs for SubSystem: '<S207>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S207>/If' */

          /* Merge: '<S199>/Merge4' incorporates:
           *  SignalConversion: '<S207>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S207>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Is_Absolute_Translation_g;

          /* End of Outputs for SubSystem: '<S204>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S204>/Increment_Search' incorporates:
           *  ActionPort: '<S206>/Action Port'
           */
          /* Merge: '<S199>/Merge2' incorporates:
           *  Constant: '<S206>/Constant'
           *  SignalConversion generated from: '<S206>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator5 = false;

          /* SignalConversion generated from: '<S206>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S206>/Constant1'
           */
          rtb_Compare_pb = false;

          /* Merge: '<S199>/Merge4' incorporates:
           *  Constant: '<S208>/FixPt Constant'
           *  SignalConversion: '<S206>/Signal Copy'
           *  Sum: '<S208>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S204>/Increment_Search' */
        }

        /* End of If: '<S204>/If' */
        /* End of Outputs for SubSystem: '<S202>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S202>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S205>/Action Port'
         */
        /* Sum: '<S212>/FixPt Sum1' incorporates:
         *  Constant: '<S212>/FixPt Constant'
         */
        rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S205>/Selector1' incorporates:
         *  Selector: '<S195>/Selector1'
         */
        rtb_Minus_k_idx_0 = rtb_Ref_Poses[((int32_T)rtb_Init_o) - 1];

        /* Sum: '<S213>/Subtract' incorporates:
         *  Selector: '<S205>/Selector1'
         *  Sum: '<S213>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Minus_k_idx_0 - rtb_Switch2_p2;

        /* Selector: '<S205>/Selector1' incorporates:
         *  Selector: '<S195>/Selector1'
         */
        rtb_Switch1_n = rtb_Ref_Poses[((int32_T)rtb_Init_o) + 9];

        /* Sum: '<S213>/Subtract' incorporates:
         *  Selector: '<S205>/Selector1'
         *  Sum: '<S213>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1_n - rtb_Switch_hs;

        /* Math: '<S213>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S213>/Divide' */
        rtb_Init_o = rtb_Minus_n[1];

        /* UnaryMinus: '<S213>/Unary Minus' */
        rtb_Switch2_c3 = rtb_Minus_n[0];

        /* Product: '<S213>/Product' incorporates:
         *  Product: '<S213>/Divide'
         *  UnaryMinus: '<S213>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Init_o / rtb_Sin4) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Switch2_c3) / rtb_Sin4) * rtb_Saturation_h;

        /* Sum: '<S213>/Add1' incorporates:
         *  Sum: '<S213>/Add2'
         *  Sum: '<S213>/Minus'
         */
        rtb_Switch2_c3 = rtb_Minus_k_idx_0 - rtb_Minus_n[0];

        /* Sum: '<S213>/Minus4' incorporates:
         *  Sum: '<S213>/Add2'
         *  Sum: '<S213>/Minus'
         */
        rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_0 + rtb_Minus_n[0]) -
          rtb_Switch2_c3;

        /* Sum: '<S213>/Minus5' incorporates:
         *  Concatenate: '<S195>/Matrix Concatenate2'
         *  Sum: '<S213>/Minus'
         */
        rtb_Init = rtb_Reshapey[0] - rtb_Switch2_c3;

        /* Sum: '<S213>/Add' incorporates:
         *  Sum: '<S213>/Add2'
         *  Sum: '<S213>/Minus1'
         */
        rtb_Init_o = rtb_Switch2_p2 - rtb_Minus_n[0];

        /* Sum: '<S213>/Minus' incorporates:
         *  Sum: '<S213>/Minus1'
         */
        rtb_Switch2_c3 -= rtb_Init_o;

        /* DotProduct: '<S213>/Dot Product' incorporates:
         *  Concatenate: '<S195>/Matrix Concatenate2'
         *  Sum: '<S213>/Minus'
         *  Sum: '<S213>/Minus1'
         *  Sum: '<S213>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Init_o) * rtb_Switch2_c3;

        /* DotProduct: '<S213>/Dot Product1' incorporates:
         *  Sum: '<S213>/Minus'
         */
        rtb_Switch2_p2 = rtb_Switch2_c3 * rtb_Switch2_c3;

        /* DotProduct: '<S213>/Dot Product2' incorporates:
         *  Sum: '<S213>/Minus4'
         *  Sum: '<S213>/Minus5'
         */
        rtb_Minus_k_idx_1 = rtb_Minus_k_idx_0 * rtb_Init;

        /* DotProduct: '<S213>/Dot Product3' incorporates:
         *  Sum: '<S213>/Minus4'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0 * rtb_Minus_k_idx_0;

        /* Sum: '<S213>/Add1' incorporates:
         *  Sum: '<S213>/Add2'
         *  Sum: '<S213>/Minus'
         */
        rtb_Switch2_c3 = rtb_Switch1_n - rtb_Minus_n[1];

        /* Sum: '<S213>/Minus4' incorporates:
         *  Sum: '<S213>/Add2'
         *  Sum: '<S213>/Minus'
         */
        rtb_Minus_k_idx_0 = (rtb_Switch1_n + rtb_Minus_n[1]) - rtb_Switch2_c3;

        /* Sum: '<S213>/Minus5' incorporates:
         *  Concatenate: '<S195>/Matrix Concatenate2'
         *  Sum: '<S213>/Minus'
         */
        rtb_Init = rtb_Reshapey[1] - rtb_Switch2_c3;

        /* Sum: '<S213>/Add' incorporates:
         *  Sum: '<S213>/Add2'
         *  Sum: '<S213>/Minus1'
         */
        rtb_Init_o = rtb_Switch_hs - rtb_Minus_n[1];

        /* Sum: '<S213>/Minus' incorporates:
         *  Sum: '<S213>/Minus1'
         */
        rtb_Switch2_c3 -= rtb_Init_o;

        /* DotProduct: '<S213>/Dot Product' incorporates:
         *  Concatenate: '<S195>/Matrix Concatenate2'
         *  Sum: '<S213>/Minus'
         *  Sum: '<S213>/Minus1'
         *  Sum: '<S213>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Init_o) * rtb_Switch2_c3;

        /* RelationalOperator: '<S214>/Compare' incorporates:
         *  Constant: '<S214>/Constant'
         */
        rtb_LogicalOperator5 = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S213>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S213>/Dot Product1'
         *  Sum: '<S213>/Minus'
         */
        rtb_Compare_pb = (rtb_Sin4 <= ((rtb_Switch2_c3 * rtb_Switch2_c3) +
          rtb_Switch2_p2));

        /* DotProduct: '<S213>/Dot Product2' incorporates:
         *  Sum: '<S213>/Minus4'
         *  Sum: '<S213>/Minus5'
         */
        rtb_Sin4 = (rtb_Minus_k_idx_0 * rtb_Init) + rtb_Minus_k_idx_1;

        /* Merge: '<S199>/Merge4' incorporates:
         *  Constant: '<S215>/Constant'
         *  DataTypeConversion: '<S205>/Data Type Conversion'
         *  DotProduct: '<S213>/Dot Product3'
         *  Logic: '<S213>/AND'
         *  RelationalOperator: '<S213>/LessThanOrEqual1'
         *  RelationalOperator: '<S215>/Compare'
         *  Sum: '<S205>/Add'
         *  Sum: '<S213>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_LogicalOperator5 &&
          rtb_Compare_pb) && (rtb_Sin4 >= 0.0)) && (rtb_Sin4 <=
          ((rtb_Minus_k_idx_0 * rtb_Minus_k_idx_0) +
           rtb_MatrixConcatenate_b_idx_0)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S199>/Merge2' incorporates:
         *  Constant: '<S205>/Constant2'
         *  SignalConversion generated from: '<S205>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S205>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S205>/Constant1'
         */
        rtb_Compare_pb = false;

        /* End of Outputs for SubSystem: '<S202>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S202>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S203>/Action Port'
         */
        /* Merge: '<S199>/Merge2' incorporates:
         *  Constant: '<S203>/Constant2'
         *  SignalConversion generated from: '<S203>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S203>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S203>/Constant1'
         */
        rtb_Compare_pb = false;

        /* Merge: '<S199>/Merge4' incorporates:
         *  SignalConversion generated from: '<S203>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S202>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S199>/Merge1' incorporates:
       *  Constant: '<S202>/Constant'
       *  SignalConversion generated from: '<S202>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S202>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator1;

      /* End of Outputs for SubSystem: '<S199>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S199>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      /* Merge: '<S199>/Merge1' incorporates:
       *  Constant: '<S201>/Constant'
       *  SignalConversion generated from: '<S201>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S199>/Merge2' incorporates:
       *  Constant: '<S201>/Constant1'
       *  SignalConversion generated from: '<S201>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator5 = false;

      /* SignalConversion generated from: '<S201>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S201>/Constant2'
       */
      rtb_Compare_pb = false;

      /* Merge: '<S199>/Merge4' incorporates:
       *  SignalConversion generated from: '<S201>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S199>/Escape_Auto_Driving' */
    }

    /* End of If: '<S199>/If' */

    /* If: '<S195>/If1' */
    if (!rtb_Compare_pb) {
      /* Outputs for IfAction SubSystem: '<S195>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S200>/Action Port'
       */
      /* Bias: '<S216>/Add Constant' incorporates:
       *  Bias: '<S216>/Bias'
       *  Sum: '<S216>/Subtract'
       */
      rtb_Init_o = ((Robot_Control_B.Spline_Num_Poses -
                     Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S216>/Selector4' incorporates:
       *  Bias: '<S216>/Bias1'
       *  Constant: '<S218>/FixPt Constant'
       *  Sum: '<S218>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S216>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S216>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s221_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S216>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S216>/Selector5' incorporates:
       *  Concatenate: '<S216>/Matrix Concatenate'
       *  Gain: '<S220>/Gain'
       *  Selector: '<S195>/Selector1'
       *  Selector: '<S216>/Selector2'
       *  Selector: '<S216>/Selector3'
       *  Sum: '<S220>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s221_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S216>/Matrix Concatenate' incorporates:
       *  Bias: '<S216>/Add Constant1'
       *  Gain: '<S219>/Gain'
       *  Selector: '<S195>/Selector1'
       *  Selector: '<S216>/Selector'
       *  Selector: '<S216>/Selector1'
       *  Selector: '<S216>/Selector5'
       *  Sum: '<S219>/Subtract'
       */
      s221_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s221_iter;
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

      /* Selector: '<S216>/Selector4' */
      s221_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s221_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S216>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S216>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S216>/Assignment' incorporates:
       *  Concatenate: '<S216>/Matrix Concatenate'
       *  Selector: '<S216>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s221_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S217>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S221>/While Iterator'
       */
      s221_iter = 1;
      do {
        rtb_Switch2_p2 = rtb_Assignment[s221_iter + 1];
        rtb_Minus_n[0] = rtb_Switch2_p2 - rtb_Assignment[s221_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s221_iter] - rtb_Assignment[s221_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Switch2_p2 - rtb_Assignment[s221_iter];
        rtb_Switch2_p2 = rtb_Assignment[s221_iter + 13];
        rtb_Minus_n[1] = rtb_Switch2_p2 - rtb_Assignment[s221_iter + 11];
        rtb_Switch2_c3 = rtb_Assignment[s221_iter + 12];
        rtb_Add2[1] = rtb_Switch2_c3 - rtb_Assignment[s221_iter + 14];
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
            rtb_Switch2_p2)) + rtb_Assignment[s221_iter];
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

        if (s221_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s221_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Init_o - ((real_T)s221_iter);
        rtb_Num_Segments = s221_iter;
        s221_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s221_iter <= 3));

      /* End of Outputs for SubSystem: '<S217>/Sampling_Loop' */

      /* SignalConversion generated from: '<S200>/Position_and_Curvature' incorporates:
       *  Assignment: '<S221>/Assignment'
       *  Merge: '<S195>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S195>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S195>/If Action Subsystem' incorporates:
       *  ActionPort: '<S198>/Action Port'
       */
      /* Product: '<S198>/Product' incorporates:
       *  Selector: '<S195>/Selector'
       *  Selector: '<S195>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) - 1];

      /* Product: '<S198>/Product1' incorporates:
       *  Selector: '<S195>/Selector'
       *  Selector: '<S195>/Selector1'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses) + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S198>/Product' incorporates:
         *  Constant: '<S198>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S198>/Product1' incorporates:
         *  Constant: '<S198>/Constant2'
         *  Product: '<S198>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Init_o;
      }

      /* Assignment: '<S198>/Assignment' incorporates:
       *  Concatenate: '<S198>/Matrix Concatenate'
       *  Merge: '<S195>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S198>/Assignment' */

      /* SignalConversion generated from: '<S198>/Num_Segments' incorporates:
       *  Constant: '<S198>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S195>/If Action Subsystem' */
    }

    /* End of If: '<S195>/If1' */

    /* Concatenate: '<S196>/Matrix Concatenate' incorporates:
     *  Merge: '<S195>/Merge'
     *  Selector: '<S196>/Selector'
     *  Selector: '<S196>/Selector1'
     *  Selector: '<S196>/Selector3'
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

    /* End of Concatenate: '<S196>/Matrix Concatenate' */

    /* MATLAB Function: '<S196>/Distance Along Curve' incorporates:
     *  Concatenate: '<S196>/Matrix Concatenate'
     *  Selector: '<S196>/Selector4'
     *  Selector: '<S196>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s221_iter = 0; s221_iter < 149; s221_iter++) {
      /* Outputs for Iterator SubSystem: '<S217>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S221>/While Iterator'
       */
      rtb_Assignment_d[s221_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s221_iter + 1] -
         rtb_MatrixConcatenate_o[s221_iter], rtb_MatrixConcatenate_o[s221_iter +
         151] - rtb_MatrixConcatenate_o[s221_iter + 150]) +
        rtb_Assignment_d[s221_iter];

      /* End of Outputs for SubSystem: '<S217>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S196>/Distance Along Curve' */

    /* MATLAB Function: '<S196>/Find closest index to curve' incorporates:
     *  Concatenate: '<S196>/Matrix Concatenate'
     *  Selector: '<S196>/Selector4'
     *  Selector: '<S196>/Selector5'
     *  Selector: '<S247>/Selector'
     */
    for (s221_iter = 0; s221_iter < 150; s221_iter++) {
      /* Outputs for Iterator SubSystem: '<S217>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S221>/While Iterator'
       */
      distance_from_robot[s221_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s221_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s221_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S217>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s221_iter = 1;
    } else {
      s221_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s221_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s221_iter == 0) {
      rtb_Init_o = distance_from_robot[0];
    } else {
      rtb_Init_o = distance_from_robot[s221_iter - 1];
      for (rtb_Bias1_p = s221_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Init_o > rtb_Sin4) {
          rtb_Init_o = rtb_Sin4;
        }
      }
    }

    s221_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s221_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Init_o) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S247>/Selector' incorporates:
     *  Constant: '<S247>/Constant'
     *  MATLAB Function: '<S196>/Find closest index to curve'
     *  MinMax: '<S247>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s221_iter)) - 1];

    /* If: '<S247>/If' incorporates:
     *  RelationalOperator: '<S247>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S247>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S250>/Action Port'
       */
      /* SignalConversion generated from: '<S250>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S252>/FixPt Sum1' incorporates:
       *  Constant: '<S252>/FixPt Constant'
       */
      rtb_Init_o = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S250>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S250>/Selector11'
       *  Selector: '<S250>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S250>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S250>/Selector1'
       *  Selector: '<S250>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Init_o) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S250>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S250>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Init_o), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S250>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S250>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S250>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S247>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S247>/Latch' incorporates:
       *  ActionPort: '<S251>/Action Port'
       */
      /* SignalConversion generated from: '<S251>/In1' incorporates:
       *  UnitDelay: '<S247>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S251>/In2' incorporates:
       *  UnitDelay: '<S247>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S247>/Latch' */
    }

    /* End of If: '<S247>/If' */

    /* MinMax: '<S194>/Min' incorporates:
     *  Lookup_n-D: '<S194>/Lookahead Distance'
     *  UnitDelay: '<S194>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S196>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S246>/While Iterator'
     */
    s246_iter = 1U;
    rtb_LogicalOperator1 = true;
    while (rtb_LogicalOperator1 && (s246_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S196>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S246>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s246_iter;
      rtb_LogicalOperator1 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s221_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s246_iter++;
    }

    /* End of Outputs for SubSystem: '<S196>/Find first index that meets distance target' */

    /* Switch: '<S249>/Switch' incorporates:
     *  Concatenate: '<S196>/Matrix Concatenate'
     *  Constant: '<S196>/Constant'
     *  Constant: '<S246>/Constant'
     *  Constant: '<S249>/Constant'
     *  Constant: '<S249>/Constant1'
     *  Constant: '<S249>/Constant2'
     *  Constant: '<S249>/Constant3'
     *  Logic: '<S246>/AND'
     *  MATLAB Function: '<S196>/Find closest index to curve'
     *  Math: '<S249>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S249>/Max'
     *  MinMax: '<S249>/Min'
     *  MinMax: '<S249>/Min1'
     *  Product: '<S246>/Product'
     *  Product: '<S249>/Divide'
     *  Product: '<S249>/Product'
     *  Product: '<S249>/Product1'
     *  RelationalOperator: '<S196>/Relational Operator'
     *  RelationalOperator: '<S246>/Relational Operator'
     *  RelationalOperator: '<S246>/Relational Operator1'
     *  Selector: '<S196>/Selector10'
     *  Selector: '<S196>/Selector7'
     *  Selector: '<S196>/Selector8'
     *  Selector: '<S196>/Selector9'
     *  Selector: '<S246>/Selector'
     *  Selector: '<S246>/Selector1'
     *  Selector: '<S247>/Selector'
     *  Sqrt: '<S249>/Sqrt'
     *  Sum: '<S196>/Subtract'
     *  Sum: '<S246>/Add'
     *  Sum: '<S249>/Subtract'
     *  Sum: '<S249>/Subtract1'
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

    /* End of Switch: '<S249>/Switch' */

    /* Logic: '<S197>/OR' */
    rtb_Compare_pb = (rtb_LogicalOperator5 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S197>/Switch1' incorporates:
     *  Switch: '<S197>/Switch'
     *  UnitDelay: '<S197>/Unit Delay'
     */
    if (rtb_Compare_pb) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S197>/Constant3'
       *  SignalConversion: '<S197>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S197>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S197>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S197>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S196>/Selector6' incorporates:
     *  Concatenate: '<S196>/Matrix Concatenate'
     *  Selector: '<S196>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S196>/Selector2' incorporates:
     *  Concatenate: '<S196>/Matrix Concatenate'
     *  Selector: '<S196>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S197>/Switch2' incorporates:
     *  Sum: '<S253>/Subtract'
     *  Sum: '<S253>/Subtract1'
     *  Trigonometry: '<S253>/Atan2'
     *  UnitDelay: '<S197>/Unit Delay1'
     */
    if (rtb_Compare_pb) {
      rtb_Switch_hs = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Switch_hs = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S197>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S197>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Switch_hs;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S194>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator5;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S194>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S197>/Constant2'
     *  SignalConversion generated from: '<S194>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S197>/Constant5'
     *  SignalConversion generated from: '<S194>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S197>/Constant6'
     *  SignalConversion generated from: '<S194>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S194>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S195>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S194>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S247>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Init_o;

    /* Update for UnitDelay: '<S247>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S197>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S197>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Switch_hs;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S193>/Constant1'
     *  SignalConversion generated from: '<S193>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S193>/Constant'
     *  SignalConversion generated from: '<S193>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S193>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S193>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S193>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S193>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S193>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S193>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S193>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S343>/Sign2' incorporates:
   *  UnitDelay: '<S343>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S343>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S343>/Product1' incorporates:
   *  Signum: '<S343>/Sign1'
   *  Signum: '<S343>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S343>/Switch' incorporates:
   *  Constant: '<S343>/Constant'
   *  Constant: '<S348>/Constant'
   *  Constant: '<S349>/Constant'
   *  Logic: '<S343>/or'
   *  Product: '<S343>/Product1'
   *  RelationalOperator: '<S348>/Compare'
   *  RelationalOperator: '<S349>/Compare'
   *  UnitDelay: '<S343>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S343>/Switch' */

  /* Switch: '<S354>/Init' incorporates:
   *  UnitDelay: '<S354>/FixPt Unit Delay1'
   *  UnitDelay: '<S354>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S354>/Init' */

  /* RelationalOperator: '<S350>/Compare' incorporates:
   *  Constant: '<S350>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S351>/Compare' incorporates:
   *  Constant: '<S351>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Sin4 > 0.0);

  /* Abs: '<S343>/Abs' incorporates:
   *  Sum: '<S343>/Subtract'
   *  UnitDelay: '<S343>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S343>/Switch5' incorporates:
   *  Constant: '<S343>/Constant1'
   *  Switch: '<S343>/Switch1'
   *  UnaryMinus: '<S343>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S343>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S343>/Constant4'
     *  Constant: '<S343>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S343>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S343>/Constant2'
     *  Constant: '<S343>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S343>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S343>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S343>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S343>/Constant10'
     *  Constant: '<S343>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S343>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S343>/Constant7'
     *  Constant: '<S343>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S343>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S343>/Lookup Table Dynamic1'
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

    /* Switch: '<S343>/Switch3' incorporates:
     *  Constant: '<S343>/Constant1'
     *  Constant: '<S343>/Constant3'
     *  UnaryMinus: '<S343>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      rtb_Add_oy = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_oy = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S343>/Switch3' */
  }

  /* End of Switch: '<S343>/Switch5' */

  /* Product: '<S343>/Product' incorporates:
   *  Switch: '<S343>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_oy * rtb_Merge1;

  /* Sum: '<S352>/Sum1' */
  rtb_Saturation_h = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S353>/Switch2' incorporates:
   *  RelationalOperator: '<S353>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S343>/Switch2' incorporates:
     *  Constant: '<S343>/Constant1'
     *  Switch: '<S343>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S343>/Switch4' incorporates:
       *  Constant: '<S343>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S343>/Switch4' incorporates:
       *  Constant: '<S343>/Constant3'
       *  UnaryMinus: '<S343>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S343>/Switch2' */

    /* Product: '<S343>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S353>/Switch' incorporates:
     *  RelationalOperator: '<S353>/UpperRelop'
     */
    if (rtb_Saturation_h < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Saturation_h;
    }

    /* End of Switch: '<S353>/Switch' */
  }

  /* End of Switch: '<S353>/Switch2' */

  /* Sum: '<S352>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S346>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S346>/Switch' incorporates:
     *  Constant: '<S380>/Constant3'
     *  Constant: '<S380>/Constant4'
     *  Math: '<S380>/Math Function'
     *  Sum: '<S346>/Subtract'
     *  Sum: '<S380>/Add1'
     *  Sum: '<S380>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S346>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S346>/Switch' */

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

  /* Sum: '<S133>/Subtract' incorporates:
   *  Constant: '<S133>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Sin4 = Rebuilt_Match_Time_TeleOp - Robot_Control_U.MatchTime;

  /* If: '<S133>/If' incorporates:
   *  Constant: '<S160>/Constant'
   *  Constant: '<S161>/Constant'
   *  Constant: '<S162>/Constant'
   *  Constant: '<S163>/Constant'
   *  Constant: '<S164>/Constant'
   *  Constant: '<S165>/Constant'
   *  Inport: '<Root>/IsBlueAlliance'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S160>/Compare'
   *  RelationalOperator: '<S161>/Compare'
   *  RelationalOperator: '<S162>/Compare'
   *  RelationalOperator: '<S163>/Compare'
   *  RelationalOperator: '<S164>/Compare'
   *  RelationalOperator: '<S165>/Compare'
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
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
       *  ActionPort: '<S166>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S166>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_ms = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
     *  ActionPort: '<S166>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S166>/Constant'
     *  SignalConversion generated from: '<S166>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S133>/Merge1' incorporates:
     *  Constant: '<S166>/Constant'
     *  SignalConversion generated from: '<S166>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S166>/Sum' incorporates:
     *  Constant: '<S166>/Constant1'
     *  UnitDelay: '<S166>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_ms - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S166>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S166>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ms = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S168>/Action Port'
     */
    /* Sum: '<S168>/Sum' incorporates:
     *  Constant: '<S168>/Constant1'
     *  UnitDelay: '<S168>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_m - 0.02;

    /* RelationalOperator: '<S173>/Compare' incorporates:
     *  Constant: '<S173>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Merge1 <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S133>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S168>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S133>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S168>/Logical Operator1'
     *  Logic: '<S168>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S168>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S168>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S168>/Constant2'
       *  Sum: '<S168>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1 -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S133>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;
    }

    /* End of Switch: '<S168>/Switch' */

    /* Update for UnitDelay: '<S168>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    /* Sum: '<S170>/Sum' incorporates:
     *  Constant: '<S170>/Constant1'
     *  UnitDelay: '<S170>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_n - 0.02;

    /* RelationalOperator: '<S175>/Compare' incorporates:
     *  Constant: '<S175>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Merge1 <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S133>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S170>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S133>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S170>/Logical Operator1'
     *  Logic: '<S170>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S170>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S170>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S170>/Constant2'
       *  Sum: '<S170>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1 -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S170>/Constant3'
       *  Sum: '<S170>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1 +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S170>/Switch' */

    /* Update for UnitDelay: '<S170>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S171>/Constant'
     *  SignalConversion generated from: '<S171>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S133>/Merge1' incorporates:
     *  Constant: '<S171>/Constant'
     *  SignalConversion generated from: '<S171>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S171>/Sum' incorporates:
     *  Constant: '<S171>/Constant1'
     *  UnitDelay: '<S171>/Unit Delay'
     */
    rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_ht - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S171>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Merge1;

    /* Update for UnitDelay: '<S171>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ht = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S133>/If' */

  /* If: '<S177>/If' incorporates:
   *  If: '<S178>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S177>/Blue' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    /* Merge: '<S177>/Merge' incorporates:
     *  Constant: '<S179>/BlueAllianceZoneX'
     *  Logic: '<S179>/AND'
     *  RelationalOperator: '<S179>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S177>/Blue' */

    /* Outputs for IfAction SubSystem: '<S178>/Blue' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    /* Merge: '<S178>/Merge' incorporates:
     *  Constant: '<S181>/BlueAllianceZoneX'
     *  RelationalOperator: '<S181>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S178>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S177>/Red' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* Merge: '<S177>/Merge' incorporates:
     *  Constant: '<S180>/RedAllianceZoneX'
     *  Logic: '<S180>/AND'
     *  RelationalOperator: '<S180>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S177>/Red' */

    /* Outputs for IfAction SubSystem: '<S178>/Red' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    /* Merge: '<S178>/Merge' incorporates:
     *  Constant: '<S182>/RedAllianceZoneX'
     *  RelationalOperator: '<S182>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S178>/Red' */
  }

  /* End of If: '<S177>/If' */

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
   *  Constant: '<S176>/Constant3'
   *  Constant: '<S176>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S176>/Math Function'
   *  Sum: '<S136>/Subtract'
   *  Sum: '<S176>/Add1'
   *  Sum: '<S176>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S135>/Max' incorporates:
   *  Abs: '<S135>/Abs1'
   *  Abs: '<S135>/Abs2'
   *  Abs: '<S135>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

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
     *  ActionPort: '<S140>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S142>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S144>/While Iterator'
     */
    /* If: '<S132>/If' incorporates:
     *  Constant: '<S142>/Constant'
     *  Constant: '<S143>/Constant'
     *  Constant: '<S143>/Shooter Assembly Offset in Robot'
     *  Constant: '<S143>/Shooter Assembly Offset in Robot1'
     *  Constant: '<S145>/Constant1'
     *  Constant: '<S145>/Constant10'
     *  Constant: '<S145>/Constant2'
     *  Constant: '<S145>/Constant5'
     *  Constant: '<S145>/Constant6'
     *  Constant: '<S145>/Constant7'
     *  Constant: '<S145>/Constant8'
     *  Constant: '<S145>/Constant9'
     *  Constant: '<S146>/Constant1'
     *  Constant: '<S146>/Constant10'
     *  Constant: '<S146>/Constant2'
     *  Constant: '<S146>/Constant5'
     *  Constant: '<S146>/Constant6'
     *  Constant: '<S146>/Constant7'
     *  Constant: '<S146>/Constant8'
     *  Constant: '<S146>/Constant9'
     *  Constant: '<S147>/Constant'
     *  Constant: '<S147>/Constant1'
     *  Constant: '<S147>/Constant2'
     *  Constant: '<S149>/Constant1'
     *  Constant: '<S149>/Constant10'
     *  Constant: '<S149>/Constant2'
     *  Constant: '<S149>/Constant5'
     *  Constant: '<S149>/Constant6'
     *  Constant: '<S149>/Constant7'
     *  Constant: '<S149>/Constant8'
     *  Constant: '<S149>/Constant9'
     *  Constant: '<S152>/Constant'
     *  Constant: '<S152>/Constant1'
     *  Constant: '<S152>/Constant11'
     *  Constant: '<S152>/Constant2'
     *  Constant: '<S152>/Constant3'
     *  Constant: '<S152>/Constant4'
     *  Constant: '<S152>/Constant5'
     *  Constant: '<S152>/Constant6'
     *  Constant: '<S158>/Constant1'
     *  Constant: '<S158>/Constant10'
     *  Constant: '<S158>/Constant2'
     *  Constant: '<S158>/Constant5'
     *  Constant: '<S158>/Constant6'
     *  Constant: '<S158>/Constant7'
     *  Constant: '<S158>/Constant8'
     *  Constant: '<S158>/Constant9'
     *  Constant: '<S159>/Constant1'
     *  Constant: '<S159>/Constant10'
     *  Constant: '<S159>/Constant2'
     *  Constant: '<S159>/Constant5'
     *  Constant: '<S159>/Constant6'
     *  Constant: '<S159>/Constant7'
     *  Constant: '<S159>/Constant8'
     *  Constant: '<S159>/Constant9'
     *  Gain: '<S150>/Gain1'
     *  Gain: '<S157>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S148>/Logical Operator'
     *  Memory: '<S144>/Memory'
     *  Memory: '<S144>/Memory1'
     *  Memory: '<S144>/Memory2'
     *  Memory: '<S144>/Memory3'
     *  Merge: '<S132>/Merge'
     *  Merge: '<S132>/Merge2'
     *  Merge: '<S132>/Merge3'
     *  MinMax: '<S143>/Max'
     *  Product: '<S143>/Divide'
     *  RelationalOperator: '<S147>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S145>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S146>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S147>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S147>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S145>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S152>/Lookup Table Dynamic'
     *  Sum: '<S143>/Add'
     *  Sum: '<S143>/Subtract'
     *  Sum: '<S143>/Subtract1'
     *  Sum: '<S147>/Add'
     *  Switch: '<S147>/Switch'
     *  Switch: '<S147>/Switch1'
     *  Switch: '<S148>/Switch4'
     *  Switch: '<S148>/Switch5'
     *  Switch: '<S148>/Switch6'
     *  Trigonometry: '<S143>/Tanh'
     *  Trigonometry: '<S143>/Tanh1'
     *  UnitDelay: '<S147>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S142>/Iterate_Shot_Target' */
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

    /* Outputs for Iterator SubSystem: '<S142>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S144>/While Iterator'
     */
    Iteration_Number = 1U;
    rtb_Merge1 = 0.0;
    rtb_Saturation_h = 0.0;
    rtb_Init_o = 0.0;
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
      /* Switch: '<S153>/Switch' incorporates:
       *  Memory: '<S144>/Memory1'
       *  Memory: '<S144>/Memory2'
       *  Switch: '<S153>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_Switch_hs = rtb_Saturation_h;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Switch_hs = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S153>/Switch' */

      /* Math: '<S151>/Hypot' incorporates:
       *  Sum: '<S151>/Subtract'
       *  Sum: '<S151>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_Switch_hs -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S152>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S152>/Lookup Table Dynamic'
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

      /* Sum: '<S154>/Subtract' incorporates:
       *  Memory: '<S144>/Memory3'
       *  Sum: '<S154>/Subtract1'
       */
      rtb_Merge1 = rtb_TOF - rtb_Init_o;

      /* Sum: '<S154>/Add' incorporates:
       *  Gain: '<S154>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S154>/Product'
       *  Sum: '<S154>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S154>/Add1' incorporates:
       *  Gain: '<S154>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S154>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Switch_hs;

      /* Memory: '<S144>/Memory' */
      rtb_LogicalOperator1 = rtb_Compare_ky;

      /* Update for Memory: '<S144>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S144>/Memory2' */
      rtb_Saturation_h = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S144>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S144>/Memory' incorporates:
       *  Constant: '<S156>/Constant'
       *  Math: '<S155>/Hypot'
       *  RelationalOperator: '<S156>/Compare'
       *  Sum: '<S155>/Subtract'
       *  Sum: '<S155>/Subtract1'
       */
      rtb_Compare_ky = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X -
        rtb_Sin4, Robot_Control_B.RB_Desired_Target_Y - rtb_Switch_hs) >=
                        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S142>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S146>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S145>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S147>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S147>/Lookup Table Dynamic1'
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
    rtb_Add_oy = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Minus_k_idx_1 = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S132>/Shooter Not Active' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    /* If: '<S132>/If' incorporates:
     *  Constant: '<S141>/Constant'
     *  Constant: '<S141>/Constant1'
     *  Constant: '<S141>/Constant2'
     *  Constant: '<S141>/Constant3'
     *  Merge: '<S132>/Merge'
     *  Merge: '<S132>/Merge1'
     *  Merge: '<S132>/Merge2'
     *  Merge: '<S132>/Merge3'
     *  SignalConversion generated from: '<S141>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* End of Outputs for SubSystem: '<S132>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_oy = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S375>/Add1' incorporates:
   *  Constant: '<S375>/Constant3'
   *  Constant: '<S375>/Constant4'
   *  Math: '<S375>/Math Function'
   *  Sum: '<S374>/Sum'
   *  Sum: '<S375>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_oy - rtb_Minus_k_idx_1) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Gain: '<S378>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle_p;

  /* Abs: '<S357>/Abs1' */
  rtb_Init_o = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S377>/Sum1' incorporates:
   *  Constant: '<S374>/Constant2'
   *  Product: '<S377>/Product'
   *  Sum: '<S377>/Sum'
   *  UnitDelay: '<S377>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Optimized_Module_Angle_p -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S374>/Product' incorporates:
   *  Constant: '<S374>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S376>/Diff' incorporates:
   *  UnitDelay: '<S376>/UD'
   *
   * Block description for '<S376>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S376>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S374>/Saturation' */
  if (rtb_Add_oy > Steering_Heading_Control_D_UL) {
    rtb_Add_oy = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Heading_Control_D_LL) {
    rtb_Add_oy = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S374>/Add' incorporates:
   *  Gain: '<S374>/Gain1'
   *  Saturate: '<S374>/Saturation'
   */
  rtb_Switch_hs = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_oy;

  /* Sum: '<S374>/Subtract' incorporates:
   *  Constant: '<S374>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Switch_hs;

  /* Sum: '<S374>/Sum2' incorporates:
   *  Gain: '<S374>/Gain2'
   *  UnitDelay: '<S374>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p)
    + Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S379>/Switch2' incorporates:
   *  RelationalOperator: '<S379>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Sin4)) {
    /* Sum: '<S374>/Subtract1' incorporates:
     *  Constant: '<S374>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Switch_hs;

    /* Switch: '<S379>/Switch' incorporates:
     *  RelationalOperator: '<S379>/UpperRelop'
     */
    if (!(rtb_Saturation_h < rtb_Sin4)) {
      rtb_Sin4 = rtb_Saturation_h;
    }

    /* End of Switch: '<S379>/Switch' */
  }

  /* End of Switch: '<S379>/Switch2' */

  /* Saturate: '<S374>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Saturation_h = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Saturation_h = Steering_Heading_Control_I_LL;
  } else {
    rtb_Saturation_h = rtb_Sin4;
  }

  /* End of Saturate: '<S374>/Saturation1' */

  /* Sum: '<S374>/Add1' */
  rtb_Add_oy = rtb_Switch_hs + rtb_Saturation_h;

  /* Saturate: '<S374>/Saturation2' */
  if (rtb_Add_oy > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S374>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_oy < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S374>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S374>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_oy;
  }

  /* End of Saturate: '<S374>/Saturation2' */

  /* Abs: '<S357>/Abs' */
  rtb_Sin4 = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S357>/Add dither' */
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

  /* End of Chart: '<S357>/Add dither' */

  /* Switch: '<S357>/Switch' incorporates:
   *  Constant: '<S357>/Constant'
   *  Constant: '<S373>/Constant'
   *  Product: '<S357>/Product'
   *  RelationalOperator: '<S373>/Compare'
   *  Signum: '<S357>/Sign'
   */
  if (rtb_Sin4 > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S357>/Sign' */
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

  /* End of Switch: '<S357>/Switch' */

  /* Signum: '<S356>/Sign2' incorporates:
   *  UnitDelay: '<S356>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S356>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Optimized_Module_Angle_p > 0.0);
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
   *  Constant: '<S365>/Constant'
   *  Constant: '<S366>/Constant'
   *  Logic: '<S356>/or'
   *  Product: '<S356>/Product1'
   *  RelationalOperator: '<S365>/Compare'
   *  RelationalOperator: '<S366>/Compare'
   *  UnitDelay: '<S356>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_c3 = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_c3 = 0.0;
  }

  /* End of Switch: '<S356>/Switch' */

  /* Switch: '<S371>/Init' incorporates:
   *  UnitDelay: '<S371>/FixPt Unit Delay1'
   *  UnitDelay: '<S371>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Switch2_c3;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S371>/Init' */

  /* RelationalOperator: '<S367>/Compare' incorporates:
   *  Constant: '<S367>/Constant'
   */
  rtb_Compare_ky = (rtb_Switch2_c3 == 0.0);

  /* RelationalOperator: '<S368>/Compare' incorporates:
   *  Constant: '<S368>/Constant'
   */
  rtb_Compare_mq = (rtb_Switch2_c3 > 0.0);

  /* Abs: '<S356>/Abs' incorporates:
   *  Sum: '<S356>/Subtract'
   *  UnitDelay: '<S356>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S356>/Switch5' incorporates:
   *  Constant: '<S356>/Constant1'
   *  Switch: '<S356>/Switch1'
   *  UnaryMinus: '<S356>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    /* SignalConversion generated from: '<S356>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S356>/Constant4'
     *  Constant: '<S356>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S356>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S356>/Constant2'
     *  Constant: '<S356>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S356>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S356>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S356>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S356>/Constant10'
     *  Constant: '<S356>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S356>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S356>/Constant7'
     *  Constant: '<S356>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S356>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S356>/Lookup Table Dynamic1'
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

    /* Switch: '<S356>/Switch3' incorporates:
     *  Constant: '<S356>/Constant1'
     *  Constant: '<S356>/Constant3'
     *  UnaryMinus: '<S356>/Unary Minus'
     */
    if (rtb_Compare_mq) {
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S356>/Switch3' */
  }

  /* End of Switch: '<S356>/Switch5' */

  /* Product: '<S356>/Product' incorporates:
   *  Switch: '<S356>/Switch1'
   */
  rtb_Switch2_p2 = rtb_Add_oy * rtb_Sin4;

  /* Sum: '<S369>/Sum1' */
  rtb_Switch_hs = rtb_Switch2_c3 - rtb_Init_o;

  /* Switch: '<S370>/Switch2' incorporates:
   *  RelationalOperator: '<S370>/LowerRelop1'
   */
  if (!(rtb_Switch_hs > rtb_Switch2_p2)) {
    /* Switch: '<S356>/Switch2' incorporates:
     *  Constant: '<S356>/Constant1'
     *  Constant: '<S356>/Constant3'
     *  Switch: '<S356>/Switch4'
     *  UnaryMinus: '<S356>/Unary Minus1'
     */
    if (rtb_Compare_ky) {
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Compare_mq) {
      /* Switch: '<S356>/Switch4' incorporates:
       *  Constant: '<S356>/Constant1'
       */
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S356>/Product2' incorporates:
     *  Switch: '<S356>/Switch2'
     */
    rtb_Switch1_n = rtb_Add_oy * rtb_Sin4;

    /* Switch: '<S370>/Switch' incorporates:
     *  RelationalOperator: '<S370>/UpperRelop'
     */
    if (rtb_Switch_hs < rtb_Switch1_n) {
      rtb_Switch2_p2 = rtb_Switch1_n;
    } else {
      rtb_Switch2_p2 = rtb_Switch_hs;
    }

    /* End of Switch: '<S370>/Switch' */
  }

  /* End of Switch: '<S370>/Switch2' */

  /* Sum: '<S369>/Sum' */
  rtb_Init_o += rtb_Switch2_p2;

  /* Signum: '<S355>/Sign2' incorporates:
   *  UnitDelay: '<S355>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S355>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S355>/Product1' incorporates:
   *  Signum: '<S355>/Sign1'
   *  Signum: '<S355>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S355>/Switch' incorporates:
   *  Constant: '<S355>/Constant'
   *  Constant: '<S358>/Constant'
   *  Constant: '<S359>/Constant'
   *  Logic: '<S355>/or'
   *  Product: '<S355>/Product1'
   *  RelationalOperator: '<S358>/Compare'
   *  RelationalOperator: '<S359>/Compare'
   *  UnitDelay: '<S355>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_c3 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_c3 = 0.0;
  }

  /* End of Switch: '<S355>/Switch' */

  /* Switch: '<S364>/Init' incorporates:
   *  UnitDelay: '<S364>/FixPt Unit Delay1'
   *  UnitDelay: '<S364>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_c3;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S364>/Init' */

  /* RelationalOperator: '<S360>/Compare' incorporates:
   *  Constant: '<S360>/Constant'
   */
  rtb_Compare_ky = (rtb_Switch2_c3 == 0.0);

  /* RelationalOperator: '<S361>/Compare' incorporates:
   *  Constant: '<S361>/Constant'
   */
  rtb_Compare_mq = (rtb_Switch2_c3 > 0.0);

  /* Abs: '<S355>/Abs' incorporates:
   *  Sum: '<S355>/Subtract'
   *  UnitDelay: '<S355>/Unit Delay'
   */
  rtb_Switch_hs = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                       Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S355>/Switch1' incorporates:
   *  Constant: '<S355>/Constant1'
   *  Switch: '<S355>/Switch3'
   *  Switch: '<S355>/Switch5'
   *  UnaryMinus: '<S355>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S355>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S355>/Constant1'
     *  Constant: '<S355>/Constant4'
     *  Constant: '<S355>/Constant6'
     *  UnaryMinus: '<S355>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S355>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S355>/Constant2'
     *  Constant: '<S355>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S355>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S355>/Lookup Table Dynamic'
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
    if (rtb_Compare_mq) {
      /* Switch: '<S355>/Switch3' incorporates:
       *  Constant: '<S355>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S355>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S355>/Constant1'
     *  Constant: '<S355>/Constant10'
     *  Constant: '<S355>/Constant8'
     *  UnaryMinus: '<S355>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S355>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S355>/Constant7'
     *  Constant: '<S355>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S355>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S355>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S355>/Switch1' */

  /* Product: '<S355>/Product' */
  rtb_Sin4 *= rtb_Switch_hs;

  /* Sum: '<S362>/Sum1' */
  rtb_Switch1_n = rtb_Switch2_c3 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S363>/Switch2' incorporates:
   *  RelationalOperator: '<S363>/LowerRelop1'
   */
  if (!(rtb_Switch1_n > rtb_Sin4)) {
    /* Switch: '<S355>/Switch2' incorporates:
     *  Constant: '<S355>/Constant1'
     *  Switch: '<S355>/Switch4'
     */
    if (rtb_Compare_ky) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Compare_mq) {
      /* Switch: '<S355>/Switch4' incorporates:
       *  Constant: '<S355>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S355>/Switch4' incorporates:
       *  Constant: '<S355>/Constant3'
       *  UnaryMinus: '<S355>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S355>/Switch2' */

    /* Product: '<S355>/Product2' */
    rtb_Sin4 *= rtb_Switch_hs;

    /* Switch: '<S363>/Switch' incorporates:
     *  RelationalOperator: '<S363>/UpperRelop'
     */
    if (!(rtb_Switch1_n < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1_n;
    }

    /* End of Switch: '<S363>/Switch' */
  }

  /* End of Switch: '<S363>/Switch2' */

  /* Sum: '<S362>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S345>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S345>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S345>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S345>/Switch' */

  /* Fcn: '<S388>/r->x' incorporates:
   *  Fcn: '<S393>/r->x'
   *  Fcn: '<S398>/r->x'
   *  Fcn: '<S403>/r->x'
   */
  rtb_Switch1_n = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S382>/Add' incorporates:
   *  Fcn: '<S388>/r->x'
   *  Fcn: '<S389>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1_n;

  /* Fcn: '<S388>/theta->y' incorporates:
   *  Fcn: '<S393>/theta->y'
   *  Fcn: '<S398>/theta->y'
   *  Fcn: '<S403>/theta->y'
   */
  rtb_Switch_hs = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S382>/Add' incorporates:
   *  Fcn: '<S388>/theta->y'
   *  Fcn: '<S389>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch_hs;

  /* Sum: '<S383>/Add' incorporates:
   *  Fcn: '<S394>/r->x'
   *  Fcn: '<S394>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1_n;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch_hs;

  /* Sum: '<S384>/Add' incorporates:
   *  Fcn: '<S399>/r->x'
   *  Fcn: '<S399>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1_n;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch_hs;

  /* Sum: '<S385>/Add' incorporates:
   *  Fcn: '<S404>/r->x'
   *  Fcn: '<S404>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1_n;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch_hs;

  /* Fcn: '<S402>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S405>/Compare' incorporates:
   *  Constant: '<S405>/Constant'
   */
  rtb_Compare_pb = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S401>/Switch1' */
  if (rtb_Compare_pb) {
    /* Switch: '<S401>/Switch1' incorporates:
     *  Constant: '<S401>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S401>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S401>/Switch1' */

  /* Fcn: '<S387>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S390>/Compare' incorporates:
   *  Constant: '<S390>/Constant'
   */
  rtb_Compare_mq = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S386>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S386>/Switch1' incorporates:
     *  Constant: '<S386>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S386>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S386>/Switch1' */

  /* Fcn: '<S392>/x->r' */
  rtb_Switch2_c3 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S395>/Compare' incorporates:
   *  Constant: '<S395>/Constant'
   */
  rtb_Compare_ky = (rtb_Switch2_c3 == 0.0);

  /* Switch: '<S391>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S391>/Switch1' incorporates:
     *  Constant: '<S391>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S391>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_c3;
  }

  /* End of Switch: '<S391>/Switch1' */

  /* Fcn: '<S397>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S400>/Compare' incorporates:
   *  Constant: '<S400>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S396>/Switch1' */
  if (rtb_LogicalOperator1) {
    /* Switch: '<S396>/Switch1' incorporates:
     *  Constant: '<S396>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S396>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S396>/Switch1' */

  /* Product: '<S381>/Divide' incorporates:
   *  Abs: '<S381>/Abs'
   *  Abs: '<S381>/Abs1'
   *  Abs: '<S381>/Abs2'
   *  Abs: '<S381>/Abs3'
   *  Constant: '<S381>/Constant'
   *  MinMax: '<S381>/Max'
   */
  rtb_Switch2_p2 = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S381>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S401>/Switch' */
  if (!rtb_Compare_pb) {
    /* Switch: '<S401>/Switch' incorporates:
     *  Fcn: '<S402>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S401>/Switch' */

  /* Trigonometry: '<S335>/Cos4' incorporates:
   *  Switch: '<S324>/Angle_Switch'
   *  Trigonometry: '<S334>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S335>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S333>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S335>/Sin4' incorporates:
   *  Switch: '<S324>/Angle_Switch'
   *  Trigonometry: '<S334>/Sin4'
   */
  rtb_Switch_hs = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S335>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S333>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S335>/Subtract1' incorporates:
   *  Product: '<S335>/Product2'
   *  Product: '<S335>/Product3'
   *  Trigonometry: '<S335>/Cos4'
   *  Trigonometry: '<S335>/Sin4'
   */
  rtb_Switch1_n = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) +
    (rtb_Switch_hs * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S335>/Subtract' incorporates:
   *  Product: '<S335>/Product'
   *  Product: '<S335>/Product1'
   *  Trigonometry: '<S335>/Cos4'
   *  Trigonometry: '<S335>/Sin4'
   */
  rtb_Init = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) - (rtb_Switch_hs
    * rtb_Optimized_Module_Angle);

  /* Math: '<S335>/Hypot' */
  rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Init, rtb_Switch1_n);

  /* Switch: '<S335>/Switch' incorporates:
   *  Constant: '<S335>/Constant'
   *  Constant: '<S335>/Constant1'
   *  Constant: '<S336>/Constant'
   *  Product: '<S335>/Divide'
   *  Product: '<S335>/Divide1'
   *  RelationalOperator: '<S336>/Compare'
   *  Switch: '<S335>/Switch1'
   */
  if (rtb_Minus_k_idx_0 > 1.0E-6) {
    rtb_Switch2_c3 = rtb_Switch1_n / rtb_Minus_k_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Minus_k_idx_0;
  } else {
    rtb_Switch2_c3 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S335>/Switch' */

  /* Switch: '<S324>/Speed_Switch' incorporates:
   *  Abs: '<S324>/Abs'
   *  Constant: '<S332>/Constant'
   *  RelationalOperator: '<S332>/Compare'
   *  Switch: '<S324>/Angle_Switch'
   *  Trigonometry: '<S334>/Atan1'
   *  Trigonometry: '<S335>/Atan1'
   *  UnaryMinus: '<S324>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_c3, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S334>/Subtract1' incorporates:
     *  Product: '<S334>/Product2'
     *  Product: '<S334>/Product3'
     *  UnaryMinus: '<S324>/Unary Minus'
     */
    rtb_Switch1_n = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_Switch_hs * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S334>/Subtract' incorporates:
     *  Product: '<S334>/Product'
     *  Product: '<S334>/Product1'
     */
    rtb_Init = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_Switch_hs * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S334>/Hypot' */
    rtb_Switch_hs = rt_hypotd_snf(rtb_Init, rtb_Switch1_n);

    /* Switch: '<S334>/Switch1' incorporates:
     *  Constant: '<S334>/Constant'
     *  Constant: '<S334>/Constant1'
     *  Constant: '<S337>/Constant'
     *  Product: '<S334>/Divide'
     *  Product: '<S334>/Divide1'
     *  RelationalOperator: '<S337>/Compare'
     *  Switch: '<S334>/Switch'
     */
    if (rtb_Switch_hs > 1.0E-6) {
      rtb_Init /= rtb_Switch_hs;
      rtb_Switch_hs = rtb_Switch1_n / rtb_Switch_hs;
    } else {
      rtb_Init = 1.0;
      rtb_Switch_hs = 0.0;
    }

    /* End of Switch: '<S334>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch_hs, rtb_Init);
  } else {
    rtb_Add_oy = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S327>/Product2' incorporates:
   *  Constant: '<S327>/Constant'
   *  Switch: '<S324>/Speed_Switch'
   */
  rtb_Switch2_c3 = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S322>/Sign' */
  if (rtIsNaN(rtb_Switch2_c3)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_c3 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_c3 > 0.0);
  }

  /* Signum: '<S322>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S325>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S326>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S257>/Product' incorporates:
   *  Abs: '<S322>/Abs'
   *  Abs: '<S325>/Abs'
   *  Constant: '<S328>/Constant'
   *  Constant: '<S338>/Constant3'
   *  Constant: '<S338>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S322>/OR'
   *  Lookup_n-D: '<S325>/1-D Lookup Table'
   *  Math: '<S338>/Math Function'
   *  RelationalOperator: '<S322>/Equal1'
   *  RelationalOperator: '<S328>/Compare'
   *  Signum: '<S322>/Sign'
   *  Signum: '<S322>/Sign1'
   *  Sum: '<S325>/Add'
   *  Sum: '<S338>/Add1'
   *  Sum: '<S338>/Add2'
   */
  rtb_Switch2_c3 = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_c3) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S323>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Init = rtb_Switch2_c3 - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S330>/Sum1' incorporates:
   *  Constant: '<S323>/Constant2'
   *  Product: '<S330>/Product'
   *  Sum: '<S330>/Sum'
   *  UnitDelay: '<S330>/Unit Delay1'
   */
  rtb_Switch_hs = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                   Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S323>/Product' incorporates:
   *  Constant: '<S323>/Constant3'
   */
  rtb_Switch1_n = rtb_Switch_hs * Drive_Motor_Control_D;

  /* Sum: '<S329>/Diff' incorporates:
   *  UnitDelay: '<S329>/UD'
   *
   * Block description for '<S329>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S329>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch1_n - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S323>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S323>/Add' incorporates:
   *  Gain: '<S323>/Gain'
   *  Gain: '<S323>/Gain1'
   *  Saturate: '<S323>/Saturation'
   */
  rtb_Minus_k_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_c3) +
                       (Drive_Motor_Control_P * rtb_Init)) + rtb_Add_oy;

  /* Saturate: '<S323>/Saturation2' incorporates:
   *  Sum: '<S323>/Add1'
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

  /* End of Saturate: '<S323>/Saturation2' */

  /* Switch: '<S386>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S386>/Switch' incorporates:
     *  Fcn: '<S387>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S386>/Switch' */

  /* Trigonometry: '<S272>/Cos4' incorporates:
   *  Switch: '<S261>/Angle_Switch'
   *  Trigonometry: '<S271>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S272>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S270>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S272>/Sin4' incorporates:
   *  Switch: '<S261>/Angle_Switch'
   *  Trigonometry: '<S271>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S272>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S270>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S272>/Subtract1' incorporates:
   *  Product: '<S272>/Product2'
   *  Product: '<S272>/Product3'
   *  Trigonometry: '<S272>/Cos4'
   *  Trigonometry: '<S272>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S272>/Subtract' incorporates:
   *  Product: '<S272>/Product'
   *  Product: '<S272>/Product1'
   *  Trigonometry: '<S272>/Cos4'
   *  Trigonometry: '<S272>/Sin4'
   */
  rtb_Init = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S272>/Hypot' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Init, rtb_Minus_k_idx_0);

  /* Switch: '<S272>/Switch' incorporates:
   *  Constant: '<S272>/Constant'
   *  Constant: '<S272>/Constant1'
   *  Constant: '<S273>/Constant'
   *  Product: '<S272>/Divide'
   *  Product: '<S272>/Divide1'
   *  RelationalOperator: '<S273>/Compare'
   *  Switch: '<S272>/Switch1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
    rtb_Switch2_c3 = rtb_Minus_k_idx_0 / rtb_MatrixConcatenate_b_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Switch2_c3 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S272>/Switch' */

  /* Product: '<S381>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S261>/Speed_Switch' incorporates:
   *  Abs: '<S261>/Abs'
   *  Constant: '<S269>/Constant'
   *  RelationalOperator: '<S269>/Compare'
   *  Switch: '<S261>/Angle_Switch'
   *  Trigonometry: '<S271>/Atan1'
   *  Trigonometry: '<S272>/Atan1'
   *  UnaryMinus: '<S261>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_c3, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S271>/Subtract1' incorporates:
     *  Product: '<S271>/Product2'
     *  Product: '<S271>/Product3'
     *  UnaryMinus: '<S261>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S271>/Subtract' incorporates:
     *  Product: '<S271>/Product'
     *  Product: '<S271>/Product1'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Cos5) - (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Sin5);

    /* Math: '<S271>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Minus_k_idx_0);

    /* Switch: '<S271>/Switch1' incorporates:
     *  Constant: '<S271>/Constant'
     *  Constant: '<S271>/Constant1'
     *  Constant: '<S274>/Constant'
     *  Product: '<S271>/Divide'
     *  Product: '<S271>/Divide1'
     *  RelationalOperator: '<S274>/Compare'
     *  Switch: '<S271>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Init;
      rtb_Minus_k_idx_0 /= rtb_Init;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S271>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_0,
      rtb_MatrixConcatenate_b_idx_0);
  } else {
    rtb_Add_oy = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S264>/Product2' incorporates:
   *  Constant: '<S264>/Constant'
   *  Switch: '<S261>/Speed_Switch'
   */
  rtb_Switch2_c3 = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S259>/Sign' */
  if (rtIsNaN(rtb_Switch2_c3)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_c3 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_c3 > 0.0);
  }

  /* Signum: '<S259>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S262>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S263>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S254>/Product' incorporates:
   *  Abs: '<S259>/Abs'
   *  Abs: '<S262>/Abs'
   *  Constant: '<S265>/Constant'
   *  Constant: '<S275>/Constant3'
   *  Constant: '<S275>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S259>/OR'
   *  Lookup_n-D: '<S262>/1-D Lookup Table'
   *  Math: '<S275>/Math Function'
   *  RelationalOperator: '<S259>/Equal1'
   *  RelationalOperator: '<S265>/Compare'
   *  Signum: '<S259>/Sign'
   *  Signum: '<S259>/Sign1'
   *  Sum: '<S262>/Add'
   *  Sum: '<S275>/Add1'
   *  Sum: '<S275>/Add2'
   */
  rtb_Switch2_c3 = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_c3) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j,
                  1U);

  /* Sum: '<S260>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_c3 -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S267>/Sum1' incorporates:
   *  Constant: '<S260>/Constant2'
   *  Product: '<S267>/Product'
   *  Sum: '<S267>/Sum'
   *  UnitDelay: '<S267>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_MatrixConcatenate_b_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_f) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S260>/Product' incorporates:
   *  Constant: '<S260>/Constant3'
   */
  rtb_Init = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S266>/Diff' incorporates:
   *  UnitDelay: '<S266>/UD'
   *
   * Block description for '<S266>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S266>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Init - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S260>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S260>/Add' incorporates:
   *  Gain: '<S260>/Gain'
   *  Gain: '<S260>/Gain1'
   *  Saturate: '<S260>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_c3) +
    (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_oy;

  /* Saturate: '<S260>/Saturation2' incorporates:
   *  Sum: '<S260>/Add1'
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

  /* End of Saturate: '<S260>/Saturation2' */

  /* Sum: '<S276>/Add1' incorporates:
   *  Constant: '<S276>/Constant3'
   *  Constant: '<S276>/Constant4'
   *  Math: '<S276>/Math Function'
   *  Sum: '<S276>/Add2'
   */
  rtb_Switch2_c3 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S278>/Sum1' incorporates:
   *  Constant: '<S263>/Constant2'
   *  Product: '<S278>/Product'
   *  Sum: '<S278>/Sum'
   *  UnitDelay: '<S278>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((rtb_Switch2_c3 -
    Robot_Control_DW.UnitDelay1_DSTATE_b) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S263>/Product' incorporates:
   *  Constant: '<S263>/Constant3'
   */
  rtb_Switch2_bq = rtb_MatrixConcatenate_b_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S277>/Diff' incorporates:
   *  UnitDelay: '<S277>/UD'
   *
   * Block description for '<S277>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S277>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch2_bq - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S263>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S263>/Add' incorporates:
   *  Gain: '<S263>/Gain1'
   *  Saturate: '<S263>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P * rtb_Switch2_c3) +
    rtb_Add_oy;

  /* Sum: '<S263>/Subtract' incorporates:
   *  Constant: '<S263>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S263>/Sum2' incorporates:
   *  Gain: '<S263>/Gain2'
   *  UnitDelay: '<S263>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Switch2_c3) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S279>/Switch2' incorporates:
   *  Constant: '<S263>/Constant'
   *  RelationalOperator: '<S279>/LowerRelop1'
   *  Sum: '<S263>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S279>/Switch' incorporates:
     *  Constant: '<S263>/Constant1'
     *  RelationalOperator: '<S279>/UpperRelop'
     *  Sum: '<S263>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S279>/Switch' */
  }

  /* End of Switch: '<S279>/Switch2' */

  /* Saturate: '<S263>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S263>/Saturation1' */

  /* Sum: '<S263>/Add1' */
  rtb_Add_oy = rtb_MatrixConcatenate_idx_0 + rtb_Sum2_e;

  /* Saturate: '<S263>/Saturation2' */
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

  /* End of Saturate: '<S263>/Saturation2' */

  /* Switch: '<S391>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S391>/Switch' incorporates:
     *  Fcn: '<S392>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S391>/Switch' */

  /* Trigonometry: '<S293>/Cos4' incorporates:
   *  Switch: '<S282>/Angle_Switch'
   *  Trigonometry: '<S292>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S293>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S291>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S293>/Sin4' incorporates:
   *  Switch: '<S282>/Angle_Switch'
   *  Trigonometry: '<S292>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S293>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S291>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S293>/Subtract1' incorporates:
   *  Product: '<S293>/Product2'
   *  Product: '<S293>/Product3'
   *  Trigonometry: '<S293>/Cos4'
   *  Trigonometry: '<S293>/Sin4'
   */
  rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S293>/Subtract' incorporates:
   *  Product: '<S293>/Product'
   *  Product: '<S293>/Product1'
   *  Trigonometry: '<S293>/Cos4'
   *  Trigonometry: '<S293>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S293>/Hypot' */
  rtb_Hypot_bl = rt_hypotd_snf(rtb_Subtract1_la, rtb_MatrixConcatenate_idx_0);

  /* Switch: '<S293>/Switch' incorporates:
   *  Constant: '<S293>/Constant'
   *  Constant: '<S293>/Constant1'
   *  Constant: '<S294>/Constant'
   *  Product: '<S293>/Divide'
   *  Product: '<S293>/Divide1'
   *  RelationalOperator: '<S294>/Compare'
   *  Switch: '<S293>/Switch1'
   */
  if (rtb_Hypot_bl > 1.0E-6) {
    rtb_Switch2_c3 = rtb_MatrixConcatenate_idx_0 / rtb_Hypot_bl;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_bl;
  } else {
    rtb_Switch2_c3 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S293>/Switch' */

  /* Product: '<S381>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S282>/Speed_Switch' incorporates:
   *  Abs: '<S282>/Abs'
   *  Constant: '<S290>/Constant'
   *  RelationalOperator: '<S290>/Compare'
   *  Switch: '<S282>/Angle_Switch'
   *  Trigonometry: '<S292>/Atan1'
   *  Trigonometry: '<S293>/Atan1'
   *  UnaryMinus: '<S282>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_c3, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S292>/Subtract1' incorporates:
     *  Product: '<S292>/Product2'
     *  Product: '<S292>/Product3'
     *  UnaryMinus: '<S282>/Unary Minus'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_m) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S292>/Subtract' incorporates:
     *  Product: '<S292>/Product'
     *  Product: '<S292>/Product1'
     */
    rtb_Hypot_bl = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S292>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_bl, rtb_MatrixConcatenate_idx_0);

    /* Switch: '<S292>/Switch1' incorporates:
     *  Constant: '<S292>/Constant'
     *  Constant: '<S292>/Constant1'
     *  Constant: '<S295>/Constant'
     *  Product: '<S292>/Divide'
     *  Product: '<S292>/Divide1'
     *  RelationalOperator: '<S295>/Compare'
     *  Switch: '<S292>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_bl /= rtb_Subtract1_la;
      rtb_MatrixConcatenate_idx_0 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_bl = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S292>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0, rtb_Hypot_bl);
  } else {
    rtb_Add_oy = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S285>/Product2' incorporates:
   *  Constant: '<S285>/Constant'
   *  Switch: '<S282>/Speed_Switch'
   */
  rtb_Switch2_c3 = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S280>/Sign' */
  if (rtIsNaN(rtb_Switch2_c3)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_c3 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_c3 > 0.0);
  }

  /* Signum: '<S280>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S283>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S284>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S255>/Product' incorporates:
   *  Abs: '<S280>/Abs'
   *  Abs: '<S283>/Abs'
   *  Constant: '<S286>/Constant'
   *  Constant: '<S296>/Constant3'
   *  Constant: '<S296>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S280>/OR'
   *  Lookup_n-D: '<S283>/1-D Lookup Table'
   *  Math: '<S296>/Math Function'
   *  RelationalOperator: '<S280>/Equal1'
   *  RelationalOperator: '<S286>/Compare'
   *  Signum: '<S280>/Sign'
   *  Signum: '<S280>/Sign1'
   *  Sum: '<S283>/Add'
   *  Sum: '<S296>/Add1'
   *  Sum: '<S296>/Add2'
   */
  rtb_Switch2_c3 = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_c3) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_gs,
                  1U);

  /* Sum: '<S281>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_bl = rtb_Switch2_c3 - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S288>/Sum1' incorporates:
   *  Constant: '<S281>/Constant2'
   *  Product: '<S288>/Product'
   *  Sum: '<S288>/Sum'
   *  UnitDelay: '<S288>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Hypot_bl -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S281>/Product' incorporates:
   *  Constant: '<S281>/Constant3'
   */
  rtb_Subtract1_la = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S287>/Diff' incorporates:
   *  UnitDelay: '<S287>/UD'
   *
   * Block description for '<S287>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S287>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S281>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S281>/Add' incorporates:
   *  Gain: '<S281>/Gain'
   *  Gain: '<S281>/Gain1'
   *  Saturate: '<S281>/Saturation'
   */
  rtb_Hypot_bl = ((Drive_Motor_Control_FF * rtb_Switch2_c3) +
                  (Drive_Motor_Control_P * rtb_Hypot_bl)) + rtb_Add_oy;

  /* Saturate: '<S281>/Saturation2' incorporates:
   *  Sum: '<S281>/Add1'
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

  /* End of Saturate: '<S281>/Saturation2' */

  /* Sum: '<S297>/Add1' incorporates:
   *  Constant: '<S297>/Constant3'
   *  Constant: '<S297>/Constant4'
   *  Math: '<S297>/Math Function'
   *  Sum: '<S297>/Add2'
   */
  rtb_Switch2_c3 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S299>/Sum1' incorporates:
   *  Constant: '<S284>/Constant2'
   *  Product: '<S299>/Product'
   *  Sum: '<S299>/Sum'
   *  UnitDelay: '<S299>/Unit Delay1'
   */
  rtb_Hypot_bl = ((rtb_Switch2_c3 - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S284>/Product' incorporates:
   *  Constant: '<S284>/Constant3'
   */
  rtb_Switch2_fl = rtb_Hypot_bl * Steering_Motor_Control_D;

  /* Sum: '<S298>/Diff' incorporates:
   *  UnitDelay: '<S298>/UD'
   *
   * Block description for '<S298>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S298>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch2_fl - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S284>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S284>/Add' incorporates:
   *  Gain: '<S284>/Gain1'
   *  Saturate: '<S284>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_c3) + rtb_Add_oy;

  /* Sum: '<S284>/Subtract' incorporates:
   *  Constant: '<S284>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S284>/Sum2' incorporates:
   *  Gain: '<S284>/Gain2'
   *  UnitDelay: '<S284>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_Switch2_c3) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S300>/Switch2' incorporates:
   *  Constant: '<S284>/Constant'
   *  RelationalOperator: '<S300>/LowerRelop1'
   *  Sum: '<S284>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S300>/Switch' incorporates:
     *  Constant: '<S284>/Constant1'
     *  RelationalOperator: '<S300>/UpperRelop'
     *  Sum: '<S284>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S300>/Switch' */
  }

  /* End of Switch: '<S300>/Switch2' */

  /* Saturate: '<S284>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S284>/Saturation1' */

  /* Sum: '<S284>/Add1' */
  rtb_Add_oy = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S284>/Saturation2' */
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

  /* End of Saturate: '<S284>/Saturation2' */

  /* Switch: '<S396>/Switch' */
  if (!rtb_LogicalOperator1) {
    /* Switch: '<S396>/Switch' incorporates:
     *  Fcn: '<S397>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S396>/Switch' */

  /* Trigonometry: '<S314>/Cos4' incorporates:
   *  Switch: '<S303>/Angle_Switch'
   *  Trigonometry: '<S313>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S314>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S312>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S314>/Sin4' incorporates:
   *  Switch: '<S303>/Angle_Switch'
   *  Trigonometry: '<S313>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S314>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S312>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S314>/Subtract1' incorporates:
   *  Product: '<S314>/Product2'
   *  Product: '<S314>/Product3'
   *  Trigonometry: '<S314>/Cos4'
   *  Trigonometry: '<S314>/Sin4'
   */
  rtb_Switch2_c3 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S314>/Subtract' incorporates:
   *  Product: '<S314>/Product'
   *  Product: '<S314>/Product1'
   *  Trigonometry: '<S314>/Cos4'
   *  Trigonometry: '<S314>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S314>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_c3);

  /* Switch: '<S314>/Switch' incorporates:
   *  Constant: '<S314>/Constant'
   *  Constant: '<S314>/Constant1'
   *  Constant: '<S315>/Constant'
   *  Product: '<S314>/Divide'
   *  Product: '<S314>/Divide1'
   *  RelationalOperator: '<S315>/Compare'
   *  Switch: '<S314>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Switch2_c3 /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_c3 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S314>/Switch' */

  /* Product: '<S381>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S303>/Speed_Switch' incorporates:
   *  Abs: '<S303>/Abs'
   *  Constant: '<S311>/Constant'
   *  RelationalOperator: '<S311>/Compare'
   *  Switch: '<S303>/Angle_Switch'
   *  Trigonometry: '<S313>/Atan1'
   *  Trigonometry: '<S314>/Atan1'
   *  UnaryMinus: '<S303>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_c3, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S313>/Subtract1' incorporates:
     *  Product: '<S313>/Product2'
     *  Product: '<S313>/Product3'
     *  UnaryMinus: '<S303>/Unary Minus'
     */
    rtb_Switch2_c3 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S313>/Subtract' incorporates:
     *  Product: '<S313>/Product'
     *  Product: '<S313>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S313>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_c3);

    /* Switch: '<S313>/Switch1' incorporates:
     *  Constant: '<S313>/Constant'
     *  Constant: '<S313>/Constant1'
     *  Constant: '<S316>/Constant'
     *  Product: '<S313>/Divide'
     *  Product: '<S313>/Divide1'
     *  RelationalOperator: '<S316>/Compare'
     *  Switch: '<S313>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_Switch2_c3 /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Switch2_c3 = 0.0;
    }

    /* End of Switch: '<S313>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Switch2_c3,
      rtb_uDLookupTable);
  } else {
    rtb_Add_oy = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S306>/Product2' incorporates:
   *  Constant: '<S306>/Constant'
   *  Switch: '<S303>/Speed_Switch'
   */
  rtb_Switch2_p2 = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S301>/Sign' */
  if (rtIsNaN(rtb_Switch2_p2)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_p2 < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_p2 > 0.0);
  }

  /* Signum: '<S301>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S304>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S305>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S256>/Product' incorporates:
   *  Abs: '<S301>/Abs'
   *  Abs: '<S304>/Abs'
   *  Constant: '<S307>/Constant'
   *  Constant: '<S317>/Constant3'
   *  Constant: '<S317>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S301>/OR'
   *  Lookup_n-D: '<S304>/1-D Lookup Table'
   *  Math: '<S317>/Math Function'
   *  RelationalOperator: '<S301>/Equal1'
   *  RelationalOperator: '<S307>/Compare'
   *  Signum: '<S301>/Sign'
   *  Signum: '<S301>/Sign1'
   *  Sum: '<S304>/Add'
   *  Sum: '<S317>/Add1'
   *  Sum: '<S317>/Add2'
   */
  rtb_Switch2_p2 = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p2) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Sum: '<S302>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_c3 = rtb_Switch2_p2 - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S309>/Sum1' incorporates:
   *  Constant: '<S302>/Constant2'
   *  Product: '<S309>/Product'
   *  Sum: '<S309>/Sum'
   *  UnitDelay: '<S309>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_Switch2_c3 - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S302>/Product' incorporates:
   *  Constant: '<S302>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S308>/Diff' incorporates:
   *  UnitDelay: '<S308>/UD'
   *
   * Block description for '<S308>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S308>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S302>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S302>/Add' incorporates:
   *  Gain: '<S302>/Gain'
   *  Gain: '<S302>/Gain1'
   *  Saturate: '<S302>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_p2) +
                    (Drive_Motor_Control_P * rtb_Switch2_c3)) + rtb_Add_oy;

  /* Saturate: '<S302>/Saturation2' incorporates:
   *  Sum: '<S302>/Add1'
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

  /* End of Saturate: '<S302>/Saturation2' */

  /* Sum: '<S318>/Add1' incorporates:
   *  Constant: '<S318>/Constant3'
   *  Constant: '<S318>/Constant4'
   *  Math: '<S318>/Math Function'
   *  Sum: '<S318>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S320>/Sum1' incorporates:
   *  Constant: '<S305>/Constant2'
   *  Product: '<S320>/Product'
   *  Sum: '<S320>/Sum'
   *  UnitDelay: '<S320>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S305>/Product' incorporates:
   *  Constant: '<S305>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S319>/Diff' incorporates:
   *  UnitDelay: '<S319>/UD'
   *
   * Block description for '<S319>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S319>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S305>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S305>/Add' incorporates:
   *  Gain: '<S305>/Gain1'
   *  Saturate: '<S305>/Saturation'
   */
  rtb_Add_ec = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_oy;

  /* Sum: '<S305>/Subtract' incorporates:
   *  Constant: '<S305>/Constant'
   */
  rtb_Switch2_c3 = 1.0 - rtb_Add_ec;

  /* Sum: '<S305>/Sum2' incorporates:
   *  Gain: '<S305>/Gain2'
   *  UnitDelay: '<S305>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S321>/Switch2' incorporates:
   *  Constant: '<S305>/Constant'
   *  RelationalOperator: '<S321>/LowerRelop1'
   *  Sum: '<S305>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_ec))) {
    /* Sum: '<S305>/Subtract1' incorporates:
     *  Constant: '<S305>/Constant1'
     */
    rtb_Switch2_c3 = -1.0 - rtb_Add_ec;

    /* Switch: '<S321>/Switch' incorporates:
     *  Constant: '<S305>/Constant1'
     *  RelationalOperator: '<S321>/UpperRelop'
     *  Sum: '<S305>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_ec))) {
      rtb_Switch2_c3 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S321>/Switch' */
  }

  /* End of Switch: '<S321>/Switch2' */

  /* Saturate: '<S305>/Saturation1' */
  if (rtb_Switch2_c3 > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_c3 < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Switch2_c3;
  }

  /* End of Saturate: '<S305>/Saturation1' */

  /* Sum: '<S305>/Add1' */
  rtb_Add_oy = rtb_Add_ec + rtb_Integral_ga;

  /* Saturate: '<S305>/Saturation2' */
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

  /* End of Saturate: '<S305>/Saturation2' */

  /* Sum: '<S339>/Add1' incorporates:
   *  Constant: '<S339>/Constant3'
   *  Constant: '<S339>/Constant4'
   *  Math: '<S339>/Math Function'
   *  Sum: '<S339>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S341>/Sum1' incorporates:
   *  Constant: '<S326>/Constant2'
   *  Product: '<S341>/Product'
   *  Sum: '<S341>/Sum'
   *  UnitDelay: '<S341>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S326>/Product' incorporates:
   *  Constant: '<S326>/Constant3'
   */
  rtb_Add_ec = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S340>/Diff' incorporates:
   *  UnitDelay: '<S340>/UD'
   *
   * Block description for '<S340>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S340>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Add_ec - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S326>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S326>/Add' incorporates:
   *  Gain: '<S326>/Gain1'
   *  Saturate: '<S326>/Saturation'
   */
  rtb_Add_os = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_oy;

  /* Sum: '<S326>/Subtract' incorporates:
   *  Constant: '<S326>/Constant'
   */
  rtb_Switch2_c3 = 1.0 - rtb_Add_os;

  /* Sum: '<S326>/Sum2' incorporates:
   *  Gain: '<S326>/Gain2'
   *  UnitDelay: '<S326>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S342>/Switch2' incorporates:
   *  Constant: '<S326>/Constant'
   *  RelationalOperator: '<S342>/LowerRelop1'
   *  Sum: '<S326>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_os))) {
    /* Sum: '<S326>/Subtract1' incorporates:
     *  Constant: '<S326>/Constant1'
     */
    rtb_Switch2_c3 = -1.0 - rtb_Add_os;

    /* Switch: '<S342>/Switch' incorporates:
     *  Constant: '<S326>/Constant1'
     *  RelationalOperator: '<S342>/UpperRelop'
     *  Sum: '<S326>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_os))) {
      rtb_Switch2_c3 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S342>/Switch' */
  }

  /* End of Switch: '<S342>/Switch2' */

  /* Saturate: '<S326>/Saturation1' */
  if (rtb_Switch2_c3 > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_c3 < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Switch2_c3;
  }

  /* End of Saturate: '<S326>/Saturation1' */

  /* Sum: '<S326>/Add1' */
  rtb_Add_oy = rtb_Add_os + rtb_Integral_bj;

  /* Saturate: '<S326>/Saturation2' */
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

  /* End of Saturate: '<S326>/Saturation2' */

  /* Sum: '<S189>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S139>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S191>/Sum1' incorporates:
   *  Constant: '<S189>/Constant2'
   *  Product: '<S191>/Product'
   *  Sum: '<S189>/Sum'
   *  Sum: '<S191>/Sum'
   *  UnitDelay: '<S191>/Unit Delay1'
   */
  rtb_Add_os = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S189>/Product' incorporates:
   *  Constant: '<S189>/Constant3'
   */
  rtb_Product_lo = rtb_Add_os * 0.0;

  /* Sum: '<S190>/Diff' incorporates:
   *  UnitDelay: '<S190>/UD'
   *
   * Block description for '<S190>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S190>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S189>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S189>/Add' incorporates:
   *  Gain: '<S189>/Gain'
   *  Gain: '<S189>/Gain1'
   *  Saturate: '<S189>/Saturation'
   *  Sum: '<S189>/Sum'
   */
  rtb_Switch2_p2 = ((Rebuilt_Transfer_Motor_Gain_FF *
                     Robot_Control_B.RB_Desired_Transfer_Speed) +
                    (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) +
    rtb_Add_oy;

  /* Logic: '<S139>/Logical Operator1' incorporates:
   *  Constant: '<S188>/Constant'
   *  RelationalOperator: '<S188>/Compare'
   */
  rtb_Compare_mq = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

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
      rtb_Compare_mq) {
    rtb_Compare_ky = true;
  } else {
    rtb_Compare_ky = (rtb_Compare_mq && (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S139>/Switch1' */

  /* Switch: '<S189>/Switch' incorporates:
   *  Constant: '<S189>/Constant4'
   */
  if (rtb_Compare_ky) {
    /* Sum: '<S189>/Sum2' incorporates:
     *  Gain: '<S189>/Gain2'
     *  Sum: '<S189>/Sum'
     *  UnitDelay: '<S189>/Unit Delay'
     */
    rtb_Switch2_c3 = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S189>/Subtract' incorporates:
     *  Constant: '<S189>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Switch2_p2;

    /* Switch: '<S192>/Switch2' incorporates:
     *  Constant: '<S189>/Constant'
     *  RelationalOperator: '<S192>/LowerRelop1'
     *  Sum: '<S189>/Subtract'
     */
    if (!(rtb_Switch2_c3 > (1.0 - rtb_Switch2_p2))) {
      /* Sum: '<S189>/Subtract1' incorporates:
       *  Constant: '<S189>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Switch2_p2;

      /* Switch: '<S192>/Switch' incorporates:
       *  Constant: '<S189>/Constant1'
       *  RelationalOperator: '<S192>/UpperRelop'
       *  Sum: '<S189>/Subtract1'
       */
      if (!(rtb_Switch2_c3 < (-1.0 - rtb_Switch2_p2))) {
        rtb_Integral_d = rtb_Switch2_c3;
      }

      /* End of Switch: '<S192>/Switch' */
    }

    /* End of Switch: '<S192>/Switch2' */

    /* Saturate: '<S189>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S189>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S189>/Switch' */

  /* Switch: '<S139>/Switch2' incorporates:
   *  Logic: '<S139>/Logical Operator1'
   */
  if (rtb_Compare_mq) {
    /* Sum: '<S189>/Add1' */
    rtb_Add_oy = rtb_Switch2_p2 + rtb_Integral_d;

    /* Saturate: '<S189>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S139>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S139>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S139>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S189>/Saturation2' */
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

  /* Switch: '<S130>/Init' incorporates:
   *  UnitDelay: '<S130>/FixPt Unit Delay1'
   *  UnitDelay: '<S130>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Switch2_c3 = rtb_Switch2_p2;
  } else {
    rtb_Switch2_c3 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S130>/Init' */

  /* Sum: '<S128>/Sum1' */
  rtb_Switch2_p2 -= rtb_Switch2_c3;

  /* Switch: '<S129>/Switch2' incorporates:
   *  Constant: '<S127>/Constant1'
   *  Constant: '<S127>/Constant3'
   *  RelationalOperator: '<S129>/LowerRelop1'
   *  RelationalOperator: '<S129>/UpperRelop'
   *  Switch: '<S129>/Switch'
   */
  if (rtb_Switch2_p2 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch2_p2 < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     */
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S129>/Switch2' */

  /* Sum: '<S128>/Sum' */
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

  /* Logic: '<S56>/Logical Operator1' incorporates:
   *  Constant: '<S68>/Constant'
   *  RelationalOperator: '<S68>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Switch2_p2 == 0.0);

  /* Sum: '<S69>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S56>/Subtract'
   */
  rtb_Error_n = rtb_Switch2_p2 - Robot_Control_U.Measured_Intake_Roller_Speed;

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
  rtb_Product_hm = rtb_Sum1_fh * 0.0;

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
  rtb_Add_oy = rtb_Product_hm - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S69>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S69>/Add' incorporates:
   *  Gain: '<S69>/Gain'
   *  Gain: '<S69>/Gain1'
   *  Saturate: '<S69>/Saturation'
   *  Sum: '<S69>/Sum'
   */
  rtb_Switch2_c3 = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Switch2_p2) +
                    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_oy;

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
    rtb_Compare_mq = true;
  } else {
    rtb_Compare_mq = (rtb_LogicalOperator1_n &&
                      (Robot_Control_DW.UnitDelay_DSTATE_nh));
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
    rtb_Switch2_p2 = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S69>/Subtract' incorporates:
     *  Constant: '<S69>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Switch2_c3;

    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S69>/Constant'
     *  RelationalOperator: '<S72>/LowerRelop1'
     *  Sum: '<S69>/Subtract'
     */
    if (!(rtb_Switch2_p2 > (1.0 - rtb_Switch2_c3))) {
      /* Sum: '<S69>/Subtract1' incorporates:
       *  Constant: '<S69>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Switch2_c3;

      /* Switch: '<S72>/Switch' incorporates:
       *  Constant: '<S69>/Constant1'
       *  RelationalOperator: '<S72>/UpperRelop'
       *  Sum: '<S69>/Subtract1'
       */
      if (!(rtb_Switch2_p2 < (-1.0 - rtb_Switch2_c3))) {
        rtb_Error_n = rtb_Switch2_p2;
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
    rtb_Add_oy = rtb_Switch2_c3 + rtb_Error_n;

    /* Saturate: '<S69>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_oy;
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
    rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S67>/Init' */

  /* Sum: '<S65>/Sum1' */
  rtb_Switch2_c3 = Robot_Control_B.RB_Des_Intake_Arm_Angle - rtb_Switch2_p2;

  /* Switch: '<S66>/Switch2' incorporates:
   *  Constant: '<S55>/Constant1'
   *  Constant: '<S55>/Constant3'
   *  RelationalOperator: '<S66>/LowerRelop1'
   *  RelationalOperator: '<S66>/UpperRelop'
   *  Switch: '<S66>/Switch'
   */
  if (rtb_Switch2_c3 > Rebuilt_Intake_RL_Inc) {
    rtb_Switch2_c3 = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Switch2_c3 < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    rtb_Switch2_c3 = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S66>/Switch2' */

  /* Sum: '<S65>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Switch2_c3 + rtb_Switch2_p2;

  /* Sum: '<S61>/Sum' */
  rtb_Switch2_p2 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S63>/Sum1' incorporates:
   *  Constant: '<S61>/Constant2'
   *  Product: '<S63>/Product'
   *  Sum: '<S63>/Sum'
   *  UnitDelay: '<S63>/Unit Delay1'
   */
  rtb_Sum1_dj = ((rtb_Switch2_p2 - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S61>/Product' incorporates:
   *  Constant: '<S61>/Constant3'
   */
  rtb_Product_ov = rtb_Sum1_dj * Rebuilt_Intake_Arm_Gain_D;

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
  rtb_Add_oy = rtb_Product_ov - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S61>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S61>/Add' incorporates:
   *  Gain: '<S61>/Gain'
   *  Gain: '<S61>/Gain1'
   *  Saturate: '<S61>/Saturation'
   */
  rtb_Add_ir = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
                (Rebuilt_Intake_Arm_Gain_P * rtb_Switch2_p2)) + rtb_Add_oy;

  /* Sum: '<S61>/Subtract' incorporates:
   *  Constant: '<S61>/Constant'
   */
  rtb_Switch2_c3 = 1.0 - rtb_Add_ir;

  /* Sum: '<S61>/Sum2' incorporates:
   *  Gain: '<S61>/Gain2'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  rtb_Switch2_p2 = (0.0 * rtb_Switch2_p2) + Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S64>/Switch2' incorporates:
   *  Constant: '<S61>/Constant'
   *  RelationalOperator: '<S64>/LowerRelop1'
   *  Sum: '<S61>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_ir))) {
    /* Sum: '<S61>/Subtract1' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    rtb_Switch2_c3 = -1.0 - rtb_Add_ir;

    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S61>/Constant1'
     *  RelationalOperator: '<S64>/UpperRelop'
     *  Sum: '<S61>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_ir))) {
      rtb_Switch2_c3 = rtb_Switch2_p2;
    }

    /* End of Switch: '<S64>/Switch' */
  }

  /* End of Switch: '<S64>/Switch2' */

  /* Saturate: '<S61>/Saturation1' */
  if (rtb_Switch2_c3 > 0.1) {
    rtb_Switch2_c3 = 0.1;
  } else if (rtb_Switch2_c3 < -0.1) {
    rtb_Switch2_c3 = -0.1;
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
    rtb_Add_oy = rtb_Add_ir + rtb_Switch2_c3;

    /* Saturate: '<S61>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_oy;
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
   *  Constant: '<S183>/Constant'
   *  RelationalOperator: '<S183>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S184>/Sum' incorporates:
   *  Sum: '<S137>/Subtract'
   */
  rtb_Switch2_p2 = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S186>/Sum1' incorporates:
   *  Constant: '<S184>/Constant2'
   *  Product: '<S186>/Product'
   *  Sum: '<S184>/Sum'
   *  Sum: '<S186>/Sum'
   *  UnitDelay: '<S186>/Unit Delay1'
   */
  rtb_Add_ir = ((rtb_Switch2_p2 - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S184>/Product' incorporates:
   *  Constant: '<S184>/Constant3'
   */
  rtb_Product_i = rtb_Add_ir * 0.0;

  /* Sum: '<S185>/Diff' incorporates:
   *  UnitDelay: '<S185>/UD'
   *
   * Block description for '<S185>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S185>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_i - Robot_Control_DW.UD_DSTATE_kz;

  /* Saturate: '<S184>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S184>/Add' incorporates:
   *  Gain: '<S184>/Gain'
   *  Gain: '<S184>/Gain1'
   *  Saturate: '<S184>/Saturation'
   *  Sum: '<S184>/Sum'
   */
  rtb_Add_oy += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Switch2_p2);

  /* Switch: '<S137>/Switch4' incorporates:
   *  Constant: '<S137>/Constant6'
   *  Constant: '<S137>/Constant7'
   *  Logic: '<S137>/Logical Operator1'
   *  Logic: '<S137>/Logical Operator2'
   *  RelationalOperator: '<S137>/LessThan2'
   *  UnitDelay: '<S137>/Unit Delay1'
   */
  if ((rtb_Switch2_p2 < 0.0) && rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_n &&
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
  if ((rtb_Switch2_p2 < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S137>/Switch1' */

  /* Switch: '<S184>/Switch' incorporates:
   *  Constant: '<S184>/Constant4'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S184>/Sum2' incorporates:
     *  Gain: '<S184>/Gain2'
     *  Product: '<S184>/Product1'
     *  Sum: '<S184>/Sum'
     *  Switch: '<S184>/Switch1'
     *  UnitDelay: '<S184>/Unit Delay'
     */
    rtb_Switch2_p2 = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Switch2_p2) * ((real_T)
      (!rtb_Intake_Arm_Move_In))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S184>/Subtract' incorporates:
     *  Constant: '<S184>/Constant'
     */
    rtb_Error_c5 = 1.0 - rtb_Add_oy;

    /* Switch: '<S187>/Switch2' incorporates:
     *  Constant: '<S184>/Constant'
     *  RelationalOperator: '<S187>/LowerRelop1'
     *  Sum: '<S184>/Subtract'
     */
    if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_oy))) {
      /* Sum: '<S184>/Subtract1' incorporates:
       *  Constant: '<S184>/Constant1'
       */
      rtb_Error_c5 = -1.0 - rtb_Add_oy;

      /* Switch: '<S187>/Switch' incorporates:
       *  Constant: '<S184>/Constant1'
       *  RelationalOperator: '<S187>/UpperRelop'
       *  Sum: '<S184>/Subtract1'
       */
      if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_oy))) {
        rtb_Error_c5 = rtb_Switch2_p2;
      }

      /* End of Switch: '<S187>/Switch' */
    }

    /* End of Switch: '<S187>/Switch2' */

    /* Saturate: '<S184>/Saturation1' */
    if (rtb_Error_c5 > 0.1) {
      rtb_Switch2_p2 = 0.1;
    } else if (rtb_Error_c5 < -0.1) {
      rtb_Switch2_p2 = -0.1;
    } else {
      rtb_Switch2_p2 = rtb_Error_c5;
    }

    /* End of Saturate: '<S184>/Saturation1' */
  } else {
    rtb_Switch2_p2 = 0.0;
  }

  /* End of Switch: '<S184>/Switch' */

  /* Switch: '<S137>/Switch2' incorporates:
   *  Logic: '<S137>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S184>/Add1' */
    rtb_Add_oy += rtb_Switch2_p2;

    /* Saturate: '<S184>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S137>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S137>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S137>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S184>/Saturation2' */
  } else {
    /* Switch: '<S137>/Switch2' incorporates:
     *  Constant: '<S137>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S137>/Switch2' */

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

  /* Update for UnitDelay: '<S354>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S354>/FixPt Constant'
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

  /* Update for UnitDelay: '<S377>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S376>/UD'
   *
   * Block description for '<S376>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S374>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Saturation_h;

  /* Update for UnitDelay: '<S356>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Init_o;

  /* Update for UnitDelay: '<S371>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S371>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S371>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S355>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S364>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S364>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S364>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S330>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch_hs;

  /* Update for UnitDelay: '<S329>/UD'
   *
   * Block description for '<S329>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch1_n;

  /* Update for UnitDelay: '<S323>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S267>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S266>/UD'
   *
   * Block description for '<S266>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Init;

  /* Update for UnitDelay: '<S260>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S278>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S277>/UD'
   *
   * Block description for '<S277>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_bq;

  /* Update for UnitDelay: '<S263>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S288>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S287>/UD'
   *
   * Block description for '<S287>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S281>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S299>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_bl;

  /* Update for UnitDelay: '<S298>/UD'
   *
   * Block description for '<S298>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_fl;

  /* Update for UnitDelay: '<S284>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S309>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S308>/UD'
   *
   * Block description for '<S308>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S302>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S320>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S319>/UD'
   *
   * Block description for '<S319>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S305>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S341>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S340>/UD'
   *
   * Block description for '<S340>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_ec;

  /* Update for UnitDelay: '<S326>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S191>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_os;

  /* Update for UnitDelay: '<S190>/UD'
   *
   * Block description for '<S190>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S189>/Unit Delay' */
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
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_hm;

  /* Update for UnitDelay: '<S69>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S56>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_nh = rtb_Compare_mq;

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
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_ov;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_Switch2_c3;

  /* Update for UnitDelay: '<S186>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Add_ir;

  /* Update for UnitDelay: '<S185>/UD'
   *
   * Block description for '<S185>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_i;

  /* Update for UnitDelay: '<S137>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S184>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S137>/Unit Delay' */
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
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

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

  /* InitializeConditions for UnitDelay: '<S354>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S371>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S364>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S130>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S67>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S433>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S199>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S195>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S199>/Robot_Index_Is_Valid' */
  /* Start for If: '<S202>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S202>/Circle_Check_Valid' */
  /* Start for If: '<S204>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d0 = -1;

  /* End of SystemInitialize for SubSystem: '<S202>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S199>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S166>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ms = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S168>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S170>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S171>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ht = Rebuilt_Match_Time_End_Game_Timer;

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
