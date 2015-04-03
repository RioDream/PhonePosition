/* Include files */

#include <stddef.h>
#include "blas.h"
#include "asbhl20screen_sfun.h"
#include "c2_asbhl20screen.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "asbhl20screen_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c2_event_log                   (0)
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_one                      ((uint8_T)1U)
#define c2_IN_three                    ((uint8_T)2U)
#define c2_IN_two                      ((uint8_T)3U)
#define c2_IN_zero                     ((uint8_T)4U)
#define c2_IN_logging                  ((uint8_T)1U)
#define c2_IN_off                      ((uint8_T)2U)
#define c2_const_diff_max              (10.0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance);
static void initialize_params_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct *
  chartInstance);
static void enable_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance);
static void disable_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_asbhl20screen
  (SFc2_asbhl20screenInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_asbhl20screen
  (SFc2_asbhl20screenInstanceStruct *chartInstance);
static void set_sim_state_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_asbhl20screen
  (SFc2_asbhl20screenInstanceStruct *chartInstance);
static void finalize_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance);
static void sf_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct *chartInstance);
static void c2_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct *chartInstance);
static void initSimStructsc2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance);
static void registerMessagesc2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance);
static void c2_enter_internal_Screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance);
static void c2_failure_logging(SFc2_asbhl20screenInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static int8_T c2_valid_sensors(SFc2_asbhl20screenInstanceStruct *chartInstance);
static void c2_none(SFc2_asbhl20screenInstanceStruct *chartInstance);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int32_T c2_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_b_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_one, const char_T *c2_identifier);
static uint8_T c2_c_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int8_T c2_d_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_b_n, const char_T *c2_identifier);
static int8_T c2_e_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_f_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_valid_signal, const char_T *c2_identifier);
static real_T c2_g_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_h_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_failure, const char_T *c2_identifier);
static boolean_T c2_i_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_j_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_b_select, const char_T *c2_identifier,
  int8_T c2_y[2]);
static void c2_k_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int8_T c2_y[2]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_l_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_m_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static uint8_T c2__u8_s32_(SFc2_asbhl20screenInstanceStruct *chartInstance,
  int32_T c2_b);
static int8_T c2__s8_s32_(SFc2_asbhl20screenInstanceStruct *chartInstance,
  int32_T c2_b);
static void init_dsm_address_info(SFc2_asbhl20screenInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance)
{
  int32_T c2_i0;
  real_T *c2_valid_signal;
  boolean_T *c2_failure;
  boolean_T *c2_logging;
  c2_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_is_active_Screen = 0U;
  chartInstance->c2_is_Screen = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_Screen = 0U;
  chartInstance->c2_tp_one = 0U;
  chartInstance->c2_tp_three = 0U;
  chartInstance->c2_tp_two = 0U;
  chartInstance->c2_tp_zero = 0U;
  chartInstance->c2_is_active_failure_logging = 0U;
  chartInstance->c2_is_failure_logging = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_failure_logging = 0U;
  chartInstance->c2_tp_logging = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_off = 0U;
  chartInstance->c2_is_active_c2_asbhl20screen = 0U;
  chartInstance->c2_n = 0;
  chartInstance->c2_prev_signal = 0.0;
  chartInstance->c2_count = 0;
  chartInstance->c2_bad = FALSE;
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    chartInstance->c2_select[c2_i0] = 0;
  }

  chartInstance->c2_middle = 0.0;
  chartInstance->c2_sum = 0.0;
  chartInstance->c2_diff = 0.0;
  chartInstance->c2_mean = 0.0;
  chartInstance->c2_diff_max = 10.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c2_valid_signal = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c2_failure = FALSE;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    *c2_logging = FALSE;
  }
}

static void initialize_params_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct *
  chartInstance)
{
}

