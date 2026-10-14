/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Tue Oct 13 21:49:47 2026
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

/* Named constants for Chart: '<S383>/Add dither' */
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
                                        * Referenced by: '<S162>/Constant2'
                                        */
real_T Blue_Hub_LeftY = 3.354;         /* Variable: Blue_Hub_LeftY
                                        * Referenced by: '<S162>/Constant3'
                                        */
real_T Blue_Hub_RightX = 5.1717;       /* Variable: Blue_Hub_RightX
                                        * Referenced by: '<S162>/Constant4'
                                        */
real_T Blue_Hub_RightY = 4.548;        /* Variable: Blue_Hub_RightY
                                        * Referenced by: '<S162>/Constant5'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S457>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S453>/Constant'
                                        *   '<S453>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S457>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S453>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S286>/Constant3'
                                        *   '<S307>/Constant3'
                                        *   '<S328>/Constant3'
                                        *   '<S349>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S286>/Constant2'
                                   *   '<S307>/Constant2'
                                   *   '<S328>/Constant2'
                                   *   '<S349>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S286>/Saturation'
                                        *   '<S307>/Saturation'
                                        *   '<S328>/Saturation'
                                        *   '<S349>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S286>/Saturation'
                                        *   '<S307>/Saturation'
                                        *   '<S328>/Saturation'
                                        *   '<S349>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S286>/Gain'
                                            *   '<S307>/Gain'
                                            *   '<S328>/Gain'
                                            *   '<S349>/Gain'
                                            */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S286>/Gain1'
                                        *   '<S307>/Gain1'
                                        *   '<S328>/Gain1'
                                        *   '<S349>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S291>/Constant'
                            *   '<S312>/Constant'
                            *   '<S333>/Constant'
                            *   '<S354>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S207>/BlueAllianceZoneX'
                                         *   '<S209>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S163>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S163>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S163>/Constant1'
                                        *   '<S163>/Switch3'
                                        *   '<S176>/If'
                                        */
real_T Field_Length = 17.557;          /* Variable: Field_Length
                                        * Referenced by: '<S162>/Constant10'
                                        */
real_T Field_Length_Half = 8.7785;     /* Variable: Field_Length_Half
                                        * Referenced by:
                                        *   '<S180>/Switch'
                                        *   '<S181>/Switch'
                                        */
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S163>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S163>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S208>/RedAllianceZoneX'
                                         *   '<S210>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S163>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S163>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S443>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S443>/Constant5'
                                          */
real_T Field_Width_Pass = 7.0692;      /* Variable: Field_Width_Pass
                                        * Referenced by: '<S162>/Constant11'
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
                                       * Referenced by: '<S178>/Constant'
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
                                          *   '<S156>/Constant3'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S139>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S139>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S66>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.008;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                          * Referenced by: '<S66>/Gain1'
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
                                            *   '<S55>/Constant'
                                            *   '<S62>/Constant'
                                            */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S63>/Constant'
                                            */
real_T Rebuilt_Intake_Meas_In_Disable = -20.0;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S64>/Constant'
                                      */
real_T Rebuilt_Intake_Meas_Out_Disable = 40.0;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S65>/Constant'
                                     */
real_T Rebuilt_Intake_RL_Dec = -3.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S59>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 3.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S59>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 30.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S192>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S196>/Constant3'
                                   *   '<S197>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S186>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S187>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S188>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S189>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S193>/Unit Delay'
                                      *   '<S194>/Unit Delay'
                                      *   '<S195>/Unit Delay'
                                      *   '<S196>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S193>/Constant2'
                                      *   '<S194>/Constant2'
                                      *   '<S195>/Constant2'
                                      *   '<S196>/Constant2'
                                      *   '<S200>/Constant'
                                      *   '<S201>/Constant'
                                      *   '<S202>/Constant'
                                      *   '<S203>/Constant'
                                      */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S183>/Constant'
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
                                * Referenced by: '<S61>/Constant1'
                                */
real_T Rebuilt_Roller_Intake_In_Delay = 2.0;
                                     /* Variable: Rebuilt_Roller_Intake_In_Delay
                                      * Referenced by: '<S73>/Constant'
                                      */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.00016534;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                                  * Referenced by: '<S75>/Gain'
                                                  */
real_T Rebuilt_Roller_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                             * Referenced by: '<S75>/Gain2'
                                             */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0001;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                             * Referenced by: '<S75>/Gain1'
                                             */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S164>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S164>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S164>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S164>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S164>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S164>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S164>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S164>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S159>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S159>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S159>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 3.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S159>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S159>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S159>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S159>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S159>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S160>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S160>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S160>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S160>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S160>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S160>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S160>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S160>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S151>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S151>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S151>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2725.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S173>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S173>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3265.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S173>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3425.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S173>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3625.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S173>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3775.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S173>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S173>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S173>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2825.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S172>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S172>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3365.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S172>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3525.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S172>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3725.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S172>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3875.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S172>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S172>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S172>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S166>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S166>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S166>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S166>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S166>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S166>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S166>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S166>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S170>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S153>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00015;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S12>/Constant1'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 0.03;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                            * Referenced by: '<S153>/Constant3'
                                            */
real_T Rebuilt_Shooter_Motor_Gain_I_Low = 0.0;
                                   /* Variable: Rebuilt_Shooter_Motor_Gain_I_Low
                                    * Referenced by: '<S153>/Constant9'
                                    */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.06;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                            * Referenced by: '<S153>/Constant4'
                                            */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S161>/Constant2'
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
                              * Referenced by: '<S154>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S215>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S215>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S215>/Gain1'
                                       */
real_T Red_Hub_LeftX = 11.369;         /* Variable: Red_Hub_LeftX
                                        * Referenced by: '<S162>/Constant6'
                                        */
real_T Red_Hub_LeftY = 4.548;          /* Variable: Red_Hub_LeftY
                                        * Referenced by: '<S162>/Constant7'
                                        */
real_T Red_Hub_RightX = 11.369;        /* Variable: Red_Hub_RightX
                                        * Referenced by: '<S162>/Constant8'
                                        */
real_T Red_Hub_RightY = 3.354;         /* Variable: Red_Hub_RightY
                                        * Referenced by: '<S162>/Constant9'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S442>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S440>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S442>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S443>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S443>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S275>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S275>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S222>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S235>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S275>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S382>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S382>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S382>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S382>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S382>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S382>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S400>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S400>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S400>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S400>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S399>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S400>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S400>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S400>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S400>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S400>/Constant1'
                                   *   '<S400>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S400>/Constant'
                                   *   '<S400>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S383>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S383>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S383>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S383>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S289>/Constant3'
                                        *   '<S310>/Constant3'
                                        *   '<S331>/Constant3'
                                        *   '<S352>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S289>/Constant2'
                                *   '<S310>/Constant2'
                                *   '<S331>/Constant2'
                                *   '<S352>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S289>/Saturation'
                                           *   '<S310>/Saturation'
                                           *   '<S331>/Saturation'
                                           *   '<S352>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S289>/Saturation'
                                          *   '<S310>/Saturation'
                                          *   '<S331>/Saturation'
                                          *   '<S352>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S289>/Gain2'
                                         *   '<S310>/Gain2'
                                         *   '<S331>/Gain2'
                                         *   '<S352>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S289>/Saturation1'
                                             *   '<S310>/Saturation1'
                                             *   '<S331>/Saturation1'
                                             *   '<S352>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S289>/Saturation1'
                                            *   '<S310>/Saturation1'
                                            *   '<S331>/Saturation1'
                                            *   '<S352>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S289>/Gain1'
                                        *   '<S310>/Gain1'
                                        *   '<S331>/Gain1'
                                        *   '<S352>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S381>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S381>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S381>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S381>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S381>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S381>/Constant3'
                                */
