//
// File: pitch_damper.cpp
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
#include "rtwtypes.h"
#include "pitch_damper_private.h"

real32_T look1_iflf_binlxpw_pd(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T yL_0d0;
  uint32_T iLeft;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

// Model step function
void pitch_damper::step(real32_T arg_pitch_rate_command, real32_T arg_pitch_rate,
  real32_T arg_speed_magnitude, real32_T &arg_elevator_deflection)
{
  // Outport: '<Root>/elevator_deflection' incorporates:
  //   DiscreteIntegrator: '<Root>/Integrator'
  //   Gain: '<Root>/Gain'
  //   Gain: '<S1>/Gain'
  //   Inport: '<Root>/pitch_rate'
  //   Inport: '<Root>/speed_magnitude'
  //   Lookup_n-D: '<Root>/Kp'
  //   Product: '<Root>/Product1'
  //   Sum: '<Root>/Sum'

  arg_elevator_deflection = (pitch_damper_DW.Integrator_DSTATE - arg_pitch_rate *
    look1_iflf_binlxpw_pd(arg_speed_magnitude, pitch_damper_P.Kp_bp01Data,
                       pitch_damper_P.Kp_tableData, 10U)) *
    pitch_damper_P.Gain_Gain * pitch_damper_P.Gain_Gain_l;

  // Update for DiscreteIntegrator: '<Root>/Integrator' incorporates:
  //   Inport: '<Root>/pitch_rate'
  //   Inport: '<Root>/pitch_rate_command'
  //   Inport: '<Root>/speed_magnitude'
  //   Lookup_n-D: '<Root>/Ki'
  //   Product: '<Root>/Product2'
  //   Sum: '<Root>/Sum1'

  pitch_damper_DW.Integrator_DSTATE += (arg_pitch_rate_command - arg_pitch_rate)
    * look1_iflf_binlxpw_pd(arg_speed_magnitude, pitch_damper_P.Ki_bp01Data,
    pitch_damper_P.Ki_tableData, 10U) * pitch_damper_P.Integrator_gainval;
  if (pitch_damper_DW.Integrator_DSTATE >= pitch_damper_P.Integrator_UpperSat) {
    pitch_damper_DW.Integrator_DSTATE = pitch_damper_P.Integrator_UpperSat;
  } else if (pitch_damper_DW.Integrator_DSTATE <=
             pitch_damper_P.Integrator_LowerSat) {
    pitch_damper_DW.Integrator_DSTATE = pitch_damper_P.Integrator_LowerSat;
  }

  // End of Update for DiscreteIntegrator: '<Root>/Integrator'
}

// Model initialize function
void pitch_damper::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<Root>/Integrator'
  pitch_damper_DW.Integrator_DSTATE = pitch_damper_P.Integrator_IC;
}

// Model terminate function
void pitch_damper::terminate()
{
  // (no terminate code required)
}

// Constructor
pitch_damper::pitch_damper() :
  pitch_damper_DW(),
  pitch_damper_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
pitch_damper::~pitch_damper() = default;

// Real-Time Model get method
pitch_damper::RT_MODEL_pitch_damper_T * pitch_damper::getRTM()
{
  return (&pitch_damper_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