static void enable_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_asbhl20screen
  (SFc2_asbhl20screenInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_asbhl20screen == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Screen == c2_IN_one) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_active_Screen == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Screen == c2_IN_three) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Screen == c2_IN_two) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Screen == c2_IN_zero) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_active_failure_logging == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_failure_logging == c2_IN_logging) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_failure_logging == c2_IN_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_asbhl20screen
  (SFc2_asbhl20screenInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  boolean_T c2_hoistedGlobal;
  boolean_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  boolean_T c2_c_hoistedGlobal;
  boolean_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  boolean_T c2_d_hoistedGlobal;
  boolean_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  int8_T c2_e_hoistedGlobal;
  int8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_hoistedGlobal;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  int8_T c2_i_hoistedGlobal;
  int8_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_j_hoistedGlobal;
  real_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  int32_T c2_i1;
  int8_T c2_k_u[2];
  const mxArray *c2_l_y = NULL;
  real_T c2_k_hoistedGlobal;
  real_T c2_l_u;
  const mxArray *c2_m_y = NULL;
  uint8_T c2_l_hoistedGlobal;
  uint8_T c2_m_u;
  const mxArray *c2_n_y = NULL;
  uint8_T c2_m_hoistedGlobal;
  uint8_T c2_n_u;
  const mxArray *c2_o_y = NULL;
  uint8_T c2_n_hoistedGlobal;
  uint8_T c2_o_u;
  const mxArray *c2_p_y = NULL;
  uint8_T c2_o_hoistedGlobal;
  uint8_T c2_p_u;
  const mxArray *c2_q_y = NULL;
  uint8_T c2_p_hoistedGlobal;
  uint8_T c2_q_u;
  const mxArray *c2_r_y = NULL;
  uint8_T c2_q_hoistedGlobal;
  uint8_T c2_r_u;
  const mxArray *c2_s_y = NULL;
  boolean_T *c2_failure;
  real_T *c2_valid_signal;
  boolean_T *c2_logging;
  c2_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(18), FALSE);
  c2_hoistedGlobal = *c2_failure;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_valid_signal;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_logging;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_bad;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_count;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 2, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = chartInstance->c2_diff;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = chartInstance->c2_mean;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = chartInstance->c2_middle;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = chartInstance->c2_n;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 2, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = chartInstance->c2_prev_signal;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_k_u[c2_i1] = chartInstance->c2_select[c2_i1];
  }

  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_k_u, 2, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_k_hoistedGlobal = chartInstance->c2_sum;
  c2_l_u = c2_k_hoistedGlobal;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 11, c2_m_y);
  c2_l_hoistedGlobal = chartInstance->c2_is_active_c2_asbhl20screen;
  c2_m_u = c2_l_hoistedGlobal;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 12, c2_n_y);
  c2_m_hoistedGlobal = chartInstance->c2_is_active_Screen;
  c2_n_u = c2_m_hoistedGlobal;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_n_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 13, c2_o_y);
  c2_n_hoistedGlobal = chartInstance->c2_is_active_failure_logging;
  c2_o_u = c2_n_hoistedGlobal;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_o_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 14, c2_p_y);
  c2_o_hoistedGlobal = chartInstance->c2_is_Screen;
  c2_p_u = c2_o_hoistedGlobal;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_p_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 15, c2_q_y);
  c2_p_hoistedGlobal = chartInstance->c2_is_failure_logging;
  c2_q_u = c2_p_hoistedGlobal;
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_q_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 16, c2_r_y);
  c2_q_hoistedGlobal = chartInstance->c2_temporalCounter_i1;
  c2_r_u = c2_q_hoistedGlobal;
  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_r_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 17, c2_s_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  int8_T c2_iv0[2];
  int32_T c2_i2;
  boolean_T *c2_failure;
  real_T *c2_valid_signal;
  boolean_T *c2_logging;
  c2_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_failure = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "failure");
  *c2_valid_signal = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "valid_signal");
  *c2_logging = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 2)), "logging");
  chartInstance->c2_bad = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "bad");
  chartInstance->c2_count = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 4)), "count");
  chartInstance->c2_diff = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 5)), "diff");
  chartInstance->c2_mean = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 6)), "mean");
  chartInstance->c2_middle = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 7)), "middle");
  chartInstance->c2_n = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 8)), "n");
  chartInstance->c2_prev_signal = c2_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 9)), "prev_signal");
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 10)),
                        "select", c2_iv0);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    chartInstance->c2_select[c2_i2] = c2_iv0[c2_i2];
  }

  chartInstance->c2_sum = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 11)), "sum");
  chartInstance->c2_is_active_c2_asbhl20screen = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 12)),
     "is_active_c2_asbhl20screen");
  chartInstance->c2_is_active_Screen = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 13)), "is_active_Screen");
  chartInstance->c2_is_active_failure_logging = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 14)),
     "is_active_failure_logging");
  chartInstance->c2_is_Screen = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 15)), "is_Screen");
  chartInstance->c2_is_failure_logging = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 16)), "is_failure_logging");
  chartInstance->c2_temporalCounter_i1 = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 17)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 18)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_asbhl20screen(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_asbhl20screen
  (SFc2_asbhl20screenInstanceStruct *chartInstance)
{
  boolean_T *c2_logging;
  c2_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_active_Screen == 1U) {
      chartInstance->c2_tp_Screen = 1U;
    } else {
      chartInstance->c2_tp_Screen = 0U;
    }

    if (chartInstance->c2_is_Screen == c2_IN_one) {
      chartInstance->c2_tp_one = 1U;
    } else {
      chartInstance->c2_tp_one = 0U;
    }

    if (chartInstance->c2_is_Screen == c2_IN_three) {
      chartInstance->c2_tp_three = 1U;
    } else {
      chartInstance->c2_tp_three = 0U;
    }

    if (chartInstance->c2_is_Screen == c2_IN_two) {
      chartInstance->c2_tp_two = 1U;
    } else {
      chartInstance->c2_tp_two = 0U;
    }

    if (chartInstance->c2_is_Screen == c2_IN_zero) {
      chartInstance->c2_tp_zero = 1U;
    } else {
      chartInstance->c2_tp_zero = 0U;
    }

    if (chartInstance->c2_is_active_failure_logging == 1U) {
      chartInstance->c2_tp_failure_logging = 1U;
    } else {
      chartInstance->c2_tp_failure_logging = 0U;
    }

    if (chartInstance->c2_is_failure_logging == c2_IN_logging) {
      chartInstance->c2_tp_logging = 1U;
      *c2_logging = TRUE;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_logging = 0U;
      *c2_logging = FALSE;
    }

    if (chartInstance->c2_is_failure_logging == c2_IN_off) {
      chartInstance->c2_tp_off = 1U;
    } else {
      chartInstance->c2_tp_off = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  real_T *c2_valid_signal;
  boolean_T *c2_failure;
  boolean_T *c2_logging;
  boolean_T (*c2_validity)[3];
  real_T (*c2_signals)[3];
  c2_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_validity = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c2_signals = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c2_set_sim_state_side_effects_c2_asbhl20screen(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_signals)[c2_i3], 0U);
  }

  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_validity)[c2_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_n, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_valid_signal, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_failure, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_prev_signal, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_count, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_diff_max, 7U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_bad, 8U);
  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i5], 9U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c2_logging, 10U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  if ((int16_T)chartInstance->c2_temporalCounter_i1 < 31) {
    chartInstance->c2_temporalCounter_i1 = c2__u8_s32_(chartInstance,
      chartInstance->c2_temporalCounter_i1 + 1);
  }

  c2_c2_asbhl20screen(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_asbhl20screenMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_c2_asbhl20screen(SFc2_asbhl20screenInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_asbhl20screen == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_asbhl20screen = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_Screen = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_Screen = 1U;
    c2_enter_internal_Screen(chartInstance);
    chartInstance->c2_is_active_failure_logging = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_failure_logging = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_failure_logging = c2_IN_off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_off = 1U;
  } else {
    if (chartInstance->c2_is_active_Screen == 0U) {
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c2_sfEvent);
      switch (chartInstance->c2_is_Screen) {
       case c2_IN_one:
        CV_STATE_EVAL(0, 0, 1);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_one = 0U;
        chartInstance->c2_is_Screen = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        c2_enter_internal_Screen(chartInstance);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
        break;

       case c2_IN_three:
        CV_STATE_EVAL(0, 0, 2);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_three = 0U;
        chartInstance->c2_is_Screen = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        c2_enter_internal_Screen(chartInstance);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
        break;

       case c2_IN_two:
        CV_STATE_EVAL(0, 0, 3);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_two = 0U;
        chartInstance->c2_is_Screen = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        c2_enter_internal_Screen(chartInstance);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
        break;

       case c2_IN_zero:
        CV_STATE_EVAL(0, 0, 4);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_zero = 0U;
        chartInstance->c2_is_Screen = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        c2_enter_internal_Screen(chartInstance);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c2_sfEvent);
        break;

       default:
        CV_STATE_EVAL(0, 0, 0);
        chartInstance->c2_is_Screen = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    }

    if (chartInstance->c2_is_active_failure_logging == 0U) {
    } else {
      c2_failure_logging(chartInstance);
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_asbhl20screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance)
{
}

static void c2_enter_internal_Screen(SFc2_asbhl20screenInstanceStruct
  *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_d_out;
  boolean_T c2_e_out;
  boolean_T c2_f_out;
  boolean_T c2_g_out;
  boolean_T c2_h_out;
  real_T *c2_valid_signal;
  boolean_T *c2_failure;
  real_T (*c2_signals)[3];
  c2_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_signals = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  chartInstance->c2_n = c2_valid_sensors(chartInstance);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_n, 2U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17U, 0,
              chartInstance->c2_n == 3 != 0U, chartInstance->c2_sfEvent)) != 0);
  if (c2_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[3];
      unsigned int numTransitions = 1;
      transitionList[0] = 17;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      c2_b_out = (chartInstance->c2_n == 2);
      if (c2_b_out) {
        transitionList[numTransitions] = 20;
        numTransitions++;
      }

      c2_c_out = (chartInstance->c2_n == 1);
      if (c2_c_out) {
        transitionList[numTransitions] = 26;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_Screen = c2_IN_three;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_three = 1U;
    chartInstance->c2_middle = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_middle, 11U);
    chartInstance->c2_sum = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_sum, 12U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
    chartInstance->c2_sum = ((*c2_signals)[0] + (*c2_signals)[1]) + (*c2_signals)
      [2];
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_sum, 12U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
    chartInstance->c2_middle = (chartInstance->c2_sum - muDoubleScalarMax
      (muDoubleScalarMax((*c2_signals)[0], (*c2_signals)[1]), (*c2_signals)[2]))
      - muDoubleScalarMin(muDoubleScalarMin((*c2_signals)[0], (*c2_signals)[1]),
                          (*c2_signals)[2]);
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_middle, 11U);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U,
                 chartInstance->c2_sfEvent);
    c2_d_out = (CV_TRANSITION_EVAL(41U, (int32_T)_SFD_CCP_CALL(41U, 0, (int16_T)
      chartInstance->c2_bad == 1 != 0U, chartInstance->c2_sfEvent)) != 0);
    if (c2_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
      c2_none(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
      *c2_valid_signal = chartInstance->c2_middle;
      _SFD_DATA_RANGE_CHECK(*c2_valid_signal, 3U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
      *c2_failure = FALSE;
      _SFD_DATA_RANGE_CHECK((real_T)*c2_failure, 4U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
      chartInstance->c2_prev_signal = *c2_valid_signal;
      _SFD_DATA_RANGE_CHECK(chartInstance->c2_prev_signal, 5U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      chartInstance->c2_count = 0;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_count, 6U);
    }
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c2_sfEvent);
    c2_e_out = (CV_TRANSITION_EVAL(20U, (int32_T)_SFD_CCP_CALL(20U, 0,
      chartInstance->c2_n == 2 != 0U, chartInstance->c2_sfEvent)) != 0);
    if (c2_e_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 20;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        c2_f_out = (chartInstance->c2_n == 1);
        if (c2_f_out) {
          transitionList[numTransitions] = 26;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_Screen = c2_IN_two;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_two = 1U;
      chartInstance->c2_diff = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c2_diff, 13U);
      chartInstance->c2_mean = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c2_mean, 14U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c2_sfEvent);
      chartInstance->c2_diff = muDoubleScalarAbs((*c2_signals)
        [_SFD_ARRAY_BOUNDS_CHECK(0U, chartInstance->c2_select[0] - 1, 1, 3, 1, 0)]
        - (*c2_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U, chartInstance->c2_select[1]
        - 1, 1, 3, 1, 0)]);
      _SFD_DATA_RANGE_CHECK(chartInstance->c2_diff, 13U);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                   chartInstance->c2_sfEvent);
      c2_g_out = (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(28U, 0,
        chartInstance->c2_diff > c2_const_diff_max != 0U,
        chartInstance->c2_sfEvent)) != 0);
      if (c2_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
        c2_none(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
        chartInstance->c2_mean = ((*c2_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U,
          chartInstance->c2_select[0] - 1, 1, 3, 1, 0)] + (*c2_signals)
          [_SFD_ARRAY_BOUNDS_CHECK(0U, chartInstance->c2_select[1] - 1, 1, 3, 1,
          0)]) / 2.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c2_mean, 14U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
        *c2_valid_signal = chartInstance->c2_mean;
        _SFD_DATA_RANGE_CHECK(*c2_valid_signal, 3U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
        *c2_failure = FALSE;
        _SFD_DATA_RANGE_CHECK((real_T)*c2_failure, 4U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c2_sfEvent);
        chartInstance->c2_prev_signal = *c2_valid_signal;
        _SFD_DATA_RANGE_CHECK(chartInstance->c2_prev_signal, 5U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_count = 0;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_count, 6U);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                   chartInstance->c2_sfEvent);
      c2_h_out = (CV_TRANSITION_EVAL(26U, (int32_T)_SFD_CCP_CALL(26U, 0,
        chartInstance->c2_n == 1 != 0U, chartInstance->c2_sfEvent)) != 0);
      if (c2_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_Screen = c2_IN_one;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_one = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
        *c2_valid_signal = (*c2_signals)[_SFD_ARRAY_BOUNDS_CHECK(0U,
          chartInstance->c2_select[0] - 1, 1, 3, 1, 0)];
        _SFD_DATA_RANGE_CHECK(*c2_valid_signal, 3U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
        *c2_failure = FALSE;
        _SFD_DATA_RANGE_CHECK((real_T)*c2_failure, 4U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_prev_signal = *c2_valid_signal;
        _SFD_DATA_RANGE_CHECK(chartInstance->c2_prev_signal, 5U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c2_sfEvent);
        chartInstance->c2_count = 0;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_count, 6U);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_Screen = c2_IN_zero;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_zero = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c2_sfEvent);
        c2_none(chartInstance);
      }
    }
  }
}

