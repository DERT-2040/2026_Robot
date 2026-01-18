/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Odometry.h
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

#ifndef RTW_HEADER_Odometry_h_
#define RTW_HEADER_Odometry_h_
#ifndef Odometry_COMMON_INCLUDES_
#define Odometry_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Odometry_COMMON_INCLUDES_ */

#include "Odometry_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T FL_Steer_Module_Angle;        /* '<S18>/Add1' */
  real_T FR_Steer_Module_Angle;        /* '<S19>/Add1' */
  real_T BL_Steer_Module_Angle;        /* '<S20>/Add1' */
  real_T BR_Steer_Module_Angle;        /* '<S21>/Add1' */
  real_T Gyro_Angle_Calibrated_deg;    /* '<S2>/Subtract1' */
  real_T Gyro_Angle_rad;               /* '<S5>/Gain1' */
  real_T Gyro_Angle_Field_rad;         /* '<S2>/Add' */
  real_T Product6[2];                  /* '<S3>/Product6' */
  real_T Odom_Position_X;              /* '<S3>/Accumulator2' */
  real_T Odometry_X_global_est_ft;     /* '<S16>/meters to feet' */
  real_T Odometry_X_global_TEAR_ft;    /* '<S16>/Subtract' */
  real_T Odom_Position_Y;              /* '<S3>/Accumulator' */
  real_T Odometry_Y_global_est_ft;     /* '<S16>/meters to feet1' */
  real_T Odometry_Y_global_TEAR_ft;    /* '<S16>/Subtract1' */
  real_T loop_counter_odometry;        /* '<S1>/Sum' */
} B_Odometry_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S8>/UD' */
  real_T UD_DSTATE_i;                  /* '<S9>/UD' */
  real_T UD_DSTATE_iy;                 /* '<S10>/UD' */
  real_T UD_DSTATE_f;                  /* '<S11>/UD' */
  real_T DelayInput1_DSTATE;           /* '<S6>/Delay Input1' */
  real_T UnitDelay1_DSTATE;            /* '<S2>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S7>/UD' */
  real_T Accumulator2_DSTATE;          /* '<S3>/Accumulator2' */
  real_T UnitDelay_DSTATE;             /* '<S16>/Unit Delay' */
  real_T Accumulator_DSTATE;           /* '<S3>/Accumulator' */
  real_T UnitDelay1_DSTATE_d;          /* '<S16>/Unit Delay1' */
  int8_T Accumulator2_PrevResetState;  /* '<S3>/Accumulator2' */
  int8_T Accumulator_PrevResetState;   /* '<S3>/Accumulator' */
} DW_Odometry_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T IsBlueAlliance;               /* '<Root>/IsBlueAlliance' */
  real_T Gyro_Angle;                   /* '<Root>/Gyro_Angle' */
  real_T FrontLeft_Drive_Motor_Rev;    /* '<Root>/FrontLeft_Drive_Motor_Rev' */
  real_T FrontRight_Drive_Motor_Rev;   /* '<Root>/FrontRight_Drive_Motor_Rev' */
  real_T BackLeft_Drive_Motor_Rev;     /* '<Root>/BackLeft_Drive_Motor_Rev' */
  real_T BackRight_Drive_Motor_Rev;    /* '<Root>/BackRight_Drive_Motor_Rev' */
  real_T FrontLeft_Steer_Rev;          /* '<Root>/FrontLeft_Steer_Rev' */
  real_T FrontRight_Steer_Rev;         /* '<Root>/FrontRight_Steer_Rev' */
  real_T BackLeft_Steer_Rev;           /* '<Root>/BackLeft_Steer_Rev' */
  real_T BackRight_Steer_Rev;          /* '<Root>/BackRight_Steer_Rev' */
  real_T FrontLeft_Turn_Offset;        /* '<Root>/FrontLeft_Turn_Offset' */
  real_T FrontRight_Turn_Offset;       /* '<Root>/FrontRight_Turn_Offset' */
  real_T BackLeft_Turn_Offset;         /* '<Root>/BackLeft_Turn_Offset' */
  real_T BackRight_Turn_Offset;        /* '<Root>/BackRight_Turn_Offset' */
} ExtU_Odometry_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Gyro_Angle_Field_rad;         /* '<Root>/Gyro_Angle_Field_rad' */
  real_T Gyro_Angle_rad;               /* '<Root>/Gyro_Angle_rad' */
  real_T Auto_Start_Position;          /* '<Root>/Auto_Start_Position' */
  real_T FL_Steer_Module_Angle;        /* '<Root>/FL_Steer_Module_Angle' */
  real_T FR_Steer_Module_Angle;        /* '<Root>/FR_Steer_Module_Angle' */
  real_T BL_Steer_Module_Angle;        /* '<Root>/BL_Steer_Module_Angle' */
  real_T BR_Steer_Module_Angle;        /* '<Root>/BR_Steer_Module_Angle' */
  real_T Odom_Position_X;              /* '<Root>/Odom_Position_X' */
  real_T Odom_Position_Y;              /* '<Root>/Odom_Position_Y' */
  real_T Odom_Delta_X;                 /* '<Root>/Odom_Delta_X' */
  real_T Odom_Delta_Y;                 /* '<Root>/Odom_Delta_Y' */
} ExtY_Odometry_T;

