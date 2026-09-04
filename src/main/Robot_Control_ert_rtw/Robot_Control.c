/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 7.1
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Thu Sep  3 20:19:26 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Robot_Control.h"
#include "rtwtypes.h"
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
#include "Robot_Control_private.h"

/* Named constants for Chart: '<S6>/Chart' */
#define Robot_Co_IN_Move_Intake_Arm_Out ((uint8_T)2U)
#define Robot_Con_IN_Move_Intake_Arm_In ((uint8_T)1U)
#define Robot_Contro_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Robot_Contro_IN_Wait_for_Button ((uint8_T)3U)

/* Named constants for Chart: '<S11>/Chart' */
#define Robot_Control_IN_Disabled      ((uint8_T)1U)
#define Robot_Control_IN_Not_Disabled  ((uint8_T)2U)

/* Named constants for Chart: '<S12>/Chart' */
#define Robot_Con_IN_if_reverse_or_zero ((uint8_T)2U)
#define Robot_Control_IN_Backwards     ((uint8_T)1U)
#define Robot_Control_IN_Forwards      ((uint8_T)2U)
#define Robot_Control_IN_if_forward    ((uint8_T)1U)

/* Named constants for Chart: '<S12>/Shooter_Transfer_Feeder Chart' */
#define Robot_Control_IN_Feeder        ((uint8_T)1U)
#define Robot_Control_IN_Not_Shooting  ((uint8_T)1U)
#define Robot_Control_IN_Shooting      ((uint8_T)2U)
#define Robot_Control_IN_Spinning_Up   ((uint8_T)2U)
#define Robot_Control_IN_Transfer      ((uint8_T)3U)

/* Named constants for Chart: '<S384>/Add dither' */
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
real_T Auto_Deploy_Intake_Time2 = 0.0; /* Variable: Auto_Deploy_Intake_Time2
                                        * Referenced by: '<S28>/Constant'
                                        */
real_T Auto_Intake_Arm_Cycle_Delay_Time = 2.0;
                                   /* Variable: Auto_Intake_Arm_Cycle_Delay_Time
                                    * Referenced by: '<S33>/Constant'
                                    */
real_T Auto_Path_Chooser = 3.0;        /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S21>/Constant17'
                                        */
real_T Auto_Shoot_Time = 4.5;          /* Variable: Auto_Shoot_Time
                                        * Referenced by: '<S24>/Constant'
                                        */
real_T Blue_Hub_LeftX = 5.1717;        /* Variable: Blue_Hub_LeftX
                                        * Referenced by: '<S163>/Constant2'
                                        */
real_T Blue_Hub_LeftY = 3.354;         /* Variable: Blue_Hub_LeftY
                                        * Referenced by: '<S163>/Constant3'
                                        */
real_T Blue_Hub_RightX = 5.1717;       /* Variable: Blue_Hub_RightX
                                        * Referenced by: '<S163>/Constant4'
                                        */
real_T Blue_Hub_RightY = 4.548;        /* Variable: Blue_Hub_RightY
                                        * Referenced by: '<S163>/Constant5'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S459>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S455>/Constant'
                                        *   '<S455>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S459>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S455>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S287>/Constant3'
                                        *   '<S308>/Constant3'
                                        *   '<S329>/Constant3'
                                        *   '<S350>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S287>/Constant2'
                                   *   '<S308>/Constant2'
                                   *   '<S329>/Constant2'
                                   *   '<S350>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S287>/Saturation'
                                        *   '<S308>/Saturation'
                                        *   '<S329>/Saturation'
                                        *   '<S350>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S287>/Saturation'
                                        *   '<S308>/Saturation'
                                        *   '<S329>/Saturation'
                                        *   '<S350>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S287>/Gain'
                                            *   '<S308>/Gain'
                                            *   '<S329>/Gain'
                                            *   '<S350>/Gain'
                                            */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S287>/Gain1'
                                        *   '<S308>/Gain1'
                                        *   '<S329>/Gain1'
                                        *   '<S350>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S292>/Constant'
                            *   '<S313>/Constant'
                            *   '<S334>/Constant'
                            *   '<S355>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S208>/BlueAllianceZoneX'
                                         *   '<S210>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S164>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S164>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S164>/Constant1'
                                        *   '<S164>/Switch3'
                                        *   '<S177>/If'
                                        */
real_T Field_Length = 17.557;          /* Variable: Field_Length
                                        * Referenced by: '<S163>/Constant10'
                                        */
real_T Field_Length_Half = 8.7785;     /* Variable: Field_Length_Half
                                        * Referenced by:
                                        *   '<S181>/Switch'
                                        *   '<S182>/Switch'
                                        */
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S164>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S164>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S209>/RedAllianceZoneX'
                                         *   '<S211>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S164>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S164>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S444>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S444>/Constant5'
                                          */
real_T Field_Width_Pass = 7.0692;      /* Variable: Field_Width_Pass
                                        * Referenced by: '<S163>/Constant11'
                                        */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rate_Limit_X = 1000.0;          /* Variable: Rate_Limit_X
                                        * Referenced by: '<S42>/Constant3'
                                        */
real_T Rate_Limit_Y = 1000.0;          /* Variable: Rate_Limit_Y
                                        * Referenced by: '<S43>/Constant3'
                                        */
real_T Rate_Limit_Z = 1000.0;          /* Variable: Rate_Limit_Z
                                        * Referenced by: '<S44>/Constant3'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = 0.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S179>/Constant'
                                       */
real_T Rebuilt_Feeder_Motor_Gain_FF = 0.00016534;/* Variable: Rebuilt_Feeder_Motor_Gain_FF
                                                  * Referenced by: '<S12>/Constant'
                                                  */
real_T Rebuilt_Feeder_Time_FWD = 0.5;  /* Variable: Rebuilt_Feeder_Time_FWD
                                        * Referenced by: '<S12>/Chart'
                                        */
real_T Rebuilt_Feeder_Time_REV = 0.5;  /* Variable: Rebuilt_Feeder_Time_REV
                                        * Referenced by: '<S12>/Chart'
                                        */
real_T Rebuilt_Hood_Servo_Pos_Max = 1.0;/* Variable: Rebuilt_Hood_Servo_Pos_Max
                                         * Referenced by: '<S10>/Saturation'
                                         */
real_T Rebuilt_Hood_Servo_Pos_Min = 0.05;/* Variable: Rebuilt_Hood_Servo_Pos_Min
                                          * Referenced by:
                                          *   '<S10>/Saturation'
                                          *   '<S157>/Constant3'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S140>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S140>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S67>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.008;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                          * Referenced by: '<S67>/Gain1'
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
                                            *   '<S56>/Constant'
                                            *   '<S63>/Constant'
                                            */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S64>/Constant'
                                            */
real_T Rebuilt_Intake_Meas_In_Disable = -20.0;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S65>/Constant'
                                      */
real_T Rebuilt_Intake_Meas_Out_Disable = 40.0;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S66>/Constant'
                                     */
real_T Rebuilt_Intake_RL_Dec = -3.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S60>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 3.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S60>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 30.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S193>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S197>/Constant3'
                                   *   '<S198>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S187>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S188>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S189>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S190>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S194>/Unit Delay'
                                      *   '<S195>/Unit Delay'
                                      *   '<S196>/Unit Delay'
                                      *   '<S197>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S194>/Constant2'
                                      *   '<S195>/Constant2'
                                      *   '<S196>/Constant2'
                                      *   '<S197>/Constant2'
                                      *   '<S201>/Constant'
                                      *   '<S202>/Constant'
                                      *   '<S203>/Constant'
                                      *   '<S204>/Constant'
                                      */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S184>/Constant'
                                       */
real_T Rebuilt_Negative_Feeder_Speed = -3000.0;
                                      /* Variable: Rebuilt_Negative_Feeder_Speed
                                       * Referenced by:
                                       *   '<S12>/Chart'
                                       *   '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Roller_Desired_Speed = 6000.0;/* Variable: Rebuilt_Roller_Desired_Speed
                                              * Referenced by: '<S6>/Constant'
                                              */
real_T Rebuilt_Roller_Error_Integral_Enable = 300.0;
                               /* Variable: Rebuilt_Roller_Error_Integral_Enable
                                * Referenced by: '<S62>/Constant1'
                                */
real_T Rebuilt_Roller_Intake_In_Delay = 2.0;
                                     /* Variable: Rebuilt_Roller_Intake_In_Delay
                                      * Referenced by: '<S74>/Constant'
                                      */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00016534;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                                  * Referenced by: '<S76>/Gain'
                                                  */
real_T Rebuilt_Roller_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                             * Referenced by: '<S76>/Gain2'
                                             */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0001;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                             * Referenced by: '<S76>/Gain1'
                                             */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S165>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S165>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S165>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S165>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S165>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S165>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S165>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S165>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S160>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S160>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S160>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 3.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S160>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S160>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S160>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S160>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S160>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S161>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S161>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S161>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S161>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S161>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S161>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S161>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S161>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S152>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S152>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S152>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2725.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S174>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S174>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3265.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S174>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3425.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S174>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3625.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S174>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3775.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S174>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S174>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S174>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2825.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S173>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S173>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3365.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S173>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3525.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S173>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3725.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S173>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3875.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S173>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S173>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S173>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S167>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S167>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S167>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S167>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S167>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S167>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S167>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S167>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S171>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S154>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00015;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S12>/Constant1'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 0.03;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                            * Referenced by: '<S154>/Constant3'
                                            */
real_T Rebuilt_Shooter_Motor_Gain_I_Low = 0.0;
                                   /* Variable: Rebuilt_Shooter_Motor_Gain_I_Low
                                    * Referenced by: '<S154>/Constant9'
                                    */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.06;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                            * Referenced by: '<S154>/Constant4'
                                            */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S162>/Constant2'
                                        */
real_T Rebuilt_Target_Feeder_Speed = 10080.0;/* Variable: Rebuilt_Target_Feeder_Speed
                                              * Referenced by:
                                              *   '<S12>/Chart'
                                              *   '<S12>/Shooter_Transfer_Feeder Chart'
                                              */
real_T Rebuilt_Target_Transfer_Speed = 4000.0;
                                      /* Variable: Rebuilt_Target_Transfer_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Transfer_Error_Integral_Enable = 300.0;
                             /* Variable: Rebuilt_Transfer_Error_Integral_Enable
                              * Referenced by: '<S155>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S216>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S216>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S216>/Gain1'
                                       */
real_T Red_Hub_LeftX = 11.369;         /* Variable: Red_Hub_LeftX
                                        * Referenced by: '<S163>/Constant6'
                                        */
real_T Red_Hub_LeftY = 4.548;          /* Variable: Red_Hub_LeftY
                                        * Referenced by: '<S163>/Constant7'
                                        */
real_T Red_Hub_RightX = 11.369;        /* Variable: Red_Hub_RightX
                                        * Referenced by: '<S163>/Constant8'
                                        */
