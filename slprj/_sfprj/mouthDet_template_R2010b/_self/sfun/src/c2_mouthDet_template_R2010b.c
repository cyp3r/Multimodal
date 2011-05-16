/* Include files */

#include "blascompat32.h"
#include "mouthDet_template_R2010b_sfun.h"
#include "c2_mouthDet_template_R2010b.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "mouthDet_template_R2010b_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[21] = { "m", "n", "ilobj", "rotFeret",
  "i", "min", "mini", "nargin", "nargout", "Original", "Area", "Centroid",
  "BBox", "MajorAxis", "MinorAxis", "Orientation", "Label", "L", "Lorig", "k",
  "mouth" };

/* Function Declarations */
static void initialize_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static void initialize_params_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static void enable_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static void disable_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static void set_sim_state_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static void sf_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static void c2_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_mrdivide(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_A[250], real_T c2_B[250]);
static void c2_eml_zlaqp2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_A[250], real_T c2_b_A[250], real_T *c2_tau, int32_T *
  c2_jpvt);
static void c2_eml_scalar_eg(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance);
static void c2_eps(SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance);
static real_T c2_sqrt(SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance,
                      real_T c2_x);
static void c2_eml_error(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance);
static real_T c2_eml_xnrm2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_x[250], int32_T c2_ix0);
static boolean_T c2_eml_use_refblas(SFc2_mouthDet_template_R2010bInstanceStruct *
  chartInstance);
static real_T c2_ceval_xnrm2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[250], int32_T c2_ix0, int32_T
  c2_incx);
static int32_T c2_ceval_ixamax(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x, int32_T c2_ix0, int32_T c2_incx);
static void c2_eml_xswap(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_x[250], int32_T c2_ix0, real_T c2_b_x[250]);
static void c2_eml_blas_xswap(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[250], int32_T c2_ix0, int32_T
  c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[250]);
static void c2_eml_refblas_xswap(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[250], int32_T c2_ix0, int32_T
  c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[250]);
static void c2_ceval_xswap(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[250], int32_T c2_ix0, int32_T
  c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[250]);
static real_T c2_b_eml_xnrm2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_x[250]);
static real_T c2_eml_dlapy2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_x1, real_T c2_x2);
static void c2_eml_xscal(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_a, real_T c2_x[250], real_T c2_b_x[250]);
static void c2_ceval_xscal(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[250], int32_T c2_ix0,
  int32_T c2_incx, real_T c2_b_x[250]);
static void c2_eml_warning(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_varargin_3, real_T c2_varargin_4);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[88]);
static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[88]);
static const mxArray *c2_g_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_h_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_i_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_emlrt_marshallIn(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, const mxArray *c2_L, const char_T *c2_name, uint8_T c2_y
  [434336]);
static real_T c2_b_emlrt_marshallIn(SFc2_mouthDet_template_R2010bInstanceStruct *
  chartInstance, const mxArray *c2_k, const char_T *c2_name);
static uint8_T c2_c_emlrt_marshallIn(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_mouthDet_template_R2010b,
  const char_T *c2_name);
static void init_dsm_address_info(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_mouthDet_template_R2010b = 0U;
}

static void initialize_params_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
}

static void enable_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  static uint8_T c2_hoistedGlobal[434336];
  int32_T c2_i1;
  static uint8_T c2_u[434336];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i2;
  static uint8_T c2_b_hoistedGlobal[434336];
  int32_T c2_i3;
  static uint8_T c2_b_u[434336];
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_k;
  real_T *c2_mouth;
  uint8_T (*c2_Lorig)[434336];
  uint8_T (*c2_L)[434336];
  c2_mouth = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Lorig = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_L = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5));
  for (c2_i0 = 0; c2_i0 < 434336; c2_i0 = c2_i0 + 1) {
    c2_hoistedGlobal[c2_i0] = (*c2_L)[c2_i0];
  }

  for (c2_i1 = 0; c2_i1 < 434336; c2_i1 = c2_i1 + 1) {
    c2_u[c2_i1] = c2_hoistedGlobal[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 1U, 0U, 2, 554, 784));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i2 = 0; c2_i2 < 434336; c2_i2 = c2_i2 + 1) {
    c2_b_hoistedGlobal[c2_i2] = (*c2_Lorig)[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 434336; c2_i3 = c2_i3 + 1) {
    c2_b_u[c2_i3] = c2_b_hoistedGlobal[c2_i3];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 1U, 0U, 2, 554, 784));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_k;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_mouth;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_active_c2_mouthDet_template_R2010b;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance, const mxArray *
   c2_st)
{
  const mxArray *c2_u;
  static uint8_T c2_uv0[434336];
  int32_T c2_i4;
  static uint8_T c2_uv1[434336];
  int32_T c2_i5;
  real_T *c2_k;
  real_T *c2_mouth;
  uint8_T (*c2_L)[434336];
  uint8_T (*c2_Lorig)[434336];
  c2_mouth = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Lorig = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_L = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "L",
                      c2_uv0);
  for (c2_i4 = 0; c2_i4 < 434336; c2_i4 = c2_i4 + 1) {
    (*c2_L)[c2_i4] = c2_uv0[c2_i4];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                      "Lorig", c2_uv1);
  for (c2_i5 = 0; c2_i5 < 434336; c2_i5 = c2_i5 + 1) {
    (*c2_Lorig)[c2_i5] = c2_uv1[c2_i5];
  }

  *c2_k = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "k");
  *c2_mouth = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "mouth");
  chartInstance->c2_is_active_c2_mouthDet_template_R2010b =
    c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
    "is_active_c2_mouthDet_template_R2010b");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_mouthDet_template_R2010b(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
}

static void sf_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_previousEvent;
  real_T *c2_k;
  real_T *c2_mouth;
  uint8_T (*c2_Label)[434336];
  real_T (*c2_Orientation)[250];
  real_T (*c2_MinorAxis)[250];
  real_T (*c2_MajorAxis)[250];
  int32_T (*c2_BBox)[1000];
  real_T (*c2_Centroid)[500];
  uint8_T (*c2_Lorig)[434336];
  uint8_T (*c2_L)[434336];
  int32_T (*c2_Area)[250];
  uint8_T (*c2_Original)[434336];
  c2_mouth = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_Label = (uint8_T (*)[434336])ssGetInputPortSignal(chartInstance->S, 7);
  c2_Orientation = (real_T (*)[250])ssGetInputPortSignal(chartInstance->S, 6);
  c2_MinorAxis = (real_T (*)[250])ssGetInputPortSignal(chartInstance->S, 5);
  c2_MajorAxis = (real_T (*)[250])ssGetInputPortSignal(chartInstance->S, 4);
  c2_BBox = (int32_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 3);
  c2_Centroid = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 2);
  c2_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Lorig = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_L = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_Area = (int32_T (*)[250])ssGetInputPortSignal(chartInstance->S, 1);
  c2_Original = (uint8_T (*)[434336])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c2_i6 = 0; c2_i6 < 434336; c2_i6 = c2_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_Original)[c2_i6], 0U);
  }

  for (c2_i7 = 0; c2_i7 < 250; c2_i7 = c2_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_Area)[c2_i7], 1U);
  }

  for (c2_i8 = 0; c2_i8 < 434336; c2_i8 = c2_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_L)[c2_i8], 2U);
  }

  for (c2_i9 = 0; c2_i9 < 434336; c2_i9 = c2_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_Lorig)[c2_i9], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_k, 4U);
  for (c2_i10 = 0; c2_i10 < 500; c2_i10 = c2_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_Centroid)[c2_i10], 5U);
  }

  for (c2_i11 = 0; c2_i11 < 1000; c2_i11 = c2_i11 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_BBox)[c2_i11], 6U);
  }

  for (c2_i12 = 0; c2_i12 < 250; c2_i12 = c2_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_MajorAxis)[c2_i12], 7U);
  }

  for (c2_i13 = 0; c2_i13 < 250; c2_i13 = c2_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_MinorAxis)[c2_i13], 8U);
  }

  for (c2_i14 = 0; c2_i14 < 250; c2_i14 = c2_i14 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_Orientation)[c2_i14], 9U);
  }

  for (c2_i15 = 0; c2_i15 < 434336; c2_i15 = c2_i15 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_Label)[c2_i15], 10U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_mouth, 11U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_mouthDet_template_R2010b(chartInstance);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_mouthDet_template_R2010bMachineNumber_,
    chartInstance->chartNumber, chartInstance->
    instanceNumber);
}

