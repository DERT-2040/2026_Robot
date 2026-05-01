/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.489
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri May  1 07:46:03 2026
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

/* Named constants for Chart: '<S378>/Add dither' */
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
                                        * Referenced by: '<S157>/Constant2'
                                        */
real_T Blue_Hub_LeftY = 3.354;         /* Variable: Blue_Hub_LeftY
                                        * Referenced by: '<S157>/Constant3'
                                        */
real_T Blue_Hub_RightX = 5.1717;       /* Variable: Blue_Hub_RightX
                                        * Referenced by: '<S157>/Constant4'
                                        */
real_T Blue_Hub_RightY = 4.548;        /* Variable: Blue_Hub_RightY
                                        * Referenced by: '<S157>/Constant5'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S452>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S448>/Constant'
                                        *   '<S448>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S452>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S448>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S281>/Constant3'
                                        *   '<S302>/Constant3'
                                        *   '<S323>/Constant3'
                                        *   '<S344>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S281>/Constant2'
                                   *   '<S302>/Constant2'
                                   *   '<S323>/Constant2'
                                   *   '<S344>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S281>/Saturation'
                                        *   '<S302>/Saturation'
                                        *   '<S323>/Saturation'
                                        *   '<S344>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S281>/Saturation'
                                        *   '<S302>/Saturation'
                                        *   '<S323>/Saturation'
                                        *   '<S344>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S281>/Gain'
                                            *   '<S302>/Gain'
                                            *   '<S323>/Gain'
                                            *   '<S344>/Gain'
                                            */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S281>/Gain1'
                                        *   '<S302>/Gain1'
                                        *   '<S323>/Gain1'
                                        *   '<S344>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S286>/Constant'
                            *   '<S307>/Constant'
                            *   '<S328>/Constant'
                            *   '<S349>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S202>/BlueAllianceZoneX'
                                         *   '<S204>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S158>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S158>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S158>/Constant1'
                                        *   '<S158>/Switch3'
                                        */
real_T Field_Length = 17.557;          /* Variable: Field_Length
                                        * Referenced by: '<S157>/Constant10'
                                        */
real_T Field_Length_Half = 8.7785;     /* Variable: Field_Length_Half
                                        * Referenced by:
                                        *   '<S175>/Switch'
                                        *   '<S176>/Switch'
                                        */
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S158>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S158>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S203>/RedAllianceZoneX'
                                         *   '<S205>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S158>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S158>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S438>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S438>/Constant5'
                                          */
real_T Field_Width_Pass = 7.0692;      /* Variable: Field_Width_Pass
                                        * Referenced by: '<S157>/Constant11'
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
                                       * Referenced by: '<S173>/Constant'
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
                                          *   '<S151>/Constant3'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S134>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S134>/Constant3'
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
                                       * Referenced by: '<S187>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S191>/Constant3'
                                   *   '<S192>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S181>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S182>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S183>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S184>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S188>/Unit Delay'
                                      *   '<S189>/Unit Delay'
                                      *   '<S190>/Unit Delay'
                                      *   '<S191>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S188>/Constant2'
                                      *   '<S189>/Constant2'
                                      *   '<S190>/Constant2'
                                      *   '<S191>/Constant2'
                                      *   '<S195>/Constant'
                                      *   '<S196>/Constant'
                                      *   '<S197>/Constant'
                                      *   '<S198>/Constant'
                                      */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S178>/Constant'
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
                                        * Referenced by: '<S159>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S159>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S159>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S159>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S159>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S159>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S159>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S159>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S154>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S154>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S154>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 3.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S154>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S154>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S154>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S154>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 10.0;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S154>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S155>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S155>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S155>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S155>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S155>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S155>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S155>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S155>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S146>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S146>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S146>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2725.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S168>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S168>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3265.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S168>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3425.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S168>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3625.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S168>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3775.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S168>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3975.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S168>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S168>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2825.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S167>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S167>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3365.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S167>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3525.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S167>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3725.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S167>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3875.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S167>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4075.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S167>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S167>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S161>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S161>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S161>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S161>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S161>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S161>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.4;      /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S161>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.5;      /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S161>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S165>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S148>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00015;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S12>/Constant1'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 0.03;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                            * Referenced by: '<S148>/Constant3'
                                            */
real_T Rebuilt_Shooter_Motor_Gain_I_Low = 0.0;
                                   /* Variable: Rebuilt_Shooter_Motor_Gain_I_Low
                                    * Referenced by: '<S148>/Constant9'
                                    */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.06;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                            * Referenced by: '<S148>/Constant4'
                                            */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S156>/Constant2'
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
                              * Referenced by: '<S149>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S210>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S210>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S210>/Gain1'
                                       */
real_T Red_Hub_LeftX = 11.369;         /* Variable: Red_Hub_LeftX
                                        * Referenced by: '<S157>/Constant6'
                                        */
real_T Red_Hub_LeftY = 4.548;          /* Variable: Red_Hub_LeftY
                                        * Referenced by: '<S157>/Constant7'
                                        */
real_T Red_Hub_RightX = 11.369;        /* Variable: Red_Hub_RightX
                                        * Referenced by: '<S157>/Constant8'
                                        */
real_T Red_Hub_RightY = 3.354;         /* Variable: Red_Hub_RightY
                                        * Referenced by: '<S157>/Constant9'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S437>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S435>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S437>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S438>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S438>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S270>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S270>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S217>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S230>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S270>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S377>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S377>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S377>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S377>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S377>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S377>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S395>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S395>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S395>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S395>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S394>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S395>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S395>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S395>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S395>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S395>/Constant1'
                                   *   '<S395>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S395>/Constant'
                                   *   '<S395>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S378>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S378>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S378>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S378>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S284>/Constant3'
                                        *   '<S305>/Constant3'
                                        *   '<S326>/Constant3'
                                        *   '<S347>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S284>/Constant2'
                                *   '<S305>/Constant2'
                                *   '<S326>/Constant2'
                                *   '<S347>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S284>/Saturation'
                                           *   '<S305>/Saturation'
                                           *   '<S326>/Saturation'
                                           *   '<S347>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S284>/Saturation'
                                          *   '<S305>/Saturation'
                                          *   '<S326>/Saturation'
                                          *   '<S347>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S284>/Gain2'
                                         *   '<S305>/Gain2'
                                         *   '<S326>/Gain2'
                                         *   '<S347>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S284>/Saturation1'
                                             *   '<S305>/Saturation1'
                                             *   '<S326>/Saturation1'
                                             *   '<S347>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S284>/Saturation1'
                                            *   '<S305>/Saturation1'
                                            *   '<S326>/Saturation1'
                                            *   '<S347>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S284>/Gain1'
                                        *   '<S305>/Gain1'
                                        *   '<S326>/Gain1'
                                        *   '<S347>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S376>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S376>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S376>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S376>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S376>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S376>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S437>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S437>/Constant1'
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
                                      * Referenced by: '<S436>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S436>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S436>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S364>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S364>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S364>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S364>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S364>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S364>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S438>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S437>/Dead Zone'
                                        *   '<S438>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S437>/Dead Zone'
                                        *   '<S438>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S435>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S435>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S435>/Constant4'
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
                                        * Referenced by: '<S435>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S435>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S435>/Constant5'
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
                                        *   '<S435>/Constant11'
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
 *    '<S141>/If Action Subsystem1'
 *    '<S141>/If Action Subsystem3'
 */
void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S188>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * System reset for action system:
 *    '<S141>/If Action Subsystem1'
 *    '<S141>/If Action Subsystem3'
 */