static void c2_failure_logging(SFc2_asbhl20screenInstanceStruct *chartInstance)
{
  boolean_T c2_temp;
  boolean_T c2_b_temp;
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T *c2_logging;
  boolean_T *c2_failure;
  c2_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c2_sfEvent);
  switch (chartInstance->c2_is_failure_logging) {
   case c2_IN_logging:
    CV_STATE_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 chartInstance->c2_sfEvent);
    c2_temp = (_SFD_CCP_CALL(25U, 0, chartInstance->c2_sfEvent == CALL_EVENT !=
                0U, chartInstance->c2_sfEvent) != 0);
    if (c2_temp) {
      c2_temp = (_SFD_CCP_CALL(25U, 1, (int16_T)
                  chartInstance->c2_temporalCounter_i1 >= 30 != 0U,
                  chartInstance->c2_sfEvent) != 0);
    }

    c2_b_temp = c2_temp;
    if (c2_b_temp) {
      c2_b_temp = !(_SFD_CCP_CALL(25U, 2, *c2_failure != 0U,
        chartInstance->c2_sfEvent) != 0);
    }

    c2_out = (CV_TRANSITION_EVAL(25U, (int32_T)c2_b_temp) != 0);
    if (c2_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
      *c2_logging = FALSE;
      _SFD_DATA_RANGE_CHECK((real_T)*c2_logging, 10U);
      chartInstance->c2_tp_logging = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_failure_logging = c2_IN_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_off = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                   chartInstance->c2_sfEvent);
      c2_b_out = (CV_TRANSITION_EVAL(42U, (int32_T)_SFD_CCP_CALL(42U, 0,
        chartInstance->c2_sfEvent == c2_event_log != 0U,
        chartInstance->c2_sfEvent)) != 0);
      if (c2_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c2_sfEvent);
        *c2_logging = FALSE;
        _SFD_DATA_RANGE_CHECK((real_T)*c2_logging, 10U);
        chartInstance->c2_tp_logging = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_failure_logging = c2_IN_logging;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        *c2_logging = TRUE;
        _SFD_DATA_RANGE_CHECK((real_T)*c2_logging, 10U);
        chartInstance->c2_tp_logging = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c2_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_off:
    CV_STATE_EVAL(5, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                 chartInstance->c2_sfEvent);
    c2_c_out = (CV_TRANSITION_EVAL(33U, (int32_T)_SFD_CCP_CALL(33U, 0,
      chartInstance->c2_sfEvent == c2_event_log != 0U, chartInstance->c2_sfEvent))
                != 0);
    if (c2_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_failure_logging = c2_IN_logging;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
      chartInstance->c2_temporalCounter_i1 = 0U;
      *c2_logging = TRUE;
      _SFD_DATA_RANGE_CHECK((real_T)*c2_logging, 10U);
      chartInstance->c2_tp_logging = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 0, 0);
    chartInstance->c2_is_failure_logging = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c2_sfEvent);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_asbhl20screen_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static int8_T c2_valid_sensors(SFc2_asbhl20screenInstanceStruct *chartInstance)
{
  int8_T c2_num;
  boolean_T c2_aVarTruthTableCondition_3;
  boolean_T c2_aVarTruthTableCondition_2;
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_temp;
  boolean_T c2_b_temp;
  boolean_T c2_out;
  boolean_T c2_c_temp;
  boolean_T c2_d_temp;
  boolean_T c2_b_out;
  int32_T c2_i6;
  int32_T c2_i7;
  boolean_T c2_e_temp;
  boolean_T c2_f_temp;
  boolean_T c2_c_out;
  int32_T c2_i8;
  int32_T c2_i9;
  boolean_T c2_g_temp;
  boolean_T c2_h_temp;
  boolean_T c2_d_out;
  int32_T c2_i10;
  int32_T c2_i11;
  boolean_T c2_i_temp;
  boolean_T c2_j_temp;
  boolean_T c2_e_out;
  int32_T c2_i12;
  int32_T c2_i13;
  boolean_T c2_k_temp;
  boolean_T c2_l_temp;
  boolean_T c2_f_out;
  int32_T c2_i14;
  int32_T c2_i15;
  boolean_T c2_m_temp;
  boolean_T c2_n_temp;
  boolean_T c2_g_out;
  int32_T c2_i16;
  int32_T c2_i17;
  boolean_T c2_o_temp;
  boolean_T c2_p_temp;
  boolean_T c2_h_out;
  boolean_T (*c2_validity)[3];
  c2_validity = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_SET_DATA_VALUE_PTR(15U, &c2_num);
  _SFD_SET_DATA_VALUE_PTR(18U, &c2_aVarTruthTableCondition_3);
  _SFD_SET_DATA_VALUE_PTR(17U, &c2_aVarTruthTableCondition_2);
  _SFD_SET_DATA_VALUE_PTR(16U, &c2_aVarTruthTableCondition_1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(4U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("num", &c2_num, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("aVarTruthTableCondition_1",
    &c2_aVarTruthTableCondition_1, c2_g_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("aVarTruthTableCondition_2",
    &c2_aVarTruthTableCondition_2, c2_g_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("aVarTruthTableCondition_3",
    &c2_aVarTruthTableCondition_3, c2_g_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c2_sfEvent);
  c2_aVarTruthTableCondition_1 = FALSE;
  _SFD_DATA_RANGE_CHECK((real_T)c2_aVarTruthTableCondition_1, 16U);
  c2_aVarTruthTableCondition_2 = FALSE;
  _SFD_DATA_RANGE_CHECK((real_T)c2_aVarTruthTableCondition_2, 17U);
  c2_aVarTruthTableCondition_3 = FALSE;
  _SFD_DATA_RANGE_CHECK((real_T)c2_aVarTruthTableCondition_3, 18U);
  c2_num = 0;
  _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c2_sfEvent);
  c2_aVarTruthTableCondition_1 = ((int16_T)(*c2_validity)[0] == 1);
  _SFD_DATA_RANGE_CHECK((real_T)c2_aVarTruthTableCondition_1, 16U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c2_sfEvent);
  c2_aVarTruthTableCondition_2 = ((int16_T)(*c2_validity)[1] == 1);
  _SFD_DATA_RANGE_CHECK((real_T)c2_aVarTruthTableCondition_2, 17U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c2_sfEvent);
  c2_aVarTruthTableCondition_3 = ((int16_T)(*c2_validity)[2] == 1);
  _SFD_DATA_RANGE_CHECK((real_T)c2_aVarTruthTableCondition_3, 18U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U, chartInstance->c2_sfEvent);
  c2_temp = (_SFD_CCP_CALL(47U, 0, c2_aVarTruthTableCondition_1 != 0U,
              chartInstance->c2_sfEvent) != 0);
  if (c2_temp) {
    c2_temp = (_SFD_CCP_CALL(47U, 1, c2_aVarTruthTableCondition_2 != 0U,
                chartInstance->c2_sfEvent) != 0);
  }

  c2_b_temp = c2_temp;
  if (c2_b_temp) {
    c2_b_temp = (_SFD_CCP_CALL(47U, 2, c2_aVarTruthTableCondition_3 != 0U,
      chartInstance->c2_sfEvent) != 0);
  }

  c2_out = (CV_TRANSITION_EVAL(47U, (int32_T)c2_b_temp) != 0);
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c2_sfEvent);
    c2_num = 3;
    _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 50U,
                 chartInstance->c2_sfEvent);
    c2_c_temp = (_SFD_CCP_CALL(50U, 0, c2_aVarTruthTableCondition_1 != 0U,
      chartInstance->c2_sfEvent) != 0);
    if (c2_c_temp) {
      c2_c_temp = (_SFD_CCP_CALL(50U, 1, c2_aVarTruthTableCondition_2 != 0U,
        chartInstance->c2_sfEvent) != 0);
    }

    c2_d_temp = c2_c_temp;
    if (c2_d_temp) {
      c2_d_temp = !(_SFD_CCP_CALL(50U, 2, c2_aVarTruthTableCondition_3 != 0U,
        chartInstance->c2_sfEvent) != 0);
    }

    c2_b_out = (CV_TRANSITION_EVAL(50U, (int32_T)c2_d_temp) != 0);
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c2_sfEvent);
      c2_num = 2;
      _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
      chartInstance->c2_select[0] = 1;
      for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i6], 9U);
      }

      chartInstance->c2_select[1] = 2;
      for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i7], 9U);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U,
                   chartInstance->c2_sfEvent);
      c2_e_temp = (_SFD_CCP_CALL(53U, 0, c2_aVarTruthTableCondition_1 != 0U,
        chartInstance->c2_sfEvent) != 0);
      if (c2_e_temp) {
        c2_e_temp = !(_SFD_CCP_CALL(53U, 1, c2_aVarTruthTableCondition_2 != 0U,
          chartInstance->c2_sfEvent) != 0);
      }

      c2_f_temp = c2_e_temp;
      if (c2_f_temp) {
        c2_f_temp = (_SFD_CCP_CALL(53U, 2, c2_aVarTruthTableCondition_3 != 0U,
          chartInstance->c2_sfEvent) != 0);
      }

      c2_c_out = (CV_TRANSITION_EVAL(53U, (int32_T)c2_f_temp) != 0);
      if (c2_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, chartInstance->c2_sfEvent);
        c2_num = 2;
        _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
        chartInstance->c2_select[0] = 1;
        for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i8], 9U);
        }

        chartInstance->c2_select[1] = 3;
        for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i9], 9U);
        }
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 56U,
                     chartInstance->c2_sfEvent);
        c2_g_temp = (_SFD_CCP_CALL(56U, 0, c2_aVarTruthTableCondition_1 != 0U,
          chartInstance->c2_sfEvent) != 0);
        if (c2_g_temp) {
          c2_g_temp = !(_SFD_CCP_CALL(56U, 1, c2_aVarTruthTableCondition_2 != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_h_temp = c2_g_temp;
        if (c2_h_temp) {
          c2_h_temp = !(_SFD_CCP_CALL(56U, 2, c2_aVarTruthTableCondition_3 != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_d_out = (CV_TRANSITION_EVAL(56U, (int32_T)c2_h_temp) != 0);
        if (c2_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c2_sfEvent);
          c2_num = 1;
          _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
          chartInstance->c2_select[0] = 1;
          for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i10], 9U);
          }

          chartInstance->c2_select[1] = 0;
          for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i11], 9U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 59U,
                       chartInstance->c2_sfEvent);
          c2_i_temp = !(_SFD_CCP_CALL(59U, 0, c2_aVarTruthTableCondition_1 != 0U,
            chartInstance->c2_sfEvent) != 0);
          if (c2_i_temp) {
            c2_i_temp = (_SFD_CCP_CALL(59U, 1, c2_aVarTruthTableCondition_2 !=
              0U, chartInstance->c2_sfEvent) != 0);
          }

          c2_j_temp = c2_i_temp;
          if (c2_j_temp) {
            c2_j_temp = (_SFD_CCP_CALL(59U, 2, c2_aVarTruthTableCondition_3 !=
              0U, chartInstance->c2_sfEvent) != 0);
          }

          c2_e_out = (CV_TRANSITION_EVAL(59U, (int32_T)c2_j_temp) != 0);
          if (c2_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, chartInstance->c2_sfEvent);
            c2_num = 2;
            _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
            chartInstance->c2_select[0] = 2;
            for (c2_i12 = 0; c2_i12 < 2; c2_i12++) {
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i12], 9U);
            }

            chartInstance->c2_select[1] = 3;
            for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i13], 9U);
            }
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 62U,
                         chartInstance->c2_sfEvent);
            c2_k_temp = !(_SFD_CCP_CALL(62U, 0, c2_aVarTruthTableCondition_1 !=
              0U, chartInstance->c2_sfEvent) != 0);
            if (c2_k_temp) {
              c2_k_temp = (_SFD_CCP_CALL(62U, 1, c2_aVarTruthTableCondition_2 !=
                0U, chartInstance->c2_sfEvent) != 0);
            }

            c2_l_temp = c2_k_temp;
            if (c2_l_temp) {
              c2_l_temp = !(_SFD_CCP_CALL(62U, 2, c2_aVarTruthTableCondition_3
                != 0U, chartInstance->c2_sfEvent) != 0);
            }

            c2_f_out = (CV_TRANSITION_EVAL(62U, (int32_T)c2_l_temp) != 0);
            if (c2_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, chartInstance->c2_sfEvent);
              c2_num = 1;
              _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
              chartInstance->c2_select[0] = 2;
              for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i14],
                                      9U);
              }

              chartInstance->c2_select[1] = 0;
              for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i15],
                                      9U);
              }
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, chartInstance->c2_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U,
                           chartInstance->c2_sfEvent);
              c2_m_temp = !(_SFD_CCP_CALL(65U, 0, c2_aVarTruthTableCondition_1
                != 0U, chartInstance->c2_sfEvent) != 0);
              if (c2_m_temp) {
                c2_m_temp = !(_SFD_CCP_CALL(65U, 1, c2_aVarTruthTableCondition_2
                  != 0U, chartInstance->c2_sfEvent) != 0);
              }

              c2_n_temp = c2_m_temp;
              if (c2_n_temp) {
                c2_n_temp = (_SFD_CCP_CALL(65U, 2, c2_aVarTruthTableCondition_3
                  != 0U, chartInstance->c2_sfEvent) != 0);
              }

              c2_g_out = (CV_TRANSITION_EVAL(65U, (int32_T)c2_n_temp) != 0);
              if (c2_g_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U,
                             chartInstance->c2_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U,
                             chartInstance->c2_sfEvent);
                c2_num = 1;
                _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
                chartInstance->c2_select[0] = 3;
                for (c2_i16 = 0; c2_i16 < 2; c2_i16++) {
                  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i16],
                                        9U);
                }

                chartInstance->c2_select[1] = 0;
                for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
                  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_select[c2_i17],
                                        9U);
                }
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U,
                             chartInstance->c2_sfEvent);
                _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 68U,
                             chartInstance->c2_sfEvent);
                c2_o_temp = !(_SFD_CCP_CALL(68U, 0, c2_aVarTruthTableCondition_1
                  != 0U, chartInstance->c2_sfEvent) != 0);
                if (c2_o_temp) {
                  c2_o_temp = !(_SFD_CCP_CALL(68U, 1,
                    c2_aVarTruthTableCondition_2 != 0U,
                    chartInstance->c2_sfEvent) != 0);
                }

                c2_p_temp = c2_o_temp;
                if (c2_p_temp) {
                  c2_p_temp = !(_SFD_CCP_CALL(68U, 2,
                    c2_aVarTruthTableCondition_3 != 0U,
                    chartInstance->c2_sfEvent) != 0);
                }

                c2_h_out = (CV_TRANSITION_EVAL(68U, (int32_T)c2_p_temp) != 0);
                if (c2_h_out) {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U,
                               chartInstance->c2_sfEvent);
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U,
                               chartInstance->c2_sfEvent);
                  c2_num = 0;
                  _SFD_DATA_RANGE_CHECK((real_T)c2_num, 15U);
                } else {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U,
                               chartInstance->c2_sfEvent);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(15U);
  _SFD_UNSET_DATA_VALUE_PTR(18U);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_UNSET_DATA_VALUE_PTR(16U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c2_sfEvent);
  return c2_num;
}

