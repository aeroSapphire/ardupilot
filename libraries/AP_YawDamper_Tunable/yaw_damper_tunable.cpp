//
// File: yaw_damper_tunable.cpp
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
#include "rtwtypes.h"

// Model step function
void yaw_damper_tunable::step(real32_T arg_yaw_rate_command, real32_T
  arg_yaw_rate_body, real32_T arg_Kp_yaw_damper, real32_T arg_Ki_yaw_damper,
  real32_T arg_Kd_yaw_damper, real32_T &arg_rudder_deflection)
{
  real32_T rtb_Sum1;
  real32_T rtb_TSamp;

  // Sum: '<Root>/Sum1' incorporates:
  //   Inport: '<Root>/yaw_rate_body'
  //   Inport: '<Root>/yaw_rate_command'

  rtb_Sum1 = arg_yaw_rate_command - arg_yaw_rate_body;

  // SampleTimeMath: '<S1>/TSamp' incorporates:
  //   Inport: '<Root>/Kd_yaw_damper'
  //   Product: '<Root>/Product1'
  //
  //  About '<S1>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = rtb_Sum1 * arg_Kd_yaw_damper * yaw_damper_tunable_P.TSamp_WtEt;

  // Outport: '<Root>/outport' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  //   Gain: '<S2>/Gain'
  //   Inport: '<Root>/Kp_yaw_damper'
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

  arg_rudder_deflection = ((rtb_Sum1 * arg_Kp_yaw_damper +
    yaw_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE) + (rtb_TSamp -
    yaw_damper_tunable_DW.UD_DSTATE)) * yaw_damper_tunable_P.Gain_Gain;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/Ki_yaw_damper'
  //   Product: '<Root>/Product2'

  yaw_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE += arg_Ki_yaw_damper *
    rtb_Sum1 * yaw_damper_tunable_P.DiscreteTimeIntegrator_gainval;
  if (yaw_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE >=
      yaw_damper_tunable_P.DiscreteTimeIntegrator_UpperSat) {
    yaw_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE =
      yaw_damper_tunable_P.DiscreteTimeIntegrator_UpperSat;
  } else if (yaw_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE <=
             yaw_damper_tunable_P.DiscreteTimeIntegrator_LowerSat) {
    yaw_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE =
      yaw_damper_tunable_P.DiscreteTimeIntegrator_LowerSat;
  }

  // End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  yaw_damper_tunable_DW.UD_DSTATE = rtb_TSamp;
}

// Model initialize function
void yaw_damper_tunable::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  yaw_damper_tunable_DW.DiscreteTimeIntegrator_DSTATE =
    yaw_damper_tunable_P.DiscreteTimeIntegrator_IC;

  // InitializeConditions for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  yaw_damper_tunable_DW.UD_DSTATE =
    yaw_damper_tunable_P.DiscreteDerivative_ICPrevScaled;
}

// Model terminate function
void yaw_damper_tunable::terminate()
{
  // (no terminate code required)
}

// Constructor
yaw_damper_tunable::yaw_damper_tunable() :
  yaw_damper_tunable_DW(),
  yaw_damper_tunable_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
yaw_damper_tunable::~yaw_damper_tunable() = default;

// Real-Time Model get method
yaw_damper_tunable::RT_MODEL_yaw_damper_tunable_T * yaw_damper_tunable::getRTM()
{
  return (&yaw_damper_tunable_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
