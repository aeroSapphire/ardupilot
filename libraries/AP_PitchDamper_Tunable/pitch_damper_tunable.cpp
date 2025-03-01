//
// File: pitch_damper_tunable.cpp
//
// Code generated for Simulink model 'pitch_damper_tunable'.
//
// Model version                  : 1.6
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Feb  3 23:46:22 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pitch_damper_tunable.h"
#include "rtwtypes.h"

// Model step function
void pitch_damper_tunable::step(real32_T arg_pitch_rate_command, real32_T
  arg_pitch_rate, real32_T arg_Kp_pitch_damper, real32_T arg_Ki_pitch_damper,
  real32_T arg_Kd_pitch_damper, real32_T &arg_elevator_deflection)
{
  real32_T rtb_Sum1;
  real32_T rtb_TSamp;

  // Sum: '<Root>/Sum1' incorporates:
  //   Inport: '<Root>/pitch_rate'
  //   Inport: '<Root>/pitch_rate_command'

  rtb_Sum1 = arg_pitch_rate_command - arg_pitch_rate;

  // SampleTimeMath: '<S1>/TSamp' incorporates:
  //   Inport: '<Root>/Kd_pitch_damper'
  //   Product: '<Root>/Product1'
  //
  //  About '<S1>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = arg_Kd_pitch_damper * rtb_Sum1 * pitch_damper_tunable_P.TSamp_WtEt;

  // Outport: '<Root>/elevator_deflection' incorporates:
  //   DiscreteIntegrator: '<Root>/Integrator'
  //   Gain: '<Root>/Gain'
  //   Gain: '<S2>/Gain'
  //   Inport: '<Root>/Kp_pitch_damper'
  //   Product: '<Root>/Product3'
  //   Sum: '<Root>/Sum'
  //   Sum: '<S1>/Diff'
  //   UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  arg_elevator_deflection = ((rtb_Sum1 * arg_Kp_pitch_damper +
    pitch_damper_tunable_DW.Integrator_DSTATE) + (rtb_TSamp -
    pitch_damper_tunable_DW.UD_DSTATE)) * pitch_damper_tunable_P.Gain_Gain *
    pitch_damper_tunable_P.Gain_Gain_l;

  // Update for DiscreteIntegrator: '<Root>/Integrator' incorporates:
  //   Inport: '<Root>/Ki_pitch_damper'
  //   Product: '<Root>/Product2'

  pitch_damper_tunable_DW.Integrator_DSTATE += arg_Ki_pitch_damper * rtb_Sum1 *
    pitch_damper_tunable_P.Integrator_gainval;
  if (pitch_damper_tunable_DW.Integrator_DSTATE >=
      pitch_damper_tunable_P.Integrator_UpperSat) {
    pitch_damper_tunable_DW.Integrator_DSTATE =
      pitch_damper_tunable_P.Integrator_UpperSat;
  } else if (pitch_damper_tunable_DW.Integrator_DSTATE <=
             pitch_damper_tunable_P.Integrator_LowerSat) {
    pitch_damper_tunable_DW.Integrator_DSTATE =
      pitch_damper_tunable_P.Integrator_LowerSat;
  }

  // End of Update for DiscreteIntegrator: '<Root>/Integrator'

  // Update for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  pitch_damper_tunable_DW.UD_DSTATE = rtb_TSamp;
}

// Model initialize function
void pitch_damper_tunable::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<Root>/Integrator'
  pitch_damper_tunable_DW.Integrator_DSTATE =
    pitch_damper_tunable_P.Integrator_IC;

  // InitializeConditions for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  pitch_damper_tunable_DW.UD_DSTATE =
    pitch_damper_tunable_P.DiscreteDerivative_ICPrevScaled;
}

// Model terminate function
void pitch_damper_tunable::terminate()
{
  // (no terminate code required)
}

// Constructor
pitch_damper_tunable::pitch_damper_tunable() :
  pitch_damper_tunable_DW(),
  pitch_damper_tunable_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
pitch_damper_tunable::~pitch_damper_tunable() = default;

// Real-Time Model get method
pitch_damper_tunable::RT_MODEL_pitch_damper_tunable_T * pitch_damper_tunable::
  getRTM()
{
  return (&pitch_damper_tunable_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
