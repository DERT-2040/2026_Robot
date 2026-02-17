/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.445
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 16 22:23:43 2026
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
  real_T Drive_Joystick_X;             /* '<S4>/Signal Copy1' */
  real_T Drive_Joystick_Y;             /* '<S4>/Signal Copy2' */
  real_T Drive_Joystick_Z;             /* '<S4>/Signal Copy3' */
  real_T Steer_Joystick_Y;             /* '<S4>/Signal Copy5' */
  real_T Steer_Joystick_Z;             /* '<S4>/Signal Copy6' */
  real_T Vision_c1_AprilTag_Corr_X_inch;/* '<S15>/Add' */
  real_T Vision_c1_AprilTag_Corr_Y_inch;/* '<S15>/Add1' */
  real_T Vision_c1_AprilTag_Corr_Yaw_deg;/* '<S15>/Add2' */
  real_T Vision_c1_Object_Corr_X_inch; /* '<S15>/Add3' */
  real_T Vision_c1_Object_Corr_Y_inch; /* '<S15>/Add4' */
  real_T Vision_c1_Object_Corr_Yaw_deg;/* '<S15>/Add5' */
  real_T KF_Position_X;                /* '<S6>/Switch' */
  real_T KF_Position_Y;                /* '<S6>/Switch1' */
  real_T Spline_Num_Poses;             /* '<S7>/Merge9' */
  real_T Measured_Shooter_Speed_Max;   /* '<S90>/Max' */
  real_T Steering_Abs_Cmd;             /* '<S7>/Merge1' */
  real_T Desired_Gyro_Angle;           /* '<S85>/Merge' */
  real_T Steering_Rel_Cmd;             /* '<S7>/Merge2' */
  real_T Translation_Speed;            /* '<S7>/Merge4' */
  real_T Translation_Angle;            /* '<S7>/Merge3' */
  real_T Translation_Speed_SPF;        /* '<S11>/Merge2' */
  real_T Translation_Speed_RL;         /* '<S288>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S11>/Merge3' */
  real_T Gyro_Angle_SPF;               /* '<S11>/Merge8' */
  real_T Translation_Steering_Cmd;     /* '<S282>/Switch' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S11>/Merge' */
  real_T Steering_Localized_PID;       /* '<S309>/Saturation2' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S11>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S281>/Switch' */
  real_T BR_Desired_Wheel_Speed_in;    /* '<S335>/Switch1' */
  real_T FL_Desired_Wheel_Speed_in;    /* '<S320>/Switch1' */
  real_T FR_Desired_Wheel_Speed_in;    /* '<S325>/Switch1' */
  real_T BL_Desired_Wheel_Speed_in;    /* '<S330>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S315>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S335>/Switch' */
  real_T FL_Desired_Module_Angle;      /* '<S320>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S315>/Product' */
  real_T FR_Desired_Module_Angle;      /* '<S325>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S315>/Product1' */
  real_T BL_Desired_Module_Angle;      /* '<S330>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S315>/Product2' */
  real_T Transfer_Motor_PID_DC;        /* '<S125>/Saturation2' */
  real_T Feeder_Motor_PID_DC;          /* '<S10>/Product' */
  real_T Desired_Hood_Pos_Shoot;       /* '<S85>/Merge2' */
  real_T Estimated_Hood_Pos;           /* '<S81>/Sum' */
  real_T Desired_Shooter_Speed;        /* '<S85>/Merge1' */
  real_T Shooter_Motor_PID_DC;         /* '<S120>/Saturation2' */
  real_T Allowed_Shoot_Gyro_Error;     /* '<S85>/Merge3' */
  real_T loop_counter_robot_control;   /* '<S1>/Sum' */
  real_T Steer_Joystick_X;             /* '<S4>/Signal Copy4' */
  real_T Feeder_Motor_Speed_tp;        /* '<Root>/Signal Copy' */
  real_T Relative_Error_Angle;         /* '<S341>/Switch4' */
  real_T Steering_Abs_Gyro_Latch;      /* '<S343>/Switch8' */
  real_T Steering_Abs_Gyro;            /* '<S343>/Switch2' */
  real_T Steering_Abs_Angle;           /* '<S343>/Switch3' */
  real_T Relative_Error_Y;             /* '<S341>/Switch2' */
  real_T Relative_Error_X;             /* '<S341>/Unary Minus1' */
  real_T Spline_Follow_Index;          /* '<S135>/Merge4' */
  real_T Spline_Target_Y;              /* '<S132>/Selector6' */
  real_T Spline_Target_X;              /* '<S132>/Selector2' */
  real_T Desired_Feeder_Speed;       /* '<S10>/Shooter_Transfer_Feeder Chart' */
  real_T Desired_Transfer_Speed;     /* '<S10>/Shooter_Transfer_Feeder Chart' */
  real_T Target_X;                     /* '<S100>/Switch' */
  real_T Target_Y;                     /* '<S100>/Switch1' */
  real_T Allowed_Shoot_Gyro_Error_Calc;/* '<S97>/Lookup Table Dynamic' */
  real_T Desired_Hood_Pos_Calc;        /* '<S98>/Lookup Table Dynamic' */
  real_T Desired_Shooter_Motor_Speed_Cal;/* '<S99>/Lookup Table Dynamic' */
  real_T Desired_Shot_Distance;        /* '<S101>/Hypot' */
  real_T Desired_Target_X;             /* '<S104>/Add' */
  real_T Desired_Target_Y;             /* '<S104>/Add1' */
  real_T Product2[2];                  /* '<S79>/Product2' */
  real_T Product3[2];                  /* '<S77>/Product3' */
  uint8_T Active_GameState;            /* '<S9>/Chart' */
  boolean_T Button_Enable_Wheels;      /* '<S23>/FixPt Relational Operator' */
  boolean_T Button_Reset_Wheel_Offsets;/* '<S24>/FixPt Relational Operator' */
  boolean_T Button_Disable_Wheels;     /* '<S25>/FixPt Relational Operator' */
  boolean_T Drive_Joystick_Z_Mode;     /* '<S20>/Compare' */
  boolean_T Is_Boosting;               /* '<S22>/Compare' */
  boolean_T Face_Toward_Driver;        /* '<S18>/Compare' */
  boolean_T Face_Right_Driver;         /* '<S19>/Compare' */
  boolean_T Face_Left_Driver;          /* '<S21>/Compare' */
  boolean_T Face_Away_Driver;          /* '<S17>/Compare' */
  boolean_T Spline_Enable;             /* '<S7>/Merge7' */
  boolean_T IsBlueActive;              /* '<S86>/Merge' */
  boolean_T IsRedActive;               /* '<S86>/Merge1' */
  boolean_T Allow_Score_In_Alliance_Zone;/* '<S113>/Merge' */
  boolean_T Ready_to_Score;            /* '<S87>/AND2' */
  boolean_T Is_Outside_Alliance_Zone;  /* '<S114>/Merge' */
  boolean_T Ready_to_Pass;             /* '<S87>/AND3' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S11>/Merge4' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S11>/Merge5' */
  boolean_T Swerve_Drive_Integral_Enable;/* '<S7>/Merge23' */
  boolean_T Robot_Reached_Destination; /* '<S11>/Merge7' */
  boolean_T Test_Mode;                 /* '<S7>/Merge10' */
  boolean_T Relative_Enable;           /* '<S341>/Logical Operator1' */
  boolean_T Steering_Abs_Angle_Active; /* '<S343>/AND6' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S135>/Merge1' */
  boolean_T Shooter_Active;          /* '<S10>/Shooter_Transfer_Feeder Chart' */
} B_Robot_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S23>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S24>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S25>/Delay Input1' */
  real_T TappedDelay_X[2];             /* '<S6>/Tapped Delay' */
  real_T TappedDelay1_X[2];            /* '<S6>/Tapped Delay1' */
  real_T MemoryX_DSTATE[2];            /* '<S26>/MemoryX' */
  real_T UnitDelay_1_DSTATE;           /* '<S10>/Unit Delay' */
  real_T UnitDelay_4_DSTATE;           /* '<S10>/Unit Delay' */
  real_T UnitDelay_2_DSTATE;           /* '<S10>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S10>/Unit Delay' */
  real_T UnitDelay_DSTATE_c;           /* '<S85>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S312>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S311>/UD' */
  real_T UnitDelay_DSTATE_m;           /* '<S309>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S292>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_e;     /* '<S307>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S291>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_p;     /* '<S300>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S266>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S265>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S259>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S203>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S202>/UD' */
  real_T UnitDelay_DSTATE_j;           /* '<S196>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S214>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S213>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S199>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S224>/Unit Delay1' */
  real_T UD_DSTATE_m;                  /* '<S223>/UD' */
  real_T UnitDelay_DSTATE_h;           /* '<S217>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S235>/Unit Delay1' */
  real_T UD_DSTATE_i;                  /* '<S234>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S220>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n4;         /* '<S245>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S244>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S238>/Unit Delay' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S256>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S255>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S241>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S277>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S276>/UD' */
  real_T UnitDelay_DSTATE_lm;          /* '<S262>/Unit Delay' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S127>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S126>/UD' */
  real_T UnitDelay_DSTATE_kz;          /* '<S125>/Unit Delay' */
  real_T UnitDelay1_DSTATE_d;          /* '<S122>/Unit Delay1' */
  real_T UD_DSTATE_ml;                 /* '<S121>/UD' */
  real_T UnitDelay_DSTATE_di;          /* '<S120>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S343>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_j2;         /* '<S343>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S357>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S357>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S361>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_gh;          /* '<S131>/Unit Delay' */
  void *MatrixConcatenate_PWORK;       /* '<S152>/Matrix Concatenate' */
  int32_T Selector5_DIMS1[2];          /* '<S152>/Selector5' */
  int32_T MatrixConcatenate_DIMS1[2];  /* '<S152>/Matrix Concatenate' */
  int32_T Selector4_DIMS1[2];          /* '<S152>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S290>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_p;    /* '<S307>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S300>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_f;    /* '<S83>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S361>/FixPt Unit Delay2' */
  boolean_T UnitDelay_DSTATE_ki;       /* '<S91>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_db;       /* '<S88>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ir;       /* '<S14>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S351>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S350>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S346>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S347>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S348>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g2;     /* '<S349>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE;         /* '<S343>/Unit Delay2' */
  boolean_T UnitDelay4_DSTATE;         /* '<S343>/Unit Delay4' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S11>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S135>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S138>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S140>/If' */
  uint8_T is_active_c2_Robot_Control;/* '<S10>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_c2_Robot_Control;       /* '<S10>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_Shooting;               /* '<S10>/Shooter_Transfer_Feeder Chart' */
  uint8_T is_active_c9_Robot_Control;  /* '<S9>/Chart' */
  uint8_T is_c9_Robot_Control;         /* '<S9>/Chart' */
  boolean_T icLoad;                    /* '<S26>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S53>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S46>/MeasurementUpdate' */
} DW_Robot_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S207>/Cos5' */
  const real_T Sin5;                   /* '<S207>/Sin5' */
  const real_T Cos5_g;                 /* '<S228>/Cos5' */
  const real_T Sin5_m;                 /* '<S228>/Sin5' */
  const real_T Cos5_i;                 /* '<S249>/Cos5' */
  const real_T Sin5_e;                 /* '<S249>/Sin5' */
  const real_T Cos5_b;                 /* '<S270>/Cos5' */
  const real_T Sin5_c;                 /* '<S270>/Sin5' */
  const real_T Atan2;                  /* '<S280>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S280>/Add' */
  const real_T Atan1;                  /* '<S280>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S280>/Add1' */
  const real_T Atan3;                  /* '<S280>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S280>/Add2' */
  const real_T Atan4;                  /* '<S280>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S280>/Add3' */
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
extern real_T BlueAllianceZoneX;       /* Variable: BlueAllianceZoneX
                                        * Referenced by:
                                        *   '<S115>/BlueAllianceZoneX'
                                        *   '<S117>/BlueAllianceZoneX'
                                        */
