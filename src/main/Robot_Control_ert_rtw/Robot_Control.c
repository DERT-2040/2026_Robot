/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.480
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Mar 28 20:54:26 2026
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

/* Named constants for Chart: '<S355>/Add dither' */
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
                                      * Referenced by: '<S429>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S425>/Constant'
                                        *   '<S425>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S429>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S425>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S258>/Constant3'
                                        *   '<S279>/Constant3'
                                        *   '<S300>/Constant3'
                                        *   '<S321>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S258>/Constant2'
                                   *   '<S279>/Constant2'
                                   *   '<S300>/Constant2'
                                   *   '<S321>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S258>/Saturation'
                                        *   '<S279>/Saturation'
                                        *   '<S300>/Saturation'
                                        *   '<S321>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S258>/Saturation'
                                        *   '<S279>/Saturation'
                                        *   '<S300>/Saturation'
                                        *   '<S321>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S258>/Gain'
                                            *   '<S279>/Gain'
                                            *   '<S300>/Gain'
                                            *   '<S321>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S258>/Gain2'
                                        *   '<S279>/Gain2'
                                        *   '<S300>/Gain2'
                                        *   '<S321>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S258>/Saturation1'
                                         *   '<S279>/Saturation1'
                                         *   '<S300>/Saturation1'
                                         *   '<S321>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S258>/Saturation1'
                                        *   '<S279>/Saturation1'
                                        *   '<S300>/Saturation1'
                                        *   '<S321>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S258>/Gain1'
                                        *   '<S279>/Gain1'
                                        *   '<S300>/Gain1'
                                        *   '<S321>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S263>/Constant'
                            *   '<S284>/Constant'
                            *   '<S305>/Constant'
                            *   '<S326>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S182>/BlueAllianceZoneX'
                                         *   '<S184>/BlueAllianceZoneX'
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
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S147>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S147>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S183>/RedAllianceZoneX'
                                         *   '<S185>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S147>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S147>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S415>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S415>/Constant5'
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
                                       * Referenced by: '<S142>/Constant'
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
                                       * Referenced by: '<S167>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S171>/Constant3'
                                   *   '<S172>/Unit Delay'
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
                                      *   '<S168>/Unit Delay'
                                      *   '<S169>/Unit Delay'
                                      *   '<S170>/Unit Delay'
                                      *   '<S171>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S168>/Constant2'
                                      *   '<S169>/Constant2'
                                      *   '<S170>/Constant2'
                                      *   '<S171>/Constant2'
                                      *   '<S175>/Constant'
                                      *   '<S176>/Constant'
                                      *   '<S177>/Constant'
                                      *   '<S178>/Constant'
                                      */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S159>/Constant'
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
                              * Referenced by: '<S138>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S187>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S187>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S187>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S414>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S412>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S414>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S415>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S415>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S247>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S247>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S194>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S207>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S247>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S354>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S354>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S354>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S354>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S354>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S354>/Constant3'
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
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S355>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S355>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S355>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S355>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S261>/Constant3'
                                        *   '<S282>/Constant3'
                                        *   '<S303>/Constant3'
                                        *   '<S324>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S261>/Constant2'
                                *   '<S282>/Constant2'
                                *   '<S303>/Constant2'
                                *   '<S324>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S261>/Saturation'
                                           *   '<S282>/Saturation'
                                           *   '<S303>/Saturation'
                                           *   '<S324>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S261>/Saturation'
                                          *   '<S282>/Saturation'
                                          *   '<S303>/Saturation'
                                          *   '<S324>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S261>/Gain2'
                                         *   '<S282>/Gain2'
                                         *   '<S303>/Gain2'
                                         *   '<S324>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S261>/Saturation1'
                                             *   '<S282>/Saturation1'
                                             *   '<S303>/Saturation1'
                                             *   '<S324>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S261>/Saturation1'
                                            *   '<S282>/Saturation1'
                                            *   '<S303>/Saturation1'
                                            *   '<S324>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S261>/Gain1'
                                        *   '<S282>/Gain1'
                                        *   '<S303>/Gain1'
                                        *   '<S324>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S353>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S353>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S353>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S353>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S353>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S353>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S414>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S414>/Constant1'
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
                                      * Referenced by: '<S413>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S413>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S413>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S341>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S341>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S341>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S341>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S341>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S341>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S415>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S414>/Dead Zone'
                                        *   '<S415>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S414>/Dead Zone'
                                        *   '<S415>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S412>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S412>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S412>/Constant4'
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
                                        * Referenced by: '<S412>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S412>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S412>/Constant5'
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
                                        *   '<S412>/Constant11'
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
  /* InitializeConditions for UnitDelay: '<S168>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * System reset for action system:
 *    '<S133>/If Action Subsystem1'
 *    '<S133>/If Action Subsystem3'
 */
