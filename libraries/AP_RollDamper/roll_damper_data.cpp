//
// File: roll_damper_data.cpp
//
// Code generated for Simulink model 'roll_damper'.
//
// Model version                  : 1.9
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Feb  4 05:53:21 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "roll_damper.h"

// Block parameters (default storage)
roll_damper::P_roll_damper_T roll_damper::roll_damper_P{
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

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<Root>/1-D Lookup Table'

  { 0.75F, 0.2F, 0.18F, 0.15F, 0.115F, 0.05F, 0.03F, 0.02F, 0.0125F, 0.005F,
    0.0025F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table'

  { 25.0F, 50.0F, 100.0F, 160.0F, 170.0F, 200.0F, 250.0F, 275.0F, 290.0F, 350.0F,
    450.0F },

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S1>/Gain'

  57.2957802F,

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<Root>/1-D Lookup Table1'

  { 0.02F, 0.2F, 1.35F, 1.5F, 1.6F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 0.1F },

  // Computed Parameter: uDLookupTable1_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table1'

  { 25.0F, 50.0F, 100.0F, 150.0F, 160.0F, 170.0F, 200.0F, 250.0F, 300.0F, 400.0F,
    450.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
