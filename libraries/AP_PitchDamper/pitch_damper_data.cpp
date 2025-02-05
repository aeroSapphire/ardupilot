//
// File: pitch_damper_data.cpp
//
// Code generated for Simulink model 'pitch_damper'.
//
// Model version                  : 1.1
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Feb  4 04:46:14 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pitch_damper.h"

// Block parameters (default storage)
pitch_damper::P_pitch_damper_T pitch_damper::pitch_damper_P{
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

  // Computed Parameter: uDLookupTable2_tableData
  //  Referenced by: '<Root>/1-D Lookup Table2'

  { 15.0F, 8.0F, 5.0F, 3.0F, 2.0F, 1.0F, 0.6F, 0.4F, 0.25F, 0.1F, 0.05F },

  // Computed Parameter: uDLookupTable2_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table2'

  { 25.0F, 50.0F, 100.0F, 150.0F, 170.0F, 200.0F, 250.0F, 275.0F, 290.0F, 350.0F,
    450.0F },

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<Root>/Gain1'

  -1.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_b
  //  Referenced by: '<S1>/Gain'

  57.2957802F,

  // Computed Parameter: uDLookupTable3_tableData
  //  Referenced by: '<Root>/1-D Lookup Table3'

  { 0.2F, 60.0F, 50.0F, 50.0F, 50.0F, 50.0F, 40.0F, 25.0F, 25.0F, 25.0F, 1.0F },

  // Computed Parameter: uDLookupTable3_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table3'

  { 25.0F, 50.0F, 100.0F, 150.0F, 160.0F, 170.0F, 200.0F, 250.0F, 300.0F, 400.0F,
    450.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
