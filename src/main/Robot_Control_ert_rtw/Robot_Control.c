/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.485
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Apr 10 13:23:05 2026
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

/* Named constants for Chart: '<S372>/Add dither' */
#define Robot_Control_IN_Dither        ((uint8_T)1U)
#define Robot_Control_IN_High          ((uint8_T)1U)
#define Robot_Control_IN_No_Dither     ((uint8_T)2U)
#define Robot_Control_IN_Off           ((uint8_T)2U)

/* Named constants for Chart: '<S20>/Chart' */
#define Robot_Control_IN_End_Action    ((uint8_T)1U)
#define Robot_Control_IN_Follow_Path   ((uint8_T)2U)
#define Robot_Control_IN_Start_Action  ((uint8_T)3U)

/* Exported block parameters */
real_T Auto_Deploy_Intake_Time = 1.5;  /* Variable: Auto_Deploy_Intake_Time
                                        * Referenced by: '<S26>/Constant'
                                        */
real_T Auto_Intake_Arm_Cycle_Delay_Time = 2.0;
                                   /* Variable: Auto_Intake_Arm_Cycle_Delay_Time
                                    * Referenced by: '<S30>/Constant'
                                    */
real_T Auto_Path_Chooser = 3.0;        /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S21>/Constant17'
                                        */
real_T Auto_Shoot_Time = 4.5;          /* Variable: Auto_Shoot_Time
                                        * Referenced by: '<S24>/Constant'
                                        */
real_T Blue_Hub_LeftX = 5.1717;        /* Variable: Blue_Hub_LeftX
                                        * Referenced by: '<S152>/Constant2'
                                        */
real_T Blue_Hub_LeftY = 3.354;         /* Variable: Blue_Hub_LeftY
                                        * Referenced by: '<S152>/Constant3'
                                        */
real_T Blue_Hub_RightX = 5.1717;       /* Variable: Blue_Hub_RightX
                                        * Referenced by: '<S152>/Constant4'
                                        */
real_T Blue_Hub_RightY = 4.548;        /* Variable: Blue_Hub_RightY
                                        * Referenced by: '<S152>/Constant5'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S446>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S442>/Constant'
                                        *   '<S442>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S446>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S442>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S275>/Constant3'
                                        *   '<S296>/Constant3'
                                        *   '<S317>/Constant3'
                                        *   '<S338>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S275>/Constant2'
                                   *   '<S296>/Constant2'
                                   *   '<S317>/Constant2'
                                   *   '<S338>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S275>/Saturation'
                                        *   '<S296>/Saturation'
                                        *   '<S317>/Saturation'
                                        *   '<S338>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S275>/Saturation'
                                        *   '<S296>/Saturation'
                                        *   '<S317>/Saturation'
                                        *   '<S338>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S275>/Gain'
                                            *   '<S296>/Gain'
                                            *   '<S317>/Gain'
                                            *   '<S338>/Gain'
                                            */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S275>/Gain1'
                                        *   '<S296>/Gain1'
                                        *   '<S317>/Gain1'
                                        *   '<S338>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S280>/Constant'
                            *   '<S301>/Constant'
                            *   '<S322>/Constant'
                            *   '<S343>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S196>/BlueAllianceZoneX'
                                         *   '<S198>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S153>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S153>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S153>/Constant1'
                                        *   '<S153>/Switch3'
                                        */
real_T Field_Length = 17.557;          /* Variable: Field_Length
                                        * Referenced by: '<S152>/Constant10'
                                        */
real_T Field_Length_Half = 8.7785;     /* Variable: Field_Length_Half
                                        * Referenced by:
                                        *   '<S170>/Switch'
                                        *   '<S171>/Switch'
                                        */
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S153>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S153>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S197>/RedAllianceZoneX'
                                         *   '<S199>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S153>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S153>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S432>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S432>/Constant5'
                                          */
real_T Field_Width_Pass = 7.0692;      /* Variable: Field_Width_Pass
                                        * Referenced by: '<S152>/Constant11'
                                        */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rate_Limit_X = 1000.0;          /* Variable: Rate_Limit_X
                                        * Referenced by: '<S39>/Constant3'
                                        */
real_T Rate_Limit_Y = 1000.0;          /* Variable: Rate_Limit_Y
                                        * Referenced by: '<S40>/Constant3'
                                        */
real_T Rate_Limit_Z = 1000.0;          /* Variable: Rate_Limit_Z
                                        * Referenced by: '<S41>/Constant3'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = 0.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S168>/Constant'
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
                                          *   '<S146>/Constant3'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S131>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S131>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S64>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.008;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                          * Referenced by: '<S64>/Gain1'
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
                                            *   '<S53>/Constant'
                                            *   '<S60>/Constant'
                                            */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S61>/Constant'
                                            */
real_T Rebuilt_Intake_Meas_In_Disable = -20.0;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S62>/Constant'
                                      */
real_T Rebuilt_Intake_Meas_Out_Disable = 40.0;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S63>/Constant'
                                     */
real_T Rebuilt_Intake_RL_Dec = -3.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S57>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 3.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S57>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 30.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S181>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S185>/Constant3'
                                   *   '<S186>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S176>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S177>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S178>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S179>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S182>/Unit Delay'
                                      *   '<S183>/Unit Delay'
                                      *   '<S184>/Unit Delay'
                                      *   '<S185>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S182>/Constant2'
                                      *   '<S183>/Constant2'
                                      *   '<S184>/Constant2'
                                      *   '<S185>/Constant2'
                                      *   '<S189>/Constant'
                                      *   '<S190>/Constant'
                                      *   '<S191>/Constant'
                                      *   '<S192>/Constant'
                                      */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S173>/Constant'
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
                                * Referenced by: '<S59>/Constant1'
                                */
real_T Rebuilt_Roller_Intake_In_Delay = 2.0;
                                     /* Variable: Rebuilt_Roller_Intake_In_Delay
                                      * Referenced by: '<S71>/Constant'
                                      */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00016534;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                                  * Referenced by: '<S73>/Gain'
                                                  */
real_T Rebuilt_Roller_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                             * Referenced by: '<S73>/Gain2'
                                             */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0001;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                             * Referenced by: '<S73>/Gain1'
                                             */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S154>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S154>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S154>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S154>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S154>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S154>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S154>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S154>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S149>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S149>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S149>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 3.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S149>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S149>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S149>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S149>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S149>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S150>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S150>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S150>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S150>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S150>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S150>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S150>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S150>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S141>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S141>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S141>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2725.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S163>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S163>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3265.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S163>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3425.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S163>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3625.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S163>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3775.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S163>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S163>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S163>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2825.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S162>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S162>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3365.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S162>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3525.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S162>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3725.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S162>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3875.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S162>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S162>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S162>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S156>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S156>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S156>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S156>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S156>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S156>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S156>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S156>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S160>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S143>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00015;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S12>/Constant1'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 0.03;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                            * Referenced by: '<S143>/Constant3'
                                            */
real_T Rebuilt_Shooter_Motor_Gain_I_Low = 0.0;
                                   /* Variable: Rebuilt_Shooter_Motor_Gain_I_Low
                                    * Referenced by: '<S143>/Constant9'
                                    */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.06;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                            * Referenced by: '<S143>/Constant4'
                                            */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S151>/Constant2'
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
                              * Referenced by: '<S144>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S204>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S204>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S204>/Gain1'
                                       */
real_T Red_Hub_LeftX = 11.369;         /* Variable: Red_Hub_LeftX
                                        * Referenced by: '<S152>/Constant6'
                                        */
real_T Red_Hub_LeftY = 4.548;          /* Variable: Red_Hub_LeftY
                                        * Referenced by: '<S152>/Constant7'
                                        */
real_T Red_Hub_RightX = 11.369;        /* Variable: Red_Hub_RightX
                                        * Referenced by: '<S152>/Constant8'
                                        */
real_T Red_Hub_RightY = 3.354;         /* Variable: Red_Hub_RightY
                                        * Referenced by: '<S152>/Constant9'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S431>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S429>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S431>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S432>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S432>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S264>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S264>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S211>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S224>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S264>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S371>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S371>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S371>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S371>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S371>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S371>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S389>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S389>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S389>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S389>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S388>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S389>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S389>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S389>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S389>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S389>/Constant1'
                                   *   '<S389>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S389>/Constant'
                                   *   '<S389>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S372>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S372>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S372>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S372>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S278>/Constant3'
                                        *   '<S299>/Constant3'
                                        *   '<S320>/Constant3'
                                        *   '<S341>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S278>/Constant2'
                                *   '<S299>/Constant2'
                                *   '<S320>/Constant2'
                                *   '<S341>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S278>/Saturation'
                                           *   '<S299>/Saturation'
                                           *   '<S320>/Saturation'
                                           *   '<S341>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S278>/Saturation'
                                          *   '<S299>/Saturation'
                                          *   '<S320>/Saturation'
                                          *   '<S341>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S278>/Gain2'
                                         *   '<S299>/Gain2'
                                         *   '<S320>/Gain2'
                                         *   '<S341>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S278>/Saturation1'
                                             *   '<S299>/Saturation1'
                                             *   '<S320>/Saturation1'
                                             *   '<S341>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S278>/Saturation1'
                                            *   '<S299>/Saturation1'
                                            *   '<S320>/Saturation1'
                                            *   '<S341>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S278>/Gain1'
                                        *   '<S299>/Gain1'
                                        *   '<S320>/Gain1'
                                        *   '<S341>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S370>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S370>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S370>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S370>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S370>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S370>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S431>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S431>/Constant1'
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
                                      * Referenced by: '<S430>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S430>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S430>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S358>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S358>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S358>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S358>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S358>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S358>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S432>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S431>/Dead Zone'
                                        *   '<S432>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S431>/Dead Zone'
                                        *   '<S432>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S429>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S429>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S429>/Constant4'
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
                                        * Referenced by: '<S429>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S429>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S429>/Constant5'
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
                                        *   '<S429>/Constant11'
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
 *    '<S137>/If Action Subsystem1'
 *    '<S137>/If Action Subsystem3'
 */
void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S182>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * System reset for action system:
 *    '<S137>/If Action Subsystem1'
 *    '<S137>/If Action Subsystem3'
 */
