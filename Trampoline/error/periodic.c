#include <stdio.h>
#include "tpl_os.h"

#include "feedback_control.h"
#include "rtwtypes.h"

static RT_MODEL_feedback_control feedback_control_M_;
static RT_MODEL_feedback_control *const feedback_control_MPtr = &feedback_control_M_;                /* Real-time model */
static D_Work_feedback_control feedback_control_DWork;/* Observable states */

/* '<Root>/WindPWM' */
static uint8_T feedback_control_U_echo_input;

/* '<Root>/Warning' */
static uint8_T feedback_control_Y_level;

/* '<Root>/enable' */
static uint8_T feedback_control_Y_trigger_output;

void setup()
{
        /* Pack model data into RTM */
        feedback_control_MPtr->dwork = &feedback_control_DWork;

        /* Initialize model */
	feedback_control_initialize(feedback_control_MPtr, &feedback_control_U_echo_input, &feedback_control_Y_level, &feedback_control_Y_trigger_output);
}

int main(void)
{
    setup();

    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(alarm_10msec);

real_T BSWreadEchoInput( void )
{       
  static uint8_T echo_value = 0;
  static int n_activation = 1;
                
        echo_value=0;
                
        printf( "BSWreadEchoInput (%d): %d\r\n", n_activation, echo_value );
                              
        n_activation++;

        
  return( echo_value );
}


void    BSWwriteLevel( uint8_T x )
{
	static int n_activation = 0;

	n_activation++;

        if( x != 0 )
        {
                printf( "BSWwriteLevel(%d): 1\r\n", n_activation );
        }
        else
        {
                printf( "BSWwriteLevel(%d): 0\r\n", n_activation );
        }
}

TASK(my_periodic_task)
{
  printf( "---\r\n" );
  feedback_control_U_echo_input = BSWreadEchoInput();
    
  feedback_control_step(feedback_control_MPtr, feedback_control_U_echo_input, &feedback_control_Y_level, &feedback_control_Y_trigger_output);

  BSWwriteLevel( feedback_control_Y_level );

  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(alarm_10msec);
  printf("Shutdown\r\n");
  ShutdownOS(E_OK);
  TerminateTask();
}
