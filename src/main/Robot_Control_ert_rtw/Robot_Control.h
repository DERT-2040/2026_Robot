/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.452
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 24 22:02:20 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Robot_Control_h_
#define RTW_HEADER_Robot_Control_h_
#ifndef Robot_Control_COMMON_INCLUDES_
#define Robot_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Robot_Control_COMMON_INCLUDES_ */

#include "Robot_Control_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Drive_Joystick_X;             /* '<S5>/Signal Copy1' */
  real_T Drive_Joystick_Y;             /* '<S5>/Signal Copy2' */
  real_T Drive_Joystick_Z;             /* '<S5>/Signal Copy3' */
  real_T Steer_Joystick_Y;             /* '<S5>/Signal Copy5' */
  real_T Steer_Joystick_Z;             /* '<S5>/Signal Copy6' */
  real_T Vision_c1_AprilTag_Corr_X_inch;/* '<S16>/Add' */
  real_T Vision_c1_AprilTag_Corr_Y_inch;/* '<S16>/Add1' */
  real_T Vision_c1_AprilTag_Corr_Yaw_deg;/* '<S16>/Add2' */
  real_T Vision_c1_Object_Corr_X_inch; /* '<S16>/Add3' */
  real_T Vision_c1_Object_Corr_Y_inch; /* '<S16>/Add4' */
  real_T Vision_c1_Object_Corr_Yaw_deg;/* '<S16>/Add5' */
  real_T KF_Position_X;                /* '<S7>/Switch' */
  real_T KF_Position_Y;                /* '<S7>/Switch1' */
  real_T Spline_Num_Poses;             /* '<S8>/Merge9' */
  real_T Steering_Abs_Cmd;             /* '<S8>/Merge1' */
  real_T Steering_Rel_Cmd;             /* '<S8>/Merge2' */
  real_T Translation_Speed;            /* '<S8>/Merge4' */
  real_T Translation_Angle;            /* '<S8>/Merge3' */
  real_T Translation_Speed_SPF;        /* '<S12>/Merge2' */
  real_T Translation_Speed_RL;         /* '<S293>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S12>/Merge3' */
  real_T Gyro_Angle_SPF;               /* '<S12>/Merge8' */
  real_T Translation_Steering_Cmd;     /* '<S287>/Switch' */
  real_T RB_Meas_Shooter_Speed_Max;    /* '<S88>/Max' */
  real_T RB_Desired_Shoot_Gyro_Ang;    /* '<S86>/Merge' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S12>/Merge' */
  real_T Steering_Localized_PID;       /* '<S314>/Saturation2' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S12>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S286>/Switch' */
  real_T BR_Desired_Wheel_Speed_in;    /* '<S340>/Switch1' */
  real_T FL_Desired_Wheel_Speed_in;    /* '<S325>/Switch1' */
  real_T FR_Desired_Wheel_Speed_in;    /* '<S330>/Switch1' */
  real_T BL_Desired_Wheel_Speed_in;    /* '<S335>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S320>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S340>/Switch' */
  real_T FL_Desired_Module_Angle;      /* '<S325>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S320>/Product' */
  real_T FR_Desired_Module_Angle;      /* '<S330>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S320>/Product1' */
  real_T BL_Desired_Module_Angle;      /* '<S335>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S320>/Product2' */
  real_T RB_Transfer_Motor_PID_DC;     /* '<S92>/Switch2' */
  real_T RB_Feeder_Motor_PID_DC;       /* '<S11>/Product' */
  real_T RB_Desired_Hood_Pos_Shoot;    /* '<S86>/Merge2' */
  real_T Estimated_Hood_Pos;           /* '<S82>/Sum' */
  real_T RB_Desired_Shooter_Speed;     /* '<S86>/Merge1' */
  real_T RB_Shooter_Motor_PID_DC;      /* '<S90>/Switch2' */
  real_T RB_Allow_Shoot_Gyro_Error;    /* '<S86>/Merge3' */
  real_T loop_counter_robot_control;   /* '<S1>/Sum' */
  real_T Steer_Joystick_X;             /* '<S5>/Signal Copy4' */
  real_T Feeder_Motor_Speed_tp;        /* '<Root>/Signal Copy' */
  real_T Relative_Error_Angle;         /* '<S346>/Switch4' */
  real_T Steering_Abs_Gyro_Latch;      /* '<S348>/Switch8' */
  real_T Steering_Abs_Gyro;            /* '<S348>/Switch2' */
  real_T Steering_Abs_Angle;           /* '<S348>/Switch3' */
  real_T Relative_Error_Y;             /* '<S346>/Switch2' */
  real_T Relative_Error_X;             /* '<S346>/Unary Minus1' */
  real_T Spline_Follow_Index;          /* '<S140>/Merge4' */
  real_T Spline_Target_Y;              /* '<S137>/Selector6' */
  real_T Spline_Target_X;              /* '<S137>/Selector2' */
  real_T RB_Desired_Feeder_Speed;    /* '<S11>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Desired_Transfer_Speed;  /* '<S11>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Shoot_Target_X;            /* '<S101>/Switch' */
  real_T RB_Shoot_Target_Y;            /* '<S101>/Switch1' */
  real_T RB_Desired_Hood_Pos;          /* '<S99>/Lookup Table Dynamic' */
  real_T RB_Desired_Shoot_Motor_Spd;   /* '<S100>/Lookup Table Dynamic' */
  real_T RB_Allow_Shoot_Gyro_Err;      /* '<S98>/Lookup Table Dynamic' */
  real_T RB_Desired_Gyro_Angle_raw;    /* '<S96>/Tanh' */
  real_T RB_Desired_Shot_Distance;     /* '<S104>/Hypot' */
  real_T RB_Desired_Target_X;          /* '<S107>/Add' */
  real_T RB_Desired_Target_Y;          /* '<S107>/Add1' */
  real_T Product2[2];                  /* '<S80>/Product2' */
  real_T Product3[2];                  /* '<S78>/Product3' */
  uint8_T Active_GameState;            /* '<S10>/Chart' */
  boolean_T Button_Enable_Wheels;      /* '<S24>/FixPt Relational Operator' */
  boolean_T Button_Reset_Wheel_Offsets;/* '<S25>/FixPt Relational Operator' */
  boolean_T Button_Disable_Wheels;     /* '<S26>/FixPt Relational Operator' */
  boolean_T Drive_Joystick_Z_Mode;     /* '<S21>/Compare' */
  boolean_T Is_Boosting;               /* '<S23>/Compare' */
  boolean_T Face_Toward_Driver;        /* '<S19>/Compare' */
  boolean_T Face_Right_Driver;         /* '<S20>/Compare' */
  boolean_T Face_Left_Driver;          /* '<S22>/Compare' */
  boolean_T Face_Away_Driver;          /* '<S18>/Compare' */
  boolean_T Spline_Enable;             /* '<S8>/Merge7' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S12>/Merge4' */
  boolean_T RB_IsBlueActive;           /* '<S87>/Merge' */
  boolean_T RB_IsRedActive;            /* '<S87>/Merge1' */
  boolean_T RB_Logic_Score_In_Zone;    /* '<S118>/Merge' */
  boolean_T RB_Logic_Velocity;         /* '<S89>/GreaterThan' */
  boolean_T RB_Logic_Gyro_Angle;       /* '<S89>/Relational Operator' */
  boolean_T RB_Logic_Shooter_Speed;    /* '<S89>/Relational Operator1' */
  boolean_T RB_Logic_Hood_Pos;         /* '<S89>/Relational Operator4' */
  boolean_T RB_Ready_to_Score;         /* '<S89>/AND2' */
  boolean_T Is_Outside_Alliance_Zone;  /* '<S119>/Merge' */
  boolean_T RB_Logic_Outside_Zone;     /* '<S89>/Signal Copy' */
  boolean_T RB_Ready_to_Pass;          /* '<S89>/AND3' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S12>/Merge5' */
  boolean_T Swerve_Drive_Integral_Enable;/* '<S8>/Merge23' */
  boolean_T Robot_Reached_Destination; /* '<S12>/Merge7' */
  boolean_T Test_Mode;                 /* '<S8>/Merge10' */
  boolean_T Relative_Enable;           /* '<S346>/Logical Operator1' */
  boolean_T Steering_Abs_Angle_Active; /* '<S348>/AND6' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S140>/Merge1' */
  boolean_T RB_Shooter_Active;       /* '<S11>/Shooter_Transfer_Feeder Chart' */
} B_Robot_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S24>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S25>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S26>/Delay Input1' */
  real_T TappedDelay_X[2];             /* '<S7>/Tapped Delay' */
  real_T TappedDelay1_X[2];            /* '<S7>/Tapped Delay1' */
  real_T MemoryX_DSTATE[2];            /* '<S27>/MemoryX' */
  real_T UnitDelay_1_DSTATE;           /* '<S11>/Unit Delay' */
  real_T UnitDelay_4_DSTATE;           /* '<S11>/Unit Delay' */
  real_T UnitDelay_2_DSTATE;           /* '<S11>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S11>/Unit Delay' */
  real_T UnitDelay_DSTATE_c;           /* '<S86>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S317>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S316>/UD' */
  real_T UnitDelay_DSTATE_m;           /* '<S314>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S297>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_e;     /* '<S312>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S296>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_p;     /* '<S305>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S271>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S270>/UD' */
  real_T UnitDelay_DSTATE_lw;          /* '<S264>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S208>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S207>/UD' */
  real_T UnitDelay_DSTATE_j;           /* '<S201>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S219>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S218>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S204>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S229>/Unit Delay1' */
  real_T UD_DSTATE_m;                  /* '<S228>/UD' */
  real_T UnitDelay_DSTATE_h;           /* '<S222>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S240>/Unit Delay1' */
  real_T UD_DSTATE_i;                  /* '<S239>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S225>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n4;         /* '<S250>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S249>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S243>/Unit Delay' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S261>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S260>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S246>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S282>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S281>/UD' */
  real_T UnitDelay_DSTATE_lm;          /* '<S267>/Unit Delay' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S132>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S131>/UD' */
  real_T UnitDelay_DSTATE_kz;          /* '<S130>/Unit Delay' */
  real_T UnitDelay1_DSTATE_d;          /* '<S127>/Unit Delay1' */
  real_T UD_DSTATE_ml;                 /* '<S126>/UD' */
  real_T UnitDelay_DSTATE_di;          /* '<S125>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S348>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_j2;         /* '<S348>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S362>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S362>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S366>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_gh;          /* '<S136>/Unit Delay' */
  void *MatrixConcatenate_PWORK;       /* '<S157>/Matrix Concatenate' */
  int32_T Selector5_DIMS1[2];          /* '<S157>/Selector5' */
  int32_T MatrixConcatenate_DIMS1[2];  /* '<S157>/Matrix Concatenate' */
  int32_T Selector4_DIMS1[2];          /* '<S157>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S295>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_p;    /* '<S312>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S305>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_f;    /* '<S84>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S366>/FixPt Unit Delay2' */
  boolean_T UnitDelay_DSTATE_ki;       /* '<S92>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_db;       /* '<S90>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ir;       /* '<S15>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S356>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S355>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S351>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S352>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S353>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g2;     /* '<S354>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE;         /* '<S348>/Unit Delay2' */
  boolean_T UnitDelay4_DSTATE;         /* '<S348>/Unit Delay4' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S12>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S140>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S143>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S145>/If' */
  uint8_T is_active_c2_Robot_Control;/* '<S11>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_c2_Robot_Control;       /* '<S11>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_Shooting;               /* '<S11>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_active_c9_Robot_Control;  /* '<S10>/Chart' */
  uint8_T is_c9_Robot_Control;         /* '<S10>/Chart' */
  boolean_T icLoad;                    /* '<S27>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S54>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S47>/MeasurementUpdate' */
} DW_Robot_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S212>/Cos5' */
  const real_T Sin5;                   /* '<S212>/Sin5' */
  const real_T Cos5_g;                 /* '<S233>/Cos5' */
  const real_T Sin5_m;                 /* '<S233>/Sin5' */
  const real_T Cos5_i;                 /* '<S254>/Cos5' */
  const real_T Sin5_e;                 /* '<S254>/Sin5' */
  const real_T Cos5_b;                 /* '<S275>/Cos5' */
  const real_T Sin5_c;                 /* '<S275>/Sin5' */
  const real_T Atan2;                  /* '<S285>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S285>/Add' */
  const real_T Atan1;                  /* '<S285>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S285>/Add1' */
  const real_T Atan3;                  /* '<S285>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S285>/Add2' */
  const real_T Atan4;                  /* '<S285>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S285>/Add3' */
} ConstB_Robot_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T GameState;                    /* '<Root>/GameState' */
  real_T IsBlueAlliance;               /* '<Root>/IsBlueAlliance' */
  real_T MatchTime;                    /* '<Root>/MatchTime' */
  real_T Joystick_Left_X;              /* '<Root>/Joystick_Left_X' */
  real_T Joystick_Left_Y;              /* '<Root>/Joystick_Left_Y' */
  real_T Joystick_Left_Z;              /* '<Root>/Joystick_Left_Z' */
  real_T Joystick_Right_X;             /* '<Root>/Joystick_Right_X' */
  real_T Joystick_Right_Y;             /* '<Root>/Joystick_Right_Y' */
  real_T Joystick_Right_Z;             /* '<Root>/Joystick_Right_Z' */
  real_T Joystick_Left_B1;             /* '<Root>/Joystick_Left_B1' */
  real_T Joystick_Left_B2;             /* '<Root>/Joystick_Left_B2' */
  real_T Joystick_Left_B3;             /* '<Root>/Joystick_Left_B3' */
  real_T Joystick_Left_B4;             /* '<Root>/Joystick_Left_B4' */
  real_T Joystick_Left_B5;             /* '<Root>/Joystick_Left_B5' */
  real_T Joystick_Left_B6;             /* '<Root>/Joystick_Left_B6' */
  real_T Joystick_Left_B7;             /* '<Root>/Joystick_Left_B7' */
  real_T Joystick_Left_B8;             /* '<Root>/Joystick_Left_B8' */
  real_T Joystick_Left_B9;             /* '<Root>/Joystick_Left_B9' */
  real_T Joystick_Left_B10;            /* '<Root>/Joystick_Left_B10' */
  real_T Joystick_Left_B11;            /* '<Root>/Joystick_Left_B11' */
  real_T Joystick_Left_B12;            /* '<Root>/Joystick_Left_B12' */
  real_T Joystick_Left_B13;            /* '<Root>/Joystick_Left_B13' */
  real_T Joystick_Left_B14;            /* '<Root>/Joystick_Left_B14' */
  real_T Joystick_Left_B15;            /* '<Root>/Joystick_Left_B15' */
  real_T Joystick_Left_B16;            /* '<Root>/Joystick_Left_B16' */
  real_T Joystick_Left_POV;            /* '<Root>/Joystick_Left_POV' */
  real_T Joystick_Right_B1;            /* '<Root>/Joystick_Right_B1' */
  real_T Joystick_Right_B2;            /* '<Root>/Joystick_Right_B2' */
  real_T Joystick_Right_B3;            /* '<Root>/Joystick_Right_B3' */
  real_T Joystick_Right_B4;            /* '<Root>/Joystick_Right_B4' */
  real_T Joystick_Right_B5;            /* '<Root>/Joystick_Right_B5' */
  real_T Joystick_Right_B6;            /* '<Root>/Joystick_Right_B6' */
  real_T Joystick_Right_B7;            /* '<Root>/Joystick_Right_B7' */
  real_T Joystick_Right_B8;            /* '<Root>/Joystick_Right_B8' */
  real_T Joystick_Right_B9;            /* '<Root>/Joystick_Right_B9' */
  real_T Joystick_Right_B10;           /* '<Root>/Joystick_Right_B10' */
  real_T Joystick_Right_B11;           /* '<Root>/Joystick_Right_B11' */
  real_T Joystick_Right_B12;           /* '<Root>/Joystick_Right_B12' */
  real_T Joystick_Right_B13;           /* '<Root>/Joystick_Right_B13' */
  real_T Joystick_Right_B14;           /* '<Root>/Joystick_Right_B14' */
  real_T Joystick_Right_B15;           /* '<Root>/Joystick_Right_B15' */
  real_T Joystick_Right_B16;           /* '<Root>/Joystick_Right_B16' */
  real_T Joystick_Right_POV;           /* '<Root>/Joystick_Right_POV' */
  real_T Gamepad_Stick_Left_X;         /* '<Root>/Gamepad_Stick_Left_X' */
  real_T Gamepad_Stick_Left_Y;         /* '<Root>/Gamepad_Stick_Left_Y' */
  real_T Gamepad_Stick_Right_X;        /* '<Root>/Gamepad_Stick_Right_X' */
  real_T Gamepad_Stick_Right_Y;        /* '<Root>/Gamepad_Stick_Right_Y' */
  real_T Gamepad_B1_A;                 /* '<Root>/Gamepad_B1_A' */
  real_T Gamepad_B2_B;                 /* '<Root>/Gamepad_B2_B' */
  real_T Gamepad_B3_X;                 /* '<Root>/Gamepad_B3_X' */
  real_T Gamepad_B4_Y;                 /* '<Root>/Gamepad_B4_Y' */
  uint8_T Gamepad_LB;                  /* '<Root>/Gamepad_LB' */
  real_T Gamepad_LT;                   /* '<Root>/Gamepad_LT' */
  uint8_T Gamepad_RB;                  /* '<Root>/Gamepad_RB' */
  real_T Gamepad_RT;                   /* '<Root>/Gamepad_RT' */
  real_T Gamepad_Back;                 /* '<Root>/Gamepad_Back' */
  real_T Gamepad_Start;                /* '<Root>/Gamepad_Start' */
  real_T Gamepad_POV;                  /* '<Root>/Gamepad_POV' */
  real_T FrontLeft_Drive_Motor_Speed; /* '<Root>/FrontLeft_Drive_Motor_Speed' */
  real_T FrontRight_Drive_Motor_Speed;
                                     /* '<Root>/FrontRight_Drive_Motor_Speed' */
  real_T BackLeft_Drive_Motor_Speed;   /* '<Root>/BackLeft_Drive_Motor_Speed' */
  real_T BackRight_Drive_Motor_Speed; /* '<Root>/BackRight_Drive_Motor_Speed' */
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
  real_T Robot_Velocity_X;             /* '<Root>/Robot_Velocity_X' */
  real_T Robot_Velocity_Y;             /* '<Root>/Robot_Velocity_Y' */
  real_T Vision_Current_Pipeline;      /* '<Root>/Vision_Current_Pipeline' */
  real_T Vision_RobotPoseFieldSpace_X;
                                     /* '<Root>/Vision_RobotPoseFieldSpace_X' */
  real_T Vision_RobotPoseFieldSpace_Y;
                                     /* '<Root>/Vision_RobotPoseFieldSpace_Y' */
  real_T Vision_Num_Tags_Detected;     /* '<Root>/Vision_Num_Tags_Detected' */
  boolean_T Vision_c1_AprilTag_Valid;  /* '<Root>/Vision_c1_AprilTag_Valid' */
  real_T Vision_c1_AprilTag_X_m;       /* '<Root>/Vision_c1_AprilTag_X_m' */
  real_T Vision_c1_AprilTag_Y_m;       /* '<Root>/Vision_c1_AprilTag_Y_m' */
  real_T Vision_c1_AprilTag_Yaw_deg;   /* '<Root>/Vision_c1_AprilTag_Yaw_deg' */
  boolean_T Vision_c1_Object_Valid;    /* '<Root>/Vision_c1_Object_Valid' */
  real_T Vision_c1_Object_Area_pct;    /* '<Root>/Vision_c1_Object_Area_pct' */
  real_T Vision_c1_Object_Hor_deg;     /* '<Root>/Vision_c1_Object_Hor_deg' */
  real_T Vision_c1_Object_Ver_deg;     /* '<Root>/Vision_c1_Object_Ver_deg' */
  real_T Measured_Transfer_Speed;      /* '<Root>/Measured_Transfer_Speed' */
  real_T Measured_Shooter_Speed_Left; /* '<Root>/Measured_Shooter_Speed_Left' */
  real_T Measured_Shooter_Speed_Center;
                                    /* '<Root>/Measured_Shooter_Speed_Center' */
  real_T Measured_Shooter_Speed_Right;
                                     /* '<Root>/Measured_Shooter_Speed_Right' */
  boolean_T IsBlueInactiveFirst;       /* '<Root>/IsBlueInactiveFirst' */
  real_T Measured_Feeder_Speed;        /* '<Root>/Measured_Feeder_Speed' */
} ExtU_Robot_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T FrontLeft_Steer_DutyCycle;    /* '<Root>/FrontLeft_Steer_DutyCycle' */
  real_T FrontLeft_Drive_DutyCycle;    /* '<Root>/FrontLeft_Drive_DutyCycle' */
  real_T FrontRight_Steer_DutyCycle;   /* '<Root>/FrontRight_Steer_DutyCycle' */
  real_T FrontRight_Drive_DutyCycle;   /* '<Root>/FrontRight_Drive_DutyCycle' */
  real_T BackLeft_Steer_DutyCycle;     /* '<Root>/BackLeft_Steer_DutyCycle' */
  real_T BackLeft_Drive_DutyCycle;     /* '<Root>/BackLeft_Drive_DutyCycle' */
  real_T BackRight_Steer_DutyCycle;    /* '<Root>/BackRight_Steer_DutyCycle' */
  real_T BackRight_Drive_DutyCycle;    /* '<Root>/BackRight_Drive_DutyCycle' */
  boolean_T Enable_Wheels;             /* '<Root>/Enable_Wheels' */
  boolean_T Reset_Wheel_Offsets;       /* '<Root>/Reset_Wheel_Offsets' */
  boolean_T Disable_Wheels;            /* '<Root>/Disable_Wheels' */
  boolean_T Swerve_Motors_Disabled;    /* '<Root>/Swerve_Motors_Disabled' */
  uint8_T Vision_Desired_Pipeline;     /* '<Root>/Vision_Desired_Pipeline' */
  real_T Transfer_Motor_DC;            /* '<Root>/Transfer_Motor_DC' */
  real_T Feeder_Motor_DC;              /* '<Root>/Feeder_Motor_DC' */
  real_T Shooter_Motor_DC_Left;        /* '<Root>/Shooter_Motor_DC_Left' */
  real_T Shooter_Motor_DC_Center;      /* '<Root>/Shooter_Motor_DC_Center' */
  real_T Shooter_Motor_DC_Right;       /* '<Root>/Shooter_Motor_DC_Right' */
  real_T Desired_Hood_Pos;             /* '<Root>/Desired_Hood_Pos' */
  boolean_T Desired_Hood_Enable;       /* '<Root>/Desired_Hood_Enable' */
} ExtY_Robot_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_Robot_Control_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Robot_Control_T Robot_Control_B;