extern real_T Blue_Hub_X;              /* Variable: Blue_Hub_X
                                        * Referenced by: '<S100>/Constant'
                                        */
extern real_T Blue_Hub_Y;              /* Variable: Blue_Hub_Y
                                        * Referenced by: '<S100>/Constant1'
                                        */
extern real_T Boost_Trigger_Decreasing_Limit;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S358>/Constant1'
                                      */
extern real_T Boost_Trigger_High_Speed;/* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S354>/Constant'
                                        *   '<S354>/Saturation'
                                        */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S358>/Constant3'
                                      */
extern real_T Boost_Trigger_Low_Speed; /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S354>/Constant1'
                                        */
extern real_T Dist_Arr_0;              /* Variable: Dist_Arr_0
                                        * Referenced by:
                                        *   '<S97>/Constant5'
                                        *   '<S98>/Constant5'
                                        *   '<S99>/Constant5'
                                        *   '<S102>/Constant5'
                                        */
extern real_T Dist_Arr_1;              /* Variable: Dist_Arr_1
                                        * Referenced by:
                                        *   '<S97>/Constant6'
                                        *   '<S98>/Constant6'
                                        *   '<S99>/Constant6'
                                        *   '<S102>/Constant6'
                                        */
extern real_T Dist_Arr_2;              /* Variable: Dist_Arr_2
                                        * Referenced by:
                                        *   '<S97>/Constant7'
                                        *   '<S98>/Constant7'
                                        *   '<S99>/Constant7'
                                        *   '<S102>/Constant7'
                                        */
