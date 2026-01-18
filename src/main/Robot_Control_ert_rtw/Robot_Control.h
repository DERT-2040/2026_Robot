/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.432
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jan  3 07:03:36 2026
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
  real_T Vision_c1_AprilTag_Corr_X_inch;/* '<S13>/Add' */
  real_T Vision_c1_AprilTag_Corr_Y_inch;/* '<S13>/Add1' */
  real_T Vision_c1_AprilTag_Corr_Yaw_deg;/* '<S13>/Add2' */
  real_T Vision_c1_Object_Corr_X_inch; /* '<S13>/Add3' */
  real_T Vision_c1_Object_Corr_Y_inch; /* '<S13>/Add4' */
  real_T Vision_c1_Object_Corr_Yaw_deg;/* '<S13>/Add5' */
  real_T KF_Position_X;                /* '<S6>/Switch' */
  real_T KF_Position_Y;                /* '<S6>/Switch1' */
  real_T Spline_Num_Poses;             /* '<S7>/Merge9' */
  real_T Steering_Abs_Cmd;             /* '<S7>/Merge1' */
  real_T Steering_Rel_Cmd;             /* '<S7>/Merge2' */
  real_T Translation_Speed;            /* '<S7>/Merge4' */
  real_T Translation_Angle;            /* '<S7>/Merge3' */
  real_T Translation_Speed_SPF;        /* '<S9>/Merge2' */
  real_T Translation_Speed_RL;         /* '<S248>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S9>/Merge3' */
  real_T Gyro_Angle_SPF;               /* '<S9>/Merge8' */
  real_T Translation_Steering_Cmd;     /* '<S242>/Switch' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S9>/Merge' */
  real_T Steering_Localized_PID;       /* '<S269>/Saturation2' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S9>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S241>/Switch' */
  real_T BR_Desired_Wheel_Speed_in;    /* '<S295>/Switch1' */
  real_T FL_Desired_Wheel_Speed_in;    /* '<S280>/Switch1' */
  real_T FR_Desired_Wheel_Speed_in;    /* '<S285>/Switch1' */
  real_T BL_Desired_Wheel_Speed_in;    /* '<S290>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S275>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S295>/Switch' */
  real_T FL_Desired_Module_Angle;      /* '<S280>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S275>/Product' */
  real_T FR_Desired_Module_Angle;      /* '<S285>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S275>/Product1' */
  real_T BL_Desired_Module_Angle;      /* '<S290>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S275>/Product2' */
  real_T loop_counter_robot_control;   /* '<S1>/Sum' */
  real_T Steer_Joystick_X;             /* '<S4>/Signal Copy4' */
  real_T Relative_Error_Angle;         /* '<S301>/Switch4' */
  real_T Steering_Abs_Gyro_Latch;      /* '<S303>/Switch8' */
  real_T Steering_Abs_Gyro;            /* '<S303>/Switch2' */
  real_T Steering_Abs_Angle;           /* '<S303>/Switch3' */
  real_T Relative_Error_Y;             /* '<S301>/Switch2' */
  real_T Relative_Error_X;             /* '<S301>/Unary Minus1' */
  real_T Spline_Follow_Index;          /* '<S95>/Merge4' */
  real_T Spline_Target_Y;              /* '<S92>/Selector6' */
  real_T Spline_Target_X;              /* '<S92>/Selector2' */
  real_T Product2[2];                  /* '<S87>/Product2' */
  real_T Product3[2];                  /* '<S85>/Product3' */
  uint8_T Active_GameState;            /* '<S8>/Chart' */
  boolean_T Button_Enable_Wheels;      /* '<S31>/FixPt Relational Operator' */
  boolean_T Button_Reset_Wheel_Offsets;/* '<S32>/FixPt Relational Operator' */
  boolean_T Button_Disable_Wheels;     /* '<S33>/FixPt Relational Operator' */
  boolean_T Drive_Joystick_Z_Mode;     /* '<S22>/Compare' */
  boolean_T Is_Boosting;               /* '<S28>/Compare' */
  boolean_T Face_Toward_Driver;        /* '<S20>/Compare' */
  boolean_T Face_Right_Driver;         /* '<S21>/Compare' */
  boolean_T Face_Left_Driver;          /* '<S23>/Compare' */
  boolean_T Face_Away_Driver;          /* '<S16>/Compare' */
  boolean_T Align_Left;                /* '<S26>/Compare' */
  boolean_T Align_Right;               /* '<S25>/Compare' */
  boolean_T Spline_Enable;             /* '<S7>/Merge7' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S9>/Merge4' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S9>/Merge5' */
  boolean_T Swerve_Drive_Integral_Enable;/* '<S7>/Merge23' */
  boolean_T Robot_Reached_Destination; /* '<S9>/Merge7' */
  boolean_T Test_Mode;                 /* '<S7>/Merge10' */
  boolean_T Gamepad_POV_Up;            /* '<S15>/Compare' */
  boolean_T Gamepad_POV_Down;          /* '<S17>/Compare' */
  boolean_T Gamepad_POV_Right;         /* '<S18>/Compare' */
  boolean_T Gamepad_POV_Left;          /* '<S19>/Compare' */
  boolean_T Drive_Engage_Hook;         /* '<S24>/Compare' */
  boolean_T Align_Center;              /* '<S27>/Compare' */
  boolean_T Actuator_Cmd;              /* '<S29>/Compare' */
  boolean_T Winch_Cmd;                 /* '<S30>/Compare' */
  boolean_T Relative_Enable;           /* '<S301>/Logical Operator1' */
  boolean_T Steering_Abs_Angle_Active; /* '<S303>/AND6' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S95>/Merge1' */
} B_Robot_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S31>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S32>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S33>/Delay Input1' */
  real_T TappedDelay_X[2];             /* '<S6>/Tapped Delay' */
  real_T TappedDelay1_X[2];            /* '<S6>/Tapped Delay1' */
  real_T MemoryX_DSTATE[2];            /* '<S34>/MemoryX' */
  real_T UnitDelay1_DSTATE;            /* '<S272>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S271>/UD' */
  real_T UnitDelay_DSTATE_m;           /* '<S269>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S252>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_e;     /* '<S267>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S251>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_p;     /* '<S260>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S226>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S225>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S219>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S163>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S162>/UD' */
  real_T UnitDelay_DSTATE_j;           /* '<S156>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S174>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S173>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S159>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S184>/Unit Delay1' */
  real_T UD_DSTATE_m;                  /* '<S183>/UD' */
  real_T UnitDelay_DSTATE_h;           /* '<S177>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S195>/Unit Delay1' */
  real_T UD_DSTATE_i;                  /* '<S194>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S180>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n4;         /* '<S205>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S204>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S198>/Unit Delay' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S216>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S215>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S201>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S237>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S236>/UD' */
  real_T UnitDelay_DSTATE_lm;          /* '<S222>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S303>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_j2;         /* '<S303>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S317>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S317>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S321>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_gh;          /* '<S91>/Unit Delay' */
  void *MatrixConcatenate_PWORK;       /* '<S112>/Matrix Concatenate' */
  int32_T Selector5_DIMS1[2];          /* '<S112>/Selector5' */
  int32_T MatrixConcatenate_DIMS1[2];  /* '<S112>/Matrix Concatenate' */
  int32_T Selector4_DIMS1[2];          /* '<S112>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S250>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_p;    /* '<S267>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S260>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S321>/FixPt Unit Delay2' */
  boolean_T UnitDelay_DSTATE_ir;       /* '<S12>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S311>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S310>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S306>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S307>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S308>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g2;     /* '<S309>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE;         /* '<S303>/Unit Delay2' */
  boolean_T UnitDelay4_DSTATE;         /* '<S303>/Unit Delay4' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S9>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S95>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S98>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S100>/If' */
  uint8_T is_active_c9_Robot_Control;  /* '<S8>/Chart' */
  uint8_T is_c9_Robot_Control;         /* '<S8>/Chart' */
  boolean_T icLoad;                    /* '<S34>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S61>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S54>/MeasurementUpdate' */
} DW_Robot_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S167>/Cos5' */
  const real_T Sin5;                   /* '<S167>/Sin5' */
  const real_T Cos5_g;                 /* '<S188>/Cos5' */
  const real_T Sin5_m;                 /* '<S188>/Sin5' */
  const real_T Cos5_i;                 /* '<S209>/Cos5' */
  const real_T Sin5_e;                 /* '<S209>/Sin5' */
  const real_T Cos5_b;                 /* '<S230>/Cos5' */
  const real_T Sin5_c;                 /* '<S230>/Sin5' */
  const real_T Atan2;                  /* '<S240>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S240>/Add' */
  const real_T Atan1;                  /* '<S240>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S240>/Add1' */
  const real_T Atan3;                  /* '<S240>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S240>/Add2' */
  const real_T Atan4;                  /* '<S240>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S240>/Add3' */
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
  real_T Auto_Start_Position;          /* '<Root>/Auto_Start_Position' */
  real_T FL_Steer_Module_Angle;        /* '<Root>/FL_Steer_Module_Angle' */
  real_T FR_Steer_Module_Angle;        /* '<Root>/FR_Steer_Module_Angle' */
  real_T BL_Steer_Module_Angle;        /* '<Root>/BL_Steer_Module_Angle' */
  real_T BR_Steer_Module_Angle;        /* '<Root>/BR_Steer_Module_Angle' */
  real_T Odom_Position_X;              /* '<Root>/Odom_Position_X' */
  real_T Odom_Position_Y;              /* '<Root>/Odom_Position_Y' */
  real_T Odom_Delta_X;                 /* '<Root>/Odom_Delta_X' */
  real_T Odom_Delta_Y;                 /* '<Root>/Odom_Delta_Y' */
  real_T Vision_RobotPoseFieldSpace_X;
                                     /* '<Root>/Vision_RobotPoseFieldSpace_X' */
  real_T Vision_RobotPoseFieldSpace_Y;
                                     /* '<Root>/Vision_RobotPoseFieldSpace_Y' */
  real_T Vision_Num_Tags_Detected;     /* '<Root>/Vision_Num_Tags_Detected' */
  real_T Vision_Current_Pipeline;      /* '<Root>/Vision_Current_Pipeline' */
  boolean_T Vision_c1_AprilTag_Valid;  /* '<Root>/Vision_c1_AprilTag_Valid' */
  real_T Vision_c1_AprilTag_X_m;       /* '<Root>/Vision_c1_AprilTag_X_m' */
  real_T Vision_c1_AprilTag_Y_m;       /* '<Root>/Vision_c1_AprilTag_Y_m' */
  real_T Vision_c1_AprilTag_Yaw_deg;   /* '<Root>/Vision_c1_AprilTag_Yaw_deg' */
  boolean_T Vision_c1_Object_Valid;    /* '<Root>/Vision_c1_Object_Valid' */
  real_T Vision_c1_Object_Area_pct;    /* '<Root>/Vision_c1_Object_Area_pct' */
  real_T Vision_c1_Object_Hor_deg;     /* '<Root>/Vision_c1_Object_Hor_deg' */
  real_T Vision_c1_Object_Ver_deg;     /* '<Root>/Vision_c1_Object_Ver_deg' */
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
                                      * Referenced by: '<S318>/Constant1'
                                      */
