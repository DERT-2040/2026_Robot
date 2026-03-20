/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control_private.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.478
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Mar 19 19:32:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Robot_Control_private_h_
#define RTW_HEADER_Robot_Control_private_h_
#include "rtwtypes.h"
#include "Robot_Control.h"
#include "Robot_Control_types.h"

extern const real_T rtCP_pooled_mZW03emckTZz[4];
extern const real_T rtCP_pooled_Por1fGzmcW36[4];
extern const real_T rtCP_pooled_INwGxsZyA2TK[4];
extern const real_T rtCP_pooled_GGVx5MaBv7ss[780];
extern const real_T rtCP_pooled_3YCYwI7khtXS[780];
extern const real_T rtCP_pooled_0QbCPVYx7Xol[13];
extern const real_T rtCP_pooled_mVxns4hAKRNf[21];
extern const real_T rtCP_pooled_wsH2dcaSihoN[21];
extern const real_T rtCP_pooled_MtklTCiS35sn[21];
extern const real_T rtCP_pooled_pwqtSNbEs40J[21];
extern const real_T rtCP_pooled_O4lHSDP8vPjo[2];
extern const real_T rtCP_pooled_Ha5Ct2ozjCBu[2];

#define rtCP_CaptureRadius_tableData   rtCP_pooled_mZW03emckTZz  /* Expression: Spline_Capture_Radius
                                                                  * Referenced by: '<S196>/Capture Radius'
                                                                  */
#define rtCP_CaptureRadius_bp01Data    rtCP_pooled_Por1fGzmcW36  /* Expression: Spline_Velocity_Axis
                                                                  * Referenced by: '<S196>/Capture Radius'
                                                                  */
#define rtCP_LookaheadDistance_tableDat rtCP_pooled_INwGxsZyA2TK /* Expression: Spline_Lookahead_Dist
                                                                  * Referenced by: '<S196>/Lookahead Distance'
                                                                  */
#define rtCP_LookaheadDistance_bp01Data rtCP_pooled_Por1fGzmcW36 /* Expression: Spline_Velocity_Axis
                                                                  * Referenced by: '<S196>/Lookahead Distance'
                                                                  */
#define rtCP_Constant_Value_c          rtCP_pooled_GGVx5MaBv7ss  /* Expression: All_Paths_Ref_Poses_Blue
                                                                  * Referenced by: '<S20>/Constant'
                                                                  */
#define rtCP_Constant1_Value_bc        rtCP_pooled_3YCYwI7khtXS  /* Expression: All_Paths_Ref_Poses_Red
                                                                  * Referenced by: '<S20>/Constant1'
                                                                  */
#define rtCP_uDLookupTable_tableData   rtCP_pooled_0QbCPVYx7Xol  /* Expression: All_Paths_Num_Poses
                                                                  * Referenced by: '<S20>/1-D Lookup Table'
                                                                  */
#define rtCP_Modulation_Str_Y_Rel_table rtCP_pooled_mVxns4hAKRNf /* Expression: Steering_Mod_Str_Rel_out
                                                                  * Referenced by: '<S417>/Modulation_Str_Y_Rel'
                                                                  */
#define rtCP_Modulation_Str_Y_Rel_bp01D rtCP_pooled_wsH2dcaSihoN /* Expression: Steering_Mod_Str_Rel_in
                                                                  * Referenced by: '<S417>/Modulation_Str_Y_Rel'
                                                                  */
#define rtCP_Modulation_Drv_tableData  rtCP_pooled_MtklTCiS35sn  /* Expression: Steering_Mod_Drv_out
                                                                  * Referenced by: '<S418>/Modulation_Drv'
                                                                  */
#define rtCP_Modulation_Drv_bp01Data   rtCP_pooled_pwqtSNbEs40J  /* Expression: Steering_Mod_Drv_in
                                                                  * Referenced by: '<S418>/Modulation_Drv'
                                                                  */
#define rtCP_uDLookupTable_tableData_g rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S327>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S327>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_j rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S264>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_h  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S264>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_gs rtCP_pooled_O4lHSDP8vPjo /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S285>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_p  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S285>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_h rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S306>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_j  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S306>/1-D Lookup Table'
                                                                  */

extern void Robot_C_IfActionSubsystem1_Init(DW_IfActionSubsystem1_Robot_C_T
  *localDW);
extern void Robot_Contro_IfActionSubsystem1(real_T rtu_IsBlueInactiveFirst,
  real_T rtu_IsBlueAlliance, boolean_T *rty_IsBlueActive, boolean_T
  *rty_IsRedActive, real_T *rty_Time_Remaining, DW_IfActionSubsystem1_Robot_C_T *
  localDW);

#endif                                 /* RTW_HEADER_Robot_Control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