void Robot__IfActionSubsystem1_Reset(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S182>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S137>/If Action Subsystem1'
 *    '<S137>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(real_T rtu_IsBlueInactiveFirst, real_T
  rtu_IsBlueAlliance, boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive,
  real_T *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  boolean_T rtb_Compare_cf;

  /* RelationalOperator: '<S189>/Compare' incorporates:
   *  Constant: '<S182>/Constant1'
   *  Constant: '<S189>/Constant'
   *  Sum: '<S182>/Sum'
   *  UnitDelay: '<S182>/Unit Delay'
   */
  rtb_Compare_cf = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S182>/Logical Operator' incorporates:
   *  Logic: '<S182>/NOT'
   */
  *rty_IsBlueActive = ((!(rtu_IsBlueInactiveFirst != 0.0)) || rtb_Compare_cf);

  /* Logic: '<S182>/Logical Operator1' */
  *rty_IsRedActive = ((rtu_IsBlueInactiveFirst != 0.0) || rtb_Compare_cf);

  /* Switch: '<S182>/Switch' incorporates:
   *  Constant: '<S182>/Constant1'
   *  Constant: '<S182>/Constant2'
   *  Logic: '<S182>/Logical Operator2'
   *  Sum: '<S182>/Subtract'
   *  Sum: '<S182>/Sum'
   *  UnitDelay: '<S182>/Unit Delay'
   */
  if ((boolean_T)((rtu_IsBlueInactiveFirst != 0.0) ^ (rtu_IsBlueAlliance != 0.0)))
  {
    *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;
  } else {
    *rty_Time_Remaining = (localDW->UnitDelay_DSTATE - 0.02) -
      Rebuilt_Match_Time_Shoot_Early;
  }

  /* End of Switch: '<S182>/Switch' */

  /* Update for UnitDelay: '<S182>/Unit Delay' incorporates:
   *  Constant: '<S182>/Constant1'
   *  Sum: '<S182>/Sum'
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
  real_T rtb_Add_i;
  real_T rtb_Add_lu;
  real_T rtb_Add_mw;
  real_T rtb_Add_pw;
  real_T rtb_Error_n;
  real_T rtb_Hypot_a;
  real_T rtb_Hypot_fg;
  real_T rtb_Hypot_pi;
  real_T rtb_Init;
  real_T rtb_Init_o;
  real_T rtb_Integral_c3;
  real_T rtb_Integral_g;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_MatrixConcatenate_idx_0;
  real_T rtb_Merge1;
  real_T rtb_Minus_f;
  real_T rtb_Minus_k_idx_0;
  real_T rtb_Minus_k_idx_1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Product_c2;
  real_T rtb_Product_d1;
  real_T rtb_Product_f2;
  real_T rtb_Product_i3;
  real_T rtb_Product_in;
  real_T rtb_Product_nq;
  real_T rtb_Saturation_h;
  real_T rtb_Shooter_Motor_Gain_Ki;
  real_T rtb_Subtract1_bm;
  real_T rtb_Subtract1_kg;
  real_T rtb_Subtract_h;
  real_T rtb_Subtract_kb;
  real_T rtb_Sum1;
  real_T rtb_Sum1_ei;
  real_T rtb_Sum1_g;
  real_T rtb_Sum2_fc;
  real_T rtb_Sum2_m;
  real_T rtb_Switch1_h;
  real_T rtb_Switch1_hb;
  real_T rtb_Switch1_m;
  real_T rtb_Switch1_n;
  real_T rtb_Switch2_dh;
  real_T rtb_Switch2_g;
  real_T rtb_Switch2_i;
  real_T rtb_Switch_cn;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s236_iter;
  uint16_T s261_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T Iteration_Number;
  uint8_T rtb_Desired_Pipeline;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4_j;
  boolean_T rtb_Button_Shoot_Enable;
  boolean_T rtb_Button_Spinup_Enable;
  boolean_T rtb_Compare_ky;
  boolean_T rtb_Compare_lk;
  boolean_T rtb_Compare_mq;
  boolean_T rtb_Compare_pb;
  boolean_T rtb_Disable_Wheels;
  boolean_T rtb_Enable_Wheels;
  boolean_T rtb_Intake_Arm_Cycle;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_ms;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_Reset_Wheel_Offsets;
  boolean_T rtb_Shooter_Active_prev;

  /* RelationalOperator: '<S36>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *  UnitDelay: '<S36>/Delay Input1'
   *
   * Block description for '<S36>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Gamepad_B3_X >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S37>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *  UnitDelay: '<S37>/Delay Input1'
   *
   * Block description for '<S37>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets = (Robot_Control_U.Gamepad_B4_Y >
    Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S38>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *  UnitDelay: '<S38>/Delay Input1'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Gamepad_B2_B >
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

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant2'
   *  Constant: '<S39>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Switch2_g = Rate_Limit_X;
  } else {
    rtb_Switch2_g = 1000.0;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Sum: '<S42>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Init_o;

  /* Switch: '<S43>/Switch2' incorporates:
   *  RelationalOperator: '<S43>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Switch2_g)) {
    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant'
     *  Constant: '<S39>/Constant3'
     *  UnaryMinus: '<S39>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_hb = -Rate_Limit_X;
    } else {
      rtb_Switch1_hb = -1000.0;
    }

    /* End of Switch: '<S39>/Switch1' */

    /* Switch: '<S43>/Switch' incorporates:
     *  RelationalOperator: '<S43>/UpperRelop'
     */
    if (rtb_Sum1 < rtb_Switch1_hb) {
      rtb_Switch2_g = rtb_Switch1_hb;
    } else {
      rtb_Switch2_g = rtb_Sum1;
    }

    /* End of Switch: '<S43>/Switch' */
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Sum: '<S42>/Sum' */
  rtb_Sum1 = rtb_Switch2_g + rtb_Init_o;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S47>/Init' incorporates:
   *  UnitDelay: '<S47>/FixPt Unit Delay1'
   *  UnitDelay: '<S47>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_j != 0) {
    rtb_Switch2_g = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Switch2_g = Robot_Control_DW.FixPtUnitDelay1_DSTATE_a;
  }

  /* End of Switch: '<S47>/Init' */

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Constant2'
   *  Constant: '<S40>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Y;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Sum: '<S45>/Sum1' */
  rtb_Switch1_hb = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Switch2_g;

  /* Switch: '<S46>/Switch2' incorporates:
   *  RelationalOperator: '<S46>/LowerRelop1'
   */
  if (!(rtb_Switch1_hb > rtb_Init_o)) {
    /* Switch: '<S40>/Switch1' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant3'
     *  UnaryMinus: '<S40>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_h = -Rate_Limit_Y;
    } else {
      rtb_Switch1_h = -1000.0;
    }

    /* End of Switch: '<S40>/Switch1' */

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
  rtb_Switch1_hb = rtb_Init_o + rtb_Switch2_g;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S50>/Init' incorporates:
   *  UnitDelay: '<S50>/FixPt Unit Delay1'
   *  UnitDelay: '<S50>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Switch2_g = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Switch2_g = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S50>/Init' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant2'
   *  Constant: '<S41>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Z;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Sum: '<S48>/Sum1' */
  rtb_Switch1_h = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Switch2_g;

  /* Switch: '<S49>/Switch2' incorporates:
   *  RelationalOperator: '<S49>/LowerRelop1'
   */
  if (!(rtb_Switch1_h > rtb_Init_o)) {
    /* Switch: '<S41>/Switch1' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/Constant3'
     *  UnaryMinus: '<S41>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_m = -Rate_Limit_Z;
    } else {
      rtb_Switch1_m = -1000.0;
    }

    /* End of Switch: '<S41>/Switch1' */

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
  rtb_Switch1_h = rtb_Init_o + rtb_Switch2_g;

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S34>/Constant'
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

  /* RelationalOperator: '<S35>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* Sum: '<S33>/Add1' incorporates:
   *  Constant: '<S33>/Constant3'
   *  Constant: '<S33>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Math: '<S33>/Math Function'
   *  Sum: '<S33>/Add2'
   */
  rtb_Switch2_g = rt_modd_snf(Robot_Control_U.Gyro_Angle_rad +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* RelationalOperator: '<S32>/GreaterThan' incorporates:
   *  Abs: '<S32>/Abs'
   *  Constant: '<S32>/Constant2'
   */
  rtb_Compare_ky = (fabs(rtb_Switch2_g) > 1.5707963267948966);

  /* Logic: '<S32>/Logical Operator1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   */
  rtb_LogicalOperator1 = ((Robot_Control_U.Joystick_Left_B2) && rtb_Compare_ky);

  /* Logic: '<S32>/Logical Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B3'
   *  Inport: '<Root>/Joystick_Left_B4'
   */
  rtb_Compare_mq = ((Robot_Control_U.Joystick_Left_B3) ||
                    (Robot_Control_U.Joystick_Left_B4));

  /* RelationalOperator: '<S32>/GreaterThan1' incorporates:
   *  Constant: '<S32>/Constant1'
   */
  rtb_Compare_pb = (rtb_Switch2_g > 0.0);

  /* Logic: '<S32>/Logical Operator5' incorporates:
   *  Logic: '<S32>/Logical Operator6'
   */
  rtb_LogicalOperator5 = (rtb_Compare_mq && (!rtb_Compare_pb));

  /* Logic: '<S32>/Logical Operator3' */
  rtb_Compare_pb = (rtb_Compare_mq && rtb_Compare_pb);

  /* Logic: '<S32>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   *  Logic: '<S32>/Logical Operator4'
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

  /* If: '<S458>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S458>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S461>/Action Port'
     */
    /* Product: '<S461>/Product' incorporates:
     *  Constant: '<S461>/Constant1'
     *  Constant: '<S461>/Constant2'
     *  Math: '<S461>/Math Function'
     */
    rtb_Switch2_g = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S458>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S458>/Subsystem' incorporates:
     *  ActionPort: '<S462>/Action Port'
     */
    /* SignalConversion generated from: '<S462>/Out1' incorporates:
     *  Constant: '<S462>/Constant'
     */
    rtb_Switch2_g = 0.0;

    /* End of Outputs for SubSystem: '<S458>/Subsystem' */
  }

  /* End of If: '<S458>/If' */

  /* Gain: '<S459>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Init_o = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S460>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Switch2_g * cos(rtb_Init_o))
    + Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S460>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Switch2_g * sin(rtb_Init_o))
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
    rtb_Compare_ky = false;

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
      Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

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
     *  Constant: '<S21>/Constant4'
     *  Constant: '<S21>/Constant5'
     *  Constant: '<S21>/Constant6'
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
      rtb_MultiportSwitch1[0] = 14;
      rtb_MultiportSwitch1[1] = 15;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 6:
      rtb_MultiportSwitch1[0] = 16;
      rtb_MultiportSwitch1[1] = 17;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 7:
      rtb_MultiportSwitch1[0] = 18;
      rtb_MultiportSwitch1[1] = 22;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 8:
      rtb_MultiportSwitch1[0] = 19;
      rtb_MultiportSwitch1[1] = 23;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 9:
      rtb_MultiportSwitch1[0] = 14;
      rtb_MultiportSwitch1[1] = 20;
      rtb_MultiportSwitch1[2] = 0;
      break;

     default:
      rtb_MultiportSwitch1[0] = 16;
      rtb_MultiportSwitch1[1] = 21;
      rtb_MultiportSwitch1[2] = 0;
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
      rtb_Switch2_dh = 0.0;
    } else {
      rtb_Switch2_dh = Robot_Control_DW.UnitDelay2_DSTATE_d + 0.02;
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
      rtb_Shooter_Active_prev = (rtb_Switch2_dh >= Auto_Deploy_Intake_Time);
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
    rtb_Compare_ky = (Robot_Control_U.IsBlueAlliance != 0.0);

    /* Selector: '<S20>/Selector' */
    i = ((int32_T)Robot_Control_B.Auto_Path_ID) - 1;
    for (rtb_Num_Segments = 0; rtb_Num_Segments < 60; rtb_Num_Segments++) {
      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S20>/Constant1'
       *  Selector: '<S20>/Selector'
       */
      if (rtb_Compare_ky) {
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
      (Robot_Control_B.Auto_Path_ID, 1.0, 1.0, 22U)];

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
      rtb_Switch2_g = 0.0;
    } else {
      rtb_Switch2_g = Robot_Control_DW.UnitDelay_DSTATE_h + 0.02;
    }

    /* End of Switch: '<S22>/Switch1' */

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S30>/Constant'
     *  RelationalOperator: '<S30>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Switch2_g >= Auto_Intake_Arm_Cycle_Delay_Time) &&
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
      rtb_LogicalOperator1_ms = false;
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
      rtb_LogicalOperator1_ms = false;
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
      rtb_LogicalOperator1_ms = false;
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
      rtb_LogicalOperator1_ms = true;
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
    rtb_Compare_ky = false;

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
    Robot_Control_DW.UnitDelay2_DSTATE_d = rtb_Switch2_dh;

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
    Robot_Control_DW.UnitDelay_DSTATE_h = rtb_Switch2_g;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S431>/Unit Delay1'
       *  UnitDelay: '<S431>/Unit Delay2'
       *  UnitDelay: '<S431>/Unit Delay3'
       *  UnitDelay: '<S431>/Unit Delay4'
       *  UnitDelay: '<S434>/Delay Input1'
       *  UnitDelay: '<S435>/Delay Input1'
       *  UnitDelay: '<S436>/Delay Input1'
       *  UnitDelay: '<S437>/Delay Input1'
       *  UnitDelay: '<S439>/Delay Input1'
       *  UnitDelay: '<S445>/Unit Delay'
       *  UnitDelay: '<S445>/Unit Delay1'
       *  UnitDelay: '<S449>/FixPt Unit Delay1'
       *  UnitDelay: '<S449>/FixPt Unit Delay2'
       *
       * Block description for '<S434>/Delay Input1':
       *
       *  Store in Global RAM
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
       * Block description for '<S439>/Delay Input1':
       *
       *  Store in Global RAM
       */
      Robot_Control_DW.DelayInput1_DSTATE_jp = false;
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

    /* Switch: '<S429>/Switch4' incorporates:
     *  Constant: '<S454>/Constant'
     *  Constant: '<S457>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S454>/Compare'
     *  RelationalOperator: '<S457>/Compare'
     *  Switch: '<S429>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S429>/Switch4' incorporates:
       *  Constant: '<S429>/Constant8'
       *  Sum: '<S429>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S429>/Switch5' incorporates:
       *  Constant: '<S429>/Constant7'
       *  Gain: '<S429>/Gain'
       *  Sum: '<S429>/Subtract5'
       *  Switch: '<S429>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S429>/Switch4' incorporates:
       *  Constant: '<S429>/Constant6'
       *  Switch: '<S429>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S429>/Switch4' */

    /* Logic: '<S429>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S429>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S431>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Minus_f = 0.0;
    } else {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S431>/Add' incorporates:
     *  Constant: '<S431>/Constant'
     *  Constant: '<S431>/Constant1'
     *  DeadZone: '<S431>/Dead Zone'
     *  Lookup_n-D: '<S431>/Modulation_Str_Y_Rel'
     *  Product: '<S431>/Product'
     *  Product: '<S431>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Minus_f *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S433>/Compare' incorporates:
     *  Constant: '<S433>/Constant'
     */
    rtb_Compare_lk = (rtb_Switch1_m == 0.0);

    /* Logic: '<S431>/AND2' incorporates:
     *  RelationalOperator: '<S434>/FixPt Relational Operator'
     *  RelationalOperator: '<S435>/FixPt Relational Operator'
     *  RelationalOperator: '<S436>/FixPt Relational Operator'
     *  RelationalOperator: '<S437>/FixPt Relational Operator'
     *  UnitDelay: '<S434>/Delay Input1'
     *  UnitDelay: '<S435>/Delay Input1'
     *  UnitDelay: '<S436>/Delay Input1'
     *  UnitDelay: '<S437>/Delay Input1'
     *
     * Block description for '<S434>/Delay Input1':
     *
     *  Store in Global RAM
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
     */
    rtb_Intake_Arm_Cycle = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_Compare_pb) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S431>/AND1' incorporates:
     *  Logic: '<S431>/AND3'
     *  UnitDelay: '<S431>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_lk && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S431>/AND4' incorporates:
     *  Logic: '<S431>/AND8'
     *  UnitDelay: '<S431>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_lk && (!rtb_Intake_Arm_Cycle)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S431>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* Switch: '<S431>/Switch8' incorporates:
     *  Constant: '<S440>/Constant'
     *  Logic: '<S431>/AND9'
     *  RelationalOperator: '<S439>/FixPt Relational Operator'
     *  RelationalOperator: '<S440>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S439>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S439>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_lk) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_jp)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_DW.UnitDelay1_DSTATE_nl)) {
      /* Switch: '<S431>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S431>/Switch8' incorporates:
       *  UnitDelay: '<S431>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S431>/Switch8' */

    /* Switch: '<S431>/Switch4' incorporates:
     *  Constant: '<S431>/Constant5'
     *  Switch: '<S431>/Switch1'
     *  Switch: '<S431>/Switch5'
     *  Switch: '<S431>/Switch6'
     *  Switch: '<S431>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Saturation_h = 0.0;
    } else if (rtb_Compare_pb) {
      /* Switch: '<S431>/Switch5' incorporates:
       *  Constant: '<S431>/Constant6'
       */
      rtb_Saturation_h = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S431>/Switch6' incorporates:
       *  Constant: '<S431>/Constant7'
       *  Switch: '<S431>/Switch5'
       */
      rtb_Saturation_h = 3.1415926535897931;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S431>/Switch7' incorporates:
       *  Constant: '<S431>/Constant8'
       *  Switch: '<S431>/Switch5'
       *  Switch: '<S431>/Switch6'
       */
      rtb_Saturation_h = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S431>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S431>/Switch5'
       *  Switch: '<S431>/Switch6'
       *  Switch: '<S431>/Switch7'
       */
      rtb_Saturation_h = 0.0;
    } else {
      /* Switch: '<S431>/Switch6' incorporates:
       *  Switch: '<S431>/Switch5'
       *  Switch: '<S431>/Switch7'
       *  UnitDelay: '<S431>/Unit Delay1'
       */
      rtb_Saturation_h = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S431>/Switch4' */

    /* Switch: '<S431>/Switch2' incorporates:
     *  Switch: '<S431>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S431>/Switch2' incorporates:
       *  Constant: '<S431>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S431>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Saturation_h;
    } else {
      /* Switch: '<S431>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S431>/Switch3' incorporates:
       *  Constant: '<S431>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S431>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S431>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S430>/Switch1' incorporates:
     *  Constant: '<S430>/Constant5'
     *  Constant: '<S430>/Constant8'
     *  DataTypeConversion: '<S430>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_mq = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Compare_mq = rtb_Compare_lk;
    }

    /* End of Switch: '<S430>/Switch1' */

    /* Lookup_n-D: '<S432>/Modulation_Drv' incorporates:
     *  Math: '<S432>/Magnitude'
     */
    rtb_Init_o = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S443>/Compare' incorporates:
     *  Constant: '<S443>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Init_o == 0.0);

    /* DeadZone: '<S432>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_Switch2_g = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_Switch2_g = 0.0;
    } else {
      rtb_Switch2_g = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S432>/Dead Zone' */

    /* Logic: '<S432>/Logical Operator' incorporates:
     *  Constant: '<S444>/Constant'
     *  RelationalOperator: '<S444>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Switch2_g != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S430>/Switch' incorporates:
     *  Constant: '<S430>/Constant5'
     *  Constant: '<S430>/Constant7'
     *  DataTypeConversion: '<S430>/Data Type Conversion'
     *  Logic: '<S432>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_ky = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Compare_ky = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S430>/Switch' */

    /* Switch: '<S429>/Switch2' incorporates:
     *  Constant: '<S429>/Constant2'
     *  Constant: '<S453>/Constant'
     *  Constant: '<S456>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S453>/Compare'
     *  RelationalOperator: '<S456>/Compare'
     *  Sum: '<S429>/Subtract'
     *  Switch: '<S429>/Switch'
     *  Switch: '<S429>/Switch1'
     *  Switch: '<S429>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S429>/Switch2' incorporates:
       *  Constant: '<S429>/Constant5'
       *  Sum: '<S429>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_i = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S429>/Switch2' incorporates:
       *  Constant: '<S429>/Constant4'
       *  Sum: '<S429>/Subtract2'
       *  Switch: '<S429>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S429>/Switch1' incorporates:
       *  Constant: '<S429>/Constant1'
       *  Sum: '<S429>/Subtract3'
       */
      rtb_Switch2_i = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S429>/Switch2' incorporates:
       *  Constant: '<S429>/Constant3'
       *  Switch: '<S429>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S429>/Switch1' incorporates:
       *  Constant: '<S429>/Constant'
       */
      rtb_Switch2_i = 0.0;
    }

    /* End of Switch: '<S429>/Switch2' */

    /* UnaryMinus: '<S429>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_i;

    /* Switch: '<S445>/Switch1' incorporates:
     *  Constant: '<S450>/Constant'
     *  Constant: '<S451>/Constant'
     *  Logic: '<S445>/AND'
     *  RelationalOperator: '<S450>/Compare'
     *  RelationalOperator: '<S451>/Compare'
     *  Switch: '<S445>/Switch2'
     *  UnitDelay: '<S445>/Unit Delay'
     *  UnitDelay: '<S445>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_dh = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1_n = rtb_Switch1_hb;
      rtb_Switch2_dh = rtb_Sum1;
    }

    /* End of Switch: '<S445>/Switch1' */

    /* Switch: '<S432>/Switch1' incorporates:
     *  Logic: '<S432>/Logical Operator1'
     *  Switch: '<S432>/Switch4'
     *  Switch: '<S432>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S432>/Sign' */
      if (rtIsNaN(rtb_Switch2_g)) {
        rtb_Minus_f = (rtNaN);
      } else if (rtb_Switch2_g < 0.0) {
        rtb_Minus_f = -1.0;
      } else {
        rtb_Minus_f = (rtb_Switch2_g > 0.0);
      }

      /* Switch: '<S432>/Switch5' incorporates:
       *  Constant: '<S432>/Constant3'
       *  Constant: '<S432>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S432>/Gain3'
       *  Signum: '<S432>/Sign'
       *  Sum: '<S432>/Add'
       *  Switch: '<S432>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Minus_f) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S432>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S432>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S432>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S432>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S432>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S432>/Switch4'
       *  Trigonometry: '<S432>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1_n,
        rtb_Switch2_dh);
    }

    /* End of Switch: '<S432>/Switch1' */

    /* Switch: '<S442>/Switch1' incorporates:
     *  Constant: '<S442>/Constant'
     *  Constant: '<S442>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_i = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_i = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S442>/Switch1' */

    /* Switch: '<S449>/Init' incorporates:
     *  UnitDelay: '<S449>/FixPt Unit Delay1'
     *  UnitDelay: '<S449>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_i;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S449>/Init' */

    /* Sum: '<S447>/Sum1' */
    rtb_Switch2_i -= rtb_Init;

    /* Switch: '<S448>/Switch2' incorporates:
     *  Constant: '<S446>/Constant1'
     *  Constant: '<S446>/Constant3'
     *  RelationalOperator: '<S448>/LowerRelop1'
     *  RelationalOperator: '<S448>/UpperRelop'
     *  Switch: '<S448>/Switch'
     */
    if (rtb_Switch2_i > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_i = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_i < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S448>/Switch' incorporates:
       *  Constant: '<S446>/Constant1'
       */
      rtb_Switch2_i = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S448>/Switch2' */

    /* Sum: '<S447>/Sum' */
    rtb_Init += rtb_Switch2_i;

    /* Switch: '<S432>/Switch8' incorporates:
     *  Logic: '<S432>/Logical Operator1'
     *  Switch: '<S432>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S432>/Switch' incorporates:
       *  Gain: '<S432>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Switch2_g;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S432>/Constant5'
       *  Gain: '<S432>/Gain2'
       *  Math: '<S432>/Magnitude1'
       *  MinMax: '<S432>/Min'
       *  Switch: '<S432>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S442>/Product' incorporates:
       *  Switch: '<S432>/Switch2'
       */
      rtb_Add_mw = rtb_Init_o * rtb_Init;

      /* Saturate: '<S442>/Saturation' incorporates:
       *  Switch: '<S432>/Switch2'
       */
      if (rtb_Add_mw > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_mw < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_mw;
      }

      /* End of Saturate: '<S442>/Saturation' */
    }

    /* End of Switch: '<S432>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S431>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Switch: '<S429>/Switch6' incorporates:
     *  Constant: '<S429>/Constant11'
     *  Switch: '<S429>/Switch7'
     */
    rtb_Desired_Pipeline = TEST_Pipeline;

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

    /* RelationalOperator: '<S425>/Compare' incorporates:
     *  Constant: '<S425>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S426>/Compare' incorporates:
     *  Constant: '<S426>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S421>/Compare' incorporates:
     *  Constant: '<S421>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S424>/Compare' incorporates:
     *  Constant: '<S424>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S423>/Compare' incorporates:
     *  Constant: '<S423>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Constant: '<S422>/Constant'
     *  Constant: '<S427>/Constant'
     *  Inport: '<Root>/Gamepad_LT'
     *  Inport: '<Root>/Joystick_Right_B1'
     *  RelationalOperator: '<S422>/Compare'
     *  RelationalOperator: '<S427>/Compare'
     */
    rtb_LogicalOperator1_ms = ((Robot_Control_U.Joystick_Right_B1 != 0.0) ||
      (Robot_Control_U.Gamepad_LT != 0.0));

    /* SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     */
    rtb_Switch1_m = 0.0;

    /* Update for UnitDelay: '<S439>/Delay Input1'
     *
     * Block description for '<S439>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_jp = rtb_Compare_lk;

    /* Update for UnitDelay: '<S438>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S438>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S434>/Delay Input1'
     *
     * Block description for '<S434>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S435>/Delay Input1'
     *
     * Block description for '<S435>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_Compare_pb;

    /* Update for UnitDelay: '<S436>/Delay Input1'
     *
     * Block description for '<S436>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S437>/Delay Input1'
     *
     * Block description for '<S437>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S431>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S431>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S431>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S431>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S445>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1_n;

    /* Update for UnitDelay: '<S445>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2_dh;

    /* Update for UnitDelay: '<S449>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S449>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S449>/FixPt Unit Delay1' */
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
    rtb_Compare_ky = false;

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
      rtb_Shooter_Active_prev = true;
    } else {
      rtb_Shooter_Active_prev = ((!Robot_Control_B.Button_Enable_Wheels) &&
        (Robot_Control_DW.UnitDelay_DSTATE_ir));
    }

    /* End of Switch: '<S16>/Switch' */

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

  /* Reshape: '<S77>/Reshapey' incorporates:
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

  /* Delay: '<S77>/MemoryX' incorporates:
   *  Constant: '<S77>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S104>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S130>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S97>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S128>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S128>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S77>/C'
     *  Delay: '<S77>/MemoryX'
     *  Product: '<S130>/Product'
     */
    rtb_Switch1_n = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Switch1_n;

    /* Sum: '<S128>/Sum' incorporates:
     *  Constant: '<S77>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S128>/C[k]*xhat[k|k-1]'
     *  Product: '<S128>/D[k]*u[k]'
     *  Sum: '<S128>/Add1'
     */
    rtb_Init_o = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Switch2_dh = rtb_Reshapey[0] - (rtb_Init_o + rtb_Switch1_n);

    /* Product: '<S128>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S77>/C'
     *  Delay: '<S77>/MemoryX'
     *  Product: '<S130>/Product'
     */
    rtb_Switch1_n = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Switch1_n;

    /* Sum: '<S128>/Sum' incorporates:
     *  Constant: '<S77>/D'
     *  Product: '<S128>/C[k]*xhat[k|k-1]'
     *  Product: '<S128>/D[k]*u[k]'
     *  Sum: '<S128>/Add1'
     */
    rtb_Switch1_n = rtb_Reshapey[1] - (rtb_Init_o + rtb_Switch1_n);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S128>/Product3' incorporates:
     *  Constant: '<S78>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Switch2_dh) +
      (-2.0601714451538746E-17 * rtb_Switch1_n);

    /* Sum: '<S130>/Add1' incorporates:
     *  Product: '<S130>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S128>/Product3' incorporates:
     *  Constant: '<S78>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Switch2_dh) +
      (0.095124921972504 * rtb_Switch1_n);

    /* Sum: '<S130>/Add1' incorporates:
     *  Product: '<S130>/Product'
     */
    rtb_Switch1_n = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S130>/Product2' incorporates:
     *  Constant: '<S78>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Switch1_n);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Switch1_n);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S128>/Product3' incorporates:
       *  Outport: '<S128>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S130>/Product2' incorporates:
       *  Outport: '<S130>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S97>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S104>/Enabled Subsystem' */

  /* Sum: '<S104>/Add' incorporates:
   *  Delay: '<S77>/MemoryX'
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
   *  Constant: '<S261>/Constant'
   *  Logic: '<S261>/AND'
   *  MATLAB Function: '<S211>/Find closest index to curve'
   *  Product: '<S261>/Product'
   *  RelationalOperator: '<S261>/Relational Operator'
   *  RelationalOperator: '<S261>/Relational Operator1'
   *  Selector: '<S261>/Selector'
   *  Selector: '<S261>/Selector1'
   *  Selector: '<S262>/Selector'
   *  Sum: '<S261>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S214>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S217>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S219>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S214>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S209>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S209>/Unit Delay'
       *  UnitDelay: '<S210>/Unit Delay'
       *  UnitDelay: '<S212>/Unit Delay'
       *  UnitDelay: '<S212>/Unit Delay1'
       *  UnitDelay: '<S262>/Unit Delay'
       *  UnitDelay: '<S262>/Unit Delay1'
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
     *  ActionPort: '<S209>/Action Port'
     */
    /* Selector: '<S210>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S210>/Selector1' */

    /* Lookup_n-D: '<S209>/Capture Radius' incorporates:
     *  UnitDelay: '<S209>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S210>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S210>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S214>/If' incorporates:
     *  RelationalOperator: '<S214>/ '
     *  UnitDelay: '<S210>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S217>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S219>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S214>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S217>/Action Port'
       */
      /* InitializeConditions for If: '<S214>/If' incorporates:
       *  UnitDelay: '<S217>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S214>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S214>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S217>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S217>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S220>/Action Port'
       */
      /* If: '<S217>/If' incorporates:
       *  Selector: '<S210>/Selector1'
       *  Selector: '<S217>/Selector'
       *  Selector: '<S220>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S217>/Increment_If_Rectangle_Check' */

      /* Sum: '<S217>/Minus' incorporates:
       *  Concatenate: '<S210>/Matrix Concatenate2'
       *  Selector: '<S217>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S217>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S220>/Action Port'
       */
      /* If: '<S217>/If' incorporates:
       *  Selector: '<S210>/Selector1'
       *  Selector: '<S217>/Selector'
       *  Selector: '<S220>/Selector'
       *  Sum: '<S217>/Minus'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh)
        + 9];

      /* End of Outputs for SubSystem: '<S217>/Increment_If_Rectangle_Check' */

      /* Sum: '<S217>/Minus' incorporates:
       *  Concatenate: '<S210>/Matrix Concatenate2'
       *  Selector: '<S217>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Init_o;

      /* Math: '<S217>/Hypot' */
      rtb_Switch1_n = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S217>/Equal' */
      rtb_LogicalOperator5 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S217>/Switch' incorporates:
       *  Logic: '<S217>/AND'
       *  Logic: '<S217>/OR'
       *  RelationalOperator: '<S217>/Relational Operator'
       *  UnitDelay: '<S217>/Unit Delay'
       */
      rtb_LogicalOperator1 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Switch1_n <= rtb_Saturation_h) && rtb_LogicalOperator5));

      /* If: '<S217>/If' */
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
        /* Disable for If: '<S219>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S217>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S219>/Action Port'
         */
        /* If: '<S219>/If' incorporates:
         *  RelationalOperator: '<S219>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S219>/Is_Last_Point' incorporates:
           *  ActionPort: '<S222>/Action Port'
           */
          /* InitializeConditions for If: '<S219>/If' incorporates:
           *  UnitDelay: '<S222>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S219>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S219>/Is_Last_Point' incorporates:
           *  ActionPort: '<S222>/Action Port'
           */
          /* Switch: '<S222>/Switch' incorporates:
           *  Constant: '<S224>/Constant'
           *  Logic: '<S222>/OR'
           *  RelationalOperator: '<S224>/Compare'
           *  UnitDelay: '<S222>/Unit Delay'
           */
          rtb_Compare_ky = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
                            (rtb_Switch1_n <= Spline_Stop_Radius));

          /* If: '<S222>/If' */
          if (rtb_Compare_ky) {
            /* Outputs for IfAction SubSystem: '<S222>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S225>/Action Port'
             */
            /* Merge: '<S214>/Merge2' incorporates:
             *  Constant: '<S225>/Constant'
             *  SignalConversion generated from: '<S225>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = true;

            /* SignalConversion generated from: '<S225>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S225>/Constant1'
             */
            rtb_Compare_pb = false;

            /* End of Outputs for SubSystem: '<S222>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S222>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S226>/Action Port'
             */
            /* Merge: '<S214>/Merge2' incorporates:
             *  Constant: '<S226>/Constant'
             *  SignalConversion generated from: '<S226>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = false;

            /* SignalConversion generated from: '<S226>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S226>/Constant1'
             */
            rtb_Compare_pb = true;

            /* End of Outputs for SubSystem: '<S222>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S222>/If' */

          /* Merge: '<S214>/Merge4' incorporates:
           *  SignalConversion: '<S222>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S222>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Compare_ky;

          /* End of Outputs for SubSystem: '<S219>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S219>/Increment_Search' incorporates:
           *  ActionPort: '<S221>/Action Port'
           */
          /* Merge: '<S214>/Merge2' incorporates:
           *  Constant: '<S221>/Constant'
           *  SignalConversion generated from: '<S221>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator5 = false;

          /* SignalConversion generated from: '<S221>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S221>/Constant1'
           */
          rtb_Compare_pb = false;

          /* Merge: '<S214>/Merge4' incorporates:
           *  Constant: '<S223>/FixPt Constant'
           *  SignalConversion: '<S221>/Signal Copy'
           *  Sum: '<S223>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S219>/Increment_Search' */
        }

        /* End of If: '<S219>/If' */
        /* End of Outputs for SubSystem: '<S217>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S217>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S220>/Action Port'
         */
        /* Sum: '<S227>/FixPt Sum1' incorporates:
         *  Constant: '<S227>/FixPt Constant'
         */
        rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S220>/Selector1' incorporates:
         *  Selector: '<S210>/Selector1'
         */
        rtb_Switch2_i = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) - 1];

        /* Sum: '<S228>/Subtract' incorporates:
         *  Selector: '<S220>/Selector1'
         *  Sum: '<S228>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_i - rtb_Init;

        /* Selector: '<S220>/Selector1' incorporates:
         *  Selector: '<S210>/Selector1'
         */
        rtb_Switch2_g = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) + 9];

        /* Sum: '<S228>/Subtract' incorporates:
         *  Selector: '<S220>/Selector1'
         *  Sum: '<S228>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch2_g - rtb_Init_o;

        /* Math: '<S228>/Hypot' */
        rtb_Switch2_dh = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S228>/Divide' */
        rtb_Switch1_n = rtb_Minus_n[1];

        /* UnaryMinus: '<S228>/Unary Minus' */
        rtb_Minus_f = rtb_Minus_n[0];

        /* Product: '<S228>/Product' incorporates:
         *  Product: '<S228>/Divide'
         *  UnaryMinus: '<S228>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch1_n / rtb_Switch2_dh) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Minus_f) / rtb_Switch2_dh) * rtb_Saturation_h;

        /* Sum: '<S228>/Add1' incorporates:
         *  Sum: '<S228>/Add2'
         *  Sum: '<S228>/Minus'
         */
        rtb_Minus_f = rtb_Switch2_i - rtb_Minus_n[0];

        /* Sum: '<S228>/Minus4' incorporates:
         *  Sum: '<S228>/Add2'
         *  Sum: '<S228>/Minus'
         */
        rtb_Switch2_i = (rtb_Switch2_i + rtb_Minus_n[0]) - rtb_Minus_f;

        /* Sum: '<S228>/Minus5' incorporates:
         *  Concatenate: '<S210>/Matrix Concatenate2'
         *  Sum: '<S228>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[0] - rtb_Minus_f;

        /* Sum: '<S228>/Add' incorporates:
         *  Sum: '<S228>/Add2'
         *  Sum: '<S228>/Minus1'
         */
        rtb_Switch1_n = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S228>/Minus' incorporates:
         *  Sum: '<S228>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S228>/Dot Product' incorporates:
         *  Concatenate: '<S210>/Matrix Concatenate2'
         *  Sum: '<S228>/Minus'
         *  Sum: '<S228>/Minus1'
         *  Sum: '<S228>/Minus5'
         */
        rtb_Switch2_dh = (rtb_Reshapey[0] - rtb_Switch1_n) * rtb_Minus_f;

        /* DotProduct: '<S228>/Dot Product1' incorporates:
         *  Sum: '<S228>/Minus'
         */
        rtb_Init = rtb_Minus_f * rtb_Minus_f;

        /* DotProduct: '<S228>/Dot Product2' incorporates:
         *  Sum: '<S228>/Minus4'
         *  Sum: '<S228>/Minus5'
         */
        rtb_Minus_k_idx_0 = rtb_Switch2_i * rtb_MatrixConcatenate_b_idx_0;

        /* DotProduct: '<S228>/Dot Product3' incorporates:
         *  Sum: '<S228>/Minus4'
         */
        rtb_Optimized_Module_Angle = rtb_Switch2_i * rtb_Switch2_i;

        /* Sum: '<S228>/Add1' incorporates:
         *  Sum: '<S228>/Add2'
         *  Sum: '<S228>/Minus'
         */
        rtb_Minus_f = rtb_Switch2_g - rtb_Minus_n[1];

        /* Sum: '<S228>/Minus4' incorporates:
         *  Sum: '<S228>/Add2'
         *  Sum: '<S228>/Minus'
         */
        rtb_Switch2_i = (rtb_Switch2_g + rtb_Minus_n[1]) - rtb_Minus_f;

        /* Sum: '<S228>/Minus5' incorporates:
         *  Concatenate: '<S210>/Matrix Concatenate2'
         *  Sum: '<S228>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[1] - rtb_Minus_f;

        /* Sum: '<S228>/Add' incorporates:
         *  Sum: '<S228>/Add2'
         *  Sum: '<S228>/Minus1'
         */
        rtb_Switch1_n = rtb_Init_o - rtb_Minus_n[1];

        /* Sum: '<S228>/Minus' incorporates:
         *  Sum: '<S228>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S228>/Dot Product' incorporates:
         *  Concatenate: '<S210>/Matrix Concatenate2'
         *  Sum: '<S228>/Minus'
         *  Sum: '<S228>/Minus1'
         *  Sum: '<S228>/Minus5'
         */
        rtb_Switch2_dh += (rtb_Reshapey[1] - rtb_Switch1_n) * rtb_Minus_f;

        /* RelationalOperator: '<S229>/Compare' incorporates:
         *  Constant: '<S229>/Constant'
         */
        rtb_LogicalOperator5 = (rtb_Switch2_dh >= 0.0);

        /* RelationalOperator: '<S228>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S228>/Dot Product1'
         *  Sum: '<S228>/Minus'
         */
        rtb_Compare_pb = (rtb_Switch2_dh <= ((rtb_Minus_f * rtb_Minus_f) +
          rtb_Init));

        /* DotProduct: '<S228>/Dot Product2' incorporates:
         *  Sum: '<S228>/Minus4'
         *  Sum: '<S228>/Minus5'
         */
        rtb_Switch2_dh = (rtb_Switch2_i * rtb_MatrixConcatenate_b_idx_0) +
          rtb_Minus_k_idx_0;

        /* Merge: '<S214>/Merge4' incorporates:
         *  Constant: '<S230>/Constant'
         *  DataTypeConversion: '<S220>/Data Type Conversion'
         *  DotProduct: '<S228>/Dot Product3'
         *  Logic: '<S228>/AND'
         *  RelationalOperator: '<S228>/LessThanOrEqual1'
         *  RelationalOperator: '<S230>/Compare'
         *  Sum: '<S220>/Add'
         *  Sum: '<S228>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_LogicalOperator5 &&
          rtb_Compare_pb) && (rtb_Switch2_dh >= 0.0)) && (rtb_Switch2_dh <=
          ((rtb_Switch2_i * rtb_Switch2_i) + rtb_Optimized_Module_Angle)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S214>/Merge2' incorporates:
         *  Constant: '<S220>/Constant2'
         *  SignalConversion generated from: '<S220>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S220>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S220>/Constant1'
         */
        rtb_Compare_pb = false;

        /* End of Outputs for SubSystem: '<S217>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S217>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S218>/Action Port'
         */
        /* Merge: '<S214>/Merge2' incorporates:
         *  Constant: '<S218>/Constant2'
         *  SignalConversion generated from: '<S218>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S218>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S218>/Constant1'
         */
        rtb_Compare_pb = false;

        /* Merge: '<S214>/Merge4' incorporates:
         *  SignalConversion generated from: '<S218>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S217>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S214>/Merge1' incorporates:
       *  Constant: '<S217>/Constant'
       *  SignalConversion generated from: '<S217>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S217>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator1;

      /* End of Outputs for SubSystem: '<S214>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S214>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S216>/Action Port'
       */
      /* Merge: '<S214>/Merge1' incorporates:
       *  Constant: '<S216>/Constant'
       *  SignalConversion generated from: '<S216>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S214>/Merge2' incorporates:
       *  Constant: '<S216>/Constant1'
       *  SignalConversion generated from: '<S216>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator5 = false;

      /* SignalConversion generated from: '<S216>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S216>/Constant2'
       */
      rtb_Compare_pb = false;

      /* Merge: '<S214>/Merge4' incorporates:
       *  SignalConversion generated from: '<S216>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S214>/Escape_Auto_Driving' */
    }

    /* End of If: '<S214>/If' */

    /* If: '<S210>/If1' */
    if (!rtb_Compare_pb) {
      /* Outputs for IfAction SubSystem: '<S210>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S215>/Action Port'
       */
      /* Bias: '<S231>/Add Constant' incorporates:
       *  Bias: '<S231>/Bias'
       *  Sum: '<S231>/Subtract'
       */
      rtb_Switch1_n = ((Robot_Control_B.Spline_Num_Poses -
                        Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S231>/Selector4' incorporates:
       *  Bias: '<S231>/Bias1'
       *  Constant: '<S233>/FixPt Constant'
       *  Sum: '<S233>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S231>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S231>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s236_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S231>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S231>/Selector5' incorporates:
       *  Concatenate: '<S231>/Matrix Concatenate'
       *  Gain: '<S235>/Gain'
       *  Selector: '<S210>/Selector1'
       *  Selector: '<S231>/Selector2'
       *  Selector: '<S231>/Selector3'
       *  Sum: '<S235>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s236_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S231>/Matrix Concatenate' incorporates:
       *  Bias: '<S231>/Add Constant1'
       *  Gain: '<S234>/Gain'
       *  Selector: '<S210>/Selector1'
       *  Selector: '<S231>/Selector'
       *  Selector: '<S231>/Selector1'
       *  Selector: '<S231>/Selector5'
       *  Sum: '<S234>/Subtract'
       */
      s236_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s236_iter;
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

      /* Selector: '<S231>/Selector4' */
      s236_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s236_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S231>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S231>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S231>/Assignment' incorporates:
       *  Concatenate: '<S231>/Matrix Concatenate'
       *  Selector: '<S231>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s236_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S232>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S236>/While Iterator'
       */
      s236_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s236_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s236_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s236_iter] - rtb_Assignment[s236_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Init - rtb_Assignment[s236_iter];
        rtb_Init = rtb_Assignment[s236_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s236_iter + 11];
        rtb_Minus_f = rtb_Assignment[s236_iter + 12];
        rtb_Add2[1] = rtb_Minus_f - rtb_Assignment[s236_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Init - rtb_Minus_f;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Switch2_dh = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Init_o = rt_powd_snf(rtb_Switch2_dh, 2.0);
          rtb_Switch2_i = rt_powd_snf(rtb_Switch2_dh, 3.0);
          rtb_Switch2_g = (rtb_Switch2_dh - (2.0 * rtb_Init_o)) + rtb_Switch2_i;
          rtb_Init = rtb_Init_o - rtb_Switch2_i;
          rtb_Switch2_i = (3.0 * rtb_Init_o) - (2.0 * rtb_Switch2_i);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch2_g) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Switch2_i)) + rtb_Assignment[s236_iter];
          rtb_Switch2_i = ((((rtb_Minus_n[1] * rtb_Switch2_g) + (rtb_Add2[1] *
            rtb_Init)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_i)) +
            rtb_Minus_f;
          rtb_Switch2_g = ((3.0 * rtb_Init_o) - (4.0 * rtb_Switch2_dh)) + 1.0;
          rtb_Init = (2.0 * rtb_Switch2_dh) - (3.0 * rtb_Init_o);
          rtb_Init_o = (rtb_Switch2_dh - rtb_Init_o) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch2_g) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Init_o);
          rtb_Optimized_Module_Angle = (((rtb_Minus_n[1] * rtb_Switch2_g) +
            (rtb_Add2[1] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Init_o);
          rtb_Init_o = (6.0 * rtb_Switch2_dh) - 4.0;
          rtb_Switch2_g = (-6.0 * rtb_Switch2_dh) + 2.0;
          rtb_Switch2_dh = (-12.0 * rtb_Switch2_dh) + 6.0;
          rtb_Init = (((rtb_Minus_n[0] * rtb_Init_o) + (rtb_Add2[0] *
            rtb_Switch2_g)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Switch2_dh);
          rtb_Switch2_g = (((rtb_Minus_n[1] * rtb_Init_o) + (rtb_Add2[1] *
            rtb_Switch2_g)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_dh);
          rtb_Init_o = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Optimized_Module_Angle), 3.0);
          rtb_Switch2_dh = fmax(1.0E-10, rtb_Init_o);
          Robot_Control_DW.Relay_Mode = ((rtb_Init_o >= 2.2204460492503131E-16) ||
            (Robot_Control_DW.Relay_Mode));
          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Switch2_i;
          if (Robot_Control_DW.Relay_Mode) {
            i = 1;
          } else {
            i = -1;
          }

          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch2_g) - (rtb_Init *
              rtb_Optimized_Module_Angle)) / (rtb_Switch2_dh * ((real_T)i));
        }

        if (s236_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s236_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Switch2_dh = rtb_Switch1_n - ((real_T)s236_iter);
        rtb_Num_Segments = s236_iter;
        s236_iter++;
      } while ((rtb_Switch2_dh >= 4.0) && (s236_iter <= 3));

      /* End of Outputs for SubSystem: '<S232>/Sampling_Loop' */

      /* SignalConversion generated from: '<S215>/Position_and_Curvature' incorporates:
       *  Assignment: '<S236>/Assignment'
       *  Merge: '<S210>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S210>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S210>/If Action Subsystem' incorporates:
       *  ActionPort: '<S213>/Action Port'
       */
      /* Product: '<S213>/Product' incorporates:
       *  Selector: '<S210>/Selector'
       *  Selector: '<S210>/Selector1'
       */
      rtb_Switch2_dh = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S213>/Product1' incorporates:
       *  Selector: '<S210>/Selector'
       *  Selector: '<S210>/Selector1'
       */
      rtb_Switch1_n = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S213>/Product' incorporates:
         *  Constant: '<S213>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Switch2_dh;

        /* Product: '<S213>/Product1' incorporates:
         *  Constant: '<S213>/Constant2'
         *  Product: '<S213>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch1_n;
      }

      /* Assignment: '<S213>/Assignment' incorporates:
       *  Concatenate: '<S213>/Matrix Concatenate'
       *  Merge: '<S210>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S213>/Assignment' */

      /* SignalConversion generated from: '<S213>/Num_Segments' incorporates:
       *  Constant: '<S213>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S210>/If Action Subsystem' */
    }

    /* End of If: '<S210>/If1' */

    /* Concatenate: '<S211>/Matrix Concatenate' incorporates:
     *  Merge: '<S210>/Merge'
     *  Selector: '<S211>/Selector'
     *  Selector: '<S211>/Selector1'
     *  Selector: '<S211>/Selector3'
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

    /* End of Concatenate: '<S211>/Matrix Concatenate' */

    /* MATLAB Function: '<S211>/Distance Along Curve' incorporates:
     *  Concatenate: '<S211>/Matrix Concatenate'
     *  Selector: '<S211>/Selector4'
     *  Selector: '<S211>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s236_iter = 0; s236_iter < 149; s236_iter++) {
      /* Outputs for Iterator SubSystem: '<S232>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S236>/While Iterator'
       */
      rtb_Assignment_d[s236_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s236_iter + 1] -
         rtb_MatrixConcatenate_o[s236_iter], rtb_MatrixConcatenate_o[s236_iter +
         151] - rtb_MatrixConcatenate_o[s236_iter + 150]) +
        rtb_Assignment_d[s236_iter];

      /* End of Outputs for SubSystem: '<S232>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S211>/Distance Along Curve' */

    /* MATLAB Function: '<S211>/Find closest index to curve' incorporates:
     *  Concatenate: '<S211>/Matrix Concatenate'
     *  Selector: '<S211>/Selector4'
     *  Selector: '<S211>/Selector5'
     *  Selector: '<S262>/Selector'
     */
    for (s236_iter = 0; s236_iter < 150; s236_iter++) {
      /* Outputs for Iterator SubSystem: '<S232>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S236>/While Iterator'
       */
      distance_from_robot[s236_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s236_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s236_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S232>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s236_iter = 1;
    } else {
      s236_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s236_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s236_iter == 0) {
      rtb_Switch1_n = distance_from_robot[0];
    } else {
      rtb_Switch1_n = distance_from_robot[s236_iter - 1];
      for (rtb_Bias1_p = s236_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Switch2_dh = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_n > rtb_Switch2_dh) {
          rtb_Switch1_n = rtb_Switch2_dh;
        }
      }
    }

    s236_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s236_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_n) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S262>/Selector' incorporates:
     *  Constant: '<S262>/Constant'
     *  MATLAB Function: '<S211>/Find closest index to curve'
     *  MinMax: '<S262>/Min'
     */
    rtb_Switch2_dh = rtb_Assignment_d[((int32_T)fmin(50.0, s236_iter)) - 1];

    /* If: '<S262>/If' incorporates:
     *  RelationalOperator: '<S262>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S262>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S265>/Action Port'
       */
      /* SignalConversion generated from: '<S265>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S267>/FixPt Sum1' incorporates:
       *  Constant: '<S267>/FixPt Constant'
       */
      rtb_Switch1_n = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S265>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S265>/Selector11'
       *  Selector: '<S265>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S265>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S265>/Selector1'
       *  Selector: '<S265>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S265>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S265>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_n), &rtb_Minus_n[0], rtb_Switch2_dh,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S265>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S265>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S265>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Switch2_dh,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S262>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S262>/Latch' incorporates:
       *  ActionPort: '<S266>/Action Port'
       */
      /* SignalConversion generated from: '<S266>/In1' incorporates:
       *  UnitDelay: '<S262>/Unit Delay1'
       */
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S266>/In2' incorporates:
       *  UnitDelay: '<S262>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S262>/Latch' */
    }

    /* End of If: '<S262>/If' */

    /* MinMax: '<S209>/Min' incorporates:
     *  Lookup_n-D: '<S209>/Lookahead Distance'
     *  UnitDelay: '<S209>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S211>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S261>/While Iterator'
     */
    s261_iter = 1U;
    rtb_LogicalOperator1 = true;
    while (rtb_LogicalOperator1 && (s261_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S211>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S261>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s261_iter;
      rtb_LogicalOperator1 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s236_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s261_iter++;
    }

    /* End of Outputs for SubSystem: '<S211>/Find first index that meets distance target' */

    /* Switch: '<S264>/Switch' incorporates:
     *  Concatenate: '<S211>/Matrix Concatenate'
     *  Constant: '<S211>/Constant'
     *  Constant: '<S261>/Constant'
     *  Constant: '<S264>/Constant'
     *  Constant: '<S264>/Constant1'
     *  Constant: '<S264>/Constant2'
     *  Constant: '<S264>/Constant3'
     *  Logic: '<S261>/AND'
     *  MATLAB Function: '<S211>/Find closest index to curve'
     *  Math: '<S264>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S264>/Max'
     *  MinMax: '<S264>/Min'
     *  MinMax: '<S264>/Min1'
     *  Product: '<S261>/Product'
     *  Product: '<S264>/Divide'
     *  Product: '<S264>/Product'
     *  Product: '<S264>/Product1'
     *  RelationalOperator: '<S211>/Relational Operator'
     *  RelationalOperator: '<S261>/Relational Operator'
     *  RelationalOperator: '<S261>/Relational Operator1'
     *  Selector: '<S211>/Selector10'
     *  Selector: '<S211>/Selector7'
     *  Selector: '<S211>/Selector8'
     *  Selector: '<S211>/Selector9'
     *  Selector: '<S261>/Selector'
     *  Selector: '<S261>/Selector1'
     *  Selector: '<S262>/Selector'
     *  Sqrt: '<S264>/Sqrt'
     *  Sum: '<S211>/Subtract'
     *  Sum: '<S261>/Add'
     *  Sum: '<S264>/Subtract'
     *  Sum: '<S264>/Subtract1'
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

    /* End of Switch: '<S264>/Switch' */

    /* Logic: '<S212>/OR' */
    rtb_Compare_pb = (rtb_LogicalOperator5 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S212>/Switch1' incorporates:
     *  Switch: '<S212>/Switch'
     *  UnitDelay: '<S212>/Unit Delay'
     */
    if (rtb_Compare_pb) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S212>/Constant3'
       *  SignalConversion: '<S212>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Switch2_dh = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S212>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Switch2_dh = rtb_Merge1;
    }

    /* End of Switch: '<S212>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S212>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Switch2_dh;

    /* Selector: '<S211>/Selector6' incorporates:
     *  Concatenate: '<S211>/Matrix Concatenate'
     *  Selector: '<S211>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S211>/Selector2' incorporates:
     *  Concatenate: '<S211>/Matrix Concatenate'
     *  Selector: '<S211>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S212>/Switch2' incorporates:
     *  Sum: '<S268>/Subtract'
     *  Sum: '<S268>/Subtract1'
     *  Trigonometry: '<S268>/Atan2'
     *  UnitDelay: '<S212>/Unit Delay1'
     */
    if (rtb_Compare_pb) {
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Init_o = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S212>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S212>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Init_o;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S209>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator5;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S209>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S212>/Constant2'
     *  SignalConversion generated from: '<S209>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S212>/Constant5'
     *  SignalConversion generated from: '<S209>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S212>/Constant6'
     *  SignalConversion generated from: '<S209>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S209>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S210>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S209>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S262>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_n;

    /* Update for UnitDelay: '<S262>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S212>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Switch2_dh;

    /* Update for UnitDelay: '<S212>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Init_o;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S208>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S208>/Constant1'
     *  SignalConversion generated from: '<S208>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S208>/Constant'
     *  SignalConversion generated from: '<S208>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S208>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S208>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S208>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S208>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S208>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Compare_ky;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S208>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Compare_mq;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S208>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* UnitDelay: '<S358>/Unit Delay' */
  rtb_Merge1 = Robot_Control_B.Translation_Speed_RL;

  /* Signum: '<S358>/Sign2' */
  if (rtIsNaN(rtb_Merge1)) {
    rtb_Minus_f = (rtNaN);
  } else if (rtb_Merge1 < 0.0) {
    rtb_Minus_f = -1.0;
  } else {
    rtb_Minus_f = (rtb_Merge1 > 0.0);
  }

  /* Signum: '<S358>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S358>/Product1' incorporates:
   *  Signum: '<S358>/Sign1'
   *  Signum: '<S358>/Sign2'
   */
  rtb_Minus_f *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Minus_f)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_f, 256.0);
  }

  /* Switch: '<S358>/Switch' incorporates:
   *  Constant: '<S358>/Constant'
   *  Constant: '<S363>/Constant'
   *  Constant: '<S364>/Constant'
   *  Logic: '<S358>/or'
   *  Product: '<S358>/Product1'
   *  RelationalOperator: '<S363>/Compare'
   *  RelationalOperator: '<S364>/Compare'
   */
  if ((rtb_Merge1 == 0.0) || (((i < 0) ? ((int32_T)((int8_T)(-((int8_T)((uint8_T)
             (-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_g = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Switch2_g = 0.0;
  }

  /* End of Switch: '<S358>/Switch' */

  /* Switch: '<S369>/Init' incorporates:
   *  UnitDelay: '<S369>/FixPt Unit Delay1'
   *  UnitDelay: '<S369>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Init_o = rtb_Switch2_g;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S369>/Init' */

  /* RelationalOperator: '<S365>/Compare' incorporates:
   *  Constant: '<S365>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Switch2_g == 0.0);

  /* RelationalOperator: '<S366>/Compare' incorporates:
   *  Constant: '<S366>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Switch2_g > 0.0);

  /* Abs: '<S358>/Abs' incorporates:
   *  Sum: '<S358>/Subtract'
   */
  rtb_Merge1 = fabs(rtb_Merge1 - Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S358>/Switch5' incorporates:
   *  Constant: '<S358>/Constant1'
   *  Switch: '<S358>/Switch1'
   *  UnaryMinus: '<S358>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S358>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S358>/Constant4'
     *  Constant: '<S358>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S358>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S358>/Constant2'
     *  Constant: '<S358>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S358>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S358>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S358>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S358>/Constant10'
     *  Constant: '<S358>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S358>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S358>/Constant7'
     *  Constant: '<S358>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S358>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S358>/Lookup Table Dynamic1'
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

    /* Switch: '<S358>/Switch3' incorporates:
     *  Constant: '<S358>/Constant1'
     *  Constant: '<S358>/Constant3'
     *  UnaryMinus: '<S358>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      rtb_Minus_f = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Minus_f = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S358>/Switch3' */
  }

  /* End of Switch: '<S358>/Switch5' */

  /* Product: '<S358>/Product' incorporates:
   *  Switch: '<S358>/Switch1'
   */
  rtb_Minus_k_idx_0 = rtb_Minus_f * rtb_Merge1;

  /* Sum: '<S367>/Sum1' */
  rtb_Saturation_h = rtb_Switch2_g - rtb_Init_o;

  /* Switch: '<S368>/Switch2' incorporates:
   *  RelationalOperator: '<S368>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Minus_k_idx_0)) {
    /* Switch: '<S358>/Switch2' incorporates:
     *  Constant: '<S358>/Constant1'
     *  Switch: '<S358>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S358>/Switch4' incorporates:
       *  Constant: '<S358>/Constant1'
       */
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S358>/Switch4' incorporates:
       *  Constant: '<S358>/Constant3'
       *  UnaryMinus: '<S358>/Unary Minus1'
       */
      rtb_Switch1_n = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S358>/Switch2' */

    /* Product: '<S358>/Product2' */
    rtb_Switch1_n *= rtb_Merge1;

    /* Switch: '<S368>/Switch' incorporates:
     *  RelationalOperator: '<S368>/UpperRelop'
     */
    if (rtb_Saturation_h < rtb_Switch1_n) {
      rtb_Minus_k_idx_0 = rtb_Switch1_n;
    } else {
      rtb_Minus_k_idx_0 = rtb_Saturation_h;
    }

    /* End of Switch: '<S368>/Switch' */
  }

  /* End of Switch: '<S368>/Switch2' */

  /* Sum: '<S367>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Minus_k_idx_0 + rtb_Init_o;

  /* Switch: '<S361>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S361>/Switch' incorporates:
     *  Constant: '<S395>/Constant3'
     *  Constant: '<S395>/Constant4'
     *  Math: '<S395>/Math Function'
     *  Sum: '<S361>/Subtract'
     *  Sum: '<S395>/Add1'
     *  Sum: '<S395>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S361>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S361>/Switch' */

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

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S175>/Constant'
   *  Constant: '<S187>/Constant'
   *  RelationalOperator: '<S175>/Compare'
   *  UnitDelay: '<S187>/Unit Delay'
   */
  if (rtb_GameState != 1) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_o;
  }

  /* Sum: '<S187>/Sum' incorporates:
   *  Constant: '<S187>/Constant4'
   *  Switch: '<S187>/Switch'
   */
  rtb_Merge1 = rtb_Minus_f + 0.02;

  /* Switch: '<S188>/Switch' incorporates:
   *  Constant: '<S180>/Constant'
   *  Constant: '<S188>/Constant'
   *  RelationalOperator: '<S180>/Compare'
   *  UnitDelay: '<S188>/Unit Delay'
   */
  if (rtb_GameState != 2) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_m;
  }

  /* MultiPortSwitch: '<S137>/Multiport Switch' incorporates:
   *  Constant: '<S137>/Constant1'
   *  Constant: '<S137>/Constant3'
   *  Constant: '<S188>/Constant4'
   *  Sum: '<S188>/Sum'
   *  Switch: '<S188>/Switch'
   */
  switch (rtb_GameState) {
   case 0:
    rtb_Switch2_g = 0.0;
    break;

   case 1:
    rtb_Switch2_g = rtb_Merge1;
    break;

   case 2:
    rtb_Switch2_g = rtb_Minus_f + 0.02;
    break;

   default:
    rtb_Switch2_g = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S137>/Multiport Switch' */

  /* If: '<S137>/If' incorporates:
   *  Constant: '<S173>/Constant'
   *  Constant: '<S174>/Constant'
   *  Constant: '<S176>/Constant'
   *  Constant: '<S177>/Constant'
   *  Constant: '<S178>/Constant'
   *  Constant: '<S179>/Constant'
   *  Inport: '<Root>/IsBlueAlliance'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S173>/Compare'
   *  RelationalOperator: '<S174>/Compare'
   *  RelationalOperator: '<S176>/Compare'
   *  RelationalOperator: '<S177>/Compare'
   *  RelationalOperator: '<S178>/Compare'
   *  RelationalOperator: '<S179>/Compare'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_n;
  if ((rtb_GameState == 1) || (rtb_Switch2_g <= Rebuilt_Match_Time_Transition))
  {
    rtAction = 0;
  } else if (rtb_Switch2_g <= Rebuilt_Match_Time_Shift_1) {
    rtAction = 1;
  } else if (rtb_Switch2_g <= Rebuilt_Match_Time_Shift_2) {
    rtAction = 2;
  } else if (rtb_Switch2_g <= Rebuilt_Match_Time_Shift_3) {
    rtAction = 3;
  } else if (rtb_Switch2_g <= Rebuilt_Match_Time_Shift_4) {
    rtAction = 4;
  } else {
    rtAction = 5;
  }

  Robot_Control_DW.If_ActiveSubsystem_n = rtAction;
  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S137>/If Action Subsystem' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
      /* InitializeConditions for If: '<S137>/If' incorporates:
       *  UnitDelay: '<S181>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S137>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    /* Merge: '<S137>/Merge' incorporates:
     *  Constant: '<S181>/Constant'
     *  SignalConversion generated from: '<S181>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S137>/Merge1' incorporates:
     *  Constant: '<S181>/Constant'
     *  SignalConversion generated from: '<S181>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S181>/Sum' incorporates:
     *  Constant: '<S181>/Constant1'
     *  UnitDelay: '<S181>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hb - 0.02;

    /* Merge: '<S137>/Merge2' incorporates:
     *  SignalConversion: '<S181>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S181>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S137>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S182>/Action Port'
       */
      /* SystemReset for If: '<S137>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem1);

      /* End of SystemReset for SubSystem: '<S137>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem1' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S137>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S183>/Action Port'
       */
      /* InitializeConditions for If: '<S137>/If' incorporates:
       *  UnitDelay: '<S183>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S137>/If Action Subsystem2' */
    }

    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S183>/Action Port'
     */
    /* Sum: '<S183>/Sum' incorporates:
     *  Constant: '<S183>/Constant1'
     *  UnitDelay: '<S183>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hz - 0.02;

    /* RelationalOperator: '<S190>/Compare' incorporates:
     *  Constant: '<S190>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S137>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S183>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S137>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S183>/Logical Operator1'
     *  Logic: '<S183>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S183>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S183>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S137>/Merge2' incorporates:
       *  Constant: '<S183>/Constant2'
       *  Sum: '<S183>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S137>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;
    }

    /* End of Switch: '<S183>/Switch' */

    /* Update for UnitDelay: '<S183>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hz = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem2' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S137>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S184>/Action Port'
       */
      /* SystemReset for If: '<S137>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem3);

      /* End of SystemReset for SubSystem: '<S137>/If Action Subsystem3' */
    }

    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S184>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem3' */
    break;

   case 4:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S137>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S185>/Action Port'
       */
      /* InitializeConditions for If: '<S137>/If' incorporates:
       *  UnitDelay: '<S185>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S137>/If Action Subsystem4' */
    }

    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    /* Sum: '<S185>/Sum' incorporates:
     *  Constant: '<S185>/Constant1'
     *  UnitDelay: '<S185>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_di - 0.02;

    /* RelationalOperator: '<S192>/Compare' incorporates:
     *  Constant: '<S192>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S137>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S185>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S137>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S185>/Logical Operator1'
     *  Logic: '<S185>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S185>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S185>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S137>/Merge2' incorporates:
       *  Constant: '<S185>/Constant2'
       *  Sum: '<S185>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S137>/Merge2' incorporates:
       *  Constant: '<S185>/Constant3'
       *  Sum: '<S185>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S185>/Switch' */

    /* Update for UnitDelay: '<S185>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem4' */
    break;

   default:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S137>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S186>/Action Port'
       */
      /* InitializeConditions for If: '<S137>/If' incorporates:
       *  UnitDelay: '<S186>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

      /* End of InitializeConditions for SubSystem: '<S137>/If Action Subsystem5' */
    }

    /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S186>/Action Port'
     */
    /* Merge: '<S137>/Merge' incorporates:
     *  Constant: '<S186>/Constant'
     *  SignalConversion generated from: '<S186>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S137>/Merge1' incorporates:
     *  Constant: '<S186>/Constant'
     *  SignalConversion generated from: '<S186>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S186>/Sum' incorporates:
     *  Constant: '<S186>/Constant1'
     *  UnitDelay: '<S186>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_du - 0.02;

    /* Merge: '<S137>/Merge2' incorporates:
     *  SignalConversion: '<S186>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S186>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_du = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S137>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S137>/If' */

  /* If: '<S194>/If' incorporates:
   *  If: '<S195>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S194>/Blue' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    /* Merge: '<S194>/Merge' incorporates:
     *  Constant: '<S196>/BlueAllianceZoneX'
     *  Logic: '<S196>/AND'
     *  RelationalOperator: '<S196>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S194>/Blue' */

    /* Outputs for IfAction SubSystem: '<S195>/Blue' incorporates:
     *  ActionPort: '<S198>/Action Port'
     */
    /* Merge: '<S195>/Merge' incorporates:
     *  Constant: '<S198>/BlueAllianceZoneX'
     *  RelationalOperator: '<S198>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S195>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S194>/Red' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    /* Merge: '<S194>/Merge' incorporates:
     *  Constant: '<S197>/RedAllianceZoneX'
     *  Logic: '<S197>/AND'
     *  RelationalOperator: '<S197>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S194>/Red' */

    /* Outputs for IfAction SubSystem: '<S195>/Red' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    /* Merge: '<S195>/Merge' incorporates:
     *  Constant: '<S199>/RedAllianceZoneX'
     *  RelationalOperator: '<S199>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S195>/Red' */
  }

  /* End of If: '<S194>/If' */

  /* RelationalOperator: '<S141>/GreaterThan' incorporates:
   *  Constant: '<S141>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S141>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S141>/Relational Operator' incorporates:
   *  Abs: '<S141>/Abs'
   *  Constant: '<S193>/Constant3'
   *  Constant: '<S193>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S193>/Math Function'
   *  Sum: '<S141>/Subtract'
   *  Sum: '<S193>/Add1'
   *  Sum: '<S193>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S140>/Max' incorporates:
   *  Abs: '<S140>/Abs1'
   *  Abs: '<S140>/Abs2'
   *  Abs: '<S140>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S141>/Relational Operator1' incorporates:
   *  Abs: '<S141>/Abs1'
   *  Constant: '<S141>/Constant2'
   *  Sum: '<S141>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S141>/Relational Operator4' incorporates:
   *  Abs: '<S141>/Abs4'
   *  Constant: '<S141>/Constant1'
   *  Sum: '<S141>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S141>/AND' incorporates:
   *  Logic: '<S141>/OR'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  rtb_Compare_pb = ((((Robot_Control_B.RB_Logic_Gyro_Angle) ||
                      (Robot_Control_DW.UnitDelay_5_DSTATE)) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S141>/AND2' incorporates:
   *  Logic: '<S141>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_pb);

  /* RelationalOperator: '<S138>/Compare' incorporates:
   *  Constant: '<S138>/Constant'
   *  Inport: '<Root>/Gamepad_RT'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_RT != 0.0);

  /* SignalConversion: '<S141>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S141>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Compare_pb);

  /* Chart: '<S12>/Shooter_Transfer_Feeder Chart' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Logic: '<S141>/AND4'
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
    if ((rtb_Button_Spinup_Enable || rtb_Button_Shoot_Enable) ||
        rtb_LogicalOperator1) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.RB_Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
      Robot_Control_B.RB_Transfer_Init = 1.0;
    }
  } else {
    /* case IN_Shooting: */
    Robot_Control_B.RB_Shooter_Active = true;
    rtb_Compare_ky = !rtb_Button_Shoot_Enable;
    rtb_LogicalOperator5 = !rtb_LogicalOperator1;
    if (((!rtb_Button_Spinup_Enable) && rtb_Compare_ky) && rtb_LogicalOperator5)
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
        if (((rtb_Compare_ky && rtb_LogicalOperator5) ||
             ((Robot_Control_DW.Feeder_Loops_Shooting * 0.02) >
              Feeder_Max_Pulsetime)) || ((!Robot_Control_B.RB_Ready_to_Score) &&
             (!Robot_Control_B.RB_Ready_to_Pass))) {
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
        if ((rtb_Button_Shoot_Enable && ((Robot_Control_B.RB_Ready_to_Score) ||
              (Robot_Control_B.RB_Ready_to_Pass))) || (rtb_LogicalOperator1 &&
             ((Robot_Control_B.RB_Logic_Shooter_Speed) &&
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
        } else if (((rtb_Compare_ky && rtb_LogicalOperator5) ||
                    ((Robot_Control_DW.Feeder_Loops_Shooting * 0.02) >
                     Feeder_Max_Pulsetime)) ||
                   ((!Robot_Control_B.RB_Ready_to_Score) &&
                    (!Robot_Control_B.RB_Ready_to_Pass))) {
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

  /* RelationalOperator: '<S139>/Compare' incorporates:
   *  Constant: '<S139>/Constant'
   *  Inport: '<Root>/Gamepad_B2_B'
   */
  rtb_Button_Shoot_Enable = (Robot_Control_U.Gamepad_B2_B != 0.0);

  /* Logic: '<S12>/AND' incorporates:
   *  Logic: '<S12>/NOT'
   */
  rtb_Button_Spinup_Enable = ((Robot_Control_B.RB_Shooter_Active) &&
    (!rtb_Button_Shoot_Enable));

  /* If: '<S136>/If' incorporates:
   *  Constant: '<S147>/Constant'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Outputs for IfAction SubSystem: '<S136>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S145>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S147>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S148>/While Iterator'
     */
    /* SignalConversion generated from: '<S149>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S154>/Constant1'
     *  Constant: '<S154>/Constant10'
     *  Constant: '<S154>/Constant2'
     *  Constant: '<S154>/Constant5'
     *  Constant: '<S154>/Constant6'
     *  Constant: '<S154>/Constant7'
     *  Constant: '<S154>/Constant8'
     *  Constant: '<S154>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S147>/Iterate_Shot_Target' */

    /* SignalConversion generated from: '<S150>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S150>/Constant1'
     *  Constant: '<S150>/Constant10'
     *  Constant: '<S150>/Constant2'
     *  Constant: '<S150>/Constant5'
     *  Constant: '<S150>/Constant6'
     *  Constant: '<S150>/Constant7'
     *  Constant: '<S150>/Constant8'
     *  Constant: '<S150>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_o3[0] = Rebuilt_Shoot_Hood_Pos_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Rebuilt_Shoot_Hood_Pos_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Rebuilt_Shoot_Hood_Pos_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Rebuilt_Shoot_Hood_Pos_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Rebuilt_Shoot_Hood_Pos_4;
    rtb_TmpSignalConversionAtLoo_o3[5] = Rebuilt_Shoot_Hood_Pos_5;
    rtb_TmpSignalConversionAtLoo_o3[6] = Rebuilt_Shoot_Hood_Pos_6;
    rtb_TmpSignalConversionAtLoo_o3[7] = Rebuilt_Shoot_Hood_Pos_7;

    /* SignalConversion generated from: '<S149>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S149>/Constant1'
     *  Constant: '<S149>/Constant10'
     *  Constant: '<S149>/Constant2'
     *  Constant: '<S149>/Constant5'
     *  Constant: '<S149>/Constant6'
     *  Constant: '<S149>/Constant7'
     *  Constant: '<S149>/Constant8'
     *  Constant: '<S149>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ov[0] = Rebuilt_Shoot_Gyro_Err_0;
    rtb_TmpSignalConversionAtLoo_ov[1] = Rebuilt_Shoot_Gyro_Err_1;
    rtb_TmpSignalConversionAtLoo_ov[2] = Rebuilt_Shoot_Gyro_Err_2;
    rtb_TmpSignalConversionAtLoo_ov[3] = Rebuilt_Shoot_Gyro_Err_3;
    rtb_TmpSignalConversionAtLoo_ov[4] = Rebuilt_Shoot_Gyro_Err_4;
    rtb_TmpSignalConversionAtLoo_ov[5] = Rebuilt_Shoot_Gyro_Err_5;
    rtb_TmpSignalConversionAtLoo_ov[6] = Rebuilt_Shoot_Gyro_Err_6;
    rtb_TmpSignalConversionAtLoo_ov[7] = Rebuilt_Shoot_Gyro_Err_7;

    /* SignalConversion generated from: '<S151>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S163>/Constant1'
     *  Constant: '<S163>/Constant10'
     *  Constant: '<S163>/Constant2'
     *  Constant: '<S163>/Constant5'
     *  Constant: '<S163>/Constant6'
     *  Constant: '<S163>/Constant7'
     *  Constant: '<S163>/Constant8'
     *  Constant: '<S163>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_lg[0] = Rebuilt_Shoot_Shooter_Spd_0;
    rtb_TmpSignalConversionAtLoo_lg[1] = Rebuilt_Shoot_Shooter_Spd_1;
    rtb_TmpSignalConversionAtLoo_lg[2] = Rebuilt_Shoot_Shooter_Spd_2;
    rtb_TmpSignalConversionAtLoo_lg[3] = Rebuilt_Shoot_Shooter_Spd_3;
    rtb_TmpSignalConversionAtLoo_lg[4] = Rebuilt_Shoot_Shooter_Spd_4;
    rtb_TmpSignalConversionAtLoo_lg[5] = Rebuilt_Shoot_Shooter_Spd_5;
    rtb_TmpSignalConversionAtLoo_lg[6] = Rebuilt_Shoot_Shooter_Spd_6;
    rtb_TmpSignalConversionAtLoo_lg[7] = Rebuilt_Shoot_Shooter_Spd_7;

    /* SignalConversion generated from: '<S151>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S162>/Constant1'
     *  Constant: '<S162>/Constant10'
     *  Constant: '<S162>/Constant2'
     *  Constant: '<S162>/Constant5'
     *  Constant: '<S162>/Constant6'
     *  Constant: '<S162>/Constant7'
     *  Constant: '<S162>/Constant8'
     *  Constant: '<S162>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ix[0] = Rebuilt_Shoot_Shooter_Spd_I_0;
    rtb_TmpSignalConversionAtLoo_ix[1] = Rebuilt_Shoot_Shooter_Spd_I_1;
    rtb_TmpSignalConversionAtLoo_ix[2] = Rebuilt_Shoot_Shooter_Spd_I_2;
    rtb_TmpSignalConversionAtLoo_ix[3] = Rebuilt_Shoot_Shooter_Spd_I_3;
    rtb_TmpSignalConversionAtLoo_ix[4] = Rebuilt_Shoot_Shooter_Spd_I_4;
    rtb_TmpSignalConversionAtLoo_ix[5] = Rebuilt_Shoot_Shooter_Spd_I_5;
    rtb_TmpSignalConversionAtLoo_ix[6] = Rebuilt_Shoot_Shooter_Spd_I_6;
    rtb_TmpSignalConversionAtLoo_ix[7] = Rebuilt_Shoot_Shooter_Spd_I_7;

    /* Switch: '<S153>/Switch4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S153>/Logical Operator'
     *  Switch: '<S153>/Switch5'
     *  Switch: '<S153>/Switch6'
     */
    if ((Robot_Control_B.Is_Outside_Alliance_Zone) || rtb_LogicalOperator1) {
      /* Switch: '<S153>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S153>/Switch4' incorporates:
         *  Constant: '<S153>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S153>/Switch4' incorporates:
         *  Constant: '<S153>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S153>/Switch2' */

      /* Switch: '<S153>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S153>/Switch6' incorporates:
         *  Constant: '<S153>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S153>/Switch6' incorporates:
         *  Constant: '<S153>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S153>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S153>/Switch5' incorporates:
         *  Constant: '<S153>/Constant8'
         *  Switch: '<S153>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S153>/Switch4' incorporates:
         *  Constant: '<S153>/Constant9'
         *  Switch: '<S153>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S153>/Switch6' incorporates:
       *  Constant: '<S153>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* End of Switch: '<S153>/Switch4' */

    /* Outputs for Iterator SubSystem: '<S147>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S148>/While Iterator'
     */
    Iteration_Number = 1U;

    /* InitializeConditions for Memory: '<S148>/Memory1' */
    rtb_Switch1_n = 0.0;

    /* InitializeConditions for Memory: '<S148>/Memory2' */
    rtb_Switch2_dh = 0.0;

    /* InitializeConditions for Memory: '<S148>/Memory3' */
    rtb_Init_o = 0.0;

    /* InitializeConditions for Memory: '<S148>/Memory' */
    rtb_LogicalOperator5 = true;
    rtb_LogicalOperator1 = true;

    /* SignalConversion generated from: '<S156>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S147>/Constant'
     *  Constant: '<S156>/Constant'
     *  Constant: '<S156>/Constant1'
     *  Constant: '<S156>/Constant11'
     *  Constant: '<S156>/Constant2'
     *  Constant: '<S156>/Constant3'
     *  Constant: '<S156>/Constant4'
     *  Constant: '<S156>/Constant5'
     *  Constant: '<S156>/Constant6'
     */
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;

    /* SignalConversion generated from: '<S156>/Lookup Table Dynamic' */
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_LogicalOperator1 && (Iteration_Number <= 10)) {
      /* Switch: '<S157>/Switch' incorporates:
       *  Memory: '<S148>/Memory1'
       *  Memory: '<S148>/Memory2'
       *  Switch: '<S157>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Switch2_g = rtb_Switch1_n;
        rtb_Init = rtb_Switch2_dh;
      } else {
        rtb_Switch2_g = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Init = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S157>/Switch' */

      /* Math: '<S155>/Hypot' incorporates:
       *  Sum: '<S155>/Subtract'
       *  Sum: '<S155>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Switch2_g -
        Robot_Control_B.KF_Position_X, rtb_Init - Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S156>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S156>/Lookup Table Dynamic'
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

      /* Sum: '<S158>/Subtract' incorporates:
       *  Memory: '<S148>/Memory3'
       *  Sum: '<S158>/Subtract1'
       */
      rtb_Switch2_dh = rtb_TOF - rtb_Init_o;

      /* Sum: '<S158>/Add' incorporates:
       *  Gain: '<S158>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S158>/Product'
       *  Sum: '<S158>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Switch2_dh *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Switch2_g;

      /* Sum: '<S158>/Add1' incorporates:
       *  Gain: '<S158>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S158>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Switch2_dh *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Init;

      /* Memory: '<S148>/Memory' */
      rtb_LogicalOperator1 = rtb_LogicalOperator5;

      /* Update for Memory: '<S148>/Memory1' */
      rtb_Switch1_n = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S148>/Memory2' */
      rtb_Switch2_dh = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S148>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S148>/Memory' incorporates:
       *  Constant: '<S160>/Constant'
       *  Math: '<S159>/Hypot'
       *  RelationalOperator: '<S160>/Compare'
       *  Sum: '<S159>/Subtract'
       *  Sum: '<S159>/Subtract1'
       */
      rtb_LogicalOperator5 = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X
        - rtb_Switch2_g, Robot_Control_B.RB_Desired_Target_Y - rtb_Init) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S147>/Iterate_Shot_Target' */

    /* Merge: '<S136>/Merge2' incorporates:
     *  S-Function (sfix_look1_dyn): '<S150>/Lookup Table Dynamic'
     */
    /* Dynamic Look-Up Table Block: '<S150>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S149>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S149>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_Switch_cn), &rtb_TmpSignalConversionAtLoo_ov[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);

    /* S-Function (sfix_look1_dyn): '<S151>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S151>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S151>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S151>/Lookup Table Dynamic1'
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

    /* Switch: '<S151>/Switch' incorporates:
     *  Constant: '<S151>/Constant'
     *  Constant: '<S151>/Constant1'
     *  Sum: '<S151>/Add'
     *  UnitDelay: '<S151>/Unit Delay'
     */
    if (Robot_Control_B.RB_Transfer_Init != 0.0) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    /* End of Switch: '<S151>/Switch' */

    /* Switch: '<S151>/Switch1' incorporates:
     *  Constant: '<S151>/Constant2'
     *  RelationalOperator: '<S151>/GreaterThan'
     */
    if (rtb_Switch1_n < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S136>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S136>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    /* End of Switch: '<S151>/Switch1' */

    /* Merge: '<S136>/Merge3' incorporates:
     *  Gain: '<S161>/Gain1'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_Switch_cn;

    /* Trigonometry: '<S164>/Atan1' incorporates:
     *  Constant: '<S164>/Constant'
     *  Constant: '<S164>/Constant1'
     *  Sum: '<S164>/Subtract3'
     *  Sum: '<S164>/Subtract4'
     */
    rtb_Switch_cn = rt_atan2d_snf(1.0 - Robot_Control_B.KF_Position_Y, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S164>/Mod' incorporates:
     *  Constant: '<S164>/Constant4'
     */
    rtb_Switch2_dh = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Sum: '<S164>/Subtract2' incorporates:
     *  Constant: '<S152>/Constant10'
     *  Sum: '<S164>/Subtract8'
     */
    rtb_Init = Field_Length - Robot_Control_B.KF_Position_X;

    /* Trigonometry: '<S164>/Atan2' incorporates:
     *  Constant: '<S164>/Constant2'
     *  Sum: '<S164>/Subtract1'
     *  Sum: '<S164>/Subtract2'
     */
    rtb_Switch_cn = rt_atan2d_snf(1.0 - Robot_Control_B.KF_Position_Y, rtb_Init);

    /* Math: '<S164>/Mod1' incorporates:
     *  Constant: '<S164>/Constant5'
     */
    rtb_Init_o = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Sum: '<S164>/Subtract5' incorporates:
     *  Constant: '<S152>/Constant11'
     *  Sum: '<S164>/Subtract7'
     */
    rtb_Switch2_i = Field_Width_Pass - Robot_Control_B.KF_Position_Y;

    /* Trigonometry: '<S164>/Atan3' incorporates:
     *  Constant: '<S164>/Constant3'
     *  Sum: '<S164>/Subtract5'
     *  Sum: '<S164>/Subtract6'
     */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch2_i, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S164>/Mod2' incorporates:
     *  Constant: '<S164>/Constant6'
     */
    rtb_Switch2_g = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Trigonometry: '<S164>/Atan4' */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch2_i, rtb_Init);

    /* Math: '<S164>/Mod3' incorporates:
     *  Constant: '<S164>/Constant7'
     */
    rtb_Init = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Merge: '<S136>/Merge' incorporates:
     *  Constant: '<S168>/Constant'
     *  Constant: '<S168>/Shooter Assembly Offset in Robot'
     *  Constant: '<S168>/Shooter Assembly Offset in Robot1'
     *  Gain: '<S172>/Gain1'
     *  MinMax: '<S168>/Max'
     *  Product: '<S168>/Divide'
     *  Sum: '<S168>/Add'
     *  Sum: '<S168>/Subtract1'
     *  Sum: '<S168>/Subtract2'
     *  Trigonometry: '<S168>/Atan2'
     *  Trigonometry: '<S168>/Tanh1'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = (rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      atan(-0.074675999999999992 / fmax(Robot_Control_B.RB_Desired_Shot_Distance,
      0.001))) + (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);

    /* Switch: '<S167>/Switch1' incorporates:
     *  Constant: '<S152>/Constant3'
     *  Constant: '<S152>/Constant7'
     *  Inport: '<Root>/IsBlueAlliance'
     */
    if (Robot_Control_U.IsBlueAlliance > 0.0) {
      rtb_Switch_cn = Blue_Hub_LeftY;
    } else {
      rtb_Switch_cn = Red_Hub_LeftY;
    }

    /* End of Switch: '<S167>/Switch1' */

    /* Sum: '<S165>/Subtract3' */
    rtb_Switch2_i = rtb_Switch_cn - Robot_Control_B.KF_Position_Y;

    /* Switch: '<S167>/Switch' incorporates:
     *  Constant: '<S152>/Constant2'
     *  Constant: '<S152>/Constant4'
     *  Constant: '<S152>/Constant5'
     *  Constant: '<S152>/Constant6'
     *  Constant: '<S152>/Constant8'
     *  Constant: '<S152>/Constant9'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Switch: '<S167>/Switch2'
     *  Switch: '<S167>/Switch3'
     */
    if (Robot_Control_U.IsBlueAlliance > 0.0) {
      rtb_Switch_cn = Blue_Hub_LeftX;
      rtb_Minus_k_idx_1 = Blue_Hub_RightX;
      rtb_Add_i = Blue_Hub_RightY;
    } else {
      rtb_Switch_cn = Red_Hub_LeftX;
      rtb_Minus_k_idx_1 = Red_Hub_RightX;
      rtb_Add_i = Red_Hub_RightY;
    }

    /* End of Switch: '<S167>/Switch' */

    /* Math: '<S165>/Mod1' incorporates:
     *  Constant: '<S165>/Constant'
     *  Sum: '<S165>/Subtract4'
     *  Trigonometry: '<S165>/Atan1'
     */
    rtb_Switch_cn = rt_modd_snf(rt_atan2d_snf(rtb_Switch2_i, rtb_Switch_cn -
      Robot_Control_B.KF_Position_X), 6.2831853071795862);

    /* Math: '<S165>/Mod2' incorporates:
     *  Constant: '<S165>/Constant1'
     *  Sum: '<S165>/Subtract1'
     *  Sum: '<S165>/Subtract2'
     *  Switch: '<S167>/Switch2'
     *  Switch: '<S167>/Switch3'
     *  Trigonometry: '<S165>/Atan3'
     */
    rtb_Switch2_i = rt_modd_snf(rt_atan2d_snf(rtb_Minus_k_idx_1 -
      Robot_Control_B.KF_Position_Y, rtb_Add_i - Robot_Control_B.KF_Position_X),
      6.2831853071795862);

    /* Switch: '<S165>/Switch' incorporates:
     *  Abs: '<S165>/Abs'
     *  Abs: '<S165>/Abs1'
     *  RelationalOperator: '<S165>/GreaterThan'
     */
    if (!(rtb_Switch_cn < rtb_Switch2_i)) {
      /* Abs: '<S152>/Abs1' */
      rtb_Switch_cn = rtb_Switch2_i;
    }

    /* End of Switch: '<S165>/Switch' */

    /* Math: '<S152>/Math Function' incorporates:
     *  Constant: '<S152>/Constant1'
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Switch2_i = rt_modd_snf(Robot_Control_U.Gyro_Angle_Field_rad,
      6.2831853071795862);

    /* If: '<S166>/If' incorporates:
     *  Switch: '<S171>/Switch'
     */
    if (Robot_Control_B.RB_Desired_Target_Y > 4.0345) {
      /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem' incorporates:
       *  ActionPort: '<S170>/Action Port'
       */
      /* Switch: '<S170>/Switch' */
      if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
        /* Abs: '<S152>/Abs' */
        rtb_Switch2_dh = rtb_Init;
      } else {
        /* Abs: '<S152>/Abs' */
        rtb_Switch2_dh = rtb_Switch2_g;
      }

      /* End of Switch: '<S170>/Switch' */
      /* End of Outputs for SubSystem: '<S166>/If Action Subsystem' */

      /* Outputs for IfAction SubSystem: '<S166>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S171>/Action Port'
       */
    } else if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
      /* Switch: '<S171>/Switch' incorporates:
       *  Abs: '<S152>/Abs'
       */
      rtb_Switch2_dh = rtb_Init_o;

      /* End of Outputs for SubSystem: '<S166>/If Action Subsystem1' */
    }

    /* End of If: '<S166>/If' */

    /* Switch: '<S169>/Switch' incorporates:
     *  Logic: '<S169>/AND'
     *  Logic: '<S169>/AND1'
     *  RelationalOperator: '<S169>/GreaterThan'
     *  RelationalOperator: '<S169>/GreaterThan1'
     *  RelationalOperator: '<S169>/GreaterThan2'
     *  RelationalOperator: '<S169>/GreaterThan3'
     *  RelationalOperator: '<S169>/GreaterThan4'
     */
    if (rtb_Switch2_dh < rtb_Switch_cn) {
      rtb_Compare_ky = ((rtb_Switch2_i > rtb_Switch2_dh) && (rtb_Switch2_i <
        rtb_Switch_cn));
    } else {
      rtb_Compare_ky = ((rtb_Switch2_i > rtb_Switch_cn) && (rtb_Switch2_i <
        rtb_Switch2_dh));
    }

    /* Merge: '<S136>/Merge4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S152>/AND'
     *  Logic: '<S169>/Logical Operator'
     *  Switch: '<S169>/Switch'
     */
    Robot_Control_B.Can_Pass = (rtb_Button_Shoot_Enable &&
      ((Robot_Control_U.IsBlueAlliance != 0.0) == ((int32_T)rtb_Compare_ky)));

    /* Update for UnitDelay: '<S151>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S136>/Desired Shooting Parameters Math' */
  } else {
    /* Outputs for IfAction SubSystem: '<S136>/Shooter Not Active' incorporates:
     *  ActionPort: '<S146>/Action Port'
     */
    /* Merge: '<S136>/Merge' incorporates:
     *  Constant: '<S146>/Constant2'
     *  SignalConversion generated from: '<S146>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;

    /* Merge: '<S136>/Merge1' incorporates:
     *  Constant: '<S146>/Constant'
     *  SignalConversion generated from: '<S146>/Desired_Shooter_Speed'
     */
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;

    /* Merge: '<S136>/Merge2' incorporates:
     *  Constant: '<S146>/Constant3'
     *  SignalConversion generated from: '<S146>/Desired_Hood_Pos'
     */
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;

    /* Merge: '<S136>/Merge3' incorporates:
     *  Constant: '<S146>/Constant1'
     *  SignalConversion generated from: '<S146>/Allowed_Shoot_Gyro_Error_rad'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* Merge: '<S136>/Merge4' incorporates:
     *  Constant: '<S146>/Constant4'
     *  SignalConversion generated from: '<S146>/Can_Pass'
     */
    Robot_Control_B.Can_Pass = true;

    /* End of Outputs for SubSystem: '<S136>/Shooter Not Active' */
  }

  /* End of If: '<S136>/If' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Switch: '<S3>/Switch3'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Minus_k_idx_1 = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;
    rtb_Add_i = Robot_Control_U.Gyro_Angle_Field_rad;
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.Steering_Abs_Cmd_SPF;
    rtb_Add_i = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* Sum: '<S390>/Add1' incorporates:
   *  Constant: '<S390>/Constant3'
   *  Constant: '<S390>/Constant4'
   *  Math: '<S390>/Math Function'
   *  Sum: '<S389>/Sum'
   *  Sum: '<S390>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf((rtb_Minus_k_idx_1 - rtb_Add_i) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Gain: '<S393>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle;

  /* Abs: '<S372>/Abs1' */
  rtb_Init_o = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S392>/Sum1' incorporates:
   *  Constant: '<S389>/Constant2'
   *  Product: '<S392>/Product'
   *  Sum: '<S392>/Sum'
   *  UnitDelay: '<S392>/Unit Delay1'
   */
  rtb_Switch_cn = ((rtb_Optimized_Module_Angle -
                    Robot_Control_DW.UnitDelay1_DSTATE) *
                   Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S389>/Product' incorporates:
   *  Constant: '<S389>/Constant3'
   */
  rtb_Switch1_n = rtb_Switch_cn * Steering_Heading_Control_D;

  /* Sum: '<S391>/Diff' incorporates:
   *  UnitDelay: '<S391>/UD'
   *
   * Block description for '<S391>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S391>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Switch1_n - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S389>/Saturation' */
  if (rtb_Add_mw > Steering_Heading_Control_D_UL) {
    rtb_Add_mw = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Heading_Control_D_LL) {
    rtb_Add_mw = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S389>/Add' incorporates:
   *  Gain: '<S389>/Gain1'
   *  Saturate: '<S389>/Saturation'
   */
  rtb_Init = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle) +
    rtb_Add_mw;

  /* Sum: '<S389>/Subtract' incorporates:
   *  Constant: '<S389>/Constant'
   */
  rtb_Switch2_g = Steering_Heading_Control_Total_UL - rtb_Init;

  /* Sum: '<S389>/Sum2' incorporates:
   *  Gain: '<S389>/Gain2'
   *  UnitDelay: '<S389>/Unit Delay'
   */
  rtb_Switch2_dh = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S394>/Switch2' incorporates:
   *  RelationalOperator: '<S394>/LowerRelop1'
   */
  if (!(rtb_Switch2_dh > rtb_Switch2_g)) {
    /* Sum: '<S389>/Subtract1' incorporates:
     *  Constant: '<S389>/Constant1'
     */
    rtb_Switch2_g = Steering_Heading_Control_Total_LL - rtb_Init;

    /* Switch: '<S394>/Switch' incorporates:
     *  RelationalOperator: '<S394>/UpperRelop'
     */
    if (!(rtb_Switch2_dh < rtb_Switch2_g)) {
      rtb_Switch2_g = rtb_Switch2_dh;
    }

    /* End of Switch: '<S394>/Switch' */
  }

  /* End of Switch: '<S394>/Switch2' */

  /* Saturate: '<S389>/Saturation1' */
  if (rtb_Switch2_g > Steering_Heading_Control_I_UL) {
    rtb_Switch2_dh = Steering_Heading_Control_I_UL;
  } else if (rtb_Switch2_g < Steering_Heading_Control_I_LL) {
    rtb_Switch2_dh = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch2_dh = rtb_Switch2_g;
  }

  /* End of Saturate: '<S389>/Saturation1' */

  /* Sum: '<S389>/Add1' */
  rtb_Add_mw = rtb_Init + rtb_Switch2_dh;

  /* Saturate: '<S389>/Saturation2' */
  if (rtb_Add_mw > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S389>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_mw < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S389>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S389>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_mw;
  }

  /* End of Saturate: '<S389>/Saturation2' */

  /* Abs: '<S372>/Abs' */
  rtb_Switch2_g = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S372>/Add dither' */
  if (Robot_Control_DW.is_active_c7_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c7_Robot_Control = 1U;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Switch2_g;
  } else if (Robot_Control_DW.is_c7_Robot_Control == Robot_Control_IN_Dither) {
    if ((!rtb_Button_Spinup_Enable) || (rtb_Init_o <
         Steering_Heading_Dither_Thresh_Off)) {
      Robot_Control_DW.is_Dither = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
      Robot_Control_B.abs_Cmd_Out = rtb_Switch2_g;
    } else if (Robot_Control_DW.is_Dither == Robot_Control_IN_High) {
      if (Robot_Control_DW.timer >= Steering_Heading_Dither_Period) {
        Robot_Control_DW.is_Dither = Robot_Control_IN_Off;
        Robot_Control_B.abs_Cmd_Out = 0.0;
        Robot_Control_DW.timer = 0.0;
      } else {
        Robot_Control_B.abs_Cmd_Out = rtb_Switch2_g *
          Steering_Heading_Dither_Gain;
        Robot_Control_DW.timer += 0.02;
      }

      /* case IN_Off: */
    } else if (Robot_Control_DW.timer >= Steering_Heading_Dither_Period) {
      Robot_Control_DW.is_Dither = Robot_Control_IN_High;
      Robot_Control_B.abs_Cmd_Out = rtb_Switch2_g * Steering_Heading_Dither_Gain;
      Robot_Control_DW.timer = 0.0;
    } else {
      Robot_Control_DW.timer += 0.02;
    }

    /* case IN_No_Dither: */
  } else if (rtb_Button_Spinup_Enable && (rtb_Init_o >
              Steering_Heading_Dither_Thresh_On)) {
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_Dither;
    Robot_Control_DW.is_Dither = Robot_Control_IN_High;
    Robot_Control_B.abs_Cmd_Out = rtb_Switch2_g * Steering_Heading_Dither_Gain;
    Robot_Control_DW.timer = 0.0;
  } else {
    Robot_Control_B.abs_Cmd_Out = rtb_Switch2_g;
  }

  /* End of Chart: '<S372>/Add dither' */

  /* Switch: '<S372>/Switch' incorporates:
   *  Constant: '<S372>/Constant'
   *  Constant: '<S388>/Constant'
   *  Product: '<S372>/Product'
   *  RelationalOperator: '<S388>/Compare'
   *  Signum: '<S372>/Sign'
   */
  if (rtb_Switch2_g > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S372>/Sign' */
    if (rtIsNaN(Robot_Control_B.Steering_Heading_PID)) {
      rtb_Minus_k_idx_1 = (rtNaN);
    } else if (Robot_Control_B.Steering_Heading_PID < 0.0) {
      rtb_Minus_k_idx_1 = -1.0;
    } else {
      rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Heading_PID > 0.0);
    }

    rtb_Optimized_Module_Angle = Robot_Control_B.abs_Cmd_Out * rtb_Minus_k_idx_1;
  } else {
    rtb_Optimized_Module_Angle = 0.0;
  }

  /* End of Switch: '<S372>/Switch' */

  /* Signum: '<S371>/Sign2' incorporates:
   *  UnitDelay: '<S371>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S371>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Add_i = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (rtb_Optimized_Module_Angle > 0.0);
  }

  /* Product: '<S371>/Product1' incorporates:
   *  Signum: '<S371>/Sign1'
   *  Signum: '<S371>/Sign2'
   */
  rtb_Minus_k_idx_1 *= rtb_Add_i;
  if (rtIsNaN(rtb_Minus_k_idx_1)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_k_idx_1, 256.0);
  }

  /* Switch: '<S371>/Switch' incorporates:
   *  Constant: '<S371>/Constant'
   *  Constant: '<S380>/Constant'
   *  Constant: '<S381>/Constant'
   *  Logic: '<S371>/or'
   *  Product: '<S371>/Product1'
   *  RelationalOperator: '<S380>/Compare'
   *  RelationalOperator: '<S381>/Compare'
   *  UnitDelay: '<S371>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Saturation_h = rtb_Optimized_Module_Angle;
  } else {
    rtb_Saturation_h = 0.0;
  }

  /* End of Switch: '<S371>/Switch' */

  /* Switch: '<S386>/Init' incorporates:
   *  UnitDelay: '<S386>/FixPt Unit Delay1'
   *  UnitDelay: '<S386>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Saturation_h;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S386>/Init' */

  /* RelationalOperator: '<S382>/Compare' incorporates:
   *  Constant: '<S382>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Saturation_h == 0.0);

  /* RelationalOperator: '<S383>/Compare' incorporates:
   *  Constant: '<S383>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Saturation_h > 0.0);

  /* Abs: '<S371>/Abs' incorporates:
   *  Sum: '<S371>/Subtract'
   *  UnitDelay: '<S371>/Unit Delay'
   */
  rtb_Switch2_g = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                       rtb_Optimized_Module_Angle);

  /* Switch: '<S371>/Switch5' incorporates:
   *  Constant: '<S371>/Constant1'
   *  Switch: '<S371>/Switch1'
   *  UnaryMinus: '<S371>/Unary Minus'
   */
  if (rtb_Button_Shoot_Enable) {
    /* SignalConversion generated from: '<S371>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S371>/Constant4'
     *  Constant: '<S371>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S371>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S371>/Constant2'
     *  Constant: '<S371>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S371>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S371>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Reshapey[0],
                         rtb_Switch2_g, &rtb_Minus_n[0], 1U);
    rtb_Switch2_g = rtb_LookupTableDynamic;
    rtb_Minus_k_idx_1 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S371>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S371>/Constant10'
     *  Constant: '<S371>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S371>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S371>/Constant7'
     *  Constant: '<S371>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S371>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S371>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Reshapey[0],
                         rtb_Switch2_g, &rtb_Minus_n[0], 1U);
    rtb_Switch2_g = rtb_LookupTableDynamic1;

    /* Switch: '<S371>/Switch3' incorporates:
     *  Constant: '<S371>/Constant1'
     *  Constant: '<S371>/Constant3'
     *  UnaryMinus: '<S371>/Unary Minus'
     */
    if (rtb_LogicalOperator1) {
      rtb_Minus_k_idx_1 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Minus_k_idx_1 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S371>/Switch3' */
  }

  /* End of Switch: '<S371>/Switch5' */

  /* Product: '<S371>/Product' incorporates:
   *  Switch: '<S371>/Switch1'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_1 * rtb_Switch2_g;

  /* Sum: '<S384>/Sum1' */
  rtb_Init = rtb_Saturation_h - rtb_Init_o;

  /* Switch: '<S385>/Switch2' incorporates:
   *  RelationalOperator: '<S385>/LowerRelop1'
   */
  if (!(rtb_Init > rtb_MatrixConcatenate_b_idx_0)) {
    /* Switch: '<S371>/Switch2' incorporates:
     *  Constant: '<S371>/Constant1'
     *  Constant: '<S371>/Constant3'
     *  Switch: '<S371>/Switch4'
     *  UnaryMinus: '<S371>/Unary Minus1'
     */
    if (rtb_Button_Shoot_Enable) {
      rtb_Minus_k_idx_1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S371>/Switch4' incorporates:
       *  Constant: '<S371>/Constant1'
       */
      rtb_Minus_k_idx_1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Minus_k_idx_1 = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S371>/Product2' incorporates:
     *  Switch: '<S371>/Switch2'
     */
    rtb_Switch2_i = rtb_Minus_k_idx_1 * rtb_Switch2_g;

    /* Switch: '<S385>/Switch' incorporates:
     *  RelationalOperator: '<S385>/UpperRelop'
     */
    if (rtb_Init < rtb_Switch2_i) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_i;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Init;
    }

    /* End of Switch: '<S385>/Switch' */
  }

  /* End of Switch: '<S385>/Switch2' */

  /* Sum: '<S384>/Sum' */
  rtb_Init_o += rtb_MatrixConcatenate_b_idx_0;

  /* Signum: '<S370>/Sign2' incorporates:
   *  UnitDelay: '<S370>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S370>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S370>/Product1' incorporates:
   *  Signum: '<S370>/Sign1'
   *  Signum: '<S370>/Sign2'
   */
  rtb_Minus_k_idx_1 *= rtb_Add_i;
  if (rtIsNaN(rtb_Minus_k_idx_1)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_k_idx_1, 256.0);
  }

  /* Switch: '<S370>/Switch' incorporates:
   *  Constant: '<S370>/Constant'
   *  Constant: '<S373>/Constant'
   *  Constant: '<S374>/Constant'
   *  Logic: '<S370>/or'
   *  Product: '<S370>/Product1'
   *  RelationalOperator: '<S373>/Compare'
   *  RelationalOperator: '<S374>/Compare'
   *  UnitDelay: '<S370>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Saturation_h = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Saturation_h = 0.0;
  }

  /* End of Switch: '<S370>/Switch' */

  /* Switch: '<S379>/Init' incorporates:
   *  UnitDelay: '<S379>/FixPt Unit Delay1'
   *  UnitDelay: '<S379>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle = rtb_Saturation_h;
  } else {
    rtb_Optimized_Module_Angle = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S379>/Init' */

  /* RelationalOperator: '<S375>/Compare' incorporates:
   *  Constant: '<S375>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Saturation_h == 0.0);

  /* RelationalOperator: '<S376>/Compare' incorporates:
   *  Constant: '<S376>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Saturation_h > 0.0);

  /* Abs: '<S370>/Abs' incorporates:
   *  Sum: '<S370>/Subtract'
   *  UnitDelay: '<S370>/Unit Delay'
   */
  rtb_Init = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                  Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S370>/Switch1' incorporates:
   *  Constant: '<S370>/Constant1'
   *  Switch: '<S370>/Switch3'
   *  Switch: '<S370>/Switch5'
   *  UnaryMinus: '<S370>/Unary Minus'
   */
  if (rtb_Button_Shoot_Enable) {
    rtb_Switch2_g = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S370>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S370>/Constant1'
     *  Constant: '<S370>/Constant4'
     *  Constant: '<S370>/Constant6'
     *  UnaryMinus: '<S370>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S370>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S370>/Constant2'
     *  Constant: '<S370>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S370>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S370>/Lookup Table Dynamic'
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
    if (rtb_LogicalOperator1) {
      /* Switch: '<S370>/Switch3' incorporates:
       *  Constant: '<S370>/Constant3'
       */
      rtb_Switch2_g = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Switch2_g = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S370>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S370>/Constant1'
     *  Constant: '<S370>/Constant10'
     *  Constant: '<S370>/Constant8'
     *  UnaryMinus: '<S370>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S370>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S370>/Constant7'
     *  Constant: '<S370>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S370>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S370>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S370>/Switch1' */

  /* Product: '<S370>/Product' */
  rtb_Switch2_g *= rtb_Init;

  /* Sum: '<S377>/Sum1' */
  rtb_Switch2_i = rtb_Saturation_h - rtb_Optimized_Module_Angle;

  /* Switch: '<S378>/Switch2' incorporates:
   *  RelationalOperator: '<S378>/LowerRelop1'
   */
  if (!(rtb_Switch2_i > rtb_Switch2_g)) {
    /* Switch: '<S370>/Switch2' incorporates:
     *  Constant: '<S370>/Constant1'
     *  Switch: '<S370>/Switch4'
     */
    if (rtb_Button_Shoot_Enable) {
      rtb_Switch2_g = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S370>/Switch4' incorporates:
       *  Constant: '<S370>/Constant1'
       */
      rtb_Switch2_g = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S370>/Switch4' incorporates:
       *  Constant: '<S370>/Constant3'
       *  UnaryMinus: '<S370>/Unary Minus1'
       */
      rtb_Switch2_g = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S370>/Switch2' */

    /* Product: '<S370>/Product2' */
    rtb_Switch2_g *= rtb_Init;

    /* Switch: '<S378>/Switch' incorporates:
     *  RelationalOperator: '<S378>/UpperRelop'
     */
    if (!(rtb_Switch2_i < rtb_Switch2_g)) {
      rtb_Switch2_g = rtb_Switch2_i;
    }

    /* End of Switch: '<S378>/Switch' */
  }

  /* End of Switch: '<S378>/Switch2' */

  /* Sum: '<S377>/Sum' */
  rtb_Switch2_g += rtb_Optimized_Module_Angle;

  /* Switch: '<S360>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (rtb_Button_Spinup_Enable || (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S360>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S360>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch2_g;
  }

  /* End of Switch: '<S360>/Switch' */

  /* Fcn: '<S403>/r->x' incorporates:
   *  Fcn: '<S408>/r->x'
   *  Fcn: '<S413>/r->x'
   *  Fcn: '<S418>/r->x'
   */
  rtb_Switch2_i = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S397>/Add' incorporates:
   *  Fcn: '<S403>/r->x'
   *  Fcn: '<S404>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2_i;

  /* Fcn: '<S403>/theta->y' incorporates:
   *  Fcn: '<S408>/theta->y'
   *  Fcn: '<S413>/theta->y'
   *  Fcn: '<S418>/theta->y'
   */
  rtb_Init = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S397>/Add' incorporates:
   *  Fcn: '<S403>/theta->y'
   *  Fcn: '<S404>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S398>/Add' incorporates:
   *  Fcn: '<S409>/r->x'
   *  Fcn: '<S409>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2_i;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S399>/Add' incorporates:
   *  Fcn: '<S414>/r->x'
   *  Fcn: '<S414>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2_i;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S400>/Add' incorporates:
   *  Fcn: '<S419>/r->x'
   *  Fcn: '<S419>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2_i;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Init;

  /* Fcn: '<S417>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_k_idx_0,
    rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S420>/Compare' incorporates:
   *  Constant: '<S420>/Constant'
   */
  rtb_Compare_pb = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S416>/Switch1' */
  if (rtb_Compare_pb) {
    /* Switch: '<S416>/Switch1' incorporates:
     *  Constant: '<S416>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S416>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S416>/Switch1' */

  /* Fcn: '<S402>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S405>/Compare' incorporates:
   *  Constant: '<S405>/Constant'
   */
  rtb_Compare_mq = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S401>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S401>/Switch1' incorporates:
     *  Constant: '<S401>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S401>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S401>/Switch1' */

  /* Fcn: '<S407>/x->r' */
  rtb_Saturation_h = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S410>/Compare' incorporates:
   *  Constant: '<S410>/Constant'
   */
  rtb_Compare_ky = (rtb_Saturation_h == 0.0);

  /* Switch: '<S406>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S406>/Switch1' incorporates:
     *  Constant: '<S406>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S406>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Saturation_h;
  }

  /* End of Switch: '<S406>/Switch1' */

  /* Fcn: '<S412>/x->r' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S415>/Compare' incorporates:
   *  Constant: '<S415>/Constant'
   */
  rtb_Button_Shoot_Enable = (rtb_Optimized_Module_Angle == 0.0);

  /* Switch: '<S411>/Switch1' */
  if (rtb_Button_Shoot_Enable) {
    /* Switch: '<S411>/Switch1' incorporates:
     *  Constant: '<S411>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S411>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle;
  }

  /* End of Switch: '<S411>/Switch1' */

  /* Product: '<S396>/Divide' incorporates:
   *  Abs: '<S396>/Abs'
   *  Abs: '<S396>/Abs1'
   *  Abs: '<S396>/Abs2'
   *  Abs: '<S396>/Abs3'
   *  Constant: '<S396>/Constant'
   *  MinMax: '<S396>/Max'
   */
  rtb_MatrixConcatenate_b_idx_0 = 5.3690930669470935 / fmax(fmax(fmax(fmax
    (5.3690930669470935, Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S396>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S416>/Switch' */
  if (!rtb_Compare_pb) {
    /* Switch: '<S416>/Switch' incorporates:
     *  Fcn: '<S417>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S416>/Switch' */

  /* Trigonometry: '<S350>/Cos4' incorporates:
   *  Switch: '<S339>/Angle_Switch'
   *  Trigonometry: '<S349>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S350>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S348>/Unary Minus'
   */
  rtb_Minus_k_idx_0 = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S350>/Sin4' incorporates:
   *  Switch: '<S339>/Angle_Switch'
   *  Trigonometry: '<S349>/Sin4'
   */
  rtb_Subtract_kb = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S350>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S348>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S350>/Subtract1' incorporates:
   *  Product: '<S350>/Product2'
   *  Product: '<S350>/Product3'
   *  Trigonometry: '<S350>/Cos4'
   *  Trigonometry: '<S350>/Sin4'
   */
  rtb_Init = (rtb_MatrixConcatenate_idx_0 * rtb_Minus_k_idx_0) +
    (rtb_Subtract_kb * rtb_Optimized_Module_Angle);

  /* Sum: '<S350>/Subtract' incorporates:
   *  Product: '<S350>/Product'
   *  Product: '<S350>/Product1'
   *  Trigonometry: '<S350>/Cos4'
   *  Trigonometry: '<S350>/Sin4'
   */
  rtb_Switch2_i = (rtb_MatrixConcatenate_idx_0 * rtb_Optimized_Module_Angle) -
    (rtb_Subtract_kb * rtb_Minus_k_idx_0);

  /* Math: '<S350>/Hypot' */
  rtb_Hypot_pi = rt_hypotd_snf(rtb_Switch2_i, rtb_Init);

  /* Switch: '<S350>/Switch' incorporates:
   *  Constant: '<S350>/Constant'
   *  Constant: '<S350>/Constant1'
   *  Constant: '<S351>/Constant'
   *  Product: '<S350>/Divide'
   *  Product: '<S350>/Divide1'
   *  RelationalOperator: '<S351>/Compare'
   *  Switch: '<S350>/Switch1'
   */
  if (rtb_Hypot_pi > 1.0E-6) {
    rtb_Saturation_h = rtb_Init / rtb_Hypot_pi;
    rtb_Optimized_Module_Angle = rtb_Switch2_i / rtb_Hypot_pi;
  } else {
    rtb_Saturation_h = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S350>/Switch' */

  /* Switch: '<S339>/Speed_Switch' incorporates:
   *  Abs: '<S339>/Abs'
   *  Constant: '<S347>/Constant'
   *  RelationalOperator: '<S347>/Compare'
   *  Switch: '<S339>/Angle_Switch'
   *  Trigonometry: '<S349>/Atan1'
   *  Trigonometry: '<S350>/Atan1'
   *  UnaryMinus: '<S339>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Saturation_h, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Minus_k_idx_1 = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S349>/Subtract1' incorporates:
     *  Product: '<S349>/Product2'
     *  Product: '<S349>/Product3'
     *  UnaryMinus: '<S339>/Unary Minus'
     */
    rtb_Init = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Sin5_c) +
      (rtb_Subtract_kb * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S349>/Subtract' incorporates:
     *  Product: '<S349>/Product'
     *  Product: '<S349>/Product1'
     */
    rtb_Hypot_pi = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Cos5_b) -
      (rtb_Subtract_kb * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S349>/Hypot' */
    rtb_Switch2_i = rt_hypotd_snf(rtb_Hypot_pi, rtb_Init);

    /* Switch: '<S349>/Switch1' incorporates:
     *  Constant: '<S349>/Constant'
     *  Constant: '<S349>/Constant1'
     *  Constant: '<S352>/Constant'
     *  Product: '<S349>/Divide'
     *  Product: '<S349>/Divide1'
     *  RelationalOperator: '<S352>/Compare'
     *  Switch: '<S349>/Switch'
     */
    if (rtb_Switch2_i > 1.0E-6) {
      rtb_Hypot_pi /= rtb_Switch2_i;
      rtb_Init /= rtb_Switch2_i;
    } else {
      rtb_Hypot_pi = 1.0;
      rtb_Init = 0.0;
    }

    /* End of Switch: '<S349>/Switch1' */
    rtb_Minus_k_idx_0 = rt_atan2d_snf(rtb_Init, rtb_Hypot_pi);
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Minus_k_idx_0 = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S342>/Product2' incorporates:
   *  Constant: '<S342>/Constant'
   *  Switch: '<S339>/Speed_Switch'
   */
  rtb_Saturation_h = rtb_Minus_k_idx_1 * 1154.7574092481445;

  /* Signum: '<S337>/Sign' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S337>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S340>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S341>/Sum'
   */
  rtb_Integral_c3 = rtb_Minus_k_idx_0 - Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S272>/Product' incorporates:
   *  Abs: '<S337>/Abs'
   *  Abs: '<S340>/Abs'
   *  Constant: '<S343>/Constant'
   *  Constant: '<S353>/Constant3'
   *  Constant: '<S353>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S337>/OR'
   *  Lookup_n-D: '<S340>/1-D Lookup Table'
   *  Math: '<S353>/Math Function'
   *  RelationalOperator: '<S337>/Equal1'
   *  RelationalOperator: '<S343>/Compare'
   *  Signum: '<S337>/Sign'
   *  Signum: '<S337>/Sign1'
   *  Sum: '<S340>/Add'
   *  Sum: '<S353>/Add1'
   *  Sum: '<S353>/Add2'
   */
  rtb_Saturation_h = (((real_T)((rtb_Minus_k_idx_1 == rtb_Add_i) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Saturation_h) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_c3 + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData_g, 1U);

  /* Gain: '<S338>/Gain' */
  rtb_Hypot_pi = Drive_Motor_Control_FF * rtb_Saturation_h;

  /* Sum: '<S338>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Saturation_h -= Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S345>/Sum1' incorporates:
   *  Constant: '<S338>/Constant2'
   *  Product: '<S345>/Product'
   *  Sum: '<S345>/Sum'
   *  UnitDelay: '<S345>/Unit Delay1'
   */
  rtb_Init = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_j) *
              Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S338>/Product' incorporates:
   *  Constant: '<S338>/Constant3'
   */
  rtb_Switch2_i = rtb_Init * Drive_Motor_Control_D;

  /* Sum: '<S344>/Diff' incorporates:
   *  UnitDelay: '<S344>/UD'
   *
   * Block description for '<S344>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S344>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Switch2_i - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S338>/Saturation' */
  if (rtb_Add_mw > Drive_Motor_Control_D_UL) {
    rtb_Add_mw = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Drive_Motor_Control_D_LL) {
    rtb_Add_mw = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S338>/Add' incorporates:
   *  Gain: '<S338>/Gain1'
   *  Saturate: '<S338>/Saturation'
   */
  rtb_Add_mw += (Drive_Motor_Control_P * rtb_Saturation_h) + rtb_Hypot_pi;

  /* Saturate: '<S338>/Saturation2' */
  if (rtb_Add_mw > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_Add_mw;
  }

  /* End of Saturate: '<S338>/Saturation2' */

  /* Sum: '<S354>/Add1' incorporates:
   *  Constant: '<S354>/Constant3'
   *  Constant: '<S354>/Constant4'
   *  Math: '<S354>/Math Function'
   *  Sum: '<S354>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Integral_c3 + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S356>/Sum1' incorporates:
   *  Constant: '<S341>/Constant2'
   *  Product: '<S356>/Product'
   *  Sum: '<S356>/Sum'
   *  UnitDelay: '<S356>/Unit Delay1'
   */
  rtb_Hypot_pi = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_i) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S341>/Product' incorporates:
   *  Constant: '<S341>/Constant3'
   */
  rtb_Product_d1 = rtb_Hypot_pi * Steering_Motor_Control_D;

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
  rtb_Add_mw = rtb_Product_d1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S341>/Saturation' */
  if (rtb_Add_mw > Steering_Motor_Control_D_UL) {
    rtb_Add_mw = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Motor_Control_D_LL) {
    rtb_Add_mw = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S341>/Add' incorporates:
   *  Gain: '<S341>/Gain1'
   *  Saturate: '<S341>/Saturation'
   */
  rtb_Add_pw = (Steering_Motor_Control_P * rtb_Saturation_h) + rtb_Add_mw;

  /* Sum: '<S341>/Subtract' incorporates:
   *  Constant: '<S341>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_pw;

  /* Sum: '<S341>/Sum2' incorporates:
   *  Gain: '<S341>/Gain2'
   *  UnitDelay: '<S341>/Unit Delay'
   */
  rtb_Sum2_fc = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S357>/Switch2' incorporates:
   *  Constant: '<S341>/Constant'
   *  RelationalOperator: '<S357>/LowerRelop1'
   *  Sum: '<S341>/Subtract'
   */
  if (!(rtb_Sum2_fc > (1.0 - rtb_Add_pw))) {
    /* Switch: '<S357>/Switch' incorporates:
     *  Constant: '<S341>/Constant1'
     *  RelationalOperator: '<S357>/UpperRelop'
     *  Sum: '<S341>/Subtract1'
     */
    if (rtb_Sum2_fc < (-1.0 - rtb_Add_pw)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_pw;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_fc;
    }

    /* End of Switch: '<S357>/Switch' */
  }

  /* End of Switch: '<S357>/Switch2' */

  /* Saturate: '<S341>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S341>/Saturation1' */

  /* Sum: '<S341>/Add1' */
  rtb_Add_mw = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S341>/Saturation2' */
  if (rtb_Add_mw > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_mw;
  }

  /* End of Saturate: '<S341>/Saturation2' */

  /* Product: '<S396>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S401>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S401>/Switch' incorporates:
     *  Fcn: '<S402>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S401>/Switch' */

  /* Trigonometry: '<S287>/Cos4' incorporates:
   *  Switch: '<S276>/Angle_Switch'
   *  Trigonometry: '<S286>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S287>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S285>/Unary Minus'
   */
  rtb_Minus_k_idx_0 = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S287>/Sin4' incorporates:
   *  Switch: '<S276>/Angle_Switch'
   *  Trigonometry: '<S286>/Sin4'
   */
  rtb_Subtract_kb = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S287>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S285>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S287>/Subtract1' incorporates:
   *  Product: '<S287>/Product2'
   *  Product: '<S287>/Product3'
   *  Trigonometry: '<S287>/Cos4'
   *  Trigonometry: '<S287>/Sin4'
   */
  rtb_Add_pw = (rtb_MatrixConcatenate_idx_0 * rtb_Minus_k_idx_0) +
    (rtb_Subtract_kb * rtb_Optimized_Module_Angle);

  /* Sum: '<S287>/Subtract' incorporates:
   *  Product: '<S287>/Product'
   *  Product: '<S287>/Product1'
   *  Trigonometry: '<S287>/Cos4'
   *  Trigonometry: '<S287>/Sin4'
   */
  rtb_Subtract1_bm = (rtb_MatrixConcatenate_idx_0 * rtb_Optimized_Module_Angle)
    - (rtb_Subtract_kb * rtb_Minus_k_idx_0);

  /* Math: '<S287>/Hypot' */
  rtb_Hypot_fg = rt_hypotd_snf(rtb_Subtract1_bm, rtb_Add_pw);

  /* Switch: '<S287>/Switch' incorporates:
   *  Constant: '<S287>/Constant'
   *  Constant: '<S287>/Constant1'
   *  Constant: '<S288>/Constant'
   *  Product: '<S287>/Divide'
   *  Product: '<S287>/Divide1'
   *  RelationalOperator: '<S288>/Compare'
   *  Switch: '<S287>/Switch1'
   */
  if (rtb_Hypot_fg > 1.0E-6) {
    rtb_Saturation_h = rtb_Add_pw / rtb_Hypot_fg;
    rtb_Optimized_Module_Angle = rtb_Subtract1_bm / rtb_Hypot_fg;
  } else {
    rtb_Saturation_h = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S287>/Switch' */

  /* Switch: '<S276>/Speed_Switch' incorporates:
   *  Abs: '<S276>/Abs'
   *  Constant: '<S284>/Constant'
   *  RelationalOperator: '<S284>/Compare'
   *  Switch: '<S276>/Angle_Switch'
   *  Trigonometry: '<S286>/Atan1'
   *  Trigonometry: '<S287>/Atan1'
   *  UnaryMinus: '<S276>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Saturation_h, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Minus_k_idx_1 = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S286>/Subtract1' incorporates:
     *  Product: '<S286>/Product2'
     *  Product: '<S286>/Product3'
     *  UnaryMinus: '<S276>/Unary Minus'
     */
    rtb_Add_pw = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Sin5) +
      (rtb_Subtract_kb * Robot_Control_ConstB.Cos5);

    /* Sum: '<S286>/Subtract' incorporates:
     *  Product: '<S286>/Product'
     *  Product: '<S286>/Product1'
     */
    rtb_Hypot_fg = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Cos5) -
      (rtb_Subtract_kb * Robot_Control_ConstB.Sin5);

    /* Math: '<S286>/Hypot' */
    rtb_Subtract1_bm = rt_hypotd_snf(rtb_Hypot_fg, rtb_Add_pw);

    /* Switch: '<S286>/Switch1' incorporates:
     *  Constant: '<S286>/Constant'
     *  Constant: '<S286>/Constant1'
     *  Constant: '<S289>/Constant'
     *  Product: '<S286>/Divide'
     *  Product: '<S286>/Divide1'
     *  RelationalOperator: '<S289>/Compare'
     *  Switch: '<S286>/Switch'
     */
    if (rtb_Subtract1_bm > 1.0E-6) {
      rtb_Hypot_fg /= rtb_Subtract1_bm;
      rtb_Add_pw /= rtb_Subtract1_bm;
    } else {
      rtb_Hypot_fg = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S286>/Switch1' */
    rtb_Minus_k_idx_0 = rt_atan2d_snf(rtb_Add_pw, rtb_Hypot_fg);
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_Minus_k_idx_0 = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S279>/Product2' incorporates:
   *  Constant: '<S279>/Constant'
   *  Switch: '<S276>/Speed_Switch'
   */
  rtb_Saturation_h = rtb_Minus_k_idx_1 * 1154.7574092481445;

  /* Signum: '<S274>/Sign' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S274>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S277>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S278>/Sum'
   */
  rtb_Integral_c3 = rtb_Minus_k_idx_0 - Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S269>/Product' incorporates:
   *  Abs: '<S274>/Abs'
   *  Abs: '<S277>/Abs'
   *  Constant: '<S280>/Constant'
   *  Constant: '<S290>/Constant3'
   *  Constant: '<S290>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S274>/OR'
   *  Lookup_n-D: '<S277>/1-D Lookup Table'
   *  Math: '<S290>/Math Function'
   *  RelationalOperator: '<S274>/Equal1'
   *  RelationalOperator: '<S280>/Compare'
   *  Signum: '<S274>/Sign'
   *  Signum: '<S274>/Sign1'
   *  Sum: '<S277>/Add'
   *  Sum: '<S290>/Add1'
   *  Sum: '<S290>/Add2'
   */
  rtb_Saturation_h = (((real_T)((rtb_Minus_k_idx_1 == rtb_Add_i) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Saturation_h) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_c3 + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_h,
                  rtCP_uDLookupTable_tableData_j, 1U);

  /* Gain: '<S275>/Gain' */
  rtb_Hypot_fg = Drive_Motor_Control_FF * rtb_Saturation_h;

  /* Sum: '<S275>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Saturation_h -= Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S282>/Sum1' incorporates:
   *  Constant: '<S275>/Constant2'
   *  Product: '<S282>/Product'
   *  Sum: '<S282>/Sum'
   *  UnitDelay: '<S282>/Unit Delay1'
   */
  rtb_Add_pw = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S275>/Product' incorporates:
   *  Constant: '<S275>/Constant3'
   */
  rtb_Subtract1_bm = rtb_Add_pw * Drive_Motor_Control_D;

  /* Sum: '<S281>/Diff' incorporates:
   *  UnitDelay: '<S281>/UD'
   *
   * Block description for '<S281>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S281>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Subtract1_bm - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S275>/Saturation' */
  if (rtb_Add_mw > Drive_Motor_Control_D_UL) {
    rtb_Add_mw = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Drive_Motor_Control_D_LL) {
    rtb_Add_mw = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S275>/Add' incorporates:
   *  Gain: '<S275>/Gain1'
   *  Saturate: '<S275>/Saturation'
   */
  rtb_Add_mw += (Drive_Motor_Control_P * rtb_Saturation_h) + rtb_Hypot_fg;

  /* Saturate: '<S275>/Saturation2' */
  if (rtb_Add_mw > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = rtb_Add_mw;
  }

  /* End of Saturate: '<S275>/Saturation2' */

  /* Sum: '<S291>/Add1' incorporates:
   *  Constant: '<S291>/Constant3'
   *  Constant: '<S291>/Constant4'
   *  Math: '<S291>/Math Function'
   *  Sum: '<S291>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Integral_c3 + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S293>/Sum1' incorporates:
   *  Constant: '<S278>/Constant2'
   *  Product: '<S293>/Product'
   *  Sum: '<S293>/Sum'
   *  UnitDelay: '<S293>/Unit Delay1'
   */
  rtb_Hypot_fg = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S278>/Product' incorporates:
   *  Constant: '<S278>/Constant3'
   */
  rtb_Product_i3 = rtb_Hypot_fg * Steering_Motor_Control_D;

  /* Sum: '<S292>/Diff' incorporates:
   *  UnitDelay: '<S292>/UD'
   *
   * Block description for '<S292>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S292>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Product_i3 - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S278>/Saturation' */
  if (rtb_Add_mw > Steering_Motor_Control_D_UL) {
    rtb_Add_mw = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Motor_Control_D_LL) {
    rtb_Add_mw = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S278>/Add' incorporates:
   *  Gain: '<S278>/Gain1'
   *  Saturate: '<S278>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P * rtb_Saturation_h) +
    rtb_Add_mw;

  /* Sum: '<S278>/Subtract' incorporates:
   *  Constant: '<S278>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S278>/Sum2' incorporates:
   *  Gain: '<S278>/Gain2'
   *  UnitDelay: '<S278>/Unit Delay'
   */
  rtb_Sum2_m = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S294>/Switch2' incorporates:
   *  Constant: '<S278>/Constant'
   *  RelationalOperator: '<S294>/LowerRelop1'
   *  Sum: '<S278>/Subtract'
   */
  if (!(rtb_Sum2_m > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S294>/Switch' incorporates:
     *  Constant: '<S278>/Constant1'
     *  RelationalOperator: '<S294>/UpperRelop'
     *  Sum: '<S278>/Subtract1'
     */
    if (rtb_Sum2_m < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_m;
    }

    /* End of Switch: '<S294>/Switch' */
  }

  /* End of Switch: '<S294>/Switch2' */

  /* Saturate: '<S278>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_m = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_m = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_m = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S278>/Saturation1' */

  /* Sum: '<S278>/Add1' */
  rtb_Add_mw = rtb_MatrixConcatenate_idx_0 + rtb_Sum2_m;

  /* Saturate: '<S278>/Saturation2' */
  if (rtb_Add_mw > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_mw;
  }

  /* End of Saturate: '<S278>/Saturation2' */

  /* Product: '<S396>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S406>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S406>/Switch' incorporates:
     *  Fcn: '<S407>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S406>/Switch' */

  /* Trigonometry: '<S308>/Cos4' incorporates:
   *  Switch: '<S297>/Angle_Switch'
   *  Trigonometry: '<S307>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S308>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S306>/Unary Minus'
   */
  rtb_Minus_k_idx_0 = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S308>/Sin4' incorporates:
   *  Switch: '<S297>/Angle_Switch'
   *  Trigonometry: '<S307>/Sin4'
   */
  rtb_Subtract_kb = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S308>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S306>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S308>/Subtract1' incorporates:
   *  Product: '<S308>/Product2'
   *  Product: '<S308>/Product3'
   *  Trigonometry: '<S308>/Cos4'
   *  Trigonometry: '<S308>/Sin4'
   */
  rtb_Saturation_h = (rtb_MatrixConcatenate_idx_0 * rtb_Minus_k_idx_0) +
    (rtb_Subtract_kb * rtb_Optimized_Module_Angle);

  /* Sum: '<S308>/Subtract' incorporates:
   *  Product: '<S308>/Product'
   *  Product: '<S308>/Product1'
   *  Trigonometry: '<S308>/Cos4'
   *  Trigonometry: '<S308>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_MatrixConcatenate_idx_0 * rtb_Optimized_Module_Angle)
    - (rtb_Subtract_kb * rtb_Minus_k_idx_0);

  /* Math: '<S308>/Hypot' */
  rtb_Hypot_a = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Saturation_h);

  /* Switch: '<S308>/Switch' incorporates:
   *  Constant: '<S308>/Constant'
   *  Constant: '<S308>/Constant1'
   *  Constant: '<S309>/Constant'
   *  Product: '<S308>/Divide'
   *  Product: '<S308>/Divide1'
   *  RelationalOperator: '<S309>/Compare'
   *  Switch: '<S308>/Switch1'
   */
  if (rtb_Hypot_a > 1.0E-6) {
    rtb_Saturation_h /= rtb_Hypot_a;
    rtb_Optimized_Module_Angle = rtb_Minus_k_idx_0 / rtb_Hypot_a;
  } else {
    rtb_Saturation_h = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S308>/Switch' */

  /* Switch: '<S297>/Speed_Switch' incorporates:
   *  Abs: '<S297>/Abs'
   *  Constant: '<S305>/Constant'
   *  RelationalOperator: '<S305>/Compare'
   *  Switch: '<S297>/Angle_Switch'
   *  Trigonometry: '<S307>/Atan1'
   *  Trigonometry: '<S308>/Atan1'
   *  UnaryMinus: '<S297>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Saturation_h, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Minus_k_idx_1 = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S307>/Subtract1' incorporates:
     *  Product: '<S307>/Product2'
     *  Product: '<S307>/Product3'
     *  UnaryMinus: '<S297>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_MatrixConcatenate_idx_0 *
                         Robot_Control_ConstB.Sin5_m) + (rtb_Subtract_kb *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S307>/Subtract' incorporates:
     *  Product: '<S307>/Product'
     *  Product: '<S307>/Product1'
     */
    rtb_Subtract_kb = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Cos5_g)
      - (rtb_Subtract_kb * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S307>/Hypot' */
    rtb_MatrixConcatenate_idx_0 = rt_hypotd_snf(rtb_Subtract_kb,
      rtb_Minus_k_idx_0);

    /* Switch: '<S307>/Switch1' incorporates:
     *  Constant: '<S307>/Constant'
     *  Constant: '<S307>/Constant1'
     *  Constant: '<S310>/Constant'
     *  Product: '<S307>/Divide'
     *  Product: '<S307>/Divide1'
     *  RelationalOperator: '<S310>/Compare'
     *  Switch: '<S307>/Switch'
     */
    if (rtb_MatrixConcatenate_idx_0 > 1.0E-6) {
      rtb_Subtract_kb /= rtb_MatrixConcatenate_idx_0;
      rtb_MatrixConcatenate_idx_0 = rtb_Minus_k_idx_0 /
        rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Subtract_kb = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S307>/Switch1' */
    rtb_Minus_k_idx_0 = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0,
      rtb_Subtract_kb);
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_Minus_k_idx_0 = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S300>/Product2' incorporates:
   *  Constant: '<S300>/Constant'
   *  Switch: '<S297>/Speed_Switch'
   */
  rtb_Saturation_h = rtb_Minus_k_idx_1 * 1154.7574092481445;

  /* Signum: '<S295>/Sign' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S295>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S298>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S299>/Sum'
   */
  rtb_Integral_c3 = rtb_Minus_k_idx_0 - Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S270>/Product' incorporates:
   *  Abs: '<S295>/Abs'
   *  Abs: '<S298>/Abs'
   *  Constant: '<S301>/Constant'
   *  Constant: '<S311>/Constant3'
   *  Constant: '<S311>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S295>/OR'
   *  Lookup_n-D: '<S298>/1-D Lookup Table'
   *  Math: '<S311>/Math Function'
   *  RelationalOperator: '<S295>/Equal1'
   *  RelationalOperator: '<S301>/Compare'
   *  Signum: '<S295>/Sign'
   *  Signum: '<S295>/Sign1'
   *  Sum: '<S298>/Add'
   *  Sum: '<S311>/Add1'
   *  Sum: '<S311>/Add2'
   */
  rtb_Saturation_h = (((real_T)((rtb_Minus_k_idx_1 == rtb_Add_i) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Saturation_h) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_c3 + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_p,
                  rtCP_uDLookupTable_tableData_gs, 1U);

  /* Gain: '<S296>/Gain' */
  rtb_Hypot_a = Drive_Motor_Control_FF * rtb_Saturation_h;

  /* Sum: '<S296>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Saturation_h -= Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S303>/Sum1' incorporates:
   *  Constant: '<S296>/Constant2'
   *  Product: '<S303>/Product'
   *  Sum: '<S303>/Sum'
   *  UnitDelay: '<S303>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Saturation_h -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S296>/Product' incorporates:
   *  Constant: '<S296>/Constant3'
   */
  rtb_Subtract_kb = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S302>/Diff' incorporates:
   *  UnitDelay: '<S302>/UD'
   *
   * Block description for '<S302>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S302>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Subtract_kb - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S296>/Saturation' */
  if (rtb_Add_mw > Drive_Motor_Control_D_UL) {
    rtb_Add_mw = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Drive_Motor_Control_D_LL) {
    rtb_Add_mw = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S296>/Add' incorporates:
   *  Gain: '<S296>/Gain1'
   *  Saturate: '<S296>/Saturation'
   */
  rtb_Add_mw += (Drive_Motor_Control_P * rtb_Saturation_h) + rtb_Hypot_a;

  /* Saturate: '<S296>/Saturation2' */
  if (rtb_Add_mw > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = rtb_Add_mw;
  }

  /* End of Saturate: '<S296>/Saturation2' */

  /* Sum: '<S312>/Add1' incorporates:
   *  Constant: '<S312>/Constant3'
   *  Constant: '<S312>/Constant4'
   *  Math: '<S312>/Math Function'
   *  Sum: '<S312>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Integral_c3 + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S314>/Sum1' incorporates:
   *  Constant: '<S299>/Constant2'
   *  Product: '<S314>/Product'
   *  Sum: '<S314>/Sum'
   *  UnitDelay: '<S314>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_n)
                       * Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S299>/Product' incorporates:
   *  Constant: '<S299>/Constant3'
   */
  rtb_Hypot_a = rtb_Minus_k_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S313>/Diff' incorporates:
   *  UnitDelay: '<S313>/UD'
   *
   * Block description for '<S313>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S313>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Hypot_a - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S299>/Saturation' */
  if (rtb_Add_mw > Steering_Motor_Control_D_UL) {
    rtb_Add_mw = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Motor_Control_D_LL) {
    rtb_Add_mw = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S299>/Add' incorporates:
   *  Gain: '<S299>/Gain1'
   *  Saturate: '<S299>/Saturation'
   */
  rtb_Add_i = (Steering_Motor_Control_P * rtb_Saturation_h) + rtb_Add_mw;

  /* Sum: '<S299>/Subtract' incorporates:
   *  Constant: '<S299>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_i;

  /* Sum: '<S299>/Sum2' incorporates:
   *  Gain: '<S299>/Gain2'
   *  UnitDelay: '<S299>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S315>/Switch2' incorporates:
   *  Constant: '<S299>/Constant'
   *  RelationalOperator: '<S315>/LowerRelop1'
   *  Sum: '<S299>/Subtract'
   */
  if (!(rtb_Saturation_h > (1.0 - rtb_Add_i))) {
    /* Switch: '<S315>/Switch' incorporates:
     *  Constant: '<S299>/Constant1'
     *  RelationalOperator: '<S315>/UpperRelop'
     *  Sum: '<S299>/Subtract1'
     */
    if (rtb_Saturation_h < (-1.0 - rtb_Add_i)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_i;
    } else {
      rtb_Optimized_Module_Angle = rtb_Saturation_h;
    }

    /* End of Switch: '<S315>/Switch' */
  }

  /* End of Switch: '<S315>/Switch2' */

  /* Saturate: '<S299>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S299>/Saturation1' */

  /* Sum: '<S299>/Add1' */
  rtb_Add_mw = rtb_Add_i + rtb_Subtract1_kg;

  /* Saturate: '<S299>/Saturation2' */
  if (rtb_Add_mw > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_mw;
  }

  /* End of Saturate: '<S299>/Saturation2' */

  /* Product: '<S396>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S411>/Switch' */
  if (!rtb_Button_Shoot_Enable) {
    /* Switch: '<S411>/Switch' incorporates:
     *  Fcn: '<S412>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S411>/Switch' */

  /* Trigonometry: '<S329>/Cos4' incorporates:
   *  Switch: '<S318>/Angle_Switch'
   *  Trigonometry: '<S328>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S329>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S327>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S329>/Sin4' incorporates:
   *  Switch: '<S318>/Angle_Switch'
   *  Trigonometry: '<S328>/Sin4'
   */
  rtb_Subtract_h = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S329>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S327>/Unary Minus'
   */
  rtb_Saturation_h = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S329>/Subtract1' incorporates:
   *  Product: '<S329>/Product2'
   *  Product: '<S329>/Product3'
   *  Trigonometry: '<S329>/Cos4'
   *  Trigonometry: '<S329>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Add_i * rtb_Optimized_Module_Angle) +
    (rtb_Subtract_h * rtb_Saturation_h);

  /* Sum: '<S329>/Subtract' incorporates:
   *  Product: '<S329>/Product'
   *  Product: '<S329>/Product1'
   *  Trigonometry: '<S329>/Cos4'
   *  Trigonometry: '<S329>/Sin4'
   */
  rtb_Saturation_h = (rtb_Add_i * rtb_Saturation_h) - (rtb_Subtract_h *
    rtb_Optimized_Module_Angle);

  /* Math: '<S329>/Hypot' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Saturation_h,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S329>/Switch' incorporates:
   *  Constant: '<S329>/Constant'
   *  Constant: '<S329>/Constant1'
   *  Constant: '<S330>/Constant'
   *  Product: '<S329>/Divide'
   *  Product: '<S329>/Divide1'
   *  RelationalOperator: '<S330>/Compare'
   *  Switch: '<S329>/Switch1'
   */
  if (rtb_Optimized_Module_Angle > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle;
    rtb_Saturation_h /= rtb_Optimized_Module_Angle;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Saturation_h = 1.0;
  }

  /* End of Switch: '<S329>/Switch' */

  /* Switch: '<S318>/Speed_Switch' incorporates:
   *  Abs: '<S318>/Abs'
   *  Constant: '<S326>/Constant'
   *  RelationalOperator: '<S326>/Compare'
   *  Switch: '<S318>/Angle_Switch'
   *  Trigonometry: '<S328>/Atan1'
   *  Trigonometry: '<S329>/Atan1'
   *  UnaryMinus: '<S318>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Saturation_h)) >
      1.5707963267948966) {
    rtb_Minus_k_idx_1 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S328>/Subtract1' incorporates:
     *  Product: '<S328>/Product2'
     *  Product: '<S328>/Product3'
     *  UnaryMinus: '<S318>/Unary Minus'
     */
    rtb_Saturation_h = (rtb_Add_i * Robot_Control_ConstB.Sin5_e) +
      (rtb_Subtract_h * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S328>/Subtract' incorporates:
     *  Product: '<S328>/Product'
     *  Product: '<S328>/Product1'
     */
    rtb_Subtract_h = (rtb_Add_i * Robot_Control_ConstB.Cos5_i) - (rtb_Subtract_h
      * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S328>/Hypot' */
    rtb_Add_i = rt_hypotd_snf(rtb_Subtract_h, rtb_Saturation_h);

    /* Switch: '<S328>/Switch1' incorporates:
     *  Constant: '<S328>/Constant'
     *  Constant: '<S328>/Constant1'
     *  Constant: '<S331>/Constant'
     *  Product: '<S328>/Divide'
     *  Product: '<S328>/Divide1'
     *  RelationalOperator: '<S331>/Compare'
     *  Switch: '<S328>/Switch'
     */
    if (rtb_Add_i > 1.0E-6) {
      rtb_Subtract_h /= rtb_Add_i;
      rtb_Saturation_h /= rtb_Add_i;
    } else {
      rtb_Subtract_h = 1.0;
      rtb_Saturation_h = 0.0;
    }

    /* End of Switch: '<S328>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Saturation_h, rtb_Subtract_h);
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S321>/Product2' incorporates:
   *  Constant: '<S321>/Constant'
   *  Switch: '<S318>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_1 * 1154.7574092481445;

  /* Signum: '<S316>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S316>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S319>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S320>/Sum'
   */
  rtb_Optimized_Module_Angle -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S271>/Product' incorporates:
   *  Abs: '<S316>/Abs'
   *  Abs: '<S319>/Abs'
   *  Constant: '<S322>/Constant'
   *  Constant: '<S332>/Constant3'
   *  Constant: '<S332>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S316>/OR'
   *  Lookup_n-D: '<S319>/1-D Lookup Table'
   *  Math: '<S332>/Math Function'
   *  RelationalOperator: '<S316>/Equal1'
   *  RelationalOperator: '<S322>/Compare'
   *  Signum: '<S316>/Sign'
   *  Signum: '<S316>/Sign1'
   *  Sum: '<S319>/Add'
   *  Sum: '<S332>/Add1'
   *  Sum: '<S332>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Minus_k_idx_1 == rtb_Add_i) ||
    (fabs(Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_j,
                    rtCP_uDLookupTable_tableData_h, 1U);

  /* Gain: '<S317>/Gain' */
  rtb_Saturation_h = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S317>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S324>/Sum1' incorporates:
   *  Constant: '<S317>/Constant2'
   *  Product: '<S324>/Product'
   *  Sum: '<S324>/Sum'
   *  UnitDelay: '<S324>/Unit Delay1'
   */
  rtb_Add_i = ((rtb_MatrixConcatenate_b_idx_0 -
                Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S317>/Product' incorporates:
   *  Constant: '<S317>/Constant3'
   */
  rtb_Subtract_h = rtb_Add_i * Drive_Motor_Control_D;

  /* Sum: '<S323>/Diff' incorporates:
   *  UnitDelay: '<S323>/UD'
   *
   * Block description for '<S323>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S323>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Subtract_h - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S317>/Saturation' */
  if (rtb_Add_mw > Drive_Motor_Control_D_UL) {
    rtb_Add_mw = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Drive_Motor_Control_D_LL) {
    rtb_Add_mw = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S317>/Add' incorporates:
   *  Gain: '<S317>/Gain1'
   *  Saturate: '<S317>/Saturation'
   */
  rtb_Add_mw += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Saturation_h;

  /* Saturate: '<S317>/Saturation2' */
  if (rtb_Add_mw > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Add_mw;
  }

  /* End of Saturate: '<S317>/Saturation2' */

  /* Sum: '<S333>/Add1' incorporates:
   *  Constant: '<S333>/Constant3'
   *  Constant: '<S333>/Constant4'
   *  Math: '<S333>/Math Function'
   *  Sum: '<S333>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S335>/Sum1' incorporates:
   *  Constant: '<S320>/Constant2'
   *  Product: '<S335>/Product'
   *  Sum: '<S335>/Sum'
   *  UnitDelay: '<S335>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S320>/Product' incorporates:
   *  Constant: '<S320>/Constant3'
   */
  rtb_Product_nq = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S334>/Diff' incorporates:
   *  UnitDelay: '<S334>/UD'
   *
   * Block description for '<S334>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S334>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Product_nq - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S320>/Saturation' */
  if (rtb_Add_mw > Steering_Motor_Control_D_UL) {
    rtb_Add_mw = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Motor_Control_D_LL) {
    rtb_Add_mw = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S320>/Add' incorporates:
   *  Gain: '<S320>/Gain1'
   *  Saturate: '<S320>/Saturation'
   */
  rtb_Add_lu = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_mw;

  /* Sum: '<S320>/Subtract' incorporates:
   *  Constant: '<S320>/Constant'
   */
  rtb_Saturation_h = 1.0 - rtb_Add_lu;

  /* Sum: '<S320>/Sum2' incorporates:
   *  Gain: '<S320>/Gain2'
   *  UnitDelay: '<S320>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S336>/Switch2' incorporates:
   *  Constant: '<S320>/Constant'
   *  RelationalOperator: '<S336>/LowerRelop1'
   *  Sum: '<S320>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_lu))) {
    /* Sum: '<S320>/Subtract1' incorporates:
     *  Constant: '<S320>/Constant1'
     */
    rtb_Saturation_h = -1.0 - rtb_Add_lu;

    /* Switch: '<S336>/Switch' incorporates:
     *  Constant: '<S320>/Constant1'
     *  RelationalOperator: '<S336>/UpperRelop'
     *  Sum: '<S320>/Subtract1'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_lu))) {
      rtb_Saturation_h = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S336>/Switch' */
  }

  /* End of Switch: '<S336>/Switch2' */

  /* Saturate: '<S320>/Saturation1' */
  if (rtb_Saturation_h > Steering_Motor_Control_I_UL) {
    rtb_Integral_g = Steering_Motor_Control_I_UL;
  } else if (rtb_Saturation_h < Steering_Motor_Control_I_LL) {
    rtb_Integral_g = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_g = rtb_Saturation_h;
  }

  /* End of Saturate: '<S320>/Saturation1' */

  /* Sum: '<S320>/Add1' */
  rtb_Add_mw = rtb_Add_lu + rtb_Integral_g;

  /* Saturate: '<S320>/Saturation2' */
  if (rtb_Add_mw > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_mw;
  }

  /* End of Saturate: '<S320>/Saturation2' */

  /* Sum: '<S204>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S144>/Subtract'
   */
  rtb_Integral_c3 = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S206>/Sum1' incorporates:
   *  Constant: '<S204>/Constant2'
   *  Product: '<S206>/Product'
   *  Sum: '<S204>/Sum'
   *  Sum: '<S206>/Sum'
   *  UnitDelay: '<S206>/Unit Delay1'
   */
  rtb_Add_lu = ((rtb_Integral_c3 - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S204>/Product' incorporates:
   *  Constant: '<S204>/Constant3'
   */
  rtb_Product_c2 = rtb_Add_lu * 0.0;

  /* Sum: '<S205>/Diff' incorporates:
   *  UnitDelay: '<S205>/UD'
   *
   * Block description for '<S205>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S205>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Product_c2 - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S204>/Saturation' */
  if (rtb_Add_mw > 0.1) {
    rtb_Add_mw = 0.1;
  } else if (rtb_Add_mw < -0.1) {
    rtb_Add_mw = -0.1;
  }

  /* Sum: '<S204>/Add' incorporates:
   *  Gain: '<S204>/Gain'
   *  Gain: '<S204>/Gain1'
   *  Saturate: '<S204>/Saturation'
   *  Sum: '<S204>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Transfer_Motor_Gain_FF *
    Robot_Control_B.RB_Desired_Transfer_Speed) + (Rebuilt_Transfer_Motor_Gain_P *
    rtb_Integral_c3)) + rtb_Add_mw;

  /* Logic: '<S144>/Logical Operator1' incorporates:
   *  Constant: '<S203>/Constant'
   *  RelationalOperator: '<S203>/Compare'
   */
  rtb_Button_Shoot_Enable = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S144>/Switch1' incorporates:
   *  Abs: '<S144>/Abs'
   *  Constant: '<S144>/Constant1'
   *  Constant: '<S144>/Constant2'
   *  Logic: '<S144>/Logical Operator'
   *  Logic: '<S144>/Logical Operator1'
   *  RelationalOperator: '<S144>/LessThan'
   *  UnitDelay: '<S144>/Unit Delay'
   */
  if ((fabs(rtb_Integral_c3) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Button_Shoot_Enable) {
    rtb_LogicalOperator1 = true;
  } else {
    rtb_LogicalOperator1 = (rtb_Button_Shoot_Enable &&
      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S144>/Switch1' */

  /* Switch: '<S204>/Switch' incorporates:
   *  Constant: '<S204>/Constant4'
   */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S204>/Sum2' incorporates:
     *  Gain: '<S204>/Gain2'
     *  Sum: '<S204>/Sum'
     *  UnitDelay: '<S204>/Unit Delay'
     */
    rtb_Saturation_h = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_c3) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S204>/Subtract' incorporates:
     *  Constant: '<S204>/Constant'
     */
    rtb_Integral_c3 = 1.0 - rtb_MatrixConcatenate_b_idx_0;

    /* Switch: '<S207>/Switch2' incorporates:
     *  Constant: '<S204>/Constant'
     *  RelationalOperator: '<S207>/LowerRelop1'
     *  Sum: '<S204>/Subtract'
     */
    if (!(rtb_Saturation_h > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S204>/Subtract1' incorporates:
       *  Constant: '<S204>/Constant1'
       */
      rtb_Integral_c3 = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S207>/Switch' incorporates:
       *  Constant: '<S204>/Constant1'
       *  RelationalOperator: '<S207>/UpperRelop'
       *  Sum: '<S204>/Subtract1'
       */
      if (!(rtb_Saturation_h < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Integral_c3 = rtb_Saturation_h;
      }

      /* End of Switch: '<S207>/Switch' */
    }

    /* End of Switch: '<S207>/Switch2' */

    /* Saturate: '<S204>/Saturation1' */
    if (rtb_Integral_c3 > 0.1) {
      rtb_Integral_c3 = 0.1;
    } else if (rtb_Integral_c3 < -0.1) {
      rtb_Integral_c3 = -0.1;
    }

    /* End of Saturate: '<S204>/Saturation1' */
  } else {
    rtb_Integral_c3 = 0.0;
  }

  /* End of Switch: '<S204>/Switch' */

  /* Switch: '<S144>/Switch2' incorporates:
   *  Logic: '<S144>/Logical Operator1'
   */
  if (rtb_Button_Shoot_Enable) {
    /* Sum: '<S204>/Add1' */
    rtb_Add_mw = rtb_MatrixConcatenate_b_idx_0 + rtb_Integral_c3;

    /* Saturate: '<S204>/Saturation2' */
    if (rtb_Add_mw > 1.0) {
      /* Switch: '<S144>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_mw < -1.0) {
      /* Switch: '<S144>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S144>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_mw;
    }

    /* End of Saturate: '<S204>/Saturation2' */
  } else {
    /* Switch: '<S144>/Switch2' incorporates:
     *  Constant: '<S144>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S144>/Switch2' */

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
  rtb_Add_mw = Robot_Control_B.RB_Desired_Feeder_Speed *
    Rebuilt_Feeder_Motor_Gain_FF;

  /* Saturate: '<S12>/Saturation' */
  if (rtb_Add_mw > 1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = 1.0;
  } else if (rtb_Add_mw < -1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = -1.0;
  } else {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = rtb_Add_mw;
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Switch: '<S10>/Switch2'
   *  Switch: '<S10>/Switch3'
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
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Sum: '<S143>/Subtract' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Logic: '<S143>/Logical Operator1' incorporates:
   *  Constant: '<S200>/Constant'
   *  RelationalOperator: '<S200>/Compare'
   */
  rtb_Button_Shoot_Enable = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Switch: '<S143>/Switch1' incorporates:
   *  Constant: '<S143>/Constant1'
   *  Constant: '<S143>/Constant2'
   *  Logic: '<S143>/Logical Operator'
   *  Logic: '<S143>/Logical Operator1'
   *  RelationalOperator: '<S143>/LessThan'
   *  UnitDelay: '<S143>/Unit Delay'
   */
  if ((rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_Button_Shoot_Enable) {
    rtb_LogicalOperator5 = true;
  } else {
    rtb_LogicalOperator5 = (rtb_Button_Shoot_Enable &&
      (Robot_Control_DW.UnitDelay_DSTATE_kt));
  }

  /* End of Switch: '<S143>/Switch1' */

  /* Switch: '<S143>/Switch4' incorporates:
   *  Constant: '<S143>/Constant7'
   *  Logic: '<S143>/Logical Operator1'
   *  Logic: '<S143>/Logical Operator3'
   *  RelationalOperator: '<S143>/LessThan2'
   *  UnitDelay: '<S143>/Unit Delay1'
   */
  if ((!(rtb_MatrixConcatenate_b_idx_0 < 0.0)) || (!rtb_Button_Shoot_Enable)) {
    rtb_Button_Shoot_Enable = (rtb_Button_Shoot_Enable &&
      (Robot_Control_DW.UnitDelay1_DSTATE_oa));
  }

  /* End of Switch: '<S143>/Switch4' */

  /* Switch: '<S143>/Switch2' incorporates:
   *  Constant: '<S143>/Constant3'
   *  Constant: '<S143>/Constant9'
   *  Logic: '<S143>/Logical Operator4'
   *  Logic: '<S143>/Logical Operator5'
   */
  if (rtb_LogicalOperator5 && (!rtb_Button_Shoot_Enable)) {
    rtb_Shooter_Motor_Gain_Ki = Rebuilt_Shooter_Motor_Gain_I;
  } else {
    rtb_Shooter_Motor_Gain_Ki = Rebuilt_Shooter_Motor_Gain_I_Low;
  }

  /* End of Switch: '<S143>/Switch2' */

  /* Outport: '<Root>/Shooter_Motor_Gain_Ki' */
  Robot_Control_Y.Shooter_Motor_Gain_Ki = rtb_Shooter_Motor_Gain_Ki;

  /* Outport: '<Root>/Shooter_Motor_Gain_Change' incorporates:
   *  Constant: '<S143>/Constant4'
   *  DataTypeConversion: '<S143>/Data Type Conversion'
   *  Logic: '<S143>/Logical Operator2'
   *  RelationalOperator: '<S201>/FixPt Relational Operator'
   *  RelationalOperator: '<S202>/FixPt Relational Operator'
   *  UnitDelay: '<S201>/Delay Input1'
   *  UnitDelay: '<S202>/Delay Input1'
   *
   * Block description for '<S201>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S202>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_Y.Shooter_Motor_Gain_Change = ((Rebuilt_Shooter_Motor_Gain_P !=
    Robot_Control_DW.DelayInput1_DSTATE_o) || (rtb_Shooter_Motor_Gain_Ki !=
    Robot_Control_DW.DelayInput1_DSTATE_j));

  /* Outport: '<Root>/Shooter_Motor_Gain_Kp' incorporates:
   *  Constant: '<S143>/Constant4'
   */
  Robot_Control_Y.Shooter_Motor_Gain_Kp = Rebuilt_Shooter_Motor_Gain_P;

  /* Switch: '<S10>/Switch5' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant6'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    rtb_MatrixConcatenate_b_idx_0 = TEST_Desired_Hood_Pos_OV;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

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

  /* Switch: '<S134>/Init' incorporates:
   *  UnitDelay: '<S134>/FixPt Unit Delay1'
   *  UnitDelay: '<S134>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Saturation_h = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Saturation_h = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S134>/Init' */

  /* Sum: '<S132>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 -= rtb_Saturation_h;

  /* Switch: '<S133>/Switch2' incorporates:
   *  Constant: '<S131>/Constant1'
   *  Constant: '<S131>/Constant3'
   *  RelationalOperator: '<S133>/LowerRelop1'
   *  RelationalOperator: '<S133>/UpperRelop'
   *  Switch: '<S133>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Hood_Servo_Rate_Limit_Dec)
  {
    /* Switch: '<S133>/Switch' incorporates:
     *  Constant: '<S131>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S133>/Switch2' */

  /* Sum: '<S132>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Saturation_h;

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
    rtb_Compare_pb = false;
  } else {
    switch (Robot_Control_DW.is_c4_Robot_Control) {
     case Robot_Con_IN_Move_Intake_Arm_In:
      rtb_Compare_pb = true;
      if ((rtb_Intake_Arm_Move_Out || (rtb_Intake_Arm_Cycle &&
            (Robot_Control_B.RB_Intake_Arm_Angle_Mod <
             Rebuilt_Intake_Cycle_Angle_In))) || (((int32_T)rtb_Intake_Arm_Cycle)
           < ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_c))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      rtb_Compare_pb = true;
      if (rtb_Intake_Arm_Move_In || (rtb_Intake_Arm_Cycle &&
           (Robot_Control_B.RB_Intake_Arm_Angle_Mod >
            Rebuilt_Intake_Cycle_Angle_Out))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
      }
      break;

     default:
      /* case IN_Wait_for_Button: */
      rtb_Compare_pb = false;
      if (rtb_Intake_Arm_Move_In || rtb_Intake_Arm_Cycle) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
        rtb_Compare_pb = true;
      } else if (rtb_Intake_Arm_Move_Out) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
        rtb_Compare_pb = true;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* Switch: '<S70>/Init' incorporates:
   *  UnitDelay: '<S70>/FixPt Unit Delay1'
   *  UnitDelay: '<S70>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S70>/Init' */

  /* Sum: '<S68>/Sum1' */
  rtb_Saturation_h = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S69>/Switch2' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Constant3'
   *  RelationalOperator: '<S69>/LowerRelop1'
   *  RelationalOperator: '<S69>/UpperRelop'
   *  Switch: '<S69>/Switch'
   */
  if (rtb_Saturation_h > Rebuilt_Intake_RL_Inc) {
    rtb_Saturation_h = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Saturation_h < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S69>/Switch' incorporates:
     *  Constant: '<S57>/Constant1'
     */
    rtb_Saturation_h = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S69>/Switch2' */

  /* Sum: '<S68>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Saturation_h +
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S64>/Sum' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S66>/Sum1' incorporates:
   *  Constant: '<S64>/Constant2'
   *  Product: '<S66>/Product'
   *  Sum: '<S66>/Sum'
   *  UnitDelay: '<S66>/Unit Delay1'
   */
  rtb_Sum1_g = ((rtb_MatrixConcatenate_b_idx_0 -
                 Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S64>/Product' incorporates:
   *  Constant: '<S64>/Constant3'
   */
  rtb_Product_f2 = rtb_Sum1_g * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S65>/Diff' incorporates:
   *  UnitDelay: '<S65>/UD'
   *
   * Block description for '<S65>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S65>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Product_f2 - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S64>/Saturation' */
  if (rtb_Add_mw > 0.1) {
    rtb_Add_mw = 0.1;
  } else if (rtb_Add_mw < -0.1) {
    rtb_Add_mw = -0.1;
  }

  /* Sum: '<S64>/Add' incorporates:
   *  Gain: '<S64>/Gain'
   *  Gain: '<S64>/Gain1'
   *  Saturate: '<S64>/Saturation'
   */
  rtb_Minus_k_idx_1 = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
                       (Rebuilt_Intake_Arm_Gain_P *
                        rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_mw;

  /* Sum: '<S64>/Subtract' incorporates:
   *  Constant: '<S64>/Constant'
   */
  rtb_Saturation_h = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S64>/Sum2' incorporates:
   *  Gain: '<S64>/Gain2'
   *  UnitDelay: '<S64>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (0.0 * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S67>/Switch2' incorporates:
   *  Constant: '<S64>/Constant'
   *  RelationalOperator: '<S67>/LowerRelop1'
   *  Sum: '<S64>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Minus_k_idx_1))) {
    /* Sum: '<S64>/Subtract1' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    rtb_Saturation_h = -1.0 - rtb_Minus_k_idx_1;

    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S64>/Constant1'
     *  RelationalOperator: '<S67>/UpperRelop'
     *  Sum: '<S64>/Subtract1'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Minus_k_idx_1))) {
      rtb_Saturation_h = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S67>/Switch' */
  }

  /* End of Switch: '<S67>/Switch2' */

  /* Saturate: '<S64>/Saturation1' */
  if (rtb_Saturation_h > 0.1) {
    rtb_Saturation_h = 0.1;
  } else if (rtb_Saturation_h < -0.1) {
    rtb_Saturation_h = -0.1;
  }

  /* End of Saturate: '<S64>/Saturation1' */

  /* Switch: '<S56>/Switch2' incorporates:
   *  Constant: '<S60>/Constant'
   *  Constant: '<S61>/Constant'
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  Logic: '<S56>/Logical Operator1'
   *  Logic: '<S56>/Logical Operator2'
   *  Logic: '<S56>/Logical Operator3'
   *  RelationalOperator: '<S60>/Compare'
   *  RelationalOperator: '<S61>/Compare'
   *  RelationalOperator: '<S62>/Compare'
   *  RelationalOperator: '<S63>/Compare'
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
    /* Sum: '<S64>/Add1' */
    rtb_Add_mw = rtb_Minus_k_idx_1 + rtb_Saturation_h;

    /* Saturate: '<S64>/Saturation2' */
    if (rtb_Add_mw > 1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_mw < -1.0) {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S56>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_mw;
    }

    /* End of Saturate: '<S64>/Saturation2' */
  }

  /* End of Switch: '<S56>/Switch2' */

  /* Switch: '<S10>/Switch7' incorporates:
   *  Constant: '<S10>/Constant'
   *  Switch: '<S6>/Switch1'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Intake_Arm_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant9'
     */
    Robot_Control_Y.Intake_Arm_Motor_DC = TEST_Intake_Arm_Motor_DC_OV;
  } else if (rtb_Compare_pb) {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Outport: '<Root>/Intake_Arm_Motor_DC'
     */
    Robot_Control_Y.Intake_Arm_Motor_DC =
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC;
  } else {
    /* Outport: '<Root>/Intake_Arm_Motor_DC' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Switch: '<S6>/Switch1'
     */
    Robot_Control_Y.Intake_Arm_Motor_DC = 0.0;
  }

  /* End of Switch: '<S10>/Switch7' */

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S58>/Constant1'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  if (rtb_Intake_Arm_Move_In) {
    rtb_Minus_k_idx_1 = 0.0;
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_DW.UnitDelay_DSTATE_eo;
  }

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S53>/Constant'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S71>/Constant'
   *  Logic: '<S6>/Logical Operator'
   *  Logic: '<S6>/Logical Operator1'
   *  RelationalOperator: '<S53>/Compare'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S71>/Compare'
   *  Sum: '<S58>/Sum'
   *  Switch: '<S58>/Switch'
   */
  if (((((Robot_Control_B.RB_Des_Intake_Arm_Angle == Rebuilt_Intake_Des_Angle_In)
         && (Robot_Control_B.RB_Transfer_Motor_PID_DC != 0.0)) ||
        rtb_Intake_Arm_Cycle) || ((rtb_Minus_k_idx_1 + 0.02) <=
        Rebuilt_Roller_Intake_In_Delay)) || rtb_LogicalOperator1_ms) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S73>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S59>/Subtract'
   */
  rtb_Error_n = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S75>/Sum1' incorporates:
   *  Constant: '<S73>/Constant2'
   *  Product: '<S75>/Product'
   *  Sum: '<S73>/Sum'
   *  Sum: '<S75>/Sum'
   *  UnitDelay: '<S75>/Unit Delay1'
   */
  rtb_Sum1_ei = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S73>/Product' incorporates:
   *  Constant: '<S73>/Constant3'
   */
  rtb_Product_in = rtb_Sum1_ei * 0.0;

  /* Sum: '<S74>/Diff' incorporates:
   *  UnitDelay: '<S74>/UD'
   *
   * Block description for '<S74>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S74>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Product_in - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S73>/Saturation' */
  if (rtb_Add_mw > 0.1) {
    rtb_Add_mw = 0.1;
  } else if (rtb_Add_mw < -0.1) {
    rtb_Add_mw = -0.1;
  }

  /* Sum: '<S73>/Add' incorporates:
   *  Gain: '<S73>/Gain'
   *  Gain: '<S73>/Gain1'
   *  Saturate: '<S73>/Saturation'
   *  Sum: '<S73>/Sum'
   */
  rtb_Add_mw += (Rebuilt_Roller_Motor_Gain_FF * rtb_MatrixConcatenate_b_idx_0) +
    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n);

  /* Logic: '<S59>/Logical Operator1' incorporates:
   *  Constant: '<S72>/Constant'
   *  RelationalOperator: '<S72>/Compare'
   */
  rtb_Intake_Arm_Move_Out = !(rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S59>/Switch1' incorporates:
   *  Abs: '<S59>/Abs'
   *  Constant: '<S59>/Constant1'
   *  Constant: '<S59>/Constant2'
   *  Logic: '<S59>/Logical Operator'
   *  Logic: '<S59>/Logical Operator1'
   *  RelationalOperator: '<S59>/LessThan'
   *  UnitDelay: '<S59>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_Intake_Arm_Move_Out) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_Intake_Arm_Move_Out &&
      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S59>/Switch1' */

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S73>/Constant4'
   */
  if (rtb_Intake_Arm_Move_In) {
    /* Sum: '<S73>/Sum2' incorporates:
     *  Gain: '<S73>/Gain2'
     *  Sum: '<S73>/Sum'
     *  UnitDelay: '<S73>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n)
      + Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S73>/Subtract' incorporates:
     *  Constant: '<S73>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Add_mw;

    /* Switch: '<S76>/Switch2' incorporates:
     *  Constant: '<S73>/Constant'
     *  RelationalOperator: '<S76>/LowerRelop1'
     *  Sum: '<S73>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_mw))) {
      /* Sum: '<S73>/Subtract1' incorporates:
       *  Constant: '<S73>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Add_mw;

      /* Switch: '<S76>/Switch' incorporates:
       *  Constant: '<S73>/Constant1'
       *  RelationalOperator: '<S76>/UpperRelop'
       *  Sum: '<S73>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_mw))) {
        rtb_Error_n = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S76>/Switch' */
    }

    /* End of Switch: '<S76>/Switch2' */

    /* Saturate: '<S73>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_MatrixConcatenate_b_idx_0 = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_MatrixConcatenate_b_idx_0 = -0.1;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Error_n;
    }

    /* End of Saturate: '<S73>/Saturation1' */
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S73>/Switch' */

  /* Switch: '<S59>/Switch2' incorporates:
   *  Logic: '<S59>/Logical Operator1'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S73>/Add1' */
    rtb_Add_mw += rtb_MatrixConcatenate_b_idx_0;

    /* Saturate: '<S73>/Saturation2' */
    if (rtb_Add_mw > 1.0) {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_mw < -1.0) {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_mw;
    }

    /* End of Saturate: '<S73>/Saturation2' */
  } else {
    /* Switch: '<S59>/Switch2' incorporates:
     *  Constant: '<S59>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S59>/Switch2' */

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

  /* Update for UnitDelay: '<S36>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *
   * Block description for '<S36>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Gamepad_B3_X;

  /* Update for UnitDelay: '<S37>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *
   * Block description for '<S37>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Gamepad_B4_Y;

  /* Update for UnitDelay: '<S38>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Gamepad_B2_B;

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

  /* Update for Delay: '<S77>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S97>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S77>/A'
   *  Delay: '<S77>/MemoryX'
   */
  rtb_Sum1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Switch1_hb = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S77>/MemoryX' incorporates:
   *  Constant: '<S77>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S97>/A[k]*xhat[k|k-1]'
   *  Product: '<S97>/B[k]*u[k]'
   *  Sum: '<S97>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Sum1) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Switch1_hb) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S369>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S369>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S187>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_o = rtb_Merge1;

  /* Update for UnitDelay: '<S188>/Unit Delay' incorporates:
   *  Constant: '<S188>/Constant4'
   *  Sum: '<S188>/Sum'
   *  Switch: '<S188>/Switch'
   */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Minus_f + 0.02;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_1_DSTATE =
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_4_DSTATE =
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_5_DSTATE = Robot_Control_B.Can_Pass;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_2_DSTATE = Robot_Control_B.RB_Desired_Shooter_Speed;

  /* Update for UnitDelay generated from: '<S12>/Unit Delay' */
  Robot_Control_DW.UnitDelay_3_DSTATE =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S392>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Switch_cn;

  /* Update for UnitDelay: '<S391>/UD'
   *
   * Block description for '<S391>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Switch1_n;

  /* Update for UnitDelay: '<S389>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch2_dh;

  /* Update for UnitDelay: '<S371>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Init_o;

  /* Update for UnitDelay: '<S386>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S386>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S386>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S370>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Switch2_g;

  /* Update for UnitDelay: '<S379>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S379>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S379>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Switch2_g;

  /* Update for UnitDelay: '<S345>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Init;

  /* Update for UnitDelay: '<S344>/UD'
   *
   * Block description for '<S344>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2_i;

  /* Update for UnitDelay: '<S356>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Hypot_pi;

  /* Update for UnitDelay: '<S355>/UD'
   *
   * Block description for '<S355>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Product_d1;

  /* Update for UnitDelay: '<S341>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S282>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Add_pw;

  /* Update for UnitDelay: '<S281>/UD'
   *
   * Block description for '<S281>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Subtract1_bm;

  /* Update for UnitDelay: '<S293>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_fg;

  /* Update for UnitDelay: '<S292>/UD'
   *
   * Block description for '<S292>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Product_i3;

  /* Update for UnitDelay: '<S278>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_m;

  /* Update for UnitDelay: '<S303>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S302>/UD'
   *
   * Block description for '<S302>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract_kb;

  /* Update for UnitDelay: '<S314>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S313>/UD'
   *
   * Block description for '<S313>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Hypot_a;

  /* Update for UnitDelay: '<S299>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S324>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_i;

  /* Update for UnitDelay: '<S323>/UD'
   *
   * Block description for '<S323>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_Subtract_h;

  /* Update for UnitDelay: '<S335>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S334>/UD'
   *
   * Block description for '<S334>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_nq;

  /* Update for UnitDelay: '<S320>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_g;

  /* Update for UnitDelay: '<S206>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_lu;

  /* Update for UnitDelay: '<S205>/UD'
   *
   * Block description for '<S205>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_c2;

  /* Update for UnitDelay: '<S204>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_c3;

  /* Update for UnitDelay: '<S144>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S143>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kt = rtb_LogicalOperator5;

  /* Update for UnitDelay: '<S143>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_oa = rtb_Button_Shoot_Enable;

  /* Update for UnitDelay: '<S201>/Delay Input1'
   *
   * Block description for '<S201>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Shooter_Motor_Gain_Ki;

  /* Update for UnitDelay: '<S202>/Delay Input1' incorporates:
   *  Constant: '<S143>/Constant4'
   *
   * Block description for '<S202>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_o = Rebuilt_Shooter_Motor_Gain_P;

  /* Update for UnitDelay: '<S134>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S134>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S55>/Delay Input1'
   *
   * Block description for '<S55>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S70>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S70>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S66>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_g;

  /* Update for UnitDelay: '<S65>/UD'
   *
   * Block description for '<S65>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_f2;

  /* Update for UnitDelay: '<S64>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_Saturation_h;

  /* Update for UnitDelay: '<S58>/Unit Delay' incorporates:
   *  Constant: '<S58>/Constant'
   *  Sum: '<S58>/Sum'
   *  Switch: '<S58>/Switch'
   */
  Robot_Control_DW.UnitDelay_DSTATE_eo = rtb_Minus_k_idx_1 + 0.02;

  /* Update for UnitDelay: '<S75>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_ei;

  /* Update for UnitDelay: '<S74>/UD'
   *
   * Block description for '<S74>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_in;

  /* Update for UnitDelay: '<S73>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S59>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Intake_Arm_Move_In;
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

  /* Start for If: '<S137>/If' */
  Robot_Control_DW.If_ActiveSubsystem_n = -1;

  /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S47>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S50>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S77>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S369>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S386>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S379>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S134>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S70>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S449>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S214>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S210>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S214>/Robot_Index_Is_Valid' */
  /* Start for If: '<S217>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S217>/Circle_Check_Valid' */
  /* Start for If: '<S219>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S217>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S214>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S137>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S181>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S137>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S137>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S137>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S137>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S183>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S137>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S137>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S137>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S137>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S185>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S137>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S137>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S186>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S137>/If Action Subsystem5' */
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
