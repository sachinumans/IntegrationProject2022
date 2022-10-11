/*
 * reaction_pendulum.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "reaction_pendulum".
 *
 * Model version              : 7.17
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Oct 11 13:48:19 2022
 *
 * Target selection: rtcon_rpend_usb2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_reaction_pendulum_h_
#define RTW_HEADER_reaction_pendulum_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef reaction_pendulum_COMMON_INCLUDES_
#define reaction_pendulum_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* reaction_pendulum_COMMON_INCLUDES_ */

#include "reaction_pendulum_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T Delay1[2];                    /* '<S1>/Delay1' */
  real_T Probe[2];                     /* '<S7>/Probe' */
  real_T Constant;                     /* '<S10>/Constant' */
  real_T AB;                           /* '<S6>/[A,B]' */
  real_T Control;                      /* '<S3>/Multiport Switch' */
  real_T Saturation;                   /* '<S2>/Saturation' */
  real_T Gain[2];                      /* '<S2>/Gain' */
  real_T Prescaler;                    /* '<S2>/Prescaler' */
  real_T ThermFlag;                    /* '<S2>/ThermFlag' */
  real_T SFunction_o1;                 /* '<S2>/S-Function' */
  real_T SFunction_o2;                 /* '<S2>/S-Function' */
  real_T SFunction_o3;                 /* '<S2>/S-Function' */
  real_T SFunction_o4;                 /* '<S2>/S-Function' */
  real_T SFunction_o5;                 /* '<S2>/S-Function' */
  real_T SFunction_o6;                 /* '<S2>/S-Function' */
  real_T SFunction_o7[2];              /* '<S2>/S-Function' */
  real_T PendulumAnglerad;             /* '<S2>/Pendulum Convert to rad' */
  real_T Periodms;                     /* '<S2>/Gain1' */
  real_T DCVelrads;                    /* '<S2>/Divide' */
  real_T DCConverttoA1;                /* '<S2>/DC Convert to [A]1' */
  real_T Probe_f[2];                   /* '<S13>/Probe' */
  real_T Constant_a;                   /* '<S16>/Constant' */
  real_T AB_o;                         /* '<S5>/[A,B]' */
  real_T TmpSignalConversionAtDelay1Inpo[2];
  real_T xk1[6];                       /* '<S63>/optimizer' */
  real_T u;                            /* '<S63>/optimizer' */
  real_T xk1_a[6];                     /* '<S41>/optimizer' */
  real_T u_f;                          /* '<S41>/optimizer' */
  boolean_T iAout[60];                 /* '<S63>/optimizer' */
  boolean_T iAout_m[60];               /* '<S41>/optimizer' */
} B_reaction_pendulum_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE[2];             /* '<S1>/Delay1' */
  real_T Integrator_DSTATE;            /* '<S12>/Integrator' */
  real_T last_mv_DSTATE;               /* '<S21>/last_mv' */
  real_T last_mv_DSTATE_d;             /* '<S43>/last_mv' */
  real_T Integrator_DSTATE_g;          /* '<S18>/Integrator' */
  real_T last_x_PreviousInput[6];      /* '<S21>/last_x' */
  real_T last_x_PreviousInput_b[6];    /* '<S43>/last_x' */
  real_T Memory1_PreviousInput;        /* '<S2>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  struct {
    void *LoggedData[4];
  } PlotState_PWORK;                   /* '<Root>/PlotState' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData[3];
  } Observer_PWORK;                    /* '<S1>/Observer' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  int8_T Integrator_PrevResetState;    /* '<S12>/Integrator' */
  int8_T Integrator_PrevResetState_l;  /* '<S18>/Integrator' */
  boolean_T Memory_PreviousInput_h[60];/* '<S21>/Memory' */
  boolean_T Memory_PreviousInput_e[60];/* '<S43>/Memory' */
} DW_reaction_pendulum_T;