extern real_T Dist_Arr_3;              /* Variable: Dist_Arr_3
                                        * Referenced by:
                                        *   '<S97>/Constant8'
                                        *   '<S98>/Constant8'
                                        *   '<S99>/Constant8'
                                        *   '<S102>/Constant8'
                                        */
extern real_T Dist_Arr_4;              /* Variable: Dist_Arr_4
                                        * Referenced by:
                                        *   '<S97>/Constant9'
                                        *   '<S98>/Constant9'
                                        *   '<S99>/Constant9'
                                        *   '<S102>/Constant9'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S196>/Constant3'
                                        *   '<S217>/Constant3'
                                        *   '<S238>/Constant3'
                                        *   '<S259>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S196>/Constant2'
                                   *   '<S217>/Constant2'
                                   *   '<S238>/Constant2'
                                   *   '<S259>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S196>/Saturation'
                                        *   '<S217>/Saturation'
                                        *   '<S238>/Saturation'
                                        *   '<S259>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S196>/Saturation'
                                        *   '<S217>/Saturation'
                                        *   '<S238>/Saturation'
                                        *   '<S259>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S196>/Gain'
                                        *   '<S217>/Gain'
                                        *   '<S238>/Gain'
                                        *   '<S259>/Gain'
                                        */
extern real_T Drive_Motor_Control_I;   /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S196>/Gain2'
                                        *   '<S217>/Gain2'
                                        *   '<S238>/Gain2'
                                        *   '<S259>/Gain2'
                                        */
extern real_T Drive_Motor_Control_I_LL;/* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S196>/Saturation1'
                                        *   '<S217>/Saturation1'
                                        *   '<S238>/Saturation1'
                                        *   '<S259>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_I_UL;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S196>/Saturation1'
                                        *   '<S217>/Saturation1'
                                        *   '<S238>/Saturation1'
                                        *   '<S259>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S196>/Gain1'
                                        *   '<S217>/Gain1'
                                        *   '<S238>/Gain1'
                                        *   '<S259>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S201>/Constant'
                            *   '<S222>/Constant'
                            *   '<S243>/Constant'
                            *   '<S264>/Constant'
                            */
extern real_T Feeder_Motor_Gain_FF;    /* Variable: Feeder_Motor_Gain_FF
                                        * Referenced by: '<S10>/Constant'
                                        */
extern real_T Field_Translation_Control_Gain;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S344>/Gain2'
                                      */
extern real_T Field_Translation_Speed_Max;/* Variable: Field_Translation_Speed_Max
                                           * Referenced by: '<S344>/Constant5'
                                           */
extern real_T Gyro_Err_Arr_0;          /* Variable: Gyro_Err_Arr_0
                                        * Referenced by: '<S97>/Constant'
                                        */
extern real_T Gyro_Err_Arr_1;          /* Variable: Gyro_Err_Arr_1
                                        * Referenced by: '<S97>/Constant1'
                                        */
