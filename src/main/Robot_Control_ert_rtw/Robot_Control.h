/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.476
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Mar 15 10:36:05 2026
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

/* Block states (default storage) for system '<S130>/If Action Subsystem1' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S163>/Unit Delay' */
} DW_IfActionSubsystem1_Robot_C_T;

/* Block states (default storage) for system '<S130>/If Action Subsystem2' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S164>/Unit Delay' */
} DW_IfActionSubsystem2_Robot_C_T;

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
  real_T Translation_Speed_RL;         /* '<S348>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S13>/Merge3' */
  real_T Gyro_Angle_SPF;               /* '<S13>/Merge8' */
  real_T Translation_Steering_Cmd;     /* '<S342>/Switch' */
  real_T RB_Meas_Shooter_Speed_Max;    /* '<S131>/Max' */
  real_T RB_Desired_Shoot_Gyro_Ang;    /* '<S129>/Merge' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S13>/Merge' */
  real_T Steering_Heading_Error_deg;   /* '<S374>/Gain' */
  real_T Steering_Heading_PID;         /* '<S370>/Saturation2' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S13>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S341>/Switch' */
  real_T BR_Desired_Wheel_Speed_in;    /* '<S397>/Switch1' */
  real_T FL_Desired_Wheel_Speed_in;    /* '<S382>/Switch1' */
  real_T FR_Desired_Wheel_Speed_in;    /* '<S387>/Switch1' */
  real_T BL_Desired_Wheel_Speed_in;    /* '<S392>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S377>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S397>/Switch' */
  real_T FL_Desired_Module_Angle;      /* '<S382>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S377>/Product' */
  real_T FR_Desired_Module_Angle;      /* '<S387>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S377>/Product1' */
  real_T BL_Desired_Module_Angle;      /* '<S392>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S377>/Product2' */
  real_T RB_Transfer_Motor_PID_DC;     /* '<S135>/Switch2' */
  real_T RB_Feeder_Motor_PID_DC;       /* '<S12>/Saturation' */
  real_T RB_Desired_Hood_Pos_Shoot;    /* '<S129>/Merge2' */
  real_T Estimated_Hood_Pos;           /* '<S125>/Sum' */
  real_T RB_Intake_Roller_Motor_PID_DC;/* '<S53>/Switch2' */
  real_T RB_Intake_Arm_Angle_Mod;      /* '<S48>/Add1' */
  real_T RB_Des_Intake_Arm_Angle_RL;   /* '<S62>/Sum' */
  real_T RB_Intake_Arm_Motor_PID_DC;   /* '<S51>/Switch2' */
  real_T RB_Desired_Shooter_Speed;     /* '<S129>/Merge1' */
  real_T RB_Shooter_Motor_PID_DC;      /* '<S133>/Switch2' */
  real_T RB_Allow_Shoot_Gyro_Error;    /* '<S129>/Merge3' */
  real_T RB_Shift_Time_Remaining;      /* '<S130>/Merge2' */
  real_T Spline_Index;                 /* '<S13>/Merge6' */
  real_T loop_counter_robot_control;   /* '<S1>/Sum' */
  real_T Steer_Joystick_X;             /* '<S5>/Signal Copy4' */
  real_T Feeder_Motor_Speed_tp;        /* '<Root>/Signal Copy' */
  real_T Relative_Error_Angle;         /* '<S409>/Switch4' */
  real_T Steering_Abs_Gyro_Latch;      /* '<S411>/Switch8' */
  real_T Steering_Abs_Gyro;            /* '<S411>/Switch2' */
  real_T Steering_Abs_Angle;           /* '<S411>/Switch3' */
  real_T Relative_Error_Y;             /* '<S409>/Switch2' */
  real_T Relative_Error_X;             /* '<S409>/Unary Minus1' */
  real_T Auto_Path_ID;                 /* '<S20>/1-D Lookup Table1' */
  real_T Auto_Desired_Static_Action;   /* '<S20>/Chart' */
  real_T Auto_Desired_Dynamic_Action;  /* '<S20>/Chart' */
  real_T Auto_Path_Counter;            /* '<S20>/Chart' */
  real_T abs_Cmd_Out;                  /* '<S353>/Add dither' */
  real_T Spline_Follow_Index;          /* '<S195>/Merge4' */
  real_T Spline_Target_Y;              /* '<S192>/Selector6' */
  real_T Spline_Target_X;              /* '<S192>/Selector2' */
  real_T Assignment[450];              /* '<S217>/Assignment' */
  real_T RB_Desired_Feeder_Speed;    /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Desired_Transfer_Speed;  /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Transfer_Init;           /* '<S12>/Shooter_Transfer_Feeder Chart' */
  real_T RB_Shoot_Target_X;            /* '<S144>/Switch4' */
  real_T RB_Shoot_Target_Y;            /* '<S144>/Switch6' */
  real_T RB_Des_SS_Shoot_Motor_Spd;    /* '<S143>/Lookup Table Dynamic' */
  real_T RB_Des_Init_Shoot_Motor_Spd;  /* '<S143>/Lookup Table Dynamic1' */
  real_T RB_Desired_Shot_Distance;     /* '<S147>/Hypot' */
  real_T RB_Desired_Target_X;          /* '<S150>/Add' */
  real_T RB_Desired_Target_Y;          /* '<S150>/Add1' */
  real_T Product2[2];                  /* '<S123>/Product2' */
  real_T Product3[2];                  /* '<S121>/Product3' */
  real_T RB_Des_Intake_Arm_Angle;      /* '<S6>/Chart' */
  uint16_T WhileIterator;              /* '<S242>/While Iterator' */
  uint8_T Active_GameState;            /* '<S11>/Chart' */
  boolean_T Button_Enable_Wheels;      /* '<S33>/FixPt Relational Operator' */
  boolean_T Button_Reset_Wheel_Offsets;/* '<S34>/FixPt Relational Operator' */
  boolean_T Button_Disable_Wheels;     /* '<S35>/FixPt Relational Operator' */
  boolean_T Drive_Joystick_Z_Mode;     /* '<S30>/Compare' */
  boolean_T Is_Boosting;               /* '<S32>/Compare' */
  boolean_T Face_Toward_Driver;        /* '<S28>/Compare' */
  boolean_T Face_Right_Driver;         /* '<S29>/Compare' */
  boolean_T Face_Left_Driver;          /* '<S31>/Compare' */
  boolean_T Face_Away_Driver;          /* '<S27>/Compare' */
  boolean_T Spline_Enable;             /* '<S9>/Merge7' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S13>/Merge4' */
  boolean_T RB_IsBlueActive;           /* '<S130>/Merge' */
  boolean_T RB_IsRedActive;            /* '<S130>/Merge1' */
  boolean_T RB_Logic_Score_In_Zone;    /* '<S173>/Merge' */
  boolean_T RB_Logic_Velocity;         /* '<S132>/GreaterThan' */
  boolean_T RB_Logic_Gyro_Angle;       /* '<S132>/Relational Operator' */
  boolean_T RB_Logic_Shooter_Speed;    /* '<S132>/Relational Operator1' */
  boolean_T RB_Logic_Hood_Pos;         /* '<S132>/Relational Operator4' */
  boolean_T RB_Ready_to_Score;         /* '<S132>/AND2' */
  boolean_T Is_Outside_Alliance_Zone;  /* '<S174>/Merge' */
  boolean_T RB_Logic_Outside_Zone;     /* '<S132>/Signal Copy' */
  boolean_T RB_Ready_to_Pass;          /* '<S132>/AND3' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S13>/Merge5' */
  boolean_T Swerve_Drive_Integral_Enable;/* '<S9>/Merge23' */
  boolean_T Robot_Reached_Destination; /* '<S13>/Merge7' */
  boolean_T Test_Mode;                 /* '<S9>/Merge10' */
  boolean_T Relative_Enable;           /* '<S409>/Logical Operator1' */
  boolean_T Steering_Abs_Angle_Active; /* '<S411>/AND6' */
  boolean_T Auto_Spline_Enable;        /* '<S20>/Chart' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S195>/Merge1' */
  boolean_T RB_Shooter_Active;       /* '<S12>/Shooter_Transfer_Feeder Chart' */
} B_Robot_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S33>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S34>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S35>/Delay Input1' */
  real_T FixPtUnitDelay1_DSTATE;       /* '<S41>/FixPt Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_a;     /* '<S44>/FixPt Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_j;     /* '<S47>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S7>/Unit Delay2' */
  real_T TappedDelay_X[2];             /* '<S8>/Tapped Delay' */
  real_T TappedDelay1_X[2];            /* '<S8>/Tapped Delay1' */
  real_T MemoryX_DSTATE[2];            /* '<S70>/MemoryX' */
  real_T UnitDelay_1_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_4_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_2_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S12>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S373>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S372>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S370>/Unit Delay' */
  real_T UnitDelay_DSTATE_d4;          /* '<S352>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_e;     /* '<S367>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S351>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_p;     /* '<S360>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S326>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S325>/UD' */
  real_T UnitDelay_DSTATE_lw;          /* '<S319>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S263>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S262>/UD' */
  real_T UnitDelay_DSTATE_j;           /* '<S256>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S274>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S273>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S259>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S284>/Unit Delay1' */
  real_T UD_DSTATE_m;                  /* '<S283>/UD' */
  real_T UnitDelay_DSTATE_h;           /* '<S277>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S295>/Unit Delay1' */
  real_T UD_DSTATE_i;                  /* '<S294>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S280>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n4;         /* '<S305>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S304>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S298>/Unit Delay' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S316>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S315>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S301>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S337>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S336>/UD' */
  real_T UnitDelay_DSTATE_lm;          /* '<S322>/Unit Delay' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S187>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S186>/UD' */
  real_T UnitDelay_DSTATE_kz;          /* '<S185>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g;          /* '<S68>/Unit Delay1' */
  real_T UD_DSTATE_jd;                 /* '<S67>/UD' */
  real_T UnitDelay_DSTATE_dl;          /* '<S66>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c;          /* '<S60>/Unit Delay1' */
  real_T UD_DSTATE_g;                  /* '<S59>/UD' */
  real_T UnitDelay_DSTATE_km;          /* '<S58>/Unit Delay' */
  real_T UnitDelay1_DSTATE_in;         /* '<S182>/Unit Delay1' */
  real_T UD_DSTATE_kz;                 /* '<S181>/UD' */
  real_T UnitDelay_DSTATE_l1;          /* '<S180>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S411>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_j2;         /* '<S411>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S425>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S425>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S429>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_iz[60];     /* '<S20>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_k;          /* '<S19>/Unit Delay1' */
  real_T UnitDelay_DSTATE_b;           /* '<S19>/Unit Delay' */
  real_T UnitDelay_DSTATE_e3;          /* '<S20>/Unit Delay' */
  real_T UnitDelay_DSTATE_gh;          /* '<S191>/Unit Delay' */
  real_T UnitDelay_DSTATE_hn;          /* '<S190>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f4;         /* '<S243>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g4;          /* '<S243>/Unit Delay' */
  real_T UnitDelay_DSTATE_le;          /* '<S193>/Unit Delay' */
  real_T UnitDelay1_DSTATE_kc;         /* '<S193>/Unit Delay1' */
  real_T UnitDelay_DSTATE_c;           /* '<S167>/Unit Delay' */
  real_T UnitDelay_DSTATE_lc;          /* '<S162>/Unit Delay' */
  real_T UnitDelay_DSTATE_bb;          /* '<S143>/Unit Delay' */
  real_T timer;                        /* '<S353>/Add dither' */
  void *MatrixConcatenate_PWORK;       /* '<S212>/Matrix Concatenate' */
  int32_T Selector5_DIMS1[2];          /* '<S212>/Selector5' */
  int32_T MatrixConcatenate_DIMS1[2];  /* '<S212>/Matrix Concatenate' */
  int32_T Selector4_DIMS1[2];          /* '<S212>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S41>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_j;    /* '<S44>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S47>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_o;    /* '<S350>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_p;    /* '<S367>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_cc;   /* '<S360>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_f;    /* '<S127>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S64>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S429>/FixPt Unit Delay2' */
  boolean_T UnitDelay_DSTATE_ll;       /* '<S7>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ki;       /* '<S135>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S53>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S50>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_ea;      /* '<S133>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_db;       /* '<S133>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ir;       /* '<S16>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S419>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S418>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S414>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S415>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S416>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g2;     /* '<S417>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE_l;       /* '<S411>/Unit Delay2' */
  boolean_T UnitDelay4_DSTATE;         /* '<S411>/Unit Delay4' */
  boolean_T DelayInput1_DSTATE_kb;     /* '<S25>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_e4;       /* '<S198>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_nu;       /* '<S203>/Unit Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S13>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S130>/If' */
  int8_T If_ActiveSubsystem_hk;        /* '<S195>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S198>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S200>/If' */
  uint8_T is_active_c6_Robot_Control;  /* '<S20>/Chart' */
  uint8_T is_c6_Robot_Control;         /* '<S20>/Chart' */
  uint8_T is_active_c7_Robot_Control;  /* '<S353>/Add dither' */
  uint8_T is_c7_Robot_Control;         /* '<S353>/Add dither' */
  uint8_T is_Dither;                   /* '<S353>/Add dither' */
  uint8_T is_active_c2_Robot_Control;/* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_c2_Robot_Control;       /* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_Shooting;               /* '<S12>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_active_c9_Robot_Control;  /* '<S11>/Chart' */
  uint8_T is_c9_Robot_Control;         /* '<S11>/Chart' */
  uint8_T is_active_c4_Robot_Control;  /* '<S6>/Chart' */
  uint8_T is_c4_Robot_Control;         /* '<S6>/Chart' */
  boolean_T icLoad;                    /* '<S70>/MemoryX' */
  boolean_T Relay_Mode;                /* '<S225>/Relay' */
  boolean_T EnabledSubsystem_MODE;     /* '<S97>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S90>/MeasurementUpdate' */
  DW_IfActionSubsystem2_Robot_C_T IfActionSubsystem4;/* '<S130>/If Action Subsystem4' */
  DW_IfActionSubsystem1_Robot_C_T IfActionSubsystem3;/* '<S130>/If Action Subsystem3' */
  DW_IfActionSubsystem2_Robot_C_T IfActionSubsystem2;/* '<S130>/If Action Subsystem2' */
  DW_IfActionSubsystem1_Robot_C_T IfActionSubsystem1;/* '<S130>/If Action Subsystem1' */
} DW_Robot_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S267>/Cos5' */
  const real_T Sin5;                   /* '<S267>/Sin5' */
  const real_T Cos5_g;                 /* '<S288>/Cos5' */
  const real_T Sin5_m;                 /* '<S288>/Sin5' */
  const real_T Cos5_i;                 /* '<S309>/Cos5' */
  const real_T Sin5_e;                 /* '<S309>/Sin5' */
  const real_T Cos5_b;                 /* '<S330>/Cos5' */
  const real_T Sin5_c;                 /* '<S330>/Sin5' */
  const real_T Width;                  /* '<S20>/Width' */
  const real_T Atan2;                  /* '<S340>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S340>/Add' */
  const real_T Atan1;                  /* '<S340>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S340>/Add1' */
  const real_T Atan3;                  /* '<S340>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S340>/Add2' */
  const real_T Atan4;                  /* '<S340>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S340>/Add3' */
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
  boolean_T IsBlueInactiveFirst;       /* '<Root>/IsBlueInactiveFirst' */
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
extern real_T Auto_Path_Chooser;       /* Variable: Auto_Path_Chooser
                                        * Referenced by: '<S21>/Constant17'
                                        */
