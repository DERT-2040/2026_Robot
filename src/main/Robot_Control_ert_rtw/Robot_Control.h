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
 * C/C++ source code generated on : Sat Oct 31 16:19:21 2026
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
  real_T Drive_Joystick_X;             /* '<S5>/Signal Copy1' */
  real_T Drive_Joystick_Y;             /* '<S5>/Signal Copy2' */
  real_T Steer_Joystick_Y;             /* '<S5>/Signal Copy5' */
  real_T Vision_c1_AprilTag_Corr_X_inch;/* '<S14>/Add' */
  real_T Vision_c1_AprilTag_Corr_Y_inch;/* '<S14>/Add1' */
  real_T Vision_c1_AprilTag_Corr_Yaw_deg;/* '<S14>/Add2' */
  real_T Vision_c1_Object_Corr_X_inch; /* '<S14>/Add3' */
  real_T Vision_c1_Object_Corr_Y_inch; /* '<S14>/Add4' */
  real_T Vision_c1_Object_Corr_Yaw_deg;/* '<S14>/Add5' */
  real_T KF_Position_X;                /* '<S7>/Switch' */
  real_T KF_Position_Y;                /* '<S7>/Switch1' */
  real_T Spline_Num_Poses;             /* '<S8>/Merge9' */
  real_T Steering_Abs_Cmd;             /* '<S8>/Merge1' */
  real_T Steering_Rel_Cmd;             /* '<S8>/Merge2' */
  real_T Translation_Speed;            /* '<S8>/Merge4' */
  real_T Translation_Angle;            /* '<S8>/Merge3' */
  real_T Translation_Speed_SPF;        /* '<S10>/Merge2' */
  real_T Translation_Speed_RL;         /* '<S246>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S10>/Merge3' */
  real_T Gyro_Angle_SPF;               /* '<S10>/Merge8' */
  real_T Translation_Steering_Cmd;     /* '<S240>/Switch' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S10>/Merge' */
  real_T Steering_Heading_Error_deg;   /* '<S272>/Gain' */
  real_T Steering_Heading_PID;         /* '<S268>/Saturation2' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S10>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S239>/Switch' */
  real_T BR_Desired_Wheel_Speed_in;    /* '<S295>/Switch1' */
  real_T FL_Desired_Wheel_Speed_in;    /* '<S280>/Switch1' */
  real_T FR_Desired_Wheel_Speed_in;    /* '<S285>/Switch1' */
  real_T BL_Desired_Wheel_Speed_in;    /* '<S290>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S275>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S295>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S275>/Product' */
  real_T FL_Desired_Module_Angle;      /* '<S280>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S275>/Product1' */
  real_T FR_Desired_Module_Angle;      /* '<S285>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S275>/Product2' */
  real_T BL_Desired_Module_Angle;      /* '<S290>/Switch' */
  real_T Spline_Index;                 /* '<S10>/Merge6' */
  real_T loop_counter_robot_control;   /* '<S1>/Sum' */
  real_T Steer_Joystick_X;             /* '<S5>/Signal Copy4' */
  real_T Relative_Error_Y;             /* '<S301>/Switch2' */
  real_T Relative_Error_X;             /* '<S301>/Unary Minus1' */
  real_T Relative_Error_Angle;         /* '<S301>/Switch4' */
  real_T Steering_Abs_Gyro_Latch;      /* '<S303>/Switch8' */
  real_T Steering_Abs_Gyro;            /* '<S303>/Switch2' */
  real_T Steering_Abs_Angle;           /* '<S303>/Switch3' */
  real_T Auto_Path_ID;                 /* '<S17>/1-D Lookup Table1' */
  real_T Auto_Desired_Static_Action;   /* '<S17>/Chart' */
  real_T Auto_Desired_Dynamic_Action;  /* '<S17>/Chart' */
  real_T Auto_Path_Counter;            /* '<S17>/Chart' */
  real_T abs_Cmd_Out;                  /* '<S251>/Add dither' */
  real_T Spline_Follow_Index;          /* '<S93>/Merge4' */
  real_T Spline_Target_Y;              /* '<S90>/Selector6' */
  real_T Spline_Target_X;              /* '<S90>/Selector2' */
  real_T Assignment[450];              /* '<S115>/Assignment' */
  real_T Product3[2];                  /* '<S80>/Product3' */
  real_T Product2[2];                  /* '<S62>/Product2' */
  uint16_T WhileIterator;              /* '<S140>/While Iterator' */
  uint8_T Active_GameState;            /* '<S9>/Chart' */
  boolean_T Button_Enable_Wheels;      /* '<S23>/FixPt Relational Operator' */
  boolean_T Button_Reset_Wheel_Offsets;/* '<S24>/FixPt Relational Operator' */
  boolean_T Button_Disable_Wheels;     /* '<S25>/FixPt Relational Operator' */
  boolean_T Spline_Enable;             /* '<S8>/Merge7' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S10>/Merge4' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S10>/Merge5' */
  boolean_T Robot_Reached_Destination; /* '<S10>/Merge7' */
  boolean_T Test_Mode;                 /* '<S8>/Merge10' */
  boolean_T Relative_Enable;           /* '<S301>/Logical Operator1' */
  boolean_T Steering_Abs_Angle_Active; /* '<S303>/AND6' */
  boolean_T Auto_Spline_Enable;        /* '<S17>/Chart' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S93>/Merge1' */
} B_Robot_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S23>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S24>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S25>/Delay Input1' */
  real_T UnitDelay2_DSTATE;            /* '<S6>/Unit Delay2' */
  real_T TappedDelay_X[2];             /* '<S7>/Tapped Delay' */
  real_T TappedDelay1_X[2];            /* '<S7>/Tapped Delay1' */
  real_T Delay_DSTATE[2];              /* '<S79>/Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S271>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S270>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S268>/Unit Delay' */
  real_T UnitDelay_DSTATE_d4;          /* '<S250>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_e;     /* '<S265>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S249>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_p;     /* '<S258>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_j;          /* '<S224>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S223>/UD' */
  real_T UnitDelay1_DSTATE_i;          /* '<S235>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S234>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S220>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S161>/Unit Delay1' */
  real_T UD_DSTATE_h;                  /* '<S160>/UD' */
  real_T UnitDelay1_DSTATE_b;          /* '<S172>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S171>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S157>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S182>/Unit Delay1' */
  real_T UD_DSTATE_m;                  /* '<S181>/UD' */
  real_T UnitDelay1_DSTATE_n;          /* '<S193>/Unit Delay1' */
  real_T UD_DSTATE_i;                  /* '<S192>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S178>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n4;         /* '<S203>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S202>/UD' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S214>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S213>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S199>/Unit Delay' */
  real_T UnitDelay_DSTATE_id;          /* '<S336>/Unit Delay' */
  real_T UnitDelay_DSTATE_n;           /* '<S337>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S321>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S317>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S317>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S303>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_j2;         /* '<S303>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_iz[60];     /* '<S17>/Unit Delay1' */
  real_T UnitDelay_DSTATE_e3;          /* '<S17>/Unit Delay' */
  real_T UnitDelay_DSTATE_gh;          /* '<S89>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S88>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f4;         /* '<S141>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g4;          /* '<S141>/Unit Delay' */
  real_T UnitDelay_DSTATE_le;          /* '<S91>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S91>/Unit Delay1' */
  real_T counter;                      /* '<S17>/Chart' */
  real_T timer;                        /* '<S251>/Add dither' */
  void *MatrixConcatenate_PWORK;       /* '<S110>/Matrix Concatenate' */
  int32_T Selector5_DIMS1[2];          /* '<S110>/Selector5' */
  int32_T MatrixConcatenate_DIMS1[2];  /* '<S110>/Matrix Concatenate' */
  int32_T Selector4_DIMS1[2];          /* '<S110>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S248>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_p;    /* '<S265>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S258>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S321>/FixPt Unit Delay2' */
  boolean_T UnitDelay1_DSTATE_nl;      /* '<S6>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_ll;       /* '<S6>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ir;       /* '<S13>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S311>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S310>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S306>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S307>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S308>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g2;     /* '<S309>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE_l;       /* '<S303>/Unit Delay2' */
  boolean_T UnitDelay4_DSTATE;         /* '<S303>/Unit Delay4' */
  boolean_T UnitDelay_DSTATE_e4;       /* '<S96>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_nu;       /* '<S101>/Unit Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S10>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S93>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S96>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S98>/If' */
  uint8_T is_active_c6_Robot_Control;  /* '<S17>/Chart' */
  uint8_T is_c6_Robot_Control;         /* '<S17>/Chart' */
  uint8_T is_active_c7_Robot_Control;  /* '<S251>/Add dither' */
  uint8_T is_c7_Robot_Control;         /* '<S251>/Add dither' */
  uint8_T is_Dither;                   /* '<S251>/Add dither' */
  uint8_T is_active_c9_Robot_Control;  /* '<S9>/Chart' */
  uint8_T is_c9_Robot_Control;         /* '<S9>/Chart' */
  boolean_T icLoad;                    /* '<S79>/Delay' */
  boolean_T Relay_Mode;                /* '<S123>/Relay' */
  boolean_T MeasurementUpdate_MODE;    /* '<S78>/MeasurementUpdate' */
} DW_Robot_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S165>/Cos5' */
  const real_T Sin5;                   /* '<S165>/Sin5' */
  const real_T Cos5_g;                 /* '<S186>/Cos5' */
  const real_T Sin5_m;                 /* '<S186>/Sin5' */
  const real_T Cos5_i;                 /* '<S207>/Cos5' */
  const real_T Sin5_e;                 /* '<S207>/Sin5' */
  const real_T Cos5_b;                 /* '<S228>/Cos5' */
  const real_T Sin5_c;                 /* '<S228>/Sin5' */
  const real_T Width;                  /* '<S17>/Width' */
  const real_T Atan2;                  /* '<S238>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S238>/Add' */
  const real_T Atan1;                  /* '<S238>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S238>/Add1' */
  const real_T Atan3;                  /* '<S238>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S238>/Add2' */
  const real_T Atan4;                  /* '<S238>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S238>/Add3' */
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
  real_T Wrist_Motor_Left_Revs;        /* '<Root>/Wrist_Motor_Left_Revs' */
  real_T Wrist_Motor_Right_Revs;       /* '<Root>/Wrist_Motor_Right_Revs' */
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
  real_T Wrist_Motor_Left_DC;          /* '<Root>/Wrist_Motor_Left_DC' */
  real_T Wrist_Motor_Right_DC;         /* '<Root>/Wrist_Motor_Right_DC' */
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
                                        * Referenced by: '<S18>/Constant17'
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
extern real_T Desired_Pitch_Angle_LL;  /* Variable: Desired_Pitch_Angle_LL
                                        * Referenced by: '<S337>/Saturation'
                                        */