/* Block states (default storage) */
extern DW_Robot_Control_T Robot_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Robot_Control_T Robot_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Robot_Control_T Robot_Control_Y;
extern const ConstB_Robot_Control_T Robot_Control_ConstB;/* constant block i/o */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T Boost_Trigger_Decreasing_Limit;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S363>/Constant1'
                                      */
extern real_T Boost_Trigger_High_Speed;/* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S359>/Constant'
                                        *   '<S359>/Saturation'
                                        */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S363>/Constant3'
                                      */
extern real_T Boost_Trigger_Low_Speed; /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S359>/Constant1'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S201>/Constant3'
                                        *   '<S222>/Constant3'
                                        *   '<S243>/Constant3'
                                        *   '<S264>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S201>/Constant2'
                                   *   '<S222>/Constant2'
                                   *   '<S243>/Constant2'
                                   *   '<S264>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S201>/Saturation'
                                        *   '<S222>/Saturation'
                                        *   '<S243>/Saturation'
                                        *   '<S264>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S201>/Saturation'
                                        *   '<S222>/Saturation'
                                        *   '<S243>/Saturation'
                                        *   '<S264>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S201>/Gain'
                                        *   '<S222>/Gain'
                                        *   '<S243>/Gain'
                                        *   '<S264>/Gain'
                                        */