extern real_T Boost_Trigger_High_Speed;/* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S314>/Constant'
                                        *   '<S314>/Saturation'
                                        */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S318>/Constant3'
                                      */
extern real_T Boost_Trigger_Low_Speed; /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S314>/Constant1'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S156>/Constant3'
                                        *   '<S177>/Constant3'
                                        *   '<S198>/Constant3'
                                        *   '<S219>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S156>/Constant2'
                                   *   '<S177>/Constant2'
                                   *   '<S198>/Constant2'
                                   *   '<S219>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S156>/Saturation'
                                        *   '<S177>/Saturation'
                                        *   '<S198>/Saturation'
                                        *   '<S219>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S156>/Saturation'
                                        *   '<S177>/Saturation'
                                        *   '<S198>/Saturation'
                                        *   '<S219>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S156>/Gain'
                                        *   '<S177>/Gain'
                                        *   '<S198>/Gain'
                                        *   '<S219>/Gain'
                                        */
extern real_T Drive_Motor_Control_I;   /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S156>/Gain2'
                                        *   '<S177>/Gain2'
                                        *   '<S198>/Gain2'
                                        *   '<S219>/Gain2'
                                        */
extern real_T Drive_Motor_Control_I_LL;/* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S156>/Saturation1'
                                        *   '<S177>/Saturation1'
                                        *   '<S198>/Saturation1'
                                        *   '<S219>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_I_UL;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S156>/Saturation1'
                                        *   '<S177>/Saturation1'
                                        *   '<S198>/Saturation1'
                                        *   '<S219>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S156>/Gain1'
                                        *   '<S177>/Gain1'
                                        *   '<S198>/Gain1'
                                        *   '<S219>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S161>/Constant'
                            *   '<S182>/Constant'
                            *   '<S203>/Constant'
                            *   '<S224>/Constant'
                            */