extern real_T Gyro_Err_Arr_2;          /* Variable: Gyro_Err_Arr_2
                                        * Referenced by: '<S97>/Constant2'
                                        */
extern real_T Gyro_Err_Arr_3;          /* Variable: Gyro_Err_Arr_3
                                        * Referenced by: '<S97>/Constant3'
                                        */
extern real_T Gyro_Err_Arr_4;          /* Variable: Gyro_Err_Arr_4
                                        * Referenced by: '<S97>/Constant4'
                                        */
extern real_T Hood_Pos_Max_Error_Shoot;/* Variable: Hood_Pos_Max_Error_Shoot
                                        * Referenced by: '<S87>/Constant1'
                                        */
extern real_T Hood_Position_0;         /* Variable: Hood_Position_0
                                        * Referenced by: '<S98>/Constant'
                                        */
extern real_T Hood_Position_1;         /* Variable: Hood_Position_1
                                        * Referenced by: '<S98>/Constant1'
                                        */
extern real_T Hood_Position_2;         /* Variable: Hood_Position_2
                                        * Referenced by: '<S98>/Constant2'
                                        */
extern real_T Hood_Position_3;         /* Variable: Hood_Position_3
                                        * Referenced by: '<S98>/Constant3'
                                        */
extern real_T Hood_Position_4;         /* Variable: Hood_Position_4
                                        * Referenced by: '<S98>/Constant4'
                                        */
extern real_T Hood_Servo_Pos_Max;      /* Variable: Hood_Servo_Pos_Max
                                        * Referenced by: '<S8>/Saturation'
                                        */
extern real_T Hood_Servo_Pos_Min;      /* Variable: Hood_Servo_Pos_Min
                                        * Referenced by: '<S8>/Saturation'
                                        */
extern real_T Hood_Servo_Rate_Limit_Dec;/* Variable: Hood_Servo_Rate_Limit_Dec
                                         * Referenced by: '<S80>/Constant1'
                                         */
extern real_T Hood_Servo_Rate_Limit_Inc;/* Variable: Hood_Servo_Rate_Limit_Inc
                                         * Referenced by: '<S80>/Constant3'
                                         */
extern real_T KF_Enable;               /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S6>/Constant2'
                                        */
extern real_T RedAllianceZoneX;        /* Variable: RedAllianceZoneX
                                        * Referenced by:
                                        *   '<S116>/RedAllianceZoneX'
                                        *   '<S118>/RedAllianceZoneX'
                                        */
extern real_T Red_Hub_X;               /* Variable: Red_Hub_X
                                        * Referenced by: '<S100>/Constant2'
                                        */
extern real_T Red_Hub_Y;               /* Variable: Red_Hub_Y
                                        * Referenced by: '<S100>/Constant3'
                                        */
extern real_T Relative_Steering_Error_Angle_Gain;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S343>/Constant4'
                                  */
extern real_T Relative_Steering_Error_Angle_Gain_Object_Factor;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S341>/Gain'
                    */
extern real_T Relative_Steering_Speed_Max;/* Variable: Relative_Steering_Speed_Max
                                           * Referenced by: '<S343>/Constant10'
                                           */
extern real_T Relative_Translation_Control_Gain;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S344>/Gain1'
                                   */
extern real_T Relative_Translation_Speed_Max;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S344>/Constant8'
                                      */
extern real_T Robot_Velocity_Maximum_Shooter;
                                     /* Variable: Robot_Velocity_Maximum_Shooter
                                      * Referenced by: '<S87>/Constant'
                                      */
extern real_T Shooter_Error_Integral_Enable;
                                      /* Variable: Shooter_Error_Integral_Enable
                                       * Referenced by: '<S88>/Constant1'
                                       */
extern real_T Shooter_Motor_Gain_D;    /* Variable: Shooter_Motor_Gain_D
                                        * Referenced by: '<S120>/Constant3'
                                        */
extern real_T Shooter_Motor_Gain_FF;   /* Variable: Shooter_Motor_Gain_FF
                                        * Referenced by: '<S120>/Gain'
                                        */
extern real_T Shooter_Motor_Gain_I;    /* Variable: Shooter_Motor_Gain_I
                                        * Referenced by: '<S120>/Gain2'
                                        */
extern real_T Shooter_Motor_Gain_P;    /* Variable: Shooter_Motor_Gain_P
                                        * Referenced by: '<S120>/Gain1'
                                        */
extern real_T Shooter_Motor_Max_Error_Shoot;
                                      /* Variable: Shooter_Motor_Max_Error_Shoot
                                       * Referenced by: '<S87>/Constant2'
                                       */
extern real_T Shooter_Spd_0;           /* Variable: Shooter_Spd_0
                                        * Referenced by: '<S99>/Constant'
                                        */
extern real_T Shooter_Spd_1;           /* Variable: Shooter_Spd_1
                                        * Referenced by: '<S99>/Constant1'
                                        */
extern real_T Shooter_Spd_2;           /* Variable: Shooter_Spd_2
                                        * Referenced by: '<S99>/Constant2'
                                        */
extern real_T Shooter_Spd_3;           /* Variable: Shooter_Spd_3
                                        * Referenced by: '<S99>/Constant3'
                                        */
extern real_T Shooter_Spd_4;           /* Variable: Shooter_Spd_4
                                        * Referenced by: '<S99>/Constant4'
                                        */
extern real_T Shot_Target_Error_Thresh;/* Variable: Shot_Target_Error_Thresh
                                        * Referenced by: '<S106>/Constant'
                                        */
