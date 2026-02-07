/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Odometry.c
 *
 * Code generated for Simulink model 'Odometry'.
 *
 * Model version                  : 2.434
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Feb  7 16:26:24 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Odometry.h"
#include "rt_modd_snf.h"
#include <math.h>
#include "rtwtypes.h"
#include "Odometry_private.h"
#include "rt_nonfinite.h"

/* Exported block parameters */
real_T Auto_Starting_Position = 2.0;   /* Variable: Auto_Starting_Position
                                        * Referenced by: '<S2>/Constant2'
                                        */
real_T Gyro_Calibration_Auto_Center = 180.0;/* Variable: Gyro_Calibration_Auto_Center
                                             * Referenced by: '<S2>/Constant5'
                                             */
real_T Gyro_Calibration_Auto_Left = 210.0;/* Variable: Gyro_Calibration_Auto_Left
                                           * Referenced by: '<S2>/Constant4'
                                           */
real_T Gyro_Calibration_Auto_Right = 125.0;/* Variable: Gyro_Calibration_Auto_Right
                                            * Referenced by: '<S2>/Constant6'
                                            */
real_T Gyro_Calibration_Default = 0.0; /* Variable: Gyro_Calibration_Default
                                        * Referenced by:
                                        *   '<S2>/Constant7'
                                        *   '<S2>/Unit Delay1'
                                        */
real_T Gyro_Calibration_Reset_Flag = 0.0;/* Variable: Gyro_Calibration_Reset_Flag
                                          * Referenced by: '<S2>/Constant3'
                                          */
real_T Odometry_IC_X = 0.0;            /* Variable: Odometry_IC_X
                                        * Referenced by: '<S1>/Constant'
                                        */
real_T Odometry_IC_Y = 0.0;            /* Variable: Odometry_IC_Y
                                        * Referenced by: '<S1>/Constant1'
                                        */
real_T Odometry_Reset_IC = 0.0;        /* Variable: Odometry_Reset_IC
                                        * Referenced by: '<S3>/Constant'
                                        */
real_T Odometry_X_Y_TEAR = 0.0;        /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S17>/Constant'
                                        */

/* Block signals (default storage) */
B_Odometry_T Odometry_B;

/* Block states (default storage) */
DW_Odometry_T Odometry_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Odometry_T Odometry_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Odometry_T Odometry_Y;

/* Real-time model */
static RT_MODEL_Odometry_T Odometry_M_;
RT_MODEL_Odometry_T *const Odometry_M = &Odometry_M_;

