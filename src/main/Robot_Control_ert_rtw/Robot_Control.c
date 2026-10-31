/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 7.6
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Fri Oct 30 21:51:34 2026
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
#include "plook_u32d_evencka.h"
#include "look1_binlcpw.h"
#include "Robot_Control_private.h"

/* Named constants for Chart: '<S8>/Chart' */
#define Robot_Contro_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Robot_Control_IN_Disabled      ((uint8_T)1U)
#define Robot_Control_IN_Not_Disabled  ((uint8_T)2U)

/* Named constants for Chart: '<S250>/Add dither' */
#define Robot_Control_IN_Dither        ((uint8_T)1U)
#define Robot_Control_IN_No_Dither     ((uint8_T)2U)

/* Named constants for Chart: '<S16>/Chart' */
#define Robot_Control_IN_End_Action    ((uint8_T)1U)
#define Robot_Control_IN_Follow_Path   ((uint8_T)2U)
#define Robot_Control_IN_Start_Action  ((uint8_T)3U)

/* Exported block parameters */
real_T Auto_Path_Chooser = 3.0;        /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S17>/Constant17'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S317>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S313>/Constant'
                                        *   '<S313>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S317>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S313>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S153>/Constant3'
                                        *   '<S174>/Constant3'
                                        *   '<S195>/Constant3'
                                        *   '<S216>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S153>/Constant2'
                                   *   '<S174>/Constant2'
                                   *   '<S195>/Constant2'
                                   *   '<S216>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S153>/Saturation'
                                        *   '<S174>/Saturation'
                                        *   '<S195>/Saturation'
                                        *   '<S216>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S153>/Saturation'
                                        *   '<S174>/Saturation'
                                        *   '<S195>/Saturation'
                                        *   '<S216>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S153>/Gain'
                                            *   '<S174>/Gain'
                                            *   '<S195>/Gain'
                                            *   '<S216>/Gain'
                                            */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S153>/Gain1'
                                        *   '<S174>/Gain1'
                                        *   '<S195>/Gain1'
                                        *   '<S216>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S158>/Constant'
                            *   '<S179>/Constant'
                            *   '<S200>/Constant'
                            *   '<S221>/Constant'
                            */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S303>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S303>/Constant5'
                                          */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S6>/Constant2'
                                        */
real_T Relative_Steering_Error_Angle_Gain = 0.05;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S302>/Constant4'
                                  */
real_T Relative_Steering_Error_Angle_Gain_Object_Factor = 0.1;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S300>/Gain'
                    */
real_T Relative_Steering_Speed_Max = 0.3;/* Variable: Relative_Steering_Speed_Max
                                          * Referenced by: '<S302>/Constant10'
                                          */
real_T Relative_Translation_Control_Gain = 0.05;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S303>/Gain1'
                                   */
real_T Relative_Translation_Speed_Max = 2.0;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S303>/Constant8'
                                      */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S142>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S142>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S89>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S102>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S142>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S249>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S249>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S249>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S249>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S249>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S249>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S267>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S267>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S267>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S267>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S266>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S267>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S267>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S267>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S267>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S267>/Constant1'
                                   *   '<S267>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S267>/Constant'
                                   *   '<S267>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S250>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S250>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S250>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S250>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S156>/Constant3'
                                        *   '<S177>/Constant3'
                                        *   '<S198>/Constant3'
                                        *   '<S219>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S156>/Constant2'
                                *   '<S177>/Constant2'
                                *   '<S198>/Constant2'
                                *   '<S219>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S156>/Saturation'
                                           *   '<S177>/Saturation'
                                           *   '<S198>/Saturation'
                                           *   '<S219>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S156>/Saturation'
                                          *   '<S177>/Saturation'
                                          *   '<S198>/Saturation'
                                          *   '<S219>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S156>/Gain2'
                                         *   '<S177>/Gain2'
                                         *   '<S198>/Gain2'
                                         *   '<S219>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S156>/Saturation1'
                                             *   '<S177>/Saturation1'
                                             *   '<S198>/Saturation1'
                                             *   '<S219>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S156>/Saturation1'
                                            *   '<S177>/Saturation1'
                                            *   '<S198>/Saturation1'
                                            *   '<S219>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S156>/Gain1'
                                        *   '<S177>/Gain1'
                                        *   '<S198>/Gain1'
                                        *   '<S219>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S248>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S248>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S248>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S248>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S248>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S248>/Constant3'
                                */
real_T Steering_Relative_Gain = 3.5;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S302>/Constant'
                                        */
real_T Steering_Twist_Gain = -0.5;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S302>/Constant1'
                                        */
real_T TEST_Swerve_Mode_Override_Flag = 0.0;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S301>/Constant5'
                                      */
real_T TEST_Swerve_Mode_Steering = 0.0;/* Variable: TEST_Swerve_Mode_Steering
                                        * Referenced by: '<S301>/Constant8'
                                        */
real_T TEST_Swerve_Mode_Translation = 0.0;/* Variable: TEST_Swerve_Mode_Translation
                                           * Referenced by: '<S301>/Constant7'
                                           */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S236>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S236>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S236>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S236>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S236>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S236>/Constant3'
                                    */
real_T Translation_Twist_Gain = -0.5;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S303>/Gain'
                                        */
real_T Twist_Deadzone_neg = -0.01;     /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S302>/Dead Zone'
                                        *   '<S303>/Dead Zone'
                                        */
real_T Twist_Deadzone_pos = 0.01;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S302>/Dead Zone'
                                        *   '<S303>/Dead Zone'
                                        */
real_T Vision_Object_Angle_Offset = 0.0;/* Variable: Vision_Object_Angle_Offset
                                         * Referenced by: '<S13>/Constant6'
                                         */
real_T Vision_Object_Target_Angle = 0.0;/* Variable: Vision_Object_Target_Angle
                                         * Referenced by: '<S300>/Constant7'
                                         */
real_T Vision_Object_Target_X = 35.0;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S300>/Constant1'
                                        */
real_T Vision_Object_Target_Y = 0.0;   /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S300>/Constant4'
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
                                        * Referenced by: '<S300>/Constant8'
                                        */
real_T Vision_Tag_Target_X = 30.0;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S300>/Constant2'
                                        */