extern real_T Spline_Last_Pose_Distance_to_Velocity_Gain;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S185>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S185>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S132>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S145>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S185>/Constant3'
                                     */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S292>/Constant5'
                    */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S292>/Constant6'
                    */
extern real_T Steering_Absolute_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S292>/Constant9'
                          */
extern real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S292>/Constant10'
                    */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S292>/Constant1'
                                */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S292>/Constant3'
                                */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S309>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S309>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S309>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S309>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S308>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S309>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S309>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S309>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S309>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S309>/Constant1'
                                   *   '<S309>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S309>/Constant'
                                   *   '<S309>/Saturation2'
                                   */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S199>/Constant3'
                                        *   '<S220>/Constant3'
                                        *   '<S241>/Constant3'
                                        *   '<S262>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S199>/Constant2'
                                *   '<S220>/Constant2'
                                *   '<S241>/Constant2'
                                *   '<S262>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S199>/Saturation'
                                           *   '<S220>/Saturation'
                                           *   '<S241>/Saturation'
                                           *   '<S262>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S199>/Saturation'
                                           *   '<S220>/Saturation'
                                           *   '<S241>/Saturation'
                                           *   '<S262>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S199>/Gain2'
                                        *   '<S220>/Gain2'
                                        *   '<S241>/Gain2'
                                        *   '<S262>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S199>/Saturation1'
                                           *   '<S220>/Saturation1'
                                           *   '<S241>/Saturation1'
                                           *   '<S262>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S199>/Saturation1'
                                           *   '<S220>/Saturation1'
                                           *   '<S241>/Saturation1'
                                           *   '<S262>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S199>/Gain1'
                                        *   '<S220>/Gain1'
                                        *   '<S241>/Gain1'
                                        *   '<S262>/Gain1'
                                        */
extern real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S291>/Constant5'
                    */
extern real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S291>/Constant6'
                    */
extern real_T Steering_Relative_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S291>/Constant9'
                          */
extern real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S291>/Constant10'
                    */
extern real_T Steering_Relative_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S291>/Constant1'
                                */
extern real_T Steering_Relative_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S291>/Constant3'
                                */
extern real_T Steering_Relative_Gain;  /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S343>/Constant'
                                        */
extern real_T Steering_Twist_Gain;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S343>/Constant1'
                                        */
extern real_T TEST_Desired_Hood_Enable_OV;/* Variable: TEST_Desired_Hood_Enable_OV
                                           * Referenced by: '<S8>/Constant7'
                                           */
extern real_T TEST_Desired_Hood_Pos_OV;/* Variable: TEST_Desired_Hood_Pos_OV
                                        * Referenced by: '<S8>/Constant6'
                                        */
extern real_T TEST_Feeder_Motor_DC_OV; /* Variable: TEST_Feeder_Motor_DC_OV
                                        * Referenced by: '<S8>/Constant2'
                                        */
extern real_T TEST_Output_Override_Flag;/* Variable: TEST_Output_Override_Flag
                                         * Referenced by: '<S8>/Constant'
                                         */
extern real_T TEST_Shooter_Motor_DC_Center_OV;
                                    /* Variable: TEST_Shooter_Motor_DC_Center_OV
                                     * Referenced by: '<S8>/Constant4'
                                     */
extern real_T TEST_Shooter_Motor_DC_Left_OV;
                                      /* Variable: TEST_Shooter_Motor_DC_Left_OV
                                       * Referenced by: '<S8>/Constant3'
                                       */
extern real_T TEST_Shooter_Motor_DC_Right_OV;
                                     /* Variable: TEST_Shooter_Motor_DC_Right_OV
                                      * Referenced by: '<S8>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Override_Flag;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S342>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Steering;/* Variable: TEST_Swerve_Mode_Steering
                                         * Referenced by: '<S342>/Constant8'
                                         */
extern real_T TEST_Swerve_Mode_Translation;/* Variable: TEST_Swerve_Mode_Translation
                                            * Referenced by: '<S342>/Constant7'
                                            */
extern real_T TEST_Transfer_Motor_DC_OV;/* Variable: TEST_Transfer_Motor_DC_OV
                                         * Referenced by: '<S8>/Constant1'
                                         */
extern real_T TOF_Arr_0;               /* Variable: TOF_Arr_0
                                        * Referenced by: '<S102>/Constant'
                                        */
extern real_T TOF_Arr_1;               /* Variable: TOF_Arr_1
                                        * Referenced by: '<S102>/Constant1'
                                        */
extern real_T TOF_Arr_2;               /* Variable: TOF_Arr_2
                                        * Referenced by: '<S102>/Constant2'
                                        */
extern real_T TOF_Arr_3;               /* Variable: TOF_Arr_3
                                        * Referenced by: '<S102>/Constant3'
                                        */
extern real_T TOF_Arr_4;               /* Variable: TOF_Arr_4
                                        * Referenced by: '<S102>/Constant4'
                                        */
extern real_T Target_Feeder_Speed;     /* Variable: Target_Feeder_Speed
                                        * Referenced by: '<S10>/Shooter_Transfer_Feeder Chart'
                                        */
extern real_T Target_Transfer_Speed;   /* Variable: Target_Transfer_Speed
                                        * Referenced by: '<S10>/Shooter_Transfer_Feeder Chart'
                                        */
extern real_T Transfer_Error_Integral_Enable;
                                     /* Variable: Transfer_Error_Integral_Enable
                                      * Referenced by: '<S91>/Constant1'
                                      */
extern real_T Transfer_Minimum_Factor; /* Variable: Transfer_Minimum_Factor
                                        * Referenced by: '<S10>/Shooter_Transfer_Feeder Chart'
                                        */
