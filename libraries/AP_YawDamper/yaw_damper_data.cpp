//
// File: yaw_damper_data.cpp
//
// Code generated for Simulink model 'yaw_damper'.
//
// Model version                  : 1.6
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Wed Feb  5 21:48:25 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "yaw_damper.h"

// Block parameters (default storage)
yaw_damper::P_yaw_damper_T yaw_damper::yaw_damper_P{
  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0025F,

  // Computed Parameter: DiscreteTimeIntegrator_IC
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0F,

  // Computed Parameter: DiscreteTimeIntegrator_UpperSat
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0329F,

  // Computed Parameter: DiscreteTimeIntegrator_LowerSat
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  -0.0329F,

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<Root>/1-D Lookup Table'

  { 0.07F, 0.15F, 0.23F, 0.25F, 0.25F, 0.23F, 0.15F, 0.1F, 0.03F, 0.01F, 0.0025F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table'

  { 25.0F, 50.0F, 100.0F, 160.0F, 170.0F, 200.0F, 250.0F, 275.0F, 290.0F, 350.0F,
    450.0F },

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<Root>/Gain2'

  0.15F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  1.0F,

  // Computed Parameter: Gain_Gain_b
  //  Referenced by: '<S1>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<Root>/Saturation'

  10.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<Root>/Saturation'

  -10.0F,

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<Root>/1-D Lookup Table1'

  { 0.0F, 0.1F, 0.1F, 0.25F, 0.30F, 0.20F, 0.10F, 0.08F, 0.05F, 0.02F, 0.0F },

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