extern real_T Field_Translation_Control_Gain;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S304>/Gain2'
                                      */
extern real_T Field_Translation_Speed_Max;/* Variable: Field_Translation_Speed_Max
                                           * Referenced by: '<S304>/Constant5'
                                           */
extern real_T KF_Enable;               /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S6>/Constant2'
                                        */
extern real_T Relative_Steering_Error_Angle_Gain;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S303>/Constant4'
                                  */
extern real_T Relative_Steering_Error_Angle_Gain_Object_Factor;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S301>/Gain'
                    */
extern real_T Relative_Steering_Speed_Max;/* Variable: Relative_Steering_Speed_Max
                                           * Referenced by: '<S303>/Constant10'
                                           */
extern real_T Relative_Translation_Control_Gain;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S304>/Gain1'
                                   */
extern real_T Relative_Translation_Speed_Max;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S304>/Constant8'
                                      */
extern real_T Spline_Last_Pose_Distance_to_Velocity_Gain;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S145>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S145>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S92>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S105>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S145>/Constant3'
                                     */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S252>/Constant5'
                    */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S252>/Constant6'
                    */
extern real_T Steering_Absolute_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S252>/Constant9'
                          */
extern real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S252>/Constant10'
                    */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S252>/Constant1'
                                */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S252>/Constant3'
                                */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S269>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S269>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S269>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S269>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S268>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S269>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S269>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S269>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S269>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S269>/Constant1'
                                   *   '<S269>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S269>/Constant'
                                   *   '<S269>/Saturation2'
                                   */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S159>/Constant3'
                                        *   '<S180>/Constant3'
                                        *   '<S201>/Constant3'
                                        *   '<S222>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S159>/Constant2'
                                *   '<S180>/Constant2'
                                *   '<S201>/Constant2'
                                *   '<S222>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S159>/Saturation'
                                           *   '<S180>/Saturation'
                                           *   '<S201>/Saturation'
                                           *   '<S222>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S159>/Saturation'
                                           *   '<S180>/Saturation'
                                           *   '<S201>/Saturation'
                                           *   '<S222>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S159>/Gain2'
                                        *   '<S180>/Gain2'
                                        *   '<S201>/Gain2'
                                        *   '<S222>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S159>/Saturation1'
                                           *   '<S180>/Saturation1'
                                           *   '<S201>/Saturation1'
                                           *   '<S222>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S159>/Saturation1'
                                           *   '<S180>/Saturation1'
                                           *   '<S201>/Saturation1'
                                           *   '<S222>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S159>/Gain1'
                                        *   '<S180>/Gain1'
                                        *   '<S201>/Gain1'
                                        *   '<S222>/Gain1'
                                        */