static void c2_none(SFc2_asbhl20screenInstanceStruct *chartInstance)
{
  boolean_T c2_out;
  int32_T c2_previousEvent;
  real_T *c2_valid_signal;
  boolean_T *c2_failure;
  c2_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  chartInstance->c2_count = c2__s8_s32_(chartInstance, chartInstance->c2_count +
    1);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_count, 6U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(9U, (int32_T)_SFD_CCP_CALL(9U, 0,
              chartInstance->c2_count > 3 != 0U, chartInstance->c2_sfEvent)) !=
            0);
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    chartInstance->c2_count = 3;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_count, 6U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    *c2_valid_signal = 0.0;
    _SFD_DATA_RANGE_CHECK(*c2_valid_signal, 3U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c2_sfEvent);
    *c2_failure = TRUE;
    _SFD_DATA_RANGE_CHECK((real_T)*c2_failure, 4U);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
    *c2_valid_signal = chartInstance->c2_prev_signal;
    _SFD_DATA_RANGE_CHECK(*c2_valid_signal, 3U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
    *c2_failure = FALSE;
    _SFD_DATA_RANGE_CHECK((real_T)*c2_failure, 4U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    c2_previousEvent = chartInstance->c2_sfEvent;
    chartInstance->c2_sfEvent = c2_event_log;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c2_event_log,
                 chartInstance->c2_sfEvent);
    if (chartInstance->c2_is_active_failure_logging == 0U) {
    } else {
      c2_failure_logging(chartInstance);
    }

    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c2_event_log,
                 chartInstance->c2_sfEvent);
    chartInstance->c2_sfEvent = c2_previousEvent;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i18;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i18, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i18;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_one, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_one),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_one);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_one;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_b_tp_one = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_one),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_one);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i19;
  real_T c2_b_inData[3];
  int32_T c2_i20;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i19 = 0; c2_i19 < 3; c2_i19++) {
    c2_b_inData[c2_i19] = (*(real_T (*)[3])c2_inData)[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
    c2_u[c2_i20] = c2_b_inData[c2_i20];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i21;
  boolean_T c2_b_inData[3];
  int32_T c2_i22;
  boolean_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
    c2_b_inData[c2_i21] = (*(boolean_T (*)[3])c2_inData)[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 3; c2_i22++) {
    c2_u[c2_i22] = c2_b_inData[c2_i22];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 11, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 2, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int8_T c2_d_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_b_n, const char_T *c2_identifier)
{
  int8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_n), &c2_thisId);
  sf_mex_destroy(&c2_b_n);
  return c2_y;
}

