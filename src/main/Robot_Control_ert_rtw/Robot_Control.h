/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 7.4
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Fri Oct 30 20:22:18 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Robot_Control_h_
#define Robot_Control_h_
#ifndef Robot_Control_COMMON_INCLUDES_
#define Robot_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Robot_Control_COMMON_INCLUDES_ */

#include "Robot_Control_types.h"
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
  real_T Steer_Joystick_Y;             /* '<S4>/Signal Copy5' */
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
  real_T Translation_Speed_RL;         /* '<S245>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S9>/Merge3' */
  real_T Gyro_Angle_SPF;               /* '<S9>/Merge8' */
  real_T Translation_Steering_Cmd;     /* '<S239>/Switch' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S9>/Merge' */
  real_T Steering_Heading_Error_deg;   /* '<S271>/Gain' */
  real_T Steering_Heading_PID;         /* '<S267>/Saturation2' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S9>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S238>/Switch' */
  real_T BR_Desired_Wheel_Speed_in;    /* '<S294>/Switch1' */
  real_T FL_Desired_Wheel_Speed_in;    /* '<S279>/Switch1' */
  real_T FR_Desired_Wheel_Speed_in;    /* '<S284>/Switch1' */
  real_T BL_Desired_Wheel_Speed_in;    /* '<S289>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S274>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S294>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S274>/Product' */
  real_T FL_Desired_Module_Angle;      /* '<S279>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S274>/Product1' */
  real_T FR_Desired_Module_Angle;      /* '<S284>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S274>/Product2' */
  real_T BL_Desired_Module_Angle;      /* '<S289>/Switch' */
  real_T Spline_Index;                 /* '<S9>/Merge6' */
  real_T loop_counter_robot_control;   /* '<S1>/Sum' */
  real_T Steer_Joystick_X;             /* '<S4>/Signal Copy4' */
  real_T Relative_Error_Y;             /* '<S300>/Switch2' */
  real_T Relative_Error_X;             /* '<S300>/Unary Minus1' */
  real_T Relative_Error_Angle;         /* '<S300>/Switch4' */
  real_T Steering_Abs_Gyro_Latch;      /* '<S302>/Switch8' */
  real_T Steering_Abs_Gyro;            /* '<S302>/Switch2' */
  real_T Steering_Abs_Angle;           /* '<S302>/Switch3' */
  real_T Auto_Path_ID;                 /* '<S16>/1-D Lookup Table1' */
  real_T Auto_Desired_Static_Action;   /* '<S16>/Chart' */
  real_T Auto_Desired_Dynamic_Action;  /* '<S16>/Chart' */
  real_T Auto_Path_Counter;            /* '<S16>/Chart' */
  real_T abs_Cmd_Out;                  /* '<S250>/Add dither' */
  real_T Spline_Follow_Index;          /* '<S92>/Merge4' */
  real_T Spline_Target_Y;              /* '<S89>/Selector6' */
  real_T Spline_Target_X;              /* '<S89>/Selector2' */
  real_T Assignment[450];              /* '<S114>/Assignment' */
  real_T Product3[2];                  /* '<S79>/Product3' */
  real_T Product2[2];                  /* '<S61>/Product2' */
  uint16_T WhileIterator;              /* '<S139>/While Iterator' */
  uint8_T Active_GameState;            /* '<S8>/Chart' */
  boolean_T Button_Enable_Wheels;      /* '<S22>/FixPt Relational Operator' */
  boolean_T Button_Reset_Wheel_Offsets;/* '<S23>/FixPt Relational Operator' */
  boolean_T Button_Disable_Wheels;     /* '<S24>/FixPt Relational Operator' */
  boolean_T Spline_Enable;             /* '<S7>/Merge7' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S9>/Merge4' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S9>/Merge5' */
  boolean_T Robot_Reached_Destination; /* '<S9>/Merge7' */
  boolean_T Test_Mode;                 /* '<S7>/Merge10' */
  boolean_T Relative_Enable;           /* '<S300>/Logical Operator1' */
  boolean_T Steering_Abs_Angle_Active; /* '<S302>/AND6' */
  boolean_T Auto_Spline_Enable;        /* '<S16>/Chart' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S92>/Merge1' */
} B_Robot_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S22>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S23>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S24>/Delay Input1' */
  real_T UnitDelay2_DSTATE;            /* '<S5>/Unit Delay2' */
  real_T TappedDelay_X[2];             /* '<S6>/Tapped Delay' */
  real_T TappedDelay1_X[2];            /* '<S6>/Tapped Delay1' */
  real_T Delay_DSTATE[2];              /* '<S78>/Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S270>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S269>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S267>/Unit Delay' */
  real_T UnitDelay_DSTATE_d4;          /* '<S249>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_e;     /* '<S264>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S248>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_p;     /* '<S257>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S223>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S222>/UD' */
  real_T UnitDelay1_DSTATE_i;          /* '<S234>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S233>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S219>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S160>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S159>/UD' */
  real_T UnitDelay1_DSTATE_b;          /* '<S171>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S170>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S156>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S181>/Unit Delay1' */
  real_T UD_DSTATE_m;                  /* '<S180>/UD' */
  real_T UnitDelay1_DSTATE_n;          /* '<S192>/Unit Delay1' */
  real_T UD_DSTATE_i;                  /* '<S191>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S177>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n4;         /* '<S202>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S201>/UD' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S213>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S212>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S198>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S320>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S316>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S316>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S302>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_j2;         /* '<S302>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_iz[60];     /* '<S16>/Unit Delay1' */
  real_T UnitDelay_DSTATE_e3;          /* '<S16>/Unit Delay' */
  real_T UnitDelay_DSTATE_gh;          /* '<S88>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S87>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f4;         /* '<S140>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g4;          /* '<S140>/Unit Delay' */
  real_T UnitDelay_DSTATE_le;          /* '<S90>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S90>/Unit Delay1' */
  real_T counter;                      /* '<S16>/Chart' */
  real_T timer;                        /* '<S250>/Add dither' */
  void *MatrixConcatenate_PWORK;       /* '<S109>/Matrix Concatenate' */
  int32_T Selector5_DIMS1[2];          /* '<S109>/Selector5' */
  int32_T MatrixConcatenate_DIMS1[2];  /* '<S109>/Matrix Concatenate' */
  int32_T Selector4_DIMS1[2];          /* '<S109>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S247>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_p;    /* '<S264>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S257>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S320>/FixPt Unit Delay2' */
  boolean_T UnitDelay1_DSTATE_nl;      /* '<S5>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_ll;       /* '<S5>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ir;       /* '<S12>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S310>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S309>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S305>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S306>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S307>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g2;     /* '<S308>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE_l;       /* '<S302>/Unit Delay2' */
  boolean_T UnitDelay4_DSTATE;         /* '<S302>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_e4;       /* '<S95>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S100>/Unit Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S9>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S92>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S95>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S97>/If' */
  uint8_T is_active_c6_Robot_Control;  /* '<S16>/Chart' */
  uint8_T is_c6_Robot_Control;         /* '<S16>/Chart' */
  uint8_T is_active_c7_Robot_Control;  /* '<S250>/Add dither' */
  uint8_T is_c7_Robot_Control;         /* '<S250>/Add dither' */
  uint8_T is_Dither;                   /* '<S250>/Add dither' */
  uint8_T is_active_c9_Robot_Control;  /* '<S8>/Chart' */
  uint8_T is_c9_Robot_Control;         /* '<S8>/Chart' */
  boolean_T icLoad;                    /* '<S78>/Delay' */
  boolean_T Relay_Mode;                /* '<S122>/Relay' */
  boolean_T MeasurementUpdate_MODE;    /* '<S77>/MeasurementUpdate' */
} DW_Robot_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S164>/Cos5' */
  const real_T Sin5;                   /* '<S164>/Sin5' */
  const real_T Cos5_g;                 /* '<S185>/Cos5' */
  const real_T Sin5_m;                 /* '<S185>/Sin5' */
  const real_T Cos5_i;                 /* '<S206>/Cos5' */
  const real_T Sin5_e;                 /* '<S206>/Sin5' */
  const real_T Cos5_b;                 /* '<S227>/Cos5' */
  const real_T Sin5_c;                 /* '<S227>/Sin5' */
  const real_T Width;                  /* '<S16>/Width' */
  const real_T Atan2;                  /* '<S237>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S237>/Add' */
  const real_T Atan1;                  /* '<S237>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S237>/Add1' */
  const real_T Atan3;                  /* '<S237>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S237>/Add2' */
  const real_T Atan4;                  /* '<S237>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S237>/Add3' */
} ConstB_Robot_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T GameState;                    /* '<Root>/GameState' */
  real_T IsBlueAlliance;               /* '<Root>/IsBlueAlliance' */
  real_T MatchTime;                    /* '<Root>/MatchTime' */
  real_T Xbox_Driver_Stick_Left_X;     /* '<Root>/Xbox_Driver_Stick_Left_X' */
  real_T Xbox_Driver_Stick_Left_Y;     /* '<Root>/Xbox_Driver_Stick_Left_Y' */
  real_T Xbox_Driver_Stick_Right_X;    /* '<Root>/Xbox_Driver_Stick_Right_X' */
  real_T Xbox_Driver_Stick_Right_Y;    /* '<Root>/Xbox_Driver_Stick_Right_Y' */
  real_T Xbox_Driver_Bumper_Left;      /* '<Root>/Xbox_Driver_Bumper_Left' */
  real_T Xbox_Driver_Bumper_Right;     /* '<Root>/Xbox_Driver_Bumper_Right' */
  real_T Xbox_Driver_Trigger_Left;     /* '<Root>/Xbox_Driver_Trigger_Left' */
  real_T Xbox_Driver_Trigger_Right;    /* '<Root>/Xbox_Driver_Trigger_Right' */
  boolean_T Xbox_Driver_ButtonA;       /* '<Root>/Xbox_Driver_ButtonA' */
  boolean_T Xbox_Driver_ButtonB;       /* '<Root>/Xbox_Driver_ButtonB' */
  boolean_T Xbox_Driver_ButtonX;       /* '<Root>/Xbox_Driver_ButtonX' */
  boolean_T Xbox_Driver_ButtonY;       /* '<Root>/Xbox_Driver_ButtonY' */
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
                                        * Referenced by: '<S17>/Constant17'
                                        */