extern real_T Drive_Motor_Control_I;   /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S201>/Gain2'
                                        *   '<S222>/Gain2'
                                        *   '<S243>/Gain2'
                                        *   '<S264>/Gain2'
                                        */
extern real_T Drive_Motor_Control_I_LL;/* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S201>/Saturation1'
                                        *   '<S222>/Saturation1'
                                        *   '<S243>/Saturation1'
                                        *   '<S264>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_I_UL;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S201>/Saturation1'
                                        *   '<S222>/Saturation1'
                                        *   '<S243>/Saturation1'
                                        *   '<S264>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S201>/Gain1'
                                        *   '<S222>/Gain1'
                                        *   '<S243>/Gain1'
                                        *   '<S264>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S206>/Constant'
                            *   '<S227>/Constant'
                            *   '<S248>/Constant'
                            *   '<S269>/Constant'
                            */
extern real_T Field_BlueAllianceZoneX; /* Variable: Field_BlueAllianceZoneX
                                        * Referenced by:
                                        *   '<S120>/BlueAllianceZoneX'
                                        *   '<S122>/BlueAllianceZoneX'
                                        */
extern real_T Field_Blue_Hub_X;        /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S101>/Constant'
                                        */
extern real_T Field_Blue_Hub_Y;        /* Variable: Field_Blue_Hub_Y
                                        * Referenced by: '<S101>/Constant1'
                                        */
