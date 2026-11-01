/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 7.4
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Sat Oct 31 16:19:21 2026
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

/* Named constants for Chart: '<S9>/Chart' */
#define Robot_Contro_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Robot_Control_IN_Disabled      ((uint8_T)1U)
#define Robot_Control_IN_Not_Disabled  ((uint8_T)2U)

/* Named constants for Chart: '<S251>/Add dither' */
#define Robot_Control_IN_Dither        ((uint8_T)1U)
#define Robot_Control_IN_No_Dither     ((uint8_T)2U)

/* Named constants for Chart: '<S17>/Chart' */
#define Robot_Control_IN_End_Action    ((uint8_T)1U)
#define Robot_Control_IN_Follow_Path   ((uint8_T)2U)
#define Robot_Control_IN_Start_Action  ((uint8_T)3U)

/* Exported block parameters */
real_T Auto_Path_Chooser = 3.0;        /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S18>/Constant17'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.24;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S318>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 5.0; /* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S314>/Constant'
                                        *   '<S314>/Saturation'
                                        */
real_T Boost_Trigger_Increasing_Limit = 3.0;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S318>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 2.0;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S314>/Constant1'
                                        */
real_T Desired_Pitch_Angle_LL = -45.0; /* Variable: Desired_Pitch_Angle_LL
                                        * Referenced by: '<S337>/Saturation'
                                        */
real_T Desired_Pitch_Angle_UL = 45.0;  /* Variable: Desired_Pitch_Angle_UL
                                        * Referenced by: '<S337>/Saturation'
                                        */
real_T Desired_Roll_Angle_LL = -180.0; /* Variable: Desired_Roll_Angle_LL
                                        * Referenced by: '<S336>/Saturation'
                                        */
real_T Desired_Roll_Angle_UL = 180.0;  /* Variable: Desired_Roll_Angle_UL
                                        * Referenced by: '<S336>/Saturation'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S154>/Constant3'
                                        *   '<S175>/Constant3'
                                        *   '<S196>/Constant3'
                                        *   '<S217>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S154>/Constant2'
                                   *   '<S175>/Constant2'
                                   *   '<S196>/Constant2'
                                   *   '<S217>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S154>/Saturation'
                                        *   '<S175>/Saturation'
                                        *   '<S196>/Saturation'
                                        *   '<S217>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S154>/Saturation'
                                        *   '<S175>/Saturation'
                                        *   '<S196>/Saturation'
                                        *   '<S217>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00016129;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S154>/Gain'
                                            *   '<S175>/Gain'
                                            *   '<S196>/Gain'
                                            *   '<S217>/Gain'
                                            */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S154>/Gain1'
                                        *   '<S175>/Gain1'
                                        *   '<S196>/Gain1'
                                        *   '<S217>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 7000.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S159>/Constant'
                            *   '<S180>/Constant'
                            *   '<S201>/Constant'
                            *   '<S222>/Constant'
                            */
real_T Field_Translation_Control_Gain = 10.0;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S304>/Gain2'
                                      */
real_T Field_Translation_Speed_Max = 5.0;/* Variable: Field_Translation_Speed_Max
                                          * Referenced by: '<S304>/Constant5'
                                          */
real_T Gamepad_Pitch_Gain = 1.0;       /* Variable: Gamepad_Pitch_Gain
                                        * Referenced by: '<S337>/Gain'
                                        */
real_T Gamepad_Roll_Gain = 1.0;        /* Variable: Gamepad_Roll_Gain
                                        * Referenced by: '<S336>/Gain'
                                        */
real_T KF_Enable = 1.0;                /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S7>/Constant1'
                                        *   '<S7>/Constant2'
                                        */
real_T Kp_motor_angle = 0.0001;        /* Variable: Kp_motor_angle
                                        * Referenced by:
                                        *   '<S335>/Gain'
                                        *   '<S335>/Gain1'
                                        */
real_T R_motor_gearbox = 49.0;         /* Variable: R_motor_gearbox
                                        * Referenced by:
                                        *   '<S335>/Constant'
                                        *   '<S335>/Constant2'
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
                          * Referenced by: '<S143>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S143>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S90>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S103>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S143>/Constant3'
                                     */
real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S250>/Constant5'
                    */
real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S250>/Constant6'
                    */
real_T Steering_Absolute_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S250>/Constant9'
                          */
real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor = 0.1;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S250>/Constant10'
                    */
real_T Steering_Absolute_Cmd_Rate_Limit_Dec = -1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S250>/Constant1'
                                */
real_T Steering_Absolute_Cmd_Rate_Limit_Inc = 1.0;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S250>/Constant3'
                                */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S268>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S268>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S268>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S268>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.01;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S267>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S268>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S268>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S268>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 2.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S268>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -2.5;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S268>/Constant1'
                                   *   '<S268>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 2.5;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S268>/Constant'
                                   *   '<S268>/Saturation2'
                                   */
real_T Steering_Heading_Dither_Gain = 2.0;/* Variable: Steering_Heading_Dither_Gain
                                           * Referenced by: '<S251>/Add dither'
                                           */
real_T Steering_Heading_Dither_Period = 0.1;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S251>/Add dither'
                                      */
real_T Steering_Heading_Dither_Thresh_Off = 1.0;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S251>/Add dither'
                                  */
real_T Steering_Heading_Dither_Thresh_On = 5.0;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S251>/Add dither'
                                   */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S157>/Constant3'
                                        *   '<S178>/Constant3'
                                        *   '<S199>/Constant3'
                                        *   '<S220>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S157>/Constant2'
                                *   '<S178>/Constant2'
                                *   '<S199>/Constant2'
                                *   '<S220>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S157>/Saturation'
                                           *   '<S178>/Saturation'
                                           *   '<S199>/Saturation'
                                           *   '<S220>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S157>/Saturation'
                                          *   '<S178>/Saturation'
                                          *   '<S199>/Saturation'
                                          *   '<S220>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S157>/Gain2'
                                         *   '<S178>/Gain2'
                                         *   '<S199>/Gain2'
                                         *   '<S220>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S157>/Saturation1'
                                             *   '<S178>/Saturation1'
                                             *   '<S199>/Saturation1'
                                             *   '<S220>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S157>/Saturation1'
                                            *   '<S178>/Saturation1'
                                            *   '<S199>/Saturation1'
                                            *   '<S220>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S157>/Gain1'
                                        *   '<S178>/Gain1'
                                        *   '<S199>/Gain1'
                                        *   '<S220>/Gain1'
                                        */
real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh = 0.2;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S249>/Constant5'
                    */
real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh = 0.01;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S249>/Constant6'
                    */
real_T Steering_Relative_Cmd_NonZero_Error_Thresh = 0.2;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S249>/Constant9'
                          */
real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor = 1.0;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S249>/Constant10'
                    */
real_T Steering_Relative_Cmd_Rate_Limit_Dec = -10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S249>/Constant1'
                                */
real_T Steering_Relative_Cmd_Rate_Limit_Inc = 10.0;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S249>/Constant3'
                                */
real_T Steering_Relative_Gain = 3.5;   /* Variable: Steering_Relative_Gain
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
                        * Referenced by: '<S237>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S237>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S237>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S237>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S237>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 4.0;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S237>/Constant3'
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
                                         * Referenced by: '<S14>/Constant6'
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
                                        * Referenced by: '<S14>/Constant4'
                                        */
real_T Vision_Object_Y_Offset = 0.0;   /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S14>/Constant8'
                                        */
real_T Vision_Tag_Angle_Offset = 0.0;  /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S14>/Constant5'
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
                                        * Referenced by: '<S14>/Constant3'
                                        */
real_T Vision_Tag_Y_Offset = 0.0;      /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S14>/Constant7'
                                        */
