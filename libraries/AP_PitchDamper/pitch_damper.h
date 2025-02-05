//
// File: pitch_damper.h
//
// Code generated for Simulink model 'pitch_damper'.
//
// Model version                  : 1.1
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Feb  4 04:46:14 2025
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
    real32_T DiscreteTimeIntegrator_DSTATE;// '<Root>/Discrete-Time Integrator'
  };

  // Parameters (default storage)
  struct P_pitch_damper_T {
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

    real32_T uDLookupTable2_tableData[11];
                                 // Computed Parameter: uDLookupTable2_tableData
                                    //  Referenced by: '<Root>/1-D Lookup Table2'

    real32_T uDLookupTable2_bp01Data[11];
                                  // Computed Parameter: uDLookupTable2_bp01Data
                                     //  Referenced by: '<Root>/1-D Lookup Table2'

    real32_T Gain1_Gain;               // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<Root>/Gain1'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<Root>/Gain'

    real32_T Gain_Gain_b;              // Computed Parameter: Gain_Gain_b
                                          //  Referenced by: '<S1>/Gain'

    real32_T uDLookupTable3_tableData[11];
                                 // Computed Parameter: uDLookupTable3_tableData
                                    //  Referenced by: '<Root>/1-D Lookup Table3'

    real32_T uDLookupTable3_bp01Data[11];
                                  // Computed Parameter: uDLookupTable3_bp01Data
                                     //  Referenced by: '<Root>/1-D Lookup Table3'

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

  // Block states
  DW_pitch_damper_T pitch_damper_DW;

  // Tunable parameters
  static P_pitch_damper_T pitch_damper_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_pitch_rate_command, real32_T arg_pitch_rate_body,
            real32_T arg_speed_magnitude, real32_T &arg_elevator_deflection);

  // model terminate function
  static void terminate();

  // Constructor
  pitch_damper();

  // Destructor
  ~pitch_damper();

  // private data and function members
 private:
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
