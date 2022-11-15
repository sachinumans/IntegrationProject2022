/*
 * reaction_pendulum.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "reaction_pendulum".
 *
 * Model version              : 7.27
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Nov  8 13:45:11 2022
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
#include "rt_assert.h"
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
  real_T Probe[2];                     /* '<S8>/Probe' */
  real_T Constant;                     /* '<S11>/Constant' */
  real_T AB;                           /* '<S7>/[A,B]' */
  real_T DiscreteTimeIntegrator;       /* '<S78>/Discrete-Time Integrator' */
  real_T TmpSignalConversionAtToWorkspac[4];
  real_T Control;                      /* '<S4>/Multiport Switch' */
  real_T Sum;                          /* '<Root>/Sum' */
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
  real_T IC;                           /* '<S20>/IC' */
  real_T TmpSignalConversionAtDelay1Inpo[2];
  real_T umin_scale5[84];              /* '<S103>/umin_scale5' */
  real_T umin_scale5_g[63];            /* '<S81>/umin_scale5' */
  real_T u;                            /* '<S123>/optimizer' */
  real_T u_g;                          /* '<S101>/optimizer' */
  real_T y;                            /* '<S3>/MATLAB Function1' */
  real_T prev_signal;                  /* '<S3>/MATLAB Function1' */
  real_T Product2[3];                  /* '<S77>/Product2' */
  real_T Product3[3];                  /* '<S75>/Product3' */
  boolean_T iAout[110];                /* '<S123>/optimizer' */
  boolean_T iAout_f[80];               /* '<S101>/optimizer' */
} B_reaction_pendulum_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE[2];             /* '<S1>/Delay1' */
  real_T Integrator_DSTATE;            /* '<S13>/Integrator' */
  real_T last_mv_DSTATE;               /* '<S81>/last_mv' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S78>/Discrete-Time Integrator' */
  real_T last_mv_DSTATE_p;             /* '<S103>/last_mv' */
  real_T MemoryX_DSTATE[3];            /* '<S23>/MemoryX' */
  real_T Delay_DSTATE;                 /* '<S3>/Delay' */
  real_T Memory1_PreviousInput;        /* '<S2>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  real_T memory_PreviousInput;         /* '<S20>/memory' */
  struct {
    void *LoggedData[4];
  } PlotState_PWORK;                   /* '<Root>/PlotState' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S4>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_i;              /* '<S4>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S4>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_i;              /* '<S78>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_e;               /* '<Root>/To Workspace' */

  int8_T Integrator_PrevResetState;    /* '<S13>/Integrator' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S51>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S44>/MeasurementUpdate' */
  boolean_T Memory_PreviousInput_e[80];/* '<S81>/Memory' */
  boolean_T Memory_PreviousInput_c[110];/* '<S103>/Memory' */
  boolean_T IC_FirstOutputTime;        /* '<S20>/IC' */
  boolean_T icLoad;                    /* '<S23>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S51>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S44>/MeasurementUpdate' */
} DW_reaction_pendulum_T;