extern real_T Boost_Trigger_Decreasing_Limit;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S317>/Constant1'
                                      */
extern real_T Boost_Trigger_High_Speed;/* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S313>/Constant'
                                        *   '<S313>/Saturation'
                                        */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S317>/Constant3'
                                      */
extern real_T Boost_Trigger_Low_Speed; /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S313>/Constant1'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S153>/Constant3'
                                        *   '<S174>/Constant3'
                                        *   '<S195>/Constant3'
                                        *   '<S216>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S153>/Constant2'
                                   *   '<S174>/Constant2'
                                   *   '<S195>/Constant2'
                                   *   '<S216>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S153>/Saturation'
                                        *   '<S174>/Saturation'
                                        *   '<S195>/Saturation'
                                        *   '<S216>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S153>/Saturation'
                                        *   '<S174>/Saturation'
                                        *   '<S195>/Saturation'
                                        *   '<S216>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S153>/Gain'
                                        *   '<S174>/Gain'
                                        *   '<S195>/Gain'
                                        *   '<S216>/Gain'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S153>/Gain1'
                                        *   '<S174>/Gain1'
                                        *   '<S195>/Gain1'
                                        *   '<S216>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S158>/Constant'
                            *   '<S179>/Constant'
                            *   '<S200>/Constant'
                            *   '<S221>/Constant'
                            */