extern real_T Desired_Pitch_Angle_UL;  /* Variable: Desired_Pitch_Angle_UL
                                        * Referenced by: '<S337>/Saturation'
                                        */
extern real_T Desired_Roll_Angle_LL;   /* Variable: Desired_Roll_Angle_LL
                                        * Referenced by: '<S336>/Saturation'
                                        */
extern real_T Desired_Roll_Angle_UL;   /* Variable: Desired_Roll_Angle_UL
                                        * Referenced by: '<S336>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S154>/Constant3'
                                        *   '<S175>/Constant3'
                                        *   '<S196>/Constant3'
                                        *   '<S217>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S154>/Constant2'
                                   *   '<S175>/Constant2'
                                   *   '<S196>/Constant2'
                                   *   '<S217>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S154>/Saturation'
                                        *   '<S175>/Saturation'
                                        *   '<S196>/Saturation'
                                        *   '<S217>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S154>/Saturation'
                                        *   '<S175>/Saturation'
                                        *   '<S196>/Saturation'
                                        *   '<S217>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S154>/Gain'
                                        *   '<S175>/Gain'
                                        *   '<S196>/Gain'
                                        *   '<S217>/Gain'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S154>/Gain1'
                                        *   '<S175>/Gain1'
                                        *   '<S196>/Gain1'
                                        *   '<S217>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S159>/Constant'
                            *   '<S180>/Constant'
                            *   '<S201>/Constant'
                            *   '<S222>/Constant'
                            */
