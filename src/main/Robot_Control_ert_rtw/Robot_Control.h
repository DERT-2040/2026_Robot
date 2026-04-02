/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.482
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Apr  1 21:22:28 2026
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
  real_T UnitDelay_DSTATE;             /* '<S180>/Unit Delay' */
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
  real_T Translation_Speed_RL;         /* '<S365>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S13>/Merge3' */
  real_T Gyro_Angle_SPF;               /* '<S13>/Merge8' */
  real_T Translation_Steering_Cmd;     /* '<S359>/Switch' */
  real_T RB_Meas_Shooter_Speed_Max;    /* '<S138>/Max' */
  real_T RB_Desired_Shoot_Gyro_Ang;    /* '<S134>/Merge' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S13>/Merge' */
  real_T Steering_Heading_Error_deg;   /* '<S391>/Gain' */
  real_T Steering_Heading_PID;         /* '<S387>/Saturation2' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S13>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S358>/Switch' */
  real_T BR_Desired_Wheel_Speed_in;    /* '<S414>/Switch1' */
  real_T FL_Desired_Wheel_Speed_in;    /* '<S399>/Switch1' */
  real_T FR_Desired_Wheel_Speed_in;    /* '<S404>/Switch1' */
  real_T BL_Desired_Wheel_Speed_in;    /* '<S409>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S394>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S414>/Switch' */
  real_T FL_Desired_Module_Angle;      /* '<S399>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S394>/Product' */
  real_T FR_Desired_Module_Angle;      /* '<S404>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S394>/Product1' */
  real_T BL_Desired_Module_Angle;      /* '<S409>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S394>/Product2' */
  real_T RB_Transfer_Motor_PID_DC;     /* '<S142>/Switch2' */
  real_T RB_Feeder_Motor_PID_DC;       /* '<S12>/Saturation' */
  real_T RB_Desired_Shooter_Speed;     /* '<S134>/Merge1' */
  real_T RB_Desired_Hood_Pos_Shoot;    /* '<S134>/Merge2' */
  real_T Estimated_Hood_Pos;           /* '<S130>/Sum' */
  real_T RB_Intake_Roller_Motor_PID_DC;/* '<S57>/Switch2' */
  real_T RB_Intake_Arm_Angle_Mod;      /* '<S51>/Add1' */
  real_T RB_Des_Intake_Arm_Angle_RL;   /* '<S66>/Sum' */
  real_T RB_Intake_Arm_Motor_PID_DC;   /* '<S54>/Switch2' */
  real_T RB_Allow_Shoot_Gyro_Error;    /* '<S134>/Merge3' */
  real_T RB_Shift_Time_Remaining;      /* '<S135>/Merge2' */
  real_T Spline_Index;                 /* '<S13>/Merge6' */
  real_T loop_counter_robot_control;   /* '<S1>/Sum' */
  real_T Steer_Joystick_X;             /* '<S5>/Signal Copy4' */
  real_T Feeder_Motor_Speed_tp;        /* '<Root>/Signal Copy' */
  real_T Relative_Error_Angle;         /* '<S427>/Switch4' */
  real_T Steering_Abs_Gyro_Latch;      /* '<S429>/Switch8' */
  real_T Steering_Abs_Gyro;            /* '<S429>/Switch2' */
  real_T Steering_Abs_Angle;           /* '<S429>/Switch3' */
  real_T Relative_Error_Y;             /* '<S427>/Switch2' */
  real_T Relative_Error_X;             /* '<S427>/Unary Minus1' */
  real_T Auto_Path_ID;                 /* '<S20>/1-D Lookup Table1' */
  real_T Auto_Desired_Static_Action;   /* '<S20>/Chart' */
  real_T Auto_Desired_Dynamic_Action;  /* '<S20>/Chart' */
  real_T Auto_Path_Counter;            /* '<S20>/Chart' */
  real_T abs_Cmd_Out;                  /* '<S370>/Add dither' */
  real_T Spline_Follow_Index;          /* '<S212>/Merge4' */
  real_T Spline_Target_Y;              /* '<S209>/Selector6' */
  real_T Spline_Target_X;              /* '<S209>/Selector2' */
  real_T Assignment[450];              /* '<S234>/Assignment' */
  real_T RB_Desired_Feeder_Speed;    /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Desired_Transfer_Speed;  /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Transfer_Init;           /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Shoot_Target_X;            /* '<S151>/Switch4' */
  real_T RB_Shoot_Target_Y;            /* '<S151>/Switch6' */
  real_T RB_Des_SS_Shoot_Motor_Spd;    /* '<S149>/Lookup Table Dynamic' */
  real_T RB_Des_Init_Shoot_Motor_Spd;  /* '<S149>/Lookup Table Dynamic1' */
  real_T RB_Desired_Shot_Distance;     /* '<S153>/Hypot' */
  real_T RB_Desired_Target_X;          /* '<S156>/Add' */
  real_T RB_Desired_Target_Y;          /* '<S156>/Add1' */
  real_T Product2[2];                  /* '<S128>/Product2' */
  real_T Product3[2];                  /* '<S126>/Product3' */
  real_T RB_Des_Intake_Arm_Angle;      /* '<S6>/Chart' */
  uint16_T WhileIterator;              /* '<S259>/While Iterator' */
  uint8_T Active_GameState;            /* '<S11>/Chart' */
  boolean_T Button_Enable_Wheels;      /* '<S35>/FixPt Relational Operator' */
  boolean_T Button_Reset_Wheel_Offsets;/* '<S36>/FixPt Relational Operator' */
  boolean_T Button_Disable_Wheels;     /* '<S37>/FixPt Relational Operator' */
  boolean_T Drive_Joystick_Z_Mode;     /* '<S33>/Compare' */
  boolean_T Is_Boosting;               /* '<S34>/Compare' */
  boolean_T Spline_Enable;             /* '<S9>/Merge7' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S13>/Merge4' */
  boolean_T RB_IsBlueActive;           /* '<S135>/Merge' */
  boolean_T RB_IsRedActive;            /* '<S135>/Merge1' */
  boolean_T RB_Logic_Score_In_Zone;    /* '<S192>/Merge' */
  boolean_T RB_Logic_Velocity;         /* '<S139>/GreaterThan' */
  boolean_T RB_Logic_Gyro_Angle;       /* '<S139>/Relational Operator' */
  boolean_T RB_Logic_Shooter_Speed;    /* '<S139>/Relational Operator1' */
  boolean_T RB_Logic_Hood_Pos;         /* '<S139>/Relational Operator4' */
  boolean_T RB_Ready_to_Score;         /* '<S139>/AND2' */
  boolean_T Is_Outside_Alliance_Zone;  /* '<S193>/Merge' */
  boolean_T RB_Logic_Outside_Zone;     /* '<S139>/Signal Copy' */
  boolean_T RB_Ready_to_Pass;          /* '<S139>/AND3' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S13>/Merge5' */
  boolean_T Swerve_Drive_Integral_Enable;/* '<S9>/Merge23' */
  boolean_T Can_Pass;                  /* '<S134>/Merge4' */
  boolean_T Robot_Reached_Destination; /* '<S13>/Merge7' */
  boolean_T Test_Mode;                 /* '<S9>/Merge10' */
  boolean_T Relative_Enable;           /* '<S427>/Logical Operator1' */
  boolean_T Steering_Abs_Angle_Active; /* '<S429>/AND6' */
  boolean_T Auto_Spline_Enable;        /* '<S20>/Chart' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S212>/Merge1' */
  boolean_T RB_Shooter_Active;       /* '<S12>/Shooter_Transfer_Feeder Chart' */
} B_Robot_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S35>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S36>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S37>/Delay Input1' */
  real_T FixPtUnitDelay1_DSTATE;       /* '<S44>/FixPt Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_a;     /* '<S47>/FixPt Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_j;     /* '<S50>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S7>/Unit Delay2' */
  real_T TappedDelay_X[2];             /* '<S8>/Tapped Delay' */
  real_T TappedDelay1_X[2];            /* '<S8>/Tapped Delay1' */
  real_T MemoryX_DSTATE[2];            /* '<S75>/MemoryX' */
  real_T UnitDelay_DSTATE_o;           /* '<S185>/Unit Delay' */
  real_T UnitDelay_DSTATE_m;           /* '<S186>/Unit Delay' */
  real_T UnitDelay_1_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_4_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_2_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S390>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S389>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S387>/Unit Delay' */
  real_T UnitDelay_DSTATE_d4;          /* '<S369>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_e;     /* '<S384>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S368>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_p;     /* '<S377>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S343>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S342>/UD' */
  real_T UnitDelay_DSTATE_lw;          /* '<S336>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S280>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S279>/UD' */
  real_T UnitDelay_DSTATE_j;           /* '<S273>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S291>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S290>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S276>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S301>/Unit Delay1' */
  real_T UD_DSTATE_m;                  /* '<S300>/UD' */
  real_T UnitDelay_DSTATE_h;           /* '<S294>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S312>/Unit Delay1' */
  real_T UD_DSTATE_i;                  /* '<S311>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S297>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n4;         /* '<S322>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S321>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S315>/Unit Delay' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S333>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S332>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S318>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S354>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S353>/UD' */
  real_T UnitDelay_DSTATE_lm;          /* '<S339>/Unit Delay' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S204>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S203>/UD' */
  real_T UnitDelay_DSTATE_kz;          /* '<S202>/Unit Delay' */
  real_T DelayInput1_DSTATE_j;         /* '<S199>/Delay Input1' */
  real_T DelayInput1_DSTATE_o;         /* '<S200>/Delay Input1' */
  real_T UnitDelay_DSTATE_eo;          /* '<S56>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g;          /* '<S73>/Unit Delay1' */
  real_T UD_DSTATE_jd;                 /* '<S72>/UD' */
  real_T UnitDelay_DSTATE_dl;          /* '<S71>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c;          /* '<S64>/Unit Delay1' */
  real_T UD_DSTATE_g;                  /* '<S63>/UD' */
  real_T UnitDelay_DSTATE_km;          /* '<S62>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S429>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_j2;         /* '<S429>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S443>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S443>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S447>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_iz[60];     /* '<S20>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_k;          /* '<S19>/Unit Delay1' */
  real_T UnitDelay_DSTATE_b;           /* '<S19>/Unit Delay' */
  real_T UnitDelay2_DSTATE_d;          /* '<S19>/Unit Delay2' */
  real_T UnitDelay_DSTATE_e3;          /* '<S20>/Unit Delay' */
  real_T UnitDelay_DSTATE_hk;          /* '<S22>/Unit Delay' */
  real_T UnitDelay_DSTATE_gh;          /* '<S208>/Unit Delay' */
  real_T UnitDelay_DSTATE_hn;          /* '<S207>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f4;         /* '<S260>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g4;          /* '<S260>/Unit Delay' */
  real_T UnitDelay_DSTATE_le;          /* '<S210>/Unit Delay' */
  real_T UnitDelay1_DSTATE_kc;         /* '<S210>/Unit Delay1' */
  real_T UnitDelay_DSTATE_du;          /* '<S184>/Unit Delay' */
  real_T UnitDelay_DSTATE_di;          /* '<S183>/Unit Delay' */
  real_T UnitDelay_DSTATE_hz;          /* '<S181>/Unit Delay' */
  real_T UnitDelay_DSTATE_hb;          /* '<S179>/Unit Delay' */
  real_T UnitDelay_DSTATE_bb;          /* '<S149>/Unit Delay' */
  real_T counter;                      /* '<S20>/Chart' */
  real_T timer;                        /* '<S370>/Add dither' */
  real_T Feeder_Loops_Shooting;      /* '<S12>/Shooter_Transfer_Feeder Chart' */
  void *MatrixConcatenate_PWORK;       /* '<S229>/Matrix Concatenate' */
  int32_T Selector5_DIMS1[2];          /* '<S229>/Selector5' */
  int32_T MatrixConcatenate_DIMS1[2];  /* '<S229>/Matrix Concatenate' */
  int32_T Selector4_DIMS1[2];          /* '<S229>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S44>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_j;    /* '<S47>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S50>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_o;    /* '<S367>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_p;    /* '<S384>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_cc;   /* '<S377>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_f;    /* '<S132>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S68>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S447>/FixPt Unit Delay2' */
  boolean_T UnitDelay1_DSTATE_nl;      /* '<S7>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_ll;       /* '<S7>/Unit Delay' */
  boolean_T UnitDelay_5_DSTATE;        /* '<S12>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ki;       /* '<S142>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_kt;       /* '<S141>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_oa;      /* '<S141>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S57>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S53>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_ir;       /* '<S16>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_jp;     /* '<S437>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S436>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S432>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S433>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S434>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g2;     /* '<S435>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE_l;       /* '<S429>/Unit Delay2' */
  boolean_T UnitDelay4_DSTATE;         /* '<S429>/Unit Delay4' */
  boolean_T DelayInput1_DSTATE_kb;     /* '<S27>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S28>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gf;     /* '<S31>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_e4;       /* '<S215>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_nu;       /* '<S220>/Unit Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S13>/If' */
  int8_T If_ActiveSubsystem_n;         /* '<S135>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S212>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S215>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S217>/If' */
  uint8_T is_active_c6_Robot_Control;  /* '<S20>/Chart' */
  uint8_T is_c6_Robot_Control;         /* '<S20>/Chart' */
  uint8_T is_active_c7_Robot_Control;  /* '<S370>/Add dither' */
  uint8_T is_c7_Robot_Control;         /* '<S370>/Add dither' */
  uint8_T is_Dither;                   /* '<S370>/Add dither' */
  uint8_T is_active_c2_Robot_Control;/* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_c2_Robot_Control;       /* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_Shooting;               /* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_active_c9_Robot_Control;  /* '<S11>/Chart' */
  uint8_T is_c9_Robot_Control;         /* '<S11>/Chart' */
  uint8_T is_active_c4_Robot_Control;  /* '<S6>/Chart' */
  uint8_T is_c4_Robot_Control;         /* '<S6>/Chart' */
  boolean_T icLoad;                    /* '<S75>/MemoryX' */
  boolean_T Relay_Mode;                /* '<S242>/Relay' */
  boolean_T EnabledSubsystem_MODE;     /* '<S102>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S95>/MeasurementUpdate' */
  DW_IfActionSubsystem1_Robot_C_T IfActionSubsystem3;/* '<S135>/If Action Subsystem3' */
  DW_IfActionSubsystem1_Robot_C_T IfActionSubsystem1;/* '<S135>/If Action Subsystem1' */
} DW_Robot_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S284>/Cos5' */
  const real_T Sin5;                   /* '<S284>/Sin5' */
  const real_T Cos5_g;                 /* '<S305>/Cos5' */
  const real_T Sin5_m;                 /* '<S305>/Sin5' */
  const real_T Cos5_i;                 /* '<S326>/Cos5' */
  const real_T Sin5_e;                 /* '<S326>/Sin5' */
  const real_T Cos5_b;                 /* '<S347>/Cos5' */
  const real_T Sin5_c;                 /* '<S347>/Sin5' */
  const real_T Width;                  /* '<S20>/Width' */
  const real_T Atan2;                  /* '<S357>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S357>/Add' */
  const real_T Atan1;                  /* '<S357>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S357>/Add1' */
  const real_T Atan3;                  /* '<S357>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S357>/Add2' */
  const real_T Atan4;                  /* '<S357>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S357>/Add3' */
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
  boolean_T Joystick_Left_B2;          /* '<Root>/Joystick_Left_B2' */
  boolean_T Joystick_Left_B3;          /* '<Root>/Joystick_Left_B3' */
  boolean_T Joystick_Left_B4;          /* '<Root>/Joystick_Left_B4' */
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
  real_T Desired_Shooter_Speed;        /* '<Root>/Desired_Shooter_Speed' */
  real_T Desired_Shooter_FF_DC;        /* '<Root>/Desired_Shooter_FF_DC' */
  real_T Desired_Hood_Pos;             /* '<Root>/Desired_Hood_Pos' */
  boolean_T Desired_Hood_Enable;       /* '<Root>/Desired_Hood_Enable' */
  real_T Intake_Arm_Motor_DC;          /* '<Root>/Intake_Arm_Motor_DC' */
  real_T Intake_Roller_Motor_DC;       /* '<Root>/Intake_Roller_Motor_DC' */
  real_T Auto_Initial_Gyro_Angle;      /* '<Root>/Auto_Initial_Gyro_Angle' */
  real_T Shooter_Motor_Gain_Kp;        /* '<Root>/Shooter_Motor_Gain_Kp' */
  real_T Shooter_Motor_Gain_Ki;        /* '<Root>/Shooter_Motor_Gain_Ki' */
  real_T Shooter_Motor_Gain_Change;    /* '<Root>/Shooter_Motor_Gain_Change' */
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
extern real_T Blue_Hub_LeftX;          /* Variable: Blue_Hub_LeftX
                                        * Referenced by: '<S150>/Constant2'
                                        */
