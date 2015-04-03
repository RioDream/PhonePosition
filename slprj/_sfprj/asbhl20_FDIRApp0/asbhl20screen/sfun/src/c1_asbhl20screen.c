/* Include files */

#include <stddef.h>
#include "blas.h"
#include "asbhl20screen_sfun.h"
#include "c1_asbhl20screen.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "asbhl20screen_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_log                   (0)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_one                      ((uint8_T)1U)
#define c1_IN_three                    ((uint8_T)2U)
#define c1_IN_two                      ((uint8_T)3U)
#define c1_IN_zero                     ((uint8_T)4U)
#define c1_IN_logging                  ((uint8_T)1U)
#define c1_IN_off                      ((uint8_T)2U)
#define c1_const_diff_max              (3.0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance);
static void initialize_params_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct *
  chartInstance);
static void enable_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance);
static void disable_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_asbhl20screen
  (SFc1_asbhl20screenInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_asbhl20screen
  (SFc1_asbhl20screenInstanceStruct *chartInstance);
static void set_sim_state_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_asbhl20screen
  (SFc1_asbhl20screenInstanceStruct *chartInstance);
static void finalize_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance);
static void sf_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct *chartInstance);
static void c1_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct *chartInstance);
static void initSimStructsc1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance);
static void registerMessagesc1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance);
static void c1_enter_internal_Screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance);
static void c1_failure_logging(SFc1_asbhl20screenInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static int8_T c1_valid_sensors(SFc1_asbhl20screenInstanceStruct *chartInstance);
static void c1_none(SFc1_asbhl20screenInstanceStruct *chartInstance);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_b_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_zero, const char_T *c1_identifier);
static uint8_T c1_c_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int8_T c1_d_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_b_n, const char_T *c1_identifier);
static int8_T c1_e_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_f_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_valid_signal, const char_T *c1_identifier);
static real_T c1_g_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_h_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_failure, const char_T *c1_identifier);
static boolean_T c1_i_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_j_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_b_select, const char_T *c1_identifier,
  int8_T c1_y[2]);
static void c1_k_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_y[2]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_l_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_m_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint8_T c1__u8_s32_(SFc1_asbhl20screenInstanceStruct *chartInstance,
  int32_T c1_b);
static int8_T c1__s8_s32_(SFc1_asbhl20screenInstanceStruct *chartInstance,
  int32_T c1_b);
static void init_dsm_address_info(SFc1_asbhl20screenInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  real_T *c1_valid_signal;
  boolean_T *c1_failure;
  boolean_T *c1_logging;
  c1_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_Screen = 0U;
  chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_Screen = 0U;
  chartInstance->c1_tp_one = 0U;
  chartInstance->c1_tp_three = 0U;
  chartInstance->c1_tp_two = 0U;
  chartInstance->c1_tp_zero = 0U;
  chartInstance->c1_is_active_failure_logging = 0U;
  chartInstance->c1_is_failure_logging = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_failure_logging = 0U;
  chartInstance->c1_tp_logging = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_off = 0U;
  chartInstance->c1_is_active_c1_asbhl20screen = 0U;
  chartInstance->c1_n = 0;
  chartInstance->c1_prev_signal = 0.0;
  chartInstance->c1_count = 0;
  chartInstance->c1_bad = FALSE;
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    chartInstance->c1_select[c1_i0] = 0;
  }

  chartInstance->c1_middle = 0.0;
  chartInstance->c1_sum = 0.0;
  chartInstance->c1_diff = 0.0;
  chartInstance->c1_mean = 0.0;
  chartInstance->c1_diff_max = 3.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c1_valid_signal = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c1_failure = FALSE;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    *c1_logging = FALSE;
  }
}

static void initialize_params_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct *
  chartInstance)
{
}

