//
// File: normal_acceleration_controller.h
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
#ifndef RTW_HEADER_normal_acceleration_controller_h_
#define RTW_HEADER_normal_acceleration_controller_h_
#include "rtwtypes.h"
#include "normal_acceleration_controller_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model normal_acceleration_controller
class normal_acceleration_controller final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_normal_acceleration_contro_T {
    real32_T DiscreteTimeIntegrator_DSTATE;// '<Root>/Discrete-Time Integrator'
  };

  // Parameters (default storage)
  struct P_normal_acceleration_control_T {
    real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<Root>/Discrete-Time Integrator'

    real32_T DiscreteTimeIntegrator_IC;
                                // Computed Parameter: DiscreteTimeIntegrator_IC
                                   //  Referenced by: '<Root>/Discrete-Time Integrator'

    real32_T DiscreteTimeIntegrator_UpperSat;
                          // Computed Parameter: DiscreteTimeIntegrator_UpperSat
                             //  Referenced by: '<Root>/Discrete-Time Integrator'

    real32_T DiscreteTimeIntegrator_LowerSat;
                          // Computed Parameter: DiscreteTimeIntegrator_LowerSat
                             //  Referenced by: '<Root>/Discrete-Time Integrator'

    real32_T Saturation_UpperSat;     // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<Root>/Saturation'

    real32_T Saturation_LowerSat;     // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<Root>/Saturation'

    real32_T Constant_Value;           // Computed Parameter: Constant_Value
                                          //  Referenced by: '<Root>/Constant'

    real32_T Gain3_Gain;               // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<Root>/Gain3'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<Root>/Gain'

    real32_T Gain1_Gain;               // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<Root>/Gain1'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_normal_acceleration__T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  normal_acceleration_controller(normal_acceleration_controller const&) = delete;

  // Assignment Operator
  normal_acceleration_controller& operator= (normal_acceleration_controller
    const&) & = delete;

  // Move Constructor
  normal_acceleration_controller(normal_acceleration_controller &&) = delete;

  // Move Assignment Operator
  normal_acceleration_controller& operator= (normal_acceleration_controller &&) =
    delete;

  // Real-Time Model get method
  normal_acceleration_controller::RT_MODEL_normal_acceleration__T * getRTM();

  // Block states
  DW_normal_acceleration_contro_T normal_acceleration_controll_DW;

  // Tunable parameters
  static P_normal_acceleration_control_T normal_acceleration_controlle_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_Az_cmd, real32_T (&arg_Axyz_body)[3], real32_T
            &arg_pitch_rate_command);

  // model terminate function
  static void terminate();

  // Constructor
  normal_acceleration_controller();

  // Destructor
  ~normal_acceleration_controller();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_normal_acceleration__T normal_acceleration_controll_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'normal_acceleration_controller'

#endif                          // RTW_HEADER_normal_acceleration_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