extern real_T Field_RedAllianceZoneX;  /* Variable: Field_RedAllianceZoneX
                                        * Referenced by:
                                        *   '<S121>/RedAllianceZoneX'
                                        *   '<S123>/RedAllianceZoneX'
                                        */
extern real_T Field_Red_Hub_X;         /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S101>/Constant2'
                                        */
extern real_T Field_Red_Hub_Y;         /* Variable: Field_Red_Hub_Y
                                        * Referenced by: '<S101>/Constant3'
                                        */
extern real_T Field_Translation_Control_Gain;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S349>/Gain2'
                                      */
extern real_T Field_Translation_Speed_Max;/* Variable: Field_Translation_Speed_Max
                                           * Referenced by: '<S349>/Constant5'
                                           */
extern real_T KF_Enable;               /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S7>/Constant1'
                                        *   '<S7>/Constant2'
                                        */
extern real_T Rebuilt_Des_Gyro_Shoot_Offset;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S96>/Constant'
                                       */
extern real_T Rebuilt_Feeder_Motor_Gain_FF;/* Variable: Rebuilt_Feeder_Motor_Gain_FF
                                            * Referenced by: '<S11>/Constant'
                                            */
extern real_T Rebuilt_Hood_Servo_Pos_Max;/* Variable: Rebuilt_Hood_Servo_Pos_Max
                                          * Referenced by: '<S9>/Saturation'
                                          */