static int8_T c2_e_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int8_T c2_y;
  int8_T c2_i23;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i23, 1, 2, 0U, 0, 0U, 0);
  c2_y = c2_i23;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_n;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int8_T c2_y;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_b_n = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_n), &c2_thisId);
  sf_mex_destroy(&c2_b_n);
  *(int8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_f_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_valid_signal, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_valid_signal),
    &c2_thisId);
  sf_mex_destroy(&c2_valid_signal);
  return c2_y;
}

static real_T c2_g_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_valid_signal;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_valid_signal = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_valid_signal),
    &c2_thisId);
  sf_mex_destroy(&c2_valid_signal);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static boolean_T c2_h_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_failure, const char_T *c2_identifier)
{
  boolean_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_failure), &c2_thisId);
  sf_mex_destroy(&c2_failure);
  return c2_y;
}

static boolean_T c2_i_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_failure;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_failure = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_failure), &c2_thisId);
  sf_mex_destroy(&c2_failure);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i24;
  int8_T c2_b_inData[2];
  int32_T c2_i25;
  int8_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    c2_b_inData[c2_i24] = (*(int8_T (*)[2])c2_inData)[c2_i24];
  }

  for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
    c2_u[c2_i25] = c2_b_inData[c2_i25];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 2, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_j_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_b_select, const char_T *c2_identifier,
  int8_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_select), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_select);
}