extern real_T Auto_Shoot_Time;         /* Variable: Auto_Shoot_Time
                                        * Referenced by: '<S24>/Constant'
                                        */
extern real_T Boost_Trigger_Decreasing_Limit;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S426>/Constant1'
                                      */
extern real_T Boost_Trigger_High_Speed;/* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S422>/Constant'
                                        *   '<S422>/Saturation'
                                        */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S426>/Constant3'
                                      */
extern real_T Boost_Trigger_Low_Speed; /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S422>/Constant1'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S256>/Constant3'
                                        *   '<S277>/Constant3'
                                        *   '<S298>/Constant3'
                                        *   '<S319>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S256>/Constant2'
                                   *   '<S277>/Constant2'
                                   *   '<S298>/Constant2'
                                   *   '<S319>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S256>/Saturation'
                                        *   '<S277>/Saturation'
                                        *   '<S298>/Saturation'
                                        *   '<S319>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S256>/Saturation'
                                        *   '<S277>/Saturation'
                                        *   '<S298>/Saturation'
                                        *   '<S319>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S256>/Gain'
                                        *   '<S277>/Gain'
                                        *   '<S298>/Gain'
                                        *   '<S319>/Gain'
                                        */
extern real_T Drive_Motor_Control_I;   /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S256>/Gain2'
                                        *   '<S277>/Gain2'
                                        *   '<S298>/Gain2'
                                        *   '<S319>/Gain2'
                                        */