extern real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S251>/Constant5'
                    */
extern real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S251>/Constant6'
                    */
extern real_T Steering_Relative_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S251>/Constant9'
                          */
extern real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S251>/Constant10'
                    */
extern real_T Steering_Relative_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S251>/Constant1'
                                */
extern real_T Steering_Relative_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S251>/Constant3'
                                */
extern real_T Steering_Relative_Gain;  /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S303>/Constant'
                                        */
extern real_T Steering_Twist_Gain;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S303>/Constant1'
                                        */
extern real_T TEST_Swerve_Mode_Override_Flag;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S302>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Steering;/* Variable: TEST_Swerve_Mode_Steering
                                         * Referenced by: '<S302>/Constant8'
                                         */
extern real_T TEST_Swerve_Mode_Translation;/* Variable: TEST_Swerve_Mode_Translation
                                            * Referenced by: '<S302>/Constant7'
                                            */
extern real_T Translation_Speed_Approach_Zero_Error_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S239>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S239>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S239>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S239>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S239>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S239>/Constant3'
                                    */
extern real_T Translation_Twist_Gain;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S304>/Gain'
                                        */
extern real_T Twist_Deadzone_neg;      /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S303>/Dead Zone'
                                        *   '<S304>/Dead Zone'
                                        */
extern real_T Twist_Deadzone_pos;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S303>/Dead Zone'
                                        *   '<S304>/Dead Zone'
                                        */