static void enable_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_asbhl20screen
  (SFc1_asbhl20screenInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_asbhl20screen == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Screen == c1_IN_zero) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Screen == c1_IN_three) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Screen == c1_IN_two) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Screen == c1_IN_one) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Screen == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_failure_logging == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_failure_logging == c1_IN_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_failure_logging == c1_IN_logging) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_asbhl20screen
  (SFc1_asbhl20screenInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  boolean_T c1_hoistedGlobal;
  boolean_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  boolean_T c1_c_hoistedGlobal;
  boolean_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  boolean_T c1_d_hoistedGlobal;
  boolean_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  int8_T c1_e_hoistedGlobal;
  int8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  int8_T c1_i_hoistedGlobal;
  int8_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  int32_T c1_i1;
  int8_T c1_k_u[2];
  const mxArray *c1_l_y = NULL;
  real_T c1_k_hoistedGlobal;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  uint8_T c1_l_hoistedGlobal;
  uint8_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  uint8_T c1_m_hoistedGlobal;
  uint8_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  uint8_T c1_n_hoistedGlobal;
  uint8_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  uint8_T c1_o_hoistedGlobal;
  uint8_T c1_p_u;
  const mxArray *c1_q_y = NULL;
  uint8_T c1_p_hoistedGlobal;
  uint8_T c1_q_u;
  const mxArray *c1_r_y = NULL;
  uint8_T c1_q_hoistedGlobal;
  uint8_T c1_r_u;
  const mxArray *c1_s_y = NULL;
  boolean_T *c1_failure;
  real_T *c1_valid_signal;
  boolean_T *c1_logging;
  c1_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(18), FALSE);
  c1_hoistedGlobal = *c1_failure;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_valid_signal;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_logging;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_bad;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_count;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 2, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_diff;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = chartInstance->c1_mean;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = chartInstance->c1_middle;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = chartInstance->c1_n;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 2, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = chartInstance->c1_prev_signal;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_k_u[c1_i1] = chartInstance->c1_select[c1_i1];
  }

  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_k_u, 2, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_k_hoistedGlobal = chartInstance->c1_sum;
  c1_l_u = c1_k_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_l_hoistedGlobal = chartInstance->c1_is_active_c1_asbhl20screen;
  c1_m_u = c1_l_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_m_hoistedGlobal = chartInstance->c1_is_active_Screen;
  c1_n_u = c1_m_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_n_hoistedGlobal = chartInstance->c1_is_active_failure_logging;
  c1_o_u = c1_n_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_o_hoistedGlobal = chartInstance->c1_is_Screen;
  c1_p_u = c1_o_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_p_hoistedGlobal = chartInstance->c1_is_failure_logging;
  c1_q_u = c1_p_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_q_hoistedGlobal = chartInstance->c1_temporalCounter_i1;
  c1_r_u = c1_q_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  int8_T c1_iv0[2];
  int32_T c1_i2;
  boolean_T *c1_failure;
  real_T *c1_valid_signal;
  boolean_T *c1_logging;
  c1_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_failure = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "failure");
  *c1_valid_signal = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "valid_signal");
  *c1_logging = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "logging");
  chartInstance->c1_bad = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "bad");
  chartInstance->c1_count = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 4)), "count");
  chartInstance->c1_diff = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 5)), "diff");
  chartInstance->c1_mean = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 6)), "mean");
  chartInstance->c1_middle = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 7)), "middle");
  chartInstance->c1_n = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 8)), "n");
  chartInstance->c1_prev_signal = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 9)), "prev_signal");
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 10)),
                        "select", c1_iv0);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    chartInstance->c1_select[c1_i2] = c1_iv0[c1_i2];
  }

  chartInstance->c1_sum = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "sum");
  chartInstance->c1_is_active_c1_asbhl20screen = c1_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 12)),
     "is_active_c1_asbhl20screen");
  chartInstance->c1_is_active_Screen = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 13)), "is_active_Screen");
  chartInstance->c1_is_active_failure_logging = c1_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 14)),
     "is_active_failure_logging");
  chartInstance->c1_is_Screen = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 15)), "is_Screen");
  chartInstance->c1_is_failure_logging = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 16)), "is_failure_logging");
  chartInstance->c1_temporalCounter_i1 = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 17)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 18)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_asbhl20screen(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_asbhl20screen
  (SFc1_asbhl20screenInstanceStruct *chartInstance)
{
  boolean_T *c1_logging;
  c1_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_Screen == 1U) {
      chartInstance->c1_tp_Screen = 1U;
    } else {
      chartInstance->c1_tp_Screen = 0U;
    }

    if (chartInstance->c1_is_Screen == c1_IN_one) {
      chartInstance->c1_tp_one = 1U;
    } else {
      chartInstance->c1_tp_one = 0U;
    }

    if (chartInstance->c1_is_Screen == c1_IN_three) {
      chartInstance->c1_tp_three = 1U;
    } else {
      chartInstance->c1_tp_three = 0U;
    }

    if (chartInstance->c1_is_Screen == c1_IN_two) {
      chartInstance->c1_tp_two = 1U;
    } else {
      chartInstance->c1_tp_two = 0U;
    }

    if (chartInstance->c1_is_Screen == c1_IN_zero) {
      chartInstance->c1_tp_zero = 1U;
    } else {
      chartInstance->c1_tp_zero = 0U;
    }

    if (chartInstance->c1_is_active_failure_logging == 1U) {
      chartInstance->c1_tp_failure_logging = 1U;
    } else {
      chartInstance->c1_tp_failure_logging = 0U;
    }

    if (chartInstance->c1_is_failure_logging == c1_IN_logging) {
      chartInstance->c1_tp_logging = 1U;
      *c1_logging = TRUE;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_logging = 0U;
      *c1_logging = FALSE;
    }

    if (chartInstance->c1_is_failure_logging == c1_IN_off) {
      chartInstance->c1_tp_off = 1U;
    } else {
      chartInstance->c1_tp_off = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct *chartInstance)
{
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  real_T *c1_valid_signal;
  boolean_T *c1_failure;
  boolean_T *c1_logging;
  boolean_T (*c1_validity)[3];
  real_T (*c1_signals)[3];
  c1_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_validity = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_signals = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c1_set_sim_state_side_effects_c1_asbhl20screen(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_signals)[c1_i3], 0U);
  }

  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_validity)[c1_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_n, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_valid_signal, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_failure, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_prev_signal, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_count, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_diff_max, 7U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_bad, 8U);
  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i5], 9U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c1_logging, 10U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  if ((int16_T)chartInstance->c1_temporalCounter_i1 < 31) {
    chartInstance->c1_temporalCounter_i1 = c1__u8_s32_(chartInstance,
      chartInstance->c1_temporalCounter_i1 + 1);
  }

  c1_c1_asbhl20screen(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_asbhl20screenMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_asbhl20screen(SFc1_asbhl20screenInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_asbhl20screen == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_asbhl20screen = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_Screen = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_Screen = 1U;
    c1_enter_internal_Screen(chartInstance);
    chartInstance->c1_is_active_failure_logging = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_failure_logging = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_failure_logging = c1_IN_off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_off = 1U;
  } else {
    if (chartInstance->c1_is_active_Screen == 0U) {
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c1_sfEvent);
      switch (chartInstance->c1_is_Screen) {
       case c1_IN_one:
        CV_STATE_EVAL(0, 0, 1);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_one = 0U;
        chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        c1_enter_internal_Screen(chartInstance);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
        break;

       case c1_IN_three:
        CV_STATE_EVAL(0, 0, 2);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_three = 0U;
        chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        c1_enter_internal_Screen(chartInstance);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
        break;

       case c1_IN_two:
        CV_STATE_EVAL(0, 0, 3);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_two = 0U;
        chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        c1_enter_internal_Screen(chartInstance);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
        break;

       case c1_IN_zero:
        CV_STATE_EVAL(0, 0, 4);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_zero = 0U;
        chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        c1_enter_internal_Screen(chartInstance);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
        break;

       default:
        CV_STATE_EVAL(0, 0, 0);
        chartInstance->c1_is_Screen = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    }

    if (chartInstance->c1_is_active_failure_logging == 0U) {
    } else {
      c1_failure_logging(chartInstance);
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_asbhl20screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance)
{
}

static void c1_enter_internal_Screen(SFc1_asbhl20screenInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  boolean_T c1_f_out;
  boolean_T c1_g_out;
  boolean_T c1_h_out;
  real_T *c1_valid_signal;
  boolean_T *c1_failure;
  real_T (*c1_signals)[3];
  c1_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_signals = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_n = c1_valid_sensors(chartInstance);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_n, 2U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(30U, (int32_T)_SFD_CCP_CALL(30U, 0,
              chartInstance->c1_n == 3 != 0U, chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[3];
      unsigned int numTransitions = 1;
      transitionList[0] = 30;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      c1_b_out = (chartInstance->c1_n == 2);
      if (c1_b_out) {
        transitionList[numTransitions] = 31;
        numTransitions++;
      }

      c1_c_out = (chartInstance->c1_n == 1);
      if (c1_c_out) {
        transitionList[numTransitions] = 28;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_Screen = c1_IN_three;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_three = 1U;
    chartInstance->c1_middle = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_middle, 11U);
    chartInstance->c1_sum = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_sum, 12U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_sum = ((*c1_signals)[0] + (*c1_signals)[1]) + (*c1_signals)
      [2];
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_sum, 12U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
    chartInstance->c1_middle = (chartInstance->c1_sum - muDoubleScalarMax
      (muDoubleScalarMax((*c1_signals)[0], (*c1_signals)[1]), (*c1_signals)[2]))
      - muDoubleScalarMin(muDoubleScalarMin((*c1_signals)[0], (*c1_signals)[1]),
                          (*c1_signals)[2]);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_middle, 11U);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c1_sfEvent);
    c1_d_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0, (int16_T)
      chartInstance->c1_bad == 1 != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      c1_none(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      *c1_valid_signal = chartInstance->c1_middle;
      _SFD_DATA_RANGE_CHECK(*c1_valid_signal, 3U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      *c1_failure = FALSE;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_failure, 4U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_prev_signal = *c1_valid_signal;
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_prev_signal, 5U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_count = 0;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_count, 6U);
    }
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                 chartInstance->c1_sfEvent);
    c1_e_out = (CV_TRANSITION_EVAL(31U, (int32_T)_SFD_CCP_CALL(31U, 0,
      chartInstance->c1_n == 2 != 0U, chartInstance->c1_sfEvent)) != 0);
    if (c1_e_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 31;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        c1_f_out = (chartInstance->c1_n == 1);
        if (c1_f_out) {
          transitionList[numTransitions] = 28;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_Screen = c1_IN_two;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_two = 1U;
      chartInstance->c1_diff = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_diff, 13U);
      chartInstance->c1_mean = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_mean, 14U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
      chartInstance->c1_diff = muDoubleScalarAbs((*c1_signals)
        [_SFD_ARRAY_BOUNDS_CHECK(0U, chartInstance->c1_select[0] - 1, 1, 3, 1, 0)]
        - (*c1_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U, chartInstance->c1_select[1]
        - 1, 1, 3, 1, 0)]);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_diff, 13U);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                   chartInstance->c1_sfEvent);
      c1_g_out = (CV_TRANSITION_EVAL(26U, (int32_T)_SFD_CCP_CALL(26U, 0,
        chartInstance->c1_diff > c1_const_diff_max != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
        c1_none(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
        chartInstance->c1_mean = ((*c1_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U,
          chartInstance->c1_select[0] - 1, 1, 3, 1, 0)] + (*c1_signals)
          [_SFD_ARRAY_BOUNDS_CHECK(0U, chartInstance->c1_select[1] - 1, 1, 3, 1,
          0)]) / 2.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_mean, 14U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
        *c1_valid_signal = chartInstance->c1_mean;
        _SFD_DATA_RANGE_CHECK(*c1_valid_signal, 3U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
        *c1_failure = FALSE;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_failure, 4U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
        chartInstance->c1_prev_signal = *c1_valid_signal;
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_prev_signal, 5U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
        chartInstance->c1_count = 0;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_count, 6U);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                   chartInstance->c1_sfEvent);
      c1_h_out = (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(28U, 0,
        chartInstance->c1_n == 1 != 0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_Screen = c1_IN_one;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_one = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
        *c1_valid_signal = (*c1_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U,
          chartInstance->c1_select[0] - 1, 1, 3, 1, 0)];
        _SFD_DATA_RANGE_CHECK(*c1_valid_signal, 3U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
        *c1_failure = FALSE;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_failure, 4U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
        chartInstance->c1_prev_signal = *c1_valid_signal;
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_prev_signal, 5U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
        chartInstance->c1_count = 0;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_count, 6U);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_Screen = c1_IN_zero;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_zero = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
        c1_none(chartInstance);
      }
    }
  }
}