static void c2_c2_mouthDet_template_R2010b
  (SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
  int32_T c2_i16;
  static uint8_T c2_hoistedGlobal[434336];
  int32_T c2_i17;
  int32_T c2_b_hoistedGlobal[250];
  int32_T c2_i18;
  real_T c2_c_hoistedGlobal[500];
  int32_T c2_i19;
  int32_T c2_d_hoistedGlobal[1000];
  int32_T c2_i20;
  real_T c2_e_hoistedGlobal[250];
  int32_T c2_i21;
  real_T c2_f_hoistedGlobal[250];
  int32_T c2_i22;
  real_T c2_g_hoistedGlobal[250];
  int32_T c2_i23;
  static uint8_T c2_h_hoistedGlobal[434336];
  int32_T c2_i24;
  static uint8_T c2_Original[434336];
  int32_T c2_i25;
  int32_T c2_Area[250];
  int32_T c2_i26;
  real_T c2_Centroid[500];
  int32_T c2_i27;
  int32_T c2_BBox[1000];
  int32_T c2_i28;
  real_T c2_MajorAxis[250];
  int32_T c2_i29;
  real_T c2_MinorAxis[250];
  int32_T c2_i30;
  real_T c2_Orientation[250];
  int32_T c2_i31;
  static uint8_T c2_Label[434336];
  uint32_T c2_debug_family_var_map[21];
  static const char *c2_sv0[21] = { "m", "n", "ilobj", "rotFeret", "i", "min",
    "mini", "nargin", "nargout", "Original", "Area",
    "Centroid", "BBox", "MajorAxis", "MinorAxis", "Orientation", "Label", "L",
    "Lorig", "k", "mouth" };

  real_T c2_m;
  real_T c2_n;
  real_T c2_ilobj;
  real_T c2_rotFeret[250];
  real_T c2_i;
  real_T c2_min;
  real_T c2_mini;
  real_T c2_nargin = 8.0;
  real_T c2_nargout = 4.0;
  static uint8_T c2_L[434336];
  static uint8_T c2_Lorig[434336];
  real_T c2_k;
  real_T c2_mouth;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  static uint8_T c2_u[434336];
  const mxArray *c2_y = NULL;
  int32_T c2_i35;
  real_T c2_b_i;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_b_y;
  int32_T c2_i36;
  real_T c2_b_MajorAxis[250];
  int32_T c2_i37;
  real_T c2_b_MinorAxis[250];
  int32_T c2_i38;
  real_T c2_c_x[250];
  real_T c2_b_k;
  real_T c2_c_k;
  real_T c2_d_x;
  real_T c2_c_y;
  int32_T c2_i39;
  real_T c2_varargin_1[250];
  int32_T c2_i40;
  real_T c2_e_x[250];
  int32_T c2_i41;
  real_T c2_f_x[250];
  real_T c2_mtmp;
  int32_T c2_itmp;
  int32_T c2_ix;
  real_T c2_g_x;
  boolean_T c2_b;
  boolean_T c2_searchingForNonNaN;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_a;
  real_T c2_h_x;
  boolean_T c2_b_b;
  int32_T c2_b_a;
  int32_T c2_i42;
  int32_T c2_f_k;
  int32_T c2_c_a;
  real_T c2_b_mtmp;
  int32_T c2_b_itmp;
  real_T c2_minval;
  real_T c2_indx;
  real_T c2_b_min;
  real_T c2_b_mini;
  real_T c2_b_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i43;
  static uint8_T c2_d_a[434336];
  int32_T c2_i44;
  static uint8_T c2_g_y[434336];
  int32_T c2_i45;
  uint32_T c2_u0;
  uint8_T c2_u1;
  int32_T c2_i46;
  static uint8_T c2_e_a[434336];
  int32_T c2_i47;
  uint32_T c2_u2;
  uint8_T c2_u3;
  static uint8_T c2_h_y[434336];
  int32_T c2_i48;
  uint32_T c2_u4;
  uint8_T c2_u5;
  int32_T c2_i49;
  int32_T c2_i50;
  real_T *c2_b_mouth;
  real_T *c2_g_k;
  uint8_T (*c2_b_L)[434336];
  uint8_T (*c2_b_Lorig)[434336];
  uint8_T (*c2_b_Label)[434336];
  real_T (*c2_b_Orientation)[250];
  real_T (*c2_c_MinorAxis)[250];
  real_T (*c2_c_MajorAxis)[250];
  int32_T (*c2_b_BBox)[1000];
  real_T (*c2_b_Centroid)[500];
  int32_T (*c2_b_Area)[250];
  uint8_T (*c2_b_Original)[434336];
  c2_b_mouth = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_Label = (uint8_T (*)[434336])ssGetInputPortSignal(chartInstance->S, 7);
  c2_b_Orientation = (real_T (*)[250])ssGetInputPortSignal(chartInstance->S, 6);
  c2_c_MinorAxis = (real_T (*)[250])ssGetInputPortSignal(chartInstance->S, 5);
  c2_c_MajorAxis = (real_T (*)[250])ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_BBox = (int32_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_Centroid = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 2);
  c2_g_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_Lorig = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_L = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_Area = (int32_T (*)[250])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_Original = (uint8_T (*)[434336])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c2_i16 = 0; c2_i16 < 434336; c2_i16 = c2_i16 + 1) {
    c2_hoistedGlobal[c2_i16] = (*c2_b_Original)[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 250; c2_i17 = c2_i17 + 1) {
    c2_b_hoistedGlobal[c2_i17] = (*c2_b_Area)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 500; c2_i18 = c2_i18 + 1) {
    c2_c_hoistedGlobal[c2_i18] = (*c2_b_Centroid)[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 1000; c2_i19 = c2_i19 + 1) {
    c2_d_hoistedGlobal[c2_i19] = (*c2_b_BBox)[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 250; c2_i20 = c2_i20 + 1) {
    c2_e_hoistedGlobal[c2_i20] = (*c2_c_MajorAxis)[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 250; c2_i21 = c2_i21 + 1) {
    c2_f_hoistedGlobal[c2_i21] = (*c2_c_MinorAxis)[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 250; c2_i22 = c2_i22 + 1) {
    c2_g_hoistedGlobal[c2_i22] = (*c2_b_Orientation)[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 434336; c2_i23 = c2_i23 + 1) {
    c2_h_hoistedGlobal[c2_i23] = (*c2_b_Label)[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 434336; c2_i24 = c2_i24 + 1) {
    c2_Original[c2_i24] = c2_hoistedGlobal[c2_i24];
  }

  for (c2_i25 = 0; c2_i25 < 250; c2_i25 = c2_i25 + 1) {
    c2_Area[c2_i25] = c2_b_hoistedGlobal[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 500; c2_i26 = c2_i26 + 1) {
    c2_Centroid[c2_i26] = c2_c_hoistedGlobal[c2_i26];
  }

  for (c2_i27 = 0; c2_i27 < 1000; c2_i27 = c2_i27 + 1) {
    c2_BBox[c2_i27] = c2_d_hoistedGlobal[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 250; c2_i28 = c2_i28 + 1) {
    c2_MajorAxis[c2_i28] = c2_e_hoistedGlobal[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 250; c2_i29 = c2_i29 + 1) {
    c2_MinorAxis[c2_i29] = c2_f_hoistedGlobal[c2_i29];
  }

  for (c2_i30 = 0; c2_i30 < 250; c2_i30 = c2_i30 + 1) {
    c2_Orientation[c2_i30] = c2_g_hoistedGlobal[c2_i30];
  }

  for (c2_i31 = 0; c2_i31 < 434336; c2_i31 = c2_i31 + 1) {
    c2_Label[c2_i31] = c2_h_hoistedGlobal[c2_i31];
  }

  sf_debug_symbol_scope_push_eml(0U, 21U, 21U, c2_sv0, c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_m, c2_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_n, c2_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_ilobj, c2_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_rotFeret, c2_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_i, c2_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_min, c2_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c2_mini, c2_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c2_Original, c2_b_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c2_Area, c2_f_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c2_Centroid, c2_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c2_BBox, c2_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c2_MajorAxis, c2_c_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c2_MinorAxis, c2_c_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c2_Orientation, c2_c_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c2_Label, c2_b_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c2_L, c2_b_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c2_Lorig, c2_b_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c2_k, c2_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c2_mouth, c2_sf_marshall, 20U);
  CV_EML_FCN(0, 0);

  /*  Analiza i detekcja mrugniec */
  /*  INPUTS: */
  /*  > Area, Centroid, BBox, MajorAxis, MinorAxis, Orientation, Label */
  /*     dane z bloku "Blob analysis" */
  /*  OUTPUTS: */
  /*  > L     - obraz indeksowany po analizie */
  /*  > k     - ilosc obiektow po analizie */
  /*  > mouth - sygnal [0,1] informujacy o fakcie detekcji ruchu ust */
  /*  COMMENTS: */
  /*  - Algorytm wykrywania ruchu ust dziaa przy spenionych poniszych zaoeniach: */
  /*  - uytkownik nie powinien wykonywa znaczcych ruchw ciaa przed kamer i powinien porusza */
  /*    tylko ustami, oczami i mruga powiekami */
  /*  - lekkie poruszanie czci ubra, np. rkaww nie powinno wpyn negatywnie na wynik dizaania */
  /*    algorytmu */
  /*  - bardzo istotn spraw jest odpowiednie owietlenie osoby. Zakada si, e owietlenie  */
  /*    pomieszczenia podczas dziaania algorytmu jest dostatecznie due aby szum spowodowany */
  /*    zbyt sabym owietleniem nie wpywa znaczco na uzyskany efekt. Dodatkowo zakada si */
  /*    e twarz osoby badanej jest dobrze owietlona i e rdo wiata nie znajduje si */
  /*    w okolicach lub za kamer. W przeciwnym wypadku wntrze ust mogoby mie bardzo zbliony kolor */
  /*    do koloru skry i wykrycie zmiany pooenia warg analizujc dane pozyskane z kamery */
  /*    mogoby da niepoprawne rezultaty */
  /*  */
  _SFD_EML_CALL(0,26);
  c2_m = 554.0;
  c2_n = 784.0;
  _SFD_EML_CALL(0,27);
  c2_ilobj = 250.0;
  _SFD_EML_CALL(0,28);
  for (c2_i32 = 0; c2_i32 < 250; c2_i32 = c2_i32 + 1) {
    c2_rotFeret[c2_i32] = 0.0;
  }

  _SFD_EML_CALL(0,29);
  for (c2_i33 = 0; c2_i33 < 434336; c2_i33 = c2_i33 + 1) {
    c2_Lorig[c2_i33] = c2_Original[c2_i33];
  }

  sf_mex_printf("%s =\\n", "Lorig");
  for (c2_i34 = 0; c2_i34 < 434336; c2_i34 = c2_i34 + 1) {
    c2_u[c2_i34] = c2_Lorig[c2_i34];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 1U, 0U, 2, 554, 784));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_y);
  _SFD_EML_CALL(0,30);
  for (c2_i35 = 0; c2_i35 < 434336; c2_i35 = c2_i35 + 1) {
    c2_L[c2_i35] = 0U;
  }

  _SFD_EML_CALL(0,32);
  c2_mouth = 0.0;

  /*  Analiza */
  _SFD_EML_CALL(0,35);
  c2_i = 1.0;
  _SFD_EML_CALL(0,35);
  c2_k = 1.0;
  c2_i = 1.0;
  c2_b_i = 1.0;
  while (c2_b_i <= 250.0) {
    c2_i = c2_b_i;
    CV_EML_FOR(0, 0, 1);

    /*  Sprawdzenie wielkosci obiektow */
    _SFD_EML_CALL(0,38);
    if (CV_EML_COND(0, 0, (real_T)c2_Area[_SFD_EML_ARRAY_BOUNDS_CHECK("Area",
          (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 250, 1, 0) - 1]
                    > 100.0)) {
      if (CV_EML_COND(0, 1, (real_T)c2_Area[_SFD_EML_ARRAY_BOUNDS_CHECK("Area",
            (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 250, 1, 0) - 1]
                      < 217168.0)) {
        CV_EML_MCDC(0, 0, TRUE);
        CV_EML_IF(0, 0, TRUE);

        /*  sprawdzanie odpowiedniego kta wykrytego obiektu */
        /*  jeeli wspczynnik Orientation jest odchylony od 0 o wicej ni 0.5 */
        /*  istnieje b. due prawdopodobiestwo, e nie wykryto ust  */
        /* (lecz np. powiewajcy rkaw od bluzki - klatka ~ 100) */
        _SFD_EML_CALL(0,43);
        c2_x = c2_Orientation[_SFD_EML_ARRAY_BOUNDS_CHECK("Orientation",
          (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 250, 1, 0) - 1];
        c2_b_x = c2_x;
        c2_b_y = muDoubleScalarAbs(c2_b_x);
        if (CV_EML_IF(0, 1, c2_b_y < 0.5)) {
          /*  rotFeret jest specyficznym wspczynnikiem Fereta.  */
          /*  Jest to wspczynnik Fereta ale analizowany w obrconej przestrzeni */
          /*  i jest on rwny stosunkowi promieni elipsy opisanej na znalezionym ksztacie */
          /*  im bliszy 1 tym ksztat jest bliszy kole. */
          /*  Podczas otwierania ust, ksztat zmiany otworu gbowego :D jest bliszy kolu */
          /*  ni ksztat zakrelony przez zmine pooenia brody. */
          _SFD_EML_CALL(0,51);
          for (c2_i36 = 0; c2_i36 < 250; c2_i36 = c2_i36 + 1) {
            c2_b_MajorAxis[c2_i36] = c2_MajorAxis[c2_i36];
          }

          for (c2_i37 = 0; c2_i37 < 250; c2_i37 = c2_i37 + 1) {
            c2_b_MinorAxis[c2_i37] = c2_MinorAxis[c2_i37];
          }

          c2_rotFeret[_SFD_EML_ARRAY_BOUNDS_CHECK("rotFeret", (int32_T)
            _SFD_INTEGER_CHECK("i", c2_i), 1, 250, 1, 0) - 1] = c2_mrdivide(
            chartInstance, c2_b_MajorAxis, c2_b_MinorAxis);

          /*              L=L + uint8(Label==i)*k; */
          /*              k=k+1; */
        }

        goto label_1;
      }
    }

    CV_EML_MCDC(0, 0, FALSE);
    CV_EML_IF(0, 0, FALSE);
   label_1:
    ;
    c2_b_i = c2_b_i + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 0, 0);

  /*  sprawdzamy ktry z ksztatw ma wspczynnik rotFeret najbliszy 1 */
  _SFD_EML_CALL(0,59);
  for (c2_i38 = 0; c2_i38 < 250; c2_i38 = c2_i38 + 1) {
    c2_c_x[c2_i38] = c2_rotFeret[c2_i38] - 1.0;
  }

  for (c2_b_k = 1.0; c2_b_k <= 250.0; c2_b_k = c2_b_k + 1.0) {
    c2_c_k = c2_b_k;
    c2_d_x = c2_c_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c2_c_k), 1, 250, 1, 0) - 1];
    c2_c_y = muDoubleScalarAbs(c2_d_x);
    c2_rotFeret[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_c_k), 1, 250, 1, 0) - 1] = c2_c_y;
  }

  _SFD_EML_CALL(0,60);
  for (c2_i39 = 0; c2_i39 < 250; c2_i39 = c2_i39 + 1) {
    c2_varargin_1[c2_i39] = c2_rotFeret[c2_i39];
  }

  for (c2_i40 = 0; c2_i40 < 250; c2_i40 = c2_i40 + 1) {
    c2_e_x[c2_i40] = c2_varargin_1[c2_i40];
  }

  for (c2_i41 = 0; c2_i41 < 250; c2_i41 = c2_i41 + 1) {
    c2_f_x[c2_i41] = c2_e_x[c2_i41];
  }

  c2_mtmp = c2_f_x[0];
  c2_itmp = 1;
  c2_ix = 1;
  c2_g_x = c2_mtmp;
  c2_b = muDoubleScalarIsNaN(c2_g_x);
  if (c2_b) {
    c2_searchingForNonNaN = TRUE;
    c2_d_k = 2;
   label_2:
    ;
    if (c2_d_k < 251) {
      c2_e_k = c2_d_k;
      c2_a = c2_ix;
      c2_ix = c2_a + 1;
      c2_h_x = c2_f_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 250, 1, 0) - 1];
      c2_b_b = muDoubleScalarIsNaN(c2_h_x);
      if (!c2_b_b) {
        c2_mtmp = c2_f_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 250, 1, 0) - 1];
        c2_itmp = c2_e_k;
        c2_searchingForNonNaN = FALSE;
      } else {
        c2_d_k = c2_d_k + 1;
        goto label_2;
      }
    }

    if (c2_searchingForNonNaN) {
      goto label_3;
    }
  }

  c2_b_a = c2_itmp;
  c2_i42 = c2_b_a + 1;
  for (c2_f_k = c2_i42; c2_f_k < 251; c2_f_k = c2_f_k + 1) {
    c2_e_k = c2_f_k;
    c2_c_a = c2_ix;
    c2_ix = c2_c_a + 1;
    if (c2_f_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_ix), 1, 250, 1, 0) - 1] < c2_mtmp) {
      c2_mtmp = c2_f_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 250, 1, 0) - 1];
      c2_itmp = c2_e_k;
    }
  }

 label_3:
  ;
  c2_b_mtmp = c2_mtmp;
  c2_b_itmp = c2_itmp;
  c2_minval = c2_b_mtmp;
  c2_indx = (real_T)c2_b_itmp;
  c2_b_min = c2_minval;
  c2_b_mini = c2_indx;
  c2_min = c2_b_min;
  c2_mini = c2_b_mini;
  sf_mex_printf("%s =\\n", "min");
  c2_b_u = c2_min;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_d_y);
  sf_mex_printf("%s =\\n", "mini");
  c2_c_u = c2_mini;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_e_y);

  /*  sprawdzamy czy jakikolwiek ksztat zosta wykryty i jeeli tak to dajemy output */
  _SFD_EML_CALL(0,63);
  if (CV_EML_IF(0, 2, c2_min != 1.0)) {
    _SFD_EML_CALL(0,64);
    c2_mouth = 1.0;
    sf_mex_printf("%s =\\n", "mouth");
    c2_d_u = c2_mouth;
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
    sf_mex_call_debug("disp", 0U, 1U, 14, c2_f_y);
    _SFD_EML_CALL(0,65);
    for (c2_i43 = 0; c2_i43 < 434336; c2_i43 = c2_i43 + 1) {
      c2_d_a[c2_i43] = (uint8_T)((real_T)c2_Label[c2_i43] == c2_mini);
    }

    for (c2_i44 = 0; c2_i44 < 434336; c2_i44 = c2_i44 + 1) {
      c2_g_y[c2_i44] = c2_d_a[c2_i44];
    }

    for (c2_i45 = 0; c2_i45 < 434336; c2_i45 = c2_i45 + 1) {
      c2_u0 = (uint32_T)c2_L[c2_i45] + (uint32_T)c2_g_y[c2_i45];
      if (c2_u0 > 255U) {
        c2_u1 = MAX_uint8_T;
      } else {
        c2_u1 = (uint8_T)c2_u0;
      }

      c2_L[c2_i45] = c2_u1;
    }

    _SFD_EML_CALL(0,66);
    for (c2_i46 = 0; c2_i46 < 434336; c2_i46 = c2_i46 + 1) {
      c2_e_a[c2_i46] = (uint8_T)((real_T)c2_Label[c2_i46] == c2_mini);
    }

    for (c2_i47 = 0; c2_i47 < 434336; c2_i47 = c2_i47 + 1) {
      c2_u2 = (uint32_T)c2_e_a[c2_i47] * 255U;
      if (c2_u2 > 255U) {
        c2_u3 = MAX_uint8_T;
      } else {
        c2_u3 = (uint8_T)c2_u2;
      }

      c2_h_y[c2_i47] = c2_u3;
    }

    for (c2_i48 = 0; c2_i48 < 434336; c2_i48 = c2_i48 + 1) {
      c2_u4 = (uint32_T)c2_Lorig[c2_i48] + (uint32_T)c2_h_y[c2_i48];
      if (c2_u4 > 255U) {
        c2_u5 = MAX_uint8_T;
      } else {
        c2_u5 = (uint8_T)c2_u4;
      }

      c2_Lorig[c2_i48] = c2_u5;
    }
  }

  _SFD_EML_CALL(0,-66);
  sf_debug_symbol_scope_pop();
  for (c2_i49 = 0; c2_i49 < 434336; c2_i49 = c2_i49 + 1) {
    (*c2_b_L)[c2_i49] = c2_L[c2_i49];
  }

  for (c2_i50 = 0; c2_i50 < 434336; c2_i50 = c2_i50 + 1) {
    (*c2_b_Lorig)[c2_i50] = c2_Lorig[c2_i50];
  }

  *c2_g_k = c2_k;
  *c2_b_mouth = c2_mouth;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static real_T c2_mrdivide(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_A[250], real_T c2_B[250])
{
  real_T c2_y;
  int32_T c2_i51;
  real_T c2_b_A[250];
  int32_T c2_i52;
  real_T c2_b_B[250];
  int32_T c2_i53;
  real_T c2_c_A[250];
  int32_T c2_i54;
  real_T c2_c_B[250];
  int32_T c2_i55;
  real_T c2_d_A[250];
  int32_T c2_jpvt;
  real_T c2_tau;
  real_T c2_e_A[250];
  int32_T c2_i56;
  real_T c2_b_tau;
  int32_T c2_b_jpvt;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_c_y;
  real_T c2_b;
  real_T c2_d_y;
  real_T c2_a;
  real_T c2_tol;
  real_T c2_rankR;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_e_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_f_y;
  real_T c2_tauj;
  real_T c2_wj;
  real_T c2_i;
  real_T c2_b_i;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_z;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_c_i;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_g_y;
  real_T c2_rr;
  real_T c2_d_i;
  real_T c2_b_rr;
  real_T c2_j;
  real_T c2_b_j;
  int32_T c2_pj;
  real_T c2_i_x;
  real_T c2_h_y;
  real_T c2_j_x;
  real_T c2_i_y;
  real_T c2_loop_ub;
  real_T c2_e_i;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_j_y;
  for (c2_i51 = 0; c2_i51 < 250; c2_i51 = c2_i51 + 1) {
    c2_b_A[c2_i51] = c2_B[c2_i51];
  }

  for (c2_i52 = 0; c2_i52 < 250; c2_i52 = c2_i52 + 1) {
    c2_b_B[c2_i52] = c2_A[c2_i52];
  }

  for (c2_i53 = 0; c2_i53 < 250; c2_i53 = c2_i53 + 1) {
    c2_c_A[c2_i53] = c2_b_A[c2_i53];
  }

  for (c2_i54 = 0; c2_i54 < 250; c2_i54 = c2_i54 + 1) {
    c2_c_B[c2_i54] = c2_b_B[c2_i54];
  }

  for (c2_i55 = 0; c2_i55 < 250; c2_i55 = c2_i55 + 1) {
    c2_d_A[c2_i55] = c2_c_A[c2_i55];
  }

  c2_eml_zlaqp2(chartInstance, c2_d_A, c2_e_A, &c2_tau, &c2_jpvt);
  for (c2_i56 = 0; c2_i56 < 250; c2_i56 = c2_i56 + 1) {
    c2_c_A[c2_i56] = c2_e_A[c2_i56];
  }

  c2_b_tau = c2_tau;
  c2_b_jpvt = c2_jpvt;
  c2_x = c2_c_A[0];
  c2_b_x = c2_x;
  c2_b_y = muDoubleScalarAbs(c2_b_x);
  c2_c_x = 0.0;
  c2_d_x = c2_c_x;
  c2_c_y = muDoubleScalarAbs(c2_d_x);
  c2_b = c2_b_y + c2_c_y;
  c2_d_y = 250.0 * c2_b;
  c2_a = c2_d_y;
  c2_tol = c2_a * 2.2204460492503131E-16;
  c2_rankR = 0.0;
  c2_e_x = c2_c_A[0];
  c2_f_x = c2_e_x;
  c2_e_y = muDoubleScalarAbs(c2_f_x);
  c2_g_x = 0.0;
  c2_h_x = c2_g_x;
  c2_f_y = muDoubleScalarAbs(c2_h_x);
  if (c2_e_y + c2_f_y <= c2_tol) {
    c2_eml_warning(chartInstance, 0.0, c2_tol);
  } else {
    c2_rankR = 1.0;
  }

  c2_y = 0.0;
  c2_tauj = c2_b_tau;
  if (c2_tauj != 0.0) {
    c2_wj = c2_c_B[0];
    for (c2_i = 2.0; c2_i <= 250.0; c2_i = c2_i + 1.0) {
      c2_b_i = c2_i;
      c2_b_a = c2_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 250, 1, 0) - 1];
      c2_b_b = c2_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 250, 1, 0) - 1];
      c2_z = c2_b_a * c2_b_b;
      c2_wj = c2_wj + c2_z;
    }

    c2_c_a = c2_tauj;
    c2_c_b = c2_wj;
    c2_wj = c2_c_a * c2_c_b;
    if (c2_wj != 0.0) {
      c2_c_B[0] = c2_c_B[0] - c2_wj;
      for (c2_c_i = 2.0; c2_c_i <= 250.0; c2_c_i = c2_c_i + 1.0) {
        c2_b_i = c2_c_i;
        c2_d_a = c2_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c2_b_i), 1, 250, 1, 0) - 1];
        c2_d_b = c2_wj;
        c2_g_y = c2_d_a * c2_d_b;
        c2_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c2_b_i), 1, 250, 1, 0) - 1] = c2_c_B[
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_i),
          1, 250, 1, 0) - 1] - c2_g_y;
      }
    }
  }

  c2_rr = c2_rankR;
  for (c2_d_i = 1.0; c2_d_i <= c2_rr; c2_d_i = c2_d_i + 1.0) {
    c2_b_i = c2_d_i;
    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_i), 1, 1, 1, 0);
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_b_jpvt), 1, 1, 1, 0);
    c2_y = c2_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_i), 1, 250, 1, 0) - 1];
  }

  c2_b_rr = c2_rr;
  for (c2_j = c2_b_rr; c2_j >= 1.0; c2_j = c2_j + -1.0) {
    c2_b_j = c2_j;
    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_j), 1, 1, 1, 0);
    c2_pj = c2_b_jpvt;
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_pj), 1, 1, 1, 0);
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_pj), 1, 1, 1, 0);
    c2_i_x = c2_y;
    c2_h_y = c2_c_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c2_b_j), 1, 250, 1, 0) - 1) + 250 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_j), 1,
      1, 2, 0) - 1)];
    c2_j_x = c2_i_x;
    c2_i_y = c2_h_y;
    c2_y = c2_j_x / c2_i_y;
    c2_loop_ub = c2_b_j - 1.0;
    for (c2_e_i = 1.0; c2_e_i <= c2_loop_ub; c2_e_i = c2_e_i + 1.0) {
      c2_b_i = c2_e_i;
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_i), 1, 1, 1, 0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c2_b_jpvt), 1, 1, 1, 0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c2_pj), 1, 1, 1, 0);
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_i), 1, 1, 1, 0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c2_b_jpvt), 1, 1, 1, 0);
      c2_e_a = c2_y;
      c2_e_b = c2_c_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 250, 1, 0) - 1) + 250 * (
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_j),
        1, 1, 2, 0) - 1)];
      c2_j_y = c2_e_a * c2_e_b;
      c2_y = c2_y - c2_j_y;
    }
  }

  return c2_y;
}

