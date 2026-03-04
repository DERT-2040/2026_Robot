/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.463
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Mar  3 09:51:54 2026
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
#include "rt_hypotd_snf.h"
#include "rt_atan2d_snf.h"
#include <string.h>
#include "rt_modd_snf.h"
#include "LookUp_real_T_real_T.h"
#include "look1_binlcpw.h"

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

/* Exported block parameters */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S388>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S384>/Constant'
                                        *   '<S384>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S388>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S384>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S222>/Constant3'
                                        *   '<S243>/Constant3'
                                        *   '<S264>/Constant3'
                                        *   '<S285>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S222>/Constant2'
                                   *   '<S243>/Constant2'
                                   *   '<S264>/Constant2'
                                   *   '<S285>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S222>/Saturation'
                                        *   '<S243>/Saturation'
                                        *   '<S264>/Saturation'
                                        *   '<S285>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S222>/Saturation'
                                        *   '<S243>/Saturation'
                                        *   '<S264>/Saturation'
                                        *   '<S285>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S222>/Gain'
                                            *   '<S243>/Gain'
                                            *   '<S264>/Gain'
                                            *   '<S285>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S222>/Gain2'
                                        *   '<S243>/Gain2'
                                        *   '<S264>/Gain2'
                                        *   '<S285>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S222>/Saturation1'
                                         *   '<S243>/Saturation1'
                                         *   '<S264>/Saturation1'
                                         *   '<S285>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S222>/Saturation1'
                                        *   '<S243>/Saturation1'
                                        *   '<S264>/Saturation1'
                                        *   '<S285>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S222>/Gain1'
                                        *   '<S243>/Gain1'
                                        *   '<S264>/Gain1'
                                        *   '<S285>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S227>/Constant'
                            *   '<S248>/Constant'
                            *   '<S269>/Constant'
                            *   '<S290>/Constant'
                            */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S141>/BlueAllianceZoneX'
                                         *   '<S143>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S120>/Constant8'
                                        */
real_T Field_Blue_Pass_X = 1.9889;     /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S120>/Blue_Top'
                                        */
real_T Field_Hub_Y = 4.0345;           /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S120>/Constant1'
                                        *   '<S120>/Switch3'
                                        */
real_T Field_Pass_Y_Bottom = 0.63297;  /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S120>/Blue_Top2'
                                        */
real_T Field_Pass_Y_Top = 7.4364;      /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S120>/Blue_Top3'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S142>/RedAllianceZoneX'
                                         *   '<S144>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S120>/Constant9'
                                        */
real_T Field_Red_Pass_X = 14.552;      /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S120>/Blue_Top1'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S374>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S374>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = -1.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S115>/Constant'
                                       */
real_T Rebuilt_Feeder_Motor_Gain_FF = 0.00012732;/* Variable: Rebuilt_Feeder_Motor_Gain_FF
                                                  * Referenced by: '<S12>/Constant'
                                                  */
real_T Rebuilt_Hood_Servo_Pos_Max = 1.0;/* Variable: Rebuilt_Hood_Servo_Pos_Max
                                         * Referenced by: '<S10>/Saturation'
                                         */
real_T Rebuilt_Hood_Servo_Pos_Min = 0.05;/* Variable: Rebuilt_Hood_Servo_Pos_Min
                                          * Referenced by: '<S10>/Saturation'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S100>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S100>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S34>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_I = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_I
                                        * Referenced by: '<S34>/Gain2'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                        * Referenced by: '<S34>/Gain1'
                                        */
real_T Rebuilt_Intake_Arm_Integral_Enable = 0.0;
                                 /* Variable: Rebuilt_Intake_Arm_Integral_Enable
                                  * Referenced by: '<S30>/Constant1'
                                  */
real_T Rebuilt_Intake_Cycle_Angle_In = 20.0;
                                      /* Variable: Rebuilt_Intake_Cycle_Angle_In
                                       * Referenced by: '<S6>/Chart'
                                       */
real_T Rebuilt_Intake_Cycle_Angle_Out = 70.0;
                                     /* Variable: Rebuilt_Intake_Cycle_Angle_Out
                                      * Referenced by: '<S6>/Chart'
                                      */
real_T Rebuilt_Intake_Des_Angle_In = 0.0;/* Variable: Rebuilt_Intake_Des_Angle_In
                                          * Referenced by: '<S6>/Chart'
                                          */
real_T Rebuilt_Intake_Des_Angle_Out = 90.0;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by: '<S6>/Chart'
                                            */
real_T Rebuilt_Intake_RL_Dec = -1.8;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S31>/Constant1'
                                        */
real_T Rebuilt_Intake_RL_Inc = 1.8;    /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S31>/Constant3'
                                        */
real_T Rebuilt_Negative_Feeder_Speed = -1000.0;
                                      /* Variable: Rebuilt_Negative_Feeder_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Roller_Desired_Speed = 0.0;/* Variable: Rebuilt_Roller_Desired_Speed
                                           * Referenced by: '<S6>/Constant'
                                           */
real_T Rebuilt_Roller_Error_Integral_Enable = 0.0;
                               /* Variable: Rebuilt_Roller_Error_Integral_Enable
                                * Referenced by: '<S32>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                           * Referenced by: '<S42>/Gain'
                                           */
real_T Rebuilt_Roller_Motor_Gain_I = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                          * Referenced by: '<S42>/Gain2'
                                          */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                          * Referenced by: '<S42>/Gain1'
                                          */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S121>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S121>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S121>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S121>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S121>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S121>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S121>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 9.0;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S121>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S117>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S117>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S117>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 4.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S117>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 3.4; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S117>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 3.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S117>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 2.8; /* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S117>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 2.5; /* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S117>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S118>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S118>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S118>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S118>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S118>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S118>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S118>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 1.0; /* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S118>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S108>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S108>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.7;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S108>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2900.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S131>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 3000.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S131>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3250.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S131>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3400.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S131>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3575.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S131>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3700.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S131>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3850.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S131>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S131>/Constant1'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_I_0 = 2900.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S130>/Constant5'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_1 = 3000.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S130>/Constant6'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_2 = 3250.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S130>/Constant7'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_3 = 3400.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S130>/Constant8'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_4 = 3575.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S130>/Constant9'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_5 = 3700.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S130>/Constant10'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_6 = 3850.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S130>/Constant2'
                                       */
real_T Rebuilt_Shoot_Shooter_Spd_I_7 = 4500.0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S130>/Constant1'
                                       */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S124>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S124>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S124>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S124>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S124>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S124>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S124>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S124>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S128>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S109>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S146>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S146>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.0005;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                              * Referenced by: '<S146>/Gain1'
                                              */
real_T Rebuilt_Shot_Init_Time = 0.4;   /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S119>/Constant2'
                                        */
real_T Rebuilt_Target_Feeder_Speed = 3360.0;/* Variable: Rebuilt_Target_Feeder_Speed
                                             * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                             */
real_T Rebuilt_Target_Transfer_Speed = 4000.0;
                                      /* Variable: Rebuilt_Target_Transfer_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Transfer_Error_Integral_Enable = 300.0;
                             /* Variable: Rebuilt_Transfer_Error_Integral_Enable
                              * Referenced by: '<S111>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S151>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S151>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S151>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S373>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S371>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S373>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S374>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S374>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S211>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S211>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S158>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S171>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S211>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S318>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S318>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S318>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S318>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S318>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S318>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S335>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S335>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S335>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S335>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S334>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S335>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S335>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S335>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S335>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S335>/Constant1'
                                   *   '<S335>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S335>/Constant'
                                   *   '<S335>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S225>/Constant3'
                                        *   '<S246>/Constant3'
                                        *   '<S267>/Constant3'
                                        *   '<S288>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S225>/Constant2'
                                *   '<S246>/Constant2'
                                *   '<S267>/Constant2'
                                *   '<S288>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S225>/Saturation'
                                           *   '<S246>/Saturation'
                                           *   '<S267>/Saturation'
                                           *   '<S288>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S225>/Saturation'
                                          *   '<S246>/Saturation'
                                          *   '<S267>/Saturation'
                                          *   '<S288>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S225>/Gain2'
                                         *   '<S246>/Gain2'
                                         *   '<S267>/Gain2'
                                         *   '<S288>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S225>/Saturation1'
                                             *   '<S246>/Saturation1'
                                             *   '<S267>/Saturation1'
                                             *   '<S288>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S225>/Saturation1'
                                            *   '<S246>/Saturation1'
                                            *   '<S267>/Saturation1'
                                            *   '<S288>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S225>/Gain1'
                                        *   '<S246>/Gain1'
                                        *   '<S267>/Gain1'
                                        *   '<S288>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S317>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S317>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S317>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S317>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S317>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S317>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S373>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S373>/Constant1'
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
                                      * Referenced by: '<S372>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S372>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S372>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S305>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S305>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S305>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S305>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S305>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S305>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S374>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S373>/Dead Zone'
                                        *   '<S374>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S373>/Dead Zone'
                                        *   '<S374>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S371>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S371>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S371>/Constant4'
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
                                        * Referenced by: '<S371>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S371>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S371>/Constant5'
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
                                        *   '<S371>/Constant11'
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
 * Output and update for action system:
 *    '<S106>/If Action Subsystem'
 *    '<S106>/If Action Subsystem5'
 */
void Robot_Control_IfActionSubsystem(boolean_T *rty_IsBlueActive, boolean_T
  *rty_IsRedActive)
{
  /* SignalConversion generated from: '<S132>/IsBlueActive' incorporates:
   *  Constant: '<S132>/Constant'
   */
  *rty_IsBlueActive = true;

  /* SignalConversion generated from: '<S132>/IsRedActive' incorporates:
   *  Constant: '<S132>/Constant'
   */
  *rty_IsRedActive = true;
}

/*
 * Output and update for action system:
 *    '<S106>/If Action Subsystem1'
 *    '<S106>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive)
{
  /* Logic: '<S133>/NOT' incorporates:
   *  SignalConversion generated from: '<S133>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S133>/IsRedActive' */
  *rty_IsRedActive = rtu_IsBlueInactiveFirst;
}