static void c1_failure_logging(SFc1_asbhl20screenInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T *c1_logging;
  boolean_T *c1_failure;
  c1_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_failure_logging) {
   case c1_IN_logging:
    CV_STATE_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 chartInstance->c1_sfEvent);
    c1_temp = (_SFD_CCP_CALL(25U, 0, chartInstance->c1_sfEvent == CALL_EVENT !=
                0U, chartInstance->c1_sfEvent) != 0);
    if (c1_temp) {
      c1_temp = (_SFD_CCP_CALL(25U, 1, (int16_T)
                  chartInstance->c1_temporalCounter_i1 >= 30 != 0U,
                  chartInstance->c1_sfEvent) != 0);
    }

    c1_b_temp = c1_temp;
    if (c1_b_temp) {
      c1_b_temp = !(_SFD_CCP_CALL(25U, 2, *c1_failure != 0U,
        chartInstance->c1_sfEvent) != 0);
    }

    c1_out = (CV_TRANSITION_EVAL(25U, (int32_T)c1_b_temp) != 0);
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
      *c1_logging = FALSE;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_logging, 10U);
      chartInstance->c1_tp_logging = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_failure_logging = c1_IN_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_off = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                   chartInstance->c1_sfEvent);
      c1_b_out = (CV_TRANSITION_EVAL(42U, (int32_T)_SFD_CCP_CALL(42U, 0,
        chartInstance->c1_sfEvent == c1_event_log != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
        *c1_logging = FALSE;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_logging, 10U);
        chartInstance->c1_tp_logging = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_failure_logging = c1_IN_logging;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i1 = 0U;
        *c1_logging = TRUE;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_logging, 10U);
        chartInstance->c1_tp_logging = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c1_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_off:
    CV_STATE_EVAL(5, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                 chartInstance->c1_sfEvent);
    c1_c_out = (CV_TRANSITION_EVAL(32U, (int32_T)_SFD_CCP_CALL(32U, 0,
      chartInstance->c1_sfEvent == c1_event_log != 0U, chartInstance->c1_sfEvent))
                != 0);
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_failure_logging = c1_IN_logging;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      *c1_logging = TRUE;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_logging, 10U);
      chartInstance->c1_tp_logging = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 0, 0);
    chartInstance->c1_is_failure_logging = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_asbhl20screen_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static int8_T c1_valid_sensors(SFc1_asbhl20screenInstanceStruct *chartInstance)
{
  int8_T c1_num;
  boolean_T c1_aVarTruthTableCondition_3;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  boolean_T c1_out;
  boolean_T c1_c_temp;
  boolean_T c1_d_temp;
  boolean_T c1_b_out;
  int32_T c1_i6;
  int32_T c1_i7;
  boolean_T c1_e_temp;
  boolean_T c1_f_temp;
  boolean_T c1_c_out;
  int32_T c1_i8;
  int32_T c1_i9;
  boolean_T c1_g_temp;
  boolean_T c1_h_temp;
  boolean_T c1_d_out;
  int32_T c1_i10;
  int32_T c1_i11;
  boolean_T c1_i_temp;
  boolean_T c1_j_temp;
  boolean_T c1_e_out;
  int32_T c1_i12;
  int32_T c1_i13;
  boolean_T c1_k_temp;
  boolean_T c1_l_temp;
  boolean_T c1_f_out;
  int32_T c1_i14;
  int32_T c1_i15;
  boolean_T c1_m_temp;
  boolean_T c1_n_temp;
  boolean_T c1_g_out;
  int32_T c1_i16;
  int32_T c1_i17;
  boolean_T c1_o_temp;
  boolean_T c1_p_temp;
  boolean_T c1_h_out;
  boolean_T (*c1_validity)[3];
  c1_validity = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_SET_DATA_VALUE_PTR(15U, &c1_num);
  _SFD_SET_DATA_VALUE_PTR(18U, &c1_aVarTruthTableCondition_3);
  _SFD_SET_DATA_VALUE_PTR(17U, &c1_aVarTruthTableCondition_2);
  _SFD_SET_DATA_VALUE_PTR(16U, &c1_aVarTruthTableCondition_1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(4U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("num", &c1_num, c1_e_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("aVarTruthTableCondition_1",
    &c1_aVarTruthTableCondition_1, c1_g_sf_marshallOut, c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("aVarTruthTableCondition_2",
    &c1_aVarTruthTableCondition_2, c1_g_sf_marshallOut, c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("aVarTruthTableCondition_3",
    &c1_aVarTruthTableCondition_3, c1_g_sf_marshallOut, c1_e_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  c1_aVarTruthTableCondition_1 = FALSE;
  _SFD_DATA_RANGE_CHECK((real_T)c1_aVarTruthTableCondition_1, 16U);
  c1_aVarTruthTableCondition_2 = FALSE;
  _SFD_DATA_RANGE_CHECK((real_T)c1_aVarTruthTableCondition_2, 17U);
  c1_aVarTruthTableCondition_3 = FALSE;
  _SFD_DATA_RANGE_CHECK((real_T)c1_aVarTruthTableCondition_3, 18U);
  c1_num = 0;
  _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
  c1_aVarTruthTableCondition_1 = ((int16_T)(*c1_validity)[0] == 1);
  _SFD_DATA_RANGE_CHECK((real_T)c1_aVarTruthTableCondition_1, 16U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
  c1_aVarTruthTableCondition_2 = ((int16_T)(*c1_validity)[1] == 1);
  _SFD_DATA_RANGE_CHECK((real_T)c1_aVarTruthTableCondition_2, 17U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
  c1_aVarTruthTableCondition_3 = ((int16_T)(*c1_validity)[2] == 1);
  _SFD_DATA_RANGE_CHECK((real_T)c1_aVarTruthTableCondition_3, 18U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U, chartInstance->c1_sfEvent);
  c1_temp = (_SFD_CCP_CALL(47U, 0, c1_aVarTruthTableCondition_1 != 0U,
              chartInstance->c1_sfEvent) != 0);
  if (c1_temp) {
    c1_temp = (_SFD_CCP_CALL(47U, 1, c1_aVarTruthTableCondition_2 != 0U,
                chartInstance->c1_sfEvent) != 0);
  }

  c1_b_temp = c1_temp;
  if (c1_b_temp) {
    c1_b_temp = (_SFD_CCP_CALL(47U, 2, c1_aVarTruthTableCondition_3 != 0U,
      chartInstance->c1_sfEvent) != 0);
  }

  c1_out = (CV_TRANSITION_EVAL(47U, (int32_T)c1_b_temp) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
    c1_num = 3;
    _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 50U,
                 chartInstance->c1_sfEvent);
    c1_c_temp = (_SFD_CCP_CALL(50U, 0, c1_aVarTruthTableCondition_1 != 0U,
      chartInstance->c1_sfEvent) != 0);
    if (c1_c_temp) {
      c1_c_temp = (_SFD_CCP_CALL(50U, 1, c1_aVarTruthTableCondition_2 != 0U,
        chartInstance->c1_sfEvent) != 0);
    }

    c1_d_temp = c1_c_temp;
    if (c1_d_temp) {
      c1_d_temp = !(_SFD_CCP_CALL(50U, 2, c1_aVarTruthTableCondition_3 != 0U,
        chartInstance->c1_sfEvent) != 0);
    }

    c1_b_out = (CV_TRANSITION_EVAL(50U, (int32_T)c1_d_temp) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
      c1_num = 2;
      _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
      chartInstance->c1_select[0] = 1;
      for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i6], 9U);
      }

      chartInstance->c1_select[1] = 2;
      for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i7], 9U);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U,
                   chartInstance->c1_sfEvent);
      c1_e_temp = (_SFD_CCP_CALL(53U, 0, c1_aVarTruthTableCondition_1 != 0U,
        chartInstance->c1_sfEvent) != 0);
      if (c1_e_temp) {
        c1_e_temp = !(_SFD_CCP_CALL(53U, 1, c1_aVarTruthTableCondition_2 != 0U,
          chartInstance->c1_sfEvent) != 0);
      }

      c1_f_temp = c1_e_temp;
      if (c1_f_temp) {
        c1_f_temp = (_SFD_CCP_CALL(53U, 2, c1_aVarTruthTableCondition_3 != 0U,
          chartInstance->c1_sfEvent) != 0);
      }

      c1_c_out = (CV_TRANSITION_EVAL(53U, (int32_T)c1_f_temp) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, chartInstance->c1_sfEvent);
        c1_num = 2;
        _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
        chartInstance->c1_select[0] = 1;
        for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i8], 9U);
        }

        chartInstance->c1_select[1] = 3;
        for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i9], 9U);
        }
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 56U,
                     chartInstance->c1_sfEvent);
        c1_g_temp = (_SFD_CCP_CALL(56U, 0, c1_aVarTruthTableCondition_1 != 0U,
          chartInstance->c1_sfEvent) != 0);
        if (c1_g_temp) {
          c1_g_temp = !(_SFD_CCP_CALL(56U, 1, c1_aVarTruthTableCondition_2 != 0U,
            chartInstance->c1_sfEvent) != 0);
        }

        c1_h_temp = c1_g_temp;
        if (c1_h_temp) {
          c1_h_temp = !(_SFD_CCP_CALL(56U, 2, c1_aVarTruthTableCondition_3 != 0U,
            chartInstance->c1_sfEvent) != 0);
        }

        c1_d_out = (CV_TRANSITION_EVAL(56U, (int32_T)c1_h_temp) != 0);
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c1_sfEvent);
          c1_num = 1;
          _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
          chartInstance->c1_select[0] = 1;
          for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i10], 9U);
          }

          chartInstance->c1_select[1] = 0;
          for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i11], 9U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 59U,
                       chartInstance->c1_sfEvent);
          c1_i_temp = !(_SFD_CCP_CALL(59U, 0, c1_aVarTruthTableCondition_1 != 0U,
            chartInstance->c1_sfEvent) != 0);
          if (c1_i_temp) {
            c1_i_temp = (_SFD_CCP_CALL(59U, 1, c1_aVarTruthTableCondition_2 !=
              0U, chartInstance->c1_sfEvent) != 0);
          }

          c1_j_temp = c1_i_temp;
          if (c1_j_temp) {
            c1_j_temp = (_SFD_CCP_CALL(59U, 2, c1_aVarTruthTableCondition_3 !=
              0U, chartInstance->c1_sfEvent) != 0);
          }

          c1_e_out = (CV_TRANSITION_EVAL(59U, (int32_T)c1_j_temp) != 0);
          if (c1_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, chartInstance->c1_sfEvent);
            c1_num = 2;
            _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
            chartInstance->c1_select[0] = 2;
            for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i12], 9U);
            }

            chartInstance->c1_select[1] = 3;
            for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i13], 9U);
            }
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, chartInstance->c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 62U,
                         chartInstance->c1_sfEvent);
            c1_k_temp = !(_SFD_CCP_CALL(62U, 0, c1_aVarTruthTableCondition_1 !=
              0U, chartInstance->c1_sfEvent) != 0);
            if (c1_k_temp) {
              c1_k_temp = (_SFD_CCP_CALL(62U, 1, c1_aVarTruthTableCondition_2 !=
                0U, chartInstance->c1_sfEvent) != 0);
            }

            c1_l_temp = c1_k_temp;
            if (c1_l_temp) {
              c1_l_temp = !(_SFD_CCP_CALL(62U, 2, c1_aVarTruthTableCondition_3
                != 0U, chartInstance->c1_sfEvent) != 0);
            }

            c1_f_out = (CV_TRANSITION_EVAL(62U, (int32_T)c1_l_temp) != 0);
            if (c1_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, chartInstance->c1_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, chartInstance->c1_sfEvent);
              c1_num = 1;
              _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
              chartInstance->c1_select[0] = 2;
              for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i14],
                                      9U);
              }

              chartInstance->c1_select[1] = 0;
              for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i15],
                                      9U);
              }
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, chartInstance->c1_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U,
                           chartInstance->c1_sfEvent);
              c1_m_temp = !(_SFD_CCP_CALL(65U, 0, c1_aVarTruthTableCondition_1
                != 0U, chartInstance->c1_sfEvent) != 0);
              if (c1_m_temp) {
                c1_m_temp = !(_SFD_CCP_CALL(65U, 1, c1_aVarTruthTableCondition_2
                  != 0U, chartInstance->c1_sfEvent) != 0);
              }

              c1_n_temp = c1_m_temp;
              if (c1_n_temp) {
                c1_n_temp = (_SFD_CCP_CALL(65U, 2, c1_aVarTruthTableCondition_3
                  != 0U, chartInstance->c1_sfEvent) != 0);
              }

              c1_g_out = (CV_TRANSITION_EVAL(65U, (int32_T)c1_n_temp) != 0);
              if (c1_g_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U,
                             chartInstance->c1_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U,
                             chartInstance->c1_sfEvent);
                c1_num = 1;
                _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
                chartInstance->c1_select[0] = 3;
                for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
                  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i16],
                                        9U);
                }

                chartInstance->c1_select[1] = 0;
                for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
                  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_select[c1_i17],
                                        9U);
                }
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U,
                             chartInstance->c1_sfEvent);
                _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 68U,
                             chartInstance->c1_sfEvent);
                c1_o_temp = !(_SFD_CCP_CALL(68U, 0, c1_aVarTruthTableCondition_1
                  != 0U, chartInstance->c1_sfEvent) != 0);
                if (c1_o_temp) {
                  c1_o_temp = !(_SFD_CCP_CALL(68U, 1,
                    c1_aVarTruthTableCondition_2 != 0U,
                    chartInstance->c1_sfEvent) != 0);
                }

                c1_p_temp = c1_o_temp;
                if (c1_p_temp) {
                  c1_p_temp = !(_SFD_CCP_CALL(68U, 2,
                    c1_aVarTruthTableCondition_3 != 0U,
                    chartInstance->c1_sfEvent) != 0);
                }

                c1_h_out = (CV_TRANSITION_EVAL(68U, (int32_T)c1_p_temp) != 0);
                if (c1_h_out) {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U,
                               chartInstance->c1_sfEvent);
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U,
                               chartInstance->c1_sfEvent);
                  c1_num = 0;
                  _SFD_DATA_RANGE_CHECK((real_T)c1_num, 15U);
                } else {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U,
                               chartInstance->c1_sfEvent);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(15U);
  _SFD_UNSET_DATA_VALUE_PTR(18U);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_UNSET_DATA_VALUE_PTR(16U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  return c1_num;
}