real_T Steering_Relative_Gain = 3.5;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S442>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S442>/Constant1'
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
                                      * Referenced by: '<S441>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S441>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S441>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S369>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S369>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S369>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S369>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S369>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S369>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S443>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S442>/Dead Zone'
                                        *   '<S443>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S442>/Dead Zone'
                                        *   '<S443>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S440>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S440>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S440>/Constant4'
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
                                        * Referenced by: '<S440>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S440>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S440>/Constant5'
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
                                        *   '<S440>/Constant11'
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
  real_T rtb_TmpSignalConversionAtLoo_cj[8];
  real_T rtb_TmpSignalConversionAtLoo_d0[8];
  real_T rtb_TmpSignalConversionAtLoo_fl[8];
  real_T rtb_TmpSignalConversionAtLoo_ga[8];
  real_T rtb_TmpSignalConversionAtLoo_mk[8];
  real_T rtb_Add2[2];
  real_T rtb_TmpSignalConversionAtLoo_mu[2];
  real_T rtb_TmpSignalConversionAtLookup[2];
  real_T rtb_Add_di;
  real_T rtb_Add_f1;
  real_T rtb_Add_ir;
  real_T rtb_Add_pw;
  real_T rtb_Error_n;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Integral_c3;
  real_T rtb_Integral_g;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_MatrixConcatenate_idx_0;
  real_T rtb_Merge1;
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
  real_T rtb_Subtract_c3;
  real_T rtb_Subtract_iu;
  real_T rtb_Subtract_j;
  real_T rtb_Sum1;
  real_T rtb_Sum1_ei;
  real_T rtb_Sum1_g;
  real_T rtb_Sum2_fc;
  real_T rtb_Sum2_m;
  real_T rtb_Switch1_c;
  real_T rtb_Switch1_jy;
  real_T rtb_Switch1_k;
  real_T rtb_Switch1_py;
  real_T rtb_Switch2_n;
  real_T rtb_Switch4_fu;
  real_T rtb_Switch8;
  real_T rtb_Switch_cn;
  real_T rtb_dy_n;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s247_iter;
  uint16_T s272_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T Iteration_Number;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4_j;
  boolean_T rtb_Button_Spinup_Enable;
  boolean_T rtb_Compare_bd;
  boolean_T rtb_Compare_cp;
  boolean_T rtb_Compare_ky;
  boolean_T rtb_Compare_mq;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_ms;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator2_e;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_Shooter_Active_prev;

  /* RelationalOperator: '<S38>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *  UnitDelay: '<S38>/Delay Input1'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Gamepad_B3_X >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S39>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *  UnitDelay: '<S39>/Delay Input1'
   *
   * Block description for '<S39>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets = (Robot_Control_U.Gamepad_B4_Y >
    Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S40>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *  UnitDelay: '<S40>/Delay Input1'
   *
   * Block description for '<S40>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Gamepad_B2_B >
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
    rtb_Subtract_c3 = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Subtract_c3 = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S46>/Init' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant2'
   *  Constant: '<S41>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Switch1_c = Rate_Limit_X;
  } else {
    rtb_Switch1_c = 1000.0;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Sum: '<S44>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Subtract_c3;

  /* Switch: '<S45>/Switch2' incorporates:
   *  RelationalOperator: '<S45>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Switch1_c)) {
    /* Switch: '<S41>/Switch1' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/Constant3'
     *  UnaryMinus: '<S41>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_py = -Rate_Limit_X;
    } else {
      rtb_Switch1_py = -1000.0;
    }

    /* End of Switch: '<S41>/Switch1' */

    /* Switch: '<S45>/Switch' incorporates:
     *  RelationalOperator: '<S45>/UpperRelop'
     */
    if (rtb_Sum1 < rtb_Switch1_py) {
      rtb_Switch1_c = rtb_Switch1_py;
    } else {
      rtb_Switch1_c = rtb_Sum1;
    }

    /* End of Switch: '<S45>/Switch' */
  }

  /* End of Switch: '<S45>/Switch2' */

  /* Sum: '<S44>/Sum' */
  rtb_Sum1 = rtb_Switch1_c + rtb_Subtract_c3;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S49>/Init' incorporates:
   *  UnitDelay: '<S49>/FixPt Unit Delay1'
   *  UnitDelay: '<S49>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_j != 0) {
    rtb_Switch1_c = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Switch1_c = Robot_Control_DW.FixPtUnitDelay1_DSTATE_a;
  }

  /* End of Switch: '<S49>/Init' */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Constant: '<S42>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_c3 = Rate_Limit_Y;
  } else {
    rtb_Subtract_c3 = 1000.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Sum: '<S47>/Sum1' */
  rtb_Switch1_py = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Switch1_c;

  /* Switch: '<S48>/Switch2' incorporates:
   *  RelationalOperator: '<S48>/LowerRelop1'
   */
  if (!(rtb_Switch1_py > rtb_Subtract_c3)) {
    /* Switch: '<S42>/Switch1' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant3'
     *  UnaryMinus: '<S42>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_jy = -Rate_Limit_Y;
    } else {
      rtb_Switch1_jy = -1000.0;
    }

    /* End of Switch: '<S42>/Switch1' */

    /* Switch: '<S48>/Switch' incorporates:
     *  RelationalOperator: '<S48>/UpperRelop'
     */
    if (rtb_Switch1_py < rtb_Switch1_jy) {
      rtb_Subtract_c3 = rtb_Switch1_jy;
    } else {
      rtb_Subtract_c3 = rtb_Switch1_py;
    }

    /* End of Switch: '<S48>/Switch' */
  }

  /* End of Switch: '<S48>/Switch2' */

  /* Sum: '<S47>/Sum' */
  rtb_Switch1_py = rtb_Subtract_c3 + rtb_Switch1_c;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S52>/Init' incorporates:
   *  UnitDelay: '<S52>/FixPt Unit Delay1'
   *  UnitDelay: '<S52>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Switch1_c = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Switch1_c = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S52>/Init' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Subtract_c3 = Rate_Limit_Z;
  } else {
    rtb_Subtract_c3 = 1000.0;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Sum: '<S50>/Sum1' */
  rtb_Switch1_jy = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Switch1_c;

  /* Switch: '<S51>/Switch2' incorporates:
   *  RelationalOperator: '<S51>/LowerRelop1'
   */
  if (!(rtb_Switch1_jy > rtb_Subtract_c3)) {
    /* Switch: '<S43>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant3'
     *  UnaryMinus: '<S43>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Subtract_c3 = -Rate_Limit_Z;
    } else {
      rtb_Subtract_c3 = -1000.0;
    }

    /* End of Switch: '<S43>/Switch1' */

    /* Switch: '<S51>/Switch' incorporates:
     *  RelationalOperator: '<S51>/UpperRelop'
     */
    if (!(rtb_Switch1_jy < rtb_Subtract_c3)) {
      rtb_Subtract_c3 = rtb_Switch1_jy;
    }

    /* End of Switch: '<S51>/Switch' */
  }

  /* End of Switch: '<S51>/Switch2' */

  /* Sum: '<S50>/Sum' */
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

  /* Logic: '<S35>/Logical Operator7' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   *  Inport: '<Root>/Joystick_Left_B5'
   */
  rtb_Compare_bd = ((Robot_Control_U.Joystick_Left_B2) ||
                    (Robot_Control_U.Joystick_Left_B5));

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
  rtb_Compare_ky = (fabs(rtb_Switch1_c) > 1.5707963267948966);

  /* Logic: '<S35>/Logical Operator1' */
  rtb_LogicalOperator1 = (rtb_Compare_bd && rtb_Compare_ky);

  /* Logic: '<S35>/Logical Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B3'
   *  Inport: '<Root>/Joystick_Left_B4'
   */
  rtb_Compare_mq = ((Robot_Control_U.Joystick_Left_B3) ||
                    (Robot_Control_U.Joystick_Left_B4));

  /* RelationalOperator: '<S35>/GreaterThan1' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  rtb_LogicalOperator2_e = (rtb_Switch1_c > 0.0);

  /* Logic: '<S35>/Logical Operator5' incorporates:
   *  Logic: '<S35>/Logical Operator6'
   */
  rtb_LogicalOperator5 = (rtb_Compare_mq && (!rtb_LogicalOperator2_e));

  /* Logic: '<S35>/Logical Operator3' */
  rtb_LogicalOperator2_e = (rtb_Compare_mq && rtb_LogicalOperator2_e);

  /* Logic: '<S35>/Logical Operator2' incorporates:
   *  Logic: '<S35>/Logical Operator4'
   */
  rtb_LogicalOperator2 = (rtb_Compare_bd && (!rtb_Compare_ky));

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

  /* If: '<S469>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S469>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S472>/Action Port'
     */
    /* Product: '<S472>/Product' incorporates:
     *  Constant: '<S472>/Constant1'
     *  Constant: '<S472>/Constant2'
     *  Math: '<S472>/Math Function'
     */
    rtb_Switch1_c = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S469>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S469>/Subsystem' incorporates:
     *  ActionPort: '<S473>/Action Port'
     */
    /* SignalConversion generated from: '<S473>/Out1' incorporates:
     *  Constant: '<S473>/Constant'
     */
    rtb_Switch1_c = 0.0;

    /* End of Outputs for SubSystem: '<S469>/Subsystem' */
  }

  /* End of If: '<S469>/If' */

  /* Gain: '<S470>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Subtract_c3 = 0.017453292519943295 *
    Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S471>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Switch1_c * cos
    (rtb_Subtract_c3)) + Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S471>/theta->y'
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
  rtb_Add_ir = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_ir)) || (rtIsInf(rtb_Add_ir))) {
    rtb_Add_ir = 0.0;
  } else {
    rtb_Add_ir = fmod(rtb_Add_ir, 4.294967296E+9);
  }

  switch ((rtb_Add_ir < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_ir)))) :
          ((int32_T)((uint32_T)rtb_Add_ir))) {
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
    rtb_Compare_bd = false;

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
    rtb_Shooter_Active_prev = false;

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
      rtb_Subtract_c3 = 0.0;
    } else {
      rtb_Subtract_c3 = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
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
    rtb_LogicalOperator2_e = (Robot_Control_DW.UnitDelay1_DSTATE_k == 5.0);

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
    if (((int32_T)rtb_LogicalOperator2_e) > ((int32_T)
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
      rtb_Shooter_Active_prev = (rtb_Subtract_c3 >= Auto_Shoot_Time);
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S19>/Switch3' incorporates:
       *  Constant: '<S26>/Constant'
       *  RelationalOperator: '<S26>/Compare'
       *  Switch: '<S19>/Switch6'
       */
      rtb_Shooter_Active_prev = (rtb_Switch2_n >= Auto_Deploy_Intake_Time);
    } else if (rtb_LogicalOperator2_e) {
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
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) + 39];
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
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
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
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        } else if (rtb_Saturation_h > Robot_Control_DW.UnitDelay_DSTATE_e3) {
          Robot_Control_DW.is_c1_Robot_Control = Robot_Control_IN_Follow_Path;
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
          Robot_Control_DW.is_c1_Robot_Control = Robot_Control_IN_Follow_Path;
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
      rtb_Switch1_k = 0.0;
    } else {
      rtb_Switch1_k = Robot_Control_DW.UnitDelay_DSTATE_h + 0.02;
    }

    /* End of Switch: '<S22>/Switch1' */

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S33>/Constant'
     *  RelationalOperator: '<S33>/Compare'
     */
    rtb_Shooter_Active_prev = ((rtb_Switch1_k >=
      Auto_Intake_Arm_Cycle_Delay_Time) && rtb_LogicalOperator2);

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
      rtb_Compare_bd = false;

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
      rtb_Compare_bd = false;

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
      rtb_Compare_bd = true;

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
      rtb_Compare_bd = false;

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

     case 4:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant3'
       *  Constant: '<S22>/Constant8'
       */
      rtb_Compare_bd = false;

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

     default:
      rtb_Button_Spinup_Enable = false;

      /* MultiPortSwitch: '<S22>/Multiport Switch1' incorporates:
       *  Constant: '<S22>/Constant3'
       *  Constant: '<S22>/Constant8'
       */
      rtb_Compare_bd = false;

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
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Subtract_c3;

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
    Robot_Control_DW.DelayInput1_DSTATE_or = rtb_LogicalOperator2_e;

    /* Update for UnitDelay: '<S19>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE_i = rtb_Switch4_fu;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S34>/Delay Input1'
     *
     * Block description for '<S34>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_gf = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S22>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_h = rtb_Switch1_k;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S442>/Unit Delay1'
       *  UnitDelay: '<S442>/Unit Delay2'
       *  UnitDelay: '<S442>/Unit Delay3'
       *  UnitDelay: '<S442>/Unit Delay4'
       *  UnitDelay: '<S445>/Delay Input1'
       *  UnitDelay: '<S446>/Delay Input1'
       *  UnitDelay: '<S447>/Delay Input1'
       *  UnitDelay: '<S448>/Delay Input1'
       *  UnitDelay: '<S450>/Delay Input1'
       *  UnitDelay: '<S456>/Unit Delay'
       *  UnitDelay: '<S456>/Unit Delay1'
       *  UnitDelay: '<S460>/FixPt Unit Delay1'
       *  UnitDelay: '<S460>/FixPt Unit Delay2'
       *
       * Block description for '<S445>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S446>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S447>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S448>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S450>/Delay Input1':
       *
       *  Store in Global RAM
       */
      Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;
      Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_l = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_p = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_jp = false;
      Robot_Control_DW.DelayInput1_DSTATE_m = false;
      Robot_Control_DW.DelayInput1_DSTATE_k = false;
      Robot_Control_DW.DelayInput1_DSTATE_g = false;
      Robot_Control_DW.DelayInput1_DSTATE_g2 = false;
      Robot_Control_DW.UnitDelay2_DSTATE_l = false;
      Robot_Control_DW.UnitDelay4_DSTATE = false;
      Robot_Control_DW.UnitDelay3_DSTATE = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_j2 = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Teleop' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* SignalConversion generated from: '<S15>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

    /* SignalConversion generated from: '<S453>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S453>/X1_Values'
     *  Constant: '<S453>/X_values'
     */
    rtb_TmpSignalConversionAtLookup[0] = 0.0;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S453>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S453>/Constant'
     *  Constant: '<S453>/Constant1'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = Boost_Trigger_Low_Speed;
    rtb_TmpSignalConversionAtLoo_mu[1] = Boost_Trigger_High_Speed;

    /* S-Function (sfix_look1_dyn): '<S453>/Lookup Table Dynamic' incorporates:
     *  Inport: '<Root>/Joystick_Left_B1'
     */
    /* Dynamic Look-Up Table Block: '<S453>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_Saturation_h), &rtb_TmpSignalConversionAtLoo_mu
                         [0], Robot_Control_U.Joystick_Left_B1,
                         &rtb_TmpSignalConversionAtLookup[0], 1U);

    /* Switch: '<S460>/Init' incorporates:
     *  UnitDelay: '<S460>/FixPt Unit Delay1'
     *  UnitDelay: '<S460>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Subtract_c3 = rtb_Saturation_h;
    } else {
      rtb_Subtract_c3 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S460>/Init' */

    /* Sum: '<S458>/Sum1' */
    rtb_Saturation_h -= rtb_Subtract_c3;

    /* Switch: '<S459>/Switch2' incorporates:
     *  Constant: '<S457>/Constant1'
     *  Constant: '<S457>/Constant3'
     *  RelationalOperator: '<S459>/LowerRelop1'
     *  RelationalOperator: '<S459>/UpperRelop'
     *  Switch: '<S459>/Switch'
     */
    if (rtb_Saturation_h > Boost_Trigger_Increasing_Limit) {
      rtb_Saturation_h = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Saturation_h < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S459>/Switch' incorporates:
       *  Constant: '<S457>/Constant1'
       */
      rtb_Saturation_h = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S459>/Switch2' */

    /* Sum: '<S458>/Sum' */
    rtb_Switch2_n = rtb_Saturation_h + rtb_Subtract_c3;

    /* Lookup_n-D: '<S443>/Modulation_Drv' incorporates:
     *  Math: '<S443>/Magnitude'
     */
    rtb_Switch4_fu = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_py),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S454>/Compare' incorporates:
     *  Constant: '<S454>/Constant'
     */
    rtb_LogicalOperator1_ms = (rtb_Switch4_fu == 0.0);

    /* Logic: '<S440>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S440>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S443>/Dead Zone' */
    if (rtb_Switch1_jy > Twist_Deadzone_pos) {
      rtb_Saturation_h = rtb_Switch1_jy - Twist_Deadzone_pos;
    } else if (rtb_Switch1_jy >= Twist_Deadzone_neg) {
      rtb_Saturation_h = 0.0;
    } else {
      rtb_Saturation_h = rtb_Switch1_jy - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S443>/Dead Zone' */

    /* Logic: '<S443>/Logical Operator' incorporates:
     *  Constant: '<S455>/Constant'
     *  RelationalOperator: '<S455>/Compare'
     */
    rtb_Intake_Arm_Move_In = ((rtb_Saturation_h != 0.0) &&
      rtb_LogicalOperator1_ms);

    /* Switch: '<S440>/Switch2' incorporates:
     *  Constant: '<S440>/Constant2'
     *  Constant: '<S464>/Constant'
     *  Constant: '<S467>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S464>/Compare'
     *  RelationalOperator: '<S467>/Compare'
     *  Sum: '<S440>/Subtract'
     *  Switch: '<S440>/Switch'
     *  Switch: '<S440>/Switch1'
     *  Switch: '<S440>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S440>/Switch2' incorporates:
       *  Constant: '<S440>/Constant5'
       *  Sum: '<S440>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Subtract_c3 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S440>/Switch2' incorporates:
       *  Constant: '<S440>/Constant4'
       *  Sum: '<S440>/Subtract2'
       *  Switch: '<S440>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S440>/Switch1' incorporates:
       *  Constant: '<S440>/Constant1'
       *  Sum: '<S440>/Subtract3'
       */
      rtb_Subtract_c3 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S440>/Switch2' incorporates:
       *  Constant: '<S440>/Constant3'
       *  Switch: '<S440>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S440>/Switch1' incorporates:
       *  Constant: '<S440>/Constant'
       */
      rtb_Subtract_c3 = 0.0;
    }

    /* End of Switch: '<S440>/Switch2' */

    /* UnaryMinus: '<S440>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Subtract_c3;

    /* Switch: '<S443>/Switch8' incorporates:
     *  Logic: '<S443>/Logical Operator1'
     *  Switch: '<S443>/Switch2'
     */
    if (rtb_Intake_Arm_Move_In) {
      /* Switch: '<S443>/Switch' incorporates:
       *  Gain: '<S443>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain *
        rtb_Saturation_h;
    } else if (rtb_LogicalOperator1_ms) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S443>/Constant5'
       *  Gain: '<S443>/Gain2'
       *  Math: '<S443>/Magnitude1'
       *  MinMax: '<S443>/Min'
       *  Switch: '<S443>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S453>/Product' incorporates:
       *  Switch: '<S443>/Switch2'
       */
      rtb_Add_di = rtb_Switch4_fu * rtb_Switch2_n;

      /* Saturate: '<S453>/Saturation' incorporates:
       *  Switch: '<S443>/Switch2'
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

      /* End of Saturate: '<S453>/Saturation' */
    }

    /* End of Switch: '<S443>/Switch8' */

    /* Switch: '<S456>/Switch1' incorporates:
     *  Constant: '<S461>/Constant'
     *  Constant: '<S462>/Constant'
     *  Logic: '<S456>/AND'
     *  RelationalOperator: '<S461>/Compare'
     *  RelationalOperator: '<S462>/Compare'
     *  Switch: '<S456>/Switch2'
     *  UnitDelay: '<S456>/Unit Delay'
     *  UnitDelay: '<S456>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_py == 0.0)) {
      rtb_Switch4_fu = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch1_c = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch4_fu = rtb_Switch1_py;
      rtb_Switch1_c = rtb_Sum1;
    }

    /* End of Switch: '<S456>/Switch1' */

    /* Switch: '<S443>/Switch1' incorporates:
     *  Logic: '<S443>/Logical Operator1'
     *  Switch: '<S443>/Switch4'
     *  Switch: '<S443>/Switch9'
     */
    if (rtb_Intake_Arm_Move_In) {
      /* Signum: '<S443>/Sign' */
      if (rtIsNaN(rtb_Saturation_h)) {
        rtb_Add_ir = (rtNaN);
      } else if (rtb_Saturation_h < 0.0) {
        rtb_Add_ir = -1.0;
      } else {
        rtb_Add_ir = (rtb_Saturation_h > 0.0);
      }

      /* Switch: '<S443>/Switch5' incorporates:
       *  Constant: '<S443>/Constant3'
       *  Constant: '<S443>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_di = -1.5707963267948966;
      } else {
        rtb_Add_di = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S443>/Gain3'
       *  Signum: '<S443>/Sign'
       *  Sum: '<S443>/Add'
       *  Switch: '<S443>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.141592653589793 * rtb_Add_ir) +
        rtb_Add_di;
    } else if (rtb_LogicalOperator1_ms) {
      /* Switch: '<S443>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S443>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S443>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S443>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.141592653589793;
      }

      /* End of Switch: '<S443>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S443>/Switch4'
       *  Trigonometry: '<S443>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch4_fu,
        rtb_Switch1_c);
    }

    /* End of Switch: '<S443>/Switch1' */

    /* Switch: '<S441>/Switch' incorporates:
     *  Constant: '<S441>/Constant5'
     *  Constant: '<S441>/Constant7'
     *  DataTypeConversion: '<S441>/Data Type Conversion'
     *  Logic: '<S443>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_ky = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Compare_ky = !rtb_Intake_Arm_Move_In;
    }

    /* End of Switch: '<S441>/Switch' */

    /* Switch: '<S440>/Switch4' incorporates:
     *  Constant: '<S465>/Constant'
     *  Constant: '<S468>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S465>/Compare'
     *  RelationalOperator: '<S468>/Compare'
     *  Switch: '<S440>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S440>/Switch4' incorporates:
       *  Constant: '<S440>/Constant8'
       *  Sum: '<S440>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S440>/Switch5' incorporates:
       *  Constant: '<S440>/Constant7'
       *  Gain: '<S440>/Gain'
       *  Sum: '<S440>/Subtract5'
       *  Switch: '<S440>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S440>/Switch4' incorporates:
       *  Constant: '<S440>/Constant6'
       *  Switch: '<S440>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S440>/Switch4' */

    /* DeadZone: '<S442>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_ir = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_ir = 0.0;
    } else {
      rtb_Add_ir = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S442>/Add' incorporates:
     *  Constant: '<S442>/Constant'
     *  Constant: '<S442>/Constant1'
     *  DeadZone: '<S442>/Dead Zone'
     *  Lookup_n-D: '<S442>/Modulation_Str_Y_Rel'
     *  Product: '<S442>/Product'
     *  Product: '<S442>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Subtract_c3 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                       Steering_Relative_Gain) + (rtb_Add_ir *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S444>/Compare' incorporates:
     *  Constant: '<S444>/Constant'
     */
    rtb_Compare_cp = (rtb_Subtract_c3 == 0.0);

    /* Switch: '<S441>/Switch1' incorporates:
     *  Constant: '<S441>/Constant5'
     *  Constant: '<S441>/Constant8'
     *  DataTypeConversion: '<S441>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_mq = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Compare_mq = rtb_Compare_cp;
    }

    /* End of Switch: '<S441>/Switch1' */

    /* Logic: '<S442>/AND2' incorporates:
     *  RelationalOperator: '<S445>/FixPt Relational Operator'
     *  RelationalOperator: '<S446>/FixPt Relational Operator'
     *  RelationalOperator: '<S447>/FixPt Relational Operator'
     *  RelationalOperator: '<S448>/FixPt Relational Operator'
     *  UnitDelay: '<S445>/Delay Input1'
     *  UnitDelay: '<S446>/Delay Input1'
     *  UnitDelay: '<S447>/Delay Input1'
     *  UnitDelay: '<S448>/Delay Input1'
     *
     * Block description for '<S445>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S446>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S447>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S448>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_LogicalOperator1_ms = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)
      rtb_LogicalOperator2_e) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k)))
      || (((int32_T)rtb_LogicalOperator1) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g))) || (((int32_T)
      rtb_LogicalOperator5) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S442>/AND1' incorporates:
     *  Logic: '<S442>/AND3'
     *  UnitDelay: '<S442>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_cp && (rtb_LogicalOperator1_ms ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S442>/AND4' incorporates:
     *  Logic: '<S442>/AND8'
     *  UnitDelay: '<S442>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_cp && (!rtb_LogicalOperator1_ms)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S442>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* UnitDelay: '<S442>/Unit Delay3' */
    rtb_Saturation_h = Robot_Control_DW.UnitDelay3_DSTATE;

    /* Switch: '<S442>/Switch8' incorporates:
     *  Constant: '<S451>/Constant'
     *  Logic: '<S442>/AND9'
     *  RelationalOperator: '<S450>/FixPt Relational Operator'
     *  RelationalOperator: '<S451>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S450>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S450>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_cp) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_jp)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_DW.UnitDelay1_DSTATE_nl)) {
      /* Switch: '<S442>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S442>/Switch8' */
      Robot_Control_B.Steering_Abs_Gyro_Latch = rtb_Saturation_h;
    }

    /* End of Switch: '<S442>/Switch8' */

    /* Switch: '<S442>/Switch4' incorporates:
     *  Constant: '<S442>/Constant5'
     *  Switch: '<S442>/Switch1'
     *  Switch: '<S442>/Switch5'
     *  Switch: '<S442>/Switch6'
     *  Switch: '<S442>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Saturation_h = 0.0;
    } else if (rtb_LogicalOperator2_e) {
      /* Switch: '<S442>/Switch5' incorporates:
       *  Constant: '<S442>/Constant6'
       */
      rtb_Saturation_h = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S442>/Switch6' incorporates:
       *  Constant: '<S442>/Constant7'
       *  Switch: '<S442>/Switch5'
       */
      rtb_Saturation_h = 3.141592653589793;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S442>/Switch7' incorporates:
       *  Constant: '<S442>/Constant8'
       *  Switch: '<S442>/Switch5'
       *  Switch: '<S442>/Switch6'
       */
      rtb_Saturation_h = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S442>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S442>/Switch5'
       *  Switch: '<S442>/Switch6'
       *  Switch: '<S442>/Switch7'
       */
      rtb_Saturation_h = 0.0;
    } else {
      /* Switch: '<S442>/Switch6' incorporates:
       *  Switch: '<S442>/Switch5'
       *  Switch: '<S442>/Switch7'
       *  UnitDelay: '<S442>/Unit Delay1'
       */
      rtb_Saturation_h = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S442>/Switch4' */

    /* Switch: '<S442>/Switch2' incorporates:
     *  Switch: '<S442>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S442>/Switch2' incorporates:
       *  Constant: '<S442>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S442>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Saturation_h;
    } else {
      /* Switch: '<S442>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S442>/Switch3' incorporates:
       *  Constant: '<S442>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S442>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S442>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S442>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Subtract_c3;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S440>/Constant11'
     *  Switch: '<S440>/Switch6'
     *  Switch: '<S440>/Switch7'
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

    /* RelationalOperator: '<S436>/Compare' incorporates:
     *  Constant: '<S436>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S437>/Compare' incorporates:
     *  Constant: '<S437>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Compare_bd = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S432>/Compare' incorporates:
     *  Constant: '<S432>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S435>/Compare' incorporates:
     *  Constant: '<S435>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S434>/Compare' incorporates:
     *  Constant: '<S434>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Shooter_Active_prev = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Constant: '<S433>/Constant'
     *  Constant: '<S438>/Constant'
     *  Inport: '<Root>/Gamepad_LT'
     *  Inport: '<Root>/Joystick_Right_B1'
     *  RelationalOperator: '<S433>/Compare'
     *  RelationalOperator: '<S438>/Compare'
     */
    rtb_LogicalOperator1_ms = ((Robot_Control_U.Joystick_Right_B1 != 0.0) ||
      (Robot_Control_U.Gamepad_LT != 0.0));

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     *  SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Update for UnitDelay: '<S460>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S460>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S460>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Switch2_n;

    /* Update for UnitDelay: '<S456>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch4_fu;

    /* Update for UnitDelay: '<S456>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch1_c;

    /* Update for UnitDelay: '<S450>/Delay Input1'
     *
     * Block description for '<S450>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_jp = rtb_Compare_cp;

    /* Update for UnitDelay: '<S449>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S449>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S445>/Delay Input1'
     *
     * Block description for '<S445>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S446>/Delay Input1'
     *
     * Block description for '<S446>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_LogicalOperator2_e;

    /* Update for UnitDelay: '<S447>/Delay Input1'
     *
     * Block description for '<S447>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S448>/Delay Input1'
     *
     * Block description for '<S448>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S442>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S442>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S442>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S442>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Saturation_h;

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
    rtb_Compare_bd = false;

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
    rtb_Shooter_Active_prev = false;

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

  /* Reshape: '<S79>/Reshape3' incorporates:
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_X'
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_Y'
   *  S-Function (sfix_udelay): '<S8>/Tapped Delay'
   *  S-Function (sfix_udelay): '<S8>/Tapped Delay1'
   *  Sum: '<S8>/Add'
   *  Sum: '<S8>/Add1'
   */
  rtb_TmpSignalConversionAtLookup[0] =
    (Robot_Control_U.Vision_RobotPoseFieldSpace_X +
     Robot_Control_DW.TappedDelay_X[0]) + Robot_Control_DW.TappedDelay_X[1];
  rtb_TmpSignalConversionAtLookup[1] =
    (Robot_Control_U.Vision_RobotPoseFieldSpace_Y +
     Robot_Control_DW.TappedDelay1_X[0]) + Robot_Control_DW.TappedDelay1_X[1];

  /* Delay: '<S132>/Delay' incorporates:
   *  Constant: '<S79>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.Delay_DSTATE[0] = 0.0;
    Robot_Control_DW.Delay_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S114>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S115>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S131>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S133>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S133>/Sum' incorporates:
     *  Constant: '<S79>/C'
     *  Delay: '<S132>/Delay'
     *  Product: '<S133>/C[k]*xhat[k|k-1]'
     *  Reshape: '<S79>/Reshape3'
     *  Sum: '<S133>/Add1'
     */
    rtb_Saturation_h = rtb_TmpSignalConversionAtLookup[0] - ((0.0 *
      Robot_Control_DW.Delay_DSTATE[1]) + Robot_Control_DW.Delay_DSTATE[0]);
    rtb_Subtract_c3 = rtb_TmpSignalConversionAtLookup[1] - ((0.0 *
      Robot_Control_DW.Delay_DSTATE[0]) + Robot_Control_DW.Delay_DSTATE[1]);

    /* Product: '<S133>/Product3' incorporates:
     *  Constant: '<S127>/Constant'
     *  Product: '<S115>/Product2'
     */
    rtb_Switch2_n = 0.09512492197250398 * rtb_Saturation_h;
    Robot_Control_B.Product3[0] = rtb_Switch2_n;
    Robot_Control_B.Product3[1] = 6.209845451961181E-17 * rtb_Saturation_h;
    Robot_Control_B.Product3[0] += -2.0399807945617856E-17 * rtb_Subtract_c3;
    Robot_Control_B.Product3[1] += 0.09512492197250422 * rtb_Subtract_c3;

    /* Product: '<S115>/Product2' incorporates:
     *  Constant: '<S127>/Constant1'
     *  Sum: '<S115>/Add1'
     */
    Robot_Control_B.Product2[0] = rtb_Switch2_n;
    Robot_Control_B.Product2[1] = 2.580507006221294E-17 * rtb_Saturation_h;
    Robot_Control_B.Product2[0] += 2.5805070062212937E-17 * rtb_Subtract_c3;
    Robot_Control_B.Product2[1] += 0.09512492197250424 * rtb_Subtract_c3;
  } else if (Robot_Control_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S133>/Product3' incorporates:
     *  Outport: '<S133>/L*(y[k]-yhat[k|k-1])'
     */
    Robot_Control_B.Product3[0] = 0.0;
    Robot_Control_B.Product3[1] = 0.0;
    Robot_Control_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S131>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S114>/Enabled Subsystem' */

  /* Sum: '<S114>/Add' incorporates:
   *  Delay: '<S132>/Delay'
   *  Product: '<S115>/Product2'
   */
  rtb_TmpSignalConversionAtLookup[0] = Robot_Control_B.Product2[0] +
    Robot_Control_DW.Delay_DSTATE[0];
  rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.Product2[1] +
    Robot_Control_DW.Delay_DSTATE[1];

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Switch: '<S8>/Switch1'
   */
  if (KF_Enable != 0.0) {
    /* Switch: '<S8>/Switch' */
    Robot_Control_B.KF_Position_X = rtb_TmpSignalConversionAtLookup[0];

    /* Switch: '<S8>/Switch1' */
    Robot_Control_B.KF_Position_Y = rtb_TmpSignalConversionAtLookup[1];
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
   *  Constant: '<S272>/Constant'
   *  Logic: '<S272>/AND'
   *  MATLAB Function: '<S222>/Find closest index to curve'
   *  Product: '<S272>/Product'
   *  RelationalOperator: '<S272>/Relational Operator'
   *  RelationalOperator: '<S272>/Relational Operator1'
   *  Selector: '<S272>/Selector'
   *  Selector: '<S272>/Selector1'
   *  Selector: '<S273>/Selector'
   *  Sum: '<S272>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S225>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S228>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S230>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S225>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S220>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S220>/Unit Delay'
       *  UnitDelay: '<S221>/Unit Delay'
       *  UnitDelay: '<S223>/Unit Delay'
       *  UnitDelay: '<S223>/Unit Delay1'
       *  UnitDelay: '<S273>/Unit Delay'
       *  UnitDelay: '<S273>/Unit Delay1'
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
     *  ActionPort: '<S220>/Action Port'
     */
    /* Selector: '<S221>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    memcpy(&rtb_Ref_Poses[0], &rtb_Spline_Ref_Poses_h[0], 10U * (sizeof(real_T)));
    memcpy(&rtb_Ref_Poses[10], &rtb_Spline_Ref_Poses_h[10], 10U * (sizeof(real_T)));

    /* Lookup_n-D: '<S220>/Capture Radius' incorporates:
     *  UnitDelay: '<S220>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S221>/Matrix Concatenate2' */
    rtb_TmpSignalConversionAtLookup[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S221>/Matrix Concatenate2' */
    rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S225>/If' incorporates:
     *  RelationalOperator: '<S225>/ '
     *  UnitDelay: '<S221>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S228>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S230>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S225>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S228>/Action Port'
       */
      /* InitializeConditions for If: '<S225>/If' incorporates:
       *  UnitDelay: '<S228>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S225>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S225>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S228>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S228>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S231>/Action Port'
       */
      /* If: '<S228>/If' incorporates:
       *  Selector: '<S221>/Selector1'
       *  Selector: '<S228>/Selector'
       *  Selector: '<S231>/Selector'
       */
      rtb_Switch1_k = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S228>/Increment_If_Rectangle_Check' */

      /* Sum: '<S228>/Minus' incorporates:
       *  Concatenate: '<S221>/Matrix Concatenate2'
       *  Selector: '<S228>/Selector'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = rtb_TmpSignalConversionAtLookup[0] -
        rtb_Switch1_k;

      /* Outputs for IfAction SubSystem: '<S228>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S231>/Action Port'
       */
      /* If: '<S228>/If' incorporates:
       *  Selector: '<S221>/Selector1'
       *  Selector: '<S228>/Selector'
       *  Selector: '<S231>/Selector'
       *  Sum: '<S228>/Minus'
       */
      rtb_Switch1_c = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S228>/Increment_If_Rectangle_Check' */

      /* Sum: '<S228>/Minus' incorporates:
       *  Concatenate: '<S221>/Matrix Concatenate2'
       *  Selector: '<S228>/Selector'
       */
      rtb_TmpSignalConversionAtLoo_mu[1] = rtb_TmpSignalConversionAtLookup[1] -
        rtb_Switch1_c;

      /* Math: '<S228>/Hypot' */
      rtb_Subtract_c3 = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu[0],
        rtb_TmpSignalConversionAtLoo_mu[1]);

      /* RelationalOperator: '<S228>/Equal' */
      rtb_LogicalOperator1 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S228>/Switch' incorporates:
       *  Logic: '<S228>/AND'
       *  Logic: '<S228>/OR'
       *  RelationalOperator: '<S228>/Relational Operator'
       *  UnitDelay: '<S228>/Unit Delay'
       */
      rtb_LogicalOperator5 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Subtract_c3 <= rtb_Saturation_h) && rtb_LogicalOperator1));

      /* If: '<S228>/If' */
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
        /* Disable for If: '<S230>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S228>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S230>/Action Port'
         */
        /* If: '<S230>/If' incorporates:
         *  RelationalOperator: '<S230>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S230>/Is_Last_Point' incorporates:
           *  ActionPort: '<S233>/Action Port'
           */
          /* InitializeConditions for If: '<S230>/If' incorporates:
           *  UnitDelay: '<S233>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S230>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S230>/Is_Last_Point' incorporates:
           *  ActionPort: '<S233>/Action Port'
           */
          /* Switch: '<S233>/Switch' incorporates:
           *  Constant: '<S235>/Constant'
           *  Logic: '<S233>/OR'
           *  RelationalOperator: '<S235>/Compare'
           *  UnitDelay: '<S233>/Unit Delay'
           */
          rtb_Compare_ky = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
                            (rtb_Subtract_c3 <= Spline_Stop_Radius));

          /* If: '<S233>/If' */
          if (rtb_Compare_ky) {
            /* Outputs for IfAction SubSystem: '<S233>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S236>/Action Port'
             */
            /* Merge: '<S225>/Merge2' incorporates:
             *  Constant: '<S236>/Constant'
             *  SignalConversion generated from: '<S236>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator1 = true;

            /* SignalConversion generated from: '<S236>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S236>/Constant1'
             */
            rtb_LogicalOperator2_e = false;

            /* End of Outputs for SubSystem: '<S233>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S233>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S237>/Action Port'
             */
            /* Merge: '<S225>/Merge2' incorporates:
             *  Constant: '<S237>/Constant'
             *  SignalConversion generated from: '<S237>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator1 = false;

            /* SignalConversion generated from: '<S237>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S237>/Constant1'
             */
            rtb_LogicalOperator2_e = true;

            /* End of Outputs for SubSystem: '<S233>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S233>/If' */

          /* Merge: '<S225>/Merge4' incorporates:
           *  SignalConversion: '<S233>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S233>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Compare_ky;

          /* End of Outputs for SubSystem: '<S230>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S230>/Increment_Search' incorporates:
           *  ActionPort: '<S232>/Action Port'
           */
          /* Merge: '<S225>/Merge2' incorporates:
           *  Constant: '<S232>/Constant'
           *  SignalConversion generated from: '<S232>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator1 = false;

          /* SignalConversion generated from: '<S232>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S232>/Constant1'
           */
          rtb_LogicalOperator2_e = false;

          /* Merge: '<S225>/Merge4' incorporates:
           *  Constant: '<S234>/FixPt Constant'
           *  SignalConversion: '<S232>/Signal Copy'
           *  Sum: '<S234>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S230>/Increment_Search' */
        }

        /* End of If: '<S230>/If' */
        /* End of Outputs for SubSystem: '<S228>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S228>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S231>/Action Port'
         */
        /* Sum: '<S238>/FixPt Sum1' incorporates:
         *  Constant: '<S238>/FixPt Constant'
         */
        rtb_Switch2_n = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S231>/Selector1' incorporates:
         *  Selector: '<S221>/Selector1'
         */
        rtb_dy_n = rtb_Ref_Poses[((int32_T)rtb_Switch2_n) - 1];

        /* Sum: '<S239>/Subtract' incorporates:
         *  Selector: '<S231>/Selector1'
         *  Sum: '<S239>/Minus1'
         */
        rtb_TmpSignalConversionAtLoo_mu[0] = rtb_dy_n - rtb_Switch1_k;

        /* Selector: '<S231>/Selector1' incorporates:
         *  Selector: '<S221>/Selector1'
         */
        rtb_Switch8 = rtb_Ref_Poses[((int32_T)rtb_Switch2_n) + 9];

        /* Sum: '<S239>/Subtract' incorporates:
         *  Selector: '<S231>/Selector1'
         *  Sum: '<S239>/Minus1'
         */
        rtb_TmpSignalConversionAtLoo_mu[1] = rtb_Switch8 - rtb_Switch1_c;

        /* Math: '<S239>/Hypot' */
        rtb_Subtract_c3 = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu[0],
          rtb_TmpSignalConversionAtLoo_mu[1]);

        /* Product: '<S239>/Divide' */
        rtb_Switch2_n = rtb_TmpSignalConversionAtLoo_mu[1];

        /* UnaryMinus: '<S239>/Unary Minus' */
        rtb_Switch4_fu = rtb_TmpSignalConversionAtLoo_mu[0];

        /* Product: '<S239>/Product' incorporates:
         *  Product: '<S239>/Divide'
         *  UnaryMinus: '<S239>/Unary Minus'
         */
        rtb_TmpSignalConversionAtLoo_mu[0] = (rtb_Switch2_n / rtb_Subtract_c3) *
          rtb_Saturation_h;
        rtb_TmpSignalConversionAtLoo_mu[1] = ((-rtb_Switch4_fu) /
          rtb_Subtract_c3) * rtb_Saturation_h;

        /* Sum: '<S239>/Add1' incorporates:
         *  Sum: '<S239>/Add2'
         *  Sum: '<S239>/Minus'
         */
        rtb_Switch4_fu = rtb_dy_n - rtb_TmpSignalConversionAtLoo_mu[0];

        /* Sum: '<S239>/Minus4' incorporates:
         *  Sum: '<S239>/Add2'
         *  Sum: '<S239>/Minus'
         */
        rtb_dy_n = (rtb_dy_n + rtb_TmpSignalConversionAtLoo_mu[0]) -
          rtb_Switch4_fu;

        /* Sum: '<S239>/Minus5' incorporates:
         *  Concatenate: '<S221>/Matrix Concatenate2'
         *  Sum: '<S239>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_TmpSignalConversionAtLookup[0] -
          rtb_Switch4_fu;

        /* Sum: '<S239>/Add' incorporates:
         *  Sum: '<S239>/Add2'
         *  Sum: '<S239>/Minus1'
         */
        rtb_Switch2_n = rtb_Switch1_k - rtb_TmpSignalConversionAtLoo_mu[0];

        /* Sum: '<S239>/Minus' incorporates:
         *  Sum: '<S239>/Minus1'
         */
        rtb_Switch4_fu -= rtb_Switch2_n;

        /* DotProduct: '<S239>/Dot Product' incorporates:
         *  Concatenate: '<S221>/Matrix Concatenate2'
         *  Sum: '<S239>/Minus'
         *  Sum: '<S239>/Minus1'
         *  Sum: '<S239>/Minus5'
         */
        rtb_Subtract_c3 = (rtb_TmpSignalConversionAtLookup[0] - rtb_Switch2_n) *
          rtb_Switch4_fu;

        /* Sum: '<S239>/Add1' incorporates:
         *  Sum: '<S239>/Add2'
         *  Sum: '<S239>/Minus'
         */
        rtb_Switch1_k = rtb_Switch8 - rtb_TmpSignalConversionAtLoo_mu[1];

        /* Sum: '<S239>/Minus4' incorporates:
         *  Sum: '<S239>/Add2'
         *  Sum: '<S239>/Minus'
         */
        rtb_Switch8 = (rtb_Switch8 + rtb_TmpSignalConversionAtLoo_mu[1]) -
          rtb_Switch1_k;

        /* Sum: '<S239>/Add' incorporates:
         *  Sum: '<S239>/Add2'
         *  Sum: '<S239>/Minus1'
         */
        rtb_Switch2_n = rtb_Switch1_c - rtb_TmpSignalConversionAtLoo_mu[1];

        /* Sum: '<S239>/Minus' incorporates:
         *  Sum: '<S239>/Minus1'
         */
        rtb_Switch1_c = rtb_Switch1_k - rtb_Switch2_n;

        /* DotProduct: '<S239>/Dot Product' incorporates:
         *  Concatenate: '<S221>/Matrix Concatenate2'
         *  Sum: '<S239>/Minus'
         *  Sum: '<S239>/Minus1'
         *  Sum: '<S239>/Minus5'
         */
        rtb_Subtract_c3 += (rtb_TmpSignalConversionAtLookup[1] - rtb_Switch2_n) *
          rtb_Switch1_c;

        /* DotProduct: '<S239>/Dot Product2' incorporates:
         *  Concatenate: '<S221>/Matrix Concatenate2'
         *  Sum: '<S239>/Minus'
         *  Sum: '<S239>/Minus4'
         *  Sum: '<S239>/Minus5'
         */
        rtb_Switch2_n = ((rtb_TmpSignalConversionAtLookup[1] - rtb_Switch1_k) *
                         rtb_Switch8) + (rtb_dy_n *
          rtb_MatrixConcatenate_b_idx_0);

        /* Merge: '<S225>/Merge4' incorporates:
         *  Constant: '<S240>/Constant'
         *  Constant: '<S241>/Constant'
         *  DataTypeConversion: '<S231>/Data Type Conversion'
         *  DotProduct: '<S239>/Dot Product1'
         *  DotProduct: '<S239>/Dot Product3'
         *  Logic: '<S239>/AND'
         *  RelationalOperator: '<S239>/LessThanOrEqual'
         *  RelationalOperator: '<S239>/LessThanOrEqual1'
         *  RelationalOperator: '<S240>/Compare'
         *  RelationalOperator: '<S241>/Compare'
         *  Sum: '<S231>/Add'
         *  Sum: '<S239>/Minus'
         *  Sum: '<S239>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)((((rtb_Subtract_c3 >=
          0.0) && (rtb_Subtract_c3 <= ((rtb_Switch1_c * rtb_Switch1_c) +
          (rtb_Switch4_fu * rtb_Switch4_fu)))) && (rtb_Switch2_n >= 0.0)) &&
          (rtb_Switch2_n <= ((rtb_dy_n * rtb_dy_n) + (rtb_Switch8 * rtb_Switch8)))))
          + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S225>/Merge2' incorporates:
         *  Constant: '<S231>/Constant2'
         *  SignalConversion generated from: '<S231>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator1 = false;

        /* SignalConversion generated from: '<S231>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S231>/Constant1'
         */
        rtb_LogicalOperator2_e = false;

        /* End of Outputs for SubSystem: '<S228>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S228>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S229>/Action Port'
         */
        /* Merge: '<S225>/Merge2' incorporates:
         *  Constant: '<S229>/Constant2'
         *  SignalConversion generated from: '<S229>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator1 = false;

        /* SignalConversion generated from: '<S229>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S229>/Constant1'
         */
        rtb_LogicalOperator2_e = false;

        /* Merge: '<S225>/Merge4' incorporates:
         *  SignalConversion generated from: '<S229>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S228>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S225>/Merge1' incorporates:
       *  Constant: '<S228>/Constant'
       *  SignalConversion generated from: '<S228>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S228>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator5;

      /* End of Outputs for SubSystem: '<S225>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S225>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S227>/Action Port'
       */
      /* Merge: '<S225>/Merge1' incorporates:
       *  Constant: '<S227>/Constant'
       *  SignalConversion generated from: '<S227>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S225>/Merge2' incorporates:
       *  Constant: '<S227>/Constant1'
       *  SignalConversion generated from: '<S227>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator1 = false;

      /* SignalConversion generated from: '<S227>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S227>/Constant2'
       */
      rtb_LogicalOperator2_e = false;

      /* Merge: '<S225>/Merge4' incorporates:
       *  SignalConversion generated from: '<S227>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S225>/Escape_Auto_Driving' */
    }

    /* End of If: '<S225>/If' */

    /* If: '<S221>/If1' */
    if (!rtb_LogicalOperator2_e) {
      /* Outputs for IfAction SubSystem: '<S221>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S226>/Action Port'
       */
      /* Bias: '<S242>/Add Constant' incorporates:
       *  Bias: '<S242>/Bias'
       *  Sum: '<S242>/Subtract'
       */
      rtb_Subtract_c3 = ((Robot_Control_B.Spline_Num_Poses -
                          Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S242>/Selector4' incorporates:
       *  Bias: '<S242>/Bias1'
       *  Constant: '<S244>/FixPt Constant'
       *  Sum: '<S244>/FixPt Sum1'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = Robot_Control_B.Spline_Follow_Index -
        1.0;
      rtb_TmpSignalConversionAtLoo_mu[1] = Robot_Control_B.Spline_Num_Poses +
        2.0;

      /* SignalConversion generated from: '<S242>/Selector5' */
      rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S242>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)
        rtb_TmpSignalConversionAtLookup[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s247_iter = ((int32_T)rtb_TmpSignalConversionAtLookup[1]) - 1;

      /* Concatenate: '<S242>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S242>/Selector5' incorporates:
       *  Concatenate: '<S242>/Matrix Concatenate'
       *  Gain: '<S246>/Gain'
       *  Selector: '<S221>/Selector1'
       *  Selector: '<S242>/Selector2'
       *  Selector: '<S242>/Selector3'
       *  Sum: '<S246>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s247_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S242>/Matrix Concatenate' incorporates:
       *  Bias: '<S242>/Add Constant1'
       *  Gain: '<S245>/Gain'
       *  Selector: '<S221>/Selector1'
       *  Selector: '<S242>/Selector'
       *  Selector: '<S242>/Selector1'
       *  Selector: '<S242>/Selector5'
       *  Sum: '<S245>/Subtract'
       */
      s247_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s247_iter;
             rtb_Num_Segments++) {
          rtb_MatrixConcatenate_p[(rtb_Num_Segments +
            (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) + 1] =
            rtb_Selector5[(Robot_Control_DW.Selector5_DIMS1[0] * i) +
            rtb_Num_Segments];
        }
      }

      rtb_MatrixConcatenate_p[Robot_Control_DW.Selector5_DIMS1[0] + 1] =
        (rtb_Ref_Poses[((int32_T)rtb_TmpSignalConversionAtLookup[1]) - 1] * 2.0)
        - rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) - 1];
      rtb_MatrixConcatenate_p[(Robot_Control_DW.Selector5_DIMS1[0] +
        Robot_Control_DW.MatrixConcatenate_DIMS1[0]) + 1] = (rtb_Ref_Poses
        [((int32_T)Robot_Control_B.Spline_Num_Poses) + 9] * 2.0) -
        rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) + 9];

      /* Selector: '<S242>/Selector4' */
      s247_iter = ((int32_T)rtb_TmpSignalConversionAtLoo_mu[1]) - ((int32_T)
        rtb_TmpSignalConversionAtLoo_mu[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s247_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S242>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S242>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_TmpSignalConversionAtLoo_mu[0];

      /* Assignment: '<S242>/Assignment' incorporates:
       *  Concatenate: '<S242>/Matrix Concatenate'
       *  Selector: '<S242>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s247_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S243>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S247>/While Iterator'
       */
      s247_iter = 1;
      do {
        rtb_Switch1_k = rtb_Assignment[s247_iter + 1];
        rtb_TmpSignalConversionAtLoo_mu[0] = rtb_Switch1_k -
          rtb_Assignment[s247_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s247_iter] - rtb_Assignment[s247_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Switch1_k - rtb_Assignment[s247_iter];
        rtb_Switch1_k = rtb_Assignment[s247_iter + 13];
        rtb_TmpSignalConversionAtLoo_mu[1] = rtb_Switch1_k -
          rtb_Assignment[s247_iter + 11];
        rtb_Switch8 = rtb_Assignment[s247_iter + 12];
        rtb_Add2[1] = rtb_Switch8 - rtb_Assignment[s247_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Switch1_k - rtb_Switch8;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Switch2_n = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Switch4_fu = rt_powd_snf(rtb_Switch2_n, 2.0);
          rtb_dy_n = rt_powd_snf(rtb_Switch2_n, 3.0);
          rtb_Switch1_c = (rtb_Switch2_n - (2.0 * rtb_Switch4_fu)) + rtb_dy_n;
          rtb_Switch1_k = rtb_Switch4_fu - rtb_dy_n;
          rtb_Optimized_Module_Angle = 3.0 * rtb_Switch4_fu;
          rtb_dy_n = rtb_Optimized_Module_Angle - (2.0 * rtb_dy_n);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_TmpSignalConversionAtLoo_mu[0]
            * rtb_Switch1_c) + (rtb_Add2[0] * rtb_Switch1_k)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_dy_n)) + rtb_Assignment[s247_iter];
          rtb_dy_n = ((((rtb_TmpSignalConversionAtLoo_mu[1] * rtb_Switch1_c) +
                        (rtb_Add2[1] * rtb_Switch1_k)) * 0.5) +
                      (rtb_Minus_k_idx_1 * rtb_dy_n)) + rtb_Switch8;
          rtb_Switch1_c = (rtb_Optimized_Module_Angle - (4.0 * rtb_Switch2_n)) +
            1.0;
          rtb_Switch1_k = (2.0 * rtb_Switch2_n) - rtb_Optimized_Module_Angle;
          rtb_Switch4_fu = (rtb_Switch2_n - rtb_Switch4_fu) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_TmpSignalConversionAtLoo_mu[0] *
            rtb_Switch1_c) + (rtb_Add2[0] * rtb_Switch1_k)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_Switch4_fu);
          rtb_Optimized_Module_Angle = (((rtb_TmpSignalConversionAtLoo_mu[1] *
            rtb_Switch1_c) + (rtb_Add2[1] * rtb_Switch1_k)) * 0.5) +
            (rtb_Minus_k_idx_1 * rtb_Switch4_fu);
          rtb_Switch4_fu = (6.0 * rtb_Switch2_n) - 4.0;
          rtb_Switch1_c = (-6.0 * rtb_Switch2_n) + 2.0;
          rtb_Switch2_n = (-12.0 * rtb_Switch2_n) + 6.0;
          rtb_Switch1_k = (((rtb_TmpSignalConversionAtLoo_mu[0] * rtb_Switch4_fu)
                            + (rtb_Add2[0] * rtb_Switch1_c)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_Switch2_n);
          rtb_Switch1_c = (((rtb_TmpSignalConversionAtLoo_mu[1] * rtb_Switch4_fu)
                            + (rtb_Add2[1] * rtb_Switch1_c)) * 0.5) +
            (rtb_Minus_k_idx_1 * rtb_Switch2_n);
          rtb_Switch4_fu = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Optimized_Module_Angle), 3.0);
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
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_dy_n;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch1_c) - (rtb_Switch1_k *
              rtb_Optimized_Module_Angle)) / (rtb_Switch2_n * rtb_Switch4_fu);
        }

        if (s247_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s247_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Switch2_n = rtb_Subtract_c3 - ((real_T)s247_iter);
        rtb_Num_Segments = s247_iter;
        s247_iter++;
      } while ((rtb_Switch2_n >= 4.0) && (s247_iter <= 3));

      /* End of Outputs for SubSystem: '<S243>/Sampling_Loop' */

      /* SignalConversion generated from: '<S226>/Position_and_Curvature' incorporates:
       *  Assignment: '<S247>/Assignment'
       *  Concatenate: '<S222>/Matrix Concatenate'
       */
      memcpy(&rtb_MatrixConcatenate_o[0], &Robot_Control_B.Assignment[0], 450U *
             (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S221>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S221>/If Action Subsystem' incorporates:
       *  ActionPort: '<S224>/Action Port'
       */
      /* Product: '<S224>/Product' incorporates:
       *  Selector: '<S221>/Selector'
       *  Selector: '<S221>/Selector1'
       */
      rtb_Subtract_c3 = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S224>/Product1' incorporates:
       *  Selector: '<S221>/Selector'
       *  Selector: '<S221>/Selector1'
       */
      rtb_Switch2_n = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S224>/Product' incorporates:
         *  Constant: '<S224>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Subtract_c3;

        /* Product: '<S224>/Product1' incorporates:
         *  Constant: '<S224>/Constant2'
         *  Product: '<S224>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch2_n;
      }

      /* Assignment: '<S224>/Assignment' incorporates:
       *  Concatenate: '<S222>/Matrix Concatenate'
       *  Concatenate: '<S224>/Matrix Concatenate'
       */
      memset(&rtb_MatrixConcatenate_o[0], 0, 450U * (sizeof(real_T)));
      memcpy(&rtb_MatrixConcatenate_o[0], &rtb_MatrixConcatenate_h[0], 50U *
             (sizeof(real_T)));
      memcpy(&rtb_MatrixConcatenate_o[50], &rtb_MatrixConcatenate_h[50], 50U *
             (sizeof(real_T)));

      /* SignalConversion generated from: '<S224>/Num_Segments' incorporates:
       *  Constant: '<S224>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S221>/If Action Subsystem' */
    }

    /* End of If: '<S221>/If1' */

    /* Concatenate: '<S222>/Matrix Concatenate' incorporates:
     *  Selector: '<S222>/Selector'
     *  Selector: '<S222>/Selector1'
     *  Selector: '<S222>/Selector3'
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

    /* MATLAB Function: '<S222>/Distance Along Curve' incorporates:
     *  Concatenate: '<S222>/Matrix Concatenate'
     *  Selector: '<S222>/Selector4'
     *  Selector: '<S222>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s247_iter = 0; s247_iter < 149; s247_iter++) {
      /* Outputs for Iterator SubSystem: '<S243>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S247>/While Iterator'
       */
      rtb_Assignment_d[s247_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s247_iter + 1] -
         rtb_MatrixConcatenate_o[s247_iter], rtb_MatrixConcatenate_o[s247_iter +
         151] - rtb_MatrixConcatenate_o[s247_iter + 150]) +
        rtb_Assignment_d[s247_iter];

      /* End of Outputs for SubSystem: '<S243>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S222>/Distance Along Curve' */

    /* MATLAB Function: '<S222>/Find closest index to curve' incorporates:
     *  Concatenate: '<S222>/Matrix Concatenate'
     *  Selector: '<S222>/Selector4'
     *  Selector: '<S222>/Selector5'
     *  Selector: '<S273>/Selector'
     */
    for (s247_iter = 0; s247_iter < 150; s247_iter++) {
      /* Outputs for Iterator SubSystem: '<S243>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S247>/While Iterator'
       */
      distance_from_robot[s247_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s247_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s247_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S243>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s247_iter = 1;
    } else {
      s247_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s247_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s247_iter == 0) {
      rtb_Subtract_c3 = distance_from_robot[0];
    } else {
      rtb_Subtract_c3 = distance_from_robot[s247_iter - 1];
      for (rtb_Bias1_p = s247_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Switch2_n = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Subtract_c3 > rtb_Switch2_n) {
          rtb_Subtract_c3 = rtb_Switch2_n;
        }
      }
    }

    s247_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s247_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Subtract_c3) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S273>/Selector' incorporates:
     *  Constant: '<S273>/Constant'
     *  MATLAB Function: '<S222>/Find closest index to curve'
     *  MinMax: '<S273>/Min'
     */
    rtb_Switch2_n = rtb_Assignment_d[((int32_T)fmin(50.0, s247_iter)) - 1];

    /* If: '<S273>/If' incorporates:
     *  RelationalOperator: '<S273>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S273>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S276>/Action Port'
       */
      /* SignalConversion generated from: '<S276>/Lookup Table Dynamic' */
      rtb_TmpSignalConversionAtLookup[0] = rtb_Assignment_d[0];
      rtb_TmpSignalConversionAtLookup[1] = rtb_Assignment_d[49];

      /* Sum: '<S278>/FixPt Sum1' incorporates:
       *  Constant: '<S278>/FixPt Constant'
       */
      rtb_Subtract_c3 = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S276>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S276>/Selector11'
       *  Selector: '<S276>/Selector12'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = rtb_Spline_Ref_Poses_h[((int32_T)
        rtb_Subtract_c3) + 19];
      rtb_TmpSignalConversionAtLoo_mu[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S276>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S276>/Selector1'
       *  Selector: '<S276>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Subtract_c3) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S276>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S276>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Subtract_c3),
                           &rtb_TmpSignalConversionAtLoo_mu[0], rtb_Switch2_n,
                           &rtb_TmpSignalConversionAtLookup[0], 1U);

      /* SignalConversion: '<S276>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S276>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S276>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Switch2_n,
                           &rtb_TmpSignalConversionAtLookup[0], 1U);

      /* End of Outputs for SubSystem: '<S273>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S273>/Latch' incorporates:
       *  ActionPort: '<S277>/Action Port'
       */
      /* SignalConversion generated from: '<S277>/In1' incorporates:
       *  UnitDelay: '<S273>/Unit Delay1'
       */
      rtb_Subtract_c3 = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S277>/In2' incorporates:
       *  UnitDelay: '<S273>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S273>/Latch' */
    }

    /* End of If: '<S273>/If' */

    /* MinMax: '<S220>/Min' incorporates:
     *  Lookup_n-D: '<S220>/Lookahead Distance'
     *  UnitDelay: '<S220>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S222>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S272>/While Iterator'
     */
    s272_iter = 1U;
    rtb_LogicalOperator5 = true;
    while (rtb_LogicalOperator5 && (s272_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S222>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S272>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s272_iter;
      rtb_LogicalOperator5 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s247_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s272_iter++;
    }

    /* End of Outputs for SubSystem: '<S222>/Find first index that meets distance target' */

    /* Switch: '<S275>/Switch' incorporates:
     *  Concatenate: '<S222>/Matrix Concatenate'
     *  Constant: '<S222>/Constant'
     *  Constant: '<S272>/Constant'
     *  Constant: '<S275>/Constant'
     *  Constant: '<S275>/Constant1'
     *  Constant: '<S275>/Constant2'
     *  Constant: '<S275>/Constant3'
     *  Logic: '<S272>/AND'
     *  MATLAB Function: '<S222>/Find closest index to curve'
     *  Math: '<S275>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S275>/Max'
     *  MinMax: '<S275>/Min'
     *  MinMax: '<S275>/Min1'
     *  Product: '<S272>/Product'
     *  Product: '<S275>/Divide'
     *  Product: '<S275>/Product'
     *  Product: '<S275>/Product1'
     *  RelationalOperator: '<S222>/Relational Operator'
     *  RelationalOperator: '<S272>/Relational Operator'
     *  RelationalOperator: '<S272>/Relational Operator1'
     *  Selector: '<S222>/Selector10'
     *  Selector: '<S222>/Selector7'
     *  Selector: '<S222>/Selector8'
     *  Selector: '<S222>/Selector9'
     *  Selector: '<S272>/Selector'
     *  Selector: '<S272>/Selector1'
     *  Selector: '<S273>/Selector'
     *  Sqrt: '<S275>/Sqrt'
     *  Sum: '<S222>/Subtract'
     *  Sum: '<S272>/Add'
     *  Sum: '<S275>/Subtract'
     *  Sum: '<S275>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Saturation_h = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Subtract_c3 *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Saturation_h = fmin(rtb_Subtract_c3 * Spline_Velocity_Multiplier_TEST,
        sqrt(Spline_Max_Centripital_Acceleration / fmax
             (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299],
              1.0E-5)));
    }

    /* End of Switch: '<S275>/Switch' */

    /* Logic: '<S223>/OR' */
    rtb_LogicalOperator2_e = (rtb_LogicalOperator1 ||
      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S223>/Switch1' incorporates:
     *  Switch: '<S223>/Switch'
     *  UnitDelay: '<S223>/Unit Delay'
     */
    if (rtb_LogicalOperator2_e) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S223>/Constant3'
       *  SignalConversion: '<S223>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Switch2_n = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S223>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Switch2_n = rtb_Merge1;
    }

    /* End of Switch: '<S223>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S223>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Switch2_n;

    /* Selector: '<S222>/Selector6' incorporates:
     *  Concatenate: '<S222>/Matrix Concatenate'
     *  Selector: '<S222>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S222>/Selector2' incorporates:
     *  Concatenate: '<S222>/Matrix Concatenate'
     *  Selector: '<S222>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S223>/Switch2' incorporates:
     *  Sum: '<S279>/Subtract'
     *  Sum: '<S279>/Subtract1'
     *  Trigonometry: '<S279>/Atan2'
     *  UnitDelay: '<S223>/Unit Delay1'
     */
    if (rtb_LogicalOperator2_e) {
      rtb_Switch4_fu = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Switch4_fu = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S223>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S223>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Switch4_fu;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S220>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator1;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S220>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S223>/Constant2'
     *  SignalConversion generated from: '<S220>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S223>/Constant5'
     *  SignalConversion generated from: '<S220>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S223>/Constant6'
     *  SignalConversion generated from: '<S220>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S220>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S221>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S220>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S273>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S273>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S223>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Switch2_n;

    /* Update for UnitDelay: '<S223>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Switch4_fu;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S219>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S219>/Constant1'
     *  SignalConversion generated from: '<S219>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S219>/Constant'
     *  SignalConversion generated from: '<S219>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S219>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S219>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S219>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S219>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S219>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Compare_ky;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S219>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Compare_mq;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S219>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S369>/Sign2' incorporates:
   *  UnitDelay: '<S369>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_ir = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S369>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S369>/Product1' incorporates:
   *  Signum: '<S369>/Sign1'
   *  Signum: '<S369>/Sign2'
   */
  rtb_Add_ir *= rtb_Add_di;
  if (rtIsNaN(rtb_Add_ir)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_ir, 256.0);
  }

  /* Switch: '<S369>/Switch' incorporates:
   *  Constant: '<S369>/Constant'
   *  Constant: '<S374>/Constant'
   *  Constant: '<S375>/Constant'
   *  Logic: '<S369>/or'
   *  Product: '<S369>/Product1'
   *  RelationalOperator: '<S374>/Compare'
   *  RelationalOperator: '<S375>/Compare'
   *  UnitDelay: '<S369>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_uDLookupTable = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_uDLookupTable = 0.0;
  }

  /* End of Switch: '<S369>/Switch' */

  /* Switch: '<S380>/Init' incorporates:
   *  UnitDelay: '<S380>/FixPt Unit Delay1'
   *  UnitDelay: '<S380>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Switch1_c = rtb_uDLookupTable;
  } else {
    rtb_Switch1_c = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S380>/Init' */

  /* RelationalOperator: '<S376>/Compare' incorporates:
   *  Constant: '<S376>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_uDLookupTable == 0.0);

  /* RelationalOperator: '<S377>/Compare' incorporates:
   *  Constant: '<S377>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_uDLookupTable > 0.0);

  /* Abs: '<S369>/Abs' incorporates:
   *  Sum: '<S369>/Subtract'
   *  UnitDelay: '<S369>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S369>/Switch1' incorporates:
   *  Constant: '<S369>/Constant1'
   *  Switch: '<S369>/Switch3'
   *  Switch: '<S369>/Switch5'
   *  UnaryMinus: '<S369>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    rtb_Subtract_c3 = -Translation_Speed_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S369>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S369>/Constant1'
     *  Constant: '<S369>/Constant4'
     *  Constant: '<S369>/Constant6'
     *  UnaryMinus: '<S369>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S369>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S369>/Constant2'
     *  Constant: '<S369>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S369>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S369>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_j),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Merge1,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic_j;
  } else {
    if (rtb_LogicalOperator5) {
      /* Switch: '<S369>/Switch3' incorporates:
       *  Constant: '<S369>/Constant3'
       */
      rtb_Subtract_c3 = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Subtract_c3 = -Translation_Speed_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S369>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S369>/Constant1'
     *  Constant: '<S369>/Constant10'
     *  Constant: '<S369>/Constant8'
     *  UnaryMinus: '<S369>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S369>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S369>/Constant7'
     *  Constant: '<S369>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S369>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S369>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_i),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Merge1,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic1_i;
  }

  /* End of Switch: '<S369>/Switch1' */

  /* Product: '<S369>/Product' */
  rtb_Subtract_c3 *= rtb_Merge1;

  /* Sum: '<S378>/Sum1' */
  rtb_Saturation_h = rtb_uDLookupTable - rtb_Switch1_c;

  /* Switch: '<S379>/Switch2' incorporates:
   *  RelationalOperator: '<S379>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Subtract_c3)) {
    /* Switch: '<S369>/Switch2' incorporates:
     *  Constant: '<S369>/Constant1'
     *  Switch: '<S369>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Subtract_c3 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S369>/Switch4' incorporates:
       *  Constant: '<S369>/Constant1'
       */
      rtb_Subtract_c3 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S369>/Switch4' incorporates:
       *  Constant: '<S369>/Constant3'
       *  UnaryMinus: '<S369>/Unary Minus1'
       */
      rtb_Subtract_c3 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S369>/Switch2' */

    /* Product: '<S369>/Product2' */
    rtb_Subtract_c3 *= rtb_Merge1;

    /* Switch: '<S379>/Switch' incorporates:
     *  RelationalOperator: '<S379>/UpperRelop'
     */
    if (!(rtb_Saturation_h < rtb_Subtract_c3)) {
      rtb_Subtract_c3 = rtb_Saturation_h;
    }

    /* End of Switch: '<S379>/Switch' */
  }

  /* End of Switch: '<S379>/Switch2' */

  /* Sum: '<S378>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Subtract_c3 + rtb_Switch1_c;

  /* Switch: '<S372>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S372>/Switch' incorporates:
     *  Constant: '<S406>/Constant3'
     *  Constant: '<S406>/Constant4'
     *  Math: '<S406>/Math Function'
     *  Sum: '<S372>/Subtract'
     *  Sum: '<S406>/Add1'
     *  Sum: '<S406>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.141592653589793, 6.283185307179586) - 3.141592653589793;
  } else {
    /* Switch: '<S372>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S372>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_ir = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_ir)) || (rtIsInf(rtb_Add_ir))) {
    rtb_Add_ir = 0.0;
  } else {
    rtb_Add_ir = fmod(rtb_Add_ir, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Add_ir < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Add_ir)))))) : ((int32_T)((uint8_T)rtb_Add_ir)));

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* Switch: '<S198>/Switch' incorporates:
   *  Constant: '<S185>/Constant'
   *  Constant: '<S198>/Constant'
   *  RelationalOperator: '<S185>/Compare'
   *  UnitDelay: '<S198>/Unit Delay'
   */
  if (rtb_GameState != 1) {
    rtb_Add_ir = 0.0;
  } else {
    rtb_Add_ir = Robot_Control_DW.UnitDelay_DSTATE_o;
  }

  /* Sum: '<S198>/Sum' incorporates:
   *  Constant: '<S198>/Constant4'
   *  Switch: '<S198>/Switch'
   */
  rtb_Merge1 = rtb_Add_ir + 0.02;

  /* Switch: '<S199>/Switch' incorporates:
   *  Constant: '<S190>/Constant'
   *  Constant: '<S199>/Constant'
   *  RelationalOperator: '<S190>/Compare'
   *  UnitDelay: '<S199>/Unit Delay'
   */
  if (rtb_GameState != 2) {
    rtb_Add_ir = 0.0;
  } else {
    rtb_Add_ir = Robot_Control_DW.UnitDelay_DSTATE_m;
  }

  /* Sum: '<S199>/Sum' incorporates:
   *  Constant: '<S199>/Constant4'
   *  Switch: '<S199>/Switch'
   */
  rtb_Saturation_h = rtb_Add_ir + 0.02;

  /* MultiPortSwitch: '<S146>/Multiport Switch' incorporates:
   *  Constant: '<S146>/Constant1'
   *  Constant: '<S146>/Constant3'
   */
  switch (rtb_GameState) {
   case 0:
    rtb_Switch1_c = 0.0;
    break;

   case 1:
    rtb_Switch1_c = rtb_Merge1;
    break;

   case 2:
    rtb_Switch1_c = rtb_Saturation_h;
    break;

   default:
    rtb_Switch1_c = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S146>/Multiport Switch' */

  /* If: '<S146>/If' incorporates:
   *  Constant: '<S183>/Constant'
   *  Constant: '<S184>/Constant'
   *  Constant: '<S186>/Constant'
   *  Constant: '<S187>/Constant'
   *  Constant: '<S188>/Constant'
   *  Constant: '<S189>/Constant'
   *  Constant: '<S191>/Constant'
   *  Inport: '<Root>/MatchTime'
   *  Logic: '<S146>/Logical Operator'
   *  RelationalOperator: '<S183>/Compare'
   *  RelationalOperator: '<S184>/Compare'
   *  RelationalOperator: '<S186>/Compare'
   *  RelationalOperator: '<S187>/Compare'
   *  RelationalOperator: '<S188>/Compare'
   *  RelationalOperator: '<S189>/Compare'
   *  RelationalOperator: '<S191>/Compare'
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
      /* InitializeConditions for IfAction SubSystem: '<S146>/If Action Subsystem' incorporates:
       *  ActionPort: '<S192>/Action Port'
       */
      /* InitializeConditions for If: '<S146>/If' incorporates:
       *  UnitDelay: '<S192>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S146>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem' incorporates:
     *  ActionPort: '<S192>/Action Port'
     */
    /* Merge: '<S146>/Merge' incorporates:
     *  Constant: '<S192>/Constant'
     *  SignalConversion generated from: '<S192>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S146>/Merge1' incorporates:
     *  Constant: '<S192>/Constant'
     *  SignalConversion generated from: '<S192>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S192>/Sum' incorporates:
     *  Constant: '<S192>/Constant1'
     *  UnitDelay: '<S192>/Unit Delay'
     */
    rtb_Subtract_c3 = Robot_Control_DW.UnitDelay_DSTATE_hb - 0.02;

    /* Merge: '<S146>/Merge2' incorporates:
     *  SignalConversion: '<S192>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S192>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hb = rtb_Subtract_c3;

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S146>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S193>/Action Port'
       */
      /* InitializeConditions for If: '<S146>/If' incorporates:
       *  UnitDelay: '<S193>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_b2 = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S146>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    /* Sum: '<S193>/Sum' incorporates:
     *  Constant: '<S193>/Constant1'
     *  UnitDelay: '<S193>/Unit Delay'
     */
    rtb_Subtract_c3 = Robot_Control_DW.UnitDelay_DSTATE_b2 - 0.02;

    /* RelationalOperator: '<S200>/Compare' incorporates:
     *  Constant: '<S200>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Subtract_c3 <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S146>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S193>/Logical Operator'
     *  Logic: '<S193>/NOT'
     */
    Robot_Control_B.RB_IsBlueActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Merge: '<S146>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S193>/Logical Operator1'
     */
    Robot_Control_B.RB_IsRedActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Switch: '<S193>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S193>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S146>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3;
    } else {
      /* Merge: '<S146>/Merge2' incorporates:
       *  Constant: '<S193>/Constant2'
       *  Sum: '<S193>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3 -
        Rebuilt_Match_Time_Shoot_Early;
    }

    /* End of Switch: '<S193>/Switch' */

    /* Update for UnitDelay: '<S193>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b2 = rtb_Subtract_c3;

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem1' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S146>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S194>/Action Port'
       */
      /* InitializeConditions for If: '<S146>/If' incorporates:
       *  UnitDelay: '<S194>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S146>/If Action Subsystem2' */
    }

    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S194>/Action Port'
     */
    /* Sum: '<S194>/Sum' incorporates:
     *  Constant: '<S194>/Constant1'
     *  UnitDelay: '<S194>/Unit Delay'
     */
    rtb_Subtract_c3 = Robot_Control_DW.UnitDelay_DSTATE_hz - 0.02;

    /* RelationalOperator: '<S201>/Compare' incorporates:
     *  Constant: '<S201>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Subtract_c3 <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S146>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S194>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S146>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S194>/Logical Operator1'
     *  Logic: '<S194>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S194>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S194>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S146>/Merge2' incorporates:
       *  Constant: '<S194>/Constant2'
       *  Sum: '<S194>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3 -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S146>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3;
    }

    /* End of Switch: '<S194>/Switch' */

    /* Update for UnitDelay: '<S194>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hz = rtb_Subtract_c3;

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem2' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S146>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S195>/Action Port'
       */
      /* InitializeConditions for If: '<S146>/If' incorporates:
       *  UnitDelay: '<S195>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_gt = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S146>/If Action Subsystem3' */
    }

    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S195>/Action Port'
     */
    /* Sum: '<S195>/Sum' incorporates:
     *  Constant: '<S195>/Constant1'
     *  UnitDelay: '<S195>/Unit Delay'
     */
    rtb_Subtract_c3 = Robot_Control_DW.UnitDelay_DSTATE_gt - 0.02;

    /* RelationalOperator: '<S202>/Compare' incorporates:
     *  Constant: '<S202>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Subtract_c3 <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S146>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S195>/Logical Operator'
     *  Logic: '<S195>/NOT'
     */
    Robot_Control_B.RB_IsBlueActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Merge: '<S146>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S195>/Logical Operator1'
     */
    Robot_Control_B.RB_IsRedActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Switch: '<S195>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S195>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S146>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3;
    } else {
      /* Merge: '<S146>/Merge2' incorporates:
       *  Constant: '<S195>/Constant2'
       *  Sum: '<S195>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3 -
        Rebuilt_Match_Time_Shoot_Early;
    }

    /* End of Switch: '<S195>/Switch' */

    /* Update for UnitDelay: '<S195>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gt = rtb_Subtract_c3;

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem3' */
    break;

   case 4:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S146>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S196>/Action Port'
       */
      /* InitializeConditions for If: '<S146>/If' incorporates:
       *  UnitDelay: '<S196>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S146>/If Action Subsystem4' */
    }

    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    /* Sum: '<S196>/Sum' incorporates:
     *  Constant: '<S196>/Constant1'
     *  UnitDelay: '<S196>/Unit Delay'
     */
    rtb_Subtract_c3 = Robot_Control_DW.UnitDelay_DSTATE_di - 0.02;

    /* RelationalOperator: '<S203>/Compare' incorporates:
     *  Constant: '<S203>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Subtract_c3 <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S146>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S196>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S146>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S196>/Logical Operator1'
     *  Logic: '<S196>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S196>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S196>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S146>/Merge2' incorporates:
       *  Constant: '<S196>/Constant2'
       *  Sum: '<S196>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3 -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S146>/Merge2' incorporates:
       *  Constant: '<S196>/Constant3'
       *  Sum: '<S196>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3 +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S196>/Switch' */

    /* Update for UnitDelay: '<S196>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Subtract_c3;

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem4' */
    break;

   default:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S146>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S197>/Action Port'
       */
      /* InitializeConditions for If: '<S146>/If' incorporates:
       *  UnitDelay: '<S197>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

      /* End of InitializeConditions for SubSystem: '<S146>/If Action Subsystem5' */
    }

    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    /* Merge: '<S146>/Merge' incorporates:
     *  Constant: '<S197>/Constant'
     *  SignalConversion generated from: '<S197>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S146>/Merge1' incorporates:
     *  Constant: '<S197>/Constant'
     *  SignalConversion generated from: '<S197>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S197>/Sum' incorporates:
     *  Constant: '<S197>/Constant1'
     *  UnitDelay: '<S197>/Unit Delay'
     */
    rtb_Subtract_c3 = Robot_Control_DW.UnitDelay_DSTATE_du - 0.02;

    /* Merge: '<S146>/Merge2' incorporates:
     *  SignalConversion: '<S197>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S197>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_du = rtb_Subtract_c3;

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S146>/If' */

  /* If: '<S205>/If' incorporates:
   *  If: '<S206>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S205>/Blue' incorporates:
     *  ActionPort: '<S207>/Action Port'
     */
    /* Merge: '<S205>/Merge' incorporates:
     *  Constant: '<S207>/BlueAllianceZoneX'
     *  Logic: '<S207>/AND'
     *  RelationalOperator: '<S207>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S205>/Blue' */

    /* Outputs for IfAction SubSystem: '<S206>/Blue' incorporates:
     *  ActionPort: '<S209>/Action Port'
     */
    /* Merge: '<S206>/Merge' incorporates:
     *  Constant: '<S209>/BlueAllianceZoneX'
     *  RelationalOperator: '<S209>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S206>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S205>/Red' incorporates:
     *  ActionPort: '<S208>/Action Port'
     */
    /* Merge: '<S205>/Merge' incorporates:
     *  Constant: '<S208>/RedAllianceZoneX'
     *  Logic: '<S208>/AND'
     *  RelationalOperator: '<S208>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S205>/Red' */

    /* Outputs for IfAction SubSystem: '<S206>/Red' incorporates:
     *  ActionPort: '<S210>/Action Port'
     */
    /* Merge: '<S206>/Merge' incorporates:
     *  Constant: '<S210>/RedAllianceZoneX'
     *  RelationalOperator: '<S210>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S206>/Red' */
  }

  /* End of If: '<S205>/If' */

  /* RelationalOperator: '<S151>/GreaterThan' incorporates:
   *  Constant: '<S151>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S151>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S151>/Relational Operator' incorporates:
   *  Abs: '<S151>/Abs'
   *  Constant: '<S204>/Constant3'
   *  Constant: '<S204>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S204>/Math Function'
   *  Sum: '<S151>/Subtract'
   *  Sum: '<S204>/Add1'
   *  Sum: '<S204>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.141592653589793, 6.283185307179586) - 3.141592653589793) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S150>/Max' incorporates:
   *  Abs: '<S150>/Abs1'
   *  Abs: '<S150>/Abs2'
   *  Abs: '<S150>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S151>/Relational Operator1' incorporates:
   *  Abs: '<S151>/Abs1'
   *  Constant: '<S151>/Constant2'
   *  Sum: '<S151>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S151>/Relational Operator4' incorporates:
   *  Abs: '<S151>/Abs4'
   *  Constant: '<S151>/Constant1'
   *  Sum: '<S151>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S151>/AND' incorporates:
   *  Logic: '<S151>/OR'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  rtb_LogicalOperator2_e = ((((Robot_Control_B.RB_Logic_Gyro_Angle) ||
    (Robot_Control_DW.UnitDelay_5_DSTATE)) &&
    (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S151>/AND2' incorporates:
   *  Logic: '<S151>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_LogicalOperator2_e);

  /* RelationalOperator: '<S147>/Compare' incorporates:
   *  Constant: '<S147>/Constant'
   *  Inport: '<Root>/Gamepad_RT'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_RT != 0.0);

  /* SignalConversion: '<S151>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S151>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_LogicalOperator2_e);

  /* Logic: '<S151>/AND4' */
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
    if ((rtb_Button_Spinup_Enable || rtb_Compare_bd) || rtb_LogicalOperator1) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.RB_Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.RB_Transfer_Init = 1.0;
    }
  } else {
    /* case IN_Shooting: */
    Robot_Control_B.RB_Shooter_Active = true;
    rtb_Compare_ky = !rtb_Compare_bd;
    rtb_LogicalOperator2_e = !rtb_LogicalOperator1;
    if (((!rtb_Button_Spinup_Enable) && rtb_Compare_ky) &&
        rtb_LogicalOperator2_e) {
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
        if (((rtb_Compare_ky && rtb_LogicalOperator2_e) ||
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
        if ((rtb_Compare_bd && ((Robot_Control_B.RB_Ready_to_Score) ||
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
        } else if (((rtb_Compare_ky && rtb_LogicalOperator2_e) ||
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

  /* RelationalOperator: '<S148>/Compare' incorporates:
   *  Constant: '<S148>/Constant'
   *  Inport: '<Root>/Gamepad_B2_B'
   */
  rtb_Compare_bd = (Robot_Control_U.Gamepad_B2_B != 0.0);

  /* Logic: '<S12>/AND' incorporates:
   *  Logic: '<S12>/NOT'
   */
  rtb_Button_Spinup_Enable = ((Robot_Control_B.RB_Shooter_Active) &&
    (!rtb_Compare_bd));

  /* If: '<S144>/If' incorporates:
   *  Constant: '<S157>/Constant'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Outputs for IfAction SubSystem: '<S144>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* SignalConversion generated from: '<S159>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S164>/Constant1'
     *  Constant: '<S164>/Constant10'
     *  Constant: '<S164>/Constant2'
     *  Constant: '<S164>/Constant5'
     *  Constant: '<S164>/Constant6'
     *  Constant: '<S164>/Constant7'
     *  Constant: '<S164>/Constant8'
     *  Constant: '<S164>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_fl[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLoo_fl[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLoo_fl[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLoo_fl[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLoo_fl[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLoo_fl[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLoo_fl[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLoo_fl[7] = Rebuilt_Shoot_Dist_7;

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
    rtb_TmpSignalConversionAtLoo_d0[0] = Rebuilt_Shoot_Hood_Pos_0;
    rtb_TmpSignalConversionAtLoo_d0[1] = Rebuilt_Shoot_Hood_Pos_1;
    rtb_TmpSignalConversionAtLoo_d0[2] = Rebuilt_Shoot_Hood_Pos_2;
    rtb_TmpSignalConversionAtLoo_d0[3] = Rebuilt_Shoot_Hood_Pos_3;
    rtb_TmpSignalConversionAtLoo_d0[4] = Rebuilt_Shoot_Hood_Pos_4;
    rtb_TmpSignalConversionAtLoo_d0[5] = Rebuilt_Shoot_Hood_Pos_5;
    rtb_TmpSignalConversionAtLoo_d0[6] = Rebuilt_Shoot_Hood_Pos_6;
    rtb_TmpSignalConversionAtLoo_d0[7] = Rebuilt_Shoot_Hood_Pos_7;

    /* SignalConversion generated from: '<S159>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S159>/Constant1'
     *  Constant: '<S159>/Constant10'
     *  Constant: '<S159>/Constant2'
     *  Constant: '<S159>/Constant5'
     *  Constant: '<S159>/Constant6'
     *  Constant: '<S159>/Constant7'
     *  Constant: '<S159>/Constant8'
     *  Constant: '<S159>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ga[0] = Rebuilt_Shoot_Gyro_Err_0;
    rtb_TmpSignalConversionAtLoo_ga[1] = Rebuilt_Shoot_Gyro_Err_1;
    rtb_TmpSignalConversionAtLoo_ga[2] = Rebuilt_Shoot_Gyro_Err_2;
    rtb_TmpSignalConversionAtLoo_ga[3] = Rebuilt_Shoot_Gyro_Err_3;
    rtb_TmpSignalConversionAtLoo_ga[4] = Rebuilt_Shoot_Gyro_Err_4;
    rtb_TmpSignalConversionAtLoo_ga[5] = Rebuilt_Shoot_Gyro_Err_5;
    rtb_TmpSignalConversionAtLoo_ga[6] = Rebuilt_Shoot_Gyro_Err_6;
    rtb_TmpSignalConversionAtLoo_ga[7] = Rebuilt_Shoot_Gyro_Err_7;

    /* SignalConversion generated from: '<S161>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S173>/Constant1'
     *  Constant: '<S173>/Constant10'
     *  Constant: '<S173>/Constant2'
     *  Constant: '<S173>/Constant5'
     *  Constant: '<S173>/Constant6'
     *  Constant: '<S173>/Constant7'
     *  Constant: '<S173>/Constant8'
     *  Constant: '<S173>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_cj[0] = Rebuilt_Shoot_Shooter_Spd_0;
    rtb_TmpSignalConversionAtLoo_cj[1] = Rebuilt_Shoot_Shooter_Spd_1;
    rtb_TmpSignalConversionAtLoo_cj[2] = Rebuilt_Shoot_Shooter_Spd_2;
    rtb_TmpSignalConversionAtLoo_cj[3] = Rebuilt_Shoot_Shooter_Spd_3;
    rtb_TmpSignalConversionAtLoo_cj[4] = Rebuilt_Shoot_Shooter_Spd_4;
    rtb_TmpSignalConversionAtLoo_cj[5] = Rebuilt_Shoot_Shooter_Spd_5;
    rtb_TmpSignalConversionAtLoo_cj[6] = Rebuilt_Shoot_Shooter_Spd_6;
    rtb_TmpSignalConversionAtLoo_cj[7] = Rebuilt_Shoot_Shooter_Spd_7;

    /* SignalConversion generated from: '<S161>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S172>/Constant1'
     *  Constant: '<S172>/Constant10'
     *  Constant: '<S172>/Constant2'
     *  Constant: '<S172>/Constant5'
     *  Constant: '<S172>/Constant6'
     *  Constant: '<S172>/Constant7'
     *  Constant: '<S172>/Constant8'
     *  Constant: '<S172>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mk[0] = Rebuilt_Shoot_Shooter_Spd_I_0;
    rtb_TmpSignalConversionAtLoo_mk[1] = Rebuilt_Shoot_Shooter_Spd_I_1;
    rtb_TmpSignalConversionAtLoo_mk[2] = Rebuilt_Shoot_Shooter_Spd_I_2;
    rtb_TmpSignalConversionAtLoo_mk[3] = Rebuilt_Shoot_Shooter_Spd_I_3;
    rtb_TmpSignalConversionAtLoo_mk[4] = Rebuilt_Shoot_Shooter_Spd_I_4;
    rtb_TmpSignalConversionAtLoo_mk[5] = Rebuilt_Shoot_Shooter_Spd_I_5;
    rtb_TmpSignalConversionAtLoo_mk[6] = Rebuilt_Shoot_Shooter_Spd_I_6;
    rtb_TmpSignalConversionAtLoo_mk[7] = Rebuilt_Shoot_Shooter_Spd_I_7;

    /* Switch: '<S163>/Switch4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S163>/Logical Operator'
     *  Switch: '<S163>/Switch5'
     *  Switch: '<S163>/Switch6'
     */
    if ((Robot_Control_B.Is_Outside_Alliance_Zone) || rtb_LogicalOperator1) {
      /* Switch: '<S163>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S163>/Switch4' incorporates:
         *  Constant: '<S163>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S163>/Switch4' incorporates:
         *  Constant: '<S163>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S163>/Switch2' */

      /* Switch: '<S163>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S163>/Switch6' incorporates:
         *  Constant: '<S163>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S163>/Switch6' incorporates:
         *  Constant: '<S163>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S163>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S163>/Switch5' incorporates:
         *  Constant: '<S163>/Constant8'
         *  Switch: '<S163>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S163>/Switch4' incorporates:
         *  Constant: '<S163>/Constant9'
         *  Switch: '<S163>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S163>/Switch6' incorporates:
       *  Constant: '<S163>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* End of Switch: '<S163>/Switch4' */

    /* Outputs for Iterator SubSystem: '<S157>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S158>/While Iterator'
     */
    Iteration_Number = 1U;

    /* InitializeConditions for Memory: '<S158>/Memory1' */
    rtb_Subtract_c3 = 0.0;

    /* InitializeConditions for Memory: '<S158>/Memory2' */
    rtb_Switch2_n = 0.0;

    /* InitializeConditions for Memory: '<S158>/Memory3' */
    rtb_Switch4_fu = 0.0;

    /* InitializeConditions for Memory: '<S158>/Memory' */
    rtb_LogicalOperator1 = true;
    rtb_LogicalOperator5 = true;

    /* SignalConversion generated from: '<S166>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S157>/Constant'
     *  Constant: '<S166>/Constant'
     *  Constant: '<S166>/Constant1'
     *  Constant: '<S166>/Constant11'
     *  Constant: '<S166>/Constant2'
     *  Constant: '<S166>/Constant3'
     *  Constant: '<S166>/Constant4'
     *  Constant: '<S166>/Constant5'
     *  Constant: '<S166>/Constant6'
     */
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;

    /* SignalConversion generated from: '<S166>/Lookup Table Dynamic' */
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLoo_fl[0];
    while (rtb_LogicalOperator5 && (Iteration_Number <= 10)) {
      /* Switch: '<S167>/Switch' incorporates:
       *  Memory: '<S158>/Memory1'
       *  Memory: '<S158>/Memory2'
       *  Switch: '<S167>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Switch1_c = rtb_Subtract_c3;
        rtb_Switch1_k = rtb_Switch2_n;
      } else {
        rtb_Switch1_c = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Switch1_k = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S167>/Switch' */

      /* Math: '<S165>/Hypot' incorporates:
       *  Sum: '<S165>/Subtract'
       *  Sum: '<S165>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Switch1_c -
        Robot_Control_B.KF_Position_X, rtb_Switch1_k -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S166>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S166>/Lookup Table Dynamic'
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

      /* Sum: '<S168>/Subtract' incorporates:
       *  Memory: '<S158>/Memory3'
       *  Sum: '<S168>/Subtract1'
       */
      rtb_Subtract_c3 = rtb_TOF - rtb_Switch4_fu;

      /* Sum: '<S168>/Add' incorporates:
       *  Gain: '<S168>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S168>/Product'
       *  Sum: '<S168>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Subtract_c3 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Switch1_c;

      /* Sum: '<S168>/Add1' incorporates:
       *  Gain: '<S168>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S168>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Subtract_c3 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Switch1_k;

      /* Memory: '<S158>/Memory' */
      rtb_LogicalOperator5 = rtb_LogicalOperator1;

      /* Update for Memory: '<S158>/Memory1' */
      rtb_Subtract_c3 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S158>/Memory2' */
      rtb_Switch2_n = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S158>/Memory3' */
      rtb_Switch4_fu = rtb_TOF;

      /* Update for Memory: '<S158>/Memory' incorporates:
       *  Constant: '<S170>/Constant'
       *  Math: '<S169>/Hypot'
       *  RelationalOperator: '<S170>/Compare'
       *  Sum: '<S169>/Subtract'
       *  Sum: '<S169>/Subtract1'
       */
      rtb_LogicalOperator1 = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X
        - rtb_Switch1_c, Robot_Control_B.RB_Desired_Target_Y - rtb_Switch1_k) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S157>/Iterate_Shot_Target' */

    /* Merge: '<S144>/Merge2' incorporates:
     *  S-Function (sfix_look1_dyn): '<S160>/Lookup Table Dynamic'
     */
    /* Dynamic Look-Up Table Block: '<S160>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Desired_Hood_Pos_Shoot),
                         &rtb_TmpSignalConversionAtLoo_d0[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLoo_fl[0], 7U);

    /* S-Function (sfix_look1_dyn): '<S159>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S159>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_Switch_cn), &rtb_TmpSignalConversionAtLoo_ga[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLoo_fl[0], 7U);

    /* S-Function (sfix_look1_dyn): '<S161>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S161>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd),
                         &rtb_TmpSignalConversionAtLoo_cj[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLoo_fl[0], 7U);

    /* S-Function (sfix_look1_dyn): '<S161>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S161>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd),
                         &rtb_TmpSignalConversionAtLoo_mk[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLoo_fl[0], 7U);

    /* Switch: '<S161>/Switch' incorporates:
     *  Constant: '<S161>/Constant'
     *  Constant: '<S161>/Constant1'
     *  Sum: '<S161>/Add'
     *  UnitDelay: '<S161>/Unit Delay'
     */
    if (Robot_Control_B.RB_Transfer_Init != 0.0) {
      rtb_Subtract_c3 = 0.0;
    } else {
      rtb_Subtract_c3 = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    /* End of Switch: '<S161>/Switch' */

    /* Switch: '<S161>/Switch1' incorporates:
     *  Constant: '<S161>/Constant2'
     *  RelationalOperator: '<S161>/GreaterThan'
     */
    if (rtb_Subtract_c3 < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S144>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S144>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    /* End of Switch: '<S161>/Switch1' */

    /* Merge: '<S144>/Merge3' incorporates:
     *  Gain: '<S171>/Gain1'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_Switch_cn;

    /* Trigonometry: '<S174>/Atan1' incorporates:
     *  Constant: '<S174>/Constant'
     *  Constant: '<S174>/Constant1'
     *  Sum: '<S174>/Subtract3'
     *  Sum: '<S174>/Subtract4'
     */
    rtb_Switch_cn = rt_atan2d_snf(1.0 - Robot_Control_B.KF_Position_Y, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S174>/Mod' incorporates:
     *  Constant: '<S174>/Constant4'
     */
    rtb_Switch2_n = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Sum: '<S174>/Subtract2' incorporates:
     *  Constant: '<S162>/Constant10'
     *  Sum: '<S174>/Subtract8'
     */
    rtb_Switch1_k = Field_Length - Robot_Control_B.KF_Position_X;

    /* Trigonometry: '<S174>/Atan2' incorporates:
     *  Constant: '<S174>/Constant2'
     *  Sum: '<S174>/Subtract1'
     *  Sum: '<S174>/Subtract2'
     */
    rtb_Switch_cn = rt_atan2d_snf(1.0 - Robot_Control_B.KF_Position_Y,
      rtb_Switch1_k);

    /* Math: '<S174>/Mod1' incorporates:
     *  Constant: '<S174>/Constant5'
     */
    rtb_Switch4_fu = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Sum: '<S174>/Subtract5' incorporates:
     *  Constant: '<S162>/Constant11'
     *  Sum: '<S174>/Subtract7'
     */
    rtb_dy_n = Field_Width_Pass - Robot_Control_B.KF_Position_Y;

    /* Trigonometry: '<S174>/Atan3' incorporates:
     *  Constant: '<S174>/Constant3'
     *  Sum: '<S174>/Subtract5'
     *  Sum: '<S174>/Subtract6'
     */
    rtb_Switch_cn = rt_atan2d_snf(rtb_dy_n, 0.0 - Robot_Control_B.KF_Position_X);

    /* Math: '<S174>/Mod2' incorporates:
     *  Constant: '<S174>/Constant6'
     */
    rtb_Switch1_c = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Trigonometry: '<S174>/Atan4' */
    rtb_Switch_cn = rt_atan2d_snf(rtb_dy_n, rtb_Switch1_k);

    /* Math: '<S174>/Mod3' incorporates:
     *  Constant: '<S174>/Constant7'
     */
    rtb_Switch1_k = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Merge: '<S144>/Merge' incorporates:
     *  Constant: '<S178>/Constant'
     *  Constant: '<S178>/Shooter Assembly Offset in Robot'
     *  Constant: '<S178>/Shooter Assembly Offset in Robot1'
     *  Gain: '<S182>/Gain1'
     *  MinMax: '<S178>/Max'
     *  Product: '<S178>/Divide'
     *  Sum: '<S178>/Add'
     *  Sum: '<S178>/Subtract1'
     *  Sum: '<S178>/Subtract2'
     *  Trigonometry: '<S178>/Atan2'
     *  Trigonometry: '<S178>/Tanh1'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = (rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      atan(-0.07467599999999999 / fmax(Robot_Control_B.RB_Desired_Shot_Distance,
      0.001))) + (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);

    /* Switch: '<S177>/Switch1' incorporates:
     *  Constant: '<S162>/Constant3'
     *  Constant: '<S162>/Constant7'
     *  Inport: '<Root>/IsBlueAlliance'
     */
    if (Robot_Control_U.IsBlueAlliance > 0.0) {
      rtb_Switch_cn = Blue_Hub_LeftY;
    } else {
      rtb_Switch_cn = Red_Hub_LeftY;
    }

    /* End of Switch: '<S177>/Switch1' */

    /* Sum: '<S175>/Subtract3' */
    rtb_dy_n = rtb_Switch_cn - Robot_Control_B.KF_Position_Y;

    /* Switch: '<S177>/Switch' incorporates:
     *  Constant: '<S162>/Constant2'
     *  Constant: '<S162>/Constant4'
     *  Constant: '<S162>/Constant5'
     *  Constant: '<S162>/Constant6'
     *  Constant: '<S162>/Constant8'
     *  Constant: '<S162>/Constant9'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Switch: '<S177>/Switch2'
     *  Switch: '<S177>/Switch3'
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

    /* End of Switch: '<S177>/Switch' */

    /* Trigonometry: '<S175>/Atan1' incorporates:
     *  Sum: '<S175>/Subtract4'
     */
    rtb_Switch_cn = rt_atan2d_snf(rtb_dy_n, rtb_Switch_cn -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S175>/Mod1' incorporates:
     *  Constant: '<S175>/Constant'
     */
    rtb_Switch_cn = rt_modd_snf(rtb_Switch_cn, 6.283185307179586);

    /* Math: '<S175>/Mod2' incorporates:
     *  Constant: '<S175>/Constant1'
     *  Sum: '<S175>/Subtract1'
     *  Sum: '<S175>/Subtract2'
     *  Switch: '<S177>/Switch2'
     *  Switch: '<S177>/Switch3'
     *  Trigonometry: '<S175>/Atan3'
     */
    rtb_dy_n = rt_modd_snf(rt_atan2d_snf(rtb_Add_ir -
      Robot_Control_B.KF_Position_Y, rtb_Add_di - Robot_Control_B.KF_Position_X),
      6.283185307179586);

    /* Switch: '<S175>/Switch' incorporates:
     *  Abs: '<S175>/Abs'
     *  Abs: '<S175>/Abs1'
     *  RelationalOperator: '<S175>/GreaterThan'
     */
    if (!(rtb_Switch_cn < rtb_dy_n)) {
      rtb_Switch_cn = rtb_dy_n;
    }

    /* End of Switch: '<S175>/Switch' */

    /* Math: '<S162>/Math Function' incorporates:
     *  Constant: '<S162>/Constant1'
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_dy_n = rt_modd_snf(Robot_Control_U.Gyro_Angle_Field_rad,
      6.283185307179586);

    /* If: '<S176>/If' incorporates:
     *  Switch: '<S181>/Switch'
     */
    if (Robot_Control_B.RB_Desired_Target_Y > Field_Hub_Y) {
      /* Outputs for IfAction SubSystem: '<S176>/If Action Subsystem' incorporates:
       *  ActionPort: '<S180>/Action Port'
       */
      /* Switch: '<S180>/Switch' */
      if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
        /* Abs: '<S162>/Abs' */
        rtb_Switch2_n = rtb_Switch1_k;
      } else {
        /* Abs: '<S162>/Abs' */
        rtb_Switch2_n = rtb_Switch1_c;
      }

      /* End of Switch: '<S180>/Switch' */
      /* End of Outputs for SubSystem: '<S176>/If Action Subsystem' */

      /* Outputs for IfAction SubSystem: '<S176>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
    } else if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
      /* Switch: '<S181>/Switch' incorporates:
       *  Abs: '<S162>/Abs'
       */
      rtb_Switch2_n = rtb_Switch4_fu;

      /* End of Outputs for SubSystem: '<S176>/If Action Subsystem1' */
    }

    /* End of If: '<S176>/If' */

    /* Switch: '<S179>/Switch' incorporates:
     *  Logic: '<S179>/AND'
     *  Logic: '<S179>/AND1'
     *  RelationalOperator: '<S179>/GreaterThan'
     *  RelationalOperator: '<S179>/GreaterThan1'
     *  RelationalOperator: '<S179>/GreaterThan2'
     *  RelationalOperator: '<S179>/GreaterThan3'
     *  RelationalOperator: '<S179>/GreaterThan4'
     */
    if (rtb_Switch2_n < rtb_Switch_cn) {
      rtb_Compare_ky = ((rtb_dy_n > rtb_Switch2_n) && (rtb_dy_n < rtb_Switch_cn));
    } else {
      rtb_Compare_ky = ((rtb_dy_n > rtb_Switch_cn) && (rtb_dy_n < rtb_Switch2_n));
    }

    /* Merge: '<S144>/Merge4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S162>/AND'
     *  Logic: '<S179>/Logical Operator'
     *  Switch: '<S179>/Switch'
     */
    Robot_Control_B.Can_Pass = (rtb_Compare_bd &&
      ((Robot_Control_U.IsBlueAlliance != 0.0) == ((int32_T)rtb_Compare_ky)));

    /* Update for UnitDelay: '<S161>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Subtract_c3;

    /* End of Outputs for SubSystem: '<S144>/Desired Shooting Parameters Math' */
  } else {
    /* Outputs for IfAction SubSystem: '<S144>/Shooter Not Active' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    /* Merge: '<S144>/Merge' incorporates:
     *  Constant: '<S156>/Constant2'
     *  SignalConversion generated from: '<S156>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;

    /* Merge: '<S144>/Merge1' incorporates:
     *  Constant: '<S156>/Constant'
     *  SignalConversion generated from: '<S156>/Desired_Shooter_Speed'
     */
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;

    /* Merge: '<S144>/Merge2' incorporates:
     *  Constant: '<S156>/Constant3'
     *  SignalConversion generated from: '<S156>/Desired_Hood_Pos'
     */
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;

    /* Merge: '<S144>/Merge3' incorporates:
     *  Constant: '<S156>/Constant1'
     *  SignalConversion generated from: '<S156>/Allowed_Shoot_Gyro_Error_rad'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* Merge: '<S144>/Merge4' incorporates:
     *  Constant: '<S156>/Constant4'
     *  SignalConversion generated from: '<S156>/Can_Pass'
     */
    Robot_Control_B.Can_Pass = true;

    /* End of Outputs for SubSystem: '<S144>/Shooter Not Active' */
  }

  /* End of If: '<S144>/If' */

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

  /* Sum: '<S401>/Add1' incorporates:
   *  Constant: '<S401>/Constant3'
   *  Constant: '<S401>/Constant4'
   *  Math: '<S401>/Math Function'
   *  Sum: '<S400>/Sum'
   *  Sum: '<S401>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf((rtb_Add_ir - rtb_Add_di) +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Gain: '<S404>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.29577951308232 *
    rtb_Optimized_Module_Angle;

  /* Abs: '<S383>/Abs1' */
  rtb_Switch4_fu = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S403>/Sum1' incorporates:
   *  Constant: '<S400>/Constant2'
   *  Product: '<S403>/Product'
   *  Sum: '<S403>/Sum'
   *  UnitDelay: '<S403>/Unit Delay1'
   */
  rtb_Switch_cn = ((rtb_Optimized_Module_Angle -
                    Robot_Control_DW.UnitDelay1_DSTATE) *
                   Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S400>/Product' incorporates:
   *  Constant: '<S400>/Constant3'
   */
  rtb_Subtract_c3 = rtb_Switch_cn * Steering_Heading_Control_D;

  /* Sum: '<S402>/Diff' incorporates:
   *  UnitDelay: '<S402>/UD'
   *
   * Block description for '<S402>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S402>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_di = rtb_Subtract_c3 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S400>/Saturation' */
  if (rtb_Add_di > Steering_Heading_Control_D_UL) {
    rtb_Add_di = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_di < Steering_Heading_Control_D_LL) {
    rtb_Add_di = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S400>/Add' incorporates:
   *  Gain: '<S400>/Gain1'
   *  Saturate: '<S400>/Saturation'
   */
  rtb_Switch1_k = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle) +
    rtb_Add_di;

  /* Sum: '<S400>/Subtract' incorporates:
   *  Constant: '<S400>/Constant'
   */
  rtb_Switch1_c = Steering_Heading_Control_Total_UL - rtb_Switch1_k;

  /* Sum: '<S400>/Sum2' incorporates:
   *  Gain: '<S400>/Gain2'
   *  UnitDelay: '<S400>/Unit Delay'
   */
  rtb_Switch2_n = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S405>/Switch2' incorporates:
   *  RelationalOperator: '<S405>/LowerRelop1'
   */
  if (!(rtb_Switch2_n > rtb_Switch1_c)) {
    /* Sum: '<S400>/Subtract1' incorporates:
     *  Constant: '<S400>/Constant1'
     */
    rtb_Switch1_c = Steering_Heading_Control_Total_LL - rtb_Switch1_k;

    /* Switch: '<S405>/Switch' incorporates:
     *  RelationalOperator: '<S405>/UpperRelop'
     */
    if (!(rtb_Switch2_n < rtb_Switch1_c)) {
      rtb_Switch1_c = rtb_Switch2_n;
    }

    /* End of Switch: '<S405>/Switch' */
  }

  /* End of Switch: '<S405>/Switch2' */

  /* Saturate: '<S400>/Saturation1' */
  if (rtb_Switch1_c > Steering_Heading_Control_I_UL) {
    rtb_Switch2_n = Steering_Heading_Control_I_UL;
  } else if (rtb_Switch1_c < Steering_Heading_Control_I_LL) {
    rtb_Switch2_n = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch2_n = rtb_Switch1_c;
  }

  /* End of Saturate: '<S400>/Saturation1' */

  /* Sum: '<S400>/Add1' */
  rtb_Add_di = rtb_Switch1_k + rtb_Switch2_n;

  /* Saturate: '<S400>/Saturation2' */
  if (rtb_Add_di > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S400>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_di < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S400>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S400>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_di;
  }

  /* End of Saturate: '<S400>/Saturation2' */

  /* Abs: '<S383>/Abs' */
  rtb_Switch1_c = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S383>/Add dither' */
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

  /* End of Chart: '<S383>/Add dither' */

  /* Switch: '<S383>/Switch' incorporates:
   *  Constant: '<S383>/Constant'
   *  Constant: '<S399>/Constant'
   *  Product: '<S383>/Product'
   *  RelationalOperator: '<S399>/Compare'
   *  Signum: '<S383>/Sign'
   */
  if (rtb_Switch1_c > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S383>/Sign' */
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

  /* End of Switch: '<S383>/Switch' */

  /* Signum: '<S382>/Sign2' incorporates:
   *  UnitDelay: '<S382>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_ir = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S382>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Add_di = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (rtb_Optimized_Module_Angle > 0.0);
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
   *  Constant: '<S391>/Constant'
   *  Constant: '<S392>/Constant'
   *  Logic: '<S382>/or'
   *  Product: '<S382>/Product1'
   *  RelationalOperator: '<S391>/Compare'
   *  RelationalOperator: '<S392>/Compare'
   *  UnitDelay: '<S382>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch8 = rtb_Optimized_Module_Angle;
  } else {
    rtb_Switch8 = 0.0;
  }

  /* End of Switch: '<S382>/Switch' */

  /* Switch: '<S397>/Init' incorporates:
   *  UnitDelay: '<S397>/FixPt Unit Delay1'
   *  UnitDelay: '<S397>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch8;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S397>/Init' */

  /* RelationalOperator: '<S393>/Compare' incorporates:
   *  Constant: '<S393>/Constant'
   */
  rtb_Compare_bd = (rtb_Switch8 == 0.0);

  /* RelationalOperator: '<S394>/Compare' incorporates:
   *  Constant: '<S394>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Switch8 > 0.0);

  /* Abs: '<S382>/Abs' incorporates:
   *  Sum: '<S382>/Subtract'
   *  UnitDelay: '<S382>/Unit Delay'
   */
  rtb_Switch4_fu = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                        rtb_Optimized_Module_Angle);

  /* Switch: '<S382>/Switch5' incorporates:
   *  Constant: '<S382>/Constant1'
   *  Switch: '<S382>/Switch1'
   *  UnaryMinus: '<S382>/Unary Minus'
   */
  if (rtb_Compare_bd) {
    /* SignalConversion generated from: '<S382>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S382>/Constant4'
     *  Constant: '<S382>/Constant6'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S382>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S382>/Constant2'
     *  Constant: '<S382>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S382>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S382>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Switch4_fu,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Switch4_fu = rtb_LookupTableDynamic;
    rtb_Add_ir = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S382>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S382>/Constant10'
     *  Constant: '<S382>/Constant8'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S382>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S382>/Constant7'
     *  Constant: '<S382>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S382>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S382>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Switch4_fu,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Switch4_fu = rtb_LookupTableDynamic1;

    /* Switch: '<S382>/Switch3' incorporates:
     *  Constant: '<S382>/Constant1'
     *  Constant: '<S382>/Constant3'
     *  UnaryMinus: '<S382>/Unary Minus'
     */
    if (rtb_LogicalOperator1) {
      rtb_Add_ir = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_ir = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S382>/Switch3' */
  }

  /* End of Switch: '<S382>/Switch5' */

  /* Product: '<S382>/Product' incorporates:
   *  Switch: '<S382>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_ir * rtb_Switch4_fu;

  /* Sum: '<S395>/Sum1' */
  rtb_Switch1_c = rtb_Switch8 - rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S396>/Switch2' incorporates:
   *  RelationalOperator: '<S396>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S382>/Switch2' incorporates:
     *  Constant: '<S382>/Constant1'
     *  Switch: '<S382>/Switch4'
     */
    if (rtb_Compare_bd) {
      rtb_Switch1_k = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S382>/Switch4' incorporates:
       *  Constant: '<S382>/Constant1'
       */
      rtb_Switch1_k = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S382>/Switch4' incorporates:
       *  Constant: '<S382>/Constant3'
       *  UnaryMinus: '<S382>/Unary Minus1'
       */
      rtb_Switch1_k = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S382>/Switch2' */

    /* Product: '<S382>/Product2' */
    rtb_Switch1_k *= rtb_Switch4_fu;

    /* Switch: '<S396>/Switch' incorporates:
     *  RelationalOperator: '<S396>/UpperRelop'
     */
    if (rtb_Switch1_c < rtb_Switch1_k) {
      rtb_Optimized_Module_Angle = rtb_Switch1_k;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch1_c;
    }

    /* End of Switch: '<S396>/Switch' */
  }

  /* End of Switch: '<S396>/Switch2' */

  /* Sum: '<S395>/Sum' */
  rtb_Switch4_fu = rtb_Optimized_Module_Angle + rtb_MatrixConcatenate_b_idx_0;

  /* Signum: '<S381>/Sign2' incorporates:
   *  UnitDelay: '<S381>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_ir = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S381>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S381>/Product1' incorporates:
   *  Signum: '<S381>/Sign1'
   *  Signum: '<S381>/Sign2'
   */
  rtb_Add_ir *= rtb_Add_di;
  if (rtIsNaN(rtb_Add_ir)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_ir, 256.0);
  }

  /* Switch: '<S381>/Switch' incorporates:
   *  Constant: '<S381>/Constant'
   *  Constant: '<S384>/Constant'
   *  Constant: '<S385>/Constant'
   *  Logic: '<S381>/or'
   *  Product: '<S381>/Product1'
   *  RelationalOperator: '<S384>/Compare'
   *  RelationalOperator: '<S385>/Compare'
   *  UnitDelay: '<S381>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S381>/Switch' */

  /* Switch: '<S390>/Init' incorporates:
   *  UnitDelay: '<S390>/FixPt Unit Delay1'
   *  UnitDelay: '<S390>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S390>/Init' */

  /* RelationalOperator: '<S386>/Compare' incorporates:
   *  Constant: '<S386>/Constant'
   */
  rtb_Compare_bd = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S387>/Compare' incorporates:
   *  Constant: '<S387>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S381>/Abs' incorporates:
   *  Sum: '<S381>/Subtract'
   *  UnitDelay: '<S381>/Unit Delay'
   */
  rtb_Switch1_k = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                       Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S381>/Switch5' incorporates:
   *  Constant: '<S381>/Constant1'
   *  Switch: '<S381>/Switch1'
   *  UnaryMinus: '<S381>/Unary Minus'
   */
  if (rtb_Compare_bd) {
    /* SignalConversion generated from: '<S381>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S381>/Constant4'
     *  Constant: '<S381>/Constant6'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S381>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S381>/Constant2'
     *  Constant: '<S381>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S381>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S381>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Switch1_k,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Switch1_k = rtb_LookupTableDynamic_p;
    rtb_Add_ir = -Steering_Relative_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S381>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S381>/Constant10'
     *  Constant: '<S381>/Constant8'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S381>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S381>/Constant7'
     *  Constant: '<S381>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S381>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S381>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Switch1_k,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Switch1_k = rtb_LookupTableDynamic1_g;

    /* Switch: '<S381>/Switch3' incorporates:
     *  Constant: '<S381>/Constant1'
     *  Constant: '<S381>/Constant3'
     *  UnaryMinus: '<S381>/Unary Minus'
     */
    if (rtb_LogicalOperator1) {
      rtb_Add_ir = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_ir = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S381>/Switch3' */
  }

  /* End of Switch: '<S381>/Switch5' */

  /* Product: '<S381>/Product' incorporates:
   *  Switch: '<S381>/Switch1'
   */
  rtb_Switch8 = rtb_Add_ir * rtb_Switch1_k;

  /* Sum: '<S388>/Sum1' */
  rtb_Switch1_c = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle;

  /* Switch: '<S389>/Switch2' incorporates:
   *  RelationalOperator: '<S389>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_Switch8)) {
    /* Switch: '<S381>/Switch2' incorporates:
     *  Constant: '<S381>/Constant1'
     *  Constant: '<S381>/Constant3'
     *  Switch: '<S381>/Switch4'
     *  UnaryMinus: '<S381>/Unary Minus1'
     */
    if (rtb_Compare_bd) {
      rtb_Add_ir = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S381>/Switch4' incorporates:
       *  Constant: '<S381>/Constant1'
       */
      rtb_Add_ir = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_ir = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S381>/Product2' incorporates:
     *  Switch: '<S381>/Switch2'
     */
    rtb_dy_n = rtb_Add_ir * rtb_Switch1_k;

    /* Switch: '<S389>/Switch' incorporates:
     *  RelationalOperator: '<S389>/UpperRelop'
     */
    if (rtb_Switch1_c < rtb_dy_n) {
      rtb_Switch8 = rtb_dy_n;
    } else {
      rtb_Switch8 = rtb_Switch1_c;
    }

    /* End of Switch: '<S389>/Switch' */
  }

  /* End of Switch: '<S389>/Switch2' */

  /* Sum: '<S388>/Sum' */
  rtb_Switch1_c = rtb_Switch8 + rtb_Optimized_Module_Angle;

  /* Switch: '<S371>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (rtb_Button_Spinup_Enable || (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S371>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch4_fu;
  } else {
    /* Switch: '<S371>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch1_c;
  }

  /* End of Switch: '<S371>/Switch' */

  /* Fcn: '<S414>/r->x' incorporates:
   *  Fcn: '<S419>/r->x'
   *  Fcn: '<S424>/r->x'
   *  Fcn: '<S429>/r->x'
   */
  rtb_Switch1_k = cos(Robot_Control_B.Translation_Steering_Cmd);
  rtb_dy_n = Robot_Control_B.Translation_Speed_RL * rtb_Switch1_k;

  /* Sum: '<S408>/Add' incorporates:
   *  Fcn: '<S414>/r->x'
   *  Fcn: '<S415>/r->x'
   */
  rtb_TmpSignalConversionAtLookup[0] = (Robot_Control_B.Steering_Localized_Cmd *
    cos(Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_dy_n;

  /* Fcn: '<S414>/theta->y' incorporates:
   *  Fcn: '<S419>/theta->y'
   *  Fcn: '<S424>/theta->y'
   *  Fcn: '<S429>/theta->y'
   */
  rtb_Switch1_k = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S408>/Add' incorporates:
   *  Fcn: '<S414>/theta->y'
   *  Fcn: '<S415>/theta->y'
   */
  rtb_TmpSignalConversionAtLookup[1] = (Robot_Control_B.Steering_Localized_Cmd *
    sin(Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1_k;

  /* Sum: '<S409>/Add' incorporates:
   *  Fcn: '<S420>/r->x'
   *  Fcn: '<S420>/theta->y'
   */
  rtb_TmpSignalConversionAtLoo_mu[0] = (Robot_Control_B.Steering_Localized_Cmd *
    cos(Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_dy_n;
  rtb_TmpSignalConversionAtLoo_mu[1] = (Robot_Control_B.Steering_Localized_Cmd *
    sin(Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1_k;

  /* Sum: '<S410>/Add' incorporates:
   *  Fcn: '<S425>/r->x'
   *  Fcn: '<S425>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_dy_n;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1_k;

  /* Sum: '<S411>/Add' incorporates:
   *  Fcn: '<S430>/r->x'
   *  Fcn: '<S430>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_dy_n;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1_k;

  /* Fcn: '<S428>/x->r' */
  rtb_Switch8 = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S431>/Compare' incorporates:
   *  Constant: '<S431>/Constant'
   */
  rtb_LogicalOperator2_e = (rtb_Switch8 == 0.0);

  /* Switch: '<S427>/Switch1' */
  if (rtb_LogicalOperator2_e) {
    /* Switch: '<S427>/Switch1' incorporates:
     *  Constant: '<S427>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S427>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch8;
  }

  /* End of Switch: '<S427>/Switch1' */

  /* Fcn: '<S413>/x->r' */
  rtb_Switch8 = rt_hypotd_snf(rtb_TmpSignalConversionAtLookup[0],
    rtb_TmpSignalConversionAtLookup[1]);

  /* RelationalOperator: '<S416>/Compare' incorporates:
   *  Constant: '<S416>/Constant'
   */
  rtb_Compare_mq = (rtb_Switch8 == 0.0);

  /* Switch: '<S412>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S412>/Switch1' incorporates:
     *  Constant: '<S412>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S412>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch8;
  }

  /* End of Switch: '<S412>/Switch1' */

  /* Fcn: '<S418>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu
    [0], rtb_TmpSignalConversionAtLoo_mu[1]);

  /* RelationalOperator: '<S421>/Compare' incorporates:
   *  Constant: '<S421>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S417>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S417>/Switch1' incorporates:
     *  Constant: '<S417>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S417>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S417>/Switch1' */

  /* Fcn: '<S423>/x->r' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S426>/Compare' incorporates:
   *  Constant: '<S426>/Constant'
   */
  rtb_Compare_bd = (rtb_Optimized_Module_Angle == 0.0);

  /* Switch: '<S422>/Switch1' */
  if (rtb_Compare_bd) {
    /* Switch: '<S422>/Switch1' incorporates:
     *  Constant: '<S422>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S422>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle;
  }

  /* End of Switch: '<S422>/Switch1' */

  /* Product: '<S407>/Divide' incorporates:
   *  Abs: '<S407>/Abs'
   *  Abs: '<S407>/Abs1'
   *  Abs: '<S407>/Abs2'
   *  Abs: '<S407>/Abs3'
   *  Constant: '<S407>/Constant'
   *  MinMax: '<S407>/Max'
   */
  rtb_Switch8 = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S407>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch8;

  /* Switch: '<S427>/Switch' */
  if (!rtb_LogicalOperator2_e) {
    /* Switch: '<S427>/Switch' incorporates:
     *  Fcn: '<S428>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S427>/Switch' */

  /* Trigonometry: '<S361>/Cos4' incorporates:
   *  Switch: '<S350>/Angle_Switch'
   *  Trigonometry: '<S360>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S361>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S359>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S361>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S361>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S359>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S361>/Subtract1' incorporates:
   *  Product: '<S361>/Product2'
   *  Product: '<S361>/Product3'
   *  Trigonometry: '<S361>/Cos4'
   */
  rtb_Switch1_k = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) + (rtb_Minus_k_idx_1 *
    rtb_Optimized_Module_Angle);

  /* Sum: '<S361>/Subtract' incorporates:
   *  Product: '<S361>/Product'
   *  Product: '<S361>/Product1'
   *  Trigonometry: '<S361>/Cos4'
   */
  rtb_dy_n = (rtb_Minus_k_idx_0 * rtb_Optimized_Module_Angle) -
    (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S361>/Hypot' */
  rtb_MatrixConcatenate_idx_0 = rt_hypotd_snf(rtb_dy_n, rtb_Switch1_k);

  /* Switch: '<S361>/Switch' incorporates:
   *  Constant: '<S361>/Constant'
   *  Constant: '<S361>/Constant1'
   *  Constant: '<S362>/Constant'
   *  Product: '<S361>/Divide'
   *  Product: '<S361>/Divide1'
   *  RelationalOperator: '<S362>/Compare'
   *  Switch: '<S361>/Switch1'
   */
  if (rtb_MatrixConcatenate_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_k / rtb_MatrixConcatenate_idx_0;
    rtb_Optimized_Module_Angle = rtb_dy_n / rtb_MatrixConcatenate_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S361>/Switch' */

  /* Switch: '<S350>/Speed_Switch' incorporates:
   *  Abs: '<S350>/Abs'
   *  Constant: '<S358>/Constant'
   *  RelationalOperator: '<S358>/Compare'
   *  Switch: '<S350>/Angle_Switch'
   *  Trigonometry: '<S360>/Atan1'
   *  Trigonometry: '<S361>/Atan1'
   *  UnaryMinus: '<S350>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_ir = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S360>/Subtract1' incorporates:
     *  Product: '<S360>/Product2'
     *  Product: '<S360>/Product3'
     *  Trigonometry: '<S360>/Sin4'
     *  UnaryMinus: '<S350>/Unary Minus'
     */
    rtb_Switch1_k = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Sin5_c) +
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S360>/Subtract' incorporates:
     *  Product: '<S360>/Product'
     *  Product: '<S360>/Product1'
     *  Trigonometry: '<S360>/Sin4'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_0 *
      Robot_Control_ConstB.Cos5_b) - (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S360>/Hypot' */
    rtb_dy_n = rt_hypotd_snf(rtb_MatrixConcatenate_idx_0, rtb_Switch1_k);

    /* Switch: '<S360>/Switch1' incorporates:
     *  Constant: '<S360>/Constant'
     *  Constant: '<S360>/Constant1'
     *  Constant: '<S363>/Constant'
     *  Product: '<S360>/Divide'
     *  Product: '<S360>/Divide1'
     *  RelationalOperator: '<S363>/Compare'
     *  Switch: '<S360>/Switch'
     */
    if (rtb_dy_n > 1.0E-6) {
      rtb_MatrixConcatenate_idx_0 /= rtb_dy_n;
      rtb_Switch1_k /= rtb_dy_n;
    } else {
      rtb_MatrixConcatenate_idx_0 = 1.0;
      rtb_Switch1_k = 0.0;
    }

    /* End of Switch: '<S360>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Switch1_k, rtb_MatrixConcatenate_idx_0);
  } else {
    rtb_Add_ir = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S353>/Product2' incorporates:
   *  Constant: '<S353>/Constant'
   *  Switch: '<S350>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_ir * 1154.7574092481445;

  /* Signum: '<S348>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_ir = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S348>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S351>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S352>/Sum'
   */
  rtb_Optimized_Module_Angle = rtb_uDLookupTable -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S283>/Product' incorporates:
   *  Abs: '<S348>/Abs'
   *  Abs: '<S351>/Abs'
   *  Constant: '<S354>/Constant'
   *  Constant: '<S364>/Constant3'
   *  Constant: '<S364>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S348>/OR'
   *  Lookup_n-D: '<S351>/1-D Lookup Table'
   *  Math: '<S364>/Math Function'
   *  RelationalOperator: '<S348>/Equal1'
   *  RelationalOperator: '<S354>/Compare'
   *  Signum: '<S348>/Sign'
   *  Signum: '<S348>/Sign1'
   *  Sum: '<S351>/Add'
   *  Sum: '<S364>/Add1'
   *  Sum: '<S364>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_ir == rtb_Add_di) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.141592653589793) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data, rtCP_uDLookupTable_tableData_g,
                    1U);

  /* Gain: '<S349>/Gain' */
  rtb_MatrixConcatenate_idx_0 = Drive_Motor_Control_FF *
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S349>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S356>/Sum1' incorporates:
   *  Constant: '<S349>/Constant2'
   *  Product: '<S356>/Product'
   *  Sum: '<S356>/Sum'
   *  UnitDelay: '<S356>/Unit Delay1'
   */
  rtb_Switch1_k = ((rtb_MatrixConcatenate_b_idx_0 -
                    Robot_Control_DW.UnitDelay1_DSTATE_j) *
                   Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S349>/Product' incorporates:
   *  Constant: '<S349>/Constant3'
   */
  rtb_dy_n = rtb_Switch1_k * Drive_Motor_Control_D;

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
  rtb_Add_di = rtb_dy_n - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S349>/Saturation' */
  if (rtb_Add_di > Drive_Motor_Control_D_UL) {
    rtb_Add_di = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_di < Drive_Motor_Control_D_LL) {
    rtb_Add_di = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S349>/Add' incorporates:
   *  Gain: '<S349>/Gain1'
   *  Saturate: '<S349>/Saturation'
   */
  rtb_Add_di += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_MatrixConcatenate_idx_0;

  /* Saturate: '<S349>/Saturation2' */
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

  /* End of Saturate: '<S349>/Saturation2' */

  /* Sum: '<S365>/Add1' incorporates:
   *  Constant: '<S365>/Constant3'
   *  Constant: '<S365>/Constant4'
   *  Math: '<S365>/Math Function'
   *  Sum: '<S365>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S367>/Sum1' incorporates:
   *  Constant: '<S352>/Constant2'
   *  Product: '<S367>/Product'
   *  Sum: '<S367>/Sum'
   *  UnitDelay: '<S367>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S352>/Product' incorporates:
   *  Constant: '<S352>/Constant3'
   */
  rtb_Product_d1 = rtb_MatrixConcatenate_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S366>/Diff' incorporates:
   *  UnitDelay: '<S366>/UD'
   *
   * Block description for '<S366>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S366>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_di = rtb_Product_d1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S352>/Saturation' */
  if (rtb_Add_di > Steering_Motor_Control_D_UL) {
    rtb_Add_di = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_di < Steering_Motor_Control_D_LL) {
    rtb_Add_di = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S352>/Add' incorporates:
   *  Gain: '<S352>/Gain1'
   *  Saturate: '<S352>/Saturation'
   */
  rtb_Add_pw = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_di;

  /* Sum: '<S352>/Subtract' incorporates:
   *  Constant: '<S352>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_pw;

  /* Sum: '<S352>/Sum2' incorporates:
   *  Gain: '<S352>/Gain2'
   *  UnitDelay: '<S352>/Unit Delay'
   */
  rtb_Sum2_fc = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S368>/Switch2' incorporates:
   *  Constant: '<S352>/Constant'
   *  RelationalOperator: '<S368>/LowerRelop1'
   *  Sum: '<S352>/Subtract'
   */
  if (!(rtb_Sum2_fc > (1.0 - rtb_Add_pw))) {
    /* Switch: '<S368>/Switch' incorporates:
     *  Constant: '<S352>/Constant1'
     *  RelationalOperator: '<S368>/UpperRelop'
     *  Sum: '<S352>/Subtract1'
     */
    if (rtb_Sum2_fc < (-1.0 - rtb_Add_pw)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_pw;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_fc;
    }

    /* End of Switch: '<S368>/Switch' */
  }

  /* End of Switch: '<S368>/Switch2' */

  /* Saturate: '<S352>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S352>/Saturation1' */

  /* Sum: '<S352>/Add1' */
  rtb_Add_di = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S352>/Saturation2' */
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

  /* End of Saturate: '<S352>/Saturation2' */

  /* Product: '<S407>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch8;

  /* Switch: '<S412>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S412>/Switch' incorporates:
     *  Fcn: '<S413>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLookup[1], rtb_TmpSignalConversionAtLookup[0]);
  }

  /* End of Switch: '<S412>/Switch' */

  /* Trigonometry: '<S298>/Cos4' incorporates:
   *  Switch: '<S287>/Angle_Switch'
   *  Trigonometry: '<S297>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S298>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S296>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S298>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S298>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S296>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S298>/Subtract1' incorporates:
   *  Product: '<S298>/Product2'
   *  Product: '<S298>/Product3'
   *  Trigonometry: '<S298>/Cos4'
   */
  rtb_Add_pw = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) + (rtb_Minus_k_idx_1 *
    rtb_Optimized_Module_Angle);

  /* Sum: '<S298>/Subtract' incorporates:
   *  Product: '<S298>/Product'
   *  Product: '<S298>/Product1'
   *  Trigonometry: '<S298>/Cos4'
   */
  rtb_Subtract1_bm = (rtb_Minus_k_idx_0 * rtb_Optimized_Module_Angle) -
    (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S298>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract1_bm, rtb_Add_pw);

  /* Switch: '<S298>/Switch' incorporates:
   *  Constant: '<S298>/Constant'
   *  Constant: '<S298>/Constant1'
   *  Constant: '<S299>/Constant'
   *  Product: '<S298>/Divide'
   *  Product: '<S298>/Divide1'
   *  RelationalOperator: '<S299>/Compare'
   *  Switch: '<S298>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pw / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle = rtb_Subtract1_bm / rtb_Hypot_g5;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S298>/Switch' */

  /* Switch: '<S287>/Speed_Switch' incorporates:
   *  Abs: '<S287>/Abs'
   *  Constant: '<S295>/Constant'
   *  RelationalOperator: '<S295>/Compare'
   *  Switch: '<S287>/Angle_Switch'
   *  Trigonometry: '<S297>/Atan1'
   *  Trigonometry: '<S298>/Atan1'
   *  UnaryMinus: '<S287>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_ir = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S297>/Subtract1' incorporates:
     *  Product: '<S297>/Product2'
     *  Product: '<S297>/Product3'
     *  Trigonometry: '<S297>/Sin4'
     *  UnaryMinus: '<S287>/Unary Minus'
     */
    rtb_Add_pw = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Sin5) +
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5);

    /* Sum: '<S297>/Subtract' incorporates:
     *  Product: '<S297>/Product'
     *  Product: '<S297>/Product1'
     *  Trigonometry: '<S297>/Sin4'
     */
    rtb_Hypot_g5 = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5) -
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5);

    /* Math: '<S297>/Hypot' */
    rtb_Subtract1_bm = rt_hypotd_snf(rtb_Hypot_g5, rtb_Add_pw);

    /* Switch: '<S297>/Switch1' incorporates:
     *  Constant: '<S297>/Constant'
     *  Constant: '<S297>/Constant1'
     *  Constant: '<S300>/Constant'
     *  Product: '<S297>/Divide'
     *  Product: '<S297>/Divide1'
     *  RelationalOperator: '<S300>/Compare'
     *  Switch: '<S297>/Switch'
     */
    if (rtb_Subtract1_bm > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Subtract1_bm;
      rtb_Add_pw /= rtb_Subtract1_bm;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S297>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_pw, rtb_Hypot_g5);
  } else {
    rtb_Add_ir = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S290>/Product2' incorporates:
   *  Constant: '<S290>/Constant'
   *  Switch: '<S287>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_ir * 1154.7574092481445;

  /* Signum: '<S285>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_ir = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S285>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S288>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S289>/Sum'
   */
  rtb_Optimized_Module_Angle = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S280>/Product' incorporates:
   *  Abs: '<S285>/Abs'
   *  Abs: '<S288>/Abs'
   *  Constant: '<S291>/Constant'
   *  Constant: '<S301>/Constant3'
   *  Constant: '<S301>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S285>/OR'
   *  Lookup_n-D: '<S288>/1-D Lookup Table'
   *  Math: '<S301>/Math Function'
   *  RelationalOperator: '<S285>/Equal1'
   *  RelationalOperator: '<S291>/Compare'
   *  Signum: '<S285>/Sign'
   *  Signum: '<S285>/Sign1'
   *  Sum: '<S288>/Add'
   *  Sum: '<S301>/Add1'
   *  Sum: '<S301>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_ir == rtb_Add_di) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.141592653589793) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Gain: '<S286>/Gain' */
  rtb_Hypot_g5 = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S286>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S293>/Sum1' incorporates:
   *  Constant: '<S286>/Constant2'
   *  Product: '<S293>/Product'
   *  Sum: '<S293>/Sum'
   *  UnitDelay: '<S293>/Unit Delay1'
   */
  rtb_Add_pw = ((rtb_MatrixConcatenate_b_idx_0 -
                 Robot_Control_DW.UnitDelay1_DSTATE_f) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S286>/Product' incorporates:
   *  Constant: '<S286>/Constant3'
   */
  rtb_Subtract1_bm = rtb_Add_pw * Drive_Motor_Control_D;

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
  rtb_Add_di = rtb_Subtract1_bm - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S286>/Saturation' */
  if (rtb_Add_di > Drive_Motor_Control_D_UL) {
    rtb_Add_di = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_di < Drive_Motor_Control_D_LL) {
    rtb_Add_di = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S286>/Add' incorporates:
   *  Gain: '<S286>/Gain1'
   *  Saturate: '<S286>/Saturation'
   */
  rtb_Add_di += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Hypot_g5;

  /* Saturate: '<S286>/Saturation2' */
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

  /* End of Saturate: '<S286>/Saturation2' */

  /* Sum: '<S302>/Add1' incorporates:
   *  Constant: '<S302>/Constant3'
   *  Constant: '<S302>/Constant4'
   *  Math: '<S302>/Math Function'
   *  Sum: '<S302>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S304>/Sum1' incorporates:
   *  Constant: '<S289>/Constant2'
   *  Product: '<S304>/Product'
   *  Sum: '<S304>/Sum'
   *  UnitDelay: '<S304>/Unit Delay1'
   */
  rtb_Hypot_g5 = ((rtb_MatrixConcatenate_b_idx_0 -
                   Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S289>/Product' incorporates:
   *  Constant: '<S289>/Constant3'
   */
  rtb_Product_i3 = rtb_Hypot_g5 * Steering_Motor_Control_D;

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
  rtb_Add_di = rtb_Product_i3 - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S289>/Saturation' */
  if (rtb_Add_di > Steering_Motor_Control_D_UL) {
    rtb_Add_di = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_di < Steering_Motor_Control_D_LL) {
    rtb_Add_di = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S289>/Add' incorporates:
   *  Gain: '<S289>/Gain1'
   *  Saturate: '<S289>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)
    + rtb_Add_di;

  /* Sum: '<S289>/Subtract' incorporates:
   *  Constant: '<S289>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S289>/Sum2' incorporates:
   *  Gain: '<S289>/Gain2'
   *  UnitDelay: '<S289>/Unit Delay'
   */
  rtb_Sum2_m = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S305>/Switch2' incorporates:
   *  Constant: '<S289>/Constant'
   *  RelationalOperator: '<S305>/LowerRelop1'
   *  Sum: '<S289>/Subtract'
   */
  if (!(rtb_Sum2_m > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S305>/Switch' incorporates:
     *  Constant: '<S289>/Constant1'
     *  RelationalOperator: '<S305>/UpperRelop'
     *  Sum: '<S289>/Subtract1'
     */
    if (rtb_Sum2_m < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_m;
    }

    /* End of Switch: '<S305>/Switch' */
  }

  /* End of Switch: '<S305>/Switch2' */

  /* Saturate: '<S289>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_m = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_m = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_m = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S289>/Saturation1' */

  /* Sum: '<S289>/Add1' */
  rtb_Add_di = rtb_Minus_k_idx_1 + rtb_Sum2_m;

  /* Saturate: '<S289>/Saturation2' */
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

  /* End of Saturate: '<S289>/Saturation2' */

  /* Product: '<S407>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch8;

  /* Switch: '<S417>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S417>/Switch' incorporates:
     *  Fcn: '<S418>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLoo_mu[1], rtb_TmpSignalConversionAtLoo_mu[0]);
  }

  /* End of Switch: '<S417>/Switch' */

  /* Trigonometry: '<S319>/Cos4' incorporates:
   *  Switch: '<S308>/Angle_Switch'
   *  Trigonometry: '<S318>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S319>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S317>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S319>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S319>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S317>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S319>/Subtract1' incorporates:
   *  Product: '<S319>/Product2'
   *  Product: '<S319>/Product3'
   *  Trigonometry: '<S319>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) +
    (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle);

  /* Sum: '<S319>/Subtract' incorporates:
   *  Product: '<S319>/Product'
   *  Product: '<S319>/Product1'
   *  Trigonometry: '<S319>/Cos4'
   */
  rtb_Subtract_iu = (rtb_Minus_k_idx_0 * rtb_Optimized_Module_Angle) -
    (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S319>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Subtract_iu, rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S319>/Switch' incorporates:
   *  Constant: '<S319>/Constant'
   *  Constant: '<S319>/Constant1'
   *  Constant: '<S320>/Constant'
   *  Product: '<S319>/Divide'
   *  Product: '<S319>/Divide1'
   *  RelationalOperator: '<S320>/Compare'
   *  Switch: '<S319>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Hypot_b;
    rtb_Optimized_Module_Angle = rtb_Subtract_iu / rtb_Hypot_b;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S319>/Switch' */

  /* Switch: '<S308>/Speed_Switch' incorporates:
   *  Abs: '<S308>/Abs'
   *  Constant: '<S316>/Constant'
   *  RelationalOperator: '<S316>/Compare'
   *  Switch: '<S308>/Angle_Switch'
   *  Trigonometry: '<S318>/Atan1'
   *  Trigonometry: '<S319>/Atan1'
   *  UnaryMinus: '<S308>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_ir = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S318>/Subtract1' incorporates:
     *  Product: '<S318>/Product2'
     *  Product: '<S318>/Product3'
     *  Trigonometry: '<S318>/Sin4'
     *  UnaryMinus: '<S308>/Unary Minus'
     */
    rtb_Subtract_iu = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Sin5_m) +
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S318>/Subtract' incorporates:
     *  Product: '<S318>/Product'
     *  Product: '<S318>/Product1'
     *  Trigonometry: '<S318>/Sin4'
     */
    rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S318>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Subtract_iu);

    /* Switch: '<S318>/Switch1' incorporates:
     *  Constant: '<S318>/Constant'
     *  Constant: '<S318>/Constant1'
     *  Constant: '<S321>/Constant'
     *  Product: '<S318>/Divide'
     *  Product: '<S318>/Divide1'
     *  RelationalOperator: '<S321>/Compare'
     *  Switch: '<S318>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_Minus_k_idx_0 /= rtb_Minus_k_idx_1;
      rtb_Minus_k_idx_1 = rtb_Subtract_iu / rtb_Minus_k_idx_1;
    } else {
      rtb_Minus_k_idx_0 = 1.0;
      rtb_Minus_k_idx_1 = 0.0;
    }

    /* End of Switch: '<S318>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_1, rtb_Minus_k_idx_0);
  } else {
    rtb_Add_ir = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S311>/Product2' incorporates:
   *  Constant: '<S311>/Constant'
   *  Switch: '<S308>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_ir * 1154.7574092481445;

  /* Signum: '<S306>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_ir = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S306>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S309>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S310>/Sum'
   */
  rtb_Optimized_Module_Angle = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S281>/Product' incorporates:
   *  Abs: '<S306>/Abs'
   *  Abs: '<S309>/Abs'
   *  Constant: '<S312>/Constant'
   *  Constant: '<S322>/Constant3'
   *  Constant: '<S322>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S306>/OR'
   *  Lookup_n-D: '<S309>/1-D Lookup Table'
   *  Math: '<S322>/Math Function'
   *  RelationalOperator: '<S306>/Equal1'
   *  RelationalOperator: '<S312>/Compare'
   *  Signum: '<S306>/Sign'
   *  Signum: '<S306>/Sign1'
   *  Sum: '<S309>/Add'
   *  Sum: '<S322>/Add1'
   *  Sum: '<S322>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_ir == rtb_Add_di) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.141592653589793) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Gain: '<S307>/Gain' */
  rtb_Subtract_iu = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S307>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S314>/Sum1' incorporates:
   *  Constant: '<S307>/Constant2'
   *  Product: '<S314>/Product'
   *  Sum: '<S314>/Sum'
   *  UnitDelay: '<S314>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_MatrixConcatenate_b_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_e) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S307>/Product' incorporates:
   *  Constant: '<S307>/Constant3'
   */
  rtb_Minus_k_idx_0 = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

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
  rtb_Add_di = rtb_Minus_k_idx_0 - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S307>/Saturation' */
  if (rtb_Add_di > Drive_Motor_Control_D_UL) {
    rtb_Add_di = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_di < Drive_Motor_Control_D_LL) {
    rtb_Add_di = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S307>/Add' incorporates:
   *  Gain: '<S307>/Gain1'
   *  Saturate: '<S307>/Saturation'
   */
  rtb_Add_di += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Subtract_iu;

  /* Saturate: '<S307>/Saturation2' */
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

  /* End of Saturate: '<S307>/Saturation2' */

  /* Sum: '<S323>/Add1' incorporates:
   *  Constant: '<S323>/Constant3'
   *  Constant: '<S323>/Constant4'
   *  Math: '<S323>/Math Function'
   *  Sum: '<S323>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S325>/Sum1' incorporates:
   *  Constant: '<S310>/Constant2'
   *  Product: '<S325>/Product'
   *  Sum: '<S325>/Sum'
   *  UnitDelay: '<S325>/Unit Delay1'
   */
  rtb_Subtract_iu = ((rtb_MatrixConcatenate_b_idx_0 -
                      Robot_Control_DW.UnitDelay1_DSTATE_n) *
                     Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S310>/Product' incorporates:
   *  Constant: '<S310>/Constant3'
   */
  rtb_Hypot_b = rtb_Subtract_iu * Steering_Motor_Control_D;

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
  rtb_Add_di = rtb_Hypot_b - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S310>/Saturation' */
  if (rtb_Add_di > Steering_Motor_Control_D_UL) {
    rtb_Add_di = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_di < Steering_Motor_Control_D_LL) {
    rtb_Add_di = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S310>/Add' incorporates:
   *  Gain: '<S310>/Gain1'
   *  Saturate: '<S310>/Saturation'
   */
  rtb_uDLookupTable = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)
    + rtb_Add_di;

  /* Sum: '<S310>/Subtract' incorporates:
   *  Constant: '<S310>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_uDLookupTable;

  /* Sum: '<S310>/Sum2' incorporates:
   *  Gain: '<S310>/Gain2'
   *  UnitDelay: '<S310>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S326>/Switch2' incorporates:
   *  Constant: '<S310>/Constant'
   *  RelationalOperator: '<S326>/LowerRelop1'
   *  Sum: '<S310>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_uDLookupTable))) {
    /* Switch: '<S326>/Switch' incorporates:
     *  Constant: '<S310>/Constant1'
     *  RelationalOperator: '<S326>/UpperRelop'
     *  Sum: '<S310>/Subtract1'
     */
    if (rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_uDLookupTable)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_uDLookupTable;
    } else {
      rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S326>/Switch' */
  }

  /* End of Switch: '<S326>/Switch2' */

  /* Saturate: '<S310>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S310>/Saturation1' */

  /* Sum: '<S310>/Add1' */
  rtb_Add_di = rtb_uDLookupTable + rtb_Subtract1_kg;

  /* Saturate: '<S310>/Saturation2' */
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

  /* End of Saturate: '<S310>/Saturation2' */

  /* Product: '<S407>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch8;

  /* Switch: '<S422>/Switch' */
  if (!rtb_Compare_bd) {
    /* Switch: '<S422>/Switch' incorporates:
     *  Fcn: '<S423>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S422>/Switch' */

  /* Trigonometry: '<S340>/Cos4' incorporates:
   *  Switch: '<S329>/Angle_Switch'
   *  Trigonometry: '<S339>/Cos4'
   */
  rtb_Subtract_j = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S340>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S338>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S340>/Sin4' */
  rtb_uDLookupTable = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S340>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S338>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S340>/Subtract1' incorporates:
   *  Product: '<S340>/Product2'
   *  Product: '<S340>/Product3'
   *  Trigonometry: '<S340>/Cos4'
   */
  rtb_Switch8 = (rtb_Subtract_j * rtb_Optimized_Module_Angle) +
    (rtb_uDLookupTable * rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S340>/Subtract' incorporates:
   *  Product: '<S340>/Product'
   *  Product: '<S340>/Product1'
   *  Trigonometry: '<S340>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Subtract_j *
    rtb_MatrixConcatenate_b_idx_0) - (rtb_uDLookupTable *
    rtb_Optimized_Module_Angle);

  /* Math: '<S340>/Hypot' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0,
    rtb_Switch8);

  /* Switch: '<S340>/Switch' incorporates:
   *  Constant: '<S340>/Constant'
   *  Constant: '<S340>/Constant1'
   *  Constant: '<S341>/Constant'
   *  Product: '<S340>/Divide'
   *  Product: '<S340>/Divide1'
   *  RelationalOperator: '<S341>/Compare'
   *  Switch: '<S340>/Switch1'
   */
  if (rtb_Optimized_Module_Angle > 1.0E-6) {
    rtb_Switch8 /= rtb_Optimized_Module_Angle;
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle;
  } else {
    rtb_Switch8 = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
  }

  /* End of Switch: '<S340>/Switch' */

  /* Switch: '<S329>/Speed_Switch' incorporates:
   *  Abs: '<S329>/Abs'
   *  Constant: '<S337>/Constant'
   *  RelationalOperator: '<S337>/Compare'
   *  Switch: '<S329>/Angle_Switch'
   *  Trigonometry: '<S339>/Atan1'
   *  Trigonometry: '<S340>/Atan1'
   *  UnaryMinus: '<S329>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch8, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    rtb_Add_ir = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S339>/Subtract1' incorporates:
     *  Product: '<S339>/Product2'
     *  Product: '<S339>/Product3'
     *  Trigonometry: '<S339>/Sin4'
     *  UnaryMinus: '<S329>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Subtract_j *
      Robot_Control_ConstB.Sin5_e) + (rtb_uDLookupTable *
      Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S339>/Subtract' incorporates:
     *  Product: '<S339>/Product'
     *  Product: '<S339>/Product1'
     *  Trigonometry: '<S339>/Sin4'
     */
    rtb_Subtract_j = (rtb_Subtract_j * Robot_Control_ConstB.Cos5_i) -
      (rtb_uDLookupTable * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S339>/Hypot' */
    rtb_uDLookupTable = rt_hypotd_snf(rtb_Subtract_j,
      rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S339>/Switch1' incorporates:
     *  Constant: '<S339>/Constant'
     *  Constant: '<S339>/Constant1'
     *  Constant: '<S342>/Constant'
     *  Product: '<S339>/Divide'
     *  Product: '<S339>/Divide1'
     *  RelationalOperator: '<S342>/Compare'
     *  Switch: '<S339>/Switch'
     */
    if (rtb_uDLookupTable > 1.0E-6) {
      rtb_Subtract_j /= rtb_uDLookupTable;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_uDLookupTable;
    } else {
      rtb_Subtract_j = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S339>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_Subtract_j);
  } else {
    rtb_Add_ir = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S332>/Product2' incorporates:
   *  Constant: '<S332>/Constant'
   *  Switch: '<S329>/Speed_Switch'
   */
  rtb_Switch8 = rtb_Add_ir * 1154.7574092481445;

  /* Signum: '<S327>/Sign' */
  if (rtIsNaN(rtb_Switch8)) {
    rtb_Add_ir = (rtNaN);
  } else if (rtb_Switch8 < 0.0) {
    rtb_Add_ir = -1.0;
  } else {
    rtb_Add_ir = (rtb_Switch8 > 0.0);
  }

  /* Signum: '<S327>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_di = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_di = -1.0;
  } else {
    rtb_Add_di = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S330>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S331>/Sum'
   */
  rtb_Optimized_Module_Angle -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S282>/Product' incorporates:
   *  Abs: '<S327>/Abs'
   *  Abs: '<S330>/Abs'
   *  Constant: '<S333>/Constant'
   *  Constant: '<S343>/Constant3'
   *  Constant: '<S343>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S327>/OR'
   *  Lookup_n-D: '<S330>/1-D Lookup Table'
   *  Math: '<S343>/Math Function'
   *  RelationalOperator: '<S327>/Equal1'
   *  RelationalOperator: '<S333>/Compare'
   *  Signum: '<S327>/Sign'
   *  Signum: '<S327>/Sign1'
   *  Sum: '<S330>/Add'
   *  Sum: '<S343>/Add1'
   *  Sum: '<S343>/Add2'
   */
  rtb_Switch8 = (((real_T)((rtb_Add_ir == rtb_Add_di) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch8) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle + 1.5707963267948966,
                      3.141592653589793) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Gain: '<S328>/Gain' */
  rtb_MatrixConcatenate_b_idx_0 = Drive_Motor_Control_FF * rtb_Switch8;

  /* Sum: '<S328>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch8 -= Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S335>/Sum1' incorporates:
   *  Constant: '<S328>/Constant2'
   *  Product: '<S335>/Product'
   *  Sum: '<S335>/Sum'
   *  UnitDelay: '<S335>/Unit Delay1'
   */
  rtb_uDLookupTable = ((rtb_Switch8 - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S328>/Product' incorporates:
   *  Constant: '<S328>/Constant3'
   */
  rtb_Subtract_j = rtb_uDLookupTable * Drive_Motor_Control_D;

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
  rtb_Add_di = rtb_Subtract_j - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S328>/Saturation' */
  if (rtb_Add_di > Drive_Motor_Control_D_UL) {
    rtb_Add_di = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_di < Drive_Motor_Control_D_LL) {
    rtb_Add_di = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S328>/Add' incorporates:
   *  Gain: '<S328>/Gain1'
   *  Saturate: '<S328>/Saturation'
   */
  rtb_Add_di += (Drive_Motor_Control_P * rtb_Switch8) +
    rtb_MatrixConcatenate_b_idx_0;

  /* Saturate: '<S328>/Saturation2' */
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

  /* End of Saturate: '<S328>/Saturation2' */

  /* Sum: '<S344>/Add1' incorporates:
   *  Constant: '<S344>/Constant3'
   *  Constant: '<S344>/Constant4'
   *  Math: '<S344>/Math Function'
   *  Sum: '<S344>/Add2'
   */
  rtb_Switch8 = rt_modd_snf(rtb_Optimized_Module_Angle + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Sum: '<S346>/Sum1' incorporates:
   *  Constant: '<S331>/Constant2'
   *  Product: '<S346>/Product'
   *  Sum: '<S346>/Sum'
   *  UnitDelay: '<S346>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch8 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S331>/Product' incorporates:
   *  Constant: '<S331>/Constant3'
   */
  rtb_Product_nq = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

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
  rtb_Add_di = rtb_Product_nq - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S331>/Saturation' */
  if (rtb_Add_di > Steering_Motor_Control_D_UL) {
    rtb_Add_di = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_di < Steering_Motor_Control_D_LL) {
    rtb_Add_di = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S331>/Add' incorporates:
   *  Gain: '<S331>/Gain1'
   *  Saturate: '<S331>/Saturation'
   */
  rtb_Add_f1 = (Steering_Motor_Control_P * rtb_Switch8) + rtb_Add_di;

  /* Sum: '<S331>/Subtract' incorporates:
   *  Constant: '<S331>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_f1;

  /* Sum: '<S331>/Sum2' incorporates:
   *  Gain: '<S331>/Gain2'
   *  UnitDelay: '<S331>/Unit Delay'
   */
  rtb_Switch8 = (Steering_Motor_Control_I * rtb_Switch8) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S347>/Switch2' incorporates:
   *  Constant: '<S331>/Constant'
   *  RelationalOperator: '<S347>/LowerRelop1'
   *  Sum: '<S331>/Subtract'
   */
  if (!(rtb_Switch8 > (1.0 - rtb_Add_f1))) {
    /* Sum: '<S331>/Subtract1' incorporates:
     *  Constant: '<S331>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_f1;

    /* Switch: '<S347>/Switch' incorporates:
     *  Constant: '<S331>/Constant1'
     *  RelationalOperator: '<S347>/UpperRelop'
     *  Sum: '<S331>/Subtract1'
     */
    if (!(rtb_Switch8 < (-1.0 - rtb_Add_f1))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch8;
    }

    /* End of Switch: '<S347>/Switch' */
  }

  /* End of Switch: '<S347>/Switch2' */

  /* Saturate: '<S331>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_g = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_g = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_g = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S331>/Saturation1' */

  /* Sum: '<S331>/Add1' */
  rtb_Add_di = rtb_Add_f1 + rtb_Integral_g;

  /* Saturate: '<S331>/Saturation2' */
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

  /* End of Saturate: '<S331>/Saturation2' */

  /* Sum: '<S215>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S217>/Sum1' incorporates:
   *  Constant: '<S215>/Constant2'
   *  Product: '<S217>/Product'
   *  Sum: '<S217>/Sum'
   *  UnitDelay: '<S217>/Unit Delay1'
   */
  rtb_Add_f1 = ((rtb_MatrixConcatenate_b_idx_0 -
                 Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S215>/Product' incorporates:
   *  Constant: '<S215>/Constant3'
   */
  rtb_Product_c2 = rtb_Add_f1 * 0.0;

  /* Sum: '<S216>/Diff' incorporates:
   *  UnitDelay: '<S216>/UD'
   *
   * Block description for '<S216>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S216>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_di = rtb_Product_c2 - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S215>/Saturation' */
  if (rtb_Add_di > 0.1) {
    rtb_Add_di = 0.1;
  } else if (rtb_Add_di < -0.1) {
    rtb_Add_di = -0.1;
  }

  /* Sum: '<S215>/Add' incorporates:
   *  Gain: '<S215>/Gain'
   *  Gain: '<S215>/Gain1'
   *  Saturate: '<S215>/Saturation'
   */
  rtb_Switch8 = ((Rebuilt_Transfer_Motor_Gain_FF *
                  Robot_Control_B.RB_Desired_Transfer_Speed) +
                 (Rebuilt_Transfer_Motor_Gain_P * rtb_MatrixConcatenate_b_idx_0))
    + rtb_Add_di;

  /* Logic: '<S154>/Logical Operator1' incorporates:
   *  Constant: '<S214>/Constant'
   *  RelationalOperator: '<S214>/Compare'
   */
  rtb_LogicalOperator2_e = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S154>/Switch1' incorporates:
   *  Abs: '<S154>/Abs'
   *  Constant: '<S154>/Constant1'
   *  Constant: '<S154>/Constant2'
   *  Logic: '<S154>/Logical Operator'
   *  RelationalOperator: '<S154>/LessThan'
   *  Sum: '<S154>/Subtract'
   *  UnitDelay: '<S154>/Unit Delay'
   */
  if ((fabs(rtb_MatrixConcatenate_b_idx_0) <
       Rebuilt_Transfer_Error_Integral_Enable) && rtb_LogicalOperator2_e) {
    rtb_Compare_bd = true;
  } else {
    rtb_Compare_bd = (rtb_LogicalOperator2_e &&
                      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S154>/Switch1' */

  /* Switch: '<S215>/Switch' incorporates:
   *  Constant: '<S215>/Constant4'
   */
  if (rtb_Compare_bd) {
    /* Sum: '<S215>/Sum2' incorporates:
     *  Gain: '<S215>/Gain2'
     *  UnitDelay: '<S215>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Transfer_Motor_Gain_I *
      rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S215>/Subtract' incorporates:
     *  Constant: '<S215>/Constant'
     */
    rtb_Integral_c3 = 1.0 - rtb_Switch8;

    /* Switch: '<S218>/Switch2' incorporates:
     *  Constant: '<S215>/Constant'
     *  RelationalOperator: '<S218>/LowerRelop1'
     *  Sum: '<S215>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Switch8))) {
      /* Sum: '<S215>/Subtract1' incorporates:
       *  Constant: '<S215>/Constant1'
       */
      rtb_Integral_c3 = -1.0 - rtb_Switch8;

      /* Switch: '<S218>/Switch' incorporates:
       *  Constant: '<S215>/Constant1'
       *  RelationalOperator: '<S218>/UpperRelop'
       *  Sum: '<S215>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Switch8))) {
        rtb_Integral_c3 = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S218>/Switch' */
    }

    /* End of Switch: '<S218>/Switch2' */

    /* Saturate: '<S215>/Saturation1' */
    if (rtb_Integral_c3 > 0.1) {
      rtb_Integral_c3 = 0.1;
    } else if (rtb_Integral_c3 < -0.1) {
      rtb_Integral_c3 = -0.1;
    }

    /* End of Saturate: '<S215>/Saturation1' */
  } else {
    rtb_Integral_c3 = 0.0;
  }

  /* End of Switch: '<S215>/Switch' */

  /* Switch: '<S154>/Switch2' */
  if (rtb_LogicalOperator2_e) {
    /* Sum: '<S215>/Add1' */
    rtb_Add_di = rtb_Switch8 + rtb_Integral_c3;

    /* Saturate: '<S215>/Saturation2' */
    if (rtb_Add_di > 1.0) {
      /* Switch: '<S154>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_di < -1.0) {
      /* Switch: '<S154>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S154>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_di;
    }

    /* End of Saturate: '<S215>/Saturation2' */
  } else {
    /* Switch: '<S154>/Switch2' incorporates:
     *  Constant: '<S154>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S154>/Switch2' */

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

  /* RelationalOperator: '<S149>/Compare' incorporates:
   *  Constant: '<S149>/Constant'
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

  /* Sum: '<S153>/Subtract' */
  rtb_Switch8 = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Logic: '<S153>/Logical Operator1' incorporates:
   *  Constant: '<S211>/Constant'
   *  RelationalOperator: '<S211>/Compare'
   */
  rtb_LogicalOperator2_e = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Switch: '<S153>/Switch1' incorporates:
   *  Constant: '<S153>/Constant1'
   *  Constant: '<S153>/Constant2'
   *  Logic: '<S153>/Logical Operator'
   *  RelationalOperator: '<S153>/LessThan'
   *  UnitDelay: '<S153>/Unit Delay'
   */
  if ((rtb_Switch8 < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator2_e) {
    rtb_LogicalOperator1 = true;
  } else {
    rtb_LogicalOperator1 = (rtb_LogicalOperator2_e &&
      (Robot_Control_DW.UnitDelay_DSTATE_kt));
  }

  /* End of Switch: '<S153>/Switch1' */

  /* Switch: '<S153>/Switch4' incorporates:
   *  Constant: '<S153>/Constant7'
   *  Constant: '<S153>/Constant8'
   *  Logic: '<S153>/Logical Operator3'
   *  RelationalOperator: '<S153>/LessThan2'
   *  UnitDelay: '<S153>/Unit Delay1'
   */
  if ((rtb_Switch8 < 0.0) && rtb_LogicalOperator2_e) {
    rtb_LogicalOperator5 = true;
  } else {
    rtb_LogicalOperator5 = (rtb_LogicalOperator2_e &&
      (Robot_Control_DW.UnitDelay1_DSTATE_oa));
  }

  /* End of Switch: '<S153>/Switch4' */

  /* Switch: '<S153>/Switch2' incorporates:
   *  Constant: '<S153>/Constant3'
   *  Constant: '<S153>/Constant9'
   *  Logic: '<S153>/Logical Operator4'
   *  Logic: '<S153>/Logical Operator5'
   */
  if (rtb_LogicalOperator1 && (!rtb_LogicalOperator5)) {
    rtb_Shooter_Motor_Gain_Ki = Rebuilt_Shooter_Motor_Gain_I;
  } else {
    rtb_Shooter_Motor_Gain_Ki = Rebuilt_Shooter_Motor_Gain_I_Low;
  }

  /* End of Switch: '<S153>/Switch2' */

  /* Outport: '<Root>/Shooter_Motor_Gain_Ki' */
  Robot_Control_Y.Shooter_Motor_Gain_Ki = rtb_Shooter_Motor_Gain_Ki;

  /* Outport: '<Root>/Shooter_Motor_Gain_Change' incorporates:
   *  Constant: '<S153>/Constant4'
   *  DataTypeConversion: '<S153>/Data Type Conversion'
   *  Logic: '<S153>/Logical Operator2'
   *  RelationalOperator: '<S212>/FixPt Relational Operator'
   *  RelationalOperator: '<S213>/FixPt Relational Operator'
   *  UnitDelay: '<S212>/Delay Input1'
   *  UnitDelay: '<S213>/Delay Input1'
   *
   * Block description for '<S212>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S213>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_Y.Shooter_Motor_Gain_Change = ((Rebuilt_Shooter_Motor_Gain_P !=
    Robot_Control_DW.DelayInput1_DSTATE_o) || (rtb_Shooter_Motor_Gain_Ki !=
    Robot_Control_DW.DelayInput1_DSTATE_j));

  /* Outport: '<Root>/Shooter_Motor_Gain_Kp' incorporates:
   *  Constant: '<S153>/Constant4'
   */
  Robot_Control_Y.Shooter_Motor_Gain_Kp = Rebuilt_Shooter_Motor_Gain_P;

  /* Switch: '<S10>/Switch5' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant6'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    rtb_Switch8 = TEST_Desired_Hood_Pos_OV;
  } else {
    rtb_Switch8 = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_Switch8 > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Switch8 = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Switch8 < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Switch8 = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Switch8;

  /* Switch: '<S142>/Init' incorporates:
   *  UnitDelay: '<S142>/FixPt Unit Delay1'
   *  UnitDelay: '<S142>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch8;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S142>/Init' */

  /* Sum: '<S140>/Sum1' */
  rtb_Switch8 -= rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S141>/Switch2' incorporates:
   *  Constant: '<S139>/Constant1'
   *  Constant: '<S139>/Constant3'
   *  RelationalOperator: '<S141>/LowerRelop1'
   *  RelationalOperator: '<S141>/UpperRelop'
   *  Switch: '<S141>/Switch'
   */
  if (rtb_Switch8 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch8 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch8 < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S139>/Constant1'
     */
    rtb_Switch8 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S141>/Switch2' */

  /* Sum: '<S140>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Switch8 +
    rtb_MatrixConcatenate_b_idx_0;

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
   *  RelationalOperator: '<S57>/FixPt Relational Operator'
   *  UnitDelay: '<S57>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Robot_Control_DW.is_active_c4_Robot_Control == 0) {
    Robot_Control_DW.is_active_c4_Robot_Control = 1U;
    Robot_Control_DW.is_c4_Robot_Control = Robot_Contro_IN_Wait_for_Button;
    Robot_Control_B.RB_Des_Intake_Arm_Angle =
      Robot_Control_B.RB_Intake_Arm_Angle_Mod;
    rtb_LogicalOperator2_e = false;
  } else {
    switch (Robot_Control_DW.is_c4_Robot_Control) {
     case Robot_Con_IN_Move_Intake_Arm_In:
      rtb_LogicalOperator2_e = true;
      if ((rtb_Intake_Arm_Move_Out || (rtb_Shooter_Active_prev &&
            (Robot_Control_B.RB_Intake_Arm_Angle_Mod <
             Rebuilt_Intake_Cycle_Angle_In))) || (((int32_T)
            rtb_Shooter_Active_prev) < ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_c))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      rtb_LogicalOperator2_e = true;
      if (rtb_Intake_Arm_Move_In || (rtb_Shooter_Active_prev &&
           (Robot_Control_B.RB_Intake_Arm_Angle_Mod >
            Rebuilt_Intake_Cycle_Angle_Out))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
      }
      break;

     default:
      /* case IN_Wait_for_Button: */
      rtb_LogicalOperator2_e = false;
      if (rtb_Intake_Arm_Move_In || rtb_Shooter_Active_prev) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Con_IN_Move_Intake_Arm_In;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_In;
        rtb_LogicalOperator2_e = true;
      } else if (rtb_Intake_Arm_Move_Out) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
        rtb_LogicalOperator2_e = true;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* Switch: '<S72>/Init' incorporates:
   *  UnitDelay: '<S72>/FixPt Unit Delay1'
   *  UnitDelay: '<S72>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Switch8 = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Switch8 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S72>/Init' */

  /* Sum: '<S70>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_Switch8;

  /* Switch: '<S71>/Switch2' incorporates:
   *  Constant: '<S59>/Constant1'
   *  Constant: '<S59>/Constant3'
   *  RelationalOperator: '<S71>/LowerRelop1'
   *  RelationalOperator: '<S71>/UpperRelop'
   *  Switch: '<S71>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Intake_RL_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S71>/Switch' incorporates:
     *  Constant: '<S59>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S71>/Switch2' */

  /* Sum: '<S70>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Switch8;

  /* Sum: '<S66>/Sum' */
  rtb_Switch8 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S68>/Sum1' incorporates:
   *  Constant: '<S66>/Constant2'
   *  Product: '<S68>/Product'
   *  Sum: '<S68>/Sum'
   *  UnitDelay: '<S68>/Unit Delay1'
   */
  rtb_Sum1_g = ((rtb_Switch8 - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S66>/Product' incorporates:
   *  Constant: '<S66>/Constant3'
   */
  rtb_Product_f2 = rtb_Sum1_g * Rebuilt_Intake_Arm_Gain_D;

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
  rtb_Add_di = rtb_Product_f2 - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S66>/Saturation' */
  if (rtb_Add_di > 0.1) {
    rtb_Add_di = 0.1;
  } else if (rtb_Add_di < -0.1) {
    rtb_Add_di = -0.1;
  }

  /* Sum: '<S66>/Add' incorporates:
   *  Gain: '<S66>/Gain'
   *  Gain: '<S66>/Gain1'
   *  Saturate: '<S66>/Saturation'
   */
  rtb_Add_ir = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
                (Rebuilt_Intake_Arm_Gain_P * rtb_Switch8)) + rtb_Add_di;

  /* Sum: '<S66>/Subtract' incorporates:
   *  Constant: '<S66>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_ir;

  /* Sum: '<S66>/Sum2' incorporates:
   *  Gain: '<S66>/Gain2'
   *  UnitDelay: '<S66>/Unit Delay'
   */
  rtb_Switch8 = (0.0 * rtb_Switch8) + Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S69>/Switch2' incorporates:
   *  Constant: '<S66>/Constant'
   *  RelationalOperator: '<S69>/LowerRelop1'
   *  Sum: '<S66>/Subtract'
   */
  if (!(rtb_Switch8 > (1.0 - rtb_Add_ir))) {
    /* Sum: '<S66>/Subtract1' incorporates:
     *  Constant: '<S66>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_ir;

    /* Switch: '<S69>/Switch' incorporates:
     *  Constant: '<S66>/Constant1'
     *  RelationalOperator: '<S69>/UpperRelop'
     *  Sum: '<S66>/Subtract1'
     */
    if (!(rtb_Switch8 < (-1.0 - rtb_Add_ir))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch8;
    }

    /* End of Switch: '<S69>/Switch' */
  }

  /* End of Switch: '<S69>/Switch2' */

  /* Saturate: '<S66>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > 0.1) {
    rtb_MatrixConcatenate_b_idx_0 = 0.1;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -0.1) {
    rtb_MatrixConcatenate_b_idx_0 = -0.1;
  }

  /* End of Saturate: '<S66>/Saturation1' */

  /* Switch: '<S58>/Switch2' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Logic: '<S58>/Logical Operator1'
   *  Logic: '<S58>/Logical Operator2'
   *  Logic: '<S58>/Logical Operator3'
   *  RelationalOperator: '<S62>/Compare'
   *  RelationalOperator: '<S63>/Compare'
   *  RelationalOperator: '<S64>/Compare'
   *  RelationalOperator: '<S65>/Compare'
   */
  if (((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_In) && (Robot_Control_B.RB_Intake_Arm_Angle_Mod
        <= Rebuilt_Intake_Meas_In_Disable)) ||
      ((Robot_Control_B.RB_Des_Intake_Arm_Angle_RL ==
        Rebuilt_Intake_Des_Angle_Out) &&
       (Robot_Control_B.RB_Intake_Arm_Angle_Mod >=
        Rebuilt_Intake_Meas_Out_Disable))) {
    /* Switch: '<S58>/Switch2' incorporates:
     *  Constant: '<S58>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  } else {
    /* Sum: '<S66>/Add1' */
    rtb_Add_di = rtb_Add_ir + rtb_MatrixConcatenate_b_idx_0;

    /* Saturate: '<S66>/Saturation2' */
    if (rtb_Add_di > 1.0) {
      /* Switch: '<S58>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_di < -1.0) {
      /* Switch: '<S58>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S58>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_di;
    }

    /* End of Saturate: '<S66>/Saturation2' */
  }

  /* End of Switch: '<S58>/Switch2' */

  /* Switch: '<S10>/Switch7' incorporates:
   *  Constant: '<S10>/Constant'
   *  Switch: '<S6>/Switch1'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Intake_Arm_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant9'
     */
    Robot_Control_Y.Intake_Arm_Motor_DC = TEST_Intake_Arm_Motor_DC_OV;
  } else if (rtb_LogicalOperator2_e) {
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

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S60>/Constant1'
   *  UnitDelay: '<S60>/Unit Delay'
   */
  if (rtb_Intake_Arm_Move_In) {
    rtb_Add_ir = 0.0;
  } else {
    rtb_Add_ir = Robot_Control_DW.UnitDelay_DSTATE_eo;
  }

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S60>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S73>/Constant'
   *  Logic: '<S6>/Logical Operator'
   *  Logic: '<S6>/Logical Operator1'
   *  RelationalOperator: '<S55>/Compare'
   *  RelationalOperator: '<S56>/Compare'
   *  RelationalOperator: '<S73>/Compare'
   *  Sum: '<S60>/Sum'
   *  Switch: '<S60>/Switch'
   */
  if (((((Robot_Control_B.RB_Des_Intake_Arm_Angle == Rebuilt_Intake_Des_Angle_In)
         && (Robot_Control_B.RB_Transfer_Motor_PID_DC != 0.0)) ||
        rtb_Shooter_Active_prev) || ((rtb_Add_ir + 0.02) <=
        Rebuilt_Roller_Intake_In_Delay)) || rtb_LogicalOperator1_ms) {
    rtb_Switch8 = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Switch8 = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S75>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   */
  rtb_Error_n = rtb_Switch8 - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S77>/Sum1' incorporates:
   *  Constant: '<S75>/Constant2'
   *  Product: '<S77>/Product'
   *  Sum: '<S77>/Sum'
   *  UnitDelay: '<S77>/Unit Delay1'
   */
  rtb_Sum1_ei = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S75>/Product' incorporates:
   *  Constant: '<S75>/Constant3'
   */
  rtb_Product_in = rtb_Sum1_ei * 0.0;

  /* Sum: '<S76>/Diff' incorporates:
   *  UnitDelay: '<S76>/UD'
   *
   * Block description for '<S76>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S76>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_di = rtb_Product_in - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S75>/Saturation' */
  if (rtb_Add_di > 0.1) {
    rtb_Add_di = 0.1;
  } else if (rtb_Add_di < -0.1) {
    rtb_Add_di = -0.1;
  }

  /* Sum: '<S75>/Add' incorporates:
   *  Gain: '<S75>/Gain'
   *  Gain: '<S75>/Gain1'
   *  Saturate: '<S75>/Saturation'
   */
  rtb_Add_di += (Rebuilt_Roller_Motor_Gain_FF * rtb_Switch8) +
    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n);

  /* Logic: '<S61>/Logical Operator1' incorporates:
   *  Constant: '<S74>/Constant'
   *  RelationalOperator: '<S74>/Compare'
   */
  rtb_LogicalOperator1_ms = !(rtb_Switch8 == 0.0);

  /* Switch: '<S61>/Switch1' incorporates:
   *  Abs: '<S61>/Abs'
   *  Constant: '<S61>/Constant1'
   *  Constant: '<S61>/Constant2'
   *  Logic: '<S61>/Logical Operator'
   *  RelationalOperator: '<S61>/LessThan'
   *  Sum: '<S61>/Subtract'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_ms) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_ms &&
      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S61>/Switch1' */

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S75>/Constant4'
   */
  if (rtb_Intake_Arm_Move_In) {
    /* Sum: '<S75>/Sum2' incorporates:
     *  Gain: '<S75>/Gain2'
     *  UnitDelay: '<S75>/Unit Delay'
     */
    rtb_Switch8 = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S75>/Subtract' incorporates:
     *  Constant: '<S75>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Add_di;

    /* Switch: '<S78>/Switch2' incorporates:
     *  Constant: '<S75>/Constant'
     *  RelationalOperator: '<S78>/LowerRelop1'
     *  Sum: '<S75>/Subtract'
     */
    if (!(rtb_Switch8 > (1.0 - rtb_Add_di))) {
      /* Sum: '<S75>/Subtract1' incorporates:
       *  Constant: '<S75>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Add_di;

      /* Switch: '<S78>/Switch' incorporates:
       *  Constant: '<S75>/Constant1'
       *  RelationalOperator: '<S78>/UpperRelop'
       *  Sum: '<S75>/Subtract1'
       */
      if (!(rtb_Switch8 < (-1.0 - rtb_Add_di))) {
        rtb_Error_n = rtb_Switch8;
      }

      /* End of Switch: '<S78>/Switch' */
    }

    /* End of Switch: '<S78>/Switch2' */

    /* Saturate: '<S75>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Switch8 = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Switch8 = -0.1;
    } else {
      rtb_Switch8 = rtb_Error_n;
    }

    /* End of Saturate: '<S75>/Saturation1' */
  } else {
    rtb_Switch8 = 0.0;
  }

  /* End of Switch: '<S75>/Switch' */

  /* Switch: '<S61>/Switch2' */
  if (rtb_LogicalOperator1_ms) {
    /* Sum: '<S75>/Add1' */
    rtb_Add_di += rtb_Switch8;

    /* Saturate: '<S75>/Saturation2' */
    if (rtb_Add_di > 1.0) {
      /* Switch: '<S61>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_di < -1.0) {
      /* Switch: '<S61>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S61>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_di;
    }

    /* End of Saturate: '<S75>/Saturation2' */
  } else {
    /* Switch: '<S61>/Switch2' incorporates:
     *  Constant: '<S61>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S61>/Switch2' */

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

  /* Update for UnitDelay: '<S38>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Gamepad_B3_X;

  /* Update for UnitDelay: '<S39>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *
   * Block description for '<S39>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Gamepad_B4_Y;

  /* Update for UnitDelay: '<S40>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *
   * Block description for '<S40>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Gamepad_B2_B;

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nl = rtb_Button_Spinup_Enable;

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
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_a = rtb_Switch1_py;

  /* Update for UnitDelay: '<S52>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S52>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S52>/FixPt Unit Delay1' */
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

  /* Update for Delay: '<S132>/Delay' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S131>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S79>/A'
   *  Delay: '<S132>/Delay'
   */
  rtb_Sum1 = Robot_Control_DW.Delay_DSTATE[0];
  rtb_Switch1_py = 0.0 * Robot_Control_DW.Delay_DSTATE[0];
  rtb_Add_di = Robot_Control_DW.Delay_DSTATE[1];

  /* Update for Delay: '<S132>/Delay' incorporates:
   *  Constant: '<S79>/A'
   *  Constant: '<S79>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S131>/A[k]*xhat[k|k-1]'
   *  Product: '<S131>/B[k]*u[k]'
   *  Product: '<S133>/Product3'
   *  Sum: '<S131>/Add'
   */
  Robot_Control_DW.Delay_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + ((0.0 * rtb_Add_di) + rtb_Sum1)) +
    Robot_Control_B.Product3[0];
  Robot_Control_DW.Delay_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + (rtb_Switch1_py + rtb_Add_di)) +
    Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S380>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S380>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S198>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_o = rtb_Merge1;

  /* Update for UnitDelay: '<S199>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Saturation_h;

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

  /* Update for UnitDelay: '<S403>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Switch_cn;

  /* Update for UnitDelay: '<S402>/UD'
   *
   * Block description for '<S402>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Subtract_c3;

  /* Update for UnitDelay: '<S400>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch2_n;

  /* Update for UnitDelay: '<S382>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Switch4_fu;

  /* Update for UnitDelay: '<S397>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S397>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S397>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Switch4_fu;

  /* Update for UnitDelay: '<S381>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Switch1_c;

  /* Update for UnitDelay: '<S390>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S390>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S390>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Switch1_c;

  /* Update for UnitDelay: '<S356>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch1_k;

  /* Update for UnitDelay: '<S355>/UD'
   *
   * Block description for '<S355>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_dy_n;

  /* Update for UnitDelay: '<S367>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S366>/UD'
   *
   * Block description for '<S366>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Product_d1;

  /* Update for UnitDelay: '<S352>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S293>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Add_pw;

  /* Update for UnitDelay: '<S292>/UD'
   *
   * Block description for '<S292>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Subtract1_bm;

  /* Update for UnitDelay: '<S304>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S303>/UD'
   *
   * Block description for '<S303>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Product_i3;

  /* Update for UnitDelay: '<S289>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_m;

  /* Update for UnitDelay: '<S314>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S313>/UD'
   *
   * Block description for '<S313>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S325>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Subtract_iu;

  /* Update for UnitDelay: '<S324>/UD'
   *
   * Block description for '<S324>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Hypot_b;

  /* Update for UnitDelay: '<S310>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S335>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S334>/UD'
   *
   * Block description for '<S334>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_Subtract_j;

  /* Update for UnitDelay: '<S346>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S345>/UD'
   *
   * Block description for '<S345>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_nq;

  /* Update for UnitDelay: '<S331>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_g;

  /* Update for UnitDelay: '<S217>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_f1;

  /* Update for UnitDelay: '<S216>/UD'
   *
   * Block description for '<S216>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_c2;

  /* Update for UnitDelay: '<S215>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_c3;

  /* Update for UnitDelay: '<S154>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Compare_bd;

  /* Update for UnitDelay: '<S153>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kt = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S153>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_oa = rtb_LogicalOperator5;

  /* Update for UnitDelay: '<S212>/Delay Input1'
   *
   * Block description for '<S212>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Shooter_Motor_Gain_Ki;

  /* Update for UnitDelay: '<S213>/Delay Input1' incorporates:
   *  Constant: '<S153>/Constant4'
   *
   * Block description for '<S213>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_o = Rebuilt_Shooter_Motor_Gain_P;

  /* Update for UnitDelay: '<S142>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S142>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S57>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Shooter_Active_prev;

  /* Update for UnitDelay: '<S72>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S72>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S68>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_g;

  /* Update for UnitDelay: '<S67>/UD'
   *
   * Block description for '<S67>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_f2;

  /* Update for UnitDelay: '<S66>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S60>/Unit Delay' incorporates:
   *  Constant: '<S60>/Constant'
   *  Sum: '<S60>/Sum'
   *  Switch: '<S60>/Switch'
   */
  Robot_Control_DW.UnitDelay_DSTATE_eo = rtb_Add_ir + 0.02;

  /* Update for UnitDelay: '<S77>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_ei;

  /* Update for UnitDelay: '<S76>/UD'
   *
   * Block description for '<S76>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_in;

  /* Update for UnitDelay: '<S75>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Switch8;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Intake_Arm_Move_In;
}

/* Model initialize function */
void Robot_Control_initialize(void)
{
  /* Start for SwitchCase: '<S1>/Switch Case' */
  Robot_Control_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S13>/If' */
  Robot_Control_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S146>/If' */
  Robot_Control_DW.If_ActiveSubsystem_n = -1;

  /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S49>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S52>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S132>/Delay' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S380>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S397>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S390>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S142>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S72>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S460>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S225>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S221>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S225>/Robot_Index_Is_Valid' */
  /* Start for If: '<S228>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S228>/Circle_Check_Valid' */
  /* Start for If: '<S230>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S228>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S225>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S146>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S192>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S146>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S146>/If Action Subsystem1' */
  /* InitializeConditions for UnitDelay: '<S193>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_b2 = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S146>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S146>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S194>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S146>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S146>/If Action Subsystem3' */
  /* InitializeConditions for UnitDelay: '<S195>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gt = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S146>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S146>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S196>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S146>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S146>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S197>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S146>/If Action Subsystem5' */
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
