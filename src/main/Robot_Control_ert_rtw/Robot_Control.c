/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.445
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 16 22:23:43 2026
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

/* Named constants for Chart: '<S9>/Chart' */
#define Robot_Contro_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Robot_Control_IN_Disabled      ((uint8_T)1U)
#define Robot_Control_IN_Not_Disabled  ((uint8_T)2U)

/* Named constants for Chart: '<S10>/Shooter_Transfer_Feeder Chart' */
#define Robot_Control_IN_Feeder        ((uint8_T)1U)
#define Robot_Control_IN_Not_Shooting  ((uint8_T)1U)
#define Robot_Control_IN_Shooting      ((uint8_T)2U)
#define Robot_Control_IN_Spinning_Up   ((uint8_T)2U)
#define Robot_Control_IN_Transfer      ((uint8_T)3U)

/* Exported block parameters */
real_T BlueAllianceZoneX = 4.6256;     /* Variable: BlueAllianceZoneX
                                        * Referenced by:
                                        *   '<S115>/BlueAllianceZoneX'
                                        *   '<S117>/BlueAllianceZoneX'
                                        */
real_T Blue_Hub_X = 4.6256;            /* Variable: Blue_Hub_X
                                        * Referenced by: '<S100>/Constant'
                                        */
real_T Blue_Hub_Y = 4.0345;            /* Variable: Blue_Hub_Y
                                        * Referenced by: '<S100>/Constant1'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S358>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S354>/Constant'
                                        *   '<S354>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S358>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S354>/Constant1'
                                        */
real_T Dist_Arr_0 = 0.0;               /* Variable: Dist_Arr_0
                                        * Referenced by:
                                        *   '<S97>/Constant5'
                                        *   '<S98>/Constant5'
                                        *   '<S99>/Constant5'
                                        *   '<S102>/Constant5'
                                        */
real_T Dist_Arr_1 = 2.5;               /* Variable: Dist_Arr_1
                                        * Referenced by:
                                        *   '<S97>/Constant6'
                                        *   '<S98>/Constant6'
                                        *   '<S99>/Constant6'
                                        *   '<S102>/Constant6'
                                        */
real_T Dist_Arr_2 = 5.0;               /* Variable: Dist_Arr_2
                                        * Referenced by:
                                        *   '<S97>/Constant7'
                                        *   '<S98>/Constant7'
                                        *   '<S99>/Constant7'
                                        *   '<S102>/Constant7'
                                        */
real_T Dist_Arr_3 = 7.5;               /* Variable: Dist_Arr_3
                                        * Referenced by:
                                        *   '<S97>/Constant8'
                                        *   '<S98>/Constant8'
                                        *   '<S99>/Constant8'
                                        *   '<S102>/Constant8'
                                        */
real_T Dist_Arr_4 = 10.0;              /* Variable: Dist_Arr_4
                                        * Referenced by:
                                        *   '<S97>/Constant9'
                                        *   '<S98>/Constant9'
                                        *   '<S99>/Constant9'
                                        *   '<S102>/Constant9'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S196>/Constant3'
                                        *   '<S217>/Constant3'
                                        *   '<S238>/Constant3'
                                        *   '<S259>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S196>/Constant2'
                                   *   '<S217>/Constant2'
                                   *   '<S238>/Constant2'
                                   *   '<S259>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S196>/Saturation'
                                        *   '<S217>/Saturation'
                                        *   '<S238>/Saturation'
                                        *   '<S259>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S196>/Saturation'
                                        *   '<S217>/Saturation'
                                        *   '<S238>/Saturation'
                                        *   '<S259>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S196>/Gain'
                                            *   '<S217>/Gain'
                                            *   '<S238>/Gain'
                                            *   '<S259>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S196>/Gain2'
                                        *   '<S217>/Gain2'
                                        *   '<S238>/Gain2'
                                        *   '<S259>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S196>/Saturation1'
                                         *   '<S217>/Saturation1'
                                         *   '<S238>/Saturation1'
                                         *   '<S259>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S196>/Saturation1'
                                        *   '<S217>/Saturation1'
                                        *   '<S238>/Saturation1'
                                        *   '<S259>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S196>/Gain1'
                                        *   '<S217>/Gain1'
                                        *   '<S238>/Gain1'
                                        *   '<S259>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S201>/Constant'
                            *   '<S222>/Constant'
                            *   '<S243>/Constant'
                            *   '<S264>/Constant'
                            */
real_T Feeder_Motor_Gain_FF = 0.00014286;/* Variable: Feeder_Motor_Gain_FF
                                          * Referenced by: '<S10>/Constant'
                                          */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S344>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S344>/Constant5'
                                          */
real_T Gyro_Err_Arr_0 = 0.17453;       /* Variable: Gyro_Err_Arr_0
                                        * Referenced by: '<S97>/Constant'
                                        */
real_T Gyro_Err_Arr_1 = 0.087266;      /* Variable: Gyro_Err_Arr_1
                                        * Referenced by: '<S97>/Constant1'
                                        */
real_T Gyro_Err_Arr_2 = 0.05236;       /* Variable: Gyro_Err_Arr_2
                                        * Referenced by: '<S97>/Constant2'
                                        */
real_T Gyro_Err_Arr_3 = 0.017453;      /* Variable: Gyro_Err_Arr_3
                                        * Referenced by: '<S97>/Constant3'
                                        */
real_T Gyro_Err_Arr_4 = 0.0087266;     /* Variable: Gyro_Err_Arr_4
                                        * Referenced by: '<S97>/Constant4'
                                        */
real_T Hood_Pos_Max_Error_Shoot = 0.03;/* Variable: Hood_Pos_Max_Error_Shoot
                                        * Referenced by: '<S87>/Constant1'
                                        */
real_T Hood_Position_0 = 0.8;          /* Variable: Hood_Position_0
                                        * Referenced by: '<S98>/Constant'
                                        */
real_T Hood_Position_1 = 0.6;          /* Variable: Hood_Position_1
                                        * Referenced by: '<S98>/Constant1'
                                        */
real_T Hood_Position_2 = 0.4;          /* Variable: Hood_Position_2
                                        * Referenced by: '<S98>/Constant2'
                                        */
real_T Hood_Position_3 = 0.3;          /* Variable: Hood_Position_3
                                        * Referenced by: '<S98>/Constant3'
                                        */
real_T Hood_Position_4 = 0.2;          /* Variable: Hood_Position_4
                                        * Referenced by: '<S98>/Constant4'
                                        */
real_T Hood_Servo_Pos_Max = 1.0;       /* Variable: Hood_Servo_Pos_Max
                                        * Referenced by: '<S8>/Saturation'
                                        */
real_T Hood_Servo_Pos_Min = 0.2;       /* Variable: Hood_Servo_Pos_Min
                                        * Referenced by: '<S8>/Saturation'
                                        */
real_T Hood_Servo_Rate_Limit_Dec = -0.0128;/* Variable: Hood_Servo_Rate_Limit_Dec
                                            * Referenced by: '<S80>/Constant1'
                                            */
real_T Hood_Servo_Rate_Limit_Inc = 0.0128;/* Variable: Hood_Servo_Rate_Limit_Inc
                                           * Referenced by: '<S80>/Constant3'
                                           */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S6>/Constant2'
                                        */
real_T RedAllianceZoneX = 11.9154;     /* Variable: RedAllianceZoneX
                                        * Referenced by:
                                        *   '<S116>/RedAllianceZoneX'
                                        *   '<S118>/RedAllianceZoneX'
                                        */
real_T Red_Hub_X = 11.9154;            /* Variable: Red_Hub_X
                                        * Referenced by: '<S100>/Constant2'
                                        */
real_T Red_Hub_Y = 4.0345;             /* Variable: Red_Hub_Y
                                        * Referenced by: '<S100>/Constant3'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S343>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S341>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S343>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S344>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S344>/Constant8'
                                      */
real_T Robot_Velocity_Maximum_Shooter = 1.0;
                                     /* Variable: Robot_Velocity_Maximum_Shooter
                                      * Referenced by: '<S87>/Constant'
                                      */
real_T Shooter_Error_Integral_Enable = 300.0;
                                      /* Variable: Shooter_Error_Integral_Enable
                                       * Referenced by: '<S88>/Constant1'
                                       */
real_T Shooter_Motor_Gain_D = 0.0;     /* Variable: Shooter_Motor_Gain_D
                                        * Referenced by: '<S120>/Constant3'
                                        */
real_T Shooter_Motor_Gain_FF = 0.00014286;/* Variable: Shooter_Motor_Gain_FF
                                           * Referenced by: '<S120>/Gain'
                                           */
real_T Shooter_Motor_Gain_I = 0.0;     /* Variable: Shooter_Motor_Gain_I
                                        * Referenced by: '<S120>/Gain2'
                                        */
real_T Shooter_Motor_Gain_P = 0.0;     /* Variable: Shooter_Motor_Gain_P
                                        * Referenced by: '<S120>/Gain1'
                                        */
real_T Shooter_Motor_Max_Error_Shoot = 100.0;
                                      /* Variable: Shooter_Motor_Max_Error_Shoot
                                       * Referenced by: '<S87>/Constant2'
                                       */
real_T Shooter_Spd_0 = 3000.0;         /* Variable: Shooter_Spd_0
                                        * Referenced by: '<S99>/Constant'
                                        */
real_T Shooter_Spd_1 = 3200.0;         /* Variable: Shooter_Spd_1
                                        * Referenced by: '<S99>/Constant1'
                                        */
real_T Shooter_Spd_2 = 3500.0;         /* Variable: Shooter_Spd_2
                                        * Referenced by: '<S99>/Constant2'
                                        */
real_T Shooter_Spd_3 = 3500.0;         /* Variable: Shooter_Spd_3
                                        * Referenced by: '<S99>/Constant3'
                                        */
real_T Shooter_Spd_4 = 3500.0;         /* Variable: Shooter_Spd_4
                                        * Referenced by: '<S99>/Constant4'
                                        */
real_T Shot_Target_Error_Thresh = 0.1; /* Variable: Shot_Target_Error_Thresh
                                        * Referenced by: '<S106>/Constant'
                                        */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S185>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S185>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S132>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S145>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S185>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S292>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S292>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S292>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S292>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S292>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S292>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S309>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S309>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S309>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S309>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S308>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S309>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S309>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S309>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S309>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S309>/Constant1'
                                   *   '<S309>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S309>/Constant'
                                   *   '<S309>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S199>/Constant3'
                                        *   '<S220>/Constant3'
                                        *   '<S241>/Constant3'
                                        *   '<S262>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S199>/Constant2'
                                *   '<S220>/Constant2'
                                *   '<S241>/Constant2'
                                *   '<S262>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S199>/Saturation'
                                           *   '<S220>/Saturation'
                                           *   '<S241>/Saturation'
                                           *   '<S262>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S199>/Saturation'
                                          *   '<S220>/Saturation'
                                          *   '<S241>/Saturation'
                                          *   '<S262>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S199>/Gain2'
                                         *   '<S220>/Gain2'
                                         *   '<S241>/Gain2'
                                         *   '<S262>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S199>/Saturation1'
                                             *   '<S220>/Saturation1'
                                             *   '<S241>/Saturation1'
                                             *   '<S262>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S199>/Saturation1'
                                            *   '<S220>/Saturation1'
                                            *   '<S241>/Saturation1'
                                            *   '<S262>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S199>/Gain1'
                                        *   '<S220>/Gain1'
                                        *   '<S241>/Gain1'
                                        *   '<S262>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S291>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S291>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S291>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S291>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S291>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S291>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S343>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S343>/Constant1'
                                        */
real_T TEST_Desired_Hood_Enable_OV = 0.0;/* Variable: TEST_Desired_Hood_Enable_OV
                                          * Referenced by: '<S8>/Constant7'
                                          */
real_T TEST_Desired_Hood_Pos_OV = 0.5; /* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S8>/Constant6'
                                        */
real_T TEST_Feeder_Motor_DC_OV = 0.0;  /* Variable: TEST_Feeder_Motor_DC_OV
                                        * Referenced by: '<S8>/Constant2'
                                        */
real_T TEST_Output_Override_Flag = 1.0;/* Variable: TEST_Output_Override_Flag
                                        * Referenced by: '<S8>/Constant'
                                        */
real_T TEST_Shooter_Motor_DC_Center_OV = 0.0;
                                    /* Variable: TEST_Shooter_Motor_DC_Center_OV
                                     * Referenced by: '<S8>/Constant4'
                                     */
real_T TEST_Shooter_Motor_DC_Left_OV = 0.0;
                                      /* Variable: TEST_Shooter_Motor_DC_Left_OV
                                       * Referenced by: '<S8>/Constant3'
                                       */
real_T TEST_Shooter_Motor_DC_Right_OV = 0.0;
                                     /* Variable: TEST_Shooter_Motor_DC_Right_OV
                                      * Referenced by: '<S8>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Override_Flag = 0.0;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S342>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S342>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S342>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S8>/Constant1'
                                        */
real_T TOF_Arr_0 = 2.0;                /* Variable: TOF_Arr_0
                                        * Referenced by: '<S102>/Constant'
                                        */
real_T TOF_Arr_1 = 3.0;                /* Variable: TOF_Arr_1
                                        * Referenced by: '<S102>/Constant1'
                                        */
real_T TOF_Arr_2 = 3.5;                /* Variable: TOF_Arr_2
                                        * Referenced by: '<S102>/Constant2'
                                        */
real_T TOF_Arr_3 = 3.8;                /* Variable: TOF_Arr_3
                                        * Referenced by: '<S102>/Constant3'
                                        */
real_T TOF_Arr_4 = 4.0;                /* Variable: TOF_Arr_4
                                        * Referenced by: '<S102>/Constant4'
                                        */
real_T Target_Feeder_Speed = 2000.0;   /* Variable: Target_Feeder_Speed
                                        * Referenced by: '<S10>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Target_Transfer_Speed = 2000.0; /* Variable: Target_Transfer_Speed
                                        * Referenced by: '<S10>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Transfer_Error_Integral_Enable = 300.0;
                                     /* Variable: Transfer_Error_Integral_Enable
                                      * Referenced by: '<S91>/Constant1'
                                      */
real_T Transfer_Minimum_Factor = 0.8;  /* Variable: Transfer_Minimum_Factor
                                        * Referenced by: '<S10>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Transfer_Motor_Gain_D = 0.0;    /* Variable: Transfer_Motor_Gain_D
                                        * Referenced by: '<S125>/Constant3'
                                        */
real_T Transfer_Motor_Gain_FF = 0.00014286;/* Variable: Transfer_Motor_Gain_FF
                                            * Referenced by: '<S125>/Gain'
                                            */
real_T Transfer_Motor_Gain_I = 0.0;    /* Variable: Transfer_Motor_Gain_I
                                        * Referenced by: '<S125>/Gain2'
                                        */
real_T Transfer_Motor_Gain_P = 0.0;    /* Variable: Transfer_Motor_Gain_P
                                        * Referenced by: '<S125>/Gain1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S279>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S279>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S279>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S279>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S279>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S279>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S344>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S343>/Dead Zone'
                                        *   '<S344>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S343>/Dead Zone'
                                        *   '<S344>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S15>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S341>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S341>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S341>/Constant4'
                                        */
real_T Vision_Object_X_Offset = 0.0;   /* Variable: Vision_Object_X_Offset
                                        * Referenced by: '<S15>/Constant4'
                                        */
real_T Vision_Object_Y_Offset = 0.0;   /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S15>/Constant8'
                                        */
real_T Vision_Tag_Angle_Offset = 0.0;  /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S15>/Constant5'
                                        */
real_T Vision_Tag_Target_Angle = 0.0;  /* Variable: Vision_Tag_Target_Angle
                                        * Referenced by: '<S341>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S341>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S341>/Constant5'
                                        */
real_T Vision_Tag_X_Offset = 0.0;      /* Variable: Vision_Tag_X_Offset
                                        * Referenced by: '<S15>/Constant3'
                                        */
real_T Vision_Tag_Y_Offset = 0.0;      /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S15>/Constant7'
                                        */
uint8_T TEST_Pipeline = 0U;            /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S14>/Constant22'
                                        *   '<S341>/Constant11'
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
 *    '<S86>/If Action Subsystem'
 *    '<S86>/If Action Subsystem5'
 */
void Robot_Control_IfActionSubsystem(boolean_T *rty_IsBlueActive, boolean_T
  *rty_IsRedActive)
{
  /* SignalConversion generated from: '<S107>/IsBlueActive' incorporates:
   *  Constant: '<S107>/Constant'
   */
  *rty_IsBlueActive = true;

  /* SignalConversion generated from: '<S107>/IsRedActive' incorporates:
   *  Constant: '<S107>/Constant'
   */
  *rty_IsRedActive = true;
}

/*
 * Output and update for action system:
 *    '<S86>/If Action Subsystem1'
 *    '<S86>/If Action Subsystem3'
 */
void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive)
{
  /* Logic: '<S108>/NOT' incorporates:
   *  SignalConversion generated from: '<S108>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S108>/IsRedActive' */
  *rty_IsRedActive = rtu_IsBlueInactiveFirst;
}

/*
 * Output and update for action system:
 *    '<S86>/If Action Subsystem2'
 *    '<S86>/If Action Subsystem4'
 */