extern real_T Blue_Hub_LeftY;          /* Variable: Blue_Hub_LeftY
                                        * Referenced by: '<S150>/Constant3'
                                        */
extern real_T Blue_Hub_RightX;         /* Variable: Blue_Hub_RightX
                                        * Referenced by: '<S150>/Constant4'
                                        */
extern real_T Blue_Hub_RightY;         /* Variable: Blue_Hub_RightY
                                        * Referenced by: '<S150>/Constant5'
                                        */
extern real_T Boost_Trigger_Decreasing_Limit;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S444>/Constant1'
                                      */
extern real_T Boost_Trigger_High_Speed;/* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S440>/Constant'
                                        *   '<S440>/Saturation'
                                        */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S444>/Constant3'
                                      */
extern real_T Boost_Trigger_Low_Speed; /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S440>/Constant1'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S273>/Constant3'
                                        *   '<S294>/Constant3'
                                        *   '<S315>/Constant3'
                                        *   '<S336>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S273>/Constant2'
                                   *   '<S294>/Constant2'
                                   *   '<S315>/Constant2'
                                   *   '<S336>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S273>/Saturation'
                                        *   '<S294>/Saturation'
                                        *   '<S315>/Saturation'
                                        *   '<S336>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S273>/Saturation'
                                        *   '<S294>/Saturation'
                                        *   '<S315>/Saturation'
                                        *   '<S336>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S273>/Gain'
                                        *   '<S294>/Gain'
                                        *   '<S315>/Gain'
                                        *   '<S336>/Gain'
                                        */
