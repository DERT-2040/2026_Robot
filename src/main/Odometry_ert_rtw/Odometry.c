/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Odometry.c
 *
 * Code generated for Simulink model 'Odometry'.
 *
 * Model version                  : 2.438
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Wed Jun  3 21:14:52 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Odometry.h"
#include "rt_modd_snf.h"
#include <math.h>
#include "rt_hypotd_snf.h"
#include "rtwtypes.h"
#include "Odometry_private.h"

/* Exported block parameters */
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
                                        * Referenced by: '<S23>/Constant'
                                        */
real_T RobotMaxV_GyroReset = 0.1;      /* Variable: RobotMaxV_GyroReset
                                        * Referenced by: '<S2>/Constant8'
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
  real_T rtb_Add1_l;
  real_T rtb_Product7_idx_0;
  real_T rtb_Product7_idx_1;
  real_T rtb_Switch;
  real_T rtb_Switch1;
  real_T rtb_TmpSignalConversionAtProd_0;
  real_T rtb_TmpSignalConversionAtProd_1;
  real_T rtb_TmpSignalConversionAtProd_2;
  real_T rtb_TmpSignalConversionAtProd_3;
  real_T rtb_rx;
  real_T rtb_rx_g;
  real_T rtb_rx_n;
  int32_T i;
  int32_T tmp;
  boolean_T rtb_Auto_Path_Reset;
  boolean_T rtb_FixPtRelationalOperator;

  /* Sum: '<S30>/Add1' incorporates:
   *  Constant: '<S30>/Constant3'
   *  Constant: '<S30>/Constant4'
   *  Gain: '<S5>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Rev'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S30>/Math Function'
   *  Sum: '<S30>/Add2'
   *  Sum: '<S5>/Add'
   */
  Odometry_B.FL_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.FrontLeft_Steer_Rev - Odometry_U.FrontLeft_Turn_Offset) *
      6.283185307179586) + 3.141592653589793, 6.283185307179586) -
    3.141592653589793;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *  Sum: '<S15>/Diff'
   *  UnitDelay: '<S15>/UD'
   *
   * Block description for '<S15>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S15>/UD':
   *
   *  Store in Global RAM
   */
  rtb_rx = (Odometry_U.FrontLeft_Drive_Motor_Rev - Odometry_DW.UD_DSTATE) *
    0.051958965164004126;

  /* Sum: '<S31>/Add1' incorporates:
   *  Constant: '<S31>/Constant3'
   *  Constant: '<S31>/Constant4'
   *  Gain: '<S5>/Revolutions to Radians1'
   *  Inport: '<Root>/FrontRight_Steer_Rev'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S31>/Math Function'
   *  Sum: '<S31>/Add2'
   *  Sum: '<S5>/Add1'
   */
  Odometry_B.FR_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.FrontRight_Steer_Rev - Odometry_U.FrontRight_Turn_Offset) *
      6.283185307179586) + 3.141592653589793, 6.283185307179586) -
    3.141592653589793;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *  Sum: '<S16>/Diff'
   *  UnitDelay: '<S16>/UD'
   *
   * Block description for '<S16>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S16>/UD':
   *
   *  Store in Global RAM
   */
  rtb_rx_n = (Odometry_U.FrontRight_Drive_Motor_Rev - Odometry_DW.UD_DSTATE_i) *
    0.051958965164004126;

  /* Sum: '<S32>/Add1' incorporates:
   *  Constant: '<S32>/Constant3'
   *  Constant: '<S32>/Constant4'
   *  Gain: '<S5>/Revolutions to Radians2'
   *  Inport: '<Root>/BackLeft_Steer_Rev'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S32>/Math Function'
   *  Sum: '<S32>/Add2'
   *  Sum: '<S5>/Add2'
   */
  Odometry_B.BL_Steer_Module_Angle = rt_modd_snf(((Odometry_U.BackLeft_Steer_Rev
    - Odometry_U.BackLeft_Turn_Offset) * 6.283185307179586) + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Product: '<S3>/Product2' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *  Sum: '<S17>/Diff'
   *  UnitDelay: '<S17>/UD'
   *
   * Block description for '<S17>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S17>/UD':
   *
   *  Store in Global RAM
   */
  rtb_rx_g = (Odometry_U.BackLeft_Drive_Motor_Rev - Odometry_DW.UD_DSTATE_iy) *
    0.051958965164004126;

  /* Sum: '<S33>/Add1' incorporates:
   *  Constant: '<S33>/Constant3'
   *  Constant: '<S33>/Constant4'
   *  Gain: '<S5>/Revolutions to Radians3'
   *  Inport: '<Root>/BackRight_Steer_Rev'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S33>/Math Function'
   *  Sum: '<S33>/Add2'
   *  Sum: '<S5>/Add3'
   */
  Odometry_B.BR_Steer_Module_Angle = rt_modd_snf
    (((Odometry_U.BackRight_Steer_Rev - Odometry_U.BackRight_Turn_Offset) *
      6.283185307179586) + 3.141592653589793, 6.283185307179586) -
    3.141592653589793;

  /* Product: '<S3>/Product3' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *  Sum: '<S18>/Diff'
   *  UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add1_l = (Odometry_U.BackRight_Drive_Motor_Rev - Odometry_DW.UD_DSTATE_f) *
    0.051958965164004126;

  /* Fcn: '<S19>/r->x' incorporates:
   *  Fcn: '<S26>/r->x'
   */
  rtb_Switch1 = cos(Odometry_B.FL_Steer_Module_Angle);

  /* Fcn: '<S19>/theta->y' incorporates:
   *  Fcn: '<S26>/theta->y'
   */
  rtb_Switch = sin(Odometry_B.FL_Steer_Module_Angle);

  /* Fcn: '<S20>/r->x' incorporates:
   *  Fcn: '<S27>/r->x'
   */
  rtb_TmpSignalConversionAtProd_0 = cos(Odometry_B.FR_Steer_Module_Angle);

  /* Fcn: '<S20>/theta->y' incorporates:
   *  Fcn: '<S27>/theta->y'
   */
  rtb_Product7_idx_0 = sin(Odometry_B.FR_Steer_Module_Angle);

  /* Fcn: '<S21>/r->x' incorporates:
   *  Fcn: '<S28>/r->x'
   */
  rtb_Product7_idx_1 = cos(Odometry_B.BL_Steer_Module_Angle);

  /* Fcn: '<S21>/theta->y' incorporates:
   *  Fcn: '<S28>/theta->y'
   */
  rtb_TmpSignalConversionAtProd_1 = sin(Odometry_B.BL_Steer_Module_Angle);

  /* Fcn: '<S22>/r->x' incorporates:
   *  Fcn: '<S29>/r->x'
   */
  rtb_TmpSignalConversionAtProd_2 = cos(Odometry_B.BR_Steer_Module_Angle);

  /* Fcn: '<S22>/theta->y' incorporates:
   *  Fcn: '<S29>/theta->y'
   */
  rtb_TmpSignalConversionAtProd_3 = sin(Odometry_B.BR_Steer_Module_Angle);

  /* SignalConversion generated from: '<S3>/Product7' incorporates:
   *  Fcn: '<S19>/r->x'
   *  Fcn: '<S19>/theta->y'
   *  Fcn: '<S20>/r->x'
   *  Fcn: '<S20>/theta->y'
   *  Fcn: '<S21>/r->x'
   *  Fcn: '<S21>/theta->y'
   *  Fcn: '<S22>/r->x'
   *  Fcn: '<S22>/theta->y'
   */
  rtb_TmpSignalConversionAtProduc[0] = rtb_rx * rtb_Switch1;
  rtb_TmpSignalConversionAtProduc[1] = rtb_rx * rtb_Switch;
  rtb_TmpSignalConversionAtProduc[2] = rtb_rx_n *
    rtb_TmpSignalConversionAtProd_0;
  rtb_TmpSignalConversionAtProduc[3] = rtb_rx_n * rtb_Product7_idx_0;
  rtb_TmpSignalConversionAtProduc[4] = rtb_rx_g * rtb_Product7_idx_1;
  rtb_TmpSignalConversionAtProduc[5] = rtb_rx_g *
    rtb_TmpSignalConversionAtProd_1;
  rtb_TmpSignalConversionAtProduc[6] = rtb_Add1_l *
    rtb_TmpSignalConversionAtProd_2;
  rtb_TmpSignalConversionAtProduc[7] = rtb_Add1_l *
    rtb_TmpSignalConversionAtProd_3;

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_rx = (0.016666666666666666 * Odometry_U.FrontLeft_Drive_Motor_Speed) *
    0.051958965164004126;

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_rx_n = (0.016666666666666666 * Odometry_U.FrontRight_Drive_Motor_Speed) *
    0.051958965164004126;

  /* Product: '<S4>/Product2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain2'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Add1_l = (0.016666666666666666 * Odometry_U.BackLeft_Drive_Motor_Speed) *
    0.051958965164004126;

  /* Product: '<S4>/Product3' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/Gain3'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_rx_g = (0.016666666666666666 * Odometry_U.BackRight_Drive_Motor_Speed) *
    0.051958965164004126;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S26>/r->x'
   *  Fcn: '<S26>/theta->y'
   *  Fcn: '<S27>/r->x'
   *  Fcn: '<S27>/theta->y'
   *  Fcn: '<S28>/r->x'
   *  Fcn: '<S28>/theta->y'
   *  Fcn: '<S29>/r->x'
   *  Fcn: '<S29>/theta->y'
   */
  rtb_rx_2[0] = rtb_rx * rtb_Switch1;
  rtb_rx_2[1] = rtb_rx * rtb_Switch;
  rtb_rx_2[2] = rtb_rx_n * rtb_TmpSignalConversionAtProd_0;
  rtb_rx_2[3] = rtb_rx_n * rtb_Product7_idx_0;
  rtb_rx_2[4] = rtb_Add1_l * rtb_Product7_idx_1;
  rtb_rx_2[5] = rtb_Add1_l * rtb_TmpSignalConversionAtProd_1;
  rtb_rx_2[6] = rtb_rx_g * rtb_TmpSignalConversionAtProd_2;
  rtb_rx_2[7] = rtb_rx_g * rtb_TmpSignalConversionAtProd_3;

  /* Product: '<S4>/Product7' incorporates:
   *  Constant: '<S4>/Constant4'
   */
  rtb_Product7_idx_0 = 0.0;
  rtb_Product7_idx_1 = 0.0;
  tmp = 0;
  for (i = 0; i < 8; i++) {
    rtb_rx_g = rtb_rx_2[i];
    rtb_Product7_idx_0 += rtCP_Constant4_Value_du[tmp] * rtb_rx_g;
    rtb_Product7_idx_1 += rtCP_Constant4_Value_du[tmp + 1] * rtb_rx_g;
    tmp += 2;
  }

  /* End of Product: '<S4>/Product7' */

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/IsBlueAlliance'
   */
  if (Odometry_U.IsBlueAlliance != 0.0) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = 3.141592653589793;
  }

  /* End of Switch: '<S2>/Switch' */

  /* RelationalOperator: '<S10>/FixPt Relational Operator' incorporates:
   *  Constant: '<S2>/Constant3'
   *  UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = (Gyro_Calibration_Reset_Flag >
    Odometry_DW.DelayInput1_DSTATE);

  /* Logic: '<S2>/AND1' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/GameState'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Auto_Path_Reset = ((Odometry_U.GameState == 1) &&
    (Odometry_DW.UnitDelay_DSTATE_dk != 1));

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant8'
   *  Inport: '<Root>/Vision_Gyro_Angle_Status'
   *  Logic: '<S2>/AND'
   *  Logic: '<S2>/NOT'
   *  Logic: '<S2>/OR'
   *  Math: '<S2>/Hypot'
   *  RelationalOperator: '<S2>/Less Than'
   *  UnitDelay: '<S1>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay2'
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if ((rtb_FixPtRelationalOperator || rtb_Auto_Path_Reset) ||
      ((!Odometry_U.Vision_Gyro_Angle_Status) && (rt_hypotd_snf
        (Odometry_DW.UnitDelay1_DSTATE, Odometry_DW.UnitDelay2_DSTATE) <
        RobotMaxV_GyroReset))) {
    /* Switch: '<S2>/Switch2' incorporates:
     *  Gain: '<S12>/Gain'
     *  Inport: '<Root>/Gyro_Angle'
     *  Inport: '<Root>/Vision_Gyro_Angle'
     *  Logic: '<S2>/AND2'
     *  Logic: '<S2>/NOT1'
     *  Logic: '<S2>/NOT2'
     *  Sum: '<S2>/Subtract'
     *  Switch: '<S2>/Switch3'
     */
    if ((!rtb_FixPtRelationalOperator) && (!rtb_Auto_Path_Reset)) {
      rtb_Switch1 = ((57.29577951308232 * rtb_Switch) +
                     Odometry_U.Vision_Gyro_Angle) - Odometry_U.Gyro_Angle;
    } else if (rtb_FixPtRelationalOperator) {
      /* Switch: '<S2>/Switch3' incorporates:
       *  Constant: '<S2>/Constant7'
       *  Inport: '<Root>/Gyro_Angle'
       *  Sum: '<S2>/Subtract2'
       */
      rtb_Switch1 = Gyro_Calibration_Default - Odometry_U.Gyro_Angle;
    } else {
      /* Switch: '<S2>/Switch3' incorporates:
       *  Gain: '<S13>/Gain'
       *  Inport: '<Root>/Auto_Initial_Gyro_Angle'
       *  Inport: '<Root>/Gyro_Angle'
       *  Sum: '<S2>/Subtract3'
       */
      rtb_Switch1 = Odometry_U.Gyro_Angle - (57.29577951308232 *
        Odometry_U.Auto_Initial_Gyro_Angle);
    }

    /* End of Switch: '<S2>/Switch2' */
  } else {
    rtb_Switch1 = Odometry_DW.UnitDelay1_DSTATE_f;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Sum: '<S2>/Subtract1' incorporates:
   *  Inport: '<Root>/Gyro_Angle'
   */
  Odometry_B.Gyro_Angle_Calibrated_deg = Odometry_U.Gyro_Angle + rtb_Switch1;

  /* Gain: '<S9>/Gain1' */
  rtb_rx = 0.017453292519943295 * Odometry_B.Gyro_Angle_Calibrated_deg;

  /* Sum: '<S8>/Add1' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Math: '<S8>/Math Function'
   *  Sum: '<S2>/Add'
   *  Sum: '<S8>/Add2'
   */
  Odometry_B.Gyro_Angle_Field_rad = rt_modd_snf((rtb_Switch + rtb_rx) +
    3.141592653589793, 6.283185307179586) - 3.141592653589793;

  /* Trigonometry: '<S4>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  rtb_Switch = cos(Odometry_B.Gyro_Angle_Field_rad);

  /* Trigonometry: '<S4>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  rtb_TmpSignalConversionAtProd_0 = sin(Odometry_B.Gyro_Angle_Field_rad);

  /* Sum: '<S25>/Diff' incorporates:
   *  UnitDelay: '<S25>/UD'
   *
   * Block description for '<S25>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S25>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add1_l = Odometry_B.Gyro_Angle_Field_rad - Odometry_DW.UD_DSTATE_m;

  /* Sum: '<S4>/Subtract2' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Gain: '<S4>/Gain7'
   *  Math: '<S4>/Square'
   */
  rtb_rx_n = 1.0 - ((rtb_Add1_l * rtb_Add1_l) * 0.16666666666666666);

  /* Gain: '<S4>/Gain6' */
  rtb_Add1_l *= 0.5;

  /* Product: '<S4>/Product6' incorporates:
   *  SignalConversion generated from: '<S4>/POSE exponential matrix for improved accuracy while rotating'
   *  Trigonometry: '<S4>/Trigonometric Function'
   *  Trigonometry: '<S4>/Trigonometric Function1'
   *  UnaryMinus: '<S4>/Unary Minus'
   *  UnaryMinus: '<S4>/Unary Minus2'
   */
  rtb_rx_g = (rtb_rx_n * rtb_Product7_idx_0) + ((-rtb_Add1_l) *
    rtb_Product7_idx_1);
  rtb_rx_n = (rtb_Add1_l * rtb_Product7_idx_0) + (rtb_rx_n * rtb_Product7_idx_1);
  Odometry_B.Product6[0] = rtb_Switch * rtb_rx_g;
  Odometry_B.Product6[1] = rtb_TmpSignalConversionAtProd_0 * rtb_rx_g;
  Odometry_B.Product6[0] += (-rtb_TmpSignalConversionAtProd_0) * rtb_rx_n;
  Odometry_B.Product6[1] += rtb_Switch * rtb_rx_n;

  /* Outport: '<Root>/Robot_Velocity_X' */
  Odometry_Y.Robot_Velocity_X = Odometry_B.Product6[0];

  /* Outport: '<Root>/Robot_Velocity_Y' */
  Odometry_Y.Robot_Velocity_Y = Odometry_B.Product6[1];

  /* Sum: '<S14>/Diff' incorporates:
   *  UnitDelay: '<S14>/UD'
   *
   * Block description for '<S14>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S14>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add1_l = Odometry_B.Gyro_Angle_Field_rad - Odometry_DW.UD_DSTATE_h;

  /* Sum: '<S3>/Subtract2' incorporates:
   *  Constant: '<S3>/Constant3'
   *  Gain: '<S3>/Gain7'
   *  Math: '<S3>/Square'
   */
  rtb_rx_n = 1.0 - ((rtb_Add1_l * rtb_Add1_l) * 0.16666666666666666);

  /* Gain: '<S3>/Gain6' */
  rtb_Add1_l *= 0.5;

  /* Product: '<S3>/Product7' incorporates:
   *  Constant: '<S3>/Constant4'
   */
  rtb_Product7_idx_0 = 0.0;
  rtb_Product7_idx_1 = 0.0;
  tmp = 0;
  for (i = 0; i < 8; i++) {
    rtb_rx_g = rtb_TmpSignalConversionAtProduc[i];
    rtb_Product7_idx_0 += rtCP_Constant4_Value_f[tmp] * rtb_rx_g;
    rtb_Product7_idx_1 += rtCP_Constant4_Value_f[tmp + 1] * rtb_rx_g;
    tmp += 2;
  }

  /* End of Product: '<S3>/Product7' */

  /* Product: '<S3>/Product6' incorporates:
   *  SignalConversion generated from: '<S3>/POSE exponential matrix for improved accuracy while rotating'
   *  Trigonometry: '<S4>/Trigonometric Function'
   *  Trigonometry: '<S4>/Trigonometric Function1'
   *  UnaryMinus: '<S3>/Unary Minus2'
   *  UnaryMinus: '<S4>/Unary Minus'
   */
  rtb_rx_g = (rtb_rx_n * rtb_Product7_idx_0) + ((-rtb_Add1_l) *
    rtb_Product7_idx_1);
  rtb_rx_n = (rtb_Add1_l * rtb_Product7_idx_0) + (rtb_rx_n * rtb_Product7_idx_1);
  Odometry_B.Product6_k[0] = rtb_Switch * rtb_rx_g;
  Odometry_B.Product6_k[1] = rtb_TmpSignalConversionAtProd_0 * rtb_rx_g;
  Odometry_B.Product6_k[0] += (-rtb_TmpSignalConversionAtProd_0) * rtb_rx_n;
  Odometry_B.Product6_k[1] += rtb_Switch * rtb_rx_n;

  /* Outport: '<Root>/Odom_Delta_X' incorporates:
   *  S-Function (sfix_udelay): '<S3>/Tapped Delay'
   *  Sum: '<S3>/Add'
   */
  Odometry_Y.Odom_Delta_X = (((Odometry_B.Product6_k[0] +
    Odometry_DW.TappedDelay_X[0]) + Odometry_DW.TappedDelay_X[1]) +
    Odometry_DW.TappedDelay_X[2]) + Odometry_DW.TappedDelay_X[3];

  /* Outport: '<Root>/Odom_Delta_Y' incorporates:
   *  S-Function (sfix_udelay): '<S3>/Tapped Delay1'
   *  Sum: '<S3>/Add1'
   */
  Odometry_Y.Odom_Delta_Y = (((Odometry_DW.TappedDelay1_X[0] +
    Odometry_B.Product6_k[1]) + Odometry_DW.TappedDelay1_X[1]) +
    Odometry_DW.TappedDelay1_X[2]) + Odometry_DW.TappedDelay1_X[3];

  /* Outport: '<Root>/Gyro_Angle_Field_rad' */
  Odometry_Y.Gyro_Angle_Field_rad = Odometry_B.Gyro_Angle_Field_rad;

  /* Sum: '<S7>/Add1' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/Constant4'
   *  Math: '<S7>/Math Function'
   *  Sum: '<S7>/Add2'
   */
  Odometry_B.Gyro_Angle_rad = rt_modd_snf(rtb_rx + 3.141592653589793,
    6.283185307179586) - 3.141592653589793;

  /* Outport: '<Root>/Gyro_Angle_rad' */
  Odometry_Y.Gyro_Angle_rad = Odometry_B.Gyro_Angle_rad;

  /* Outport: '<Root>/BR_Steer_Module_Angle' */
  Odometry_Y.BR_Steer_Module_Angle = Odometry_B.BR_Steer_Module_Angle;

  /* Outport: '<Root>/BL_Steer_Module_Angle' */
  Odometry_Y.BL_Steer_Module_Angle = Odometry_B.BL_Steer_Module_Angle;

  /* Outport: '<Root>/FR_Steer_Module_Angle' */
  Odometry_Y.FR_Steer_Module_Angle = Odometry_B.FR_Steer_Module_Angle;

  /* Outport: '<Root>/FL_Steer_Module_Angle' */
  Odometry_Y.FL_Steer_Module_Angle = Odometry_B.FL_Steer_Module_Angle;

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S24>/Constant'
   */
  rtb_FixPtRelationalOperator = (Odometry_X_Y_TEAR != 0.0);

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

  /* Gain: '<S23>/meters to feet' */
  Odometry_B.Odometry_X_global_est_ft = 3.28084 * Odometry_B.Odom_Position_X;

  /* Switch: '<S23>/Switch' incorporates:
   *  UnitDelay: '<S23>/Unit Delay'
   */
  if (rtb_FixPtRelationalOperator) {
    rtb_rx = Odometry_B.Odometry_X_global_est_ft;
  } else {
    rtb_rx = Odometry_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S23>/Switch' */

  /* Sum: '<S23>/Subtract' */
  Odometry_B.Odometry_X_global_TEAR_ft = Odometry_B.Odometry_X_global_est_ft -
    rtb_rx;

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

  /* Gain: '<S23>/meters to feet1' */
  Odometry_B.Odometry_Y_global_est_ft = 3.28084 * Odometry_B.Odom_Position_Y;

  /* Switch: '<S23>/Switch1' incorporates:
   *  UnitDelay: '<S23>/Unit Delay1'
   */
  if (rtb_FixPtRelationalOperator) {
    rtb_Switch = Odometry_B.Odometry_Y_global_est_ft;
  } else {
    rtb_Switch = Odometry_DW.UnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* Sum: '<S23>/Subtract1' */
  Odometry_B.Odometry_Y_global_TEAR_ft = Odometry_B.Odometry_Y_global_est_ft -
    rtb_Switch;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant2'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Odometry_B.loop_counter_odometry++;

  /* Update for UnitDelay: '<S15>/UD' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *
   * Block description for '<S15>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE = Odometry_U.FrontLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S16>/UD' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *
   * Block description for '<S16>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_i = Odometry_U.FrontRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S17>/UD' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *
   * Block description for '<S17>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_iy = Odometry_U.BackLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S18>/UD' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_f = Odometry_U.BackRight_Drive_Motor_Rev;

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  Odometry_DW.TappedDelay_X[0] = Odometry_DW.TappedDelay_X[1];

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay1' */
  Odometry_DW.TappedDelay1_X[0] = Odometry_DW.TappedDelay1_X[1];

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  Odometry_DW.TappedDelay_X[1] = Odometry_DW.TappedDelay_X[2];

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay1' */
  Odometry_DW.TappedDelay1_X[1] = Odometry_DW.TappedDelay1_X[2];

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  Odometry_DW.TappedDelay_X[2] = Odometry_DW.TappedDelay_X[3];

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay1' */
  Odometry_DW.TappedDelay1_X[2] = Odometry_DW.TappedDelay1_X[3];

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  Odometry_DW.TappedDelay_X[3] = Odometry_B.Product6_k[0];

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay1' */
  Odometry_DW.TappedDelay1_X[3] = Odometry_B.Product6_k[1];

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Constant: '<S2>/Constant3'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Odometry_DW.DelayInput1_DSTATE = Gyro_Calibration_Reset_Flag;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  Inport: '<Root>/GameState'
   */
  Odometry_DW.UnitDelay_DSTATE_dk = Odometry_U.GameState;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  Odometry_DW.UnitDelay1_DSTATE = Odometry_B.Product6[0];

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  Odometry_DW.UnitDelay2_DSTATE = Odometry_B.Product6[1];

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  Odometry_DW.UnitDelay1_DSTATE_f = rtb_Switch1;

  /* Update for UnitDelay: '<S25>/UD'
   *
   * Block description for '<S25>/UD':
   *
   *  Store in Global RAM
   */
  Odometry_DW.UD_DSTATE_m = Odometry_B.Gyro_Angle_Field_rad;

  /* Update for UnitDelay: '<S14>/UD'
   *
   * Block description for '<S14>/UD':
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
  } else if (Odometry_Reset_IC < 0.0) {
    Odometry_DW.Accumulator2_PrevResetState = -1;
    Odometry_DW.Accumulator_PrevResetState = -1;
  } else if (Odometry_Reset_IC == 0.0) {
    Odometry_DW.Accumulator2_PrevResetState = 0;
    Odometry_DW.Accumulator_PrevResetState = 0;
  } else {
    Odometry_DW.Accumulator2_PrevResetState = 2;
    Odometry_DW.Accumulator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Accumulator2' */

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  Odometry_DW.UnitDelay_DSTATE = rtb_rx;

  /* Update for DiscreteIntegrator: '<S3>/Accumulator' */
  Odometry_DW.Accumulator_DSTATE += Odometry_B.Product6_k[1];

  /* Update for UnitDelay: '<S23>/Unit Delay1' */
  Odometry_DW.UnitDelay1_DSTATE_d = rtb_Switch;
}

/* Model initialize function */
void Odometry_initialize(void)
{
  {
    real_T Constant;
    real_T Constant1;

    /* Start for Constant: '<S1>/Constant' */
    Constant = Odometry_IC_X;

    /* Start for Constant: '<S1>/Constant1' */
    Constant1 = Odometry_IC_Y;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
    Odometry_DW.UnitDelay1_DSTATE_f = Gyro_Calibration_Default;

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