extern real_T Vision_Object_Angle_Offset;/* Variable: Vision_Object_Angle_Offset
                                          * Referenced by: '<S13>/Constant6'
                                          */
extern real_T Vision_Object_Target_Angle;/* Variable: Vision_Object_Target_Angle
                                          * Referenced by: '<S301>/Constant7'
                                          */
extern real_T Vision_Object_Target_X;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S301>/Constant1'
                                        */
extern real_T Vision_Object_Target_Y;  /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S301>/Constant4'
                                        */
extern real_T Vision_Object_X_Offset;  /* Variable: Vision_Object_X_Offset
                                        * Referenced by: '<S13>/Constant4'
                                        */
extern real_T Vision_Object_Y_Offset;  /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S13>/Constant8'
                                        */
extern real_T Vision_Tag_Angle_Offset; /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S13>/Constant5'
                                        */
extern real_T Vision_Tag_Target_Angle; /* Variable: Vision_Tag_Target_Angle
                                        * Referenced by: '<S301>/Constant8'
                                        */
extern real_T Vision_Tag_Target_X;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S301>/Constant2'
                                        */
extern real_T Vision_Tag_Target_Y;     /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S301>/Constant5'
                                        */
extern real_T Vision_Tag_X_Offset;     /* Variable: Vision_Tag_X_Offset
                                        * Referenced by: '<S13>/Constant3'
                                        */
extern real_T Vision_Tag_Y_Offset;     /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S13>/Constant7'
                                        */