extern real_T Drive_Motor_Control_I;   /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S273>/Gain2'
                                        *   '<S294>/Gain2'
                                        *   '<S315>/Gain2'
                                        *   '<S336>/Gain2'
                                        */
extern real_T Drive_Motor_Control_I_LL;/* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S273>/Saturation1'
                                        *   '<S294>/Saturation1'
                                        *   '<S315>/Saturation1'
                                        *   '<S336>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_I_UL;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S273>/Saturation1'
                                        *   '<S294>/Saturation1'
                                        *   '<S315>/Saturation1'
                                        *   '<S336>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S273>/Gain1'
                                        *   '<S294>/Gain1'
                                        *   '<S315>/Gain1'
                                        *   '<S336>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S278>/Constant'
                            *   '<S299>/Constant'
                            *   '<S320>/Constant'
                            *   '<S341>/Constant'
                            */
extern real_T Feeder_Max_Pulsetime;    /* Variable: Feeder_Max_Pulsetime
                                        * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                        */
extern real_T Field_BlueAllianceZoneX; /* Variable: Field_BlueAllianceZoneX
                                        * Referenced by:
                                        *   '<S194>/BlueAllianceZoneX'
                                        *   '<S196>/BlueAllianceZoneX'
                                        */
extern real_T Field_Blue_Hub_X;        /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S151>/Constant8'
                                        */