static void c2_k_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int8_T c2_y[2])
{
  int8_T c2_iv1[2];
  int32_T c2_i26;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_iv1, 1, 2, 0U, 1, 0U, 1, 2);
  for (c2_i26 = 0; c2_i26 < 2; c2_i26++) {
    c2_y[c2_i26] = c2_iv1[c2_i26];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_select;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int8_T c2_y[2];
  int32_T c2_i27;
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)chartInstanceVoid;
  c2_b_select = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_select), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_select);
  for (c2_i27 = 0; c2_i27 < 2; c2_i27++) {
    (*(int8_T (*)[2])c2_outData)[c2_i27] = c2_y[c2_i27];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_l_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), FALSE);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_m_emlrt_marshallIn(SFc2_asbhl20screenInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static uint8_T c2__u8_s32_(SFc2_asbhl20screenInstanceStruct *chartInstance,
  int32_T c2_b)
{
  uint8_T c2_a;
  c2_a = (uint8_T)c2_b;
  if (c2_a != c2_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW);
  }

  return c2_a;
}

static int8_T c2__s8_s32_(SFc2_asbhl20screenInstanceStruct *chartInstance,
  int32_T c2_b)
{
  int8_T c2_a;
  c2_a = (int8_T)c2_b;
  if (c2_a != c2_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW);
  }

  return c2_a;
}