extern real_T Rebuilt_Hood_Servo_Pos_Min;/* Variable: Rebuilt_Hood_Servo_Pos_Min
                                          * Referenced by: '<S9>/Saturation'
                                          */
extern real_T Rebuilt_Hood_Servo_Rate_Limit_Dec;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S81>/Constant1'
                                   */
extern real_T Rebuilt_Hood_Servo_Rate_Limit_Inc;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S81>/Constant3'
                                   */
extern real_T Rebuilt_Shoot_Dist_0;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S102>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Dist_1;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S102>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Dist_2;    /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S102>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Dist_3;    /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S102>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Dist_4;    /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S102>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Dist_5;    /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S102>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Dist_6;    /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S102>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Dist_7;    /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S102>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_0;/* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S98>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_1;/* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S98>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_2;/* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S98>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_3;/* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S98>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_4;/* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S98>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_5;/* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S98>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_6;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S98>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_7;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S98>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_0;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S99>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_1;/* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S99>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_2;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S99>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_3;/* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S99>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_4;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S99>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_5;/* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S99>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_6;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S99>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_7;/* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S99>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_Max_Error;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S89>/Constant1'
                                    */
extern real_T Rebuilt_Shoot_Motor_Max_Error;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S89>/Constant2'
                                       */
extern real_T Rebuilt_Shoot_Robot_Velocity_Max;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S89>/Constant'
                                    */
extern real_T Rebuilt_Shoot_Shooter_Spd_0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                           * Referenced by: '<S100>/Constant5'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_1;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                           * Referenced by: '<S100>/Constant6'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_2;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                           * Referenced by: '<S100>/Constant7'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_3;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                           * Referenced by: '<S100>/Constant8'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_4;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                           * Referenced by: '<S100>/Constant9'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_5;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                           * Referenced by: '<S100>/Constant10'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_6;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                           * Referenced by: '<S100>/Constant2'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_7;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                           * Referenced by: '<S100>/Constant1'
                                           */
extern real_T Rebuilt_Shoot_TOF_0;     /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S105>/Constant'
                                        */
extern real_T Rebuilt_Shoot_TOF_1;     /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S105>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_TOF_2;     /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S105>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_TOF_3;     /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S105>/Constant3'
                                        */
extern real_T Rebuilt_Shoot_TOF_4;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S105>/Constant4'
                                        */
extern real_T Rebuilt_Shoot_TOF_5;     /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S105>/Constant11'
                                        */
extern real_T Rebuilt_Shoot_TOF_6;     /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S105>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_TOF_7;     /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S105>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Target_Error_Thresh;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S109>/Constant'
                                   */
extern real_T Rebuilt_Shooter_Error_Integral_Enable;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S90>/Constant1'
                               */
extern real_T Rebuilt_Shooter_Motor_Gain_FF;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S125>/Gain'
                                       */
extern real_T Rebuilt_Shooter_Motor_Gain_I;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                            * Referenced by: '<S125>/Gain2'
                                            */
extern real_T Rebuilt_Shooter_Motor_Gain_P;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                            * Referenced by: '<S125>/Gain1'
                                            */
extern real_T Rebuilt_Target_Feeder_Speed;/* Variable: Rebuilt_Target_Feeder_Speed
                                           * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                           */
extern real_T Rebuilt_Target_Transfer_Speed;
                                      /* Variable: Rebuilt_Target_Transfer_Speed
                                       * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                       */
extern real_T Rebuilt_Transfer_Error_Integral_Enable;
                             /* Variable: Rebuilt_Transfer_Error_Integral_Enable
                              * Referenced by: '<S92>/Constant1'
                              */
extern real_T Rebuilt_Transfer_Minimum_Factor;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S11>/Shooter_Transfer_Feeder Chart'
                                     */
extern real_T Rebuilt_Transfer_Motor_Gain_FF;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S130>/Gain'
                                      */
extern real_T Rebuilt_Transfer_Motor_Gain_I;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S130>/Gain2'
                                       */
extern real_T Rebuilt_Transfer_Motor_Gain_P;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S130>/Gain1'
                                       */
extern real_T Relative_Steering_Error_Angle_Gain;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S348>/Constant4'
                                  */
extern real_T Relative_Steering_Error_Angle_Gain_Object_Factor;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S346>/Gain'
                    */
extern real_T Relative_Steering_Speed_Max;/* Variable: Relative_Steering_Speed_Max
                                           * Referenced by: '<S348>/Constant10'
                                           */
extern real_T Relative_Translation_Control_Gain;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S349>/Gain1'
                                   */
extern real_T Relative_Translation_Speed_Max;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S349>/Constant8'
                                      */
extern real_T Spline_Last_Pose_Distance_to_Velocity_Gain;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S190>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S190>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S137>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S150>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S190>/Constant3'
                                     */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S297>/Constant5'
                    */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S297>/Constant6'
                    */
extern real_T Steering_Absolute_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S297>/Constant9'
                          */