extern real_T Drive_Motor_Control_I_LL;/* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S256>/Saturation1'
                                        *   '<S277>/Saturation1'
                                        *   '<S298>/Saturation1'
                                        *   '<S319>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_I_UL;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S256>/Saturation1'
                                        *   '<S277>/Saturation1'
                                        *   '<S298>/Saturation1'
                                        *   '<S319>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S256>/Gain1'
                                        *   '<S277>/Gain1'
                                        *   '<S298>/Gain1'
                                        *   '<S319>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S261>/Constant'
                            *   '<S282>/Constant'
                            *   '<S303>/Constant'
                            *   '<S324>/Constant'
                            */
extern real_T Field_BlueAllianceZoneX; /* Variable: Field_BlueAllianceZoneX
                                        * Referenced by:
                                        *   '<S175>/BlueAllianceZoneX'
                                        *   '<S177>/BlueAllianceZoneX'
                                        */
extern real_T Field_Blue_Hub_X;        /* Variable: Field_Blue_Hub_X
                                        * Referenced by: '<S144>/Constant8'
                                        */
extern real_T Field_Blue_Pass_X;       /* Variable: Field_Blue_Pass_X
                                        * Referenced by: '<S144>/Blue_Top'
                                        */
extern real_T Field_Hub_Y;             /* Variable: Field_Hub_Y
                                        * Referenced by:
                                        *   '<S144>/Constant1'
                                        *   '<S144>/Switch3'
                                        */
extern real_T Field_Pass_Y_Bottom;     /* Variable: Field_Pass_Y_Bottom
                                        * Referenced by: '<S144>/Blue_Top2'
                                        */
extern real_T Field_Pass_Y_Top;        /* Variable: Field_Pass_Y_Top
                                        * Referenced by: '<S144>/Blue_Top3'
                                        */
extern real_T Field_RedAllianceZoneX;  /* Variable: Field_RedAllianceZoneX
                                        * Referenced by:
                                        *   '<S176>/RedAllianceZoneX'
                                        *   '<S178>/RedAllianceZoneX'
                                        */
extern real_T Field_Red_Hub_X;         /* Variable: Field_Red_Hub_X
                                        * Referenced by: '<S144>/Constant9'
                                        */
extern real_T Field_Red_Pass_X;        /* Variable: Field_Red_Pass_X
                                        * Referenced by: '<S144>/Blue_Top1'
                                        */
extern real_T Field_Translation_Control_Gain;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S412>/Gain2'
                                      */
extern real_T Field_Translation_Speed_Max;/* Variable: Field_Translation_Speed_Max
                                           * Referenced by: '<S412>/Constant5'
                                           */
extern real_T KF_Enable;               /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S8>/Constant2'
                                        */
extern real_T Rate_Limit_X;            /* Variable: Rate_Limit_X
                                        * Referenced by: '<S36>/Constant3'
                                        */
extern real_T Rate_Limit_Y;            /* Variable: Rate_Limit_Y
                                        * Referenced by: '<S37>/Constant3'
                                        */
extern real_T Rate_Limit_Z;            /* Variable: Rate_Limit_Z
                                        * Referenced by: '<S38>/Constant3'
                                        */
extern real_T Rebuilt_Des_Gyro_Shoot_Offset;
                                      /* Variable: Rebuilt_Des_Gyro_Shoot_Offset
                                       * Referenced by: '<S139>/Constant'
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
                                          *   '<S137>/Constant3'
                                          */
