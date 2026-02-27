/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.457
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 26 22:51:08 2026
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
                                      * Referenced by: '<S382>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S378>/Constant'
                                        *   '<S378>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S382>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S378>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S216>/Constant3'
                                        *   '<S237>/Constant3'
                                        *   '<S258>/Constant3'
                                        *   '<S279>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S216>/Constant2'
                                   *   '<S237>/Constant2'
                                   *   '<S258>/Constant2'
                                   *   '<S279>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S216>/Saturation'
                                        *   '<S237>/Saturation'
                                        *   '<S258>/Saturation'
                                        *   '<S279>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S216>/Saturation'
                                        *   '<S237>/Saturation'
                                        *   '<S258>/Saturation'
                                        *   '<S279>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S216>/Gain'
                                            *   '<S237>/Gain'
                                            *   '<S258>/Gain'
                                            *   '<S279>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S216>/Gain2'
                                        *   '<S237>/Gain2'
                                        *   '<S258>/Gain2'
                                        *   '<S279>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S216>/Saturation1'
                                         *   '<S237>/Saturation1'
                                         *   '<S258>/Saturation1'
                                         *   '<S279>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S216>/Saturation1'
                                        *   '<S237>/Saturation1'
                                        *   '<S258>/Saturation1'
                                        *   '<S279>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S216>/Gain1'
                                        *   '<S237>/Gain1'
                                        *   '<S258>/Gain1'
                                        *   '<S279>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S221>/Constant'
                            *   '<S242>/Constant'
                            *   '<S263>/Constant'
                            *   '<S284>/Constant'
                            */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S135>/BlueAllianceZoneX'
                                         *   '<S137>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S116>/Constant'
                                        */
real_T Field_Blue_Hub_Y = 4.0345;      /* Variable: Field_Blue_Hub_Y
                                        * Referenced by: '<S116>/Constant1'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S136>/RedAllianceZoneX'
                                         *   '<S138>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S116>/Constant2'
                                        */
real_T Field_Red_Hub_Y = 4.0345;       /* Variable: Field_Red_Hub_Y
                                        * Referenced by: '<S116>/Constant3'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S368>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S368>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = -1.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S111>/Constant'
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
                                   * Referenced by: '<S96>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S96>/Constant3'
                                   */
real_T Rebuilt_Intake_Arm_Gain_D = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                        * Referenced by: '<S33>/Constant3'
                                        */
real_T Rebuilt_Intake_Arm_Gain_I = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_I
                                        * Referenced by: '<S33>/Gain2'
                                        */
real_T Rebuilt_Intake_Arm_Gain_P = 0.0;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                        * Referenced by: '<S33>/Gain1'
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
real_T Rebuilt_Roller_Desired_Speed = 0.0;/* Variable: Rebuilt_Roller_Desired_Speed
                                           * Referenced by: '<S6>/Constant'
                                           */
real_T Rebuilt_Roller_Error_Integral_Enable = 0.0;
                               /* Variable: Rebuilt_Roller_Error_Integral_Enable
                                * Referenced by: '<S31>/Constant1'
                                */
real_T Rebuilt_Roller_Motor_Gain_FF = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                           * Referenced by: '<S38>/Gain'
                                           */
real_T Rebuilt_Roller_Motor_Gain_I = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                          * Referenced by: '<S38>/Gain2'
                                          */
real_T Rebuilt_Roller_Motor_Gain_P = 0.0;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                          * Referenced by: '<S38>/Gain1'
                                          */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S117>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S117>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S117>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S117>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S117>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S117>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S117>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 6.5;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S117>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S113>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S113>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S113>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S113>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S113>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S113>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S113>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S113>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S114>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S114>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S114>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S114>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S114>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S114>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S114>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 0.62;/* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S114>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S104>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S104>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.0;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S104>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S115>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2800.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S115>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3100.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S115>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3200.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S115>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3400.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S115>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3550.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S115>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3800.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S115>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4000.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S115>/Constant1'
                                             */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S120>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S120>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S120>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S120>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S120>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S120>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S120>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S120>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S124>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S105>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S140>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S140>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.0005;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                              * Referenced by: '<S140>/Gain1'
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
                              * Referenced by: '<S107>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S145>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S145>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S145>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S367>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S365>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S367>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S368>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S368>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S205>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S205>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S152>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S165>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S205>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S312>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S312>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S312>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S312>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S312>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S312>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S329>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S329>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S329>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S329>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S328>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S329>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S329>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S329>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S329>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S329>/Constant1'
                                   *   '<S329>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S329>/Constant'
                                   *   '<S329>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S219>/Constant3'
                                        *   '<S240>/Constant3'
                                        *   '<S261>/Constant3'
                                        *   '<S282>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S219>/Constant2'
                                *   '<S240>/Constant2'
                                *   '<S261>/Constant2'
                                *   '<S282>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S219>/Saturation'
                                           *   '<S240>/Saturation'
                                           *   '<S261>/Saturation'
                                           *   '<S282>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S219>/Saturation'
                                          *   '<S240>/Saturation'
                                          *   '<S261>/Saturation'
                                          *   '<S282>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S219>/Gain2'
                                         *   '<S240>/Gain2'
                                         *   '<S261>/Gain2'
                                         *   '<S282>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S219>/Saturation1'
                                             *   '<S240>/Saturation1'
                                             *   '<S261>/Saturation1'
                                             *   '<S282>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S219>/Saturation1'
                                            *   '<S240>/Saturation1'
                                            *   '<S261>/Saturation1'
                                            *   '<S282>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S219>/Gain1'
                                        *   '<S240>/Gain1'
                                        *   '<S261>/Gain1'
                                        *   '<S282>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S311>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S311>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S311>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S311>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S311>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S311>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S367>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S367>/Constant1'
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
                                      * Referenced by: '<S366>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S366>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S366>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S299>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S299>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S299>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S299>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S299>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S299>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S368>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S367>/Dead Zone'
                                        *   '<S368>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S367>/Dead Zone'
                                        *   '<S368>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S17>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S365>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S365>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S365>/Constant4'
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
                                        * Referenced by: '<S365>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S365>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S365>/Constant5'
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
                                        *   '<S365>/Constant11'
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
 *    '<S102>/If Action Subsystem'
 *    '<S102>/If Action Subsystem5'
 */
void Robot_Control_IfActionSubsystem(boolean_T *rty_IsBlueActive, boolean_T
  *rty_IsRedActive)
{
  /* SignalConversion generated from: '<S126>/IsBlueActive' incorporates:
   *  Constant: '<S126>/Constant'
   */
  *rty_IsBlueActive = true;

  /* SignalConversion generated from: '<S126>/IsRedActive' incorporates:
   *  Constant: '<S126>/Constant'
   */
  *rty_IsRedActive = true;
}

/*
 * Output and update for action system:
 *    '<S102>/If Action Subsystem1'
 *    '<S102>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive)
{
  /* Logic: '<S127>/NOT' incorporates:
   *  SignalConversion generated from: '<S127>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S127>/IsRedActive' */
  *rty_IsRedActive = rtu_IsBlueInactiveFirst;
}