real_T Red_Hub_RightY = 3.354;         /* Variable: Red_Hub_RightY
                                        * Referenced by: '<S163>/Constant9'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S443>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S441>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S443>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S444>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S444>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S276>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S276>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S223>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S236>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S276>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S383>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S383>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S383>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S383>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S383>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S383>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S401>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S401>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S401>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S401>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S400>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S401>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S401>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S401>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S401>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S401>/Constant1'
                                   *   '<S401>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S401>/Constant'
                                   *   '<S401>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S384>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S384>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S384>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S384>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S290>/Constant3'
                                        *   '<S311>/Constant3'
                                        *   '<S332>/Constant3'
                                        *   '<S353>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S290>/Constant2'
                                *   '<S311>/Constant2'
                                *   '<S332>/Constant2'
                                *   '<S353>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S290>/Saturation'
                                           *   '<S311>/Saturation'
                                           *   '<S332>/Saturation'
                                           *   '<S353>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S290>/Saturation'
                                          *   '<S311>/Saturation'
                                          *   '<S332>/Saturation'
                                          *   '<S353>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S290>/Gain2'
                                         *   '<S311>/Gain2'
                                         *   '<S332>/Gain2'
                                         *   '<S353>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S290>/Saturation1'
                                             *   '<S311>/Saturation1'
                                             *   '<S332>/Saturation1'
                                             *   '<S353>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S290>/Saturation1'
                                            *   '<S311>/Saturation1'
                                            *   '<S332>/Saturation1'
                                            *   '<S353>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S290>/Gain1'
                                        *   '<S311>/Gain1'
                                        *   '<S332>/Gain1'
                                        *   '<S353>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S382>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S382>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S382>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S382>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S382>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S382>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S443>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S443>/Constant1'
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
                                      * Referenced by: '<S442>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S442>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S442>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S370>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S370>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S370>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S370>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S370>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S370>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S444>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S443>/Dead Zone'
                                        *   '<S444>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S443>/Dead Zone'
                                        *   '<S444>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S441>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S441>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S441>/Constant4'
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
                                        * Referenced by: '<S441>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S441>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S441>/Constant5'
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
                                        *   '<S441>/Constant11'
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
  real_T rtb_MatrixConcatenate_k[450];
  real_T rtb_MatrixConcatenate_o[450];
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
  real_T rtb_Reshape3[2];
  real_T rtb_Add_di;
  real_T rtb_Add_f1;
  real_T rtb_Add_ir;
  real_T rtb_Add_pw;
  real_T rtb_Error_n;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Init;
  real_T rtb_Integral_c3;
  real_T rtb_Integral_g;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_MatrixConcatenate_idx_0;
  real_T rtb_Merge1;
  real_T rtb_Minus_f_tmp;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Product_dq;
  real_T rtb_Product_gy;
  real_T rtb_Product_ih;
  real_T rtb_Product_k;
  real_T rtb_Product_kv;
  real_T rtb_Shooter_Motor_Gain_Ki;
  real_T rtb_Subtract1_bm;
  real_T rtb_Subtract1_kg;
  real_T rtb_Subtract_av;
  real_T rtb_Subtract_c3;
  real_T rtb_Subtract_dr;
  real_T rtb_Subtract_iu;
  real_T rtb_Sum1;
  real_T rtb_Sum1_ei;
  real_T rtb_Sum1_g;
  real_T rtb_Sum2_fc;
  real_T rtb_Sum2_m;
  real_T rtb_Switch11;
  real_T rtb_Switch1_ac;
  real_T rtb_Switch1_c;
  real_T rtb_Switch1_dt;
  real_T rtb_Switch1_jy;
  real_T rtb_Switch1_py;
  real_T rtb_Switch2_ks;
  real_T rtb_Switch2_n;
  real_T rtb_Switch4_fu;
  real_T rtb_Switch_cn;
  real_T rtb_uDLookupTable_d;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s248_iter;
  uint16_T s273_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T Iteration_Number;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4_j;
  boolean_T rtb_Button_Spinup_Enable;
  boolean_T rtb_Compare_a3;
  boolean_T rtb_Compare_cp;
  boolean_T rtb_Compare_ir;
  boolean_T rtb_Compare_lp;
  boolean_T rtb_Intake_Arm_Cycle;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_Shooter_Active_prev;

  /* RelationalOperator: '<S39>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *  UnitDelay: '<S39>/Delay Input1'
   *
   * Block description for '<S39>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Gamepad_B3_X >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S40>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *  UnitDelay: '<S40>/Delay Input1'
   *
   * Block description for '<S40>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets = (Robot_Control_U.Gamepad_B4_Y >
    Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S41>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *  UnitDelay: '<S41>/Delay Input1'
   *
   * Block description for '<S41>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Gamepad_B2_B >
    Robot_Control_DW.DelayInput1_DSTATE_n);

  /* SignalConversion: '<S5>/Signal Copy1' incorporates:
   *  Inport: '<Root>/Joystick_Left_X'
   */
  Robot_Control_B.Drive_Joystick_X_preRL = Robot_Control_U.Joystick_Left_X;

  /* Switch: '<S47>/Init' incorporates:
   *  UnitDelay: '<S47>/FixPt Unit Delay1'
   *  UnitDelay: '<S47>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Subtract_c3 = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Subtract_c3 = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S47>/Init' */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Constant: '<S42>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Switch1_c = Rate_Limit_X;
  } else {
    rtb_Switch1_c = 1000.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Sum: '<S45>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Subtract_c3;

  /* Switch: '<S46>/Switch2' incorporates:
   *  RelationalOperator: '<S46>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Switch1_c)) {
    /* Switch: '<S42>/Switch1' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant3'
     *  UnaryMinus: '<S42>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_py = -Rate_Limit_X;
    } else {
      rtb_Switch1_py = -1000.0;
    }

    /* End of Switch: '<S42>/Switch1' */

    /* Switch: '<S46>/Switch' incorporates:
     *  RelationalOperator: '<S46>/UpperRelop'
     */
    if (rtb_Sum1 < rtb_Switch1_py) {
      rtb_Switch1_c = rtb_Switch1_py;
    } else {
      rtb_Switch1_c = rtb_Sum1;
    }

    /* End of Switch: '<S46>/Switch' */
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Sum: '<S45>/Sum' */
  rtb_Sum1 = rtb_Switch1_c + rtb_Subtract_c3;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S50>/Init' incorporates:
   *  UnitDelay: '<S50>/FixPt Unit Delay1'
   *  UnitDelay: '<S50>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_j != 0) {
    rtb_Switch1_c = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Switch1_c = Robot_Control_DW.FixPtUnitDelay1_DSTATE_a;
  }

  /* End of Switch: '<S50>/Init' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_c3 = Rate_Limit_Y;
  } else {
    rtb_Subtract_c3 = 1000.0;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Sum: '<S48>/Sum1' */
  rtb_Switch1_py = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Switch1_c;

  /* Switch: '<S49>/Switch2' incorporates:
   *  RelationalOperator: '<S49>/LowerRelop1'
   */
  if (!(rtb_Switch1_py > rtb_Subtract_c3)) {
    /* Switch: '<S43>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant3'
     *  UnaryMinus: '<S43>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_jy = -Rate_Limit_Y;
    } else {
      rtb_Switch1_jy = -1000.0;
    }

    /* End of Switch: '<S43>/Switch1' */

    /* Switch: '<S49>/Switch' incorporates:
     *  RelationalOperator: '<S49>/UpperRelop'
     */
    if (rtb_Switch1_py < rtb_Switch1_jy) {
      rtb_Subtract_c3 = rtb_Switch1_jy;
    } else {
      rtb_Subtract_c3 = rtb_Switch1_py;
    }

    /* End of Switch: '<S49>/Switch' */
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Sum: '<S48>/Sum' */
  rtb_Switch1_py = rtb_Subtract_c3 + rtb_Switch1_c;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S53>/Init' incorporates:
   *  UnitDelay: '<S53>/FixPt Unit Delay1'
   *  UnitDelay: '<S53>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Switch1_c = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Switch1_c = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S53>/Init' */

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Constant2'
   *  Constant: '<S44>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_c3 = Rate_Limit_Z;
  } else {
    rtb_Subtract_c3 = 1000.0;
  }

  /* End of Switch: '<S44>/Switch' */

  /* Sum: '<S51>/Sum1' */
  rtb_Switch1_jy = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Switch1_c;

  /* Switch: '<S52>/Switch2' incorporates:
   *  RelationalOperator: '<S52>/LowerRelop1'
   */
  if (!(rtb_Switch1_jy > rtb_Subtract_c3)) {
    /* Switch: '<S44>/Switch1' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant3'
     *  UnaryMinus: '<S44>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Subtract_c3 = -Rate_Limit_Z;
    } else {
      rtb_Subtract_c3 = -1000.0;
    }

    /* End of Switch: '<S44>/Switch1' */

    /* Switch: '<S52>/Switch' incorporates:
     *  RelationalOperator: '<S52>/UpperRelop'
     */
    if (!(rtb_Switch1_jy < rtb_Subtract_c3)) {
      rtb_Subtract_c3 = rtb_Switch1_jy;
    }

    /* End of Switch: '<S52>/Switch' */
  }

  /* End of Switch: '<S52>/Switch2' */

  /* Sum: '<S51>/Sum' */
  rtb_Switch1_jy = rtb_Subtract_c3 + rtb_Switch1_c;

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
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

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* Sum: '<S36>/Add1' incorporates:
   *  Constant: '<S36>/Constant3'
   *  Constant: '<S36>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Math: '<S36>/Math Function'
   *  Sum: '<S36>/Add2'
   */
  rtb_Switch1_c = rt_modd_snf(Robot_Control_U.Gyro_Angle_rad + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* RelationalOperator: '<S35>/GreaterThan' incorporates:
   *  Abs: '<S35>/Abs'
   *  Constant: '<S35>/Constant2'
   */
  rtb_Compare_a3 = (fabs(rtb_Switch1_c) > 1.5707963267948966);

  /* Logic: '<S35>/Logical Operator1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   */
  rtb_LogicalOperator1 = ((Robot_Control_U.Joystick_Left_B2) && rtb_Compare_a3);

  /* Logic: '<S35>/Logical Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B3'
   *  Inport: '<Root>/Joystick_Left_B4'
   */
  rtb_Compare_ir = ((Robot_Control_U.Joystick_Left_B3) ||
                    (Robot_Control_U.Joystick_Left_B4));

  /* RelationalOperator: '<S35>/GreaterThan1' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  rtb_Compare_lp = (rtb_Switch1_c > 0.0);

  /* Logic: '<S35>/Logical Operator5' incorporates:
   *  Logic: '<S35>/Logical Operator6'
   */
  rtb_LogicalOperator5 = (rtb_Compare_ir && (!rtb_Compare_lp));

  /* Logic: '<S35>/Logical Operator3' */
  rtb_Compare_lp = (rtb_Compare_ir && rtb_Compare_lp);

  /* Logic: '<S35>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   *  Logic: '<S35>/Logical Operator4'
   */
  rtb_LogicalOperator2 = ((Robot_Control_U.Joystick_Left_B2) && (!rtb_Compare_a3));

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

  /* If: '<S471>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S471>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S474>/Action Port'
     */
    /* Product: '<S474>/Product' incorporates:
     *  Constant: '<S474>/Constant1'
     *  Constant: '<S474>/Constant2'
     *  Math: '<S474>/Math Function'
     */
    rtb_Switch1_c = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S471>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S471>/Subsystem' incorporates:
     *  ActionPort: '<S475>/Action Port'
     */
    /* SignalConversion generated from: '<S475>/Out1' incorporates:
     *  Constant: '<S475>/Constant'
     */
    rtb_Switch1_c = 0.0;

    /* End of Outputs for SubSystem: '<S471>/Subsystem' */
  }

  /* End of If: '<S471>/If' */

  /* Gain: '<S472>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Subtract_c3 = 0.017453292519943295 *
    Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S473>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Switch1_c * cos
    (rtb_Subtract_c3)) + Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S473>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Switch1_c * sin
    (rtb_Subtract_c3)) + Vision_Object_Y_Offset;

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
  rtb_Minus_f_tmp = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Minus_f_tmp)) || (rtIsInf(rtb_Minus_f_tmp))) {
    rtb_Minus_f_tmp = 0.0;
  } else {
    rtb_Minus_f_tmp = fmod(rtb_Minus_f_tmp, 4.294967296E+9);
  }

  switch ((rtb_Minus_f_tmp < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Minus_f_tmp))))
          : ((int32_T)((uint32_T)rtb_Minus_f_tmp))) {
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
    rtb_Compare_ir = false;

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
    rtb_Compare_a3 = false;

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
    rtb_Shooter_Active_prev = false;

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
       *  UnitDelay: '<S19>/Unit Delay3'
       *  UnitDelay: '<S20>/Unit Delay'
       *  UnitDelay: '<S20>/Unit Delay1'
       *  UnitDelay: '<S22>/Unit Delay'
       *  UnitDelay: '<S29>/Delay Input1'
       *  UnitDelay: '<S30>/Delay Input1'
       *  UnitDelay: '<S31>/Delay Input1'
       *  UnitDelay: '<S34>/Delay Input1'
       *
       * Block description for '<S29>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S30>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S31>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S34>/Delay Input1':
       *
       *  Store in Global RAM
       */
      memset(&Robot_Control_DW.UnitDelay1_DSTATE_iz[0], 0, 60U * (sizeof(real_T)));
      Robot_Control_DW.UnitDelay1_DSTATE_k = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_kb = false;
      Robot_Control_DW.UnitDelay_DSTATE_b = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_h = false;
      Robot_Control_DW.UnitDelay2_DSTATE_d = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_or = false;
      Robot_Control_DW.UnitDelay3_DSTATE_i = 0.0;
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
      Robot_Control_B.Auto_Desired_Static_Action = 0.0;
      Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
      Robot_Control_B.Auto_Path_Counter = 0.0;
      Robot_Control_DW.counter = 0.0;
      Robot_Control_DW.is_active_c1_Robot_Control = 0U;
      Robot_Control_DW.is_c1_Robot_Control = Robot_Contro_IN_NO_ACTIVE_CHILD;

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
     *  Constant: '<S21>/Constant13'
     *  Constant: '<S21>/Constant17'
     *  Constant: '<S21>/Constant2'
     *  Constant: '<S21>/Constant3'
     *  Constant: '<S21>/Constant4'
     *  Constant: '<S21>/Constant5'
     *  Constant: '<S21>/Constant6'
     *  Constant: '<S21>/Constant7'
     *  Constant: '<S21>/Constant8'
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

     case 10:
      rtb_MultiportSwitch1[0] = 16;
      rtb_MultiportSwitch1[1] = 21;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 11:
      rtb_MultiportSwitch1[0] = 11;
      rtb_MultiportSwitch1[1] = 12;
      rtb_MultiportSwitch1[2] = 0;
      break;

     case 12:
      rtb_MultiportSwitch1[0] = 11;
      rtb_MultiportSwitch1[1] = 24;
      rtb_MultiportSwitch1[2] = 25;
      break;

     default:
      rtb_MultiportSwitch1[0] = 11;
      rtb_MultiportSwitch1[1] = 24;
      rtb_MultiportSwitch1[2] = 25;
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
    rtb_LogicalOperator1 = (Robot_Control_DW.UnitDelay1_DSTATE_k == 2.0);

    /* Switch: '<S19>/Switch1' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S19>/Constant2'
     *  RelationalOperator: '<S29>/FixPt Relational Operator'
     *  Sum: '<S19>/Sum'
     *  UnitDelay: '<S19>/Unit Delay'
     *  UnitDelay: '<S29>/Delay Input1'
     *
     * Block description for '<S29>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_LogicalOperator1) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_kb)) {
      rtb_Switch1_ac = 0.0;
    } else {
      rtb_Switch1_ac = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
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
     *  RelationalOperator: '<S30>/FixPt Relational Operator'
     *  Sum: '<S19>/Sum1'
     *  UnitDelay: '<S19>/Unit Delay2'
     *  UnitDelay: '<S30>/Delay Input1'
     *
     * Block description for '<S30>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_LogicalOperator5) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_h)) {
      rtb_Switch2_n = 0.0;
    } else {
      rtb_Switch2_n = Robot_Control_DW.UnitDelay2_DSTATE_d + 0.02;
    }

    /* End of Switch: '<S19>/Switch2' */

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     *  UnitDelay: '<S19>/Unit Delay1'
     */
    rtb_Compare_lp = (Robot_Control_DW.UnitDelay1_DSTATE_k == 5.0);

    /* Switch: '<S19>/Switch4' incorporates:
     *  Constant: '<S19>/Constant6'
     *  Constant: '<S19>/Constant7'
     *  RelationalOperator: '<S31>/FixPt Relational Operator'
     *  Sum: '<S19>/Sum2'
     *  UnitDelay: '<S19>/Unit Delay3'
     *  UnitDelay: '<S31>/Delay Input1'
     *
     * Block description for '<S31>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_lp) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_or)) {
      rtb_Switch4_fu = 0.0;
    } else {
      rtb_Switch4_fu = Robot_Control_DW.UnitDelay3_DSTATE_i + 0.02;
    }

    /* End of Switch: '<S19>/Switch4' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     *  Switch: '<S19>/Switch3'
     *  Switch: '<S19>/Switch5'
     *  Switch: '<S19>/Switch6'
     */
    if (rtb_LogicalOperator1) {
      rtb_Shooter_Active_prev = (rtb_Switch1_ac >= Auto_Shoot_Time);
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S19>/Switch3' incorporates:
       *  Constant: '<S26>/Constant'
       *  RelationalOperator: '<S26>/Compare'
       *  Switch: '<S19>/Switch6'
       */
      rtb_Shooter_Active_prev = (rtb_Switch2_n >= Auto_Deploy_Intake_Time);
    } else if (rtb_Compare_lp) {
      /* Switch: '<S19>/Switch5' incorporates:
       *  Constant: '<S28>/Constant'
       *  RelationalOperator: '<S28>/Compare'
       *  Switch: '<S19>/Switch6'
       */
      rtb_Shooter_Active_prev = (rtb_Switch4_fu >= Auto_Deploy_Intake_Time2);
    } else {
      /* Switch: '<S19>/Switch6' incorporates:
       *  Constant: '<S19>/Constant5'
       *  Switch: '<S19>/Switch5'
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
    if (Robot_Control_DW.is_active_c1_Robot_Control == 0) {
      Robot_Control_DW.is_active_c1_Robot_Control = 1U;
      Robot_Control_B.Auto_Path_Counter = 1.0;
      Robot_Control_DW.is_c1_Robot_Control = Robot_Control_IN_Start_Action;
      Robot_Control_B.Auto_Spline_Enable = false;
      Robot_Control_B.Auto_Desired_Static_Action =
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) + 39];
      Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
      Robot_Control_DW.counter = 0.0;
    } else {
      switch (Robot_Control_DW.is_c1_Robot_Control) {
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
          Robot_Control_DW.is_c1_Robot_Control = Robot_Control_IN_Start_Action;
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
          Robot_Control_DW.counter = 0.0;
        }
        break;

       case Robot_Control_IN_Follow_Path:
        Robot_Control_B.Auto_Spline_Enable = true;
        if (Robot_Control_DW.UnitDelay_DSTATE_ll) {
          Robot_Control_DW.is_c1_Robot_Control = Robot_Control_IN_End_Action;
          Robot_Control_B.Auto_Spline_Enable = false;
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        } else if (rtb_Subtract_c3 > Robot_Control_DW.UnitDelay_DSTATE_e3) {
          Robot_Control_DW.is_c1_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            49];
        }
        break;

       default:
        /* case IN_Start_Action: */
        Robot_Control_B.Auto_Spline_Enable = false;
        if ((Robot_Control_DW.counter > 1.0) &&
            ((Robot_Control_B.Auto_Desired_Static_Action == 0.0) ||
             rtb_Shooter_Active_prev)) {
          Robot_Control_DW.is_c1_Robot_Control = Robot_Control_IN_Follow_Path;
          Robot_Control_B.Auto_Spline_Enable = true;
          Robot_Control_B.Auto_Desired_Static_Action = 0.0;
          Robot_Control_B.Auto_Desired_Dynamic_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            49];
        } else {
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Subtract_c3) +
            39];
          Robot_Control_DW.counter++;
        }
        break;
      }
    }

    /* End of Chart: '<S20>/Chart' */

    /* Lookup_n-D: '<S20>/1-D Lookup Table1' */
    Robot_Control_B.Auto_Path_ID = rtb_MultiportSwitch1[plook_u32d_evencka
      (Robot_Control_B.Auto_Path_Counter, 1.0, 1.0, 2U)];

    /* Selector: '<S20>/Selector' */
    i = ((int32_T)Robot_Control_B.Auto_Path_ID) - 1;

    /* Switch: '<S20>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     */
    if (Robot_Control_U.IsBlueAlliance != 0.0) {
      /* Selector: '<S20>/Selector' incorporates:
       *  Constant: '<S20>/Constant'
       */
      memcpy(&rtb_Spline_Ref_Poses_h[0], &rtCP_Constant_Value_c[i * 60], 60U *
             (sizeof(real_T)));
    } else {
      /* Selector: '<S20>/Selector' incorporates:
       *  Constant: '<S20>/Constant1'
       */
      memcpy(&rtb_Spline_Ref_Poses_h[0], &rtCP_Constant1_Value_bc[i * 60], 60U *
             (sizeof(real_T)));
    }

    /* End of Switch: '<S20>/Switch' */

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
      (Robot_Control_B.Auto_Path_ID, 1.0, 1.0, 24U)];

    /* Merge: '<S9>/Merge7' incorporates:
     *  SignalConversion: '<S18>/Signal Copy'
     */
    Robot_Control_B.Spline_Enable = Robot_Control_B.Auto_Spline_Enable;

    /* Switch: '<S22>/Switch' */
    if (Robot_Control_B.Auto_Desired_Static_Action != 0.0) {
      rtb_Switch1_c = Robot_Control_B.Auto_Desired_Static_Action;
    } else {
      rtb_Switch1_c = Robot_Control_B.Auto_Desired_Dynamic_Action;
    }

    /* End of Switch: '<S22>/Switch' */

    /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
     *  Constant: '<S22>/Constant20'
     *  Constant: '<S22>/Constant21'
     *  Constant: '<S22>/Constant22'
     *  Constant: '<S22>/Constant23'
     *  Constant: '<S22>/Constant24'
     */
    switch ((int32_T)rtb_Switch1_c) {
     case 0:
      rtb_LogicalOperator2 = false;
      break;

     case 1:
      rtb_LogicalOperator2 = false;
      break;

     case 2:
      rtb_LogicalOperator2 = true;
      break;

     case 3:
      rtb_LogicalOperator2 = false;
      break;

     case 4:
      rtb_LogicalOperator2 = false;
      break;

     default:
      rtb_LogicalOperator2 = false;
      break;
    }

    /* End of MultiPortSwitch: '<S22>/Multiport Switch4' */

    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/Constant30'
     *  Constant: '<S22>/Constant31'
     *  RelationalOperator: '<S34>/FixPt Relational Operator'
     *  Sum: '<S22>/Sum'
     *  UnitDelay: '<S22>/Unit Delay'
     *  UnitDelay: '<S34>/Delay Input1'
     *
     * Block description for '<S34>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_LogicalOperator2) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_gf)) {
      rtb_Switch1_dt = 0.0;
    } else {
      rtb_Switch1_dt = Robot_Control_DW.UnitDelay_DSTATE_h + 0.02;
    }

    /* End of Switch: '<S22>/Switch1' */

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S33>/Constant'
     *  RelationalOperator: '<S33>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Switch1_dt >= Auto_Intake_Arm_Cycle_Delay_Time)
      && rtb_LogicalOperator2);

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     */
    switch ((int32_T)rtb_Switch1_c) {
     case 0:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant'
       *  Constant: '<S22>/Constant4'
       */
      rtb_Compare_a3 = false;

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
      rtb_Shooter_Active_prev = false;
      break;

     case 1:
      rtb_Button_Spinup_Enable = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant1'
       *  Constant: '<S22>/Constant5'
       */
      rtb_Compare_a3 = false;

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
      rtb_Shooter_Active_prev = false;
      break;

     case 2:
      rtb_Button_Spinup_Enable = true;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant2'
       *  Constant: '<S22>/Constant7'
       */
      rtb_Compare_a3 = true;

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
      rtb_Shooter_Active_prev = false;
      break;

     case 3:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant18'
       *  Constant: '<S22>/Constant6'
       */
      rtb_Compare_a3 = false;

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
      rtb_Shooter_Active_prev = true;
      break;

     case 4:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant3'
       *  Constant: '<S22>/Constant8'
       */
      rtb_Compare_a3 = false;

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
      rtb_Shooter_Active_prev = false;
      break;

     default:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant3'
       *  Constant: '<S22>/Constant8'
       */
      rtb_Compare_a3 = false;

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
      rtb_Shooter_Active_prev = false;
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
    rtb_Compare_ir = false;

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

    /* Update for UnitDelay: '<S29>/Delay Input1'
     *
     * Block description for '<S29>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_kb = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Switch1_ac;

    /* Update for UnitDelay: '<S30>/Delay Input1'
     *
     * Block description for '<S30>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_h = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S19>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_d = rtb_Switch2_n;

    /* Update for UnitDelay: '<S31>/Delay Input1'
     *
     * Block description for '<S31>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_or = rtb_Compare_lp;

    /* Update for UnitDelay: '<S19>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE_i = rtb_Switch4_fu;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S34>/Delay Input1'
     *
     * Block description for '<S34>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_gf = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S22>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_h = rtb_Switch1_dt;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S443>/Previous_Abs_Offset'
       *  UnitDelay: '<S443>/Unit Delay1'
       *  UnitDelay: '<S443>/Unit Delay2'
       *  UnitDelay: '<S443>/Unit Delay3'
       *  UnitDelay: '<S443>/Unit Delay4'
       *  UnitDelay: '<S447>/Delay Input1'
       *  UnitDelay: '<S448>/Delay Input1'
       *  UnitDelay: '<S449>/Delay Input1'
       *  UnitDelay: '<S450>/Delay Input1'
       *  UnitDelay: '<S452>/Delay Input1'
       *  UnitDelay: '<S458>/Unit Delay'
       *  UnitDelay: '<S458>/Unit Delay1'
       *  UnitDelay: '<S462>/FixPt Unit Delay1'
       *  UnitDelay: '<S462>/FixPt Unit Delay2'
       *
       * Block description for '<S447>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S448>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S449>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S450>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S452>/Delay Input1':
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
      Robot_Control_DW.UnitDelay1_DSTATE_l = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_p = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_j2 = 0.0;
      Robot_Control_DW.Previous_Abs_Offset_DSTATE = 0.0;
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

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Constant: '<S434>/Constant'
     *  Constant: '<S439>/Constant'
     *  Inport: '<Root>/Gamepad_LT'
     *  Inport: '<Root>/Joystick_Right_B1'
     *  RelationalOperator: '<S434>/Compare'
     *  RelationalOperator: '<S439>/Compare'
     */
    rtb_Shooter_Active_prev = ((Robot_Control_U.Joystick_Right_B1 != 0.0) ||
      (Robot_Control_U.Gamepad_LT != 0.0));

    /* Switch: '<S441>/Switch4' incorporates:
     *  Constant: '<S467>/Constant'
     *  Constant: '<S470>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S467>/Compare'
     *  RelationalOperator: '<S470>/Compare'
     *  Switch: '<S441>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S441>/Switch4' incorporates:
       *  Constant: '<S441>/Constant8'
       *  Sum: '<S441>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S441>/Switch5' incorporates:
       *  Constant: '<S441>/Constant7'
       *  Gain: '<S441>/Gain'
       *  Sum: '<S441>/Subtract5'
       *  Switch: '<S441>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S441>/Switch4' incorporates:
       *  Constant: '<S441>/Constant6'
       *  Switch: '<S441>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S441>/Switch4' */

    /* Logic: '<S441>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S441>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S443>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Minus_f_tmp = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Minus_f_tmp = 0.0;
    } else {
      rtb_Minus_f_tmp = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S443>/Add' incorporates:
     *  Constant: '<S443>/Constant'
     *  Constant: '<S443>/Constant1'
     *  DeadZone: '<S443>/Dead Zone'
     *  Lookup_n-D: '<S443>/Modulation_Str_Y_Rel'
     *  Product: '<S443>/Product'
     *  Product: '<S443>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Subtract_c3 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                       Steering_Relative_Gain) + (rtb_Minus_f_tmp *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S446>/Compare' incorporates:
     *  Constant: '<S446>/Constant'
     */
    rtb_Compare_cp = (rtb_Subtract_c3 == 0.0);

    /* Logic: '<S443>/AND2' incorporates:
     *  RelationalOperator: '<S447>/FixPt Relational Operator'
     *  RelationalOperator: '<S448>/FixPt Relational Operator'
     *  RelationalOperator: '<S449>/FixPt Relational Operator'
     *  RelationalOperator: '<S450>/FixPt Relational Operator'
     *  UnitDelay: '<S447>/Delay Input1'
     *  UnitDelay: '<S448>/Delay Input1'
     *  UnitDelay: '<S449>/Delay Input1'
     *  UnitDelay: '<S450>/Delay Input1'
     *
     * Block description for '<S447>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S448>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S449>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S450>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Intake_Arm_Move_In = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_Compare_lp) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S443>/AND1' incorporates:
     *  Logic: '<S443>/AND3'
     *  UnitDelay: '<S443>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_cp && (rtb_Intake_Arm_Move_In ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S443>/AND4' incorporates:
     *  Logic: '<S443>/AND8'
     *  UnitDelay: '<S443>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_cp && (!rtb_Intake_Arm_Move_In)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S443>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* Switch: '<S443>/Switch8' incorporates:
     *  Constant: '<S453>/Constant'
     *  Logic: '<S443>/AND9'
     *  RelationalOperator: '<S452>/FixPt Relational Operator'
     *  RelationalOperator: '<S453>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S452>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S452>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_cp) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_jp)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_DW.UnitDelay1_DSTATE_nl)) {
      /* Switch: '<S443>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S443>/Switch8' incorporates:
       *  UnitDelay: '<S443>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S443>/Switch8' */

    /* Switch: '<S443>/Switch2' */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S443>/Switch2' incorporates:
       *  Constant: '<S443>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;
    } else {
      /* Switch: '<S443>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;
    }

    /* End of Switch: '<S443>/Switch2' */

    /* DeadZone: '<S444>/Dead Zone' */
    if (rtb_Switch1_jy > Twist_Deadzone_pos) {
      rtb_Switch1_ac = rtb_Switch1_jy - Twist_Deadzone_pos;
    } else if (rtb_Switch1_jy >= Twist_Deadzone_neg) {
      rtb_Switch1_ac = 0.0;
    } else {
      rtb_Switch1_ac = rtb_Switch1_jy - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S444>/Dead Zone' */

    /* Lookup_n-D: '<S444>/Modulation_Drv' incorporates:
     *  Math: '<S444>/Magnitude'
     */
    rtb_Switch2_n = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_py),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S456>/Compare' incorporates:
     *  Constant: '<S456>/Constant'
     */
    rtb_Intake_Arm_Cycle = (rtb_Switch2_n == 0.0);

    /* Logic: '<S444>/Logical Operator' incorporates:
     *  Constant: '<S457>/Constant'
     *  RelationalOperator: '<S457>/Compare'
     */
    rtb_Intake_Arm_Move_In = ((rtb_Switch1_ac != 0.0) && rtb_Intake_Arm_Cycle);

    /* Switch: '<S441>/Switch2' incorporates:
     *  Constant: '<S441>/Constant2'
     *  Constant: '<S466>/Constant'
     *  Constant: '<S469>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S466>/Compare'
     *  RelationalOperator: '<S469>/Compare'
     *  Sum: '<S441>/Subtract'
     *  Switch: '<S441>/Switch'
     *  Switch: '<S441>/Switch1'
     *  Switch: '<S441>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S441>/Switch2' incorporates:
       *  Constant: '<S441>/Constant5'
       *  Sum: '<S441>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Init = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S441>/Switch2' incorporates:
       *  Constant: '<S441>/Constant4'
       *  Sum: '<S441>/Subtract2'
       *  Switch: '<S441>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S441>/Switch1' incorporates:
       *  Constant: '<S441>/Constant1'
       *  Sum: '<S441>/Subtract3'
       */
      rtb_Init = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S441>/Switch2' incorporates:
       *  Constant: '<S441>/Constant3'
       *  Switch: '<S441>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S441>/Switch1' incorporates:
       *  Constant: '<S441>/Constant'
       */
      rtb_Init = 0.0;
    }

    /* End of Switch: '<S441>/Switch2' */

    /* UnaryMinus: '<S441>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Init;

    /* Switch: '<S458>/Switch1' incorporates:
     *  Constant: '<S463>/Constant'
     *  Constant: '<S464>/Constant'
     *  Logic: '<S458>/AND'
     *  RelationalOperator: '<S463>/Compare'
     *  RelationalOperator: '<S464>/Compare'
     *  Switch: '<S458>/Switch2'
     *  UnitDelay: '<S458>/Unit Delay'
     *  UnitDelay: '<S458>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_py == 0.0)) {
      rtb_Switch4_fu = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch1_c = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch4_fu = rtb_Switch1_py;
      rtb_Switch1_c = rtb_Sum1;
    }

    /* End of Switch: '<S458>/Switch1' */

    /* Switch: '<S444>/Switch1' incorporates:
     *  Gain: '<S444>/Gain3'
     *  Logic: '<S444>/Logical Operator1'
     *  Signum: '<S444>/Sign'
     *  Sum: '<S444>/Add'
     *  Switch: '<S444>/Switch4'
     *  Switch: '<S444>/Switch5'
     *  Switch: '<S444>/Switch9'
     */
    if (rtb_Intake_Arm_Move_In) {
      /* Signum: '<S444>/Sign' */
      if (rtIsNaN(rtb_Switch1_ac)) {
        rtb_Minus_f_tmp = (rtNaN);
      } else if (rtb_Switch1_ac < 0.0) {
        rtb_Minus_f_tmp = -1.0;
      } else {
        rtb_Minus_f_tmp = (rtb_Switch1_ac > 0.0);
      }

      /* Switch: '<S444>/Switch5' incorporates:
       *  Constant: '<S444>/Constant3'
       *  Constant: '<S444>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_ir = -1.5707963267948966;
      } else {
        rtb_Add_ir = 0.0;
      }

      rtb_Init = (3.141592653589793 * rtb_Minus_f_tmp) + rtb_Add_ir;
    } else if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S444>/Switch6' incorporates:
       *  Constant: '<S444>/Constant'
       *  Constant: '<S444>/Constant1'
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S444>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        rtb_Init = 0.0;
      } else {
        rtb_Init = 3.141592653589793;
      }

      /* End of Switch: '<S444>/Switch6' */
    } else {
      /* Switch: '<S444>/Switch4' incorporates:
       *  Trigonometry: '<S444>/Atan2'
       */
      rtb_Init = rt_atan2d_snf(rtb_Switch4_fu, rtb_Switch1_c);
    }

    /* End of Switch: '<S444>/Switch1' */

    /* RelationalOperator: '<S445>/Compare' incorporates:
     *  Constant: '<S445>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* Switch: '<S443>/Switch4' incorporates:
     *  Constant: '<S443>/Constant5'
     *  Switch: '<S443>/Switch1'
     *  Switch: '<S443>/Switch5'
     *  Switch: '<S443>/Switch6'
     *  Switch: '<S443>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Switch1_dt = 0.0;
    } else if (rtb_Compare_lp) {
      /* Switch: '<S443>/Switch5' incorporates:
       *  Constant: '<S443>/Constant6'
       */
      rtb_Switch1_dt = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S443>/Switch6' incorporates:
       *  Constant: '<S443>/Constant7'
       *  Switch: '<S443>/Switch5'
       */
      rtb_Switch1_dt = 3.141592653589793;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S443>/Switch7' incorporates:
       *  Constant: '<S443>/Constant8'
       *  Switch: '<S443>/Switch5'
       *  Switch: '<S443>/Switch6'
       */
      rtb_Switch1_dt = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S443>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S443>/Switch5'
       *  Switch: '<S443>/Switch6'
       *  Switch: '<S443>/Switch7'
       */
      rtb_Switch1_dt = 0.0;
    } else {
      /* Switch: '<S443>/Switch6' incorporates:
       *  Switch: '<S443>/Switch5'
       *  Switch: '<S443>/Switch7'
       *  UnitDelay: '<S443>/Unit Delay1'
       */
      rtb_Switch1_dt = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S443>/Switch4' */

    /* Switch: '<S443>/Switch11' incorporates:
     *  UnitDelay: '<S443>/Previous_Abs_Offset'
     */
    if (rtb_Button_Spinup_Enable) {
      rtb_Switch11 = rtb_Init;
    } else {
      rtb_Switch11 = Robot_Control_DW.Previous_Abs_Offset_DSTATE;
    }

    /* End of Switch: '<S443>/Switch11' */

    /* Switch: '<S443>/Switch3' */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S443>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Switch1_dt;
    } else {
      /* Switch: '<S443>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Switch11;
    }

    /* End of Switch: '<S443>/Switch3' */

    /* Switch: '<S443>/Switch9' */
    if (rtb_Button_Spinup_Enable) {
      rtb_Minus_f_tmp = rtb_Init;
    } else {
      rtb_Minus_f_tmp = Robot_Control_B.Steering_Abs_Angle;
    }

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S443>/Add1'
     *  Switch: '<S443>/Switch9'
     */
    Robot_Control_B.Steering_Abs_Cmd = rtb_Minus_f_tmp +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S442>/Switch1' incorporates:
     *  Constant: '<S442>/Constant5'
     *  Constant: '<S442>/Constant7'
     *  Constant: '<S442>/Constant8'
     *  DataTypeConversion: '<S442>/Data Type Conversion'
     *  DataTypeConversion: '<S442>/Data Type Conversion1'
     *  Logic: '<S444>/Logical Operator1'
     *  Switch: '<S442>/Switch'
     *  Switch: '<S443>/Switch10'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
      rtb_Compare_ir = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Steering = (rtb_Button_Spinup_Enable || rtb_Compare_cp);
      rtb_Compare_ir = !rtb_Intake_Arm_Move_In;
    }

    /* End of Switch: '<S442>/Switch1' */

    /* Merge: '<S9>/Merge3' incorporates:
     *  SignalConversion generated from: '<S15>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = rtb_Init;

    /* Switch: '<S455>/Switch1' incorporates:
     *  Constant: '<S455>/Constant'
     *  Constant: '<S455>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_ks = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_ks = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S455>/Switch1' */

    /* Switch: '<S462>/Init' incorporates:
     *  UnitDelay: '<S462>/FixPt Unit Delay1'
     *  UnitDelay: '<S462>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_ks;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S462>/Init' */

    /* Sum: '<S460>/Sum1' */
    rtb_Switch2_ks -= rtb_Init;

    /* Switch: '<S461>/Switch2' incorporates:
     *  Constant: '<S459>/Constant1'
     *  Constant: '<S459>/Constant3'
     *  RelationalOperator: '<S461>/LowerRelop1'
     *  RelationalOperator: '<S461>/UpperRelop'
     *  Switch: '<S461>/Switch'
     */
    if (rtb_Switch2_ks > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_ks = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_ks < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S461>/Switch' incorporates:
       *  Constant: '<S459>/Constant1'
       */
      rtb_Switch2_ks = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S461>/Switch2' */

    /* Sum: '<S460>/Sum' */
    rtb_Init += rtb_Switch2_ks;

    /* Switch: '<S444>/Switch8' incorporates:
     *  Logic: '<S444>/Logical Operator1'
     *  Switch: '<S444>/Switch2'
     */
    if (rtb_Intake_Arm_Move_In) {
      /* Switch: '<S444>/Switch' incorporates:
       *  Gain: '<S444>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain *
        rtb_Switch1_ac;
    } else if (rtb_Intake_Arm_Cycle) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S444>/Constant5'
       *  Gain: '<S444>/Gain2'
       *  Math: '<S444>/Magnitude1'
       *  MinMax: '<S444>/Min'
       *  Switch: '<S444>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S455>/Product' incorporates:
       *  Switch: '<S444>/Switch2'
       */
      rtb_Add_di = rtb_Switch2_n * rtb_Init;

      /* Saturate: '<S455>/Saturation' incorporates:
       *  Switch: '<S444>/Switch2'
       */
      if (rtb_Add_di > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_di < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_di;
      }

      /* End of Saturate: '<S455>/Saturation' */
    }

    /* End of Switch: '<S444>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S443>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Subtract_c3;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S441>/Constant11'
     *  Switch: '<S441>/Switch6'
     *  Switch: '<S441>/Switch7'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = TEST_Pipeline;

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

    /* RelationalOperator: '<S437>/Compare' incorporates:
     *  Constant: '<S437>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S438>/Compare' incorporates:
     *  Constant: '<S438>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Compare_a3 = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S433>/Compare' incorporates:
     *  Constant: '<S433>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S436>/Compare' incorporates:
     *  Constant: '<S436>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S435>/Compare' incorporates:
     *  Constant: '<S435>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     *  SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Update for UnitDelay: '<S452>/Delay Input1'
     *
     * Block description for '<S452>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_jp = rtb_Compare_cp;

    /* Update for UnitDelay: '<S451>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S451>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S447>/Delay Input1'
     *
     * Block description for '<S447>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S448>/Delay Input1'
     *
     * Block description for '<S448>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_Compare_lp;

    /* Update for UnitDelay: '<S449>/Delay Input1'
     *
     * Block description for '<S449>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S450>/Delay Input1'
     *
     * Block description for '<S450>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S443>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S443>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S443>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S458>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch4_fu;

    /* Update for UnitDelay: '<S458>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch1_c;

    /* Update for UnitDelay: '<S443>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Switch1_dt;

    /* Update for UnitDelay: '<S443>/Previous_Abs_Offset' */
    Robot_Control_DW.Previous_Abs_Offset_DSTATE = rtb_Switch11;

    /* Update for UnitDelay: '<S462>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S462>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S462>/FixPt Unit Delay1' */
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
    rtb_Compare_ir = false;

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

    /* SignalConversion generated from: '<S16>/Button_Spinup_Enable' incorporates:
     *  Constant: '<S16>/Constant11'
     */
    rtb_Button_Spinup_Enable = false;

    /* SignalConversion generated from: '<S16>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S16>/Constant15'
     */
    rtb_Compare_a3 = false;

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
    rtb_Shooter_Active_prev = false;

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

  /* Reshape: '<S80>/Reshape3' incorporates:
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_X'
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_Y'
   *  S-Function (sfix_udelay): '<S8>/Tapped Delay'
   *  S-Function (sfix_udelay): '<S8>/Tapped Delay1'
   *  Sum: '<S8>/Add'
   *  Sum: '<S8>/Add1'
   */
  rtb_Reshape3[0] = (Robot_Control_U.Vision_RobotPoseFieldSpace_X +
                     Robot_Control_DW.TappedDelay_X[0]) +
    Robot_Control_DW.TappedDelay_X[1];
  rtb_Reshape3[1] = (Robot_Control_U.Vision_RobotPoseFieldSpace_Y +
                     Robot_Control_DW.TappedDelay1_X[0]) +
    Robot_Control_DW.TappedDelay1_X[1];

  /* Delay: '<S133>/Delay' incorporates:
   *  Constant: '<S80>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.Delay_DSTATE[0] = 0.0;
    Robot_Control_DW.Delay_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S115>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S116>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S132>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S134>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S134>/Sum' incorporates:
     *  Constant: '<S80>/C'
     *  Delay: '<S133>/Delay'
     *  Product: '<S134>/C[k]*xhat[k|k-1]'
     *  Reshape: '<S80>/Reshape3'
     *  Sum: '<S134>/Add1'
     */
    rtb_Switch1_ac = rtb_Reshape3[0] - ((0.0 * Robot_Control_DW.Delay_DSTATE[1])
      + Robot_Control_DW.Delay_DSTATE[0]);
    rtb_Switch2_n = rtb_Reshape3[1] - ((0.0 * Robot_Control_DW.Delay_DSTATE[0])
      + Robot_Control_DW.Delay_DSTATE[1]);

    /* Product: '<S134>/Product3' incorporates:
     *  Constant: '<S128>/Constant'
     *  Product: '<S116>/Product2'
     */
    rtb_Switch1_c = 0.09512492197250398 * rtb_Switch1_ac;
    Robot_Control_B.Product3[0] = rtb_Switch1_c;
    Robot_Control_B.Product3[1] = 6.209845451961181E-17 * rtb_Switch1_ac;
    Robot_Control_B.Product3[0] += -2.039980794561786E-17 * rtb_Switch2_n;
    Robot_Control_B.Product3[1] += 0.09512492197250423 * rtb_Switch2_n;

    /* Product: '<S116>/Product2' incorporates:
     *  Constant: '<S128>/Constant1'
     *  Sum: '<S116>/Add1'
     */
    Robot_Control_B.Product2[0] = rtb_Switch1_c;
    Robot_Control_B.Product2[1] = 2.580507006221294E-17 * rtb_Switch1_ac;
    Robot_Control_B.Product2[0] += 2.5805070062212937E-17 * rtb_Switch2_n;
    Robot_Control_B.Product2[1] += 0.09512492197250424 * rtb_Switch2_n;
  } else if (Robot_Control_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S134>/Product3' incorporates:
     *  Outport: '<S134>/L*(y[k]-yhat[k|k-1])'
     */
    Robot_Control_B.Product3[0] = 0.0;
    Robot_Control_B.Product3[1] = 0.0;
    Robot_Control_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S132>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S115>/Enabled Subsystem' */

  /* Sum: '<S115>/Add' incorporates:
   *  Delay: '<S133>/Delay'
   *  Product: '<S116>/Product2'
   */
  rtb_Reshape3[0] = Robot_Control_B.Product2[0] + Robot_Control_DW.Delay_DSTATE
    [0];
  rtb_Reshape3[1] = Robot_Control_B.Product2[1] + Robot_Control_DW.Delay_DSTATE
    [1];

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Switch: '<S8>/Switch1'
   */
  if (KF_Enable != 0.0) {
    /* Switch: '<S8>/Switch' */
    Robot_Control_B.KF_Position_X = rtb_Reshape3[0];

    /* Switch: '<S8>/Switch1' */
    Robot_Control_B.KF_Position_Y = rtb_Reshape3[1];
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
   *  Constant: '<S273>/Constant'
   *  Logic: '<S273>/AND'
   *  MATLAB Function: '<S223>/Find closest index to curve'
   *  Product: '<S273>/Product'
   *  RelationalOperator: '<S273>/Relational Operator'
   *  RelationalOperator: '<S273>/Relational Operator1'
   *  Selector: '<S273>/Selector'
   *  Selector: '<S273>/Selector1'
   *  Selector: '<S274>/Selector'
   *  Sum: '<S273>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S226>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S229>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S231>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S226>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S221>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S221>/Unit Delay'
       *  UnitDelay: '<S222>/Unit Delay'
       *  UnitDelay: '<S224>/Unit Delay'
       *  UnitDelay: '<S224>/Unit Delay1'
       *  UnitDelay: '<S274>/Unit Delay'
       *  UnitDelay: '<S274>/Unit Delay1'
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
     *  ActionPort: '<S221>/Action Port'
     */
    /* Selector: '<S222>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    memcpy(&rtb_Ref_Poses[0], &rtb_Spline_Ref_Poses_h[0], 10U * (sizeof(real_T)));
    memcpy(&rtb_Ref_Poses[10], &rtb_Spline_Ref_Poses_h[10], 10U * (sizeof(real_T)));

    /* Lookup_n-D: '<S221>/Capture Radius' incorporates:
     *  UnitDelay: '<S221>/Unit Delay'
     */
    rtb_Subtract_c3 = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S222>/Matrix Concatenate2' */
    rtb_Reshape3[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S222>/Matrix Concatenate2' */
    rtb_Reshape3[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S226>/If' incorporates:
     *  RelationalOperator: '<S226>/ '
     *  UnitDelay: '<S222>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S229>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S231>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S226>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S229>/Action Port'
       */
      /* InitializeConditions for If: '<S226>/If' incorporates:
       *  UnitDelay: '<S229>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S226>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S226>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S229>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S229>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S232>/Action Port'
       */
      /* If: '<S229>/If' incorporates:
       *  Selector: '<S222>/Selector1'
       *  Selector: '<S229>/Selector'
       *  Selector: '<S232>/Selector'
       */
      rtb_Switch1_dt = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S229>/Increment_If_Rectangle_Check' */

      /* Sum: '<S229>/Minus' incorporates:
       *  Concatenate: '<S222>/Matrix Concatenate2'
       *  Selector: '<S229>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshape3[0] - rtb_Switch1_dt;

      /* Outputs for IfAction SubSystem: '<S229>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S232>/Action Port'
       */
      /* If: '<S229>/If' incorporates:
       *  Selector: '<S222>/Selector1'
       *  Selector: '<S229>/Selector'
       *  Selector: '<S232>/Selector'
       *  Sum: '<S229>/Minus'
       */
      rtb_Switch1_c = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S229>/Increment_If_Rectangle_Check' */

      /* Sum: '<S229>/Minus' incorporates:
       *  Concatenate: '<S222>/Matrix Concatenate2'
       *  Selector: '<S229>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshape3[1] - rtb_Switch1_c;

      /* Math: '<S229>/Hypot' */
      rtb_Switch1_ac = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S229>/Equal' */
      rtb_LogicalOperator1 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S229>/Switch' incorporates:
       *  Logic: '<S229>/AND'
       *  Logic: '<S229>/OR'
       *  RelationalOperator: '<S229>/Relational Operator'
       *  UnitDelay: '<S229>/Unit Delay'
       */
      rtb_LogicalOperator5 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Switch1_ac <= rtb_Subtract_c3) && rtb_LogicalOperator1));

      /* If: '<S229>/If' */
      rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_o;
      if (!rtb_LogicalOperator5) {
        if (!rtb_LogicalOperator1) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Robot_Control_DW.If_ActiveSubsystem_o = rtAction;
      if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
        /* Disable for If: '<S231>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S229>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S231>/Action Port'
         */
        /* If: '<S231>/If' incorporates:
         *  RelationalOperator: '<S231>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S231>/Is_Last_Point' incorporates:
           *  ActionPort: '<S234>/Action Port'
           */
          /* InitializeConditions for If: '<S231>/If' incorporates:
           *  UnitDelay: '<S234>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S231>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S231>/Is_Last_Point' incorporates:
           *  ActionPort: '<S234>/Action Port'
           */
          /* Switch: '<S234>/Switch' incorporates:
           *  Constant: '<S236>/Constant'
           *  Logic: '<S234>/OR'
           *  RelationalOperator: '<S236>/Compare'
           *  UnitDelay: '<S234>/Unit Delay'
           */
          rtb_Compare_ir = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
                            (rtb_Switch1_ac <= Spline_Stop_Radius));

          /* If: '<S234>/If' */
          if (rtb_Compare_ir) {
            /* Outputs for IfAction SubSystem: '<S234>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S237>/Action Port'
             */
            /* Merge: '<S226>/Merge2' incorporates:
             *  Constant: '<S237>/Constant'
             *  SignalConversion generated from: '<S237>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator1 = true;

            /* SignalConversion generated from: '<S237>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S237>/Constant1'
             */
            rtb_Compare_lp = false;

            /* End of Outputs for SubSystem: '<S234>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S234>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S238>/Action Port'
             */
            /* Merge: '<S226>/Merge2' incorporates:
             *  Constant: '<S238>/Constant'
             *  SignalConversion generated from: '<S238>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator1 = false;

            /* SignalConversion generated from: '<S238>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S238>/Constant1'
             */
            rtb_Compare_lp = true;

            /* End of Outputs for SubSystem: '<S234>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S234>/If' */

          /* Merge: '<S226>/Merge4' incorporates:
           *  SignalConversion: '<S234>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S234>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Compare_ir;

          /* End of Outputs for SubSystem: '<S231>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S231>/Increment_Search' incorporates:
           *  ActionPort: '<S233>/Action Port'
           */
          /* Merge: '<S226>/Merge2' incorporates:
           *  Constant: '<S233>/Constant'
           *  SignalConversion generated from: '<S233>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator1 = false;

          /* SignalConversion generated from: '<S233>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S233>/Constant1'
           */
          rtb_Compare_lp = false;

          /* Merge: '<S226>/Merge4' incorporates:
           *  Constant: '<S235>/FixPt Constant'
           *  SignalConversion: '<S233>/Signal Copy'
           *  Sum: '<S235>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S231>/Increment_Search' */
        }

        /* End of If: '<S231>/If' */
        /* End of Outputs for SubSystem: '<S229>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S229>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S232>/Action Port'
         */
        /* Sum: '<S239>/FixPt Sum1' incorporates:
         *  Constant: '<S239>/FixPt Constant'
         */
        rtb_Switch2_n = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S232>/Selector1' incorporates:
         *  Selector: '<S222>/Selector1'
         */
        rtb_Minus_f_tmp = rtb_Ref_Poses[((int32_T)rtb_Switch2_n) - 1];

        /* Sum: '<S240>/Subtract' incorporates:
         *  Selector: '<S232>/Selector1'
         *  Sum: '<S240>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Minus_f_tmp - rtb_Switch1_dt;

        /* Selector: '<S232>/Selector1' incorporates:
         *  Selector: '<S222>/Selector1'
         */
        rtb_Switch11 = rtb_Ref_Poses[((int32_T)rtb_Switch2_n) + 9];

        /* Sum: '<S240>/Subtract' incorporates:
         *  Selector: '<S232>/Selector1'
         *  Sum: '<S240>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch11 - rtb_Switch1_c;

        /* Math: '<S240>/Hypot' */
        rtb_Switch1_ac = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S240>/Divide' */
        rtb_Switch2_n = rtb_Minus_n[1];

        /* UnaryMinus: '<S240>/Unary Minus' */
        rtb_Switch4_fu = rtb_Minus_n[0];

        /* Product: '<S240>/Product' incorporates:
         *  Product: '<S240>/Divide'
         *  UnaryMinus: '<S240>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch2_n / rtb_Switch1_ac) * rtb_Subtract_c3;
        rtb_Minus_n[1] = ((-rtb_Switch4_fu) / rtb_Switch1_ac) * rtb_Subtract_c3;

        /* Sum: '<S240>/Add1' incorporates:
         *  Sum: '<S240>/Add2'
         *  Sum: '<S240>/Minus'
         */
        rtb_Switch4_fu = rtb_Minus_f_tmp - rtb_Minus_n[0];

        /* Sum: '<S240>/Minus4' incorporates:
         *  Sum: '<S240>/Add2'
         *  Sum: '<S240>/Minus'
         */
        rtb_Minus_f_tmp = (rtb_Minus_f_tmp + rtb_Minus_n[0]) - rtb_Switch4_fu;

        /* Sum: '<S240>/Minus5' incorporates:
         *  Concatenate: '<S222>/Matrix Concatenate2'
         *  Sum: '<S240>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshape3[0] - rtb_Switch4_fu;

        /* Sum: '<S240>/Add' incorporates:
         *  Sum: '<S240>/Add2'
         *  Sum: '<S240>/Minus1'
         */
        rtb_Switch2_n = rtb_Switch1_dt - rtb_Minus_n[0];

        /* Sum: '<S240>/Minus' incorporates:
         *  Sum: '<S240>/Minus1'
         */
        rtb_Switch4_fu -= rtb_Switch2_n;

        /* DotProduct: '<S240>/Dot Product' incorporates:
         *  Concatenate: '<S222>/Matrix Concatenate2'
         *  Sum: '<S240>/Minus'
         *  Sum: '<S240>/Minus1'
         *  Sum: '<S240>/Minus5'
         */
        rtb_Switch1_ac = (rtb_Reshape3[0] - rtb_Switch2_n) * rtb_Switch4_fu;

        /* Sum: '<S240>/Add1' incorporates:
         *  Sum: '<S240>/Add2'
         *  Sum: '<S240>/Minus'
         */
        rtb_Switch1_dt = rtb_Switch11 - rtb_Minus_n[1];

        /* Sum: '<S240>/Minus4' incorporates:
         *  Sum: '<S240>/Add2'
         *  Sum: '<S240>/Minus'
         */
        rtb_Switch11 = (rtb_Switch11 + rtb_Minus_n[1]) - rtb_Switch1_dt;

        /* Sum: '<S240>/Add' incorporates:
         *  Sum: '<S240>/Add2'
         *  Sum: '<S240>/Minus1'
         */
        rtb_Switch2_n = rtb_Switch1_c - rtb_Minus_n[1];

        /* Sum: '<S240>/Minus' incorporates:
         *  Sum: '<S240>/Minus1'
         */
        rtb_Switch1_c = rtb_Switch1_dt - rtb_Switch2_n;

        /* DotProduct: '<S240>/Dot Product' incorporates:
         *  Concatenate: '<S222>/Matrix Concatenate2'
         *  Sum: '<S240>/Minus'
         *  Sum: '<S240>/Minus1'
         *  Sum: '<S240>/Minus5'
         */
        rtb_Switch1_ac += (rtb_Reshape3[1] - rtb_Switch2_n) * rtb_Switch1_c;

        /* DotProduct: '<S240>/Dot Product2' incorporates:
         *  Concatenate: '<S222>/Matrix Concatenate2'
         *  Sum: '<S240>/Minus'
         *  Sum: '<S240>/Minus4'
         *  Sum: '<S240>/Minus5'
         */
        rtb_Switch2_n = ((rtb_Reshape3[1] - rtb_Switch1_dt) * rtb_Switch11) +
          (rtb_Minus_f_tmp * rtb_MatrixConcatenate_b_idx_0);

        /* Merge: '<S226>/Merge4' incorporates:
         *  Constant: '<S241>/Constant'
         *  Constant: '<S242>/Constant'
         *  DataTypeConversion: '<S232>/Data Type Conversion'
         *  DotProduct: '<S240>/Dot Product1'
         *  DotProduct: '<S240>/Dot Product3'
         *  Logic: '<S240>/AND'
         *  RelationalOperator: '<S240>/LessThanOrEqual'
         *  RelationalOperator: '<S240>/LessThanOrEqual1'
         *  RelationalOperator: '<S241>/Compare'
         *  RelationalOperator: '<S242>/Compare'
         *  Sum: '<S232>/Add'
         *  Sum: '<S240>/Minus'
         *  Sum: '<S240>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)((((rtb_Switch1_ac >= 0.0)
          && (rtb_Switch1_ac <= ((rtb_Switch1_c * rtb_Switch1_c) +
          (rtb_Switch4_fu * rtb_Switch4_fu)))) && (rtb_Switch2_n >= 0.0)) &&
          (rtb_Switch2_n <= ((rtb_Minus_f_tmp * rtb_Minus_f_tmp) + (rtb_Switch11
          * rtb_Switch11))))) + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S226>/Merge2' incorporates:
         *  Constant: '<S232>/Constant2'
         *  SignalConversion generated from: '<S232>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator1 = false;

        /* SignalConversion generated from: '<S232>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S232>/Constant1'
         */
        rtb_Compare_lp = false;

        /* End of Outputs for SubSystem: '<S229>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S229>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S230>/Action Port'
         */
        /* Merge: '<S226>/Merge2' incorporates:
         *  Constant: '<S230>/Constant2'
         *  SignalConversion generated from: '<S230>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator1 = false;

        /* SignalConversion generated from: '<S230>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S230>/Constant1'
         */
        rtb_Compare_lp = false;

        /* Merge: '<S226>/Merge4' incorporates:
         *  SignalConversion generated from: '<S230>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S229>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S226>/Merge1' incorporates:
       *  Constant: '<S229>/Constant'
       *  SignalConversion generated from: '<S229>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S229>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator5;

      /* End of Outputs for SubSystem: '<S226>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S226>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S228>/Action Port'
       */
      /* Merge: '<S226>/Merge1' incorporates:
       *  Constant: '<S228>/Constant'
       *  SignalConversion generated from: '<S228>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S226>/Merge2' incorporates:
       *  Constant: '<S228>/Constant1'
       *  SignalConversion generated from: '<S228>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator1 = false;

      /* SignalConversion generated from: '<S228>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S228>/Constant2'
       */
      rtb_Compare_lp = false;

      /* Merge: '<S226>/Merge4' incorporates:
       *  SignalConversion generated from: '<S228>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S226>/Escape_Auto_Driving' */
    }

    /* End of If: '<S226>/If' */

    /* If: '<S222>/If1' */
    if (!rtb_Compare_lp) {
      /* Outputs for IfAction SubSystem: '<S222>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S227>/Action Port'
       */
      /* Bias: '<S243>/Add Constant' incorporates:
       *  Bias: '<S243>/Bias'
       *  Sum: '<S243>/Subtract'
       */
      rtb_Switch1_ac = ((Robot_Control_B.Spline_Num_Poses -
                         Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S243>/Selector4' incorporates:
       *  Bias: '<S243>/Bias1'
       *  Constant: '<S245>/FixPt Constant'
       *  Sum: '<S245>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S243>/Selector5' */
      rtb_Reshape3[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S243>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshape3[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s248_iter = ((int32_T)rtb_Reshape3[1]) - 1;

      /* Concatenate: '<S243>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S243>/Selector5' incorporates:
       *  Concatenate: '<S243>/Matrix Concatenate'
       *  Gain: '<S247>/Gain'
       *  Selector: '<S222>/Selector1'
       *  Selector: '<S243>/Selector2'
       *  Selector: '<S243>/Selector3'
       *  Sum: '<S247>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s248_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S243>/Matrix Concatenate' incorporates:
       *  Bias: '<S243>/Add Constant1'
       *  Gain: '<S246>/Gain'
       *  Selector: '<S222>/Selector1'
       *  Selector: '<S243>/Selector'
       *  Selector: '<S243>/Selector1'
       *  Selector: '<S243>/Selector5'
       *  Sum: '<S246>/Subtract'
       */
      s248_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s248_iter;
             rtb_Num_Segments++) {
          rtb_MatrixConcatenate_p[(rtb_Num_Segments +
            (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) + 1] =
            rtb_Selector5[(Robot_Control_DW.Selector5_DIMS1[0] * i) +
            rtb_Num_Segments];
        }
      }

      rtb_MatrixConcatenate_p[Robot_Control_DW.Selector5_DIMS1[0] + 1] =
        (rtb_Ref_Poses[((int32_T)rtb_Reshape3[1]) - 1] * 2.0) - rtb_Ref_Poses
        [((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) - 1];
      rtb_MatrixConcatenate_p[(Robot_Control_DW.Selector5_DIMS1[0] +
        Robot_Control_DW.MatrixConcatenate_DIMS1[0]) + 1] = (rtb_Ref_Poses
        [((int32_T)Robot_Control_B.Spline_Num_Poses) + 9] * 2.0) -
        rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) + 9];

      /* Selector: '<S243>/Selector4' */
      s248_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s248_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S243>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S243>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S243>/Assignment' incorporates:
       *  Concatenate: '<S243>/Matrix Concatenate'
       *  Selector: '<S243>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s248_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S244>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S248>/While Iterator'
       */
      s248_iter = 1;
      do {
        rtb_Switch1_dt = rtb_Assignment[s248_iter + 1];
        rtb_Minus_n[0] = rtb_Switch1_dt - rtb_Assignment[s248_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s248_iter] - rtb_Assignment[s248_iter + 2];
        rtb_Init = rtb_Switch1_dt - rtb_Assignment[s248_iter];
        rtb_Switch1_dt = rtb_Assignment[s248_iter + 13];
        rtb_Minus_n[1] = rtb_Switch1_dt - rtb_Assignment[s248_iter + 11];
        rtb_Minus_f_tmp = rtb_Assignment[s248_iter + 12];
        rtb_Add2[1] = rtb_Minus_f_tmp - rtb_Assignment[s248_iter + 14];
        rtb_Switch2_ks = rtb_Switch1_dt - rtb_Minus_f_tmp;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Switch2_n = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Switch4_fu = rt_powd_snf(rtb_Switch2_n, 2.0);
          rtb_Switch11 = rt_powd_snf(rtb_Switch2_n, 3.0);
          rtb_Switch1_c = (rtb_Switch2_n - (2.0 * rtb_Switch4_fu)) +
            rtb_Switch11;
          rtb_Switch1_dt = rtb_Switch4_fu - rtb_Switch11;
          rtb_Add_ir = 3.0 * rtb_Switch4_fu;
          rtb_Switch11 = rtb_Add_ir - (2.0 * rtb_Switch11);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch1_c) +
            (rtb_Add2[0] * rtb_Switch1_dt)) * 0.5) + (rtb_Init * rtb_Switch11))
            + rtb_Assignment[s248_iter];
          rtb_Switch11 = ((((rtb_Minus_n[1] * rtb_Switch1_c) + (rtb_Add2[1] *
            rtb_Switch1_dt)) * 0.5) + (rtb_Switch2_ks * rtb_Switch11)) +
            rtb_Minus_f_tmp;
          rtb_Switch1_c = (rtb_Add_ir - (4.0 * rtb_Switch2_n)) + 1.0;
          rtb_Switch1_dt = (2.0 * rtb_Switch2_n) - rtb_Add_ir;
          rtb_Switch4_fu = (rtb_Switch2_n - rtb_Switch4_fu) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch1_c) +
            (rtb_Add2[0] * rtb_Switch1_dt)) * 0.5) + (rtb_Init * rtb_Switch4_fu);
          rtb_Add_ir = (((rtb_Minus_n[1] * rtb_Switch1_c) + (rtb_Add2[1] *
            rtb_Switch1_dt)) * 0.5) + (rtb_Switch2_ks * rtb_Switch4_fu);
          rtb_Switch4_fu = (6.0 * rtb_Switch2_n) - 4.0;
          rtb_Switch1_c = (-6.0 * rtb_Switch2_n) + 2.0;
          rtb_Switch2_n = (-12.0 * rtb_Switch2_n) + 6.0;
          rtb_Switch1_dt = (((rtb_Minus_n[0] * rtb_Switch4_fu) + (rtb_Add2[0] *
            rtb_Switch1_c)) * 0.5) + (rtb_Init * rtb_Switch2_n);
          rtb_Switch1_c = (((rtb_Minus_n[1] * rtb_Switch4_fu) + (rtb_Add2[1] *
            rtb_Switch1_c)) * 0.5) + (rtb_Switch2_ks * rtb_Switch2_n);
          rtb_Switch4_fu = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Add_ir), 3.0);
          rtb_Switch2_n = fmax(1.0E-10, rtb_Switch4_fu);
          Robot_Control_DW.Relay_Mode = ((rtb_Switch4_fu >=
            2.220446049250313E-16) || (Robot_Control_DW.Relay_Mode));
          if (Robot_Control_DW.Relay_Mode) {
            rtb_Switch4_fu = 1.0;
          } else {
            rtb_Switch4_fu = -1.0;
          }

          if (rtb_Bias1_p == 0) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Switch11;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch1_c) - (rtb_Switch1_dt *
              rtb_Add_ir)) / (rtb_Switch2_n * rtb_Switch4_fu);
        }

        if (s248_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s248_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Switch2_n = rtb_Switch1_ac - ((real_T)s248_iter);
        rtb_Num_Segments = s248_iter;
        s248_iter++;
      } while ((rtb_Switch2_n >= 4.0) && (s248_iter <= 3));

      /* End of Outputs for SubSystem: '<S244>/Sampling_Loop' */

      /* SignalConversion generated from: '<S227>/Position_and_Curvature' incorporates:
       *  Assignment: '<S248>/Assignment'
       *  Concatenate: '<S223>/Matrix Concatenate'
       */
      memcpy(&rtb_MatrixConcatenate_o[0], &Robot_Control_B.Assignment[0], 450U *
             (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S222>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem' incorporates:
       *  ActionPort: '<S225>/Action Port'
       */
      /* Product: '<S225>/Product' incorporates:
       *  Selector: '<S222>/Selector'
       *  Selector: '<S222>/Selector1'
       */
      rtb_Switch1_ac = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S225>/Product1' incorporates:
       *  Selector: '<S222>/Selector'
       *  Selector: '<S222>/Selector1'
       */
      rtb_Switch2_n = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S225>/Product' incorporates:
         *  Constant: '<S225>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Switch1_ac;

        /* Product: '<S225>/Product1' incorporates:
         *  Constant: '<S225>/Constant2'
         *  Product: '<S225>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch2_n;
      }

      /* Assignment: '<S225>/Assignment' incorporates:
       *  Concatenate: '<S223>/Matrix Concatenate'
       *  Concatenate: '<S225>/Matrix Concatenate'
       */
      memset(&rtb_MatrixConcatenate_o[0], 0, 450U * (sizeof(real_T)));
      memcpy(&rtb_MatrixConcatenate_o[0], &rtb_MatrixConcatenate_h[0], 50U *
             (sizeof(real_T)));
      memcpy(&rtb_MatrixConcatenate_o[50], &rtb_MatrixConcatenate_h[50], 50U *
             (sizeof(real_T)));

      /* SignalConversion generated from: '<S225>/Num_Segments' incorporates:
       *  Constant: '<S225>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S222>/If Action Subsystem' */
    }

    /* End of If: '<S222>/If1' */

    /* Concatenate: '<S223>/Matrix Concatenate' incorporates:
     *  Selector: '<S223>/Selector'
     *  Selector: '<S223>/Selector1'
     *  Selector: '<S223>/Selector3'
     */
    memcpy(&rtb_MatrixConcatenate_k[0], &rtb_MatrixConcatenate_o[0], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_k[50], &rtb_MatrixConcatenate_o[150], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_k[100], &rtb_MatrixConcatenate_o[300], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_k[150], &rtb_MatrixConcatenate_o[50], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_k[200], &rtb_MatrixConcatenate_o[200], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_k[250], &rtb_MatrixConcatenate_o[350], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_k[300], &rtb_MatrixConcatenate_o[100], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_k[350], &rtb_MatrixConcatenate_o[250], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_k[400], &rtb_MatrixConcatenate_o[400], 50U *
           (sizeof(real_T)));
    memcpy(&rtb_MatrixConcatenate_o[0], &rtb_MatrixConcatenate_k[0], 450U *
           (sizeof(real_T)));

    /* MATLAB Function: '<S223>/Distance Along Curve' incorporates:
     *  Concatenate: '<S223>/Matrix Concatenate'
     *  Selector: '<S223>/Selector4'
     *  Selector: '<S223>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s248_iter = 0; s248_iter < 149; s248_iter++) {
      /* Outputs for Iterator SubSystem: '<S244>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S248>/While Iterator'
       */
      rtb_Assignment_d[s248_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s248_iter + 1] -
         rtb_MatrixConcatenate_o[s248_iter], rtb_MatrixConcatenate_o[s248_iter +
         151] - rtb_MatrixConcatenate_o[s248_iter + 150]) +
        rtb_Assignment_d[s248_iter];

      /* End of Outputs for SubSystem: '<S244>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S223>/Distance Along Curve' */

    /* MATLAB Function: '<S223>/Find closest index to curve' incorporates:
     *  Concatenate: '<S223>/Matrix Concatenate'
     *  Selector: '<S223>/Selector4'
     *  Selector: '<S223>/Selector5'
     *  Selector: '<S274>/Selector'
     */
    for (s248_iter = 0; s248_iter < 150; s248_iter++) {
      /* Outputs for Iterator SubSystem: '<S244>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S248>/While Iterator'
       */
      distance_from_robot[s248_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s248_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s248_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S244>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s248_iter = 1;
    } else {
      s248_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s248_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s248_iter == 0) {
      rtb_Switch1_ac = distance_from_robot[0];
    } else {
      rtb_Switch1_ac = distance_from_robot[s248_iter - 1];
      for (rtb_Bias1_p = s248_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Switch2_n = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_ac > rtb_Switch2_n) {
          rtb_Switch1_ac = rtb_Switch2_n;
        }
      }
    }

    s248_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s248_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_ac) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S274>/Selector' incorporates:
     *  Constant: '<S274>/Constant'
     *  MATLAB Function: '<S223>/Find closest index to curve'
     *  MinMax: '<S274>/Min'
     */
    rtb_Switch2_n = rtb_Assignment_d[((int32_T)fmin(50.0, s248_iter)) - 1];

    /* If: '<S274>/If' incorporates:
     *  RelationalOperator: '<S274>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S274>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S277>/Action Port'
       */
      /* SignalConversion generated from: '<S277>/Lookup Table Dynamic' */
      rtb_Reshape3[0] = rtb_Assignment_d[0];
      rtb_Reshape3[1] = rtb_Assignment_d[49];

      /* Sum: '<S279>/FixPt Sum1' incorporates:
       *  Constant: '<S279>/FixPt Constant'
       */
      rtb_Switch1_ac = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S277>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S277>/Selector11'
       *  Selector: '<S277>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_ac) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S277>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S277>/Selector1'
       *  Selector: '<S277>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_ac) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S277>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S277>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_ac), &rtb_Minus_n[0], rtb_Switch2_n,
                           &rtb_Reshape3[0], 1U);

      /* SignalConversion: '<S277>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S277>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S277>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Switch2_n,
                           &rtb_Reshape3[0], 1U);

      /* End of Outputs for SubSystem: '<S274>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S274>/Latch' incorporates:
       *  ActionPort: '<S278>/Action Port'
       */
      /* SignalConversion generated from: '<S278>/In1' incorporates:
       *  UnitDelay: '<S274>/Unit Delay1'
       */
      rtb_Switch1_ac = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S278>/In2' incorporates:
       *  UnitDelay: '<S274>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S274>/Latch' */
    }

    /* End of If: '<S274>/If' */

    /* MinMax: '<S221>/Min' incorporates:
     *  Lookup_n-D: '<S221>/Lookahead Distance'
     *  UnitDelay: '<S221>/Unit Delay'
     */
    rtb_Subtract_c3 = fmin(rtb_Subtract_c3, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S223>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S273>/While Iterator'
     */
    s273_iter = 1U;
    rtb_LogicalOperator5 = true;
    while (rtb_LogicalOperator5 && (s273_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S223>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S273>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s273_iter;
      rtb_LogicalOperator5 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s248_iter - 1] + rtb_Subtract_c3)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s273_iter++;
    }

    /* End of Outputs for SubSystem: '<S223>/Find first index that meets distance target' */

    /* Switch: '<S276>/Switch' incorporates:
     *  Concatenate: '<S223>/Matrix Concatenate'
     *  Constant: '<S223>/Constant'
     *  Constant: '<S273>/Constant'
     *  Constant: '<S276>/Constant'
     *  Constant: '<S276>/Constant1'
     *  Constant: '<S276>/Constant2'
     *  Constant: '<S276>/Constant3'
     *  Logic: '<S273>/AND'
     *  MATLAB Function: '<S223>/Find closest index to curve'
     *  Math: '<S276>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S276>/Max'
     *  MinMax: '<S276>/Min'
     *  MinMax: '<S276>/Min1'
     *  Product: '<S273>/Product'
     *  Product: '<S276>/Divide'
     *  Product: '<S276>/Product'
     *  Product: '<S276>/Product1'
     *  RelationalOperator: '<S223>/Relational Operator'
     *  RelationalOperator: '<S273>/Relational Operator'
     *  RelationalOperator: '<S273>/Relational Operator1'
     *  Selector: '<S223>/Selector10'
     *  Selector: '<S223>/Selector7'
     *  Selector: '<S223>/Selector8'
     *  Selector: '<S223>/Selector9'
     *  Selector: '<S273>/Selector'
     *  Selector: '<S273>/Selector1'
     *  Selector: '<S274>/Selector'
     *  Sqrt: '<S276>/Sqrt'
     *  Sum: '<S223>/Subtract'
     *  Sum: '<S273>/Add'
     *  Sum: '<S276>/Subtract'
     *  Sum: '<S276>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Subtract_c3 = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Switch1_ac *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Subtract_c3 = fmin(rtb_Switch1_ac * Spline_Velocity_Multiplier_TEST,
        sqrt(Spline_Max_Centripital_Acceleration / fmax
             (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299],
              1.0E-5)));
    }

    /* End of Switch: '<S276>/Switch' */

    /* Logic: '<S224>/OR' */
    rtb_Compare_lp = (rtb_LogicalOperator1 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S224>/Switch1' incorporates:
     *  Switch: '<S224>/Switch'
     *  UnitDelay: '<S224>/Unit Delay'
     */
    if (rtb_Compare_lp) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S224>/Constant3'
       *  SignalConversion: '<S224>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Switch2_n = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S224>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Subtract_c3;
      rtb_Switch2_n = rtb_Merge1;
    }

    /* End of Switch: '<S224>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S224>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Switch2_n;

    /* Selector: '<S223>/Selector6' incorporates:
     *  Concatenate: '<S223>/Matrix Concatenate'
     *  Selector: '<S223>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S223>/Selector2' incorporates:
     *  Concatenate: '<S223>/Matrix Concatenate'
     *  Selector: '<S223>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S224>/Switch2' incorporates:
     *  Sum: '<S280>/Subtract'
     *  Sum: '<S280>/Subtract1'
     *  Trigonometry: '<S280>/Atan2'
     *  UnitDelay: '<S224>/Unit Delay1'
     */
    if (rtb_Compare_lp) {
      rtb_Switch4_fu = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Switch4_fu = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S224>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S224>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Switch4_fu;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S221>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator1;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S221>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S224>/Constant2'
     *  SignalConversion generated from: '<S221>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S224>/Constant5'
     *  SignalConversion generated from: '<S221>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S224>/Constant6'
     *  SignalConversion generated from: '<S221>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S221>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S222>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S221>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S274>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_ac;

    /* Update for UnitDelay: '<S274>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S224>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Switch2_n;

    /* Update for UnitDelay: '<S224>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Switch4_fu;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S220>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S220>/Constant1'
     *  SignalConversion generated from: '<S220>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S220>/Constant'
     *  SignalConversion generated from: '<S220>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S220>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S220>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S220>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S220>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S220>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Compare_ir;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S220>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S220>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S370>/Sign2' incorporates:
   *  UnitDelay: '<S370>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Minus_f_tmp = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Minus_f_tmp = -1.0;
  } else {
    rtb_Minus_f_tmp = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S370>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_ir = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S370>/Product1' incorporates:
   *  Signum: '<S370>/Sign1'
   *  Signum: '<S370>/Sign2'
   */
  rtb_Minus_f_tmp *= rtb_Add_ir;
  if (rtIsNaN(rtb_Minus_f_tmp)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_f_tmp, 256.0);
  }

  /* Switch: '<S370>/Switch' incorporates:
   *  Constant: '<S370>/Constant'
   *  Constant: '<S375>/Constant'
   *  Constant: '<S376>/Constant'
   *  Logic: '<S370>/or'
   *  Product: '<S370>/Product1'
   *  RelationalOperator: '<S375>/Compare'
   *  RelationalOperator: '<S376>/Compare'
   *  UnitDelay: '<S370>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_idx_0 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_MatrixConcatenate_idx_0 = 0.0;
  }

  /* End of Switch: '<S370>/Switch' */

  /* Switch: '<S381>/Init' incorporates:
   *  UnitDelay: '<S381>/FixPt Unit Delay1'
   *  UnitDelay: '<S381>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Switch1_c = rtb_MatrixConcatenate_idx_0;
  } else {
    rtb_Switch1_c = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S381>/Init' */

  /* RelationalOperator: '<S377>/Compare' incorporates:
   *  Constant: '<S377>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_idx_0 == 0.0);

  /* RelationalOperator: '<S378>/Compare' incorporates:
   *  Constant: '<S378>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_MatrixConcatenate_idx_0 > 0.0);

  /* Abs: '<S370>/Abs' incorporates:
   *  Sum: '<S370>/Subtract'
   *  UnitDelay: '<S370>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S370>/Switch5' incorporates:
   *  Constant: '<S370>/Constant1'
   *  Switch: '<S370>/Switch1'
   *  UnaryMinus: '<S370>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S370>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S370>/Constant4'
     *  Constant: '<S370>/Constant6'
     */
    rtb_Reshape3[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshape3[1] = 1.0;

    /* SignalConversion generated from: '<S370>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S370>/Constant2'
     *  Constant: '<S370>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S370>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S370>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_j), &rtb_Reshape3[0],
                         rtb_Merge1, &rtb_Minus_n[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic_j;
    rtb_Minus_f_tmp = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S370>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S370>/Constant10'
     *  Constant: '<S370>/Constant8'
     */
    rtb_Reshape3[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshape3[1] = 1.0;

    /* SignalConversion generated from: '<S370>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S370>/Constant7'
     *  Constant: '<S370>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S370>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S370>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_i), &rtb_Reshape3[0],
                         rtb_Merge1, &rtb_Minus_n[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic1_i;

    /* Switch: '<S370>/Switch3' incorporates:
     *  Constant: '<S370>/Constant1'
     *  Constant: '<S370>/Constant3'
     *  UnaryMinus: '<S370>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      rtb_Minus_f_tmp = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Minus_f_tmp = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S370>/Switch3' */
  }

  /* End of Switch: '<S370>/Switch5' */

  /* Product: '<S370>/Product' incorporates:
   *  Switch: '<S370>/Switch1'
   */
  rtb_Subtract_c3 = rtb_Minus_f_tmp * rtb_Merge1;

  /* Sum: '<S379>/Sum1' */
  rtb_Switch1_ac = rtb_MatrixConcatenate_idx_0 - rtb_Switch1_c;

  /* Switch: '<S380>/Switch2' incorporates:
   *  RelationalOperator: '<S380>/LowerRelop1'
   */
  if (!(rtb_Switch1_ac > rtb_Subtract_c3)) {
    /* Switch: '<S370>/Switch2' incorporates:
     *  Constant: '<S370>/Constant1'
     *  Constant: '<S370>/Constant3'
     *  Switch: '<S370>/Switch4'
     *  UnaryMinus: '<S370>/Unary Minus1'
     */
    if (rtb_LogicalOperator1) {
      rtb_Minus_f_tmp = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S370>/Switch4' incorporates:
       *  Constant: '<S370>/Constant1'
       */
      rtb_Minus_f_tmp = Translation_Speed_Rate_Limit_Dec;
    } else {
      rtb_Minus_f_tmp = -Translation_Speed_Rate_Limit_Inc;
    }

    /* Product: '<S370>/Product2' incorporates:
     *  Switch: '<S370>/Switch2'
     */
    rtb_Subtract_c3 = rtb_Minus_f_tmp * rtb_Merge1;

    /* Switch: '<S380>/Switch' incorporates:
     *  RelationalOperator: '<S380>/UpperRelop'
     */
    if (!(rtb_Switch1_ac < rtb_Subtract_c3)) {
      rtb_Subtract_c3 = rtb_Switch1_ac;
    }

    /* End of Switch: '<S380>/Switch' */
  }

  /* End of Switch: '<S380>/Switch2' */

  /* Sum: '<S379>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Subtract_c3 + rtb_Switch1_c;

  /* Switch: '<S373>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S373>/Switch' incorporates:
     *  Constant: '<S407>/Constant3'
     *  Constant: '<S407>/Constant4'
     *  Math: '<S407>/Math Function'
     *  Sum: '<S373>/Subtract'
     *  Sum: '<S407>/Add1'
     *  Sum: '<S407>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.141592653589793, 6.283185307179586) - 3.141592653589793;
  } else {
    /* Switch: '<S373>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S373>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Minus_f_tmp = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Minus_f_tmp)) || (rtIsInf(rtb_Minus_f_tmp))) {
    rtb_Minus_f_tmp = 0.0;
  } else {
    rtb_Minus_f_tmp = fmod(rtb_Minus_f_tmp, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Minus_f_tmp < 0.0) ? ((int32_T)((uint8_T)
    (-((int8_T)((uint8_T)(-rtb_Minus_f_tmp)))))) : ((int32_T)((uint8_T)
    rtb_Minus_f_tmp)));

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* Switch: '<S199>/Switch' incorporates:
   *  Constant: '<S186>/Constant'
   *  Constant: '<S199>/Constant'
   *  RelationalOperator: '<S186>/Compare'
   *  UnitDelay: '<S199>/Unit Delay'
   */
  if (rtb_GameState != 1) {
    rtb_Minus_f_tmp = 0.0;
  } else {
    rtb_Minus_f_tmp = Robot_Control_DW.UnitDelay_DSTATE_o;
  }

  /* Sum: '<S199>/Sum' incorporates:
   *  Constant: '<S199>/Constant4'
   *  Switch: '<S199>/Switch'
   */
  rtb_Merge1 = rtb_Minus_f_tmp + 0.02;

  /* Switch: '<S200>/Switch' incorporates:
   *  Constant: '<S191>/Constant'
   *  Constant: '<S200>/Constant'
   *  RelationalOperator: '<S191>/Compare'
   *  UnitDelay: '<S200>/Unit Delay'
   */
  if (rtb_GameState != 2) {
    rtb_Minus_f_tmp = 0.0;
  } else {
    rtb_Minus_f_tmp = Robot_Control_DW.UnitDelay_DSTATE_m;
  }

  /* MultiPortSwitch: '<S147>/Multiport Switch' incorporates:
   *  Constant: '<S147>/Constant1'
   *  Constant: '<S147>/Constant3'
   *  Constant: '<S200>/Constant4'
   *  Sum: '<S200>/Sum'
   *  Switch: '<S200>/Switch'
   */
  switch (rtb_GameState) {
   case 0:
    rtb_Switch1_c = 0.0;
    break;

   case 1:
    rtb_Switch1_c = rtb_Merge1;
    break;

   case 2:
    rtb_Switch1_c = rtb_Minus_f_tmp + 0.02;
    break;

   default:
    rtb_Switch1_c = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S147>/Multiport Switch' */

  /* If: '<S147>/If' incorporates:
   *  Constant: '<S184>/Constant'
   *  Constant: '<S185>/Constant'
   *  Constant: '<S187>/Constant'
   *  Constant: '<S188>/Constant'
   *  Constant: '<S189>/Constant'
   *  Constant: '<S190>/Constant'
   *  Constant: '<S192>/Constant'
   *  Inport: '<Root>/MatchTime'
   *  Logic: '<S147>/Logical Operator'
   *  RelationalOperator: '<S184>/Compare'
   *  RelationalOperator: '<S185>/Compare'
   *  RelationalOperator: '<S187>/Compare'
   *  RelationalOperator: '<S188>/Compare'
   *  RelationalOperator: '<S189>/Compare'
   *  RelationalOperator: '<S190>/Compare'
   *  RelationalOperator: '<S192>/Compare'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_n;
  if (((Robot_Control_U.MatchTime == -1.0) || (rtb_GameState == 1)) ||
      (rtb_Switch1_c <= Rebuilt_Match_Time_Transition)) {
    rtAction = 0;
  } else if (rtb_Switch1_c <= Rebuilt_Match_Time_Shift_1) {
    rtAction = 1;
  } else if (rtb_Switch1_c <= Rebuilt_Match_Time_Shift_2) {
    rtAction = 2;
  } else if (rtb_Switch1_c <= Rebuilt_Match_Time_Shift_3) {
    rtAction = 3;
  } else if (rtb_Switch1_c <= Rebuilt_Match_Time_Shift_4) {
    rtAction = 4;
  } else {
    rtAction = 5;
  }

  Robot_Control_DW.If_ActiveSubsystem_n = rtAction;
  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S147>/If Action Subsystem' incorporates:
       *  ActionPort: '<S193>/Action Port'
       */
      /* InitializeConditions for If: '<S147>/If' incorporates:
       *  UnitDelay: '<S193>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S147>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    /* Merge: '<S147>/Merge' incorporates:
     *  Constant: '<S193>/Constant'
     *  SignalConversion generated from: '<S193>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S147>/Merge1' incorporates:
     *  Constant: '<S193>/Constant'
     *  SignalConversion generated from: '<S193>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S193>/Sum' incorporates:
     *  Constant: '<S193>/Constant1'
     *  UnitDelay: '<S193>/Unit Delay'
     */
    rtb_Switch1_ac = Robot_Control_DW.UnitDelay_DSTATE_hb - 0.02;

    /* Merge: '<S147>/Merge2' incorporates:
     *  SignalConversion: '<S193>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac;

    /* Update for UnitDelay: '<S193>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hb = rtb_Switch1_ac;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S147>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S194>/Action Port'
       */
      /* InitializeConditions for If: '<S147>/If' incorporates:
       *  UnitDelay: '<S194>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_b2 = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S147>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S194>/Action Port'
     */
    /* Sum: '<S194>/Sum' incorporates:
     *  Constant: '<S194>/Constant1'
     *  UnitDelay: '<S194>/Unit Delay'
     */
    rtb_Switch1_ac = Robot_Control_DW.UnitDelay_DSTATE_b2 - 0.02;

    /* RelationalOperator: '<S201>/Compare' incorporates:
     *  Constant: '<S201>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_ac <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S147>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S194>/Logical Operator'
     *  Logic: '<S194>/NOT'
     */
    Robot_Control_B.RB_IsBlueActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Merge: '<S147>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S194>/Logical Operator1'
     */
    Robot_Control_B.RB_IsRedActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Switch: '<S194>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S194>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S147>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac;
    } else {
      /* Merge: '<S147>/Merge2' incorporates:
       *  Constant: '<S194>/Constant2'
       *  Sum: '<S194>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac -
        Rebuilt_Match_Time_Shoot_Early;
    }

    /* End of Switch: '<S194>/Switch' */

    /* Update for UnitDelay: '<S194>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b2 = rtb_Switch1_ac;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem1' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S147>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S195>/Action Port'
       */
      /* InitializeConditions for If: '<S147>/If' incorporates:
       *  UnitDelay: '<S195>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S147>/If Action Subsystem2' */
    }

    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S195>/Action Port'
     */
    /* Sum: '<S195>/Sum' incorporates:
     *  Constant: '<S195>/Constant1'
     *  UnitDelay: '<S195>/Unit Delay'
     */
    rtb_Switch1_ac = Robot_Control_DW.UnitDelay_DSTATE_hz - 0.02;

    /* RelationalOperator: '<S202>/Compare' incorporates:
     *  Constant: '<S202>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_ac <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S147>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S195>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S147>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S195>/Logical Operator1'
     *  Logic: '<S195>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S195>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S195>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S147>/Merge2' incorporates:
       *  Constant: '<S195>/Constant2'
       *  Sum: '<S195>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S147>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac;
    }

    /* End of Switch: '<S195>/Switch' */

    /* Update for UnitDelay: '<S195>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hz = rtb_Switch1_ac;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem2' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S147>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S196>/Action Port'
       */
      /* InitializeConditions for If: '<S147>/If' incorporates:
       *  UnitDelay: '<S196>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_gt = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S147>/If Action Subsystem3' */
    }

    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    /* Sum: '<S196>/Sum' incorporates:
     *  Constant: '<S196>/Constant1'
     *  UnitDelay: '<S196>/Unit Delay'
     */
    rtb_Switch1_ac = Robot_Control_DW.UnitDelay_DSTATE_gt - 0.02;

    /* RelationalOperator: '<S203>/Compare' incorporates:
     *  Constant: '<S203>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_ac <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S147>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S196>/Logical Operator'
     *  Logic: '<S196>/NOT'
     */
    Robot_Control_B.RB_IsBlueActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Merge: '<S147>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S196>/Logical Operator1'
     */
    Robot_Control_B.RB_IsRedActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Switch: '<S196>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S196>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S147>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac;
    } else {
      /* Merge: '<S147>/Merge2' incorporates:
       *  Constant: '<S196>/Constant2'
       *  Sum: '<S196>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac -
        Rebuilt_Match_Time_Shoot_Early;
    }

    /* End of Switch: '<S196>/Switch' */

    /* Update for UnitDelay: '<S196>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gt = rtb_Switch1_ac;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem3' */
    break;

   case 4:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S147>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S197>/Action Port'
       */
      /* InitializeConditions for If: '<S147>/If' incorporates:
       *  UnitDelay: '<S197>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S147>/If Action Subsystem4' */
    }

    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    /* Sum: '<S197>/Sum' incorporates:
     *  Constant: '<S197>/Constant1'
     *  UnitDelay: '<S197>/Unit Delay'
     */
    rtb_Switch1_ac = Robot_Control_DW.UnitDelay_DSTATE_di - 0.02;

    /* RelationalOperator: '<S204>/Compare' incorporates:
     *  Constant: '<S204>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_ac <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S147>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S197>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S147>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S197>/Logical Operator1'
     *  Logic: '<S197>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S197>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S197>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S147>/Merge2' incorporates:
       *  Constant: '<S197>/Constant2'
       *  Sum: '<S197>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S147>/Merge2' incorporates:
       *  Constant: '<S197>/Constant3'
       *  Sum: '<S197>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S197>/Switch' */

    /* Update for UnitDelay: '<S197>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Switch1_ac;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem4' */
    break;

   default:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S147>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S198>/Action Port'
       */
      /* InitializeConditions for If: '<S147>/If' incorporates:
       *  UnitDelay: '<S198>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

      /* End of InitializeConditions for SubSystem: '<S147>/If Action Subsystem5' */
    }

    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S198>/Action Port'
     */
    /* Merge: '<S147>/Merge' incorporates:
     *  Constant: '<S198>/Constant'
     *  SignalConversion generated from: '<S198>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S147>/Merge1' incorporates:
     *  Constant: '<S198>/Constant'
     *  SignalConversion generated from: '<S198>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S198>/Sum' incorporates:
     *  Constant: '<S198>/Constant1'
     *  UnitDelay: '<S198>/Unit Delay'
     */
    rtb_Switch1_ac = Robot_Control_DW.UnitDelay_DSTATE_du - 0.02;

    /* Merge: '<S147>/Merge2' incorporates:
     *  SignalConversion: '<S198>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_ac;

    /* Update for UnitDelay: '<S198>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_du = rtb_Switch1_ac;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S147>/If' */

  /* If: '<S206>/If' incorporates:
   *  If: '<S207>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S206>/Blue' incorporates:
     *  ActionPort: '<S208>/Action Port'
     */
    /* Merge: '<S206>/Merge' incorporates:
     *  Constant: '<S208>/BlueAllianceZoneX'
     *  Logic: '<S208>/AND'
     *  RelationalOperator: '<S208>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S206>/Blue' */

    /* Outputs for IfAction SubSystem: '<S207>/Blue' incorporates:
     *  ActionPort: '<S210>/Action Port'
     */
    /* Merge: '<S207>/Merge' incorporates:
     *  Constant: '<S210>/BlueAllianceZoneX'
     *  RelationalOperator: '<S210>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S207>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S206>/Red' incorporates:
     *  ActionPort: '<S209>/Action Port'
     */
    /* Merge: '<S206>/Merge' incorporates:
     *  Constant: '<S209>/RedAllianceZoneX'
     *  Logic: '<S209>/AND'
     *  RelationalOperator: '<S209>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S206>/Red' */

    /* Outputs for IfAction SubSystem: '<S207>/Red' incorporates:
     *  ActionPort: '<S211>/Action Port'
     */
    /* Merge: '<S207>/Merge' incorporates:
     *  Constant: '<S211>/RedAllianceZoneX'
     *  RelationalOperator: '<S211>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S207>/Red' */
  }

  /* End of If: '<S206>/If' */

  /* RelationalOperator: '<S152>/GreaterThan' incorporates:
   *  Constant: '<S152>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S152>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S152>/Relational Operator' incorporates:
   *  Abs: '<S152>/Abs'
   *  Constant: '<S205>/Constant3'
   *  Constant: '<S205>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S205>/Math Function'
   *  Sum: '<S152>/Subtract'
   *  Sum: '<S205>/Add1'
   *  Sum: '<S205>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.141592653589793, 6.283185307179586) - 3.141592653589793) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S151>/Max' incorporates:
   *  Abs: '<S151>/Abs1'
   *  Abs: '<S151>/Abs2'
   *  Abs: '<S151>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S152>/Relational Operator1' incorporates:
   *  Abs: '<S152>/Abs1'
   *  Constant: '<S152>/Constant2'
   *  Sum: '<S152>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S152>/Relational Operator4' incorporates:
   *  Abs: '<S152>/Abs4'
   *  Constant: '<S152>/Constant1'
   *  Sum: '<S152>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S152>/AND' incorporates:
   *  Logic: '<S152>/OR'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  rtb_Compare_lp = ((((Robot_Control_B.RB_Logic_Gyro_Angle) ||
                      (Robot_Control_DW.UnitDelay_5_DSTATE)) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S152>/AND2' incorporates:
   *  Logic: '<S152>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_lp);

  /* RelationalOperator: '<S148>/Compare' incorporates:
   *  Constant: '<S148>/Constant'
   *  Inport: '<Root>/Gamepad_RT'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_RT != 0.0);

  /* SignalConversion: '<S152>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S152>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Compare_lp);

  /* Logic: '<S152>/AND4' */
  rtb_LogicalOperator5 = ((Robot_Control_B.RB_Logic_Shooter_Speed) &&
    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Chart: '<S12>/Shooter_Transfer_Feeder Chart' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   */
  if (Robot_Control_DW.is_active_c2_Robot_Control == 0) {
    Robot_Control_DW.is_active_c2_Robot_Control = 1U;
    Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Not_Shooting;
    Robot_Control_B.RB_Shooter_Active = false;
    Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
    Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
    Robot_Control_B.RB_Transfer_Init = 0.0;
  } else if (Robot_Control_DW.is_c2_Robot_Control ==
             Robot_Control_IN_Not_Shooting) {
    Robot_Control_B.RB_Shooter_Active = false;
    Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
    Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
    Robot_Control_B.RB_Transfer_Init = 0.0;
    if ((rtb_Button_Spinup_Enable || rtb_Compare_a3) || rtb_LogicalOperator1) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.RB_Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.RB_Transfer_Init = 1.0;
    }
  } else {
    /* case IN_Shooting: */
    Robot_Control_B.RB_Shooter_Active = true;
    rtb_Compare_ir = !rtb_Compare_a3;
    rtb_Compare_lp = !rtb_LogicalOperator1;
    if (((!rtb_Button_Spinup_Enable) && rtb_Compare_ir) && rtb_Compare_lp) {
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
        if (((rtb_Compare_ir && rtb_Compare_lp) ||
             ((Robot_Control_DW.Feeder_Loops_Shooting * 0.02) >
              Feeder_Max_Pulsetime)) || (((!Robot_Control_B.RB_Ready_to_Score) &&
              (!Robot_Control_B.RB_Ready_to_Pass)) && (!rtb_LogicalOperator5)))
        {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
          Robot_Control_B.RB_Transfer_Init = 1.0;
        } else {
          Robot_Control_DW.Feeder_Loops_Shooting++;
        }
        break;

       case Robot_Control_IN_Spinning_Up:
        Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
        Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        Robot_Control_B.RB_Transfer_Init = 1.0;
        if ((rtb_Compare_a3 && ((Robot_Control_B.RB_Ready_to_Score) ||
                                (Robot_Control_B.RB_Ready_to_Pass))) ||
            (rtb_LogicalOperator1 && rtb_LogicalOperator5)) {
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
        Robot_Control_B.RB_Desired_Transfer_Speed =
          Rebuilt_Target_Transfer_Speed;
        if (Robot_Control_U.Measured_Transfer_Speed >
            (Robot_Control_B.RB_Desired_Transfer_Speed *
             Rebuilt_Transfer_Minimum_Factor)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Feeder;
          Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
          Robot_Control_B.RB_Transfer_Init = 0.0;
          Robot_Control_DW.Feeder_Loops_Shooting = 0.0;
        } else if (((rtb_Compare_ir && rtb_Compare_lp) ||
                    ((Robot_Control_DW.Feeder_Loops_Shooting * 0.02) >
                     Feeder_Max_Pulsetime)) ||
                   (((!Robot_Control_B.RB_Ready_to_Score) &&
                     (!Robot_Control_B.RB_Ready_to_Pass)) &&
                    (!rtb_LogicalOperator5))) {
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

  /* RelationalOperator: '<S149>/Compare' incorporates:
   *  Constant: '<S149>/Constant'
   *  Inport: '<Root>/Gamepad_B2_B'
   */
  rtb_Compare_a3 = (Robot_Control_U.Gamepad_B2_B != 0.0);

  /* Logic: '<S12>/AND' incorporates:
   *  Logic: '<S12>/NOT'
   */
  rtb_Button_Spinup_Enable = ((Robot_Control_B.RB_Shooter_Active) &&
    (!rtb_Compare_a3));

  /* If: '<S145>/If' incorporates:
   *  Constant: '<S158>/Constant'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Outputs for IfAction SubSystem: '<S145>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    /* SignalConversion generated from: '<S160>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S165>/Constant1'
     *  Constant: '<S165>/Constant10'
     *  Constant: '<S165>/Constant2'
     *  Constant: '<S165>/Constant5'
     *  Constant: '<S165>/Constant6'
     *  Constant: '<S165>/Constant7'
     *  Constant: '<S165>/Constant8'
     *  Constant: '<S165>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* SignalConversion generated from: '<S161>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S161>/Constant1'
     *  Constant: '<S161>/Constant10'
     *  Constant: '<S161>/Constant2'
     *  Constant: '<S161>/Constant5'
     *  Constant: '<S161>/Constant6'
     *  Constant: '<S161>/Constant7'
     *  Constant: '<S161>/Constant8'
     *  Constant: '<S161>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_o3[0] = Rebuilt_Shoot_Hood_Pos_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Rebuilt_Shoot_Hood_Pos_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Rebuilt_Shoot_Hood_Pos_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Rebuilt_Shoot_Hood_Pos_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Rebuilt_Shoot_Hood_Pos_4;
    rtb_TmpSignalConversionAtLoo_o3[5] = Rebuilt_Shoot_Hood_Pos_5;
    rtb_TmpSignalConversionAtLoo_o3[6] = Rebuilt_Shoot_Hood_Pos_6;
    rtb_TmpSignalConversionAtLoo_o3[7] = Rebuilt_Shoot_Hood_Pos_7;

    /* SignalConversion generated from: '<S160>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant10'
     *  Constant: '<S160>/Constant2'
     *  Constant: '<S160>/Constant5'
     *  Constant: '<S160>/Constant6'
     *  Constant: '<S160>/Constant7'
     *  Constant: '<S160>/Constant8'
     *  Constant: '<S160>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ov[0] = Rebuilt_Shoot_Gyro_Err_0;
    rtb_TmpSignalConversionAtLoo_ov[1] = Rebuilt_Shoot_Gyro_Err_1;
    rtb_TmpSignalConversionAtLoo_ov[2] = Rebuilt_Shoot_Gyro_Err_2;
    rtb_TmpSignalConversionAtLoo_ov[3] = Rebuilt_Shoot_Gyro_Err_3;
    rtb_TmpSignalConversionAtLoo_ov[4] = Rebuilt_Shoot_Gyro_Err_4;
    rtb_TmpSignalConversionAtLoo_ov[5] = Rebuilt_Shoot_Gyro_Err_5;
    rtb_TmpSignalConversionAtLoo_ov[6] = Rebuilt_Shoot_Gyro_Err_6;
    rtb_TmpSignalConversionAtLoo_ov[7] = Rebuilt_Shoot_Gyro_Err_7;

    /* SignalConversion generated from: '<S162>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S174>/Constant1'
     *  Constant: '<S174>/Constant10'
     *  Constant: '<S174>/Constant2'
     *  Constant: '<S174>/Constant5'
     *  Constant: '<S174>/Constant6'
     *  Constant: '<S174>/Constant7'
     *  Constant: '<S174>/Constant8'
     *  Constant: '<S174>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_lg[0] = Rebuilt_Shoot_Shooter_Spd_0;
    rtb_TmpSignalConversionAtLoo_lg[1] = Rebuilt_Shoot_Shooter_Spd_1;
    rtb_TmpSignalConversionAtLoo_lg[2] = Rebuilt_Shoot_Shooter_Spd_2;
    rtb_TmpSignalConversionAtLoo_lg[3] = Rebuilt_Shoot_Shooter_Spd_3;
    rtb_TmpSignalConversionAtLoo_lg[4] = Rebuilt_Shoot_Shooter_Spd_4;
    rtb_TmpSignalConversionAtLoo_lg[5] = Rebuilt_Shoot_Shooter_Spd_5;
    rtb_TmpSignalConversionAtLoo_lg[6] = Rebuilt_Shoot_Shooter_Spd_6;
    rtb_TmpSignalConversionAtLoo_lg[7] = Rebuilt_Shoot_Shooter_Spd_7;

    /* SignalConversion generated from: '<S162>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S173>/Constant1'
     *  Constant: '<S173>/Constant10'
     *  Constant: '<S173>/Constant2'
     *  Constant: '<S173>/Constant5'
     *  Constant: '<S173>/Constant6'
     *  Constant: '<S173>/Constant7'
     *  Constant: '<S173>/Constant8'
     *  Constant: '<S173>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ix[0] = Rebuilt_Shoot_Shooter_Spd_I_0;
    rtb_TmpSignalConversionAtLoo_ix[1] = Rebuilt_Shoot_Shooter_Spd_I_1;
    rtb_TmpSignalConversionAtLoo_ix[2] = Rebuilt_Shoot_Shooter_Spd_I_2;
    rtb_TmpSignalConversionAtLoo_ix[3] = Rebuilt_Shoot_Shooter_Spd_I_3;
    rtb_TmpSignalConversionAtLoo_ix[4] = Rebuilt_Shoot_Shooter_Spd_I_4;
    rtb_TmpSignalConversionAtLoo_ix[5] = Rebuilt_Shoot_Shooter_Spd_I_5;
    rtb_TmpSignalConversionAtLoo_ix[6] = Rebuilt_Shoot_Shooter_Spd_I_6;
    rtb_TmpSignalConversionAtLoo_ix[7] = Rebuilt_Shoot_Shooter_Spd_I_7;

    /* Switch: '<S164>/Switch4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S164>/Logical Operator'
     *  Switch: '<S164>/Switch5'
     *  Switch: '<S164>/Switch6'
     */
    if ((Robot_Control_B.Is_Outside_Alliance_Zone) || rtb_LogicalOperator1) {
      /* Switch: '<S164>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S164>/Switch4' incorporates:
         *  Constant: '<S164>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S164>/Switch4' incorporates:
         *  Constant: '<S164>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S164>/Switch2' */

      /* Switch: '<S164>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S164>/Switch6' incorporates:
         *  Constant: '<S164>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S164>/Switch6' incorporates:
         *  Constant: '<S164>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S164>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S164>/Switch5' incorporates:
         *  Constant: '<S164>/Constant8'
         *  Switch: '<S164>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S164>/Switch4' incorporates:
         *  Constant: '<S164>/Constant9'
         *  Switch: '<S164>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S164>/Switch6' incorporates:
       *  Constant: '<S164>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* End of Switch: '<S164>/Switch4' */

    /* Outputs for Iterator SubSystem: '<S158>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S159>/While Iterator'
     */
    Iteration_Number = 1U;

    /* InitializeConditions for Memory: '<S159>/Memory1' */
    rtb_Switch1_ac = 0.0;

    /* InitializeConditions for Memory: '<S159>/Memory2' */
    rtb_Switch2_n = 0.0;

    /* InitializeConditions for Memory: '<S159>/Memory3' */
    rtb_Switch4_fu = 0.0;

    /* InitializeConditions for Memory: '<S159>/Memory' */
    rtb_LogicalOperator1 = true;
    rtb_LogicalOperator5 = true;

    /* SignalConversion generated from: '<S167>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S158>/Constant'
     *  Constant: '<S167>/Constant'
     *  Constant: '<S167>/Constant1'
     *  Constant: '<S167>/Constant11'
     *  Constant: '<S167>/Constant2'
     *  Constant: '<S167>/Constant3'
     *  Constant: '<S167>/Constant4'
     *  Constant: '<S167>/Constant5'
     *  Constant: '<S167>/Constant6'
     */
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;

    /* SignalConversion generated from: '<S167>/Lookup Table Dynamic' */
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_LogicalOperator5 && (Iteration_Number <= 10)) {
      /* Switch: '<S168>/Switch' incorporates:
       *  Memory: '<S159>/Memory1'
       *  Memory: '<S159>/Memory2'
       *  Switch: '<S168>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Switch1_c = rtb_Switch1_ac;
        rtb_Switch1_dt = rtb_Switch2_n;
      } else {
        rtb_Switch1_c = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Switch1_dt = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S168>/Switch' */

      /* Math: '<S166>/Hypot' incorporates:
       *  Sum: '<S166>/Subtract'
       *  Sum: '<S166>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Switch1_c -
        Robot_Control_B.KF_Position_X, rtb_Switch1_dt -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S167>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S167>/Lookup Table Dynamic'
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

      /* Sum: '<S169>/Subtract' incorporates:
       *  Memory: '<S159>/Memory3'
       *  Sum: '<S169>/Subtract1'
       */
      rtb_Switch1_ac = rtb_TOF - rtb_Switch4_fu;

      /* Sum: '<S169>/Add' incorporates:
       *  Gain: '<S169>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S169>/Product'
       *  Sum: '<S169>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Switch1_ac *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Switch1_c;

      /* Sum: '<S169>/Add1' incorporates:
       *  Gain: '<S169>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S169>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Switch1_ac *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Switch1_dt;

      /* Memory: '<S159>/Memory' */
      rtb_LogicalOperator5 = rtb_LogicalOperator1;

      /* Update for Memory: '<S159>/Memory1' */
      rtb_Switch1_ac = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S159>/Memory2' */
      rtb_Switch2_n = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S159>/Memory3' */
      rtb_Switch4_fu = rtb_TOF;

      /* Update for Memory: '<S159>/Memory' incorporates:
       *  Constant: '<S171>/Constant'
       *  Math: '<S170>/Hypot'
       *  RelationalOperator: '<S171>/Compare'
       *  Sum: '<S170>/Subtract'
       *  Sum: '<S170>/Subtract1'
       */
      rtb_LogicalOperator1 = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X
        - rtb_Switch1_c, Robot_Control_B.RB_Desired_Target_Y - rtb_Switch1_dt) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S158>/Iterate_Shot_Target' */

    /* Merge: '<S145>/Merge2' incorporates:
     *  S-Function (sfix_look1_dyn): '<S161>/Lookup Table Dynamic'
     */
    /* Dynamic Look-Up Table Block: '<S161>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S160>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S160>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S162>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S162>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S162>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S162>/Lookup Table Dynamic1'
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

    /* Switch: '<S162>/Switch' incorporates:
     *  Constant: '<S162>/Constant'
     *  Constant: '<S162>/Constant1'
     *  Sum: '<S162>/Add'
     *  UnitDelay: '<S162>/Unit Delay'
     */
    if (Robot_Control_B.RB_Transfer_Init != 0.0) {
      rtb_Switch1_ac = 0.0;
    } else {
      rtb_Switch1_ac = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    /* End of Switch: '<S162>/Switch' */

    /* Switch: '<S162>/Switch1' incorporates:
     *  Constant: '<S162>/Constant2'
     *  RelationalOperator: '<S162>/GreaterThan'
     */
    if (rtb_Switch1_ac < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S145>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S145>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    /* End of Switch: '<S162>/Switch1' */

    /* Merge: '<S145>/Merge3' incorporates:
     *  Gain: '<S172>/Gain1'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_Switch_cn;

    /* Trigonometry: '<S175>/Atan1' incorporates:
     *  Constant: '<S175>/Constant'
     *  Constant: '<S175>/Constant1'
     *  Sum: '<S175>/Subtract3'
     *  Sum: '<S175>/Subtract4'
     */
    rtb_Switch_cn = rt_atan2d_snf(1.0 - Robot_Control_B.KF_Position_Y, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S175>/Mod' incorporates:
     *  Constant: '<S175>/Constant4'
     */
    rtb_Switch2_n = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Sum: '<S175>/Subtract2' incorporates:
     *  Constant: '<S163>/Constant10'
     *  Sum: '<S175>/Subtract8'
     */
    rtb_Switch1_dt = Field_Length - Robot_Control_B.KF_Position_X;

    /* Trigonometry: '<S175>/Atan2' incorporates:
     *  Constant: '<S175>/Constant2'
     *  Sum: '<S175>/Subtract1'
     *  Sum: '<S175>/Subtract2'
     */
    rtb_Switch_cn = rt_atan2d_snf(1.0 - Robot_Control_B.KF_Position_Y,
      rtb_Switch1_dt);

    /* Math: '<S175>/Mod1' incorporates:
     *  Constant: '<S175>/Constant5'
     */
    rtb_Switch4_fu = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Sum: '<S175>/Subtract5' incorporates:
     *  Constant: '<S163>/Constant11'
     *  Sum: '<S175>/Subtract7'
     */
    rtb_Switch11 = Field_Width_Pass - Robot_Control_B.KF_Position_Y;

    /* Trigonometry: '<S175>/Atan3' incorporates:
     *  Constant: '<S175>/Constant3'
     *  Sum: '<S175>/Subtract5'
     *  Sum: '<S175>/Subtract6'
     */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch11, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S175>/Mod2' incorporates:
     *  Constant: '<S175>/Constant6'
     */
    rtb_Switch1_c = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Trigonometry: '<S175>/Atan4' */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch11, rtb_Switch1_dt);

    /* Math: '<S175>/Mod3' incorporates:
     *  Constant: '<S175>/Constant7'
     */
    rtb_Switch1_dt = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Merge: '<S145>/Merge' incorporates:
     *  Constant: '<S179>/Constant'
     *  Constant: '<S179>/Shooter Assembly Offset in Robot'
     *  Constant: '<S179>/Shooter Assembly Offset in Robot1'
     *  Gain: '<S183>/Gain1'
     *  MinMax: '<S179>/Max'
     *  Product: '<S179>/Divide'
     *  Sum: '<S179>/Add'
     *  Sum: '<S179>/Subtract1'
     *  Sum: '<S179>/Subtract2'
     *  Trigonometry: '<S179>/Atan2'
     *  Trigonometry: '<S179>/Tanh1'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = (rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      atan(-0.07467599999999999 / fmax(Robot_Control_B.RB_Desired_Shot_Distance,
      0.001))) + (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);

    /* Switch: '<S178>/Switch1' incorporates:
     *  Constant: '<S163>/Constant3'
     *  Constant: '<S163>/Constant7'
     *  Inport: '<Root>/IsBlueAlliance'
     */
    if (Robot_Control_U.IsBlueAlliance > 0.0) {
      rtb_Switch_cn = Blue_Hub_LeftY;
    } else {
      rtb_Switch_cn = Red_Hub_LeftY;
    }

    /* End of Switch: '<S178>/Switch1' */

    /* Sum: '<S176>/Subtract3' */
    rtb_Switch11 = rtb_Switch_cn - Robot_Control_B.KF_Position_Y;

    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S163>/Constant2'
     *  Constant: '<S163>/Constant4'
     *  Constant: '<S163>/Constant5'
     *  Constant: '<S163>/Constant6'
     *  Constant: '<S163>/Constant8'
     *  Constant: '<S163>/Constant9'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Switch: '<S178>/Switch2'
     *  Switch: '<S178>/Switch3'
     */
    if (Robot_Control_U.IsBlueAlliance > 0.0) {
      rtb_Switch_cn = Blue_Hub_LeftX;
      rtb_Add_ir = Blue_Hub_RightX;
      rtb_Add_di = Blue_Hub_RightY;
    } else {
      rtb_Switch_cn = Red_Hub_LeftX;
      rtb_Add_ir = Red_Hub_RightX;
      rtb_Add_di = Red_Hub_RightY;
    }

    /* End of Switch: '<S178>/Switch' */

    /* Trigonometry: '<S176>/Atan1' incorporates:
     *  Sum: '<S176>/Subtract4'
     */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch11, rtb_Switch_cn -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S176>/Mod1' incorporates:
     *  Constant: '<S176>/Constant'
     */
    rtb_Switch_cn = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Math: '<S176>/Mod2' incorporates:
     *  Constant: '<S176>/Constant1'
     *  Sum: '<S176>/Subtract1'
     *  Sum: '<S176>/Subtract2'
     *  Switch: '<S178>/Switch2'
     *  Switch: '<S178>/Switch3'
     *  Trigonometry: '<S176>/Atan3'
     */
    rtb_Switch11 = rt_modd_snf(rt_atan2d_snf(rtb_Add_ir -
      Robot_Control_B.KF_Position_Y, rtb_Add_di - Robot_Control_B.KF_Position_X),
      6.283185307179586);

    /* Switch: '<S176>/Switch' incorporates:
     *  Abs: '<S176>/Abs'
     *  Abs: '<S176>/Abs1'
     *  RelationalOperator: '<S176>/GreaterThan'
     */
    if (!(rtb_Switch_cn < rtb_Switch11)) {
      rtb_Switch_cn = rtb_Switch11;
    }

    /* End of Switch: '<S176>/Switch' */

    /* Math: '<S163>/Math Function' incorporates:
     *  Constant: '<S163>/Constant1'
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Switch11 = rt_modd_snf(Robot_Control_U.Gyro_Angle_Field_rad,
      6.283185307179586);

    /* If: '<S177>/If' incorporates:
     *  Switch: '<S182>/Switch'
     */
    if (Robot_Control_B.RB_Desired_Target_Y > Field_Hub_Y) {
      /* Outputs for IfAction SubSystem: '<S177>/If Action Subsystem' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
      /* Switch: '<S181>/Switch' */
      if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
        /* Abs: '<S163>/Abs' */
        rtb_Switch2_n = rtb_Switch1_dt;
      } else {
        /* Abs: '<S163>/Abs' */
        rtb_Switch2_n = rtb_Switch1_c;
      }

      /* End of Switch: '<S181>/Switch' */
      /* End of Outputs for SubSystem: '<S177>/If Action Subsystem' */

      /* Outputs for IfAction SubSystem: '<S177>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S182>/Action Port'
       */
    } else if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
      /* Switch: '<S182>/Switch' incorporates:
       *  Abs: '<S163>/Abs'
       */
      rtb_Switch2_n = rtb_Switch4_fu;

      /* End of Outputs for SubSystem: '<S177>/If Action Subsystem1' */
    }

    /* End of If: '<S177>/If' */

    /* Switch: '<S180>/Switch' incorporates:
     *  Logic: '<S180>/AND'
     *  Logic: '<S180>/AND1'
     *  RelationalOperator: '<S180>/GreaterThan'
     *  RelationalOperator: '<S180>/GreaterThan1'
     *  RelationalOperator: '<S180>/GreaterThan2'
     *  RelationalOperator: '<S180>/GreaterThan3'
     *  RelationalOperator: '<S180>/GreaterThan4'
     */
    if (rtb_Switch2_n < rtb_Switch_cn) {
      rtb_Compare_ir = ((rtb_Switch11 > rtb_Switch2_n) && (rtb_Switch11 <
        rtb_Switch_cn));
    } else {
      rtb_Compare_ir = ((rtb_Switch11 > rtb_Switch_cn) && (rtb_Switch11 <
        rtb_Switch2_n));
    }

    /* Merge: '<S145>/Merge4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S163>/AND'
     *  Logic: '<S180>/Logical Operator'
     *  Switch: '<S180>/Switch'
     */
    Robot_Control_B.Can_Pass = (rtb_Compare_a3 &&
      ((Robot_Control_U.IsBlueAlliance != 0.0) == ((int32_T)rtb_Compare_ir)));

    /* Update for UnitDelay: '<S162>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Switch1_ac;

    /* End of Outputs for SubSystem: '<S145>/Desired Shooting Parameters Math' */
  } else {
    /* Outputs for IfAction SubSystem: '<S145>/Shooter Not Active' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    /* Merge: '<S145>/Merge' incorporates:
     *  Constant: '<S157>/Constant2'
     *  SignalConversion generated from: '<S157>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;

    /* Merge: '<S145>/Merge1' incorporates:
     *  Constant: '<S157>/Constant'
     *  SignalConversion generated from: '<S157>/Desired_Shooter_Speed'
     */
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;

    /* Merge: '<S145>/Merge2' incorporates:
     *  Constant: '<S157>/Constant3'
     *  SignalConversion generated from: '<S157>/Desired_Hood_Pos'
     */
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;

    /* Merge: '<S145>/Merge3' incorporates:
     *  Constant: '<S157>/Constant1'
     *  SignalConversion generated from: '<S157>/Allowed_Shoot_Gyro_Error_rad'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* Merge: '<S145>/Merge4' incorporates:
     *  Constant: '<S157>/Constant4'
     *  SignalConversion generated from: '<S157>/Can_Pass'
     */
    Robot_Control_B.Can_Pass = true;

    /* End of Outputs for SubSystem: '<S145>/Shooter Not Active' */
  }

  /* End of If: '<S145>/If' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Switch: '<S3>/Switch3'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Add_ir = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;
    rtb_Add_di = Robot_Control_U.Gyro_Angle_Field_rad;
  } else {
    rtb_Add_ir = Robot_Control_B.Steering_Abs_Cmd_SPF;
    rtb_Add_di = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* Sum: '<S402>/Add1' incorporates:
   *  Constant: '<S402>/Constant3'
   *  Constant: '<S402>/Constant4'
   *  Math: '<S402>/Math Function'
   *  Sum: '<S401>/Sum'
   *  Sum: '<S402>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf((rtb_Add_ir - rtb_Add_di) +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Gain: '<S405>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.29577951308232 *
    rtb_Optimized_Module_Angle;

  /* Abs: '<S384>/Abs1' */
  rtb_Switch4_fu = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S404>/Sum1' incorporates:
   *  Constant: '<S401>/Constant2'
   *  Product: '<S404>/Product'
   *  Sum: '<S404>/Sum'
   *  UnitDelay: '<S404>/Unit Delay1'
   */
  rtb_Switch_cn = ((rtb_Optimized_Module_Angle -
                    Robot_Control_DW.UnitDelay1_DSTATE) *
                   Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S401>/Product' incorporates:
   *  Constant: '<S401>/Constant3'
   */
  rtb_Switch1_ac = rtb_Switch_cn * Steering_Heading_Control_D;

  /* Sum: '<S403>/Diff' incorporates:
   *  UnitDelay: '<S403>/UD'
   *
   * Block description for '<S403>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S403>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_di = rtb_Switch1_ac - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S401>/Saturation' */
  if (rtb_Add_di > Steering_Heading_Control_D_UL) {
    rtb_Add_di = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_di < Steering_Heading_Control_D_LL) {
    rtb_Add_di = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S401>/Add' incorporates:
   *  Gain: '<S401>/Gain1'
   *  Saturate: '<S401>/Saturation'
   */
  rtb_Switch1_dt = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle) +
    rtb_Add_di;

  /* Sum: '<S401>/Subtract' incorporates:
   *  Constant: '<S401>/Constant'
   */
  rtb_Switch1_c = Steering_Heading_Control_Total_UL - rtb_Switch1_dt;

  /* Sum: '<S401>/Sum2' incorporates:
   *  Gain: '<S401>/Gain2'
   *  UnitDelay: '<S401>/Unit Delay'
   */
  rtb_Switch2_n = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S406>/Switch2' incorporates:
   *  RelationalOperator: '<S406>/LowerRelop1'
   */
  if (!(rtb_Switch2_n > rtb_Switch1_c)) {
    /* Sum: '<S401>/Subtract1' incorporates:
     *  Constant: '<S401>/Constant1'
     */
    rtb_Switch1_c = Steering_Heading_Control_Total_LL - rtb_Switch1_dt;

    /* Switch: '<S406>/Switch' incorporates:
     *  RelationalOperator: '<S406>/UpperRelop'
     */
    if (!(rtb_Switch2_n < rtb_Switch1_c)) {
      rtb_Switch1_c = rtb_Switch2_n;
    }

    /* End of Switch: '<S406>/Switch' */
  }

  /* End of Switch: '<S406>/Switch2' */

  /* Saturate: '<S401>/Saturation1' */
  if (rtb_Switch1_c > Steering_Heading_Control_I_UL) {
    rtb_Switch2_n = Steering_Heading_Control_I_UL;
  } else if (rtb_Switch1_c < Steering_Heading_Control_I_LL) {
    rtb_Switch2_n = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch2_n = rtb_Switch1_c;
  }

  /* End of Saturate: '<S401>/Saturation1' */

  /* Sum: '<S401>/Add1' */
  rtb_Add_di = rtb_Switch1_dt + rtb_Switch2_n;

  /* Saturate: '<S401>/Saturation2' */
  if (rtb_Add_di > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S401>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_di < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S401>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S401>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_di;
  }

  /* End of Saturate: '<S401>/Saturation2' */

  /* Abs: '<S384>/Abs' */
  rtb_Switch1_c = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S384>/Add dither' */
  if (Robot_Control_DW.is_active_c7_Robot_Control == 0) {
    Robot_Control_DW.is_active_c7_Robot_Control = 1U;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c;
  } else if (Robot_Control_DW.is_c7_Robot_Control == Robot_Control_IN_Dither) {
    if ((!rtb_Button_Spinup_Enable) || (rtb_Switch4_fu <
         Steering_Heading_Dither_Thresh_Off)) {
      Robot_Control_DW.is_Dither = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
      Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c;
    } else if (Robot_Control_DW.is_Dither == Robot_Control_IN_High) {
      if (Robot_Control_DW.timer >= Steering_Heading_Dither_Period) {
        Robot_Control_DW.is_Dither = Robot_Control_IN_Off;
        Robot_Control_B.abs_Cmd_Out = 0.0;
        Robot_Control_DW.timer = 0.0;
      } else {
        Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c *
          Steering_Heading_Dither_Gain;
        Robot_Control_DW.timer += 0.02;
      }

      /* case IN_Off: */
    } else if (Robot_Control_DW.timer >= Steering_Heading_Dither_Period) {
      Robot_Control_DW.is_Dither = Robot_Control_IN_High;
      Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c * Steering_Heading_Dither_Gain;
      Robot_Control_DW.timer = 0.0;
    } else {
      Robot_Control_DW.timer += 0.02;
    }

    /* case IN_No_Dither: */
  } else if (rtb_Button_Spinup_Enable && (rtb_Switch4_fu >
              Steering_Heading_Dither_Thresh_On)) {
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_Dither;
    Robot_Control_DW.is_Dither = Robot_Control_IN_High;
    Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c * Steering_Heading_Dither_Gain;
    Robot_Control_DW.timer = 0.0;
  } else {
    Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c;
  }

  /* End of Chart: '<S384>/Add dither' */

  /* Switch: '<S384>/Switch' incorporates:
   *  Constant: '<S384>/Constant'
   *  Constant: '<S400>/Constant'
   *  Product: '<S384>/Product'
   *  RelationalOperator: '<S400>/Compare'
   *  Signum: '<S384>/Sign'
   */
  if (rtb_Switch1_c > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S384>/Sign' */
    if (rtIsNaN(Robot_Control_B.Steering_Heading_PID)) {
      rtb_Add_ir = (rtNaN);
    } else if (Robot_Control_B.Steering_Heading_PID < 0.0) {
      rtb_Add_ir = -1.0;
    } else {
      rtb_Add_ir = (Robot_Control_B.Steering_Heading_PID > 0.0);
    }

    rtb_Optimized_Module_Angle = Robot_Control_B.abs_Cmd_Out * rtb_Add_ir;
  } else {
    rtb_Optimized_Module_Angle = 0.0;
  }

  /* End of Switch: '<S384>/Switch' */

  /* Signum: '<S383>/Sign2' incorporates:
   *  UnitDelay: '<S383>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_ir = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S383>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Add_di = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (rtb_Optimized_Module_Angle > 0.0);
  }

  /* Product: '<S383>/Product1' incorporates:
   *  Signum: '<S383>/Sign1'
   *  Signum: '<S383>/Sign2'
   */
  rtb_Add_ir *= rtb_Add_di;
  if (rtIsNaN(rtb_Add_ir)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_ir, 256.0);
  }

  /* Switch: '<S383>/Switch' incorporates:
   *  Constant: '<S383>/Constant'
   *  Constant: '<S392>/Constant'
   *  Constant: '<S393>/Constant'
   *  Logic: '<S383>/or'
   *  Product: '<S383>/Product1'
   *  RelationalOperator: '<S392>/Compare'
   *  RelationalOperator: '<S393>/Compare'
   *  UnitDelay: '<S383>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Subtract_c3 = rtb_Optimized_Module_Angle;
  } else {
    rtb_Subtract_c3 = 0.0;
  }

  /* End of Switch: '<S383>/Switch' */

  /* Switch: '<S398>/Init' incorporates:
   *  UnitDelay: '<S398>/FixPt Unit Delay1'
   *  UnitDelay: '<S398>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Subtract_c3;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S398>/Init' */

  /* RelationalOperator: '<S394>/Compare' incorporates:
   *  Constant: '<S394>/Constant'
   */
  rtb_Compare_a3 = (rtb_Subtract_c3 == 0.0);

  /* RelationalOperator: '<S395>/Compare' incorporates:
   *  Constant: '<S395>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Subtract_c3 > 0.0);

  /* Abs: '<S383>/Abs' incorporates:
   *  Sum: '<S383>/Subtract'
   *  UnitDelay: '<S383>/Unit Delay'
   */
  rtb_Switch4_fu = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                        rtb_Optimized_Module_Angle);

  /* Switch: '<S383>/Switch5' incorporates:
   *  Constant: '<S383>/Constant1'
   *  Switch: '<S383>/Switch1'
   *  UnaryMinus: '<S383>/Unary Minus'
   */
  if (rtb_Compare_a3) {
    /* SignalConversion generated from: '<S383>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S383>/Constant4'
     *  Constant: '<S383>/Constant6'
     */
    rtb_Reshape3[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshape3[1] = 1.0;

    /* SignalConversion generated from: '<S383>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S383>/Constant2'
     *  Constant: '<S383>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S383>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S383>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Reshape3[0],
                         rtb_Switch4_fu, &rtb_Minus_n[0], 1U);
    rtb_Switch4_fu = rtb_LookupTableDynamic;
    rtb_Add_ir = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S383>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S383>/Constant10'
     *  Constant: '<S383>/Constant8'
     */
    rtb_Reshape3[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshape3[1] = 1.0;

    /* SignalConversion generated from: '<S383>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S383>/Constant7'
     *  Constant: '<S383>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S383>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S383>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Reshape3[0],
                         rtb_Switch4_fu, &rtb_Minus_n[0], 1U);
    rtb_Switch4_fu = rtb_LookupTableDynamic1;

    /* Switch: '<S383>/Switch3' incorporates:
     *  Constant: '<S383>/Constant1'
     *  Constant: '<S383>/Constant3'
     *  UnaryMinus: '<S383>/Unary Minus'
     */
    if (rtb_LogicalOperator1) {
      rtb_Add_ir = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_ir = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S383>/Switch3' */
  }

  /* End of Switch: '<S383>/Switch5' */

  /* Product: '<S383>/Product' incorporates:
   *  Switch: '<S383>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_ir * rtb_Switch4_fu;

  /* Sum: '<S396>/Sum1' */
  rtb_Switch1_c = rtb_Subtract_c3 - rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S397>/Switch2' incorporates:
   *  RelationalOperator: '<S397>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S383>/Switch2' incorporates:
     *  Constant: '<S383>/Constant1'
     *  Switch: '<S383>/Switch4'
     */
    if (rtb_Compare_a3) {
      rtb_Switch1_dt = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S383>/Switch4' incorporates:
       *  Constant: '<S383>/Constant1'
       */
      rtb_Switch1_dt = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S383>/Switch4' incorporates:
       *  Constant: '<S383>/Constant3'
       *  UnaryMinus: '<S383>/Unary Minus1'
       */
      rtb_Switch1_dt = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S383>/Switch2' */

    /* Product: '<S383>/Product2' */
    rtb_Switch1_dt *= rtb_Switch4_fu;

    /* Switch: '<S397>/Switch' incorporates:
     *  RelationalOperator: '<S397>/UpperRelop'
     */
    if (rtb_Switch1_c < rtb_Switch1_dt) {
      rtb_Optimized_Module_Angle = rtb_Switch1_dt;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch1_c;
    }

    /* End of Switch: '<S397>/Switch' */
  }

  /* End of Switch: '<S397>/Switch2' */

  /* Sum: '<S396>/Sum' */
  rtb_Switch4_fu = rtb_Optimized_Module_Angle + rtb_MatrixConcatenate_b_idx_0;

  /* Signum: '<S382>/Sign2' incorporates:
   *  UnitDelay: '<S382>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_ir = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S382>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S382>/Product1' incorporates:
   *  Signum: '<S382>/Sign1'
   *  Signum: '<S382>/Sign2'
   */
  rtb_Add_ir *= rtb_Add_di;
  if (rtIsNaN(rtb_Add_ir)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_ir, 256.0);
  }

  /* Switch: '<S382>/Switch' incorporates:
   *  Constant: '<S382>/Constant'
   *  Constant: '<S385>/Constant'
   *  Constant: '<S386>/Constant'
   *  Logic: '<S382>/or'
   *  Product: '<S382>/Product1'
   *  RelationalOperator: '<S385>/Compare'
   *  RelationalOperator: '<S386>/Compare'
   *  UnitDelay: '<S382>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S382>/Switch' */

  /* Switch: '<S391>/Init' incorporates:
   *  UnitDelay: '<S391>/FixPt Unit Delay1'
   *  UnitDelay: '<S391>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S391>/Init' */

  /* RelationalOperator: '<S387>/Compare' incorporates:
   *  Constant: '<S387>/Constant'
   */
  rtb_Compare_a3 = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S388>/Compare' incorporates:
   *  Constant: '<S388>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S382>/Abs' incorporates:
   *  Sum: '<S382>/Subtract'
   *  UnitDelay: '<S382>/Unit Delay'
   */
  rtb_Switch1_dt = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                        Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S382>/Switch5' incorporates:
   *  Constant: '<S382>/Constant1'
   *  Switch: '<S382>/Switch1'
   *  UnaryMinus: '<S382>/Unary Minus'
   */
  if (rtb_Compare_a3) {
    /* SignalConversion generated from: '<S382>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S382>/Constant4'
     *  Constant: '<S382>/Constant6'
     */
    rtb_Reshape3[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshape3[1] = 1.0;

    /* SignalConversion generated from: '<S382>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S382>/Constant2'
     *  Constant: '<S382>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S382>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S382>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshape3[0],
                         rtb_Switch1_dt, &rtb_Minus_n[0], 1U);
    rtb_Switch1_dt = rtb_LookupTableDynamic_p;
    rtb_Add_ir = -Steering_Relative_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S382>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S382>/Constant10'
     *  Constant: '<S382>/Constant8'
     */
    rtb_Reshape3[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshape3[1] = 1.0;

    /* SignalConversion generated from: '<S382>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S382>/Constant7'
     *  Constant: '<S382>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S382>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S382>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshape3[0],
                         rtb_Switch1_dt, &rtb_Minus_n[0], 1U);
    rtb_Switch1_dt = rtb_LookupTableDynamic1_g;

    /* Switch: '<S382>/Switch3' incorporates:
     *  Constant: '<S382>/Constant1'
     *  Constant: '<S382>/Constant3'
     *  UnaryMinus: '<S382>/Unary Minus'
     */
    if (rtb_LogicalOperator1) {
      rtb_Add_ir = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_ir = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S382>/Switch3' */
  }

  /* End of Switch: '<S382>/Switch5' */

  /* Product: '<S382>/Product' incorporates:
   *  Switch: '<S382>/Switch1'
   */
  rtb_Subtract_c3 = rtb_Add_ir * rtb_Switch1_dt;

  /* Sum: '<S389>/Sum1' */
  rtb_Switch1_c = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle;

  /* Switch: '<S390>/Switch2' incorporates:
   *  RelationalOperator: '<S390>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_Subtract_c3)) {
    /* Switch: '<S382>/Switch2' incorporates:
     *  Constant: '<S382>/Constant1'
     *  Constant: '<S382>/Constant3'
     *  Switch: '<S382>/Switch4'
     *  UnaryMinus: '<S382>/Unary Minus1'
     */
    if (rtb_Compare_a3) {
      rtb_Add_ir = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S382>/Switch4' incorporates:
       *  Constant: '<S382>/Constant1'
       */
      rtb_Add_ir = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_ir = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S382>/Product2' incorporates:
     *  Switch: '<S382>/Switch2'
     */
    rtb_Switch11 = rtb_Add_ir * rtb_Switch1_dt;

    /* Switch: '<S390>/Switch' incorporates:
     *  RelationalOperator: '<S390>/UpperRelop'
     */
    if (rtb_Switch1_c < rtb_Switch11) {
      rtb_Subtract_c3 = rtb_Switch11;
    } else {
      rtb_Subtract_c3 = rtb_Switch1_c;
    }

    /* End of Switch: '<S390>/Switch' */
  }

  /* End of Switch: '<S390>/Switch2' */

  /* Sum: '<S389>/Sum' */
  rtb_Switch1_c = rtb_Subtract_c3 + rtb_Optimized_Module_Angle;

  /* Switch: '<S372>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (rtb_Button_Spinup_Enable || (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S372>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch4_fu;
  } else {
    /* Switch: '<S372>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch1_c;
  }

  /* End of Switch: '<S372>/Switch' */

  /* Fcn: '<S415>/r->x' incorporates:
   *  Fcn: '<S420>/r->x'
   *  Fcn: '<S425>/r->x'
   *  Fcn: '<S430>/r->x'
   */
  rtb_Switch1_dt = cos(Robot_Control_B.Translation_Steering_Cmd);
  rtb_Switch11 = Robot_Control_B.Translation_Speed_RL * rtb_Switch1_dt;

  /* Sum: '<S409>/Add' incorporates:
   *  Fcn: '<S415>/r->x'
   *  Fcn: '<S416>/r->x'
   */
  rtb_Reshape3[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch11;

  /* Fcn: '<S415>/theta->y' incorporates:
   *  Fcn: '<S420>/theta->y'
   *  Fcn: '<S425>/theta->y'
   *  Fcn: '<S430>/theta->y'
   */
  rtb_Switch1_dt = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S409>/Add' incorporates:
   *  Fcn: '<S415>/theta->y'
   *  Fcn: '<S416>/theta->y'
   */
  rtb_Reshape3[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1_dt;

  /* Sum: '<S410>/Add' incorporates:
   *  Fcn: '<S421>/r->x'
   *  Fcn: '<S421>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch11;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1_dt;

  /* Sum: '<S411>/Add' incorporates:
   *  Fcn: '<S426>/r->x'
   *  Fcn: '<S426>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch11;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1_dt;

  /* Sum: '<S412>/Add' incorporates:
   *  Fcn: '<S431>/r->x'
   *  Fcn: '<S431>/theta->y'
   */
  rtb_Init = (Robot_Control_B.Steering_Localized_Cmd * cos
              (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch11;
  rtb_Switch2_ks = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1_dt;

  /* Fcn: '<S429>/x->r' */
  rtb_Subtract_c3 = rt_hypotd_snf(rtb_Init, rtb_Switch2_ks);

  /* RelationalOperator: '<S432>/Compare' incorporates:
   *  Constant: '<S432>/Constant'
   */
  rtb_Compare_lp = (rtb_Subtract_c3 == 0.0);

  /* Switch: '<S428>/Switch1' */
  if (rtb_Compare_lp) {
    /* Switch: '<S428>/Switch1' incorporates:
     *  Constant: '<S428>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S428>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Subtract_c3;
  }

  /* End of Switch: '<S428>/Switch1' */

  /* Fcn: '<S414>/x->r' */
  rtb_Subtract_c3 = rt_hypotd_snf(rtb_Reshape3[0], rtb_Reshape3[1]);

  /* RelationalOperator: '<S417>/Compare' incorporates:
   *  Constant: '<S417>/Constant'
   */
  rtb_Compare_ir = (rtb_Subtract_c3 == 0.0);

  /* Switch: '<S413>/Switch1' */
  if (rtb_Compare_ir) {
    /* Switch: '<S413>/Switch1' incorporates:
     *  Constant: '<S413>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S413>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Subtract_c3;
  }

  /* End of Switch: '<S413>/Switch1' */

  /* Fcn: '<S419>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S422>/Compare' incorporates:
   *  Constant: '<S422>/Constant'
   */
  rtb_Compare_a3 = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S418>/Switch1' */
  if (rtb_Compare_a3) {
    /* Switch: '<S418>/Switch1' incorporates:
     *  Constant: '<S418>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S418>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S418>/Switch1' */

  /* Fcn: '<S424>/x->r' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S427>/Compare' incorporates:
   *  Constant: '<S427>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Optimized_Module_Angle == 0.0);

  /* Switch: '<S423>/Switch1' */
  if (rtb_LogicalOperator1) {
    /* Switch: '<S423>/Switch1' incorporates:
     *  Constant: '<S423>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S423>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle;
  }

  /* End of Switch: '<S423>/Switch1' */

  /* Product: '<S408>/Divide' incorporates:
   *  Abs: '<S408>/Abs'
   *  Abs: '<S408>/Abs1'
   *  Abs: '<S408>/Abs2'
   *  Abs: '<S408>/Abs3'
   *  Constant: '<S408>/Constant'
   *  MinMax: '<S408>/Max'
   */
  rtb_Subtract_c3 = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S408>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Subtract_c3;

  /* Switch: '<S428>/Switch' */
  if (!rtb_Compare_lp) {
    /* Switch: '<S428>/Switch' incorporates:
     *  Fcn: '<S429>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Switch2_ks,
      rtb_Init);
  }

  /* End of Switch: '<S428>/Switch' */

  /* Trigonometry: '<S362>/Cos4' incorporates:
   *  Switch: '<S351>/Angle_Switch'
   *  Trigonometry: '<S361>/Cos4'
   */
  rtb_Subtract_dr = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S362>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S360>/Unary Minus'
   */
  rtb_MatrixConcatenate_idx_0 = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S362>/Sin4' */
  rtb_uDLookupTable_d = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S362>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S360>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S362>/Subtract1' incorporates:
   *  Product: '<S362>/Product2'
   *  Product: '<S362>/Product3'
   *  Trigonometry: '<S362>/Cos4'
   */
  rtb_Switch1_dt = (rtb_Subtract_dr * rtb_MatrixConcatenate_idx_0) +
    (rtb_uDLookupTable_d * rtb_Optimized_Module_Angle);

  /* Sum: '<S362>/Subtract' incorporates:
   *  Product: '<S362>/Product'
   *  Product: '<S362>/Product1'
   *  Trigonometry: '<S362>/Cos4'
   */
  rtb_Switch11 = (rtb_Subtract_dr * rtb_Optimized_Module_Angle) -
    (rtb_uDLookupTable_d * rtb_MatrixConcatenate_idx_0);

  /* Math: '<S362>/Hypot' */
  rtb_Init = rt_hypotd_snf(rtb_Switch11, rtb_Switch1_dt);

  /* Switch: '<S362>/Switch' incorporates:
   *  Constant: '<S362>/Constant'
   *  Constant: '<S362>/Constant1'
   *  Constant: '<S363>/Constant'
   *  Product: '<S362>/Divide'
   *  Product: '<S362>/Divide1'
   *  RelationalOperator: '<S363>/Compare'
   *  Switch: '<S362>/Switch1'
   */
  if (rtb_Init > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_dt / rtb_Init;
    rtb_Optimized_Module_Angle = rtb_Switch11 / rtb_Init;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S362>/Switch' */

  /* Switch: '<S351>/Speed_Switch' incorporates:
   *  Abs: '<S351>/Abs'
   *  Constant: '<S359>/Constant'
   *  RelationalOperator: '<S359>/Compare'
   *  Switch: '<S351>/Angle_Switch'
   *  Trigonometry: '<S361>/Atan1'
   *  Trigonometry: '<S362>/Atan1'
   *  UnaryMinus: '<S351>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_ir = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S361>/Subtract1' incorporates:
     *  Product: '<S361>/Product2'
     *  Product: '<S361>/Product3'
     *  Trigonometry: '<S361>/Sin4'
     *  UnaryMinus: '<S351>/Unary Minus'
     */
    rtb_Switch1_dt = (rtb_Subtract_dr * Robot_Control_ConstB.Sin5_c) +
      (rtb_uDLookupTable_d * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S361>/Subtract' incorporates:
     *  Product: '<S361>/Product'
     *  Product: '<S361>/Product1'
     *  Trigonometry: '<S361>/Sin4'
     */
    rtb_Init = (rtb_Subtract_dr * Robot_Control_ConstB.Cos5_b) -
      (rtb_uDLookupTable_d * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S361>/Hypot' */
    rtb_Switch11 = rt_hypotd_snf(rtb_Init, rtb_Switch1_dt);

    /* Switch: '<S361>/Switch1' incorporates:
     *  Constant: '<S361>/Constant'
     *  Constant: '<S361>/Constant1'
     *  Constant: '<S364>/Constant'
     *  Product: '<S361>/Divide'
     *  Product: '<S361>/Divide1'
     *  RelationalOperator: '<S364>/Compare'
     *  Switch: '<S361>/Switch'
     */
    if (rtb_Switch11 > 1.0E-6) {
      rtb_Init /= rtb_Switch11;
      rtb_Switch1_dt /= rtb_Switch11;
    } else {
      rtb_Init = 1.0;
      rtb_Switch1_dt = 0.0;
    }

    /* End of Switch: '<S361>/Switch1' */
    rtb_MatrixConcatenate_idx_0 = rt_atan2d_snf(rtb_Switch1_dt, rtb_Init);
  } else {
    rtb_Add_ir = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_MatrixConcatenate_idx_0 = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S354>/Product2' incorporates:
   *  Constant: '<S354>/Constant'
   *  Switch: '<S351>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_ir * 1154.7574092481445;

  /* Signum: '<S349>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_ir = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S349>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S352>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S353>/Sum'
   */
  rtb_MatrixConcatenate_idx_0 -= Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S284>/Product' incorporates:
   *  Abs: '<S349>/Abs'
   *  Abs: '<S352>/Abs'
   *  Constant: '<S355>/Constant'
   *  Constant: '<S365>/Constant3'
   *  Constant: '<S365>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S349>/OR'
   *  Lookup_n-D: '<S352>/1-D Lookup Table'
   *  Math: '<S365>/Math Function'
   *  RelationalOperator: '<S349>/Equal1'
   *  RelationalOperator: '<S355>/Compare'
   *  Signum: '<S349>/Sign'
   *  Signum: '<S349>/Sign1'
   *  Sum: '<S352>/Add'
   *  Sum: '<S365>/Add1'
   *  Sum: '<S365>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_ir == rtb_Add_di) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_MatrixConcatenate_idx_0 +
    1.5707963267948966, 3.141592653589793) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data, rtCP_uDLookupTable_tableData_g,
                    1U);

  /* Gain: '<S350>/Gain' */
  rtb_Init = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S350>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S357>/Sum1' incorporates:
   *  Constant: '<S350>/Constant2'
   *  Product: '<S357>/Product'
   *  Sum: '<S357>/Sum'
   *  UnitDelay: '<S357>/Unit Delay1'
   */
  rtb_Switch1_dt = ((rtb_MatrixConcatenate_b_idx_0 -
                     Robot_Control_DW.UnitDelay1_DSTATE_j) *
                    Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S350>/Product' incorporates:
   *  Constant: '<S350>/Constant3'
   */
  rtb_Switch11 = rtb_Switch1_dt * Drive_Motor_Control_D;

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
  rtb_Add_di = rtb_Switch11 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S350>/Saturation' */
  if (rtb_Add_di > Drive_Motor_Control_D_UL) {
    rtb_Add_di = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_di < Drive_Motor_Control_D_LL) {
    rtb_Add_di = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S350>/Add' incorporates:
   *  Gain: '<S350>/Gain1'
   *  Saturate: '<S350>/Saturation'
   */
  rtb_Add_di += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Init;

  /* Saturate: '<S350>/Saturation2' */
  if (rtb_Add_di > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_Add_di;
  }

  /* End of Saturate: '<S350>/Saturation2' */

  /* Sum: '<S366>/Add1' incorporates:
   *  Constant: '<S366>/Constant3'
   *  Constant: '<S366>/Constant4'
   *  Math: '<S366>/Math Function'
   *  Sum: '<S366>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_MatrixConcatenate_idx_0 +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S368>/Sum1' incorporates:
   *  Constant: '<S353>/Constant2'
   *  Product: '<S368>/Product'
   *  Sum: '<S368>/Sum'
   *  UnitDelay: '<S368>/Unit Delay1'
   */
  rtb_Init = ((rtb_MatrixConcatenate_b_idx_0 -
               Robot_Control_DW.UnitDelay1_DSTATE_i) *
              Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S353>/Product' incorporates:
   *  Constant: '<S353>/Constant3'
   */
  rtb_Switch2_ks = rtb_Init * Steering_Motor_Control_D;

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
  rtb_Add_di = rtb_Switch2_ks - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S353>/Saturation' */
  if (rtb_Add_di > Steering_Motor_Control_D_UL) {
    rtb_Add_di = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_di < Steering_Motor_Control_D_LL) {
    rtb_Add_di = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S353>/Add' incorporates:
   *  Gain: '<S353>/Gain1'
   *  Saturate: '<S353>/Saturation'
   */
  rtb_Add_pw = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_di;

  /* Sum: '<S353>/Subtract' incorporates:
   *  Constant: '<S353>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_pw;

  /* Sum: '<S353>/Sum2' incorporates:
   *  Gain: '<S353>/Gain2'
   *  UnitDelay: '<S353>/Unit Delay'
   */
  rtb_Sum2_fc = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S369>/Switch2' incorporates:
   *  Constant: '<S353>/Constant'
   *  RelationalOperator: '<S369>/LowerRelop1'
   *  Sum: '<S353>/Subtract'
   */
  if (!(rtb_Sum2_fc > (1.0 - rtb_Add_pw))) {
    /* Switch: '<S369>/Switch' incorporates:
     *  Constant: '<S353>/Constant1'
     *  RelationalOperator: '<S369>/UpperRelop'
     *  Sum: '<S353>/Subtract1'
     */
    if (rtb_Sum2_fc < (-1.0 - rtb_Add_pw)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_pw;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_fc;
    }

    /* End of Switch: '<S369>/Switch' */
  }

  /* End of Switch: '<S369>/Switch2' */

  /* Saturate: '<S353>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S353>/Saturation1' */

  /* Sum: '<S353>/Add1' */
  rtb_Add_di = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S353>/Saturation2' */
  if (rtb_Add_di > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_di;
  }

  /* End of Saturate: '<S353>/Saturation2' */

  /* Product: '<S408>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Subtract_c3;

  /* Switch: '<S413>/Switch' */
  if (!rtb_Compare_ir) {
    /* Switch: '<S413>/Switch' incorporates:
     *  Fcn: '<S414>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshape3[1],
      rtb_Reshape3[0]);
  }

  /* End of Switch: '<S413>/Switch' */

  /* Trigonometry: '<S299>/Cos4' incorporates:
   *  Switch: '<S288>/Angle_Switch'
   *  Trigonometry: '<S298>/Cos4'
   */
  rtb_Subtract_dr = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S299>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S297>/Unary Minus'
   */
  rtb_MatrixConcatenate_idx_0 = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S299>/Sin4' */
  rtb_uDLookupTable_d = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S299>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S297>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S299>/Subtract1' incorporates:
   *  Product: '<S299>/Product2'
   *  Product: '<S299>/Product3'
   *  Trigonometry: '<S299>/Cos4'
   */
  rtb_Add_pw = (rtb_Subtract_dr * rtb_MatrixConcatenate_idx_0) +
    (rtb_uDLookupTable_d * rtb_Optimized_Module_Angle);

  /* Sum: '<S299>/Subtract' incorporates:
   *  Product: '<S299>/Product'
   *  Product: '<S299>/Product1'
   *  Trigonometry: '<S299>/Cos4'
   */
  rtb_Subtract1_bm = (rtb_Subtract_dr * rtb_Optimized_Module_Angle) -
    (rtb_uDLookupTable_d * rtb_MatrixConcatenate_idx_0);

  /* Math: '<S299>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract1_bm, rtb_Add_pw);

  /* Switch: '<S299>/Switch' incorporates:
   *  Constant: '<S299>/Constant'
   *  Constant: '<S299>/Constant1'
   *  Constant: '<S300>/Constant'
   *  Product: '<S299>/Divide'
   *  Product: '<S299>/Divide1'
   *  RelationalOperator: '<S300>/Compare'
   *  Switch: '<S299>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pw / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle = rtb_Subtract1_bm / rtb_Hypot_g5;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S299>/Switch' */

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
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_ir = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S298>/Subtract1' incorporates:
     *  Product: '<S298>/Product2'
     *  Product: '<S298>/Product3'
     *  Trigonometry: '<S298>/Sin4'
     *  UnaryMinus: '<S288>/Unary Minus'
     */
    rtb_Add_pw = (rtb_Subtract_dr * Robot_Control_ConstB.Sin5) +
      (rtb_uDLookupTable_d * Robot_Control_ConstB.Cos5);

    /* Sum: '<S298>/Subtract' incorporates:
     *  Product: '<S298>/Product'
     *  Product: '<S298>/Product1'
     *  Trigonometry: '<S298>/Sin4'
     */
    rtb_Hypot_g5 = (rtb_Subtract_dr * Robot_Control_ConstB.Cos5) -
      (rtb_uDLookupTable_d * Robot_Control_ConstB.Sin5);

    /* Math: '<S298>/Hypot' */
    rtb_Subtract1_bm = rt_hypotd_snf(rtb_Hypot_g5, rtb_Add_pw);

    /* Switch: '<S298>/Switch1' incorporates:
     *  Constant: '<S298>/Constant'
     *  Constant: '<S298>/Constant1'
     *  Constant: '<S301>/Constant'
     *  Product: '<S298>/Divide'
     *  Product: '<S298>/Divide1'
     *  RelationalOperator: '<S301>/Compare'
     *  Switch: '<S298>/Switch'
     */
    if (rtb_Subtract1_bm > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Subtract1_bm;
      rtb_Add_pw /= rtb_Subtract1_bm;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S298>/Switch1' */
    rtb_MatrixConcatenate_idx_0 = rt_atan2d_snf(rtb_Add_pw, rtb_Hypot_g5);
  } else {
    rtb_Add_ir = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_MatrixConcatenate_idx_0 = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S291>/Product2' incorporates:
   *  Constant: '<S291>/Constant'
   *  Switch: '<S288>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_ir * 1154.7574092481445;

  /* Signum: '<S286>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_ir = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S286>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S289>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S290>/Sum'
   */
  rtb_MatrixConcatenate_idx_0 -= Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S281>/Product' incorporates:
   *  Abs: '<S286>/Abs'
   *  Abs: '<S289>/Abs'
   *  Constant: '<S292>/Constant'
   *  Constant: '<S302>/Constant3'
   *  Constant: '<S302>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
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
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_ir == rtb_Add_di) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_MatrixConcatenate_idx_0 +
    1.5707963267948966, 3.141592653589793) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Gain: '<S287>/Gain' */
  rtb_Hypot_g5 = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S287>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S294>/Sum1' incorporates:
   *  Constant: '<S287>/Constant2'
   *  Product: '<S294>/Product'
   *  Sum: '<S294>/Sum'
   *  UnitDelay: '<S294>/Unit Delay1'
   */
  rtb_Add_pw = ((rtb_MatrixConcatenate_b_idx_0 -
                 Robot_Control_DW.UnitDelay1_DSTATE_f) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S287>/Product' incorporates:
   *  Constant: '<S287>/Constant3'
   */
  rtb_Subtract1_bm = rtb_Add_pw * Drive_Motor_Control_D;

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
  rtb_Add_di = rtb_Subtract1_bm - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S287>/Saturation' */
  if (rtb_Add_di > Drive_Motor_Control_D_UL) {
    rtb_Add_di = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_di < Drive_Motor_Control_D_LL) {
    rtb_Add_di = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S287>/Add' incorporates:
   *  Gain: '<S287>/Gain1'
   *  Saturate: '<S287>/Saturation'
   */
  rtb_Add_di += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Hypot_g5;

  /* Saturate: '<S287>/Saturation2' */
  if (rtb_Add_di > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = rtb_Add_di;
  }

  /* End of Saturate: '<S287>/Saturation2' */

  /* Sum: '<S303>/Add1' incorporates:
   *  Constant: '<S303>/Constant3'
   *  Constant: '<S303>/Constant4'
   *  Math: '<S303>/Math Function'
   *  Sum: '<S303>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_MatrixConcatenate_idx_0 +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S305>/Sum1' incorporates:
   *  Constant: '<S290>/Constant2'
   *  Product: '<S305>/Product'
   *  Sum: '<S305>/Sum'
   *  UnitDelay: '<S305>/Unit Delay1'
   */
  rtb_Hypot_g5 = ((rtb_MatrixConcatenate_b_idx_0 -
                   Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S290>/Product' incorporates:
   *  Constant: '<S290>/Constant3'
   */
  rtb_Product_dq = rtb_Hypot_g5 * Steering_Motor_Control_D;

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
  rtb_Add_di = rtb_Product_dq - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S290>/Saturation' */
  if (rtb_Add_di > Steering_Motor_Control_D_UL) {
    rtb_Add_di = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_di < Steering_Motor_Control_D_LL) {
    rtb_Add_di = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S290>/Add' incorporates:
   *  Gain: '<S290>/Gain1'
   *  Saturate: '<S290>/Saturation'
   */
  rtb_uDLookupTable_d = (Steering_Motor_Control_P *
    rtb_MatrixConcatenate_b_idx_0) + rtb_Add_di;

  /* Sum: '<S290>/Subtract' incorporates:
   *  Constant: '<S290>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_uDLookupTable_d;

  /* Sum: '<S290>/Sum2' incorporates:
   *  Gain: '<S290>/Gain2'
   *  UnitDelay: '<S290>/Unit Delay'
   */
  rtb_Sum2_m = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S306>/Switch2' incorporates:
   *  Constant: '<S290>/Constant'
   *  RelationalOperator: '<S306>/LowerRelop1'
   *  Sum: '<S290>/Subtract'
   */
  if (!(rtb_Sum2_m > (1.0 - rtb_uDLookupTable_d))) {
    /* Switch: '<S306>/Switch' incorporates:
     *  Constant: '<S290>/Constant1'
     *  RelationalOperator: '<S306>/UpperRelop'
     *  Sum: '<S290>/Subtract1'
     */
    if (rtb_Sum2_m < (-1.0 - rtb_uDLookupTable_d)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_uDLookupTable_d;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_m;
    }

    /* End of Switch: '<S306>/Switch' */
  }

  /* End of Switch: '<S306>/Switch2' */

  /* Saturate: '<S290>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_m = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_m = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_m = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S290>/Saturation1' */

  /* Sum: '<S290>/Add1' */
  rtb_Add_di = rtb_uDLookupTable_d + rtb_Sum2_m;

  /* Saturate: '<S290>/Saturation2' */
  if (rtb_Add_di > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_di;
  }

  /* End of Saturate: '<S290>/Saturation2' */

  /* Product: '<S408>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Subtract_c3;

  /* Switch: '<S418>/Switch' */
  if (!rtb_Compare_a3) {
    /* Switch: '<S418>/Switch' incorporates:
     *  Fcn: '<S419>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S418>/Switch' */

  /* Trigonometry: '<S320>/Cos4' incorporates:
   *  Switch: '<S309>/Angle_Switch'
   *  Trigonometry: '<S319>/Cos4'
   */
  rtb_Subtract_dr = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S320>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S318>/Unary Minus'
   */
  rtb_MatrixConcatenate_idx_0 = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S320>/Sin4' */
  rtb_uDLookupTable_d = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S320>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S318>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S320>/Subtract1' incorporates:
   *  Product: '<S320>/Product2'
   *  Product: '<S320>/Product3'
   *  Trigonometry: '<S320>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Subtract_dr * rtb_MatrixConcatenate_idx_0)
    + (rtb_uDLookupTable_d * rtb_Optimized_Module_Angle);

  /* Sum: '<S320>/Subtract' incorporates:
   *  Product: '<S320>/Product'
   *  Product: '<S320>/Product1'
   *  Trigonometry: '<S320>/Cos4'
   */
  rtb_Subtract_iu = (rtb_Subtract_dr * rtb_Optimized_Module_Angle) -
    (rtb_uDLookupTable_d * rtb_MatrixConcatenate_idx_0);

  /* Math: '<S320>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Subtract_iu, rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S320>/Switch' incorporates:
   *  Constant: '<S320>/Constant'
   *  Constant: '<S320>/Constant1'
   *  Constant: '<S321>/Constant'
   *  Product: '<S320>/Divide'
   *  Product: '<S320>/Divide1'
   *  RelationalOperator: '<S321>/Compare'
   *  Switch: '<S320>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Hypot_b;
    rtb_Optimized_Module_Angle = rtb_Subtract_iu / rtb_Hypot_b;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S320>/Switch' */

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
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_ir = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S319>/Subtract1' incorporates:
     *  Product: '<S319>/Product2'
     *  Product: '<S319>/Product3'
     *  Trigonometry: '<S319>/Sin4'
     *  UnaryMinus: '<S309>/Unary Minus'
     */
    rtb_Subtract_iu = (rtb_Subtract_dr * Robot_Control_ConstB.Sin5_m) +
      (rtb_uDLookupTable_d * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S319>/Subtract' incorporates:
     *  Product: '<S319>/Product'
     *  Product: '<S319>/Product1'
     *  Trigonometry: '<S319>/Sin4'
     */
    rtb_Subtract_dr = (rtb_Subtract_dr * Robot_Control_ConstB.Cos5_g) -
      (rtb_uDLookupTable_d * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S319>/Hypot' */
    rtb_uDLookupTable_d = rt_hypotd_snf(rtb_Subtract_dr, rtb_Subtract_iu);

    /* Switch: '<S319>/Switch1' incorporates:
     *  Constant: '<S319>/Constant'
     *  Constant: '<S319>/Constant1'
     *  Constant: '<S322>/Constant'
     *  Product: '<S319>/Divide'
     *  Product: '<S319>/Divide1'
     *  RelationalOperator: '<S322>/Compare'
     *  Switch: '<S319>/Switch'
     */
    if (rtb_uDLookupTable_d > 1.0E-6) {
      rtb_Subtract_dr /= rtb_uDLookupTable_d;
      rtb_uDLookupTable_d = rtb_Subtract_iu / rtb_uDLookupTable_d;
    } else {
      rtb_Subtract_dr = 1.0;
      rtb_uDLookupTable_d = 0.0;
    }

    /* End of Switch: '<S319>/Switch1' */
    rtb_MatrixConcatenate_idx_0 = rt_atan2d_snf(rtb_uDLookupTable_d,
      rtb_Subtract_dr);
  } else {
    rtb_Add_ir = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_MatrixConcatenate_idx_0 = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S312>/Product2' incorporates:
   *  Constant: '<S312>/Constant'
   *  Switch: '<S309>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_ir * 1154.7574092481445;

  /* Signum: '<S307>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_ir = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S307>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S310>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S311>/Sum'
   */
  rtb_MatrixConcatenate_idx_0 -= Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S282>/Product' incorporates:
   *  Abs: '<S307>/Abs'
   *  Abs: '<S310>/Abs'
   *  Constant: '<S313>/Constant'
   *  Constant: '<S323>/Constant3'
   *  Constant: '<S323>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
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
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_ir == rtb_Add_di) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_MatrixConcatenate_idx_0 +
    1.5707963267948966, 3.141592653589793) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Gain: '<S308>/Gain' */
  rtb_Subtract_iu = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S308>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S315>/Sum1' incorporates:
   *  Constant: '<S308>/Constant2'
   *  Product: '<S315>/Product'
   *  Sum: '<S315>/Sum'
   *  UnitDelay: '<S315>/Unit Delay1'
   */
  rtb_uDLookupTable_d = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S308>/Product' incorporates:
   *  Constant: '<S308>/Constant3'
   */
  rtb_Subtract_dr = rtb_uDLookupTable_d * Drive_Motor_Control_D;

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
  rtb_Add_di = rtb_Subtract_dr - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S308>/Saturation' */
  if (rtb_Add_di > Drive_Motor_Control_D_UL) {
    rtb_Add_di = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_di < Drive_Motor_Control_D_LL) {
    rtb_Add_di = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S308>/Add' incorporates:
   *  Gain: '<S308>/Gain1'
   *  Saturate: '<S308>/Saturation'
   */
  rtb_Add_di += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Subtract_iu;

  /* Saturate: '<S308>/Saturation2' */
  if (rtb_Add_di > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = rtb_Add_di;
  }

  /* End of Saturate: '<S308>/Saturation2' */

  /* Sum: '<S324>/Add1' incorporates:
   *  Constant: '<S324>/Constant3'
   *  Constant: '<S324>/Constant4'
   *  Math: '<S324>/Math Function'
   *  Sum: '<S324>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_MatrixConcatenate_idx_0 +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S326>/Sum1' incorporates:
   *  Constant: '<S311>/Constant2'
   *  Product: '<S326>/Product'
   *  Sum: '<S326>/Sum'
   *  UnitDelay: '<S326>/Unit Delay1'
   */
  rtb_Subtract_iu = ((rtb_MatrixConcatenate_b_idx_0 -
                      Robot_Control_DW.UnitDelay1_DSTATE_n) *
                     Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S311>/Product' incorporates:
   *  Constant: '<S311>/Constant3'
   */
  rtb_Hypot_b = rtb_Subtract_iu * Steering_Motor_Control_D;

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
  rtb_Add_di = rtb_Hypot_b - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S311>/Saturation' */
  if (rtb_Add_di > Steering_Motor_Control_D_UL) {
    rtb_Add_di = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_di < Steering_Motor_Control_D_LL) {
    rtb_Add_di = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S311>/Add' incorporates:
   *  Gain: '<S311>/Gain1'
   *  Saturate: '<S311>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P *
    rtb_MatrixConcatenate_b_idx_0) + rtb_Add_di;

  /* Sum: '<S311>/Subtract' incorporates:
   *  Constant: '<S311>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S311>/Sum2' incorporates:
   *  Gain: '<S311>/Gain2'
   *  UnitDelay: '<S311>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S327>/Switch2' incorporates:
   *  Constant: '<S311>/Constant'
   *  RelationalOperator: '<S327>/LowerRelop1'
   *  Sum: '<S311>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S327>/Switch' incorporates:
     *  Constant: '<S311>/Constant1'
     *  RelationalOperator: '<S327>/UpperRelop'
     *  Sum: '<S311>/Subtract1'
     */
    if (rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S327>/Switch' */
  }

  /* End of Switch: '<S327>/Switch2' */

  /* Saturate: '<S311>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S311>/Saturation1' */

  /* Sum: '<S311>/Add1' */
  rtb_Add_di = rtb_MatrixConcatenate_idx_0 + rtb_Subtract1_kg;

  /* Saturate: '<S311>/Saturation2' */
  if (rtb_Add_di > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_di;
  }

  /* End of Saturate: '<S311>/Saturation2' */

  /* Product: '<S408>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Subtract_c3;

  /* Switch: '<S423>/Switch' */
  if (!rtb_LogicalOperator1) {
    /* Switch: '<S423>/Switch' incorporates:
     *  Fcn: '<S424>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S423>/Switch' */

  /* Trigonometry: '<S341>/Cos4' incorporates:
   *  Switch: '<S330>/Angle_Switch'
   *  Trigonometry: '<S340>/Cos4'
   */
  rtb_Subtract_av = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S341>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S339>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S341>/Sin4' */
  rtb_MatrixConcatenate_idx_0 = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S341>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S339>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S341>/Subtract1' incorporates:
   *  Product: '<S341>/Product2'
   *  Product: '<S341>/Product3'
   *  Trigonometry: '<S341>/Cos4'
   */
  rtb_Subtract_c3 = (rtb_Subtract_av * rtb_Optimized_Module_Angle) +
    (rtb_MatrixConcatenate_idx_0 * rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S341>/Subtract' incorporates:
   *  Product: '<S341>/Product'
   *  Product: '<S341>/Product1'
   *  Trigonometry: '<S341>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Subtract_av *
    rtb_MatrixConcatenate_b_idx_0) - (rtb_MatrixConcatenate_idx_0 *
    rtb_Optimized_Module_Angle);

  /* Math: '<S341>/Hypot' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0,
    rtb_Subtract_c3);

  /* Switch: '<S341>/Switch' incorporates:
   *  Constant: '<S341>/Constant'
   *  Constant: '<S341>/Constant1'
   *  Constant: '<S342>/Constant'
   *  Product: '<S341>/Divide'
   *  Product: '<S341>/Divide1'
   *  RelationalOperator: '<S342>/Compare'
   *  Switch: '<S341>/Switch1'
   */
  if (rtb_Optimized_Module_Angle > 1.0E-6) {
    rtb_Subtract_c3 /= rtb_Optimized_Module_Angle;
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle;
  } else {
    rtb_Subtract_c3 = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
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
  if (fabs(rt_atan2d_snf(rtb_Subtract_c3, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    rtb_Add_ir = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S340>/Subtract1' incorporates:
     *  Product: '<S340>/Product2'
     *  Product: '<S340>/Product3'
     *  Trigonometry: '<S340>/Sin4'
     *  UnaryMinus: '<S330>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Subtract_av *
      Robot_Control_ConstB.Sin5_e) + (rtb_MatrixConcatenate_idx_0 *
      Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S340>/Subtract' incorporates:
     *  Product: '<S340>/Product'
     *  Product: '<S340>/Product1'
     *  Trigonometry: '<S340>/Sin4'
     */
    rtb_Subtract_av = (rtb_Subtract_av * Robot_Control_ConstB.Cos5_i) -
      (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S340>/Hypot' */
    rtb_MatrixConcatenate_idx_0 = rt_hypotd_snf(rtb_Subtract_av,
      rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S340>/Switch1' incorporates:
     *  Constant: '<S340>/Constant'
     *  Constant: '<S340>/Constant1'
     *  Constant: '<S343>/Constant'
     *  Product: '<S340>/Divide'
     *  Product: '<S340>/Divide1'
     *  RelationalOperator: '<S343>/Compare'
     *  Switch: '<S340>/Switch'
     */
    if (rtb_MatrixConcatenate_idx_0 > 1.0E-6) {
      rtb_Subtract_av /= rtb_MatrixConcatenate_idx_0;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Subtract_av = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S340>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_Subtract_av);
  } else {
    rtb_Add_ir = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S333>/Product2' incorporates:
   *  Constant: '<S333>/Constant'
   *  Switch: '<S330>/Speed_Switch'
   */
  rtb_Subtract_c3 = rtb_Add_ir * 1154.7574092481445;

  /* Signum: '<S328>/Sign' */
  if (rtIsNaN(rtb_Subtract_c3)) {
    rtb_Add_ir = (rtNaN);
  } else if (rtb_Subtract_c3 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (rtb_Subtract_c3 > 0.0);
  }

  /* Signum: '<S328>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S331>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S332>/Sum'
   */
  rtb_Optimized_Module_Angle -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S283>/Product' incorporates:
   *  Abs: '<S328>/Abs'
   *  Abs: '<S331>/Abs'
   *  Constant: '<S334>/Constant'
   *  Constant: '<S344>/Constant3'
   *  Constant: '<S344>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
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
  rtb_Subtract_c3 = (((real_T)((rtb_Add_ir == rtb_Add_di) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Subtract_c3) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.141592653589793) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Gain: '<S329>/Gain' */
  rtb_MatrixConcatenate_b_idx_0 = Drive_Motor_Control_FF * rtb_Subtract_c3;

  /* Sum: '<S329>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Subtract_c3 -= Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S336>/Sum1' incorporates:
   *  Constant: '<S329>/Constant2'
   *  Product: '<S336>/Product'
   *  Sum: '<S336>/Sum'
   *  UnitDelay: '<S336>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Subtract_c3 -
    Robot_Control_DW.UnitDelay1_DSTATE_n4) * Drive_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S329>/Product' incorporates:
   *  Constant: '<S329>/Constant3'
   */
  rtb_Subtract_av = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

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
  rtb_Add_di = rtb_Subtract_av - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S329>/Saturation' */
  if (rtb_Add_di > Drive_Motor_Control_D_UL) {
    rtb_Add_di = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_di < Drive_Motor_Control_D_LL) {
    rtb_Add_di = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S329>/Add' incorporates:
   *  Gain: '<S329>/Gain1'
   *  Saturate: '<S329>/Saturation'
   */
  rtb_Add_di += (Drive_Motor_Control_P * rtb_Subtract_c3) +
    rtb_MatrixConcatenate_b_idx_0;

  /* Saturate: '<S329>/Saturation2' */
  if (rtb_Add_di > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Add_di;
  }

  /* End of Saturate: '<S329>/Saturation2' */

  /* Sum: '<S345>/Add1' incorporates:
   *  Constant: '<S345>/Constant3'
   *  Constant: '<S345>/Constant4'
   *  Math: '<S345>/Math Function'
   *  Sum: '<S345>/Add2'
   */
  rtb_Subtract_c3 = rt_modd_snf(rtb_Optimized_Module_Angle + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Sum: '<S347>/Sum1' incorporates:
   *  Constant: '<S332>/Constant2'
   *  Product: '<S347>/Product'
   *  Sum: '<S347>/Sum'
   *  UnitDelay: '<S347>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Subtract_c3 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S332>/Product' incorporates:
   *  Constant: '<S332>/Constant3'
   */
  rtb_Product_k = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

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
  rtb_Add_di = rtb_Product_k - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S332>/Saturation' */
  if (rtb_Add_di > Steering_Motor_Control_D_UL) {
    rtb_Add_di = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_di < Steering_Motor_Control_D_LL) {
    rtb_Add_di = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S332>/Add' incorporates:
   *  Gain: '<S332>/Gain1'
   *  Saturate: '<S332>/Saturation'
   */
  rtb_Add_f1 = (Steering_Motor_Control_P * rtb_Subtract_c3) + rtb_Add_di;

  /* Sum: '<S332>/Subtract' incorporates:
   *  Constant: '<S332>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_f1;

  /* Sum: '<S332>/Sum2' incorporates:
   *  Gain: '<S332>/Gain2'
   *  UnitDelay: '<S332>/Unit Delay'
   */
  rtb_Subtract_c3 = (Steering_Motor_Control_I * rtb_Subtract_c3) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S348>/Switch2' incorporates:
   *  Constant: '<S332>/Constant'
   *  RelationalOperator: '<S348>/LowerRelop1'
   *  Sum: '<S332>/Subtract'
   */
  if (!(rtb_Subtract_c3 > (1.0 - rtb_Add_f1))) {
    /* Sum: '<S332>/Subtract1' incorporates:
     *  Constant: '<S332>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_f1;

    /* Switch: '<S348>/Switch' incorporates:
     *  Constant: '<S332>/Constant1'
     *  RelationalOperator: '<S348>/UpperRelop'
     *  Sum: '<S332>/Subtract1'
     */
    if (!(rtb_Subtract_c3 < (-1.0 - rtb_Add_f1))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Subtract_c3;
    }

    /* End of Switch: '<S348>/Switch' */
  }

  /* End of Switch: '<S348>/Switch2' */

  /* Saturate: '<S332>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_g = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_g = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_g = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S332>/Saturation1' */

  /* Sum: '<S332>/Add1' */
  rtb_Add_di = rtb_Add_f1 + rtb_Integral_g;

  /* Saturate: '<S332>/Saturation2' */
  if (rtb_Add_di > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_di;
  }

  /* End of Saturate: '<S332>/Saturation2' */

  /* Sum: '<S216>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S218>/Sum1' incorporates:
   *  Constant: '<S216>/Constant2'
   *  Product: '<S218>/Product'
   *  Sum: '<S218>/Sum'
   *  UnitDelay: '<S218>/Unit Delay1'
   */
  rtb_Add_f1 = ((rtb_MatrixConcatenate_b_idx_0 -
                 Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S216>/Product' incorporates:
   *  Constant: '<S216>/Constant3'
   */
  rtb_Product_ih = rtb_Add_f1 * 0.0;

  /* Sum: '<S217>/Diff' incorporates:
   *  UnitDelay: '<S217>/UD'
   *
   * Block description for '<S217>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S217>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_di = rtb_Product_ih - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S216>/Saturation' */
  if (rtb_Add_di > 0.1) {
    rtb_Add_di = 0.1;
  } else if (rtb_Add_di < -0.1) {
    rtb_Add_di = -0.1;
  }

  /* Sum: '<S216>/Add' incorporates:
   *  Gain: '<S216>/Gain'
   *  Gain: '<S216>/Gain1'
   *  Saturate: '<S216>/Saturation'
   */
  rtb_Subtract_c3 = ((Rebuilt_Transfer_Motor_Gain_FF *
                      Robot_Control_B.RB_Desired_Transfer_Speed) +
                     (Rebuilt_Transfer_Motor_Gain_P *
                      rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_di;

  /* Logic: '<S155>/Logical Operator1' incorporates:
   *  Constant: '<S215>/Constant'
   *  RelationalOperator: '<S215>/Compare'
   */
  rtb_LogicalOperator1 = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S155>/Switch1' incorporates:
   *  Abs: '<S155>/Abs'
   *  Constant: '<S155>/Constant1'
   *  Constant: '<S155>/Constant2'
   *  Logic: '<S155>/Logical Operator'
   *  RelationalOperator: '<S155>/LessThan'
   *  Sum: '<S155>/Subtract'
   *  UnitDelay: '<S155>/Unit Delay'
   */
  if ((fabs(rtb_MatrixConcatenate_b_idx_0) <
       Rebuilt_Transfer_Error_Integral_Enable) && rtb_LogicalOperator1) {
    rtb_Compare_a3 = true;
  } else {
    rtb_Compare_a3 = (rtb_LogicalOperator1 &&
                      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S155>/Switch1' */

  /* Switch: '<S216>/Switch' incorporates:
   *  Constant: '<S216>/Constant4'
   */
  if (rtb_Compare_a3) {
    /* Sum: '<S216>/Sum2' incorporates:
     *  Gain: '<S216>/Gain2'
     *  UnitDelay: '<S216>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Transfer_Motor_Gain_I *
      rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S216>/Subtract' incorporates:
     *  Constant: '<S216>/Constant'
     */
    rtb_Integral_c3 = 1.0 - rtb_Subtract_c3;

    /* Switch: '<S219>/Switch2' incorporates:
     *  Constant: '<S216>/Constant'
     *  RelationalOperator: '<S219>/LowerRelop1'
     *  Sum: '<S216>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Subtract_c3))) {
      /* Sum: '<S216>/Subtract1' incorporates:
       *  Constant: '<S216>/Constant1'
       */
      rtb_Integral_c3 = -1.0 - rtb_Subtract_c3;

      /* Switch: '<S219>/Switch' incorporates:
       *  Constant: '<S216>/Constant1'
       *  RelationalOperator: '<S219>/UpperRelop'
       *  Sum: '<S216>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Subtract_c3))) {
        rtb_Integral_c3 = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S219>/Switch' */
    }

    /* End of Switch: '<S219>/Switch2' */

    /* Saturate: '<S216>/Saturation1' */
    if (rtb_Integral_c3 > 0.1) {
      rtb_Integral_c3 = 0.1;
    } else if (rtb_Integral_c3 < -0.1) {
      rtb_Integral_c3 = -0.1;
    }

    /* End of Saturate: '<S216>/Saturation1' */
  } else {
    rtb_Integral_c3 = 0.0;
  }

  /* End of Switch: '<S216>/Switch' */

  /* Switch: '<S155>/Switch2' */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S216>/Add1' */
    rtb_Add_di = rtb_Subtract_c3 + rtb_Integral_c3;

    /* Saturate: '<S216>/Saturation2' */
    if (rtb_Add_di > 1.0) {
      /* Switch: '<S155>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_di < -1.0) {
      /* Switch: '<S155>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S155>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_di;
    }

    /* End of Saturate: '<S216>/Saturation2' */
  } else {
    /* Switch: '<S155>/Switch2' incorporates:
     *  Constant: '<S155>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S155>/Switch2' */

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

  /* RelationalOperator: '<S150>/Compare' incorporates:
   *  Constant: '<S150>/Constant'
   *  Inport: '<Root>/Gamepad_Start'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_Start != 0.0);

  /* Chart: '<S12>/Chart' */
  if (Robot_Control_DW.temporalCounter_i1 < MAX_uint32_T) {
    Robot_Control_DW.temporalCounter_i1++;
  }

  if (Robot_Control_DW.is_active_c6_Robot_Control == 0) {
    Robot_Control_DW.is_active_c6_Robot_Control = 1U;
    Robot_Control_DW.is_c6_Robot_Control = Robot_Con_IN_if_reverse_or_zero;
    Robot_Control_B.Desired_Feeder_Speed_Out =
      Robot_Control_B.RB_Desired_Feeder_Speed;
  } else if (Robot_Control_DW.is_c6_Robot_Control == Robot_Control_IN_if_forward)
  {
    if ((Robot_Control_B.RB_Desired_Feeder_Speed == 0.0) ||
        (!rtb_LogicalOperator1)) {
      Robot_Control_DW.is_if_forward = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_DW.is_c6_Robot_Control = Robot_Con_IN_if_reverse_or_zero;
      Robot_Control_B.Desired_Feeder_Speed_Out =
        Robot_Control_B.RB_Desired_Feeder_Speed;
    } else if (Robot_Control_DW.is_if_forward == Robot_Control_IN_Backwards) {
      if (Robot_Control_DW.temporalCounter_i1 >= ((uint32_T)ceil
           (Rebuilt_Feeder_Time_REV * 50.0))) {
        Robot_Control_DW.temporalCounter_i1 = 0U;
        Robot_Control_DW.is_if_forward = Robot_Control_IN_Forwards;
        Robot_Control_B.Desired_Feeder_Speed_Out = Rebuilt_Target_Feeder_Speed;
      }

      /* case IN_Forwards: */
    } else if (Robot_Control_DW.temporalCounter_i1 >= ((uint32_T)ceil
                (Rebuilt_Feeder_Time_FWD * 50.0))) {
      Robot_Control_DW.temporalCounter_i1 = 0U;
      Robot_Control_DW.is_if_forward = Robot_Control_IN_Backwards;
      Robot_Control_B.Desired_Feeder_Speed_Out = Rebuilt_Negative_Feeder_Speed;
    }

    /* case IN_if_reverse_or_zero: */
  } else if ((Robot_Control_B.RB_Desired_Feeder_Speed ==
              Rebuilt_Target_Feeder_Speed) && rtb_LogicalOperator1) {
    Robot_Control_DW.is_c6_Robot_Control = Robot_Control_IN_if_forward;
    Robot_Control_DW.temporalCounter_i1 = 0U;
    Robot_Control_DW.is_if_forward = Robot_Control_IN_Forwards;
    Robot_Control_B.Desired_Feeder_Speed_Out = Rebuilt_Target_Feeder_Speed;
  } else {
    Robot_Control_B.Desired_Feeder_Speed_Out =
      Robot_Control_B.RB_Desired_Feeder_Speed;
  }

  /* End of Chart: '<S12>/Chart' */

  /* Product: '<S12>/Product' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Add_di = Robot_Control_B.Desired_Feeder_Speed_Out *
    Rebuilt_Feeder_Motor_Gain_FF;

  /* Saturate: '<S12>/Saturation' */
  if (rtb_Add_di > 1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = 1.0;
  } else if (rtb_Add_di < -1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = -1.0;
  } else {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = rtb_Add_di;
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

  /* Sum: '<S154>/Subtract' */
  rtb_Subtract_c3 = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Logic: '<S154>/Logical Operator1' incorporates:
   *  Constant: '<S212>/Constant'
   *  RelationalOperator: '<S212>/Compare'
   */
  rtb_LogicalOperator1 = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Switch: '<S154>/Switch1' incorporates:
   *  Constant: '<S154>/Constant1'
   *  Constant: '<S154>/Constant2'
   *  Logic: '<S154>/Logical Operator'
   *  RelationalOperator: '<S154>/LessThan'
   *  UnitDelay: '<S154>/Unit Delay'
   */
  if ((rtb_Subtract_c3 < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1) {
    rtb_LogicalOperator5 = true;
  } else {
    rtb_LogicalOperator5 = (rtb_LogicalOperator1 &&
      (Robot_Control_DW.UnitDelay_DSTATE_kt));
  }

  /* End of Switch: '<S154>/Switch1' */

  /* Switch: '<S154>/Switch4' incorporates:
   *  Constant: '<S154>/Constant7'
   *  Logic: '<S154>/Logical Operator3'
   *  RelationalOperator: '<S154>/LessThan2'
   *  UnitDelay: '<S154>/Unit Delay1'
   */
  if ((!(rtb_Subtract_c3 < 0.0)) || (!rtb_LogicalOperator1)) {
    rtb_LogicalOperator1 = (rtb_LogicalOperator1 &&
      (Robot_Control_DW.UnitDelay1_DSTATE_oa));
  }

  /* End of Switch: '<S154>/Switch4' */

  /* Switch: '<S154>/Switch2' incorporates:
   *  Constant: '<S154>/Constant3'
   *  Constant: '<S154>/Constant9'
   *  Logic: '<S154>/Logical Operator4'
   *  Logic: '<S154>/Logical Operator5'
   */
  if (rtb_LogicalOperator5 && (!rtb_LogicalOperator1)) {
    rtb_Shooter_Motor_Gain_Ki = Rebuilt_Shooter_Motor_Gain_I;
  } else {
    rtb_Shooter_Motor_Gain_Ki = Rebuilt_Shooter_Motor_Gain_I_Low;
  }

  /* End of Switch: '<S154>/Switch2' */

  /* Outport: '<Root>/Shooter_Motor_Gain_Ki' */
  Robot_Control_Y.Shooter_Motor_Gain_Ki = rtb_Shooter_Motor_Gain_Ki;

  /* Outport: '<Root>/Shooter_Motor_Gain_Change' incorporates:
   *  Constant: '<S154>/Constant4'
   *  DataTypeConversion: '<S154>/Data Type Conversion'
   *  Logic: '<S154>/Logical Operator2'
   *  RelationalOperator: '<S213>/FixPt Relational Operator'
   *  RelationalOperator: '<S214>/FixPt Relational Operator'
   *  UnitDelay: '<S213>/Delay Input1'
   *  UnitDelay: '<S214>/Delay Input1'
   *
   * Block description for '<S213>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S214>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_Y.Shooter_Motor_Gain_Change = ((Rebuilt_Shooter_Motor_Gain_P !=
    Robot_Control_DW.DelayInput1_DSTATE_o) || (rtb_Shooter_Motor_Gain_Ki !=
    Robot_Control_DW.DelayInput1_DSTATE_j));

  /* Outport: '<Root>/Shooter_Motor_Gain_Kp' incorporates:
   *  Constant: '<S154>/Constant4'
   */
  Robot_Control_Y.Shooter_Motor_Gain_Kp = Rebuilt_Shooter_Motor_Gain_P;

  /* Switch: '<S10>/Switch5' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant6'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    rtb_Subtract_c3 = TEST_Desired_Hood_Pos_OV;
  } else {
    rtb_Subtract_c3 = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_Subtract_c3 > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Subtract_c3 = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Subtract_c3 < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Subtract_c3 = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Subtract_c3;

  /* Switch: '<S143>/Init' incorporates:
   *  UnitDelay: '<S143>/FixPt Unit Delay1'
   *  UnitDelay: '<S143>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Subtract_c3;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S143>/Init' */

  /* Sum: '<S141>/Sum1' */
  rtb_Subtract_c3 -= rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S142>/Switch2' incorporates:
   *  Constant: '<S140>/Constant1'
   *  Constant: '<S140>/Constant3'
   *  RelationalOperator: '<S142>/LowerRelop1'
   *  RelationalOperator: '<S142>/UpperRelop'
   *  Switch: '<S142>/Switch'
   */
  if (rtb_Subtract_c3 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Subtract_c3 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Subtract_c3 < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S142>/Switch' incorporates:
     *  Constant: '<S140>/Constant1'
     */
    rtb_Subtract_c3 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S142>/Switch2' */

  /* Sum: '<S141>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Subtract_c3 +
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S54>/Add1' incorporates:
   *  Constant: '<S54>/Constant3'
   *  Constant: '<S54>/Constant4'
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Math: '<S54>/Math Function'
   *  Sum: '<S54>/Add2'
   */
  Robot_Control_B.RB_Intake_Arm_Angle_Mod = rt_modd_snf
    (Robot_Control_U.Measured_Intake_Arm_Angle + 180.0, 360.0) - 180.0;

  /* Chart: '<S6>/Chart' incorporates:
   *  RelationalOperator: '<S58>/FixPt Relational Operator'
   *  UnitDelay: '<S58>/Delay Input1'
   *
   * Block description for '<S58>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Robot_Control_DW.is_active_c4_Robot_Control == 0) {
    Robot_Control_DW.is_active_c4_Robot_Control = 1U;
    Robot_Control_DW.is_c4_Robot_Control = Robot_Contro_IN_Wait_for_Button;
    Robot_Control_B.RB_Des_Intake_Arm_Angle =
      Robot_Control_B.RB_Intake_Arm_Angle_Mod;
    rtb_Compare_lp = false;
  } else {
    switch (Robot_Control_DW.is_c4_Robot_Control) {
     case Robot_Con_IN_Move_Intake_Arm_In:
      rtb_Compare_lp = true;
      if ((rtb_Intake_Arm_Move_Out || (rtb_Intake_Arm_Cycle &&
            (Robot_Control_B.RB_Intake_Arm_Angle_Mod <
             Rebuilt_Intake_Cycle_Angle_In))) || (((int32_T)rtb_Intake_Arm_Cycle)
           < ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_c))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      rtb_Compare_lp = true;
      if (rtb_Intake_Arm_Move_In || (rtb_Intake_Arm_Cycle &&
           (Robot_Control_B.RB_Intake_Arm_Angle_Mod >
            Rebuilt_Intake_Cycle_Angle_Out))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
      }
      break;

     default:
      /* case IN_Wait_for_Button: */
      rtb_Compare_lp = false;
      if (rtb_Intake_Arm_Move_In || rtb_Intake_Arm_Cycle) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
        rtb_Compare_lp = true;
      } else if (rtb_Intake_Arm_Move_Out) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
        rtb_Compare_lp = true;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* Switch: '<S73>/Init' incorporates:
   *  UnitDelay: '<S73>/FixPt Unit Delay1'
   *  UnitDelay: '<S73>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Subtract_c3 = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Subtract_c3 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S73>/Init' */

  /* Sum: '<S71>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_Subtract_c3;

  /* Switch: '<S72>/Switch2' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Constant: '<S60>/Constant3'
   *  RelationalOperator: '<S72>/LowerRelop1'
   *  RelationalOperator: '<S72>/UpperRelop'
   *  Switch: '<S72>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Intake_RL_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S72>/Switch' incorporates:
     *  Constant: '<S60>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S72>/Switch2' */

  /* Sum: '<S71>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Subtract_c3;

  /* Sum: '<S67>/Sum' */
  rtb_Subtract_c3 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S69>/Sum1' incorporates:
   *  Constant: '<S67>/Constant2'
   *  Product: '<S69>/Product'
   *  Sum: '<S69>/Sum'
   *  UnitDelay: '<S69>/Unit Delay1'
   */
  rtb_Sum1_g = ((rtb_Subtract_c3 - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S67>/Product' incorporates:
   *  Constant: '<S67>/Constant3'
   */
  rtb_Product_kv = rtb_Sum1_g * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S68>/Diff' incorporates:
   *  UnitDelay: '<S68>/UD'
   *
   * Block description for '<S68>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S68>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_di = rtb_Product_kv - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S67>/Saturation' */
  if (rtb_Add_di > 0.1) {
    rtb_Add_di = 0.1;
  } else if (rtb_Add_di < -0.1) {
    rtb_Add_di = -0.1;
  }

  /* Sum: '<S67>/Add' incorporates:
   *  Gain: '<S67>/Gain'
   *  Gain: '<S67>/Gain1'
   *  Saturate: '<S67>/Saturation'
   */
  rtb_Add_ir = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
                (Rebuilt_Intake_Arm_Gain_P * rtb_Subtract_c3)) + rtb_Add_di;

  /* Sum: '<S67>/Subtract' incorporates:
   *  Constant: '<S67>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_ir;

  /* Sum: '<S67>/Sum2' incorporates:
   *  Gain: '<S67>/Gain2'
   *  UnitDelay: '<S67>/Unit Delay'
   */
  rtb_Subtract_c3 = (0.0 * rtb_Subtract_c3) +
    Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S67>/Constant'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  Sum: '<S67>/Subtract'
   */
  if (!(rtb_Subtract_c3 > (1.0 - rtb_Add_ir))) {
    /* Sum: '<S67>/Subtract1' incorporates:
     *  Constant: '<S67>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_ir;

    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S67>/Constant1'
     *  RelationalOperator: '<S70>/UpperRelop'
     *  Sum: '<S67>/Subtract1'
     */
    if (!(rtb_Subtract_c3 < (-1.0 - rtb_Add_ir))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Subtract_c3;
    }

    /* End of Switch: '<S70>/Switch' */
  }

  /* End of Switch: '<S70>/Switch2' */

  /* Saturate: '<S67>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > 0.1) {
    rtb_MatrixConcatenate_b_idx_0 = 0.1;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -0.1) {
    rtb_MatrixConcatenate_b_idx_0 = -0.1;
  }

  /* End of Saturate: '<S67>/Saturation1' */

  /* Switch: '<S59>/Switch2' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S66>/Constant'
   *  Logic: '<S59>/Logical Operator1'
   *  Logic: '<S59>/Logical Operator2'
   *  Logic: '<S59>/Logical Operator3'
   *  RelationalOperator: '<S63>/Compare'
   *  RelationalOperator: '<S64>/Compare'
   *  RelationalOperator: '<S65>/Compare'
   *  RelationalOperator: '<S66>/Compare'
   */
  if (((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_In) && (Robot_Control_B.RB_Intake_Arm_Angle_Mod
        <= Rebuilt_Intake_Meas_In_Disable)) ||
      ((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_Out) &&
       (Robot_Control_B.RB_Intake_Arm_Angle_Mod >=
        Rebuilt_Intake_Meas_Out_Disable))) {
    /* Switch: '<S59>/Switch2' incorporates:
     *  Constant: '<S59>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  } else {
    /* Sum: '<S67>/Add1' */
    rtb_Add_di = rtb_Add_ir + rtb_MatrixConcatenate_b_idx_0;

    /* Saturate: '<S67>/Saturation2' */
    if (rtb_Add_di > 1.0) {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_di < -1.0) {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_di;
    }

    /* End of Saturate: '<S67>/Saturation2' */
  }

  /* End of Switch: '<S59>/Switch2' */

  /* Switch: '<S10>/Switch7' incorporates:
   *  Constant: '<S10>/Constant'
   *  Switch: '<S6>/Switch1'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Intake_Arm_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant9'
     */
    Robot_Control_Y.Intake_Arm_Motor_DC = TEST_Intake_Arm_Motor_DC_OV;
  } else if (rtb_Compare_lp) {
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

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/Constant1'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  if (rtb_Intake_Arm_Move_In) {
    rtb_Add_ir = 0.0;
  } else {
    rtb_Add_ir = Robot_Control_DW.UnitDelay_DSTATE_eo;
  }

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S61>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S74>/Constant'
   *  Logic: '<S6>/Logical Operator'
   *  Logic: '<S6>/Logical Operator1'
   *  RelationalOperator: '<S56>/Compare'
   *  RelationalOperator: '<S57>/Compare'
   *  RelationalOperator: '<S74>/Compare'
   *  Sum: '<S61>/Sum'
   *  Switch: '<S61>/Switch'
   */
  if (((((Robot_Control_B.RB_Des_Intake_Arm_Angle == Rebuilt_Intake_Des_Angle_In)
         && (Robot_Control_B.RB_Transfer_Motor_PID_DC != 0.0)) ||
        rtb_Intake_Arm_Cycle) || ((rtb_Add_ir + 0.02) <=
        Rebuilt_Roller_Intake_In_Delay)) || rtb_Shooter_Active_prev) {
    rtb_Subtract_c3 = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Subtract_c3 = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S76>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   */
  rtb_Error_n = rtb_Subtract_c3 - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S78>/Sum1' incorporates:
   *  Constant: '<S76>/Constant2'
   *  Product: '<S78>/Product'
   *  Sum: '<S78>/Sum'
   *  UnitDelay: '<S78>/Unit Delay1'
   */
  rtb_Sum1_ei = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S76>/Product' incorporates:
   *  Constant: '<S76>/Constant3'
   */
  rtb_Product_gy = rtb_Sum1_ei * 0.0;

  /* Sum: '<S77>/Diff' incorporates:
   *  UnitDelay: '<S77>/UD'
   *
   * Block description for '<S77>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S77>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_di = rtb_Product_gy - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S76>/Saturation' */
  if (rtb_Add_di > 0.1) {
    rtb_Add_di = 0.1;
  } else if (rtb_Add_di < -0.1) {
    rtb_Add_di = -0.1;
  }

  /* Sum: '<S76>/Add' incorporates:
   *  Gain: '<S76>/Gain'
   *  Gain: '<S76>/Gain1'
   *  Saturate: '<S76>/Saturation'
   */
  rtb_Add_di += (Rebuilt_Roller_Motor_Gain_FF * rtb_Subtract_c3) +
    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n);

  /* Logic: '<S62>/Logical Operator1' incorporates:
   *  Constant: '<S75>/Constant'
   *  RelationalOperator: '<S75>/Compare'
   */
  rtb_Shooter_Active_prev = !(rtb_Subtract_c3 == 0.0);

  /* Switch: '<S62>/Switch1' incorporates:
   *  Abs: '<S62>/Abs'
   *  Constant: '<S62>/Constant1'
   *  Constant: '<S62>/Constant2'
   *  Logic: '<S62>/Logical Operator'
   *  RelationalOperator: '<S62>/LessThan'
   *  Sum: '<S62>/Subtract'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_Shooter_Active_prev) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_Shooter_Active_prev &&
      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S62>/Switch1' */

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/Constant4'
   */
  if (rtb_Intake_Arm_Move_In) {
    /* Sum: '<S76>/Sum2' incorporates:
     *  Gain: '<S76>/Gain2'
     *  UnitDelay: '<S76>/Unit Delay'
     */
    rtb_Subtract_c3 = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S76>/Subtract' incorporates:
     *  Constant: '<S76>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Add_di;

    /* Switch: '<S79>/Switch2' incorporates:
     *  Constant: '<S76>/Constant'
     *  RelationalOperator: '<S79>/LowerRelop1'
     *  Sum: '<S76>/Subtract'
     */
    if (!(rtb_Subtract_c3 > (1.0 - rtb_Add_di))) {
      /* Sum: '<S76>/Subtract1' incorporates:
       *  Constant: '<S76>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Add_di;

      /* Switch: '<S79>/Switch' incorporates:
       *  Constant: '<S76>/Constant1'
       *  RelationalOperator: '<S79>/UpperRelop'
       *  Sum: '<S76>/Subtract1'
       */
      if (!(rtb_Subtract_c3 < (-1.0 - rtb_Add_di))) {
        rtb_Error_n = rtb_Subtract_c3;
      }

      /* End of Switch: '<S79>/Switch' */
    }

    /* End of Switch: '<S79>/Switch2' */

    /* Saturate: '<S76>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Subtract_c3 = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Subtract_c3 = -0.1;
    } else {
      rtb_Subtract_c3 = rtb_Error_n;
    }

    /* End of Saturate: '<S76>/Saturation1' */
  } else {
    rtb_Subtract_c3 = 0.0;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Switch: '<S62>/Switch2' */
  if (rtb_Shooter_Active_prev) {
    /* Sum: '<S76>/Add1' */
    rtb_Add_di += rtb_Subtract_c3;

    /* Saturate: '<S76>/Saturation2' */
    if (rtb_Add_di > 1.0) {
      /* Switch: '<S62>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_di < -1.0) {
      /* Switch: '<S62>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S62>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_di;
    }

    /* End of Saturate: '<S76>/Saturation2' */
  } else {
    /* Switch: '<S62>/Switch2' incorporates:
     *  Constant: '<S62>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S62>/Switch2' */

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
  if (Robot_Control_DW.is_active_c9_Robot_Control == 0) {
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

  /* Update for UnitDelay: '<S39>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *
   * Block description for '<S39>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Gamepad_B3_X;

  /* Update for UnitDelay: '<S40>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *
   * Block description for '<S40>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Gamepad_B4_Y;

  /* Update for UnitDelay: '<S41>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *
   * Block description for '<S41>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Gamepad_B2_B;

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nl = rtb_Button_Spinup_Enable;

  /* Update for UnitDelay: '<S47>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S47>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S47>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S50>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S50>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 0U;

  /* Update for UnitDelay: '<S50>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_a = rtb_Switch1_py;

  /* Update for UnitDelay: '<S53>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S53>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S53>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_j = rtb_Switch1_jy;

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

  /* Update for Delay: '<S133>/Delay' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S132>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S80>/A'
   *  Delay: '<S133>/Delay'
   */
  rtb_Sum1 = Robot_Control_DW.Delay_DSTATE[0];
  rtb_Switch1_py = 0.0 * Robot_Control_DW.Delay_DSTATE[0];
  rtb_Add_di = Robot_Control_DW.Delay_DSTATE[1];

  /* Update for Delay: '<S133>/Delay' incorporates:
   *  Constant: '<S80>/A'
   *  Constant: '<S80>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S132>/A[k]*xhat[k|k-1]'
   *  Product: '<S132>/B[k]*u[k]'
   *  Product: '<S134>/Product3'
   *  Sum: '<S132>/Add'
   */
  Robot_Control_DW.Delay_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + ((0.0 * rtb_Add_di) + rtb_Sum1)) +
    Robot_Control_B.Product3[0];
  Robot_Control_DW.Delay_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + (rtb_Switch1_py + rtb_Add_di)) +
    Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S381>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S381>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S199>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_o = rtb_Merge1;

  /* Update for UnitDelay: '<S200>/Unit Delay' incorporates:
   *  Constant: '<S200>/Constant4'
   *  Sum: '<S200>/Sum'
   *  Switch: '<S200>/Switch'
   */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Minus_f_tmp + 0.02;

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

  /* Update for UnitDelay: '<S404>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Switch_cn;

  /* Update for UnitDelay: '<S403>/UD'
   *
   * Block description for '<S403>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Switch1_ac;

  /* Update for UnitDelay: '<S401>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch2_n;

  /* Update for UnitDelay: '<S383>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Switch4_fu;

  /* Update for UnitDelay: '<S398>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S398>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S398>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Switch4_fu;

  /* Update for UnitDelay: '<S382>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Switch1_c;

  /* Update for UnitDelay: '<S391>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S391>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S391>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Switch1_c;

  /* Update for UnitDelay: '<S357>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch1_dt;

  /* Update for UnitDelay: '<S356>/UD'
   *
   * Block description for '<S356>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch11;

  /* Update for UnitDelay: '<S368>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Init;

  /* Update for UnitDelay: '<S367>/UD'
   *
   * Block description for '<S367>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Switch2_ks;

  /* Update for UnitDelay: '<S353>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S294>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Add_pw;

  /* Update for UnitDelay: '<S293>/UD'
   *
   * Block description for '<S293>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Subtract1_bm;

  /* Update for UnitDelay: '<S305>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S304>/UD'
   *
   * Block description for '<S304>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Product_dq;

  /* Update for UnitDelay: '<S290>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_m;

  /* Update for UnitDelay: '<S315>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_uDLookupTable_d;

  /* Update for UnitDelay: '<S314>/UD'
   *
   * Block description for '<S314>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract_dr;

  /* Update for UnitDelay: '<S326>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Subtract_iu;

  /* Update for UnitDelay: '<S325>/UD'
   *
   * Block description for '<S325>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Hypot_b;

  /* Update for UnitDelay: '<S311>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S336>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S335>/UD'
   *
   * Block description for '<S335>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_Subtract_av;

  /* Update for UnitDelay: '<S347>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S346>/UD'
   *
   * Block description for '<S346>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_k;

  /* Update for UnitDelay: '<S332>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_g;

  /* Update for UnitDelay: '<S218>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_f1;

  /* Update for UnitDelay: '<S217>/UD'
   *
   * Block description for '<S217>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_ih;

  /* Update for UnitDelay: '<S216>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_c3;

  /* Update for UnitDelay: '<S155>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Compare_a3;

  /* Update for UnitDelay: '<S154>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kt = rtb_LogicalOperator5;

  /* Update for UnitDelay: '<S154>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_oa = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S213>/Delay Input1'
   *
   * Block description for '<S213>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Shooter_Motor_Gain_Ki;

  /* Update for UnitDelay: '<S214>/Delay Input1' incorporates:
   *  Constant: '<S154>/Constant4'
   *
   * Block description for '<S214>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_o = Rebuilt_Shooter_Motor_Gain_P;

  /* Update for UnitDelay: '<S143>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S143>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S58>/Delay Input1'
   *
   * Block description for '<S58>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S73>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S73>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S69>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_g;

  /* Update for UnitDelay: '<S68>/UD'
   *
   * Block description for '<S68>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_kv;

  /* Update for UnitDelay: '<S67>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S61>/Unit Delay' incorporates:
   *  Constant: '<S61>/Constant'
   *  Sum: '<S61>/Sum'
   *  Switch: '<S61>/Switch'
   */
  Robot_Control_DW.UnitDelay_DSTATE_eo = rtb_Add_ir + 0.02;

  /* Update for UnitDelay: '<S78>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_ei;

  /* Update for UnitDelay: '<S77>/UD'
   *
   * Block description for '<S77>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_gy;

  /* Update for UnitDelay: '<S76>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Subtract_c3;

  /* Update for UnitDelay: '<S62>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Intake_Arm_Move_In;
}

/* Model initialize function */
void Robot_Control_initialize(void)
{
  /* Start for SwitchCase: '<S1>/Switch Case' */
  Robot_Control_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S13>/If' */
  Robot_Control_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S147>/If' */
  Robot_Control_DW.If_ActiveSubsystem_n = -1;

  /* InitializeConditions for UnitDelay: '<S47>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S50>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S53>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S133>/Delay' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S381>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S398>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S391>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S143>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S73>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S462>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S226>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S222>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S226>/Robot_Index_Is_Valid' */
  /* Start for If: '<S229>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S229>/Circle_Check_Valid' */
  /* Start for If: '<S231>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S229>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S226>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S147>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S193>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S147>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S147>/If Action Subsystem1' */
  /* InitializeConditions for UnitDelay: '<S194>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_b2 = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S147>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S147>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S195>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S147>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S147>/If Action Subsystem3' */
  /* InitializeConditions for UnitDelay: '<S196>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gt = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S147>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S147>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S197>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S147>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S147>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S198>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S147>/If Action Subsystem5' */
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