static void c2_eml_zlaqp2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_A[250], real_T c2_b_A[250], real_T *
  c2_tau, int32_T *c2_jpvt)
{
  int32_T c2_i57;
  int32_T c2_i58;
  real_T c2_c_A[250];
  real_T c2_vn1;
  real_T c2_x;
  real_T c2_b_x;
  int32_T c2_idxmax;
  int32_T c2_b;
  int32_T c2_pvt;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_c_b;
  int32_T c2_pvtcol;
  int32_T c2_i59;
  real_T c2_d_A[250];
  int32_T c2_itemp;
  real_T c2_atmp;
  real_T c2_alpha1;
  int32_T c2_i60;
  real_T c2_c_x[250];
  int32_T c2_i61;
  real_T c2_e_A[250];
  real_T c2_b_atmp;
  real_T c2_d0;
  int32_T c2_i62;
  real_T c2_f_A[250];
  real_T c2_xnorm;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_b_a;
  int32_T c2_c_c;
  int32_T c2_c_a;
  int32_T c2_d_c;
  int32_T c2_d_b;
  int32_T c2_e_c;
  real_T c2_beta1;
  int32_T c2_knt;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_y;
  int32_T c2_d_a;
  int32_T c2_i63;
  real_T c2_g_A[250];
  real_T c2_e_a;
  real_T c2_f_a;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_b_y;
  int32_T c2_i64;
  real_T c2_h_A[250];
  real_T c2_i_A;
  real_T c2_B;
  real_T c2_h_x;
  real_T c2_c_y;
  real_T c2_i_x;
  real_T c2_d_y;
  real_T c2_j_x;
  real_T c2_e_y;
  real_T c2_j_A;
  real_T c2_b_B;
  real_T c2_k_x;
  real_T c2_f_y;
  real_T c2_l_x;
  real_T c2_g_y;
  real_T c2_m_x;
  real_T c2_h_y;
  real_T c2_i_y;
  real_T c2_g_a;
  real_T c2_e_b;
  real_T c2_k_A;
  real_T c2_c_B;
  real_T c2_n_x;
  real_T c2_j_y;
  real_T c2_o_x;
  real_T c2_k_y;
  real_T c2_p_x;
  real_T c2_l_y;
  real_T c2_m_y;
  real_T c2_n_y;
  int32_T c2_i65;
  real_T c2_l_A[250];
  int32_T c2_c_k;
  real_T c2_h_a;
  int32_T c2_i66;
  for (c2_i57 = 0; c2_i57 < 250; c2_i57 = c2_i57 + 1) {
    c2_b_A[c2_i57] = c2_A[c2_i57];
  }

  c2_eml_scalar_eg(chartInstance);
  *c2_jpvt = 1;
  c2_eml_scalar_eg(chartInstance);
  c2_eps(chartInstance);
  c2_sqrt(chartInstance, 2.2204460492503131E-16);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i58 = 0; c2_i58 < 250; c2_i58 = c2_i58 + 1) {
    c2_c_A[c2_i58] = c2_b_A[c2_i58];
  }

  c2_vn1 = c2_eml_xnrm2(chartInstance, c2_c_A, 1);
  c2_x = c2_vn1;
  c2_b_x = c2_x;
  c2_idxmax = c2_ceval_ixamax(chartInstance, 1, c2_b_x, 1, 1);
  c2_b = c2_idxmax;
  c2_pvt = c2_b;
  if (c2_pvt != 1) {
    c2_a = c2_pvt;
    c2_c = c2_a - 1;
    c2_b_b = c2_c;
    c2_b_c = 250 * c2_b_b;
    c2_c_b = c2_b_c;
    c2_pvtcol = 1 + c2_c_b;
    for (c2_i59 = 0; c2_i59 < 250; c2_i59 = c2_i59 + 1) {
      c2_d_A[c2_i59] = c2_b_A[c2_i59];
    }

    c2_eml_xswap(chartInstance, c2_d_A, c2_pvtcol, c2_b_A);
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_pvt), 1, 1, 1, 0);
    c2_itemp = *c2_jpvt;
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_pvt), 1, 1, 1, 0);
    *c2_jpvt = c2_itemp;
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_pvt), 1, 1, 1, 0);
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_pvt), 1, 1, 1, 0);
  }

  c2_atmp = c2_b_A[0];
  c2_alpha1 = c2_atmp;
  for (c2_i60 = 0; c2_i60 < 250; c2_i60 = c2_i60 + 1) {
    c2_c_x[c2_i60] = c2_b_A[c2_i60];
  }

  for (c2_i61 = 0; c2_i61 < 250; c2_i61 = c2_i61 + 1) {
    c2_e_A[c2_i61] = c2_c_x[c2_i61];
  }

  c2_b_atmp = c2_alpha1;
  c2_d0 = 0.0;
  for (c2_i62 = 0; c2_i62 < 250; c2_i62 = c2_i62 + 1) {
    c2_f_A[c2_i62] = c2_e_A[c2_i62];
  }

  c2_xnorm = c2_b_eml_xnrm2(chartInstance, c2_f_A);
  if (c2_xnorm == 0.0) {
    if (!(c2_b_atmp >= 0.0)) {
      c2_d0 = 2.0;
      for (c2_k = 1; c2_k < 250; c2_k = c2_k + 1) {
        c2_b_k = c2_k;
        c2_b_a = c2_b_k;
        c2_c_c = c2_b_a - 1;
        c2_c_a = c2_c_c;
        c2_d_c = c2_c_a;
        c2_d_b = c2_d_c;
        c2_e_c = 2 + c2_d_b;
        c2_e_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_e_c), 1, 250, 1, 0) - 1] = 0.0;
      }

      c2_b_atmp = -c2_b_atmp;
    }
  } else {
    c2_beta1 = c2_eml_dlapy2(chartInstance, c2_b_atmp, c2_xnorm);
    if (c2_b_atmp < 0.0) {
      c2_beta1 = -c2_beta1;
    }

    c2_knt = 0;
    c2_d_x = c2_beta1;
    c2_e_x = c2_d_x;
    c2_y = muDoubleScalarAbs(c2_e_x);
    if (c2_y < 1.0020841800044864E-292) {
      do {
        c2_d_a = c2_knt;
        c2_knt = c2_d_a + 1;
        for (c2_i63 = 0; c2_i63 < 250; c2_i63 = c2_i63 + 1) {
          c2_g_A[c2_i63] = c2_e_A[c2_i63];
        }

        c2_eml_xscal(chartInstance, 9.9792015476735991E+291, c2_g_A, c2_e_A);
        c2_e_a = c2_beta1;
        c2_beta1 = c2_e_a * 9.9792015476735991E+291;
        c2_f_a = c2_b_atmp;
        c2_b_atmp = c2_f_a * 9.9792015476735991E+291;
        c2_f_x = c2_beta1;
        c2_g_x = c2_f_x;
        c2_b_y = muDoubleScalarAbs(c2_g_x);
      } while (!(c2_b_y >= 1.0020841800044864E-292));

      for (c2_i64 = 0; c2_i64 < 250; c2_i64 = c2_i64 + 1) {
        c2_h_A[c2_i64] = c2_e_A[c2_i64];
      }

      c2_xnorm = c2_b_eml_xnrm2(chartInstance, c2_h_A);
      c2_beta1 = c2_eml_dlapy2(chartInstance, c2_b_atmp, c2_xnorm);
      if (c2_b_atmp < 0.0) {
        c2_beta1 = -c2_beta1;
      }
    }

    c2_b_atmp = c2_b_atmp + c2_beta1;
    if (c2_beta1 < 0.0) {
      c2_beta1 = -c2_beta1;
      c2_i_A = -c2_b_atmp;
      c2_B = c2_beta1;
      c2_h_x = c2_i_A;
      c2_c_y = c2_B;
      c2_i_x = c2_h_x;
      c2_d_y = c2_c_y;
      c2_j_x = c2_i_x;
      c2_e_y = c2_d_y;
      c2_d0 = c2_j_x / c2_e_y;
    } else {
      c2_j_A = c2_xnorm;
      c2_b_B = c2_b_atmp;
      c2_k_x = c2_j_A;
      c2_f_y = c2_b_B;
      c2_l_x = c2_k_x;
      c2_g_y = c2_f_y;
      c2_m_x = c2_l_x;
      c2_h_y = c2_g_y;
      c2_i_y = c2_m_x / c2_h_y;
      c2_g_a = c2_xnorm;
      c2_e_b = c2_i_y;
      c2_b_atmp = c2_g_a * c2_e_b;
      c2_k_A = c2_b_atmp;
      c2_c_B = c2_beta1;
      c2_n_x = c2_k_A;
      c2_j_y = c2_c_B;
      c2_o_x = c2_n_x;
      c2_k_y = c2_j_y;
      c2_p_x = c2_o_x;
      c2_l_y = c2_k_y;
      c2_d0 = c2_p_x / c2_l_y;
      c2_b_atmp = -c2_b_atmp;
    }

    c2_m_y = c2_b_atmp;
    c2_n_y = c2_m_y;
    c2_b_atmp = 1.0 / c2_n_y;
    for (c2_i65 = 0; c2_i65 < 250; c2_i65 = c2_i65 + 1) {
      c2_l_A[c2_i65] = c2_e_A[c2_i65];
    }

    c2_eml_xscal(chartInstance, c2_b_atmp, c2_l_A, c2_e_A);
    for (c2_c_k = 1; c2_c_k <= c2_knt; c2_c_k = c2_c_k + 1) {
      c2_h_a = c2_beta1;
      c2_beta1 = c2_h_a * 1.0020841800044864E-292;
    }

    c2_b_atmp = c2_beta1;
  }

  c2_atmp = c2_b_atmp;
  for (c2_i66 = 0; c2_i66 < 250; c2_i66 = c2_i66 + 1) {
    c2_b_A[c2_i66] = c2_e_A[c2_i66];
  }

  *c2_tau = c2_d0;
  c2_b_A[0] = c2_atmp;
}