extern real_T Field_Blue_Pass_X;       /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S151>/Blue_Top'
                                        */
extern real_T Field_Hub_Y;             /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S151>/Constant1'
                                        *   '<S151>/Switch3'
                                        */
extern real_T Field_Length;            /* Variable: Field_Length
                                        * Referenced by: '<S150>/Constant10'
                                        */
extern real_T Field_Length_Half;       /* Variable: Field_Length_Half
                                        * Referenced by:
                                        *   '<S168>/Switch'
                                        *   '<S169>/Switch'
                                        */
extern real_T Field_Pass_Y_Bottom;     /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S151>/Blue_Top2'
                                        */
extern real_T Field_Pass_Y_Top;        /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S151>/Blue_Top3'
                                        */
extern real_T Field_RedAllianceZoneX;  /* Variable: Field_RedAllianceZoneX
                                        * Referenced by:
                                        *   '<S195>/RedAllianceZoneX'
                                        *   '<S197>/RedAllianceZoneX'
                                        */
extern real_T Field_Red_Hub_X;         /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S151>/Constant9'
                                        */
extern real_T Field_Red_Pass_X;        /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S151>/Blue_Top1'
                                        */
extern real_T Field_Translation_Control_Gain;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S430>/Gain2'
                                      */
extern real_T Field_Translation_Speed_Max;/* Variable: Field_Translation_Speed_Max
                                           * Referenced by: '<S430>/Constant5'
                                           */
extern real_T Field_Width;             /* Variable: Field_Width
                                        * Referenced by: '<S150>/Constant11'
                                        */
extern real_T KF_Enable;               /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
extern real_T Rate_Limit_X;            /* Variable: Rate_Limit_X
                                        * Referenced by: '<S38>/Constant3'
                                        */
extern real_T Rate_Limit_Y;            /* Variable: Rate_Limit_Y
                                        * Referenced by: '<S39>/Constant3'
                                        */
extern real_T Rate_Limit_Z;            /* Variable: Rate_Limit_Z
                                        * Referenced by: '<S40>/Constant3'
                                        */
extern real_T Rebuilt_Des_Gyro_Shoot_Offset;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S166>/Constant'
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
                                          *   '<S144>/Constant3'
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
                                         * Referenced by: '<S62>/Constant3'
                                         */
extern real_T Rebuilt_Intake_Arm_Gain_P;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                         * Referenced by: '<S62>/Gain1'
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
                                           *   '<S58>/Constant'
                                           */
extern real_T Rebuilt_Intake_Des_Angle_Out;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S59>/Constant'
                                            */
extern real_T Rebuilt_Intake_Meas_In_Disable;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S60>/Constant'
                                      */
extern real_T Rebuilt_Intake_Meas_Out_Disable;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S61>/Constant'
                                     */
extern real_T Rebuilt_Intake_RL_Dec;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S55>/Constant1'
                                        */