extern real_T Field_Translation_Control_Gain;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S303>/Gain2'
                                      */
extern real_T Field_Translation_Speed_Max;/* Variable: Field_Translation_Speed_Max
                                           * Referenced by: '<S303>/Constant5'
                                           */
extern real_T KF_Enable;               /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S6>/Constant2'
                                        */
extern real_T Relative_Steering_Error_Angle_Gain;
                                 /* Variable: Relative_Steering_Error_Angle_Gain
                                  * Referenced by: '<S302>/Constant4'
                                  */
extern real_T Relative_Steering_Error_Angle_Gain_Object_Factor;
                   /* Variable: Relative_Steering_Error_Angle_Gain_Object_Factor
                    * Referenced by: '<S300>/Gain'
                    */
extern real_T Relative_Steering_Speed_Max;/* Variable: Relative_Steering_Speed_Max
                                           * Referenced by: '<S302>/Constant10'
                                           */
extern real_T Relative_Translation_Control_Gain;
                                  /* Variable: Relative_Translation_Control_Gain
                                   * Referenced by: '<S303>/Gain1'
                                   */
extern real_T Relative_Translation_Speed_Max;
                                     /* Variable: Relative_Translation_Speed_Max
                                      * Referenced by: '<S303>/Constant8'
                                      */
