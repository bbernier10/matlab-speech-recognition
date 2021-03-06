/* Include files */

#include "blascompat32.h"
#include "file_sfun.h"
#include "c2_file.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "file_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[6] = { "nargin", "nargout", "u", "y",
  "g", "a" };

/* Function Declarations */
static void initialize_c2_file(SFc2_fileInstanceStruct *chartInstance);
static void initialize_params_c2_file(SFc2_fileInstanceStruct *chartInstance);
static void enable_c2_file(SFc2_fileInstanceStruct *chartInstance);
static void disable_c2_file(SFc2_fileInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_file(SFc2_fileInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_file(SFc2_fileInstanceStruct
  *chartInstance);
static void set_sim_state_c2_file(SFc2_fileInstanceStruct *chartInstance, const
  mxArray *c2_st);
static void finalize_c2_file(SFc2_fileInstanceStruct *chartInstance);
static void sf_c2_file(SFc2_fileInstanceStruct *chartInstance);
static void initSimStructsc2_file(SFc2_fileInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance, const
  mxArray *c2_a, const char_T *c2_identifier, real32_T c2_y[2048]);
static void c2_b_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real32_T c2_y[2048]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_file, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_fileInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_file(SFc2_fileInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_file = 0U;
}

static void initialize_params_c2_file(SFc2_fileInstanceStruct *chartInstance)
{
}

static void enable_c2_file(SFc2_fileInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_file(SFc2_fileInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_file(SFc2_fileInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_file(SFc2_fileInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real32_T c2_u[2048];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real32_T c2_b_u[2048];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i2;
  real32_T c2_c_u[2048];
  const mxArray *c2_d_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real32_T (*c2_f_y)[2048];
  real32_T (*c2_g)[2048];
  real32_T (*c2_a)[2048];
  c2_a = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_g = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_f_y = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4), FALSE);
  for (c2_i0 = 0; c2_i0 < 2048; c2_i0++) {
    c2_u[c2_i0] = (*c2_a)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 1, 0U, 1U, 0U, 2, 1024, 2),
                FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 2048; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_g)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 1, 0U, 1U, 0U, 2, 1024, 2),
                FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 2048; c2_i2++) {
    c2_c_u[c2_i2] = (*c2_f_y)[c2_i2];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 1, 0U, 1U, 0U, 2, 1024, 2),
                FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_file;
  c2_d_u = c2_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_file(SFc2_fileInstanceStruct *chartInstance, const
  mxArray *c2_st)
{
  const mxArray *c2_u;
  real32_T c2_fv0[2048];
  int32_T c2_i3;
  real32_T c2_fv1[2048];
  int32_T c2_i4;
  real32_T c2_fv2[2048];
  int32_T c2_i5;
  real32_T (*c2_a)[2048];
  real32_T (*c2_g)[2048];
  real32_T (*c2_y)[2048];
  c2_a = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_g = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_y = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "a",
                      c2_fv0);
  for (c2_i3 = 0; c2_i3 < 2048; c2_i3++) {
    (*c2_a)[c2_i3] = c2_fv0[c2_i3];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "g",
                      c2_fv1);
  for (c2_i4 = 0; c2_i4 < 2048; c2_i4++) {
    (*c2_g)[c2_i4] = c2_fv1[c2_i4];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)), "y",
                      c2_fv2);
  for (c2_i5 = 0; c2_i5 < 2048; c2_i5++) {
    (*c2_y)[c2_i5] = c2_fv2[c2_i5];
  }

  chartInstance->c2_is_active_c2_file = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "is_active_c2_file");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_file(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_file(SFc2_fileInstanceStruct *chartInstance)
{
}

static void sf_c2_file(SFc2_fileInstanceStruct *chartInstance)
{
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  real32_T c2_u[2048];
  uint32_T c2_debug_family_var_map[6];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 3.0;
  real32_T c2_y[2048];
  real32_T c2_g[2048];
  real32_T c2_a[2048];
  int32_T c2_i11;
  int32_T c2_i12;
  real32_T c2_b[2048];
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  real32_T (*c2_b_y)[2048];
  real32_T (*c2_b_g)[2048];
  real32_T (*c2_b_a)[2048];
  real32_T (*c2_b_u)[2048];
  c2_b_a = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_g = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_y = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real32_T (*)[2048])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i6 = 0; c2_i6 < 2048; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_u)[c2_i6], 0U);
  }

  for (c2_i7 = 0; c2_i7 < 2048; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_y)[c2_i7], 1U);
  }

  for (c2_i8 = 0; c2_i8 < 2048; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_g)[c2_i8], 2U);
  }

  for (c2_i9 = 0; c2_i9 < 2048; c2_i9++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_a)[c2_i9], 3U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i10 = 0; c2_i10 < 2048; c2_i10++) {
    c2_u[c2_i10] = (*c2_b_u)[c2_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_u, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_y, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_g, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_a, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  for (c2_i11 = 0; c2_i11 < 2048; c2_i11++) {
    c2_y[c2_i11] = c2_u[c2_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i12 = 0; c2_i12 < 2048; c2_i12++) {
    c2_b[c2_i12] = c2_u[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 2048; c2_i13++) {
    c2_g[c2_i13] = 2.0F * c2_b[c2_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i14 = 0; c2_i14 < 2048; c2_i14++) {
    c2_b[c2_i14] = c2_u[c2_i14];
  }

  for (c2_i15 = 0; c2_i15 < 2048; c2_i15++) {
    c2_a[c2_i15] = 4.0F * c2_b[c2_i15];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  for (c2_i16 = 0; c2_i16 < 2048; c2_i16++) {
    (*c2_b_y)[c2_i16] = c2_y[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 2048; c2_i17++) {
    (*c2_b_g)[c2_i17] = c2_g[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 2048; c2_i18++) {
    (*c2_b_a)[c2_i18] = c2_a[c2_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_fileMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_file(SFc2_fileInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  real32_T c2_b_inData[2048];
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  real32_T c2_u[2048];
  const mxArray *c2_y = NULL;
  SFc2_fileInstanceStruct *chartInstance;
  chartInstance = (SFc2_fileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i19 = 0;
  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    for (c2_i21 = 0; c2_i21 < 1024; c2_i21++) {
      c2_b_inData[c2_i21 + c2_i19] = (*(real32_T (*)[2048])c2_inData)[c2_i21 +
        c2_i19];
    }

    c2_i19 += 1024;
  }

  c2_i22 = 0;
  for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
    for (c2_i24 = 0; c2_i24 < 1024; c2_i24++) {
      c2_u[c2_i24 + c2_i22] = c2_b_inData[c2_i24 + c2_i22];
    }

    c2_i22 += 1024;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 1, 0U, 1U, 0U, 2, 1024, 2),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance, const
  mxArray *c2_a, const char_T *c2_identifier, real32_T c2_y[2048])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_a), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_a);
}

static void c2_b_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real32_T c2_y[2048])
{
  real32_T c2_fv3[2048];
  int32_T c2_i25;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_fv3, 1, 1, 0U, 1, 0U, 2, 1024,
                2);
  for (c2_i25 = 0; c2_i25 < 2048; c2_i25++) {
    c2_y[c2_i25] = c2_fv3[c2_i25];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_a;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real32_T c2_y[2048];
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  SFc2_fileInstanceStruct *chartInstance;
  chartInstance = (SFc2_fileInstanceStruct *)chartInstanceVoid;
  c2_a = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_a), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_a);
  c2_i26 = 0;
  for (c2_i27 = 0; c2_i27 < 2; c2_i27++) {
    for (c2_i28 = 0; c2_i28 < 1024; c2_i28++) {
      (*(real32_T (*)[2048])c2_outData)[c2_i28 + c2_i26] = c2_y[c2_i28 + c2_i26];
    }

    c2_i26 += 1024;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_fileInstanceStruct *chartInstance;
  chartInstance = (SFc2_fileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_fileInstanceStruct *chartInstance;
  chartInstance = (SFc2_fileInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_file_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[1];
  c2_ResolvedFunctionInfo (*c2_b_info)[1];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i29;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[1])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mtimes";
  (*c2_b_info)[0].dominantType = "single";
  (*c2_b_info)[0].resolved =
    "[ILXE]c:/program files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[0].fileTimeLo = 1289541292U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c2_i29 = 0; c2_i29 < 1; c2_i29++) {
    c2_r0 = &c2_info[c2_i29];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i29);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i29);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i29);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i29);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i29);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i29);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i29);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i29);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_fileInstanceStruct *chartInstance;
  chartInstance = (SFc2_fileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i30;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i30, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i30;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_fileInstanceStruct *chartInstance;
  chartInstance = (SFc2_fileInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_file, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_is_active_c2_file),
    &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_file);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_fileInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_fileInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_file_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2520719340U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4256743702U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3903715488U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1710209362U);
}