static void c2_eml_scalar_eg(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance)
{
}

static void c2_eps(SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance)
{
}

static real_T c2_sqrt(SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance,
                      real_T c2_x)
{
  real_T c2_b_x;
  real_T c2_c_x;
  c2_b_x = c2_x;
  if (c2_b_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_c_x = c2_b_x;
  c2_b_x = c2_c_x;
  return muDoubleScalarSqrt(c2_b_x);
}

static void c2_eml_error(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance)
{
  int32_T c2_i67;
  static char_T c2_cv0[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  int32_T c2_i68;
  static char_T c2_cv1[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c2_b_u[77];
  const mxArray *c2_b_y = NULL;
  for (c2_i67 = 0; c2_i67 < 31; c2_i67 = c2_i67 + 1) {
    c2_u[c2_i67] = c2_cv0[c2_i67];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c2_i68 = 0; c2_i68 < 77; c2_i68 = c2_i68 + 1) {
    c2_b_u[c2_i68] = c2_cv1[c2_i68];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static real_T c2_eml_xnrm2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_x[250], int32_T c2_ix0)
{
  int32_T c2_i69;
  real_T c2_b_x[250];
  int32_T c2_b_ix0;
  int32_T c2_i70;
  real_T c2_c_x[250];
  for (c2_i69 = 0; c2_i69 < 250; c2_i69 = c2_i69 + 1) {
    c2_b_x[c2_i69] = c2_x[c2_i69];
  }

  c2_b_ix0 = c2_ix0;
  for (c2_i70 = 0; c2_i70 < 250; c2_i70 = c2_i70 + 1) {
    c2_c_x[c2_i70] = c2_b_x[c2_i70];
  }

  return c2_ceval_xnrm2(chartInstance, 250, c2_c_x, c2_b_ix0, 1);
}

static boolean_T c2_eml_use_refblas(SFc2_mouthDet_template_R2010bInstanceStruct *
  chartInstance)
{
  return FALSE;
}

static real_T c2_ceval_xnrm2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[250], int32_T
  c2_ix0, int32_T c2_incx)
{
  return dnrm232(&c2_n, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 250, 1, 0) - 1], &
                 c2_incx);
}

static int32_T c2_ceval_ixamax(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x, int32_T c2_ix0
  , int32_T c2_incx)
{
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_ix0),
    1, 1, 1, 0);
  return idamax32(&c2_n, &c2_x, &c2_incx);
}