static void init_dsm_address_info(SFc2_asbhl20screenInstanceStruct
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

void sf_c2_asbhl20screen_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1189673390U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3468140533U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3645177890U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2418357365U);
}

mxArray *sf_c2_asbhl20screen_get_autoinheritance_info(void)
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

mxArray *sf_c2_asbhl20screen_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_asbhl20screen(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[146],T\"failure\",},{M[1],M[145],T\"valid_signal\",},{M[2],M[152],T\"logging\",},{M[3],M[150],T\"bad\",},{M[3],M[148],T\"count\",},{M[3],M[157],T\"diff\",},{M[3],M[158],T\"mean\",},{M[3],M[153],T\"middle\",},{M[3],M[144],T\"n\",},{M[3],M[147],T\"prev_signal\",}}",
    "100 S1x8'type','srcId','name','auxInfo'{{M[3],M[151],T\"select\",},{M[3],M[154],T\"sum\",},{M[8],M[0],T\"is_active_c2_asbhl20screen\",},{M[8],M[5],T\"is_active_Screen\",},{M[8],M[10],T\"is_active_failure_logging\",},{M[9],M[5],T\"is_Screen\",},{M[9],M[10],T\"is_failure_logging\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"wu\",M[11],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 18, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_asbhl20screen_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_asbhl20screenInstanceStruct *chartInstance;
    chartInstance = (SFc2_asbhl20screenInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _asbhl20screenMachineNumber_,
           2,
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
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(9,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(20,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(26,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(41,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(28,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(33,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(42,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);

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

        _SFD_TRANS_COV_WTS(5,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(5,
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

        _SFD_TRANS_COV_WTS(1,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(38,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(38,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(8,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(10,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(12,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(27,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(27,
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

        _SFD_TRANS_COV_WTS(18,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(18,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(15,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(15,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(17,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(17,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(37,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(37,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(20,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(20,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(26,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(26,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(35,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(35,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(24,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(24,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(22,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(22,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(41,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(41,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
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

        _SFD_TRANS_COV_WTS(6,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(6,
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

        _SFD_TRANS_COV_WTS(3,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(3,
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

        _SFD_TRANS_COV_WTS(40,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(40,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(28,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(28,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(31,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(31,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(21,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(21,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(30,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(30,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(29,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(29,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(39,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(39,
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

        _SFD_TRANS_COV_WTS(36,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(36,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(33,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          _SFD_TRANS_COV_MAPS(33,
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

        _SFD_TRANS_COV_WTS(32,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(32,
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
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT8,1,&(dimVector[0]),0,0,0,0.0,1.0,
            0,0,(MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)
            c2_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));

        {
          real_T *c2_valid_signal;
          boolean_T *c2_failure;
          boolean_T *c2_logging;
          real_T (*c2_signals)[3];
          boolean_T (*c2_validity)[3];
          c2_logging = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_failure = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_valid_signal = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_validity = (boolean_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            1);
          c2_signals = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_signals);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_validity);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c2_n);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_valid_signal);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_failure);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c2_prev_signal);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c2_count);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c2_diff_max);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c2_bad);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c2_select);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_logging);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c2_middle);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c2_sum);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c2_diff);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c2_mean);
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
  return "jL0nCqPLkej4c2ollj76yE";
}

static void sf_opaque_initialize_c2_asbhl20screen(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_asbhl20screenInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*)
    chartInstanceVar);
  initialize_c2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_asbhl20screen(void *chartInstanceVar)
{
  enable_c2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_asbhl20screen(void *chartInstanceVar)
{
  disable_c2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_asbhl20screen(void *chartInstanceVar)
{
  sf_c2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_asbhl20screen(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_asbhl20screen
    ((SFc2_asbhl20screenInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_asbhl20screen();/* state var info */
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

extern void sf_internal_set_sim_state_c2_asbhl20screen(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_asbhl20screen();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_asbhl20screen(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_asbhl20screen(S);
}

static void sf_opaque_set_sim_state_c2_asbhl20screen(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_asbhl20screen(S, st);
}

static void sf_opaque_terminate_c2_asbhl20screen(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_asbhl20screenInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_asbhl20screen_optimization_info();
    }

    finalize_c2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_asbhl20screen(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_asbhl20screen((SFc2_asbhl20screenInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_asbhl20screen(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_asbhl20screen_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1451636616U));
  ssSetChecksum1(S,(2768456571U));
  ssSetChecksum2(S,(1470708751U));
  ssSetChecksum3(S,(3336329670U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_asbhl20screen(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_asbhl20screen(SimStruct *S)
{
  SFc2_asbhl20screenInstanceStruct *chartInstance;
  chartInstance = (SFc2_asbhl20screenInstanceStruct *)utMalloc(sizeof
    (SFc2_asbhl20screenInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_asbhl20screenInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_asbhl20screen;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_asbhl20screen;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_asbhl20screen;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_asbhl20screen;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_asbhl20screen;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_asbhl20screen;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_asbhl20screen;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_asbhl20screen;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_asbhl20screen;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_asbhl20screen;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_asbhl20screen;
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

void c2_asbhl20screen_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_asbhl20screen(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_asbhl20screen(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_asbhl20screen(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_asbhl20screen_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
