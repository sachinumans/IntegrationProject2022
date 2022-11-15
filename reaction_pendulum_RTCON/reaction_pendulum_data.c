/*
 * reaction_pendulum_data.c
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

#include "reaction_pendulum.h"
#include "reaction_pendulum_private.h"

/* Block parameters (default storage) */
P_reaction_pendulum_T reaction_pendulum_P = {
  { -3.0402455892500528, -1.3062637146035558, 0.0015894966287545518 },

  { -22.556091051209638, -3.1274528840014075, 0.0021642004935652575 },

  { 1.0, 1.0 },
  0.05,
  0.0,
  0.0,
  1.0,
  50.0,
  1.0,
  0.0,
  0.0,
  0.0,

  { 8.61908108672307, 2.302531520780708, -0.00085970618270543044,
    13.317713544471053 },
  0.0,
  2.0,

  { 0.0, 0.0, 0.0 },
  0.0,
  0.0,
  0.05,
  0.0,
  0.0,
  0.0,
  0.0,

  { 0.0, 0.0, 0.0 },
  0.0,

  { 0.0, 0.0, 0.0 },
  0.0,
  0.0,
  0.0,

  { 0.0, 0.0, 0.0 },

  { 0.0, 0.0, 0.0 },
  0.0,
  1.0,

  { 0.0, 0.0, 0.0 },

  { 1.0, 1.0, 1.0 },
  0.0,
  0.0,
  1.0,
  0.0,
  0.0,
  1.0,
  0.0,
  1.0,

  { 0.0, 0.0, 0.0 },
  0.0,
  0.0,
  0.0,
  1.0,
  0.05,
  0.0,
  1.0,
  -1.0,

  { 0.0, 0.0, 0.0 },
  0.0,

  { 0.0, 0.0, 0.0, 0.0 },
  0.0,
  0.0,
  0.0,
  0.0,

  { 0.0, 0.0, 0.0, 0.0 },

  { 0.0, 0.0, 0.0, 0.0 },
  0.0,
  1.0,

  { 0.0, 0.0, 0.0, 0.0 },

  { 1.0, 1.0, 1.0, 1.0 },
  0.0,
  0.0,
  1.0,
  0.0,
  0.0,
  1.0,
  0.0,
  1.0,

  { 0.0, 0.0, 0.0, 0.0 },
  0.0,
  0.0,
  0.0,
  1.0,
  2.0,
  0.0,
  1.0,
  2.2,
  0.0,
  -1.0,
  1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  0.0,

  { 1.0, 1.0 },
  0.0,
  0.0,

  { 1.0, 1.0 },
  1.0,
  0.00031415926535897931,
  0.0015339807878856412,
  0.0,
  1.0,
  0.0,
  5.0E-8,
  0.8333,
  0.0,
  1.0,

  { 1.0, 1.0 },
  -1.0,
  1.0,

  { 0.99999000019748463, -4.9527426727703537E-14, -9.8236561230438244E-16,
    -4.952742598713337E-14, 0.99999999000000028, -3.8694317662647396E-17,
    -9.8236561231488021E-16, -3.8694317576895467E-17, 0.99999000019120554 },

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  { 0.0, 0.0, 0.0 },
  0.0,

  { 0.98615263436656475, -0.54967062879931416, 0.0, 0.048980249871033235,
    0.9548677869051535, 0.0, -1.0286617624311921E-5, -0.00040517078607285053,
    0.95504024985492664 },

  { -0.0047670535098030412, -0.19064676957187676, 20.210925143091238 },

  { 9.999900001974848E-11, -4.9527425985648948E-24, -9.8236561229668266E-26,
    -4.9527425985648925E-24, 9.9999999000000035E-11, -3.8694317662344115E-27,
    -9.8236561229668266E-26, -3.8694317662344115E-27, 9.9999000019120572E-11 },

  { 0.98614277303496967, -0.54966513220162561, -1.0536342306135606E-15,
    0.048980249381181909, 0.95486777735650308, -3.6918911261099855E-17,
    -1.0286514761146594E-5, -0.00040516673444191618, 0.95503069963503706 },

  { 0.0, 0.0, 0.0 },

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0 },

  { false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false },

  { false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false
  },
  true,
  false
};
