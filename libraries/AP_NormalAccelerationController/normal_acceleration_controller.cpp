//
// File: normal_acceleration_controller.cpp
//
// Code generated for Simulink model 'normal_acceleration_controller'.
//
// Model version                  : 1.5
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Feb  4 05:42:14 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "normal_acceleration_controller.h"
#include "rtwtypes.h"

// Model step function
void normal_acceleration_controller::step(real32_T arg_Az_cmd, real32_T
  (&arg_Axyz_body)[3], real32_T &arg_pitch_rate_command)
{
  real32_T rtb_Sum;

  // Saturate: '<Root>/Saturation' incorporates:
  //   Inport: '<Root>/Az_cmd'

  if (arg_Az_cmd > normal_acceleration_controlle_P.Saturation_UpperSat) {
    rtb_Sum = normal_acceleration_controlle_P.Saturation_UpperSat;
  } else if (arg_Az_cmd < normal_acceleration_controlle_P.Saturation_LowerSat) {
    rtb_Sum = normal_acceleration_controlle_P.Saturation_LowerSat;
  } else {
    rtb_Sum = arg_Az_cmd;
  }

  // Sum: '<Root>/Sum' incorporates:
  //   Constant: '<Root>/Constant'
  //   Gain: '<Root>/Gain3'
  //   Inport: '<Root>/Axyz_body'
  //   Saturate: '<Root>/Saturation'
  //   Sum: '<Root>/Subtract'

  rtb_Sum -= (arg_Axyz_body[2] - normal_acceleration_controlle_P.Constant_Value)
    * normal_acceleration_controlle_P.Gain3_Gain;

  // Outport: '<Root>/pitch_rate_command' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  //   Gain: '<Root>/Gain'
  //   Sum: '<Root>/Sum1'

  arg_pitch_rate_command = normal_acceleration_controlle_P.Gain_Gain * rtb_Sum +
    normal_acceleration_controll_DW.DiscreteTimeIntegrator_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Gain: '<Root>/Gain1'

  normal_acceleration_controll_DW.DiscreteTimeIntegrator_DSTATE +=
    normal_acceleration_controlle_P.Gain1_Gain * rtb_Sum *
    normal_acceleration_controlle_P.DiscreteTimeIntegrator_gainval;
  if (normal_acceleration_controll_DW.DiscreteTimeIntegrator_DSTATE >=
      normal_acceleration_controlle_P.DiscreteTimeIntegrator_UpperSat) {
    normal_acceleration_controll_DW.DiscreteTimeIntegrator_DSTATE =
      normal_acceleration_controlle_P.DiscreteTimeIntegrator_UpperSat;
  } else if (normal_acceleration_controll_DW.DiscreteTimeIntegrator_DSTATE <=
             normal_acceleration_controlle_P.DiscreteTimeIntegrator_LowerSat) {
    normal_acceleration_controll_DW.DiscreteTimeIntegrator_DSTATE =
      normal_acceleration_controlle_P.DiscreteTimeIntegrator_LowerSat;
  }

  // End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
}

// Model initialize function
void normal_acceleration_controller::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  normal_acceleration_controll_DW.DiscreteTimeIntegrator_DSTATE =
    normal_acceleration_controlle_P.DiscreteTimeIntegrator_IC;
}

// Model terminate function
void normal_acceleration_controller::terminate()
{
  // (no terminate code required)
}

// Constructor
normal_acceleration_controller::normal_acceleration_controller() :
  normal_acceleration_controll_DW(),
  normal_acceleration_controll_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
normal_acceleration_controller::~normal_acceleration_controller() = default;

// Real-Time Model get method
normal_acceleration_controller::RT_MODEL_normal_acceleration__T
  * normal_acceleration_controller::getRTM()
{
  return (&normal_acceleration_controll_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
