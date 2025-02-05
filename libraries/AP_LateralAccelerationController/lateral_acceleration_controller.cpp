//
// File: lateral_acceleration_controller.cpp
//
// Code generated for Simulink model 'lateral_acceleration_controller'.
//
// Model version                  : 1.2
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Feb  4 05:04:46 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "lateral_acceleration_controller.h"
#include "rtwtypes.h"

// Model step function
void lateral_acceleration_controller::step(real32_T arg_Ay_cmd, real32_T
  (&arg_Axyz_body)[3], real32_T arg_yaw_rate_body, real32_T
  &arg_yaw_rate_command)
{
  real32_T rtb_Sum;
  real32_T rtb_TSamp;

  // Saturate: '<Root>/Saturation' incorporates:
  //   Inport: '<Root>/Ay_cmd'

  if (arg_Ay_cmd > lateral_acceleration_controll_P.Saturation_UpperSat) {
    rtb_TSamp = lateral_acceleration_controll_P.Saturation_UpperSat;
  } else if (arg_Ay_cmd < lateral_acceleration_controll_P.Saturation_LowerSat) {
    rtb_TSamp = lateral_acceleration_controll_P.Saturation_LowerSat;
  } else {
    rtb_TSamp = arg_Ay_cmd;
  }

  // Sum: '<Root>/Sum' incorporates:
  //   Gain: '<Root>/Gain3'
  //   Inport: '<Root>/Axyz_body'
  //   Inport: '<Root>/yaw_rate_body'
  //   Saturate: '<Root>/Saturation'
  //   Sum: '<Root>/Subtract'

  rtb_Sum = rtb_TSamp - (arg_Axyz_body[1] - arg_yaw_rate_body) *
    lateral_acceleration_controll_P.Gain3_Gain;

  // SampleTimeMath: '<S1>/TSamp' incorporates:
  //   Gain: '<Root>/Kd_lac'
  //
  //  About '<S1>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = lateral_acceleration_controll_P.Kd_lac_Gain * rtb_Sum *
    lateral_acceleration_controll_P.TSamp_WtEt;

  // Outport: '<Root>/yaw_rate_command' incorporates:
  //   Gain: '<Root>/Kp_lac'
  //   Sum: '<Root>/Sum1'
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

  arg_yaw_rate_command = (rtb_TSamp - lateral_acceleration_control_DW.UD_DSTATE)
    + lateral_acceleration_controll_P.Kp_lac_Gain * rtb_Sum;

  // Update for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  lateral_acceleration_control_DW.UD_DSTATE = rtb_TSamp;
}

// Model initialize function
void lateral_acceleration_controller::initialize()
{
  // InitializeConditions for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  lateral_acceleration_control_DW.UD_DSTATE =
    lateral_acceleration_controll_P.DiscreteDerivative_ICPrevScaled;
}

// Model terminate function
void lateral_acceleration_controller::terminate()
{
  // (no terminate code required)
}

// Constructor
lateral_acceleration_controller::lateral_acceleration_controller() :
  lateral_acceleration_control_DW(),
  lateral_acceleration_control_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
lateral_acceleration_controller::~lateral_acceleration_controller() = default;

// Real-Time Model get method
lateral_acceleration_controller::RT_MODEL_lateral_acceleration_T
  * lateral_acceleration_controller::getRTM()
{
  return (&lateral_acceleration_control_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