extern real_T Spline_Last_Pose_Distance_to_Velocity_Gain;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S142>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S142>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S89>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S102>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S142>/Constant3'
                                     */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S249>/Constant5'
                    */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S249>/Constant6'
                    */
extern real_T Steering_Absolute_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S249>/Constant9'
                          */
extern real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S249>/Constant10'
                    */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S249>/Constant1'
                                */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S249>/Constant3'
                                */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S267>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S267>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S267>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S267>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S266>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S267>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S267>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S267>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S267>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S267>/Constant1'
                                   *   '<S267>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S267>/Constant'
                                   *   '<S267>/Saturation2'
                                   */
extern real_T Steering_Heading_Dither_Gain;/* Variable: Steering_Heading_Dither_Gain
                                            * Referenced by: '<S250>/Add dither'
                                            */
extern real_T Steering_Heading_Dither_Period;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S250>/Add dither'
                                      */
extern real_T Steering_Heading_Dither_Thresh_Off;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S250>/Add dither'
                                  */
extern real_T Steering_Heading_Dither_Thresh_On;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S250>/Add dither'
                                   */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S156>/Constant3'
                                        *   '<S177>/Constant3'
                                        *   '<S198>/Constant3'
                                        *   '<S219>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S156>/Constant2'
                                *   '<S177>/Constant2'
                                *   '<S198>/Constant2'
                                *   '<S219>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S156>/Saturation'
                                           *   '<S177>/Saturation'
                                           *   '<S198>/Saturation'
                                           *   '<S219>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S156>/Saturation'
                                           *   '<S177>/Saturation'
                                           *   '<S198>/Saturation'
                                           *   '<S219>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S156>/Gain2'
                                        *   '<S177>/Gain2'
                                        *   '<S198>/Gain2'
                                        *   '<S219>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S156>/Saturation1'
                                           *   '<S177>/Saturation1'
                                           *   '<S198>/Saturation1'
                                           *   '<S219>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S156>/Saturation1'
                                           *   '<S177>/Saturation1'
                                           *   '<S198>/Saturation1'
                                           *   '<S219>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S156>/Gain1'
                                        *   '<S177>/Gain1'
                                        *   '<S198>/Gain1'
                                        *   '<S219>/Gain1'
                                        */
extern real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S248>/Constant5'
                    */
extern real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S248>/Constant6'
                    */
extern real_T Steering_Relative_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S248>/Constant9'
                          */
extern real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S248>/Constant10'
                    */
extern real_T Steering_Relative_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S248>/Constant1'
                                */
extern real_T Steering_Relative_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S248>/Constant3'
                                */
extern real_T Steering_Relative_Gain;  /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S302>/Constant'
                                        */
extern real_T Steering_Twist_Gain;     /* Variable: Steering_Twist_Gain
                                        * Referenced by: '<S302>/Constant1'
                                        */
extern real_T TEST_Swerve_Mode_Override_Flag;
                                     /* Variable: TEST_Swerve_Mode_Override_Flag
                                      * Referenced by: '<S301>/Constant5'
                                      */
extern real_T TEST_Swerve_Mode_Steering;/* Variable: TEST_Swerve_Mode_Steering
                                         * Referenced by: '<S301>/Constant8'
                                         */
extern real_T TEST_Swerve_Mode_Translation;/* Variable: TEST_Swerve_Mode_Translation
                                            * Referenced by: '<S301>/Constant7'
                                            */
extern real_T Translation_Speed_Approach_Zero_Error_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S236>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S236>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S236>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S236>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S236>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S236>/Constant3'
                                    */
