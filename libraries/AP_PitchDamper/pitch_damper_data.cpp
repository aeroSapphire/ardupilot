//
// File: pitch_damper_data.cpp
//
// Code generated for Simulink model 'pitch_damper'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Wed Feb  5 04:50:17 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pitch_damper.h"

// Block parameters (default storage)
pitch_damper::P_pitch_damper_T pitch_damper::pitch_damper_P{
  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<Root>/Integrator'

  0.0025F,

  // Computed Parameter: Integrator_IC
  //  Referenced by: '<Root>/Integrator'

  0.0F,

  // Computed Parameter: Integrator_UpperSat
  //  Referenced by: '<Root>/Integrator'

  0.0872664601F,

  // Computed Parameter: Integrator_LowerSat
  //  Referenced by: '<Root>/Integrator'

  -0.0872664601F,

  // Computed Parameter: Kp_tableData
  //  Referenced by: '<Root>/Kp'

  { 0.75F, 1.2F, 0.3F, 0.15F, 0.15F, 0.06F, 0.015F, 0.015F, 0.015F, 0.015F,
    0.015F },

  // Computed Parameter: Kp_bp01Data
  //  Referenced by: '<Root>/Kp'

  { 25.0F, 50.0F, 100.0F, 160.0F, 170.0F, 200.0F, 250.0F, 275.0F, 290.0F, 350.0F,
    450.0F },

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_l
  //  Referenced by: '<S1>/Gain'

  57.2957802F,

  // Computed Parameter: Ki_tableData
  //  Referenced by: '<Root>/Ki'

  { 0.0F, 0.0F, 1.1F, 0.45F, 0.35F, 0.2F, 0.1F, 0.08F, 0.06F, 0.05F, 0.03F },

  // Computed Parameter: Ki_bp01Data
  //  Referenced by: '<Root>/Ki'

  { 25.0F, 50.0F, 100.0F, 150.0F, 160.0F, 170.0F, 200.0F, 250.0F, 300.0F, 400.0F,
    450.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