extern real_T Field_Translation_Control_Gain;
                                     /* Variable: Field_Translation_Control_Gain
                                      * Referenced by: '<S304>/Gain2'
                                      */
extern real_T Field_Translation_Speed_Max;/* Variable: Field_Translation_Speed_Max
                                           * Referenced by: '<S304>/Constant5'
                                           */
extern real_T Gamepad_Pitch_Gain;      /* Variable: Gamepad_Pitch_Gain
                                        * Referenced by: '<S337>/Gain'
                                        */
extern real_T Gamepad_Roll_Gain;       /* Variable: Gamepad_Roll_Gain
                                        * Referenced by: '<S336>/Gain'
                                        */
extern real_T KF_Enable;               /* Variable: KF_Enable
                                        * Referenced by:
                                        *   '<S7>/Constant1'
                                        *   '<S7>/Constant2'
                                        */
extern real_T Kp_motor_angle;          /* Variable: Kp_motor_angle
                                        * Referenced by:
                                        *   '<S335>/Gain'
                                        *   '<S335>/Gain1'
                                        */
extern real_T R_motor_gearbox;         /* Variable: R_motor_gearbox
                                        * Referenced by:
                                        *   '<S335>/Constant'
                                        *   '<S335>/Constant2'
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
                          * Referenced by: '<S143>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S143>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S90>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S103>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S143>/Constant3'
                                     */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S250>/Constant5'
                    */
