/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control_private.h
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 7.1
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Thu Oct 29 00:21:41 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Robot_Control_private_h_
#define Robot_Control_private_h_
#include "rtwtypes.h"
#include "Robot_Control_types.h"

extern const real_T rtCP_pooled_mZW03emckTZz[4];
extern const real_T rtCP_pooled_Por1fGzmcW36[4];
extern const real_T rtCP_pooled_INwGxsZyA2TK[4];
extern const real_T rtCP_pooled_Rjm7j3rS18VE[1500];
extern const real_T rtCP_pooled_8H9wYQ5Cr7gD[1500];
extern const real_T rtCP_pooled_qv7wsteWw1rp[25];
extern const real_T rtCP_pooled_pwqtSNbEs40J[21];
extern const real_T rtCP_pooled_wsH2dcaSihoN[21];
extern const real_T rtCP_pooled_O4lHSDP8vPjo[2];
extern const real_T rtCP_pooled_Ha5Ct2ozjCBu[2];

#define rtCP_CaptureRadius_tableData   rtCP_pooled_mZW03emckTZz  /* Expression: Spline_Capture_Radius
                                                                  * Referenced by: '<S215>/Capture Radius'
                                                                  */
#define rtCP_CaptureRadius_bp01Data    rtCP_pooled_Por1fGzmcW36  /* Expression: Spline_Velocity_Axis
                                                                  * Referenced by: '<S215>/Capture Radius'
                                                                  */
#define rtCP_LookaheadDistance_tableDat rtCP_pooled_INwGxsZyA2TK /* Expression: Spline_Lookahead_Dist
                                                                  * Referenced by: '<S215>/Lookahead Distance'
                                                                  */
#define rtCP_LookaheadDistance_bp01Data rtCP_pooled_Por1fGzmcW36 /* Expression: Spline_Velocity_Axis
                                                                  * Referenced by: '<S215>/Lookahead Distance'
                                                                  */
#define rtCP_Constant_Value_c          rtCP_pooled_Rjm7j3rS18VE  /* Expression: All_Paths_Ref_Poses_Blue
                                                                  * Referenced by: '<S20>/Constant'
                                                                  */
#define rtCP_Constant1_Value_bc        rtCP_pooled_8H9wYQ5Cr7gD  /* Expression: All_Paths_Ref_Poses_Red
                                                                  * Referenced by: '<S20>/Constant1'
                                                                  */
#define rtCP_uDLookupTable_tableData   rtCP_pooled_qv7wsteWw1rp  /* Expression: All_Paths_Num_Poses
                                                                  * Referenced by: '<S20>/1-D Lookup Table'
                                                                  */
#define rtCP_Modulation_Drv_tableData  rtCP_pooled_pwqtSNbEs40J  /* Expression: Steering_Mod_Drv_out
                                                                  * Referenced by: '<S438>/Modulation_Drv'
                                                                  */
#define rtCP_Modulation_Drv_bp01Data   rtCP_pooled_pwqtSNbEs40J  /* Expression: Steering_Mod_Drv_in
                                                                  * Referenced by: '<S438>/Modulation_Drv'
                                                                  */
#define rtCP_Modulation_Str_Y_Rel_table rtCP_pooled_wsH2dcaSihoN /* Expression: Steering_Mod_Str_Rel_out
                                                                  * Referenced by: '<S437>/Modulation_Str_Y_Rel'
                                                                  */
#define rtCP_Modulation_Str_Y_Rel_bp01D rtCP_pooled_wsH2dcaSihoN /* Expression: Steering_Mod_Str_Rel_in
                                                                  * Referenced by: '<S437>/Modulation_Str_Y_Rel'
                                                                  */
#define rtCP_uDLookupTable_tableData_g rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S346>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S346>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_j rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S283>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_h  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S283>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_gs rtCP_pooled_O4lHSDP8vPjo /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S304>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_p  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S304>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_h rtCP_pooled_O4lHSDP8vPjo  /* Expression: Drive_Motor_Control_Scale_Factor
                                                                  * Referenced by: '<S325>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_j  rtCP_pooled_Ha5Ct2ozjCBu  /* Expression: Drive_Motor_Control_Module_Angle_Error
                                                                  * Referenced by: '<S325>/1-D Lookup Table'
                                                                  */
#endif                                 /* Robot_Control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