void Robot__IfActionSubsystem1_Reset(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S188>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * Output and update for action system:
 *    '<S141>/If Action Subsystem1'
 *    '<S141>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(real_T rtu_IsBlueInactiveFirst, real_T
  rtu_IsBlueAlliance, boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive,
  real_T *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  boolean_T rtb_Compare_cf;

  /* RelationalOperator: '<S195>/Compare' incorporates:
   *  Constant: '<S188>/Constant1'
   *  Constant: '<S195>/Constant'
   *  Sum: '<S188>/Sum'
   *  UnitDelay: '<S188>/Unit Delay'
   */
  rtb_Compare_cf = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S188>/Logical Operator' incorporates:
   *  Logic: '<S188>/NOT'
   */
  *rty_IsBlueActive = ((!(rtu_IsBlueInactiveFirst != 0.0)) || rtb_Compare_cf);

  /* Logic: '<S188>/Logical Operator1' */
  *rty_IsRedActive = ((rtu_IsBlueInactiveFirst != 0.0) || rtb_Compare_cf);

  /* Switch: '<S188>/Switch' incorporates:
   *  Constant: '<S188>/Constant1'
   *  Constant: '<S188>/Constant2'
   *  Logic: '<S188>/Logical Operator2'
   *  Sum: '<S188>/Subtract'
   *  Sum: '<S188>/Sum'
   *  UnitDelay: '<S188>/Unit Delay'
   */
  if ((boolean_T)((rtu_IsBlueInactiveFirst != 0.0) ^ (rtu_IsBlueAlliance != 0.0)))
  {
    *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;
  } else {
    *rty_Time_Remaining = (localDW->UnitDelay_DSTATE - 0.02) -
      Rebuilt_Match_Time_Shoot_Early;
  }

  /* End of Switch: '<S188>/Switch' */

  /* Update for UnitDelay: '<S188>/Unit Delay' incorporates:
   *  Constant: '<S188>/Constant1'
   *  Sum: '<S188>/Sum'
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
  real_T rtb_Switch1_k;
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
  int32_T s242_iter;
  uint16_T s267_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T Iteration_Number;
  uint8_T rtb_Desired_Pipeline;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4_j;
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
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_Reset_Wheel_Offsets;
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
    rtb_Init_o = Robot_Control_B.Drive_Joystick_X_preRL;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S47>/Init' */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Constant: '<S42>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Switch2_g = Rate_Limit_X;
  } else {
    rtb_Switch2_g = 1000.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Sum: '<S45>/Sum1' */
  rtb_Sum1 = Robot_Control_B.Drive_Joystick_X_preRL - rtb_Init_o;

  /* Switch: '<S46>/Switch2' incorporates:
   *  RelationalOperator: '<S46>/LowerRelop1'
   */
  if (!(rtb_Sum1 > rtb_Switch2_g)) {
    /* Switch: '<S42>/Switch1' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant3'
     *  UnaryMinus: '<S42>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_hb = -Rate_Limit_X;
    } else {
      rtb_Switch1_hb = -1000.0;
    }

    /* End of Switch: '<S42>/Switch1' */

    /* Switch: '<S46>/Switch' incorporates:
     *  RelationalOperator: '<S46>/UpperRelop'
     */
    if (rtb_Sum1 < rtb_Switch1_hb) {
      rtb_Switch2_g = rtb_Switch1_hb;
    } else {
      rtb_Switch2_g = rtb_Sum1;
    }

    /* End of Switch: '<S46>/Switch' */
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Sum: '<S45>/Sum' */
  rtb_Sum1 = rtb_Switch2_g + rtb_Init_o;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y_preRL = Robot_Control_U.Joystick_Left_Y;

  /* Switch: '<S50>/Init' incorporates:
   *  UnitDelay: '<S50>/FixPt Unit Delay1'
   *  UnitDelay: '<S50>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_j != 0) {
    rtb_Switch2_g = Robot_Control_B.Drive_Joystick_Y_preRL;
  } else {
    rtb_Switch2_g = Robot_Control_DW.FixPtUnitDelay1_DSTATE_a;
  }

  /* End of Switch: '<S50>/Init' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Y;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Sum: '<S48>/Sum1' */
  rtb_Switch1_hb = Robot_Control_B.Drive_Joystick_Y_preRL - rtb_Switch2_g;

  /* Switch: '<S49>/Switch2' incorporates:
   *  RelationalOperator: '<S49>/LowerRelop1'
   */
  if (!(rtb_Switch1_hb > rtb_Init_o)) {
    /* Switch: '<S43>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant3'
     *  UnaryMinus: '<S43>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_h = -Rate_Limit_Y;
    } else {
      rtb_Switch1_h = -1000.0;
    }

    /* End of Switch: '<S43>/Switch1' */

    /* Switch: '<S49>/Switch' incorporates:
     *  RelationalOperator: '<S49>/UpperRelop'
     */
    if (rtb_Switch1_hb < rtb_Switch1_h) {
      rtb_Init_o = rtb_Switch1_h;
    } else {
      rtb_Init_o = rtb_Switch1_hb;
    }

    /* End of Switch: '<S49>/Switch' */
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Sum: '<S48>/Sum' */
  rtb_Switch1_hb = rtb_Init_o + rtb_Switch2_g;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z_preRL = Robot_Control_U.Joystick_Left_Z;

  /* Switch: '<S53>/Init' incorporates:
   *  UnitDelay: '<S53>/FixPt Unit Delay1'
   *  UnitDelay: '<S53>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Switch2_g = Robot_Control_B.Drive_Joystick_Z_preRL;
  } else {
    rtb_Switch2_g = Robot_Control_DW.FixPtUnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S53>/Init' */

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Constant2'
   *  Constant: '<S44>/Constant3'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    rtb_Init_o = Rate_Limit_Z;
  } else {
    rtb_Init_o = 1000.0;
  }

  /* End of Switch: '<S44>/Switch' */

  /* Sum: '<S51>/Sum1' */
  rtb_Switch1_h = Robot_Control_B.Drive_Joystick_Z_preRL - rtb_Switch2_g;

  /* Switch: '<S52>/Switch2' incorporates:
   *  RelationalOperator: '<S52>/LowerRelop1'
   */
  if (!(rtb_Switch1_h > rtb_Init_o)) {
    /* Switch: '<S44>/Switch1' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant3'
     *  UnaryMinus: '<S44>/Unary Minus'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    if (Robot_Control_B.RB_Shooter_Active) {
      rtb_Switch1_m = -Rate_Limit_Z;
    } else {
      rtb_Switch1_m = -1000.0;
    }

    /* End of Switch: '<S44>/Switch1' */

    /* Switch: '<S52>/Switch' incorporates:
     *  RelationalOperator: '<S52>/UpperRelop'
     */
    if (rtb_Switch1_h < rtb_Switch1_m) {
      rtb_Init_o = rtb_Switch1_m;
    } else {
      rtb_Init_o = rtb_Switch1_h;
    }

    /* End of Switch: '<S52>/Switch' */
  }

  /* End of Switch: '<S52>/Switch2' */

  /* Sum: '<S51>/Sum' */
  rtb_Switch1_h = rtb_Init_o + rtb_Switch2_g;

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
  rtb_Switch2_g = rt_modd_snf(Robot_Control_U.Gyro_Angle_rad +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* RelationalOperator: '<S35>/GreaterThan' incorporates:
   *  Abs: '<S35>/Abs'
   *  Constant: '<S35>/Constant2'
   */
  rtb_Compare_ky = (fabs(rtb_Switch2_g) > 1.5707963267948966);

  /* Logic: '<S35>/Logical Operator1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   */
  rtb_LogicalOperator1 = ((Robot_Control_U.Joystick_Left_B2) && rtb_Compare_ky);

  /* Logic: '<S35>/Logical Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B3'
   *  Inport: '<Root>/Joystick_Left_B4'
   */
  rtb_Compare_mq = ((Robot_Control_U.Joystick_Left_B3) ||
                    (Robot_Control_U.Joystick_Left_B4));

  /* RelationalOperator: '<S35>/GreaterThan1' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  rtb_Compare_pb = (rtb_Switch2_g > 0.0);

  /* Logic: '<S35>/Logical Operator5' incorporates:
   *  Logic: '<S35>/Logical Operator6'
   */
  rtb_LogicalOperator5 = (rtb_Compare_mq && (!rtb_Compare_pb));

  /* Logic: '<S35>/Logical Operator3' */
  rtb_LogicalOperator3 = (rtb_Compare_mq && rtb_Compare_pb);

  /* Logic: '<S35>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Joystick_Left_B2'
   *  Logic: '<S35>/Logical Operator4'
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

  /* If: '<S464>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S464>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S467>/Action Port'
     */
    /* Product: '<S467>/Product' incorporates:
     *  Constant: '<S467>/Constant1'
     *  Constant: '<S467>/Constant2'
     *  Math: '<S467>/Math Function'
     */
    rtb_Switch2_g = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S464>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S464>/Subsystem' incorporates:
     *  ActionPort: '<S468>/Action Port'
     */
    /* SignalConversion generated from: '<S468>/Out1' incorporates:
     *  Constant: '<S468>/Constant'
     */
    rtb_Switch2_g = 0.0;

    /* End of Outputs for SubSystem: '<S464>/Subsystem' */
  }

  /* End of If: '<S464>/If' */

  /* Gain: '<S465>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Init_o = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S466>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Switch2_g * cos(rtb_Init_o))
    + Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S466>/theta->y'
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
    rtb_Compare_ky = false;

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
      Robot_Control_DW.is_active_c5_Robot_Control = 0U;
      Robot_Control_DW.is_c5_Robot_Control = Robot_Contro_IN_NO_ACTIVE_CHILD;
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
      rtb_Switch2_dh = 0.0;
    } else {
      rtb_Switch2_dh = Robot_Control_DW.UnitDelay2_DSTATE_d + 0.02;
    }

    /* End of Switch: '<S19>/Switch2' */

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     *  UnitDelay: '<S19>/Unit Delay1'
     */
    rtb_LogicalOperator3 = (Robot_Control_DW.UnitDelay1_DSTATE_k == 5.0);

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
    if (((int32_T)rtb_LogicalOperator3) > ((int32_T)
         Robot_Control_DW.DelayInput1_DSTATE_or)) {
      rtb_Init_o = 0.0;
    } else {
      rtb_Init_o = Robot_Control_DW.UnitDelay3_DSTATE_i + 0.02;
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
      rtb_Shooter_Active_prev = (rtb_Switch1_n >= Auto_Shoot_Time);
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S19>/Switch3' incorporates:
       *  Constant: '<S26>/Constant'
       *  RelationalOperator: '<S26>/Compare'
       *  Switch: '<S19>/Switch6'
       */
      rtb_Shooter_Active_prev = (rtb_Switch2_dh >= Auto_Deploy_Intake_Time);
    } else if (rtb_LogicalOperator3) {
      /* Switch: '<S19>/Switch5' incorporates:
       *  Constant: '<S28>/Constant'
       *  RelationalOperator: '<S28>/Compare'
       *  Switch: '<S19>/Switch6'
       */
      rtb_Shooter_Active_prev = (rtb_Init_o >= Auto_Deploy_Intake_Time2);
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
    if (Robot_Control_DW.is_active_c5_Robot_Control == 0U) {
      Robot_Control_DW.is_active_c5_Robot_Control = 1U;
      Robot_Control_B.Auto_Path_Counter = 1.0;
      Robot_Control_DW.is_c5_Robot_Control = Robot_Control_IN_Start_Action;
      Robot_Control_B.Auto_Spline_Enable = false;
      Robot_Control_B.Auto_Desired_Static_Action =
        Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) + 39];
      Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
      Robot_Control_DW.counter = 0.0;
    } else {
      switch (Robot_Control_DW.is_c5_Robot_Control) {
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
          Robot_Control_DW.is_c5_Robot_Control = Robot_Control_IN_Start_Action;
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
          Robot_Control_DW.is_c5_Robot_Control = Robot_Control_IN_End_Action;
          Robot_Control_B.Auto_Spline_Enable = false;
          Robot_Control_B.Auto_Desired_Static_Action =
            Robot_Control_DW.UnitDelay1_DSTATE_iz[((int32_T)rtb_Saturation_h) +
            39];
          Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
        } else if (rtb_Saturation_h > Robot_Control_DW.UnitDelay_DSTATE_e3) {
          Robot_Control_DW.is_c5_Robot_Control = Robot_Control_IN_Follow_Path;
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
          Robot_Control_DW.is_c5_Robot_Control = Robot_Control_IN_Follow_Path;
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
      (Robot_Control_B.Auto_Path_ID, 1.0, 1.0, 24U)];

    /* Merge: '<S9>/Merge7' incorporates:
     *  SignalConversion: '<S18>/Signal Copy'
     */
    Robot_Control_B.Spline_Enable = Robot_Control_B.Auto_Spline_Enable;

    /* Switch: '<S22>/Switch' */
    if (Robot_Control_B.Auto_Desired_Static_Action != 0.0) {
      rtb_Switch2_g = Robot_Control_B.Auto_Desired_Static_Action;
    } else {
      rtb_Switch2_g = Robot_Control_B.Auto_Desired_Dynamic_Action;
    }

    /* End of Switch: '<S22>/Switch' */

    /* MultiPortSwitch: '<S22>/Multiport Switch4' incorporates:
     *  Constant: '<S22>/Constant20'
     *  Constant: '<S22>/Constant21'
     *  Constant: '<S22>/Constant22'
     *  Constant: '<S22>/Constant23'
     *  Constant: '<S22>/Constant24'
     */
    switch ((int32_T)rtb_Switch2_g) {
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
    rtb_Intake_Arm_Cycle = ((rtb_Switch1_k >= Auto_Intake_Arm_Cycle_Delay_Time) &&
      rtb_LogicalOperator2);

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant18'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     */
    switch ((int32_T)rtb_Switch2_g) {
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
      rtb_Compare_ky = false;

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
      rtb_Compare_ky = true;

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
      rtb_Compare_ky = false;

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
      rtb_Compare_ky = false;

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
      rtb_Compare_ky = false;

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

    /* Update for UnitDelay: '<S29>/Delay Input1'
     *
     * Block description for '<S29>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_kb = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Switch1_n;

    /* Update for UnitDelay: '<S30>/Delay Input1'
     *
     * Block description for '<S30>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_h = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S19>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_d = rtb_Switch2_dh;

    /* Update for UnitDelay: '<S31>/Delay Input1'
     *
     * Block description for '<S31>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_or = rtb_LogicalOperator3;

    /* Update for UnitDelay: '<S19>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE_i = rtb_Init_o;

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
       *  UnitDelay: '<S437>/Unit Delay1'
       *  UnitDelay: '<S437>/Unit Delay2'
       *  UnitDelay: '<S437>/Unit Delay3'
       *  UnitDelay: '<S437>/Unit Delay4'
       *  UnitDelay: '<S440>/Delay Input1'
       *  UnitDelay: '<S441>/Delay Input1'
       *  UnitDelay: '<S442>/Delay Input1'
       *  UnitDelay: '<S443>/Delay Input1'
       *  UnitDelay: '<S445>/Delay Input1'
       *  UnitDelay: '<S451>/Unit Delay'
       *  UnitDelay: '<S451>/Unit Delay1'
       *  UnitDelay: '<S455>/FixPt Unit Delay1'
       *  UnitDelay: '<S455>/FixPt Unit Delay2'
       *
       * Block description for '<S440>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S441>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S442>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S443>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S445>/Delay Input1':
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

    /* Switch: '<S435>/Switch4' incorporates:
     *  Constant: '<S460>/Constant'
     *  Constant: '<S463>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S460>/Compare'
     *  RelationalOperator: '<S463>/Compare'
     *  Switch: '<S435>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S435>/Switch4' incorporates:
       *  Constant: '<S435>/Constant8'
       *  Sum: '<S435>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S435>/Switch5' incorporates:
       *  Constant: '<S435>/Constant7'
       *  Gain: '<S435>/Gain'
       *  Sum: '<S435>/Subtract5'
       *  Switch: '<S435>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S435>/Switch4' incorporates:
       *  Constant: '<S435>/Constant6'
       *  Switch: '<S435>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S435>/Switch4' */

    /* Logic: '<S435>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S435>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S437>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Minus_f = 0.0;
    } else {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S437>/Add' incorporates:
     *  Constant: '<S437>/Constant'
     *  Constant: '<S437>/Constant1'
     *  DeadZone: '<S437>/Dead Zone'
     *  Lookup_n-D: '<S437>/Modulation_Str_Y_Rel'
     *  Product: '<S437>/Product'
     *  Product: '<S437>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Minus_f *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S439>/Compare' incorporates:
     *  Constant: '<S439>/Constant'
     */
    rtb_Compare_lk = (rtb_Switch1_m == 0.0);

    /* Logic: '<S437>/AND2' incorporates:
     *  RelationalOperator: '<S440>/FixPt Relational Operator'
     *  RelationalOperator: '<S441>/FixPt Relational Operator'
     *  RelationalOperator: '<S442>/FixPt Relational Operator'
     *  RelationalOperator: '<S443>/FixPt Relational Operator'
     *  UnitDelay: '<S440>/Delay Input1'
     *  UnitDelay: '<S441>/Delay Input1'
     *  UnitDelay: '<S442>/Delay Input1'
     *  UnitDelay: '<S443>/Delay Input1'
     *
     * Block description for '<S440>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S441>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S442>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S443>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Intake_Arm_Cycle = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_LogicalOperator3)
      > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S437>/AND1' incorporates:
     *  Logic: '<S437>/AND3'
     *  UnitDelay: '<S437>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_lk && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S437>/AND4' incorporates:
     *  Logic: '<S437>/AND8'
     *  UnitDelay: '<S437>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_lk && (!rtb_Intake_Arm_Cycle)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S437>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* Switch: '<S437>/Switch8' incorporates:
     *  Constant: '<S446>/Constant'
     *  Logic: '<S437>/AND9'
     *  RelationalOperator: '<S445>/FixPt Relational Operator'
     *  RelationalOperator: '<S446>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S445>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S445>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_lk) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_jp)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_DW.UnitDelay1_DSTATE_nl)) {
      /* Switch: '<S437>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S437>/Switch8' incorporates:
       *  UnitDelay: '<S437>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S437>/Switch8' */

    /* Switch: '<S437>/Switch4' incorporates:
     *  Constant: '<S437>/Constant5'
     *  Switch: '<S437>/Switch1'
     *  Switch: '<S437>/Switch5'
     *  Switch: '<S437>/Switch6'
     *  Switch: '<S437>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Saturation_h = 0.0;
    } else if (rtb_LogicalOperator3) {
      /* Switch: '<S437>/Switch5' incorporates:
       *  Constant: '<S437>/Constant6'
       */
      rtb_Saturation_h = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S437>/Switch6' incorporates:
       *  Constant: '<S437>/Constant7'
       *  Switch: '<S437>/Switch5'
       */
      rtb_Saturation_h = 3.1415926535897931;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S437>/Switch7' incorporates:
       *  Constant: '<S437>/Constant8'
       *  Switch: '<S437>/Switch5'
       *  Switch: '<S437>/Switch6'
       */
      rtb_Saturation_h = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S437>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S437>/Switch5'
       *  Switch: '<S437>/Switch6'
       *  Switch: '<S437>/Switch7'
       */
      rtb_Saturation_h = 0.0;
    } else {
      /* Switch: '<S437>/Switch6' incorporates:
       *  Switch: '<S437>/Switch5'
       *  Switch: '<S437>/Switch7'
       *  UnitDelay: '<S437>/Unit Delay1'
       */
      rtb_Saturation_h = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S437>/Switch4' */

    /* Switch: '<S437>/Switch2' incorporates:
     *  Switch: '<S437>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S437>/Switch2' incorporates:
       *  Constant: '<S437>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S437>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Saturation_h;
    } else {
      /* Switch: '<S437>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S437>/Switch3' incorporates:
       *  Constant: '<S437>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S437>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S437>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S436>/Switch1' incorporates:
     *  Constant: '<S436>/Constant5'
     *  Constant: '<S436>/Constant8'
     *  DataTypeConversion: '<S436>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_mq = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Compare_mq = rtb_Compare_lk;
    }

    /* End of Switch: '<S436>/Switch1' */

    /* Lookup_n-D: '<S438>/Modulation_Drv' incorporates:
     *  Math: '<S438>/Magnitude'
     */
    rtb_Init_o = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S449>/Compare' incorporates:
     *  Constant: '<S449>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Init_o == 0.0);

    /* DeadZone: '<S438>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_Switch2_g = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_Switch2_g = 0.0;
    } else {
      rtb_Switch2_g = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S438>/Dead Zone' */

    /* Logic: '<S438>/Logical Operator' incorporates:
     *  Constant: '<S450>/Constant'
     *  RelationalOperator: '<S450>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Switch2_g != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S436>/Switch' incorporates:
     *  Constant: '<S436>/Constant5'
     *  Constant: '<S436>/Constant7'
     *  DataTypeConversion: '<S436>/Data Type Conversion'
     *  Logic: '<S438>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_pb = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Compare_pb = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S436>/Switch' */

    /* Switch: '<S435>/Switch2' incorporates:
     *  Constant: '<S435>/Constant2'
     *  Constant: '<S459>/Constant'
     *  Constant: '<S462>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S459>/Compare'
     *  RelationalOperator: '<S462>/Compare'
     *  Sum: '<S435>/Subtract'
     *  Switch: '<S435>/Switch'
     *  Switch: '<S435>/Switch1'
     *  Switch: '<S435>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S435>/Switch2' incorporates:
       *  Constant: '<S435>/Constant5'
       *  Sum: '<S435>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_i = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S435>/Switch2' incorporates:
       *  Constant: '<S435>/Constant4'
       *  Sum: '<S435>/Subtract2'
       *  Switch: '<S435>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S435>/Switch1' incorporates:
       *  Constant: '<S435>/Constant1'
       *  Sum: '<S435>/Subtract3'
       */
      rtb_Switch2_i = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S435>/Switch2' incorporates:
       *  Constant: '<S435>/Constant3'
       *  Switch: '<S435>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S435>/Switch1' incorporates:
       *  Constant: '<S435>/Constant'
       */
      rtb_Switch2_i = 0.0;
    }

    /* End of Switch: '<S435>/Switch2' */

    /* UnaryMinus: '<S435>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_i;

    /* Switch: '<S451>/Switch1' incorporates:
     *  Constant: '<S456>/Constant'
     *  Constant: '<S457>/Constant'
     *  Logic: '<S451>/AND'
     *  RelationalOperator: '<S456>/Compare'
     *  RelationalOperator: '<S457>/Compare'
     *  Switch: '<S451>/Switch2'
     *  UnitDelay: '<S451>/Unit Delay'
     *  UnitDelay: '<S451>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_dh = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1_n = rtb_Switch1_hb;
      rtb_Switch2_dh = rtb_Sum1;
    }

    /* End of Switch: '<S451>/Switch1' */

    /* Switch: '<S438>/Switch1' incorporates:
     *  Logic: '<S438>/Logical Operator1'
     *  Switch: '<S438>/Switch4'
     *  Switch: '<S438>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S438>/Sign' */
      if (rtIsNaN(rtb_Switch2_g)) {
        rtb_Minus_f = (rtNaN);
      } else if (rtb_Switch2_g < 0.0) {
        rtb_Minus_f = -1.0;
      } else {
        rtb_Minus_f = (rtb_Switch2_g > 0.0);
      }

      /* Switch: '<S438>/Switch5' incorporates:
       *  Constant: '<S438>/Constant3'
       *  Constant: '<S438>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S438>/Gain3'
       *  Signum: '<S438>/Sign'
       *  Sum: '<S438>/Add'
       *  Switch: '<S438>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Minus_f) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S438>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S438>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S438>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S438>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S438>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S438>/Switch4'
       *  Trigonometry: '<S438>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1_n,
        rtb_Switch2_dh);
    }

    /* End of Switch: '<S438>/Switch1' */

    /* Switch: '<S448>/Switch1' incorporates:
     *  Constant: '<S448>/Constant'
     *  Constant: '<S448>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_i = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_i = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S448>/Switch1' */

    /* Switch: '<S455>/Init' incorporates:
     *  UnitDelay: '<S455>/FixPt Unit Delay1'
     *  UnitDelay: '<S455>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Switch1_k = rtb_Switch2_i;
    } else {
      rtb_Switch1_k = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S455>/Init' */

    /* Sum: '<S453>/Sum1' */
    rtb_Switch2_i -= rtb_Switch1_k;

    /* Switch: '<S454>/Switch2' incorporates:
     *  Constant: '<S452>/Constant1'
     *  Constant: '<S452>/Constant3'
     *  RelationalOperator: '<S454>/LowerRelop1'
     *  RelationalOperator: '<S454>/UpperRelop'
     *  Switch: '<S454>/Switch'
     */
    if (rtb_Switch2_i > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_i = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_i < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S454>/Switch' incorporates:
       *  Constant: '<S452>/Constant1'
       */
      rtb_Switch2_i = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S454>/Switch2' */

    /* Sum: '<S453>/Sum' */
    rtb_Switch1_k += rtb_Switch2_i;

    /* Switch: '<S438>/Switch8' incorporates:
     *  Logic: '<S438>/Logical Operator1'
     *  Switch: '<S438>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S438>/Switch' incorporates:
       *  Gain: '<S438>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Switch2_g;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S438>/Constant5'
       *  Gain: '<S438>/Gain2'
       *  Math: '<S438>/Magnitude1'
       *  MinMax: '<S438>/Min'
       *  Switch: '<S438>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S448>/Product' incorporates:
       *  Switch: '<S438>/Switch2'
       */
      rtb_Add_mw = rtb_Init_o * rtb_Switch1_k;

      /* Saturate: '<S448>/Saturation' incorporates:
       *  Switch: '<S438>/Switch2'
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

      /* End of Saturate: '<S448>/Saturation' */
    }

    /* End of Switch: '<S438>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S437>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Switch: '<S435>/Switch6' incorporates:
     *  Constant: '<S435>/Constant11'
     *  Switch: '<S435>/Switch7'
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

    /* RelationalOperator: '<S431>/Compare' incorporates:
     *  Constant: '<S431>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S432>/Compare' incorporates:
     *  Constant: '<S432>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Compare_ky = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S427>/Compare' incorporates:
     *  Constant: '<S427>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S430>/Compare' incorporates:
     *  Constant: '<S430>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S429>/Compare' incorporates:
     *  Constant: '<S429>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Constant: '<S428>/Constant'
     *  Constant: '<S433>/Constant'
     *  Inport: '<Root>/Gamepad_LT'
     *  Inport: '<Root>/Joystick_Right_B1'
     *  RelationalOperator: '<S428>/Compare'
     *  RelationalOperator: '<S433>/Compare'
     */
    rtb_LogicalOperator1_ms = ((Robot_Control_U.Joystick_Right_B1 != 0.0) ||
      (Robot_Control_U.Gamepad_LT != 0.0));

    /* SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     */
    rtb_Switch1_m = 0.0;

    /* Update for UnitDelay: '<S445>/Delay Input1'
     *
     * Block description for '<S445>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_jp = rtb_Compare_lk;

    /* Update for UnitDelay: '<S444>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S444>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S440>/Delay Input1'
     *
     * Block description for '<S440>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S441>/Delay Input1'
     *
     * Block description for '<S441>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_LogicalOperator3;

    /* Update for UnitDelay: '<S442>/Delay Input1'
     *
     * Block description for '<S442>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S443>/Delay Input1'
     *
     * Block description for '<S443>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S437>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S437>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S437>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S437>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S451>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1_n;

    /* Update for UnitDelay: '<S451>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2_dh;

    /* Update for UnitDelay: '<S455>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S455>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S455>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Switch1_k;

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
    rtb_Compare_ky = false;

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

  /* Reshape: '<S80>/Reshapey' incorporates:
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

  /* Delay: '<S80>/MemoryX' incorporates:
   *  Constant: '<S80>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S107>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S133>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S100>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S131>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S131>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S80>/C'
     *  Delay: '<S80>/MemoryX'
     *  Product: '<S133>/Product'
     */
    rtb_Switch1_n = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Switch1_n;

    /* Sum: '<S131>/Sum' incorporates:
     *  Constant: '<S80>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S131>/C[k]*xhat[k|k-1]'
     *  Product: '<S131>/D[k]*u[k]'
     *  Sum: '<S131>/Add1'
     */
    rtb_Init_o = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Switch2_dh = rtb_Reshapey[0] - (rtb_Init_o + rtb_Switch1_n);

    /* Product: '<S131>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S80>/C'
     *  Delay: '<S80>/MemoryX'
     *  Product: '<S133>/Product'
     */
    rtb_Switch1_n = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Switch1_n;

    /* Sum: '<S131>/Sum' incorporates:
     *  Constant: '<S80>/D'
     *  Product: '<S131>/C[k]*xhat[k|k-1]'
     *  Product: '<S131>/D[k]*u[k]'
     *  Sum: '<S131>/Add1'
     */
    rtb_Switch1_n = rtb_Reshapey[1] - (rtb_Init_o + rtb_Switch1_n);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S131>/Product3' incorporates:
     *  Constant: '<S81>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Switch2_dh) +
      (-2.0601714451538746E-17 * rtb_Switch1_n);

    /* Sum: '<S133>/Add1' incorporates:
     *  Product: '<S133>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S131>/Product3' incorporates:
     *  Constant: '<S81>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Switch2_dh) +
      (0.095124921972504 * rtb_Switch1_n);

    /* Sum: '<S133>/Add1' incorporates:
     *  Product: '<S133>/Product'
     */
    rtb_Switch1_n = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S133>/Product2' incorporates:
     *  Constant: '<S81>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Switch1_n);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Switch1_n);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S131>/Product3' incorporates:
       *  Outport: '<S131>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S133>/Product2' incorporates:
       *  Outport: '<S133>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S100>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S107>/Enabled Subsystem' */

  /* Sum: '<S107>/Add' incorporates:
   *  Delay: '<S80>/MemoryX'
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
   *  Constant: '<S267>/Constant'
   *  Logic: '<S267>/AND'
   *  MATLAB Function: '<S217>/Find closest index to curve'
   *  Product: '<S267>/Product'
   *  RelationalOperator: '<S267>/Relational Operator'
   *  RelationalOperator: '<S267>/Relational Operator1'
   *  Selector: '<S267>/Selector'
   *  Selector: '<S267>/Selector1'
   *  Selector: '<S268>/Selector'
   *  Sum: '<S267>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S220>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S223>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S225>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S220>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S215>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S215>/Unit Delay'
       *  UnitDelay: '<S216>/Unit Delay'
       *  UnitDelay: '<S218>/Unit Delay'
       *  UnitDelay: '<S218>/Unit Delay1'
       *  UnitDelay: '<S268>/Unit Delay'
       *  UnitDelay: '<S268>/Unit Delay1'
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
     *  ActionPort: '<S215>/Action Port'
     */
    /* Selector: '<S216>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S216>/Selector1' */

    /* Lookup_n-D: '<S215>/Capture Radius' incorporates:
     *  UnitDelay: '<S215>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S216>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S216>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S220>/If' incorporates:
     *  RelationalOperator: '<S220>/ '
     *  UnitDelay: '<S216>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S223>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S225>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S220>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S223>/Action Port'
       */
      /* InitializeConditions for If: '<S220>/If' incorporates:
       *  UnitDelay: '<S223>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S220>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S220>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S223>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S223>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S226>/Action Port'
       */
      /* If: '<S223>/If' incorporates:
       *  Selector: '<S216>/Selector1'
       *  Selector: '<S223>/Selector'
       *  Selector: '<S226>/Selector'
       */
      rtb_Switch1_k = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S223>/Increment_If_Rectangle_Check' */

      /* Sum: '<S223>/Minus' incorporates:
       *  Concatenate: '<S216>/Matrix Concatenate2'
       *  Selector: '<S223>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Switch1_k;

      /* Outputs for IfAction SubSystem: '<S223>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S226>/Action Port'
       */
      /* If: '<S223>/If' incorporates:
       *  Selector: '<S216>/Selector1'
       *  Selector: '<S223>/Selector'
       *  Selector: '<S226>/Selector'
       *  Sum: '<S223>/Minus'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh)
        + 9];

      /* End of Outputs for SubSystem: '<S223>/Increment_If_Rectangle_Check' */

      /* Sum: '<S223>/Minus' incorporates:
       *  Concatenate: '<S216>/Matrix Concatenate2'
       *  Selector: '<S223>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Init_o;

      /* Math: '<S223>/Hypot' */
      rtb_Switch1_n = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S223>/Equal' */
      rtb_LogicalOperator5 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S223>/Switch' incorporates:
       *  Logic: '<S223>/AND'
       *  Logic: '<S223>/OR'
       *  RelationalOperator: '<S223>/Relational Operator'
       *  UnitDelay: '<S223>/Unit Delay'
       */
      rtb_LogicalOperator1 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Switch1_n <= rtb_Saturation_h) && rtb_LogicalOperator5));

      /* If: '<S223>/If' */
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
        /* Disable for If: '<S225>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S223>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S225>/Action Port'
         */
        /* If: '<S225>/If' incorporates:
         *  RelationalOperator: '<S225>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S225>/Is_Last_Point' incorporates:
           *  ActionPort: '<S228>/Action Port'
           */
          /* InitializeConditions for If: '<S225>/If' incorporates:
           *  UnitDelay: '<S228>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S225>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S225>/Is_Last_Point' incorporates:
           *  ActionPort: '<S228>/Action Port'
           */
          /* Switch: '<S228>/Switch' incorporates:
           *  Constant: '<S230>/Constant'
           *  Logic: '<S228>/OR'
           *  RelationalOperator: '<S230>/Compare'
           *  UnitDelay: '<S228>/Unit Delay'
           */
          rtb_Compare_mq = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
                            (rtb_Switch1_n <= Spline_Stop_Radius));

          /* If: '<S228>/If' */
          if (rtb_Compare_mq) {
            /* Outputs for IfAction SubSystem: '<S228>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S231>/Action Port'
             */
            /* Merge: '<S220>/Merge2' incorporates:
             *  Constant: '<S231>/Constant'
             *  SignalConversion generated from: '<S231>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = true;

            /* SignalConversion generated from: '<S231>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S231>/Constant1'
             */
            rtb_Compare_pb = false;

            /* End of Outputs for SubSystem: '<S228>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S228>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S232>/Action Port'
             */
            /* Merge: '<S220>/Merge2' incorporates:
             *  Constant: '<S232>/Constant'
             *  SignalConversion generated from: '<S232>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = false;

            /* SignalConversion generated from: '<S232>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S232>/Constant1'
             */
            rtb_Compare_pb = true;

            /* End of Outputs for SubSystem: '<S228>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S228>/If' */

          /* Merge: '<S220>/Merge4' incorporates:
           *  SignalConversion: '<S228>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S228>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Compare_mq;

          /* End of Outputs for SubSystem: '<S225>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S225>/Increment_Search' incorporates:
           *  ActionPort: '<S227>/Action Port'
           */
          /* Merge: '<S220>/Merge2' incorporates:
           *  Constant: '<S227>/Constant'
           *  SignalConversion generated from: '<S227>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator5 = false;

          /* SignalConversion generated from: '<S227>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S227>/Constant1'
           */
          rtb_Compare_pb = false;

          /* Merge: '<S220>/Merge4' incorporates:
           *  Constant: '<S229>/FixPt Constant'
           *  SignalConversion: '<S227>/Signal Copy'
           *  Sum: '<S229>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S225>/Increment_Search' */
        }

        /* End of If: '<S225>/If' */
        /* End of Outputs for SubSystem: '<S223>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S223>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S226>/Action Port'
         */
        /* Sum: '<S233>/FixPt Sum1' incorporates:
         *  Constant: '<S233>/FixPt Constant'
         */
        rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S226>/Selector1' incorporates:
         *  Selector: '<S216>/Selector1'
         */
        rtb_Switch2_i = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) - 1];

        /* Sum: '<S234>/Subtract' incorporates:
         *  Selector: '<S226>/Selector1'
         *  Sum: '<S234>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_i - rtb_Switch1_k;

        /* Selector: '<S226>/Selector1' incorporates:
         *  Selector: '<S216>/Selector1'
         */
        rtb_Switch2_g = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) + 9];

        /* Sum: '<S234>/Subtract' incorporates:
         *  Selector: '<S226>/Selector1'
         *  Sum: '<S234>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch2_g - rtb_Init_o;

        /* Math: '<S234>/Hypot' */
        rtb_Switch2_dh = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S234>/Divide' */
        rtb_Switch1_n = rtb_Minus_n[1];

        /* UnaryMinus: '<S234>/Unary Minus' */
        rtb_Minus_f = rtb_Minus_n[0];

        /* Product: '<S234>/Product' incorporates:
         *  Product: '<S234>/Divide'
         *  UnaryMinus: '<S234>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch1_n / rtb_Switch2_dh) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Minus_f) / rtb_Switch2_dh) * rtb_Saturation_h;

        /* Sum: '<S234>/Add1' incorporates:
         *  Sum: '<S234>/Add2'
         *  Sum: '<S234>/Minus'
         */
        rtb_Minus_f = rtb_Switch2_i - rtb_Minus_n[0];

        /* Sum: '<S234>/Minus4' incorporates:
         *  Sum: '<S234>/Add2'
         *  Sum: '<S234>/Minus'
         */
        rtb_Switch2_i = (rtb_Switch2_i + rtb_Minus_n[0]) - rtb_Minus_f;

        /* Sum: '<S234>/Minus5' incorporates:
         *  Concatenate: '<S216>/Matrix Concatenate2'
         *  Sum: '<S234>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[0] - rtb_Minus_f;

        /* Sum: '<S234>/Add' incorporates:
         *  Sum: '<S234>/Add2'
         *  Sum: '<S234>/Minus1'
         */
        rtb_Switch1_n = rtb_Switch1_k - rtb_Minus_n[0];

        /* Sum: '<S234>/Minus' incorporates:
         *  Sum: '<S234>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S234>/Dot Product' incorporates:
         *  Concatenate: '<S216>/Matrix Concatenate2'
         *  Sum: '<S234>/Minus'
         *  Sum: '<S234>/Minus1'
         *  Sum: '<S234>/Minus5'
         */
        rtb_Switch2_dh = (rtb_Reshapey[0] - rtb_Switch1_n) * rtb_Minus_f;

        /* DotProduct: '<S234>/Dot Product1' incorporates:
         *  Sum: '<S234>/Minus'
         */
        rtb_Switch1_k = rtb_Minus_f * rtb_Minus_f;

        /* DotProduct: '<S234>/Dot Product2' incorporates:
         *  Sum: '<S234>/Minus4'
         *  Sum: '<S234>/Minus5'
         */
        rtb_Minus_k_idx_0 = rtb_Switch2_i * rtb_MatrixConcatenate_b_idx_0;

        /* DotProduct: '<S234>/Dot Product3' incorporates:
         *  Sum: '<S234>/Minus4'
         */
        rtb_Optimized_Module_Angle = rtb_Switch2_i * rtb_Switch2_i;

        /* Sum: '<S234>/Add1' incorporates:
         *  Sum: '<S234>/Add2'
         *  Sum: '<S234>/Minus'
         */
        rtb_Minus_f = rtb_Switch2_g - rtb_Minus_n[1];

        /* Sum: '<S234>/Minus4' incorporates:
         *  Sum: '<S234>/Add2'
         *  Sum: '<S234>/Minus'
         */
        rtb_Switch2_i = (rtb_Switch2_g + rtb_Minus_n[1]) - rtb_Minus_f;

        /* Sum: '<S234>/Minus5' incorporates:
         *  Concatenate: '<S216>/Matrix Concatenate2'
         *  Sum: '<S234>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[1] - rtb_Minus_f;

        /* Sum: '<S234>/Add' incorporates:
         *  Sum: '<S234>/Add2'
         *  Sum: '<S234>/Minus1'
         */
        rtb_Switch1_n = rtb_Init_o - rtb_Minus_n[1];

        /* Sum: '<S234>/Minus' incorporates:
         *  Sum: '<S234>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S234>/Dot Product' incorporates:
         *  Concatenate: '<S216>/Matrix Concatenate2'
         *  Sum: '<S234>/Minus'
         *  Sum: '<S234>/Minus1'
         *  Sum: '<S234>/Minus5'
         */
        rtb_Switch2_dh += (rtb_Reshapey[1] - rtb_Switch1_n) * rtb_Minus_f;

        /* RelationalOperator: '<S235>/Compare' incorporates:
         *  Constant: '<S235>/Constant'
         */
        rtb_LogicalOperator5 = (rtb_Switch2_dh >= 0.0);

        /* RelationalOperator: '<S234>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S234>/Dot Product1'
         *  Sum: '<S234>/Minus'
         */
        rtb_Compare_pb = (rtb_Switch2_dh <= ((rtb_Minus_f * rtb_Minus_f) +
          rtb_Switch1_k));

        /* DotProduct: '<S234>/Dot Product2' incorporates:
         *  Sum: '<S234>/Minus4'
         *  Sum: '<S234>/Minus5'
         */
        rtb_Switch2_dh = (rtb_Switch2_i * rtb_MatrixConcatenate_b_idx_0) +
          rtb_Minus_k_idx_0;

        /* Merge: '<S220>/Merge4' incorporates:
         *  Constant: '<S236>/Constant'
         *  DataTypeConversion: '<S226>/Data Type Conversion'
         *  DotProduct: '<S234>/Dot Product3'
         *  Logic: '<S234>/AND'
         *  RelationalOperator: '<S234>/LessThanOrEqual1'
         *  RelationalOperator: '<S236>/Compare'
         *  Sum: '<S226>/Add'
         *  Sum: '<S234>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_LogicalOperator5 &&
          rtb_Compare_pb) && (rtb_Switch2_dh >= 0.0)) && (rtb_Switch2_dh <=
          ((rtb_Switch2_i * rtb_Switch2_i) + rtb_Optimized_Module_Angle)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S220>/Merge2' incorporates:
         *  Constant: '<S226>/Constant2'
         *  SignalConversion generated from: '<S226>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S226>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S226>/Constant1'
         */
        rtb_Compare_pb = false;

        /* End of Outputs for SubSystem: '<S223>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S223>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S224>/Action Port'
         */
        /* Merge: '<S220>/Merge2' incorporates:
         *  Constant: '<S224>/Constant2'
         *  SignalConversion generated from: '<S224>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S224>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S224>/Constant1'
         */
        rtb_Compare_pb = false;

        /* Merge: '<S220>/Merge4' incorporates:
         *  SignalConversion generated from: '<S224>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S223>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S220>/Merge1' incorporates:
       *  Constant: '<S223>/Constant'
       *  SignalConversion generated from: '<S223>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S223>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator1;

      /* End of Outputs for SubSystem: '<S220>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S220>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S222>/Action Port'
       */
      /* Merge: '<S220>/Merge1' incorporates:
       *  Constant: '<S222>/Constant'
       *  SignalConversion generated from: '<S222>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S220>/Merge2' incorporates:
       *  Constant: '<S222>/Constant1'
       *  SignalConversion generated from: '<S222>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator5 = false;

      /* SignalConversion generated from: '<S222>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S222>/Constant2'
       */
      rtb_Compare_pb = false;

      /* Merge: '<S220>/Merge4' incorporates:
       *  SignalConversion generated from: '<S222>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S220>/Escape_Auto_Driving' */
    }

    /* End of If: '<S220>/If' */

    /* If: '<S216>/If1' */
    if (!rtb_Compare_pb) {
      /* Outputs for IfAction SubSystem: '<S216>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S221>/Action Port'
       */
      /* Bias: '<S237>/Add Constant' incorporates:
       *  Bias: '<S237>/Bias'
       *  Sum: '<S237>/Subtract'
       */
      rtb_Switch1_n = ((Robot_Control_B.Spline_Num_Poses -
                        Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S237>/Selector4' incorporates:
       *  Bias: '<S237>/Bias1'
       *  Constant: '<S239>/FixPt Constant'
       *  Sum: '<S239>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S237>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S237>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s242_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S237>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S237>/Selector5' incorporates:
       *  Concatenate: '<S237>/Matrix Concatenate'
       *  Gain: '<S241>/Gain'
       *  Selector: '<S216>/Selector1'
       *  Selector: '<S237>/Selector2'
       *  Selector: '<S237>/Selector3'
       *  Sum: '<S241>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s242_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S237>/Matrix Concatenate' incorporates:
       *  Bias: '<S237>/Add Constant1'
       *  Gain: '<S240>/Gain'
       *  Selector: '<S216>/Selector1'
       *  Selector: '<S237>/Selector'
       *  Selector: '<S237>/Selector1'
       *  Selector: '<S237>/Selector5'
       *  Sum: '<S240>/Subtract'
       */
      s242_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s242_iter;
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

      /* Selector: '<S237>/Selector4' */
      s242_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s242_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S237>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S237>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S237>/Assignment' incorporates:
       *  Concatenate: '<S237>/Matrix Concatenate'
       *  Selector: '<S237>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s242_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S238>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S242>/While Iterator'
       */
      s242_iter = 1;
      do {
        rtb_Switch1_k = rtb_Assignment[s242_iter + 1];
        rtb_Minus_n[0] = rtb_Switch1_k - rtb_Assignment[s242_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s242_iter] - rtb_Assignment[s242_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Switch1_k - rtb_Assignment[s242_iter];
        rtb_Switch1_k = rtb_Assignment[s242_iter + 13];
        rtb_Minus_n[1] = rtb_Switch1_k - rtb_Assignment[s242_iter + 11];
        rtb_Minus_f = rtb_Assignment[s242_iter + 12];
        rtb_Add2[1] = rtb_Minus_f - rtb_Assignment[s242_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Switch1_k - rtb_Minus_f;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Switch2_dh = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Init_o = rt_powd_snf(rtb_Switch2_dh, 2.0);
          rtb_Switch2_i = rt_powd_snf(rtb_Switch2_dh, 3.0);
          rtb_Switch2_g = (rtb_Switch2_dh - (2.0 * rtb_Init_o)) + rtb_Switch2_i;
          rtb_Switch1_k = rtb_Init_o - rtb_Switch2_i;
          rtb_Switch2_i = (3.0 * rtb_Init_o) - (2.0 * rtb_Switch2_i);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch2_g) +
            (rtb_Add2[0] * rtb_Switch1_k)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Switch2_i)) + rtb_Assignment[s242_iter];
          rtb_Switch2_i = ((((rtb_Minus_n[1] * rtb_Switch2_g) + (rtb_Add2[1] *
            rtb_Switch1_k)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_i)) +
            rtb_Minus_f;
          rtb_Switch2_g = ((3.0 * rtb_Init_o) - (4.0 * rtb_Switch2_dh)) + 1.0;
          rtb_Switch1_k = (2.0 * rtb_Switch2_dh) - (3.0 * rtb_Init_o);
          rtb_Init_o = (rtb_Switch2_dh - rtb_Init_o) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch2_g) +
            (rtb_Add2[0] * rtb_Switch1_k)) * 0.5) + (rtb_Minus_k_idx_0 *
            rtb_Init_o);
          rtb_Optimized_Module_Angle = (((rtb_Minus_n[1] * rtb_Switch2_g) +
            (rtb_Add2[1] * rtb_Switch1_k)) * 0.5) + (rtb_Minus_k_idx_1 *
            rtb_Init_o);
          rtb_Init_o = (6.0 * rtb_Switch2_dh) - 4.0;
          rtb_Switch2_g = (-6.0 * rtb_Switch2_dh) + 2.0;
          rtb_Switch2_dh = (-12.0 * rtb_Switch2_dh) + 6.0;
          rtb_Switch1_k = (((rtb_Minus_n[0] * rtb_Init_o) + (rtb_Add2[0] *
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
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch2_g) - (rtb_Switch1_k *
              rtb_Optimized_Module_Angle)) / (rtb_Switch2_dh * ((real_T)i));
        }

        if (s242_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s242_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Switch2_dh = rtb_Switch1_n - ((real_T)s242_iter);
        rtb_Num_Segments = s242_iter;
        s242_iter++;
      } while ((rtb_Switch2_dh >= 4.0) && (s242_iter <= 3));

      /* End of Outputs for SubSystem: '<S238>/Sampling_Loop' */

      /* SignalConversion generated from: '<S221>/Position_and_Curvature' incorporates:
       *  Assignment: '<S242>/Assignment'
       *  Merge: '<S216>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S216>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S216>/If Action Subsystem' incorporates:
       *  ActionPort: '<S219>/Action Port'
       */
      /* Product: '<S219>/Product' incorporates:
       *  Selector: '<S216>/Selector'
       *  Selector: '<S216>/Selector1'
       */
      rtb_Switch2_dh = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S219>/Product1' incorporates:
       *  Selector: '<S216>/Selector'
       *  Selector: '<S216>/Selector1'
       */
      rtb_Switch1_n = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S219>/Product' incorporates:
         *  Constant: '<S219>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Switch2_dh;

        /* Product: '<S219>/Product1' incorporates:
         *  Constant: '<S219>/Constant2'
         *  Product: '<S219>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch1_n;
      }

      /* Assignment: '<S219>/Assignment' incorporates:
       *  Concatenate: '<S219>/Matrix Concatenate'
       *  Merge: '<S216>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S219>/Assignment' */

      /* SignalConversion generated from: '<S219>/Num_Segments' incorporates:
       *  Constant: '<S219>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S216>/If Action Subsystem' */
    }

    /* End of If: '<S216>/If1' */

    /* Concatenate: '<S217>/Matrix Concatenate' incorporates:
     *  Merge: '<S216>/Merge'
     *  Selector: '<S217>/Selector'
     *  Selector: '<S217>/Selector1'
     *  Selector: '<S217>/Selector3'
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

    /* End of Concatenate: '<S217>/Matrix Concatenate' */

    /* MATLAB Function: '<S217>/Distance Along Curve' incorporates:
     *  Concatenate: '<S217>/Matrix Concatenate'
     *  Selector: '<S217>/Selector4'
     *  Selector: '<S217>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s242_iter = 0; s242_iter < 149; s242_iter++) {
      /* Outputs for Iterator SubSystem: '<S238>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S242>/While Iterator'
       */
      rtb_Assignment_d[s242_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s242_iter + 1] -
         rtb_MatrixConcatenate_o[s242_iter], rtb_MatrixConcatenate_o[s242_iter +
         151] - rtb_MatrixConcatenate_o[s242_iter + 150]) +
        rtb_Assignment_d[s242_iter];

      /* End of Outputs for SubSystem: '<S238>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S217>/Distance Along Curve' */

    /* MATLAB Function: '<S217>/Find closest index to curve' incorporates:
     *  Concatenate: '<S217>/Matrix Concatenate'
     *  Selector: '<S217>/Selector4'
     *  Selector: '<S217>/Selector5'
     *  Selector: '<S268>/Selector'
     */
    for (s242_iter = 0; s242_iter < 150; s242_iter++) {
      /* Outputs for Iterator SubSystem: '<S238>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S242>/While Iterator'
       */
      distance_from_robot[s242_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s242_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s242_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S238>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s242_iter = 1;
    } else {
      s242_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s242_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s242_iter == 0) {
      rtb_Switch1_n = distance_from_robot[0];
    } else {
      rtb_Switch1_n = distance_from_robot[s242_iter - 1];
      for (rtb_Bias1_p = s242_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Switch2_dh = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_n > rtb_Switch2_dh) {
          rtb_Switch1_n = rtb_Switch2_dh;
        }
      }
    }

    s242_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s242_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_n) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S268>/Selector' incorporates:
     *  Constant: '<S268>/Constant'
     *  MATLAB Function: '<S217>/Find closest index to curve'
     *  MinMax: '<S268>/Min'
     */
    rtb_Switch2_dh = rtb_Assignment_d[((int32_T)fmin(50.0, s242_iter)) - 1];

    /* If: '<S268>/If' incorporates:
     *  RelationalOperator: '<S268>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S268>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S271>/Action Port'
       */
      /* SignalConversion generated from: '<S271>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S273>/FixPt Sum1' incorporates:
       *  Constant: '<S273>/FixPt Constant'
       */
      rtb_Switch1_n = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S271>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S271>/Selector11'
       *  Selector: '<S271>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S271>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S271>/Selector1'
       *  Selector: '<S271>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S271>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S271>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_n), &rtb_Minus_n[0], rtb_Switch2_dh,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S271>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S271>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S271>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Switch2_dh,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S268>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S268>/Latch' incorporates:
       *  ActionPort: '<S272>/Action Port'
       */
      /* SignalConversion generated from: '<S272>/In1' incorporates:
       *  UnitDelay: '<S268>/Unit Delay1'
       */
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S272>/In2' incorporates:
       *  UnitDelay: '<S268>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S268>/Latch' */
    }

    /* End of If: '<S268>/If' */

    /* MinMax: '<S215>/Min' incorporates:
     *  Lookup_n-D: '<S215>/Lookahead Distance'
     *  UnitDelay: '<S215>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S217>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S267>/While Iterator'
     */
    s267_iter = 1U;
    rtb_LogicalOperator1 = true;
    while (rtb_LogicalOperator1 && (s267_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S217>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S267>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s267_iter;
      rtb_LogicalOperator1 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s242_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s267_iter++;
    }

    /* End of Outputs for SubSystem: '<S217>/Find first index that meets distance target' */

    /* Switch: '<S270>/Switch' incorporates:
     *  Concatenate: '<S217>/Matrix Concatenate'
     *  Constant: '<S217>/Constant'
     *  Constant: '<S267>/Constant'
     *  Constant: '<S270>/Constant'
     *  Constant: '<S270>/Constant1'
     *  Constant: '<S270>/Constant2'
     *  Constant: '<S270>/Constant3'
     *  Logic: '<S267>/AND'
     *  MATLAB Function: '<S217>/Find closest index to curve'
     *  Math: '<S270>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S270>/Max'
     *  MinMax: '<S270>/Min'
     *  MinMax: '<S270>/Min1'
     *  Product: '<S267>/Product'
     *  Product: '<S270>/Divide'
     *  Product: '<S270>/Product'
     *  Product: '<S270>/Product1'
     *  RelationalOperator: '<S217>/Relational Operator'
     *  RelationalOperator: '<S267>/Relational Operator'
     *  RelationalOperator: '<S267>/Relational Operator1'
     *  Selector: '<S217>/Selector10'
     *  Selector: '<S217>/Selector7'
     *  Selector: '<S217>/Selector8'
     *  Selector: '<S217>/Selector9'
     *  Selector: '<S267>/Selector'
     *  Selector: '<S267>/Selector1'
     *  Selector: '<S268>/Selector'
     *  Sqrt: '<S270>/Sqrt'
     *  Sum: '<S217>/Subtract'
     *  Sum: '<S267>/Add'
     *  Sum: '<S270>/Subtract'
     *  Sum: '<S270>/Subtract1'
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

    /* End of Switch: '<S270>/Switch' */

    /* Logic: '<S218>/OR' */
    rtb_Compare_pb = (rtb_LogicalOperator5 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S218>/Switch1' incorporates:
     *  Switch: '<S218>/Switch'
     *  UnitDelay: '<S218>/Unit Delay'
     */
    if (rtb_Compare_pb) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S218>/Constant3'
       *  SignalConversion: '<S218>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Switch2_dh = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S218>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Switch2_dh = rtb_Merge1;
    }

    /* End of Switch: '<S218>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S218>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Switch2_dh;

    /* Selector: '<S217>/Selector6' incorporates:
     *  Concatenate: '<S217>/Matrix Concatenate'
     *  Selector: '<S217>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S217>/Selector2' incorporates:
     *  Concatenate: '<S217>/Matrix Concatenate'
     *  Selector: '<S217>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S218>/Switch2' incorporates:
     *  Sum: '<S274>/Subtract'
     *  Sum: '<S274>/Subtract1'
     *  Trigonometry: '<S274>/Atan2'
     *  UnitDelay: '<S218>/Unit Delay1'
     */
    if (rtb_Compare_pb) {
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Init_o = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S218>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S218>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Init_o;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S215>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator5;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S215>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S218>/Constant2'
     *  SignalConversion generated from: '<S215>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S218>/Constant5'
     *  SignalConversion generated from: '<S215>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S218>/Constant6'
     *  SignalConversion generated from: '<S215>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S215>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S216>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S215>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S268>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_n;

    /* Update for UnitDelay: '<S268>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S218>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Switch2_dh;

    /* Update for UnitDelay: '<S218>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Init_o;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S214>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S214>/Constant1'
     *  SignalConversion generated from: '<S214>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S214>/Constant'
     *  SignalConversion generated from: '<S214>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S214>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S214>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S214>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S214>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S214>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Compare_pb;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S214>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Compare_mq;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S214>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* UnitDelay: '<S364>/Unit Delay' */
  rtb_Merge1 = Robot_Control_B.Translation_Speed_RL;

  /* Signum: '<S364>/Sign2' */
  if (rtIsNaN(rtb_Merge1)) {
    rtb_Minus_f = (rtNaN);
  } else if (rtb_Merge1 < 0.0) {
    rtb_Minus_f = -1.0;
  } else {
    rtb_Minus_f = (rtb_Merge1 > 0.0);
  }

  /* Signum: '<S364>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S364>/Product1' incorporates:
   *  Signum: '<S364>/Sign1'
   *  Signum: '<S364>/Sign2'
   */
  rtb_Minus_f *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Minus_f)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_f, 256.0);
  }

  /* Switch: '<S364>/Switch' incorporates:
   *  Constant: '<S364>/Constant'
   *  Constant: '<S369>/Constant'
   *  Constant: '<S370>/Constant'
   *  Logic: '<S364>/or'
   *  Product: '<S364>/Product1'
   *  RelationalOperator: '<S369>/Compare'
   *  RelationalOperator: '<S370>/Compare'
   */
  if ((rtb_Merge1 == 0.0) || (((i < 0) ? ((int32_T)((int8_T)(-((int8_T)((uint8_T)
             (-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_g = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Switch2_g = 0.0;
  }

  /* End of Switch: '<S364>/Switch' */

  /* Switch: '<S375>/Init' incorporates:
   *  UnitDelay: '<S375>/FixPt Unit Delay1'
   *  UnitDelay: '<S375>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Init_o = rtb_Switch2_g;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S375>/Init' */

  /* RelationalOperator: '<S371>/Compare' incorporates:
   *  Constant: '<S371>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Switch2_g == 0.0);

  /* RelationalOperator: '<S372>/Compare' incorporates:
   *  Constant: '<S372>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Switch2_g > 0.0);

  /* Abs: '<S364>/Abs' incorporates:
   *  Sum: '<S364>/Subtract'
   */
  rtb_Merge1 = fabs(rtb_Merge1 - Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S364>/Switch5' incorporates:
   *  Constant: '<S364>/Constant1'
   *  Switch: '<S364>/Switch1'
   *  UnaryMinus: '<S364>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S364>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S364>/Constant4'
     *  Constant: '<S364>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S364>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S364>/Constant2'
     *  Constant: '<S364>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S364>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S364>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S364>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S364>/Constant10'
     *  Constant: '<S364>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S364>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S364>/Constant7'
     *  Constant: '<S364>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S364>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S364>/Lookup Table Dynamic1'
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

    /* Switch: '<S364>/Switch3' incorporates:
     *  Constant: '<S364>/Constant1'
     *  Constant: '<S364>/Constant3'
     *  UnaryMinus: '<S364>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      rtb_Minus_f = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Minus_f = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S364>/Switch3' */
  }

  /* End of Switch: '<S364>/Switch5' */

  /* Product: '<S364>/Product' incorporates:
   *  Switch: '<S364>/Switch1'
   */
  rtb_Minus_k_idx_0 = rtb_Minus_f * rtb_Merge1;

  /* Sum: '<S373>/Sum1' */
  rtb_Saturation_h = rtb_Switch2_g - rtb_Init_o;

  /* Switch: '<S374>/Switch2' incorporates:
   *  RelationalOperator: '<S374>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Minus_k_idx_0)) {
    /* Switch: '<S364>/Switch2' incorporates:
     *  Constant: '<S364>/Constant1'
     *  Switch: '<S364>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S364>/Switch4' incorporates:
       *  Constant: '<S364>/Constant1'
       */
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S364>/Switch4' incorporates:
       *  Constant: '<S364>/Constant3'
       *  UnaryMinus: '<S364>/Unary Minus1'
       */
      rtb_Switch1_n = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S364>/Switch2' */

    /* Product: '<S364>/Product2' */
    rtb_Switch1_n *= rtb_Merge1;

    /* Switch: '<S374>/Switch' incorporates:
     *  RelationalOperator: '<S374>/UpperRelop'
     */
    if (rtb_Saturation_h < rtb_Switch1_n) {
      rtb_Minus_k_idx_0 = rtb_Switch1_n;
    } else {
      rtb_Minus_k_idx_0 = rtb_Saturation_h;
    }

    /* End of Switch: '<S374>/Switch' */
  }

  /* End of Switch: '<S374>/Switch2' */

  /* Sum: '<S373>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Minus_k_idx_0 + rtb_Init_o;

  /* Switch: '<S367>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S367>/Switch' incorporates:
     *  Constant: '<S401>/Constant3'
     *  Constant: '<S401>/Constant4'
     *  Math: '<S401>/Math Function'
     *  Sum: '<S367>/Subtract'
     *  Sum: '<S401>/Add1'
     *  Sum: '<S401>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S367>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S367>/Switch' */

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

  /* Switch: '<S193>/Switch' incorporates:
   *  Constant: '<S180>/Constant'
   *  Constant: '<S193>/Constant'
   *  RelationalOperator: '<S180>/Compare'
   *  UnitDelay: '<S193>/Unit Delay'
   */
  if (rtb_GameState != 1) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_o;
  }

  /* Sum: '<S193>/Sum' incorporates:
   *  Constant: '<S193>/Constant4'
   *  Switch: '<S193>/Switch'
   */
  rtb_Merge1 = rtb_Minus_f + 0.02;

  /* Switch: '<S194>/Switch' incorporates:
   *  Constant: '<S185>/Constant'
   *  Constant: '<S194>/Constant'
   *  RelationalOperator: '<S185>/Compare'
   *  UnitDelay: '<S194>/Unit Delay'
   */
  if (rtb_GameState != 2) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_m;
  }

  /* MultiPortSwitch: '<S141>/Multiport Switch' incorporates:
   *  Constant: '<S141>/Constant1'
   *  Constant: '<S141>/Constant3'
   *  Constant: '<S194>/Constant4'
   *  Sum: '<S194>/Sum'
   *  Switch: '<S194>/Switch'
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

  /* End of MultiPortSwitch: '<S141>/Multiport Switch' */

  /* If: '<S141>/If' incorporates:
   *  Constant: '<S178>/Constant'
   *  Constant: '<S179>/Constant'
   *  Constant: '<S181>/Constant'
   *  Constant: '<S182>/Constant'
   *  Constant: '<S183>/Constant'
   *  Constant: '<S184>/Constant'
   *  Constant: '<S186>/Constant'
   *  Inport: '<Root>/IsBlueAlliance'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  Inport: '<Root>/MatchTime'
   *  Logic: '<S141>/Logical Operator'
   *  RelationalOperator: '<S178>/Compare'
   *  RelationalOperator: '<S179>/Compare'
   *  RelationalOperator: '<S181>/Compare'
   *  RelationalOperator: '<S182>/Compare'
   *  RelationalOperator: '<S183>/Compare'
   *  RelationalOperator: '<S184>/Compare'
   *  RelationalOperator: '<S186>/Compare'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_n;
  if (((Robot_Control_U.MatchTime == -1.0) || (rtb_GameState == 1)) ||
      (rtb_Switch2_g <= Rebuilt_Match_Time_Transition)) {
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
      /* InitializeConditions for IfAction SubSystem: '<S141>/If Action Subsystem' incorporates:
       *  ActionPort: '<S187>/Action Port'
       */
      /* InitializeConditions for If: '<S141>/If' incorporates:
       *  UnitDelay: '<S187>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S141>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem' incorporates:
     *  ActionPort: '<S187>/Action Port'
     */
    /* Merge: '<S141>/Merge' incorporates:
     *  Constant: '<S187>/Constant'
     *  SignalConversion generated from: '<S187>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S141>/Merge1' incorporates:
     *  Constant: '<S187>/Constant'
     *  SignalConversion generated from: '<S187>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S187>/Sum' incorporates:
     *  Constant: '<S187>/Constant1'
     *  UnitDelay: '<S187>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hb - 0.02;

    /* Merge: '<S141>/Merge2' incorporates:
     *  SignalConversion: '<S187>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S187>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S141>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S188>/Action Port'
       */
      /* SystemReset for If: '<S141>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem1);

      /* End of SystemReset for SubSystem: '<S141>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S188>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem1' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S141>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S189>/Action Port'
       */
      /* InitializeConditions for If: '<S141>/If' incorporates:
       *  UnitDelay: '<S189>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S141>/If Action Subsystem2' */
    }

    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S189>/Action Port'
     */
    /* Sum: '<S189>/Sum' incorporates:
     *  Constant: '<S189>/Constant1'
     *  UnitDelay: '<S189>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hz - 0.02;

    /* RelationalOperator: '<S196>/Compare' incorporates:
     *  Constant: '<S196>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S141>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S189>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S141>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S189>/Logical Operator1'
     *  Logic: '<S189>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S189>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S189>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S141>/Merge2' incorporates:
       *  Constant: '<S189>/Constant2'
       *  Sum: '<S189>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S141>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;
    }

    /* End of Switch: '<S189>/Switch' */

    /* Update for UnitDelay: '<S189>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hz = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem2' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S141>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S190>/Action Port'
       */
      /* SystemReset for If: '<S141>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem3);

      /* End of SystemReset for SubSystem: '<S141>/If Action Subsystem3' */
    }

    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S190>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem3' */
    break;

   case 4:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S141>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S191>/Action Port'
       */
      /* InitializeConditions for If: '<S141>/If' incorporates:
       *  UnitDelay: '<S191>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S141>/If Action Subsystem4' */
    }

    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S191>/Action Port'
     */
    /* Sum: '<S191>/Sum' incorporates:
     *  Constant: '<S191>/Constant1'
     *  UnitDelay: '<S191>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_di - 0.02;

    /* RelationalOperator: '<S198>/Compare' incorporates:
     *  Constant: '<S198>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S141>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S191>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S141>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S191>/Logical Operator1'
     *  Logic: '<S191>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S191>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S191>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S141>/Merge2' incorporates:
       *  Constant: '<S191>/Constant2'
       *  Sum: '<S191>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S141>/Merge2' incorporates:
       *  Constant: '<S191>/Constant3'
       *  Sum: '<S191>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S191>/Switch' */

    /* Update for UnitDelay: '<S191>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem4' */
    break;

   default:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S141>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S192>/Action Port'
       */
      /* InitializeConditions for If: '<S141>/If' incorporates:
       *  UnitDelay: '<S192>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

      /* End of InitializeConditions for SubSystem: '<S141>/If Action Subsystem5' */
    }

    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S192>/Action Port'
     */
    /* Merge: '<S141>/Merge' incorporates:
     *  Constant: '<S192>/Constant'
     *  SignalConversion generated from: '<S192>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S141>/Merge1' incorporates:
     *  Constant: '<S192>/Constant'
     *  SignalConversion generated from: '<S192>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S192>/Sum' incorporates:
     *  Constant: '<S192>/Constant1'
     *  UnitDelay: '<S192>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_du - 0.02;

    /* Merge: '<S141>/Merge2' incorporates:
     *  SignalConversion: '<S192>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S192>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_du = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S141>/If' */

  /* If: '<S200>/If' incorporates:
   *  If: '<S201>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S200>/Blue' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    /* Merge: '<S200>/Merge' incorporates:
     *  Constant: '<S202>/BlueAllianceZoneX'
     *  Logic: '<S202>/AND'
     *  RelationalOperator: '<S202>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S200>/Blue' */

    /* Outputs for IfAction SubSystem: '<S201>/Blue' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* Merge: '<S201>/Merge' incorporates:
     *  Constant: '<S204>/BlueAllianceZoneX'
     *  RelationalOperator: '<S204>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S201>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S200>/Red' incorporates:
     *  ActionPort: '<S203>/Action Port'
     */
    /* Merge: '<S200>/Merge' incorporates:
     *  Constant: '<S203>/RedAllianceZoneX'
     *  Logic: '<S203>/AND'
     *  RelationalOperator: '<S203>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S200>/Red' */

    /* Outputs for IfAction SubSystem: '<S201>/Red' incorporates:
     *  ActionPort: '<S205>/Action Port'
     */
    /* Merge: '<S201>/Merge' incorporates:
     *  Constant: '<S205>/RedAllianceZoneX'
     *  RelationalOperator: '<S205>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S201>/Red' */
  }

  /* End of If: '<S200>/If' */

  /* RelationalOperator: '<S146>/GreaterThan' incorporates:
   *  Constant: '<S146>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S146>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S146>/Relational Operator' incorporates:
   *  Abs: '<S146>/Abs'
   *  Constant: '<S199>/Constant3'
   *  Constant: '<S199>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S199>/Math Function'
   *  Sum: '<S146>/Subtract'
   *  Sum: '<S199>/Add1'
   *  Sum: '<S199>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S145>/Max' incorporates:
   *  Abs: '<S145>/Abs1'
   *  Abs: '<S145>/Abs2'
   *  Abs: '<S145>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S146>/Relational Operator1' incorporates:
   *  Abs: '<S146>/Abs1'
   *  Constant: '<S146>/Constant2'
   *  Sum: '<S146>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S146>/Relational Operator4' incorporates:
   *  Abs: '<S146>/Abs4'
   *  Constant: '<S146>/Constant1'
   *  Sum: '<S146>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S146>/AND' incorporates:
   *  Logic: '<S146>/OR'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  rtb_Compare_pb = ((((Robot_Control_B.RB_Logic_Gyro_Angle) ||
                      (Robot_Control_DW.UnitDelay_5_DSTATE)) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S146>/AND2' incorporates:
   *  Logic: '<S146>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_pb);

  /* RelationalOperator: '<S142>/Compare' incorporates:
   *  Constant: '<S142>/Constant'
   *  Inport: '<Root>/Gamepad_RT'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_RT != 0.0);

  /* SignalConversion: '<S146>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S146>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Compare_pb);

  /* Logic: '<S146>/AND4' */
  rtb_LogicalOperator5 = ((Robot_Control_B.RB_Logic_Shooter_Speed) &&
    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Chart: '<S12>/Shooter_Transfer_Feeder Chart' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
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
    rtb_LogicalOperator3 = !rtb_LogicalOperator1;
    if (((!rtb_Button_Spinup_Enable) && rtb_Compare_mq) && rtb_LogicalOperator3)
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
        if (((rtb_Compare_mq && rtb_LogicalOperator3) ||
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
        Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        Robot_Control_B.RB_Transfer_Init = 1.0;
        if ((rtb_Compare_ky && ((Robot_Control_B.RB_Ready_to_Score) ||
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
        if (Robot_Control_U.Measured_Transfer_Speed >
            (Robot_Control_B.RB_Desired_Transfer_Speed *
             Rebuilt_Transfer_Minimum_Factor)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Feeder;
          Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
          Robot_Control_B.RB_Transfer_Init = 0.0;
          Robot_Control_DW.Feeder_Loops_Shooting = 0.0;
        } else if (((rtb_Compare_mq && rtb_LogicalOperator3) ||
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

  /* RelationalOperator: '<S143>/Compare' incorporates:
   *  Constant: '<S143>/Constant'
   *  Inport: '<Root>/Gamepad_B2_B'
   */
  rtb_Compare_ky = (Robot_Control_U.Gamepad_B2_B != 0.0);

  /* Logic: '<S12>/AND' incorporates:
   *  Logic: '<S12>/NOT'
   */
  rtb_Button_Spinup_Enable = ((Robot_Control_B.RB_Shooter_Active) &&
    (!rtb_Compare_ky));

  /* If: '<S139>/If' incorporates:
   *  Constant: '<S152>/Constant'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Outputs for IfAction SubSystem: '<S139>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S152>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S153>/While Iterator'
     */
    /* SignalConversion generated from: '<S154>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S159>/Constant1'
     *  Constant: '<S159>/Constant10'
     *  Constant: '<S159>/Constant2'
     *  Constant: '<S159>/Constant5'
     *  Constant: '<S159>/Constant6'
     *  Constant: '<S159>/Constant7'
     *  Constant: '<S159>/Constant8'
     *  Constant: '<S159>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S152>/Iterate_Shot_Target' */

    /* SignalConversion generated from: '<S155>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S155>/Constant1'
     *  Constant: '<S155>/Constant10'
     *  Constant: '<S155>/Constant2'
     *  Constant: '<S155>/Constant5'
     *  Constant: '<S155>/Constant6'
     *  Constant: '<S155>/Constant7'
     *  Constant: '<S155>/Constant8'
     *  Constant: '<S155>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_o3[0] = Rebuilt_Shoot_Hood_Pos_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Rebuilt_Shoot_Hood_Pos_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Rebuilt_Shoot_Hood_Pos_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Rebuilt_Shoot_Hood_Pos_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Rebuilt_Shoot_Hood_Pos_4;
    rtb_TmpSignalConversionAtLoo_o3[5] = Rebuilt_Shoot_Hood_Pos_5;
    rtb_TmpSignalConversionAtLoo_o3[6] = Rebuilt_Shoot_Hood_Pos_6;
    rtb_TmpSignalConversionAtLoo_o3[7] = Rebuilt_Shoot_Hood_Pos_7;

    /* SignalConversion generated from: '<S154>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S154>/Constant1'
     *  Constant: '<S154>/Constant10'
     *  Constant: '<S154>/Constant2'
     *  Constant: '<S154>/Constant5'
     *  Constant: '<S154>/Constant6'
     *  Constant: '<S154>/Constant7'
     *  Constant: '<S154>/Constant8'
     *  Constant: '<S154>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ov[0] = Rebuilt_Shoot_Gyro_Err_0;
    rtb_TmpSignalConversionAtLoo_ov[1] = Rebuilt_Shoot_Gyro_Err_1;
    rtb_TmpSignalConversionAtLoo_ov[2] = Rebuilt_Shoot_Gyro_Err_2;
    rtb_TmpSignalConversionAtLoo_ov[3] = Rebuilt_Shoot_Gyro_Err_3;
    rtb_TmpSignalConversionAtLoo_ov[4] = Rebuilt_Shoot_Gyro_Err_4;
    rtb_TmpSignalConversionAtLoo_ov[5] = Rebuilt_Shoot_Gyro_Err_5;
    rtb_TmpSignalConversionAtLoo_ov[6] = Rebuilt_Shoot_Gyro_Err_6;
    rtb_TmpSignalConversionAtLoo_ov[7] = Rebuilt_Shoot_Gyro_Err_7;

    /* SignalConversion generated from: '<S156>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S168>/Constant1'
     *  Constant: '<S168>/Constant10'
     *  Constant: '<S168>/Constant2'
     *  Constant: '<S168>/Constant5'
     *  Constant: '<S168>/Constant6'
     *  Constant: '<S168>/Constant7'
     *  Constant: '<S168>/Constant8'
     *  Constant: '<S168>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_lg[0] = Rebuilt_Shoot_Shooter_Spd_0;
    rtb_TmpSignalConversionAtLoo_lg[1] = Rebuilt_Shoot_Shooter_Spd_1;
    rtb_TmpSignalConversionAtLoo_lg[2] = Rebuilt_Shoot_Shooter_Spd_2;
    rtb_TmpSignalConversionAtLoo_lg[3] = Rebuilt_Shoot_Shooter_Spd_3;
    rtb_TmpSignalConversionAtLoo_lg[4] = Rebuilt_Shoot_Shooter_Spd_4;
    rtb_TmpSignalConversionAtLoo_lg[5] = Rebuilt_Shoot_Shooter_Spd_5;
    rtb_TmpSignalConversionAtLoo_lg[6] = Rebuilt_Shoot_Shooter_Spd_6;
    rtb_TmpSignalConversionAtLoo_lg[7] = Rebuilt_Shoot_Shooter_Spd_7;

    /* SignalConversion generated from: '<S156>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S167>/Constant1'
     *  Constant: '<S167>/Constant10'
     *  Constant: '<S167>/Constant2'
     *  Constant: '<S167>/Constant5'
     *  Constant: '<S167>/Constant6'
     *  Constant: '<S167>/Constant7'
     *  Constant: '<S167>/Constant8'
     *  Constant: '<S167>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ix[0] = Rebuilt_Shoot_Shooter_Spd_I_0;
    rtb_TmpSignalConversionAtLoo_ix[1] = Rebuilt_Shoot_Shooter_Spd_I_1;
    rtb_TmpSignalConversionAtLoo_ix[2] = Rebuilt_Shoot_Shooter_Spd_I_2;
    rtb_TmpSignalConversionAtLoo_ix[3] = Rebuilt_Shoot_Shooter_Spd_I_3;
    rtb_TmpSignalConversionAtLoo_ix[4] = Rebuilt_Shoot_Shooter_Spd_I_4;
    rtb_TmpSignalConversionAtLoo_ix[5] = Rebuilt_Shoot_Shooter_Spd_I_5;
    rtb_TmpSignalConversionAtLoo_ix[6] = Rebuilt_Shoot_Shooter_Spd_I_6;
    rtb_TmpSignalConversionAtLoo_ix[7] = Rebuilt_Shoot_Shooter_Spd_I_7;

    /* Switch: '<S158>/Switch4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S158>/Logical Operator'
     *  Switch: '<S158>/Switch5'
     *  Switch: '<S158>/Switch6'
     */
    if ((Robot_Control_B.Is_Outside_Alliance_Zone) || rtb_LogicalOperator1) {
      /* Switch: '<S158>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S158>/Switch4' incorporates:
         *  Constant: '<S158>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S158>/Switch4' incorporates:
         *  Constant: '<S158>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S158>/Switch2' */

      /* Switch: '<S158>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S158>/Switch6' incorporates:
         *  Constant: '<S158>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S158>/Switch6' incorporates:
         *  Constant: '<S158>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S158>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S158>/Switch5' incorporates:
         *  Constant: '<S158>/Constant8'
         *  Switch: '<S158>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S158>/Switch4' incorporates:
         *  Constant: '<S158>/Constant9'
         *  Switch: '<S158>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S158>/Switch6' incorporates:
       *  Constant: '<S158>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* End of Switch: '<S158>/Switch4' */

    /* Outputs for Iterator SubSystem: '<S152>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S153>/While Iterator'
     */
    Iteration_Number = 1U;

    /* InitializeConditions for Memory: '<S153>/Memory1' */
    rtb_Switch1_n = 0.0;

    /* InitializeConditions for Memory: '<S153>/Memory2' */
    rtb_Switch2_dh = 0.0;

    /* InitializeConditions for Memory: '<S153>/Memory3' */
    rtb_Init_o = 0.0;

    /* InitializeConditions for Memory: '<S153>/Memory' */
    rtb_LogicalOperator5 = true;
    rtb_LogicalOperator1 = true;

    /* SignalConversion generated from: '<S161>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S152>/Constant'
     *  Constant: '<S161>/Constant'
     *  Constant: '<S161>/Constant1'
     *  Constant: '<S161>/Constant11'
     *  Constant: '<S161>/Constant2'
     *  Constant: '<S161>/Constant3'
     *  Constant: '<S161>/Constant4'
     *  Constant: '<S161>/Constant5'
     *  Constant: '<S161>/Constant6'
     */
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;

    /* SignalConversion generated from: '<S161>/Lookup Table Dynamic' */
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_LogicalOperator1 && (Iteration_Number <= 10)) {
      /* Switch: '<S162>/Switch' incorporates:
       *  Memory: '<S153>/Memory1'
       *  Memory: '<S153>/Memory2'
       *  Switch: '<S162>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Switch2_g = rtb_Switch1_n;
        rtb_Switch1_k = rtb_Switch2_dh;
      } else {
        rtb_Switch2_g = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Switch1_k = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S162>/Switch' */

      /* Math: '<S160>/Hypot' incorporates:
       *  Sum: '<S160>/Subtract'
       *  Sum: '<S160>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Switch2_g -
        Robot_Control_B.KF_Position_X, rtb_Switch1_k -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S161>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S161>/Lookup Table Dynamic'
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

      /* Sum: '<S163>/Subtract' incorporates:
       *  Memory: '<S153>/Memory3'
       *  Sum: '<S163>/Subtract1'
       */
      rtb_Switch2_dh = rtb_TOF - rtb_Init_o;

      /* Sum: '<S163>/Add' incorporates:
       *  Gain: '<S163>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S163>/Product'
       *  Sum: '<S163>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Switch2_dh *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Switch2_g;

      /* Sum: '<S163>/Add1' incorporates:
       *  Gain: '<S163>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S163>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Switch2_dh *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Switch1_k;

      /* Memory: '<S153>/Memory' */
      rtb_LogicalOperator1 = rtb_LogicalOperator5;

      /* Update for Memory: '<S153>/Memory1' */
      rtb_Switch1_n = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S153>/Memory2' */
      rtb_Switch2_dh = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S153>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S153>/Memory' incorporates:
       *  Constant: '<S165>/Constant'
       *  Math: '<S164>/Hypot'
       *  RelationalOperator: '<S165>/Compare'
       *  Sum: '<S164>/Subtract'
       *  Sum: '<S164>/Subtract1'
       */
      rtb_LogicalOperator5 = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X
        - rtb_Switch2_g, Robot_Control_B.RB_Desired_Target_Y - rtb_Switch1_k) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S152>/Iterate_Shot_Target' */

    /* Merge: '<S139>/Merge2' incorporates:
     *  S-Function (sfix_look1_dyn): '<S155>/Lookup Table Dynamic'
     */
    /* Dynamic Look-Up Table Block: '<S155>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S154>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S154>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S156>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S156>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S156>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S156>/Lookup Table Dynamic1'
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

    /* Switch: '<S156>/Switch' incorporates:
     *  Constant: '<S156>/Constant'
     *  Constant: '<S156>/Constant1'
     *  Sum: '<S156>/Add'
     *  UnitDelay: '<S156>/Unit Delay'
     */
    if (Robot_Control_B.RB_Transfer_Init != 0.0) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    /* End of Switch: '<S156>/Switch' */

    /* Switch: '<S156>/Switch1' incorporates:
     *  Constant: '<S156>/Constant2'
     *  RelationalOperator: '<S156>/GreaterThan'
     */
    if (rtb_Switch1_n < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S139>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S139>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    /* End of Switch: '<S156>/Switch1' */

    /* Merge: '<S139>/Merge3' incorporates:
     *  Gain: '<S166>/Gain1'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_Switch_cn;

    /* Trigonometry: '<S169>/Atan1' incorporates:
     *  Constant: '<S169>/Constant'
     *  Constant: '<S169>/Constant1'
     *  Sum: '<S169>/Subtract3'
     *  Sum: '<S169>/Subtract4'
     */
    rtb_Switch_cn = rt_atan2d_snf(1.0 - Robot_Control_B.KF_Position_Y, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S169>/Mod' incorporates:
     *  Constant: '<S169>/Constant4'
     */
    rtb_Switch2_dh = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Sum: '<S169>/Subtract2' incorporates:
     *  Constant: '<S157>/Constant10'
     *  Sum: '<S169>/Subtract8'
     */
    rtb_Switch1_k = Field_Length - Robot_Control_B.KF_Position_X;

    /* Trigonometry: '<S169>/Atan2' incorporates:
     *  Constant: '<S169>/Constant2'
     *  Sum: '<S169>/Subtract1'
     *  Sum: '<S169>/Subtract2'
     */
    rtb_Switch_cn = rt_atan2d_snf(1.0 - Robot_Control_B.KF_Position_Y,
      rtb_Switch1_k);

    /* Math: '<S169>/Mod1' incorporates:
     *  Constant: '<S169>/Constant5'
     */
    rtb_Init_o = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Sum: '<S169>/Subtract5' incorporates:
     *  Constant: '<S157>/Constant11'
     *  Sum: '<S169>/Subtract7'
     */
    rtb_Switch2_i = Field_Width_Pass - Robot_Control_B.KF_Position_Y;

    /* Trigonometry: '<S169>/Atan3' incorporates:
     *  Constant: '<S169>/Constant3'
     *  Sum: '<S169>/Subtract5'
     *  Sum: '<S169>/Subtract6'
     */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch2_i, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S169>/Mod2' incorporates:
     *  Constant: '<S169>/Constant6'
     */
    rtb_Switch2_g = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Trigonometry: '<S169>/Atan4' */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch2_i, rtb_Switch1_k);

    /* Math: '<S169>/Mod3' incorporates:
     *  Constant: '<S169>/Constant7'
     */
    rtb_Switch1_k = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Merge: '<S139>/Merge' incorporates:
     *  Constant: '<S173>/Constant'
     *  Constant: '<S173>/Shooter Assembly Offset in Robot'
     *  Constant: '<S173>/Shooter Assembly Offset in Robot1'
     *  Gain: '<S177>/Gain1'
     *  MinMax: '<S173>/Max'
     *  Product: '<S173>/Divide'
     *  Sum: '<S173>/Add'
     *  Sum: '<S173>/Subtract1'
     *  Sum: '<S173>/Subtract2'
     *  Trigonometry: '<S173>/Atan2'
     *  Trigonometry: '<S173>/Tanh1'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = (rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      atan(-0.074675999999999992 / fmax(Robot_Control_B.RB_Desired_Shot_Distance,
      0.001))) + (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);

    /* Switch: '<S172>/Switch1' incorporates:
     *  Constant: '<S157>/Constant3'
     *  Constant: '<S157>/Constant7'
     *  Inport: '<Root>/IsBlueAlliance'
     */
    if (Robot_Control_U.IsBlueAlliance > 0.0) {
      rtb_Switch_cn = Blue_Hub_LeftY;
    } else {
      rtb_Switch_cn = Red_Hub_LeftY;
    }

    /* End of Switch: '<S172>/Switch1' */

    /* Sum: '<S170>/Subtract3' */
    rtb_Switch2_i = rtb_Switch_cn - Robot_Control_B.KF_Position_Y;

    /* Switch: '<S172>/Switch' incorporates:
     *  Constant: '<S157>/Constant2'
     *  Constant: '<S157>/Constant4'
     *  Constant: '<S157>/Constant5'
     *  Constant: '<S157>/Constant6'
     *  Constant: '<S157>/Constant8'
     *  Constant: '<S157>/Constant9'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Switch: '<S172>/Switch2'
     *  Switch: '<S172>/Switch3'
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

    /* End of Switch: '<S172>/Switch' */

    /* Math: '<S170>/Mod1' incorporates:
     *  Constant: '<S170>/Constant'
     *  Sum: '<S170>/Subtract4'
     *  Trigonometry: '<S170>/Atan1'
     */
    rtb_Switch_cn = rt_modd_snf(rt_atan2d_snf(rtb_Switch2_i, rtb_Switch_cn -
      Robot_Control_B.KF_Position_X), 6.2831853071795862);

    /* Math: '<S170>/Mod2' incorporates:
     *  Constant: '<S170>/Constant1'
     *  Sum: '<S170>/Subtract1'
     *  Sum: '<S170>/Subtract2'
     *  Switch: '<S172>/Switch2'
     *  Switch: '<S172>/Switch3'
     *  Trigonometry: '<S170>/Atan3'
     */
    rtb_Switch2_i = rt_modd_snf(rt_atan2d_snf(rtb_Minus_k_idx_1 -
      Robot_Control_B.KF_Position_Y, rtb_Add_i - Robot_Control_B.KF_Position_X),
      6.2831853071795862);

    /* Switch: '<S170>/Switch' incorporates:
     *  Abs: '<S170>/Abs'
     *  Abs: '<S170>/Abs1'
     *  RelationalOperator: '<S170>/GreaterThan'
     */
    if (!(rtb_Switch_cn < rtb_Switch2_i)) {
      /* Abs: '<S157>/Abs1' */
      rtb_Switch_cn = rtb_Switch2_i;
    }

    /* End of Switch: '<S170>/Switch' */

    /* Math: '<S157>/Math Function' incorporates:
     *  Constant: '<S157>/Constant1'
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Switch2_i = rt_modd_snf(Robot_Control_U.Gyro_Angle_Field_rad,
      6.2831853071795862);

    /* If: '<S171>/If' incorporates:
     *  Switch: '<S176>/Switch'
     */
    if (Robot_Control_B.RB_Desired_Target_Y > 4.0345) {
      /* Outputs for IfAction SubSystem: '<S171>/If Action Subsystem' incorporates:
       *  ActionPort: '<S175>/Action Port'
       */
      /* Switch: '<S175>/Switch' */
      if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
        /* Abs: '<S157>/Abs' */
        rtb_Switch2_dh = rtb_Switch1_k;
      } else {
        /* Abs: '<S157>/Abs' */
        rtb_Switch2_dh = rtb_Switch2_g;
      }

      /* End of Switch: '<S175>/Switch' */
      /* End of Outputs for SubSystem: '<S171>/If Action Subsystem' */

      /* Outputs for IfAction SubSystem: '<S171>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
    } else if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
      /* Switch: '<S176>/Switch' incorporates:
       *  Abs: '<S157>/Abs'
       */
      rtb_Switch2_dh = rtb_Init_o;

      /* End of Outputs for SubSystem: '<S171>/If Action Subsystem1' */
    }

    /* End of If: '<S171>/If' */

    /* Switch: '<S174>/Switch' incorporates:
     *  Logic: '<S174>/AND'
     *  Logic: '<S174>/AND1'
     *  RelationalOperator: '<S174>/GreaterThan'
     *  RelationalOperator: '<S174>/GreaterThan1'
     *  RelationalOperator: '<S174>/GreaterThan2'
     *  RelationalOperator: '<S174>/GreaterThan3'
     *  RelationalOperator: '<S174>/GreaterThan4'
     */
    if (rtb_Switch2_dh < rtb_Switch_cn) {
      rtb_Compare_mq = ((rtb_Switch2_i > rtb_Switch2_dh) && (rtb_Switch2_i <
        rtb_Switch_cn));
    } else {
      rtb_Compare_mq = ((rtb_Switch2_i > rtb_Switch_cn) && (rtb_Switch2_i <
        rtb_Switch2_dh));
    }

    /* Merge: '<S139>/Merge4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S157>/AND'
     *  Logic: '<S174>/Logical Operator'
     *  Switch: '<S174>/Switch'
     */
    Robot_Control_B.Can_Pass = (rtb_Compare_ky &&
      ((Robot_Control_U.IsBlueAlliance != 0.0) == ((int32_T)rtb_Compare_mq)));

    /* Update for UnitDelay: '<S156>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S139>/Desired Shooting Parameters Math' */
  } else {
    /* Outputs for IfAction SubSystem: '<S139>/Shooter Not Active' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    /* Merge: '<S139>/Merge' incorporates:
     *  Constant: '<S151>/Constant2'
     *  SignalConversion generated from: '<S151>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;

    /* Merge: '<S139>/Merge1' incorporates:
     *  Constant: '<S151>/Constant'
     *  SignalConversion generated from: '<S151>/Desired_Shooter_Speed'
     */
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;

    /* Merge: '<S139>/Merge2' incorporates:
     *  Constant: '<S151>/Constant3'
     *  SignalConversion generated from: '<S151>/Desired_Hood_Pos'
     */
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;

    /* Merge: '<S139>/Merge3' incorporates:
     *  Constant: '<S151>/Constant1'
     *  SignalConversion generated from: '<S151>/Allowed_Shoot_Gyro_Error_rad'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* Merge: '<S139>/Merge4' incorporates:
     *  Constant: '<S151>/Constant4'
     *  SignalConversion generated from: '<S151>/Can_Pass'
     */
    Robot_Control_B.Can_Pass = true;

    /* End of Outputs for SubSystem: '<S139>/Shooter Not Active' */
  }

  /* End of If: '<S139>/If' */

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

  /* Sum: '<S396>/Add1' incorporates:
   *  Constant: '<S396>/Constant3'
   *  Constant: '<S396>/Constant4'
   *  Math: '<S396>/Math Function'
   *  Sum: '<S395>/Sum'
   *  Sum: '<S396>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf((rtb_Minus_k_idx_1 - rtb_Add_i) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Gain: '<S399>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle;

  /* Abs: '<S378>/Abs1' */
  rtb_Init_o = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S398>/Sum1' incorporates:
   *  Constant: '<S395>/Constant2'
   *  Product: '<S398>/Product'
   *  Sum: '<S398>/Sum'
   *  UnitDelay: '<S398>/Unit Delay1'
   */
  rtb_Switch_cn = ((rtb_Optimized_Module_Angle -
                    Robot_Control_DW.UnitDelay1_DSTATE) *
                   Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S395>/Product' incorporates:
   *  Constant: '<S395>/Constant3'
   */
  rtb_Switch1_n = rtb_Switch_cn * Steering_Heading_Control_D;

  /* Sum: '<S397>/Diff' incorporates:
   *  UnitDelay: '<S397>/UD'
   *
   * Block description for '<S397>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S397>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Switch1_n - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S395>/Saturation' */
  if (rtb_Add_mw > Steering_Heading_Control_D_UL) {
    rtb_Add_mw = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Heading_Control_D_LL) {
    rtb_Add_mw = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S395>/Add' incorporates:
   *  Gain: '<S395>/Gain1'
   *  Saturate: '<S395>/Saturation'
   */
  rtb_Switch1_k = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle) +
    rtb_Add_mw;

  /* Sum: '<S395>/Subtract' incorporates:
   *  Constant: '<S395>/Constant'
   */
  rtb_Switch2_g = Steering_Heading_Control_Total_UL - rtb_Switch1_k;

  /* Sum: '<S395>/Sum2' incorporates:
   *  Gain: '<S395>/Gain2'
   *  UnitDelay: '<S395>/Unit Delay'
   */
  rtb_Switch2_dh = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S400>/Switch2' incorporates:
   *  RelationalOperator: '<S400>/LowerRelop1'
   */
  if (!(rtb_Switch2_dh > rtb_Switch2_g)) {
    /* Sum: '<S395>/Subtract1' incorporates:
     *  Constant: '<S395>/Constant1'
     */
    rtb_Switch2_g = Steering_Heading_Control_Total_LL - rtb_Switch1_k;

    /* Switch: '<S400>/Switch' incorporates:
     *  RelationalOperator: '<S400>/UpperRelop'
     */
    if (!(rtb_Switch2_dh < rtb_Switch2_g)) {
      rtb_Switch2_g = rtb_Switch2_dh;
    }

    /* End of Switch: '<S400>/Switch' */
  }

  /* End of Switch: '<S400>/Switch2' */

  /* Saturate: '<S395>/Saturation1' */
  if (rtb_Switch2_g > Steering_Heading_Control_I_UL) {
    rtb_Switch2_dh = Steering_Heading_Control_I_UL;
  } else if (rtb_Switch2_g < Steering_Heading_Control_I_LL) {
    rtb_Switch2_dh = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch2_dh = rtb_Switch2_g;
  }

  /* End of Saturate: '<S395>/Saturation1' */

  /* Sum: '<S395>/Add1' */
  rtb_Add_mw = rtb_Switch1_k + rtb_Switch2_dh;

  /* Saturate: '<S395>/Saturation2' */
  if (rtb_Add_mw > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S395>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_mw < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S395>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S395>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_mw;
  }

  /* End of Saturate: '<S395>/Saturation2' */

  /* Abs: '<S378>/Abs' */
  rtb_Switch2_g = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S378>/Add dither' */
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

  /* End of Chart: '<S378>/Add dither' */

  /* Switch: '<S378>/Switch' incorporates:
   *  Constant: '<S378>/Constant'
   *  Constant: '<S394>/Constant'
   *  Product: '<S378>/Product'
   *  RelationalOperator: '<S394>/Compare'
   *  Signum: '<S378>/Sign'
   */
  if (rtb_Switch2_g > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S378>/Sign' */
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

  /* End of Switch: '<S378>/Switch' */

  /* Signum: '<S377>/Sign2' incorporates:
   *  UnitDelay: '<S377>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S377>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Add_i = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (rtb_Optimized_Module_Angle > 0.0);
  }

  /* Product: '<S377>/Product1' incorporates:
   *  Signum: '<S377>/Sign1'
   *  Signum: '<S377>/Sign2'
   */
  rtb_Minus_k_idx_1 *= rtb_Add_i;
  if (rtIsNaN(rtb_Minus_k_idx_1)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_k_idx_1, 256.0);
  }

  /* Switch: '<S377>/Switch' incorporates:
   *  Constant: '<S377>/Constant'
   *  Constant: '<S386>/Constant'
   *  Constant: '<S387>/Constant'
   *  Logic: '<S377>/or'
   *  Product: '<S377>/Product1'
   *  RelationalOperator: '<S386>/Compare'
   *  RelationalOperator: '<S387>/Compare'
   *  UnitDelay: '<S377>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Saturation_h = rtb_Optimized_Module_Angle;
  } else {
    rtb_Saturation_h = 0.0;
  }

  /* End of Switch: '<S377>/Switch' */

  /* Switch: '<S392>/Init' incorporates:
   *  UnitDelay: '<S392>/FixPt Unit Delay1'
   *  UnitDelay: '<S392>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Saturation_h;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S392>/Init' */

  /* RelationalOperator: '<S388>/Compare' incorporates:
   *  Constant: '<S388>/Constant'
   */
  rtb_Compare_ky = (rtb_Saturation_h == 0.0);

  /* RelationalOperator: '<S389>/Compare' incorporates:
   *  Constant: '<S389>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Saturation_h > 0.0);

  /* Abs: '<S377>/Abs' incorporates:
   *  Sum: '<S377>/Subtract'
   *  UnitDelay: '<S377>/Unit Delay'
   */
  rtb_Switch2_g = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                       rtb_Optimized_Module_Angle);

  /* Switch: '<S377>/Switch5' incorporates:
   *  Constant: '<S377>/Constant1'
   *  Switch: '<S377>/Switch1'
   *  UnaryMinus: '<S377>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    /* SignalConversion generated from: '<S377>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S377>/Constant4'
     *  Constant: '<S377>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S377>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S377>/Constant2'
     *  Constant: '<S377>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S377>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S377>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S377>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S377>/Constant10'
     *  Constant: '<S377>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S377>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S377>/Constant7'
     *  Constant: '<S377>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S377>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S377>/Lookup Table Dynamic1'
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

    /* Switch: '<S377>/Switch3' incorporates:
     *  Constant: '<S377>/Constant1'
     *  Constant: '<S377>/Constant3'
     *  UnaryMinus: '<S377>/Unary Minus'
     */
    if (rtb_LogicalOperator1) {
      rtb_Minus_k_idx_1 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Minus_k_idx_1 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S377>/Switch3' */
  }

  /* End of Switch: '<S377>/Switch5' */

  /* Product: '<S377>/Product' incorporates:
   *  Switch: '<S377>/Switch1'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_1 * rtb_Switch2_g;

  /* Sum: '<S390>/Sum1' */
  rtb_Switch1_k = rtb_Saturation_h - rtb_Init_o;

  /* Switch: '<S391>/Switch2' incorporates:
   *  RelationalOperator: '<S391>/LowerRelop1'
   */
  if (!(rtb_Switch1_k > rtb_MatrixConcatenate_b_idx_0)) {
    /* Switch: '<S377>/Switch2' incorporates:
     *  Constant: '<S377>/Constant1'
     *  Constant: '<S377>/Constant3'
     *  Switch: '<S377>/Switch4'
     *  UnaryMinus: '<S377>/Unary Minus1'
     */
    if (rtb_Compare_ky) {
      rtb_Minus_k_idx_1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S377>/Switch4' incorporates:
       *  Constant: '<S377>/Constant1'
       */
      rtb_Minus_k_idx_1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Minus_k_idx_1 = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S377>/Product2' incorporates:
     *  Switch: '<S377>/Switch2'
     */
    rtb_Switch2_i = rtb_Minus_k_idx_1 * rtb_Switch2_g;

    /* Switch: '<S391>/Switch' incorporates:
     *  RelationalOperator: '<S391>/UpperRelop'
     */
    if (rtb_Switch1_k < rtb_Switch2_i) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_i;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_k;
    }

    /* End of Switch: '<S391>/Switch' */
  }

  /* End of Switch: '<S391>/Switch2' */

  /* Sum: '<S390>/Sum' */
  rtb_Init_o += rtb_MatrixConcatenate_b_idx_0;

  /* Signum: '<S376>/Sign2' incorporates:
   *  UnitDelay: '<S376>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S376>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S376>/Product1' incorporates:
   *  Signum: '<S376>/Sign1'
   *  Signum: '<S376>/Sign2'
   */
  rtb_Minus_k_idx_1 *= rtb_Add_i;
  if (rtIsNaN(rtb_Minus_k_idx_1)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_k_idx_1, 256.0);
  }

  /* Switch: '<S376>/Switch' incorporates:
   *  Constant: '<S376>/Constant'
   *  Constant: '<S379>/Constant'
   *  Constant: '<S380>/Constant'
   *  Logic: '<S376>/or'
   *  Product: '<S376>/Product1'
   *  RelationalOperator: '<S379>/Compare'
   *  RelationalOperator: '<S380>/Compare'
   *  UnitDelay: '<S376>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Saturation_h = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Saturation_h = 0.0;
  }

  /* End of Switch: '<S376>/Switch' */

  /* Switch: '<S385>/Init' incorporates:
   *  UnitDelay: '<S385>/FixPt Unit Delay1'
   *  UnitDelay: '<S385>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle = rtb_Saturation_h;
  } else {
    rtb_Optimized_Module_Angle = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S385>/Init' */

  /* RelationalOperator: '<S381>/Compare' incorporates:
   *  Constant: '<S381>/Constant'
   */
  rtb_Compare_ky = (rtb_Saturation_h == 0.0);

  /* RelationalOperator: '<S382>/Compare' incorporates:
   *  Constant: '<S382>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Saturation_h > 0.0);

  /* Abs: '<S376>/Abs' incorporates:
   *  Sum: '<S376>/Subtract'
   *  UnitDelay: '<S376>/Unit Delay'
   */
  rtb_Switch1_k = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                       Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S376>/Switch1' incorporates:
   *  Constant: '<S376>/Constant1'
   *  Switch: '<S376>/Switch3'
   *  Switch: '<S376>/Switch5'
   *  UnaryMinus: '<S376>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    rtb_Switch2_g = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S376>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S376>/Constant1'
     *  Constant: '<S376>/Constant4'
     *  Constant: '<S376>/Constant6'
     *  UnaryMinus: '<S376>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S376>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S376>/Constant2'
     *  Constant: '<S376>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S376>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S376>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_Switch1_k, &rtb_Minus_n[0], 1U);
    rtb_Switch1_k = rtb_LookupTableDynamic_p;
  } else {
    if (rtb_LogicalOperator1) {
      /* Switch: '<S376>/Switch3' incorporates:
       *  Constant: '<S376>/Constant3'
       */
      rtb_Switch2_g = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Switch2_g = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S376>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S376>/Constant1'
     *  Constant: '<S376>/Constant10'
     *  Constant: '<S376>/Constant8'
     *  UnaryMinus: '<S376>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S376>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S376>/Constant7'
     *  Constant: '<S376>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S376>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S376>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_Switch1_k, &rtb_Minus_n[0], 1U);
    rtb_Switch1_k = rtb_LookupTableDynamic1_g;
  }

  /* End of Switch: '<S376>/Switch1' */

  /* Product: '<S376>/Product' */
  rtb_Switch2_g *= rtb_Switch1_k;

  /* Sum: '<S383>/Sum1' */
  rtb_Switch2_i = rtb_Saturation_h - rtb_Optimized_Module_Angle;

  /* Switch: '<S384>/Switch2' incorporates:
   *  RelationalOperator: '<S384>/LowerRelop1'
   */
  if (!(rtb_Switch2_i > rtb_Switch2_g)) {
    /* Switch: '<S376>/Switch2' incorporates:
     *  Constant: '<S376>/Constant1'
     *  Switch: '<S376>/Switch4'
     */
    if (rtb_Compare_ky) {
      rtb_Switch2_g = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S376>/Switch4' incorporates:
       *  Constant: '<S376>/Constant1'
       */
      rtb_Switch2_g = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S376>/Switch4' incorporates:
       *  Constant: '<S376>/Constant3'
       *  UnaryMinus: '<S376>/Unary Minus1'
       */
      rtb_Switch2_g = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S376>/Switch2' */

    /* Product: '<S376>/Product2' */
    rtb_Switch2_g *= rtb_Switch1_k;

    /* Switch: '<S384>/Switch' incorporates:
     *  RelationalOperator: '<S384>/UpperRelop'
     */
    if (!(rtb_Switch2_i < rtb_Switch2_g)) {
      rtb_Switch2_g = rtb_Switch2_i;
    }

    /* End of Switch: '<S384>/Switch' */
  }

  /* End of Switch: '<S384>/Switch2' */

  /* Sum: '<S383>/Sum' */
  rtb_Switch2_g += rtb_Optimized_Module_Angle;

  /* Switch: '<S366>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (rtb_Button_Spinup_Enable || (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S366>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S366>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch2_g;
  }

  /* End of Switch: '<S366>/Switch' */

  /* Fcn: '<S409>/r->x' incorporates:
   *  Fcn: '<S414>/r->x'
   *  Fcn: '<S419>/r->x'
   *  Fcn: '<S424>/r->x'
   */
  rtb_Switch2_i = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S403>/Add' incorporates:
   *  Fcn: '<S409>/r->x'
   *  Fcn: '<S410>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2_i;

  /* Fcn: '<S409>/theta->y' incorporates:
   *  Fcn: '<S414>/theta->y'
   *  Fcn: '<S419>/theta->y'
   *  Fcn: '<S424>/theta->y'
   */
  rtb_Switch1_k = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S403>/Add' incorporates:
   *  Fcn: '<S409>/theta->y'
   *  Fcn: '<S410>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1_k;

  /* Sum: '<S404>/Add' incorporates:
   *  Fcn: '<S415>/r->x'
   *  Fcn: '<S415>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2_i;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1_k;

  /* Sum: '<S405>/Add' incorporates:
   *  Fcn: '<S420>/r->x'
   *  Fcn: '<S420>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2_i;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1_k;

  /* Sum: '<S406>/Add' incorporates:
   *  Fcn: '<S425>/r->x'
   *  Fcn: '<S425>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2_i;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1_k;

  /* Fcn: '<S423>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_k_idx_0,
    rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S426>/Compare' incorporates:
   *  Constant: '<S426>/Constant'
   */
  rtb_Compare_pb = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S422>/Switch1' */
  if (rtb_Compare_pb) {
    /* Switch: '<S422>/Switch1' incorporates:
     *  Constant: '<S422>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S422>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S422>/Switch1' */

  /* Fcn: '<S408>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S411>/Compare' incorporates:
   *  Constant: '<S411>/Constant'
   */
  rtb_Compare_mq = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S407>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S407>/Switch1' incorporates:
     *  Constant: '<S407>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S407>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S407>/Switch1' */

  /* Fcn: '<S413>/x->r' */
  rtb_Saturation_h = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S416>/Compare' incorporates:
   *  Constant: '<S416>/Constant'
   */
  rtb_Compare_ky = (rtb_Saturation_h == 0.0);

  /* Switch: '<S412>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S412>/Switch1' incorporates:
     *  Constant: '<S412>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S412>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Saturation_h;
  }

  /* End of Switch: '<S412>/Switch1' */

  /* Fcn: '<S418>/x->r' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S421>/Compare' incorporates:
   *  Constant: '<S421>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Optimized_Module_Angle == 0.0);

  /* Switch: '<S417>/Switch1' */
  if (rtb_LogicalOperator1) {
    /* Switch: '<S417>/Switch1' incorporates:
     *  Constant: '<S417>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S417>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle;
  }

  /* End of Switch: '<S417>/Switch1' */

  /* Product: '<S402>/Divide' incorporates:
   *  Abs: '<S402>/Abs'
   *  Abs: '<S402>/Abs1'
   *  Abs: '<S402>/Abs2'
   *  Abs: '<S402>/Abs3'
   *  Constant: '<S402>/Constant'
   *  MinMax: '<S402>/Max'
   */
  rtb_MatrixConcatenate_b_idx_0 = 5.3690930669470935 / fmax(fmax(fmax(fmax
    (5.3690930669470935, Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S402>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S422>/Switch' */
  if (!rtb_Compare_pb) {
    /* Switch: '<S422>/Switch' incorporates:
     *  Fcn: '<S423>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S422>/Switch' */

  /* Trigonometry: '<S356>/Cos4' incorporates:
   *  Switch: '<S345>/Angle_Switch'
   *  Trigonometry: '<S355>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S356>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S354>/Unary Minus'
   */
  rtb_Minus_k_idx_0 = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S356>/Sin4' incorporates:
   *  Switch: '<S345>/Angle_Switch'
   *  Trigonometry: '<S355>/Sin4'
   */
  rtb_Subtract_kb = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S356>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S354>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S356>/Subtract1' incorporates:
   *  Product: '<S356>/Product2'
   *  Product: '<S356>/Product3'
   *  Trigonometry: '<S356>/Cos4'
   *  Trigonometry: '<S356>/Sin4'
   */
  rtb_Switch1_k = (rtb_MatrixConcatenate_idx_0 * rtb_Minus_k_idx_0) +
    (rtb_Subtract_kb * rtb_Optimized_Module_Angle);

  /* Sum: '<S356>/Subtract' incorporates:
   *  Product: '<S356>/Product'
   *  Product: '<S356>/Product1'
   *  Trigonometry: '<S356>/Cos4'
   *  Trigonometry: '<S356>/Sin4'
   */
  rtb_Switch2_i = (rtb_MatrixConcatenate_idx_0 * rtb_Optimized_Module_Angle) -
    (rtb_Subtract_kb * rtb_Minus_k_idx_0);

  /* Math: '<S356>/Hypot' */
  rtb_Hypot_pi = rt_hypotd_snf(rtb_Switch2_i, rtb_Switch1_k);

  /* Switch: '<S356>/Switch' incorporates:
   *  Constant: '<S356>/Constant'
   *  Constant: '<S356>/Constant1'
   *  Constant: '<S357>/Constant'
   *  Product: '<S356>/Divide'
   *  Product: '<S356>/Divide1'
   *  RelationalOperator: '<S357>/Compare'
   *  Switch: '<S356>/Switch1'
   */
  if (rtb_Hypot_pi > 1.0E-6) {
    rtb_Saturation_h = rtb_Switch1_k / rtb_Hypot_pi;
    rtb_Optimized_Module_Angle = rtb_Switch2_i / rtb_Hypot_pi;
  } else {
    rtb_Saturation_h = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S356>/Switch' */

  /* Switch: '<S345>/Speed_Switch' incorporates:
   *  Abs: '<S345>/Abs'
   *  Constant: '<S353>/Constant'
   *  RelationalOperator: '<S353>/Compare'
   *  Switch: '<S345>/Angle_Switch'
   *  Trigonometry: '<S355>/Atan1'
   *  Trigonometry: '<S356>/Atan1'
   *  UnaryMinus: '<S345>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Saturation_h, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Minus_k_idx_1 = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S355>/Subtract1' incorporates:
     *  Product: '<S355>/Product2'
     *  Product: '<S355>/Product3'
     *  UnaryMinus: '<S345>/Unary Minus'
     */
    rtb_Switch1_k = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Sin5_c)
      + (rtb_Subtract_kb * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S355>/Subtract' incorporates:
     *  Product: '<S355>/Product'
     *  Product: '<S355>/Product1'
     */
    rtb_Hypot_pi = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Cos5_b) -
      (rtb_Subtract_kb * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S355>/Hypot' */
    rtb_Switch2_i = rt_hypotd_snf(rtb_Hypot_pi, rtb_Switch1_k);

    /* Switch: '<S355>/Switch1' incorporates:
     *  Constant: '<S355>/Constant'
     *  Constant: '<S355>/Constant1'
     *  Constant: '<S358>/Constant'
     *  Product: '<S355>/Divide'
     *  Product: '<S355>/Divide1'
     *  RelationalOperator: '<S358>/Compare'
     *  Switch: '<S355>/Switch'
     */
    if (rtb_Switch2_i > 1.0E-6) {
      rtb_Hypot_pi /= rtb_Switch2_i;
      rtb_Switch1_k /= rtb_Switch2_i;
    } else {
      rtb_Hypot_pi = 1.0;
      rtb_Switch1_k = 0.0;
    }

    /* End of Switch: '<S355>/Switch1' */
    rtb_Minus_k_idx_0 = rt_atan2d_snf(rtb_Switch1_k, rtb_Hypot_pi);
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Minus_k_idx_0 = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S348>/Product2' incorporates:
   *  Constant: '<S348>/Constant'
   *  Switch: '<S345>/Speed_Switch'
   */
  rtb_Saturation_h = rtb_Minus_k_idx_1 * 1154.7574092481445;

  /* Signum: '<S343>/Sign' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S343>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S346>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S347>/Sum'
   */
  rtb_Integral_c3 = rtb_Minus_k_idx_0 - Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S278>/Product' incorporates:
   *  Abs: '<S343>/Abs'
   *  Abs: '<S346>/Abs'
   *  Constant: '<S349>/Constant'
   *  Constant: '<S359>/Constant3'
   *  Constant: '<S359>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S343>/OR'
   *  Lookup_n-D: '<S346>/1-D Lookup Table'
   *  Math: '<S359>/Math Function'
   *  RelationalOperator: '<S343>/Equal1'
   *  RelationalOperator: '<S349>/Compare'
   *  Signum: '<S343>/Sign'
   *  Signum: '<S343>/Sign1'
   *  Sum: '<S346>/Add'
   *  Sum: '<S359>/Add1'
   *  Sum: '<S359>/Add2'
   */
  rtb_Saturation_h = (((real_T)((rtb_Minus_k_idx_1 == rtb_Add_i) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Saturation_h) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_c3 + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData_g, 1U);

  /* Gain: '<S344>/Gain' */
  rtb_Hypot_pi = Drive_Motor_Control_FF * rtb_Saturation_h;

  /* Sum: '<S344>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Saturation_h -= Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S351>/Sum1' incorporates:
   *  Constant: '<S344>/Constant2'
   *  Product: '<S351>/Product'
   *  Sum: '<S351>/Sum'
   *  UnitDelay: '<S351>/Unit Delay1'
   */
  rtb_Switch1_k = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                   Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S344>/Product' incorporates:
   *  Constant: '<S344>/Constant3'
   */
  rtb_Switch2_i = rtb_Switch1_k * Drive_Motor_Control_D;

  /* Sum: '<S350>/Diff' incorporates:
   *  UnitDelay: '<S350>/UD'
   *
   * Block description for '<S350>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S350>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Switch2_i - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S344>/Saturation' */
  if (rtb_Add_mw > Drive_Motor_Control_D_UL) {
    rtb_Add_mw = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Drive_Motor_Control_D_LL) {
    rtb_Add_mw = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S344>/Add' incorporates:
   *  Gain: '<S344>/Gain1'
   *  Saturate: '<S344>/Saturation'
   */
  rtb_Add_mw += (Drive_Motor_Control_P * rtb_Saturation_h) + rtb_Hypot_pi;

  /* Saturate: '<S344>/Saturation2' */
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

  /* End of Saturate: '<S344>/Saturation2' */

  /* Sum: '<S360>/Add1' incorporates:
   *  Constant: '<S360>/Constant3'
   *  Constant: '<S360>/Constant4'
   *  Math: '<S360>/Math Function'
   *  Sum: '<S360>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Integral_c3 + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S362>/Sum1' incorporates:
   *  Constant: '<S347>/Constant2'
   *  Product: '<S362>/Product'
   *  Sum: '<S362>/Sum'
   *  UnitDelay: '<S362>/Unit Delay1'
   */
  rtb_Hypot_pi = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_i) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S347>/Product' incorporates:
   *  Constant: '<S347>/Constant3'
   */
  rtb_Product_d1 = rtb_Hypot_pi * Steering_Motor_Control_D;

  /* Sum: '<S361>/Diff' incorporates:
   *  UnitDelay: '<S361>/UD'
   *
   * Block description for '<S361>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S361>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Product_d1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S347>/Saturation' */
  if (rtb_Add_mw > Steering_Motor_Control_D_UL) {
    rtb_Add_mw = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Motor_Control_D_LL) {
    rtb_Add_mw = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S347>/Add' incorporates:
   *  Gain: '<S347>/Gain1'
   *  Saturate: '<S347>/Saturation'
   */
  rtb_Add_pw = (Steering_Motor_Control_P * rtb_Saturation_h) + rtb_Add_mw;

  /* Sum: '<S347>/Subtract' incorporates:
   *  Constant: '<S347>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_pw;

  /* Sum: '<S347>/Sum2' incorporates:
   *  Gain: '<S347>/Gain2'
   *  UnitDelay: '<S347>/Unit Delay'
   */
  rtb_Sum2_fc = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S363>/Switch2' incorporates:
   *  Constant: '<S347>/Constant'
   *  RelationalOperator: '<S363>/LowerRelop1'
   *  Sum: '<S347>/Subtract'
   */
  if (!(rtb_Sum2_fc > (1.0 - rtb_Add_pw))) {
    /* Switch: '<S363>/Switch' incorporates:
     *  Constant: '<S347>/Constant1'
     *  RelationalOperator: '<S363>/UpperRelop'
     *  Sum: '<S347>/Subtract1'
     */
    if (rtb_Sum2_fc < (-1.0 - rtb_Add_pw)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_pw;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_fc;
    }

    /* End of Switch: '<S363>/Switch' */
  }

  /* End of Switch: '<S363>/Switch2' */

  /* Saturate: '<S347>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S347>/Saturation1' */

  /* Sum: '<S347>/Add1' */
  rtb_Add_mw = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S347>/Saturation2' */
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

  /* End of Saturate: '<S347>/Saturation2' */

  /* Product: '<S402>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S407>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S407>/Switch' incorporates:
     *  Fcn: '<S408>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S407>/Switch' */

  /* Trigonometry: '<S293>/Cos4' incorporates:
   *  Switch: '<S282>/Angle_Switch'
   *  Trigonometry: '<S292>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S293>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S291>/Unary Minus'
   */
  rtb_Minus_k_idx_0 = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S293>/Sin4' incorporates:
   *  Switch: '<S282>/Angle_Switch'
   *  Trigonometry: '<S292>/Sin4'
   */
  rtb_Subtract_kb = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S293>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S291>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S293>/Subtract1' incorporates:
   *  Product: '<S293>/Product2'
   *  Product: '<S293>/Product3'
   *  Trigonometry: '<S293>/Cos4'
   *  Trigonometry: '<S293>/Sin4'
   */
  rtb_Add_pw = (rtb_MatrixConcatenate_idx_0 * rtb_Minus_k_idx_0) +
    (rtb_Subtract_kb * rtb_Optimized_Module_Angle);

  /* Sum: '<S293>/Subtract' incorporates:
   *  Product: '<S293>/Product'
   *  Product: '<S293>/Product1'
   *  Trigonometry: '<S293>/Cos4'
   *  Trigonometry: '<S293>/Sin4'
   */
  rtb_Subtract1_bm = (rtb_MatrixConcatenate_idx_0 * rtb_Optimized_Module_Angle)
    - (rtb_Subtract_kb * rtb_Minus_k_idx_0);

  /* Math: '<S293>/Hypot' */
  rtb_Hypot_fg = rt_hypotd_snf(rtb_Subtract1_bm, rtb_Add_pw);

  /* Switch: '<S293>/Switch' incorporates:
   *  Constant: '<S293>/Constant'
   *  Constant: '<S293>/Constant1'
   *  Constant: '<S294>/Constant'
   *  Product: '<S293>/Divide'
   *  Product: '<S293>/Divide1'
   *  RelationalOperator: '<S294>/Compare'
   *  Switch: '<S293>/Switch1'
   */
  if (rtb_Hypot_fg > 1.0E-6) {
    rtb_Saturation_h = rtb_Add_pw / rtb_Hypot_fg;
    rtb_Optimized_Module_Angle = rtb_Subtract1_bm / rtb_Hypot_fg;
  } else {
    rtb_Saturation_h = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S293>/Switch' */

  /* Switch: '<S282>/Speed_Switch' incorporates:
   *  Abs: '<S282>/Abs'
   *  Constant: '<S290>/Constant'
   *  RelationalOperator: '<S290>/Compare'
   *  Switch: '<S282>/Angle_Switch'
   *  Trigonometry: '<S292>/Atan1'
   *  Trigonometry: '<S293>/Atan1'
   *  UnaryMinus: '<S282>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Saturation_h, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Minus_k_idx_1 = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S292>/Subtract1' incorporates:
     *  Product: '<S292>/Product2'
     *  Product: '<S292>/Product3'
     *  UnaryMinus: '<S282>/Unary Minus'
     */
    rtb_Add_pw = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Sin5) +
      (rtb_Subtract_kb * Robot_Control_ConstB.Cos5);

    /* Sum: '<S292>/Subtract' incorporates:
     *  Product: '<S292>/Product'
     *  Product: '<S292>/Product1'
     */
    rtb_Hypot_fg = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Cos5) -
      (rtb_Subtract_kb * Robot_Control_ConstB.Sin5);

    /* Math: '<S292>/Hypot' */
    rtb_Subtract1_bm = rt_hypotd_snf(rtb_Hypot_fg, rtb_Add_pw);

    /* Switch: '<S292>/Switch1' incorporates:
     *  Constant: '<S292>/Constant'
     *  Constant: '<S292>/Constant1'
     *  Constant: '<S295>/Constant'
     *  Product: '<S292>/Divide'
     *  Product: '<S292>/Divide1'
     *  RelationalOperator: '<S295>/Compare'
     *  Switch: '<S292>/Switch'
     */
    if (rtb_Subtract1_bm > 1.0E-6) {
      rtb_Hypot_fg /= rtb_Subtract1_bm;
      rtb_Add_pw /= rtb_Subtract1_bm;
    } else {
      rtb_Hypot_fg = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S292>/Switch1' */
    rtb_Minus_k_idx_0 = rt_atan2d_snf(rtb_Add_pw, rtb_Hypot_fg);
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_Minus_k_idx_0 = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S285>/Product2' incorporates:
   *  Constant: '<S285>/Constant'
   *  Switch: '<S282>/Speed_Switch'
   */
  rtb_Saturation_h = rtb_Minus_k_idx_1 * 1154.7574092481445;

  /* Signum: '<S280>/Sign' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S280>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S283>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S284>/Sum'
   */
  rtb_Integral_c3 = rtb_Minus_k_idx_0 - Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S275>/Product' incorporates:
   *  Abs: '<S280>/Abs'
   *  Abs: '<S283>/Abs'
   *  Constant: '<S286>/Constant'
   *  Constant: '<S296>/Constant3'
   *  Constant: '<S296>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
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
  rtb_Saturation_h = (((real_T)((rtb_Minus_k_idx_1 == rtb_Add_i) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Saturation_h) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_c3 + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_h,
                  rtCP_uDLookupTable_tableData_j, 1U);

  /* Gain: '<S281>/Gain' */
  rtb_Hypot_fg = Drive_Motor_Control_FF * rtb_Saturation_h;

  /* Sum: '<S281>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Saturation_h -= Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S288>/Sum1' incorporates:
   *  Constant: '<S281>/Constant2'
   *  Product: '<S288>/Product'
   *  Sum: '<S288>/Sum'
   *  UnitDelay: '<S288>/Unit Delay1'
   */
  rtb_Add_pw = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S281>/Product' incorporates:
   *  Constant: '<S281>/Constant3'
   */
  rtb_Subtract1_bm = rtb_Add_pw * Drive_Motor_Control_D;

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
  rtb_Add_mw = rtb_Subtract1_bm - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S281>/Saturation' */
  if (rtb_Add_mw > Drive_Motor_Control_D_UL) {
    rtb_Add_mw = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Drive_Motor_Control_D_LL) {
    rtb_Add_mw = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S281>/Add' incorporates:
   *  Gain: '<S281>/Gain1'
   *  Saturate: '<S281>/Saturation'
   */
  rtb_Add_mw += (Drive_Motor_Control_P * rtb_Saturation_h) + rtb_Hypot_fg;

  /* Saturate: '<S281>/Saturation2' */
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

  /* End of Saturate: '<S281>/Saturation2' */

  /* Sum: '<S297>/Add1' incorporates:
   *  Constant: '<S297>/Constant3'
   *  Constant: '<S297>/Constant4'
   *  Math: '<S297>/Math Function'
   *  Sum: '<S297>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Integral_c3 + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S299>/Sum1' incorporates:
   *  Constant: '<S284>/Constant2'
   *  Product: '<S299>/Product'
   *  Sum: '<S299>/Sum'
   *  UnitDelay: '<S299>/Unit Delay1'
   */
  rtb_Hypot_fg = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S284>/Product' incorporates:
   *  Constant: '<S284>/Constant3'
   */
  rtb_Product_i3 = rtb_Hypot_fg * Steering_Motor_Control_D;

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
  rtb_Add_mw = rtb_Product_i3 - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S284>/Saturation' */
  if (rtb_Add_mw > Steering_Motor_Control_D_UL) {
    rtb_Add_mw = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Motor_Control_D_LL) {
    rtb_Add_mw = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S284>/Add' incorporates:
   *  Gain: '<S284>/Gain1'
   *  Saturate: '<S284>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P * rtb_Saturation_h) +
    rtb_Add_mw;

  /* Sum: '<S284>/Subtract' incorporates:
   *  Constant: '<S284>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S284>/Sum2' incorporates:
   *  Gain: '<S284>/Gain2'
   *  UnitDelay: '<S284>/Unit Delay'
   */
  rtb_Sum2_m = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S300>/Switch2' incorporates:
   *  Constant: '<S284>/Constant'
   *  RelationalOperator: '<S300>/LowerRelop1'
   *  Sum: '<S284>/Subtract'
   */
  if (!(rtb_Sum2_m > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S300>/Switch' incorporates:
     *  Constant: '<S284>/Constant1'
     *  RelationalOperator: '<S300>/UpperRelop'
     *  Sum: '<S284>/Subtract1'
     */
    if (rtb_Sum2_m < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_m;
    }

    /* End of Switch: '<S300>/Switch' */
  }

  /* End of Switch: '<S300>/Switch2' */

  /* Saturate: '<S284>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_m = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_m = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_m = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S284>/Saturation1' */

  /* Sum: '<S284>/Add1' */
  rtb_Add_mw = rtb_MatrixConcatenate_idx_0 + rtb_Sum2_m;

  /* Saturate: '<S284>/Saturation2' */
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

  /* End of Saturate: '<S284>/Saturation2' */

  /* Product: '<S402>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S412>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S412>/Switch' incorporates:
     *  Fcn: '<S413>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S412>/Switch' */

  /* Trigonometry: '<S314>/Cos4' incorporates:
   *  Switch: '<S303>/Angle_Switch'
   *  Trigonometry: '<S313>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S314>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S312>/Unary Minus'
   */
  rtb_Minus_k_idx_0 = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S314>/Sin4' incorporates:
   *  Switch: '<S303>/Angle_Switch'
   *  Trigonometry: '<S313>/Sin4'
   */
  rtb_Subtract_kb = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S314>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S312>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S314>/Subtract1' incorporates:
   *  Product: '<S314>/Product2'
   *  Product: '<S314>/Product3'
   *  Trigonometry: '<S314>/Cos4'
   *  Trigonometry: '<S314>/Sin4'
   */
  rtb_Saturation_h = (rtb_MatrixConcatenate_idx_0 * rtb_Minus_k_idx_0) +
    (rtb_Subtract_kb * rtb_Optimized_Module_Angle);

  /* Sum: '<S314>/Subtract' incorporates:
   *  Product: '<S314>/Product'
   *  Product: '<S314>/Product1'
   *  Trigonometry: '<S314>/Cos4'
   *  Trigonometry: '<S314>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_MatrixConcatenate_idx_0 * rtb_Optimized_Module_Angle)
    - (rtb_Subtract_kb * rtb_Minus_k_idx_0);

  /* Math: '<S314>/Hypot' */
  rtb_Hypot_a = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Saturation_h);

  /* Switch: '<S314>/Switch' incorporates:
   *  Constant: '<S314>/Constant'
   *  Constant: '<S314>/Constant1'
   *  Constant: '<S315>/Constant'
   *  Product: '<S314>/Divide'
   *  Product: '<S314>/Divide1'
   *  RelationalOperator: '<S315>/Compare'
   *  Switch: '<S314>/Switch1'
   */
  if (rtb_Hypot_a > 1.0E-6) {
    rtb_Saturation_h /= rtb_Hypot_a;
    rtb_Optimized_Module_Angle = rtb_Minus_k_idx_0 / rtb_Hypot_a;
  } else {
    rtb_Saturation_h = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S314>/Switch' */

  /* Switch: '<S303>/Speed_Switch' incorporates:
   *  Abs: '<S303>/Abs'
   *  Constant: '<S311>/Constant'
   *  RelationalOperator: '<S311>/Compare'
   *  Switch: '<S303>/Angle_Switch'
   *  Trigonometry: '<S313>/Atan1'
   *  Trigonometry: '<S314>/Atan1'
   *  UnaryMinus: '<S303>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Saturation_h, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Minus_k_idx_1 = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S313>/Subtract1' incorporates:
     *  Product: '<S313>/Product2'
     *  Product: '<S313>/Product3'
     *  UnaryMinus: '<S303>/Unary Minus'
     */
    rtb_Minus_k_idx_0 = (rtb_MatrixConcatenate_idx_0 *
                         Robot_Control_ConstB.Sin5_m) + (rtb_Subtract_kb *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S313>/Subtract' incorporates:
     *  Product: '<S313>/Product'
     *  Product: '<S313>/Product1'
     */
    rtb_Subtract_kb = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Cos5_g)
      - (rtb_Subtract_kb * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S313>/Hypot' */
    rtb_MatrixConcatenate_idx_0 = rt_hypotd_snf(rtb_Subtract_kb,
      rtb_Minus_k_idx_0);

    /* Switch: '<S313>/Switch1' incorporates:
     *  Constant: '<S313>/Constant'
     *  Constant: '<S313>/Constant1'
     *  Constant: '<S316>/Constant'
     *  Product: '<S313>/Divide'
     *  Product: '<S313>/Divide1'
     *  RelationalOperator: '<S316>/Compare'
     *  Switch: '<S313>/Switch'
     */
    if (rtb_MatrixConcatenate_idx_0 > 1.0E-6) {
      rtb_Subtract_kb /= rtb_MatrixConcatenate_idx_0;
      rtb_MatrixConcatenate_idx_0 = rtb_Minus_k_idx_0 /
        rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Subtract_kb = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S313>/Switch1' */
    rtb_Minus_k_idx_0 = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0,
      rtb_Subtract_kb);
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_Minus_k_idx_0 = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S306>/Product2' incorporates:
   *  Constant: '<S306>/Constant'
   *  Switch: '<S303>/Speed_Switch'
   */
  rtb_Saturation_h = rtb_Minus_k_idx_1 * 1154.7574092481445;

  /* Signum: '<S301>/Sign' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S301>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S304>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S305>/Sum'
   */
  rtb_Integral_c3 = rtb_Minus_k_idx_0 - Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S276>/Product' incorporates:
   *  Abs: '<S301>/Abs'
   *  Abs: '<S304>/Abs'
   *  Constant: '<S307>/Constant'
   *  Constant: '<S317>/Constant3'
   *  Constant: '<S317>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
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
  rtb_Saturation_h = (((real_T)((rtb_Minus_k_idx_1 == rtb_Add_i) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Saturation_h) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_c3 + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_p,
                  rtCP_uDLookupTable_tableData_gs, 1U);

  /* Gain: '<S302>/Gain' */
  rtb_Hypot_a = Drive_Motor_Control_FF * rtb_Saturation_h;

  /* Sum: '<S302>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Saturation_h -= Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S309>/Sum1' incorporates:
   *  Constant: '<S302>/Constant2'
   *  Product: '<S309>/Product'
   *  Sum: '<S309>/Sum'
   *  UnitDelay: '<S309>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Saturation_h -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S302>/Product' incorporates:
   *  Constant: '<S302>/Constant3'
   */
  rtb_Subtract_kb = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

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
  rtb_Add_mw = rtb_Subtract_kb - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S302>/Saturation' */
  if (rtb_Add_mw > Drive_Motor_Control_D_UL) {
    rtb_Add_mw = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Drive_Motor_Control_D_LL) {
    rtb_Add_mw = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S302>/Add' incorporates:
   *  Gain: '<S302>/Gain1'
   *  Saturate: '<S302>/Saturation'
   */
  rtb_Add_mw += (Drive_Motor_Control_P * rtb_Saturation_h) + rtb_Hypot_a;

  /* Saturate: '<S302>/Saturation2' */
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

  /* End of Saturate: '<S302>/Saturation2' */

  /* Sum: '<S318>/Add1' incorporates:
   *  Constant: '<S318>/Constant3'
   *  Constant: '<S318>/Constant4'
   *  Math: '<S318>/Math Function'
   *  Sum: '<S318>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Integral_c3 + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S320>/Sum1' incorporates:
   *  Constant: '<S305>/Constant2'
   *  Product: '<S320>/Product'
   *  Sum: '<S320>/Sum'
   *  UnitDelay: '<S320>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_n)
                       * Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S305>/Product' incorporates:
   *  Constant: '<S305>/Constant3'
   */
  rtb_Hypot_a = rtb_Minus_k_idx_0 * Steering_Motor_Control_D;

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
  rtb_Add_mw = rtb_Hypot_a - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S305>/Saturation' */
  if (rtb_Add_mw > Steering_Motor_Control_D_UL) {
    rtb_Add_mw = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Motor_Control_D_LL) {
    rtb_Add_mw = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S305>/Add' incorporates:
   *  Gain: '<S305>/Gain1'
   *  Saturate: '<S305>/Saturation'
   */
  rtb_Add_i = (Steering_Motor_Control_P * rtb_Saturation_h) + rtb_Add_mw;

  /* Sum: '<S305>/Subtract' incorporates:
   *  Constant: '<S305>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_i;

  /* Sum: '<S305>/Sum2' incorporates:
   *  Gain: '<S305>/Gain2'
   *  UnitDelay: '<S305>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S321>/Switch2' incorporates:
   *  Constant: '<S305>/Constant'
   *  RelationalOperator: '<S321>/LowerRelop1'
   *  Sum: '<S305>/Subtract'
   */
  if (!(rtb_Saturation_h > (1.0 - rtb_Add_i))) {
    /* Switch: '<S321>/Switch' incorporates:
     *  Constant: '<S305>/Constant1'
     *  RelationalOperator: '<S321>/UpperRelop'
     *  Sum: '<S305>/Subtract1'
     */
    if (rtb_Saturation_h < (-1.0 - rtb_Add_i)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_i;
    } else {
      rtb_Optimized_Module_Angle = rtb_Saturation_h;
    }

    /* End of Switch: '<S321>/Switch' */
  }

  /* End of Switch: '<S321>/Switch2' */

  /* Saturate: '<S305>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S305>/Saturation1' */

  /* Sum: '<S305>/Add1' */
  rtb_Add_mw = rtb_Add_i + rtb_Subtract1_kg;

  /* Saturate: '<S305>/Saturation2' */
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

  /* End of Saturate: '<S305>/Saturation2' */

  /* Product: '<S402>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S417>/Switch' */
  if (!rtb_LogicalOperator1) {
    /* Switch: '<S417>/Switch' incorporates:
     *  Fcn: '<S418>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S417>/Switch' */

  /* Trigonometry: '<S335>/Cos4' incorporates:
   *  Switch: '<S324>/Angle_Switch'
   *  Trigonometry: '<S334>/Cos4'
   */
  rtb_Add_i = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S335>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S333>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S335>/Sin4' incorporates:
   *  Switch: '<S324>/Angle_Switch'
   *  Trigonometry: '<S334>/Sin4'
   */
  rtb_Subtract_h = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S335>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S333>/Unary Minus'
   */
  rtb_Saturation_h = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S335>/Subtract1' incorporates:
   *  Product: '<S335>/Product2'
   *  Product: '<S335>/Product3'
   *  Trigonometry: '<S335>/Cos4'
   *  Trigonometry: '<S335>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Add_i * rtb_Optimized_Module_Angle) +
    (rtb_Subtract_h * rtb_Saturation_h);

  /* Sum: '<S335>/Subtract' incorporates:
   *  Product: '<S335>/Product'
   *  Product: '<S335>/Product1'
   *  Trigonometry: '<S335>/Cos4'
   *  Trigonometry: '<S335>/Sin4'
   */
  rtb_Saturation_h = (rtb_Add_i * rtb_Saturation_h) - (rtb_Subtract_h *
    rtb_Optimized_Module_Angle);

  /* Math: '<S335>/Hypot' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Saturation_h,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S335>/Switch' incorporates:
   *  Constant: '<S335>/Constant'
   *  Constant: '<S335>/Constant1'
   *  Constant: '<S336>/Constant'
   *  Product: '<S335>/Divide'
   *  Product: '<S335>/Divide1'
   *  RelationalOperator: '<S336>/Compare'
   *  Switch: '<S335>/Switch1'
   */
  if (rtb_Optimized_Module_Angle > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle;
    rtb_Saturation_h /= rtb_Optimized_Module_Angle;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Saturation_h = 1.0;
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
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Saturation_h)) >
      1.5707963267948966) {
    rtb_Minus_k_idx_1 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S334>/Subtract1' incorporates:
     *  Product: '<S334>/Product2'
     *  Product: '<S334>/Product3'
     *  UnaryMinus: '<S324>/Unary Minus'
     */
    rtb_Saturation_h = (rtb_Add_i * Robot_Control_ConstB.Sin5_e) +
      (rtb_Subtract_h * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S334>/Subtract' incorporates:
     *  Product: '<S334>/Product'
     *  Product: '<S334>/Product1'
     */
    rtb_Subtract_h = (rtb_Add_i * Robot_Control_ConstB.Cos5_i) - (rtb_Subtract_h
      * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S334>/Hypot' */
    rtb_Add_i = rt_hypotd_snf(rtb_Subtract_h, rtb_Saturation_h);

    /* Switch: '<S334>/Switch1' incorporates:
     *  Constant: '<S334>/Constant'
     *  Constant: '<S334>/Constant1'
     *  Constant: '<S337>/Constant'
     *  Product: '<S334>/Divide'
     *  Product: '<S334>/Divide1'
     *  RelationalOperator: '<S337>/Compare'
     *  Switch: '<S334>/Switch'
     */
    if (rtb_Add_i > 1.0E-6) {
      rtb_Subtract_h /= rtb_Add_i;
      rtb_Saturation_h /= rtb_Add_i;
    } else {
      rtb_Subtract_h = 1.0;
      rtb_Saturation_h = 0.0;
    }

    /* End of Switch: '<S334>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Saturation_h, rtb_Subtract_h);
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S327>/Product2' incorporates:
   *  Constant: '<S327>/Constant'
   *  Switch: '<S324>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_1 * 1154.7574092481445;

  /* Signum: '<S322>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S322>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S325>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S326>/Sum'
   */
  rtb_Optimized_Module_Angle -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S277>/Product' incorporates:
   *  Abs: '<S322>/Abs'
   *  Abs: '<S325>/Abs'
   *  Constant: '<S328>/Constant'
   *  Constant: '<S338>/Constant3'
   *  Constant: '<S338>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
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
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Minus_k_idx_1 == rtb_Add_i) ||
    (fabs(Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_j,
                    rtCP_uDLookupTable_tableData_h, 1U);

  /* Gain: '<S323>/Gain' */
  rtb_Saturation_h = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S323>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S330>/Sum1' incorporates:
   *  Constant: '<S323>/Constant2'
   *  Product: '<S330>/Product'
   *  Sum: '<S330>/Sum'
   *  UnitDelay: '<S330>/Unit Delay1'
   */
  rtb_Add_i = ((rtb_MatrixConcatenate_b_idx_0 -
                Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S323>/Product' incorporates:
   *  Constant: '<S323>/Constant3'
   */
  rtb_Subtract_h = rtb_Add_i * Drive_Motor_Control_D;

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
  rtb_Add_mw = rtb_Subtract_h - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S323>/Saturation' */
  if (rtb_Add_mw > Drive_Motor_Control_D_UL) {
    rtb_Add_mw = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Drive_Motor_Control_D_LL) {
    rtb_Add_mw = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S323>/Add' incorporates:
   *  Gain: '<S323>/Gain1'
   *  Saturate: '<S323>/Saturation'
   */
  rtb_Add_mw += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Saturation_h;

  /* Saturate: '<S323>/Saturation2' */
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

  /* End of Saturate: '<S323>/Saturation2' */

  /* Sum: '<S339>/Add1' incorporates:
   *  Constant: '<S339>/Constant3'
   *  Constant: '<S339>/Constant4'
   *  Math: '<S339>/Math Function'
   *  Sum: '<S339>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S341>/Sum1' incorporates:
   *  Constant: '<S326>/Constant2'
   *  Product: '<S341>/Product'
   *  Sum: '<S341>/Sum'
   *  UnitDelay: '<S341>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S326>/Product' incorporates:
   *  Constant: '<S326>/Constant3'
   */
  rtb_Product_nq = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

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
  rtb_Add_mw = rtb_Product_nq - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S326>/Saturation' */
  if (rtb_Add_mw > Steering_Motor_Control_D_UL) {
    rtb_Add_mw = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_mw < Steering_Motor_Control_D_LL) {
    rtb_Add_mw = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S326>/Add' incorporates:
   *  Gain: '<S326>/Gain1'
   *  Saturate: '<S326>/Saturation'
   */
  rtb_Add_lu = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_mw;

  /* Sum: '<S326>/Subtract' incorporates:
   *  Constant: '<S326>/Constant'
   */
  rtb_Saturation_h = 1.0 - rtb_Add_lu;

  /* Sum: '<S326>/Sum2' incorporates:
   *  Gain: '<S326>/Gain2'
   *  UnitDelay: '<S326>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S342>/Switch2' incorporates:
   *  Constant: '<S326>/Constant'
   *  RelationalOperator: '<S342>/LowerRelop1'
   *  Sum: '<S326>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_lu))) {
    /* Sum: '<S326>/Subtract1' incorporates:
     *  Constant: '<S326>/Constant1'
     */
    rtb_Saturation_h = -1.0 - rtb_Add_lu;

    /* Switch: '<S342>/Switch' incorporates:
     *  Constant: '<S326>/Constant1'
     *  RelationalOperator: '<S342>/UpperRelop'
     *  Sum: '<S326>/Subtract1'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_lu))) {
      rtb_Saturation_h = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S342>/Switch' */
  }

  /* End of Switch: '<S342>/Switch2' */

  /* Saturate: '<S326>/Saturation1' */
  if (rtb_Saturation_h > Steering_Motor_Control_I_UL) {
    rtb_Integral_g = Steering_Motor_Control_I_UL;
  } else if (rtb_Saturation_h < Steering_Motor_Control_I_LL) {
    rtb_Integral_g = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_g = rtb_Saturation_h;
  }

  /* End of Saturate: '<S326>/Saturation1' */

  /* Sum: '<S326>/Add1' */
  rtb_Add_mw = rtb_Add_lu + rtb_Integral_g;

  /* Saturate: '<S326>/Saturation2' */
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

  /* End of Saturate: '<S326>/Saturation2' */

  /* Sum: '<S210>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S149>/Subtract'
   */
  rtb_Integral_c3 = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S212>/Sum1' incorporates:
   *  Constant: '<S210>/Constant2'
   *  Product: '<S212>/Product'
   *  Sum: '<S210>/Sum'
   *  Sum: '<S212>/Sum'
   *  UnitDelay: '<S212>/Unit Delay1'
   */
  rtb_Add_lu = ((rtb_Integral_c3 - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S210>/Product' incorporates:
   *  Constant: '<S210>/Constant3'
   */
  rtb_Product_c2 = rtb_Add_lu * 0.0;

  /* Sum: '<S211>/Diff' incorporates:
   *  UnitDelay: '<S211>/UD'
   *
   * Block description for '<S211>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S211>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_mw = rtb_Product_c2 - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S210>/Saturation' */
  if (rtb_Add_mw > 0.1) {
    rtb_Add_mw = 0.1;
  } else if (rtb_Add_mw < -0.1) {
    rtb_Add_mw = -0.1;
  }

  /* Sum: '<S210>/Add' incorporates:
   *  Gain: '<S210>/Gain'
   *  Gain: '<S210>/Gain1'
   *  Saturate: '<S210>/Saturation'
   *  Sum: '<S210>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Transfer_Motor_Gain_FF *
    Robot_Control_B.RB_Desired_Transfer_Speed) + (Rebuilt_Transfer_Motor_Gain_P *
    rtb_Integral_c3)) + rtb_Add_mw;

  /* Logic: '<S149>/Logical Operator1' incorporates:
   *  Constant: '<S209>/Constant'
   *  RelationalOperator: '<S209>/Compare'
   */
  rtb_LogicalOperator1 = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S149>/Switch1' incorporates:
   *  Abs: '<S149>/Abs'
   *  Constant: '<S149>/Constant1'
   *  Constant: '<S149>/Constant2'
   *  Logic: '<S149>/Logical Operator'
   *  Logic: '<S149>/Logical Operator1'
   *  RelationalOperator: '<S149>/LessThan'
   *  UnitDelay: '<S149>/Unit Delay'
   */
  if ((fabs(rtb_Integral_c3) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_LogicalOperator1) {
    rtb_Compare_ky = true;
  } else {
    rtb_Compare_ky = (rtb_LogicalOperator1 &&
                      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S149>/Switch1' */

  /* Switch: '<S210>/Switch' incorporates:
   *  Constant: '<S210>/Constant4'
   */
  if (rtb_Compare_ky) {
    /* Sum: '<S210>/Sum2' incorporates:
     *  Gain: '<S210>/Gain2'
     *  Sum: '<S210>/Sum'
     *  UnitDelay: '<S210>/Unit Delay'
     */
    rtb_Saturation_h = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_c3) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S210>/Subtract' incorporates:
     *  Constant: '<S210>/Constant'
     */
    rtb_Integral_c3 = 1.0 - rtb_MatrixConcatenate_b_idx_0;

    /* Switch: '<S213>/Switch2' incorporates:
     *  Constant: '<S210>/Constant'
     *  RelationalOperator: '<S213>/LowerRelop1'
     *  Sum: '<S210>/Subtract'
     */
    if (!(rtb_Saturation_h > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S210>/Subtract1' incorporates:
       *  Constant: '<S210>/Constant1'
       */
      rtb_Integral_c3 = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S213>/Switch' incorporates:
       *  Constant: '<S210>/Constant1'
       *  RelationalOperator: '<S213>/UpperRelop'
       *  Sum: '<S210>/Subtract1'
       */
      if (!(rtb_Saturation_h < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Integral_c3 = rtb_Saturation_h;
      }

      /* End of Switch: '<S213>/Switch' */
    }

    /* End of Switch: '<S213>/Switch2' */

    /* Saturate: '<S210>/Saturation1' */
    if (rtb_Integral_c3 > 0.1) {
      rtb_Integral_c3 = 0.1;
    } else if (rtb_Integral_c3 < -0.1) {
      rtb_Integral_c3 = -0.1;
    }

    /* End of Saturate: '<S210>/Saturation1' */
  } else {
    rtb_Integral_c3 = 0.0;
  }

  /* End of Switch: '<S210>/Switch' */

  /* Switch: '<S149>/Switch2' incorporates:
   *  Logic: '<S149>/Logical Operator1'
   */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S210>/Add1' */
    rtb_Add_mw = rtb_MatrixConcatenate_b_idx_0 + rtb_Integral_c3;

    /* Saturate: '<S210>/Saturation2' */
    if (rtb_Add_mw > 1.0) {
      /* Switch: '<S149>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_mw < -1.0) {
      /* Switch: '<S149>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S149>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_mw;
    }

    /* End of Saturate: '<S210>/Saturation2' */
  } else {
    /* Switch: '<S149>/Switch2' incorporates:
     *  Constant: '<S149>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S149>/Switch2' */

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

  /* RelationalOperator: '<S144>/Compare' incorporates:
   *  Constant: '<S144>/Constant'
   *  Inport: '<Root>/Gamepad_Start'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_Start != 0.0);

  /* Chart: '<S12>/Chart' */
  if (Robot_Control_DW.temporalCounter_i1 < MAX_uint32_T) {
    Robot_Control_DW.temporalCounter_i1++;
  }

  if (Robot_Control_DW.is_active_c6_Robot_Control == 0U) {
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
  rtb_Add_mw = Robot_Control_B.Desired_Feeder_Speed_Out *
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

  /* Sum: '<S148>/Subtract' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Logic: '<S148>/Logical Operator1' incorporates:
   *  Constant: '<S206>/Constant'
   *  RelationalOperator: '<S206>/Compare'
   */
  rtb_LogicalOperator1 = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Switch: '<S148>/Switch1' incorporates:
   *  Constant: '<S148>/Constant1'
   *  Constant: '<S148>/Constant2'
   *  Logic: '<S148>/Logical Operator'
   *  Logic: '<S148>/Logical Operator1'
   *  RelationalOperator: '<S148>/LessThan'
   *  UnitDelay: '<S148>/Unit Delay'
   */
  if ((rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1) {
    rtb_LogicalOperator5 = true;
  } else {
    rtb_LogicalOperator5 = (rtb_LogicalOperator1 &&
      (Robot_Control_DW.UnitDelay_DSTATE_kt));
  }

  /* End of Switch: '<S148>/Switch1' */

  /* Switch: '<S148>/Switch4' incorporates:
   *  Constant: '<S148>/Constant7'
   *  Logic: '<S148>/Logical Operator1'
   *  Logic: '<S148>/Logical Operator3'
   *  RelationalOperator: '<S148>/LessThan2'
   *  UnitDelay: '<S148>/Unit Delay1'
   */
  if ((!(rtb_MatrixConcatenate_b_idx_0 < 0.0)) || (!rtb_LogicalOperator1)) {
    rtb_LogicalOperator1 = (rtb_LogicalOperator1 &&
      (Robot_Control_DW.UnitDelay1_DSTATE_oa));
  }

  /* End of Switch: '<S148>/Switch4' */

  /* Switch: '<S148>/Switch2' incorporates:
   *  Constant: '<S148>/Constant3'
   *  Constant: '<S148>/Constant9'
   *  Logic: '<S148>/Logical Operator4'
   *  Logic: '<S148>/Logical Operator5'
   */
  if (rtb_LogicalOperator5 && (!rtb_LogicalOperator1)) {
    rtb_Shooter_Motor_Gain_Ki = Rebuilt_Shooter_Motor_Gain_I;
  } else {
    rtb_Shooter_Motor_Gain_Ki = Rebuilt_Shooter_Motor_Gain_I_Low;
  }

  /* End of Switch: '<S148>/Switch2' */

  /* Outport: '<Root>/Shooter_Motor_Gain_Ki' */
  Robot_Control_Y.Shooter_Motor_Gain_Ki = rtb_Shooter_Motor_Gain_Ki;

  /* Outport: '<Root>/Shooter_Motor_Gain_Change' incorporates:
   *  Constant: '<S148>/Constant4'
   *  DataTypeConversion: '<S148>/Data Type Conversion'
   *  Logic: '<S148>/Logical Operator2'
   *  RelationalOperator: '<S207>/FixPt Relational Operator'
   *  RelationalOperator: '<S208>/FixPt Relational Operator'
   *  UnitDelay: '<S207>/Delay Input1'
   *  UnitDelay: '<S208>/Delay Input1'
   *
   * Block description for '<S207>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S208>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_Y.Shooter_Motor_Gain_Change = ((Rebuilt_Shooter_Motor_Gain_P !=
    Robot_Control_DW.DelayInput1_DSTATE_o) || (rtb_Shooter_Motor_Gain_Ki !=
    Robot_Control_DW.DelayInput1_DSTATE_j));

  /* Outport: '<Root>/Shooter_Motor_Gain_Kp' incorporates:
   *  Constant: '<S148>/Constant4'
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

  /* Switch: '<S137>/Init' incorporates:
   *  UnitDelay: '<S137>/FixPt Unit Delay1'
   *  UnitDelay: '<S137>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Saturation_h = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Saturation_h = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S137>/Init' */

  /* Sum: '<S135>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 -= rtb_Saturation_h;

  /* Switch: '<S136>/Switch2' incorporates:
   *  Constant: '<S134>/Constant1'
   *  Constant: '<S134>/Constant3'
   *  RelationalOperator: '<S136>/LowerRelop1'
   *  RelationalOperator: '<S136>/UpperRelop'
   *  Switch: '<S136>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Hood_Servo_Rate_Limit_Dec)
  {
    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S134>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S136>/Switch2' */

  /* Sum: '<S135>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Saturation_h;

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

  /* Switch: '<S73>/Init' incorporates:
   *  UnitDelay: '<S73>/FixPt Unit Delay1'
   *  UnitDelay: '<S73>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S73>/Init' */

  /* Sum: '<S71>/Sum1' */
  rtb_Saturation_h = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S72>/Switch2' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Constant: '<S60>/Constant3'
   *  RelationalOperator: '<S72>/LowerRelop1'
   *  RelationalOperator: '<S72>/UpperRelop'
   *  Switch: '<S72>/Switch'
   */
  if (rtb_Saturation_h > Rebuilt_Intake_RL_Inc) {
    rtb_Saturation_h = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Saturation_h < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S72>/Switch' incorporates:
     *  Constant: '<S60>/Constant1'
     */
    rtb_Saturation_h = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S72>/Switch2' */

  /* Sum: '<S71>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Saturation_h +
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S67>/Sum' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S69>/Sum1' incorporates:
   *  Constant: '<S67>/Constant2'
   *  Product: '<S69>/Product'
   *  Sum: '<S69>/Sum'
   *  UnitDelay: '<S69>/Unit Delay1'
   */
  rtb_Sum1_g = ((rtb_MatrixConcatenate_b_idx_0 -
                 Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S67>/Product' incorporates:
   *  Constant: '<S67>/Constant3'
   */
  rtb_Product_f2 = rtb_Sum1_g * Rebuilt_Intake_Arm_Gain_D;

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
  rtb_Add_mw = rtb_Product_f2 - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S67>/Saturation' */
  if (rtb_Add_mw > 0.1) {
    rtb_Add_mw = 0.1;
  } else if (rtb_Add_mw < -0.1) {
    rtb_Add_mw = -0.1;
  }

  /* Sum: '<S67>/Add' incorporates:
   *  Gain: '<S67>/Gain'
   *  Gain: '<S67>/Gain1'
   *  Saturate: '<S67>/Saturation'
   */
  rtb_Minus_k_idx_1 = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
                       (Rebuilt_Intake_Arm_Gain_P *
                        rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_mw;

  /* Sum: '<S67>/Subtract' incorporates:
   *  Constant: '<S67>/Constant'
   */
  rtb_Saturation_h = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S67>/Sum2' incorporates:
   *  Gain: '<S67>/Gain2'
   *  UnitDelay: '<S67>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (0.0 * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S67>/Constant'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  Sum: '<S67>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Minus_k_idx_1))) {
    /* Sum: '<S67>/Subtract1' incorporates:
     *  Constant: '<S67>/Constant1'
     */
    rtb_Saturation_h = -1.0 - rtb_Minus_k_idx_1;

    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S67>/Constant1'
     *  RelationalOperator: '<S70>/UpperRelop'
     *  Sum: '<S67>/Subtract1'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Minus_k_idx_1))) {
      rtb_Saturation_h = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S70>/Switch' */
  }

  /* End of Switch: '<S70>/Switch2' */

  /* Saturate: '<S67>/Saturation1' */
  if (rtb_Saturation_h > 0.1) {
    rtb_Saturation_h = 0.1;
  } else if (rtb_Saturation_h < -0.1) {
    rtb_Saturation_h = -0.1;
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
    rtb_Add_mw = rtb_Minus_k_idx_1 + rtb_Saturation_h;

    /* Saturate: '<S67>/Saturation2' */
    if (rtb_Add_mw > 1.0) {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_mw < -1.0) {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S59>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_mw;
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

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/Constant1'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  if (rtb_Intake_Arm_Move_In) {
    rtb_Minus_k_idx_1 = 0.0;
  } else {
    rtb_Minus_k_idx_1 = Robot_Control_DW.UnitDelay_DSTATE_eo;
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
        rtb_Intake_Arm_Cycle) || ((rtb_Minus_k_idx_1 + 0.02) <=
        Rebuilt_Roller_Intake_In_Delay)) || rtb_LogicalOperator1_ms) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S76>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S62>/Subtract'
   */
  rtb_Error_n = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S78>/Sum1' incorporates:
   *  Constant: '<S76>/Constant2'
   *  Product: '<S78>/Product'
   *  Sum: '<S76>/Sum'
   *  Sum: '<S78>/Sum'
   *  UnitDelay: '<S78>/Unit Delay1'
   */
  rtb_Sum1_ei = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S76>/Product' incorporates:
   *  Constant: '<S76>/Constant3'
   */
  rtb_Product_in = rtb_Sum1_ei * 0.0;

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
  rtb_Add_mw = rtb_Product_in - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S76>/Saturation' */
  if (rtb_Add_mw > 0.1) {
    rtb_Add_mw = 0.1;
  } else if (rtb_Add_mw < -0.1) {
    rtb_Add_mw = -0.1;
  }

  /* Sum: '<S76>/Add' incorporates:
   *  Gain: '<S76>/Gain'
   *  Gain: '<S76>/Gain1'
   *  Saturate: '<S76>/Saturation'
   *  Sum: '<S76>/Sum'
   */
  rtb_Add_mw += (Rebuilt_Roller_Motor_Gain_FF * rtb_MatrixConcatenate_b_idx_0) +
    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n);

  /* Logic: '<S62>/Logical Operator1' incorporates:
   *  Constant: '<S75>/Constant'
   *  RelationalOperator: '<S75>/Compare'
   */
  rtb_Intake_Arm_Move_Out = !(rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S62>/Switch1' incorporates:
   *  Abs: '<S62>/Abs'
   *  Constant: '<S62>/Constant1'
   *  Constant: '<S62>/Constant2'
   *  Logic: '<S62>/Logical Operator'
   *  Logic: '<S62>/Logical Operator1'
   *  RelationalOperator: '<S62>/LessThan'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_Intake_Arm_Move_Out) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_Intake_Arm_Move_Out &&
      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S62>/Switch1' */

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/Constant4'
   */
  if (rtb_Intake_Arm_Move_In) {
    /* Sum: '<S76>/Sum2' incorporates:
     *  Gain: '<S76>/Gain2'
     *  Sum: '<S76>/Sum'
     *  UnitDelay: '<S76>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n)
      + Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S76>/Subtract' incorporates:
     *  Constant: '<S76>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Add_mw;

    /* Switch: '<S79>/Switch2' incorporates:
     *  Constant: '<S76>/Constant'
     *  RelationalOperator: '<S79>/LowerRelop1'
     *  Sum: '<S76>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Add_mw))) {
      /* Sum: '<S76>/Subtract1' incorporates:
       *  Constant: '<S76>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Add_mw;

      /* Switch: '<S79>/Switch' incorporates:
       *  Constant: '<S76>/Constant1'
       *  RelationalOperator: '<S79>/UpperRelop'
       *  Sum: '<S76>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Add_mw))) {
        rtb_Error_n = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S79>/Switch' */
    }

    /* End of Switch: '<S79>/Switch2' */

    /* Saturate: '<S76>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_MatrixConcatenate_b_idx_0 = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_MatrixConcatenate_b_idx_0 = -0.1;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Error_n;
    }

    /* End of Saturate: '<S76>/Saturation1' */
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Switch: '<S62>/Switch2' incorporates:
   *  Logic: '<S62>/Logical Operator1'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S76>/Add1' */
    rtb_Add_mw += rtb_MatrixConcatenate_b_idx_0;

    /* Saturate: '<S76>/Saturation2' */
    if (rtb_Add_mw > 1.0) {
      /* Switch: '<S62>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_mw < -1.0) {
      /* Switch: '<S62>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S62>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_mw;
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
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_a = rtb_Switch1_hb;

  /* Update for UnitDelay: '<S53>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S53>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S53>/FixPt Unit Delay1' */
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

  /* Update for Delay: '<S80>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S100>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S80>/A'
   *  Delay: '<S80>/MemoryX'
   */
  rtb_Sum1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Switch1_hb = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S80>/MemoryX' incorporates:
   *  Constant: '<S80>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S100>/A[k]*xhat[k|k-1]'
   *  Product: '<S100>/B[k]*u[k]'
   *  Sum: '<S100>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Sum1) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Switch1_hb) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S375>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S375>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S193>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_o = rtb_Merge1;

  /* Update for UnitDelay: '<S194>/Unit Delay' incorporates:
   *  Constant: '<S194>/Constant4'
   *  Sum: '<S194>/Sum'
   *  Switch: '<S194>/Switch'
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

  /* Update for UnitDelay: '<S398>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Switch_cn;

  /* Update for UnitDelay: '<S397>/UD'
   *
   * Block description for '<S397>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Switch1_n;

  /* Update for UnitDelay: '<S395>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch2_dh;

  /* Update for UnitDelay: '<S377>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Init_o;

  /* Update for UnitDelay: '<S392>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S392>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S392>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S376>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Switch2_g;

  /* Update for UnitDelay: '<S385>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S385>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S385>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Switch2_g;

  /* Update for UnitDelay: '<S351>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch1_k;

  /* Update for UnitDelay: '<S350>/UD'
   *
   * Block description for '<S350>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2_i;

  /* Update for UnitDelay: '<S362>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Hypot_pi;

  /* Update for UnitDelay: '<S361>/UD'
   *
   * Block description for '<S361>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Product_d1;

  /* Update for UnitDelay: '<S347>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S288>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Add_pw;

  /* Update for UnitDelay: '<S287>/UD'
   *
   * Block description for '<S287>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Subtract1_bm;

  /* Update for UnitDelay: '<S299>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_fg;

  /* Update for UnitDelay: '<S298>/UD'
   *
   * Block description for '<S298>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Product_i3;

  /* Update for UnitDelay: '<S284>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_m;

  /* Update for UnitDelay: '<S309>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S308>/UD'
   *
   * Block description for '<S308>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract_kb;

  /* Update for UnitDelay: '<S320>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S319>/UD'
   *
   * Block description for '<S319>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Hypot_a;

  /* Update for UnitDelay: '<S305>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S330>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_i;

  /* Update for UnitDelay: '<S329>/UD'
   *
   * Block description for '<S329>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_Subtract_h;

  /* Update for UnitDelay: '<S341>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S340>/UD'
   *
   * Block description for '<S340>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_nq;

  /* Update for UnitDelay: '<S326>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_g;

  /* Update for UnitDelay: '<S212>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_lu;

  /* Update for UnitDelay: '<S211>/UD'
   *
   * Block description for '<S211>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_c2;

  /* Update for UnitDelay: '<S210>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_c3;

  /* Update for UnitDelay: '<S149>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Compare_ky;

  /* Update for UnitDelay: '<S148>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kt = rtb_LogicalOperator5;

  /* Update for UnitDelay: '<S148>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_oa = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S207>/Delay Input1'
   *
   * Block description for '<S207>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Shooter_Motor_Gain_Ki;

  /* Update for UnitDelay: '<S208>/Delay Input1' incorporates:
   *  Constant: '<S148>/Constant4'
   *
   * Block description for '<S208>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_o = Rebuilt_Shooter_Motor_Gain_P;

  /* Update for UnitDelay: '<S137>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S137>/FixPt Constant'
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
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_f2;

  /* Update for UnitDelay: '<S67>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_km = rtb_Saturation_h;

  /* Update for UnitDelay: '<S61>/Unit Delay' incorporates:
   *  Constant: '<S61>/Constant'
   *  Sum: '<S61>/Sum'
   *  Switch: '<S61>/Switch'
   */
  Robot_Control_DW.UnitDelay_DSTATE_eo = rtb_Minus_k_idx_1 + 0.02;

  /* Update for UnitDelay: '<S78>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_ei;

  /* Update for UnitDelay: '<S77>/UD'
   *
   * Block description for '<S77>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_in;

  /* Update for UnitDelay: '<S76>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S62>/Unit Delay' */
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

  /* Start for If: '<S141>/If' */
  Robot_Control_DW.If_ActiveSubsystem_n = -1;

  /* InitializeConditions for UnitDelay: '<S47>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S50>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S53>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S80>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S375>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S392>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S385>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S137>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S73>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S455>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S220>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S216>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S220>/Robot_Index_Is_Valid' */
  /* Start for If: '<S223>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S223>/Circle_Check_Valid' */
  /* Start for If: '<S225>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S223>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S220>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S141>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S187>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S141>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S141>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S141>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S141>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S189>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S141>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S141>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S141>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S141>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S191>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S141>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S141>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S192>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

  /* End of SystemInitialize for SubSystem: '<S141>/If Action Subsystem5' */
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
