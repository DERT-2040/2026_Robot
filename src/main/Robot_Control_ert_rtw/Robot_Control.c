/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.447
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Feb 21 00:05:40 2026
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
real_T BlueAllianceZoneX = 4.6256;     /* Variable: BlueAllianceZoneX
                                        * Referenced by:
                                        *   '<S116>/BlueAllianceZoneX'
                                        *   '<S118>/BlueAllianceZoneX'
                                        */
real_T Blue_Hub_X = 4.6256;            /* Variable: Blue_Hub_X
                                        * Referenced by: '<S101>/Constant'
                                        */
real_T Blue_Hub_Y = 4.0345;            /* Variable: Blue_Hub_Y
                                        * Referenced by: '<S101>/Constant1'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S359>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S355>/Constant'
                                        *   '<S355>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S359>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S355>/Constant1'
                                        */
real_T Dist_Arr_0 = 0.0;               /* Variable: Dist_Arr_0
                                        * Referenced by:
                                        *   '<S98>/Constant5'
                                        *   '<S99>/Constant5'
                                        *   '<S100>/Constant5'
                                        *   '<S103>/Constant5'
                                        */
real_T Dist_Arr_1 = 2.5;               /* Variable: Dist_Arr_1
                                        * Referenced by:
                                        *   '<S98>/Constant6'
                                        *   '<S99>/Constant6'
                                        *   '<S100>/Constant6'
                                        *   '<S103>/Constant6'
                                        */
real_T Dist_Arr_2 = 5.0;               /* Variable: Dist_Arr_2
                                        * Referenced by:
                                        *   '<S98>/Constant7'
                                        *   '<S99>/Constant7'
                                        *   '<S100>/Constant7'
                                        *   '<S103>/Constant7'
                                        */
real_T Dist_Arr_3 = 7.5;               /* Variable: Dist_Arr_3
                                        * Referenced by:
                                        *   '<S98>/Constant8'
                                        *   '<S99>/Constant8'
                                        *   '<S100>/Constant8'
                                        *   '<S103>/Constant8'
                                        */
real_T Dist_Arr_4 = 10.0;              /* Variable: Dist_Arr_4
                                        * Referenced by:
                                        *   '<S98>/Constant9'
                                        *   '<S99>/Constant9'
                                        *   '<S100>/Constant9'
                                        *   '<S103>/Constant9'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S197>/Constant3'
                                        *   '<S218>/Constant3'
                                        *   '<S239>/Constant3'
                                        *   '<S260>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S197>/Constant2'
                                   *   '<S218>/Constant2'
                                   *   '<S239>/Constant2'
                                   *   '<S260>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S197>/Saturation'
                                        *   '<S218>/Saturation'
                                        *   '<S239>/Saturation'
                                        *   '<S260>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S197>/Saturation'
                                        *   '<S218>/Saturation'
                                        *   '<S239>/Saturation'
                                        *   '<S260>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S197>/Gain'
                                            *   '<S218>/Gain'
                                            *   '<S239>/Gain'
                                            *   '<S260>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S197>/Gain2'
                                        *   '<S218>/Gain2'
                                        *   '<S239>/Gain2'
                                        *   '<S260>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S197>/Saturation1'
                                         *   '<S218>/Saturation1'
                                         *   '<S239>/Saturation1'
                                         *   '<S260>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S197>/Saturation1'
                                        *   '<S218>/Saturation1'
                                        *   '<S239>/Saturation1'
                                        *   '<S260>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S197>/Gain1'
                                        *   '<S218>/Gain1'
                                        *   '<S239>/Gain1'
                                        *   '<S260>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S202>/Constant'
                            *   '<S223>/Constant'
                            *   '<S244>/Constant'
                            *   '<S265>/Constant'
                            */
real_T Feeder_Motor_Gain_FF = 0.00012732;/* Variable: Feeder_Motor_Gain_FF
                                          * Referenced by: '<S11>/Constant'
                                          */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S345>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S345>/Constant5'
                                          */
real_T Gyro_Err_Arr_0 = 0.17453;       /* Variable: Gyro_Err_Arr_0
                                        * Referenced by: '<S98>/Constant'
                                        */
real_T Gyro_Err_Arr_1 = 0.087266;      /* Variable: Gyro_Err_Arr_1
                                        * Referenced by: '<S98>/Constant1'
                                        */
real_T Gyro_Err_Arr_2 = 0.05236;       /* Variable: Gyro_Err_Arr_2
                                        * Referenced by: '<S98>/Constant2'
                                        */
real_T Gyro_Err_Arr_3 = 0.017453;      /* Variable: Gyro_Err_Arr_3
                                        * Referenced by: '<S98>/Constant3'
                                        */
real_T Gyro_Err_Arr_4 = 0.0087266;     /* Variable: Gyro_Err_Arr_4
                                        * Referenced by: '<S98>/Constant4'
                                        */
real_T Hood_Pos_Max_Error_Shoot = 0.03;/* Variable: Hood_Pos_Max_Error_Shoot
                                        * Referenced by: '<S88>/Constant1'
                                        */
real_T Hood_Position_0 = 0.8;          /* Variable: Hood_Position_0
                                        * Referenced by: '<S99>/Constant'
                                        */
real_T Hood_Position_1 = 0.6;          /* Variable: Hood_Position_1
                                        * Referenced by: '<S99>/Constant1'
                                        */
real_T Hood_Position_2 = 0.4;          /* Variable: Hood_Position_2
                                        * Referenced by: '<S99>/Constant2'
                                        */
real_T Hood_Position_3 = 0.3;          /* Variable: Hood_Position_3
                                        * Referenced by: '<S99>/Constant3'
                                        */
real_T Hood_Position_4 = 0.2;          /* Variable: Hood_Position_4
                                        * Referenced by: '<S99>/Constant4'
                                        */
real_T Hood_Servo_Pos_Max = 1.0;       /* Variable: Hood_Servo_Pos_Max
                                        * Referenced by: '<S9>/Saturation'
                                        */
real_T Hood_Servo_Pos_Min = 0.05;      /* Variable: Hood_Servo_Pos_Min
                                        * Referenced by: '<S9>/Saturation'
                                        */
real_T Hood_Servo_Rate_Limit_Dec = -0.0128;/* Variable: Hood_Servo_Rate_Limit_Dec
                                            * Referenced by: '<S81>/Constant1'
                                            */
real_T Hood_Servo_Rate_Limit_Inc = 0.0128;/* Variable: Hood_Servo_Rate_Limit_Inc
                                           * Referenced by: '<S81>/Constant3'
                                           */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S7>/Constant1'
                                        *   '<S7>/Constant2'
                                        */
real_T RedAllianceZoneX = 11.9154;     /* Variable: RedAllianceZoneX
                                        * Referenced by:
                                        *   '<S117>/RedAllianceZoneX'
                                        *   '<S119>/RedAllianceZoneX'
                                        */
real_T Red_Hub_X = 11.9154;            /* Variable: Red_Hub_X
                                        * Referenced by: '<S101>/Constant2'
                                        */
real_T Red_Hub_Y = 4.0345;             /* Variable: Red_Hub_Y
                                        * Referenced by: '<S101>/Constant3'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S344>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S342>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S344>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S345>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S345>/Constant8'
                                      */
real_T Robot_Velocity_Maximum_Shooter = 1.0;
                                     /* Variable: Robot_Velocity_Maximum_Shooter
                                      * Referenced by: '<S88>/Constant'
                                      */
real_T Shooter_Error_Integral_Enable = 300.0;
                                      /* Variable: Shooter_Error_Integral_Enable
                                       * Referenced by: '<S89>/Constant1'
                                       */
real_T Shooter_Motor_Gain_D = 0.0;     /* Variable: Shooter_Motor_Gain_D
                                        * Referenced by: '<S121>/Constant3'
                                        */
real_T Shooter_Motor_Gain_FF = 0.00016534;/* Variable: Shooter_Motor_Gain_FF
                                           * Referenced by: '<S121>/Gain'
                                           */
real_T Shooter_Motor_Gain_I = 2.0E-5;  /* Variable: Shooter_Motor_Gain_I
                                        * Referenced by: '<S121>/Gain2'
                                        */
real_T Shooter_Motor_Gain_P = 0.0005;  /* Variable: Shooter_Motor_Gain_P
                                        * Referenced by: '<S121>/Gain1'
                                        */
real_T Shooter_Motor_Max_Error_Shoot = 100.0;
                                      /* Variable: Shooter_Motor_Max_Error_Shoot
                                       * Referenced by: '<S88>/Constant2'
                                       */
real_T Shooter_Spd_0 = 3000.0;         /* Variable: Shooter_Spd_0
                                        * Referenced by: '<S100>/Constant'
                                        */
real_T Shooter_Spd_1 = 3200.0;         /* Variable: Shooter_Spd_1
                                        * Referenced by: '<S100>/Constant1'
                                        */
real_T Shooter_Spd_2 = 3500.0;         /* Variable: Shooter_Spd_2
                                        * Referenced by: '<S100>/Constant2'
                                        */
real_T Shooter_Spd_3 = 3500.0;         /* Variable: Shooter_Spd_3
                                        * Referenced by: '<S100>/Constant3'
                                        */
real_T Shooter_Spd_4 = 3500.0;         /* Variable: Shooter_Spd_4
                                        * Referenced by: '<S100>/Constant4'
                                        */
real_T Shot_Target_Error_Thresh = 0.1; /* Variable: Shot_Target_Error_Thresh
                                        * Referenced by: '<S107>/Constant'
                                        */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S186>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S186>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S133>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S146>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S186>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S293>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S293>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S293>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S293>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S293>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S293>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S310>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S310>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S310>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S310>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S309>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S310>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S310>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S310>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S310>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S310>/Constant1'
                                   *   '<S310>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S310>/Constant'
                                   *   '<S310>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S200>/Constant3'
                                        *   '<S221>/Constant3'
                                        *   '<S242>/Constant3'
                                        *   '<S263>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S200>/Constant2'
                                *   '<S221>/Constant2'
                                *   '<S242>/Constant2'
                                *   '<S263>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S200>/Saturation'
                                           *   '<S221>/Saturation'
                                           *   '<S242>/Saturation'
                                           *   '<S263>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S200>/Saturation'
                                          *   '<S221>/Saturation'
                                          *   '<S242>/Saturation'
                                          *   '<S263>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S200>/Gain2'
                                         *   '<S221>/Gain2'
                                         *   '<S242>/Gain2'
                                         *   '<S263>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S200>/Saturation1'
                                             *   '<S221>/Saturation1'
                                             *   '<S242>/Saturation1'
                                             *   '<S263>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S200>/Saturation1'
                                            *   '<S221>/Saturation1'
                                            *   '<S242>/Saturation1'
                                            *   '<S263>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S200>/Gain1'
                                        *   '<S221>/Gain1'
                                        *   '<S242>/Gain1'
                                        *   '<S263>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S292>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S292>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S292>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S292>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S292>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S292>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S344>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S344>/Constant1'
                                        */
real_T TEST_Desired_Hood_Enable_OV = 0.0;/* Variable: TEST_Desired_Hood_Enable_OV
                                          * Referenced by: '<S9>/Constant7'
                                          */
real_T TEST_Desired_Hood_Pos_OV = 0.5; /* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S9>/Constant6'
                                        */
real_T TEST_Feeder_Motor_DC_OV = 0.0;  /* Variable: TEST_Feeder_Motor_DC_OV
                                        * Referenced by: '<S9>/Constant2'
                                        */
real_T TEST_Output_Override_Flag = 1.0;/* Variable: TEST_Output_Override_Flag
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
                                      * Referenced by: '<S343>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S343>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S343>/Constant7'
                                           */
real_T TEST_Transfer_Motor_DC_OV = 0.0;/* Variable: TEST_Transfer_Motor_DC_OV
                                        * Referenced by: '<S9>/Constant1'
                                        */
real_T TOF_Arr_0 = 2.0;                /* Variable: TOF_Arr_0
                                        * Referenced by: '<S103>/Constant'
                                        */
real_T TOF_Arr_1 = 3.0;                /* Variable: TOF_Arr_1
                                        * Referenced by: '<S103>/Constant1'
                                        */
real_T TOF_Arr_2 = 3.5;                /* Variable: TOF_Arr_2
                                        * Referenced by: '<S103>/Constant2'
                                        */
real_T TOF_Arr_3 = 3.8;                /* Variable: TOF_Arr_3
                                        * Referenced by: '<S103>/Constant3'
                                        */
real_T TOF_Arr_4 = 4.0;                /* Variable: TOF_Arr_4
                                        * Referenced by: '<S103>/Constant4'
                                        */
real_T Target_Feeder_Speed = 2000.0;   /* Variable: Target_Feeder_Speed
                                        * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Target_Transfer_Speed = 2000.0; /* Variable: Target_Transfer_Speed
                                        * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Transfer_Error_Integral_Enable = 300.0;
                                     /* Variable: Transfer_Error_Integral_Enable
                                      * Referenced by: '<S92>/Constant1'
                                      */
real_T Transfer_Minimum_Factor = 0.8;  /* Variable: Transfer_Minimum_Factor
                                        * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                        */
real_T Transfer_Motor_Gain_D = 0.0;    /* Variable: Transfer_Motor_Gain_D
                                        * Referenced by: '<S126>/Constant3'
                                        */
real_T Transfer_Motor_Gain_FF = 0.00012732;/* Variable: Transfer_Motor_Gain_FF
                                            * Referenced by: '<S126>/Gain'
                                            */
real_T Transfer_Motor_Gain_I = 2.0E-5; /* Variable: Transfer_Motor_Gain_I
                                        * Referenced by: '<S126>/Gain2'
                                        */