void Robot__IfActionSubsystem1_Reset(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S168>/Unit Delay' */
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

  /* RelationalOperator: '<S175>/Compare' incorporates:
   *  Constant: '<S168>/Constant1'
   *  Constant: '<S175>/Constant'
   *  Sum: '<S168>/Sum'
   *  UnitDelay: '<S168>/Unit Delay'
   */
  rtb_Compare_cf = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S168>/Logical Operator' incorporates:
   *  Logic: '<S168>/NOT'
   */
  *rty_IsBlueActive = ((!(rtu_IsBlueInactiveFirst != 0.0)) || rtb_Compare_cf);

  /* Logic: '<S168>/Logical Operator1' */
  *rty_IsRedActive = ((rtu_IsBlueInactiveFirst != 0.0) || rtb_Compare_cf);

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
  real_T rtb_LookupTableDynamic_b;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_MatrixConcatenate_idx_0;
  real_T rtb_Merge1;
  real_T rtb_Minus_f;
  real_T rtb_Minus_k_idx_0;
  real_T rtb_Minus_k_idx_1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_ej;
  real_T rtb_Product_hi;
  real_T rtb_Product_ih;
  real_T rtb_Product_k;
  real_T rtb_Product_ld;
  real_T rtb_Saturation_h;
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
  real_T rtb_Switch2_e;
  real_T rtb_Switch2_h;
  real_T rtb_Switch2_hw;
  real_T rtb_Switch2_pt;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s219_iter;
  uint16_T s244_iter;
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

  /* If: '<S441>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S441>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S444>/Action Port'
     */
    /* Product: '<S444>/Product' incorporates:
     *  Constant: '<S444>/Constant1'
     *  Constant: '<S444>/Constant2'
     *  Math: '<S444>/Math Function'
     */
    rtb_Sin4 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495) *
      111.0;

    /* End of Outputs for SubSystem: '<S441>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S441>/Subsystem' incorporates:
     *  ActionPort: '<S445>/Action Port'
     */
    /* SignalConversion generated from: '<S445>/Out1' incorporates:
     *  Constant: '<S445>/Constant'
     */
    rtb_Sin4 = 0.0;

    /* End of Outputs for SubSystem: '<S441>/Subsystem' */
  }

  /* End of If: '<S441>/If' */

  /* Gain: '<S442>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Init_o = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S443>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Sin4 * cos(rtb_Init_o)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S443>/theta->y'
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
      rtb_Compare_pb);

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     */
    switch ((int32_T)rtb_Init_o) {
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
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S31>/Delay Input1'
     *
     * Block description for '<S31>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_gf = rtb_Compare_pb;

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
       *  UnitDelay: '<S414>/Unit Delay1'
       *  UnitDelay: '<S414>/Unit Delay2'
       *  UnitDelay: '<S414>/Unit Delay3'
       *  UnitDelay: '<S414>/Unit Delay4'
       *  UnitDelay: '<S417>/Delay Input1'
       *  UnitDelay: '<S418>/Delay Input1'
       *  UnitDelay: '<S419>/Delay Input1'
       *  UnitDelay: '<S420>/Delay Input1'
       *  UnitDelay: '<S422>/Delay Input1'
       *  UnitDelay: '<S428>/Unit Delay'
       *  UnitDelay: '<S428>/Unit Delay1'
       *  UnitDelay: '<S432>/FixPt Unit Delay1'
       *  UnitDelay: '<S432>/FixPt Unit Delay2'
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
       * Block description for '<S420>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S422>/Delay Input1':
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

    /* Switch: '<S412>/Switch4' incorporates:
     *  Constant: '<S437>/Constant'
     *  Constant: '<S440>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S437>/Compare'
     *  RelationalOperator: '<S440>/Compare'
     *  Switch: '<S412>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S412>/Switch4' incorporates:
       *  Constant: '<S412>/Constant8'
       *  Sum: '<S412>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S412>/Switch5' incorporates:
       *  Constant: '<S412>/Constant7'
       *  Gain: '<S412>/Gain'
       *  Sum: '<S412>/Subtract5'
       *  Switch: '<S412>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S412>/Switch4' incorporates:
       *  Constant: '<S412>/Constant6'
       *  Switch: '<S412>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S412>/Switch4' */

    /* Logic: '<S412>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S412>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S414>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Minus_f = 0.0;
    } else {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S414>/Add' incorporates:
     *  Constant: '<S414>/Constant'
     *  Constant: '<S414>/Constant1'
     *  DeadZone: '<S414>/Dead Zone'
     *  Lookup_n-D: '<S414>/Modulation_Str_Y_Rel'
     *  Product: '<S414>/Product'
     *  Product: '<S414>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Minus_f *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S416>/Compare' incorporates:
     *  Constant: '<S416>/Constant'
     */
    rtb_Compare_lk = (rtb_Switch1_m == 0.0);

    /* Logic: '<S414>/AND2' incorporates:
     *  RelationalOperator: '<S417>/FixPt Relational Operator'
     *  RelationalOperator: '<S418>/FixPt Relational Operator'
     *  RelationalOperator: '<S419>/FixPt Relational Operator'
     *  RelationalOperator: '<S420>/FixPt Relational Operator'
     *  UnitDelay: '<S417>/Delay Input1'
     *  UnitDelay: '<S418>/Delay Input1'
     *  UnitDelay: '<S419>/Delay Input1'
     *  UnitDelay: '<S420>/Delay Input1'
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
     * Block description for '<S420>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Intake_Arm_Move_In = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_Compare_pb) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S414>/AND1' incorporates:
     *  Logic: '<S414>/AND3'
     *  UnitDelay: '<S414>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_lk && (rtb_Intake_Arm_Move_In ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S414>/AND4' incorporates:
     *  Logic: '<S414>/AND8'
     *  UnitDelay: '<S414>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_lk && (!rtb_Intake_Arm_Move_In)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S414>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* Switch: '<S414>/Switch8' incorporates:
     *  Constant: '<S423>/Constant'
     *  Logic: '<S414>/AND9'
     *  RelationalOperator: '<S422>/FixPt Relational Operator'
     *  RelationalOperator: '<S423>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S422>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S422>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_lk) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S414>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S414>/Switch8' incorporates:
       *  UnitDelay: '<S414>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S414>/Switch8' */

    /* Switch: '<S414>/Switch4' incorporates:
     *  Constant: '<S414>/Constant5'
     *  Switch: '<S414>/Switch1'
     *  Switch: '<S414>/Switch5'
     *  Switch: '<S414>/Switch6'
     *  Switch: '<S414>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Saturation_h = 0.0;
    } else if (rtb_Compare_pb) {
      /* Switch: '<S414>/Switch5' incorporates:
       *  Constant: '<S414>/Constant6'
       */
      rtb_Saturation_h = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S414>/Switch6' incorporates:
       *  Constant: '<S414>/Constant7'
       *  Switch: '<S414>/Switch5'
       */
      rtb_Saturation_h = 3.1415926535897931;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S414>/Switch7' incorporates:
       *  Constant: '<S414>/Constant8'
       *  Switch: '<S414>/Switch5'
       *  Switch: '<S414>/Switch6'
       */
      rtb_Saturation_h = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S414>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S414>/Switch5'
       *  Switch: '<S414>/Switch6'
       *  Switch: '<S414>/Switch7'
       */
      rtb_Saturation_h = 0.0;
    } else {
      /* Switch: '<S414>/Switch6' incorporates:
       *  Switch: '<S414>/Switch5'
       *  Switch: '<S414>/Switch7'
       *  UnitDelay: '<S414>/Unit Delay1'
       */
      rtb_Saturation_h = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S414>/Switch4' */

    /* Switch: '<S414>/Switch2' incorporates:
     *  Switch: '<S414>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S414>/Switch2' incorporates:
       *  Constant: '<S414>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S414>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Saturation_h;
    } else {
      /* Switch: '<S414>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S414>/Switch3' incorporates:
       *  Constant: '<S414>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S414>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S414>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S413>/Switch1' incorporates:
     *  Constant: '<S413>/Constant5'
     *  Constant: '<S413>/Constant8'
     *  DataTypeConversion: '<S413>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_lk;
    }

    /* End of Switch: '<S413>/Switch1' */

    /* Lookup_n-D: '<S415>/Modulation_Drv' incorporates:
     *  Math: '<S415>/Magnitude'
     */
    rtb_Init_o = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S426>/Compare' incorporates:
     *  Constant: '<S426>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Init_o == 0.0);

    /* DeadZone: '<S415>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_Sin4 = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S415>/Dead Zone' */

    /* Logic: '<S415>/Logical Operator' incorporates:
     *  Constant: '<S427>/Constant'
     *  RelationalOperator: '<S427>/Compare'
     */
    rtb_Intake_Arm_Move_In = ((rtb_Sin4 != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S413>/Switch' incorporates:
     *  Constant: '<S413>/Constant5'
     *  Constant: '<S413>/Constant7'
     *  DataTypeConversion: '<S413>/Data Type Conversion'
     *  Logic: '<S415>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Move_In;
    }

    /* End of Switch: '<S413>/Switch' */

    /* Switch: '<S412>/Switch2' incorporates:
     *  Constant: '<S412>/Constant2'
     *  Constant: '<S436>/Constant'
     *  Constant: '<S439>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S436>/Compare'
     *  RelationalOperator: '<S439>/Compare'
     *  Sum: '<S412>/Subtract'
     *  Switch: '<S412>/Switch'
     *  Switch: '<S412>/Switch1'
     *  Switch: '<S412>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S412>/Switch2' incorporates:
       *  Constant: '<S412>/Constant5'
       *  Sum: '<S412>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_h = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S412>/Switch2' incorporates:
       *  Constant: '<S412>/Constant4'
       *  Sum: '<S412>/Subtract2'
       *  Switch: '<S412>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S412>/Switch1' incorporates:
       *  Constant: '<S412>/Constant1'
       *  Sum: '<S412>/Subtract3'
       */
      rtb_Switch2_h = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S412>/Switch2' incorporates:
       *  Constant: '<S412>/Constant3'
       *  Switch: '<S412>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S412>/Switch1' incorporates:
       *  Constant: '<S412>/Constant'
       */
      rtb_Switch2_h = 0.0;
    }

    /* End of Switch: '<S412>/Switch2' */

    /* UnaryMinus: '<S412>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_h;

    /* Switch: '<S428>/Switch1' incorporates:
     *  Constant: '<S433>/Constant'
     *  Constant: '<S434>/Constant'
     *  Logic: '<S428>/AND'
     *  RelationalOperator: '<S433>/Compare'
     *  RelationalOperator: '<S434>/Compare'
     *  Switch: '<S428>/Switch2'
     *  UnitDelay: '<S428>/Unit Delay'
     *  UnitDelay: '<S428>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_hw = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1_n = rtb_Switch1_hb;
      rtb_Switch2_hw = rtb_Sum1;
    }

    /* End of Switch: '<S428>/Switch1' */

    /* Switch: '<S415>/Switch1' incorporates:
     *  Logic: '<S415>/Logical Operator1'
     *  Switch: '<S415>/Switch4'
     *  Switch: '<S415>/Switch9'
     */
    if (rtb_Intake_Arm_Move_In) {
      /* Signum: '<S415>/Sign' */
      if (rtIsNaN(rtb_Sin4)) {
        rtb_Minus_f = (rtNaN);
      } else if (rtb_Sin4 < 0.0) {
        rtb_Minus_f = -1.0;
      } else {
        rtb_Minus_f = (rtb_Sin4 > 0.0);
      }

      /* Switch: '<S415>/Switch5' incorporates:
       *  Constant: '<S415>/Constant3'
       *  Constant: '<S415>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_pv = -1.5707963267948966;
      } else {
        rtb_Add_pv = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S415>/Gain3'
       *  Signum: '<S415>/Sign'
       *  Sum: '<S415>/Add'
       *  Switch: '<S415>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Minus_f) +
        rtb_Add_pv;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S415>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S415>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S415>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S415>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S415>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S415>/Switch4'
       *  Trigonometry: '<S415>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1_n,
        rtb_Switch2_hw);
    }

    /* End of Switch: '<S415>/Switch1' */

    /* Switch: '<S425>/Switch1' incorporates:
     *  Constant: '<S425>/Constant'
     *  Constant: '<S425>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_h = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_h = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S425>/Switch1' */

    /* Switch: '<S432>/Init' incorporates:
     *  UnitDelay: '<S432>/FixPt Unit Delay1'
     *  UnitDelay: '<S432>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_h;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S432>/Init' */

    /* Sum: '<S430>/Sum1' */
    rtb_Switch2_h -= rtb_Init;

    /* Switch: '<S431>/Switch2' incorporates:
     *  Constant: '<S429>/Constant1'
     *  Constant: '<S429>/Constant3'
     *  RelationalOperator: '<S431>/LowerRelop1'
     *  RelationalOperator: '<S431>/UpperRelop'
     *  Switch: '<S431>/Switch'
     */
    if (rtb_Switch2_h > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_h = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_h < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S431>/Switch' incorporates:
       *  Constant: '<S429>/Constant1'
       */
      rtb_Switch2_h = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S431>/Switch2' */

    /* Sum: '<S430>/Sum' */
    rtb_Init += rtb_Switch2_h;

    /* Switch: '<S415>/Switch8' incorporates:
     *  Logic: '<S415>/Logical Operator1'
     *  Switch: '<S415>/Switch2'
     */
    if (rtb_Intake_Arm_Move_In) {
      /* Switch: '<S415>/Switch' incorporates:
       *  Gain: '<S415>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Sin4;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S415>/Constant5'
       *  Gain: '<S415>/Gain2'
       *  Math: '<S415>/Magnitude1'
       *  MinMax: '<S415>/Min'
       *  Switch: '<S415>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S425>/Product' incorporates:
       *  Switch: '<S415>/Switch2'
       */
      rtb_Add_pv = rtb_Init_o * rtb_Init;

      /* Saturate: '<S425>/Saturation' incorporates:
       *  Switch: '<S415>/Switch2'
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

      /* End of Saturate: '<S425>/Saturation' */
    }

    /* End of Switch: '<S415>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S414>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Switch: '<S412>/Switch6' incorporates:
     *  Constant: '<S412>/Constant11'
     *  Switch: '<S412>/Switch7'
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

    /* RelationalOperator: '<S408>/Compare' incorporates:
     *  Constant: '<S408>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Compare_ky = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S409>/Compare' incorporates:
     *  Constant: '<S409>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Compare_mq = (Robot_Control_U.Gamepad_RB != 0.0);

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
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Constant: '<S405>/Constant'
     *  Constant: '<S410>/Constant'
     *  Inport: '<Root>/Gamepad_LT'
     *  Inport: '<Root>/Joystick_Right_B1'
     *  RelationalOperator: '<S405>/Compare'
     *  RelationalOperator: '<S410>/Compare'
     */
    rtb_LogicalOperator1_ms = ((Robot_Control_U.Joystick_Right_B1 != 0.0) ||
      (Robot_Control_U.Gamepad_LT != 0.0));

    /* SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     */
    rtb_Switch1_m = 0.0;

    /* Update for UnitDelay: '<S422>/Delay Input1'
     *
     * Block description for '<S422>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_lk;

    /* Update for UnitDelay: '<S421>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S421>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S417>/Delay Input1'
     *
     * Block description for '<S417>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S418>/Delay Input1'
     *
     * Block description for '<S418>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_Compare_pb;

    /* Update for UnitDelay: '<S419>/Delay Input1'
     *
     * Block description for '<S419>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S420>/Delay Input1'
     *
     * Block description for '<S420>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S414>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S414>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S414>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S414>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S428>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1_n;

    /* Update for UnitDelay: '<S428>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2_hw;

    /* Update for UnitDelay: '<S432>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S432>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S432>/FixPt Unit Delay1' */
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
   *  Constant: '<S244>/Constant'
   *  Logic: '<S244>/AND'
   *  MATLAB Function: '<S194>/Find closest index to curve'
   *  Product: '<S244>/Product'
   *  RelationalOperator: '<S244>/Relational Operator'
   *  RelationalOperator: '<S244>/Relational Operator1'
   *  Selector: '<S244>/Selector'
   *  Selector: '<S244>/Selector1'
   *  Selector: '<S245>/Selector'
   *  Sum: '<S244>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S197>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S200>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S202>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S197>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S192>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S192>/Unit Delay'
       *  UnitDelay: '<S193>/Unit Delay'
       *  UnitDelay: '<S195>/Unit Delay'
       *  UnitDelay: '<S195>/Unit Delay1'
       *  UnitDelay: '<S245>/Unit Delay'
       *  UnitDelay: '<S245>/Unit Delay1'
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
     *  ActionPort: '<S192>/Action Port'
     */
    /* Selector: '<S193>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S193>/Selector1' */

    /* Lookup_n-D: '<S192>/Capture Radius' incorporates:
     *  UnitDelay: '<S192>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S193>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S193>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S197>/If' incorporates:
     *  RelationalOperator: '<S197>/ '
     *  UnitDelay: '<S193>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S200>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S202>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S197>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S200>/Action Port'
       */
      /* InitializeConditions for If: '<S197>/If' incorporates:
       *  UnitDelay: '<S200>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S197>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S197>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S200>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S200>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S203>/Action Port'
       */
      /* If: '<S200>/If' incorporates:
       *  Selector: '<S193>/Selector1'
       *  Selector: '<S200>/Selector'
       *  Selector: '<S203>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S200>/Increment_If_Rectangle_Check' */

      /* Sum: '<S200>/Minus' incorporates:
       *  Concatenate: '<S193>/Matrix Concatenate2'
       *  Selector: '<S200>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S200>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S203>/Action Port'
       */
      /* If: '<S200>/If' incorporates:
       *  Selector: '<S193>/Selector1'
       *  Selector: '<S200>/Selector'
       *  Selector: '<S203>/Selector'
       *  Sum: '<S200>/Minus'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh)
        + 9];

      /* End of Outputs for SubSystem: '<S200>/Increment_If_Rectangle_Check' */

      /* Sum: '<S200>/Minus' incorporates:
       *  Concatenate: '<S193>/Matrix Concatenate2'
       *  Selector: '<S200>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Init_o;

      /* Math: '<S200>/Hypot' */
      rtb_Switch1_n = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S200>/Equal' */
      rtb_LogicalOperator5 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S200>/Switch' incorporates:
       *  Logic: '<S200>/AND'
       *  Logic: '<S200>/OR'
       *  RelationalOperator: '<S200>/Relational Operator'
       *  UnitDelay: '<S200>/Unit Delay'
       */
      rtb_LogicalOperator1 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Switch1_n <= rtb_Saturation_h) && rtb_LogicalOperator5));

      /* If: '<S200>/If' */
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
        /* Disable for If: '<S202>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S200>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S202>/Action Port'
         */
        /* If: '<S202>/If' incorporates:
         *  RelationalOperator: '<S202>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S202>/Is_Last_Point' incorporates:
           *  ActionPort: '<S205>/Action Port'
           */
          /* InitializeConditions for If: '<S202>/If' incorporates:
           *  UnitDelay: '<S205>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S202>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S202>/Is_Last_Point' incorporates:
           *  ActionPort: '<S205>/Action Port'
           */
          /* Switch: '<S205>/Switch' incorporates:
           *  Constant: '<S207>/Constant'
           *  Logic: '<S205>/OR'
           *  RelationalOperator: '<S207>/Compare'
           *  UnitDelay: '<S205>/Unit Delay'
           */
          rtb_Is_Absolute_Translation_g = ((Robot_Control_DW.UnitDelay_DSTATE_nu)
            || (rtb_Switch1_n <= Spline_Stop_Radius));

          /* If: '<S205>/If' */
          if (rtb_Is_Absolute_Translation_g) {
            /* Outputs for IfAction SubSystem: '<S205>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S208>/Action Port'
             */
            /* Merge: '<S197>/Merge2' incorporates:
             *  Constant: '<S208>/Constant'
             *  SignalConversion generated from: '<S208>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = true;

            /* SignalConversion generated from: '<S208>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S208>/Constant1'
             */
            rtb_Compare_pb = false;

            /* End of Outputs for SubSystem: '<S205>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S205>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S209>/Action Port'
             */
            /* Merge: '<S197>/Merge2' incorporates:
             *  Constant: '<S209>/Constant'
             *  SignalConversion generated from: '<S209>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = false;

            /* SignalConversion generated from: '<S209>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S209>/Constant1'
             */
            rtb_Compare_pb = true;

            /* End of Outputs for SubSystem: '<S205>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S205>/If' */

          /* Merge: '<S197>/Merge4' incorporates:
           *  SignalConversion: '<S205>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S205>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Is_Absolute_Translation_g;

          /* End of Outputs for SubSystem: '<S202>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S202>/Increment_Search' incorporates:
           *  ActionPort: '<S204>/Action Port'
           */
          /* Merge: '<S197>/Merge2' incorporates:
           *  Constant: '<S204>/Constant'
           *  SignalConversion generated from: '<S204>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator5 = false;

          /* SignalConversion generated from: '<S204>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S204>/Constant1'
           */
          rtb_Compare_pb = false;

          /* Merge: '<S197>/Merge4' incorporates:
           *  Constant: '<S206>/FixPt Constant'
           *  SignalConversion: '<S204>/Signal Copy'
           *  Sum: '<S206>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S202>/Increment_Search' */
        }

        /* End of If: '<S202>/If' */
        /* End of Outputs for SubSystem: '<S200>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S200>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S203>/Action Port'
         */
        /* Sum: '<S210>/FixPt Sum1' incorporates:
         *  Constant: '<S210>/FixPt Constant'
         */
        rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S203>/Selector1' incorporates:
         *  Selector: '<S193>/Selector1'
         */
        rtb_Switch2_h = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) - 1];

        /* Sum: '<S211>/Subtract' incorporates:
         *  Selector: '<S203>/Selector1'
         *  Sum: '<S211>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_h - rtb_Init;

        /* Selector: '<S203>/Selector1' incorporates:
         *  Selector: '<S193>/Selector1'
         */
        rtb_Sin4 = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) + 9];

        /* Sum: '<S211>/Subtract' incorporates:
         *  Selector: '<S203>/Selector1'
         *  Sum: '<S211>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Sin4 - rtb_Init_o;

        /* Math: '<S211>/Hypot' */
        rtb_Switch2_hw = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S211>/Divide' */
        rtb_Switch1_n = rtb_Minus_n[1];

        /* UnaryMinus: '<S211>/Unary Minus' */
        rtb_Minus_f = rtb_Minus_n[0];

        /* Product: '<S211>/Product' incorporates:
         *  Product: '<S211>/Divide'
         *  UnaryMinus: '<S211>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch1_n / rtb_Switch2_hw) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Minus_f) / rtb_Switch2_hw) * rtb_Saturation_h;

        /* Sum: '<S211>/Add1' incorporates:
         *  Sum: '<S211>/Add2'
         *  Sum: '<S211>/Minus'
         */
        rtb_Minus_f = rtb_Switch2_h - rtb_Minus_n[0];

        /* Sum: '<S211>/Minus4' incorporates:
         *  Sum: '<S211>/Add2'
         *  Sum: '<S211>/Minus'
         */
        rtb_Switch2_h = (rtb_Switch2_h + rtb_Minus_n[0]) - rtb_Minus_f;

        /* Sum: '<S211>/Minus5' incorporates:
         *  Concatenate: '<S193>/Matrix Concatenate2'
         *  Sum: '<S211>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[0] - rtb_Minus_f;

        /* Sum: '<S211>/Add' incorporates:
         *  Sum: '<S211>/Add2'
         *  Sum: '<S211>/Minus1'
         */
        rtb_Switch1_n = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S211>/Minus' incorporates:
         *  Sum: '<S211>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S211>/Dot Product' incorporates:
         *  Concatenate: '<S193>/Matrix Concatenate2'
         *  Sum: '<S211>/Minus'
         *  Sum: '<S211>/Minus1'
         *  Sum: '<S211>/Minus5'
         */
        rtb_Switch2_hw = (rtb_Reshapey[0] - rtb_Switch1_n) * rtb_Minus_f;

        /* DotProduct: '<S211>/Dot Product1' incorporates:
         *  Sum: '<S211>/Minus'
         */
        rtb_Init = rtb_Minus_f * rtb_Minus_f;

        /* DotProduct: '<S211>/Dot Product2' incorporates:
         *  Sum: '<S211>/Minus4'
         *  Sum: '<S211>/Minus5'
         */
        rtb_Minus_k_idx_0 = rtb_Switch2_h * rtb_MatrixConcatenate_b_idx_0;

        /* DotProduct: '<S211>/Dot Product3' incorporates:
         *  Sum: '<S211>/Minus4'
         */
        rtb_Minus_k_idx_1 = rtb_Switch2_h * rtb_Switch2_h;

        /* Sum: '<S211>/Add1' incorporates:
         *  Sum: '<S211>/Add2'
         *  Sum: '<S211>/Minus'
         */
        rtb_Minus_f = rtb_Sin4 - rtb_Minus_n[1];

        /* Sum: '<S211>/Minus4' incorporates:
         *  Sum: '<S211>/Add2'
         *  Sum: '<S211>/Minus'
         */
        rtb_Switch2_h = (rtb_Sin4 + rtb_Minus_n[1]) - rtb_Minus_f;

        /* Sum: '<S211>/Minus5' incorporates:
         *  Concatenate: '<S193>/Matrix Concatenate2'
         *  Sum: '<S211>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[1] - rtb_Minus_f;

        /* Sum: '<S211>/Add' incorporates:
         *  Sum: '<S211>/Add2'
         *  Sum: '<S211>/Minus1'
         */
        rtb_Switch1_n = rtb_Init_o - rtb_Minus_n[1];

        /* Sum: '<S211>/Minus' incorporates:
         *  Sum: '<S211>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S211>/Dot Product' incorporates:
         *  Concatenate: '<S193>/Matrix Concatenate2'
         *  Sum: '<S211>/Minus'
         *  Sum: '<S211>/Minus1'
         *  Sum: '<S211>/Minus5'
         */
        rtb_Switch2_hw += (rtb_Reshapey[1] - rtb_Switch1_n) * rtb_Minus_f;

        /* RelationalOperator: '<S212>/Compare' incorporates:
         *  Constant: '<S212>/Constant'
         */
        rtb_LogicalOperator5 = (rtb_Switch2_hw >= 0.0);

        /* RelationalOperator: '<S211>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S211>/Dot Product1'
         *  Sum: '<S211>/Minus'
         */
        rtb_Compare_pb = (rtb_Switch2_hw <= ((rtb_Minus_f * rtb_Minus_f) +
          rtb_Init));

        /* DotProduct: '<S211>/Dot Product2' incorporates:
         *  Sum: '<S211>/Minus4'
         *  Sum: '<S211>/Minus5'
         */
        rtb_Switch2_hw = (rtb_Switch2_h * rtb_MatrixConcatenate_b_idx_0) +
          rtb_Minus_k_idx_0;

        /* Merge: '<S197>/Merge4' incorporates:
         *  Constant: '<S213>/Constant'
         *  DataTypeConversion: '<S203>/Data Type Conversion'
         *  DotProduct: '<S211>/Dot Product3'
         *  Logic: '<S211>/AND'
         *  RelationalOperator: '<S211>/LessThanOrEqual1'
         *  RelationalOperator: '<S213>/Compare'
         *  Sum: '<S203>/Add'
         *  Sum: '<S211>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_LogicalOperator5 &&
          rtb_Compare_pb) && (rtb_Switch2_hw >= 0.0)) && (rtb_Switch2_hw <=
          ((rtb_Switch2_h * rtb_Switch2_h) + rtb_Minus_k_idx_1)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S197>/Merge2' incorporates:
         *  Constant: '<S203>/Constant2'
         *  SignalConversion generated from: '<S203>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S203>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S203>/Constant1'
         */
        rtb_Compare_pb = false;

        /* End of Outputs for SubSystem: '<S200>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S200>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S201>/Action Port'
         */
        /* Merge: '<S197>/Merge2' incorporates:
         *  Constant: '<S201>/Constant2'
         *  SignalConversion generated from: '<S201>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S201>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S201>/Constant1'
         */
        rtb_Compare_pb = false;

        /* Merge: '<S197>/Merge4' incorporates:
         *  SignalConversion generated from: '<S201>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S200>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S197>/Merge1' incorporates:
       *  Constant: '<S200>/Constant'
       *  SignalConversion generated from: '<S200>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S200>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator1;

      /* End of Outputs for SubSystem: '<S197>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S197>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S199>/Action Port'
       */
      /* Merge: '<S197>/Merge1' incorporates:
       *  Constant: '<S199>/Constant'
       *  SignalConversion generated from: '<S199>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S197>/Merge2' incorporates:
       *  Constant: '<S199>/Constant1'
       *  SignalConversion generated from: '<S199>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator5 = false;

      /* SignalConversion generated from: '<S199>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S199>/Constant2'
       */
      rtb_Compare_pb = false;

      /* Merge: '<S197>/Merge4' incorporates:
       *  SignalConversion generated from: '<S199>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S197>/Escape_Auto_Driving' */
    }

    /* End of If: '<S197>/If' */

    /* If: '<S193>/If1' */
    if (!rtb_Compare_pb) {
      /* Outputs for IfAction SubSystem: '<S193>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S198>/Action Port'
       */
      /* Bias: '<S214>/Add Constant' incorporates:
       *  Bias: '<S214>/Bias'
       *  Sum: '<S214>/Subtract'
       */
      rtb_Switch1_n = ((Robot_Control_B.Spline_Num_Poses -
                        Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S214>/Selector4' incorporates:
       *  Bias: '<S214>/Bias1'
       *  Constant: '<S216>/FixPt Constant'
       *  Sum: '<S216>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S214>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S214>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s219_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S214>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S214>/Selector5' incorporates:
       *  Concatenate: '<S214>/Matrix Concatenate'
       *  Gain: '<S218>/Gain'
       *  Selector: '<S193>/Selector1'
       *  Selector: '<S214>/Selector2'
       *  Selector: '<S214>/Selector3'
       *  Sum: '<S218>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s219_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S214>/Matrix Concatenate' incorporates:
       *  Bias: '<S214>/Add Constant1'
       *  Gain: '<S217>/Gain'
       *  Selector: '<S193>/Selector1'
       *  Selector: '<S214>/Selector'
       *  Selector: '<S214>/Selector1'
       *  Selector: '<S214>/Selector5'
       *  Sum: '<S217>/Subtract'
       */
      s219_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s219_iter;
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

      /* Selector: '<S214>/Selector4' */
      s219_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s219_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S214>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S214>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S214>/Assignment' incorporates:
       *  Concatenate: '<S214>/Matrix Concatenate'
       *  Selector: '<S214>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s219_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S215>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S219>/While Iterator'
       */
      s219_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s219_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s219_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s219_iter] - rtb_Assignment[s219_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Init - rtb_Assignment[s219_iter];
        rtb_Init = rtb_Assignment[s219_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s219_iter + 11];
        rtb_Minus_f = rtb_Assignment[s219_iter + 12];
        rtb_Add2[1] = rtb_Minus_f - rtb_Assignment[s219_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Init - rtb_Minus_f;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Switch2_hw = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Init_o = rt_powd_snf(rtb_Switch2_hw, 2.0);
          rtb_Switch2_h = rt_powd_snf(rtb_Switch2_hw, 3.0);
          rtb_Sin4 = (rtb_Switch2_hw - (2.0 * rtb_Init_o)) + rtb_Switch2_h;
          rtb_Init = rtb_Init_o - rtb_Switch2_h;
          rtb_Switch2_h = (3.0 * rtb_Init_o) - (2.0 * rtb_Switch2_h);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Sin4) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Switch2_h)) + rtb_Assignment[s219_iter];
          rtb_Switch2_h = ((((rtb_Minus_n[1] * rtb_Sin4) + (rtb_Add2[1] *
            rtb_Init)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_h)) +
            rtb_Minus_f;
          rtb_Sin4 = ((3.0 * rtb_Init_o) - (4.0 * rtb_Switch2_hw)) + 1.0;
          rtb_Init = (2.0 * rtb_Switch2_hw) - (3.0 * rtb_Init_o);
          rtb_Init_o = (rtb_Switch2_hw - rtb_Init_o) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Sin4) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Init_o);
          rtb_Add_i = (((rtb_Minus_n[1] * rtb_Sin4) + (rtb_Add2[1] * rtb_Init)) *
                       0.5) + (rtb_Minus_k_idx_1 * rtb_Init_o);
          rtb_Init_o = (6.0 * rtb_Switch2_hw) - 4.0;
          rtb_Sin4 = (-6.0 * rtb_Switch2_hw) + 2.0;
          rtb_Switch2_hw = (-12.0 * rtb_Switch2_hw) + 6.0;
          rtb_Init = (((rtb_Minus_n[0] * rtb_Init_o) + (rtb_Add2[0] * rtb_Sin4))
                      * 0.5) + (rtb_Minus_k_idx_0 * rtb_Switch2_hw);
          rtb_Sin4 = (((rtb_Minus_n[1] * rtb_Init_o) + (rtb_Add2[1] * rtb_Sin4))
                      * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_hw);
          rtb_Init_o = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Add_i), 3.0);
          rtb_Switch2_hw = fmax(1.0E-10, rtb_Init_o);
          Robot_Control_DW.Relay_Mode = ((rtb_Init_o >= 2.2204460492503131E-16) ||
            (Robot_Control_DW.Relay_Mode));
          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Switch2_h;
          if (Robot_Control_DW.Relay_Mode) {
            i = 1;
          } else {
            i = -1;
          }

          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Sin4) - (rtb_Init * rtb_Add_i)) /
            (rtb_Switch2_hw * ((real_T)i));
        }

        if (s219_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s219_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Switch2_hw = rtb_Switch1_n - ((real_T)s219_iter);
        rtb_Num_Segments = s219_iter;
        s219_iter++;
      } while ((rtb_Switch2_hw >= 4.0) && (s219_iter <= 3));

      /* End of Outputs for SubSystem: '<S215>/Sampling_Loop' */

      /* SignalConversion generated from: '<S198>/Position_and_Curvature' incorporates:
       *  Assignment: '<S219>/Assignment'
       *  Merge: '<S193>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S193>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S193>/If Action Subsystem' incorporates:
       *  ActionPort: '<S196>/Action Port'
       */
      /* Product: '<S196>/Product' incorporates:
       *  Selector: '<S193>/Selector'
       *  Selector: '<S193>/Selector1'
       */
      rtb_Switch2_hw = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S196>/Product1' incorporates:
       *  Selector: '<S193>/Selector'
       *  Selector: '<S193>/Selector1'
       */
      rtb_Switch1_n = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S196>/Product' incorporates:
         *  Constant: '<S196>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Switch2_hw;

        /* Product: '<S196>/Product1' incorporates:
         *  Constant: '<S196>/Constant2'
         *  Product: '<S196>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch1_n;
      }

      /* Assignment: '<S196>/Assignment' incorporates:
       *  Concatenate: '<S196>/Matrix Concatenate'
       *  Merge: '<S193>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S196>/Assignment' */

      /* SignalConversion generated from: '<S196>/Num_Segments' incorporates:
       *  Constant: '<S196>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S193>/If Action Subsystem' */
    }

    /* End of If: '<S193>/If1' */

    /* Concatenate: '<S194>/Matrix Concatenate' incorporates:
     *  Merge: '<S193>/Merge'
     *  Selector: '<S194>/Selector'
     *  Selector: '<S194>/Selector1'
     *  Selector: '<S194>/Selector3'
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

    /* End of Concatenate: '<S194>/Matrix Concatenate' */

    /* MATLAB Function: '<S194>/Distance Along Curve' incorporates:
     *  Concatenate: '<S194>/Matrix Concatenate'
     *  Selector: '<S194>/Selector4'
     *  Selector: '<S194>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s219_iter = 0; s219_iter < 149; s219_iter++) {
      /* Outputs for Iterator SubSystem: '<S215>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S219>/While Iterator'
       */
      rtb_Assignment_d[s219_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s219_iter + 1] -
         rtb_MatrixConcatenate_o[s219_iter], rtb_MatrixConcatenate_o[s219_iter +
         151] - rtb_MatrixConcatenate_o[s219_iter + 150]) +
        rtb_Assignment_d[s219_iter];

      /* End of Outputs for SubSystem: '<S215>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S194>/Distance Along Curve' */

    /* MATLAB Function: '<S194>/Find closest index to curve' incorporates:
     *  Concatenate: '<S194>/Matrix Concatenate'
     *  Selector: '<S194>/Selector4'
     *  Selector: '<S194>/Selector5'
     *  Selector: '<S245>/Selector'
     */
    for (s219_iter = 0; s219_iter < 150; s219_iter++) {
      /* Outputs for Iterator SubSystem: '<S215>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S219>/While Iterator'
       */
      distance_from_robot[s219_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s219_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s219_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S215>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s219_iter = 1;
    } else {
      s219_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s219_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s219_iter == 0) {
      rtb_Switch1_n = distance_from_robot[0];
    } else {
      rtb_Switch1_n = distance_from_robot[s219_iter - 1];
      for (rtb_Bias1_p = s219_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Switch2_hw = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_n > rtb_Switch2_hw) {
          rtb_Switch1_n = rtb_Switch2_hw;
        }
      }
    }

    s219_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s219_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_n) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S245>/Selector' incorporates:
     *  Constant: '<S245>/Constant'
     *  MATLAB Function: '<S194>/Find closest index to curve'
     *  MinMax: '<S245>/Min'
     */
    rtb_Switch2_hw = rtb_Assignment_d[((int32_T)fmin(50.0, s219_iter)) - 1];

    /* If: '<S245>/If' incorporates:
     *  RelationalOperator: '<S245>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S245>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S248>/Action Port'
       */
      /* SignalConversion generated from: '<S248>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S250>/FixPt Sum1' incorporates:
       *  Constant: '<S250>/FixPt Constant'
       */
      rtb_Switch1_n = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S248>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S248>/Selector11'
       *  Selector: '<S248>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S248>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S248>/Selector1'
       *  Selector: '<S248>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S248>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S248>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_n), &rtb_Minus_n[0], rtb_Switch2_hw,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S248>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S248>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S248>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Switch2_hw,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S245>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S245>/Latch' incorporates:
       *  ActionPort: '<S249>/Action Port'
       */
      /* SignalConversion generated from: '<S249>/In1' incorporates:
       *  UnitDelay: '<S245>/Unit Delay1'
       */
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S249>/In2' incorporates:
       *  UnitDelay: '<S245>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S245>/Latch' */
    }

    /* End of If: '<S245>/If' */

    /* MinMax: '<S192>/Min' incorporates:
     *  Lookup_n-D: '<S192>/Lookahead Distance'
     *  UnitDelay: '<S192>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S194>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S244>/While Iterator'
     */
    s244_iter = 1U;
    rtb_LogicalOperator1 = true;
    while (rtb_LogicalOperator1 && (s244_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S194>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S244>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s244_iter;
      rtb_LogicalOperator1 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s219_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s244_iter++;
    }

    /* End of Outputs for SubSystem: '<S194>/Find first index that meets distance target' */

    /* Switch: '<S247>/Switch' incorporates:
     *  Concatenate: '<S194>/Matrix Concatenate'
     *  Constant: '<S194>/Constant'
     *  Constant: '<S244>/Constant'
     *  Constant: '<S247>/Constant'
     *  Constant: '<S247>/Constant1'
     *  Constant: '<S247>/Constant2'
     *  Constant: '<S247>/Constant3'
     *  Logic: '<S244>/AND'
     *  MATLAB Function: '<S194>/Find closest index to curve'
     *  Math: '<S247>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S247>/Max'
     *  MinMax: '<S247>/Min'
     *  MinMax: '<S247>/Min1'
     *  Product: '<S244>/Product'
     *  Product: '<S247>/Divide'
     *  Product: '<S247>/Product'
     *  Product: '<S247>/Product1'
     *  RelationalOperator: '<S194>/Relational Operator'
     *  RelationalOperator: '<S244>/Relational Operator'
     *  RelationalOperator: '<S244>/Relational Operator1'
     *  Selector: '<S194>/Selector10'
     *  Selector: '<S194>/Selector7'
     *  Selector: '<S194>/Selector8'
     *  Selector: '<S194>/Selector9'
     *  Selector: '<S244>/Selector'
     *  Selector: '<S244>/Selector1'
     *  Selector: '<S245>/Selector'
     *  Sqrt: '<S247>/Sqrt'
     *  Sum: '<S194>/Subtract'
     *  Sum: '<S244>/Add'
     *  Sum: '<S247>/Subtract'
     *  Sum: '<S247>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Saturation_h = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Switch1_n *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Saturation_h = fmin(rtb_Switch1_n * Spline_Velocity_Multiplier_TEST,
        sqrt(Spline_Max_Centripital_Acceleration / fmax
             (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299],
              1.0E-5)));
    }

    /* End of Switch: '<S247>/Switch' */

    /* Logic: '<S195>/OR' */
    rtb_Compare_pb = (rtb_LogicalOperator5 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S195>/Switch1' incorporates:
     *  Switch: '<S195>/Switch'
     *  UnitDelay: '<S195>/Unit Delay'
     */
    if (rtb_Compare_pb) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S195>/Constant3'
       *  SignalConversion: '<S195>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Switch2_hw = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S195>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Switch2_hw = rtb_Merge1;
    }

    /* End of Switch: '<S195>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S195>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Switch2_hw;

    /* Selector: '<S194>/Selector6' incorporates:
     *  Concatenate: '<S194>/Matrix Concatenate'
     *  Selector: '<S194>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S194>/Selector2' incorporates:
     *  Concatenate: '<S194>/Matrix Concatenate'
     *  Selector: '<S194>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S195>/Switch2' incorporates:
     *  Sum: '<S251>/Subtract'
     *  Sum: '<S251>/Subtract1'
     *  Trigonometry: '<S251>/Atan2'
     *  UnitDelay: '<S195>/Unit Delay1'
     */
    if (rtb_Compare_pb) {
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Init_o = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S195>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S195>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Init_o;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S192>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator5;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S192>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S195>/Constant2'
     *  SignalConversion generated from: '<S192>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S195>/Constant5'
     *  SignalConversion generated from: '<S192>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S195>/Constant6'
     *  SignalConversion generated from: '<S192>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S192>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S193>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S192>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S245>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_n;

    /* Update for UnitDelay: '<S245>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S195>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Switch2_hw;

    /* Update for UnitDelay: '<S195>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Init_o;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S191>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S191>/Constant1'
     *  SignalConversion generated from: '<S191>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S191>/Constant'
     *  SignalConversion generated from: '<S191>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S191>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S191>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S191>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S191>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S191>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S191>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S191>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S341>/Sign2' incorporates:
   *  UnitDelay: '<S341>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Minus_f = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Minus_f = -1.0;
  } else {
    rtb_Minus_f = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S341>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_pv = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S341>/Product1' incorporates:
   *  Signum: '<S341>/Sign1'
   *  Signum: '<S341>/Sign2'
   */
  rtb_Minus_f *= rtb_Add_pv;
  if (rtIsNaN(rtb_Minus_f)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_f, 256.0);
  }

  /* Switch: '<S341>/Switch' incorporates:
   *  Constant: '<S341>/Constant'
   *  Constant: '<S346>/Constant'
   *  Constant: '<S347>/Constant'
   *  Logic: '<S341>/or'
   *  Product: '<S341>/Product1'
   *  RelationalOperator: '<S346>/Compare'
   *  RelationalOperator: '<S347>/Compare'
   *  UnitDelay: '<S341>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S341>/Switch' */

  /* Switch: '<S352>/Init' incorporates:
   *  UnitDelay: '<S352>/FixPt Unit Delay1'
   *  UnitDelay: '<S352>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S352>/Init' */

  /* RelationalOperator: '<S348>/Compare' incorporates:
   *  Constant: '<S348>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S349>/Compare' incorporates:
   *  Constant: '<S349>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Sin4 > 0.0);

  /* Abs: '<S341>/Abs' incorporates:
   *  Sum: '<S341>/Subtract'
   *  UnitDelay: '<S341>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S341>/Switch5' incorporates:
   *  Constant: '<S341>/Constant1'
   *  Switch: '<S341>/Switch1'
   *  UnaryMinus: '<S341>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S341>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S341>/Constant4'
     *  Constant: '<S341>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S341>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S341>/Constant2'
     *  Constant: '<S341>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S341>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S341>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S341>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S341>/Constant10'
     *  Constant: '<S341>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S341>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S341>/Constant7'
     *  Constant: '<S341>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S341>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S341>/Lookup Table Dynamic1'
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

    /* Switch: '<S341>/Switch3' incorporates:
     *  Constant: '<S341>/Constant1'
     *  Constant: '<S341>/Constant3'
     *  UnaryMinus: '<S341>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      rtb_Minus_f = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Minus_f = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S341>/Switch3' */
  }

  /* End of Switch: '<S341>/Switch5' */

  /* Product: '<S341>/Product' incorporates:
   *  Switch: '<S341>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Minus_f * rtb_Merge1;

  /* Sum: '<S350>/Sum1' */
  rtb_Saturation_h = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S351>/Switch2' incorporates:
   *  RelationalOperator: '<S351>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S341>/Switch2' incorporates:
     *  Constant: '<S341>/Constant1'
     *  Switch: '<S341>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S341>/Switch4' incorporates:
       *  Constant: '<S341>/Constant1'
       */
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S341>/Switch4' incorporates:
       *  Constant: '<S341>/Constant3'
       *  UnaryMinus: '<S341>/Unary Minus1'
       */
      rtb_Switch1_n = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S341>/Switch2' */

    /* Product: '<S341>/Product2' */
    rtb_Switch1_n *= rtb_Merge1;

    /* Switch: '<S351>/Switch' incorporates:
     *  RelationalOperator: '<S351>/UpperRelop'
     */
    if (rtb_Saturation_h < rtb_Switch1_n) {
      rtb_Optimized_Module_Angle = rtb_Switch1_n;
    } else {
      rtb_Optimized_Module_Angle = rtb_Saturation_h;
    }

    /* End of Switch: '<S351>/Switch' */
  }

  /* End of Switch: '<S351>/Switch2' */

  /* Sum: '<S350>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S344>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S344>/Switch' incorporates:
     *  Constant: '<S378>/Constant3'
     *  Constant: '<S378>/Constant4'
     *  Math: '<S378>/Math Function'
     *  Sum: '<S344>/Subtract'
     *  Sum: '<S378>/Add1'
     *  Sum: '<S378>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S344>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S344>/Switch' */

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

  /* Switch: '<S173>/Switch' incorporates:
   *  Constant: '<S161>/Constant'
   *  Constant: '<S173>/Constant'
   *  RelationalOperator: '<S161>/Compare'
   *  UnitDelay: '<S173>/Unit Delay'
   */
  if (rtb_GameState != 1) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_o;
  }

  /* Sum: '<S173>/Sum' incorporates:
   *  Constant: '<S173>/Constant4'
   *  Switch: '<S173>/Switch'
   */
  rtb_Merge1 = rtb_Minus_f + 0.02;

  /* Switch: '<S174>/Switch' incorporates:
   *  Constant: '<S166>/Constant'
   *  Constant: '<S174>/Constant'
   *  RelationalOperator: '<S166>/Compare'
   *  UnitDelay: '<S174>/Unit Delay'
   */
  if (rtb_GameState != 2) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_m;
  }

  /* MultiPortSwitch: '<S133>/Multiport Switch' incorporates:
   *  Constant: '<S133>/Constant1'
   *  Constant: '<S133>/Constant3'
   *  Constant: '<S174>/Constant4'
   *  Sum: '<S174>/Sum'
   *  Switch: '<S174>/Switch'
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
   *  Constant: '<S159>/Constant'
   *  Constant: '<S160>/Constant'
   *  Constant: '<S162>/Constant'
   *  Constant: '<S163>/Constant'
   *  Constant: '<S164>/Constant'
   *  Constant: '<S165>/Constant'
   *  Inport: '<Root>/IsBlueAlliance'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S159>/Compare'
   *  RelationalOperator: '<S160>/Compare'
   *  RelationalOperator: '<S162>/Compare'
   *  RelationalOperator: '<S163>/Compare'
   *  RelationalOperator: '<S164>/Compare'
   *  RelationalOperator: '<S165>/Compare'
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
       *  ActionPort: '<S167>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S167>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S167>/Constant'
     *  SignalConversion generated from: '<S167>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S133>/Merge1' incorporates:
     *  Constant: '<S167>/Constant'
     *  SignalConversion generated from: '<S167>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S167>/Sum' incorporates:
     *  Constant: '<S167>/Constant1'
     *  UnitDelay: '<S167>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hb - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S167>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S167>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S168>/Action Port'
       */
      /* SystemReset for If: '<S133>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem1);

      /* End of SystemReset for SubSystem: '<S133>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S168>/Action Port'
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
       *  ActionPort: '<S169>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S169>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem2' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    /* Sum: '<S169>/Sum' incorporates:
     *  Constant: '<S169>/Constant1'
     *  UnitDelay: '<S169>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hz - 0.02;

    /* RelationalOperator: '<S176>/Compare' incorporates:
     *  Constant: '<S176>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S133>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S169>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S133>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S169>/Logical Operator1'
     *  Logic: '<S169>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S169>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S169>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S169>/Constant2'
       *  Sum: '<S169>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S133>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;
    }

    /* End of Switch: '<S169>/Switch' */

    /* Update for UnitDelay: '<S169>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hz = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem2' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S170>/Action Port'
       */
      /* SystemReset for If: '<S133>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem3);

      /* End of SystemReset for SubSystem: '<S133>/If Action Subsystem3' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S170>/Action Port'
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
       *  ActionPort: '<S171>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S171>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem4' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    /* Sum: '<S171>/Sum' incorporates:
     *  Constant: '<S171>/Constant1'
     *  UnitDelay: '<S171>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_di - 0.02;

    /* RelationalOperator: '<S178>/Compare' incorporates:
     *  Constant: '<S178>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S133>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S171>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S133>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S171>/Logical Operator1'
     *  Logic: '<S171>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S171>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S171>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S171>/Constant2'
       *  Sum: '<S171>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S133>/Merge2' incorporates:
       *  Constant: '<S171>/Constant3'
       *  Sum: '<S171>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S171>/Switch' */

    /* Update for UnitDelay: '<S171>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem4' */
    break;

   default:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S133>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S172>/Action Port'
       */
      /* InitializeConditions for If: '<S133>/If' incorporates:
       *  UnitDelay: '<S172>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

      /* End of InitializeConditions for SubSystem: '<S133>/If Action Subsystem5' */
    }

    /* Outputs for IfAction SubSystem: '<S133>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S172>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S172>/Constant'
     *  SignalConversion generated from: '<S172>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S133>/Merge1' incorporates:
     *  Constant: '<S172>/Constant'
     *  SignalConversion generated from: '<S172>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S172>/Sum' incorporates:
     *  Constant: '<S172>/Constant1'
     *  UnitDelay: '<S172>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_du - 0.02;

    /* Merge: '<S133>/Merge2' incorporates:
     *  SignalConversion: '<S172>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S172>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_du = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S133>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S133>/If' */

  /* If: '<S180>/If' incorporates:
   *  If: '<S181>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S180>/Blue' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    /* Merge: '<S180>/Merge' incorporates:
     *  Constant: '<S182>/BlueAllianceZoneX'
     *  Logic: '<S182>/AND'
     *  RelationalOperator: '<S182>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S180>/Blue' */

    /* Outputs for IfAction SubSystem: '<S181>/Blue' incorporates:
     *  ActionPort: '<S184>/Action Port'
     */
    /* Merge: '<S181>/Merge' incorporates:
     *  Constant: '<S184>/BlueAllianceZoneX'
     *  RelationalOperator: '<S184>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S181>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S180>/Red' incorporates:
     *  ActionPort: '<S183>/Action Port'
     */
    /* Merge: '<S180>/Merge' incorporates:
     *  Constant: '<S183>/RedAllianceZoneX'
     *  Logic: '<S183>/AND'
     *  RelationalOperator: '<S183>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S180>/Red' */

    /* Outputs for IfAction SubSystem: '<S181>/Red' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    /* Merge: '<S181>/Merge' incorporates:
     *  Constant: '<S185>/RedAllianceZoneX'
     *  RelationalOperator: '<S185>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S181>/Red' */
  }

  /* End of If: '<S180>/If' */

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
   *  Constant: '<S179>/Constant3'
   *  Constant: '<S179>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S179>/Math Function'
   *  Sum: '<S136>/Subtract'
   *  Sum: '<S179>/Add1'
   *  Sum: '<S179>/Add2'
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
     *  Logic: '<S147>/Logical Operator'
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
    if ((Robot_Control_B.Is_Outside_Alliance_Zone) || rtb_LogicalOperator1) {
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
    rtb_Switch1_n = 0.0;
    rtb_Switch2_hw = 0.0;
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
      /* Switch: '<S152>/Switch' incorporates:
       *  Memory: '<S143>/Memory1'
       *  Memory: '<S143>/Memory2'
       *  Switch: '<S152>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Switch1_n;
        rtb_Init = rtb_Switch2_hw;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Init = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S152>/Switch' */

      /* Math: '<S150>/Hypot' incorporates:
       *  Sum: '<S150>/Subtract'
       *  Sum: '<S150>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_Init - Robot_Control_B.KF_Position_Y);

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
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Init;

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
        rtb_Sin4, Robot_Control_B.RB_Desired_Target_Y - rtb_Init) >=
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
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    if (rtb_Switch1_n < Rebuilt_Shot_Init_Time) {
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
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S132>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_pv = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Add_i = Robot_Control_U.Gyro_Angle_Field_rad;
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
    rtb_Add_pv = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Add_i = Robot_Control_B.Gyro_Angle_SPF;
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
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_pv - rtb_Add_i) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Gain: '<S376>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle_p;

  /* Abs: '<S355>/Abs1' */
  rtb_Init_o = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S375>/Sum1' incorporates:
   *  Constant: '<S372>/Constant2'
   *  Product: '<S375>/Product'
   *  Sum: '<S375>/Sum'
   *  UnitDelay: '<S375>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Optimized_Module_Angle_p -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S372>/Product' incorporates:
   *  Constant: '<S372>/Constant3'
   */
  rtb_Switch1_n = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

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
  rtb_Add_pv = rtb_Switch1_n - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S372>/Saturation' */
  if (rtb_Add_pv > Steering_Heading_Control_D_UL) {
    rtb_Add_pv = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Heading_Control_D_LL) {
    rtb_Add_pv = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S372>/Add' incorporates:
   *  Gain: '<S372>/Gain1'
   *  Saturate: '<S372>/Saturation'
   */
  rtb_Init = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_pv;

  /* Sum: '<S372>/Subtract' incorporates:
   *  Constant: '<S372>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Init;

  /* Sum: '<S372>/Sum2' incorporates:
   *  Gain: '<S372>/Gain2'
   *  UnitDelay: '<S372>/Unit Delay'
   */
  rtb_Switch2_hw = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S377>/Switch2' incorporates:
   *  RelationalOperator: '<S377>/LowerRelop1'
   */
  if (!(rtb_Switch2_hw > rtb_Sin4)) {
    /* Sum: '<S372>/Subtract1' incorporates:
     *  Constant: '<S372>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Init;

    /* Switch: '<S377>/Switch' incorporates:
     *  RelationalOperator: '<S377>/UpperRelop'
     */
    if (!(rtb_Switch2_hw < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2_hw;
    }

    /* End of Switch: '<S377>/Switch' */
  }

  /* End of Switch: '<S377>/Switch2' */

  /* Saturate: '<S372>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Switch2_hw = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Switch2_hw = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch2_hw = rtb_Sin4;
  }

  /* End of Saturate: '<S372>/Saturation1' */

  /* Sum: '<S372>/Add1' */
  rtb_Add_pv = rtb_Init + rtb_Switch2_hw;

  /* Saturate: '<S372>/Saturation2' */
  if (rtb_Add_pv > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S372>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_pv < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S372>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S372>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_pv;
  }

  /* End of Saturate: '<S372>/Saturation2' */

  /* Abs: '<S355>/Abs' */
  rtb_Sin4 = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S355>/Add dither' */
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

  /* End of Chart: '<S355>/Add dither' */

  /* Switch: '<S355>/Switch' incorporates:
   *  Constant: '<S355>/Constant'
   *  Constant: '<S371>/Constant'
   *  Product: '<S355>/Product'
   *  RelationalOperator: '<S371>/Compare'
   *  Signum: '<S355>/Sign'
   */
  if (rtb_Sin4 > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S355>/Sign' */
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

  /* End of Switch: '<S355>/Switch' */

  /* Signum: '<S354>/Sign2' incorporates:
   *  UnitDelay: '<S354>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_pv = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S354>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Add_i = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S354>/Product1' incorporates:
   *  Signum: '<S354>/Sign1'
   *  Signum: '<S354>/Sign2'
   */
  rtb_Add_pv *= rtb_Add_i;
  if (rtIsNaN(rtb_Add_pv)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_pv, 256.0);
  }

  /* Switch: '<S354>/Switch' incorporates:
   *  Constant: '<S354>/Constant'
   *  Constant: '<S363>/Constant'
   *  Constant: '<S364>/Constant'
   *  Logic: '<S354>/or'
   *  Product: '<S354>/Product1'
   *  RelationalOperator: '<S363>/Compare'
   *  RelationalOperator: '<S364>/Compare'
   *  UnitDelay: '<S354>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S354>/Switch' */

  /* Switch: '<S369>/Init' incorporates:
   *  UnitDelay: '<S369>/FixPt Unit Delay1'
   *  UnitDelay: '<S369>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S369>/Init' */

  /* RelationalOperator: '<S365>/Compare' incorporates:
   *  Constant: '<S365>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S366>/Compare' incorporates:
   *  Constant: '<S366>/Constant'
   */
  rtb_Compare_mq = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S354>/Abs' incorporates:
   *  Sum: '<S354>/Subtract'
   *  UnitDelay: '<S354>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S354>/Switch5' incorporates:
   *  Constant: '<S354>/Constant1'
   *  Switch: '<S354>/Switch1'
   *  UnaryMinus: '<S354>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    /* SignalConversion generated from: '<S354>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S354>/Constant4'
     *  Constant: '<S354>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S354>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S354>/Constant2'
     *  Constant: '<S354>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S354>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S354>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S354>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S354>/Constant10'
     *  Constant: '<S354>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S354>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S354>/Constant7'
     *  Constant: '<S354>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S354>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S354>/Lookup Table Dynamic1'
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

    /* Switch: '<S354>/Switch3' incorporates:
     *  Constant: '<S354>/Constant1'
     *  Constant: '<S354>/Constant3'
     *  UnaryMinus: '<S354>/Unary Minus'
     */
    if (rtb_Compare_mq) {
      rtb_Add_pv = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_pv = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S354>/Switch3' */
  }

  /* End of Switch: '<S354>/Switch5' */

  /* Product: '<S354>/Product' incorporates:
   *  Switch: '<S354>/Switch1'
   */
  rtb_Saturation_h = rtb_Add_pv * rtb_Sin4;

  /* Sum: '<S367>/Sum1' */
  rtb_Init = rtb_MatrixConcatenate_b_idx_0 - rtb_Init_o;

  /* Switch: '<S368>/Switch2' incorporates:
   *  RelationalOperator: '<S368>/LowerRelop1'
   */
  if (!(rtb_Init > rtb_Saturation_h)) {
    /* Switch: '<S354>/Switch2' incorporates:
     *  Constant: '<S354>/Constant1'
     *  Constant: '<S354>/Constant3'
     *  Switch: '<S354>/Switch4'
     *  UnaryMinus: '<S354>/Unary Minus1'
     */
    if (rtb_Compare_ky) {
      rtb_Add_pv = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Compare_mq) {
      /* Switch: '<S354>/Switch4' incorporates:
       *  Constant: '<S354>/Constant1'
       */
      rtb_Add_pv = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_pv = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S354>/Product2' incorporates:
     *  Switch: '<S354>/Switch2'
     */
    rtb_Switch2_h = rtb_Add_pv * rtb_Sin4;

    /* Switch: '<S368>/Switch' incorporates:
     *  RelationalOperator: '<S368>/UpperRelop'
     */
    if (rtb_Init < rtb_Switch2_h) {
      rtb_Saturation_h = rtb_Switch2_h;
    } else {
      rtb_Saturation_h = rtb_Init;
    }

    /* End of Switch: '<S368>/Switch' */
  }

  /* End of Switch: '<S368>/Switch2' */

  /* Sum: '<S367>/Sum' */
  rtb_Init_o += rtb_Saturation_h;

  /* Signum: '<S353>/Sign2' incorporates:
   *  UnitDelay: '<S353>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_pv = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S353>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S353>/Product1' incorporates:
   *  Signum: '<S353>/Sign1'
   *  Signum: '<S353>/Sign2'
   */
  rtb_Add_pv *= rtb_Add_i;
  if (rtIsNaN(rtb_Add_pv)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_pv, 256.0);
  }

  /* Switch: '<S353>/Switch' incorporates:
   *  Constant: '<S353>/Constant'
   *  Constant: '<S356>/Constant'
   *  Constant: '<S357>/Constant'
   *  Logic: '<S353>/or'
   *  Product: '<S353>/Product1'
   *  RelationalOperator: '<S356>/Compare'
   *  RelationalOperator: '<S357>/Compare'
   *  UnitDelay: '<S353>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S353>/Switch' */

  /* Switch: '<S362>/Init' incorporates:
   *  UnitDelay: '<S362>/FixPt Unit Delay1'
   *  UnitDelay: '<S362>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S362>/Init' */

  /* RelationalOperator: '<S358>/Compare' incorporates:
   *  Constant: '<S358>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S359>/Compare' incorporates:
   *  Constant: '<S359>/Constant'
   */
  rtb_Compare_mq = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S353>/Abs' incorporates:
   *  Sum: '<S353>/Subtract'
   *  UnitDelay: '<S353>/Unit Delay'
   */
  rtb_Init = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                  Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S353>/Switch1' incorporates:
   *  Constant: '<S353>/Constant1'
   *  Switch: '<S353>/Switch3'
   *  Switch: '<S353>/Switch5'
   *  UnaryMinus: '<S353>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S353>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S353>/Constant1'
     *  Constant: '<S353>/Constant4'
     *  Constant: '<S353>/Constant6'
     *  UnaryMinus: '<S353>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S353>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S353>/Constant2'
     *  Constant: '<S353>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S353>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S353>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_Init, &rtb_Minus_n[0], 1U);
    rtb_Init = rtb_LookupTableDynamic_p;
  } else {
    if (rtb_Compare_mq) {
      /* Switch: '<S353>/Switch3' incorporates:
       *  Constant: '<S353>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S353>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S353>/Constant1'
     *  Constant: '<S353>/Constant10'
     *  Constant: '<S353>/Constant8'
     *  UnaryMinus: '<S353>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S353>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S353>/Constant7'
     *  Constant: '<S353>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S353>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S353>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_Init, &rtb_Minus_n[0], 1U);
    rtb_Init = rtb_LookupTableDynamic1_g;
  }

  /* End of Switch: '<S353>/Switch1' */

  /* Product: '<S353>/Product' */
  rtb_Sin4 *= rtb_Init;

  /* Sum: '<S360>/Sum1' */
  rtb_Switch2_h = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S361>/Switch2' incorporates:
   *  RelationalOperator: '<S361>/LowerRelop1'
   */
  if (!(rtb_Switch2_h > rtb_Sin4)) {
    /* Switch: '<S353>/Switch2' incorporates:
     *  Constant: '<S353>/Constant1'
     *  Switch: '<S353>/Switch4'
     */
    if (rtb_Compare_ky) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Compare_mq) {
      /* Switch: '<S353>/Switch4' incorporates:
       *  Constant: '<S353>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S353>/Switch4' incorporates:
       *  Constant: '<S353>/Constant3'
       *  UnaryMinus: '<S353>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S353>/Switch2' */

    /* Product: '<S353>/Product2' */
    rtb_Sin4 *= rtb_Init;

    /* Switch: '<S361>/Switch' incorporates:
     *  RelationalOperator: '<S361>/UpperRelop'
     */
    if (!(rtb_Switch2_h < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2_h;
    }

    /* End of Switch: '<S361>/Switch' */
  }

  /* End of Switch: '<S361>/Switch2' */

  /* Sum: '<S360>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S343>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S343>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S343>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S343>/Switch' */

  /* Fcn: '<S386>/r->x' incorporates:
   *  Fcn: '<S391>/r->x'
   *  Fcn: '<S396>/r->x'
   *  Fcn: '<S401>/r->x'
   */
  rtb_Switch2_h = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S380>/Add' incorporates:
   *  Fcn: '<S386>/r->x'
   *  Fcn: '<S387>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2_h;

  /* Fcn: '<S386>/theta->y' incorporates:
   *  Fcn: '<S391>/theta->y'
   *  Fcn: '<S396>/theta->y'
   *  Fcn: '<S401>/theta->y'
   */
  rtb_Init = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S380>/Add' incorporates:
   *  Fcn: '<S386>/theta->y'
   *  Fcn: '<S387>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S381>/Add' incorporates:
   *  Fcn: '<S392>/r->x'
   *  Fcn: '<S392>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2_h;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S382>/Add' incorporates:
   *  Fcn: '<S397>/r->x'
   *  Fcn: '<S397>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2_h;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S383>/Add' incorporates:
   *  Fcn: '<S402>/r->x'
   *  Fcn: '<S402>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2_h;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Init;

  /* Fcn: '<S400>/x->r' */
  rtb_Saturation_h = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S403>/Compare' incorporates:
   *  Constant: '<S403>/Constant'
   */
  rtb_Compare_pb = (rtb_Saturation_h == 0.0);

  /* Switch: '<S399>/Switch1' */
  if (rtb_Compare_pb) {
    /* Switch: '<S399>/Switch1' incorporates:
     *  Constant: '<S399>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S399>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Saturation_h;
  }

  /* End of Switch: '<S399>/Switch1' */

  /* Fcn: '<S385>/x->r' */
  rtb_Saturation_h = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S388>/Compare' incorporates:
   *  Constant: '<S388>/Constant'
   */
  rtb_Compare_mq = (rtb_Saturation_h == 0.0);

  /* Switch: '<S384>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S384>/Switch1' incorporates:
     *  Constant: '<S384>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S384>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Saturation_h;
  }

  /* End of Switch: '<S384>/Switch1' */

  /* Fcn: '<S390>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S393>/Compare' incorporates:
   *  Constant: '<S393>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S389>/Switch1' */
  if (rtb_Compare_ky) {
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
  rtb_LogicalOperator1 = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S394>/Switch1' */
  if (rtb_LogicalOperator1) {
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
  rtb_Saturation_h = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S379>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Saturation_h;

  /* Switch: '<S399>/Switch' */
  if (!rtb_Compare_pb) {
    /* Switch: '<S399>/Switch' incorporates:
     *  Fcn: '<S400>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S399>/Switch' */

  /* Trigonometry: '<S333>/Cos4' incorporates:
   *  Switch: '<S322>/Angle_Switch'
   *  Trigonometry: '<S332>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S333>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S331>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S333>/Sin4' incorporates:
   *  Switch: '<S322>/Angle_Switch'
   *  Trigonometry: '<S332>/Sin4'
   */
  rtb_Init = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S333>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S331>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S333>/Subtract1' incorporates:
   *  Product: '<S333>/Product2'
   *  Product: '<S333>/Product3'
   *  Trigonometry: '<S333>/Cos4'
   *  Trigonometry: '<S333>/Sin4'
   */
  rtb_Switch2_h = (rtb_Add_i * rtb_Optimized_Module_Angle) + (rtb_Init *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S333>/Subtract' incorporates:
   *  Product: '<S333>/Product'
   *  Product: '<S333>/Product1'
   *  Trigonometry: '<S333>/Cos4'
   *  Trigonometry: '<S333>/Sin4'
   */
  rtb_Minus_k_idx_1 = (rtb_Add_i * rtb_Optimized_Module_Angle_p) - (rtb_Init *
    rtb_Optimized_Module_Angle);

  /* Math: '<S333>/Hypot' */
  rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Minus_k_idx_1, rtb_Switch2_h);

  /* Switch: '<S333>/Switch' incorporates:
   *  Constant: '<S333>/Constant'
   *  Constant: '<S333>/Constant1'
   *  Constant: '<S334>/Constant'
   *  Product: '<S333>/Divide'
   *  Product: '<S333>/Divide1'
   *  RelationalOperator: '<S334>/Compare'
   *  Switch: '<S333>/Switch1'
   */
  if (rtb_Minus_k_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_h / rtb_Minus_k_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Minus_k_idx_1 / rtb_Minus_k_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S333>/Switch' */

  /* Switch: '<S322>/Speed_Switch' incorporates:
   *  Abs: '<S322>/Abs'
   *  Constant: '<S330>/Constant'
   *  RelationalOperator: '<S330>/Compare'
   *  Switch: '<S322>/Angle_Switch'
   *  Trigonometry: '<S332>/Atan1'
   *  Trigonometry: '<S333>/Atan1'
   *  UnaryMinus: '<S322>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_pv = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S332>/Subtract1' incorporates:
     *  Product: '<S332>/Product2'
     *  Product: '<S332>/Product3'
     *  UnaryMinus: '<S322>/Unary Minus'
     */
    rtb_Switch2_h = (rtb_Add_i * Robot_Control_ConstB.Sin5_c) + (rtb_Init *
      Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S332>/Subtract' incorporates:
     *  Product: '<S332>/Product'
     *  Product: '<S332>/Product1'
     */
    rtb_Minus_k_idx_1 = (rtb_Add_i * Robot_Control_ConstB.Cos5_b) - (rtb_Init *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S332>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Minus_k_idx_1, rtb_Switch2_h);

    /* Switch: '<S332>/Switch1' incorporates:
     *  Constant: '<S332>/Constant'
     *  Constant: '<S332>/Constant1'
     *  Constant: '<S335>/Constant'
     *  Product: '<S332>/Divide'
     *  Product: '<S332>/Divide1'
     *  RelationalOperator: '<S335>/Compare'
     *  Switch: '<S332>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Minus_k_idx_1 /= rtb_Init;
      rtb_Init = rtb_Switch2_h / rtb_Init;
    } else {
      rtb_Minus_k_idx_1 = 1.0;
      rtb_Init = 0.0;
    }

    /* End of Switch: '<S332>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Init, rtb_Minus_k_idx_1);
  } else {
    rtb_Add_pv = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S325>/Product2' incorporates:
   *  Constant: '<S325>/Constant'
   *  Switch: '<S322>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pv * 1154.7574092481445;

  /* Signum: '<S320>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_pv = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S320>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S323>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S324>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S255>/Product' incorporates:
   *  Abs: '<S320>/Abs'
   *  Abs: '<S323>/Abs'
   *  Constant: '<S326>/Constant'
   *  Constant: '<S336>/Constant3'
   *  Constant: '<S336>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S320>/OR'
   *  Lookup_n-D: '<S323>/1-D Lookup Table'
   *  Math: '<S336>/Math Function'
   *  RelationalOperator: '<S320>/Equal1'
   *  RelationalOperator: '<S326>/Compare'
   *  Signum: '<S320>/Sign'
   *  Signum: '<S320>/Sign1'
   *  Sum: '<S323>/Add'
   *  Sum: '<S336>/Add1'
   *  Sum: '<S336>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_pv == rtb_Add_i) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                    rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S321>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Minus_k_idx_1 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S328>/Sum1' incorporates:
   *  Constant: '<S321>/Constant2'
   *  Product: '<S328>/Product'
   *  Sum: '<S328>/Sum'
   *  UnitDelay: '<S328>/Unit Delay1'
   */
  rtb_Init = ((rtb_Minus_k_idx_1 - Robot_Control_DW.UnitDelay1_DSTATE_j) *
              Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S321>/Product' incorporates:
   *  Constant: '<S321>/Constant3'
   */
  rtb_Switch2_h = rtb_Init * Drive_Motor_Control_D;

  /* Sum: '<S327>/Diff' incorporates:
   *  UnitDelay: '<S327>/UD'
   *
   * Block description for '<S327>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S327>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Switch2_h - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S321>/Saturation' */
  if (rtb_Add_pv > Drive_Motor_Control_D_UL) {
    rtb_Add_pv = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Drive_Motor_Control_D_LL) {
    rtb_Add_pv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S321>/Add' incorporates:
   *  Gain: '<S321>/Gain'
   *  Gain: '<S321>/Gain1'
   *  Saturate: '<S321>/Saturation'
   */
  rtb_Minus_k_idx_0 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0)
                       + (Drive_Motor_Control_P * rtb_Minus_k_idx_1)) +
    rtb_Add_pv;

  /* Saturate: '<S321>/Saturation2' incorporates:
   *  Sum: '<S321>/Add1'
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

  /* End of Saturate: '<S321>/Saturation2' */

  /* Switch: '<S384>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S384>/Switch' incorporates:
     *  Fcn: '<S385>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S384>/Switch' */

  /* Trigonometry: '<S270>/Cos4' incorporates:
   *  Switch: '<S259>/Angle_Switch'
   *  Trigonometry: '<S269>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S270>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S268>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S270>/Sin4' incorporates:
   *  Switch: '<S259>/Angle_Switch'
   *  Trigonometry: '<S269>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S270>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S268>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S270>/Subtract1' incorporates:
   *  Product: '<S270>/Product2'
   *  Product: '<S270>/Product3'
   *  Trigonometry: '<S270>/Cos4'
   *  Trigonometry: '<S270>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_Add_i * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S270>/Subtract' incorporates:
   *  Product: '<S270>/Product'
   *  Product: '<S270>/Product1'
   *  Trigonometry: '<S270>/Cos4'
   *  Trigonometry: '<S270>/Sin4'
   */
  rtb_Minus_k_idx_1 = (rtb_Add_i * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S270>/Hypot' */
  rtb_MatrixConcatenate_idx_0 = rt_hypotd_snf(rtb_Minus_k_idx_1,
    rtb_Minus_k_idx_0);

  /* Switch: '<S270>/Switch' incorporates:
   *  Constant: '<S270>/Constant'
   *  Constant: '<S270>/Constant1'
   *  Constant: '<S271>/Constant'
   *  Product: '<S270>/Divide'
   *  Product: '<S270>/Divide1'
   *  RelationalOperator: '<S271>/Compare'
   *  Switch: '<S270>/Switch1'
   */
  if (rtb_MatrixConcatenate_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0 /
      rtb_MatrixConcatenate_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Minus_k_idx_1 /
      rtb_MatrixConcatenate_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S270>/Switch' */

  /* Product: '<S379>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Saturation_h;

  /* Switch: '<S259>/Speed_Switch' incorporates:
   *  Abs: '<S259>/Abs'
   *  Constant: '<S267>/Constant'
   *  RelationalOperator: '<S267>/Compare'
   *  Switch: '<S259>/Angle_Switch'
   *  Trigonometry: '<S269>/Atan1'
   *  Trigonometry: '<S270>/Atan1'
   *  UnaryMinus: '<S259>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_pv = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S269>/Subtract1' incorporates:
     *  Product: '<S269>/Product2'
     *  Product: '<S269>/Product3'
     *  UnaryMinus: '<S259>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_Add_i * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S269>/Subtract' incorporates:
     *  Product: '<S269>/Product'
     *  Product: '<S269>/Product1'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Add_i * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S269>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
      rtb_Minus_k_idx_0);

    /* Switch: '<S269>/Switch1' incorporates:
     *  Constant: '<S269>/Constant'
     *  Constant: '<S269>/Constant1'
     *  Constant: '<S272>/Constant'
     *  Product: '<S269>/Divide'
     *  Product: '<S269>/Divide1'
     *  RelationalOperator: '<S272>/Compare'
     *  Switch: '<S269>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_MatrixConcatenate_idx_0 /= rtb_Minus_k_idx_1;
      rtb_Minus_k_idx_0 /= rtb_Minus_k_idx_1;
    } else {
      rtb_MatrixConcatenate_idx_0 = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S269>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_0,
      rtb_MatrixConcatenate_idx_0);
  } else {
    rtb_Add_pv = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S262>/Product2' incorporates:
   *  Constant: '<S262>/Constant'
   *  Switch: '<S259>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pv * 1154.7574092481445;

  /* Signum: '<S257>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_pv = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S257>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S260>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S261>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S252>/Product' incorporates:
   *  Abs: '<S257>/Abs'
   *  Abs: '<S260>/Abs'
   *  Constant: '<S263>/Constant'
   *  Constant: '<S273>/Constant3'
   *  Constant: '<S273>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S257>/OR'
   *  Lookup_n-D: '<S260>/1-D Lookup Table'
   *  Math: '<S273>/Math Function'
   *  RelationalOperator: '<S257>/Equal1'
   *  RelationalOperator: '<S263>/Compare'
   *  Signum: '<S257>/Sign'
   *  Signum: '<S257>/Sign1'
   *  Sum: '<S260>/Add'
   *  Sum: '<S273>/Add1'
   *  Sum: '<S273>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_pv == rtb_Add_i) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S258>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_idx_0 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S265>/Sum1' incorporates:
   *  Constant: '<S258>/Constant2'
   *  Product: '<S265>/Product'
   *  Sum: '<S265>/Sum'
   *  UnitDelay: '<S265>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_MatrixConcatenate_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_f) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S258>/Product' incorporates:
   *  Constant: '<S258>/Constant3'
   */
  rtb_Minus_k_idx_1 = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S264>/Diff' incorporates:
   *  UnitDelay: '<S264>/UD'
   *
   * Block description for '<S264>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S264>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Minus_k_idx_1 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S258>/Saturation' */
  if (rtb_Add_pv > Drive_Motor_Control_D_UL) {
    rtb_Add_pv = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Drive_Motor_Control_D_LL) {
    rtb_Add_pv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S258>/Add' incorporates:
   *  Gain: '<S258>/Gain'
   *  Gain: '<S258>/Gain1'
   *  Saturate: '<S258>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = ((Drive_Motor_Control_FF *
    rtb_MatrixConcatenate_b_idx_0) + (Drive_Motor_Control_P *
    rtb_MatrixConcatenate_idx_0)) + rtb_Add_pv;

  /* Saturate: '<S258>/Saturation2' incorporates:
   *  Sum: '<S258>/Add1'
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

  /* End of Saturate: '<S258>/Saturation2' */

  /* Sum: '<S274>/Add1' incorporates:
   *  Constant: '<S274>/Constant3'
   *  Constant: '<S274>/Constant4'
   *  Math: '<S274>/Math Function'
   *  Sum: '<S274>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S276>/Sum1' incorporates:
   *  Constant: '<S261>/Constant2'
   *  Product: '<S276>/Product'
   *  Sum: '<S276>/Sum'
   *  UnitDelay: '<S276>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_b) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S261>/Product' incorporates:
   *  Constant: '<S261>/Constant3'
   */
  rtb_Switch2_pt = rtb_MatrixConcatenate_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S275>/Diff' incorporates:
   *  UnitDelay: '<S275>/UD'
   *
   * Block description for '<S275>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S275>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Switch2_pt - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S261>/Saturation' */
  if (rtb_Add_pv > Steering_Motor_Control_D_UL) {
    rtb_Add_pv = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Motor_Control_D_LL) {
    rtb_Add_pv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S261>/Add' incorporates:
   *  Gain: '<S261>/Gain1'
   *  Saturate: '<S261>/Saturation'
   */
  rtb_Add_e3 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_pv;

  /* Sum: '<S261>/Subtract' incorporates:
   *  Constant: '<S261>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_e3;

  /* Sum: '<S261>/Sum2' incorporates:
   *  Gain: '<S261>/Gain2'
   *  UnitDelay: '<S261>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S277>/Switch2' incorporates:
   *  Constant: '<S261>/Constant'
   *  RelationalOperator: '<S277>/LowerRelop1'
   *  Sum: '<S261>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_e3))) {
    /* Switch: '<S277>/Switch' incorporates:
     *  Constant: '<S261>/Constant1'
     *  RelationalOperator: '<S277>/UpperRelop'
     *  Sum: '<S261>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_e3)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_e3;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S277>/Switch' */
  }

  /* End of Switch: '<S277>/Switch2' */

  /* Saturate: '<S261>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S261>/Saturation1' */

  /* Sum: '<S261>/Add1' */
  rtb_Add_pv = rtb_Add_e3 + rtb_Sum2_e;

  /* Saturate: '<S261>/Saturation2' */
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

  /* End of Saturate: '<S261>/Saturation2' */

  /* Switch: '<S389>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S389>/Switch' incorporates:
     *  Fcn: '<S390>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S389>/Switch' */

  /* Trigonometry: '<S291>/Cos4' incorporates:
   *  Switch: '<S280>/Angle_Switch'
   *  Trigonometry: '<S290>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S291>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S289>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S291>/Sin4' incorporates:
   *  Switch: '<S280>/Angle_Switch'
   *  Trigonometry: '<S290>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S291>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S289>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S291>/Subtract1' incorporates:
   *  Product: '<S291>/Product2'
   *  Product: '<S291>/Product3'
   *  Trigonometry: '<S291>/Cos4'
   *  Trigonometry: '<S291>/Sin4'
   */
  rtb_Add_e3 = (rtb_Add_i * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S291>/Subtract' incorporates:
   *  Product: '<S291>/Product'
   *  Product: '<S291>/Product1'
   *  Trigonometry: '<S291>/Cos4'
   *  Trigonometry: '<S291>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Add_i * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S291>/Hypot' */
  rtb_uDLookupTable = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_e3);

  /* Switch: '<S291>/Switch' incorporates:
   *  Constant: '<S291>/Constant'
   *  Constant: '<S291>/Constant1'
   *  Constant: '<S292>/Constant'
   *  Product: '<S291>/Divide'
   *  Product: '<S291>/Divide1'
   *  RelationalOperator: '<S292>/Compare'
   *  Switch: '<S291>/Switch1'
   */
  if (rtb_uDLookupTable > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_e3 / rtb_uDLookupTable;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_uDLookupTable;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S291>/Switch' */

  /* Product: '<S379>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Saturation_h;

  /* Switch: '<S280>/Speed_Switch' incorporates:
   *  Abs: '<S280>/Abs'
   *  Constant: '<S288>/Constant'
   *  RelationalOperator: '<S288>/Compare'
   *  Switch: '<S280>/Angle_Switch'
   *  Trigonometry: '<S290>/Atan1'
   *  Trigonometry: '<S291>/Atan1'
   *  UnaryMinus: '<S280>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_pv = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S290>/Subtract1' incorporates:
     *  Product: '<S290>/Product2'
     *  Product: '<S290>/Product3'
     *  UnaryMinus: '<S280>/Unary Minus'
     */
    rtb_Add_e3 = (rtb_Add_i * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S290>/Subtract' incorporates:
     *  Product: '<S290>/Product'
     *  Product: '<S290>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_i * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S290>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_uDLookupTable, rtb_Add_e3);

    /* Switch: '<S290>/Switch1' incorporates:
     *  Constant: '<S290>/Constant'
     *  Constant: '<S290>/Constant1'
     *  Constant: '<S293>/Constant'
     *  Product: '<S290>/Divide'
     *  Product: '<S290>/Divide1'
     *  RelationalOperator: '<S293>/Compare'
     *  Switch: '<S290>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Subtract1_la;
      rtb_Add_e3 /= rtb_Subtract1_la;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Add_e3 = 0.0;
    }

    /* End of Switch: '<S290>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_e3, rtb_uDLookupTable);
  } else {
    rtb_Add_pv = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S283>/Product2' incorporates:
   *  Constant: '<S283>/Constant'
   *  Switch: '<S280>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pv * 1154.7574092481445;

  /* Signum: '<S278>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_pv = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S278>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S281>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S282>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S253>/Product' incorporates:
   *  Abs: '<S278>/Abs'
   *  Abs: '<S281>/Abs'
   *  Constant: '<S284>/Constant'
   *  Constant: '<S294>/Constant3'
   *  Constant: '<S294>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S278>/OR'
   *  Lookup_n-D: '<S281>/1-D Lookup Table'
   *  Math: '<S294>/Math Function'
   *  RelationalOperator: '<S278>/Equal1'
   *  RelationalOperator: '<S284>/Compare'
   *  Signum: '<S278>/Sign'
   *  Signum: '<S278>/Sign1'
   *  Sum: '<S281>/Add'
   *  Sum: '<S294>/Add1'
   *  Sum: '<S294>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_pv == rtb_Add_i) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Sum: '<S279>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_uDLookupTable = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S286>/Sum1' incorporates:
   *  Constant: '<S279>/Constant2'
   *  Product: '<S286>/Product'
   *  Sum: '<S286>/Sum'
   *  UnitDelay: '<S286>/Unit Delay1'
   */
  rtb_Add_e3 = ((rtb_uDLookupTable - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S279>/Product' incorporates:
   *  Constant: '<S279>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_e3 * Drive_Motor_Control_D;

  /* Sum: '<S285>/Diff' incorporates:
   *  UnitDelay: '<S285>/UD'
   *
   * Block description for '<S285>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S285>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S279>/Saturation' */
  if (rtb_Add_pv > Drive_Motor_Control_D_UL) {
    rtb_Add_pv = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Drive_Motor_Control_D_LL) {
    rtb_Add_pv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S279>/Add' incorporates:
   *  Gain: '<S279>/Gain'
   *  Gain: '<S279>/Gain1'
   *  Saturate: '<S279>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF *
    rtb_MatrixConcatenate_b_idx_0) + (Drive_Motor_Control_P * rtb_uDLookupTable))
    + rtb_Add_pv;

  /* Saturate: '<S279>/Saturation2' incorporates:
   *  Sum: '<S279>/Add1'
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

  /* End of Saturate: '<S279>/Saturation2' */

  /* Sum: '<S295>/Add1' incorporates:
   *  Constant: '<S295>/Constant3'
   *  Constant: '<S295>/Constant4'
   *  Math: '<S295>/Math Function'
   *  Sum: '<S295>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S297>/Sum1' incorporates:
   *  Constant: '<S282>/Constant2'
   *  Product: '<S297>/Product'
   *  Sum: '<S297>/Sum'
   *  UnitDelay: '<S297>/Unit Delay1'
   */
  rtb_Switch2_e = ((rtb_MatrixConcatenate_b_idx_0 -
                    Robot_Control_DW.UnitDelay1_DSTATE_n) *
                   Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S282>/Product' incorporates:
   *  Constant: '<S282>/Constant3'
   */
  rtb_Product_hi = rtb_Switch2_e * Steering_Motor_Control_D;

  /* Sum: '<S296>/Diff' incorporates:
   *  UnitDelay: '<S296>/UD'
   *
   * Block description for '<S296>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S296>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Product_hi - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S282>/Saturation' */
  if (rtb_Add_pv > Steering_Motor_Control_D_UL) {
    rtb_Add_pv = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Motor_Control_D_LL) {
    rtb_Add_pv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S282>/Add' incorporates:
   *  Gain: '<S282>/Gain1'
   *  Saturate: '<S282>/Saturation'
   */
  rtb_Add_i = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_pv;

  /* Sum: '<S282>/Subtract' incorporates:
   *  Constant: '<S282>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_i;

  /* Sum: '<S282>/Sum2' incorporates:
   *  Gain: '<S282>/Gain2'
   *  UnitDelay: '<S282>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S298>/Switch2' incorporates:
   *  Constant: '<S282>/Constant'
   *  RelationalOperator: '<S298>/LowerRelop1'
   *  Sum: '<S282>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_i))) {
    /* Switch: '<S298>/Switch' incorporates:
     *  Constant: '<S282>/Constant1'
     *  RelationalOperator: '<S298>/UpperRelop'
     *  Sum: '<S282>/Subtract1'
     */
    if (rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_i)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_i;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S298>/Switch' */
  }

  /* End of Switch: '<S298>/Switch2' */

  /* Saturate: '<S282>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S282>/Saturation1' */

  /* Sum: '<S282>/Add1' */
  rtb_Add_pv = rtb_Add_i + rtb_Subtract1_kg;

  /* Saturate: '<S282>/Saturation2' */
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

  /* End of Saturate: '<S282>/Saturation2' */

  /* Switch: '<S394>/Switch' */
  if (!rtb_LogicalOperator1) {
    /* Switch: '<S394>/Switch' incorporates:
     *  Fcn: '<S395>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S394>/Switch' */

  /* Trigonometry: '<S312>/Cos4' incorporates:
   *  Switch: '<S301>/Angle_Switch'
   *  Trigonometry: '<S311>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S312>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S310>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S312>/Sin4' incorporates:
   *  Switch: '<S301>/Angle_Switch'
   *  Trigonometry: '<S311>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S312>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S310>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S312>/Subtract1' incorporates:
   *  Product: '<S312>/Product2'
   *  Product: '<S312>/Product3'
   *  Trigonometry: '<S312>/Cos4'
   *  Trigonometry: '<S312>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Add_i * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S312>/Subtract' incorporates:
   *  Product: '<S312>/Product'
   *  Product: '<S312>/Product1'
   *  Trigonometry: '<S312>/Cos4'
   *  Trigonometry: '<S312>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Add_i * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S312>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S312>/Switch' incorporates:
   *  Constant: '<S312>/Constant'
   *  Constant: '<S312>/Constant1'
   *  Constant: '<S313>/Constant'
   *  Product: '<S312>/Divide'
   *  Product: '<S312>/Divide1'
   *  RelationalOperator: '<S313>/Compare'
   *  Switch: '<S312>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S312>/Switch' */

  /* Product: '<S379>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Saturation_h;

  /* Switch: '<S301>/Speed_Switch' incorporates:
   *  Abs: '<S301>/Abs'
   *  Constant: '<S309>/Constant'
   *  RelationalOperator: '<S309>/Compare'
   *  Switch: '<S301>/Angle_Switch'
   *  Trigonometry: '<S311>/Atan1'
   *  Trigonometry: '<S312>/Atan1'
   *  UnaryMinus: '<S301>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Add_pv = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S311>/Subtract1' incorporates:
     *  Product: '<S311>/Product2'
     *  Product: '<S311>/Product3'
     *  UnaryMinus: '<S301>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Add_i * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S311>/Subtract' incorporates:
     *  Product: '<S311>/Product'
     *  Product: '<S311>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_i * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S311>/Hypot' */
    rtb_Add_i = rt_hypotd_snf(rtb_uDLookupTable, rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S311>/Switch1' incorporates:
     *  Constant: '<S311>/Constant'
     *  Constant: '<S311>/Constant1'
     *  Constant: '<S314>/Constant'
     *  Product: '<S311>/Divide'
     *  Product: '<S311>/Divide1'
     *  RelationalOperator: '<S314>/Compare'
     *  Switch: '<S311>/Switch'
     */
    if (rtb_Add_i > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Add_i;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Add_i;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S311>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_uDLookupTable);
  } else {
    rtb_Add_pv = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S304>/Product2' incorporates:
   *  Constant: '<S304>/Constant'
   *  Switch: '<S301>/Speed_Switch'
   */
  rtb_Saturation_h = rtb_Add_pv * 1154.7574092481445;

  /* Signum: '<S299>/Sign' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Add_pv = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Add_pv = -1.0;
  } else {
    rtb_Add_pv = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S299>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S302>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S303>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S254>/Product' incorporates:
   *  Abs: '<S299>/Abs'
   *  Abs: '<S302>/Abs'
   *  Constant: '<S305>/Constant'
   *  Constant: '<S315>/Constant3'
   *  Constant: '<S315>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S299>/OR'
   *  Lookup_n-D: '<S302>/1-D Lookup Table'
   *  Math: '<S315>/Math Function'
   *  RelationalOperator: '<S299>/Equal1'
   *  RelationalOperator: '<S305>/Compare'
   *  Signum: '<S299>/Sign'
   *  Signum: '<S299>/Sign1'
   *  Sum: '<S302>/Add'
   *  Sum: '<S315>/Add1'
   *  Sum: '<S315>/Add2'
   */
  rtb_Saturation_h = (((real_T)((rtb_Add_pv == rtb_Add_i) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Saturation_h) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Sum: '<S300>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h -
    Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S307>/Sum1' incorporates:
   *  Constant: '<S300>/Constant2'
   *  Product: '<S307>/Product'
   *  Sum: '<S307>/Sum'
   *  UnitDelay: '<S307>/Unit Delay1'
   */
  rtb_Add_i = ((rtb_MatrixConcatenate_b_idx_0 -
                Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S300>/Product' incorporates:
   *  Constant: '<S300>/Constant3'
   */
  rtb_uDLookupTable = rtb_Add_i * Drive_Motor_Control_D;

  /* Sum: '<S306>/Diff' incorporates:
   *  UnitDelay: '<S306>/UD'
   *
   * Block description for '<S306>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S306>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S300>/Saturation' */
  if (rtb_Add_pv > Drive_Motor_Control_D_UL) {
    rtb_Add_pv = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Drive_Motor_Control_D_LL) {
    rtb_Add_pv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S300>/Add' incorporates:
   *  Gain: '<S300>/Gain'
   *  Gain: '<S300>/Gain1'
   *  Saturate: '<S300>/Saturation'
   */
  rtb_Saturation_h = ((Drive_Motor_Control_FF * rtb_Saturation_h) +
                      (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) +
    rtb_Add_pv;

  /* Saturate: '<S300>/Saturation2' incorporates:
   *  Sum: '<S300>/Add1'
   */
  if (rtb_Saturation_h > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Saturation_h < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Saturation_h;
  }

  /* End of Saturate: '<S300>/Saturation2' */

  /* Sum: '<S316>/Add1' incorporates:
   *  Constant: '<S316>/Constant3'
   *  Constant: '<S316>/Constant4'
   *  Math: '<S316>/Math Function'
   *  Sum: '<S316>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S318>/Sum1' incorporates:
   *  Constant: '<S303>/Constant2'
   *  Product: '<S318>/Product'
   *  Sum: '<S318>/Sum'
   *  UnitDelay: '<S318>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Saturation_h -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S303>/Product' incorporates:
   *  Constant: '<S303>/Constant3'
   */
  rtb_Product_k = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S317>/Diff' incorporates:
   *  UnitDelay: '<S317>/UD'
   *
   * Block description for '<S317>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S317>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Product_k - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S303>/Saturation' */
  if (rtb_Add_pv > Steering_Motor_Control_D_UL) {
    rtb_Add_pv = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Motor_Control_D_LL) {
    rtb_Add_pv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S303>/Add' incorporates:
   *  Gain: '<S303>/Gain1'
   *  Saturate: '<S303>/Saturation'
   */
  rtb_Add_lu = (Steering_Motor_Control_P * rtb_Saturation_h) + rtb_Add_pv;

  /* Sum: '<S303>/Subtract' incorporates:
   *  Constant: '<S303>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_lu;

  /* Sum: '<S303>/Sum2' incorporates:
   *  Gain: '<S303>/Gain2'
   *  UnitDelay: '<S303>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S319>/Switch2' incorporates:
   *  Constant: '<S303>/Constant'
   *  RelationalOperator: '<S319>/LowerRelop1'
   *  Sum: '<S303>/Subtract'
   */
  if (!(rtb_Saturation_h > (1.0 - rtb_Add_lu))) {
    /* Sum: '<S303>/Subtract1' incorporates:
     *  Constant: '<S303>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_lu;

    /* Switch: '<S319>/Switch' incorporates:
     *  Constant: '<S303>/Constant1'
     *  RelationalOperator: '<S319>/UpperRelop'
     *  Sum: '<S303>/Subtract1'
     */
    if (!(rtb_Saturation_h < (-1.0 - rtb_Add_lu))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h;
    }

    /* End of Switch: '<S319>/Switch' */
  }

  /* End of Switch: '<S319>/Switch2' */

  /* Saturate: '<S303>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S303>/Saturation1' */

  /* Sum: '<S303>/Add1' */
  rtb_Add_pv = rtb_Add_lu + rtb_Integral_ga;

  /* Saturate: '<S303>/Saturation2' */
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

  /* End of Saturate: '<S303>/Saturation2' */

  /* Sum: '<S337>/Add1' incorporates:
   *  Constant: '<S337>/Constant3'
   *  Constant: '<S337>/Constant4'
   *  Math: '<S337>/Math Function'
   *  Sum: '<S337>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S339>/Sum1' incorporates:
   *  Constant: '<S324>/Constant2'
   *  Product: '<S339>/Product'
   *  Sum: '<S339>/Sum'
   *  UnitDelay: '<S339>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Saturation_h -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S324>/Product' incorporates:
   *  Constant: '<S324>/Constant3'
   */
  rtb_Add_lu = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S338>/Diff' incorporates:
   *  UnitDelay: '<S338>/UD'
   *
   * Block description for '<S338>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S338>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Add_lu - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S324>/Saturation' */
  if (rtb_Add_pv > Steering_Motor_Control_D_UL) {
    rtb_Add_pv = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_pv < Steering_Motor_Control_D_LL) {
    rtb_Add_pv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S324>/Add' incorporates:
   *  Gain: '<S324>/Gain1'
   *  Saturate: '<S324>/Saturation'
   */
  rtb_Add_jp = (Steering_Motor_Control_P * rtb_Saturation_h) + rtb_Add_pv;

  /* Sum: '<S324>/Subtract' incorporates:
   *  Constant: '<S324>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_jp;

  /* Sum: '<S324>/Sum2' incorporates:
   *  Gain: '<S324>/Gain2'
   *  UnitDelay: '<S324>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S340>/Switch2' incorporates:
   *  Constant: '<S324>/Constant'
   *  RelationalOperator: '<S340>/LowerRelop1'
   *  Sum: '<S324>/Subtract'
   */
  if (!(rtb_Saturation_h > (1.0 - rtb_Add_jp))) {
    /* Sum: '<S324>/Subtract1' incorporates:
     *  Constant: '<S324>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_jp;

    /* Switch: '<S340>/Switch' incorporates:
     *  Constant: '<S324>/Constant1'
     *  RelationalOperator: '<S340>/UpperRelop'
     *  Sum: '<S324>/Subtract1'
     */
    if (!(rtb_Saturation_h < (-1.0 - rtb_Add_jp))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h;
    }

    /* End of Switch: '<S340>/Switch' */
  }

  /* End of Switch: '<S340>/Switch2' */

  /* Saturate: '<S324>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S324>/Saturation1' */

  /* Sum: '<S324>/Add1' */
  rtb_Add_pv = rtb_Add_jp + rtb_Integral_bj;

  /* Saturate: '<S324>/Saturation2' */
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

  /* End of Saturate: '<S324>/Saturation2' */

  /* Sum: '<S187>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S138>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S189>/Sum1' incorporates:
   *  Constant: '<S187>/Constant2'
   *  Product: '<S189>/Product'
   *  Sum: '<S187>/Sum'
   *  Sum: '<S189>/Sum'
   *  UnitDelay: '<S189>/Unit Delay1'
   */
  rtb_Add_jp = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S187>/Product' incorporates:
   *  Constant: '<S187>/Constant3'
   */
  rtb_Product_ih = rtb_Add_jp * 0.0;

  /* Sum: '<S188>/Diff' incorporates:
   *  UnitDelay: '<S188>/UD'
   *
   * Block description for '<S188>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S188>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_pv = rtb_Product_ih - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S187>/Saturation' */
  if (rtb_Add_pv > 0.1) {
    rtb_Add_pv = 0.1;
  } else if (rtb_Add_pv < -0.1) {
    rtb_Add_pv = -0.1;
  }

  /* Sum: '<S187>/Add' incorporates:
   *  Gain: '<S187>/Gain'
   *  Gain: '<S187>/Gain1'
   *  Saturate: '<S187>/Saturation'
   *  Sum: '<S187>/Sum'
   */
  rtb_Saturation_h = ((Rebuilt_Transfer_Motor_Gain_FF *
                       Robot_Control_B.RB_Desired_Transfer_Speed) +
                      (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) +
    rtb_Add_pv;

  /* Logic: '<S138>/Logical Operator1' incorporates:
   *  Constant: '<S186>/Constant'
   *  RelationalOperator: '<S186>/Compare'
   */
  rtb_Compare_mq = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

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
      rtb_Compare_mq) {
    rtb_Compare_ky = true;
  } else {
    rtb_Compare_ky = (rtb_Compare_mq && (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S138>/Switch1' */

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S187>/Constant4'
   */
  if (rtb_Compare_ky) {
    /* Sum: '<S187>/Sum2' incorporates:
     *  Gain: '<S187>/Gain2'
     *  Sum: '<S187>/Sum'
     *  UnitDelay: '<S187>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Transfer_Motor_Gain_I *
      rtb_Integral_d) + Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S187>/Subtract' incorporates:
     *  Constant: '<S187>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Saturation_h;

    /* Switch: '<S190>/Switch2' incorporates:
     *  Constant: '<S187>/Constant'
     *  RelationalOperator: '<S190>/LowerRelop1'
     *  Sum: '<S187>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Saturation_h))) {
      /* Sum: '<S187>/Subtract1' incorporates:
       *  Constant: '<S187>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Saturation_h;

      /* Switch: '<S190>/Switch' incorporates:
       *  Constant: '<S187>/Constant1'
       *  RelationalOperator: '<S190>/UpperRelop'
       *  Sum: '<S187>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Saturation_h))) {
        rtb_Integral_d = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S190>/Switch' */
    }

    /* End of Switch: '<S190>/Switch2' */

    /* Saturate: '<S187>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S187>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S187>/Switch' */

  /* Switch: '<S138>/Switch2' incorporates:
   *  Logic: '<S138>/Logical Operator1'
   */
  if (rtb_Compare_mq) {
    /* Sum: '<S187>/Add1' */
    rtb_Add_pv = rtb_Saturation_h + rtb_Integral_d;

    /* Saturate: '<S187>/Saturation2' */
    if (rtb_Add_pv > 1.0) {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_pv < -1.0) {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S138>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_pv;
    }

    /* End of Saturate: '<S187>/Saturation2' */
  } else {
    /* Switch: '<S138>/Switch2' incorporates:
     *  Constant: '<S138>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S138>/Switch2' */

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
    rtb_Saturation_h = TEST_Desired_Hood_Pos_OV;
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
    rtb_Saturation_h = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_Saturation_h > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Saturation_h = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Saturation_h < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Saturation_h = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Saturation_h;

  /* Switch: '<S130>/Init' incorporates:
   *  UnitDelay: '<S130>/FixPt Unit Delay1'
   *  UnitDelay: '<S130>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S130>/Init' */

  /* Sum: '<S128>/Sum1' */
  rtb_Saturation_h -= rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S129>/Switch2' incorporates:
   *  Constant: '<S127>/Constant1'
   *  Constant: '<S127>/Constant3'
   *  RelationalOperator: '<S129>/LowerRelop1'
   *  RelationalOperator: '<S129>/UpperRelop'
   *  Switch: '<S129>/Switch'
   */
  if (rtb_Saturation_h > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Saturation_h = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Saturation_h < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     */
    rtb_Saturation_h = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S129>/Switch2' */

  /* Sum: '<S128>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Saturation_h +
    rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Logic: '<S6>/Logical Operator'
   */
  if (rtb_Intake_Arm_Cycle || rtb_LogicalOperator1_ms) {
    rtb_Saturation_h = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Saturation_h = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S56>/Logical Operator1' incorporates:
   *  Constant: '<S68>/Constant'
   *  RelationalOperator: '<S68>/Compare'
   */
  rtb_LogicalOperator1_ms = !(rtb_Saturation_h == 0.0);

  /* Sum: '<S69>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S56>/Subtract'
   */
  rtb_Error_n = rtb_Saturation_h - Robot_Control_U.Measured_Intake_Roller_Speed;

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
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Roller_Motor_Gain_FF *
    rtb_Saturation_h) + (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) +
    rtb_Add_pv;

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
    rtb_Saturation_h = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
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
    if (!(rtb_Saturation_h > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S69>/Subtract1' incorporates:
       *  Constant: '<S69>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S72>/Switch' incorporates:
       *  Constant: '<S69>/Constant1'
       *  RelationalOperator: '<S72>/UpperRelop'
       *  Sum: '<S69>/Subtract1'
       */
      if (!(rtb_Saturation_h < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Error_n = rtb_Saturation_h;
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
    rtb_Saturation_h = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Saturation_h = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S67>/Init' */

  /* Sum: '<S65>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_Saturation_h;

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
    rtb_Saturation_h;

  /* Sum: '<S61>/Sum' */
  rtb_Saturation_h = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S63>/Sum1' incorporates:
   *  Constant: '<S61>/Constant2'
   *  Product: '<S63>/Product'
   *  Sum: '<S63>/Sum'
   *  UnitDelay: '<S63>/Unit Delay1'
   */
  rtb_Sum1_dj = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_c;

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
    (Rebuilt_Intake_Arm_Gain_P * rtb_Saturation_h);

  /* Sum: '<S61>/Subtract' incorporates:
   *  Constant: '<S61>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_pv;

  /* Sum: '<S61>/Sum2' incorporates:
   *  Gain: '<S61>/Gain2'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  rtb_Saturation_h = (0.0 * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S64>/Switch2' incorporates:
   *  Constant: '<S61>/Constant'
   *  RelationalOperator: '<S64>/LowerRelop1'
   *  Sum: '<S61>/Subtract'
   */
  if (!(rtb_Saturation_h > (1.0 - rtb_Add_pv))) {
    /* Sum: '<S61>/Subtract1' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_pv;

    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S61>/Constant1'
     *  RelationalOperator: '<S64>/UpperRelop'
     *  Sum: '<S61>/Subtract1'
     */
    if (!(rtb_Saturation_h < (-1.0 - rtb_Add_pv))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h;
    }

    /* End of Switch: '<S64>/Switch' */
  }

  /* End of Switch: '<S64>/Switch2' */

  /* Saturate: '<S61>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > 0.1) {
    rtb_Saturation_h = 0.1;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -0.1) {
    rtb_Saturation_h = -0.1;
  } else {
    rtb_Saturation_h = rtb_MatrixConcatenate_b_idx_0;
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
    rtb_Add_pv += rtb_Saturation_h;

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

  /* Update for UnitDelay: '<S352>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S352>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S173>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_o = rtb_Merge1;

  /* Update for UnitDelay: '<S174>/Unit Delay' incorporates:
   *  Constant: '<S174>/Constant4'
   *  Sum: '<S174>/Sum'
   *  Switch: '<S174>/Switch'
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

  /* Update for UnitDelay: '<S375>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S374>/UD'
   *
   * Block description for '<S374>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Switch1_n;

  /* Update for UnitDelay: '<S372>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch2_hw;

  /* Update for UnitDelay: '<S354>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Init_o;

  /* Update for UnitDelay: '<S369>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S369>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S369>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S353>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S362>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S362>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S362>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S328>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Init;

  /* Update for UnitDelay: '<S327>/UD'
   *
   * Block description for '<S327>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2_h;

  /* Update for UnitDelay: '<S321>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S265>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S264>/UD'
   *
   * Block description for '<S264>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S258>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S276>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S275>/UD'
   *
   * Block description for '<S275>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_pt;

  /* Update for UnitDelay: '<S261>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S286>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_e3;

  /* Update for UnitDelay: '<S285>/UD'
   *
   * Block description for '<S285>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S279>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S297>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Switch2_e;

  /* Update for UnitDelay: '<S296>/UD'
   *
   * Block description for '<S296>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_hi;

  /* Update for UnitDelay: '<S282>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S307>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_i;

  /* Update for UnitDelay: '<S306>/UD'
   *
   * Block description for '<S306>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S300>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S318>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S317>/UD'
   *
   * Block description for '<S317>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_k;

  /* Update for UnitDelay: '<S303>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S339>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S338>/UD'
   *
   * Block description for '<S338>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_lu;

  /* Update for UnitDelay: '<S324>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S189>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_jp;

  /* Update for UnitDelay: '<S188>/UD'
   *
   * Block description for '<S188>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_ih;

  /* Update for UnitDelay: '<S187>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S138>/Unit Delay' */
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
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_ej;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_Saturation_h;
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

  /* InitializeConditions for UnitDelay: '<S352>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S369>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S362>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S130>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S67>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S432>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S197>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S193>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S197>/Robot_Index_Is_Valid' */
  /* Start for If: '<S200>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S200>/Circle_Check_Valid' */
  /* Start for If: '<S202>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S200>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S197>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S169>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S171>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S133>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S172>/Unit Delay' */
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