extern uint8_T TEST_Pipeline;          /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S12>/Constant22'
                                        *   '<S301>/Constant11'
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
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Conversion' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Conversion' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/G' : Unused code path elimination
 * Block '<S34>/H' : Unused code path elimination
 * Block '<S34>/N' : Unused code path elimination
 * Block '<S34>/P0' : Unused code path elimination
 * Block '<S34>/Q' : Unused code path elimination
 * Block '<S34>/R' : Unused code path elimination
 * Block '<S66>/CheckSignalProperties' : Unused code path elimination
 * Block '<S75>/CheckSignalProperties' : Unused code path elimination
 * Block '<S76>/CheckSignalProperties' : Unused code path elimination
 * Block '<S8>/Unit Delay1' : Unused code path elimination
 * Block '<S9>/Gain' : Unused code path elimination
 * Block '<S9>/Gain1' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S104>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S114>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Data Type Propagation' : Unused code path elimination
 * Block '<S156>/Scope' : Unused code path elimination
 * Block '<S158>/Scope' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Propagation' : Unused code path elimination
 * Block '<S159>/Scope' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Propagation' : Unused code path elimination
 * Block '<S177>/Scope' : Unused code path elimination
 * Block '<S179>/Scope' : Unused code path elimination
 * Block '<S196>/Data Type Duplicate' : Unused code path elimination
 * Block '<S196>/Data Type Propagation' : Unused code path elimination
 * Block '<S180>/Scope' : Unused code path elimination
 * Block '<S206>/Data Type Duplicate' : Unused code path elimination
 * Block '<S206>/Data Type Propagation' : Unused code path elimination
 * Block '<S198>/Scope' : Unused code path elimination
 * Block '<S200>/Scope' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate' : Unused code path elimination
 * Block '<S217>/Data Type Propagation' : Unused code path elimination
 * Block '<S201>/Scope' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate' : Unused code path elimination
 * Block '<S227>/Data Type Propagation' : Unused code path elimination
 * Block '<S219>/Scope' : Unused code path elimination
 * Block '<S221>/Scope' : Unused code path elimination
 * Block '<S238>/Data Type Duplicate' : Unused code path elimination
 * Block '<S238>/Data Type Propagation' : Unused code path elimination
 * Block '<S222>/Scope' : Unused code path elimination
 * Block '<S249>/Data Type Duplicate' : Unused code path elimination
 * Block '<S249>/Data Type Propagation' : Unused code path elimination
 * Block '<S250>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Propagation' : Unused code path elimination
 * Block '<S260>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S266>/Data Type Duplicate' : Unused code path elimination
 * Block '<S266>/Data Type Propagation' : Unused code path elimination
 * Block '<S267>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S273>/Data Type Duplicate' : Unused code path elimination
 * Block '<S273>/Data Type Propagation' : Unused code path elimination
 * Block '<S269>/Scope' : Unused code path elimination
 * Block '<S313>/Data Type Duplicate' : Unused code path elimination
 * Block '<S313>/Data Type Propagation' : Unused code path elimination
 * Block '<S320>/Data Type Duplicate' : Unused code path elimination
 * Block '<S320>/Data Type Propagation' : Unused code path elimination
 * Block '<S321>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S77>/Conversion' : Eliminate redundant data type conversion
 * Block '<S78>/Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Conversion' : Eliminate redundant data type conversion
 * Block '<S34>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S50>/Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Reshape' : Reshape block reduction
 * Block '<S34>/ReshapeX0' : Reshape block reduction
 * Block '<S34>/Reshapexhat' : Reshape block reduction
 * Block '<S6>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S6>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S144>/Signal Copy' : Eliminate redundant signal conversion block
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
 * '<S8>'   : 'Robot_Control/Control_System/Previous GameState'
 * '<S9>'   : 'Robot_Control/Control_System/Spline_Path_Following'
 * '<S10>'  : 'Robot_Control/Control_System/Swerve_Drive'
 * '<S11>'  : 'Robot_Control/Control_System/Teleop'
 * '<S12>'  : 'Robot_Control/Control_System/Test'
 * '<S13>'  : 'Robot_Control/Control_System/Vision_Corrections'
 * '<S14>'  : 'Robot_Control/Control_System/Autonomous/Subsystem'
 * '<S15>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant'
 * '<S16>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant1'
 * '<S17>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant2'
 * '<S18>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant3'
 * '<S19>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant4'
 * '<S20>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant5'
 * '<S21>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant6'
 * '<S22>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant7'
 * '<S23>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Constant8'
 * '<S24>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero1'
 * '<S25>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero14'
 * '<S26>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero15'
 * '<S27>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero16'
 * '<S28>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero17'
 * '<S29>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero6'
 * '<S30>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Compare To Zero8'
 * '<S31>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase'
 * '<S32>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase1'
 * '<S33>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase2'
 * '<S34>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter'
 * '<S35>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL'
 * '<S36>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat'
 * '<S37>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator'
 * '<S38>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionA'
 * '<S39>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionB'
 * '<S40>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionC'
 * '<S41>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionD'
 * '<S42>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionG'
 * '<S43>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionH'
 * '<S44>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionN'
 * '<S45>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP'
 * '<S46>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionP0'
 * '<S47>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionQ'
 * '<S48>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionR'
 * '<S49>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionReset'
 * '<S50>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX'
 * '<S51>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionX0'
 * '<S52>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/DataTypeConversionu'
 * '<S53>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/MemoryP'
 * '<S54>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer'
 * '<S55>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN'
 * '<S56>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reset'
 * '<S57>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Reshapeyhat'
 * '<S58>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionP0'
 * '<S59>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionQ'
 * '<S60>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ScalarExpansionR'
 * '<S61>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator'
 * '<S62>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkA'
 * '<S63>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkB'
 * '<S64>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkC'
 * '<S65>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkD'
 * '<S66>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkEnable'
 * '<S67>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkG'
 * '<S68>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkH'
 * '<S69>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkN'
 * '<S70>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkP0'
 * '<S71>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkQ'
 * '<S72>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkR'
 * '<S73>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkReset'
 * '<S74>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checkX0'
 * '<S75>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checku'
 * '<S76>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/checky'
 * '<S77>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S78>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S79>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S80>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S81>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculatePL/Ground'
 * '<S82>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CalculateYhat/Ground'
 * '<S83>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S84>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S85>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Observer/MeasurementUpdate'
 * '<S86>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/ReducedQRN/Ground'
 * '<S87>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S88>'  : 'Robot_Control/Control_System/Previous GameState/Chart'
 * '<S89>'  : 'Robot_Control/Control_System/Spline_Path_Following/Pass Through'
 * '<S90>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled'
 * '<S91>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S92>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S93>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S94>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S95>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S96>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S97>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S98>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S99>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S100>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S101>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S102>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S103>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S104>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S105>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S106>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S107>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S108>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S109>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S110>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S111>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S112>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S113>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S114>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S115>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S116>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S117>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S118>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S119>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S120>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S121>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S122>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S123>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S124>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S125>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S126>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S127>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S128>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S129>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S130>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S131>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S132>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S133>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S134>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S135>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S136>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S137>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S138>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S139>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S140>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S141>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S142>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S143>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S144>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S145>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S146>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S147>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S148>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S149>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S150>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module'
 * '<S151>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1'
 * '<S152>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2'
 * '<S153>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3'
 * '<S154>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S155>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S156>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable'
 * '<S157>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S158>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S159>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S160>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S161>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S162>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Difference'
 * '<S163>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S164>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S165>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S166>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S167>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S168>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S169>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S170>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S171>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S172>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S173>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S174>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S175>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S176>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S177>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable'
 * '<S178>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S179>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S180>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S181>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S182>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S183>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Difference'
 * '<S184>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S185>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S186>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S187>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S188>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S189>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S190>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S191>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S192>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S193>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S194>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S195>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S196>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S197>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S198>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable'
 * '<S199>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S200>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S201>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S202>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S203>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S204>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Difference'
 * '<S205>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S206>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S207>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S208>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S209>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S210>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S211>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S212>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S213>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S214>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S215>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S216>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S217>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S218>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S219>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable'
 * '<S220>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S221>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S222>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S223>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S224>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S225>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Difference'
 * '<S226>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S227>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S228>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S229>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S230>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S231>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S232>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S233>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S234>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S235>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S236>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S237>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S238>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S239>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S240>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S241>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S242>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S243>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S244>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S245>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S246>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S247>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S248>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S249>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S250>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S251>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S252>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1'
 * '<S253>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S254>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S255>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S256>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S257>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S258>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S259>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S260>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S261>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero'
 * '<S262>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero1'
 * '<S263>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero2'
 * '<S264>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero3'
 * '<S265>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter'
 * '<S266>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S267>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S268>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S269>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S270>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S271>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S272>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S273>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S274>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S275>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Reduce Speeds for Maximum Speed Limit'
 * '<S276>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S277>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S278>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S279>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S280>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S281>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S282>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S283>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S284>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S285>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S286>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S287>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S288>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S289>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S290>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S291>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S292>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S293>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S294>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S295>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S296>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S297>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S298>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S299>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S300>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S301>' : 'Robot_Control/Control_System/Teleop/Relative Errors'
 * '<S302>' : 'Robot_Control/Control_System/Teleop/Subsystem'
 * '<S303>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S304>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S305>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Compare To Zero2'
 * '<S306>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase'
 * '<S307>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase1'
 * '<S308>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase2'
 * '<S309>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase3'
 * '<S310>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase4'
 * '<S311>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase5'
 * '<S312>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Previous active game state was not Teleop'
 * '<S313>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Saturation Dynamic'
 * '<S314>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S315>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero'
 * '<S316>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero1'
 * '<S317>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S318>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S319>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S320>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S321>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S322>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S323>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S324>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant'
 * '<S325>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant1'
 * '<S326>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant2'
 * '<S327>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero6'
 * '<S328>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero7'
 * '<S329>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero8'
 * '<S330>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance'
 * '<S331>' : 'Robot_Control/Control_System/Vision_Corrections/Degrees to Radians'
 * '<S332>' : 'Robot_Control/Control_System/Vision_Corrections/Polar to Cartesian1'
 * '<S333>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Prevent raising 0 to a negative exponent'
 * '<S334>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Subsystem'
 */
#endif                                 /* RTW_HEADER_Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