mxArray *sf_c2_file_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("pbFTsYrM768biy9ctbDwmH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1024);
      pr[1] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(1024);
      pr[1] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1024);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1024);
      pr[1] = (double)(2);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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

static const mxArray *sf_get_sim_state_info_c2_file(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[7],T\"a\",},{M[1],M[6],T\"g\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_file\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_file_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_fileInstanceStruct *chartInstance;
    chartInstance = (SFc2_fileInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_fileMachineNumber_,
          2,
          1,
          1,
          4,
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
          init_script_number_translation(_fileMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_fileMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_fileMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,2,0,1,"g");
          _SFD_SET_DATA_PROPS(3,2,0,1,"a");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,50);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1024;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1024;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1024;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1024;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real32_T (*c2_u)[2048];
          real32_T (*c2_y)[2048];
          real32_T (*c2_g)[2048];
          real32_T (*c2_a)[2048];
          c2_a = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 3);
          c2_g = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_y = (real32_T (*)[2048])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real32_T (*)[2048])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_g);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_a);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_fileMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "w4gsLhgNZYmox7BZlXT8rB";
}

static void sf_opaque_initialize_c2_file(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_fileInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_file((SFc2_fileInstanceStruct*) chartInstanceVar);
  initialize_c2_file((SFc2_fileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_file(void *chartInstanceVar)
{
  enable_c2_file((SFc2_fileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_file(void *chartInstanceVar)
{
  disable_c2_file((SFc2_fileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_file(void *chartInstanceVar)
{
  sf_c2_file((SFc2_fileInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_file(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_file((SFc2_fileInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_file();/* state var info */
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

extern void sf_internal_set_sim_state_c2_file(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_file();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_file((SFc2_fileInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_file(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_file(S);
}

static void sf_opaque_set_sim_state_c2_file(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_file(S, st);
}

static void sf_opaque_terminate_c2_file(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_fileInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_file((SFc2_fileInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_file_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_file((SFc2_fileInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_file(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_file((SFc2_fileInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_file(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_file_optimization_info();
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
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3421396967U));
  ssSetChecksum1(S,(2749744540U));
  ssSetChecksum2(S,(1606763462U));
  ssSetChecksum3(S,(2229579775U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_file(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_file(SimStruct *S)
{
  SFc2_fileInstanceStruct *chartInstance;
  chartInstance = (SFc2_fileInstanceStruct *)malloc(sizeof
    (SFc2_fileInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_fileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_file;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_file;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_file;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_file;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_file;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_file;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_file;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_file;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_file;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_file;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_file;
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

void c2_file_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_file(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_file(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_file(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_file_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