extern real_T Rebuilt_Intake_RL_Inc;   /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S55>/Constant3'
                                        */
extern real_T Rebuilt_Match_Time_Auto_Timer;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S179>/Unit Delay'
                                       */
extern real_T Rebuilt_Match_Time_End_Game_Timer;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by:
                                   *   '<S183>/Constant3'
                                   *   '<S184>/Unit Delay'
                                   */
extern real_T Rebuilt_Match_Time_Shift_1;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S174>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_2;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S175>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_3;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S176>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_4;/* Variable: Rebuilt_Match_Time_Shift_4
                                          * Referenced by: '<S177>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_Timer;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S180>/Unit Delay'
                                      *   '<S181>/Unit Delay'
                                      *   '<S182>/Unit Delay'
                                      *   '<S183>/Unit Delay'
                                      */
extern real_T Rebuilt_Match_Time_Shoot_Early;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S180>/Constant2'
                                      *   '<S181>/Constant2'
                                      *   '<S182>/Constant2'
                                      *   '<S183>/Constant2'
                                      *   '<S187>/Constant'
                                      *   '<S188>/Constant'
                                      *   '<S189>/Constant'
                                      *   '<S190>/Constant'
                                      */
extern real_T Rebuilt_Match_Time_Transition;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S171>/Constant'
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
                                * Referenced by: '<S57>/Constant1'
                                */
extern real_T Rebuilt_Roller_Intake_In_Delay;
                                     /* Variable: Rebuilt_Roller_Intake_In_Delay
                                      * Referenced by: '<S69>/Constant'
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
                                        * Referenced by: '<S152>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Dist_1;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S152>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Dist_2;    /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S152>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Dist_3;    /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S152>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Dist_4;    /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S152>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Dist_5;    /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S152>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Dist_6;    /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S152>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Dist_7;    /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S152>/Constant1'
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
                                    * Referenced by: '<S139>/Constant1'
                                    */
extern real_T Rebuilt_Shoot_Motor_Max_Error;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S139>/Constant2'
                                       */
extern real_T Rebuilt_Shoot_Robot_Velocity_Max;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S139>/Constant'
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
                               * Referenced by: '<S141>/Constant1'
                               */
extern real_T Rebuilt_Shooter_Motor_Gain_FF;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S12>/Constant1'
                                       */
extern real_T Rebuilt_Shooter_Motor_Gain_I;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                            * Referenced by: '<S141>/Constant3'
                                            */
extern real_T Rebuilt_Shooter_Motor_Gain_I_Low;
                                   /* Variable: Rebuilt_Shooter_Motor_Gain_I_Low
                                    * Referenced by: '<S141>/Constant9'
                                    */
extern real_T Rebuilt_Shooter_Motor_Gain_P;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                            * Referenced by: '<S141>/Constant4'
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
                              * Referenced by: '<S142>/Constant1'
                              */
extern real_T Rebuilt_Transfer_Minimum_Factor;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
extern real_T Rebuilt_Transfer_Motor_Gain_FF;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S202>/Gain'
                                      */
extern real_T Rebuilt_Transfer_Motor_Gain_I;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S202>/Gain2'
                                       */
extern real_T Rebuilt_Transfer_Motor_Gain_P;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S202>/Gain1'
                                       */
extern real_T Red_Hub_LeftX;           /* Variable: Red_Hub_LeftX
                                        * Referenced by: '<S150>/Constant6'
                                        */
extern real_T Red_Hub_LeftY;           /* Variable: Red_Hub_LeftY
                                        * Referenced by: '<S150>/Constant7'
                                        */
extern real_T Red_Hub_RightX;          /* Variable: Red_Hub_RightX
                                        * Referenced by: '<S150>/Constant8'
                                        */
extern real_T Red_Hub_RightY;          /* Variable: Red_Hub_RightY
                                        * Referenced by: '<S150>/Constant9'
                                        */
extern real_T Relative_Steering_Error_Angle_Gain;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S429>/Constant4'
                                  */
extern real_T Relative_Steering_Error_Angle_Gain_Object_Factor;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S427>/Gain'
                    */
extern real_T Relative_Steering_Speed_Max;/* Variable: Relative_Steering_Speed_Max
                                           * Referenced by: '<S429>/Constant10'
                                           */
extern real_T Relative_Translation_Control_Gain;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S430>/Gain1'
                                   */
extern real_T Relative_Translation_Speed_Max;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S430>/Constant8'
                                      */
extern real_T Spline_Last_Pose_Distance_to_Velocity_Gain;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S262>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S262>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S209>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S222>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S262>/Constant3'
                                     */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S369>/Constant5'
                    */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S369>/Constant6'
                    */
extern real_T Steering_Absolute_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S369>/Constant9'
                          */
extern real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S369>/Constant10'
                    */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S369>/Constant1'
                                */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S369>/Constant3'
                                */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S387>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S387>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S387>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S387>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S386>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S387>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S387>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S387>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S387>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S387>/Constant1'
                                   *   '<S387>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S387>/Constant'
                                   *   '<S387>/Saturation2'
                                   */
extern real_T Steering_Heading_Dither_Gain;/* Variable: Steering_Heading_Dither_Gain
                                            * Referenced by: '<S370>/Add dither'
                                            */
extern real_T Steering_Heading_Dither_Period;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S370>/Add dither'
                                      */
extern real_T Steering_Heading_Dither_Thresh_Off;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S370>/Add dither'
                                  */
