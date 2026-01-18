/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: rt_hypotd_snf.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.420
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Dec 13 19:32:09 2025
 */

#include "rtwtypes.h"
#include "rt_hypotd_snf.h"
#include <math.h>
#include "rt_nonfinite.h"

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt((a * a) + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt((b * b) + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