/*
 * Output and update for action system:
 *    '<S106>/If Action Subsystem2'
 *    '<S106>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive)
{
  /* Logic: '<S134>/NOT1' incorporates:
   *  SignalConversion generated from: '<S134>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S134>/IsBlueActive' */
  *rty_IsBlueActive = rtu_IsBlueInactiveFirst;
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
  const real_T *rtb_Spline_Ref_Poses_0;
  real_T rtb_Add_f1;
  real_T rtb_Add_fd;
  real_T rtb_Add_h5;
  real_T rtb_Add_oy;
  real_T rtb_DeadZone;
  real_T rtb_Error_e;
  real_T rtb_Error_h;
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
  real_T rtb_Minus_k_idx_1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_di;
  real_T rtb_Product_hm;
  real_T rtb_Product_i;
  real_T rtb_Product_lf;
  real_T rtb_Product_lo;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_la;
  real_T rtb_Sum1_fh;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1;
  real_T rtb_Switch2;
  real_T rtb_Switch2_cw;
  real_T rtb_Switch2_nf;
  real_T rtb_Switch2_ow;
  real_T rtb_Switch2_p0;
  real_T rtb_Switch2_p2;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s183_iter;
  uint16_T s208_iter;
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T rtb_Button_Shoot_Enable;
  uint8_T rtb_Button_Spinup_Enable;
  uint8_T rtb_Desired_Pipeline;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T rtb_AND1_c;
  boolean_T rtb_AND4;
  boolean_T rtb_Compare_a;
  boolean_T rtb_Disable_Wheels;
  boolean_T rtb_Enable_Wheels;
  boolean_T rtb_Intake_Arm_Cycle;
  boolean_T rtb_Intake_Arm_Move_In;
  boolean_T rtb_Intake_Arm_Move_Out;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation_g;
  boolean_T rtb_LogicalOperator1_n;
  boolean_T rtb_Reset_Wheel_Offsets;
  boolean_T rtb_Swerve_Motors_Disabled;

  /* RelationalOperator: '<S25>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *  UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Joystick_Left_B11 >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S26>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *  UnitDelay: '<S26>/Delay Input1'
   *
   * Block description for '<S26>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets =
    (Robot_Control_U.Joystick_Left_B12 > Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S27>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *  UnitDelay: '<S27>/Delay Input1'
   *
   * Block description for '<S27>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Joystick_Left_B13 >
    Robot_Control_DW.DelayInput1_DSTATE_n);

  /* SignalConversion: '<S5>/Signal Copy1' incorporates:
   *  Inport: '<Root>/Joystick_Left_X'
   */
  Robot_Control_B.Drive_Joystick_X = Robot_Control_U.Joystick_Left_X;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y = Robot_Control_U.Joystick_Left_Y;

  /* SignalConversion: '<S5>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z = Robot_Control_U.Joystick_Left_Z;

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
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

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Toward_Driver = (Robot_Control_U.Joystick_Right_POV ==
    180.0);

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Right_Driver = (Robot_Control_U.Joystick_Right_POV ==
    90.0);

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Left_Driver = (Robot_Control_U.Joystick_Right_POV ==
    270.0);

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
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

  /* If: '<S400>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S400>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S403>/Action Port'
     */
    /* Product: '<S403>/Product' incorporates:
     *  Constant: '<S403>/Constant1'
     *  Constant: '<S403>/Constant2'
     *  Math: '<S403>/Math Function'
     */
    rtb_Init_o = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495)
      * 111.0;

    /* End of Outputs for SubSystem: '<S400>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S400>/Subsystem' incorporates:
     *  ActionPort: '<S404>/Action Port'
     */
    /* SignalConversion generated from: '<S404>/Out1' incorporates:
     *  Constant: '<S404>/Constant'
     */
    rtb_Init_o = 0.0;

    /* End of Outputs for SubSystem: '<S400>/Subsystem' */
  }

  /* End of If: '<S400>/If' */

  /* Gain: '<S401>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S402>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Init_o * cos(rtb_Sin4)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S402>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Init_o * sin(rtb_Sin4)) +
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
     *  Constant: '<S4>/Constant8'
     *  Merge: '<S9>/Merge8'
     */
    rtb_Spline_Ref_Poses_0 = &rtCP_Constant8_Value_o[0];

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
    Robot_Control_B.Spline_Num_Poses = 9.0;

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
    rtb_Swerve_Motors_Disabled = true;

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
    rtb_Button_Spinup_Enable = 0U;

    /* SignalConversion generated from: '<S4>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S4>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

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

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/Spline_Ref_Poses' incorporates:
     *  Constant: '<S18>/Constant8'
     *  Merge: '<S9>/Merge8'
     */
    rtb_Spline_Ref_Poses_0 = &rtCP_Constant8_Value_m[0];

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

    /* Merge: '<S9>/Merge7' incorporates:
     *  Constant: '<S18>/Constant7'
     *  SignalConversion generated from: '<S2>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = true;

    /* Merge: '<S9>/Merge3' incorporates:
     *  Constant: '<S18>/Constant3'
     *  SignalConversion generated from: '<S2>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S9>/Merge9' incorporates:
     *  Constant: '<S18>/Constant9'
     *  SignalConversion generated from: '<S2>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 9.0;

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
    rtb_Swerve_Motors_Disabled = false;

    /* SignalConversion generated from: '<S2>/Desired_Pipeline' incorporates:
     *  Constant: '<S2>/Constant'
     */
    rtb_Desired_Pipeline = 0U;

    /* SignalConversion generated from: '<S2>/Button_Spinup_Enable' incorporates:
     *  Constant: '<S2>/Constant11'
     */
    rtb_Button_Spinup_Enable = 0U;

    /* SignalConversion generated from: '<S2>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S2>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

    /* SignalConversion generated from: '<S2>/Intake_Arm_Move_In' incorporates:
     *  Constant: '<S2>/Constant16'
     */
    rtb_Intake_Arm_Move_In = false;

    /* SignalConversion generated from: '<S2>/Intake_Arm_Move_Out' incorporates:
     *  Constant: '<S2>/Constant17'
     */
    rtb_Intake_Arm_Move_Out = false;

    /* SignalConversion generated from: '<S2>/Intake_Arm_Move_Cycle' incorporates:
     *  Constant: '<S2>/Constant19'
     */
    rtb_Intake_Arm_Cycle = false;

    /* SignalConversion generated from: '<S2>/Intake_Roller_On' incorporates:
     *  Constant: '<S2>/Constant20'
     */
    rtb_LogicalOperator1_n = false;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S373>/Unit Delay1'
       *  UnitDelay: '<S373>/Unit Delay2'
       *  UnitDelay: '<S373>/Unit Delay3'
       *  UnitDelay: '<S373>/Unit Delay4'
       *  UnitDelay: '<S376>/Delay Input1'
       *  UnitDelay: '<S377>/Delay Input1'
       *  UnitDelay: '<S378>/Delay Input1'
       *  UnitDelay: '<S379>/Delay Input1'
       *  UnitDelay: '<S381>/Delay Input1'
       *  UnitDelay: '<S387>/Unit Delay'
       *  UnitDelay: '<S387>/Unit Delay1'
       *  UnitDelay: '<S391>/FixPt Unit Delay1'
       *  UnitDelay: '<S391>/FixPt Unit Delay2'
       *
       * Block description for '<S376>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S377>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S378>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S379>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S381>/Delay Input1':
       *
       *  Store in Global RAM
       */
      Robot_Control_DW.DelayInput1_DSTATE_j = false;
      Robot_Control_DW.DelayInput1_DSTATE_m = false;
      Robot_Control_DW.DelayInput1_DSTATE_k = false;
      Robot_Control_DW.DelayInput1_DSTATE_g = false;
      Robot_Control_DW.DelayInput1_DSTATE_g2 = false;
      Robot_Control_DW.UnitDelay2_DSTATE = false;
      Robot_Control_DW.UnitDelay4_DSTATE = false;
      Robot_Control_DW.UnitDelay3_DSTATE = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_j2 = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_lw = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_p = 0.0;
      Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;
      Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Teleop' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* SignalConversion generated from: '<S15>/Spline_Ref_Poses' incorporates:
     *  Constant: '<S15>/Constant4'
     *  Merge: '<S9>/Merge8'
     */
    rtb_Spline_Ref_Poses_0 = &rtCP_Constant4_Value_i[0];

    /* Switch: '<S371>/Switch4' incorporates:
     *  Constant: '<S396>/Constant'
     *  Constant: '<S399>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S396>/Compare'
     *  RelationalOperator: '<S399>/Compare'
     *  Switch: '<S371>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S371>/Switch4' incorporates:
       *  Constant: '<S371>/Constant8'
       *  Sum: '<S371>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S371>/Switch5' incorporates:
       *  Constant: '<S371>/Constant7'
       *  Gain: '<S371>/Gain'
       *  Sum: '<S371>/Subtract5'
       *  Switch: '<S371>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S371>/Switch4' incorporates:
       *  Constant: '<S371>/Constant6'
       *  Switch: '<S371>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S371>/Switch4' */

    /* Logic: '<S371>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S371>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S373>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_oy = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_oy = 0.0;
    } else {
      rtb_Add_oy = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S373>/Add' incorporates:
     *  Constant: '<S373>/Constant'
     *  Constant: '<S373>/Constant1'
     *  DeadZone: '<S373>/Dead Zone'
     *  Lookup_n-D: '<S373>/Modulation_Str_Y_Rel'
     *  Product: '<S373>/Product'
     *  Product: '<S373>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Add_h5 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                  Steering_Relative_Gain) + (rtb_Add_oy * Steering_Twist_Gain);

    /* RelationalOperator: '<S375>/Compare' incorporates:
     *  Constant: '<S375>/Constant'
     */
    rtb_Compare_a = (rtb_Add_h5 == 0.0);

    /* Logic: '<S373>/AND2' incorporates:
     *  RelationalOperator: '<S376>/FixPt Relational Operator'
     *  RelationalOperator: '<S377>/FixPt Relational Operator'
     *  RelationalOperator: '<S378>/FixPt Relational Operator'
     *  RelationalOperator: '<S379>/FixPt Relational Operator'
     *  UnitDelay: '<S376>/Delay Input1'
     *  UnitDelay: '<S377>/Delay Input1'
     *  UnitDelay: '<S378>/Delay Input1'
     *  UnitDelay: '<S379>/Delay Input1'
     *
     * Block description for '<S376>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S377>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S378>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S379>/Delay Input1':
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

    /* Logic: '<S373>/AND1' incorporates:
     *  Logic: '<S373>/AND3'
     *  UnitDelay: '<S373>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_a && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE)));

    /* Logic: '<S373>/AND4' incorporates:
     *  Logic: '<S373>/AND8'
     *  UnitDelay: '<S373>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_a && (!rtb_Intake_Arm_Cycle)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S373>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S373>/Switch8' incorporates:
     *  Constant: '<S382>/Constant'
     *  Logic: '<S373>/AND9'
     *  RelationalOperator: '<S381>/FixPt Relational Operator'
     *  RelationalOperator: '<S382>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S381>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S381>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_Compare_a) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j))) ||
         (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_B.RB_Shooter_Active)) {
      /* Switch: '<S373>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S373>/Switch8' incorporates:
       *  UnitDelay: '<S373>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S373>/Switch8' */

    /* Switch: '<S373>/Switch4' incorporates:
     *  Constant: '<S373>/Constant5'
     *  Switch: '<S373>/Switch1'
     *  Switch: '<S373>/Switch5'
     *  Switch: '<S373>/Switch6'
     *  Switch: '<S373>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Init_o = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S373>/Switch5' incorporates:
       *  Constant: '<S373>/Constant6'
       */
      rtb_Init_o = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S373>/Switch6' incorporates:
       *  Constant: '<S373>/Constant7'
       *  Switch: '<S373>/Switch5'
       */
      rtb_Init_o = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S373>/Switch7' incorporates:
       *  Constant: '<S373>/Constant8'
       *  Switch: '<S373>/Switch5'
       *  Switch: '<S373>/Switch6'
       */
      rtb_Init_o = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S373>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S373>/Switch5'
       *  Switch: '<S373>/Switch6'
       *  Switch: '<S373>/Switch7'
       */
      rtb_Init_o = 0.0;
    } else {
      /* Switch: '<S373>/Switch6' incorporates:
       *  Switch: '<S373>/Switch5'
       *  Switch: '<S373>/Switch7'
       *  UnitDelay: '<S373>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S373>/Switch4' */

    /* Switch: '<S373>/Switch2' incorporates:
     *  Switch: '<S373>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S373>/Switch2' incorporates:
       *  Constant: '<S373>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S373>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Init_o;
    } else {
      /* Switch: '<S373>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S373>/Switch3' incorporates:
       *  Constant: '<S373>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S373>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S373>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S372>/Switch1' incorporates:
     *  Constant: '<S372>/Constant5'
     *  Constant: '<S372>/Constant8'
     *  DataTypeConversion: '<S372>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_a;
    }

    /* End of Switch: '<S372>/Switch1' */

    /* Lookup_n-D: '<S374>/Modulation_Drv' incorporates:
     *  Math: '<S374>/Magnitude'
     */
    rtb_Sin4 = look1_binlcpw(rt_hypotd_snf(Robot_Control_B.Drive_Joystick_X,
      Robot_Control_B.Drive_Joystick_Y), rtCP_Modulation_Drv_bp01Data,
      rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S385>/Compare' incorporates:
     *  Constant: '<S385>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Sin4 == 0.0);

    /* DeadZone: '<S374>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S374>/Dead Zone' */

    /* Logic: '<S374>/Logical Operator' incorporates:
     *  Constant: '<S386>/Constant'
     *  RelationalOperator: '<S386>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_DeadZone != 0.0) && rtb_Swerve_Motors_Disabled);

    /* Switch: '<S372>/Switch' incorporates:
     *  Constant: '<S372>/Constant5'
     *  Constant: '<S372>/Constant7'
     *  DataTypeConversion: '<S372>/Data Type Conversion'
     *  Logic: '<S374>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S372>/Switch' */

    /* Switch: '<S371>/Switch2' incorporates:
     *  Constant: '<S371>/Constant2'
     *  Constant: '<S395>/Constant'
     *  Constant: '<S398>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S395>/Compare'
     *  RelationalOperator: '<S398>/Compare'
     *  Sum: '<S371>/Subtract'
     *  Switch: '<S371>/Switch'
     *  Switch: '<S371>/Switch1'
     *  Switch: '<S371>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S371>/Switch2' incorporates:
       *  Constant: '<S371>/Constant5'
       *  Sum: '<S371>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S371>/Switch2' incorporates:
       *  Constant: '<S371>/Constant4'
       *  Sum: '<S371>/Subtract2'
       *  Switch: '<S371>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S371>/Switch1' incorporates:
       *  Constant: '<S371>/Constant1'
       *  Sum: '<S371>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S371>/Switch2' incorporates:
       *  Constant: '<S371>/Constant3'
       *  Switch: '<S371>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S371>/Switch1' incorporates:
       *  Constant: '<S371>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S371>/Switch2' */

    /* UnaryMinus: '<S371>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S387>/Switch1' incorporates:
     *  Constant: '<S392>/Constant'
     *  Constant: '<S393>/Constant'
     *  Logic: '<S387>/AND'
     *  RelationalOperator: '<S392>/Compare'
     *  RelationalOperator: '<S393>/Compare'
     *  Switch: '<S387>/Switch2'
     *  UnitDelay: '<S387>/Unit Delay'
     *  UnitDelay: '<S387>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_lw;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S387>/Switch1' */

    /* Switch: '<S374>/Switch1' incorporates:
     *  Logic: '<S374>/Logical Operator1'
     *  Switch: '<S374>/Switch4'
     *  Switch: '<S374>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S374>/Sign' */
      if (rtIsNaN(rtb_DeadZone)) {
        rtb_Add_oy = (rtNaN);
      } else if (rtb_DeadZone < 0.0) {
        rtb_Add_oy = -1.0;
      } else {
        rtb_Add_oy = (rtb_DeadZone > 0.0);
      }

      /* Switch: '<S374>/Switch5' incorporates:
       *  Constant: '<S374>/Constant3'
       *  Constant: '<S374>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Minus_k_idx_1 = -1.5707963267948966;
      } else {
        rtb_Minus_k_idx_1 = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S374>/Gain3'
       *  Signum: '<S374>/Sign'
       *  Sum: '<S374>/Add'
       *  Switch: '<S374>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_oy) +
        rtb_Minus_k_idx_1;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Switch: '<S374>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S374>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S374>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S374>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S374>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S374>/Switch4'
       *  Trigonometry: '<S374>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S374>/Switch1' */

    /* Switch: '<S384>/Switch1' incorporates:
     *  Constant: '<S384>/Constant'
     *  Constant: '<S384>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S384>/Switch1' */

    /* Switch: '<S391>/Init' incorporates:
     *  UnitDelay: '<S391>/FixPt Unit Delay1'
     *  UnitDelay: '<S391>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S391>/Init' */

    /* Sum: '<S389>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S390>/Switch2' incorporates:
     *  Constant: '<S388>/Constant1'
     *  Constant: '<S388>/Constant3'
     *  RelationalOperator: '<S390>/LowerRelop1'
     *  RelationalOperator: '<S390>/UpperRelop'
     *  Switch: '<S390>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S390>/Switch' incorporates:
       *  Constant: '<S388>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S390>/Switch2' */

    /* Sum: '<S389>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S374>/Switch8' incorporates:
     *  Logic: '<S374>/Logical Operator1'
     *  Switch: '<S374>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S374>/Switch' incorporates:
       *  Gain: '<S374>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_DeadZone;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S374>/Constant5'
       *  Gain: '<S374>/Gain2'
       *  Math: '<S374>/Magnitude1'
       *  MinMax: '<S374>/Min'
       *  Switch: '<S374>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S384>/Product' incorporates:
       *  Switch: '<S374>/Switch2'
       */
      rtb_Add_oy = rtb_Sin4 * rtb_Init;

      /* Saturate: '<S384>/Saturation' incorporates:
       *  Switch: '<S374>/Switch2'
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

      /* End of Saturate: '<S384>/Saturation' */
    }

    /* End of Switch: '<S374>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S373>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Add_h5;

    /* Switch: '<S371>/Switch6' incorporates:
     *  Constant: '<S371>/Constant11'
     *  Switch: '<S371>/Switch7'
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
    Robot_Control_B.Spline_Num_Poses = 9.0;

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
    rtb_Swerve_Motors_Disabled = false;

    /* RelationalOperator: '<S366>/Compare' incorporates:
     *  Constant: '<S366>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S369>/Compare' incorporates:
     *  Constant: '<S369>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S368>/Compare' incorporates:
     *  Constant: '<S368>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S367>/Compare' incorporates:
     *  Constant: '<S367>/Constant'
     *  Inport: '<Root>/Joystick_Right_B1'
     */
    rtb_LogicalOperator1_n = (Robot_Control_U.Joystick_Right_B1 != 0.0);

    /* SignalConversion: '<S15>/Signal Copy' incorporates:
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = Robot_Control_U.Gamepad_LB;

    /* SignalConversion: '<S15>/Signal Copy1' incorporates:
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = Robot_Control_U.Gamepad_RB;

    /* Update for UnitDelay: '<S381>/Delay Input1'
     *
     * Block description for '<S381>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_a;

    /* Update for UnitDelay: '<S380>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S380>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S376>/Delay Input1'
     *
     * Block description for '<S376>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S377>/Delay Input1'
     *
     * Block description for '<S377>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S378>/Delay Input1'
     *
     * Block description for '<S378>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S379>/Delay Input1'
     *
     * Block description for '<S379>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S373>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE = rtb_AND1_c;

    /* Update for UnitDelay: '<S373>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S373>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S373>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Init_o;

    /* Update for UnitDelay: '<S387>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_lw = rtb_Switch1;

    /* Update for UnitDelay: '<S387>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S391>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S391>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S391>/FixPt Unit Delay1' */
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
     *  Constant: '<S16>/Constant8'
     *  Merge: '<S9>/Merge8'
     */
    rtb_Spline_Ref_Poses_0 = &rtCP_Constant8_Value_h[0];

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
    Robot_Control_B.Spline_Num_Poses = 9.0;

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
      rtb_Swerve_Motors_Disabled = true;
    } else {
      rtb_Swerve_Motors_Disabled = ((!Robot_Control_B.Button_Enable_Wheels) &&
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
    rtb_Button_Spinup_Enable = 0U;

    /* SignalConversion generated from: '<S16>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S16>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

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

    /* SignalConversion: '<S16>/Signal Copy' */
    rtb_Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* SignalConversion: '<S16>/Signal Copy2' */
    rtb_Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* SignalConversion: '<S16>/Signal Copy1' */
    rtb_Reset_Wheel_Offsets = Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_Swerve_Motors_Disabled;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Reshape: '<S46>/Reshapey' incorporates:
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

  /* Delay: '<S46>/MemoryX' incorporates:
   *  Constant: '<S46>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S73>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S99>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S66>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S97>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S97>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S46>/C'
     *  Delay: '<S46>/MemoryX'
     *  Product: '<S99>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Init_o;

    /* Sum: '<S97>/Sum' incorporates:
     *  Constant: '<S46>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S97>/C[k]*xhat[k|k-1]'
     *  Product: '<S97>/D[k]*u[k]'
     *  Sum: '<S97>/Add1'
     */
    rtb_Sin4 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Add_h5 = rtb_Reshapey[0] - (rtb_Sin4 + rtb_Init_o);

    /* Product: '<S97>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S46>/C'
     *  Delay: '<S46>/MemoryX'
     *  Product: '<S99>/Product'
     */
    rtb_Init_o = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Init_o;

    /* Sum: '<S97>/Sum' incorporates:
     *  Constant: '<S46>/D'
     *  Product: '<S97>/C[k]*xhat[k|k-1]'
     *  Product: '<S97>/D[k]*u[k]'
     *  Sum: '<S97>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Sin4 + rtb_Init_o);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S97>/Product3' incorporates:
     *  Constant: '<S47>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Add_h5) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S99>/Add1' incorporates:
     *  Product: '<S99>/Product'
     */
    rtb_Init_o = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S97>/Product3' incorporates:
     *  Constant: '<S47>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Add_h5) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S99>/Add1' incorporates:
     *  Product: '<S99>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S99>/Product2' incorporates:
     *  Constant: '<S47>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Init_o) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Init_o) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S97>/Product3' incorporates:
       *  Outport: '<S97>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S99>/Product2' incorporates:
       *  Outport: '<S99>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S66>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S73>/Enabled Subsystem' */

  /* Sum: '<S73>/Add' incorporates:
   *  Delay: '<S46>/MemoryX'
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
   *  Constant: '<S208>/Constant'
   *  Logic: '<S208>/AND'
   *  MATLAB Function: '<S158>/Find closest index to curve'
   *  Product: '<S208>/Product'
   *  RelationalOperator: '<S208>/Relational Operator'
   *  RelationalOperator: '<S208>/Relational Operator1'
   *  Selector: '<S208>/Selector'
   *  Selector: '<S208>/Selector1'
   *  Selector: '<S209>/Selector'
   *  Sum: '<S208>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S161>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S164>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S166>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S161>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S156>/Action Port'
       */
      /* InitializeConditions for If: '<S13>/If' incorporates:
       *  UnitDelay: '<S156>/Unit Delay'
       *  UnitDelay: '<S157>/Unit Delay'
       *  UnitDelay: '<S159>/Unit Delay'
       *  UnitDelay: '<S159>/Unit Delay1'
       *  UnitDelay: '<S209>/Unit Delay'
       *  UnitDelay: '<S209>/Unit Delay1'
       */
      Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;
      Robot_Control_DW.UnitDelay_DSTATE_hn = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_f4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_g4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_le = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_k = 0.0;

      /* End of InitializeConditions for SubSystem: '<S13>/Spline Path Following Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S13>/Spline Path Following Enabled' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    /* Selector: '<S157>/Selector1' incorporates:
     *  Merge: '<S9>/Merge8'
     */
    for (i = 0; i < 10; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses_0[i];
      rtb_Ref_Poses[i + 10] = rtb_Spline_Ref_Poses_0[i + 10];
    }

    /* End of Selector: '<S157>/Selector1' */

    /* Lookup_n-D: '<S156>/Capture Radius' incorporates:
     *  UnitDelay: '<S156>/Unit Delay'
     */
    rtb_Add_h5 = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_hn,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S157>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S157>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S161>/If' incorporates:
     *  RelationalOperator: '<S161>/ '
     *  UnitDelay: '<S157>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <= 9.0));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S164>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S166>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S161>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S164>/Action Port'
       */
      /* InitializeConditions for If: '<S161>/If' incorporates:
       *  UnitDelay: '<S164>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S161>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S161>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S164>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S164>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S167>/Action Port'
       */
      /* If: '<S164>/If' incorporates:
       *  Selector: '<S157>/Selector1'
       *  Selector: '<S164>/Selector'
       *  Selector: '<S167>/Selector'
       */
      rtb_Init = rtb_Ref_Poses[((int32_T)Robot_Control_DW.UnitDelay_DSTATE_gh) -
        1];

      /* End of Outputs for SubSystem: '<S164>/Increment_If_Rectangle_Check' */

      /* Sum: '<S164>/Minus' incorporates:
       *  Concatenate: '<S157>/Matrix Concatenate2'
       *  Selector: '<S164>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Init;

      /* Outputs for IfAction SubSystem: '<S164>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S167>/Action Port'
       */
      /* If: '<S164>/If' incorporates:
       *  Selector: '<S157>/Selector1'
       *  Selector: '<S164>/Selector'
       *  Selector: '<S167>/Selector'
       *  Sum: '<S164>/Minus'
       */
      rtb_DeadZone = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S164>/Increment_If_Rectangle_Check' */

      /* Sum: '<S164>/Minus' incorporates:
       *  Concatenate: '<S157>/Matrix Concatenate2'
       *  Selector: '<S164>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_DeadZone;

      /* Math: '<S164>/Hypot' */
      rtb_Init_o = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S164>/Equal' */
      rtb_AND1_c = (Robot_Control_DW.UnitDelay_DSTATE_gh == 9.0);

      /* Switch: '<S164>/Switch' incorporates:
       *  Logic: '<S164>/AND'
       *  Logic: '<S164>/OR'
       *  RelationalOperator: '<S164>/Relational Operator'
       *  UnitDelay: '<S164>/Unit Delay'
       */
      rtb_Compare_a = ((Robot_Control_DW.UnitDelay_DSTATE_e4) || ((rtb_Init_o <=
        rtb_Add_h5) && rtb_AND1_c));

      /* If: '<S164>/If' */
      rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_o;
      if (!rtb_Compare_a) {
        if (!rtb_AND1_c) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Robot_Control_DW.If_ActiveSubsystem_o = rtAction;
      if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
        /* Disable for If: '<S166>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S164>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S166>/Action Port'
         */
        /* If: '<S166>/If' incorporates:
         *  RelationalOperator: '<S166>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh == 9.0));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S166>/Is_Last_Point' incorporates:
           *  ActionPort: '<S169>/Action Port'
           */
          /* InitializeConditions for If: '<S166>/If' incorporates:
           *  UnitDelay: '<S169>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S166>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S166>/Is_Last_Point' incorporates:
           *  ActionPort: '<S169>/Action Port'
           */
          /* Switch: '<S169>/Switch' incorporates:
           *  Constant: '<S171>/Constant'
           *  Logic: '<S169>/OR'
           *  RelationalOperator: '<S171>/Compare'
           *  UnitDelay: '<S169>/Unit Delay'
           */
          rtb_Is_Absolute_Steering = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
            (rtb_Init_o <= Spline_Stop_Radius));

          /* If: '<S169>/If' */
          if (rtb_Is_Absolute_Steering) {
            /* Outputs for IfAction SubSystem: '<S169>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S172>/Action Port'
             */
            /* Merge: '<S161>/Merge2' incorporates:
             *  Constant: '<S172>/Constant'
             *  SignalConversion generated from: '<S172>/Robot_Reached_Destination'
             */
            rtb_AND1_c = true;

            /* SignalConversion generated from: '<S172>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S172>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = false;

            /* End of Outputs for SubSystem: '<S169>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S169>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S173>/Action Port'
             */
            /* Merge: '<S161>/Merge2' incorporates:
             *  Constant: '<S173>/Constant'
             *  SignalConversion generated from: '<S173>/Robot_Reached_Destination'
             */
            rtb_AND1_c = false;

            /* SignalConversion generated from: '<S173>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S173>/Constant1'
             */
            rtb_Is_Absolute_Translation_g = true;

            /* End of Outputs for SubSystem: '<S169>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S169>/If' */

          /* Merge: '<S161>/Merge4' incorporates:
           *  SignalConversion: '<S169>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S169>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Is_Absolute_Steering;

          /* End of Outputs for SubSystem: '<S166>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S166>/Increment_Search' incorporates:
           *  ActionPort: '<S168>/Action Port'
           */
          /* Merge: '<S161>/Merge2' incorporates:
           *  Constant: '<S168>/Constant'
           *  SignalConversion generated from: '<S168>/Robot_Reached_Destination'
           */
          rtb_AND1_c = false;

          /* SignalConversion generated from: '<S168>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S168>/Constant1'
           */
          rtb_Is_Absolute_Translation_g = false;

          /* Merge: '<S161>/Merge4' incorporates:
           *  Constant: '<S170>/FixPt Constant'
           *  SignalConversion: '<S168>/Signal Copy'
           *  Sum: '<S170>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S166>/Increment_Search' */
        }

        /* End of If: '<S166>/If' */
        /* End of Outputs for SubSystem: '<S164>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S164>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S167>/Action Port'
         */
        /* Sum: '<S174>/FixPt Sum1' incorporates:
         *  Constant: '<S174>/FixPt Constant'
         */
        rtb_Init_o = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S167>/Selector1' incorporates:
         *  Selector: '<S157>/Selector1'
         */
        rtb_Switch2_p2 = rtb_Ref_Poses[((int32_T)rtb_Init_o) - 1];

        /* Sum: '<S175>/Subtract' incorporates:
         *  Selector: '<S167>/Selector1'
         *  Sum: '<S175>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_p2 - rtb_Init;

        /* Selector: '<S167>/Selector1' incorporates:
         *  Selector: '<S157>/Selector1'
         */
        rtb_Switch1 = rtb_Ref_Poses[((int32_T)rtb_Init_o) + 9];

        /* Sum: '<S175>/Subtract' incorporates:
         *  Selector: '<S167>/Selector1'
         *  Sum: '<S175>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1 - rtb_DeadZone;

        /* Math: '<S175>/Hypot' */
        rtb_Sin4 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S175>/Divide' */
        rtb_Init_o = rtb_Minus_n[1];

        /* UnaryMinus: '<S175>/Unary Minus' */
        rtb_Switch2_nf = rtb_Minus_n[0];

        /* Product: '<S175>/Product' incorporates:
         *  Product: '<S175>/Divide'
         *  UnaryMinus: '<S175>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Init_o / rtb_Sin4) * rtb_Add_h5;
        rtb_Minus_n[1] = ((-rtb_Switch2_nf) / rtb_Sin4) * rtb_Add_h5;

        /* Sum: '<S175>/Add1' incorporates:
         *  Sum: '<S175>/Add2'
         *  Sum: '<S175>/Minus'
         */
        rtb_Switch2_nf = rtb_Switch2_p2 - rtb_Minus_n[0];

        /* Sum: '<S175>/Minus4' incorporates:
         *  Sum: '<S175>/Add2'
         *  Sum: '<S175>/Minus'
         */
        rtb_Switch2_p2 = (rtb_Switch2_p2 + rtb_Minus_n[0]) - rtb_Switch2_nf;

        /* Sum: '<S175>/Minus5' incorporates:
         *  Concatenate: '<S157>/Matrix Concatenate2'
         *  Sum: '<S175>/Minus'
         */
        rtb_Switch2 = rtb_Reshapey[0] - rtb_Switch2_nf;

        /* Sum: '<S175>/Add' incorporates:
         *  Sum: '<S175>/Add2'
         *  Sum: '<S175>/Minus1'
         */
        rtb_Init_o = rtb_Init - rtb_Minus_n[0];

        /* Sum: '<S175>/Minus' incorporates:
         *  Sum: '<S175>/Minus1'
         */
        rtb_Switch2_nf -= rtb_Init_o;

        /* DotProduct: '<S175>/Dot Product' incorporates:
         *  Concatenate: '<S157>/Matrix Concatenate2'
         *  Sum: '<S175>/Minus'
         *  Sum: '<S175>/Minus1'
         *  Sum: '<S175>/Minus5'
         */
        rtb_Sin4 = (rtb_Reshapey[0] - rtb_Init_o) * rtb_Switch2_nf;

        /* DotProduct: '<S175>/Dot Product1' incorporates:
         *  Sum: '<S175>/Minus'
         */
        rtb_Init = rtb_Switch2_nf * rtb_Switch2_nf;

        /* DotProduct: '<S175>/Dot Product2' incorporates:
         *  Sum: '<S175>/Minus4'
         *  Sum: '<S175>/Minus5'
         */
        rtb_Minus_k_idx_1 = rtb_Switch2_p2 * rtb_Switch2;

        /* DotProduct: '<S175>/Dot Product3' incorporates:
         *  Sum: '<S175>/Minus4'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p2 * rtb_Switch2_p2;

        /* Sum: '<S175>/Add1' incorporates:
         *  Sum: '<S175>/Add2'
         *  Sum: '<S175>/Minus'
         */
        rtb_Switch2_nf = rtb_Switch1 - rtb_Minus_n[1];

        /* Sum: '<S175>/Minus4' incorporates:
         *  Sum: '<S175>/Add2'
         *  Sum: '<S175>/Minus'
         */
        rtb_Switch2_p2 = (rtb_Switch1 + rtb_Minus_n[1]) - rtb_Switch2_nf;

        /* Sum: '<S175>/Minus5' incorporates:
         *  Concatenate: '<S157>/Matrix Concatenate2'
         *  Sum: '<S175>/Minus'
         */
        rtb_Switch2 = rtb_Reshapey[1] - rtb_Switch2_nf;

        /* Sum: '<S175>/Add' incorporates:
         *  Sum: '<S175>/Add2'
         *  Sum: '<S175>/Minus1'
         */
        rtb_Init_o = rtb_DeadZone - rtb_Minus_n[1];

        /* Sum: '<S175>/Minus' incorporates:
         *  Sum: '<S175>/Minus1'
         */
        rtb_Switch2_nf -= rtb_Init_o;

        /* DotProduct: '<S175>/Dot Product' incorporates:
         *  Concatenate: '<S157>/Matrix Concatenate2'
         *  Sum: '<S175>/Minus'
         *  Sum: '<S175>/Minus1'
         *  Sum: '<S175>/Minus5'
         */
        rtb_Sin4 += (rtb_Reshapey[1] - rtb_Init_o) * rtb_Switch2_nf;

        /* RelationalOperator: '<S176>/Compare' incorporates:
         *  Constant: '<S176>/Constant'
         */
        rtb_AND1_c = (rtb_Sin4 >= 0.0);

        /* RelationalOperator: '<S175>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S175>/Dot Product1'
         *  Sum: '<S175>/Minus'
         */
        rtb_Is_Absolute_Translation_g = (rtb_Sin4 <= ((rtb_Switch2_nf *
          rtb_Switch2_nf) + rtb_Init));

        /* DotProduct: '<S175>/Dot Product2' incorporates:
         *  Sum: '<S175>/Minus4'
         *  Sum: '<S175>/Minus5'
         */
        rtb_Sin4 = (rtb_Switch2_p2 * rtb_Switch2) + rtb_Minus_k_idx_1;

        /* Merge: '<S161>/Merge4' incorporates:
         *  Constant: '<S177>/Constant'
         *  DataTypeConversion: '<S167>/Data Type Conversion'
         *  DotProduct: '<S175>/Dot Product3'
         *  Logic: '<S175>/AND'
         *  RelationalOperator: '<S175>/LessThanOrEqual1'
         *  RelationalOperator: '<S177>/Compare'
         *  Sum: '<S167>/Add'
         *  Sum: '<S175>/Minus4'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)(((rtb_AND1_c &&
          rtb_Is_Absolute_Translation_g) && (rtb_Sin4 >= 0.0)) && (rtb_Sin4 <=
          ((rtb_Switch2_p2 * rtb_Switch2_p2) + rtb_MatrixConcatenate_b_idx_0))))
          + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S161>/Merge2' incorporates:
         *  Constant: '<S167>/Constant2'
         *  SignalConversion generated from: '<S167>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S167>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S167>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* End of Outputs for SubSystem: '<S164>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S164>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S165>/Action Port'
         */
        /* Merge: '<S161>/Merge2' incorporates:
         *  Constant: '<S165>/Constant2'
         *  SignalConversion generated from: '<S165>/Robot_Reached_Destination'
         */
        rtb_AND1_c = false;

        /* SignalConversion generated from: '<S165>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S165>/Constant1'
         */
        rtb_Is_Absolute_Translation_g = false;

        /* Merge: '<S161>/Merge4' incorporates:
         *  SignalConversion generated from: '<S165>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S164>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S161>/Merge1' incorporates:
       *  Constant: '<S164>/Constant'
       *  SignalConversion generated from: '<S164>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S164>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_Compare_a;

      /* End of Outputs for SubSystem: '<S161>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S161>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S163>/Action Port'
       */
      /* Merge: '<S161>/Merge1' incorporates:
       *  Constant: '<S163>/Constant'
       *  SignalConversion generated from: '<S163>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S161>/Merge2' incorporates:
       *  Constant: '<S163>/Constant1'
       *  SignalConversion generated from: '<S163>/Robot_Reached_Destination'
       */
      rtb_AND1_c = false;

      /* SignalConversion generated from: '<S163>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S163>/Constant2'
       */
      rtb_Is_Absolute_Translation_g = false;

      /* Merge: '<S161>/Merge4' incorporates:
       *  SignalConversion generated from: '<S163>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S161>/Escape_Auto_Driving' */
    }

    /* End of If: '<S161>/If' */

    /* If: '<S157>/If1' */
    if (!rtb_Is_Absolute_Translation_g) {
      /* Outputs for IfAction SubSystem: '<S157>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S162>/Action Port'
       */
      /* Bias: '<S178>/Add Constant' incorporates:
       *  Bias: '<S178>/Bias'
       *  Sum: '<S178>/Subtract'
       */
      rtb_Init_o = ((9.0 - Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S178>/Selector4' incorporates:
       *  Constant: '<S180>/FixPt Constant'
       *  Sum: '<S180>/FixPt Sum1'
       */
      rtb_Minus_n[0] = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* Selector: '<S178>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = 9;
      Robot_Control_DW.Selector5_DIMS1[1] = 2;

      /* Concatenate: '<S178>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] = 11;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S178>/Selector5' incorporates:
       *  Concatenate: '<S178>/Matrix Concatenate'
       *  Gain: '<S182>/Gain'
       *  Selector: '<S157>/Selector1'
       *  Selector: '<S178>/Selector2'
       *  Selector: '<S178>/Selector3'
       *  Sum: '<S182>/Subtract'
       */
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (s183_iter = 0; s183_iter < 9; s183_iter++) {
          rtb_Selector5[s183_iter + (Robot_Control_DW.Selector5_DIMS1[0] *
            rtb_Num_Segments)] = rtb_Ref_Poses[s183_iter + i];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
          rtb_Num_Segments] = (rtb_Ref_Poses[i] * 2.0) - rtb_Ref_Poses[i + 1];
        i += 10;
      }

      /* Concatenate: '<S178>/Matrix Concatenate' incorporates:
       *  Gain: '<S181>/Gain'
       *  Selector: '<S157>/Selector1'
       *  Selector: '<S178>/Selector'
       *  Selector: '<S178>/Selector1'
       *  Selector: '<S178>/Selector5'
       *  Sum: '<S181>/Subtract'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments < 9; rtb_Num_Segments++) {
          rtb_MatrixConcatenate_p[(rtb_Num_Segments +
            (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) + 1] =
            rtb_Selector5[(Robot_Control_DW.Selector5_DIMS1[0] * i) +
            rtb_Num_Segments];
        }
      }

      rtb_MatrixConcatenate_p[10] = (2.0 * rtb_Ref_Poses[8]) - rtb_Ref_Poses[7];
      rtb_MatrixConcatenate_p[10 + Robot_Control_DW.MatrixConcatenate_DIMS1[0]] =
        (2.0 * rtb_Ref_Poses[18]) - rtb_Ref_Poses[17];

      /* Selector: '<S178>/Selector4' */
      Robot_Control_DW.Selector4_DIMS1[0] = 12 - ((int32_T)rtb_Minus_n[0]);
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S178>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S178>/Selector4' */
      s183_iter = (int32_T)rtb_Minus_n[0];
      rtb_Bias1_p = 11 - ((int32_T)rtb_Minus_n[0]);

      /* Assignment: '<S178>/Assignment' incorporates:
       *  Concatenate: '<S178>/Matrix Concatenate'
       *  Selector: '<S178>/Selector4'
       */
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= rtb_Bias1_p;
             rtb_Num_Segments++) {
          rtb_Assignment[rtb_Num_Segments + (12 * i)] = rtb_MatrixConcatenate_p
            [((rtb_Num_Segments + s183_iter) +
              (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S179>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S183>/While Iterator'
       */
      s183_iter = 1;
      do {
        rtb_Init = rtb_Assignment[s183_iter + 1];
        rtb_Minus_n[0] = rtb_Init - rtb_Assignment[s183_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s183_iter] - rtb_Assignment[s183_iter + 2];
        rtb_Switch2_p2 = rtb_Init - rtb_Assignment[s183_iter];
        rtb_Init = rtb_Assignment[s183_iter + 13];
        rtb_Minus_n[1] = rtb_Init - rtb_Assignment[s183_iter + 11];
        rtb_Switch2_nf = rtb_Assignment[s183_iter + 12];
        rtb_Add2[1] = rtb_Switch2_nf - rtb_Assignment[s183_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Init - rtb_Switch2_nf;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Sin4 = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_DeadZone = rt_powd_snf(rtb_Sin4, 2.0);
          rtb_Init = rt_powd_snf(rtb_Sin4, 3.0);
          rtb_Switch1 = (rtb_Sin4 - (2.0 * rtb_DeadZone)) + rtb_Init;
          rtb_Switch2 = rtb_DeadZone - rtb_Init;
          rtb_Init = (3.0 * rtb_DeadZone) - (2.0 * rtb_Init);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Minus_n[0] * rtb_Switch1) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Switch2_p2 * rtb_Init)) +
            rtb_Assignment[s183_iter];
          rtb_Init = ((((rtb_Minus_n[1] * rtb_Switch1) + (rtb_Add2[1] *
            rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Init)) +
            rtb_Switch2_nf;
          rtb_Switch1 = ((3.0 * rtb_DeadZone) - (4.0 * rtb_Sin4)) + 1.0;
          rtb_Switch2 = (2.0 * rtb_Sin4) - (3.0 * rtb_DeadZone);
          rtb_DeadZone = (rtb_Sin4 - rtb_DeadZone) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_Minus_n[0] * rtb_Switch1) +
            (rtb_Add2[0] * rtb_Switch2)) * 0.5) + (rtb_Switch2_p2 * rtb_DeadZone);
          rtb_Switch2_ow = (((rtb_Minus_n[1] * rtb_Switch1) + (rtb_Add2[1] *
            rtb_Switch2)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_DeadZone);
          rtb_DeadZone = (6.0 * rtb_Sin4) - 4.0;
          rtb_Switch1 = (-6.0 * rtb_Sin4) + 2.0;
          rtb_Sin4 = (-12.0 * rtb_Sin4) + 6.0;
          rtb_Switch2 = (((rtb_Minus_n[0] * rtb_DeadZone) + (rtb_Add2[0] *
            rtb_Switch1)) * 0.5) + (rtb_Switch2_p2 * rtb_Sin4);
          rtb_Switch1 = (((rtb_Minus_n[1] * rtb_DeadZone) + (rtb_Add2[1] *
            rtb_Switch1)) * 0.5) + (rtb_Minus_k_idx_1 * rtb_Sin4);
          rtb_DeadZone = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Switch2_ow), 3.0);
          rtb_Sin4 = fmax(1.0E-10, rtb_DeadZone);
          Robot_Control_DW.Relay_Mode = ((rtb_DeadZone >= 2.2204460492503131E-16)
            || (Robot_Control_DW.Relay_Mode));
          if (Robot_Control_DW.Relay_Mode) {
            rtb_DeadZone = 1.0;
          } else {
            rtb_DeadZone = -1.0;
          }

          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Init;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch1) - (rtb_Switch2 *
              rtb_Switch2_ow)) / (rtb_Sin4 * rtb_DeadZone);
        }

        if (s183_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Robot_Control_B.Assignment[((i * 50) + (s183_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Sin4 = rtb_Init_o - ((real_T)s183_iter);
        rtb_Num_Segments = s183_iter;
        s183_iter++;
      } while ((rtb_Sin4 >= 4.0) && (s183_iter <= 3));

      /* End of Outputs for SubSystem: '<S179>/Sampling_Loop' */

      /* SignalConversion generated from: '<S162>/Position_and_Curvature' incorporates:
       *  Assignment: '<S183>/Assignment'
       *  Merge: '<S157>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Robot_Control_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S157>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S157>/If Action Subsystem' incorporates:
       *  ActionPort: '<S160>/Action Port'
       */
      /* Product: '<S160>/Product' incorporates:
       *  Selector: '<S157>/Selector'
       *  Selector: '<S157>/Selector1'
       */
      rtb_Sin4 = rtb_Ref_Poses[8];

      /* Product: '<S160>/Product1' incorporates:
       *  Selector: '<S157>/Selector'
       *  Selector: '<S157>/Selector1'
       */
      rtb_Init_o = rtb_Ref_Poses[18];
      for (i = 0; i < 50; i++) {
        /* Product: '<S160>/Product' incorporates:
         *  Constant: '<S160>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Sin4;

        /* Product: '<S160>/Product1' incorporates:
         *  Constant: '<S160>/Constant2'
         *  Product: '<S160>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Init_o;
      }

      /* Assignment: '<S160>/Assignment' incorporates:
       *  Concatenate: '<S160>/Matrix Concatenate'
       *  Merge: '<S157>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S160>/Assignment' */

      /* SignalConversion generated from: '<S160>/Num_Segments' incorporates:
       *  Constant: '<S160>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S157>/If Action Subsystem' */
    }

    /* End of If: '<S157>/If1' */

    /* Concatenate: '<S158>/Matrix Concatenate' incorporates:
     *  Merge: '<S157>/Merge'
     *  Selector: '<S158>/Selector'
     *  Selector: '<S158>/Selector1'
     *  Selector: '<S158>/Selector3'
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

    /* End of Concatenate: '<S158>/Matrix Concatenate' */

    /* MATLAB Function: '<S158>/Distance Along Curve' incorporates:
     *  Concatenate: '<S158>/Matrix Concatenate'
     *  Selector: '<S158>/Selector4'
     *  Selector: '<S158>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s183_iter = 0; s183_iter < 149; s183_iter++) {
      /* Outputs for Iterator SubSystem: '<S179>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S183>/While Iterator'
       */
      rtb_Assignment_d[s183_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s183_iter + 1] -
         rtb_MatrixConcatenate_o[s183_iter], rtb_MatrixConcatenate_o[s183_iter +
         151] - rtb_MatrixConcatenate_o[s183_iter + 150]) +
        rtb_Assignment_d[s183_iter];

      /* End of Outputs for SubSystem: '<S179>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S158>/Distance Along Curve' */

    /* MATLAB Function: '<S158>/Find closest index to curve' incorporates:
     *  Concatenate: '<S158>/Matrix Concatenate'
     *  Selector: '<S158>/Selector4'
     *  Selector: '<S158>/Selector5'
     *  Selector: '<S209>/Selector'
     */
    for (s183_iter = 0; s183_iter < 150; s183_iter++) {
      /* Outputs for Iterator SubSystem: '<S179>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S183>/While Iterator'
       */
      distance_from_robot[s183_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s183_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s183_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S179>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s183_iter = 1;
    } else {
      s183_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s183_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s183_iter == 0) {
      rtb_Init_o = distance_from_robot[0];
    } else {
      rtb_Init_o = distance_from_robot[s183_iter - 1];
      for (rtb_Bias1_p = s183_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Sin4 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Init_o > rtb_Sin4) {
          rtb_Init_o = rtb_Sin4;
        }
      }
    }

    s183_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s183_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Init_o) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S209>/Selector' incorporates:
     *  Constant: '<S209>/Constant'
     *  MATLAB Function: '<S158>/Find closest index to curve'
     *  MinMax: '<S209>/Min'
     */
    rtb_Sin4 = rtb_Assignment_d[((int32_T)fmin(50.0, s183_iter)) - 1];

    /* If: '<S209>/If' incorporates:
     *  RelationalOperator: '<S209>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S209>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S212>/Action Port'
       */
      /* SignalConversion generated from: '<S212>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S214>/FixPt Sum1' incorporates:
       *  Constant: '<S214>/FixPt Constant'
       */
      rtb_Init_o = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S212>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S212>/Selector11'
       *  Selector: '<S212>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses_0[((int32_T)rtb_Init_o) + 19];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses_0[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S212>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S9>/Merge8'
       *  Selector: '<S212>/Selector1'
       *  Selector: '<S212>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_0[((int32_T)rtb_Init_o) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_0[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S212>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S212>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Init_o), &rtb_Minus_n[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S212>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S212>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S212>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Sin4,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S209>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S209>/Latch' incorporates:
       *  ActionPort: '<S213>/Action Port'
       */
      /* SignalConversion generated from: '<S213>/In1' incorporates:
       *  UnitDelay: '<S209>/Unit Delay1'
       */
      rtb_Init_o = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S213>/In2' incorporates:
       *  UnitDelay: '<S209>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S209>/Latch' */
    }

    /* End of If: '<S209>/If' */

    /* MinMax: '<S156>/Min' incorporates:
     *  Lookup_n-D: '<S156>/Lookahead Distance'
     *  UnitDelay: '<S156>/Unit Delay'
     */
    rtb_Add_h5 = fmin(rtb_Add_h5, look1_binlcpw
                      (Robot_Control_DW.UnitDelay_DSTATE_hn,
                       rtCP_LookaheadDistance_bp01Data,
                       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S158>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S208>/While Iterator'
     */
    s208_iter = 1U;
    rtb_Compare_a = true;
    while (rtb_Compare_a && (s208_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S158>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S208>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s208_iter;
      rtb_Compare_a = ((rtb_Assignment_d[Robot_Control_B.WhileIterator - 1] <=
                        (rtb_Assignment_d[s183_iter - 1] + rtb_Add_h5)) &&
                       (Robot_Control_B.WhileIterator < (((real_T)
        rtb_Num_Segments) * 50.0)));
      s208_iter++;
    }

    /* End of Outputs for SubSystem: '<S158>/Find first index that meets distance target' */

    /* Switch: '<S211>/Switch' incorporates:
     *  Concatenate: '<S158>/Matrix Concatenate'
     *  Constant: '<S158>/Constant'
     *  Constant: '<S208>/Constant'
     *  Constant: '<S211>/Constant'
     *  Constant: '<S211>/Constant1'
     *  Constant: '<S211>/Constant2'
     *  Constant: '<S211>/Constant3'
     *  Logic: '<S208>/AND'
     *  MATLAB Function: '<S158>/Find closest index to curve'
     *  Math: '<S211>/Hypot'
     *  Merge: '<S9>/Merge8'
     *  MinMax: '<S211>/Max'
     *  MinMax: '<S211>/Min'
     *  MinMax: '<S211>/Min1'
     *  Product: '<S208>/Product'
     *  Product: '<S211>/Divide'
     *  Product: '<S211>/Product'
     *  Product: '<S211>/Product1'
     *  RelationalOperator: '<S158>/Relational Operator'
     *  RelationalOperator: '<S208>/Relational Operator'
     *  RelationalOperator: '<S208>/Relational Operator1'
     *  Selector: '<S158>/Selector10'
     *  Selector: '<S158>/Selector7'
     *  Selector: '<S158>/Selector8'
     *  Selector: '<S158>/Selector9'
     *  Selector: '<S208>/Selector'
     *  Selector: '<S208>/Selector1'
     *  Selector: '<S209>/Selector'
     *  Sqrt: '<S211>/Sqrt'
     *  Sum: '<S158>/Subtract'
     *  Sum: '<S208>/Add'
     *  Sum: '<S211>/Subtract'
     *  Sum: '<S211>/Subtract1'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (9.0 -
         Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Add_h5 = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_0[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_0[19] -
        Robot_Control_B.KF_Position_Y) *
                        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin
                        (rtb_Init_o * Spline_Velocity_Multiplier_TEST, sqrt
                         (Spline_Max_Centripital_Acceleration / fmax
                          (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator
                           + 299], 1.0E-5))));
    } else {
      rtb_Add_h5 = fmin(rtb_Init_o * Spline_Velocity_Multiplier_TEST, sqrt
                        (Spline_Max_Centripital_Acceleration / fmax
                         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator
                          + 299], 1.0E-5)));
    }

    /* End of Switch: '<S211>/Switch' */

    /* Logic: '<S159>/OR' */
    rtb_Is_Absolute_Translation_g = (rtb_AND1_c ||
      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S159>/Switch1' incorporates:
     *  Switch: '<S159>/Switch'
     *  UnitDelay: '<S159>/Unit Delay'
     */
    if (rtb_Is_Absolute_Translation_g) {
      /* Merge: '<S13>/Merge2' incorporates:
       *  Constant: '<S159>/Constant3'
       *  SignalConversion: '<S159>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Sin4 = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S13>/Merge2' incorporates:
       *  SignalConversion: '<S159>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Add_h5;
      rtb_Sin4 = rtb_Merge1;
    }

    /* End of Switch: '<S159>/Switch1' */

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion: '<S159>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Sin4;

    /* Selector: '<S158>/Selector6' incorporates:
     *  Concatenate: '<S158>/Matrix Concatenate'
     *  Selector: '<S158>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S158>/Selector2' incorporates:
     *  Concatenate: '<S158>/Matrix Concatenate'
     *  Selector: '<S158>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S159>/Switch2' incorporates:
     *  Sum: '<S215>/Subtract'
     *  Sum: '<S215>/Subtract1'
     *  Trigonometry: '<S215>/Atan2'
     *  UnitDelay: '<S159>/Unit Delay1'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_DeadZone = Robot_Control_DW.UnitDelay1_DSTATE_k;
    } else {
      rtb_DeadZone = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S159>/Switch2' */

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion: '<S159>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_DeadZone;

    /* Merge: '<S13>/Merge7' incorporates:
     *  SignalConversion: '<S156>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_AND1_c;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Constant: '<S159>/Constant2'
     *  SignalConversion generated from: '<S156>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S13>/Merge4' incorporates:
     *  Constant: '<S159>/Constant5'
     *  SignalConversion generated from: '<S156>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S13>/Merge5' incorporates:
     *  Constant: '<S159>/Constant6'
     *  SignalConversion generated from: '<S156>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S156>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S157>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S156>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_hn = rtb_Add_h5;

    /* Update for UnitDelay: '<S209>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Init_o;

    /* Update for UnitDelay: '<S209>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S159>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Sin4;

    /* Update for UnitDelay: '<S159>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_k = rtb_DeadZone;

    /* End of Outputs for SubSystem: '<S13>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* Merge: '<S13>/Merge7' incorporates:
     *  Constant: '<S155>/Constant'
     *  SignalConversion generated from: '<S155>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S155>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S155>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S13>/Merge2' incorporates:
     *  SignalConversion generated from: '<S155>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S13>/Merge3' incorporates:
     *  SignalConversion generated from: '<S155>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S13>/Merge4' incorporates:
     *  SignalConversion generated from: '<S155>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;

    /* Merge: '<S13>/Merge5' incorporates:
     *  SignalConversion generated from: '<S155>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S13>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S155>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S13>/Pass Through' */
  }

  /* End of If: '<S13>/If' */

  /* Signum: '<S305>/Sign2' incorporates:
   *  UnitDelay: '<S305>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S305>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S305>/Product1' incorporates:
   *  Signum: '<S305>/Sign1'
   *  Signum: '<S305>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S305>/Switch' incorporates:
   *  Constant: '<S305>/Constant'
   *  Constant: '<S310>/Constant'
   *  Constant: '<S311>/Constant'
   *  Logic: '<S305>/or'
   *  Product: '<S305>/Product1'
   *  RelationalOperator: '<S310>/Compare'
   *  RelationalOperator: '<S311>/Compare'
   *  UnitDelay: '<S305>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S305>/Switch' */

  /* Switch: '<S316>/Init' incorporates:
   *  UnitDelay: '<S316>/FixPt Unit Delay1'
   *  UnitDelay: '<S316>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S316>/Init' */

  /* RelationalOperator: '<S312>/Compare' incorporates:
   *  Constant: '<S312>/Constant'
   */
  rtb_Compare_a = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S313>/Compare' incorporates:
   *  Constant: '<S313>/Constant'
   */
  rtb_AND1_c = (rtb_Sin4 > 0.0);

  /* Abs: '<S305>/Abs' incorporates:
   *  Sum: '<S305>/Subtract'
   *  UnitDelay: '<S305>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S305>/Switch5' incorporates:
   *  Constant: '<S305>/Constant1'
   *  Switch: '<S305>/Switch1'
   *  UnaryMinus: '<S305>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S305>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S305>/Constant4'
     *  Constant: '<S305>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S305>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S305>/Constant2'
     *  Constant: '<S305>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S305>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S305>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S305>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S305>/Constant10'
     *  Constant: '<S305>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S305>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S305>/Constant7'
     *  Constant: '<S305>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S305>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S305>/Lookup Table Dynamic1'
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

    /* Switch: '<S305>/Switch3' incorporates:
     *  Constant: '<S305>/Constant1'
     *  Constant: '<S305>/Constant3'
     *  UnaryMinus: '<S305>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_oy = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_oy = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S305>/Switch3' */
  }

  /* End of Switch: '<S305>/Switch5' */

  /* Product: '<S305>/Product' incorporates:
   *  Switch: '<S305>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_oy * rtb_Merge1;

  /* Sum: '<S314>/Sum1' */
  rtb_Add_h5 = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S315>/Switch2' incorporates:
   *  RelationalOperator: '<S315>/LowerRelop1'
   */
  if (!(rtb_Add_h5 > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S305>/Switch2' incorporates:
     *  Constant: '<S305>/Constant1'
     *  Switch: '<S305>/Switch4'
     */
    if (rtb_Compare_a) {
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S305>/Switch4' incorporates:
       *  Constant: '<S305>/Constant1'
       */
      rtb_Sin4 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S305>/Switch4' incorporates:
       *  Constant: '<S305>/Constant3'
       *  UnaryMinus: '<S305>/Unary Minus1'
       */
      rtb_Sin4 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S305>/Switch2' */

    /* Product: '<S305>/Product2' */
    rtb_Sin4 *= rtb_Merge1;

    /* Switch: '<S315>/Switch' incorporates:
     *  RelationalOperator: '<S315>/UpperRelop'
     */
    if (rtb_Add_h5 < rtb_Sin4) {
      rtb_Optimized_Module_Angle = rtb_Sin4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Add_h5;
    }

    /* End of Switch: '<S315>/Switch' */
  }

  /* End of Switch: '<S315>/Switch2' */

  /* Sum: '<S314>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S308>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S308>/Switch' incorporates:
     *  Constant: '<S340>/Constant3'
     *  Constant: '<S340>/Constant4'
     *  Math: '<S340>/Math Function'
     *  Sum: '<S308>/Subtract'
     *  Sum: '<S340>/Add1'
     *  Sum: '<S340>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S308>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S308>/Switch' */

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

  /* Sum: '<S106>/Subtract' incorporates:
   *  Constant: '<S106>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Merge1 = 140.0 - Robot_Control_U.MatchTime;

  /* If: '<S106>/If' incorporates:
   *  DataTypeConversion: '<S106>/Data Type Conversion'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   */
  if ((rtb_GameState == 1) || (rtb_Merge1 <= 10.0)) {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem' incorporates:
     *  ActionPort: '<S132>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem' */
  } else if (rtb_Merge1 <= 35.0) {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S133>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem1' */
  } else if (rtb_Merge1 <= 60.0) {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S134>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem2' */
  } else if (rtb_Merge1 <= 85.0) {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S135>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem3' */
  } else if (rtb_Merge1 <= 110.0) {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S136>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S106>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S137>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S106>/If Action Subsystem5' */
  }

  /* End of If: '<S106>/If' */

  /* If: '<S139>/If' incorporates:
   *  If: '<S140>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S139>/Blue' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    /* Merge: '<S139>/Merge' incorporates:
     *  Constant: '<S141>/BlueAllianceZoneX'
     *  Logic: '<S141>/AND'
     *  RelationalOperator: '<S141>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S139>/Blue' */

    /* Outputs for IfAction SubSystem: '<S140>/Blue' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    /* Merge: '<S140>/Merge' incorporates:
     *  Constant: '<S143>/BlueAllianceZoneX'
     *  RelationalOperator: '<S143>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S140>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S139>/Red' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    /* Merge: '<S139>/Merge' incorporates:
     *  Constant: '<S142>/RedAllianceZoneX'
     *  Logic: '<S142>/AND'
     *  RelationalOperator: '<S142>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S139>/Red' */

    /* Outputs for IfAction SubSystem: '<S140>/Red' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    /* Merge: '<S140>/Merge' incorporates:
     *  Constant: '<S144>/RedAllianceZoneX'
     *  RelationalOperator: '<S144>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S140>/Red' */
  }

  /* End of If: '<S139>/If' */

  /* RelationalOperator: '<S108>/GreaterThan' incorporates:
   *  Constant: '<S108>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S108>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S108>/Relational Operator' incorporates:
   *  Abs: '<S108>/Abs'
   *  Constant: '<S138>/Constant3'
   *  Constant: '<S138>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S138>/Math Function'
   *  Sum: '<S108>/Subtract'
   *  Sum: '<S138>/Add1'
   *  Sum: '<S138>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S107>/Max' incorporates:
   *  Abs: '<S107>/Abs1'
   *  Abs: '<S107>/Abs2'
   *  Abs: '<S107>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S108>/Relational Operator1' incorporates:
   *  Abs: '<S108>/Abs1'
   *  Constant: '<S108>/Constant2'
   *  Sum: '<S108>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S108>/Relational Operator4' incorporates:
   *  Abs: '<S108>/Abs4'
   *  Constant: '<S108>/Constant1'
   *  Sum: '<S108>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S108>/AND' */
  rtb_Compare_a = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
                    (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                   (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S108>/AND2' incorporates:
   *  Logic: '<S108>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_a);

  /* SignalConversion: '<S108>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S108>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_Compare_a);

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
    if ((rtb_Button_Spinup_Enable != 0) || (rtb_Button_Shoot_Enable != 0)) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.RB_Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
      guard2 = true;
    } else {
      guard1 = true;
    }
  } else {
    /* case IN_Shooting: */
    Robot_Control_B.RB_Shooter_Active = true;
    if ((rtb_Button_Spinup_Enable == 0) && (rtb_Button_Shoot_Enable == 0)) {
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
        if (rtb_Button_Shoot_Enable == 0) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        }
        break;

       case Robot_Control_IN_Spinning_Up:
        Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        if ((rtb_Button_Shoot_Enable != 0) &&
            ((Robot_Control_B.RB_Ready_to_Score) ||
             (Robot_Control_B.RB_Ready_to_Pass))) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Transfer;
          Robot_Control_B.RB_Desired_Feeder_Speed =
            Rebuilt_Negative_Feeder_Speed;
          Robot_Control_B.RB_Desired_Transfer_Speed =
            Rebuilt_Target_Transfer_Speed;
          Robot_Control_B.RB_Transfer_Init = 1.0;
        }
        break;

       default:
        /* case IN_Transfer: */
        Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Negative_Feeder_Speed;
        Robot_Control_B.RB_Transfer_Init = 1.0;
        if (Robot_Control_U.Measured_Transfer_Speed >
            (Robot_Control_B.RB_Desired_Transfer_Speed *
             Rebuilt_Transfer_Minimum_Factor)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Feeder;
          Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
          Robot_Control_B.RB_Transfer_Init = 0.0;
        } else if (rtb_Button_Shoot_Enable == 0) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.RB_Desired_Transfer_Speed = 0.0;
          Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
        }
        break;
      }

      guard2 = true;
    }
  }

  if (guard2) {
    /* Outputs for IfAction SubSystem: '<S105>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S114>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S116>/While Iterator'
     */
    /* If: '<S105>/If' incorporates:
     *  Constant: '<S114>/Constant'
     *  Constant: '<S115>/Constant'
     *  Constant: '<S117>/Constant1'
     *  Constant: '<S117>/Constant10'
     *  Constant: '<S117>/Constant2'
     *  Constant: '<S117>/Constant5'
     *  Constant: '<S117>/Constant6'
     *  Constant: '<S117>/Constant7'
     *  Constant: '<S117>/Constant8'
     *  Constant: '<S117>/Constant9'
     *  Constant: '<S118>/Constant1'
     *  Constant: '<S118>/Constant10'
     *  Constant: '<S118>/Constant2'
     *  Constant: '<S118>/Constant5'
     *  Constant: '<S118>/Constant6'
     *  Constant: '<S118>/Constant7'
     *  Constant: '<S118>/Constant8'
     *  Constant: '<S118>/Constant9'
     *  Constant: '<S119>/Constant'
     *  Constant: '<S119>/Constant1'
     *  Constant: '<S119>/Constant2'
     *  Constant: '<S121>/Constant1'
     *  Constant: '<S121>/Constant10'
     *  Constant: '<S121>/Constant2'
     *  Constant: '<S121>/Constant5'
     *  Constant: '<S121>/Constant6'
     *  Constant: '<S121>/Constant7'
     *  Constant: '<S121>/Constant8'
     *  Constant: '<S121>/Constant9'
     *  Constant: '<S124>/Constant'
     *  Constant: '<S124>/Constant1'
     *  Constant: '<S124>/Constant11'
     *  Constant: '<S124>/Constant2'
     *  Constant: '<S124>/Constant3'
     *  Constant: '<S124>/Constant4'
     *  Constant: '<S124>/Constant5'
     *  Constant: '<S124>/Constant6'
     *  Constant: '<S130>/Constant1'
     *  Constant: '<S130>/Constant10'
     *  Constant: '<S130>/Constant2'
     *  Constant: '<S130>/Constant5'
     *  Constant: '<S130>/Constant6'
     *  Constant: '<S130>/Constant7'
     *  Constant: '<S130>/Constant8'
     *  Constant: '<S130>/Constant9'
     *  Constant: '<S131>/Constant1'
     *  Constant: '<S131>/Constant10'
     *  Constant: '<S131>/Constant2'
     *  Constant: '<S131>/Constant5'
     *  Constant: '<S131>/Constant6'
     *  Constant: '<S131>/Constant7'
     *  Constant: '<S131>/Constant8'
     *  Constant: '<S131>/Constant9'
     *  Gain: '<S122>/Gain1'
     *  Gain: '<S129>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S116>/Memory'
     *  Memory: '<S116>/Memory1'
     *  Memory: '<S116>/Memory2'
     *  Memory: '<S116>/Memory3'
     *  Merge: '<S105>/Merge'
     *  Merge: '<S105>/Merge2'
     *  Merge: '<S105>/Merge3'
     *  RelationalOperator: '<S119>/GreaterThan'
     *  S-Function (sfix_look1_dyn): '<S117>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S118>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S119>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S119>/Lookup Table Dynamic1'
     *  SignalConversion generated from: '<S117>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S124>/Lookup Table Dynamic'
     *  Sum: '<S115>/Add'
     *  Sum: '<S115>/Subtract'
     *  Sum: '<S115>/Subtract1'
     *  Sum: '<S119>/Add'
     *  Switch: '<S119>/Switch'
     *  Switch: '<S119>/Switch1'
     *  Switch: '<S120>/Switch4'
     *  Switch: '<S120>/Switch5'
     *  Switch: '<S120>/Switch6'
     *  Trigonometry: '<S115>/Tanh'
     *  UnitDelay: '<S119>/Unit Delay'
     * */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S114>/Iterate_Shot_Target' */
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
      /* Switch: '<S120>/Switch2' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S120>/Switch4' incorporates:
         *  Constant: '<S120>/Blue_Top'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Pass_X;
      } else {
        /* Switch: '<S120>/Switch4' incorporates:
         *  Constant: '<S120>/Blue_Top1'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Pass_X;
      }

      /* End of Switch: '<S120>/Switch2' */

      /* Switch: '<S120>/Switch3' */
      if (Robot_Control_B.KF_Position_Y > Field_Hub_Y) {
        /* Switch: '<S120>/Switch6' incorporates:
         *  Constant: '<S120>/Blue_Top3'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Top;
      } else {
        /* Switch: '<S120>/Switch6' incorporates:
         *  Constant: '<S120>/Blue_Top2'
         */
        Robot_Control_B.RB_Shoot_Target_Y = Field_Pass_Y_Bottom;
      }

      /* End of Switch: '<S120>/Switch3' */
    } else {
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Switch: '<S120>/Switch5' incorporates:
         *  Constant: '<S120>/Constant8'
         *  Switch: '<S120>/Switch4'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;
      } else {
        /* Switch: '<S120>/Switch4' incorporates:
         *  Constant: '<S120>/Constant9'
         *  Switch: '<S120>/Switch5'
         */
        Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;
      }

      /* Switch: '<S120>/Switch6' incorporates:
       *  Constant: '<S120>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S114>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S116>/While Iterator'
     */
    rtb_Button_Spinup_Enable = 1U;
    rtb_Merge1 = 0.0;
    rtb_Add_h5 = 0.0;
    rtb_Init_o = 0.0;
    rtb_AND1_c = true;
    rtb_Compare_a = true;
    rtb_TOF_g[0] = Rebuilt_Shoot_TOF_0;
    rtb_TOF_g[1] = Rebuilt_Shoot_TOF_1;
    rtb_TOF_g[2] = Rebuilt_Shoot_TOF_2;
    rtb_TOF_g[3] = Rebuilt_Shoot_TOF_3;
    rtb_TOF_g[4] = Rebuilt_Shoot_TOF_4;
    rtb_TOF_g[5] = Rebuilt_Shoot_TOF_5;
    rtb_TOF_g[6] = Rebuilt_Shoot_TOF_6;
    rtb_TOF_g[7] = Rebuilt_Shoot_TOF_7;
    rtb_TmpSignalConversionAtLoo__0 = &rtb_TmpSignalConversionAtLook_o[0];
    while (rtb_Compare_a && (rtb_Button_Spinup_Enable <= 10)) {
      /* Switch: '<S125>/Switch' incorporates:
       *  Memory: '<S116>/Memory1'
       *  Memory: '<S116>/Memory2'
       *  Switch: '<S125>/Switch1'
       */
      if (rtb_Button_Spinup_Enable > 1) {
        rtb_Sin4 = rtb_Merge1;
        rtb_DeadZone = rtb_Add_h5;
      } else {
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_X;
        rtb_DeadZone = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S125>/Switch' */

      /* Math: '<S123>/Hypot' incorporates:
       *  Sum: '<S123>/Subtract'
       *  Sum: '<S123>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_DeadZone -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S124>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S124>/Lookup Table Dynamic'
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

      /* Sum: '<S126>/Subtract' incorporates:
       *  Memory: '<S116>/Memory3'
       *  Sum: '<S126>/Subtract1'
       */
      rtb_Merge1 = rtb_TOF - rtb_Init_o;

      /* Sum: '<S126>/Add' incorporates:
       *  Gain: '<S126>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S126>/Product'
       *  Sum: '<S126>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S126>/Add1' incorporates:
       *  Gain: '<S126>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S126>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Merge1 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_DeadZone;

      /* Memory: '<S116>/Memory' */
      rtb_Compare_a = rtb_AND1_c;

      /* Update for Memory: '<S116>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S116>/Memory2' */
      rtb_Add_h5 = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S116>/Memory3' */
      rtb_Init_o = rtb_TOF;

      /* Update for Memory: '<S116>/Memory' incorporates:
       *  Constant: '<S128>/Constant'
       *  Math: '<S127>/Hypot'
       *  RelationalOperator: '<S128>/Compare'
       *  Sum: '<S127>/Subtract'
       *  Sum: '<S127>/Subtract1'
       */
      rtb_AND1_c = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X - rtb_Sin4,
        Robot_Control_B.RB_Desired_Target_Y - rtb_DeadZone) >=
                    Rebuilt_Shoot_Target_Error_Thresh);
      rtb_Button_Spinup_Enable++;
    }

    /* End of Outputs for SubSystem: '<S114>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S118>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S117>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S119>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S119>/Lookup Table Dynamic1'
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
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_b + 0.02;
    }

    if (rtb_Merge1 < Rebuilt_Shot_Init_Time) {
      /* Merge: '<S105>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_Init_Shoot_Motor_Spd;
    } else {
      /* Merge: '<S105>/Merge1' */
      Robot_Control_B.RB_Desired_Shooter_Speed =
        Robot_Control_B.RB_Des_SS_Shoot_Motor_Spd;
    }

    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      rtb_LookupTableDynamic_b;
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X) +
      (0.017453292519943295 * Rebuilt_Des_Gyro_Shoot_Offset);
    Robot_Control_DW.UnitDelay_DSTATE_b = rtb_Merge1;

    /* End of Outputs for SubSystem: '<S105>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_oy = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Minus_k_idx_1 = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S105>/Shooter Not Active' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    /* If: '<S105>/If' incorporates:
     *  Constant: '<S113>/Constant'
     *  Constant: '<S113>/Constant1'
     *  Constant: '<S113>/Constant2'
     *  Merge: '<S105>/Merge'
     *  Merge: '<S105>/Merge1'
     *  Merge: '<S105>/Merge2'
     *  Merge: '<S105>/Merge3'
     *  SignalConversion generated from: '<S113>/Desired_Gyro_Angle'
     *  UnitDelay: '<S105>/Unit Delay'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot =
      Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S105>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_oy = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Minus_k_idx_1 = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S336>/Add1' incorporates:
   *  Constant: '<S336>/Constant3'
   *  Constant: '<S336>/Constant4'
   *  Math: '<S336>/Math Function'
   *  Sum: '<S335>/Sum'
   *  Sum: '<S336>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_oy - rtb_Minus_k_idx_1) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S338>/Sum1' incorporates:
   *  Constant: '<S335>/Constant2'
   *  Product: '<S338>/Product'
   *  Sum: '<S338>/Sum'
   *  UnitDelay: '<S338>/Unit Delay1'
   */
  rtb_LookupTableDynamic_b = ((rtb_Optimized_Module_Angle_p -
    Robot_Control_DW.UnitDelay1_DSTATE) * Steering_Heading_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S335>/Product' incorporates:
   *  Constant: '<S335>/Constant3'
   */
  rtb_Merge1 = rtb_LookupTableDynamic_b * Steering_Heading_Control_D;

  /* Sum: '<S337>/Diff' incorporates:
   *  UnitDelay: '<S337>/UD'
   *
   * Block description for '<S337>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S337>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Merge1 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S335>/Saturation' */
  if (rtb_Add_oy > Steering_Heading_Control_D_UL) {
    rtb_Add_oy = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Heading_Control_D_LL) {
    rtb_Add_oy = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S335>/Add' incorporates:
   *  Gain: '<S335>/Gain1'
   *  Saturate: '<S335>/Saturation'
   */
  rtb_Init_o = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_oy;

  /* Sum: '<S335>/Subtract' incorporates:
   *  Constant: '<S335>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Init_o;

  /* Sum: '<S335>/Sum2' incorporates:
   *  Gain: '<S335>/Gain2'
   *  UnitDelay: '<S335>/Unit Delay'
   */
  rtb_Add_h5 = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S339>/Switch2' incorporates:
   *  RelationalOperator: '<S339>/LowerRelop1'
   */
  if (!(rtb_Add_h5 > rtb_Sin4)) {
    /* Sum: '<S335>/Subtract1' incorporates:
     *  Constant: '<S335>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Init_o;

    /* Switch: '<S339>/Switch' incorporates:
     *  RelationalOperator: '<S339>/UpperRelop'
     */
    if (!(rtb_Add_h5 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Add_h5;
    }

    /* End of Switch: '<S339>/Switch' */
  }

  /* End of Switch: '<S339>/Switch2' */

  /* Saturate: '<S335>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Add_h5 = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Add_h5 = Steering_Heading_Control_I_LL;
  } else {
    rtb_Add_h5 = rtb_Sin4;
  }

  /* End of Saturate: '<S335>/Saturation1' */

  /* Sum: '<S335>/Add1' */
  rtb_Add_oy = rtb_Init_o + rtb_Add_h5;

  /* Saturate: '<S335>/Saturation2' */
  if (rtb_Add_oy > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S335>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_oy < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S335>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S335>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_oy;
  }

  /* End of Saturate: '<S335>/Saturation2' */

  /* Switch: '<S319>/Switch' incorporates:
   *  Abs: '<S319>/Abs'
   *  Constant: '<S319>/Constant'
   *  Constant: '<S334>/Constant'
   *  RelationalOperator: '<S334>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Optimized_Module_Angle_p = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Optimized_Module_Angle_p = 0.0;
  }

  /* End of Switch: '<S319>/Switch' */

  /* Signum: '<S318>/Sign2' incorporates:
   *  UnitDelay: '<S318>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S318>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S318>/Product1' incorporates:
   *  Signum: '<S318>/Sign1'
   *  Signum: '<S318>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S318>/Switch' incorporates:
   *  Constant: '<S318>/Constant'
   *  Constant: '<S327>/Constant'
   *  Constant: '<S328>/Constant'
   *  Logic: '<S318>/or'
   *  Product: '<S318>/Product1'
   *  RelationalOperator: '<S327>/Compare'
   *  RelationalOperator: '<S328>/Compare'
   *  UnitDelay: '<S318>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_nf = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_nf = 0.0;
  }

  /* End of Switch: '<S318>/Switch' */

  /* Switch: '<S333>/Init' incorporates:
   *  UnitDelay: '<S333>/FixPt Unit Delay1'
   *  UnitDelay: '<S333>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Switch2_nf;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S333>/Init' */

  /* RelationalOperator: '<S329>/Compare' incorporates:
   *  Constant: '<S329>/Constant'
   */
  rtb_Compare_a = (rtb_Switch2_nf == 0.0);

  /* RelationalOperator: '<S330>/Compare' incorporates:
   *  Constant: '<S330>/Constant'
   */
  rtb_AND1_c = (rtb_Switch2_nf > 0.0);

  /* Abs: '<S318>/Abs' incorporates:
   *  Sum: '<S318>/Subtract'
   *  UnitDelay: '<S318>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S318>/Switch5' incorporates:
   *  Constant: '<S318>/Constant1'
   *  Switch: '<S318>/Switch1'
   *  UnaryMinus: '<S318>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S318>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S318>/Constant4'
     *  Constant: '<S318>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S318>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S318>/Constant2'
     *  Constant: '<S318>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S318>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S318>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S318>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S318>/Constant10'
     *  Constant: '<S318>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S318>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S318>/Constant7'
     *  Constant: '<S318>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S318>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S318>/Lookup Table Dynamic1'
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

    /* Switch: '<S318>/Switch3' incorporates:
     *  Constant: '<S318>/Constant1'
     *  Constant: '<S318>/Constant3'
     *  UnaryMinus: '<S318>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S318>/Switch3' */
  }

  /* End of Switch: '<S318>/Switch5' */

  /* Product: '<S318>/Product' incorporates:
   *  Switch: '<S318>/Switch1'
   */
  rtb_Init = rtb_Add_oy * rtb_Sin4;

  /* Sum: '<S331>/Sum1' */
  rtb_DeadZone = rtb_Switch2_nf - rtb_Init_o;

  /* Switch: '<S332>/Switch2' incorporates:
   *  RelationalOperator: '<S332>/LowerRelop1'
   */
  if (!(rtb_DeadZone > rtb_Init)) {
    /* Switch: '<S318>/Switch2' incorporates:
     *  Constant: '<S318>/Constant1'
     *  Constant: '<S318>/Constant3'
     *  Switch: '<S318>/Switch4'
     *  UnaryMinus: '<S318>/Unary Minus1'
     */
    if (rtb_Compare_a) {
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S318>/Switch4' incorporates:
       *  Constant: '<S318>/Constant1'
       */
      rtb_Add_oy = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_oy = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S318>/Product2' incorporates:
     *  Switch: '<S318>/Switch2'
     */
    rtb_Switch1 = rtb_Add_oy * rtb_Sin4;

    /* Switch: '<S332>/Switch' incorporates:
     *  RelationalOperator: '<S332>/UpperRelop'
     */
    if (rtb_DeadZone < rtb_Switch1) {
      rtb_Init = rtb_Switch1;
    } else {
      rtb_Init = rtb_DeadZone;
    }

    /* End of Switch: '<S332>/Switch' */
  }

  /* End of Switch: '<S332>/Switch2' */

  /* Sum: '<S331>/Sum' */
  rtb_Init_o += rtb_Init;

  /* Signum: '<S317>/Sign2' incorporates:
   *  UnitDelay: '<S317>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_oy = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S317>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S317>/Product1' incorporates:
   *  Signum: '<S317>/Sign1'
   *  Signum: '<S317>/Sign2'
   */
  rtb_Add_oy *= rtb_Minus_k_idx_1;
  if (rtIsNaN(rtb_Add_oy)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_oy, 256.0);
  }

  /* Switch: '<S317>/Switch' incorporates:
   *  Constant: '<S317>/Constant'
   *  Constant: '<S320>/Constant'
   *  Constant: '<S321>/Constant'
   *  Logic: '<S317>/or'
   *  Product: '<S317>/Product1'
   *  RelationalOperator: '<S320>/Compare'
   *  RelationalOperator: '<S321>/Compare'
   *  UnitDelay: '<S317>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_nf = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_nf = 0.0;
  }

  /* End of Switch: '<S317>/Switch' */

  /* Switch: '<S326>/Init' incorporates:
   *  UnitDelay: '<S326>/FixPt Unit Delay1'
   *  UnitDelay: '<S326>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_nf;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S326>/Init' */

  /* RelationalOperator: '<S322>/Compare' incorporates:
   *  Constant: '<S322>/Constant'
   */
  rtb_Compare_a = (rtb_Switch2_nf == 0.0);

  /* RelationalOperator: '<S323>/Compare' incorporates:
   *  Constant: '<S323>/Constant'
   */
  rtb_AND1_c = (rtb_Switch2_nf > 0.0);

  /* Abs: '<S317>/Abs' incorporates:
   *  Sum: '<S317>/Subtract'
   *  UnitDelay: '<S317>/Unit Delay'
   */
  rtb_DeadZone = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                      Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S317>/Switch1' incorporates:
   *  Constant: '<S317>/Constant1'
   *  Switch: '<S317>/Switch3'
   *  Switch: '<S317>/Switch5'
   *  UnaryMinus: '<S317>/Unary Minus'
   */
  if (rtb_Compare_a) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S317>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S317>/Constant1'
     *  Constant: '<S317>/Constant4'
     *  Constant: '<S317>/Constant6'
     *  UnaryMinus: '<S317>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S317>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S317>/Constant2'
     *  Constant: '<S317>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S317>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S317>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_DeadZone, &rtb_Minus_n[0], 1U);
    rtb_DeadZone = rtb_LookupTableDynamic_p;
  } else {
    if (rtb_AND1_c) {
      /* Switch: '<S317>/Switch3' incorporates:
       *  Constant: '<S317>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S317>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S317>/Constant1'
     *  Constant: '<S317>/Constant10'
     *  Constant: '<S317>/Constant8'
     *  UnaryMinus: '<S317>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S317>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S317>/Constant7'
     *  Constant: '<S317>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S317>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S317>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_DeadZone, &rtb_Minus_n[0], 1U);
    rtb_DeadZone = rtb_LookupTableDynamic1_g;
  }

  /* End of Switch: '<S317>/Switch1' */

  /* Product: '<S317>/Product' */
  rtb_Sin4 *= rtb_DeadZone;

  /* Sum: '<S324>/Sum1' */
  rtb_Switch1 = rtb_Switch2_nf - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S325>/Switch2' incorporates:
   *  RelationalOperator: '<S325>/LowerRelop1'
   */
  if (!(rtb_Switch1 > rtb_Sin4)) {
    /* Switch: '<S317>/Switch2' incorporates:
     *  Constant: '<S317>/Constant1'
     *  Switch: '<S317>/Switch4'
     */
    if (rtb_Compare_a) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S317>/Switch4' incorporates:
       *  Constant: '<S317>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S317>/Switch4' incorporates:
       *  Constant: '<S317>/Constant3'
       *  UnaryMinus: '<S317>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S317>/Switch2' */

    /* Product: '<S317>/Product2' */
    rtb_Sin4 *= rtb_DeadZone;

    /* Switch: '<S325>/Switch' incorporates:
     *  RelationalOperator: '<S325>/UpperRelop'
     */
    if (!(rtb_Switch1 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch1;
    }

    /* End of Switch: '<S325>/Switch' */
  }

  /* End of Switch: '<S325>/Switch2' */

  /* Sum: '<S324>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S307>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S307>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S307>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S307>/Switch' */

  /* Fcn: '<S348>/r->x' incorporates:
   *  Fcn: '<S353>/r->x'
   *  Fcn: '<S358>/r->x'
   *  Fcn: '<S363>/r->x'
   */
  rtb_Switch1 = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S342>/Add' incorporates:
   *  Fcn: '<S348>/r->x'
   *  Fcn: '<S349>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1;

  /* Fcn: '<S348>/theta->y' incorporates:
   *  Fcn: '<S353>/theta->y'
   *  Fcn: '<S358>/theta->y'
   *  Fcn: '<S363>/theta->y'
   */
  rtb_DeadZone = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S342>/Add' incorporates:
   *  Fcn: '<S348>/theta->y'
   *  Fcn: '<S349>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S343>/Add' incorporates:
   *  Fcn: '<S354>/r->x'
   *  Fcn: '<S354>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S344>/Add' incorporates:
   *  Fcn: '<S359>/r->x'
   *  Fcn: '<S359>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_DeadZone;

  /* Sum: '<S345>/Add' incorporates:
   *  Fcn: '<S364>/r->x'
   *  Fcn: '<S364>/theta->y'
   */
  rtb_Switch2_p2 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_DeadZone;

  /* Fcn: '<S362>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Switch2_p2, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S365>/Compare' incorporates:
   *  Constant: '<S365>/Constant'
   */
  rtb_Compare_a = (rtb_Init == 0.0);

  /* Switch: '<S361>/Switch1' */
  if (rtb_Compare_a) {
    /* Switch: '<S361>/Switch1' incorporates:
     *  Constant: '<S361>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S361>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S361>/Switch1' */

  /* Fcn: '<S347>/x->r' */
  rtb_Init = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S350>/Compare' incorporates:
   *  Constant: '<S350>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Init == 0.0);

  /* Switch: '<S346>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S346>/Switch1' incorporates:
     *  Constant: '<S346>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S346>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Init;
  }

  /* End of Switch: '<S346>/Switch1' */

  /* Fcn: '<S352>/x->r' */
  rtb_Switch2_nf = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S355>/Compare' incorporates:
   *  Constant: '<S355>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Switch2_nf == 0.0);

  /* Switch: '<S351>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S351>/Switch1' incorporates:
     *  Constant: '<S351>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S351>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_nf;
  }

  /* End of Switch: '<S351>/Switch1' */

  /* Fcn: '<S357>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S360>/Compare' incorporates:
   *  Constant: '<S360>/Constant'
   */
  rtb_AND1_c = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S356>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S356>/Switch1' incorporates:
     *  Constant: '<S356>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S356>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S356>/Switch1' */

  /* Product: '<S341>/Divide' incorporates:
   *  Abs: '<S341>/Abs'
   *  Abs: '<S341>/Abs1'
   *  Abs: '<S341>/Abs2'
   *  Abs: '<S341>/Abs3'
   *  Constant: '<S341>/Constant'
   *  MinMax: '<S341>/Max'
   */
  rtb_Init = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S341>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S361>/Switch' */
  if (!rtb_Compare_a) {
    /* Switch: '<S361>/Switch' incorporates:
     *  Fcn: '<S362>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Switch2_p2);
  }

  /* End of Switch: '<S361>/Switch' */

  /* Trigonometry: '<S297>/Cos4' incorporates:
   *  Switch: '<S286>/Angle_Switch'
   *  Trigonometry: '<S296>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S297>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S295>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S297>/Sin4' incorporates:
   *  Switch: '<S286>/Angle_Switch'
   *  Trigonometry: '<S296>/Sin4'
   */
  rtb_DeadZone = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S297>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S295>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S297>/Subtract1' incorporates:
   *  Product: '<S297>/Product2'
   *  Product: '<S297>/Product3'
   *  Trigonometry: '<S297>/Cos4'
   *  Trigonometry: '<S297>/Sin4'
   */
  rtb_Switch1 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle) + (rtb_DeadZone
    * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S297>/Subtract' incorporates:
   *  Product: '<S297>/Product'
   *  Product: '<S297>/Product1'
   *  Trigonometry: '<S297>/Cos4'
   *  Trigonometry: '<S297>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_DeadZone * rtb_Optimized_Module_Angle);

  /* Math: '<S297>/Hypot' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

  /* Switch: '<S297>/Switch' incorporates:
   *  Constant: '<S297>/Constant'
   *  Constant: '<S297>/Constant1'
   *  Constant: '<S298>/Constant'
   *  Product: '<S297>/Divide'
   *  Product: '<S297>/Divide1'
   *  RelationalOperator: '<S298>/Compare'
   *  Switch: '<S297>/Switch1'
   */
  if (rtb_Switch2_p2 > 1.0E-6) {
    rtb_Switch2_nf = rtb_Switch1 / rtb_Switch2_p2;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Switch2_p2;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S297>/Switch' */

  /* Switch: '<S286>/Speed_Switch' incorporates:
   *  Abs: '<S286>/Abs'
   *  Constant: '<S294>/Constant'
   *  RelationalOperator: '<S294>/Compare'
   *  Switch: '<S286>/Angle_Switch'
   *  Trigonometry: '<S296>/Atan1'
   *  Trigonometry: '<S297>/Atan1'
   *  UnaryMinus: '<S286>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S296>/Subtract1' incorporates:
     *  Product: '<S296>/Product2'
     *  Product: '<S296>/Product3'
     *  UnaryMinus: '<S286>/Unary Minus'
     */
    rtb_Switch1 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c) +
      (rtb_DeadZone * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S296>/Subtract' incorporates:
     *  Product: '<S296>/Product'
     *  Product: '<S296>/Product1'
     */
    rtb_Switch2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b) -
      (rtb_DeadZone * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S296>/Hypot' */
    rtb_DeadZone = rt_hypotd_snf(rtb_Switch2, rtb_Switch1);

    /* Switch: '<S296>/Switch1' incorporates:
     *  Constant: '<S296>/Constant'
     *  Constant: '<S296>/Constant1'
     *  Constant: '<S299>/Constant'
     *  Product: '<S296>/Divide'
     *  Product: '<S296>/Divide1'
     *  RelationalOperator: '<S299>/Compare'
     *  Switch: '<S296>/Switch'
     */
    if (rtb_DeadZone > 1.0E-6) {
      rtb_Switch2 /= rtb_DeadZone;
      rtb_DeadZone = rtb_Switch1 / rtb_DeadZone;
    } else {
      rtb_Switch2 = 1.0;
      rtb_DeadZone = 0.0;
    }

    /* End of Switch: '<S296>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_DeadZone, rtb_Switch2);
  } else {
    rtb_Add_oy = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S289>/Product2' incorporates:
   *  Constant: '<S289>/Constant'
   *  Switch: '<S286>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S284>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S284>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S287>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S288>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S219>/Product' incorporates:
   *  Abs: '<S284>/Abs'
   *  Abs: '<S287>/Abs'
   *  Constant: '<S290>/Constant'
   *  Constant: '<S300>/Constant3'
   *  Constant: '<S300>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S284>/OR'
   *  Lookup_n-D: '<S287>/1-D Lookup Table'
   *  Math: '<S300>/Math Function'
   *  RelationalOperator: '<S284>/Equal1'
   *  RelationalOperator: '<S290>/Compare'
   *  Signum: '<S284>/Sign'
   *  Signum: '<S284>/Sign1'
   *  Sum: '<S287>/Add'
   *  Sum: '<S300>/Add1'
   *  Sum: '<S300>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData, 1U);

  /* Sum: '<S285>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2 = rtb_Switch2_nf - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S292>/Sum1' incorporates:
   *  Constant: '<S285>/Constant2'
   *  Product: '<S292>/Product'
   *  Sum: '<S292>/Sum'
   *  UnitDelay: '<S292>/Unit Delay1'
   */
  rtb_DeadZone = ((rtb_Switch2 - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S285>/Product' incorporates:
   *  Constant: '<S285>/Constant3'
   */
  rtb_Switch1 = rtb_DeadZone * Drive_Motor_Control_D;

  /* Sum: '<S291>/Diff' incorporates:
   *  UnitDelay: '<S291>/UD'
   *
   * Block description for '<S291>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S291>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch1 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S285>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S285>/Add' incorporates:
   *  Gain: '<S285>/Gain'
   *  Gain: '<S285>/Gain1'
   *  Saturate: '<S285>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
                    (Drive_Motor_Control_P * rtb_Switch2)) + rtb_Add_oy;

  /* Saturate: '<S285>/Saturation2' incorporates:
   *  Sum: '<S285>/Add1'
   */
  if (rtb_Switch2_p2 > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch2_p2 < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_Switch2_p2;
  }

  /* End of Saturate: '<S285>/Saturation2' */

  /* Switch: '<S346>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S346>/Switch' incorporates:
     *  Fcn: '<S347>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S346>/Switch' */

  /* Trigonometry: '<S234>/Cos4' incorporates:
   *  Switch: '<S223>/Angle_Switch'
   *  Trigonometry: '<S233>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S234>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S232>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S234>/Sin4' incorporates:
   *  Switch: '<S223>/Angle_Switch'
   *  Trigonometry: '<S233>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S234>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S232>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S234>/Subtract1' incorporates:
   *  Product: '<S234>/Product2'
   *  Product: '<S234>/Product3'
   *  Trigonometry: '<S234>/Cos4'
   *  Trigonometry: '<S234>/Sin4'
   */
  rtb_Switch2_p2 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S234>/Subtract' incorporates:
   *  Product: '<S234>/Product'
   *  Product: '<S234>/Product1'
   *  Trigonometry: '<S234>/Cos4'
   *  Trigonometry: '<S234>/Sin4'
   */
  rtb_Switch2 = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S234>/Hypot' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Switch2, rtb_Switch2_p2);

  /* Switch: '<S234>/Switch' incorporates:
   *  Constant: '<S234>/Constant'
   *  Constant: '<S234>/Constant1'
   *  Constant: '<S235>/Constant'
   *  Product: '<S234>/Divide'
   *  Product: '<S234>/Divide1'
   *  RelationalOperator: '<S235>/Compare'
   *  Switch: '<S234>/Switch1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
    rtb_Switch2_nf = rtb_Switch2_p2 / rtb_MatrixConcatenate_b_idx_0;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S234>/Switch' */

  /* Product: '<S341>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S223>/Speed_Switch' incorporates:
   *  Abs: '<S223>/Abs'
   *  Constant: '<S231>/Constant'
   *  RelationalOperator: '<S231>/Compare'
   *  Switch: '<S223>/Angle_Switch'
   *  Trigonometry: '<S233>/Atan1'
   *  Trigonometry: '<S234>/Atan1'
   *  UnaryMinus: '<S223>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S233>/Subtract1' incorporates:
     *  Product: '<S233>/Product2'
     *  Product: '<S233>/Product3'
     *  UnaryMinus: '<S223>/Unary Minus'
     */
    rtb_Switch2_p2 = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S233>/Subtract' incorporates:
     *  Product: '<S233>/Product'
     *  Product: '<S233>/Product1'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Cos5) - (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Sin5);

    /* Math: '<S233>/Hypot' */
    rtb_Switch2 = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Switch2_p2);

    /* Switch: '<S233>/Switch1' incorporates:
     *  Constant: '<S233>/Constant'
     *  Constant: '<S233>/Constant1'
     *  Constant: '<S236>/Constant'
     *  Product: '<S233>/Divide'
     *  Product: '<S233>/Divide1'
     *  RelationalOperator: '<S236>/Compare'
     *  Switch: '<S233>/Switch'
     */
    if (rtb_Switch2 > 1.0E-6) {
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Switch2;
      rtb_Switch2_p2 /= rtb_Switch2;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = 1.0;
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S233>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Switch2_p2,
      rtb_MatrixConcatenate_b_idx_0);
  } else {
    rtb_Add_oy = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S226>/Product2' incorporates:
   *  Constant: '<S226>/Constant'
   *  Switch: '<S223>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S221>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S221>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S224>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S225>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S216>/Product' incorporates:
   *  Abs: '<S221>/Abs'
   *  Abs: '<S224>/Abs'
   *  Constant: '<S227>/Constant'
   *  Constant: '<S237>/Constant3'
   *  Constant: '<S237>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S221>/OR'
   *  Lookup_n-D: '<S224>/1-D Lookup Table'
   *  Math: '<S237>/Math Function'
   *  RelationalOperator: '<S221>/Equal1'
   *  RelationalOperator: '<S227>/Compare'
   *  Signum: '<S221>/Sign'
   *  Signum: '<S221>/Sign1'
   *  Sum: '<S224>/Add'
   *  Sum: '<S237>/Add1'
   *  Sum: '<S237>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j,
                  1U);

  /* Sum: '<S222>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_nf -
    Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S229>/Sum1' incorporates:
   *  Constant: '<S222>/Constant2'
   *  Product: '<S229>/Product'
   *  Sum: '<S229>/Sum'
   *  UnitDelay: '<S229>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_MatrixConcatenate_b_idx_0 -
                     Robot_Control_DW.UnitDelay1_DSTATE_f) *
                    Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S222>/Product' incorporates:
   *  Constant: '<S222>/Constant3'
   */
  rtb_Switch2 = rtb_Switch2_p2 * Drive_Motor_Control_D;

  /* Sum: '<S228>/Diff' incorporates:
   *  UnitDelay: '<S228>/UD'
   *
   * Block description for '<S228>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S228>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S222>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S222>/Add' incorporates:
   *  Gain: '<S222>/Gain'
   *  Gain: '<S222>/Gain1'
   *  Saturate: '<S222>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
    (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)) + rtb_Add_oy;

  /* Saturate: '<S222>/Saturation2' incorporates:
   *  Sum: '<S222>/Add1'
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

  /* End of Saturate: '<S222>/Saturation2' */

  /* Sum: '<S238>/Add1' incorporates:
   *  Constant: '<S238>/Constant3'
   *  Constant: '<S238>/Constant4'
   *  Math: '<S238>/Math Function'
   *  Sum: '<S238>/Add2'
   */
  rtb_Switch2_nf = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S240>/Sum1' incorporates:
   *  Constant: '<S225>/Constant2'
   *  Product: '<S240>/Product'
   *  Sum: '<S240>/Sum'
   *  UnitDelay: '<S240>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((rtb_Switch2_nf -
    Robot_Control_DW.UnitDelay1_DSTATE_b) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S225>/Product' incorporates:
   *  Constant: '<S225>/Constant3'
   */
  rtb_Switch2_ow = rtb_MatrixConcatenate_b_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S239>/Diff' incorporates:
   *  UnitDelay: '<S239>/UD'
   *
   * Block description for '<S239>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S239>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch2_ow - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S225>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S225>/Add' incorporates:
   *  Gain: '<S225>/Gain1'
   *  Saturate: '<S225>/Saturation'
   */
  rtb_MatrixConcatenate_idx_0 = (Steering_Motor_Control_P * rtb_Switch2_nf) +
    rtb_Add_oy;

  /* Sum: '<S225>/Subtract' incorporates:
   *  Constant: '<S225>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_MatrixConcatenate_idx_0;

  /* Sum: '<S225>/Sum2' incorporates:
   *  Gain: '<S225>/Gain2'
   *  UnitDelay: '<S225>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Switch2_nf) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S241>/Switch2' incorporates:
   *  Constant: '<S225>/Constant'
   *  RelationalOperator: '<S241>/LowerRelop1'
   *  Sum: '<S225>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_MatrixConcatenate_idx_0))) {
    /* Switch: '<S241>/Switch' incorporates:
     *  Constant: '<S225>/Constant1'
     *  RelationalOperator: '<S241>/UpperRelop'
     *  Sum: '<S225>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_MatrixConcatenate_idx_0)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_MatrixConcatenate_idx_0;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S241>/Switch' */
  }

  /* End of Switch: '<S241>/Switch2' */

  /* Saturate: '<S225>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S225>/Saturation1' */

  /* Sum: '<S225>/Add1' */
  rtb_Add_oy = rtb_MatrixConcatenate_idx_0 + rtb_Sum2_e;

  /* Saturate: '<S225>/Saturation2' */
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

  /* End of Saturate: '<S225>/Saturation2' */

  /* Switch: '<S351>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S351>/Switch' incorporates:
     *  Fcn: '<S352>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S351>/Switch' */

  /* Trigonometry: '<S255>/Cos4' incorporates:
   *  Switch: '<S244>/Angle_Switch'
   *  Trigonometry: '<S254>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S255>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S253>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S255>/Sin4' incorporates:
   *  Switch: '<S244>/Angle_Switch'
   *  Trigonometry: '<S254>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S255>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S253>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S255>/Subtract1' incorporates:
   *  Product: '<S255>/Product2'
   *  Product: '<S255>/Product3'
   *  Trigonometry: '<S255>/Cos4'
   *  Trigonometry: '<S255>/Sin4'
   */
  rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S255>/Subtract' incorporates:
   *  Product: '<S255>/Product'
   *  Product: '<S255>/Product1'
   *  Trigonometry: '<S255>/Cos4'
   *  Trigonometry: '<S255>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S255>/Hypot' */
  rtb_Hypot_bl = rt_hypotd_snf(rtb_Subtract1_la, rtb_MatrixConcatenate_idx_0);

  /* Switch: '<S255>/Switch' incorporates:
   *  Constant: '<S255>/Constant'
   *  Constant: '<S255>/Constant1'
   *  Constant: '<S256>/Constant'
   *  Product: '<S255>/Divide'
   *  Product: '<S255>/Divide1'
   *  RelationalOperator: '<S256>/Compare'
   *  Switch: '<S255>/Switch1'
   */
  if (rtb_Hypot_bl > 1.0E-6) {
    rtb_Switch2_nf = rtb_MatrixConcatenate_idx_0 / rtb_Hypot_bl;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_bl;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S255>/Switch' */

  /* Product: '<S341>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S244>/Speed_Switch' incorporates:
   *  Abs: '<S244>/Abs'
   *  Constant: '<S252>/Constant'
   *  RelationalOperator: '<S252>/Compare'
   *  Switch: '<S244>/Angle_Switch'
   *  Trigonometry: '<S254>/Atan1'
   *  Trigonometry: '<S255>/Atan1'
   *  UnaryMinus: '<S244>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S254>/Subtract1' incorporates:
     *  Product: '<S254>/Product2'
     *  Product: '<S254>/Product3'
     *  UnaryMinus: '<S244>/Unary Minus'
     */
    rtb_MatrixConcatenate_idx_0 = (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Sin5_m) + (rtb_Optimized_Module_Angle *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S254>/Subtract' incorporates:
     *  Product: '<S254>/Product'
     *  Product: '<S254>/Product1'
     */
    rtb_Hypot_bl = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S254>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_bl, rtb_MatrixConcatenate_idx_0);

    /* Switch: '<S254>/Switch1' incorporates:
     *  Constant: '<S254>/Constant'
     *  Constant: '<S254>/Constant1'
     *  Constant: '<S257>/Constant'
     *  Product: '<S254>/Divide'
     *  Product: '<S254>/Divide1'
     *  RelationalOperator: '<S257>/Compare'
     *  Switch: '<S254>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_bl /= rtb_Subtract1_la;
      rtb_MatrixConcatenate_idx_0 /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_bl = 1.0;
      rtb_MatrixConcatenate_idx_0 = 0.0;
    }

    /* End of Switch: '<S254>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_MatrixConcatenate_idx_0, rtb_Hypot_bl);
  } else {
    rtb_Add_oy = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S247>/Product2' incorporates:
   *  Constant: '<S247>/Constant'
   *  Switch: '<S244>/Speed_Switch'
   */
  rtb_Switch2_nf = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S242>/Sign' */
  if (rtIsNaN(rtb_Switch2_nf)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Switch2_nf < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Switch2_nf > 0.0);
  }

  /* Signum: '<S242>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S245>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S246>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S217>/Product' incorporates:
   *  Abs: '<S242>/Abs'
   *  Abs: '<S245>/Abs'
   *  Constant: '<S248>/Constant'
   *  Constant: '<S258>/Constant3'
   *  Constant: '<S258>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S242>/OR'
   *  Lookup_n-D: '<S245>/1-D Lookup Table'
   *  Math: '<S258>/Math Function'
   *  RelationalOperator: '<S242>/Equal1'
   *  RelationalOperator: '<S248>/Compare'
   *  Signum: '<S242>/Sign'
   *  Signum: '<S242>/Sign1'
   *  Sum: '<S245>/Add'
   *  Sum: '<S258>/Add1'
   *  Sum: '<S258>/Add2'
   */
  rtb_Switch2_nf = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nf) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_g,
                  1U);

  /* Sum: '<S243>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_bl = rtb_Switch2_nf - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S250>/Sum1' incorporates:
   *  Constant: '<S243>/Constant2'
   *  Product: '<S250>/Product'
   *  Sum: '<S250>/Sum'
   *  UnitDelay: '<S250>/Unit Delay1'
   */
  rtb_MatrixConcatenate_idx_0 = ((rtb_Hypot_bl -
    Robot_Control_DW.UnitDelay1_DSTATE_e) * Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S243>/Product' incorporates:
   *  Constant: '<S243>/Constant3'
   */
  rtb_Subtract1_la = rtb_MatrixConcatenate_idx_0 * Drive_Motor_Control_D;

  /* Sum: '<S249>/Diff' incorporates:
   *  UnitDelay: '<S249>/UD'
   *
   * Block description for '<S249>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S249>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S243>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S243>/Add' incorporates:
   *  Gain: '<S243>/Gain'
   *  Gain: '<S243>/Gain1'
   *  Saturate: '<S243>/Saturation'
   */
  rtb_Hypot_bl = ((Drive_Motor_Control_FF * rtb_Switch2_nf) +
                  (Drive_Motor_Control_P * rtb_Hypot_bl)) + rtb_Add_oy;

  /* Saturate: '<S243>/Saturation2' incorporates:
   *  Sum: '<S243>/Add1'
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

  /* End of Saturate: '<S243>/Saturation2' */

  /* Sum: '<S259>/Add1' incorporates:
   *  Constant: '<S259>/Constant3'
   *  Constant: '<S259>/Constant4'
   *  Math: '<S259>/Math Function'
   *  Sum: '<S259>/Add2'
   */
  rtb_Switch2_nf = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S261>/Sum1' incorporates:
   *  Constant: '<S246>/Constant2'
   *  Product: '<S261>/Product'
   *  Sum: '<S261>/Sum'
   *  UnitDelay: '<S261>/Unit Delay1'
   */
  rtb_Hypot_bl = ((rtb_Switch2_nf - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S246>/Product' incorporates:
   *  Constant: '<S246>/Constant3'
   */
  rtb_Switch2_cw = rtb_Hypot_bl * Steering_Motor_Control_D;

  /* Sum: '<S260>/Diff' incorporates:
   *  UnitDelay: '<S260>/UD'
   *
   * Block description for '<S260>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S260>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Switch2_cw - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S246>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S246>/Add' incorporates:
   *  Gain: '<S246>/Gain1'
   *  Saturate: '<S246>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_nf) + rtb_Add_oy;

  /* Sum: '<S246>/Subtract' incorporates:
   *  Constant: '<S246>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S246>/Sum2' incorporates:
   *  Gain: '<S246>/Gain2'
   *  UnitDelay: '<S246>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_Switch2_nf) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S262>/Switch2' incorporates:
   *  Constant: '<S246>/Constant'
   *  RelationalOperator: '<S262>/LowerRelop1'
   *  Sum: '<S246>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S262>/Switch' incorporates:
     *  Constant: '<S246>/Constant1'
     *  RelationalOperator: '<S262>/UpperRelop'
     *  Sum: '<S246>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S262>/Switch' */
  }

  /* End of Switch: '<S262>/Switch2' */

  /* Saturate: '<S246>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S246>/Saturation1' */

  /* Sum: '<S246>/Add1' */
  rtb_Add_oy = rtb_Minus_k_idx_1 + rtb_Sum2_oc;

  /* Saturate: '<S246>/Saturation2' */
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

  /* End of Saturate: '<S246>/Saturation2' */

  /* Switch: '<S356>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S356>/Switch' incorporates:
     *  Fcn: '<S357>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S356>/Switch' */

  /* Trigonometry: '<S276>/Cos4' incorporates:
   *  Switch: '<S265>/Angle_Switch'
   *  Trigonometry: '<S275>/Cos4'
   */
  rtb_Minus_k_idx_1 = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S276>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S274>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S276>/Sin4' incorporates:
   *  Switch: '<S265>/Angle_Switch'
   *  Trigonometry: '<S275>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S276>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S274>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S276>/Subtract1' incorporates:
   *  Product: '<S276>/Product2'
   *  Product: '<S276>/Product3'
   *  Trigonometry: '<S276>/Cos4'
   *  Trigonometry: '<S276>/Sin4'
   */
  rtb_Switch2_nf = (rtb_Minus_k_idx_1 * rtb_uDLookupTable) +
    (rtb_Optimized_Module_Angle * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S276>/Subtract' incorporates:
   *  Product: '<S276>/Product'
   *  Product: '<S276>/Product1'
   *  Trigonometry: '<S276>/Cos4'
   *  Trigonometry: '<S276>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S276>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_nf);

  /* Switch: '<S276>/Switch' incorporates:
   *  Constant: '<S276>/Constant'
   *  Constant: '<S276>/Constant1'
   *  Constant: '<S277>/Constant'
   *  Product: '<S276>/Divide'
   *  Product: '<S276>/Divide1'
   *  RelationalOperator: '<S277>/Compare'
   *  Switch: '<S276>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Switch2_nf /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Switch2_nf = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S276>/Switch' */

  /* Product: '<S341>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Init;

  /* Switch: '<S265>/Speed_Switch' incorporates:
   *  Abs: '<S265>/Abs'
   *  Constant: '<S273>/Constant'
   *  RelationalOperator: '<S273>/Compare'
   *  Switch: '<S265>/Angle_Switch'
   *  Trigonometry: '<S275>/Atan1'
   *  Trigonometry: '<S276>/Atan1'
   *  UnaryMinus: '<S265>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nf, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_oy = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S275>/Subtract1' incorporates:
     *  Product: '<S275>/Product2'
     *  Product: '<S275>/Product3'
     *  UnaryMinus: '<S265>/Unary Minus'
     */
    rtb_Switch2_nf = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S275>/Subtract' incorporates:
     *  Product: '<S275>/Product'
     *  Product: '<S275>/Product1'
     */
    rtb_uDLookupTable = (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S275>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_uDLookupTable, rtb_Switch2_nf);

    /* Switch: '<S275>/Switch1' incorporates:
     *  Constant: '<S275>/Constant'
     *  Constant: '<S275>/Constant1'
     *  Constant: '<S278>/Constant'
     *  Product: '<S275>/Divide'
     *  Product: '<S275>/Divide1'
     *  RelationalOperator: '<S278>/Compare'
     *  Switch: '<S275>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Minus_k_idx_1;
      rtb_Switch2_nf /= rtb_Minus_k_idx_1;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Switch2_nf = 0.0;
    }

    /* End of Switch: '<S275>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Switch2_nf,
      rtb_uDLookupTable);
  } else {
    rtb_Add_oy = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S268>/Product2' incorporates:
   *  Constant: '<S268>/Constant'
   *  Switch: '<S265>/Speed_Switch'
   */
  rtb_Init = rtb_Add_oy * 1154.7574092481445;

  /* Signum: '<S263>/Sign' */
  if (rtIsNaN(rtb_Init)) {
    rtb_Add_oy = (rtNaN);
  } else if (rtb_Init < 0.0) {
    rtb_Add_oy = -1.0;
  } else {
    rtb_Add_oy = (rtb_Init > 0.0);
  }

  /* Signum: '<S263>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Minus_k_idx_1 = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Minus_k_idx_1 = -1.0;
  } else {
    rtb_Minus_k_idx_1 = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S266>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S267>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S218>/Product' incorporates:
   *  Abs: '<S263>/Abs'
   *  Abs: '<S266>/Abs'
   *  Constant: '<S269>/Constant'
   *  Constant: '<S279>/Constant3'
   *  Constant: '<S279>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S263>/OR'
   *  Lookup_n-D: '<S266>/1-D Lookup Table'
   *  Math: '<S279>/Math Function'
   *  RelationalOperator: '<S263>/Equal1'
   *  RelationalOperator: '<S269>/Compare'
   *  Signum: '<S263>/Sign'
   *  Signum: '<S263>/Sign1'
   *  Sum: '<S266>/Add'
   *  Sum: '<S279>/Add1'
   *  Sum: '<S279>/Add2'
   */
  rtb_Init = (((real_T)((rtb_Add_oy == rtb_Minus_k_idx_1) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init) * look1_binlcpw(fabs
    (rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                 3.1415926535897931) - 1.5707963267948966),
    rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S264>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_nf = rtb_Init - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S271>/Sum1' incorporates:
   *  Constant: '<S264>/Constant2'
   *  Product: '<S271>/Product'
   *  Sum: '<S271>/Sum'
   *  UnitDelay: '<S271>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_Switch2_nf - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S264>/Product' incorporates:
   *  Constant: '<S264>/Constant3'
   */
  rtb_uDLookupTable = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S270>/Diff' incorporates:
   *  UnitDelay: '<S270>/UD'
   *
   * Block description for '<S270>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S270>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S264>/Saturation' */
  if (rtb_Add_oy > Drive_Motor_Control_D_UL) {
    rtb_Add_oy = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Drive_Motor_Control_D_LL) {
    rtb_Add_oy = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S264>/Add' incorporates:
   *  Gain: '<S264>/Gain'
   *  Gain: '<S264>/Gain1'
   *  Saturate: '<S264>/Saturation'
   */
  rtb_Init = ((Drive_Motor_Control_FF * rtb_Init) + (Drive_Motor_Control_P *
    rtb_Switch2_nf)) + rtb_Add_oy;

  /* Saturate: '<S264>/Saturation2' incorporates:
   *  Sum: '<S264>/Add1'
   */
  if (rtb_Init > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Init < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Init;
  }

  /* End of Saturate: '<S264>/Saturation2' */

  /* Sum: '<S280>/Add1' incorporates:
   *  Constant: '<S280>/Constant3'
   *  Constant: '<S280>/Constant4'
   *  Math: '<S280>/Math Function'
   *  Sum: '<S280>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S282>/Sum1' incorporates:
   *  Constant: '<S267>/Constant2'
   *  Product: '<S282>/Product'
   *  Sum: '<S282>/Sum'
   *  UnitDelay: '<S282>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Init -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S267>/Product' incorporates:
   *  Constant: '<S267>/Constant3'
   */
  rtb_Product_lf = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

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
  rtb_Add_oy = rtb_Product_lf - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S267>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S267>/Add' incorporates:
   *  Gain: '<S267>/Gain1'
   *  Saturate: '<S267>/Saturation'
   */
  rtb_Add_f1 = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_oy;

  /* Sum: '<S267>/Subtract' incorporates:
   *  Constant: '<S267>/Constant'
   */
  rtb_Switch2_nf = 1.0 - rtb_Add_f1;

  /* Sum: '<S267>/Sum2' incorporates:
   *  Gain: '<S267>/Gain2'
   *  UnitDelay: '<S267>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S283>/Switch2' incorporates:
   *  Constant: '<S267>/Constant'
   *  RelationalOperator: '<S283>/LowerRelop1'
   *  Sum: '<S267>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_f1))) {
    /* Sum: '<S267>/Subtract1' incorporates:
     *  Constant: '<S267>/Constant1'
     */
    rtb_Switch2_nf = -1.0 - rtb_Add_f1;

    /* Switch: '<S283>/Switch' incorporates:
     *  Constant: '<S267>/Constant1'
     *  RelationalOperator: '<S283>/UpperRelop'
     *  Sum: '<S267>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_f1))) {
      rtb_Switch2_nf = rtb_Init;
    }

    /* End of Switch: '<S283>/Switch' */
  }

  /* End of Switch: '<S283>/Switch2' */

  /* Saturate: '<S267>/Saturation1' */
  if (rtb_Switch2_nf > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_nf < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Switch2_nf;
  }

  /* End of Saturate: '<S267>/Saturation1' */

  /* Sum: '<S267>/Add1' */
  rtb_Add_oy = rtb_Add_f1 + rtb_Integral_ga;

  /* Saturate: '<S267>/Saturation2' */
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

  /* End of Saturate: '<S267>/Saturation2' */

  /* Sum: '<S301>/Add1' incorporates:
   *  Constant: '<S301>/Constant3'
   *  Constant: '<S301>/Constant4'
   *  Math: '<S301>/Math Function'
   *  Sum: '<S301>/Add2'
   */
  rtb_Init = rt_modd_snf(rtb_Integral_d + 3.1415926535897931, 6.2831853071795862)
    - 3.1415926535897931;

  /* Sum: '<S303>/Sum1' incorporates:
   *  Constant: '<S288>/Constant2'
   *  Product: '<S303>/Product'
   *  Sum: '<S303>/Sum'
   *  UnitDelay: '<S303>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_i)
    * Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S288>/Product' incorporates:
   *  Constant: '<S288>/Constant3'
   */
  rtb_Add_f1 = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

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
  rtb_Add_oy = rtb_Add_f1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S288>/Saturation' */
  if (rtb_Add_oy > Steering_Motor_Control_D_UL) {
    rtb_Add_oy = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_oy < Steering_Motor_Control_D_LL) {
    rtb_Add_oy = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S288>/Add' incorporates:
   *  Gain: '<S288>/Gain1'
   *  Saturate: '<S288>/Saturation'
   */
  rtb_Add_fd = (Steering_Motor_Control_P * rtb_Init) + rtb_Add_oy;

  /* Sum: '<S288>/Subtract' incorporates:
   *  Constant: '<S288>/Constant'
   */
  rtb_Switch2_nf = 1.0 - rtb_Add_fd;

  /* Sum: '<S288>/Sum2' incorporates:
   *  Gain: '<S288>/Gain2'
   *  UnitDelay: '<S288>/Unit Delay'
   */
  rtb_Init = (Steering_Motor_Control_I * rtb_Init) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S304>/Switch2' incorporates:
   *  Constant: '<S288>/Constant'
   *  RelationalOperator: '<S304>/LowerRelop1'
   *  Sum: '<S288>/Subtract'
   */
  if (!(rtb_Init > (1.0 - rtb_Add_fd))) {
    /* Sum: '<S288>/Subtract1' incorporates:
     *  Constant: '<S288>/Constant1'
     */
    rtb_Switch2_nf = -1.0 - rtb_Add_fd;

    /* Switch: '<S304>/Switch' incorporates:
     *  Constant: '<S288>/Constant1'
     *  RelationalOperator: '<S304>/UpperRelop'
     *  Sum: '<S288>/Subtract1'
     */
    if (!(rtb_Init < (-1.0 - rtb_Add_fd))) {
      rtb_Switch2_nf = rtb_Init;
    }

    /* End of Switch: '<S304>/Switch' */
  }

  /* End of Switch: '<S304>/Switch2' */

  /* Saturate: '<S288>/Saturation1' */
  if (rtb_Switch2_nf > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_nf < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Switch2_nf;
  }

  /* End of Saturate: '<S288>/Saturation1' */

  /* Sum: '<S288>/Add1' */
  rtb_Add_oy = rtb_Add_fd + rtb_Integral_bj;

  /* Saturate: '<S288>/Saturation2' */
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

  /* End of Saturate: '<S288>/Saturation2' */

  /* Sum: '<S151>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S111>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S153>/Sum1' incorporates:
   *  Constant: '<S151>/Constant2'
   *  Product: '<S153>/Product'
   *  Sum: '<S151>/Sum'
   *  Sum: '<S153>/Sum'
   *  UnitDelay: '<S153>/Unit Delay1'
   */
  rtb_Add_fd = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S151>/Product' incorporates:
   *  Constant: '<S151>/Constant3'
   */
  rtb_Product_lo = rtb_Add_fd * 0.0;

  /* Sum: '<S152>/Diff' incorporates:
   *  UnitDelay: '<S152>/UD'
   *
   * Block description for '<S152>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S152>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S151>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S151>/Add' incorporates:
   *  Gain: '<S151>/Gain'
   *  Gain: '<S151>/Gain1'
   *  Saturate: '<S151>/Saturation'
   *  Sum: '<S151>/Sum'
   */
  rtb_Init = ((Rebuilt_Transfer_Motor_Gain_FF *
               Robot_Control_B.RB_Desired_Transfer_Speed) +
              (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_oy;

  /* Logic: '<S111>/Logical Operator1' incorporates:
   *  Constant: '<S150>/Constant'
   *  RelationalOperator: '<S150>/Compare'
   */
  rtb_Is_Absolute_Translation_g = !(Robot_Control_B.RB_Desired_Transfer_Speed ==
    0.0);

  /* Switch: '<S111>/Switch1' incorporates:
   *  Abs: '<S111>/Abs'
   *  Constant: '<S111>/Constant1'
   *  Constant: '<S111>/Constant2'
   *  Logic: '<S111>/Logical Operator'
   *  Logic: '<S111>/Logical Operator1'
   *  RelationalOperator: '<S111>/LessThan'
   *  UnitDelay: '<S111>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Is_Absolute_Translation_g) {
    rtb_Compare_a = true;
  } else {
    rtb_Compare_a = (rtb_Is_Absolute_Translation_g &&
                     (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S111>/Switch1' */

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S151>/Constant4'
   */
  if (rtb_Compare_a) {
    /* Sum: '<S151>/Sum2' incorporates:
     *  Gain: '<S151>/Gain2'
     *  Sum: '<S151>/Sum'
     *  UnitDelay: '<S151>/Unit Delay'
     */
    rtb_Switch2_nf = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S151>/Subtract' incorporates:
     *  Constant: '<S151>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Init;

    /* Switch: '<S154>/Switch2' incorporates:
     *  Constant: '<S151>/Constant'
     *  RelationalOperator: '<S154>/LowerRelop1'
     *  Sum: '<S151>/Subtract'
     */
    if (!(rtb_Switch2_nf > (1.0 - rtb_Init))) {
      /* Sum: '<S151>/Subtract1' incorporates:
       *  Constant: '<S151>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Init;

      /* Switch: '<S154>/Switch' incorporates:
       *  Constant: '<S151>/Constant1'
       *  RelationalOperator: '<S154>/UpperRelop'
       *  Sum: '<S151>/Subtract1'
       */
      if (!(rtb_Switch2_nf < (-1.0 - rtb_Init))) {
        rtb_Integral_d = rtb_Switch2_nf;
      }

      /* End of Switch: '<S154>/Switch' */
    }

    /* End of Switch: '<S154>/Switch2' */

    /* Saturate: '<S151>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S151>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S151>/Switch' */

  /* Switch: '<S111>/Switch2' incorporates:
   *  Logic: '<S111>/Logical Operator1'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* Sum: '<S151>/Add1' */
    rtb_Add_oy = rtb_Init + rtb_Integral_d;

    /* Saturate: '<S151>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S111>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S111>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S111>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S151>/Saturation2' */
  } else {
    /* Switch: '<S111>/Switch2' incorporates:
     *  Constant: '<S111>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S111>/Switch2' */

  /* Product: '<S12>/Product' incorporates:
   *  Constant: '<S12>/Constant'
   */
  Robot_Control_B.RB_Feeder_Motor_PID_DC =
    Robot_Control_B.RB_Desired_Feeder_Speed * Rebuilt_Feeder_Motor_Gain_FF;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant6'
   *  Switch: '<S10>/Switch1'
   *  Switch: '<S10>/Switch5'
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

    /* Outport: '<Root>/Feeder_Motor_DC' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    Robot_Control_Y.Feeder_Motor_DC = TEST_Feeder_Motor_DC_OV;
    rtb_Init = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Transfer_Motor_DC' */
    Robot_Control_Y.Transfer_Motor_DC = Robot_Control_B.RB_Transfer_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S10>/Constant8'
     */
    Robot_Control_Y.Desired_Hood_Enable = true;

    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;
    rtb_Init = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_Init > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Init = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Init < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Init = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Init;

  /* Switch: '<S103>/Init' incorporates:
   *  UnitDelay: '<S103>/FixPt Unit Delay1'
   *  UnitDelay: '<S103>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Switch2_nf = rtb_Init;
  } else {
    rtb_Switch2_nf = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S103>/Init' */

  /* Sum: '<S101>/Sum1' */
  rtb_Init -= rtb_Switch2_nf;

  /* Switch: '<S102>/Switch2' incorporates:
   *  Constant: '<S100>/Constant1'
   *  Constant: '<S100>/Constant3'
   *  RelationalOperator: '<S102>/LowerRelop1'
   *  RelationalOperator: '<S102>/UpperRelop'
   *  Switch: '<S102>/Switch'
   */
  if (rtb_Init > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Init < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S102>/Switch' incorporates:
     *  Constant: '<S100>/Constant1'
     */
    rtb_Init = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S102>/Switch2' */

  /* Sum: '<S101>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Init + rtb_Switch2_nf;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  if (rtb_LogicalOperator1_n) {
    rtb_Init = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S32>/Logical Operator1' incorporates:
   *  Constant: '<S41>/Constant'
   *  RelationalOperator: '<S41>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Init == 0.0);

  /* Sum: '<S42>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S32>/Subtract'
   */
  rtb_Error_n = rtb_Init - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S44>/Sum1' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Product: '<S44>/Product'
   *  Sum: '<S42>/Sum'
   *  Sum: '<S44>/Sum'
   *  UnitDelay: '<S44>/Unit Delay1'
   */
  rtb_Sum1_fh = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S42>/Product' incorporates:
   *  Constant: '<S42>/Constant3'
   */
  rtb_Product_hm = rtb_Sum1_fh * 0.0;

  /* Sum: '<S43>/Diff' incorporates:
   *  UnitDelay: '<S43>/UD'
   *
   * Block description for '<S43>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S43>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_hm - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S42>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S42>/Add' incorporates:
   *  Gain: '<S42>/Gain'
   *  Gain: '<S42>/Gain1'
   *  Saturate: '<S42>/Saturation'
   *  Sum: '<S42>/Sum'
   */
  rtb_Switch2_nf = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Init) +
                    (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_oy;

  /* Switch: '<S32>/Switch1' incorporates:
   *  Abs: '<S32>/Abs'
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S32>/Constant2'
   *  Logic: '<S32>/Logical Operator'
   *  Logic: '<S32>/Logical Operator1'
   *  RelationalOperator: '<S32>/LessThan'
   *  UnitDelay: '<S32>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_AND1_c = true;
  } else {
    rtb_AND1_c = (rtb_LogicalOperator1_n && (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S32>/Switch1' */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant4'
   */
  if (rtb_AND1_c) {
    /* Sum: '<S42>/Sum2' incorporates:
     *  Gain: '<S42>/Gain2'
     *  Sum: '<S42>/Sum'
     *  UnitDelay: '<S42>/Unit Delay'
     */
    rtb_Init = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S42>/Subtract' incorporates:
     *  Constant: '<S42>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Switch2_nf;

    /* Switch: '<S45>/Switch2' incorporates:
     *  Constant: '<S42>/Constant'
     *  RelationalOperator: '<S45>/LowerRelop1'
     *  Sum: '<S42>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Switch2_nf))) {
      /* Sum: '<S42>/Subtract1' incorporates:
       *  Constant: '<S42>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Switch2_nf;

      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S42>/Constant1'
       *  RelationalOperator: '<S45>/UpperRelop'
       *  Sum: '<S42>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Switch2_nf))) {
        rtb_Error_n = rtb_Init;
      }

      /* End of Switch: '<S45>/Switch' */
    }

    /* End of Switch: '<S45>/Switch2' */

    /* Saturate: '<S42>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Error_n = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Error_n = -0.1;
    }

    /* End of Saturate: '<S42>/Saturation1' */
  } else {
    rtb_Error_n = 0.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Switch: '<S32>/Switch2' incorporates:
   *  Logic: '<S32>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S42>/Add1' */
    rtb_Add_oy = rtb_Switch2_nf + rtb_Error_n;

    /* Saturate: '<S42>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S32>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S32>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S32>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S42>/Saturation2' */
  } else {
    /* Switch: '<S32>/Switch2' incorporates:
     *  Constant: '<S32>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S32>/Switch2' */

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

  /* Chart: '<S6>/Chart' incorporates:
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  RelationalOperator: '<S29>/FixPt Relational Operator'
   *  UnitDelay: '<S29>/Delay Input1'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Robot_Control_DW.is_active_c4_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c4_Robot_Control = 1U;
    Robot_Control_DW.is_c4_Robot_Control = Robot_Contro_IN_Wait_for_Button;
    Robot_Control_B.RB_Des_Intake_Arm_Angle =
      Robot_Control_U.Measured_Intake_Arm_Angle;
  } else {
    switch (Robot_Control_DW.is_c4_Robot_Control) {
     case Robot_Con_IN_Move_Intake_Arm_In:
      if (rtb_Intake_Arm_Move_Out || (rtb_Intake_Arm_Cycle &&
           (Robot_Control_U.Measured_Intake_Arm_Angle <
            Rebuilt_Intake_Cycle_Angle_In))) {
        Robot_Control_DW.is_c4_Robot_Control = Robot_Co_IN_Move_Intake_Arm_Out;
        Robot_Control_B.RB_Des_Intake_Arm_Angle = Rebuilt_Intake_Des_Angle_Out;
      }
      break;

     case Robot_Co_IN_Move_Intake_Arm_Out:
      if ((rtb_Intake_Arm_Move_In || (rtb_Intake_Arm_Cycle &&
            (Robot_Control_U.Measured_Intake_Arm_Angle >
             Rebuilt_Intake_Cycle_Angle_Out))) || (((int32_T)
            rtb_Intake_Arm_Cycle) < ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_c))) {
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

  /* Switch: '<S40>/Init' incorporates:
   *  UnitDelay: '<S40>/FixPt Unit Delay1'
   *  UnitDelay: '<S40>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_b != 0) {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle;
  } else {
    rtb_Init = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL;
  }

  /* End of Switch: '<S40>/Init' */

  /* Sum: '<S38>/Sum1' */
  rtb_Switch2_nf = Robot_Control_B.RB_Des_Intake_Arm_Angle - rtb_Init;

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S31>/Constant3'
   *  RelationalOperator: '<S39>/LowerRelop1'
   *  RelationalOperator: '<S39>/UpperRelop'
   *  Switch: '<S39>/Switch'
   */
  if (rtb_Switch2_nf > Rebuilt_Intake_RL_Inc) {
    rtb_Switch2_nf = Rebuilt_Intake_RL_Inc;
  } else if (rtb_Switch2_nf < Rebuilt_Intake_RL_Dec) {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S31>/Constant1'
     */
    rtb_Switch2_nf = Rebuilt_Intake_RL_Dec;
  }

  /* End of Switch: '<S39>/Switch2' */

  /* Sum: '<S38>/Sum' */
  Robot_Control_B.RB_Des_Intake_Arm_Angle_RL = rtb_Switch2_nf + rtb_Init;

  /* Logic: '<S30>/Logical Operator1' incorporates:
   *  Constant: '<S33>/Constant'
   *  RelationalOperator: '<S33>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Des_Intake_Arm_Angle_RL == 0.0);

  /* Sum: '<S34>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Sum: '<S30>/Subtract'
   */
  rtb_Error_e = Robot_Control_B.RB_Des_Intake_Arm_Angle_RL -
    Robot_Control_U.Measured_Intake_Arm_Angle;

  /* Sum: '<S36>/Sum1' incorporates:
   *  Constant: '<S34>/Constant2'
   *  Product: '<S36>/Product'
   *  Sum: '<S34>/Sum'
   *  Sum: '<S36>/Sum'
   *  UnitDelay: '<S36>/Unit Delay1'
   */
  rtb_Switch2_nf = ((rtb_Error_e - Robot_Control_DW.UnitDelay1_DSTATE_l) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_l;

  /* Product: '<S34>/Product' incorporates:
   *  Constant: '<S34>/Constant3'
   */
  rtb_Product_di = rtb_Switch2_nf * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S35>/Diff' incorporates:
   *  UnitDelay: '<S35>/UD'
   *
   * Block description for '<S35>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S35>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_di - Robot_Control_DW.UD_DSTATE_d;

  /* Saturate: '<S34>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S34>/Add' incorporates:
   *  Gain: '<S34>/Gain'
   *  Gain: '<S34>/Gain1'
   *  Saturate: '<S34>/Saturation'
   *  Sum: '<S34>/Sum'
   */
  rtb_Init = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle_RL) +
              (Rebuilt_Intake_Arm_Gain_P * rtb_Error_e)) + rtb_Add_oy;

  /* Switch: '<S30>/Switch1' incorporates:
   *  Abs: '<S30>/Abs'
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant2'
   *  Logic: '<S30>/Logical Operator'
   *  Logic: '<S30>/Logical Operator1'
   *  RelationalOperator: '<S30>/LessThan'
   *  UnitDelay: '<S30>/Unit Delay'
   */
  if ((fabs(rtb_Error_e) < Rebuilt_Intake_Arm_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_In = true;
  } else {
    rtb_Intake_Arm_Move_In = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_dvn));
  }

  /* End of Switch: '<S30>/Switch1' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Constant4'
   */
  if (rtb_Intake_Arm_Move_In) {
    /* Sum: '<S34>/Sum2' incorporates:
     *  Gain: '<S34>/Gain2'
     *  Sum: '<S34>/Sum'
     *  UnitDelay: '<S34>/Unit Delay'
     */
    rtb_Error_e = (Rebuilt_Intake_Arm_Gain_I * rtb_Error_e) +
      Robot_Control_DW.UnitDelay_DSTATE_ej;

    /* Sum: '<S34>/Subtract' incorporates:
     *  Constant: '<S34>/Constant'
     */
    rtb_Switch2_p0 = 1.0 - rtb_Init;

    /* Switch: '<S37>/Switch2' incorporates:
     *  Constant: '<S34>/Constant'
     *  RelationalOperator: '<S37>/LowerRelop1'
     *  Sum: '<S34>/Subtract'
     */
    if (!(rtb_Error_e > (1.0 - rtb_Init))) {
      /* Sum: '<S34>/Subtract1' incorporates:
       *  Constant: '<S34>/Constant1'
       */
      rtb_Switch2_p0 = -1.0 - rtb_Init;

      /* Switch: '<S37>/Switch' incorporates:
       *  Constant: '<S34>/Constant1'
       *  RelationalOperator: '<S37>/UpperRelop'
       *  Sum: '<S34>/Subtract1'
       */
      if (!(rtb_Error_e < (-1.0 - rtb_Init))) {
        rtb_Switch2_p0 = rtb_Error_e;
      }

      /* End of Switch: '<S37>/Switch' */
    }

    /* End of Switch: '<S37>/Switch2' */

    /* Saturate: '<S34>/Saturation1' */
    if (rtb_Switch2_p0 > 0.1) {
      rtb_Error_e = 0.1;
    } else if (rtb_Switch2_p0 < -0.1) {
      rtb_Error_e = -0.1;
    } else {
      rtb_Error_e = rtb_Switch2_p0;
    }

    /* End of Saturate: '<S34>/Saturation1' */
  } else {
    rtb_Error_e = 0.0;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Switch: '<S30>/Switch2' incorporates:
   *  Logic: '<S30>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S34>/Add1' */
    rtb_Add_oy = rtb_Init + rtb_Error_e;

    /* Saturate: '<S34>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S30>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S30>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S30>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S34>/Saturation2' */
  } else {
    /* Switch: '<S30>/Switch2' incorporates:
     *  Constant: '<S30>/Constant3'
     */
    Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S30>/Switch2' */

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

  /* Logic: '<S109>/Logical Operator1' incorporates:
   *  Constant: '<S145>/Constant'
   *  RelationalOperator: '<S145>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S146>/Sum' incorporates:
   *  Sum: '<S109>/Subtract'
   */
  rtb_Init = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S148>/Sum1' incorporates:
   *  Constant: '<S146>/Constant2'
   *  Product: '<S148>/Product'
   *  Sum: '<S146>/Sum'
   *  Sum: '<S148>/Sum'
   *  UnitDelay: '<S148>/Unit Delay1'
   */
  rtb_Switch2_p0 = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_in) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_in;

  /* Product: '<S146>/Product' incorporates:
   *  Constant: '<S146>/Constant3'
   */
  rtb_Product_i = rtb_Switch2_p0 * 0.0;

  /* Sum: '<S147>/Diff' incorporates:
   *  UnitDelay: '<S147>/UD'
   *
   * Block description for '<S147>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S147>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_oy = rtb_Product_i - Robot_Control_DW.UD_DSTATE_kz;

  /* Saturate: '<S146>/Saturation' */
  if (rtb_Add_oy > 0.1) {
    rtb_Add_oy = 0.1;
  } else if (rtb_Add_oy < -0.1) {
    rtb_Add_oy = -0.1;
  }

  /* Sum: '<S146>/Add' incorporates:
   *  Gain: '<S146>/Gain'
   *  Gain: '<S146>/Gain1'
   *  Saturate: '<S146>/Saturation'
   *  Sum: '<S146>/Sum'
   */
  rtb_Add_oy += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Init);

  /* Switch: '<S109>/Switch4' incorporates:
   *  Constant: '<S109>/Constant6'
   *  Constant: '<S109>/Constant7'
   *  Logic: '<S109>/Logical Operator1'
   *  Logic: '<S109>/Logical Operator2'
   *  RelationalOperator: '<S109>/LessThan2'
   *  UnitDelay: '<S109>/Unit Delay1'
   */
  if ((rtb_Init < 0.0) && rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay1_DSTATE_ea));
  }

  /* End of Switch: '<S109>/Switch4' */

  /* Switch: '<S109>/Switch1' incorporates:
   *  Constant: '<S109>/Constant1'
   *  Constant: '<S109>/Constant2'
   *  Logic: '<S109>/Logical Operator'
   *  Logic: '<S109>/Logical Operator1'
   *  RelationalOperator: '<S109>/LessThan'
   *  UnitDelay: '<S109>/Unit Delay'
   */
  if ((rtb_Init < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Is_Absolute_Translation_g = true;
  } else {
    rtb_Is_Absolute_Translation_g = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S109>/Switch1' */

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S146>/Constant4'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* Sum: '<S146>/Sum2' incorporates:
     *  Gain: '<S146>/Gain2'
     *  Product: '<S146>/Product1'
     *  Sum: '<S146>/Sum'
     *  Switch: '<S146>/Switch1'
     *  UnitDelay: '<S146>/Unit Delay'
     */
    rtb_Init = ((Rebuilt_Shooter_Motor_Gain_I * rtb_Init) * ((real_T)
      (!rtb_Intake_Arm_Move_Out))) + Robot_Control_DW.UnitDelay_DSTATE_l1;

    /* Sum: '<S146>/Subtract' incorporates:
     *  Constant: '<S146>/Constant'
     */
    rtb_Error_h = 1.0 - rtb_Add_oy;

    /* Switch: '<S149>/Switch2' incorporates:
     *  Constant: '<S146>/Constant'
     *  RelationalOperator: '<S149>/LowerRelop1'
     *  Sum: '<S146>/Subtract'
     */
    if (!(rtb_Init > (1.0 - rtb_Add_oy))) {
      /* Sum: '<S146>/Subtract1' incorporates:
       *  Constant: '<S146>/Constant1'
       */
      rtb_Error_h = -1.0 - rtb_Add_oy;

      /* Switch: '<S149>/Switch' incorporates:
       *  Constant: '<S146>/Constant1'
       *  RelationalOperator: '<S149>/UpperRelop'
       *  Sum: '<S146>/Subtract1'
       */
      if (!(rtb_Init < (-1.0 - rtb_Add_oy))) {
        rtb_Error_h = rtb_Init;
      }

      /* End of Switch: '<S149>/Switch' */
    }

    /* End of Switch: '<S149>/Switch2' */

    /* Saturate: '<S146>/Saturation1' */
    if (rtb_Error_h > 0.1) {
      rtb_Init = 0.1;
    } else if (rtb_Error_h < -0.1) {
      rtb_Init = -0.1;
    } else {
      rtb_Init = rtb_Error_h;
    }

    /* End of Saturate: '<S146>/Saturation1' */
  } else {
    rtb_Init = 0.0;
  }

  /* End of Switch: '<S146>/Switch' */

  /* Switch: '<S109>/Switch2' incorporates:
   *  Logic: '<S109>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S146>/Add1' */
    rtb_Add_oy += rtb_Init;

    /* Saturate: '<S146>/Saturation2' */
    if (rtb_Add_oy > 1.0) {
      /* Switch: '<S109>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_oy < -1.0) {
      /* Switch: '<S109>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S109>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_oy;
    }

    /* End of Saturate: '<S146>/Saturation2' */
  } else {
    /* Switch: '<S109>/Switch2' incorporates:
     *  Constant: '<S109>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S109>/Switch2' */

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
  Robot_Control_Y.Swerve_Motors_Disabled = rtb_Swerve_Motors_Disabled;

  /* Outport: '<Root>/Vision_Desired_Pipeline' */
  Robot_Control_Y.Vision_Desired_Pipeline = rtb_Desired_Pipeline;

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

  /* Update for UnitDelay: '<S25>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Joystick_Left_B11;

  /* Update for UnitDelay: '<S26>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *
   * Block description for '<S26>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Joystick_Left_B12;

  /* Update for UnitDelay: '<S27>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *
   * Block description for '<S27>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Joystick_Left_B13;

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

  /* Update for Delay: '<S46>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S66>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S46>/A'
   *  Delay: '<S46>/MemoryX'
   */
  rtb_Add_oy = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Error_h = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S46>/MemoryX' incorporates:
   *  Constant: '<S46>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S66>/A[k]*xhat[k|k-1]'
   *  Product: '<S66>/B[k]*u[k]'
   *  Sum: '<S66>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Add_oy) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Error_h) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S316>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S316>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

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

  /* Update for UnitDelay: '<S105>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S338>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_LookupTableDynamic_b;

  /* Update for UnitDelay: '<S337>/UD'
   *
   * Block description for '<S337>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S335>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Add_h5;

  /* Update for UnitDelay: '<S318>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Init_o;

  /* Update for UnitDelay: '<S333>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S333>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S333>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S317>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S326>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S326>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S326>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S292>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_DeadZone;

  /* Update for UnitDelay: '<S291>/UD'
   *
   * Block description for '<S291>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S285>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S229>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S228>/UD'
   *
   * Block description for '<S228>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Switch2;

  /* Update for UnitDelay: '<S222>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S240>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S239>/UD'
   *
   * Block description for '<S239>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_ow;

  /* Update for UnitDelay: '<S225>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S250>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S249>/UD'
   *
   * Block description for '<S249>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S243>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S261>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_bl;

  /* Update for UnitDelay: '<S260>/UD'
   *
   * Block description for '<S260>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_cw;

  /* Update for UnitDelay: '<S246>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S271>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S270>/UD'
   *
   * Block description for '<S270>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S264>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S282>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S281>/UD'
   *
   * Block description for '<S281>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S267>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S303>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S302>/UD'
   *
   * Block description for '<S302>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add_f1;

  /* Update for UnitDelay: '<S288>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S153>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_fd;

  /* Update for UnitDelay: '<S152>/UD'
   *
   * Block description for '<S152>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S151>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S111>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Compare_a;

  /* Update for UnitDelay: '<S103>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S103>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S44>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Sum1_fh;

  /* Update for UnitDelay: '<S43>/UD'
   *
   * Block description for '<S43>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_hm;

  /* Update for UnitDelay: '<S42>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Error_n;

  /* Update for UnitDelay: '<S32>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_AND1_c;

  /* Update for UnitDelay: '<S29>/Delay Input1'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S40>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S40>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 0U;

  /* Update for UnitDelay: '<S36>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch2_nf;

  /* Update for UnitDelay: '<S35>/UD'
   *
   * Block description for '<S35>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_d = rtb_Product_di;

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ej = rtb_Error_e;

  /* Update for UnitDelay: '<S30>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dvn = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S148>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_in = rtb_Switch2_p0;

  /* Update for UnitDelay: '<S147>/UD'
   *
   * Block description for '<S147>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_kz = rtb_Product_i;

  /* Update for UnitDelay: '<S109>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ea = rtb_Intake_Arm_Move_Out;

  /* Update for UnitDelay: '<S146>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l1 = rtb_Init;

  /* Update for UnitDelay: '<S109>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_db = rtb_Is_Absolute_Translation_g;
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

  /* InitializeConditions for Delay: '<S46>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S316>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S333>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S326>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S103>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* InitializeConditions for UnitDelay: '<S40>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_b = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S391>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S161>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S157>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S161>/Robot_Index_Is_Valid' */
  /* Start for If: '<S164>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S164>/Circle_Check_Valid' */
  /* Start for If: '<S166>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S164>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S161>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S13>/Spline Path Following Enabled' */
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
