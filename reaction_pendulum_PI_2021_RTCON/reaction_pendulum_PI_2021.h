/*
 * reaction_pendulum_PI_2021.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "reaction_pendulum_PI_2021".
 *
 * Model version              : 7.0
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Sep 29 14:10:17 2022
 *
 * Target selection: rtcon_rpend_usb2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_reaction_pendulum_PI_2021_h_
#define RTW_HEADER_reaction_pendulum_PI_2021_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef reaction_pendulum_PI_2021_COMMON_INCLUDES_
#define reaction_pendulum_PI_2021_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                          /* reaction_pendulum_PI_2021_COMMON_INCLUDES_ */

#include "reaction_pendulum_PI_2021_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Control;                      /* '<Root>/Manual Switch' */
  real_T Saturation;                   /* '<S3>/Saturation' */
  real_T Gain[2];                      /* '<S3>/Gain' */
  real_T Prescaler;                    /* '<S3>/Prescaler' */
  real_T ThermFlag;                    /* '<S3>/ThermFlag' */
  real_T SFunction_o1;                 /* '<S3>/S-Function' */
  real_T SFunction_o2;                 /* '<S3>/S-Function' */
  real_T SFunction_o3;                 /* '<S3>/S-Function' */
  real_T SFunction_o4;                 /* '<S3>/S-Function' */
  real_T SFunction_o5;                 /* '<S3>/S-Function' */
  real_T SFunction_o6;                 /* '<S3>/S-Function' */
  real_T SFunction_o7[2];              /* '<S3>/S-Function' */
  real_T PendulumAnglerad;             /* '<S3>/Pendulum Convert to rad' */
  real_T Periodms;                     /* '<S3>/Gain1' */
  real_T DCVelrads;                    /* '<S3>/Divide' */
  real_T DCConverttoA1;                /* '<S3>/DC Convert to [A]1' */
  real_T Product1;                     /* '<Root>/Product1' */
  real_T TmpSignalConversionAtToWorkspac[2];
} B_reaction_pendulum_PI_2021_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Integrator_DSTATE;            /* '<S35>/Integrator' */
  real_T Memory1_PreviousInput;        /* '<S3>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S3>/Memory' */
  struct {
    void *LoggedData[4];
  } PlotState_PWORK;                   /* '<Root>/PlotState' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */
} DW_reaction_pendulum_PI_2021_T;

/* Parameters (default storage) */
struct P_reaction_pendulum_PI_2021_T_ {
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T h;                            /* Variable: h
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S32>/Integral Gain'
                                       */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S35>/Integrator'
                               */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S40>/Proportional Gain'
                                       */
  real_T Constant1_Value;              /* Expression: pi
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T Normal_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  real_T DC_Ctrl1_Value;               /* Expression: pi
                                        * Referenced by: '<Root>/DC_Ctrl1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S35>/Integrator'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain_Gain[2];                 /* Expression: [1;1]
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Prescaler_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Prescaler'
                                        */
  real_T ThermFlag_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/ThermFlag'
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: 1
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T PendulumConverttorad_Gain;    /* Expression: 2*pi/20000
                                        * Referenced by: '<S3>/Pendulum Convert to rad'
                                        */
  real_T DCConverttorad_Gain;          /* Expression: 2*pi/4096
                                        * Referenced by: '<S3>/DC Convert to rad'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory1'
                                        */
  real_T rad2RPM_Gain;                 /* Expression: 1
                                        * Referenced by: '<S3>/rad2RPM'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/20000000
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T DCConverttoA1_Gain;           /* Expression: 0.8333
                                        * Referenced by: '<S3>/DC Convert to [A]1'
                                        */
  real_T Constant2_Value;              /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant2'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ResetEncoders_CurrentSetting;
                             /* Computed Parameter: ResetEncoders_CurrentSetting
                              * Referenced by: '<Root>/Reset Encoders'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_reaction_pendulum_PI_2021_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssSFcnModelMethods4 methods4[1];
    struct _ssStatesInfo2 statesInfo2[1];
    ssPeriodicStatesInfo periodicStatesInfo[1];
    struct _ssPortInfo2 inputOutputPortInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      struct _ssInPortUnit inputPortUnits[4];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[4];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[7];
      struct _ssOutPortUnit outputPortUnits[7];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[7];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_reaction_pendulum_PI_2021_T reaction_pendulum_PI_2021_P;

/* Block signals (default storage) */
extern B_reaction_pendulum_PI_2021_T reaction_pendulum_PI_2021_B;

/* Block states (default storage) */
extern DW_reaction_pendulum_PI_2021_T reaction_pendulum_PI_2021_DW;

/* Model entry point functions */
extern void reaction_pendulum_PI_2021_initialize(void);
extern void reaction_pendulum_PI_2021_step(void);
extern void reaction_pendulum_PI_2021_terminate(void);

/* Real-time Model object */
extern RT_MODEL_reaction_pendulum_PI_2021_T *const reaction_pendulum_PI_2021_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'reaction_pendulum_PI_2021'
 * '<S1>'   : 'reaction_pendulum_PI_2021/Chirp Signal'
 * '<S2>'   : 'reaction_pendulum_PI_2021/Discrete PID Controller'
 * '<S3>'   : 'reaction_pendulum_PI_2021/RP Driver'
 * '<S4>'   : 'reaction_pendulum_PI_2021/Discrete PID Controller/Anti-windup'
 * '<S5>'   : 'reaction_pendulum_PI_2021/Discrete PID Controller/D Gain'
 * '<S6>'   : 'reaction_pendulum_PI_2021/Discrete PID Controller/Filter'
 * '<S7>'   : 'reaction_pendulum_PI_2021/Discrete PID Controller/Filter ICs'
 * '<S8>'   : 'reaction_pendulum_PI_2021/Discrete PID Controller/I Gain'
 * '<S9>'   : 'reaction_pendulum_PI_2021/Discrete PID Controller/Ideal P Gain'
 * '<S10>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Integrator'
 * '<S12>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Integrator ICs'
 * '<S13>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/N Copy'
 * '<S14>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/N Gain'
 * '<S15>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/P Copy'
 * '<S16>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Parallel P Gain'
 * '<S17>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Reset Signal'
 * '<S18>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Saturation'
 * '<S19>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Saturation Fdbk'
 * '<S20>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Sum'
 * '<S21>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Sum Fdbk'
 * '<S22>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Tracking Mode'
 * '<S23>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Tsamp - Integral'
 * '<S25>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/postSat Signal'
 * '<S27>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/preSat Signal'
 * '<S28>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S29>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/D Gain/Disabled'
 * '<S30>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Filter/Disabled'
 * '<S31>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Filter ICs/Disabled'
 * '<S32>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S33>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S34>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S35>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Integrator/Discrete'
 * '<S36>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S37>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S38>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/N Gain/Disabled'
 * '<S39>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/P Copy/Disabled'
 * '<S40>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S41>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Reset Signal/Disabled'
 * '<S42>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Saturation/Passthrough'
 * '<S43>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S44>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Sum/Sum_PI'
 * '<S45>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S46>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S47>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S48>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S49>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S50>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S51>'  : 'reaction_pendulum_PI_2021/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                             /* RTW_HEADER_reaction_pendulum_PI_2021_h_ */
