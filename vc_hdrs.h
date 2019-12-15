#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>
#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _VC_TYPES_
#define _VC_TYPES_
/* common definitions shared with DirectC.h */

typedef unsigned int U;
typedef unsigned char UB;
typedef unsigned char scalar;
typedef struct { U c; U d;} vec32;

#define scalar_0 0
#define scalar_1 1
#define scalar_z 2
#define scalar_x 3

extern long long int ConvUP2LLI(U* a);
extern void ConvLLI2UP(long long int a1, U* a2);
extern long long int GetLLIresult();
extern void StoreLLIresult(const unsigned int* data);
typedef struct VeriC_Descriptor *vc_handle;

#ifndef SV_3_COMPATIBILITY
#define SV_STRING const char*
#else
#define SV_STRING char*
#endif

#endif /* _VC_TYPES_ */


 extern long long XMODEL_create_params(/* INPUT */double ai_real, /* INPUT */double ai_imag, /* INPUT */double bi_real, /* INPUT */double bi_imag, /* INPUT */int mi);

 extern long long XMODEL_insert_params(/* INPUT */long long node, /* INPUT */double ai_real, /* INPUT */double ai_imag, /* INPUT */double bi_real, /* INPUT */double bi_imag, /* INPUT */int mi);

 extern void XMODEL_display_params(/* INPUT */long long param_set);

 extern int XMODEL_count_params(/* INPUT */long long param_set);

 extern void XMODEL_delete_params(/* INPUT */long long param_set);

 extern long long XMODEL_copy_params(/* INPUT */long long param_set);

 extern long long XMODEL_scale_params(/* INPUT */long long param_set, /* INPUT */double scale);

 extern long long XMODEL_add_params(/* INPUT */long long a, /* INPUT */long long b);

 extern long long XMODEL_subs_params(/* INPUT */long long a, /* INPUT */long long b);

 extern long long XMODEL_multiply_params(/* INPUT */long long a, /* INPUT */long long b);

 extern long long XMODEL_trim_params(/* INPUT */long long param_set, /* INPUT */double t_unit, /* INPUT */double tol);

 extern long long XMODEL_update_params(/* INPUT */long long param_set, /* INPUT */double dT);

 extern long long XMODEL_pfrac_params(/* INPUT */long long in, /* INPUT */long long tf);

 extern double XMODEL_sample_params(/* INPUT */long long param_set, /* INPUT */double dT);

 extern double XMODEL_find_cross_params(/* INPUT */long long params_set, /* INPUT */double threshold, /* INPUT */double t_start, /* INPUT */double t_stop, /* INPUT */double t_step);

 extern long long XMODEL_deriv_params(/* INPUT */long long param_set);

 extern void* XMODEL_fread_pwl(/* INPUT */const char* filename);

 extern long long XMODEL_new(/* INPUT */int xtype, /* INPUT */double time_precision);

 extern void XMODEL_set_xreal(/* INPUT */long long XMODEL_cls, /* INPUT */long long state, /* INPUT */double delay_frac, /* INPUT */double abs_time);

 extern void XMODEL_set_st_xreal(/* INPUT */long long XMODEL_cls, /* INPUT */long long state, /* INPUT */double delay_frac, /* INPUT */double abs_time, /* INPUT */long long XMODEL_acf);

 extern void XMODEL_set_xbit(/* INPUT */long long XMODEL_cls, /* INPUT */unsigned char value, /* INPUT */double delay_frac, /* INPUT */double abs_time);

 extern void XMODEL_set_st_xbit(/* INPUT */long long XMODEL_cls, /* INPUT */unsigned char value, /* INPUT */double delay_frac, /* INPUT */double abs_time, /* INPUT */double j_mean, /* INPUT */double j_rsm, /* INPUT */double prob1, /* INPUT */double prob0);

 extern void XMODEL_change_xreal(/* INPUT */long long XMODEL_cls, /* INPUT */long long delta, /* INPUT */double delay_frac, /* INPUT */double abs_time);

 extern void XMODEL_eval_xreal(/* INPUT */long long XMODEL_cls_out, /* INPUT */long long tf, /* INPUT */long long XMODEL_cls_in, /* INPUT */double delay_frac, /* INPUT */double abs_time);

 extern double XMODEL_set_delaystep(/* INPUT */double delay, /* INPUT */double abs_unit, /* INPUT */double rel_unit, /* INPUT */double abs_time);

 extern double XMODEL_set_delaystep_from(/* INPUT */double delay, /* INPUT */double abs_unit, /* INPUT */double rel_unit, /* INPUT */double abs_time, /* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern long long XMODEL_state(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern long long XMODEL_pstate(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern long long XMODEL_ppstate(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern long long XMODEL_changestate(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern long long XMODEL_pchangestate(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_getabstime(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_ptime(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_pptime(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_tprecision(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_toffset(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_tstamp(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_ptstamp(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_value(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_jmean(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_jrms(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_prob1(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_prob0(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern long long XMODEL_acf(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype);

 extern double XMODEL_find_cross(/* INPUT */long long XMODEL_cls, /* INPUT */int xtype, /* INPUT */double threshold, /* INPUT */double t_start, /* INPUT */double t_stop, /* INPUT */double t_step);

 extern double XMODEL_meas_value(/* INPUT */long long XMODEL_cls);

 extern double XMODEL_meas_deriv1(/* INPUT */long long XMODEL_cls);

 extern double XMODEL_meas_deriv2(/* INPUT */long long XMODEL_cls);

 extern long long NPRIMS_initarray_logic(/* INPUT */int size);

 extern long long NPRIMS_initarray_int(/* INPUT */int size);

 extern long long NPRIMS_initarray_real(/* INPUT */int size);

 extern long long NPRIMS_getarray_logic(/* INPUT */long long array_ptr, /* INPUT */int index);

 extern long long NPRIMS_getarray_int(/* INPUT */long long array_ptr, /* INPUT */int index);

 extern long long NPRIMS_getarray_real(/* INPUT */long long array_ptr, /* INPUT */int index);

 extern void NPRIMS_closearray_logic(/* INPUT */long long array_ptr);

 extern void NPRIMS_closearray_int(/* INPUT */long long array_ptr);

 extern void NPRIMS_closearray_real(/* INPUT */long long array_ptr);

 extern unsigned char NPRIMS_getelem_logic(/* INPUT */long long array_ptr, /* INPUT */int index);

 extern int NPRIMS_getelem_int(/* INPUT */long long array_ptr, /* INPUT */int index);

 extern double NPRIMS_getelem_real(/* INPUT */long long array_ptr, /* INPUT */int index);

 extern void NPRIMS_putelem_logic(/* INPUT */long long array_ptr, /* INPUT */int index, /* INPUT */unsigned char elem);

 extern void NPRIMS_putelem_int(/* INPUT */long long array_ptr, /* INPUT */int index, /* INPUT */int elem);

 extern void NPRIMS_putelem_real(/* INPUT */long long array_ptr, /* INPUT */int index, /* INPUT */double elem);

 extern long long NPRIMS_new_xbit();

 extern void NPRIMS_set_xbit(/* INPUT */long long obj_ptr, /* INPUT */unsigned char value, /* INPUT */double t_offset);

 extern void NPRIMS_set_st_xbit(/* INPUT */long long obj_ptr, /* INPUT */unsigned char value, /* INPUT */double t_offset, /* INPUT */double j_mean, /* INPUT */double j_rms, /* INPUT */double prob1, /* INPUT */double prob0);

 extern int NPRIMS_updated_st_xbit(/* INPUT */long long obj_ptr, /* INPUT */double j_mean, /* INPUT */double j_rms, /* INPUT */double prob1, /* INPUT */double prob0);

 extern long long NPRIMS_new_xreal();

 extern void NPRIMS_set_xreal(/* INPUT */long long obj_ptr, /* INPUT */long long state_ptr, /* INPUT */double t_offset);

 extern void NPRIMS_set_st_xreal(/* INPUT */long long obj_ptr, /* INPUT */long long state_ptr, /* INPUT */double t_offset, /* INPUT */long long acf_ptr);

 extern int JEZ_CheckHeader(/* INPUT */const char* filename);

 extern int JEZ_GetVersionIndex(/* INPUT */const char* version_str);

 extern void JEZ_OpenHeader(/* INPUT */const char* filename, /* INPUT */double timestep, /* INPUT */double timescale, /* INPUT */int version);

 extern void JEZ_AddVariable(/* INPUT */const char* filename, /* INPUT */int index, /* INPUT */const char* name, /* INPUT */const char* data_type);

 extern void JEZ_CloseHeader(/* INPUT */const char* filename);

 extern void* JEZ_OpenBody(/* INPUT */const char* filename);

 extern void JEZ_FlushBody(/* INPUT */void* fp);

 extern void JEZ_CloseBody(/* INPUT */void* fp);

 extern void JEZ_WriteEvent(/* INPUT */void* fp, /* INPUT */int index, /* INPUT */double event_abstime, /* INPUT */const char* data, /* INPUT */int data_len, /* INPUT */int version);

 extern void JEZ_WriteEventSVbit(/* INPUT */void* fp, /* INPUT */int index, /* INPUT */double event_abstime, /* INPUT */unsigned char value, /* INPUT */int version);

 extern void JEZ_WriteEventSVreal(/* INPUT */void* fp, /* INPUT */int index, /* INPUT */double event_abstime, /* INPUT */double value, /* INPUT */int version);

 extern void JEZ_WriteEventXbit(/* INPUT */void* fp, /* INPUT */int index, /* INPUT */double event_abstime, /* INPUT */long long in, /* INPUT */int version, /* INPUT */int mode_stat);

 extern void JEZ_WriteEventXreal(/* INPUT */void* fp, /* INPUT */int index, /* INPUT */double t_event, /* INPUT */long long in, /* INPUT */int version, /* INPUT */int mode_stat);

 extern void JEZ_WriteEventMeas(/* INPUT */void* fp, /* INPUT */int index, /* INPUT */double event_abstime, /* INPUT */long long in, /* INPUT */int version);

 extern int JEZ_obsfunc1(/* INPUT */const char* filename, /* INPUT */double xmodel_absunit, /* INPUT */double xmodel_timescale, /* INPUT */int version_index, /* INPUT */int mode_stat, /* INPUT */const char* var_name, /* INPUT */const char* type_normal, /* INPUT */const char* type_stat);

 extern void* JEZ_obsfunc2(/* INPUT */void* fp, /* INPUT */const char* filename, /* INPUT */double t_event, /* INPUT */double start, /* INPUT */double stop, /* INPUT */int var_index, /* INPUT */long long in_xmodel, /* INPUT */int version_index, /* INPUT */int mode_stat, /* INPUT */int flag, 
/* INPUT */int flush);

 extern void* JEZ_obsfunc3(/* INPUT */void* fp, /* INPUT */const char* filename, /* INPUT */double t_event, /* INPUT */double start, /* INPUT */double stop, /* INPUT */int var_index, /* INPUT */long long in_xmodel, /* INPUT */int version_index, /* INPUT */int mode_stat, /* INPUT */int flag, 
/* INPUT */int flush);

 extern void* JEZ_obsfunc4(/* INPUT */void* fp, /* INPUT */const char* filename, /* INPUT */double t_event, /* INPUT */double start, /* INPUT */double stop, /* INPUT */int var_index, /* INPUT */unsigned char in, /* INPUT */int version_index, /* INPUT */int flag, /* INPUT */int flush
);

 extern void* JEZ_obsfunc5(/* INPUT */void* fp, /* INPUT */const char* filename, /* INPUT */double t_event, /* INPUT */double start, /* INPUT */double stop, /* INPUT */int var_index, /* INPUT */double in, /* INPUT */int version_index, /* INPUT */int flag, /* INPUT */int flush
);

 extern void* JEZ_obsfunc6(/* INPUT */void* fp, /* INPUT */const char* filename, /* INPUT */double t_event, /* INPUT */double start, /* INPUT */double stop, /* INPUT */int var_index, /* INPUT */long long in_meas_xmodel, /* INPUT */int version_index, /* INPUT */int flag, /* INPUT */int flush
);

 extern void JEZ_obsfunc7(/* INPUT */void* fp, /* INPUT */const char* var_name, /* INPUT */long long num_bit, /* INPUT */long long num_err, /* INPUT */double sum_prb);

 extern long long PARAM_read_paramfile(/* INPUT */const char* filename);

 extern double PARAM_extract_param_real(/* INPUT */long long palist, /* INPUT */const char* param);

 extern int PARAM_extract_param_int(/* INPUT */long long palist, /* INPUT */const char* param);

 extern int PARAM_extract_param_arraysize(/* INPUT */long long palist, /* INPUT */const char* param);

 extern double PARAM_extract_param_arrayelem(/* INPUT */long long palist, /* INPUT */const char* param, /* INPUT */int index);

 extern void PARAM_delete_paramlist(/* INPUT */long long palist);

 extern double NPRIMS_get_timeunit();

 extern unsigned long long NPRIMS_convto_reltime(/* INPUT */double t_abs);

 extern double NPRIMS_convto_abstime(/* INPUT */unsigned long long t_rel);

 extern long long NPRIMS_filter_init(/* INPUT */double gain, /* INPUT */int poles_size, /* INPUT */int zeros_size, /* INPUT */double delay, /* INPUT */const char* filename, /* OUTPUT */long long *p_handle, /* OUTPUT */long long *z_handle);

 extern void NPRIMS_filter_check(/* INPUT */long long prim_ptr, /* OUTPUT */double *delay);

 extern void NPRIMS_filter_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long out_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern long long NPRIMS_filter_var_init(/* INPUT */int num_poles, /* INPUT */int num_zeros, /* OUTPUT */long long *p_handle, /* OUTPUT */long long *z_handle);

 extern void NPRIMS_filter_var_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long out_ptr, /* INPUT */double gain, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern void NPRIMS_filter_var_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long out_ptr, /* INPUT */double gain, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern double PRIMS_function_filterfir1(/* INPUT */long long in, /* INPUT */double t_offset, /* INPUT */double abs_time);

 extern void PRIMS_function_filterfir2(/* INPUT */long long in);

 extern long long PRIMS_function_filterfir3(/* INPUT */long long out, /* INPUT */long long trig, /* INPUT */double p_out, /* INPUT */double v_out, /* INPUT */double tran_time, /* INPUT */double abs_time, /* INPUT */double abs_unit);

 extern double PRIMS_function_filterfir4(/* INPUT */long long trig, /* INPUT */double abs_time);

 extern long long PRIMS_function_filterfir5(/* INPUT */double v_out);

 extern double PRIMS_function_filterfir6(/* INPUT */long long out, /* INPUT */long long trig, /* INPUT */double p_out, /* INPUT */double v_out, /* INPUT */double tran_time, /* INPUT */double start_time, /* INPUT */double abs_time, /* INPUT */double abs_unit);

 extern double PRIMS_function_filterfir7(/* INPUT */double stop_time, /* INPUT */double abs_unit, /* INPUT */double rel_unit);

 extern unsigned char PRIMS_function_filterfir8(/* INPUT */long long in, /* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_function_filterfir9(/* INPUT */long long trig);

 extern long long PRIMS_function_polyfunc1(/* INPUT */int i, /* INPUT */long long vec, /* INPUT */double data);

 extern long long PRIMS_function_polyfunc1_filename(/* INPUT */const char* filename, /* OUTPUT */int *len);

 extern long long PRIMS_function_polyfunc2(/* INPUT */int num_data, /* INPUT */int order, /* INPUT */long long data_vec, /* INPUT */long long in0);

 extern long long PRIMS_function_polyfunc3(/* INPUT */int num_data, /* INPUT */int order, /* INPUT */long long data_vec, /* INPUT */long long in0, /* INPUT */long long in1);

 extern long long PRIMS_function_polyfunc4(/* INPUT */int num_data, /* INPUT */int order, /* INPUT */long long data_vec, /* INPUT */long long in0, /* INPUT */long long in1, /* INPUT */long long in2);

 extern double PRIMS_function_polyfunc5(/* INPUT */long long in, /* INPUT */double abs_time);

 extern long long PRIMS_function_polyfunc6(/* INPUT */int num_data, /* INPUT */int order, /* INPUT */long long data_vec, /* INPUT */long long in, /* INPUT */double abs_time);

 extern double PRIMS_function_polyfunc7(/* INPUT */long long in0, /* INPUT */long long in1, /* INPUT */double abs_time);

 extern long long PRIMS_function_polyfunc8(/* INPUT */int num_data, /* INPUT */int order, /* INPUT */long long data_vec, /* INPUT */long long in0, /* INPUT */long long in1, /* INPUT */double abs_time);

 extern double PRIMS_function_polyfunc9(/* INPUT */long long in0, /* INPUT */long long in1, /* INPUT */long long in2, /* INPUT */double abs_time);

 extern long long PRIMS_function_polyfunc10(/* INPUT */int num_data, /* INPUT */int order, /* INPUT */long long data_vec, /* INPUT */long long in0, /* INPUT */long long in1, /* INPUT */long long in2, /* INPUT */double abs_time);

 extern long long NPRIMS_buffer_init(/* INPUT */double scale, /* INPUT */double init_value, /* INPUT */double abstol, /* INPUT */double reltol, /* INPUT */double delay, /* INPUT */const char* filename, /* INPUT */int pwl_mode, /* INPUT */int mor_mode, /* INPUT */int trim_mode, /* INPUT */int skip_dc, 
/* INPUT */long long handle);

 extern void NPRIMS_buffer_check(/* INPUT */long long prim_ptr, /* OUTPUT */double *delay, /* OUTPUT */double *init_value);

 extern int NPRIMS_buffer_cb0(/* INPUT */double value, /* OUTPUT */long long *state_ptr);

 extern void NPRIMS_buffer_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long out_ptr, /* INPUT */long long t_next);

 extern int NPRIMS_buffer_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long t_next, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime);

 extern long long NPRIMS_deriv_init(/* INPUT */double scale);

 extern void NPRIMS_deriv_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern long long NPRIMS_integ_init(/* INPUT */double scale, /* INPUT */double init_value, /* OUTPUT */long long *state_ptr);

 extern void NPRIMS_integ_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long out_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern long long NPRIMS_scale_init(/* INPUT */double scale);

 extern void NPRIMS_scale_cb1(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime, /* OUTPUT */long long *acf_ptr);

 extern long long NPRIMS_select_init(/* INPUT */int width_sel, /* INPUT */int num_in, /* INPUT */long long trig_out);

 extern int NPRIMS_select_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index);

 extern int NPRIMS_select_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long sel_ptr, /* INPUT */int index);

 extern int NPRIMS_select_cb3(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* OUTPUT */long long *state_ptr, /* OUTPUT */long long *acf_ptr);

 extern int NPRIMS_select_cb4(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime, /* OUTPUT */long long *acf_ptr);

 extern long long NPRIMS_add_init(/* INPUT */int num_in, /* OUTPUT */long long *scale_handle);

 extern int NPRIMS_add_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index);

 extern int NPRIMS_add_cb2(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* INPUT */long long out_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */long long *acf_ptr);

 extern int NPRIMS_add_cb3(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime, /* OUTPUT */long long *acf_ptr);

 extern long long NPRIMS_multiply_init(/* INPUT */int num_in);

 extern int NPRIMS_multiply_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index);

 extern int NPRIMS_multiply_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long out_ptr, /* OUTPUT */long long *state_ptr);

 extern int NPRIMS_multiply_cb3(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime);

 extern long long NPRIMS_power_init(/* INPUT */double index);

 extern void NPRIMS_power_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern double PRIMS_function_sample1(/* INPUT */long long trig, /* INPUT */double abs_time);

 extern long long PRIMS_function_sample2(/* INPUT */long long in, /* INPUT */long long trig, /* INPUT */double abs_time);

 extern long long PRIMS_function_sample3(/* INPUT */long long in);

 extern long long NPRIMS_delay_init(/* INPUT */double delay, /* INPUT */long long trig_out, /* INPUT */int skip_dc);

 extern void NPRIMS_delay_cb1(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* INPUT */long long in_ptr);

 extern void NPRIMS_delay_cb2(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime, /* OUTPUT */long long *acf_ptr);

 extern long long NPRIMS_delay_cb3(/* INPUT */long long prim_ptr);

 extern void PRIMS_function_dac2(/* INPUT */long long in);

 extern long long PRIMS_function_dac3(/* INPUT */long long out, /* INPUT */double t_event, /* INPUT */double p_out, /* INPUT */double v_out, /* INPUT */double tran_time, /* INPUT */double abs_time, /* INPUT */double abs_unit);

 extern double PRIMS_function_dac4(/* INPUT */long long trig, /* INPUT */double abs_time);

 extern long long PRIMS_function_dac5(/* INPUT */double v_out);

 extern double PRIMS_function_dac6(/* INPUT */long long out, /* INPUT */double start_time, /* INPUT */double p_out, /* INPUT */double v_out, /* INPUT */double tran_time, /* INPUT */double abs_time, /* INPUT */double abs_unit);

 extern double PRIMS_function_dac7(/* INPUT */double stop_time, /* INPUT */double abs_unit, /* INPUT */double rel_unit);

 extern unsigned char PRIMS_function_dac8(/* INPUT */long long in, /* INPUT */double abs_time);

 extern double PRIMS_function_dac9(/* INPUT */long long in, /* INPUT */double abs_time, /* INPUT */double abs_unit, /* INPUT */double t_event);

 extern long long NPRIMS_adc_init(/* INPUT */int num_bit);

 extern void NPRIMS_adc_cb1(/* INPUT */long long prim_ptr, /* INPUT */int index, /* INPUT */long long in_ptr);

 extern void NPRIMS_adc_cb2(/* INPUT */long long prim_ptr, /* INPUT */int index, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime);

 extern unsigned char PRIMS_function_compare1(/* INPUT */long long out, /* INPUT */long long in, /* INPUT */long long in_ref, /* INPUT */long long trig, /* INPUT */double threshold, /* INPUT */double sensitivity, /* INPUT */double abs_time);

 extern double PRIMS_function_compare2(/* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_function_compare3(/* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_function_compare4(/* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_function_compare5(/* INPUT */long long in, /* INPUT */long long in_ref, /* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_function_compare6(/* INPUT */long long in, /* INPUT */long long in_ref, /* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_function_compare7(/* INPUT */long long in, /* INPUT */long long in_ref, /* INPUT */long long trig, /* INPUT */double abs_time);

 extern unsigned char PRIMS_function_compare8(/* INPUT */long long in, /* INPUT */long long in_ref, /* INPUT */double threshold, /* INPUT */double mu, /* INPUT */double sig);

 extern long long PRIMS_function_compare9(/* INPUT */double regen_const);

 extern int PRIMS_function_compare10(/* INPUT */long long filter, /* INPUT */long long trig_delayed, /* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_function_compare11(/* INPUT */long long in, /* INPUT */double abs_time);

 extern long long PRIMS_function_compare12(/* INPUT */long long filter, /* INPUT */long long trig_delayed, /* INPUT */long long tf, /* INPUT */double abs_time);

 extern long long PRIMS_function_compare13(/* INPUT */long long filter, /* INPUT */long long tf, /* INPUT */double abs_time);

 extern double PRIMS_function_compare14(/* INPUT */long long filter, /* INPUT */long long trig_delayed, /* INPUT */double abs_time);

 extern long long PRIMS_function_compare15(/* INPUT */long long filter, /* INPUT */long long trig_delayed, /* INPUT */long long tf, /* INPUT */double abs_time);

 extern long long PRIMS_function_compare16();

 extern int PRIMS_function_compare17(/* INPUT */long long in, /* INPUT */double threshold, /* INPUT */double abs_unit);

 extern double PRIMS_function_compare18(/* INPUT */long long in);

 extern double PRIMS_function_compare19(/* INPUT */long long in, /* INPUT */long long trig, /* INPUT */double t_obs);

 extern int PRIMS_function_compare20(/* INPUT */long long in, /* INPUT */double abs_time);

 extern int PRIMS_function_compare21(/* INPUT */long long in, /* INPUT */void* t_cross);

 extern void* PRIMS_function_compare22(/* INPUT */long long in, /* INPUT */double threshold, /* INPUT */int max_iter, /* INPUT */double abs_unit);

 extern int PRIMS_function_compare23(/* INPUT */long long in, /* INPUT */void* t_cross);

 extern void* PRIMS_function_compare24(/* INPUT */long long in, /* INPUT */double threshold, /* INPUT */int max_iter, /* INPUT */double abs_unit);

 extern void* PRIMS_function_compare25(/* INPUT */long long in, /* INPUT */double threshold, /* INPUT */int max_iter, /* INPUT */double abs_unit, /* INPUT */double abs_time);

 extern double PRIMS_function_compare26(/* INPUT */void* t_cross, /* INPUT */double abs_unit, /* INPUT */double rel_unit, /* INPUT */double rel_time);

 extern int PRIMS_function_compare27(/* INPUT */void* t_cross, /* INPUT */double abs_time);

 extern int PRIMS_function_compare28(/* INPUT */void* t_cross);

 extern double PRIMS_function_compare29(/* INPUT */void* t_cross, /* INPUT */double delay_step, /* INPUT */double rel_time, /* INPUT */double time_scale);

 extern int PRIMS_function_compare30(/* INPUT */void* t_cross);

 extern double PRIMS_function_compare31(/* INPUT */void* n_cross, /* INPUT */void* t_cross);

 extern void* PRIMS_function_compare32(/* INPUT */long long in, /* INPUT */long long out, /* INPUT */double threshold, /* INPUT */double abs_unit, /* INPUT */int max_iter);

 extern void* PRIMS_function_compare33(/* INPUT */long long in, /* INPUT */long long out, /* INPUT */double threshold, /* INPUT */double abs_unit, /* INPUT */int max_iter);

 extern int PRIMS_function_compare34(/* INPUT */long long in, /* INPUT */long long out, /* INPUT */double threshold, /* INPUT */double abs_unit, /* INPUT */void* t_cross);

 extern double PRIMS_function_compare35(/* INPUT */long long in, /* INPUT */double threshold, /* INPUT */double delay_step, /* INPUT */double abs_time, /* INPUT */double rel_time, /* INPUT */double abs_unit, /* INPUT */double rel_unit, /* INPUT */int max_iter);

 extern unsigned char PRIMS_function_compare36(/* INPUT */long long out, /* INPUT */long long in, /* INPUT */long long in_ref, /* INPUT */long long trig, /* INPUT */double threshold, /* INPUT */double sensitivity, /* INPUT */double noise_in, /* INPUT */double abs_time);

 extern long long NPRIMS_slice_init(/* INPUT */double threshold, /* INPUT */int sync, /* INPUT */long long trig_handle);

 extern void NPRIMS_slice_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long ref_ptr);

 extern int NPRIMS_slice_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long ref_ptr, /* INPUT */int stat_mode, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0
);

 extern long long NPRIMS_pwl_func_init(/* INPUT */int data_size, /* INPUT */int scale_size, /* INPUT */const char* filename, /* INPUT */long long trig_out, /* OUTPUT */long long *data_handle, /* OUTPUT */long long *scale_handle);

 extern void NPRIMS_pwl_func_check(/* INPUT */long long prim_ptr);

 extern int NPRIMS_pwl_func_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern int NPRIMS_pwl_func_cb2(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* INPUT */long long in_ptr, /* INPUT */long long out_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */long long *acf_ptr);

 extern int NPRIMS_pwl_func_cb3(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime, /* OUTPUT */long long *acf_ptr);

 extern long long NPRIMS_integ_mod_init(/* INPUT */double scale, /* INPUT */double init_value, /* INPUT */double modulus, /* INPUT */double offset, /* INPUT */long long trig_out);

 extern int NPRIMS_integ_mod_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern int NPRIMS_integ_mod_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long out_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime);

 extern int NPRIMS_integ_mod_cb3(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime);

 extern long long NPRIMS_sin_func_init(/* INPUT */const char* mode, /* INPUT */double scale, /* INPUT */double abstol, /* INPUT */double reltol, /* INPUT */long long trig_handle);

 extern void NPRIMS_sin_func_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern void NPRIMS_sin_func_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime);

 extern long long NPRIMS_exp_func_init(/* INPUT */double base, /* INPUT */double scale, /* INPUT */double abstol, /* INPUT */double reltol, /* INPUT */long long trig_handle);

 extern void NPRIMS_exp_func_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern void NPRIMS_exp_func_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime);

 extern long long NPRIMS_delay_var_init(/* INPUT */double abstol, /* INPUT */double reltol, /* INPUT */long long trig_handle);

 extern void NPRIMS_delay_var_cb1(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* INPUT */long long in_ptr);

 extern void NPRIMS_delay_var_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long delay_ptr);

 extern int NPRIMS_delay_var_cb3(/* INPUT */long long prim_ptr, /* INPUT */long long delay_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime, /* OUTPUT */long long *acf_ptr);

 extern long long NPRIMS_ilo_init(/* INPUT */int num_in, /* INPUT */int num_phase, /* INPUT */double init_phase, /* INPUT */int ppv_size, /* INPUT */long long trig_handle, /* OUTPUT */long long *ppv_handle);

 extern void NPRIMS_ilo_check(/* INPUT */long long prim_ptr);

 extern int NPRIMS_ilo_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index);

 extern int NPRIMS_ilo_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long phase_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */long long *state_a_ptr);

 extern int NPRIMS_ilo_cb3(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */long long *state_a_ptr, /* OUTPUT */double *ftime);

 extern long long NPRIMS_minductor_init(/* INPUT */int num_port, /* OUTPUT */long long *L_handle, /* OUTPUT */long long *ic_handle);

 extern void NPRIMS_minductor_check(/* INPUT */long long prim_ptr);

 extern long long NPRIMS_mscale_init(/* INPUT */int num_sel, /* OUTPUT */long long *scale_handle, /* OUTPUT */long long *sel_handle);

 extern void NPRIMS_mscale_cb1(/* INPUT */long long prim_ptr, /* OUTPUT */double *mult, /* OUTPUT */int *index);

 extern long long NPRIMS_tline_unit_init(/* INPUT */int num_line, /* INPUT */double Z0, /* INPUT */double delay, /* INPUT */int ports_size, /* INPUT */int data_size, /* INPUT */const char* filename, /* INPUT */double index, /* OUTPUT */long long *ports_handle, /* OUTPUT */long long *data_handle);

 extern double NPRIMS_tline_unit_check(/* INPUT */long long prim_ptr, /* OUTPUT */long long *tf1_handle, /* OUTPUT */long long *tf2_handle);

 extern long long NPRIMS_buf_xbit_init(/* INPUT */double delay, /* INPUT */long long trig_out, /* INPUT */unsigned char inv_mode, /* INPUT */unsigned char twostate);

 extern void NPRIMS_buf_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat, /* INPUT */long long in_ptr);

 extern void NPRIMS_buf_xbit_cb2(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_delay_xbit_init(/* INPUT */double delay, /* INPUT */double RJ_rms, /* INPUT */long long trig_out);

 extern void NPRIMS_delay_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern void NPRIMS_delay_xbit_cb2(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_interp_xbit_init(/* INPUT */double delay, /* INPUT */long long trig_out, /* INPUT */int max_warn);

 extern void NPRIMS_interp_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */double weight);

 extern void NPRIMS_interp_xbit_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index, /* INPUT */int stat_mode);

 extern int NPRIMS_interp_xbit_cb3(/* INPUT */long long prim_ptr, /* INPUT */int stat_mode, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_interp_var_xbit_init(/* INPUT */long long trig_out, /* INPUT */int max_warn);

 extern void NPRIMS_interp_var_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */double weight);

 extern void NPRIMS_interp_var_xbit_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long delay_ptr, /* INPUT */int index, /* INPUT */int stat_mode);

 extern int NPRIMS_interp_var_xbit_cb3(/* INPUT */long long prim_ptr, /* INPUT */int stat_mode, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_mux_xbit_init(/* INPUT */int width_sel, /* INPUT */int num_in, /* INPUT */double delay, /* INPUT */long long handle);

 extern int NPRIMS_mux_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index);

 extern int NPRIMS_mux_xbit_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long sel_ptr, /* INPUT */int index);

 extern void NPRIMS_mux_xbit_cb3(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern void NPRIMS_mux_xbit_cb4(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_and_xbit_init(/* INPUT */int num_in, /* INPUT */double delay, /* INPUT */long long handle);

 extern void NPRIMS_and_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index);

 extern void NPRIMS_and_xbit_cb2(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern void NPRIMS_and_xbit_cb3(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_or_xbit_init(/* INPUT */int num_in, /* INPUT */double delay, /* INPUT */long long handle);

 extern void NPRIMS_or_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index);

 extern void NPRIMS_or_xbit_cb2(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern void NPRIMS_or_xbit_cb3(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_xor_xbit_init(/* INPUT */int num_in, /* INPUT */double delay, /* INPUT */long long handle);

 extern int NPRIMS_xor_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */int index);

 extern void NPRIMS_xor_xbit_cb2(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern void NPRIMS_xor_xbit_cb3(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_tribuf_xbit_init(/* INPUT */double delay, /* INPUT */long long handle);

 extern int NPRIMS_tribuf_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern int NPRIMS_tribuf_xbit_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long en_ptr);

 extern void NPRIMS_tribuf_xbit_cb3(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern void NPRIMS_tribuf_xbit_cb4(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long NPRIMS_latch_xbit_init(/* INPUT */double delay, /* INPUT */long long handle);

 extern int NPRIMS_latch_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern int NPRIMS_latch_xbit_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long en_ptr);

 extern void NPRIMS_latch_xbit_cb3(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern void NPRIMS_latch_xbit_cb4(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern double PRIMS_gate_dff1(/* INPUT */long long clk, /* INPUT */double delay, /* INPUT */double abs_time);

 extern double PRIMS_gate_dff2(/* INPUT */double t_event, /* INPUT */double abs_unit, /* INPUT */double rel_unit);

 extern unsigned char PRIMS_gate_dff3(/* INPUT */long long in, /* INPUT */long long clk, /* INPUT */double abs_time);

 extern void* PRIMS_gate_dff4(/* INPUT */long long in, /* INPUT */long long clk, /* INPUT */double abs_time);

 extern unsigned char PRIMS_gate_dff5(/* INPUT */void* sample);

 extern double PRIMS_gate_dff6(/* INPUT */void* sample);

 extern double PRIMS_gate_dff7(/* INPUT */void* sample);

 extern double PRIMS_gate_dff8(/* INPUT */void* sample);

 extern double PRIMS_gate_dff9(/* INPUT */void* sample);

 extern double PRIMS_gate_dff_set_sync1(/* INPUT */long long clk, /* INPUT */double delay, /* INPUT */double abs_time);

 extern double PRIMS_gate_dff_set_sync2(/* INPUT */double t_event, /* INPUT */double abs_unit, /* INPUT */double rel_unit);

 extern unsigned char PRIMS_gate_dff_set_sync3(/* INPUT */long long in, /* INPUT */long long clk, /* INPUT */long long set, /* INPUT */double abs_time);

 extern double PRIMS_gate_dff_rst_sync1(/* INPUT */long long clk, /* INPUT */double delay, /* INPUT */double abs_time);

 extern double PRIMS_gate_dff_rst_sync2(/* INPUT */double t_event, /* INPUT */double abs_unit, /* INPUT */double rel_unit);

 extern unsigned char PRIMS_gate_dff_rst_sync3(/* INPUT */long long in, /* INPUT */long long clk, /* INPUT */long long rst, /* INPUT */double abs_time);

 extern double PRIMS_gate_dff_set_async1(/* INPUT */long long clk, /* INPUT */long long set, /* INPUT */double c_delay, /* INPUT */double s_delay, /* INPUT */double abs_time);

 extern double PRIMS_gate_dff_set_async2(/* INPUT */double t_event, /* INPUT */double abs_unit, /* INPUT */double rel_unit);

 extern unsigned char PRIMS_gate_dff_set_async3(/* INPUT */long long in, /* INPUT */long long clk, /* INPUT */long long set, /* INPUT */double abs_time);

 extern double PRIMS_gate_dff_rst_async1(/* INPUT */long long clk, /* INPUT */long long rst, /* INPUT */double c_delay, /* INPUT */double r_delay, /* INPUT */double abs_time);

 extern double PRIMS_gate_dff_rst_async2(/* INPUT */double t_event, /* INPUT */double abs_unit, /* INPUT */double rel_unit);

 extern unsigned char PRIMS_gate_dff_rst_async3(/* INPUT */long long in, /* INPUT */long long clk, /* INPUT */long long rst, /* INPUT */double abs_time);

 extern long long PRIMS_stim_clkgen1(/* INPUT */double freq, /* INPUT */double init_phase, /* INPUT */double SJ_amp, /* INPUT */double SJ_freq, /* INPUT */double abs_unit);

 extern long long NPRIMS_pulse_gen_init(/* INPUT */unsigned char init_value, /* INPUT */double delay, /* INPUT */double width, /* INPUT */double period, /* INPUT */long long handle);

 extern int NPRIMS_pulse_gen_cb1(/* INPUT */long long prim_ptr, /* INPUT */int flag_init, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime);

 extern long long NPRIMS_sin_gen_init(/* INPUT */double offset, /* INPUT */double amp, /* INPUT */double freq, /* INPUT */double delay, /* INPUT */double damp, /* INPUT */double init_phase, /* INPUT */double AM_offset, /* INPUT */double AM_amp, /* INPUT */double AM_freq, /* INPUT */double FM_index, 
/* INPUT */double FM_freq);

 extern void NPRIMS_sin_gen_cb0(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state0, /* OUTPUT */long long *state1, /* OUTPUT */unsigned long long *ctime, /* OUTPUT */double *ftime);

 extern long long NPRIMS_chirp_gen_init(/* INPUT */const char* mode, /* INPUT */double freq_start, /* INPUT */double freq_stop, /* INPUT */double period, /* INPUT */double init_phase);

 extern void NPRIMS_chirp_gen_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *ftime);

 extern long long NPRIMS_pwl_gen_init(/* INPUT */int data_size, /* INPUT */double repeat_pos, /* INPUT */double period, /* INPUT */double delay, /* INPUT */const char* filename, /* INPUT */long long trig_out, /* OUTPUT */long long *data_handle);

 extern void NPRIMS_pwl_gen_cb0(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state, /* OUTPUT */double *ftime);

 extern void NPRIMS_pwl_gen_cb1(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state, /* OUTPUT */double *ftime);

 extern long long NPRIMS_exp_gen_init(/* INPUT */double init_value, /* INPUT */double change, /* INPUT */double delay1, /* INPUT */double delay2, /* INPUT */double tau1, /* INPUT */double tau2);

 extern void NPRIMS_exp_gen_cb0(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state0, /* OUTPUT */long long *state1, /* OUTPUT */unsigned long long *ctime1, /* OUTPUT */double *ftime1, /* OUTPUT */long long *state2, /* OUTPUT */unsigned long long *ctime2, /* OUTPUT */double *ftime2);

 extern long long NPRIMS_pat_gen_init(/* INPUT */int data_size, /* INPUT */int repeat_pos, /* INPUT */int repeat_num, /* INPUT */const char* filename, /* OUTPUT */long long *data_handle);

 extern void NPRIMS_pat_gen_cb0(/* INPUT */long long prim_ptr);

 extern int NPRIMS_pat_gen_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long trig_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime);

 extern long long PRIMS_stim_dcgen1(/* INPUT */double value);

 extern long long PRIMS_stim_dcgen2(/* INPUT */double noise);

 extern long long PRIMS_stim_noisegen1(/* INPUT */double value);

 extern long long PRIMS_stim_noisegen2(/* INPUT */double stddev);

 extern long long PRIMS_stim_stepgen1(/* INPUT */double value);

 extern long long PRIMS_stim_stepgen2(/* INPUT */double change);

 extern long long NPRIMS_replay_xreal_init(/* INPUT */const char* filename, /* INPUT */const char* signal, /* INPUT */double abstol, /* INPUT */double reltol, /* INPUT */double start, /* INPUT */double stop, /* INPUT */double delay, /* INPUT */double init_value, /* INPUT */double final_value, /* INPUT */long long trig_out
);

 extern void NPRIMS_replay_xreal_cb0(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state, /* OUTPUT */double *ftime);

 extern void NPRIMS_replay_xreal_cb1(/* INPUT */long long prim_ptr, /* OUTPUT */long long *state, /* OUTPUT */double *ftime);

 extern long long NPRIMS_replay_xbit_init(/* INPUT */const char* filename, /* INPUT */const char* signal, /* INPUT */int width, /* INPUT */double start, /* INPUT */double stop, /* INPUT */double delay, /* INPUT */long long trig_out, /* OUTPUT */long long *init_handle, /* OUTPUT */long long *final_handle);

 extern void NPRIMS_replay_xbit_cb0(/* INPUT */long long prim_ptr, /* INPUT */int index, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime);

 extern void NPRIMS_replay_xbit_cb1(/* INPUT */long long prim_ptr, /* INPUT */int index, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime);

 extern double PRIMS_meas_probeber1(/* INPUT */long long in, /* INPUT */double delay);

 extern double PRIMS_meas_probeber2(/* INPUT */double t_event, /* INPUT */double abs_unit, /* INPUT */double rel_unit);

 extern unsigned char PRIMS_meas_probeber3(/* INPUT */long long in_ptr, /* INPUT */double abs_time, /* INPUT */double t_offset, /* INPUT */double abs_unit, /* INPUT */double j_mean, /* INPUT */double j_rms);

 extern double PRIMS_meas_probeber4(/* INPUT */long long in_ptr, /* INPUT */double abs_time, /* INPUT */double t_offset, /* INPUT */double abs_unit, /* INPUT */double j_mean, /* INPUT */double j_rms);

 extern double PRIMS_meas_probeber5(/* INPUT */long long in_ptr, /* INPUT */double abs_time, /* INPUT */double t_offset, /* INPUT */double abs_unit, /* INPUT */double j_mean, /* INPUT */double j_rms);

 extern long long NPRIMS_trig_time_init(/* INPUT */double delay, /* INPUT */double period, /* INPUT */int data_size, /* OUTPUT */long long *data_handle);

 extern void NPRIMS_trig_time_cb1(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */unsigned long long *ctime, /* OUTPUT */double *ftime, /* OUTPUT */int *flag);

 extern void NPRIMS_trig_time_cb2(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */unsigned long long *ctime, /* OUTPUT */double *ftime, /* OUTPUT */int *flag);

 extern long long NPRIMS_trig_edge_init(/* INPUT */int direction, /* INPUT */double delay, /* INPUT */int times);

 extern void NPRIMS_trig_edge_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime);

 extern long long NPRIMS_meas_time_init();

 extern double NPRIMS_meas_time_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long trig_ptr);

 extern void NPRIMS_meas_time_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long trig_ptr, /* OUTPUT */unsigned long long *ctime, /* OUTPUT */double *ftime);

 extern double NPRIMS_meas_time_cb3(/* INPUT */long long prim_ptr, /* INPUT */unsigned long long ctime1, /* INPUT */double ftime1, /* INPUT */unsigned long long ctime2, /* INPUT */double ftime2);

 extern long long NPRIMS_meas_value_init();

 extern double NPRIMS_meas_value_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long trig_ptr);

 extern long long NPRIMS_meas_deriv_init(/* INPUT */int order);

 extern double NPRIMS_meas_deriv_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long trig_ptr);

 extern long long NPRIMS_meas_max_init();

 extern void NPRIMS_meas_max_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern void NPRIMS_meas_max_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern double NPRIMS_meas_max_cb3(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern long long NPRIMS_meas_min_init();

 extern void NPRIMS_meas_min_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern void NPRIMS_meas_min_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern double NPRIMS_meas_min_cb3(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern long long NPRIMS_meas_pp_init();

 extern void NPRIMS_meas_pp_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern void NPRIMS_meas_pp_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern double NPRIMS_meas_pp_cb3(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern long long NPRIMS_meas_integ_init();

 extern void NPRIMS_meas_integ_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern void NPRIMS_meas_integ_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern double NPRIMS_meas_integ_cb3(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern long long NPRIMS_meas_avg_init();

 extern void NPRIMS_meas_avg_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern void NPRIMS_meas_avg_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern double NPRIMS_meas_avg_cb3(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern long long NPRIMS_meas_rms_init();

 extern void NPRIMS_meas_rms_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern void NPRIMS_meas_rms_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern double NPRIMS_meas_rms_cb3(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* INPUT */long long from_ptr, /* INPUT */long long to_ptr);

 extern long long NPRIMS_probe_ac_init();

 extern int NPRIMS_probe_ac_cb1(/* INPUT */long long prim_ptr, /* INPUT */double freq, /* INPUT */double resp_i, /* INPUT */double resp_q, /* OUTPUT */double *tffreq, /* OUTPUT */double *tfmag, /* OUTPUT */double *tfphase);

 extern int NPRIMS_probe_ac_cb2(/* INPUT */long long prim_ptr, /* OUTPUT */double *tffreq, /* OUTPUT */double *tfmag, /* OUTPUT */double *tfphase);

 extern long long NPRIMS_clk_to_duty_init();

 extern int NPRIMS_clk_to_duty_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern long long NPRIMS_clk_to_freq_init();

 extern int NPRIMS_clk_to_freq_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern long long NPRIMS_clk_to_period_init();

 extern int NPRIMS_clk_to_period_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern long long NPRIMS_clk_to_phase_init(/* INPUT */double freq, /* INPUT */int phase_wrap);

 extern int NPRIMS_clk_to_phase_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern long long NPRIMS_clk_to_delay_init(/* INPUT */double delay_trig, /* INPUT */double delay_in, /* INPUT */int skip_trig, /* INPUT */int skip_in);

 extern int NPRIMS_clk_to_delay_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long trig_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern int NPRIMS_clk_to_delay_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr, /* OUTPUT */long long *state_ptr, /* OUTPUT */double *t_offset);

 extern long long NPRIMS_phase_to_clk_init(/* INPUT */int num_phase, /* INPUT */double freq, /* INPUT */double RJ_kappa, /* INPUT */double PN_fcenter, /* INPUT */double PN_foffset, /* INPUT */double PN_dbc, /* INPUT */long long trig_out);

 extern int NPRIMS_phase_to_clk_set(/* INPUT */long long prim_ptr, /* OUTPUT */int *index, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern int NPRIMS_phase_to_clk_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern void NPRIMS_phase_to_clk_cb2(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern void NPRIMS_phase_to_clk_cb3(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern long long NPRIMS_freq_to_clk_init(/* INPUT */int num_phase, /* INPUT */double init_phase, /* INPUT */double RJ_kappa, /* INPUT */double PN_fcenter, /* INPUT */double PN_foffset, /* INPUT */double PN_dbc, /* INPUT */long long trig_out);

 extern int NPRIMS_freq_to_clk_set(/* INPUT */long long prim_ptr, /* OUTPUT */int *index, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern int NPRIMS_freq_to_clk_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern void NPRIMS_freq_to_clk_cb2(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern void NPRIMS_freq_to_clk_cb3(/* INPUT */long long prim_ptr, /* INPUT */int flag_stat);

 extern long long NPRIMS_delay_to_clk_init(/* INPUT */double RJ_rms, /* INPUT */double RJ_kappa, /* INPUT */long long trig_out, /* INPUT */int max_iter);

 extern void NPRIMS_delay_to_clk_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern void NPRIMS_delay_to_clk_cb2(/* INPUT */long long prim_ptr, /* INPUT */long long trig_ptr);

 extern void NPRIMS_delay_to_clk_cb3(/* INPUT */long long prim_ptr, /* OUTPUT */unsigned char *value, /* OUTPUT */double *ftime, /* OUTPUT */double *j_mean, /* OUTPUT */double *j_rms, /* OUTPUT */double *prob1, /* OUTPUT */double *prob0);

 extern long long PRIMS_vdt_period2clk1(/* INPUT */long long in, /* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_vdt_period2clk2(/* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_vdt_duty2clk1(/* INPUT */long long in, /* INPUT */long long trig, /* INPUT */double abs_time);

 extern double PRIMS_connect_bit2xbit1(/* INPUT */double t_event, /* INPUT */double rel_unit, /* INPUT */double time_scale);

 extern long long NPRIMS_real_to_xreal_init(/* INPUT */double abstol, /* INPUT */double delay, /* INPUT */long long trig_out);

 extern void NPRIMS_real_to_xreal_cb1(/* INPUT */long long prim_ptr, /* INPUT */double in, /* OUTPUT */long long *state, /* OUTPUT */double *ftime);

 extern void NPRIMS_real_to_xreal_cb2(/* INPUT */long long prim_ptr, /* INPUT */double in, /* OUTPUT */long long *state, /* OUTPUT */double *ftime);

 extern void NPRIMS_real_to_xreal_cb3(/* INPUT */long long prim_ptr, /* INPUT */long long state_ptr, /* INPUT */double ftime);

 extern double PRIMS_connect_xreal2real1(/* INPUT */long long in, /* INPUT */double abs_time);

 extern long long NPRIMS_xbit_to_real_init(/* INPUT */double delay, /* INPUT */long long handle);

 extern void NPRIMS_xbit_to_real_cb1(/* INPUT */long long prim_ptr, /* INPUT */long long in_ptr);

 extern long long XMODEL_set_bbeq(/* INPUT */double I_val, /* INPUT */double Q_val, /* INPUT */double freq);

 extern int XMODEL_get_bbeq(/* INPUT */long long in_ptr, /* INPUT */double freq, /* OUTPUT */long long *st_I, /* OUTPUT */long long *st_Q, /* OUTPUT */double *t_offset);

 extern void XMODEL_sample_bbeq(/* INPUT */long long bb_I_ptr, /* INPUT */long long bb_Q_ptr, /* OUTPUT */double *I_comp, /* OUTPUT */double *Q_comp);

 extern double math_sqrt(/* INPUT */double rVal);

 extern double math_cos(/* INPUT */double rTheta);

 extern double math_sin(/* INPUT */double rTheta);

 extern double math_tan(/* INPUT */double rTheta);

 extern double math_acos(/* INPUT */double rVal);

 extern double math_asin(/* INPUT */double rVal);

 extern double math_atan(/* INPUT */double rVal);

 extern double math_atan2(/* INPUT */double y, /* INPUT */double x);

 extern double math_log(/* INPUT */double rVal);

 extern double math_log10(/* INPUT */double rVal);

 extern double math_fabs(/* INPUT */double x);

 extern double math_fmod(/* INPUT */double x, /* INPUT */double y);

 extern double math_round(/* INPUT */double x);

 extern double math_floor(/* INPUT */double x);

 extern double math_ceil(/* INPUT */double x);

 extern double math_pow(/* INPUT */double base, /* INPUT */double exp);

 extern double math_erf(/* INPUT */double value);

 extern double math_erfc(/* INPUT */double value);

 extern int math_isfinite(/* INPUT */double value);

 extern int math_isnan(/* INPUT */double value);

 extern int math_isinf(/* INPUT */double value);

 extern double ceil_float(/* INPUT */double x);

 extern int eq_float(/* INPUT */double x, /* INPUT */double y, /* INPUT */int tol);

 extern void rand_seed(/* INPUT */int seed);

 extern double rand_gaussian(/* INPUT */double mean, /* INPUT */double variance);

 extern double rand_uniform(/* INPUT */double a, /* INPUT */double b);

 extern double rand_basic();

#ifdef __cplusplus
}
#endif

