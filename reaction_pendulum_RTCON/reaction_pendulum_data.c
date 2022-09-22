/*
 * reaction_pendulum_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "reaction_pendulum".
 *
 * Model version              : 7.5
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Sep 22 14:04:14 2022
 *
 * Target selection: rtcon_rpend_usb2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "reaction_pendulum.h"
#include "reaction_pendulum_private.h"

/* Block parameters (default storage) */
P_reaction_pendulum_T reaction_pendulum_P = {
  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S2>/S-Function'
   */
  { 1.0, 1.0 },

  /* Variable: h
   * Referenced by: '<S2>/S-Function'
   */
  0.05,

  /* Mask Parameter: Chirp_Tsweep
   * Referenced by: '<Root>/Chirp'
   */
  60.0,

  /* Mask Parameter: Chirp_f0
   * Referenced by: '<Root>/Chirp'
   */
  10.0,

  /* Mask Parameter: Chirp_f1
   * Referenced by: '<Root>/Chirp'
   */
  0.01,

  /* Mask Parameter: Chirp_phase
   * Referenced by: '<Root>/Chirp'
   */
  0.0,

  /* Mask Parameter: Chirp_t1
   * Referenced by: '<Root>/Chirp'
   */
  60.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/DC_Ctrl1'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/Gain1'
   */
  0.3,

  /* Expression: 1
   * Referenced by: '<Root>/Reset'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Normal'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Gain2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Saturation'
   */
  -1.0,

  /* Expression: [1;1]
   * Referenced by: '<S2>/Gain'
   */
  { 1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/Prescaler'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/ThermFlag'
   */
  0.0,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S2>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S2>/S-Function'
   */
  1.0,

  /* Expression: 2*pi/20000
   * Referenced by: '<S2>/Pendulum Convert to rad'
   */
  0.00031415926535897931,

  /* Expression: 2*pi/4096
   * Referenced by: '<S2>/DC Convert to rad'
   */
  0.0015339807878856412,

  /* Expression: 0
   * Referenced by: '<S2>/Memory1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/rad2RPM'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Memory'
   */
  0.0,

  /* Expression: 1/20000000
   * Referenced by: '<S2>/Gain1'
   */
  5.0E-8,

  /* Expression: 0.8333
   * Referenced by: '<S2>/DC Convert to [A]1'
   */
  0.8333,

  /* Computed Parameter: ResetEncoders1_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders1'
   */
  0U,

  /* Computed Parameter: ResetEncoders_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders'
   */
  0U
};