extern real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S297>/Constant10'
                    */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S297>/Constant1'
                                */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S297>/Constant3'
                                */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S314>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S314>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S314>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S314>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S313>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S314>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S314>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S314>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S314>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S314>/Constant1'
                                   *   '<S314>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S314>/Constant'
                                   *   '<S314>/Saturation2'
                                   */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S204>/Constant3'
                                        *   '<S225>/Constant3'
                                        *   '<S246>/Constant3'
                                        *   '<S267>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S204>/Constant2'
                                *   '<S225>/Constant2'
                                *   '<S246>/Constant2'
                                *   '<S267>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S204>/Saturation'
                                           *   '<S225>/Saturation'
                                           *   '<S246>/Saturation'
                                           *   '<S267>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S204>/Saturation'
                                           *   '<S225>/Saturation'
                                           *   '<S246>/Saturation'
                                           *   '<S267>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S204>/Gain2'
                                        *   '<S225>/Gain2'
                                        *   '<S246>/Gain2'
                                        *   '<S267>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S204>/Saturation1'
                                           *   '<S225>/Saturation1'
                                           *   '<S246>/Saturation1'
                                           *   '<S267>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S204>/Saturation1'
                                           *   '<S225>/Saturation1'
                                           *   '<S246>/Saturation1'
                                           *   '<S267>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S204>/Gain1'
                                        *   '<S225>/Gain1'
                                        *   '<S246>/Gain1'
                                        *   '<S267>/Gain1'
                                        */
extern real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S296>/Constant5'
                    */
extern real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S296>/Constant6'
                    */
extern real_T Steering_Relative_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S296>/Constant9'
                          */
extern real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S296>/Constant10'
                    */
extern real_T Steering_Relative_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S296>/Constant1'
                                */
extern real_T Steering_Relative_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S296>/Constant3'
                                */
extern real_T Steering_Relative_Gain;  /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S348>/Constant'
                                        */
extern real_T Steering_Twist_Gain;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S348>/Constant1'
                                        */
extern real_T TEST_Desired_Hood_Enable_OV;/* Variable: TEST_Desired_Hood_Enable_OV
                                           * Referenced by: '<S9>/Constant7'
                                           */
extern real_T TEST_Desired_Hood_Pos_OV;/* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S9>/Constant6'
                                        */
extern real_T TEST_Feeder_Motor_DC_OV; /* Variable: TEST_Feeder_Motor_DC_OV
                                        * Referenced by: '<S9>/Constant2'
                                        */
extern real_T TEST_Output_Override_Flag;/* Variable: TEST_Output_Override_Flag
                                         * Referenced by: '<S9>/Constant'
                                         */
extern real_T TEST_Shooter_Motor_DC_Center_OV;
                                    /* Variable: TEST_Shooter_Motor_DC_Center_OV
                                     * Referenced by: '<S9>/Constant4'
                                     */
extern real_T TEST_Shooter_Motor_DC_Left_OV;
                                      /* Variable: TEST_Shooter_Motor_DC_Left_OV
                                       * Referenced by: '<S9>/Constant3'
                                       */
extern real_T TEST_Shooter_Motor_DC_Right_OV;
                                     /* Variable: TEST_Shooter_Motor_DC_Right_OV
                                      * Referenced by: '<S9>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Override_Flag;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S347>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Steering;/* Variable: TEST_Swerve_Mode_Steering
                                         * Referenced by: '<S347>/Constant8'
                                         */
extern real_T TEST_Swerve_Mode_Translation;/* Variable: TEST_Swerve_Mode_Translation
                                            * Referenced by: '<S347>/Constant7'
                                            */
extern real_T TEST_Transfer_Motor_DC_OV;/* Variable: TEST_Transfer_Motor_DC_OV
                                         * Referenced by: '<S9>/Constant1'
                                         */
extern real_T Translation_Speed_Approach_Zero_Error_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S284>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S284>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S284>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S284>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S284>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S284>/Constant3'
                                    */
extern real_T Translation_Twist_Gain;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S349>/Gain'
                                        */
extern real_T Twist_Deadzone_neg;      /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S348>/Dead Zone'
                                        *   '<S349>/Dead Zone'
                                        */
extern real_T Twist_Deadzone_pos;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S348>/Dead Zone'
                                        *   '<S349>/Dead Zone'
                                        */
extern real_T Vision_Object_Angle_Offset;/* Variable: Vision_Object_Angle_Offset
                                          * Referenced by: '<S16>/Constant6'
                                          */
extern real_T Vision_Object_Target_Angle;/* Variable: Vision_Object_Target_Angle
                                          * Referenced by: '<S346>/Constant7'
                                          */
extern real_T Vision_Object_Target_X;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S346>/Constant1'
                                        */
extern real_T Vision_Object_Target_Y;  /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S346>/Constant4'
                                        */
extern real_T Vision_Object_X_Offset;  /* Variable: Vision_Object_X_Offset
                                        * Referenced by: '<S16>/Constant4'
                                        */
extern real_T Vision_Object_Y_Offset;  /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S16>/Constant8'
                                        */
extern real_T Vision_Tag_Angle_Offset; /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S16>/Constant5'
                                        */
extern real_T Vision_Tag_Target_Angle; /* Variable: Vision_Tag_Target_Angle
                                        * Referenced by: '<S346>/Constant8'
                                        */
extern real_T Vision_Tag_Target_X;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S346>/Constant2'
                                        */
extern real_T Vision_Tag_Target_Y;     /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S346>/Constant5'
                                        */
extern real_T Vision_Tag_X_Offset;     /* Variable: Vision_Tag_X_Offset
                                        * Referenced by: '<S16>/Constant3'
                                        */
extern real_T Vision_Tag_Y_Offset;     /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S16>/Constant7'
                                        */
extern uint8_T TEST_Pipeline;          /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S15>/Constant22'
                                        *   '<S346>/Constant11'
                                        */

