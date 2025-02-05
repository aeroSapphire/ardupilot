//
// File: normal_acceleration_controller_data.cpp
//
// Code generated for Simulink model 'normal_acceleration_controller'.
//
// Model version                  : 1.5
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Feb  4 05:42:14 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "normal_acceleration_controller.h"

// Block parameters (default storage)
normal_acceleration_controller::P_normal_acceleration_control_T
  normal_acceleration_controller::normal_acceleration_controlle_P{
  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0025F,

  // Computed Parameter: DiscreteTimeIntegrator_IC
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0F,

  // Computed Parameter: DiscreteTimeIntegrator_UpperSat
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.122173049F,

  // Computed Parameter: DiscreteTimeIntegrator_LowerSat
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  -0.122173049F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<Root>/Saturation'

  60.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<Root>/Saturation'

  -60.0F,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<Root>/Constant'

  -9.81F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<Root>/Gain3'

  1.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  -0.07F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<Root>/Gain1'

  -0.03F
};

//
// File trailer for generated code.
//
// [EOF]
//
