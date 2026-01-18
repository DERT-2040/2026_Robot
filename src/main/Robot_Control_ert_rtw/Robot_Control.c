/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.432
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jan  3 07:03:36 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Robot_Control.h"
#include "rtwtypes.h"
#include "rt_powd_snf.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rt_hypotd_snf.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "LookUp_real_T_real_T.h"
#include "look1_binlcpw.h"
#include "Robot_Control_private.h"

/* Named constants for Chart: '<S8>/Chart' */
#define Robot_Control_IN_Disabled      ((uint8_T)1U)
#define Robot_Control_IN_Not_Disabled  ((uint8_T)2U)

/* Exported block parameters */
real_T Boost_Trigger_Decreasing_Limit = -0.28;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S318>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S314>/Constant'
                                        *   '<S314>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.5;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S318>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S314>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S156>/Constant3'
                                        *   '<S177>/Constant3'
                                        *   '<S198>/Constant3'
                                        *   '<S219>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S156>/Constant2'
                                   *   '<S177>/Constant2'
                                   *   '<S198>/Constant2'
                                   *   '<S219>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S156>/Saturation'
                                        *   '<S177>/Saturation'
                                        *   '<S198>/Saturation'
                                        *   '<S219>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S156>/Saturation'
                                        *   '<S177>/Saturation'
                                        *   '<S198>/Saturation'
                                        *   '<S219>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S156>/Gain'
                                            *   '<S177>/Gain'
                                            *   '<S198>/Gain'
                                            *   '<S219>/Gain'
                                            */
real_T Drive_Motor_Control_I = 1.0E-6; /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S156>/Gain2'
                                        *   '<S177>/Gain2'
                                        *   '<S198>/Gain2'
                                        *   '<S219>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = -0.03;/* Variable: Drive_Motor_Control_I_LL
                                         * Referenced by:
                                         *   '<S156>/Saturation1'
                                         *   '<S177>/Saturation1'
                                         *   '<S198>/Saturation1'
                                         *   '<S219>/Saturation1'
                                         */
real_T Drive_Motor_Control_I_UL = 0.03;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S156>/Saturation1'
                                        *   '<S177>/Saturation1'
                                        *   '<S198>/Saturation1'
                                        *   '<S219>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S156>/Gain1'
                                        *   '<S177>/Gain1'
                                        *   '<S198>/Gain1'
                                        *   '<S219>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S161>/Constant'
                            *   '<S182>/Constant'
                            *   '<S203>/Constant'
                            *   '<S224>/Constant'
                            */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S304>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S304>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S6>/Constant2'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S303>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S301>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S303>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S304>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S304>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S145>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S145>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S92>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S105>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S145>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S252>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S252>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S252>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S252>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S252>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S252>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S269>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S269>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S269>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S269>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S268>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S269>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S269>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S269>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S269>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S269>/Constant1'
                                   *   '<S269>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S269>/Constant'
                                   *   '<S269>/Saturation2'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S159>/Constant3'
                                        *   '<S180>/Constant3'
                                        *   '<S201>/Constant3'
                                        *   '<S222>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S159>/Constant2'
                                *   '<S180>/Constant2'
                                *   '<S201>/Constant2'
                                *   '<S222>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S159>/Saturation'
                                           *   '<S180>/Saturation'
                                           *   '<S201>/Saturation'
                                           *   '<S222>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S159>/Saturation'
                                          *   '<S180>/Saturation'
                                          *   '<S201>/Saturation'
                                          *   '<S222>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S159>/Gain2'
                                         *   '<S180>/Gain2'
                                         *   '<S201>/Gain2'
                                         *   '<S222>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S159>/Saturation1'
                                             *   '<S180>/Saturation1'
                                             *   '<S201>/Saturation1'
                                             *   '<S222>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S159>/Saturation1'
                                            *   '<S180>/Saturation1'
                                            *   '<S201>/Saturation1'
                                            *   '<S222>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S159>/Gain1'
                                        *   '<S180>/Gain1'
                                        *   '<S201>/Gain1'
                                        *   '<S222>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S251>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S251>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S251>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S251>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S251>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S251>/Constant3'
                                */
real_T Steering_Relative_Gain = 5.0;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S303>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S303>/Constant1'
                                        */
real_T TEST_Swerve_Mode_Override_Flag = 0.0;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S302>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S302>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S302>/Constant7'
                                           */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S239>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S239>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S239>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S239>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S239>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S239>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S304>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S303>/Dead Zone'
                                        *   '<S304>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S303>/Dead Zone'
                                        *   '<S304>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S13>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S301>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S301>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S301>/Constant4'
                                        */
real_T Vision_Object_X_Offset = 0.0;   /* Variable: Vision_Object_X_Offset
                                        * Referenced by: '<S13>/Constant4'
                                        */
real_T Vision_Object_Y_Offset = 0.0;   /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S13>/Constant8'
                                        */
real_T Vision_Tag_Angle_Offset = 0.0;  /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S13>/Constant5'
                                        */
real_T Vision_Tag_Target_Angle = 0.0;  /* Variable: Vision_Tag_Target_Angle
                                        * Referenced by: '<S301>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S301>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S301>/Constant5'
                                        */
real_T Vision_Tag_X_Offset = 0.0;      /* Variable: Vision_Tag_X_Offset
                                        * Referenced by: '<S13>/Constant3'
                                        */
real_T Vision_Tag_Y_Offset = 0.0;      /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S13>/Constant7'
                                        */