extern real_T Steering_Absolute_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Absolute_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S250>/Constant6'
                    */
extern real_T Steering_Absolute_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Absolute_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S250>/Constant9'
                          */
extern real_T Steering_Absolute_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Absolute_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S250>/Constant10'
                    */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S250>/Constant1'
                                */
extern real_T Steering_Absolute_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Absolute_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S250>/Constant3'
                                */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S268>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S268>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S268>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S268>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S267>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S268>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S268>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S268>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S268>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S268>/Constant1'
                                   *   '<S268>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S268>/Constant'
                                   *   '<S268>/Saturation2'
                                   */
extern real_T Steering_Heading_Dither_Gain;/* Variable: Steering_Heading_Dither_Gain
                                            * Referenced by: '<S251>/Add dither'
                                            */
extern real_T Steering_Heading_Dither_Period;
                                     /* Variable: Steering_Heading_Dither_Period
                                      * Referenced by: '<S251>/Add dither'
                                      */
extern real_T Steering_Heading_Dither_Thresh_Off;
                                 /* Variable: Steering_Heading_Dither_Thresh_Off
                                  * Referenced by: '<S251>/Add dither'
                                  */
extern real_T Steering_Heading_Dither_Thresh_On;
                                  /* Variable: Steering_Heading_Dither_Thresh_On
                                   * Referenced by: '<S251>/Add dither'
                                   */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S157>/Constant3'
                                        *   '<S178>/Constant3'
                                        *   '<S199>/Constant3'
                                        *   '<S220>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S157>/Constant2'
                                *   '<S178>/Constant2'
                                *   '<S199>/Constant2'
                                *   '<S220>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S157>/Saturation'
                                           *   '<S178>/Saturation'
                                           *   '<S199>/Saturation'
                                           *   '<S220>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S157>/Saturation'
                                           *   '<S178>/Saturation'
                                           *   '<S199>/Saturation'
                                           *   '<S220>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S157>/Gain2'
                                        *   '<S178>/Gain2'
                                        *   '<S199>/Gain2'
                                        *   '<S220>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S157>/Saturation1'
                                           *   '<S178>/Saturation1'
                                           *   '<S199>/Saturation1'
                                           *   '<S220>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S157>/Saturation1'
                                           *   '<S178>/Saturation1'
                                           *   '<S199>/Saturation1'
                                           *   '<S220>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S157>/Gain1'
                                        *   '<S178>/Gain1'
                                        *   '<S199>/Gain1'
                                        *   '<S220>/Gain1'
                                        */
extern real_T Steering_Relative_Cmd_Approach_Zero_Error_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Error_Thresh
                    * Referenced by: '<S249>/Constant5'
                    */
extern real_T Steering_Relative_Cmd_Approach_Zero_Final_Thresh;
                   /* Variable: Steering_Relative_Cmd_Approach_Zero_Final_Thresh
                    * Referenced by: '<S249>/Constant6'
                    */