extern real_T Rebuilt_Hood_Servo_Rate_Limit_Dec;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Dec
                                   * Referenced by: '<S124>/Constant1'
                                   */
extern real_T Rebuilt_Hood_Servo_Rate_Limit_Inc;
                                  /* Variable: Rebuilt_Hood_Servo_Rate_Limit_Inc
                                   * Referenced by: '<S124>/Constant3'
                                   */
extern real_T Rebuilt_Intake_Arm_Gain_D;/* Variable: Rebuilt_Intake_Arm_Gain_D
                                         * Referenced by: '<S58>/Constant3'
                                         */
extern real_T Rebuilt_Intake_Arm_Gain_P;/* Variable: Rebuilt_Intake_Arm_Gain_P
                                         * Referenced by: '<S58>/Gain1'
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
                                           *   '<S54>/Constant'
                                           */
extern real_T Rebuilt_Intake_Des_Angle_Out;/* Variable: Rebuilt_Intake_Des_Angle_Out
                                            * Referenced by:
                                            *   '<S6>/Chart'
                                            *   '<S55>/Constant'
                                            */
extern real_T Rebuilt_Intake_Meas_In_Disable;
                                     /* Variable: Rebuilt_Intake_Meas_In_Disable
                                      * Referenced by: '<S56>/Constant'
                                      */
extern real_T Rebuilt_Intake_Meas_Out_Disable;
                                    /* Variable: Rebuilt_Intake_Meas_Out_Disable
                                     * Referenced by: '<S57>/Constant'
                                     */
extern real_T Rebuilt_Intake_RL_Dec;   /* Variable: Rebuilt_Intake_RL_Dec
                                        * Referenced by: '<S52>/Constant1'
                                        */
extern real_T Rebuilt_Intake_RL_Inc;   /* Variable: Rebuilt_Intake_RL_Inc
                                        * Referenced by: '<S52>/Constant3'
                                        */
extern real_T Rebuilt_Match_Time_Auto_Timer;
                                      /* Variable: Rebuilt_Match_Time_Auto_Timer
                                       * Referenced by: '<S162>/Unit Delay'
                                       */
extern real_T Rebuilt_Match_Time_End_Game_Timer;
                                  /* Variable: Rebuilt_Match_Time_End_Game_Timer
                                   * Referenced by: '<S167>/Unit Delay'
                                   */
extern real_T Rebuilt_Match_Time_Shift_1;/* Variable: Rebuilt_Match_Time_Shift_1
                                          * Referenced by: '<S158>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_2;/* Variable: Rebuilt_Match_Time_Shift_2
                                          * Referenced by: '<S159>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_3;/* Variable: Rebuilt_Match_Time_Shift_3
                                          * Referenced by: '<S160>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_4;/* Variable: Rebuilt_Match_Time_Shift_4
                                          * Referenced by: '<S161>/Constant'
                                          */
extern real_T Rebuilt_Match_Time_Shift_Timer;
                                     /* Variable: Rebuilt_Match_Time_Shift_Timer
                                      * Referenced by:
                                      *   '<S163>/Unit Delay'
                                      *   '<S164>/Unit Delay'
                                      *   '<S165>/Unit Delay'
                                      *   '<S166>/Unit Delay'
                                      */
extern real_T Rebuilt_Match_Time_Shoot_Early;
                                     /* Variable: Rebuilt_Match_Time_Shoot_Early
                                      * Referenced by:
                                      *   '<S168>/Constant'
                                      *   '<S169>/Constant'
                                      *   '<S170>/Constant'
                                      *   '<S171>/Constant'
                                      */
extern real_T Rebuilt_Match_Time_TeleOp;/* Variable: Rebuilt_Match_Time_TeleOp
                                         * Referenced by: '<S130>/Constant'
                                         */
extern real_T Rebuilt_Match_Time_Transition;
                                      /* Variable: Rebuilt_Match_Time_Transition
                                       * Referenced by: '<S156>/Constant'
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
                                * Referenced by: '<S53>/Constant1'
                                */
extern real_T Rebuilt_Roller_Motor_Gain_FF;/* Variable: Rebuilt_Roller_Motor_Gain_FF
                                            * Referenced by: '<S66>/Gain'
                                            */
extern real_T Rebuilt_Roller_Motor_Gain_I;/* Variable: Rebuilt_Roller_Motor_Gain_I
                                           * Referenced by: '<S66>/Gain2'
                                           */
extern real_T Rebuilt_Roller_Motor_Gain_P;/* Variable: Rebuilt_Roller_Motor_Gain_P
                                           * Referenced by: '<S66>/Gain1'
                                           */
extern real_T Rebuilt_Shoot_Dist_0;    /* Variable: Rebuilt_Shoot_Dist_0
                                        * Referenced by: '<S145>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Dist_1;    /* Variable: Rebuilt_Shoot_Dist_1
                                        * Referenced by: '<S145>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Dist_2;    /* Variable: Rebuilt_Shoot_Dist_2
                                        * Referenced by: '<S145>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Dist_3;    /* Variable: Rebuilt_Shoot_Dist_3
                                        * Referenced by: '<S145>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Dist_4;    /* Variable: Rebuilt_Shoot_Dist_4
                                        * Referenced by: '<S145>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Dist_5;    /* Variable: Rebuilt_Shoot_Dist_5
                                        * Referenced by: '<S145>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Dist_6;    /* Variable: Rebuilt_Shoot_Dist_6
                                        * Referenced by: '<S145>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Dist_7;    /* Variable: Rebuilt_Shoot_Dist_7
                                        * Referenced by: '<S145>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_0;/* Variable: Rebuilt_Shoot_Gyro_Err_0
                                        * Referenced by: '<S141>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_1;/* Variable: Rebuilt_Shoot_Gyro_Err_1
                                        * Referenced by: '<S141>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_2;/* Variable: Rebuilt_Shoot_Gyro_Err_2
                                        * Referenced by: '<S141>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_3;/* Variable: Rebuilt_Shoot_Gyro_Err_3
                                        * Referenced by: '<S141>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_4;/* Variable: Rebuilt_Shoot_Gyro_Err_4
                                        * Referenced by: '<S141>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_5;/* Variable: Rebuilt_Shoot_Gyro_Err_5
                                        * Referenced by: '<S141>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_6;/* Variable: Rebuilt_Shoot_Gyro_Err_6
                                        * Referenced by: '<S141>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Gyro_Err_7;/* Variable: Rebuilt_Shoot_Gyro_Err_7
                                        * Referenced by: '<S141>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_0;/* Variable: Rebuilt_Shoot_Hood_Pos_0
                                        * Referenced by: '<S142>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_1;/* Variable: Rebuilt_Shoot_Hood_Pos_1
                                        * Referenced by: '<S142>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_2;/* Variable: Rebuilt_Shoot_Hood_Pos_2
                                        * Referenced by: '<S142>/Constant7'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_3;/* Variable: Rebuilt_Shoot_Hood_Pos_3
                                        * Referenced by: '<S142>/Constant8'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_4;/* Variable: Rebuilt_Shoot_Hood_Pos_4
                                        * Referenced by: '<S142>/Constant9'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_5;/* Variable: Rebuilt_Shoot_Hood_Pos_5
                                        * Referenced by: '<S142>/Constant10'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_6;/* Variable: Rebuilt_Shoot_Hood_Pos_6
                                        * Referenced by: '<S142>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_7;/* Variable: Rebuilt_Shoot_Hood_Pos_7
                                        * Referenced by: '<S142>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_Hood_Pos_Max_Error;
                                   /* Variable: Rebuilt_Shoot_Hood_Pos_Max_Error
                                    * Referenced by: '<S132>/Constant1'
                                    */
