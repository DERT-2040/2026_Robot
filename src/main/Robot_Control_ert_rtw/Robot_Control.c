/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.452
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 23 18:39:09 2026
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

/* Named constants for Chart: '<S10>/Chart' */
#define Robot_Contro_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Robot_Control_IN_Disabled      ((uint8_T)1U)
#define Robot_Control_IN_Not_Disabled  ((uint8_T)2U)

/* Named constants for Chart: '<S11>/Shooter_Transfer_Feeder Chart' */
#define Robot_Control_IN_Feeder        ((uint8_T)1U)
#define Robot_Control_IN_Not_Shooting  ((uint8_T)1U)
#define Robot_Control_IN_Shooting      ((uint8_T)2U)
#define Robot_Control_IN_Spinning_Up   ((uint8_T)2U)
#define Robot_Control_IN_Transfer      ((uint8_T)3U)

/* Exported block parameters */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S363>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S359>/Constant'
                                        *   '<S359>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S363>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S359>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S201>/Constant3'
                                        *   '<S222>/Constant3'
                                        *   '<S243>/Constant3'
                                        *   '<S264>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S201>/Constant2'
                                   *   '<S222>/Constant2'
                                   *   '<S243>/Constant2'
                                   *   '<S264>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S201>/Saturation'
                                        *   '<S222>/Saturation'
                                        *   '<S243>/Saturation'
                                        *   '<S264>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S201>/Saturation'
                                        *   '<S222>/Saturation'
                                        *   '<S243>/Saturation'
                                        *   '<S264>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S201>/Gain'
                                            *   '<S222>/Gain'
                                            *   '<S243>/Gain'
                                            *   '<S264>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S201>/Gain2'
                                        *   '<S222>/Gain2'
                                        *   '<S243>/Gain2'
                                        *   '<S264>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S201>/Saturation1'
                                         *   '<S222>/Saturation1'
                                         *   '<S243>/Saturation1'
                                         *   '<S264>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S201>/Saturation1'
                                        *   '<S222>/Saturation1'
                                        *   '<S243>/Saturation1'
                                        *   '<S264>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S201>/Gain1'
                                        *   '<S222>/Gain1'
                                        *   '<S243>/Gain1'
                                        *   '<S264>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S206>/Constant'
                            *   '<S227>/Constant'
                            *   '<S248>/Constant'
                            *   '<S269>/Constant'
                            */
real_T Field_BlueAllianceZoneX = 4.6256;/* Variable: Field_BlueAllianceZoneX
                                         * Referenced by:
                                         *   '<S120>/BlueAllianceZoneX'
                                         *   '<S122>/BlueAllianceZoneX'
                                         */
real_T Field_Blue_Hub_X = 4.6256;      /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S101>/Constant'
                                        */
real_T Field_Blue_Hub_Y = 4.0345;      /* Variable: Field_Blue_Hub_Y
                                        * Referenced by: '<S101>/Constant1'
                                        */
real_T Field_RedAllianceZoneX = 11.9154;/* Variable: Field_RedAllianceZoneX
                                         * Referenced by:
                                         *   '<S121>/RedAllianceZoneX'
                                         *   '<S123>/RedAllianceZoneX'
                                         */
real_T Field_Red_Hub_X = 11.9154;      /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S101>/Constant2'
                                        */
real_T Field_Red_Hub_Y = 4.0345;       /* Variable: Field_Red_Hub_Y
                                        * Referenced by: '<S101>/Constant3'
                                        */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S349>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S349>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S7>/Constant1'
                                        *   '<S7>/Constant2'
                                        */
real_T Rebuilt_Des_Gyro_Shoot_Offset = -1.0;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S96>/Constant'
                                       */
real_T Rebuilt_Feeder_Motor_Gain_FF = 0.00012732;/* Variable: Rebuilt_Feeder_Motor_Gain_FF
                                                  * Referenced by: '<S11>/Constant'
                                                  */
real_T Rebuilt_Hood_Servo_Pos_Max = 1.0;/* Variable: Rebuilt_Hood_Servo_Pos_Max
                                         * Referenced by: '<S9>/Saturation'
                                         */
real_T Rebuilt_Hood_Servo_Pos_Min = 0.05;/* Variable: Rebuilt_Hood_Servo_Pos_Min
                                          * Referenced by: '<S9>/Saturation'
                                          */
real_T Rebuilt_Hood_Servo_Rate_Limit_Dec = -0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S81>/Constant1'
                                   */
real_T Rebuilt_Hood_Servo_Rate_Limit_Inc = 0.0128;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S81>/Constant3'
                                   */
real_T Rebuilt_Shoot_Dist_0 = 1.37;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S102>/Constant5'
                                        */
real_T Rebuilt_Shoot_Dist_1 = 2.12;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S102>/Constant6'
                                        */
real_T Rebuilt_Shoot_Dist_2 = 3.115;   /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S102>/Constant7'
                                        */
real_T Rebuilt_Shoot_Dist_3 = 3.692;   /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S102>/Constant8'
                                        */
real_T Rebuilt_Shoot_Dist_4 = 4.353;   /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S102>/Constant9'
                                        */
real_T Rebuilt_Shoot_Dist_5 = 4.884;   /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S102>/Constant10'
                                        */
real_T Rebuilt_Shoot_Dist_6 = 5.6;     /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S102>/Constant2'
                                        */
real_T Rebuilt_Shoot_Dist_7 = 6.5;     /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S102>/Constant1'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_0 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S98>/Constant5'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_1 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S98>/Constant6'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_2 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S98>/Constant7'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_3 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S98>/Constant8'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_4 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S98>/Constant9'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_5 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S98>/Constant10'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_6 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S98>/Constant2'
                                        */
real_T Rebuilt_Shoot_Gyro_Err_7 = 5.0; /* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S98>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_0 = 0.05;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S99>/Constant5'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_1 = 0.2; /* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S99>/Constant6'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_2 = 0.35;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S99>/Constant7'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_3 = 0.4; /* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S99>/Constant8'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_4 = 0.45;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S99>/Constant9'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_5 = 0.5; /* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S99>/Constant10'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_6 = 0.58;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S99>/Constant2'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_7 = 0.62;/* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S99>/Constant1'
                                        */
real_T Rebuilt_Shoot_Hood_Pos_Max_Error = 0.03;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S89>/Constant1'
                                    */
real_T Rebuilt_Shoot_Motor_Max_Error = 100.0;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S89>/Constant2'
                                       */
real_T Rebuilt_Shoot_Robot_Velocity_Max = 1.0;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S89>/Constant'
                                    */
real_T Rebuilt_Shoot_Shooter_Spd_0 = 2500.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                             * Referenced by: '<S100>/Constant5'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_1 = 2800.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                             * Referenced by: '<S100>/Constant6'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_2 = 3100.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                             * Referenced by: '<S100>/Constant7'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_3 = 3200.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                             * Referenced by: '<S100>/Constant8'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_4 = 3400.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                             * Referenced by: '<S100>/Constant9'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_5 = 3550.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                             * Referenced by: '<S100>/Constant10'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_6 = 3800.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                             * Referenced by: '<S100>/Constant2'
                                             */
real_T Rebuilt_Shoot_Shooter_Spd_7 = 4000.0;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                             * Referenced by: '<S100>/Constant1'
                                             */
real_T Rebuilt_Shoot_TOF_0 = 0.943;    /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S105>/Constant'
                                        */
real_T Rebuilt_Shoot_TOF_1 = 1.092;    /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S105>/Constant1'
                                        */
real_T Rebuilt_Shoot_TOF_2 = 1.167;    /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S105>/Constant2'
                                        */
real_T Rebuilt_Shoot_TOF_3 = 1.185;    /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S105>/Constant3'
                                        */
real_T Rebuilt_Shoot_TOF_4 = 1.25;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S105>/Constant4'
                                        */
real_T Rebuilt_Shoot_TOF_5 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S105>/Constant11'
                                        */
real_T Rebuilt_Shoot_TOF_6 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S105>/Constant6'
                                        */
real_T Rebuilt_Shoot_TOF_7 = 1.337;    /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S105>/Constant5'
                                        */
real_T Rebuilt_Shoot_Target_Error_Thresh = 0.1;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S109>/Constant'
                                   */
real_T Rebuilt_Shooter_Error_Integral_Enable = 300.0;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S90>/Constant1'
                               */
real_T Rebuilt_Shooter_Motor_Gain_FF = 0.00016534;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S125>/Gain'
                                       */
real_T Rebuilt_Shooter_Motor_Gain_I = 2.0E-5;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                              * Referenced by: '<S125>/Gain2'
                                              */
real_T Rebuilt_Shooter_Motor_Gain_P = 0.0005;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                              * Referenced by: '<S125>/Gain1'
                                              */
real_T Rebuilt_Target_Feeder_Speed = 3360.0;/* Variable: Rebuilt_Target_Feeder_Speed
                                             * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                             */
real_T Rebuilt_Target_Transfer_Speed = 4000.0;
                                      /* Variable: Rebuilt_Target_Transfer_Speed
                                       * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                       */
real_T Rebuilt_Transfer_Error_Integral_Enable = 300.0;
                             /* Variable: Rebuilt_Transfer_Error_Integral_Enable
                              * Referenced by: '<S92>/Constant1'
                              */
real_T Rebuilt_Transfer_Minimum_Factor = 0.8;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                     */
real_T Rebuilt_Transfer_Motor_Gain_FF = 0.00012732;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S130>/Gain'
                                      */
real_T Rebuilt_Transfer_Motor_Gain_I = 2.0E-5;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S130>/Gain2'
                                       */
real_T Rebuilt_Transfer_Motor_Gain_P = 0.0001;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S130>/Gain1'
                                       */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S348>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S346>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S348>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S349>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S349>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S190>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S190>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S137>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S150>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S190>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S297>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S297>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S297>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S297>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S297>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S297>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S314>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S314>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S314>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S314>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S313>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S314>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S314>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S314>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S314>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S314>/Constant1'
                                   *   '<S314>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S314>/Constant'
                                   *   '<S314>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S204>/Constant3'
                                        *   '<S225>/Constant3'
                                        *   '<S246>/Constant3'
                                        *   '<S267>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S204>/Constant2'
                                *   '<S225>/Constant2'
                                *   '<S246>/Constant2'
                                *   '<S267>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S204>/Saturation'
                                           *   '<S225>/Saturation'
                                           *   '<S246>/Saturation'
                                           *   '<S267>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S204>/Saturation'
                                          *   '<S225>/Saturation'
                                          *   '<S246>/Saturation'
                                          *   '<S267>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S204>/Gain2'
                                         *   '<S225>/Gain2'
                                         *   '<S246>/Gain2'
                                         *   '<S267>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S204>/Saturation1'
                                             *   '<S225>/Saturation1'
                                             *   '<S246>/Saturation1'
                                             *   '<S267>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S204>/Saturation1'
                                            *   '<S225>/Saturation1'
                                            *   '<S246>/Saturation1'
                                            *   '<S267>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S204>/Gain1'
                                        *   '<S225>/Gain1'
                                        *   '<S246>/Gain1'
                                        *   '<S267>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S296>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S296>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S296>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S296>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S296>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S296>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S348>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S348>/Constant1'
                                        */
real_T TEST_Desired_Hood_Enable_OV = 0.0;/* Variable: TEST_Desired_Hood_Enable_OV
                                          * Referenced by: '<S9>/Constant7'
                                          */
real_T TEST_Desired_Hood_Pos_OV = 0.05;/* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S9>/Constant6'
                                        */
real_T TEST_Feeder_Motor_DC_OV = 0.0;  /* Variable: TEST_Feeder_Motor_DC_OV
                                        * Referenced by: '<S9>/Constant2'
                                        */
real_T TEST_Output_Override_Flag = 0.0;/* Variable: TEST_Output_Override_Flag
                                        * Referenced by: '<S9>/Constant'
                                        */
real_T TEST_Shooter_Motor_DC_Center_OV = 0.0;
                                    /* Variable: TEST_Shooter_Motor_DC_Center_OV
                                     * Referenced by: '<S9>/Constant4'
                                     */
real_T TEST_Shooter_Motor_DC_Left_OV = 0.0;
                                      /* Variable: TEST_Shooter_Motor_DC_Left_OV
                                       * Referenced by: '<S9>/Constant3'
                                       */
real_T TEST_Shooter_Motor_DC_Right_OV = 0.0;
                                     /* Variable: TEST_Shooter_Motor_DC_Right_OV
                                      * Referenced by: '<S9>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Override_Flag = 0.0;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S347>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S347>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S347>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S9>/Constant1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S284>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S284>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S284>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S284>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S284>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S284>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S349>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S348>/Dead Zone'
                                        *   '<S349>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S348>/Dead Zone'
                                        *   '<S349>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S16>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S346>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S346>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S346>/Constant4'
                                        */
real_T Vision_Object_X_Offset = 0.0;   /* Variable: Vision_Object_X_Offset
                                        * Referenced by: '<S16>/Constant4'
                                        */
real_T Vision_Object_Y_Offset = 0.0;   /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S16>/Constant8'
                                        */
real_T Vision_Tag_Angle_Offset = 0.0;  /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S16>/Constant5'
                                        */
real_T Vision_Tag_Target_Angle = 0.0;  /* Variable: Vision_Tag_Target_Angle
                                        * Referenced by: '<S346>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S346>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S346>/Constant5'
                                        */
real_T Vision_Tag_X_Offset = 0.0;      /* Variable: Vision_Tag_X_Offset
                                        * Referenced by: '<S16>/Constant3'
                                        */
real_T Vision_Tag_Y_Offset = 0.0;      /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S16>/Constant7'
                                        */
uint8_T TEST_Pipeline = 0U;            /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S15>/Constant22'
                                        *   '<S346>/Constant11'
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
 *    '<S87>/If Action Subsystem'
 *    '<S87>/If Action Subsystem5'
 */
void Robot_Control_IfActionSubsystem(boolean_T *rty_IsBlueActive, boolean_T
  *rty_IsRedActive)
{
  /* SignalConversion generated from: '<S111>/IsBlueActive' incorporates:
   *  Constant: '<S111>/Constant'
   */
  *rty_IsBlueActive = true;

  /* SignalConversion generated from: '<S111>/IsRedActive' incorporates:
   *  Constant: '<S111>/Constant'
   */
  *rty_IsRedActive = true;
}

/*
 * Output and update for action system:
 *    '<S87>/If Action Subsystem1'
 *    '<S87>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive)
{
  /* Logic: '<S112>/NOT' incorporates:
   *  SignalConversion generated from: '<S112>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S112>/IsRedActive' */
  *rty_IsRedActive = rtu_IsBlueInactiveFirst;
}

