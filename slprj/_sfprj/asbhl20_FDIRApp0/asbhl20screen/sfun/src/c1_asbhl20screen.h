#ifndef __c1_asbhl20screen_h__
#define __c1_asbhl20screen_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_asbhl20screenInstanceStruct
#define typedef_SFc1_asbhl20screenInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_zero;
  uint8_T c1_tp_three;
  uint8_T c1_tp_two;
  uint8_T c1_tp_one;
  uint8_T c1_tp_Screen;
  uint8_T c1_tp_failure_logging;
  uint8_T c1_tp_off;
  uint8_T c1_tp_logging;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_asbhl20screen;
  uint8_T c1_is_Screen;
  uint8_T c1_is_active_Screen;
  uint8_T c1_is_failure_logging;
  uint8_T c1_is_active_failure_logging;
  int8_T c1_n;
  real_T c1_prev_signal;
  int8_T c1_count;
  real_T c1_diff_max;
  boolean_T c1_bad;
  int8_T c1_select[2];
  real_T c1_middle;
  real_T c1_sum;
  real_T c1_diff;
  real_T c1_mean;
  uint8_T c1_temporalCounter_i1;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_asbhl20screenInstanceStruct;

#endif                                 /*typedef_SFc1_asbhl20screenInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_asbhl20screen_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_asbhl20screen_get_check_sum(mxArray *plhs[]);
extern void c1_asbhl20screen_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
