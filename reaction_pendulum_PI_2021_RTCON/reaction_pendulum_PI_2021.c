/*
 * reaction_pendulum_PI_2021.c
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

#include "reaction_pendulum_PI_2021.h"
#include "reaction_pendulum_PI_2021_private.h"
#include "reaction_pendulum_PI_2021_dt.h"

/* Block signals (default storage) */
B_reaction_pendulum_PI_2021_T reaction_pendulum_PI_2021_B;

/* Block states (default storage) */
DW_reaction_pendulum_PI_2021_T reaction_pendulum_PI_2021_DW;

/* Real-time model */
static RT_MODEL_reaction_pendulum_PI_2021_T reaction_pendulum_PI_2021_M_;
RT_MODEL_reaction_pendulum_PI_2021_T *const reaction_pendulum_PI_2021_M =
  &reaction_pendulum_PI_2021_M_;

/* Model step function */
void reaction_pendulum_PI_2021_step(void)
{
  /* local block i/o variables */
  real_T rtb_DCAnglerad;
  real_T rtb_Abs;
  real_T rtb_IntegralGain;
  real_T rtb_Memory;
  real_T rtb_Sum_g;

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Delay: '<Root>/Delay'
   */
  if (reaction_pendulum_PI_2021_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_Sum_g = reaction_pendulum_PI_2021_P.Constant1_Value;
  } else {
    rtb_Sum_g = reaction_pendulum_PI_2021_DW.Delay_DSTATE;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/DC_Ctrl1'
   */
  rtb_Sum_g = reaction_pendulum_PI_2021_P.DC_Ctrl1_Value - rtb_Sum_g;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (reaction_pendulum_PI_2021_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  DiscreteIntegrator: '<S35>/Integrator'
     *  Gain: '<S40>/Proportional Gain'
     *  Sum: '<S44>/Sum'
     */
    reaction_pendulum_PI_2021_B.Control =
      reaction_pendulum_PI_2021_P.DiscretePIDController_P * rtb_Sum_g +
      reaction_pendulum_PI_2021_DW.Integrator_DSTATE;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    reaction_pendulum_PI_2021_B.Control =
      reaction_pendulum_PI_2021_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<S3>/Gain2' */
  rtb_Memory = reaction_pendulum_PI_2021_P.Gain2_Gain *
    reaction_pendulum_PI_2021_B.Control;

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Memory > reaction_pendulum_PI_2021_P.Saturation_UpperSat) {
    /* Saturate: '<S3>/Saturation' */
    reaction_pendulum_PI_2021_B.Saturation =
      reaction_pendulum_PI_2021_P.Saturation_UpperSat;
  } else if (rtb_Memory < reaction_pendulum_PI_2021_P.Saturation_LowerSat) {
    /* Saturate: '<S3>/Saturation' */
    reaction_pendulum_PI_2021_B.Saturation =
      reaction_pendulum_PI_2021_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Saturation' */
    reaction_pendulum_PI_2021_B.Saturation = rtb_Memory;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
   *  Constant: '<Root>/Normal'
   *  Constant: '<Root>/Reset'
   */
  if (reaction_pendulum_PI_2021_P.ResetEncoders_CurrentSetting == 1) {
    rtb_Memory = reaction_pendulum_PI_2021_P.Reset_Value;
  } else {
    rtb_Memory = reaction_pendulum_PI_2021_P.Normal_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders' */

  /* Gain: '<S3>/Gain' */
  reaction_pendulum_PI_2021_B.Gain[0] = reaction_pendulum_PI_2021_P.Gain_Gain[0]
    * rtb_Memory;
  reaction_pendulum_PI_2021_B.Gain[1] = reaction_pendulum_PI_2021_P.Gain_Gain[1]
    * rtb_Memory;

  /* Constant: '<S3>/Prescaler' */
  reaction_pendulum_PI_2021_B.Prescaler =
    reaction_pendulum_PI_2021_P.Prescaler_Value;

  /* Constant: '<S3>/ThermFlag' */
  reaction_pendulum_PI_2021_B.ThermFlag =
    reaction_pendulum_PI_2021_P.ThermFlag_Value;

  /* S-Function (rtdacusb2_rpend_dd): '<S3>/S-Function' */

  /* Level2 S-Function Block: '<S3>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = reaction_pendulum_PI_2021_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S3>/Pendulum Convert to rad' */
  reaction_pendulum_PI_2021_B.PendulumAnglerad =
    reaction_pendulum_PI_2021_P.PendulumConverttorad_Gain *
    reaction_pendulum_PI_2021_B.SFunction_o2;

  /* Gain: '<S3>/DC Convert to rad' */
  rtb_DCAnglerad = reaction_pendulum_PI_2021_P.DCConverttorad_Gain *
    reaction_pendulum_PI_2021_B.SFunction_o3;

  /* Gain: '<S3>/Gain1' incorporates:
   *  Memory: '<S3>/Memory'
   *  Sum: '<S3>/Add'
   */
  reaction_pendulum_PI_2021_B.Periodms =
    (reaction_pendulum_PI_2021_B.SFunction_o6 -
     reaction_pendulum_PI_2021_DW.Memory_PreviousInput) *
    reaction_pendulum_PI_2021_P.Gain1_Gain;

  /* Product: '<S3>/Divide' incorporates:
   *  Gain: '<S3>/rad2RPM'
   *  Memory: '<S3>/Memory1'
   *  Sum: '<S3>/Add1'
   */
  reaction_pendulum_PI_2021_B.DCVelrads = (rtb_DCAnglerad -
    reaction_pendulum_PI_2021_DW.Memory1_PreviousInput) *
    reaction_pendulum_PI_2021_P.rad2RPM_Gain /
    reaction_pendulum_PI_2021_B.Periodms;

  /* Gain: '<S3>/DC Convert to [A]1' */
  reaction_pendulum_PI_2021_B.DCConverttoA1 =
    reaction_pendulum_PI_2021_P.DCConverttoA1_Gain *
    reaction_pendulum_PI_2021_B.SFunction_o4;

  /* Abs: '<Root>/Abs' */
  rtb_Abs = fabs(reaction_pendulum_PI_2021_B.PendulumAnglerad);

  /* Product: '<Root>/Product1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  reaction_pendulum_PI_2021_B.Product1 = rtb_Abs /
    reaction_pendulum_PI_2021_P.Constant2_Value;

  /* SignalConversion generated from: '<Root>/To Workspace' */
  reaction_pendulum_PI_2021_B.TmpSignalConversionAtToWorkspac[0] =
    reaction_pendulum_PI_2021_B.PendulumAnglerad;
  reaction_pendulum_PI_2021_B.TmpSignalConversionAtToWorkspac[1] =
    reaction_pendulum_PI_2021_B.DCVelrads;

  /* ToWorkspace: '<Root>/To Workspace' */
  {
    double locTime = reaction_pendulum_PI_2021_M->Timing.t[1]
      ;
    rt_UpdateStructLogVar((StructLogVar *)
                          reaction_pendulum_PI_2021_DW.ToWorkspace_PWORK.LoggedData,
                          &locTime,
                          &reaction_pendulum_PI_2021_B.TmpSignalConversionAtToWorkspac
                          [0]);
  }

  /* ToWorkspace: '<Root>/To Workspace1' */
  {
    double locTime = reaction_pendulum_PI_2021_M->Timing.t[1]
      ;
    rt_UpdateStructLogVar((StructLogVar *)
                          reaction_pendulum_PI_2021_DW.ToWorkspace1_PWORK.LoggedData,
                          &locTime, &reaction_pendulum_PI_2021_B.Control);
  }

  /* Gain: '<S32>/Integral Gain' */
  rtb_IntegralGain = reaction_pendulum_PI_2021_P.DiscretePIDController_I *
    rtb_Sum_g;

  /* Matfile logging */
  rt_UpdateTXYLogVars(reaction_pendulum_PI_2021_M->rtwLogInfo,
                      (reaction_pendulum_PI_2021_M->Timing.t));

  /* Update for Delay: '<Root>/Delay' */
  reaction_pendulum_PI_2021_DW.Delay_DSTATE = rtb_Abs;

  /* Update for DiscreteIntegrator: '<S35>/Integrator' */
  reaction_pendulum_PI_2021_DW.Integrator_DSTATE +=
    reaction_pendulum_PI_2021_P.Integrator_gainval * rtb_IntegralGain;

  /* Update for Memory: '<S3>/Memory1' */
  reaction_pendulum_PI_2021_DW.Memory1_PreviousInput = rtb_DCAnglerad;

  /* Update for Memory: '<S3>/Memory' */
  reaction_pendulum_PI_2021_DW.Memory_PreviousInput =
    reaction_pendulum_PI_2021_B.SFunction_o6;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)reaction_pendulum_PI_2021_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(1, (real_T)reaction_pendulum_PI_2021_M->Timing.t[1]);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(reaction_pendulum_PI_2021_M)!=-1) &&
        !((rtmGetTFinal(reaction_pendulum_PI_2021_M)-
           reaction_pendulum_PI_2021_M->Timing.t[0]) >
          reaction_pendulum_PI_2021_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(reaction_pendulum_PI_2021_M, "Simulation finished");
    }

    if (rtmGetStopRequested(reaction_pendulum_PI_2021_M)) {
      rtmSetErrorStatus(reaction_pendulum_PI_2021_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++reaction_pendulum_PI_2021_M->Timing.clockTick0)) {
    ++reaction_pendulum_PI_2021_M->Timing.clockTickH0;
  }

  reaction_pendulum_PI_2021_M->Timing.t[0] =
    reaction_pendulum_PI_2021_M->Timing.clockTick0 *
    reaction_pendulum_PI_2021_M->Timing.stepSize0 +
    reaction_pendulum_PI_2021_M->Timing.clockTickH0 *
    reaction_pendulum_PI_2021_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++reaction_pendulum_PI_2021_M->Timing.clockTick1)) {
      ++reaction_pendulum_PI_2021_M->Timing.clockTickH1;
    }

    reaction_pendulum_PI_2021_M->Timing.t[1] =
      reaction_pendulum_PI_2021_M->Timing.clockTick1 *
      reaction_pendulum_PI_2021_M->Timing.stepSize1 +
      reaction_pendulum_PI_2021_M->Timing.clockTickH1 *
      reaction_pendulum_PI_2021_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void reaction_pendulum_PI_2021_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)reaction_pendulum_PI_2021_M, 0,
                sizeof(RT_MODEL_reaction_pendulum_PI_2021_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&reaction_pendulum_PI_2021_M->solverInfo,
                          &reaction_pendulum_PI_2021_M->Timing.simTimeStep);
    rtsiSetTPtr(&reaction_pendulum_PI_2021_M->solverInfo, &rtmGetTPtr
                (reaction_pendulum_PI_2021_M));
    rtsiSetStepSizePtr(&reaction_pendulum_PI_2021_M->solverInfo,
                       &reaction_pendulum_PI_2021_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&reaction_pendulum_PI_2021_M->solverInfo,
                          (&rtmGetErrorStatus(reaction_pendulum_PI_2021_M)));
    rtsiSetRTModelPtr(&reaction_pendulum_PI_2021_M->solverInfo,
                      reaction_pendulum_PI_2021_M);
  }

  rtsiSetSimTimeStep(&reaction_pendulum_PI_2021_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&reaction_pendulum_PI_2021_M->solverInfo,"FixedStepDiscrete");
  reaction_pendulum_PI_2021_M->solverInfoPtr =
    (&reaction_pendulum_PI_2021_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = reaction_pendulum_PI_2021_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "reaction_pendulum_PI_2021_M points to
       static memory which is guaranteed to be non-NULL" */
    reaction_pendulum_PI_2021_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    reaction_pendulum_PI_2021_M->Timing.sampleTimes =
      (&reaction_pendulum_PI_2021_M->Timing.sampleTimesArray[0]);
    reaction_pendulum_PI_2021_M->Timing.offsetTimes =
      (&reaction_pendulum_PI_2021_M->Timing.offsetTimesArray[0]);

    /* task periods */
    reaction_pendulum_PI_2021_M->Timing.sampleTimes[0] = (0.0);
    reaction_pendulum_PI_2021_M->Timing.sampleTimes[1] = (0.05);

    /* task offsets */
    reaction_pendulum_PI_2021_M->Timing.offsetTimes[0] = (0.0);
    reaction_pendulum_PI_2021_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(reaction_pendulum_PI_2021_M,
             &reaction_pendulum_PI_2021_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = reaction_pendulum_PI_2021_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    reaction_pendulum_PI_2021_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(reaction_pendulum_PI_2021_M, 500.0);
  reaction_pendulum_PI_2021_M->Timing.stepSize0 = 0.05;
  reaction_pendulum_PI_2021_M->Timing.stepSize1 = 0.05;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    reaction_pendulum_PI_2021_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(reaction_pendulum_PI_2021_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(reaction_pendulum_PI_2021_M->rtwLogInfo, (NULL));
    rtliSetLogT(reaction_pendulum_PI_2021_M->rtwLogInfo, "");
    rtliSetLogX(reaction_pendulum_PI_2021_M->rtwLogInfo, "");
    rtliSetLogXFinal(reaction_pendulum_PI_2021_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(reaction_pendulum_PI_2021_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(reaction_pendulum_PI_2021_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(reaction_pendulum_PI_2021_M->rtwLogInfo, 0);
    rtliSetLogDecimation(reaction_pendulum_PI_2021_M->rtwLogInfo, 1);
    rtliSetLogY(reaction_pendulum_PI_2021_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(reaction_pendulum_PI_2021_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(reaction_pendulum_PI_2021_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  reaction_pendulum_PI_2021_M->Sizes.checksums[0] = (718429032U);
  reaction_pendulum_PI_2021_M->Sizes.checksums[1] = (609093004U);
  reaction_pendulum_PI_2021_M->Sizes.checksums[2] = (662411530U);
  reaction_pendulum_PI_2021_M->Sizes.checksums[3] = (3683977293U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    reaction_pendulum_PI_2021_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(reaction_pendulum_PI_2021_M->extModeInfo,
      &reaction_pendulum_PI_2021_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(reaction_pendulum_PI_2021_M->extModeInfo,
                        reaction_pendulum_PI_2021_M->Sizes.checksums);
    rteiSetTPtr(reaction_pendulum_PI_2021_M->extModeInfo, rtmGetTPtr
                (reaction_pendulum_PI_2021_M));
  }

  reaction_pendulum_PI_2021_M->solverInfoPtr =
    (&reaction_pendulum_PI_2021_M->solverInfo);
  reaction_pendulum_PI_2021_M->Timing.stepSize = (0.05);
  rtsiSetFixedStepSize(&reaction_pendulum_PI_2021_M->solverInfo, 0.05);
  rtsiSetSolverMode(&reaction_pendulum_PI_2021_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &reaction_pendulum_PI_2021_B), 0,
                sizeof(B_reaction_pendulum_PI_2021_T));

  /* states (dwork) */
  (void) memset((void *)&reaction_pendulum_PI_2021_DW, 0,
                sizeof(DW_reaction_pendulum_PI_2021_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    reaction_pendulum_PI_2021_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &reaction_pendulum_PI_2021_M->NonInlinedSFcns.sfcnInfo;
    reaction_pendulum_PI_2021_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (reaction_pendulum_PI_2021_M)));
    reaction_pendulum_PI_2021_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &reaction_pendulum_PI_2021_M->Sizes.numSampTimes);
    reaction_pendulum_PI_2021_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (reaction_pendulum_PI_2021_M)[0]);
    reaction_pendulum_PI_2021_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (reaction_pendulum_PI_2021_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   reaction_pendulum_PI_2021_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(reaction_pendulum_PI_2021_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(reaction_pendulum_PI_2021_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (reaction_pendulum_PI_2021_M));
    rtssSetStepSizePtr(sfcnInfo, &reaction_pendulum_PI_2021_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (reaction_pendulum_PI_2021_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &reaction_pendulum_PI_2021_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &reaction_pendulum_PI_2021_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &reaction_pendulum_PI_2021_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &reaction_pendulum_PI_2021_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &reaction_pendulum_PI_2021_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &reaction_pendulum_PI_2021_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &reaction_pendulum_PI_2021_M->solverInfoPtr);
  }

  reaction_pendulum_PI_2021_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)
                  &reaction_pendulum_PI_2021_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  1*sizeof(SimStruct));
    reaction_pendulum_PI_2021_M->childSfunctions =
      (&reaction_pendulum_PI_2021_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    reaction_pendulum_PI_2021_M->childSfunctions[0] =
      (&reaction_pendulum_PI_2021_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: reaction_pendulum_PI_2021/<S3>/S-Function (rtdacusb2_rpend_dd) */
    {
      SimStruct *rts = reaction_pendulum_PI_2021_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &reaction_pendulum_PI_2021_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &reaction_pendulum_PI_2021_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, reaction_pendulum_PI_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &reaction_pendulum_PI_2021_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &reaction_pendulum_PI_2021_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &reaction_pendulum_PI_2021_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &reaction_pendulum_PI_2021_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &reaction_pendulum_PI_2021_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &reaction_pendulum_PI_2021_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = reaction_pendulum_PI_2021_B.Gain;
          sfcnUPtrs[1] = &reaction_pendulum_PI_2021_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.UPtrs2;
          sfcnUPtrs[0] = &reaction_pendulum_PI_2021_B.Prescaler;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = &reaction_pendulum_PI_2021_B.ThermFlag;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 7);
        _ssSetPortInfo2ForOutputUnits(rts,
          &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        ssSetOutputPortUnit(rts, 6, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 4, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 5, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 6, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &reaction_pendulum_PI_2021_B.SFunction_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &reaction_pendulum_PI_2021_B.SFunction_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &reaction_pendulum_PI_2021_B.SFunction_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &reaction_pendulum_PI_2021_B.SFunction_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &reaction_pendulum_PI_2021_B.SFunction_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &reaction_pendulum_PI_2021_B.SFunction_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 2);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            reaction_pendulum_PI_2021_B.SFunction_o7));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "reaction_pendulum_PI_2021/RP Driver/S-Function");
      ssSetRTModel(rts,reaction_pendulum_PI_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &reaction_pendulum_PI_2021_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       reaction_pendulum_PI_2021_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       reaction_pendulum_PI_2021_P.SFunction_P2_Size);
      }

      /* registration */
      rtdacusb2_rpend_dd(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(reaction_pendulum_PI_2021_M->rtwLogInfo, 0.0,
    rtmGetTFinal(reaction_pendulum_PI_2021_M),
    reaction_pendulum_PI_2021_M->Timing.stepSize0, (&rtmGetErrorStatus
    (reaction_pendulum_PI_2021_M)));

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 2 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 2 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "reaction_pendulum_PI_2021/To Workspace";
    reaction_pendulum_PI_2021_DW.ToWorkspace_PWORK.LoggedData =
      rt_CreateStructLogVar(
      reaction_pendulum_PI_2021_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_PI_2021_M),
      reaction_pendulum_PI_2021_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_PI_2021_M)),
      "Meas",
      1,
      0,
      1,
      0.05,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (reaction_pendulum_PI_2021_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "Control" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "reaction_pendulum_PI_2021/To Workspace1";
    reaction_pendulum_PI_2021_DW.ToWorkspace1_PWORK.LoggedData =
      rt_CreateStructLogVar(
      reaction_pendulum_PI_2021_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_PI_2021_M),
      reaction_pendulum_PI_2021_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_PI_2021_M)),
      "CtrlIn",
      1,
      0,
      1,
      0.05,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (reaction_pendulum_PI_2021_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Constant: '<S3>/Prescaler' */
  reaction_pendulum_PI_2021_B.Prescaler =
    reaction_pendulum_PI_2021_P.Prescaler_Value;

  /* Start for Constant: '<S3>/ThermFlag' */
  reaction_pendulum_PI_2021_B.ThermFlag =
    reaction_pendulum_PI_2021_P.ThermFlag_Value;

  /* Start for S-Function (rtdacusb2_rpend_dd): '<S3>/S-Function' */
  /* Level2 S-Function Block: '<S3>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = reaction_pendulum_PI_2021_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Delay: '<Root>/Delay' */
  reaction_pendulum_PI_2021_DW.Delay_DSTATE =
    reaction_pendulum_PI_2021_P.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Integrator' */
  reaction_pendulum_PI_2021_DW.Integrator_DSTATE =
    reaction_pendulum_PI_2021_P.DiscretePIDController_InitialCo;

  /* InitializeConditions for Memory: '<S3>/Memory1' */
  reaction_pendulum_PI_2021_DW.Memory1_PreviousInput =
    reaction_pendulum_PI_2021_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  reaction_pendulum_PI_2021_DW.Memory_PreviousInput =
    reaction_pendulum_PI_2021_P.Memory_InitialCondition;
}

/* Model terminate function */
void reaction_pendulum_PI_2021_terminate(void)
{
  /* Terminate for S-Function (rtdacusb2_rpend_dd): '<S3>/S-Function' */
  /* Level2 S-Function Block: '<S3>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = reaction_pendulum_PI_2021_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

#include <stdio.h>

/* Final time from "Simulation Parameters"   */
real_T finaltime = 500.0;
real_T StepSize = 0.05;

////////////////////////////////////////////////
//
//  Return compilation date and time
//
char *GetDateAndTime( void )
{
  static char AuxStr[ 128 ];
  sprintf( AuxStr, "%s %s", __DATE__, __TIME__ );
  return( AuxStr );
}