/*
 * Output and update for action system:
 *    '<S87>/If Action Subsystem2'
 *    '<S87>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive)
{
  /* Logic: '<S113>/NOT1' incorporates:
   *  SignalConversion generated from: '<S113>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S113>/IsBlueActive' */
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
  real_T rtb_Add_bn;
  real_T rtb_Add_fn;
  real_T rtb_Add_h5;
  real_T rtb_Add_jp;
  real_T rtb_Add_k;
  real_T rtb_Error_d;
  real_T rtb_Hypot_fg;
  real_T rtb_Hypot_pi;
  real_T rtb_Init;
  real_T rtb_Init_g;
  real_T rtb_Init_o;
  real_T rtb_Integral_bj;
  real_T rtb_Integral_d;
  real_T rtb_Integral_ga;
  real_T rtb_Merge1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_hi;
  real_T rtb_Product_lo;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_kg;
  real_T rtb_Subtract1_la;
  real_T rtb_Sum2_e;
  real_T rtb_Switch1;
  real_T rtb_Switch2;
  real_T rtb_Switch2_dp;
  real_T rtb_Switch2_f;
  real_T rtb_Switch2_m;
  real_T rtb_Switch2_p2;
  real_T rtb_Switch4;
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
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation_g;
  boolean_T rtb_Reset_Wheel_Offsets;
  boolean_T rtb_Swerve_Motors_Disabled;

  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Joystick_Left_B11 >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S25>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *  UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets =
    (Robot_Control_U.Joystick_Left_B12 > Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S26>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *  UnitDelay: '<S26>/Delay Input1'
   *
   * Block description for '<S26>/Delay Input1':
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

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
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

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Toward_Driver = (Robot_Control_U.Joystick_Right_POV ==
    180.0);

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Right_Driver = (Robot_Control_U.Joystick_Right_POV ==
    90.0);

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Left_Driver = (Robot_Control_U.Joystick_Right_POV ==
    270.0);

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Away_Driver = (Robot_Control_U.Joystick_Right_POV == 0.0);

  /* Sum: '<S16>/Add' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Gain: '<S16>/Convert meters to inches1'
   *  Inport: '<Root>/Vision_c1_AprilTag_X_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_X_m) + Vision_Tag_X_Offset;

  /* Sum: '<S16>/Add1' incorporates:
   *  Constant: '<S16>/Constant7'
   *  Gain: '<S16>/Convert meters to inches'
   *  Inport: '<Root>/Vision_c1_AprilTag_Y_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_Y_m) + Vision_Tag_Y_Offset;

  /* Sum: '<S16>/Add2' incorporates:
   *  Constant: '<S16>/Constant5'
   *  Inport: '<Root>/Vision_c1_AprilTag_Yaw_deg'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_AprilTag_Yaw_deg + Vision_Tag_Angle_Offset;

  /* If: '<S375>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S375>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S378>/Action Port'
     */
    /* Product: '<S378>/Product' incorporates:
     *  Constant: '<S378>/Constant1'
     *  Constant: '<S378>/Constant2'
     *  Math: '<S378>/Math Function'
     */
    rtb_Init_o = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct, -0.3495)
      * 111.0;

    /* End of Outputs for SubSystem: '<S375>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S375>/Subsystem' incorporates:
     *  ActionPort: '<S379>/Action Port'
     */
    /* SignalConversion generated from: '<S379>/Out1' incorporates:
     *  Constant: '<S379>/Constant'
     */
    rtb_Init_o = 0.0;

    /* End of Outputs for SubSystem: '<S375>/Subsystem' */
  }

  /* End of If: '<S375>/If' */

  /* Gain: '<S376>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S16>/Add3' incorporates:
   *  Constant: '<S16>/Constant4'
   *  Fcn: '<S377>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Init_o * cos(rtb_Sin4)) +
    Vision_Object_X_Offset;

  /* Sum: '<S16>/Add4' incorporates:
   *  Constant: '<S16>/Constant8'
   *  Fcn: '<S377>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Init_o * sin(rtb_Sin4)) +
    Vision_Object_Y_Offset;

  /* Sum: '<S16>/Add5' incorporates:
   *  Constant: '<S16>/Constant6'
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_Object_Hor_deg + Vision_Object_Angle_Offset;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Robot_Control_DW.SwitchCase_ActiveSubsystem;
  rtb_Add_bn = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_bn)) || (rtIsInf(rtb_Add_bn))) {
    rtb_Add_bn = 0.0;
  } else {
    rtb_Add_bn = fmod(rtb_Add_bn, 4.294967296E+9);
  }

  switch ((rtb_Add_bn < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_bn)))) :
          ((int32_T)((uint32_T)rtb_Add_bn))) {
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
    /* Merge: '<S8>/Merge1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  SignalConversion generated from: '<S4>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* Merge: '<S8>/Merge2' incorporates:
     *  Constant: '<S4>/Constant2'
     *  SignalConversion generated from: '<S4>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S8>/Merge3' incorporates:
     *  Constant: '<S4>/Constant3'
     *  SignalConversion generated from: '<S4>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S8>/Merge4' incorporates:
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

    /* Merge: '<S8>/Merge7' incorporates:
     *  Constant: '<S4>/Constant7'
     *  SignalConversion generated from: '<S4>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S8>/Merge9' incorporates:
     *  Constant: '<S4>/Constant9'
     *  SignalConversion generated from: '<S4>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S8>/Merge10' incorporates:
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

    /* Merge: '<S8>/Merge23' incorporates:
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

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S17>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S8>/Merge1' incorporates:
     *  Constant: '<S17>/Constant1'
     *  SignalConversion generated from: '<S2>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S17>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* Merge: '<S8>/Merge2' incorporates:
     *  Constant: '<S17>/Constant2'
     *  SignalConversion generated from: '<S2>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S8>/Merge7' incorporates:
     *  Constant: '<S17>/Constant7'
     *  SignalConversion generated from: '<S2>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S8>/Merge3' incorporates:
     *  Constant: '<S17>/Constant3'
     *  SignalConversion generated from: '<S2>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S8>/Merge9' incorporates:
     *  Constant: '<S17>/Constant9'
     *  SignalConversion generated from: '<S2>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S8>/Merge4' incorporates:
     *  Constant: '<S17>/Constant4'
     *  SignalConversion generated from: '<S2>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* Merge: '<S8>/Merge23' incorporates:
     *  Constant: '<S17>/Constant10'
     *  SignalConversion generated from: '<S2>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* Merge: '<S8>/Merge10' incorporates:
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

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S348>/Unit Delay1'
       *  UnitDelay: '<S348>/Unit Delay2'
       *  UnitDelay: '<S348>/Unit Delay3'
       *  UnitDelay: '<S348>/Unit Delay4'
       *  UnitDelay: '<S351>/Delay Input1'
       *  UnitDelay: '<S352>/Delay Input1'
       *  UnitDelay: '<S353>/Delay Input1'
       *  UnitDelay: '<S354>/Delay Input1'
       *  UnitDelay: '<S356>/Delay Input1'
       *  UnitDelay: '<S362>/Unit Delay'
       *  UnitDelay: '<S362>/Unit Delay1'
       *  UnitDelay: '<S366>/FixPt Unit Delay1'
       *  UnitDelay: '<S366>/FixPt Unit Delay2'
       *
       * Block description for '<S351>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S352>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S353>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S354>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S356>/Delay Input1':
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
      Robot_Control_DW.UnitDelay1_DSTATE_l = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_p = 0.0;
      Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;
      Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Teleop' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Switch: '<S346>/Switch4' incorporates:
     *  Constant: '<S371>/Constant'
     *  Constant: '<S374>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S371>/Compare'
     *  RelationalOperator: '<S374>/Compare'
     *  Switch: '<S346>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S346>/Switch4' incorporates:
       *  Constant: '<S346>/Constant8'
       *  Sum: '<S346>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S346>/Switch5' incorporates:
       *  Constant: '<S346>/Constant7'
       *  Gain: '<S346>/Gain'
       *  Sum: '<S346>/Subtract5'
       *  Switch: '<S346>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S346>/Switch4' incorporates:
       *  Constant: '<S346>/Constant6'
       *  Switch: '<S346>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S346>/Switch4' */

    /* Logic: '<S346>/Logical Operator1' incorporates:
     *  Constant: '<S14>/Constant12'
     *  Logic: '<S346>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S348>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_bn = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_bn = 0.0;
    } else {
      rtb_Add_bn = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S348>/Add' incorporates:
     *  Constant: '<S348>/Constant'
     *  Constant: '<S348>/Constant1'
     *  DeadZone: '<S348>/Dead Zone'
     *  Lookup_n-D: '<S348>/Modulation_Str_Y_Rel'
     *  Product: '<S348>/Product'
     *  Product: '<S348>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Add_h5 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                  Steering_Relative_Gain) + (rtb_Add_bn * Steering_Twist_Gain);

    /* RelationalOperator: '<S350>/Compare' incorporates:
     *  Constant: '<S350>/Constant'
     */
    rtb_Compare_a = (rtb_Add_h5 == 0.0);

    /* Logic: '<S348>/AND2' incorporates:
     *  RelationalOperator: '<S351>/FixPt Relational Operator'
     *  RelationalOperator: '<S352>/FixPt Relational Operator'
     *  RelationalOperator: '<S353>/FixPt Relational Operator'
     *  RelationalOperator: '<S354>/FixPt Relational Operator'
     *  UnitDelay: '<S351>/Delay Input1'
     *  UnitDelay: '<S352>/Delay Input1'
     *  UnitDelay: '<S353>/Delay Input1'
     *  UnitDelay: '<S354>/Delay Input1'
     *
     * Block description for '<S351>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S352>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S353>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S354>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Enable_Wheels = ((((((int32_T)Robot_Control_B.Face_Away_Driver) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)
      Robot_Control_B.Face_Left_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      Robot_Control_B.Face_Toward_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g))) || (((int32_T)
      Robot_Control_B.Face_Right_Driver) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S348>/AND1' incorporates:
     *  Logic: '<S348>/AND3'
     *  UnitDelay: '<S348>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_a && (rtb_Enable_Wheels ||
      (Robot_Control_DW.UnitDelay2_DSTATE)));

    /* Logic: '<S348>/AND4' incorporates:
     *  Logic: '<S348>/AND8'
     *  UnitDelay: '<S348>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_a && (!rtb_Enable_Wheels)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S348>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S348>/Switch8' incorporates:
     *  Constant: '<S357>/Constant'
     *  Logic: '<S348>/AND9'
     *  RelationalOperator: '<S356>/FixPt Relational Operator'
     *  RelationalOperator: '<S357>/Compare'
     *  UnitDelay: '<S10>/Unit Delay'
     *  UnitDelay: '<S356>/Delay Input1'
     *
     * Block description for '<S356>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)rtb_Compare_a)
          > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j))) ||
        (Robot_Control_B.Active_GameState != 2)) {
      /* Switch: '<S348>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S348>/Switch8' incorporates:
       *  UnitDelay: '<S348>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S348>/Switch8' */

    /* Switch: '<S348>/Switch4' incorporates:
     *  Constant: '<S348>/Constant5'
     *  Switch: '<S348>/Switch1'
     *  Switch: '<S348>/Switch5'
     *  Switch: '<S348>/Switch6'
     *  Switch: '<S348>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Switch4 = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S348>/Switch5' incorporates:
       *  Constant: '<S348>/Constant6'
       */
      rtb_Switch4 = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S348>/Switch6' incorporates:
       *  Constant: '<S348>/Constant7'
       *  Switch: '<S348>/Switch5'
       */
      rtb_Switch4 = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S348>/Switch7' incorporates:
       *  Constant: '<S348>/Constant8'
       *  Switch: '<S348>/Switch5'
       *  Switch: '<S348>/Switch6'
       */
      rtb_Switch4 = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S348>/Switch1' incorporates:
       *  Constant: '<S14>/Constant10'
       *  Switch: '<S348>/Switch5'
       *  Switch: '<S348>/Switch6'
       *  Switch: '<S348>/Switch7'
       */
      rtb_Switch4 = 0.0;
    } else {
      /* Switch: '<S348>/Switch6' incorporates:
       *  Switch: '<S348>/Switch5'
       *  Switch: '<S348>/Switch7'
       *  UnitDelay: '<S348>/Unit Delay1'
       */
      rtb_Switch4 = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S348>/Switch4' */

    /* Switch: '<S348>/Switch2' incorporates:
     *  Switch: '<S348>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S348>/Switch2' incorporates:
       *  Constant: '<S348>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S348>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Switch4;
    } else {
      /* Switch: '<S348>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S348>/Switch3' incorporates:
       *  Constant: '<S348>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S348>/Switch2' */

    /* Merge: '<S8>/Merge1' incorporates:
     *  Sum: '<S348>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S347>/Switch1' incorporates:
     *  Constant: '<S347>/Constant5'
     *  Constant: '<S347>/Constant8'
     *  DataTypeConversion: '<S347>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_a;
    }

    /* End of Switch: '<S347>/Switch1' */

    /* Lookup_n-D: '<S349>/Modulation_Drv' incorporates:
     *  Math: '<S349>/Magnitude'
     */
    rtb_Init_o = look1_binlcpw(rt_hypotd_snf(Robot_Control_B.Drive_Joystick_X,
      Robot_Control_B.Drive_Joystick_Y), rtCP_Modulation_Drv_bp01Data,
      rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S360>/Compare' incorporates:
     *  Constant: '<S360>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Init_o == 0.0);

    /* DeadZone: '<S349>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S349>/Dead Zone' */

    /* Logic: '<S349>/Logical Operator' incorporates:
     *  Constant: '<S361>/Constant'
     *  RelationalOperator: '<S361>/Compare'
     */
    rtb_Enable_Wheels = ((rtb_Sin4 != 0.0) && rtb_Swerve_Motors_Disabled);

    /* Switch: '<S347>/Switch' incorporates:
     *  Constant: '<S347>/Constant5'
     *  Constant: '<S347>/Constant7'
     *  DataTypeConversion: '<S347>/Data Type Conversion'
     *  Logic: '<S349>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Enable_Wheels;
    }

    /* End of Switch: '<S347>/Switch' */

    /* Switch: '<S346>/Switch2' incorporates:
     *  Constant: '<S346>/Constant2'
     *  Constant: '<S370>/Constant'
     *  Constant: '<S373>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S370>/Compare'
     *  RelationalOperator: '<S373>/Compare'
     *  Sum: '<S346>/Subtract'
     *  Switch: '<S346>/Switch'
     *  Switch: '<S346>/Switch1'
     *  Switch: '<S346>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S346>/Switch2' incorporates:
       *  Constant: '<S346>/Constant5'
       *  Sum: '<S346>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S346>/Switch2' incorporates:
       *  Constant: '<S346>/Constant4'
       *  Sum: '<S346>/Subtract2'
       *  Switch: '<S346>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S346>/Switch1' incorporates:
       *  Constant: '<S346>/Constant1'
       *  Sum: '<S346>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S346>/Switch2' incorporates:
       *  Constant: '<S346>/Constant3'
       *  Switch: '<S346>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S346>/Switch1' incorporates:
       *  Constant: '<S346>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S346>/Switch2' */

    /* UnaryMinus: '<S346>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S362>/Switch1' incorporates:
     *  Constant: '<S367>/Constant'
     *  Constant: '<S368>/Constant'
     *  Logic: '<S362>/AND'
     *  RelationalOperator: '<S367>/Compare'
     *  RelationalOperator: '<S368>/Compare'
     *  Switch: '<S362>/Switch2'
     *  UnitDelay: '<S362>/Unit Delay'
     *  UnitDelay: '<S362>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S362>/Switch1' */

    /* Switch: '<S349>/Switch1' incorporates:
     *  Logic: '<S349>/Logical Operator1'
     *  Switch: '<S349>/Switch4'
     *  Switch: '<S349>/Switch9'
     */
    if (rtb_Enable_Wheels) {
      /* Signum: '<S349>/Sign' */
      if (rtIsNaN(rtb_Sin4)) {
        rtb_Add_bn = (rtNaN);
      } else if (rtb_Sin4 < 0.0) {
        rtb_Add_bn = -1.0;
      } else {
        rtb_Add_bn = (rtb_Sin4 > 0.0);
      }

      /* Switch: '<S349>/Switch5' incorporates:
       *  Constant: '<S349>/Constant3'
       *  Constant: '<S349>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_k = -1.5707963267948966;
      } else {
        rtb_Add_k = 0.0;
      }

      /* Merge: '<S8>/Merge3' incorporates:
       *  Gain: '<S349>/Gain3'
       *  Signum: '<S349>/Sign'
       *  Sum: '<S349>/Add'
       *  Switch: '<S349>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_bn) +
        rtb_Add_k;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Switch: '<S349>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S349>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S8>/Merge3' incorporates:
         *  Constant: '<S349>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S8>/Merge3' incorporates:
         *  Constant: '<S349>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S349>/Switch6' */
    } else {
      /* Merge: '<S8>/Merge3' incorporates:
       *  Switch: '<S349>/Switch4'
       *  Trigonometry: '<S349>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S349>/Switch1' */

    /* Switch: '<S359>/Switch1' incorporates:
     *  Constant: '<S359>/Constant'
     *  Constant: '<S359>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S359>/Switch1' */

    /* Switch: '<S366>/Init' incorporates:
     *  UnitDelay: '<S366>/FixPt Unit Delay1'
     *  UnitDelay: '<S366>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S366>/Init' */

    /* Sum: '<S364>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S365>/Switch2' incorporates:
     *  Constant: '<S363>/Constant1'
     *  Constant: '<S363>/Constant3'
     *  RelationalOperator: '<S365>/LowerRelop1'
     *  RelationalOperator: '<S365>/UpperRelop'
     *  Switch: '<S365>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S365>/Switch' incorporates:
       *  Constant: '<S363>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S365>/Switch2' */

    /* Sum: '<S364>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S349>/Switch8' incorporates:
     *  Logic: '<S349>/Logical Operator1'
     *  Switch: '<S349>/Switch2'
     */
    if (rtb_Enable_Wheels) {
      /* Switch: '<S349>/Switch' incorporates:
       *  Gain: '<S349>/Gain'
       *  Merge: '<S8>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Sin4;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S8>/Merge4' incorporates:
       *  Constant: '<S14>/Constant7'
       *  Constant: '<S14>/Constant8'
       *  Constant: '<S349>/Constant5'
       *  Gain: '<S349>/Gain2'
       *  Math: '<S349>/Magnitude1'
       *  MinMax: '<S349>/Min'
       *  Switch: '<S349>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S359>/Product' incorporates:
       *  Switch: '<S349>/Switch2'
       */
      rtb_Add_bn = rtb_Init_o * rtb_Init;

      /* Saturate: '<S359>/Saturation' incorporates:
       *  Switch: '<S349>/Switch2'
       */
      if (rtb_Add_bn > Boost_Trigger_High_Speed) {
        /* Merge: '<S8>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_bn < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S8>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S8>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_bn;
      }

      /* End of Saturate: '<S359>/Saturation' */
    }

    /* End of Switch: '<S349>/Switch8' */

    /* Merge: '<S8>/Merge2' incorporates:
     *  SignalConversion: '<S348>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Add_h5;

    /* Switch: '<S346>/Switch6' incorporates:
     *  Constant: '<S346>/Constant11'
     *  Switch: '<S346>/Switch7'
     */
    rtb_Desired_Pipeline = TEST_Pipeline;

    /* Merge: '<S8>/Merge23' incorporates:
     *  Constant: '<S14>/Constant'
     *  SignalConversion generated from: '<S14>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* Merge: '<S8>/Merge7' incorporates:
     *  Constant: '<S14>/Constant3'
     *  SignalConversion generated from: '<S14>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S8>/Merge9' incorporates:
     *  Constant: '<S14>/Constant9'
     *  SignalConversion generated from: '<S14>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S8>/Merge10' incorporates:
     *  Constant: '<S14>/Constant1'
     *  SignalConversion generated from: '<S14>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* SignalConversion generated from: '<S14>/Enable_Wheels' incorporates:
     *  Constant: '<S14>/Constant6'
     */
    rtb_Enable_Wheels = false;

    /* SignalConversion generated from: '<S14>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S14>/Constant13'
     */
    rtb_Reset_Wheel_Offsets = false;

    /* SignalConversion generated from: '<S14>/Disable_Wheels' incorporates:
     *  Constant: '<S14>/Constant14'
     */
    rtb_Disable_Wheels = false;

    /* SignalConversion generated from: '<S14>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S14>/Constant2'
     */
    rtb_Swerve_Motors_Disabled = false;

    /* SignalConversion: '<S14>/Signal Copy' incorporates:
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = Robot_Control_U.Gamepad_LB;

    /* SignalConversion: '<S14>/Signal Copy1' incorporates:
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = Robot_Control_U.Gamepad_RB;

    /* Update for UnitDelay: '<S356>/Delay Input1'
     *
     * Block description for '<S356>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_a;

    /* Update for UnitDelay: '<S355>/Delay Input1' incorporates:
     *  Constant: '<S14>/Constant5'
     *
     * Block description for '<S355>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S351>/Delay Input1'
     *
     * Block description for '<S351>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S352>/Delay Input1'
     *
     * Block description for '<S352>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S353>/Delay Input1'
     *
     * Block description for '<S353>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S354>/Delay Input1'
     *
     * Block description for '<S354>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S348>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE = rtb_AND1_c;

    /* Update for UnitDelay: '<S348>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S348>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S348>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Switch4;

    /* Update for UnitDelay: '<S362>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1;

    /* Update for UnitDelay: '<S362>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S366>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S366>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S366>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Init;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* InitializeConditions for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
     *  UnitDelay: '<S15>/Unit Delay'
     */
    Robot_Control_DW.UnitDelay_DSTATE_ir = ((rtAction == rtPrevAction) &&
      (Robot_Control_DW.UnitDelay_DSTATE_ir));

    /* End of InitializeConditions for SubSystem: '<S1>/Test' */

    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Merge: '<S8>/Merge1' incorporates:
     *  Constant: '<S15>/Constant1'
     *  SignalConversion generated from: '<S15>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* Merge: '<S8>/Merge2' incorporates:
     *  Constant: '<S15>/Constant2'
     *  SignalConversion generated from: '<S15>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S8>/Merge3' incorporates:
     *  Constant: '<S15>/Constant3'
     *  SignalConversion generated from: '<S15>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S8>/Merge4' incorporates:
     *  Constant: '<S15>/Constant4'
     *  SignalConversion generated from: '<S15>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* SignalConversion generated from: '<S15>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S15>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* SignalConversion generated from: '<S15>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S15>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S8>/Merge7' incorporates:
     *  Constant: '<S15>/Constant7'
     *  SignalConversion generated from: '<S15>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S8>/Merge9' incorporates:
     *  Constant: '<S15>/Constant9'
     *  SignalConversion generated from: '<S15>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S8>/Merge10' incorporates:
     *  Constant: '<S15>/Constant12'
     *  SignalConversion generated from: '<S15>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = true;

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Constant14'
     *  Switch: '<S15>/Switch1'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    if (Robot_Control_B.Button_Disable_Wheels) {
      rtb_Swerve_Motors_Disabled = true;
    } else {
      rtb_Swerve_Motors_Disabled = ((!Robot_Control_B.Button_Enable_Wheels) &&
        (Robot_Control_DW.UnitDelay_DSTATE_ir));
    }

    /* End of Switch: '<S15>/Switch' */

    /* Merge: '<S8>/Merge23' incorporates:
     *  Constant: '<S15>/Constant21'
     *  SignalConversion generated from: '<S15>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* SignalConversion generated from: '<S15>/Button_Spinup_Enable' incorporates:
     *  Constant: '<S15>/Constant11'
     */
    rtb_Button_Spinup_Enable = 0U;

    /* SignalConversion generated from: '<S15>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S15>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

    /* SignalConversion generated from: '<S15>/Desired_Pipeline' incorporates:
     *  Constant: '<S15>/Constant22'
     */
    rtb_Desired_Pipeline = TEST_Pipeline;

    /* SignalConversion: '<S15>/Signal Copy' */
    rtb_Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* SignalConversion: '<S15>/Signal Copy2' */
    rtb_Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* SignalConversion: '<S15>/Signal Copy1' */
    rtb_Reset_Wheel_Offsets = Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S15>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_Swerve_Motors_Disabled;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Reshape: '<S27>/Reshapey' incorporates:
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_X'
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_Y'
   *  S-Function (sfix_udelay): '<S7>/Tapped Delay'
   *  S-Function (sfix_udelay): '<S7>/Tapped Delay1'
   *  Sum: '<S7>/Add'
   *  Sum: '<S7>/Add1'
   */
  rtb_Reshapey[0] = (Robot_Control_U.Vision_RobotPoseFieldSpace_X +
                     Robot_Control_DW.TappedDelay_X[0]) +
    Robot_Control_DW.TappedDelay_X[1];
  rtb_Reshapey[1] = (Robot_Control_U.Vision_RobotPoseFieldSpace_Y +
                     Robot_Control_DW.TappedDelay1_X[0]) +
    Robot_Control_DW.TappedDelay1_X[1];

  /* Delay: '<S27>/MemoryX' incorporates:
   *  Constant: '<S27>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S54>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S80>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S47>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S78>/Enable'
   */
  /* Logic: '<S7>/AND' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S78>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S27>/C'
     *  Delay: '<S27>/MemoryX'
     *  Product: '<S80>/Product'
     */
    rtb_Sin4 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Sin4;

    /* Sum: '<S78>/Sum' incorporates:
     *  Constant: '<S27>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S78>/C[k]*xhat[k|k-1]'
     *  Product: '<S78>/D[k]*u[k]'
     *  Sum: '<S78>/Add1'
     */
    rtb_Add_h5 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Init_o = rtb_Reshapey[0] - (rtb_Add_h5 + rtb_Sin4);

    /* Product: '<S78>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S27>/C'
     *  Delay: '<S27>/MemoryX'
     *  Product: '<S80>/Product'
     */
    rtb_Sin4 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Sin4;

    /* Sum: '<S78>/Sum' incorporates:
     *  Constant: '<S27>/D'
     *  Product: '<S78>/C[k]*xhat[k|k-1]'
     *  Product: '<S78>/D[k]*u[k]'
     *  Sum: '<S78>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Add_h5 + rtb_Sin4);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S78>/Product3' incorporates:
     *  Constant: '<S28>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Init_o) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S80>/Add1' incorporates:
     *  Product: '<S80>/Product'
     */
    rtb_Add_h5 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S78>/Product3' incorporates:
     *  Constant: '<S28>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Init_o) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S80>/Add1' incorporates:
     *  Product: '<S80>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S80>/Product2' incorporates:
     *  Constant: '<S28>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Add_h5) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Add_h5) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S78>/Product3' incorporates:
       *  Outport: '<S78>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S80>/Product2' incorporates:
       *  Outport: '<S80>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S7>/AND' */
  /* End of Outputs for SubSystem: '<S47>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S54>/Enabled Subsystem' */

  /* Sum: '<S54>/Add' incorporates:
   *  Delay: '<S27>/MemoryX'
   */
  rtb_Reshapey[0] = Robot_Control_B.Product2[0] +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Reshapey[1] = Robot_Control_B.Product2[1] +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Switch: '<S7>/Switch1'
   */
  if (KF_Enable != 0.0) {
    /* Switch: '<S7>/Switch' */
    Robot_Control_B.KF_Position_X = rtb_Reshapey[0];

    /* Switch: '<S7>/Switch1' */
    Robot_Control_B.KF_Position_Y = rtb_Reshapey[1];
  } else {
    /* Switch: '<S7>/Switch' incorporates:
     *  Inport: '<Root>/Odom_Position_X'
     */
    Robot_Control_B.KF_Position_X = Robot_Control_U.Odom_Position_X;

    /* Switch: '<S7>/Switch1' incorporates:
     *  Inport: '<Root>/Odom_Position_Y'
     */
    Robot_Control_B.KF_Position_Y = Robot_Control_U.Odom_Position_Y;
  }

  /* End of Switch: '<S7>/Switch' */

  /* If: '<S12>/If' incorporates:
   *  Constant: '<S134>/Constant'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Merge: '<S12>/Merge'
   *  Merge: '<S12>/Merge1'
   *  Merge: '<S12>/Merge2'
   *  Merge: '<S12>/Merge3'
   *  Merge: '<S12>/Merge4'
   *  Merge: '<S12>/Merge5'
   *  Merge: '<S12>/Merge7'
   *  Merge: '<S12>/Merge8'
   *  SignalConversion generated from: '<S134>/Robot_Reached_Destination'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  Robot_Control_DW.If_ActiveSubsystem = 1;
  if ((rtPrevAction != 1) && (rtPrevAction == 0)) {
    /* Disable for If: '<S140>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S143>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S145>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;

      /* End of Disable for If: '<S143>/If' */
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S140>/If' */
  }

  /* Outputs for IfAction SubSystem: '<S12>/Pass Through' incorporates:
   *  ActionPort: '<S134>/Action Port'
   */
  Robot_Control_B.Robot_Reached_Destination = true;
  Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;
  Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;
  Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;
  Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;
  Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;
  Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;
  Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

  /* End of If: '<S12>/If' */
  /* End of Outputs for SubSystem: '<S12>/Pass Through' */

  /* Signum: '<S284>/Sign2' incorporates:
   *  UnitDelay: '<S284>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S284>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S284>/Product1' incorporates:
   *  Signum: '<S284>/Sign1'
   *  Signum: '<S284>/Sign2'
   */
  rtb_Add_bn *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_bn)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_bn, 256.0);
  }

  /* Switch: '<S284>/Switch' incorporates:
   *  Constant: '<S284>/Constant'
   *  Constant: '<S289>/Constant'
   *  Constant: '<S290>/Constant'
   *  Logic: '<S284>/or'
   *  Product: '<S284>/Product1'
   *  RelationalOperator: '<S289>/Compare'
   *  RelationalOperator: '<S290>/Compare'
   *  UnitDelay: '<S284>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S284>/Switch' */

  /* Switch: '<S295>/Init' incorporates:
   *  UnitDelay: '<S295>/FixPt Unit Delay1'
   *  UnitDelay: '<S295>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_o = rtb_Sin4;
  } else {
    rtb_Init_o = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S295>/Init' */

  /* RelationalOperator: '<S291>/Compare' incorporates:
   *  Constant: '<S291>/Constant'
   */
  rtb_Compare_a = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S292>/Compare' incorporates:
   *  Constant: '<S292>/Constant'
   */
  rtb_AND1_c = (rtb_Sin4 > 0.0);

  /* Abs: '<S284>/Abs' incorporates:
   *  Sum: '<S284>/Subtract'
   *  UnitDelay: '<S284>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S284>/Switch5' incorporates:
   *  Constant: '<S284>/Constant1'
   *  Switch: '<S284>/Switch1'
   *  UnaryMinus: '<S284>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S284>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S284>/Constant4'
     *  Constant: '<S284>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S284>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S284>/Constant2'
     *  Constant: '<S284>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S284>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S284>/Lookup Table Dynamic'
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
    rtb_Add_bn = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S284>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S284>/Constant10'
     *  Constant: '<S284>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S284>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S284>/Constant7'
     *  Constant: '<S284>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S284>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S284>/Lookup Table Dynamic1'
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

    /* Switch: '<S284>/Switch3' incorporates:
     *  Constant: '<S284>/Constant1'
     *  Constant: '<S284>/Constant3'
     *  UnaryMinus: '<S284>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_bn = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_bn = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S284>/Switch3' */
  }

  /* End of Switch: '<S284>/Switch5' */

  /* Product: '<S284>/Product' incorporates:
   *  Switch: '<S284>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_bn * rtb_Merge1;

  /* Sum: '<S293>/Sum1' */
  rtb_Add_h5 = rtb_Sin4 - rtb_Init_o;

  /* Switch: '<S294>/Switch2' incorporates:
   *  RelationalOperator: '<S294>/LowerRelop1'
   */
  if (!(rtb_Add_h5 > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S284>/Switch2' incorporates:
     *  Constant: '<S284>/Constant1'
     *  Constant: '<S284>/Constant3'
     *  Switch: '<S284>/Switch4'
     *  UnaryMinus: '<S284>/Unary Minus1'
     */
    if (rtb_Compare_a) {
      rtb_Add_bn = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S284>/Switch4' incorporates:
       *  Constant: '<S284>/Constant1'
       */
      rtb_Add_bn = Translation_Speed_Rate_Limit_Dec;
    } else {
      rtb_Add_bn = -Translation_Speed_Rate_Limit_Inc;
    }

    /* Product: '<S284>/Product2' incorporates:
     *  Switch: '<S284>/Switch2'
     */
    rtb_Switch4 = rtb_Add_bn * rtb_Merge1;

    /* Switch: '<S294>/Switch' incorporates:
     *  RelationalOperator: '<S294>/UpperRelop'
     */
    if (rtb_Add_h5 < rtb_Switch4) {
      rtb_Optimized_Module_Angle = rtb_Switch4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Add_h5;
    }

    /* End of Switch: '<S294>/Switch' */
  }

  /* End of Switch: '<S294>/Switch2' */

  /* Sum: '<S293>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle + rtb_Init_o;

  /* Switch: '<S287>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S287>/Switch' incorporates:
     *  Constant: '<S319>/Constant3'
     *  Constant: '<S319>/Constant4'
     *  Math: '<S319>/Math Function'
     *  Sum: '<S287>/Subtract'
     *  Sum: '<S319>/Add1'
     *  Sum: '<S319>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S287>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S287>/Switch' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_bn = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_bn)) || (rtIsInf(rtb_Add_bn))) {
    rtb_Add_bn = 0.0;
  } else {
    rtb_Add_bn = fmod(rtb_Add_bn, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Add_bn < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Add_bn)))))) : ((int32_T)((uint8_T)rtb_Add_bn)));

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

  /* Sum: '<S87>/Subtract' incorporates:
   *  Constant: '<S87>/Constant'
   *  Inport: '<Root>/MatchTime'
   */
  rtb_Merge1 = 140.0 - Robot_Control_U.MatchTime;

  /* If: '<S87>/If' incorporates:
   *  DataTypeConversion: '<S87>/Data Type Conversion'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   */
  if ((rtb_GameState == 1) || (rtb_Merge1 <= 10.0)) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem' */
  } else if (rtb_Merge1 <= 35.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem1' */
  } else if (rtb_Merge1 <= 60.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem2' */
  } else if (rtb_Merge1 <= 85.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem3' */
  } else if (rtb_Merge1 <= 110.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.RB_IsBlueActive, &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.RB_IsBlueActive,
      &Robot_Control_B.RB_IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem5' */
  }

  /* End of If: '<S87>/If' */

  /* If: '<S118>/If' incorporates:
   *  If: '<S119>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S118>/Blue' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    /* Merge: '<S118>/Merge' incorporates:
     *  Constant: '<S120>/BlueAllianceZoneX'
     *  Logic: '<S120>/AND'
     *  RelationalOperator: '<S120>/Less Than'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsBlueActive) &&
      (Robot_Control_B.KF_Position_X < Field_BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S118>/Blue' */

    /* Outputs for IfAction SubSystem: '<S119>/Blue' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    /* Merge: '<S119>/Merge' incorporates:
     *  Constant: '<S122>/BlueAllianceZoneX'
     *  RelationalOperator: '<S122>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      Field_BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S119>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S118>/Red' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    /* Merge: '<S118>/Merge' incorporates:
     *  Constant: '<S121>/RedAllianceZoneX'
     *  Logic: '<S121>/AND'
     *  RelationalOperator: '<S121>/GreaterThan'
     */
    Robot_Control_B.RB_Logic_Score_In_Zone = ((Robot_Control_B.RB_IsRedActive) &&
      (Robot_Control_B.KF_Position_X > Field_RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S118>/Red' */

    /* Outputs for IfAction SubSystem: '<S119>/Red' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    /* Merge: '<S119>/Merge' incorporates:
     *  Constant: '<S123>/RedAllianceZoneX'
     *  RelationalOperator: '<S123>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      Field_RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S119>/Red' */
  }

  /* End of If: '<S118>/If' */

  /* RelationalOperator: '<S89>/GreaterThan' incorporates:
   *  Constant: '<S89>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Math: '<S89>/Hypot'
   */
  Robot_Control_B.RB_Logic_Velocity = (rt_hypotd_snf
    (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
    Rebuilt_Shoot_Robot_Velocity_Max);

  /* RelationalOperator: '<S89>/Relational Operator' incorporates:
   *  Abs: '<S89>/Abs'
   *  Constant: '<S117>/Constant3'
   *  Constant: '<S117>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  Math: '<S117>/Math Function'
   *  Sum: '<S117>/Add1'
   *  Sum: '<S117>/Add2'
   *  Sum: '<S89>/Subtract'
   *  UnitDelay generated from: '<S11>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Gyro_Angle = (fabs(rt_modd_snf
    ((Robot_Control_DW.UnitDelay_1_DSTATE - Robot_Control_U.Gyro_Angle_Field_rad)
     + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931) <=
    Robot_Control_DW.UnitDelay_4_DSTATE);

  /* MinMax: '<S88>/Max' incorporates:
   *  Abs: '<S88>/Abs1'
   *  Abs: '<S88>/Abs2'
   *  Abs: '<S88>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.RB_Meas_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* RelationalOperator: '<S89>/Relational Operator1' incorporates:
   *  Abs: '<S89>/Abs1'
   *  Constant: '<S89>/Constant2'
   *  Sum: '<S89>/Subtract1'
   *  UnitDelay generated from: '<S11>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Shooter_Speed = (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.RB_Meas_Shooter_Speed_Max) <= Rebuilt_Shoot_Motor_Max_Error);

  /* RelationalOperator: '<S89>/Relational Operator4' incorporates:
   *  Abs: '<S89>/Abs4'
   *  Constant: '<S89>/Constant1'
   *  Sum: '<S89>/Subtract4'
   *  UnitDelay generated from: '<S11>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Robot_Control_B.RB_Logic_Hood_Pos = (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Rebuilt_Shoot_Hood_Pos_Max_Error);

  /* Logic: '<S89>/AND' */
  rtb_AND1_c = (((Robot_Control_B.RB_Logic_Gyro_Angle) &&
                 (Robot_Control_B.RB_Logic_Shooter_Speed)) &&
                (Robot_Control_B.RB_Logic_Hood_Pos));

  /* Logic: '<S89>/AND2' incorporates:
   *  Logic: '<S89>/AND1'
   */
  Robot_Control_B.RB_Ready_to_Score = (((Robot_Control_B.RB_Logic_Score_In_Zone)
    && (Robot_Control_B.RB_Logic_Velocity)) && rtb_AND1_c);

  /* SignalConversion: '<S89>/Signal Copy' */
  Robot_Control_B.RB_Logic_Outside_Zone =
    Robot_Control_B.Is_Outside_Alliance_Zone;

  /* Logic: '<S89>/AND3' */
  Robot_Control_B.RB_Ready_to_Pass = ((Robot_Control_B.RB_Logic_Outside_Zone) &&
    rtb_AND1_c);

  /* Chart: '<S11>/Shooter_Transfer_Feeder Chart' */
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
    /* Outputs for IfAction SubSystem: '<S86>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S95>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S97>/While Iterator'
     */
    /* If: '<S86>/If' incorporates:
     *  Constant: '<S100>/Constant1'
     *  Constant: '<S100>/Constant10'
     *  Constant: '<S100>/Constant2'
     *  Constant: '<S100>/Constant5'
     *  Constant: '<S100>/Constant6'
     *  Constant: '<S100>/Constant7'
     *  Constant: '<S100>/Constant8'
     *  Constant: '<S100>/Constant9'
     *  Constant: '<S102>/Constant1'
     *  Constant: '<S102>/Constant10'
     *  Constant: '<S102>/Constant2'
     *  Constant: '<S102>/Constant5'
     *  Constant: '<S102>/Constant6'
     *  Constant: '<S102>/Constant7'
     *  Constant: '<S102>/Constant8'
     *  Constant: '<S102>/Constant9'
     *  Constant: '<S105>/Constant'
     *  Constant: '<S105>/Constant1'
     *  Constant: '<S105>/Constant11'
     *  Constant: '<S105>/Constant2'
     *  Constant: '<S105>/Constant3'
     *  Constant: '<S105>/Constant4'
     *  Constant: '<S105>/Constant5'
     *  Constant: '<S105>/Constant6'
     *  Constant: '<S95>/Constant'
     *  Constant: '<S96>/Constant'
     *  Constant: '<S98>/Constant1'
     *  Constant: '<S98>/Constant10'
     *  Constant: '<S98>/Constant2'
     *  Constant: '<S98>/Constant5'
     *  Constant: '<S98>/Constant6'
     *  Constant: '<S98>/Constant7'
     *  Constant: '<S98>/Constant8'
     *  Constant: '<S98>/Constant9'
     *  Constant: '<S99>/Constant1'
     *  Constant: '<S99>/Constant10'
     *  Constant: '<S99>/Constant2'
     *  Constant: '<S99>/Constant5'
     *  Constant: '<S99>/Constant6'
     *  Constant: '<S99>/Constant7'
     *  Constant: '<S99>/Constant8'
     *  Constant: '<S99>/Constant9'
     *  Gain: '<S103>/Gain1'
     *  Gain: '<S110>/Gain1'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S97>/Memory'
     *  Memory: '<S97>/Memory1'
     *  Memory: '<S97>/Memory2'
     *  Memory: '<S97>/Memory3'
     *  Merge: '<S86>/Merge'
     *  Merge: '<S86>/Merge1'
     *  Merge: '<S86>/Merge2'
     *  Merge: '<S86>/Merge3'
     *  S-Function (sfix_look1_dyn): '<S100>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S98>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S99>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S105>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S93>/Desired_Shooter_Speed'
     *  SignalConversion generated from: '<S98>/Lookup Table Dynamic'
     *  Sum: '<S96>/Add'
     *  Sum: '<S96>/Subtract'
     *  Sum: '<S96>/Subtract1'
     *  Switch: '<S101>/Switch'
     *  Switch: '<S101>/Switch1'
     *  Trigonometry: '<S96>/Tanh'
     */
    rtb_TmpSignalConversionAtLook_o[0] = Rebuilt_Shoot_Dist_0;
    rtb_TmpSignalConversionAtLook_o[1] = Rebuilt_Shoot_Dist_1;
    rtb_TmpSignalConversionAtLook_o[2] = Rebuilt_Shoot_Dist_2;
    rtb_TmpSignalConversionAtLook_o[3] = Rebuilt_Shoot_Dist_3;
    rtb_TmpSignalConversionAtLook_o[4] = Rebuilt_Shoot_Dist_4;
    rtb_TmpSignalConversionAtLook_o[5] = Rebuilt_Shoot_Dist_5;
    rtb_TmpSignalConversionAtLook_o[6] = Rebuilt_Shoot_Dist_6;
    rtb_TmpSignalConversionAtLook_o[7] = Rebuilt_Shoot_Dist_7;

    /* End of Outputs for SubSystem: '<S95>/Iterate_Shot_Target' */
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
      /* Switch: '<S101>/Switch' incorporates:
       *  Constant: '<S101>/Constant'
       */
      Robot_Control_B.RB_Shoot_Target_X = Field_Blue_Hub_X;

      /* Switch: '<S101>/Switch1' incorporates:
       *  Constant: '<S101>/Constant1'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Blue_Hub_Y;
    } else {
      /* Switch: '<S101>/Switch' incorporates:
       *  Constant: '<S101>/Constant2'
       */
      Robot_Control_B.RB_Shoot_Target_X = Field_Red_Hub_X;

      /* Switch: '<S101>/Switch1' incorporates:
       *  Constant: '<S101>/Constant3'
       */
      Robot_Control_B.RB_Shoot_Target_Y = Field_Red_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S95>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S97>/While Iterator'
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
      /* Switch: '<S106>/Switch' incorporates:
       *  Memory: '<S97>/Memory1'
       *  Memory: '<S97>/Memory2'
       *  Switch: '<S106>/Switch1'
       */
      if (rtb_Button_Spinup_Enable > 1) {
        rtb_Init_o = rtb_Merge1;
        rtb_Sin4 = rtb_Add_h5;
      } else {
        rtb_Init_o = Robot_Control_B.RB_Shoot_Target_X;
        rtb_Sin4 = Robot_Control_B.RB_Shoot_Target_Y;
      }

      /* End of Switch: '<S106>/Switch' */

      /* Math: '<S104>/Hypot' incorporates:
       *  Sum: '<S104>/Subtract'
       *  Sum: '<S104>/Subtract1'
       */
      Robot_Control_B.RB_Desired_Shot_Distance = rt_hypotd_snf(rtb_Init_o -
        Robot_Control_B.KF_Position_X, rtb_Sin4 - Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S105>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S105>/Lookup Table Dynamic'
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

      /* Sum: '<S107>/Subtract' incorporates:
       *  Memory: '<S97>/Memory3'
       *  Sum: '<S107>/Subtract1'
       */
      rtb_Add_h5 = rtb_TOF - rtb_Switch4;

      /* Sum: '<S107>/Add' incorporates:
       *  Gain: '<S107>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S107>/Product'
       *  Sum: '<S107>/Subtract'
       */
      Robot_Control_B.RB_Desired_Target_X = (rtb_Add_h5 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Init_o;

      /* Sum: '<S107>/Add1' incorporates:
       *  Gain: '<S107>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S107>/Product1'
       */
      Robot_Control_B.RB_Desired_Target_Y = (rtb_Add_h5 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Sin4;

      /* Memory: '<S97>/Memory' */
      rtb_Compare_a = rtb_AND1_c;

      /* Update for Memory: '<S97>/Memory1' */
      rtb_Merge1 = Robot_Control_B.RB_Desired_Target_X;

      /* Update for Memory: '<S97>/Memory2' */
      rtb_Add_h5 = Robot_Control_B.RB_Desired_Target_Y;

      /* Update for Memory: '<S97>/Memory3' */
      rtb_Switch4 = rtb_TOF;

      /* Update for Memory: '<S97>/Memory' incorporates:
       *  Constant: '<S109>/Constant'
       *  Math: '<S108>/Hypot'
       *  RelationalOperator: '<S109>/Compare'
       *  Sum: '<S108>/Subtract'
       *  Sum: '<S108>/Subtract1'
       */
      rtb_AND1_c = (rt_hypotd_snf(Robot_Control_B.RB_Desired_Target_X -
        rtb_Init_o, Robot_Control_B.RB_Desired_Target_Y - rtb_Sin4) >=
                    Rebuilt_Shoot_Target_Error_Thresh);
      rtb_Button_Spinup_Enable++;
    }

    /* End of Outputs for SubSystem: '<S95>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S99>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S100>/Lookup Table Dynamic'
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

    /* Dynamic Look-Up Table Block: '<S98>/Lookup Table Dynamic'
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

    /* End of Outputs for SubSystem: '<S86>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_bn = Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

    /* Switch: '<S3>/Switch3' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     */
    rtb_Add_k = Robot_Control_U.Gyro_Angle_Field_rad;
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S86>/Shooter Not Active' incorporates:
     *  ActionPort: '<S94>/Action Port'
     */
    /* If: '<S86>/If' incorporates:
     *  Constant: '<S94>/Constant'
     *  Constant: '<S94>/Constant1'
     *  Constant: '<S94>/Constant2'
     *  Merge: '<S86>/Merge'
     *  Merge: '<S86>/Merge1'
     *  Merge: '<S86>/Merge2'
     *  Merge: '<S86>/Merge3'
     *  SignalConversion generated from: '<S94>/Desired_Gyro_Angle'
     *  UnitDelay: '<S86>/Unit Delay'
     */
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang = 0.0;
    Robot_Control_B.RB_Desired_Shooter_Speed = 0.0;
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error = 0.0;
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot =
      Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S86>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_bn = Robot_Control_B.Steering_Abs_Cmd_SPF;

    /* Switch: '<S3>/Switch3' */
    rtb_Add_k = Robot_Control_B.Gyro_Angle_SPF;
  }

  /* End of Chart: '<S11>/Shooter_Transfer_Feeder Chart' */

  /* Sum: '<S315>/Add1' incorporates:
   *  Constant: '<S315>/Constant3'
   *  Constant: '<S315>/Constant4'
   *  Math: '<S315>/Math Function'
   *  Sum: '<S314>/Sum'
   *  Sum: '<S315>/Add2'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Optimized_Module_Angle_p = rt_modd_snf((rtb_Add_bn - rtb_Add_k) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S317>/Sum1' incorporates:
   *  Constant: '<S314>/Constant2'
   *  Product: '<S317>/Product'
   *  Sum: '<S317>/Sum'
   *  UnitDelay: '<S317>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_Optimized_Module_Angle_p -
                 Robot_Control_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S314>/Product' incorporates:
   *  Constant: '<S314>/Constant3'
   */
  rtb_Add_h5 = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S316>/Diff' incorporates:
   *  UnitDelay: '<S316>/UD'
   *
   * Block description for '<S316>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S316>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Add_h5 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S314>/Saturation' */
  if (rtb_Add_bn > Steering_Heading_Control_D_UL) {
    rtb_Add_bn = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Heading_Control_D_LL) {
    rtb_Add_bn = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S314>/Add' incorporates:
   *  Gain: '<S314>/Gain1'
   *  Saturate: '<S314>/Saturation'
   */
  rtb_Init_o = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle_p) +
    rtb_Add_bn;

  /* Sum: '<S314>/Subtract' incorporates:
   *  Constant: '<S314>/Constant'
   */
  rtb_Sin4 = Steering_Heading_Control_Total_UL - rtb_Init_o;

  /* Sum: '<S314>/Sum2' incorporates:
   *  Gain: '<S314>/Gain2'
   *  UnitDelay: '<S314>/Unit Delay'
   */
  rtb_Switch4 = (Steering_Heading_Control_I * rtb_Optimized_Module_Angle_p) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S318>/Switch2' incorporates:
   *  RelationalOperator: '<S318>/LowerRelop1'
   */
  if (!(rtb_Switch4 > rtb_Sin4)) {
    /* Sum: '<S314>/Subtract1' incorporates:
     *  Constant: '<S314>/Constant1'
     */
    rtb_Sin4 = Steering_Heading_Control_Total_LL - rtb_Init_o;

    /* Switch: '<S318>/Switch' incorporates:
     *  RelationalOperator: '<S318>/UpperRelop'
     */
    if (!(rtb_Switch4 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch4;
    }

    /* End of Switch: '<S318>/Switch' */
  }

  /* End of Switch: '<S318>/Switch2' */

  /* Saturate: '<S314>/Saturation1' */
  if (rtb_Sin4 > Steering_Heading_Control_I_UL) {
    rtb_Switch4 = Steering_Heading_Control_I_UL;
  } else if (rtb_Sin4 < Steering_Heading_Control_I_LL) {
    rtb_Switch4 = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch4 = rtb_Sin4;
  }

  /* End of Saturate: '<S314>/Saturation1' */

  /* Sum: '<S314>/Add1' */
  rtb_Add_bn = rtb_Init_o + rtb_Switch4;

  /* Saturate: '<S314>/Saturation2' */
  if (rtb_Add_bn > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S314>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_bn < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S314>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S314>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_bn;
  }

  /* End of Saturate: '<S314>/Saturation2' */

  /* Switch: '<S298>/Switch' incorporates:
   *  Abs: '<S298>/Abs'
   *  Constant: '<S298>/Constant'
   *  Constant: '<S313>/Constant'
   *  RelationalOperator: '<S313>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Optimized_Module_Angle_p = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Optimized_Module_Angle_p = 0.0;
  }

  /* End of Switch: '<S298>/Switch' */

  /* Signum: '<S297>/Sign2' incorporates:
   *  UnitDelay: '<S297>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S297>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle_p)) {
    rtb_Add_k = (rtNaN);
  } else if (rtb_Optimized_Module_Angle_p < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (rtb_Optimized_Module_Angle_p > 0.0);
  }

  /* Product: '<S297>/Product1' incorporates:
   *  Signum: '<S297>/Sign1'
   *  Signum: '<S297>/Sign2'
   */
  rtb_Add_bn *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_bn)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_bn, 256.0);
  }

  /* Switch: '<S297>/Switch' incorporates:
   *  Constant: '<S297>/Constant'
   *  Constant: '<S306>/Constant'
   *  Constant: '<S307>/Constant'
   *  Logic: '<S297>/or'
   *  Product: '<S297>/Product1'
   *  RelationalOperator: '<S306>/Compare'
   *  RelationalOperator: '<S307>/Compare'
   *  UnitDelay: '<S297>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Init_g = rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Init_g = 0.0;
  }

  /* End of Switch: '<S297>/Switch' */

  /* Switch: '<S312>/Init' incorporates:
   *  UnitDelay: '<S312>/FixPt Unit Delay1'
   *  UnitDelay: '<S312>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Init_o = rtb_Init_g;
  } else {
    rtb_Init_o = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S312>/Init' */

  /* RelationalOperator: '<S308>/Compare' incorporates:
   *  Constant: '<S308>/Constant'
   */
  rtb_Compare_a = (rtb_Init_g == 0.0);

  /* RelationalOperator: '<S309>/Compare' incorporates:
   *  Constant: '<S309>/Constant'
   */
  rtb_AND1_c = (rtb_Init_g > 0.0);

  /* Abs: '<S297>/Abs' incorporates:
   *  Sum: '<S297>/Subtract'
   *  UnitDelay: '<S297>/Unit Delay'
   */
  rtb_Sin4 = fabs(Robot_Control_DW.UnitDelay_DSTATE_d -
                  rtb_Optimized_Module_Angle_p);

  /* Switch: '<S297>/Switch5' incorporates:
   *  Constant: '<S297>/Constant1'
   *  Switch: '<S297>/Switch1'
   *  UnaryMinus: '<S297>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S297>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S297>/Constant4'
     *  Constant: '<S297>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S297>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S297>/Constant2'
     *  Constant: '<S297>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S297>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S297>/Lookup Table Dynamic'
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
    rtb_Add_bn = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S297>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S297>/Constant10'
     *  Constant: '<S297>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S297>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S297>/Constant7'
     *  Constant: '<S297>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S297>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S297>/Lookup Table Dynamic1'
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

    /* Switch: '<S297>/Switch3' incorporates:
     *  Constant: '<S297>/Constant1'
     *  Constant: '<S297>/Constant3'
     *  UnaryMinus: '<S297>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_bn = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_bn = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S297>/Switch3' */
  }

  /* End of Switch: '<S297>/Switch5' */

  /* Product: '<S297>/Product' incorporates:
   *  Switch: '<S297>/Switch1'
   */
  rtb_Switch2_p2 = rtb_Add_bn * rtb_Sin4;

  /* Sum: '<S310>/Sum1' */
  rtb_Switch1 = rtb_Init_g - rtb_Init_o;

  /* Switch: '<S311>/Switch2' incorporates:
   *  RelationalOperator: '<S311>/LowerRelop1'
   */
  if (!(rtb_Switch1 > rtb_Switch2_p2)) {
    /* Switch: '<S297>/Switch2' incorporates:
     *  Constant: '<S297>/Constant1'
     *  Constant: '<S297>/Constant3'
     *  Switch: '<S297>/Switch4'
     *  UnaryMinus: '<S297>/Unary Minus1'
     */
    if (rtb_Compare_a) {
      rtb_Add_bn = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S297>/Switch4' incorporates:
       *  Constant: '<S297>/Constant1'
       */
      rtb_Add_bn = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_bn = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S297>/Product2' incorporates:
     *  Switch: '<S297>/Switch2'
     */
    rtb_Switch2 = rtb_Add_bn * rtb_Sin4;

    /* Switch: '<S311>/Switch' incorporates:
     *  RelationalOperator: '<S311>/UpperRelop'
     */
    if (rtb_Switch1 < rtb_Switch2) {
      rtb_Switch2_p2 = rtb_Switch2;
    } else {
      rtb_Switch2_p2 = rtb_Switch1;
    }

    /* End of Switch: '<S311>/Switch' */
  }

  /* End of Switch: '<S311>/Switch2' */

  /* Sum: '<S310>/Sum' */
  rtb_Init_o += rtb_Switch2_p2;

  /* Signum: '<S296>/Sign2' incorporates:
   *  UnitDelay: '<S296>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S296>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S296>/Product1' incorporates:
   *  Signum: '<S296>/Sign1'
   *  Signum: '<S296>/Sign2'
   */
  rtb_Add_bn *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_bn)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_bn, 256.0);
  }

  /* Switch: '<S296>/Switch' incorporates:
   *  Constant: '<S296>/Constant'
   *  Constant: '<S299>/Constant'
   *  Constant: '<S300>/Constant'
   *  Logic: '<S296>/or'
   *  Product: '<S296>/Product1'
   *  RelationalOperator: '<S299>/Compare'
   *  RelationalOperator: '<S300>/Compare'
   *  UnitDelay: '<S296>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Init_g = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Init_g = 0.0;
  }

  /* End of Switch: '<S296>/Switch' */

  /* Switch: '<S305>/Init' incorporates:
   *  UnitDelay: '<S305>/FixPt Unit Delay1'
   *  UnitDelay: '<S305>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Init_g;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S305>/Init' */

  /* RelationalOperator: '<S301>/Compare' incorporates:
   *  Constant: '<S301>/Constant'
   */
  rtb_Compare_a = (rtb_Init_g == 0.0);

  /* RelationalOperator: '<S302>/Compare' incorporates:
   *  Constant: '<S302>/Constant'
   */
  rtb_AND1_c = (rtb_Init_g > 0.0);

  /* Abs: '<S296>/Abs' incorporates:
   *  Sum: '<S296>/Subtract'
   *  UnitDelay: '<S296>/Unit Delay'
   */
  rtb_Switch1 = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                     Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S296>/Switch1' incorporates:
   *  Constant: '<S296>/Constant1'
   *  Switch: '<S296>/Switch3'
   *  Switch: '<S296>/Switch5'
   *  UnaryMinus: '<S296>/Unary Minus'
   */
  if (rtb_Compare_a) {
    rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S296>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S296>/Constant1'
     *  Constant: '<S296>/Constant4'
     *  Constant: '<S296>/Constant6'
     *  UnaryMinus: '<S296>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S296>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S296>/Constant2'
     *  Constant: '<S296>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S296>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S296>/Lookup Table Dynamic'
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
      /* Switch: '<S296>/Switch3' incorporates:
       *  Constant: '<S296>/Constant3'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S296>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S296>/Constant1'
     *  Constant: '<S296>/Constant10'
     *  Constant: '<S296>/Constant8'
     *  UnaryMinus: '<S296>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S296>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S296>/Constant7'
     *  Constant: '<S296>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S296>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S296>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S296>/Switch1' */

  /* Product: '<S296>/Product' */
  rtb_Sin4 *= rtb_Switch1;

  /* Sum: '<S303>/Sum1' */
  rtb_Switch2 = rtb_Init_g - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S304>/Switch2' incorporates:
   *  RelationalOperator: '<S304>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_Sin4)) {
    /* Switch: '<S296>/Switch2' incorporates:
     *  Constant: '<S296>/Constant1'
     *  Switch: '<S296>/Switch4'
     */
    if (rtb_Compare_a) {
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S296>/Switch4' incorporates:
       *  Constant: '<S296>/Constant1'
       */
      rtb_Sin4 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S296>/Switch4' incorporates:
       *  Constant: '<S296>/Constant3'
       *  UnaryMinus: '<S296>/Unary Minus1'
       */
      rtb_Sin4 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S296>/Switch2' */

    /* Product: '<S296>/Product2' */
    rtb_Sin4 *= rtb_Switch1;

    /* Switch: '<S304>/Switch' incorporates:
     *  RelationalOperator: '<S304>/UpperRelop'
     */
    if (!(rtb_Switch2 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2;
    }

    /* End of Switch: '<S304>/Switch' */
  }

  /* End of Switch: '<S304>/Switch2' */

  /* Sum: '<S303>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S286>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.RB_Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S286>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Init_o;
  } else {
    /* Switch: '<S286>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S286>/Switch' */

  /* Fcn: '<S327>/r->x' incorporates:
   *  Fcn: '<S332>/r->x'
   *  Fcn: '<S337>/r->x'
   *  Fcn: '<S342>/r->x'
   */
  rtb_Init_g = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S321>/Add' incorporates:
   *  Fcn: '<S327>/r->x'
   *  Fcn: '<S328>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Init_g;

  /* Fcn: '<S327>/theta->y' incorporates:
   *  Fcn: '<S332>/theta->y'
   *  Fcn: '<S337>/theta->y'
   *  Fcn: '<S342>/theta->y'
   */
  rtb_Switch2_p2 = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S321>/Add' incorporates:
   *  Fcn: '<S327>/theta->y'
   *  Fcn: '<S328>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S322>/Add' incorporates:
   *  Fcn: '<S333>/r->x'
   *  Fcn: '<S333>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Init_g;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S323>/Add' incorporates:
   *  Fcn: '<S338>/r->x'
   *  Fcn: '<S338>/theta->y'
   */
  rtb_Add2_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Init_g;
  rtb_Add2_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S324>/Add' incorporates:
   *  Fcn: '<S343>/r->x'
   *  Fcn: '<S343>/theta->y'
   */
  rtb_Switch1 = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Init_g;
  rtb_Switch2 = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2_p2;

  /* Fcn: '<S341>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Switch1, rtb_Switch2);

  /* RelationalOperator: '<S344>/Compare' incorporates:
   *  Constant: '<S344>/Constant'
   */
  rtb_AND1_c = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S340>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S340>/Switch1' incorporates:
     *  Constant: '<S340>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S340>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S340>/Switch1' */

  /* Fcn: '<S326>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S329>/Compare' incorporates:
   *  Constant: '<S329>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S325>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S325>/Switch1' incorporates:
     *  Constant: '<S325>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S325>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S325>/Switch1' */

  /* Fcn: '<S331>/x->r' */
  rtb_Init_g = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S334>/Compare' incorporates:
   *  Constant: '<S334>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Init_g == 0.0);

  /* Switch: '<S330>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S330>/Switch1' incorporates:
     *  Constant: '<S330>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S330>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Init_g;
  }

  /* End of Switch: '<S330>/Switch1' */

  /* Fcn: '<S336>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2_idx_0, rtb_Add2_idx_1);

  /* RelationalOperator: '<S339>/Compare' incorporates:
   *  Constant: '<S339>/Constant'
   */
  rtb_Compare_a = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S335>/Switch1' */
  if (rtb_Compare_a) {
    /* Switch: '<S335>/Switch1' incorporates:
     *  Constant: '<S335>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S335>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S335>/Switch1' */

  /* Product: '<S320>/Divide' incorporates:
   *  Abs: '<S320>/Abs'
   *  Abs: '<S320>/Abs1'
   *  Abs: '<S320>/Abs2'
   *  Abs: '<S320>/Abs3'
   *  Constant: '<S320>/Constant'
   *  MinMax: '<S320>/Max'
   */
  rtb_Switch2_p2 = 5.3893029530209224 / fmax(fmax(fmax(fmax(5.3893029530209224,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S320>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S340>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S340>/Switch' incorporates:
     *  Fcn: '<S341>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Switch2,
      rtb_Switch1);
  }

  /* End of Switch: '<S340>/Switch' */

  /* Trigonometry: '<S276>/Cos4' incorporates:
   *  Switch: '<S265>/Angle_Switch'
   *  Trigonometry: '<S275>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S276>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S274>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S276>/Sin4' incorporates:
   *  Switch: '<S265>/Angle_Switch'
   *  Trigonometry: '<S275>/Sin4'
   */
  rtb_Switch1 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S276>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S274>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S276>/Subtract1' incorporates:
   *  Product: '<S276>/Product2'
   *  Product: '<S276>/Product3'
   *  Trigonometry: '<S276>/Cos4'
   *  Trigonometry: '<S276>/Sin4'
   */
  rtb_Switch2 = (rtb_Add_k * rtb_Optimized_Module_Angle) + (rtb_Switch1 *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S276>/Subtract' incorporates:
   *  Product: '<S276>/Product'
   *  Product: '<S276>/Product1'
   *  Trigonometry: '<S276>/Cos4'
   *  Trigonometry: '<S276>/Sin4'
   */
  rtb_Init = (rtb_Add_k * rtb_Optimized_Module_Angle_p) - (rtb_Switch1 *
    rtb_Optimized_Module_Angle);

  /* Math: '<S276>/Hypot' */
  rtb_Hypot_pi = rt_hypotd_snf(rtb_Init, rtb_Switch2);

  /* Switch: '<S276>/Switch' incorporates:
   *  Constant: '<S276>/Constant'
   *  Constant: '<S276>/Constant1'
   *  Constant: '<S277>/Constant'
   *  Product: '<S276>/Divide'
   *  Product: '<S276>/Divide1'
   *  RelationalOperator: '<S277>/Compare'
   *  Switch: '<S276>/Switch1'
   */
  if (rtb_Hypot_pi > 1.0E-6) {
    rtb_Init_g = rtb_Switch2 / rtb_Hypot_pi;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Hypot_pi;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S276>/Switch' */

  /* Switch: '<S265>/Speed_Switch' incorporates:
   *  Abs: '<S265>/Abs'
   *  Constant: '<S273>/Constant'
   *  RelationalOperator: '<S273>/Compare'
   *  Switch: '<S265>/Angle_Switch'
   *  Trigonometry: '<S275>/Atan1'
   *  Trigonometry: '<S276>/Atan1'
   *  UnaryMinus: '<S265>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S275>/Subtract1' incorporates:
     *  Product: '<S275>/Product2'
     *  Product: '<S275>/Product3'
     *  UnaryMinus: '<S265>/Unary Minus'
     */
    rtb_Switch2 = (rtb_Add_k * Robot_Control_ConstB.Sin5_c) + (rtb_Switch1 *
      Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S275>/Subtract' incorporates:
     *  Product: '<S275>/Product'
     *  Product: '<S275>/Product1'
     */
    rtb_Init = (rtb_Add_k * Robot_Control_ConstB.Cos5_b) - (rtb_Switch1 *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S275>/Hypot' */
    rtb_Switch1 = rt_hypotd_snf(rtb_Init, rtb_Switch2);

    /* Switch: '<S275>/Switch1' incorporates:
     *  Constant: '<S275>/Constant'
     *  Constant: '<S275>/Constant1'
     *  Constant: '<S278>/Constant'
     *  Product: '<S275>/Divide'
     *  Product: '<S275>/Divide1'
     *  RelationalOperator: '<S278>/Compare'
     *  Switch: '<S275>/Switch'
     */
    if (rtb_Switch1 > 1.0E-6) {
      rtb_Init /= rtb_Switch1;
      rtb_Switch1 = rtb_Switch2 / rtb_Switch1;
    } else {
      rtb_Init = 1.0;
      rtb_Switch1 = 0.0;
    }

    /* End of Switch: '<S275>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Init);
  } else {
    rtb_Add_bn = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S268>/Product2' incorporates:
   *  Constant: '<S268>/Constant'
   *  Switch: '<S265>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1150.4270689634639;

  /* Signum: '<S263>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S263>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S266>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S267>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S198>/Product' incorporates:
   *  Abs: '<S263>/Abs'
   *  Abs: '<S266>/Abs'
   *  Constant: '<S269>/Constant'
   *  Constant: '<S279>/Constant3'
   *  Constant: '<S279>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
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
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966, 3.1415926535897931) -
          1.5707963267948966), rtCP_uDLookupTable_bp01Data,
     rtCP_uDLookupTable_tableData, 1U);

  /* Sum: '<S264>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Init = rtb_Init_g - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S271>/Sum1' incorporates:
   *  Constant: '<S264>/Constant2'
   *  Product: '<S271>/Product'
   *  Sum: '<S271>/Sum'
   *  UnitDelay: '<S271>/Unit Delay1'
   */
  rtb_Switch1 = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                 Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S264>/Product' incorporates:
   *  Constant: '<S264>/Constant3'
   */
  rtb_Switch2 = rtb_Switch1 * Drive_Motor_Control_D;

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
  rtb_Add_bn = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S264>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S264>/Add' incorporates:
   *  Gain: '<S264>/Gain'
   *  Gain: '<S264>/Gain1'
   *  Saturate: '<S264>/Saturation'
   */
  rtb_Hypot_pi = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P
    * rtb_Init)) + rtb_Add_bn;

  /* Saturate: '<S264>/Saturation2' incorporates:
   *  Sum: '<S264>/Add1'
   */
  if (rtb_Hypot_pi > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Hypot_pi < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_Hypot_pi;
  }

  /* End of Saturate: '<S264>/Saturation2' */

  /* Switch: '<S325>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S325>/Switch' incorporates:
     *  Fcn: '<S326>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S325>/Switch' */

  /* Trigonometry: '<S213>/Cos4' incorporates:
   *  Switch: '<S202>/Angle_Switch'
   *  Trigonometry: '<S212>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S213>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S211>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S213>/Sin4' incorporates:
   *  Switch: '<S202>/Angle_Switch'
   *  Trigonometry: '<S212>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S213>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S211>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S213>/Subtract1' incorporates:
   *  Product: '<S213>/Product2'
   *  Product: '<S213>/Product3'
   *  Trigonometry: '<S213>/Cos4'
   *  Trigonometry: '<S213>/Sin4'
   */
  rtb_Hypot_pi = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S213>/Subtract' incorporates:
   *  Product: '<S213>/Product'
   *  Product: '<S213>/Product1'
   *  Trigonometry: '<S213>/Cos4'
   *  Trigonometry: '<S213>/Sin4'
   */
  rtb_Init = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S213>/Hypot' */
  rtb_Hypot_fg = rt_hypotd_snf(rtb_Init, rtb_Hypot_pi);

  /* Switch: '<S213>/Switch' incorporates:
   *  Constant: '<S213>/Constant'
   *  Constant: '<S213>/Constant1'
   *  Constant: '<S214>/Constant'
   *  Product: '<S213>/Divide'
   *  Product: '<S213>/Divide1'
   *  RelationalOperator: '<S214>/Compare'
   *  Switch: '<S213>/Switch1'
   */
  if (rtb_Hypot_fg > 1.0E-6) {
    rtb_Init_g = rtb_Hypot_pi / rtb_Hypot_fg;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Hypot_fg;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S213>/Switch' */

  /* Product: '<S320>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S202>/Speed_Switch' incorporates:
   *  Abs: '<S202>/Abs'
   *  Constant: '<S210>/Constant'
   *  RelationalOperator: '<S210>/Compare'
   *  Switch: '<S202>/Angle_Switch'
   *  Trigonometry: '<S212>/Atan1'
   *  Trigonometry: '<S213>/Atan1'
   *  UnaryMinus: '<S202>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S212>/Subtract1' incorporates:
     *  Product: '<S212>/Product2'
     *  Product: '<S212>/Product3'
     *  UnaryMinus: '<S202>/Unary Minus'
     */
    rtb_Hypot_pi = (rtb_Add_k * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S212>/Subtract' incorporates:
     *  Product: '<S212>/Product'
     *  Product: '<S212>/Product1'
     */
    rtb_Hypot_fg = (rtb_Add_k * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S212>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Hypot_fg, rtb_Hypot_pi);

    /* Switch: '<S212>/Switch1' incorporates:
     *  Constant: '<S212>/Constant'
     *  Constant: '<S212>/Constant1'
     *  Constant: '<S215>/Constant'
     *  Product: '<S212>/Divide'
     *  Product: '<S212>/Divide1'
     *  RelationalOperator: '<S215>/Compare'
     *  Switch: '<S212>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Hypot_fg /= rtb_Init;
      rtb_Hypot_pi /= rtb_Init;
    } else {
      rtb_Hypot_fg = 1.0;
      rtb_Hypot_pi = 0.0;
    }

    /* End of Switch: '<S212>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Hypot_pi, rtb_Hypot_fg);
  } else {
    rtb_Add_bn = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S205>/Product2' incorporates:
   *  Constant: '<S205>/Constant'
   *  Switch: '<S202>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1150.4270689634639;

  /* Signum: '<S200>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S200>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S203>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S204>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S195>/Product' incorporates:
   *  Abs: '<S200>/Abs'
   *  Abs: '<S203>/Abs'
   *  Constant: '<S206>/Constant'
   *  Constant: '<S216>/Constant3'
   *  Constant: '<S216>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S200>/OR'
   *  Lookup_n-D: '<S203>/1-D Lookup Table'
   *  Math: '<S216>/Math Function'
   *  RelationalOperator: '<S200>/Equal1'
   *  RelationalOperator: '<S206>/Compare'
   *  Signum: '<S200>/Sign'
   *  Signum: '<S200>/Sign1'
   *  Sum: '<S203>/Add'
   *  Sum: '<S216>/Add1'
   *  Sum: '<S216>/Add2'
   */
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S201>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_fg = rtb_Init_g - Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S208>/Sum1' incorporates:
   *  Constant: '<S201>/Constant2'
   *  Product: '<S208>/Product'
   *  Sum: '<S208>/Sum'
   *  UnitDelay: '<S208>/Unit Delay1'
   */
  rtb_Hypot_pi = ((rtb_Hypot_fg - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S201>/Product' incorporates:
   *  Constant: '<S201>/Constant3'
   */
  rtb_Init = rtb_Hypot_pi * Drive_Motor_Control_D;

  /* Sum: '<S207>/Diff' incorporates:
   *  UnitDelay: '<S207>/UD'
   *
   * Block description for '<S207>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S207>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Init - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S201>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S201>/Add' incorporates:
   *  Gain: '<S201>/Gain'
   *  Gain: '<S201>/Gain1'
   *  Saturate: '<S201>/Saturation'
   */
  rtb_Hypot_fg = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P
    * rtb_Hypot_fg)) + rtb_Add_bn;

  /* Saturate: '<S201>/Saturation2' incorporates:
   *  Sum: '<S201>/Add1'
   */
  if (rtb_Hypot_fg > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Hypot_fg < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = rtb_Hypot_fg;
  }

  /* End of Saturate: '<S201>/Saturation2' */

  /* Sum: '<S217>/Add1' incorporates:
   *  Constant: '<S217>/Constant3'
   *  Constant: '<S217>/Constant4'
   *  Math: '<S217>/Math Function'
   *  Sum: '<S217>/Add2'
   */
  rtb_Init_g = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S219>/Sum1' incorporates:
   *  Constant: '<S204>/Constant2'
   *  Product: '<S219>/Product'
   *  Sum: '<S219>/Sum'
   *  UnitDelay: '<S219>/Unit Delay1'
   */
  rtb_Hypot_fg = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S204>/Product' incorporates:
   *  Constant: '<S204>/Constant3'
   */
  rtb_Switch2_dp = rtb_Hypot_fg * Steering_Motor_Control_D;

  /* Sum: '<S218>/Diff' incorporates:
   *  UnitDelay: '<S218>/UD'
   *
   * Block description for '<S218>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S218>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Switch2_dp - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S204>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S204>/Add' incorporates:
   *  Gain: '<S204>/Gain1'
   *  Saturate: '<S204>/Saturation'
   */
  rtb_Add_fn = (Steering_Motor_Control_P * rtb_Init_g) + rtb_Add_bn;

  /* Sum: '<S204>/Subtract' incorporates:
   *  Constant: '<S204>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_fn;

  /* Sum: '<S204>/Sum2' incorporates:
   *  Gain: '<S204>/Gain2'
   *  UnitDelay: '<S204>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Init_g) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S220>/Switch2' incorporates:
   *  Constant: '<S204>/Constant'
   *  RelationalOperator: '<S220>/LowerRelop1'
   *  Sum: '<S204>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_fn))) {
    /* Switch: '<S220>/Switch' incorporates:
     *  Constant: '<S204>/Constant1'
     *  RelationalOperator: '<S220>/UpperRelop'
     *  Sum: '<S204>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_fn)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_fn;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S220>/Switch' */
  }

  /* End of Switch: '<S220>/Switch2' */

  /* Saturate: '<S204>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S204>/Saturation1' */

  /* Sum: '<S204>/Add1' */
  rtb_Add_bn = rtb_Add_fn + rtb_Sum2_e;

  /* Saturate: '<S204>/Saturation2' */
  if (rtb_Add_bn > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_bn < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_bn;
  }

  /* End of Saturate: '<S204>/Saturation2' */

  /* Switch: '<S330>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S330>/Switch' incorporates:
     *  Fcn: '<S331>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S330>/Switch' */

  /* Trigonometry: '<S234>/Cos4' incorporates:
   *  Switch: '<S223>/Angle_Switch'
   *  Trigonometry: '<S233>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S234>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S232>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S234>/Sin4' incorporates:
   *  Switch: '<S223>/Angle_Switch'
   *  Trigonometry: '<S233>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S234>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S232>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S234>/Subtract1' incorporates:
   *  Product: '<S234>/Product2'
   *  Product: '<S234>/Product3'
   *  Trigonometry: '<S234>/Cos4'
   *  Trigonometry: '<S234>/Sin4'
   */
  rtb_Add_fn = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S234>/Subtract' incorporates:
   *  Product: '<S234>/Product'
   *  Product: '<S234>/Product1'
   *  Trigonometry: '<S234>/Cos4'
   *  Trigonometry: '<S234>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S234>/Hypot' */
  rtb_uDLookupTable = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_fn);

  /* Switch: '<S234>/Switch' incorporates:
   *  Constant: '<S234>/Constant'
   *  Constant: '<S234>/Constant1'
   *  Constant: '<S235>/Constant'
   *  Product: '<S234>/Divide'
   *  Product: '<S234>/Divide1'
   *  RelationalOperator: '<S235>/Compare'
   *  Switch: '<S234>/Switch1'
   */
  if (rtb_uDLookupTable > 1.0E-6) {
    rtb_Init_g = rtb_Add_fn / rtb_uDLookupTable;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_uDLookupTable;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S234>/Switch' */

  /* Product: '<S320>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S223>/Speed_Switch' incorporates:
   *  Abs: '<S223>/Abs'
   *  Constant: '<S231>/Constant'
   *  RelationalOperator: '<S231>/Compare'
   *  Switch: '<S223>/Angle_Switch'
   *  Trigonometry: '<S233>/Atan1'
   *  Trigonometry: '<S234>/Atan1'
   *  UnaryMinus: '<S223>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S233>/Subtract1' incorporates:
     *  Product: '<S233>/Product2'
     *  Product: '<S233>/Product3'
     *  UnaryMinus: '<S223>/Unary Minus'
     */
    rtb_Add_fn = (rtb_Add_k * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S233>/Subtract' incorporates:
     *  Product: '<S233>/Product'
     *  Product: '<S233>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_k * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S233>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_uDLookupTable, rtb_Add_fn);

    /* Switch: '<S233>/Switch1' incorporates:
     *  Constant: '<S233>/Constant'
     *  Constant: '<S233>/Constant1'
     *  Constant: '<S236>/Constant'
     *  Product: '<S233>/Divide'
     *  Product: '<S233>/Divide1'
     *  RelationalOperator: '<S236>/Compare'
     *  Switch: '<S233>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Subtract1_la;
      rtb_Add_fn /= rtb_Subtract1_la;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Add_fn = 0.0;
    }

    /* End of Switch: '<S233>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_fn, rtb_uDLookupTable);
  } else {
    rtb_Add_bn = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S226>/Product2' incorporates:
   *  Constant: '<S226>/Constant'
   *  Switch: '<S223>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1150.4270689634639;

  /* Signum: '<S221>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S221>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S224>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S225>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S196>/Product' incorporates:
   *  Abs: '<S221>/Abs'
   *  Abs: '<S224>/Abs'
   *  Constant: '<S227>/Constant'
   *  Constant: '<S237>/Constant3'
   *  Constant: '<S237>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
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
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S222>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_uDLookupTable = rtb_Init_g - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S229>/Sum1' incorporates:
   *  Constant: '<S222>/Constant2'
   *  Product: '<S229>/Product'
   *  Sum: '<S229>/Sum'
   *  UnitDelay: '<S229>/Unit Delay1'
   */
  rtb_Add_fn = ((rtb_uDLookupTable - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S222>/Product' incorporates:
   *  Constant: '<S222>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_fn * Drive_Motor_Control_D;

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
  rtb_Add_bn = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S222>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S222>/Add' incorporates:
   *  Gain: '<S222>/Gain'
   *  Gain: '<S222>/Gain1'
   *  Saturate: '<S222>/Saturation'
   */
  rtb_Init_g = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P *
    rtb_uDLookupTable)) + rtb_Add_bn;

  /* Saturate: '<S222>/Saturation2' incorporates:
   *  Sum: '<S222>/Add1'
   */
  if (rtb_Init_g > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Init_g < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = rtb_Init_g;
  }

  /* End of Saturate: '<S222>/Saturation2' */

  /* Sum: '<S238>/Add1' incorporates:
   *  Constant: '<S238>/Constant3'
   *  Constant: '<S238>/Constant4'
   *  Math: '<S238>/Math Function'
   *  Sum: '<S238>/Add2'
   */
  rtb_Init_g = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S240>/Sum1' incorporates:
   *  Constant: '<S225>/Constant2'
   *  Product: '<S240>/Product'
   *  Sum: '<S240>/Sum'
   *  UnitDelay: '<S240>/Unit Delay1'
   */
  rtb_Switch2_m = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                   Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S225>/Product' incorporates:
   *  Constant: '<S225>/Constant3'
   */
  rtb_Product_hi = rtb_Switch2_m * Steering_Motor_Control_D;

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
  rtb_Add_bn = rtb_Product_hi - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S225>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S225>/Add' incorporates:
   *  Gain: '<S225>/Gain1'
   *  Saturate: '<S225>/Saturation'
   */
  rtb_Add_k = (Steering_Motor_Control_P * rtb_Init_g) + rtb_Add_bn;

  /* Sum: '<S225>/Subtract' incorporates:
   *  Constant: '<S225>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_k;

  /* Sum: '<S225>/Sum2' incorporates:
   *  Gain: '<S225>/Gain2'
   *  UnitDelay: '<S225>/Unit Delay'
   */
  rtb_Init_g = (Steering_Motor_Control_I * rtb_Init_g) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S241>/Switch2' incorporates:
   *  Constant: '<S225>/Constant'
   *  RelationalOperator: '<S241>/LowerRelop1'
   *  Sum: '<S225>/Subtract'
   */
  if (!(rtb_Init_g > (1.0 - rtb_Add_k))) {
    /* Switch: '<S241>/Switch' incorporates:
     *  Constant: '<S225>/Constant1'
     *  RelationalOperator: '<S241>/UpperRelop'
     *  Sum: '<S225>/Subtract1'
     */
    if (rtb_Init_g < (-1.0 - rtb_Add_k)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_k;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Init_g;
    }

    /* End of Switch: '<S241>/Switch' */
  }

  /* End of Switch: '<S241>/Switch2' */

  /* Saturate: '<S225>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S225>/Saturation1' */

  /* Sum: '<S225>/Add1' */
  rtb_Add_bn = rtb_Add_k + rtb_Subtract1_kg;

  /* Saturate: '<S225>/Saturation2' */
  if (rtb_Add_bn > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_bn < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_bn;
  }

  /* End of Saturate: '<S225>/Saturation2' */

  /* Switch: '<S335>/Switch' */
  if (!rtb_Compare_a) {
    /* Switch: '<S335>/Switch' incorporates:
     *  Fcn: '<S336>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2_idx_1,
      rtb_Add2_idx_0);
  }

  /* End of Switch: '<S335>/Switch' */

  /* Trigonometry: '<S255>/Cos4' incorporates:
   *  Switch: '<S244>/Angle_Switch'
   *  Trigonometry: '<S254>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S255>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S253>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S255>/Sin4' incorporates:
   *  Switch: '<S244>/Angle_Switch'
   *  Trigonometry: '<S254>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S255>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S253>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S255>/Subtract1' incorporates:
   *  Product: '<S255>/Product2'
   *  Product: '<S255>/Product3'
   *  Trigonometry: '<S255>/Cos4'
   *  Trigonometry: '<S255>/Sin4'
   */
  rtb_Init_g = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S255>/Subtract' incorporates:
   *  Product: '<S255>/Product'
   *  Product: '<S255>/Product1'
   *  Trigonometry: '<S255>/Cos4'
   *  Trigonometry: '<S255>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S255>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Init_g);

  /* Switch: '<S255>/Switch' incorporates:
   *  Constant: '<S255>/Constant'
   *  Constant: '<S255>/Constant1'
   *  Constant: '<S256>/Constant'
   *  Product: '<S255>/Divide'
   *  Product: '<S255>/Divide1'
   *  RelationalOperator: '<S256>/Compare'
   *  Switch: '<S255>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Init_g /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S255>/Switch' */

  /* Product: '<S320>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S244>/Speed_Switch' incorporates:
   *  Abs: '<S244>/Abs'
   *  Constant: '<S252>/Constant'
   *  RelationalOperator: '<S252>/Compare'
   *  Switch: '<S244>/Angle_Switch'
   *  Trigonometry: '<S254>/Atan1'
   *  Trigonometry: '<S255>/Atan1'
   *  UnaryMinus: '<S244>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S254>/Subtract1' incorporates:
     *  Product: '<S254>/Product2'
     *  Product: '<S254>/Product3'
     *  UnaryMinus: '<S244>/Unary Minus'
     */
    rtb_Init_g = (rtb_Add_k * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S254>/Subtract' incorporates:
     *  Product: '<S254>/Product'
     *  Product: '<S254>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_k * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S254>/Hypot' */
    rtb_Add_k = rt_hypotd_snf(rtb_uDLookupTable, rtb_Init_g);

    /* Switch: '<S254>/Switch1' incorporates:
     *  Constant: '<S254>/Constant'
     *  Constant: '<S254>/Constant1'
     *  Constant: '<S257>/Constant'
     *  Product: '<S254>/Divide'
     *  Product: '<S254>/Divide1'
     *  RelationalOperator: '<S257>/Compare'
     *  Switch: '<S254>/Switch'
     */
    if (rtb_Add_k > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Add_k;
      rtb_Init_g /= rtb_Add_k;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Init_g = 0.0;
    }

    /* End of Switch: '<S254>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Init_g, rtb_uDLookupTable);
  } else {
    rtb_Add_bn = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S247>/Product2' incorporates:
   *  Constant: '<S247>/Constant'
   *  Switch: '<S244>/Speed_Switch'
   */
  rtb_Switch2_p2 = rtb_Add_bn * 1150.4270689634639;

  /* Signum: '<S242>/Sign' */
  if (rtIsNaN(rtb_Switch2_p2)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Switch2_p2 < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Switch2_p2 > 0.0);
  }

  /* Signum: '<S242>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S245>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S246>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S197>/Product' incorporates:
   *  Abs: '<S242>/Abs'
   *  Abs: '<S245>/Abs'
   *  Constant: '<S248>/Constant'
   *  Constant: '<S258>/Constant3'
   *  Constant: '<S258>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
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
  rtb_Switch2_p2 = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p2) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Sum: '<S243>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Init_g = rtb_Switch2_p2 - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S250>/Sum1' incorporates:
   *  Constant: '<S243>/Constant2'
   *  Product: '<S250>/Product'
   *  Sum: '<S250>/Sum'
   *  UnitDelay: '<S250>/Unit Delay1'
   */
  rtb_Add_k = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S243>/Product' incorporates:
   *  Constant: '<S243>/Constant3'
   */
  rtb_uDLookupTable = rtb_Add_k * Drive_Motor_Control_D;

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
  rtb_Add_bn = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S243>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S243>/Add' incorporates:
   *  Gain: '<S243>/Gain'
   *  Gain: '<S243>/Gain1'
   *  Saturate: '<S243>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_p2) +
                    (Drive_Motor_Control_P * rtb_Init_g)) + rtb_Add_bn;

  /* Saturate: '<S243>/Saturation2' incorporates:
   *  Sum: '<S243>/Add1'
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

  /* End of Saturate: '<S243>/Saturation2' */

  /* Sum: '<S259>/Add1' incorporates:
   *  Constant: '<S259>/Constant3'
   *  Constant: '<S259>/Constant4'
   *  Math: '<S259>/Math Function'
   *  Sum: '<S259>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S261>/Sum1' incorporates:
   *  Constant: '<S246>/Constant2'
   *  Product: '<S261>/Product'
   *  Sum: '<S261>/Sum'
   *  UnitDelay: '<S261>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S246>/Product' incorporates:
   *  Constant: '<S246>/Constant3'
   */
  rtb_Add2_idx_0 = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

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
  rtb_Add_bn = rtb_Add2_idx_0 - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S246>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S246>/Add' incorporates:
   *  Gain: '<S246>/Gain1'
   *  Saturate: '<S246>/Saturation'
   */
  rtb_Add2_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_bn;

  /* Sum: '<S246>/Subtract' incorporates:
   *  Constant: '<S246>/Constant'
   */
  rtb_Init_g = 1.0 - rtb_Add2_idx_1;

  /* Sum: '<S246>/Sum2' incorporates:
   *  Gain: '<S246>/Gain2'
   *  UnitDelay: '<S246>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S262>/Switch2' incorporates:
   *  Constant: '<S246>/Constant'
   *  RelationalOperator: '<S262>/LowerRelop1'
   *  Sum: '<S246>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add2_idx_1))) {
    /* Sum: '<S246>/Subtract1' incorporates:
     *  Constant: '<S246>/Constant1'
     */
    rtb_Init_g = -1.0 - rtb_Add2_idx_1;

    /* Switch: '<S262>/Switch' incorporates:
     *  Constant: '<S246>/Constant1'
     *  RelationalOperator: '<S262>/UpperRelop'
     *  Sum: '<S246>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add2_idx_1))) {
      rtb_Init_g = rtb_Switch2_p2;
    }

    /* End of Switch: '<S262>/Switch' */
  }

  /* End of Switch: '<S262>/Switch2' */

  /* Saturate: '<S246>/Saturation1' */
  if (rtb_Init_g > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Init_g < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Init_g;
  }

  /* End of Saturate: '<S246>/Saturation1' */

  /* Sum: '<S246>/Add1' */
  rtb_Add_bn = rtb_Add2_idx_1 + rtb_Integral_ga;

  /* Saturate: '<S246>/Saturation2' */
  if (rtb_Add_bn > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_bn < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_bn;
  }

  /* End of Saturate: '<S246>/Saturation2' */

  /* Sum: '<S280>/Add1' incorporates:
   *  Constant: '<S280>/Constant3'
   *  Constant: '<S280>/Constant4'
   *  Math: '<S280>/Math Function'
   *  Sum: '<S280>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S282>/Sum1' incorporates:
   *  Constant: '<S267>/Constant2'
   *  Product: '<S282>/Product'
   *  Sum: '<S282>/Sum'
   *  UnitDelay: '<S282>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S267>/Product' incorporates:
   *  Constant: '<S267>/Constant3'
   */
  rtb_Add2_idx_1 = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

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
  rtb_Add_bn = rtb_Add2_idx_1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S267>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S267>/Add' incorporates:
   *  Gain: '<S267>/Gain1'
   *  Saturate: '<S267>/Saturation'
   */
  rtb_Add_jp = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_bn;

  /* Sum: '<S267>/Subtract' incorporates:
   *  Constant: '<S267>/Constant'
   */
  rtb_Init_g = 1.0 - rtb_Add_jp;

  /* Sum: '<S267>/Sum2' incorporates:
   *  Gain: '<S267>/Gain2'
   *  UnitDelay: '<S267>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S283>/Switch2' incorporates:
   *  Constant: '<S267>/Constant'
   *  RelationalOperator: '<S283>/LowerRelop1'
   *  Sum: '<S267>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_jp))) {
    /* Sum: '<S267>/Subtract1' incorporates:
     *  Constant: '<S267>/Constant1'
     */
    rtb_Init_g = -1.0 - rtb_Add_jp;

    /* Switch: '<S283>/Switch' incorporates:
     *  Constant: '<S267>/Constant1'
     *  RelationalOperator: '<S283>/UpperRelop'
     *  Sum: '<S267>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_jp))) {
      rtb_Init_g = rtb_Switch2_p2;
    }

    /* End of Switch: '<S283>/Switch' */
  }

  /* End of Switch: '<S283>/Switch2' */

  /* Saturate: '<S267>/Saturation1' */
  if (rtb_Init_g > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Init_g < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Init_g;
  }

  /* End of Saturate: '<S267>/Saturation1' */

  /* Sum: '<S267>/Add1' */
  rtb_Add_bn = rtb_Add_jp + rtb_Integral_bj;

  /* Saturate: '<S267>/Saturation2' */
  if (rtb_Add_bn > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_bn < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_bn;
  }

  /* End of Saturate: '<S267>/Saturation2' */

  /* Sum: '<S130>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S92>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.RB_Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S132>/Sum1' incorporates:
   *  Constant: '<S130>/Constant2'
   *  Product: '<S132>/Product'
   *  Sum: '<S130>/Sum'
   *  Sum: '<S132>/Sum'
   *  UnitDelay: '<S132>/Unit Delay1'
   */
  rtb_Add_jp = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S130>/Product' incorporates:
   *  Constant: '<S130>/Constant3'
   */
  rtb_Product_lo = rtb_Add_jp * 0.0;

  /* Sum: '<S131>/Diff' incorporates:
   *  UnitDelay: '<S131>/UD'
   *
   * Block description for '<S131>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S131>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S130>/Saturation' */
  if (rtb_Add_bn > 0.1) {
    rtb_Add_bn = 0.1;
  } else if (rtb_Add_bn < -0.1) {
    rtb_Add_bn = -0.1;
  }

  /* Sum: '<S130>/Add' incorporates:
   *  Gain: '<S130>/Gain'
   *  Gain: '<S130>/Gain1'
   *  Saturate: '<S130>/Saturation'
   *  Sum: '<S130>/Sum'
   */
  rtb_Switch2_p2 = ((Rebuilt_Transfer_Motor_Gain_FF *
                     Robot_Control_B.RB_Desired_Transfer_Speed) +
                    (Rebuilt_Transfer_Motor_Gain_P * rtb_Integral_d)) +
    rtb_Add_bn;

  /* Logic: '<S92>/Logical Operator1' incorporates:
   *  Constant: '<S129>/Constant'
   *  RelationalOperator: '<S129>/Compare'
   */
  rtb_Is_Absolute_Steering = !(Robot_Control_B.RB_Desired_Transfer_Speed == 0.0);

  /* Switch: '<S92>/Switch1' incorporates:
   *  Abs: '<S92>/Abs'
   *  Constant: '<S92>/Constant1'
   *  Constant: '<S92>/Constant2'
   *  Logic: '<S92>/Logical Operator'
   *  Logic: '<S92>/Logical Operator1'
   *  RelationalOperator: '<S92>/LessThan'
   *  UnitDelay: '<S92>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Rebuilt_Transfer_Error_Integral_Enable) &&
      rtb_Is_Absolute_Steering) {
    rtb_AND1_c = true;
  } else {
    rtb_AND1_c = (rtb_Is_Absolute_Steering &&
                  (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S92>/Switch1' */

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S130>/Constant4'
   */
  if (rtb_AND1_c) {
    /* Sum: '<S130>/Sum2' incorporates:
     *  Gain: '<S130>/Gain2'
     *  Sum: '<S130>/Sum'
     *  UnitDelay: '<S130>/Unit Delay'
     */
    rtb_Init_g = (Rebuilt_Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S130>/Subtract' incorporates:
     *  Constant: '<S130>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Switch2_p2;

    /* Switch: '<S133>/Switch2' incorporates:
     *  Constant: '<S130>/Constant'
     *  RelationalOperator: '<S133>/LowerRelop1'
     *  Sum: '<S130>/Subtract'
     */
    if (!(rtb_Init_g > (1.0 - rtb_Switch2_p2))) {
      /* Sum: '<S130>/Subtract1' incorporates:
       *  Constant: '<S130>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Switch2_p2;

      /* Switch: '<S133>/Switch' incorporates:
       *  Constant: '<S130>/Constant1'
       *  RelationalOperator: '<S133>/UpperRelop'
       *  Sum: '<S130>/Subtract1'
       */
      if (!(rtb_Init_g < (-1.0 - rtb_Switch2_p2))) {
        rtb_Integral_d = rtb_Init_g;
      }

      /* End of Switch: '<S133>/Switch' */
    }

    /* End of Switch: '<S133>/Switch2' */

    /* Saturate: '<S130>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S130>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S130>/Switch' */

  /* Switch: '<S92>/Switch2' incorporates:
   *  Logic: '<S92>/Logical Operator1'
   */
  if (rtb_Is_Absolute_Steering) {
    /* Sum: '<S130>/Add1' */
    rtb_Add_bn = rtb_Switch2_p2 + rtb_Integral_d;

    /* Saturate: '<S130>/Saturation2' */
    if (rtb_Add_bn > 1.0) {
      /* Switch: '<S92>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_bn < -1.0) {
      /* Switch: '<S92>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S92>/Switch2' */
      Robot_Control_B.RB_Transfer_Motor_PID_DC = rtb_Add_bn;
    }

    /* End of Saturate: '<S130>/Saturation2' */
  } else {
    /* Switch: '<S92>/Switch2' incorporates:
     *  Constant: '<S92>/Constant3'
     */
    Robot_Control_B.RB_Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S92>/Switch2' */

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S11>/Constant'
   */
  Robot_Control_B.RB_Feeder_Motor_PID_DC =
    Robot_Control_B.RB_Desired_Feeder_Speed * Rebuilt_Feeder_Motor_Gain_FF;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant6'
   *  Switch: '<S9>/Switch1'
   *  Switch: '<S9>/Switch5'
   *  Switch: '<S9>/Switch6'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Transfer_Motor_DC' incorporates:
     *  Constant: '<S9>/Constant1'
     */
    Robot_Control_Y.Transfer_Motor_DC = TEST_Transfer_Motor_DC_OV;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S9>/Constant7'
     *  DataTypeConversion: '<S9>/Data Type Conversion'
     */
    Robot_Control_Y.Desired_Hood_Enable = (TEST_Desired_Hood_Enable_OV != 0.0);

    /* Outport: '<Root>/Feeder_Motor_DC' incorporates:
     *  Constant: '<S9>/Constant2'
     */
    Robot_Control_Y.Feeder_Motor_DC = TEST_Feeder_Motor_DC_OV;
    rtb_Switch2_p2 = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Transfer_Motor_DC' */
    Robot_Control_Y.Transfer_Motor_DC = Robot_Control_B.RB_Transfer_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S9>/Constant8'
     */
    Robot_Control_Y.Desired_Hood_Enable = true;

    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.RB_Feeder_Motor_PID_DC;
    rtb_Switch2_p2 = Robot_Control_B.RB_Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Switch: '<S9>/Switch5'
   */
  if (rtb_Switch2_p2 > Rebuilt_Hood_Servo_Pos_Max) {
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Pos_Max;
  } else if (rtb_Switch2_p2 < Rebuilt_Hood_Servo_Pos_Min) {
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Switch2_p2;

  /* Switch: '<S84>/Init' incorporates:
   *  UnitDelay: '<S84>/FixPt Unit Delay1'
   *  UnitDelay: '<S84>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Init_g = rtb_Switch2_p2;
  } else {
    rtb_Init_g = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S84>/Init' */

  /* Sum: '<S82>/Sum1' */
  rtb_Switch2_p2 -= rtb_Init_g;

  /* Switch: '<S83>/Switch2' incorporates:
   *  Constant: '<S81>/Constant1'
   *  Constant: '<S81>/Constant3'
   *  RelationalOperator: '<S83>/LowerRelop1'
   *  RelationalOperator: '<S83>/UpperRelop'
   *  Switch: '<S83>/Switch'
   */
  if (rtb_Switch2_p2 > Rebuilt_Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch2_p2 < Rebuilt_Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S83>/Switch' incorporates:
     *  Constant: '<S81>/Constant1'
     */
    rtb_Switch2_p2 = Rebuilt_Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S83>/Switch2' */

  /* Sum: '<S82>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Switch2_p2 + rtb_Init_g;

  /* Logic: '<S90>/Logical Operator1' incorporates:
   *  Constant: '<S124>/Constant'
   *  RelationalOperator: '<S124>/Compare'
   */
  rtb_Is_Absolute_Steering = !(Robot_Control_B.RB_Desired_Shooter_Speed == 0.0);

  /* Sum: '<S125>/Sum' incorporates:
   *  Sum: '<S90>/Subtract'
   */
  rtb_Error_d = Robot_Control_B.RB_Desired_Shooter_Speed -
    Robot_Control_B.RB_Meas_Shooter_Speed_Max;

  /* Sum: '<S127>/Sum1' incorporates:
   *  Constant: '<S125>/Constant2'
   *  Product: '<S127>/Product'
   *  Sum: '<S125>/Sum'
   *  Sum: '<S127>/Sum'
   *  UnitDelay: '<S127>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_Error_d - Robot_Control_DW.UnitDelay1_DSTATE_d) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_d;

  /* Product: '<S125>/Product' incorporates:
   *  Constant: '<S125>/Constant3'
   */
  rtb_Init_g = rtb_Switch2_p2 * 0.0;

  /* Sum: '<S126>/Diff' incorporates:
   *  UnitDelay: '<S126>/UD'
   *
   * Block description for '<S126>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S126>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Init_g - Robot_Control_DW.UD_DSTATE_ml;

  /* Saturate: '<S125>/Saturation' */
  if (rtb_Add_bn > 0.1) {
    rtb_Add_bn = 0.1;
  } else if (rtb_Add_bn < -0.1) {
    rtb_Add_bn = -0.1;
  }

  /* Sum: '<S125>/Add' incorporates:
   *  Gain: '<S125>/Gain'
   *  Gain: '<S125>/Gain1'
   *  Saturate: '<S125>/Saturation'
   *  Sum: '<S125>/Sum'
   */
  rtb_Add_bn += (Rebuilt_Shooter_Motor_Gain_FF *
                 Robot_Control_B.RB_Desired_Shooter_Speed) +
    (Rebuilt_Shooter_Motor_Gain_P * rtb_Error_d);

  /* Switch: '<S90>/Switch1' incorporates:
   *  Abs: '<S90>/Abs'
   *  Constant: '<S90>/Constant1'
   *  Constant: '<S90>/Constant2'
   *  Logic: '<S90>/Logical Operator'
   *  Logic: '<S90>/Logical Operator1'
   *  RelationalOperator: '<S90>/LessThan'
   *  UnitDelay: '<S90>/Unit Delay'
   */
  if ((fabs(rtb_Error_d) < Rebuilt_Shooter_Error_Integral_Enable) &&
      rtb_Is_Absolute_Steering) {
    rtb_Is_Absolute_Translation_g = true;
  } else {
    rtb_Is_Absolute_Translation_g = (rtb_Is_Absolute_Steering &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S90>/Switch1' */

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Constant4'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* Sum: '<S125>/Sum2' incorporates:
     *  Gain: '<S125>/Gain2'
     *  Sum: '<S125>/Sum'
     *  UnitDelay: '<S125>/Unit Delay'
     */
    rtb_Error_d = (Rebuilt_Shooter_Motor_Gain_I * rtb_Error_d) +
      Robot_Control_DW.UnitDelay_DSTATE_di;

    /* Sum: '<S125>/Subtract' incorporates:
     *  Constant: '<S125>/Constant'
     */
    rtb_Switch2_f = 1.0 - rtb_Add_bn;

    /* Switch: '<S128>/Switch2' incorporates:
     *  Constant: '<S125>/Constant'
     *  RelationalOperator: '<S128>/LowerRelop1'
     *  Sum: '<S125>/Subtract'
     */
    if (!(rtb_Error_d > (1.0 - rtb_Add_bn))) {
      /* Sum: '<S125>/Subtract1' incorporates:
       *  Constant: '<S125>/Constant1'
       */
      rtb_Switch2_f = -1.0 - rtb_Add_bn;

      /* Switch: '<S128>/Switch' incorporates:
       *  Constant: '<S125>/Constant1'
       *  RelationalOperator: '<S128>/UpperRelop'
       *  Sum: '<S125>/Subtract1'
       */
      if (!(rtb_Error_d < (-1.0 - rtb_Add_bn))) {
        rtb_Switch2_f = rtb_Error_d;
      }

      /* End of Switch: '<S128>/Switch' */
    }

    /* End of Switch: '<S128>/Switch2' */

    /* Saturate: '<S125>/Saturation1' */
    if (rtb_Switch2_f > 0.1) {
      rtb_Error_d = 0.1;
    } else if (rtb_Switch2_f < -0.1) {
      rtb_Error_d = -0.1;
    } else {
      rtb_Error_d = rtb_Switch2_f;
    }

    /* End of Saturate: '<S125>/Saturation1' */
  } else {
    rtb_Error_d = 0.0;
  }

  /* End of Switch: '<S125>/Switch' */

  /* Switch: '<S90>/Switch2' incorporates:
   *  Logic: '<S90>/Logical Operator1'
   */
  if (rtb_Is_Absolute_Steering) {
    /* Sum: '<S125>/Add1' */
    rtb_Add_bn += rtb_Error_d;

    /* Saturate: '<S125>/Saturation2' */
    if (rtb_Add_bn > 1.0) {
      /* Switch: '<S90>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_bn < -1.0) {
      /* Switch: '<S90>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S90>/Switch2' */
      Robot_Control_B.RB_Shooter_Motor_PID_DC = rtb_Add_bn;
    }

    /* End of Saturate: '<S125>/Saturation2' */
  } else {
    /* Switch: '<S90>/Switch2' incorporates:
     *  Constant: '<S90>/Constant3'
     */
    Robot_Control_B.RB_Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S90>/Switch2' */

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S9>/Constant'
   *  Switch: '<S9>/Switch3'
   *  Switch: '<S9>/Switch4'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Shooter_Motor_DC_Left' incorporates:
     *  Constant: '<S9>/Constant3'
     */
    Robot_Control_Y.Shooter_Motor_DC_Left = TEST_Shooter_Motor_DC_Left_OV;

    /* Outport: '<Root>/Shooter_Motor_DC_Center' incorporates:
     *  Constant: '<S9>/Constant4'
     */
    Robot_Control_Y.Shooter_Motor_DC_Center = TEST_Shooter_Motor_DC_Center_OV;

    /* Outport: '<Root>/Shooter_Motor_DC_Right' incorporates:
     *  Constant: '<S9>/Constant5'
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

  /* End of Switch: '<S9>/Switch2' */

  /* Chart: '<S10>/Chart' */
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

  /* End of Chart: '<S10>/Chart' */

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

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Joystick_Left_B11;

  /* Update for UnitDelay: '<S25>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Joystick_Left_B12;

  /* Update for UnitDelay: '<S26>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *
   * Block description for '<S26>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Joystick_Left_B13;

  /* Update for S-Function (sfix_udelay): '<S7>/Tapped Delay' incorporates:
   *  Inport: '<Root>/Odom_Delta_X'
   */
  Robot_Control_DW.TappedDelay_X[0] = Robot_Control_DW.TappedDelay_X[1];
  Robot_Control_DW.TappedDelay_X[1] = Robot_Control_U.Odom_Delta_X;

  /* Update for S-Function (sfix_udelay): '<S7>/Tapped Delay1' incorporates:
   *  Inport: '<Root>/Odom_Delta_Y'
   */
  Robot_Control_DW.TappedDelay1_X[0] = Robot_Control_DW.TappedDelay1_X[1];
  Robot_Control_DW.TappedDelay1_X[1] = Robot_Control_U.Odom_Delta_Y;

  /* Update for Delay: '<S27>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S47>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S27>/A'
   *  Delay: '<S27>/MemoryX'
   */
  rtb_Add_bn = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Switch2_f = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S27>/MemoryX' incorporates:
   *  Constant: '<S27>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S47>/A[k]*xhat[k|k-1]'
   *  Product: '<S47>/B[k]*u[k]'
   *  Sum: '<S47>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Add_bn) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Switch2_f) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S295>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S295>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay generated from: '<S11>/Unit Delay' */
  Robot_Control_DW.UnitDelay_1_DSTATE =
    Robot_Control_B.RB_Desired_Shoot_Gyro_Ang;

  /* Update for UnitDelay generated from: '<S11>/Unit Delay' */
  Robot_Control_DW.UnitDelay_4_DSTATE =
    Robot_Control_B.RB_Allow_Shoot_Gyro_Error;

  /* Update for UnitDelay generated from: '<S11>/Unit Delay' */
  Robot_Control_DW.UnitDelay_2_DSTATE = Robot_Control_B.RB_Desired_Shooter_Speed;

  /* Update for UnitDelay generated from: '<S11>/Unit Delay' */
  Robot_Control_DW.UnitDelay_3_DSTATE =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S86>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c =
    Robot_Control_B.RB_Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S317>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S316>/UD'
   *
   * Block description for '<S316>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Add_h5;

  /* Update for UnitDelay: '<S314>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Switch4;

  /* Update for UnitDelay: '<S297>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Init_o;

  /* Update for UnitDelay: '<S312>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S312>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S312>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Init_o;

  /* Update for UnitDelay: '<S296>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S305>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S305>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S305>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S271>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S270>/UD'
   *
   * Block description for '<S270>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2;

  /* Update for UnitDelay: '<S264>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S208>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Hypot_pi;

  /* Update for UnitDelay: '<S207>/UD'
   *
   * Block description for '<S207>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Init;

  /* Update for UnitDelay: '<S201>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S219>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_fg;

  /* Update for UnitDelay: '<S218>/UD'
   *
   * Block description for '<S218>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_dp;

  /* Update for UnitDelay: '<S204>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S229>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_fn;

  /* Update for UnitDelay: '<S228>/UD'
   *
   * Block description for '<S228>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S222>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S240>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Switch2_m;

  /* Update for UnitDelay: '<S239>/UD'
   *
   * Block description for '<S239>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_hi;

  /* Update for UnitDelay: '<S225>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S250>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_k;

  /* Update for UnitDelay: '<S249>/UD'
   *
   * Block description for '<S249>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S243>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S261>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S260>/UD'
   *
   * Block description for '<S260>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Add2_idx_0;

  /* Update for UnitDelay: '<S246>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S282>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S281>/UD'
   *
   * Block description for '<S281>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add2_idx_1;

  /* Update for UnitDelay: '<S267>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S132>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_jp;

  /* Update for UnitDelay: '<S131>/UD'
   *
   * Block description for '<S131>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S130>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S92>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_AND1_c;

  /* Update for UnitDelay: '<S84>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S84>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S127>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_d = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S126>/UD'
   *
   * Block description for '<S126>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_ml = rtb_Init_g;

  /* Update for UnitDelay: '<S125>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Error_d;

  /* Update for UnitDelay: '<S90>/Unit Delay' */
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

  /* Start for If: '<S12>/If' */
  Robot_Control_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for Delay: '<S27>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S295>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S312>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S305>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S366>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S12>/Spline Path Following Enabled' */
  /* Start for If: '<S140>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S136>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S140>/Robot_Index_Is_Valid' */
  /* Start for If: '<S143>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S143>/Circle_Check_Valid' */
  /* Start for If: '<S145>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S143>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S140>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S12>/Spline Path Following Enabled' */
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