/* Parameters (default storage) */
struct P_reaction_pendulum_T_ {
  real_T K[3];                         /* Variable: K
                                        * Referenced by: '<S4>/LQR STABLE'
                                        */
  real_T K_Unst[3];                    /* Variable: K_Unst
                                        * Referenced by: '<S4>/LQR UNSTABLE'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T h;                            /* Variable: h
                                        * Referenced by:
                                        *   '<Root>/Step2'
                                        *   '<S2>/S-Function'
                                        *   '<S8>/Time constant'
                                        */
  real_T FilteredDerivative1_A;        /* Mask Parameter: FilteredDerivative1_A
                                        * Referenced by: '<S7>/[A,B]'
                                        */
  real_T FilteredDerivative1_B;        /* Mask Parameter: FilteredDerivative1_B
                                        * Referenced by: '<S7>/[A,B]'
                                        */
  real_T FilteredDerivative1_K;        /* Mask Parameter: FilteredDerivative1_K
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T CheckDiscreteGradient_gradient;
                               /* Mask Parameter: CheckDiscreteGradient_gradient
                                * Referenced by: '<S20>/gradient_val'
                                */
  real_T FilteredDerivative1_minRatio;
                                 /* Mask Parameter: FilteredDerivative1_minRatio
                                  * Referenced by: '<S8>/Minimum sampling to time constant ratio'
                                  */
  real_T FilteredDerivative1_x0;       /* Mask Parameter: FilteredDerivative1_x0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S75>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S77>/deltax'
                                        */
  real_T LQIUNSTABLE_Gain[4];        /* Expression: -Ki_Unst*diag([1, 1, 1, 35])
                                      * Referenced by: '<S4>/LQI UNSTABLE'
                                      */
  real_T Defaultstoponerror_Value;     /* Expression: 0
                                        * Referenced by: '<S4>/Default stop on error'
                                        */
  real_T Controllerselection_Value;    /* Expression: 2
                                        * Referenced by: '<Root>/<Controller selection'
                                        */
  real_T Ref_Value[3];                 /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/Ref'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T DisturbanceState_Value[3];    /* Expression: [0 0 0]
                                        * Referenced by: '<S4>/DisturbanceState'
                                        */
  real_T last_mv_InitialCondition;     /* Expression: lastu+uoff
                                        * Referenced by: '<S81>/last_mv'
                                        */
  real_T ym_zero_Value[3];             /* Expression: zeros(nym,1)
                                        * Referenced by: '<S81>/ym_zero'
                                        */
  real_T md_zero_Value;                /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/md_zero'
                                        */
  real_T umin_zero_Value;              /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/umin_zero'
                                        */
  real_T umax_zero_Value;              /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/umax_zero'
                                        */
  real_T ymin_zero_Value[3];           /* Expression: zeros(3,1)
                                        * Referenced by: '<S79>/ymin_zero'
                                        */
  real_T ymax_zero_Value[3];           /* Expression: zeros(3,1)
                                        * Referenced by: '<S79>/ymax_zero'
                                        */
  real_T E_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/E_zero'
                                        */
  real_T umin_scale4_Gain;         /* Expression: MVscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S81>/umin_scale4'
                                    */
  real_T F_zero_Value[3];              /* Expression: zeros(1,3)
                                        * Referenced by: '<S79>/F_zero'
                                        */
  real_T ymin_scale1_Gain[3];       /* Expression: Yscale(:,ones(1,max(nCC,1)))'
                                     * Referenced by: '<S81>/ymin_scale1'
                                     */
  real_T G_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/G_zero'
                                        */
  real_T S_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/S_zero'
                                        */
  real_T ymin_scale2_Gain;         /* Expression: MDscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S81>/ymin_scale2'
                                    */
  real_T switch_zero_Value;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/switch_zero'
                                        */
  real_T extmv_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/ext.mv_zero'
                                        */
  real_T extmv_scale_Gain;             /* Expression: RMVscale
                                        * Referenced by: '<S81>/ext.mv_scale'
                                        */
  real_T mvtarget_zero_Value;          /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/mv.target_zero'
                                        */
  real_T extmv_scale1_Gain;            /* Expression: RMVscale
                                        * Referenced by: '<S81>/ext.mv_scale1'
                                        */
  real_T ywt_zero_Value[3];            /* Expression: zeros(3,1)
                                        * Referenced by: '<S79>/y.wt_zero'
                                        */
  real_T uwt_zero_Value;               /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/u.wt_zero'
                                        */
  real_T duwt_zero_Value;              /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/du.wt_zero'
                                        */
  real_T ecrwt_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S79>/ecr.wt_zero'
                                        */
  real_T umin_scale1_Gain;             /* Expression: MVscale
                                        * Referenced by: '<S81>/umin_scale1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S78>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S78>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S78>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: -1
                                          * Referenced by: '<S78>/Discrete-Time Integrator'
                                          */
  real_T DisturbanceState1_Value[3];   /* Expression: [0 0 0]
                                        * Referenced by: '<S4>/DisturbanceState1'
                                        */
  real_T last_mv_InitialCondition_n;   /* Expression: lastu+uoff
                                        * Referenced by: '<S103>/last_mv'
                                        */
  real_T ym_zero_Value_c[4];           /* Expression: zeros(nym,1)
                                        * Referenced by: '<S103>/ym_zero'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T md_zero_Value_k;              /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/md_zero'
                                        */
  real_T umin_zero_Value_m;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/umin_zero'
                                        */
  real_T umax_zero_Value_o;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/umax_zero'
                                        */
  real_T ymin_zero_Value_l[4];         /* Expression: zeros(4,1)
                                        * Referenced by: '<S80>/ymin_zero'
                                        */
  real_T ymax_zero_Value_b[4];         /* Expression: zeros(4,1)
                                        * Referenced by: '<S80>/ymax_zero'
                                        */
  real_T E_zero_Value_e;               /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/E_zero'
                                        */
  real_T umin_scale4_Gain_d;       /* Expression: MVscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S103>/umin_scale4'
                                    */
  real_T F_zero_Value_l[4];            /* Expression: zeros(1,4)
                                        * Referenced by: '<S80>/F_zero'
                                        */
  real_T ymin_scale1_Gain_j[4];     /* Expression: Yscale(:,ones(1,max(nCC,1)))'
                                     * Referenced by: '<S103>/ymin_scale1'
                                     */
  real_T G_zero_Value_b;               /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/G_zero'
                                        */
  real_T S_zero_Value_o;               /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/S_zero'
                                        */
  real_T ymin_scale2_Gain_o;       /* Expression: MDscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S103>/ymin_scale2'
                                    */
  real_T switch_zero_Value_n;          /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/switch_zero'
                                        */
  real_T extmv_zero_Value_f;           /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/ext.mv_zero'
                                        */
  real_T extmv_scale_Gain_l;           /* Expression: RMVscale
                                        * Referenced by: '<S103>/ext.mv_scale'
                                        */
  real_T mvtarget_zero_Value_a;        /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/mv.target_zero'
                                        */
  real_T extmv_scale1_Gain_h;          /* Expression: RMVscale
                                        * Referenced by: '<S103>/ext.mv_scale1'
                                        */
  real_T ywt_zero_Value_c[4];          /* Expression: zeros(4,1)
                                        * Referenced by: '<S80>/y.wt_zero'
                                        */
  real_T uwt_zero_Value_e;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/u.wt_zero'
                                        */
  real_T duwt_zero_Value_p;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/du.wt_zero'
                                        */
  real_T ecrwt_zero_Value_a;           /* Expression: zeros(1,1)
                                        * Referenced by: '<S80>/ecr.wt_zero'
                                        */
  real_T umin_scale1_Gain_a;           /* Expression: MVscale
                                        * Referenced by: '<S103>/umin_scale1'
                                        */
  real_T Step3_Time;                   /* Expression: 2
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step3_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step3_YFinal;                 /* Expression: 1
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step4_Time;                   /* Expression: 2.2
                                        * Referenced by: '<Root>/Step4'
                                        */
  real_T Step4_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step4'
                                        */
  real_T Step4_YFinal;                 /* Expression: -1
                                        * Referenced by: '<Root>/Step4'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
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
  real_T Gain_Gain_d[2];               /* Expression: [1;1]
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
  real_T memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S20>/memory'
                                        */
  real_T rising_Gain;                  /* Expression: 1
                                        * Referenced by: '<S20>/rising'
                                        */
  real_T expander_Gain[2];             /* Expression: [1 1]
                                        * Referenced by: '<S20>/expander'
                                        */
  real_T falling_Gain;                 /* Expression: -1
                                        * Referenced by: '<S20>/falling'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S20>/IC'
                                        */
  real_T KalmanGainM_Value[9];         /* Expression: pInitialization.M
                                        * Referenced by: '<S24>/KalmanGainM'
                                        */
  real_T C_Value[9];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S23>/C'
                                        */
  real_T Constant3_Value[3];           /* Expression: [0 0 0]
                                        * Referenced by: '<S21>/Constant3'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T A_Value[9];                   /* Expression: pInitialization.A
                                        * Referenced by: '<S23>/A'
                                        */
  real_T B_Value[3];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S23>/B'
                                        */
  real_T CovarianceZ_Value[9];         /* Expression: pInitialization.Z
                                        * Referenced by: '<S24>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value[9];         /* Expression: pInitialization.L
                                        * Referenced by: '<S24>/KalmanGainL'
                                        */
  real_T D_Value[3];                   /* Expression: pInitialization.D
                                        * Referenced by: '<S23>/D'
                                        */
  real_T umin_scale5_Gain[84];         /* Expression: Yscale(:,ones(1,p+1))'
                                        * Referenced by: '<S103>/umin_scale5'
                                        */
  real_T umin_scale5_Gain_f[63];       /* Expression: Yscale(:,ones(1,p+1))'
                                        * Referenced by: '<S81>/umin_scale5'
                                        */
  boolean_T Memory_InitialCondition_a[80];/* Expression: iA
                                           * Referenced by: '<S81>/Memory'
                                           */
  boolean_T Memory_InitialCondition_k[110];/* Expression: iA
                                            * Referenced by: '<S103>/Memory'
                                            */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S23>/Enable'
                                        */
  boolean_T isSqrtUsed_Value;          /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S73>/isSqrtUsed'
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
 * '<S3>'   : 'reaction_pendulum/RPM packet drop rejector'
 * '<S4>'   : 'reaction_pendulum/State feedback controllers'
 * '<S5>'   : 'reaction_pendulum/Observer/Deriver'
 * '<S6>'   : 'reaction_pendulum/Observer/Filtered Derivative'
 * '<S7>'   : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1'
 * '<S8>'   : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Enable//disable time constant'
 * '<S9>'   : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Initialization'
 * '<S10>'  : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Integrator (Discrete or Continuous)'
 * '<S11>'  : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Initialization/Init_param'
 * '<S12>'  : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Initialization/Init_param/Data Type Conversion Inherited'
 * '<S13>'  : 'reaction_pendulum/Observer/Deriver/Filtered Derivative1/Integrator (Discrete or Continuous)/Discrete'
 * '<S14>'  : 'reaction_pendulum/Observer/Filtered Derivative/Enable//disable time constant'
 * '<S15>'  : 'reaction_pendulum/Observer/Filtered Derivative/Initialization'
 * '<S16>'  : 'reaction_pendulum/Observer/Filtered Derivative/Integrator (Discrete or Continuous)'
 * '<S17>'  : 'reaction_pendulum/Observer/Filtered Derivative/Initialization/Init_param'
 * '<S18>'  : 'reaction_pendulum/Observer/Filtered Derivative/Initialization/Init_param/Data Type Conversion Inherited'
 * '<S19>'  : 'reaction_pendulum/Observer/Filtered Derivative/Integrator (Discrete or Continuous)/Discrete'
 * '<S20>'  : 'reaction_pendulum/RPM packet drop rejector/Check Discrete Gradient'
 * '<S21>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1'
 * '<S22>'  : 'reaction_pendulum/RPM packet drop rejector/MATLAB Function1'
 * '<S23>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter'
 * '<S24>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CalculatePL'
 * '<S25>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CalculateYhat'
 * '<S26>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CovarianceOutputConfigurator'
 * '<S27>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionA'
 * '<S28>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionB'
 * '<S29>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionC'
 * '<S30>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionD'
 * '<S31>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionEnable'
 * '<S32>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionG'
 * '<S33>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionH'
 * '<S34>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionN'
 * '<S35>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionP'
 * '<S36>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionP0'
 * '<S37>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionQ'
 * '<S38>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionR'
 * '<S39>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionReset'
 * '<S40>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionX'
 * '<S41>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionX0'
 * '<S42>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/DataTypeConversionu'
 * '<S43>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/MemoryP'
 * '<S44>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/Observer'
 * '<S45>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/ReducedQRN'
 * '<S46>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/Reset'
 * '<S47>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/Reshapeyhat'
 * '<S48>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/ScalarExpansionP0'
 * '<S49>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/ScalarExpansionQ'
 * '<S50>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/ScalarExpansionR'
 * '<S51>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/UseCurrentEstimator'
 * '<S52>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkA'
 * '<S53>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkB'
 * '<S54>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkC'
 * '<S55>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkD'
 * '<S56>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkEnable'
 * '<S57>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkG'
 * '<S58>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkH'
 * '<S59>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkN'
 * '<S60>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkP0'
 * '<S61>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkQ'
 * '<S62>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkR'
 * '<S63>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkReset'
 * '<S64>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checkX0'
 * '<S65>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checku'
 * '<S66>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/checky'
 * '<S67>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S68>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S69>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S70>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S71>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CalculatePL/Ground'
 * '<S72>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CalculateYhat/Ground'
 * '<S73>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S74>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S75>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/Observer/MeasurementUpdate'
 * '<S76>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/ReducedQRN/Ground'
 * '<S77>'  : 'reaction_pendulum/RPM packet drop rejector/Kalman Filter1/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S78>'  : 'reaction_pendulum/State feedback controllers/Add integraion channel'
 * '<S79>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE'
 * '<S80>'  : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE'
 * '<S81>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC'
 * '<S82>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Matrix Signal Check'
 * '<S83>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Matrix Signal Check1'
 * '<S84>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Matrix Signal Check2'
 * '<S85>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check'
 * '<S86>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check1'
 * '<S87>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check2'
 * '<S88>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check3'
 * '<S89>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check4'
 * '<S90>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check5'
 * '<S91>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check6'
 * '<S92>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check7'
 * '<S93>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Preview Signal Check8'
 * '<S94>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Scalar Signal Check'
 * '<S95>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Scalar Signal Check1'
 * '<S96>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Scalar Signal Check2'
 * '<S97>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Vector Signal Check'
 * '<S98>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Vector Signal Check1'
 * '<S99>'  : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/MPC Vector Signal Check6'
 * '<S100>' : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/moorx'
 * '<S101>' : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/optimizer'
 * '<S102>' : 'reaction_pendulum/State feedback controllers/MPC Controller UNSTABLE/MPC/optimizer/optimizer'
 * '<S103>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC'
 * '<S104>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Matrix Signal Check'
 * '<S105>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Matrix Signal Check1'
 * '<S106>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Matrix Signal Check2'
 * '<S107>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check'
 * '<S108>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check1'
 * '<S109>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check2'
 * '<S110>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check3'
 * '<S111>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check4'
 * '<S112>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check5'
 * '<S113>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check6'
 * '<S114>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check7'
 * '<S115>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Preview Signal Check8'
 * '<S116>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Scalar Signal Check'
 * '<S117>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Scalar Signal Check1'
 * '<S118>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Scalar Signal Check2'
 * '<S119>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Vector Signal Check'
 * '<S120>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Vector Signal Check1'
 * '<S121>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/MPC Vector Signal Check6'
 * '<S122>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/moorx'
 * '<S123>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/optimizer'
 * '<S124>' : 'reaction_pendulum/State feedback controllers/MPCI Controller UNSTABLE/MPC/optimizer/optimizer'
 */
#endif                                 /* RTW_HEADER_reaction_pendulum_h_ */