/* Model entry point functions */
extern void Robot_Control_initialize(void);
extern void Robot_Control_step(void);
extern void Robot_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Robot_Control_T *const Robot_Control_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Unit Delay' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Conversion' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Conversion' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/G' : Unused code path elimination
 * Block '<S27>/H' : Unused code path elimination
 * Block '<S27>/N' : Unused code path elimination
 * Block '<S27>/P0' : Unused code path elimination
 * Block '<S27>/Q' : Unused code path elimination
 * Block '<S27>/R' : Unused code path elimination
 * Block '<S59>/CheckSignalProperties' : Unused code path elimination
 * Block '<S68>/CheckSignalProperties' : Unused code path elimination
 * Block '<S69>/CheckSignalProperties' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Propagation' : Unused code path elimination
 * Block '<S84>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Unit Delay1' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Propagation' : Unused code path elimination
 * Block '<S125>/Scope' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Propagation' : Unused code path elimination
 * Block '<S130>/Scope' : Unused code path elimination
 * Block '<S149>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S159>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate' : Unused code path elimination
 * Block '<S209>/Data Type Propagation' : Unused code path elimination
 * Block '<S201>/Scope' : Unused code path elimination
 * Block '<S203>/Scope' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Propagation' : Unused code path elimination
 * Block '<S204>/Scope' : Unused code path elimination
 * Block '<S230>/Data Type Duplicate' : Unused code path elimination
 * Block '<S230>/Data Type Propagation' : Unused code path elimination
 * Block '<S222>/Scope' : Unused code path elimination
 * Block '<S224>/Scope' : Unused code path elimination
 * Block '<S241>/Data Type Duplicate' : Unused code path elimination
 * Block '<S241>/Data Type Propagation' : Unused code path elimination
 * Block '<S225>/Scope' : Unused code path elimination
 * Block '<S251>/Data Type Duplicate' : Unused code path elimination
 * Block '<S251>/Data Type Propagation' : Unused code path elimination
 * Block '<S243>/Scope' : Unused code path elimination
 * Block '<S245>/Scope' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate' : Unused code path elimination
 * Block '<S262>/Data Type Propagation' : Unused code path elimination
 * Block '<S246>/Scope' : Unused code path elimination
 * Block '<S272>/Data Type Duplicate' : Unused code path elimination
 * Block '<S272>/Data Type Propagation' : Unused code path elimination
 * Block '<S264>/Scope' : Unused code path elimination
 * Block '<S266>/Scope' : Unused code path elimination
 * Block '<S283>/Data Type Duplicate' : Unused code path elimination
 * Block '<S283>/Data Type Propagation' : Unused code path elimination
 * Block '<S267>/Scope' : Unused code path elimination
 * Block '<S294>/Data Type Duplicate' : Unused code path elimination
 * Block '<S294>/Data Type Propagation' : Unused code path elimination
 * Block '<S295>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S304>/Data Type Duplicate' : Unused code path elimination
 * Block '<S304>/Data Type Propagation' : Unused code path elimination
 * Block '<S305>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S311>/Data Type Duplicate' : Unused code path elimination
 * Block '<S311>/Data Type Propagation' : Unused code path elimination
 * Block '<S312>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S318>/Data Type Duplicate' : Unused code path elimination
 * Block '<S318>/Data Type Propagation' : Unused code path elimination
 * Block '<S314>/Scope' : Unused code path elimination
 * Block '<S358>/Data Type Duplicate' : Unused code path elimination
 * Block '<S358>/Data Type Propagation' : Unused code path elimination
 * Block '<S365>/Data Type Duplicate' : Unused code path elimination
 * Block '<S365>/Data Type Propagation' : Unused code path elimination
 * Block '<S366>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S70>/Conversion' : Eliminate redundant data type conversion
 * Block '<S71>/Conversion' : Eliminate redundant data type conversion
 * Block '<S73>/Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S43>/Conversion' : Eliminate redundant data type conversion
 * Block '<S47>/Reshape' : Reshape block reduction
 * Block '<S27>/ReshapeX0' : Reshape block reduction
 * Block '<S27>/Reshapexhat' : Reshape block reduction
 * Block '<S7>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S7>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S11>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S11>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S11>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S189>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S346>/Constant10' : Unused code path elimination
 * Block '<S346>/Constant9' : Unused code path elimination
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
 * '<Root>' : 'Robot_Control'
 * '<S1>'   : 'Robot_Control/Control_System'
 * '<S2>'   : 'Robot_Control/Control_System/Autonomous'
 * '<S3>'   : 'Robot_Control/Control_System/Desired Gyro Override for Shooting'
 * '<S4>'   : 'Robot_Control/Control_System/Disabled'
 * '<S5>'   : 'Robot_Control/Control_System/Human_Input_Pre_Processing'
 * '<S6>'   : 'Robot_Control/Control_System/Internal Feedback'
 * '<S7>'   : 'Robot_Control/Control_System/Kalman_Filter'
 * '<S8>'   : 'Robot_Control/Control_System/Merge'
 * '<S9>'   : 'Robot_Control/Control_System/Output Overrides'
 * '<S10>'  : 'Robot_Control/Control_System/Previous GameState'
 * '<S11>'  : 'Robot_Control/Control_System/Shooter Controls'
 * '<S12>'  : 'Robot_Control/Control_System/Spline_Path_Following'
 * '<S13>'  : 'Robot_Control/Control_System/Swerve_Drive'
 * '<S14>'  : 'Robot_Control/Control_System/Teleop'
 * '<S15>'  : 'Robot_Control/Control_System/Test'
 * '<S16>'  : 'Robot_Control/Control_System/Vision_Corrections'
 * '<S17>'  : 'Robot_Control/Control_System/Autonomous/Subsystem'
 * '<S18>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant1'
 * '<S19>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant5'
 * '<S20>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant6'
 * '<S21>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant7'
 * '<S22>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant8'
 * '<S23>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero17'
 * '<S24>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase'
 * '<S25>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase1'
 * '<S26>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase2'
 * '<S27>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter'
 * '<S28>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL'
 * '<S29>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat'
 * '<S30>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator'
 * '<S31>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionA'
 * '<S32>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionB'
 * '<S33>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionC'
 * '<S34>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionD'
 * '<S35>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionG'
 * '<S36>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionH'
 * '<S37>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionN'
 * '<S38>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP'
 * '<S39>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP0'
 * '<S40>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionQ'
 * '<S41>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionR'
 * '<S42>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionReset'
 * '<S43>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX'
 * '<S44>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX0'
 * '<S45>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionu'
 * '<S46>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/MemoryP'
 * '<S47>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer'
 * '<S48>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN'
 * '<S49>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reset'
 * '<S50>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reshapeyhat'
 * '<S51>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionP0'
 * '<S52>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionQ'
 * '<S53>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionR'
 * '<S54>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator'
 * '<S55>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkA'
 * '<S56>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkB'
 * '<S57>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkC'
 * '<S58>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkD'
 * '<S59>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkEnable'
 * '<S60>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkG'
 * '<S61>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkH'
 * '<S62>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkN'
 * '<S63>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkP0'
 * '<S64>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkQ'
 * '<S65>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkR'
 * '<S66>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkReset'
 * '<S67>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkX0'
 * '<S68>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checku'
 * '<S69>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checky'
 * '<S70>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S71>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S72>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S73>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S74>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/Ground'
 * '<S75>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat/Ground'
 * '<S76>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S77>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S78>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer/MeasurementUpdate'
 * '<S79>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN/Ground'
 * '<S80>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S81>'  : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo'
 * '<S82>'  : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter'
 * '<S83>'  : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter/Saturation Dynamic'
 * '<S84>'  : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter/Unit Delay External IC'
 * '<S85>'  : 'Robot_Control/Control_System/Previous GameState/Chart'
 * '<S86>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings'
 * '<S87>'  : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring'
 * '<S88>'  : 'Robot_Control/Control_System/Shooter Controls/Maximum of measured shooter motor speeds'
 * '<S89>'  : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot'
 * '<S90>'  : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control'
 * '<S91>'  : 'Robot_Control/Control_System/Shooter Controls/Shooter_Transfer_Feeder Chart'
 * '<S92>'  : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control'
 * '<S93>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math'
 * '<S94>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Shooter Not Active'
 * '<S95>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters'
 * '<S96>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Desired Gyro Angle Calculation'
 * '<S97>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target'
 * '<S98>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error'
 * '<S99>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Hood Position'
 * '<S100>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed'
 * '<S101>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Shot_Coordinate_Selection'
 * '<S102>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Subsystem'
 * '<S103>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Desired Gyro Angle Calculation/Degrees to Radians'
 * '<S104>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Calculate Shot Distance'
 * '<S105>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Shot Distance to TOF'
 * '<S106>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Target_Selection'
 * '<S107>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position'
 * '<S108>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check'
 * '<S109>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check/Compare To Constant'
 * '<S110>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error/Degrees to Radians'
 * '<S111>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem'
 * '<S112>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem1'
 * '<S113>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem2'
 * '<S114>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem3'
 * '<S115>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem4'
 * '<S116>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem5'
 * '<S117>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Angle Modulus'
 * '<S118>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone'
 * '<S119>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone'
 * '<S120>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone/Blue'
 * '<S121>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone/Red'
 * '<S122>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone/Blue'
 * '<S123>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone/Red'
 * '<S124>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Compare To Zero'
 * '<S125>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S126>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S127>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S128>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S129>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Compare To Zero'
 * '<S130>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S131>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S132>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S133>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S134>' : 'Robot_Control/Control_System/Spline_Path_Following/Pass Through'
 * '<S135>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled'
 * '<S136>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S137>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S138>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S139>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S140>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S141>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S142>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S143>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S144>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S145>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S146>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S147>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S148>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S149>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S150>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S151>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S152>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S153>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S154>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S155>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S156>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S157>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S158>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S159>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S160>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S161>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S162>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S163>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S164>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S165>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S166>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S167>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S168>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S169>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S170>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S171>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S172>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S173>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S174>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S175>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S176>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S177>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S178>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S179>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S180>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S181>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S182>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S183>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S184>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S185>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S186>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S187>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S188>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S189>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S190>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S191>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S192>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S193>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S194>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S195>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module'
 * '<S196>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1'
 * '<S197>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2'
 * '<S198>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3'
 * '<S199>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S200>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S201>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable'
 * '<S202>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S203>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S204>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S205>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S206>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S207>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Difference'
 * '<S208>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S209>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S210>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S211>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S212>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S213>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S214>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S215>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S216>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S217>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S218>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S219>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S220>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S221>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S222>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable'
 * '<S223>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S224>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S225>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S226>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S227>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S228>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Difference'
 * '<S229>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S230>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S231>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S232>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S233>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S234>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S235>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S236>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S237>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S238>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S239>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S240>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S241>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S242>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S243>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable'
 * '<S244>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S245>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S246>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S247>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S248>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S249>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Difference'
 * '<S250>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S251>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S252>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S253>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S254>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S255>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S256>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S257>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S258>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S259>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S260>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S261>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S262>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S263>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S264>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable'
 * '<S265>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S266>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S267>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S268>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S269>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S270>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Difference'
 * '<S271>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S272>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S273>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S274>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S275>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S276>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S277>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S278>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S279>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S280>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S281>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S282>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S283>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S284>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S285>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S286>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S287>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S288>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S289>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S290>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S291>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S292>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S293>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S294>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S295>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S296>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S297>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1'
 * '<S298>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S299>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S300>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S301>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S302>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S303>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S304>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S305>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S306>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero'
 * '<S307>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero1'
 * '<S308>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero2'
 * '<S309>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero3'
 * '<S310>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter'
 * '<S311>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S312>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S313>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S314>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S315>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S316>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S317>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S318>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S319>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S320>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Reduce Speeds for Maximum Speed Limit'
 * '<S321>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S322>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S323>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S324>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S325>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S326>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S327>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S328>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S329>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S330>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S331>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S332>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S333>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S334>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S335>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S336>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S337>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S338>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S339>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S340>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S341>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S342>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S343>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S344>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S345>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S346>' : 'Robot_Control/Control_System/Teleop/Relative Errors'
 * '<S347>' : 'Robot_Control/Control_System/Teleop/Subsystem'
 * '<S348>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S349>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S350>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Compare To Zero2'
 * '<S351>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase'
 * '<S352>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase1'
 * '<S353>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase2'
 * '<S354>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase3'
 * '<S355>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase4'
 * '<S356>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase5'
 * '<S357>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Previous active game state was not Teleop'
 * '<S358>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Saturation Dynamic'
 * '<S359>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S360>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero'
 * '<S361>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero1'
 * '<S362>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S363>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S364>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S365>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S366>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S367>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S368>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S369>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant'
 * '<S370>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant1'
 * '<S371>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant2'
 * '<S372>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero6'
 * '<S373>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero7'
 * '<S374>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero8'
 * '<S375>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance'
 * '<S376>' : 'Robot_Control/Control_System/Vision_Corrections/Degrees to Radians'
 * '<S377>' : 'Robot_Control/Control_System/Vision_Corrections/Polar to Cartesian1'
 * '<S378>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Prevent raising 0 to a negative exponent'
 * '<S379>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Subsystem'
 */
#endif                                 /* RTW_HEADER_Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
