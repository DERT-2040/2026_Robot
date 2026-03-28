/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.478
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Mar 28 18:50:21 2026
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

/* Block states (default storage) for system '<S135>/If Action Subsystem1' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S169>/Unit Delay' */
} DW_IfActionSubsystem1_Robot_C_T;

/* Block signals (default storage) */
typedef struct {
  real_T Drive_Joystick_X_preRL;       /* '<S5>/Signal Copy1' */
  real_T Drive_Joystick_Y_preRL;       /* '<S5>/Signal Copy2' */
  real_T Drive_Joystick_Z_preRL;       /* '<S5>/Signal Copy3' */
  real_T Steer_Joystick_Y;             /* '<S5>/Signal Copy5' */
  real_T Steer_Joystick_Z;             /* '<S5>/Signal Copy6' */
  real_T Vision_c1_AprilTag_Corr_X_inch;/* '<S17>/Add' */
  real_T Vision_c1_AprilTag_Corr_Y_inch;/* '<S17>/Add1' */
  real_T Vision_c1_AprilTag_Corr_Yaw_deg;/* '<S17>/Add2' */
  real_T Vision_c1_Object_Corr_X_inch; /* '<S17>/Add3' */
  real_T Vision_c1_Object_Corr_Y_inch; /* '<S17>/Add4' */
  real_T Vision_c1_Object_Corr_Yaw_deg;/* '<S17>/Add5' */
  real_T KF_Position_X;                /* '<S8>/Switch' */
  real_T KF_Position_Y;                /* '<S8>/Switch1' */
  real_T Spline_Num_Poses;             /* '<S9>/Merge9' */
  real_T Steering_Abs_Cmd;             /* '<S9>/Merge1' */
  real_T Steering_Rel_Cmd;             /* '<S9>/Merge2' */
  real_T Translation_Speed;            /* '<S9>/Merge4' */
  real_T Translation_Angle;            /* '<S9>/Merge3' */
  real_T Translation_Speed_SPF;        /* '<S13>/Merge2' */
  real_T Translation_Speed_RL;         /* '<S354>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S13>/Merge3' */
  real_T Gyro_Angle_SPF;               /* '<S13>/Merge8' */
  real_T Translation_Steering_Cmd;     /* '<S348>/Switch' */
  real_T RB_Meas_Shooter_Speed_Max;    /* '<S137>/Max' */
  real_T RB_Desired_Shoot_Gyro_Ang;    /* '<S134>/Merge' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S13>/Merge' */
  real_T Steering_Heading_Error_deg;   /* '<S380>/Gain' */
  real_T Steering_Heading_PID;         /* '<S376>/Saturation2' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S13>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S347>/Switch' */
  real_T BR_Desired_Wheel_Speed_in;    /* '<S403>/Switch1' */
  real_T FL_Desired_Wheel_Speed_in;    /* '<S388>/Switch1' */
  real_T FR_Desired_Wheel_Speed_in;    /* '<S393>/Switch1' */
  real_T BL_Desired_Wheel_Speed_in;    /* '<S398>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S383>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S403>/Switch' */
  real_T FL_Desired_Module_Angle;      /* '<S388>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S383>/Product' */
  real_T FR_Desired_Module_Angle;      /* '<S393>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S383>/Product1' */
  real_T BL_Desired_Module_Angle;      /* '<S398>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S383>/Product2' */
  real_T RB_Transfer_Motor_PID_DC;     /* '<S141>/Switch2' */
  real_T RB_Feeder_Motor_PID_DC;       /* '<S12>/Saturation' */
  real_T RB_Desired_Hood_Pos_Shoot;    /* '<S134>/Merge2' */
  real_T Estimated_Hood_Pos;           /* '<S130>/Sum' */
  real_T RB_Intake_Roller_Motor_PID_DC;/* '<S58>/Switch2' */
  real_T RB_Intake_Arm_Angle_Mod;      /* '<S53>/Add1' */
  real_T RB_Des_Intake_Arm_Angle_RL;   /* '<S67>/Sum' */
  real_T RB_Intake_Arm_Motor_PID_DC;   /* '<S56>/Switch2' */
  real_T RB_Desired_Shooter_Speed;     /* '<S134>/Merge1' */
  real_T RB_Shooter_Motor_PID_DC;      /* '<S139>/Switch2' */
  real_T RB_Allow_Shoot_Gyro_Error;    /* '<S134>/Merge3' */
  real_T RB_Shift_Time_Remaining;      /* '<S135>/Merge2' */
  real_T Spline_Index;                 /* '<S13>/Merge6' */
  real_T loop_counter_robot_control;   /* '<S1>/Sum' */
  real_T Steer_Joystick_X;             /* '<S5>/Signal Copy4' */
  real_T Feeder_Motor_Speed_tp;        /* '<Root>/Signal Copy' */
  real_T Relative_Error_Angle;         /* '<S415>/Switch4' */
  real_T Steering_Abs_Gyro_Latch;      /* '<S417>/Switch8' */
  real_T Steering_Abs_Gyro;            /* '<S417>/Switch2' */
  real_T Steering_Abs_Angle;           /* '<S417>/Switch3' */
  real_T Relative_Error_Y;             /* '<S415>/Switch2' */
  real_T Relative_Error_X;             /* '<S415>/Unary Minus1' */
  real_T Auto_Path_ID;                 /* '<S20>/1-D Lookup Table1' */
  real_T Auto_Desired_Static_Action;   /* '<S20>/Chart' */
  real_T Auto_Desired_Dynamic_Action;  /* '<S20>/Chart' */
  real_T Auto_Path_Counter;            /* '<S20>/Chart' */
  real_T abs_Cmd_Out;                  /* '<S359>/Add dither' */
  real_T Spline_Follow_Index;          /* '<S201>/Merge4' */
  real_T Spline_Target_Y;              /* '<S198>/Selector6' */
  real_T Spline_Target_X;              /* '<S198>/Selector2' */
  real_T Assignment[450];              /* '<S223>/Assignment' */
  real_T RB_Desired_Feeder_Speed;    /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Desired_Transfer_Speed;  /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Transfer_Init;           /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Shoot_Target_X;            /* '<S150>/Switch4' */
  real_T RB_Shoot_Target_Y;            /* '<S150>/Switch6' */
  real_T RB_Des_SS_Shoot_Motor_Spd;    /* '<S149>/Lookup Table Dynamic' */
  real_T RB_Des_Init_Shoot_Motor_Spd;  /* '<S149>/Lookup Table Dynamic1' */
  real_T RB_Desired_Shot_Distance;     /* '<S153>/Hypot' */
  real_T RB_Desired_Target_X;          /* '<S156>/Add' */
  real_T RB_Desired_Target_Y;          /* '<S156>/Add1' */
  real_T Product2[2];                  /* '<S128>/Product2' */
  real_T Product3[2];                  /* '<S126>/Product3' */
  real_T RB_Des_Intake_Arm_Angle;      /* '<S6>/Chart' */
  uint16_T WhileIterator;              /* '<S248>/While Iterator' */
  uint8_T Active_GameState;            /* '<S11>/Chart' */
  boolean_T Button_Enable_Wheels;      /* '<S38>/FixPt Relational Operator' */
  boolean_T Button_Reset_Wheel_Offsets;/* '<S39>/FixPt Relational Operator' */
  boolean_T Button_Disable_Wheels;     /* '<S40>/FixPt Relational Operator' */
  boolean_T Drive_Joystick_Z_Mode;     /* '<S35>/Compare' */
  boolean_T Is_Boosting;               /* '<S37>/Compare' */
  boolean_T Face_Toward_Driver;        /* '<S33>/Compare' */
  boolean_T Face_Right_Driver;         /* '<S34>/Compare' */
  boolean_T Face_Left_Driver;          /* '<S36>/Compare' */
  boolean_T Face_Away_Driver;          /* '<S32>/Compare' */
  boolean_T Spline_Enable;             /* '<S9>/Merge7' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S13>/Merge4' */
  boolean_T RB_IsBlueActive;           /* '<S135>/Merge' */
  boolean_T RB_IsRedActive;            /* '<S135>/Merge1' */
  boolean_T RB_Logic_Score_In_Zone;    /* '<S179>/Merge' */
  boolean_T RB_Logic_Velocity;         /* '<S138>/GreaterThan' */
  boolean_T RB_Logic_Gyro_Angle;       /* '<S138>/Relational Operator' */
  boolean_T RB_Logic_Shooter_Speed;    /* '<S138>/Relational Operator1' */
  boolean_T RB_Logic_Hood_Pos;         /* '<S138>/Relational Operator4' */
  boolean_T RB_Ready_to_Score;         /* '<S138>/AND2' */
  boolean_T Is_Outside_Alliance_Zone;  /* '<S180>/Merge' */
  boolean_T RB_Logic_Outside_Zone;     /* '<S138>/Signal Copy' */
  boolean_T RB_Ready_to_Pass;          /* '<S138>/AND3' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S13>/Merge5' */
  boolean_T Swerve_Drive_Integral_Enable;/* '<S9>/Merge23' */
  boolean_T Robot_Reached_Destination; /* '<S13>/Merge7' */
  boolean_T Test_Mode;                 /* '<S9>/Merge10' */
  boolean_T Relative_Enable;           /* '<S415>/Logical Operator1' */
  boolean_T Steering_Abs_Angle_Active; /* '<S417>/AND6' */
  boolean_T Auto_Spline_Enable;        /* '<S20>/Chart' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S201>/Merge1' */
  boolean_T RB_Shooter_Active;       /* '<S12>/Shooter_Transfer_Feeder Chart' */
} B_Robot_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S38>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S39>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S40>/Delay Input1' */
  real_T FixPtUnitDelay1_DSTATE;       /* '<S46>/FixPt Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_a;     /* '<S49>/FixPt Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_j;     /* '<S52>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S7>/Unit Delay2' */
  real_T TappedDelay_X[2];             /* '<S8>/Tapped Delay' */
  real_T TappedDelay1_X[2];            /* '<S8>/Tapped Delay1' */
  real_T MemoryX_DSTATE[2];            /* '<S75>/MemoryX' */
  real_T UnitDelay_1_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_4_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_2_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S379>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S378>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S376>/Unit Delay' */
  real_T UnitDelay_DSTATE_d4;          /* '<S358>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_e;     /* '<S373>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S357>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_p;     /* '<S366>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S332>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S331>/UD' */
  real_T UnitDelay_DSTATE_lw;          /* '<S325>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S269>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S268>/UD' */
  real_T UnitDelay_DSTATE_j;           /* '<S262>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S280>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S279>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S265>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S290>/Unit Delay1' */
  real_T UD_DSTATE_m;                  /* '<S289>/UD' */
  real_T UnitDelay_DSTATE_h;           /* '<S283>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S301>/Unit Delay1' */
  real_T UD_DSTATE_i;                  /* '<S300>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S286>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n4;         /* '<S311>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S310>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S304>/Unit Delay' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S322>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S321>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S307>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S343>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S342>/UD' */
  real_T UnitDelay_DSTATE_lm;          /* '<S328>/Unit Delay' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S193>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S192>/UD' */
  real_T UnitDelay_DSTATE_kz;          /* '<S191>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g;          /* '<S73>/Unit Delay1' */
  real_T UD_DSTATE_jd;                 /* '<S72>/UD' */
  real_T UnitDelay_DSTATE_dl;          /* '<S71>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c;          /* '<S65>/Unit Delay1' */
  real_T UD_DSTATE_g;                  /* '<S64>/UD' */
  real_T UnitDelay_DSTATE_km;          /* '<S63>/Unit Delay' */
  real_T UnitDelay1_DSTATE_in;         /* '<S188>/Unit Delay1' */
  real_T UD_DSTATE_kz;                 /* '<S187>/UD' */
  real_T UnitDelay_DSTATE_l1;          /* '<S186>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S417>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_j2;         /* '<S417>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S431>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S431>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S435>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_iz[60];     /* '<S20>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_k;          /* '<S19>/Unit Delay1' */
  real_T UnitDelay_DSTATE_b;           /* '<S19>/Unit Delay' */
  real_T UnitDelay2_DSTATE_d;          /* '<S19>/Unit Delay2' */
  real_T UnitDelay_DSTATE_e3;          /* '<S20>/Unit Delay' */
  real_T UnitDelay_DSTATE_hk;          /* '<S22>/Unit Delay' */
  real_T UnitDelay_DSTATE_gh;          /* '<S197>/Unit Delay' */
  real_T UnitDelay_DSTATE_hn;          /* '<S196>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f4;         /* '<S249>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g4;          /* '<S249>/Unit Delay' */
  real_T UnitDelay_DSTATE_le;          /* '<S199>/Unit Delay' */
  real_T UnitDelay1_DSTATE_kc;         /* '<S199>/Unit Delay1' */
  real_T UnitDelay_DSTATE_ht;          /* '<S173>/Unit Delay' */
  real_T UnitDelay_DSTATE_n;           /* '<S172>/Unit Delay' */
  real_T UnitDelay_DSTATE_m;           /* '<S170>/Unit Delay' */
  real_T UnitDelay_DSTATE_ms;          /* '<S168>/Unit Delay' */
  real_T UnitDelay_DSTATE_bb;          /* '<S149>/Unit Delay' */
  real_T counter;                      /* '<S20>/Chart' */
  real_T timer;                        /* '<S359>/Add dither' */
  real_T Feeder_Loops_Shooting;      /* '<S12>/Shooter_Transfer_Feeder Chart' */
  void *MatrixConcatenate_PWORK;       /* '<S218>/Matrix Concatenate' */
  int32_T Selector5_DIMS1[2];          /* '<S218>/Selector5' */
  int32_T MatrixConcatenate_DIMS1[2];  /* '<S218>/Matrix Concatenate' */
  int32_T Selector4_DIMS1[2];          /* '<S218>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S46>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_j;    /* '<S49>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S52>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_o;    /* '<S356>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_p;    /* '<S373>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_cc;   /* '<S366>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_f;    /* '<S132>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S69>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S435>/FixPt Unit Delay2' */
  boolean_T UnitDelay_DSTATE_ll;       /* '<S7>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ki;       /* '<S141>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_nh;       /* '<S58>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S55>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_ea;      /* '<S139>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_db;       /* '<S139>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ir;       /* '<S16>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S425>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S424>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S420>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S421>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S422>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g2;     /* '<S423>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE_l;       /* '<S417>/Unit Delay2' */
  boolean_T UnitDelay4_DSTATE;         /* '<S417>/Unit Delay4' */
  boolean_T DelayInput1_DSTATE_kb;     /* '<S27>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S28>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gf;     /* '<S31>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_e4;       /* '<S204>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_nu;       /* '<S209>/Unit Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S13>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S135>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S201>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S204>/If' */
  int8_T If_ActiveSubsystem_d0;        /* '<S206>/If' */
  uint8_T is_active_c6_Robot_Control;  /* '<S20>/Chart' */
  uint8_T is_c6_Robot_Control;         /* '<S20>/Chart' */
  uint8_T is_active_c7_Robot_Control;  /* '<S359>/Add dither' */
  uint8_T is_c7_Robot_Control;         /* '<S359>/Add dither' */
  uint8_T is_Dither;                   /* '<S359>/Add dither' */
  uint8_T is_active_c2_Robot_Control;/* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_c2_Robot_Control;       /* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_Shooting;               /* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_active_c9_Robot_Control;  /* '<S11>/Chart' */
  uint8_T is_c9_Robot_Control;         /* '<S11>/Chart' */
  uint8_T is_active_c4_Robot_Control;  /* '<S6>/Chart' */
  uint8_T is_c4_Robot_Control;         /* '<S6>/Chart' */
  boolean_T icLoad;                    /* '<S75>/MemoryX' */
  boolean_T Relay_Mode;                /* '<S231>/Relay' */
  boolean_T EnabledSubsystem_MODE;     /* '<S102>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S95>/MeasurementUpdate' */
  DW_IfActionSubsystem1_Robot_C_T IfActionSubsystem3;/* '<S135>/If Action Subsystem3' */
  DW_IfActionSubsystem1_Robot_C_T IfActionSubsystem1;/* '<S135>/If Action Subsystem1' */
} DW_Robot_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S273>/Cos5' */
  const real_T Sin5;                   /* '<S273>/Sin5' */
  const real_T Cos5_g;                 /* '<S294>/Cos5' */
  const real_T Sin5_m;                 /* '<S294>/Sin5' */
  const real_T Cos5_i;                 /* '<S315>/Cos5' */
  const real_T Sin5_e;                 /* '<S315>/Sin5' */
  const real_T Cos5_b;                 /* '<S336>/Cos5' */
  const real_T Sin5_c;                 /* '<S336>/Sin5' */
  const real_T Width;                  /* '<S20>/Width' */
  const real_T Atan2;                  /* '<S346>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S346>/Add' */
  const real_T Atan1;                  /* '<S346>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S346>/Add1' */
  const real_T Atan3;                  /* '<S346>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S346>/Add2' */
  const real_T Atan4;                  /* '<S346>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S346>/Add3' */
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
  real_T Gamepad_LB;                   /* '<Root>/Gamepad_LB' */
  real_T Gamepad_LT;                   /* '<Root>/Gamepad_LT' */
  real_T Gamepad_RB;                   /* '<Root>/Gamepad_RB' */
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
  real_T IsBlueInactiveFirst;          /* '<Root>/IsBlueInactiveFirst' */
  real_T Measured_Feeder_Speed;        /* '<Root>/Measured_Feeder_Speed' */
  real_T Measured_Intake_Arm_Angle;    /* '<Root>/Measured_Intake_Arm_Angle' */
  real_T Measured_Intake_Roller_Speed;
                                     /* '<Root>/Measured_Intake_Roller_Speed' */
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
  real_T Intake_Arm_Motor_DC;          /* '<Root>/Intake_Arm_Motor_DC' */
  real_T Intake_Roller_Motor_DC;       /* '<Root>/Intake_Roller_Motor_DC' */
  real_T Auto_Initial_Gyro_Angle;      /* '<Root>/Auto_Initial_Gyro_Angle' */
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
extern real_T Auto_Deploy_Intake_Time; /* Variable: Auto_Deploy_Intake_Time
                                        * Referenced by: '<S26>/Constant'
                                        */
