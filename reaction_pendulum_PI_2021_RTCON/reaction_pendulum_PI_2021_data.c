/*
 * reaction_pendulum_PI_2021_data.c
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

/* Block parameters (default storage) */
P_reaction_pendulum_PI_2021_T reaction_pendulum_PI_2021_P = {
  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S3>/S-Function'
   */
  { 1.0, 1.0 },

  /* Variable: h
   * Referenced by: '<S3>/S-Function'
   */
  0.05,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S32>/Integral Gain'
   */
  2.0,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S35>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S40>/Proportional Gain'
   */
  5.0,

  /* Expression: pi
   * Referenced by: '<Root>/Constant1'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Reset'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Normal'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/DC_Ctrl1'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S35>/Integrator'
   */
  0.05,

  /* Expression: 1
   * Referenced by: '<S3>/Gain2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S3>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S3>/Saturation'
   */
  -1.0,

  /* Expression: [1;1]
   * Referenced by: '<S3>/Gain'
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S3>/Prescaler'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/ThermFlag'
   */
  0.0,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S3>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S3>/S-Function'
   */
  1.0,

  /* Expression: 2*pi/20000
   * Referenced by: '<S3>/Pendulum Convert to rad'
   */
  0.00031415926535897931,

  /* Expression: 2*pi/4096
   * Referenced by: '<S3>/DC Convert to rad'
   */
  0.0015339807878856412,

  /* Expression: 0
   * Referenced by: '<S3>/Memory1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/rad2RPM'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory'
   */
  0.0,

  /* Expression: 1/20000000
   * Referenced by: '<S3>/Gain1'
   */
  5.0E-8,

  /* Expression: 0.8333
   * Referenced by: '<S3>/DC Convert to [A]1'
   */
  0.8333,

  /* Expression: 2*pi
   * Referenced by: '<Root>/Constant2'
   */
  6.2831853071795862,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ResetEncoders_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders'
   */
  0U
};
