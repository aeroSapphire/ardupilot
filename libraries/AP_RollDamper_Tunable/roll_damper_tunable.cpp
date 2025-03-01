//
// File: roll_damper_tunable.cpp
//
// Code generated for Simulink model 'roll_damper_tunable'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Feb  3 23:15:23 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "roll_damper_tunable.h"
#include "rtwtypes.h"

// Model step function
void roll_damper_tunable::step(real32_T arg_roll_rate_command, real32_T
  arg_roll_rate, real32_T arg_Kp_roll_damper, real32_T arg_Ki_roll_damper,
  real32_T arg_Kd_roll_damper, real32_T *arg_aileron_deflection)
{
  real32_T rtb_Error;
  real32_T rtb_TSamp;

  // Sum: '<Root>/Error' incorporates:
  //   Inport: '<Root>/roll_rate'
  //   Inport: '<Root>/roll_rate_command'

  rtb_Error = arg_roll_rate_command - arg_roll_rate;

  // SampleTimeMath: '<S1>/TSamp' incorporates:
  //   Inport: '<Root>/Kd_roll_damper'
  //   Product: '<Root>/Product1'
  //
  //  About '<S1>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = arg_Kd_roll_damper * rtb_Error * roll_damper_tunable_P.TSamp_WtEt;

  // Outport: '<Root>/aileron_deflection' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  //   Gain: '<Root>/Gain'
  //   Gain: '<S2>/Gain'
  //   Inport: '<Root>/Kp_roll_damper'
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

  *arg_aileron_deflection = ((arg_Kp_roll_damper * rtb_Error +
    roll_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE) + (rtb_TSamp -
    roll_damper_tunable_DW.UD_DSTATE)) * roll_damper_tunable_P.Gain_Gain *
    roll_damper_tunable_P.Gain_Gain_b;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/Ki_roll_damper'
  //   Product: '<Root>/Product2'

  roll_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE += arg_Ki_roll_damper *
    rtb_Error * roll_damper_tunable_P.DiscreteTimeIntegrator_gainval;
  if (roll_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE >=
      roll_damper_tunable_P.DiscreteTimeIntegrator_UpperSat) {
    roll_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE =
      roll_damper_tunable_P.DiscreteTimeIntegrator_UpperSat;
  } else if (roll_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE <=
             roll_damper_tunable_P.DiscreteTimeIntegrator_LowerSat) {
    roll_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE =
      roll_damper_tunable_P.DiscreteTimeIntegrator_LowerSat;
  }

  // End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  roll_damper_tunable_DW.UD_DSTATE = rtb_TSamp;
}

// Model initialize function
void roll_damper_tunable::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  roll_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE =
    roll_damper_tunable_P.DiscreteTimeIntegrator_IC;

  // InitializeConditions for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  roll_damper_tunable_DW.UD_DSTATE =
    roll_damper_tunable_P.DiscreteDerivative_ICPrevScaled;
}

// Model terminate function
void roll_damper_tunable::terminate()
{
  // (no terminate code required)
}

// Constructor
roll_damper_tunable::roll_damper_tunable() :
  roll_damper_tunable_DW(),
  roll_damper_tunable_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
roll_damper_tunable::~roll_damper_tunable() = default;

// Real-Time Model get method
roll_damper_tunable::RT_MODEL_roll_damper_tunable_T * roll_damper_tunable::
  getRTM()
{
  return (&roll_damper_tunable_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