extern real_T Auto_Intake_Arm_Cycle_Delay_Time;
                                   /* Variable: Auto_Intake_Arm_Cycle_Delay_Time
                                    * Referenced by: '<S30>/Constant'
                                    */
extern real_T Auto_Path_Chooser;       /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S21>/Constant17'
                                        */
extern real_T Auto_Shoot_Time;         /* Variable: Auto_Shoot_Time
                                        * Referenced by: '<S24>/Constant'
                                        */
extern real_T Boost_Trigger_Decreasing_Limit;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S432>/Constant1'
                                      */
extern real_T Boost_Trigger_High_Speed;/* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S428>/Constant'
                                        *   '<S428>/Saturation'
                                        */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S432>/Constant3'
                                      */
extern real_T Boost_Trigger_Low_Speed; /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S428>/Constant1'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S262>/Constant3'
                                        *   '<S283>/Constant3'
                                        *   '<S304>/Constant3'
                                        *   '<S325>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S262>/Constant2'
                                   *   '<S283>/Constant2'
                                   *   '<S304>/Constant2'
                                   *   '<S325>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S262>/Saturation'
                                        *   '<S283>/Saturation'
                                        *   '<S304>/Saturation'
                                        *   '<S325>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S262>/Saturation'
                                        *   '<S283>/Saturation'
                                        *   '<S304>/Saturation'
                                        *   '<S325>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S262>/Gain'
                                        *   '<S283>/Gain'
                                        *   '<S304>/Gain'
                                        *   '<S325>/Gain'
                                        */