/* Parameters (default storage) */
struct P_reaction_pendulum_T_ {
  real_T K[3];                         /* Variable: K
                                        * Referenced by: '<S3>/LQR STABLE'
                                        */
  real_T K_Unst[3];                    /* Variable: K_Unst
                                        * Referenced by: '<S3>/LQR UNSTABLE'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T h;                            /* Variable: h
                                        * Referenced by:
                                        *   '<Root>/Step2'
                                        *   '<S2>/S-Function'
                                        *   '<S13>/Time constant'
                                        *   '<S7>/Time constant'
                                        */
  real_T FilteredDerivative1_A;        /* Mask Parameter: FilteredDerivative1_A
                                        * Referenced by: '<S6>/[A,B]'
                                        */
  real_T FilteredDerivative_A;         /* Mask Parameter: FilteredDerivative_A
                                        * Referenced by: '<S5>/[A,B]'
                                        */
  real_T FilteredDerivative1_B;        /* Mask Parameter: FilteredDerivative1_B
                                        * Referenced by: '<S6>/[A,B]'
                                        */
  real_T FilteredDerivative_B;         /* Mask Parameter: FilteredDerivative_B
                                        * Referenced by: '<S5>/[A,B]'
                                        */
  real_T FilteredDerivative1_K;        /* Mask Parameter: FilteredDerivative1_K
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T FilteredDerivative_K;         /* Mask Parameter: FilteredDerivative_K
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T FilteredDerivative1_minRatio;
                                 /* Mask Parameter: FilteredDerivative1_minRatio
                                  * Referenced by: '<S7>/Minimum sampling to time constant ratio'
                                  */
  real_T FilteredDerivative_minRatio;
                                  /* Mask Parameter: FilteredDerivative_minRatio
                                   * Referenced by: '<S13>/Minimum sampling to time constant ratio'
                                   */
  real_T FilteredDerivative1_x0;       /* Mask Parameter: FilteredDerivative1_x0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T FilteredDerivative_x0;        /* Mask Parameter: FilteredDerivative_x0
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Defaultstoponerror_Value;     /* Expression: 0
                                        * Referenced by: '<S3>/Default stop on error'
                                        */
  real_T Controllerselection_Value;    /* Expression: 4
                                        * Referenced by: '<Root>/<Controller selection'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T last_x_InitialCondition[6];   /* Expression: lastx+xoff
                                        * Referenced by: '<S21>/last_x'
                                        */
  real_T last_mv_InitialCondition;     /* Expression: lastu+uoff
                                        * Referenced by: '<S21>/last_mv'
                                        */
  real_T Ref_Value[3];                 /* Expression: [0 0 0]
                                        * Referenced by: '<S3>/Ref'
                                        */
  real_T md_zero_Value;                /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/md_zero'
                                        */
  real_T umin_zero_Value;              /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/umin_zero'
                                        */
  real_T umax_zero_Value;              /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/umax_zero'
                                        */
  real_T ymin_zero_Value[3];           /* Expression: zeros(3,1)
                                        * Referenced by: '<S19>/ymin_zero'
                                        */
  real_T ymax_zero_Value[3];           /* Expression: zeros(3,1)
                                        * Referenced by: '<S19>/ymax_zero'
                                        */
  real_T E_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/E_zero'
                                        */
  real_T umin_scale4_Gain;         /* Expression: MVscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S21>/umin_scale4'
                                    */
  real_T F_zero_Value[3];              /* Expression: zeros(1,3)
                                        * Referenced by: '<S19>/F_zero'
                                        */
  real_T ymin_scale1_Gain[3];       /* Expression: Yscale(:,ones(1,max(nCC,1)))'
                                     * Referenced by: '<S21>/ymin_scale1'
                                     */
  real_T G_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/G_zero'
                                        */
  real_T S_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/S_zero'
                                        */
  real_T ymin_scale2_Gain;         /* Expression: MDscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S21>/ymin_scale2'
                                    */
  real_T switch_zero_Value;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/switch_zero'
                                        */
  real_T extmv_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/ext.mv_zero'
                                        */
  real_T extmv_scale_Gain;             /* Expression: RMVscale
                                        * Referenced by: '<S21>/ext.mv_scale'
                                        */
  real_T mvtarget_zero_Value;          /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/mv.target_zero'
                                        */
  real_T extmv_scale1_Gain;            /* Expression: RMVscale
                                        * Referenced by: '<S21>/ext.mv_scale1'
                                        */
  real_T ywt_zero_Value[3];            /* Expression: zeros(3,1)
                                        * Referenced by: '<S19>/y.wt_zero'
                                        */
  real_T uwt_zero_Value;               /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/u.wt_zero'
                                        */
  real_T duwt_zero_Value;              /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/du.wt_zero'
                                        */
  real_T ecrwt_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S19>/ecr.wt_zero'
                                        */
  real_T umin_scale1_Gain;             /* Expression: MVscale
                                        * Referenced by: '<S21>/umin_scale1'
                                        */
  real_T last_x_InitialCondition_e[6]; /* Expression: lastx+xoff
                                        * Referenced by: '<S43>/last_x'
                                        */
  real_T last_mv_InitialCondition_g;   /* Expression: lastu+uoff
                                        * Referenced by: '<S43>/last_mv'
                                        */
  real_T Ref1_Value[3];                /* Expression: [0 0 0]
                                        * Referenced by: '<S3>/Ref1'
                                        */
  real_T md_zero_Value_o;              /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/md_zero'
                                        */
  real_T umin_zero_Value_m;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/umin_zero'
                                        */
  real_T umax_zero_Value_n;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/umax_zero'
                                        */
  real_T ymin_zero_Value_g[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S20>/ymin_zero'
                                        */
  real_T ymax_zero_Value_m[3];         /* Expression: zeros(3,1)
                                        * Referenced by: '<S20>/ymax_zero'
                                        */
  real_T E_zero_Value_f;               /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/E_zero'
                                        */
  real_T umin_scale4_Gain_e;       /* Expression: MVscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S43>/umin_scale4'
                                    */
  real_T F_zero_Value_f[3];            /* Expression: zeros(1,3)
                                        * Referenced by: '<S20>/F_zero'
                                        */
  real_T ymin_scale1_Gain_g[3];     /* Expression: Yscale(:,ones(1,max(nCC,1)))'
                                     * Referenced by: '<S43>/ymin_scale1'
                                     */
  real_T G_zero_Value_a;               /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/G_zero'
                                        */
  real_T S_zero_Value_d;               /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/S_zero'
                                        */
  real_T ymin_scale2_Gain_i;       /* Expression: MDscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S43>/ymin_scale2'
                                    */
  real_T switch_zero_Value_f;          /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/switch_zero'
                                        */
  real_T extmv_zero_Value_k;           /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/ext.mv_zero'
                                        */
  real_T extmv_scale_Gain_j;           /* Expression: RMVscale
                                        * Referenced by: '<S43>/ext.mv_scale'
                                        */
  real_T mvtarget_zero_Value_d;        /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/mv.target_zero'
                                        */
  real_T extmv_scale1_Gain_l;          /* Expression: RMVscale
                                        * Referenced by: '<S43>/ext.mv_scale1'
                                        */
  real_T ywt_zero_Value_k[3];          /* Expression: zeros(3,1)
                                        * Referenced by: '<S20>/y.wt_zero'
                                        */
  real_T uwt_zero_Value_d;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/u.wt_zero'
                                        */
  real_T duwt_zero_Value_j;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/du.wt_zero'
                                        */
  real_T ecrwt_zero_Value_e;           /* Expression: zeros(1,1)
                                        * Referenced by: '<S20>/ecr.wt_zero'
                                        */
  real_T umin_scale1_Gain_g;           /* Expression: MVscale
                                        * Referenced by: '<S43>/umin_scale1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Step2_Y0;                     /* Expression: 1
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_YFinal;                 /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Gain_Gain[2];                 /* Expression: [1;1]
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Prescaler_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Prescaler'
                                        */
  real_T ThermFlag_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/ThermFlag'
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: 1
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T PendulumConverttorad_Gain;    /* Expression: 2*pi/20000
                                        * Referenced by: '<S2>/Pendulum Convert to rad'
                                        */
  real_T DCConverttorad_Gain;          /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/DC Convert to rad'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */
  real_T rad2RPM_Gain;                 /* Expression: 1
                                        * Referenced by: '<S2>/rad2RPM'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/20000000
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T DCConverttoA1_Gain;           /* Expression: 0.8333
                                        * Referenced by: '<S2>/DC Convert to [A]1'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Integrator_gainval_n;       /* Computed Parameter: Integrator_gainval_n
                                      * Referenced by: '<S18>/Integrator'
                                      */
  real_T Integrator_UpperSat_o;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T Integrator_LowerSat_h;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S18>/Saturation'
                                        */
  boolean_T Memory_InitialCondition_p[60];/* Expression: iA
                                           * Referenced by: '<S21>/Memory'
                                           */
  boolean_T Memory_InitialCondition_a[60];/* Expression: iA
                                           * Referenced by: '<S43>/Memory'
                                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_reaction_pendulum_T {
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
extern P_reaction_pendulum_T reaction_pendulum_P;

/* Block signals (default storage) */
extern B_reaction_pendulum_T reaction_pendulum_B;

/* Block states (default storage) */
extern DW_reaction_pendulum_T reaction_pendulum_DW;

/* Model entry point functions */
extern void reaction_pendulum_initialize(void);
extern void reaction_pendulum_step(void);
extern void reaction_pendulum_terminate(void);

/* Real-time Model object */
extern RT_MODEL_reaction_pendulum_T *const reaction_pendulum_M;

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
 * '<Root>' : 'reaction_pendulum'
 * '<S1>'   : 'reaction_pendulum/Observer'
 * '<S2>'   : 'reaction_pendulum/RP Driver'
 * '<S3>'   : 'reaction_pendulum/State feedback controllers'
 * '<S4>'   : 'reaction_pendulum/Observer/Deriver'
 * '<S5>'   : 'reaction_pendulum/Observer/Filtered Derivative'
 * '<S6>'   : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1'
 * '<S7>'   : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Enable//disable time constant'
 * '<S8>'   : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Initialization'
 * '<S9>'   : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Integrator (Discrete or Continuous)'
 * '<S10>'  : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Initialization/Init_param'
 * '<S11>'  : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Initialization/Init_param/Data Type Conversion Inherited'
 * '<S12>'  : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Integrator (Discrete or Continuous)/Discrete'
 * '<S13>'  : 'reaction_pendulum/Observer/Filtered Derivative/Enable//disable time constant'
 * '<S14>'  : 'reaction_pendulum/Observer/Filtered Derivative/Initialization'
 * '<S15>'  : 'reaction_pendulum/Observer/Filtered Derivative/Integrator (Discrete or Continuous)'
 * '<S16>'  : 'reaction_pendulum/Observer/Filtered Derivative/Initialization/Init_param'
 * '<S17>'  : 'reaction_pendulum/Observer/Filtered Derivative/Initialization/Init_param/Data Type Conversion Inherited'
 * '<S18>'  : 'reaction_pendulum/Observer/Filtered Derivative/Integrator (Discrete or Continuous)/Discrete'
 * '<S19>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE'
 * '<S20>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE'
 * '<S21>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC'
 * '<S22>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Matrix Signal Check'
 * '<S23>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Matrix Signal Check1'
 * '<S24>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Matrix Signal Check2'
 * '<S25>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check'
 * '<S26>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check1'
 * '<S27>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check2'
 * '<S28>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check3'
 * '<S29>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check4'
 * '<S30>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check5'
 * '<S31>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check6'
 * '<S32>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check7'
 * '<S33>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Preview Signal Check8'
 * '<S34>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Scalar Signal Check'
 * '<S35>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Scalar Signal Check1'
 * '<S36>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Scalar Signal Check2'
 * '<S37>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Vector Signal Check'
 * '<S38>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Vector Signal Check1'
 * '<S39>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/MPC Vector Signal Check6'
 * '<S40>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/moorx'
 * '<S41>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/optimizer'
 * '<S42>'  : 'reaction_pendulum/State feedback controllers/MPC Controller STABLE/MPC/optimizer/optimizer'
 * '<S43>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC'
 * '<S44>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Matrix Signal Check'
 * '<S45>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Matrix Signal Check1'
 * '<S46>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Matrix Signal Check2'
 * '<S47>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check'
 * '<S48>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check1'
 * '<S49>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check2'
 * '<S50>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check3'
 * '<S51>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check4'
 * '<S52>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check5'
 * '<S53>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check6'
 * '<S54>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check7'
 * '<S55>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check8'
 * '<S56>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Scalar Signal Check'
 * '<S57>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Scalar Signal Check1'
 * '<S58>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Scalar Signal Check2'
 * '<S59>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Vector Signal Check'
 * '<S60>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Vector Signal Check1'
 * '<S61>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Vector Signal Check6'
 * '<S62>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/moorx'
 * '<S63>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/optimizer'
 * '<S64>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/optimizer/optimizer'
 */
#endif                                 /* RTW_HEADER_reaction_pendulum_h_ */