extern real_T Steering_Relative_Cmd_NonZero_Error_Thresh;
                         /* Variable: Steering_Relative_Cmd_NonZero_Error_Thresh
                          * Referenced by: '<S249>/Constant9'
                          */
extern real_T Steering_Relative_Cmd_NonZero_Final_Scale_Factor;
                   /* Variable: Steering_Relative_Cmd_NonZero_Final_Scale_Factor
                    * Referenced by: '<S249>/Constant10'
                    */
extern real_T Steering_Relative_Cmd_Rate_Limit_Dec;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Dec
                                * Referenced by: '<S249>/Constant1'
                                */
extern real_T Steering_Relative_Cmd_Rate_Limit_Inc;
                               /* Variable: Steering_Relative_Cmd_Rate_Limit_Inc
                                * Referenced by: '<S249>/Constant3'
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
                        * Referenced by: '<S237>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S237>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S237>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S237>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S237>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S237>/Constant3'
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
                                          * Referenced by: '<S14>/Constant6'
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
                                        * Referenced by: '<S14>/Constant4'
                                        */
extern real_T Vision_Object_Y_Offset;  /* Variable: Vision_Object_Y_Offset
                                        * Referenced by: '<S14>/Constant8'
                                        */
extern real_T Vision_Tag_Angle_Offset; /* Variable: Vision_Tag_Angle_Offset
                                        * Referenced by: '<S14>/Constant5'
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
                                        * Referenced by: '<S14>/Constant3'
                                        */
extern real_T Vision_Tag_Y_Offset;     /* Variable: Vision_Tag_Y_Offset
                                        * Referenced by: '<S14>/Constant7'
                                        */