extern real_T Translation_Twist_Gain;  /* Variable: Translation_Twist_Gain
                                        * Referenced by: '<S303>/Gain'
                                        */
extern real_T Twist_Deadzone_neg;      /* Variable: Twist_Deadzone_neg
                                        * Referenced by:
                                        *   '<S302>/Dead Zone'
                                        *   '<S303>/Dead Zone'
                                        */
extern real_T Twist_Deadzone_pos;      /* Variable: Twist_Deadzone_pos
                                        * Referenced by:
                                        *   '<S302>/Dead Zone'
                                        *   '<S303>/Dead Zone'
                                        */
extern real_T Vision_Object_Angle_Offset;/* Variable: Vision_Object_Angle_Offset
                                          * Referenced by: '<S13>/Constant6'
                                          */
extern real_T Vision_Object_Target_Angle;/* Variable: Vision_Object_Target_Angle
                                          * Referenced by: '<S300>/Constant7'
                                          */
extern real_T Vision_Object_Target_X;  /* Variable: Vision_Object_Target_X
                                        * Referenced by: '<S300>/Constant1'
                                        */
extern real_T Vision_Object_Target_Y;  /* Variable: Vision_Object_Target_Y
                                        * Referenced by: '<S300>/Constant4'
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
                                        * Referenced by: '<S300>/Constant8'
                                        */
extern real_T Vision_Tag_Target_X;     /* Variable: Vision_Tag_Target_X
                                        * Referenced by: '<S300>/Constant2'
                                        */