extern real_T Steering_Heading_Dither_Thresh_On;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S370>/Add dither'
                                   */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S276>/Constant3'
                                        *   '<S297>/Constant3'
                                        *   '<S318>/Constant3'
                                        *   '<S339>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S276>/Constant2'
                                *   '<S297>/Constant2'
                                *   '<S318>/Constant2'
                                *   '<S339>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S276>/Saturation'
                                           *   '<S297>/Saturation'
                                           *   '<S318>/Saturation'
                                           *   '<S339>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S276>/Saturation'
                                           *   '<S297>/Saturation'
                                           *   '<S318>/Saturation'
                                           *   '<S339>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S276>/Gain2'
                                        *   '<S297>/Gain2'
                                        *   '<S318>/Gain2'
                                        *   '<S339>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S276>/Saturation1'
                                           *   '<S297>/Saturation1'
                                           *   '<S318>/Saturation1'
                                           *   '<S339>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S276>/Saturation1'
                                           *   '<S297>/Saturation1'
                                           *   '<S318>/Saturation1'
                                           *   '<S339>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S276>/Gain1'
                                        *   '<S297>/Gain1'
                                        *   '<S318>/Gain1'
                                        *   '<S339>/Gain1'
                                        */
extern real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S368>/Constant5'
                    */
extern real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S368>/Constant6'
                    */
extern real_T Steering_Relative_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S368>/Constant9'
                          */
extern real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S368>/Constant10'
                    */
extern real_T Steering_Relative_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S368>/Constant1'
                                */
extern real_T Steering_Relative_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S368>/Constant3'
                                */
extern real_T Steering_Relative_Gain;  /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S429>/Constant'
                                        */
extern real_T Steering_Twist_Gain;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S429>/Constant1'
                                        */
extern real_T TEST_Desired_Hood_Enable_OV;/* Variable: TEST_Desired_Hood_Enable_OV
                                           * Referenced by: '<S10>/Constant7'
                                           */
extern real_T TEST_Desired_Hood_Pos_OV;/* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S10>/Constant6'
                                        */
extern real_T TEST_Desired_Shooter_FF_DC_OV;
                                      /* Variable: TEST_Desired_Shooter_FF_DC_OV
                                       * Referenced by: '<S10>/Constant4'
                                       */
extern real_T TEST_Desired_Shooter_Speed_OV;
                                      /* Variable: TEST_Desired_Shooter_Speed_OV
                                       * Referenced by: '<S10>/Constant3'
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
extern real_T TEST_Swerve_Mode_Override_Flag;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S428>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Steering;/* Variable: TEST_Swerve_Mode_Steering
                                         * Referenced by: '<S428>/Constant8'
                                         */
extern real_T TEST_Swerve_Mode_Translation;/* Variable: TEST_Swerve_Mode_Translation
                                            * Referenced by: '<S428>/Constant7'
                                            */
extern real_T TEST_Transfer_Motor_DC_OV;/* Variable: TEST_Transfer_Motor_DC_OV
                                         * Referenced by: '<S10>/Constant1'
                                         */
extern real_T Translation_Speed_Approach_Zero_Error_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S356>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S356>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S356>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S356>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S356>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S356>/Constant3'
                                    */
extern real_T Translation_Twist_Gain;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S430>/Gain'
                                        */
extern real_T Twist_Deadzone_neg;      /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S429>/Dead Zone'
                                        *   '<S430>/Dead Zone'
                                        */
extern real_T Twist_Deadzone_pos;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S429>/Dead Zone'
                                        *   '<S430>/Dead Zone'
                                        */
extern real_T Vision_Object_Angle_Offset;/* Variable: Vision_Object_Angle_Offset
                                          * Referenced by: '<S17>/Constant6'
                                          */
extern real_T Vision_Object_Target_Angle;/* Variable: Vision_Object_Target_Angle
                                          * Referenced by: '<S427>/Constant7'
                                          */
extern real_T Vision_Object_Target_X;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S427>/Constant1'
                                        */
extern real_T Vision_Object_Target_Y;  /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S427>/Constant4'
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
                                        * Referenced by: '<S427>/Constant8'
                                        */
extern real_T Vision_Tag_Target_X;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S427>/Constant2'
                                        */