extern real_T Transfer_Motor_Gain_D;   /* Variable: Transfer_Motor_Gain_D
                                        * Referenced by: '<S125>/Constant3'
                                        */
extern real_T Transfer_Motor_Gain_FF;  /* Variable: Transfer_Motor_Gain_FF
                                        * Referenced by: '<S125>/Gain'
                                        */
extern real_T Transfer_Motor_Gain_I;   /* Variable: Transfer_Motor_Gain_I
                                        * Referenced by: '<S125>/Gain2'
                                        */
extern real_T Transfer_Motor_Gain_P;   /* Variable: Transfer_Motor_Gain_P
                                        * Referenced by: '<S125>/Gain1'
                                        */
extern real_T Translation_Speed_Approach_Zero_Error_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S279>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S279>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S279>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S279>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S279>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S279>/Constant3'
                                    */
extern real_T Translation_Twist_Gain;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S344>/Gain'
                                        */
extern real_T Twist_Deadzone_neg;      /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S343>/Dead Zone'
                                        *   '<S344>/Dead Zone'
                                        */
extern real_T Twist_Deadzone_pos;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S343>/Dead Zone'
                                        *   '<S344>/Dead Zone'
                                        */
extern real_T Vision_Object_Angle_Offset;/* Variable: Vision_Object_Angle_Offset
                                          * Referenced by: '<S15>/Constant6'
                                          */
extern real_T Vision_Object_Target_Angle;/* Variable: Vision_Object_Target_Angle
                                          * Referenced by: '<S341>/Constant7'
                                          */
extern real_T Vision_Object_Target_X;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S341>/Constant1'
                                        */
extern real_T Vision_Object_Target_Y;  /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S341>/Constant4'
                                        */
extern real_T Vision_Object_X_Offset;  /* Variable: Vision_Object_X_Offset
                                        * Referenced by: '<S15>/Constant4'
                                        */
extern real_T Vision_Object_Y_Offset;  /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S15>/Constant8'
                                        */
extern real_T Vision_Tag_Angle_Offset; /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S15>/Constant5'
                                        */
extern real_T Vision_Tag_Target_Angle; /* Variable: Vision_Tag_Target_Angle
                                        * Referenced by: '<S341>/Constant8'
                                        */
extern real_T Vision_Tag_Target_X;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S341>/Constant2'
                                        */
extern real_T Vision_Tag_Target_Y;     /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S341>/Constant5'
                                        */
extern real_T Vision_Tag_X_Offset;     /* Variable: Vision_Tag_X_Offset
                                        * Referenced by: '<S15>/Constant3'
                                        */
extern real_T Vision_Tag_Y_Offset;     /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S15>/Constant7'
                                        */