extern uint8_T TEST_Pipeline;          /* Variable: TEST_Pipeline
                                        * Referenced by:
                                        *   '<S13>/Constant22'
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
 * Block '<S16>/Unit Delay1' : Unused code path elimination
 * Block '<S19>/Switch' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S43>/Conversion' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Conversion' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Conversion' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Nbar' : Unused code path elimination
 * Block '<S52>/Qbar' : Unused code path elimination
 * Block '<S52>/Rbar' : Unused code path elimination
 * Block '<S26>/D' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Conversion' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Conversion' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Conversion' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Conversion' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Conversion' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Conversion' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Conversion' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Add1' : Unused code path elimination
 * Block '<S58>/Conversion' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Constant' : Unused code path elimination
 * Block '<S56>/Product' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Constant2' : Unused code path elimination
 * Block '<S74>/Constant3' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Conversion' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Conversion' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Delay' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/G' : Unused code path elimination
 * Block '<S26>/H' : Unused code path elimination
 * Block '<S26>/N' : Unused code path elimination
 * Block '<S26>/P0' : Unused code path elimination
 * Block '<S26>/Q' : Unused code path elimination
 * Block '<S26>/R' : Unused code path elimination
 * Block '<S26>/Reset' : Unused code path elimination
 * Block '<S26>/Reshape1' : Unused code path elimination
 * Block '<S9>/Unit Delay1' : Unused code path elimination
 * Block '<S102>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S146>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Propagation' : Unused code path elimination
 * Block '<S154>/Scope' : Unused code path elimination
 * Block '<S156>/Scope' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Propagation' : Unused code path elimination
 * Block '<S157>/Scope' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Propagation' : Unused code path elimination
 * Block '<S175>/Scope' : Unused code path elimination
 * Block '<S177>/Scope' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Propagation' : Unused code path elimination
 * Block '<S178>/Scope' : Unused code path elimination
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
 * Block '<S247>/Data Type Duplicate' : Unused code path elimination
 * Block '<S247>/Data Type Propagation' : Unused code path elimination
 * Block '<S248>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate' : Unused code path elimination
 * Block '<S257>/Data Type Propagation' : Unused code path elimination
 * Block '<S258>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S264>/Data Type Duplicate' : Unused code path elimination
 * Block '<S264>/Data Type Propagation' : Unused code path elimination
 * Block '<S265>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S273>/Data Type Duplicate' : Unused code path elimination
 * Block '<S273>/Data Type Propagation' : Unused code path elimination
 * Block '<S268>/Scope' : Unused code path elimination
 * Block '<S313>/Data Type Duplicate' : Unused code path elimination
 * Block '<S313>/Data Type Propagation' : Unused code path elimination
 * Block '<S320>/Data Type Duplicate' : Unused code path elimination
 * Block '<S320>/Data Type Propagation' : Unused code path elimination
 * Block '<S321>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S5>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S28>/Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Conversion' : Eliminate redundant data type conversion
 * Block '<S33>/Conversion' : Eliminate redundant data type conversion
 * Block '<S35>/Conversion' : Eliminate redundant data type conversion
 * Block '<S63>/Conversion' : Eliminate redundant data type conversion
 * Block '<S69>/Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Conversion' : Eliminate redundant data type conversion
 * Block '<S81>/Conversion' : Eliminate redundant data type conversion
 * Block '<S78>/Reshape' : Reshape block reduction
 * Block '<S26>/Reshape' : Reshape block reduction
 * Block '<S26>/Reshape4' : Reshape block reduction
 * Block '<S7>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S7>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S142>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S148>/Constant' : Unused code path elimination
 * Block '<S154>/Constant' : Unused code path elimination
 * Block '<S154>/Constant1' : Unused code path elimination
 * Block '<S154>/Gain2' : Unused code path elimination
 * Block '<S162>/LowerRelop1' : Unused code path elimination
 * Block '<S162>/Switch' : Unused code path elimination
 * Block '<S162>/Switch2' : Unused code path elimination
 * Block '<S162>/UpperRelop' : Unused code path elimination
 * Block '<S154>/Saturation1' : Unused code path elimination
 * Block '<S154>/Subtract' : Unused code path elimination
 * Block '<S154>/Subtract1' : Unused code path elimination
 * Block '<S154>/Sum2' : Unused code path elimination
 * Block '<S154>/Unit Delay' : Unused code path elimination
 * Block '<S149>/Constant' : Unused code path elimination
 * Block '<S175>/Constant' : Unused code path elimination
 * Block '<S175>/Constant1' : Unused code path elimination
 * Block '<S175>/Gain2' : Unused code path elimination
 * Block '<S183>/LowerRelop1' : Unused code path elimination
 * Block '<S183>/Switch' : Unused code path elimination
 * Block '<S183>/Switch2' : Unused code path elimination
 * Block '<S183>/UpperRelop' : Unused code path elimination
 * Block '<S175>/Saturation1' : Unused code path elimination
 * Block '<S175>/Subtract' : Unused code path elimination
 * Block '<S175>/Subtract1' : Unused code path elimination
 * Block '<S175>/Sum2' : Unused code path elimination
 * Block '<S175>/Unit Delay' : Unused code path elimination
 * Block '<S150>/Constant' : Unused code path elimination
 * Block '<S196>/Constant' : Unused code path elimination
 * Block '<S196>/Constant1' : Unused code path elimination
 * Block '<S196>/Gain2' : Unused code path elimination
 * Block '<S204>/LowerRelop1' : Unused code path elimination
 * Block '<S204>/Switch' : Unused code path elimination
 * Block '<S204>/Switch2' : Unused code path elimination
 * Block '<S204>/UpperRelop' : Unused code path elimination
 * Block '<S196>/Saturation1' : Unused code path elimination
 * Block '<S196>/Subtract' : Unused code path elimination
 * Block '<S196>/Subtract1' : Unused code path elimination
 * Block '<S196>/Sum2' : Unused code path elimination
 * Block '<S196>/Unit Delay' : Unused code path elimination
 * Block '<S151>/Constant' : Unused code path elimination
 * Block '<S217>/Constant' : Unused code path elimination
 * Block '<S217>/Constant1' : Unused code path elimination
 * Block '<S217>/Gain2' : Unused code path elimination
 * Block '<S225>/LowerRelop1' : Unused code path elimination
 * Block '<S225>/Switch' : Unused code path elimination
 * Block '<S225>/Switch2' : Unused code path elimination
 * Block '<S225>/UpperRelop' : Unused code path elimination
 * Block '<S217>/Saturation1' : Unused code path elimination
 * Block '<S217>/Subtract' : Unused code path elimination
 * Block '<S217>/Subtract1' : Unused code path elimination
 * Block '<S217>/Sum2' : Unused code path elimination
 * Block '<S217>/Unit Delay' : Unused code path elimination
 * Block '<S12>/Constant16' : Unused code path elimination
 * Block '<S304>/Constant3' : Unused code path elimination
 * Block '<S301>/Constant10' : Unused code path elimination
 * Block '<S301>/Constant9' : Unused code path elimination
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
 * '<S2>'   : 'Robot_Control/Subsystem'
 * '<S3>'   : 'Robot_Control/Control_System/Autonomous'
 * '<S4>'   : 'Robot_Control/Control_System/Disabled'
 * '<S5>'   : 'Robot_Control/Control_System/Human_Input_Pre_Processing'
 * '<S6>'   : 'Robot_Control/Control_System/Internal Feedback'
 * '<S7>'   : 'Robot_Control/Control_System/Kalman_Filter'
 * '<S8>'   : 'Robot_Control/Control_System/Merge'
 * '<S9>'   : 'Robot_Control/Control_System/Previous GameState'
 * '<S10>'  : 'Robot_Control/Control_System/Spline_Path_Following'
 * '<S11>'  : 'Robot_Control/Control_System/Swerve_Drive'
 * '<S12>'  : 'Robot_Control/Control_System/Teleop'
 * '<S13>'  : 'Robot_Control/Control_System/Test'
 * '<S14>'  : 'Robot_Control/Control_System/Vision_Corrections'
 * '<S15>'  : 'Robot_Control/Control_System/Autonomous/Subsystem'
 * '<S16>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Action Complete Logic'
 * '<S17>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Autonomous Paths and Actions'
 * '<S18>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Subsystem'
 * '<S19>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Take Action'
 * '<S20>'  : 'Robot_Control/Control_System/Autonomous/Subsystem/Autonomous Paths and Actions/Chart'
 * '<S21>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Align to nearest cardinal angle'
 * '<S22>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Angle Modulus'
 * '<S23>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase'
 * '<S24>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase1'
 * '<S25>'  : 'Robot_Control/Control_System/Human_Input_Pre_Processing/Detect Increase2'
 * '<S26>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter'
 * '<S27>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar'
 * '<S28>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited'
 * '<S29>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited1'
 * '<S30>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited10'
 * '<S31>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited11'
 * '<S32>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited2'
 * '<S33>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited3'
 * '<S34>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited4'
 * '<S35>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited5'
 * '<S36>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited6'
 * '<S37>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited7'
 * '<S38>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited8'
 * '<S39>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Data Type Conversion Inherited9'
 * '<S40>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter'
 * '<S41>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Square Covariance'
 * '<S42>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Varying P0'
 * '<S43>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Data Type Conversion Inherited'
 * '<S44>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Data Type Conversion Inherited1'
 * '<S45>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Data Type Conversion Inherited2'
 * '<S46>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying Q'
 * '<S47>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying QRN'
 * '<S48>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying QRNbar'
 * '<S49>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying R'
 * '<S50>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying Q/Invariant'
 * '<S51>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying QRN/Invariant'
 * '<S52>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying QRNbar/Invariant'
 * '<S53>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Compute QRNbar/Varying R/Invariant'
 * '<S54>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values'
 * '<S55>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator'
 * '<S56>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/Compute Yhat'
 * '<S57>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator'
 * '<S58>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/Compute Yhat/Data Type Conversion Inherited'
 * '<S59>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/Compute Yhat/Feedthrough'
 * '<S60>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/Compute Yhat/Feedthrough/No Feedthrough'
 * '<S61>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current'
 * '<S62>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current/Enabled Subsystem'
 * '<S63>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current/Enabled Subsystem/Data Type Conversion Inherited'
 * '<S64>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current/Enabled Subsystem/Feedthrough'
 * '<S65>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Calculate Current Values/UseCurrentEstimator/Current/Enabled Subsystem/Feedthrough/No Feedthrough'
 * '<S66>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains'
 * '<S67>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer'
 * '<S68>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Calculate PL'
 * '<S69>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Data Type Conversion Inherited'
 * '<S70>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Data Type Conversion Inherited1'
 * '<S71>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Data Type Conversion Inherited2'
 * '<S72>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Data Type Conversion Inherited3'
 * '<S73>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/IDP'
 * '<S74>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/Calculate PL/Constant'
 * '<S75>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/Calculate Gains/IDP/DT'
 * '<S76>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Data Type Conversion Inherited'
 * '<S77>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/IDX'
 * '<S78>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer'
 * '<S79>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/IDX/DT'
 * '<S80>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer/MeasurementUpdate'
 * '<S81>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer/MeasurementUpdate/Data Type Conversion Inherited'
 * '<S82>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer/MeasurementUpdate/Feedthrough'
 * '<S83>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Filter/Estimator/State Observer/Observer/MeasurementUpdate/Feedthrough/No Feedthrough'
 * '<S84>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Square Covariance/Normal'
 * '<S85>'  : 'Robot_Control/Control_System/Kalman_Filter/Kalman Filter/Varying P0/Invariant'
 * '<S86>'  : 'Robot_Control/Control_System/Previous GameState/Chart'
 * '<S87>'  : 'Robot_Control/Control_System/Spline_Path_Following/Pass Through'
 * '<S88>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled'
 * '<S89>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S90>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S91>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S92>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S93>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S94>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S95>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S96>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S97>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S98>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S99>'  : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S100>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S101>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S102>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S103>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S104>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S105>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S106>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S107>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S108>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S109>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S110>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S111>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S112>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S113>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S114>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S115>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S116>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S117>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S118>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S119>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S120>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S121>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S122>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S123>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S124>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S125>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S126>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S127>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S128>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S129>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S130>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S131>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S132>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S133>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S134>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S135>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S136>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S137>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S138>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S139>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S140>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S141>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S142>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S143>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S144>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S145>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S146>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S147>' : 'Robot_Control/Control_System/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S148>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module'
 * '<S149>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1'
 * '<S150>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2'
 * '<S151>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3'
 * '<S152>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S153>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S154>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable'
 * '<S155>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S156>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S157>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S158>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S159>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S160>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Difference'
 * '<S161>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S162>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S163>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S164>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S165>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S166>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S167>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S168>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S169>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S170>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S171>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S172>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S173>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S174>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S175>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable'
 * '<S176>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S177>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S178>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S179>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S180>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S181>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Difference'
 * '<S182>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S183>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S184>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S185>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S186>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S187>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S188>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S189>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S190>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S191>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S192>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S193>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S194>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S195>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S196>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable'
 * '<S197>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S198>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S199>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S200>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S201>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S202>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Difference'
 * '<S203>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S204>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S205>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S206>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S207>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S208>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S209>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S210>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S211>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S212>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S213>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S214>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S215>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S216>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S217>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable'
 * '<S218>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S219>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S220>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S221>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S222>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S223>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Difference'
 * '<S224>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Low_Pass_Filter'
 * '<S225>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Feed Forward plus PID and Integral Enable/Saturation Dynamic'
 * '<S226>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S227>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S228>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S229>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S230>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S231>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S232>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S233>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S234>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S235>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S236>' : 'Robot_Control/Control_System/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S237>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S238>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S239>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S240>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S241>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S242>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S243>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S244>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S245>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S246>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S247>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S248>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S249>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S250>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1'
 * '<S251>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S252>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S253>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S254>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S255>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S256>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S257>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S258>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S259>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero'
 * '<S260>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero1'
 * '<S261>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero2'
 * '<S262>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Compare To Zero3'
 * '<S263>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter'
 * '<S264>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Saturation Dynamic'
 * '<S265>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit1/Discrete Rate Limiter/Unit Delay External IC'
 * '<S266>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Add dither'
 * '<S267>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S268>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S269>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S270>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S271>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S272>' : 'Robot_Control/Control_System/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Radians to Degrees'
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
 * '<S335>' : 'Robot_Control/Subsystem/Controller'
 * '<S336>' : 'Robot_Control/Subsystem/Subsystem'
 * '<S337>' : 'Robot_Control/Subsystem/Subsystem1'
 */
#endif                                 /* Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