extern real_T Drive_Motor_Control_I;   /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S262>/Gain2'
                                        *   '<S283>/Gain2'
                                        *   '<S304>/Gain2'
                                        *   '<S325>/Gain2'
                                        */
extern real_T Drive_Motor_Control_I_LL;/* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S262>/Saturation1'
                                        *   '<S283>/Saturation1'
                                        *   '<S304>/Saturation1'
                                        *   '<S325>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_I_UL;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S262>/Saturation1'
                                        *   '<S283>/Saturation1'
                                        *   '<S304>/Saturation1'
                                        *   '<S325>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S262>/Gain1'
                                        *   '<S283>/Gain1'
                                        *   '<S304>/Gain1'
                                        *   '<S325>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S267>/Constant'
                            *   '<S288>/Constant'
                            *   '<S309>/Constant'
                            *   '<S330>/Constant'
                            */
extern real_T Feeder_Max_Pulsetime;    /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
extern real_T Field_BlueAllianceZoneX; /* Variable: Field_BlueAllianceZoneX
                                        * Referenced by:
                                        *   '<S181>/BlueAllianceZoneX'
                                        *   '<S183>/BlueAllianceZoneX'
                                        */
extern real_T Field_Blue_Hub_X;        /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S150>/Constant8'
                                        */