real_T Vision_Tag_Target_Y = 0.0;      /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S300>/Constant5'
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
                                        *   '<S300>/Constant11'
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
  real_T rtb_Add2[2];
  real_T rtb_TmpSignalConversionAtLoo_mu[2];
  real_T rtb_TmpSignalConversionAtLookup[2];
  real_T rtb_Add_f1;
  real_T rtb_Add_pw;
  real_T rtb_Hypot;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Integral_k;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_MatrixConcatenate_idx_0;
  real_T rtb_Merge1;
  real_T rtb_Minus_k_idx_0;
  real_T rtb_Minus_k_idx_1;
  real_T rtb_Modulation_Drv;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Product_f;
  real_T rtb_Product_k5;
  real_T rtb_Product_kx;
  real_T rtb_Product_lb;
  real_T rtb_Saturation_h;
  real_T rtb_Subtract;
  real_T rtb_Subtract1_la;
  real_T rtb_Subtract_e;
  real_T rtb_Subtract_i;
  real_T rtb_Sum2_fc;
  real_T rtb_Switch1_c;
  real_T rtb_Switch2;
  real_T rtb_UnitDelay3;
  real_T rtb_uDLookupTable;
  real_T tmp;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s114_iter;
  uint16_T s139_iter;
  int8_T rtb_MultiportSwitch1[3];
  int8_T rtAction;
  int8_T rtPrevAction;
  uint8_T rtb_GameState;
  boolean_T exitg1;
  boolean_T rtb_AND1;
  boolean_T rtb_Compare_bd;
  boolean_T rtb_Compare_ky;
  boolean_T rtb_Compare_mq;
  boolean_T rtb_Compare_ph;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator1_h;
  boolean_T rtb_LogicalOperator5;

  /* RelationalOperator: '<S22>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *  UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Gamepad_B3_X >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S23>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets = (Robot_Control_U.Gamepad_B4_Y >
    Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Gamepad_B2_B >
    Robot_Control_DW.DelayInput1_DSTATE_n);

  /* SignalConversion: '<S4>/Signal Copy1' incorporates:
   *  Inport: '<Root>/Xbox_Driver_Stick_Left_X'
   */
  Robot_Control_B.Drive_Joystick_X = Robot_Control_U.Xbox_Driver_Stick_Left_X;

  /* SignalConversion: '<S4>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Xbox_Driver_Stick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y = Robot_Control_U.Xbox_Driver_Stick_Left_Y;

  /* SignalConversion: '<S4>/Signal Copy5' incorporates:
   *  Inport: '<Root>/Xbox_Driver_Stick_Right_Y'
   */
  Robot_Control_B.Steer_Joystick_Y = Robot_Control_U.Xbox_Driver_Stick_Right_Y;

  /* Logic: '<S20>/Logical Operator7' incorporates:
   *  Inport: '<Root>/Xbox_Driver_ButtonA'
   *  Inport: '<Root>/Xbox_Driver_ButtonY'
   */
  rtb_Compare_bd = ((Robot_Control_U.Xbox_Driver_ButtonY) ||
                    (Robot_Control_U.Xbox_Driver_ButtonA));

  /* Sum: '<S21>/Add1' incorporates:
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S21>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Math: '<S21>/Math Function'
   *  Sum: '<S21>/Add2'
   */
  rtb_Subtract_e = rt_modd_snf(Robot_Control_U.Gyro_Angle_rad +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* RelationalOperator: '<S20>/GreaterThan' incorporates:
   *  Abs: '<S20>/Abs'
   *  Constant: '<S20>/Constant2'
   */
  rtb_Compare_ky = (fabs(rtb_Subtract_e) > 1.5707963267948966);

  /* Logic: '<S20>/Logical Operator1' */
  rtb_LogicalOperator1 = (rtb_Compare_bd && rtb_Compare_ky);

  /* Logic: '<S20>/Logical Operator' incorporates:
   *  Inport: '<Root>/Xbox_Driver_ButtonB'
   *  Inport: '<Root>/Xbox_Driver_ButtonX'
   */
  rtb_Compare_mq = ((Robot_Control_U.Xbox_Driver_ButtonX) ||
                    (Robot_Control_U.Xbox_Driver_ButtonB));

  /* RelationalOperator: '<S20>/GreaterThan1' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  rtb_Compare_ph = (rtb_Subtract_e > 0.0);

  /* Logic: '<S20>/Logical Operator5' incorporates:
   *  Logic: '<S20>/Logical Operator6'
   */
  rtb_LogicalOperator5 = (rtb_Compare_mq && (!rtb_Compare_ph));

  /* Logic: '<S20>/Logical Operator3' */
  rtb_Compare_mq = (rtb_Compare_mq && rtb_Compare_ph);

  /* Logic: '<S20>/Logical Operator2' incorporates:
   *  Logic: '<S20>/Logical Operator4'
   */
  rtb_Compare_bd = (rtb_Compare_bd && (!rtb_Compare_ky));

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

  /* If: '<S329>/If' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Area_pct'
   */
  if (Robot_Control_U.Vision_c1_Object_Area_pct > 0.0) {
    /* Outputs for IfAction SubSystem: '<S329>/Prevent raising 0 to a negative exponent' incorporates:
     *  ActionPort: '<S332>/Action Port'
     */
    /* Product: '<S332>/Product' incorporates:
     *  Constant: '<S332>/Constant1'
     *  Constant: '<S332>/Constant2'
     *  Math: '<S332>/Math Function'
     */
    rtb_Switch1_c = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S329>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S329>/Subsystem' incorporates:
     *  ActionPort: '<S333>/Action Port'
     */
    /* SignalConversion generated from: '<S333>/Out1' incorporates:
     *  Constant: '<S333>/Constant'
     */
    rtb_Switch1_c = 0.0;

    /* End of Outputs for SubSystem: '<S329>/Subsystem' */
  }

  /* End of If: '<S329>/If' */

  /* Gain: '<S330>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Subtract_e = 0.017453292519943295 *
    Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S13>/Add3' incorporates:
   *  Constant: '<S13>/Constant4'
   *  Fcn: '<S331>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Switch1_c * cos
    (rtb_Subtract_e)) + Vision_Object_X_Offset;

  /* Sum: '<S13>/Add4' incorporates:
   *  Constant: '<S13>/Constant8'
   *  Fcn: '<S331>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Switch1_c * sin
    (rtb_Subtract_e)) + Vision_Object_Y_Offset;

  /* Sum: '<S13>/Add5' incorporates:
   *  Constant: '<S13>/Constant6'
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_Object_Hor_deg + Vision_Object_Angle_Offset;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Robot_Control_DW.SwitchCase_ActiveSubsystem;
  rtb_Add_f1 = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_f1)) || (rtIsInf(rtb_Add_f1))) {
    rtb_Add_f1 = 0.0;
  } else {
    rtb_Add_f1 = fmod(rtb_Add_f1, 4.294967296E+9);
  }

  switch ((rtb_Add_f1 < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_f1)))) :
          ((int32_T)((uint32_T)rtb_Add_f1))) {
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
    /* SignalConversion generated from: '<S3>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S7>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

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
    rtb_Compare_ph = false;

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

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  Constant: '<S3>/Constant18'
     *  SignalConversion generated from: '<S3>/Enable_Wheels'
     */
    Robot_Control_Y.Enable_Wheels = false;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S3>/Constant13'
     *  SignalConversion generated from: '<S3>/Reset_Wheel_Offsets'
     */
    Robot_Control_Y.Reset_Wheel_Offsets = false;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  Constant: '<S3>/Constant14'
     *  SignalConversion generated from: '<S3>/Disable_Wheels'
     */
    Robot_Control_Y.Disable_Wheels = false;

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S3>/Constant12'
     *  SignalConversion generated from: '<S3>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = true;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S3>/Constant25'
     *  SignalConversion generated from: '<S3>/Desired_Pipeline'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = 0U;

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S3>/Constant11'
     *  SignalConversion generated from: '<S3>/Auto_Initial_Gyro_Angle'
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
       *  UnitDelay: '<S16>/Unit Delay'
       *  UnitDelay: '<S16>/Unit Delay1'
       */
      memset(&Robot_Control_DW.UnitDelay1_DSTATE_iz[0], 0, 60U * (sizeof(real_T)));
      Robot_Control_DW.UnitDelay_DSTATE_e3 = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Autonomous' */

      /* SystemReset for IfAction SubSystem: '<S1>/Autonomous' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S16>/Chart'
       */
      Robot_Control_B.Auto_Desired_Static_Action = 0.0;
      Robot_Control_B.Auto_Desired_Dynamic_Action = 0.0;
      Robot_Control_B.Auto_Path_Counter = 0.0;
      Robot_Control_DW.counter = 0.0;
      Robot_Control_DW.is_active_c6_Robot_Control = 0U;
      Robot_Control_DW.is_c6_Robot_Control = Robot_Contro_IN_NO_ACTIVE_CHILD;

      /* End of SystemReset for SubSystem: '<S1>/Autonomous' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MultiPortSwitch: '<S17>/Multiport Switch1' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/Constant10'
     *  Constant: '<S17>/Constant11'
     *  Constant: '<S17>/Constant12'
     *  Constant: '<S17>/Constant13'
     *  Constant: '<S17>/Constant17'
     *  Constant: '<S17>/Constant2'
     *  Constant: '<S17>/Constant3'
     *  Constant: '<S17>/Constant4'
     *  Constant: '<S17>/Constant5'
     *  Constant: '<S17>/Constant6'
     *  Constant: '<S17>/Constant7'
     *  Constant: '<S17>/Constant8'
     *  Constant: '<S17>/Constant9'
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

    /* End of MultiPortSwitch: '<S17>/Multiport Switch1' */

    /* Saturate: '<S16>/Saturation' incorporates:
     *  UnitDelay: '<S5>/Unit Delay2'
     */
    if (Robot_Control_DW.UnitDelay2_DSTATE > 10.0) {
      rtb_Saturation_h = 10.0;
    } else if (Robot_Control_DW.UnitDelay2_DSTATE < 1.0) {
      rtb_Saturation_h = 1.0;
    } else {
      rtb_Saturation_h = Robot_Control_DW.UnitDelay2_DSTATE;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* Chart: '<S16>/Chart' incorporates:
     *  Selector: '<S16>/Selector1'
     *  Selector: '<S16>/Selector2'
     *  UnitDelay: '<S16>/Unit Delay'
     *  UnitDelay: '<S16>/Unit Delay1'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    if (Robot_Control_DW.is_active_c6_Robot_Control == 0) {
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
        if ((Robot_Control_B.Auto_Desired_Static_Action == 0.0) &&
            (Robot_Control_B.Auto_Path_Counter < Robot_Control_ConstB.Width)) {
          rtb_LogicalOperator1 = (rtb_MultiportSwitch1[((int32_T)
            (Robot_Control_B.Auto_Path_Counter + 1.0)) - 1] != 0);
        } else {
          rtb_LogicalOperator1 = false;
        }

        if (rtb_LogicalOperator1) {
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
            (Robot_Control_B.Auto_Desired_Static_Action == 0.0)) {
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

    /* End of Chart: '<S16>/Chart' */

    /* Lookup_n-D: '<S16>/1-D Lookup Table1' */
    Robot_Control_B.Auto_Path_ID = rtb_MultiportSwitch1[plook_u32d_evencka
      (Robot_Control_B.Auto_Path_Counter, 1.0, 1.0, 2U)];

    /* Switch: '<S16>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     */
    rtb_Compare_bd = (Robot_Control_U.IsBlueAlliance != 0.0);

    /* Selector: '<S16>/Selector' */
    rtb_Bias1_p = ((int32_T)Robot_Control_B.Auto_Path_ID) - 1;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Lookup_n-D: '<S16>/1-D Lookup Table'
     *  Lookup_n-D: '<S16>/1-D Lookup Table1'
     */
    Robot_Control_B.Spline_Num_Poses =
      rtCP_uDLookupTable_tableData[plook_u32d_evencka
      (Robot_Control_B.Auto_Path_ID, 1.0, 1.0, 24U)];

    /* Merge: '<S7>/Merge7' incorporates:
     *  SignalConversion: '<S14>/Signal Copy'
     */
    Robot_Control_B.Spline_Enable = Robot_Control_B.Auto_Spline_Enable;

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
    rtb_Compare_ph = false;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S14>/Constant2'
     *  SignalConversion generated from: '<S2>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S7>/Merge3' incorporates:
     *  Constant: '<S14>/Constant3'
     *  SignalConversion generated from: '<S2>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S7>/Merge4' incorporates:
     *  Constant: '<S14>/Constant4'
     *  SignalConversion generated from: '<S2>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* Merge: '<S7>/Merge10' incorporates:
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
    for (i = 0; i < 60; i++) {
      /* Switch: '<S16>/Switch' */
      if (rtb_Compare_bd) {
        /* Selector: '<S16>/Selector' incorporates:
         *  Constant: '<S16>/Constant'
         */
        rtb_Spline_Ref_Poses_h[i] = rtCP_Constant_Value_c[(rtb_Bias1_p * 60) + i];
      } else {
        /* Selector: '<S16>/Selector' incorporates:
         *  Constant: '<S16>/Constant1'
         */
        rtb_Spline_Ref_Poses_h[i] = rtCP_Constant1_Value_b[(rtb_Bias1_p * 60) +
          i];
      }

      /* Update for UnitDelay: '<S16>/Unit Delay1' incorporates:
       *  Selector: '<S16>/Selector'
       */
      Robot_Control_DW.UnitDelay1_DSTATE_iz[i] = rtb_Spline_Ref_Poses_h[i];
    }

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Selector: '<S14>/Select heading angle from first row'
     *  Selector: '<S16>/Selector'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = rtb_Spline_Ref_Poses_h[30];

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Saturation_h;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S302>/Unit Delay1'
       *  UnitDelay: '<S302>/Unit Delay2'
       *  UnitDelay: '<S302>/Unit Delay3'
       *  UnitDelay: '<S302>/Unit Delay4'
       *  UnitDelay: '<S305>/Delay Input1'
       *  UnitDelay: '<S306>/Delay Input1'
       *  UnitDelay: '<S307>/Delay Input1'
       *  UnitDelay: '<S308>/Delay Input1'
       *  UnitDelay: '<S310>/Delay Input1'
       *  UnitDelay: '<S316>/Unit Delay'
       *  UnitDelay: '<S316>/Unit Delay1'
       *  UnitDelay: '<S320>/FixPt Unit Delay1'
       *  UnitDelay: '<S320>/FixPt Unit Delay2'
       *
       * Block description for '<S305>/Delay Input1':
       *
       *  Store in Global RAM
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
       * Block description for '<S310>/Delay Input1':
       *
       *  Store in Global RAM
       */
      Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;
      Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_l = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_p = 0.0;
      Robot_Control_DW.DelayInput1_DSTATE_j = false;
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
     *  ActionPort: '<S11>/Action Port'
     */
    /* SignalConversion generated from: '<S11>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S7>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

    /* SignalConversion generated from: '<S313>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S313>/X1_Values'
     *  Constant: '<S313>/X_values'
     */
    rtb_TmpSignalConversionAtLookup[0] = 0.0;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S313>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S313>/Constant'
     *  Constant: '<S313>/Constant1'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = Boost_Trigger_Low_Speed;
    rtb_TmpSignalConversionAtLoo_mu[1] = Boost_Trigger_High_Speed;

    /* S-Function (sfix_look1_dyn): '<S313>/Lookup Table Dynamic' incorporates:
     *  Inport: '<Root>/Xbox_Driver_Trigger_Right'
     */
    /* Dynamic Look-Up Table Block: '<S313>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_UnitDelay3), &rtb_TmpSignalConversionAtLoo_mu[0],
                         Robot_Control_U.Xbox_Driver_Trigger_Right,
                         &rtb_TmpSignalConversionAtLookup[0], 1U);

    /* Switch: '<S320>/Init' incorporates:
     *  UnitDelay: '<S320>/FixPt Unit Delay1'
     *  UnitDelay: '<S320>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Saturation_h = rtb_UnitDelay3;
    } else {
      rtb_Saturation_h = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S320>/Init' */

    /* Sum: '<S318>/Sum1' */
    rtb_Subtract_e = rtb_UnitDelay3 - rtb_Saturation_h;

    /* Switch: '<S319>/Switch2' incorporates:
     *  Constant: '<S317>/Constant1'
     *  Constant: '<S317>/Constant3'
     *  RelationalOperator: '<S319>/LowerRelop1'
     *  RelationalOperator: '<S319>/UpperRelop'
     *  Switch: '<S319>/Switch'
     */
    if (rtb_Subtract_e > Boost_Trigger_Increasing_Limit) {
      rtb_UnitDelay3 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Subtract_e < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S319>/Switch' incorporates:
       *  Constant: '<S317>/Constant1'
       */
      rtb_UnitDelay3 = Boost_Trigger_Decreasing_Limit;
    } else {
      rtb_UnitDelay3 = rtb_Subtract_e;
    }

    /* End of Switch: '<S319>/Switch2' */

    /* Sum: '<S318>/Sum' */
    rtb_Subtract_e = rtb_UnitDelay3 + rtb_Saturation_h;

    /* Lookup_n-D: '<S303>/Modulation_Drv' incorporates:
     *  Math: '<S303>/Magnitude'
     */
    rtb_Modulation_Drv = look1_binlcpw(rt_hypotd_snf
      (Robot_Control_B.Drive_Joystick_X, Robot_Control_B.Drive_Joystick_Y),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S314>/Compare' incorporates:
     *  Constant: '<S314>/Constant'
     */
    rtb_Compare_ph = (rtb_Modulation_Drv == 0.0);

    /* Logic: '<S300>/Logical Operator1' incorporates:
     *  Constant: '<S11>/Constant12'
     *  Logic: '<S300>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S303>/Dead Zone' incorporates:
     *  Constant: '<S11>/Constant'
     */
    if (Twist_Deadzone_pos < 0.0) {
      rtb_Switch1_c = 0.0 - Twist_Deadzone_pos;
    } else if (Twist_Deadzone_neg <= 0.0) {
      rtb_Switch1_c = 0.0;
    } else {
      rtb_Switch1_c = 0.0 - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S303>/Dead Zone' */

    /* Logic: '<S303>/Logical Operator' incorporates:
     *  Constant: '<S315>/Constant'
     *  RelationalOperator: '<S315>/Compare'
     */
    rtb_Is_Absolute_Steering = ((rtb_Switch1_c != 0.0) && rtb_Compare_ph);

    /* Switch: '<S300>/Switch2' incorporates:
     *  Constant: '<S300>/Constant2'
     *  Constant: '<S324>/Constant'
     *  Constant: '<S327>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S324>/Compare'
     *  RelationalOperator: '<S327>/Compare'
     *  Sum: '<S300>/Subtract'
     *  Switch: '<S300>/Switch'
     *  Switch: '<S300>/Switch1'
     *  Switch: '<S300>/Switch3'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S300>/Switch2' incorporates:
       *  Constant: '<S300>/Constant5'
       *  Sum: '<S300>/Subtract1'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Tag_Target_Y -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch;
      rtb_Saturation_h = Vision_Tag_Target_X -
        Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S300>/Switch2' incorporates:
       *  Constant: '<S300>/Constant4'
       *  Sum: '<S300>/Subtract2'
       *  Switch: '<S300>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = Vision_Object_Target_Y -
        Robot_Control_B.Vision_c1_Object_Corr_Y_inch;

      /* Switch: '<S300>/Switch1' incorporates:
       *  Constant: '<S300>/Constant1'
       *  Sum: '<S300>/Subtract3'
       */
      rtb_Saturation_h = Vision_Object_Target_X -
        Robot_Control_B.Vision_c1_Object_Corr_X_inch;
    } else {
      /* Switch: '<S300>/Switch2' incorporates:
       *  Constant: '<S300>/Constant3'
       *  Switch: '<S300>/Switch3'
       */
      Robot_Control_B.Relative_Error_Y = 0.0;

      /* Switch: '<S300>/Switch1' incorporates:
       *  Constant: '<S300>/Constant'
       */
      rtb_Saturation_h = 0.0;
    }

    /* End of Switch: '<S300>/Switch2' */

    /* UnaryMinus: '<S300>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Saturation_h;

    /* Switch: '<S303>/Switch8' incorporates:
     *  Logic: '<S303>/Logical Operator1'
     *  Switch: '<S303>/Switch2'
     */
    if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S303>/Switch' incorporates:
       *  Gain: '<S303>/Gain'
       *  Merge: '<S7>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain * rtb_Switch1_c;
    } else if (rtb_Compare_ph) {
      /* Merge: '<S7>/Merge4' incorporates:
       *  Constant: '<S11>/Constant7'
       *  Constant: '<S11>/Constant8'
       *  Constant: '<S303>/Constant5'
       *  Gain: '<S303>/Gain2'
       *  Math: '<S303>/Magnitude1'
       *  MinMax: '<S303>/Min'
       *  Switch: '<S303>/Switch2'
       */
      Robot_Control_B.Translation_Speed = fmin(Field_Translation_Speed_Max,
        Field_Translation_Control_Gain * 0.0);
    } else {
      /* Product: '<S313>/Product' incorporates:
       *  Switch: '<S303>/Switch2'
       */
      rtb_Add_f1 = rtb_Modulation_Drv * rtb_Subtract_e;

      /* Saturate: '<S313>/Saturation' incorporates:
       *  Switch: '<S303>/Switch2'
       */
      if (rtb_Add_f1 > Boost_Trigger_High_Speed) {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (rtb_Add_f1 < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S7>/Merge4' */
        Robot_Control_B.Translation_Speed = rtb_Add_f1;
      }

      /* End of Saturate: '<S313>/Saturation' */
    }

    /* End of Switch: '<S303>/Switch8' */

    /* Switch: '<S316>/Switch1' incorporates:
     *  Constant: '<S321>/Constant'
     *  Constant: '<S322>/Constant'
     *  Logic: '<S316>/AND'
     *  RelationalOperator: '<S321>/Compare'
     *  RelationalOperator: '<S322>/Compare'
     *  Switch: '<S316>/Switch2'
     *  UnitDelay: '<S316>/Unit Delay'
     *  UnitDelay: '<S316>/Unit Delay1'
     */
    if ((Robot_Control_B.Drive_Joystick_X == 0.0) &&
        (Robot_Control_B.Drive_Joystick_Y == 0.0)) {
      rtb_Modulation_Drv = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2 = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Modulation_Drv = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch2 = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S316>/Switch1' */

    /* Switch: '<S303>/Switch1' incorporates:
     *  Logic: '<S303>/Logical Operator1'
     *  Switch: '<S303>/Switch4'
     *  Switch: '<S303>/Switch9'
     */
    if (rtb_Is_Absolute_Steering) {
      /* Signum: '<S303>/Sign' */
      if (rtIsNaN(rtb_Switch1_c)) {
        rtb_Add_f1 = (rtNaN);
      } else if (rtb_Switch1_c < 0.0) {
        rtb_Add_f1 = -1.0;
      } else {
        rtb_Add_f1 = (rtb_Switch1_c > 0.0);
      }

      /* Merge: '<S7>/Merge3' incorporates:
       *  Gain: '<S303>/Gain3'
       *  Signum: '<S303>/Sign'
       */
      Robot_Control_B.Translation_Angle = 3.141592653589793 * rtb_Add_f1;
    } else if (rtb_Compare_ph) {
      /* Switch: '<S303>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S303>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S7>/Merge3' incorporates:
         *  Constant: '<S303>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S7>/Merge3' incorporates:
         *  Constant: '<S303>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.141592653589793;
      }

      /* End of Switch: '<S303>/Switch6' */
    } else {
      /* Merge: '<S7>/Merge3' incorporates:
       *  Switch: '<S303>/Switch4'
       *  Trigonometry: '<S303>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Modulation_Drv,
        rtb_Switch2);
    }

    /* End of Switch: '<S303>/Switch1' */

    /* Switch: '<S301>/Switch' incorporates:
     *  Constant: '<S301>/Constant5'
     *  Constant: '<S301>/Constant7'
     *  DataTypeConversion: '<S301>/Data Type Conversion'
     *  Logic: '<S303>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_ph = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Compare_ph = !rtb_Is_Absolute_Steering;
    }

    /* End of Switch: '<S301>/Switch' */

    /* Switch: '<S300>/Switch4' incorporates:
     *  Constant: '<S325>/Constant'
     *  Constant: '<S328>/Constant'
     *  Inport: '<Root>/Vision_Current_Pipeline'
     *  RelationalOperator: '<S325>/Compare'
     *  RelationalOperator: '<S328>/Compare'
     *  Switch: '<S300>/Switch5'
     */
    if (Robot_Control_U.Vision_Current_Pipeline == 0.0) {
      /* Switch: '<S300>/Switch4' incorporates:
       *  Constant: '<S300>/Constant8'
       *  Sum: '<S300>/Subtract4'
       */
      Robot_Control_B.Relative_Error_Angle = Vision_Tag_Target_Angle -
        Robot_Control_B.Vision_c1_AprilTag_Corr_Yaw_deg;
    } else if (Robot_Control_U.Vision_Current_Pipeline == 1.0) {
      /* Switch: '<S300>/Switch5' incorporates:
       *  Constant: '<S300>/Constant7'
       *  Gain: '<S300>/Gain'
       *  Sum: '<S300>/Subtract5'
       *  Switch: '<S300>/Switch4'
       */
      Robot_Control_B.Relative_Error_Angle = (Vision_Object_Target_Angle -
        Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg) *
        Relative_Steering_Error_Angle_Gain_Object_Factor;
    } else {
      /* Switch: '<S300>/Switch4' incorporates:
       *  Constant: '<S300>/Constant6'
       *  Switch: '<S300>/Switch5'
       */
      Robot_Control_B.Relative_Error_Angle = 0.0;
    }

    /* End of Switch: '<S300>/Switch4' */

    /* DeadZone: '<S302>/Dead Zone' incorporates:
     *  Constant: '<S11>/Constant15'
     */
    if (Twist_Deadzone_pos < 0.0) {
      rtb_Add_f1 = 0.0 - Twist_Deadzone_pos;
    } else if (Twist_Deadzone_neg <= 0.0) {
      rtb_Add_f1 = 0.0;
    } else {
      rtb_Add_f1 = 0.0 - Twist_Deadzone_neg;
    }

    /* Sum: '<S302>/Add' incorporates:
     *  Constant: '<S302>/Constant'
     *  Constant: '<S302>/Constant1'
     *  DeadZone: '<S302>/Dead Zone'
     *  Lookup_n-D: '<S302>/Modulation_Str_Y_Rel'
     *  Product: '<S302>/Product'
     *  Product: '<S302>/Product1'
     *  SignalConversion: '<S4>/Signal Copy5'
     */
    rtb_Saturation_h = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                        Steering_Relative_Gain) + (rtb_Add_f1 *
      Steering_Twist_Gain);

    /* RelationalOperator: '<S304>/Compare' incorporates:
     *  Constant: '<S304>/Constant'
     */
    rtb_LogicalOperator1_h = (rtb_Saturation_h == 0.0);

    /* Switch: '<S301>/Switch1' incorporates:
     *  Constant: '<S301>/Constant5'
     *  Constant: '<S301>/Constant8'
     *  DataTypeConversion: '<S301>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_LogicalOperator1_h;
    }

    /* End of Switch: '<S301>/Switch1' */

    /* Logic: '<S302>/AND2' incorporates:
     *  RelationalOperator: '<S305>/FixPt Relational Operator'
     *  RelationalOperator: '<S306>/FixPt Relational Operator'
     *  RelationalOperator: '<S307>/FixPt Relational Operator'
     *  RelationalOperator: '<S308>/FixPt Relational Operator'
     *  UnitDelay: '<S305>/Delay Input1'
     *  UnitDelay: '<S306>/Delay Input1'
     *  UnitDelay: '<S307>/Delay Input1'
     *  UnitDelay: '<S308>/Delay Input1'
     *
     * Block description for '<S305>/Delay Input1':
     *
     *  Store in Global RAM
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
     */
    rtb_Compare_ky = ((((((int32_T)rtb_Compare_bd) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_Compare_mq) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
                      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S302>/AND1' incorporates:
     *  Logic: '<S302>/AND3'
     *  UnitDelay: '<S302>/Unit Delay2'
     */
    rtb_AND1 = (rtb_LogicalOperator1_h && (rtb_Compare_ky ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S302>/AND4' incorporates:
     *  Logic: '<S302>/AND8'
     *  UnitDelay: '<S302>/Unit Delay4'
     */
    rtb_Compare_ky = ((rtb_LogicalOperator1_h && (!rtb_Compare_ky)) &&
                      (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S302>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1 || rtb_Compare_ky);

    /* UnitDelay: '<S302>/Unit Delay3' */
    rtb_UnitDelay3 = Robot_Control_DW.UnitDelay3_DSTATE;

    /* Switch: '<S302>/Switch8' incorporates:
     *  Constant: '<S311>/Constant'
     *  Logic: '<S302>/AND9'
     *  RelationalOperator: '<S310>/FixPt Relational Operator'
     *  RelationalOperator: '<S311>/Compare'
     *  UnitDelay: '<S310>/Delay Input1'
     *  UnitDelay: '<S5>/Unit Delay1'
     *  UnitDelay: '<S8>/Unit Delay'
     *
     * Block description for '<S310>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_LogicalOperator1_h) > ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_j))) ||
         (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_DW.UnitDelay1_DSTATE_nl)) {
      /* Switch: '<S302>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S302>/Switch8' */
      Robot_Control_B.Steering_Abs_Gyro_Latch = rtb_UnitDelay3;
    }

    /* End of Switch: '<S302>/Switch8' */

    /* Switch: '<S302>/Switch4' incorporates:
     *  Constant: '<S302>/Constant5'
     *  Switch: '<S302>/Switch1'
     *  Switch: '<S302>/Switch5'
     *  Switch: '<S302>/Switch6'
     *  Switch: '<S302>/Switch7'
     */
    if (rtb_Compare_bd) {
      rtb_Switch1_c = 0.0;
    } else if (rtb_Compare_mq) {
      /* Switch: '<S302>/Switch5' incorporates:
       *  Constant: '<S302>/Constant6'
       */
      rtb_Switch1_c = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S302>/Switch6' incorporates:
       *  Constant: '<S302>/Constant7'
       *  Switch: '<S302>/Switch5'
       */
      rtb_Switch1_c = 3.141592653589793;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S302>/Switch7' incorporates:
       *  Constant: '<S302>/Constant8'
       *  Switch: '<S302>/Switch5'
       *  Switch: '<S302>/Switch6'
       */
      rtb_Switch1_c = 4.71238898038469;
    } else if (rtb_Compare_ky) {
      /* Switch: '<S302>/Switch1' incorporates:
       *  Constant: '<S11>/Constant10'
       *  Switch: '<S302>/Switch5'
       *  Switch: '<S302>/Switch6'
       *  Switch: '<S302>/Switch7'
       */
      rtb_Switch1_c = 0.0;
    } else {
      /* Switch: '<S302>/Switch6' incorporates:
       *  Switch: '<S302>/Switch5'
       *  Switch: '<S302>/Switch7'
       *  UnitDelay: '<S302>/Unit Delay1'
       */
      rtb_Switch1_c = Robot_Control_DW.UnitDelay1_DSTATE_j2;
    }

    /* End of Switch: '<S302>/Switch4' */

    /* Switch: '<S302>/Switch2' incorporates:
     *  Switch: '<S302>/Switch3'
     */
    if (Robot_Control_B.Steering_Abs_Angle_Active) {
      /* Switch: '<S302>/Switch2' incorporates:
       *  Constant: '<S302>/Constant2'
       */
      Robot_Control_B.Steering_Abs_Gyro = 0.0;

      /* Switch: '<S302>/Switch3' */
      Robot_Control_B.Steering_Abs_Angle = rtb_Switch1_c;
    } else {
      /* Switch: '<S302>/Switch2' */
      Robot_Control_B.Steering_Abs_Gyro =
        Robot_Control_B.Steering_Abs_Gyro_Latch;

      /* Switch: '<S302>/Switch3' incorporates:
       *  Constant: '<S302>/Constant3'
       */
      Robot_Control_B.Steering_Abs_Angle = 0.0;
    }

    /* End of Switch: '<S302>/Switch2' */

    /* Merge: '<S7>/Merge1' incorporates:
     *  Sum: '<S302>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Merge: '<S7>/Merge2' incorporates:
     *  SignalConversion: '<S302>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Saturation_h;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S300>/Constant11'
     *  Switch: '<S300>/Switch6'
     *  Switch: '<S300>/Switch7'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = TEST_Pipeline;

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

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  Constant: '<S11>/Constant6'
     *  SignalConversion generated from: '<S11>/Enable_Wheels'
     */
    Robot_Control_Y.Enable_Wheels = false;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S11>/Constant13'
     *  SignalConversion generated from: '<S11>/Reset_Wheel_Offsets'
     */
    Robot_Control_Y.Reset_Wheel_Offsets = false;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  Constant: '<S11>/Constant14'
     *  SignalConversion generated from: '<S11>/Disable_Wheels'
     */
    Robot_Control_Y.Disable_Wheels = false;

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S11>/Constant2'
     *  SignalConversion generated from: '<S11>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = false;

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S11>/Constant21'
     *  SignalConversion generated from: '<S11>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Update for UnitDelay: '<S320>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S320>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S320>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Subtract_e;

    /* Update for UnitDelay: '<S316>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Modulation_Drv;

    /* Update for UnitDelay: '<S316>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch2;

    /* Update for UnitDelay: '<S310>/Delay Input1'
     *
     * Block description for '<S310>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_LogicalOperator1_h;

    /* Update for UnitDelay: '<S309>/Delay Input1' incorporates:
     *  Constant: '<S11>/Constant5'
     *
     * Block description for '<S309>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_f = false;

    /* Update for UnitDelay: '<S305>/Delay Input1'
     *
     * Block description for '<S305>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_Compare_bd;

    /* Update for UnitDelay: '<S306>/Delay Input1'
     *
     * Block description for '<S306>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_Compare_mq;

    /* Update for UnitDelay: '<S307>/Delay Input1'
     *
     * Block description for '<S307>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S308>/Delay Input1'
     *
     * Block description for '<S308>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S302>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1;

    /* Update for UnitDelay: '<S302>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_Compare_ky;

    /* Update for UnitDelay: '<S302>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S302>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_Switch1_c;

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
    /* SignalConversion generated from: '<S12>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S7>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

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
    rtb_Compare_ph = false;

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
      rtb_LogicalOperator1 = true;
    } else {
      rtb_LogicalOperator1 = ((!Robot_Control_B.Button_Enable_Wheels) &&
        (Robot_Control_DW.UnitDelay_DSTATE_ir));
    }

    /* End of Switch: '<S12>/Switch' */

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  SignalConversion generated from: '<S12>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = rtb_LogicalOperator1;

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S12>/Constant10'
     *  SignalConversion generated from: '<S12>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S12>/Constant22'
     *  SignalConversion generated from: '<S12>/Desired_Pipeline'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = TEST_Pipeline;

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  SignalConversion: '<S12>/Signal Copy'
     */
    Robot_Control_Y.Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  SignalConversion: '<S12>/Signal Copy2'
     */
    Robot_Control_Y.Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  SignalConversion: '<S12>/Signal Copy1'
     */
    Robot_Control_Y.Reset_Wheel_Offsets =
      Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S12>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_LogicalOperator1;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Reshape: '<S25>/Reshape3' incorporates:
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_X'
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_Y'
   *  S-Function (sfix_udelay): '<S6>/Tapped Delay'
   *  S-Function (sfix_udelay): '<S6>/Tapped Delay1'
   *  Sum: '<S6>/Add'
   *  Sum: '<S6>/Add1'
   */
  rtb_TmpSignalConversionAtLookup[0] =
    (Robot_Control_U.Vision_RobotPoseFieldSpace_X +
     Robot_Control_DW.TappedDelay_X[0]) + Robot_Control_DW.TappedDelay_X[1];
  rtb_TmpSignalConversionAtLookup[1] =
    (Robot_Control_U.Vision_RobotPoseFieldSpace_Y +
     Robot_Control_DW.TappedDelay1_X[0]) + Robot_Control_DW.TappedDelay1_X[1];

  /* Delay: '<S78>/Delay' incorporates:
   *  Constant: '<S25>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.Delay_DSTATE[0] = 0.0;
    Robot_Control_DW.Delay_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S60>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S77>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S79>/Enable'
   */
  /* Logic: '<S6>/AND' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S79>/Sum' incorporates:
     *  Constant: '<S25>/C'
     *  Delay: '<S78>/Delay'
     *  Product: '<S79>/C[k]*xhat[k|k-1]'
     *  Reshape: '<S25>/Reshape3'
     *  Sum: '<S79>/Add1'
     */
    rtb_Saturation_h = rtb_TmpSignalConversionAtLookup[0] - ((0.0 *
      Robot_Control_DW.Delay_DSTATE[1]) + Robot_Control_DW.Delay_DSTATE[0]);
    rtb_Subtract_e = rtb_TmpSignalConversionAtLookup[1] - ((0.0 *
      Robot_Control_DW.Delay_DSTATE[0]) + Robot_Control_DW.Delay_DSTATE[1]);

    /* Product: '<S79>/Product3' incorporates:
     *  Constant: '<S73>/Constant'
     *  Product: '<S61>/Product2'
     */
    rtb_Modulation_Drv = 0.09512492197250398 * rtb_Saturation_h;
    Robot_Control_B.Product3[0] = rtb_Modulation_Drv;
    Robot_Control_B.Product3[1] = 6.209845451961181E-17 * rtb_Saturation_h;
    Robot_Control_B.Product3[0] += -2.0399807945617856E-17 * rtb_Subtract_e;
    Robot_Control_B.Product3[1] += 0.09512492197250422 * rtb_Subtract_e;

    /* Product: '<S61>/Product2' incorporates:
     *  Constant: '<S73>/Constant1'
     *  Sum: '<S61>/Add1'
     */
    Robot_Control_B.Product2[0] = rtb_Modulation_Drv;
    Robot_Control_B.Product2[1] = 2.580507006221294E-17 * rtb_Saturation_h;
    Robot_Control_B.Product2[0] += 2.5805070062212937E-17 * rtb_Subtract_e;
    Robot_Control_B.Product2[1] += 0.09512492197250424 * rtb_Subtract_e;
  } else if (Robot_Control_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S79>/Product3' incorporates:
     *  Outport: '<S79>/L*(y[k]-yhat[k|k-1])'
     */
    Robot_Control_B.Product3[0] = 0.0;
    Robot_Control_B.Product3[1] = 0.0;
    Robot_Control_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Logic: '<S6>/AND' */
  /* End of Outputs for SubSystem: '<S77>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S60>/Enabled Subsystem' */

  /* Sum: '<S60>/Add' incorporates:
   *  Delay: '<S78>/Delay'
   *  Product: '<S61>/Product2'
   */
  rtb_TmpSignalConversionAtLookup[0] = Robot_Control_B.Product2[0] +
    Robot_Control_DW.Delay_DSTATE[0];
  rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.Product2[1] +
    Robot_Control_DW.Delay_DSTATE[1];

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Switch: '<S6>/Switch1'
   */
  if (KF_Enable != 0.0) {
    /* Switch: '<S6>/Switch' */
    Robot_Control_B.KF_Position_X = rtb_TmpSignalConversionAtLookup[0];

    /* Switch: '<S6>/Switch1' */
    Robot_Control_B.KF_Position_Y = rtb_TmpSignalConversionAtLookup[1];
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
   *  Constant: '<S139>/Constant'
   *  Logic: '<S139>/AND'
   *  MATLAB Function: '<S89>/Find closest index to curve'
   *  Product: '<S139>/Product'
   *  RelationalOperator: '<S139>/Relational Operator'
   *  RelationalOperator: '<S139>/Relational Operator1'
   *  Selector: '<S139>/Selector'
   *  Selector: '<S139>/Selector1'
   *  Selector: '<S140>/Selector'
   *  Sum: '<S139>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S92>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S95>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S97>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S92>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S9>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S87>/Action Port'
       */
      /* InitializeConditions for If: '<S9>/If' incorporates:
       *  UnitDelay: '<S140>/Unit Delay'
       *  UnitDelay: '<S140>/Unit Delay1'
       *  UnitDelay: '<S87>/Unit Delay'
       *  UnitDelay: '<S88>/Unit Delay'
       *  UnitDelay: '<S90>/Unit Delay'
       *  UnitDelay: '<S90>/Unit Delay1'
       */
      Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;
      Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_f4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_g4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_le = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_k = 0.0;

      /* End of InitializeConditions for SubSystem: '<S9>/Spline Path Following Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S9>/Spline Path Following Enabled' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    /* Selector: '<S88>/Selector1' incorporates:
     *  Merge: '<S7>/Merge8'
     */
    memcpy(&rtb_Ref_Poses[0], &rtb_Spline_Ref_Poses_h[0], 10U * (sizeof(real_T)));
    memcpy(&rtb_Ref_Poses[10], &rtb_Spline_Ref_Poses_h[10], 10U * (sizeof(real_T)));

    /* Lookup_n-D: '<S87>/Capture Radius' incorporates:
     *  UnitDelay: '<S87>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_h,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S88>/Matrix Concatenate2' */
    rtb_TmpSignalConversionAtLookup[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S88>/Matrix Concatenate2' */
    rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S92>/If' incorporates:
     *  RelationalOperator: '<S92>/ '
     *  UnitDelay: '<S88>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S95>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S97>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S92>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S95>/Action Port'
       */
      /* InitializeConditions for If: '<S92>/If' incorporates:
       *  UnitDelay: '<S95>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S92>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S92>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S95>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S95>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S98>/Action Port'
       */
      /* If: '<S95>/If' incorporates:
       *  Selector: '<S88>/Selector1'
       *  Selector: '<S95>/Selector'
       *  Selector: '<S98>/Selector'
       */
      rtb_UnitDelay3 = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S95>/Increment_If_Rectangle_Check' */

      /* Sum: '<S95>/Minus' incorporates:
       *  Concatenate: '<S88>/Matrix Concatenate2'
       *  Selector: '<S95>/Selector'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = rtb_TmpSignalConversionAtLookup[0] -
        rtb_UnitDelay3;

      /* Outputs for IfAction SubSystem: '<S95>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S98>/Action Port'
       */
      /* If: '<S95>/If' incorporates:
       *  Selector: '<S88>/Selector1'
       *  Selector: '<S95>/Selector'
       *  Selector: '<S98>/Selector'
       *  Sum: '<S95>/Minus'
       */
      rtb_Switch1_c = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S95>/Increment_If_Rectangle_Check' */

      /* Sum: '<S95>/Minus' incorporates:
       *  Concatenate: '<S88>/Matrix Concatenate2'
       *  Selector: '<S95>/Selector'
       */
      rtb_TmpSignalConversionAtLoo_mu[1] = rtb_TmpSignalConversionAtLookup[1] -
        rtb_Switch1_c;

      /* Math: '<S95>/Hypot' */
      rtb_Subtract_e = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu[0],
        rtb_TmpSignalConversionAtLoo_mu[1]);

      /* RelationalOperator: '<S95>/Equal' */
      rtb_LogicalOperator1 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S95>/Switch' incorporates:
       *  Logic: '<S95>/AND'
       *  Logic: '<S95>/OR'
       *  RelationalOperator: '<S95>/Relational Operator'
       *  UnitDelay: '<S95>/Unit Delay'
       */
      rtb_LogicalOperator5 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Subtract_e <= rtb_Saturation_h) && rtb_LogicalOperator1));

      /* If: '<S95>/If' */
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
        /* Disable for If: '<S97>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S95>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S97>/Action Port'
         */
        /* If: '<S97>/If' incorporates:
         *  RelationalOperator: '<S97>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S97>/Is_Last_Point' incorporates:
           *  ActionPort: '<S100>/Action Port'
           */
          /* InitializeConditions for If: '<S97>/If' incorporates:
           *  UnitDelay: '<S100>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_n = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_n));

          /* End of InitializeConditions for SubSystem: '<S97>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S97>/Is_Last_Point' incorporates:
           *  ActionPort: '<S100>/Action Port'
           */
          /* Switch: '<S100>/Switch' incorporates:
           *  Constant: '<S102>/Constant'
           *  Logic: '<S100>/OR'
           *  RelationalOperator: '<S102>/Compare'
           *  UnitDelay: '<S100>/Unit Delay'
           */
          rtb_Compare_bd = ((Robot_Control_DW.UnitDelay_DSTATE_n) ||
                            (rtb_Subtract_e <= Spline_Stop_Radius));

          /* If: '<S100>/If' */
          if (rtb_Compare_bd) {
            /* Outputs for IfAction SubSystem: '<S100>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S103>/Action Port'
             */
            /* Merge: '<S92>/Merge2' incorporates:
             *  Constant: '<S103>/Constant'
             *  SignalConversion generated from: '<S103>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator1 = true;

            /* SignalConversion generated from: '<S103>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S103>/Constant1'
             */
            rtb_Compare_mq = false;

            /* End of Outputs for SubSystem: '<S100>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S100>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S104>/Action Port'
             */
            /* Merge: '<S92>/Merge2' incorporates:
             *  Constant: '<S104>/Constant'
             *  SignalConversion generated from: '<S104>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator1 = false;

            /* SignalConversion generated from: '<S104>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S104>/Constant1'
             */
            rtb_Compare_mq = true;

            /* End of Outputs for SubSystem: '<S100>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S100>/If' */

          /* Merge: '<S92>/Merge4' incorporates:
           *  SignalConversion: '<S100>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S100>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Compare_bd;

          /* End of Outputs for SubSystem: '<S97>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S97>/Increment_Search' incorporates:
           *  ActionPort: '<S99>/Action Port'
           */
          /* Merge: '<S92>/Merge2' incorporates:
           *  Constant: '<S99>/Constant'
           *  SignalConversion generated from: '<S99>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator1 = false;

          /* SignalConversion generated from: '<S99>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S99>/Constant1'
           */
          rtb_Compare_mq = false;

          /* Merge: '<S92>/Merge4' incorporates:
           *  Constant: '<S101>/FixPt Constant'
           *  SignalConversion: '<S99>/Signal Copy'
           *  Sum: '<S101>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S97>/Increment_Search' */
        }

        /* End of If: '<S97>/If' */
        /* End of Outputs for SubSystem: '<S95>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S95>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S98>/Action Port'
         */
        /* Sum: '<S105>/FixPt Sum1' incorporates:
         *  Constant: '<S105>/FixPt Constant'
         */
        rtb_Modulation_Drv = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S98>/Selector1' incorporates:
         *  Selector: '<S88>/Selector1'
         */
        rtb_Subtract = rtb_Ref_Poses[((int32_T)rtb_Modulation_Drv) - 1];

        /* Sum: '<S106>/Subtract' incorporates:
         *  Selector: '<S98>/Selector1'
         *  Sum: '<S106>/Minus1'
         */
        rtb_TmpSignalConversionAtLoo_mu[0] = rtb_Subtract - rtb_UnitDelay3;

        /* Selector: '<S98>/Selector1' incorporates:
         *  Selector: '<S88>/Selector1'
         */
        rtb_Optimized_Module_Angle = rtb_Ref_Poses[((int32_T)rtb_Modulation_Drv)
          + 9];

        /* Sum: '<S106>/Subtract' incorporates:
         *  Selector: '<S98>/Selector1'
         *  Sum: '<S106>/Minus1'
         */
        rtb_TmpSignalConversionAtLoo_mu[1] = rtb_Optimized_Module_Angle -
          rtb_Switch1_c;

        /* Math: '<S106>/Hypot' */
        rtb_Subtract_e = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu[0],
          rtb_TmpSignalConversionAtLoo_mu[1]);

        /* Product: '<S106>/Divide' */
        rtb_Modulation_Drv = rtb_TmpSignalConversionAtLoo_mu[1];

        /* UnaryMinus: '<S106>/Unary Minus' */
        rtb_Switch2 = rtb_TmpSignalConversionAtLoo_mu[0];

        /* Product: '<S106>/Product' incorporates:
         *  Product: '<S106>/Divide'
         *  UnaryMinus: '<S106>/Unary Minus'
         */
        rtb_TmpSignalConversionAtLoo_mu[0] = (rtb_Modulation_Drv /
          rtb_Subtract_e) * rtb_Saturation_h;
        rtb_TmpSignalConversionAtLoo_mu[1] = ((-rtb_Switch2) / rtb_Subtract_e) *
          rtb_Saturation_h;

        /* Sum: '<S106>/Add1' incorporates:
         *  Sum: '<S106>/Add2'
         *  Sum: '<S106>/Minus'
         */
        rtb_Switch2 = rtb_Subtract - rtb_TmpSignalConversionAtLoo_mu[0];

        /* Sum: '<S106>/Minus4' incorporates:
         *  Sum: '<S106>/Add2'
         *  Sum: '<S106>/Minus'
         */
        rtb_Subtract = (rtb_Subtract + rtb_TmpSignalConversionAtLoo_mu[0]) -
          rtb_Switch2;

        /* Sum: '<S106>/Minus5' incorporates:
         *  Concatenate: '<S88>/Matrix Concatenate2'
         *  Sum: '<S106>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_TmpSignalConversionAtLookup[0] -
          rtb_Switch2;

        /* Sum: '<S106>/Add' incorporates:
         *  Sum: '<S106>/Add2'
         *  Sum: '<S106>/Minus1'
         */
        rtb_Modulation_Drv = rtb_UnitDelay3 - rtb_TmpSignalConversionAtLoo_mu[0];

        /* Sum: '<S106>/Minus' incorporates:
         *  Sum: '<S106>/Minus1'
         */
        rtb_Switch2 -= rtb_Modulation_Drv;

        /* DotProduct: '<S106>/Dot Product' incorporates:
         *  Concatenate: '<S88>/Matrix Concatenate2'
         *  Sum: '<S106>/Minus'
         *  Sum: '<S106>/Minus1'
         *  Sum: '<S106>/Minus5'
         */
        rtb_Subtract_e = (rtb_TmpSignalConversionAtLookup[0] -
                          rtb_Modulation_Drv) * rtb_Switch2;

        /* Sum: '<S106>/Add1' incorporates:
         *  Sum: '<S106>/Add2'
         *  Sum: '<S106>/Minus'
         */
        rtb_UnitDelay3 = rtb_Optimized_Module_Angle -
          rtb_TmpSignalConversionAtLoo_mu[1];

        /* Sum: '<S106>/Minus4' incorporates:
         *  Sum: '<S106>/Add2'
         *  Sum: '<S106>/Minus'
         */
        rtb_Optimized_Module_Angle = (rtb_Optimized_Module_Angle +
          rtb_TmpSignalConversionAtLoo_mu[1]) - rtb_UnitDelay3;

        /* Sum: '<S106>/Add' incorporates:
         *  Sum: '<S106>/Add2'
         *  Sum: '<S106>/Minus1'
         */
        rtb_Modulation_Drv = rtb_Switch1_c - rtb_TmpSignalConversionAtLoo_mu[1];

        /* Sum: '<S106>/Minus' incorporates:
         *  Sum: '<S106>/Minus1'
         */
        rtb_Switch1_c = rtb_UnitDelay3 - rtb_Modulation_Drv;

        /* DotProduct: '<S106>/Dot Product' incorporates:
         *  Concatenate: '<S88>/Matrix Concatenate2'
         *  Sum: '<S106>/Minus'
         *  Sum: '<S106>/Minus1'
         *  Sum: '<S106>/Minus5'
         */
        rtb_Subtract_e += (rtb_TmpSignalConversionAtLookup[1] -
                           rtb_Modulation_Drv) * rtb_Switch1_c;

        /* DotProduct: '<S106>/Dot Product2' incorporates:
         *  Concatenate: '<S88>/Matrix Concatenate2'
         *  Sum: '<S106>/Minus'
         *  Sum: '<S106>/Minus4'
         *  Sum: '<S106>/Minus5'
         */
        rtb_Modulation_Drv = ((rtb_TmpSignalConversionAtLookup[1] -
          rtb_UnitDelay3) * rtb_Optimized_Module_Angle) + (rtb_Subtract *
          rtb_MatrixConcatenate_b_idx_0);

        /* Merge: '<S92>/Merge4' incorporates:
         *  Constant: '<S107>/Constant'
         *  Constant: '<S108>/Constant'
         *  DataTypeConversion: '<S98>/Data Type Conversion'
         *  DotProduct: '<S106>/Dot Product1'
         *  DotProduct: '<S106>/Dot Product3'
         *  Logic: '<S106>/AND'
         *  RelationalOperator: '<S106>/LessThanOrEqual'
         *  RelationalOperator: '<S106>/LessThanOrEqual1'
         *  RelationalOperator: '<S107>/Compare'
         *  RelationalOperator: '<S108>/Compare'
         *  Sum: '<S106>/Minus'
         *  Sum: '<S106>/Minus4'
         *  Sum: '<S98>/Add'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)((((rtb_Subtract_e >= 0.0)
          && (rtb_Subtract_e <= ((rtb_Switch1_c * rtb_Switch1_c) + (rtb_Switch2 *
          rtb_Switch2)))) && (rtb_Modulation_Drv >= 0.0)) && (rtb_Modulation_Drv
          <= ((rtb_Subtract * rtb_Subtract) + (rtb_Optimized_Module_Angle *
          rtb_Optimized_Module_Angle))))) + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S92>/Merge2' incorporates:
         *  Constant: '<S98>/Constant2'
         *  SignalConversion generated from: '<S98>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator1 = false;

        /* SignalConversion generated from: '<S98>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S98>/Constant1'
         */
        rtb_Compare_mq = false;

        /* End of Outputs for SubSystem: '<S95>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S95>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S96>/Action Port'
         */
        /* Merge: '<S92>/Merge2' incorporates:
         *  Constant: '<S96>/Constant2'
         *  SignalConversion generated from: '<S96>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator1 = false;

        /* SignalConversion generated from: '<S96>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S96>/Constant1'
         */
        rtb_Compare_mq = false;

        /* Merge: '<S92>/Merge4' incorporates:
         *  SignalConversion generated from: '<S96>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S95>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S92>/Merge1' incorporates:
       *  Constant: '<S95>/Constant'
       *  SignalConversion generated from: '<S95>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S95>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator5;

      /* End of Outputs for SubSystem: '<S92>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S92>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S94>/Action Port'
       */
      /* Merge: '<S92>/Merge1' incorporates:
       *  Constant: '<S94>/Constant'
       *  SignalConversion generated from: '<S94>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S92>/Merge2' incorporates:
       *  Constant: '<S94>/Constant1'
       *  SignalConversion generated from: '<S94>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator1 = false;

      /* SignalConversion generated from: '<S94>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S94>/Constant2'
       */
      rtb_Compare_mq = false;

      /* Merge: '<S92>/Merge4' incorporates:
       *  SignalConversion generated from: '<S94>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S92>/Escape_Auto_Driving' */
    }

    /* End of If: '<S92>/If' */

    /* If: '<S88>/If1' */
    if (!rtb_Compare_mq) {
      /* Outputs for IfAction SubSystem: '<S88>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S93>/Action Port'
       */
      /* Bias: '<S109>/Add Constant' incorporates:
       *  Bias: '<S109>/Bias'
       *  Sum: '<S109>/Subtract'
       */
      rtb_Subtract_e = ((Robot_Control_B.Spline_Num_Poses -
                         Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S109>/Selector4' incorporates:
       *  Bias: '<S109>/Bias1'
       *  Constant: '<S111>/FixPt Constant'
       *  Sum: '<S111>/FixPt Sum1'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = Robot_Control_B.Spline_Follow_Index -
        1.0;
      rtb_TmpSignalConversionAtLoo_mu[1] = Robot_Control_B.Spline_Num_Poses +
        2.0;

      /* SignalConversion generated from: '<S109>/Selector5' */
      rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S109>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)
        rtb_TmpSignalConversionAtLookup[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s114_iter = ((int32_T)rtb_TmpSignalConversionAtLookup[1]) - 1;

      /* Concatenate: '<S109>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S109>/Selector5' incorporates:
       *  Concatenate: '<S109>/Matrix Concatenate'
       *  Gain: '<S113>/Gain'
       *  Selector: '<S109>/Selector2'
       *  Selector: '<S109>/Selector3'
       *  Selector: '<S88>/Selector1'
       *  Sum: '<S113>/Subtract'
       */
      rtb_Bias1_p = 0;
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s114_iter;
             rtb_Num_Segments++) {
          rtb_Selector5[rtb_Num_Segments + (Robot_Control_DW.Selector5_DIMS1[0] *
            i)] = rtb_Ref_Poses[rtb_Num_Segments + rtb_Bias1_p];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i]
          = (rtb_Ref_Poses[rtb_Bias1_p] * 2.0) - rtb_Ref_Poses[rtb_Bias1_p + 1];
        rtb_Bias1_p += 10;
      }

      /* Concatenate: '<S109>/Matrix Concatenate' incorporates:
       *  Bias: '<S109>/Add Constant1'
       *  Gain: '<S112>/Gain'
       *  Selector: '<S109>/Selector'
       *  Selector: '<S109>/Selector1'
       *  Selector: '<S109>/Selector5'
       *  Selector: '<S88>/Selector1'
       *  Sum: '<S112>/Subtract'
       */
      s114_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (rtb_Bias1_p = 0; rtb_Bias1_p < 2; rtb_Bias1_p++) {
        for (i = 0; i < s114_iter; i++) {
          rtb_MatrixConcatenate_p[(i +
            (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * rtb_Bias1_p)) + 1] =
            rtb_Selector5[(Robot_Control_DW.Selector5_DIMS1[0] * rtb_Bias1_p) +
            i];
        }
      }

      rtb_MatrixConcatenate_p[Robot_Control_DW.Selector5_DIMS1[0] + 1] =
        (rtb_Ref_Poses[((int32_T)rtb_TmpSignalConversionAtLookup[1]) - 1] * 2.0)
        - rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) - 1];
      rtb_MatrixConcatenate_p[(Robot_Control_DW.Selector5_DIMS1[0] +
        Robot_Control_DW.MatrixConcatenate_DIMS1[0]) + 1] = (rtb_Ref_Poses
        [((int32_T)Robot_Control_B.Spline_Num_Poses) + 9] * 2.0) -
        rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) + 9];

      /* Selector: '<S109>/Selector4' */
      s114_iter = ((int32_T)rtb_TmpSignalConversionAtLoo_mu[1]) - ((int32_T)
        rtb_TmpSignalConversionAtLoo_mu[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s114_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S109>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S109>/Selector4' */
      rtb_Num_Segments = (int32_T)rtb_TmpSignalConversionAtLoo_mu[0];

      /* Assignment: '<S109>/Assignment' incorporates:
       *  Concatenate: '<S109>/Matrix Concatenate'
       *  Selector: '<S109>/Selector4'
       */
      for (rtb_Bias1_p = 0; rtb_Bias1_p < 2; rtb_Bias1_p++) {
        for (i = 0; i <= s114_iter; i++) {
          rtb_Assignment[i + (12 * rtb_Bias1_p)] = rtb_MatrixConcatenate_p[((i +
            rtb_Num_Segments) + (Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
            rtb_Bias1_p)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S110>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S114>/While Iterator'
       */
      s114_iter = 1;
      do {
        rtb_UnitDelay3 = rtb_Assignment[s114_iter + 1];
        rtb_TmpSignalConversionAtLoo_mu[0] = rtb_UnitDelay3 -
          rtb_Assignment[s114_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s114_iter] - rtb_Assignment[s114_iter + 2];
        rtb_Minus_k_idx_0 = rtb_UnitDelay3 - rtb_Assignment[s114_iter];
        rtb_UnitDelay3 = rtb_Assignment[s114_iter + 13];
        rtb_TmpSignalConversionAtLoo_mu[1] = rtb_UnitDelay3 -
          rtb_Assignment[s114_iter + 11];
        rtb_Optimized_Module_Angle = rtb_Assignment[s114_iter + 12];
        rtb_Add2[1] = rtb_Optimized_Module_Angle - rtb_Assignment[s114_iter + 14];
        rtb_Minus_k_idx_1 = rtb_UnitDelay3 - rtb_Optimized_Module_Angle;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Modulation_Drv = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Switch2 = rt_powd_snf(rtb_Modulation_Drv, 2.0);
          rtb_Subtract = rt_powd_snf(rtb_Modulation_Drv, 3.0);
          rtb_Switch1_c = (rtb_Modulation_Drv - (2.0 * rtb_Switch2)) +
            rtb_Subtract;
          rtb_UnitDelay3 = rtb_Switch2 - rtb_Subtract;
          rtb_Hypot = 3.0 * rtb_Switch2;
          rtb_Subtract = rtb_Hypot - (2.0 * rtb_Subtract);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_TmpSignalConversionAtLoo_mu[0]
            * rtb_Switch1_c) + (rtb_Add2[0] * rtb_UnitDelay3)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_Subtract)) + rtb_Assignment[s114_iter];
          rtb_Subtract = ((((rtb_TmpSignalConversionAtLoo_mu[1] * rtb_Switch1_c)
                            + (rtb_Add2[1] * rtb_UnitDelay3)) * 0.5) +
                          (rtb_Minus_k_idx_1 * rtb_Subtract)) +
            rtb_Optimized_Module_Angle;
          rtb_Switch1_c = (rtb_Hypot - (4.0 * rtb_Modulation_Drv)) + 1.0;
          rtb_UnitDelay3 = (2.0 * rtb_Modulation_Drv) - rtb_Hypot;
          rtb_Switch2 = (rtb_Modulation_Drv - rtb_Switch2) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_TmpSignalConversionAtLoo_mu[0] *
            rtb_Switch1_c) + (rtb_Add2[0] * rtb_UnitDelay3)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_Switch2);
          rtb_Hypot = (((rtb_TmpSignalConversionAtLoo_mu[1] * rtb_Switch1_c) +
                        (rtb_Add2[1] * rtb_UnitDelay3)) * 0.5) +
            (rtb_Minus_k_idx_1 * rtb_Switch2);
          rtb_Switch2 = (6.0 * rtb_Modulation_Drv) - 4.0;
          rtb_Switch1_c = (-6.0 * rtb_Modulation_Drv) + 2.0;
          rtb_Modulation_Drv = (-12.0 * rtb_Modulation_Drv) + 6.0;
          rtb_UnitDelay3 = (((rtb_TmpSignalConversionAtLoo_mu[0] * rtb_Switch2)
                             + (rtb_Add2[0] * rtb_Switch1_c)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_Modulation_Drv);
          rtb_Switch1_c = (((rtb_TmpSignalConversionAtLoo_mu[1] * rtb_Switch2) +
                            (rtb_Add2[1] * rtb_Switch1_c)) * 0.5) +
            (rtb_Minus_k_idx_1 * rtb_Modulation_Drv);
          rtb_Switch2 = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Hypot), 3.0);
          rtb_Modulation_Drv = fmax(1.0E-10, rtb_Switch2);
          Robot_Control_DW.Relay_Mode = ((rtb_Switch2 >= 2.220446049250313E-16) ||
            (Robot_Control_DW.Relay_Mode));
          if (Robot_Control_DW.Relay_Mode) {
            rtb_Switch2 = 1.0;
          } else {
            rtb_Switch2 = -1.0;
          }

          if (rtb_Bias1_p == 0) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Subtract;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs
            ((rtb_MatrixConcatenate_idx_0 * rtb_Switch1_c) - (rtb_UnitDelay3 *
              rtb_Hypot)) / (rtb_Modulation_Drv * rtb_Switch2);
        }

        if (s114_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (rtb_Bias1_p = 0; rtb_Bias1_p < 3; rtb_Bias1_p++) {
          memcpy(&Robot_Control_B.Assignment[((rtb_Bias1_p * 50) + (s114_iter *
                   150)) + -150], &rtb_Assignment_d[rtb_Bias1_p * 50], 50U *
                 (sizeof(real_T)));
        }

        rtb_Modulation_Drv = rtb_Subtract_e - ((real_T)s114_iter);
        rtb_Num_Segments = s114_iter;
        s114_iter++;
      } while ((rtb_Modulation_Drv >= 4.0) && (s114_iter <= 3));

      /* End of Outputs for SubSystem: '<S110>/Sampling_Loop' */

      /* SignalConversion generated from: '<S93>/Position_and_Curvature' incorporates:
       *  Assignment: '<S114>/Assignment'
       *  Concatenate: '<S89>/Matrix Concatenate'
       */
      memcpy(&rtb_MatrixConcatenate_o[0], &Robot_Control_B.Assignment[0], 450U *
             (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S88>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem' incorporates:
       *  ActionPort: '<S91>/Action Port'
       */
      /* Product: '<S91>/Product' incorporates:
       *  Selector: '<S88>/Selector'
       *  Selector: '<S88>/Selector1'
       */
      rtb_Subtract_e = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S91>/Product1' incorporates:
       *  Selector: '<S88>/Selector'
       *  Selector: '<S88>/Selector1'
       */
      rtb_Modulation_Drv = rtb_Ref_Poses[((int32_T)
        Robot_Control_B.Spline_Num_Poses) + 9];
      for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
        /* Product: '<S91>/Product' incorporates:
         *  Constant: '<S91>/Constant2'
         */
        rtb_MatrixConcatenate_h[rtb_Bias1_p] = rtb_Subtract_e;

        /* Product: '<S91>/Product1' incorporates:
         *  Constant: '<S91>/Constant2'
         *  Product: '<S91>/Product'
         */
        rtb_MatrixConcatenate_h[rtb_Bias1_p + 50] = rtb_Modulation_Drv;
      }

      /* Assignment: '<S91>/Assignment' incorporates:
       *  Concatenate: '<S89>/Matrix Concatenate'
       *  Concatenate: '<S91>/Matrix Concatenate'
       */
      memset(&rtb_MatrixConcatenate_o[0], 0, 450U * (sizeof(real_T)));
      memcpy(&rtb_MatrixConcatenate_o[0], &rtb_MatrixConcatenate_h[0], 50U *
             (sizeof(real_T)));
      memcpy(&rtb_MatrixConcatenate_o[50], &rtb_MatrixConcatenate_h[50], 50U *
             (sizeof(real_T)));

      /* SignalConversion generated from: '<S91>/Num_Segments' incorporates:
       *  Constant: '<S91>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S88>/If Action Subsystem' */
    }

    /* End of If: '<S88>/If1' */

    /* Concatenate: '<S89>/Matrix Concatenate' incorporates:
     *  Selector: '<S89>/Selector'
     *  Selector: '<S89>/Selector1'
     *  Selector: '<S89>/Selector3'
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

    /* MATLAB Function: '<S89>/Distance Along Curve' incorporates:
     *  Concatenate: '<S89>/Matrix Concatenate'
     *  Selector: '<S89>/Selector4'
     *  Selector: '<S89>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s114_iter = 0; s114_iter < 149; s114_iter++) {
      /* Outputs for Iterator SubSystem: '<S110>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S114>/While Iterator'
       */
      rtb_Assignment_d[s114_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s114_iter + 1] -
         rtb_MatrixConcatenate_o[s114_iter], rtb_MatrixConcatenate_o[s114_iter +
         151] - rtb_MatrixConcatenate_o[s114_iter + 150]) +
        rtb_Assignment_d[s114_iter];

      /* End of Outputs for SubSystem: '<S110>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S89>/Distance Along Curve' */

    /* MATLAB Function: '<S89>/Find closest index to curve' incorporates:
     *  Concatenate: '<S89>/Matrix Concatenate'
     *  Selector: '<S140>/Selector'
     *  Selector: '<S89>/Selector4'
     *  Selector: '<S89>/Selector5'
     */
    for (s114_iter = 0; s114_iter < 150; s114_iter++) {
      /* Outputs for Iterator SubSystem: '<S110>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S114>/While Iterator'
       */
      distance_from_robot[s114_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s114_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s114_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S110>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s114_iter = 1;
    } else {
      s114_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s114_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s114_iter == 0) {
      rtb_Subtract_e = distance_from_robot[0];
    } else {
      rtb_Subtract_e = distance_from_robot[s114_iter - 1];
      for (rtb_Bias1_p = s114_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Modulation_Drv = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Subtract_e > rtb_Modulation_Drv) {
          rtb_Subtract_e = rtb_Modulation_Drv;
        }
      }
    }

    s114_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s114_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Subtract_e) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S140>/Selector' incorporates:
     *  Constant: '<S140>/Constant'
     *  MATLAB Function: '<S89>/Find closest index to curve'
     *  MinMax: '<S140>/Min'
     */
    rtb_Modulation_Drv = rtb_Assignment_d[((int32_T)fmin(50.0, s114_iter)) - 1];

    /* If: '<S140>/If' incorporates:
     *  RelationalOperator: '<S140>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S140>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S143>/Action Port'
       */
      /* SignalConversion generated from: '<S143>/Lookup Table Dynamic' */
      rtb_TmpSignalConversionAtLookup[0] = rtb_Assignment_d[0];
      rtb_TmpSignalConversionAtLookup[1] = rtb_Assignment_d[49];

      /* Sum: '<S145>/FixPt Sum1' incorporates:
       *  Constant: '<S145>/FixPt Constant'
       */
      rtb_Subtract_e = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S143>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S7>/Merge8'
       *  Selector: '<S143>/Selector11'
       *  Selector: '<S143>/Selector12'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = rtb_Spline_Ref_Poses_h[((int32_T)
        rtb_Subtract_e) + 19];
      rtb_TmpSignalConversionAtLoo_mu[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S143>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S7>/Merge8'
       *  Selector: '<S143>/Selector1'
       *  Selector: '<S143>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Subtract_e) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S143>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S143>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Subtract_e), &rtb_TmpSignalConversionAtLoo_mu
                           [0], rtb_Modulation_Drv,
                           &rtb_TmpSignalConversionAtLookup[0], 1U);

      /* SignalConversion: '<S143>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S143>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S143>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Modulation_Drv,
                           &rtb_TmpSignalConversionAtLookup[0], 1U);

      /* End of Outputs for SubSystem: '<S140>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S140>/Latch' incorporates:
       *  ActionPort: '<S144>/Action Port'
       */
      /* SignalConversion generated from: '<S144>/In1' incorporates:
       *  UnitDelay: '<S140>/Unit Delay1'
       */
      rtb_Subtract_e = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S144>/In2' incorporates:
       *  UnitDelay: '<S140>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S140>/Latch' */
    }

    /* End of If: '<S140>/If' */

    /* MinMax: '<S87>/Min' incorporates:
     *  Lookup_n-D: '<S87>/Lookahead Distance'
     *  UnitDelay: '<S87>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_h, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S89>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S139>/While Iterator'
     */
    s139_iter = 1U;
    rtb_LogicalOperator5 = true;
    while (rtb_LogicalOperator5 && (s139_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S89>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S139>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s139_iter;
      rtb_LogicalOperator5 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s114_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s139_iter++;
    }

    /* End of Outputs for SubSystem: '<S89>/Find first index that meets distance target' */

    /* Switch: '<S142>/Switch' incorporates:
     *  Concatenate: '<S89>/Matrix Concatenate'
     *  Constant: '<S139>/Constant'
     *  Constant: '<S142>/Constant'
     *  Constant: '<S142>/Constant1'
     *  Constant: '<S142>/Constant2'
     *  Constant: '<S142>/Constant3'
     *  Constant: '<S89>/Constant'
     *  Logic: '<S139>/AND'
     *  MATLAB Function: '<S89>/Find closest index to curve'
     *  Math: '<S142>/Hypot'
     *  Merge: '<S7>/Merge8'
     *  MinMax: '<S142>/Max'
     *  MinMax: '<S142>/Min'
     *  MinMax: '<S142>/Min1'
     *  Product: '<S139>/Product'
     *  Product: '<S142>/Divide'
     *  Product: '<S142>/Product'
     *  Product: '<S142>/Product1'
     *  RelationalOperator: '<S139>/Relational Operator'
     *  RelationalOperator: '<S139>/Relational Operator1'
     *  RelationalOperator: '<S89>/Relational Operator'
     *  Selector: '<S139>/Selector'
     *  Selector: '<S139>/Selector1'
     *  Selector: '<S140>/Selector'
     *  Selector: '<S89>/Selector10'
     *  Selector: '<S89>/Selector7'
     *  Selector: '<S89>/Selector8'
     *  Selector: '<S89>/Selector9'
     *  Sqrt: '<S142>/Sqrt'
     *  Sum: '<S139>/Add'
     *  Sum: '<S142>/Subtract'
     *  Sum: '<S142>/Subtract1'
     *  Sum: '<S89>/Subtract'
     */
    if (Robot_Control_B.Spline_Follow_Index >= (Robot_Control_B.Spline_Num_Poses
         - Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Saturation_h = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses_h[9] -
        Robot_Control_B.KF_Position_X, rtb_Spline_Ref_Poses_h[19] -
        Robot_Control_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Subtract_e *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration / fmax
         (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299], 1.0E-5))));
    } else {
      rtb_Saturation_h = fmin(rtb_Subtract_e * Spline_Velocity_Multiplier_TEST,
        sqrt(Spline_Max_Centripital_Acceleration / fmax
             (rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 299],
              1.0E-5)));
    }

    /* End of Switch: '<S142>/Switch' */

    /* Logic: '<S90>/OR' */
    rtb_Compare_mq = (rtb_LogicalOperator1 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S90>/Switch1' incorporates:
     *  Switch: '<S90>/Switch'
     *  UnitDelay: '<S90>/Unit Delay'
     */
    if (rtb_Compare_mq) {
      /* Merge: '<S9>/Merge2' incorporates:
       *  Constant: '<S90>/Constant3'
       *  SignalConversion: '<S90>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Modulation_Drv = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S9>/Merge2' incorporates:
       *  SignalConversion: '<S90>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Modulation_Drv = rtb_Merge1;
    }

    /* End of Switch: '<S90>/Switch1' */

    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion: '<S90>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Modulation_Drv;

    /* Selector: '<S89>/Selector6' incorporates:
     *  Concatenate: '<S89>/Matrix Concatenate'
     *  Selector: '<S89>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S89>/Selector2' incorporates:
     *  Concatenate: '<S89>/Matrix Concatenate'
     *  Selector: '<S89>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S90>/Switch2' incorporates:
     *  Sum: '<S146>/Subtract'
     *  Sum: '<S146>/Subtract1'
     *  Trigonometry: '<S146>/Atan2'
     *  UnitDelay: '<S90>/Unit Delay1'
     */
    if (rtb_Compare_mq) {
      rtb_Switch2 = Robot_Control_DW.UnitDelay1_DSTATE_k;
    } else {
      rtb_Switch2 = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S90>/Switch2' */

    /* Merge: '<S9>/Merge3' incorporates:
     *  SignalConversion: '<S90>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Switch2;

    /* Merge: '<S9>/Merge7' incorporates:
     *  SignalConversion: '<S87>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator1;

    /* Merge: '<S9>/Merge6' incorporates:
     *  SignalConversion: '<S87>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S90>/Constant2'
     *  SignalConversion generated from: '<S87>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S9>/Merge4' incorporates:
     *  Constant: '<S90>/Constant5'
     *  SignalConversion generated from: '<S87>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S9>/Merge5' incorporates:
     *  Constant: '<S90>/Constant6'
     *  SignalConversion generated from: '<S87>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S9>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S87>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S88>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S87>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_h = rtb_Saturation_h;

    /* Update for UnitDelay: '<S140>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Subtract_e;

    /* Update for UnitDelay: '<S140>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S90>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Modulation_Drv;

    /* Update for UnitDelay: '<S90>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_k = rtb_Switch2;

    /* End of Outputs for SubSystem: '<S9>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/Pass Through' incorporates:
     *  ActionPort: '<S86>/Action Port'
     */
    /* Merge: '<S9>/Merge6' incorporates:
     *  Constant: '<S86>/Constant1'
     *  SignalConversion generated from: '<S86>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S9>/Merge7' incorporates:
     *  Constant: '<S86>/Constant'
     *  SignalConversion generated from: '<S86>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion generated from: '<S86>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S9>/Merge1' incorporates:
     *  SignalConversion generated from: '<S86>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion generated from: '<S86>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S9>/Merge3' incorporates:
     *  SignalConversion generated from: '<S86>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S9>/Merge4' incorporates:
     *  SignalConversion generated from: '<S86>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Compare_ph;

    /* Merge: '<S9>/Merge5' incorporates:
     *  SignalConversion generated from: '<S86>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S9>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S86>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S9>/Pass Through' */
  }

  /* End of If: '<S9>/If' */

  /* Signum: '<S236>/Sign2' incorporates:
   *  UnitDelay: '<S236>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    rtb_Add_f1 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    rtb_Add_f1 = -1.0;
  } else {
    rtb_Add_f1 = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S236>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S236>/Product1' incorporates:
   *  Signum: '<S236>/Sign1'
   *  Signum: '<S236>/Sign2'
   */
  rtb_Add_f1 *= rtb_Product_lb;
  if (rtIsNaN(rtb_Add_f1)) {
    rtb_Bias1_p = 0;
  } else {
    rtb_Bias1_p = (int32_T)fmod(rtb_Add_f1, 256.0);
  }

  /* Switch: '<S236>/Switch' incorporates:
   *  Constant: '<S236>/Constant'
   *  Constant: '<S241>/Constant'
   *  Constant: '<S242>/Constant'
   *  Logic: '<S236>/or'
   *  Product: '<S236>/Product1'
   *  RelationalOperator: '<S241>/Compare'
   *  RelationalOperator: '<S242>/Compare'
   *  UnitDelay: '<S236>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((rtb_Bias1_p < 0) ?
        ((int32_T)((int8_T)(-((int8_T)((uint8_T)(-((real_T)rtb_Bias1_p))))))) :
        rtb_Bias1_p) > 0)) {
    rtb_uDLookupTable = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_uDLookupTable = 0.0;
  }

  /* End of Switch: '<S236>/Switch' */

  /* Switch: '<S247>/Init' incorporates:
   *  UnitDelay: '<S247>/FixPt Unit Delay1'
   *  UnitDelay: '<S247>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Switch1_c = rtb_uDLookupTable;
  } else {
    rtb_Switch1_c = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S247>/Init' */

  /* RelationalOperator: '<S243>/Compare' incorporates:
   *  Constant: '<S243>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_uDLookupTable == 0.0);

  /* RelationalOperator: '<S244>/Compare' incorporates:
   *  Constant: '<S244>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_uDLookupTable > 0.0);

  /* Abs: '<S236>/Abs' incorporates:
   *  Sum: '<S236>/Subtract'
   *  UnitDelay: '<S236>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S236>/Switch1' incorporates:
   *  Constant: '<S236>/Constant1'
   *  Switch: '<S236>/Switch3'
   *  Switch: '<S236>/Switch5'
   *  UnaryMinus: '<S236>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    rtb_Subtract_e = -Translation_Speed_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S236>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S236>/Constant1'
     *  Constant: '<S236>/Constant4'
     *  Constant: '<S236>/Constant6'
     *  UnaryMinus: '<S236>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S236>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S236>/Constant2'
     *  Constant: '<S236>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S236>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S236>/Lookup Table Dynamic'
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
      /* Switch: '<S236>/Switch3' incorporates:
       *  Constant: '<S236>/Constant3'
       */
      rtb_Subtract_e = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Subtract_e = -Translation_Speed_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S236>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S236>/Constant1'
     *  Constant: '<S236>/Constant10'
     *  Constant: '<S236>/Constant8'
     *  UnaryMinus: '<S236>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S236>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S236>/Constant7'
     *  Constant: '<S236>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S236>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S236>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S236>/Switch1' */

  /* Product: '<S236>/Product' */
  rtb_Subtract_e *= rtb_Merge1;

  /* Sum: '<S245>/Sum1' */
  rtb_Saturation_h = rtb_uDLookupTable - rtb_Switch1_c;

  /* Switch: '<S246>/Switch2' incorporates:
   *  RelationalOperator: '<S246>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Subtract_e)) {
    /* Switch: '<S236>/Switch2' incorporates:
     *  Constant: '<S236>/Constant1'
     *  Switch: '<S236>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Subtract_e = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S236>/Switch4' incorporates:
       *  Constant: '<S236>/Constant1'
       */
      rtb_Subtract_e = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S236>/Switch4' incorporates:
       *  Constant: '<S236>/Constant3'
       *  UnaryMinus: '<S236>/Unary Minus1'
       */
      rtb_Subtract_e = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S236>/Switch2' */

    /* Product: '<S236>/Product2' */
    rtb_Subtract_e *= rtb_Merge1;

    /* Switch: '<S246>/Switch' incorporates:
     *  RelationalOperator: '<S246>/UpperRelop'
     */
    if (!(rtb_Saturation_h < rtb_Subtract_e)) {
      rtb_Subtract_e = rtb_Saturation_h;
    }

    /* End of Switch: '<S246>/Switch' */
  }

  /* End of Switch: '<S246>/Switch2' */

  /* Sum: '<S245>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Subtract_e + rtb_Switch1_c;

  /* Switch: '<S239>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S239>/Switch' incorporates:
     *  Constant: '<S273>/Constant3'
     *  Constant: '<S273>/Constant4'
     *  Math: '<S273>/Math Function'
     *  Sum: '<S239>/Subtract'
     *  Sum: '<S273>/Add1'
     *  Sum: '<S273>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.141592653589793, 6.283185307179586) - 3.141592653589793;
  } else {
    /* Switch: '<S239>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S239>/Switch' */

  /* Sum: '<S268>/Add1' incorporates:
   *  Constant: '<S268>/Constant3'
   *  Constant: '<S268>/Constant4'
   *  Math: '<S268>/Math Function'
   *  Sum: '<S267>/Sum'
   *  Sum: '<S268>/Add2'
   */
  rtb_Switch1_c = rt_modd_snf((Robot_Control_B.Steering_Abs_Cmd_SPF -
    Robot_Control_B.Gyro_Angle_SPF) + 3.141592653589793, 6.283185307179586) -
    3.141592653589793;

  /* Gain: '<S271>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.29577951308232 * rtb_Switch1_c;

  /* Sum: '<S270>/Sum1' incorporates:
   *  Constant: '<S267>/Constant2'
   *  Product: '<S270>/Product'
   *  Sum: '<S270>/Sum'
   *  UnitDelay: '<S270>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_Switch1_c - Robot_Control_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S267>/Product' incorporates:
   *  Constant: '<S267>/Constant3'
   */
  rtb_Saturation_h = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S269>/Diff' incorporates:
   *  UnitDelay: '<S269>/UD'
   *
   * Block description for '<S269>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S269>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_f1 = rtb_Saturation_h - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S267>/Saturation' */
  if (rtb_Add_f1 > Steering_Heading_Control_D_UL) {
    rtb_Add_f1 = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_f1 < Steering_Heading_Control_D_LL) {
    rtb_Add_f1 = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S267>/Add' incorporates:
   *  Gain: '<S267>/Gain1'
   *  Saturate: '<S267>/Saturation'
   */
  rtb_Switch2 = (Steering_Heading_Control_P * rtb_Switch1_c) + rtb_Add_f1;

  /* Sum: '<S267>/Subtract' incorporates:
   *  Constant: '<S267>/Constant'
   */
  rtb_Subtract_e = Steering_Heading_Control_Total_UL - rtb_Switch2;

  /* Sum: '<S267>/Sum2' incorporates:
   *  Gain: '<S267>/Gain2'
   *  UnitDelay: '<S267>/Unit Delay'
   */
  rtb_Switch1_c = (Steering_Heading_Control_I * rtb_Switch1_c) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S272>/Switch2' incorporates:
   *  RelationalOperator: '<S272>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_Subtract_e)) {
    /* Sum: '<S267>/Subtract1' incorporates:
     *  Constant: '<S267>/Constant1'
     */
    rtb_Subtract_e = Steering_Heading_Control_Total_LL - rtb_Switch2;

    /* Switch: '<S272>/Switch' incorporates:
     *  RelationalOperator: '<S272>/UpperRelop'
     */
    if (!(rtb_Switch1_c < rtb_Subtract_e)) {
      rtb_Subtract_e = rtb_Switch1_c;
    }

    /* End of Switch: '<S272>/Switch' */
  }

  /* End of Switch: '<S272>/Switch2' */

  /* Saturate: '<S267>/Saturation1' */
  if (rtb_Subtract_e > Steering_Heading_Control_I_UL) {
    rtb_Subtract_e = Steering_Heading_Control_I_UL;
  } else if (rtb_Subtract_e < Steering_Heading_Control_I_LL) {
    rtb_Subtract_e = Steering_Heading_Control_I_LL;
  }

  /* End of Saturate: '<S267>/Saturation1' */

  /* Sum: '<S267>/Add1' */
  rtb_Add_f1 = rtb_Switch2 + rtb_Subtract_e;

  /* Saturate: '<S267>/Saturation2' */
  if (rtb_Add_f1 > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S267>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_f1 < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S267>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S267>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = rtb_Add_f1;
  }

  /* End of Saturate: '<S267>/Saturation2' */

  /* Abs: '<S250>/Abs' */
  rtb_Switch2 = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S250>/Add dither' */
  if (Robot_Control_DW.is_active_c7_Robot_Control == 0) {
    Robot_Control_DW.is_active_c7_Robot_Control = 1U;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Switch2;
  } else if (Robot_Control_DW.is_c7_Robot_Control == Robot_Control_IN_Dither) {
    Robot_Control_DW.is_Dither = Robot_Contro_IN_NO_ACTIVE_CHILD;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Switch2;
  } else {
    /* case IN_No_Dither: */
    Robot_Control_B.abs_Cmd_Out = rtb_Switch2;
  }

  /* End of Chart: '<S250>/Add dither' */

  /* Switch: '<S250>/Switch' incorporates:
   *  Constant: '<S250>/Constant'
   *  Constant: '<S266>/Constant'
   *  Product: '<S250>/Product'
   *  RelationalOperator: '<S266>/Compare'
   *  Signum: '<S250>/Sign'
   */
  if (rtb_Switch2 > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S250>/Sign' */
    if (rtIsNaN(Robot_Control_B.Steering_Heading_PID)) {
      rtb_Add_f1 = (rtNaN);
    } else if (Robot_Control_B.Steering_Heading_PID < 0.0) {
      rtb_Add_f1 = -1.0;
    } else {
      rtb_Add_f1 = (Robot_Control_B.Steering_Heading_PID > 0.0);
    }

    rtb_Switch1_c = Robot_Control_B.abs_Cmd_Out * rtb_Add_f1;
  } else {
    rtb_Switch1_c = 0.0;
  }

  /* End of Switch: '<S250>/Switch' */

  /* Signum: '<S249>/Sign2' incorporates:
   *  UnitDelay: '<S249>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    rtb_Add_f1 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    rtb_Add_f1 = -1.0;
  } else {
    rtb_Add_f1 = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S249>/Sign1' */
  if (rtIsNaN(rtb_Switch1_c)) {
    rtb_Product_lb = (rtNaN);
  } else if (rtb_Switch1_c < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (rtb_Switch1_c > 0.0);
  }

  /* Product: '<S249>/Product1' incorporates:
   *  Signum: '<S249>/Sign1'
   *  Signum: '<S249>/Sign2'
   */
  rtb_Add_f1 *= rtb_Product_lb;
  if (rtIsNaN(rtb_Add_f1)) {
    rtb_Bias1_p = 0;
  } else {
    rtb_Bias1_p = (int32_T)fmod(rtb_Add_f1, 256.0);
  }

  /* Switch: '<S249>/Switch' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S258>/Constant'
   *  Constant: '<S259>/Constant'
   *  Logic: '<S249>/or'
   *  Product: '<S249>/Product1'
   *  RelationalOperator: '<S258>/Compare'
   *  RelationalOperator: '<S259>/Compare'
   *  UnitDelay: '<S249>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((rtb_Bias1_p < 0) ?
        ((int32_T)((int8_T)(-((int8_T)((uint8_T)(-((real_T)rtb_Bias1_p))))))) :
        rtb_Bias1_p) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch1_c;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S249>/Switch' */

  /* Switch: '<S264>/Init' incorporates:
   *  UnitDelay: '<S264>/FixPt Unit Delay1'
   *  UnitDelay: '<S264>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S264>/Init' */

  /* RelationalOperator: '<S260>/Compare' incorporates:
   *  Constant: '<S260>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S261>/Compare' incorporates:
   *  Constant: '<S261>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S249>/Abs' incorporates:
   *  Sum: '<S249>/Subtract'
   *  UnitDelay: '<S249>/Unit Delay'
   */
  rtb_Modulation_Drv = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 - rtb_Switch1_c);

  /* Switch: '<S249>/Switch1' incorporates:
   *  Constant: '<S249>/Constant1'
   *  Switch: '<S249>/Switch3'
   *  Switch: '<S249>/Switch5'
   *  UnaryMinus: '<S249>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    rtb_Switch2 = -Steering_Absolute_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S249>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S249>/Constant1'
     *  Constant: '<S249>/Constant4'
     *  Constant: '<S249>/Constant6'
     *  UnaryMinus: '<S249>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S249>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S249>/Constant2'
     *  Constant: '<S249>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S249>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S249>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Modulation_Drv,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Modulation_Drv = rtb_LookupTableDynamic;
  } else {
    if (rtb_LogicalOperator5) {
      /* Switch: '<S249>/Switch3' incorporates:
       *  Constant: '<S249>/Constant3'
       */
      rtb_Switch2 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Switch2 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S249>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S249>/Constant1'
     *  Constant: '<S249>/Constant10'
     *  Constant: '<S249>/Constant8'
     *  UnaryMinus: '<S249>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S249>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S249>/Constant7'
     *  Constant: '<S249>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S249>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S249>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Modulation_Drv,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Modulation_Drv = rtb_LookupTableDynamic1;
  }

  /* End of Switch: '<S249>/Switch1' */

  /* Product: '<S249>/Product' */
  rtb_Switch2 *= rtb_Modulation_Drv;

  /* Sum: '<S262>/Sum1' */
  rtb_Switch1_c = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle;

  /* Switch: '<S263>/Switch2' incorporates:
   *  RelationalOperator: '<S263>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_Switch2)) {
    /* Switch: '<S249>/Switch2' incorporates:
     *  Constant: '<S249>/Constant1'
     *  Switch: '<S249>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Switch2 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S249>/Switch4' incorporates:
       *  Constant: '<S249>/Constant1'
       */
      rtb_Switch2 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S249>/Switch4' incorporates:
       *  Constant: '<S249>/Constant3'
       *  UnaryMinus: '<S249>/Unary Minus1'
       */
      rtb_Switch2 = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S249>/Switch2' */

    /* Product: '<S249>/Product2' */
    rtb_Switch2 *= rtb_Modulation_Drv;

    /* Switch: '<S263>/Switch' incorporates:
     *  RelationalOperator: '<S263>/UpperRelop'
     */
    if (!(rtb_Switch1_c < rtb_Switch2)) {
      rtb_Switch2 = rtb_Switch1_c;
    }

    /* End of Switch: '<S263>/Switch' */
  }

  /* End of Switch: '<S263>/Switch2' */

  /* Sum: '<S262>/Sum' */
  rtb_Modulation_Drv = rtb_Switch2 + rtb_Optimized_Module_Angle;

  /* Signum: '<S248>/Sign2' incorporates:
   *  UnitDelay: '<S248>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    rtb_Add_f1 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    rtb_Add_f1 = -1.0;
  } else {
    rtb_Add_f1 = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S248>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S248>/Product1' incorporates:
   *  Signum: '<S248>/Sign1'
   *  Signum: '<S248>/Sign2'
   */
  rtb_Add_f1 *= rtb_Product_lb;
  if (rtIsNaN(rtb_Add_f1)) {
    rtb_Bias1_p = 0;
  } else {
    rtb_Bias1_p = (int32_T)fmod(rtb_Add_f1, 256.0);
  }

  /* Switch: '<S248>/Switch' incorporates:
   *  Constant: '<S248>/Constant'
   *  Constant: '<S251>/Constant'
   *  Constant: '<S252>/Constant'
   *  Logic: '<S248>/or'
   *  Product: '<S248>/Product1'
   *  RelationalOperator: '<S251>/Compare'
   *  RelationalOperator: '<S252>/Compare'
   *  UnitDelay: '<S248>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((rtb_Bias1_p < 0) ?
        ((int32_T)((int8_T)(-((int8_T)((uint8_T)(-((real_T)rtb_Bias1_p))))))) :
        rtb_Bias1_p) > 0)) {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
  }

  /* End of Switch: '<S248>/Switch' */

  /* Switch: '<S257>/Init' incorporates:
   *  UnitDelay: '<S257>/FixPt Unit Delay1'
   *  UnitDelay: '<S257>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Optimized_Module_Angle = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S257>/Init' */

  /* RelationalOperator: '<S253>/Compare' incorporates:
   *  Constant: '<S253>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* RelationalOperator: '<S254>/Compare' incorporates:
   *  Constant: '<S254>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);

  /* Abs: '<S248>/Abs' incorporates:
   *  Sum: '<S248>/Subtract'
   *  UnitDelay: '<S248>/Unit Delay'
   */
  rtb_Switch2 = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                     Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S248>/Switch5' incorporates:
   *  Constant: '<S248>/Constant1'
   *  Switch: '<S248>/Switch1'
   *  UnaryMinus: '<S248>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S248>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S248>/Constant4'
     *  Constant: '<S248>/Constant6'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S248>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S248>/Constant2'
     *  Constant: '<S248>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S248>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S248>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Switch2,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_UnitDelay3 = rtb_LookupTableDynamic_p;
    rtb_Add_f1 = -Steering_Relative_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S248>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S248>/Constant10'
     *  Constant: '<S248>/Constant8'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S248>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S248>/Constant7'
     *  Constant: '<S248>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S248>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S248>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_Switch2,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_UnitDelay3 = rtb_LookupTableDynamic1_g;

    /* Switch: '<S248>/Switch3' incorporates:
     *  Constant: '<S248>/Constant1'
     *  Constant: '<S248>/Constant3'
     *  UnaryMinus: '<S248>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      rtb_Add_f1 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_f1 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S248>/Switch3' */
  }

  /* End of Switch: '<S248>/Switch5' */

  /* Product: '<S248>/Product' incorporates:
   *  Switch: '<S248>/Switch1'
   */
  rtb_Switch2 = rtb_Add_f1 * rtb_UnitDelay3;

  /* Sum: '<S255>/Sum1' */
  rtb_Switch1_c = rtb_MatrixConcatenate_b_idx_0 - rtb_Optimized_Module_Angle;

  /* Switch: '<S256>/Switch2' incorporates:
   *  RelationalOperator: '<S256>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_Switch2)) {
    /* Switch: '<S248>/Switch2' incorporates:
     *  Constant: '<S248>/Constant1'
     *  Switch: '<S248>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Switch2 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S248>/Switch4' incorporates:
       *  Constant: '<S248>/Constant1'
       */
      rtb_Switch2 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S248>/Switch4' incorporates:
       *  Constant: '<S248>/Constant3'
       *  UnaryMinus: '<S248>/Unary Minus1'
       */
      rtb_Switch2 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S248>/Switch2' */

    /* Product: '<S248>/Product2' */
    rtb_Switch2 *= rtb_UnitDelay3;

    /* Switch: '<S256>/Switch' incorporates:
     *  RelationalOperator: '<S256>/UpperRelop'
     */
    if (!(rtb_Switch1_c < rtb_Switch2)) {
      rtb_Switch2 = rtb_Switch1_c;
    }

    /* End of Switch: '<S256>/Switch' */
  }

  /* End of Switch: '<S256>/Switch2' */

  /* Sum: '<S255>/Sum' */
  rtb_Switch1_c = rtb_Switch2 + rtb_Optimized_Module_Angle;

  /* Switch: '<S238>/Switch' */
  if (Robot_Control_B.Is_Absolute_Steering_SPF) {
    /* Switch: '<S238>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Modulation_Drv;
  } else {
    /* Switch: '<S238>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch1_c;
  }

  /* End of Switch: '<S238>/Switch' */

  /* Fcn: '<S281>/r->x' incorporates:
   *  Fcn: '<S286>/r->x'
   *  Fcn: '<S291>/r->x'
   *  Fcn: '<S296>/r->x'
   */
  rtb_Switch2 = cos(Robot_Control_B.Translation_Steering_Cmd);

  /* Fcn: '<S281>/theta->y' incorporates:
   *  Fcn: '<S286>/theta->y'
   *  Fcn: '<S291>/theta->y'
   *  Fcn: '<S296>/theta->y'
   */
  rtb_UnitDelay3 = sin(Robot_Control_B.Translation_Steering_Cmd);

  /* Fcn: '<S281>/r->x' incorporates:
   *  Fcn: '<S286>/r->x'
   *  Fcn: '<S291>/r->x'
   *  Fcn: '<S296>/r->x'
   */
  rtb_Switch2 *= Robot_Control_B.Translation_Speed_RL;

  /* Sum: '<S275>/Add' incorporates:
   *  Fcn: '<S281>/r->x'
   *  Fcn: '<S282>/r->x'
   */
  rtb_TmpSignalConversionAtLookup[0] = (Robot_Control_B.Steering_Localized_Cmd *
    cos(Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch2;

  /* Fcn: '<S281>/theta->y' incorporates:
   *  Fcn: '<S286>/theta->y'
   *  Fcn: '<S291>/theta->y'
   *  Fcn: '<S296>/theta->y'
   */
  rtb_UnitDelay3 *= Robot_Control_B.Translation_Speed_RL;

  /* Sum: '<S275>/Add' incorporates:
   *  Fcn: '<S281>/theta->y'
   *  Fcn: '<S282>/theta->y'
   */
  rtb_TmpSignalConversionAtLookup[1] = (Robot_Control_B.Steering_Localized_Cmd *
    sin(Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_UnitDelay3;

  /* Sum: '<S276>/Add' incorporates:
   *  Fcn: '<S287>/r->x'
   *  Fcn: '<S287>/theta->y'
   */
  rtb_TmpSignalConversionAtLoo_mu[0] = (Robot_Control_B.Steering_Localized_Cmd *
    cos(Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch2;
  rtb_TmpSignalConversionAtLoo_mu[1] = (Robot_Control_B.Steering_Localized_Cmd *
    sin(Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_UnitDelay3;

  /* Sum: '<S277>/Add' incorporates:
   *  Fcn: '<S292>/r->x'
   *  Fcn: '<S292>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch2;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_UnitDelay3;

  /* Sum: '<S278>/Add' incorporates:
   *  Fcn: '<S297>/r->x'
   *  Fcn: '<S297>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch2;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_UnitDelay3;

  /* Fcn: '<S295>/x->r' */
  rtb_Switch2 = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S298>/Compare' incorporates:
   *  Constant: '<S298>/Constant'
   */
  rtb_Compare_ph = (rtb_Switch2 == 0.0);

  /* Switch: '<S294>/Switch1' */
  if (rtb_Compare_ph) {
    /* Switch: '<S294>/Switch1' incorporates:
     *  Constant: '<S294>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S294>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_Switch2;
  }

  /* End of Switch: '<S294>/Switch1' */

  /* Fcn: '<S280>/x->r' */
  rtb_Switch2 = rt_hypotd_snf(rtb_TmpSignalConversionAtLookup[0],
    rtb_TmpSignalConversionAtLookup[1]);

  /* RelationalOperator: '<S283>/Compare' incorporates:
   *  Constant: '<S283>/Constant'
   */
  rtb_Compare_mq = (rtb_Switch2 == 0.0);

  /* Switch: '<S279>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S279>/Switch1' incorporates:
     *  Constant: '<S279>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S279>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_Switch2;
  }

  /* End of Switch: '<S279>/Switch1' */

  /* Fcn: '<S285>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu
    [0], rtb_TmpSignalConversionAtLoo_mu[1]);

  /* RelationalOperator: '<S288>/Compare' incorporates:
   *  Constant: '<S288>/Constant'
   */
  rtb_Compare_ky = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S284>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S284>/Switch1' incorporates:
     *  Constant: '<S284>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S284>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S284>/Switch1' */

  /* Fcn: '<S290>/x->r' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S293>/Compare' incorporates:
   *  Constant: '<S293>/Constant'
   */
  rtb_Compare_bd = (rtb_Optimized_Module_Angle == 0.0);

  /* Switch: '<S289>/Switch1' */
  if (rtb_Compare_bd) {
    /* Switch: '<S289>/Switch1' incorporates:
     *  Constant: '<S289>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S289>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_Optimized_Module_Angle;
  }

  /* End of Switch: '<S289>/Switch1' */

  /* Product: '<S274>/Divide' incorporates:
   *  Abs: '<S274>/Abs'
   *  Abs: '<S274>/Abs1'
   *  Abs: '<S274>/Abs2'
   *  Abs: '<S274>/Abs3'
   *  Constant: '<S274>/Constant'
   *  MinMax: '<S274>/Max'
   */
  rtb_Switch2 = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S274>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_Switch2;

  /* Switch: '<S294>/Switch' */
  if (!rtb_Compare_ph) {
    /* Switch: '<S294>/Switch' incorporates:
     *  Fcn: '<S295>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S294>/Switch' */

  /* Trigonometry: '<S228>/Cos4' incorporates:
   *  Switch: '<S217>/Angle_Switch'
   *  Trigonometry: '<S227>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S228>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S226>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S228>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S228>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S226>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S228>/Subtract1' incorporates:
   *  Product: '<S228>/Product2'
   *  Product: '<S228>/Product3'
   *  Trigonometry: '<S228>/Cos4'
   */
  rtb_UnitDelay3 = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) + (rtb_Minus_k_idx_1 *
    rtb_Optimized_Module_Angle);

  /* Sum: '<S228>/Subtract' incorporates:
   *  Product: '<S228>/Product'
   *  Product: '<S228>/Product1'
   *  Trigonometry: '<S228>/Cos4'
   */
  rtb_Subtract = (rtb_Minus_k_idx_0 * rtb_Optimized_Module_Angle) -
    (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S228>/Hypot' */
  rtb_Hypot = rt_hypotd_snf(rtb_Subtract, rtb_UnitDelay3);

  /* Switch: '<S228>/Switch' incorporates:
   *  Constant: '<S228>/Constant'
   *  Constant: '<S228>/Constant1'
   *  Constant: '<S229>/Constant'
   *  Product: '<S228>/Divide'
   *  Product: '<S228>/Divide1'
   *  RelationalOperator: '<S229>/Compare'
   *  Switch: '<S228>/Switch1'
   */
  if (rtb_Hypot > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_UnitDelay3 / rtb_Hypot;
    rtb_Optimized_Module_Angle = rtb_Subtract / rtb_Hypot;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S228>/Switch' */

  /* Switch: '<S217>/Speed_Switch' incorporates:
   *  Abs: '<S217>/Abs'
   *  Constant: '<S225>/Constant'
   *  RelationalOperator: '<S225>/Compare'
   *  Switch: '<S217>/Angle_Switch'
   *  Trigonometry: '<S227>/Atan1'
   *  Trigonometry: '<S228>/Atan1'
   *  UnaryMinus: '<S217>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_f1 = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S227>/Subtract1' incorporates:
     *  Product: '<S227>/Product2'
     *  Product: '<S227>/Product3'
     *  Trigonometry: '<S227>/Sin4'
     *  UnaryMinus: '<S217>/Unary Minus'
     */
    rtb_UnitDelay3 = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Sin5_c) +
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S227>/Subtract' incorporates:
     *  Product: '<S227>/Product'
     *  Product: '<S227>/Product1'
     *  Trigonometry: '<S227>/Sin4'
     */
    rtb_Hypot = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5_b) -
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S227>/Hypot' */
    rtb_Subtract = rt_hypotd_snf(rtb_Hypot, rtb_UnitDelay3);

    /* Switch: '<S227>/Switch1' incorporates:
     *  Constant: '<S227>/Constant'
     *  Constant: '<S227>/Constant1'
     *  Constant: '<S230>/Constant'
     *  Product: '<S227>/Divide'
     *  Product: '<S227>/Divide1'
     *  RelationalOperator: '<S230>/Compare'
     *  Switch: '<S227>/Switch'
     */
    if (rtb_Subtract > 1.0E-6) {
      rtb_Hypot /= rtb_Subtract;
      rtb_UnitDelay3 /= rtb_Subtract;
    } else {
      rtb_Hypot = 1.0;
      rtb_UnitDelay3 = 0.0;
    }

    /* End of Switch: '<S227>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_UnitDelay3, rtb_Hypot);
  } else {
    rtb_Add_f1 = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S220>/Product2' incorporates:
   *  Constant: '<S220>/Constant'
   *  Switch: '<S217>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_f1 * 1154.7574092481445;

  /* Signum: '<S215>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_f1 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_f1 = -1.0;
  } else {
    rtb_Add_f1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S215>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S218>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S219>/Sum'
   */
  rtb_uDLookupTable -= Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S150>/Product' incorporates:
   *  Abs: '<S215>/Abs'
   *  Abs: '<S218>/Abs'
   *  Constant: '<S221>/Constant'
   *  Constant: '<S231>/Constant3'
   *  Constant: '<S231>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
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
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_f1 == rtb_Product_lb) ||
    (fabs(Robot_Control_U.BackRight_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_uDLookupTable + 1.5707963267948966,
    3.141592653589793) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
                    rtCP_uDLookupTable_tableData_g, 1U);

  /* Gain: '<S216>/Gain' */
  rtb_Hypot = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S216>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S223>/Sum1' incorporates:
   *  Constant: '<S216>/Constant2'
   *  Product: '<S223>/Product'
   *  Sum: '<S223>/Sum'
   *  UnitDelay: '<S223>/Unit Delay1'
   */
  rtb_UnitDelay3 = ((rtb_MatrixConcatenate_b_idx_0 -
                     Robot_Control_DW.UnitDelay1_DSTATE_j) *
                    Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S216>/Product' incorporates:
   *  Constant: '<S216>/Constant3'
   */
  rtb_Subtract = rtb_UnitDelay3 * Drive_Motor_Control_D;

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
  rtb_Add_f1 = rtb_Subtract - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S216>/Saturation' */
  if (rtb_Add_f1 > Drive_Motor_Control_D_UL) {
    rtb_Add_f1 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_f1 < Drive_Motor_Control_D_LL) {
    rtb_Add_f1 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S216>/Add' incorporates:
   *  Gain: '<S216>/Gain1'
   *  Saturate: '<S216>/Saturation'
   */
  rtb_Add_f1 += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Hypot;

  /* Saturate: '<S216>/Saturation2' */
  if (rtb_Add_f1 > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_f1 < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = rtb_Add_f1;
  }

  /* End of Saturate: '<S216>/Saturation2' */

  /* Sum: '<S232>/Add1' incorporates:
   *  Constant: '<S232>/Constant3'
   *  Constant: '<S232>/Constant4'
   *  Math: '<S232>/Math Function'
   *  Sum: '<S232>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_uDLookupTable +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S234>/Sum1' incorporates:
   *  Constant: '<S219>/Constant2'
   *  Product: '<S234>/Product'
   *  Sum: '<S234>/Sum'
   *  UnitDelay: '<S234>/Unit Delay1'
   */
  rtb_Hypot = ((rtb_MatrixConcatenate_b_idx_0 -
                Robot_Control_DW.UnitDelay1_DSTATE_i) *
               Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S219>/Product' incorporates:
   *  Constant: '<S219>/Constant3'
   */
  rtb_MatrixConcatenate_idx_0 = rtb_Hypot * Steering_Motor_Control_D;

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
  rtb_Add_f1 = rtb_MatrixConcatenate_idx_0 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S219>/Saturation' */
  if (rtb_Add_f1 > Steering_Motor_Control_D_UL) {
    rtb_Add_f1 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_f1 < Steering_Motor_Control_D_LL) {
    rtb_Add_f1 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S219>/Add' incorporates:
   *  Gain: '<S219>/Gain1'
   *  Saturate: '<S219>/Saturation'
   */
  rtb_Add_pw = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_f1;

  /* Sum: '<S219>/Subtract' incorporates:
   *  Constant: '<S219>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_pw;

  /* Sum: '<S219>/Sum2' incorporates:
   *  Gain: '<S219>/Gain2'
   *  UnitDelay: '<S219>/Unit Delay'
   */
  rtb_Sum2_fc = (Steering_Motor_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Robot_Control_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S235>/Switch2' incorporates:
   *  Constant: '<S219>/Constant'
   *  RelationalOperator: '<S235>/LowerRelop1'
   *  Sum: '<S219>/Subtract'
   */
  if (!(rtb_Sum2_fc > (1.0 - rtb_Add_pw))) {
    /* Switch: '<S235>/Switch' incorporates:
     *  Constant: '<S219>/Constant1'
     *  RelationalOperator: '<S235>/UpperRelop'
     *  Sum: '<S219>/Subtract1'
     */
    if (rtb_Sum2_fc < (-1.0 - rtb_Add_pw)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_pw;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_fc;
    }

    /* End of Switch: '<S235>/Switch' */
  }

  /* End of Switch: '<S235>/Switch2' */

  /* Saturate: '<S219>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S219>/Saturation1' */

  /* Sum: '<S219>/Add1' */
  rtb_Add_f1 = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S219>/Saturation2' */
  if (rtb_Add_f1 > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_f1 < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = rtb_Add_f1;
  }

  /* End of Saturate: '<S219>/Saturation2' */

  /* Product: '<S274>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_Switch2;

  /* Switch: '<S279>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S279>/Switch' incorporates:
     *  Fcn: '<S280>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLookup[1], rtb_TmpSignalConversionAtLookup[0]);
  }

  /* End of Switch: '<S279>/Switch' */

  /* Trigonometry: '<S165>/Cos4' incorporates:
   *  Switch: '<S154>/Angle_Switch'
   *  Trigonometry: '<S164>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S165>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S163>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S165>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S165>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S163>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S165>/Subtract1' incorporates:
   *  Product: '<S165>/Product2'
   *  Product: '<S165>/Product3'
   *  Trigonometry: '<S165>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) +
    (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle);

  /* Sum: '<S165>/Subtract' incorporates:
   *  Product: '<S165>/Product'
   *  Product: '<S165>/Product1'
   *  Trigonometry: '<S165>/Cos4'
   */
  rtb_Add_pw = (rtb_Minus_k_idx_0 * rtb_Optimized_Module_Angle) -
    (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S165>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Add_pw, rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S165>/Switch' incorporates:
   *  Constant: '<S165>/Constant'
   *  Constant: '<S165>/Constant1'
   *  Constant: '<S166>/Constant'
   *  Product: '<S165>/Divide'
   *  Product: '<S165>/Divide1'
   *  RelationalOperator: '<S166>/Compare'
   *  Switch: '<S165>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Hypot_g5;
    rtb_Optimized_Module_Angle = rtb_Add_pw / rtb_Hypot_g5;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S165>/Switch' */

  /* Switch: '<S154>/Speed_Switch' incorporates:
   *  Abs: '<S154>/Abs'
   *  Constant: '<S162>/Constant'
   *  RelationalOperator: '<S162>/Compare'
   *  Switch: '<S154>/Angle_Switch'
   *  Trigonometry: '<S164>/Atan1'
   *  Trigonometry: '<S165>/Atan1'
   *  UnaryMinus: '<S154>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_f1 = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S164>/Subtract1' incorporates:
     *  Product: '<S164>/Product2'
     *  Product: '<S164>/Product3'
     *  Trigonometry: '<S164>/Sin4'
     *  UnaryMinus: '<S154>/Unary Minus'
     */
    rtb_Add_pw = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Sin5) +
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5);

    /* Sum: '<S164>/Subtract' incorporates:
     *  Product: '<S164>/Product'
     *  Product: '<S164>/Product1'
     *  Trigonometry: '<S164>/Sin4'
     */
    rtb_Subtract_i = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5) -
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5);

    /* Math: '<S164>/Hypot' */
    rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract_i, rtb_Add_pw);

    /* Switch: '<S164>/Switch1' incorporates:
     *  Constant: '<S164>/Constant'
     *  Constant: '<S164>/Constant1'
     *  Constant: '<S167>/Constant'
     *  Product: '<S164>/Divide'
     *  Product: '<S164>/Divide1'
     *  RelationalOperator: '<S167>/Compare'
     *  Switch: '<S164>/Switch'
     */
    if (rtb_Hypot_g5 > 1.0E-6) {
      rtb_Subtract_i /= rtb_Hypot_g5;
      rtb_Add_pw /= rtb_Hypot_g5;
    } else {
      rtb_Subtract_i = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S164>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_pw, rtb_Subtract_i);
  } else {
    rtb_Add_f1 = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S157>/Product2' incorporates:
   *  Constant: '<S157>/Constant'
   *  Switch: '<S154>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_f1 * 1154.7574092481445;

  /* Signum: '<S152>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_f1 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_f1 = -1.0;
  } else {
    rtb_Add_f1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S152>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S155>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S156>/Sum'
   */
  rtb_uDLookupTable -= Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S147>/Product' incorporates:
   *  Abs: '<S152>/Abs'
   *  Abs: '<S155>/Abs'
   *  Constant: '<S158>/Constant'
   *  Constant: '<S168>/Constant3'
   *  Constant: '<S168>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S152>/OR'
   *  Lookup_n-D: '<S155>/1-D Lookup Table'
   *  Math: '<S168>/Math Function'
   *  RelationalOperator: '<S152>/Equal1'
   *  RelationalOperator: '<S158>/Compare'
   *  Signum: '<S152>/Sign'
   *  Signum: '<S152>/Sign1'
   *  Sum: '<S155>/Add'
   *  Sum: '<S168>/Add1'
   *  Sum: '<S168>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_f1 == rtb_Product_lb) ||
    (fabs(Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_uDLookupTable + 1.5707963267948966,
    3.141592653589793) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_h,
                    rtCP_uDLookupTable_tableData_j, 1U);

  /* Gain: '<S153>/Gain' */
  rtb_Subtract_i = Drive_Motor_Control_FF * rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S153>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S160>/Sum1' incorporates:
   *  Constant: '<S153>/Constant2'
   *  Product: '<S160>/Product'
   *  Sum: '<S160>/Sum'
   *  UnitDelay: '<S160>/Unit Delay1'
   */
  rtb_Add_pw = ((rtb_MatrixConcatenate_b_idx_0 -
                 Robot_Control_DW.UnitDelay1_DSTATE_f) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S153>/Product' incorporates:
   *  Constant: '<S153>/Constant3'
   */
  rtb_Hypot_g5 = rtb_Add_pw * Drive_Motor_Control_D;

  /* Sum: '<S159>/Diff' incorporates:
   *  UnitDelay: '<S159>/UD'
   *
   * Block description for '<S159>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S159>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_f1 = rtb_Hypot_g5 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S153>/Saturation' */
  if (rtb_Add_f1 > Drive_Motor_Control_D_UL) {
    rtb_Add_f1 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_f1 < Drive_Motor_Control_D_LL) {
    rtb_Add_f1 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S153>/Add' incorporates:
   *  Gain: '<S153>/Gain1'
   *  Saturate: '<S153>/Saturation'
   */
  rtb_Add_f1 += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Subtract_i;

  /* Saturate: '<S153>/Saturation2' */
  if (rtb_Add_f1 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_f1 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = rtb_Add_f1;
  }

  /* End of Saturate: '<S153>/Saturation2' */

  /* Sum: '<S169>/Add1' incorporates:
   *  Constant: '<S169>/Constant3'
   *  Constant: '<S169>/Constant4'
   *  Math: '<S169>/Math Function'
   *  Sum: '<S169>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_uDLookupTable +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S171>/Sum1' incorporates:
   *  Constant: '<S156>/Constant2'
   *  Product: '<S171>/Product'
   *  Sum: '<S171>/Sum'
   *  UnitDelay: '<S171>/Unit Delay1'
   */
  rtb_Subtract_i = ((rtb_MatrixConcatenate_b_idx_0 -
                     Robot_Control_DW.UnitDelay1_DSTATE_b) *
                    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S156>/Product' incorporates:
   *  Constant: '<S156>/Constant3'
   */
  rtb_Product_f = rtb_Subtract_i * Steering_Motor_Control_D;

  /* Sum: '<S170>/Diff' incorporates:
   *  UnitDelay: '<S170>/UD'
   *
   * Block description for '<S170>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S170>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_f1 = rtb_Product_f - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S156>/Saturation' */
  if (rtb_Add_f1 > Steering_Motor_Control_D_UL) {
    rtb_Add_f1 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_f1 < Steering_Motor_Control_D_LL) {
    rtb_Add_f1 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S156>/Add' incorporates:
   *  Gain: '<S156>/Gain1'
   *  Saturate: '<S156>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)
    + rtb_Add_f1;

  /* Sum: '<S156>/Subtract' incorporates:
   *  Constant: '<S156>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S156>/Sum2' incorporates:
   *  Gain: '<S156>/Gain2'
   *  UnitDelay: '<S156>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S172>/Switch2' incorporates:
   *  Constant: '<S156>/Constant'
   *  RelationalOperator: '<S172>/LowerRelop1'
   *  Sum: '<S156>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S172>/Switch' incorporates:
     *  Constant: '<S156>/Constant1'
     *  RelationalOperator: '<S172>/UpperRelop'
     *  Sum: '<S156>/Subtract1'
     */
    if (rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S172>/Switch' */
  }

  /* End of Switch: '<S172>/Switch2' */

  /* Saturate: '<S156>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_la = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S156>/Saturation1' */

  /* Sum: '<S156>/Add1' */
  rtb_Add_f1 = rtb_Minus_k_idx_1 + rtb_Subtract1_la;

  /* Saturate: '<S156>/Saturation2' */
  if (rtb_Add_f1 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_f1 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = rtb_Add_f1;
  }

  /* End of Saturate: '<S156>/Saturation2' */

  /* Product: '<S274>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_Switch2;

  /* Switch: '<S284>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S284>/Switch' incorporates:
     *  Fcn: '<S285>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLoo_mu[1], rtb_TmpSignalConversionAtLoo_mu[0]);
  }

  /* End of Switch: '<S284>/Switch' */

  /* Trigonometry: '<S186>/Cos4' incorporates:
   *  Switch: '<S175>/Angle_Switch'
   *  Trigonometry: '<S185>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S186>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S184>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S186>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S186>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S184>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S186>/Subtract1' incorporates:
   *  Product: '<S186>/Product2'
   *  Product: '<S186>/Product3'
   *  Trigonometry: '<S186>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) +
    (rtb_Minus_k_idx_1 * rtb_Optimized_Module_Angle);

  /* Sum: '<S186>/Subtract' incorporates:
   *  Product: '<S186>/Product'
   *  Product: '<S186>/Product1'
   *  Trigonometry: '<S186>/Cos4'
   */
  rtb_Optimized_Module_Angle = (rtb_Minus_k_idx_0 * rtb_Optimized_Module_Angle)
    - (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S186>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Optimized_Module_Angle,
    rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S186>/Switch' incorporates:
   *  Constant: '<S186>/Constant'
   *  Constant: '<S186>/Constant1'
   *  Constant: '<S187>/Constant'
   *  Product: '<S186>/Divide'
   *  Product: '<S186>/Divide1'
   *  RelationalOperator: '<S187>/Compare'
   *  Switch: '<S186>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Hypot_b;
    rtb_Optimized_Module_Angle /= rtb_Hypot_b;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S186>/Switch' */

  /* Switch: '<S175>/Speed_Switch' incorporates:
   *  Abs: '<S175>/Abs'
   *  Constant: '<S183>/Constant'
   *  RelationalOperator: '<S183>/Compare'
   *  Switch: '<S175>/Angle_Switch'
   *  Trigonometry: '<S185>/Atan1'
   *  Trigonometry: '<S186>/Atan1'
   *  UnaryMinus: '<S175>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
                         rtb_Optimized_Module_Angle)) > 1.5707963267948966) {
    rtb_Add_f1 = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S185>/Subtract1' incorporates:
     *  Product: '<S185>/Product2'
     *  Product: '<S185>/Product3'
     *  Trigonometry: '<S185>/Sin4'
     *  UnaryMinus: '<S175>/Unary Minus'
     */
    rtb_Optimized_Module_Angle = (rtb_Minus_k_idx_0 *
      Robot_Control_ConstB.Sin5_m) + (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S185>/Subtract' incorporates:
     *  Product: '<S185>/Product'
     *  Product: '<S185>/Product1'
     *  Trigonometry: '<S185>/Sin4'
     */
    rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S185>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_Minus_k_idx_0,
      rtb_Optimized_Module_Angle);

    /* Switch: '<S185>/Switch1' incorporates:
     *  Constant: '<S185>/Constant'
     *  Constant: '<S185>/Constant1'
     *  Constant: '<S188>/Constant'
     *  Product: '<S185>/Divide'
     *  Product: '<S185>/Divide1'
     *  RelationalOperator: '<S188>/Compare'
     *  Switch: '<S185>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_Minus_k_idx_0 /= rtb_Minus_k_idx_1;
      rtb_Optimized_Module_Angle /= rtb_Minus_k_idx_1;
    } else {
      rtb_Minus_k_idx_0 = 1.0;
      rtb_Optimized_Module_Angle = 0.0;
    }

    /* End of Switch: '<S185>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Optimized_Module_Angle,
      rtb_Minus_k_idx_0);
  } else {
    rtb_Add_f1 = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S178>/Product2' incorporates:
   *  Constant: '<S178>/Constant'
   *  Switch: '<S175>/Speed_Switch'
   */
  rtb_MatrixConcatenate_b_idx_0 = rtb_Add_f1 * 1154.7574092481445;

  /* Signum: '<S173>/Sign' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_f1 = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_f1 = -1.0;
  } else {
    rtb_Add_f1 = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Signum: '<S173>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S176>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S177>/Sum'
   */
  rtb_uDLookupTable -= Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S148>/Product' incorporates:
   *  Abs: '<S173>/Abs'
   *  Abs: '<S176>/Abs'
   *  Constant: '<S179>/Constant'
   *  Constant: '<S189>/Constant3'
   *  Constant: '<S189>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S173>/OR'
   *  Lookup_n-D: '<S176>/1-D Lookup Table'
   *  Math: '<S189>/Math Function'
   *  RelationalOperator: '<S173>/Equal1'
   *  RelationalOperator: '<S179>/Compare'
   *  Signum: '<S173>/Sign'
   *  Signum: '<S173>/Sign1'
   *  Sum: '<S176>/Add'
   *  Sum: '<S189>/Add1'
   *  Sum: '<S189>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = (((real_T)((rtb_Add_f1 == rtb_Product_lb) ||
    (fabs(Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
     Drive_Motor_Control_Sign_Change_Deadband))) * rtb_MatrixConcatenate_b_idx_0)
    * look1_binlcpw(fabs(rt_modd_snf(rtb_uDLookupTable + 1.5707963267948966,
    3.141592653589793) - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_p,
                    rtCP_uDLookupTable_tableData_gs, 1U);

  /* Gain: '<S174>/Gain' */
  rtb_Optimized_Module_Angle = Drive_Motor_Control_FF *
    rtb_MatrixConcatenate_b_idx_0;

  /* Sum: '<S174>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S181>/Sum1' incorporates:
   *  Constant: '<S174>/Constant2'
   *  Product: '<S181>/Product'
   *  Sum: '<S181>/Sum'
   *  UnitDelay: '<S181>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_MatrixConcatenate_b_idx_0 -
                        Robot_Control_DW.UnitDelay1_DSTATE_e) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S174>/Product' incorporates:
   *  Constant: '<S174>/Constant3'
   */
  rtb_Minus_k_idx_0 = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S180>/Diff' incorporates:
   *  UnitDelay: '<S180>/UD'
   *
   * Block description for '<S180>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S180>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_f1 = rtb_Minus_k_idx_0 - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S174>/Saturation' */
  if (rtb_Add_f1 > Drive_Motor_Control_D_UL) {
    rtb_Add_f1 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_f1 < Drive_Motor_Control_D_LL) {
    rtb_Add_f1 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S174>/Add' incorporates:
   *  Gain: '<S174>/Gain1'
   *  Saturate: '<S174>/Saturation'
   */
  rtb_Add_f1 += (Drive_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Optimized_Module_Angle;

  /* Saturate: '<S174>/Saturation2' */
  if (rtb_Add_f1 > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_f1 < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = rtb_Add_f1;
  }

  /* End of Saturate: '<S174>/Saturation2' */

  /* Sum: '<S190>/Add1' incorporates:
   *  Constant: '<S190>/Constant3'
   *  Constant: '<S190>/Constant4'
   *  Math: '<S190>/Math Function'
   *  Sum: '<S190>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf(rtb_uDLookupTable +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Sum: '<S192>/Sum1' incorporates:
   *  Constant: '<S177>/Constant2'
   *  Product: '<S192>/Product'
   *  Sum: '<S192>/Sum'
   *  UnitDelay: '<S192>/Unit Delay1'
   */
  rtb_Hypot_b = ((rtb_MatrixConcatenate_b_idx_0 -
                  Robot_Control_DW.UnitDelay1_DSTATE_n) *
                 Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S177>/Product' incorporates:
   *  Constant: '<S177>/Constant3'
   */
  rtb_Product_k5 = rtb_Hypot_b * Steering_Motor_Control_D;

  /* Sum: '<S191>/Diff' incorporates:
   *  UnitDelay: '<S191>/UD'
   *
   * Block description for '<S191>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S191>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_f1 = rtb_Product_k5 - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S177>/Saturation' */
  if (rtb_Add_f1 > Steering_Motor_Control_D_UL) {
    rtb_Add_f1 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_f1 < Steering_Motor_Control_D_LL) {
    rtb_Add_f1 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S177>/Add' incorporates:
   *  Gain: '<S177>/Gain1'
   *  Saturate: '<S177>/Saturation'
   */
  rtb_uDLookupTable = (Steering_Motor_Control_P * rtb_MatrixConcatenate_b_idx_0)
    + rtb_Add_f1;

  /* Sum: '<S177>/Subtract' incorporates:
   *  Constant: '<S177>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_uDLookupTable;

  /* Sum: '<S177>/Sum2' incorporates:
   *  Gain: '<S177>/Gain2'
   *  UnitDelay: '<S177>/Unit Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = (Steering_Motor_Control_I *
    rtb_MatrixConcatenate_b_idx_0) + Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S193>/Switch2' incorporates:
   *  Constant: '<S177>/Constant'
   *  RelationalOperator: '<S193>/LowerRelop1'
   *  Sum: '<S177>/Subtract'
   */
  if (!(rtb_MatrixConcatenate_b_idx_0 > (1.0 - rtb_uDLookupTable))) {
    /* Sum: '<S177>/Subtract1' incorporates:
     *  Constant: '<S177>/Constant1'
     */
    rtb_Optimized_Module_Angle = -1.0 - rtb_uDLookupTable;

    /* Switch: '<S193>/Switch' incorporates:
     *  Constant: '<S177>/Constant1'
     *  RelationalOperator: '<S193>/UpperRelop'
     *  Sum: '<S177>/Subtract1'
     */
    if (!(rtb_MatrixConcatenate_b_idx_0 < (-1.0 - rtb_uDLookupTable))) {
      rtb_Optimized_Module_Angle = rtb_MatrixConcatenate_b_idx_0;
    }

    /* End of Switch: '<S193>/Switch' */
  }

  /* End of Switch: '<S193>/Switch2' */

  /* Saturate: '<S177>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Integral_k = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Integral_k = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_k = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S177>/Saturation1' */

  /* Sum: '<S177>/Add1' */
  rtb_Add_f1 = rtb_uDLookupTable + rtb_Integral_k;

  /* Saturate: '<S177>/Saturation2' */
  if (rtb_Add_f1 > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_f1 < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = rtb_Add_f1;
  }

  /* End of Saturate: '<S177>/Saturation2' */

  /* Product: '<S274>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_Switch2;

  /* Switch: '<S289>/Switch' */
  if (!rtb_Compare_bd) {
    /* Switch: '<S289>/Switch' incorporates:
     *  Fcn: '<S290>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S289>/Switch' */

  /* Trigonometry: '<S207>/Cos4' incorporates:
   *  Switch: '<S196>/Angle_Switch'
   *  Trigonometry: '<S206>/Cos4'
   */
  rtb_Product_lb = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S207>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S205>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S207>/Sin4' */
  rtb_uDLookupTable = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S207>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S205>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S207>/Subtract1' incorporates:
   *  Product: '<S207>/Product2'
   *  Product: '<S207>/Product3'
   *  Trigonometry: '<S207>/Cos4'
   */
  rtb_Switch2 = (rtb_Product_lb * rtb_Optimized_Module_Angle) +
    (rtb_uDLookupTable * rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S207>/Subtract' incorporates:
   *  Product: '<S207>/Product'
   *  Product: '<S207>/Product1'
   *  Trigonometry: '<S207>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Product_lb *
    rtb_MatrixConcatenate_b_idx_0) - (rtb_uDLookupTable *
    rtb_Optimized_Module_Angle);

  /* Math: '<S207>/Hypot' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0,
    rtb_Switch2);

  /* Switch: '<S207>/Switch' incorporates:
   *  Constant: '<S207>/Constant'
   *  Constant: '<S207>/Constant1'
   *  Constant: '<S208>/Constant'
   *  Product: '<S207>/Divide'
   *  Product: '<S207>/Divide1'
   *  RelationalOperator: '<S208>/Compare'
   *  Switch: '<S207>/Switch1'
   */
  if (rtb_Optimized_Module_Angle > 1.0E-6) {
    rtb_Switch2 /= rtb_Optimized_Module_Angle;
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle;
  } else {
    rtb_Switch2 = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
  }

  /* End of Switch: '<S207>/Switch' */

  /* Switch: '<S196>/Speed_Switch' incorporates:
   *  Abs: '<S196>/Abs'
   *  Constant: '<S204>/Constant'
   *  RelationalOperator: '<S204>/Compare'
   *  Switch: '<S196>/Angle_Switch'
   *  Trigonometry: '<S206>/Atan1'
   *  Trigonometry: '<S207>/Atan1'
   *  UnaryMinus: '<S196>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    rtb_Switch2 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S206>/Subtract1' incorporates:
     *  Product: '<S206>/Product2'
     *  Product: '<S206>/Product3'
     *  Trigonometry: '<S206>/Sin4'
     *  UnaryMinus: '<S196>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Product_lb *
      Robot_Control_ConstB.Sin5_e) + (rtb_uDLookupTable *
      Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S206>/Subtract' incorporates:
     *  Product: '<S206>/Product'
     *  Product: '<S206>/Product1'
     *  Trigonometry: '<S206>/Sin4'
     */
    rtb_uDLookupTable = (rtb_Product_lb * Robot_Control_ConstB.Cos5_i) -
      (rtb_uDLookupTable * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S206>/Hypot' */
    rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_uDLookupTable,
      rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S206>/Switch1' incorporates:
     *  Constant: '<S206>/Constant'
     *  Constant: '<S206>/Constant1'
     *  Constant: '<S209>/Constant'
     *  Product: '<S206>/Divide'
     *  Product: '<S206>/Divide1'
     *  RelationalOperator: '<S209>/Compare'
     *  Switch: '<S206>/Switch'
     */
    if (rtb_Optimized_Module_Angle > 1.0E-6) {
      rtb_uDLookupTable /= rtb_Optimized_Module_Angle;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Optimized_Module_Angle;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S206>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_uDLookupTable);
  } else {
    rtb_Switch2 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* End of Switch: '<S196>/Speed_Switch' */

  /* Product: '<S199>/Product2' incorporates:
   *  Constant: '<S199>/Constant'
   */
  rtb_Switch2 *= 1154.7574092481445;

  /* Signum: '<S194>/Sign' */
  if (rtIsNaN(rtb_Switch2)) {
    rtb_Add_f1 = (rtNaN);
  } else if (rtb_Switch2 < 0.0) {
    rtb_Add_f1 = -1.0;
  } else {
    rtb_Add_f1 = (rtb_Switch2 > 0.0);
  }

  /* Signum: '<S194>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S197>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S198>/Sum'
   */
  rtb_Optimized_Module_Angle -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S149>/Product' incorporates:
   *  Abs: '<S194>/Abs'
   *  Abs: '<S197>/Abs'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S210>/Constant3'
   *  Constant: '<S210>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S194>/OR'
   *  Lookup_n-D: '<S197>/1-D Lookup Table'
   *  Math: '<S210>/Math Function'
   *  RelationalOperator: '<S194>/Equal1'
   *  RelationalOperator: '<S200>/Compare'
   *  Signum: '<S194>/Sign'
   *  Signum: '<S194>/Sign1'
   *  Sum: '<S197>/Add'
   *  Sum: '<S210>/Add1'
   *  Sum: '<S210>/Add2'
   */
  rtb_Switch2 = (((real_T)((rtb_Add_f1 == rtb_Product_lb) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle + 1.5707963267948966,
                      3.141592653589793) - 1.5707963267948966),
     rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h, 1U);

  /* Gain: '<S195>/Gain' */
  rtb_MatrixConcatenate_b_idx_0 = Drive_Motor_Control_FF * rtb_Switch2;

  /* Sum: '<S195>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Switch2 -= Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S202>/Sum1' incorporates:
   *  Constant: '<S195>/Constant2'
   *  Product: '<S202>/Product'
   *  Sum: '<S202>/Sum'
   *  UnitDelay: '<S202>/Unit Delay1'
   */
  rtb_uDLookupTable = ((rtb_Switch2 - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S195>/Product' incorporates:
   *  Constant: '<S195>/Constant3'
   */
  rtb_Product_lb = rtb_uDLookupTable * Drive_Motor_Control_D;

  /* Sum: '<S201>/Diff' incorporates:
   *  UnitDelay: '<S201>/UD'
   *
   * Block description for '<S201>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S201>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_f1 = rtb_Product_lb - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S195>/Saturation' */
  if (rtb_Add_f1 > Drive_Motor_Control_D_UL) {
    rtb_Add_f1 = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_f1 < Drive_Motor_Control_D_LL) {
    rtb_Add_f1 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S195>/Add' incorporates:
   *  Gain: '<S195>/Gain1'
   *  Saturate: '<S195>/Saturation'
   */
  rtb_Add_f1 += (Drive_Motor_Control_P * rtb_Switch2) +
    rtb_MatrixConcatenate_b_idx_0;

  /* Saturate: '<S195>/Saturation2' */
  if (rtb_Add_f1 > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_f1 < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = rtb_Add_f1;
  }

  /* End of Saturate: '<S195>/Saturation2' */

  /* Sum: '<S211>/Add1' incorporates:
   *  Constant: '<S211>/Constant3'
   *  Constant: '<S211>/Constant4'
   *  Math: '<S211>/Math Function'
   *  Sum: '<S211>/Add2'
   */
  rtb_Switch2 = rt_modd_snf(rtb_Optimized_Module_Angle + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Sum: '<S213>/Sum1' incorporates:
   *  Constant: '<S198>/Constant2'
   *  Product: '<S213>/Product'
   *  Sum: '<S213>/Sum'
   *  UnitDelay: '<S213>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Switch2 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S198>/Product' incorporates:
   *  Constant: '<S198>/Constant3'
   */
  rtb_Product_kx = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S212>/Diff' incorporates:
   *  UnitDelay: '<S212>/UD'
   *
   * Block description for '<S212>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S212>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_f1 = rtb_Product_kx - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S198>/Saturation' */
  if (rtb_Add_f1 > Steering_Motor_Control_D_UL) {
    rtb_Add_f1 = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_f1 < Steering_Motor_Control_D_LL) {
    rtb_Add_f1 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S198>/Add' incorporates:
   *  Gain: '<S198>/Gain1'
   *  Saturate: '<S198>/Saturation'
   */
  rtb_Add_f1 += Steering_Motor_Control_P * rtb_Switch2;

  /* Sum: '<S198>/Subtract' incorporates:
   *  Constant: '<S198>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_f1;

  /* Sum: '<S198>/Sum2' incorporates:
   *  Gain: '<S198>/Gain2'
   *  UnitDelay: '<S198>/Unit Delay'
   */
  rtb_Switch2 = (Steering_Motor_Control_I * rtb_Switch2) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S214>/Switch2' incorporates:
   *  Constant: '<S198>/Constant'
   *  RelationalOperator: '<S214>/LowerRelop1'
   *  Sum: '<S198>/Subtract'
   */
  if (!(rtb_Switch2 > (1.0 - rtb_Add_f1))) {
    /* Sum: '<S198>/Subtract1' incorporates:
     *  Constant: '<S198>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_f1;

    /* Switch: '<S214>/Switch' incorporates:
     *  Constant: '<S198>/Constant1'
     *  RelationalOperator: '<S214>/UpperRelop'
     *  Sum: '<S198>/Subtract1'
     */
    if (!(rtb_Switch2 < (-1.0 - rtb_Add_f1))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2;
    }

    /* End of Switch: '<S214>/Switch' */
  }

  /* End of Switch: '<S214>/Switch2' */

  /* Saturate: '<S198>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Switch2 = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Switch2 = Steering_Motor_Control_I_LL;
  } else {
    rtb_Switch2 = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S198>/Saturation1' */

  /* Sum: '<S198>/Add1' */
  rtb_Add_f1 += rtb_Switch2;

  /* Saturate: '<S198>/Saturation2' */
  if (rtb_Add_f1 > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_f1 < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = rtb_Add_f1;
  }

  /* End of Saturate: '<S198>/Saturation2' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant2'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  Robot_Control_B.loop_counter_robot_control++;

  /* SignalConversion: '<S4>/Signal Copy4' incorporates:
   *  Inport: '<Root>/Xbox_Driver_Stick_Right_X'
   */
  Robot_Control_B.Steer_Joystick_X = Robot_Control_U.Xbox_Driver_Stick_Right_X;

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Add_f1 = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(rtb_Add_f1)) || (rtIsInf(rtb_Add_f1))) {
    rtb_Add_f1 = 0.0;
  } else {
    rtb_Add_f1 = fmod(rtb_Add_f1, 256.0);
  }

  rtb_GameState = (uint8_T)((rtb_Add_f1 < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-rtb_Add_f1)))))) : ((int32_T)((uint8_T)rtb_Add_f1)));

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* Chart: '<S8>/Chart' */
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

  /* End of Chart: '<S8>/Chart' */

  /* Outport: '<Root>/Wrist_Motor_Left_DC' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Wrist_Motor_Left_Revs'
   */
  Robot_Control_Y.Wrist_Motor_Left_DC = 2.0 *
    Robot_Control_U.Wrist_Motor_Left_Revs;

  /* Outport: '<Root>/Wrist_Motor_Right_DC' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Inport: '<Root>/Wrist_Motor_Right_Revs'
   */
  Robot_Control_Y.Wrist_Motor_Right_DC = 2.0 *
    Robot_Control_U.Wrist_Motor_Right_Revs;

  /* Update for UnitDelay: '<S22>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Gamepad_B3_X;

  /* Update for UnitDelay: '<S23>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Gamepad_B4_Y;

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Gamepad_B2_B;

  /* Update for UnitDelay: '<S5>/Unit Delay1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Robot_Control_DW.UnitDelay1_DSTATE_nl = false;

  /* Update for UnitDelay: '<S5>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = Robot_Control_B.Spline_Index;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ll =
    Robot_Control_B.Robot_Reached_Destination;

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

  /* Update for Delay: '<S78>/Delay' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S77>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S25>/A'
   *  Delay: '<S78>/Delay'
   */
  rtb_MatrixConcatenate_b_idx_0 = Robot_Control_DW.Delay_DSTATE[0];
  tmp = 0.0 * Robot_Control_DW.Delay_DSTATE[0];
  rtb_Add_f1 = Robot_Control_DW.Delay_DSTATE[1];

  /* Update for Delay: '<S78>/Delay' incorporates:
   *  Constant: '<S25>/A'
   *  Constant: '<S25>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S77>/A[k]*xhat[k|k-1]'
   *  Product: '<S77>/B[k]*u[k]'
   *  Product: '<S79>/Product3'
   *  Sum: '<S77>/Add'
   */
  Robot_Control_DW.Delay_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + ((0.0 * rtb_Add_f1) +
    rtb_MatrixConcatenate_b_idx_0)) + Robot_Control_B.Product3[0];
  Robot_Control_DW.Delay_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + (tmp + rtb_Add_f1)) +
    Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S247>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S247>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S270>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S269>/UD'
   *
   * Block description for '<S269>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Saturation_h;

  /* Update for UnitDelay: '<S267>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Subtract_e;

  /* Update for UnitDelay: '<S249>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S264>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S264>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S264>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S248>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Switch1_c;

  /* Update for UnitDelay: '<S257>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S257>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S257>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Switch1_c;

  /* Update for UnitDelay: '<S223>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_UnitDelay3;

  /* Update for UnitDelay: '<S222>/UD'
   *
   * Block description for '<S222>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Subtract;

  /* Update for UnitDelay: '<S234>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Hypot;

  /* Update for UnitDelay: '<S233>/UD'
   *
   * Block description for '<S233>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S219>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S160>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Add_pw;

  /* Update for UnitDelay: '<S159>/UD'
   *
   * Block description for '<S159>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S171>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Subtract_i;

  /* Update for UnitDelay: '<S170>/UD'
   *
   * Block description for '<S170>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Product_f;

  /* Update for UnitDelay: '<S156>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S181>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S180>/UD'
   *
   * Block description for '<S180>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S192>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_b;

  /* Update for UnitDelay: '<S191>/UD'
   *
   * Block description for '<S191>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_k5;

  /* Update for UnitDelay: '<S177>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Integral_k;

  /* Update for UnitDelay: '<S202>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S201>/UD'
   *
   * Block description for '<S201>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_Product_lb;

  /* Update for UnitDelay: '<S213>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S212>/UD'
   *
   * Block description for '<S212>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_kx;

  /* Update for UnitDelay: '<S198>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_Switch2;
}

/* Model initialize function */
void Robot_Control_initialize(void)
{
  /* Start for SwitchCase: '<S1>/Switch Case' */
  Robot_Control_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S9>/If' */
  Robot_Control_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S78>/Delay' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S247>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S264>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S257>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S320>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S9>/Spline Path Following Enabled' */
  /* Start for If: '<S92>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S88>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S92>/Robot_Index_Is_Valid' */
  /* Start for If: '<S95>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S95>/Circle_Check_Valid' */
  /* Start for If: '<S97>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S95>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S92>/Robot_Index_Is_Valid' */
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
