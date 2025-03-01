//
// File: ert_main.cpp
//
// Code generated for Simulink model 'roll_damper_tunable'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Feb  3 23:15:23 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stdio.h>              // This example main program uses printf/fflush
#include "roll_damper_tunable.h"       // Model header file

static roll_damper_tunable roll_damper_tunable_Obj;// Instance of model class

// '<Root>/roll_rate_command'
static real32_T arg_roll_rate_command{ 0.0F };

// '<Root>/roll_rate'
static real32_T arg_roll_rate{ 0.0F };

// '<Root>/Kp_roll_damper'
static real32_T arg_Kp_roll_damper{ 0.0F };

// '<Root>/Ki_roll_damper'
static real32_T arg_Ki_roll_damper{ 0.0F };

// '<Root>/Kd_roll_damper'
static real32_T arg_Kd_roll_damper{ 0.0F };

// '<Root>/aileron_deflection'
static real32_T arg_aileron_deflection;

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag{ false };

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(roll_damper_tunable_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  roll_damper_tunable_Obj.step(arg_roll_rate_command, arg_roll_rate,
    arg_Kp_roll_damper, arg_Ki_roll_damper, arg_Kd_roll_damper,
    &arg_aileron_deflection);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example main function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific. This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Initialize model
  roll_damper_tunable_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.0025 seconds (base rate of the model) here.
  //  The call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((nullptr));
  while (rtmGetErrorStatus(roll_damper_tunable_Obj.getRTM()) == (nullptr)) {
    //  Perform application tasks here
  }

  // Terminate model
  roll_damper_tunable_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