static void c2_eml_xswap(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_x[250], int32_T c2_ix0, real_T c2_b_x
  [250])
{
  int32_T c2_i71;
  int32_T c2_i72;
  real_T c2_c_x[250];
  real_T c2_d_x[250];
  int32_T c2_i73;
  for (c2_i71 = 0; c2_i71 < 250; c2_i71 = c2_i71 + 1) {
    c2_b_x[c2_i71] = c2_x[c2_i71];
  }

  for (c2_i72 = 0; c2_i72 < 250; c2_i72 = c2_i72 + 1) {
    c2_c_x[c2_i72] = c2_b_x[c2_i72];
  }

  c2_eml_blas_xswap(chartInstance, 250, c2_c_x, c2_ix0, 1, 1, 1, c2_d_x);
  for (c2_i73 = 0; c2_i73 < 250; c2_i73 = c2_i73 + 1) {
    c2_b_x[c2_i73] = c2_d_x[c2_i73];
  }
}

static void c2_eml_blas_xswap(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[250], int32_T
  c2_ix0, int32_T c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[250])
{
  int32_T c2_i74;
  int32_T c2_i75;
  real_T c2_c_x[250];
  real_T c2_d_x[250];
  int32_T c2_i76;
  int32_T c2_i77;
  real_T c2_e_x[250];
  real_T c2_f_x[250];
  int32_T c2_i78;
  for (c2_i74 = 0; c2_i74 < 250; c2_i74 = c2_i74 + 1) {
    c2_b_x[c2_i74] = c2_x[c2_i74];
  }

  if (c2_eml_use_refblas(chartInstance)) {
    for (c2_i75 = 0; c2_i75 < 250; c2_i75 = c2_i75 + 1) {
      c2_c_x[c2_i75] = c2_b_x[c2_i75];
    }

    c2_eml_refblas_xswap(chartInstance, c2_n, c2_c_x, c2_ix0, c2_incx, c2_iy0,
                         c2_incy, c2_d_x);
    for (c2_i76 = 0; c2_i76 < 250; c2_i76 = c2_i76 + 1) {
      c2_b_x[c2_i76] = c2_d_x[c2_i76];
    }

    /* Empty Loop. */
  } else {
    for (c2_i77 = 0; c2_i77 < 250; c2_i77 = c2_i77 + 1) {
      c2_e_x[c2_i77] = c2_b_x[c2_i77];
    }

    c2_ceval_xswap(chartInstance, c2_n, c2_e_x, c2_ix0, c2_incx, c2_iy0, c2_incy,
                   c2_f_x);
    for (c2_i78 = 0; c2_i78 < 250; c2_i78 = c2_i78 + 1) {
      c2_b_x[c2_i78] = c2_f_x[c2_i78];
    }

    /* Empty Loop. */
  }
}

static void c2_eml_refblas_xswap(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[250], int32_T
  c2_ix0, int32_T c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[250])
{
  int32_T c2_i79;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_c_x;
  int32_T c2_d_x;
  int32_T c2_i80;
  int32_T c2_saturatedUnaryMinus;
  int32_T c2_ixinc;
  int32_T c2_e_x;
  int32_T c2_f_x;
  int32_T c2_i81;
  int32_T c2_b_saturatedUnaryMinus;
  int32_T c2_iyinc;
  int32_T c2_loop_ub;
  int32_T c2_k;
  real_T c2_temp;
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_d_b;

  /* Empty Loop. */
  for (c2_i79 = 0; c2_i79 < 250; c2_i79 = c2_i79 + 1) {
    c2_b_x[c2_i79] = c2_x[c2_i79];
  }

  c2_ix = c2_ix0;
  c2_iy = c2_iy0;
  c2_c_x = c2_incx;
  c2_d_x = c2_c_x;
  if ((real_T)c2_d_x < 0.0) {
    c2_i80 = c2_d_x;
    if (c2_i80 <= MIN_int32_T) {
      c2_saturatedUnaryMinus = MAX_int32_T;
    } else {
      c2_saturatedUnaryMinus = -c2_i80;
    }

    c2_ixinc = c2_saturatedUnaryMinus;
  } else {
    c2_ixinc = c2_d_x;
  }

  c2_e_x = c2_incy;
  c2_f_x = c2_e_x;
  if ((real_T)c2_f_x < 0.0) {
    c2_i81 = c2_f_x;
    if (c2_i81 <= MIN_int32_T) {
      c2_b_saturatedUnaryMinus = MAX_int32_T;
    } else {
      c2_b_saturatedUnaryMinus = -c2_i81;
    }

    c2_iyinc = c2_b_saturatedUnaryMinus;
  } else {
    c2_iyinc = c2_f_x;
  }

  c2_loop_ub = c2_n;
  for (c2_k = 1; c2_k <= c2_loop_ub; c2_k = c2_k + 1) {
    c2_temp = c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c2_ix), 1, 250, 1, 0) - 1];
    c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_ix), 1, 250, 1, 0) - 1] = c2_b_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_iy), 1, 250, 1, 0) - 1];
    c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_iy), 1, 250, 1, 0) - 1] = c2_temp;
    if ((real_T)c2_incx < 0.0) {
      c2_a = c2_ix;
      c2_b = c2_ixinc;
      c2_ix = c2_a - c2_b;
    } else {
      c2_b_a = c2_ix;
      c2_b_b = c2_ixinc;
      c2_ix = c2_b_a + c2_b_b;
    }

    if ((real_T)c2_incy < 0.0) {
      c2_c_a = c2_iy;
      c2_c_b = c2_iyinc;
      c2_iy = c2_c_a - c2_c_b;
    } else {
      c2_d_a = c2_iy;
      c2_d_b = c2_iyinc;
      c2_iy = c2_d_a + c2_d_b;
    }
  }
}

static void c2_ceval_xswap(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[250], int32_T
  c2_ix0, int32_T c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[250])
{
  int32_T c2_i82;

  /* Empty Loop. */
  for (c2_i82 = 0; c2_i82 < 250; c2_i82 = c2_i82 + 1) {
    c2_b_x[c2_i82] = c2_x[c2_i82];
  }

  dswap32(&c2_n, &c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 250, 1, 0) - 1], &c2_incx
          , &c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c2_iy0), 1, 250, 1, 0) - 1], &c2_incy);
}

