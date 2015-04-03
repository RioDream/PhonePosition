#ifndef __c2_asbhl20screen_h__
#define __c2_asbhl20screen_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc2_asbhl20screenInstanceStruct
#define typedef_SFc2_asbhl20screenInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_one;
  uint8_T c2_tp_Screen;
  uint8_T c2_tp_three;
  uint8_T c2_tp_two;
  uint8_T c2_tp_zero;
  uint8_T c2_tp_failure_logging;
  uint8_T c2_tp_logging;
  uint8_T c2_tp_off;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_asbhl20screen;
  uint8_T c2_is_Screen;
  uint8_T c2_is_active_Screen;
  uint8_T c2_is_failure_logging;
  uint8_T c2_is_active_failure_logging;
  int8_T c2_n;
  real_T c2_prev_signal;
  int8_T c2_count;
  real_T c2_diff_max;
  boolean_T c2_bad;
  int8_T c2_select[2];
  real_T c2_middle;
  real_T c2_sum;
  real_T c2_diff;
  real_T c2_mean;
  uint8_T c2_temporalCounter_i1;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
} SFc2_asbhl20screenInstanceStruct;

#endif                                 /*typedef_SFc2_asbhl20screenInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_asbhl20screen_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_asbhl20screen_get_check_sum(mxArray *plhs[]);
extern void c2_asbhl20screen_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