extern real_T Rebuilt_Shoot_Motor_Max_Error;
                                      /* Variable: Rebuilt_Shoot_Motor_Max_Error
                                       * Referenced by: '<S132>/Constant2'
                                       */
extern real_T Rebuilt_Shoot_Robot_Velocity_Max;
                                   /* Variable: Rebuilt_Shoot_Robot_Velocity_Max
                                    * Referenced by: '<S132>/Constant'
                                    */
extern real_T Rebuilt_Shoot_Shooter_Spd_0;/* Variable: Rebuilt_Shoot_Shooter_Spd_0
                                           * Referenced by: '<S155>/Constant5'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_1;/* Variable: Rebuilt_Shoot_Shooter_Spd_1
                                           * Referenced by: '<S155>/Constant6'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_2;/* Variable: Rebuilt_Shoot_Shooter_Spd_2
                                           * Referenced by: '<S155>/Constant7'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_3;/* Variable: Rebuilt_Shoot_Shooter_Spd_3
                                           * Referenced by: '<S155>/Constant8'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_4;/* Variable: Rebuilt_Shoot_Shooter_Spd_4
                                           * Referenced by: '<S155>/Constant9'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_5;/* Variable: Rebuilt_Shoot_Shooter_Spd_5
                                           * Referenced by: '<S155>/Constant10'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_6;/* Variable: Rebuilt_Shoot_Shooter_Spd_6
                                           * Referenced by: '<S155>/Constant2'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_7;/* Variable: Rebuilt_Shoot_Shooter_Spd_7
                                           * Referenced by: '<S155>/Constant1'
                                           */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_0;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_0
                                       * Referenced by: '<S154>/Constant5'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_1;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_1
                                       * Referenced by: '<S154>/Constant6'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_2;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_2
                                       * Referenced by: '<S154>/Constant7'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_3;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_3
                                       * Referenced by: '<S154>/Constant8'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_4;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_4
                                       * Referenced by: '<S154>/Constant9'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_5;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_5
                                       * Referenced by: '<S154>/Constant10'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_6;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_6
                                       * Referenced by: '<S154>/Constant2'
                                       */
extern real_T Rebuilt_Shoot_Shooter_Spd_I_7;
                                      /* Variable: Rebuilt_Shoot_Shooter_Spd_I_7
                                       * Referenced by: '<S154>/Constant1'
                                       */
extern real_T Rebuilt_Shoot_TOF_0;     /* Variable: Rebuilt_Shoot_TOF_0
                                        * Referenced by: '<S148>/Constant'
                                        */
extern real_T Rebuilt_Shoot_TOF_1;     /* Variable: Rebuilt_Shoot_TOF_1
                                        * Referenced by: '<S148>/Constant1'
                                        */
extern real_T Rebuilt_Shoot_TOF_2;     /* Variable: Rebuilt_Shoot_TOF_2
                                        * Referenced by: '<S148>/Constant2'
                                        */
extern real_T Rebuilt_Shoot_TOF_3;     /* Variable: Rebuilt_Shoot_TOF_3
                                        * Referenced by: '<S148>/Constant3'
                                        */
extern real_T Rebuilt_Shoot_TOF_4;     /* Variable: Rebuilt_Shoot_TOF_4
                                        * Referenced by: '<S148>/Constant4'
                                        */
extern real_T Rebuilt_Shoot_TOF_5;     /* Variable: Rebuilt_Shoot_TOF_5
                                        * Referenced by: '<S148>/Constant11'
                                        */
extern real_T Rebuilt_Shoot_TOF_6;     /* Variable: Rebuilt_Shoot_TOF_6
                                        * Referenced by: '<S148>/Constant6'
                                        */
extern real_T Rebuilt_Shoot_TOF_7;     /* Variable: Rebuilt_Shoot_TOF_7
                                        * Referenced by: '<S148>/Constant5'
                                        */
extern real_T Rebuilt_Shoot_Target_Error_Thresh;
                                  /* Variable: Rebuilt_Shoot_Target_Error_Thresh
                                   * Referenced by: '<S152>/Constant'
                                   */
extern real_T Rebuilt_Shooter_Error_Integral_Enable;
                              /* Variable: Rebuilt_Shooter_Error_Integral_Enable
                               * Referenced by: '<S133>/Constant1'
                               */
extern real_T Rebuilt_Shooter_Motor_Gain_FF;
                                      /* Variable: Rebuilt_Shooter_Motor_Gain_FF
                                       * Referenced by: '<S180>/Gain'
                                       */
extern real_T Rebuilt_Shooter_Motor_Gain_I;/* Variable: Rebuilt_Shooter_Motor_Gain_I
                                            * Referenced by: '<S180>/Gain2'
                                            */
extern real_T Rebuilt_Shooter_Motor_Gain_P;/* Variable: Rebuilt_Shooter_Motor_Gain_P
                                            * Referenced by: '<S180>/Gain1'
                                            */
extern real_T Rebuilt_Shot_Init_Time;  /* Variable: Rebuilt_Shot_Init_Time
                                        * Referenced by: '<S143>/Constant2'
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
                              * Referenced by: '<S135>/Constant1'
                              */
extern real_T Rebuilt_Transfer_Minimum_Factor;
                                    /* Variable: Rebuilt_Transfer_Minimum_Factor
                                     * Referenced by: '<S12>/Shooter_Transfer_Feeder Chart'
                                     */
extern real_T Rebuilt_Transfer_Motor_Gain_FF;
                                     /* Variable: Rebuilt_Transfer_Motor_Gain_FF
                                      * Referenced by: '<S185>/Gain'
                                      */
extern real_T Rebuilt_Transfer_Motor_Gain_I;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_I
                                       * Referenced by: '<S185>/Gain2'
                                       */
extern real_T Rebuilt_Transfer_Motor_Gain_P;
                                      /* Variable: Rebuilt_Transfer_Motor_Gain_P
                                       * Referenced by: '<S185>/Gain1'
                                       */