/* Real-time Model Data Structure */
struct tag_RTM_Odometry_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Odometry_T Odometry_B;

/* Block states (default storage) */
extern DW_Odometry_T Odometry_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Odometry_T Odometry_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Odometry_T Odometry_Y;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T Auto_Starting_Position;  /* Variable: Auto_Starting_Position
                                        * Referenced by: '<S2>/Constant2'
                                        */
extern real_T Gyro_Calibration_Auto_Center;/* Variable: Gyro_Calibration_Auto_Center
                                            * Referenced by: '<S2>/Constant5'
                                            */
extern real_T Gyro_Calibration_Auto_Left;/* Variable: Gyro_Calibration_Auto_Left
                                          * Referenced by: '<S2>/Constant4'
                                          */
extern real_T Gyro_Calibration_Auto_Right;/* Variable: Gyro_Calibration_Auto_Right
                                           * Referenced by: '<S2>/Constant6'
                                           */
extern real_T Gyro_Calibration_Default;/* Variable: Gyro_Calibration_Default
                                        * Referenced by:
                                        *   '<S2>/Constant7'
                                        *   '<S2>/Unit Delay1'
                                        */
extern real_T Gyro_Calibration_Reset_Flag;/* Variable: Gyro_Calibration_Reset_Flag
                                           * Referenced by: '<S2>/Constant3'
                                           */
extern real_T Odometry_IC_X;           /* Variable: Odometry_IC_X
                                        * Referenced by: '<S1>/Constant'
                                        */
extern real_T Odometry_IC_Y;           /* Variable: Odometry_IC_Y
                                        * Referenced by: '<S1>/Constant1'
                                        */
extern real_T Odometry_Reset_IC;       /* Variable: Odometry_Reset_IC
                                        * Referenced by: '<S3>/Constant'
                                        */
extern real_T Odometry_X_Y_TEAR;       /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S16>/Constant'
                                        */

/* Model entry point functions */
extern void Odometry_initialize(void);
extern void Odometry_step(void);
extern void Odometry_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Odometry_T *const Odometry_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S3>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S3>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S3>/Signal Copy3' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Odometry'
 * '<S1>'   : 'Odometry/Odometry'
 * '<S2>'   : 'Odometry/Odometry/Gyro_Angles'
 * '<S3>'   : 'Odometry/Odometry/Odometry'
 * '<S4>'   : 'Odometry/Odometry/Steer_Module_Offset_Adjustments'
 * '<S5>'   : 'Odometry/Odometry/Gyro_Angles/Degrees to Radians'
 * '<S6>'   : 'Odometry/Odometry/Gyro_Angles/Detect Increase'
 * '<S7>'   : 'Odometry/Odometry/Odometry/Difference'
 * '<S8>'   : 'Odometry/Odometry/Odometry/Difference1'
 * '<S9>'   : 'Odometry/Odometry/Odometry/Difference3'
 * '<S10>'  : 'Odometry/Odometry/Odometry/Difference4'
 * '<S11>'  : 'Odometry/Odometry/Odometry/Difference5'
 * '<S12>'  : 'Odometry/Odometry/Odometry/Polar to Cartesian'
 * '<S13>'  : 'Odometry/Odometry/Odometry/Polar to Cartesian1'
 * '<S14>'  : 'Odometry/Odometry/Odometry/Polar to Cartesian2'
 * '<S15>'  : 'Odometry/Odometry/Odometry/Polar to Cartesian3'
 * '<S16>'  : 'Odometry/Odometry/Odometry/Tear for validation testing'
 * '<S17>'  : 'Odometry/Odometry/Odometry/Tear for validation testing/Compare To Zero'
 * '<S18>'  : 'Odometry/Odometry/Steer_Module_Offset_Adjustments/Angle Modulus'
 * '<S19>'  : 'Odometry/Odometry/Steer_Module_Offset_Adjustments/Angle Modulus1'
 * '<S20>'  : 'Odometry/Odometry/Steer_Module_Offset_Adjustments/Angle Modulus2'
 * '<S21>'  : 'Odometry/Odometry/Steer_Module_Offset_Adjustments/Angle Modulus3'
 */
#endif                                 /* RTW_HEADER_Odometry_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