void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive)
{
  /* Logic: '<S109>/NOT1' incorporates:
   *  SignalConversion generated from: '<S109>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S109>/IsBlueActive' */
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
  real_T rtb_TOF_g[5];
  real_T rtb_TmpSignalConversionAtLoo_o3[5];
  real_T rtb_TmpSignalConversionAtLook_f[5];
  real_T rtb_TmpSignalConversionAtLook_k[5];
  real_T rtb_shot_distance[5];
  real_T rtb_shot_distance_fj[5];
  real_T rtb_shot_distance_m[5];
  real_T rtb_shot_distance_o[5];
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
  real_T rtb_Integral_bj;
  real_T rtb_Integral_d;
  real_T rtb_Integral_ga;
  real_T rtb_Merge1;
  real_T rtb_Modulation_Drv;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_hi;
  real_T rtb_Product_lo;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_kg;
  real_T rtb_Subtract1_la;
  real_T rtb_Subtract_c3;
  real_T rtb_Sum2_e;
  real_T rtb_Switch1;
  real_T rtb_Switch2;
  real_T rtb_Switch2_dp;
  real_T rtb_Switch2_f;
  real_T rtb_Switch2_m;
  real_T rtb_Switch2_p2;
  real_T rtb_uDLookupTable;
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

  /* RelationalOperator: '<S23>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Joystick_Left_B11 >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets =
    (Robot_Control_U.Joystick_Left_B12 > Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S25>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *  UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Joystick_Left_B13 >
    Robot_Control_DW.DelayInput1_DSTATE_n);

  /* SignalConversion: '<S4>/Signal Copy1' incorporates:
   *  Inport: '<Root>/Joystick_Left_X'
   */
  Robot_Control_B.Drive_Joystick_X = Robot_Control_U.Joystick_Left_X;

  /* SignalConversion: '<S4>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Joystick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y = Robot_Control_U.Joystick_Left_Y;

  /* SignalConversion: '<S4>/Signal Copy3' incorporates:
   *  Inport: '<Root>/Joystick_Left_Z'
   */
  Robot_Control_B.Drive_Joystick_Z = Robot_Control_U.Joystick_Left_Z;

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   *  Inport: '<Root>/Joystick_Left_POV'
   */
  Robot_Control_B.Drive_Joystick_Z_Mode = (Robot_Control_U.Joystick_Left_POV !=
    -1.0);

  /* SignalConversion: '<S4>/Signal Copy5' incorporates:
   *  Inport: '<Root>/Joystick_Right_Y'
   */
  Robot_Control_B.Steer_Joystick_Y = Robot_Control_U.Joystick_Right_Y;

  /* SignalConversion: '<S4>/Signal Copy6' incorporates:
   *  Inport: '<Root>/Joystick_Right_Z'
   */
  Robot_Control_B.Steer_Joystick_Z = Robot_Control_U.Joystick_Right_Z;

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   *  Inport: '<Root>/Joystick_Left_B1'
   */
  Robot_Control_B.Is_Boosting = (Robot_Control_U.Joystick_Left_B1 != 0.0);

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Toward_Driver = (Robot_Control_U.Joystick_Right_POV ==
    180.0);

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Right_Driver = (Robot_Control_U.Joystick_Right_POV ==
    90.0);

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Left_Driver = (Robot_Control_U.Joystick_Right_POV ==
    270.0);

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Away_Driver = (Robot_Control_U.Joystick_Right_POV == 0.0);

  /* Sum: '<S15>/Add' incorporates:
   *  Constant: '<S15>/Constant3'
   *  Gain: '<S15>/Convert meters to inches1'
   *  Inport: '<Root>/Vision_c1_AprilTag_X_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_X_m) + Vision_Tag_X_Offset;

  /* Sum: '<S15>/Add1' incorporates:
   *  Constant: '<S15>/Constant7'
   *  Gain: '<S15>/Convert meters to inches'
   *  Inport: '<Root>/Vision_c1_AprilTag_Y_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_Y_m) + Vision_Tag_Y_Offset;

  /* Sum: '<S15>/Add2' incorporates:
   *  Constant: '<S15>/Constant5'
   *  Inport: '<Root>/Vision_c1_AprilTag_Yaw_deg'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_AprilTag_Yaw_deg + Vision_Tag_Angle_Offset;

  /* If: '<S370>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S370>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S373>/Action Port'
     */
    /* Product: '<S373>/Product' incorporates:
     *  Constant: '<S373>/Constant1'
     *  Constant: '<S373>/Constant2'
     *  Math: '<S373>/Math Function'
     */
    rtb_Subtract_c3 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S370>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S370>/Subsystem' incorporates:
     *  ActionPort: '<S374>/Action Port'
     */
    /* SignalConversion generated from: '<S374>/Out1' incorporates:
     *  Constant: '<S374>/Constant'
     */
    rtb_Subtract_c3 = 0.0;

    /* End of Outputs for SubSystem: '<S370>/Subsystem' */
  }

  /* End of If: '<S370>/If' */

  /* Gain: '<S371>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S15>/Add3' incorporates:
   *  Constant: '<S15>/Constant4'
   *  Fcn: '<S372>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Subtract_c3 * cos(rtb_Sin4))
    + Vision_Object_X_Offset;

  /* Sum: '<S15>/Add4' incorporates:
   *  Constant: '<S15>/Constant8'
   *  Fcn: '<S372>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Subtract_c3 * sin(rtb_Sin4))
    + Vision_Object_Y_Offset;

  /* Sum: '<S15>/Add5' incorporates:
   *  Constant: '<S15>/Constant6'
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
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<S7>/Merge1' incorporates:
     *  Constant: '<S3>/Constant1'
     *  SignalConversion generated from: '<S3>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S3>/Constant2'
     *  SignalConversion generated from: '<S3>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S7>/Merge3' incorporates:
     *  Constant: '<S3>/Constant3'
     *  SignalConversion generated from: '<S3>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S7>/Merge4' incorporates:
     *  Constant: '<S3>/Constant4'
     *  SignalConversion generated from: '<S3>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* SignalConversion generated from: '<S3>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S3>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* SignalConversion generated from: '<S3>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S3>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S3>/Constant7'
     *  SignalConversion generated from: '<S3>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S3>/Constant9'
     *  SignalConversion generated from: '<S3>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S7>/Merge10' incorporates:
     *  Constant: '<S3>/Constant10'
     *  SignalConversion generated from: '<S3>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* SignalConversion generated from: '<S3>/Enable_Wheels' incorporates:
     *  Constant: '<S3>/Constant18'
     */
    rtb_Enable_Wheels = false;

    /* SignalConversion generated from: '<S3>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S3>/Constant13'
     */
    rtb_Reset_Wheel_Offsets = false;

    /* SignalConversion generated from: '<S3>/Disable_Wheels' incorporates:
     *  Constant: '<S3>/Constant14'
     */
    rtb_Disable_Wheels = false;

    /* SignalConversion generated from: '<S3>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S3>/Constant12'
     */
    rtb_Swerve_Motors_Disabled = true;

    /* Merge: '<S7>/Merge23' incorporates:
     *  Constant: '<S3>/Constant23'
     *  SignalConversion generated from: '<S3>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* SignalConversion generated from: '<S3>/Desired_Pipeline' incorporates:
     *  Constant: '<S3>/Constant25'
     */
    rtb_Desired_Pipeline = 0U;

    /* SignalConversion generated from: '<S3>/Button_Spinup_Enable' incorporates:
     *  Constant: '<S3>/Constant11'
     */
    rtb_Button_Spinup_Enable = 0U;

    /* SignalConversion generated from: '<S3>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S3>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S16>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S7>/Merge1' incorporates:
     *  Constant: '<S16>/Constant1'
     *  SignalConversion generated from: '<S2>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S16>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S16>/Constant2'
     *  SignalConversion generated from: '<S2>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S16>/Constant7'
     *  SignalConversion generated from: '<S2>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge3' incorporates:
     *  Constant: '<S16>/Constant3'
     *  SignalConversion generated from: '<S2>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S16>/Constant9'
     *  SignalConversion generated from: '<S2>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S7>/Merge4' incorporates:
     *  Constant: '<S16>/Constant4'
     *  SignalConversion generated from: '<S2>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* Merge: '<S7>/Merge23' incorporates:
     *  Constant: '<S16>/Constant10'
     *  SignalConversion generated from: '<S2>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* Merge: '<S7>/Merge10' incorporates:
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
       *  ActionPort: '<S13>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S343>/Unit Delay1'
       *  UnitDelay: '<S343>/Unit Delay2'
       *  UnitDelay: '<S343>/Unit Delay3'
       *  UnitDelay: '<S343>/Unit Delay4'
       *  UnitDelay: '<S346>/Delay Input1'
       *  UnitDelay: '<S347>/Delay Input1'
       *  UnitDelay: '<S348>/Delay Input1'
       *  UnitDelay: '<S349>/Delay Input1'
       *  UnitDelay: '<S351>/Delay Input1'
       *  UnitDelay: '<S357>/Unit Delay'
       *  UnitDelay: '<S357>/Unit Delay1'
       *  UnitDelay: '<S361>/FixPt Unit Delay1'
       *  UnitDelay: '<S361>/FixPt Unit Delay2'
       *
       * Block description for '<S346>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S347>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S348>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S349>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S351>/Delay Input1':
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
     *  ActionPort: '<S13>/Action Port'
     */
    /* Switch: '<S341>/Switch4' incorporates:
     *  Constant: '<S366>/Constant'
     *  Constant: '<S369>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S366>/Compare'
     *  RelationalOperator: '<S369>/Compare'
     *  Switch: '<S341>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S341>/Switch4' incorporates:
       *  Constant: '<S341>/Constant8'
       *  Sum: '<S341>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S341>/Switch5' incorporates:
       *  Constant: '<S341>/Constant7'
       *  Gain: '<S341>/Gain'
       *  Sum: '<S341>/Subtract5'
       *  Switch: '<S341>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S341>/Switch4' incorporates:
       *  Constant: '<S341>/Constant6'
       *  Switch: '<S341>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S341>/Switch4' */

    /* Logic: '<S341>/Logical Operator1' incorporates:
     *  Constant: '<S13>/Constant12'
     *  Logic: '<S341>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S343>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_bn = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_bn = 0.0;
    } else {
      rtb_Add_bn = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S343>/Add' incorporates:
     *  Constant: '<S343>/Constant'
     *  Constant: '<S343>/Constant1'
     *  DeadZone: '<S343>/Dead Zone'
     *  Lookup_n-D: '<S343>/Modulation_Str_Y_Rel'
     *  Product: '<S343>/Product'
     *  Product: '<S343>/Product1'
     *  SignalConversion: '<S4>/Signal Copy5'
     */
    rtb_Add_h5 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                  Steering_Relative_Gain) + (rtb_Add_bn * Steering_Twist_Gain);

    /* RelationalOperator: '<S345>/Compare' incorporates:
     *  Constant: '<S345>/Constant'
     */
    rtb_Compare_a = (rtb_Add_h5 == 0.0);

    /* Logic: '<S343>/AND2' incorporates:
     *  RelationalOperator: '<S346>/FixPt Relational Operator'
     *  RelationalOperator: '<S347>/FixPt Relational Operator'
     *  RelationalOperator: '<S348>/FixPt Relational Operator'
     *  RelationalOperator: '<S349>/FixPt Relational Operator'
     *  UnitDelay: '<S346>/Delay Input1'
     *  UnitDelay: '<S347>/Delay Input1'
     *  UnitDelay: '<S348>/Delay Input1'
     *  UnitDelay: '<S349>/Delay Input1'
     *
     * Block description for '<S346>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S347>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S348>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S349>/Delay Input1':
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

    /* Logic: '<S343>/AND1' incorporates:
     *  Logic: '<S343>/AND3'
     *  UnitDelay: '<S343>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_a && (rtb_Enable_Wheels ||
      (Robot_Control_DW.UnitDelay2_DSTATE)));

    /* Logic: '<S343>/AND4' incorporates:
     *  Logic: '<S343>/AND8'
     *  UnitDelay: '<S343>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_a && (!rtb_Enable_Wheels)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S343>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S343>/Switch8' incorporates:
     *  Constant: '<S352>/Constant'
     *  Logic: '<S343>/AND9'
     *  RelationalOperator: '<S351>/FixPt Relational Operator'
     *  RelationalOperator: '<S352>/Compare'
     *  UnitDelay: '<S351>/Delay Input1'
     *  UnitDelay: '<S9>/Unit Delay'
     *
     * Block description for '<S351>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)rtb_Compare_a)
          > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j))) ||
        (Robot_Control_B.Active_GameState != 2)) {
      /* Switch: '<S343>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S343>/Switch8' incorporates:
       *  UnitDelay: '<S343>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S343>/Switch8' */

    /* Switch: '<S343>/Switch4' incorporates:
     *  Constant: '<S343>/Constant5'
     *  Switch: '<S343>/Switch1'
     *  Switch: '<S343>/Switch5'
     *  Switch: '<S343>/Switch6'
     *  Switch: '<S343>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Subtract_c3 = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S343>/Switch5' incorporates:
       *  Constant: '<S343>/Constant6'
       */
      rtb_Subtract_c3 = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S343>/Switch6' incorporates:
       *  Constant: '<S343>/Constant7'
       *  Switch: '<S343>/Switch5'
       */
      rtb_Subtract_c3 = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S343>/Switch7' incorporates:
       *  Constant: '<S343>/Constant8'
       *  Switch: '<S343>/Switch5'
       *  Switch: '<S343>/Switch6'
       */
      rtb_Subtract_c3 = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S343>/Switch1' incorporates:
       *  Constant: '<S13>/Constant10'
       *  Switch: '<S343>/Switch5'
       *  Switch: '<S343>/Switch6'
       *  Switch: '<S343>/Switch7'
       */
      rtb_Subtract_c3 = 0.0;
    } else {
      /* Switch: '<S343>/Switch6' incorporates:
       *  Switch: '<S343>/Switch5'
       *  Switch: '<S343>/Switch7'
       *  UnitDelay: '<S343>/Unit Delay1'
       */
      rtb_Subtract_c3 = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S343>/Switch4' */

    /* Switch: '<S343>/Switch2' incorporates:
     *  Switch: '<S343>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S343>/Switch2' incorporates:
       *  Constant: '<S343>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S343>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Subtract_c3;
    } else {
      /* Switch: '<S343>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S343>/Switch3' incorporates:
       *  Constant: '<S343>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S343>/Switch2' */

    /* Merge: '<S7>/Merge1' incorporates:
     *  Sum: '<S343>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S342>/Switch1' incorporates:
     *  Constant: '<S342>/Constant5'
     *  Constant: '<S342>/Constant8'
     *  DataTypeConversion: '<S342>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_a;
    }

    /* End of Switch: '<S342>/Switch1' */

    /* Lookup_n-D: '<S344>/Modulation_Drv' incorporates:
     *  Math: '<S344>/Magnitude'
     */
    rtb_Modulation_Drv = look1_binlcpw(rt_hypotd_snf
      (Robot_Control_B.Drive_Joystick_X, Robot_Control_B.Drive_Joystick_Y),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S355>/Compare' incorporates:
     *  Constant: '<S355>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Modulation_Drv == 0.0);

    /* DeadZone: '<S344>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S344>/Dead Zone' */

    /* Logic: '<S344>/Logical Operator' incorporates:
     *  Constant: '<S356>/Constant'
     *  RelationalOperator: '<S356>/Compare'
     */
    rtb_Enable_Wheels = ((rtb_Sin4 != 0.0) && rtb_Swerve_Motors_Disabled);

    /* Switch: '<S342>/Switch' incorporates:
     *  Constant: '<S342>/Constant5'
     *  Constant: '<S342>/Constant7'
     *  DataTypeConversion: '<S342>/Data Type Conversion'
     *  Logic: '<S344>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Enable_Wheels;
    }

    /* End of Switch: '<S342>/Switch' */

    /* Switch: '<S341>/Switch2' incorporates:
     *  Constant: '<S341>/Constant2'
     *  Constant: '<S365>/Constant'
     *  Constant: '<S368>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S365>/Compare'
     *  RelationalOperator: '<S368>/Compare'
     *  Sum: '<S341>/Subtract'
     *  Switch: '<S341>/Switch'
     *  Switch: '<S341>/Switch1'
     *  Switch: '<S341>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S341>/Switch2' incorporates:
       *  Constant: '<S341>/Constant5'
       *  Sum: '<S341>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S341>/Switch2' incorporates:
       *  Constant: '<S341>/Constant4'
       *  Sum: '<S341>/Subtract2'
       *  Switch: '<S341>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S341>/Switch1' incorporates:
       *  Constant: '<S341>/Constant1'
       *  Sum: '<S341>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S341>/Switch2' incorporates:
       *  Constant: '<S341>/Constant3'
       *  Switch: '<S341>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S341>/Switch1' incorporates:
       *  Constant: '<S341>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S341>/Switch2' */

    /* UnaryMinus: '<S341>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S357>/Switch1' incorporates:
     *  Constant: '<S362>/Constant'
     *  Constant: '<S363>/Constant'
     *  Logic: '<S357>/AND'
     *  RelationalOperator: '<S362>/Compare'
     *  RelationalOperator: '<S363>/Compare'
     *  Switch: '<S357>/Switch2'
     *  UnitDelay: '<S357>/Unit Delay'
     *  UnitDelay: '<S357>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S357>/Switch1' */

    /* Switch: '<S344>/Switch1' incorporates:
     *  Logic: '<S344>/Logical Operator1'
     *  Switch: '<S344>/Switch4'
     *  Switch: '<S344>/Switch9'
     */
    if (rtb_Enable_Wheels) {
      /* Signum: '<S344>/Sign' */
      if (rtIsNaN(rtb_Sin4)) {
        rtb_Add_bn = (rtNaN);
      } else if (rtb_Sin4 < 0.0) {
        rtb_Add_bn = -1.0;
      } else {
        rtb_Add_bn = (rtb_Sin4 > 0.0);
      }

      /* Switch: '<S344>/Switch5' incorporates:
       *  Constant: '<S344>/Constant3'
       *  Constant: '<S344>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_k = -1.5707963267948966;
      } else {
        rtb_Add_k = 0.0;
      }

      /* Merge: '<S7>/Merge3' incorporates:
       *  Gain: '<S344>/Gain3'
       *  Signum: '<S344>/Sign'
       *  Sum: '<S344>/Add'
       *  Switch: '<S344>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_bn) +
        rtb_Add_k;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Switch: '<S344>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S344>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S7>/Merge3' incorporates:
         *  Constant: '<S344>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S7>/Merge3' incorporates:
         *  Constant: '<S344>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S344>/Switch6' */
    } else {
      /* Merge: '<S7>/Merge3' incorporates:
       *  Switch: '<S344>/Switch4'
       *  Trigonometry: '<S344>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S344>/Switch1' */

    /* Switch: '<S354>/Switch1' incorporates:
     *  Constant: '<S354>/Constant'
     *  Constant: '<S354>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S354>/Switch1' */

    /* Switch: '<S361>/Init' incorporates:
     *  UnitDelay: '<S361>/FixPt Unit Delay1'
     *  UnitDelay: '<S361>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S361>/Init' */

    /* Sum: '<S359>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S360>/Switch2' incorporates:
     *  Constant: '<S358>/Constant1'
     *  Constant: '<S358>/Constant3'
     *  RelationalOperator: '<S360>/LowerRelop1'
     *  RelationalOperator: '<S360>/UpperRelop'
     *  Switch: '<S360>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S360>/Switch' incorporates:
       *  Constant: '<S358>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S360>/Switch2' */

    /* Sum: '<S359>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S344>/Switch8' incorporates:
     *  Logic: '<S344>/Logical Operator1'
     *  Switch: '<S344>/Switch2'
     */
    if (rtb_Enable_Wheels) {
      /* Switch: '<S344>/Switch' incorporates:
       *  Gain: '<S344>/Gain'
       *  Merge: '<S7>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Sin4;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S7>/Merge4' incorporates:
       *  Constant: '<S13>/Constant7'
       *  Constant: '<S13>/Constant8'
       *  Constant: '<S344>/Constant5'
       *  Gain: '<S344>/Gain2'
       *  Math: '<S344>/Magnitude1'
       *  MinMax: '<S344>/Min'
       *  Switch: '<S344>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S354>/Product' incorporates:
       *  Switch: '<S344>/Switch2'
       */
      rtb_Add_bn = rtb_Modulation_Drv * rtb_Init;

      /* Saturate: '<S354>/Saturation' incorporates:
       *  Switch: '<S344>/Switch2'
       */
      if (rtb_Add_bn > Boost_Trigger_High_Speed) {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_bn < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_bn;
      }

      /* End of Saturate: '<S354>/Saturation' */
    }

    /* End of Switch: '<S344>/Switch8' */

    /* Merge: '<S7>/Merge2' incorporates:
     *  SignalConversion: '<S343>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Add_h5;

    /* Switch: '<S341>/Switch6' incorporates:
     *  Constant: '<S341>/Constant11'
     *  Switch: '<S341>/Switch7'
     */
    rtb_Desired_Pipeline = TEST_Pipeline;

    /* Merge: '<S7>/Merge23' incorporates:
     *  Constant: '<S13>/Constant'
     *  SignalConversion generated from: '<S13>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S13>/Constant3'
     *  SignalConversion generated from: '<S13>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S13>/Constant9'
     *  SignalConversion generated from: '<S13>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S7>/Merge10' incorporates:
     *  Constant: '<S13>/Constant1'
     *  SignalConversion generated from: '<S13>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* SignalConversion generated from: '<S13>/Enable_Wheels' incorporates:
     *  Constant: '<S13>/Constant6'
     */
    rtb_Enable_Wheels = false;

    /* SignalConversion generated from: '<S13>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S13>/Constant13'
     */
    rtb_Reset_Wheel_Offsets = false;

    /* SignalConversion generated from: '<S13>/Disable_Wheels' incorporates:
     *  Constant: '<S13>/Constant14'
     */
    rtb_Disable_Wheels = false;

    /* SignalConversion generated from: '<S13>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S13>/Constant2'
     */
    rtb_Swerve_Motors_Disabled = false;

    /* SignalConversion: '<S13>/Signal Copy' incorporates:
     *  Inport: '<Root>/Gamepad_LB'
     */
    rtb_Button_Spinup_Enable = Robot_Control_U.Gamepad_LB;

    /* SignalConversion: '<S13>/Signal Copy1' incorporates:
     *  Inport: '<Root>/Gamepad_RB'
     */
    rtb_Button_Shoot_Enable = Robot_Control_U.Gamepad_RB;

    /* Update for UnitDelay: '<S351>/Delay Input1'
     *
     * Block description for '<S351>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_a;

    /* Update for UnitDelay: '<S350>/Delay Input1' incorporates:
     *  Constant: '<S13>/Constant5'
     *
     * Block description for '<S350>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S346>/Delay Input1'
     *
     * Block description for '<S346>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S347>/Delay Input1'
     *
     * Block description for '<S347>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S348>/Delay Input1'
     *
     * Block description for '<S348>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S349>/Delay Input1'
     *
     * Block description for '<S349>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S343>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE = rtb_AND1_c;

    /* Update for UnitDelay: '<S343>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S343>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S343>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S357>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1;

    /* Update for UnitDelay: '<S357>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S361>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S361>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S361>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Init;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* InitializeConditions for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
     *  UnitDelay: '<S14>/Unit Delay'
     */
    Robot_Control_DW.UnitDelay_DSTATE_ir = ((rtAction == rtPrevAction) &&
      (Robot_Control_DW.UnitDelay_DSTATE_ir));

    /* End of InitializeConditions for SubSystem: '<S1>/Test' */

    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Merge: '<S7>/Merge1' incorporates:
     *  Constant: '<S14>/Constant1'
     *  SignalConversion generated from: '<S14>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S14>/Constant2'
     *  SignalConversion generated from: '<S14>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S7>/Merge3' incorporates:
     *  Constant: '<S14>/Constant3'
     *  SignalConversion generated from: '<S14>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S7>/Merge4' incorporates:
     *  Constant: '<S14>/Constant4'
     *  SignalConversion generated from: '<S14>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* SignalConversion generated from: '<S14>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S14>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* SignalConversion generated from: '<S14>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S14>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S14>/Constant7'
     *  SignalConversion generated from: '<S14>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S14>/Constant9'
     *  SignalConversion generated from: '<S14>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S7>/Merge10' incorporates:
     *  Constant: '<S14>/Constant12'
     *  SignalConversion generated from: '<S14>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = true;

    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S14>/Constant14'
     *  Switch: '<S14>/Switch1'
     *  UnitDelay: '<S14>/Unit Delay'
     */
    if (Robot_Control_B.Button_Disable_Wheels) {
      rtb_Swerve_Motors_Disabled = true;
    } else {
      rtb_Swerve_Motors_Disabled = ((!Robot_Control_B.Button_Enable_Wheels) &&
        (Robot_Control_DW.UnitDelay_DSTATE_ir));
    }

    /* End of Switch: '<S14>/Switch' */

    /* Merge: '<S7>/Merge23' incorporates:
     *  Constant: '<S14>/Constant21'
     *  SignalConversion generated from: '<S14>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* SignalConversion generated from: '<S14>/Button_Spinup_Enable' incorporates:
     *  Constant: '<S14>/Constant11'
     */
    rtb_Button_Spinup_Enable = 0U;

    /* SignalConversion generated from: '<S14>/Button_Shoot_Enable' incorporates:
     *  Constant: '<S14>/Constant15'
     */
    rtb_Button_Shoot_Enable = 0U;

    /* SignalConversion generated from: '<S14>/Desired_Pipeline' incorporates:
     *  Constant: '<S14>/Constant22'
     */
    rtb_Desired_Pipeline = TEST_Pipeline;

    /* SignalConversion: '<S14>/Signal Copy' */
    rtb_Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* SignalConversion: '<S14>/Signal Copy2' */
    rtb_Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* SignalConversion: '<S14>/Signal Copy1' */
    rtb_Reset_Wheel_Offsets = Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S14>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_Swerve_Motors_Disabled;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Reshape: '<S26>/Reshapey' incorporates:
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_X'
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_Y'
   *  S-Function (sfix_udelay): '<S6>/Tapped Delay'
   *  S-Function (sfix_udelay): '<S6>/Tapped Delay1'
   *  Sum: '<S6>/Add'
   *  Sum: '<S6>/Add1'
   */
  rtb_Reshapey[0] = (Robot_Control_U.Vision_RobotPoseFieldSpace_X +
                     Robot_Control_DW.TappedDelay_X[0]) +
    Robot_Control_DW.TappedDelay_X[1];
  rtb_Reshapey[1] = (Robot_Control_U.Vision_RobotPoseFieldSpace_Y +
                     Robot_Control_DW.TappedDelay1_X[0]) +
    Robot_Control_DW.TappedDelay1_X[1];

  /* Delay: '<S26>/MemoryX' incorporates:
   *  Constant: '<S26>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S53>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S79>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S46>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S77>/Enable'
   */
  /* Logic: '<S6>/AND' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S77>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S26>/C'
     *  Delay: '<S26>/MemoryX'
     *  Product: '<S79>/Product'
     */
    rtb_Subtract_c3 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Subtract_c3;

    /* Sum: '<S77>/Sum' incorporates:
     *  Constant: '<S26>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S77>/C[k]*xhat[k|k-1]'
     *  Product: '<S77>/D[k]*u[k]'
     *  Sum: '<S77>/Add1'
     */
    rtb_Add_h5 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Sin4 = rtb_Reshapey[0] - (rtb_Add_h5 + rtb_Subtract_c3);

    /* Product: '<S77>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S26>/C'
     *  Delay: '<S26>/MemoryX'
     *  Product: '<S79>/Product'
     */
    rtb_Subtract_c3 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Subtract_c3;

    /* Sum: '<S77>/Sum' incorporates:
     *  Constant: '<S26>/D'
     *  Product: '<S77>/C[k]*xhat[k|k-1]'
     *  Product: '<S77>/D[k]*u[k]'
     *  Sum: '<S77>/Add1'
     */
    rtb_Subtract_c3 = rtb_Reshapey[1] - (rtb_Add_h5 + rtb_Subtract_c3);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S77>/Product3' incorporates:
     *  Constant: '<S27>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Sin4) +
      (-2.0601714451538746E-17 * rtb_Subtract_c3);

    /* Sum: '<S79>/Add1' incorporates:
     *  Product: '<S79>/Product'
     */
    rtb_Add_h5 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S77>/Product3' incorporates:
     *  Constant: '<S27>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Sin4) +
      (0.095124921972504 * rtb_Subtract_c3);

    /* Sum: '<S79>/Add1' incorporates:
     *  Product: '<S79>/Product'
     */
    rtb_Subtract_c3 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S79>/Product2' incorporates:
     *  Constant: '<S27>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Add_h5) +
      (5.9896845167210271E-17 * rtb_Subtract_c3);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Add_h5) +
      (0.095124921972503981 * rtb_Subtract_c3);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S77>/Product3' incorporates:
       *  Outport: '<S77>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S79>/Product2' incorporates:
       *  Outport: '<S79>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S6>/AND' */
  /* End of Outputs for SubSystem: '<S46>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S53>/Enabled Subsystem' */

  /* Sum: '<S53>/Add' incorporates:
   *  Delay: '<S26>/MemoryX'
   */
  rtb_Reshapey[0] = Robot_Control_B.Product2[0] +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Reshapey[1] = Robot_Control_B.Product2[1] +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Switch: '<S6>/Switch1'
   */
  if (KF_Enable != 0.0) {
    /* Switch: '<S6>/Switch' */
    Robot_Control_B.KF_Position_X = rtb_Reshapey[0];

    /* Switch: '<S6>/Switch1' */
    Robot_Control_B.KF_Position_Y = rtb_Reshapey[1];
  } else {
    /* Switch: '<S6>/Switch' incorporates:
     *  Inport: '<Root>/Odom_Position_X'
     */
    Robot_Control_B.KF_Position_X = Robot_Control_U.Odom_Position_X;

    /* Switch: '<S6>/Switch1' incorporates:
     *  Inport: '<Root>/Odom_Position_Y'
     */
    Robot_Control_B.KF_Position_Y = Robot_Control_U.Odom_Position_Y;
  }

  /* End of Switch: '<S6>/Switch' */

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
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

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* If: '<S86>/If' incorporates:
   *  Constant: '<S86>/Constant'
   *  DataTypeConversion: '<S86>/Data Type Conversion'
   *  Inport: '<Root>/IsBlueInactiveFirst'
   *  Inport: '<Root>/MatchTime'
   *  Sum: '<S86>/Subtract'
   */
  if ((rtb_GameState == 1) || ((140.0 - Robot_Control_U.MatchTime) <= 10.0)) {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.IsBlueActive,
      &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem' */
  } else if ((140.0 - Robot_Control_U.MatchTime) <= 35.0) {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S108>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.IsBlueActive, &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem1' */
  } else if ((140.0 - Robot_Control_U.MatchTime) <= 60.0) {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.IsBlueActive, &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem2' */
  } else if ((140.0 - Robot_Control_U.MatchTime) <= 85.0) {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.IsBlueActive, &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem3' */
  } else if ((140.0 - Robot_Control_U.MatchTime) <= 110.0) {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.IsBlueActive, &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S86>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.IsBlueActive,
      &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S86>/If Action Subsystem5' */
  }

  /* End of If: '<S86>/If' */

  /* If: '<S113>/If' incorporates:
   *  If: '<S114>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S113>/Blue' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    /* Merge: '<S113>/Merge' incorporates:
     *  Constant: '<S115>/BlueAllianceZoneX'
     *  Logic: '<S115>/AND'
     *  RelationalOperator: '<S115>/Less Than'
     */
    Robot_Control_B.Allow_Score_In_Alliance_Zone =
      ((Robot_Control_B.IsBlueActive) && (Robot_Control_B.KF_Position_X <
        BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S113>/Blue' */

    /* Outputs for IfAction SubSystem: '<S114>/Blue' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    /* Merge: '<S114>/Merge' incorporates:
     *  Constant: '<S117>/BlueAllianceZoneX'
     *  RelationalOperator: '<S117>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S114>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S113>/Red' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    /* Merge: '<S113>/Merge' incorporates:
     *  Constant: '<S116>/RedAllianceZoneX'
     *  Logic: '<S116>/AND'
     *  RelationalOperator: '<S116>/GreaterThan'
     */
    Robot_Control_B.Allow_Score_In_Alliance_Zone = ((Robot_Control_B.IsRedActive)
      && (Robot_Control_B.KF_Position_X > RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S113>/Red' */

    /* Outputs for IfAction SubSystem: '<S114>/Red' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    /* Merge: '<S114>/Merge' incorporates:
     *  Constant: '<S118>/RedAllianceZoneX'
     *  RelationalOperator: '<S118>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S114>/Red' */
  }

  /* End of If: '<S113>/If' */

  /* MinMax: '<S90>/Max' incorporates:
   *  Abs: '<S90>/Abs1'
   *  Abs: '<S90>/Abs2'
   *  Abs: '<S90>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.Measured_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* Logic: '<S87>/AND' incorporates:
   *  Abs: '<S87>/Abs'
   *  Abs: '<S87>/Abs1'
   *  Abs: '<S87>/Abs4'
   *  Constant: '<S87>/Constant1'
   *  Constant: '<S87>/Constant2'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  RelationalOperator: '<S87>/Relational Operator'
   *  RelationalOperator: '<S87>/Relational Operator1'
   *  RelationalOperator: '<S87>/Relational Operator4'
   *  Sum: '<S87>/Subtract'
   *  Sum: '<S87>/Subtract1'
   *  Sum: '<S87>/Subtract4'
   *  UnitDelay generated from: '<S10>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Compare_a = (((fabs(Robot_Control_DW.UnitDelay_1_DSTATE -
    Robot_Control_U.Gyro_Angle_Field_rad) <= Robot_Control_DW.UnitDelay_4_DSTATE)
                    && (fabs(Robot_Control_DW.UnitDelay_2_DSTATE -
    Robot_Control_B.Measured_Shooter_Speed_Max) <= Shooter_Motor_Max_Error_Shoot))
                   && (fabs(Robot_Control_DW.UnitDelay_3_DSTATE -
    Robot_Control_B.Estimated_Hood_Pos) <= Hood_Pos_Max_Error_Shoot));

  /* Logic: '<S87>/AND2' incorporates:
   *  Constant: '<S87>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Logic: '<S87>/AND1'
   *  Math: '<S87>/Hypot'
   *  RelationalOperator: '<S87>/GreaterThan'
   */
  Robot_Control_B.Ready_to_Score =
    (((Robot_Control_B.Allow_Score_In_Alliance_Zone) && (rt_hypotd_snf
       (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
       Robot_Velocity_Maximum_Shooter)) && rtb_Compare_a);

  /* Logic: '<S87>/AND3' */
  Robot_Control_B.Ready_to_Pass = ((Robot_Control_B.Is_Outside_Alliance_Zone) &&
    rtb_Compare_a);

  /* Chart: '<S10>/Shooter_Transfer_Feeder Chart' */
  guard1 = false;
  guard2 = false;
  if (Robot_Control_DW.is_active_c2_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c2_Robot_Control = 1U;
    Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Not_Shooting;
    Robot_Control_B.Shooter_Active = false;
    Robot_Control_B.Desired_Transfer_Speed = 0.0;
    Robot_Control_B.Desired_Feeder_Speed = 0.0;
    guard1 = true;
  } else if (Robot_Control_DW.is_c2_Robot_Control ==
             Robot_Control_IN_Not_Shooting) {
    Robot_Control_B.Shooter_Active = false;
    Robot_Control_B.Desired_Feeder_Speed = 0.0;
    if ((rtb_Button_Spinup_Enable != 0) || (rtb_Button_Shoot_Enable != 0)) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.Desired_Transfer_Speed = 0.0;
      guard2 = true;
    } else {
      guard1 = true;
    }
  } else {
    /* case IN_Shooting: */
    Robot_Control_B.Shooter_Active = true;
    if ((rtb_Button_Spinup_Enable == 0) && (rtb_Button_Shoot_Enable == 0)) {
      Robot_Control_DW.is_Shooting = Robot_Contro_IN_NO_ACTIVE_CHILD;
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Not_Shooting;
      Robot_Control_B.Shooter_Active = false;
      Robot_Control_B.Desired_Transfer_Speed = 0.0;
      Robot_Control_B.Desired_Feeder_Speed = 0.0;
      guard1 = true;
    } else {
      switch (Robot_Control_DW.is_Shooting) {
       case Robot_Control_IN_Feeder:
        Robot_Control_B.Desired_Feeder_Speed = Target_Feeder_Speed;
        if (rtb_Button_Shoot_Enable == 0) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.Desired_Transfer_Speed = 0.0;
          Robot_Control_B.Desired_Feeder_Speed = 0.0;
        }
        break;

       case Robot_Control_IN_Spinning_Up:
        Robot_Control_B.Desired_Feeder_Speed = 0.0;
        if ((rtb_Button_Shoot_Enable != 0) && ((Robot_Control_B.Ready_to_Score) ||
             (Robot_Control_B.Ready_to_Pass))) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Transfer;
          Robot_Control_B.Desired_Transfer_Speed = Target_Transfer_Speed;
        }
        break;

       default:
        /* case IN_Transfer: */
        if (Robot_Control_U.Measured_Transfer_Speed >
            (Robot_Control_B.Desired_Transfer_Speed * Transfer_Minimum_Factor))
        {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Feeder;
          Robot_Control_B.Desired_Feeder_Speed = Target_Feeder_Speed;
        } else if (rtb_Button_Shoot_Enable == 0) {
          Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
          Robot_Control_B.Desired_Transfer_Speed = 0.0;
          Robot_Control_B.Desired_Feeder_Speed = 0.0;
        }
        break;
      }

      guard2 = true;
    }
  }

  if (guard2) {
    /* Outputs for IfAction SubSystem: '<S85>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S94>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S96>/While Iterator'
     */
    /* If: '<S85>/If' incorporates:
     *  Constant: '<S102>/Constant'
     *  Constant: '<S102>/Constant1'
     *  Constant: '<S102>/Constant2'
     *  Constant: '<S102>/Constant3'
     *  Constant: '<S102>/Constant4'
     *  Constant: '<S94>/Constant'
     *  Constant: '<S97>/Constant'
     *  Constant: '<S97>/Constant1'
     *  Constant: '<S97>/Constant2'
     *  Constant: '<S97>/Constant3'
     *  Constant: '<S97>/Constant4'
     *  Constant: '<S97>/Constant5'
     *  Constant: '<S97>/Constant6'
     *  Constant: '<S97>/Constant7'
     *  Constant: '<S97>/Constant8'
     *  Constant: '<S97>/Constant9'
     *  Constant: '<S98>/Constant'
     *  Constant: '<S98>/Constant1'
     *  Constant: '<S98>/Constant2'
     *  Constant: '<S98>/Constant3'
     *  Constant: '<S98>/Constant4'
     *  Constant: '<S99>/Constant'
     *  Constant: '<S99>/Constant1'
     *  Constant: '<S99>/Constant2'
     *  Constant: '<S99>/Constant3'
     *  Constant: '<S99>/Constant4'
     *  Inport: '<Root>/IsBlueAlliance'
     *  Memory: '<S96>/Memory'
     *  Memory: '<S96>/Memory1'
     *  Memory: '<S96>/Memory2'
     *  Memory: '<S96>/Memory3'
     *  Merge: '<S85>/Merge'
     *  Merge: '<S85>/Merge1'
     *  Merge: '<S85>/Merge2'
     *  Merge: '<S85>/Merge3'
     *  S-Function (sfix_look1_dyn): '<S97>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S98>/Lookup Table Dynamic'
     *  S-Function (sfix_look1_dyn): '<S99>/Lookup Table Dynamic'
     *  SignalConversion generated from: '<S92>/Desired_Shooter_Speed'
     *  SignalConversion generated from: '<S97>/Lookup Table Dynamic'
     *  Sum: '<S95>/Subtract'
     *  Sum: '<S95>/Subtract1'
     *  Switch: '<S100>/Switch'
     *  Switch: '<S100>/Switch1'
     *  Trigonometry: '<S95>/Tanh'
     */
    rtb_shot_distance[0] = Dist_Arr_0;
    rtb_shot_distance[1] = Dist_Arr_1;
    rtb_shot_distance[2] = Dist_Arr_2;
    rtb_shot_distance[3] = Dist_Arr_3;
    rtb_shot_distance[4] = Dist_Arr_4;

    /* End of Outputs for SubSystem: '<S94>/Iterate_Shot_Target' */
    rtb_TmpSignalConversionAtLook_k[0] = Gyro_Err_Arr_0;
    rtb_TmpSignalConversionAtLook_k[1] = Gyro_Err_Arr_1;
    rtb_TmpSignalConversionAtLook_k[2] = Gyro_Err_Arr_2;
    rtb_TmpSignalConversionAtLook_k[3] = Gyro_Err_Arr_3;
    rtb_TmpSignalConversionAtLook_k[4] = Gyro_Err_Arr_4;
    rtb_TmpSignalConversionAtLoo_o3[0] = Hood_Position_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Hood_Position_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Hood_Position_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Hood_Position_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Hood_Position_4;
    for (i = 0; i < 5; i++) {
      rtb_shot_distance_m[i] = rtb_shot_distance[i];
      rtb_shot_distance_fj[i] = rtb_shot_distance[i];
    }

    rtb_TmpSignalConversionAtLook_f[0] = Shooter_Spd_0;
    rtb_TmpSignalConversionAtLook_f[1] = Shooter_Spd_1;
    rtb_TmpSignalConversionAtLook_f[2] = Shooter_Spd_2;
    rtb_TmpSignalConversionAtLook_f[3] = Shooter_Spd_3;
    rtb_TmpSignalConversionAtLook_f[4] = Shooter_Spd_4;
    if (Robot_Control_U.IsBlueAlliance != 0.0) {
      /* Switch: '<S100>/Switch' incorporates:
       *  Constant: '<S100>/Constant'
       */
      Robot_Control_B.Target_X = Blue_Hub_X;

      /* Switch: '<S100>/Switch1' incorporates:
       *  Constant: '<S100>/Constant1'
       */
      Robot_Control_B.Target_Y = Blue_Hub_Y;
    } else {
      /* Switch: '<S100>/Switch' incorporates:
       *  Constant: '<S100>/Constant2'
       */
      Robot_Control_B.Target_X = Red_Hub_X;

      /* Switch: '<S100>/Switch1' incorporates:
       *  Constant: '<S100>/Constant3'
       */
      Robot_Control_B.Target_Y = Red_Hub_Y;
    }

    /* Outputs for Iterator SubSystem: '<S94>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S96>/While Iterator'
     */
    rtb_Button_Spinup_Enable = 1U;
    rtb_Add_h5 = 0.0;
    rtb_Subtract_c3 = 0.0;
    rtb_Modulation_Drv = 0.0;
    rtb_AND1_c = true;
    rtb_Compare_a = true;
    rtb_TOF_g[0] = TOF_Arr_0;
    rtb_TOF_g[1] = TOF_Arr_1;
    rtb_TOF_g[2] = TOF_Arr_2;
    rtb_TOF_g[3] = TOF_Arr_3;
    rtb_TOF_g[4] = TOF_Arr_4;
    for (i = 0; i < 5; i++) {
      rtb_shot_distance_o[i] = rtb_shot_distance[i];
    }

    while (rtb_Compare_a && (rtb_Button_Spinup_Enable <= 10)) {
      /* Switch: '<S103>/Switch' incorporates:
       *  Memory: '<S96>/Memory1'
       *  Memory: '<S96>/Memory2'
       *  Switch: '<S103>/Switch1'
       */
      if (rtb_Button_Spinup_Enable > 1) {
        rtb_Sin4 = rtb_Add_h5;
        rtb_Switch1 = rtb_Subtract_c3;
      } else {
        rtb_Sin4 = Robot_Control_B.Target_X;
        rtb_Switch1 = Robot_Control_B.Target_Y;
      }

      /* End of Switch: '<S103>/Switch' */

      /* Math: '<S101>/Hypot' incorporates:
       *  Sum: '<S101>/Subtract'
       *  Sum: '<S101>/Subtract1'
       */
      Robot_Control_B.Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_Switch1 -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S102>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S102>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_TOF), &rtb_TOF_g[0],
                           Robot_Control_B.Desired_Shot_Distance,
                           &rtb_shot_distance_o[0], 4U);

      /* Sum: '<S104>/Subtract' incorporates:
       *  Memory: '<S96>/Memory3'
       *  Sum: '<S104>/Subtract1'
       */
      rtb_Subtract_c3 = rtb_TOF - rtb_Modulation_Drv;

      /* Sum: '<S104>/Add' incorporates:
       *  Gain: '<S104>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S104>/Product'
       *  Sum: '<S104>/Subtract'
       */
      Robot_Control_B.Desired_Target_X = (rtb_Subtract_c3 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S104>/Add1' incorporates:
       *  Gain: '<S104>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S104>/Product1'
       */
      Robot_Control_B.Desired_Target_Y = (rtb_Subtract_c3 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Switch1;

      /* Memory: '<S96>/Memory' */
      rtb_Compare_a = rtb_AND1_c;

      /* Update for Memory: '<S96>/Memory1' */
      rtb_Add_h5 = Robot_Control_B.Desired_Target_X;

      /* Update for Memory: '<S96>/Memory2' */
      rtb_Subtract_c3 = Robot_Control_B.Desired_Target_Y;

      /* Update for Memory: '<S96>/Memory3' */
      rtb_Modulation_Drv = rtb_TOF;

      /* Update for Memory: '<S96>/Memory' incorporates:
       *  Constant: '<S106>/Constant'
       *  Math: '<S105>/Hypot'
       *  RelationalOperator: '<S106>/Compare'
       *  Sum: '<S105>/Subtract'
       *  Sum: '<S105>/Subtract1'
       */
      rtb_AND1_c = (rt_hypotd_snf(Robot_Control_B.Desired_Target_X - rtb_Sin4,
        Robot_Control_B.Desired_Target_Y - rtb_Switch1) >=
                    Shot_Target_Error_Thresh);
      rtb_Button_Spinup_Enable++;
    }

    /* End of Outputs for SubSystem: '<S94>/Iterate_Shot_Target' */
    /* Dynamic Look-Up Table Block: '<S97>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.Allowed_Shoot_Gyro_Error_Calc),
                         &rtb_TmpSignalConversionAtLook_k[0],
                         Robot_Control_B.Desired_Shot_Distance,
                         &rtb_shot_distance[0], 4U);

    /* Dynamic Look-Up Table Block: '<S98>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.Desired_Hood_Pos_Calc),
                         &rtb_TmpSignalConversionAtLoo_o3[0],
                         Robot_Control_B.Desired_Shot_Distance,
                         &rtb_shot_distance_m[0], 4U);

    /* Dynamic Look-Up Table Block: '<S99>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(Robot_Control_B.Desired_Shooter_Motor_Speed_Cal),
                         &rtb_TmpSignalConversionAtLook_f[0],
                         Robot_Control_B.Desired_Shot_Distance,
                         &rtb_shot_distance_fj[0], 4U);
    Robot_Control_B.Desired_Shooter_Speed =
      Robot_Control_B.Desired_Shooter_Motor_Speed_Cal;
    Robot_Control_B.Desired_Hood_Pos_Shoot =
      Robot_Control_B.Desired_Hood_Pos_Calc;
    Robot_Control_B.Allowed_Shoot_Gyro_Error =
      Robot_Control_B.Allowed_Shoot_Gyro_Error_Calc;
    Robot_Control_B.Desired_Gyro_Angle = rt_atan2d_snf
      (Robot_Control_B.Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.Desired_Target_X - Robot_Control_B.KF_Position_X);

    /* End of Outputs for SubSystem: '<S85>/Desired Shooting Parameters Math' */
  }

  if (guard1) {
    /* Outputs for IfAction SubSystem: '<S85>/Shooter Not Active' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* If: '<S85>/If' incorporates:
     *  Constant: '<S93>/Constant'
     *  Constant: '<S93>/Constant1'
     *  Merge: '<S85>/Merge'
     *  Merge: '<S85>/Merge1'
     *  Merge: '<S85>/Merge2'
     *  Merge: '<S85>/Merge3'
     *  SignalConversion generated from: '<S93>/Desired_Shooter_Speed'
     *  UnitDelay: '<S85>/Unit Delay'
     */
    Robot_Control_B.Desired_Shooter_Speed = 0.0;
    Robot_Control_B.Allowed_Shoot_Gyro_Error = 0.0;
    Robot_Control_B.Desired_Gyro_Angle = Robot_Control_B.Steering_Abs_Cmd;
    Robot_Control_B.Desired_Hood_Pos_Shoot = Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S85>/Shooter Not Active' */
  }

  /* End of Chart: '<S10>/Shooter_Transfer_Feeder Chart' */

  /* If: '<S11>/If' incorporates:
   *  Constant: '<S129>/Constant'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Merge: '<S11>/Merge'
   *  Merge: '<S11>/Merge1'
   *  Merge: '<S11>/Merge2'
   *  Merge: '<S11>/Merge3'
   *  Merge: '<S11>/Merge4'
   *  Merge: '<S11>/Merge5'
   *  Merge: '<S11>/Merge7'
   *  Merge: '<S11>/Merge8'
   *  SignalConversion generated from: '<S129>/Robot_Reached_Destination'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  Robot_Control_DW.If_ActiveSubsystem = 1;
  if ((rtPrevAction != 1) && (rtPrevAction == 0)) {
    /* Disable for If: '<S135>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S138>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S140>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;

      /* End of Disable for If: '<S138>/If' */
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S135>/If' */
  }

  /* Outputs for IfAction SubSystem: '<S11>/Pass Through' incorporates:
   *  ActionPort: '<S129>/Action Port'
   */
  Robot_Control_B.Robot_Reached_Destination = true;
  Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Desired_Gyro_Angle;
  Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;
  Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;
  Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;
  Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;
  Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;
  Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

  /* End of If: '<S11>/If' */
  /* End of Outputs for SubSystem: '<S11>/Pass Through' */

  /* Signum: '<S279>/Sign2' incorporates:
   *  UnitDelay: '<S279>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S279>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S279>/Product1' incorporates:
   *  Signum: '<S279>/Sign1'
   *  Signum: '<S279>/Sign2'
   */
  rtb_Add_bn *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_bn)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_bn, 256.0);
  }

  /* Switch: '<S279>/Switch' incorporates:
   *  Constant: '<S279>/Constant'
   *  Constant: '<S284>/Constant'
   *  Constant: '<S285>/Constant'
   *  Logic: '<S279>/or'
   *  Product: '<S279>/Product1'
   *  RelationalOperator: '<S284>/Compare'
   *  RelationalOperator: '<S285>/Compare'
   *  UnitDelay: '<S279>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S279>/Switch' */

  /* Switch: '<S290>/Init' incorporates:
   *  UnitDelay: '<S290>/FixPt Unit Delay1'
   *  UnitDelay: '<S290>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Subtract_c3 = rtb_Sin4;
  } else {
    rtb_Subtract_c3 = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S290>/Init' */

  /* RelationalOperator: '<S286>/Compare' incorporates:
   *  Constant: '<S286>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S287>/Compare' incorporates:
   *  Constant: '<S287>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Sin4 > 0.0);

  /* Abs: '<S279>/Abs' incorporates:
   *  Sum: '<S279>/Subtract'
   *  UnitDelay: '<S279>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S279>/Switch5' incorporates:
   *  Constant: '<S279>/Constant1'
   *  Switch: '<S279>/Switch1'
   *  UnaryMinus: '<S279>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* SignalConversion generated from: '<S279>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S279>/Constant4'
     *  Constant: '<S279>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S279>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S279>/Constant2'
     *  Constant: '<S279>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S279>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S279>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S279>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S279>/Constant10'
     *  Constant: '<S279>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S279>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S279>/Constant7'
     *  Constant: '<S279>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S279>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S279>/Lookup Table Dynamic1'
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

    /* Switch: '<S279>/Switch3' incorporates:
     *  Constant: '<S279>/Constant1'
     *  Constant: '<S279>/Constant3'
     *  UnaryMinus: '<S279>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_bn = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_bn = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S279>/Switch3' */
  }

  /* End of Switch: '<S279>/Switch5' */

  /* Product: '<S279>/Product' incorporates:
   *  Switch: '<S279>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_bn * rtb_Merge1;

  /* Sum: '<S288>/Sum1' */
  rtb_Add_h5 = rtb_Sin4 - rtb_Subtract_c3;

  /* Switch: '<S289>/Switch2' incorporates:
   *  RelationalOperator: '<S289>/LowerRelop1'
   */
  if (!(rtb_Add_h5 > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S279>/Switch2' incorporates:
     *  Constant: '<S279>/Constant1'
     *  Switch: '<S279>/Switch4'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_Modulation_Drv = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S279>/Switch4' incorporates:
       *  Constant: '<S279>/Constant1'
       */
      rtb_Modulation_Drv = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S279>/Switch4' incorporates:
       *  Constant: '<S279>/Constant3'
       *  UnaryMinus: '<S279>/Unary Minus1'
       */
      rtb_Modulation_Drv = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S279>/Switch2' */

    /* Product: '<S279>/Product2' */
    rtb_Modulation_Drv *= rtb_Merge1;

    /* Switch: '<S289>/Switch' incorporates:
     *  RelationalOperator: '<S289>/UpperRelop'
     */
    if (rtb_Add_h5 < rtb_Modulation_Drv) {
      rtb_Optimized_Module_Angle = rtb_Modulation_Drv;
    } else {
      rtb_Optimized_Module_Angle = rtb_Add_h5;
    }

    /* End of Switch: '<S289>/Switch' */
  }

  /* End of Switch: '<S289>/Switch2' */

  /* Sum: '<S288>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle +
    rtb_Subtract_c3;

  /* Switch: '<S282>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S282>/Switch' incorporates:
     *  Constant: '<S314>/Constant3'
     *  Constant: '<S314>/Constant4'
     *  Math: '<S314>/Math Function'
     *  Sum: '<S282>/Subtract'
     *  Sum: '<S314>/Add1'
     *  Sum: '<S314>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S282>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S282>/Switch' */

  /* Sum: '<S310>/Add1' incorporates:
   *  Constant: '<S310>/Constant3'
   *  Constant: '<S310>/Constant4'
   *  Math: '<S310>/Math Function'
   *  Sum: '<S309>/Sum'
   *  Sum: '<S310>/Add2'
   */
  rtb_Sin4 = rt_modd_snf((Robot_Control_B.Steering_Abs_Cmd_SPF -
    Robot_Control_B.Gyro_Angle_SPF) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Sum: '<S312>/Sum1' incorporates:
   *  Constant: '<S309>/Constant2'
   *  Product: '<S312>/Product'
   *  Sum: '<S312>/Sum'
   *  UnitDelay: '<S312>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_Sin4 - Robot_Control_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S309>/Product' incorporates:
   *  Constant: '<S309>/Constant3'
   */
  rtb_Add_h5 = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S311>/Diff' incorporates:
   *  UnitDelay: '<S311>/UD'
   *
   * Block description for '<S311>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S311>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Add_h5 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S309>/Saturation' */
  if (rtb_Add_bn > Steering_Heading_Control_D_UL) {
    rtb_Add_bn = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Heading_Control_D_LL) {
    rtb_Add_bn = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S309>/Add' incorporates:
   *  Gain: '<S309>/Gain1'
   *  Saturate: '<S309>/Saturation'
   */
  rtb_Modulation_Drv = (Steering_Heading_Control_P * rtb_Sin4) + rtb_Add_bn;

  /* Sum: '<S309>/Subtract' incorporates:
   *  Constant: '<S309>/Constant'
   */
  rtb_Subtract_c3 = Steering_Heading_Control_Total_UL - rtb_Modulation_Drv;

  /* Sum: '<S309>/Sum2' incorporates:
   *  Gain: '<S309>/Gain2'
   *  UnitDelay: '<S309>/Unit Delay'
   */
  rtb_Sin4 = (Steering_Heading_Control_I * rtb_Sin4) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S313>/Switch2' incorporates:
   *  RelationalOperator: '<S313>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Subtract_c3)) {
    /* Sum: '<S309>/Subtract1' incorporates:
     *  Constant: '<S309>/Constant1'
     */
    rtb_Subtract_c3 = Steering_Heading_Control_Total_LL - rtb_Modulation_Drv;

    /* Switch: '<S313>/Switch' incorporates:
     *  RelationalOperator: '<S313>/UpperRelop'
     */
    if (!(rtb_Sin4 < rtb_Subtract_c3)) {
      rtb_Subtract_c3 = rtb_Sin4;
    }

    /* End of Switch: '<S313>/Switch' */
  }

  /* End of Switch: '<S313>/Switch2' */

  /* Saturate: '<S309>/Saturation1' */
  if (rtb_Subtract_c3 > Steering_Heading_Control_I_UL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_UL;
  } else if (rtb_Subtract_c3 < Steering_Heading_Control_I_LL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_LL;
  }

  /* End of Saturate: '<S309>/Saturation1' */

  /* Sum: '<S309>/Add1' */
  rtb_Add_bn = rtb_Modulation_Drv + rtb_Subtract_c3;

  /* Saturate: '<S309>/Saturation2' */
  if (rtb_Add_bn > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S309>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_bn < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S309>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S309>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_bn;
  }

  /* End of Saturate: '<S309>/Saturation2' */

  /* Switch: '<S293>/Switch' incorporates:
   *  Abs: '<S293>/Abs'
   *  Constant: '<S293>/Constant'
   *  Constant: '<S308>/Constant'
   *  RelationalOperator: '<S308>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Sin4 = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S293>/Switch' */

  /* Signum: '<S292>/Sign2' incorporates:
   *  UnitDelay: '<S292>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S292>/Sign1' */
  if (rtIsNaN(rtb_Sin4)) {
    rtb_Add_k = (rtNaN);
  } else if (rtb_Sin4 < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (rtb_Sin4 > 0.0);
  }

  /* Product: '<S292>/Product1' incorporates:
   *  Signum: '<S292>/Sign1'
   *  Signum: '<S292>/Sign2'
   */
  rtb_Add_bn *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_bn)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_bn, 256.0);
  }

  /* Switch: '<S292>/Switch' incorporates:
   *  Constant: '<S292>/Constant'
   *  Constant: '<S301>/Constant'
   *  Constant: '<S302>/Constant'
   *  Logic: '<S292>/or'
   *  Product: '<S292>/Product1'
   *  RelationalOperator: '<S301>/Compare'
   *  RelationalOperator: '<S302>/Compare'
   *  UnitDelay: '<S292>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Init_g = rtb_Sin4;
  } else {
    rtb_Init_g = 0.0;
  }

  /* End of Switch: '<S292>/Switch' */

  /* Switch: '<S307>/Init' incorporates:
   *  UnitDelay: '<S307>/FixPt Unit Delay1'
   *  UnitDelay: '<S307>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Init_g;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S307>/Init' */

  /* RelationalOperator: '<S303>/Compare' incorporates:
   *  Constant: '<S303>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Init_g == 0.0);

  /* RelationalOperator: '<S304>/Compare' incorporates:
   *  Constant: '<S304>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Init_g > 0.0);

  /* Abs: '<S292>/Abs' incorporates:
   *  Sum: '<S292>/Subtract'
   *  UnitDelay: '<S292>/Unit Delay'
   */
  rtb_Modulation_Drv = fabs(Robot_Control_DW.UnitDelay_DSTATE_d - rtb_Sin4);

  /* Switch: '<S292>/Switch5' incorporates:
   *  Constant: '<S292>/Constant1'
   *  Switch: '<S292>/Switch1'
   *  UnaryMinus: '<S292>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* SignalConversion generated from: '<S292>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S292>/Constant4'
     *  Constant: '<S292>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S292>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S292>/Constant2'
     *  Constant: '<S292>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S292>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S292>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Reshapey[0],
                         rtb_Modulation_Drv, &rtb_Minus_n[0], 1U);
    rtb_Modulation_Drv = rtb_LookupTableDynamic;
    rtb_Add_bn = -Steering_Absolute_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S292>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S292>/Constant10'
     *  Constant: '<S292>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S292>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S292>/Constant7'
     *  Constant: '<S292>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S292>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S292>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Reshapey[0],
                         rtb_Modulation_Drv, &rtb_Minus_n[0], 1U);
    rtb_Modulation_Drv = rtb_LookupTableDynamic1;

    /* Switch: '<S292>/Switch3' incorporates:
     *  Constant: '<S292>/Constant1'
     *  Constant: '<S292>/Constant3'
     *  UnaryMinus: '<S292>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_bn = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_bn = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S292>/Switch3' */
  }

  /* End of Switch: '<S292>/Switch5' */

  /* Product: '<S292>/Product' incorporates:
   *  Switch: '<S292>/Switch1'
   */
  rtb_Switch2_p2 = rtb_Add_bn * rtb_Modulation_Drv;

  /* Sum: '<S305>/Sum1' */
  rtb_Sin4 = rtb_Init_g - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S306>/Switch2' incorporates:
   *  RelationalOperator: '<S306>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Switch2_p2)) {
    /* Switch: '<S292>/Switch2' incorporates:
     *  Constant: '<S292>/Constant1'
     *  Switch: '<S292>/Switch4'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_Switch1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S292>/Switch4' incorporates:
       *  Constant: '<S292>/Constant1'
       */
      rtb_Switch1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S292>/Switch4' incorporates:
       *  Constant: '<S292>/Constant3'
       *  UnaryMinus: '<S292>/Unary Minus1'
       */
      rtb_Switch1 = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S292>/Switch2' */

    /* Product: '<S292>/Product2' */
    rtb_Switch1 *= rtb_Modulation_Drv;

    /* Switch: '<S306>/Switch' incorporates:
     *  RelationalOperator: '<S306>/UpperRelop'
     */
    if (rtb_Sin4 < rtb_Switch1) {
      rtb_Switch2_p2 = rtb_Switch1;
    } else {
      rtb_Switch2_p2 = rtb_Sin4;
    }

    /* End of Switch: '<S306>/Switch' */
  }

  /* End of Switch: '<S306>/Switch2' */

  /* Sum: '<S305>/Sum' */
  rtb_Modulation_Drv = rtb_Switch2_p2 + rtb_Optimized_Module_Angle_p;

  /* Signum: '<S291>/Sign2' incorporates:
   *  UnitDelay: '<S291>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S291>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S291>/Product1' incorporates:
   *  Signum: '<S291>/Sign1'
   *  Signum: '<S291>/Sign2'
   */
  rtb_Add_bn *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_bn)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_bn, 256.0);
  }

  /* Switch: '<S291>/Switch' incorporates:
   *  Constant: '<S291>/Constant'
   *  Constant: '<S294>/Constant'
   *  Constant: '<S295>/Constant'
   *  Logic: '<S291>/or'
   *  Product: '<S291>/Product1'
   *  RelationalOperator: '<S294>/Compare'
   *  RelationalOperator: '<S295>/Compare'
   *  UnitDelay: '<S291>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Init_g = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Init_g = 0.0;
  }

  /* End of Switch: '<S291>/Switch' */

  /* Switch: '<S300>/Init' incorporates:
   *  UnitDelay: '<S300>/FixPt Unit Delay1'
   *  UnitDelay: '<S300>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Init_g;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S300>/Init' */

  /* RelationalOperator: '<S296>/Compare' incorporates:
   *  Constant: '<S296>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Init_g == 0.0);

  /* RelationalOperator: '<S297>/Compare' incorporates:
   *  Constant: '<S297>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Init_g > 0.0);

  /* Abs: '<S291>/Abs' incorporates:
   *  Sum: '<S291>/Subtract'
   *  UnitDelay: '<S291>/Unit Delay'
   */
  rtb_Switch1 = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                     Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S291>/Switch5' incorporates:
   *  Constant: '<S291>/Constant1'
   *  Switch: '<S291>/Switch1'
   *  UnaryMinus: '<S291>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* SignalConversion generated from: '<S291>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S291>/Constant4'
     *  Constant: '<S291>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S291>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S291>/Constant2'
     *  Constant: '<S291>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S291>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S291>/Lookup Table Dynamic'
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
    rtb_Add_bn = -Steering_Relative_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S291>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S291>/Constant10'
     *  Constant: '<S291>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S291>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S291>/Constant7'
     *  Constant: '<S291>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S291>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S291>/Lookup Table Dynamic1'
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

    /* Switch: '<S291>/Switch3' incorporates:
     *  Constant: '<S291>/Constant1'
     *  Constant: '<S291>/Constant3'
     *  UnaryMinus: '<S291>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_bn = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_bn = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S291>/Switch3' */
  }

  /* End of Switch: '<S291>/Switch5' */

  /* Product: '<S291>/Product' incorporates:
   *  Switch: '<S291>/Switch1'
   */
  rtb_Sin4 = rtb_Add_bn * rtb_Switch1;

  /* Sum: '<S298>/Sum1' */
  rtb_Switch2 = rtb_Init_g - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S299>/Switch2' incorporates:
   *  RelationalOperator: '<S299>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_Sin4)) {
    /* Switch: '<S291>/Switch2' incorporates:
     *  Constant: '<S291>/Constant1'
     *  Constant: '<S291>/Constant3'
     *  Switch: '<S291>/Switch4'
     *  UnaryMinus: '<S291>/Unary Minus1'
     */
    if (rtb_Is_Absolute_Translation_g) {
      rtb_Add_bn = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S291>/Switch4' incorporates:
       *  Constant: '<S291>/Constant1'
       */
      rtb_Add_bn = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_bn = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S291>/Product2' incorporates:
     *  Switch: '<S291>/Switch2'
     */
    rtb_Sin4 = rtb_Add_bn * rtb_Switch1;

    /* Switch: '<S299>/Switch' incorporates:
     *  RelationalOperator: '<S299>/UpperRelop'
     */
    if (!(rtb_Switch2 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2;
    }

    /* End of Switch: '<S299>/Switch' */
  }

  /* End of Switch: '<S299>/Switch2' */

  /* Sum: '<S298>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S281>/Switch' */
  if (Robot_Control_B.Is_Absolute_Steering_SPF) {
    /* Switch: '<S281>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Modulation_Drv;
  } else {
    /* Switch: '<S281>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S281>/Switch' */

  /* Fcn: '<S322>/r->x' incorporates:
   *  Fcn: '<S327>/r->x'
   *  Fcn: '<S332>/r->x'
   *  Fcn: '<S337>/r->x'
   */
  rtb_Init_g = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S316>/Add' incorporates:
   *  Fcn: '<S322>/r->x'
   *  Fcn: '<S323>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Init_g;

  /* Fcn: '<S322>/theta->y' incorporates:
   *  Fcn: '<S327>/theta->y'
   *  Fcn: '<S332>/theta->y'
   *  Fcn: '<S337>/theta->y'
   */
  rtb_Switch2_p2 = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S316>/Add' incorporates:
   *  Fcn: '<S322>/theta->y'
   *  Fcn: '<S323>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S317>/Add' incorporates:
   *  Fcn: '<S328>/r->x'
   *  Fcn: '<S328>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Init_g;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S318>/Add' incorporates:
   *  Fcn: '<S333>/r->x'
   *  Fcn: '<S333>/theta->y'
   */
  rtb_Add2_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Init_g;
  rtb_Add2_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S319>/Add' incorporates:
   *  Fcn: '<S338>/r->x'
   *  Fcn: '<S338>/theta->y'
   */
  rtb_Switch1 = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Init_g;
  rtb_Switch2 = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2_p2;

  /* Fcn: '<S336>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Switch1, rtb_Switch2);

  /* RelationalOperator: '<S339>/Compare' incorporates:
   *  Constant: '<S339>/Constant'
   */
  rtb_Compare_a = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S335>/Switch1' */
  if (rtb_Compare_a) {
    /* Switch: '<S335>/Switch1' incorporates:
     *  Constant: '<S335>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S335>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S335>/Switch1' */

  /* Fcn: '<S321>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S324>/Compare' incorporates:
   *  Constant: '<S324>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S320>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S320>/Switch1' incorporates:
     *  Constant: '<S320>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S320>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S320>/Switch1' */

  /* Fcn: '<S326>/x->r' */
  rtb_Init_g = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S329>/Compare' incorporates:
   *  Constant: '<S329>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Init_g == 0.0);

  /* Switch: '<S325>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S325>/Switch1' incorporates:
     *  Constant: '<S325>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S325>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Init_g;
  }

  /* End of Switch: '<S325>/Switch1' */

  /* Fcn: '<S331>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2_idx_0, rtb_Add2_idx_1);

  /* RelationalOperator: '<S334>/Compare' incorporates:
   *  Constant: '<S334>/Constant'
   */
  rtb_AND1_c = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S330>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S330>/Switch1' incorporates:
     *  Constant: '<S330>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S330>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S330>/Switch1' */

  /* Product: '<S315>/Divide' incorporates:
   *  Abs: '<S315>/Abs'
   *  Abs: '<S315>/Abs1'
   *  Abs: '<S315>/Abs2'
   *  Abs: '<S315>/Abs3'
   *  Constant: '<S315>/Constant'
   *  MinMax: '<S315>/Max'
   */
  rtb_Switch2_p2 = 5.1198378053698752 / fmax(fmax(fmax(fmax(5.1198378053698752,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S315>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S335>/Switch' */
  if (!rtb_Compare_a) {
    /* Switch: '<S335>/Switch' incorporates:
     *  Fcn: '<S336>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Switch2,
      rtb_Switch1);
  }

  /* End of Switch: '<S335>/Switch' */

  /* Trigonometry: '<S271>/Cos4' incorporates:
   *  Switch: '<S260>/Angle_Switch'
   *  Trigonometry: '<S270>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S271>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S269>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S271>/Sin4' incorporates:
   *  Switch: '<S260>/Angle_Switch'
   *  Trigonometry: '<S270>/Sin4'
   */
  rtb_Switch1 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S271>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S269>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S271>/Subtract1' incorporates:
   *  Product: '<S271>/Product2'
   *  Product: '<S271>/Product3'
   *  Trigonometry: '<S271>/Cos4'
   *  Trigonometry: '<S271>/Sin4'
   */
  rtb_Switch2 = (rtb_Add_k * rtb_Optimized_Module_Angle) + (rtb_Switch1 *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S271>/Subtract' incorporates:
   *  Product: '<S271>/Product'
   *  Product: '<S271>/Product1'
   *  Trigonometry: '<S271>/Cos4'
   *  Trigonometry: '<S271>/Sin4'
   */
  rtb_Init = (rtb_Add_k * rtb_Optimized_Module_Angle_p) - (rtb_Switch1 *
    rtb_Optimized_Module_Angle);

  /* Math: '<S271>/Hypot' */
  rtb_Hypot_pi = rt_hypotd_snf(rtb_Init, rtb_Switch2);

  /* Switch: '<S271>/Switch' incorporates:
   *  Constant: '<S271>/Constant'
   *  Constant: '<S271>/Constant1'
   *  Constant: '<S272>/Constant'
   *  Product: '<S271>/Divide'
   *  Product: '<S271>/Divide1'
   *  RelationalOperator: '<S272>/Compare'
   *  Switch: '<S271>/Switch1'
   */
  if (rtb_Hypot_pi > 1.0E-6) {
    rtb_Init_g = rtb_Switch2 / rtb_Hypot_pi;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Hypot_pi;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S271>/Switch' */

  /* Switch: '<S260>/Speed_Switch' incorporates:
   *  Abs: '<S260>/Abs'
   *  Constant: '<S268>/Constant'
   *  RelationalOperator: '<S268>/Compare'
   *  Switch: '<S260>/Angle_Switch'
   *  Trigonometry: '<S270>/Atan1'
   *  Trigonometry: '<S271>/Atan1'
   *  UnaryMinus: '<S260>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S270>/Subtract1' incorporates:
     *  Product: '<S270>/Product2'
     *  Product: '<S270>/Product3'
     *  UnaryMinus: '<S260>/Unary Minus'
     */
    rtb_Switch2 = (rtb_Add_k * Robot_Control_ConstB.Sin5_c) + (rtb_Switch1 *
      Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S270>/Subtract' incorporates:
     *  Product: '<S270>/Product'
     *  Product: '<S270>/Product1'
     */
    rtb_Init = (rtb_Add_k * Robot_Control_ConstB.Cos5_b) - (rtb_Switch1 *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S270>/Hypot' */
    rtb_Switch1 = rt_hypotd_snf(rtb_Init, rtb_Switch2);

    /* Switch: '<S270>/Switch1' incorporates:
     *  Constant: '<S270>/Constant'
     *  Constant: '<S270>/Constant1'
     *  Constant: '<S273>/Constant'
     *  Product: '<S270>/Divide'
     *  Product: '<S270>/Divide1'
     *  RelationalOperator: '<S273>/Compare'
     *  Switch: '<S270>/Switch'
     */
    if (rtb_Switch1 > 1.0E-6) {
      rtb_Init /= rtb_Switch1;
      rtb_Switch1 = rtb_Switch2 / rtb_Switch1;
    } else {
      rtb_Init = 1.0;
      rtb_Switch1 = 0.0;
    }

    /* End of Switch: '<S270>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Init);
  } else {
    rtb_Add_bn = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S263>/Product2' incorporates:
   *  Constant: '<S263>/Constant'
   *  Switch: '<S260>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1210.9758620668042;

  /* Signum: '<S258>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S258>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S261>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S262>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S193>/Product' incorporates:
   *  Abs: '<S258>/Abs'
   *  Abs: '<S261>/Abs'
   *  Constant: '<S264>/Constant'
   *  Constant: '<S274>/Constant3'
   *  Constant: '<S274>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S258>/OR'
   *  Lookup_n-D: '<S261>/1-D Lookup Table'
   *  Math: '<S274>/Math Function'
   *  RelationalOperator: '<S258>/Equal1'
   *  RelationalOperator: '<S264>/Compare'
   *  Signum: '<S258>/Sign'
   *  Signum: '<S258>/Sign1'
   *  Sum: '<S261>/Add'
   *  Sum: '<S274>/Add1'
   *  Sum: '<S274>/Add2'
   */
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966, 3.1415926535897931) -
          1.5707963267948966), rtCP_uDLookupTable_bp01Data,
     rtCP_uDLookupTable_tableData, 1U);

  /* Sum: '<S259>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Init = rtb_Init_g - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S266>/Sum1' incorporates:
   *  Constant: '<S259>/Constant2'
   *  Product: '<S266>/Product'
   *  Sum: '<S266>/Sum'
   *  UnitDelay: '<S266>/Unit Delay1'
   */
  rtb_Switch1 = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                 Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S259>/Product' incorporates:
   *  Constant: '<S259>/Constant3'
   */
  rtb_Switch2 = rtb_Switch1 * Drive_Motor_Control_D;

  /* Sum: '<S265>/Diff' incorporates:
   *  UnitDelay: '<S265>/UD'
   *
   * Block description for '<S265>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S265>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S259>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S259>/Add' incorporates:
   *  Gain: '<S259>/Gain'
   *  Gain: '<S259>/Gain1'
   *  Saturate: '<S259>/Saturation'
   */
  rtb_Hypot_pi = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P
    * rtb_Init)) + rtb_Add_bn;

  /* Saturate: '<S259>/Saturation2' incorporates:
   *  Sum: '<S259>/Add1'
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

  /* End of Saturate: '<S259>/Saturation2' */

  /* Switch: '<S320>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S320>/Switch' incorporates:
     *  Fcn: '<S321>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S320>/Switch' */

  /* Trigonometry: '<S208>/Cos4' incorporates:
   *  Switch: '<S197>/Angle_Switch'
   *  Trigonometry: '<S207>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S208>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S206>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S208>/Sin4' incorporates:
   *  Switch: '<S197>/Angle_Switch'
   *  Trigonometry: '<S207>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S208>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S206>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S208>/Subtract1' incorporates:
   *  Product: '<S208>/Product2'
   *  Product: '<S208>/Product3'
   *  Trigonometry: '<S208>/Cos4'
   *  Trigonometry: '<S208>/Sin4'
   */
  rtb_Hypot_pi = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S208>/Subtract' incorporates:
   *  Product: '<S208>/Product'
   *  Product: '<S208>/Product1'
   *  Trigonometry: '<S208>/Cos4'
   *  Trigonometry: '<S208>/Sin4'
   */
  rtb_Init = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S208>/Hypot' */
  rtb_Hypot_fg = rt_hypotd_snf(rtb_Init, rtb_Hypot_pi);

  /* Switch: '<S208>/Switch' incorporates:
   *  Constant: '<S208>/Constant'
   *  Constant: '<S208>/Constant1'
   *  Constant: '<S209>/Constant'
   *  Product: '<S208>/Divide'
   *  Product: '<S208>/Divide1'
   *  RelationalOperator: '<S209>/Compare'
   *  Switch: '<S208>/Switch1'
   */
  if (rtb_Hypot_fg > 1.0E-6) {
    rtb_Init_g = rtb_Hypot_pi / rtb_Hypot_fg;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Hypot_fg;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S208>/Switch' */

  /* Product: '<S315>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S197>/Speed_Switch' incorporates:
   *  Abs: '<S197>/Abs'
   *  Constant: '<S205>/Constant'
   *  RelationalOperator: '<S205>/Compare'
   *  Switch: '<S197>/Angle_Switch'
   *  Trigonometry: '<S207>/Atan1'
   *  Trigonometry: '<S208>/Atan1'
   *  UnaryMinus: '<S197>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S207>/Subtract1' incorporates:
     *  Product: '<S207>/Product2'
     *  Product: '<S207>/Product3'
     *  UnaryMinus: '<S197>/Unary Minus'
     */
    rtb_Hypot_pi = (rtb_Add_k * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S207>/Subtract' incorporates:
     *  Product: '<S207>/Product'
     *  Product: '<S207>/Product1'
     */
    rtb_Hypot_fg = (rtb_Add_k * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S207>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Hypot_fg, rtb_Hypot_pi);

    /* Switch: '<S207>/Switch1' incorporates:
     *  Constant: '<S207>/Constant'
     *  Constant: '<S207>/Constant1'
     *  Constant: '<S210>/Constant'
     *  Product: '<S207>/Divide'
     *  Product: '<S207>/Divide1'
     *  RelationalOperator: '<S210>/Compare'
     *  Switch: '<S207>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Hypot_fg /= rtb_Init;
      rtb_Hypot_pi /= rtb_Init;
    } else {
      rtb_Hypot_fg = 1.0;
      rtb_Hypot_pi = 0.0;
    }

    /* End of Switch: '<S207>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Hypot_pi, rtb_Hypot_fg);
  } else {
    rtb_Add_bn = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S200>/Product2' incorporates:
   *  Constant: '<S200>/Constant'
   *  Switch: '<S197>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1210.9758620668042;

  /* Signum: '<S195>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S195>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S198>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S199>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S190>/Product' incorporates:
   *  Abs: '<S195>/Abs'
   *  Abs: '<S198>/Abs'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S211>/Constant3'
   *  Constant: '<S211>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S195>/OR'
   *  Lookup_n-D: '<S198>/1-D Lookup Table'
   *  Math: '<S211>/Math Function'
   *  RelationalOperator: '<S195>/Equal1'
   *  RelationalOperator: '<S201>/Compare'
   *  Signum: '<S195>/Sign'
   *  Signum: '<S195>/Sign1'
   *  Sum: '<S198>/Add'
   *  Sum: '<S211>/Add1'
   *  Sum: '<S211>/Add2'
   */
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S196>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_fg = rtb_Init_g - Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S203>/Sum1' incorporates:
   *  Constant: '<S196>/Constant2'
   *  Product: '<S203>/Product'
   *  Sum: '<S203>/Sum'
   *  UnitDelay: '<S203>/Unit Delay1'
   */
  rtb_Hypot_pi = ((rtb_Hypot_fg - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S196>/Product' incorporates:
   *  Constant: '<S196>/Constant3'
   */
  rtb_Init = rtb_Hypot_pi * Drive_Motor_Control_D;

  /* Sum: '<S202>/Diff' incorporates:
   *  UnitDelay: '<S202>/UD'
   *
   * Block description for '<S202>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S202>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Init - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S196>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S196>/Add' incorporates:
   *  Gain: '<S196>/Gain'
   *  Gain: '<S196>/Gain1'
   *  Saturate: '<S196>/Saturation'
   */
  rtb_Hypot_fg = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P
    * rtb_Hypot_fg)) + rtb_Add_bn;

  /* Saturate: '<S196>/Saturation2' incorporates:
   *  Sum: '<S196>/Add1'
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

  /* End of Saturate: '<S196>/Saturation2' */

  /* Sum: '<S212>/Add1' incorporates:
   *  Constant: '<S212>/Constant3'
   *  Constant: '<S212>/Constant4'
   *  Math: '<S212>/Math Function'
   *  Sum: '<S212>/Add2'
   */
  rtb_Init_g = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S214>/Sum1' incorporates:
   *  Constant: '<S199>/Constant2'
   *  Product: '<S214>/Product'
   *  Sum: '<S214>/Sum'
   *  UnitDelay: '<S214>/Unit Delay1'
   */
  rtb_Hypot_fg = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S199>/Product' incorporates:
   *  Constant: '<S199>/Constant3'
   */
  rtb_Switch2_dp = rtb_Hypot_fg * Steering_Motor_Control_D;

  /* Sum: '<S213>/Diff' incorporates:
   *  UnitDelay: '<S213>/UD'
   *
   * Block description for '<S213>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S213>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Switch2_dp - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S199>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S199>/Add' incorporates:
   *  Gain: '<S199>/Gain1'
   *  Saturate: '<S199>/Saturation'
   */
  rtb_Add_fn = (Steering_Motor_Control_P * rtb_Init_g) + rtb_Add_bn;

  /* Sum: '<S199>/Subtract' incorporates:
   *  Constant: '<S199>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_fn;

  /* Sum: '<S199>/Sum2' incorporates:
   *  Gain: '<S199>/Gain2'
   *  UnitDelay: '<S199>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Init_g) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S215>/Switch2' incorporates:
   *  Constant: '<S199>/Constant'
   *  RelationalOperator: '<S215>/LowerRelop1'
   *  Sum: '<S199>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_fn))) {
    /* Switch: '<S215>/Switch' incorporates:
     *  Constant: '<S199>/Constant1'
     *  RelationalOperator: '<S215>/UpperRelop'
     *  Sum: '<S199>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_fn)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_fn;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S215>/Switch' */
  }

  /* End of Switch: '<S215>/Switch2' */

  /* Saturate: '<S199>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S199>/Saturation1' */

  /* Sum: '<S199>/Add1' */
  rtb_Add_bn = rtb_Add_fn + rtb_Sum2_e;

  /* Saturate: '<S199>/Saturation2' */
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

  /* End of Saturate: '<S199>/Saturation2' */

  /* Switch: '<S325>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S325>/Switch' incorporates:
     *  Fcn: '<S326>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S325>/Switch' */

  /* Trigonometry: '<S229>/Cos4' incorporates:
   *  Switch: '<S218>/Angle_Switch'
   *  Trigonometry: '<S228>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S229>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S227>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S229>/Sin4' incorporates:
   *  Switch: '<S218>/Angle_Switch'
   *  Trigonometry: '<S228>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S229>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S227>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S229>/Subtract1' incorporates:
   *  Product: '<S229>/Product2'
   *  Product: '<S229>/Product3'
   *  Trigonometry: '<S229>/Cos4'
   *  Trigonometry: '<S229>/Sin4'
   */
  rtb_Add_fn = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S229>/Subtract' incorporates:
   *  Product: '<S229>/Product'
   *  Product: '<S229>/Product1'
   *  Trigonometry: '<S229>/Cos4'
   *  Trigonometry: '<S229>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S229>/Hypot' */
  rtb_uDLookupTable = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_fn);

  /* Switch: '<S229>/Switch' incorporates:
   *  Constant: '<S229>/Constant'
   *  Constant: '<S229>/Constant1'
   *  Constant: '<S230>/Constant'
   *  Product: '<S229>/Divide'
   *  Product: '<S229>/Divide1'
   *  RelationalOperator: '<S230>/Compare'
   *  Switch: '<S229>/Switch1'
   */
  if (rtb_uDLookupTable > 1.0E-6) {
    rtb_Init_g = rtb_Add_fn / rtb_uDLookupTable;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_uDLookupTable;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S229>/Switch' */

  /* Product: '<S315>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S218>/Speed_Switch' incorporates:
   *  Abs: '<S218>/Abs'
   *  Constant: '<S226>/Constant'
   *  RelationalOperator: '<S226>/Compare'
   *  Switch: '<S218>/Angle_Switch'
   *  Trigonometry: '<S228>/Atan1'
   *  Trigonometry: '<S229>/Atan1'
   *  UnaryMinus: '<S218>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S228>/Subtract1' incorporates:
     *  Product: '<S228>/Product2'
     *  Product: '<S228>/Product3'
     *  UnaryMinus: '<S218>/Unary Minus'
     */
    rtb_Add_fn = (rtb_Add_k * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S228>/Subtract' incorporates:
     *  Product: '<S228>/Product'
     *  Product: '<S228>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_k * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S228>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_uDLookupTable, rtb_Add_fn);

    /* Switch: '<S228>/Switch1' incorporates:
     *  Constant: '<S228>/Constant'
     *  Constant: '<S228>/Constant1'
     *  Constant: '<S231>/Constant'
     *  Product: '<S228>/Divide'
     *  Product: '<S228>/Divide1'
     *  RelationalOperator: '<S231>/Compare'
     *  Switch: '<S228>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Subtract1_la;
      rtb_Add_fn /= rtb_Subtract1_la;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Add_fn = 0.0;
    }

    /* End of Switch: '<S228>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_fn, rtb_uDLookupTable);
  } else {
    rtb_Add_bn = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S221>/Product2' incorporates:
   *  Constant: '<S221>/Constant'
   *  Switch: '<S218>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1210.9758620668042;

  /* Signum: '<S216>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S216>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S219>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S220>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S191>/Product' incorporates:
   *  Abs: '<S216>/Abs'
   *  Abs: '<S219>/Abs'
   *  Constant: '<S222>/Constant'
   *  Constant: '<S232>/Constant3'
   *  Constant: '<S232>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S216>/OR'
   *  Lookup_n-D: '<S219>/1-D Lookup Table'
   *  Math: '<S232>/Math Function'
   *  RelationalOperator: '<S216>/Equal1'
   *  RelationalOperator: '<S222>/Compare'
   *  Signum: '<S216>/Sign'
   *  Signum: '<S216>/Sign1'
   *  Sum: '<S219>/Add'
   *  Sum: '<S232>/Add1'
   *  Sum: '<S232>/Add2'
   */
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S217>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_uDLookupTable = rtb_Init_g - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S224>/Sum1' incorporates:
   *  Constant: '<S217>/Constant2'
   *  Product: '<S224>/Product'
   *  Sum: '<S224>/Sum'
   *  UnitDelay: '<S224>/Unit Delay1'
   */
  rtb_Add_fn = ((rtb_uDLookupTable - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S217>/Product' incorporates:
   *  Constant: '<S217>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_fn * Drive_Motor_Control_D;

  /* Sum: '<S223>/Diff' incorporates:
   *  UnitDelay: '<S223>/UD'
   *
   * Block description for '<S223>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S223>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S217>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S217>/Add' incorporates:
   *  Gain: '<S217>/Gain'
   *  Gain: '<S217>/Gain1'
   *  Saturate: '<S217>/Saturation'
   */
  rtb_Init_g = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P *
    rtb_uDLookupTable)) + rtb_Add_bn;

  /* Saturate: '<S217>/Saturation2' incorporates:
   *  Sum: '<S217>/Add1'
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

  /* End of Saturate: '<S217>/Saturation2' */

  /* Sum: '<S233>/Add1' incorporates:
   *  Constant: '<S233>/Constant3'
   *  Constant: '<S233>/Constant4'
   *  Math: '<S233>/Math Function'
   *  Sum: '<S233>/Add2'
   */
  rtb_Init_g = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S235>/Sum1' incorporates:
   *  Constant: '<S220>/Constant2'
   *  Product: '<S235>/Product'
   *  Sum: '<S235>/Sum'
   *  UnitDelay: '<S235>/Unit Delay1'
   */
  rtb_Switch2_m = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                   Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S220>/Product' incorporates:
   *  Constant: '<S220>/Constant3'
   */
  rtb_Product_hi = rtb_Switch2_m * Steering_Motor_Control_D;

  /* Sum: '<S234>/Diff' incorporates:
   *  UnitDelay: '<S234>/UD'
   *
   * Block description for '<S234>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S234>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Product_hi - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S220>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S220>/Add' incorporates:
   *  Gain: '<S220>/Gain1'
   *  Saturate: '<S220>/Saturation'
   */
  rtb_Add_k = (Steering_Motor_Control_P * rtb_Init_g) + rtb_Add_bn;

  /* Sum: '<S220>/Subtract' incorporates:
   *  Constant: '<S220>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_k;

  /* Sum: '<S220>/Sum2' incorporates:
   *  Gain: '<S220>/Gain2'
   *  UnitDelay: '<S220>/Unit Delay'
   */
  rtb_Init_g = (Steering_Motor_Control_I * rtb_Init_g) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S236>/Switch2' incorporates:
   *  Constant: '<S220>/Constant'
   *  RelationalOperator: '<S236>/LowerRelop1'
   *  Sum: '<S220>/Subtract'
   */
  if (!(rtb_Init_g > (1.0 - rtb_Add_k))) {
    /* Switch: '<S236>/Switch' incorporates:
     *  Constant: '<S220>/Constant1'
     *  RelationalOperator: '<S236>/UpperRelop'
     *  Sum: '<S220>/Subtract1'
     */
    if (rtb_Init_g < (-1.0 - rtb_Add_k)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_k;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Init_g;
    }

    /* End of Switch: '<S236>/Switch' */
  }

  /* End of Switch: '<S236>/Switch2' */

  /* Saturate: '<S220>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S220>/Saturation1' */

  /* Sum: '<S220>/Add1' */
  rtb_Add_bn = rtb_Add_k + rtb_Subtract1_kg;

  /* Saturate: '<S220>/Saturation2' */
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

  /* End of Saturate: '<S220>/Saturation2' */

  /* Switch: '<S330>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S330>/Switch' incorporates:
     *  Fcn: '<S331>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2_idx_1,
      rtb_Add2_idx_0);
  }

  /* End of Switch: '<S330>/Switch' */

  /* Trigonometry: '<S250>/Cos4' incorporates:
   *  Switch: '<S239>/Angle_Switch'
   *  Trigonometry: '<S249>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S250>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S248>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S250>/Sin4' incorporates:
   *  Switch: '<S239>/Angle_Switch'
   *  Trigonometry: '<S249>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S250>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S248>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S250>/Subtract1' incorporates:
   *  Product: '<S250>/Product2'
   *  Product: '<S250>/Product3'
   *  Trigonometry: '<S250>/Cos4'
   *  Trigonometry: '<S250>/Sin4'
   */
  rtb_Init_g = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S250>/Subtract' incorporates:
   *  Product: '<S250>/Product'
   *  Product: '<S250>/Product1'
   *  Trigonometry: '<S250>/Cos4'
   *  Trigonometry: '<S250>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S250>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Init_g);

  /* Switch: '<S250>/Switch' incorporates:
   *  Constant: '<S250>/Constant'
   *  Constant: '<S250>/Constant1'
   *  Constant: '<S251>/Constant'
   *  Product: '<S250>/Divide'
   *  Product: '<S250>/Divide1'
   *  RelationalOperator: '<S251>/Compare'
   *  Switch: '<S250>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Init_g /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S250>/Switch' */

  /* Product: '<S315>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S239>/Speed_Switch' incorporates:
   *  Abs: '<S239>/Abs'
   *  Constant: '<S247>/Constant'
   *  RelationalOperator: '<S247>/Compare'
   *  Switch: '<S239>/Angle_Switch'
   *  Trigonometry: '<S249>/Atan1'
   *  Trigonometry: '<S250>/Atan1'
   *  UnaryMinus: '<S239>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S249>/Subtract1' incorporates:
     *  Product: '<S249>/Product2'
     *  Product: '<S249>/Product3'
     *  UnaryMinus: '<S239>/Unary Minus'
     */
    rtb_Init_g = (rtb_Add_k * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S249>/Subtract' incorporates:
     *  Product: '<S249>/Product'
     *  Product: '<S249>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_k * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S249>/Hypot' */
    rtb_Add_k = rt_hypotd_snf(rtb_uDLookupTable, rtb_Init_g);

    /* Switch: '<S249>/Switch1' incorporates:
     *  Constant: '<S249>/Constant'
     *  Constant: '<S249>/Constant1'
     *  Constant: '<S252>/Constant'
     *  Product: '<S249>/Divide'
     *  Product: '<S249>/Divide1'
     *  RelationalOperator: '<S252>/Compare'
     *  Switch: '<S249>/Switch'
     */
    if (rtb_Add_k > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Add_k;
      rtb_Init_g /= rtb_Add_k;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Init_g = 0.0;
    }

    /* End of Switch: '<S249>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Init_g, rtb_uDLookupTable);
  } else {
    rtb_Add_bn = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S242>/Product2' incorporates:
   *  Constant: '<S242>/Constant'
   *  Switch: '<S239>/Speed_Switch'
   */
  rtb_Switch2_p2 = rtb_Add_bn * 1210.9758620668042;

  /* Signum: '<S237>/Sign' */
  if (rtIsNaN(rtb_Switch2_p2)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Switch2_p2 < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Switch2_p2 > 0.0);
  }

  /* Signum: '<S237>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S240>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S241>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S192>/Product' incorporates:
   *  Abs: '<S237>/Abs'
   *  Abs: '<S240>/Abs'
   *  Constant: '<S243>/Constant'
   *  Constant: '<S253>/Constant3'
   *  Constant: '<S253>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S237>/OR'
   *  Lookup_n-D: '<S240>/1-D Lookup Table'
   *  Math: '<S253>/Math Function'
   *  RelationalOperator: '<S237>/Equal1'
   *  RelationalOperator: '<S243>/Compare'
   *  Signum: '<S237>/Sign'
   *  Signum: '<S237>/Sign1'
   *  Sum: '<S240>/Add'
   *  Sum: '<S253>/Add1'
   *  Sum: '<S253>/Add2'
   */
  rtb_Switch2_p2 = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p2) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Sum: '<S238>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Init_g = rtb_Switch2_p2 - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S245>/Sum1' incorporates:
   *  Constant: '<S238>/Constant2'
   *  Product: '<S245>/Product'
   *  Sum: '<S245>/Sum'
   *  UnitDelay: '<S245>/Unit Delay1'
   */
  rtb_Add_k = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S238>/Product' incorporates:
   *  Constant: '<S238>/Constant3'
   */
  rtb_uDLookupTable = rtb_Add_k * Drive_Motor_Control_D;

  /* Sum: '<S244>/Diff' incorporates:
   *  UnitDelay: '<S244>/UD'
   *
   * Block description for '<S244>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S244>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S238>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S238>/Add' incorporates:
   *  Gain: '<S238>/Gain'
   *  Gain: '<S238>/Gain1'
   *  Saturate: '<S238>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_p2) +
                    (Drive_Motor_Control_P * rtb_Init_g)) + rtb_Add_bn;

  /* Saturate: '<S238>/Saturation2' incorporates:
   *  Sum: '<S238>/Add1'
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

  /* End of Saturate: '<S238>/Saturation2' */

  /* Sum: '<S254>/Add1' incorporates:
   *  Constant: '<S254>/Constant3'
   *  Constant: '<S254>/Constant4'
   *  Math: '<S254>/Math Function'
   *  Sum: '<S254>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S256>/Sum1' incorporates:
   *  Constant: '<S241>/Constant2'
   *  Product: '<S256>/Product'
   *  Sum: '<S256>/Sum'
   *  UnitDelay: '<S256>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S241>/Product' incorporates:
   *  Constant: '<S241>/Constant3'
   */
  rtb_Add2_idx_0 = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S255>/Diff' incorporates:
   *  UnitDelay: '<S255>/UD'
   *
   * Block description for '<S255>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S255>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Add2_idx_0 - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S241>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S241>/Add' incorporates:
   *  Gain: '<S241>/Gain1'
   *  Saturate: '<S241>/Saturation'
   */
  rtb_Add2_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_bn;

  /* Sum: '<S241>/Subtract' incorporates:
   *  Constant: '<S241>/Constant'
   */
  rtb_Init_g = 1.0 - rtb_Add2_idx_1;

  /* Sum: '<S241>/Sum2' incorporates:
   *  Gain: '<S241>/Gain2'
   *  UnitDelay: '<S241>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S257>/Switch2' incorporates:
   *  Constant: '<S241>/Constant'
   *  RelationalOperator: '<S257>/LowerRelop1'
   *  Sum: '<S241>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add2_idx_1))) {
    /* Sum: '<S241>/Subtract1' incorporates:
     *  Constant: '<S241>/Constant1'
     */
    rtb_Init_g = -1.0 - rtb_Add2_idx_1;

    /* Switch: '<S257>/Switch' incorporates:
     *  Constant: '<S241>/Constant1'
     *  RelationalOperator: '<S257>/UpperRelop'
     *  Sum: '<S241>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add2_idx_1))) {
      rtb_Init_g = rtb_Switch2_p2;
    }

    /* End of Switch: '<S257>/Switch' */
  }

  /* End of Switch: '<S257>/Switch2' */

  /* Saturate: '<S241>/Saturation1' */
  if (rtb_Init_g > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Init_g < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Init_g;
  }

  /* End of Saturate: '<S241>/Saturation1' */

  /* Sum: '<S241>/Add1' */
  rtb_Add_bn = rtb_Add2_idx_1 + rtb_Integral_ga;

  /* Saturate: '<S241>/Saturation2' */
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

  /* End of Saturate: '<S241>/Saturation2' */

  /* Sum: '<S275>/Add1' incorporates:
   *  Constant: '<S275>/Constant3'
   *  Constant: '<S275>/Constant4'
   *  Math: '<S275>/Math Function'
   *  Sum: '<S275>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S277>/Sum1' incorporates:
   *  Constant: '<S262>/Constant2'
   *  Product: '<S277>/Product'
   *  Sum: '<S277>/Sum'
   *  UnitDelay: '<S277>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S262>/Product' incorporates:
   *  Constant: '<S262>/Constant3'
   */
  rtb_Add2_idx_1 = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S276>/Diff' incorporates:
   *  UnitDelay: '<S276>/UD'
   *
   * Block description for '<S276>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S276>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Add2_idx_1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S262>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S262>/Add' incorporates:
   *  Gain: '<S262>/Gain1'
   *  Saturate: '<S262>/Saturation'
   */
  rtb_Add_jp = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_bn;

  /* Sum: '<S262>/Subtract' incorporates:
   *  Constant: '<S262>/Constant'
   */
  rtb_Init_g = 1.0 - rtb_Add_jp;

  /* Sum: '<S262>/Sum2' incorporates:
   *  Gain: '<S262>/Gain2'
   *  UnitDelay: '<S262>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S278>/Switch2' incorporates:
   *  Constant: '<S262>/Constant'
   *  RelationalOperator: '<S278>/LowerRelop1'
   *  Sum: '<S262>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_jp))) {
    /* Sum: '<S262>/Subtract1' incorporates:
     *  Constant: '<S262>/Constant1'
     */
    rtb_Init_g = -1.0 - rtb_Add_jp;

    /* Switch: '<S278>/Switch' incorporates:
     *  Constant: '<S262>/Constant1'
     *  RelationalOperator: '<S278>/UpperRelop'
     *  Sum: '<S262>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_jp))) {
      rtb_Init_g = rtb_Switch2_p2;
    }

    /* End of Switch: '<S278>/Switch' */
  }

  /* End of Switch: '<S278>/Switch2' */

  /* Saturate: '<S262>/Saturation1' */
  if (rtb_Init_g > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Init_g < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Init_g;
  }

  /* End of Saturate: '<S262>/Saturation1' */

  /* Sum: '<S262>/Add1' */
  rtb_Add_bn = rtb_Add_jp + rtb_Integral_bj;

  /* Saturate: '<S262>/Saturation2' */
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

  /* End of Saturate: '<S262>/Saturation2' */

  /* Sum: '<S125>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S91>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S127>/Sum1' incorporates:
   *  Constant: '<S125>/Constant2'
   *  Product: '<S127>/Product'
   *  Sum: '<S125>/Sum'
   *  Sum: '<S127>/Sum'
   *  UnitDelay: '<S127>/Unit Delay1'
   */
  rtb_Add_jp = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S125>/Product' incorporates:
   *  Constant: '<S125>/Constant3'
   */
  rtb_Product_lo = rtb_Add_jp * Transfer_Motor_Gain_D;

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
  rtb_Add_bn = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

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
  rtb_Switch2_p2 = ((Transfer_Motor_Gain_FF *
                     Robot_Control_B.Desired_Transfer_Speed) +
                    (Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_bn;

  /* Logic: '<S91>/Logical Operator1' incorporates:
   *  Constant: '<S124>/Constant'
   *  RelationalOperator: '<S124>/Compare'
   */
  rtb_Is_Absolute_Steering = !(Robot_Control_B.Desired_Transfer_Speed == 0.0);

  /* Switch: '<S91>/Switch1' incorporates:
   *  Abs: '<S91>/Abs'
   *  Constant: '<S91>/Constant1'
   *  Constant: '<S91>/Constant2'
   *  Logic: '<S91>/Logical Operator'
   *  Logic: '<S91>/Logical Operator1'
   *  RelationalOperator: '<S91>/LessThan'
   *  UnitDelay: '<S91>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Transfer_Error_Integral_Enable) &&
      rtb_Is_Absolute_Steering) {
    rtb_Is_Absolute_Translation_g = true;
  } else {
    rtb_Is_Absolute_Translation_g = (rtb_Is_Absolute_Steering &&
      (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S91>/Switch1' */

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Constant4'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* Sum: '<S125>/Sum2' incorporates:
     *  Gain: '<S125>/Gain2'
     *  Sum: '<S125>/Sum'
     *  UnitDelay: '<S125>/Unit Delay'
     */
    rtb_Init_g = (Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S125>/Subtract' incorporates:
     *  Constant: '<S125>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Switch2_p2;

    /* Switch: '<S128>/Switch2' incorporates:
     *  Constant: '<S125>/Constant'
     *  RelationalOperator: '<S128>/LowerRelop1'
     *  Sum: '<S125>/Subtract'
     */
    if (!(rtb_Init_g > (1.0 - rtb_Switch2_p2))) {
      /* Sum: '<S125>/Subtract1' incorporates:
       *  Constant: '<S125>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Switch2_p2;

      /* Switch: '<S128>/Switch' incorporates:
       *  Constant: '<S125>/Constant1'
       *  RelationalOperator: '<S128>/UpperRelop'
       *  Sum: '<S125>/Subtract1'
       */
      if (!(rtb_Init_g < (-1.0 - rtb_Switch2_p2))) {
        rtb_Integral_d = rtb_Init_g;
      }

      /* End of Switch: '<S128>/Switch' */
    }

    /* End of Switch: '<S128>/Switch2' */

    /* Saturate: '<S125>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S125>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S125>/Switch' */

  /* Sum: '<S125>/Add1' */
  rtb_Add_bn = rtb_Switch2_p2 + rtb_Integral_d;

  /* Saturate: '<S125>/Saturation2' */
  if (rtb_Add_bn > 1.0) {
    /* Saturate: '<S125>/Saturation2' */
    Robot_Control_B.Transfer_Motor_PID_DC = 1.0;
  } else if (rtb_Add_bn < -1.0) {
    /* Saturate: '<S125>/Saturation2' */
    Robot_Control_B.Transfer_Motor_PID_DC = -1.0;
  } else {
    /* Saturate: '<S125>/Saturation2' */
    Robot_Control_B.Transfer_Motor_PID_DC = rtb_Add_bn;
  }

  /* End of Saturate: '<S125>/Saturation2' */

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant'
   */
  Robot_Control_B.Feeder_Motor_PID_DC = Robot_Control_B.Desired_Feeder_Speed *
    Feeder_Motor_Gain_FF;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant6'
   *  Switch: '<S8>/Switch1'
   *  Switch: '<S8>/Switch5'
   *  Switch: '<S8>/Switch6'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Transfer_Motor_DC' incorporates:
     *  Constant: '<S8>/Constant1'
     */
    Robot_Control_Y.Transfer_Motor_DC = TEST_Transfer_Motor_DC_OV;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S8>/Constant7'
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     */
    Robot_Control_Y.Desired_Hood_Enable = (TEST_Desired_Hood_Enable_OV != 0.0);

    /* Outport: '<Root>/Feeder_Motor_DC' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    Robot_Control_Y.Feeder_Motor_DC = TEST_Feeder_Motor_DC_OV;
    rtb_Switch2_p2 = TEST_Desired_Hood_Pos_OV;
  } else {
    /* Outport: '<Root>/Transfer_Motor_DC' */
    Robot_Control_Y.Transfer_Motor_DC = Robot_Control_B.Transfer_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S8>/Constant8'
     */
    Robot_Control_Y.Desired_Hood_Enable = true;

    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.Feeder_Motor_PID_DC;
    rtb_Switch2_p2 = Robot_Control_B.Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Switch: '<S8>/Switch5'
   */
  if (rtb_Switch2_p2 > Hood_Servo_Pos_Max) {
    rtb_Switch2_p2 = Hood_Servo_Pos_Max;
  } else if (rtb_Switch2_p2 < Hood_Servo_Pos_Min) {
    rtb_Switch2_p2 = Hood_Servo_Pos_Min;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Outport: '<Root>/Desired_Hood_Pos' */
  Robot_Control_Y.Desired_Hood_Pos = rtb_Switch2_p2;

  /* Switch: '<S83>/Init' incorporates:
   *  UnitDelay: '<S83>/FixPt Unit Delay1'
   *  UnitDelay: '<S83>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Init_g = rtb_Switch2_p2;
  } else {
    rtb_Init_g = Robot_Control_B.Estimated_Hood_Pos;
  }

  /* End of Switch: '<S83>/Init' */

  /* Sum: '<S81>/Sum1' */
  rtb_Switch2_p2 -= rtb_Init_g;

  /* Switch: '<S82>/Switch2' incorporates:
   *  Constant: '<S80>/Constant1'
   *  Constant: '<S80>/Constant3'
   *  RelationalOperator: '<S82>/LowerRelop1'
   *  RelationalOperator: '<S82>/UpperRelop'
   *  Switch: '<S82>/Switch'
   */
  if (rtb_Switch2_p2 > Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch2_p2 = Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch2_p2 < Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S82>/Switch' incorporates:
     *  Constant: '<S80>/Constant1'
     */
    rtb_Switch2_p2 = Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S82>/Switch2' */

  /* Sum: '<S81>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Switch2_p2 + rtb_Init_g;

  /* Sum: '<S120>/Sum' incorporates:
   *  Sum: '<S88>/Subtract'
   */
  rtb_Error_d = Robot_Control_B.Desired_Shooter_Speed -
    Robot_Control_B.Measured_Shooter_Speed_Max;

  /* Sum: '<S122>/Sum1' incorporates:
   *  Constant: '<S120>/Constant2'
   *  Product: '<S122>/Product'
   *  Sum: '<S120>/Sum'
   *  Sum: '<S122>/Sum'
   *  UnitDelay: '<S122>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_Error_d - Robot_Control_DW.UnitDelay1_DSTATE_d) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_d;

  /* Product: '<S120>/Product' incorporates:
   *  Constant: '<S120>/Constant3'
   */
  rtb_Init_g = rtb_Switch2_p2 * Shooter_Motor_Gain_D;

  /* Sum: '<S121>/Diff' incorporates:
   *  UnitDelay: '<S121>/UD'
   *
   * Block description for '<S121>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S121>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Init_g - Robot_Control_DW.UD_DSTATE_ml;

  /* Saturate: '<S120>/Saturation' */
  if (rtb_Add_bn > 0.1) {
    rtb_Add_bn = 0.1;
  } else if (rtb_Add_bn < -0.1) {
    rtb_Add_bn = -0.1;
  }

  /* Sum: '<S120>/Add' incorporates:
   *  Gain: '<S120>/Gain'
   *  Gain: '<S120>/Gain1'
   *  Saturate: '<S120>/Saturation'
   *  Sum: '<S120>/Sum'
   */
  rtb_Add_bn += (Shooter_Motor_Gain_FF * Robot_Control_B.Desired_Shooter_Speed)
    + (Shooter_Motor_Gain_P * rtb_Error_d);

  /* Logic: '<S88>/Logical Operator1' incorporates:
   *  Constant: '<S119>/Constant'
   *  RelationalOperator: '<S119>/Compare'
   */
  rtb_Is_Absolute_Steering = !(Robot_Control_B.Desired_Shooter_Speed == 0.0);

  /* Switch: '<S88>/Switch1' incorporates:
   *  Abs: '<S88>/Abs'
   *  Constant: '<S88>/Constant1'
   *  Constant: '<S88>/Constant2'
   *  Logic: '<S88>/Logical Operator'
   *  Logic: '<S88>/Logical Operator1'
   *  RelationalOperator: '<S88>/LessThan'
   *  UnitDelay: '<S88>/Unit Delay'
   */
  if ((fabs(rtb_Error_d) < Shooter_Error_Integral_Enable) &&
      rtb_Is_Absolute_Steering) {
    rtb_Is_Absolute_Steering = true;
  } else {
    rtb_Is_Absolute_Steering = (rtb_Is_Absolute_Steering &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S88>/Switch1' */

  /* Switch: '<S120>/Switch' incorporates:
   *  Constant: '<S120>/Constant4'
   */
  if (rtb_Is_Absolute_Steering) {
    /* Sum: '<S120>/Sum2' incorporates:
     *  Gain: '<S120>/Gain2'
     *  Sum: '<S120>/Sum'
     *  UnitDelay: '<S120>/Unit Delay'
     */
    rtb_Error_d = (Shooter_Motor_Gain_I * rtb_Error_d) +
      Robot_Control_DW.UnitDelay_DSTATE_di;

    /* Sum: '<S120>/Subtract' incorporates:
     *  Constant: '<S120>/Constant'
     */
    rtb_Switch2_f = 1.0 - rtb_Add_bn;

    /* Switch: '<S123>/Switch2' incorporates:
     *  Constant: '<S120>/Constant'
     *  RelationalOperator: '<S123>/LowerRelop1'
     *  Sum: '<S120>/Subtract'
     */
    if (!(rtb_Error_d > (1.0 - rtb_Add_bn))) {
      /* Sum: '<S120>/Subtract1' incorporates:
       *  Constant: '<S120>/Constant1'
       */
      rtb_Switch2_f = -1.0 - rtb_Add_bn;

      /* Switch: '<S123>/Switch' incorporates:
       *  Constant: '<S120>/Constant1'
       *  RelationalOperator: '<S123>/UpperRelop'
       *  Sum: '<S120>/Subtract1'
       */
      if (!(rtb_Error_d < (-1.0 - rtb_Add_bn))) {
        rtb_Switch2_f = rtb_Error_d;
      }

      /* End of Switch: '<S123>/Switch' */
    }

    /* End of Switch: '<S123>/Switch2' */

    /* Saturate: '<S120>/Saturation1' */
    if (rtb_Switch2_f > 0.1) {
      rtb_Error_d = 0.1;
    } else if (rtb_Switch2_f < -0.1) {
      rtb_Error_d = -0.1;
    } else {
      rtb_Error_d = rtb_Switch2_f;
    }

    /* End of Saturate: '<S120>/Saturation1' */
  } else {
    rtb_Error_d = 0.0;
  }

  /* End of Switch: '<S120>/Switch' */

  /* Sum: '<S120>/Add1' */
  rtb_Add_bn += rtb_Error_d;

  /* Saturate: '<S120>/Saturation2' */
  if (rtb_Add_bn > 1.0) {
    /* Saturate: '<S120>/Saturation2' */
    Robot_Control_B.Shooter_Motor_PID_DC = 1.0;
  } else if (rtb_Add_bn < -1.0) {
    /* Saturate: '<S120>/Saturation2' */
    Robot_Control_B.Shooter_Motor_PID_DC = -1.0;
  } else {
    /* Saturate: '<S120>/Saturation2' */
    Robot_Control_B.Shooter_Motor_PID_DC = rtb_Add_bn;
  }

  /* End of Saturate: '<S120>/Saturation2' */

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S8>/Constant'
   *  Switch: '<S8>/Switch3'
   *  Switch: '<S8>/Switch4'
   */
  if (TEST_Output_Override_Flag != 0.0) {
    /* Outport: '<Root>/Shooter_Motor_DC_Left' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    Robot_Control_Y.Shooter_Motor_DC_Left = TEST_Shooter_Motor_DC_Left_OV;

    /* Outport: '<Root>/Shooter_Motor_DC_Center' incorporates:
     *  Constant: '<S8>/Constant4'
     */
    Robot_Control_Y.Shooter_Motor_DC_Center = TEST_Shooter_Motor_DC_Center_OV;

    /* Outport: '<Root>/Shooter_Motor_DC_Right' incorporates:
     *  Constant: '<S8>/Constant5'
     */
    Robot_Control_Y.Shooter_Motor_DC_Right = TEST_Shooter_Motor_DC_Right_OV;
  } else {
    /* Outport: '<Root>/Shooter_Motor_DC_Left' */
    Robot_Control_Y.Shooter_Motor_DC_Left = Robot_Control_B.Shooter_Motor_PID_DC;

    /* Outport: '<Root>/Shooter_Motor_DC_Center' */
    Robot_Control_Y.Shooter_Motor_DC_Center =
      Robot_Control_B.Shooter_Motor_PID_DC;

    /* Outport: '<Root>/Shooter_Motor_DC_Right' */
    Robot_Control_Y.Shooter_Motor_DC_Right =
      Robot_Control_B.Shooter_Motor_PID_DC;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Chart: '<S9>/Chart' */
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

  /* End of Chart: '<S9>/Chart' */

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

  /* SignalConversion: '<S4>/Signal Copy4' incorporates:
   *  Inport: '<Root>/Joystick_Right_X'
   */
  Robot_Control_B.Steer_Joystick_X = Robot_Control_U.Joystick_Right_X;

  /* SignalConversion: '<Root>/Signal Copy' incorporates:
   *  Inport: '<Root>/Measured_Feeder_Speed'
   */
  Robot_Control_B.Feeder_Motor_Speed_tp = Robot_Control_U.Measured_Feeder_Speed;

  /* Update for UnitDelay: '<S23>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Joystick_Left_B11;

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Joystick_Left_B12;

  /* Update for UnitDelay: '<S25>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Joystick_Left_B13;

  /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' incorporates:
   *  Inport: '<Root>/Odom_Delta_X'
   */
  Robot_Control_DW.TappedDelay_X[0] = Robot_Control_DW.TappedDelay_X[1];
  Robot_Control_DW.TappedDelay_X[1] = Robot_Control_U.Odom_Delta_X;

  /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay1' incorporates:
   *  Inport: '<Root>/Odom_Delta_Y'
   */
  Robot_Control_DW.TappedDelay1_X[0] = Robot_Control_DW.TappedDelay1_X[1];
  Robot_Control_DW.TappedDelay1_X[1] = Robot_Control_U.Odom_Delta_Y;

  /* Update for Delay: '<S26>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S46>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S26>/A'
   *  Delay: '<S26>/MemoryX'
   */
  rtb_Add_bn = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Switch2_f = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S26>/MemoryX' incorporates:
   *  Constant: '<S26>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S46>/A[k]*xhat[k|k-1]'
   *  Product: '<S46>/B[k]*u[k]'
   *  Sum: '<S46>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Add_bn) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Switch2_f) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay generated from: '<S10>/Unit Delay' */
  Robot_Control_DW.UnitDelay_1_DSTATE = Robot_Control_B.Desired_Gyro_Angle;

  /* Update for UnitDelay generated from: '<S10>/Unit Delay' */
  Robot_Control_DW.UnitDelay_4_DSTATE = Robot_Control_B.Allowed_Shoot_Gyro_Error;

  /* Update for UnitDelay generated from: '<S10>/Unit Delay' */
  Robot_Control_DW.UnitDelay_2_DSTATE = Robot_Control_B.Desired_Shooter_Speed;

  /* Update for UnitDelay generated from: '<S10>/Unit Delay' */
  Robot_Control_DW.UnitDelay_3_DSTATE = Robot_Control_B.Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S85>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c = Robot_Control_B.Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S290>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S290>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S312>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S311>/UD'
   *
   * Block description for '<S311>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Add_h5;

  /* Update for UnitDelay: '<S309>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Subtract_c3;

  /* Update for UnitDelay: '<S292>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S307>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S307>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S307>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S291>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S300>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S300>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S300>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S266>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S265>/UD'
   *
   * Block description for '<S265>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2;

  /* Update for UnitDelay: '<S259>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l = 0.0;

  /* Update for UnitDelay: '<S203>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Hypot_pi;

  /* Update for UnitDelay: '<S202>/UD'
   *
   * Block description for '<S202>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Init;

  /* Update for UnitDelay: '<S196>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S214>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_fg;

  /* Update for UnitDelay: '<S213>/UD'
   *
   * Block description for '<S213>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_dp;

  /* Update for UnitDelay: '<S199>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S224>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_fn;

  /* Update for UnitDelay: '<S223>/UD'
   *
   * Block description for '<S223>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S217>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S235>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Switch2_m;

  /* Update for UnitDelay: '<S234>/UD'
   *
   * Block description for '<S234>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_hi;

  /* Update for UnitDelay: '<S220>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S245>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_k;

  /* Update for UnitDelay: '<S244>/UD'
   *
   * Block description for '<S244>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S238>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S256>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S255>/UD'
   *
   * Block description for '<S255>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Add2_idx_0;

  /* Update for UnitDelay: '<S241>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S277>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S276>/UD'
   *
   * Block description for '<S276>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add2_idx_1;

  /* Update for UnitDelay: '<S262>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S127>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_jp;

  /* Update for UnitDelay: '<S126>/UD'
   *
   * Block description for '<S126>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S125>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S91>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_Is_Absolute_Translation_g;

  /* Update for UnitDelay: '<S83>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S83>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S122>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_d = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S121>/UD'
   *
   * Block description for '<S121>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_ml = rtb_Init_g;

  /* Update for UnitDelay: '<S120>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Error_d;

  /* Update for UnitDelay: '<S88>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_db = rtb_Is_Absolute_Steering;
}

/* Model initialize function */
void Robot_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  Robot_Control_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S11>/If' */
  Robot_Control_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for Delay: '<S26>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S290>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S307>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S300>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S83>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S361>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S11>/Spline Path Following Enabled' */
  /* Start for If: '<S135>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S131>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S135>/Robot_Index_Is_Valid' */
  /* Start for If: '<S138>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S138>/Circle_Check_Valid' */
  /* Start for If: '<S140>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S138>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S135>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S11>/Spline Path Following Enabled' */
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