uint8_T TEST_Pipeline = 0U;            /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S13>/Constant22'
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
  real_T rtb_Switch2_p;
  real_T rtb_Switch5_o;
  real_T rtb_UnitDelay3;
  real_T rtb_uDLookupTable;
  real_T tmp;
  real_T tmp_0;
  real_T u0;
  int32_T i;
  int32_T i_0;
  int32_T rtb_Num_Segments;
  int32_T s115_iter;
  uint16_T s140_iter;
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

  /* RelationalOperator: '<S23>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Enable_Wheels = (Robot_Control_U.Gamepad_B3_X >
    Robot_Control_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Reset_Wheel_Offsets = (Robot_Control_U.Gamepad_B4_Y >
    Robot_Control_DW.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S25>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *  UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_B.Button_Disable_Wheels = (Robot_Control_U.Gamepad_B2_B >
    Robot_Control_DW.DelayInput1_DSTATE_n);

  /* SignalConversion: '<S5>/Signal Copy1' incorporates:
   *  Inport: '<Root>/Xbox_Driver_Stick_Left_X'
   */
  Robot_Control_B.Drive_Joystick_X = Robot_Control_U.Xbox_Driver_Stick_Left_X;

  /* SignalConversion: '<S5>/Signal Copy2' incorporates:
   *  Inport: '<Root>/Xbox_Driver_Stick_Left_Y'
   */
  Robot_Control_B.Drive_Joystick_Y = Robot_Control_U.Xbox_Driver_Stick_Left_Y;

  /* SignalConversion: '<S5>/Signal Copy5' incorporates:
   *  Inport: '<Root>/Xbox_Driver_Stick_Right_Y'
   */
  Robot_Control_B.Steer_Joystick_Y = Robot_Control_U.Xbox_Driver_Stick_Right_Y;

  /* Logic: '<S21>/Logical Operator7' incorporates:
   *  Inport: '<Root>/Xbox_Driver_ButtonA'
   *  Inport: '<Root>/Xbox_Driver_ButtonY'
   */
  rtb_Compare_bd = ((Robot_Control_U.Xbox_Driver_ButtonY) ||
                    (Robot_Control_U.Xbox_Driver_ButtonA));

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant3'
   *  Constant: '<S22>/Constant4'
   *  Inport: '<Root>/Gyro_Angle_rad'
   *  Math: '<S22>/Math Function'
   *  Sum: '<S22>/Add2'
   */
  rtb_Subtract_e = rt_modd_snf(Robot_Control_U.Gyro_Angle_rad +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* RelationalOperator: '<S21>/GreaterThan' incorporates:
   *  Abs: '<S21>/Abs'
   *  Constant: '<S21>/Constant2'
   */
  rtb_Compare_ky = (fabs(rtb_Subtract_e) > 1.5707963267948966);

  /* Logic: '<S21>/Logical Operator1' */
  rtb_LogicalOperator1 = (rtb_Compare_bd && rtb_Compare_ky);

  /* Logic: '<S21>/Logical Operator' incorporates:
   *  Inport: '<Root>/Xbox_Driver_ButtonB'
   *  Inport: '<Root>/Xbox_Driver_ButtonX'
   */
  rtb_Compare_mq = ((Robot_Control_U.Xbox_Driver_ButtonX) ||
                    (Robot_Control_U.Xbox_Driver_ButtonB));

  /* RelationalOperator: '<S21>/GreaterThan1' incorporates:
   *  Constant: '<S21>/Constant1'
   */
  rtb_Compare_ph = (rtb_Subtract_e > 0.0);

  /* Logic: '<S21>/Logical Operator5' incorporates:
   *  Logic: '<S21>/Logical Operator6'
   */
  rtb_LogicalOperator5 = (rtb_Compare_mq && (!rtb_Compare_ph));

  /* Logic: '<S21>/Logical Operator3' */
  rtb_Compare_mq = (rtb_Compare_mq && rtb_Compare_ph);

  /* Logic: '<S21>/Logical Operator2' incorporates:
   *  Logic: '<S21>/Logical Operator4'
   */
  rtb_Compare_bd = (rtb_Compare_bd && (!rtb_Compare_ky));

  /* Sum: '<S14>/Add' incorporates:
   *  Constant: '<S14>/Constant3'
   *  Gain: '<S14>/Convert meters to inches1'
   *  Inport: '<Root>/Vision_c1_AprilTag_X_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_X_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_X_m) + Vision_Tag_X_Offset;

  /* Sum: '<S14>/Add1' incorporates:
   *  Constant: '<S14>/Constant7'
   *  Gain: '<S14>/Convert meters to inches'
   *  Inport: '<Root>/Vision_c1_AprilTag_Y_m'
   */
  Robot_Control_B.Vision_c1_AprilTag_Corr_Y_inch = (39.37008 *
    Robot_Control_U.Vision_c1_AprilTag_Y_m) + Vision_Tag_Y_Offset;

  /* Sum: '<S14>/Add2' incorporates:
   *  Constant: '<S14>/Constant5'
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
    rtb_Switch1_c = rt_powd_snf(Robot_Control_U.Vision_c1_Object_Area_pct,
      -0.3495) * 111.0;

    /* End of Outputs for SubSystem: '<S330>/Prevent raising 0 to a negative exponent' */
  } else {
    /* Outputs for IfAction SubSystem: '<S330>/Subsystem' incorporates:
     *  ActionPort: '<S334>/Action Port'
     */
    /* SignalConversion generated from: '<S334>/Out1' incorporates:
     *  Constant: '<S334>/Constant'
     */
    rtb_Switch1_c = 0.0;

    /* End of Outputs for SubSystem: '<S330>/Subsystem' */
  }

  /* End of If: '<S330>/If' */

  /* Gain: '<S331>/Gain1' incorporates:
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  rtb_Subtract_e = 0.017453292519943295 *
    Robot_Control_U.Vision_c1_Object_Hor_deg;

  /* Sum: '<S14>/Add3' incorporates:
   *  Constant: '<S14>/Constant4'
   *  Fcn: '<S332>/r->x'
   */
  Robot_Control_B.Vision_c1_Object_Corr_X_inch = (rtb_Switch1_c * cos
    (rtb_Subtract_e)) + Vision_Object_X_Offset;

  /* Sum: '<S14>/Add4' incorporates:
   *  Constant: '<S14>/Constant8'
   *  Fcn: '<S332>/theta->y'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Y_inch = (rtb_Switch1_c * sin
    (rtb_Subtract_e)) + Vision_Object_Y_Offset;

  /* Sum: '<S14>/Add5' incorporates:
   *  Constant: '<S14>/Constant6'
   *  Inport: '<Root>/Vision_c1_Object_Hor_deg'
   */
  Robot_Control_B.Vision_c1_Object_Corr_Yaw_deg =
    Robot_Control_U.Vision_c1_Object_Hor_deg + Vision_Object_Angle_Offset;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Robot_Control_DW.SwitchCase_ActiveSubsystem;
  u0 = trunc(Robot_Control_U.GameState);
  if ((rtIsNaN(u0)) || (rtIsInf(u0))) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 4.294967296E+9);
  }

  switch ((u0 < 0.0) ? (-((int32_T)((uint32_T)(-u0)))) : ((int32_T)((uint32_T)u0)))
  {
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
     *  Merge: '<S8>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

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
    rtb_Compare_ph = false;

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

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S4>/Constant11'
     *  SignalConversion generated from: '<S4>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Autonomous' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S17>/Unit Delay'
       *  UnitDelay: '<S17>/Unit Delay1'
       */
      memset(&Robot_Control_DW.UnitDelay1_DSTATE_iz[0], 0, 60U * (sizeof(real_T)));
      Robot_Control_DW.UnitDelay_DSTATE_e3 = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Autonomous' */

      /* SystemReset for IfAction SubSystem: '<S1>/Autonomous' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S17>/Chart'
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
     *  ActionPort: '<S3>/Action Port'
     */
    /* MultiPortSwitch: '<S18>/Multiport Switch1' incorporates:
     *  Constant: '<S18>/Constant1'
     *  Constant: '<S18>/Constant10'
     *  Constant: '<S18>/Constant11'
     *  Constant: '<S18>/Constant12'
     *  Constant: '<S18>/Constant13'
     *  Constant: '<S18>/Constant17'
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S18>/Constant3'
     *  Constant: '<S18>/Constant4'
     *  Constant: '<S18>/Constant5'
     *  Constant: '<S18>/Constant6'
     *  Constant: '<S18>/Constant7'
     *  Constant: '<S18>/Constant8'
     *  Constant: '<S18>/Constant9'
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

    /* End of MultiPortSwitch: '<S18>/Multiport Switch1' */

    /* Saturate: '<S17>/Saturation' incorporates:
     *  UnitDelay: '<S6>/Unit Delay2'
     */
    if (Robot_Control_DW.UnitDelay2_DSTATE > 10.0) {
      rtb_Saturation_h = 10.0;
    } else if (Robot_Control_DW.UnitDelay2_DSTATE < 1.0) {
      rtb_Saturation_h = 1.0;
    } else {
      rtb_Saturation_h = Robot_Control_DW.UnitDelay2_DSTATE;
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* Chart: '<S17>/Chart' incorporates:
     *  Selector: '<S17>/Selector1'
     *  Selector: '<S17>/Selector2'
     *  UnitDelay: '<S17>/Unit Delay'
     *  UnitDelay: '<S17>/Unit Delay1'
     *  UnitDelay: '<S6>/Unit Delay'
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

    /* End of Chart: '<S17>/Chart' */

    /* Lookup_n-D: '<S17>/1-D Lookup Table1' */
    Robot_Control_B.Auto_Path_ID = rtb_MultiportSwitch1[plook_u32d_evencka
      (Robot_Control_B.Auto_Path_Counter, 1.0, 1.0, 2U)];

    /* Switch: '<S17>/Switch' incorporates:
     *  Inport: '<Root>/IsBlueAlliance'
     */
    rtb_Compare_bd = (Robot_Control_U.IsBlueAlliance != 0.0);

    /* Selector: '<S17>/Selector' */
    i_0 = ((int32_T)Robot_Control_B.Auto_Path_ID) - 1;

    /* Merge: '<S8>/Merge9' incorporates:
     *  Lookup_n-D: '<S17>/1-D Lookup Table'
     *  Lookup_n-D: '<S17>/1-D Lookup Table1'
     */
    Robot_Control_B.Spline_Num_Poses =
      rtCP_uDLookupTable_tableData[plook_u32d_evencka
      (Robot_Control_B.Auto_Path_ID, 1.0, 1.0, 24U)];

    /* Merge: '<S8>/Merge7' incorporates:
     *  SignalConversion: '<S15>/Signal Copy'
     */
    Robot_Control_B.Spline_Enable = Robot_Control_B.Auto_Spline_Enable;

    /* SignalConversion generated from: '<S3>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S15>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S8>/Merge1' incorporates:
     *  Constant: '<S15>/Constant1'
     *  SignalConversion generated from: '<S3>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* SignalConversion generated from: '<S3>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S15>/Constant5'
     */
    rtb_Compare_ph = false;

    /* Merge: '<S8>/Merge2' incorporates:
     *  Constant: '<S15>/Constant2'
     *  SignalConversion generated from: '<S3>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S8>/Merge3' incorporates:
     *  Constant: '<S15>/Constant3'
     *  SignalConversion generated from: '<S3>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S8>/Merge4' incorporates:
     *  Constant: '<S15>/Constant4'
     *  SignalConversion generated from: '<S3>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* Merge: '<S8>/Merge10' incorporates:
     *  Constant: '<S3>/Constant3'
     *  SignalConversion generated from: '<S3>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  Constant: '<S3>/Constant1'
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
     *  Constant: '<S3>/Constant4'
     *  SignalConversion generated from: '<S3>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = false;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S3>/Constant'
     *  SignalConversion generated from: '<S3>/Desired_Pipeline'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = 0U;
    for (i = 0; i < 60; i++) {
      /* Switch: '<S17>/Switch' */
      if (rtb_Compare_bd) {
        /* Selector: '<S17>/Selector' incorporates:
         *  Constant: '<S17>/Constant'
         */
        rtb_Spline_Ref_Poses_h[i] = rtCP_Constant_Value_c[(i_0 * 60) + i];
      } else {
        /* Selector: '<S17>/Selector' incorporates:
         *  Constant: '<S17>/Constant1'
         */
        rtb_Spline_Ref_Poses_h[i] = rtCP_Constant1_Value_b[(i_0 * 60) + i];
      }

      /* Update for UnitDelay: '<S17>/Unit Delay1' incorporates:
       *  Selector: '<S17>/Selector'
       */
      Robot_Control_DW.UnitDelay1_DSTATE_iz[i] = rtb_Spline_Ref_Poses_h[i];
    }

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Selector: '<S15>/Select heading angle from first row'
     *  Selector: '<S17>/Selector'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = rtb_Spline_Ref_Poses_h[30];

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_e3 = rtb_Saturation_h;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S12>/Action Port'
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
     *  ActionPort: '<S12>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S8>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

    /* SignalConversion generated from: '<S314>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S314>/X1_Values'
     *  Constant: '<S314>/X_values'
     */
    rtb_TmpSignalConversionAtLookup[0] = 0.0;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S314>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S314>/Constant'
     *  Constant: '<S314>/Constant1'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = Boost_Trigger_Low_Speed;
    rtb_TmpSignalConversionAtLoo_mu[1] = Boost_Trigger_High_Speed;

    /* S-Function (sfix_look1_dyn): '<S314>/Lookup Table Dynamic' incorporates:
     *  Inport: '<Root>/Xbox_Driver_Trigger_Right'
     */
    /* Dynamic Look-Up Table Block: '<S314>/Lookup Table Dynamic'
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

    /* Switch: '<S321>/Init' incorporates:
     *  UnitDelay: '<S321>/FixPt Unit Delay1'
     *  UnitDelay: '<S321>/FixPt Unit Delay2'
     */
    if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Saturation_h = rtb_UnitDelay3;
    } else {
      rtb_Saturation_h = Robot_Control_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S321>/Init' */

    /* Sum: '<S319>/Sum1' */
    rtb_Subtract_e = rtb_UnitDelay3 - rtb_Saturation_h;

    /* Switch: '<S320>/Switch2' incorporates:
     *  Constant: '<S318>/Constant1'
     *  Constant: '<S318>/Constant3'
     *  RelationalOperator: '<S320>/LowerRelop1'
     *  RelationalOperator: '<S320>/UpperRelop'
     *  Switch: '<S320>/Switch'
     */
    if (rtb_Subtract_e > Boost_Trigger_Increasing_Limit) {
      rtb_UnitDelay3 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Subtract_e < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S320>/Switch' incorporates:
       *  Constant: '<S318>/Constant1'
       */
      rtb_UnitDelay3 = Boost_Trigger_Decreasing_Limit;
    } else {
      rtb_UnitDelay3 = rtb_Subtract_e;
    }

    /* End of Switch: '<S320>/Switch2' */

    /* Sum: '<S319>/Sum' */
    rtb_Subtract_e = rtb_UnitDelay3 + rtb_Saturation_h;

    /* Lookup_n-D: '<S304>/Modulation_Drv' incorporates:
     *  Math: '<S304>/Magnitude'
     */
    rtb_Modulation_Drv = look1_binlcpw(rt_hypotd_snf
      (Robot_Control_B.Drive_Joystick_X, Robot_Control_B.Drive_Joystick_Y),
      rtCP_Modulation_Drv_bp01Data, rtCP_Modulation_Drv_tableData, 20U);

    /* RelationalOperator: '<S315>/Compare' incorporates:
     *  Constant: '<S315>/Constant'
     */
    rtb_Compare_ph = (rtb_Modulation_Drv == 0.0);

    /* Logic: '<S301>/Logical Operator1' incorporates:
     *  Constant: '<S12>/Constant12'
     *  Logic: '<S301>/Logical Operator2'
     */
    Robot_Control_B.Relative_Enable = false;

    /* DeadZone: '<S304>/Dead Zone' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (Twist_Deadzone_pos < 0.0) {
      rtb_UnitDelay3 = 0.0 - Twist_Deadzone_pos;
    } else if (Twist_Deadzone_neg <= 0.0) {
      rtb_UnitDelay3 = 0.0;
    } else {
      rtb_UnitDelay3 = 0.0 - Twist_Deadzone_neg;
    }

    /* End of DeadZone: '<S304>/Dead Zone' */

    /* Logic: '<S304>/Logical Operator' incorporates:
     *  Constant: '<S316>/Constant'
     *  RelationalOperator: '<S316>/Compare'
     */
    rtb_Is_Absolute_Steering = ((rtb_UnitDelay3 != 0.0) && rtb_Compare_ph);

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
      rtb_Saturation_h = Vision_Tag_Target_X -
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
      rtb_Saturation_h = Vision_Object_Target_X -
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
      rtb_Saturation_h = 0.0;
    }

    /* End of Switch: '<S301>/Switch2' */

    /* UnaryMinus: '<S301>/Unary Minus1' */
    Robot_Control_B.Relative_Error_X = -rtb_Saturation_h;

    /* Switch: '<S304>/Switch8' incorporates:
     *  Logic: '<S304>/Logical Operator1'
     *  Switch: '<S304>/Switch2'
     */
    if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S304>/Switch' incorporates:
       *  Gain: '<S304>/Gain'
       *  Merge: '<S8>/Merge4'
       */
      Robot_Control_B.Translation_Speed = Translation_Twist_Gain *
        rtb_UnitDelay3;
    } else if (rtb_Compare_ph) {
      /* Merge: '<S8>/Merge4' incorporates:
       *  Constant: '<S12>/Constant7'
       *  Constant: '<S12>/Constant8'
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
      u0 = rtb_Modulation_Drv * rtb_Subtract_e;

      /* Saturate: '<S314>/Saturation' incorporates:
       *  Switch: '<S304>/Switch2'
       */
      if (u0 > Boost_Trigger_High_Speed) {
        /* Merge: '<S8>/Merge4' */
        Robot_Control_B.Translation_Speed = Boost_Trigger_High_Speed;
      } else if (u0 < (-Boost_Trigger_High_Speed)) {
        /* Merge: '<S8>/Merge4' */
        Robot_Control_B.Translation_Speed = -Boost_Trigger_High_Speed;
      } else {
        /* Merge: '<S8>/Merge4' */
        Robot_Control_B.Translation_Speed = u0;
      }

      /* End of Saturate: '<S314>/Saturation' */
    }

    /* End of Switch: '<S304>/Switch8' */

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
      rtb_Modulation_Drv = Robot_Control_DW.UnitDelay1_DSTATE_l;
      rtb_Switch1_c = Robot_Control_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Modulation_Drv = Robot_Control_B.Drive_Joystick_Y;
      rtb_Switch1_c = Robot_Control_B.Drive_Joystick_X;
    }

    /* End of Switch: '<S317>/Switch1' */

    /* Switch: '<S304>/Switch1' incorporates:
     *  Logic: '<S304>/Logical Operator1'
     *  Switch: '<S304>/Switch4'
     *  Switch: '<S304>/Switch9'
     */
    if (rtb_Is_Absolute_Steering) {
      /* Signum: '<S304>/Sign' */
      if (rtIsNaN(rtb_UnitDelay3)) {
        u0 = (rtNaN);
      } else if (rtb_UnitDelay3 < 0.0) {
        u0 = -1.0;
      } else {
        u0 = (rtb_UnitDelay3 > 0.0);
      }

      /* Merge: '<S8>/Merge3' incorporates:
       *  Gain: '<S304>/Gain3'
       *  Signum: '<S304>/Sign'
       */
      Robot_Control_B.Translation_Angle = 3.141592653589793 * u0;
    } else if (rtb_Compare_ph) {
      /* Switch: '<S304>/Switch6' incorporates:
       *  Inport: '<Root>/IsBlueAlliance'
       *  Switch: '<S304>/Switch4'
       */
      if (Robot_Control_U.IsBlueAlliance != 0.0) {
        /* Merge: '<S8>/Merge3' incorporates:
         *  Constant: '<S304>/Constant'
         */
        Robot_Control_B.Translation_Angle = 0.0;
      } else {
        /* Merge: '<S8>/Merge3' incorporates:
         *  Constant: '<S304>/Constant1'
         */
        Robot_Control_B.Translation_Angle = 3.141592653589793;
      }

      /* End of Switch: '<S304>/Switch6' */
    } else {
      /* Merge: '<S8>/Merge3' incorporates:
       *  Switch: '<S304>/Switch4'
       *  Trigonometry: '<S304>/Atan2'
       */
      Robot_Control_B.Translation_Angle = rt_atan2d_snf(rtb_Modulation_Drv,
        rtb_Switch1_c);
    }

    /* End of Switch: '<S304>/Switch1' */

    /* Switch: '<S302>/Switch' incorporates:
     *  Constant: '<S302>/Constant5'
     *  Constant: '<S302>/Constant7'
     *  DataTypeConversion: '<S302>/Data Type Conversion'
     *  Logic: '<S304>/Logical Operator1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Compare_ph = (TEST_Swerve_Mode_Translation != 0.0);
    } else {
      rtb_Compare_ph = !rtb_Is_Absolute_Steering;
    }

    /* End of Switch: '<S302>/Switch' */

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

    /* DeadZone: '<S303>/Dead Zone' incorporates:
     *  Constant: '<S12>/Constant15'
     */
    if (Twist_Deadzone_pos < 0.0) {
      u0 = 0.0 - Twist_Deadzone_pos;
    } else if (Twist_Deadzone_neg <= 0.0) {
      u0 = 0.0;
    } else {
      u0 = 0.0 - Twist_Deadzone_neg;
    }

    /* Sum: '<S303>/Add' incorporates:
     *  Constant: '<S303>/Constant'
     *  Constant: '<S303>/Constant1'
     *  DeadZone: '<S303>/Dead Zone'
     *  Lookup_n-D: '<S303>/Modulation_Str_Y_Rel'
     *  Product: '<S303>/Product'
     *  Product: '<S303>/Product1'
     *  SignalConversion: '<S5>/Signal Copy5'
     */
    rtb_Saturation_h = (look1_binlcpw(Robot_Control_B.Steer_Joystick_Y,
      rtCP_Modulation_Str_Y_Rel_bp01D, rtCP_Modulation_Str_Y_Rel_table, 20U) *
                        Steering_Relative_Gain) + (u0 * Steering_Twist_Gain);

    /* RelationalOperator: '<S305>/Compare' incorporates:
     *  Constant: '<S305>/Constant'
     */
    rtb_LogicalOperator1_h = (rtb_Saturation_h == 0.0);

    /* Switch: '<S302>/Switch1' incorporates:
     *  Constant: '<S302>/Constant5'
     *  Constant: '<S302>/Constant8'
     *  DataTypeConversion: '<S302>/Data Type Conversion1'
     */
    if (TEST_Swerve_Mode_Override_Flag != 0.0) {
      rtb_Is_Absolute_Steering = (TEST_Swerve_Mode_Steering != 0.0);
    } else {
      rtb_Is_Absolute_Steering = rtb_LogicalOperator1_h;
    }

    /* End of Switch: '<S302>/Switch1' */

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
    rtb_Compare_ky = ((((((int32_T)rtb_Compare_bd) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_m)) || (((int32_T)rtb_Compare_mq) >
      ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_k))) || (((int32_T)
      rtb_LogicalOperator1) > ((int32_T)Robot_Control_DW.DelayInput1_DSTATE_g)))
                      || (((int32_T)rtb_LogicalOperator5) > ((int32_T)
      Robot_Control_DW.DelayInput1_DSTATE_g2)));

    /* Logic: '<S303>/AND1' incorporates:
     *  Logic: '<S303>/AND3'
     *  UnitDelay: '<S303>/Unit Delay2'
     */
    rtb_AND1 = (rtb_LogicalOperator1_h && (rtb_Compare_ky ||
      (Robot_Control_DW.UnitDelay2_DSTATE_l)));

    /* Logic: '<S303>/AND4' incorporates:
     *  Logic: '<S303>/AND8'
     *  UnitDelay: '<S303>/Unit Delay4'
     */
    rtb_Compare_ky = ((rtb_LogicalOperator1_h && (!rtb_Compare_ky)) &&
                      (Robot_Control_DW.UnitDelay4_DSTATE));

    /* Logic: '<S303>/AND6' */
    Robot_Control_B.Steering_Abs_Angle_Active = (rtb_AND1 || rtb_Compare_ky);

    /* UnitDelay: '<S303>/Unit Delay3' */
    rtb_UnitDelay3 = Robot_Control_DW.UnitDelay3_DSTATE;

    /* Switch: '<S303>/Switch8' incorporates:
     *  Constant: '<S312>/Constant'
     *  Logic: '<S303>/AND9'
     *  RelationalOperator: '<S311>/FixPt Relational Operator'
     *  RelationalOperator: '<S312>/Compare'
     *  UnitDelay: '<S311>/Delay Input1'
     *  UnitDelay: '<S6>/Unit Delay1'
     *  UnitDelay: '<S9>/Unit Delay'
     *
     * Block description for '<S311>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((((Robot_Control_B.Steering_Abs_Angle_Active) || (((int32_T)
            rtb_LogicalOperator1_h) > ((int32_T)
            Robot_Control_DW.DelayInput1_DSTATE_j))) ||
         (Robot_Control_B.Active_GameState != 2)) ||
        (Robot_Control_DW.UnitDelay1_DSTATE_nl)) {
      /* Switch: '<S303>/Switch8' incorporates:
       *  Inport: '<Root>/Gyro_Angle_rad'
       */
      Robot_Control_B.Steering_Abs_Gyro_Latch = Robot_Control_U.Gyro_Angle_rad;
    } else {
      /* Switch: '<S303>/Switch8' */
      Robot_Control_B.Steering_Abs_Gyro_Latch = rtb_UnitDelay3;
    }

    /* End of Switch: '<S303>/Switch8' */

    /* Switch: '<S303>/Switch4' incorporates:
     *  Constant: '<S303>/Constant5'
     *  Switch: '<S303>/Switch1'
     *  Switch: '<S303>/Switch5'
     *  Switch: '<S303>/Switch6'
     *  Switch: '<S303>/Switch7'
     */
    if (rtb_Compare_bd) {
      rtb_UnitDelay3 = 0.0;
    } else if (rtb_Compare_mq) {
      /* Switch: '<S303>/Switch5' incorporates:
       *  Constant: '<S303>/Constant6'
       */
      rtb_UnitDelay3 = 1.5707963267948966;
    } else if (rtb_LogicalOperator1) {
      /* Switch: '<S303>/Switch6' incorporates:
       *  Constant: '<S303>/Constant7'
       *  Switch: '<S303>/Switch5'
       */
      rtb_UnitDelay3 = 3.141592653589793;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S303>/Switch7' incorporates:
       *  Constant: '<S303>/Constant8'
       *  Switch: '<S303>/Switch5'
       *  Switch: '<S303>/Switch6'
       */
      rtb_UnitDelay3 = 4.71238898038469;
    } else if (rtb_Compare_ky) {
      /* Switch: '<S303>/Switch1' incorporates:
       *  Constant: '<S12>/Constant10'
       *  Switch: '<S303>/Switch5'
       *  Switch: '<S303>/Switch6'
       *  Switch: '<S303>/Switch7'
       */
      rtb_UnitDelay3 = 0.0;
    } else {
      /* Switch: '<S303>/Switch6' incorporates:
       *  Switch: '<S303>/Switch5'
       *  Switch: '<S303>/Switch7'
       *  UnitDelay: '<S303>/Unit Delay1'
       */
      rtb_UnitDelay3 = Robot_Control_DW.UnitDelay1_DSTATE_j2;
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
      Robot_Control_B.Steering_Abs_Angle = rtb_UnitDelay3;
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

    /* Merge: '<S8>/Merge1' incorporates:
     *  Sum: '<S303>/Add1'
     */
    Robot_Control_B.Steering_Abs_Cmd = Robot_Control_B.Steering_Abs_Angle +
      Robot_Control_B.Steering_Abs_Gyro;

    /* Merge: '<S8>/Merge2' incorporates:
     *  SignalConversion: '<S303>/Signal Copy'
     */
    Robot_Control_B.Steering_Rel_Cmd = rtb_Saturation_h;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S301>/Constant11'
     *  Switch: '<S301>/Switch6'
     *  Switch: '<S301>/Switch7'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = TEST_Pipeline;

    /* Merge: '<S8>/Merge7' incorporates:
     *  Constant: '<S12>/Constant3'
     *  SignalConversion generated from: '<S12>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S8>/Merge9' incorporates:
     *  Constant: '<S12>/Constant9'
     *  SignalConversion generated from: '<S12>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S8>/Merge10' incorporates:
     *  Constant: '<S12>/Constant1'
     *  SignalConversion generated from: '<S12>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = false;

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  Constant: '<S12>/Constant6'
     *  SignalConversion generated from: '<S12>/Enable_Wheels'
     */
    Robot_Control_Y.Enable_Wheels = false;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  Constant: '<S12>/Constant13'
     *  SignalConversion generated from: '<S12>/Reset_Wheel_Offsets'
     */
    Robot_Control_Y.Reset_Wheel_Offsets = false;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  Constant: '<S12>/Constant14'
     *  SignalConversion generated from: '<S12>/Disable_Wheels'
     */
    Robot_Control_Y.Disable_Wheels = false;

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  Constant: '<S12>/Constant2'
     *  SignalConversion generated from: '<S12>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = false;

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S12>/Constant21'
     *  SignalConversion generated from: '<S12>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Update for UnitDelay: '<S321>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S321>/FixPt Constant'
     */
    Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S321>/FixPt Unit Delay1' */
    Robot_Control_DW.FixPtUnitDelay1_DSTATE_f = rtb_Subtract_e;

    /* Update for UnitDelay: '<S317>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_l = rtb_Modulation_Drv;

    /* Update for UnitDelay: '<S317>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_p = rtb_Switch1_c;

    /* Update for UnitDelay: '<S311>/Delay Input1'
     *
     * Block description for '<S311>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_j = rtb_LogicalOperator1_h;

    /* Update for UnitDelay: '<S310>/Delay Input1' incorporates:
     *  Constant: '<S12>/Constant5'
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
    Robot_Control_DW.DelayInput1_DSTATE_m = rtb_Compare_bd;

    /* Update for UnitDelay: '<S307>/Delay Input1'
     *
     * Block description for '<S307>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_k = rtb_Compare_mq;

    /* Update for UnitDelay: '<S308>/Delay Input1'
     *
     * Block description for '<S308>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g = rtb_LogicalOperator1;

    /* Update for UnitDelay: '<S309>/Delay Input1'
     *
     * Block description for '<S309>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Robot_Control_DW.DelayInput1_DSTATE_g2 = rtb_LogicalOperator5;

    /* Update for UnitDelay: '<S303>/Unit Delay2' */
    Robot_Control_DW.UnitDelay2_DSTATE_l = rtb_AND1;

    /* Update for UnitDelay: '<S303>/Unit Delay4' */
    Robot_Control_DW.UnitDelay4_DSTATE = rtb_Compare_ky;

    /* Update for UnitDelay: '<S303>/Unit Delay3' */
    Robot_Control_DW.UnitDelay3_DSTATE = Robot_Control_B.Steering_Abs_Gyro_Latch;

    /* Update for UnitDelay: '<S303>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_j2 = rtb_UnitDelay3;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* InitializeConditions for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
     *  UnitDelay: '<S13>/Unit Delay'
     */
    Robot_Control_DW.UnitDelay_DSTATE_ir = ((rtAction == rtPrevAction) &&
      (Robot_Control_DW.UnitDelay_DSTATE_ir));

    /* End of InitializeConditions for SubSystem: '<S1>/Test' */

    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* SignalConversion generated from: '<S13>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S8>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses_h[0], 0, 60U * (sizeof(real_T)));

    /* Merge: '<S8>/Merge1' incorporates:
     *  Constant: '<S13>/Constant1'
     *  SignalConversion generated from: '<S13>/Steering_Abs_Cmd'
     */
    Robot_Control_B.Steering_Abs_Cmd = 0.0;

    /* Merge: '<S8>/Merge2' incorporates:
     *  Constant: '<S13>/Constant2'
     *  SignalConversion generated from: '<S13>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd = 0.0;

    /* Merge: '<S8>/Merge3' incorporates:
     *  Constant: '<S13>/Constant3'
     *  SignalConversion generated from: '<S13>/Translation_Angle'
     */
    Robot_Control_B.Translation_Angle = 0.0;

    /* Merge: '<S8>/Merge4' incorporates:
     *  Constant: '<S13>/Constant4'
     *  SignalConversion generated from: '<S13>/Translation_Speed'
     */
    Robot_Control_B.Translation_Speed = 0.0;

    /* SignalConversion generated from: '<S13>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S13>/Constant5'
     */
    rtb_Compare_ph = false;

    /* SignalConversion generated from: '<S13>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S13>/Constant6'
     */
    rtb_Is_Absolute_Steering = false;

    /* Merge: '<S8>/Merge7' incorporates:
     *  Constant: '<S13>/Constant7'
     *  SignalConversion generated from: '<S13>/Spline_Enable'
     */
    Robot_Control_B.Spline_Enable = false;

    /* Merge: '<S8>/Merge9' incorporates:
     *  Constant: '<S13>/Constant9'
     *  SignalConversion generated from: '<S13>/Spline_Num_Poses'
     */
    Robot_Control_B.Spline_Num_Poses = 10.0;

    /* Merge: '<S8>/Merge10' incorporates:
     *  Constant: '<S13>/Constant12'
     *  SignalConversion generated from: '<S13>/Test_Mode'
     */
    Robot_Control_B.Test_Mode = true;

    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant14'
     *  Switch: '<S13>/Switch1'
     *  UnitDelay: '<S13>/Unit Delay'
     */
    if (Robot_Control_B.Button_Disable_Wheels) {
      rtb_LogicalOperator1 = true;
    } else {
      rtb_LogicalOperator1 = ((!Robot_Control_B.Button_Enable_Wheels) &&
        (Robot_Control_DW.UnitDelay_DSTATE_ir));
    }

    /* End of Switch: '<S13>/Switch' */

    /* Outport: '<Root>/Swerve_Motors_Disabled' incorporates:
     *  SignalConversion generated from: '<S13>/Swerve_Motors_Disabled'
     */
    Robot_Control_Y.Swerve_Motors_Disabled = rtb_LogicalOperator1;

    /* Outport: '<Root>/Auto_Initial_Gyro_Angle' incorporates:
     *  Constant: '<S13>/Constant10'
     *  SignalConversion generated from: '<S13>/Auto_Initial_Gyro_Angle'
     */
    Robot_Control_Y.Auto_Initial_Gyro_Angle = 0.0;

    /* Outport: '<Root>/Vision_Desired_Pipeline' incorporates:
     *  Constant: '<S13>/Constant22'
     *  SignalConversion generated from: '<S13>/Desired_Pipeline'
     */
    Robot_Control_Y.Vision_Desired_Pipeline = TEST_Pipeline;

    /* Outport: '<Root>/Enable_Wheels' incorporates:
     *  SignalConversion: '<S13>/Signal Copy'
     */
    Robot_Control_Y.Enable_Wheels = Robot_Control_B.Button_Enable_Wheels;

    /* Outport: '<Root>/Disable_Wheels' incorporates:
     *  SignalConversion: '<S13>/Signal Copy2'
     */
    Robot_Control_Y.Disable_Wheels = Robot_Control_B.Button_Disable_Wheels;

    /* Outport: '<Root>/Reset_Wheel_Offsets' incorporates:
     *  SignalConversion: '<S13>/Signal Copy1'
     */
    Robot_Control_Y.Reset_Wheel_Offsets =
      Robot_Control_B.Button_Reset_Wheel_Offsets;

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_ir = rtb_LogicalOperator1;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Reshape: '<S26>/Reshape3' incorporates:
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_X'
   *  Inport: '<Root>/Vision_RobotPoseFieldSpace_Y'
   *  S-Function (sfix_udelay): '<S7>/Tapped Delay'
   *  S-Function (sfix_udelay): '<S7>/Tapped Delay1'
   *  Sum: '<S7>/Add'
   *  Sum: '<S7>/Add1'
   */
  rtb_TmpSignalConversionAtLookup[0] =
    (Robot_Control_U.Vision_RobotPoseFieldSpace_X +
     Robot_Control_DW.TappedDelay_X[0]) + Robot_Control_DW.TappedDelay_X[1];
  rtb_TmpSignalConversionAtLookup[1] =
    (Robot_Control_U.Vision_RobotPoseFieldSpace_Y +
     Robot_Control_DW.TappedDelay1_X[0]) + Robot_Control_DW.TappedDelay1_X[1];

  /* Delay: '<S79>/Delay' incorporates:
   *  Constant: '<S26>/X0'
   */
  if (Robot_Control_DW.icLoad) {
    Robot_Control_DW.Delay_DSTATE[0] = 0.0;
    Robot_Control_DW.Delay_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S61>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S62>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S78>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S80>/Enable'
   */
  /* Logic: '<S7>/AND' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/Vision_Num_Tags_Detected'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if ((Robot_Control_U.Vision_Num_Tags_Detected > 0.0) && (KF_Enable != 0.0)) {
    Robot_Control_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S80>/Sum' incorporates:
     *  Constant: '<S26>/C'
     *  Delay: '<S79>/Delay'
     *  Product: '<S80>/C[k]*xhat[k|k-1]'
     *  Reshape: '<S26>/Reshape3'
     *  Sum: '<S80>/Add1'
     */
    rtb_Saturation_h = rtb_TmpSignalConversionAtLookup[0] - ((0.0 *
      Robot_Control_DW.Delay_DSTATE[1]) + Robot_Control_DW.Delay_DSTATE[0]);
    rtb_Subtract_e = rtb_TmpSignalConversionAtLookup[1] - ((0.0 *
      Robot_Control_DW.Delay_DSTATE[0]) + Robot_Control_DW.Delay_DSTATE[1]);

    /* Product: '<S80>/Product3' incorporates:
     *  Constant: '<S74>/Constant'
     *  Product: '<S62>/Product2'
     */
    rtb_Modulation_Drv = 0.09512492197250398 * rtb_Saturation_h;
    Robot_Control_B.Product3[0] = rtb_Modulation_Drv;
    Robot_Control_B.Product3[1] = 6.209845451961181E-17 * rtb_Saturation_h;
    Robot_Control_B.Product3[0] += -2.0399807945617856E-17 * rtb_Subtract_e;
    Robot_Control_B.Product3[1] += 0.09512492197250422 * rtb_Subtract_e;

    /* Product: '<S62>/Product2' incorporates:
     *  Constant: '<S74>/Constant1'
     *  Sum: '<S62>/Add1'
     */
    Robot_Control_B.Product2[0] = rtb_Modulation_Drv;
    Robot_Control_B.Product2[1] = 2.580507006221294E-17 * rtb_Saturation_h;
    Robot_Control_B.Product2[0] += 2.5805070062212937E-17 * rtb_Subtract_e;
    Robot_Control_B.Product2[1] += 0.09512492197250424 * rtb_Subtract_e;
  } else if (Robot_Control_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S80>/Product3' incorporates:
     *  Outport: '<S80>/L*(y[k]-yhat[k|k-1])'
     */
    Robot_Control_B.Product3[0] = 0.0;
    Robot_Control_B.Product3[1] = 0.0;
    Robot_Control_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Logic: '<S7>/AND' */
  /* End of Outputs for SubSystem: '<S78>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S61>/Enabled Subsystem' */

  /* Sum: '<S61>/Add' incorporates:
   *  Delay: '<S79>/Delay'
   *  Product: '<S62>/Product2'
   */
  rtb_TmpSignalConversionAtLookup[0] = Robot_Control_B.Product2[0] +
    Robot_Control_DW.Delay_DSTATE[0];
  rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.Product2[1] +
    Robot_Control_DW.Delay_DSTATE[1];

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Switch: '<S7>/Switch1'
   */
  if (KF_Enable != 0.0) {
    /* Switch: '<S7>/Switch' */
    Robot_Control_B.KF_Position_X = rtb_TmpSignalConversionAtLookup[0];

    /* Switch: '<S7>/Switch1' */
    Robot_Control_B.KF_Position_Y = rtb_TmpSignalConversionAtLookup[1];
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

  /* If: '<S10>/If' incorporates:
   *  Constant: '<S140>/Constant'
   *  Logic: '<S140>/AND'
   *  MATLAB Function: '<S90>/Find closest index to curve'
   *  Product: '<S140>/Product'
   *  RelationalOperator: '<S140>/Relational Operator'
   *  RelationalOperator: '<S140>/Relational Operator1'
   *  Selector: '<S140>/Selector'
   *  Selector: '<S140>/Selector1'
   *  Selector: '<S141>/Selector'
   *  Sum: '<S140>/Add'
   */
  rtPrevAction = Robot_Control_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Robot_Control_B.Spline_Enable);
  Robot_Control_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S93>/If' */
    if (Robot_Control_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S96>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S98>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    Robot_Control_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S93>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S10>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S88>/Action Port'
       */
      /* InitializeConditions for If: '<S10>/If' incorporates:
       *  UnitDelay: '<S141>/Unit Delay'
       *  UnitDelay: '<S141>/Unit Delay1'
       *  UnitDelay: '<S88>/Unit Delay'
       *  UnitDelay: '<S89>/Unit Delay'
       *  UnitDelay: '<S91>/Unit Delay'
       *  UnitDelay: '<S91>/Unit Delay1'
       */
      Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;
      Robot_Control_DW.UnitDelay_DSTATE_h = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_f4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_g4 = 0.0;
      Robot_Control_DW.UnitDelay_DSTATE_le = 0.0;
      Robot_Control_DW.UnitDelay1_DSTATE_k = 0.0;

      /* End of InitializeConditions for SubSystem: '<S10>/Spline Path Following Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S10>/Spline Path Following Enabled' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    /* Selector: '<S89>/Selector1' incorporates:
     *  Merge: '<S8>/Merge8'
     */
    memcpy(&rtb_Ref_Poses[0], &rtb_Spline_Ref_Poses_h[0], 10U * (sizeof(real_T)));
    memcpy(&rtb_Ref_Poses[10], &rtb_Spline_Ref_Poses_h[10], 10U * (sizeof(real_T)));

    /* Lookup_n-D: '<S88>/Capture Radius' incorporates:
     *  UnitDelay: '<S88>/Unit Delay'
     */
    rtb_Saturation_h = look1_binlcpw(Robot_Control_DW.UnitDelay_DSTATE_h,
      rtCP_CaptureRadius_bp01Data, rtCP_CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S89>/Matrix Concatenate2' */
    rtb_TmpSignalConversionAtLookup[0] = Robot_Control_B.KF_Position_X;

    /* SignalConversion generated from: '<S89>/Matrix Concatenate2' */
    rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.KF_Position_Y;

    /* If: '<S93>/If' incorporates:
     *  RelationalOperator: '<S93>/ '
     *  UnitDelay: '<S89>/Unit Delay'
     */
    rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh <=
                          Robot_Control_B.Spline_Num_Poses));
    Robot_Control_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S96>/If' */
      if (Robot_Control_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S98>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      Robot_Control_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S93>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S96>/Action Port'
       */
      /* InitializeConditions for If: '<S93>/If' incorporates:
       *  UnitDelay: '<S96>/Unit Delay'
       */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Robot_Control_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S93>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S93>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S96>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S96>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S99>/Action Port'
       */
      /* If: '<S96>/If' incorporates:
       *  Selector: '<S89>/Selector1'
       *  Selector: '<S96>/Selector'
       *  Selector: '<S99>/Selector'
       */
      rtb_Switch5_o = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S96>/Increment_If_Rectangle_Check' */

      /* Sum: '<S96>/Minus' incorporates:
       *  Concatenate: '<S89>/Matrix Concatenate2'
       *  Selector: '<S96>/Selector'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = rtb_TmpSignalConversionAtLookup[0] -
        rtb_Switch5_o;

      /* Outputs for IfAction SubSystem: '<S96>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S99>/Action Port'
       */
      /* If: '<S96>/If' incorporates:
       *  Selector: '<S89>/Selector1'
       *  Selector: '<S96>/Selector'
       *  Selector: '<S99>/Selector'
       *  Sum: '<S96>/Minus'
       */
      rtb_Switch1_c = rtb_Ref_Poses[((int32_T)
        Robot_Control_DW.UnitDelay_DSTATE_gh) + 9];

      /* End of Outputs for SubSystem: '<S96>/Increment_If_Rectangle_Check' */

      /* Sum: '<S96>/Minus' incorporates:
       *  Concatenate: '<S89>/Matrix Concatenate2'
       *  Selector: '<S96>/Selector'
       */
      rtb_TmpSignalConversionAtLoo_mu[1] = rtb_TmpSignalConversionAtLookup[1] -
        rtb_Switch1_c;

      /* Math: '<S96>/Hypot' */
      rtb_Subtract_e = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu[0],
        rtb_TmpSignalConversionAtLoo_mu[1]);

      /* RelationalOperator: '<S96>/Equal' */
      rtb_LogicalOperator1 = (Robot_Control_B.Spline_Num_Poses ==
        Robot_Control_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S96>/Switch' incorporates:
       *  Logic: '<S96>/AND'
       *  Logic: '<S96>/OR'
       *  RelationalOperator: '<S96>/Relational Operator'
       *  UnitDelay: '<S96>/Unit Delay'
       */
      rtb_LogicalOperator5 = ((Robot_Control_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Subtract_e <= rtb_Saturation_h) && rtb_LogicalOperator1));

      /* If: '<S96>/If' */
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
        /* Disable for If: '<S98>/If' */
        Robot_Control_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S96>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S98>/Action Port'
         */
        /* If: '<S98>/If' incorporates:
         *  RelationalOperator: '<S98>/Equal'
         */
        rtPrevAction = Robot_Control_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Robot_Control_DW.UnitDelay_DSTATE_gh ==
                              Robot_Control_B.Spline_Num_Poses));
        Robot_Control_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S98>/Is_Last_Point' incorporates:
           *  ActionPort: '<S101>/Action Port'
           */
          /* InitializeConditions for If: '<S98>/If' incorporates:
           *  UnitDelay: '<S101>/Unit Delay'
           */
          Robot_Control_DW.UnitDelay_DSTATE_nu = ((rtPrevAction == 0) &&
            (Robot_Control_DW.UnitDelay_DSTATE_nu));

          /* End of InitializeConditions for SubSystem: '<S98>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S98>/Is_Last_Point' incorporates:
           *  ActionPort: '<S101>/Action Port'
           */
          /* Switch: '<S101>/Switch' incorporates:
           *  Constant: '<S103>/Constant'
           *  Logic: '<S101>/OR'
           *  RelationalOperator: '<S103>/Compare'
           *  UnitDelay: '<S101>/Unit Delay'
           */
          rtb_Compare_bd = ((Robot_Control_DW.UnitDelay_DSTATE_nu) ||
                            (rtb_Subtract_e <= Spline_Stop_Radius));

          /* If: '<S101>/If' */
          if (rtb_Compare_bd) {
            /* Outputs for IfAction SubSystem: '<S101>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S104>/Action Port'
             */
            /* Merge: '<S93>/Merge2' incorporates:
             *  Constant: '<S104>/Constant'
             *  SignalConversion generated from: '<S104>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator1 = true;

            /* SignalConversion generated from: '<S104>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S104>/Constant1'
             */
            rtb_Compare_mq = false;

            /* End of Outputs for SubSystem: '<S101>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S101>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S105>/Action Port'
             */
            /* Merge: '<S93>/Merge2' incorporates:
             *  Constant: '<S105>/Constant'
             *  SignalConversion generated from: '<S105>/Robot_Reached_Destination'
             */
            rtb_LogicalOperator1 = false;

            /* SignalConversion generated from: '<S105>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S105>/Constant1'
             */
            rtb_Compare_mq = true;

            /* End of Outputs for SubSystem: '<S101>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S101>/If' */

          /* Merge: '<S93>/Merge4' incorporates:
           *  SignalConversion: '<S101>/Signal Copy'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S101>/Unit Delay' */
          Robot_Control_DW.UnitDelay_DSTATE_nu = rtb_Compare_bd;

          /* End of Outputs for SubSystem: '<S98>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S98>/Increment_Search' incorporates:
           *  ActionPort: '<S100>/Action Port'
           */
          /* Merge: '<S93>/Merge2' incorporates:
           *  Constant: '<S100>/Constant'
           *  SignalConversion generated from: '<S100>/Robot_Reached_Destination'
           */
          rtb_LogicalOperator1 = false;

          /* SignalConversion generated from: '<S100>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S100>/Constant1'
           */
          rtb_Compare_mq = false;

          /* Merge: '<S93>/Merge4' incorporates:
           *  Constant: '<S102>/FixPt Constant'
           *  SignalConversion: '<S100>/Signal Copy'
           *  Sum: '<S102>/FixPt Sum1'
           */
          Robot_Control_B.Spline_Follow_Index =
            Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

          /* End of Outputs for SubSystem: '<S98>/Increment_Search' */
        }

        /* End of If: '<S98>/If' */
        /* End of Outputs for SubSystem: '<S96>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S96>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S99>/Action Port'
         */
        /* Sum: '<S106>/FixPt Sum1' incorporates:
         *  Constant: '<S106>/FixPt Constant'
         */
        rtb_Modulation_Drv = Robot_Control_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S99>/Selector1' incorporates:
         *  Selector: '<S89>/Selector1'
         */
        rtb_Subtract = rtb_Ref_Poses[((int32_T)rtb_Modulation_Drv) - 1];

        /* Sum: '<S107>/Subtract' incorporates:
         *  Selector: '<S99>/Selector1'
         *  Sum: '<S107>/Minus1'
         */
        rtb_TmpSignalConversionAtLoo_mu[0] = rtb_Subtract - rtb_Switch5_o;

        /* Selector: '<S99>/Selector1' incorporates:
         *  Selector: '<S89>/Selector1'
         */
        rtb_Switch2_p = rtb_Ref_Poses[((int32_T)rtb_Modulation_Drv) + 9];

        /* Sum: '<S107>/Subtract' incorporates:
         *  Selector: '<S99>/Selector1'
         *  Sum: '<S107>/Minus1'
         */
        rtb_TmpSignalConversionAtLoo_mu[1] = rtb_Switch2_p - rtb_Switch1_c;

        /* Math: '<S107>/Hypot' */
        rtb_Subtract_e = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu[0],
          rtb_TmpSignalConversionAtLoo_mu[1]);

        /* Product: '<S107>/Divide' */
        rtb_Modulation_Drv = rtb_TmpSignalConversionAtLoo_mu[1];

        /* UnaryMinus: '<S107>/Unary Minus' */
        rtb_UnitDelay3 = rtb_TmpSignalConversionAtLoo_mu[0];

        /* Product: '<S107>/Product' incorporates:
         *  Product: '<S107>/Divide'
         *  UnaryMinus: '<S107>/Unary Minus'
         */
        rtb_TmpSignalConversionAtLoo_mu[0] = (rtb_Modulation_Drv /
          rtb_Subtract_e) * rtb_Saturation_h;
        rtb_TmpSignalConversionAtLoo_mu[1] = ((-rtb_UnitDelay3) / rtb_Subtract_e)
          * rtb_Saturation_h;

        /* Sum: '<S107>/Add1' incorporates:
         *  Sum: '<S107>/Add2'
         *  Sum: '<S107>/Minus'
         */
        rtb_UnitDelay3 = rtb_Subtract - rtb_TmpSignalConversionAtLoo_mu[0];

        /* Sum: '<S107>/Minus4' incorporates:
         *  Sum: '<S107>/Add2'
         *  Sum: '<S107>/Minus'
         */
        rtb_Subtract = (rtb_Subtract + rtb_TmpSignalConversionAtLoo_mu[0]) -
          rtb_UnitDelay3;

        /* Sum: '<S107>/Minus5' incorporates:
         *  Concatenate: '<S89>/Matrix Concatenate2'
         *  Sum: '<S107>/Minus'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_TmpSignalConversionAtLookup[0] -
          rtb_UnitDelay3;

        /* Sum: '<S107>/Add' incorporates:
         *  Sum: '<S107>/Add2'
         *  Sum: '<S107>/Minus1'
         */
        rtb_Modulation_Drv = rtb_Switch5_o - rtb_TmpSignalConversionAtLoo_mu[0];

        /* Sum: '<S107>/Minus' incorporates:
         *  Sum: '<S107>/Minus1'
         */
        rtb_UnitDelay3 -= rtb_Modulation_Drv;

        /* DotProduct: '<S107>/Dot Product' incorporates:
         *  Concatenate: '<S89>/Matrix Concatenate2'
         *  Sum: '<S107>/Minus'
         *  Sum: '<S107>/Minus1'
         *  Sum: '<S107>/Minus5'
         */
        rtb_Subtract_e = (rtb_TmpSignalConversionAtLookup[0] -
                          rtb_Modulation_Drv) * rtb_UnitDelay3;

        /* Sum: '<S107>/Add1' incorporates:
         *  Sum: '<S107>/Add2'
         *  Sum: '<S107>/Minus'
         */
        rtb_Switch5_o = rtb_Switch2_p - rtb_TmpSignalConversionAtLoo_mu[1];

        /* Sum: '<S107>/Minus4' incorporates:
         *  Sum: '<S107>/Add2'
         *  Sum: '<S107>/Minus'
         */
        rtb_Switch2_p = (rtb_Switch2_p + rtb_TmpSignalConversionAtLoo_mu[1]) -
          rtb_Switch5_o;

        /* Sum: '<S107>/Add' incorporates:
         *  Sum: '<S107>/Add2'
         *  Sum: '<S107>/Minus1'
         */
        rtb_Modulation_Drv = rtb_Switch1_c - rtb_TmpSignalConversionAtLoo_mu[1];

        /* Sum: '<S107>/Minus' incorporates:
         *  Sum: '<S107>/Minus1'
         */
        rtb_Switch1_c = rtb_Switch5_o - rtb_Modulation_Drv;

        /* DotProduct: '<S107>/Dot Product' incorporates:
         *  Concatenate: '<S89>/Matrix Concatenate2'
         *  Sum: '<S107>/Minus'
         *  Sum: '<S107>/Minus1'
         *  Sum: '<S107>/Minus5'
         */
        rtb_Subtract_e += (rtb_TmpSignalConversionAtLookup[1] -
                           rtb_Modulation_Drv) * rtb_Switch1_c;

        /* DotProduct: '<S107>/Dot Product2' incorporates:
         *  Concatenate: '<S89>/Matrix Concatenate2'
         *  Sum: '<S107>/Minus'
         *  Sum: '<S107>/Minus4'
         *  Sum: '<S107>/Minus5'
         */
        rtb_Modulation_Drv = ((rtb_TmpSignalConversionAtLookup[1] -
          rtb_Switch5_o) * rtb_Switch2_p) + (rtb_Subtract *
          rtb_MatrixConcatenate_b_idx_0);

        /* Merge: '<S93>/Merge4' incorporates:
         *  Constant: '<S108>/Constant'
         *  Constant: '<S109>/Constant'
         *  DataTypeConversion: '<S99>/Data Type Conversion'
         *  DotProduct: '<S107>/Dot Product1'
         *  DotProduct: '<S107>/Dot Product3'
         *  Logic: '<S107>/AND'
         *  RelationalOperator: '<S107>/LessThanOrEqual'
         *  RelationalOperator: '<S107>/LessThanOrEqual1'
         *  RelationalOperator: '<S108>/Compare'
         *  RelationalOperator: '<S109>/Compare'
         *  Sum: '<S107>/Minus'
         *  Sum: '<S107>/Minus4'
         *  Sum: '<S99>/Add'
         */
        Robot_Control_B.Spline_Follow_Index = ((real_T)((((rtb_Subtract_e >= 0.0)
          && (rtb_Subtract_e <= ((rtb_Switch1_c * rtb_Switch1_c) +
          (rtb_UnitDelay3 * rtb_UnitDelay3)))) && (rtb_Modulation_Drv >= 0.0)) &&
          (rtb_Modulation_Drv <= ((rtb_Subtract * rtb_Subtract) + (rtb_Switch2_p
          * rtb_Switch2_p))))) + Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S93>/Merge2' incorporates:
         *  Constant: '<S99>/Constant2'
         *  SignalConversion generated from: '<S99>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator1 = false;

        /* SignalConversion generated from: '<S99>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S99>/Constant1'
         */
        rtb_Compare_mq = false;

        /* End of Outputs for SubSystem: '<S96>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S96>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S97>/Action Port'
         */
        /* Merge: '<S93>/Merge2' incorporates:
         *  Constant: '<S97>/Constant2'
         *  SignalConversion generated from: '<S97>/Robot_Reached_Destination'
         */
        rtb_LogicalOperator1 = false;

        /* SignalConversion generated from: '<S97>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S97>/Constant1'
         */
        rtb_Compare_mq = false;

        /* Merge: '<S93>/Merge4' incorporates:
         *  SignalConversion generated from: '<S97>/Current_Index'
         */
        Robot_Control_B.Spline_Follow_Index =
          Robot_Control_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S96>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S93>/Merge1' incorporates:
       *  Constant: '<S96>/Constant'
       *  SignalConversion generated from: '<S96>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S96>/Unit Delay' */
      Robot_Control_DW.UnitDelay_DSTATE_e4 = rtb_LogicalOperator5;

      /* End of Outputs for SubSystem: '<S93>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S93>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S95>/Action Port'
       */
      /* Merge: '<S93>/Merge1' incorporates:
       *  Constant: '<S95>/Constant'
       *  SignalConversion generated from: '<S95>/Out_Of_Bounds'
       */
      Robot_Control_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S93>/Merge2' incorporates:
       *  Constant: '<S95>/Constant1'
       *  SignalConversion generated from: '<S95>/Robot_Reached_Destination'
       */
      rtb_LogicalOperator1 = false;

      /* SignalConversion generated from: '<S95>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S95>/Constant2'
       */
      rtb_Compare_mq = false;

      /* Merge: '<S93>/Merge4' incorporates:
       *  SignalConversion generated from: '<S95>/Current_Index'
       */
      Robot_Control_B.Spline_Follow_Index = Robot_Control_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S93>/Escape_Auto_Driving' */
    }

    /* End of If: '<S93>/If' */

    /* If: '<S89>/If1' */
    if (!rtb_Compare_mq) {
      /* Outputs for IfAction SubSystem: '<S89>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S94>/Action Port'
       */
      /* Bias: '<S110>/Add Constant' incorporates:
       *  Bias: '<S110>/Bias'
       *  Sum: '<S110>/Subtract'
       */
      rtb_Subtract_e = ((Robot_Control_B.Spline_Num_Poses -
                         Robot_Control_B.Spline_Follow_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S110>/Selector4' incorporates:
       *  Bias: '<S110>/Bias1'
       *  Constant: '<S112>/FixPt Constant'
       *  Sum: '<S112>/FixPt Sum1'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = Robot_Control_B.Spline_Follow_Index -
        1.0;
      rtb_TmpSignalConversionAtLoo_mu[1] = Robot_Control_B.Spline_Num_Poses +
        2.0;

      /* SignalConversion generated from: '<S110>/Selector5' */
      rtb_TmpSignalConversionAtLookup[1] = Robot_Control_B.Spline_Num_Poses;

      /* Selector: '<S110>/Selector5' */
      Robot_Control_DW.Selector5_DIMS1[0] = (int32_T)
        rtb_TmpSignalConversionAtLookup[1];
      Robot_Control_DW.Selector5_DIMS1[1] = 2;
      s115_iter = ((int32_T)rtb_TmpSignalConversionAtLookup[1]) - 1;

      /* Concatenate: '<S110>/Matrix Concatenate' */
      Robot_Control_DW.MatrixConcatenate_DIMS1[0] =
        Robot_Control_DW.Selector5_DIMS1[0] + 2;
      Robot_Control_DW.MatrixConcatenate_DIMS1[1] = 2;

      /* Selector: '<S110>/Selector5' incorporates:
       *  Concatenate: '<S110>/Matrix Concatenate'
       *  Gain: '<S114>/Gain'
       *  Selector: '<S110>/Selector2'
       *  Selector: '<S110>/Selector3'
       *  Selector: '<S89>/Selector1'
       *  Sum: '<S114>/Subtract'
       */
      i_0 = 0;
      for (i = 0; i < 2; i++) {
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s115_iter;
             rtb_Num_Segments++) {
          rtb_Selector5[rtb_Num_Segments + (Robot_Control_DW.Selector5_DIMS1[0] *
            i)] = rtb_Ref_Poses[rtb_Num_Segments + i_0];
        }

        rtb_MatrixConcatenate_p[Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i]
          = (rtb_Ref_Poses[i_0] * 2.0) - rtb_Ref_Poses[i_0 + 1];
        i_0 += 10;
      }

      /* Concatenate: '<S110>/Matrix Concatenate' incorporates:
       *  Bias: '<S110>/Add Constant1'
       *  Gain: '<S113>/Gain'
       *  Selector: '<S110>/Selector'
       *  Selector: '<S110>/Selector1'
       *  Selector: '<S110>/Selector5'
       *  Selector: '<S89>/Selector1'
       *  Sum: '<S113>/Subtract'
       */
      s115_iter = Robot_Control_DW.Selector5_DIMS1[0];
      for (i_0 = 0; i_0 < 2; i_0++) {
        for (i = 0; i < s115_iter; i++) {
          rtb_MatrixConcatenate_p[(i +
            (Robot_Control_DW.MatrixConcatenate_DIMS1[0] * i_0)) + 1] =
            rtb_Selector5[(Robot_Control_DW.Selector5_DIMS1[0] * i_0) + i];
        }
      }

      rtb_MatrixConcatenate_p[Robot_Control_DW.Selector5_DIMS1[0] + 1] =
        (rtb_Ref_Poses[((int32_T)rtb_TmpSignalConversionAtLookup[1]) - 1] * 2.0)
        - rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) - 1];
      rtb_MatrixConcatenate_p[(Robot_Control_DW.Selector5_DIMS1[0] +
        Robot_Control_DW.MatrixConcatenate_DIMS1[0]) + 1] = (rtb_Ref_Poses
        [((int32_T)Robot_Control_B.Spline_Num_Poses) + 9] * 2.0) -
        rtb_Ref_Poses[((int32_T)(Robot_Control_B.Spline_Num_Poses - 1.0)) + 9];

      /* Selector: '<S110>/Selector4' */
      s115_iter = ((int32_T)rtb_TmpSignalConversionAtLoo_mu[1]) - ((int32_T)
        rtb_TmpSignalConversionAtLoo_mu[0]);
      Robot_Control_DW.Selector4_DIMS1[0] = s115_iter + 1;
      Robot_Control_DW.Selector4_DIMS1[1] = 2;

      /* Assignment: '<S110>/Assignment' */
      memset(&rtb_Assignment[0], 0, 24U * (sizeof(real_T)));

      /* Selector: '<S110>/Selector4' */
      rtb_Num_Segments = (int32_T)rtb_TmpSignalConversionAtLoo_mu[0];

      /* Assignment: '<S110>/Assignment' incorporates:
       *  Concatenate: '<S110>/Matrix Concatenate'
       *  Selector: '<S110>/Selector4'
       */
      for (i_0 = 0; i_0 < 2; i_0++) {
        for (i = 0; i <= s115_iter; i++) {
          rtb_Assignment[i + (12 * i_0)] = rtb_MatrixConcatenate_p[((i +
            rtb_Num_Segments) + (Robot_Control_DW.MatrixConcatenate_DIMS1[0] *
            i_0)) - 1];
        }
      }

      /* Outputs for Iterator SubSystem: '<S111>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S115>/While Iterator'
       */
      s115_iter = 1;
      do {
        rtb_Switch5_o = rtb_Assignment[s115_iter + 1];
        rtb_TmpSignalConversionAtLoo_mu[0] = rtb_Switch5_o -
          rtb_Assignment[s115_iter - 1];
        rtb_Add2[0] = rtb_Assignment[s115_iter] - rtb_Assignment[s115_iter + 2];
        rtb_Minus_k_idx_0 = rtb_Switch5_o - rtb_Assignment[s115_iter];
        rtb_Switch5_o = rtb_Assignment[s115_iter + 13];
        rtb_TmpSignalConversionAtLoo_mu[1] = rtb_Switch5_o -
          rtb_Assignment[s115_iter + 11];
        rtb_Switch2_p = rtb_Assignment[s115_iter + 12];
        rtb_Add2[1] = rtb_Switch2_p - rtb_Assignment[s115_iter + 14];
        rtb_Minus_k_idx_1 = rtb_Switch5_o - rtb_Switch2_p;
        for (i = 0; i < 50; i++) {
          rtb_Modulation_Drv = ((real_T)i) / 49.0;
          rtb_Switch1_c = rt_powd_snf(rtb_Modulation_Drv, 2.0);
          rtb_Subtract = rt_powd_snf(rtb_Modulation_Drv, 3.0);
          rtb_UnitDelay3 = (rtb_Modulation_Drv - (2.0 * rtb_Switch1_c)) +
            rtb_Subtract;
          rtb_Switch5_o = rtb_Switch1_c - rtb_Subtract;
          rtb_Hypot = 3.0 * rtb_Switch1_c;
          rtb_Subtract = rtb_Hypot - (2.0 * rtb_Subtract);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_TmpSignalConversionAtLoo_mu[0]
            * rtb_UnitDelay3) + (rtb_Add2[0] * rtb_Switch5_o)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_Subtract)) + rtb_Assignment[s115_iter];
          rtb_Subtract = ((((rtb_TmpSignalConversionAtLoo_mu[1] * rtb_UnitDelay3)
                            + (rtb_Add2[1] * rtb_Switch5_o)) * 0.5) +
                          (rtb_Minus_k_idx_1 * rtb_Subtract)) + rtb_Switch2_p;
          rtb_UnitDelay3 = (rtb_Hypot - (4.0 * rtb_Modulation_Drv)) + 1.0;
          rtb_Switch5_o = (2.0 * rtb_Modulation_Drv) - rtb_Hypot;
          rtb_Switch1_c = (rtb_Modulation_Drv - rtb_Switch1_c) * 6.0;
          rtb_MatrixConcatenate_idx_0 = (((rtb_TmpSignalConversionAtLoo_mu[0] *
            rtb_UnitDelay3) + (rtb_Add2[0] * rtb_Switch5_o)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_Switch1_c);
          rtb_Hypot = (((rtb_TmpSignalConversionAtLoo_mu[1] * rtb_UnitDelay3) +
                        (rtb_Add2[1] * rtb_Switch5_o)) * 0.5) +
            (rtb_Minus_k_idx_1 * rtb_Switch1_c);
          rtb_Switch1_c = (6.0 * rtb_Modulation_Drv) - 4.0;
          rtb_UnitDelay3 = (-6.0 * rtb_Modulation_Drv) + 2.0;
          rtb_Modulation_Drv = (-12.0 * rtb_Modulation_Drv) + 6.0;
          rtb_Switch5_o = (((rtb_TmpSignalConversionAtLoo_mu[0] * rtb_Switch1_c)
                            + (rtb_Add2[0] * rtb_UnitDelay3)) * 0.5) +
            (rtb_Minus_k_idx_0 * rtb_Modulation_Drv);
          rtb_UnitDelay3 = (((rtb_TmpSignalConversionAtLoo_mu[1] * rtb_Switch1_c)
                             + (rtb_Add2[1] * rtb_UnitDelay3)) * 0.5) +
            (rtb_Minus_k_idx_1 * rtb_Modulation_Drv);
          rtb_Switch1_c = rt_powd_snf(rt_hypotd_snf(rtb_MatrixConcatenate_idx_0,
            rtb_Hypot), 3.0);
          rtb_Modulation_Drv = fmax(1.0E-10, rtb_Switch1_c);
          Robot_Control_DW.Relay_Mode = ((rtb_Switch1_c >= 2.220446049250313E-16)
            || (Robot_Control_DW.Relay_Mode));
          if (i == 0) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[i] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[i + 50] = rtb_Subtract;
          if (Robot_Control_DW.Relay_Mode) {
            i_0 = 1;
          } else {
            i_0 = -1;
          }

          rtb_Assignment_d[i + 100] = fabs((rtb_MatrixConcatenate_idx_0 *
            rtb_UnitDelay3) - (rtb_Switch5_o * rtb_Hypot)) / (rtb_Modulation_Drv
            * ((real_T)i_0));
        }

        if (s115_iter == 1) {
          memset(&Robot_Control_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i_0 = 0; i_0 < 3; i_0++) {
          memcpy(&Robot_Control_B.Assignment[((i_0 * 50) + (s115_iter * 150)) +
                 -150], &rtb_Assignment_d[i_0 * 50], 50U * (sizeof(real_T)));
        }

        rtb_Modulation_Drv = rtb_Subtract_e - ((real_T)s115_iter);
        rtb_Num_Segments = s115_iter;
        s115_iter++;
      } while ((rtb_Modulation_Drv >= 4.0) && (s115_iter <= 3));

      /* End of Outputs for SubSystem: '<S111>/Sampling_Loop' */

      /* SignalConversion generated from: '<S94>/Position_and_Curvature' incorporates:
       *  Assignment: '<S115>/Assignment'
       *  Concatenate: '<S90>/Matrix Concatenate'
       */
      memcpy(&rtb_MatrixConcatenate_o[0], &Robot_Control_B.Assignment[0], 450U *
             (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S89>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem' incorporates:
       *  ActionPort: '<S92>/Action Port'
       */
      /* Product: '<S92>/Product' incorporates:
       *  Selector: '<S89>/Selector'
       *  Selector: '<S89>/Selector1'
       */
      rtb_Subtract_e = rtb_Ref_Poses[((int32_T)Robot_Control_B.Spline_Num_Poses)
        - 1];

      /* Product: '<S92>/Product1' incorporates:
       *  Selector: '<S89>/Selector'
       *  Selector: '<S89>/Selector1'
       */
      rtb_Modulation_Drv = rtb_Ref_Poses[((int32_T)
        Robot_Control_B.Spline_Num_Poses) + 9];
      for (i_0 = 0; i_0 < 50; i_0++) {
        /* Product: '<S92>/Product' incorporates:
         *  Constant: '<S92>/Constant2'
         */
        rtb_MatrixConcatenate_h[i_0] = rtb_Subtract_e;

        /* Product: '<S92>/Product1' incorporates:
         *  Constant: '<S92>/Constant2'
         *  Product: '<S92>/Product'
         */
        rtb_MatrixConcatenate_h[i_0 + 50] = rtb_Modulation_Drv;
      }

      /* Assignment: '<S92>/Assignment' incorporates:
       *  Concatenate: '<S90>/Matrix Concatenate'
       *  Concatenate: '<S92>/Matrix Concatenate'
       */
      memset(&rtb_MatrixConcatenate_o[0], 0, 450U * (sizeof(real_T)));
      memcpy(&rtb_MatrixConcatenate_o[0], &rtb_MatrixConcatenate_h[0], 50U *
             (sizeof(real_T)));
      memcpy(&rtb_MatrixConcatenate_o[50], &rtb_MatrixConcatenate_h[50], 50U *
             (sizeof(real_T)));

      /* SignalConversion generated from: '<S92>/Num_Segments' incorporates:
       *  Constant: '<S92>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S89>/If Action Subsystem' */
    }

    /* End of If: '<S89>/If1' */

    /* Concatenate: '<S90>/Matrix Concatenate' incorporates:
     *  Selector: '<S90>/Selector'
     *  Selector: '<S90>/Selector1'
     *  Selector: '<S90>/Selector3'
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

    /* MATLAB Function: '<S90>/Distance Along Curve' incorporates:
     *  Concatenate: '<S90>/Matrix Concatenate'
     *  Selector: '<S90>/Selector4'
     *  Selector: '<S90>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s115_iter = 0; s115_iter < 149; s115_iter++) {
      /* Outputs for Iterator SubSystem: '<S111>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S115>/While Iterator'
       */
      rtb_Assignment_d[s115_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s115_iter + 1] -
         rtb_MatrixConcatenate_o[s115_iter], rtb_MatrixConcatenate_o[s115_iter +
         151] - rtb_MatrixConcatenate_o[s115_iter + 150]) +
        rtb_Assignment_d[s115_iter];

      /* End of Outputs for SubSystem: '<S111>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S90>/Distance Along Curve' */

    /* MATLAB Function: '<S90>/Find closest index to curve' incorporates:
     *  Concatenate: '<S90>/Matrix Concatenate'
     *  Selector: '<S141>/Selector'
     *  Selector: '<S90>/Selector4'
     *  Selector: '<S90>/Selector5'
     */
    for (s115_iter = 0; s115_iter < 150; s115_iter++) {
      /* Outputs for Iterator SubSystem: '<S111>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S115>/While Iterator'
       */
      distance_from_robot[s115_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s115_iter] - Robot_Control_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s115_iter + 150] -
         Robot_Control_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S111>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s115_iter = 1;
    } else {
      s115_iter = 0;
      i = 2;
      exitg1 = false;
      while ((!exitg1) && (i < 151)) {
        if (!rtIsNaN(distance_from_robot[i - 1])) {
          s115_iter = i;
          exitg1 = true;
        } else {
          i++;
        }
      }
    }

    if (s115_iter == 0) {
      rtb_Subtract_e = distance_from_robot[0];
    } else {
      rtb_Subtract_e = distance_from_robot[s115_iter - 1];
      for (i = s115_iter + 1; i < 151; i++) {
        rtb_Modulation_Drv = distance_from_robot[i - 1];
        if (rtb_Subtract_e > rtb_Modulation_Drv) {
          rtb_Subtract_e = rtb_Modulation_Drv;
        }
      }
    }

    s115_iter = 1;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 150)) {
      s115_iter = i + 1;
      if (distance_from_robot[i] == rtb_Subtract_e) {
        exitg1 = true;
      } else {
        i++;
      }
    }

    /* Selector: '<S141>/Selector' incorporates:
     *  Constant: '<S141>/Constant'
     *  MATLAB Function: '<S90>/Find closest index to curve'
     *  MinMax: '<S141>/Min'
     */
    rtb_Modulation_Drv = rtb_Assignment_d[((int32_T)fmin(50.0, s115_iter)) - 1];

    /* If: '<S141>/If' incorporates:
     *  RelationalOperator: '<S141>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S141>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S144>/Action Port'
       */
      /* SignalConversion generated from: '<S144>/Lookup Table Dynamic' */
      rtb_TmpSignalConversionAtLookup[0] = rtb_Assignment_d[0];
      rtb_TmpSignalConversionAtLookup[1] = rtb_Assignment_d[49];

      /* Sum: '<S146>/FixPt Sum1' incorporates:
       *  Constant: '<S146>/FixPt Constant'
       */
      rtb_Subtract_e = Robot_Control_B.Spline_Follow_Index - 1.0;

      /* SignalConversion generated from: '<S144>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S8>/Merge8'
       *  Selector: '<S144>/Selector11'
       *  Selector: '<S144>/Selector12'
       */
      rtb_TmpSignalConversionAtLoo_mu[0] = rtb_Spline_Ref_Poses_h[((int32_T)
        rtb_Subtract_e) + 19];
      rtb_TmpSignalConversionAtLoo_mu[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 19];

      /* SignalConversion generated from: '<S144>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S8>/Merge8'
       *  Selector: '<S144>/Selector1'
       *  Selector: '<S144>/Selector2'
       */
      rtb_Add2[0] = rtb_Spline_Ref_Poses_h[((int32_T)rtb_Subtract_e) + 29];
      rtb_Add2[1] = rtb_Spline_Ref_Poses_h[((int32_T)
        Robot_Control_B.Spline_Follow_Index) + 29];

      /* S-Function (sfix_look1_dyn): '<S144>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S144>/Lookup Table Dynamic'
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

      /* SignalConversion: '<S144>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S144>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S144>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2[0], rtb_Modulation_Drv,
                           &rtb_TmpSignalConversionAtLookup[0], 1U);

      /* End of Outputs for SubSystem: '<S141>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S141>/Latch' incorporates:
       *  ActionPort: '<S145>/Action Port'
       */
      /* SignalConversion generated from: '<S145>/In1' incorporates:
       *  UnitDelay: '<S141>/Unit Delay1'
       */
      rtb_Subtract_e = Robot_Control_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S145>/In2' incorporates:
       *  UnitDelay: '<S141>/Unit Delay'
       */
      rtb_Merge1 = Robot_Control_DW.UnitDelay_DSTATE_g4;

      /* End of Outputs for SubSystem: '<S141>/Latch' */
    }

    /* End of If: '<S141>/If' */

    /* MinMax: '<S88>/Min' incorporates:
     *  Lookup_n-D: '<S88>/Lookahead Distance'
     *  UnitDelay: '<S88>/Unit Delay'
     */
    rtb_Saturation_h = fmin(rtb_Saturation_h, look1_binlcpw
      (Robot_Control_DW.UnitDelay_DSTATE_h, rtCP_LookaheadDistance_bp01Data,
       rtCP_LookaheadDistance_tableDat, 3U));

    /* Outputs for Iterator SubSystem: '<S90>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S140>/While Iterator'
     */
    s140_iter = 1U;
    rtb_LogicalOperator5 = true;
    while (rtb_LogicalOperator5 && (s140_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S90>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S140>/While Iterator'
       */
      Robot_Control_B.WhileIterator = s140_iter;
      rtb_LogicalOperator5 = ((rtb_Assignment_d[Robot_Control_B.WhileIterator -
        1] <= (rtb_Assignment_d[s115_iter - 1] + rtb_Saturation_h)) &&
        (Robot_Control_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s140_iter++;
    }

    /* End of Outputs for SubSystem: '<S90>/Find first index that meets distance target' */

    /* Switch: '<S143>/Switch' incorporates:
     *  Concatenate: '<S90>/Matrix Concatenate'
     *  Constant: '<S140>/Constant'
     *  Constant: '<S143>/Constant'
     *  Constant: '<S143>/Constant1'
     *  Constant: '<S143>/Constant2'
     *  Constant: '<S143>/Constant3'
     *  Constant: '<S90>/Constant'
     *  Logic: '<S140>/AND'
     *  MATLAB Function: '<S90>/Find closest index to curve'
     *  Math: '<S143>/Hypot'
     *  Merge: '<S8>/Merge8'
     *  MinMax: '<S143>/Max'
     *  MinMax: '<S143>/Min'
     *  MinMax: '<S143>/Min1'
     *  Product: '<S140>/Product'
     *  Product: '<S143>/Divide'
     *  Product: '<S143>/Product'
     *  Product: '<S143>/Product1'
     *  RelationalOperator: '<S140>/Relational Operator'
     *  RelationalOperator: '<S140>/Relational Operator1'
     *  RelationalOperator: '<S90>/Relational Operator'
     *  Selector: '<S140>/Selector'
     *  Selector: '<S140>/Selector1'
     *  Selector: '<S141>/Selector'
     *  Selector: '<S90>/Selector10'
     *  Selector: '<S90>/Selector7'
     *  Selector: '<S90>/Selector8'
     *  Selector: '<S90>/Selector9'
     *  Sqrt: '<S143>/Sqrt'
     *  Sum: '<S140>/Add'
     *  Sum: '<S143>/Subtract'
     *  Sum: '<S143>/Subtract1'
     *  Sum: '<S90>/Subtract'
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

    /* End of Switch: '<S143>/Switch' */

    /* Logic: '<S91>/OR' */
    rtb_Compare_mq = (rtb_LogicalOperator1 ||
                      (Robot_Control_B.Spline_Out_Of_Bounds));

    /* Switch: '<S91>/Switch1' incorporates:
     *  Switch: '<S91>/Switch'
     *  UnitDelay: '<S91>/Unit Delay'
     */
    if (rtb_Compare_mq) {
      /* Merge: '<S10>/Merge2' incorporates:
       *  Constant: '<S91>/Constant3'
       *  SignalConversion: '<S91>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = 0.0;
      rtb_Modulation_Drv = Robot_Control_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S10>/Merge2' incorporates:
       *  SignalConversion: '<S91>/Signal Copy1'
       */
      Robot_Control_B.Translation_Speed_SPF = rtb_Saturation_h;
      rtb_Modulation_Drv = rtb_Merge1;
    }

    /* End of Switch: '<S91>/Switch1' */

    /* Merge: '<S10>/Merge' incorporates:
     *  SignalConversion: '<S91>/Signal Copy'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = rtb_Modulation_Drv;

    /* Selector: '<S90>/Selector6' incorporates:
     *  Concatenate: '<S90>/Matrix Concatenate'
     *  Selector: '<S90>/Selector5'
     */
    Robot_Control_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator + 149];

    /* Selector: '<S90>/Selector2' incorporates:
     *  Concatenate: '<S90>/Matrix Concatenate'
     *  Selector: '<S90>/Selector4'
     */
    Robot_Control_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Robot_Control_B.WhileIterator - 1];

    /* Switch: '<S91>/Switch2' incorporates:
     *  Sum: '<S147>/Subtract'
     *  Sum: '<S147>/Subtract1'
     *  Trigonometry: '<S147>/Atan2'
     *  UnitDelay: '<S91>/Unit Delay1'
     */
    if (rtb_Compare_mq) {
      rtb_Switch1_c = Robot_Control_DW.UnitDelay1_DSTATE_k;
    } else {
      rtb_Switch1_c = rt_atan2d_snf(Robot_Control_B.Spline_Target_Y -
        Robot_Control_B.KF_Position_Y, Robot_Control_B.Spline_Target_X -
        Robot_Control_B.KF_Position_X);
    }

    /* End of Switch: '<S91>/Switch2' */

    /* Merge: '<S10>/Merge3' incorporates:
     *  SignalConversion: '<S91>/Signal Copy2'
     */
    Robot_Control_B.Translation_Angle_SPF = rtb_Switch1_c;

    /* Merge: '<S10>/Merge7' incorporates:
     *  SignalConversion: '<S88>/Signal Copy'
     */
    Robot_Control_B.Robot_Reached_Destination = rtb_LogicalOperator1;

    /* Merge: '<S10>/Merge6' incorporates:
     *  SignalConversion: '<S88>/Signal Copy1'
     */
    Robot_Control_B.Spline_Index = Robot_Control_B.Spline_Follow_Index;

    /* Merge: '<S10>/Merge1' incorporates:
     *  Constant: '<S91>/Constant2'
     *  SignalConversion generated from: '<S88>/Steering_Rel_Cmd'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S10>/Merge4' incorporates:
     *  Constant: '<S91>/Constant5'
     *  SignalConversion generated from: '<S88>/Is_Absolute_Translation'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S10>/Merge5' incorporates:
     *  Constant: '<S91>/Constant6'
     *  SignalConversion generated from: '<S88>/Is_Absolute_Steering'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S10>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_Field_rad'
     *  SignalConversion generated from: '<S88>/Gyro_Angle_Field_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_Field_rad;

    /* Update for UnitDelay: '<S89>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_gh = Robot_Control_B.Spline_Follow_Index;

    /* Update for UnitDelay: '<S88>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_h = rtb_Saturation_h;

    /* Update for UnitDelay: '<S141>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_f4 = rtb_Subtract_e;

    /* Update for UnitDelay: '<S141>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_g4 = rtb_Merge1;

    /* Update for UnitDelay: '<S91>/Unit Delay' */
    Robot_Control_DW.UnitDelay_DSTATE_le = rtb_Modulation_Drv;

    /* Update for UnitDelay: '<S91>/Unit Delay1' */
    Robot_Control_DW.UnitDelay1_DSTATE_k = rtb_Switch1_c;

    /* End of Outputs for SubSystem: '<S10>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/Pass Through' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    /* Merge: '<S10>/Merge6' incorporates:
     *  Constant: '<S87>/Constant1'
     *  SignalConversion generated from: '<S87>/Spline_Index'
     */
    Robot_Control_B.Spline_Index = 1.0;

    /* Merge: '<S10>/Merge7' incorporates:
     *  Constant: '<S87>/Constant'
     *  SignalConversion generated from: '<S87>/Robot_Reached_Destination'
     */
    Robot_Control_B.Robot_Reached_Destination = true;

    /* Merge: '<S10>/Merge' incorporates:
     *  SignalConversion generated from: '<S87>/Steering_Abs_Cmd_In'
     */
    Robot_Control_B.Steering_Abs_Cmd_SPF = Robot_Control_B.Steering_Abs_Cmd;

    /* Merge: '<S10>/Merge1' incorporates:
     *  SignalConversion generated from: '<S87>/Steering_Rel_Cmd_In'
     */
    Robot_Control_B.Steering_Rel_Cmd_SPF = Robot_Control_B.Steering_Rel_Cmd;

    /* Merge: '<S10>/Merge2' incorporates:
     *  SignalConversion generated from: '<S87>/Translation_Speed_In'
     */
    Robot_Control_B.Translation_Speed_SPF = Robot_Control_B.Translation_Speed;

    /* Merge: '<S10>/Merge3' incorporates:
     *  SignalConversion generated from: '<S87>/Translation_Angle_In'
     */
    Robot_Control_B.Translation_Angle_SPF = Robot_Control_B.Translation_Angle;

    /* Merge: '<S10>/Merge4' incorporates:
     *  SignalConversion generated from: '<S87>/Is_Absolute_Translation_In'
     */
    Robot_Control_B.Is_Absolute_Translation_SPF = rtb_Compare_ph;

    /* Merge: '<S10>/Merge5' incorporates:
     *  SignalConversion generated from: '<S87>/Is_Absolute_Steering_In'
     */
    Robot_Control_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S10>/Merge8' incorporates:
     *  Inport: '<Root>/Gyro_Angle_rad'
     *  SignalConversion generated from: '<S87>/Gyro_Angle_rad'
     */
    Robot_Control_B.Gyro_Angle_SPF = Robot_Control_U.Gyro_Angle_rad;

    /* End of Outputs for SubSystem: '<S10>/Pass Through' */
  }

  /* End of If: '<S10>/If' */

  /* Signum: '<S237>/Sign2' incorporates:
   *  UnitDelay: '<S237>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_RL)) {
    u0 = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_RL < 0.0) {
    u0 = -1.0;
  } else {
    u0 = (Robot_Control_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S237>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Translation_Speed_SPF)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_B.Translation_Speed_SPF < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S237>/Product1' incorporates:
   *  Signum: '<S237>/Sign1'
   *  Signum: '<S237>/Sign2'
   */
  u0 *= rtb_Product_lb;
  if (rtIsNaN(u0)) {
    i_0 = 0;
  } else {
    i_0 = (int32_T)fmod(u0, 256.0);
  }

  /* Switch: '<S237>/Switch' incorporates:
   *  Constant: '<S237>/Constant'
   *  Constant: '<S242>/Constant'
   *  Constant: '<S243>/Constant'
   *  Logic: '<S237>/or'
   *  Product: '<S237>/Product1'
   *  RelationalOperator: '<S242>/Compare'
   *  RelationalOperator: '<S243>/Compare'
   *  UnitDelay: '<S237>/Unit Delay'
   */
  if ((Robot_Control_B.Translation_Speed_RL == 0.0) || (((i_0 < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i_0))))))) : i_0) > 0)) {
    rtb_uDLookupTable = Robot_Control_B.Translation_Speed_SPF;
  } else {
    rtb_uDLookupTable = 0.0;
  }

  /* End of Switch: '<S237>/Switch' */

  /* Switch: '<S248>/Init' incorporates:
   *  UnitDelay: '<S248>/FixPt Unit Delay1'
   *  UnitDelay: '<S248>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Switch1_c = rtb_uDLookupTable;
  } else {
    rtb_Switch1_c = Robot_Control_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S248>/Init' */

  /* RelationalOperator: '<S244>/Compare' incorporates:
   *  Constant: '<S244>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_uDLookupTable == 0.0);

  /* RelationalOperator: '<S245>/Compare' incorporates:
   *  Constant: '<S245>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_uDLookupTable > 0.0);

  /* Abs: '<S237>/Abs' incorporates:
   *  Sum: '<S237>/Subtract'
   *  UnitDelay: '<S237>/Unit Delay'
   */
  rtb_Merge1 = fabs(Robot_Control_B.Translation_Speed_RL -
                    Robot_Control_B.Translation_Speed_SPF);

  /* Switch: '<S237>/Switch1' incorporates:
   *  Constant: '<S237>/Constant1'
   *  Switch: '<S237>/Switch3'
   *  Switch: '<S237>/Switch5'
   *  UnaryMinus: '<S237>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    rtb_Subtract_e = -Translation_Speed_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S237>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S237>/Constant1'
     *  Constant: '<S237>/Constant4'
     *  Constant: '<S237>/Constant6'
     *  UnaryMinus: '<S237>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S237>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S237>/Constant2'
     *  Constant: '<S237>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S237>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S237>/Lookup Table Dynamic'
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
      /* Switch: '<S237>/Switch3' incorporates:
       *  Constant: '<S237>/Constant3'
       */
      rtb_Subtract_e = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Subtract_e = -Translation_Speed_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S237>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S237>/Constant1'
     *  Constant: '<S237>/Constant10'
     *  Constant: '<S237>/Constant8'
     *  UnaryMinus: '<S237>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S237>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S237>/Constant7'
     *  Constant: '<S237>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S237>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S237>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S237>/Switch1' */

  /* Product: '<S237>/Product' */
  rtb_Subtract_e *= rtb_Merge1;

  /* Sum: '<S246>/Sum1' */
  rtb_Saturation_h = rtb_uDLookupTable - rtb_Switch1_c;

  /* Switch: '<S247>/Switch2' incorporates:
   *  RelationalOperator: '<S247>/LowerRelop1'
   */
  if (!(rtb_Saturation_h > rtb_Subtract_e)) {
    /* Switch: '<S237>/Switch2' incorporates:
     *  Constant: '<S237>/Constant1'
     *  Switch: '<S237>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_Subtract_e = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S237>/Switch4' incorporates:
       *  Constant: '<S237>/Constant1'
       */
      rtb_Subtract_e = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S237>/Switch4' incorporates:
       *  Constant: '<S237>/Constant3'
       *  UnaryMinus: '<S237>/Unary Minus1'
       */
      rtb_Subtract_e = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S237>/Switch2' */

    /* Product: '<S237>/Product2' */
    rtb_Subtract_e *= rtb_Merge1;

    /* Switch: '<S247>/Switch' incorporates:
     *  RelationalOperator: '<S247>/UpperRelop'
     */
    if (!(rtb_Saturation_h < rtb_Subtract_e)) {
      rtb_Subtract_e = rtb_Saturation_h;
    }

    /* End of Switch: '<S247>/Switch' */
  }

  /* End of Switch: '<S247>/Switch2' */

  /* Sum: '<S246>/Sum' */
  Robot_Control_B.Translation_Speed_RL = rtb_Subtract_e + rtb_Switch1_c;

  /* Switch: '<S240>/Switch' */
  if (Robot_Control_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S274>/Constant3'
     *  Constant: '<S274>/Constant4'
     *  Math: '<S274>/Math Function'
     *  Sum: '<S240>/Subtract'
     *  Sum: '<S274>/Add1'
     *  Sum: '<S274>/Add2'
     */
    Robot_Control_B.Translation_Steering_Cmd = rt_modd_snf
      ((Robot_Control_B.Translation_Angle_SPF - Robot_Control_B.Gyro_Angle_SPF)
       + 3.141592653589793, 6.283185307179586) - 3.141592653589793;
  } else {
    /* Switch: '<S240>/Switch' */
    Robot_Control_B.Translation_Steering_Cmd =
      Robot_Control_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S240>/Switch' */

  /* Sum: '<S269>/Add1' incorporates:
   *  Constant: '<S269>/Constant3'
   *  Constant: '<S269>/Constant4'
   *  Math: '<S269>/Math Function'
   *  Sum: '<S268>/Sum'
   *  Sum: '<S269>/Add2'
   */
  rtb_Switch1_c = rt_modd_snf((Robot_Control_B.Steering_Abs_Cmd_SPF -
    Robot_Control_B.Gyro_Angle_SPF) + 3.141592653589793, 6.283185307179586) -
    3.141592653589793;

  /* Gain: '<S272>/Gain' */
  Robot_Control_B.Steering_Heading_Error_deg = 57.29577951308232 * rtb_Switch1_c;

  /* Sum: '<S271>/Sum1' incorporates:
   *  Constant: '<S268>/Constant2'
   *  Product: '<S271>/Product'
   *  Sum: '<S271>/Sum'
   *  UnitDelay: '<S271>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_Switch1_c - Robot_Control_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE;

  /* Product: '<S268>/Product' incorporates:
   *  Constant: '<S268>/Constant3'
   */
  rtb_Saturation_h = rtb_Merge1 * Steering_Heading_Control_D;

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
  u0 = rtb_Saturation_h - Robot_Control_DW.UD_DSTATE;

  /* Saturate: '<S268>/Saturation' */
  if (u0 > Steering_Heading_Control_D_UL) {
    u0 = Steering_Heading_Control_D_UL;
  } else if (u0 < Steering_Heading_Control_D_LL) {
    u0 = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S268>/Add' incorporates:
   *  Gain: '<S268>/Gain1'
   *  Saturate: '<S268>/Saturation'
   */
  rtb_UnitDelay3 = (Steering_Heading_Control_P * rtb_Switch1_c) + u0;

  /* Sum: '<S268>/Subtract' incorporates:
   *  Constant: '<S268>/Constant'
   */
  rtb_Subtract_e = Steering_Heading_Control_Total_UL - rtb_UnitDelay3;

  /* Sum: '<S268>/Sum2' incorporates:
   *  Gain: '<S268>/Gain2'
   *  UnitDelay: '<S268>/Unit Delay'
   */
  rtb_Switch1_c = (Steering_Heading_Control_I * rtb_Switch1_c) +
    Robot_Control_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S273>/Switch2' incorporates:
   *  RelationalOperator: '<S273>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_Subtract_e)) {
    /* Sum: '<S268>/Subtract1' incorporates:
     *  Constant: '<S268>/Constant1'
     */
    rtb_Subtract_e = Steering_Heading_Control_Total_LL - rtb_UnitDelay3;

    /* Switch: '<S273>/Switch' incorporates:
     *  RelationalOperator: '<S273>/UpperRelop'
     */
    if (!(rtb_Switch1_c < rtb_Subtract_e)) {
      rtb_Subtract_e = rtb_Switch1_c;
    }

    /* End of Switch: '<S273>/Switch' */
  }

  /* End of Switch: '<S273>/Switch2' */

  /* Saturate: '<S268>/Saturation1' */
  if (rtb_Subtract_e > Steering_Heading_Control_I_UL) {
    rtb_Subtract_e = Steering_Heading_Control_I_UL;
  } else if (rtb_Subtract_e < Steering_Heading_Control_I_LL) {
    rtb_Subtract_e = Steering_Heading_Control_I_LL;
  }

  /* End of Saturate: '<S268>/Saturation1' */

  /* Sum: '<S268>/Add1' */
  u0 = rtb_UnitDelay3 + rtb_Subtract_e;

  /* Saturate: '<S268>/Saturation2' */
  if (u0 > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S268>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_UL;
  } else if (u0 < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S268>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S268>/Saturation2' */
    Robot_Control_B.Steering_Heading_PID = u0;
  }

  /* End of Saturate: '<S268>/Saturation2' */

  /* Abs: '<S251>/Abs' */
  rtb_Switch1_c = fabs(Robot_Control_B.Steering_Heading_PID);

  /* Chart: '<S251>/Add dither' */
  if (Robot_Control_DW.is_active_c7_Robot_Control == 0) {
    Robot_Control_DW.is_active_c7_Robot_Control = 1U;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c;
  } else if (Robot_Control_DW.is_c7_Robot_Control == Robot_Control_IN_Dither) {
    Robot_Control_DW.is_Dither = Robot_Contro_IN_NO_ACTIVE_CHILD;
    Robot_Control_DW.is_c7_Robot_Control = Robot_Control_IN_No_Dither;
    Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c;
  } else {
    /* case IN_No_Dither: */
    Robot_Control_B.abs_Cmd_Out = rtb_Switch1_c;
  }

  /* End of Chart: '<S251>/Add dither' */

  /* Switch: '<S251>/Switch' incorporates:
   *  Constant: '<S251>/Constant'
   *  Constant: '<S267>/Constant'
   *  Product: '<S251>/Product'
   *  RelationalOperator: '<S267>/Compare'
   *  Signum: '<S251>/Sign'
   */
  if (rtb_Switch1_c > Steering_Heading_Control_Deadzone) {
    /* Signum: '<S251>/Sign' */
    if (rtIsNaN(Robot_Control_B.Steering_Heading_PID)) {
      u0 = (rtNaN);
    } else if (Robot_Control_B.Steering_Heading_PID < 0.0) {
      u0 = -1.0;
    } else {
      u0 = (Robot_Control_B.Steering_Heading_PID > 0.0);
    }

    rtb_Switch1_c = Robot_Control_B.abs_Cmd_Out * u0;
  } else {
    rtb_Switch1_c = 0.0;
  }

  /* End of Switch: '<S251>/Switch' */

  /* Signum: '<S250>/Sign2' incorporates:
   *  UnitDelay: '<S250>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_d4)) {
    u0 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_d4 < 0.0) {
    u0 = -1.0;
  } else {
    u0 = (Robot_Control_DW.UnitDelay_DSTATE_d4 > 0.0);
  }

  /* Signum: '<S250>/Sign1' */
  if (rtIsNaN(rtb_Switch1_c)) {
    rtb_Product_lb = (rtNaN);
  } else if (rtb_Switch1_c < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (rtb_Switch1_c > 0.0);
  }

  /* Product: '<S250>/Product1' incorporates:
   *  Signum: '<S250>/Sign1'
   *  Signum: '<S250>/Sign2'
   */
  u0 *= rtb_Product_lb;
  if (rtIsNaN(u0)) {
    i_0 = 0;
  } else {
    i_0 = (int32_T)fmod(u0, 256.0);
  }

  /* Switch: '<S250>/Switch' incorporates:
   *  Constant: '<S250>/Constant'
   *  Constant: '<S259>/Constant'
   *  Constant: '<S260>/Constant'
   *  Logic: '<S250>/or'
   *  Product: '<S250>/Product1'
   *  RelationalOperator: '<S259>/Compare'
   *  RelationalOperator: '<S260>/Compare'
   *  UnitDelay: '<S250>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_d4 == 0.0) || (((i_0 < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i_0))))))) : i_0) > 0)) {
    rtb_Switch2_p = rtb_Switch1_c;
  } else {
    rtb_Switch2_p = 0.0;
  }

  /* End of Switch: '<S250>/Switch' */

  /* Switch: '<S265>/Init' incorporates:
   *  UnitDelay: '<S265>/FixPt Unit Delay1'
   *  UnitDelay: '<S265>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_p != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S265>/Init' */

  /* RelationalOperator: '<S261>/Compare' incorporates:
   *  Constant: '<S261>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Switch2_p == 0.0);

  /* RelationalOperator: '<S262>/Compare' incorporates:
   *  Constant: '<S262>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Switch2_p > 0.0);

  /* Abs: '<S250>/Abs' incorporates:
   *  Sum: '<S250>/Subtract'
   *  UnitDelay: '<S250>/Unit Delay'
   */
  rtb_Modulation_Drv = fabs(Robot_Control_DW.UnitDelay_DSTATE_d4 - rtb_Switch1_c);

  /* Switch: '<S250>/Switch1' incorporates:
   *  Constant: '<S250>/Constant1'
   *  Switch: '<S250>/Switch3'
   *  Switch: '<S250>/Switch5'
   *  UnaryMinus: '<S250>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    rtb_UnitDelay3 = -Steering_Absolute_Cmd_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S250>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S250>/Constant1'
     *  Constant: '<S250>/Constant4'
     *  Constant: '<S250>/Constant6'
     *  UnaryMinus: '<S250>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S250>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S250>/Constant2'
     *  Constant: '<S250>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S250>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S250>/Lookup Table Dynamic'
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
      /* Switch: '<S250>/Switch3' incorporates:
       *  Constant: '<S250>/Constant3'
       */
      rtb_UnitDelay3 = Steering_Absolute_Cmd_Rate_Limit_Inc;
    } else {
      rtb_UnitDelay3 = -Steering_Absolute_Cmd_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S250>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S250>/Constant1'
     *  Constant: '<S250>/Constant10'
     *  Constant: '<S250>/Constant8'
     *  UnaryMinus: '<S250>/Unary Minus'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S250>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S250>/Constant7'
     *  Constant: '<S250>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Absolute_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S250>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S250>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S250>/Switch1' */

  /* Product: '<S250>/Product' */
  rtb_UnitDelay3 *= rtb_Modulation_Drv;

  /* Sum: '<S263>/Sum1' */
  rtb_Switch1_c = rtb_Switch2_p - rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S264>/Switch2' incorporates:
   *  RelationalOperator: '<S264>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_UnitDelay3)) {
    /* Switch: '<S250>/Switch2' incorporates:
     *  Constant: '<S250>/Constant1'
     *  Switch: '<S250>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_UnitDelay3 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S250>/Switch4' incorporates:
       *  Constant: '<S250>/Constant1'
       */
      rtb_UnitDelay3 = Steering_Absolute_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S250>/Switch4' incorporates:
       *  Constant: '<S250>/Constant3'
       *  UnaryMinus: '<S250>/Unary Minus1'
       */
      rtb_UnitDelay3 = -Steering_Absolute_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S250>/Switch2' */

    /* Product: '<S250>/Product2' */
    rtb_UnitDelay3 *= rtb_Modulation_Drv;

    /* Switch: '<S264>/Switch' incorporates:
     *  RelationalOperator: '<S264>/UpperRelop'
     */
    if (!(rtb_Switch1_c < rtb_UnitDelay3)) {
      rtb_UnitDelay3 = rtb_Switch1_c;
    }

    /* End of Switch: '<S264>/Switch' */
  }

  /* End of Switch: '<S264>/Switch2' */

  /* Sum: '<S263>/Sum' */
  rtb_Modulation_Drv = rtb_UnitDelay3 + rtb_MatrixConcatenate_b_idx_0;

  /* Signum: '<S249>/Sign2' incorporates:
   *  UnitDelay: '<S249>/Unit Delay'
   */
  if (rtIsNaN(Robot_Control_DW.UnitDelay_DSTATE_g)) {
    u0 = (rtNaN);
  } else if (Robot_Control_DW.UnitDelay_DSTATE_g < 0.0) {
    u0 = -1.0;
  } else {
    u0 = (Robot_Control_DW.UnitDelay_DSTATE_g > 0.0);
  }

  /* Signum: '<S249>/Sign1' */
  if (rtIsNaN(Robot_Control_B.Steering_Rel_Cmd_SPF)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_B.Steering_Rel_Cmd_SPF < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_B.Steering_Rel_Cmd_SPF > 0.0);
  }

  /* Product: '<S249>/Product1' incorporates:
   *  Signum: '<S249>/Sign1'
   *  Signum: '<S249>/Sign2'
   */
  u0 *= rtb_Product_lb;
  if (rtIsNaN(u0)) {
    i_0 = 0;
  } else {
    i_0 = (int32_T)fmod(u0, 256.0);
  }

  /* Switch: '<S249>/Switch' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S252>/Constant'
   *  Constant: '<S253>/Constant'
   *  Logic: '<S249>/or'
   *  Product: '<S249>/Product1'
   *  RelationalOperator: '<S252>/Compare'
   *  RelationalOperator: '<S253>/Compare'
   *  UnitDelay: '<S249>/Unit Delay'
   */
  if ((Robot_Control_DW.UnitDelay_DSTATE_g == 0.0) || (((i_0 < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i_0))))))) : i_0) > 0)) {
    rtb_Switch2_p = Robot_Control_B.Steering_Rel_Cmd_SPF;
  } else {
    rtb_Switch2_p = 0.0;
  }

  /* End of Switch: '<S249>/Switch' */

  /* Switch: '<S258>/Init' incorporates:
   *  UnitDelay: '<S258>/FixPt Unit Delay1'
   *  UnitDelay: '<S258>/FixPt Unit Delay2'
   */
  if (Robot_Control_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_DW.FixPtUnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S258>/Init' */

  /* RelationalOperator: '<S254>/Compare' incorporates:
   *  Constant: '<S254>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Switch2_p == 0.0);

  /* RelationalOperator: '<S255>/Compare' incorporates:
   *  Constant: '<S255>/Constant'
   */
  rtb_LogicalOperator5 = (rtb_Switch2_p > 0.0);

  /* Abs: '<S249>/Abs' incorporates:
   *  Sum: '<S249>/Subtract'
   *  UnitDelay: '<S249>/Unit Delay'
   */
  rtb_UnitDelay3 = fabs(Robot_Control_DW.UnitDelay_DSTATE_g -
                        Robot_Control_B.Steering_Rel_Cmd_SPF);

  /* Switch: '<S249>/Switch5' incorporates:
   *  Constant: '<S249>/Constant1'
   *  Switch: '<S249>/Switch1'
   *  UnaryMinus: '<S249>/Unary Minus'
   */
  if (rtb_LogicalOperator1) {
    /* SignalConversion generated from: '<S249>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S249>/Constant4'
     *  Constant: '<S249>/Constant6'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S249>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S249>/Constant2'
     *  Constant: '<S249>/Constant5'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Relative_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S249>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S249>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_UnitDelay3,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Switch5_o = rtb_LookupTableDynamic_p;
    u0 = -Steering_Relative_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S249>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S249>/Constant10'
     *  Constant: '<S249>/Constant8'
     */
    rtb_TmpSignalConversionAtLookup[0] =
      Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
    rtb_TmpSignalConversionAtLookup[1] = 1.0;

    /* SignalConversion generated from: '<S249>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S249>/Constant7'
     *  Constant: '<S249>/Constant9'
     */
    rtb_TmpSignalConversionAtLoo_mu[0] = 0.0;
    rtb_TmpSignalConversionAtLoo_mu[1] =
      Steering_Relative_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S249>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S249>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_g),
                         &rtb_TmpSignalConversionAtLookup[0], rtb_UnitDelay3,
                         &rtb_TmpSignalConversionAtLoo_mu[0], 1U);
    rtb_Switch5_o = rtb_LookupTableDynamic1_g;

    /* Switch: '<S249>/Switch3' incorporates:
     *  Constant: '<S249>/Constant1'
     *  Constant: '<S249>/Constant3'
     *  UnaryMinus: '<S249>/Unary Minus'
     */
    if (rtb_LogicalOperator5) {
      u0 = Steering_Relative_Cmd_Rate_Limit_Inc;
    } else {
      u0 = -Steering_Relative_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S249>/Switch3' */
  }

  /* End of Switch: '<S249>/Switch5' */

  /* Product: '<S249>/Product' incorporates:
   *  Switch: '<S249>/Switch1'
   */
  rtb_UnitDelay3 = u0 * rtb_Switch5_o;

  /* Sum: '<S256>/Sum1' */
  rtb_Switch1_c = rtb_Switch2_p - rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S257>/Switch2' incorporates:
   *  RelationalOperator: '<S257>/LowerRelop1'
   */
  if (!(rtb_Switch1_c > rtb_UnitDelay3)) {
    /* Switch: '<S249>/Switch2' incorporates:
     *  Constant: '<S249>/Constant1'
     *  Switch: '<S249>/Switch4'
     */
    if (rtb_LogicalOperator1) {
      rtb_UnitDelay3 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else if (rtb_LogicalOperator5) {
      /* Switch: '<S249>/Switch4' incorporates:
       *  Constant: '<S249>/Constant1'
       */
      rtb_UnitDelay3 = Steering_Relative_Cmd_Rate_Limit_Dec;
    } else {
      /* Switch: '<S249>/Switch4' incorporates:
       *  Constant: '<S249>/Constant3'
       *  UnaryMinus: '<S249>/Unary Minus1'
       */
      rtb_UnitDelay3 = -Steering_Relative_Cmd_Rate_Limit_Inc;
    }

    /* End of Switch: '<S249>/Switch2' */

    /* Product: '<S249>/Product2' */
    rtb_UnitDelay3 *= rtb_Switch5_o;

    /* Switch: '<S257>/Switch' incorporates:
     *  RelationalOperator: '<S257>/UpperRelop'
     */
    if (!(rtb_Switch1_c < rtb_UnitDelay3)) {
      rtb_UnitDelay3 = rtb_Switch1_c;
    }

    /* End of Switch: '<S257>/Switch' */
  }

  /* End of Switch: '<S257>/Switch2' */

  /* Sum: '<S256>/Sum' */
  rtb_Switch1_c = rtb_UnitDelay3 + rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S239>/Switch' */
  if (Robot_Control_B.Is_Absolute_Steering_SPF) {
    /* Switch: '<S239>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Modulation_Drv;
  } else {
    /* Switch: '<S239>/Switch' */
    Robot_Control_B.Steering_Localized_Cmd = rtb_Switch1_c;
  }

  /* End of Switch: '<S239>/Switch' */

  /* Fcn: '<S282>/r->x' incorporates:
   *  Fcn: '<S287>/r->x'
   *  Fcn: '<S292>/r->x'
   *  Fcn: '<S297>/r->x'
   */
  rtb_UnitDelay3 = cos(Robot_Control_B.Translation_Steering_Cmd);
  rtb_Switch5_o = Robot_Control_B.Translation_Speed_RL * rtb_UnitDelay3;

  /* Sum: '<S276>/Add' incorporates:
   *  Fcn: '<S282>/r->x'
   *  Fcn: '<S283>/r->x'
   */
  rtb_TmpSignalConversionAtLookup[0] = (Robot_Control_B.Steering_Localized_Cmd *
    cos(Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_Switch5_o;

  /* Fcn: '<S282>/theta->y' incorporates:
   *  Fcn: '<S287>/theta->y'
   *  Fcn: '<S292>/theta->y'
   *  Fcn: '<S297>/theta->y'
   */
  rtb_UnitDelay3 = Robot_Control_B.Translation_Speed_RL * sin
    (Robot_Control_B.Translation_Steering_Cmd);

  /* Sum: '<S276>/Add' incorporates:
   *  Fcn: '<S282>/theta->y'
   *  Fcn: '<S283>/theta->y'
   */
  rtb_TmpSignalConversionAtLookup[1] = (Robot_Control_B.Steering_Localized_Cmd *
    sin(Robot_Control_ConstB.FL_Tangent_Angle)) + rtb_UnitDelay3;

  /* Sum: '<S277>/Add' incorporates:
   *  Fcn: '<S288>/r->x'
   *  Fcn: '<S288>/theta->y'
   */
  rtb_TmpSignalConversionAtLoo_mu[0] = (Robot_Control_B.Steering_Localized_Cmd *
    cos(Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_Switch5_o;
  rtb_TmpSignalConversionAtLoo_mu[1] = (Robot_Control_B.Steering_Localized_Cmd *
    sin(Robot_Control_ConstB.FR_Tangent_Angle)) + rtb_UnitDelay3;

  /* Sum: '<S278>/Add' incorporates:
   *  Fcn: '<S293>/r->x'
   *  Fcn: '<S293>/theta->y'
   */
  rtb_Add2[0] = (Robot_Control_B.Steering_Localized_Cmd * cos
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_Switch5_o;
  rtb_Add2[1] = (Robot_Control_B.Steering_Localized_Cmd * sin
                 (Robot_Control_ConstB.BL_Tangent_Angle)) + rtb_UnitDelay3;

  /* Sum: '<S279>/Add' incorporates:
   *  Fcn: '<S298>/r->x'
   *  Fcn: '<S298>/theta->y'
   */
  rtb_Minus_k_idx_0 = (Robot_Control_B.Steering_Localized_Cmd * cos
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_Switch5_o;
  rtb_Minus_k_idx_1 = (Robot_Control_B.Steering_Localized_Cmd * sin
                       (Robot_Control_ConstB.BR_Tangent_Angle)) + rtb_UnitDelay3;

  /* Fcn: '<S296>/x->r' */
  rtb_UnitDelay3 = rt_hypotd_snf(rtb_Minus_k_idx_0, rtb_Minus_k_idx_1);

  /* RelationalOperator: '<S299>/Compare' incorporates:
   *  Constant: '<S299>/Constant'
   */
  rtb_Compare_ph = (rtb_UnitDelay3 == 0.0);

  /* Switch: '<S295>/Switch1' */
  if (rtb_Compare_ph) {
    /* Switch: '<S295>/Switch1' incorporates:
     *  Constant: '<S295>/Constant'
     */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S295>/Switch1' */
    Robot_Control_B.BR_Desired_Wheel_Speed_in = rtb_UnitDelay3;
  }

  /* End of Switch: '<S295>/Switch1' */

  /* Fcn: '<S281>/x->r' */
  rtb_UnitDelay3 = rt_hypotd_snf(rtb_TmpSignalConversionAtLookup[0],
    rtb_TmpSignalConversionAtLookup[1]);

  /* RelationalOperator: '<S284>/Compare' incorporates:
   *  Constant: '<S284>/Constant'
   */
  rtb_Compare_mq = (rtb_UnitDelay3 == 0.0);

  /* Switch: '<S280>/Switch1' */
  if (rtb_Compare_mq) {
    /* Switch: '<S280>/Switch1' incorporates:
     *  Constant: '<S280>/Constant'
     */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S280>/Switch1' */
    Robot_Control_B.FL_Desired_Wheel_Speed_in = rtb_UnitDelay3;
  }

  /* End of Switch: '<S280>/Switch1' */

  /* Fcn: '<S286>/x->r' */
  rtb_Switch2_p = rt_hypotd_snf(rtb_TmpSignalConversionAtLoo_mu[0],
    rtb_TmpSignalConversionAtLoo_mu[1]);

  /* RelationalOperator: '<S289>/Compare' incorporates:
   *  Constant: '<S289>/Constant'
   */
  rtb_Compare_ky = (rtb_Switch2_p == 0.0);

  /* Switch: '<S285>/Switch1' */
  if (rtb_Compare_ky) {
    /* Switch: '<S285>/Switch1' incorporates:
     *  Constant: '<S285>/Constant'
     */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S285>/Switch1' */
    Robot_Control_B.FR_Desired_Wheel_Speed_in = rtb_Switch2_p;
  }

  /* End of Switch: '<S285>/Switch1' */

  /* Fcn: '<S291>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Add2[0], rtb_Add2[1]);

  /* RelationalOperator: '<S294>/Compare' incorporates:
   *  Constant: '<S294>/Constant'
   */
  rtb_Compare_bd = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S290>/Switch1' */
  if (rtb_Compare_bd) {
    /* Switch: '<S290>/Switch1' incorporates:
     *  Constant: '<S290>/Constant'
     */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = 1.0E-15;
  } else {
    /* Switch: '<S290>/Switch1' */
    Robot_Control_B.BL_Desired_Wheel_Speed_in = rtb_MatrixConcatenate_b_idx_0;
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
  rtb_UnitDelay3 = 5.3690930669470935 / fmax(fmax(fmax(fmax(5.3690930669470935,
    Robot_Control_B.FL_Desired_Wheel_Speed_in),
    Robot_Control_B.FR_Desired_Wheel_Speed_in),
    Robot_Control_B.BL_Desired_Wheel_Speed_in),
    Robot_Control_B.BR_Desired_Wheel_Speed_in);

  /* Product: '<S275>/Product3' */
  Robot_Control_B.BR_Desired_Wheel_Speed =
    Robot_Control_B.BR_Desired_Wheel_Speed_in * rtb_UnitDelay3;

  /* Switch: '<S295>/Switch' */
  if (!rtb_Compare_ph) {
    /* Switch: '<S295>/Switch' incorporates:
     *  Fcn: '<S296>/x->theta'
     */
    Robot_Control_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_k_idx_1,
      rtb_Minus_k_idx_0);
  }

  /* End of Switch: '<S295>/Switch' */

  /* Trigonometry: '<S229>/Cos4' incorporates:
   *  Switch: '<S218>/Angle_Switch'
   *  Trigonometry: '<S228>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S229>/Sin5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S227>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Trigonometry: '<S229>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S229>/Cos5' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  UnaryMinus: '<S227>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Robot_Control_U.BR_Steer_Module_Angle);

  /* Sum: '<S229>/Subtract1' incorporates:
   *  Product: '<S229>/Product2'
   *  Product: '<S229>/Product3'
   *  Trigonometry: '<S229>/Cos4'
   */
  rtb_Switch5_o = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) + (rtb_Minus_k_idx_1 *
    rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S229>/Subtract' incorporates:
   *  Product: '<S229>/Product'
   *  Product: '<S229>/Product1'
   *  Trigonometry: '<S229>/Cos4'
   */
  rtb_Subtract = (rtb_Minus_k_idx_0 * rtb_MatrixConcatenate_b_idx_0) -
    (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S229>/Hypot' */
  rtb_Hypot = rt_hypotd_snf(rtb_Subtract, rtb_Switch5_o);

  /* Switch: '<S229>/Switch' incorporates:
   *  Constant: '<S229>/Constant'
   *  Constant: '<S229>/Constant1'
   *  Constant: '<S230>/Constant'
   *  Product: '<S229>/Divide'
   *  Product: '<S229>/Divide1'
   *  RelationalOperator: '<S230>/Compare'
   *  Switch: '<S229>/Switch1'
   */
  if (rtb_Hypot > 1.0E-6) {
    rtb_Switch2_p = rtb_Switch5_o / rtb_Hypot;
    rtb_MatrixConcatenate_b_idx_0 = rtb_Subtract / rtb_Hypot;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
  }

  /* End of Switch: '<S229>/Switch' */

  /* Switch: '<S218>/Speed_Switch' incorporates:
   *  Abs: '<S218>/Abs'
   *  Constant: '<S226>/Constant'
   *  RelationalOperator: '<S226>/Compare'
   *  Switch: '<S218>/Angle_Switch'
   *  Trigonometry: '<S228>/Atan1'
   *  Trigonometry: '<S229>/Atan1'
   *  UnaryMinus: '<S218>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    u0 = -Robot_Control_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S228>/Subtract1' incorporates:
     *  Product: '<S228>/Product2'
     *  Product: '<S228>/Product3'
     *  Trigonometry: '<S228>/Sin4'
     *  UnaryMinus: '<S218>/Unary Minus'
     */
    rtb_Switch5_o = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Sin5_c) +
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5_b);

    /* Sum: '<S228>/Subtract' incorporates:
     *  Product: '<S228>/Product'
     *  Product: '<S228>/Product1'
     *  Trigonometry: '<S228>/Sin4'
     */
    rtb_Hypot = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5_b) -
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_c);

    /* Math: '<S228>/Hypot' */
    rtb_Subtract = rt_hypotd_snf(rtb_Hypot, rtb_Switch5_o);

    /* Switch: '<S228>/Switch1' incorporates:
     *  Constant: '<S228>/Constant'
     *  Constant: '<S228>/Constant1'
     *  Constant: '<S231>/Constant'
     *  Product: '<S228>/Divide'
     *  Product: '<S228>/Divide1'
     *  RelationalOperator: '<S231>/Compare'
     *  Switch: '<S228>/Switch'
     */
    if (rtb_Subtract > 1.0E-6) {
      rtb_Hypot /= rtb_Subtract;
      rtb_Switch5_o /= rtb_Subtract;
    } else {
      rtb_Hypot = 1.0;
      rtb_Switch5_o = 0.0;
    }

    /* End of Switch: '<S228>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Switch5_o, rtb_Hypot);
  } else {
    u0 = Robot_Control_B.BR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S221>/Product2' incorporates:
   *  Constant: '<S221>/Constant'
   *  Switch: '<S218>/Speed_Switch'
   */
  rtb_Switch2_p = u0 * 1154.7574092481445;

  /* Signum: '<S216>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    u0 = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    u0 = -1.0;
  } else {
    u0 = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S216>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackRight_Drive_Motor_Speed)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S219>/Add' incorporates:
   *  Inport: '<Root>/BR_Steer_Module_Angle'
   *  Sum: '<S220>/Sum'
   */
  rtb_uDLookupTable -= Robot_Control_U.BR_Steer_Module_Angle;

  /* Product: '<S151>/Product' incorporates:
   *  Abs: '<S216>/Abs'
   *  Abs: '<S219>/Abs'
   *  Constant: '<S222>/Constant'
   *  Constant: '<S232>/Constant3'
   *  Constant: '<S232>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
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
  rtb_Switch2_p = (((real_T)((u0 == rtb_Product_lb) || (fabs
    (Robot_Control_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable + 1.5707963267948966, 3.141592653589793)
          - 1.5707963267948966), rtCP_uDLookupTable_bp01Data,
     rtCP_uDLookupTable_tableData_g, 1U);

  /* Gain: '<S217>/Gain' */
  rtb_Hypot = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S217>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Robot_Control_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S224>/Sum1' incorporates:
   *  Constant: '<S217>/Constant2'
   *  Product: '<S224>/Product'
   *  Sum: '<S224>/Sum'
   *  UnitDelay: '<S224>/Unit Delay1'
   */
  rtb_Switch5_o = ((rtb_Switch2_p - Robot_Control_DW.UnitDelay1_DSTATE_j) *
                   Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S217>/Product' incorporates:
   *  Constant: '<S217>/Constant3'
   */
  rtb_Subtract = rtb_Switch5_o * Drive_Motor_Control_D;

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
  u0 = rtb_Subtract - Robot_Control_DW.UD_DSTATE_j;

  /* Saturate: '<S217>/Saturation' */
  if (u0 > Drive_Motor_Control_D_UL) {
    u0 = Drive_Motor_Control_D_UL;
  } else if (u0 < Drive_Motor_Control_D_LL) {
    u0 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S217>/Add' incorporates:
   *  Gain: '<S217>/Gain1'
   *  Saturate: '<S217>/Saturation'
   */
  u0 += (Drive_Motor_Control_P * rtb_Switch2_p) + rtb_Hypot;

  /* Saturate: '<S217>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Robot_Control_Y.BackRight_Drive_DutyCycle = u0;
  }

  /* End of Saturate: '<S217>/Saturation2' */

  /* Sum: '<S233>/Add1' incorporates:
   *  Constant: '<S233>/Constant3'
   *  Constant: '<S233>/Constant4'
   *  Math: '<S233>/Math Function'
   *  Sum: '<S233>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Sum: '<S235>/Sum1' incorporates:
   *  Constant: '<S220>/Constant2'
   *  Product: '<S235>/Product'
   *  Sum: '<S235>/Sum'
   *  UnitDelay: '<S235>/Unit Delay1'
   */
  rtb_Hypot = ((rtb_Switch2_p - Robot_Control_DW.UnitDelay1_DSTATE_i) *
               Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S220>/Product' incorporates:
   *  Constant: '<S220>/Constant3'
   */
  rtb_MatrixConcatenate_idx_0 = rtb_Hypot * Steering_Motor_Control_D;

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
  u0 = rtb_MatrixConcatenate_idx_0 - Robot_Control_DW.UD_DSTATE_l;

  /* Saturate: '<S220>/Saturation' */
  if (u0 > Steering_Motor_Control_D_UL) {
    u0 = Steering_Motor_Control_D_UL;
  } else if (u0 < Steering_Motor_Control_D_LL) {
    u0 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S220>/Add' incorporates:
   *  Gain: '<S220>/Gain1'
   *  Saturate: '<S220>/Saturation'
   */
  rtb_Add_pw = (Steering_Motor_Control_P * rtb_Switch2_p) + u0;

  /* Sum: '<S220>/Subtract' incorporates:
   *  Constant: '<S220>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_pw;

  /* Sum: '<S220>/Sum2' incorporates:
   *  Gain: '<S220>/Gain2'
   *  UnitDelay: '<S220>/Unit Delay'
   */
  rtb_Sum2_fc = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Robot_Control_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S236>/Switch2' incorporates:
   *  Constant: '<S220>/Constant'
   *  RelationalOperator: '<S236>/LowerRelop1'
   *  Sum: '<S220>/Subtract'
   */
  if (!(rtb_Sum2_fc > (1.0 - rtb_Add_pw))) {
    /* Switch: '<S236>/Switch' incorporates:
     *  Constant: '<S220>/Constant1'
     *  RelationalOperator: '<S236>/UpperRelop'
     *  Sum: '<S220>/Subtract1'
     */
    if (rtb_Sum2_fc < (-1.0 - rtb_Add_pw)) {
      rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_pw;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Sum2_fc;
    }

    /* End of Switch: '<S236>/Switch' */
  }

  /* End of Switch: '<S236>/Switch2' */

  /* Saturate: '<S220>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S220>/Saturation1' */

  /* Sum: '<S220>/Add1' */
  u0 = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S220>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Robot_Control_Y.BackRight_Steer_DutyCycle = u0;
  }

  /* End of Saturate: '<S220>/Saturation2' */

  /* Product: '<S275>/Product' */
  Robot_Control_B.FL_Desired_Wheel_Speed =
    Robot_Control_B.FL_Desired_Wheel_Speed_in * rtb_UnitDelay3;

  /* Switch: '<S280>/Switch' */
  if (!rtb_Compare_mq) {
    /* Switch: '<S280>/Switch' incorporates:
     *  Fcn: '<S281>/x->theta'
     */
    Robot_Control_B.FL_Desired_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLookup[1], rtb_TmpSignalConversionAtLookup[0]);
  }

  /* End of Switch: '<S280>/Switch' */

  /* Trigonometry: '<S166>/Cos4' incorporates:
   *  Switch: '<S155>/Angle_Switch'
   *  Trigonometry: '<S165>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S166>/Sin5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S164>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Trigonometry: '<S166>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S166>/Cos5' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  UnaryMinus: '<S164>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Robot_Control_U.FL_Steer_Module_Angle);

  /* Sum: '<S166>/Subtract1' incorporates:
   *  Product: '<S166>/Product2'
   *  Product: '<S166>/Product3'
   *  Trigonometry: '<S166>/Cos4'
   */
  rtb_Switch2_p = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) + (rtb_Minus_k_idx_1 *
    rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S166>/Subtract' incorporates:
   *  Product: '<S166>/Product'
   *  Product: '<S166>/Product1'
   *  Trigonometry: '<S166>/Cos4'
   */
  rtb_Add_pw = (rtb_Minus_k_idx_0 * rtb_MatrixConcatenate_b_idx_0) -
    (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S166>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Add_pw, rtb_Switch2_p);

  /* Switch: '<S166>/Switch' incorporates:
   *  Constant: '<S166>/Constant'
   *  Constant: '<S166>/Constant1'
   *  Constant: '<S167>/Constant'
   *  Product: '<S166>/Divide'
   *  Product: '<S166>/Divide1'
   *  RelationalOperator: '<S167>/Compare'
   *  Switch: '<S166>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_Switch2_p /= rtb_Hypot_g5;
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pw / rtb_Hypot_g5;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
  }

  /* End of Switch: '<S166>/Switch' */

  /* Switch: '<S155>/Speed_Switch' incorporates:
   *  Abs: '<S155>/Abs'
   *  Constant: '<S163>/Constant'
   *  RelationalOperator: '<S163>/Compare'
   *  Switch: '<S155>/Angle_Switch'
   *  Trigonometry: '<S165>/Atan1'
   *  Trigonometry: '<S166>/Atan1'
   *  UnaryMinus: '<S155>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    u0 = -Robot_Control_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S165>/Subtract1' incorporates:
     *  Product: '<S165>/Product2'
     *  Product: '<S165>/Product3'
     *  Trigonometry: '<S165>/Sin4'
     *  UnaryMinus: '<S155>/Unary Minus'
     */
    rtb_Add_pw = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Sin5) +
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Cos5);

    /* Sum: '<S165>/Subtract' incorporates:
     *  Product: '<S165>/Product'
     *  Product: '<S165>/Product1'
     *  Trigonometry: '<S165>/Sin4'
     */
    rtb_Subtract_i = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5) -
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5);

    /* Math: '<S165>/Hypot' */
    rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract_i, rtb_Add_pw);

    /* Switch: '<S165>/Switch1' incorporates:
     *  Constant: '<S165>/Constant'
     *  Constant: '<S165>/Constant1'
     *  Constant: '<S168>/Constant'
     *  Product: '<S165>/Divide'
     *  Product: '<S165>/Divide1'
     *  RelationalOperator: '<S168>/Compare'
     *  Switch: '<S165>/Switch'
     */
    if (rtb_Hypot_g5 > 1.0E-6) {
      rtb_Subtract_i /= rtb_Hypot_g5;
      rtb_Add_pw /= rtb_Hypot_g5;
    } else {
      rtb_Subtract_i = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S165>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_Add_pw, rtb_Subtract_i);
  } else {
    u0 = Robot_Control_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S158>/Product2' incorporates:
   *  Constant: '<S158>/Constant'
   *  Switch: '<S155>/Speed_Switch'
   */
  rtb_Switch2_p = u0 * 1154.7574092481445;

  /* Signum: '<S153>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    u0 = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    u0 = -1.0;
  } else {
    u0 = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S153>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S156>/Add' incorporates:
   *  Inport: '<Root>/FL_Steer_Module_Angle'
   *  Sum: '<S157>/Sum'
   */
  rtb_uDLookupTable -= Robot_Control_U.FL_Steer_Module_Angle;

  /* Product: '<S148>/Product' incorporates:
   *  Abs: '<S153>/Abs'
   *  Abs: '<S156>/Abs'
   *  Constant: '<S159>/Constant'
   *  Constant: '<S169>/Constant3'
   *  Constant: '<S169>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S153>/OR'
   *  Lookup_n-D: '<S156>/1-D Lookup Table'
   *  Math: '<S169>/Math Function'
   *  RelationalOperator: '<S153>/Equal1'
   *  RelationalOperator: '<S159>/Compare'
   *  Signum: '<S153>/Sign'
   *  Signum: '<S153>/Sign1'
   *  Sum: '<S156>/Add'
   *  Sum: '<S169>/Add1'
   *  Sum: '<S169>/Add2'
   */
  rtb_Switch2_p = (((real_T)((u0 == rtb_Product_lb) || (fabs
    (Robot_Control_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable + 1.5707963267948966, 3.141592653589793)
          - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_h,
     rtCP_uDLookupTable_tableData_j, 1U);

  /* Gain: '<S154>/Gain' */
  rtb_Subtract_i = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S154>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Robot_Control_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S161>/Sum1' incorporates:
   *  Constant: '<S154>/Constant2'
   *  Product: '<S161>/Product'
   *  Sum: '<S161>/Sum'
   *  UnitDelay: '<S161>/Unit Delay1'
   */
  rtb_Add_pw = ((rtb_Switch2_p - Robot_Control_DW.UnitDelay1_DSTATE_f) *
                Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S154>/Product' incorporates:
   *  Constant: '<S154>/Constant3'
   */
  rtb_Hypot_g5 = rtb_Add_pw * Drive_Motor_Control_D;

  /* Sum: '<S160>/Diff' incorporates:
   *  UnitDelay: '<S160>/UD'
   *
   * Block description for '<S160>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S160>/UD':
   *
   *  Store in Global RAM
   */
  u0 = rtb_Hypot_g5 - Robot_Control_DW.UD_DSTATE_h;

  /* Saturate: '<S154>/Saturation' */
  if (u0 > Drive_Motor_Control_D_UL) {
    u0 = Drive_Motor_Control_D_UL;
  } else if (u0 < Drive_Motor_Control_D_LL) {
    u0 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S154>/Add' incorporates:
   *  Gain: '<S154>/Gain1'
   *  Saturate: '<S154>/Saturation'
   */
  u0 += (Drive_Motor_Control_P * rtb_Switch2_p) + rtb_Subtract_i;

  /* Saturate: '<S154>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Robot_Control_Y.FrontLeft_Drive_DutyCycle = u0;
  }

  /* End of Saturate: '<S154>/Saturation2' */

  /* Sum: '<S170>/Add1' incorporates:
   *  Constant: '<S170>/Constant3'
   *  Constant: '<S170>/Constant4'
   *  Math: '<S170>/Math Function'
   *  Sum: '<S170>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Sum: '<S172>/Sum1' incorporates:
   *  Constant: '<S157>/Constant2'
   *  Product: '<S172>/Product'
   *  Sum: '<S172>/Sum'
   *  UnitDelay: '<S172>/Unit Delay1'
   */
  rtb_Subtract_i = ((rtb_Switch2_p - Robot_Control_DW.UnitDelay1_DSTATE_b) *
                    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S157>/Product' incorporates:
   *  Constant: '<S157>/Constant3'
   */
  rtb_Product_f = rtb_Subtract_i * Steering_Motor_Control_D;

  /* Sum: '<S171>/Diff' incorporates:
   *  UnitDelay: '<S171>/UD'
   *
   * Block description for '<S171>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S171>/UD':
   *
   *  Store in Global RAM
   */
  u0 = rtb_Product_f - Robot_Control_DW.UD_DSTATE_b;

  /* Saturate: '<S157>/Saturation' */
  if (u0 > Steering_Motor_Control_D_UL) {
    u0 = Steering_Motor_Control_D_UL;
  } else if (u0 < Steering_Motor_Control_D_LL) {
    u0 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S157>/Add' incorporates:
   *  Gain: '<S157>/Gain1'
   *  Saturate: '<S157>/Saturation'
   */
  rtb_Minus_k_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_p) + u0;

  /* Sum: '<S157>/Subtract' incorporates:
   *  Constant: '<S157>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Minus_k_idx_1;

  /* Sum: '<S157>/Sum2' incorporates:
   *  Gain: '<S157>/Gain2'
   *  UnitDelay: '<S157>/Unit Delay'
   */
  rtb_Switch2_p = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Robot_Control_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S173>/Switch2' incorporates:
   *  Constant: '<S157>/Constant'
   *  RelationalOperator: '<S173>/LowerRelop1'
   *  Sum: '<S157>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_Minus_k_idx_1))) {
    /* Switch: '<S173>/Switch' incorporates:
     *  Constant: '<S157>/Constant1'
     *  RelationalOperator: '<S173>/UpperRelop'
     *  Sum: '<S157>/Subtract1'
     */
    if (rtb_Switch2_p < (-1.0 - rtb_Minus_k_idx_1)) {
      rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Minus_k_idx_1;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
    }

    /* End of Switch: '<S173>/Switch' */
  }

  /* End of Switch: '<S173>/Switch2' */

  /* Saturate: '<S157>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_la = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S157>/Saturation1' */

  /* Sum: '<S157>/Add1' */
  u0 = rtb_Minus_k_idx_1 + rtb_Subtract1_la;

  /* Saturate: '<S157>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Robot_Control_Y.FrontLeft_Steer_DutyCycle = u0;
  }

  /* End of Saturate: '<S157>/Saturation2' */

  /* Product: '<S275>/Product1' */
  Robot_Control_B.FR_Desired_Wheel_Speed =
    Robot_Control_B.FR_Desired_Wheel_Speed_in * rtb_UnitDelay3;

  /* Switch: '<S285>/Switch' */
  if (!rtb_Compare_ky) {
    /* Switch: '<S285>/Switch' incorporates:
     *  Fcn: '<S286>/x->theta'
     */
    Robot_Control_B.FR_Desired_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLoo_mu[1], rtb_TmpSignalConversionAtLoo_mu[0]);
  }

  /* End of Switch: '<S285>/Switch' */

  /* Trigonometry: '<S187>/Cos4' incorporates:
   *  Switch: '<S176>/Angle_Switch'
   *  Trigonometry: '<S186>/Cos4'
   */
  rtb_Minus_k_idx_0 = cos(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S187>/Sin5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S185>/Unary Minus'
   */
  rtb_uDLookupTable = sin(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Trigonometry: '<S187>/Sin4' */
  rtb_Minus_k_idx_1 = sin(Robot_Control_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S187>/Cos5' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  UnaryMinus: '<S185>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Robot_Control_U.FR_Steer_Module_Angle);

  /* Sum: '<S187>/Subtract1' incorporates:
   *  Product: '<S187>/Product2'
   *  Product: '<S187>/Product3'
   *  Trigonometry: '<S187>/Cos4'
   */
  rtb_Switch2_p = (rtb_Minus_k_idx_0 * rtb_uDLookupTable) + (rtb_Minus_k_idx_1 *
    rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S187>/Subtract' incorporates:
   *  Product: '<S187>/Product'
   *  Product: '<S187>/Product1'
   *  Trigonometry: '<S187>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_0 *
    rtb_MatrixConcatenate_b_idx_0) - (rtb_Minus_k_idx_1 * rtb_uDLookupTable);

  /* Math: '<S187>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Switch2_p);

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S187>/Constant'
   *  Constant: '<S187>/Constant1'
   *  Constant: '<S188>/Constant'
   *  Product: '<S187>/Divide'
   *  Product: '<S187>/Divide1'
   *  RelationalOperator: '<S188>/Compare'
   *  Switch: '<S187>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_Switch2_p /= rtb_Hypot_b;
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Hypot_b;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
  }

  /* End of Switch: '<S187>/Switch' */

  /* Switch: '<S176>/Speed_Switch' incorporates:
   *  Abs: '<S176>/Abs'
   *  Constant: '<S184>/Constant'
   *  RelationalOperator: '<S184>/Compare'
   *  Switch: '<S176>/Angle_Switch'
   *  Trigonometry: '<S186>/Atan1'
   *  Trigonometry: '<S187>/Atan1'
   *  UnaryMinus: '<S176>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    u0 = -Robot_Control_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S186>/Subtract1' incorporates:
     *  Product: '<S186>/Product2'
     *  Product: '<S186>/Product3'
     *  Trigonometry: '<S186>/Sin4'
     *  UnaryMinus: '<S176>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Minus_k_idx_0 *
      Robot_Control_ConstB.Sin5_m) + (rtb_Minus_k_idx_1 *
      Robot_Control_ConstB.Cos5_g);

    /* Sum: '<S186>/Subtract' incorporates:
     *  Product: '<S186>/Product'
     *  Product: '<S186>/Product1'
     *  Trigonometry: '<S186>/Sin4'
     */
    rtb_Minus_k_idx_0 = (rtb_Minus_k_idx_0 * Robot_Control_ConstB.Cos5_g) -
      (rtb_Minus_k_idx_1 * Robot_Control_ConstB.Sin5_m);

    /* Math: '<S186>/Hypot' */
    rtb_Minus_k_idx_1 = rt_hypotd_snf(rtb_Minus_k_idx_0,
      rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S186>/Switch1' incorporates:
     *  Constant: '<S186>/Constant'
     *  Constant: '<S186>/Constant1'
     *  Constant: '<S189>/Constant'
     *  Product: '<S186>/Divide'
     *  Product: '<S186>/Divide1'
     *  RelationalOperator: '<S189>/Compare'
     *  Switch: '<S186>/Switch'
     */
    if (rtb_Minus_k_idx_1 > 1.0E-6) {
      rtb_Minus_k_idx_0 /= rtb_Minus_k_idx_1;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Minus_k_idx_1;
    } else {
      rtb_Minus_k_idx_0 = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S186>/Switch1' */
    rtb_uDLookupTable = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_Minus_k_idx_0);
  } else {
    u0 = Robot_Control_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable = Robot_Control_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S179>/Product2' incorporates:
   *  Constant: '<S179>/Constant'
   *  Switch: '<S176>/Speed_Switch'
   */
  rtb_Switch2_p = u0 * 1154.7574092481445;

  /* Signum: '<S174>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    u0 = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    u0 = -1.0;
  } else {
    u0 = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S174>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S177>/Add' incorporates:
   *  Inport: '<Root>/FR_Steer_Module_Angle'
   *  Sum: '<S178>/Sum'
   */
  rtb_uDLookupTable -= Robot_Control_U.FR_Steer_Module_Angle;

  /* Product: '<S149>/Product' incorporates:
   *  Abs: '<S174>/Abs'
   *  Abs: '<S177>/Abs'
   *  Constant: '<S180>/Constant'
   *  Constant: '<S190>/Constant3'
   *  Constant: '<S190>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S174>/OR'
   *  Lookup_n-D: '<S177>/1-D Lookup Table'
   *  Math: '<S190>/Math Function'
   *  RelationalOperator: '<S174>/Equal1'
   *  RelationalOperator: '<S180>/Compare'
   *  Signum: '<S174>/Sign'
   *  Signum: '<S174>/Sign1'
   *  Sum: '<S177>/Add'
   *  Sum: '<S190>/Add1'
   *  Sum: '<S190>/Add2'
   */
  rtb_Switch2_p = (((real_T)((u0 == rtb_Product_lb) || (fabs
    (Robot_Control_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable + 1.5707963267948966, 3.141592653589793)
          - 1.5707963267948966), rtCP_uDLookupTable_bp01Data_p,
     rtCP_uDLookupTable_tableData_gs, 1U);

  /* Gain: '<S175>/Gain' */
  rtb_MatrixConcatenate_b_idx_0 = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S175>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Robot_Control_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S182>/Sum1' incorporates:
   *  Constant: '<S175>/Constant2'
   *  Product: '<S182>/Product'
   *  Sum: '<S182>/Sum'
   *  UnitDelay: '<S182>/Unit Delay1'
   */
  rtb_Minus_k_idx_1 = ((rtb_Switch2_p - Robot_Control_DW.UnitDelay1_DSTATE_e) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S175>/Product' incorporates:
   *  Constant: '<S175>/Constant3'
   */
  rtb_Minus_k_idx_0 = rtb_Minus_k_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S181>/Diff' incorporates:
   *  UnitDelay: '<S181>/UD'
   *
   * Block description for '<S181>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S181>/UD':
   *
   *  Store in Global RAM
   */
  u0 = rtb_Minus_k_idx_0 - Robot_Control_DW.UD_DSTATE_m;

  /* Saturate: '<S175>/Saturation' */
  if (u0 > Drive_Motor_Control_D_UL) {
    u0 = Drive_Motor_Control_D_UL;
  } else if (u0 < Drive_Motor_Control_D_LL) {
    u0 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S175>/Add' incorporates:
   *  Gain: '<S175>/Gain1'
   *  Saturate: '<S175>/Saturation'
   */
  u0 += (Drive_Motor_Control_P * rtb_Switch2_p) + rtb_MatrixConcatenate_b_idx_0;

  /* Saturate: '<S175>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Robot_Control_Y.FrontRight_Drive_DutyCycle = u0;
  }

  /* End of Saturate: '<S175>/Saturation2' */

  /* Sum: '<S191>/Add1' incorporates:
   *  Constant: '<S191>/Constant3'
   *  Constant: '<S191>/Constant4'
   *  Math: '<S191>/Math Function'
   *  Sum: '<S191>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Sum: '<S193>/Sum1' incorporates:
   *  Constant: '<S178>/Constant2'
   *  Product: '<S193>/Product'
   *  Sum: '<S193>/Sum'
   *  UnitDelay: '<S193>/Unit Delay1'
   */
  rtb_Hypot_b = ((rtb_Switch2_p - Robot_Control_DW.UnitDelay1_DSTATE_n) *
                 Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S178>/Product' incorporates:
   *  Constant: '<S178>/Constant3'
   */
  rtb_Product_k5 = rtb_Hypot_b * Steering_Motor_Control_D;

  /* Sum: '<S192>/Diff' incorporates:
   *  UnitDelay: '<S192>/UD'
   *
   * Block description for '<S192>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S192>/UD':
   *
   *  Store in Global RAM
   */
  u0 = rtb_Product_k5 - Robot_Control_DW.UD_DSTATE_i;

  /* Saturate: '<S178>/Saturation' */
  if (u0 > Steering_Motor_Control_D_UL) {
    u0 = Steering_Motor_Control_D_UL;
  } else if (u0 < Steering_Motor_Control_D_LL) {
    u0 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S178>/Add' incorporates:
   *  Gain: '<S178>/Gain1'
   *  Saturate: '<S178>/Saturation'
   */
  rtb_uDLookupTable = (Steering_Motor_Control_P * rtb_Switch2_p) + u0;

  /* Sum: '<S178>/Subtract' incorporates:
   *  Constant: '<S178>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_uDLookupTable;

  /* Sum: '<S178>/Sum2' incorporates:
   *  Gain: '<S178>/Gain2'
   *  UnitDelay: '<S178>/Unit Delay'
   */
  rtb_Switch2_p = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Robot_Control_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S194>/Switch2' incorporates:
   *  Constant: '<S178>/Constant'
   *  RelationalOperator: '<S194>/LowerRelop1'
   *  Sum: '<S178>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_uDLookupTable))) {
    /* Sum: '<S178>/Subtract1' incorporates:
     *  Constant: '<S178>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_uDLookupTable;

    /* Switch: '<S194>/Switch' incorporates:
     *  Constant: '<S178>/Constant1'
     *  RelationalOperator: '<S194>/UpperRelop'
     *  Sum: '<S178>/Subtract1'
     */
    if (!(rtb_Switch2_p < (-1.0 - rtb_uDLookupTable))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
    }

    /* End of Switch: '<S194>/Switch' */
  }

  /* End of Switch: '<S194>/Switch2' */

  /* Saturate: '<S178>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_k = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_k = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_k = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S178>/Saturation1' */

  /* Sum: '<S178>/Add1' */
  u0 = rtb_uDLookupTable + rtb_Integral_k;

  /* Saturate: '<S178>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Robot_Control_Y.FrontRight_Steer_DutyCycle = u0;
  }

  /* End of Saturate: '<S178>/Saturation2' */

  /* Product: '<S275>/Product2' */
  Robot_Control_B.BL_Desired_Wheel_Speed =
    Robot_Control_B.BL_Desired_Wheel_Speed_in * rtb_UnitDelay3;

  /* Switch: '<S290>/Switch' */
  if (!rtb_Compare_bd) {
    /* Switch: '<S290>/Switch' incorporates:
     *  Fcn: '<S291>/x->theta'
     */
    Robot_Control_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2[1],
      rtb_Add2[0]);
  }

  /* End of Switch: '<S290>/Switch' */

  /* Trigonometry: '<S208>/Cos4' incorporates:
   *  Switch: '<S197>/Angle_Switch'
   *  Trigonometry: '<S207>/Cos4'
   */
  rtb_Product_lb = cos(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S208>/Sin5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S206>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = sin(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Trigonometry: '<S208>/Sin4' */
  rtb_uDLookupTable = sin(Robot_Control_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S208>/Cos5' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  UnaryMinus: '<S206>/Unary Minus'
   */
  rtb_Switch2_p = cos(-Robot_Control_U.BL_Steer_Module_Angle);

  /* Sum: '<S208>/Subtract1' incorporates:
   *  Product: '<S208>/Product2'
   *  Product: '<S208>/Product3'
   *  Trigonometry: '<S208>/Cos4'
   */
  rtb_UnitDelay3 = (rtb_Product_lb * rtb_MatrixConcatenate_b_idx_0) +
    (rtb_uDLookupTable * rtb_Switch2_p);

  /* Sum: '<S208>/Subtract' incorporates:
   *  Product: '<S208>/Product'
   *  Product: '<S208>/Product1'
   *  Trigonometry: '<S208>/Cos4'
   */
  rtb_Switch2_p = (rtb_Product_lb * rtb_Switch2_p) - (rtb_uDLookupTable *
    rtb_MatrixConcatenate_b_idx_0);

  /* Math: '<S208>/Hypot' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Switch2_p, rtb_UnitDelay3);

  /* Switch: '<S208>/Switch' incorporates:
   *  Constant: '<S208>/Constant'
   *  Constant: '<S208>/Constant1'
   *  Constant: '<S209>/Constant'
   *  Product: '<S208>/Divide'
   *  Product: '<S208>/Divide1'
   *  RelationalOperator: '<S209>/Compare'
   *  Switch: '<S208>/Switch1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
    rtb_UnitDelay3 /= rtb_MatrixConcatenate_b_idx_0;
    rtb_Switch2_p /= rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_UnitDelay3 = 0.0;
    rtb_Switch2_p = 1.0;
  }

  /* End of Switch: '<S208>/Switch' */

  /* Switch: '<S197>/Speed_Switch' incorporates:
   *  Abs: '<S197>/Abs'
   *  Constant: '<S205>/Constant'
   *  RelationalOperator: '<S205>/Compare'
   *  Switch: '<S197>/Angle_Switch'
   *  Trigonometry: '<S207>/Atan1'
   *  Trigonometry: '<S208>/Atan1'
   *  UnaryMinus: '<S197>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_UnitDelay3, rtb_Switch2_p)) > 1.5707963267948966) {
    rtb_UnitDelay3 = -Robot_Control_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S207>/Subtract1' incorporates:
     *  Product: '<S207>/Product2'
     *  Product: '<S207>/Product3'
     *  Trigonometry: '<S207>/Sin4'
     *  UnaryMinus: '<S197>/Unary Minus'
     */
    rtb_Switch2_p = (rtb_Product_lb * Robot_Control_ConstB.Sin5_e) +
      (rtb_uDLookupTable * Robot_Control_ConstB.Cos5_i);

    /* Sum: '<S207>/Subtract' incorporates:
     *  Product: '<S207>/Product'
     *  Product: '<S207>/Product1'
     *  Trigonometry: '<S207>/Sin4'
     */
    rtb_uDLookupTable = (rtb_Product_lb * Robot_Control_ConstB.Cos5_i) -
      (rtb_uDLookupTable * Robot_Control_ConstB.Sin5_e);

    /* Math: '<S207>/Hypot' */
    rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_uDLookupTable,
      rtb_Switch2_p);

    /* Switch: '<S207>/Switch1' incorporates:
     *  Constant: '<S207>/Constant'
     *  Constant: '<S207>/Constant1'
     *  Constant: '<S210>/Constant'
     *  Product: '<S207>/Divide'
     *  Product: '<S207>/Divide1'
     *  RelationalOperator: '<S210>/Compare'
     *  Switch: '<S207>/Switch'
     */
    if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
      rtb_uDLookupTable /= rtb_MatrixConcatenate_b_idx_0;
      rtb_Switch2_p /= rtb_MatrixConcatenate_b_idx_0;
    } else {
      rtb_uDLookupTable = 1.0;
      rtb_Switch2_p = 0.0;
    }

    /* End of Switch: '<S207>/Switch1' */
    rtb_MatrixConcatenate_b_idx_0 = rt_atan2d_snf(rtb_Switch2_p,
      rtb_uDLookupTable);
  } else {
    rtb_UnitDelay3 = Robot_Control_B.BL_Desired_Wheel_Speed;
    rtb_MatrixConcatenate_b_idx_0 = Robot_Control_B.BL_Desired_Module_Angle;
  }

  /* End of Switch: '<S197>/Speed_Switch' */

  /* Product: '<S200>/Product2' incorporates:
   *  Constant: '<S200>/Constant'
   */
  rtb_UnitDelay3 *= 1154.7574092481445;

  /* Signum: '<S195>/Sign' */
  if (rtIsNaN(rtb_UnitDelay3)) {
    u0 = (rtNaN);
  } else if (rtb_UnitDelay3 < 0.0) {
    u0 = -1.0;
  } else {
    u0 = (rtb_UnitDelay3 > 0.0);
  }

  /* Signum: '<S195>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Robot_Control_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Product_lb = (rtNaN);
  } else if (Robot_Control_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Product_lb = -1.0;
  } else {
    rtb_Product_lb = (Robot_Control_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S198>/Add' incorporates:
   *  Inport: '<Root>/BL_Steer_Module_Angle'
   *  Sum: '<S199>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Robot_Control_U.BL_Steer_Module_Angle;

  /* Product: '<S150>/Product' incorporates:
   *  Abs: '<S195>/Abs'
   *  Abs: '<S198>/Abs'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S211>/Constant3'
   *  Constant: '<S211>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
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
  rtb_UnitDelay3 = (((real_T)((u0 == rtb_Product_lb) || (fabs
    (Robot_Control_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_UnitDelay3) *
    look1_binlcpw(fabs(rt_modd_snf(rtb_MatrixConcatenate_b_idx_0 +
    1.5707963267948966, 3.141592653589793) - 1.5707963267948966),
                  rtCP_uDLookupTable_bp01Data_j, rtCP_uDLookupTable_tableData_h,
                  1U);

  /* Gain: '<S196>/Gain' */
  rtb_Switch2_p = Drive_Motor_Control_FF * rtb_UnitDelay3;

  /* Sum: '<S196>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_UnitDelay3 -= Robot_Control_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S203>/Sum1' incorporates:
   *  Constant: '<S196>/Constant2'
   *  Product: '<S203>/Product'
   *  Sum: '<S203>/Sum'
   *  UnitDelay: '<S203>/Unit Delay1'
   */
  rtb_uDLookupTable = ((rtb_UnitDelay3 - Robot_Control_DW.UnitDelay1_DSTATE_n4) *
                       Drive_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_n4;

  /* Product: '<S196>/Product' incorporates:
   *  Constant: '<S196>/Constant3'
   */
  rtb_Product_lb = rtb_uDLookupTable * Drive_Motor_Control_D;

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
  u0 = rtb_Product_lb - Robot_Control_DW.UD_DSTATE_o;

  /* Saturate: '<S196>/Saturation' */
  if (u0 > Drive_Motor_Control_D_UL) {
    u0 = Drive_Motor_Control_D_UL;
  } else if (u0 < Drive_Motor_Control_D_LL) {
    u0 = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S196>/Add' incorporates:
   *  Gain: '<S196>/Gain1'
   *  Saturate: '<S196>/Saturation'
   */
  u0 += (Drive_Motor_Control_P * rtb_UnitDelay3) + rtb_Switch2_p;

  /* Saturate: '<S196>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Robot_Control_Y.BackLeft_Drive_DutyCycle = u0;
  }

  /* End of Saturate: '<S196>/Saturation2' */

  /* Sum: '<S212>/Add1' incorporates:
   *  Constant: '<S212>/Constant3'
   *  Constant: '<S212>/Constant4'
   *  Math: '<S212>/Math Function'
   *  Sum: '<S212>/Add2'
   */
  rtb_UnitDelay3 = rt_modd_snf(rtb_MatrixConcatenate_b_idx_0 + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Sum: '<S214>/Sum1' incorporates:
   *  Constant: '<S199>/Constant2'
   *  Product: '<S214>/Product'
   *  Sum: '<S214>/Sum'
   *  UnitDelay: '<S214>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((rtb_UnitDelay3 -
    Robot_Control_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Robot_Control_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S199>/Product' incorporates:
   *  Constant: '<S199>/Constant3'
   */
  rtb_Product_kx = rtb_MatrixConcatenate_b_idx_0 * Steering_Motor_Control_D;

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
  u0 = rtb_Product_kx - Robot_Control_DW.UD_DSTATE_k;

  /* Saturate: '<S199>/Saturation' */
  if (u0 > Steering_Motor_Control_D_UL) {
    u0 = Steering_Motor_Control_D_UL;
  } else if (u0 < Steering_Motor_Control_D_LL) {
    u0 = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S199>/Add' incorporates:
   *  Gain: '<S199>/Gain1'
   *  Saturate: '<S199>/Saturation'
   */
  rtb_Add_f1 = (Steering_Motor_Control_P * rtb_UnitDelay3) + u0;

  /* Sum: '<S199>/Subtract' incorporates:
   *  Constant: '<S199>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_f1;

  /* Sum: '<S199>/Sum2' incorporates:
   *  Gain: '<S199>/Gain2'
   *  UnitDelay: '<S199>/Unit Delay'
   */
  rtb_UnitDelay3 = (Steering_Motor_Control_I * rtb_UnitDelay3) +
    Robot_Control_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S215>/Switch2' incorporates:
   *  Constant: '<S199>/Constant'
   *  RelationalOperator: '<S215>/LowerRelop1'
   *  Sum: '<S199>/Subtract'
   */
  if (!(rtb_UnitDelay3 > (1.0 - rtb_Add_f1))) {
    /* Sum: '<S199>/Subtract1' incorporates:
     *  Constant: '<S199>/Constant1'
     */
    rtb_Switch2_p = -1.0 - rtb_Add_f1;

    /* Switch: '<S215>/Switch' incorporates:
     *  Constant: '<S199>/Constant1'
     *  RelationalOperator: '<S215>/UpperRelop'
     *  Sum: '<S199>/Subtract1'
     */
    if (!(rtb_UnitDelay3 < (-1.0 - rtb_Add_f1))) {
      rtb_Switch2_p = rtb_UnitDelay3;
    }

    /* End of Switch: '<S215>/Switch' */
  }

  /* End of Switch: '<S215>/Switch2' */

  /* Saturate: '<S199>/Saturation1' */
  if (rtb_Switch2_p > Steering_Motor_Control_I_UL) {
    rtb_UnitDelay3 = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_p < Steering_Motor_Control_I_LL) {
    rtb_UnitDelay3 = Steering_Motor_Control_I_LL;
  } else {
    rtb_UnitDelay3 = rtb_Switch2_p;
  }

  /* End of Saturate: '<S199>/Saturation1' */

  /* Sum: '<S199>/Add1' */
  u0 = rtb_Add_f1 + rtb_UnitDelay3;

  /* Saturate: '<S199>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Robot_Control_Y.BackLeft_Steer_DutyCycle = u0;
  }

  /* End of Saturate: '<S199>/Saturation2' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant2'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  Robot_Control_B.loop_counter_robot_control++;

  /* Sum: '<S336>/Sum' incorporates:
   *  Gain: '<S336>/Gain'
   *  Inport: '<Root>/Gamepad_Stick_Left_X'
   *  UnitDelay: '<S336>/Unit Delay'
   */
  rtb_Switch2_p = (Gamepad_Roll_Gain * Robot_Control_U.Gamepad_Stick_Left_X) +
    Robot_Control_DW.UnitDelay_DSTATE_id;

  /* Saturate: '<S336>/Saturation' */
  if (rtb_Switch2_p > Desired_Roll_Angle_UL) {
    rtb_Switch2_p = Desired_Roll_Angle_UL;
  } else if (rtb_Switch2_p < Desired_Roll_Angle_LL) {
    rtb_Switch2_p = Desired_Roll_Angle_LL;
  }

  /* End of Saturate: '<S336>/Saturation' */

  /* Sum: '<S337>/Sum' incorporates:
   *  Gain: '<S337>/Gain'
   *  Inport: '<Root>/Gamepad_Stick_Right_X'
   *  UnitDelay: '<S337>/Unit Delay'
   */
  rtb_Add_f1 = (Gamepad_Pitch_Gain * Robot_Control_U.Gamepad_Stick_Right_X) +
    Robot_Control_DW.UnitDelay_DSTATE_n;

  /* Saturate: '<S337>/Saturation' */
  if (rtb_Add_f1 > Desired_Pitch_Angle_UL) {
    rtb_Add_f1 = Desired_Pitch_Angle_UL;
  } else if (rtb_Add_f1 < Desired_Pitch_Angle_LL) {
    rtb_Add_f1 = Desired_Pitch_Angle_LL;
  }

  /* End of Saturate: '<S337>/Saturation' */

  /* Gain: '<S335>/Gain' incorporates:
   *  Constant: '<S335>/Constant'
   *  Inport: '<Root>/Wrist_Motor_Left_Revs'
   *  Product: '<S335>/Product'
   *  Sum: '<S335>/Add'
   *  Sum: '<S335>/Subtract'
   */
  u0 = (((rtb_Switch2_p + rtb_Add_f1) * R_motor_gearbox) -
        Robot_Control_U.Wrist_Motor_Left_Revs) * Kp_motor_angle;

  /* Saturate: '<S335>/Saturation' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/Wrist_Motor_Left_DC' */
    Robot_Control_Y.Wrist_Motor_Left_DC = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/Wrist_Motor_Left_DC' */
    Robot_Control_Y.Wrist_Motor_Left_DC = -1.0;
  } else {
    /* Outport: '<Root>/Wrist_Motor_Left_DC' */
    Robot_Control_Y.Wrist_Motor_Left_DC = u0;
  }

  /* End of Saturate: '<S335>/Saturation' */

  /* Gain: '<S335>/Gain1' incorporates:
   *  Constant: '<S335>/Constant2'
   *  Inport: '<Root>/Wrist_Motor_Right_Revs'
   *  Product: '<S335>/Product1'
   *  Sum: '<S335>/Add1'
   *  Sum: '<S335>/Subtract1'
   */
  u0 = (((rtb_Switch2_p - rtb_Add_f1) * R_motor_gearbox) -
        Robot_Control_U.Wrist_Motor_Right_Revs) * Kp_motor_angle;

  /* Saturate: '<S335>/Saturation1' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/Wrist_Motor_Right_DC' */
    Robot_Control_Y.Wrist_Motor_Right_DC = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/Wrist_Motor_Right_DC' */
    Robot_Control_Y.Wrist_Motor_Right_DC = -1.0;
  } else {
    /* Outport: '<Root>/Wrist_Motor_Right_DC' */
    Robot_Control_Y.Wrist_Motor_Right_DC = u0;
  }

  /* End of Saturate: '<S335>/Saturation1' */

  /* SignalConversion: '<S5>/Signal Copy4' incorporates:
   *  Inport: '<Root>/Xbox_Driver_Stick_Right_X'
   */
  Robot_Control_B.Steer_Joystick_X = Robot_Control_U.Xbox_Driver_Stick_Right_X;

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/GameState'
   */
  u0 = floor(Robot_Control_U.GameState);
  if ((rtIsNaN(u0)) || (rtIsInf(u0))) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 256.0);
  }

  rtb_GameState = (uint8_T)((u0 < 0.0) ? ((int32_T)((uint8_T)(-((int8_T)
    ((uint8_T)(-u0)))))) : ((int32_T)((uint8_T)u0)));

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* Chart: '<S9>/Chart' */
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

  /* End of Chart: '<S9>/Chart' */

  /* Update for UnitDelay: '<S23>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE = Robot_Control_U.Gamepad_B3_X;

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B4_Y'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_e = Robot_Control_U.Gamepad_B4_Y;

  /* Update for UnitDelay: '<S25>/Delay Input1' incorporates:
   *  Inport: '<Root>/Gamepad_B2_B'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.DelayInput1_DSTATE_n = Robot_Control_U.Gamepad_B2_B;

  /* Update for UnitDelay: '<S6>/Unit Delay1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Robot_Control_DW.UnitDelay1_DSTATE_nl = false;

  /* Update for UnitDelay: '<S6>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = Robot_Control_B.Spline_Index;

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_ll =
    Robot_Control_B.Robot_Reached_Destination;

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

  /* Update for Delay: '<S79>/Delay' */
  Robot_Control_DW.icLoad = false;

  /* Product: '<S78>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S26>/A'
   *  Delay: '<S79>/Delay'
   */
  tmp_0 = Robot_Control_DW.Delay_DSTATE[0];
  tmp = 0.0 * Robot_Control_DW.Delay_DSTATE[0];
  u0 = Robot_Control_DW.Delay_DSTATE[1];

  /* Update for Delay: '<S79>/Delay' incorporates:
   *  Constant: '<S26>/A'
   *  Constant: '<S26>/B'
   *  Inport: '<Root>/Odom_Delta_X'
   *  Inport: '<Root>/Odom_Delta_Y'
   *  Product: '<S78>/A[k]*xhat[k|k-1]'
   *  Product: '<S78>/B[k]*u[k]'
   *  Product: '<S80>/Product3'
   *  Sum: '<S78>/Add'
   */
  Robot_Control_DW.Delay_DSTATE[0] = (((0.0 * Robot_Control_U.Odom_Delta_Y) +
    Robot_Control_U.Odom_Delta_X) + ((0.0 * u0) + tmp_0)) +
    Robot_Control_B.Product3[0];
  Robot_Control_DW.Delay_DSTATE[1] = (((0.0 * Robot_Control_U.Odom_Delta_X) +
    Robot_Control_U.Odom_Delta_Y) + (tmp + u0)) + Robot_Control_B.Product3[1];

  /* Update for UnitDelay: '<S248>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S248>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S271>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S270>/UD'
   *
   * Block description for '<S270>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE = rtb_Saturation_h;

  /* Update for UnitDelay: '<S268>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d = rtb_Subtract_e;

  /* Update for UnitDelay: '<S250>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_d4 = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S265>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S265>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 0U;

  /* Update for UnitDelay: '<S265>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_e = rtb_Modulation_Drv;

  /* Update for UnitDelay: '<S249>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_g = rtb_Switch1_c;

  /* Update for UnitDelay: '<S258>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S258>/FixPt Constant'
   */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S258>/FixPt Unit Delay1' */
  Robot_Control_DW.FixPtUnitDelay1_DSTATE_p = rtb_Switch1_c;

  /* Update for UnitDelay: '<S224>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_j = rtb_Switch5_o;

  /* Update for UnitDelay: '<S223>/UD'
   *
   * Block description for '<S223>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_j = rtb_Subtract;

  /* Update for UnitDelay: '<S235>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_i = rtb_Hypot;

  /* Update for UnitDelay: '<S234>/UD'
   *
   * Block description for '<S234>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_l = rtb_MatrixConcatenate_idx_0;

  /* Update for UnitDelay: '<S220>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_l = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S161>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_f = rtb_Add_pw;

  /* Update for UnitDelay: '<S160>/UD'
   *
   * Block description for '<S160>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_h = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S172>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_b = rtb_Subtract_i;

  /* Update for UnitDelay: '<S171>/UD'
   *
   * Block description for '<S171>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_b = rtb_Product_f;

  /* Update for UnitDelay: '<S157>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_e = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S182>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_e = rtb_Minus_k_idx_1;

  /* Update for UnitDelay: '<S181>/UD'
   *
   * Block description for '<S181>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_m = rtb_Minus_k_idx_0;

  /* Update for UnitDelay: '<S193>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n = rtb_Hypot_b;

  /* Update for UnitDelay: '<S192>/UD'
   *
   * Block description for '<S192>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_i = rtb_Product_k5;

  /* Update for UnitDelay: '<S178>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_dt = rtb_Integral_k;

  /* Update for UnitDelay: '<S203>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_n4 = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S202>/UD'
   *
   * Block description for '<S202>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_o = rtb_Product_lb;

  /* Update for UnitDelay: '<S214>/Unit Delay1' */
  Robot_Control_DW.UnitDelay1_DSTATE_nw = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S213>/UD'
   *
   * Block description for '<S213>/UD':
   *
   *  Store in Global RAM
   */
  Robot_Control_DW.UD_DSTATE_k = rtb_Product_kx;

  /* Update for UnitDelay: '<S199>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_k = rtb_UnitDelay3;

  /* Update for UnitDelay: '<S336>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_id = rtb_Switch2_p;

  /* Update for UnitDelay: '<S337>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_n = rtb_Add_f1;
}

/* Model initialize function */
void Robot_Control_initialize(void)
{
  /* Start for SwitchCase: '<S1>/Switch Case' */
  Robot_Control_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S10>/If' */
  Robot_Control_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay2' */
  Robot_Control_DW.UnitDelay2_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S79>/Delay' */
  Robot_Control_DW.icLoad = true;

  /* InitializeConditions for UnitDelay: '<S248>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S265>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S258>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S321>/FixPt Unit Delay2' */
  Robot_Control_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S10>/Spline Path Following Enabled' */
  /* Start for If: '<S93>/If' */
  Robot_Control_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S89>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S93>/Robot_Index_Is_Valid' */
  /* Start for If: '<S96>/If' */
  Robot_Control_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S96>/Circle_Check_Valid' */
  /* Start for If: '<S98>/If' */
  Robot_Control_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S96>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S93>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S10>/Spline Path Following Enabled' */
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