extern real_T Relative_Steering_Error_Angle_Gain;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S411>/Constant4'
                                  */
extern real_T Relative_Steering_Error_Angle_Gain_Object_Factor;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S409>/Gain'
                    */
extern real_T Relative_Steering_Speed_Max;/* Variable: Relative_Steering_Speed_Max
                                           * Referenced by: '<S411>/Constant10'
                                           */
extern real_T Relative_Translation_Control_Gain;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S412>/Gain1'
                                   */
extern real_T Relative_Translation_Speed_Max;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S412>/Constant8'
                                      */
extern real_T Spline_Last_Pose_Distance_to_Velocity_Gain;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S245>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S245>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S192>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S205>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S245>/Constant3'
                                     */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S352>/Constant5'
                    */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S352>/Constant6'
                    */
extern real_T Steering_Absolute_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S352>/Constant9'
                          */
extern real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S352>/Constant10'
                    */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S352>/Constant1'
                                */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S352>/Constant3'
                                */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S370>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S370>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S370>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S370>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S369>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S370>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S370>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S370>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S370>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S370>/Constant1'
                                   *   '<S370>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S370>/Constant'
                                   *   '<S370>/Saturation2'
                                   */
extern real_T Steering_Heading_Dither_Gain;/* Variable: Steering_Heading_Dither_Gain
                                            * Referenced by: '<S353>/Add dither'
                                            */
extern real_T Steering_Heading_Dither_Period;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S353>/Add dither'
                                      */
extern real_T Steering_Heading_Dither_Thresh_Off;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S353>/Add dither'
                                  */
extern real_T Steering_Heading_Dither_Thresh_On;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S353>/Add dither'
                                   */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S259>/Constant3'
                                        *   '<S280>/Constant3'
                                        *   '<S301>/Constant3'
                                        *   '<S322>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S259>/Constant2'
                                *   '<S280>/Constant2'
                                *   '<S301>/Constant2'
                                *   '<S322>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S259>/Saturation'
                                           *   '<S280>/Saturation'
                                           *   '<S301>/Saturation'
                                           *   '<S322>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S259>/Saturation'
                                           *   '<S280>/Saturation'
                                           *   '<S301>/Saturation'
                                           *   '<S322>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S259>/Gain2'
                                        *   '<S280>/Gain2'
                                        *   '<S301>/Gain2'
                                        *   '<S322>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S259>/Saturation1'
                                           *   '<S280>/Saturation1'
                                           *   '<S301>/Saturation1'
                                           *   '<S322>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S259>/Saturation1'
                                           *   '<S280>/Saturation1'
                                           *   '<S301>/Saturation1'
                                           *   '<S322>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S259>/Gain1'
                                        *   '<S280>/Gain1'
                                        *   '<S301>/Gain1'
                                        *   '<S322>/Gain1'
                                        */
extern real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S351>/Constant5'
                    */
extern real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S351>/Constant6'
                    */
extern real_T Steering_Relative_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S351>/Constant9'
                          */
extern real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S351>/Constant10'
                    */
extern real_T Steering_Relative_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S351>/Constant1'
                                */
extern real_T Steering_Relative_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S351>/Constant3'
                                */
extern real_T Steering_Relative_Gain;  /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S411>/Constant'
                                        */
extern real_T Steering_Twist_Gain;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S411>/Constant1'
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
                                      * Referenced by: '<S410>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Steering;/* Variable: TEST_Swerve_Mode_Steering
                                         * Referenced by: '<S410>/Constant8'
                                         */
extern real_T TEST_Swerve_Mode_Translation;/* Variable: TEST_Swerve_Mode_Translation
                                            * Referenced by: '<S410>/Constant7'
                                            */
extern real_T TEST_Transfer_Motor_DC_OV;/* Variable: TEST_Transfer_Motor_DC_OV
                                         * Referenced by: '<S10>/Constant1'
                                         */
extern real_T Translation_Speed_Approach_Zero_Error_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S339>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S339>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S339>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S339>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S339>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S339>/Constant3'
                                    */
extern real_T Translation_Twist_Gain;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S412>/Gain'
                                        */
extern real_T Twist_Deadzone_neg;      /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S411>/Dead Zone'
                                        *   '<S412>/Dead Zone'
                                        */
extern real_T Twist_Deadzone_pos;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S411>/Dead Zone'
                                        *   '<S412>/Dead Zone'
                                        */
extern real_T Vision_Object_Angle_Offset;/* Variable: Vision_Object_Angle_Offset
                                          * Referenced by: '<S17>/Constant6'
                                          */
extern real_T Vision_Object_Target_Angle;/* Variable: Vision_Object_Target_Angle
                                          * Referenced by: '<S409>/Constant7'
                                          */
extern real_T Vision_Object_Target_X;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S409>/Constant1'
                                        */
extern real_T Vision_Object_Target_Y;  /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S409>/Constant4'
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
                                        * Referenced by: '<S409>/Constant8'
                                        */
extern real_T Vision_Tag_Target_X;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S409>/Constant2'
                                        */
