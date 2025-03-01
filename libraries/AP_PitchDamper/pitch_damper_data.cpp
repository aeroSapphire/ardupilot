//
// File: pitch_damper_data.cpp
//
// Code generated for Simulink model 'pitch_damper'.
//
// Model version                  : 1.12
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Feb 17 21:04:45 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pitch_damper.h"

// Block parameters (default storage)
pitch_damper::P_pitch_damper_T pitch_damper::pitch_damper_P{
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S1>/UD'

  0.0F,

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

  // Computed Parameter: KP_Lookup
  //  Referenced by: '<Root>/1-D Lookup Table2'

  { 0.5F, 0.3F, 0.1F, 0.04F, 0.05F, 0.04F, 0.0001F, 7.0E-5F, 3.0E-5F, 2.0E-5F,
    1.0E-5F },

  // Computed Parameter: KP_Lookup Speed
  //  Referenced by: '<Root>/1-D Lookup Table2'

  { 25.0F, 50.0F, 100.0F, 150.0F, 160.0F, 170.0F, 200.0F, 250.0F, 300.0F, 400.0F,
    450.0F },

  // Computed Parameter: KD_Lookup
  //  Referenced by: '<Root>/1-D Lookup Table1'

  { 0.01F, 0.0005F, 0.00007F, 0.00001F },

  // Computed Parameter: KD_Lookup Speed
  //  Referenced by: '<Root>/1-D Lookup Table1'

  { 25.0F, 200.0F, 350.0F, 450.0F },

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S1>/TSamp'

  400.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_b
  //  Referenced by: '<S2>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<Root>/Saturation'

  10.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<Root>/Saturation'

  -10.0F,

  // Computed Parameter: KI_Lookup
  //  Referenced by: '<Root>/1-D Lookup Table3'

  { 0.0F, 0.1F, 0.25F, 0.5F, 0.4F, 0.2F, 0.075F, 0.015F, 0.005F, 0.0025F, 0.0F },

  // Computed Parameter: KI_Lookup Speed
  //  Referenced by: '<Root>/1-D Lookup Table3'

  { 25.0F, 50.0F, 100.0F, 150.0F, 160.0F, 170.0F, 200.0F, 250.0F, 300.0F, 400.0F,
    450.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