extern real_T Field_Blue_Pass_X;       /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S150>/Blue_Top'
                                        */
extern real_T Field_Hub_Y;             /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S150>/Constant1'
                                        *   '<S150>/Switch3'
                                        */
extern real_T Field_Pass_Y_Bottom;     /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S150>/Blue_Top2'
                                        */
extern real_T Field_Pass_Y_Top;        /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S150>/Blue_Top3'
                                        */
extern real_T Field_RedAllianceZoneX;  /* Variable: Field_RedAllianceZoneX
                                        * Referenced by:
                                        *   '<S182>/RedAllianceZoneX'
                                        *   '<S184>/RedAllianceZoneX'
                                        */
extern real_T Field_Red_Hub_X;         /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S150>/Constant9'
                                        */
extern real_T Field_Red_Pass_X;        /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S150>/Blue_Top1'
                                        */
extern real_T Field_Translation_Control_Gain;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S418>/Gain2'
                                      */
extern real_T Field_Translation_Speed_Max;/* Variable: Field_Translation_Speed_Max
                                           * Referenced by: '<S418>/Constant5'
                                           */
extern real_T KF_Enable;               /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
extern real_T Rate_Limit_X;            /* Variable: Rate_Limit_X
                                        * Referenced by: '<S41>/Constant3'
                                        */
extern real_T Rate_Limit_Y;            /* Variable: Rate_Limit_Y
                                        * Referenced by: '<S42>/Constant3'
                                        */
extern real_T Rate_Limit_Z;            /* Variable: Rate_Limit_Z
                                        * Referenced by: '<S43>/Constant3'
                                        */
extern real_T Rebuilt_Des_Gyro_Shoot_Offset;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S145>/Constant'
                                       */
extern real_T Rebuilt_Feeder_Motor_Gain_FF;/* Variable: Rebuilt_Feeder_Motor_Gain_FF
                                            * Referenced by: '<S12>/Constant'
                                            */
extern real_T Rebuilt_Hood_Servo_Pos_Max;/* Variable: Rebuilt_Hood_Servo_Pos_Max
                                          * Referenced by: '<S10>/Saturation'
                                          */
extern real_T Rebuilt_Hood_Servo_Pos_Min;/* Variable: Rebuilt_Hood_Servo_Pos_Min
                                          * Referenced by:
                                          *   '<S10>/Saturation'
                                          *   '<S143>/Constant3'
                                          */
extern real_T Rebuilt_Hood_Servo_Rate_Limit_Dec;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S129>/Constant1'
                                   */
extern real_T Rebuilt_Hood_Servo_Rate_Limit_Inc;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S129>/Constant3'
                                   */
extern real_T Rebuilt_Intake_Arm_Gain_D;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                         * Referenced by: '<S63>/Constant3'
                                         */
extern real_T Rebuilt_Intake_Arm_Gain_P;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                         * Referenced by: '<S63>/Gain1'
                                         */
extern real_T Rebuilt_Intake_Cycle_Angle_In;
                                      /* Variable: Rebuilt_Intake_Cycle_Angle_In
                                       * Referenced by: '<S6>/Chart'
                                       */
extern real_T Rebuilt_Intake_Cycle_Angle_Out;
                                     /* Variable: Rebuilt_Intake_Cycle_Angle_Out
                                      * Referenced by: '<S6>/Chart'
                                      */
extern real_T Rebuilt_Intake_Des_Angle_In;/* Variable: Rebuilt_Intake_Des_Angle_In
                                           * Referenced by:
                                           *   '<S6>/Chart'
                                           *   '<S59>/Constant'
                                           */
extern real_T Rebuilt_Intake_Des_Angle_Out;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S60>/Constant'
                                            */
extern real_T Rebuilt_Intake_Meas_In_Disable;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S61>/Constant'
                                      */
extern real_T Rebuilt_Intake_Meas_Out_Disable;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S62>/Constant'
                                     */
extern real_T Rebuilt_Intake_RL_Dec;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S57>/Constant1'
                                        */
extern real_T Rebuilt_Intake_RL_Inc;   /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S57>/Constant3'
                                        */
extern real_T Rebuilt_Match_Time_Auto_Timer;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S168>/Unit Delay'
                                       */
extern real_T Rebuilt_Match_Time_End_Game_Timer;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S172>/Constant3'
                                   *   '<S173>/Unit Delay'
                                   */
extern real_T Rebuilt_Match_Time_Shift_1;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S164>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_2;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S165>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_3;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S166>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_4;/* Variable: Rebuilt_Match_Time_Shift_4
                                          * Referenced by: '<S167>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_Timer;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S169>/Unit Delay'
                                      *   '<S170>/Unit Delay'
                                      *   '<S171>/Unit Delay'
                                      *   '<S172>/Unit Delay'
                                      */
extern real_T Rebuilt_Match_Time_Shoot_Early;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S169>/Constant2'
                                      *   '<S170>/Constant2'
                                      *   '<S171>/Constant2'
                                      *   '<S172>/Constant2'
                                      *   '<S174>/Constant'
                                      *   '<S175>/Constant'
                                      *   '<S176>/Constant'
                                      *   '<S177>/Constant'
                                      */
extern real_T Rebuilt_Match_Time_TeleOp;/* Variable: Rebuilt_Match_Time_TeleOp
                                         * Referenced by: '<S135>/Constant'
                                         */
extern real_T Rebuilt_Match_Time_Transition;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S162>/Constant'
                                       */
extern real_T Rebuilt_Negative_Feeder_Speed;
                                      /* Variable: Rebuilt_Negative_Feeder_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
extern real_T Rebuilt_Roller_Desired_Speed;/* Variable: Rebuilt_Roller_Desired_Speed
                                            * Referenced by: '<S6>/Constant'
                                            */
extern real_T Rebuilt_Roller_Error_Integral_Enable;
                               /* Variable: Rebuilt_Roller_Error_Integral_Enable
                                * Referenced by: '<S58>/Constant1'
                                */
extern real_T Rebuilt_Roller_Motor_Gain_FF;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                            * Referenced by: '<S71>/Gain'
                                            */
extern real_T Rebuilt_Roller_Motor_Gain_I;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                           * Referenced by: '<S71>/Gain2'
                                           */
extern real_T Rebuilt_Roller_Motor_Gain_P;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                           * Referenced by: '<S71>/Gain1'
                                           */
