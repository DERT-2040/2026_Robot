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
 * C/C++ source code generated on : Tue Mar 31 20:33:27 2026
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

/* Named constants for Chart: '<S366>/Add dither' */
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
                                        * Referenced by: '<S149>/Constant2'
                                        */
real_T Blue_Hub_LeftY = 3.354;         /* Variable: Blue_Hub_LeftY
                                        * Referenced by: '<S149>/Constant3'
                                        */
real_T Blue_Hub_RightX = 5.1717;       /* Variable: Blue_Hub_RightX
                                        * Referenced by: '<S149>/Constant4'
                                        */
real_T Blue_Hub_RightY = 4.548;        /* Variable: Blue_Hub_RightY
                                        * Referenced by: '<S149>/Constant5'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S440>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S436>/Constant'
                                        *   '<S436>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S440>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S436>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S269>/Constant3'
                                        *   '<S290>/Constant3'
                                        *   '<S311>/Constant3'
                                        *   '<S332>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S269>/Constant2'
                                   *   '<S290>/Constant2'
                                   *   '<S311>/Constant2'
                                   *   '<S332>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S269>/Saturation'
                                        *   '<S290>/Saturation'
                                        *   '<S311>/Saturation'
                                        *   '<S332>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S269>/Saturation'
                                        *   '<S290>/Saturation'
                                        *   '<S311>/Saturation'
                                        *   '<S332>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S269>/Gain'
                                            *   '<S290>/Gain'
                                            *   '<S311>/Gain'
                                            *   '<S332>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S269>/Gain2'
                                        *   '<S290>/Gain2'
                                        *   '<S311>/Gain2'
                                        *   '<S332>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S269>/Saturation1'
                                         *   '<S290>/Saturation1'
                                         *   '<S311>/Saturation1'
                                         *   '<S332>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S269>/Saturation1'
                                        *   '<S290>/Saturation1'
                                        *   '<S311>/Saturation1'
                                        *   '<S332>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S269>/Gain1'
                                        *   '<S290>/Gain1'
                                        *   '<S311>/Gain1'
                                        *   '<S332>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S274>/Constant'
                            *   '<S295>/Constant'
                            *   '<S316>/Constant'
                            *   '<S337>/Constant'
                            */
real_T Feeder_Max_Pulsetime = 1000.0;  /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S193>/BlueAllianceZoneX'
                                         *   '<S195>/BlueAllianceZoneX'
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
real_T Field_Length = 17.557;          /* Variable: Field_Length
                                        * Referenced by: '<S149>/Constant10'
                                        */
real_T Field_Length_Half = 8.7785;     /* Variable: Field_Length_Half
                                        * Referenced by:
                                        *   '<S167>/Switch'
                                        *   '<S168>/Switch'
                                        */
real_T Field_Pass_Y_Bottom = 2.4384;   /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S150>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 5.6309;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S150>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S194>/RedAllianceZoneX'
                                         *   '<S196>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S150>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S150>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S426>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S426>/Constant5'
                                          */
real_T Field_Width = 8.0693;           /* Variable: Field_Width
                                        * Referenced by: '<S149>/Constant11'
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
                                       * Referenced by: '<S165>/Constant'
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
                                   * Referenced by: '<S129>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S129>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S62>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.008;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                          * Referenced by: '<S62>/Gain1'
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
                                            *   '<S58>/Constant'
                                            */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S59>/Constant'
                                            */
real_T Rebuilt_Intake_Meas_In_Disable = -20.0;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S60>/Constant'
                                      */
real_T Rebuilt_Intake_Meas_Out_Disable = 80.0;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S61>/Constant'
                                     */
real_T Rebuilt_Intake_RL_Dec = -3.0;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S55>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 3.0;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S55>/Constant3'
                                        */
real_T Rebuilt_Match_Time_Auto_Timer = 30.0;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S178>/Unit Delay'
                                       */
real_T Rebuilt_Match_Time_End_Game_Timer = 30.0;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S182>/Constant3'
                                   *   '<S183>/Unit Delay'
                                   */
real_T Rebuilt_Match_Time_Shift_1 = 35.0;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S173>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_2 = 60.0;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S174>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_3 = 85.0;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S175>/Constant'
                                          */
real_T Rebuilt_Match_Time_Shift_4 = 110.0;/* Variable: Rebuilt_Match_Time_Shift_4
                                           * Referenced by: '<S176>/Constant'
                                           */
real_T Rebuilt_Match_Time_Shift_Timer = 25.0;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S179>/Unit Delay'
                                      *   '<S180>/Unit Delay'
                                      *   '<S181>/Unit Delay'
                                      *   '<S182>/Unit Delay'
                                      */
real_T Rebuilt_Match_Time_Shoot_Early = 2.0;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S179>/Constant2'
                                      *   '<S180>/Constant2'
                                      *   '<S181>/Constant2'
                                      *   '<S182>/Constant2'
                                      *   '<S186>/Constant'
                                      *   '<S187>/Constant'
                                      *   '<S188>/Constant'
                                      *   '<S189>/Constant'
                                      */
real_T Rebuilt_Match_Time_Transition = 10.0;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S170>/Constant'
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
                                * Referenced by: '<S57>/Constant1'
                                */
real_T Rebuilt_Roller_Intake_In_Delay = 2.0;
                                     /* Variable: Rebuilt_Roller_Intake_In_Delay
                                      * Referenced by: '<S69>/Constant'
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
                                        * Referenced by: '<S146>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S146>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 3.5; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S146>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 3.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S146>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S146>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_5
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
                                    * Referenced by: '<S139>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S139>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S139>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2680.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S160>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2930.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S160>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3220.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S160>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3380.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S160>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3580.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S160>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3730.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S160>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3930.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S160>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S160>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2780.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S159>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3030.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S159>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3320.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S159>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3480.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S159>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3680.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S159>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3830.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S159>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 4030.0;
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
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00015;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S12>/Constant1'
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
                              * Referenced by: '<S141>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S198>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S198>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S198>/Gain1'
                                       */
real_T Red_Hub_LeftX = 11.369;         /* Variable: Red_Hub_LeftX
                                        * Referenced by: '<S149>/Constant6'
                                        */
real_T Red_Hub_LeftY = 4.548;          /* Variable: Red_Hub_LeftY
                                        * Referenced by: '<S149>/Constant7'
                                        */
real_T Red_Hub_RightX = 11.369;        /* Variable: Red_Hub_RightX
                                        * Referenced by: '<S149>/Constant8'
                                        */
real_T Red_Hub_RightY = 3.354;         /* Variable: Red_Hub_RightY
                                        * Referenced by: '<S149>/Constant9'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S425>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S423>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S425>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S426>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S426>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S258>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S258>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S205>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S218>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S258>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S365>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S365>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S365>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S365>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S365>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S365>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S383>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S383>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S383>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S383>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S382>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S383>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S383>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S383>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S383>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S383>/Constant1'
                                   *   '<S383>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S383>/Constant'
                                   *   '<S383>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S366>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S366>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S366>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S366>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S272>/Constant3'
                                        *   '<S293>/Constant3'
                                        *   '<S314>/Constant3'
                                        *   '<S335>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S272>/Constant2'
                                *   '<S293>/Constant2'
                                *   '<S314>/Constant2'
                                *   '<S335>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S272>/Saturation'
                                           *   '<S293>/Saturation'
                                           *   '<S314>/Saturation'
                                           *   '<S335>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S272>/Saturation'
                                          *   '<S293>/Saturation'
                                          *   '<S314>/Saturation'
                                          *   '<S335>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S272>/Gain2'
                                         *   '<S293>/Gain2'
                                         *   '<S314>/Gain2'
                                         *   '<S335>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S272>/Saturation1'
                                             *   '<S293>/Saturation1'
                                             *   '<S314>/Saturation1'
                                             *   '<S335>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S272>/Saturation1'
                                            *   '<S293>/Saturation1'
                                            *   '<S314>/Saturation1'
                                            *   '<S335>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S272>/Gain1'
                                        *   '<S293>/Gain1'
                                        *   '<S314>/Gain1'
                                        *   '<S335>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S364>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S364>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S364>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S364>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S364>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S364>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S425>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S425>/Constant1'
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
                                      * Referenced by: '<S424>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S424>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S424>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S352>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S352>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S352>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S352>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S352>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S352>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S426>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S425>/Dead Zone'
                                        *   '<S426>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S425>/Dead Zone'
                                        *   '<S426>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S423>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S423>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S423>/Constant4'
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
                                        * Referenced by: '<S423>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S423>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S423>/Constant5'
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
                                        *   '<S423>/Constant11'
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
  /* InitializeConditions for UnitDelay: '<S179>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Rebuilt_Match_Time_Shift_Timer;
}

/*
 * System reset for action system:
 *    '<S135>/If Action Subsystem1'
 *    '<S135>/If Action Subsystem3'
 */