extern real_T Vision_Tag_Target_Y;     /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S427>/Constant5'
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
                                        *   '<S427>/Constant11'
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
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Propagation' : Unused code path elimination
 * Block '<S44>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Propagation' : Unused code path elimination
 * Block '<S47>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Propagation' : Unused code path elimination
 * Block '<S50>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Propagation' : Unused code path elimination
 * Block '<S62>/Scope' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Propagation' : Unused code path elimination
 * Block '<S68>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * Block '<S162>/Display' : Unused code path elimination
 * Block '<S162>/Display1' : Unused code path elimination
 * Block '<S163>/Display' : Unused code path elimination
 * Block '<S163>/Display1' : Unused code path elimination
 * Block '<S163>/Display4' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate' : Unused code path elimination
 * Block '<S205>/Data Type Propagation' : Unused code path elimination
 * Block '<S202>/Scope' : Unused code path elimination
 * Block '<S221>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S225>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S265>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S281>/Data Type Duplicate' : Unused code path elimination
 * Block '<S281>/Data Type Propagation' : Unused code path elimination
 * Block '<S273>/Scope' : Unused code path elimination
 * Block '<S275>/Scope' : Unused code path elimination
 * Block '<S292>/Data Type Duplicate' : Unused code path elimination
 * Block '<S292>/Data Type Propagation' : Unused code path elimination
 * Block '<S276>/Scope' : Unused code path elimination
 * Block '<S302>/Data Type Duplicate' : Unused code path elimination
 * Block '<S302>/Data Type Propagation' : Unused code path elimination
 * Block '<S294>/Scope' : Unused code path elimination
 * Block '<S296>/Scope' : Unused code path elimination
 * Block '<S313>/Data Type Duplicate' : Unused code path elimination
 * Block '<S313>/Data Type Propagation' : Unused code path elimination
 * Block '<S297>/Scope' : Unused code path elimination
 * Block '<S323>/Data Type Duplicate' : Unused code path elimination
 * Block '<S323>/Data Type Propagation' : Unused code path elimination
 * Block '<S315>/Scope' : Unused code path elimination
 * Block '<S317>/Scope' : Unused code path elimination
 * Block '<S334>/Data Type Duplicate' : Unused code path elimination
 * Block '<S334>/Data Type Propagation' : Unused code path elimination
 * Block '<S318>/Scope' : Unused code path elimination
 * Block '<S344>/Data Type Duplicate' : Unused code path elimination
 * Block '<S344>/Data Type Propagation' : Unused code path elimination
 * Block '<S336>/Scope' : Unused code path elimination
 * Block '<S338>/Scope' : Unused code path elimination
 * Block '<S355>/Data Type Duplicate' : Unused code path elimination
 * Block '<S355>/Data Type Propagation' : Unused code path elimination
 * Block '<S339>/Scope' : Unused code path elimination
 * Block '<S366>/Data Type Duplicate' : Unused code path elimination
 * Block '<S366>/Data Type Propagation' : Unused code path elimination
 * Block '<S367>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S376>/Data Type Duplicate' : Unused code path elimination
 * Block '<S376>/Data Type Propagation' : Unused code path elimination
 * Block '<S377>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S383>/Data Type Duplicate' : Unused code path elimination
 * Block '<S383>/Data Type Propagation' : Unused code path elimination
 * Block '<S384>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S392>/Data Type Duplicate' : Unused code path elimination
 * Block '<S392>/Data Type Propagation' : Unused code path elimination
 * Block '<S387>/Scope' : Unused code path elimination
 * Block '<S439>/Data Type Duplicate' : Unused code path elimination
 * Block '<S439>/Data Type Propagation' : Unused code path elimination
 * Block '<S446>/Data Type Duplicate' : Unused code path elimination
 * Block '<S446>/Data Type Propagation' : Unused code path elimination
 * Block '<S447>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * Block '<S261>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S427>/Constant10' : Unused code path elimination
 * Block '<S427>/Constant9' : Unused code path elimination
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
 * '<S32>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Angle Modulus'
 * '<S33>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant7'
 * '<S34>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero17'
 * '<S35>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase'
 * '<S36>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase1'
 * '<S37>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase2'
 * '<S38>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit'
 * '<S39>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1'
 * '<S40>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2'
 * '<S41>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Subsystem'
 * '<S42>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter'
 * '<S43>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S44>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S45>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter'
 * '<S46>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S47>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S48>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter'
 * '<S49>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter/Saturation Dynamic'
 * '<S50>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter/Unit Delay External IC'
 * '<S51>'  : 'Robot_Control/Control_System/Intake Controls/Angle Modulus Broken Library Link for Degrees'
 * '<S52>'  : 'Robot_Control/Control_System/Intake Controls/Chart'
 * '<S53>'  : 'Robot_Control/Control_System/Intake Controls/Detect Decrease'
 * '<S54>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control'
 * '<S55>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit'
 * '<S56>'  : 'Robot_Control/Control_System/Intake Controls/Subsystem'
 * '<S57>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control'
 * '<S58>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant'
 * '<S59>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant1'
 * '<S60>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant2'
 * '<S61>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant3'
 * '<S62>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID'
 * '<S63>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Difference'
 * '<S64>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Low_Pass_Filter'
 * '<S65>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Saturation Dynamic'
 * '<S66>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter'
 * '<S67>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S68>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S69>'  : 'Robot_Control/Control_System/Intake Controls/Subsystem/Compare To Constant'
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
 * '<S137>' : 'Robot_Control/Control_System/Shooter Controls/Compare To Zero1'
 * '<S138>' : 'Robot_Control/Control_System/Shooter Controls/Maximum of measured shooter motor speeds'
 * '<S139>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot'
 * '<S140>' : 'Robot_Control/Control_System/Shooter Controls/Shooter_Transfer_Feeder Chart'
 * '<S141>' : 'Robot_Control/Control_System/Shooter Controls/Subsystem'
 * '<S142>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control'
 * '<S143>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math'
 * '<S144>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Shooter Not Active'
 * '<S145>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters'
 * '<S146>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target'
 * '<S147>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error'
 * '<S148>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Hood Position'
 * '<S149>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed'
 * '<S150>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2'
 * '<S151>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Shot_Coordinate_Selection'
 * '<S152>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Subsystem'
 * '<S153>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Calculate Shot Distance'
 * '<S154>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Shot Distance to TOF'
 * '<S155>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Target_Selection'
 * '<S156>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position'
 * '<S157>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check'
 * '<S158>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check/Compare To Constant'
 * '<S159>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error/Degrees to Radians'
 * '<S160>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed/Rebuilt_Shoot_Shooter_Spd Init Array'
 * '<S161>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed/Rebuilt_Shoot_Shooter_Spd Steady State Array'
 * '<S162>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/AngleWindow'
 * '<S163>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/Angle_To_Hub'
 * '<S164>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/Choose_Corner'
 * '<S165>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/Choose_Hub'
 * '<S166>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/Subsystem'
 * '<S167>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/Subsystem1'
 * '<S168>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/Choose_Corner/If Action Subsystem'
 * '<S169>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/Choose_Corner/If Action Subsystem1'
 * '<S170>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Passing_Deadzone_v2/Subsystem/Degrees to Radians'
 * '<S171>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/ '
 * '<S172>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/ 1'
 * '<S173>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant'
 * '<S174>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant1'
 * '<S175>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant2'
 * '<S176>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant3'
 * '<S177>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant4'
 * '<S178>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant5'
 * '<S179>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem'
 * '<S180>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem1'
 * '<S181>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem2'
 * '<S182>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem3'
 * '<S183>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem4'
 * '<S184>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem5'
 * '<S185>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Subsystem'
 * '<S186>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Subsystem1'
 * '<S187>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem1/Compare To Constant'
 * '<S188>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem2/Compare To Constant'
 * '<S189>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem3/Compare To Constant'
 * '<S190>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem4/Compare To Constant'
 * '<S191>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Angle Modulus'
 * '<S192>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone'
 * '<S193>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone'
 * '<S194>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone/Blue'
 * '<S195>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone/Red'
 * '<S196>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone/Blue'
 * '<S197>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone/Red'
 * '<S198>' : 'Robot_Control/Control_System/Shooter Controls/Subsystem/Compare To Zero'
 * '<S199>' : 'Robot_Control/Control_System/Shooter Controls/Subsystem/Detect Change1'
 * '<S200>' : 'Robot_Control/Control_System/Shooter Controls/Subsystem/Detect Change2'
 * '<S201>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Compare To Zero'
 * '<S202>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S203>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S204>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S205>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S206>' : 'Robot_Control/Control_System/Spline_Path_Following/Pass Through'
 * '<S207>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled'
 * '<S208>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S209>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S210>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S211>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S212>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S213>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S214>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S215>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S216>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S217>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S218>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S219>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S220>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S221>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S222>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S223>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S224>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S225>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S226>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S227>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S228>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S229>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S230>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S231>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S232>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S233>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S234>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S235>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S236>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S237>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S238>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S239>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S240>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S241>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S242>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S243>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S244>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S245>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S246>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S247>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S248>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S249>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S250>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S251>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S252>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S253>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S254>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S255>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S256>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S257>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S258>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S259>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S260>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S261>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S262>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S263>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S264>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S265>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S266>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S267>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module'
 * '<S268>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1'
 * '<S269>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2'
 * '<S270>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3'
 * '<S271>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S272>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S273>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable'
 * '<S274>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S275>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S276>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S277>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S278>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S279>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Difference'
 * '<S280>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S281>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S282>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S283>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S284>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S285>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S286>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S287>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S288>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S289>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S290>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S291>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S292>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S293>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S294>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable'
 * '<S295>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S296>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S297>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S298>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S299>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S300>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Difference'
 * '<S301>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S302>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S303>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S304>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S305>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S306>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S307>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S308>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S309>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S310>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S311>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S312>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S313>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S314>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S315>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable'
 * '<S316>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S317>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S318>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S319>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S320>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S321>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Difference'
 * '<S322>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S323>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S324>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S325>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S326>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S327>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S328>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S329>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S330>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S331>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S332>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S333>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S334>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S335>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S336>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable'
 * '<S337>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S338>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S339>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S340>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S341>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S342>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Difference'
 * '<S343>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S344>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S345>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S346>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S347>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S348>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S349>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S350>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S351>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S352>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S353>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S354>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S355>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S356>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S357>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S358>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S359>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S360>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S361>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S362>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S363>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S364>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S365>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S366>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S367>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S368>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S369>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1'
 * '<S370>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S371>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S372>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S373>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S374>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S375>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S376>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S377>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S378>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero'
 * '<S379>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero1'
 * '<S380>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero2'
 * '<S381>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero3'
 * '<S382>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter'
 * '<S383>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S384>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S385>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Add dither'
 * '<S386>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S387>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S388>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S389>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S390>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S391>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Radians to Degrees'
 * '<S392>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S393>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S394>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Reduce Speeds for Maximum Speed Limit'
 * '<S395>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S396>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S397>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S398>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S399>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S400>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S401>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S402>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S403>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S404>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S405>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S406>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S407>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S408>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S409>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S410>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S411>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S412>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S413>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S414>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S415>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S416>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S417>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S418>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S419>' : 'Robot_Control/Control_System/Teleop/Compare To Zero'
 * '<S420>' : 'Robot_Control/Control_System/Teleop/Compare To Zero1'
 * '<S421>' : 'Robot_Control/Control_System/Teleop/Compare To Zero2'
 * '<S422>' : 'Robot_Control/Control_System/Teleop/Compare To Zero3'
 * '<S423>' : 'Robot_Control/Control_System/Teleop/Compare To Zero4'
 * '<S424>' : 'Robot_Control/Control_System/Teleop/Compare To Zero5'
 * '<S425>' : 'Robot_Control/Control_System/Teleop/Compare To Zero6'
 * '<S426>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S427>' : 'Robot_Control/Control_System/Teleop/Relative Errors'
 * '<S428>' : 'Robot_Control/Control_System/Teleop/Subsystem'
 * '<S429>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S430>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S431>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Compare To Zero2'
 * '<S432>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase'
 * '<S433>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase1'
 * '<S434>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase2'
 * '<S435>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase3'
 * '<S436>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase4'
 * '<S437>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase5'
 * '<S438>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Previous active game state was not Teleop'
 * '<S439>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Saturation Dynamic'
 * '<S440>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S441>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero'
 * '<S442>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero1'
 * '<S443>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S444>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S445>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S446>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S447>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S448>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S449>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S450>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant'
 * '<S451>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant1'
 * '<S452>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant2'
 * '<S453>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero6'
 * '<S454>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero7'
 * '<S455>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero8'
 * '<S456>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance'
 * '<S457>' : 'Robot_Control/Control_System/Vision_Corrections/Degrees to Radians'
 * '<S458>' : 'Robot_Control/Control_System/Vision_Corrections/Polar to Cartesian1'
 * '<S459>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Prevent raising 0 to a negative exponent'
 * '<S460>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Subsystem'
 */
#endif                                 /* RTW_HEADER_Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