static real_T c2_b_eml_xnrm2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_x[250])
{
  int32_T c2_i83;
  real_T c2_b_x[250];
  int32_T c2_i84;
  real_T c2_c_x[250];
  for (c2_i83 = 0; c2_i83 < 250; c2_i83 = c2_i83 + 1) {
    c2_b_x[c2_i83] = c2_x[c2_i83];
  }

  for (c2_i84 = 0; c2_i84 < 250; c2_i84 = c2_i84 + 1) {
    c2_c_x[c2_i84] = c2_b_x[c2_i84];
  }

  return c2_ceval_xnrm2(chartInstance, 249, c2_c_x, 2, 1);
}

static real_T c2_eml_dlapy2(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_x1, real_T c2_x2)
{
  real_T c2_y;
  real_T c2_a;
  real_T c2_b;
  real_T c2_x;
  boolean_T c2_b_b;
  real_T c2_b_x;
  boolean_T c2_c_b;
  boolean_T c2_b0;
  c2_a = muDoubleScalarAbs(c2_x1);
  c2_b = muDoubleScalarAbs(c2_x2);
  if (c2_b > c2_a) {
  } else {
    c2_x = c2_b;
    c2_b_b = muDoubleScalarIsNaN(c2_x);
    if (c2_b_b) {
    } else {
      c2_y = c2_a;
      goto label_1;
    }
  }

  c2_y = c2_b;
  c2_b = c2_a;
 label_1:
  ;
  if (c2_y == 0.0) {
  } else {
    c2_b_x = c2_y;
    c2_c_b = muDoubleScalarIsInf(c2_b_x);
    if (c2_c_b) {
    } else {
      c2_b0 = FALSE;
      goto label_2;
    }
  }

  c2_b0 = TRUE;
 label_2:
  ;
  if (!c2_b0) {
    c2_b = c2_b / c2_y;
    return c2_y * muDoubleScalarSqrt(1.0 + c2_b * c2_b);
  }

  return c2_y;
}

static void c2_eml_xscal(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_a, real_T c2_x[250], real_T c2_b_x[
  250])
{
  int32_T c2_i85;
  real_T c2_b_a;
  int32_T c2_i86;
  real_T c2_c_x[250];
  int32_T c2_i87;
  int32_T c2_i88;
  real_T c2_d_x[250];
  for (c2_i85 = 0; c2_i85 < 250; c2_i85 = c2_i85 + 1) {
    c2_b_x[c2_i85] = c2_x[c2_i85];
  }

  c2_b_a = c2_a;
  for (c2_i86 = 0; c2_i86 < 250; c2_i86 = c2_i86 + 1) {
    c2_c_x[c2_i86] = c2_b_x[c2_i86];
  }

  for (c2_i87 = 0; c2_i87 < 250; c2_i87 = c2_i87 + 1) {
    c2_b_x[c2_i87] = c2_c_x[c2_i87];
  }

  for (c2_i88 = 0; c2_i88 < 250; c2_i88 = c2_i88 + 1) {
    c2_d_x[c2_i88] = c2_b_x[c2_i88];
  }

  c2_ceval_xscal(chartInstance, 249, c2_b_a, c2_d_x, 2, 1, c2_b_x);
}

static void c2_ceval_xscal(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[250],
  int32_T c2_ix0, int32_T c2_incx, real_T c2_b_x[250])
{
  int32_T c2_i89;
  for (c2_i89 = 0; c2_i89 < 250; c2_i89 = c2_i89 + 1) {
    c2_b_x[c2_i89] = c2_x[c2_i89];
  }

  dscal32(&c2_n, &c2_a, &c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 250, 1, 0) - 1], &
          c2_incx);
}

static void c2_eml_warning(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, real_T c2_varargin_3, real_T c2_varargin_4)
{
  int32_T c2_i90;
  static char_T c2_cv2[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e', 'n', 't', 'M'
    , 'a', 't', 'r', 'i', 'x' };

  char_T c2_u[26];
  const mxArray *c2_y = NULL;
  int32_T c2_i91;
  static char_T c2_cv3[41] = { 'R', 'a', 'n', 'k', ' ', 'd', 'e', 'f', 'i', 'c',
    'i', 'e', 'n', 't', ',', ' ', 'r', 'a', 'n', 'k', ' '
    , '=', ' ', '%', 'd', ',', ' ', ' ', 't', 'o', 'l', ' ', '=', ' ', '%', '1',
    '3', '.', '4', 'e', '.' };

  char_T c2_b_u[41];
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  for (c2_i90 = 0; c2_i90 < 26; c2_i90 = c2_i90 + 1) {
    c2_u[c2_i90] = c2_cv2[c2_i90];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 26));
  for (c2_i91 = 0; c2_i91 < 41; c2_i91 = c2_i91 + 1) {
    c2_b_u[c2_i91] = c2_cv3[c2_i91];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 41));
  c2_c_u = c2_varargin_3;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  c2_d_u = c2_varargin_4;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("warning", 0U, 4U, 14, c2_y, 14, c2_b_y, 14, c2_c_y, 14,
                    c2_d_y);
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  static uint8_T c2_b_u[434336];
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_i92 = 0;
  for (c2_i93 = 0; c2_i93 < 784; c2_i93 = c2_i93 + 1) {
    for (c2_i94 = 0; c2_i94 < 554; c2_i94 = c2_i94 + 1) {
      c2_b_u[c2_i94 + c2_i92] = (*((uint8_T (*)[434336])c2_u))[c2_i94 + c2_i92];
    }

    c2_i92 = c2_i92 + 554;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 3, 0U, 1U, 0U, 2, 554, 784));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i95;
  real_T c2_b_u[250];
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i95 = 0; c2_i95 < 250; c2_i95 = c2_i95 + 1) {
    c2_b_u[c2_i95] = (*((real_T (*)[250])c2_u))[c2_i95];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 1, 250));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i96;
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_b_u[1000];
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_i96 = 0;
  for (c2_i97 = 0; c2_i97 < 250; c2_i97 = c2_i97 + 1) {
    for (c2_i98 = 0; c2_i98 < 4; c2_i98 = c2_i98 + 1) {
      c2_b_u[c2_i98 + c2_i96] = (*((int32_T (*)[1000])c2_u))[c2_i98 + c2_i96];
    }

    c2_i96 = c2_i96 + 4;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 1U, 0U, 2, 4, 250));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_e_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i99;
  int32_T c2_i100;
  int32_T c2_i101;
  real_T c2_b_u[500];
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_i99 = 0;
  for (c2_i100 = 0; c2_i100 < 250; c2_i100 = c2_i100 + 1) {
    for (c2_i101 = 0; c2_i101 < 2; c2_i101 = c2_i101 + 1) {
      c2_b_u[c2_i101 + c2_i99] = (*((real_T (*)[500])c2_u))[c2_i101 + c2_i99];
    }

    c2_i99 = c2_i99 + 2;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 2, 250));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_f_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i102;
  int32_T c2_b_u[250];
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i102 = 0; c2_i102 < 250; c2_i102 = c2_i102 + 1) {
    c2_b_u[c2_i102] = (*((int32_T (*)[250])c2_u))[c2_i102];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 1U, 0U, 2, 1, 250));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_mouthDet_template_R2010b_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[88];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i103;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 88));
  for (c2_i103 = 0; c2_i103 < 88; c2_i103 = c2_i103 + 1) {
    c2_r0 = &c2_info[c2_i103];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i103);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i103);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i103);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i103);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i103);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c2_i103);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c2_i103);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[88])
{
  c2_info[0].context = "";
  c2_info[0].name = "size";
  c2_info[0].dominantType = "uint8";
  c2_info[0].resolved = "[B]size";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "length";
  c2_info[1].dominantType = "int32";
  c2_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[1].fileLength = 326U;
  c2_info[1].fileTime1 = 1226577274U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[2].name = "nargin";
  c2_info[2].dominantType = "";
  c2_info[2].resolved = "[B]nargin";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[3].name = "eq";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]eq";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[4].name = "gt";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]gt";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "zeros";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]zeros";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "mtimes";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[6].fileLength = 3425U;
  c2_info[6].fileTime1 = 1250672766U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[7].name = "isa";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]isa";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[8].name = "isinteger";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]isinteger";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].name = "isscalar";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]isscalar";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].name = "strcmp";
  c2_info[10].dominantType = "char";
  c2_info[10].resolved = "[B]strcmp";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].name = "class";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]class";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].name = "not";
  c2_info[12].dominantType = "logical";
  c2_info[12].resolved = "[B]not";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "lt";
  c2_info[13].dominantType = "int32";
  c2_info[13].resolved = "[B]lt";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "abs";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[14].fileLength = 566U;
  c2_info[14].fileTime1 = 1221267132U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[15].name = "ischar";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]ischar";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[16].name = "islogical";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]islogical";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[17].name = "eml_scalar_abs";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[17].fileLength = 461U;
  c2_info[17].fileTime1 = 1203447960U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[18].name = "isreal";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]isreal";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "";
  c2_info[19].name = "mrdivide";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[19].fileLength = 800U;
  c2_info[19].fileTime1 = 1238434290U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[20].name = "ge";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]ge";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[21].name = "ndims";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[B]ndims";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[22].name = "ctranspose";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]ctranspose";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[23].name = "mldivide";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c2_info[23].fileLength = 998U;
  c2_info[23].fileTime1 = 1238434288U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c2_info[24].name = "isempty";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]isempty";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c2_info[25].name = "eml_qrsolve";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[25].fileLength = 3280U;
  c2_info[25].fileTime1 = 1228093838U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[26].name = "false";
  c2_info[26].dominantType = "";
  c2_info[26].resolved = "[B]false";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[27].name = "min";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[27].fileLength = 362U;
  c2_info[27].fileTime1 = 1244735552U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[28].name = "le";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[B]le";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[29].name = "nargout";
  c2_info[29].dominantType = "";
  c2_info[29].resolved = "[B]nargout";
  c2_info[29].fileLength = 0U;
  c2_info[29].fileTime1 = 0U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[30].name = "eml_min_or_max";
  c2_info[30].dominantType = "char";
  c2_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[30].fileLength = 9969U;
  c2_info[30].fileTime1 = 1240262006U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[31].name = "isnumeric";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[B]isnumeric";
  c2_info[31].fileLength = 0U;
  c2_info[31].fileTime1 = 0U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[32].name = "eml_scalar_eg";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[32].fileLength = 3068U;
  c2_info[32].fileTime1 = 1240262010U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[33].name = "isstruct";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved = "[B]isstruct";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[34].name = "cast";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved = "[B]cast";
  c2_info[34].fileLength = 0U;
  c2_info[34].fileTime1 = 0U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[35].name = "plus";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved = "[B]plus";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[36].name = "eml_scalexp_alloc";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[36].fileLength = 808U;
  c2_info[36].fileTime1 = 1230494698U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[37].name = "minus";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved = "[B]minus";
  c2_info[37].fileLength = 0U;
  c2_info[37].fileTime1 = 0U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[38].name = "eml_index_class";
  c2_info[38].dominantType = "";
  c2_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[38].fileLength = 909U;
  c2_info[38].fileTime1 = 1192466782U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[39].name = "ones";
  c2_info[39].dominantType = "char";
  c2_info[39].resolved = "[B]ones";
  c2_info[39].fileLength = 0U;
  c2_info[39].fileTime1 = 0U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[40].name = "eml_zlaqp2";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[40].fileLength = 3560U;
  c2_info[40].fileTime1 = 1253722088U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[41].name = "colon";
  c2_info[41].dominantType = "int32";
  c2_info[41].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[41].fileLength = 8592U;
  c2_info[41].fileTime1 = 1257783382U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[42].name = "floor";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[42].fileLength = 332U;
  c2_info[42].fileTime1 = 1203448022U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[43].name = "eml_scalar_floor";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[43].fileLength = 260U;
  c2_info[43].fileTime1 = 1209330790U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c2_info[44].name = "intmin";
  c2_info[44].dominantType = "char";
  c2_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[44].fileLength = 1505U;
  c2_info[44].fileTime1 = 1192466728U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[45].name = "uminus";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved = "[B]uminus";
  c2_info[45].fileLength = 0U;
  c2_info[45].fileTime1 = 0U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[46].name = "int32";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved = "[B]int32";
  c2_info[46].fileLength = 0U;
  c2_info[46].fileTime1 = 0U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c2_info[47].name = "intmax";
  c2_info[47].dominantType = "char";
  c2_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[47].fileLength = 1535U;
  c2_info[47].fileTime1 = 1192466728U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c2_info[48].name = "double";
  c2_info[48].dominantType = "int32";
  c2_info[48].resolved = "[B]double";
  c2_info[48].fileLength = 0U;
  c2_info[48].fileTime1 = 0U;
  c2_info[48].fileTime2 = 0U;
  c2_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c2_info[49].name = "isnan";
  c2_info[49].dominantType = "double";
  c2_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[49].fileLength = 506U;
  c2_info[49].fileTime1 = 1228093810U;
  c2_info[49].fileTime2 = 0U;
  c2_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c2_info[50].name = "isinf";
  c2_info[50].dominantType = "double";
  c2_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[50].fileLength = 506U;
  c2_info[50].fileTime1 = 1228093808U;
  c2_info[50].fileTime2 = 0U;
  c2_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c2_info[51].name = "realmax";
  c2_info[51].dominantType = "";
  c2_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[51].fileLength = 771U;
  c2_info[51].fileTime1 = 1226577276U;
  c2_info[51].fileTime2 = 0U;
  c2_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[52].name = "mpower";
  c2_info[52].dominantType = "double";
  c2_info[52].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[52].fileLength = 3710U;
  c2_info[52].fileTime1 = 1238434288U;
  c2_info[52].fileTime2 = 0U;
  c2_info[53].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[53].name = "power";
  c2_info[53].dominantType = "double";
  c2_info[53].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[53].fileLength = 5380U;
  c2_info[53].fileTime1 = 1228093898U;
  c2_info[53].fileTime2 = 0U;
  c2_info[54].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[54].name = "ne";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved = "[B]ne";
  c2_info[54].fileLength = 0U;
  c2_info[54].fileTime1 = 0U;
  c2_info[54].fileTime2 = 0U;
  c2_info[55].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[55].name = "eml_error";
  c2_info[55].dominantType = "char";
  c2_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[55].fileLength = 315U;
  c2_info[55].fileTime1 = 1213926744U;
  c2_info[55].fileTime2 = 0U;
  c2_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c2_info[56].name = "transpose";
  c2_info[56].dominantType = "int32";
  c2_info[56].resolved = "[B]transpose";
  c2_info[56].fileLength = 0U;
  c2_info[56].fileTime1 = 0U;
  c2_info[56].fileTime2 = 0U;
  c2_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[57].name = "eps";
  c2_info[57].dominantType = "char";
  c2_info[57].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[57].fileLength = 1331U;
  c2_info[57].fileTime1 = 1246283386U;
  c2_info[57].fileTime2 = 0U;
  c2_info[58].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[58].name = "eml_is_float_class";
  c2_info[58].dominantType = "char";
  c2_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[58].fileLength = 226U;
  c2_info[58].fileTime1 = 1197850440U;
  c2_info[58].fileTime2 = 0U;
  c2_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[59].name = "sqrt";
  c2_info[59].dominantType = "double";
  c2_info[59].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[59].fileLength = 572U;
  c2_info[59].fileTime1 = 1203448044U;
  c2_info[59].fileTime2 = 0U;
  c2_info[60].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[60].name = "eml_scalar_sqrt";
  c2_info[60].dominantType = "double";
  c2_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[60].fileLength = 664U;
  c2_info[60].fileTime1 = 1209330794U;
  c2_info[60].fileTime2 = 0U;
  c2_info[61].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[61].name = "real";
  c2_info[61].dominantType = "double";
  c2_info[61].resolved = "[B]real";
  c2_info[61].fileLength = 0U;
  c2_info[61].fileTime1 = 0U;
  c2_info[61].fileTime2 = 0U;
  c2_info[62].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[62].name = "eml_xnrm2";
  c2_info[62].dominantType = "int32";
  c2_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c2_info[62].fileLength = 718U;
  c2_info[62].fileTime1 = 1209330856U;
  c2_info[62].fileTime2 = 0U;
  c2_info[63].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c2_info[63].name = "eml_refblas_xnrm2";
  c2_info[63].dominantType = "int32";
  c2_info[63].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[63].fileLength = 1433U;
  c2_info[63].fileTime1 = 1240262042U;
  c2_info[63].fileTime2 = 0U;
}