extern uint8_T TEST_Pipeline;          /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S14>/Constant22'
                                        *   '<S341>/Constant11'
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
 * Block '<S5>/Unit Delay' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Conversion' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Conversion' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/G' : Unused code path elimination
 * Block '<S26>/H' : Unused code path elimination
 * Block '<S26>/N' : Unused code path elimination
 * Block '<S26>/P0' : Unused code path elimination
 * Block '<S26>/Q' : Unused code path elimination
 * Block '<S26>/R' : Unused code path elimination
 * Block '<S58>/CheckSignalProperties' : Unused code path elimination
 * Block '<S67>/CheckSignalProperties' : Unused code path elimination
 * Block '<S68>/CheckSignalProperties' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Propagation' : Unused code path elimination
 * Block '<S83>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S9>/Unit Delay1' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Propagation' : Unused code path elimination
 * Block '<S120>/Scope' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Propagation' : Unused code path elimination
 * Block '<S125>/Scope' : Unused code path elimination
 * Block '<S11>/Gain' : Unused code path elimination
 * Block '<S11>/Gain1' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S144>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S154>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S204>/Data Type Duplicate' : Unused code path elimination
 * Block '<S204>/Data Type Propagation' : Unused code path elimination
 * Block '<S196>/Scope' : Unused code path elimination
 * Block '<S198>/Scope' : Unused code path elimination
 * Block '<S215>/Data Type Duplicate' : Unused code path elimination
 * Block '<S215>/Data Type Propagation' : Unused code path elimination
 * Block '<S199>/Scope' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S225>/Data Type Propagation' : Unused code path elimination
 * Block '<S217>/Scope' : Unused code path elimination
 * Block '<S219>/Scope' : Unused code path elimination
 * Block '<S236>/Data Type Duplicate' : Unused code path elimination
 * Block '<S236>/Data Type Propagation' : Unused code path elimination
 * Block '<S220>/Scope' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate' : Unused code path elimination
 * Block '<S246>/Data Type Propagation' : Unused code path elimination
 * Block '<S238>/Scope' : Unused code path elimination
 * Block '<S240>/Scope' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate' : Unused code path elimination
 * Block '<S257>/Data Type Propagation' : Unused code path elimination
 * Block '<S241>/Scope' : Unused code path elimination
 * Block '<S267>/Data Type Duplicate' : Unused code path elimination
 * Block '<S267>/Data Type Propagation' : Unused code path elimination
 * Block '<S259>/Scope' : Unused code path elimination
 * Block '<S261>/Scope' : Unused code path elimination
 * Block '<S278>/Data Type Duplicate' : Unused code path elimination
 * Block '<S278>/Data Type Propagation' : Unused code path elimination
 * Block '<S262>/Scope' : Unused code path elimination
 * Block '<S289>/Data Type Duplicate' : Unused code path elimination
 * Block '<S289>/Data Type Propagation' : Unused code path elimination
 * Block '<S290>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S299>/Data Type Duplicate' : Unused code path elimination
 * Block '<S299>/Data Type Propagation' : Unused code path elimination
 * Block '<S300>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S306>/Data Type Duplicate' : Unused code path elimination
 * Block '<S306>/Data Type Propagation' : Unused code path elimination
 * Block '<S307>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S313>/Data Type Duplicate' : Unused code path elimination
 * Block '<S313>/Data Type Propagation' : Unused code path elimination
 * Block '<S309>/Scope' : Unused code path elimination
 * Block '<S353>/Data Type Duplicate' : Unused code path elimination
 * Block '<S353>/Data Type Propagation' : Unused code path elimination
 * Block '<S360>/Data Type Duplicate' : Unused code path elimination
 * Block '<S360>/Data Type Propagation' : Unused code path elimination
 * Block '<S361>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S69>/Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/Conversion' : Eliminate redundant data type conversion
 * Block '<S72>/Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S42>/Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Reshape' : Reshape block reduction
 * Block '<S26>/ReshapeX0' : Reshape block reduction
 * Block '<S26>/Reshapexhat' : Reshape block reduction
 * Block '<S6>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S6>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S10>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S10>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S10>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S184>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S341>/Constant10' : Unused code path elimination
 * Block '<S341>/Constant9' : Unused code path elimination
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
 * '<S3>'   : 'Robot_Control/Control_System/Disabled'
 * '<S4>'   : 'Robot_Control/Control_System/Human_Input_Pre_Processing'
 * '<S5>'   : 'Robot_Control/Control_System/Internal Feedback'
 * '<S6>'   : 'Robot_Control/Control_System/Kalman_Filter'
 * '<S7>'   : 'Robot_Control/Control_System/Merge'
 * '<S8>'   : 'Robot_Control/Control_System/Output Overrides'
 * '<S9>'   : 'Robot_Control/Control_System/Previous GameState'
 * '<S10>'  : 'Robot_Control/Control_System/Shooter Controls'
 * '<S11>'  : 'Robot_Control/Control_System/Spline_Path_Following'
 * '<S12>'  : 'Robot_Control/Control_System/Swerve_Drive'
 * '<S13>'  : 'Robot_Control/Control_System/Teleop'
 * '<S14>'  : 'Robot_Control/Control_System/Test'
 * '<S15>'  : 'Robot_Control/Control_System/Vision_Corrections'
 * '<S16>'  : 'Robot_Control/Control_System/Autonomous/Subsystem'
 * '<S17>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant1'
 * '<S18>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant5'
 * '<S19>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant6'
 * '<S20>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant7'
 * '<S21>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant8'
 * '<S22>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero17'
 * '<S23>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase'
 * '<S24>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase1'
 * '<S25>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase2'
 * '<S26>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter'
 * '<S27>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL'
 * '<S28>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat'
 * '<S29>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator'
 * '<S30>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionA'
 * '<S31>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionB'
 * '<S32>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionC'
 * '<S33>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionD'
 * '<S34>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionG'
 * '<S35>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionH'
 * '<S36>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionN'
 * '<S37>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP'
 * '<S38>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP0'
 * '<S39>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionQ'
 * '<S40>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionR'
 * '<S41>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionReset'
 * '<S42>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX'
 * '<S43>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX0'
 * '<S44>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionu'
 * '<S45>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/MemoryP'
 * '<S46>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer'
 * '<S47>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN'
 * '<S48>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reset'
 * '<S49>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reshapeyhat'
 * '<S50>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionP0'
 * '<S51>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionQ'
 * '<S52>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionR'
 * '<S53>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator'
 * '<S54>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkA'
 * '<S55>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkB'
 * '<S56>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkC'
 * '<S57>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkD'
 * '<S58>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkEnable'
 * '<S59>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkG'
 * '<S60>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkH'
 * '<S61>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkN'
 * '<S62>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkP0'
 * '<S63>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkQ'
 * '<S64>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkR'
 * '<S65>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkReset'
 * '<S66>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkX0'
 * '<S67>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checku'
 * '<S68>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checky'
 * '<S69>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S70>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S71>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S72>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S73>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/Ground'
 * '<S74>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat/Ground'
 * '<S75>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S76>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S77>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer/MeasurementUpdate'
 * '<S78>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN/Ground'
 * '<S79>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S80>'  : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo'
 * '<S81>'  : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter'
 * '<S82>'  : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter/Saturation Dynamic'
 * '<S83>'  : 'Robot_Control/Control_System/Output Overrides/Represents the response of the servo/Discrete Rate Limiter/Unit Delay External IC'
 * '<S84>'  : 'Robot_Control/Control_System/Previous GameState/Chart'
 * '<S85>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings'
 * '<S86>'  : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring'
 * '<S87>'  : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot'
 * '<S88>'  : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control'
 * '<S89>'  : 'Robot_Control/Control_System/Shooter Controls/Shooter_Transfer_Feeder Chart'
 * '<S90>'  : 'Robot_Control/Control_System/Shooter Controls/Subsystem'
 * '<S91>'  : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control'
 * '<S92>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math'
 * '<S93>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Shooter Not Active'
 * '<S94>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters'
 * '<S95>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Desired Gyro Angle Calculation'
 * '<S96>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target'
 * '<S97>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Allowed Shoot Gyro Error'
 * '<S98>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Hood Position'
 * '<S99>'  : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Look Up Desired Shooter Motor Speed'
 * '<S100>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Shot_Coordinate_Selection'
 * '<S101>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Calculate Shot Distance'
 * '<S102>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Shot Distance to TOF'
 * '<S103>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Target_Selection'
 * '<S104>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position'
 * '<S105>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check'
 * '<S106>' : 'Robot_Control/Control_System/Shooter Controls/Calculate Shooter Settings/Desired Shooting Parameters Math/Shooting_Parameters/Iterate_Shot_Target/Update Target Position/Convergence Error Check/Compare To Constant'
 * '<S107>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem'
 * '<S108>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem1'
 * '<S109>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem2'
 * '<S110>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem3'
 * '<S111>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem4'
 * '<S112>' : 'Robot_Control/Control_System/Shooter Controls/Check if Hub is Active for Scoring/If Action Subsystem5'
 * '<S113>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Allow Score in Alliance Zone'
 * '<S114>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Subsystem'
 * '<S115>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Allow Score in Alliance Zone/Blue'
 * '<S116>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Allow Score in Alliance Zone/Red'
 * '<S117>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Subsystem/Blue'
 * '<S118>' : 'Robot_Control/Control_System/Shooter Controls/Ready_to_Shoot/Subsystem/Red'
 * '<S119>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Compare To Zero'
 * '<S120>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S121>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S122>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S123>' : 'Robot_Control/Control_System/Shooter Controls/Shooter Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S124>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Compare To Zero'
 * '<S125>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable'
 * '<S126>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Difference'
 * '<S127>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S128>' : 'Robot_Control/Control_System/Shooter Controls/Transfer Motor Speed Closed Loop Control/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S129>' : 'Robot_Control/Control_System/Spline_Path_Following/Pass Through'
 * '<S130>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled'
 * '<S131>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S132>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S133>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S134>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S135>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S136>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S137>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S138>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S139>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S140>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S141>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S142>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S143>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S144>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S145>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S146>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S147>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S148>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S149>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S150>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S151>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S152>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S153>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S154>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S155>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S156>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S157>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S158>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S159>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S160>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S161>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S162>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S163>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S164>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S165>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S166>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S167>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S168>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S169>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S170>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S171>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S172>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S173>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S174>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S175>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S176>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S177>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S178>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S179>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S180>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S181>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S182>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S183>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S184>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S185>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S186>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S187>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S188>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S189>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S190>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module'
 * '<S191>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1'
 * '<S192>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2'
 * '<S193>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3'
 * '<S194>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S195>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S196>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable'
 * '<S197>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S198>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S199>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S200>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S201>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S202>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Difference'
 * '<S203>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S204>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S205>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S206>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S207>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S208>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S209>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S210>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S211>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S212>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S213>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S214>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S215>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S216>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S217>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable'
 * '<S218>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S219>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S220>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S221>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S222>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S223>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Difference'
 * '<S224>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S225>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S226>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S227>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S228>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S229>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S230>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S231>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S232>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S233>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S234>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S235>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S236>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S237>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S238>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable'
 * '<S239>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S240>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S241>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S242>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S243>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S244>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Difference'
 * '<S245>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S246>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S247>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S248>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S249>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S250>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S251>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S252>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S253>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S254>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S255>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S256>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S257>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S258>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S259>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable'
 * '<S260>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S261>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S262>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S263>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S264>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S265>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Difference'
 * '<S266>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S267>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S268>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S269>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S270>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S271>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S272>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S273>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S274>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S275>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S276>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S277>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S278>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S279>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S280>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S281>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S282>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S283>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S284>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S285>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S286>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S287>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S288>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S289>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S290>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S291>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S292>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1'
 * '<S293>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S294>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S295>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S296>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S297>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S298>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S299>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S300>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S301>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero'
 * '<S302>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero1'
 * '<S303>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero2'
 * '<S304>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero3'
 * '<S305>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter'
 * '<S306>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S307>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S308>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S309>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S310>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S311>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S312>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S313>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S314>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S315>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Reduce Speeds for Maximum Speed Limit'
 * '<S316>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S317>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S318>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S319>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S320>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S321>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S322>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S323>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S324>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S325>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S326>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S327>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S328>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S329>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S330>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S331>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S332>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S333>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S334>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S335>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S336>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S337>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S338>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S339>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S340>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S341>' : 'Robot_Control/Control_System/Teleop/Relative Errors'
 * '<S342>' : 'Robot_Control/Control_System/Teleop/Subsystem'
 * '<S343>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S344>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S345>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Compare To Zero2'
 * '<S346>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase'
 * '<S347>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase1'
 * '<S348>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase2'
 * '<S349>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase3'
 * '<S350>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase4'
 * '<S351>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase5'
 * '<S352>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Previous active game state was not Teleop'
 * '<S353>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Saturation Dynamic'
 * '<S354>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S355>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero'
 * '<S356>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero1'
 * '<S357>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S358>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S359>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S360>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S361>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S362>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S363>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S364>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant'
 * '<S365>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant1'
 * '<S366>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant2'
 * '<S367>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero6'
 * '<S368>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero7'
 * '<S369>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero8'
 * '<S370>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance'
 * '<S371>' : 'Robot_Control/Control_System/Vision_Corrections/Degrees to Radians'
 * '<S372>' : 'Robot_Control/Control_System/Vision_Corrections/Polar to Cartesian1'
 * '<S373>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Prevent raising 0 to a negative exponent'
 * '<S374>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Subsystem'
 */
#endif                                 /* RTW_HEADER_Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