uint8_T TEST_Pipeline = 0U;            /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S12>/Constant22'
                                        *   '<S301>/Constant11'
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
  real_T rtb_Minus_n[2];
  real_T rtb_Reshapey[2];
  real_T rtb_Add2_idx_0;
  real_T rtb_Add2_idx_1;
  real_T rtb_Add_fn;
  real_T rtb_Add_h5;
  real_T rtb_Add_jp;
  real_T rtb_Add_k;
  real_T rtb_Hypot;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Init;
  real_T rtb_Integral_hv;
  real_T rtb_Merge1;
  real_T rtb_Modulation_Drv;
  real_T rtb_Optimized_Module_Angle_p;
  real_T rtb_Product_hi;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_a;
  real_T rtb_Subtract1_la;
  real_T rtb_Subtract_e;
  real_T rtb_Switch1;
  real_T rtb_Switch2;
  real_T rtb_Switch2_a;
  real_T rtb_Switch2_e;
  real_T rtb_Switch2_k;
  real_T rtb_Switch2_nt;
  real_T rtb_Switch2_pt;
  real_T rtb_uDLookupTable;
  int32_T tmp;
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T rtb_Desired_Pipeline;
  boolean_T rtb_AND1;
  boolean_T rtb_AND4;
  boolean_T rtb_Compare_a;
  boolean_T rtb_Disable_Wheels;
  boolean_T rtb_Enable_Wheels;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation_g;
  boolean_T rtb_Reset_Wheel_Offsets;
  boolean_T rtb_Swerve_Motors_Disabled;

  /* RelationalOperator: '<S31>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *  UnitDelay: '<S31>/Delay Input1'
   *
   * Block description for '<S31>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Joystick_Left_B11 >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S32>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *  UnitDelay: '<S32>/Delay Input1'
   *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets =
    (Robot_Control_U.Joystick_Left_B12 > Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S33>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *  UnitDelay: '<S33>/Delay Input1'
   *
   * Block description for '<S33>/Delay Input1':
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

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
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

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
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

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   *  Inport: '<Root>/Joystick_Right_POV'
   */
  Robot_Control_B.Face_Away_Driver = (Robot_Control_U.Joystick_Right_POV == 0.0);

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<S13>/Constant3'
   *  Gain: '<S13>/Convert meters to inches1'
   *  Inport: '<Root>/Vision_c1_AprilTag_X_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_X_m) + Vision_Tag_X_Offset;

  /* Sum: '<S13>/Add1' incorporates:
   *  Constant: '<S13>/Constant7'
   *  Gain: '<S13>/Convert meters to inches'
   *  Inport: '<Root>/Vision_c1_AprilTag_Y_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_Y_m) + Vision_Tag_Y_Offset;

  /* Sum: '<S13>/Add2' incorporates:
   *  Constant: '<S13>/Constant5'
   *  Inport: '<Root>/Vision_c1_AprilTag_Yaw_deg'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_AprilTag_Yaw_deg + Vision_Tag_Angle_Offset;

  /* If: '<S330>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S330>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S333>/Action Port'
     */
    /* Product: '<S333>/Product' incorporates:
     *  Constant: '<S333>/Constant1'
     *  Constant: '<S333>/Constant2'
     *  Math: '<S333>/Math Function'
     */
    rtb_Subtract_e = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S330>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S330>/Subsystem' incorporates:
     *  ActionPort: '<S334>/Action Port'
     */
    /* SignalConversion generated from: '<S334>/Out1' incorporates:
     *  Constant: '<S334>/Constant'
     */
    rtb_Subtract_e = 0.0;

    /* End of Outputs for SubSystem: '<S330>/Subsystem' */
  }

  /* End of If: '<S330>/If' */

  /* Gain: '<S331>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Sin4 = 0.017453292519943295 * Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S13>/Add3' incorporates:
   *  Constant: '<S13>/Constant4'
   *  Fcn: '<S332>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Subtract_e * cos(rtb_Sin4))
    + Vision_Object_X_Offset;

  /* Sum: '<S13>/Add4' incorporates:
   *  Constant: '<S13>/Constant8'
   *  Fcn: '<S332>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Subtract_e * sin(rtb_Sin4))
    + Vision_Object_Y_Offset;

  /* Sum: '<S13>/Add5' incorporates:
   *  Constant: '<S13>/Constant6'
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_Object_Hor_deg + Vision_Object_Angle_Offset;

  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   *  Inport: '<Root>/Joystick_Left_B3'
   */
  Robot_Control_B.Align_Left = (Robot_Control_U.Joystick_Left_B3 != 0.0);

  /* RelationalOperator: '<S25>/Compare' incorporates:
   *  Constant: '<S25>/Constant'
   *  Inport: '<Root>/Joystick_Left_B4'
   */
  Robot_Control_B.Align_Right = (Robot_Control_U.Joystick_Left_B4 != 0.0);

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Robot_Control_DW.SwitchCase_ActiveSubsystem;
  rtb_Add_jp = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_jp)) || (rtIsInf(rtb_Add_jp))) {
    rtb_Add_jp = 0.0;
  } else {
    rtb_Add_jp = fmod(rtb_Add_jp, 4.294967296E+9);
  }

  switch ((rtb_Add_jp < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_jp)))) :
          ((int32_T)((uint32_T)rtb_Add_jp))) {
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

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S14>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S7>/Merge1' incorporates:
     *  Constant: '<S14>/Constant1'
     *  SignalConversion generated from: '<S2>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S14>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S14>/Constant2'
     *  SignalConversion generated from: '<S2>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S14>/Constant7'
     *  SignalConversion generated from: '<S2>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge3' incorporates:
     *  Constant: '<S14>/Constant3'
     *  SignalConversion generated from: '<S2>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S14>/Constant9'
     *  SignalConversion generated from: '<S2>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S7>/Merge4' incorporates:
     *  Constant: '<S14>/Constant4'
     *  SignalConversion generated from: '<S2>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* Merge: '<S7>/Merge23' incorporates:
     *  Constant: '<S14>/Constant10'
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

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S303>/Unit Delay1'
       *  UnitDelay: '<S303>/Unit Delay2'
       *  UnitDelay: '<S303>/Unit Delay3'
       *  UnitDelay: '<S303>/Unit Delay4'
       *  UnitDelay: '<S306>/Delay Input1'
       *  UnitDelay: '<S307>/Delay Input1'
       *  UnitDelay: '<S308>/Delay Input1'
       *  UnitDelay: '<S309>/Delay Input1'
       *  UnitDelay: '<S311>/Delay Input1'
       *  UnitDelay: '<S317>/Unit Delay'
       *  UnitDelay: '<S317>/Unit Delay1'
       *  UnitDelay: '<S321>/FixPt Unit Delay1'
       *  UnitDelay: '<S321>/FixPt Unit Delay2'
       *
       * Block description for '<S306>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S307>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S308>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S309>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S311>/Delay Input1':
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
     *  ActionPort: '<S11>/Action Port'
     */
    /* Switch: '<S301>/Switch4' incorporates:
     *  Constant: '<S326>/Constant'
     *  Constant: '<S329>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S326>/Compare'
     *  RelationalOperator: '<S329>/Compare'
     *  Switch: '<S301>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S301>/Switch4' incorporates:
       *  Constant: '<S301>/Constant8'
       *  Sum: '<S301>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S301>/Switch5' incorporates:
       *  Constant: '<S301>/Constant7'
       *  Gain: '<S301>/Gain'
       *  Sum: '<S301>/Subtract5'
       *  Switch: '<S301>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S301>/Switch4' incorporates:
       *  Constant: '<S301>/Constant6'
       *  Switch: '<S301>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S301>/Switch4' */

    /* Logic: '<S301>/Logical Operator1' incorporates:
     *  Inport: '<Root>/Vision_c1_AprilTag_Valid'
     *  Inport: '<Root>/Vision_c1_Object_Valid'
     *  Logic: '<S301>/Logical Operator2'
     *  Logic: '<S301>/Logical Operator3'
     */
    Robot_Control_B.Relative_Enable = (((Robot_Control_B.Align_Left) &&
      (Robot_Control_U.Vision_c1_AprilTag_Valid)) ||
      ((Robot_Control_B.Align_Right) && (Robot_Control_U.Vision_c1_Object_Valid)));

    /* Switch: '<S303>/Switch' incorporates:
     *  Constant: '<S303>/Constant9'
     */
    if (Robot_Control_B.Relative_Enable) {
      /* Product: '<S303>/Product2' incorporates:
       *  Constant: '<S303>/Constant4'
       */
      rtb_Add_h5 = Robot_Control_B.Relative_Error_Angle *
        Relative_Steering_Error_Angle_Gain;

      /* Switch: '<S313>/Switch2' incorporates:
       *  Constant: '<S303>/Constant10'
       *  RelationalOperator: '<S313>/LowerRelop1'
       *  RelationalOperator: '<S313>/UpperRelop'
       *  Switch: '<S313>/Switch'
       *  UnaryMinus: '<S303>/Unary Minus'
       */
      if (rtb_Add_h5 > Relative_Steering_Speed_Max) {
        rtb_Add_h5 = Relative_Steering_Speed_Max;
      } else if (rtb_Add_h5 < (-Relative_Steering_Speed_Max)) {
        /* Switch: '<S313>/Switch' incorporates:
         *  UnaryMinus: '<S303>/Unary Minus'
         */
        rtb_Add_h5 = -Relative_Steering_Speed_Max;
      }

      /* End of Switch: '<S313>/Switch2' */
    } else {
      rtb_Add_h5 = 0.0;
    }

    /* End of Switch: '<S303>/Switch' */

    /* DeadZone: '<S303>/Dead Zone' */
    if (Robot_Control_B.Steer_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Add_jp = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Steer_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Add_jp = 0.0;
    } else {
      rtb_Add_jp = Robot_Control_B.Steer_Joystick_Z - Twist_Deadzone_neg;
    }

    /* Sum: '<S303>/Add' incorporates:
     *  Constant: '<S303>/Constant'
     *  Constant: '<S303>/Constant1'
     *  DeadZone: '<S303>/Dead Zone'
     *  Lookup_n-D: '<S303>/Modulation_Str_Y_Rel'
     *  Product: '<S303>/Product'
     *  Product: '<S303>/Product1'
     *  SignalConversion: '<S4>/Signal Copy5'
     */
    rtb_Add_h5 += (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                   Steering_Relative_Gain) + (rtb_Add_jp * Steering_Twist_Gain);

    /* RelationalOperator: '<S305>/Compare' incorporates:
     *  Constant: '<S305>/Constant'
     */
    rtb_Compare_a = (rtb_Add_h5 == 0.0);

    /* Logic: '<S303>/AND2' incorporates:
     *  RelationalOperator: '<S306>/FixPt Relational Operator'
     *  RelationalOperator: '<S307>/FixPt Relational Operator'
     *  RelationalOperator: '<S308>/FixPt Relational Operator'
     *  RelationalOperator: '<S309>/FixPt Relational Operator'
     *  UnitDelay: '<S306>/Delay Input1'
     *  UnitDelay: '<S307>/Delay Input1'
     *  UnitDelay: '<S308>/Delay Input1'
     *  UnitDelay: '<S309>/Delay Input1'
     *
     * Block description for '<S306>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S307>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S308>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S309>/Delay Input1':
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

    /* Logic: '<S303>/AND1' incorporates:
     *  Logic: '<S303>/AND3'
     *  UnitDelay: '<S303>/Unit Delay2'
     */
    rtb_AND1 = (rtb_Compare_a && (rtb_Enable_Wheels ||
      (Robot_Control_DW.UnitDelay2_DSTATE)));

    /* Logic: '<S303>/AND4' incorporates:
     *  Logic: '<S303>/AND8'
     *  UnitDelay: '<S303>/Unit Delay4'
     */
    rtb_AND4 = ((rtb_Compare_a && (!rtb_Enable_Wheels)) &&
                (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S303>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1 || rtb_AND4);

    /* Switch: '<S303>/Switch8' incorporates:
     *  Constant: '<S312>/Constant'
     *  Logic: '<S303>/AND9'
     *  RelationalOperator: '<S311>/FixPt Relational Operator'
     *  RelationalOperator: '<S312>/Compare'
     *  UnitDelay: '<S311>/Delay Input1'
     *  UnitDelay: '<S8>/Unit Delay'
     *
     * Block description for '<S311>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)rtb_Compare_a)
          > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_j))) ||
        (Robot_Control_B.Active_GameState != 2)) {
      /* Switch: '<S303>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S303>/Switch8' incorporates:
       *  UnitDelay: '<S303>/Unit Delay3'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch =
        Robot_Control_DW.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S303>/Switch8' */

    /* Switch: '<S303>/Switch4' incorporates:
     *  Constant: '<S303>/Constant5'
     *  Switch: '<S303>/Switch1'
     *  Switch: '<S303>/Switch5'
     *  Switch: '<S303>/Switch6'
     *  Switch: '<S303>/Switch7'
     */
    if (Robot_Control_B.Face_Away_Driver) {
      rtb_Subtract_e = 0.0;
    } else if (Robot_Control_B.Face_Left_Driver) {
      /* Switch: '<S303>/Switch5' incorporates:
       *  Constant: '<S303>/Constant6'
       */
      rtb_Subtract_e = 1.5707963267948966;
    } else if (Robot_Control_B.Face_Toward_Driver) {
      /* Switch: '<S303>/Switch6' incorporates:
       *  Constant: '<S303>/Constant7'
       *  Switch: '<S303>/Switch5'
       */
      rtb_Subtract_e = 3.1415926535897931;
    } else if (Robot_Control_B.Face_Right_Driver) {
      /* Switch: '<S303>/Switch7' incorporates:
       *  Constant: '<S303>/Constant8'
       *  Switch: '<S303>/Switch5'
       *  Switch: '<S303>/Switch6'
       */
      rtb_Subtract_e = 4.71238898038469;
    } else if (rtb_AND4) {
      /* Switch: '<S303>/Switch1' incorporates:
       *  Constant: '<S11>/Constant10'
       *  Switch: '<S303>/Switch5'
       *  Switch: '<S303>/Switch6'
       *  Switch: '<S303>/Switch7'
       */
      rtb_Subtract_e = 0.0;
    } else {
      /* Switch: '<S303>/Switch6' incorporates:
       *  Switch: '<S303>/Switch5'
       *  Switch: '<S303>/Switch7'
       *  UnitDelay: '<S303>/Unit Delay1'
       */
      rtb_Subtract_e = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S303>/Switch4' */

    /* Switch: '<S303>/Switch2' incorporates:
     *  Switch: '<S303>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S303>/Switch2' incorporates:
       *  Constant: '<S303>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S303>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Subtract_e;
    } else {
      /* Switch: '<S303>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S303>/Switch3' incorporates:
       *  Constant: '<S303>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S303>/Switch2' */

    /* Merge: '<S7>/Merge1' incorporates:
     *  Sum: '<S303>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Switch: '<S302>/Switch1' incorporates:
     *  Constant: '<S302>/Constant5'
     *  Constant: '<S302>/Constant8'
     *  DataTypeConversion: '<S302>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_Compare_a;
    }

    /* End of Switch: '<S302>/Switch1' */

    /* Lookup_n-D: '<S304>/Modulation_Drv' incorporates:
     *  Math: '<S304>/Magnitude'
     */
    rtb_Modulation_Drv = look1_binlcpw(rt_hypotd_snf
      (Robot_Control_B.Drive_Joystick_X, Robot_Control_B.Drive_Joystick_Y),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S315>/Compare' incorporates:
     *  Constant: '<S315>/Constant'
     */
    rtb_Swerve_Motors_Disabled = (rtb_Modulation_Drv == 0.0);

    /* DeadZone: '<S304>/Dead Zone' */
    if (Robot_Control_B.Drive_Joystick_Z > Twist_Deadzone_pos) {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_pos;
    } else if (Robot_Control_B.Drive_Joystick_Z >= Twist_Deadzone_neg) {
      rtb_Sin4 = 0.0;
    } else {
      rtb_Sin4 = Robot_Control_B.Drive_Joystick_Z - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S304>/Dead Zone' */

    /* Logic: '<S304>/Logical Operator' incorporates:
     *  Constant: '<S316>/Constant'
     *  RelationalOperator: '<S316>/Compare'
     */
    rtb_Enable_Wheels = ((rtb_Sin4 != 0.0) && rtb_Swerve_Motors_Disabled);

    /* Logic: '<S304>/Logical Operator1' */
    rtb_Disable_Wheels = ((Robot_Control_B.Relative_Enable) || rtb_Enable_Wheels);

    /* Switch: '<S302>/Switch' incorporates:
     *  Constant: '<S302>/Constant5'
     *  Constant: '<S302>/Constant7'
     *  DataTypeConversion: '<S302>/Data Type Conversion'
     *  Switch: '<S304>/Switch7'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Translation_g = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Is_Absolute_Translation_g = !rtb_Disable_Wheels;
    }

    /* End of Switch: '<S302>/Switch' */

    /* Switch: '<S301>/Switch2' incorporates:
     *  Constant: '<S301>/Constant2'
     *  Constant: '<S325>/Constant'
     *  Constant: '<S328>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S325>/Compare'
     *  RelationalOperator: '<S328>/Compare'
     *  Sum: '<S301>/Subtract'
     *  Switch: '<S301>/Switch'
     *  Switch: '<S301>/Switch1'
     *  Switch: '<S301>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S301>/Switch2' incorporates:
       *  Constant: '<S301>/Constant5'
       *  Sum: '<S301>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Switch2_k = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S301>/Switch2' incorporates:
       *  Constant: '<S301>/Constant4'
       *  Sum: '<S301>/Subtract2'
       *  Switch: '<S301>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S301>/Switch1' incorporates:
       *  Constant: '<S301>/Constant1'
       *  Sum: '<S301>/Subtract3'
       */
      rtb_Switch2_k = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S301>/Switch2' incorporates:
       *  Constant: '<S301>/Constant3'
       *  Switch: '<S301>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S301>/Switch1' incorporates:
       *  Constant: '<S301>/Constant'
       */
      rtb_Switch2_k = 0.0;
    }

    /* End of Switch: '<S301>/Switch2' */

    /* UnaryMinus: '<S301>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Switch2_k;

    /* Switch: '<S317>/Switch1' incorporates:
     *  Constant: '<S322>/Constant'
     *  Constant: '<S323>/Constant'
     *  Logic: '<S317>/AND'
     *  RelationalOperator: '<S322>/Compare'
     *  RelationalOperator: '<S323>/Compare'
     *  Switch: '<S317>/Switch2'
     *  UnitDelay: '<S317>/Unit Delay'
     *  UnitDelay: '<S317>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Switch1 = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1 = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S317>/Switch1' */

    /* Switch: '<S304>/Switch9' incorporates:
     *  Switch: '<S304>/Switch4'
     */
    if (rtb_Disable_Wheels) {
      /* Switch: '<S304>/Switch1' */
      if (rtb_Enable_Wheels) {
        /* Signum: '<S304>/Sign' */
        if (rtIsNaN(rtb_Sin4)) {
          rtb_Add_jp = (rtNaN);
        } else if (rtb_Sin4 < 0.0) {
          rtb_Add_jp = -1.0;
        } else {
          rtb_Add_jp = (rtb_Sin4 > 0.0);
        }

        /* Switch: '<S304>/Switch5' incorporates:
         *  Constant: '<S304>/Constant3'
         *  Constant: '<S304>/Constant4'
         */
        if (Robot_Control_B.Drive_Joystick_Z_Mode) {
          rtb_Add_k = -1.5707963267948966;
        } else {
          rtb_Add_k = 0.0;
        }

        /* Merge: '<S7>/Merge3' incorporates:
         *  Gain: '<S304>/Gain3'
         *  Signum: '<S304>/Sign'
         *  Sum: '<S304>/Add'
         *  Switch: '<S304>/Switch5'
         */
        Robot_Control_B.Translation_Angle = (3.1415926535897931 * rtb_Add_jp) +
          rtb_Add_k;
      } else {
        /* Merge: '<S7>/Merge3' incorporates:
         *  Trigonometry: '<S304>/Atan3'
         */
        Robot_Control_B.Translation_Angle = rt_atan2d_snf
          (Robot_Control_B.Relative_Error_Y, Robot_Control_B.Relative_Error_X);
      }

      /* End of Switch: '<S304>/Switch1' */
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Switch: '<S304>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S304>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S7>/Merge3' incorporates:
         *  Constant: '<S304>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S7>/Merge3' incorporates:
         *  Constant: '<S304>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.1415926535897931;
      }

      /* End of Switch: '<S304>/Switch6' */
    } else {
      /* Merge: '<S7>/Merge3' incorporates:
       *  Switch: '<S304>/Switch4'
       *  Trigonometry: '<S304>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1, rtb_Switch2);
    }

    /* End of Switch: '<S304>/Switch9' */

    /* Switch: '<S314>/Switch1' incorporates:
     *  Constant: '<S314>/Constant'
     *  Constant: '<S314>/Constant1'
     */
    if (Robot_Control_B.Is_Boosting) {
      rtb_Switch2_k = Boost_Trigger_High_Speed;
    } else {
      rtb_Switch2_k = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S314>/Switch1' */

    /* Switch: '<S321>/Init' incorporates:
     *  UnitDelay: '<S321>/FixPt Unit Delay1'
     *  UnitDelay: '<S321>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_k;
    } else {
      rtb_Init = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S321>/Init' */

    /* Sum: '<S319>/Sum1' */
    rtb_Switch2_k -= rtb_Init;

    /* Switch: '<S320>/Switch2' incorporates:
     *  Constant: '<S318>/Constant1'
     *  Constant: '<S318>/Constant3'
     *  RelationalOperator: '<S320>/LowerRelop1'
     *  RelationalOperator: '<S320>/UpperRelop'
     *  Switch: '<S320>/Switch'
     */
    if (rtb_Switch2_k > Boost_Trigger_Increasing_Limit) {
      rtb_Switch2_k = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Switch2_k < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S320>/Switch' incorporates:
       *  Constant: '<S318>/Constant1'
       */
      rtb_Switch2_k = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S320>/Switch2' */

    /* Sum: '<S319>/Sum' */
    rtb_Init += rtb_Switch2_k;

    /* Switch: '<S304>/Switch8' incorporates:
     *  Switch: '<S304>/Switch2'
     */
    if (rtb_Disable_Wheels) {
      /* Switch: '<S304>/Switch' */
      if (rtb_Enable_Wheels) {
        /* Merge: '<S7>/Merge4' incorporates:
         *  Gain: '<S304>/Gain'
         */
        Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Sin4;
      } else {
        /* Merge: '<S7>/Merge4' incorporates:
         *  Constant: '<S304>/Constant8'
         *  Gain: '<S304>/Gain1'
         *  Math: '<S304>/Magnitude2'
         *  MinMax: '<S304>/Min1'
         */
        Robot_Control_B.Translation_Speed = fmin(Relative_Translation_Speed_Max,
          Relative_Translation_Control_Gain * rt_hypotd_snf
          (Robot_Control_B.Relative_Error_X, Robot_Control_B.Relative_Error_Y));
      }

      /* End of Switch: '<S304>/Switch' */
    } else if (rtb_Swerve_Motors_Disabled) {
      /* Merge: '<S7>/Merge4' incorporates:
       *  Constant: '<S11>/Constant7'
       *  Constant: '<S11>/Constant8'
       *  Constant: '<S304>/Constant5'
       *  Gain: '<S304>/Gain2'
       *  Math: '<S304>/Magnitude1'
       *  MinMax: '<S304>/Min'
       *  Switch: '<S304>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S314>/Product' incorporates:
       *  Switch: '<S304>/Switch2'
       */
      rtb_Add_jp = rtb_Modulation_Drv * rtb_Init;

      /* Saturate: '<S314>/Saturation' incorporates:
       *  Switch: '<S304>/Switch2'
       */
      if (rtb_Add_jp > Boost_Trigger_High_Speed) {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_jp < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_jp;
      }

      /* End of Saturate: '<S314>/Saturation' */
    }

    /* End of Switch: '<S304>/Switch8' */

    /* Merge: '<S7>/Merge2' incorporates:
     *  SignalConversion: '<S303>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Add_h5;

    /* Switch: '<S301>/Switch6' incorporates:
     *  Constant: '<S301>/Constant11'
     *  Constant: '<S301>/Constant9'
     *  Switch: '<S301>/Switch7'
     */
    if (Robot_Control_B.Align_Left) {
      rtb_Desired_Pipeline = 0U;
    } else if (Robot_Control_B.Align_Right) {
      /* Switch: '<S301>/Switch7' incorporates:
       *  Constant: '<S301>/Constant10'
       */
      rtb_Desired_Pipeline = 1U;
    } else {
      rtb_Desired_Pipeline = TEST_Pipeline;
    }

    /* End of Switch: '<S301>/Switch6' */

    /* Merge: '<S7>/Merge23' incorporates:
     *  Constant: '<S11>/Constant'
     *  SignalConversion generated from: '<S11>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S11>/Constant3'
     *  SignalConversion generated from: '<S11>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S11>/Constant9'
     *  SignalConversion generated from: '<S11>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S7>/Merge10' incorporates:
     *  Constant: '<S11>/Constant1'
     *  SignalConversion generated from: '<S11>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* SignalConversion generated from: '<S11>/Enable_Wheels' incorporates:
     *  Constant: '<S11>/Constant6'
     */
    rtb_Enable_Wheels = false;

    /* SignalConversion generated from: '<S11>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S11>/Constant13'
     */
    rtb_Reset_Wheel_Offsets = false;

    /* SignalConversion generated from: '<S11>/Disable_Wheels' incorporates:
     *  Constant: '<S11>/Constant14'
     */
    rtb_Disable_Wheels = false;

    /* SignalConversion generated from: '<S11>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S11>/Constant2'
     */
    rtb_Swerve_Motors_Disabled = false;

    /* Update for UnitDelay: '<S311>/Delay Input1'
     *
     * Block description for '<S311>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_Compare_a;

    /* Update for UnitDelay: '<S310>/Delay Input1' incorporates:
     *  Constant: '<S11>/Constant5'
     *
     * Block description for '<S310>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S306>/Delay Input1'
     *
     * Block description for '<S306>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = Robot_Control_B.Face_Away_Driver;

    /* Update for UnitDelay: '<S307>/Delay Input1'
     *
     * Block description for '<S307>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = Robot_Control_B.Face_Left_Driver;

    /* Update for UnitDelay: '<S308>/Delay Input1'
     *
     * Block description for '<S308>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = Robot_Control_B.Face_Toward_Driver;

    /* Update for UnitDelay: '<S309>/Delay Input1'
     *
     * Block description for '<S309>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = Robot_Control_B.Face_Right_Driver;

    /* Update for UnitDelay: '<S303>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE = rtb_AND1;

    /* Update for UnitDelay: '<S303>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_AND4;

    /* Update for UnitDelay: '<S303>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S303>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Subtract_e;

    /* Update for UnitDelay: '<S317>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Switch1;

    /* Update for UnitDelay: '<S317>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S321>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S321>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S321>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Init;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* InitializeConditions for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
     *  UnitDelay: '<S12>/Unit Delay'
     */
    Robot_Control_DW.UnitDelay_DSTATE_ir = ((rtAction == rtPrevAction) &&
      (Robot_Control_DW.UnitDelay_DSTATE_ir));

    /* End of InitializeConditions for SubSystem: '<S1>/Test' */

    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Merge: '<S7>/Merge1' incorporates:
     *  Constant: '<S12>/Constant1'
     *  SignalConversion generated from: '<S12>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S12>/Constant2'
     *  SignalConversion generated from: '<S12>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S7>/Merge3' incorporates:
     *  Constant: '<S12>/Constant3'
     *  SignalConversion generated from: '<S12>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S7>/Merge4' incorporates:
     *  Constant: '<S12>/Constant4'
     *  SignalConversion generated from: '<S12>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* SignalConversion generated from: '<S12>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S12>/Constant5'
     */
    rtb_Is_Absolute_Translation_g = false;

    /* SignalConversion generated from: '<S12>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S12>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S12>/Constant7'
     *  SignalConversion generated from: '<S12>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S12>/Constant9'
     *  SignalConversion generated from: '<S12>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S7>/Merge10' incorporates:
     *  Constant: '<S12>/Constant12'
     *  SignalConversion generated from: '<S12>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = true;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant14'
     *  Switch: '<S12>/Switch1'
     *  UnitDelay: '<S12>/Unit Delay'
     */
    if (Robot_Control_B.Button_Disable_Wheels) {
      rtb_Swerve_Motors_Disabled = true;
    } else {
      rtb_Swerve_Motors_Disabled = ((!Robot_Control_B.Button_Enable_Wheels) &&
        (Robot_Control_DW.UnitDelay_DSTATE_ir));
    }

    /* End of Switch: '<S12>/Switch' */

    /* Merge: '<S7>/Merge23' incorporates:
     *  Constant: '<S12>/Constant21'
     *  SignalConversion generated from: '<S12>/Swerve_Drive_Integral_Enable'
     */
    Robot_Control_B.Swerve_Drive_Integral_Enable = false;

    /* SignalConversion generated from: '<S12>/Desired_Pipeline' incorporates:
     *  Constant: '<S12>/Constant22'
     */
    rtb_Desired_Pipeline = TEST_Pipeline;

    /* SignalConversion: '<S12>/Signal Copy' */
    rtb_Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* SignalConversion: '<S12>/Signal Copy2' */
    rtb_Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* SignalConversion: '<S12>/Signal Copy1' */
    rtb_Reset_Wheel_Offsets = Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S12>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_Swerve_Motors_Disabled;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Reshape: '<S34>/Reshapey' incorporates:
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

  /* Delay: '<S34>/MemoryX' incorporates:
   *  Constant: '<S34>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.MemoryX_DSTATE[0] = 0.0;
    Robot_Control_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S61>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S87>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S54>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S85>/Enable'
   */
  /* Logic: '<S6>/AND' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S85>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S34>/C'
     *  Delay: '<S34>/MemoryX'
     *  Product: '<S87>/Product'
     */
    rtb_Sin4 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
      Robot_Control_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Sin4;

    /* Sum: '<S85>/Sum' incorporates:
     *  Constant: '<S34>/D'
     *  Inport: '<Root>/Odom_Delta_X'
     *  Inport: '<Root>/Odom_Delta_Y'
     *  Product: '<S85>/C[k]*xhat[k|k-1]'
     *  Product: '<S85>/D[k]*u[k]'
     *  Sum: '<S85>/Add1'
     */
    rtb_Add_h5 = (0.0 * Robot_Control_U.Odom_Delta_X) + (0.0 *
      Robot_Control_U.Odom_Delta_Y);
    rtb_Subtract_e = rtb_Reshapey[0] - (rtb_Add_h5 + rtb_Sin4);

    /* Product: '<S85>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S34>/C'
     *  Delay: '<S34>/MemoryX'
     *  Product: '<S87>/Product'
     */
    rtb_Sin4 = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
      Robot_Control_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Sin4;

    /* Sum: '<S85>/Sum' incorporates:
     *  Constant: '<S34>/D'
     *  Product: '<S85>/C[k]*xhat[k|k-1]'
     *  Product: '<S85>/D[k]*u[k]'
     *  Sum: '<S85>/Add1'
     */
    rtb_Sin4 = rtb_Reshapey[1] - (rtb_Add_h5 + rtb_Sin4);
    Robot_Control_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S85>/Product3' incorporates:
     *  Constant: '<S35>/KalmanGainL'
     */
    Robot_Control_B.Product3[0] = (0.0951249219725039 * rtb_Subtract_e) +
      (-2.0601714451538746E-17 * rtb_Sin4);

    /* Sum: '<S87>/Add1' incorporates:
     *  Product: '<S87>/Product'
     */
    rtb_Add_h5 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S85>/Product3' incorporates:
     *  Constant: '<S35>/KalmanGainL'
     */
    Robot_Control_B.Product3[1] = (1.304610855474728E-16 * rtb_Subtract_e) +
      (0.095124921972504 * rtb_Sin4);

    /* Sum: '<S87>/Add1' incorporates:
     *  Product: '<S87>/Product'
     */
    rtb_Sin4 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S87>/Product2' incorporates:
     *  Constant: '<S35>/KalmanGainM'
     */
    Robot_Control_B.Product2[0] = (0.09512492197250387 * rtb_Add_h5) +
      (5.9896845167210271E-17 * rtb_Sin4);
    Robot_Control_B.Product2[1] = (5.9896845167210271E-17 * rtb_Add_h5) +
      (0.095124921972503981 * rtb_Sin4);
  } else {
    if (Robot_Control_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S85>/Product3' incorporates:
       *  Outport: '<S85>/L*(y[k]-yhat[k|k-1])'
       */
      Robot_Control_B.Product3[0] = 0.0;
      Robot_Control_B.Product3[1] = 0.0;
      Robot_Control_DW.MeasurementUpdate_MODE = false;
    }

    if (Robot_Control_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S87>/Product2' incorporates:
       *  Outport: '<S87>/deltax'
       */
      Robot_Control_B.Product2[0] = 0.0;
      Robot_Control_B.Product2[1] = 0.0;
      Robot_Control_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S6>/AND' */
  /* End of Outputs for SubSystem: '<S54>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S61>/Enabled Subsystem' */

  /* Sum: '<S61>/Add' incorporates:
   *  Delay: '<S34>/MemoryX'
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

  /* If: '<S9>/If' incorporates:
   *  Constant: '<S89>/Constant'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Merge: '<S9>/Merge'
   *  Merge: '<S9>/Merge1'
   *  Merge: '<S9>/Merge2'
   *  Merge: '<S9>/Merge3'
   *  Merge: '<S9>/Merge4'
   *  Merge: '<S9>/Merge5'
   *  Merge: '<S9>/Merge7'
   *  Merge: '<S9>/Merge8'
   *  SignalConversion generated from: '<S89>/Robot_Reached_Destination'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  Robot_Control_DW.If_ActiveSubsystem = 1;
  if ((rtPrevAction != 1) && (rtPrevAction == 0)) {
    /* Disable for If: '<S95>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S98>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S100>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;

      /* End of Disable for If: '<S98>/If' */
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S95>/If' */
  }

  /* Outputs for IfAction SubSystem: '<S9>/Pass Through' incorporates:
   *  ActionPort: '<S89>/Action Port'
   */
  Robot_Control_B.Robot_Reached_Destination = true;
  Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;
  Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;
  Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;
  Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;
  Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation_g;
  Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;
  Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

  /* End of If: '<S9>/If' */
  /* End of Outputs for SubSystem: '<S9>/Pass Through' */

  /* Signum: '<S239>/Sign2' incorporates:
   *  UnitDelay: '<S239>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_jp = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_jp = -1.0;
  } else {
    rtb_Add_jp = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S239>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S239>/Product1' incorporates:
   *  Signum: '<S239>/Sign1'
   *  Signum: '<S239>/Sign2'
   */
  rtb_Add_jp *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_jp)) {
    tmp = 0;
  } else {
    tmp = (int32_T)fmod(rtb_Add_jp, 256.0);
  }

  /* Switch: '<S239>/Switch' incorporates:
   *  Constant: '<S239>/Constant'
   *  Constant: '<S244>/Constant'
   *  Constant: '<S245>/Constant'
   *  Logic: '<S239>/or'
   *  Product: '<S239>/Product1'
   *  RelationalOperator: '<S244>/Compare'
   *  RelationalOperator: '<S245>/Compare'
   *  UnitDelay: '<S239>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((tmp < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)tmp))))))) : tmp) > 0)) {
    rtb_Sin4 = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S239>/Switch' */

  /* Switch: '<S250>/Init' incorporates:
   *  UnitDelay: '<S250>/FixPt Unit Delay1'
   *  UnitDelay: '<S250>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Subtract_e = rtb_Sin4;
  } else {
    rtb_Subtract_e = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S250>/Init' */

  /* RelationalOperator: '<S246>/Compare' incorporates:
   *  Constant: '<S246>/Constant'
   */
  rtb_Compare_a = (rtb_Sin4 == 0.0);

  /* RelationalOperator: '<S247>/Compare' incorporates:
   *  Constant: '<S247>/Constant'
   */
  rtb_AND1 = (rtb_Sin4 > 0.0);

  /* Abs: '<S239>/Abs' incorporates:
   *  Sum: '<S239>/Subtract'
   *  UnitDelay: '<S239>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S239>/Switch5' incorporates:
   *  Constant: '<S239>/Constant1'
   *  Switch: '<S239>/Switch1'
   *  UnaryMinus: '<S239>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S239>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S239>/Constant4'
     *  Constant: '<S239>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S239>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S239>/Constant2'
     *  Constant: '<S239>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S239>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S239>/Lookup Table Dynamic'
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
    rtb_Add_jp = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S239>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S239>/Constant10'
     *  Constant: '<S239>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S239>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S239>/Constant7'
     *  Constant: '<S239>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S239>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S239>/Lookup Table Dynamic1'
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

    /* Switch: '<S239>/Switch3' incorporates:
     *  Constant: '<S239>/Constant1'
     *  Constant: '<S239>/Constant3'
     *  UnaryMinus: '<S239>/Unary Minus'
     */
    if (rtb_AND1) {
      rtb_Add_jp = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_jp = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S239>/Switch3' */
  }

  /* End of Switch: '<S239>/Switch5' */

  /* Product: '<S239>/Product' incorporates:
   *  Switch: '<S239>/Switch1'
   */
  rtb_Switch2 = rtb_Add_jp * rtb_Merge1;

  /* Sum: '<S248>/Sum1' */
  rtb_Add_h5 = rtb_Sin4 - rtb_Subtract_e;

  /* Switch: '<S249>/Switch2' incorporates:
   *  RelationalOperator: '<S249>/LowerRelop1'
   */
  if (!(rtb_Add_h5 > rtb_Switch2)) {
    /* Switch: '<S239>/Switch2' incorporates:
     *  Constant: '<S239>/Constant1'
     *  Switch: '<S239>/Switch4'
     */
    if (rtb_Compare_a) {
      rtb_Modulation_Drv = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_AND1) {
      /* Switch: '<S239>/Switch4' incorporates:
       *  Constant: '<S239>/Constant1'
       */
      rtb_Modulation_Drv = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S239>/Switch4' incorporates:
       *  Constant: '<S239>/Constant3'
       *  UnaryMinus: '<S239>/Unary Minus1'
       */
      rtb_Modulation_Drv = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S239>/Switch2' */

    /* Product: '<S239>/Product2' */
    rtb_Modulation_Drv *= rtb_Merge1;

    /* Switch: '<S249>/Switch' incorporates:
     *  RelationalOperator: '<S249>/UpperRelop'
     */
    if (rtb_Add_h5 < rtb_Modulation_Drv) {
      rtb_Switch2 = rtb_Modulation_Drv;
    } else {
      rtb_Switch2 = rtb_Add_h5;
    }

    /* End of Switch: '<S249>/Switch' */
  }

  /* End of Switch: '<S249>/Switch2' */

  /* Sum: '<S248>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Switch2 + rtb_Subtract_e;

  /* Switch: '<S242>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S242>/Switch' incorporates:
     *  Constant: '<S274>/Constant3'
     *  Constant: '<S274>/Constant4'
     *  Math: '<S274>/Math Function'
     *  Sum: '<S242>/Subtract'
     *  Sum: '<S274>/Add1'
     *  Sum: '<S274>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S242>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S242>/Switch' */

  /* Sum: '<S270>/Add1' incorporates:
   *  Constant: '<S270>/Constant3'
   *  Constant: '<S270>/Constant4'
   *  Math: '<S270>/Math Function'
   *  Sum: '<S269>/Sum'
   *  Sum: '<S270>/Add2'
   */
  rtb_Sin4 = rt_modd_snf((Robot_Control_B.Steering_Abs_Cmd_SPF -
    Robot_Control_B.Gyro_Angle_SPF) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Sum: '<S272>/Sum1' incorporates:
   *  Constant: '<S269>/Constant2'
   *  Product: '<S272>/Product'
   *  Sum: '<S272>/Sum'
   *  UnitDelay: '<S272>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_Sin4 - Robot_Control_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S269>/Product' incorporates:
   *  Constant: '<S269>/Constant3'
   */
  rtb_Add_h5 = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S271>/Diff' incorporates:
   *  UnitDelay: '<S271>/UD'
   *
   * Block description for '<S271>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S271>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_Add_h5 - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S269>/Saturation' */
  if (rtb_Add_jp > Steering_Heading_Control_D_UL) {
    rtb_Add_jp = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_jp < Steering_Heading_Control_D_LL) {
    rtb_Add_jp = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S269>/Add' incorporates:
   *  Gain: '<S269>/Gain1'
   *  Saturate: '<S269>/Saturation'
   */
  rtb_Modulation_Drv = (Steering_Heading_Control_P * rtb_Sin4) + rtb_Add_jp;

  /* Sum: '<S269>/Subtract' incorporates:
   *  Constant: '<S269>/Constant'
   */
  rtb_Subtract_e = Steering_Heading_Control_Total_UL - rtb_Modulation_Drv;

  /* Sum: '<S269>/Sum2' incorporates:
   *  Gain: '<S269>/Gain2'
   *  UnitDelay: '<S269>/Unit Delay'
   */
  rtb_Sin4 = (Steering_Heading_Control_I * rtb_Sin4) +
    Robot_Control_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S273>/Switch2' incorporates:
   *  RelationalOperator: '<S273>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Subtract_e)) {
    /* Sum: '<S269>/Subtract1' incorporates:
     *  Constant: '<S269>/Constant1'
     */
    rtb_Subtract_e = Steering_Heading_Control_Total_LL - rtb_Modulation_Drv;

    /* Switch: '<S273>/Switch' incorporates:
     *  RelationalOperator: '<S273>/UpperRelop'
     */
    if (!(rtb_Sin4 < rtb_Subtract_e)) {
      rtb_Subtract_e = rtb_Sin4;
    }

    /* End of Switch: '<S273>/Switch' */
  }

  /* End of Switch: '<S273>/Switch2' */

  /* Saturate: '<S269>/Saturation1' */
  if (rtb_Subtract_e > Steering_Heading_Control_I_UL) {
    rtb_Subtract_e = Steering_Heading_Control_I_UL;
  } else if (rtb_Subtract_e < Steering_Heading_Control_I_LL) {
    rtb_Subtract_e = Steering_Heading_Control_I_LL;
  }

  /* End of Saturate: '<S269>/Saturation1' */

  /* Sum: '<S269>/Add1' */
  rtb_Add_jp = rtb_Modulation_Drv + rtb_Subtract_e;

  /* Saturate: '<S269>/Saturation2' */
  if (rtb_Add_jp > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S269>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_jp < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S269>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S269>/Saturation2' */
    Robot_Control_B.Steering_Localized_PID = rtb_Add_jp;
  }

  /* End of Saturate: '<S269>/Saturation2' */

  /* Switch: '<S253>/Switch' incorporates:
   *  Abs: '<S253>/Abs'
   *  Constant: '<S253>/Constant'
   *  Constant: '<S268>/Constant'
   *  RelationalOperator: '<S268>/Compare'
   */
  if (fabs(Robot_Control_B.Steering_Localized_PID) >
      Steering_Heading_Control_Deadzone) {
    rtb_Sin4 = Robot_Control_B.Steering_Localized_PID;
  } else {
    rtb_Sin4 = 0.0;
  }

  /* End of Switch: '<S253>/Switch' */

  /* Signum: '<S252>/Sign2' incorporates:
   *  UnitDelay: '<S252>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d)) {
    rtb_Add_jp = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d < 0.0) {
    rtb_Add_jp = -1.0;
  } else {
    rtb_Add_jp = (Robot_Control_DW.UnitDelay_DSTATE_d > 0.0);
  }

  /* Signum: '<S252>/Sign1' */
  if (rtIsNaN(rtb_Sin4)) {
    rtb_Add_k = (rtNaN);
  } else if (rtb_Sin4 < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (rtb_Sin4 > 0.0);
  }

  /* Product: '<S252>/Product1' incorporates:
   *  Signum: '<S252>/Sign1'
   *  Signum: '<S252>/Sign2'
   */
  rtb_Add_jp *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_jp)) {
    tmp = 0;
  } else {
    tmp = (int32_T)fmod(rtb_Add_jp, 256.0);
  }

  /* Switch: '<S252>/Switch' incorporates:
   *  Constant: '<S252>/Constant'
   *  Constant: '<S261>/Constant'
   *  Constant: '<S262>/Constant'
   *  Logic: '<S252>/or'
   *  Product: '<S252>/Product1'
   *  RelationalOperator: '<S261>/Compare'
   *  RelationalOperator: '<S262>/Compare'
   *  UnitDelay: '<S252>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d == 0.0) || (((tmp < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)tmp))))))) : tmp) > 0)) {
    rtb_Switch2_nt = rtb_Sin4;
  } else {
    rtb_Switch2_nt = 0.0;
  }

  /* End of Switch: '<S252>/Switch' */

  /* Switch: '<S267>/Init' incorporates:
   *  UnitDelay: '<S267>/FixPt Unit Delay1'
   *  UnitDelay: '<S267>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_nt;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S267>/Init' */

  /* RelationalOperator: '<S263>/Compare' incorporates:
   *  Constant: '<S263>/Constant'
   */
  rtb_Compare_a = (rtb_Switch2_nt == 0.0);

  /* RelationalOperator: '<S264>/Compare' incorporates:
   *  Constant: '<S264>/Constant'
   */
  rtb_AND1 = (rtb_Switch2_nt > 0.0);

  /* Abs: '<S252>/Abs' incorporates:
   *  Sum: '<S252>/Subtract'
   *  UnitDelay: '<S252>/Unit Delay'
   */
  rtb_Modulation_Drv = fabs(Robot_Control_DW.UnitDelay_DSTATE_d - rtb_Sin4);

  /* Switch: '<S252>/Switch1' incorporates:
   *  Constant: '<S252>/Constant1'
   *  Switch: '<S252>/Switch3'
   *  Switch: '<S252>/Switch5'
   *  UnaryMinus: '<S252>/Unary Minus'
   */
  if (rtb_Compare_a) {
    rtb_Switch1 = -Steering_Absolute_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S252>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S252>/Constant1'
     *  Constant: '<S252>/Constant4'
     *  Constant: '<S252>/Constant6'
     *  UnaryMinus: '<S252>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S252>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S252>/Constant2'
     *  Constant: '<S252>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S252>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S252>/Lookup Table Dynamic'
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
  } else {
    if (rtb_AND1) {
      /* Switch: '<S252>/Switch3' incorporates:
       *  Constant: '<S252>/Constant3'
       */
      rtb_Switch1 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Switch1 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S252>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S252>/Constant1'
     *  Constant: '<S252>/Constant10'
     *  Constant: '<S252>/Constant8'
     *  UnaryMinus: '<S252>/Unary Minus'
     */
    rtb_Reshapey[0] = Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S252>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S252>/Constant7'
     *  Constant: '<S252>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S252>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S252>/Lookup Table Dynamic1'
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
  }

  /* End of Switch: '<S252>/Switch1' */

  /* Product: '<S252>/Product' */
  rtb_Switch1 *= rtb_Modulation_Drv;

  /* Sum: '<S265>/Sum1' */
  rtb_Sin4 = rtb_Switch2_nt - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S266>/Switch2' incorporates:
   *  RelationalOperator: '<S266>/LowerRelop1'
   */
  if (!(rtb_Sin4 > rtb_Switch1)) {
    /* Switch: '<S252>/Switch2' incorporates:
     *  Constant: '<S252>/Constant1'
     *  Switch: '<S252>/Switch4'
     */
    if (rtb_Compare_a) {
      rtb_Switch1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1) {
      /* Switch: '<S252>/Switch4' incorporates:
       *  Constant: '<S252>/Constant1'
       */
      rtb_Switch1 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S252>/Switch4' incorporates:
       *  Constant: '<S252>/Constant3'
       *  UnaryMinus: '<S252>/Unary Minus1'
       */
      rtb_Switch1 = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S252>/Switch2' */

    /* Product: '<S252>/Product2' */
    rtb_Switch1 *= rtb_Modulation_Drv;

    /* Switch: '<S266>/Switch' incorporates:
     *  RelationalOperator: '<S266>/UpperRelop'
     */
    if (!(rtb_Sin4 < rtb_Switch1)) {
      rtb_Switch1 = rtb_Sin4;
    }

    /* End of Switch: '<S266>/Switch' */
  }

  /* End of Switch: '<S266>/Switch2' */

  /* Sum: '<S265>/Sum' */
  rtb_Modulation_Drv = rtb_Switch1 + rtb_Optimized_Module_Angle_p;

  /* Signum: '<S251>/Sign2' incorporates:
   *  UnitDelay: '<S251>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_jp = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_jp = -1.0;
  } else {
    rtb_Add_jp = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S251>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S251>/Product1' incorporates:
   *  Signum: '<S251>/Sign1'
   *  Signum: '<S251>/Sign2'
   */
  rtb_Add_jp *= rtb_Add_k;
  if (rtIsNaN(rtb_Add_jp)) {
    tmp = 0;
  } else {
    tmp = (int32_T)fmod(rtb_Add_jp, 256.0);
  }

  /* Switch: '<S251>/Switch' incorporates:
   *  Constant: '<S251>/Constant'
   *  Constant: '<S254>/Constant'
   *  Constant: '<S255>/Constant'
   *  Logic: '<S251>/or'
   *  Product: '<S251>/Product1'
   *  RelationalOperator: '<S254>/Compare'
   *  RelationalOperator: '<S255>/Compare'
   *  UnitDelay: '<S251>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((tmp < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)tmp))))))) : tmp) > 0)) {
    rtb_Switch2_nt = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_nt = 0.0;
  }

  /* End of Switch: '<S251>/Switch' */

  /* Switch: '<S260>/Init' incorporates:
   *  UnitDelay: '<S260>/FixPt Unit Delay1'
   *  UnitDelay: '<S260>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle_p = rtb_Switch2_nt;
  } else {
    rtb_Optimized_Module_Angle_p = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S260>/Init' */

  /* RelationalOperator: '<S256>/Compare' incorporates:
   *  Constant: '<S256>/Constant'
   */
  rtb_Compare_a = (rtb_Switch2_nt == 0.0);

  /* RelationalOperator: '<S257>/Compare' incorporates:
   *  Constant: '<S257>/Constant'
   */
  rtb_AND1 = (rtb_Switch2_nt > 0.0);

  /* Abs: '<S251>/Abs' incorporates:
   *  Sum: '<S251>/Subtract'
   *  UnitDelay: '<S251>/Unit Delay'
   */
  rtb_Switch1 = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                     Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S251>/Switch5' incorporates:
   *  Constant: '<S251>/Constant1'
   *  Switch: '<S251>/Switch1'
   *  UnaryMinus: '<S251>/Unary Minus'
   */
  if (rtb_Compare_a) {
    /* SignalConversion generated from: '<S251>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S251>/Constant4'
     *  Constant: '<S251>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S251>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S251>/Constant2'
     *  Constant: '<S251>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S251>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S251>/Lookup Table Dynamic'
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
    rtb_Add_jp = -Steering_Relative_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S251>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S251>/Constant10'
     *  Constant: '<S251>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S251>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S251>/Constant7'
     *  Constant: '<S251>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S251>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S251>/Lookup Table Dynamic1'
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

    /* Switch: '<S251>/Switch3' incorporates:
     *  Constant: '<S251>/Constant1'
     *  Constant: '<S251>/Constant3'
     *  UnaryMinus: '<S251>/Unary Minus'
     */
    if (rtb_AND1) {
      rtb_Add_jp = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_jp = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S251>/Switch3' */
  }

  /* End of Switch: '<S251>/Switch5' */

  /* Product: '<S251>/Product' incorporates:
   *  Switch: '<S251>/Switch1'
   */
  rtb_Sin4 = rtb_Add_jp * rtb_Switch1;

  /* Sum: '<S258>/Sum1' */
  rtb_Switch2 = rtb_Switch2_nt - rtb_Optimized_Module_Angle_p;

  /* Switch: '<S259>/Switch2' incorporates:
   *  RelationalOperator: '<S259>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_Sin4)) {
    /* Switch: '<S251>/Switch2' incorporates:
     *  Constant: '<S251>/Constant1'
     *  Constant: '<S251>/Constant3'
     *  Switch: '<S251>/Switch4'
     *  UnaryMinus: '<S251>/Unary Minus1'
     */
    if (rtb_Compare_a) {
      rtb_Add_jp = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_AND1) {
      /* Switch: '<S251>/Switch4' incorporates:
       *  Constant: '<S251>/Constant1'
       */
      rtb_Add_jp = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_jp = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S251>/Product2' incorporates:
     *  Switch: '<S251>/Switch2'
     */
    rtb_Sin4 = rtb_Add_jp * rtb_Switch1;

    /* Switch: '<S259>/Switch' incorporates:
     *  RelationalOperator: '<S259>/UpperRelop'
     */
    if (!(rtb_Switch2 < rtb_Sin4)) {
      rtb_Sin4 = rtb_Switch2;
    }

    /* End of Switch: '<S259>/Switch' */
  }

  /* End of Switch: '<S259>/Switch2' */

  /* Sum: '<S258>/Sum' */
  rtb_Sin4 += rtb_Optimized_Module_Angle_p;

  /* Switch: '<S241>/Switch' */
  if (Robot_Control_B.Is_Absolute_Steering_SPF) {
    /* Switch: '<S241>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Modulation_Drv;
  } else {
    /* Switch: '<S241>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Sin4;
  }

  /* End of Switch: '<S241>/Switch' */

  /* Fcn: '<S282>/r->x' incorporates:
   *  Fcn: '<S287>/r->x'
   *  Fcn: '<S292>/r->x'
   *  Fcn: '<S297>/r->x'
   */
  rtb_Switch2_k = Robot_Control_B.Translation_Speed_RL * cos
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S276>/Add' incorporates:
   *  Fcn: '<S282>/r->x'
   *  Fcn: '<S283>/r->x'
   */
  rtb_Reshapey[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2_k;

  /* Fcn: '<S282>/theta->y' incorporates:
   *  Fcn: '<S287>/theta->y'
   *  Fcn: '<S292>/theta->y'
   *  Fcn: '<S297>/theta->y'
   */
  rtb_Switch1 = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S276>/Add' incorporates:
   *  Fcn: '<S282>/theta->y'
   *  Fcn: '<S283>/theta->y'
   */
  rtb_Reshapey[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                     (Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch1;

  /* Sum: '<S277>/Add' incorporates:
   *  Fcn: '<S288>/r->x'
   *  Fcn: '<S288>/theta->y'
   */
  rtb_Minus_n[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2_k;
  rtb_Minus_n[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch1;

  /* Sum: '<S278>/Add' incorporates:
   *  Fcn: '<S293>/r->x'
   *  Fcn: '<S293>/theta->y'
   */
  rtb_Add2_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2_k;
  rtb_Add2_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                    (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch1;

  /* Sum: '<S279>/Add' incorporates:
   *  Fcn: '<S298>/r->x'
   *  Fcn: '<S298>/theta->y'
   */
  rtb_Switch2_k += Robot_Control_B.Steering_Localized_Cmd * cos
    (Robot_Control_ConstB.BR_Tangent_Angle);
  rtb_Init = (Robot_Control_B.Steering_Localized_Cmd * sin
              (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch1;

  /* Fcn: '<S296>/x->r' */
  rtb_Switch1 = rt_hypotd_snf(rtb_Switch2_k, rtb_Init);

  /* RelationalOperator: '<S299>/Compare' incorporates:
   *  Constant: '<S299>/Constant'
   */
  rtb_Compare_a = (rtb_Switch1 == 0.0);

  /* Switch: '<S295>/Switch1' */
  if (rtb_Compare_a) {
    /* Switch: '<S295>/Switch1' incorporates:
     *  Constant: '<S295>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S295>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch1;
  }

  /* End of Switch: '<S295>/Switch1' */

  /* Fcn: '<S281>/x->r' */
  rtb_Switch1 = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S284>/Compare' incorporates:
   *  Constant: '<S284>/Constant'
   */
  rtb_AND1 = (rtb_Switch1 == 0.0);

  /* Switch: '<S280>/Switch1' */
  if (rtb_AND1) {
    /* Switch: '<S280>/Switch1' incorporates:
     *  Constant: '<S280>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S280>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch1;
  }

  /* End of Switch: '<S280>/Switch1' */

  /* Fcn: '<S286>/x->r' */
  rtb_Switch2_nt = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S289>/Compare' incorporates:
   *  Constant: '<S289>/Constant'
   */
  rtb_Is_Absolute_Translation_g = (rtb_Switch2_nt == 0.0);

  /* Switch: '<S285>/Switch1' */
  if (rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S285>/Switch1' incorporates:
     *  Constant: '<S285>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S285>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_nt;
  }

  /* End of Switch: '<S285>/Switch1' */

  /* Fcn: '<S291>/x->r' */
  rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add2_idx_0, rtb_Add2_idx_1);

  /* RelationalOperator: '<S294>/Compare' incorporates:
   *  Constant: '<S294>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Optimized_Module_Angle_p == 0.0);

  /* Switch: '<S290>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S290>/Switch1' incorporates:
     *  Constant: '<S290>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S290>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle_p;
  }

  /* End of Switch: '<S290>/Switch1' */

  /* Product: '<S275>/Divide' incorporates:
   *  Abs: '<S275>/Abs'
   *  Abs: '<S275>/Abs1'
   *  Abs: '<S275>/Abs2'
   *  Abs: '<S275>/Abs3'
   *  Constant: '<S275>/Constant'
   *  MinMax: '<S275>/Max'
   */
  rtb_Switch1 = 5.1198378053698752 / fmax(fmax(fmax(fmax(5.1198378053698752,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S275>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch1;

  /* Switch: '<S295>/Switch' */
  if (!rtb_Compare_a) {
    /* Switch: '<S295>/Switch' incorporates:
     *  Fcn: '<S296>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Init,
      rtb_Switch2_k);
  }

  /* End of Switch: '<S295>/Switch' */

  /* Trigonometry: '<S231>/Cos4' incorporates:
   *  Switch: '<S220>/Angle_Switch'
   *  Trigonometry: '<S230>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S231>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S229>/Unary Minus'
   */
  rtb_Switch2 = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S231>/Sin4' incorporates:
   *  Switch: '<S220>/Angle_Switch'
   *  Trigonometry: '<S230>/Sin4'
   */
  rtb_Init = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S231>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S229>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S231>/Subtract1' incorporates:
   *  Product: '<S231>/Product2'
   *  Product: '<S231>/Product3'
   *  Trigonometry: '<S231>/Cos4'
   *  Trigonometry: '<S231>/Sin4'
   */
  rtb_Switch2_k = (rtb_Add_k * rtb_Switch2) + (rtb_Init *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S231>/Subtract' incorporates:
   *  Product: '<S231>/Product'
   *  Product: '<S231>/Product1'
   *  Trigonometry: '<S231>/Cos4'
   *  Trigonometry: '<S231>/Sin4'
   */
  rtb_Switch2 = (rtb_Add_k * rtb_Optimized_Module_Angle_p) - (rtb_Init *
    rtb_Switch2);

  /* Math: '<S231>/Hypot' */
  rtb_Hypot = rt_hypotd_snf(rtb_Switch2, rtb_Switch2_k);

  /* Switch: '<S231>/Switch' incorporates:
   *  Constant: '<S231>/Constant'
   *  Constant: '<S231>/Constant1'
   *  Constant: '<S232>/Constant'
   *  Product: '<S231>/Divide'
   *  Product: '<S231>/Divide1'
   *  RelationalOperator: '<S232>/Compare'
   *  Switch: '<S231>/Switch1'
   */
  if (rtb_Hypot > 1.0E-6) {
    rtb_Switch2_nt = rtb_Switch2_k / rtb_Hypot;
    rtb_Optimized_Module_Angle_p = rtb_Switch2 / rtb_Hypot;
  } else {
    rtb_Switch2_nt = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S231>/Switch' */

  /* Switch: '<S220>/Speed_Switch' incorporates:
   *  Abs: '<S220>/Abs'
   *  Constant: '<S228>/Constant'
   *  RelationalOperator: '<S228>/Compare'
   *  Switch: '<S220>/Angle_Switch'
   *  Trigonometry: '<S230>/Atan1'
   *  Trigonometry: '<S231>/Atan1'
   *  UnaryMinus: '<S220>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nt, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_jp = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S230>/Subtract1' incorporates:
     *  Product: '<S230>/Product2'
     *  Product: '<S230>/Product3'
     *  UnaryMinus: '<S220>/Unary Minus'
     */
    rtb_Switch2 = (rtb_Add_k * Robot_Control_ConstB.Sin5_c) + (rtb_Init *
      Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S230>/Subtract' incorporates:
     *  Product: '<S230>/Product'
     *  Product: '<S230>/Product1'
     */
    rtb_Switch2_k = (rtb_Add_k * Robot_Control_ConstB.Cos5_b) - (rtb_Init *
      Robot_Control_ConstB.Sin5_c);

    /* Math: '<S230>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Switch2_k, rtb_Switch2);

    /* Switch: '<S230>/Switch1' incorporates:
     *  Constant: '<S230>/Constant'
     *  Constant: '<S230>/Constant1'
     *  Constant: '<S233>/Constant'
     *  Product: '<S230>/Divide'
     *  Product: '<S230>/Divide1'
     *  RelationalOperator: '<S233>/Compare'
     *  Switch: '<S230>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Switch2_k /= rtb_Init;
      rtb_Switch2 /= rtb_Init;
    } else {
      rtb_Switch2_k = 1.0;
      rtb_Switch2 = 0.0;
    }

    /* End of Switch: '<S230>/Switch1' */
    rtb_Switch2 = rt_atan2d_snf(rtb_Switch2, rtb_Switch2_k);
  } else {
    rtb_Add_jp = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_Switch2 = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S223>/Product2' incorporates:
   *  Constant: '<S223>/Constant'
   *  Switch: '<S220>/Speed_Switch'
   */
  rtb_Switch2_nt = rtb_Add_jp * 1210.9758620668042;

  /* Signum: '<S218>/Sign' */
  if (rtIsNaN(rtb_Switch2_nt)) {
    rtb_Add_jp = (rtNaN);
  } else if (rtb_Switch2_nt < 0.0) {
    rtb_Add_jp = -1.0;
  } else {
    rtb_Add_jp = (rtb_Switch2_nt > 0.0);
  }

  /* Signum: '<S218>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S221>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S222>/Sum'
   */
  rtb_Switch2 -= Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S153>/Product' incorporates:
   *  Abs: '<S218>/Abs'
   *  Abs: '<S221>/Abs'
   *  Constant: '<S224>/Constant'
   *  Constant: '<S234>/Constant3'
   *  Constant: '<S234>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S218>/OR'
   *  Lookup_n-D: '<S221>/1-D Lookup Table'
   *  Math: '<S234>/Math Function'
   *  RelationalOperator: '<S218>/Equal1'
   *  RelationalOperator: '<S224>/Compare'
   *  Signum: '<S218>/Sign'
   *  Signum: '<S218>/Sign1'
   *  Sum: '<S221>/Add'
   *  Sum: '<S234>/Add1'
   *  Sum: '<S234>/Add2'
   */
  rtb_Switch2_nt = (((real_T)((rtb_Add_jp == rtb_Add_k) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nt) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Switch2 + 1.5707963267948966,
    3.1415926535897931) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                  rtCP_uDLookupTable_tableData, 1U);

  /* Sum: '<S219>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Hypot = rtb_Switch2_nt - Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S226>/Sum1' incorporates:
   *  Constant: '<S219>/Constant2'
   *  Product: '<S226>/Product'
   *  Sum: '<S226>/Sum'
   *  UnitDelay: '<S226>/Unit Delay1'
   */
  rtb_Init = ((rtb_Hypot - Robot_Control_DW.UnitDelay1_DSTATE_j) *
              Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S219>/Product' incorporates:
   *  Constant: '<S219>/Constant3'
   */
  rtb_Switch2_k = rtb_Init * Drive_Motor_Control_D;

  /* Sum: '<S225>/Diff' incorporates:
   *  UnitDelay: '<S225>/UD'
   *
   * Block description for '<S225>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S225>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_Switch2_k - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S219>/Saturation' */
  if (rtb_Add_jp > Drive_Motor_Control_D_UL) {
    rtb_Add_jp = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_jp < Drive_Motor_Control_D_LL) {
    rtb_Add_jp = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S219>/Add' incorporates:
   *  Gain: '<S219>/Gain'
   *  Gain: '<S219>/Gain1'
   *  Saturate: '<S219>/Saturation'
   */
  rtb_Hypot = ((Drive_Motor_Control_FF * rtb_Switch2_nt) +
               (Drive_Motor_Control_P * rtb_Hypot)) + rtb_Add_jp;

  /* Saturate: '<S219>/Saturation2' incorporates:
   *  Sum: '<S219>/Add1'
   */
  if (rtb_Hypot > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Hypot < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_Hypot;
  }

  /* End of Saturate: '<S219>/Saturation2' */

  /* Switch: '<S280>/Switch' */
  if (!rtb_AND1) {
    /* Switch: '<S280>/Switch' incorporates:
     *  Fcn: '<S281>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S280>/Switch' */

  /* Trigonometry: '<S168>/Cos4' incorporates:
   *  Switch: '<S157>/Angle_Switch'
   *  Trigonometry: '<S167>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S168>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S166>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S168>/Sin4' incorporates:
   *  Switch: '<S157>/Angle_Switch'
   *  Trigonometry: '<S167>/Sin4'
   */
  rtb_Integral_hv = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S168>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S166>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S168>/Subtract1' incorporates:
   *  Product: '<S168>/Product2'
   *  Product: '<S168>/Product3'
   *  Trigonometry: '<S168>/Cos4'
   *  Trigonometry: '<S168>/Sin4'
   */
  rtb_Hypot = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Integral_hv *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S168>/Subtract' incorporates:
   *  Product: '<S168>/Product'
   *  Product: '<S168>/Product1'
   *  Trigonometry: '<S168>/Cos4'
   *  Trigonometry: '<S168>/Sin4'
   */
  rtb_Switch2_a = (rtb_Add_k * rtb_Optimized_Module_Angle_p) - (rtb_Integral_hv *
    rtb_uDLookupTable);

  /* Math: '<S168>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Switch2_a, rtb_Hypot);

  /* Switch: '<S168>/Switch' incorporates:
   *  Constant: '<S168>/Constant'
   *  Constant: '<S168>/Constant1'
   *  Constant: '<S169>/Constant'
   *  Product: '<S168>/Divide'
   *  Product: '<S168>/Divide1'
   *  RelationalOperator: '<S169>/Compare'
   *  Switch: '<S168>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_Switch2_nt = rtb_Hypot / rtb_Hypot_g5;
    rtb_Optimized_Module_Angle_p = rtb_Switch2_a / rtb_Hypot_g5;
  } else {
    rtb_Switch2_nt = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S168>/Switch' */

  /* Product: '<S275>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch1;

  /* Switch: '<S157>/Speed_Switch' incorporates:
   *  Abs: '<S157>/Abs'
   *  Constant: '<S165>/Constant'
   *  RelationalOperator: '<S165>/Compare'
   *  Switch: '<S157>/Angle_Switch'
   *  Trigonometry: '<S167>/Atan1'
   *  Trigonometry: '<S168>/Atan1'
   *  UnaryMinus: '<S157>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nt, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_jp = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S167>/Subtract1' incorporates:
     *  Product: '<S167>/Product2'
     *  Product: '<S167>/Product3'
     *  UnaryMinus: '<S157>/Unary Minus'
     */
    rtb_Hypot = (rtb_Add_k * Robot_Control_ConstB.Sin5) + (rtb_Integral_hv *
      Robot_Control_ConstB.Cos5);

    /* Sum: '<S167>/Subtract' incorporates:
     *  Product: '<S167>/Product'
     *  Product: '<S167>/Product1'
     */
    rtb_Hypot_g5 = (rtb_Add_k * Robot_Control_ConstB.Cos5) - (rtb_Integral_hv *
      Robot_Control_ConstB.Sin5);

    /* Math: '<S167>/Hypot' */
    rtb_Switch2_a = rt_hypotd_snf(rtb_Hypot_g5, rtb_Hypot);

    /* Switch: '<S167>/Switch1' incorporates:
     *  Constant: '<S167>/Constant'
     *  Constant: '<S167>/Constant1'
     *  Constant: '<S170>/Constant'
     *  Product: '<S167>/Divide'
     *  Product: '<S167>/Divide1'
     *  RelationalOperator: '<S170>/Compare'
     *  Switch: '<S167>/Switch'
     */
    if (rtb_Switch2_a > 1.0E-6) {
      rtb_Hypot_g5 /= rtb_Switch2_a;
      rtb_Hypot /= rtb_Switch2_a;
    } else {
      rtb_Hypot_g5 = 1.0;
      rtb_Hypot = 0.0;
    }

    /* End of Switch: '<S167>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Hypot, rtb_Hypot_g5);
  } else {
    rtb_Add_jp = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S160>/Product2' incorporates:
   *  Constant: '<S160>/Constant'
   *  Switch: '<S157>/Speed_Switch'
   */
  rtb_Switch2_nt = rtb_Add_jp * 1210.9758620668042;

  /* Signum: '<S155>/Sign' */
  if (rtIsNaN(rtb_Switch2_nt)) {
    rtb_Add_jp = (rtNaN);
  } else if (rtb_Switch2_nt < 0.0) {
    rtb_Add_jp = -1.0;
  } else {
    rtb_Add_jp = (rtb_Switch2_nt > 0.0);
  }

  /* Signum: '<S155>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S158>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S159>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S150>/Product' incorporates:
   *  Abs: '<S155>/Abs'
   *  Abs: '<S158>/Abs'
   *  Constant: '<S161>/Constant'
   *  Constant: '<S171>/Constant3'
   *  Constant: '<S171>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S155>/OR'
   *  Lookup_n-D: '<S158>/1-D Lookup Table'
   *  Math: '<S171>/Math Function'
   *  RelationalOperator: '<S155>/Equal1'
   *  RelationalOperator: '<S161>/Compare'
   *  Signum: '<S155>/Sign'
   *  Signum: '<S155>/Sign1'
   *  Sum: '<S158>/Add'
   *  Sum: '<S171>/Add1'
   *  Sum: '<S171>/Add2'
   */
  rtb_Switch2_nt = (((real_T)((rtb_Add_jp == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nt) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_h, rtCP_uDLookupTable_tableData_j,
                  1U);

  /* Sum: '<S156>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Hypot_g5 = rtb_Switch2_nt - Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S163>/Sum1' incorporates:
   *  Constant: '<S156>/Constant2'
   *  Product: '<S163>/Product'
   *  Sum: '<S163>/Sum'
   *  UnitDelay: '<S163>/Unit Delay1'
   */
  rtb_Hypot = ((rtb_Hypot_g5 - Robot_Control_DW.UnitDelay1_DSTATE_f) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S156>/Product' incorporates:
   *  Constant: '<S156>/Constant3'
   */
  rtb_Switch2_a = rtb_Hypot * Drive_Motor_Control_D;

  /* Sum: '<S162>/Diff' incorporates:
   *  UnitDelay: '<S162>/UD'
   *
   * Block description for '<S162>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S162>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_Switch2_a - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S156>/Saturation' */
  if (rtb_Add_jp > Drive_Motor_Control_D_UL) {
    rtb_Add_jp = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_jp < Drive_Motor_Control_D_LL) {
    rtb_Add_jp = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S156>/Add' incorporates:
   *  Gain: '<S156>/Gain'
   *  Gain: '<S156>/Gain1'
   *  Saturate: '<S156>/Saturation'
   */
  rtb_Hypot_g5 = ((Drive_Motor_Control_FF * rtb_Switch2_nt) +
                  (Drive_Motor_Control_P * rtb_Hypot_g5)) + rtb_Add_jp;

  /* Saturate: '<S156>/Saturation2' incorporates:
   *  Sum: '<S156>/Add1'
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

  /* End of Saturate: '<S156>/Saturation2' */

  /* Sum: '<S172>/Add1' incorporates:
   *  Constant: '<S172>/Constant3'
   *  Constant: '<S172>/Constant4'
   *  Math: '<S172>/Math Function'
   *  Sum: '<S172>/Add2'
   */
  rtb_Switch2_nt = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S174>/Sum1' incorporates:
   *  Constant: '<S159>/Constant2'
   *  Product: '<S174>/Product'
   *  Sum: '<S174>/Sum'
   *  UnitDelay: '<S174>/Unit Delay1'
   */
  rtb_Hypot_g5 = ((rtb_Switch2_nt - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                  Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S159>/Product' incorporates:
   *  Constant: '<S159>/Constant3'
   */
  rtb_Switch2_pt = rtb_Hypot_g5 * Steering_Motor_Control_D;

  /* Sum: '<S173>/Diff' incorporates:
   *  UnitDelay: '<S173>/UD'
   *
   * Block description for '<S173>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S173>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_Switch2_pt - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S159>/Saturation' */
  if (rtb_Add_jp > Steering_Motor_Control_D_UL) {
    rtb_Add_jp = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_jp < Steering_Motor_Control_D_LL) {
    rtb_Add_jp = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S159>/Add' incorporates:
   *  Gain: '<S159>/Gain1'
   *  Saturate: '<S159>/Saturation'
   */
  rtb_Add_fn = (Steering_Motor_Control_P * rtb_Switch2_nt) + rtb_Add_jp;

  /* Sum: '<S159>/Subtract' incorporates:
   *  Constant: '<S159>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_fn;

  /* Sum: '<S159>/Sum2' incorporates:
   *  Gain: '<S159>/Gain2'
   *  UnitDelay: '<S159>/Unit Delay'
   */
  rtb_Switch2_nt = (Steering_Motor_Control_I * rtb_Switch2_nt) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S175>/Switch2' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S175>/LowerRelop1'
   *  Sum: '<S159>/Subtract'
   */
  if (!(rtb_Switch2_nt > (1.0 - rtb_Add_fn))) {
    /* Switch: '<S175>/Switch' incorporates:
     *  Constant: '<S159>/Constant1'
     *  RelationalOperator: '<S175>/UpperRelop'
     *  Sum: '<S159>/Subtract1'
     */
    if (rtb_Switch2_nt < (-1.0 - rtb_Add_fn)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_fn;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Switch2_nt;
    }

    /* End of Switch: '<S175>/Switch' */
  }

  /* End of Switch: '<S175>/Switch2' */

  /* Saturate: '<S159>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_la = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S159>/Saturation1' */

  /* Sum: '<S159>/Add1' */
  rtb_Add_jp = rtb_Add_fn + rtb_Subtract1_la;

  /* Saturate: '<S159>/Saturation2' */
  if (rtb_Add_jp > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_jp < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_jp;
  }

  /* End of Saturate: '<S159>/Saturation2' */

  /* Switch: '<S285>/Switch' */
  if (!rtb_Is_Absolute_Translation_g) {
    /* Switch: '<S285>/Switch' incorporates:
     *  Fcn: '<S286>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S285>/Switch' */

  /* Trigonometry: '<S189>/Cos4' incorporates:
   *  Switch: '<S178>/Angle_Switch'
   *  Trigonometry: '<S188>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S189>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S187>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S189>/Sin4' incorporates:
   *  Switch: '<S178>/Angle_Switch'
   *  Trigonometry: '<S188>/Sin4'
   */
  rtb_Integral_hv = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S189>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S187>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S189>/Subtract1' incorporates:
   *  Product: '<S189>/Product2'
   *  Product: '<S189>/Product3'
   *  Trigonometry: '<S189>/Cos4'
   *  Trigonometry: '<S189>/Sin4'
   */
  rtb_Switch2_nt = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Integral_hv *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S189>/Subtract' incorporates:
   *  Product: '<S189>/Product'
   *  Product: '<S189>/Product1'
   *  Trigonometry: '<S189>/Cos4'
   *  Trigonometry: '<S189>/Sin4'
   */
  rtb_Add_fn = (rtb_Add_k * rtb_Optimized_Module_Angle_p) - (rtb_Integral_hv *
    rtb_uDLookupTable);

  /* Math: '<S189>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Add_fn, rtb_Switch2_nt);

  /* Switch: '<S189>/Switch' incorporates:
   *  Constant: '<S189>/Constant'
   *  Constant: '<S189>/Constant1'
   *  Constant: '<S190>/Constant'
   *  Product: '<S189>/Divide'
   *  Product: '<S189>/Divide1'
   *  RelationalOperator: '<S190>/Compare'
   *  Switch: '<S189>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_Switch2_nt /= rtb_Hypot_b;
    rtb_Optimized_Module_Angle_p = rtb_Add_fn / rtb_Hypot_b;
  } else {
    rtb_Switch2_nt = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S189>/Switch' */

  /* Product: '<S275>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch1;

  /* Switch: '<S178>/Speed_Switch' incorporates:
   *  Abs: '<S178>/Abs'
   *  Constant: '<S186>/Constant'
   *  RelationalOperator: '<S186>/Compare'
   *  Switch: '<S178>/Angle_Switch'
   *  Trigonometry: '<S188>/Atan1'
   *  Trigonometry: '<S189>/Atan1'
   *  UnaryMinus: '<S178>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nt, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Add_jp = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S188>/Subtract1' incorporates:
     *  Product: '<S188>/Product2'
     *  Product: '<S188>/Product3'
     *  UnaryMinus: '<S178>/Unary Minus'
     */
    rtb_Add_fn = (rtb_Add_k * Robot_Control_ConstB.Sin5_m) + (rtb_Integral_hv *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S188>/Subtract' incorporates:
     *  Product: '<S188>/Product'
     *  Product: '<S188>/Product1'
     */
    rtb_Add_k = (rtb_Add_k * Robot_Control_ConstB.Cos5_g) - (rtb_Integral_hv *
      Robot_Control_ConstB.Sin5_m);

    /* Math: '<S188>/Hypot' */
    rtb_Hypot_b = rt_hypotd_snf(rtb_Add_k, rtb_Add_fn);

    /* Switch: '<S188>/Switch1' incorporates:
     *  Constant: '<S188>/Constant'
     *  Constant: '<S188>/Constant1'
     *  Constant: '<S191>/Constant'
     *  Product: '<S188>/Divide'
     *  Product: '<S188>/Divide1'
     *  RelationalOperator: '<S191>/Compare'
     *  Switch: '<S188>/Switch'
     */
    if (rtb_Hypot_b > 1.0E-6) {
      rtb_Add_k /= rtb_Hypot_b;
      rtb_Add_fn /= rtb_Hypot_b;
    } else {
      rtb_Add_k = 1.0;
      rtb_Add_fn = 0.0;
    }

    /* End of Switch: '<S188>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_fn, rtb_Add_k);
  } else {
    rtb_Add_jp = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S181>/Product2' incorporates:
   *  Constant: '<S181>/Constant'
   *  Switch: '<S178>/Speed_Switch'
   */
  rtb_Switch2_nt = rtb_Add_jp * 1210.9758620668042;

  /* Signum: '<S176>/Sign' */
  if (rtIsNaN(rtb_Switch2_nt)) {
    rtb_Add_jp = (rtNaN);
  } else if (rtb_Switch2_nt < 0.0) {
    rtb_Add_jp = -1.0;
  } else {
    rtb_Add_jp = (rtb_Switch2_nt > 0.0);
  }

  /* Signum: '<S176>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S179>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S180>/Sum'
   */
  rtb_Optimized_Module_Angle_p = rtb_uDLookupTable -
    Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S151>/Product' incorporates:
   *  Abs: '<S176>/Abs'
   *  Abs: '<S179>/Abs'
   *  Constant: '<S182>/Constant'
   *  Constant: '<S192>/Constant3'
   *  Constant: '<S192>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S176>/OR'
   *  Lookup_n-D: '<S179>/1-D Lookup Table'
   *  Math: '<S192>/Math Function'
   *  RelationalOperator: '<S176>/Equal1'
   *  RelationalOperator: '<S182>/Compare'
   *  Signum: '<S176>/Sign'
   *  Signum: '<S176>/Sign1'
   *  Sum: '<S179>/Add'
   *  Sum: '<S192>/Add1'
   *  Sum: '<S192>/Add2'
   */
  rtb_Switch2_nt = (((real_T)((rtb_Add_jp == rtb_Add_k) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_nt) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_p, rtCP_uDLookupTable_tableData_g,
                  1U);

  /* Sum: '<S177>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Add_k = rtb_Switch2_nt - Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S184>/Sum1' incorporates:
   *  Constant: '<S177>/Constant2'
   *  Product: '<S184>/Product'
   *  Sum: '<S184>/Sum'
   *  UnitDelay: '<S184>/Unit Delay1'
   */
  rtb_Add_fn = ((rtb_Add_k - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S177>/Product' incorporates:
   *  Constant: '<S177>/Constant3'
   */
  rtb_Hypot_b = rtb_Add_fn * Drive_Motor_Control_D;

  /* Sum: '<S183>/Diff' incorporates:
   *  UnitDelay: '<S183>/UD'
   *
   * Block description for '<S183>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S183>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_Hypot_b - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S177>/Saturation' */
  if (rtb_Add_jp > Drive_Motor_Control_D_UL) {
    rtb_Add_jp = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_jp < Drive_Motor_Control_D_LL) {
    rtb_Add_jp = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S177>/Add' incorporates:
   *  Gain: '<S177>/Gain'
   *  Gain: '<S177>/Gain1'
   *  Saturate: '<S177>/Saturation'
   */
  rtb_Switch2_nt = ((Drive_Motor_Control_FF * rtb_Switch2_nt) +
                    (Drive_Motor_Control_P * rtb_Add_k)) + rtb_Add_jp;

  /* Saturate: '<S177>/Saturation2' incorporates:
   *  Sum: '<S177>/Add1'
   */
  if (rtb_Switch2_nt > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch2_nt < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = rtb_Switch2_nt;
  }

  /* End of Saturate: '<S177>/Saturation2' */

  /* Sum: '<S193>/Add1' incorporates:
   *  Constant: '<S193>/Constant3'
   *  Constant: '<S193>/Constant4'
   *  Math: '<S193>/Math Function'
   *  Sum: '<S193>/Add2'
   */
  rtb_Switch2_nt = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S195>/Sum1' incorporates:
   *  Constant: '<S180>/Constant2'
   *  Product: '<S195>/Product'
   *  Sum: '<S195>/Sum'
   *  UnitDelay: '<S195>/Unit Delay1'
   */
  rtb_Switch2_e = ((rtb_Switch2_nt - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                   Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S180>/Product' incorporates:
   *  Constant: '<S180>/Constant3'
   */
  rtb_Product_hi = rtb_Switch2_e * Steering_Motor_Control_D;

  /* Sum: '<S194>/Diff' incorporates:
   *  UnitDelay: '<S194>/UD'
   *
   * Block description for '<S194>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S194>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_Product_hi - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S180>/Saturation' */
  if (rtb_Add_jp > Steering_Motor_Control_D_UL) {
    rtb_Add_jp = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_jp < Steering_Motor_Control_D_LL) {
    rtb_Add_jp = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S180>/Add' incorporates:
   *  Gain: '<S180>/Gain1'
   *  Saturate: '<S180>/Saturation'
   */
  rtb_Add_k = (Steering_Motor_Control_P * rtb_Switch2_nt) + rtb_Add_jp;

  /* Sum: '<S180>/Subtract' incorporates:
   *  Constant: '<S180>/Constant'
   */
  rtb_Optimized_Module_Angle_p = 1.0 - rtb_Add_k;

  /* Sum: '<S180>/Sum2' incorporates:
   *  Gain: '<S180>/Gain2'
   *  UnitDelay: '<S180>/Unit Delay'
   */
  rtb_Switch2_nt = (Steering_Motor_Control_I * rtb_Switch2_nt) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S196>/Switch2' incorporates:
   *  Constant: '<S180>/Constant'
   *  RelationalOperator: '<S196>/LowerRelop1'
   *  Sum: '<S180>/Subtract'
   */
  if (!(rtb_Switch2_nt > (1.0 - rtb_Add_k))) {
    /* Switch: '<S196>/Switch' incorporates:
     *  Constant: '<S180>/Constant1'
     *  RelationalOperator: '<S196>/UpperRelop'
     *  Sum: '<S180>/Subtract1'
     */
    if (rtb_Switch2_nt < (-1.0 - rtb_Add_k)) {
      rtb_Optimized_Module_Angle_p = -1.0 - rtb_Add_k;
    } else {
      rtb_Optimized_Module_Angle_p = rtb_Switch2_nt;
    }

    /* End of Switch: '<S196>/Switch' */
  }

  /* End of Switch: '<S196>/Switch2' */

  /* Saturate: '<S180>/Saturation1' */
  if (rtb_Optimized_Module_Angle_p > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_a = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle_p < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_a = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_a = rtb_Optimized_Module_Angle_p;
  }

  /* End of Saturate: '<S180>/Saturation1' */

  /* Sum: '<S180>/Add1' */
  rtb_Add_jp = rtb_Add_k + rtb_Subtract1_a;

  /* Saturate: '<S180>/Saturation2' */
  if (rtb_Add_jp > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_jp < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_jp;
  }

  /* End of Saturate: '<S180>/Saturation2' */

  /* Switch: '<S290>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S290>/Switch' incorporates:
     *  Fcn: '<S291>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2_idx_1,
      rtb_Add2_idx_0);
  }

  /* End of Switch: '<S290>/Switch' */

  /* Trigonometry: '<S210>/Cos4' incorporates:
   *  Switch: '<S199>/Angle_Switch'
   *  Trigonometry: '<S209>/Cos4'
   */
  rtb_Add_k = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S210>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S208>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S210>/Sin4' incorporates:
   *  Switch: '<S199>/Angle_Switch'
   *  Trigonometry: '<S209>/Sin4'
   */
  rtb_Integral_hv = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S210>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S208>/Unary Minus'
   */
  rtb_Optimized_Module_Angle_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S210>/Subtract1' incorporates:
   *  Product: '<S210>/Product2'
   *  Product: '<S210>/Product3'
   *  Trigonometry: '<S210>/Cos4'
   *  Trigonometry: '<S210>/Sin4'
   */
  rtb_Switch2_nt = (rtb_Add_k * rtb_uDLookupTable) + (rtb_Integral_hv *
    rtb_Optimized_Module_Angle_p);

  /* Sum: '<S210>/Subtract' incorporates:
   *  Product: '<S210>/Product'
   *  Product: '<S210>/Product1'
   *  Trigonometry: '<S210>/Cos4'
   *  Trigonometry: '<S210>/Sin4'
   */
  rtb_Optimized_Module_Angle_p = (rtb_Add_k * rtb_Optimized_Module_Angle_p) -
    (rtb_Integral_hv * rtb_uDLookupTable);

  /* Math: '<S210>/Hypot' */
  rtb_uDLookupTable = rt_hypotd_snf(rtb_Optimized_Module_Angle_p, rtb_Switch2_nt);

  /* Switch: '<S210>/Switch' incorporates:
   *  Constant: '<S210>/Constant'
   *  Constant: '<S210>/Constant1'
   *  Constant: '<S211>/Constant'
   *  Product: '<S210>/Divide'
   *  Product: '<S210>/Divide1'
   *  RelationalOperator: '<S211>/Compare'
   *  Switch: '<S210>/Switch1'
   */
  if (rtb_uDLookupTable > 1.0E-6) {
    rtb_Switch2_nt /= rtb_uDLookupTable;
    rtb_Optimized_Module_Angle_p /= rtb_uDLookupTable;
  } else {
    rtb_Switch2_nt = 0.0;
    rtb_Optimized_Module_Angle_p = 1.0;
  }

  /* End of Switch: '<S210>/Switch' */

  /* Product: '<S275>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch1;

  /* Switch: '<S199>/Speed_Switch' incorporates:
   *  Abs: '<S199>/Abs'
   *  Constant: '<S207>/Constant'
   *  RelationalOperator: '<S207>/Compare'
   *  Switch: '<S199>/Angle_Switch'
   *  Trigonometry: '<S209>/Atan1'
   *  Trigonometry: '<S210>/Atan1'
   *  UnaryMinus: '<S199>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_nt, rtb_Optimized_Module_Angle_p)) >
      1.5707963267948966) {
    rtb_Switch1 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S209>/Subtract1' incorporates:
     *  Product: '<S209>/Product2'
     *  Product: '<S209>/Product3'
     *  UnaryMinus: '<S199>/Unary Minus'
     */
    rtb_Switch2_nt = (rtb_Add_k * Robot_Control_ConstB.Sin5_e) +
      (rtb_Integral_hv * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S209>/Subtract' incorporates:
     *  Product: '<S209>/Product'
     *  Product: '<S209>/Product1'
     */
    rtb_Add_k = (rtb_Add_k * Robot_Control_ConstB.Cos5_i) - (rtb_Integral_hv *
      Robot_Control_ConstB.Sin5_e);

    /* Math: '<S209>/Hypot' */
    rtb_Optimized_Module_Angle_p = rt_hypotd_snf(rtb_Add_k, rtb_Switch2_nt);

    /* Switch: '<S209>/Switch1' incorporates:
     *  Constant: '<S209>/Constant'
     *  Constant: '<S209>/Constant1'
     *  Constant: '<S212>/Constant'
     *  Product: '<S209>/Divide'
     *  Product: '<S209>/Divide1'
     *  RelationalOperator: '<S212>/Compare'
     *  Switch: '<S209>/Switch'
     */
    if (rtb_Optimized_Module_Angle_p > 1.0E-6) {
      rtb_Add_k /= rtb_Optimized_Module_Angle_p;
      rtb_Switch2_nt /= rtb_Optimized_Module_Angle_p;
    } else {
      rtb_Add_k = 1.0;
      rtb_Switch2_nt = 0.0;
    }

    /* End of Switch: '<S209>/Switch1' */
    rtb_Optimized_Module_Angle_p = rt_atan2d_snf(rtb_Switch2_nt, rtb_Add_k);
  } else {
    rtb_Switch1 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle_p = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* End of Switch: '<S199>/Speed_Switch' */

  /* Product: '<S202>/Product2' incorporates:
   *  Constant: '<S202>/Constant'
   */
  rtb_Switch1 *= 1210.9758620668042;

  /* Signum: '<S197>/Sign' */
  if (rtIsNaN(rtb_Switch1)) {
    rtb_Add_jp = (rtNaN);
  } else if (rtb_Switch1 < 0.0) {
    rtb_Add_jp = -1.0;
  } else {
    rtb_Add_jp = (rtb_Switch1 > 0.0);
  }

  /* Signum: '<S197>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_k = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_k = -1.0;
  } else {
    rtb_Add_k = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S200>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S201>/Sum'
   */
  rtb_Optimized_Module_Angle_p -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S152>/Product' incorporates:
   *  Abs: '<S197>/Abs'
   *  Abs: '<S200>/Abs'
   *  Constant: '<S203>/Constant'
   *  Constant: '<S213>/Constant3'
   *  Constant: '<S213>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S197>/OR'
   *  Lookup_n-D: '<S200>/1-D Lookup Table'
   *  Math: '<S213>/Math Function'
   *  RelationalOperator: '<S197>/Equal1'
   *  RelationalOperator: '<S203>/Compare'
   *  Signum: '<S197>/Sign'
   *  Signum: '<S197>/Sign1'
   *  Sum: '<S200>/Add'
   *  Sum: '<S213>/Add1'
   *  Sum: '<S213>/Add2'
   */
  rtb_Switch1 = (((real_T)((rtb_Add_jp == rtb_Add_k) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch1) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle_p + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Sum: '<S198>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_nt = rtb_Switch1 - Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S205>/Sum1' incorporates:
   *  Constant: '<S198>/Constant2'
   *  Product: '<S205>/Product'
   *  Sum: '<S205>/Sum'
   *  UnitDelay: '<S205>/Unit Delay1'
   */
  rtb_Add_k = ((rtb_Switch2_nt - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
               Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S198>/Product' incorporates:
   *  Constant: '<S198>/Constant3'
   */
  rtb_uDLookupTable = rtb_Add_k * Drive_Motor_Control_D;

  /* Sum: '<S204>/Diff' incorporates:
   *  UnitDelay: '<S204>/UD'
   *
   * Block description for '<S204>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S204>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_uDLookupTable - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S198>/Saturation' */
  if (rtb_Add_jp > Drive_Motor_Control_D_UL) {
    rtb_Add_jp = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_jp < Drive_Motor_Control_D_LL) {
    rtb_Add_jp = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S198>/Add' incorporates:
   *  Gain: '<S198>/Gain'
   *  Gain: '<S198>/Gain1'
   *  Saturate: '<S198>/Saturation'
   */
  rtb_Switch1 = ((Drive_Motor_Control_FF * rtb_Switch1) + (Drive_Motor_Control_P
    * rtb_Switch2_nt)) + rtb_Add_jp;

  /* Saturate: '<S198>/Saturation2' incorporates:
   *  Sum: '<S198>/Add1'
   */
  if (rtb_Switch1 > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch1 < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Switch1;
  }

  /* End of Saturate: '<S198>/Saturation2' */

  /* Sum: '<S214>/Add1' incorporates:
   *  Constant: '<S214>/Constant3'
   *  Constant: '<S214>/Constant4'
   *  Math: '<S214>/Math Function'
   *  Sum: '<S214>/Add2'
   */
  rtb_Switch1 = rt_modd_snf(rtb_Optimized_Module_Angle_p + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S216>/Sum1' incorporates:
   *  Constant: '<S201>/Constant2'
   *  Product: '<S216>/Product'
   *  Sum: '<S216>/Sum'
   *  UnitDelay: '<S216>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle_p = ((rtb_Switch1 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S201>/Product' incorporates:
   *  Constant: '<S201>/Constant3'
   */
  rtb_Integral_hv = rtb_Optimized_Module_Angle_p * Steering_Motor_Control_D;

  /* Sum: '<S215>/Diff' incorporates:
   *  UnitDelay: '<S215>/UD'
   *
   * Block description for '<S215>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S215>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_Integral_hv - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S201>/Saturation' */
  if (rtb_Add_jp > Steering_Motor_Control_D_UL) {
    rtb_Add_jp = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_jp < Steering_Motor_Control_D_LL) {
    rtb_Add_jp = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S201>/Add' incorporates:
   *  Gain: '<S201>/Gain1'
   *  Saturate: '<S201>/Saturation'
   */
  rtb_Add2_idx_0 = (Steering_Motor_Control_P * rtb_Switch1) + rtb_Add_jp;

  /* Sum: '<S201>/Subtract' incorporates:
   *  Constant: '<S201>/Constant'
   */
  rtb_Switch2_nt = 1.0 - rtb_Add2_idx_0;

  /* Sum: '<S201>/Sum2' incorporates:
   *  Gain: '<S201>/Gain2'
   *  UnitDelay: '<S201>/Unit Delay'
   */
  rtb_Switch1 = (Steering_Motor_Control_I * rtb_Switch1) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S217>/Switch2' incorporates:
   *  Constant: '<S201>/Constant'
   *  RelationalOperator: '<S217>/LowerRelop1'
   *  Sum: '<S201>/Subtract'
   */
  if (!(rtb_Switch1 > (1.0 - rtb_Add2_idx_0))) {
    /* Sum: '<S201>/Subtract1' incorporates:
     *  Constant: '<S201>/Constant1'
     */
    rtb_Switch2_nt = -1.0 - rtb_Add2_idx_0;

    /* Switch: '<S217>/Switch' incorporates:
     *  Constant: '<S201>/Constant1'
     *  RelationalOperator: '<S217>/UpperRelop'
     *  Sum: '<S201>/Subtract1'
     */
    if (!(rtb_Switch1 < (-1.0 - rtb_Add2_idx_0))) {
      rtb_Switch2_nt = rtb_Switch1;
    }

    /* End of Switch: '<S217>/Switch' */
  }

  /* End of Switch: '<S217>/Switch2' */

  /* Saturate: '<S201>/Saturation1' */
  if (rtb_Switch2_nt > Steering_Motor_Control_I_UL) {
    rtb_Add2_idx_1 = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_nt < Steering_Motor_Control_I_LL) {
    rtb_Add2_idx_1 = Steering_Motor_Control_I_LL;
  } else {
    rtb_Add2_idx_1 = rtb_Switch2_nt;
  }

  /* End of Saturate: '<S201>/Saturation1' */

  /* Sum: '<S201>/Add1' */
  rtb_Add_jp = rtb_Add2_idx_0 + rtb_Add2_idx_1;

  /* Saturate: '<S201>/Saturation2' */
  if (rtb_Add_jp > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_jp < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_jp;
  }

  /* End of Saturate: '<S201>/Saturation2' */

  /* Sum: '<S235>/Add1' incorporates:
   *  Constant: '<S235>/Constant3'
   *  Constant: '<S235>/Constant4'
   *  Math: '<S235>/Math Function'
   *  Sum: '<S235>/Add2'
   */
  rtb_Switch1 = rt_modd_snf(rtb_Switch2 + 3.1415926535897931, 6.2831853071795862)
    - 3.1415926535897931;

  /* Sum: '<S237>/Sum1' incorporates:
   *  Constant: '<S222>/Constant2'
   *  Product: '<S237>/Product'
   *  Sum: '<S237>/Sum'
   *  UnitDelay: '<S237>/Unit Delay1'
   */
  rtb_Switch2 = ((rtb_Switch1 - Robot_Control_DW.UnitDelay1_DSTATE_i) *
                 Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S222>/Product' incorporates:
   *  Constant: '<S222>/Constant3'
   */
  rtb_Add2_idx_0 = rtb_Switch2 * Steering_Motor_Control_D;

  /* Sum: '<S236>/Diff' incorporates:
   *  UnitDelay: '<S236>/UD'
   *
   * Block description for '<S236>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S236>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_jp = rtb_Add2_idx_0 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S222>/Saturation' */
  if (rtb_Add_jp > Steering_Motor_Control_D_UL) {
    rtb_Add_jp = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_jp < Steering_Motor_Control_D_LL) {
    rtb_Add_jp = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S222>/Add' incorporates:
   *  Gain: '<S222>/Gain1'
   *  Saturate: '<S222>/Saturation'
   */
  rtb_Add_jp += Steering_Motor_Control_P * rtb_Switch1;

  /* Sum: '<S222>/Subtract' incorporates:
   *  Constant: '<S222>/Constant'
   */
  rtb_Switch2_nt = 1.0 - rtb_Add_jp;

  /* Sum: '<S222>/Sum2' incorporates:
   *  Gain: '<S222>/Gain2'
   *  UnitDelay: '<S222>/Unit Delay'
   */
  rtb_Switch1 = (Steering_Motor_Control_I * rtb_Switch1) +
    Robot_Control_DW.UnitDelay_DSTATE_lm;

  /* Switch: '<S238>/Switch2' incorporates:
   *  Constant: '<S222>/Constant'
   *  RelationalOperator: '<S238>/LowerRelop1'
   *  Sum: '<S222>/Subtract'
   */
  if (!(rtb_Switch1 > (1.0 - rtb_Add_jp))) {
    /* Sum: '<S222>/Subtract1' incorporates:
     *  Constant: '<S222>/Constant1'
     */
    rtb_Switch2_nt = -1.0 - rtb_Add_jp;

    /* Switch: '<S238>/Switch' incorporates:
     *  Constant: '<S222>/Constant1'
     *  RelationalOperator: '<S238>/UpperRelop'
     *  Sum: '<S222>/Subtract1'
     */
    if (!(rtb_Switch1 < (-1.0 - rtb_Add_jp))) {
      rtb_Switch2_nt = rtb_Switch1;
    }

    /* End of Switch: '<S238>/Switch' */
  }

  /* End of Switch: '<S238>/Switch2' */

  /* Saturate: '<S222>/Saturation1' */
  if (rtb_Switch2_nt > Steering_Motor_Control_I_UL) {
    rtb_Switch1 = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_nt < Steering_Motor_Control_I_LL) {
    rtb_Switch1 = Steering_Motor_Control_I_LL;
  } else {
    rtb_Switch1 = rtb_Switch2_nt;
  }

  /* End of Saturate: '<S222>/Saturation1' */

  /* Sum: '<S222>/Add1' */
  rtb_Add_jp += rtb_Switch1;

  /* Saturate: '<S222>/Saturation2' */
  if (rtb_Add_jp > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_jp < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_jp;
  }

  /* End of Saturate: '<S222>/Saturation2' */

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

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   *  Inport: '<Root>/Gamepad_POV'
   */
  Robot_Control_B.Gamepad_POV_Up = (Robot_Control_U.Gamepad_POV == 0.0);

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   *  Inport: '<Root>/Gamepad_POV'
   */
  Robot_Control_B.Gamepad_POV_Down = (Robot_Control_U.Gamepad_POV == 180.0);

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   *  Inport: '<Root>/Gamepad_POV'
   */
  Robot_Control_B.Gamepad_POV_Right = (Robot_Control_U.Gamepad_POV == 90.0);

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   *  Inport: '<Root>/Gamepad_POV'
   */
  Robot_Control_B.Gamepad_POV_Left = (Robot_Control_U.Gamepad_POV == 270.0);

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/Joystick_Left_B7'
   */
  Robot_Control_B.Drive_Engage_Hook = (Robot_Control_U.Joystick_Left_B7 != 0.0);

  /* RelationalOperator: '<S27>/Compare' incorporates:
   *  Constant: '<S27>/Constant'
   *  Inport: '<Root>/Joystick_Left_B2'
   */
  Robot_Control_B.Align_Center = (Robot_Control_U.Joystick_Left_B2 != 0.0);

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   *  Inport: '<Root>/Joystick_Left_B8'
   */
  Robot_Control_B.Actuator_Cmd = (Robot_Control_U.Joystick_Left_B8 != 0.0);

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   *  Inport: '<Root>/Joystick_Left_B5'
   */
  Robot_Control_B.Winch_Cmd = (Robot_Control_U.Joystick_Left_B5 != 0.0);

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant2'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  Robot_Control_B.loop_counter_robot_control++;

  /* SignalConversion: '<S4>/Signal Copy4' incorporates:
   *  Inport: '<Root>/Joystick_Right_X'
   */
  Robot_Control_B.Steer_Joystick_X = Robot_Control_U.Joystick_Right_X;

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_jp = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_jp)) || (rtIsInf(rtb_Add_jp))) {
    rtb_Add_jp = 0.0;
  } else {
    rtb_Add_jp = fmod(rtb_Add_jp, 256.0);
  }

  rtb_Desired_Pipeline = (uint8_T)((rtb_Add_jp < 0.0) ? ((int32_T)((uint8_T)
    (-((int8_T)((uint8_T)(-rtb_Add_jp)))))) : ((int32_T)((uint8_T)rtb_Add_jp)));

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* Chart: '<S8>/Chart' */
  if (Robot_Control_DW.is_active_c9_Robot_Control == 0U) {
    Robot_Control_DW.is_active_c9_Robot_Control = 1U;
    Robot_Control_B.Active_GameState = 0U;
    Robot_Control_DW.is_c9_Robot_Control = Robot_Control_IN_Disabled;
  } else if (Robot_Control_DW.is_c9_Robot_Control == Robot_Control_IN_Disabled)
  {
    if (rtb_Desired_Pipeline != 0) {
      Robot_Control_DW.is_c9_Robot_Control = Robot_Control_IN_Not_Disabled;
      Robot_Control_B.Active_GameState = rtb_Desired_Pipeline;
    }

    /* case IN_Not_Disabled: */
  } else if (rtb_Desired_Pipeline == 0) {
    Robot_Control_DW.is_c9_Robot_Control = Robot_Control_IN_Disabled;
  } else {
    Robot_Control_B.Active_GameState = rtb_Desired_Pipeline;
  }

  /* End of Chart: '<S8>/Chart' */

  /* Update for UnitDelay: '<S31>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B11'
   *
   * Block description for '<S31>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Joystick_Left_B11;

  /* Update for UnitDelay: '<S32>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B12'
   *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Joystick_Left_B12;

  /* Update for UnitDelay: '<S33>/Delay Input1' incorporates:
   *  Inport: '<Root>/Joystick_Left_B13'
   *
   * Block description for '<S33>/Delay Input1':
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

  /* Update for Delay: '<S34>/MemoryX' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S54>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S34>/A'
   *  Delay: '<S34>/MemoryX'
   */
  rtb_Switch2_nt = (0.0 * Robot_Control_DW.MemoryX_DSTATE[1]) +
    Robot_Control_DW.MemoryX_DSTATE[0];
  rtb_Add_jp = (0.0 * Robot_Control_DW.MemoryX_DSTATE[0]) +
    Robot_Control_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S34>/MemoryX' incorporates:
   *  Constant: '<S34>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S54>/A[k]*xhat[k|k-1]'
   *  Product: '<S54>/B[k]*u[k]'
   *  Sum: '<S54>/Add'
   */
  Robot_Control_DW.MemoryX_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + rtb_Switch2_nt) + Robot_Control_B.Product3[0];
  Robot_Control_DW.MemoryX_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + rtb_Add_jp) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S250>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S250>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S272>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S271>/UD'
   *
   * Block description for '<S271>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Add_h5;

  /* Update for UnitDelay: '<S269>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_m = rtb_Subtract_e;

  /* Update for UnitDelay: '<S252>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S267>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S267>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S267>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S251>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Sin4;

  /* Update for UnitDelay: '<S260>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S260>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S260>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Sin4;

  /* Update for UnitDelay: '<S226>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Init;

  /* Update for UnitDelay: '<S225>/UD'
   *
   * Block description for '<S225>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Switch2_k;

  /* Update for UnitDelay: '<S219>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l = 0.0;

  /* Update for UnitDelay: '<S163>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Hypot;

  /* Update for UnitDelay: '<S162>/UD'
   *
   * Block description for '<S162>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Switch2_a;

  /* Update for UnitDelay: '<S156>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S174>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S173>/UD'
   *
   * Block description for '<S173>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Switch2_pt;

  /* Update for UnitDelay: '<S159>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S184>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Add_fn;

  /* Update for UnitDelay: '<S183>/UD'
   *
   * Block description for '<S183>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Hypot_b;

  /* Update for UnitDelay: '<S177>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;

  /* Update for UnitDelay: '<S195>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Switch2_e;

  /* Update for UnitDelay: '<S194>/UD'
   *
   * Block description for '<S194>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_hi;

  /* Update for UnitDelay: '<S180>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Subtract1_a;

  /* Update for UnitDelay: '<S205>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_Add_k;

  /* Update for UnitDelay: '<S204>/UD'
   *
   * Block description for '<S204>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S198>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_f = 0.0;

  /* Update for UnitDelay: '<S216>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle_p;

  /* Update for UnitDelay: '<S215>/UD'
   *
   * Block description for '<S215>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Integral_hv;

  /* Update for UnitDelay: '<S201>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Add2_idx_1;

  /* Update for UnitDelay: '<S237>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Switch2;

  /* Update for UnitDelay: '<S236>/UD'
   *
   * Block description for '<S236>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_Add2_idx_0;

  /* Update for UnitDelay: '<S222>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_lm = rtb_Switch1;
}

/* Model initialize function */
void Robot_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  Robot_Control_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S9>/If' */
  Robot_Control_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for Delay: '<S34>/MemoryX' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S250>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S267>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S260>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S321>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S9>/Spline Path Following Enabled' */
  /* Start for If: '<S95>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S91>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S95>/Robot_Index_Is_Valid' */
  /* Start for If: '<S98>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S98>/Circle_Check_Valid' */
  /* Start for If: '<S100>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S98>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S95>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S9>/Spline Path Following Enabled' */
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