void Robot__IfActionSubsystem1_Reset(DW_IfActionSubsystem1_Robot_C_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S179>/Unit Delay' */
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
  boolean_T rtb_Compare_cf;

  /* RelationalOperator: '<S186>/Compare' incorporates:
   *  Constant: '<S179>/Constant1'
   *  Constant: '<S186>/Constant'
   *  Sum: '<S179>/Sum'
   *  UnitDelay: '<S179>/Unit Delay'
   */
  rtb_Compare_cf = ((localDW->UnitDelay_DSTATE - 0.02) <=
                    Rebuilt_Match_Time_Shoot_Early);

  /* Logic: '<S179>/Logical Operator' incorporates:
   *  Logic: '<S179>/NOT'
   */
  *rty_IsBlueActive = ((!(rtu_IsBlueInactiveFirst != 0.0)) || rtb_Compare_cf);

  /* Logic: '<S179>/Logical Operator1' */
  *rty_IsRedActive = ((rtu_IsBlueInactiveFirst != 0.0) || rtb_Compare_cf);

  /* Switch: '<S179>/Switch' incorporates:
   *  Constant: '<S179>/Constant1'
   *  Constant: '<S179>/Constant2'
   *  Logic: '<S179>/Logical Operator2'
   *  Sum: '<S179>/Subtract'
   *  Sum: '<S179>/Sum'
   *  UnitDelay: '<S179>/Unit Delay'
   */
  if ((boolean_T)((rtu_IsBlueInactiveFirst != 0.0) ^ (rtu_IsBlueAlliance != 0.0)))
  {
    *rty_Time_Remaining = localDW->UnitDelay_DSTATE - 0.02;
  } else {
    *rty_Time_Remaining = (localDW->UnitDelay_DSTATE - 0.02) -
      Rebuilt_Match_Time_Shoot_Early;
  }

  /* End of Switch: '<S179>/Switch' */

  /* Update for UnitDelay: '<S179>/Unit Delay' incorporates:
   *  Constant: '<S179>/Constant1'
   *  Sum: '<S179>/Sum'
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
  real_T rtb_Add_de;
  real_T rtb_Add_fn;
  real_T rtb_Add_ju;
  real_T rtb_Add_nz;
  real_T rtb_Error_n;
  real_T rtb_Hypot_g5;
  real_T rtb_Init;
  real_T rtb_Init_o;
  real_T rtb_Integral_d;
  real_T rtb_Integral_hv;
  real_T rtb_Integral_m;
  real_T rtb_Integral_p;
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
  real_T rtb_Switch_cn;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s230_iter;
  uint16_T s255_iter;
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
  boolean_T rtb_Is_Absolute_Steering;
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

  /* If: '<S452>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S452>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S455>/Action Port'
     */
    /* Product: '<S455>/Product' incorporates:
     *  Constant: '<S455>/Constant1'
     *  Constant: '<S455>/Constant2'
     *  Math: '<S455>/Math Function'
     */
    rtb_Sin4 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495) *
      111.0;

    /* End of Outputs for SubSystem: '<S452>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S452>/Subsystem' incorporates:
     *  ActionPort: '<S456>/Action Port'
     */
    /* SignalConversion generated from: '<S456>/Out1' incorporates:
     *  Constant: '<S456>/Constant'
     */
    rtb_Sin4 = 0.0;

    /* End of Outputs for SubSystem: '<S452>/Subsystem' */
  }

  /* End of If: '<S452>/If' */

  /* Gain: '<S453>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Init_o = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S454>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Sin4 * cos(rtb_Init_o)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S454>/theta->y'
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
    rtb_Compare_mq = false;

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
      rtb_MultiportSwitch1[0] = 14;
      rtb_MultiportSwitch1[1] = 15;
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
      (Robot_Control_B.Auto_Path_ID, 1.0, 1.0, 14U)];

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
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S18>/Constant1'
     *  SignalConversion generated from: '<S2>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S18>/Constant5'
     */
    rtb_Compare_mq = false;

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
       *  UnitDelay: '<S425>/Unit Delay1'
       *  UnitDelay: '<S425>/Unit Delay2'
       *  UnitDelay: '<S425>/Unit Delay3'
       *  UnitDelay: '<S425>/Unit Delay4'
       *  UnitDelay: '<S428>/Delay Input1'
       *  UnitDelay: '<S429>/Delay Input1'
       *  UnitDelay: '<S430>/Delay Input1'
       *  UnitDelay: '<S431>/Delay Input1'
       *  UnitDelay: '<S433>/Delay Input1'
       *  UnitDelay: '<S439>/Unit Delay'
       *  UnitDelay: '<S439>/Unit Delay1'
       *  UnitDelay: '<S443>/FixPt Unit Delay1'
       *  UnitDelay: '<S443>/FixPt Unit Delay2'
       *
       * Block description for '<S428>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S429>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S430>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S431>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S433>/Delay Input1':
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

    /* Switch: '<S423>/Switch4' incorporates:
     *  Constant: '<S448>/Constant'
     *  Constant: '<S451>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S448>/Compare'
     *  RelationalOperator: '<S451>/Compare'
     *  Switch: '<S423>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S423>/Switch4' incorporates:
       *  Constant: '<S423>/Constant8'
       *  Sum: '<S423>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S423>/Switch5' incorporates:
       *  Constant: '<S423>/Constant7'
       *  Gain: '<S423>/Gain'
       *  Sum: '<S423>/Subtract5'
       *  Switch: '<S423>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S423>/Switch4' incorporates:
       *  Constant: '<S423>/Constant6'
       *  Switch: '<S423>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S423>/Switch4' */

    /* Logic: '<S423>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S423>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S425>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Minus_f = 0.0;
    } else {
      rtb_Minus_f = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S425>/Add' incorporates:
     *  Constant: '<S425>/Constant'
     *  Constant: '<S425>/Constant1'
     *  DeadZone: '<S425>/Dead Zone'
     *  Lookup_n-D: '<S425>/Modulation_Str_Y_Rel'
     *  Product: '<S425>/Product'
     *  Product: '<S425>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Switch1_m = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                     Steering_Relative_Gain) + (rtb_Minus_f *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S427>/Compare' incorporates:
     *  Constant: '<S427>/Constant'
     */
    rtb_Compare_lk = (rtb_Switch1_m == 0.0);

    /* Logic: '<S425>/AND2' incorporates:
     *  RelationalOperator: '<S428>/FixPt Relational Operator'
     *  RelationalOperator: '<S429>/FixPt Relational Operator'
     *  RelationalOperator: '<S430>/FixPt Relational Operator'
     *  RelationalOperator: '<S431>/FixPt Relational Operator'
     *  UnitDelay: '<S428>/Delay Input1'
     *  UnitDelay: '<S429>/Delay Input1'
     *  UnitDelay: '<S430>/Delay Input1'
     *  UnitDelay: '<S431>/Delay Input1'
     *
     * Block description for '<S428>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S429>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S430>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S431>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Intake_Arm_Move_In = ((((((int32_T)rtb_LogicalOperator2) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_Compare_pb) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S425>/AND1' incorporates:
     *  Logic: '<S425>/AND3'
     *  UnitDelay: '<S425>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_lk && (rtb_Intake_Arm_Move_In ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S425>/AND4' incorporates:
     *  Logic: '<S425>/AND8'
     *  UnitDelay: '<S425>/Unit Delay4'
     */
    rtb_AND4_j = ((rtb_Compare_lk && (!rtb_Intake_Arm_Move_In)) &&
                  (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S425>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4_j);

    /* Switch: '<S425>/Switch8' incorporates:
     *  Constant: '<S434>/Constant'
     *  Logic: '<S425>/AND9'
     *  RelationalOperator: '<S433>/FixPt Relational Operator'
     *  RelationalOperator: '<S434>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S433>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S433>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_lk) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j)))
         || (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_DW.UnitDelay1_DSTATE_nl)) {
      /* Switch: '<S425>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S425>/Switch8' incorporates:
       *  UnitDelay: '<S425>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S425>/Switch8' */

    /* Switch: '<S425>/Switch4' incorporates:
     *  Constant: '<S425>/Constant5'
     *  Switch: '<S425>/Switch1'
     *  Switch: '<S425>/Switch5'
     *  Switch: '<S425>/Switch6'
     *  Switch: '<S425>/Switch7'
     */
    if (rtb_LogicalOperator2) {
      rtb_Saturation_h = 0.0;
    } else if (rtb_Compare_pb) {
      /* Switch: '<S425>/Switch5' incorporates:
       *  Constant: '<S425>/Constant6'
       */
      rtb_Saturation_h = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S425>/Switch6' incorporates:
       *  Constant: '<S425>/Constant7'
       *  Switch: '<S425>/Switch5'
       */
      rtb_Saturation_h = 3.1415926535897931;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S425>/Switch7' incorporates:
       *  Constant: '<S425>/Constant8'
       *  Switch: '<S425>/Switch5'
       *  Switch: '<S425>/Switch6'
       */
      rtb_Saturation_h = 4.71238898038469;
    } else if (rtb_AND4_j) {
      /* Switch: '<S425>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S425>/Switch5'
       *  Switch: '<S425>/Switch6'
       *  Switch: '<S425>/Switch7'
       */
      rtb_Saturation_h = 0.0;
    } else {
      /* Switch: '<S425>/Switch6' incorporates:
       *  Switch: '<S425>/Switch5'
       *  Switch: '<S425>/Switch7'
       *  UnitDelay: '<S425>/Unit Delay1'
       */
      rtb_Saturation_h = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S425>/Switch4' */

    /* Switch: '<S425>/Switch2' incorporates:
     *  Switch: '<S425>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S425>/Switch2' incorporates:
       *  Constant: '<S425>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S425>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Saturation_h;
    } else {
      /* Switch: '<S425>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S425>/Switch3' incorporates:
       *  Constant: '<S425>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S425>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S425>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S424>/Switch1' incorporates:
     *  Constant: '<S424>/Constant5'
     *  Constant: '<S424>/Constant8'
     *  DataTypeConversion: '<S424>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_lk;
    }

    /* End of Switch: '<S424>/Switch1' */

    /* Lookup_n-D: '<S426>/Modulation_Drv' incorporates:
     *  Math: '<S426>/Magnitude'
     */
    rtb_Init_o = look1_binlcpw(rt_hypotd_snf(rtb_Sum1, rtb_Switch1_hb),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S437>/Compare' incorporates:
     *  Constant: '<S437>/Constant'
     */
    rtb_Shooter_Active_prev = (rtb_Init_o == 0.0);

    /* DeadZone: '<S426>/Dead Zone' */
    if (rtb_Switch1_h > Twist_Deadzone_pos) {
      rtb_Sin4 = rtb_Switch1_h - Twist_Deadzone_pos;
    } else if (rtb_Switch1_h >= Twist_Deadzone_neg) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = rtb_Switch1_h - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S426>/Dead Zone' */

    /* Logic: '<S426>/Logical Operator' incorporates:
     *  Constant: '<S438>/Constant'
     *  RelationalOperator: '<S438>/Compare'
     */
    rtb_Intake_Arm_Move_In = ((rtb_Sin4 != 0.0) && rtb_Shooter_Active_prev);

    /* Switch: '<S424>/Switch' incorporates:
     *  Constant: '<S424>/Constant5'
     *  Constant: '<S424>/Constant7'
     *  DataTypeConversion: '<S424>/Data Type Conversion'
     *  Logic: '<S426>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_mq = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Compare_mq = !rtb_Intake_Arm_Move_In;
    }

    /* End of Switch: '<S424>/Switch' */

    /* Switch: '<S423>/Switch2' incorporates:
     *  Constant: '<S423>/Constant2'
     *  Constant: '<S447>/Constant'
     *  Constant: '<S450>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S447>/Compare'
     *  RelationalOperator: '<S450>/Compare'
     *  Sum: '<S423>/Subtract'
     *  Switch: '<S423>/Switch'
     *  Switch: '<S423>/Switch1'
     *  Switch: '<S423>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S423>/Switch2' incorporates:
       *  Constant: '<S423>/Constant5'
       *  Sum: '<S423>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_h = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S423>/Switch2' incorporates:
       *  Constant: '<S423>/Constant4'
       *  Sum: '<S423>/Subtract2'
       *  Switch: '<S423>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S423>/Switch1' incorporates:
       *  Constant: '<S423>/Constant1'
       *  Sum: '<S423>/Subtract3'
       */
      rtb_Switch2_h = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S423>/Switch2' incorporates:
       *  Constant: '<S423>/Constant3'
       *  Switch: '<S423>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S423>/Switch1' incorporates:
       *  Constant: '<S423>/Constant'
       */
      rtb_Switch2_h = 0.0;
    }

    /* End of Switch: '<S423>/Switch2' */

    /* UnaryMinus: '<S423>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_h;

    /* Switch: '<S439>/Switch1' incorporates:
     *  Constant: '<S444>/Constant'
     *  Constant: '<S445>/Constant'
     *  Logic: '<S439>/AND'
     *  RelationalOperator: '<S444>/Compare'
     *  RelationalOperator: '<S445>/Compare'
     *  Switch: '<S439>/Switch2'
     *  UnitDelay: '<S439>/Unit Delay'
     *  UnitDelay: '<S439>/Unit Delay1'
     */
    if ((rtb_Sum1 == 0.0) && (rtb_Switch1_hb == 0.0)) {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_hw = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1_n = rtb_Switch1_hb;
      rtb_Switch2_hw = rtb_Sum1;
    }

    /* End of Switch: '<S439>/Switch1' */

    /* Switch: '<S426>/Switch1' incorporates:
     *  Logic: '<S426>/Logical Operator1'
     *  Switch: '<S426>/Switch4'
     *  Switch: '<S426>/Switch9'
     */
    if (rtb_Intake_Arm_Move_In) {
      /* Signum: '<S426>/Sign' */
      if (rtIsNaN(rtb_Sin4)) {
        rtb_Minus_f = (rtNaN);
      } else if (rtb_Sin4 < 0.0) {
        rtb_Minus_f = -1.0;
      } else {
        rtb_Minus_f = (rtb_Sin4 > 0.0);
      }

      /* Switch: '<S426>/Switch5' incorporates:
       *  Constant: '<S426>/Constant3'
       *  Constant: '<S426>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Hypot_g5 = -1.5707963267948966;
      } else {
        rtb_Hypot_g5 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S426>/Gain3'
       *  Signum: '<S426>/Sign'
       *  Sum: '<S426>/Add'
       *  Switch: '<S426>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Minus_f) +
        rtb_Hypot_g5;
    } else if (rtb_Shooter_Active_prev) {
      /* Switch: '<S426>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S426>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S426>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S426>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S426>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S426>/Switch4'
       *  Trigonometry: '<S426>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1_n,
        rtb_Switch2_hw);
    }

    /* End of Switch: '<S426>/Switch1' */

    /* Switch: '<S436>/Switch1' incorporates:
     *  Constant: '<S436>/Constant'
     *  Constant: '<S436>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_h = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_h = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S436>/Switch1' */

    /* Switch: '<S443>/Init' incorporates:
     *  UnitDelay: '<S443>/FixPt Unit Delay1'
     *  UnitDelay: '<S443>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_h;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S443>/Init' */

    /* Sum: '<S441>/Sum1' */
    rtb_Switch2_h -= rtb_Init;

    /* Switch: '<S442>/Switch2' incorporates:
     *  Constant: '<S440>/Constant1'
     *  Constant: '<S440>/Constant3'
     *  RelationalOperator: '<S442>/LowerRelop1'
     *  RelationalOperator: '<S442>/UpperRelop'
     *  Switch: '<S442>/Switch'
     */
    if (rtb_Switch2_h > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_h = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_h < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S442>/Switch' incorporates:
       *  Constant: '<S440>/Constant1'
       */
      rtb_Switch2_h = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S442>/Switch2' */

    /* Sum: '<S441>/Sum' */
    rtb_Init += rtb_Switch2_h;

    /* Switch: '<S426>/Switch8' incorporates:
     *  Logic: '<S426>/Logical Operator1'
     *  Switch: '<S426>/Switch2'
     */
    if (rtb_Intake_Arm_Move_In) {
      /* Switch: '<S426>/Switch' incorporates:
       *  Gain: '<S426>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Sin4;
    } else if (rtb_Shooter_Active_prev) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S426>/Constant5'
       *  Gain: '<S426>/Gain2'
       *  Math: '<S426>/Magnitude1'
       *  MinMax: '<S426>/Min'
       *  Switch: '<S426>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S436>/Product' incorporates:
       *  Switch: '<S426>/Switch2'
       */
      rtb_Integral_hv = rtb_Init_o * rtb_Init;

      /* Saturate: '<S436>/Saturation' incorporates:
       *  Switch: '<S426>/Switch2'
       */
      if (rtb_Integral_hv > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Integral_hv < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Integral_hv;
      }

      /* End of Saturate: '<S436>/Saturation' */
    }

    /* End of Switch: '<S426>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S425>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Switch1_m;

    /* Switch: '<S423>/Switch6' incorporates:
     *  Constant: '<S423>/Constant11'
     *  Switch: '<S423>/Switch7'
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

    /* RelationalOperator: '<S419>/Compare' incorporates:
     *  Constant: '<S419>/Constant'
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = (Robot_Control_U.Gamepad_LB != 0.0);

    /* RelationalOperator: '<S420>/Compare' incorporates:
     *  Constant: '<S420>/Constant'
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Compare_ky = (Robot_Control_U.Gamepad_RB != 0.0);

    /* RelationalOperator: '<S415>/Compare' incorporates:
     *  Constant: '<S415>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S418>/Compare' incorporates:
     *  Constant: '<S418>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S417>/Compare' incorporates:
     *  Constant: '<S417>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Constant: '<S416>/Constant'
     *  Constant: '<S421>/Constant'
     *  Inport: '<Root>/Gamepad_LT'
     *  Inport: '<Root>/Joystick_Right_B1'
     *  RelationalOperator: '<S416>/Compare'
     *  RelationalOperator: '<S421>/Compare'
     */
    rtb_LogicalOperator1_ms = ((Robot_Control_U.Joystick_Right_B1 != 0.0) ||
      (Robot_Control_U.Gamepad_LT != 0.0));

    /* SignalConversion generated from: '<S15>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S15>/Constant21'
     */
    rtb_Switch1_m = 0.0;

    /* Update for UnitDelay: '<S433>/Delay Input1'
     *
     * Block description for '<S433>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_lk;

    /* Update for UnitDelay: '<S432>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S432>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S428>/Delay Input1'
     *
     * Block description for '<S428>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S429>/Delay Input1'
     *
     * Block description for '<S429>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_Compare_pb;

    /* Update for UnitDelay: '<S430>/Delay Input1'
     *
     * Block description for '<S430>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S431>/Delay Input1'
     *
     * Block description for '<S431>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S425>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1_c;

    /* Update for UnitDelay: '<S425>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4_j;

    /* Update for UnitDelay: '<S425>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S425>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Saturation_h;

    /* Update for UnitDelay: '<S439>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1_n;

    /* Update for UnitDelay: '<S439>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2_hw;

    /* Update for UnitDelay: '<S443>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S443>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S443>/FixPt Unit Delay1' */
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
    rtb_Compare_mq = false;

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
    rtb_Switch1_n = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Switch1_n;

    /* Sum: '<S126>/Sum' incorporates:
     *  Constant: '<S75>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S126>/C[k]*xhat[k|k-1]'
     *  Product: '<S126>/D[k]*u[k]'
     *  Sum: '<S126>/Add1'
     */
    rtb_Init_o = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Switch2_hw = rtb_Reshapey[0] - (rtb_Init_o + rtb_Switch1_n);

    /* Product: '<S126>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S75>/C'
     *  Delay: '<S75>/MemoryX'
     *  Product: '<S128>/Product'
     */
    rtb_Switch1_n = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Switch1_n;

    /* Sum: '<S126>/Sum' incorporates:
     *  Constant: '<S75>/D'
     *  Product: '<S126>/C[k]*xhat[k|k-1]'
     *  Product: '<S126>/D[k]*u[k]'
     *  Sum: '<S126>/Add1'
     */
    rtb_Switch1_n = rtb_Reshapey[1] - (rtb_Init_o + rtb_Switch1_n);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S126>/Product3' incorporates:
     *  Constant: '<S76>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Switch2_hw) +
      (-2.0601714451538746E-17 * rtb_Switch1_n);

    /* Sum: '<S128>/Add1' incorporates:
     *  Product: '<S128>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S126>/Product3' incorporates:
     *  Constant: '<S76>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Switch2_hw) +
      (0.095124921972504 * rtb_Switch1_n);

    /* Sum: '<S128>/Add1' incorporates:
     *  Product: '<S128>/Product'
     */
    rtb_Switch1_n = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S128>/Product2' incorporates:
     *  Constant: '<S76>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Switch1_n);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Switch1_n);
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
   *  Constant: '<S255>/Constant'
   *  Logic: '<S255>/AND'
   *  MATLAB Function: '<S205>/Find closest index to curve'
   *  Product: '<S255>/Product'
   *  RelationalOperator: '<S255>/Relational Operator'
   *  RelationalOperator: '<S255>/Relational Operator1'
   *  Selector: '<S255>/Selector'
   *  Selector: '<S255>/Selector1'
   *  Selector: '<S256>/Selector'
   *  Sum: '<S255>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S208>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S211>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S213>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S208>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S203>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S203>/Unit Delay'
       *  UnitDelay: '<S204>/Unit Delay'
       *  UnitDelay: '<S206>/Unit Delay'
       *  UnitDelay: '<S206>/Unit Delay1'
       *  UnitDelay: '<S256>/Unit Delay'
       *  UnitDelay: '<S256>/Unit Delay1'
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
     *  ActionPort: '<S203>/Action Port'
     */
    /* Selector: '<S204>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_h[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_h[i + 10];
    }

    /* End of Selector: '<S204>/Selector1' */

    /* Lookup_n-D: '<S203>/Capture Radius' incorporates:
     *  UnitDelay: '<S203>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S204>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S204>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S208>/If' incorporates:
     *  RelationalOperator: '<S208>/ '
     *  UnitDelay: '<S204>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S211>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S213>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S208>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S211>/Action Port'
       */
      /* InitializeConditions for If: '<S208>/If' incorporates:
       *  UnitDelay: '<S211>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S208>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S208>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S211>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S211>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S214>/Action Port'
       */
      /* If: '<S211>/If' incorporates:
       *  Selector: '<S204>/Selector1'
       *  Selector: '<S211>/Selector'
       *  Selector: '<S214>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S211>/Increment_If_Rectangle_Check' */

      /* Sum: '<S211>/Minus' incorporates:
       *  Concatenate: '<S204>/Matrix Concatenate2'
       *  Selector: '<S211>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S211>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S214>/Action Port'
       */
      /* If: '<S211>/If' incorporates:
       *  Selector: '<S204>/Selector1'
       *  Selector: '<S211>/Selector'
       *  Selector: '<S214>/Selector'
       *  Sum: '<S211>/Minus'
       */
      rtb_Init_o = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh)
        + 9];

      /* End of Outputs for SubSystem: '<S211>/Increment_If_Rectangle_Check' */

      /* Sum: '<S211>/Minus' incorporates:
       *  Concatenate: '<S204>/Matrix Concatenate2'
       *  Selector: '<S211>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Init_o;

      /* Math: '<S211>/Hypot' */
      rtb_Switch1_n = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S211>/Equal' */
      rtb_LogicalOperator5 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S211>/Switch' incorporates:
       *  Logic: '<S211>/AND'
       *  Logic: '<S211>/OR'
       *  RelationalOperator: '<S211>/Relational Operator'
       *  UnitDelay: '<S211>/Unit Delay'
       */
      rtb_LogicalOperator1 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Switch1_n <= rtb_Saturation_h) && rtb_LogicalOperator5));

      /* If: '<S211>/If' */
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
        /* Disable for If: '<S213>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S211>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S213>/Action Port'
         */
        /* If: '<S213>/If' incorporates:
         *  RelationalOperator: '<S213>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S213>/Is_Last_Point' incorporates:
           *  ActionPort: '<S216>/Action Port'
           */
          /* InitializeConditions for If: '<S213>/If' incorporates:
           *  UnitDelay: '<S216>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S213>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S213>/Is_Last_Point' incorporates:
           *  ActionPort: '<S216>/Action Port'
           */
          /* Switch: '<S216>/Switch' incorporates:
           *  Constant: '<S218>/Constant'
           *  Logic: '<S216>/OR'
           *  RelationalOperator: '<S218>/Compare'
           *  UnitDelay: '<S216>/Unit Delay'
           */
          rtb_Compare_mq = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
                            (rtb_Switch1_n <= Spline_Stop_Radius));

          /* If: '<S216>/If' */
          if (rtb_Compare_mq) {
            /* Outputs for IfAction SubSystem: '<S216>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S219>/Action Port'
             */
            /* Merge: '<S208>/Merge2' incorporates:
             *  Constant: '<S219>/Constant'
             *  SignalConversion generated from: '<S219>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = true;

            /* SignalConversion generated from: '<S219>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S219>/Constant1'
             */
            rtb_Compare_pb = false;

            /* End of Outputs for SubSystem: '<S216>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S216>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S220>/Action Port'
             */
            /* Merge: '<S208>/Merge2' incorporates:
             *  Constant: '<S220>/Constant'
             *  SignalConversion generated from: '<S220>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator5 = false;

            /* SignalConversion generated from: '<S220>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S220>/Constant1'
             */
            rtb_Compare_pb = true;

            /* End of Outputs for SubSystem: '<S216>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S216>/If' */

          /* Merge: '<S208>/Merge4' incorporates:
           *  SignalConversion: '<S216>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S216>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Compare_mq;

          /* End of Outputs for SubSystem: '<S213>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S213>/Increment_Search' incorporates:
           *  ActionPort: '<S215>/Action Port'
           */
          /* Merge: '<S208>/Merge2' incorporates:
           *  Constant: '<S215>/Constant'
           *  SignalConversion generated from: '<S215>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator5 = false;

          /* SignalConversion generated from: '<S215>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S215>/Constant1'
           */
          rtb_Compare_pb = false;

          /* Merge: '<S208>/Merge4' incorporates:
           *  Constant: '<S217>/FixPt Constant'
           *  SignalConversion: '<S215>/Signal Copy'
           *  Sum: '<S217>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S213>/Increment_Search' */
        }

        /* End of If: '<S213>/If' */
        /* End of Outputs for SubSystem: '<S211>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S211>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S214>/Action Port'
         */
        /* Sum: '<S221>/FixPt Sum1' incorporates:
         *  Constant: '<S221>/FixPt Constant'
         */
        rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S214>/Selector1' incorporates:
         *  Selector: '<S204>/Selector1'
         */
        rtb_Switch2_h = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) - 1];

        /* Sum: '<S222>/Subtract' incorporates:
         *  Selector: '<S214>/Selector1'
         *  Sum: '<S222>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_h - rtb_Init;

        /* Selector: '<S214>/Selector1' incorporates:
         *  Selector: '<S204>/Selector1'
         */
        rtb_Sin4 = rtb_Ref_Poses[((int32_T)rtb_Switch1_n) + 9];

        /* Sum: '<S222>/Subtract' incorporates:
         *  Selector: '<S214>/Selector1'
         *  Sum: '<S222>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Sin4 - rtb_Init_o;

        /* Math: '<S222>/Hypot' */
        rtb_Switch2_hw = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S222>/Divide' */
        rtb_Switch1_n = rtb_Minus_n[1];

        /* UnaryMinus: '<S222>/Unary Minus' */
        rtb_Minus_f = rtb_Minus_n[0];

        /* Product: '<S222>/Product' incorporates:
         *  Product: '<S222>/Divide'
         *  UnaryMinus: '<S222>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Switch1_n / rtb_Switch2_hw) * rtb_Saturation_h;
        rtb_Minus_n[1] = ((-rtb_Minus_f) / rtb_Switch2_hw) * rtb_Saturation_h;

        /* Sum: '<S222>/Add1' incorporates:
         *  Sum: '<S222>/Add2'
         *  Sum: '<S222>/Minus'
         */
        rtb_Minus_f = rtb_Switch2_h - rtb_Minus_n[0];

        /* Sum: '<S222>/Minus4' incorporates:
         *  Sum: '<S222>/Add2'
         *  Sum: '<S222>/Minus'
         */
        rtb_Switch2_h = (rtb_Switch2_h + rtb_Minus_n[0]) - rtb_Minus_f;

        /* Sum: '<S222>/Minus5' incorporates:
         *  Concatenate: '<S204>/Matrix Concatenate2'
         *  Sum: '<S222>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[0] - rtb_Minus_f;

        /* Sum: '<S222>/Add' incorporates:
         *  Sum: '<S222>/Add2'
         *  Sum: '<S222>/Minus1'
         */
        rtb_Switch1_n = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S222>/Minus' incorporates:
         *  Sum: '<S222>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S222>/Dot Product' incorporates:
         *  Concatenate: '<S204>/Matrix Concatenate2'
         *  Sum: '<S222>/Minus'
         *  Sum: '<S222>/Minus1'
         *  Sum: '<S222>/Minus5'
         */
        rtb_Switch2_hw = (rtb_Reshapey[0] - rtb_Switch1_n) * rtb_Minus_f;

        /* DotProduct: '<S222>/Dot Product1' incorporates:
         *  Sum: '<S222>/Minus'
         */
        rtb_Init = rtb_Minus_f * rtb_Minus_f;

        /* DotProduct: '<S222>/Dot Product2' incorporates:
         *  Sum: '<S222>/Minus4'
         *  Sum: '<S222>/Minus5'
         */
        rtb_Minus_k_idx_0 = rtb_Switch2_h * rtb_MatrixConcatenate_b_idx_0;

        /* DotProduct: '<S222>/Dot Product3' incorporates:
         *  Sum: '<S222>/Minus4'
         */
        rtb_Minus_k_idx_1 = rtb_Switch2_h * rtb_Switch2_h;

        /* Sum: '<S222>/Add1' incorporates:
         *  Sum: '<S222>/Add2'
         *  Sum: '<S222>/Minus'
         */
        rtb_Minus_f = rtb_Sin4 - rtb_Minus_n[1];

        /* Sum: '<S222>/Minus4' incorporates:
         *  Sum: '<S222>/Add2'
         *  Sum: '<S222>/Minus'
         */
        rtb_Switch2_h = (rtb_Sin4 + rtb_Minus_n[1]) - rtb_Minus_f;

        /* Sum: '<S222>/Minus5' incorporates:
         *  Concatenate: '<S204>/Matrix Concatenate2'
         *  Sum: '<S222>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Reshapey[1] - rtb_Minus_f;

        /* Sum: '<S222>/Add' incorporates:
         *  Sum: '<S222>/Add2'
         *  Sum: '<S222>/Minus1'
         */
        rtb_Switch1_n = rtb_Init_o - rtb_Minus_n[1];

        /* Sum: '<S222>/Minus' incorporates:
         *  Sum: '<S222>/Minus1'
         */
        rtb_Minus_f -= rtb_Switch1_n;

        /* DotProduct: '<S222>/Dot Product' incorporates:
         *  Concatenate: '<S204>/Matrix Concatenate2'
         *  Sum: '<S222>/Minus'
         *  Sum: '<S222>/Minus1'
         *  Sum: '<S222>/Minus5'
         */
        rtb_Switch2_hw += (rtb_Reshapey[1] - rtb_Switch1_n) * rtb_Minus_f;

        /* RelationalOperator: '<S223>/Compare' incorporates:
         *  Constant: '<S223>/Constant'
         */
        rtb_LogicalOperator5 = (rtb_Switch2_hw >= 0.0);

        /* RelationalOperator: '<S222>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S222>/Dot Product1'
         *  Sum: '<S222>/Minus'
         */
        rtb_Compare_pb = (rtb_Switch2_hw <= ((rtb_Minus_f * rtb_Minus_f) +
          rtb_Init));

        /* DotProduct: '<S222>/Dot Product2' incorporates:
         *  Sum: '<S222>/Minus4'
         *  Sum: '<S222>/Minus5'
         */
        rtb_Switch2_hw = (rtb_Switch2_h * rtb_MatrixConcatenate_b_idx_0) +
          rtb_Minus_k_idx_0;

        /* Merge: '<S208>/Merge4' incorporates:
         *  Constant: '<S224>/Constant'
         *  DataTypeConversion: '<S214>/Data Type Conversion'
         *  DotProduct: '<S222>/Dot Product3'
         *  Logic: '<S222>/AND'
         *  RelationalOperator: '<S222>/LessThanOrEqual1'
         *  RelationalOperator: '<S224>/Compare'
         *  Sum: '<S214>/Add'
         *  Sum: '<S222>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_LogicalOperator5 &&
          rtb_Compare_pb) && (rtb_Switch2_hw >= 0.0)) && (rtb_Switch2_hw <=
          ((rtb_Switch2_h * rtb_Switch2_h) + rtb_Minus_k_idx_1)))) +
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S208>/Merge2' incorporates:
         *  Constant: '<S214>/Constant2'
         *  SignalConversion generated from: '<S214>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S214>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S214>/Constant1'
         */
        rtb_Compare_pb = false;

        /* End of Outputs for SubSystem: '<S211>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S211>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S212>/Action Port'
         */
        /* Merge: '<S208>/Merge2' incorporates:
         *  Constant: '<S212>/Constant2'
         *  SignalConversion generated from: '<S212>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator5 = false;

        /* SignalConversion generated from: '<S212>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S212>/Constant1'
         */
        rtb_Compare_pb = false;

        /* Merge: '<S208>/Merge4' incorporates:
         *  SignalConversion generated from: '<S212>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S211>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S208>/Merge1' incorporates:
       *  Constant: '<S211>/Constant'
       *  SignalConversion generated from: '<S211>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S211>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator1;

      /* End of Outputs for SubSystem: '<S208>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S208>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S210>/Action Port'
       */
      /* Merge: '<S208>/Merge1' incorporates:
       *  Constant: '<S210>/Constant'
       *  SignalConversion generated from: '<S210>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S208>/Merge2' incorporates:
       *  Constant: '<S210>/Constant1'
       *  SignalConversion generated from: '<S210>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator5 = false;

      /* SignalConversion generated from: '<S210>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S210>/Constant2'
       */
      rtb_Compare_pb = false;

      /* Merge: '<S208>/Merge4' incorporates:
       *  SignalConversion generated from: '<S210>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S208>/Escape_Auto_Driving' */
    }

    /* End of If: '<S208>/If' */

    /* If: '<S204>/If1' */
    if (!rtb_Compare_pb) {
      /* Outputs for IfAction SubSystem: '<S204>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S209>/Action Port'
       */
      /* Bias: '<S225>/Add Constant' incorporates:
       *  Bias: '<S225>/Bias'
       *  Sum: '<S225>/Subtract'
       */
      rtb_Switch1_n = ((Robot_Control_B.Spline_Num_Poses -
                        Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S225>/Selector4' incorporates:
       *  Bias: '<S225>/Bias1'
       *  Constant: '<S227>/FixPt Constant'
       *  Sum: '<S227>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;
      rtb_Minus_n[1] = Robot_Control_B.Spline_Num_Poses + 2.0;

      /* SignalConversion generated from: '<S225>/Selector5' */
      rtb_Reshapey[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S225>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)rtb_Reshapey[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s230_iter = ((int32_T)rtb_Reshapey[1]) - 1;

      /* Concatenate: '<S225>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S225>/Selector5' incorporates:
       *  Concatenate: '<S225>/Matrix Concatenate'
       *  Gain: '<S229>/Gain'
       *  Selector: '<S204>/Selector1'
       *  Selector: '<S225>/Selector2'
       *  Selector: '<S225>/Selector3'
       *  Sum: '<S229>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (rtb_Bias1_p = 0; rtb_Bias1_p <= s230_iter; rtb_Bias1_p++) {
          rtb_Selector5[rtb_Bias1_p + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[rtb_Bias1_p + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S225>/Matrix Concatenate' incorporates:
       *  Bias: '<S225>/Add Constant1'
       *  Gain: '<S228>/Gain'
       *  Selector: '<S204>/Selector1'
       *  Selector: '<S225>/Selector'
       *  Selector: '<S225>/Selector1'
       *  Selector: '<S225>/Selector5'
       *  Sum: '<S228>/Subtract'
       */
      s230_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < s230_iter;
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

      /* Selector: '<S225>/Selector4' */
      s230_iter = ((int32_T)rtb_Minus_n[1]) - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s230_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S225>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S225>/Selector4' */
      rtb_Bias1_p = (int32_T)rtb_Minus_n[0];

      /* Assignment: '<S225>/Assignment' incorporates:
       *  Concatenate: '<S225>/Matrix Concatenate'
       *  Selector: '<S225>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s230_iter;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + rtb_Bias1_p) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S226>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S230>/While Iterator'
       */
      s230_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s230_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s230_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s230_iter] - rtb_Assignment[s230_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Init - rtb_Assignment[s230_iter];
        rtb_Init = rtb_Assignment[s230_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s230_iter + 11];
        rtb_Minus_f = rtb_Assignment[s230_iter + 12];
        rtb_Add2[1] = rtb_Minus_f - rtb_Assignment[s230_iter + 14];
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
            rtb_Switch2_h)) + rtb_Assignment[s230_iter];
          rtb_Switch2_h = ((((rtb_Minus_n[1] * rtb_Sin4) + (rtb_Add2[1] *
            rtb_Init)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_h)) +
            rtb_Minus_f;
          rtb_Sin4 = ((3.0 * rtb_Init_o) - (4.0 * rtb_Switch2_hw)) + 1.0;
          rtb_Init = (2.0 * rtb_Switch2_hw) - (3.0 * rtb_Init_o);
          rtb_Init_o = (rtb_Switch2_hw - rtb_Init_o) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Sin4) +
            (rtb_Add2[0] * rtb_Init)) * 0.5) + (rtb_Minus_k_idx_0 * rtb_Init_o);
          rtb_Hypot_g5 = (((rtb_Minus_n[1] * rtb_Sin4) + (rtb_Add2[1] * rtb_Init))
                          * 0.5) + (rtb_Minus_k_idx_1 * rtb_Init_o);
          rtb_Init_o = (6.0 * rtb_Switch2_hw) - 4.0;
          rtb_Sin4 = (-6.0 * rtb_Switch2_hw) + 2.0;
          rtb_Switch2_hw = (-12.0 * rtb_Switch2_hw) + 6.0;
          rtb_Init = (((rtb_Minus_n[0] * rtb_Init_o) + (rtb_Add2[0] * rtb_Sin4))
                      * 0.5) + (rtb_Minus_k_idx_0 * rtb_Switch2_hw);
          rtb_Sin4 = (((rtb_Minus_n[1] * rtb_Init_o) + (rtb_Add2[1] * rtb_Sin4))
                      * 0.5) + (rtb_Minus_k_idx_1 * rtb_Switch2_hw);
          rtb_Init_o = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Hypot_g5), 3.0);
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
            ((rtb_MatrixConcatenate_idx_0 * rtb_Sin4) - (rtb_Init * rtb_Hypot_g5))
            / (rtb_Switch2_hw * ((real_T)i));
        }

        if (s230_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s230_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Switch2_hw = rtb_Switch1_n - ((real_T)s230_iter);
        rtb_Num_Segments = s230_iter;
        s230_iter++;
      } while ((rtb_Switch2_hw >= 4.0) && (s230_iter <= 3));

      /* End of Outputs for SubSystem: '<S226>/Sampling_Loop' */

      /* SignalConversion generated from: '<S209>/Position_and_Curvature' incorporates:
       *  Assignment: '<S230>/Assignment'
       *  Merge: '<S204>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S204>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S204>/If Action Subsystem' incorporates:
       *  ActionPort: '<S207>/Action Port'
       */
      /* Product: '<S207>/Product' incorporates:
       *  Selector: '<S204>/Selector'
       *  Selector: '<S204>/Selector1'
       */
      rtb_Switch2_hw = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S207>/Product1' incorporates:
       *  Selector: '<S204>/Selector'
       *  Selector: '<S204>/Selector1'
       */
      rtb_Switch1_n = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        + 9];
      for (i = 0; i < 50; i++) {
        /* Product: '<S207>/Product' incorporates:
         *  Constant: '<S207>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Switch2_hw;

        /* Product: '<S207>/Product1' incorporates:
         *  Constant: '<S207>/Constant2'
         *  Product: '<S207>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Switch1_n;
      }

      /* Assignment: '<S207>/Assignment' incorporates:
       *  Concatenate: '<S207>/Matrix Concatenate'
       *  Merge: '<S204>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S207>/Assignment' */

      /* SignalConversion generated from: '<S207>/Num_Segments' incorporates:
       *  Constant: '<S207>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S204>/If Action Subsystem' */
    }

    /* End of If: '<S204>/If1' */

    /* Concatenate: '<S205>/Matrix Concatenate' incorporates:
     *  Merge: '<S204>/Merge'
     *  Selector: '<S205>/Selector'
     *  Selector: '<S205>/Selector1'
     *  Selector: '<S205>/Selector3'
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

    /* End of Concatenate: '<S205>/Matrix Concatenate' */

    /* MATLAB Function: '<S205>/Distance Along Curve' incorporates:
     *  Concatenate: '<S205>/Matrix Concatenate'
     *  Selector: '<S205>/Selector4'
     *  Selector: '<S205>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s230_iter = 0; s230_iter < 149; s230_iter++) {
      /* Outputs for Iterator SubSystem: '<S226>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S230>/While Iterator'
       */
      rtb_Assignment_d[s230_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s230_iter + 1] -
         rtb_MatrixConcatenate_o[s230_iter], rtb_MatrixConcatenate_o[s230_iter +
         151] - rtb_MatrixConcatenate_o[s230_iter + 150]) +
        rtb_Assignment_d[s230_iter];

      /* End of Outputs for SubSystem: '<S226>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S205>/Distance Along Curve' */

    /* MATLAB Function: '<S205>/Find closest index to curve' incorporates:
     *  Concatenate: '<S205>/Matrix Concatenate'
     *  Selector: '<S205>/Selector4'
     *  Selector: '<S205>/Selector5'
     *  Selector: '<S256>/Selector'
     */
    for (s230_iter = 0; s230_iter < 150; s230_iter++) {
      /* Outputs for Iterator SubSystem: '<S226>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S230>/While Iterator'
       */
      distance_from_robot[s230_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s230_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s230_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S226>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s230_iter = 1;
    } else {
      s230_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s230_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s230_iter == 0) {
      rtb_Switch1_n = distance_from_robot[0];
    } else {
      rtb_Switch1_n = distance_from_robot[s230_iter - 1];
      for (rtb_Bias1_p = s230_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Switch2_hw = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Switch1_n > rtb_Switch2_hw) {
          rtb_Switch1_n = rtb_Switch2_hw;
        }
      }
    }

    s230_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s230_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Switch1_n) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S256>/Selector' incorporates:
     *  Constant: '<S256>/Constant'
     *  MATLAB Function: '<S205>/Find closest index to curve'
     *  MinMax: '<S256>/Min'
     */
    rtb_Switch2_hw = rtb_Assignment_d[((int32_T)fmin(50.0, s230_iter)) - 1];

    /* If: '<S256>/If' incorporates:
     *  RelationalOperator: '<S256>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S256>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S259>/Action Port'
       */
      /* SignalConversion generated from: '<S259>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S261>/FixPt Sum1' incorporates:
       *  Constant: '<S261>/FixPt Constant'
       */
      rtb_Switch1_n = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S259>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S259>/Selector11'
       *  Selector: '<S259>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S259>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S259>/Selector1'
       *  Selector: '<S259>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Switch1_n) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S259>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S259>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Switch1_n), &rtb_Minus_n[0], rtb_Switch2_hw,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S259>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S259>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S259>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Switch2_hw,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S256>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S256>/Latch' incorporates:
       *  ActionPort: '<S260>/Action Port'
       */
      /* SignalConversion generated from: '<S260>/In1' incorporates:
       *  UnitDelay: '<S256>/Unit Delay1'
       */
      rtb_Switch1_n = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S260>/In2' incorporates:
       *  UnitDelay: '<S256>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S256>/Latch' */
    }

    /* End of If: '<S256>/If' */

    /* MinMax: '<S203>/Min' incorporates:
     *  Lookup_n-D: '<S203>/Lookahead Distance'
     *  UnitDelay: '<S203>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_hn, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S205>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S255>/While Iterator'
     */
    s255_iter = 1U;
    rtb_LogicalOperator1 = true;
    while (rtb_LogicalOperator1 && (s255_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S205>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S255>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s255_iter;
      rtb_LogicalOperator1 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s230_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s255_iter++;
    }

    /* End of Outputs for SubSystem: '<S205>/Find first index that meets distance target' */

    /* Switch: '<S258>/Switch' incorporates:
     *  Concatenate: '<S205>/Matrix Concatenate'
     *  Constant: '<S205>/Constant'
     *  Constant: '<S255>/Constant'
     *  Constant: '<S258>/Constant'
     *  Constant: '<S258>/Constant1'
     *  Constant: '<S258>/Constant2'
     *  Constant: '<S258>/Constant3'
     *  Logic: '<S255>/AND'
     *  MATLAB Function: '<S205>/Find closest index to curve'
     *  Math: '<S258>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S258>/Max'
     *  MinMax: '<S258>/Min'
     *  MinMax: '<S258>/Min1'
     *  Product: '<S255>/Product'
     *  Product: '<S258>/Divide'
     *  Product: '<S258>/Product'
     *  Product: '<S258>/Product1'
     *  RelationalOperator: '<S205>/Relational Operator'
     *  RelationalOperator: '<S255>/Relational Operator'
     *  RelationalOperator: '<S255>/Relational Operator1'
     *  Selector: '<S205>/Selector10'
     *  Selector: '<S205>/Selector7'
     *  Selector: '<S205>/Selector8'
     *  Selector: '<S205>/Selector9'
     *  Selector: '<S255>/Selector'
     *  Selector: '<S255>/Selector1'
     *  Selector: '<S256>/Selector'
     *  Sqrt: '<S258>/Sqrt'
     *  Sum: '<S205>/Subtract'
     *  Sum: '<S255>/Add'
     *  Sum: '<S258>/Subtract'
     *  Sum: '<S258>/Subtract1'
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

    /* End of Switch: '<S258>/Switch' */

    /* Logic: '<S206>/OR' */
    rtb_Compare_pb = (rtb_LogicalOperator5 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S206>/Switch1' incorporates:
     *  Switch: '<S206>/Switch'
     *  UnitDelay: '<S206>/Unit Delay'
     */
    if (rtb_Compare_pb) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S206>/Constant3'
       *  SignalConversion: '<S206>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Switch2_hw = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S206>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Switch2_hw = rtb_Merge1;
    }

    /* End of Switch: '<S206>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S206>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Switch2_hw;

    /* Selector: '<S205>/Selector6' incorporates:
     *  Concatenate: '<S205>/Matrix Concatenate'
     *  Selector: '<S205>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S205>/Selector2' incorporates:
     *  Concatenate: '<S205>/Matrix Concatenate'
     *  Selector: '<S205>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S206>/Switch2' incorporates:
     *  Sum: '<S262>/Subtract'
     *  Sum: '<S262>/Subtract1'
     *  Trigonometry: '<S262>/Atan2'
     *  UnitDelay: '<S206>/Unit Delay1'
     */
    if (rtb_Compare_pb) {
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Init_o = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S206>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S206>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Init_o;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S203>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator5;

    /* Merge: '<S13>/Merge6' incorporates:
     *  SignalConversion: '<S203>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S206>/Constant2'
     *  SignalConversion generated from: '<S203>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S206>/Constant5'
     *  SignalConversion generated from: '<S203>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S206>/Constant6'
     *  SignalConversion generated from: '<S203>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S203>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S204>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S203>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Saturation_h;

    /* Update for UnitDelay: '<S256>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Switch1_n;

    /* Update for UnitDelay: '<S256>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S206>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Switch2_hw;

    /* Update for UnitDelay: '<S206>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_kc = rtb_Init_o;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    /* Merge: '<S13>/Merge6' incorporates:
     *  Constant: '<S202>/Constant1'
     *  SignalConversion generated from: '<S202>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S202>/Constant'
     *  SignalConversion generated from: '<S202>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S202>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S202>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S202>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S202>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S202>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Compare_mq;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S202>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S202>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S352>/Sign2' incorporates:
   *  UnitDelay: '<S352>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Minus_f = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Minus_f = -1.0;
  } else {
    rtb_Minus_f = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S352>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Hypot_g5 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Hypot_g5 = -1.0;
  } else {
    rtb_Hypot_g5 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S352>/Product1' incorporates:
   *  Signum: '<S352>/Sign1'
   *  Signum: '<S352>/Sign2'
   */
  rtb_Minus_f *= rtb_Hypot_g5;
  if (rtIsNaN(rtb_Minus_f)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Minus_f, 256.0);
  }

  /* Switch: '<S352>/Switch' incorporates:
   *  Constant: '<S352>/Constant'
   *  Constant: '<S357>/Constant'
   *  Constant: '<S358>/Constant'
   *  Logic: '<S352>/or'
   *  Product: '<S352>/Product1'
   *  RelationalOperator: '<S357>/Compare'
   *  RelationalOperator: '<S358>/Compare'
   *  UnitDelay: '<S352>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S352>/Switch' */

  /* Switch: '<S363>/Init' incorporates:
   *  UnitDelay: '<S363>/FixPt Unit Delay1'
   *  UnitDelay: '<S363>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_o != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S363>/Init' */

  /* RelationalOperator: '<S359>/Compare' incorporates:
   *  Constant: '<S359>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S360>/Compare' incorporates:
   *  Constant: '<S360>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Sin4 > 0.0);

  /* Abs: '<S352>/Abs' incorporates:
   *  Sum: '<S352>/Subtract'
   *  UnitDelay: '<S352>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S352>/Switch5' incorporates:
   *  Constant: '<S352>/Constant1'
   *  Switch: '<S352>/Switch1'
   *  UnaryMinus: '<S352>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S352>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S352>/Constant4'
     *  Constant: '<S352>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S352>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S352>/Constant2'
     *  Constant: '<S352>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S352>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S352>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S352>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S352>/Constant10'
     *  Constant: '<S352>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S352>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S352>/Constant7'
     *  Constant: '<S352>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S352>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S352>/Lookup Table Dynamic1'
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

    /* Switch: '<S352>/Switch3' incorporates:
     *  Constant: '<S352>/Constant1'
     *  Constant: '<S352>/Constant3'
     *  UnaryMinus: '<S352>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      rtb_Minus_f = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Minus_f = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S352>/Switch3' */
  }

  /* End of Switch: '<S352>/Switch5' */

  /* Product: '<S352>/Product' incorporates:
   *  Switch: '<S352>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Minus_f * rtb_Merge1;

  /* Sum: '<S361>/Sum1' */
  rtb_Saturation_h = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S362>/Switch2' incorporates:
   *  RelationalOperator: '<S362>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S352>/Switch2' incorporates:
     *  Constant: '<S352>/Constant1'
     *  Switch: '<S352>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S352>/Switch4' incorporates:
       *  Constant: '<S352>/Constant1'
       */
      rtb_Switch1_n = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S352>/Switch4' incorporates:
       *  Constant: '<S352>/Constant3'
       *  UnaryMinus: '<S352>/Unary Minus1'
       */
      rtb_Switch1_n = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S352>/Switch2' */

    /* Product: '<S352>/Product2' */
    rtb_Switch1_n *= rtb_Merge1;

    /* Switch: '<S362>/Switch' incorporates:
     *  RelationalOperator: '<S362>/UpperRelop'
     */
    if (rtb_Saturation_h < rtb_Switch1_n) {
      rtb_Optimized_Module_Angle = rtb_Switch1_n;
    } else {
      rtb_Optimized_Module_Angle = rtb_Saturation_h;
    }

    /* End of Switch: '<S362>/Switch' */
  }

  /* End of Switch: '<S362>/Switch2' */

  /* Sum: '<S361>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S355>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S355>/Switch' incorporates:
     *  Constant: '<S389>/Constant3'
     *  Constant: '<S389>/Constant4'
     *  Math: '<S389>/Math Function'
     *  Sum: '<S355>/Subtract'
     *  Sum: '<S389>/Add1'
     *  Sum: '<S389>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S355>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S355>/Switch' */

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

  /* Switch: '<S184>/Switch' incorporates:
   *  Constant: '<S172>/Constant'
   *  Constant: '<S184>/Constant'
   *  RelationalOperator: '<S172>/Compare'
   *  UnitDelay: '<S184>/Unit Delay'
   */
  if (rtb_GameState != 1) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_o;
  }

  /* Sum: '<S184>/Sum' incorporates:
   *  Constant: '<S184>/Constant4'
   *  Switch: '<S184>/Switch'
   */
  rtb_Merge1 = rtb_Minus_f + 0.02;

  /* Switch: '<S185>/Switch' incorporates:
   *  Constant: '<S177>/Constant'
   *  Constant: '<S185>/Constant'
   *  RelationalOperator: '<S177>/Compare'
   *  UnitDelay: '<S185>/Unit Delay'
   */
  if (rtb_GameState != 2) {
    rtb_Minus_f = 0.0;
  } else {
    rtb_Minus_f = Robot_Control_DW.UnitDelay_DSTATE_m;
  }

  /* MultiPortSwitch: '<S135>/Multiport Switch' incorporates:
   *  Constant: '<S135>/Constant1'
   *  Constant: '<S135>/Constant3'
   *  Constant: '<S185>/Constant4'
   *  Sum: '<S185>/Sum'
   *  Switch: '<S185>/Switch'
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

  /* End of MultiPortSwitch: '<S135>/Multiport Switch' */

  /* If: '<S135>/If' incorporates:
   *  Constant: '<S170>/Constant'
   *  Constant: '<S171>/Constant'
   *  Constant: '<S173>/Constant'
   *  Constant: '<S174>/Constant'
   *  Constant: '<S175>/Constant'
   *  Constant: '<S176>/Constant'
   *  Inport: '<Root>/IsBlueAlliance'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  RelationalOperator: '<S170>/Compare'
   *  RelationalOperator: '<S171>/Compare'
   *  RelationalOperator: '<S173>/Compare'
   *  RelationalOperator: '<S174>/Compare'
   *  RelationalOperator: '<S175>/Compare'
   *  RelationalOperator: '<S176>/Compare'
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
      /* InitializeConditions for IfAction SubSystem: '<S135>/If Action Subsystem' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      /* InitializeConditions for If: '<S135>/If' incorporates:
       *  UnitDelay: '<S178>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

      /* End of InitializeConditions for SubSystem: '<S135>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Merge: '<S135>/Merge' incorporates:
     *  Constant: '<S178>/Constant'
     *  SignalConversion generated from: '<S178>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S135>/Merge1' incorporates:
     *  Constant: '<S178>/Constant'
     *  SignalConversion generated from: '<S178>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S178>/Sum' incorporates:
     *  Constant: '<S178>/Constant1'
     *  UnitDelay: '<S178>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hb - 0.02;

    /* Merge: '<S135>/Merge2' incorporates:
     *  SignalConversion: '<S178>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S178>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S135>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S179>/Action Port'
       */
      /* SystemReset for If: '<S135>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem1);

      /* End of SystemReset for SubSystem: '<S135>/If Action Subsystem1' */
    }

    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem1' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S135>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S180>/Action Port'
       */
      /* InitializeConditions for If: '<S135>/If' incorporates:
       *  UnitDelay: '<S180>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S135>/If Action Subsystem2' */
    }

    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* Sum: '<S180>/Sum' incorporates:
     *  Constant: '<S180>/Constant1'
     *  UnitDelay: '<S180>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_hz - 0.02;

    /* RelationalOperator: '<S187>/Compare' incorporates:
     *  Constant: '<S187>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S135>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S180>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S135>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S180>/Logical Operator1'
     *  Logic: '<S180>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S180>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S180>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S135>/Merge2' incorporates:
       *  Constant: '<S180>/Constant2'
       *  Sum: '<S180>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S135>/Merge2' */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;
    }

    /* End of Switch: '<S180>/Switch' */

    /* Update for UnitDelay: '<S180>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hz = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem2' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S135>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
      /* SystemReset for If: '<S135>/If' */
      Robot__IfActionSubsystem1_Reset(&Robot_Control_DW.IfActionSubsystem3);

      /* End of SystemReset for SubSystem: '<S135>/If Action Subsystem3' */
    }

    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      Robot_Control_U.IsBlueAlliance, &Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive, &Robot_Control_B.RB_Shift_Time_Remaining,
      &Robot_Control_DW.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem3' */
    break;

   case 4:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S135>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S182>/Action Port'
       */
      /* InitializeConditions for If: '<S135>/If' incorporates:
       *  UnitDelay: '<S182>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

      /* End of InitializeConditions for SubSystem: '<S135>/If Action Subsystem4' */
    }

    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    /* Sum: '<S182>/Sum' incorporates:
     *  Constant: '<S182>/Constant1'
     *  UnitDelay: '<S182>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_di - 0.02;

    /* RelationalOperator: '<S189>/Compare' incorporates:
     *  Constant: '<S189>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_Switch1_n <= Rebuilt_Match_Time_Shoot_Early);

    /* Merge: '<S135>/Merge' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S182>/Logical Operator'
     */
    Robot_Control_B.RB_IsBlueActive = ((Robot_Control_U.IsBlueInactiveFirst !=
      0.0) || rtb_LogicalOperator1);

    /* Merge: '<S135>/Merge1' incorporates:
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S182>/Logical Operator1'
     *  Logic: '<S182>/NOT1'
     */
    Robot_Control_B.RB_IsRedActive = ((!(Robot_Control_U.IsBlueInactiveFirst !=
      0.0)) || rtb_LogicalOperator1);

    /* Switch: '<S182>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Inport: '<Root>/IsBlueInactiveFirst'
     *  Logic: '<S182>/Logical Operator2'
     */
    if ((boolean_T)((Robot_Control_U.IsBlueInactiveFirst != 0.0) ^
                    (Robot_Control_U.IsBlueAlliance != 0.0))) {
      /* Merge: '<S135>/Merge2' incorporates:
       *  Constant: '<S182>/Constant2'
       *  Sum: '<S182>/Subtract'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n -
        Rebuilt_Match_Time_Shoot_Early;
    } else {
      /* Merge: '<S135>/Merge2' incorporates:
       *  Constant: '<S182>/Constant3'
       *  Sum: '<S182>/Subtract1'
       */
      Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n +
        Rebuilt_Match_Time_End_Game_Timer;
    }

    /* End of Switch: '<S182>/Switch' */

    /* Update for UnitDelay: '<S182>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem4' */
    break;

   default:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S135>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S183>/Action Port'
       */
      /* InitializeConditions for If: '<S135>/If' incorporates:
       *  UnitDelay: '<S183>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

      /* End of InitializeConditions for SubSystem: '<S135>/If Action Subsystem5' */
    }

    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S183>/Action Port'
     */
    /* Merge: '<S135>/Merge' incorporates:
     *  Constant: '<S183>/Constant'
     *  SignalConversion generated from: '<S183>/IsBlueActive'
     */
    Robot_Control_B.RB_IsBlueActive = true;

    /* Merge: '<S135>/Merge1' incorporates:
     *  Constant: '<S183>/Constant'
     *  SignalConversion generated from: '<S183>/IsRedActive'
     */
    Robot_Control_B.RB_IsRedActive = true;

    /* Sum: '<S183>/Sum' incorporates:
     *  Constant: '<S183>/Constant1'
     *  UnitDelay: '<S183>/Unit Delay'
     */
    rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_du - 0.02;

    /* Merge: '<S135>/Merge2' incorporates:
     *  SignalConversion: '<S183>/Signal Copy'
     */
    Robot_Control_B.RB_Shift_Time_Remaining = rtb_Switch1_n;

    /* Update for UnitDelay: '<S183>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_du = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem5' */
    break;
  }

  /* End of If: '<S135>/If' */

  /* If: '<S191>/If' incorporates:
   *  If: '<S192>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S191>/Blue' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    /* Merge: '<S191>/Merge' incorporates:
     *  Constant: '<S193>/BlueAllianceZoneX'
     *  Logic: '<S193>/AND'
     *  RelationalOperator: '<S193>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S191>/Blue' */

    /* Outputs for IfAction SubSystem: '<S192>/Blue' incorporates:
     *  ActionPort: '<S195>/Action Port'
     */
    /* Merge: '<S192>/Merge' incorporates:
     *  Constant: '<S195>/BlueAllianceZoneX'
     *  RelationalOperator: '<S195>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S192>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S191>/Red' incorporates:
     *  ActionPort: '<S194>/Action Port'
     */
    /* Merge: '<S191>/Merge' incorporates:
     *  Constant: '<S194>/RedAllianceZoneX'
     *  Logic: '<S194>/AND'
     *  RelationalOperator: '<S194>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S191>/Red' */

    /* Outputs for IfAction SubSystem: '<S192>/Red' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    /* Merge: '<S192>/Merge' incorporates:
     *  Constant: '<S196>/RedAllianceZoneX'
     *  RelationalOperator: '<S196>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S192>/Red' */
  }

  /* End of If: '<S191>/If' */

  /* RelationalOperator: '<S139>/GreaterThan' incorporates:
   *  Constant: '<S139>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S139>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S139>/Relational Operator' incorporates:
   *  Abs: '<S139>/Abs'
   *  Constant: '<S190>/Constant3'
   *  Constant: '<S190>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S190>/Math Function'
   *  Sum: '<S139>/Subtract'
   *  Sum: '<S190>/Add1'
   *  Sum: '<S190>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S138>/Max' incorporates:
   *  Abs: '<S138>/Abs1'
   *  Abs: '<S138>/Abs2'
   *  Abs: '<S138>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S139>/Relational Operator1' incorporates:
   *  Abs: '<S139>/Abs1'
   *  Constant: '<S139>/Constant2'
   *  Sum: '<S139>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S139>/Relational Operator4' incorporates:
   *  Abs: '<S139>/Abs4'
   *  Constant: '<S139>/Constant1'
   *  Sum: '<S139>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S139>/AND' incorporates:
   *  Logic: '<S139>/OR'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  rtb_Compare_pb = ((((Robot_Control_B.RB_Logic_Gyro_Angle) ||
                      (Robot_Control_DW.UnitDelay_5_DSTATE)) &&
                     (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                    (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S139>/AND2' incorporates:
   *  Logic: '<S139>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_pb);

  /* RelationalOperator: '<S136>/Compare' incorporates:
   *  Constant: '<S136>/Constant'
   *  Inport: '<Root>/Gamepad_RT'
   */
  rtb_LogicalOperator1 = (Robot_Control_U.Gamepad_RT != 0.0);

  /* SignalConversion: '<S139>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S139>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Compare_pb);

  /* Chart: '<S12>/Shooter_Transfer_Feeder Chart' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Logic: '<S139>/AND4'
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

  /* RelationalOperator: '<S137>/Compare' incorporates:
   *  Constant: '<S137>/Constant'
   *  Inport: '<Root>/Gamepad_B2_B'
   */
  rtb_Compare_ky = (Robot_Control_U.Gamepad_B2_B != 0.0);

  /* Logic: '<S12>/AND' incorporates:
   *  Logic: '<S12>/NOT'
   */
  rtb_Button_Spinup_Enable = ((Robot_Control_B.RB_Shooter_Active) &&
    (!rtb_Compare_ky));

  /* If: '<S134>/If' incorporates:
   *  Constant: '<S144>/Constant'
   */
  if (Robot_Control_B.RB_Shooter_Active) {
    /* Outputs for IfAction SubSystem: '<S134>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S144>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S145>/While Iterator'
     */
    /* SignalConversion generated from: '<S146>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S151>/Constant1'
     *  Constant: '<S151>/Constant10'
     *  Constant: '<S151>/Constant2'
     *  Constant: '<S151>/Constant5'
     *  Constant: '<S151>/Constant6'
     *  Constant: '<S151>/Constant7'
     *  Constant: '<S151>/Constant8'
     *  Constant: '<S151>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S144>/Iterate_Shot_Target' */

    /* SignalConversion generated from: '<S147>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S147>/Constant1'
     *  Constant: '<S147>/Constant10'
     *  Constant: '<S147>/Constant2'
     *  Constant: '<S147>/Constant5'
     *  Constant: '<S147>/Constant6'
     *  Constant: '<S147>/Constant7'
     *  Constant: '<S147>/Constant8'
     *  Constant: '<S147>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_o3[0] = Rebuilt_Shoot_Hood_Pos_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Rebuilt_Shoot_Hood_Pos_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Rebuilt_Shoot_Hood_Pos_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Rebuilt_Shoot_Hood_Pos_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Rebuilt_Shoot_Hood_Pos_4;
    rtb_TmpSignalConversionAtLoo_o3[5] = Rebuilt_Shoot_Hood_Pos_5;
    rtb_TmpSignalConversionAtLoo_o3[6] = Rebuilt_Shoot_Hood_Pos_6;
    rtb_TmpSignalConversionAtLoo_o3[7] = Rebuilt_Shoot_Hood_Pos_7;

    /* SignalConversion generated from: '<S146>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S146>/Constant1'
     *  Constant: '<S146>/Constant10'
     *  Constant: '<S146>/Constant2'
     *  Constant: '<S146>/Constant5'
     *  Constant: '<S146>/Constant6'
     *  Constant: '<S146>/Constant7'
     *  Constant: '<S146>/Constant8'
     *  Constant: '<S146>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ov[0] = Rebuilt_Shoot_Gyro_Err_0;
    rtb_TmpSignalConversionAtLoo_ov[1] = Rebuilt_Shoot_Gyro_Err_1;
    rtb_TmpSignalConversionAtLoo_ov[2] = Rebuilt_Shoot_Gyro_Err_2;
    rtb_TmpSignalConversionAtLoo_ov[3] = Rebuilt_Shoot_Gyro_Err_3;
    rtb_TmpSignalConversionAtLoo_ov[4] = Rebuilt_Shoot_Gyro_Err_4;
    rtb_TmpSignalConversionAtLoo_ov[5] = Rebuilt_Shoot_Gyro_Err_5;
    rtb_TmpSignalConversionAtLoo_ov[6] = Rebuilt_Shoot_Gyro_Err_6;
    rtb_TmpSignalConversionAtLoo_ov[7] = Rebuilt_Shoot_Gyro_Err_7;

    /* SignalConversion generated from: '<S148>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant10'
     *  Constant: '<S160>/Constant2'
     *  Constant: '<S160>/Constant5'
     *  Constant: '<S160>/Constant6'
     *  Constant: '<S160>/Constant7'
     *  Constant: '<S160>/Constant8'
     *  Constant: '<S160>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_lg[0] = Rebuilt_Shoot_Shooter_Spd_0;
    rtb_TmpSignalConversionAtLoo_lg[1] = Rebuilt_Shoot_Shooter_Spd_1;
    rtb_TmpSignalConversionAtLoo_lg[2] = Rebuilt_Shoot_Shooter_Spd_2;
    rtb_TmpSignalConversionAtLoo_lg[3] = Rebuilt_Shoot_Shooter_Spd_3;
    rtb_TmpSignalConversionAtLoo_lg[4] = Rebuilt_Shoot_Shooter_Spd_4;
    rtb_TmpSignalConversionAtLoo_lg[5] = Rebuilt_Shoot_Shooter_Spd_5;
    rtb_TmpSignalConversionAtLoo_lg[6] = Rebuilt_Shoot_Shooter_Spd_6;
    rtb_TmpSignalConversionAtLoo_lg[7] = Rebuilt_Shoot_Shooter_Spd_7;

    /* SignalConversion generated from: '<S148>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S159>/Constant1'
     *  Constant: '<S159>/Constant10'
     *  Constant: '<S159>/Constant2'
     *  Constant: '<S159>/Constant5'
     *  Constant: '<S159>/Constant6'
     *  Constant: '<S159>/Constant7'
     *  Constant: '<S159>/Constant8'
     *  Constant: '<S159>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_ix[0] = Rebuilt_Shoot_Shooter_Spd_I_0;
    rtb_TmpSignalConversionAtLoo_ix[1] = Rebuilt_Shoot_Shooter_Spd_I_1;
    rtb_TmpSignalConversionAtLoo_ix[2] = Rebuilt_Shoot_Shooter_Spd_I_2;
    rtb_TmpSignalConversionAtLoo_ix[3] = Rebuilt_Shoot_Shooter_Spd_I_3;
    rtb_TmpSignalConversionAtLoo_ix[4] = Rebuilt_Shoot_Shooter_Spd_I_4;
    rtb_TmpSignalConversionAtLoo_ix[5] = Rebuilt_Shoot_Shooter_Spd_I_5;
    rtb_TmpSignalConversionAtLoo_ix[6] = Rebuilt_Shoot_Shooter_Spd_I_6;
    rtb_TmpSignalConversionAtLoo_ix[7] = Rebuilt_Shoot_Shooter_Spd_I_7;

    /* Switch: '<S150>/Switch4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S150>/Logical Operator'
     *  Switch: '<S150>/Switch5'
     *  Switch: '<S150>/Switch6'
     */
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

    /* End of Switch: '<S150>/Switch4' */

    /* Outputs for Iterator SubSystem: '<S144>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S145>/While Iterator'
     */
    Iteration_Number = 1U;

    /* InitializeConditions for Memory: '<S145>/Memory1' */
    rtb_Switch1_n = 0.0;

    /* InitializeConditions for Memory: '<S145>/Memory2' */
    rtb_Switch2_hw = 0.0;

    /* InitializeConditions for Memory: '<S145>/Memory3' */
    rtb_Init_o = 0.0;

    /* InitializeConditions for Memory: '<S145>/Memory' */
    rtb_LogicalOperator5 = true;
    rtb_LogicalOperator1 = true;

    /* SignalConversion generated from: '<S153>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S144>/Constant'
     *  Constant: '<S153>/Constant'
     *  Constant: '<S153>/Constant1'
     *  Constant: '<S153>/Constant11'
     *  Constant: '<S153>/Constant2'
     *  Constant: '<S153>/Constant3'
     *  Constant: '<S153>/Constant4'
     *  Constant: '<S153>/Constant5'
     *  Constant: '<S153>/Constant6'
     */
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;

    /* SignalConversion generated from: '<S153>/Lookup Table Dynamic' */
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_LogicalOperator1 && (Iteration_Number <= 10)) {
      /* Switch: '<S154>/Switch' incorporates:
       *  Memory: '<S145>/Memory1'
       *  Memory: '<S145>/Memory2'
       *  Switch: '<S154>/Switch1'
       */
      if (Iteration_Number > 1) {
        rtb_Sin4 = rtb_Switch1_n;
        rtb_Init = rtb_Switch2_hw;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Init = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S154>/Switch' */

      /* Math: '<S152>/Hypot' incorporates:
       *  Sum: '<S152>/Subtract'
       *  Sum: '<S152>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_Init - Robot_Control_B.KF_Position_Y);

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
      rtb_Switch2_hw = rtb_TOF - rtb_Init_o;

      /* Sum: '<S155>/Add' incorporates:
       *  Gain: '<S155>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S155>/Product'
       *  Sum: '<S155>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Switch2_hw *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S155>/Add1' incorporates:
       *  Gain: '<S155>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S155>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Switch2_hw *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Init;

      /* Memory: '<S145>/Memory' */
      rtb_LogicalOperator1 = rtb_LogicalOperator5;

      /* Update for Memory: '<S145>/Memory1' */
      rtb_Switch1_n = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S145>/Memory2' */
      rtb_Switch2_hw = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S145>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S145>/Memory' incorporates:
       *  Constant: '<S157>/Constant'
       *  Math: '<S156>/Hypot'
       *  RelationalOperator: '<S157>/Compare'
       *  Sum: '<S156>/Subtract'
       *  Sum: '<S156>/Subtract1'
       */
      rtb_LogicalOperator5 = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X
        - rtb_Sin4, Robot_Control_B.RB_Desired_Target_Y - rtb_Init) >=
        Rebuilt_Shoot_Target_Error_Thresh);
      Iteration_Number++;
    }

    /* End of Outputs for SubSystem: '<S144>/Iterate_Shot_Target' */

    /* Merge: '<S134>/Merge2' incorporates:
     *  S-Function (sfix_look1_dyn): '<S147>/Lookup Table Dynamic'
     */
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

    /* S-Function (sfix_look1_dyn): '<S146>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S146>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S148>/Lookup Table Dynamic' */
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

    /* S-Function (sfix_look1_dyn): '<S148>/Lookup Table Dynamic1' */
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

    /* Switch: '<S148>/Switch' incorporates:
     *  Constant: '<S148>/Constant'
     *  Constant: '<S148>/Constant1'
     *  Sum: '<S148>/Add'
     *  UnitDelay: '<S148>/Unit Delay'
     */
    if (Robot_Control_B.RB_Transfer_Init != 0.0) {
      rtb_Switch1_n = 0.0;
    } else {
      rtb_Switch1_n = Robot_Control_DW.UnitDelay_DSTATE_bb + 0.02;
    }

    /* End of Switch: '<S148>/Switch' */

    /* Switch: '<S148>/Switch1' incorporates:
     *  Constant: '<S148>/Constant2'
     *  RelationalOperator: '<S148>/GreaterThan'
     */
    if (rtb_Switch1_n < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S134>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S134>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    /* End of Switch: '<S148>/Switch1' */

    /* Merge: '<S134>/Merge3' incorporates:
     *  Gain: '<S158>/Gain1'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_Switch_cn;

    /* Trigonometry: '<S161>/Atan1' incorporates:
     *  Constant: '<S161>/Constant'
     *  Constant: '<S161>/Constant1'
     *  Sum: '<S161>/Subtract3'
     *  Sum: '<S161>/Subtract4'
     */
    rtb_Switch_cn = rt_atan2d_snf(0.0 - Robot_Control_B.KF_Position_Y, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S161>/Mod' incorporates:
     *  Constant: '<S161>/Constant4'
     */
    rtb_Switch2_hw = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Sum: '<S161>/Subtract2' incorporates:
     *  Constant: '<S149>/Constant10'
     *  Sum: '<S161>/Subtract8'
     */
    rtb_Init = Field_Length - Robot_Control_B.KF_Position_X;

    /* Trigonometry: '<S161>/Atan2' incorporates:
     *  Constant: '<S161>/Constant2'
     *  Sum: '<S161>/Subtract1'
     *  Sum: '<S161>/Subtract2'
     */
    rtb_Switch_cn = rt_atan2d_snf(0.0 - Robot_Control_B.KF_Position_Y, rtb_Init);

    /* Math: '<S161>/Mod1' incorporates:
     *  Constant: '<S161>/Constant5'
     */
    rtb_Init_o = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Sum: '<S161>/Subtract5' incorporates:
     *  Constant: '<S149>/Constant11'
     *  Sum: '<S161>/Subtract7'
     */
    rtb_Switch2_h = Field_Width - Robot_Control_B.KF_Position_Y;

    /* Trigonometry: '<S161>/Atan3' incorporates:
     *  Constant: '<S161>/Constant3'
     *  Sum: '<S161>/Subtract5'
     *  Sum: '<S161>/Subtract6'
     */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch2_h, 0.0 -
      Robot_Control_B.KF_Position_X);

    /* Math: '<S161>/Mod2' incorporates:
     *  Constant: '<S161>/Constant6'
     */
    rtb_Sin4 = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Trigonometry: '<S161>/Atan4' */
    rtb_Switch_cn = rt_atan2d_snf(rtb_Switch2_h, rtb_Init);

    /* Math: '<S161>/Mod3' incorporates:
     *  Constant: '<S161>/Constant7'
     */
    rtb_Init = rt_modd_snf(rtb_Switch_cn, 6.2831853071795862);

    /* Merge: '<S134>/Merge' incorporates:
     *  Constant: '<S165>/Constant'
     *  Constant: '<S165>/Shooter Assembly Offset in Robot'
     *  Constant: '<S165>/Shooter Assembly Offset in Robot1'
     *  Gain: '<S169>/Gain1'
     *  MinMax: '<S165>/Max'
     *  Product: '<S165>/Divide'
     *  Sum: '<S165>/Add'
     *  Sum: '<S165>/Subtract1'
     *  Sum: '<S165>/Subtract2'
     *  Trigonometry: '<S165>/Atan2'
     *  Trigonometry: '<S165>/Tanh1'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = (rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      atan(-0.074675999999999992 / fmax(Robot_Control_B.RB_Desired_Shot_Distance,
      0.001))) + (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);

    /* Switch: '<S164>/Switch1' incorporates:
     *  Constant: '<S149>/Constant3'
     *  Constant: '<S149>/Constant7'
     *  Inport: '<Root>/IsBlueAlliance'
     */
    if (Robot_Control_U.IsBlueAlliance > 0.0) {
      rtb_Switch_cn = Blue_Hub_LeftY;
    } else {
      rtb_Switch_cn = Red_Hub_LeftY;
    }

    /* End of Switch: '<S164>/Switch1' */

    /* Sum: '<S162>/Subtract3' */
    rtb_Switch2_h = rtb_Switch_cn - Robot_Control_B.KF_Position_Y;

    /* Switch: '<S164>/Switch' incorporates:
     *  Constant: '<S149>/Constant2'
     *  Constant: '<S149>/Constant4'
     *  Constant: '<S149>/Constant5'
     *  Constant: '<S149>/Constant6'
     *  Constant: '<S149>/Constant8'
     *  Constant: '<S149>/Constant9'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Switch: '<S164>/Switch2'
     *  Switch: '<S164>/Switch3'
     */
    if (Robot_Control_U.IsBlueAlliance > 0.0) {
      rtb_Switch_cn = Blue_Hub_LeftX;
      rtb_Hypot_g5 = Blue_Hub_RightX;
      rtb_MatrixConcatenate_idx_0 = Blue_Hub_RightY;
    } else {
      rtb_Switch_cn = Red_Hub_LeftX;
      rtb_Hypot_g5 = Red_Hub_RightX;
      rtb_MatrixConcatenate_idx_0 = Red_Hub_RightY;
    }

    /* End of Switch: '<S164>/Switch' */

    /* Math: '<S162>/Mod1' incorporates:
     *  Constant: '<S162>/Constant'
     *  Sum: '<S162>/Subtract4'
     *  Trigonometry: '<S162>/Atan1'
     */
    rtb_Switch_cn = rt_modd_snf(rt_atan2d_snf(rtb_Switch2_h, rtb_Switch_cn -
      Robot_Control_B.KF_Position_X), 6.2831853071795862);

    /* Math: '<S162>/Mod2' incorporates:
     *  Constant: '<S162>/Constant1'
     *  Sum: '<S162>/Subtract1'
     *  Sum: '<S162>/Subtract2'
     *  Switch: '<S164>/Switch2'
     *  Switch: '<S164>/Switch3'
     *  Trigonometry: '<S162>/Atan3'
     */
    rtb_Switch2_h = rt_modd_snf(rt_atan2d_snf(rtb_Hypot_g5 -
      Robot_Control_B.KF_Position_Y, rtb_MatrixConcatenate_idx_0 -
      Robot_Control_B.KF_Position_X), 6.2831853071795862);

    /* Switch: '<S162>/Switch' incorporates:
     *  Abs: '<S162>/Abs'
     *  Abs: '<S162>/Abs1'
     *  RelationalOperator: '<S162>/GreaterThan'
     */
    if (!(rtb_Switch_cn < rtb_Switch2_h)) {
      /* Abs: '<S149>/Abs1' */
      rtb_Switch_cn = rtb_Switch2_h;
    }

    /* End of Switch: '<S162>/Switch' */

    /* Math: '<S149>/Math Function' incorporates:
     *  Constant: '<S149>/Constant1'
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Switch2_h = rt_modd_snf(Robot_Control_U.Gyro_Angle_Field_rad,
      6.2831853071795862);

    /* If: '<S163>/If' incorporates:
     *  Switch: '<S168>/Switch'
     */
    if (Robot_Control_B.RB_Desired_Target_Y > 4.0345) {
      /* Outputs for IfAction SubSystem: '<S163>/If Action Subsystem' incorporates:
       *  ActionPort: '<S167>/Action Port'
       */
      /* Switch: '<S167>/Switch' */
      if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
        /* Abs: '<S149>/Abs' */
        rtb_Switch2_hw = rtb_Init;
      } else {
        /* Abs: '<S149>/Abs' */
        rtb_Switch2_hw = rtb_Sin4;
      }

      /* End of Switch: '<S167>/Switch' */
      /* End of Outputs for SubSystem: '<S163>/If Action Subsystem' */

      /* Outputs for IfAction SubSystem: '<S163>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S168>/Action Port'
       */
    } else if (Robot_Control_B.RB_Desired_Target_X > Field_Length_Half) {
      /* Switch: '<S168>/Switch' incorporates:
       *  Abs: '<S149>/Abs'
       */
      rtb_Switch2_hw = rtb_Init_o;

      /* End of Outputs for SubSystem: '<S163>/If Action Subsystem1' */
    }

    /* End of If: '<S163>/If' */

    /* Switch: '<S166>/Switch' incorporates:
     *  Logic: '<S166>/AND'
     *  Logic: '<S166>/AND1'
     *  RelationalOperator: '<S166>/GreaterThan'
     *  RelationalOperator: '<S166>/GreaterThan1'
     *  RelationalOperator: '<S166>/GreaterThan2'
     *  RelationalOperator: '<S166>/GreaterThan3'
     *  RelationalOperator: '<S166>/GreaterThan4'
     */
    if (rtb_Switch2_hw < rtb_Switch_cn) {
      rtb_Compare_mq = ((rtb_Switch2_h > rtb_Switch2_hw) && (rtb_Switch2_h <
        rtb_Switch_cn));
    } else {
      rtb_Compare_mq = ((rtb_Switch2_h > rtb_Switch_cn) && (rtb_Switch2_h <
        rtb_Switch2_hw));
    }

    /* Merge: '<S134>/Merge4' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Logic: '<S149>/AND'
     *  Logic: '<S166>/Logical Operator'
     *  Switch: '<S166>/Switch'
     */
    Robot_Control_B.Can_Pass = (rtb_Compare_ky &&
      ((Robot_Control_U.IsBlueAlliance != 0.0) == ((int32_T)rtb_Compare_mq)));

    /* Update for UnitDelay: '<S148>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_bb = rtb_Switch1_n;

    /* End of Outputs for SubSystem: '<S134>/Desired Shooting Parameters Math' */
  } else {
    /* Outputs for IfAction SubSystem: '<S134>/Shooter Not Active' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    /* Merge: '<S134>/Merge' incorporates:
     *  Constant: '<S143>/Constant2'
     *  SignalConversion generated from: '<S143>/Desired_Gyro_Angle'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;

    /* Merge: '<S134>/Merge1' incorporates:
     *  Constant: '<S143>/Constant'
     *  SignalConversion generated from: '<S143>/Desired_Shooter_Speed'
     */
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;

    /* Merge: '<S134>/Merge2' incorporates:
     *  Constant: '<S143>/Constant3'
     *  SignalConversion generated from: '<S143>/Desired_Hood_Pos'
     */
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot = Rebuilt_Hood_Servo_Pos_Min;

    /* Merge: '<S134>/Merge3' incorporates:
     *  Constant: '<S143>/Constant1'
     *  SignalConversion generated from: '<S143>/Allowed_Shoot_Gyro_Error_rad'
     */
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;

    /* Merge: '<S134>/Merge4' incorporates:
     *  Constant: '<S143>/Constant4'
     *  SignalConversion generated from: '<S143>/Can_Pass'
     */
    Robot_Control_B.Can_Pass = true;

    /* End of Outputs for SubSystem: '<S134>/Shooter Not Active' */
  }

  /* End of If: '<S134>/If' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Switch: '<S3>/Switch3'
   */
  if (rtb_Button_Spinup_Enable) {
    rtb_Hypot_g5 = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;
    rtb_MatrixConcatenate_idx_0 = Robot_Control_U.Gyro_Angle_Field_rad;
  } else {
    rtb_Hypot_g5 = Robot_Control_B.Steering_Abs_Cmd_SPF;
    rtb_MatrixConcatenate_idx_0 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* Sum: '<S384>/Add1' incorporates:
   *  Constant: '<S384>/Constant3'
   *  Constant: '<S384>/Constant4'
   *  Math: '<S384>/Math Function'
   *  Sum: '<S383>/Sum'
   *  Sum: '<S384>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Hypot_g5 -
    rtb_MatrixConcatenate_idx_0) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Gain: '<S387>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.295779513082323 *
    rtb_Optimized_Module_Angle_p;

  /* Abs: '<S366>/Abs1' */
  rtb_Init_o = fabs(Robot_Control_B.Steering_Heading_Error_deg);

  /* Sum: '<S386>/Sum1' incorporates:
   *  Constant: '<S383>/Constant2'
   *  Product: '<S386>/Product'
   *  Sum: '<S386>/Sum'
   *  UnitDelay: '<S386>/Unit Delay1'
   */
  rtb_Switch_cn = ((rtb_Optimized_Module_Angle_p -
                    Robot_Control_DW.UnitDelay1_DSTATE) *
                   Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S383>/Product' incorporates:
   *  Constant: '<S383>/Constant3'
   */
  rtb_Switch1_n = rtb_Switch_cn * Steering_Heading_Control_D;

  /* Sum: '<S385>/Diff' incorporates:
   *  UnitDelay: '<S385>/UD'
   *
   * Block description for '<S385>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S385>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integral_hv = rtb_Switch1_n - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S383>/Saturation' */
  if (rtb_Integral_hv > Steering_Heading_Control_D_UL) {
    rtb_Integral_hv = Steering_Heading_Control_D_UL;
  } else if (rtb_Integral_hv < Steering_Heading_Control_D_LL) {
    rtb_Integral_hv = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S383>/Add' incorporates:
   *  Gain: '<S383>/Gain1'
   *  Saturate: '<S383>/Saturation'
   */
  rtb_Init = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Integral_hv;

  /* Sum: '<S383>/Subtract' incorporates:
   *  Constant: '<S383>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Init;

  /* Sum: '<S383>/Sum2' incorporates:
   *  Gain: '<S383>/Gain2'
   *  UnitDelay: '<S383>/Unit Delay'
   */
  rtb_Switch2_hw = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S388>/Switch2' incorporates:
   *  RelationalOperator: '<S388>/LowerRelop1'
   */
  if (!(rtb_Switch2_hw > rtb_Sin4)) {
    /* Sum: '<S383>/Subtract1' incorporates:
     *  Constant: '<S383>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Init;

    /* Switch: '<S388>/Switch' incorporates:
     *  RelationalOperator: '<S388>/UpperRelop'
     */
    if (!(rtb_Switch2_hw < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2_hw;
    }

    /* End of Switch: '<S388>/Switch' */
  }

  /* End of Switch: '<S388>/Switch2' */

  /* Saturate: '<S383>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Switch2_hw = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Switch2_hw = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch2_hw = rtb_Sin4;
  }

  /* End of Saturate: '<S383>/Saturation1' */

  /* Sum: '<S383>/Add1' */
  rtb_Integral_hv = rtb_Init + rtb_Switch2_hw;

  /* Saturate: '<S383>/Saturation2' */
  if (rtb_Integral_hv > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S383>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Integral_hv < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S383>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S383>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Integral_hv;
  }

  /* End of Saturate: '<S383>/Saturation2' */

  /* Abs: '<S366>/Abs' */
  rtb_Sin4 = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S366>/Add dither' */
  if (Robot_Control_DW.is_active_c7_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c7_Robot_Control = 1U;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Sin4;
  } else if (Robot_Control_DW.is_c7_Robot_Control == Robot_Control_IN_Dither) {
    if ((!rtb_Button_Spinup_Enable) || (rtb_Init_o <
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
  } else if (rtb_Button_Spinup_Enable && (rtb_Init_o >
              Steering_Heading_Dither_Thresh_On)) {
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_Dither;
    Robot_Control_DW.is_Dither = Robot_Control_IN_High;
    Robot_Control_B.abs_Cmd_Out = rtb_Sin4 * Steering_Heading_Dither_Gain;
    Robot_Control_DW.timer = 0.0;
  } else {
    Robot_Control_B.abs_Cmd_Out = rtb_Sin4;
  }

  /* End of Chart: '<S366>/Add dither' */

  /* Switch: '<S366>/Switch' incorporates:
   *  Constant: '<S366>/Constant'
   *  Constant: '<S382>/Constant'
   *  Product: '<S366>/Product'
   *  RelationalOperator: '<S382>/Compare'
   *  Signum: '<S366>/Sign'
   */
  if (rtb_Sin4 > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S366>/Sign' */
    if (rtIsNaN(Robot_Control_B.Steering_Heading_PID)) {
      rtb_Hypot_g5 = (rtNaN);
    } else if (Robot_Control_B.Steering_Heading_PID < 0.0) {
      rtb_Hypot_g5 = -1.0;
    } else {
      rtb_Hypot_g5 = (Robot_Control_B.Steering_Heading_PID > 0.0);
    }

    rtb_Optimized_Module_Angle_p = Robot_Control_B.abs_Cmd_Out * rtb_Hypot_g5;
  } else {
    rtb_Optimized_Module_Angle_p = 0.0;
  }

  /* End of Switch: '<S366>/Switch' */

  /* Signum: '<S365>/Sign2' incorporates:
   *  UnitDelay: '<S365>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Hypot_g5 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Hypot_g5 = -1.0;
  } else {
    rtb_Hypot_g5 = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S365>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_MatrixConcatenate_idx_0 = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_MatrixConcatenate_idx_0 = -1.0;
  } else {
    rtb_MatrixConcatenate_idx_0 = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S365>/Product1' incorporates:
   *  Signum: '<S365>/Sign1'
   *  Signum: '<S365>/Sign2'
   */
  rtb_Hypot_g5 *= rtb_MatrixConcatenate_idx_0;
  if (rtIsNaN(rtb_Hypot_g5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Hypot_g5, 256.0);
  }

  /* Switch: '<S365>/Switch' incorporates:
   *  Constant: '<S365>/Constant'
   *  Constant: '<S374>/Constant'
   *  Constant: '<S375>/Constant'
   *  Logic: '<S365>/or'
   *  Product: '<S365>/Product1'
   *  RelationalOperator: '<S374>/Compare'
   *  RelationalOperator: '<S375>/Compare'
   *  UnitDelay: '<S365>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S365>/Switch' */

  /* Switch: '<S380>/Init' incorporates:
   *  UnitDelay: '<S380>/FixPt Unit Delay1'
   *  UnitDelay: '<S380>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S380>/Init' */

  /* RelationalOperator: '<S376>/Compare' incorporates:
   *  Constant: '<S376>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S377>/Compare' incorporates:
   *  Constant: '<S377>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S365>/Abs' incorporates:
   *  Sum: '<S365>/Subtract'
   *  UnitDelay: '<S365>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S365>/Switch5' incorporates:
   *  Constant: '<S365>/Constant1'
   *  Switch: '<S365>/Switch1'
   *  UnaryMinus: '<S365>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    /* SignalConversion generated from: '<S365>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S365>/Constant4'
     *  Constant: '<S365>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S365>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S365>/Constant2'
     *  Constant: '<S365>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S365>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S365>/Lookup Table Dynamic'
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
    rtb_Hypot_g5 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S365>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S365>/Constant10'
     *  Constant: '<S365>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S365>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S365>/Constant7'
     *  Constant: '<S365>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S365>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S365>/Lookup Table Dynamic1'
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

    /* Switch: '<S365>/Switch3' incorporates:
     *  Constant: '<S365>/Constant1'
     *  Constant: '<S365>/Constant3'
     *  UnaryMinus: '<S365>/Unary Minus'
     */
    if (rtb_LogicalOperator1) {
      rtb_Hypot_g5 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Hypot_g5 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S365>/Switch3' */
  }

  /* End of Switch: '<S365>/Switch5' */

  /* Product: '<S365>/Product' incorporates:
   *  Switch: '<S365>/Switch1'
   */
  rtb_Saturation_h = rtb_Hypot_g5 * rtb_Sin4;

  /* Sum: '<S378>/Sum1' */
  rtb_Init = rtb_MatrixConcatenate_b_idx_0 - rtb_Init_o;

  /* Switch: '<S379>/Switch2' incorporates:
   *  RelationalOperator: '<S379>/LowerRelop1'
   */
  if (!(rtb_Init > rtb_Saturation_h)) {
    /* Switch: '<S365>/Switch2' incorporates:
     *  Constant: '<S365>/Constant1'
     *  Constant: '<S365>/Constant3'
     *  Switch: '<S365>/Switch4'
     *  UnaryMinus: '<S365>/Unary Minus1'
     */
    if (rtb_Compare_ky) {
      rtb_Hypot_g5 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S365>/Switch4' incorporates:
       *  Constant: '<S365>/Constant1'
       */
      rtb_Hypot_g5 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Hypot_g5 = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S365>/Product2' incorporates:
     *  Switch: '<S365>/Switch2'
     */
    rtb_Switch2_h = rtb_Hypot_g5 * rtb_Sin4;

    /* Switch: '<S379>/Switch' incorporates:
     *  RelationalOperator: '<S379>/UpperRelop'
     */
    if (rtb_Init < rtb_Switch2_h) {
      rtb_Saturation_h = rtb_Switch2_h;
    } else {
      rtb_Saturation_h = rtb_Init;
    }

    /* End of Switch: '<S379>/Switch' */
  }

  /* End of Switch: '<S379>/Switch2' */

  /* Sum: '<S378>/Sum' */
  rtb_Init_o += rtb_Saturation_h;

  /* Signum: '<S364>/Sign2' incorporates:
   *  UnitDelay: '<S364>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Hypot_g5 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Hypot_g5 = -1.0;
  } else {
    rtb_Hypot_g5 = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S364>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_MatrixConcatenate_idx_0 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_MatrixConcatenate_idx_0 = -1.0;
  } else {
    rtb_MatrixConcatenate_idx_0 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S364>/Product1' incorporates:
   *  Signum: '<S364>/Sign1'
   *  Signum: '<S364>/Sign2'
   */
  rtb_Hypot_g5 *= rtb_MatrixConcatenate_idx_0;
  if (rtIsNaN(rtb_Hypot_g5)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Hypot_g5, 256.0);
  }

  /* Switch: '<S364>/Switch' incorporates:
   *  Constant: '<S364>/Constant'
   *  Constant: '<S367>/Constant'
   *  Constant: '<S368>/Constant'
   *  Logic: '<S364>/or'
   *  Product: '<S364>/Product1'
   *  RelationalOperator: '<S367>/Compare'
   *  RelationalOperator: '<S368>/Compare'
   *  UnitDelay: '<S364>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S364>/Switch' */

  /* Switch: '<S373>/Init' incorporates:
   *  UnitDelay: '<S373>/FixPt Unit Delay1'
   *  UnitDelay: '<S373>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc != 0) {
    rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S373>/Init' */

  /* RelationalOperator: '<S369>/Compare' incorporates:
   *  Constant: '<S369>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S370>/Compare' incorporates:
   *  Constant: '<S370>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S364>/Abs' incorporates:
   *  Sum: '<S364>/Subtract'
   *  UnitDelay: '<S364>/Unit Delay'
   */
  rtb_Init = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                  Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S364>/Switch1' incorporates:
   *  Constant: '<S364>/Constant1'
   *  Switch: '<S364>/Switch3'
   *  Switch: '<S364>/Switch5'
   *  UnaryMinus: '<S364>/Unary Minus'
   */
  if (rtb_Compare_ky) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S364>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S364>/Constant1'
     *  Constant: '<S364>/Constant4'
     *  Constant: '<S364>/Constant6'
     *  UnaryMinus: '<S364>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S364>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S364>/Constant2'
     *  Constant: '<S364>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S364>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S364>/Lookup Table Dynamic'
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
      /* Switch: '<S364>/Switch3' incorporates:
       *  Constant: '<S364>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S364>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S364>/Constant1'
     *  Constant: '<S364>/Constant10'
     *  Constant: '<S364>/Constant8'
     *  UnaryMinus: '<S364>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S364>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S364>/Constant7'
     *  Constant: '<S364>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S364>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S364>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S364>/Switch1' */

  /* Product: '<S364>/Product' */
  rtb_Sin4 *= rtb_Init;

  /* Sum: '<S371>/Sum1' */
  rtb_Switch2_h = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S372>/Switch2' incorporates:
   *  RelationalOperator: '<S372>/LowerRelop1'
   */
  if (!(rtb_Switch2_h > rtb_Sin4)) {
    /* Switch: '<S364>/Switch2' incorporates:
     *  Constant: '<S364>/Constant1'
     *  Switch: '<S364>/Switch4'
     */
    if (rtb_Compare_ky) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S364>/Switch4' incorporates:
       *  Constant: '<S364>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S364>/Switch4' incorporates:
       *  Constant: '<S364>/Constant3'
       *  UnaryMinus: '<S364>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S364>/Switch2' */

    /* Product: '<S364>/Product2' */
    rtb_Sin4 *= rtb_Init;

    /* Switch: '<S372>/Switch' incorporates:
     *  RelationalOperator: '<S372>/UpperRelop'
     */
    if (!(rtb_Switch2_h < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2_h;
    }

    /* End of Switch: '<S372>/Switch' */
  }

  /* End of Switch: '<S372>/Switch2' */

  /* Sum: '<S371>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S354>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (rtb_Button_Spinup_Enable || (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S354>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S354>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S354>/Switch' */

  /* Fcn: '<S397>/r->x' incorporates:
   *  Fcn: '<S402>/r->x'
   *  Fcn: '<S407>/r->x'
   *  Fcn: '<S412>/r->x'
   */
  rtb_Switch2_h = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S391>/Add' incorporates:
   *  Fcn: '<S397>/r->x'
   *  Fcn: '<S398>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2_h;

  /* Fcn: '<S397>/theta->y' incorporates:
   *  Fcn: '<S402>/theta->y'
   *  Fcn: '<S407>/theta->y'
   *  Fcn: '<S412>/theta->y'
   */
  rtb_Init = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S391>/Add' incorporates:
   *  Fcn: '<S397>/theta->y'
   *  Fcn: '<S398>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S392>/Add' incorporates:
   *  Fcn: '<S403>/r->x'
   *  Fcn: '<S403>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2_h;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S393>/Add' incorporates:
   *  Fcn: '<S408>/r->x'
   *  Fcn: '<S408>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2_h;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Init;

  /* Sum: '<S394>/Add' incorporates:
   *  Fcn: '<S413>/r->x'
   *  Fcn: '<S413>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2_h;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Init;

  /* Fcn: '<S411>/x->r' */
  rtb_Saturation_h = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S414>/Compare' incorporates:
   *  Constant: '<S414>/Constant'
   */
  rtb_Compare_pb = (rtb_Saturation_h == 0.0);

  /* Switch: '<S410>/Switch1' */
  if (rtb_Compare_pb) {
    /* Switch: '<S410>/Switch1' incorporates:
     *  Constant: '<S410>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S410>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Saturation_h;
  }

  /* End of Switch: '<S410>/Switch1' */

  /* Fcn: '<S396>/x->r' */
  rtb_Saturation_h = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S399>/Compare' incorporates:
   *  Constant: '<S399>/Constant'
   */
  rtb_Compare_mq = (rtb_Saturation_h == 0.0);

  /* Switch: '<S395>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S395>/Switch1' incorporates:
     *  Constant: '<S395>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S395>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Saturation_h;
  }

  /* End of Switch: '<S395>/Switch1' */

  /* Fcn: '<S401>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S404>/Compare' incorporates:
   *  Constant: '<S404>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S400>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S400>/Switch1' incorporates:
     *  Constant: '<S400>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S400>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S400>/Switch1' */

  /* Fcn: '<S406>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S409>/Compare' incorporates:
   *  Constant: '<S409>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S405>/Switch1' */
  if (rtb_LogicalOperator1) {
    /* Switch: '<S405>/Switch1' incorporates:
     *  Constant: '<S405>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S405>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S405>/Switch1' */

  /* Product: '<S390>/Divide' incorporates:
   *  Abs: '<S390>/Abs'
   *  Abs: '<S390>/Abs1'
   *  Abs: '<S390>/Abs2'
   *  Abs: '<S390>/Abs3'
   *  Constant: '<S390>/Constant'
   *  MinMax: '<S390>/Max'
   */
  rtb_Saturation_h = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S390>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Saturation_h;

  /* Switch: '<S410>/Switch' */
  if (!rtb_Compare_pb) {
    /* Switch: '<S410>/Switch' incorporates:
     *  Fcn: '<S411>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S410>/Switch' */

  /* Trigonometry: '<S344>/Cos4' incorporates:
   *  Switch: '<S333>/Angle_Switch'
   *  Trigonometry: '<S343>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S344>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S342>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S344>/Sin4' incorporates:
   *  Switch: '<S333>/Angle_Switch'
   *  Trigonometry: '<S343>/Sin4'
   */
  rtb_Init = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S344>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S342>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S344>/Subtract1' incorporates:
   *  Product: '<S344>/Product2'
   *  Product: '<S344>/Product3'
   *  Trigonometry: '<S344>/Cos4'
   *  Trigonometry: '<S344>/Sin4'
   */
  rtb_Switch2_h = (rtb_MatrixConcatenate_idx_0 * rtb_Optimized_Module_Angle) +
    (rtb_Init * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S344>/Subtract' incorporates:
   *  Product: '<S344>/Product'
   *  Product: '<S344>/Product1'
   *  Trigonometry: '<S344>/Cos4'
   *  Trigonometry: '<S344>/Sin4'
   */
  rtb_Minus_k_idx_1 = (rtb_MatrixConcatenate_idx_0 *
                       rtb_Optimized_Module_Angle_p) - (rtb_Init *
    rtb_Optimized_Module_Angle);

  /* Math: '<S344>/Hypot' */
  rtb_Minus_k_idx_0 = rt_hypotd_snf(rtb_Minus_k_idx_1, rtb_Switch2_h);

  /* Switch: '<S344>/Switch' incorporates:
   *  Constant: '<S344>/Constant'
   *  Constant: '<S344>/Constant1'
   *  Constant: '<S345>/Constant'
   *  Product: '<S344>/Divide'
   *  Product: '<S344>/Divide1'
   *  RelationalOperator: '<S345>/Compare'
   *  Switch: '<S344>/Switch1'
   */
  if (rtb_Minus_k_idx_0 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_h / rtb_Minus_k_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Minus_k_idx_1 / rtb_Minus_k_idx_0;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S344>/Switch' */

  /* Switch: '<S333>/Speed_Switch' incorporates:
   *  Abs: '<S333>/Abs'
   *  Constant: '<S341>/Constant'
   *  RelationalOperator: '<S341>/Compare'
   *  Switch: '<S333>/Angle_Switch'
   *  Trigonometry: '<S343>/Atan1'
   *  Trigonometry: '<S344>/Atan1'
   *  UnaryMinus: '<S333>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Hypot_g5 = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S343>/Subtract1' incorporates:
     *  Product: '<S343>/Product2'
     *  Product: '<S343>/Product3'
     *  UnaryMinus: '<S333>/Unary Minus'
     */
    rtb_Switch2_h = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Sin5_c)
      + (rtb_Init * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S343>/Subtract' incorporates:
     *  Product: '<S343>/Product'
     *  Product: '<S343>/Product1'
     */
    rtb_Minus_k_idx_1 = (rtb_MatrixConcatenate_idx_0 *
                         Robot_Control_ConstB.Cos5_b) - (rtb_Init *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S343>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Minus_k_idx_1, rtb_Switch2_h);

    /* Switch: '<S343>/Switch1' incorporates:
     *  Constant: '<S343>/Constant'
     *  Constant: '<S343>/Constant1'
     *  Constant: '<S346>/Constant'
     *  Product: '<S343>/Divide'
     *  Product: '<S343>/Divide1'
     *  RelationalOperator: '<S346>/Compare'
     *  Switch: '<S343>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Minus_k_idx_1 /= rtb_Init;
      rtb_Init = rtb_Switch2_h / rtb_Init;
    } else {
      rtb_Minus_k_idx_1 = 1.0;
      rtb_Init = 0.0;
    }

    /* End of Switch: '<S343>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Init, rtb_Minus_k_idx_1);
  } else {
    rtb_Hypot_g5 = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S336>/Product2' incorporates:
   *  Constant: '<S336>/Constant'
   *  Switch: '<S333>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Hypot_g5 * 1154.7574092481445;

  /* Signum: '<S331>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Hypot_g5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Hypot_g5 = -1.0;
  } else {
    rtb_Hypot_g5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S331>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_MatrixConcatenate_idx_0 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_MatrixConcatenate_idx_0 = -1.0;
  } else {
    rtb_MatrixConcatenate_idx_0 = (Robot_Control_U.BackRight_Drive_Motor_Speed >
      0.0);
  }

  /* Sum: '<S334>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S335>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S266>/Product' incorporates:
   *  Abs: '<S331>/Abs'
   *  Abs: '<S334>/Abs'
   *  Constant: '<S337>/Constant'
   *  Constant: '<S347>/Constant3'
   *  Constant: '<S347>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S331>/OR'
   *  Lookup_n-D: '<S334>/1-D Lookup Table'
   *  Math: '<S347>/Math Function'
   *  RelationalOperator: '<S331>/Equal1'
   *  RelationalOperator: '<S337>/Compare'
   *  Signum: '<S331>/Sign'
   *  Signum: '<S331>/Sign1'
   *  Sum: '<S334>/Add'
   *  Sum: '<S347>/Add1'
   *  Sum: '<S347>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Hypot_g5 ==
    rtb_MatrixConcatenate_idx_0) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                    rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S332>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Minus_k_idx_1 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S339>/Sum1' incorporates:
   *  Constant: '<S332>/Constant2'
   *  Product: '<S339>/Product'
   *  Sum: '<S339>/Sum'
   *  UnitDelay: '<S339>/Unit Delay1'
   */
  rtb_Init = ((rtb_Minus_k_idx_1 - Robot_Control_DW.UnitDelay1_DSTATE_j) *
              Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S332>/Product' incorporates:
   *  Constant: '<S332>/Constant3'
   */
  rtb_Switch2_h = rtb_Init * Drive_Motor_Control_D;

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
  rtb_Integral_hv = rtb_Switch2_h - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S332>/Saturation' */
  if (rtb_Integral_hv > Drive_Motor_Control_D_UL) {
    rtb_Integral_hv = Drive_Motor_Control_D_UL;
  } else if (rtb_Integral_hv < Drive_Motor_Control_D_LL) {
    rtb_Integral_hv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S332>/Add' incorporates:
   *  Gain: '<S332>/Gain'
   *  Gain: '<S332>/Gain1'
   *  Saturate: '<S332>/Saturation'
   */
  rtb_Minus_k_idx_0 = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0)
                       + (Drive_Motor_Control_P * rtb_Minus_k_idx_1)) +
    rtb_Integral_hv;

  /* Saturate: '<S332>/Saturation2' incorporates:
   *  Sum: '<S332>/Add1'
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

  /* End of Saturate: '<S332>/Saturation2' */

  /* Switch: '<S395>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S395>/Switch' incorporates:
     *  Fcn: '<S396>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S395>/Switch' */

  /* Trigonometry: '<S281>/Cos4' incorporates:
   *  Switch: '<S270>/Angle_Switch'
   *  Trigonometry: '<S280>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S281>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S279>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S281>/Sin4' incorporates:
   *  Switch: '<S270>/Angle_Switch'
   *  Trigonometry: '<S280>/Sin4'
   */
  rtb_Integral_hv = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S281>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S279>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S281>/Subtract1' incorporates:
   *  Product: '<S281>/Product2'
   *  Product: '<S281>/Product3'
   *  Trigonometry: '<S281>/Cos4'
   *  Trigonometry: '<S281>/Sin4'
   */
  rtb_Minus_k_idx_0 = (rtb_MatrixConcatenate_idx_0 * rtb_uDLookupTable) +
    (rtb_Integral_hv * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S281>/Subtract' incorporates:
   *  Product: '<S281>/Product'
   *  Product: '<S281>/Product1'
   *  Trigonometry: '<S281>/Cos4'
   *  Trigonometry: '<S281>/Sin4'
   */
  rtb_Minus_k_idx_1 = (rtb_MatrixConcatenate_idx_0 *
                       rtb_Optimized_Module_Angle_p) - (rtb_Integral_hv *
    rtb_uDLookupTable);

  /* Math: '<S281>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Minus_k_idx_1, rtb_Minus_k_idx_0);

  /* Switch: '<S281>/Switch' incorporates:
   *  Constant: '<S281>/Constant'
   *  Constant: '<S281>/Constant1'
   *  Constant: '<S282>/Constant'
   *  Product: '<S281>/Divide'
   *  Product: '<S281>/Divide1'
   *  RelationalOperator: '<S282>/Compare'
   *  Switch: '<S281>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Minus_k_idx_0 / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle_p = rtb_Minus_k_idx_1 / rtb_Hypot_g5;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S281>/Switch' */

  /* RelationalOperator: '<S278>/Compare' incorporates:
   *  Abs: '<S270>/Abs'
   *  Constant: '<S278>/Constant'
   *  Trigonometry: '<S281>/Atan1'
   */
  rtb_Compare_pb = (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
    rtb_Optimized_Module_Angle_p)) > 1.5707963267948966);

  /* Product: '<S390>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Saturation_h;

  /* Switch: '<S270>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S270>/Unary Minus'
   */
  if (rtb_Compare_pb) {
    rtb_Hypot_g5 = -Robot_Control_B.FL_Desired_Wheel_Speed;
  } else {
    rtb_Hypot_g5 = Robot_Control_B.FL_Desired_Wheel_Speed;
  }

  /* Product: '<S273>/Product2' incorporates:
   *  Constant: '<S273>/Constant'
   *  Switch: '<S270>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Hypot_g5 * 1154.7574092481445;

  /* Switch: '<S270>/Angle_Switch' incorporates:
   *  Trigonometry: '<S280>/Atan1'
   */
  if (rtb_Compare_pb) {
    /* Sum: '<S280>/Subtract1' incorporates:
     *  Product: '<S280>/Product2'
     *  Product: '<S280>/Product3'
     */
    rtb_Minus_k_idx_0 = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Sin5)
      + (rtb_Integral_hv * Robot_Control_ConstB.Cos5);

    /* Sum: '<S280>/Subtract' incorporates:
     *  Product: '<S280>/Product'
     *  Product: '<S280>/Product1'
     */
    rtb_Hypot_g5 = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Cos5) -
      (rtb_Integral_hv * Robot_Control_ConstB.Sin5);

    /* Math: '<S280>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_Hypot_g5, rtb_Minus_k_idx_0);

    /* Switch: '<S280>/Switch1' incorporates:
     *  Constant: '<S280>/Constant'
     *  Constant: '<S280>/Constant1'
     *  Constant: '<S283>/Constant'
     *  Product: '<S280>/Divide'
     *  Product: '<S280>/Divide1'
     *  RelationalOperator: '<S283>/Compare'
     *  Switch: '<S280>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Minus_k_idx_1;
      rtb_Minus_k_idx_0 /= rtb_Minus_k_idx_1;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Minus_k_idx_0 = 0.0;
    }

    /* End of Switch: '<S280>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Minus_k_idx_0, rtb_Hypot_g5);
  } else {
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Signum: '<S268>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Hypot_g5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Hypot_g5 = -1.0;
  } else {
    rtb_Hypot_g5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S268>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_MatrixConcatenate_idx_0 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_MatrixConcatenate_idx_0 = -1.0;
  } else {
    rtb_MatrixConcatenate_idx_0 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed >
      0.0);
  }

  /* Sum: '<S271>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S272>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S263>/Product' incorporates:
   *  Abs: '<S268>/Abs'
   *  Abs: '<S271>/Abs'
   *  Constant: '<S274>/Constant'
   *  Constant: '<S284>/Constant3'
   *  Constant: '<S284>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S268>/OR'
   *  Lookup_n-D: '<S271>/1-D Lookup Table'
   *  Math: '<S284>/Math Function'
   *  RelationalOperator: '<S268>/Equal1'
   *  RelationalOperator: '<S274>/Compare'
   *  Signum: '<S268>/Sign'
   *  Signum: '<S268>/Sign1'
   *  Sum: '<S271>/Add'
   *  Sum: '<S284>/Add1'
   *  Sum: '<S284>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Hypot_g5 ==
    rtb_MatrixConcatenate_idx_0) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S269>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_g5 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S276>/Sum1' incorporates:
   *  Constant: '<S269>/Constant2'
   *  Product: '<S276>/Product'
   *  Sum: '<S276>/Sum'
   *  UnitDelay: '<S276>/Unit Delay1'
   */
  rtb_Minus_k_idx_0 = ((rtb_Hypot_g5 - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S269>/Product' incorporates:
   *  Constant: '<S269>/Constant3'
   */
  rtb_Minus_k_idx_1 = rtb_Minus_k_idx_0 * Drive_Motor_Control_D;

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
  rtb_Integral_hv = rtb_Minus_k_idx_1 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S269>/Saturation' */
  if (rtb_Integral_hv > Drive_Motor_Control_D_UL) {
    rtb_Integral_hv = Drive_Motor_Control_D_UL;
  } else if (rtb_Integral_hv < Drive_Motor_Control_D_LL) {
    rtb_Integral_hv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S269>/Add' incorporates:
   *  Gain: '<S269>/Gain'
   *  Gain: '<S269>/Gain1'
   *  Saturate: '<S269>/Saturation'
   */
  rtb_Add_ju = ((Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0) +
                (Drive_Motor_Control_P * rtb_Hypot_g5)) + rtb_Integral_hv;

  /* Saturate: '<S269>/Saturation2' incorporates:
   *  Sum: '<S269>/Add1'
   */
  if (rtb_Add_ju > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ju < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = rtb_Add_ju;
  }

  /* End of Saturate: '<S269>/Saturation2' */

  /* Sum: '<S285>/Add1' incorporates:
   *  Constant: '<S285>/Constant3'
   *  Constant: '<S285>/Constant4'
   *  Math: '<S285>/Math Function'
   *  Sum: '<S285>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S287>/Sum1' incorporates:
   *  Constant: '<S272>/Constant2'
   *  Product: '<S287>/Product'
   *  Sum: '<S287>/Sum'
   *  UnitDelay: '<S287>/Unit Delay1'
   */
  rtb_Add_ju = ((rtb_MatrixConcatenate_b_idx_0 -
                 Robot_Control_DW.UnitDelay1_DSTATE_b) *
                Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S272>/Product' incorporates:
   *  Constant: '<S272>/Constant3'
   */
  rtb_Switch2_pt = rtb_Add_ju * Steering_Motor_Control_D;

  /* Sum: '<S286>/Diff' incorporates:
   *  UnitDelay: '<S286>/UD'
   *
   * Block description for '<S286>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S286>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integral_hv = rtb_Switch2_pt - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S272>/Saturation' */
  if (rtb_Integral_hv > Steering_Motor_Control_D_UL) {
    rtb_Integral_hv = Steering_Motor_Control_D_UL;
  } else if (rtb_Integral_hv < Steering_Motor_Control_D_LL) {
    rtb_Integral_hv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S272>/Add' incorporates:
   *  Gain: '<S272>/Gain1'
   *  Saturate: '<S272>/Saturation'
   */
  rtb_Add_fn = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Integral_hv;

  /* Sum: '<S272>/Subtract' incorporates:
   *  Constant: '<S272>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_fn;

  /* Sum: '<S272>/Sum2' incorporates:
   *  Gain: '<S272>/Gain2'
   *  UnitDelay: '<S272>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S288>/Switch2' incorporates:
   *  Constant: '<S272>/Constant'
   *  RelationalOperator: '<S288>/LowerRelop1'
   *  Sum: '<S272>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_fn))) {
    /* Switch: '<S288>/Switch' incorporates:
     *  Constant: '<S272>/Constant1'
     *  RelationalOperator: '<S288>/UpperRelop'
     *  Sum: '<S272>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_fn)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_fn;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S288>/Switch' */
  }

  /* End of Switch: '<S288>/Switch2' */

  /* Saturate: '<S272>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S272>/Saturation1' */

  /* Sum: '<S272>/Add1' */
  rtb_Integral_hv = rtb_Add_fn + rtb_Sum2_e;

  /* Saturate: '<S272>/Saturation2' */
  if (rtb_Integral_hv > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Integral_hv < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Integral_hv;
  }

  /* End of Saturate: '<S272>/Saturation2' */

  /* Switch: '<S400>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S400>/Switch' incorporates:
     *  Fcn: '<S401>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S400>/Switch' */

  /* Trigonometry: '<S302>/Cos4' incorporates:
   *  Switch: '<S291>/Angle_Switch'
   *  Trigonometry: '<S301>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S302>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S300>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S302>/Sin4' incorporates:
   *  Switch: '<S291>/Angle_Switch'
   *  Trigonometry: '<S301>/Sin4'
   */
  rtb_Integral_hv = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S302>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S300>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S302>/Subtract1' incorporates:
   *  Product: '<S302>/Product2'
   *  Product: '<S302>/Product3'
   *  Trigonometry: '<S302>/Cos4'
   *  Trigonometry: '<S302>/Sin4'
   */
  rtb_Add_fn = (rtb_MatrixConcatenate_idx_0 * rtb_uDLookupTable) +
    (rtb_Integral_hv * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S302>/Subtract' incorporates:
   *  Product: '<S302>/Product'
   *  Product: '<S302>/Product1'
   *  Trigonometry: '<S302>/Cos4'
   *  Trigonometry: '<S302>/Sin4'
   */
  rtb_Subtract1_la = (rtb_MatrixConcatenate_idx_0 * rtb_Optimized_Module_Angle_p)
    - (rtb_Integral_hv * rtb_uDLookupTable);

  /* Math: '<S302>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_fn);

  /* Switch: '<S302>/Switch' incorporates:
   *  Constant: '<S302>/Constant'
   *  Constant: '<S302>/Constant1'
   *  Constant: '<S303>/Constant'
   *  Product: '<S302>/Divide'
   *  Product: '<S302>/Divide1'
   *  RelationalOperator: '<S303>/Compare'
   *  Switch: '<S302>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_fn / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_g5;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S302>/Switch' */

  /* RelationalOperator: '<S299>/Compare' incorporates:
   *  Abs: '<S291>/Abs'
   *  Constant: '<S299>/Constant'
   *  Trigonometry: '<S302>/Atan1'
   */
  rtb_Compare_pb = (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
    rtb_Optimized_Module_Angle_p)) > 1.5707963267948966);

  /* Product: '<S390>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Saturation_h;

  /* Switch: '<S291>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S291>/Unary Minus'
   */
  if (rtb_Compare_pb) {
    rtb_Hypot_g5 = -Robot_Control_B.FR_Desired_Wheel_Speed;
  } else {
    rtb_Hypot_g5 = Robot_Control_B.FR_Desired_Wheel_Speed;
  }

  /* Product: '<S294>/Product2' incorporates:
   *  Constant: '<S294>/Constant'
   *  Switch: '<S291>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Hypot_g5 * 1154.7574092481445;

  /* Switch: '<S291>/Angle_Switch' incorporates:
   *  Trigonometry: '<S301>/Atan1'
   */
  if (rtb_Compare_pb) {
    /* Sum: '<S301>/Subtract1' incorporates:
     *  Product: '<S301>/Product2'
     *  Product: '<S301>/Product3'
     */
    rtb_Add_fn = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Sin5_m) +
      (rtb_Integral_hv * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S301>/Subtract' incorporates:
     *  Product: '<S301>/Product'
     *  Product: '<S301>/Product1'
     */
    rtb_Hypot_g5 = (rtb_MatrixConcatenate_idx_0 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Integral_hv * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S301>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_g5, rtb_Add_fn);

    /* Switch: '<S301>/Switch1' incorporates:
     *  Constant: '<S301>/Constant'
     *  Constant: '<S301>/Constant1'
     *  Constant: '<S304>/Constant'
     *  Product: '<S301>/Divide'
     *  Product: '<S301>/Divide1'
     *  RelationalOperator: '<S304>/Compare'
     *  Switch: '<S301>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Subtract1_la;
      rtb_Add_fn /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Add_fn = 0.0;
    }

    /* End of Switch: '<S301>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_fn, rtb_Hypot_g5);
  } else {
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Signum: '<S289>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Hypot_g5 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Hypot_g5 = -1.0;
  } else {
    rtb_Hypot_g5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S289>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_MatrixConcatenate_idx_0 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_MatrixConcatenate_idx_0 = -1.0;
  } else {
    rtb_MatrixConcatenate_idx_0 = (Robot_Control_U.FrontRight_Drive_Motor_Speed >
      0.0);
  }

  /* Sum: '<S292>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S293>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S264>/Product' incorporates:
   *  Abs: '<S289>/Abs'
   *  Abs: '<S292>/Abs'
   *  Constant: '<S295>/Constant'
   *  Constant: '<S305>/Constant3'
   *  Constant: '<S305>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S289>/OR'
   *  Lookup_n-D: '<S292>/1-D Lookup Table'
   *  Math: '<S305>/Math Function'
   *  RelationalOperator: '<S289>/Equal1'
   *  RelationalOperator: '<S295>/Compare'
   *  Signum: '<S289>/Sign'
   *  Signum: '<S289>/Sign1'
   *  Sum: '<S292>/Add'
   *  Sum: '<S305>/Add1'
   *  Sum: '<S305>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Hypot_g5 ==
    rtb_MatrixConcatenate_idx_0) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Sum: '<S290>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_g5 = rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S297>/Sum1' incorporates:
   *  Constant: '<S290>/Constant2'
   *  Product: '<S297>/Product'
   *  Sum: '<S297>/Sum'
   *  UnitDelay: '<S297>/Unit Delay1'
   */
  rtb_Add_fn = ((rtb_Hypot_g5 - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S290>/Product' incorporates:
   *  Constant: '<S290>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_fn * Drive_Motor_Control_D;

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
  rtb_Integral_hv = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S290>/Saturation' */
  if (rtb_Integral_hv > Drive_Motor_Control_D_UL) {
    rtb_Integral_hv = Drive_Motor_Control_D_UL;
  } else if (rtb_Integral_hv < Drive_Motor_Control_D_LL) {
    rtb_Integral_hv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S290>/Add' incorporates:
   *  Gain: '<S290>/Gain'
   *  Gain: '<S290>/Gain1'
   *  Saturate: '<S290>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF *
    rtb_MatrixConcatenate_b_idx_0) + (Drive_Motor_Control_P * rtb_Hypot_g5)) +
    rtb_Integral_hv;

  /* Saturate: '<S290>/Saturation2' incorporates:
   *  Sum: '<S290>/Add1'
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

  /* End of Saturate: '<S290>/Saturation2' */

  /* Sum: '<S306>/Add1' incorporates:
   *  Constant: '<S306>/Constant3'
   *  Constant: '<S306>/Constant4'
   *  Math: '<S306>/Math Function'
   *  Sum: '<S306>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S308>/Sum1' incorporates:
   *  Constant: '<S293>/Constant2'
   *  Product: '<S308>/Product'
   *  Sum: '<S308>/Sum'
   *  UnitDelay: '<S308>/Unit Delay1'
   */
  rtb_Switch2_e = ((rtb_MatrixConcatenate_b_idx_0 -
                    Robot_Control_DW.UnitDelay1_DSTATE_n) *
                   Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S293>/Product' incorporates:
   *  Constant: '<S293>/Constant3'
   */
  rtb_Product_hi = rtb_Switch2_e * Steering_Motor_Control_D;

  /* Sum: '<S307>/Diff' incorporates:
   *  UnitDelay: '<S307>/UD'
   *
   * Block description for '<S307>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S307>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integral_hv = rtb_Product_hi - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S293>/Saturation' */
  if (rtb_Integral_hv > Steering_Motor_Control_D_UL) {
    rtb_Integral_hv = Steering_Motor_Control_D_UL;
  } else if (rtb_Integral_hv < Steering_Motor_Control_D_LL) {
    rtb_Integral_hv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S293>/Add' incorporates:
   *  Gain: '<S293>/Gain1'
   *  Saturate: '<S293>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P *
    rtb_MatrixConcatenate_b_idx_0) + rtb_Integral_hv;

  /* Sum: '<S293>/Subtract' incorporates:
   *  Constant: '<S293>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S293>/Sum2' incorporates:
   *  Gain: '<S293>/Gain2'
   *  UnitDelay: '<S293>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S309>/Switch2' incorporates:
   *  Constant: '<S293>/Constant'
   *  RelationalOperator: '<S309>/LowerRelop1'
   *  Sum: '<S293>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S309>/Switch' incorporates:
     *  Constant: '<S293>/Constant1'
     *  RelationalOperator: '<S309>/UpperRelop'
     *  Sum: '<S293>/Subtract1'
     */
    if (rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S309>/Switch' */
  }

  /* End of Switch: '<S309>/Switch2' */

  /* Saturate: '<S293>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S293>/Saturation1' */

  /* Sum: '<S293>/Add1' */
  rtb_Integral_hv = rtb_MatrixConcatenate_idx_0 + rtb_Subtract1_kg;

  /* Saturate: '<S293>/Saturation2' */
  if (rtb_Integral_hv > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Integral_hv < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Integral_hv;
  }

  /* End of Saturate: '<S293>/Saturation2' */

  /* Switch: '<S405>/Switch' */
  if (!rtb_LogicalOperator1) {
    /* Switch: '<S405>/Switch' incorporates:
     *  Fcn: '<S406>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S405>/Switch' */

  /* Trigonometry: '<S323>/Cos4' incorporates:
   *  Switch: '<S312>/Angle_Switch'
   *  Trigonometry: '<S322>/Cos4'
   */
  rtb_MatrixConcatenate_idx_0 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S323>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S321>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S323>/Sin4' incorporates:
   *  Switch: '<S312>/Angle_Switch'
   *  Trigonometry: '<S322>/Sin4'
   */
  rtb_Integral_hv = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S323>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S321>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S323>/Subtract1' incorporates:
   *  Product: '<S323>/Product2'
   *  Product: '<S323>/Product3'
   *  Trigonometry: '<S323>/Cos4'
   *  Trigonometry: '<S323>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_MatrixConcatenate_idx_0 *
    rtb_uDLookupTable) + (rtb_Integral_hv * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S323>/Subtract' incorporates:
   *  Product: '<S323>/Product'
   *  Product: '<S323>/Product1'
   *  Trigonometry: '<S323>/Cos4'
   *  Trigonometry: '<S323>/Sin4'
   */
  rtb_uDLookupTable = (rtb_MatrixConcatenate_idx_0 *
                       rtb_Optimized_Module_Angle_p) - (rtb_Integral_hv *
    rtb_uDLookupTable);

  /* Math: '<S323>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S323>/Switch' incorporates:
   *  Constant: '<S323>/Constant'
   *  Constant: '<S323>/Constant1'
   *  Constant: '<S324>/Constant'
   *  Product: '<S323>/Divide'
   *  Product: '<S323>/Divide1'
   *  RelationalOperator: '<S324>/Compare'
   *  Switch: '<S323>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S323>/Switch' */

  /* Product: '<S390>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Saturation_h;

  /* Switch: '<S312>/Speed_Switch' incorporates:
   *  Abs: '<S312>/Abs'
   *  Constant: '<S320>/Constant'
   *  RelationalOperator: '<S320>/Compare'
   *  Switch: '<S312>/Angle_Switch'
   *  Trigonometry: '<S322>/Atan1'
   *  Trigonometry: '<S323>/Atan1'
   *  UnaryMinus: '<S312>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle_p)) > 1.5707963267948966) {
    rtb_Hypot_g5 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S322>/Subtract1' incorporates:
     *  Product: '<S322>/Product2'
     *  Product: '<S322>/Product3'
     *  UnaryMinus: '<S312>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_MatrixConcatenate_idx_0 *
      Robot_Control_ConstB.Sin5_e) + (rtb_Integral_hv *
      Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S322>/Subtract' incorporates:
     *  Product: '<S322>/Product'
     *  Product: '<S322>/Product1'
     */
    rtb_uDLookupTable = (rtb_MatrixConcatenate_idx_0 *
                         Robot_Control_ConstB.Cos5_i) - (rtb_Integral_hv *
      Robot_Control_ConstB.Sin5_e);

    /* Math: '<S322>/Hypot' */
    rtb_MatrixConcatenate_idx_0 = rt_hypotd_snf(rtb_uDLookupTable,
      rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S322>/Switch1' incorporates:
     *  Constant: '<S322>/Constant'
     *  Constant: '<S322>/Constant1'
     *  Constant: '<S325>/Constant'
     *  Product: '<S322>/Divide'
     *  Product: '<S322>/Divide1'
     *  RelationalOperator: '<S325>/Compare'
     *  Switch: '<S322>/Switch'
     */
    if (rtb_MatrixConcatenate_idx_0 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_MatrixConcatenate_idx_0;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S322>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_uDLookupTable);
  } else {
    rtb_Hypot_g5 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S315>/Product2' incorporates:
   *  Constant: '<S315>/Constant'
   *  Switch: '<S312>/Speed_Switch'
   */
  rtb_Saturation_h = rtb_Hypot_g5 * 1154.7574092481445;

  /* Signum: '<S310>/Sign' */
  if (rtIsNaN(rtb_Saturation_h)) {
    rtb_Hypot_g5 = (rtNaN);
  } else if (rtb_Saturation_h < 0.0) {
    rtb_Hypot_g5 = -1.0;
  } else {
    rtb_Hypot_g5 = (rtb_Saturation_h > 0.0);
  }

  /* Signum: '<S310>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_MatrixConcatenate_idx_0 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_MatrixConcatenate_idx_0 = -1.0;
  } else {
    rtb_MatrixConcatenate_idx_0 = (Robot_Control_U.BackLeft_Drive_Motor_Speed >
      0.0);
  }

  /* Sum: '<S313>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S314>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S265>/Product' incorporates:
   *  Abs: '<S310>/Abs'
   *  Abs: '<S313>/Abs'
   *  Constant: '<S316>/Constant'
   *  Constant: '<S326>/Constant3'
   *  Constant: '<S326>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S310>/OR'
   *  Lookup_n-D: '<S313>/1-D Lookup Table'
   *  Math: '<S326>/Math Function'
   *  RelationalOperator: '<S310>/Equal1'
   *  RelationalOperator: '<S316>/Compare'
   *  Signum: '<S310>/Sign'
   *  Signum: '<S310>/Sign1'
   *  Sum: '<S313>/Add'
   *  Sum: '<S326>/Add1'
   *  Sum: '<S326>/Add2'
   */
  rtb_Saturation_h = (((real_T)((rtb_Hypot_g5 == rtb_MatrixConcatenate_idx_0) ||
    (fabs(Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Saturation_h) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Sum: '<S311>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h -
    Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S318>/Sum1' incorporates:
   *  Constant: '<S311>/Constant2'
   *  Product: '<S318>/Product'
   *  Sum: '<S318>/Sum'
   *  UnitDelay: '<S318>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_MatrixConcatenate_b_idx_0 -
    Robot_Control_DW.UnitDelay1_DSTATE_n4) * Drive_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S311>/Product' incorporates:
   *  Constant: '<S311>/Constant3'
   */
  rtb_uDLookupTable = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

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
  rtb_Integral_hv = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S311>/Saturation' */
  if (rtb_Integral_hv > Drive_Motor_Control_D_UL) {
    rtb_Integral_hv = Drive_Motor_Control_D_UL;
  } else if (rtb_Integral_hv < Drive_Motor_Control_D_LL) {
    rtb_Integral_hv = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S311>/Add' incorporates:
   *  Gain: '<S311>/Gain'
   *  Gain: '<S311>/Gain1'
   *  Saturate: '<S311>/Saturation'
   */
  rtb_Saturation_h = ((Drive_Motor_Control_FF * rtb_Saturation_h) +
                      (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) +
    rtb_Integral_hv;

  /* Saturate: '<S311>/Saturation2' incorporates:
   *  Sum: '<S311>/Add1'
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

  /* End of Saturate: '<S311>/Saturation2' */

  /* Sum: '<S327>/Add1' incorporates:
   *  Constant: '<S327>/Constant3'
   *  Constant: '<S327>/Constant4'
   *  Math: '<S327>/Math Function'
   *  Sum: '<S327>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Optimized_Module_Angle_p +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S329>/Sum1' incorporates:
   *  Constant: '<S314>/Constant2'
   *  Product: '<S329>/Product'
   *  Sum: '<S329>/Sum'
   *  UnitDelay: '<S329>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Saturation_h -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S314>/Product' incorporates:
   *  Constant: '<S314>/Constant3'
   */
  rtb_Product_k = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S328>/Diff' incorporates:
   *  UnitDelay: '<S328>/UD'
   *
   * Block description for '<S328>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S328>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integral_hv = rtb_Product_k - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S314>/Saturation' */
  if (rtb_Integral_hv > Steering_Motor_Control_D_UL) {
    rtb_Integral_hv = Steering_Motor_Control_D_UL;
  } else if (rtb_Integral_hv < Steering_Motor_Control_D_LL) {
    rtb_Integral_hv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S314>/Add' incorporates:
   *  Gain: '<S314>/Gain1'
   *  Saturate: '<S314>/Saturation'
   */
  rtb_Add_nz = (Steering_Motor_Control_P * rtb_Saturation_h) + rtb_Integral_hv;

  /* Sum: '<S314>/Subtract' incorporates:
   *  Constant: '<S314>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_nz;

  /* Sum: '<S314>/Sum2' incorporates:
   *  Gain: '<S314>/Gain2'
   *  UnitDelay: '<S314>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S330>/Switch2' incorporates:
   *  Constant: '<S314>/Constant'
   *  RelationalOperator: '<S330>/LowerRelop1'
   *  Sum: '<S314>/Subtract'
   */
  if (!(rtb_Saturation_h > (1.0 - rtb_Add_nz))) {
    /* Sum: '<S314>/Subtract1' incorporates:
     *  Constant: '<S314>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_nz;

    /* Switch: '<S330>/Switch' incorporates:
     *  Constant: '<S314>/Constant1'
     *  RelationalOperator: '<S330>/UpperRelop'
     *  Sum: '<S314>/Subtract1'
     */
    if (!(rtb_Saturation_h < (-1.0 - rtb_Add_nz))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h;
    }

    /* End of Switch: '<S330>/Switch' */
  }

  /* End of Switch: '<S330>/Switch2' */

  /* Saturate: '<S314>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_m = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_m = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_m = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S314>/Saturation1' */

  /* Sum: '<S314>/Add1' */
  rtb_Integral_hv = rtb_Add_nz + rtb_Integral_m;

  /* Saturate: '<S314>/Saturation2' */
  if (rtb_Integral_hv > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Integral_hv < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Integral_hv;
  }

  /* End of Saturate: '<S314>/Saturation2' */

  /* Sum: '<S348>/Add1' incorporates:
   *  Constant: '<S348>/Constant3'
   *  Constant: '<S348>/Constant4'
   *  Math: '<S348>/Math Function'
   *  Sum: '<S348>/Add2'
   */
  rtb_Saturation_h = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S350>/Sum1' incorporates:
   *  Constant: '<S335>/Constant2'
   *  Product: '<S350>/Product'
   *  Sum: '<S350>/Sum'
   *  UnitDelay: '<S350>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Saturation_h -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S335>/Product' incorporates:
   *  Constant: '<S335>/Constant3'
   */
  rtb_Add_nz = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S349>/Diff' incorporates:
   *  UnitDelay: '<S349>/UD'
   *
   * Block description for '<S349>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S349>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integral_hv = rtb_Add_nz - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S335>/Saturation' */
  if (rtb_Integral_hv > Steering_Motor_Control_D_UL) {
    rtb_Integral_hv = Steering_Motor_Control_D_UL;
  } else if (rtb_Integral_hv < Steering_Motor_Control_D_LL) {
    rtb_Integral_hv = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S335>/Add' incorporates:
   *  Gain: '<S335>/Gain1'
   *  Saturate: '<S335>/Saturation'
   */
  rtb_Add_de = (Steering_Motor_Control_P * rtb_Saturation_h) + rtb_Integral_hv;

  /* Sum: '<S335>/Subtract' incorporates:
   *  Constant: '<S335>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_de;

  /* Sum: '<S335>/Sum2' incorporates:
   *  Gain: '<S335>/Gain2'
   *  UnitDelay: '<S335>/Unit Delay'
   */
  rtb_Saturation_h = (Steering_Motor_Control_I * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S351>/Switch2' incorporates:
   *  Constant: '<S335>/Constant'
   *  RelationalOperator: '<S351>/LowerRelop1'
   *  Sum: '<S335>/Subtract'
   */
  if (!(rtb_Saturation_h > (1.0 - rtb_Add_de))) {
    /* Sum: '<S335>/Subtract1' incorporates:
     *  Constant: '<S335>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_de;

    /* Switch: '<S351>/Switch' incorporates:
     *  Constant: '<S335>/Constant1'
     *  RelationalOperator: '<S351>/UpperRelop'
     *  Sum: '<S335>/Subtract1'
     */
    if (!(rtb_Saturation_h < (-1.0 - rtb_Add_de))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h;
    }

    /* End of Switch: '<S351>/Switch' */
  }

  /* End of Switch: '<S351>/Switch2' */

  /* Saturate: '<S335>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_p = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_p = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_p = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S335>/Saturation1' */

  /* Sum: '<S335>/Add1' */
  rtb_Integral_hv = rtb_Add_de + rtb_Integral_p;

  /* Saturate: '<S335>/Saturation2' */
  if (rtb_Integral_hv > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Integral_hv < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Integral_hv;
  }

  /* End of Saturate: '<S335>/Saturation2' */

  /* Sum: '<S198>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S141>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S200>/Sum1' incorporates:
   *  Constant: '<S198>/Constant2'
   *  Product: '<S200>/Product'
   *  Sum: '<S198>/Sum'
   *  Sum: '<S200>/Sum'
   *  UnitDelay: '<S200>/Unit Delay1'
   */
  rtb_Add_de = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S198>/Product' incorporates:
   *  Constant: '<S198>/Constant3'
   */
  rtb_Product_ih = rtb_Add_de * 0.0;

  /* Sum: '<S199>/Diff' incorporates:
   *  UnitDelay: '<S199>/UD'
   *
   * Block description for '<S199>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S199>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integral_hv = rtb_Product_ih - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S198>/Saturation' */
  if (rtb_Integral_hv > 0.1) {
    rtb_Integral_hv = 0.1;
  } else if (rtb_Integral_hv < -0.1) {
    rtb_Integral_hv = -0.1;
  }

  /* Sum: '<S198>/Add' incorporates:
   *  Gain: '<S198>/Gain'
   *  Gain: '<S198>/Gain1'
   *  Saturate: '<S198>/Saturation'
   *  Sum: '<S198>/Sum'
   */
  rtb_Saturation_h = ((Rebuilt_Transfer_Motor_Gain_FF *
                       Robot_Control_B.RB_Desired_Transfer_Speed) +
                      (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) +
    rtb_Integral_hv;

  /* Logic: '<S141>/Logical Operator1' incorporates:
   *  Constant: '<S197>/Constant'
   *  RelationalOperator: '<S197>/Compare'
   */
  rtb_LogicalOperator1 = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

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
      rtb_LogicalOperator1) {
    rtb_Compare_ky = true;
  } else {
    rtb_Compare_ky = (rtb_LogicalOperator1 &&
                      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S141>/Switch1' */

  /* Switch: '<S198>/Switch' incorporates:
   *  Constant: '<S198>/Constant4'
   */
  if (rtb_Compare_ky) {
    /* Sum: '<S198>/Sum2' incorporates:
     *  Gain: '<S198>/Gain2'
     *  Sum: '<S198>/Sum'
     *  UnitDelay: '<S198>/Unit Delay'
     */
    rtb_MatrixConcatenate_b_idx_0 = (Rebuilt_Transfer_Motor_Gain_I *
      rtb_Integral_d) + Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S198>/Subtract' incorporates:
     *  Constant: '<S198>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Saturation_h;

    /* Switch: '<S201>/Switch2' incorporates:
     *  Constant: '<S198>/Constant'
     *  RelationalOperator: '<S201>/LowerRelop1'
     *  Sum: '<S198>/Subtract'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Saturation_h))) {
      /* Sum: '<S198>/Subtract1' incorporates:
       *  Constant: '<S198>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Saturation_h;

      /* Switch: '<S201>/Switch' incorporates:
       *  Constant: '<S198>/Constant1'
       *  RelationalOperator: '<S201>/UpperRelop'
       *  Sum: '<S198>/Subtract1'
       */
      if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Saturation_h))) {
        rtb_Integral_d = rtb_MatrixConcatenate_b_idx_0;
      }

      /* End of Switch: '<S201>/Switch' */
    }

    /* End of Switch: '<S201>/Switch2' */

    /* Saturate: '<S198>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S198>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S198>/Switch' */

  /* Switch: '<S141>/Switch2' incorporates:
   *  Logic: '<S141>/Logical Operator1'
   */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S198>/Add1' */
    rtb_Integral_hv = rtb_Saturation_h + rtb_Integral_d;

    /* Saturate: '<S198>/Saturation2' */
    if (rtb_Integral_hv > 1.0) {
      /* Switch: '<S141>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Integral_hv < -1.0) {
      /* Switch: '<S141>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S141>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Integral_hv;
    }

    /* End of Saturate: '<S198>/Saturation2' */
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
  rtb_Integral_hv = Robot_Control_B.RB_Desired_Feeder_Speed *
    Rebuilt_Feeder_Motor_Gain_FF;

  /* Saturate: '<S12>/Saturation' */
  if (rtb_Integral_hv > 1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = 1.0;
  } else if (rtb_Integral_hv < -1.0) {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = -1.0;
  } else {
    /* Saturate: '<S12>/Saturation' */
    Robot_Control_B.RB_Feeder_Motor_PID_DC = rtb_Integral_hv;
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

  /* Switch: '<S132>/Init' incorporates:
   *  UnitDelay: '<S132>/FixPt Unit Delay1'
   *  UnitDelay: '<S132>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S132>/Init' */

  /* Sum: '<S130>/Sum1' */
  rtb_Saturation_h -= rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S131>/Switch2' incorporates:
   *  Constant: '<S129>/Constant1'
   *  Constant: '<S129>/Constant3'
   *  RelationalOperator: '<S131>/LowerRelop1'
   *  RelationalOperator: '<S131>/UpperRelop'
   *  Switch: '<S131>/Switch'
   */
  if (rtb_Saturation_h > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Saturation_h = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Saturation_h < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S131>/Switch' incorporates:
     *  Constant: '<S129>/Constant1'
     */
    rtb_Saturation_h = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S131>/Switch2' */

  /* Sum: '<S130>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Saturation_h +
    rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S56>/Switch' incorporates:
   *  Constant: '<S56>/Constant1'
   *  UnitDelay: '<S56>/Unit Delay'
   */
  if (rtb_Intake_Arm_Move_In) {
    rtb_Hypot_g5 = 0.0;
  } else {
    rtb_Hypot_g5 = Robot_Control_DW.UnitDelay_DSTATE_eo;
  }

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S56>/Constant'
   *  Constant: '<S69>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S69>/Compare'
   *  Sum: '<S56>/Sum'
   *  Switch: '<S56>/Switch'
   */
  if ((rtb_Intake_Arm_Cycle || ((rtb_Hypot_g5 + 0.02) <=
        Rebuilt_Roller_Intake_In_Delay)) || rtb_LogicalOperator1_ms) {
    rtb_Saturation_h = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Saturation_h = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S57>/Logical Operator1' incorporates:
   *  Constant: '<S70>/Constant'
   *  RelationalOperator: '<S70>/Compare'
   */
  rtb_LogicalOperator1_ms = !(rtb_Saturation_h == 0.0);

  /* Sum: '<S71>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S57>/Subtract'
   */
  rtb_Error_n = rtb_Saturation_h - Robot_Control_U.Measured_Intake_Roller_Speed;

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
  rtb_Product_ld = rtb_Sum1_fh * 0.0;

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
  rtb_Integral_hv = rtb_Product_ld - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S71>/Saturation' */
  if (rtb_Integral_hv > 0.1) {
    rtb_Integral_hv = 0.1;
  } else if (rtb_Integral_hv < -0.1) {
    rtb_Integral_hv = -0.1;
  }

  /* Sum: '<S71>/Add' incorporates:
   *  Gain: '<S71>/Gain'
   *  Gain: '<S71>/Gain1'
   *  Saturate: '<S71>/Saturation'
   *  Sum: '<S71>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Rebuilt_Roller_Motor_Gain_FF *
    rtb_Saturation_h) + (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) +
    rtb_Integral_hv;

  /* Switch: '<S57>/Switch1' incorporates:
   *  Abs: '<S57>/Abs'
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Constant2'
   *  Logic: '<S57>/Logical Operator'
   *  Logic: '<S57>/Logical Operator1'
   *  RelationalOperator: '<S57>/LessThan'
   *  UnitDelay: '<S57>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_ms) {
    rtb_LogicalOperator1 = true;
  } else {
    rtb_LogicalOperator1 = (rtb_LogicalOperator1_ms &&
      (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S57>/Switch1' */

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S71>/Constant4'
   */
  if (rtb_LogicalOperator1) {
    /* Sum: '<S71>/Sum2' incorporates:
     *  Gain: '<S71>/Gain2'
     *  Sum: '<S71>/Sum'
     *  UnitDelay: '<S71>/Unit Delay'
     */
    rtb_Saturation_h = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S71>/Subtract' incorporates:
     *  Constant: '<S71>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_MatrixConcatenate_b_idx_0;

    /* Switch: '<S74>/Switch2' incorporates:
     *  Constant: '<S71>/Constant'
     *  RelationalOperator: '<S74>/LowerRelop1'
     *  Sum: '<S71>/Subtract'
     */
    if (!(rtb_Saturation_h > (1.0 - rtb_MatrixConcatenate_b_idx_0))) {
      /* Sum: '<S71>/Subtract1' incorporates:
       *  Constant: '<S71>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_MatrixConcatenate_b_idx_0;

      /* Switch: '<S74>/Switch' incorporates:
       *  Constant: '<S71>/Constant1'
       *  RelationalOperator: '<S74>/UpperRelop'
       *  Sum: '<S71>/Subtract1'
       */
      if (!(rtb_Saturation_h < (-1.0 - rtb_MatrixConcatenate_b_idx_0))) {
        rtb_Error_n = rtb_Saturation_h;
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

  /* Switch: '<S57>/Switch2' incorporates:
   *  Logic: '<S57>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_ms) {
    /* Sum: '<S71>/Add1' */
    rtb_Integral_hv = rtb_MatrixConcatenate_b_idx_0 + rtb_Error_n;

    /* Saturate: '<S71>/Saturation2' */
    if (rtb_Integral_hv > 1.0) {
      /* Switch: '<S57>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Integral_hv < -1.0) {
      /* Switch: '<S57>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S57>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Integral_hv;
    }

    /* End of Saturate: '<S71>/Saturation2' */
  } else {
    /* Switch: '<S57>/Switch2' incorporates:
     *  Constant: '<S57>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S57>/Switch2' */

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

  /* Switch: '<S68>/Init' incorporates:
   *  UnitDelay: '<S68>/FixPt Unit Delay1'
   *  UnitDelay: '<S68>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Saturation_h = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Saturation_h = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S68>/Init' */

  /* Sum: '<S66>/Sum1' */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    rtb_Saturation_h;

  /* Switch: '<S67>/Switch2' incorporates:
   *  Constant: '<S55>/Constant1'
   *  Constant: '<S55>/Constant3'
   *  RelationalOperator: '<S67>/LowerRelop1'
   *  RelationalOperator: '<S67>/UpperRelop'
   *  Switch: '<S67>/Switch'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > Rebuilt_Intake_RL_Inc) {
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Inc;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S67>/Switch2' */

  /* Sum: '<S66>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_MatrixConcatenate_b_idx_0 +
    rtb_Saturation_h;

  /* Sum: '<S62>/Sum' */
  rtb_Saturation_h = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_B.RB_Intake_Arm_Angle_Mod;

  /* Sum: '<S64>/Sum1' incorporates:
   *  Constant: '<S62>/Constant2'
   *  Product: '<S64>/Product'
   *  Sum: '<S64>/Sum'
   *  UnitDelay: '<S64>/Unit Delay1'
   */
  rtb_Sum1_dj = ((rtb_Saturation_h - Robot_Control_DW.UnitDelay1_DSTATE_c) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S62>/Product' incorporates:
   *  Constant: '<S62>/Constant3'
   */
  rtb_Product_ej = rtb_Sum1_dj * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S63>/Diff' incorporates:
   *  UnitDelay: '<S63>/UD'
   *
   * Block description for '<S63>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S63>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integral_hv = rtb_Product_ej - Robot_Control_DW.UD_DSTATE_g;

  /* Saturate: '<S62>/Saturation' */
  if (rtb_Integral_hv > 0.1) {
    rtb_Integral_hv = 0.1;
  } else if (rtb_Integral_hv < -0.1) {
    rtb_Integral_hv = -0.1;
  }

  /* Sum: '<S62>/Add' incorporates:
   *  Gain: '<S62>/Gain'
   *  Gain: '<S62>/Gain1'
   *  Saturate: '<S62>/Saturation'
   */
  rtb_Integral_hv += (0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
    (Rebuilt_Intake_Arm_Gain_P * rtb_Saturation_h);

  /* Sum: '<S62>/Subtract' incorporates:
   *  Constant: '<S62>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Integral_hv;

  /* Sum: '<S62>/Sum2' incorporates:
   *  Gain: '<S62>/Gain2'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  rtb_Saturation_h = (0.0 * rtb_Saturation_h) +
    Robot_Control_DW.UnitDelay_DSTATE_km;

  /* Switch: '<S65>/Switch2' incorporates:
   *  Constant: '<S62>/Constant'
   *  RelationalOperator: '<S65>/LowerRelop1'
   *  Sum: '<S62>/Subtract'
   */
  if (!(rtb_Saturation_h > (1.0 - rtb_Integral_hv))) {
    /* Sum: '<S62>/Subtract1' incorporates:
     *  Constant: '<S62>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Integral_hv;

    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S62>/Constant1'
     *  RelationalOperator: '<S65>/UpperRelop'
     *  Sum: '<S62>/Subtract1'
     */
    if (!(rtb_Saturation_h < (-1.0 - rtb_Integral_hv))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Saturation_h;
    }

    /* End of Switch: '<S65>/Switch' */
  }

  /* End of Switch: '<S65>/Switch2' */

  /* Saturate: '<S62>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > 0.1) {
    rtb_Saturation_h = 0.1;
  } else if (rtb_MatrixConcatenate_b_idx_0 < -0.1) {
    rtb_Saturation_h = -0.1;
  } else {
    rtb_Saturation_h = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S62>/Saturation1' */

  /* Switch: '<S54>/Switch2' incorporates:
   *  Constant: '<S58>/Constant'
   *  Constant: '<S59>/Constant'
   *  Constant: '<S60>/Constant'
   *  Constant: '<S61>/Constant'
   *  Logic: '<S54>/Logical Operator1'
   *  Logic: '<S54>/Logical Operator2'
   *  Logic: '<S54>/Logical Operator3'
   *  RelationalOperator: '<S58>/Compare'
   *  RelationalOperator: '<S59>/Compare'
   *  RelationalOperator: '<S60>/Compare'
   *  RelationalOperator: '<S61>/Compare'
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
    /* Sum: '<S62>/Add1' */
    rtb_Integral_hv += rtb_Saturation_h;

    /* Saturate: '<S62>/Saturation2' */
    if (rtb_Integral_hv > 1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Integral_hv < -1.0) {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S54>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Integral_hv;
    }

    /* End of Saturate: '<S62>/Saturation2' */
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

  /* Update for UnitDelay: '<S363>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S363>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 0U;

  /* Update for UnitDelay: '<S184>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_o = rtb_Merge1;

  /* Update for UnitDelay: '<S185>/Unit Delay' incorporates:
   *  Constant: '<S185>/Constant4'
   *  Sum: '<S185>/Sum'
   *  Switch: '<S185>/Switch'
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

  /* Update for UnitDelay: '<S386>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Switch_cn;

  /* Update for UnitDelay: '<S385>/UD'
   *
   * Block description for '<S385>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Switch1_n;

  /* Update for UnitDelay: '<S383>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Switch2_hw;

  /* Update for UnitDelay: '<S365>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Init_o;

  /* Update for UnitDelay: '<S380>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S380>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S380>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S364>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S373>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S373>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 0U;

  /* Update for UnitDelay: '<S373>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S339>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Init;

  /* Update for UnitDelay: '<S338>/UD'
   *
   * Block description for '<S338>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2_h;

  /* Update for UnitDelay: '<S332>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S276>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S275>/UD'
   *
   * Block description for '<S275>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S269>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S287>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Add_ju;

  /* Update for UnitDelay: '<S286>/UD'
   *
   * Block description for '<S286>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_pt;

  /* Update for UnitDelay: '<S272>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S297>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_fn;

  /* Update for UnitDelay: '<S296>/UD'
   *
   * Block description for '<S296>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S290>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S308>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Switch2_e;

  /* Update for UnitDelay: '<S307>/UD'
   *
   * Block description for '<S307>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_hi;

  /* Update for UnitDelay: '<S293>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S318>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S317>/UD'
   *
   * Block description for '<S317>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S311>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S329>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S328>/UD'
   *
   * Block description for '<S328>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_k;

  /* Update for UnitDelay: '<S314>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_m;

  /* Update for UnitDelay: '<S350>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S349>/UD'
   *
   * Block description for '<S349>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_nz;

  /* Update for UnitDelay: '<S335>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_p;

  /* Update for UnitDelay: '<S200>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_de;

  /* Update for UnitDelay: '<S199>/UD'
   *
   * Block description for '<S199>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_ih;

  /* Update for UnitDelay: '<S198>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S141>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Compare_ky;

  /* Update for UnitDelay: '<S132>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S132>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S56>/Unit Delay' incorporates:
   *  Constant: '<S56>/Constant'
   *  Sum: '<S56>/Sum'
   *  Switch: '<S56>/Switch'
   */
  Robot_Control_DW.UnitDelay_DSTATE_eo = rtb_Hypot_g5 + 0.02;

  /* Update for UnitDelay: '<S73>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_fh;

  /* Update for UnitDelay: '<S72>/UD'
   *
   * Block description for '<S72>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_ld;

  /* Update for UnitDelay: '<S71>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S57>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S53>/Delay Input1'
   *
   * Block description for '<S53>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S68>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S68>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S64>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_c = rtb_Sum1_dj;

  /* Update for UnitDelay: '<S63>/UD'
   *
   * Block description for '<S63>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_g = rtb_Product_ej;

  /* Update for UnitDelay: '<S62>/Unit Delay' */
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

  /* Start for If: '<S135>/If' */
  Robot_Control_DW.If_ActiveSubsystem_n = -1;

  /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S47>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_j = 1U;

  /* InitializeConditions for UnitDelay: '<S50>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S75>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S363>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_o = 1U;

  /* InitializeConditions for UnitDelay: '<S380>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S373>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_cc = 1U;

  /* InitializeConditions for UnitDelay: '<S132>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S68>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S443>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S208>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S204>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S208>/Robot_Index_Is_Valid' */
  /* Start for If: '<S211>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S211>/Circle_Check_Valid' */
  /* Start for If: '<S213>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S211>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S208>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S178>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hb = Rebuilt_Match_Time_Auto_Timer;

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem1' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem2' */
  /* InitializeConditions for UnitDelay: '<S180>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_hz = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem2' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem3' */
  Robot_C_IfActionSubsystem1_Init(&Robot_Control_DW.IfActionSubsystem3);

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem3' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem4' */
  /* InitializeConditions for UnitDelay: '<S182>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = Rebuilt_Match_Time_Shift_Timer;

  /* End of SystemInitialize for SubSystem: '<S135>/If Action Subsystem4' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/If Action Subsystem5' */
  /* InitializeConditions for UnitDelay: '<S183>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_du = Rebuilt_Match_Time_End_Game_Timer;

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
