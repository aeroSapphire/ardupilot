//
// File: pitch_damper_tunable.h
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
#ifndef RTW_HEADER_pitch_damper_tunable_h_
#define RTW_HEADER_pitch_damper_tunable_h_
#include "rtwtypes.h"
#include "pitch_damper_tunable_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model pitch_damper_tunable
class pitch_damper_tunable final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_pitch_damper_tunable_T {
    real32_T Integrator_DSTATE;        // '<Root>/Integrator'
    real32_T UD_DSTATE;                // '<S1>/UD'
  };

  // Parameters (default storage)
  struct P_pitch_damper_tunable_T {
    real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S1>/UD'

    real32_T Integrator_gainval;       // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<Root>/Integrator'

    real32_T Integrator_IC;            // Computed Parameter: Integrator_IC
                                          //  Referenced by: '<Root>/Integrator'

    real32_T Integrator_UpperSat;     // Computed Parameter: Integrator_UpperSat
                                         //  Referenced by: '<Root>/Integrator'

    real32_T Integrator_LowerSat;     // Computed Parameter: Integrator_LowerSat
                                         //  Referenced by: '<Root>/Integrator'

    real32_T TSamp_WtEt;               // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S1>/TSamp'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<Root>/Gain'

    real32_T Gain_Gain_l;              // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S2>/Gain'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_pitch_damper_tunable_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  pitch_damper_tunable(pitch_damper_tunable const&) = delete;

  // Assignment Operator
  pitch_damper_tunable& operator= (pitch_damper_tunable const&) & = delete;

  // Move Constructor
  pitch_damper_tunable(pitch_damper_tunable &&) = delete;

  // Move Assignment Operator
  pitch_damper_tunable& operator= (pitch_damper_tunable &&) = delete;

  // Real-Time Model get method
  pitch_damper_tunable::RT_MODEL_pitch_damper_tunable_T * getRTM();

  // Block states
  DW_pitch_damper_tunable_T pitch_damper_tunable_DW;

  // Tunable parameters
  static P_pitch_damper_tunable_T pitch_damper_tunable_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_pitch_rate_command, real32_T arg_pitch_rate, real32_T
            arg_Kp_pitch_damper, real32_T arg_Ki_pitch_damper, real32_T
            arg_Kd_pitch_damper, real32_T &arg_elevator_deflection);

  // model terminate function
  static void terminate();

  // Constructor
  pitch_damper_tunable();

  // Destructor
  ~pitch_damper_tunable();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_pitch_damper_tunable_T pitch_damper_tunable_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Data Type Duplicate' : Unused code path elimination


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
//  '<Root>' : 'pitch_damper_tunable'
//  '<S1>'   : 'pitch_damper_tunable/Discrete Derivative'
//  '<S2>'   : 'pitch_damper_tunable/Radians to Degrees'

#endif                                 // RTW_HEADER_pitch_damper_tunable_h_

//
// File trailer for generated code.
//
// [EOF]
//