extern real_T Rebuilt_Shoot_Dist_0;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S151>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Dist_1;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S151>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Dist_2;    /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S151>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Dist_3;    /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S151>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Dist_4;    /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S151>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Dist_5;    /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S151>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Dist_6;    /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S151>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Dist_7;    /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S151>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_0;/* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S147>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_1;/* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S147>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_2;/* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S147>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_3;/* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S147>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_4;/* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S147>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_5;/* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S147>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_6;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S147>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_7;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S147>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_0;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S148>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_1;/* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S148>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_2;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S148>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_3;/* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S148>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_4;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S148>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_5;/* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S148>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_6;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S148>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_7;/* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S148>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_Max_Error;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S138>/Constant1'
                                    */
extern real_T Rebuilt_Shoot_Motor_Max_Error;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S138>/Constant2'
                                       */
extern real_T Rebuilt_Shoot_Robot_Velocity_Max;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S138>/Constant'
                                    */
extern real_T Rebuilt_Shoot_Shooter_Spd_0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                           * Referenced by: '<S161>/Constant5'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_1;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                           * Referenced by: '<S161>/Constant6'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_2;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                           * Referenced by: '<S161>/Constant7'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_3;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                           * Referenced by: '<S161>/Constant8'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_4;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                           * Referenced by: '<S161>/Constant9'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_5;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                           * Referenced by: '<S161>/Constant10'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_6;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                           * Referenced by: '<S161>/Constant2'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_7;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                           * Referenced by: '<S161>/Constant1'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S160>/Constant5'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_1;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S160>/Constant6'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_2;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S160>/Constant7'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_3;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S160>/Constant8'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_4;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S160>/Constant9'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_5;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S160>/Constant10'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_6;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S160>/Constant2'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_7;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S160>/Constant1'
                                       */
extern real_T Rebuilt_Shoot_TOF_0;     /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S154>/Constant'
                                        */
extern real_T Rebuilt_Shoot_TOF_1;     /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S154>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_TOF_2;     /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S154>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_TOF_3;     /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S154>/Constant3'
                                        */
extern real_T Rebuilt_Shoot_TOF_4;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S154>/Constant4'
                                        */
extern real_T Rebuilt_Shoot_TOF_5;     /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S154>/Constant11'
                                        */
extern real_T Rebuilt_Shoot_TOF_6;     /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S154>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_TOF_7;     /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S154>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Target_Error_Thresh;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S158>/Constant'
                                   */
extern real_T Rebuilt_Shooter_Error_Integral_Enable;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S139>/Constant1'
                               */
extern real_T Rebuilt_Shooter_Motor_Gain_FF;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S186>/Gain'
                                       */
extern real_T Rebuilt_Shooter_Motor_Gain_I;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                            * Referenced by: '<S186>/Gain2'
                                            */
extern real_T Rebuilt_Shooter_Motor_Gain_P;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                            * Referenced by: '<S186>/Gain1'
                                            */
extern real_T Rebuilt_Shot_Init_Time;  /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S149>/Constant2'
                                        */
extern real_T Rebuilt_Target_Feeder_Speed;/* Variable: Rebuilt_Target_Feeder_Speed
                                           * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                           */
extern real_T Rebuilt_Target_Transfer_Speed;
                                      /* Variable: Rebuilt_Target_Transfer_Speed
                                       * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                       */
extern real_T Rebuilt_Transfer_Error_Integral_Enable;
                             /* Variable: Rebuilt_Transfer_Error_Integral_Enable
                              * Referenced by: '<S141>/Constant1'
                              */
extern real_T Rebuilt_Transfer_Minimum_Factor;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
extern real_T Rebuilt_Transfer_Motor_Gain_FF;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S191>/Gain'
                                      */
extern real_T Rebuilt_Transfer_Motor_Gain_I;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S191>/Gain2'
                                       */
extern real_T Rebuilt_Transfer_Motor_Gain_P;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S191>/Gain1'
                                       */
extern real_T Relative_Steering_Error_Angle_Gain;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S417>/Constant4'
                                  */
extern real_T Relative_Steering_Error_Angle_Gain_Object_Factor;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S415>/Gain'
                    */
extern real_T Relative_Steering_Speed_Max;/* Variable: Relative_Steering_Speed_Max
                                           * Referenced by: '<S417>/Constant10'
                                           */
extern real_T Relative_Translation_Control_Gain;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S418>/Gain1'
                                   */
extern real_T Relative_Translation_Speed_Max;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S418>/Constant8'
                                      */
extern real_T Spline_Last_Pose_Distance_to_Velocity_Gain;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S251>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S251>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S198>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S211>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S251>/Constant3'
                                     */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S358>/Constant5'
                    */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S358>/Constant6'
                    */
extern real_T Steering_Absolute_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S358>/Constant9'
                          */
extern real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S358>/Constant10'
                    */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S358>/Constant1'
                                */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S358>/Constant3'
                                */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S376>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S376>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S376>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S376>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S375>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S376>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S376>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S376>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S376>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S376>/Constant1'
                                   *   '<S376>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S376>/Constant'
                                   *   '<S376>/Saturation2'
                                   */
extern real_T Steering_Heading_Dither_Gain;/* Variable: Steering_Heading_Dither_Gain
                                            * Referenced by: '<S359>/Add dither'
                                            */
extern real_T Steering_Heading_Dither_Period;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S359>/Add dither'
                                      */
extern real_T Steering_Heading_Dither_Thresh_Off;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S359>/Add dither'
                                  */
extern real_T Steering_Heading_Dither_Thresh_On;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S359>/Add dither'
                                   */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S265>/Constant3'
                                        *   '<S286>/Constant3'
                                        *   '<S307>/Constant3'
                                        *   '<S328>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S265>/Constant2'
                                *   '<S286>/Constant2'
                                *   '<S307>/Constant2'
                                *   '<S328>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S265>/Saturation'
                                           *   '<S286>/Saturation'
                                           *   '<S307>/Saturation'
                                           *   '<S328>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S265>/Saturation'
                                           *   '<S286>/Saturation'
                                           *   '<S307>/Saturation'
                                           *   '<S328>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S265>/Gain2'
                                        *   '<S286>/Gain2'
                                        *   '<S307>/Gain2'
                                        *   '<S328>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S265>/Saturation1'
                                           *   '<S286>/Saturation1'
                                           *   '<S307>/Saturation1'
                                           *   '<S328>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S265>/Saturation1'
                                           *   '<S286>/Saturation1'
                                           *   '<S307>/Saturation1'
                                           *   '<S328>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S265>/Gain1'
                                        *   '<S286>/Gain1'
                                        *   '<S307>/Gain1'
                                        *   '<S328>/Gain1'
                                        */
extern real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S357>/Constant5'
                    */
extern real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S357>/Constant6'
                    */
extern real_T Steering_Relative_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S357>/Constant9'
                          */
extern real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S357>/Constant10'
                    */
extern real_T Steering_Relative_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S357>/Constant1'
                                */
extern real_T Steering_Relative_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S357>/Constant3'
                                */
extern real_T Steering_Relative_Gain;  /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S417>/Constant'
                                        */
extern real_T Steering_Twist_Gain;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S417>/Constant1'
                                        */
