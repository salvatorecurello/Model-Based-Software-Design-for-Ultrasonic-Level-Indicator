/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.h
 *
 * Code generated for Simulink model 'feedback_control'.
 *
 * Model version                  : 1.57
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jun 24 15:44:09 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_feedback_control_h_
#define RTW_HEADER_feedback_control_h_
#include <math.h>
#include <string.h>
#ifndef feedback_control_COMMON_INCLUDES_
#define feedback_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* feedback_control_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_feedback_control RT_MODEL_feedback_control;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T mean;                         /* '<Root>/Stateflow_controller' */
  real_T dist_v[4];                    /* '<Root>/Stateflow_controller' */
  real_T up;                           /* '<Root>/Stateflow_controller' */
  real_T down;                         /* '<Root>/Stateflow_controller' */
  uint32_T temporalCounter_i3;         /* '<Root>/Stateflow_controller' */
  uint16_T counter;                    /* '<Root>/Stateflow_controller' */
  uint16_T temporalCounter_i1;         /* '<Root>/Stateflow_controller' */
  uint16_T temporalCounter_i2;         /* '<Root>/Stateflow_controller' */
  uint8_T is_active_c3_feedback_control;/* '<Root>/Stateflow_controller' */
  uint8_T is_TRIGGER;                  /* '<Root>/Stateflow_controller' */
  uint8_T is_LOGIC_OPERATOR;           /* '<Root>/Stateflow_controller' */
  uint8_T is_LED;                      /* '<Root>/Stateflow_controller' */
  uint8_T i;                           /* '<Root>/Stateflow_controller' */
} D_Work_feedback_control;

/* Real-time Model Data Structure */
struct tag_RTM_feedback_control {
  const char_T * volatile errorStatus;
  D_Work_feedback_control *dwork;
};

/* Model entry point functions */
extern void feedback_control_initialize(RT_MODEL_feedback_control *const
  feedback_control_M, uint8_T *feedback_control_U_echo_input, uint8_T
  *feedback_control_Y_level, uint8_T *feedback_control_Y_trigger_output);
extern void feedback_control_step(RT_MODEL_feedback_control *const
  feedback_control_M, uint8_T feedback_control_U_echo_input, uint8_T
  *feedback_control_Y_level, uint8_T *feedback_control_Y_trigger_output);
extern void feedback_control_terminate(RT_MODEL_feedback_control *const
  feedback_control_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'feedback_control'
 * '<S1>'   : 'feedback_control/Stateflow_controller'
 */
#endif                                 /* RTW_HEADER_feedback_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