real_T Transfer_Motor_Gain_P = 0.0001; /* Variable: Transfer_Motor_Gain_P
                                        * Referenced by: '<S126>/Gain1'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S280>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S280>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S280>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S280>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S280>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S280>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S345>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S344>/Dead Zone'
                                        *   '<S345>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S344>/Dead Zone'
                                        *   '<S345>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S16>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S342>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S342>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S342>/Constant4'
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
                                        * Referenced by: '<S342>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S342>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S342>/Constant5'
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
                                        *   '<S342>/Constant11'
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
  /* SignalConversion generated from: '<S108>/IsBlueActive' incorporates:
   *  Constant: '<S108>/Constant'
   */
  *rty_IsBlueActive = true;

  /* SignalConversion generated from: '<S108>/IsRedActive' incorporates:
   *  Constant: '<S108>/Constant'
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
  /* Logic: '<S109>/NOT' incorporates:
   *  SignalConversion generated from: '<S109>/IsBlueInactiveFirst'
   */
  *rty_IsBlueActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S109>/IsRedActive' */
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
  /* Logic: '<S110>/NOT1' incorporates:
   *  SignalConversion generated from: '<S110>/IsBlueInactiveFirst'
   */
  *rty_IsRedActive = !rtu_IsBlueInactiveFirst;

  /* SignalConversion generated from: '<S110>/IsBlueActive' */
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

  /* If: '<S371>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S371>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S374>/Action Port'
     */
    /* Product: '<S374>/Product' incorporates:
     *  Constant: '<S374>/Constant1'
     *  Constant: '<S374>/Constant2'
     *  Math: '<S374>/Math Function'
     */
    rtb_Subtract_c3 = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S371>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S371>/Subsystem' incorporates:
     *  ActionPort: '<S375>/Action Port'
     */
    /* SignalConversion generated from: '<S375>/Out1' incorporates:
     *  Constant: '<S375>/Constant'
     */
    rtb_Subtract_c3 = 0.0;

    /* End of Outputs for SubSystem: '<S371>/Subsystem' */
  }

  /* End of If: '<S371>/If' */

  /* Gain: '<S372>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S16>/Add3' incorporates:
   *  Constant: '<S16>/Constant4'
   *  Fcn: '<S373>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Subtract_c3 * cos(rtb_Sin4))
    + Vision_Object_X_Offset;

  /* Sum: '<S16>/Add4' incorporates:
   *  Constant: '<S16>/Constant8'
   *  Fcn: '<S373>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Subtract_c3 * sin(rtb_Sin4))
    + Vision_Object_Y_Offset;

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
       *  UnitDelay: '<S344>/Unit Delay1'
       *  UnitDelay: '<S344>/Unit Delay2'
       *  UnitDelay: '<S344>/Unit Delay3'
       *  UnitDelay: '<S344>/Unit Delay4'
       *  UnitDelay: '<S347>/Delay Input1'
       *  UnitDelay: '<S348>/Delay Input1'
       *  UnitDelay: '<S349>/Delay Input1'
       *  UnitDelay: '<S350>/Delay Input1'
       *  UnitDelay: '<S352>/Delay Input1'
       *  UnitDelay: '<S358>/Unit Delay'
       *  UnitDelay: '<S358>/Unit Delay1'
       *  UnitDelay: '<S362>/FixPt Unit Delay1'
       *  UnitDelay: '<S362>/FixPt Unit Delay2'
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
       * Block description for '<S350>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S352>/Delay Input1':
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
    /* Switch: '<S342>/Switch4' incorporates:
     *  Constant: '<S367>/Constant'
     *  Constant: '<S370>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S367>/Compare'
     *  RelationalOperator: '<S370>/Compare'
     *  Switch: '<S342>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S342>/Switch4' incorporates:
       *  Constant: '<S342>/Constant8'
       *  Sum: '<S342>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S342>/Switch5' incorporates:
       *  Constant: '<S342>/Constant7'
       *  Gain: '<S342>/Gain'
       *  Sum: '<S342>/Subtract5'
       *  Switch: '<S342>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S342>/Switch4' incorporates:
       *  Constant: '<S342>/Constant6'
       *  Switch: '<S342>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S342>/Switch4' */

    /* Logic: '<S342>/Logical Operator1' incorporates:
     *  Constant: '<S14>/Constant12'
     *  Logic: '<S342>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S344>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_bn = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_bn = 0.0;
    } else {
      rtb_Add_bn = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S344>/Add' incorporates:
     *  Constant: '<S344>/Constant'
     *  Constant: '<S344>/Constant1'
     *  DeadZone: '<S344>/Dead Zone'
     *  Lookup_n-D: '<S344>/Modulation_Str_Y_Rel'
     *  Product: '<S344>/Product'
     *  Product: '<S344>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Add_h5 = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                  Steering_Relative_Gain) + (rtb_Add_bn * Steering_Twist_Gain);

    /* RelationalOperator: '<S346>/Compare' incorporates:
     *  Constant: '<S346>/Constant'
     */
    rtb_Compare_a = (rtb_Add_h5 == 0.0);

    /* Logic: '<S344>/AND2' incorporates:
     *  RelationalOperator: '<S347>/FixPt Relational Operator'
     *  RelationalOperator: '<S348>/FixPt Relational Operator'
     *  RelationalOperator: '<S349>/FixPt Relational Operator'
     *  RelationalOperator: '<S350>/FixPt Relational Operator'
     *  UnitDelay: '<S347>/Delay Input1'
     *  UnitDelay: '<S348>/Delay Input1'
     *  UnitDelay: '<S349>/Delay Input1'
     *  UnitDelay: '<S350>/Delay Input1'
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
     * Block description for '<S350>/Delay Input1':
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

    /* Logic: '<S344>/AND1' incorporates:
     *  Logic: '<S344>/AND3'
     *  UnitDelay: '<S344>/Unit Delay2'
     */
    rtb_AND1_c = (rtb_Compare_a && (rtb_Enable_Wheels ||
      (Robot_Control_DW.UnitDelay2_DSTATE)));

    /* Logic: '<S344>/AND4' incorporates:
     *  Logic: '<S344>/AND8'
     *  UnitDelay: '<S344>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_a && (!rtb_Enable_Wheels)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S344>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1_c || rtb_AND4);

    /* Switch: '<S344>/Switch8' incorporates:
     *  Constant: '<S353>/Constant'
     *  Logic: '<S344>/AND9'
     *  RelationalOperator: '<S352>/FixPt Relational Operator'
     *  RelationalOperator: '<S353>/Compare'
     *  UnitDelay: '<S10>/Unit Delay'
     *  UnitDelay: '<S352>/Delay Input1'
     *
     * Block description for '<S352>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)rtb_Compare_a)
          > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j))) ||
        (Robot_Control_B.Active_GameState != 2)) {
      /* Switch: '<S344>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S344>/Switch8' incorporates:
       *  UnitDelay: '<S344>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S344>/Switch8' */

    /* Switch: '<S344>/Switch4' incorporates:
     *  Constant: '<S344>/Constant5'
     *  Switch: '<S344>/Switch1'
     *  Switch: '<S344>/Switch5'
     *  Switch: '<S344>/Switch6'
     *  Switch: '<S344>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Subtract_c3 = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S344>/Switch5' incorporates:
       *  Constant: '<S344>/Constant6'
       */
      rtb_Subtract_c3 = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S344>/Switch6' incorporates:
       *  Constant: '<S344>/Constant7'
       *  Switch: '<S344>/Switch5'
       */
      rtb_Subtract_c3 = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S344>/Switch7' incorporates:
       *  Constant: '<S344>/Constant8'
       *  Switch: '<S344>/Switch5'
       *  Switch: '<S344>/Switch6'
       */
      rtb_Subtract_c3 = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S344>/Switch1' incorporates:
       *  Constant: '<S14>/Constant10'
       *  Switch: '<S344>/Switch5'
       *  Switch: '<S344>/Switch6'
       *  Switch: '<S344>/Switch7'
       */
      rtb_Subtract_c3 = 0.0;
    } else {
      /* Switch: '<S344>/Switch6' incorporates:
       *  Switch: '<S344>/Switch5'
       *  Switch: '<S344>/Switch7'
       *  UnitDelay: '<S344>/Unit Delay1'
       */
      rtb_Subtract_c3 = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S344>/Switch4' */

    /* Switch: '<S344>/Switch2' incorporates:
     *  Switch: '<S344>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S344>/Switch2' incorporates:
       *  Constant: '<S344>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S344>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Subtract_c3;
    } else {
      /* Switch: '<S344>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S344>/Switch3' incorporates:
       *  Constant: '<S344>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S344>/Switch2' */

    /* Merge: '<S8>/Merge1' incorporates:
     *  Sum: '<S344>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S343>/Switch1' incorporates:
     *  Constant: '<S343>/Constant5'
     *  Constant: '<S343>/Constant8'
     *  DataTypeConversion: '<S343>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_a;
    }

    /* End of Switch: '<S343>/Switch1' */

    /* Lookup_n-D: '<S345>/Modulation_Drv' incorporates:
     *  Math: '<S345>/Magnitude'
     */
    rtb_Modulation_Drv = look1_binlcpw(rt_hypotd_snf
      (Robot_Control_B.Drive_Joystick_X, Robot_Control_B.Drive_Joystick_Y),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S356>/Compare' incorporates:
     *  Constant: '<S356>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Modulation_Drv == 0.0);

    /* DeadZone: '<S345>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S345>/Dead Zone' */

    /* Logic: '<S345>/Logical Operator' incorporates:
     *  Constant: '<S357>/Constant'
     *  RelationalOperator: '<S357>/Compare'
     */
    rtb_Enable_Wheels = ((rtb_Sin4 != 0.0) && rtb_Swerve_Motors_Disabled);

    /* Switch: '<S343>/Switch' incorporates:
     *  Constant: '<S343>/Constant5'
     *  Constant: '<S343>/Constant7'
     *  DataTypeConversion: '<S343>/Data Type Conversion'
     *  Logic: '<S345>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Enable_Wheels;
    }

    /* End of Switch: '<S343>/Switch' */

    /* Switch: '<S342>/Switch2' incorporates:
     *  Constant: '<S342>/Constant2'
     *  Constant: '<S366>/Constant'
     *  Constant: '<S369>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S366>/Compare'
     *  RelationalOperator: '<S369>/Compare'
     *  Sum: '<S342>/Subtract'
     *  Switch: '<S342>/Switch'
     *  Switch: '<S342>/Switch1'
     *  Switch: '<S342>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S342>/Switch2' incorporates:
       *  Constant: '<S342>/Constant5'
       *  Sum: '<S342>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_p2 = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S342>/Switch2' incorporates:
       *  Constant: '<S342>/Constant4'
       *  Sum: '<S342>/Subtract2'
       *  Switch: '<S342>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S342>/Switch1' incorporates:
       *  Constant: '<S342>/Constant1'
       *  Sum: '<S342>/Subtract3'
       */
      rtb_Switch2_p2 = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S342>/Switch2' incorporates:
       *  Constant: '<S342>/Constant3'
       *  Switch: '<S342>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S342>/Switch1' incorporates:
       *  Constant: '<S342>/Constant'
       */
      rtb_Switch2_p2 = 0.0;
    }

    /* End of Switch: '<S342>/Switch2' */

    /* UnaryMinus: '<S342>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_p2;

    /* Switch: '<S358>/Switch1' incorporates:
     *  Constant: '<S363>/Constant'
     *  Constant: '<S364>/Constant'
     *  Logic: '<S358>/AND'
     *  RelationalOperator: '<S363>/Compare'
     *  RelationalOperator: '<S364>/Compare'
     *  Switch: '<S358>/Switch2'
     *  UnitDelay: '<S358>/Unit Delay'
     *  UnitDelay: '<S358>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S358>/Switch1' */

    /* Switch: '<S345>/Switch1' incorporates:
     *  Logic: '<S345>/Logical Operator1'
     *  Switch: '<S345>/Switch4'
     *  Switch: '<S345>/Switch9'
     */
    if (rtb_Enable_Wheels) {
      /* Signum: '<S345>/Sign' */
      if (rtIsNaN(rtb_Sin4)) {
        rtb_Add_bn = (rtNaN);
      } else if (rtb_Sin4 < 0.0) {
        rtb_Add_bn = -1.0;
      } else {
        rtb_Add_bn = (rtb_Sin4 > 0.0);
      }

      /* Switch: '<S345>/Switch5' incorporates:
       *  Constant: '<S345>/Constant3'
       *  Constant: '<S345>/Constant4'
       */
      if (Robot_Control_B.Drive_Joystick_Z_Mode) {
        rtb_Add_k = -1.5707963267948966;
      } else {
        rtb_Add_k = 0.0;
      }

      /* Merge: '<S8>/Merge3' incorporates:
       *  Gain: '<S345>/Gain3'
       *  Signum: '<S345>/Sign'
       *  Sum: '<S345>/Add'
       *  Switch: '<S345>/Switch5'
       */
      Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_bn) +
        rtb_Add_k;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Switch: '<S345>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S345>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S8>/Merge3' incorporates:
         *  Constant: '<S345>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S8>/Merge3' incorporates:
         *  Constant: '<S345>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S345>/Switch6' */
    } else {
      /* Merge: '<S8>/Merge3' incorporates:
       *  Switch: '<S345>/Switch4'
       *  Trigonometry: '<S345>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S345>/Switch1' */

    /* Switch: '<S355>/Switch1' incorporates:
     *  Constant: '<S355>/Constant'
     *  Constant: '<S355>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_p2 = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_p2 = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S355>/Switch1' */

    /* Switch: '<S362>/Init' incorporates:
     *  UnitDelay: '<S362>/FixPt Unit Delay1'
     *  UnitDelay: '<S362>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_p2;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S362>/Init' */

    /* Sum: '<S360>/Sum1' */
    rtb_Switch2_p2 -= rtb_Init;

    /* Switch: '<S361>/Switch2' incorporates:
     *  Constant: '<S359>/Constant1'
     *  Constant: '<S359>/Constant3'
     *  RelationalOperator: '<S361>/LowerRelop1'
     *  RelationalOperator: '<S361>/UpperRelop'
     *  Switch: '<S361>/Switch'
     */
    if (rtb_Switch2_p2 > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_p2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_p2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S361>/Switch' incorporates:
       *  Constant: '<S359>/Constant1'
       */
      rtb_Switch2_p2 = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S361>/Switch2' */

    /* Sum: '<S360>/Sum' */
    rtb_Init += rtb_Switch2_p2;

    /* Switch: '<S345>/Switch8' incorporates:
     *  Logic: '<S345>/Logical Operator1'
     *  Switch: '<S345>/Switch2'
     */
    if (rtb_Enable_Wheels) {
      /* Switch: '<S345>/Switch' incorporates:
       *  Gain: '<S345>/Gain'
       *  Merge: '<S8>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Sin4;
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S8>/Merge4' incorporates:
       *  Constant: '<S14>/Constant7'
       *  Constant: '<S14>/Constant8'
       *  Constant: '<S345>/Constant5'
       *  Gain: '<S345>/Gain2'
       *  Math: '<S345>/Magnitude1'
       *  MinMax: '<S345>/Min'
       *  Switch: '<S345>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S355>/Product' incorporates:
       *  Switch: '<S345>/Switch2'
       */
      rtb_Add_bn = rtb_Modulation_Drv * rtb_Init;

      /* Saturate: '<S355>/Saturation' incorporates:
       *  Switch: '<S345>/Switch2'
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

      /* End of Saturate: '<S355>/Saturation' */
    }

    /* End of Switch: '<S345>/Switch8' */

    /* Merge: '<S8>/Merge2' incorporates:
     *  SignalConversion: '<S344>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Add_h5;

    /* Switch: '<S342>/Switch6' incorporates:
     *  Constant: '<S342>/Constant11'
     *  Switch: '<S342>/Switch7'
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

    /* Update for UnitDelay: '<S352>/Delay Input1'
     *
     * Block description for '<S352>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_a;

    /* Update for UnitDelay: '<S351>/Delay Input1' incorporates:
     *  Constant: '<S14>/Constant5'
     *
     * Block description for '<S351>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S347>/Delay Input1'
     *
     * Block description for '<S347>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S348>/Delay Input1'
     *
     * Block description for '<S348>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S349>/Delay Input1'
     *
     * Block description for '<S349>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S350>/Delay Input1'
     *
     * Block description for '<S350>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S344>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE = rtb_AND1_c;

    /* Update for UnitDelay: '<S344>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S344>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S344>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Subtract_c3;

    /* Update for UnitDelay: '<S358>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1;

    /* Update for UnitDelay: '<S358>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S362>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S362>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S362>/FixPt Unit Delay1' */
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
    rtb_Merge1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Merge1;

    /* Sum: '<S78>/Sum' incorporates:
     *  Constant: '<S27>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S78>/C[k]*xhat[k|k-1]'
     *  Product: '<S78>/D[k]*u[k]'
     *  Sum: '<S78>/Add1'
     */
    rtb_Subtract_c3 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Sin4 = rtb_Reshapey[0] - (rtb_Subtract_c3 + rtb_Merge1);

    /* Product: '<S78>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S27>/C'
     *  Delay: '<S27>/MemoryX'
     *  Product: '<S80>/Product'
     */
    rtb_Merge1 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Merge1;

    /* Sum: '<S78>/Sum' incorporates:
     *  Constant: '<S27>/D'
     *  Product: '<S78>/C[k]*xhat[k|k-1]'
     *  Product: '<S78>/D[k]*u[k]'
     *  Sum: '<S78>/Add1'
     */
    rtb_Merge1 = rtb_Reshapey[1] - (rtb_Subtract_c3 + rtb_Merge1);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S78>/Product3' incorporates:
     *  Constant: '<S28>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Sin4) +
      (-2.0601714451538746E-17 * rtb_Merge1);

    /* Sum: '<S80>/Add1' incorporates:
     *  Product: '<S80>/Product'
     */
    rtb_Subtract_c3 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S78>/Product3' incorporates:
     *  Constant: '<S28>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Sin4) +
      (0.095124921972504 * rtb_Merge1);

    /* Sum: '<S80>/Add1' incorporates:
     *  Product: '<S80>/Product'
     */
    rtb_Merge1 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S80>/Product2' incorporates:
     *  Constant: '<S28>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Subtract_c3) +
      (5.9896845167210271E-17 * rtb_Merge1);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Subtract_c3) +
      (0.095124921972503981 * rtb_Merge1);
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
   *  Constant: '<S130>/Constant'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Merge: '<S12>/Merge'
   *  Merge: '<S12>/Merge1'
   *  Merge: '<S12>/Merge2'
   *  Merge: '<S12>/Merge3'
   *  Merge: '<S12>/Merge4'
   *  Merge: '<S12>/Merge5'
   *  Merge: '<S12>/Merge7'
   *  Merge: '<S12>/Merge8'
   *  SignalConversion generated from: '<S130>/Robot_Reached_Destination'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  Robot_Control_DW.If_ActiveSubsystem = 1;
  if ((rtPrevAction != 1) && (rtPrevAction == 0)) {
    /* Disable for If: '<S136>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S139>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S141>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;

      /* End of Disable for If: '<S139>/If' */
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S136>/If' */
  }

  /* Outputs for IfAction SubSystem: '<S12>/Pass Through' incorporates:
   *  ActionPort: '<S130>/Action Port'
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

  /* Signum: '<S280>/Sign2' incorporates:
   *  UnitDelay: '<S280>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S280>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S280>/Product1' incorporates:
   *  Signum: '<S280>/Sign1'
   *  Signum: '<S280>/Sign2'
   */
  rtb_Add_bn *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_bn)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_bn, 256.0);
  }

  /* Switch: '<S280>/Switch' incorporates:
   *  Constant: '<S280>/Constant'
   *  Constant: '<S285>/Constant'
   *  Constant: '<S286>/Constant'
   *  Logic: '<S280>/or'
   *  Product: '<S280>/Product1'
   *  RelationalOperator: '<S285>/Compare'
   *  RelationalOperator: '<S286>/Compare'
   *  UnitDelay: '<S280>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S280>/Switch' */

  /* Switch: '<S291>/Init' incorporates:
   *  UnitDelay: '<S291>/FixPt Unit Delay1'
   *  UnitDelay: '<S291>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Subtract_c3 = rtb_Sin4;
  } else {
    rtb_Subtract_c3 = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S291>/Init' */

  /* RelationalOperator: '<S287>/Compare' incorporates:
   *  Constant: '<S287>/Constant'
   */
  rtb_Compare_a = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S288>/Compare' incorporates:
   *  Constant: '<S288>/Constant'
   */
  rtb_AND1_c = (rtb_Sin4 > 0.0);

  /* Abs: '<S280>/Abs' incorporates:
   *  Sum: '<S280>/Subtract'
   *  UnitDelay: '<S280>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S280>/Switch5' incorporates:
   *  Constant: '<S280>/Constant1'
   *  Switch: '<S280>/Switch1'
   *  UnaryMinus: '<S280>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S280>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S280>/Constant4'
     *  Constant: '<S280>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S280>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S280>/Constant2'
     *  Constant: '<S280>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S280>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S280>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S280>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S280>/Constant10'
     *  Constant: '<S280>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S280>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S280>/Constant7'
     *  Constant: '<S280>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S280>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S280>/Lookup Table Dynamic1'
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

    /* Switch: '<S280>/Switch3' incorporates:
     *  Constant: '<S280>/Constant1'
     *  Constant: '<S280>/Constant3'
     *  UnaryMinus: '<S280>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_bn = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_bn = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S280>/Switch3' */
  }

  /* End of Switch: '<S280>/Switch5' */

  /* Product: '<S280>/Product' incorporates:
   *  Switch: '<S280>/Switch1'
   */
  rtb_Optimized_Module_Angle = rtb_Add_bn * rtb_Merge1;

  /* Sum: '<S289>/Sum1' */
  rtb_Add_h5 = rtb_Sin4 - rtb_Subtract_c3;

  /* Switch: '<S290>/Switch2' incorporates:
   *  RelationalOperator: '<S290>/LowerRelop1'
   */
  if (!(rtb_Add_h5 > rtb_Optimized_Module_Angle)) {
    /* Switch: '<S280>/Switch2' incorporates:
     *  Constant: '<S280>/Constant1'
     *  Switch: '<S280>/Switch4'
     */
    if (rtb_Compare_a) {
      rtb_Modulation_Drv = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S280>/Switch4' incorporates:
       *  Constant: '<S280>/Constant1'
       */
      rtb_Modulation_Drv = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S280>/Switch4' incorporates:
       *  Constant: '<S280>/Constant3'
       *  UnaryMinus: '<S280>/Unary Minus1'
       */
      rtb_Modulation_Drv = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S280>/Switch2' */

    /* Product: '<S280>/Product2' */
    rtb_Modulation_Drv *= rtb_Merge1;

    /* Switch: '<S290>/Switch' incorporates:
     *  RelationalOperator: '<S290>/UpperRelop'
     */
    if (rtb_Add_h5 < rtb_Modulation_Drv) {
      rtb_Optimized_Module_Angle = rtb_Modulation_Drv;
    } else {
      rtb_Optimized_Module_Angle = rtb_Add_h5;
    }

    /* End of Switch: '<S290>/Switch' */
  }

  /* End of Switch: '<S290>/Switch2' */

  /* Sum: '<S289>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Optimized_Module_Angle +
    rtb_Subtract_c3;

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
     *  ActionPort: '<S108>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.IsBlueActive,
      &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem' */
  } else if (rtb_Merge1 <= 35.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.IsBlueActive, &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem1' */
  } else if (rtb_Merge1 <= 60.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.IsBlueActive, &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem2' */
  } else if (rtb_Merge1 <= 85.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    Robot_Contro_IfActionSubsystem1(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.IsBlueActive, &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem3' */
  } else if (rtb_Merge1 <= 110.0) {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    Robot_Contro_IfActionSubsystem2(Robot_Control_U.IsBlueInactiveFirst,
      &Robot_Control_B.IsBlueActive, &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    Robot_Control_IfActionSubsystem(&Robot_Control_B.IsBlueActive,
      &Robot_Control_B.IsRedActive);

    /* End of Outputs for SubSystem: '<S87>/If Action Subsystem5' */
  }

  /* End of If: '<S87>/If' */

  /* If: '<S114>/If' incorporates:
   *  If: '<S115>/If'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Robot_Control_U.IsBlueAlliance != 0.0) {
    /* Outputs for IfAction SubSystem: '<S114>/Blue' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    /* Merge: '<S114>/Merge' incorporates:
     *  Constant: '<S116>/BlueAllianceZoneX'
     *  Logic: '<S116>/AND'
     *  RelationalOperator: '<S116>/Less Than'
     */
    Robot_Control_B.Allow_Score_In_Alliance_Zone =
      ((Robot_Control_B.IsBlueActive) && (Robot_Control_B.KF_Position_X <
        BlueAllianceZoneX));

    /* End of Outputs for SubSystem: '<S114>/Blue' */

    /* Outputs for IfAction SubSystem: '<S115>/Blue' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    /* Merge: '<S115>/Merge' incorporates:
     *  Constant: '<S118>/BlueAllianceZoneX'
     *  RelationalOperator: '<S118>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X >
      BlueAllianceZoneX);

    /* End of Outputs for SubSystem: '<S115>/Blue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S114>/Red' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    /* Merge: '<S114>/Merge' incorporates:
     *  Constant: '<S117>/RedAllianceZoneX'
     *  Logic: '<S117>/AND'
     *  RelationalOperator: '<S117>/GreaterThan'
     */
    Robot_Control_B.Allow_Score_In_Alliance_Zone = ((Robot_Control_B.IsRedActive)
      && (Robot_Control_B.KF_Position_X > RedAllianceZoneX));

    /* End of Outputs for SubSystem: '<S114>/Red' */

    /* Outputs for IfAction SubSystem: '<S115>/Red' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* Merge: '<S115>/Merge' incorporates:
     *  Constant: '<S119>/RedAllianceZoneX'
     *  RelationalOperator: '<S119>/GreaterThan'
     */
    Robot_Control_B.Is_Outside_Alliance_Zone = (Robot_Control_B.KF_Position_X <
      RedAllianceZoneX);

    /* End of Outputs for SubSystem: '<S115>/Red' */
  }

  /* End of If: '<S114>/If' */

  /* MinMax: '<S91>/Max' incorporates:
   *  Abs: '<S91>/Abs1'
   *  Abs: '<S91>/Abs2'
   *  Abs: '<S91>/Abs3'
   *  Inport: '<Root>/Measured_Shooter_Speed_Center'
   *  Inport: '<Root>/Measured_Shooter_Speed_Left'
   *  Inport: '<Root>/Measured_Shooter_Speed_Right'
   */
  Robot_Control_B.Measured_Shooter_Speed_Max = fmax(fmax(fabs
    (Robot_Control_U.Measured_Shooter_Speed_Left), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Center)), fabs
    (Robot_Control_U.Measured_Shooter_Speed_Right));

  /* Logic: '<S88>/AND' incorporates:
   *  Abs: '<S88>/Abs'
   *  Abs: '<S88>/Abs1'
   *  Abs: '<S88>/Abs4'
   *  Constant: '<S88>/Constant1'
   *  Constant: '<S88>/Constant2'
   *  Inport: '<Root>/Gyro_Angle_Field_rad'
   *  RelationalOperator: '<S88>/Relational Operator'
   *  RelationalOperator: '<S88>/Relational Operator1'
   *  RelationalOperator: '<S88>/Relational Operator4'
   *  Sum: '<S88>/Subtract'
   *  Sum: '<S88>/Subtract1'
   *  Sum: '<S88>/Subtract4'
   *  UnitDelay generated from: '<S11>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_AND1_c = (((fabs(Robot_Control_DW.UnitDelay_1_DSTATE -
                       Robot_Control_U.Gyro_Angle_Field_rad) <=
                  Robot_Control_DW.UnitDelay_4_DSTATE) && (fabs
    (Robot_Control_DW.UnitDelay_2_DSTATE -
     Robot_Control_B.Measured_Shooter_Speed_Max) <=
    Shooter_Motor_Max_Error_Shoot)) && (fabs(Robot_Control_DW.UnitDelay_3_DSTATE
    - Robot_Control_B.Estimated_Hood_Pos) <= Hood_Pos_Max_Error_Shoot));

  /* Logic: '<S88>/AND2' incorporates:
   *  Constant: '<S88>/Constant'
   *  Inport: '<Root>/Robot_Velocity_X'
   *  Inport: '<Root>/Robot_Velocity_Y'
   *  Logic: '<S88>/AND1'
   *  Math: '<S88>/Hypot'
   *  RelationalOperator: '<S88>/GreaterThan'
   */
  Robot_Control_B.Ready_to_Score =
    (((Robot_Control_B.Allow_Score_In_Alliance_Zone) && (rt_hypotd_snf
       (Robot_Control_U.Robot_Velocity_X, Robot_Control_U.Robot_Velocity_Y) <=
       Robot_Velocity_Maximum_Shooter)) && rtb_AND1_c);

  /* Logic: '<S88>/AND3' */
  Robot_Control_B.Ready_to_Pass = ((Robot_Control_B.Is_Outside_Alliance_Zone) &&
    rtb_AND1_c);

  /* Chart: '<S11>/Shooter_Transfer_Feeder Chart' */
  if (Robot_Control_DW.is_active_c2_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c2_Robot_Control = 1U;
    Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Not_Shooting;
    Robot_Control_B.Shooter_Active = false;
    Robot_Control_B.Desired_Transfer_Speed = 0.0;
    Robot_Control_B.Desired_Feeder_Speed = 0.0;

    /* Switch: '<S3>/Switch2' */
    rtb_Merge1 = Robot_Control_B.Gyro_Angle_SPF;
  } else if (Robot_Control_DW.is_c2_Robot_Control ==
             Robot_Control_IN_Not_Shooting) {
    Robot_Control_B.Shooter_Active = false;
    Robot_Control_B.Desired_Feeder_Speed = 0.0;
    if ((rtb_Button_Spinup_Enable != 0) || (rtb_Button_Shoot_Enable != 0)) {
      Robot_Control_DW.is_c2_Robot_Control = Robot_Control_IN_Shooting;
      Robot_Control_B.Shooter_Active = true;
      Robot_Control_DW.is_Shooting = Robot_Control_IN_Spinning_Up;
      Robot_Control_B.Desired_Transfer_Speed = 0.0;

      /* Switch: '<S3>/Switch2' incorporates:
       *  Inport: '<Root>/Gyro_Angle_Field_rad'
       */
      rtb_Merge1 = Robot_Control_U.Gyro_Angle_Field_rad;
    } else {
      /* Switch: '<S3>/Switch2' */
      rtb_Merge1 = Robot_Control_B.Gyro_Angle_SPF;
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

      /* Switch: '<S3>/Switch2' */
      rtb_Merge1 = Robot_Control_B.Gyro_Angle_SPF;
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

      /* Switch: '<S3>/Switch2' incorporates:
       *  Inport: '<Root>/Gyro_Angle_Field_rad'
       */
      rtb_Merge1 = Robot_Control_U.Gyro_Angle_Field_rad;
    }
  }

  /* End of Chart: '<S11>/Shooter_Transfer_Feeder Chart' */

  /* Switch: '<S283>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S283>/Switch' incorporates:
     *  Constant: '<S315>/Constant3'
     *  Constant: '<S315>/Constant4'
     *  Math: '<S315>/Math Function'
     *  Sum: '<S283>/Subtract'
     *  Sum: '<S315>/Add1'
     *  Sum: '<S315>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - rtb_Merge1) + 3.1415926535897931,
       6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S283>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S283>/Switch' */

  /* If: '<S86>/If' incorporates:
   *  Constant: '<S95>/Constant'
   */
  if (Robot_Control_B.Shooter_Active) {
    /* Outputs for IfAction SubSystem: '<S86>/Desired Shooting Parameters Math' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S95>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S97>/While Iterator'
     */
    /* SignalConversion generated from: '<S98>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S98>/Constant5'
     *  Constant: '<S98>/Constant6'
     *  Constant: '<S98>/Constant7'
     *  Constant: '<S98>/Constant8'
     *  Constant: '<S98>/Constant9'
     */
    rtb_shot_distance[0] = Dist_Arr_0;
    rtb_shot_distance[1] = Dist_Arr_1;
    rtb_shot_distance[2] = Dist_Arr_2;
    rtb_shot_distance[3] = Dist_Arr_3;
    rtb_shot_distance[4] = Dist_Arr_4;

    /* End of Outputs for SubSystem: '<S95>/Iterate_Shot_Target' */

    /* SignalConversion generated from: '<S98>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S98>/Constant'
     *  Constant: '<S98>/Constant1'
     *  Constant: '<S98>/Constant2'
     *  Constant: '<S98>/Constant3'
     *  Constant: '<S98>/Constant4'
     */
    rtb_TmpSignalConversionAtLook_k[0] = Gyro_Err_Arr_0;
    rtb_TmpSignalConversionAtLook_k[1] = Gyro_Err_Arr_1;
    rtb_TmpSignalConversionAtLook_k[2] = Gyro_Err_Arr_2;
    rtb_TmpSignalConversionAtLook_k[3] = Gyro_Err_Arr_3;
    rtb_TmpSignalConversionAtLook_k[4] = Gyro_Err_Arr_4;

    /* SignalConversion generated from: '<S99>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S99>/Constant'
     *  Constant: '<S99>/Constant1'
     *  Constant: '<S99>/Constant2'
     *  Constant: '<S99>/Constant3'
     *  Constant: '<S99>/Constant4'
     */
    rtb_TmpSignalConversionAtLoo_o3[0] = Hood_Position_0;
    rtb_TmpSignalConversionAtLoo_o3[1] = Hood_Position_1;
    rtb_TmpSignalConversionAtLoo_o3[2] = Hood_Position_2;
    rtb_TmpSignalConversionAtLoo_o3[3] = Hood_Position_3;
    rtb_TmpSignalConversionAtLoo_o3[4] = Hood_Position_4;

    /* SignalConversion generated from: '<S99>/Lookup Table Dynamic' */
    for (i = 0; i < 5; i++) {
      rtb_shot_distance_m[i] = rtb_shot_distance[i];
      rtb_shot_distance_fj[i] = rtb_shot_distance[i];
    }

    /* SignalConversion generated from: '<S100>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S100>/Constant1'
     *  Constant: '<S100>/Constant2'
     *  Constant: '<S100>/Constant3'
     *  Constant: '<S100>/Constant4'
     */
    rtb_TmpSignalConversionAtLook_f[0] = Shooter_Spd_0;
    rtb_TmpSignalConversionAtLook_f[1] = Shooter_Spd_1;
    rtb_TmpSignalConversionAtLook_f[2] = Shooter_Spd_2;
    rtb_TmpSignalConversionAtLook_f[3] = Shooter_Spd_3;
    rtb_TmpSignalConversionAtLook_f[4] = Shooter_Spd_4;

    /* Switch: '<S101>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     *  Switch: '<S101>/Switch1'
     */
    if (Robot_Control_U.IsBlueAlliance != 0.0) {
      /* Switch: '<S101>/Switch' incorporates:
       *  Constant: '<S101>/Constant'
       */
      Robot_Control_B.Target_X = Blue_Hub_X;

      /* Switch: '<S101>/Switch1' incorporates:
       *  Constant: '<S101>/Constant1'
       */
      Robot_Control_B.Target_Y = Blue_Hub_Y;
    } else {
      /* Switch: '<S101>/Switch' incorporates:
       *  Constant: '<S101>/Constant2'
       */
      Robot_Control_B.Target_X = Red_Hub_X;

      /* Switch: '<S101>/Switch1' incorporates:
       *  Constant: '<S101>/Constant3'
       */
      Robot_Control_B.Target_Y = Red_Hub_Y;
    }

    /* End of Switch: '<S101>/Switch' */

    /* Outputs for Iterator SubSystem: '<S95>/Iterate_Shot_Target' incorporates:
     *  WhileIterator: '<S97>/While Iterator'
     */
    rtb_Button_Spinup_Enable = 1U;

    /* InitializeConditions for Memory: '<S97>/Memory1' */
    rtb_Add_h5 = 0.0;

    /* InitializeConditions for Memory: '<S97>/Memory2' */
    rtb_Subtract_c3 = 0.0;

    /* InitializeConditions for Memory: '<S97>/Memory3' */
    rtb_Modulation_Drv = 0.0;

    /* InitializeConditions for Memory: '<S97>/Memory' */
    rtb_AND1_c = true;
    rtb_Compare_a = true;

    /* SignalConversion generated from: '<S103>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S103>/Constant'
     *  Constant: '<S103>/Constant1'
     *  Constant: '<S103>/Constant2'
     *  Constant: '<S103>/Constant3'
     *  Constant: '<S103>/Constant4'
     *  Constant: '<S95>/Constant'
     */
    rtb_TOF_g[0] = TOF_Arr_0;
    rtb_TOF_g[1] = TOF_Arr_1;
    rtb_TOF_g[2] = TOF_Arr_2;
    rtb_TOF_g[3] = TOF_Arr_3;
    rtb_TOF_g[4] = TOF_Arr_4;

    /* SignalConversion generated from: '<S103>/Lookup Table Dynamic' */
    for (i = 0; i < 5; i++) {
      rtb_shot_distance_o[i] = rtb_shot_distance[i];
    }

    while (rtb_Compare_a && (rtb_Button_Spinup_Enable <= 10)) {
      /* Switch: '<S104>/Switch' incorporates:
       *  Memory: '<S97>/Memory1'
       *  Memory: '<S97>/Memory2'
       *  Switch: '<S104>/Switch1'
       */
      if (rtb_Button_Spinup_Enable > 1) {
        rtb_Sin4 = rtb_Add_h5;
        rtb_Switch1 = rtb_Subtract_c3;
      } else {
        rtb_Sin4 = Robot_Control_B.Target_X;
        rtb_Switch1 = Robot_Control_B.Target_Y;
      }

      /* End of Switch: '<S104>/Switch' */

      /* Math: '<S102>/Hypot' incorporates:
       *  Sum: '<S102>/Subtract'
       *  Sum: '<S102>/Subtract1'
       */
      Robot_Control_B.Desired_Shot_Distance = rt_hypotd_snf(rtb_Sin4 -
        Robot_Control_B.KF_Position_X, rtb_Switch1 -
        Robot_Control_B.KF_Position_Y);

      /* S-Function (sfix_look1_dyn): '<S103>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S103>/Lookup Table Dynamic'
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

      /* Sum: '<S105>/Subtract' incorporates:
       *  Memory: '<S97>/Memory3'
       *  Sum: '<S105>/Subtract1'
       */
      rtb_Subtract_c3 = rtb_TOF - rtb_Modulation_Drv;

      /* Sum: '<S105>/Add' incorporates:
       *  Gain: '<S105>/Multiply'
       *  Inport: '<Root>/Robot_Velocity_X'
       *  Product: '<S105>/Product'
       *  Sum: '<S105>/Subtract'
       */
      Robot_Control_B.Desired_Target_X = (rtb_Subtract_c3 *
        (-Robot_Control_U.Robot_Velocity_X)) + rtb_Sin4;

      /* Sum: '<S105>/Add1' incorporates:
       *  Gain: '<S105>/Multiply1'
       *  Inport: '<Root>/Robot_Velocity_Y'
       *  Product: '<S105>/Product1'
       */
      Robot_Control_B.Desired_Target_Y = (rtb_Subtract_c3 *
        (-Robot_Control_U.Robot_Velocity_Y)) + rtb_Switch1;

      /* Memory: '<S97>/Memory' */
      rtb_Compare_a = rtb_AND1_c;

      /* Update for Memory: '<S97>/Memory1' */
      rtb_Add_h5 = Robot_Control_B.Desired_Target_X;

      /* Update for Memory: '<S97>/Memory2' */
      rtb_Subtract_c3 = Robot_Control_B.Desired_Target_Y;

      /* Update for Memory: '<S97>/Memory3' */
      rtb_Modulation_Drv = rtb_TOF;

      /* Update for Memory: '<S97>/Memory' incorporates:
       *  Constant: '<S107>/Constant'
       *  Math: '<S106>/Hypot'
       *  RelationalOperator: '<S107>/Compare'
       *  Sum: '<S106>/Subtract'
       *  Sum: '<S106>/Subtract1'
       */
      rtb_AND1_c = (rt_hypotd_snf(Robot_Control_B.Desired_Target_X - rtb_Sin4,
        Robot_Control_B.Desired_Target_Y - rtb_Switch1) >=
                    Shot_Target_Error_Thresh);
      rtb_Button_Spinup_Enable++;
    }

    /* End of Outputs for SubSystem: '<S95>/Iterate_Shot_Target' */

    /* S-Function (sfix_look1_dyn): '<S98>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S98>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S99>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S99>/Lookup Table Dynamic'
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

    /* S-Function (sfix_look1_dyn): '<S100>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S100>/Lookup Table Dynamic'
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

    /* Merge: '<S86>/Merge1' incorporates:
     *  SignalConversion generated from: '<S93>/Desired_Shooter_Speed'
     */
    Robot_Control_B.Desired_Shooter_Speed =
      Robot_Control_B.Desired_Shooter_Motor_Speed_Cal;

    /* Merge: '<S86>/Merge2' incorporates:
     *  SignalConversion generated from: '<S93>/Desired_Hood_Pos'
     */
    Robot_Control_B.Desired_Hood_Pos_Shoot =
      Robot_Control_B.Desired_Hood_Pos_Calc;

    /* Merge: '<S86>/Merge3' incorporates:
     *  SignalConversion generated from: '<S93>/Allowed_Shoot_Gyro_Error'
     */
    Robot_Control_B.Allowed_Shoot_Gyro_Error =
      Robot_Control_B.Allowed_Shoot_Gyro_Error_Calc;

    /* Merge: '<S86>/Merge' incorporates:
     *  Sum: '<S96>/Subtract'
     *  Sum: '<S96>/Subtract1'
     *  Trigonometry: '<S96>/Tanh'
     */
    Robot_Control_B.Desired_Shoot_Gyro_Angle_rad = rt_atan2d_snf
      (Robot_Control_B.Desired_Target_Y - Robot_Control_B.KF_Position_Y,
       Robot_Control_B.Desired_Target_X - Robot_Control_B.KF_Position_X);

    /* End of Outputs for SubSystem: '<S86>/Desired Shooting Parameters Math' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_bn = Robot_Control_B.Desired_Shoot_Gyro_Angle_rad;
  } else {
    /* Outputs for IfAction SubSystem: '<S86>/Shooter Not Active' incorporates:
     *  ActionPort: '<S94>/Action Port'
     */
    /* Merge: '<S86>/Merge' incorporates:
     *  Constant: '<S94>/Constant2'
     *  SignalConversion generated from: '<S94>/Desired_Gyro_Angle'
     */
    Robot_Control_B.Desired_Shoot_Gyro_Angle_rad = 0.0;

    /* Merge: '<S86>/Merge1' incorporates:
     *  Constant: '<S94>/Constant'
     *  SignalConversion generated from: '<S94>/Desired_Shooter_Speed'
     */
    Robot_Control_B.Desired_Shooter_Speed = 0.0;

    /* Merge: '<S86>/Merge3' incorporates:
     *  Constant: '<S94>/Constant1'
     *  SignalConversion generated from: '<S94>/Allowed_Shoot_Gyro_Error'
     */
    Robot_Control_B.Allowed_Shoot_Gyro_Error = 0.0;

    /* Merge: '<S86>/Merge2' incorporates:
     *  SignalConversion generated from: '<S94>/Desired_Hood_Pos_Previous'
     *  UnitDelay: '<S86>/Unit Delay'
     */
    Robot_Control_B.Desired_Hood_Pos_Shoot = Robot_Control_DW.UnitDelay_DSTATE_c;

    /* End of Outputs for SubSystem: '<S86>/Shooter Not Active' */

    /* Switch: '<S3>/Switch1' */
    rtb_Add_bn = Robot_Control_B.Steering_Abs_Cmd_SPF;
  }

  /* End of If: '<S86>/If' */

  /* Sum: '<S311>/Add1' incorporates:
   *  Constant: '<S311>/Constant3'
   *  Constant: '<S311>/Constant4'
   *  Math: '<S311>/Math Function'
   *  Sum: '<S310>/Sum'
   *  Sum: '<S311>/Add2'
   *  Switch: '<S3>/Switch1'
   */
  rtb_Sin4 = rt_modd_snf((rtb_Add_bn - rtb_Merge1) + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S313>/Sum1' incorporates:
   *  Constant: '<S310>/Constant2'
   *  Product: '<S313>/Product'
   *  Sum: '<S313>/Sum'
   *  UnitDelay: '<S313>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_Sin4 - Robot_Control_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S310>/Product' incorporates:
   *  Constant: '<S310>/Constant3'
   */
  rtb_Add_h5 = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S312>/Diff' incorporates:
   *  UnitDelay: '<S312>/UD'
   *
   * Block description for '<S312>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S312>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Add_h5 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S310>/Saturation' */
  if (rtb_Add_bn > Steering_Heading_Control_D_UL) {
    rtb_Add_bn = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Heading_Control_D_LL) {
    rtb_Add_bn = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S310>/Add' incorporates:
   *  Gain: '<S310>/Gain1'
   *  Saturate: '<S310>/Saturation'
   */
  rtb_Modulation_Drv = (Steering_Heading_Control_P * rtb_Sin4) + rtb_Add_bn;

  /* Sum: '<S310>/Subtract' incorporates:
   *  Constant: '<S310>/Constant'
   */
  rtb_Subtract_c3 = Steering_Heading_Control_Total_UL - rtb_Modulation_Drv;

  /* Sum: '<S310>/Sum2' incorporates:
   *  Gain: '<S310>/Gain2'
   *  UnitDelay: '<S310>/Unit Delay'
   */
  rtb_Sin4 = (Steering_Heading_Control_I * rtb_Sin4) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S314>/Switch2' incorporates:
   *  RelationalOperator: '<S314>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Subtract_c3)) {
    /* Sum: '<S310>/Subtract1' incorporates:
     *  Constant: '<S310>/Constant1'
     */
    rtb_Subtract_c3 = Steering_Heading_Control_Total_LL - rtb_Modulation_Drv;

    /* Switch: '<S314>/Switch' incorporates:
     *  RelationalOperator: '<S314>/UpperRelop'
     */
    if (!(rtb_Sin4 < rtb_Subtract_c3)) {
      rtb_Subtract_c3 = rtb_Sin4;
    }

    /* End of Switch: '<S314>/Switch' */
  }

  /* End of Switch: '<S314>/Switch2' */

  /* Saturate: '<S310>/Saturation1' */
  if (rtb_Subtract_c3 > Steering_Heading_Control_I_UL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_UL;
  } else if (rtb_Subtract_c3 < Steering_Heading_Control_I_LL) {
    rtb_Subtract_c3 = Steering_Heading_Control_I_LL;
  }

  /* End of Saturate: '<S310>/Saturation1' */

  /* Sum: '<S310>/Add1' */
  rtb_Add_bn = rtb_Modulation_Drv + rtb_Subtract_c3;

  /* Saturate: '<S310>/Saturation2' */
  if (rtb_Add_bn > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S310>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_bn < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S310>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S310>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_bn;
  }

  /* End of Saturate: '<S310>/Saturation2' */

  /* Switch: '<S294>/Switch' incorporates:
   *  Abs: '<S294>/Abs'
   *  Constant: '<S294>/Constant'
   *  Constant: '<S309>/Constant'
   *  RelationalOperator: '<S309>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Sin4 = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S294>/Switch' */

  /* Signum: '<S293>/Sign2' incorporates:
   *  UnitDelay: '<S293>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S293>/Sign1' */
  if (rtIsNaN(rtb_Sin4)) {
    rtb_Add_k = (rtNaN);
  } else if (rtb_Sin4 < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (rtb_Sin4 > 0.0);
  }

  /* Product: '<S293>/Product1' incorporates:
   *  Signum: '<S293>/Sign1'
   *  Signum: '<S293>/Sign2'
   */
  rtb_Add_bn *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_bn)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_bn, 256.0);
  }

  /* Switch: '<S293>/Switch' incorporates:
   *  Constant: '<S293>/Constant'
   *  Constant: '<S302>/Constant'
   *  Constant: '<S303>/Constant'
   *  Logic: '<S293>/or'
   *  Product: '<S293>/Product1'
   *  RelationalOperator: '<S302>/Compare'
   *  RelationalOperator: '<S303>/Compare'
   *  UnitDelay: '<S293>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Init_g = rtb_Sin4;
  } else {
    rtb_Init_g = 0.0;
  }

  /* End of Switch: '<S293>/Switch' */

  /* Switch: '<S308>/Init' incorporates:
   *  UnitDelay: '<S308>/FixPt Unit Delay1'
   *  UnitDelay: '<S308>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Init_g;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S308>/Init' */

  /* RelationalOperator: '<S304>/Compare' incorporates:
   *  Constant: '<S304>/Constant'
   */
  rtb_Compare_a = (rtb_Init_g == 0.0);

  /* RelationalOperator: '<S305>/Compare' incorporates:
   *  Constant: '<S305>/Constant'
   */
  rtb_AND1_c = (rtb_Init_g > 0.0);

  /* Abs: '<S293>/Abs' incorporates:
   *  Sum: '<S293>/Subtract'
   *  UnitDelay: '<S293>/Unit Delay'
   */
  rtb_Modulation_Drv = fabs(Robot_Control_DW.UnitDelay_DSTATE_d - rtb_Sin4);

  /* Switch: '<S293>/Switch5' incorporates:
   *  Constant: '<S293>/Constant1'
   *  Switch: '<S293>/Switch1'
   *  UnaryMinus: '<S293>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S293>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S293>/Constant4'
     *  Constant: '<S293>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S293>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S293>/Constant2'
     *  Constant: '<S293>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S293>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S293>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S293>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S293>/Constant10'
     *  Constant: '<S293>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S293>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S293>/Constant7'
     *  Constant: '<S293>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S293>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S293>/Lookup Table Dynamic1'
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

    /* Switch: '<S293>/Switch3' incorporates:
     *  Constant: '<S293>/Constant1'
     *  Constant: '<S293>/Constant3'
     *  UnaryMinus: '<S293>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_bn = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_bn = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S293>/Switch3' */
  }

  /* End of Switch: '<S293>/Switch5' */

  /* Product: '<S293>/Product' incorporates:
   *  Switch: '<S293>/Switch1'
   */
  rtb_Switch2_p2 = rtb_Add_bn * rtb_Modulation_Drv;

  /* Sum: '<S306>/Sum1' */
  rtb_Sin4 = rtb_Init_g - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S307>/Switch2' incorporates:
   *  RelationalOperator: '<S307>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Switch2_p2)) {
    /* Switch: '<S293>/Switch2' incorporates:
     *  Constant: '<S293>/Constant1'
     *  Switch: '<S293>/Switch4'
     */
    if (rtb_Compare_a) {
      rtb_Switch1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S293>/Switch4' incorporates:
       *  Constant: '<S293>/Constant1'
       */
      rtb_Switch1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S293>/Switch4' incorporates:
       *  Constant: '<S293>/Constant3'
       *  UnaryMinus: '<S293>/Unary Minus1'
       */
      rtb_Switch1 = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S293>/Switch2' */

    /* Product: '<S293>/Product2' */
    rtb_Switch1 *= rtb_Modulation_Drv;

    /* Switch: '<S307>/Switch' incorporates:
     *  RelationalOperator: '<S307>/UpperRelop'
     */
    if (rtb_Sin4 < rtb_Switch1) {
      rtb_Switch2_p2 = rtb_Switch1;
    } else {
      rtb_Switch2_p2 = rtb_Sin4;
    }

    /* End of Switch: '<S307>/Switch' */
  }

  /* End of Switch: '<S307>/Switch2' */

  /* Sum: '<S306>/Sum' */
  rtb_Modulation_Drv = rtb_Switch2_p2 + rtb_Optimized_Module_Angle_p;

  /* Signum: '<S292>/Sign2' incorporates:
   *  UnitDelay: '<S292>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S292>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
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
   *  Constant: '<S295>/Constant'
   *  Constant: '<S296>/Constant'
   *  Logic: '<S292>/or'
   *  Product: '<S292>/Product1'
   *  RelationalOperator: '<S295>/Compare'
   *  RelationalOperator: '<S296>/Compare'
   *  UnitDelay: '<S292>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Init_g = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Init_g = 0.0;
  }

  /* End of Switch: '<S292>/Switch' */

  /* Switch: '<S301>/Init' incorporates:
   *  UnitDelay: '<S301>/FixPt Unit Delay1'
   *  UnitDelay: '<S301>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Init_g;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S301>/Init' */

  /* RelationalOperator: '<S297>/Compare' incorporates:
   *  Constant: '<S297>/Constant'
   */
  rtb_Compare_a = (rtb_Init_g == 0.0);

  /* RelationalOperator: '<S298>/Compare' incorporates:
   *  Constant: '<S298>/Constant'
   */
  rtb_AND1_c = (rtb_Init_g > 0.0);

  /* Abs: '<S292>/Abs' incorporates:
   *  Sum: '<S292>/Subtract'
   *  UnitDelay: '<S292>/Unit Delay'
   */
  rtb_Switch1 = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                     Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S292>/Switch5' incorporates:
   *  Constant: '<S292>/Constant1'
   *  Switch: '<S292>/Switch1'
   *  UnaryMinus: '<S292>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S292>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S292>/Constant4'
     *  Constant: '<S292>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S292>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S292>/Constant2'
     *  Constant: '<S292>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S292>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S292>/Lookup Table Dynamic'
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
    /* SignalConversion generated from: '<S292>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S292>/Constant10'
     *  Constant: '<S292>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S292>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S292>/Constant7'
     *  Constant: '<S292>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S292>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S292>/Lookup Table Dynamic1'
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

    /* Switch: '<S292>/Switch3' incorporates:
     *  Constant: '<S292>/Constant1'
     *  Constant: '<S292>/Constant3'
     *  UnaryMinus: '<S292>/Unary Minus'
     */
    if (rtb_AND1_c) {
      rtb_Add_bn = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_bn = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S292>/Switch3' */
  }

  /* End of Switch: '<S292>/Switch5' */

  /* Product: '<S292>/Product' incorporates:
   *  Switch: '<S292>/Switch1'
   */
  rtb_Sin4 = rtb_Add_bn * rtb_Switch1;

  /* Sum: '<S299>/Sum1' */
  rtb_Switch2 = rtb_Init_g - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S300>/Switch2' incorporates:
   *  RelationalOperator: '<S300>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_Sin4)) {
    /* Switch: '<S292>/Switch2' incorporates:
     *  Constant: '<S292>/Constant1'
     *  Constant: '<S292>/Constant3'
     *  Switch: '<S292>/Switch4'
     *  UnaryMinus: '<S292>/Unary Minus1'
     */
    if (rtb_Compare_a) {
      rtb_Add_bn = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1_c) {
      /* Switch: '<S292>/Switch4' incorporates:
       *  Constant: '<S292>/Constant1'
       */
      rtb_Add_bn = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_bn = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S292>/Product2' incorporates:
     *  Switch: '<S292>/Switch2'
     */
    rtb_Sin4 = rtb_Add_bn * rtb_Switch1;

    /* Switch: '<S300>/Switch' incorporates:
     *  RelationalOperator: '<S300>/UpperRelop'
     */
    if (!(rtb_Switch2 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2;
    }

    /* End of Switch: '<S300>/Switch' */
  }

  /* End of Switch: '<S300>/Switch2' */

  /* Sum: '<S299>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S282>/Switch' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if ((Robot_Control_B.Shooter_Active) ||
      (Robot_Control_B.Is_Absolute_Steering_SPF)) {
    /* Switch: '<S282>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Modulation_Drv;
  } else {
    /* Switch: '<S282>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S282>/Switch' */

  /* Fcn: '<S323>/r->x' incorporates:
   *  Fcn: '<S328>/r->x'
   *  Fcn: '<S333>/r->x'
   *  Fcn: '<S338>/r->x'
   */
  rtb_Init_g = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S317>/Add' incorporates:
   *  Fcn: '<S323>/r->x'
   *  Fcn: '<S324>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Init_g;

  /* Fcn: '<S323>/theta->y' incorporates:
   *  Fcn: '<S328>/theta->y'
   *  Fcn: '<S333>/theta->y'
   *  Fcn: '<S338>/theta->y'
   */
  rtb_Switch2_p2 = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S317>/Add' incorporates:
   *  Fcn: '<S323>/theta->y'
   *  Fcn: '<S324>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S318>/Add' incorporates:
   *  Fcn: '<S329>/r->x'
   *  Fcn: '<S329>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Init_g;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S319>/Add' incorporates:
   *  Fcn: '<S334>/r->x'
   *  Fcn: '<S334>/theta->y'
   */
  rtb_Add2_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Init_g;
  rtb_Add2_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2_p2;

  /* Sum: '<S320>/Add' incorporates:
   *  Fcn: '<S339>/r->x'
   *  Fcn: '<S339>/theta->y'
   */
  rtb_Switch1 = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Init_g;
  rtb_Switch2 = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2_p2;

  /* Fcn: '<S337>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Switch1, rtb_Switch2);

  /* RelationalOperator: '<S340>/Compare' incorporates:
   *  Constant: '<S340>/Constant'
   */
  rtb_AND1_c = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S336>/Switch1' */
  if (rtb_AND1_c) {
    /* Switch: '<S336>/Switch1' incorporates:
     *  Constant: '<S336>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S336>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S336>/Switch1' */

  /* Fcn: '<S322>/x->r' */
  rtb_Switch2_p2 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S325>/Compare' incorporates:
   *  Constant: '<S325>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Switch2_p2 == 0.0);

  /* Switch: '<S321>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S321>/Switch1' incorporates:
     *  Constant: '<S321>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S321>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch2_p2;
  }

  /* End of Switch: '<S321>/Switch1' */

  /* Fcn: '<S327>/x->r' */
  rtb_Init_g = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S330>/Compare' incorporates:
   *  Constant: '<S330>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Init_g == 0.0);

  /* Switch: '<S326>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S326>/Switch1' incorporates:
     *  Constant: '<S326>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S326>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Init_g;
  }

  /* End of Switch: '<S326>/Switch1' */

  /* Fcn: '<S332>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2_idx_0, rtb_Add2_idx_1);

  /* RelationalOperator: '<S335>/Compare' incorporates:
   *  Constant: '<S335>/Constant'
   */
  rtb_Compare_a = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S331>/Switch1' */
  if (rtb_Compare_a) {
    /* Switch: '<S331>/Switch1' incorporates:
     *  Constant: '<S331>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S331>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S331>/Switch1' */

  /* Product: '<S316>/Divide' incorporates:
   *  Abs: '<S316>/Abs'
   *  Abs: '<S316>/Abs1'
   *  Abs: '<S316>/Abs2'
   *  Abs: '<S316>/Abs3'
   *  Constant: '<S316>/Constant'
   *  MinMax: '<S316>/Max'
   */
  rtb_Switch2_p2 = 5.3893029530209224 / fmax(fmax(fmax(fmax(5.3893029530209224,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S316>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S336>/Switch' */
  if (!rtb_AND1_c) {
    /* Switch: '<S336>/Switch' incorporates:
     *  Fcn: '<S337>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Switch2,
      rtb_Switch1);
  }

  /* End of Switch: '<S336>/Switch' */

  /* Trigonometry: '<S272>/Cos4' incorporates:
   *  Switch: '<S261>/Angle_Switch'
   *  Trigonometry: '<S271>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S272>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S270>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S272>/Sin4' incorporates:
   *  Switch: '<S261>/Angle_Switch'
   *  Trigonometry: '<S271>/Sin4'
   */
  rtb_Switch1 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S272>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S270>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S272>/Subtract1' incorporates:
   *  Product: '<S272>/Product2'
   *  Product: '<S272>/Product3'
   *  Trigonometry: '<S272>/Cos4'
   *  Trigonometry: '<S272>/Sin4'
   */
  rtb_Switch2 = (rtb_Add_k * rtb_Optimized_Module_Angle) + (rtb_Switch1 *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S272>/Subtract' incorporates:
   *  Product: '<S272>/Product'
   *  Product: '<S272>/Product1'
   *  Trigonometry: '<S272>/Cos4'
   *  Trigonometry: '<S272>/Sin4'
   */
  rtb_Init = (rtb_Add_k * rtb_Optimized_Module_Angle_p) - (rtb_Switch1 *
    rtb_Optimized_Module_Angle);

  /* Math: '<S272>/Hypot' */
  rtb_Hypot_pi = rt_hypotd_snf(rtb_Init, rtb_Switch2);

  /* Switch: '<S272>/Switch' incorporates:
   *  Constant: '<S272>/Constant'
   *  Constant: '<S272>/Constant1'
   *  Constant: '<S273>/Constant'
   *  Product: '<S272>/Divide'
   *  Product: '<S272>/Divide1'
   *  RelationalOperator: '<S273>/Compare'
   *  Switch: '<S272>/Switch1'
   */
  if (rtb_Hypot_pi > 1.0E-6) {
    rtb_Init_g = rtb_Switch2 / rtb_Hypot_pi;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Hypot_pi;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S272>/Switch' */

  /* Switch: '<S261>/Speed_Switch' incorporates:
   *  Abs: '<S261>/Abs'
   *  Constant: '<S269>/Constant'
   *  RelationalOperator: '<S269>/Compare'
   *  Switch: '<S261>/Angle_Switch'
   *  Trigonometry: '<S271>/Atan1'
   *  Trigonometry: '<S272>/Atan1'
   *  UnaryMinus: '<S261>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S271>/Subtract1' incorporates:
     *  Product: '<S271>/Product2'
     *  Product: '<S271>/Product3'
     *  UnaryMinus: '<S261>/Unary Minus'
     */
    rtb_Switch2 = (rtb_Add_k * Robot_Control_ConstB.Sin5_c) + (rtb_Switch1 *
      Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S271>/Subtract' incorporates:
     *  Product: '<S271>/Product'
     *  Product: '<S271>/Product1'
     */
    rtb_Init = (rtb_Add_k * Robot_Control_ConstB.Cos5_b) - (rtb_Switch1 *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S271>/Hypot' */
    rtb_Switch1 = rt_hypotd_snf(rtb_Init, rtb_Switch2);

    /* Switch: '<S271>/Switch1' incorporates:
     *  Constant: '<S271>/Constant'
     *  Constant: '<S271>/Constant1'
     *  Constant: '<S274>/Constant'
     *  Product: '<S271>/Divide'
     *  Product: '<S271>/Divide1'
     *  RelationalOperator: '<S274>/Compare'
     *  Switch: '<S271>/Switch'
     */
    if (rtb_Switch1 > 1.0E-6) {
      rtb_Init /= rtb_Switch1;
      rtb_Switch1 = rtb_Switch2 / rtb_Switch1;
    } else {
      rtb_Init = 1.0;
      rtb_Switch1 = 0.0;
    }

    /* End of Switch: '<S271>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Init);
  } else {
    rtb_Add_bn = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S264>/Product2' incorporates:
   *  Constant: '<S264>/Constant'
   *  Switch: '<S261>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1150.4270689634639;

  /* Signum: '<S259>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S259>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S262>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S263>/Sum'
   */
  rtb_Integral_d = rtb_Optimized_Module_Angle -
    Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S194>/Product' incorporates:
   *  Abs: '<S259>/Abs'
   *  Abs: '<S262>/Abs'
   *  Constant: '<S265>/Constant'
   *  Constant: '<S275>/Constant3'
   *  Constant: '<S275>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S259>/OR'
   *  Lookup_n-D: '<S262>/1-D Lookup Table'
   *  Math: '<S275>/Math Function'
   *  RelationalOperator: '<S259>/Equal1'
   *  RelationalOperator: '<S265>/Compare'
   *  Signum: '<S259>/Sign'
   *  Signum: '<S259>/Sign1'
   *  Sum: '<S262>/Add'
   *  Sum: '<S275>/Add1'
   *  Sum: '<S275>/Add2'
   */
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Integral_d + 1.5707963267948966, 3.1415926535897931) -
          1.5707963267948966), rtCP_uDLookupTable_bp01Data,
     rtCP_uDLookupTable_tableData, 1U);

  /* Sum: '<S260>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Init = rtb_Init_g - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S267>/Sum1' incorporates:
   *  Constant: '<S260>/Constant2'
   *  Product: '<S267>/Product'
   *  Sum: '<S267>/Sum'
   *  UnitDelay: '<S267>/Unit Delay1'
   */
  rtb_Switch1 = ((rtb_Init - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                 Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S260>/Product' incorporates:
   *  Constant: '<S260>/Constant3'
   */
  rtb_Switch2 = rtb_Switch1 * Drive_Motor_Control_D;

  /* Sum: '<S266>/Diff' incorporates:
   *  UnitDelay: '<S266>/UD'
   *
   * Block description for '<S266>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S266>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Switch2 - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S260>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S260>/Add' incorporates:
   *  Gain: '<S260>/Gain'
   *  Gain: '<S260>/Gain1'
   *  Saturate: '<S260>/Saturation'
   */
  rtb_Hypot_pi = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P
    * rtb_Init)) + rtb_Add_bn;

  /* Saturate: '<S260>/Saturation2' incorporates:
   *  Sum: '<S260>/Add1'
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

  /* End of Saturate: '<S260>/Saturation2' */

  /* Switch: '<S321>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S321>/Switch' incorporates:
     *  Fcn: '<S322>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S321>/Switch' */

  /* Trigonometry: '<S209>/Cos4' incorporates:
   *  Switch: '<S198>/Angle_Switch'
   *  Trigonometry: '<S208>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S209>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S207>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S209>/Sin4' incorporates:
   *  Switch: '<S198>/Angle_Switch'
   *  Trigonometry: '<S208>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S209>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S207>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S209>/Subtract1' incorporates:
   *  Product: '<S209>/Product2'
   *  Product: '<S209>/Product3'
   *  Trigonometry: '<S209>/Cos4'
   *  Trigonometry: '<S209>/Sin4'
   */
  rtb_Hypot_pi = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S209>/Subtract' incorporates:
   *  Product: '<S209>/Product'
   *  Product: '<S209>/Product1'
   *  Trigonometry: '<S209>/Cos4'
   *  Trigonometry: '<S209>/Sin4'
   */
  rtb_Init = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S209>/Hypot' */
  rtb_Hypot_fg = rt_hypotd_snf(rtb_Init, rtb_Hypot_pi);

  /* Switch: '<S209>/Switch' incorporates:
   *  Constant: '<S209>/Constant'
   *  Constant: '<S209>/Constant1'
   *  Constant: '<S210>/Constant'
   *  Product: '<S209>/Divide'
   *  Product: '<S209>/Divide1'
   *  RelationalOperator: '<S210>/Compare'
   *  Switch: '<S209>/Switch1'
   */
  if (rtb_Hypot_fg > 1.0E-6) {
    rtb_Init_g = rtb_Hypot_pi / rtb_Hypot_fg;
    rtb_Optimized_Module_Angle_p = rtb_Init / rtb_Hypot_fg;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S209>/Switch' */

  /* Product: '<S316>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S198>/Speed_Switch' incorporates:
   *  Abs: '<S198>/Abs'
   *  Constant: '<S206>/Constant'
   *  RelationalOperator: '<S206>/Compare'
   *  Switch: '<S198>/Angle_Switch'
   *  Trigonometry: '<S208>/Atan1'
   *  Trigonometry: '<S209>/Atan1'
   *  UnaryMinus: '<S198>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S208>/Subtract1' incorporates:
     *  Product: '<S208>/Product2'
     *  Product: '<S208>/Product3'
     *  UnaryMinus: '<S198>/Unary Minus'
     */
    rtb_Hypot_pi = (rtb_Add_k * Robot_Control_ConstB.Sin5) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5);

    /* Sum: '<S208>/Subtract' incorporates:
     *  Product: '<S208>/Product'
     *  Product: '<S208>/Product1'
     */
    rtb_Hypot_fg = (rtb_Add_k * Robot_Control_ConstB.Cos5) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5);

    /* Math: '<S208>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Hypot_fg, rtb_Hypot_pi);

    /* Switch: '<S208>/Switch1' incorporates:
     *  Constant: '<S208>/Constant'
     *  Constant: '<S208>/Constant1'
     *  Constant: '<S211>/Constant'
     *  Product: '<S208>/Divide'
     *  Product: '<S208>/Divide1'
     *  RelationalOperator: '<S211>/Compare'
     *  Switch: '<S208>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Hypot_fg /= rtb_Init;
      rtb_Hypot_pi /= rtb_Init;
    } else {
      rtb_Hypot_fg = 1.0;
      rtb_Hypot_pi = 0.0;
    }

    /* End of Switch: '<S208>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Hypot_pi, rtb_Hypot_fg);
  } else {
    rtb_Add_bn = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S201>/Product2' incorporates:
   *  Constant: '<S201>/Constant'
   *  Switch: '<S198>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1150.4270689634639;

  /* Signum: '<S196>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S196>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S199>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S200>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S191>/Product' incorporates:
   *  Abs: '<S196>/Abs'
   *  Abs: '<S199>/Abs'
   *  Constant: '<S202>/Constant'
   *  Constant: '<S212>/Constant3'
   *  Constant: '<S212>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S196>/OR'
   *  Lookup_n-D: '<S199>/1-D Lookup Table'
   *  Math: '<S212>/Math Function'
   *  RelationalOperator: '<S196>/Equal1'
   *  RelationalOperator: '<S202>/Compare'
   *  Signum: '<S196>/Sign'
   *  Signum: '<S196>/Sign1'
   *  Sum: '<S199>/Add'
   *  Sum: '<S212>/Add1'
   *  Sum: '<S212>/Add2'
   */
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j, 1U);

  /* Sum: '<S197>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_fg = rtb_Init_g - Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S204>/Sum1' incorporates:
   *  Constant: '<S197>/Constant2'
   *  Product: '<S204>/Product'
   *  Sum: '<S204>/Sum'
   *  UnitDelay: '<S204>/Unit Delay1'
   */
  rtb_Hypot_pi = ((rtb_Hypot_fg - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                  Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S197>/Product' incorporates:
   *  Constant: '<S197>/Constant3'
   */
  rtb_Init = rtb_Hypot_pi * Drive_Motor_Control_D;

  /* Sum: '<S203>/Diff' incorporates:
   *  UnitDelay: '<S203>/UD'
   *
   * Block description for '<S203>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S203>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Init - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S197>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S197>/Add' incorporates:
   *  Gain: '<S197>/Gain'
   *  Gain: '<S197>/Gain1'
   *  Saturate: '<S197>/Saturation'
   */
  rtb_Hypot_fg = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P
    * rtb_Hypot_fg)) + rtb_Add_bn;

  /* Saturate: '<S197>/Saturation2' incorporates:
   *  Sum: '<S197>/Add1'
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

  /* End of Saturate: '<S197>/Saturation2' */

  /* Sum: '<S213>/Add1' incorporates:
   *  Constant: '<S213>/Constant3'
   *  Constant: '<S213>/Constant4'
   *  Math: '<S213>/Math Function'
   *  Sum: '<S213>/Add2'
   */
  rtb_Init_g = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S215>/Sum1' incorporates:
   *  Constant: '<S200>/Constant2'
   *  Product: '<S215>/Product'
   *  Sum: '<S215>/Sum'
   *  UnitDelay: '<S215>/Unit Delay1'
   */
  rtb_Hypot_fg = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S200>/Product' incorporates:
   *  Constant: '<S200>/Constant3'
   */
  rtb_Switch2_dp = rtb_Hypot_fg * Steering_Motor_Control_D;

  /* Sum: '<S214>/Diff' incorporates:
   *  UnitDelay: '<S214>/UD'
   *
   * Block description for '<S214>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S214>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Switch2_dp - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S200>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S200>/Add' incorporates:
   *  Gain: '<S200>/Gain1'
   *  Saturate: '<S200>/Saturation'
   */
  rtb_Add_fn = (Steering_Motor_Control_P * rtb_Init_g) + rtb_Add_bn;

  /* Sum: '<S200>/Subtract' incorporates:
   *  Constant: '<S200>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_fn;

  /* Sum: '<S200>/Sum2' incorporates:
   *  Gain: '<S200>/Gain2'
   *  UnitDelay: '<S200>/Unit Delay'
   */
  rtb_Sum2_e = (Steering_Motor_Control_I * rtb_Init_g) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S216>/Switch2' incorporates:
   *  Constant: '<S200>/Constant'
   *  RelationalOperator: '<S216>/LowerRelop1'
   *  Sum: '<S200>/Subtract'
   */
  if (!(rtb_Sum2_e > (1.0 - rtb_Add_fn))) {
    /* Switch: '<S216>/Switch' incorporates:
     *  Constant: '<S200>/Constant1'
     *  RelationalOperator: '<S216>/UpperRelop'
     *  Sum: '<S200>/Subtract1'
     */
    if (rtb_Sum2_e < (-1.0 - rtb_Add_fn)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_fn;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Sum2_e;
    }

    /* End of Switch: '<S216>/Switch' */
  }

  /* End of Switch: '<S216>/Switch2' */

  /* Saturate: '<S200>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Sum2_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Sum2_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_e = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S200>/Saturation1' */

  /* Sum: '<S200>/Add1' */
  rtb_Add_bn = rtb_Add_fn + rtb_Sum2_e;

  /* Saturate: '<S200>/Saturation2' */
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

  /* End of Saturate: '<S200>/Saturation2' */

  /* Switch: '<S326>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S326>/Switch' incorporates:
     *  Fcn: '<S327>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S326>/Switch' */

  /* Trigonometry: '<S230>/Cos4' incorporates:
   *  Switch: '<S219>/Angle_Switch'
   *  Trigonometry: '<S229>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S230>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S228>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S230>/Sin4' incorporates:
   *  Switch: '<S219>/Angle_Switch'
   *  Trigonometry: '<S229>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S230>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S228>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S230>/Subtract1' incorporates:
   *  Product: '<S230>/Product2'
   *  Product: '<S230>/Product3'
   *  Trigonometry: '<S230>/Cos4'
   *  Trigonometry: '<S230>/Sin4'
   */
  rtb_Add_fn = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S230>/Subtract' incorporates:
   *  Product: '<S230>/Product'
   *  Product: '<S230>/Product1'
   *  Trigonometry: '<S230>/Cos4'
   *  Trigonometry: '<S230>/Sin4'
   */
  rtb_Subtract1_la = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S230>/Hypot' */
  rtb_uDLookupTable = rt_hypotd_snf(rtb_Subtract1_la, rtb_Add_fn);

  /* Switch: '<S230>/Switch' incorporates:
   *  Constant: '<S230>/Constant'
   *  Constant: '<S230>/Constant1'
   *  Constant: '<S231>/Constant'
   *  Product: '<S230>/Divide'
   *  Product: '<S230>/Divide1'
   *  RelationalOperator: '<S231>/Compare'
   *  Switch: '<S230>/Switch1'
   */
  if (rtb_uDLookupTable > 1.0E-6) {
    rtb_Init_g = rtb_Add_fn / rtb_uDLookupTable;
    rtb_Optimized_Module_Angle_p = rtb_Subtract1_la / rtb_uDLookupTable;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S230>/Switch' */

  /* Product: '<S316>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S219>/Speed_Switch' incorporates:
   *  Abs: '<S219>/Abs'
   *  Constant: '<S227>/Constant'
   *  RelationalOperator: '<S227>/Compare'
   *  Switch: '<S219>/Angle_Switch'
   *  Trigonometry: '<S229>/Atan1'
   *  Trigonometry: '<S230>/Atan1'
   *  UnaryMinus: '<S219>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S229>/Subtract1' incorporates:
     *  Product: '<S229>/Product2'
     *  Product: '<S229>/Product3'
     *  UnaryMinus: '<S219>/Unary Minus'
     */
    rtb_Add_fn = (rtb_Add_k * Robot_Control_ConstB.Sin5_m) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S229>/Subtract' incorporates:
     *  Product: '<S229>/Product'
     *  Product: '<S229>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_k * Robot_Control_ConstB.Cos5_g) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S229>/Hypot' */
    rtb_Subtract1_la = rt_hypotd_snf(rtb_uDLookupTable, rtb_Add_fn);

    /* Switch: '<S229>/Switch1' incorporates:
     *  Constant: '<S229>/Constant'
     *  Constant: '<S229>/Constant1'
     *  Constant: '<S232>/Constant'
     *  Product: '<S229>/Divide'
     *  Product: '<S229>/Divide1'
     *  RelationalOperator: '<S232>/Compare'
     *  Switch: '<S229>/Switch'
     */
    if (rtb_Subtract1_la > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Subtract1_la;
      rtb_Add_fn /= rtb_Subtract1_la;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Add_fn = 0.0;
    }

    /* End of Switch: '<S229>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_fn, rtb_uDLookupTable);
  } else {
    rtb_Add_bn = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S222>/Product2' incorporates:
   *  Constant: '<S222>/Constant'
   *  Switch: '<S219>/Speed_Switch'
   */
  rtb_Init_g = rtb_Add_bn * 1150.4270689634639;

  /* Signum: '<S217>/Sign' */
  if (rtIsNaN(rtb_Init_g)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Init_g < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Init_g > 0.0);
  }

  /* Signum: '<S217>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S220>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S221>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S192>/Product' incorporates:
   *  Abs: '<S217>/Abs'
   *  Abs: '<S220>/Abs'
   *  Constant: '<S223>/Constant'
   *  Constant: '<S233>/Constant3'
   *  Constant: '<S233>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S217>/OR'
   *  Lookup_n-D: '<S220>/1-D Lookup Table'
   *  Math: '<S233>/Math Function'
   *  RelationalOperator: '<S217>/Equal1'
   *  RelationalOperator: '<S223>/Compare'
   *  Signum: '<S217>/Sign'
   *  Signum: '<S217>/Sign1'
   *  Sum: '<S220>/Add'
   *  Sum: '<S233>/Add1'
   *  Sum: '<S233>/Add2'
   */
  rtb_Init_g = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_g) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_g, 1U);

  /* Sum: '<S218>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_uDLookupTable = rtb_Init_g - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S225>/Sum1' incorporates:
   *  Constant: '<S218>/Constant2'
   *  Product: '<S225>/Product'
   *  Sum: '<S225>/Sum'
   *  UnitDelay: '<S225>/Unit Delay1'
   */
  rtb_Add_fn = ((rtb_uDLookupTable - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S218>/Product' incorporates:
   *  Constant: '<S218>/Constant3'
   */
  rtb_Subtract1_la = rtb_Add_fn * Drive_Motor_Control_D;

  /* Sum: '<S224>/Diff' incorporates:
   *  UnitDelay: '<S224>/UD'
   *
   * Block description for '<S224>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S224>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Subtract1_la - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S218>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S218>/Add' incorporates:
   *  Gain: '<S218>/Gain'
   *  Gain: '<S218>/Gain1'
   *  Saturate: '<S218>/Saturation'
   */
  rtb_Init_g = ((Drive_Motor_Control_FF * rtb_Init_g) + (Drive_Motor_Control_P *
    rtb_uDLookupTable)) + rtb_Add_bn;

  /* Saturate: '<S218>/Saturation2' incorporates:
   *  Sum: '<S218>/Add1'
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

  /* End of Saturate: '<S218>/Saturation2' */

  /* Sum: '<S234>/Add1' incorporates:
   *  Constant: '<S234>/Constant3'
   *  Constant: '<S234>/Constant4'
   *  Math: '<S234>/Math Function'
   *  Sum: '<S234>/Add2'
   */
  rtb_Init_g = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S236>/Sum1' incorporates:
   *  Constant: '<S221>/Constant2'
   *  Product: '<S236>/Product'
   *  Sum: '<S236>/Sum'
   *  UnitDelay: '<S236>/Unit Delay1'
   */
  rtb_Switch2_m = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                   Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S221>/Product' incorporates:
   *  Constant: '<S221>/Constant3'
   */
  rtb_Product_hi = rtb_Switch2_m * Steering_Motor_Control_D;

  /* Sum: '<S235>/Diff' incorporates:
   *  UnitDelay: '<S235>/UD'
   *
   * Block description for '<S235>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S235>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Product_hi - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S221>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S221>/Add' incorporates:
   *  Gain: '<S221>/Gain1'
   *  Saturate: '<S221>/Saturation'
   */
  rtb_Add_k = (Steering_Motor_Control_P * rtb_Init_g) + rtb_Add_bn;

  /* Sum: '<S221>/Subtract' incorporates:
   *  Constant: '<S221>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_k;

  /* Sum: '<S221>/Sum2' incorporates:
   *  Gain: '<S221>/Gain2'
   *  UnitDelay: '<S221>/Unit Delay'
   */
  rtb_Init_g = (Steering_Motor_Control_I * rtb_Init_g) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S237>/Switch2' incorporates:
   *  Constant: '<S221>/Constant'
   *  RelationalOperator: '<S237>/LowerRelop1'
   *  Sum: '<S221>/Subtract'
   */
  if (!(rtb_Init_g > (1.0 - rtb_Add_k))) {
    /* Switch: '<S237>/Switch' incorporates:
     *  Constant: '<S221>/Constant1'
     *  RelationalOperator: '<S237>/UpperRelop'
     *  Sum: '<S221>/Subtract1'
     */
    if (rtb_Init_g < (-1.0 - rtb_Add_k)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_k;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Init_g;
    }

    /* End of Switch: '<S237>/Switch' */
  }

  /* End of Switch: '<S237>/Switch2' */

  /* Saturate: '<S221>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_kg = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_kg = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S221>/Saturation1' */

  /* Sum: '<S221>/Add1' */
  rtb_Add_bn = rtb_Add_k + rtb_Subtract1_kg;

  /* Saturate: '<S221>/Saturation2' */
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

  /* End of Saturate: '<S221>/Saturation2' */

  /* Switch: '<S331>/Switch' */
  if (!rtb_Compare_a) {
    /* Switch: '<S331>/Switch' incorporates:
     *  Fcn: '<S332>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2_idx_1,
      rtb_Add2_idx_0);
  }

  /* End of Switch: '<S331>/Switch' */

  /* Trigonometry: '<S251>/Cos4' incorporates:
   *  Switch: '<S240>/Angle_Switch'
   *  Trigonometry: '<S250>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S251>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S249>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S251>/Sin4' incorporates:
   *  Switch: '<S240>/Angle_Switch'
   *  Trigonometry: '<S250>/Sin4'
   */
  rtb_Optimized_Module_Angle = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S251>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S249>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S251>/Subtract1' incorporates:
   *  Product: '<S251>/Product2'
   *  Product: '<S251>/Product3'
   *  Trigonometry: '<S251>/Cos4'
   *  Trigonometry: '<S251>/Sin4'
   */
  rtb_Init_g = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Optimized_Module_Angle *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S251>/Subtract' incorporates:
   *  Product: '<S251>/Product'
   *  Product: '<S251>/Product1'
   *  Trigonometry: '<S251>/Cos4'
   *  Trigonometry: '<S251>/Sin4'
   */
  rtb_uDLookupTable = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Optimized_Module_Angle * rtb_uDLookupTable);

  /* Math: '<S251>/Hypot' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_uDLookupTable, rtb_Init_g);

  /* Switch: '<S251>/Switch' incorporates:
   *  Constant: '<S251>/Constant'
   *  Constant: '<S251>/Constant1'
   *  Constant: '<S252>/Constant'
   *  Product: '<S251>/Divide'
   *  Product: '<S251>/Divide1'
   *  RelationalOperator: '<S252>/Compare'
   *  Switch: '<S251>/Switch1'
   */
  if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
    rtb_Init_g /= rtb_Optimized_Module_Angle_p;
    rtb_Optimized_Module_Angle_p = rtb_uDLookupTable /
      rtb_Optimized_Module_Angle_p;
  } else {
    rtb_Init_g = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S251>/Switch' */

  /* Product: '<S316>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch2_p2;

  /* Switch: '<S240>/Speed_Switch' incorporates:
   *  Abs: '<S240>/Abs'
   *  Constant: '<S248>/Constant'
   *  RelationalOperator: '<S248>/Compare'
   *  Switch: '<S240>/Angle_Switch'
   *  Trigonometry: '<S250>/Atan1'
   *  Trigonometry: '<S251>/Atan1'
   *  UnaryMinus: '<S240>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_g, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_bn = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S250>/Subtract1' incorporates:
     *  Product: '<S250>/Product2'
     *  Product: '<S250>/Product3'
     *  UnaryMinus: '<S240>/Unary Minus'
     */
    rtb_Init_g = (rtb_Add_k * Robot_Control_ConstB.Sin5_e) +
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S250>/Subtract' incorporates:
     *  Product: '<S250>/Product'
     *  Product: '<S250>/Product1'
     */
    rtb_uDLookupTable = (rtb_Add_k * Robot_Control_ConstB.Cos5_i) -
      (rtb_Optimized_Module_Angle * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S250>/Hypot' */
    rtb_Add_k = rt_hypotd_snf(rtb_uDLookupTable, rtb_Init_g);

    /* Switch: '<S250>/Switch1' incorporates:
     *  Constant: '<S250>/Constant'
     *  Constant: '<S250>/Constant1'
     *  Constant: '<S253>/Constant'
     *  Product: '<S250>/Divide'
     *  Product: '<S250>/Divide1'
     *  RelationalOperator: '<S253>/Compare'
     *  Switch: '<S250>/Switch'
     */
    if (rtb_Add_k > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Add_k;
      rtb_Init_g /= rtb_Add_k;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Init_g = 0.0;
    }

    /* End of Switch: '<S250>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Init_g, rtb_uDLookupTable);
  } else {
    rtb_Add_bn = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S243>/Product2' incorporates:
   *  Constant: '<S243>/Constant'
   *  Switch: '<S240>/Speed_Switch'
   */
  rtb_Switch2_p2 = rtb_Add_bn * 1150.4270689634639;

  /* Signum: '<S238>/Sign' */
  if (rtIsNaN(rtb_Switch2_p2)) {
    rtb_Add_bn = (rtNaN);
  } else if (rtb_Switch2_p2 < 0.0) {
    rtb_Add_bn = -1.0;
  } else {
    rtb_Add_bn = (rtb_Switch2_p2 > 0.0);
  }

  /* Signum: '<S238>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S241>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S242>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S193>/Product' incorporates:
   *  Abs: '<S238>/Abs'
   *  Abs: '<S241>/Abs'
   *  Constant: '<S244>/Constant'
   *  Constant: '<S254>/Constant3'
   *  Constant: '<S254>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S238>/OR'
   *  Lookup_n-D: '<S241>/1-D Lookup Table'
   *  Math: '<S254>/Math Function'
   *  RelationalOperator: '<S238>/Equal1'
   *  RelationalOperator: '<S244>/Compare'
   *  Signum: '<S238>/Sign'
   *  Signum: '<S238>/Sign1'
   *  Sum: '<S241>/Add'
   *  Sum: '<S254>/Add1'
   *  Sum: '<S254>/Add2'
   */
  rtb_Switch2_p2 = (((real_T)((rtb_Add_bn == rtb_Add_k) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p2) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Sum: '<S239>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Init_g = rtb_Switch2_p2 - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S246>/Sum1' incorporates:
   *  Constant: '<S239>/Constant2'
   *  Product: '<S246>/Product'
   *  Sum: '<S246>/Sum'
   *  UnitDelay: '<S246>/Unit Delay1'
   */
  rtb_Add_k = ((rtb_Init_g - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S239>/Product' incorporates:
   *  Constant: '<S239>/Constant3'
   */
  rtb_uDLookupTable = rtb_Add_k * Drive_Motor_Control_D;

  /* Sum: '<S245>/Diff' incorporates:
   *  UnitDelay: '<S245>/UD'
   *
   * Block description for '<S245>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S245>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S239>/Saturation' */
  if (rtb_Add_bn > Drive_Motor_Control_D_UL) {
    rtb_Add_bn = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Drive_Motor_Control_D_LL) {
    rtb_Add_bn = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S239>/Add' incorporates:
   *  Gain: '<S239>/Gain'
   *  Gain: '<S239>/Gain1'
   *  Saturate: '<S239>/Saturation'
   */
  rtb_Switch2_p2 = ((Drive_Motor_Control_FF * rtb_Switch2_p2) +
                    (Drive_Motor_Control_P * rtb_Init_g)) + rtb_Add_bn;

  /* Saturate: '<S239>/Saturation2' incorporates:
   *  Sum: '<S239>/Add1'
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

  /* End of Saturate: '<S239>/Saturation2' */

  /* Sum: '<S255>/Add1' incorporates:
   *  Constant: '<S255>/Constant3'
   *  Constant: '<S255>/Constant4'
   *  Math: '<S255>/Math Function'
   *  Sum: '<S255>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S257>/Sum1' incorporates:
   *  Constant: '<S242>/Constant2'
   *  Product: '<S257>/Product'
   *  Sum: '<S257>/Sum'
   *  UnitDelay: '<S257>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S242>/Product' incorporates:
   *  Constant: '<S242>/Constant3'
   */
  rtb_Add2_idx_0 = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S256>/Diff' incorporates:
   *  UnitDelay: '<S256>/UD'
   *
   * Block description for '<S256>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S256>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Add2_idx_0 - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S242>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S242>/Add' incorporates:
   *  Gain: '<S242>/Gain1'
   *  Saturate: '<S242>/Saturation'
   */
  rtb_Add2_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_bn;

  /* Sum: '<S242>/Subtract' incorporates:
   *  Constant: '<S242>/Constant'
   */
  rtb_Init_g = 1.0 - rtb_Add2_idx_1;

  /* Sum: '<S242>/Sum2' incorporates:
   *  Gain: '<S242>/Gain2'
   *  UnitDelay: '<S242>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S258>/Switch2' incorporates:
   *  Constant: '<S242>/Constant'
   *  RelationalOperator: '<S258>/LowerRelop1'
   *  Sum: '<S242>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add2_idx_1))) {
    /* Sum: '<S242>/Subtract1' incorporates:
     *  Constant: '<S242>/Constant1'
     */
    rtb_Init_g = -1.0 - rtb_Add2_idx_1;

    /* Switch: '<S258>/Switch' incorporates:
     *  Constant: '<S242>/Constant1'
     *  RelationalOperator: '<S258>/UpperRelop'
     *  Sum: '<S242>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add2_idx_1))) {
      rtb_Init_g = rtb_Switch2_p2;
    }

    /* End of Switch: '<S258>/Switch' */
  }

  /* End of Switch: '<S258>/Switch2' */

  /* Saturate: '<S242>/Saturation1' */
  if (rtb_Init_g > Steering_Motor_Control_I_UL) {
    rtb_Integral_ga = Steering_Motor_Control_I_UL;
  } else if (rtb_Init_g < Steering_Motor_Control_I_LL) {
    rtb_Integral_ga = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_ga = rtb_Init_g;
  }

  /* End of Saturate: '<S242>/Saturation1' */

  /* Sum: '<S242>/Add1' */
  rtb_Add_bn = rtb_Add2_idx_1 + rtb_Integral_ga;

  /* Saturate: '<S242>/Saturation2' */
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

  /* End of Saturate: '<S242>/Saturation2' */

  /* Sum: '<S276>/Add1' incorporates:
   *  Constant: '<S276>/Constant3'
   *  Constant: '<S276>/Constant4'
   *  Math: '<S276>/Math Function'
   *  Sum: '<S276>/Add2'
   */
  rtb_Switch2_p2 = rt_modd_snf(rtb_Integral_d + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S278>/Sum1' incorporates:
   *  Constant: '<S263>/Constant2'
   *  Product: '<S278>/Product'
   *  Sum: '<S278>/Sum'
   *  UnitDelay: '<S278>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch2_p2 -
    Robot_Control_DW.UnitDelay1_DSTATE_i) * Steering_Motor_Control_D_FilterCoeff)
    + Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S263>/Product' incorporates:
   *  Constant: '<S263>/Constant3'
   */
  rtb_Add2_idx_1 = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S277>/Diff' incorporates:
   *  UnitDelay: '<S277>/UD'
   *
   * Block description for '<S277>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S277>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Add2_idx_1 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S263>/Saturation' */
  if (rtb_Add_bn > Steering_Motor_Control_D_UL) {
    rtb_Add_bn = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_bn < Steering_Motor_Control_D_LL) {
    rtb_Add_bn = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S263>/Add' incorporates:
   *  Gain: '<S263>/Gain1'
   *  Saturate: '<S263>/Saturation'
   */
  rtb_Add_jp = (Steering_Motor_Control_P * rtb_Switch2_p2) + rtb_Add_bn;

  /* Sum: '<S263>/Subtract' incorporates:
   *  Constant: '<S263>/Constant'
   */
  rtb_Init_g = 1.0 - rtb_Add_jp;

  /* Sum: '<S263>/Sum2' incorporates:
   *  Gain: '<S263>/Gain2'
   *  UnitDelay: '<S263>/Unit Delay'
   */
  rtb_Switch2_p2 = (Steering_Motor_Control_I * rtb_Switch2_p2) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S279>/Switch2' incorporates:
   *  Constant: '<S263>/Constant'
   *  RelationalOperator: '<S279>/LowerRelop1'
   *  Sum: '<S263>/Subtract'
   */
  if (!(rtb_Switch2_p2 > (1.0 - rtb_Add_jp))) {
    /* Sum: '<S263>/Subtract1' incorporates:
     *  Constant: '<S263>/Constant1'
     */
    rtb_Init_g = -1.0 - rtb_Add_jp;

    /* Switch: '<S279>/Switch' incorporates:
     *  Constant: '<S263>/Constant1'
     *  RelationalOperator: '<S279>/UpperRelop'
     *  Sum: '<S263>/Subtract1'
     */
    if (!(rtb_Switch2_p2 < (-1.0 - rtb_Add_jp))) {
      rtb_Init_g = rtb_Switch2_p2;
    }

    /* End of Switch: '<S279>/Switch' */
  }

  /* End of Switch: '<S279>/Switch2' */

  /* Saturate: '<S263>/Saturation1' */
  if (rtb_Init_g > Steering_Motor_Control_I_UL) {
    rtb_Integral_bj = Steering_Motor_Control_I_UL;
  } else if (rtb_Init_g < Steering_Motor_Control_I_LL) {
    rtb_Integral_bj = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_bj = rtb_Init_g;
  }

  /* End of Saturate: '<S263>/Saturation1' */

  /* Sum: '<S263>/Add1' */
  rtb_Add_bn = rtb_Add_jp + rtb_Integral_bj;

  /* Saturate: '<S263>/Saturation2' */
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

  /* End of Saturate: '<S263>/Saturation2' */

  /* Sum: '<S126>/Sum' incorporates:
   *  Inport: '<Root>/Measured_Transfer_Speed'
   *  Sum: '<S92>/Subtract'
   */
  rtb_Integral_d = Robot_Control_B.Desired_Transfer_Speed -
    Robot_Control_U.Measured_Transfer_Speed;

  /* Sum: '<S128>/Sum1' incorporates:
   *  Constant: '<S126>/Constant2'
   *  Product: '<S128>/Product'
   *  Sum: '<S126>/Sum'
   *  Sum: '<S128>/Sum'
   *  UnitDelay: '<S128>/Unit Delay1'
   */
  rtb_Add_jp = ((rtb_Integral_d - Robot_Control_DW.UnitDelay1_DSTATE_ji) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_ji;

  /* Product: '<S126>/Product' incorporates:
   *  Constant: '<S126>/Constant3'
   */
  rtb_Product_lo = rtb_Add_jp * Transfer_Motor_Gain_D;

  /* Sum: '<S127>/Diff' incorporates:
   *  UnitDelay: '<S127>/UD'
   *
   * Block description for '<S127>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S127>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Product_lo - Robot_Control_DW.UD_DSTATE_a;

  /* Saturate: '<S126>/Saturation' */
  if (rtb_Add_bn > 0.1) {
    rtb_Add_bn = 0.1;
  } else if (rtb_Add_bn < -0.1) {
    rtb_Add_bn = -0.1;
  }

  /* Sum: '<S126>/Add' incorporates:
   *  Gain: '<S126>/Gain'
   *  Gain: '<S126>/Gain1'
   *  Saturate: '<S126>/Saturation'
   *  Sum: '<S126>/Sum'
   */
  rtb_Switch2_p2 = ((Transfer_Motor_Gain_FF *
                     Robot_Control_B.Desired_Transfer_Speed) +
                    (Transfer_Motor_Gain_P * rtb_Integral_d)) + rtb_Add_bn;

  /* Logic: '<S92>/Logical Operator1' incorporates:
   *  Constant: '<S125>/Constant'
   *  RelationalOperator: '<S125>/Compare'
   */
  rtb_Is_Absolute_Steering = !(Robot_Control_B.Desired_Transfer_Speed == 0.0);

  /* Switch: '<S92>/Switch1' incorporates:
   *  Abs: '<S92>/Abs'
   *  Constant: '<S92>/Constant1'
   *  Constant: '<S92>/Constant2'
   *  Logic: '<S92>/Logical Operator'
   *  Logic: '<S92>/Logical Operator1'
   *  RelationalOperator: '<S92>/LessThan'
   *  UnitDelay: '<S92>/Unit Delay'
   */
  if ((fabs(rtb_Integral_d) < Transfer_Error_Integral_Enable) &&
      rtb_Is_Absolute_Steering) {
    rtb_AND1_c = true;
  } else {
    rtb_AND1_c = (rtb_Is_Absolute_Steering &&
                  (Robot_Control_DW.UnitDelay_DSTATE_ki));
  }

  /* End of Switch: '<S92>/Switch1' */

  /* Switch: '<S126>/Switch' incorporates:
   *  Constant: '<S126>/Constant4'
   */
  if (rtb_AND1_c) {
    /* Sum: '<S126>/Sum2' incorporates:
     *  Gain: '<S126>/Gain2'
     *  Sum: '<S126>/Sum'
     *  UnitDelay: '<S126>/Unit Delay'
     */
    rtb_Init_g = (Transfer_Motor_Gain_I * rtb_Integral_d) +
      Robot_Control_DW.UnitDelay_DSTATE_kz;

    /* Sum: '<S126>/Subtract' incorporates:
     *  Constant: '<S126>/Constant'
     */
    rtb_Integral_d = 1.0 - rtb_Switch2_p2;

    /* Switch: '<S129>/Switch2' incorporates:
     *  Constant: '<S126>/Constant'
     *  RelationalOperator: '<S129>/LowerRelop1'
     *  Sum: '<S126>/Subtract'
     */
    if (!(rtb_Init_g > (1.0 - rtb_Switch2_p2))) {
      /* Sum: '<S126>/Subtract1' incorporates:
       *  Constant: '<S126>/Constant1'
       */
      rtb_Integral_d = -1.0 - rtb_Switch2_p2;

      /* Switch: '<S129>/Switch' incorporates:
       *  Constant: '<S126>/Constant1'
       *  RelationalOperator: '<S129>/UpperRelop'
       *  Sum: '<S126>/Subtract1'
       */
      if (!(rtb_Init_g < (-1.0 - rtb_Switch2_p2))) {
        rtb_Integral_d = rtb_Init_g;
      }

      /* End of Switch: '<S129>/Switch' */
    }

    /* End of Switch: '<S129>/Switch2' */

    /* Saturate: '<S126>/Saturation1' */
    if (rtb_Integral_d > 0.1) {
      rtb_Integral_d = 0.1;
    } else if (rtb_Integral_d < -0.1) {
      rtb_Integral_d = -0.1;
    }

    /* End of Saturate: '<S126>/Saturation1' */
  } else {
    rtb_Integral_d = 0.0;
  }

  /* End of Switch: '<S126>/Switch' */

  /* Switch: '<S92>/Switch2' incorporates:
   *  Logic: '<S92>/Logical Operator1'
   */
  if (rtb_Is_Absolute_Steering) {
    /* Sum: '<S126>/Add1' */
    rtb_Add_bn = rtb_Switch2_p2 + rtb_Integral_d;

    /* Saturate: '<S126>/Saturation2' */
    if (rtb_Add_bn > 1.0) {
      /* Switch: '<S92>/Switch2' */
      Robot_Control_B.Transfer_Motor_PID_DC = 1.0;
    } else if (rtb_Add_bn < -1.0) {
      /* Switch: '<S92>/Switch2' */
      Robot_Control_B.Transfer_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S92>/Switch2' */
      Robot_Control_B.Transfer_Motor_PID_DC = rtb_Add_bn;
    }

    /* End of Saturate: '<S126>/Saturation2' */
  } else {
    /* Switch: '<S92>/Switch2' incorporates:
     *  Constant: '<S92>/Constant3'
     */
    Robot_Control_B.Transfer_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S92>/Switch2' */

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S11>/Constant'
   */
  Robot_Control_B.Feeder_Motor_PID_DC = Robot_Control_B.Desired_Feeder_Speed *
    Feeder_Motor_Gain_FF;

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
    Robot_Control_Y.Transfer_Motor_DC = Robot_Control_B.Transfer_Motor_PID_DC;

    /* Outport: '<Root>/Desired_Hood_Enable' incorporates:
     *  Constant: '<S9>/Constant8'
     */
    Robot_Control_Y.Desired_Hood_Enable = true;

    /* Outport: '<Root>/Feeder_Motor_DC' */
    Robot_Control_Y.Feeder_Motor_DC = Robot_Control_B.Feeder_Motor_PID_DC;
    rtb_Switch2_p2 = Robot_Control_B.Desired_Hood_Pos_Shoot;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Switch: '<S9>/Switch5'
   */
  if (rtb_Switch2_p2 > Hood_Servo_Pos_Max) {
    rtb_Switch2_p2 = Hood_Servo_Pos_Max;
  } else if (rtb_Switch2_p2 < Hood_Servo_Pos_Min) {
    rtb_Switch2_p2 = Hood_Servo_Pos_Min;
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
  if (rtb_Switch2_p2 > Hood_Servo_Rate_Limit_Inc) {
    rtb_Switch2_p2 = Hood_Servo_Rate_Limit_Inc;
  } else if (rtb_Switch2_p2 < Hood_Servo_Rate_Limit_Dec) {
    /* Switch: '<S83>/Switch' incorporates:
     *  Constant: '<S81>/Constant1'
     */
    rtb_Switch2_p2 = Hood_Servo_Rate_Limit_Dec;
  }

  /* End of Switch: '<S83>/Switch2' */

  /* Sum: '<S82>/Sum' */
  Robot_Control_B.Estimated_Hood_Pos = rtb_Switch2_p2 + rtb_Init_g;

  /* Logic: '<S89>/Logical Operator1' incorporates:
   *  Constant: '<S120>/Constant'
   *  RelationalOperator: '<S120>/Compare'
   */
  rtb_Is_Absolute_Steering = !(Robot_Control_B.Desired_Shooter_Speed == 0.0);

  /* Sum: '<S121>/Sum' incorporates:
   *  Sum: '<S89>/Subtract'
   */
  rtb_Error_d = Robot_Control_B.Desired_Shooter_Speed -
    Robot_Control_B.Measured_Shooter_Speed_Max;

  /* Sum: '<S123>/Sum1' incorporates:
   *  Constant: '<S121>/Constant2'
   *  Product: '<S123>/Product'
   *  Sum: '<S121>/Sum'
   *  Sum: '<S123>/Sum'
   *  UnitDelay: '<S123>/Unit Delay1'
   */
  rtb_Switch2_p2 = ((rtb_Error_d - Robot_Control_DW.UnitDelay1_DSTATE_d) * 0.1)
    + Robot_Control_DW.UnitDelay1_DSTATE_d;

  /* Product: '<S121>/Product' incorporates:
   *  Constant: '<S121>/Constant3'
   */
  rtb_Init_g = rtb_Switch2_p2 * Shooter_Motor_Gain_D;

  /* Sum: '<S122>/Diff' incorporates:
   *  UnitDelay: '<S122>/UD'
   *
   * Block description for '<S122>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S122>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_bn = rtb_Init_g - Robot_Control_DW.UD_DSTATE_ml;

  /* Saturate: '<S121>/Saturation' */
  if (rtb_Add_bn > 0.1) {
    rtb_Add_bn = 0.1;
  } else if (rtb_Add_bn < -0.1) {
    rtb_Add_bn = -0.1;
  }

  /* Sum: '<S121>/Add' incorporates:
   *  Gain: '<S121>/Gain'
   *  Gain: '<S121>/Gain1'
   *  Saturate: '<S121>/Saturation'
   *  Sum: '<S121>/Sum'
   */
  rtb_Add_bn += (Shooter_Motor_Gain_FF * Robot_Control_B.Desired_Shooter_Speed)
    + (Shooter_Motor_Gain_P * rtb_Error_d);

  /* Switch: '<S89>/Switch1' incorporates:
   *  Abs: '<S89>/Abs'
   *  Constant: '<S89>/Constant1'
   *  Constant: '<S89>/Constant2'
   *  Logic: '<S89>/Logical Operator'
   *  Logic: '<S89>/Logical Operator1'
   *  RelationalOperator: '<S89>/LessThan'
   *  UnitDelay: '<S89>/Unit Delay'
   */
  if ((fabs(rtb_Error_d) < Shooter_Error_Integral_Enable) &&
      rtb_Is_Absolute_Steering) {
    rtb_Is_Absolute_Translation_g = true;
  } else {
    rtb_Is_Absolute_Translation_g = (rtb_Is_Absolute_Steering &&
      (Robot_Control_DW.UnitDelay_DSTATE_db));
  }

  /* End of Switch: '<S89>/Switch1' */

  /* Switch: '<S121>/Switch' incorporates:
   *  Constant: '<S121>/Constant4'
   */
  if (rtb_Is_Absolute_Translation_g) {
    /* Sum: '<S121>/Sum2' incorporates:
     *  Gain: '<S121>/Gain2'
     *  Sum: '<S121>/Sum'
     *  UnitDelay: '<S121>/Unit Delay'
     */
    rtb_Error_d = (Shooter_Motor_Gain_I * rtb_Error_d) +
      Robot_Control_DW.UnitDelay_DSTATE_di;

    /* Sum: '<S121>/Subtract' incorporates:
     *  Constant: '<S121>/Constant'
     */
    rtb_Switch2_f = 1.0 - rtb_Add_bn;

    /* Switch: '<S124>/Switch2' incorporates:
     *  Constant: '<S121>/Constant'
     *  RelationalOperator: '<S124>/LowerRelop1'
     *  Sum: '<S121>/Subtract'
     */
    if (!(rtb_Error_d > (1.0 - rtb_Add_bn))) {
      /* Sum: '<S121>/Subtract1' incorporates:
       *  Constant: '<S121>/Constant1'
       */
      rtb_Switch2_f = -1.0 - rtb_Add_bn;

      /* Switch: '<S124>/Switch' incorporates:
       *  Constant: '<S121>/Constant1'
       *  RelationalOperator: '<S124>/UpperRelop'
       *  Sum: '<S121>/Subtract1'
       */
      if (!(rtb_Error_d < (-1.0 - rtb_Add_bn))) {
        rtb_Switch2_f = rtb_Error_d;
      }

      /* End of Switch: '<S124>/Switch' */
    }

    /* End of Switch: '<S124>/Switch2' */

    /* Saturate: '<S121>/Saturation1' */
    if (rtb_Switch2_f > 0.1) {
      rtb_Error_d = 0.1;
    } else if (rtb_Switch2_f < -0.1) {
      rtb_Error_d = -0.1;
    } else {
      rtb_Error_d = rtb_Switch2_f;
    }

    /* End of Saturate: '<S121>/Saturation1' */
  } else {
    rtb_Error_d = 0.0;
  }

  /* End of Switch: '<S121>/Switch' */

  /* Switch: '<S89>/Switch2' incorporates:
   *  Logic: '<S89>/Logical Operator1'
   */
  if (rtb_Is_Absolute_Steering) {
    /* Sum: '<S121>/Add1' */
    rtb_Add_bn += rtb_Error_d;

    /* Saturate: '<S121>/Saturation2' */
    if (rtb_Add_bn > 1.0) {
      /* Switch: '<S89>/Switch2' */
      Robot_Control_B.Shooter_Motor_PID_DC = 1.0;
    } else if (rtb_Add_bn < -1.0) {
      /* Switch: '<S89>/Switch2' */
      Robot_Control_B.Shooter_Motor_PID_DC = -1.0;
    } else {
      /* Switch: '<S89>/Switch2' */
      Robot_Control_B.Shooter_Motor_PID_DC = rtb_Add_bn;
    }

    /* End of Saturate: '<S121>/Saturation2' */
  } else {
    /* Switch: '<S89>/Switch2' incorporates:
     *  Constant: '<S89>/Constant3'
     */
    Robot_Control_B.Shooter_Motor_PID_DC = 0.0;
  }

  /* End of Switch: '<S89>/Switch2' */

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
    Robot_Control_Y.Shooter_Motor_DC_Left = Robot_Control_B.Shooter_Motor_PID_DC;

    /* Outport: '<Root>/Shooter_Motor_DC_Center' */
    Robot_Control_Y.Shooter_Motor_DC_Center =
      Robot_Control_B.Shooter_Motor_PID_DC;

    /* Outport: '<Root>/Shooter_Motor_DC_Right' */
    Robot_Control_Y.Shooter_Motor_DC_Right =
      Robot_Control_B.Shooter_Motor_PID_DC;
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

  /* Update for UnitDelay: '<S291>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S291>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay generated from: '<S11>/Unit Delay' */
  Robot_Control_DW.UnitDelay_1_DSTATE =
    Robot_Control_B.Desired_Shoot_Gyro_Angle_rad;

  /* Update for UnitDelay generated from: '<S11>/Unit Delay' */
  Robot_Control_DW.UnitDelay_4_DSTATE = Robot_Control_B.Allowed_Shoot_Gyro_Error;

  /* Update for UnitDelay generated from: '<S11>/Unit Delay' */
  Robot_Control_DW.UnitDelay_2_DSTATE = Robot_Control_B.Desired_Shooter_Speed;

  /* Update for UnitDelay generated from: '<S11>/Unit Delay' */
  Robot_Control_DW.UnitDelay_3_DSTATE = Robot_Control_B.Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S86>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_c = Robot_Control_B.Desired_Hood_Pos_Shoot;

  /* Update for UnitDelay: '<S313>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S312>/UD'
   *
   * Block description for '<S312>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Add_h5;

  /* Update for UnitDelay: '<S310>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Subtract_c3;

  /* Update for UnitDelay: '<S293>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S308>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S308>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S308>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S292>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S301>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S301>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S301>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S267>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch1;

  /* Update for UnitDelay: '<S266>/UD'
   *
   * Block description for '<S266>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2;

  /* Update for UnitDelay: '<S260>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lw = 0.0;

  /* Update for UnitDelay: '<S204>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Hypot_pi;

  /* Update for UnitDelay: '<S203>/UD'
   *
   * Block description for '<S203>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Init;

  /* Update for UnitDelay: '<S197>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S215>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_fg;

  /* Update for UnitDelay: '<S214>/UD'
   *
   * Block description for '<S214>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_dp;

  /* Update for UnitDelay: '<S200>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Sum2_e;

  /* Update for UnitDelay: '<S225>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_fn;

  /* Update for UnitDelay: '<S224>/UD'
   *
   * Block description for '<S224>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S218>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S236>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Switch2_m;

  /* Update for UnitDelay: '<S235>/UD'
   *
   * Block description for '<S235>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_hi;

  /* Update for UnitDelay: '<S221>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_kg;

  /* Update for UnitDelay: '<S246>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_k;

  /* Update for UnitDelay: '<S245>/UD'
   *
   * Block description for '<S245>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S239>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S257>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S256>/UD'
   *
   * Block description for '<S256>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Add2_idx_0;

  /* Update for UnitDelay: '<S242>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Integral_ga;

  /* Update for UnitDelay: '<S278>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S277>/UD'
   *
   * Block description for '<S277>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add2_idx_1;

  /* Update for UnitDelay: '<S263>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Integral_bj;

  /* Update for UnitDelay: '<S128>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_ji = rtb_Add_jp;

  /* Update for UnitDelay: '<S127>/UD'
   *
   * Block description for '<S127>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_a = rtb_Product_lo;

  /* Update for UnitDelay: '<S126>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_kz = rtb_Integral_d;

  /* Update for UnitDelay: '<S92>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ki = rtb_AND1_c;

  /* Update for UnitDelay: '<S84>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S84>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 0U;

  /* Update for UnitDelay: '<S123>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_d = rtb_Switch2_p2;

  /* Update for UnitDelay: '<S122>/UD'
   *
   * Block description for '<S122>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_ml = rtb_Init_g;

  /* Update for UnitDelay: '<S121>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_di = rtb_Error_d;

  /* Update for UnitDelay: '<S89>/Unit Delay' */
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

  /* InitializeConditions for UnitDelay: '<S291>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S308>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S301>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_f = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S362>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S12>/Spline Path Following Enabled' */
  /* Start for If: '<S136>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S132>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S136>/Robot_Index_Is_Valid' */
  /* Start for If: '<S139>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S139>/Circle_Check_Valid' */
  /* Start for If: '<S141>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S139>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S136>/Robot_Index_Is_Valid' */
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
