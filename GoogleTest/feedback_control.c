/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.c
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

#include "feedback_control.h"

/* Named constants for Chart: '<Root>/Stateflow_controller' */
#define feedback_con_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define feedback_contr_IN_INITIAL_STATE ((uint8_T)3U)
#define feedback_contro_IN_SAVE_MEASURE ((uint8_T)7U)
#define feedback_control_IN_COUNTER    ((uint8_T)1U)
#define feedback_control_IN_ERROR      ((uint8_T)2U)
#define feedback_control_IN_IN_RANGE   ((uint8_T)4U)
#define feedback_control_IN_MEAN       ((uint8_T)5U)
#define feedback_control_IN_OFF        ((uint8_T)1U)
#define feedback_control_IN_ON         ((uint8_T)2U)
#define feedback_control_IN_OUT_RANGE  ((uint8_T)6U)
#define feedback_control_IN_TRIGGER_OFF ((uint8_T)1U)
#define feedback_control_IN_TRIGGER_ON ((uint8_T)2U)

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

/* Model step function */
void feedback_control_step(RT_MODEL_feedback_control *const feedback_control_M,
  uint8_T feedback_control_U_echo_input, uint8_T *feedback_control_Y_level,
  uint8_T *feedback_control_Y_trigger_output)
{
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;

  /* Chart: '<Root>/Stateflow_controller' incorporates:
   *  Inport: '<Root>/echo_input'
   */
  if (feedback_control_DWork->temporalCounter_i1 < 65535U) {
    feedback_control_DWork->temporalCounter_i1++;
  }

  if (feedback_control_DWork->temporalCounter_i2 < 65535U) {
    feedback_control_DWork->temporalCounter_i2++;
  }

  if (feedback_control_DWork->temporalCounter_i3 < MAX_uint32_T) {
    feedback_control_DWork->temporalCounter_i3++;
  }

  /* Gateway: Stateflow_controller */
  /* During: Stateflow_controller */
  if (feedback_control_DWork->is_active_c3_feedback_control == 0U) {
    /* Entry: Stateflow_controller */
    feedback_control_DWork->is_active_c3_feedback_control = 1U;

    /* Entry Internal: Stateflow_controller */
    /* Entry 'TRIGGER': '<S1>:4' */
    /* Entry Internal 'TRIGGER': '<S1>:4' */
    /* Transition: '<S1>:7' */
    feedback_control_DWork->is_TRIGGER = feedback_control_IN_TRIGGER_ON;
    feedback_control_DWork->temporalCounter_i1 = 0U;

    /* Outport: '<Root>/trigger_output' */
    /* Entry 'TRIGGER_ON': '<S1>:6' */
    *feedback_control_Y_trigger_output = 1U;

    /* Entry Internal 'LOGIC_OPERATOR': '<S1>:11' */
    /* Transition: '<S1>:13' */
    feedback_control_DWork->is_LOGIC_OPERATOR = feedback_contr_IN_INITIAL_STATE;
    feedback_control_DWork->temporalCounter_i2 = 0U;

    /* Entry 'INITIAL_STATE': '<S1>:12' */
    feedback_control_DWork->dist_v[0] = 0.0;
    feedback_control_DWork->dist_v[1] = 0.0;
    feedback_control_DWork->dist_v[2] = 0.0;
    feedback_control_DWork->dist_v[3] = 0.0;
    feedback_control_DWork->i = 1U;
    feedback_control_DWork->counter = 0U;
    feedback_control_DWork->mean = 0.0;

    /* Entry Internal 'LED': '<S1>:51' */
    /* Transition: '<S1>:53' */
    feedback_control_DWork->is_LED = feedback_control_IN_OFF;
    feedback_control_DWork->temporalCounter_i3 = 0U;

    /* Outport: '<Root>/level' */
    /* Entry 'OFF': '<S1>:52' */
    *feedback_control_Y_level = 0U;
  } else {
    /* During 'TRIGGER': '<S1>:4' */
    if (feedback_control_DWork->is_TRIGGER == feedback_control_IN_TRIGGER_OFF) {
      /* Outport: '<Root>/trigger_output' */
      *feedback_control_Y_trigger_output = 0U;

      /* During 'TRIGGER_OFF': '<S1>:8' */
      if (feedback_control_DWork->temporalCounter_i1 >= 60000U) {
        /* Transition: '<S1>:10' */
        feedback_control_DWork->is_TRIGGER = feedback_control_IN_TRIGGER_ON;
        feedback_control_DWork->temporalCounter_i1 = 0U;

        /* Outport: '<Root>/trigger_output' */
        /* Entry 'TRIGGER_ON': '<S1>:6' */
        *feedback_control_Y_trigger_output = 1U;
      }
    } else {
      /* Outport: '<Root>/trigger_output' */
      *feedback_control_Y_trigger_output = 1U;

      /* During 'TRIGGER_ON': '<S1>:6' */
      if (feedback_control_DWork->temporalCounter_i1 >= 10U) {
        /* Transition: '<S1>:9' */
        feedback_control_DWork->is_TRIGGER = feedback_control_IN_TRIGGER_OFF;
        feedback_control_DWork->temporalCounter_i1 = 0U;

        /* Outport: '<Root>/trigger_output' */
        /* Entry 'TRIGGER_OFF': '<S1>:8' */
        *feedback_control_Y_trigger_output = 0U;
      }
    }

    /* During 'LOGIC_OPERATOR': '<S1>:11' */
    switch (feedback_control_DWork->is_LOGIC_OPERATOR) {
     case feedback_control_IN_COUNTER:
      /* During 'COUNTER': '<S1>:14' */
      if (feedback_control_U_echo_input == 0) {
        /* Transition: '<S1>:18' */
        feedback_control_DWork->is_LOGIC_OPERATOR =
          feedback_contro_IN_SAVE_MEASURE;
        feedback_control_DWork->temporalCounter_i2 = 0U;

        /* Entry 'SAVE_MEASURE': '<S1>:16' */
        feedback_control_DWork->dist_v[feedback_control_DWork->i - 1] =
          feedback_control_DWork->counter;
      } else {
        feedback_control_DWork->counter++;
      }
      break;

     case feedback_control_IN_ERROR:
      /* During 'ERROR': '<S1>:26' */
      /* Transition: '<S1>:46' */
      /* Transition: '<S1>:47' */
      feedback_control_DWork->is_LOGIC_OPERATOR =
        feedback_contr_IN_INITIAL_STATE;
      feedback_control_DWork->temporalCounter_i2 = 0U;

      /* Entry 'INITIAL_STATE': '<S1>:12' */
      feedback_control_DWork->dist_v[0] = 0.0;
      feedback_control_DWork->dist_v[1] = 0.0;
      feedback_control_DWork->dist_v[2] = 0.0;
      feedback_control_DWork->dist_v[3] = 0.0;
      feedback_control_DWork->i = 1U;
      feedback_control_DWork->counter = 0U;
      feedback_control_DWork->mean = 0.0;
      break;

     case feedback_contr_IN_INITIAL_STATE:
      /* During 'INITIAL_STATE': '<S1>:12' */
      if (feedback_control_U_echo_input == 1) {
        /* Transition: '<S1>:15' */
        feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_COUNTER;

        /* Entry 'COUNTER': '<S1>:14' */
        feedback_control_DWork->counter++;
      } else {
        if (feedback_control_DWork->temporalCounter_i2 >= 60010U) {
          /* Transition: '<S1>:50' */
          /* Transition: '<S1>:49' */
          feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_ERROR;

          /* Entry 'ERROR': '<S1>:26' */
          feedback_control_DWork->up = 0.5;
          feedback_control_DWork->down = 0.5;
        }
      }
      break;

     case feedback_control_IN_IN_RANGE:
      /* During 'IN_RANGE': '<S1>:24' */
      if (feedback_control_U_echo_input == 1) {
        /* Transition: '<S1>:30' */
        feedback_control_DWork->counter = 0U;

        /* Transition: '<S1>:33' */
        /* Transition: '<S1>:34' */
        feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_COUNTER;

        /* Entry 'COUNTER': '<S1>:14' */
        feedback_control_DWork->counter++;
      } else {
        if (feedback_control_DWork->temporalCounter_i2 >= 60010U) {
          /* Transition: '<S1>:39' */
          /* Transition: '<S1>:42' */
          /* Transition: '<S1>:43' */
          feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_ERROR;

          /* Entry 'ERROR': '<S1>:26' */
          feedback_control_DWork->up = 0.5;
          feedback_control_DWork->down = 0.5;
        }
      }
      break;

     case feedback_control_IN_MEAN:
      /* During 'MEAN': '<S1>:20' */
      if ((feedback_control_DWork->mean >= 10.0) &&
          (feedback_control_DWork->mean <= 100.0)) {
        /* Transition: '<S1>:28' */
        feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_IN_RANGE;
        feedback_control_DWork->temporalCounter_i2 = 0U;

        /* Entry 'IN_RANGE': '<S1>:24' */
        feedback_control_DWork->up = feedback_control_DWork->mean * 0.001;
        feedback_control_DWork->down = 0.1 - feedback_control_DWork->up;
      } else {
        /* Transition: '<S1>:29' */
        feedback_control_DWork->is_LOGIC_OPERATOR =
          feedback_control_IN_OUT_RANGE;
        feedback_control_DWork->temporalCounter_i2 = 0U;

        /* Entry 'OUT_RANGE': '<S1>:25' */
        feedback_control_DWork->up = 0.25;
        feedback_control_DWork->down = 0.25;
      }
      break;

     case feedback_control_IN_OUT_RANGE:
      /* During 'OUT_RANGE': '<S1>:25' */
      if (feedback_control_U_echo_input == 1) {
        /* Transition: '<S1>:35' */
        feedback_control_DWork->counter = 0U;

        /* Transition: '<S1>:33' */
        /* Transition: '<S1>:34' */
        feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_COUNTER;

        /* Entry 'COUNTER': '<S1>:14' */
        feedback_control_DWork->counter++;
      } else {
        if (feedback_control_DWork->temporalCounter_i2 >= 60010U) {
          /* Transition: '<S1>:37' */
          /* Transition: '<S1>:40' */
          /* Transition: '<S1>:42' */
          /* Transition: '<S1>:43' */
          feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_ERROR;

          /* Entry 'ERROR': '<S1>:26' */
          feedback_control_DWork->up = 0.5;
          feedback_control_DWork->down = 0.5;
        }
      }
      break;

     default:
      /* During 'SAVE_MEASURE': '<S1>:16' */
      if (feedback_control_DWork->i == 4) {
        /* Transition: '<S1>:23' */
        feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_MEAN;

        /* Entry 'MEAN': '<S1>:20' */
        feedback_control_DWork->mean = (((feedback_control_DWork->dist_v[0] +
          feedback_control_DWork->dist_v[1]) + feedback_control_DWork->dist_v[2])
          + feedback_control_DWork->dist_v[3]) / 232.0;
        feedback_control_DWork->dist_v[0] = feedback_control_DWork->dist_v[1];
        feedback_control_DWork->dist_v[1] = feedback_control_DWork->dist_v[2];
        feedback_control_DWork->dist_v[2] = feedback_control_DWork->dist_v[3];
        feedback_control_DWork->i = 4U;
      } else if (feedback_control_U_echo_input == 1) {
        /* Transition: '<S1>:19' */
        feedback_control_DWork->counter = 0U;
        feedback_control_DWork->i++;
        feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_COUNTER;

        /* Entry 'COUNTER': '<S1>:14' */
        feedback_control_DWork->counter++;
      } else {
        if (feedback_control_DWork->temporalCounter_i2 >= 60010U) {
          /* Transition: '<S1>:44' */
          feedback_control_DWork->is_LOGIC_OPERATOR = feedback_control_IN_ERROR;

          /* Entry 'ERROR': '<S1>:26' */
          feedback_control_DWork->up = 0.5;
          feedback_control_DWork->down = 0.5;
        }
      }
      break;
    }

    /* During 'LED': '<S1>:51' */
    if (feedback_control_DWork->is_LED == feedback_control_IN_OFF) {
      /* Outport: '<Root>/level' */
      *feedback_control_Y_level = 0U;

      /* During 'OFF': '<S1>:52' */
      if (feedback_control_DWork->temporalCounter_i3 >= ((uint32_T)ceil
           ((feedback_control_DWork->down / 1.0E-6) - 1.0E-14))) {
        /* Transition: '<S1>:55' */
        feedback_control_DWork->is_LED = feedback_control_IN_ON;
        feedback_control_DWork->temporalCounter_i3 = 0U;

        /* Outport: '<Root>/level' */
        /* Entry 'ON': '<S1>:54' */
        *feedback_control_Y_level = 1U;
      }
    } else {
      /* Outport: '<Root>/level' */
      *feedback_control_Y_level = 1U;

      /* During 'ON': '<S1>:54' */
      if ((feedback_control_DWork->temporalCounter_i3 >= ((uint32_T)ceil
            ((feedback_control_DWork->up / 1.0E-6) - 1.0E-14))) &&
          (feedback_control_DWork->down != 0.0)) {
        /* Transition: '<S1>:56' */
        feedback_control_DWork->is_LED = feedback_control_IN_OFF;
        feedback_control_DWork->temporalCounter_i3 = 0U;

        /* Outport: '<Root>/level' */
        /* Entry 'OFF': '<S1>:52' */
        *feedback_control_Y_level = 0U;
      }
    }
  }

  /* End of Chart: '<Root>/Stateflow_controller' */
}

/* Model initialize function */
void feedback_control_initialize(RT_MODEL_feedback_control *const
  feedback_control_M, uint8_T *feedback_control_U_echo_input, uint8_T
  *feedback_control_Y_level, uint8_T *feedback_control_Y_trigger_output)
{
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)feedback_control_DWork, 0,
                sizeof(D_Work_feedback_control));

  /* external inputs */
  *feedback_control_U_echo_input = 0U;

  /* external outputs */
  (*feedback_control_Y_level) = 0U;
  (*feedback_control_Y_trigger_output) = 0U;

  /* SystemInitialize for Chart: '<Root>/Stateflow_controller' */
  feedback_control_DWork->is_LED = feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->temporalCounter_i3 = 0U;
  feedback_control_DWork->is_LOGIC_OPERATOR = feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->temporalCounter_i2 = 0U;
  feedback_control_DWork->is_TRIGGER = feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->temporalCounter_i1 = 0U;
  feedback_control_DWork->is_active_c3_feedback_control = 0U;
  feedback_control_DWork->up = 2.0;
  feedback_control_DWork->down = 2.0;
}

/* Model terminate function */
void feedback_control_terminate(RT_MODEL_feedback_control *const
  feedback_control_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(feedback_control_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
