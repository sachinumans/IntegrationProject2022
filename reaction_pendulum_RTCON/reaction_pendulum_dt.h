/*
 * reaction_pendulum_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(struct_WTmPWsEMvOzNnnAVv5fQNC),
  sizeof(struct_WHjMt45Sk148iktWsfFxl),
  sizeof(struct_lnQ9KXdSZFplhcBp5LBCc),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "struct_WTmPWsEMvOzNnnAVv5fQNC",
  "struct_WHjMt45Sk148iktWsfFxl",
  "struct_lnQ9KXdSZFplhcBp5LBCc",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&reaction_pendulum_B.Delay1[0]), 0, 0, 44 },

  { (char_T *)(&reaction_pendulum_B.iAout[0]), 8, 0, 120 }
  ,

  { (char_T *)(&reaction_pendulum_DW.Delay1_DSTATE[0]), 0, 0, 20 },

  { (char_T *)(&reaction_pendulum_DW.PlotState_PWORK.LoggedData[0]), 11, 0, 9 },

  { (char_T *)(&reaction_pendulum_DW.Integrator_PrevResetState), 2, 0, 2 },

  { (char_T *)(&reaction_pendulum_DW.Memory_PreviousInput_h[0]), 8, 0, 120 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&reaction_pendulum_P.K[0]), 0, 0, 137 },

  { (char_T *)(&reaction_pendulum_P.Memory_InitialCondition_p[0]), 8, 0, 120 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] reaction_pendulum_dt.h */