static void c1_none(SFc1_asbhl20screenInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  int32_T c1_previousEvent;
  real_T *c1_valid_signal;
  boolean_T *c1_failure;
  c1_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  chartInstance->c1_count = c1__s8_s32_(chartInstance, chartInstance->c1_count +
    1);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_count, 6U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12U, 0,
              chartInstance->c1_count > 3 != 0U, chartInstance->c1_sfEvent)) !=
            0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    chartInstance->c1_count = 3;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_count, 6U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
    *c1_valid_signal = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_valid_signal, 3U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    *c1_failure = TRUE;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_failure, 4U);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    *c1_valid_signal = chartInstance->c1_prev_signal;
    _SFD_DATA_RANGE_CHECK(*c1_valid_signal, 3U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
    *c1_failure = FALSE;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_failure, 4U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    c1_previousEvent = chartInstance->c1_sfEvent;
    chartInstance->c1_sfEvent = c1_event_log;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_log,
                 chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_active_failure_logging == 0U) {
    } else {
      c1_failure_logging(chartInstance);
    }

    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_log,
                 chartInstance->c1_sfEvent);
    chartInstance->c1_sfEvent = c1_previousEvent;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i18;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i18, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i18;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_b_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_zero, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_zero),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_zero);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_zero;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_b_tp_zero = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_zero),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_zero);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i19;
  real_T c1_b_inData[3];
  int32_T c1_i20;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    c1_b_inData[c1_i19] = (*(real_T (*)[3])c1_inData)[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
    c1_u[c1_i20] = c1_b_inData[c1_i20];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i21;
  boolean_T c1_b_inData[3];
  int32_T c1_i22;
  boolean_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i21 = 0; c1_i21 < 3; c1_i21++) {
    c1_b_inData[c1_i21] = (*(boolean_T (*)[3])c1_inData)[c1_i21];
  }

  for (c1_i22 = 0; c1_i22 < 3; c1_i22++) {
    c1_u[c1_i22] = c1_b_inData[c1_i22];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 11, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int8_T c1_d_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_b_n, const char_T *c1_identifier)
{
  int8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n), &c1_thisId);
  sf_mex_destroy(&c1_b_n);
  return c1_y;
}

