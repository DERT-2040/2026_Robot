/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control_private.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.460
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Mar  1 19:25:20 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Robot_Control_private_h_
#define RTW_HEADER_Robot_Control_private_h_
#include "rtwtypes.h"
#include "Robot_Control_types.h"
#include "Robot_Control.h"

extern const real_T rtCP_pooled_mZW03emckTZz[4];
extern const real_T rtCP_pooled_Por1fGzmcW36[4];
extern const real_T rtCP_pooled_INwGxsZyA2TK[4];
extern const real_T rtCP_pooled_jyEP69xrmSuL[60];
extern const real_T rtCP_pooled_mVxns4hAKRNf[21];
extern const real_T rtCP_pooled_wsH2dcaSihoN[21];
extern const real_T rtCP_pooled_MtklTCiS35sn[21];
extern const real_T rtCP_pooled_pwqtSNbEs40J[21];
extern const real_T rtCP_pooled_O4lHSDP8vPjo[2];
extern const real_T rtCP_pooled_Ha5Ct2ozjCBu[2];

#define rtCP_CaptureRadius_tableData   rtCP_pooled_mZW03emckTZz  /* Expression: Spline_Capture_Radius
                                                                  * Referenced by: '<S150>/Capture Radius'
                                                                  */
#define rtCP_CaptureRadius_bp01Data    rtCP_pooled_Por1fGzmcW36  /* Expression: Spline_Velocity_Axis
                                                                  * Referenced by: '<S150>/Capture Radius'
                                                                  */
#define rtCP_LookaheadDistance_tableDat rtCP_pooled_INwGxsZyA2TK /* Expression: Spline_Lookahead_Dist
                                                                  * Referenced by: '<S150>/Lookahead Distance'
                                                                  */
#define rtCP_LookaheadDistance_bp01Data rtCP_pooled_Por1fGzmcW36 /* Expression: Spline_Velocity_Axis
                                                                  * Referenced by: '<S150>/Lookahead Distance'
                                                                  */
#define rtCP_Constant8_Value_o         rtCP_pooled_jyEP69xrmSuL  /* Expression: Spline_Ref_Poses_default
                                                                  * Referenced by: '<S4>/Constant8'
                                                                  */
#define rtCP_Constant8_Value_m         rtCP_pooled_jyEP69xrmSuL  /* Expression: Spline_Ref_Poses_default
                                                                  * Referenced by: '<S18>/Constant8'
                                                                  */
#define rtCP_Constant4_Value_i         rtCP_pooled_jyEP69xrmSuL  /* Expression: Spline_Ref_Poses_default
                                                                  * Referenced by: '<S15>/Constant4'
                                                                  */
#define rtCP_Modulation_Str_Y_Rel_table rtCP_pooled_mVxns4hAKRNf /* Expression: Steering_Mod_Str_Rel_out
                                                                  * Referenced by: '<S367>/Modulation_Str_Y_Rel'
                                                                  */
#define rtCP_Modulation_Str_Y_Rel_bp01D rtCP_pooled_wsH2dcaSihoN /* Expression: Steering_Mod_Str_Rel_in
                                                                  * Referenced by: '<S367>/Modulation_Str_Y_Rel'
                                                                  */
#define rtCP_Modulation_Drv_tableData  rtCP_pooled_MtklTCiS35sn  /* Expression: Steering_Mod_Drv_out
                                                                  * Referenced by: '<S368>/Modulation_Drv'
                                                                  */
#define rtCP_Modulation_Drv_bp01Data   rtCP_pooled_pwqtSNbEs40J  /* Expression: Steering_Mod_Drv_in
                                                                  * Referenced by: '<S368>/Modulation_Drv'
                                                                  */
#define rtCP_Constant8_Value_h         rtCP_pooled_jyEP69xrmSuL  /* Expression: Spline_Ref_Poses_default
                                                                  * Referenced by: '<S16>/Constant8'
                                                                  */
#define rtCP_uDLookupTable_tableData   rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S281>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S281>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_j rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S218>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_h  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S218>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_g rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S239>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_p  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S239>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_h rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S260>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_j  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S260>/1-D Lookup Table'
                                                                  */

extern void Robot_Control_IfActionSubsystem(boolean_T *rty_IsBlueActive,
  boolean_T *rty_IsRedActive);
extern void Robot_Contro_IfActionSubsystem1(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive);
extern void Robot_Contro_IfActionSubsystem2(boolean_T rtu_IsBlueInactiveFirst,
  boolean_T *rty_IsBlueActive, boolean_T *rty_IsRedActive);

#endif                                 /* RTW_HEADER_Robot_Control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