extern real_T Vision_Tag_Target_Y;     /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S409>/Constant5'
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
                                        *   '<S409>/Constant11'
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
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Propagation' : Unused code path elimination
 * Block '<S41>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Propagation' : Unused code path elimination
 * Block '<S44>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Propagation' : Unused code path elimination
 * Block '<S47>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Propagation' : Unused code path elimination
 * Block '<S58>/Scope' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Propagation' : Unused code path elimination
 * Block '<S64>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Propagation' : Unused code path elimination
 * Block '<S66>/Scope' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 * Block '<S114>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Conversion' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Conversion' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/G' : Unused code path elimination
 * Block '<S70>/H' : Unused code path elimination
 * Block '<S70>/N' : Unused code path elimination
 * Block '<S70>/P0' : Unused code path elimination
 * Block '<S70>/Q' : Unused code path elimination
 * Block '<S70>/R' : Unused code path elimination
 * Block '<S102>/CheckSignalProperties' : Unused code path elimination
 * Block '<S111>/CheckSignalProperties' : Unused code path elimination
 * Block '<S112>/CheckSignalProperties' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Propagation' : Unused code path elimination
 * Block '<S127>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S11>/Unit Delay1' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Propagation' : Unused code path elimination
 * Block '<S180>/Scope' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/Data Type Propagation' : Unused code path elimination
 * Block '<S185>/Scope' : Unused code path elimination
 * Block '<S204>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S208>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S248>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S264>/Data Type Duplicate' : Unused code path elimination
 * Block '<S264>/Data Type Propagation' : Unused code path elimination
 * Block '<S256>/Scope' : Unused code path elimination
 * Block '<S258>/Scope' : Unused code path elimination
 * Block '<S275>/Data Type Duplicate' : Unused code path elimination
 * Block '<S275>/Data Type Propagation' : Unused code path elimination
 * Block '<S259>/Scope' : Unused code path elimination
 * Block '<S285>/Data Type Duplicate' : Unused code path elimination
 * Block '<S285>/Data Type Propagation' : Unused code path elimination
 * Block '<S277>/Scope' : Unused code path elimination
 * Block '<S279>/Scope' : Unused code path elimination
 * Block '<S296>/Data Type Duplicate' : Unused code path elimination
 * Block '<S296>/Data Type Propagation' : Unused code path elimination
 * Block '<S280>/Scope' : Unused code path elimination
 * Block '<S306>/Data Type Duplicate' : Unused code path elimination
 * Block '<S306>/Data Type Propagation' : Unused code path elimination
 * Block '<S298>/Scope' : Unused code path elimination
 * Block '<S300>/Scope' : Unused code path elimination
 * Block '<S317>/Data Type Duplicate' : Unused code path elimination
 * Block '<S317>/Data Type Propagation' : Unused code path elimination
 * Block '<S301>/Scope' : Unused code path elimination
 * Block '<S327>/Data Type Duplicate' : Unused code path elimination
 * Block '<S327>/Data Type Propagation' : Unused code path elimination
 * Block '<S319>/Scope' : Unused code path elimination
 * Block '<S321>/Scope' : Unused code path elimination
 * Block '<S338>/Data Type Duplicate' : Unused code path elimination
 * Block '<S338>/Data Type Propagation' : Unused code path elimination
 * Block '<S322>/Scope' : Unused code path elimination
 * Block '<S349>/Data Type Duplicate' : Unused code path elimination
 * Block '<S349>/Data Type Propagation' : Unused code path elimination
 * Block '<S350>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S359>/Data Type Duplicate' : Unused code path elimination
 * Block '<S359>/Data Type Propagation' : Unused code path elimination
 * Block '<S360>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S366>/Data Type Duplicate' : Unused code path elimination
 * Block '<S366>/Data Type Propagation' : Unused code path elimination
 * Block '<S367>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S375>/Data Type Duplicate' : Unused code path elimination
 * Block '<S375>/Data Type Propagation' : Unused code path elimination
 * Block '<S370>/Scope' : Unused code path elimination
 * Block '<S421>/Data Type Duplicate' : Unused code path elimination
 * Block '<S421>/Data Type Propagation' : Unused code path elimination
 * Block '<S428>/Data Type Duplicate' : Unused code path elimination
 * Block '<S428>/Data Type Propagation' : Unused code path elimination
 * Block '<S429>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S3>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S113>/Conversion' : Eliminate redundant data type conversion
 * Block '<S114>/Conversion' : Eliminate redundant data type conversion
 * Block '<S116>/Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S86>/Conversion' : Eliminate redundant data type conversion
 * Block '<S90>/Reshape' : Reshape block reduction
 * Block '<S70>/ReshapeX0' : Reshape block reduction
 * Block '<S70>/Reshapexhat' : Reshape block reduction
 * Block '<S8>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S8>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S12>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S12>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S12>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S244>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S409>/Constant10' : Unused code path elimination
 * Block '<S409>/Constant9' : Unused code path elimination
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
 * '<S25>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic/Detect Increase'
 * '<S26>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Autonomous Paths and Actions/Chart'
 * '<S27>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant1'
 * '<S28>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant5'
 * '<S29>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant6'
 * '<S30>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant7'
 * '<S31>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant8'
 * '<S32>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero17'
 * '<S33>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase'
 * '<S34>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase1'
 * '<S35>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase2'
 * '<S36>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit'
 * '<S37>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1'
 * '<S38>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2'
 * '<S39>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter'
 * '<S40>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S41>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S42>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter'
 * '<S43>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S44>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S45>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter'
 * '<S46>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter/Saturation Dynamic'
 * '<S47>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Rate Limit2/Discrete Rate Limiter/Unit Delay External IC'
 * '<S48>'  : 'Robot_Control/Control_System/Intake Controls/Angle Modulus Broken Library Link for Degrees'
 * '<S49>'  : 'Robot_Control/Control_System/Intake Controls/Chart'
 * '<S50>'  : 'Robot_Control/Control_System/Intake Controls/Detect Decrease'
 * '<S51>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control'
 * '<S52>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit'
 * '<S53>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control'
 * '<S54>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant'
 * '<S55>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant1'
 * '<S56>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant2'
 * '<S57>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Compare To Constant3'
 * '<S58>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID'
 * '<S59>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Difference'
 * '<S60>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Low_Pass_Filter'
 * '<S61>'  : 'Robot_Control/Control_System/Intake Controls/Intake Arm Closed Loop Control/Feed Forward plus PID/Saturation Dynamic'
 * '<S62>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter'
 * '<S63>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S64>'  : 'Robot_Control/Control_System/Intake Controls/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S65>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Compare To Zero'
 * '<S66>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S67>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S68>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S69>'  : 'Robot_Control/Control_System/Intake Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S70>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter'
 * '<S71>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL'
 * '<S72>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat'
 * '<S73>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator'
 * '<S74>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionA'
 * '<S75>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionB'
 * '<S76>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionC'
 * '<S77>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionD'
 * '<S78>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionG'
 * '<S79>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionH'
 * '<S80>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionN'
 * '<S81>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP'
 * '<S82>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP0'
 * '<S83>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionQ'
 * '<S84>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionR'
 * '<S85>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionReset'
 * '<S86>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX'
 * '<S87>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX0'
 * '<S88>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionu'
 * '<S89>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/MemoryP'
 * '<S90>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer'
 * '<S91>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN'
 * '<S92>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reset'
 * '<S93>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reshapeyhat'
 * '<S94>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionP0'
 * '<S95>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionQ'
 * '<S96>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionR'
 * '<S97>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator'
 * '<S98>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkA'
 * '<S99>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkB'
 * '<S100>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkC'
 * '<S101>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkD'
 * '<S102>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkEnable'
 * '<S103>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkG'
 * '<S104>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkH'
 * '<S105>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkN'
 * '<S106>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkP0'
 * '<S107>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkQ'
 * '<S108>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkR'
 * '<S109>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkReset'
 * '<S110>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkX0'
 * '<S111>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checku'
 * '<S112>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checky'
 * '<S113>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S114>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S115>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S116>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S117>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/Ground'
 * '<S118>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat/Ground'
 * '<S119>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S120>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S121>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer/MeasurementUpdate'
 * '<S122>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN/Ground'
 * '<S123>' : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S124>' : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo'
 * '<S125>' : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter'
 * '<S126>' : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter/Saturation Dynamic'
 * '<S127>' : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter/Unit Delay External IC'
 * '<S128>' : 'Robot_Control/Control_System/Previous GameState/Chart'
 * '<S129>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings'
 * '<S130>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring'
 * '<S131>' : 'Robot_Control/Control_System/Shooter Controls/Maximum of measured shooter motor speeds'
 * '<S132>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot'
 * '<S133>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control'
 * '<S134>' : 'Robot_Control/Control_System/Shooter Controls/Shooter_Transfer_Feeder Chart'
 * '<S135>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control'
 * '<S136>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math'
 * '<S137>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Shooter Not Active'
 * '<S138>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters'
 * '<S139>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Desired Gyro Angle Calculation'
 * '<S140>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target'
 * '<S141>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error'
 * '<S142>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Hood Position'
 * '<S143>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed'
 * '<S144>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Shot_Coordinate_Selection'
 * '<S145>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Subsystem'
 * '<S146>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Desired Gyro Angle Calculation/Degrees to Radians'
 * '<S147>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Calculate Shot Distance'
 * '<S148>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Shot Distance to TOF'
 * '<S149>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Target_Selection'
 * '<S150>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position'
 * '<S151>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check'
 * '<S152>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check/Compare To Constant'
 * '<S153>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error/Degrees to Radians'
 * '<S154>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed/Rebuilt_Shoot_Shooter_Spd Init Array'
 * '<S155>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed/Rebuilt_Shoot_Shooter_Spd Steady State Array'
 * '<S156>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/ '
 * '<S157>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/ 1'
 * '<S158>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant1'
 * '<S159>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant2'
 * '<S160>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant3'
 * '<S161>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/Compare To Constant4'
 * '<S162>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem'
 * '<S163>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem1'
 * '<S164>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem2'
 * '<S165>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem3'
 * '<S166>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem4'
 * '<S167>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem5'
 * '<S168>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem1/Compare To Constant'
 * '<S169>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem2/Compare To Constant'
 * '<S170>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem3/Compare To Constant'
 * '<S171>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem4/Compare To Constant'
 * '<S172>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Angle Modulus'
 * '<S173>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone'
 * '<S174>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone'
 * '<S175>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone/Blue'
 * '<S176>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if allowed to score in alliance zone/Red'
 * '<S177>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone/Blue'
 * '<S178>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Check if outside alliance zone/Red'
 * '<S179>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Compare To Zero'
 * '<S180>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S181>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S182>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S183>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S184>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Compare To Zero'
 * '<S185>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S186>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S187>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S188>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S189>' : 'Robot_Control/Control_System/Spline_Path_Following/Pass Through'
 * '<S190>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled'
 * '<S191>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S192>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S193>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S194>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S195>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S196>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S197>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S198>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S199>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S200>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S201>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S202>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S203>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S204>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S205>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S206>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S207>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S208>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S209>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S210>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S211>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S212>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S213>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S214>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S215>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S216>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S217>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S218>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S219>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S220>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S221>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S222>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S223>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S224>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S225>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S226>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S227>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S228>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S229>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S230>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S231>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S232>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S233>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S234>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S235>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S236>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S237>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S238>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S239>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S240>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S241>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S242>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S243>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S244>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S245>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S246>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S247>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S248>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S249>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S250>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module'
 * '<S251>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1'
 * '<S252>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2'
 * '<S253>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3'
 * '<S254>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S255>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S256>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable'
 * '<S257>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S258>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S259>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S260>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S261>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S262>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Difference'
 * '<S263>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S264>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S265>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S266>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S267>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S268>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S269>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S270>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S271>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S272>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S273>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S274>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S275>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S276>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S277>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable'
 * '<S278>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S279>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S280>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S281>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S282>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S283>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Difference'
 * '<S284>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S285>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S286>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S287>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S288>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S289>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S290>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S291>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S292>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S293>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S294>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S295>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S296>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S297>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S298>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable'
 * '<S299>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S300>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S301>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S302>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S303>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S304>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Difference'
 * '<S305>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S306>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S307>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S308>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S309>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S310>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S311>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S312>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S313>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S314>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S315>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S316>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S317>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S318>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S319>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable'
 * '<S320>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S321>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S322>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S323>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S324>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S325>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Difference'
 * '<S326>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S327>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S328>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S329>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S330>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S331>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S332>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S333>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S334>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S335>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S336>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S337>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S338>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S339>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S340>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S341>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S342>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S343>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S344>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S345>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S346>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S347>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S348>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S349>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S350>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S351>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S352>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1'
 * '<S353>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S354>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S355>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S356>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S357>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S358>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S359>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S360>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S361>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero'
 * '<S362>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero1'
 * '<S363>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero2'
 * '<S364>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero3'
 * '<S365>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter'
 * '<S366>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S367>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S368>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Add dither'
 * '<S369>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S370>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S371>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S372>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S373>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S374>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Radians to Degrees'
 * '<S375>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S376>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S377>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Reduce Speeds for Maximum Speed Limit'
 * '<S378>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S379>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S380>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S381>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S382>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S383>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S384>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S385>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S386>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S387>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S388>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S389>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S390>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S391>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S392>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S393>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S394>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S395>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S396>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S397>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S398>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S399>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S400>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S401>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S402>' : 'Robot_Control/Control_System/Teleop/Compare To Zero'
 * '<S403>' : 'Robot_Control/Control_System/Teleop/Compare To Zero1'
 * '<S404>' : 'Robot_Control/Control_System/Teleop/Compare To Zero2'
 * '<S405>' : 'Robot_Control/Control_System/Teleop/Compare To Zero3'
 * '<S406>' : 'Robot_Control/Control_System/Teleop/Compare To Zero4'
 * '<S407>' : 'Robot_Control/Control_System/Teleop/Compare To Zero5'
 * '<S408>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S409>' : 'Robot_Control/Control_System/Teleop/Relative Errors'
 * '<S410>' : 'Robot_Control/Control_System/Teleop/Subsystem'
 * '<S411>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S412>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S413>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Compare To Zero2'
 * '<S414>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase'
 * '<S415>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase1'
 * '<S416>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase2'
 * '<S417>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase3'
 * '<S418>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase4'
 * '<S419>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase5'
 * '<S420>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Previous active game state was not Teleop'
 * '<S421>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Saturation Dynamic'
 * '<S422>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S423>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero'
 * '<S424>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero1'
 * '<S425>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S426>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S427>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S428>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S429>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S430>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S431>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S432>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant'
 * '<S433>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant1'
 * '<S434>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant2'
 * '<S435>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero6'
 * '<S436>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero7'
 * '<S437>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero8'
 * '<S438>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance'
 * '<S439>' : 'Robot_Control/Control_System/Vision_Corrections/Degrees to Radians'
 * '<S440>' : 'Robot_Control/Control_System/Vision_Corrections/Polar to Cartesian1'
 * '<S441>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Prevent raising 0 to a negative exponent'
 * '<S442>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Subsystem'
 */
#endif                                 /* RTW_HEADER_Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