static int8_T c1_e_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i23;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i23, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i23;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_n;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_b_n = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n), &c1_thisId);
  sf_mex_destroy(&c1_b_n);
  *(int8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_f_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_valid_signal, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_valid_signal),
    &c1_thisId);
  sf_mex_destroy(&c1_valid_signal);
  return c1_y;
}

static real_T c1_g_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_valid_signal;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_valid_signal = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_valid_signal),
    &c1_thisId);
  sf_mex_destroy(&c1_valid_signal);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_h_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_failure, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_failure), &c1_thisId);
  sf_mex_destroy(&c1_failure);
  return c1_y;
}

static boolean_T c1_i_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_failure;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_failure = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_failure), &c1_thisId);
  sf_mex_destroy(&c1_failure);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i24;
  int8_T c1_b_inData[2];
  int32_T c1_i25;
  int8_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
    c1_b_inData[c1_i24] = (*(int8_T (*)[2])c1_inData)[c1_i24];
  }

  for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
    c1_u[c1_i25] = c1_b_inData[c1_i25];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 2, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_j_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_b_select, const char_T *c1_identifier,
  int8_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_select), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_select);
}

static void c1_k_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_y[2])
{
  int8_T c1_iv1[2];
  int32_T c1_i26;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_iv1, 1, 2, 0U, 1, 0U, 1, 2);
  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    c1_y[c1_i26] = c1_iv1[c1_i26];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_select;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y[2];
  int32_T c1_i27;
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c1_b_select = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_select), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_select);
  for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
    (*(int8_T (*)[2])c1_outData)[c1_i27] = c1_y[c1_i27];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_l_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_m_emlrt_marshallIn(SFc1_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint8_T c1__u8_s32_(SFc1_asbhl20screenInstanceStruct *chartInstance,
  int32_T c1_b)
{
  uint8_T c1_a;
  c1_a = (uint8_T)c1_b;
  if (c1_a != c1_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW);
  }

  return c1_a;
}