extern real_T Vision_Tag_Target_Y;     /* Variable: Vision_Tag_Target_Y
                                        * Referenced by: '<S300>/Constant5'
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
                                        *   '<S300>/Constant11'
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
 * Block '<S15>/Unit Delay1' : Unused code path elimination
 * Block '<S18>/Switch' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S42>/Conversion' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Conversion' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Conversion' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Nbar' : Unused code path elimination
 * Block '<S51>/Qbar' : Unused code path elimination
 * Block '<S51>/Rbar' : Unused code path elimination
 * Block '<S25>/D' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Conversion' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Conversion' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Conversion' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Conversion' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Conversion' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Conversion' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Conversion' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Add1' : Unused code path elimination
 * Block '<S57>/Conversion' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Constant' : Unused code path elimination
 * Block '<S55>/Product' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Constant2' : Unused code path elimination
 * Block '<S73>/Constant3' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Conversion' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Conversion' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Delay' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/G' : Unused code path elimination
 * Block '<S25>/H' : Unused code path elimination
 * Block '<S25>/N' : Unused code path elimination
 * Block '<S25>/P0' : Unused code path elimination
 * Block '<S25>/Q' : Unused code path elimination
 * Block '<S25>/R' : Unused code path elimination
 * Block '<S25>/Reset' : Unused code path elimination
 * Block '<S25>/Reshape1' : Unused code path elimination
 * Block '<S8>/Unit Delay1' : Unused code path elimination
 * Block '<S101>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S111>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S145>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Propagation' : Unused code path elimination
 * Block '<S153>/Scope' : Unused code path elimination
 * Block '<S155>/Scope' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Propagation' : Unused code path elimination
 * Block '<S156>/Scope' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Propagation' : Unused code path elimination
 * Block '<S174>/Scope' : Unused code path elimination
 * Block '<S176>/Scope' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Propagation' : Unused code path elimination
 * Block '<S177>/Scope' : Unused code path elimination
 * Block '<S203>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Data Type Propagation' : Unused code path elimination
 * Block '<S195>/Scope' : Unused code path elimination
 * Block '<S197>/Scope' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Data Type Propagation' : Unused code path elimination
 * Block '<S198>/Scope' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S224>/Data Type Propagation' : Unused code path elimination
 * Block '<S216>/Scope' : Unused code path elimination
 * Block '<S218>/Scope' : Unused code path elimination
 * Block '<S235>/Data Type Duplicate' : Unused code path elimination
 * Block '<S235>/Data Type Propagation' : Unused code path elimination
 * Block '<S219>/Scope' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate' : Unused code path elimination
 * Block '<S246>/Data Type Propagation' : Unused code path elimination
 * Block '<S247>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S256>/Data Type Duplicate' : Unused code path elimination
 * Block '<S256>/Data Type Propagation' : Unused code path elimination
 * Block '<S257>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S263>/Data Type Duplicate' : Unused code path elimination
 * Block '<S263>/Data Type Propagation' : Unused code path elimination
 * Block '<S264>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S272>/Data Type Duplicate' : Unused code path elimination
 * Block '<S272>/Data Type Propagation' : Unused code path elimination
 * Block '<S267>/Scope' : Unused code path elimination
 * Block '<S312>/Data Type Duplicate' : Unused code path elimination
 * Block '<S312>/Data Type Propagation' : Unused code path elimination
 * Block '<S319>/Data Type Duplicate' : Unused code path elimination
 * Block '<S319>/Data Type Propagation' : Unused code path elimination
 * Block '<S320>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S4>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S27>/Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Conversion' : Eliminate redundant data type conversion
 * Block '<S34>/Conversion' : Eliminate redundant data type conversion
 * Block '<S62>/Conversion' : Eliminate redundant data type conversion
 * Block '<S68>/Conversion' : Eliminate redundant data type conversion
 * Block '<S69>/Conversion' : Eliminate redundant data type conversion
 * Block '<S75>/Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Conversion' : Eliminate redundant data type conversion
 * Block '<S77>/Reshape' : Reshape block reduction
 * Block '<S25>/Reshape' : Reshape block reduction
 * Block '<S25>/Reshape4' : Reshape block reduction
 * Block '<S6>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S6>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S141>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S147>/Constant' : Unused code path elimination
 * Block '<S153>/Constant' : Unused code path elimination
 * Block '<S153>/Constant1' : Unused code path elimination
 * Block '<S153>/Gain2' : Unused code path elimination
 * Block '<S161>/LowerRelop1' : Unused code path elimination
 * Block '<S161>/Switch' : Unused code path elimination
 * Block '<S161>/Switch2' : Unused code path elimination
 * Block '<S161>/UpperRelop' : Unused code path elimination
 * Block '<S153>/Saturation1' : Unused code path elimination
 * Block '<S153>/Subtract' : Unused code path elimination
 * Block '<S153>/Subtract1' : Unused code path elimination
 * Block '<S153>/Sum2' : Unused code path elimination
 * Block '<S153>/Unit Delay' : Unused code path elimination
 * Block '<S148>/Constant' : Unused code path elimination
 * Block '<S174>/Constant' : Unused code path elimination
 * Block '<S174>/Constant1' : Unused code path elimination
 * Block '<S174>/Gain2' : Unused code path elimination
 * Block '<S182>/LowerRelop1' : Unused code path elimination
 * Block '<S182>/Switch' : Unused code path elimination
 * Block '<S182>/Switch2' : Unused code path elimination
 * Block '<S182>/UpperRelop' : Unused code path elimination
 * Block '<S174>/Saturation1' : Unused code path elimination
 * Block '<S174>/Subtract' : Unused code path elimination
 * Block '<S174>/Subtract1' : Unused code path elimination
 * Block '<S174>/Sum2' : Unused code path elimination
 * Block '<S174>/Unit Delay' : Unused code path elimination
 * Block '<S149>/Constant' : Unused code path elimination
 * Block '<S195>/Constant' : Unused code path elimination
 * Block '<S195>/Constant1' : Unused code path elimination
 * Block '<S195>/Gain2' : Unused code path elimination
 * Block '<S203>/LowerRelop1' : Unused code path elimination
 * Block '<S203>/Switch' : Unused code path elimination
 * Block '<S203>/Switch2' : Unused code path elimination
 * Block '<S203>/UpperRelop' : Unused code path elimination
 * Block '<S195>/Saturation1' : Unused code path elimination
 * Block '<S195>/Subtract' : Unused code path elimination
 * Block '<S195>/Subtract1' : Unused code path elimination
 * Block '<S195>/Sum2' : Unused code path elimination
 * Block '<S195>/Unit Delay' : Unused code path elimination
 * Block '<S150>/Constant' : Unused code path elimination
 * Block '<S216>/Constant' : Unused code path elimination
 * Block '<S216>/Constant1' : Unused code path elimination
 * Block '<S216>/Gain2' : Unused code path elimination
 * Block '<S224>/LowerRelop1' : Unused code path elimination
 * Block '<S224>/Switch' : Unused code path elimination
 * Block '<S224>/Switch2' : Unused code path elimination
 * Block '<S224>/UpperRelop' : Unused code path elimination
 * Block '<S216>/Saturation1' : Unused code path elimination
 * Block '<S216>/Subtract' : Unused code path elimination
 * Block '<S216>/Subtract1' : Unused code path elimination
 * Block '<S216>/Sum2' : Unused code path elimination
 * Block '<S216>/Unit Delay' : Unused code path elimination
 * Block '<S11>/Constant16' : Unused code path elimination
 * Block '<S303>/Constant3' : Unused code path elimination
 * Block '<S300>/Constant10' : Unused code path elimination
 * Block '<S300>/Constant9' : Unused code path elimination
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
 * '<S15>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic'
 * '<S16>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Autonomous Paths and Actions'
 * '<S17>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Subsystem'
 * '<S18>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Take Action'
 * '<S19>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Autonomous Paths and Actions/Chart'
 * '<S20>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Align to nearest cardinal angle'
 * '<S21>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Angle Modulus'
 * '<S22>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase'
 * '<S23>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase1'
 * '<S24>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase2'
 * '<S25>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter'
 * '<S26>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar'
 * '<S27>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited'
 * '<S28>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited1'
 * '<S29>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited10'
 * '<S30>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited11'
 * '<S31>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited2'
 * '<S32>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited3'
 * '<S33>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited4'
 * '<S34>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited5'
 * '<S35>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited6'
 * '<S36>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited7'
 * '<S37>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited8'
 * '<S38>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited9'
 * '<S39>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter'
 * '<S40>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Square Covariance'
 * '<S41>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Varying P0'
 * '<S42>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Data Type Conversion Inherited'
 * '<S43>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Data Type Conversion Inherited1'
 * '<S44>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Data Type Conversion Inherited2'
 * '<S45>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying Q'
 * '<S46>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying QRN'
 * '<S47>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying QRNbar'
 * '<S48>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying R'
 * '<S49>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying Q/Invariant'
 * '<S50>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying QRN/Invariant'
 * '<S51>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying QRNbar/Invariant'
 * '<S52>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying R/Invariant'
 * '<S53>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values'
 * '<S54>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator'
 * '<S55>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/Compute Yhat'
 * '<S56>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator'
 * '<S57>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/Compute Yhat/Data Type Conversion Inherited'
 * '<S58>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/Compute Yhat/Feedthrough'
 * '<S59>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/Compute Yhat/Feedthrough/No Feedthrough'
 * '<S60>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current'
 * '<S61>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current/Enabled Subsystem'
 * '<S62>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current/Enabled Subsystem/Data Type Conversion Inherited'
 * '<S63>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current/Enabled Subsystem/Feedthrough'
 * '<S64>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current/Enabled Subsystem/Feedthrough/No Feedthrough'
 * '<S65>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains'
 * '<S66>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer'
 * '<S67>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Calculate PL'
 * '<S68>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Data Type Conversion Inherited'
 * '<S69>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Data Type Conversion Inherited1'
 * '<S70>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Data Type Conversion Inherited2'
 * '<S71>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Data Type Conversion Inherited3'
 * '<S72>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/IDP'
 * '<S73>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Calculate PL/Constant'
 * '<S74>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/IDP/DT'
 * '<S75>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Data Type Conversion Inherited'
 * '<S76>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/IDX'
 * '<S77>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer'
 * '<S78>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/IDX/DT'
 * '<S79>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer/MeasurementUpdate'
 * '<S80>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer/MeasurementUpdate/Data Type Conversion Inherited'
 * '<S81>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer/MeasurementUpdate/Feedthrough'
 * '<S82>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer/MeasurementUpdate/Feedthrough/No Feedthrough'
 * '<S83>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Square Covariance/Normal'
 * '<S84>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Varying P0/Invariant'
 * '<S85>'  : 'Robot_Control/Control_System/Previous GameState/Chart'
 * '<S86>'  : 'Robot_Control/Control_System/Spline_Path_Following/Pass Through'
 * '<S87>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled'
 * '<S88>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S89>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S90>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S91>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S92>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S93>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S94>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S95>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S96>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S97>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S98>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S99>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S100>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S101>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S102>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S103>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S104>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S105>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S106>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S107>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S108>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S109>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S110>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S111>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S112>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S113>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S114>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S115>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S116>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S117>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S118>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S119>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S120>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S121>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S122>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S123>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S124>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S125>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S126>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S127>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S128>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S129>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S130>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S131>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S132>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S133>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S134>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S135>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S136>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S137>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S138>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S139>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S140>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S141>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S142>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S143>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S144>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S145>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S146>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S147>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module'
 * '<S148>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1'
 * '<S149>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2'
 * '<S150>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3'
 * '<S151>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S152>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S153>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable'
 * '<S154>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S155>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S156>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S157>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S158>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S159>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Difference'
 * '<S160>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S161>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S162>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S163>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S164>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S165>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S166>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S167>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S168>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S169>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S170>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S171>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S172>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S173>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S174>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable'
 * '<S175>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S176>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S177>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S178>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S179>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S180>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Difference'
 * '<S181>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S182>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S183>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S184>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S185>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S186>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S187>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S188>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S189>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S190>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S191>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S192>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S193>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S194>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S195>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable'
 * '<S196>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S197>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S198>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S199>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S200>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S201>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Difference'
 * '<S202>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S203>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S204>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S205>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S206>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S207>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S208>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S209>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S210>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S211>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S212>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S213>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S214>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S215>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S216>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable'
 * '<S217>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S218>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S219>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S220>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S221>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S222>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Difference'
 * '<S223>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S224>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S225>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S226>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S227>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S228>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S229>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S230>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S231>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S232>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S233>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S234>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S235>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S236>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S237>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S238>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S239>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S240>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S241>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S242>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S243>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S244>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S245>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S246>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S247>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S248>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S249>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1'
 * '<S250>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S251>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S252>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S253>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S254>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S255>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S256>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S257>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S258>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero'
 * '<S259>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero1'
 * '<S260>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero2'
 * '<S261>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero3'
 * '<S262>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter'
 * '<S263>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S264>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S265>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Add dither'
 * '<S266>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S267>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S268>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S269>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S270>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S271>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Radians to Degrees'
 * '<S272>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S273>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S274>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Reduce Speeds for Maximum Speed Limit'
 * '<S275>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S276>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S277>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S278>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S279>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S280>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S281>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S282>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S283>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S284>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S285>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S286>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S287>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S288>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S289>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S290>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S291>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S292>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S293>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S294>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S295>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S296>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S297>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S298>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S299>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S300>' : 'Robot_Control/Control_System/Teleop/Relative Errors'
 * '<S301>' : 'Robot_Control/Control_System/Teleop/Subsystem'
 * '<S302>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S303>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S304>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Compare To Zero2'
 * '<S305>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase'
 * '<S306>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase1'
 * '<S307>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase2'
 * '<S308>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase3'
 * '<S309>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase4'
 * '<S310>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Detect Increase5'
 * '<S311>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Previous active game state was not Teleop'
 * '<S312>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Saturation Dynamic'
 * '<S313>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S314>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero'
 * '<S315>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Compare To Zero1'
 * '<S316>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S317>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S318>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S319>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S320>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S321>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S322>' : 'Robot_Control/Control_System/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S323>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant'
 * '<S324>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant1'
 * '<S325>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Constant2'
 * '<S326>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero6'
 * '<S327>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero7'
 * '<S328>' : 'Robot_Control/Control_System/Teleop/Relative Errors/Compare To Zero8'
 * '<S329>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance'
 * '<S330>' : 'Robot_Control/Control_System/Vision_Corrections/Degrees to Radians'
 * '<S331>' : 'Robot_Control/Control_System/Vision_Corrections/Polar to Cartesian1'
 * '<S332>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Prevent raising 0 to a negative exponent'
 * '<S333>' : 'Robot_Control/Control_System/Vision_Corrections/Area Percentage to Distance/Subsystem'
 */
#endif                                 /* Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