/*
 * Output and update for action system:
 *    '<S102>/If Action Subsystem2'
 *    '<S102>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive)
{
  /* Logic: '<S128>/NOT1' incorporates:
   *  SignalConversion generated from: '<S128>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S128>/IsBlueActive' */
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
  real_T rtb_TOF_g[8];
  real_T rtb_TmpSignalConversionAtLoo_d0[8];
  real_T rtb_TmpSignalConversionAtLoo_o3[8];
  real_T rtb_TmpSignalConversionAtLook_f[8];
  real_T rtb_TmpSignalConversionAtLook_o[8];
  real_T rtb_Minus_n[2];
  real_T rtb_Reshapey[2];
  real_T rtb_Add2_idx_0;
  real_T rtb_Add2_idx_1;
  real_T rtb_Add_ec;
  real_T rtb_Add_fn;
  real_T rtb_Add_h5;
  real_T rtb_Add_i;
  real_T rtb_Add_is;
  real_T rtb_Add_jp;
  real_T rtb_Add_k;
  real_T rtb_Derivative;
  real_T rtb_Error_b;
  real_T rtb_Error_e;
  real_T rtb_Error_n;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Init;
  real_T rtb_Init_o;
  real_T rtb_Integral_bj;
  real_T rtb_Integral_d;
  real_T rtb_Integral_ga;
  real_T rtb_Merge1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_lu;
  real_T rtb_Product_m5;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_la;
  real_T rtb_Sum2_e;
  real_T rtb_Sum2_oc;
  real_T rtb_Switch1;
  real_T rtb_Switch2;
  real_T rtb_Switch2_dp;
  real_T rtb_Switch2_ku;
  real_T rtb_Switch2_m;
  real_T rtb_Switch2_ox;
  real_T rtb_Switch2_p2;
  real_T rtb_Switch4;
  real_T rtb_Switch4_e;
  real_T rtb_uDLookupTable;
  real_T *rtb_TmpSignalConversionAtLoo__0;
  int32_T i;
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T rtb_Button_Shoot_Enable;
  uint8_T rtb_Button_Spinup_Enable;
  uint8_T rtb_Desired_Pipeline;
  uint8_T rtb_GameState;
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

  /* If: '<S394>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S394>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S397>/Action Port'
     */
    /* Product: '<S397>/Product' incorporates:
     *  Constant: '<S397>/Constant1'
     *  Constant: '<S397>/Constant2'
     *  Math: '<S397>/Math Function'
     */
    rtb_Init_o = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495)
      * 111.0;

    /* End of Outputs for SubSystem: '<S394>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S394>/Subsystem' incorporates:
     *  ActionPort: '<S398>/Action Port'
     */
    /* SignalConversion generated from: '<S398>/Out1' incorporates:
     *  Constant: '<S398>/Constant'
     */
    rtb_Init_o = 0.0;

    /* End of Outputs for SubSystem: '<S394>/Subsystem' */
  }

  /* End of If: '<S394>/If' */

  /* Gain: '<S395>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S17>/Add3' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Fcn: '<S396>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Init_o * cos(rtb_Sin4)) +
    Vision_Object_X_Offset;

  /* Sum: '<S17>/Add4' incorporates:
   *  Constant: '<S17>/Constant8'
   *  Fcn: '<S396>/theta->y'
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
  rtb_Add_i = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_i)) || (rtIsInf(rtb_Add_i))) {
    rtb_Add_i = 0.0;
  } else {
    rtb_Add_i = fmod(rtb_Add_i, 4.294967296E+9);
  }

  switch ((rtb_Add_i < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_i)))) : ((int32_T)
           ((uint32_T)rtb_Add_i))) {
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
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S9>/Merge3' incorporates:
     *  Constant: '<S18>/Constant3'
     *  SignalConversion generated from: '<S2>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S9>/Merge9' incorporates:
     *  Constant: '<S18>/Constant9'
     *  SignalConversion generated from: '<S2>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

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
       *  UnitDelay: '<S367>/Unit Delay1'
       *  UnitDelay: '<S367>/Unit Delay2'
       *  UnitDelay: '<S367>/Unit Delay3'
       *  UnitDelay: '<S367>/Unit Delay4'
       *  UnitDelay: '<S370>/Delay Input1'
       *  UnitDelay: '<S371>/Delay Input1'
       *  UnitDelay: '<S372>/Delay Input1'
       *  UnitDelay: '<S373>/Delay Input1'
       *  UnitDelay: '<S375>/Delay Input1'
       *  UnitDelay: '<S381>/Unit Delay'
       *  UnitDelay: '<S381>/Unit Delay1'
       *  UnitDelay: '<S385>/FixPt Unit Delay1'
       *  UnitDelay: '<S385>/FixPt Unit Delay2'
       *
       * Block description for '<S370>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S371>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S372>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S373>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S375>/Delay Input1':
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
    /* Switch: '<S365>/Switch4' incorporates:
     *  Constant: '<S390>/Constant'
     *  Constant: '<S393>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S390>/Compare'
     *  RelationalOperator: '<S393>/Compare'
     *  Switch: '<S365>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S365>/Switch4' incorporates:
       *  Constant: '<S365>/Constant8'
       *  Sum: '<S365>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S365>/Switch5' incorporates:
       *  Constant: '<S365>/Constant7'
       *  Gain: '<S365>/Gain'
       *  Sum: '<S365>/Subtract5'
       *  Switch: '<S365>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S365>/Switch4' incorporates:
       *  Constant: '<S365>/Constant6'
       *  Switch: '<S365>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S365>/Switch4' */

    /* Logic: '<S365>/Logical Operator1' incorporates:
     *  Constant: '<S15>/Constant12'
     *  Logic: '<S365>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S367>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_i = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_i = 0.0;
    } else {
      rtb_Add_i = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S367>/Add' incorporates:
     *  Constant: '<S367>/Constant'
     *  Constant: '<S367>/Constant1'
     *  DeadZone: '<S367>/Dead Zone'
     *  Lookup_n-D: '<S367>/Modulation_Str_Y_Rel'
     *  Product: '<S367>/Product'
     *  Product: '<S367>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Add_h5 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                  Steering_Relative_Gain) + (rtb_Add_i * Steering_Twist_Gain);

    /* RelationalOperator: '<S369>/Compare' incorporates:
     *  Constant: '<S369>/Constant'
     */
    rtb_Compare_a = (rtb_Add_h5 == 0.0);

    /* Logic: '<S367>/AND2' incorporates:
     *  RelationalOperator: '<S370>/FixPt Relational Operator'
     *  RelationalOperator: '<S371>/FixPt Relational Operator'
     *  RelationalOperator: '<S372>/FixPt Relational Operator'
     *  RelationalOperator: '<S373>/FixPt Relational Operator'
     *  UnitDelay: '<S370>/Delay Input1'
     *  UnitDelay: '<S371>/Delay Input1'
     *  UnitDelay: '<S372>/Delay Input1'
     *  UnitDelay: '<S373>/Delay Input1'
     *
     * Block description for '<S370>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S371>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S372>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S373>/Delay Input1':
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

    /* Logic: '<S367>/AND1' incorporates:
     *  Logic: '<S367>/AND3'
     *  UnitDelay: '<S367>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_a && (rtb_Intake_Arm_Cycle ||
      (Robot_Control_DW.UnitDelay2_DSTATE)));

    /* Logic: '<S367>/AND4' incorporates:
     *  Logic: '<S367>/AND8'
     *  UnitDelay: '<S367>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_a && (!rtb_Intake_Arm_Cycle)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S367>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S367>/Switch8' incorporates:
     *  Constant: '<S376>/Constant'
     *  Logic: '<S367>/AND9'
     *  RelationalOperator: '<S375>/FixPt Relational Operator'
     *  RelationalOperator: '<S376>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S375>/Delay Input1'
     *
     * Block description for '<S375>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)rtb_Compare_a)
          > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j))) ||
        (Robot_Control_B.Active_GameState != 2)) {
      /* Switch: '<S367>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S367>/Switch8' incorporates:
       *  UnitDelay: '<S367>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S367>/Switch8' */

    /* Switch: '<S367>/Switch4' incorporates:
     *  Constant: '<S367>/Constant5'
     *  Switch: '<S367>/Switch1'
     *  Switch: '<S367>/Switch5'
     *  Switch: '<S367>/Switch6'
     *  Switch: '<S367>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Switch4 = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S367>/Switch5' incorporates:
       *  Constant: '<S367>/Constant6'
       */
      rtb_Switch4 = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S367>/Switch6' incorporates:
       *  Constant: '<S367>/Constant7'
       *  Switch: '<S367>/Switch5'
       */
      rtb_Switch4 = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S367>/Switch7' incorporates:
       *  Constant: '<S367>/Constant8'
       *  Switch: '<S367>/Switch5'
       *  Switch: '<S367>/Switch6'
       */
      rtb_Switch4 = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S367>/Switch1' incorporates:
       *  Constant: '<S15>/Constant10'
       *  Switch: '<S367>/Switch5'
       *  Switch: '<S367>/Switch6'
       *  Switch: '<S367>/Switch7'
       */
      rtb_Switch4 = 0.0;
    } else {
      /* Switch: '<S367>/Switch6' incorporates:
       *  Switch: '<S367>/Switch5'
       *  Switch: '<S367>/Switch7'
       *  UnitDelay: '<S367>/Unit Delay1'
       */
      rtb_Switch4 = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S367>/Switch4' */

    /* Switch: '<S367>/Switch2' incorporates:
     *  Switch: '<S367>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S367>/Switch2' incorporates:
       *  Constant: '<S367>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S367>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Switch4;
    } else {
      /* Switch: '<S367>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S367>/Switch3' incorporates:
       *  Constant: '<S367>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S367>/Switch2' */

    /* Merge: '<S9>/Merge1' incorporates:
     *  Sum: '<S367>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S366>/Switch1' incorporates:
     *  Constant: '<S366>/Constant5'
     *  Constant: '<S366>/Constant8'
     *  DataTypeConversion: '<S366>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_a;
    }

    /* End of Switch: '<S366>/Switch1' */

    /* Lookup_n-D: '<S368>/Modulation_Drv' incorporates:
     *  Math: '<S368>/Magnitude'
     */
    rtb_Init_o = look1_binlcpw(rt_hypotd_snf(Robot_Control_B.Drive_Joystick_X,
      Robot_Control_B.Drive_Joystick_Y), rtCP_Modulation_Drv_bp01Data,
      rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S379>/Compare' incorporates:
     *  Constant: '<S379>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Init_o == 0.0);

    /* DeadZone: '<S368>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S368>/Dead Zone' */

    /* Logic: '<S368>/Logical Operator' incorporates:
     *  Constant: '<S380>/Constant'
     *  RelationalOperator: '<S380>/Compare'
     */
    rtb_Intake_Arm_Cycle = ((rtb_Sin4 != 0.0) && rtb_Swerve_Motors_Disabled);

    /* Switch: '<S366>/Switch' incorporates:
     *  Constant: '<S366>/Constant5'
     *  Constant: '<S366>/Constant7'
     *  DataTypeConversion: '<S366>/Data Type Conversion'
     *  Logic: '<S368>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Intake_Arm_Cycle;
    }

    /* End of Switch: '<S366>/Switch' */

    /* Switch: '<S365>/Switch2' incorporates:
     *  Constant: '<S365>/Constant2'
     *  Constant: '<S389>/Constant'
     *  Constant: '<S392>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S389>/Compare'
     *  RelationalOperator: '<S392>/Compare'
     *  Sum: '<S365>/Subtract'
     *  Switch: '<S365>/Switch'
     *  Switch: '<S365>/Switch1'
     *  Switch: '<S365>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S365>/Switch2' incorporates:
       *  Constant: '<S365>/Constant5'
       *  Sum: '<S365>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S365>/Switch2' incorporates:
       *  Constant: '<S365>/Constant4'
       *  Sum: '<S365>/Subtract2'
       *  Switch: '<S365>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S365>/Switch1' incorporates:
       *  Constant: '<S365>/Constant1'
       *  Sum: '<S365>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S365>/Switch2' incorporates:
       *  Constant: '<S365>/Constant3'
       *  Switch: '<S365>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S365>/Switch1' incorporates:
       *  Constant: '<S365>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S365>/Switch2' */

    /* UnaryMinus: '<S365>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S381>/Switch1' incorporates:
     *  Constant: '<S386>/Constant'
     *  Constant: '<S387>/Constant'
     *  Logic: '<S381>/AND'
     *  RelationalOperator: '<S386>/Compare'
     *  RelationalOperator: '<S387>/Compare'
     *  Switch: '<S381>/Switch2'
     *  UnitDelay: '<S381>/Unit Delay'
     *  UnitDelay: '<S381>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_lw;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S381>/Switch1' */

    /* Switch: '<S368>/Switch1' incorporates:
     *  Logic: '<S368>/Logical Operator1'
     *  Switch: '<S368>/Switch4'
     *  Switch: '<S368>/Switch9'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Signum: '<S368>/Sign' */
      if (rtIsNaN(rtb_Sin4)) {
        rtb_Add_i = (rtNaN);
      } else if (rtb_Sin4 < 0.0) {
        rtb_Add_i = -1.0;
      } else {
        rtb_Add_i = (rtb_Sin4 > 0.0);
      }

      /* Switch: '<S368>/Switch5' incorporates:
       *  Constant: '<S368>/Constant3'
       *  Constant: '<S368>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_k = -1.5707963267948966;
      } else {
        rtb_Add_k = 0.0;
      }

      /* Merge: '<S9>/Merge3' incorporates:
       *  Gain: '<S368>/Gain3'
       *  Signum: '<S368>/Sign'
       *  Sum: '<S368>/Add'
       *  Switch: '<S368>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_i) +
        rtb_Add_k;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Switch: '<S368>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S368>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S368>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S9>/Merge3' incorporates:
         *  Constant: '<S368>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S368>/Switch6' */
    } else {
      /* Merge: '<S9>/Merge3' incorporates:
       *  Switch: '<S368>/Switch4'
       *  Trigonometry: '<S368>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S368>/Switch1' */

    /* Switch: '<S378>/Switch1' incorporates:
     *  Constant: '<S378>/Constant'
     *  Constant: '<S378>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S378>/Switch1' */

    /* Switch: '<S385>/Init' incorporates:
     *  UnitDelay: '<S385>/FixPt Unit Delay1'
     *  UnitDelay: '<S385>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S385>/Init' */

    /* Sum: '<S383>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S384>/Switch2' incorporates:
     *  Constant: '<S382>/Constant1'
     *  Constant: '<S382>/Constant3'
     *  RelationalOperator: '<S384>/LowerRelop1'
     *  RelationalOperator: '<S384>/UpperRelop'
     *  Switch: '<S384>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S384>/Switch' incorporates:
       *  Constant: '<S382>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S384>/Switch2' */

    /* Sum: '<S383>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S368>/Switch8' incorporates:
     *  Logic: '<S368>/Logical Operator1'
     *  Switch: '<S368>/Switch2'
     */
    if (rtb_Intake_Arm_Cycle) {
      /* Switch: '<S368>/Switch' incorporates:
       *  Gain: '<S368>/Gain'
       *  Merge: '<S9>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Sin4;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S9>/Merge4' incorporates:
       *  Constant: '<S15>/Constant7'
       *  Constant: '<S15>/Constant8'
       *  Constant: '<S368>/Constant5'
       *  Gain: '<S368>/Gain2'
       *  Math: '<S368>/Magnitude1'
       *  MinMax: '<S368>/Min'
       *  Switch: '<S368>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S378>/Product' incorporates:
       *  Switch: '<S368>/Switch2'
       */
      rtb_Add_i = rtb_Init_o * rtb_Init;

      /* Saturate: '<S378>/Saturation' incorporates:
       *  Switch: '<S368>/Switch2'
       */
      if (rtb_Add_i > Boost_Trigger_High_Speed) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_i < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S9>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_i;
      }

      /* End of Saturate: '<S378>/Saturation' */
    }

    /* End of Switch: '<S368>/Switch8' */

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion: '<S367>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Add_h5;

    /* Switch: '<S365>/Switch6' incorporates:
     *  Constant: '<S365>/Constant11'
     *  Switch: '<S365>/Switch7'
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
    rtb_Swerve_Motors_Disabled = false;

    /* RelationalOperator: '<S360>/Compare' incorporates:
     *  Constant: '<S360>/Constant'
     *  Inport: '<Root>/Gamepad_B1_A'
     */
    rtb_Intake_Arm_Move_In = (Robot_Control_U.Gamepad_B1_A != 0.0);

    /* RelationalOperator: '<S363>/Compare' incorporates:
     *  Constant: '<S363>/Constant'
     *  Inport: '<Root>/Gamepad_B4_Y'
     */
    rtb_Intake_Arm_Move_Out = (Robot_Control_U.Gamepad_B4_Y != 0.0);

    /* RelationalOperator: '<S362>/Compare' incorporates:
     *  Constant: '<S362>/Constant'
     *  Inport: '<Root>/Gamepad_B3_X'
     */
    rtb_Intake_Arm_Cycle = (Robot_Control_U.Gamepad_B3_X != 0.0);

    /* RelationalOperator: '<S361>/Compare' incorporates:
     *  Constant: '<S361>/Constant'
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

    /* Update for UnitDelay: '<S375>/Delay Input1'
     *
     * Block description for '<S375>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_a;

    /* Update for UnitDelay: '<S374>/Delay Input1' incorporates:
     *  Constant: '<S15>/Constant5'
     *
     * Block description for '<S374>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S370>/Delay Input1'
     *
     * Block description for '<S370>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S371>/Delay Input1'
     *
     * Block description for '<S371>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S372>/Delay Input1'
     *
     * Block description for '<S372>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S373>/Delay Input1'
     *
     * Block description for '<S373>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S367>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE = rtb_AND1_c;

    /* Update for UnitDelay: '<S367>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S367>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S367>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Switch4;

    /* Update for UnitDelay: '<S381>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_lw = rtb_Switch1;

    /* Update for UnitDelay: '<S381>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S385>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S385>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S385>/FixPt Unit Delay1' */
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

  /* Reshape: '<S42>/Reshapey' incorporates:
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

  /* Delay: '<S42>/MemoryX' incorporates:
   *  Constant: '<S42>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S69>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S95>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S62>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S93>/Enable'
   */
  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S93>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S42>/C'
     *  Delay: '<S42>/MemoryX'
     *  Product: '<S95>/Product'
     */
    rtb_Sin4 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Sin4;

    /* Sum: '<S93>/Sum' incorporates:
     *  Constant: '<S42>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S93>/C[k]*xhat[k|k-1]'
     *  Product: '<S93>/D[k]*u[k]'
     *  Sum: '<S93>/Add1'
     */
    rtb_Add_h5 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Init_o = rtb_Reshapey[0] - (rtb_Add_h5 + rtb_Sin4);

    /* Product: '<S93>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S42>/C'
     *  Delay: '<S42>/MemoryX'
     *  Product: '<S95>/Product'
     */
    rtb_Sin4 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Sin4;

    /* Sum: '<S93>/Sum' incorporates:
     *  Constant: '<S42>/D'
     *  Product: '<S93>/C[k]*xhat[k|k-1]'
     *  Product: '<S93>/D[k]*u[k]'
     *  Sum: '<S93>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Add_h5 + rtb_Sin4);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S93>/Product3' incorporates:
     *  Constant: '<S43>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Init_o) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S95>/Add1' incorporates:
     *  Product: '<S95>/Product'
     */
    rtb_Add_h5 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S93>/Product3' incorporates:
     *  Constant: '<S43>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Init_o) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S95>/Add1' incorporates:
     *  Product: '<S95>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S95>/Product2' incorporates:
     *  Constant: '<S43>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Add_h5) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Add_h5) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S93>/Product3' incorporates:
       *  Outport: '<S93>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S95>/Product2' incorporates:
       *  Outport: '<S95>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S8>/AND' */
  /* End of Outputs for SubSystem: '<S62>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S69>/Enabled Subsystem' */

  /* Sum: '<S69>/Add' incorporates:
   *  Delay: '<S42>/MemoryX'
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
   *  Constant: '<S149>/Constant'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Merge: '<S13>/Merge'
   *  Merge: '<S13>/Merge1'
   *  Merge: '<S13>/Merge2'
   *  Merge: '<S13>/Merge3'
   *  Merge: '<S13>/Merge4'
   *  Merge: '<S13>/Merge5'
   *  Merge: '<S13>/Merge7'
   *  Merge: '<S13>/Merge8'
   *  SignalConversion generated from: '<S149>/Robot_Reached_Destination'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  Robot_Control_DW.If_ActiveSubsystem = 1;
  if ((rtPrevAction != 1) && (rtPrevAction == 0)) {
    /* Disable for If: '<S155>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S158>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S160>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;

      /* End of Disable for If: '<S158>/If' */
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S155>/If' */
  }

  /* Outputs for IfAction SubSystem: '<S13>/Pass Through' incorporates:
   *  ActionPort: '<S149>/Action Port'
   */
  Robot_Control_B.Robot_Reached_Destination = true;
  Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;
  Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;
  Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;
  Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;
  Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;
  Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;
  Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

  /* End of If: '<S13>/If' */
  /* End of Outputs for SubSystem: '<S13>/Pass Through' */

  /* Signum: '<S299>/Sign2' incorporates:
   *  UnitDelay: '<S299>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S299>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S299>/Product1' incorporates:
   *  Signum: '<S299>/Sign1'
   *  Signum: '<S299>/Sign2'
   */
  rtb_Add_i *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_i)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_i, 256.0);
  }

  /* Switch: '<S299>/Switch' incorporates:
   *  Constant: '<S299>/Constant'
   *  Constant: '<S304>/Constant'
   *  Constant: '<S305>/Constant'
   *  Logic: '<S299>/or'
   *  Product: '<S299>/Product1'
   *  RelationalOperator: '<S304>/Compare'
   *  RelationalOperator: '<S305>/Compare'
   *  UnitDelay: '<S299>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S299>/Switch' */

  /* Switch: '<S310>/Init' incorporates:
   *  UnitDelay: '<S310>/FixPt Unit Delay1'
   *  UnitDelay: '<S310>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S310>/Init' */

  /* RelationalOperator: '<S306>/Compare' incorporates:
   *  Constant: '<S306>/Constant'
   */
  rtb_Compare_a = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S307>/Compare' incorporates:
   *  Constant: '<S307>/Constant'
   */
  rtb_AND1_c = (rtb_Sin4 > 0.0);

  /* Abs: '<S299>/Abs' incorporates:
   *  Sum: '<S299>/Subtract'
   *  UnitDelay: '<S299>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S299>/Switch5' incorporates:
   *  Constant: '<S299>/Constant1'
   *  Switch: '<S299>/Switch1'
   *  UnaryMinus: '<S299>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S299>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S299>/Constant4'
     *  Constant: '<S299>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S299>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S299>/Constant2'
     *  Constant: '<S299>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S299>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S299>/Lookup Table Dynamic'
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
    rtb_Add_i = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S299>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S299>/Constant10'
     *  Constant: '<S299>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S299>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S299>/Constant7'
     *  Constant: '<S299>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S299>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S299>/Lookup Table Dynamic1'
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

    /* Switch: '<S299>/Switch3' incorporates:
     *  Constant: '<S299>/Constant1'
     *  Constant: '<S299>/Constant3'
     *  UnaryMinus: '<S299>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_i = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_i = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S299>/Switch3' */
  }

  /* End of Switch: '<S299>/Switch5' */

  /* Product: '<S299>/Product' incorporates:
   *  Switch: '<S299>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_i * rtb_Merge1;

  /* Sum: '<S308>/Sum1' */
  rtb_Add_h5 = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S309>/Switch2' incorporates:
   *  RelationalOperator: '<S309>/LowerRelop1'
   */
  if (!(rtb_Add_h5 > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S299>/Switch2' incorporates:
     *  Constant: '<S299>/Constant1'
     *  Constant: '<S299>/Constant3'
     *  Switch: '<S299>/Switch4'
     *  UnaryMinus: '<S299>/Unary Minus1'
     */
    if (rtb_Compare_a) {
      rtb_Add_i = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S299>/Switch4' incorporates:
       *  Constant: '<S299>/Constant1'
       */
      rtb_Add_i = Translation_Speed_Rate_Limit_Dec;
    } else {
      rtb_Add_i = -Translation_Speed_Rate_Limit_Inc;
    }

    /* Product: '<S299>/Product2' incorporates:
     *  Switch: '<S299>/Switch2'
     */
    rtb_Switch4 = rtb_Add_i * rtb_Merge1;

    /* Switch: '<S309>/Switch' incorporates:
     *  RelationalOperator: '<S309>/UpperRelop'
     */
    if (rtb_Add_h5 < rtb_Switch4) {
      rtb_Optimized_Module_Angle = rtb_Switch4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Add_h5;
    }

    /* End of Switch: '<S309>/Switch' */
  }

  /* End of Switch: '<S309>/Switch2' */

  /* Sum: '<S308>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S302>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S302>/Switch' incorporates:
     *  Constant: '<S334>/Constant3'
     *  Constant: '<S334>/Constant4'
     *  Math: '<S334>/Math Function'
     *  Sum: '<S302>/Subtract'
     *  Sum: '<S334>/Add1'
     *  Sum: '<S334>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S302>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S302>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_i = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_i)) || (rtIsInf(rtb_Add_i))) {
    rtb_Add_i = 0.0;
  } else {
    rtb_Add_i = fmod(rtb_Add_i, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Add_i < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Add_i)))))) : ((int32_T)((uint8_T)rtb_Add_i)));

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* Sum: '<S102>/Subtract' incorporates:
   *  Constant: '<S102>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Merge1 = 140.0 - Robot_Control_U.MatchTime;

  /* If: '<S102>/If' incorporates:
   *  DataTypeConversion: '<S102>/Data Type Conversion'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   */
  if ((rtb_GameState == 1) || (rtb_Merge1 <= 10.0)) {
    /* Outputs for IfAction SubSystem: '<S102>/If Action Subsystem' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S102>/If Action Subsystem' */
  } else if (rtb_Merge1 <= 35.0) {
    /* Outputs for IfAction SubSystem: '<S102>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S102>/If Action Subsystem1' */
  } else if (rtb_Merge1 <= 60.0) {
    /* Outputs for IfAction SubSystem: '<S102>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S102>/If Action Subsystem2' */
  } else if (rtb_Merge1 <= 85.0) {
    /* Outputs for IfAction SubSystem: '<S102>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S102>/If Action Subsystem3' */
  } else if (rtb_Merge1 <= 110.0) {
    /* Outputs for IfAction SubSystem: '<S102>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S102>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S102>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S102>/If Action Subsystem5' */
  }

  /* End of If: '<S102>/If' */

  /* If: '<S133>/If' incorporates:
   *  If: '<S134>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S133>/Blue' incorporates:
     *  ActionPort: '<S135>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S135>/BlueAllianceZoneX'
     *  Logic: '<S135>/AND'
     *  RelationalOperator: '<S135>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S133>/Blue' */

    /* Outputs for IfAction SubSystem: '<S134>/Blue' incorporates:
     *  ActionPort: '<S137>/Action Port'
     */
    /* Merge: '<S134>/Merge' incorporates:
     *  Constant: '<S137>/BlueAllianceZoneX'
     *  RelationalOperator: '<S137>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S134>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S133>/Red' incorporates:
     *  ActionPort: '<S136>/Action Port'
     */
    /* Merge: '<S133>/Merge' incorporates:
     *  Constant: '<S136>/RedAllianceZoneX'
     *  Logic: '<S136>/AND'
     *  RelationalOperator: '<S136>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S133>/Red' */

    /* Outputs for IfAction SubSystem: '<S134>/Red' incorporates:
     *  ActionPort: '<S138>/Action Port'
     */
    /* Merge: '<S134>/Merge' incorporates:
     *  Constant: '<S138>/RedAllianceZoneX'
     *  RelationalOperator: '<S138>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S134>/Red' */
  }

  /* End of If: '<S133>/If' */

  /* RelationalOperator: '<S104>/GreaterThan' incorporates:
   *  Constant: '<S104>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S104>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S104>/Relational Operator' incorporates:
   *  Abs: '<S104>/Abs'
   *  Constant: '<S132>/Constant3'
   *  Constant: '<S132>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S132>/Math Function'
   *  Sum: '<S104>/Subtract'
   *  Sum: '<S132>/Add1'
   *  Sum: '<S132>/Add2'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S103>/Max' incorporates:
   *  Abs: '<S103>/Abs1'
   *  Abs: '<S103>/Abs2'
   *  Abs: '<S103>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S104>/Relational Operator1' incorporates:
   *  Abs: '<S104>/Abs1'
   *  Constant: '<S104>/Constant2'
   *  Sum: '<S104>/Subtract1'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S104>/Relational Operator4' incorporates:
   *  Abs: '<S104>/Abs4'
   *  Constant: '<S104>/Constant1'
   *  Sum: '<S104>/Subtract4'
   *  UnitDelay generated from: '<S12>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S104>/AND' */
  rtb_Compare_a = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
                    (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                   (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S104>/AND2' incorporates:
   *  Logic: '<S104>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_Compare_a);

  /* SignalConversion: '<S104>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S104>/AND3' */
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
    guard1 = true;
  } else if (Robot_Control_DW.is_c2_Robot_Control ==
             Robot_Control_IN_Not_Shooting) {
    Robot_Control_B.RB_Shooter_Active = false;
    Robot_Control_B.RB_Desired_Feeder_Speed = 0.0;
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
      guard1 = true;
    } else {
      switch (Robot_Control_DW.is_Shooting) {
       case Robot_Control_IN_Feeder:
        Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
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
          Robot_Control_B.RB_Desired_Transfer_Speed =
            Rebuilt_Target_Transfer_Speed;
        }
        break;

       default:
        /* case IN_Transfer: */
        if (Robot_Control_U.Measured_Transfer_Speed >
            (Robot_Control_B.RB_Desired_Transfer_Speed *
             Rebuilt_Transfer_Minimum_Factor)) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Feeder;
          Robot_Control_B.RB_Desired_Feeder_Speed = Rebuilt_Target_Feeder_Speed;
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
    /* Outputs for IfAction SubSystem: '<S101>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S108>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S110>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S112>/While Iterator'
     */
    /* If: '<S101>/If' incorporates:
     *  Constant: '<S110>/Constant'
     *  Constant: '<S111>/Constant'
     *  Constant: '<S113>/Constant1'
     *  Constant: '<S113>/Constant10'
     *  Constant: '<S113>/Constant2'
     *  Constant: '<S113>/Constant5'
     *  Constant: '<S113>/Constant6'
     *  Constant: '<S113>/Constant7'
     *  Constant: '<S113>/Constant8'
     *  Constant: '<S113>/Constant9'
     *  Constant: '<S114>/Constant1'
     *  Constant: '<S114>/Constant10'
     *  Constant: '<S114>/Constant2'
     *  Constant: '<S114>/Constant5'
     *  Constant: '<S114>/Constant6'
     *  Constant: '<S114>/Constant7'
     *  Constant: '<S114>/Constant8'
     *  Constant: '<S114>/Constant9'
     *  Constant: '<S115>/Constant1'
     *  Constant: '<S115>/Constant10'
     *  Constant: '<S115>/Constant2'
     *  Constant: '<S115>/Constant5'
     *  Constant: '<S115>/Constant6'
     *  Constant: '<S115>/Constant7'
     *  Constant: '<S115>/Constant8'
     *  Constant: '<S115>/Constant9'
     *  Constant: '<S117>/Constant1'
     *  Constant: '<S117>/Constant10'
     *  Constant: '<S117>/Constant2'
     *  Constant: '<S117>/Constant5'
     *  Constant: '<S117>/Constant6'
     *  Constant: '<S117>/Constant7'
     *  Constant: '<S117>/Constant8'
     *  Constant: '<S117>/Constant9'
     *  Constant: '<S120>/Constant'
     *  Constant: '<S120>/Constant1'
     *  Constant: '<S120>/Constant11'
     *  Constant: '<S120>/Constant2'
     *  Constant: '<S120>/Constant3'
     *  Constant: '<S120>/Constant4'
     *  Constant: '<S120>/Constant5'
     *  Constant: '<S120>/Constant6'
     *  Gain: '<S118>/Gain1'
     *  Gain: '<S125>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S112>/Memory'
     *  Memory: '<S112>/Memory1'
     *  Memory: '<S112>/Memory2'
     *  Memory: '<S112>/Memory3'
     *  Merge: '<S101>/Merge'
     *  Merge: '<S101>/Merge1'
     *  Merge: '<S101>/Merge2'
     *  Merge: '<S101>/Merge3'
     *  S-Function (sfix_look1_dyn): '<S113>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S114>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S115>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S108>/Desired_Shooter_Speed'
     *  SignalConversion generated from: '<S113>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S120>/Lookup Table Dynamic'
     *  Sum: '<S111>/Add'
     *  Sum: '<S111>/Subtract'
     *  Sum: '<S111>/Subtract1'
     *  Switch: '<S116>/Switch'
     *  Switch: '<S116>/Switch1'
     *  Trigonometry: '<S111>/Tanh'
     */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S110>/Iterate_Shot_Target' */
    rtb_TmpSignalConversionAtLoo_o3[0] = Rebuilt_Shoot_Hood_Pos_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Rebuilt_Shoot_Hood_Pos_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Rebuilt_Shoot_Hood_Pos_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Rebuilt_Shoot_Hood_Pos_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Rebuilt_Shoot_Hood_Pos_4;
    rtb_TmpSignalConversionAtLoo_o3[5] = Rebuilt_Shoot_Hood_Pos_5;
    rtb_TmpSignalConversionAtLoo_o3[6] = Rebuilt_Shoot_Hood_Pos_6;
    rtb_TmpSignalConversionAtLoo_o3[7] = Rebuilt_Shoot_Hood_Pos_7;
    rtb_TmpSignalConversionAtLook_f[0] = Rebuilt_Shoot_Shooter_Spd_0;
    rtb_TmpSignalConversionAtLook_f[1] = Rebuilt_Shoot_Shooter_Spd_1;
    rtb_TmpSignalConversionAtLook_f[2] = Rebuilt_Shoot_Shooter_Spd_2;
    rtb_TmpSignalConversionAtLook_f[3] = Rebuilt_Shoot_Shooter_Spd_3;
    rtb_TmpSignalConversionAtLook_f[4] = Rebuilt_Shoot_Shooter_Spd_4;
    rtb_TmpSignalConversionAtLook_f[5] = Rebuilt_Shoot_Shooter_Spd_5;
    rtb_TmpSignalConversionAtLook_f[6] = Rebuilt_Shoot_Shooter_Spd_6;
    rtb_TmpSignalConversionAtLook_f[7] = Rebuilt_Shoot_Shooter_Spd_7;
    rtb_TmpSignalConversionAtLoo_d0[0] = Rebuilt_Shoot_Gyro_Err_0;
    rtb_TmpSignalConversionAtLoo_d0[1] = Rebuilt_Shoot_Gyro_Err_1;
    rtb_TmpSignalConversionAtLoo_d0[2] = Rebuilt_Shoot_Gyro_Err_2;
    rtb_TmpSignalConversionAtLoo_d0[3] = Rebuilt_Shoot_Gyro_Err_3;
    rtb_TmpSignalConversionAtLoo_d0[4] = Rebuilt_Shoot_Gyro_Err_4;
    rtb_TmpSignalConversionAtLoo_d0[5] = Rebuilt_Shoot_Gyro_Err_5;
    rtb_TmpSignalConversionAtLoo_d0[6] = Rebuilt_Shoot_Gyro_Err_6;
    rtb_TmpSignalConversionAtLoo_d0[7] = Rebuilt_Shoot_Gyro_Err_7;
    if (Robot_Control_U.IsBlueAlliance != 0.0) {
      /* Switch: '<S116>/Switch' incorporates:
       *  Constant: '<S116>/Constant'
       */
      Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;

      /* Switch: '<S116>/Switch1' incorporates:
       *  Constant: '<S116>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Blue_Hub_Y;
    } else {
      /* Switch: '<S116>/Switch' incorporates:
       *  Constant: '<S116>/Constant2'
       */
      Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;

      /* Switch: '<S116>/Switch1' incorporates:
       *  Constant: '<S116>/Constant3'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Red_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S110>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S112>/While Iterator'
     */
    rtb_Button_Spinup_Enable = 1U;
    rtb_Merge1 = 0.0;
    rtb_Add_h5 = 0.0;
    rtb_Switch4 = 0.0;
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
      /* Switch: '<S121>/Switch' incorporates:
       *  Memory: '<S112>/Memory1'
       *  Memory: '<S112>/Memory2'
       *  Switch: '<S121>/Switch1'
       */
      if (rtb_Button_Spinup_Enable > 1) {
        rtb_Init_o = rtb_Merge1;
        rtb_Sin4 = rtb_Add_h5;
      } else {
        rtb_Init_o = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S121>/Switch' */

      /* Math: '<S119>/Hypot' incorporates:
       *  Sum: '<S119>/Subtract'
       *  Sum: '<S119>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Init_o -
        Robot_Control_B.KF_Position_X, rtb_Sin4 - Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S120>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S120>/Lookup Table Dynamic'
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

      /* Sum: '<S122>/Subtract' incorporates:
       *  Memory: '<S112>/Memory3'
       *  Sum: '<S122>/Subtract1'
       */
      rtb_Add_h5 = rtb_TOF - rtb_Switch4;

      /* Sum: '<S122>/Add' incorporates:
       *  Gain: '<S122>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S122>/Product'
       *  Sum: '<S122>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Add_h5 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Init_o;

      /* Sum: '<S122>/Add1' incorporates:
       *  Gain: '<S122>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S122>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Add_h5 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Sin4;

      /* Memory: '<S112>/Memory' */
      rtb_Compare_a = rtb_AND1_c;

      /* Update for Memory: '<S112>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S112>/Memory2' */
      rtb_Add_h5 = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S112>/Memory3' */
      rtb_Switch4 = rtb_TOF;

      /* Update for Memory: '<S112>/Memory' incorporates:
       *  Constant: '<S124>/Constant'
       *  Math: '<S123>/Hypot'
       *  RelationalOperator: '<S124>/Compare'
       *  Sum: '<S123>/Subtract'
       *  Sum: '<S123>/Subtract1'
       */
      rtb_AND1_c = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X -
        rtb_Init_o, Robot_Control_B.RB_Desired_Target_Y - rtb_Sin4) >=
                    Rebuilt_Shoot_Target_Error_Thresh);
      rtb_Button_Spinup_Enable++;
    }

    /* End of Outputs for SubSystem: '<S110>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S114>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Desired_Hood_Pos),
                         &rtb_TmpSignalConversionAtLoo_o3[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);

    /* Dynamic Look-Up Table Block: '<S115>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Desired_Shoot_Motor_Spd),
                         &rtb_TmpSignalConversionAtLook_f[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);

    /* Dynamic Look-Up Table Block: '<S113>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.RB_Allow_Shoot_Gyro_Err),
                         &rtb_TmpSignalConversionAtLoo_d0[0],
                         Robot_Control_B.RB_Desired_Shot_Distance,
                         &rtb_TmpSignalConversionAtLook_o[0], 7U);
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.017453292519943295 *
      Robot_Control_B.RB_Allow_Shoot_Gyro_Err;
    Robot_Control_B.RB_Desired_Shooter_Speed =
      Robot_Control_B.RB_Desired_Shoot_Motor_Spd;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot =
      Robot_Control_B.RB_Desired_Hood_Pos;
    Robot_Control_B.RB_Desired_Gyro_Angle_raw = rt_atan2d_snf
      (Robot_Control_B.RB_Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.RB_Desired_Target_X - Robot_Control_B.KF_Position_X);
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = (0.017453292519943295 *
      Rebuilt_Des_Gyro_Shoot_Offset) + Robot_Control_B.RB_Desired_Gyro_Angle_raw;

    /* End of Outputs for SubSystem: '<S101>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_i = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Add_k = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S101>/Shooter Not Active' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    /* If: '<S101>/If' incorporates:
     *  Constant: '<S109>/Constant'
     *  Constant: '<S109>/Constant1'
     *  Constant: '<S109>/Constant2'
     *  Merge: '<S101>/Merge'
     *  Merge: '<S101>/Merge1'
     *  Merge: '<S101>/Merge2'
     *  Merge: '<S101>/Merge3'
     *  SignalConversion generated from: '<S109>/Desired_Gyro_Angle'
     *  UnitDelay: '<S101>/Unit Delay'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot =
      Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S101>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_i = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Add_k = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S12>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S330>/Add1' incorporates:
   *  Constant: '<S330>/Constant3'
   *  Constant: '<S330>/Constant4'
   *  Math: '<S330>/Math Function'
   *  Sum: '<S329>/Sum'
   *  Sum: '<S330>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_i - rtb_Add_k) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S332>/Sum1' incorporates:
   *  Constant: '<S329>/Constant2'
   *  Product: '<S332>/Product'
   *  Sum: '<S332>/Sum'
   *  UnitDelay: '<S332>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_Optimized_Module_Angle_p -
                 Robot_Control_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S329>/Product' incorporates:
   *  Constant: '<S329>/Constant3'
   */
  rtb_Add_h5 = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S331>/Diff' incorporates:
   *  UnitDelay: '<S331>/UD'
   *
   * Block description for '<S331>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S331>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Add_h5 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S329>/Saturation' */
  if (rtb_Add_i > Steering_Heading_Control_D_UL) {
    rtb_Add_i = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_i < Steering_Heading_Control_D_LL) {
    rtb_Add_i = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S329>/Add' incorporates:
   *  Gain: '<S329>/Gain1'
   *  Saturate: '<S329>/Saturation'
   */
  rtb_Init_o = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_i;

  /* Sum: '<S329>/Subtract' incorporates:
   *  Constant: '<S329>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Init_o;

  /* Sum: '<S329>/Sum2' incorporates:
   *  Gain: '<S329>/Gain2'
   *  UnitDelay: '<S329>/Unit Delay'
   */
  rtb_Switch4 = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S333>/Switch2' incorporates:
   *  RelationalOperator: '<S333>/LowerRelop1'
   */
  if (!(rtb_Switch4 > rtb_Sin4)) {
    /* Sum: '<S329>/Subtract1' incorporates:
     *  Constant: '<S329>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Init_o;

    /* Switch: '<S333>/Switch' incorporates:
     *  RelationalOperator: '<S333>/UpperRelop'
     */
    if (!(rtb_Switch4 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch4;
    }

    /* End of Switch: '<S333>/Switch' */
  }

  /* End of Switch: '<S333>/Switch2' */

  /* Saturate: '<S329>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Switch4 = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Switch4 = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch4 = rtb_Sin4;
  }

  /* End of Saturate: '<S329>/Saturation1' */

  /* Sum: '<S329>/Add1' */
  rtb_Add_i = rtb_Init_o + rtb_Switch4;

  /* Saturate: '<S329>/Saturation2' */
  if (rtb_Add_i > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S329>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_i < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S329>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S329>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_i;
  }

  /* End of Saturate: '<S329>/Saturation2' */

  /* Switch: '<S313>/Switch' incorporates:
   *  Abs: '<S313>/Abs'
   *  Constant: '<S313>/Constant'
   *  Constant: '<S328>/Constant'
   *  RelationalOperator: '<S328>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Optimized_Module_Angle_p = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Optimized_Module_Angle_p = 0.0;
  }

  /* End of Switch: '<S313>/Switch' */

  /* Signum: '<S312>/Sign2' incorporates:
   *  UnitDelay: '<S312>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S312>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Add_k = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S312>/Product1' incorporates:
   *  Signum: '<S312>/Sign1'
   *  Signum: '<S312>/Sign2'
   */
  rtb_Add_i *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_i)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_i, 256.0);
  }

  /* Switch: '<S312>/Switch' incorporates:
   *  Constant: '<S312>/Constant'
   *  Constant: '<S321>/Constant'
   *  Constant: '<S322>/Constant'
   *  Logic: '<S312>/or'
   *  Product: '<S312>/Product1'
   *  RelationalOperator: '<S321>/Compare'
   *  RelationalOperator: '<S322>/Compare'
   *  UnitDelay: '<S312>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Derivative = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Derivative = 0.0;
  }

  /* End of Switch: '<S312>/Switch' */

  /* Switch: '<S327>/Init' incorporates:
   *  UnitDelay: '<S327>/FixPt Unit Delay1'
   *  UnitDelay: '<S327>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Derivative;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S327>/Init' */

  /* RelationalOperator: '<S323>/Compare' incorporates:
   *  Constant: '<S323>/Constant'
   */
  rtb_Compare_a = (rtb_Derivative == 0.0);

  /* RelationalOperator: '<S324>/Compare' incorporates:
   *  Constant: '<S324>/Constant'
   */
  rtb_AND1_c = (rtb_Derivative > 0.0);

  /* Abs: '<S312>/Abs' incorporates:
   *  Sum: '<S312>/Subtract'
   *  UnitDelay: '<S312>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S312>/Switch5' incorporates:
   *  Constant: '<S312>/Constant1'
   *  Switch: '<S312>/Switch1'
   *  UnaryMinus: '<S312>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S312>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S312>/Constant4'
     *  Constant: '<S312>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S312>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S312>/Constant2'
     *  Constant: '<S312>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S312>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S312>/Lookup Table Dynamic'
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
    rtb_Add_i = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S312>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S312>/Constant10'
     *  Constant: '<S312>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S312>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S312>/Constant7'
     *  Constant: '<S312>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S312>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S312>/Lookup Table Dynamic1'
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

    /* Switch: '<S312>/Switch3' incorporates:
     *  Constant: '<S312>/Constant1'
     *  Constant: '<S312>/Constant3'
     *  UnaryMinus: '<S312>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_i = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_i = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S312>/Switch3' */
  }

  /* End of Switch: '<S312>/Switch5' */

  /* Product: '<S312>/Product' incorporates:
   *  Switch: '<S312>/Switch1'
   */
  rtb_Switch4_e = rtb_Add_i * rtb_Sin4;

  /* Sum: '<S325>/Sum1' */
  rtb_Switch1 = rtb_Derivative - rtb_Init_o;

  /* Switch: '<S326>/Switch2' incorporates:
   *  RelationalOperator: '<S326>/LowerRelop1'
   */
  if (!(rtb_Switch1 > rtb_Switch4_e)) {
    /* Switch: '<S312>/Switch2' incorporates:
     *  Constant: '<S312>/Constant1'
     *  Constant: '<S312>/Constant3'
     *  Switch: '<S312>/Switch4'
     *  UnaryMinus: '<S312>/Unary Minus1'
     */
    if (rtb_Compare_a) {
      rtb_Add_i = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S312>/Switch4' incorporates:
       *  Constant: '<S312>/Constant1'
       */
      rtb_Add_i = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_i = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S312>/Product2' incorporates:
     *  Switch: '<S312>/Switch2'
     */
    rtb_Switch2 = rtb_Add_i * rtb_Sin4;

    /* Switch: '<S326>/Switch' incorporates:
     *  RelationalOperator: '<S326>/UpperRelop'
     */
    if (rtb_Switch1 < rtb_Switch2) {
      rtb_Switch4_e = rtb_Switch2;
    } else {
      rtb_Switch4_e = rtb_Switch1;
    }

    /* End of Switch: '<S326>/Switch' */
  }

  /* End of Switch: '<S326>/Switch2' */

  /* Sum: '<S325>/Sum' */
  rtb_Init_o += rtb_Switch4_e;

  /* Signum: '<S311>/Sign2' incorporates:
   *  UnitDelay: '<S311>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_i = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S311>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S311>/Product1' incorporates:
   *  Signum: '<S311>/Sign1'
   *  Signum: '<S311>/Sign2'
   */
  rtb_Add_i *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_i)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_i, 256.0);
  }

  /* Switch: '<S311>/Switch' incorporates:
   *  Constant: '<S311>/Constant'
   *  Constant: '<S314>/Constant'
   *  Constant: '<S315>/Constant'
   *  Logic: '<S311>/or'
   *  Product: '<S311>/Product1'
   *  RelationalOperator: '<S314>/Compare'
   *  RelationalOperator: '<S315>/Compare'
   *  UnitDelay: '<S311>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Derivative = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Derivative = 0.0;
  }

  /* End of Switch: '<S311>/Switch' */

  /* Switch: '<S320>/Init' incorporates:
   *  UnitDelay: '<S320>/FixPt Unit Delay1'
   *  UnitDelay: '<S320>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Derivative;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S320>/Init' */

  /* RelationalOperator: '<S316>/Compare' incorporates:
   *  Constant: '<S316>/Constant'
   */
  rtb_Compare_a = (rtb_Derivative == 0.0);

  /* RelationalOperator: '<S317>/Compare' incorporates:
   *  Constant: '<S317>/Constant'
   */
  rtb_AND1_c = (rtb_Derivative > 0.0);

  /* Abs: '<S311>/Abs' incorporates:
   *  Sum: '<S311>/Subtract'
   *  UnitDelay: '<S311>/Unit Delay'
   */
  rtb_Switch1 = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                     Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S311>/Switch1' incorporates:
   *  Constant: '<S311>/Constant1'
   *  Switch: '<S311>/Switch3'
   *  Switch: '<S311>/Switch5'
   *  UnaryMinus: '<S311>/Unary Minus'
   */
  if (rtb_Compare_a) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S311>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S311>/Constant1'
     *  Constant: '<S311>/Constant4'
     *  Constant: '<S311>/Constant6'
     *  UnaryMinus: '<S311>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S311>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S311>/Constant2'
     *  Constant: '<S311>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S311>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S311>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p), &rtb_Reshapey[0],
                         rtb_Switch1, &rtb_Minus_n[0], 1U);
    rtb_Switch1 = rtb_LookupTableDynamic_p;
  } else {
    if (rtb_AND1_c) {
      /* Switch: '<S311>/Switch3' incorporates:
       *  Constant: '<S311>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S311>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S311>/Constant1'
     *  Constant: '<S311>/Constant10'
     *  Constant: '<S311>/Constant8'
     *  UnaryMinus: '<S311>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S311>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S311>/Constant7'
     *  Constant: '<S311>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S311>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S311>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g), &rtb_Reshapey[0],
                         rtb_Switch1, &rtb_Minus_n[0], 1U);
    rtb_Switch1 = rtb_LookupTableDynamic1_g;
  }

  /* End of Switch: '<S311>/Switch1' */

  /* Product: '<S311>/Product' */
  rtb_Sin4 *= rtb_Switch1;

  /* Sum: '<S318>/Sum1' */
  rtb_Switch2 = rtb_Derivative - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S319>/Switch2' incorporates:
   *  RelationalOperator: '<S319>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_Sin4)) {
    /* Switch: '<S311>/Switch2' incorporates:
     *  Constant: '<S311>/Constant1'
     *  Switch: '<S311>/Switch4'
     */
    if (rtb_Compare_a) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S311>/Switch4' incorporates:
       *  Constant: '<S311>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S311>/Switch4' incorporates:
       *  Constant: '<S311>/Constant3'
       *  UnaryMinus: '<S311>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S311>/Switch2' */

    /* Product: '<S311>/Product2' */
    rtb_Sin4 *= rtb_Switch1;

    /* Switch: '<S319>/Switch' incorporates:
     *  RelationalOperator: '<S319>/UpperRelop'
     */
    if (!(rtb_Switch2 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2;
    }

    /* End of Switch: '<S319>/Switch' */
  }

  /* End of Switch: '<S319>/Switch2' */

  /* Sum: '<S318>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S301>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S301>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S301>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S301>/Switch' */

  /* Fcn: '<S342>/r->x' incorporates:
   *  Fcn: '<S347>/r->x'
   *  Fcn: '<S352>/r->x'
   *  Fcn: '<S357>/r->x'
   */
  rtb_Switch4_e = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S336>/Add' incorporates:
   *  Fcn: '<S342>/r->x'
   *  Fcn: '<S343>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch4_e;

  /* Fcn: '<S342>/theta->y' incorporates:
   *  Fcn: '<S347>/theta->y'
   *  Fcn: '<S352>/theta->y'
   *  Fcn: '<S357>/theta->y'
   */
  rtb_Derivative = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S336>/Add' incorporates:
   *  Fcn: '<S342>/theta->y'
   *  Fcn: '<S343>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Derivative;

  /* Sum: '<S337>/Add' incorporates:
   *  Fcn: '<S348>/r->x'
   *  Fcn: '<S348>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch4_e;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Derivative;

  /* Sum: '<S338>/Add' incorporates:
   *  Fcn: '<S353>/r->x'
   *  Fcn: '<S353>/theta->y'
   */
  rtb_Add2_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch4_e;
  rtb_Add2_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Derivative;

  /* Sum: '<S339>/Add' incorporates:
   *  Fcn: '<S358>/r->x'
   *  Fcn: '<S358>/theta->y'
   */
  rtb_Switch2_p2 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch4_e;
  rtb_Switch1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Derivative;

  /* Fcn: '<S356>/x->r' */
  rtb_Switch4_e = rt_hypotd_snf(rtb_Switch2_p2, rtb_Switch1);

  /* RelationalOperator: '<S359>/Compare' incorporates:
   *  Constant: '<S359>/Constant'
   */
  rtb_Compare_a = (rtb_Switch4_e == 0.0);

  /* Switch: '<S355>/Switch1' */
  if (rtb_Compare_a) {
    /* Switch: '<S355>/Switch1' incorporates:
     *  Constant: '<S355>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S355>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch4_e;
  }

  /* End of Switch: '<S355>/Switch1' */

  /* Fcn: '<S341>/x->r' */
  rtb_Switch4_e = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S344>/Compare' incorporates:
   *  Constant: '<S344>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Switch4_e == 0.0);

  /* Switch: '<S340>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S340>/Switch1' incorporates:
     *  Constant: '<S340>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S340>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch4_e;
  }

  /* End of Switch: '<S340>/Switch1' */

  /* Fcn: '<S346>/x->r' */
  rtb_Derivative = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S349>/Compare' incorporates:
   *  Constant: '<S349>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Derivative == 0.0);

  /* Switch: '<S345>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S345>/Switch1' incorporates:
     *  Constant: '<S345>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S345>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Derivative;
  }

  /* End of Switch: '<S345>/Switch1' */

  /* Fcn: '<S351>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2_idx_0, rtb_Add2_idx_1);

  /* RelationalOperator: '<S354>/Compare' incorporates:
   *  Constant: '<S354>/Constant'
   */
  rtb_AND1_c = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S350>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S350>/Switch1' incorporates:
     *  Constant: '<S350>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S350>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S350>/Switch1' */

  /* Product: '<S335>/Divide' incorporates:
   *  Abs: '<S335>/Abs'
   *  Abs: '<S335>/Abs1'
   *  Abs: '<S335>/Abs2'
   *  Abs: '<S335>/Abs3'
   *  Constant: '<S335>/Constant'
   *  MinMax: '<S335>/Max'
   */
  rtb_Switch4_e = 5.6911039183900929 / fmax(fmax(fmax(fmax(5.6911039183900929,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S335>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch4_e;

  /* Switch: '<S355>/Switch' */
  if (!rtb_Compare_a) {
    /* Switch: '<S355>/Switch' incorporates:
     *  Fcn: '<S356>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Switch1,
      rtb_Switch2_p2);
  }

  /* End of Switch: '<S355>/Switch' */

  /* Trigonometry: '<S291>/Cos4' incorporates:
   *  Switch: '<S280>/Angle_Switch'
   *  Trigonometry: '<S290>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S291>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S289>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S291>/Sin4' incorporates:
   *  Switch: '<S280>/Angle_Switch'
   *  Trigonometry: '<S290>/Sin4'
   */
  rtb_Switch1 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S291>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S289>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S291>/Subtract1' incorporates:
   *  Product: '<S291>/Product2'
   *  Product: '<S291>/Product3'
   *  Trigonometry: '<S291>/Cos4'
   *  Trigonometry: '<S291>/Sin4'
   */
  rtb_Switch2 = (rtb_Add_k * rtb_Optimized_Module_Angle) + (rtb_Switch1 *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S291>/Subtract' incorporates:
   *  Product: '<S291>/Product'
   *  Product: '<S291>/Product1'
   *  Trigonometry: '<S291>/Cos4'
   *  Trigonometry: '<S291>/Sin4'
   */
  rtb_Init = (rtb_Add_k * rtb_Optimized_Module_Angle_p) - (rtb_Switch1 *
    rtb_Optimized_Module_Angle);

  /* Math: '<S291>/Hypot' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Init, rtb_Switch2);

  /* Switch: '<S291>/Switch' incorporates:
   *  Constant: '<S291>/Constant'
   *  Constant: '<S291>/Constant1'
   *  Constant: '<S292>/Constant'
   *  Product: '<S291>/Divide'
   *  Product: '<S291>/Divide1'
   *  RelationalOperator: '<S292>/Compare'
   *  Switch: '<S291>/Switch1'
   */
  if (rtb_Switch2_p2 > 1.0E-6) {
    rtb_Derivative = rtb_Switch2 / rtb_Switch2_p2;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Switch2_p2;
  } else {
    rtb_Derivative = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S291>/Switch' */

  /* Switch: '<S280>/Speed_Switch' incorporates:
   *  Abs: '<S280>/Abs'
   *  Constant: '<S288>/Constant'
   *  RelationalOperator: '<S288>/Compare'
   *  Switch: '<S280>/Angle_Switch'
   *  Trigonometry: '<S290>/Atan1'
   *  Trigonometry: '<S291>/Atan1'
   *  UnaryMinus: '<S280>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Derivative, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_i = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S290>/Subtract1' incorporates:
     *  Product: '<S290>/Product2'
     *  Product: '<S290>/Product3'
     *  UnaryMinus: '<S280>/Unary Minus'
     */
    rtb_Switch2 = (rtb_Add_k * Robot_Control_ConstB.Sin5_c) + (rtb_Switch1 *
      Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S290>/Subtract' incorporates:
     *  Product: '<S290>/Product'
     *  Product: '<S290>/Product1'
     */
    rtb_Init = (rtb_Add_k * Robot_Control_ConstB.Cos5_b) - (rtb_Switch1 *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S290>/Hypot' */
    rtb_Switch1 = rt_hypotd_snf(rtb_Init, rtb_Switch2);

    /* Switch: '<S290>/Switch1' incorporates:
     *  Constant: '<S290>/Constant'
     *  Constant: '<S290>/Constant1'
     *  Constant: '<S293>/Constant'
     *  Product: '<S290>/Divide'
     *  Product: '<S290>/Divide1'
     *  RelationalOperator: '<S293>/Compare'
     *  Switch: '<S290>/Switch'
     */
    if (rtb_Switch1 > 1.0E-6) {
      rtb_Init /= rtb_Switch1;
      rtb_Switch1 = rtb_Switch2 / rtb_Switch1;
    } else {
      rtb_Init = 1.0;
      rtb_Switch1 = 0.0;
    }

    /* End of Switch: '<S290>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Init);
  } else {
    rtb_Add_i = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S283>/Product2' incorporates:
   *  Constant: '<S283>/Constant'
   *  Switch: '<S280>/Speed_Switch'
   */
  rtb_Derivative = rtb_Add_i * 1089.4195728820682;

  /* Signum: '<S278>/Sign' */
  if (rtIsNaN(rtb_Derivative)) {
    rtb_Add_i = (rtNaN);
  } else if (rtb_Derivative < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (rtb_Derivative > 0.0);
  }

  /* Signum: '<S278>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S281>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S282>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S213>/Product' incorporates:
   *  Abs: '<S278>/Abs'
   *  Abs: '<S281>/Abs'
   *  Constant: '<S284>/Constant'
   *  Constant: '<S294>/Constant3'
   *  Constant: '<S294>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
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
  rtb_Derivative = (((real_T)((rtb_Add_i == rtb_Add_k) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Derivative) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData, 1U);

  /* Sum: '<S279>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Init = rtb_Derivative - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S286>/Sum1' incorporates:
   *  Constant: '<S279>/Constant2'
   *  Product: '<S286>/Product'
   *  Sum: '<S286>/Sum'
   *  UnitDelay: '<S286>/Unit Delay1'
   */
  rtb_Switch1 = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                 Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S279>/Product' incorporates:
   *  Constant: '<S279>/Constant3'
   */
  rtb_Switch2 = rtb_Switch1 * Drive_Motor_Control_D;

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
  rtb_Add_i = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S279>/Saturation' */
  if (rtb_Add_i > Drive_Motor_Control_D_UL) {
    rtb_Add_i = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_i < Drive_Motor_Control_D_LL) {
    rtb_Add_i = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S279>/Add' incorporates:
   *  Gain: '<S279>/Gain'
   *  Gain: '<S279>/Gain1'
   *  Saturate: '<S279>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Derivative) +
                    (Drive_Motor_Control_P * rtb_Init)) + rtb_Add_i;

  /* Saturate: '<S279>/Saturation2' incorporates:
   *  Sum: '<S279>/Add1'
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

  /* End of Saturate: '<S279>/Saturation2' */

  /* Switch: '<S340>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S340>/Switch' incorporates:
     *  Fcn: '<S341>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S340>/Switch' */

  /* Trigonometry: '<S228>/Cos4' incorporates:
   *  Switch: '<S217>/Angle_Switch'
   *  Trigonometry: '<S227>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S228>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S226>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S228>/Sin4' incorporates:
   *  Switch: '<S217>/Angle_Switch'
   *  Trigonometry: '<S227>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S228>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S226>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S228>/Subtract1' incorporates:
   *  Product: '<S228>/Product2'
   *  Product: '<S228>/Product3'
   *  Trigonometry: '<S228>/Cos4'
   *  Trigonometry: '<S228>/Sin4'
   */
  rtb_Switch2_p2 = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle
    * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S228>/Subtract' incorporates:
   *  Product: '<S228>/Product'
   *  Product: '<S228>/Product1'
   *  Trigonometry: '<S228>/Cos4'
   *  Trigonometry: '<S228>/Sin4'
   */
  rtb_Init = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S228>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Init, rtb_Switch2_p2);

  /* Switch: '<S228>/Switch' incorporates:
   *  Constant: '<S228>/Constant'
   *  Constant: '<S228>/Constant1'
   *  Constant: '<S229>/Constant'
   *  Product: '<S228>/Divide'
   *  Product: '<S228>/Divide1'
   *  RelationalOperator: '<S229>/Compare'
   *  Switch: '<S228>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_Derivative = rtb_Switch2_p2 / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Hypot_g5;
  } else {
    rtb_Derivative = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S228>/Switch' */

  /* Product: '<S335>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch4_e;

  /* Switch: '<S217>/Speed_Switch' incorporates:
   *  Abs: '<S217>/Abs'
   *  Constant: '<S225>/Constant'
   *  RelationalOperator: '<S225>/Compare'
   *  Switch: '<S217>/Angle_Switch'
   *  Trigonometry: '<S227>/Atan1'
   *  Trigonometry: '<S228>/Atan1'
   *  UnaryMinus: '<S217>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Derivative, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_i = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S227>/Subtract1' incorporates:
     *  Product: '<S227>/Product2'
     *  Product: '<S227>/Product3'
     *  UnaryMinus: '<S217>/Unary Minus'
     */
    rtb_Switch2_p2 = (rtb_Add_k * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S227>/Subtract' incorporates:
     *  Product: '<S227>/Product'
     *  Product: '<S227>/Product1'
     */
    rtb_Hypot_g5 = (rtb_Add_k * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S227>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Hypot_g5, rtb_Switch2_p2);

    /* Switch: '<S227>/Switch1' incorporates:
     *  Constant: '<S227>/Constant'
     *  Constant: '<S227>/Constant1'
     *  Constant: '<S230>/Constant'
     *  Product: '<S227>/Divide'
     *  Product: '<S227>/Divide1'
     *  RelationalOperator: '<S230>/Compare'
     *  Switch: '<S227>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Init;
      rtb_Switch2_p2 /= rtb_Init;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S227>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Switch2_p2, rtb_Hypot_g5);
  } else {
    rtb_Add_i = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S220>/Product2' incorporates:
   *  Constant: '<S220>/Constant'
   *  Switch: '<S217>/Speed_Switch'
   */
  rtb_Derivative = rtb_Add_i * 1089.4195728820682;

  /* Signum: '<S215>/Sign' */
  if (rtIsNaN(rtb_Derivative)) {
    rtb_Add_i = (rtNaN);
  } else if (rtb_Derivative < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (rtb_Derivative > 0.0);
  }

  /* Signum: '<S215>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S218>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S219>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S210>/Product' incorporates:
   *  Abs: '<S215>/Abs'
   *  Abs: '<S218>/Abs'
   *  Constant: '<S221>/Constant'
   *  Constant: '<S231>/Constant3'
   *  Constant: '<S231>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S215>/OR'
   *  Lookup_n-D: '<S218>/1-D Lookup Table'
   *  Math: '<S231>/Math Function'
   *  RelationalOperator: '<S215>/Equal1'
   *  RelationalOperator: '<S221>/Compare'
   *  Signum: '<S215>/Sign'
   *  Signum: '<S215>/Sign1'
   *  Sum: '<S218>/Add'
   *  Sum: '<S231>/Add1'
   *  Sum: '<S231>/Add2'
   */
  rtb_Derivative = (((real_T)((rtb_Add_i == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Derivative) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j,
                  1U);

  /* Sum: '<S216>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_g5 = rtb_Derivative - Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S223>/Sum1' incorporates:
   *  Constant: '<S216>/Constant2'
   *  Product: '<S223>/Product'
   *  Sum: '<S223>/Sum'
   *  UnitDelay: '<S223>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_Hypot_g5 - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                    Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S216>/Product' incorporates:
   *  Constant: '<S216>/Constant3'
   */
  rtb_Init = rtb_Switch2_p2 * Drive_Motor_Control_D;

  /* Sum: '<S222>/Diff' incorporates:
   *  UnitDelay: '<S222>/UD'
   *
   * Block description for '<S222>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S222>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Init - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S216>/Saturation' */
  if (rtb_Add_i > Drive_Motor_Control_D_UL) {
    rtb_Add_i = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_i < Drive_Motor_Control_D_LL) {
    rtb_Add_i = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S216>/Add' incorporates:
   *  Gain: '<S216>/Gain'
   *  Gain: '<S216>/Gain1'
   *  Saturate: '<S216>/Saturation'
   */
  rtb_Hypot_g5 = ((Drive_Motor_Control_FF * rtb_Derivative) +
                  (Drive_Motor_Control_P * rtb_Hypot_g5)) + rtb_Add_i;

  /* Saturate: '<S216>/Saturation2' incorporates:
   *  Sum: '<S216>/Add1'
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

  /* End of Saturate: '<S216>/Saturation2' */

  /* Sum: '<S232>/Add1' incorporates:
   *  Constant: '<S232>/Constant3'
   *  Constant: '<S232>/Constant4'
   *  Math: '<S232>/Math Function'
   *  Sum: '<S232>/Add2'
   */
  rtb_Derivative = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S234>/Sum1' incorporates:
   *  Constant: '<S219>/Constant2'
   *  Product: '<S234>/Product'
   *  Sum: '<S234>/Sum'
   *  UnitDelay: '<S234>/Unit Delay1'
   */
  rtb_Hypot_g5 = ((rtb_Derivative - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S219>/Product' incorporates:
   *  Constant: '<S219>/Constant3'
   */
  rtb_Switch2_dp = rtb_Hypot_g5 * Steering_Motor_Control_D;

  /* Sum: '<S233>/Diff' incorporates:
   *  UnitDelay: '<S233>/UD'
   *
   * Block description for '<S233>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S233>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Switch2_dp - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S219>/Saturation' */
  if (rtb_Add_i > Steering_Motor_Control_D_UL) {
    rtb_Add_i = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_i < Steering_Motor_Control_D_LL) {
    rtb_Add_i = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S219>/Add' incorporates:
   *  Gain: '<S219>/Gain1'
   *  Saturate: '<S219>/Saturation'
   */
  rtb_Add_fn = (Steering_Motor_Control_P * rtb_Derivative) + rtb_Add_i;

  /* Sum: '<S219>/Subtract' incorporates:
   *  Constant: '<S219>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_fn;

  /* Sum: '<S219>/Sum2' incorporates:
   *  Gain: '<S219>/Gain2'
   *  UnitDelay: '<S219>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Derivative) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S235>/Switch2' incorporates:
   *  Constant: '<S219>/Constant'
   *  RelationalOperator: '<S235>/LowerRelop1'
   *  Sum: '<S219>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_fn))) {
    /* Switch: '<S235>/Switch' incorporates:
     *  Constant: '<S219>/Constant1'
     *  RelationalOperator: '<S235>/UpperRelop'
     *  Sum: '<S219>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_fn)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_fn;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S235>/Switch' */
  }

  /* End of Switch: '<S235>/Switch2' */

  /* Saturate: '<S219>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S219>/Saturation1' */

  /* Sum: '<S219>/Add1' */
  rtb_Add_i = rtb_Add_fn + rtb_Sum2_e;

  /* Saturate: '<S219>/Saturation2' */
  if (rtb_Add_i > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_i < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_i;
  }

  /* End of Saturate: '<S219>/Saturation2' */

  /* Switch: '<S345>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S345>/Switch' incorporates:
     *  Fcn: '<S346>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S345>/Switch' */

  /* Trigonometry: '<S249>/Cos4' incorporates:
   *  Switch: '<S238>/Angle_Switch'
   *  Trigonometry: '<S248>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S249>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S247>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S249>/Sin4' incorporates:
   *  Switch: '<S238>/Angle_Switch'
   *  Trigonometry: '<S248>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S249>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S247>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S249>/Subtract1' incorporates:
   *  Product: '<S249>/Product2'
   *  Product: '<S249>/Product3'
   *  Trigonometry: '<S249>/Cos4'
   *  Trigonometry: '<S249>/Sin4'
   */
  rtb_Add_fn = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S249>/Subtract' incorporates:
   *  Product: '<S249>/Product'
   *  Product: '<S249>/Product1'
   *  Trigonometry: '<S249>/Cos4'
   *  Trigonometry: '<S249>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S249>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_fn);

  /* Switch: '<S249>/Switch' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S249>/Constant1'
   *  Constant: '<S250>/Constant'
   *  Product: '<S249>/Divide'
   *  Product: '<S249>/Divide1'
   *  RelationalOperator: '<S250>/Compare'
   *  Switch: '<S249>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_Derivative = rtb_Add_fn / rtb_Hypot_b;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_Hypot_b;
  } else {
    rtb_Derivative = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S249>/Switch' */

  /* Product: '<S335>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch4_e;

  /* Switch: '<S238>/Speed_Switch' incorporates:
   *  Abs: '<S238>/Abs'
   *  Constant: '<S246>/Constant'
   *  RelationalOperator: '<S246>/Compare'
   *  Switch: '<S238>/Angle_Switch'
   *  Trigonometry: '<S248>/Atan1'
   *  Trigonometry: '<S249>/Atan1'
   *  UnaryMinus: '<S238>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Derivative, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_i = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S248>/Subtract1' incorporates:
     *  Product: '<S248>/Product2'
     *  Product: '<S248>/Product3'
     *  UnaryMinus: '<S238>/Unary Minus'
     */
    rtb_Add_fn = (rtb_Add_k * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S248>/Subtract' incorporates:
     *  Product: '<S248>/Product'
     *  Product: '<S248>/Product1'
     */
    rtb_Hypot_b = (rtb_Add_k * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S248>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_Hypot_b, rtb_Add_fn);

    /* Switch: '<S248>/Switch1' incorporates:
     *  Constant: '<S248>/Constant'
     *  Constant: '<S248>/Constant1'
     *  Constant: '<S251>/Constant'
     *  Product: '<S248>/Divide'
     *  Product: '<S248>/Divide1'
     *  RelationalOperator: '<S251>/Compare'
     *  Switch: '<S248>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_Hypot_b /= rtb_Subtract1_la;
      rtb_Add_fn /= rtb_Subtract1_la;
    } else {
      rtb_Hypot_b = 1.0;
      rtb_Add_fn = 0.0;
    }

    /* End of Switch: '<S248>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_fn, rtb_Hypot_b);
  } else {
    rtb_Add_i = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S241>/Product2' incorporates:
   *  Constant: '<S241>/Constant'
   *  Switch: '<S238>/Speed_Switch'
   */
  rtb_Derivative = rtb_Add_i * 1089.4195728820682;

  /* Signum: '<S236>/Sign' */
  if (rtIsNaN(rtb_Derivative)) {
    rtb_Add_i = (rtNaN);
  } else if (rtb_Derivative < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (rtb_Derivative > 0.0);
  }

  /* Signum: '<S236>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S239>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S240>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S211>/Product' incorporates:
   *  Abs: '<S236>/Abs'
   *  Abs: '<S239>/Abs'
   *  Constant: '<S242>/Constant'
   *  Constant: '<S252>/Constant3'
   *  Constant: '<S252>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S236>/OR'
   *  Lookup_n-D: '<S239>/1-D Lookup Table'
   *  Math: '<S252>/Math Function'
   *  RelationalOperator: '<S236>/Equal1'
   *  RelationalOperator: '<S242>/Compare'
   *  Signum: '<S236>/Sign'
   *  Signum: '<S236>/Sign1'
   *  Sum: '<S239>/Add'
   *  Sum: '<S252>/Add1'
   *  Sum: '<S252>/Add2'
   */
  rtb_Derivative = (((real_T)((rtb_Add_i == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Derivative) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_g,
                  1U);

  /* Sum: '<S237>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Hypot_b = rtb_Derivative - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S244>/Sum1' incorporates:
   *  Constant: '<S237>/Constant2'
   *  Product: '<S244>/Product'
   *  Sum: '<S244>/Sum'
   *  UnitDelay: '<S244>/Unit Delay1'
   */
  rtb_Add_fn = ((rtb_Hypot_b - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S237>/Product' incorporates:
   *  Constant: '<S237>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_fn * Drive_Motor_Control_D;

  /* Sum: '<S243>/Diff' incorporates:
   *  UnitDelay: '<S243>/UD'
   *
   * Block description for '<S243>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S243>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S237>/Saturation' */
  if (rtb_Add_i > Drive_Motor_Control_D_UL) {
    rtb_Add_i = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_i < Drive_Motor_Control_D_LL) {
    rtb_Add_i = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S237>/Add' incorporates:
   *  Gain: '<S237>/Gain'
   *  Gain: '<S237>/Gain1'
   *  Saturate: '<S237>/Saturation'
   */
  rtb_Hypot_b = ((Drive_Motor_Control_FF * rtb_Derivative) +
                 (Drive_Motor_Control_P * rtb_Hypot_b)) + rtb_Add_i;

  /* Saturate: '<S237>/Saturation2' incorporates:
   *  Sum: '<S237>/Add1'
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

  /* End of Saturate: '<S237>/Saturation2' */

  /* Sum: '<S253>/Add1' incorporates:
   *  Constant: '<S253>/Constant3'
   *  Constant: '<S253>/Constant4'
   *  Math: '<S253>/Math Function'
   *  Sum: '<S253>/Add2'
   */
  rtb_Derivative = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S255>/Sum1' incorporates:
   *  Constant: '<S240>/Constant2'
   *  Product: '<S255>/Product'
   *  Sum: '<S255>/Sum'
   *  UnitDelay: '<S255>/Unit Delay1'
   */
  rtb_Hypot_b = ((rtb_Derivative - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                 Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S240>/Product' incorporates:
   *  Constant: '<S240>/Constant3'
   */
  rtb_Switch2_m = rtb_Hypot_b * Steering_Motor_Control_D;

  /* Sum: '<S254>/Diff' incorporates:
   *  UnitDelay: '<S254>/UD'
   *
   * Block description for '<S254>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S254>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Switch2_m - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S240>/Saturation' */
  if (rtb_Add_i > Steering_Motor_Control_D_UL) {
    rtb_Add_i = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_i < Steering_Motor_Control_D_LL) {
    rtb_Add_i = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S240>/Add' incorporates:
   *  Gain: '<S240>/Gain1'
   *  Saturate: '<S240>/Saturation'
   */
  rtb_Add_k = (Steering_Motor_Control_P * rtb_Derivative) + rtb_Add_i;

  /* Sum: '<S240>/Subtract' incorporates:
   *  Constant: '<S240>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_k;

  /* Sum: '<S240>/Sum2' incorporates:
   *  Gain: '<S240>/Gain2'
   *  UnitDelay: '<S240>/Unit Delay'
   */
  rtb_Sum2_oc = (Steering_Motor_Control_I * rtb_Derivative) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S256>/Switch2' incorporates:
   *  Constant: '<S240>/Constant'
   *  RelationalOperator: '<S256>/LowerRelop1'
   *  Sum: '<S240>/Subtract'
   */
  if (!(rtb_Sum2_oc > (1.0 - rtb_Add_k))) {
    /* Switch: '<S256>/Switch' incorporates:
     *  Constant: '<S240>/Constant1'
     *  RelationalOperator: '<S256>/UpperRelop'
     *  Sum: '<S240>/Subtract1'
     */
    if (rtb_Sum2_oc < (-1.0 - rtb_Add_k)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_k;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_oc;
    }

    /* End of Switch: '<S256>/Switch' */
  }

  /* End of Switch: '<S256>/Switch2' */

  /* Saturate: '<S240>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_oc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_oc = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S240>/Saturation1' */

  /* Sum: '<S240>/Add1' */
  rtb_Add_i = rtb_Add_k + rtb_Sum2_oc;

  /* Saturate: '<S240>/Saturation2' */
  if (rtb_Add_i > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_i < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_i;
  }

  /* End of Saturate: '<S240>/Saturation2' */

  /* Switch: '<S350>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S350>/Switch' incorporates:
     *  Fcn: '<S351>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2_idx_1,
      rtb_Add2_idx_0);
  }

  /* End of Switch: '<S350>/Switch' */

  /* Trigonometry: '<S270>/Cos4' incorporates:
   *  Switch: '<S259>/Angle_Switch'
   *  Trigonometry: '<S269>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S270>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S268>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S270>/Sin4' incorporates:
   *  Switch: '<S259>/Angle_Switch'
   *  Trigonometry: '<S269>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S270>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S268>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S270>/Subtract1' incorporates:
   *  Product: '<S270>/Product2'
   *  Product: '<S270>/Product3'
   *  Trigonometry: '<S270>/Cos4'
   *  Trigonometry: '<S270>/Sin4'
   */
  rtb_Derivative = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle
    * rtb_Optimized_Module_Angle_p);

  /* Sum: '<S270>/Subtract' incorporates:
   *  Product: '<S270>/Product'
   *  Product: '<S270>/Product1'
   *  Trigonometry: '<S270>/Cos4'
   *  Trigonometry: '<S270>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S270>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Derivative);

  /* Switch: '<S270>/Switch' incorporates:
   *  Constant: '<S270>/Constant'
   *  Constant: '<S270>/Constant1'
   *  Constant: '<S271>/Constant'
   *  Product: '<S270>/Divide'
   *  Product: '<S270>/Divide1'
   *  RelationalOperator: '<S271>/Compare'
   *  Switch: '<S270>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Derivative /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Derivative = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S270>/Switch' */

  /* Product: '<S335>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch4_e;

  /* Switch: '<S259>/Speed_Switch' incorporates:
   *  Abs: '<S259>/Abs'
   *  Constant: '<S267>/Constant'
   *  RelationalOperator: '<S267>/Compare'
   *  Switch: '<S259>/Angle_Switch'
   *  Trigonometry: '<S269>/Atan1'
   *  Trigonometry: '<S270>/Atan1'
   *  UnaryMinus: '<S259>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Derivative, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_i = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S269>/Subtract1' incorporates:
     *  Product: '<S269>/Product2'
     *  Product: '<S269>/Product3'
     *  UnaryMinus: '<S259>/Unary Minus'
     */
    rtb_Derivative = (rtb_Add_k * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S269>/Subtract' incorporates:
     *  Product: '<S269>/Product'
     *  Product: '<S269>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_k * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S269>/Hypot' */
    rtb_Add_k = rt_hypotd_snf(rtb_uDLookupTable, rtb_Derivative);

    /* Switch: '<S269>/Switch1' incorporates:
     *  Constant: '<S269>/Constant'
     *  Constant: '<S269>/Constant1'
     *  Constant: '<S272>/Constant'
     *  Product: '<S269>/Divide'
     *  Product: '<S269>/Divide1'
     *  RelationalOperator: '<S272>/Compare'
     *  Switch: '<S269>/Switch'
     */
    if (rtb_Add_k > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Add_k;
      rtb_Derivative /= rtb_Add_k;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Derivative = 0.0;
    }

    /* End of Switch: '<S269>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Derivative,
      rtb_uDLookupTable);
  } else {
    rtb_Add_i = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S262>/Product2' incorporates:
   *  Constant: '<S262>/Constant'
   *  Switch: '<S259>/Speed_Switch'
   */
  rtb_Switch4_e = rtb_Add_i * 1089.4195728820682;

  /* Signum: '<S257>/Sign' */
  if (rtIsNaN(rtb_Switch4_e)) {
    rtb_Add_i = (rtNaN);
  } else if (rtb_Switch4_e < 0.0) {
    rtb_Add_i = -1.0;
  } else {
    rtb_Add_i = (rtb_Switch4_e > 0.0);
  }

  /* Signum: '<S257>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S260>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S261>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S212>/Product' incorporates:
   *  Abs: '<S257>/Abs'
   *  Abs: '<S260>/Abs'
   *  Constant: '<S263>/Constant'
   *  Constant: '<S273>/Constant3'
   *  Constant: '<S273>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
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
  rtb_Switch4_e = (((real_T)((rtb_Add_i == rtb_Add_k) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch4_e) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S258>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Derivative = rtb_Switch4_e - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S265>/Sum1' incorporates:
   *  Constant: '<S258>/Constant2'
   *  Product: '<S265>/Product'
   *  Sum: '<S265>/Sum'
   *  UnitDelay: '<S265>/Unit Delay1'
   */
  rtb_Add_k = ((rtb_Derivative - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S258>/Product' incorporates:
   *  Constant: '<S258>/Constant3'
   */
  rtb_uDLookupTable = rtb_Add_k * Drive_Motor_Control_D;

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
  rtb_Add_i = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S258>/Saturation' */
  if (rtb_Add_i > Drive_Motor_Control_D_UL) {
    rtb_Add_i = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_i < Drive_Motor_Control_D_LL) {
    rtb_Add_i = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S258>/Add' incorporates:
   *  Gain: '<S258>/Gain'
   *  Gain: '<S258>/Gain1'
   *  Saturate: '<S258>/Saturation'
   */
  rtb_Switch4_e = ((Drive_Motor_Control_FF * rtb_Switch4_e) +
                   (Drive_Motor_Control_P * rtb_Derivative)) + rtb_Add_i;

  /* Saturate: '<S258>/Saturation2' incorporates:
   *  Sum: '<S258>/Add1'
   */
  if (rtb_Switch4_e > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch4_e < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Switch4_e;
  }

  /* End of Saturate: '<S258>/Saturation2' */

  /* Sum: '<S274>/Add1' incorporates:
   *  Constant: '<S274>/Constant3'
   *  Constant: '<S274>/Constant4'
   *  Math: '<S274>/Math Function'
   *  Sum: '<S274>/Add2'
   */
  rtb_Switch4_e = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S276>/Sum1' incorporates:
   *  Constant: '<S261>/Constant2'
   *  Product: '<S276>/Product'
   *  Sum: '<S276>/Sum'
   *  UnitDelay: '<S276>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch4_e -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S261>/Product' incorporates:
   *  Constant: '<S261>/Constant3'
   */
  rtb_Add2_idx_0 = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

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
  rtb_Add_i = rtb_Add2_idx_0 - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S261>/Saturation' */
  if (rtb_Add_i > Steering_Motor_Control_D_UL) {
    rtb_Add_i = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_i < Steering_Motor_Control_D_LL) {
    rtb_Add_i = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S261>/Add' incorporates:
   *  Gain: '<S261>/Gain1'
   *  Saturate: '<S261>/Saturation'
   */
  rtb_Add2_idx_1 = (Steering_Motor_Control_P * rtb_Switch4_e) + rtb_Add_i;

  /* Sum: '<S261>/Subtract' incorporates:
   *  Constant: '<S261>/Constant'
   */
  rtb_Derivative = 1.0 - rtb_Add2_idx_1;

  /* Sum: '<S261>/Sum2' incorporates:
   *  Gain: '<S261>/Gain2'
   *  UnitDelay: '<S261>/Unit Delay'
   */
  rtb_Switch4_e = (Steering_Motor_Control_I * rtb_Switch4_e) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S277>/Switch2' incorporates:
   *  Constant: '<S261>/Constant'
   *  RelationalOperator: '<S277>/LowerRelop1'
   *  Sum: '<S261>/Subtract'
   */
  if (!(rtb_Switch4_e > (1.0 - rtb_Add2_idx_1))) {
    /* Sum: '<S261>/Subtract1' incorporates:
     *  Constant: '<S261>/Constant1'
     */
    rtb_Derivative = -1.0 - rtb_Add2_idx_1;

    /* Switch: '<S277>/Switch' incorporates:
     *  Constant: '<S261>/Constant1'
     *  RelationalOperator: '<S277>/UpperRelop'
     *  Sum: '<S261>/Subtract1'
     */
    if (!(rtb_Switch4_e < (-1.0 - rtb_Add2_idx_1))) {
      rtb_Derivative = rtb_Switch4_e;
    }

    /* End of Switch: '<S277>/Switch' */
  }

  /* End of Switch: '<S277>/Switch2' */

  /* Saturate: '<S261>/Saturation1' */
  if (rtb_Derivative > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Derivative < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Derivative;
  }

  /* End of Saturate: '<S261>/Saturation1' */

  /* Sum: '<S261>/Add1' */
  rtb_Add_i = rtb_Add2_idx_1 + rtb_Integral_ga;

  /* Saturate: '<S261>/Saturation2' */
  if (rtb_Add_i > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_i < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_i;
  }

  /* End of Saturate: '<S261>/Saturation2' */

  /* Sum: '<S295>/Add1' incorporates:
   *  Constant: '<S295>/Constant3'
   *  Constant: '<S295>/Constant4'
   *  Math: '<S295>/Math Function'
   *  Sum: '<S295>/Add2'
   */
  rtb_Switch4_e = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S297>/Sum1' incorporates:
   *  Constant: '<S282>/Constant2'
   *  Product: '<S297>/Product'
   *  Sum: '<S297>/Sum'
   *  UnitDelay: '<S297>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch4_e -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S282>/Product' incorporates:
   *  Constant: '<S282>/Constant3'
   */
  rtb_Add2_idx_1 = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

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
  rtb_Add_i = rtb_Add2_idx_1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S282>/Saturation' */
  if (rtb_Add_i > Steering_Motor_Control_D_UL) {
    rtb_Add_i = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_i < Steering_Motor_Control_D_LL) {
    rtb_Add_i = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S282>/Add' incorporates:
   *  Gain: '<S282>/Gain1'
   *  Saturate: '<S282>/Saturation'
   */
  rtb_Add_jp = (Steering_Motor_Control_P * rtb_Switch4_e) + rtb_Add_i;

  /* Sum: '<S282>/Subtract' incorporates:
   *  Constant: '<S282>/Constant'
   */
  rtb_Derivative = 1.0 - rtb_Add_jp;

  /* Sum: '<S282>/Sum2' incorporates:
   *  Gain: '<S282>/Gain2'
   *  UnitDelay: '<S282>/Unit Delay'
   */
  rtb_Switch4_e = (Steering_Motor_Control_I * rtb_Switch4_e) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S298>/Switch2' incorporates:
   *  Constant: '<S282>/Constant'
   *  RelationalOperator: '<S298>/LowerRelop1'
   *  Sum: '<S282>/Subtract'
   */
  if (!(rtb_Switch4_e > (1.0 - rtb_Add_jp))) {
    /* Sum: '<S282>/Subtract1' incorporates:
     *  Constant: '<S282>/Constant1'
     */
    rtb_Derivative = -1.0 - rtb_Add_jp;

    /* Switch: '<S298>/Switch' incorporates:
     *  Constant: '<S282>/Constant1'
     *  RelationalOperator: '<S298>/UpperRelop'
     *  Sum: '<S282>/Subtract1'
     */
    if (!(rtb_Switch4_e < (-1.0 - rtb_Add_jp))) {
      rtb_Derivative = rtb_Switch4_e;
    }

    /* End of Switch: '<S298>/Switch' */
  }

  /* End of Switch: '<S298>/Switch2' */

  /* Saturate: '<S282>/Saturation1' */
  if (rtb_Derivative > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Derivative < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Derivative;
  }

  /* End of Saturate: '<S282>/Saturation1' */

  /* Sum: '<S282>/Add1' */
  rtb_Add_i = rtb_Add_jp + rtb_Integral_bj;

  /* Saturate: '<S282>/Saturation2' */
  if (rtb_Add_i > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_i < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_i;
  }

  /* End of Saturate: '<S282>/Saturation2' */

  /* Sum: '<S145>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S107>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S147>/Sum1' incorporates:
   *  Constant: '<S145>/Constant2'
   *  Product: '<S147>/Product'
   *  Sum: '<S145>/Sum'
   *  Sum: '<S147>/Sum'
   *  UnitDelay: '<S147>/Unit Delay1'
   */
  rtb_Add_jp = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S145>/Product' incorporates:
   *  Constant: '<S145>/Constant3'
   */
  rtb_Product_lu = rtb_Add_jp * 0.0;

  /* Sum: '<S146>/Diff' incorporates:
   *  UnitDelay: '<S146>/UD'
   *
   * Block description for '<S146>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S146>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Product_lu - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S145>/Saturation' */
  if (rtb_Add_i > 0.1) {
    rtb_Add_i = 0.1;
  } else if (rtb_Add_i < -0.1) {
    rtb_Add_i = -0.1;
  }

  /* Sum: '<S145>/Add' incorporates:
   *  Gain: '<S145>/Gain'
   *  Gain: '<S145>/Gain1'
   *  Saturate: '<S145>/Saturation'
   *  Sum: '<S145>/Sum'
   */
  rtb_Switch4_e = ((Rebuilt_Transfer_Motor_Gain_FF *
                    Robot_Control_B.RB_Desired_Transfer_Speed) +
                   (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_i;

  /* Logic: '<S107>/Logical Operator1' incorporates:
   *  Constant: '<S144>/Constant'
   *  RelationalOperator: '<S144>/Compare'
   */
  rtb_AND1_c = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S107>/Switch1' incorporates:
   *  Abs: '<S107>/Abs'
   *  Constant: '<S107>/Constant1'
   *  Constant: '<S107>/Constant2'
   *  Logic: '<S107>/Logical Operator'
   *  Logic: '<S107>/Logical Operator1'
   *  RelationalOperator: '<S107>/LessThan'
   *  UnitDelay: '<S107>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_AND1_c) {
    rtb_Compare_a = true;
  } else {
    rtb_Compare_a = (rtb_AND1_c && (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S107>/Switch1' */

  /* Switch: '<S145>/Switch' incorporates:
   *  Constant: '<S145>/Constant4'
   */
  if (rtb_Compare_a) {
    /* Sum: '<S145>/Sum2' incorporates:
     *  Gain: '<S145>/Gain2'
     *  Sum: '<S145>/Sum'
     *  UnitDelay: '<S145>/Unit Delay'
     */
    rtb_Derivative = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S145>/Subtract' incorporates:
     *  Constant: '<S145>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Switch4_e;

    /* Switch: '<S148>/Switch2' incorporates:
     *  Constant: '<S145>/Constant'
     *  RelationalOperator: '<S148>/LowerRelop1'
     *  Sum: '<S145>/Subtract'
     */
    if (!(rtb_Derivative > (1.0 - rtb_Switch4_e))) {
      /* Sum: '<S145>/Subtract1' incorporates:
       *  Constant: '<S145>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Switch4_e;

      /* Switch: '<S148>/Switch' incorporates:
       *  Constant: '<S145>/Constant1'
       *  RelationalOperator: '<S148>/UpperRelop'
       *  Sum: '<S145>/Subtract1'
       */
      if (!(rtb_Derivative < (-1.0 - rtb_Switch4_e))) {
        rtb_Integral_d = rtb_Derivative;
      }

      /* End of Switch: '<S148>/Switch' */
    }

    /* End of Switch: '<S148>/Switch2' */

    /* Saturate: '<S145>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S145>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S145>/Switch' */

  /* Switch: '<S107>/Switch2' incorporates:
   *  Logic: '<S107>/Logical Operator1'
   */
  if (rtb_AND1_c) {
    /* Sum: '<S145>/Add1' */
    rtb_Add_i = rtb_Switch4_e + rtb_Integral_d;

    /* Saturate: '<S145>/Saturation2' */
    if (rtb_Add_i > 1.0) {
      /* Switch: '<S107>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_i < -1.0) {
      /* Switch: '<S107>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S107>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_i;
    }

    /* End of Saturate: '<S145>/Saturation2' */
  } else {
    /* Switch: '<S107>/Switch2' incorporates:
     *  Constant: '<S107>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S107>/Switch2' */

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
    rtb_Switch4_e = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Transfer_Motor_DC' */
    Robot_Control_Y.Transfer_Motor_DC = Robot_Control_B.RB_Transfer_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S10>/Constant8'
     */
    Robot_Control_Y.Desired_Hood_Enable = true;

    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;
    rtb_Switch4_e = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Saturate: '<S10>/Saturation' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (rtb_Switch4_e > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Switch4_e = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Switch4_e < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Switch4_e = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Switch4_e;

  /* Switch: '<S99>/Init' incorporates:
   *  UnitDelay: '<S99>/FixPt Unit Delay1'
   *  UnitDelay: '<S99>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Derivative = rtb_Switch4_e;
  } else {
    rtb_Derivative = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S99>/Init' */

  /* Sum: '<S97>/Sum1' */
  rtb_Switch4_e -= rtb_Derivative;

  /* Switch: '<S98>/Switch2' incorporates:
   *  Constant: '<S96>/Constant1'
   *  Constant: '<S96>/Constant3'
   *  RelationalOperator: '<S98>/LowerRelop1'
   *  RelationalOperator: '<S98>/UpperRelop'
   *  Switch: '<S98>/Switch'
   */
  if (rtb_Switch4_e > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch4_e = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch4_e < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S96>/Constant1'
     */
    rtb_Switch4_e = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S98>/Switch2' */

  /* Sum: '<S97>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Switch4_e + rtb_Derivative;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  if (rtb_LogicalOperator1_n) {
    rtb_Switch4_e = Rebuilt_Roller_Desired_Speed;
  } else {
    rtb_Switch4_e = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S31>/Logical Operator1' incorporates:
   *  Constant: '<S37>/Constant'
   *  RelationalOperator: '<S37>/Compare'
   */
  rtb_LogicalOperator1_n = !(rtb_Switch4_e == 0.0);

  /* Sum: '<S38>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Roller_Speed'
   *  Sum: '<S31>/Subtract'
   */
  rtb_Error_n = rtb_Switch4_e - Robot_Control_U.Measured_Intake_Roller_Speed;

  /* Sum: '<S40>/Sum1' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Product: '<S40>/Product'
   *  Sum: '<S38>/Sum'
   *  Sum: '<S40>/Sum'
   *  UnitDelay: '<S40>/Unit Delay1'
   */
  rtb_Derivative = ((rtb_Error_n - Robot_Control_DW.UnitDelay1_DSTATE_g) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_g;

  /* Product: '<S38>/Product' incorporates:
   *  Constant: '<S38>/Constant3'
   */
  rtb_Product_m5 = rtb_Derivative * 0.0;

  /* Sum: '<S39>/Diff' incorporates:
   *  UnitDelay: '<S39>/UD'
   *
   * Block description for '<S39>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S39>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Product_m5 - Robot_Control_DW.UD_DSTATE_jd;

  /* Saturate: '<S38>/Saturation' */
  if (rtb_Add_i > 0.1) {
    rtb_Add_i = 0.1;
  } else if (rtb_Add_i < -0.1) {
    rtb_Add_i = -0.1;
  }

  /* Sum: '<S38>/Add' incorporates:
   *  Gain: '<S38>/Gain'
   *  Gain: '<S38>/Gain1'
   *  Saturate: '<S38>/Saturation'
   *  Sum: '<S38>/Sum'
   */
  rtb_Add_ec = ((Rebuilt_Roller_Motor_Gain_FF * rtb_Switch4_e) +
                (Rebuilt_Roller_Motor_Gain_P * rtb_Error_n)) + rtb_Add_i;

  /* Switch: '<S31>/Switch1' incorporates:
   *  Abs: '<S31>/Abs'
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S31>/Constant2'
   *  Logic: '<S31>/Logical Operator'
   *  Logic: '<S31>/Logical Operator1'
   *  RelationalOperator: '<S31>/LessThan'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  if ((fabs(rtb_Error_n) < Rebuilt_Roller_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_AND1_c = true;
  } else {
    rtb_AND1_c = (rtb_LogicalOperator1_n && (Robot_Control_DW.UnitDelay_DSTATE_n));
  }

  /* End of Switch: '<S31>/Switch1' */

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant4'
   */
  if (rtb_AND1_c) {
    /* Sum: '<S38>/Sum2' incorporates:
     *  Gain: '<S38>/Gain2'
     *  Sum: '<S38>/Sum'
     *  UnitDelay: '<S38>/Unit Delay'
     */
    rtb_Switch4_e = (Rebuilt_Roller_Motor_Gain_I * rtb_Error_n) +
      Robot_Control_DW.UnitDelay_DSTATE_dl;

    /* Sum: '<S38>/Subtract' incorporates:
     *  Constant: '<S38>/Constant'
     */
    rtb_Error_n = 1.0 - rtb_Add_ec;

    /* Switch: '<S41>/Switch2' incorporates:
     *  Constant: '<S38>/Constant'
     *  RelationalOperator: '<S41>/LowerRelop1'
     *  Sum: '<S38>/Subtract'
     */
    if (!(rtb_Switch4_e > (1.0 - rtb_Add_ec))) {
      /* Sum: '<S38>/Subtract1' incorporates:
       *  Constant: '<S38>/Constant1'
       */
      rtb_Error_n = -1.0 - rtb_Add_ec;

      /* Switch: '<S41>/Switch' incorporates:
       *  Constant: '<S38>/Constant1'
       *  RelationalOperator: '<S41>/UpperRelop'
       *  Sum: '<S38>/Subtract1'
       */
      if (!(rtb_Switch4_e < (-1.0 - rtb_Add_ec))) {
        rtb_Error_n = rtb_Switch4_e;
      }

      /* End of Switch: '<S41>/Switch' */
    }

    /* End of Switch: '<S41>/Switch2' */

    /* Saturate: '<S38>/Saturation1' */
    if (rtb_Error_n > 0.1) {
      rtb_Switch4_e = 0.1;
    } else if (rtb_Error_n < -0.1) {
      rtb_Switch4_e = -0.1;
    } else {
      rtb_Switch4_e = rtb_Error_n;
    }

    /* End of Saturate: '<S38>/Saturation1' */
  } else {
    rtb_Switch4_e = 0.0;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Switch: '<S31>/Switch2' incorporates:
   *  Logic: '<S31>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S38>/Add1' */
    rtb_Add_i = rtb_Add_ec + rtb_Switch4_e;

    /* Saturate: '<S38>/Saturation2' */
    if (rtb_Add_i > 1.0) {
      /* Switch: '<S31>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 1.0;
    } else if (rtb_Add_i < -1.0) {
      /* Switch: '<S31>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S31>/Switch2' */
      Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = rtb_Add_i;
    }

    /* End of Saturate: '<S38>/Saturation2' */
  } else {
    /* Switch: '<S31>/Switch2' incorporates:
     *  Constant: '<S31>/Constant3'
     */
    Robot_Control_B.RB_Intake_Roller_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S31>/Switch2' */

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

  /* Logic: '<S30>/Logical Operator1' incorporates:
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S32>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Des_Intake_Arm_Angle == 0.0);

  /* Sum: '<S33>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Intake_Arm_Angle'
   *  Sum: '<S30>/Subtract'
   */
  rtb_Error_e = Robot_Control_B.RB_Des_Intake_Arm_Angle -
    Robot_Control_U.Measured_Intake_Arm_Angle;

  /* Sum: '<S35>/Sum1' incorporates:
   *  Constant: '<S33>/Constant2'
   *  Product: '<S35>/Product'
   *  Sum: '<S33>/Sum'
   *  Sum: '<S35>/Sum'
   *  UnitDelay: '<S35>/Unit Delay1'
   */
  rtb_Add_ec = ((rtb_Error_e - Robot_Control_DW.UnitDelay1_DSTATE_l) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_l;

  /* Product: '<S33>/Product' incorporates:
   *  Constant: '<S33>/Constant3'
   */
  rtb_Error_n = rtb_Add_ec * Rebuilt_Intake_Arm_Gain_D;

  /* Sum: '<S34>/Diff' incorporates:
   *  UnitDelay: '<S34>/UD'
   *
   * Block description for '<S34>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S34>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Error_n - Robot_Control_DW.UD_DSTATE_d;

  /* Saturate: '<S33>/Saturation' */
  if (rtb_Add_i > 0.1) {
    rtb_Add_i = 0.1;
  } else if (rtb_Add_i < -0.1) {
    rtb_Add_i = -0.1;
  }

  /* Sum: '<S33>/Add' incorporates:
   *  Gain: '<S33>/Gain'
   *  Gain: '<S33>/Gain1'
   *  Saturate: '<S33>/Saturation'
   *  Sum: '<S33>/Sum'
   */
  rtb_Add_is = ((0.0 * Robot_Control_B.RB_Des_Intake_Arm_Angle) +
                (Rebuilt_Intake_Arm_Gain_P * rtb_Error_e)) + rtb_Add_i;

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

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Constant4'
   */
  if (rtb_Intake_Arm_Move_In) {
    /* Sum: '<S33>/Sum2' incorporates:
     *  Gain: '<S33>/Gain2'
     *  Sum: '<S33>/Sum'
     *  UnitDelay: '<S33>/Unit Delay'
     */
    rtb_Error_e = (Rebuilt_Intake_Arm_Gain_I * rtb_Error_e) +
      Robot_Control_DW.UnitDelay_DSTATE_ej;

    /* Sum: '<S33>/Subtract' incorporates:
     *  Constant: '<S33>/Constant'
     */
    rtb_Switch2_ku = 1.0 - rtb_Add_is;

    /* Switch: '<S36>/Switch2' incorporates:
     *  Constant: '<S33>/Constant'
     *  RelationalOperator: '<S36>/LowerRelop1'
     *  Sum: '<S33>/Subtract'
     */
    if (!(rtb_Error_e > (1.0 - rtb_Add_is))) {
      /* Sum: '<S33>/Subtract1' incorporates:
       *  Constant: '<S33>/Constant1'
       */
      rtb_Switch2_ku = -1.0 - rtb_Add_is;

      /* Switch: '<S36>/Switch' incorporates:
       *  Constant: '<S33>/Constant1'
       *  RelationalOperator: '<S36>/UpperRelop'
       *  Sum: '<S33>/Subtract1'
       */
      if (!(rtb_Error_e < (-1.0 - rtb_Add_is))) {
        rtb_Switch2_ku = rtb_Error_e;
      }

      /* End of Switch: '<S36>/Switch' */
    }

    /* End of Switch: '<S36>/Switch2' */

    /* Saturate: '<S33>/Saturation1' */
    if (rtb_Switch2_ku > 0.1) {
      rtb_Error_e = 0.1;
    } else if (rtb_Switch2_ku < -0.1) {
      rtb_Error_e = -0.1;
    } else {
      rtb_Error_e = rtb_Switch2_ku;
    }

    /* End of Saturate: '<S33>/Saturation1' */
  } else {
    rtb_Error_e = 0.0;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Switch: '<S30>/Switch2' incorporates:
   *  Logic: '<S30>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S33>/Add1' */
    rtb_Add_i = rtb_Add_is + rtb_Error_e;

    /* Saturate: '<S33>/Saturation2' */
    if (rtb_Add_i > 1.0) {
      /* Switch: '<S30>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = 1.0;
    } else if (rtb_Add_i < -1.0) {
      /* Switch: '<S30>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S30>/Switch2' */
      Robot_Control_B.RB_Intake_Arm_Motor_PID_DC = rtb_Add_i;
    }

    /* End of Saturate: '<S33>/Saturation2' */
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

  /* Logic: '<S105>/Logical Operator1' incorporates:
   *  Constant: '<S139>/Constant'
   *  RelationalOperator: '<S139>/Compare'
   */
  rtb_LogicalOperator1_n = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S140>/Sum' incorporates:
   *  Sum: '<S105>/Subtract'
   */
  rtb_Error_b = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S142>/Sum1' incorporates:
   *  Constant: '<S140>/Constant2'
   *  Product: '<S142>/Product'
   *  Sum: '<S140>/Sum'
   *  Sum: '<S142>/Sum'
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  rtb_Add_is = ((rtb_Error_b - Robot_Control_DW.UnitDelay1_DSTATE_d) * 0.1) +
    Robot_Control_DW.UnitDelay1_DSTATE_d;

  /* Product: '<S140>/Product' incorporates:
   *  Constant: '<S140>/Constant3'
   */
  rtb_Switch2_ku = rtb_Add_is * 0.0;

  /* Sum: '<S141>/Diff' incorporates:
   *  UnitDelay: '<S141>/UD'
   *
   * Block description for '<S141>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S141>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_i = rtb_Switch2_ku - Robot_Control_DW.UD_DSTATE_ml;

  /* Saturate: '<S140>/Saturation' */
  if (rtb_Add_i > 0.1) {
    rtb_Add_i = 0.1;
  } else if (rtb_Add_i < -0.1) {
    rtb_Add_i = -0.1;
  }

  /* Sum: '<S140>/Add' incorporates:
   *  Gain: '<S140>/Gain'
   *  Gain: '<S140>/Gain1'
   *  Saturate: '<S140>/Saturation'
   *  Sum: '<S140>/Sum'
   */
  rtb_Add_i += (Rebuilt_Shooter_Motor_Gain_FF *
                Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Error_b);

  /* Switch: '<S105>/Switch1' incorporates:
   *  Abs: '<S105>/Abs'
   *  Constant: '<S105>/Constant1'
   *  Constant: '<S105>/Constant2'
   *  Logic: '<S105>/Logical Operator'
   *  Logic: '<S105>/Logical Operator1'
   *  RelationalOperator: '<S105>/LessThan'
   *  UnitDelay: '<S105>/Unit Delay'
   */
  if ((fabs(rtb_Error_b) < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_LogicalOperator1_n) {
    rtb_Intake_Arm_Move_Out = true;
  } else {
    rtb_Intake_Arm_Move_Out = (rtb_LogicalOperator1_n &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S105>/Switch1' */

  /* Switch: '<S140>/Switch' incorporates:
   *  Constant: '<S140>/Constant4'
   */
  if (rtb_Intake_Arm_Move_Out) {
    /* Sum: '<S140>/Sum2' incorporates:
     *  Gain: '<S140>/Gain2'
     *  Sum: '<S140>/Sum'
     *  UnitDelay: '<S140>/Unit Delay'
     */
    rtb_Error_b = (Rebuilt_Shooter_Motor_Gain_I * rtb_Error_b) +
      Robot_Control_DW.UnitDelay_DSTATE_di;

    /* Sum: '<S140>/Subtract' incorporates:
     *  Constant: '<S140>/Constant'
     */
    rtb_Switch2_ox = 1.0 - rtb_Add_i;

    /* Switch: '<S143>/Switch2' incorporates:
     *  Constant: '<S140>/Constant'
     *  RelationalOperator: '<S143>/LowerRelop1'
     *  Sum: '<S140>/Subtract'
     */
    if (!(rtb_Error_b > (1.0 - rtb_Add_i))) {
      /* Sum: '<S140>/Subtract1' incorporates:
       *  Constant: '<S140>/Constant1'
       */
      rtb_Switch2_ox = -1.0 - rtb_Add_i;

      /* Switch: '<S143>/Switch' incorporates:
       *  Constant: '<S140>/Constant1'
       *  RelationalOperator: '<S143>/UpperRelop'
       *  Sum: '<S140>/Subtract1'
       */
      if (!(rtb_Error_b < (-1.0 - rtb_Add_i))) {
        rtb_Switch2_ox = rtb_Error_b;
      }

      /* End of Switch: '<S143>/Switch' */
    }

    /* End of Switch: '<S143>/Switch2' */

    /* Saturate: '<S140>/Saturation1' */
    if (rtb_Switch2_ox > 0.1) {
      rtb_Error_b = 0.1;
    } else if (rtb_Switch2_ox < -0.1) {
      rtb_Error_b = -0.1;
    } else {
      rtb_Error_b = rtb_Switch2_ox;
    }

    /* End of Saturate: '<S140>/Saturation1' */
  } else {
    rtb_Error_b = 0.0;
  }

  /* End of Switch: '<S140>/Switch' */

  /* Switch: '<S105>/Switch2' incorporates:
   *  Logic: '<S105>/Logical Operator1'
   */
  if (rtb_LogicalOperator1_n) {
    /* Sum: '<S140>/Add1' */
    rtb_Add_i += rtb_Error_b;

    /* Saturate: '<S140>/Saturation2' */
    if (rtb_Add_i > 1.0) {
      /* Switch: '<S105>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_i < -1.0) {
      /* Switch: '<S105>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S105>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_i;
    }

    /* End of Saturate: '<S140>/Saturation2' */
  } else {
    /* Switch: '<S105>/Switch2' incorporates:
     *  Constant: '<S105>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S105>/Switch2' */

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

  /* Update for Delay: '<S42>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S62>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S42>/A'
   *  Delay: '<S42>/MemoryX'
   */
  rtb_Add_i = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Switch2_ox = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S42>/MemoryX' incorporates:
   *  Constant: '<S42>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S62>/A[k]*xhat[k|k-1]'
   *  Product: '<S62>/B[k]*u[k]'
   *  Sum: '<S62>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Add_i) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Switch2_ox) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S310>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S310>/FixPt Constant'
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

  /* Update for UnitDelay: '<S101>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S332>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S331>/UD'
   *
   * Block description for '<S331>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Add_h5;

  /* Update for UnitDelay: '<S329>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Switch4;

  /* Update for UnitDelay: '<S312>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Init_o;

  /* Update for UnitDelay: '<S327>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S327>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S327>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S311>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S320>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S320>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S320>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S286>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S285>/UD'
   *
   * Block description for '<S285>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2;

  /* Update for UnitDelay: '<S279>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S223>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S222>/UD'
   *
   * Block description for '<S222>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Init;

  /* Update for UnitDelay: '<S216>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S234>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S233>/UD'
   *
   * Block description for '<S233>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_dp;

  /* Update for UnitDelay: '<S219>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S244>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_fn;

  /* Update for UnitDelay: '<S243>/UD'
   *
   * Block description for '<S243>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S237>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S255>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_b;

  /* Update for UnitDelay: '<S254>/UD'
   *
   * Block description for '<S254>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Switch2_m;

  /* Update for UnitDelay: '<S240>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Sum2_oc;

  /* Update for UnitDelay: '<S265>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_k;

  /* Update for UnitDelay: '<S264>/UD'
   *
   * Block description for '<S264>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S258>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S276>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S275>/UD'
   *
   * Block description for '<S275>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Add2_idx_0;

  /* Update for UnitDelay: '<S261>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S297>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S296>/UD'
   *
   * Block description for '<S296>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add2_idx_1;

  /* Update for UnitDelay: '<S282>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S147>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_jp;

  /* Update for UnitDelay: '<S146>/UD'
   *
   * Block description for '<S146>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lu;

  /* Update for UnitDelay: '<S145>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S107>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Compare_a;

  /* Update for UnitDelay: '<S99>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S99>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S40>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_g = rtb_Derivative;

  /* Update for UnitDelay: '<S39>/UD'
   *
   * Block description for '<S39>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_jd = rtb_Product_m5;

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dl = rtb_Switch4_e;

  /* Update for UnitDelay: '<S31>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_AND1_c;

  /* Update for UnitDelay: '<S29>/Delay Input1'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_c = rtb_Intake_Arm_Cycle;

  /* Update for UnitDelay: '<S35>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Add_ec;

  /* Update for UnitDelay: '<S34>/UD'
   *
   * Block description for '<S34>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_d = rtb_Error_n;

  /* Update for UnitDelay: '<S33>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ej = rtb_Error_e;

  /* Update for UnitDelay: '<S30>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dvn = rtb_Intake_Arm_Move_In;

  /* Update for UnitDelay: '<S142>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_d = rtb_Add_is;

  /* Update for UnitDelay: '<S141>/UD'
   *
   * Block description for '<S141>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_ml = rtb_Switch2_ku;

  /* Update for UnitDelay: '<S140>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Error_b;

  /* Update for UnitDelay: '<S105>/Unit Delay' */
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

  /* InitializeConditions for Delay: '<S42>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S310>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S327>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S320>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S99>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S385>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Spline Path Following Enabled' */
  /* Start for If: '<S155>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S151>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S155>/Robot_Index_Is_Valid' */
  /* Start for If: '<S158>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S158>/Circle_Check_Valid' */
  /* Start for If: '<S160>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S158>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S155>/Robot_Index_Is_Valid' */
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