static int8_T c1__s8_s32_(SFc1_asbhl20screenInstanceStruct *chartInstance,
  int32_T c1_b)
{
  int8_T c1_a;
  c1_a = (int8_T)c1_b;
  if (c1_a != c1_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW);
  }

  return c1_a;
}

static void init_dsm_address_info(SFc1_asbhl20screenInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_asbhl20screen_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3046866020U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3016360783U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1622835493U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2690824429U);
}

mxArray *sf_c1_asbhl20screen_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("VOtW1oUsfnbecfqaxxKHmD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(2));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_asbhl20screen_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_asbhl20screen(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[146],T\"failure\",},{M[1],M[145],T\"valid_signal\",},{M[2],M[152],T\"logging\",},{M[3],M[150],T\"bad\",},{M[3],M[148],T\"count\",},{M[3],M[157],T\"diff\",},{M[3],M[158],T\"mean\",},{M[3],M[153],T\"middle\",},{M[3],M[144],T\"n\",},{M[3],M[147],T\"prev_signal\",}}",
    "100 S1x8'type','srcId','name','auxInfo'{{M[3],M[151],T\"select\",},{M[3],M[154],T\"sum\",},{M[8],M[0],T\"is_active_c1_asbhl20screen\",},{M[8],M[7],T\"is_active_Screen\",},{M[8],M[10],T\"is_active_failure_logging\",},{M[9],M[7],T\"is_Screen\",},{M[9],M[10],T\"is_failure_logging\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"wu\",M[12],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 18, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_asbhl20screen_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_asbhl20screenInstanceStruct *chartInstance;
    chartInstance = (SFc1_asbhl20screenInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _asbhl20screenMachineNumber_,
           1,
           10,
           71,
           19,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_asbhl20screenMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_asbhl20screenMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _asbhl20screenMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,1,1,0,"signals");
          _SFD_SET_DATA_PROPS(1,1,1,0,"validity");
          _SFD_SET_DATA_PROPS(2,0,0,0,"n");
          _SFD_SET_DATA_PROPS(3,2,0,1,"valid_signal");
          _SFD_SET_DATA_PROPS(4,2,0,1,"failure");
          _SFD_SET_DATA_PROPS(5,0,0,0,"prev_signal");
          _SFD_SET_DATA_PROPS(6,0,0,0,"count");
          _SFD_SET_DATA_PROPS(7,7,0,0,"diff_max");
          _SFD_SET_DATA_PROPS(8,0,0,0,"bad");
          _SFD_SET_DATA_PROPS(9,0,0,0,"select");
          _SFD_SET_DATA_PROPS(10,2,0,1,"logging");
          _SFD_SET_DATA_PROPS(11,0,0,0,"middle");
          _SFD_SET_DATA_PROPS(12,0,0,0,"sum");
          _SFD_SET_DATA_PROPS(13,0,0,0,"diff");
          _SFD_SET_DATA_PROPS(14,0,0,0,"mean");
          _SFD_SET_DATA_PROPS(15,9,0,0,"");
          _SFD_SET_DATA_PROPS(16,6,0,0,"");
          _SFD_SET_DATA_PROPS(17,6,0,0,"");
          _SFD_SET_DATA_PROPS(18,6,0,0,"");
          _SFD_EVENT_SCOPE(0,0);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,1);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,5);
          _SFD_ST_SUBSTATE_COUNT(0,4);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_INDEX(0,3,4);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,2);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,7);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
        }

        _SFD_CV_INIT_CHART(2,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 30, 59 };

          static unsigned int sEndGuardMap[] = { 26, 55, 84 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(47,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 30, 60 };

          static unsigned int sEndGuardMap[] = { 26, 55, 85 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -1, -3 };

          _SFD_CV_INIT_TRANS(50,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),6,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 31, 60 };

          static unsigned int sEndGuardMap[] = { 26, 56, 85 };

          static int sPostFixPredicateTree[] = { 0, 1, -1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(53,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),6,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(54,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(55,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 31, 61 };

          static unsigned int sEndGuardMap[] = { 26, 56, 86 };

          static int sPostFixPredicateTree[] = { 0, 1, -1, -3, 2, -1, -3 };

          _SFD_CV_INIT_TRANS(56,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(57,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 31, 60 };

          static unsigned int sEndGuardMap[] = { 27, 56, 85 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(59,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),6,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 31, 61 };

          static unsigned int sEndGuardMap[] = { 27, 56, 86 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -3, 2, -1, -3 };

          _SFD_CV_INIT_TRANS(62,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(63,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(64,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 32, 61 };

          static unsigned int sEndGuardMap[] = { 27, 57, 86 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(65,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(66,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(67,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 32, 62 };

          static unsigned int sEndGuardMap[] = { 27, 57, 87 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -1, -3, 2, -1, -3 };

          _SFD_CV_INIT_TRANS(68,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),8,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(69,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(70,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(26,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(30,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(31,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(28,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(32,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(42,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 9, 0, 16 };

          static unsigned int sEndGuardMap[] = { 13, 14, 23 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -1, -3 };

          _SFD_CV_INIT_TRANS(25,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),6,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(43,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(43,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(44,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(44,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(45,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(45,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(46,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(46,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(47,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 30, 59 };

          static unsigned int sEndGuardMap[] = { 26, 55, 84 };

          _SFD_TRANS_COV_MAPS(47,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(48,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(48,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(49,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(49,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(50,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 30, 60 };

          static unsigned int sEndGuardMap[] = { 26, 55, 85 };

          _SFD_TRANS_COV_MAPS(50,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(51,0,0,3,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(51,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(52,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(52,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(53,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 31, 60 };

          static unsigned int sEndGuardMap[] = { 26, 56, 85 };

          _SFD_TRANS_COV_MAPS(53,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(54,0,0,3,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(54,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(55,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(55,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(56,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 31, 61 };

          static unsigned int sEndGuardMap[] = { 26, 56, 86 };

          _SFD_TRANS_COV_MAPS(56,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(57,0,0,3,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(57,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(58,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(58,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(59,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 31, 60 };

          static unsigned int sEndGuardMap[] = { 27, 56, 85 };

          _SFD_TRANS_COV_MAPS(59,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(60,0,0,3,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(60,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(61,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(61,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(62,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 31, 61 };

          static unsigned int sEndGuardMap[] = { 27, 56, 86 };

          _SFD_TRANS_COV_MAPS(62,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(63,0,0,3,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(63,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(64,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(64,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(65,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 32, 61 };

          static unsigned int sEndGuardMap[] = { 27, 57, 86 };

          _SFD_TRANS_COV_MAPS(65,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(66,0,0,3,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(66,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(67,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(67,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(68,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 32, 62 };

          static unsigned int sEndGuardMap[] = { 27, 57, 87 };

          _SFD_TRANS_COV_MAPS(68,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(69,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(69,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(70,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(70,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(11,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(27,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(27,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(12,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(34,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(34,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(33,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(33,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(19,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(19,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(36,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(36,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(35,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(35,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(26,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(26,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(20,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(20,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(37,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(37,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(17,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(17,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(15,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(15,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(18,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(18,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(14,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(14,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(41,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(41,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(22,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(22,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(23,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(23,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(24,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(24,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(39,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(39,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(29,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(29,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(30,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(30,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(21,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(21,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(31,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(31,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(28,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(28,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(40,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(40,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(38,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(38,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(32,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          _SFD_TRANS_COV_MAPS(32,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(42,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          _SFD_TRANS_COV_MAPS(42,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(16,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(16,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(25,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 9, 0, 16 };

          static unsigned int sEndGuardMap[] = { 13, 14, 23 };

          _SFD_TRANS_COV_MAPS(25,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT8,1,&(dimVector[0]),0,0,0,0.0,1.0,
            0,0,(MexFcnForType)c1_h_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));

        {
          real_T *c1_valid_signal;
          boolean_T *c1_failure;
          boolean_T *c1_logging;
          real_T (*c1_signals)[3];
          boolean_T (*c1_validity)[3];
          c1_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_validity = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            1);
          c1_signals = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_signals);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_validity);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c1_n);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_valid_signal);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_failure);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c1_prev_signal);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c1_count);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_diff_max);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c1_bad);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c1_select);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_logging);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c1_middle);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c1_sum);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c1_diff);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c1_mean);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _asbhl20screenMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "GdZuyJBEWXqbQuAPU4igzG";
}

static void sf_opaque_initialize_c1_asbhl20screen(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_asbhl20screenInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*)
    chartInstanceVar);
  initialize_c1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_asbhl20screen(void *chartInstanceVar)
{
  enable_c1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_asbhl20screen(void *chartInstanceVar)
{
  disable_c1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_asbhl20screen(void *chartInstanceVar)
{
  sf_c1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_asbhl20screen(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_asbhl20screen
    ((SFc1_asbhl20screenInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_asbhl20screen();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_asbhl20screen(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_asbhl20screen();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_asbhl20screen(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_asbhl20screen(S);
}

static void sf_opaque_set_sim_state_c1_asbhl20screen(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_asbhl20screen(S, st);
}

static void sf_opaque_terminate_c1_asbhl20screen(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_asbhl20screenInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_asbhl20screen_optimization_info();
    }

    finalize_c1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_asbhl20screen(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_asbhl20screen((SFc1_asbhl20screenInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_asbhl20screen(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_asbhl20screen_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1302192709U));
  ssSetChecksum1(S,(1312348672U));
  ssSetChecksum2(S,(2708625617U));
  ssSetChecksum3(S,(861055271U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_asbhl20screen(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_asbhl20screen(SimStruct *S)
{
  SFc1_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc1_asbhl20screenInstanceStruct *)utMalloc(sizeof
    (SFc1_asbhl20screenInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_asbhl20screenInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_asbhl20screen;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_asbhl20screen;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_asbhl20screen;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_asbhl20screen;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_asbhl20screen;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_asbhl20screen;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_asbhl20screen;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_asbhl20screen;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_asbhl20screen;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_asbhl20screen;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_asbhl20screen;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_asbhl20screen_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_asbhl20screen(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_asbhl20screen(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_asbhl20screen(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_asbhl20screen_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