static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[88])
{
  c2_info[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[64].name = "true";
  c2_info[64].dominantType = "";
  c2_info[64].resolved = "[B]true";
  c2_info[64].fileLength = 0U;
  c2_info[64].fileTime1 = 0U;
  c2_info[64].fileTime2 = 0U;
  c2_info[65].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[65].name = "eml_index_minus";
  c2_info[65].dominantType = "int32";
  c2_info[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[65].fileLength = 277U;
  c2_info[65].fileTime1 = 1192466784U;
  c2_info[65].fileTime2 = 0U;
  c2_info[66].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[66].name = "eml_index_times";
  c2_info[66].dominantType = "int32";
  c2_info[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[66].fileLength = 280U;
  c2_info[66].fileTime1 = 1192466786U;
  c2_info[66].fileTime2 = 0U;
  c2_info[67].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[67].name = "eml_index_plus";
  c2_info[67].dominantType = "int32";
  c2_info[67].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[67].fileLength = 272U;
  c2_info[67].fileTime1 = 1192466784U;
  c2_info[67].fileTime2 = 0U;
  c2_info[68].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[68].name = "times";
  c2_info[68].dominantType = "double";
  c2_info[68].resolved = "[B]times";
  c2_info[68].fileLength = 0U;
  c2_info[68].fileTime1 = 0U;
  c2_info[68].fileTime2 = 0U;
  c2_info[69].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[69].name = "imag";
  c2_info[69].dominantType = "double";
  c2_info[69].resolved = "[B]imag";
  c2_info[69].fileLength = 0U;
  c2_info[69].fileTime1 = 0U;
  c2_info[69].fileTime2 = 0U;
  c2_info[70].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[70].name = "eml_ixamax";
  c2_info[70].dominantType = "int32";
  c2_info[70].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[70].fileLength = 731U;
  c2_info[70].fileTime1 = 1209330844U;
  c2_info[70].fileTime2 = 0U;
  c2_info[71].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c2_info[71].name = "eml_refblas_ixamax";
  c2_info[71].dominantType = "int32";
  c2_info[71].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[71].fileLength = 740U;
  c2_info[71].fileTime1 = 1192466866U;
  c2_info[71].fileTime2 = 0U;
  c2_info[72].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[72].name = "eml_xcabs1";
  c2_info[72].dominantType = "double";
  c2_info[72].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[72].fileLength = 419U;
  c2_info[72].fileTime1 = 1209330846U;
  c2_info[72].fileTime2 = 0U;
  c2_info[73].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[73].name = "eml_xswap";
  c2_info[73].dominantType = "int32";
  c2_info[73].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[73].fileLength = 1330U;
  c2_info[73].fileTime1 = 1209330860U;
  c2_info[73].fileTime2 = 0U;
  c2_info[74].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c2_info[74].name = "eml_refblas_xswap";
  c2_info[74].dominantType = "int32";
  c2_info[74].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[74].fileLength = 905U;
  c2_info[74].fileTime1 = 1238434270U;
  c2_info[74].fileTime2 = 0U;
  c2_info[75].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zlaqp2.m";
  c2_info[75].name = "eml_xlarfp";
  c2_info[75].dominantType = "int32";
  c2_info[75].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xlarfp.m";
  c2_info[75].fileLength = 3270U;
  c2_info[75].fileTime1 = 1253722088U;
  c2_info[75].fileTime2 = 0U;
  c2_info[76].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xlarfp.m";
  c2_info[76].name = "eml_dlapy2";
  c2_info[76].dominantType = "double";
  c2_info[76].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c2_info[76].fileLength = 1062U;
  c2_info[76].fileTime1 = 1209330826U;
  c2_info[76].fileTime2 = 0U;
  c2_info[77].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xlarfp.m";
  c2_info[77].name = "eml_div";
  c2_info[77].dominantType = "double";
  c2_info[77].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[77].fileLength = 4269U;
  c2_info[77].fileTime1 = 1228093826U;
  c2_info[77].fileTime2 = 0U;
  c2_info[78].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xlarfp.m";
  c2_info[78].name = "realmin";
  c2_info[78].dominantType = "char";
  c2_info[78].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[78].fileLength = 749U;
  c2_info[78].fileTime1 = 1226577278U;
  c2_info[78].fileTime2 = 0U;
  c2_info[79].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xlarfp.m";
  c2_info[79].name = "eml_xscal";
  c2_info[79].dominantType = "int32";
  c2_info[79].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c2_info[79].fileLength = 1205U;
  c2_info[79].fileTime1 = 1209330860U;
  c2_info[79].fileTime2 = 0U;
  c2_info[80].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c2_info[80].name = "eml_refblas_xscal";
  c2_info[80].dominantType = "int32";
  c2_info[80].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c2_info[80].fileLength = 464U;
  c2_info[80].fileTime1 = 1195314404U;
  c2_info[80].fileTime2 = 0U;
  c2_info[81].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[81].name = "rdivide";
  c2_info[81].dominantType = "double";
  c2_info[81].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[81].fileLength = 403U;
  c2_info[81].fileTime1 = 1244735552U;
  c2_info[81].fileTime2 = 0U;
  c2_info[82].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[82].name = "max";
  c2_info[82].dominantType = "double";
  c2_info[82].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[82].fileLength = 362U;
  c2_info[82].fileTime1 = 1244735552U;
  c2_info[82].fileTime2 = 0U;
  c2_info[83].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[83].name = "eml_warning";
  c2_info[83].dominantType = "char";
  c2_info[83].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[83].fileLength = 262U;
  c2_info[83].fileTime1 = 1236257278U;
  c2_info[83].fileTime2 = 0U;
  c2_info[84].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[84].name = "conj";
  c2_info[84].dominantType = "double";
  c2_info[84].resolved = "[B]conj";
  c2_info[84].fileLength = 0U;
  c2_info[84].fileTime1 = 0U;
  c2_info[84].fileTime2 = 0U;
  c2_info[85].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[85].name = "eml_conjtimes";
  c2_info[85].dominantType = "double";
  c2_info[85].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  c2_info[85].fileLength = 500U;
  c2_info[85].fileTime1 = 1192466768U;
  c2_info[85].fileTime2 = 0U;
  c2_info[86].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[86].name = "eml_const_nonsingleton_dim";
  c2_info[86].dominantType = "double";
  c2_info[86].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[86].fileLength = 1473U;
  c2_info[86].fileTime1 = 1240262002U;
  c2_info[86].fileTime2 = 0U;
  c2_info[87].context = "";
  c2_info[87].name = "uint8";
  c2_info[87].dominantType = "logical";
  c2_info[87].resolved = "[B]uint8";
  c2_info[87].fileLength = 0U;
  c2_info[87].fileTime1 = 0U;
  c2_info[87].fileTime2 = 0U;
}

static const mxArray *c2_g_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_h_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i104;
  int32_T c2_i105;
  int32_T c2_i106;
  static uint8_T c2_b_u[434336];
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_i104 = 0;
  for (c2_i105 = 0; c2_i105 < 784; c2_i105 = c2_i105 + 1) {
    for (c2_i106 = 0; c2_i106 < 554; c2_i106 = c2_i106 + 1) {
      c2_b_u[c2_i106 + c2_i104] = (*((uint8_T (*)[434336])c2_u))[c2_i106 +
        c2_i104];
    }

    c2_i104 = c2_i104 + 554;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 3, 0U, 1U, 0U, 2, 554, 784));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_i_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static void c2_emlrt_marshallIn(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, const mxArray *c2_L, const char_T *
  c2_name, uint8_T c2_y[434336])
{
  static uint8_T c2_uv2[434336];
  int32_T c2_i107;
  sf_mex_import(c2_name, sf_mex_dup(c2_L), &c2_uv2, 1, 3, 0U, 1, 0U, 2, 554, 784);
  for (c2_i107 = 0; c2_i107 < 434336; c2_i107 = c2_i107 + 1) {
    c2_y[c2_i107] = c2_uv2[c2_i107];
  }

  sf_mex_destroy(&c2_L);
}

static real_T c2_b_emlrt_marshallIn(SFc2_mouthDet_template_R2010bInstanceStruct *
  chartInstance, const mxArray *c2_k, const char_T *
  c2_name)
{
  real_T c2_y;
  real_T c2_d1;
  sf_mex_import(c2_name, sf_mex_dup(c2_k), &c2_d1, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_k);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance, const mxArray *
  c2_b_is_active_c2_mouthDet_template_R2010b, const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u6;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_mouthDet_template_R2010b),
                &c2_u6, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u6;
  sf_mex_destroy(&c2_b_is_active_c2_mouthDet_template_R2010b);
  return c2_y;
}

static void init_dsm_address_info(SFc2_mouthDet_template_R2010bInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_mouthDet_template_R2010b_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(874563087U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1076020339U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1132231986U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3095729689U);
}

mxArray *sf_c2_mouthDet_template_R2010b_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(790390575U);
    pr[1] = (double)(857231584U);
    pr[2] = (double)(3157743187U);
    pr[3] = (double)(542463491U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(554);
      pr[1] = (double)(784);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(250);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(250);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(250);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(250);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(250);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(250);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(554);
      pr[1] = (double)(784);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(554);
      pr[1] = (double)(784);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(554);
      pr[1] = (double)(784);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_mouthDet_template_R2010b(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"L\",},{M[1],M[15],T\"Lorig\",},{M[1],M[11],T\"k\",},{M[1],M[10],T\"mouth\",},{M[8],M[0],T\"is_active_c2_mouthDet_template_R2010b\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_mouthDet_template_R2010b_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
    chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_mouthDet_template_R2010bMachineNumber_,
           2,
           1,
           1,
           12,
           0,
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
          init_script_number_translation(_mouthDet_template_R2010bMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_mouthDet_template_R2010bMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_mouthDet_template_R2010bMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[2];
            dimVector[0]= 554;
            dimVector[1]= 784;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"Original",0,(MexFcnForType)c2_h_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 250;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"Area",0,(MexFcnForType)c2_f_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 554;
            dimVector[1]= 784;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"L",0,(MexFcnForType)c2_h_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 554;
            dimVector[1]= 784;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"Lorig",0,(MexFcnForType)c2_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"k",0,
                              (MexFcnForType)c2_i_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 2;
            dimVector[1]= 250;
            _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Centroid",0,(MexFcnForType)
                                c2_e_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 4;
            dimVector[1]= 250;
            _SFD_SET_DATA_PROPS(6,1,1,0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"BBox",0,(MexFcnForType)c2_d_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 250;
            _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"MajorAxis",0,(MexFcnForType)
                                c2_c_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 250;
            _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"MinorAxis",0,(MexFcnForType)
                                c2_c_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 250;
            _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Orientation",0,(MexFcnForType)
                                c2_c_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 554;
            dimVector[1]= 784;
            _SFD_SET_DATA_PROPS(10,1,1,0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Label",0,(MexFcnForType)c2_h_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(11,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"mouth",
                              0,(MexFcnForType)c2_sf_marshall);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,3,0,0,1,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2813);
        _SFD_CV_INIT_EML_IF(0,0,1546,1585,-1,2483);
        _SFD_CV_INIT_EML_IF(0,1,1862,1890,-1,2475);
        _SFD_CV_INIT_EML_IF(0,2,2696,2707,-1,2801);
        _SFD_CV_INIT_EML_FOR(0,0,1491,1505,2487);

        {
          static int condStart[] = { 1549, 1566 };

          static int condEnd[] = { 1562, 1585 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,1549,1585,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          uint8_T (*c2_Original)[434336];
          int32_T (*c2_Area)[250];
          uint8_T (*c2_L)[434336];
          uint8_T (*c2_Lorig)[434336];
          real_T *c2_k;
          real_T (*c2_Centroid)[500];
          int32_T (*c2_BBox)[1000];
          real_T (*c2_MajorAxis)[250];
          real_T (*c2_MinorAxis)[250];
          real_T (*c2_Orientation)[250];
          uint8_T (*c2_Label)[434336];
          real_T *c2_mouth;
          c2_mouth = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_Label = (uint8_T (*)[434336])ssGetInputPortSignal(chartInstance->S,
            7);
          c2_Orientation = (real_T (*)[250])ssGetInputPortSignal
            (chartInstance->S, 6);
          c2_MinorAxis = (real_T (*)[250])ssGetInputPortSignal(chartInstance->S,
            5);
          c2_MajorAxis = (real_T (*)[250])ssGetInputPortSignal(chartInstance->S,
            4);
          c2_BBox = (int32_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 3);
          c2_Centroid = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S,
            2);
          c2_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_Lorig = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S,
            2);
          c2_L = (uint8_T (*)[434336])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Area = (int32_T (*)[250])ssGetInputPortSignal(chartInstance->S, 1);
          c2_Original = (uint8_T (*)[434336])ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_Original);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_Area);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_L);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_Lorig);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_k);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_Centroid);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_BBox);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_MajorAxis);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_MinorAxis);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_Orientation);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_Label);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_mouth);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_mouthDet_template_R2010bMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_mouthDet_template_R2010b(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_mouthDet_template_R2010bInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_mouthDet_template_R2010b
    ((SFc2_mouthDet_template_R2010bInstanceStruct*) chartInstanceVar);
  initialize_c2_mouthDet_template_R2010b
    ((SFc2_mouthDet_template_R2010bInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_mouthDet_template_R2010b(void *chartInstanceVar)
{
  enable_c2_mouthDet_template_R2010b
    ((SFc2_mouthDet_template_R2010bInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_mouthDet_template_R2010b(void *chartInstanceVar)
{
  disable_c2_mouthDet_template_R2010b
    ((SFc2_mouthDet_template_R2010bInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_mouthDet_template_R2010b(void *chartInstanceVar)
{
  sf_c2_mouthDet_template_R2010b((SFc2_mouthDet_template_R2010bInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_mouthDet_template_R2010b(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_mouthDet_template_R2010b
    ((SFc2_mouthDet_template_R2010bInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_mouthDet_template_R2010b();/* state var info */
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

static void sf_internal_set_sim_state_c2_mouthDet_template_R2010b(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_mouthDet_template_R2010b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_mouthDet_template_R2010b
    ((SFc2_mouthDet_template_R2010bInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_mouthDet_template_R2010b(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_mouthDet_template_R2010b(S);
}

static void sf_opaque_set_sim_state_c2_mouthDet_template_R2010b(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_mouthDet_template_R2010b(S, st);
}

static void sf_opaque_terminate_c2_mouthDet_template_R2010b(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_mouthDet_template_R2010bInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_mouthDet_template_R2010b
      ((SFc2_mouthDet_template_R2010bInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_mouthDet_template_R2010b(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_mouthDet_template_R2010b
      ((SFc2_mouthDet_template_R2010bInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_mouthDet_template_R2010b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("mouthDet_template_R2010b",
      "mouthDet_template_R2010b",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("mouthDet_template_R2010b",
                "mouthDet_template_R2010b",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("mouthDet_template_R2010b",
      "mouthDet_template_R2010b",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"mouthDet_template_R2010b",
        "mouthDet_template_R2010b",2,8);
      sf_mark_chart_reusable_outputs(S,"mouthDet_template_R2010b",
        "mouthDet_template_R2010b",2,4);
    }

    sf_set_rtw_dwork_info(S,"mouthDet_template_R2010b",
                          "mouthDet_template_R2010b",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3206205630U));
  ssSetChecksum1(S,(1401033920U));
  ssSetChecksum2(S,(3667940024U));
  ssSetChecksum3(S,(2878451607U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_mouthDet_template_R2010b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "mouthDet_template_R2010b",
      "mouthDet_template_R2010b",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_mouthDet_template_R2010b(SimStruct *S)
{
  SFc2_mouthDet_template_R2010bInstanceStruct *chartInstance;
  chartInstance = (SFc2_mouthDet_template_R2010bInstanceStruct *)malloc(sizeof
    (SFc2_mouthDet_template_R2010bInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_mouthDet_template_R2010bInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_mouthDet_template_R2010b;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }

  chart_debug_initialization(S,1);
}

void c2_mouthDet_template_R2010b_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_mouthDet_template_R2010b(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_mouthDet_template_R2010b(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_mouthDet_template_R2010b(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_mouthDet_template_R2010b_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
