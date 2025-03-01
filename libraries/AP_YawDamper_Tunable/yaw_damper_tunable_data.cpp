//
// File: yaw_damper_tunable_data.cpp
//
// Code generated for Simulink model 'yaw_damper_tunable'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Feb  3 23:52:56 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "yaw_damper_tunable.h"

// Block parameters (default storage)
yaw_damper_tunable::P_yaw_damper_tunable_T yaw_damper_tunable::
  yaw_damper_tunable_P{
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S1>/UD'

  0.0F,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0025F,

  // Computed Parameter: DiscreteTimeIntegrator_IC
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0F,

  // Computed Parameter: DiscreteTimeIntegrator_UpperSat
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0872664601F,

  // Computed Parameter: DiscreteTimeIntegrator_LowerSat
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  -0.0872664601F,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S1>/TSamp'

  400.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S2>/Gain'

  57.2957802F
};

//
// File trailer for generated code.
//
// [EOF]
//
