//
// File: yaw_damper_data.cpp
//
// Code generated for Simulink model 'yaw_damper'.
//
// Model version                  : 1.1
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Feb  4 04:53:29 2025
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

  0.122173049F,

  // Computed Parameter: DiscreteTimeIntegrator_LowerSat
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  -0.122173049F,

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<Root>/1-D Lookup Table'

  { -7.5F, -7.0F, -6.0F, -3.5F, -3.0F, -2.0F, -1.0F, -0.2F, -0.1875F, -0.2F,
    -0.2F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<Root>/1-D Lookup Table'

  { 25.0F, 50.0F, 100.0F, 160.0F, 170.0F, 200.0F, 250.0F, 275.0F, 290.0F, 350.0F,
    450.0F },

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S1>/Gain'

  57.2957802F,

  // Computed Parameter: uDLookupTable1_tableData
  //  Referenced by: '<Root>/1-D Lookup Table1'

  { 0.2F, 2.0F, 25.0F, 50.0F, 50.0F, 50.0F, 50.0F, 40.0F, 25.0F, 25.0F, 1.0F },

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