extern real_T TEST_Desired_Hood_Enable_OV;/* Variable: TEST_Desired_Hood_Enable_OV
                                           * Referenced by: '<S10>/Constant7'
                                           */
extern real_T TEST_Desired_Hood_Pos_OV;/* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S10>/Constant6'
                                        */
extern real_T TEST_Feeder_Motor_DC_OV; /* Variable: TEST_Feeder_Motor_DC_OV
                                        * Referenced by: '<S10>/Constant2'
                                        */
extern real_T TEST_Intake_Arm_Motor_DC_OV;/* Variable: TEST_Intake_Arm_Motor_DC_OV
                                           * Referenced by: '<S10>/Constant9'
                                           */
extern real_T TEST_Intake_Roller_Motor_DC_OV;
                                     /* Variable: TEST_Intake_Roller_Motor_DC_OV
                                      * Referenced by: '<S10>/Constant10'
                                      */
extern real_T TEST_Output_Override_Flag;/* Variable: TEST_Output_Override_Flag
                                         * Referenced by: '<S10>/Constant'
                                         */
extern real_T TEST_Shooter_Motor_DC_Center_OV;
                                    /* Variable: TEST_Shooter_Motor_DC_Center_OV
                                     * Referenced by: '<S10>/Constant4'
                                     */
extern real_T TEST_Shooter_Motor_DC_Left_OV;
                                      /* Variable: TEST_Shooter_Motor_DC_Left_OV
                                       * Referenced by: '<S10>/Constant3'
                                       */
extern real_T TEST_Shooter_Motor_DC_Right_OV;
                                     /* Variable: TEST_Shooter_Motor_DC_Right_OV
                                      * Referenced by: '<S10>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Override_Flag;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S416>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Steering;/* Variable: TEST_Swerve_Mode_Steering
                                         * Referenced by: '<S416>/Constant8'
                                         */
extern real_T TEST_Swerve_Mode_Translation;/* Variable: TEST_Swerve_Mode_Translation
                                            * Referenced by: '<S416>/Constant7'
                                            */
extern real_T TEST_Transfer_Motor_DC_OV;/* Variable: TEST_Transfer_Motor_DC_OV
                                         * Referenced by: '<S10>/Constant1'
                                         */
extern real_T Translation_Speed_Approach_Zero_Error_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S345>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S345>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S345>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S345>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S345>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S345>/Constant3'
                                    */
extern real_T Translation_Twist_Gain;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S418>/Gain'
                                        */
extern real_T Twist_Deadzone_neg;      /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S417>/Dead Zone'
                                        *   '<S418>/Dead Zone'
                                        */
extern real_T Twist_Deadzone_pos;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S417>/Dead Zone'
                                        *   '<S418>/Dead Zone'
                                        */
extern real_T Vision_Object_Angle_Offset;/* Variable: Vision_Object_Angle_Offset
                                          * Referenced by: '<S17>/Constant6'
                                          */
extern real_T Vision_Object_Target_Angle;/* Variable: Vision_Object_Target_Angle
                                          * Referenced by: '<S415>/Constant7'
                                          */
extern real_T Vision_Object_Target_X;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S415>/Constant1'
                                        */
extern real_T Vision_Object_Target_Y;  /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S415>/Constant4'
                                        */
extern real_T Vision_Object_X_Offset;  /* Variable: Vision_Object_X_Offset
                                        * Referenced by: '<S17>/Constant4'
                                        */
extern real_T Vision_Object_Y_Offset;  /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S17>/Constant8'
                                        */
extern real_T Vision_Tag_Angle_Offset; /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S17>/Constant5'
                                        */
extern real_T Vision_Tag_Target_Angle; /* Variable: Vision_Tag_Target_Angle
                                        * Referenced by: '<S415>/Constant8'
                                        */
extern real_T Vision_Tag_Target_X;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S415>/Constant2'
                                        */
extern real_T Vision_Tag_Target_Y;     /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S415>/Constant5'
                                        */
extern real_T Vision_Tag_X_Offset;     /* Variable: Vision_Tag_X_Offset
                                        * Referenced by: '<S17>/Constant3'
                                        */
extern real_T Vision_Tag_Y_Offset;     /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S17>/Constant7'
                                        */