/* Model step function */
void Odometry_step(void)
{
  real_T rtb_TmpSignalConversionAtProduc[8];
  real_T rtb_rx_2[8];
  real_T rtb_Product7[2];
  real_T rtb_Subtract2;
  real_T rtb_Switch;
  real_T rtb_Switch1;
  real_T rtb_Switch1_c;
  real_T rtb_TmpSignalConversionAtProd_0;
  real_T rtb_TmpSignalConversionAtProd_1;
  real_T rtb_TmpSignalConversionAtProd_2;
  real_T rtb_TmpSignalConversionAtProd_3;
  real_T rtb_TmpSignalConversionAtProd_4;
  real_T rtb_rx;
  real_T rtb_rx_g;
  real_T rtb_rx_n;
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  boolean_T rtb_Compare;

  /* Sum: '<S24>/Add1' incorporates:
   *  Constant: '<S24>/Constant3'
   *  Constant: '<S24>/Constant4'
   *  Gain: '<S5>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Rev'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S24>/Math Function'
   *  Sum: '<S24>/Add2'
   *  Sum: '<S5>/Add'
   */
  Odometry_B.FL_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.FrontLeft_Steer_Rev - Odometry_U.FrontLeft_Turn_Offset) *
      6.2831853071795862) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *  Sum: '<S9>/Diff'
   *  UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  rtb_rx = (Odometry_U.FrontLeft_Drive_Motor_Rev - Odometry_DW.UD_DSTATE) *
    0.049546817471321378;

  /* Sum: '<S25>/Add1' incorporates:
   *  Constant: '<S25>/Constant3'
   *  Constant: '<S25>/Constant4'
   *  Gain: '<S5>/Revolutions to Radians1'
   *  Inport: '<Root>/FrontRight_Steer_Rev'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S25>/Math Function'
   *  Sum: '<S25>/Add2'
   *  Sum: '<S5>/Add1'
   */
  Odometry_B.FR_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.FrontRight_Steer_Rev - Odometry_U.FrontRight_Turn_Offset) *
      6.2831853071795862) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *  Sum: '<S10>/Diff'
   *  UnitDelay: '<S10>/UD'
   *
   * Block description for '<S10>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  rtb_rx_n = (Odometry_U.FrontRight_Drive_Motor_Rev - Odometry_DW.UD_DSTATE_i) *
    0.049546817471321378;

  /* Sum: '<S26>/Add1' incorporates:
   *  Constant: '<S26>/Constant3'
   *  Constant: '<S26>/Constant4'
   *  Gain: '<S5>/Revolutions to Radians2'
   *  Inport: '<Root>/BackLeft_Steer_Rev'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S26>/Math Function'
   *  Sum: '<S26>/Add2'
   *  Sum: '<S5>/Add2'
   */
  Odometry_B.BL_Steer_Module_Angle = rt_modd_snf(((Odometry_U.BackLeft_Steer_Rev
    - Odometry_U.BackLeft_Turn_Offset) * 6.2831853071795862) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S3>/Product2' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *  Sum: '<S11>/Diff'
   *  UnitDelay: '<S11>/UD'
   *
   * Block description for '<S11>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S11>/UD':
   *
   *  Store in Global RAM
   */
  rtb_rx_g = (Odometry_U.BackLeft_Drive_Motor_Rev - Odometry_DW.UD_DSTATE_iy) *
    0.049546817471321378;

  /* Sum: '<S27>/Add1' incorporates:
   *  Constant: '<S27>/Constant3'
   *  Constant: '<S27>/Constant4'
   *  Gain: '<S5>/Revolutions to Radians3'
   *  Inport: '<Root>/BackRight_Steer_Rev'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S27>/Math Function'
   *  Sum: '<S27>/Add2'
   *  Sum: '<S5>/Add3'
   */
  Odometry_B.BR_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.BackRight_Steer_Rev - Odometry_U.BackRight_Turn_Offset) *
      6.2831853071795862) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Product: '<S3>/Product3' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *  Sum: '<S12>/Diff'
   *  UnitDelay: '<S12>/UD'
   *
   * Block description for '<S12>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S12>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Subtract2 = (Odometry_U.BackRight_Drive_Motor_Rev -
                   Odometry_DW.UD_DSTATE_f) * 0.049546817471321378;

  /* Fcn: '<S13>/r->x' incorporates:
   *  Fcn: '<S20>/r->x'
   */
  rtb_Switch1 = cos(Odometry_B.FL_Steer_Module_Angle);

  /* Fcn: '<S13>/theta->y' incorporates:
   *  Fcn: '<S20>/theta->y'
   */
  rtb_Switch = sin(Odometry_B.FL_Steer_Module_Angle);

  /* Fcn: '<S14>/r->x' incorporates:
   *  Fcn: '<S21>/r->x'
   */
  rtb_Switch1_c = cos(Odometry_B.FR_Steer_Module_Angle);

  /* Fcn: '<S14>/theta->y' incorporates:
   *  Fcn: '<S21>/theta->y'
   */
  rtb_TmpSignalConversionAtProd_0 = sin(Odometry_B.FR_Steer_Module_Angle);

  /* Fcn: '<S15>/r->x' incorporates:
   *  Fcn: '<S22>/r->x'
   */
  rtb_TmpSignalConversionAtProd_1 = cos(Odometry_B.BL_Steer_Module_Angle);

  /* Fcn: '<S15>/theta->y' incorporates:
   *  Fcn: '<S22>/theta->y'
   */
  rtb_TmpSignalConversionAtProd_2 = sin(Odometry_B.BL_Steer_Module_Angle);

  /* Fcn: '<S16>/r->x' incorporates:
   *  Fcn: '<S23>/r->x'
   */
  rtb_TmpSignalConversionAtProd_3 = cos(Odometry_B.BR_Steer_Module_Angle);

  /* Fcn: '<S16>/theta->y' incorporates:
   *  Fcn: '<S23>/theta->y'
   */
  rtb_TmpSignalConversionAtProd_4 = sin(Odometry_B.BR_Steer_Module_Angle);

  /* SignalConversion generated from: '<S3>/Product7' incorporates:
   *  Fcn: '<S13>/r->x'
   *  Fcn: '<S13>/theta->y'
   *  Fcn: '<S14>/r->x'
   *  Fcn: '<S14>/theta->y'
   *  Fcn: '<S15>/r->x'
   *  Fcn: '<S15>/theta->y'
   *  Fcn: '<S16>/r->x'
   *  Fcn: '<S16>/theta->y'
   */
  rtb_TmpSignalConversionAtProduc[0] = rtb_rx * rtb_Switch1;
  rtb_TmpSignalConversionAtProduc[1] = rtb_rx * rtb_Switch;
  rtb_TmpSignalConversionAtProduc[2] = rtb_rx_n * rtb_Switch1_c;
  rtb_TmpSignalConversionAtProduc[3] = rtb_rx_n *
    rtb_TmpSignalConversionAtProd_0;
  rtb_TmpSignalConversionAtProduc[4] = rtb_rx_g *
    rtb_TmpSignalConversionAtProd_1;
  rtb_TmpSignalConversionAtProduc[5] = rtb_rx_g *
    rtb_TmpSignalConversionAtProd_2;
  rtb_TmpSignalConversionAtProduc[6] = rtb_Subtract2 *
    rtb_TmpSignalConversionAtProd_3;
  rtb_TmpSignalConversionAtProduc[7] = rtb_Subtract2 *
    rtb_TmpSignalConversionAtProd_4;

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_rx = (0.016666666666666666 * Odometry_U.FrontLeft_Drive_Motor_Speed) *
    0.049546817471321378;

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Subtract2 = (0.016666666666666666 *
                   Odometry_U.FrontRight_Drive_Motor_Speed) *
    0.049546817471321378;

  /* Product: '<S4>/Product2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain2'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_rx_n = (0.016666666666666666 * Odometry_U.BackLeft_Drive_Motor_Speed) *
    0.049546817471321378;

  /* Product: '<S4>/Product3' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain3'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_rx_g = (0.016666666666666666 * Odometry_U.BackRight_Drive_Motor_Speed) *
    0.049546817471321378;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S20>/r->x'
   *  Fcn: '<S20>/theta->y'
   *  Fcn: '<S21>/r->x'
   *  Fcn: '<S21>/theta->y'
   *  Fcn: '<S22>/r->x'
   *  Fcn: '<S22>/theta->y'
   *  Fcn: '<S23>/r->x'
   *  Fcn: '<S23>/theta->y'
   */
  rtb_rx_2[0] = rtb_rx * rtb_Switch1;
  rtb_rx_2[1] = rtb_rx * rtb_Switch;
  rtb_rx_2[2] = rtb_Subtract2 * rtb_Switch1_c;
  rtb_rx_2[3] = rtb_Subtract2 * rtb_TmpSignalConversionAtProd_0;
  rtb_rx_2[4] = rtb_rx_n * rtb_TmpSignalConversionAtProd_1;
  rtb_rx_2[5] = rtb_rx_n * rtb_TmpSignalConversionAtProd_2;
  rtb_rx_2[6] = rtb_rx_g * rtb_TmpSignalConversionAtProd_3;
  rtb_rx_2[7] = rtb_rx_g * rtb_TmpSignalConversionAtProd_4;

  /* Product: '<S4>/Product7' incorporates:
   *  Constant: '<S4>/Constant4'
   */
  for (i = 0; i < 2; i++) {
    rtb_Switch1 = 0.0;
    tmp = 0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_Switch1 += rtCP_Constant4_Value_d[tmp + i] * rtb_rx_2[i_0];
      tmp += 2;
    }

    rtb_Product7[i] = rtb_Switch1;
  }

  /* End of Product: '<S4>/Product7' */

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Inport: '<Root>/Gyro_Angle'
   *  RelationalOperator: '<S7>/FixPt Relational Operator'
   *  Sum: '<S2>/Sum'
   *  UnitDelay: '<S2>/Unit Delay1'
   *  UnitDelay: '<S7>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Gyro_Calibration_Reset_Flag > Odometry_DW.DelayInput1_DSTATE) {
    /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant4'
     *  Constant: '<S2>/Constant5'
     *  Constant: '<S2>/Constant6'
     *  Constant: '<S2>/Constant7'
     */
    switch ((int32_T)Auto_Starting_Position) {
     case 1:
      rtb_Switch1 = Gyro_Calibration_Auto_Left;
      break;

     case 2:
      rtb_Switch1 = Gyro_Calibration_Auto_Center;
      break;

     case 3:
      rtb_Switch1 = Gyro_Calibration_Auto_Right;
      break;

     default:
      rtb_Switch1 = Gyro_Calibration_Default;
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch' */
    rtb_Switch1 -= Odometry_U.Gyro_Angle;
  } else {
    rtb_Switch1 = Odometry_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Sum: '<S2>/Subtract1' incorporates:
   *  Inport: '<Root>/Gyro_Angle'
   */
  Odometry_B.Gyro_Angle_Calibrated_deg = Odometry_U.Gyro_Angle + rtb_Switch1;

  /* Gain: '<S6>/Gain1' */
  Odometry_B.Gyro_Angle_rad = 0.017453292519943295 *
    Odometry_B.Gyro_Angle_Calibrated_deg;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Odometry_U.IsBlueAlliance != 0.0) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = 3.1415926535897931;
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Switch: '<S2>/Switch'
   */
  Odometry_B.Gyro_Angle_Field_rad = Odometry_B.Gyro_Angle_rad + rtb_Switch;

  /* Trigonometry: '<S4>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  rtb_rx_n = cos(Odometry_B.Gyro_Angle_Field_rad);

  /* Trigonometry: '<S4>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  rtb_rx_g = sin(Odometry_B.Gyro_Angle_Field_rad);

  /* Sum: '<S19>/Diff' incorporates:
   *  UnitDelay: '<S19>/UD'
   *
   * Block description for '<S19>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S19>/UD':
   *
   *  Store in Global RAM
   */
  rtb_rx = Odometry_B.Gyro_Angle_Field_rad - Odometry_DW.UD_DSTATE_m;

  /* Sum: '<S4>/Subtract2' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Gain: '<S4>/Gain7'
   *  Math: '<S4>/Square'
   */
  rtb_Subtract2 = 1.0 - ((rtb_rx * rtb_rx) * 0.16666666666666666);

  /* Gain: '<S4>/Gain6' */
  rtb_rx *= 0.5;

  /* Product: '<S4>/Product6' incorporates:
   *  SignalConversion generated from: '<S4>/POSE exponential matrix for improved accuracy while rotating'
   *  UnaryMinus: '<S4>/Unary Minus2'
   */
  rtb_Switch = (rtb_Subtract2 * rtb_Product7[0]) + ((-rtb_rx) * rtb_Product7[1]);
  rtb_rx = (rtb_rx * rtb_Product7[0]) + (rtb_Subtract2 * rtb_Product7[1]);

  /* Product: '<S4>/Product6' incorporates:
   *  Trigonometry: '<S4>/Trigonometric Function'
   *  Trigonometry: '<S4>/Trigonometric Function1'
   *  UnaryMinus: '<S4>/Unary Minus'
   */
  Odometry_B.Product6[0] = (rtb_rx_n * rtb_Switch) + ((-rtb_rx_g) * rtb_rx);
  Odometry_B.Product6[1] = (rtb_rx_g * rtb_Switch) + (rtb_rx_n * rtb_rx);

  /* Outport: '<Root>/Robot_Velocity_X' */
  Odometry_Y.Robot_Velocity_X = Odometry_B.Product6[0];

  /* Outport: '<Root>/Robot_Velocity_Y' */
  Odometry_Y.Robot_Velocity_Y = Odometry_B.Product6[1];

  /* Sum: '<S8>/Diff' incorporates:
   *  UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  rtb_rx = Odometry_B.Gyro_Angle_Field_rad - Odometry_DW.UD_DSTATE_h;

  /* Sum: '<S3>/Subtract2' incorporates:
   *  Constant: '<S3>/Constant3'
   *  Gain: '<S3>/Gain7'
   *  Math: '<S3>/Square'
   */
  rtb_Subtract2 = 1.0 - ((rtb_rx * rtb_rx) * 0.16666666666666666);

  /* Gain: '<S3>/Gain6' */
  rtb_rx *= 0.5;

  /* Product: '<S3>/Product7' incorporates:
   *  Constant: '<S3>/Constant4'
   */
  for (i = 0; i < 2; i++) {
    rtb_Switch = 0.0;
    tmp = 0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_Switch += rtCP_Constant4_Value[tmp + i] *
        rtb_TmpSignalConversionAtProduc[i_0];
      tmp += 2;
    }

    rtb_Product7[i] = rtb_Switch;
  }

  /* End of Product: '<S3>/Product7' */

  /* Product: '<S3>/Product6' incorporates:
   *  SignalConversion generated from: '<S3>/POSE exponential matrix for improved accuracy while rotating'
   *  UnaryMinus: '<S3>/Unary Minus2'
   */
  rtb_Switch = (rtb_Subtract2 * rtb_Product7[0]) + ((-rtb_rx) * rtb_Product7[1]);
  rtb_rx = (rtb_rx * rtb_Product7[0]) + (rtb_Subtract2 * rtb_Product7[1]);

  /* Product: '<S3>/Product6' incorporates:
   *  Trigonometry: '<S4>/Trigonometric Function1'
   *  UnaryMinus: '<S4>/Unary Minus'
   */
  Odometry_B.Product6_k[0] = (rtb_rx_n * rtb_Switch) + ((-rtb_rx_g) * rtb_rx);
  Odometry_B.Product6_k[1] = (rtb_rx_g * rtb_Switch) + (rtb_rx_n * rtb_rx);

  /* Outport: '<Root>/Odom_Delta_X' */
  Odometry_Y.Odom_Delta_X = Odometry_B.Product6_k[0];

  /* Outport: '<Root>/Odom_Delta_Y' */
  Odometry_Y.Odom_Delta_Y = Odometry_B.Product6_k[1];

  /* Outport: '<Root>/Gyro_Angle_Field_rad' */
  Odometry_Y.Gyro_Angle_Field_rad = Odometry_B.Gyro_Angle_Field_rad;

  /* Outport: '<Root>/Gyro_Angle_rad' */
  Odometry_Y.Gyro_Angle_rad = Odometry_B.Gyro_Angle_rad;

  /* Outport: '<Root>/Auto_Start_Position' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  Odometry_Y.Auto_Start_Position = Auto_Starting_Position;

  /* Outport: '<Root>/BR_Steer_Module_Angle' */
  Odometry_Y.BR_Steer_Module_Angle = Odometry_B.BR_Steer_Module_Angle;

  /* Outport: '<Root>/BL_Steer_Module_Angle' */
  Odometry_Y.BL_Steer_Module_Angle = Odometry_B.BL_Steer_Module_Angle;

  /* Outport: '<Root>/FR_Steer_Module_Angle' */
  Odometry_Y.FR_Steer_Module_Angle = Odometry_B.FR_Steer_Module_Angle;

  /* Outport: '<Root>/FL_Steer_Module_Angle' */
  Odometry_Y.FL_Steer_Module_Angle = Odometry_B.FL_Steer_Module_Angle;

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   */
  rtb_Compare = (Odometry_X_Y_TEAR != 0.0);

  /* DiscreteIntegrator: '<S3>/Accumulator2' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S3>/Constant'
   */
  if ((Odometry_Reset_IC > 0.0) && (Odometry_DW.Accumulator2_PrevResetState <= 0))
  {
    Odometry_DW.Accumulator2_DSTATE = Odometry_IC_X;
  }

  /* DiscreteIntegrator: '<S3>/Accumulator2' */
  Odometry_B.Odom_Position_X = Odometry_DW.Accumulator2_DSTATE;

  /* Gain: '<S17>/meters to feet' */
  Odometry_B.Odometry_X_global_est_ft = 3.28084 * Odometry_B.Odom_Position_X;

  /* Switch: '<S17>/Switch' incorporates:
   *  UnitDelay: '<S17>/Unit Delay'
   */
  if (rtb_Compare) {
    rtb_Switch = Odometry_B.Odometry_X_global_est_ft;
  } else {
    rtb_Switch = Odometry_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Sum: '<S17>/Subtract' */
  Odometry_B.Odometry_X_global_TEAR_ft = Odometry_B.Odometry_X_global_est_ft -
    rtb_Switch;

  /* Outport: '<Root>/Odom_Position_X' */
  Odometry_Y.Odom_Position_X = Odometry_B.Odom_Position_X;

  /* DiscreteIntegrator: '<S3>/Accumulator' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S3>/Constant'
   */
  if ((Odometry_Reset_IC > 0.0) && (Odometry_DW.Accumulator_PrevResetState <= 0))
  {
    Odometry_DW.Accumulator_DSTATE = Odometry_IC_Y;
  }

  /* DiscreteIntegrator: '<S3>/Accumulator' */
  Odometry_B.Odom_Position_Y = Odometry_DW.Accumulator_DSTATE;

  /* Outport: '<Root>/Odom_Position_Y' */
  Odometry_Y.Odom_Position_Y = Odometry_B.Odom_Position_Y;

  /* Gain: '<S17>/meters to feet1' */
  Odometry_B.Odometry_Y_global_est_ft = 3.28084 * Odometry_B.Odom_Position_Y;

  /* Switch: '<S17>/Switch1' incorporates:
   *  UnitDelay: '<S17>/Unit Delay1'
   */
  if (rtb_Compare) {
    rtb_Switch1_c = Odometry_B.Odometry_Y_global_est_ft;
  } else {
    rtb_Switch1_c = Odometry_DW.UnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S17>/Switch1' */

  /* Sum: '<S17>/Subtract1' */
  Odometry_B.Odometry_Y_global_TEAR_ft = Odometry_B.Odometry_Y_global_est_ft -
    rtb_Switch1_c;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant2'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Odometry_B.loop_counter_odometry++;

  /* Update for UnitDelay: '<S9>/UD' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE = Odometry_U.FrontLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S10>/UD' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_i = Odometry_U.FrontRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S11>/UD' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *
   * Block description for '<S11>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_iy = Odometry_U.BackLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S12>/UD' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *
   * Block description for '<S12>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_f = Odometry_U.BackRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S7>/Delay Input1' incorporates:
   *  Constant: '<S2>/Constant3'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Odometry_DW.DelayInput1_DSTATE = Gyro_Calibration_Reset_Flag;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  Odometry_DW.UnitDelay1_DSTATE = rtb_Switch1;

  /* Update for UnitDelay: '<S19>/UD'
   *
   * Block description for '<S19>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_m = Odometry_B.Gyro_Angle_Field_rad;

  /* Update for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_h = Odometry_B.Gyro_Angle_Field_rad;

  /* Update for DiscreteIntegrator: '<S3>/Accumulator2' incorporates:
   *  Constant: '<S3>/Constant'
   *  DiscreteIntegrator: '<S3>/Accumulator'
   */
  Odometry_DW.Accumulator2_DSTATE += Odometry_B.Product6_k[0];
  if (Odometry_Reset_IC > 0.0) {
    Odometry_DW.Accumulator2_PrevResetState = 1;
    Odometry_DW.Accumulator_PrevResetState = 1;
  } else {
    if (Odometry_Reset_IC < 0.0) {
      Odometry_DW.Accumulator2_PrevResetState = -1;
    } else if (Odometry_Reset_IC == 0.0) {
      Odometry_DW.Accumulator2_PrevResetState = 0;
    } else {
      Odometry_DW.Accumulator2_PrevResetState = 2;
    }

    if (Odometry_Reset_IC < 0.0) {
      Odometry_DW.Accumulator_PrevResetState = -1;
    } else if (Odometry_Reset_IC == 0.0) {
      Odometry_DW.Accumulator_PrevResetState = 0;
    } else {
      Odometry_DW.Accumulator_PrevResetState = 2;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Accumulator2' */

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  Odometry_DW.UnitDelay_DSTATE = rtb_Switch;

  /* Update for DiscreteIntegrator: '<S3>/Accumulator' */
  Odometry_DW.Accumulator_DSTATE += Odometry_B.Product6_k[1];

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  Odometry_DW.UnitDelay1_DSTATE_d = rtb_Switch1_c;
}

/* Model initialize function */
void Odometry_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T Constant;
    real_T Constant1;

    /* Start for Constant: '<S1>/Constant' */
    Constant = Odometry_IC_X;

    /* Start for Constant: '<S1>/Constant1' */
    Constant1 = Odometry_IC_Y;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
    Odometry_DW.UnitDelay1_DSTATE = Gyro_Calibration_Default;

    /* InitializeConditions for DiscreteIntegrator: '<S3>/Accumulator2' */
    Odometry_DW.Accumulator2_DSTATE = Constant;
    Odometry_DW.Accumulator2_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S3>/Accumulator' */
    Odometry_DW.Accumulator_DSTATE = Constant1;
    Odometry_DW.Accumulator_PrevResetState = 2;
  }
}

/* Model terminate function */
void Odometry_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
