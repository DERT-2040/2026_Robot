/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Odometry.c
 *
 * Code generated for Simulink model 'Odometry'.
 *
 * Model version                  : 2.431
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Dec 20 08:47:34 2025
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
                                        * Referenced by: '<S16>/Constant'
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
  real_T rtb_thetay_2[8];
  real_T rtb_Product7[2];
  real_T rtb_POSEexponentialmatrixfori_0;
  real_T rtb_Rotationmatrixfromlocalto_0;
  real_T rtb_Rotationmatrixfromlocalto_1;
  real_T rtb_Subtract2;
  real_T rtb_thetay;
  real_T rtb_thetay_o;
  real_T rtb_thetay_p;
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  boolean_T rtb_Compare;

  /* Sum: '<S18>/Add1' incorporates:
   *  Constant: '<S18>/Constant3'
   *  Constant: '<S18>/Constant4'
   *  Gain: '<S4>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Rev'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S18>/Math Function'
   *  Sum: '<S18>/Add2'
   *  Sum: '<S4>/Add'
   */
  Odometry_B.FL_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.FrontLeft_Steer_Rev - Odometry_U.FrontLeft_Turn_Offset) *
      6.2831853071795862) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *  Sum: '<S8>/Diff'
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
  rtb_thetay = (Odometry_U.FrontLeft_Drive_Motor_Rev - Odometry_DW.UD_DSTATE) *
    0.049546817471321378;

  /* Sum: '<S19>/Add1' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Constant: '<S19>/Constant4'
   *  Gain: '<S4>/Revolutions to Radians1'
   *  Inport: '<Root>/FrontRight_Steer_Rev'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S19>/Math Function'
   *  Sum: '<S19>/Add2'
   *  Sum: '<S4>/Add1'
   */
  Odometry_B.FR_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.FrontRight_Steer_Rev - Odometry_U.FrontRight_Turn_Offset) *
      6.2831853071795862) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
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
  rtb_thetay_p = (Odometry_U.FrontRight_Drive_Motor_Rev -
                  Odometry_DW.UD_DSTATE_i) * 0.049546817471321378;

  /* Sum: '<S20>/Add1' incorporates:
   *  Constant: '<S20>/Constant3'
   *  Constant: '<S20>/Constant4'
   *  Gain: '<S4>/Revolutions to Radians2'
   *  Inport: '<Root>/BackLeft_Steer_Rev'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S20>/Math Function'
   *  Sum: '<S20>/Add2'
   *  Sum: '<S4>/Add2'
   */
  Odometry_B.BL_Steer_Module_Angle = rt_modd_snf(((Odometry_U.BackLeft_Steer_Rev
    - Odometry_U.BackLeft_Turn_Offset) * 6.2831853071795862) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S3>/Product2' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
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
  rtb_thetay_o = (Odometry_U.BackLeft_Drive_Motor_Rev - Odometry_DW.UD_DSTATE_iy)
    * 0.049546817471321378;

  /* Sum: '<S21>/Add1' incorporates:
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S21>/Constant4'
   *  Gain: '<S4>/Revolutions to Radians3'
   *  Inport: '<Root>/BackRight_Steer_Rev'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S21>/Math Function'
   *  Sum: '<S21>/Add2'
   *  Sum: '<S4>/Add3'
   */
  Odometry_B.BR_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.BackRight_Steer_Rev - Odometry_U.BackRight_Turn_Offset) *
      6.2831853071795862) + 3.1415926535897931, 6.2831853071795862) -
    3.1415926535897931;

  /* Product: '<S3>/Product3' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
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
  rtb_Subtract2 = (Odometry_U.BackRight_Drive_Motor_Rev -
                   Odometry_DW.UD_DSTATE_f) * 0.049546817471321378;

  /* SignalConversion generated from: '<S3>/Product7' incorporates:
   *  Fcn: '<S12>/r->x'
   *  Fcn: '<S12>/theta->y'
   *  Fcn: '<S13>/r->x'
   *  Fcn: '<S13>/theta->y'
   *  Fcn: '<S14>/r->x'
   *  Fcn: '<S14>/theta->y'
   *  Fcn: '<S15>/r->x'
   *  Fcn: '<S15>/theta->y'
   */
  rtb_thetay_2[0] = rtb_thetay * cos(Odometry_B.FL_Steer_Module_Angle);
  rtb_thetay_2[1] = rtb_thetay * sin(Odometry_B.FL_Steer_Module_Angle);
  rtb_thetay_2[2] = rtb_thetay_p * cos(Odometry_B.FR_Steer_Module_Angle);
  rtb_thetay_2[3] = rtb_thetay_p * sin(Odometry_B.FR_Steer_Module_Angle);
  rtb_thetay_2[4] = rtb_thetay_o * cos(Odometry_B.BL_Steer_Module_Angle);
  rtb_thetay_2[5] = rtb_thetay_o * sin(Odometry_B.BL_Steer_Module_Angle);
  rtb_thetay_2[6] = rtb_Subtract2 * cos(Odometry_B.BR_Steer_Module_Angle);
  rtb_thetay_2[7] = rtb_Subtract2 * sin(Odometry_B.BR_Steer_Module_Angle);

  /* Product: '<S3>/Product7' incorporates:
   *  Constant: '<S3>/Constant4'
   */
  for (i = 0; i < 2; i++) {
    rtb_thetay = 0.0;
    tmp = 0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_thetay += rtCP_Constant4_Value[tmp + i] * rtb_thetay_2[i_0];
      tmp += 2;
    }

    rtb_Product7[i] = rtb_thetay;
  }

  /* End of Product: '<S3>/Product7' */

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Inport: '<Root>/Gyro_Angle'
   *  RelationalOperator: '<S6>/FixPt Relational Operator'
   *  Sum: '<S2>/Sum'
   *  UnitDelay: '<S2>/Unit Delay1'
   *  UnitDelay: '<S6>/Delay Input1'
   *
   * Block description for '<S6>/Delay Input1':
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
      rtb_Subtract2 = Gyro_Calibration_Auto_Left;
      break;

     case 2:
      rtb_Subtract2 = Gyro_Calibration_Auto_Center;
      break;

     case 3:
      rtb_Subtract2 = Gyro_Calibration_Auto_Right;
      break;

     default:
      rtb_Subtract2 = Gyro_Calibration_Default;
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch' */
    rtb_thetay = rtb_Subtract2 - Odometry_U.Gyro_Angle;
  } else {
    rtb_thetay = Odometry_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Sum: '<S2>/Subtract1' incorporates:
   *  Inport: '<Root>/Gyro_Angle'
   */
  Odometry_B.Gyro_Angle_Calibrated_deg = Odometry_U.Gyro_Angle + rtb_thetay;

  /* Gain: '<S5>/Gain1' */
  Odometry_B.Gyro_Angle_rad = 0.017453292519943295 *
    Odometry_B.Gyro_Angle_Calibrated_deg;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Odometry_U.IsBlueAlliance != 0.0) {
    rtb_thetay_p = 0.0;
  } else {
    rtb_thetay_p = 3.1415926535897931;
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Switch: '<S2>/Switch'
   */
  Odometry_B.Gyro_Angle_Field_rad = Odometry_B.Gyro_Angle_rad + rtb_thetay_p;

  /* Trigonometry: '<S3>/Trigonometric Function1' */
  rtb_Subtract2 = sin(Odometry_B.Gyro_Angle_Field_rad);

  /* SignalConversion generated from: '<S3>/Rotation matrix from local to global' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  rtb_Rotationmatrixfromlocalto_0 = cos(Odometry_B.Gyro_Angle_Field_rad);
  rtb_thetay_o = rtb_Subtract2;

  /* SignalConversion generated from: '<S3>/Rotation matrix from local to global' incorporates:
   *  UnaryMinus: '<S3>/Unary Minus'
   */
  rtb_Rotationmatrixfromlocalto_1 = -rtb_Subtract2;

  /* Sum: '<S7>/Diff' incorporates:
   *  UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  rtb_thetay_p = Odometry_B.Gyro_Angle_Field_rad - Odometry_DW.UD_DSTATE_h;

  /* Sum: '<S3>/Subtract2' incorporates:
   *  Constant: '<S3>/Constant3'
   *  Gain: '<S3>/Gain7'
   *  Math: '<S3>/Square'
   */
  rtb_Subtract2 = 1.0 - ((rtb_thetay_p * rtb_thetay_p) * 0.16666666666666666);

  /* Gain: '<S3>/Gain6' */
  rtb_thetay_p *= 0.5;

  /* Product: '<S3>/Product6' incorporates:
   *  SignalConversion generated from: '<S3>/POSE exponential matrix for improved accuracy while rotating'
   *  UnaryMinus: '<S3>/Unary Minus2'
   */
  rtb_POSEexponentialmatrixfori_0 = (rtb_Subtract2 * rtb_Product7[0]) +
    ((-rtb_thetay_p) * rtb_Product7[1]);
  rtb_thetay_p = (rtb_thetay_p * rtb_Product7[0]) + (rtb_Subtract2 *
    rtb_Product7[1]);

  /* Product: '<S3>/Product6' incorporates:
   *  Concatenate: '<S3>/Rotation matrix from local to global'
   */
  Odometry_B.Product6[0] = (rtb_Rotationmatrixfromlocalto_0 *
    rtb_POSEexponentialmatrixfori_0) + (rtb_Rotationmatrixfromlocalto_1 *
    rtb_thetay_p);
  Odometry_B.Product6[1] = (rtb_thetay_o * rtb_POSEexponentialmatrixfori_0) +
    (rtb_Rotationmatrixfromlocalto_0 * rtb_thetay_p);

  /* Outport: '<Root>/Odom_Delta_X' */
  Odometry_Y.Odom_Delta_X = Odometry_B.Product6[0];

  /* Outport: '<Root>/Odom_Delta_Y' */
  Odometry_Y.Odom_Delta_Y = Odometry_B.Product6[1];

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

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
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

  /* Gain: '<S16>/meters to feet' */
  Odometry_B.Odometry_X_global_est_ft = 3.28084 * Odometry_B.Odom_Position_X;

  /* Switch: '<S16>/Switch' incorporates:
   *  UnitDelay: '<S16>/Unit Delay'
   */
  if (rtb_Compare) {
    rtb_Subtract2 = Odometry_B.Odometry_X_global_est_ft;
  } else {
    rtb_Subtract2 = Odometry_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Sum: '<S16>/Subtract' */
  Odometry_B.Odometry_X_global_TEAR_ft = Odometry_B.Odometry_X_global_est_ft -
    rtb_Subtract2;

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

  /* Gain: '<S16>/meters to feet1' */
  Odometry_B.Odometry_Y_global_est_ft = 3.28084 * Odometry_B.Odom_Position_Y;

  /* Switch: '<S16>/Switch1' incorporates:
   *  UnitDelay: '<S16>/Unit Delay1'
   */
  if (rtb_Compare) {
    rtb_thetay_p = Odometry_B.Odometry_Y_global_est_ft;
  } else {
    rtb_thetay_p = Odometry_DW.UnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* Sum: '<S16>/Subtract1' */
  Odometry_B.Odometry_Y_global_TEAR_ft = Odometry_B.Odometry_Y_global_est_ft -
    rtb_thetay_p;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant2'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Odometry_B.loop_counter_odometry++;

  /* Update for UnitDelay: '<S8>/UD' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE = Odometry_U.FrontLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S9>/UD' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_i = Odometry_U.FrontRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S10>/UD' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_iy = Odometry_U.BackLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S11>/UD' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *
   * Block description for '<S11>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_f = Odometry_U.BackRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S6>/Delay Input1' incorporates:
   *  Constant: '<S2>/Constant3'
   *
   * Block description for '<S6>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Odometry_DW.DelayInput1_DSTATE = Gyro_Calibration_Reset_Flag;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  Odometry_DW.UnitDelay1_DSTATE = rtb_thetay;

  /* Update for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_h = Odometry_B.Gyro_Angle_Field_rad;

  /* Update for DiscreteIntegrator: '<S3>/Accumulator2' incorporates:
   *  Constant: '<S3>/Constant'
   *  DiscreteIntegrator: '<S3>/Accumulator'
   */
  Odometry_DW.Accumulator2_DSTATE += Odometry_B.Product6[0];
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

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  Odometry_DW.UnitDelay_DSTATE = rtb_Subtract2;

  /* Update for DiscreteIntegrator: '<S3>/Accumulator' */
  Odometry_DW.Accumulator_DSTATE += Odometry_B.Product6[1];

  /* Update for UnitDelay: '<S16>/Unit Delay1' */
  Odometry_DW.UnitDelay1_DSTATE_d = rtb_thetay_p;
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