extern uint8_T TEST_Pipeline;          /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S16>/Constant22'
                                        *   '<S415>/Constant11'
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
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Propagation' : Unused code path elimination
 * Block '<S46>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Propagation' : Unused code path elimination
 * Block '<S49>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Propagation' : Unused code path elimination
 * Block '<S52>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Propagation' : Unused code path elimination
 * Block '<S63>/Scope' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Propagation' : Unused code path elimination
 * Block '<S69>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Propagation' : Unused code path elimination
 * Block '<S71>/Scope' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Conversion' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Conversion' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/G' : Unused code path elimination
 * Block '<S75>/H' : Unused code path elimination
 * Block '<S75>/N' : Unused code path elimination
 * Block '<S75>/P0' : Unused code path elimination
 * Block '<S75>/Q' : Unused code path elimination
 * Block '<S75>/R' : Unused code path elimination
 * Block '<S107>/CheckSignalProperties' : Unused code path elimination
 * Block '<S116>/CheckSignalProperties' : Unused code path elimination
 * Block '<S117>/CheckSignalProperties' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Propagation' : Unused code path elimination
 * Block '<S132>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S11>/Unit Delay1' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Propagation' : Unused code path elimination
 * Block '<S186>/Scope' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Propagation' : Unused code path elimination
 * Block '<S191>/Scope' : Unused code path elimination
 * Block '<S210>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S254>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S270>/Data Type Duplicate' : Unused code path elimination
 * Block '<S270>/Data Type Propagation' : Unused code path elimination
 * Block '<S262>/Scope' : Unused code path elimination
 * Block '<S264>/Scope' : Unused code path elimination
 * Block '<S281>/Data Type Duplicate' : Unused code path elimination
 * Block '<S281>/Data Type Propagation' : Unused code path elimination
 * Block '<S265>/Scope' : Unused code path elimination
 * Block '<S291>/Data Type Duplicate' : Unused code path elimination
 * Block '<S291>/Data Type Propagation' : Unused code path elimination
 * Block '<S283>/Scope' : Unused code path elimination
 * Block '<S285>/Scope' : Unused code path elimination
 * Block '<S302>/Data Type Duplicate' : Unused code path elimination
 * Block '<S302>/Data Type Propagation' : Unused code path elimination
 * Block '<S286>/Scope' : Unused code path elimination
 * Block '<S312>/Data Type Duplicate' : Unused code path elimination
 * Block '<S312>/Data Type Propagation' : Unused code path elimination
 * Block '<S304>/Scope' : Unused code path elimination
 * Block '<S306>/Scope' : Unused code path elimination
 * Block '<S323>/Data Type Duplicate' : Unused code path elimination
 * Block '<S323>/Data Type Propagation' : Unused code path elimination
 * Block '<S307>/Scope' : Unused code path elimination
 * Block '<S333>/Data Type Duplicate' : Unused code path elimination
 * Block '<S333>/Data Type Propagation' : Unused code path elimination
 * Block '<S325>/Scope' : Unused code path elimination
 * Block '<S327>/Scope' : Unused code path elimination
 * Block '<S344>/Data Type Duplicate' : Unused code path elimination
 * Block '<S344>/Data Type Propagation' : Unused code path elimination
 * Block '<S328>/Scope' : Unused code path elimination
 * Block '<S355>/Data Type Duplicate' : Unused code path elimination
 * Block '<S355>/Data Type Propagation' : Unused code path elimination
 * Block '<S356>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S365>/Data Type Duplicate' : Unused code path elimination
 * Block '<S365>/Data Type Propagation' : Unused code path elimination
 * Block '<S366>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S372>/Data Type Duplicate' : Unused code path elimination
 * Block '<S372>/Data Type Propagation' : Unused code path elimination
 * Block '<S373>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S381>/Data Type Duplicate' : Unused code path elimination
 * Block '<S381>/Data Type Propagation' : Unused code path elimination
 * Block '<S376>/Scope' : Unused code path elimination
 * Block '<S427>/Data Type Duplicate' : Unused code path elimination
 * Block '<S427>/Data Type Propagation' : Unused code path elimination
 * Block '<S434>/Data Type Duplicate' : Unused code path elimination
 * Block '<S434>/Data Type Propagation' : Unused code path elimination
 * Block '<S435>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S3>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S118>/Conversion' : Eliminate redundant data type conversion
 * Block '<S119>/Conversion' : Eliminate redundant data type conversion
 * Block '<S121>/Conversion' : Eliminate redundant data type conversion
 * Block '<S75>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S91>/Conversion' : Eliminate redundant data type conversion
 * Block '<S95>/Reshape' : Reshape block reduction
 * Block '<S75>/ReshapeX0' : Reshape block reduction
 * Block '<S75>/Reshapexhat' : Reshape block reduction
 * Block '<S8>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S8>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S12>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S12>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S12>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S250>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S415>/Constant10' : Unused code path elimination
 * Block '<S415>/Constant9' : Unused code path elimination
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
 * '<S6>'   : 'Robot_Control/Control_System/Intake Controls'
 * '<S7>'   : 'Robot_Control/Control_System/Internal Feedback'
 * '<S8>'   : 'Robot_Control/Control_System/Kalman_Filter'
 * '<S9>'   : 'Robot_Control/Control_System/Merge'
 * '<S10>'  : 'Robot_Control/Control_System/Output Overrides'
 * '<S11>'  : 'Robot_Control/Control_System/Previous GameState'
 * '<S12>'  : 'Robot_Control/Control_System/Shooter Controls'
 * '<S13>'  : 'Robot_Control/Control_System/Spline_Path_Following'
 * '<S14>'  : 'Robot_Control/Control_System/Swerve_Drive'
 * '<S15>'  : 'Robot_Control/Control_System/Teleop'
 * '<S16>'  : 'Robot_Control/Control_System/Test'
 * '<S17>'  : 'Robot_Control/Control_System/Vision_Corrections'
 * '<S18>'  : 'Robot_Control/Control_System/Autonomous/Subsystem'
 * '<S19>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic'
 * '<S20>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Autonomous Paths and Actions'
 * '<S21>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Subsystem'
 * '<S22>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Take Action'
 * '<S23>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic/Compare To Constant'
 * '<S24>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic/Compare To Constant1'
 * '<S25>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic/Compare To Constant2'
 * '<S26>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic/Compare To Constant3'
 * '<S27>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic/Detect Increase'
 * '<S28>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic/Detect Increase1'
 * '<S29>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Autonomous Paths and Actions/Chart'
 * '<S30>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Take Action/Compare To Constant'
 * '<S31>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Take Action/Detect Increase'
 * '<S32>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant1'
 * '<S33>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant5'
 * '<S34>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant6'
 * '<S35>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant7'
 * '<S36>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant8'
 * '<S37>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero17'
 * '<S38>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase'
 * '<S39>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase1'
 * '<S40>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase2'
 * '<S41>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit'
 * '<S42>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1'
 * '<S43>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2'
 * '<S44>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter'
 * '<S45>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S46>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S47>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter'
 * '<S48>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S49>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S50>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter'
 * '<S51>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter/Saturation Dynamic'
 * '<S52>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter/Unit Delay External IC'
 * '<S53>'  : 'Robot_Control/Control_System/Intake Controls/Angle Modulus Broken Library Link for Degrees'
 * '<S54>'  : 'Robot_Control/Control_System/Intake Controls/Chart'
 * '<S55>'  : 'Robot_Control/Control_System/Intake Controls/Detect Decrease'
 * '<S56>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control'
 * '<S57>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit'
 * '<S58>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control'
 * '<S59>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant'
 * '<S60>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant1'
 * '<S61>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant2'
 * '<S62>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant3'
 * '<S63>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID'
 * '<S64>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Difference'
 * '<S65>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Low_Pass_Filter'
 * '<S66>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Saturation Dynamic'
 * '<S67>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter'
 * '<S68>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S69>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S70>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Compare To Zero'
 * '<S71>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S72>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S73>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S74>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S75>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter'
 * '<S76>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL'
 * '<S77>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat'
 * '<S78>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator'
 * '<S79>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionA'
 * '<S80>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionB'
 * '<S81>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionC'
 * '<S82>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionD'
 * '<S83>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionG'
 * '<S84>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionH'
 * '<S85>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionN'
 * '<S86>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP'
 * '<S87>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP0'
 * '<S88>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionQ'
 * '<S89>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionR'
 * '<S90>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionReset'
 * '<S91>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX'
 * '<S92>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX0'
 * '<S93>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionu'
 * '<S94>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/MemoryP'
 * '<S95>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer'
 * '<S96>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN'
 * '<S97>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reset'
 * '<S98>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reshapeyhat'
 * '<S99>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionP0'
 * '<S100>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionQ'
 * '<S101>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionR'
 * '<S102>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator'
 * '<S103>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkA'
 * '<S104>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkB'
 * '<S105>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkC'
 * '<S106>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkD'
 * '<S107>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkEnable'
 * '<S108>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkG'
 * '<S109>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkH'
 * '<S110>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkN'
 * '<S111>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkP0'
 * '<S112>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkQ'
 * '<S113>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkR'
 * '<S114>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkReset'
 * '<S115>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkX0'
 * '<S116>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checku'
 * '<S117>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checky'
 * '<S118>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S119>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S120>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S121>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S122>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/Ground'
 * '<S123>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat/Ground'
 * '<S124>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S125>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S126>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer/MeasurementUpdate'
 * '<S127>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN/Ground'
 * '<S128>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S129>' : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo'
 * '<S130>' : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter'
 * '<S131>' : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter/Saturation Dynamic'
 * '<S132>' : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter/Unit Delay External IC'
 * '<S133>' : 'Robot_Control/Control_System/Previous GameState/Chart'
 * '<S134>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings'
 * '<S135>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring'
 * '<S136>' : 'Robot_Control/Control_System/Shooter Controls/Compare To Zero'
 * '<S137>' : 'Robot_Control/Control_System/Shooter Controls/Maximum of measured shooter motor speeds'
 * '<S138>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot'
 * '<S139>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control'
 * '<S140>' : 'Robot_Control/Control_System/Shooter Controls/Shooter_Transfer_Feeder Chart'
 * '<S141>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control'
 * '<S142>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math'
 * '<S143>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Shooter Not Active'
 * '<S144>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters'
 * '<S145>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Desired Gyro Angle Calculation'
 * '<S146>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target'
 * '<S147>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error'
 * '<S148>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Hood Position'
 * '<S149>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed'
 * '<S150>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Shot_Coordinate_Selection'
 * '<S151>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Subsystem'
 * '<S152>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Desired Gyro Angle Calculation/Degrees to Radians'
 * '<S153>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Calculate Shot Distance'
 * '<S154>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Shot Distance to TOF'
 * '<S155>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Target_Selection'
 * '<S156>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position'
 * '<S157>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check'
 * '<S158>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check/Compare To Constant'
 * '<S159>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error/Degrees to Radians'
 * '<S160>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed/Rebuilt_Shoot_Shooter_Spd Init Array'
 * '<S161>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed/Rebuilt_Shoot_Shooter_Spd Steady State Array'
 * '<S162>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/ '
 * '<S163>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/ 1'
 * '<S164>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant1'
 * '<S165>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant2'
 * '<S166>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant3'
 * '<S167>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant4'
 * '<S168>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem'
 * '<S169>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem1'
 * '<S170>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem2'
 * '<S171>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem3'
 * '<S172>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem4'
 * '<S173>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem5'
 * '<S174>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem1/Compare To Constant'
 * '<S175>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem2/Compare To Constant'
 * '<S176>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem3/Compare To Constant'
 * '<S177>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem4/Compare To Constant'
 * '<S178>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Angle Modulus'
 * '<S179>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone'
 * '<S180>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone'
 * '<S181>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone/Blue'
 * '<S182>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone/Red'
 * '<S183>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone/Blue'
 * '<S184>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone/Red'
 * '<S185>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Compare To Zero'
 * '<S186>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S187>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S188>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S189>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S190>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Compare To Zero'
 * '<S191>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S192>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S193>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S194>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S195>' : 'Robot_Control/Control_System/Spline_Path_Following/Pass Through'
 * '<S196>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled'
 * '<S197>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S198>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S199>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S200>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S201>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S202>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S203>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S204>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S205>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S206>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S207>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S208>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S209>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S210>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S211>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S212>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S213>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S214>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S215>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S216>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S217>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S218>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S219>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S220>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S221>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S222>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S223>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S224>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S225>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S226>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S227>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S228>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S229>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S230>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S231>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S232>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S233>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S234>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S235>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S236>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S237>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S238>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S239>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S240>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S241>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S242>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S243>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S244>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S245>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S246>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S247>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S248>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S249>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S250>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S251>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S252>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S253>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S254>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S255>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S256>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module'
 * '<S257>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1'
 * '<S258>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2'
 * '<S259>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3'
 * '<S260>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S261>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S262>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable'
 * '<S263>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S264>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S265>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S266>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S267>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S268>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Difference'
 * '<S269>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S270>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S271>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S272>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S273>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S274>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S275>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S276>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S277>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S278>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S279>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S280>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S281>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S282>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S283>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable'
 * '<S284>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S285>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S286>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S287>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S288>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S289>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Difference'
 * '<S290>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S291>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S292>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S293>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S294>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S295>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S296>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S297>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S298>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S299>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S300>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S301>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S302>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S303>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S304>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable'
 * '<S305>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S306>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S307>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S308>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S309>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S310>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Difference'
 * '<S311>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S312>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S313>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S314>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S315>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S316>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S317>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S318>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S319>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S320>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S321>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S322>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S323>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S324>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S325>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable'
 * '<S326>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S327>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S328>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S329>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S330>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S331>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Difference'
 * '<S332>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S333>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S334>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S335>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S336>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S337>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S338>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S339>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S340>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S341>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S342>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S343>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S344>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S345>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S346>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S347>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S348>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S349>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S350>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S351>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S352>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S353>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S354>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S355>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S356>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S357>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S358>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1'
 * '<S359>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S360>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S361>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S362>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S363>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S364>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S365>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S366>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S367>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero'
 * '<S368>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero1'
 * '<S369>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero2'
 * '<S370>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero3'
 * '<S371>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter'
 * '<S372>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S373>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S374>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Add dither'
 * '<S375>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S376>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S377>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S378>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S379>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S380>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Radians to Degrees'
 * '<S381>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S382>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S383>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Reduce Speeds for Maximum Speed Limit'
 * '<S384>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S385>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S386>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S387>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S388>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S389>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S390>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S391>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S392>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S393>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S394>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S395>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S396>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S397>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S398>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S399>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S400>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S401>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S402>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S403>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S404>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S405>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S406>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S407>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S408>' : 'Robot_Control/Control_System/Teleop/Compare To Zero'
 * '<S409>' : 'Robot_Control/Control_System/Teleop/Compare To Zero1'
 * '<S410>' : 'Robot_Control/Control_System/Teleop/Compare To Zero2'
 * '<S411>' : 'Robot_Control/Control_System/Teleop/Compare To Zero3'
 * '<S412>' : 'Robot_Control/Control_System/Teleop/Compare To Zero4'
 * '<S413>' : 'Robot_Control/Control_System/Teleop/Compare To Zero5'
 * '<S414>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S415>' : 'Robot_Control/Control_System/Teleop/Relative Errors'
 * '<S416>' : 'Robot_Control/Control_System/Teleop/Subsystem'
 * '<S417>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S418>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S419>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Compare To Zero2'
 * '<S420>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase'
 * '<S421>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase1'
 * '<S422>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase2'
 * '<S423>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase3'
 * '<S424>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase4'
 * '<S425>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase5'
 * '<S426>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Previous active game state was not Teleop'
 * '<S427>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Saturation Dynamic'
 * '<S428>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S429>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero'
 * '<S430>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero1'
 * '<S431>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S432>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S433>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S434>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S435>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S436>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S437>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S438>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant'
 * '<S439>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant1'
 * '<S440>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant2'
 * '<S441>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero6'
 * '<S442>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero7'
 * '<S443>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero8'
 * '<S444>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance'
 * '<S445>' : 'Robot_Control/Control_System/Vision_Corrections/Degrees to Radians'
 * '<S446>' : 'Robot_Control/Control_System/Vision_Corrections/Polar to Cartesian1'
 * '<S447>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Prevent raising 0 to a negative exponent'
 * '<S448>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Subsystem'
 */
#endif                                 /* RTW_HEADER_Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
