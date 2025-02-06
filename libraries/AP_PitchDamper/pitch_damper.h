//
// File: pitch_damper.h
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
#ifndef RTW_HEADER_pitch_damper_h_
#define RTW_HEADER_pitch_damper_h_
#include "rtwtypes.h"
#include "pitch_damper_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model pitch_damper
class pitch_damper final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_pitch_damper_T {
    real32_T Integrator_DSTATE;        // '<Root>/Integrator'
  };

  // Parameters (default storage)
  struct P_pitch_damper_T {
    real32_T Integrator_gainval;       // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<Root>/Integrator'

    real32_T Integrator_IC;            // Computed Parameter: Integrator_IC
                                          //  Referenced by: '<Root>/Integrator'

    real32_T Integrator_UpperSat;     // Computed Parameter: Integrator_UpperSat
                                         //  Referenced by: '<Root>/Integrator'

    real32_T Integrator_LowerSat;     // Computed Parameter: Integrator_LowerSat
                                         //  Referenced by: '<Root>/Integrator'

    real32_T Kp_tableData[11];         // Computed Parameter: Kp_tableData
                                          //  Referenced by: '<Root>/Kp'

    real32_T Kp_bp01Data[11];          // Computed Parameter: Kp_bp01Data
                                          //  Referenced by: '<Root>/Kp'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<Root>/Gain'

    real32_T Gain_Gain_l;              // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S1>/Gain'

    real32_T Ki_tableData[11];         // Computed Parameter: Ki_tableData
                                          //  Referenced by: '<Root>/Ki'

    real32_T Ki_bp01Data[11];          // Computed Parameter: Ki_bp01Data
                                          //  Referenced by: '<Root>/Ki'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_pitch_damper_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  pitch_damper(pitch_damper const&) = delete;

  // Assignment Operator
  pitch_damper& operator= (pitch_damper const&) & = delete;

  // Move Constructor
  pitch_damper(pitch_damper &&) = delete;

  // Move Assignment Operator
  pitch_damper& operator= (pitch_damper &&) = delete;

  // Real-Time Model get method
  pitch_damper::RT_MODEL_pitch_damper_T * getRTM();

  // Tunable parameters
  static P_pitch_damper_T pitch_damper_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_pitch_rate_command, real32_T arg_pitch_rate, real32_T
            arg_speed_magnitude, real32_T &arg_elevator_deflection);

  // model terminate function
  static void terminate();

  // Constructor
  pitch_damper();

  // Destructor
  ~pitch_damper();

  // private data and function members
 private:
  // Block states
  DW_pitch_damper_T pitch_damper_DW;

  // Real-Time Model
  RT_MODEL_pitch_damper_T pitch_damper_M;
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
//  '<Root>' : 'pitch_damper'
//  '<S1>'   : 'pitch_damper/Radians to Degrees'

#endif                                 // RTW_HEADER_pitch_damper_h_

//
// File trailer for generated code.
//
// [EOF]
//
