/*
 * reaction_pendulum.c
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
#include "reaction_pendulum_dt.h"

/* Named constants for MATLAB Function: '<S101>/optimizer' */
#define reaction_pendulum_ny           (3)
#define reaction_pendulum_p            (20)

/* Block signals (default storage) */
B_reaction_pendulum_T reaction_pendulum_B;

/* Block states (default storage) */
DW_reaction_pendulum_T reaction_pendulum_DW;

/* Real-time model */
static RT_MODEL_reaction_pendulum_T reaction_pendulum_M_;
RT_MODEL_reaction_pendulum_T *const reaction_pendulum_M = &reaction_pendulum_M_;

/* Forward declaration for local functions */
static void reaction_pendulum_Unconstrained(const real_T b_Hinv[256], const
  real_T f[16], real_T x[16], int16_T n);
static real_T reaction_pendulum_norm(const real_T x[16]);
static void reaction_pendulum_abs(const real_T x[16], real_T y[16]);
static real_T reaction_pendulum_maximum(const real_T x[16]);
static void reaction_pendulum_abs_j(const real_T x[80], real_T y[80]);
static void reaction_pendulum_maximum2(const real_T x[80], real_T y, real_T ex
  [80]);
static real_T reaction_pendulum_xnrm2(int32_T n, const real_T x[256], int32_T
  ix0);
static void reaction_pendulum_xgemv(int32_T b_m, int32_T n, const real_T b_A[256],
  int32_T ia0, const real_T x[256], int32_T ix0, real_T y[16]);
static void reaction_pendulum_xgerc(int32_T b_m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[16], real_T b_A[256], int32_T ia0);
static void reaction_pendulum_qr(const real_T b_A[256], real_T Q[256], real_T R
  [256]);
static real_T reaction_pendulum_KWIKfactor(const real_T b_Ac[1280], const
  int16_T iC[80], int16_T nA, const real_T b_Linv[256], real_T RLinv[256],
  real_T D[256], real_T b_H[256], int16_T n);
static real_T reaction_pendulum_mtimes(const real_T b_A[16], const real_T B[16]);
static void reaction_pendulu_DropConstraint(int16_T kDrop, int16_T iA[80],
  int16_T *nA, int16_T iC[80]);
static void reaction_pendulum_qpkwik(const real_T b_Linv[256], const real_T
  b_Hinv[256], const real_T f[16], const real_T b_Ac[1280], const real_T b[80],
  int16_T iA[80], int16_T maxiter, real_T FeasTol, real_T x[16], real_T lambda
  [80], real_T *status);
static void reaction_pendulum_abs_cd(const real_T x[110], real_T y[110]);
static void reaction_pendulum_maximum2_h(const real_T x[110], real_T y, real_T
  ex[110]);
static real_T reaction_pendulum_KWIKfactor_l(const real_T b_Ac[1760], const
  int16_T iC[110], int16_T nA, const real_T b_Linv[256], real_T RLinv[256],
  real_T D[256], real_T b_H[256], int16_T n);
static void reaction_pendu_DropConstraint_n(int16_T kDrop, int16_T iA[110],
  int16_T *nA, int16_T iC[110]);
static void reaction_pendulum_qpkwik_j(const real_T b_Linv[256], const real_T
  b_Hinv[256], const real_T f[16], const real_T b_Ac[1760], const real_T b[110],
  int16_T iA[110], int16_T maxiter, real_T FeasTol, real_T x[16], real_T lambda
  [110], real_T *status);

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulum_Unconstrained(const real_T b_Hinv[256], const
  real_T f[16], real_T x[16], int16_T n)
{
  real_T b_Hinv_0;
  int32_T i;
  int32_T i_0;
  for (i = 1; i - 1 < n; i++) {
    b_Hinv_0 = 0.0;
    for (i_0 = 0; i_0 < 16; i_0++) {
      b_Hinv_0 += -b_Hinv[((i_0 << 4) + (int16_T)i) - 1] * f[i_0];
    }

    x[(int16_T)i - 1] = b_Hinv_0;
  }
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static real_T reaction_pendulum_norm(const real_T x[16])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 16; k++) {
    absxk = fabs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulum_abs(const real_T x[16], real_T y[16])
{
  int32_T k;
  for (k = 0; k < 16; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static real_T reaction_pendulum_maximum(const real_T x[16])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 16) {
      if (ex < x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulum_abs_j(const real_T x[80], real_T y[80])
{
  int32_T k;
  for (k = 0; k < 80; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulum_maximum2(const real_T x[80], real_T y, real_T ex
  [80])
{
  real_T u0;
  int32_T k;
  for (k = 0; k < 80; k++) {
    u0 = x[k];
    if ((u0 >= y) || rtIsNaN(y)) {
      ex[k] = u0;
    } else {
      ex[k] = y;
    }
  }
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static real_T reaction_pendulum_xnrm2(int32_T n, const real_T x[256], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulum_xgemv(int32_T b_m, int32_T n, const real_T b_A[256],
  int32_T ia0, const real_T x[256], int32_T ix0, real_T y[16])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((b_m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = ((n - 1) << 4) + ia0;
    for (iac = ia0; iac <= b; iac += 16) {
      ix = ix0;
      c = 0.0;
      d = (iac + b_m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += b_A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulum_xgerc(int32_T b_m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[16], real_T b_A[256], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        ijA = jA;
        b = b_m + jA;
        while (ijA + 1 <= b) {
          b_A[ijA] += b_A[ix - 1] * temp;
          ix++;
          ijA++;
        }
      }

      jy++;
      jA += 16;
    }
  }
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulum_qr(const real_T b_A[256], real_T Q[256], real_T R
  [256])
{
  real_T c_A[256];
  real_T tau[16];
  real_T work[16];
  real_T atmp;
  real_T beta1;
  int32_T b_coltop;
  int32_T c_lastc;
  int32_T coltop;
  int32_T exitg1;
  int32_T i;
  int32_T itau;
  int32_T knt;
  boolean_T exitg2;
  memcpy(&c_A[0], &b_A[0], sizeof(real_T) << 8U);
  memset(&tau[0], 0, sizeof(real_T) << 4U);
  memset(&work[0], 0, sizeof(real_T) << 4U);
  for (itau = 0; itau < 16; itau++) {
    i = (itau << 4) + itau;
    if (itau + 1 < 16) {
      atmp = c_A[i];
      tau[itau] = 0.0;
      beta1 = reaction_pendulum_xnrm2(15 - itau, c_A, i + 2);
      if (beta1 != 0.0) {
        beta1 = rt_hypotd_snf(c_A[i], beta1);
        if (c_A[i] >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = -1;
          c_lastc = (i - itau) + 16;
          do {
            knt++;
            for (b_coltop = i + 1; b_coltop < c_lastc; b_coltop++) {
              c_A[b_coltop] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            atmp *= 9.9792015476736E+291;
          } while (!(fabs(beta1) >= 1.0020841800044864E-292));

          beta1 = rt_hypotd_snf(atmp, reaction_pendulum_xnrm2(15 - itau, c_A, i
            + 2));
          if (atmp >= 0.0) {
            beta1 = -beta1;
          }

          tau[itau] = (beta1 - atmp) / beta1;
          atmp = 1.0 / (atmp - beta1);
          for (b_coltop = i + 1; b_coltop < c_lastc; b_coltop++) {
            c_A[b_coltop] *= atmp;
          }

          for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
            beta1 *= 1.0020841800044864E-292;
          }

          atmp = beta1;
        } else {
          tau[itau] = (beta1 - c_A[i]) / beta1;
          atmp = 1.0 / (c_A[i] - beta1);
          knt = (i - itau) + 16;
          for (c_lastc = i + 1; c_lastc < knt; c_lastc++) {
            c_A[c_lastc] *= atmp;
          }

          atmp = beta1;
        }
      }

      c_A[i] = atmp;
      beta1 = c_A[i];
      c_A[i] = 1.0;
      if (tau[itau] != 0.0) {
        knt = 16 - itau;
        c_lastc = (i - itau) + 15;
        while ((knt > 0) && (c_A[c_lastc] == 0.0)) {
          knt--;
          c_lastc--;
        }

        c_lastc = 15 - itau;
        exitg2 = false;
        while ((!exitg2) && (c_lastc > 0)) {
          b_coltop = (((c_lastc - 1) << 4) + i) + 16;
          coltop = b_coltop;
          do {
            exitg1 = 0;
            if (coltop + 1 <= b_coltop + knt) {
              if (c_A[coltop] != 0.0) {
                exitg1 = 1;
              } else {
                coltop++;
              }
            } else {
              c_lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        knt = 0;
        c_lastc = 0;
      }

      if (knt > 0) {
        reaction_pendulum_xgemv(knt, c_lastc, c_A, i + 17, c_A, i + 1, work);
        reaction_pendulum_xgerc(knt, c_lastc, -tau[itau], i + 1, work, c_A, i +
          17);
      }

      c_A[i] = beta1;
    } else {
      tau[15] = 0.0;
    }
  }

  for (itau = 0; itau < 16; itau++) {
    for (i = 0; i <= itau; i++) {
      R[i + (itau << 4)] = c_A[(itau << 4) + i];
    }

    for (i = itau + 1; i + 1 < 17; i++) {
      R[i + (itau << 4)] = 0.0;
    }

    work[itau] = 0.0;
  }

  for (i = 15; i >= 0; i--) {
    knt = ((i << 4) + i) + 17;
    if (i + 1 < 16) {
      c_A[knt - 17] = 1.0;
      if (tau[i] != 0.0) {
        c_lastc = 16 - i;
        b_coltop = knt - i;
        while ((c_lastc > 0) && (c_A[b_coltop - 2] == 0.0)) {
          c_lastc--;
          b_coltop--;
        }

        b_coltop = 15 - i;
        exitg2 = false;
        while ((!exitg2) && (b_coltop > 0)) {
          coltop = ((b_coltop - 1) << 4) + knt;
          itau = coltop;
          do {
            exitg1 = 0;
            if (itau <= (coltop + c_lastc) - 1) {
              if (c_A[itau - 1] != 0.0) {
                exitg1 = 1;
              } else {
                itau++;
              }
            } else {
              b_coltop--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        c_lastc = 0;
        b_coltop = 0;
      }

      if (c_lastc > 0) {
        reaction_pendulum_xgemv(c_lastc, b_coltop, c_A, knt, c_A, knt - 16, work);
        reaction_pendulum_xgerc(c_lastc, b_coltop, -tau[i], knt - 16, work, c_A,
          knt);
      }

      c_lastc = (knt - i) - 1;
      for (b_coltop = knt - 16; b_coltop < c_lastc; b_coltop++) {
        c_A[b_coltop] *= -tau[i];
      }
    }

    c_A[knt - 17] = 1.0 - tau[i];
    for (c_lastc = 0; c_lastc < i; c_lastc++) {
      c_A[(knt - c_lastc) - 18] = 0.0;
    }
  }

  for (itau = 0; itau < 16; itau++) {
    memcpy(&Q[itau << 4], &c_A[itau << 4], sizeof(real_T) << 4U);
  }
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static real_T reaction_pendulum_KWIKfactor(const real_T b_Ac[1280], const
  int16_T iC[80], int16_T nA, const real_T b_Linv[256], real_T RLinv[256],
  real_T D[256], real_T b_H[256], int16_T n)
{
  real_T QQ[256];
  real_T RR[256];
  real_T TL[256];
  real_T Status;
  real_T b_Linv_0;
  int32_T exitg1;
  int32_T f_i;
  int32_T i;
  int32_T iC_0;
  int32_T i_0;
  int32_T tmp;
  int16_T b_j;
  int16_T c_k;
  Status = 1.0;
  memset(&RLinv[0], 0, sizeof(real_T) << 8U);
  for (i = 1; i - 1 < nA; i++) {
    iC_0 = iC[(int16_T)i - 1];
    for (i_0 = 0; i_0 < 16; i_0++) {
      tmp = (((int16_T)i - 1) << 4) + i_0;
      RLinv[tmp] = 0.0;
      for (f_i = 0; f_i < 16; f_i++) {
        RLinv[tmp] += b_Ac[(80 * f_i + iC_0) - 1] * b_Linv[(f_i << 4) + i_0];
      }
    }
  }

  reaction_pendulum_qr(RLinv, QQ, RR);
  i = 1;
  do {
    exitg1 = 0;
    if (i - 1 <= nA - 1) {
      if (fabs(RR[((((int16_T)i - 1) << 4) + (int16_T)i) - 1]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      for (i = 1; i - 1 < n; i++) {
        for (f_i = 1; f_i - 1 < n; f_i++) {
          b_Linv_0 = 0.0;
          for (i_0 = 0; i_0 < 16; i_0++) {
            b_Linv_0 += b_Linv[(((int16_T)i - 1) << 4) + i_0] * QQ[(((int16_T)
              f_i - 1) << 4) + i_0];
          }

          TL[((int16_T)i + (((int16_T)f_i - 1) << 4)) - 1] = b_Linv_0;
        }
      }

      memset(&RLinv[0], 0, sizeof(real_T) << 8U);
      for (b_j = nA; b_j > 0; b_j--) {
        i_0 = (b_j - 1) << 4;
        tmp = (b_j + i_0) - 1;
        RLinv[tmp] = 1.0;
        for (c_k = b_j; c_k <= nA; c_k++) {
          f_i = (((c_k - 1) << 4) + b_j) - 1;
          RLinv[f_i] /= RR[tmp];
        }

        if (b_j > 1) {
          for (i = 1; i - 1 <= b_j - 2; i++) {
            for (c_k = b_j; c_k <= nA; c_k++) {
              tmp = (c_k - 1) << 4;
              f_i = (tmp + (int16_T)i) - 1;
              RLinv[f_i] -= RR[(i_0 + (int16_T)i) - 1] * RLinv[(tmp + b_j) - 1];
            }
          }
        }
      }

      for (i = 1; i - 1 < n; i++) {
        for (b_j = (int16_T)i; b_j <= n; b_j++) {
          i_0 = (((b_j - 1) << 4) + (int16_T)i) - 1;
          b_H[i_0] = 0.0;
          tmp = nA + 1;
          if (nA + 1 > 32767) {
            tmp = 32767;
          }

          for (c_k = (int16_T)tmp; c_k <= n; c_k++) {
            tmp = (c_k - 1) << 4;
            b_H[i_0] -= TL[(tmp + (int16_T)i) - 1] * TL[(tmp + b_j) - 1];
          }

          b_H[(b_j + (((int16_T)i - 1) << 4)) - 1] = b_H[i_0];
        }
      }

      for (i = 1; i - 1 < nA; i++) {
        for (f_i = 1; f_i - 1 < n; f_i++) {
          i_0 = ((((int16_T)i - 1) << 4) + (int16_T)f_i) - 1;
          D[i_0] = 0.0;
          for (b_j = (int16_T)i; b_j <= nA; b_j++) {
            tmp = (b_j - 1) << 4;
            D[i_0] += TL[(tmp + (int16_T)f_i) - 1] * RLinv[(tmp + (int16_T)i) -
              1];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static real_T reaction_pendulum_mtimes(const real_T b_A[16], const real_T B[16])
{
  real_T b_C;
  int32_T k;
  b_C = 0.0;
  for (k = 0; k < 16; k++) {
    b_C += b_A[k] * B[k];
  }

  return b_C;
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulu_DropConstraint(int16_T kDrop, int16_T iA[80],
  int16_T *nA, int16_T iC[80])
{
  int32_T tmp;
  int16_T i;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (*nA - 1 < -32768) {
      tmp = -32768;
    }

    for (i = kDrop; i <= (int16_T)tmp; i++) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  tmp = *nA - 1;
  if (*nA - 1 < -32768) {
    tmp = -32768;
  }

  *nA = (int16_T)tmp;
}

/* Function for MATLAB Function: '<S101>/optimizer' */
static void reaction_pendulum_qpkwik(const real_T b_Linv[256], const real_T
  b_Hinv[256], const real_T f[16], const real_T b_Ac[1280], const real_T b[80],
  int16_T iA[80], int16_T maxiter, real_T FeasTol, real_T x[16], real_T lambda
  [80], real_T *status)
{
  real_T D[256];
  real_T RLinv[256];
  real_T U[256];
  real_T b_H[256];
  real_T cTol[80];
  real_T tmp_2[80];
  real_T Opt[32];
  real_T Rhs[32];
  real_T b_Ac_0[16];
  real_T r[16];
  real_T z[16];
  real_T Xnorm0;
  real_T b_Ac_1;
  real_T cMin;
  real_T cVal;
  real_T rMin;
  real_T t;
  int32_T U_tmp;
  int32_T U_tmp_0;
  int32_T exitg1;
  int32_T exitg3;
  int32_T i;
  int32_T lambda_tmp_tmp;
  int32_T tmp;
  int16_T iC[80];
  int16_T kDrop;
  int16_T kNext;
  int16_T nA;
  int16_T tmp_0;
  int16_T tmp_1;
  uint16_T c_x;
  uint16_T q;
  boolean_T ColdReset;
  boolean_T DualFeasible;
  boolean_T cTolComputed;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0;
  memset(&lambda[0], 0, 80U * sizeof(real_T));
  memset(&x[0], 0, sizeof(real_T) << 4U);
  memset(&r[0], 0, sizeof(real_T) << 4U);
  rMin = 0.0;
  cTolComputed = false;
  for (i = 0; i < 80; i++) {
    cTol[i] = 1.0;
    iC[i] = 0;
  }

  nA = 0;
  for (i = 0; i < 80; i++) {
    if (iA[i] == 1) {
      U_tmp = nA + 1;
      if (nA + 1 > 32767) {
        U_tmp = 32767;
      }

      nA = (int16_T)U_tmp;
      iC[(int16_T)U_tmp - 1] = (int16_T)(i + 1);
    }
  }

  guard1 = false;
  if (nA > 0) {
    memset(&Opt[0], 0, sizeof(real_T) << 5U);
    for (i = 0; i < 16; i++) {
      Rhs[i] = f[i];
      Rhs[i + 16] = 0.0;
    }

    DualFeasible = false;
    U_tmp = 3 * nA;
    if (U_tmp > 32767) {
      U_tmp = 32767;
    }

    if ((int16_T)U_tmp >= 50) {
      kNext = (int16_T)U_tmp;
    } else {
      kNext = 50;
    }

    q = (uint16_T)(kNext / 10U);
    c_x = (uint16_T)((uint32_T)kNext - q * 10);
    if ((c_x > 0) && (c_x >= 5)) {
      q++;
    }

    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && ((int32_T)*status <= maxiter)) {
        Xnorm0 = reaction_pendulum_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D,
          b_H, 16);
        if (Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            memset(&iA[0], 0, 80U * sizeof(int16_T));
            memset(&iC[0], 0, 80U * sizeof(int16_T));
            ColdReset = true;
          }
        } else {
          for (i = 1; i - 1 < nA; i++) {
            U_tmp = (int16_T)i + 16;
            if ((int16_T)i + 16 > 32767) {
              U_tmp = 32767;
            }

            Rhs[U_tmp - 1] = b[iC[(int16_T)i - 1] - 1];
            for (kNext = (int16_T)i; kNext <= nA; kNext++) {
              U_tmp = ((((int16_T)i - 1) << 4) + kNext) - 1;
              U[U_tmp] = 0.0;
              for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
              {
                U_tmp_0 = ((int16_T)lambda_tmp_tmp - 1) << 4;
                U[U_tmp] += RLinv[(U_tmp_0 + kNext) - 1] * RLinv[(U_tmp_0 +
                  (int16_T)i) - 1];
              }

              U[((int16_T)i + ((kNext - 1) << 4)) - 1] = U[U_tmp];
            }
          }

          for (i = 0; i < 16; i++) {
            Xnorm0 = 0.0;
            for (U_tmp = 0; U_tmp < 16; U_tmp++) {
              Xnorm0 += b_H[(U_tmp << 4) + i] * Rhs[U_tmp];
            }

            Opt[i] = Xnorm0;
            for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
            {
              U_tmp = (int16_T)lambda_tmp_tmp + 16;
              if ((int16_T)lambda_tmp_tmp + 16 > 32767) {
                U_tmp = 32767;
              }

              Opt[i] += D[(((int16_T)lambda_tmp_tmp - 1) << 4) + i] * Rhs[U_tmp
                - 1];
            }
          }

          for (i = 1; i - 1 < nA; i++) {
            Xnorm0 = 0.0;
            for (U_tmp = 0; U_tmp < 16; U_tmp++) {
              Xnorm0 += D[(((int16_T)i - 1) << 4) + U_tmp] * Rhs[U_tmp];
            }

            U_tmp = (int16_T)i + 16;
            if ((int16_T)i + 16 > 32767) {
              U_tmp = 32767;
            }

            Opt[U_tmp - 1] = Xnorm0;
            for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
            {
              U_tmp = (int16_T)i + 16;
              if ((int16_T)i + 16 > 32767) {
                U_tmp = 32767;
              }

              U_tmp_0 = (int16_T)i + 16;
              if ((int16_T)i + 16 > 32767) {
                U_tmp_0 = 32767;
              }

              tmp = (int16_T)lambda_tmp_tmp + 16;
              if ((int16_T)lambda_tmp_tmp + 16 > 32767) {
                tmp = 32767;
              }

              Opt[U_tmp - 1] = U[((((int16_T)lambda_tmp_tmp - 1) << 4) +
                                  (int16_T)i) - 1] * Rhs[tmp - 1] + Opt[U_tmp_0
                - 1];
            }
          }

          Xnorm0 = -1.0E-12;
          kDrop = 0;
          for (i = 1; i - 1 < nA; i++) {
            U_tmp = (int16_T)i + 16;
            if ((int16_T)i + 16 > 32767) {
              U_tmp = 32767;
            }

            lambda[iC[(int16_T)i - 1] - 1] = Opt[U_tmp - 1];
            U_tmp = (int16_T)i + 16;
            if ((int16_T)i + 16 > 32767) {
              U_tmp = 32767;
            }

            if ((Opt[U_tmp - 1] < Xnorm0) && ((int16_T)i <= nA)) {
              kDrop = (int16_T)i;
              U_tmp = (int16_T)i + 16;
              if ((int16_T)i + 16 > 32767) {
                U_tmp = 32767;
              }

              Xnorm0 = Opt[U_tmp - 1];
            }
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            memcpy(&x[0], &Opt[0], sizeof(real_T) << 4U);
          } else {
            (*status)++;
            if ((int32_T)*status > q) {
              nA = 0;
              memset(&iA[0], 0, 80U * sizeof(int16_T));
              memset(&iC[0], 0, 80U * sizeof(int16_T));
              ColdReset = true;
            } else {
              lambda[iC[kDrop - 1] - 1] = 0.0;
              reaction_pendulu_DropConstraint(kDrop, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          memset(&lambda[0], 0, 80U * sizeof(real_T));
          reaction_pendulum_Unconstrained(b_Hinv, f, x, 16);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    reaction_pendulum_Unconstrained(b_Hinv, f, x, 16);
    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = reaction_pendulum_norm(x);
    exitg2 = false;
    while ((!exitg2) && ((int32_T)*status <= maxiter)) {
      cMin = -FeasTol;
      kNext = 0;
      for (i = 0; i < 80; i++) {
        t = cTol[i];
        if (!cTolComputed) {
          for (U_tmp = 0; U_tmp < 16; U_tmp++) {
            b_Ac_0[U_tmp] = b_Ac[80 * U_tmp + i] * x[U_tmp];
          }

          reaction_pendulum_abs(b_Ac_0, z);
          cVal = reaction_pendulum_maximum(z);
          if ((!(t >= cVal)) && (!rtIsNaN(cVal))) {
            t = cVal;
          }
        }

        if (iA[i] == 0) {
          b_Ac_1 = 0.0;
          for (U_tmp = 0; U_tmp < 16; U_tmp++) {
            b_Ac_1 += b_Ac[80 * U_tmp + i] * x[U_tmp];
          }

          cVal = (b_Ac_1 - b[i]) / t;
          if (cVal < cMin) {
            cMin = cVal;
            kNext = (int16_T)(i + 1);
          }
        }

        cTol[i] = t;
      }

      cTolComputed = true;
      if (kNext <= 0) {
        exitg2 = true;
      } else if ((int32_T)*status == maxiter) {
        *status = 0.0;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0;
          if ((kNext > 0) && ((int32_T)*status <= maxiter)) {
            guard2 = false;
            if (nA == 0) {
              for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                z[U_tmp] = 0.0;
                for (U_tmp_0 = 0; U_tmp_0 < 16; U_tmp_0++) {
                  z[U_tmp] += b_Ac[(80 * U_tmp_0 + kNext) - 1] * b_Hinv[(U_tmp_0
                    << 4) + U_tmp];
                }
              }

              guard2 = true;
            } else {
              cMin = reaction_pendulum_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D,
                b_H, 16);
              if (cMin <= 0.0) {
                *status = -2.0;
                exitg1 = 1;
              } else {
                for (U_tmp = 0; U_tmp < 256; U_tmp++) {
                  U[U_tmp] = -b_H[U_tmp];
                }

                for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                  z[U_tmp] = 0.0;
                  for (U_tmp_0 = 0; U_tmp_0 < 16; U_tmp_0++) {
                    z[U_tmp] += b_Ac[(80 * U_tmp_0 + kNext) - 1] * U[(U_tmp_0 <<
                      4) + U_tmp];
                  }
                }

                for (i = 1; i - 1 < nA; i++) {
                  b_Ac_1 = 0.0;
                  for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                    b_Ac_1 += b_Ac[(80 * U_tmp + kNext) - 1] * D[(((int16_T)i -
                      1) << 4) + U_tmp];
                  }

                  r[(int16_T)i - 1] = b_Ac_1;
                }

                guard2 = true;
              }
            }

            if (guard2) {
              kDrop = 0;
              cMin = 0.0;
              DualFeasible = true;
              ColdReset = true;
              if (nA > 0) {
                i = 0;
                exitg4 = false;
                while ((!exitg4) && (i <= nA - 1)) {
                  if (r[i] >= 1.0E-12) {
                    ColdReset = false;
                    exitg4 = true;
                  } else {
                    i++;
                  }
                }
              }

              if ((nA != 0) && (!ColdReset)) {
                for (i = 1; i - 1 < nA; i++) {
                  t = r[(int16_T)i - 1];
                  if (t > 1.0E-12) {
                    cVal = lambda[iC[(int16_T)i - 1] - 1] / t;
                    if ((kDrop == 0) || (cVal < rMin)) {
                      rMin = cVal;
                      kDrop = (int16_T)i;
                    }
                  }
                }

                if (kDrop > 0) {
                  cMin = rMin;
                  DualFeasible = false;
                }
              }

              for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                b_Ac_0[U_tmp] = b_Ac[(80 * U_tmp + kNext) - 1];
              }

              cVal = reaction_pendulum_mtimes(z, b_Ac_0);
              if (cVal <= 0.0) {
                cVal = 0.0;
                ColdReset = true;
              } else {
                b_Ac_1 = 0.0;
                for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                  b_Ac_1 += b_Ac[(80 * U_tmp + kNext) - 1] * x[U_tmp];
                }

                cVal = (b[kNext - 1] - b_Ac_1) / cVal;
                ColdReset = false;
              }

              if (DualFeasible && ColdReset) {
                *status = -1.0;
                exitg1 = 1;
              } else {
                if (ColdReset) {
                  t = cMin;
                } else if (DualFeasible) {
                  t = cVal;
                } else if ((cMin <= cVal) || rtIsNaN(cVal)) {
                  t = cMin;
                } else {
                  t = cVal;
                }

                for (i = 1; i - 1 < nA; i++) {
                  lambda_tmp_tmp = iC[(int16_T)i - 1];
                  lambda[lambda_tmp_tmp - 1] -= r[(int16_T)i - 1] * t;
                  if ((lambda_tmp_tmp <= 80) && (lambda[lambda_tmp_tmp - 1] <
                       0.0)) {
                    lambda[lambda_tmp_tmp - 1] = 0.0;
                  }
                }

                lambda[kNext - 1] += t;
                if (t == cMin) {
                  reaction_pendulu_DropConstraint(kDrop, iA, &nA, iC);
                }

                if (!ColdReset) {
                  for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                    x[U_tmp] += t * z[U_tmp];
                  }

                  if (t == cVal) {
                    if (nA == 16) {
                      *status = -1.0;
                      exitg1 = 1;
                    } else {
                      U_tmp = nA + 1;
                      if (nA + 1 > 32767) {
                        U_tmp = 32767;
                      }

                      nA = (int16_T)U_tmp;
                      iC[(int16_T)U_tmp - 1] = kNext;
                      kDrop = (int16_T)U_tmp;
                      exitg4 = false;
                      while ((!exitg4) && (kDrop > 1)) {
                        tmp_0 = iC[kDrop - 1];
                        tmp_1 = iC[kDrop - 2];
                        if (tmp_0 > tmp_1) {
                          exitg4 = true;
                        } else {
                          iC[kDrop - 1] = tmp_1;
                          iC[kDrop - 2] = tmp_0;
                          kDrop--;
                        }
                      }

                      iA[kNext - 1] = 1;
                      kNext = 0;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            cMin = reaction_pendulum_norm(x);
            if (fabs(cMin - Xnorm0) > 0.001) {
              Xnorm0 = cMin;
              reaction_pendulum_abs_j(b, tmp_2);
              reaction_pendulum_maximum2(tmp_2, 1.0, cTol);
              cTolComputed = false;
            }

            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S123>/optimizer' */
static void reaction_pendulum_abs_cd(const real_T x[110], real_T y[110])
{
  int32_T k;
  for (k = 0; k < 110; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Function for MATLAB Function: '<S123>/optimizer' */
static void reaction_pendulum_maximum2_h(const real_T x[110], real_T y, real_T
  ex[110])
{
  real_T u0;
  int32_T k;
  for (k = 0; k < 110; k++) {
    u0 = x[k];
    if ((u0 >= y) || rtIsNaN(y)) {
      ex[k] = u0;
    } else {
      ex[k] = y;
    }
  }
}

/* Function for MATLAB Function: '<S123>/optimizer' */
static real_T reaction_pendulum_KWIKfactor_l(const real_T b_Ac[1760], const
  int16_T iC[110], int16_T nA, const real_T b_Linv[256], real_T RLinv[256],
  real_T D[256], real_T b_H[256], int16_T n)
{
  real_T QQ[256];
  real_T RR[256];
  real_T TL[256];
  real_T Status;
  real_T b_Linv_0;
  int32_T exitg1;
  int32_T f_i;
  int32_T i;
  int32_T iC_0;
  int32_T i_0;
  int32_T tmp;
  int16_T b_j;
  int16_T c_k;
  Status = 1.0;
  memset(&RLinv[0], 0, sizeof(real_T) << 8U);
  for (i = 1; i - 1 < nA; i++) {
    iC_0 = iC[(int16_T)i - 1];
    for (i_0 = 0; i_0 < 16; i_0++) {
      tmp = (((int16_T)i - 1) << 4) + i_0;
      RLinv[tmp] = 0.0;
      for (f_i = 0; f_i < 16; f_i++) {
        RLinv[tmp] += b_Ac[(110 * f_i + iC_0) - 1] * b_Linv[(f_i << 4) + i_0];
      }
    }
  }

  reaction_pendulum_qr(RLinv, QQ, RR);
  i = 1;
  do {
    exitg1 = 0;
    if (i - 1 <= nA - 1) {
      if (fabs(RR[((((int16_T)i - 1) << 4) + (int16_T)i) - 1]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      for (i = 1; i - 1 < n; i++) {
        for (f_i = 1; f_i - 1 < n; f_i++) {
          b_Linv_0 = 0.0;
          for (i_0 = 0; i_0 < 16; i_0++) {
            b_Linv_0 += b_Linv[(((int16_T)i - 1) << 4) + i_0] * QQ[(((int16_T)
              f_i - 1) << 4) + i_0];
          }

          TL[((int16_T)i + (((int16_T)f_i - 1) << 4)) - 1] = b_Linv_0;
        }
      }

      memset(&RLinv[0], 0, sizeof(real_T) << 8U);
      for (b_j = nA; b_j > 0; b_j--) {
        i_0 = (b_j - 1) << 4;
        tmp = (b_j + i_0) - 1;
        RLinv[tmp] = 1.0;
        for (c_k = b_j; c_k <= nA; c_k++) {
          f_i = (((c_k - 1) << 4) + b_j) - 1;
          RLinv[f_i] /= RR[tmp];
        }

        if (b_j > 1) {
          for (i = 1; i - 1 <= b_j - 2; i++) {
            for (c_k = b_j; c_k <= nA; c_k++) {
              tmp = (c_k - 1) << 4;
              f_i = (tmp + (int16_T)i) - 1;
              RLinv[f_i] -= RR[(i_0 + (int16_T)i) - 1] * RLinv[(tmp + b_j) - 1];
            }
          }
        }
      }

      for (i = 1; i - 1 < n; i++) {
        for (b_j = (int16_T)i; b_j <= n; b_j++) {
          i_0 = (((b_j - 1) << 4) + (int16_T)i) - 1;
          b_H[i_0] = 0.0;
          tmp = nA + 1;
          if (nA + 1 > 32767) {
            tmp = 32767;
          }

          for (c_k = (int16_T)tmp; c_k <= n; c_k++) {
            tmp = (c_k - 1) << 4;
            b_H[i_0] -= TL[(tmp + (int16_T)i) - 1] * TL[(tmp + b_j) - 1];
          }

          b_H[(b_j + (((int16_T)i - 1) << 4)) - 1] = b_H[i_0];
        }
      }

      for (i = 1; i - 1 < nA; i++) {
        for (f_i = 1; f_i - 1 < n; f_i++) {
          i_0 = ((((int16_T)i - 1) << 4) + (int16_T)f_i) - 1;
          D[i_0] = 0.0;
          for (b_j = (int16_T)i; b_j <= nA; b_j++) {
            tmp = (b_j - 1) << 4;
            D[i_0] += TL[(tmp + (int16_T)f_i) - 1] * RLinv[(tmp + (int16_T)i) -
              1];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

/* Function for MATLAB Function: '<S123>/optimizer' */
static void reaction_pendu_DropConstraint_n(int16_T kDrop, int16_T iA[110],
  int16_T *nA, int16_T iC[110])
{
  int32_T tmp;
  int16_T i;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (*nA - 1 < -32768) {
      tmp = -32768;
    }

    for (i = kDrop; i <= (int16_T)tmp; i++) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  tmp = *nA - 1;
  if (*nA - 1 < -32768) {
    tmp = -32768;
  }

  *nA = (int16_T)tmp;
}

/* Function for MATLAB Function: '<S123>/optimizer' */
static void reaction_pendulum_qpkwik_j(const real_T b_Linv[256], const real_T
  b_Hinv[256], const real_T f[16], const real_T b_Ac[1760], const real_T b[110],
  int16_T iA[110], int16_T maxiter, real_T FeasTol, real_T x[16], real_T lambda
  [110], real_T *status)
{
  real_T D[256];
  real_T RLinv[256];
  real_T U[256];
  real_T b_H[256];
  real_T cTol[110];
  real_T tmp_2[110];
  real_T Opt[32];
  real_T Rhs[32];
  real_T b_Ac_0[16];
  real_T r[16];
  real_T z[16];
  real_T Xnorm0;
  real_T b_Ac_1;
  real_T cMin;
  real_T cVal;
  real_T rMin;
  real_T t;
  int32_T U_tmp;
  int32_T U_tmp_0;
  int32_T exitg1;
  int32_T exitg3;
  int32_T i;
  int32_T lambda_tmp_tmp;
  int32_T tmp;
  int16_T iC[110];
  int16_T kDrop;
  int16_T kNext;
  int16_T nA;
  int16_T tmp_0;
  int16_T tmp_1;
  uint16_T c_x;
  uint16_T q;
  boolean_T ColdReset;
  boolean_T DualFeasible;
  boolean_T cTolComputed;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0;
  memset(&lambda[0], 0, 110U * sizeof(real_T));
  memset(&x[0], 0, sizeof(real_T) << 4U);
  memset(&r[0], 0, sizeof(real_T) << 4U);
  rMin = 0.0;
  cTolComputed = false;
  for (i = 0; i < 110; i++) {
    cTol[i] = 1.0;
    iC[i] = 0;
  }

  nA = 0;
  for (i = 0; i < 110; i++) {
    if (iA[i] == 1) {
      U_tmp = nA + 1;
      if (nA + 1 > 32767) {
        U_tmp = 32767;
      }

      nA = (int16_T)U_tmp;
      iC[(int16_T)U_tmp - 1] = (int16_T)(i + 1);
    }
  }

  guard1 = false;
  if (nA > 0) {
    memset(&Opt[0], 0, sizeof(real_T) << 5U);
    for (i = 0; i < 16; i++) {
      Rhs[i] = f[i];
      Rhs[i + 16] = 0.0;
    }

    DualFeasible = false;
    U_tmp = 3 * nA;
    if (U_tmp > 32767) {
      U_tmp = 32767;
    }

    if ((int16_T)U_tmp >= 50) {
      kNext = (int16_T)U_tmp;
    } else {
      kNext = 50;
    }

    q = (uint16_T)(kNext / 10U);
    c_x = (uint16_T)((uint32_T)kNext - q * 10);
    if ((c_x > 0) && (c_x >= 5)) {
      q++;
    }

    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && ((int32_T)*status <= maxiter)) {
        Xnorm0 = reaction_pendulum_KWIKfactor_l(b_Ac, iC, nA, b_Linv, RLinv, D,
          b_H, 16);
        if (Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            memset(&iA[0], 0, 110U * sizeof(int16_T));
            memset(&iC[0], 0, 110U * sizeof(int16_T));
            ColdReset = true;
          }
        } else {
          for (i = 1; i - 1 < nA; i++) {
            U_tmp = (int16_T)i + 16;
            if ((int16_T)i + 16 > 32767) {
              U_tmp = 32767;
            }

            Rhs[U_tmp - 1] = b[iC[(int16_T)i - 1] - 1];
            for (kNext = (int16_T)i; kNext <= nA; kNext++) {
              U_tmp = ((((int16_T)i - 1) << 4) + kNext) - 1;
              U[U_tmp] = 0.0;
              for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
              {
                U_tmp_0 = ((int16_T)lambda_tmp_tmp - 1) << 4;
                U[U_tmp] += RLinv[(U_tmp_0 + kNext) - 1] * RLinv[(U_tmp_0 +
                  (int16_T)i) - 1];
              }

              U[((int16_T)i + ((kNext - 1) << 4)) - 1] = U[U_tmp];
            }
          }

          for (i = 0; i < 16; i++) {
            Xnorm0 = 0.0;
            for (U_tmp = 0; U_tmp < 16; U_tmp++) {
              Xnorm0 += b_H[(U_tmp << 4) + i] * Rhs[U_tmp];
            }

            Opt[i] = Xnorm0;
            for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
            {
              U_tmp = (int16_T)lambda_tmp_tmp + 16;
              if ((int16_T)lambda_tmp_tmp + 16 > 32767) {
                U_tmp = 32767;
              }

              Opt[i] += D[(((int16_T)lambda_tmp_tmp - 1) << 4) + i] * Rhs[U_tmp
                - 1];
            }
          }

          for (i = 1; i - 1 < nA; i++) {
            Xnorm0 = 0.0;
            for (U_tmp = 0; U_tmp < 16; U_tmp++) {
              Xnorm0 += D[(((int16_T)i - 1) << 4) + U_tmp] * Rhs[U_tmp];
            }

            U_tmp = (int16_T)i + 16;
            if ((int16_T)i + 16 > 32767) {
              U_tmp = 32767;
            }

            Opt[U_tmp - 1] = Xnorm0;
            for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
            {
              U_tmp = (int16_T)i + 16;
              if ((int16_T)i + 16 > 32767) {
                U_tmp = 32767;
              }

              U_tmp_0 = (int16_T)i + 16;
              if ((int16_T)i + 16 > 32767) {
                U_tmp_0 = 32767;
              }

              tmp = (int16_T)lambda_tmp_tmp + 16;
              if ((int16_T)lambda_tmp_tmp + 16 > 32767) {
                tmp = 32767;
              }

              Opt[U_tmp - 1] = U[((((int16_T)lambda_tmp_tmp - 1) << 4) +
                                  (int16_T)i) - 1] * Rhs[tmp - 1] + Opt[U_tmp_0
                - 1];
            }
          }

          Xnorm0 = -1.0E-12;
          kDrop = 0;
          for (i = 1; i - 1 < nA; i++) {
            U_tmp = (int16_T)i + 16;
            if ((int16_T)i + 16 > 32767) {
              U_tmp = 32767;
            }

            lambda[iC[(int16_T)i - 1] - 1] = Opt[U_tmp - 1];
            U_tmp = (int16_T)i + 16;
            if ((int16_T)i + 16 > 32767) {
              U_tmp = 32767;
            }

            if ((Opt[U_tmp - 1] < Xnorm0) && ((int16_T)i <= nA)) {
              kDrop = (int16_T)i;
              U_tmp = (int16_T)i + 16;
              if ((int16_T)i + 16 > 32767) {
                U_tmp = 32767;
              }

              Xnorm0 = Opt[U_tmp - 1];
            }
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            memcpy(&x[0], &Opt[0], sizeof(real_T) << 4U);
          } else {
            (*status)++;
            if ((int32_T)*status > q) {
              nA = 0;
              memset(&iA[0], 0, 110U * sizeof(int16_T));
              memset(&iC[0], 0, 110U * sizeof(int16_T));
              ColdReset = true;
            } else {
              lambda[iC[kDrop - 1] - 1] = 0.0;
              reaction_pendu_DropConstraint_n(kDrop, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          memset(&lambda[0], 0, 110U * sizeof(real_T));
          reaction_pendulum_Unconstrained(b_Hinv, f, x, 16);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    reaction_pendulum_Unconstrained(b_Hinv, f, x, 16);
    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = reaction_pendulum_norm(x);
    exitg2 = false;
    while ((!exitg2) && ((int32_T)*status <= maxiter)) {
      cMin = -FeasTol;
      kNext = 0;
      for (i = 0; i < 110; i++) {
        t = cTol[i];
        if (!cTolComputed) {
          for (U_tmp = 0; U_tmp < 16; U_tmp++) {
            b_Ac_0[U_tmp] = b_Ac[110 * U_tmp + i] * x[U_tmp];
          }

          reaction_pendulum_abs(b_Ac_0, z);
          cVal = reaction_pendulum_maximum(z);
          if ((!(t >= cVal)) && (!rtIsNaN(cVal))) {
            t = cVal;
          }
        }

        if (iA[i] == 0) {
          b_Ac_1 = 0.0;
          for (U_tmp = 0; U_tmp < 16; U_tmp++) {
            b_Ac_1 += b_Ac[110 * U_tmp + i] * x[U_tmp];
          }

          cVal = (b_Ac_1 - b[i]) / t;
          if (cVal < cMin) {
            cMin = cVal;
            kNext = (int16_T)(i + 1);
          }
        }

        cTol[i] = t;
      }

      cTolComputed = true;
      if (kNext <= 0) {
        exitg2 = true;
      } else if ((int32_T)*status == maxiter) {
        *status = 0.0;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0;
          if ((kNext > 0) && ((int32_T)*status <= maxiter)) {
            guard2 = false;
            if (nA == 0) {
              for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                z[U_tmp] = 0.0;
                for (U_tmp_0 = 0; U_tmp_0 < 16; U_tmp_0++) {
                  z[U_tmp] += b_Ac[(110 * U_tmp_0 + kNext) - 1] * b_Hinv
                    [(U_tmp_0 << 4) + U_tmp];
                }
              }

              guard2 = true;
            } else {
              cMin = reaction_pendulum_KWIKfactor_l(b_Ac, iC, nA, b_Linv, RLinv,
                D, b_H, 16);
              if (cMin <= 0.0) {
                *status = -2.0;
                exitg1 = 1;
              } else {
                for (U_tmp = 0; U_tmp < 256; U_tmp++) {
                  U[U_tmp] = -b_H[U_tmp];
                }

                for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                  z[U_tmp] = 0.0;
                  for (U_tmp_0 = 0; U_tmp_0 < 16; U_tmp_0++) {
                    z[U_tmp] += b_Ac[(110 * U_tmp_0 + kNext) - 1] * U[(U_tmp_0 <<
                      4) + U_tmp];
                  }
                }

                for (i = 1; i - 1 < nA; i++) {
                  b_Ac_1 = 0.0;
                  for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                    b_Ac_1 += b_Ac[(110 * U_tmp + kNext) - 1] * D[(((int16_T)i -
                      1) << 4) + U_tmp];
                  }

                  r[(int16_T)i - 1] = b_Ac_1;
                }

                guard2 = true;
              }
            }

            if (guard2) {
              kDrop = 0;
              cMin = 0.0;
              DualFeasible = true;
              ColdReset = true;
              if (nA > 0) {
                i = 0;
                exitg4 = false;
                while ((!exitg4) && (i <= nA - 1)) {
                  if (r[i] >= 1.0E-12) {
                    ColdReset = false;
                    exitg4 = true;
                  } else {
                    i++;
                  }
                }
              }

              if ((nA != 0) && (!ColdReset)) {
                for (i = 1; i - 1 < nA; i++) {
                  t = r[(int16_T)i - 1];
                  if (t > 1.0E-12) {
                    cVal = lambda[iC[(int16_T)i - 1] - 1] / t;
                    if ((kDrop == 0) || (cVal < rMin)) {
                      rMin = cVal;
                      kDrop = (int16_T)i;
                    }
                  }
                }

                if (kDrop > 0) {
                  cMin = rMin;
                  DualFeasible = false;
                }
              }

              for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                b_Ac_0[U_tmp] = b_Ac[(110 * U_tmp + kNext) - 1];
              }

              cVal = reaction_pendulum_mtimes(z, b_Ac_0);
              if (cVal <= 0.0) {
                cVal = 0.0;
                ColdReset = true;
              } else {
                b_Ac_1 = 0.0;
                for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                  b_Ac_1 += b_Ac[(110 * U_tmp + kNext) - 1] * x[U_tmp];
                }

                cVal = (b[kNext - 1] - b_Ac_1) / cVal;
                ColdReset = false;
              }

              if (DualFeasible && ColdReset) {
                *status = -1.0;
                exitg1 = 1;
              } else {
                if (ColdReset) {
                  t = cMin;
                } else if (DualFeasible) {
                  t = cVal;
                } else if ((cMin <= cVal) || rtIsNaN(cVal)) {
                  t = cMin;
                } else {
                  t = cVal;
                }

                for (i = 1; i - 1 < nA; i++) {
                  lambda_tmp_tmp = iC[(int16_T)i - 1];
                  lambda[lambda_tmp_tmp - 1] -= r[(int16_T)i - 1] * t;
                  if ((lambda_tmp_tmp <= 110) && (lambda[lambda_tmp_tmp - 1] <
                       0.0)) {
                    lambda[lambda_tmp_tmp - 1] = 0.0;
                  }
                }

                lambda[kNext - 1] += t;
                if (t == cMin) {
                  reaction_pendu_DropConstraint_n(kDrop, iA, &nA, iC);
                }

                if (!ColdReset) {
                  for (U_tmp = 0; U_tmp < 16; U_tmp++) {
                    x[U_tmp] += t * z[U_tmp];
                  }

                  if (t == cVal) {
                    if (nA == 16) {
                      *status = -1.0;
                      exitg1 = 1;
                    } else {
                      U_tmp = nA + 1;
                      if (nA + 1 > 32767) {
                        U_tmp = 32767;
                      }

                      nA = (int16_T)U_tmp;
                      iC[(int16_T)U_tmp - 1] = kNext;
                      kDrop = (int16_T)U_tmp;
                      exitg4 = false;
                      while ((!exitg4) && (kDrop > 1)) {
                        tmp_0 = iC[kDrop - 1];
                        tmp_1 = iC[kDrop - 2];
                        if (tmp_0 > tmp_1) {
                          exitg4 = true;
                        } else {
                          iC[kDrop - 1] = tmp_1;
                          iC[kDrop - 2] = tmp_0;
                          kDrop--;
                        }
                      }

                      iA[kNext - 1] = 1;
                      kNext = 0;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            cMin = reaction_pendulum_norm(x);
            if (fabs(cMin - Xnorm0) > 0.001) {
              Xnorm0 = cMin;
              reaction_pendulum_abs_cd(b, tmp_2);
              reaction_pendulum_maximum2_h(tmp_2, 1.0, cTol);
              cTolComputed = false;
            }

            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }
  }
}

/* Model step function */
void reaction_pendulum_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;
  real_T rtb_uT;
  real_T rtb_DCAnglerad;
  real_T rtb_Add_i[3];
  real_T a_0[300];
  real_T a__1_0[110];
  real_T b_Mlim_0[110];
  real_T yseq_0[84];
  real_T a__1[80];
  real_T b_Mlim[80];
  real_T yseq[63];
  real_T rseq[60];
  real_T uopt_dim[20];
  real_T f[16];
  real_T zopt[16];
  real_T c_A_0[7];
  real_T rtb_xest[7];
  real_T c_A[6];
  real_T rtb_xest_j[6];
  real_T b_C[4];
  real_T rtb_Bkuk[3];
  real_T tmp[3];
  real_T rtb_Integrator;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_TmpSignalConversionAtSFun_1;
  real_T rtb_last_mv;
  int32_T a_tmp;
  int32_T i1;
  int32_T ibcol;
  int32_T kidx;
  int16_T iAnew_0[110];
  int16_T iAnew[80];
  int8_T a[400];
  static const real_T b_Kx[90] = { -2.0605192857047534E+9,
    -5.5315191000229275E+8, 1.2126505177250742E+6, -4.5286675019904792E+8,
    -29431.505527935082, 292.22710508104183, -1.7438433234256437E+9,
    -4.6860497762594533E+8, 1.029495578187024E+6, -3.7767642922610176E+8,
    -25241.568413396442, 267.89178765029942, -1.4679311122695122E+9,
    -3.9481882309430528E+8, 869378.73315172142, -3.1300588295946455E+8,
    -21573.559934286237, 244.315468046119, -1.2280315606579998E+9,
    -3.3056652481042826E+8, 729664.88475840527, -2.5757250488811016E+8,
    -18365.572335435965, 221.53387706885673, -1.0199742629519674E+9,
    -2.7476616927026707E+8, 608042.406808747, -2.1024469550316024E+8,
    -15563.123713449968, 199.58442759232054, -8.400976764331243E+8,
    -2.2646385789631641E+8, 502482.7219215114, -1.7002364325818193E+8,
    -13118.28264864365, 178.50629374954474, -6.8518572935087562E+8,
    -1.8481851013141149E+8, 411204.66607981978, -1.3602723574325916E+8,
    -10988.899490779428, 158.3404938463367, -5.5241165592927349E+8,
    -1.4908823235617796E+8, 332642.92977552721, -1.0747583764161466E+8,
    -9137.9321384294944, 139.12997717808565, -4.3928797370334488E+8,
    -1.1861803580986856E+8, 265419.93605594628, -8.3679701172596574E+7,
    -7532.8557346579455, 120.91971493358457, -3.4362161220983297E+8,
    -9.2828696969958141E+7, 208320.57044357821, -6.4027799841281153E+7,
    -6145.1471280439073, 103.75679537826657, -2.6347327115291688E+8,
    -7.1206560408915162E+7, 160269.21677779345, -4.7977897760280348E+7,
    -4949.8362442747875, 87.6905235183148, -1.9712013116117778E+8,
    -5.329408654733938E+7, 120308.57682708488, -3.5047684857936867E+7,
    -3925.1177047590845, 72.77252545658861, -1.4302106078728992E+8,
    -3.8680944400479138E+7, 87579.759800366621, -2.4806823141221151E+7,
    -3052.0171394005706, 59.056857661239412, -9.9783458238064289E+7,
    -2.6995441661226168E+7, 61303.1198217207, -1.6869760970616851E+7,
    -2314.1076952643643, 46.600121378287405, -6.6130833249577239E+7,
    -1.7896070377216004E+7, 40759.293559784761, -1.0889181081330907E+7,
    -1697.2732664389205, 35.461582430317648 };

  static const real_T b_Linv[256] = { 3.5039731319287627E-5,
    -0.0016596265616186316, 0.0055926499784776929, 0.00169551942603511,
    -6.997754554531736E-5, -0.00064660956671115947, -0.00065440482004552717,
    -0.00046874917454976935, -0.00027072035371990955, -0.00012625854924745169,
    -4.24471466549571E-5, -3.6624115104720077E-6, 8.8461128264121786E-6,
    9.1975002444719313E-6, 5.6643673544494385E-6, 0.0, 0.0,
    0.0019532467783578652, -0.012806383860152572, 0.0020595522197792353,
    0.0018663850778424739, 0.0012389804565077634, 0.00066674888033923043,
    0.00028109783849930364, 7.0309951043275186E-5, -1.9573968895068421E-5,
    -4.2332188366070857E-5, -3.6152079850851438E-5, -2.2480353492880805E-5,
    -1.0627695113129198E-5, -3.0407372639681258E-6, 0.0, 0.0, 0.0,
    0.0073636843874090325, -0.011295623702826474, 0.0019029370060991346,
    0.0014182674869215276, 0.000840066055135982, 0.00040065243867131145,
    0.00013569223939984609, 7.5958539761067629E-6, -3.6501507352467081E-5,
    -3.954894073385029E-5, -2.8269564031743853E-5, -1.5814343696091025E-5,
    -6.8100928121790069E-6, 0.0, 0.0, 0.0, 0.0, 0.00773437844084652,
    -0.01130245847140628, 0.00158041938853681, 0.0011499810970351562,
    0.00066934807440327743, 0.00031106171026553861, 9.9490855952530491E-5,
    1.392127995918309E-7, -3.2163657803470728E-5, -3.2748979285822605E-5,
    -2.2905147887105128E-5, -1.2742417321462376E-5, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0078215154735207411, -0.01131268327580257, 0.0013944019950861298,
    0.0010373771940803702, 0.0006125013755478104, 0.00028943967285874941,
    9.6687680532621268E-5, 5.0044155550158968E-6, -2.5895081908716387E-5,
    -2.77708396084195E-5, -1.9823311104807375E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0079620533217326182, -0.011234426945843794, 0.0012951615675099034,
    0.00098204683604342772, 0.00058722938648181485, 0.00028235589134011042,
    9.8718137481398877E-5, 1.0172501086540752E-5, -2.0800788492419317E-5,
    -2.3994681605335393E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0081098439728405462, -0.011143136153794853, 0.0012154972552667425,
    0.00093373368351293317, 0.0005634657959650175, 0.00027468362244708385,
    9.9595708998639662E-5, 1.4282935181945439E-5, -1.6452580881460192E-5, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0082452920468381475,
    -0.011059869469872188, 0.0011295922737650152, 0.00087909179118592757,
    0.00053521499105703212, 0.00026421593627575321, 9.8798777568705629E-5,
    1.7370923219129093E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.00837971783077773, -0.010975542585413313, 0.0010337220796299833,
    0.00081718612826614772, 0.00050225501187458655, 0.00025077204707491012,
    9.60402058521075E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0085269223615954872, -0.010878441089397107, 0.00092960507400124623,
    0.00074896865098858284, 0.00046477965934864281, 0.00023407707741636421, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0086957321850795032,
    -0.010760148761288625, 0.00081959273217671873, 0.00067561744064197028,
    0.00042319447635954529, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0088920429100560021, -0.010613448023829967,
    0.0007069889267483549, 0.00059928762959891618, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0091211935225689253,
    -0.010430190807730517, 0.00059707433368894546, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0093888121477958275,
    -0.010200607705968333, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0097009122540006269, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.003162277660168379 };

  static const real_T b_Hinv[256] = { 3.807032109588675E-5,
    -7.2886049086127042E-5, 2.0206349385405945E-5, 1.1719250401946525E-5,
    5.1617056396851411E-6, 1.2438305911704603E-6, -5.547411298325585E-7,
    -1.0493934822974237E-6, -9.2238202830645618E-7, -6.0601648816864838E-7,
    -3.1383959632207462E-7, -1.1655696288982894E-7, -1.1862527127878361E-8,
    2.8573612739420763E-8, 5.4949530679939672E-8, 0.0, -7.2886049086127042E-5,
    0.00017761148496818623, -0.00011157135010792629, -2.2302753297023456E-6,
    1.8371498179740766E-6, 2.7804509800316968E-6, 2.3059787422014128E-6,
    1.4543987814245493E-6, 7.1646175155417967E-7, 2.3750696394838865E-7,
    -5.999429340500016E-9, -9.22077209565236E-8, -9.6014312963808333E-8,
    -6.8764065014559441E-8, -2.9497925385224731E-8, 0.0, 2.0206349385405945E-5,
    -0.00011157135010792629, 0.00018833631005913632, -0.00010535119533025154,
    5.0934712256829768E-7, 2.4972810840291081E-6, 2.485945852717182E-6,
    1.7489327620560003E-6, 9.6482443108854444E-7, 3.9496656941953424E-7,
    7.14091840616352E-8, -6.6895099801100368E-8, -9.6971673711121516E-8,
    -7.9010816985005045E-8, -6.6064112812548924E-8, 0.0, 1.1719250401946525E-5,
    -2.2302753297023456E-6, -0.00010535119533025154, 0.00019194383802492181,
    -0.00010376232388941706, 8.92133069940241E-7, 2.3263876064781183E-6,
    2.16282330264339E-6, 1.4650873517846487E-6, 7.787803731890295E-7,
    2.995878364667235E-7, 3.7748905157086981E-8, -6.741288512259566E-8,
    -8.5071730407539085E-8, -1.2361307233936421E-7, 0.0, 5.1617056396851411E-6,
    1.8371498179740766E-6, 5.0934712256829768E-7, -0.00010376232388941706,
    0.00019264355711732292, -0.00010359386695406578, 8.16705900154641E-7,
    2.1839872993881096E-6, 2.0379950520026657E-6, 1.3839284035143726E-6,
    7.3854691939798653E-7, 2.8782204255347509E-7, 4.1625112365108403E-8,
    -5.8525376256512775E-8, -1.9230420161149258E-7, 0.0, 1.2438305911704603E-6,
    2.7804509800316968E-6, 2.4972810840291081E-6, 8.92133069940241E-7,
    -0.00010359386695406578, 0.00019268392174346782, -0.000103612295292885,
    7.8227333790702486E-7, 2.1542513348468853E-6, 2.0197708343714083E-6,
    1.3771988829924362E-6, 7.4075495993703512E-7, 2.9541493541447554E-7,
    4.9465638404282696E-8, -2.3277030081604154E-7, 0.0, -5.547411298325585E-7,
    2.3059787422014128E-6, 2.485945852717182E-6, 2.3263876064781183E-6,
    8.16705900154641E-7, -0.000103612295292885, 0.00019269168356568484,
    -0.00010359712147340968, 7.9624899236498263E-7, 2.16497375711015E-6,
    2.0284260953570424E-6, 1.3856827254534005E-6, 7.4963458278465233E-7,
    3.0192611866491986E-7, -1.5960504348289362E-7, 0.0, -1.0493934822974237E-6,
    1.4543987814245493E-6, 1.7489327620560003E-6, 2.16282330264339E-6,
    2.1839872993881096E-6, 7.8227333790702486E-7, -0.00010359712147340968,
    0.00019272066280560021, -0.0001035712185897689, 8.1421117791559229E-7,
    2.1760047763012337E-6, 2.0351723809713763E-6, 1.3898463173123819E-6,
    7.5040918977560883E-7, 1.6851380191975344E-7, 0.0, -9.2238202830645618E-7,
    7.1646175155417967E-7, 9.6482443108854444E-7, 1.4650873517846487E-6,
    2.0379950520026657E-6, 2.1542513348468853E-6, 7.9624899236498263E-7,
    -0.0001035712185897689, 0.00019274295091150793, -0.00010355801606101858,
    8.1764026314661268E-7, 2.1706454225373664E-6, 2.0229080026682617E-6,
    1.3747831780067506E-6, 9.316776098274524E-7, 0.0, -6.0601648816864838E-7,
    2.3750696394838865E-7, 3.9496656941953424E-7, 7.787803731890295E-7,
    1.3839284035143726E-6, 2.0197708343714083E-6, 2.16497375711015E-6,
    8.1421117791559229E-7, -0.00010355801606101858, 0.00019274481733984902,
    -0.00010357177655696888, 7.8582192808515348E-7, 2.1235088924761449E-6,
    1.9760004720570335E-6, 2.270761188689061E-6, 0.0, -3.1383959632207462E-7,
    -5.999429340500016E-9, 7.14091840616352E-8, 2.995878364667235E-7,
    7.3854691939798653E-7, 1.3771988829924362E-6, 2.0284260953570424E-6,
    2.1760047763012337E-6, 8.1764026314661268E-7, -0.00010357177655696888,
    0.0001927038443372464, -0.00010364714010378199, 6.81523660941777E-7,
    2.0264043972856461E-6, 4.1053724815416913E-6, 0.0, -1.1655696288982894E-7,
    -9.22077209565236E-8, -6.6895099801100368E-8, 3.7748905157086981E-8,
    2.8782204255347509E-7, 7.4075495993703512E-7, 1.3856827254534005E-6,
    2.0351723809713763E-6, 2.1706454225373664E-6, 7.8582192808515348E-7,
    -0.00010364714010378199, 0.00019257268507435251, -0.00010382352350988701,
    5.2468821123388776E-7, 5.8136367096471152E-6, 0.0, -1.1862527127878361E-8,
    -9.6014312963808333E-8, -9.6971673711121516E-8, -6.741288512259566E-8,
    4.1625112365108403E-8, 2.9541493541447554E-7, 7.4963458278465233E-7,
    1.3898463173123819E-6, 2.0229080026682617E-6, 2.1235088924761449E-6,
    6.81523660941777E-7, -0.00010382352350988701, 0.00019234154932176958,
    -0.00010401762320871202, 5.79216572023235E-6, 0.0, 2.8573612739420763E-8,
    -6.8764065014559441E-8, -7.9010816985005045E-8, -8.5071730407539085E-8,
    -5.8525376256512775E-8, 4.9465638404282696E-8, 3.0192611866491986E-7,
    7.5040918977560883E-7, 1.3747831780067506E-6, 1.9760004720570335E-6,
    2.0264043972856461E-6, 5.2468821123388776E-7, -0.00010401762320871202,
    0.000192202191117659, -9.8955200293081427E-5, 0.0, 5.4949530679939672E-8,
    -2.9497925385224731E-8, -6.6064112812548924E-8, -1.2361307233936421E-7,
    -1.9230420161149258E-7, -2.3277030081604154E-7, -1.5960504348289362E-7,
    1.6851380191975344E-7, 9.316776098274524E-7, 2.270761188689061E-6,
    4.1053724815416913E-6, 5.8136367096471152E-6, 5.79216572023235E-6,
    -9.8955200293081427E-5, 9.4107698559819526E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.9999999999999974E-6 };

  static const real_T b_Ac[1280] = { 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989,
    0.6419960832400321, -178.51413177724191, 0.78607605325261687,
    -190.69910617020003, 0.95184545876072357, -202.33624716112328,
    1.14205592406578, -213.45018520278953, 1.3598563005969111,
    -224.0644433689782, 1.6088420897991329, -234.20148714195321,
    1.893112375397997, -243.88277196151304, 2.2173351228541769,
    -253.12878863624749, 2.5868218506654892, -261.95910671311555,
    3.007612838917848, -270.39241589713794, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
    202.33624716112328, -1.14205592406578, 213.45018520278953,
    -1.3598563005969111, 224.0644433689782, -1.6088420897991329,
    234.20148714195321, -1.893112375397997, 243.88277196151304,
    -2.2173351228541769, 253.12878863624749, -2.5868218506654892,
    261.95910671311555, -3.007612838917848, 270.39241589713794, -0.0, -0.0,
    0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014,
    0.23922319557143779, -123.76154386633067, 0.317482486824172,
    -138.40818092168897, 0.40963446866862863, -152.39630883721321,
    0.5172085160937393, -165.75553401917989, 0.6419960832400321,
    -178.51413177724191, 0.78607605325261687, -190.69910617020003,
    0.95184545876072357, -202.33624716112328, 1.14205592406578,
    -213.45018520278953, 1.3598563005969111, -224.0644433689782,
    1.6088420897991329, -234.20148714195321, 1.893112375397997,
    -243.88277196151304, 2.2173351228541769, -253.12878863624749,
    2.5868218506654892, -261.95910671311555, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
    202.33624716112328, -1.14205592406578, 213.45018520278953,
    -1.3598563005969111, 224.0644433689782, -1.6088420897991329,
    234.20148714195321, -1.893112375397997, 243.88277196151304,
    -2.2173351228541769, 253.12878863624749, -2.5868218506654892,
    261.95910671311555, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897,
    0.40963446866862863, -152.39630883721321, 0.5172085160937393,
    -165.75553401917989, 0.6419960832400321, -178.51413177724191,
    0.78607605325261687, -190.69910617020003, 0.95184545876072357,
    -202.33624716112328, 1.14205592406578, -213.45018520278953,
    1.3598563005969111, -224.0644433689782, 1.6088420897991329,
    -234.20148714195321, 1.893112375397997, -243.88277196151304,
    2.2173351228541769, -253.12878863624749, 0.0, 0.0, 0.0, 0.0,
    -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321,
    -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
    178.51413177724191, -0.78607605325261687, 190.69910617020003,
    -0.95184545876072357, 202.33624716112328, -1.14205592406578,
    213.45018520278953, -1.3598563005969111, 224.0644433689782,
    -1.6088420897991329, 234.20148714195321, -1.893112375397997,
    243.88277196151304, -2.2173351228541769, 253.12878863624749, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989,
    0.6419960832400321, -178.51413177724191, 0.78607605325261687,
    -190.69910617020003, 0.95184545876072357, -202.33624716112328,
    1.14205592406578, -213.45018520278953, 1.3598563005969111,
    -224.0644433689782, 1.6088420897991329, -234.20148714195321,
    1.893112375397997, -243.88277196151304, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321,
    -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
    178.51413177724191, -0.78607605325261687, 190.69910617020003,
    -0.95184545876072357, 202.33624716112328, -1.14205592406578,
    213.45018520278953, -1.3598563005969111, 224.0644433689782,
    -1.6088420897991329, 234.20148714195321, -1.893112375397997,
    243.88277196151304, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014,
    0.23922319557143779, -123.76154386633067, 0.317482486824172,
    -138.40818092168897, 0.40963446866862863, -152.39630883721321,
    0.5172085160937393, -165.75553401917989, 0.6419960832400321,
    -178.51413177724191, 0.78607605325261687, -190.69910617020003,
    0.95184545876072357, -202.33624716112328, 1.14205592406578,
    -213.45018520278953, 1.3598563005969111, -224.0644433689782,
    1.6088420897991329, -234.20148714195321, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321,
    -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
    178.51413177724191, -0.78607605325261687, 190.69910617020003,
    -0.95184545876072357, 202.33624716112328, -1.14205592406578,
    213.45018520278953, -1.3598563005969111, 224.0644433689782,
    -1.6088420897991329, 234.20148714195321, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989,
    0.6419960832400321, -178.51413177724191, 0.78607605325261687,
    -190.69910617020003, 0.95184545876072357, -202.33624716112328,
    1.14205592406578, -213.45018520278953, 1.3598563005969111,
    -224.0644433689782, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321,
    -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
    178.51413177724191, -0.78607605325261687, 190.69910617020003,
    -0.95184545876072357, 202.33624716112328, -1.14205592406578,
    213.45018520278953, -1.3598563005969111, 224.0644433689782, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897,
    0.40963446866862863, -152.39630883721321, 0.5172085160937393,
    -165.75553401917989, 0.6419960832400321, -178.51413177724191,
    0.78607605325261687, -190.69910617020003, 0.95184545876072357,
    -202.33624716112328, 1.14205592406578, -213.45018520278953, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
    202.33624716112328, -1.14205592406578, 213.45018520278953, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014,
    0.23922319557143779, -123.76154386633067, 0.317482486824172,
    -138.40818092168897, 0.40963446866862863, -152.39630883721321,
    0.5172085160937393, -165.75553401917989, 0.6419960832400321,
    -178.51413177724191, 0.78607605325261687, -190.69910617020003,
    0.95184545876072357, -202.33624716112328, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
    202.33624716112328, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897,
    0.40963446866862863, -152.39630883721321, 0.5172085160937393,
    -165.75553401917989, 0.6419960832400321, -178.51413177724191,
    0.78607605325261687, -190.69910617020003, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014,
    0.23922319557143779, -123.76154386633067, 0.317482486824172,
    -138.40818092168897, 0.40963446866862863, -152.39630883721321,
    0.5172085160937393, -165.75553401917989, 0.6419960832400321,
    -178.51413177724191, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321,
    -0.5172085160937393, 165.75553401917989, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
    -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
    57.947594890272953, -0.076049818436936173, 75.553210635790776,
    -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
    108.42539750515014, -0.23922319557143779, 123.76154386633067,
    -0.317482486824172, 138.40818092168897, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
    -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
    57.947594890272953, -0.076049818436936173, 75.553210635790776,
    -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
    108.42539750515014, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

  static const real_T b_Ku1[15] = { 8.14476325671191E+8, 6.9204084137616038E+8,
    5.8495984206490076E+8, 4.914721464730351E+8, 4.1003334459267879E+8,
    3.3928921634185982E+8, 2.780521795989598E+8, 2.2528032838449991E+8,
    1.8005865953515089E+8, 1.4158211436682308E+8, 1.091400806848726E+8,
    8.21020098867991E+7, 5.9903803304666691E+7, 4.2034610471281506E+7,
    2.8023658363439217E+7 };

  static const real_T b_Kr[900] = { 119176.33760729058, 76.25870773834356,
    -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, 1.6049902081000803E+7, 1195.3108837691202,
    -16.066271859951772, 1.9651901331315421E+7, 1387.7086066140378,
    -17.162919555318002, 2.3796136469018091E+7, 1605.0764037715489,
    -18.210262244501095, 2.8551398101644497E+7, 1850.9673523499337,
    -19.210516668251056, 3.3996407514922775E+7, 2129.383157864223,
    -20.165799903208036, 4.0221052244978324E+7, 2444.8410648063191,
    -21.078133842775788, 4.7327809384949923E+7, 2802.4486219859959,
    -21.949449476536174, 5.5433378071354419E+7, 3207.9875988502713,
    -22.781590977262272, 6.4670546266637228E+7, 3668.0084791102045,
    -23.576319604180398, 7.51903209729462E+7, 4189.9371145386394,
    -24.335317430742414, -0.0, -0.0, -0.0, 119176.33760729058, 76.25870773834356,
    -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, 1.6049902081000803E+7, 1195.3108837691202,
    -16.066271859951772, 1.9651901331315421E+7, 1387.7086066140378,
    -17.162919555318002, 2.3796136469018091E+7, 1605.0764037715489,
    -18.210262244501095, 2.8551398101644497E+7, 1850.9673523499337,
    -19.210516668251056, 3.3996407514922775E+7, 2129.383157864223,
    -20.165799903208036, 4.0221052244978324E+7, 2444.8410648063191,
    -21.078133842775788, 4.7327809384949923E+7, 2802.4486219859959,
    -21.949449476536174, 5.5433378071354419E+7, 3207.9875988502713,
    -22.781590977262272, 6.4670546266637228E+7, 3668.0084791102045,
    -23.576319604180398, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058,
    76.25870773834356, -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, 1.6049902081000803E+7, 1195.3108837691202,
    -16.066271859951772, 1.9651901331315421E+7, 1387.7086066140378,
    -17.162919555318002, 2.3796136469018091E+7, 1605.0764037715489,
    -18.210262244501095, 2.8551398101644497E+7, 1850.9673523499337,
    -19.210516668251056, 3.3996407514922775E+7, 2129.383157864223,
    -20.165799903208036, 4.0221052244978324E+7, 2444.8410648063191,
    -21.078133842775788, 4.7327809384949923E+7, 2802.4486219859959,
    -21.949449476536174, 5.5433378071354419E+7, 3207.9875988502713,
    -22.781590977262272, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    119176.33760729058, 76.25870773834356, -1.81898326105613, 475348.10832782066,
    153.39936550217371, -3.5561854895050238, 1.0676997524213777E+6,
    233.3192118609409, -5.2152835401245659, 1.9012454609234044E+6,
    317.829307310411, -6.7997889572211694, 2.9864841626234408E+6,
    408.70939707991869, -8.3130554069472424, 4.3392272594275726E+6,
    507.75727694713265, -9.7582857754635128, 5.9805798892859444E+6,
    616.83442882544421, -11.13853894796976, 7.9370621706043007E+6,
    737.909444136206, -12.456736282952006, 1.0240861716715716E+7,
    873.10056535851356, -13.715667795349189, 1.2930212902343482E+7,
    1024.7185395157026, -14.917998061726189, 1.6049902081000803E+7,
    1195.3108837691202, -16.066271859951772, 1.9651901331315421E+7,
    1387.7086066140378, -17.162919555318002, 2.3796136469018091E+7,
    1605.0764037715489, -18.210262244501095, 2.8551398101644497E+7,
    1850.9673523499337, -19.210516668251056, 3.3996407514922775E+7,
    2129.383157864223, -20.165799903208036, 4.0221052244978324E+7,
    2444.8410648063191, -21.078133842775788, 4.7327809384949923E+7,
    2802.4486219859959, -21.949449476536174, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 76.25870773834356,
    -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, 1.6049902081000803E+7, 1195.3108837691202,
    -16.066271859951772, 1.9651901331315421E+7, 1387.7086066140378,
    -17.162919555318002, 2.3796136469018091E+7, 1605.0764037715489,
    -18.210262244501095, 2.8551398101644497E+7, 1850.9673523499337,
    -19.210516668251056, 3.3996407514922775E+7, 2129.383157864223,
    -20.165799903208036, 4.0221052244978324E+7, 2444.8410648063191,
    -21.078133842775788, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 76.25870773834356,
    -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, 1.6049902081000803E+7, 1195.3108837691202,
    -16.066271859951772, 1.9651901331315421E+7, 1387.7086066140378,
    -17.162919555318002, 2.3796136469018091E+7, 1605.0764037715489,
    -18.210262244501095, 2.8551398101644497E+7, 1850.9673523499337,
    -19.210516668251056, 3.3996407514922775E+7, 2129.383157864223,
    -20.165799903208036, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058,
    76.25870773834356, -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, 1.6049902081000803E+7, 1195.3108837691202,
    -16.066271859951772, 1.9651901331315421E+7, 1387.7086066140378,
    -17.162919555318002, 2.3796136469018091E+7, 1605.0764037715489,
    -18.210262244501095, 2.8551398101644497E+7, 1850.9673523499337,
    -19.210516668251056, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    119176.33760729058, 76.25870773834356, -1.81898326105613, 475348.10832782066,
    153.39936550217371, -3.5561854895050238, 1.0676997524213777E+6,
    233.3192118609409, -5.2152835401245659, 1.9012454609234044E+6,
    317.829307310411, -6.7997889572211694, 2.9864841626234408E+6,
    408.70939707991869, -8.3130554069472424, 4.3392272594275726E+6,
    507.75727694713265, -9.7582857754635128, 5.9805798892859444E+6,
    616.83442882544421, -11.13853894796976, 7.9370621706043007E+6,
    737.909444136206, -12.456736282952006, 1.0240861716715716E+7,
    873.10056535851356, -13.715667795349189, 1.2930212902343482E+7,
    1024.7185395157026, -14.917998061726189, 1.6049902081000803E+7,
    1195.3108837691202, -16.066271859951772, 1.9651901331315421E+7,
    1387.7086066140378, -17.162919555318002, 2.3796136469018091E+7,
    1605.0764037715489, -18.210262244501095, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 76.25870773834356,
    -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, 1.6049902081000803E+7, 1195.3108837691202,
    -16.066271859951772, 1.9651901331315421E+7, 1387.7086066140378,
    -17.162919555318002, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 76.25870773834356,
    -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, 1.6049902081000803E+7, 1195.3108837691202,
    -16.066271859951772, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058,
    76.25870773834356, -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, 1.0240861716715716E+7, 873.10056535851356,
    -13.715667795349189, 1.2930212902343482E+7, 1024.7185395157026,
    -14.917998061726189, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    119176.33760729058, 76.25870773834356, -1.81898326105613, 475348.10832782066,
    153.39936550217371, -3.5561854895050238, 1.0676997524213777E+6,
    233.3192118609409, -5.2152835401245659, 1.9012454609234044E+6,
    317.829307310411, -6.7997889572211694, 2.9864841626234408E+6,
    408.70939707991869, -8.3130554069472424, 4.3392272594275726E+6,
    507.75727694713265, -9.7582857754635128, 5.9805798892859444E+6,
    616.83442882544421, -11.13853894796976, 7.9370621706043007E+6,
    737.909444136206, -12.456736282952006, 1.0240861716715716E+7,
    873.10056535851356, -13.715667795349189, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 76.25870773834356,
    -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, 7.9370621706043007E+6, 737.909444136206,
    -12.456736282952006, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 76.25870773834356,
    -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128, 5.9805798892859444E+6, 616.83442882544421,
    -11.13853894796976, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058,
    76.25870773834356, -1.81898326105613, 475348.10832782066, 153.39936550217371,
    -3.5561854895050238, 1.0676997524213777E+6, 233.3192118609409,
    -5.2152835401245659, 1.9012454609234044E+6, 317.829307310411,
    -6.7997889572211694, 2.9864841626234408E+6, 408.70939707991869,
    -8.3130554069472424, 4.3392272594275726E+6, 507.75727694713265,
    -9.7582857754635128 };

  static const real_T b_Mlim_1[80] = { 0.025, 300.0, 0.025, 300.0, 0.025, 300.0,
    0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025,
    300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0,
    0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025,
    300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0,
    0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025,
    300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0,
    0.025, 300.0, 0.025, 300.0, 0.025, 300.0, 0.025, 300.0 };

  static const real_T c_a[80] = { 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989,
    0.6419960832400321, -178.51413177724191, 0.78607605325261687,
    -190.69910617020003, 0.95184545876072357, -202.33624716112328,
    1.14205592406578, -213.45018520278953, 1.3598563005969111,
    -224.0644433689782, 1.6088420897991329, -234.20148714195321,
    1.893112375397997, -243.88277196151304, 2.2173351228541769,
    -253.12878863624749, 2.5868218506654892, -261.95910671311555,
    3.007612838917848, -270.39241589713794, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
    202.33624716112328, -1.14205592406578, 213.45018520278953,
    -1.3598563005969111, 224.0644433689782, -1.6088420897991329,
    234.20148714195321, -1.893112375397997, 243.88277196151304,
    -2.2173351228541769, 253.12878863624749, -2.5868218506654892,
    261.95910671311555, -3.007612838917848, 270.39241589713794 };

  static const real_T b_a[480] = { -0.98615263436656475, -0.0,
    -0.99942002301347388, -0.0, -1.0378387905461661, -0.0, -1.1002744255838741,
    -0.0, -1.1863207617797207, -0.0, -1.2962271849089555, -0.0,
    -1.43084928730111, -0.0, -1.5916196723905174, -0.0, -1.7805364232478644,
    -0.0, -2.0001674254954458, -0.0, -2.2536693062662012, -0.0,
    -2.5448202408426392, -0.0, -2.8780663071232788, -0.0, -3.2585814516218368,
    -0.0, -3.6923414832284154, -0.0, -4.1862128443695985, -0.0,
    -4.7480572338937677, -0.0, -5.3868534812612943, -0.0, -6.1128384059420107,
    -0.0, -6.93766874733306, -0.0, 0.98615263436656475, 0.0, 0.99942002301347388,
    0.0, 1.0378387905461661, 0.0, 1.1002744255838741, 0.0, 1.1863207617797207,
    0.0, 1.2962271849089555, 0.0, 1.43084928730111, 0.0, 1.5916196723905174, 0.0,
    1.7805364232478644, 0.0, 2.0001674254954458, 0.0, 2.2536693062662012, 0.0,
    2.5448202408426392, 0.0, 2.8780663071232788, 0.0, 3.2585814516218368, 0.0,
    3.6923414832284154, 0.0, 4.1862128443695985, 0.0, 4.7480572338937677, 0.0,
    5.3868534812612943, 0.0, 6.1128384059420107, 0.0, 6.93766874733306, 0.0,
    -0.048980249871033235, -0.0, -0.095071665238666947, -0.0,
    -0.13973271303714727, -0.0, -0.18425986974283584, -0.0, -0.22983553032857923,
    -0.0, -0.27756883153618794, -0.0, -0.32853106728927578, -0.0,
    -0.38378708877189704, -0.0, -0.44442385735173262, -0.0, -0.51157714403245669,
    -0.0, -0.58645723563819907, -0.0, -0.670374408455958, -0.0,
    -0.76476485907352743, -0.0, -0.87121773535467084, -0.0, -0.991503884596186,
    -0.0, -1.1276069284499322, -0.0, -1.2817572833984563, -0.0,
    -1.4564697702663292, -0.0, -1.6545854957592905, -0.0, -1.879318743125328,
    -0.0, 0.048980249871033235, 0.0, 0.095071665238666947, 0.0,
    0.13973271303714727, 0.0, 0.18425986974283584, 0.0, 0.22983553032857923, 0.0,
    0.27756883153618794, 0.0, 0.32853106728927578, 0.0, 0.38378708877189704, 0.0,
    0.44442385735173262, 0.0, 0.51157714403245669, 0.0, 0.58645723563819907, 0.0,
    0.670374408455958, 0.0, 0.76476485907352743, 0.0, 0.87121773535467084, 0.0,
    0.991503884596186, 0.0, 1.1276069284499322, 0.0, 1.2817572833984563, 0.0,
    1.4564697702663292, 0.0, 1.6545854957592905, 0.0, 1.879318743125328, 0.0,
    1.0286617582746761E-5, -0.9550402500352021, 3.9813675118921535E-5,
    -0.91210187918730135, 8.6824575005253177E-5, -0.871094006756618,
    0.0001502124275274879, -0.83192983801700648, 0.00022943373256239266,
    -0.79452648051150709, 0.00032444431943717171, -0.75880476860729884,
    0.00043565395852127471, -0.72468909593861841, 0.00056389685516130389,
    -0.69210725538300266, 0.00071041589227329989, -0.66099028623216038,
    0.000876859031574618, -0.63127232823400226, 0.0010652867389217549,
    -0.60289048219690566, 0.0012781896860195963, -0.57578467686117629,
    0.0015185163149112715, -0.54989754175593586, 0.0017897101464240484,
    -0.52517428577233194, 0.0020957569802455486, -0.50156258119606656,
    0.0024412423819552107, -0.47901245295379274, 0.0028314200892587032,
    -0.45747617283896569, 0.0032722922030135517, -0.43690815849327314,
    0.0037707022648347031, -0.41726487692983527, 0.0043344425680970381,
    -0.3985047523939777, -1.0286617582746761E-5, 0.9550402500352021,
    -3.9813675118921535E-5, 0.91210187918730135, -8.6824575005253177E-5,
    0.871094006756618, -0.0001502124275274879, 0.83192983801700648,
    -0.00022943373256239266, 0.79452648051150709, -0.00032444431943717171,
    0.75880476860729884, -0.00043565395852127471, 0.72468909593861841,
    -0.00056389685516130389, 0.69210725538300266, -0.00071041589227329989,
    0.66099028623216038, -0.000876859031574618, 0.63127232823400226,
    -0.0010652867389217549, 0.60289048219690566, -0.0012781896860195963,
    0.57578467686117629, -0.0015185163149112715, 0.54989754175593586,
    -0.0017897101464240484, 0.52517428577233194, -0.0020957569802455486,
    0.50156258119606656, -0.0024412423819552107, 0.47901245295379274,
    -0.0028314200892587032, 0.45747617283896569, -0.0032722922030135517,
    0.43690815849327314, -0.0037707022648347031, 0.41726487692983527,
    -0.0043344425680970381, 0.3985047523939777, -1.0, -0.0, -1.0, -0.0, -1.0,
    -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
    -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
    -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
    -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
    -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
    -1.0, -0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T b_A[400] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const int8_T c_b[300] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };

  static const int8_T b_C_0[18] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
    0, 0, 1 };

  static const real_T b_Bu[6] = { -0.0047670535042916235, -0.19064676934585889,
    20.210925122845889, 0.0, 0.0, 0.0 };

  static const real_T c_A_1[36] = { 0.98615263436656475, 0.54967062879931416,
    0.0, 0.0, 0.0, 0.0, 0.048980249871033235, 0.9548677869051535, 0.0, 0.0, 0.0,
    0.0, -1.0286617582746761E-5, -0.00040517078444852746, 0.9550402500352021,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const real_T b_Kx_0[105] = { -9.4455006329805618E+10,
    -2.2009849229360661E+10, 4.0350496010776341E+7, -2.6896527741718636E+9,
    -4.5286675019904792E+8, -1.8836163537878452E+6, 292.22710508104183,
    -7.66583563228287E+10, -1.7905996542997818E+10, 3.2914567894522652E+7,
    -2.145798716086277E+9, -3.7767642922610176E+8, -1.6154603784573723E+6,
    267.89178765029942, -6.1645237007540939E+10, -1.443538221957469E+10,
    2.6611230836308558E+7, -1.6950702446246479E+9, -3.1300588295946455E+8,
    -1.3807078357943192E+6, 244.315468046119, -4.9057787881568588E+10,
    -1.1517740296027138E+10, 2.1298205179945104E+7, -1.3241658375857692E+9,
    -2.5757250488811016E+8, -1.1753966294679018E+6, 221.53387706885673,
    -3.857880086990818E+10, -9.081920118938406E+9, 1.6849505613416005E+7,
    -1.0214134760612185E+9, -2.1024469550316024E+8, -996039.917660798,
    199.58442759232054, -2.99268663719738E+10, -7.0647636623468657E+9,
    1.3153407895473883E+7, -7.7657942976943648E+8, -1.7002364325818193E+8,
    -839570.08951319358, 178.50629374954474, -2.2852102008487888E+10,
    -5.4101230364108143E+9, 1.0110657547197053E+7, -5.8070021029914331E+8,
    -1.3602723574325916E+8, -703289.56740988337, 158.3404938463367,
    -1.713240249750132E+10, -4.0680023929631777E+9, 7.6328963033665614E+6,
    -4.2593500409521824E+8, -1.0747583764161466E+8, -584827.65685948764,
    139.12997717808565, -1.2570157835099785E+10, -2.9938108929597011E+9,
    5.6412857085849857E+6, -3.0543623440667915E+8, -8.3679701172596574E+7,
    -482102.76701810851, 120.91971493358457, -8.9893951984727287E+9,
    -2.1477156648313022E+9, 4.0653107314615794E+6, -2.132362026352343E+8,
    -6.4027799841281153E+7, -393289.41619481007, 103.75679537826657,
    -6.2333078916104994E+9, -1.4940858102813013E+9, 2.8417497261748011E+6,
    -1.4414802986043057E+8, -4.7977897760280348E+7, -316789.5196335864,
    87.6905235183148, -4.1621423938679705E+9, -1.0010205633716284E+9,
    1.913800574454071E+6, -9.3679363665001482E+7, -3.5047684857936867E+7,
    -251207.53310458141, 72.77252545658861, -2.6514223433629484E+9,
    -6.3995673989469874E+8, 1.2303564860115957E+6, -5.7957538341643021E+7,
    -2.4806823141221151E+7, -195329.09692163655, 59.05685766123942,
    -1.5904963088915927E+9, -3.8535269116533345E+8, 745428.83180875413,
    -3.3665082543954752E+7, -1.6869760970616851E+7, -148102.89249691935,
    46.600121378287412, -8.8140472569069684E+8, -2.1444817019009334E+8,
    417718.66313565138, -1.7984661786838248E+7, -1.0889181081330907E+7,
    -108625.48905209091, 35.461582430317648 };

  static const real_T b_Linv_0[256] = { 6.27783268376304E-6,
    -0.00023593461288955674, 0.0005496466015318972, 0.00026784529730069259,
    0.00012111159481917013, 3.193633529827695E-5, -1.8716679117798152E-5,
    -4.2924091295817549E-5, -5.0198391314691292E-5, -4.7470392070050076E-5,
    -3.9531785387920326E-5, -2.9640259580544116E-5, -1.9947260720887463E-5,
    -1.174656865651121E-5, -5.6418535733549858E-6, 0.0, 0.0,
    0.000288960845166408, -0.0013374222202995546, -1.0997770544228921E-5,
    4.3541353024067907E-5, 6.693243389854653E-5, 7.0943031778388692E-5,
    6.4034590846639685E-5, 5.2091029381284257E-5, 3.8755263022597623E-5,
    2.6168134830388554E-5, 1.552714404294064E-5, 7.3916631641738422E-6,
    1.8496391583733361E-6, -1.3559839442572117E-6, 0.0, 0.0, 0.0,
    0.00082070873560509633, -0.0011203750554127255, 2.2563804099929125E-5,
    4.568508186238082E-5, 5.2574279232990641E-5, 5.0049898749356704E-5,
    4.2628876508430106E-5, 3.3264791519182891E-5, 2.3803710787660055E-5,
    1.5369235563038451E-5, 8.5791324307248762E-6, 3.6615591225070034E-6,
    5.4281190048322678E-7, 0.0, 0.0, 0.0, 0.0, 0.00090933576852047008,
    -0.0010647073760357874, 2.4105938034444994E-5, 3.4734195522967252E-5,
    3.6668673229910427E-5, 3.3755240852144081E-5, 2.8292785225544627E-5,
    2.1859260034775002E-5, 1.5524639461220638E-5, 9.97984783344015E-6,
    5.6028277675888975E-6, 2.5079079836576461E-6, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.00093500789521852178, -0.0010495362150958058, 1.6319318585666566E-5,
    2.3348003152317021E-5, 2.4963829511773535E-5, 2.342816856852455E-5,
    2.0037744198562019E-5, 1.5804923257253435E-5, 1.1495058074921099E-5,
    7.63970064608094E-6, 4.5457688370322619E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.00094744045101998137, -0.0010412103911457849, 8.9083070869740544E-6,
    1.5587238349282946E-5, 1.8034348475512912E-5, 1.7812784888101251E-5,
    1.5822638224516536E-5, 1.2872344694277314E-5, 9.6320636703543979E-6,
    6.5976805366028783E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.00095945656300420155, -0.0010310228759720036, 4.4863316475453053E-6,
    1.1461881963044224E-5, 1.4556313668656208E-5, 1.5054952151784123E-5,
    1.3725313621611647E-5, 1.1326597201683665E-5, 8.5202296230967174E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.000972667975740107,
    -0.0010187895364967307, 2.6624307894242228E-6, 9.6867699742384752E-6,
    1.2925809449638584E-5, 1.3568928632537288E-5, 1.2362392520910468E-5,
    1.0075037762645532E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.00098596707528219641, -0.0010060976232749751, 2.2683153096209695E-6,
    8.9404493708021852E-6, 1.1894390540039976E-5, 1.2304064485053696E-5,
    1.0935983266352631E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.00099840367084103043, -0.000994069150919616, 2.2706385075480078E-6,
    8.2913321140800276E-6, 1.071076404516283E-5, 1.072137794434875E-5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0010097760166580627,
    -0.000982959251720318, 2.0234169384220361E-6, 7.2490505929889314E-6,
    9.0588980911871424E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0010205246278527866, -0.00097229931403816606, 1.262532497157455E-6,
    5.6902981620509036E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0010315199210041903, -0.00096110809105383582,
    3.6210089373623047E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0010439118149419982, -0.00094802286426569837, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.001059093102399953, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.003162277660168379 };

  static const real_T b_Hinv_0[256] = { 4.552201114619461E-7,
    -8.0900748485514312E-7, 1.467392191722846E-7, 1.0851782579446654E-7,
    7.4443761605151447E-8, 4.61445506803858E-8, 2.4052002070180766E-8,
    8.0255399992116067E-9, -2.5322704886536166E-9, -8.51628021196163E-9,
    -1.0959703474577218E-8, -1.0900841215713401E-8, -9.28647891718964E-9,
    -6.9137756211797473E-9, -5.9752482042907929E-9, 0.0, -8.0900748485514312E-7,
    1.8930278648391648E-6, -1.0698967383495711E-6, -4.618514497578705E-8,
    -2.3812636308336863E-8, -7.55498022856921E-9, 3.449057014269696E-9,
    9.88147031643176E-9, 1.2662487487290839E-8, 1.2782277591763639E-8,
    1.1177485886521349E-8, 8.6535431485108864E-9, 5.8468955422557539E-9,
    3.2163639535383204E-9, -1.4361132423278952E-9, 0.0, 1.467392191722846E-7,
    -1.0698967383495711E-6, 1.9404822933409764E-6, -1.0348117604879959E-6,
    -2.2131817575180949E-8, -8.9302806573202875E-9, 1.5439765360854555E-10,
    5.9370305666743989E-9, 8.90747499446541E-9, 9.7002235927596245E-9,
    8.9779032391810789E-9, 7.350910424857332E-9, 5.3304115639797784E-9,
    3.3077467364401007E-9, 5.7488833970239522E-10, 0.0, 1.0851782579446654E-7,
    -4.618514497578705E-8, -1.0348117604879959E-6, 1.9664215069840162E-6,
    -1.0170290715133179E-6, -1.1129623507219775E-8, -3.2308448899198831E-9,
    1.9946471859842268E-9, 5.219701276036708E-9, 6.7229004375590007E-9,
    6.8963959949248688E-9, 6.1612222023742973E-9, 4.9095795601454618E-9,
    3.4713039936892164E-9, 2.6561080469455868E-9, 0.0, 7.4443761605151447E-8,
    -2.3812636308336863E-8, -2.2131817575180949E-8, -1.0170290715133179E-6,
    1.9786120243874312E-6, -1.0094867394078577E-6, -7.221466979797043E-9,
    -1.9660456176972121E-9, 1.509682826569394E-9, 3.7336266863602374E-9,
    4.8178575095467129E-9, 4.9881884946684506E-9, 4.5149678958994431E-9,
    3.6656809738908335E-9, 4.8143924204055245E-9, 0.0, 4.61445506803858E-8,
    -7.55498022856921E-9, -8.9302806573202875E-9, -1.1129623507219775E-8,
    -1.0094867394078577E-6, 1.9832796990011484E-6, -1.007064687779568E-6,
    -6.4299951915094911E-9, -2.25017047150078E-9, 6.1497913437075756E-10,
    2.5895514932539344E-9, 3.6813236322450961E-9, 4.0208645576582126E-9,
    3.8002730679362331E-9, 6.9875579481545286E-9, 0.0, 2.4052002070180766E-8,
    3.449057014269696E-9, 1.5439765360854555E-10, -3.2308448899198831E-9,
    -7.221466979797043E-9, -1.007064687779568E-6, 1.9845443771821275E-6,
    -1.0066353406040705E-6, -6.5449860499123724E-9, -2.6657467427552143E-9,
    8.72749318557468E-11, 2.0816192668031959E-9, 3.2721587263528134E-9,
    3.7465961504369514E-9, 9.023716424685484E-9, 0.0, 8.0255399992116067E-9,
    9.88147031643176E-9, 5.9370305666743989E-9, 1.9946471859842268E-9,
    -1.9660456176972121E-9, -6.4299951915094911E-9, -1.0066353406040705E-6,
    1.9847215602647462E-6, -1.0066103874680529E-6, -6.5888552385392849E-9,
    -2.7157360364042539E-9, 7.0984767803253214E-11, 2.1153895325337095E-9,
    3.353881456200742E-9, 1.0670403000836938E-8, 0.0, -2.5322704886536166E-9,
    1.2662487487290839E-8, 8.90747499446541E-9, 5.219701276036708E-9,
    1.509682826569394E-9, -2.25017047150078E-9, -6.5449860499123724E-9,
    -1.0066103874680529E-6, 1.9848610402485516E-6, -1.0063784669638587E-6,
    -6.2852789705142489E-9, -2.3631957092680924E-9, 4.4416085375323081E-10,
    2.4767961080264188E-9, 1.158222444535538E-8, 0.0, -8.51628021196163E-9,
    1.2782277591763639E-8, 9.7002235927596245E-9, 6.7229004375590007E-9,
    3.7336266863602374E-9, 6.1497913437075756E-10, -2.6657467427552143E-9,
    -6.5888552385392849E-9, -1.0063784669638587E-6, 1.9852869371578063E-6,
    -1.0058275890640897E-6, -5.6698834841912068E-9, -1.7411395157856008E-9,
    1.0169817061248415E-9, 1.1354937429082749E-8, 0.0, -1.0959703474577218E-8,
    1.1177485886521349E-8, 8.9779032391810789E-9, 6.8963959949248688E-9,
    4.8178575095467129E-9, 2.5895514932539344E-9, 8.72749318557468E-11,
    -2.7157360364042539E-9, -6.2852789705142489E-9, -1.0058275890640897E-6,
    1.9859952009456243E-6, -1.0050407914644665E-6, -4.8795982733911207E-9,
    -1.0206729543648572E-9, 9.5942164837204032E-9, 0.0, -1.0900841215713401E-8,
    8.6535431485108864E-9, 7.350910424857332E-9, 6.1612222023742973E-9,
    4.9881884946684506E-9, 3.6813236322450961E-9, 2.0816192668031959E-9,
    7.0984767803253214E-11, -2.3631957092680924E-9, -5.6698834841912068E-9,
    -1.0050407914644665E-6, 1.9868704456146361E-6, -1.0041593357611091E-6,
    -4.0765601715824445E-9, 6.0265555340272422E-9, 0.0, -9.28647891718964E-9,
    5.8468955422557539E-9, 5.3304115639797784E-9, 4.9095795601454618E-9,
    4.5149678958994431E-9, 4.0208645576582126E-9, 3.2721587263528134E-9,
    2.1153895325337095E-9, 4.4416085375323081E-10, -1.7411395157856008E-9,
    -4.8795982733911207E-9, -1.0041593357611091E-6, 1.9877621114288097E-6,
    -1.0033464196800924E-6, 3.834985589289E-11, 0.0, -6.9137756211797473E-9,
    3.2163639535383204E-9, 3.3077467364401007E-9, 3.4713039936892164E-9,
    3.6656809738908335E-9, 3.8002730679362331E-9, 3.7465961504369514E-9,
    3.353881456200742E-9, 2.4767961080264188E-9, 1.0169817061248415E-9,
    -1.0206729543648572E-9, -4.0765601715824445E-9, -1.0033464196800924E-6,
    1.9884992285460354E-6, -1.004044476461248E-6, 0.0, -5.9752482042907929E-9,
    -1.4361132423278952E-9, 5.7488833970239522E-10, 2.6561080469455868E-9,
    4.8143924204055245E-9, 6.9875579481545286E-9, 9.023716424685484E-9,
    1.0670403000836938E-8, 1.158222444535538E-8, 1.1354937429082749E-8,
    9.5942164837204032E-9, 6.0265555340272422E-9, 3.834985589289E-11,
    -1.004044476461248E-6, 1.1216781995511574E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.9999999999999974E-6 };

  static const real_T b_Ac_0[1760] = { 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897,
    0.40963446866862863, -152.39630883721321, 0.5172085160937393,
    -165.75553401917989, 0.6419960832400321, -178.51413177724191,
    0.78607605325261687, -190.69910617020003, 0.95184545876072357,
    -202.33624716112328, 1.14205592406578, -213.45018520278953,
    1.3598563005969111, -224.0644433689782, 1.6088420897991329,
    -234.20148714195321, 1.893112375397997, -243.88277196151304,
    2.2173351228541769, -253.12878863624749, 2.5868218506654892,
    -261.95910671311555, 3.007612838917848, -270.39241589713794,
    -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321,
    -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
    178.51413177724191, -0.78607605325261687, 190.69910617020003,
    -0.95184545876072357, 202.33624716112328, -1.14205592406578,
    213.45018520278953, -1.3598563005969111, 224.0644433689782,
    -1.6088420897991329, 234.20148714195321, -1.893112375397997,
    243.88277196151304, -2.2173351228541769, 253.12878863624749,
    -2.5868218506654892, 261.95910671311555, -3.007612838917848,
    270.39241589713794, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897,
    0.40963446866862863, -152.39630883721321, 0.5172085160937393,
    -165.75553401917989, 0.6419960832400321, -178.51413177724191,
    0.78607605325261687, -190.69910617020003, 0.95184545876072357,
    -202.33624716112328, 1.14205592406578, -213.45018520278953,
    1.3598563005969111, -224.0644433689782, 1.6088420897991329,
    -234.20148714195321, 1.893112375397997, -243.88277196151304,
    2.2173351228541769, -253.12878863624749, 2.5868218506654892,
    -261.95910671311555, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
    -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
    57.947594890272953, -0.076049818436936173, 75.553210635790776,
    -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
    108.42539750515014, -0.23922319557143779, 123.76154386633067,
    -0.317482486824172, 138.40818092168897, -0.40963446866862863,
    152.39630883721321, -0.5172085160937393, 165.75553401917989,
    -0.6419960832400321, 178.51413177724191, -0.78607605325261687,
    190.69910617020003, -0.95184545876072357, 202.33624716112328,
    -1.14205592406578, 213.45018520278953, -1.3598563005969111,
    224.0644433689782, -1.6088420897991329, 234.20148714195321,
    -1.893112375397997, 243.88277196151304, -2.2173351228541769,
    253.12878863624749, -2.5868218506654892, 261.95910671311555, -0.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989,
    0.6419960832400321, -178.51413177724191, 0.78607605325261687,
    -190.69910617020003, 0.95184545876072357, -202.33624716112328,
    1.14205592406578, -213.45018520278953, 1.3598563005969111,
    -224.0644433689782, 1.6088420897991329, -234.20148714195321,
    1.893112375397997, -243.88277196151304, 2.2173351228541769,
    -253.12878863624749, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
    202.33624716112328, -1.14205592406578, 213.45018520278953,
    -1.3598563005969111, 224.0644433689782, -1.6088420897991329,
    234.20148714195321, -1.893112375397997, 243.88277196151304,
    -2.2173351228541769, 253.12878863624749, -0.0, -0.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989,
    0.6419960832400321, -178.51413177724191, 0.78607605325261687,
    -190.69910617020003, 0.95184545876072357, -202.33624716112328,
    1.14205592406578, -213.45018520278953, 1.3598563005969111,
    -224.0644433689782, 1.6088420897991329, -234.20148714195321,
    1.893112375397997, -243.88277196151304, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321,
    -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
    178.51413177724191, -0.78607605325261687, 190.69910617020003,
    -0.95184545876072357, 202.33624716112328, -1.14205592406578,
    213.45018520278953, -1.3598563005969111, 224.0644433689782,
    -1.6088420897991329, 234.20148714195321, -1.893112375397997,
    243.88277196151304, -0.0, -0.0, -0.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, 0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014,
    0.23922319557143779, -123.76154386633067, 0.317482486824172,
    -138.40818092168897, 0.40963446866862863, -152.39630883721321,
    0.5172085160937393, -165.75553401917989, 0.6419960832400321,
    -178.51413177724191, 0.78607605325261687, -190.69910617020003,
    0.95184545876072357, -202.33624716112328, 1.14205592406578,
    -213.45018520278953, 1.3598563005969111, -224.0644433689782,
    1.6088420897991329, -234.20148714195321, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.40963446866862863, 152.39630883721321,
    -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
    178.51413177724191, -0.78607605325261687, 190.69910617020003,
    -0.95184545876072357, 202.33624716112328, -1.14205592406578,
    213.45018520278953, -1.3598563005969111, 224.0644433689782,
    -1.6088420897991329, 234.20148714195321, -0.0, -0.0, -0.0, -0.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897,
    0.40963446866862863, -152.39630883721321, 0.5172085160937393,
    -165.75553401917989, 0.6419960832400321, -178.51413177724191,
    0.78607605325261687, -190.69910617020003, 0.95184545876072357,
    -202.33624716112328, 1.14205592406578, -213.45018520278953,
    1.3598563005969111, -224.0644433689782, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
    -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
    57.947594890272953, -0.076049818436936173, 75.553210635790776,
    -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
    108.42539750515014, -0.23922319557143779, 123.76154386633067,
    -0.317482486824172, 138.40818092168897, -0.40963446866862863,
    152.39630883721321, -0.5172085160937393, 165.75553401917989,
    -0.6419960832400321, 178.51413177724191, -0.78607605325261687,
    190.69910617020003, -0.95184545876072357, 202.33624716112328,
    -1.14205592406578, 213.45018520278953, -1.3598563005969111,
    224.0644433689782, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989,
    0.6419960832400321, -178.51413177724191, 0.78607605325261687,
    -190.69910617020003, 0.95184545876072357, -202.33624716112328,
    1.14205592406578, -213.45018520278953, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
    -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
    57.947594890272953, -0.076049818436936173, 75.553210635790776,
    -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
    108.42539750515014, -0.23922319557143779, 123.76154386633067,
    -0.317482486824172, 138.40818092168897, -0.40963446866862863,
    152.39630883721321, -0.5172085160937393, 165.75553401917989,
    -0.6419960832400321, 178.51413177724191, -0.78607605325261687,
    190.69910617020003, -0.95184545876072357, 202.33624716112328,
    -1.14205592406578, 213.45018520278953, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014,
    0.23922319557143779, -123.76154386633067, 0.317482486824172,
    -138.40818092168897, 0.40963446866862863, -152.39630883721321,
    0.5172085160937393, -165.75553401917989, 0.6419960832400321,
    -178.51413177724191, 0.78607605325261687, -190.69910617020003,
    0.95184545876072357, -202.33624716112328, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
    202.33624716112328, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897,
    0.40963446866862863, -152.39630883721321, 0.5172085160937393,
    -165.75553401917989, 0.6419960832400321, -178.51413177724191,
    0.78607605325261687, -190.69910617020003, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, 0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014,
    0.23922319557143779, -123.76154386633067, 0.317482486824172,
    -138.40818092168897, 0.40963446866862863, -152.39630883721321,
    0.5172085160937393, -165.75553401917989, 0.6419960832400321,
    -178.51413177724191, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.317482486824172, -138.40818092168897,
    0.40963446866862863, -152.39630883721321, 0.5172085160937393,
    -165.75553401917989, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, 0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014,
    0.23922319557143779, -123.76154386633067, 0.317482486824172,
    -138.40818092168897, 0.40963446866862863, -152.39630883721321, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
    -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
    57.947594890272953, -0.076049818436936173, 75.553210635790776,
    -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
    108.42539750515014, -0.23922319557143779, 123.76154386633067,
    -0.317482486824172, 138.40818092168897, -0.40963446866862863,
    152.39630883721321, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.317482486824172,
    138.40818092168897, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
    -20.210925122845889, 0.019013924333112827, -39.513172105611375,
    0.042707990096855108, -57.947594890272953, 0.076049818436936173,
    -75.553210635790776, 0.11945936650493763, -92.3672822994138,
    0.17356909037710291, -108.42539750515014, 0.23922319557143779,
    -123.76154386633067, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
    39.513172105611375, -0.042707990096855108, 57.947594890272953,
    -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
    92.3672822994138, -0.17356909037710291, 108.42539750515014,
    -0.23922319557143779, 123.76154386633067, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
    -39.513172105611375, 0.042707990096855108, -57.947594890272953,
    0.076049818436936173, -75.553210635790776, 0.11945936650493763,
    -92.3672822994138, 0.17356909037710291, -108.42539750515014, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const real_T b_Ku1_0[15] = { 2.53735080765841E+10,
    2.0717301507443062E+10, 1.6767600924569258E+10, 1.3435819181971052E+10,
    1.0643535237384817E+10, 8.3212270903022919E+9, 6.4071536386631823E+9,
    4.8463702262113762E+9, 3.5898650731630239E+9, 2.593806117235487E+9,
    1.8188900956036923E+9, 1.2297880322721872E+9, 7.9468372900536227E+8,
    4.849044713153736E+8, 2.7464604787727761E+8 };

  static const real_T b_Kr_0[1200] = { 119176.33760729058, 4880.5572952539878,
    -1.81898326105613, -0.0, 475348.10832782066, 9817.5593921391173,
    -3.5561854895050238, 171613.92615449845, 1.0676997524213777E+6,
    14932.429559100217, -5.2152835401245659, 856115.20214656007,
    1.9012454609234044E+6, 20341.075667866306, -6.7997889572211694,
    2.3936028456333438E+6, 2.9864841626234408E+6, 26157.401413114796,
    -8.3130554069472424, 5.1313963093630467E+6, 4.3392272594275726E+6,
    32496.46572461649, -9.7582857754635128, 9.4319335035408E+6,
    5.9805798892859444E+6, 39477.403444828429, -11.13853894796976,
    1.5680420757116506E+7, 7.9370621706043007E+6, 47226.204424717187,
    -12.456736282952006, 2.4292455797688264E+7, 1.0240861716715716E+7,
    55878.436182944868, -13.715667795349189, 3.5721825323358461E+7,
    1.2930212902343482E+7, 65581.986529004964, -14.917998061726189,
    5.0468666195429087E+7, 1.6049902081000803E+7, 76499.8965612237,
    -16.066271859951772, 6.9088172774803713E+7, 1.9651901331315421E+7,
    88813.350823298417, -17.162919555318002, 9.2200031771444857E+7,
    2.3796136469018091E+7, 102724.88984137913, -18.210262244501095,
    1.2049876968853907E+8, 2.8551398101644497E+7, 118461.91055039575,
    -19.210516668251056, 1.547652062039251E+8, 3.3996407514922775E+7,
    136280.52210331027, -20.165799903208036, 1.9587921947029319E+8,
    4.0221052244978324E+7, 156469.82814760442, -21.078133842775788,
    2.4483404629178202E+8, 4.7327809384949923E+7, 179356.71180710374,
    -21.949449476536174, 3.027523615245508E+8, 5.5433378071354419E+7,
    205311.20632641736, -22.781590977262272, 3.7090440703887868E+8,
    6.4670546266637228E+7, 234752.54266305309, -23.576319604180398,
    4.5072847146162909E+8, 7.51903209729462E+7, 268155.97533047292,
    -24.335317430742414, 5.4385405808558679E+8, -0.0, -0.0, -0.0, -0.0,
    119176.33760729058, 4880.5572952539878, -1.81898326105613, -0.0,
    475348.10832782066, 9817.5593921391173, -3.5561854895050238,
    171613.92615449845, 1.0676997524213777E+6, 14932.429559100217,
    -5.2152835401245659, 856115.20214656007, 1.9012454609234044E+6,
    20341.075667866306, -6.7997889572211694, 2.3936028456333438E+6,
    2.9864841626234408E+6, 26157.401413114796, -8.3130554069472424,
    5.1313963093630467E+6, 4.3392272594275726E+6, 32496.46572461649,
    -9.7582857754635128, 9.4319335035408E+6, 5.9805798892859444E+6,
    39477.403444828429, -11.13853894796976, 1.5680420757116506E+7,
    7.9370621706043007E+6, 47226.204424717187, -12.456736282952006,
    2.4292455797688264E+7, 1.0240861716715716E+7, 55878.436182944868,
    -13.715667795349189, 3.5721825323358461E+7, 1.2930212902343482E+7,
    65581.986529004964, -14.917998061726189, 5.0468666195429087E+7,
    1.6049902081000803E+7, 76499.8965612237, -16.066271859951772,
    6.9088172774803713E+7, 1.9651901331315421E+7, 88813.350823298417,
    -17.162919555318002, 9.2200031771444857E+7, 2.3796136469018091E+7,
    102724.88984137913, -18.210262244501095, 1.2049876968853907E+8,
    2.8551398101644497E+7, 118461.91055039575, -19.210516668251056,
    1.547652062039251E+8, 3.3996407514922775E+7, 136280.52210331027,
    -20.165799903208036, 1.9587921947029319E+8, 4.0221052244978324E+7,
    156469.82814760442, -21.078133842775788, 2.4483404629178202E+8,
    4.7327809384949923E+7, 179356.71180710374, -21.949449476536174,
    3.027523615245508E+8, 5.5433378071354419E+7, 205311.20632641736,
    -22.781590977262272, 3.7090440703887868E+8, 6.4670546266637228E+7,
    234752.54266305309, -23.576319604180398, 4.5072847146162909E+8, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 4880.5572952539878,
    -1.81898326105613, -0.0, 475348.10832782066, 9817.5593921391173,
    -3.5561854895050238, 171613.92615449845, 1.0676997524213777E+6,
    14932.429559100217, -5.2152835401245659, 856115.20214656007,
    1.9012454609234044E+6, 20341.075667866306, -6.7997889572211694,
    2.3936028456333438E+6, 2.9864841626234408E+6, 26157.401413114796,
    -8.3130554069472424, 5.1313963093630467E+6, 4.3392272594275726E+6,
    32496.46572461649, -9.7582857754635128, 9.4319335035408E+6,
    5.9805798892859444E+6, 39477.403444828429, -11.13853894796976,
    1.5680420757116506E+7, 7.9370621706043007E+6, 47226.204424717187,
    -12.456736282952006, 2.4292455797688264E+7, 1.0240861716715716E+7,
    55878.436182944868, -13.715667795349189, 3.5721825323358461E+7,
    1.2930212902343482E+7, 65581.986529004964, -14.917998061726189,
    5.0468666195429087E+7, 1.6049902081000803E+7, 76499.8965612237,
    -16.066271859951772, 6.9088172774803713E+7, 1.9651901331315421E+7,
    88813.350823298417, -17.162919555318002, 9.2200031771444857E+7,
    2.3796136469018091E+7, 102724.88984137913, -18.210262244501095,
    1.2049876968853907E+8, 2.8551398101644497E+7, 118461.91055039575,
    -19.210516668251056, 1.547652062039251E+8, 3.3996407514922775E+7,
    136280.52210331027, -20.165799903208036, 1.9587921947029319E+8,
    4.0221052244978324E+7, 156469.82814760442, -21.078133842775788,
    2.4483404629178202E+8, 4.7327809384949923E+7, 179356.71180710374,
    -21.949449476536174, 3.027523615245508E+8, 5.5433378071354419E+7,
    205311.20632641736, -22.781590977262272, 3.7090440703887868E+8, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    119176.33760729058, 4880.5572952539878, -1.81898326105613, -0.0,
    475348.10832782066, 9817.5593921391173, -3.5561854895050238,
    171613.92615449845, 1.0676997524213777E+6, 14932.429559100217,
    -5.2152835401245659, 856115.20214656007, 1.9012454609234044E+6,
    20341.075667866306, -6.7997889572211694, 2.3936028456333438E+6,
    2.9864841626234408E+6, 26157.401413114796, -8.3130554069472424,
    5.1313963093630467E+6, 4.3392272594275726E+6, 32496.46572461649,
    -9.7582857754635128, 9.4319335035408E+6, 5.9805798892859444E+6,
    39477.403444828429, -11.13853894796976, 1.5680420757116506E+7,
    7.9370621706043007E+6, 47226.204424717187, -12.456736282952006,
    2.4292455797688264E+7, 1.0240861716715716E+7, 55878.436182944868,
    -13.715667795349189, 3.5721825323358461E+7, 1.2930212902343482E+7,
    65581.986529004964, -14.917998061726189, 5.0468666195429087E+7,
    1.6049902081000803E+7, 76499.8965612237, -16.066271859951772,
    6.9088172774803713E+7, 1.9651901331315421E+7, 88813.350823298417,
    -17.162919555318002, 9.2200031771444857E+7, 2.3796136469018091E+7,
    102724.88984137913, -18.210262244501095, 1.2049876968853907E+8,
    2.8551398101644497E+7, 118461.91055039575, -19.210516668251056,
    1.547652062039251E+8, 3.3996407514922775E+7, 136280.52210331027,
    -20.165799903208036, 1.9587921947029319E+8, 4.0221052244978324E+7,
    156469.82814760442, -21.078133842775788, 2.4483404629178202E+8,
    4.7327809384949923E+7, 179356.71180710374, -21.949449476536174,
    3.027523615245508E+8, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058,
    4880.5572952539878, -1.81898326105613, -0.0, 475348.10832782066,
    9817.5593921391173, -3.5561854895050238, 171613.92615449845,
    1.0676997524213777E+6, 14932.429559100217, -5.2152835401245659,
    856115.20214656007, 1.9012454609234044E+6, 20341.075667866306,
    -6.7997889572211694, 2.3936028456333438E+6, 2.9864841626234408E+6,
    26157.401413114796, -8.3130554069472424, 5.1313963093630467E+6,
    4.3392272594275726E+6, 32496.46572461649, -9.7582857754635128,
    9.4319335035408E+6, 5.9805798892859444E+6, 39477.403444828429,
    -11.13853894796976, 1.5680420757116506E+7, 7.9370621706043007E+6,
    47226.204424717187, -12.456736282952006, 2.4292455797688264E+7,
    1.0240861716715716E+7, 55878.436182944868, -13.715667795349189,
    3.5721825323358461E+7, 1.2930212902343482E+7, 65581.986529004964,
    -14.917998061726189, 5.0468666195429087E+7, 1.6049902081000803E+7,
    76499.8965612237, -16.066271859951772, 6.9088172774803713E+7,
    1.9651901331315421E+7, 88813.350823298417, -17.162919555318002,
    9.2200031771444857E+7, 2.3796136469018091E+7, 102724.88984137913,
    -18.210262244501095, 1.2049876968853907E+8, 2.8551398101644497E+7,
    118461.91055039575, -19.210516668251056, 1.547652062039251E+8,
    3.3996407514922775E+7, 136280.52210331027, -20.165799903208036,
    1.9587921947029319E+8, 4.0221052244978324E+7, 156469.82814760442,
    -21.078133842775788, 2.4483404629178202E+8, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, 119176.33760729058, 4880.5572952539878, -1.81898326105613, -0.0,
    475348.10832782066, 9817.5593921391173, -3.5561854895050238,
    171613.92615449845, 1.0676997524213777E+6, 14932.429559100217,
    -5.2152835401245659, 856115.20214656007, 1.9012454609234044E+6,
    20341.075667866306, -6.7997889572211694, 2.3936028456333438E+6,
    2.9864841626234408E+6, 26157.401413114796, -8.3130554069472424,
    5.1313963093630467E+6, 4.3392272594275726E+6, 32496.46572461649,
    -9.7582857754635128, 9.4319335035408E+6, 5.9805798892859444E+6,
    39477.403444828429, -11.13853894796976, 1.5680420757116506E+7,
    7.9370621706043007E+6, 47226.204424717187, -12.456736282952006,
    2.4292455797688264E+7, 1.0240861716715716E+7, 55878.436182944868,
    -13.715667795349189, 3.5721825323358461E+7, 1.2930212902343482E+7,
    65581.986529004964, -14.917998061726189, 5.0468666195429087E+7,
    1.6049902081000803E+7, 76499.8965612237, -16.066271859951772,
    6.9088172774803713E+7, 1.9651901331315421E+7, 88813.350823298417,
    -17.162919555318002, 9.2200031771444857E+7, 2.3796136469018091E+7,
    102724.88984137913, -18.210262244501095, 1.2049876968853907E+8,
    2.8551398101644497E+7, 118461.91055039575, -19.210516668251056,
    1.547652062039251E+8, 3.3996407514922775E+7, 136280.52210331027,
    -20.165799903208036, 1.9587921947029319E+8, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 4880.5572952539878,
    -1.81898326105613, -0.0, 475348.10832782066, 9817.5593921391173,
    -3.5561854895050238, 171613.92615449845, 1.0676997524213777E+6,
    14932.429559100217, -5.2152835401245659, 856115.20214656007,
    1.9012454609234044E+6, 20341.075667866306, -6.7997889572211694,
    2.3936028456333438E+6, 2.9864841626234408E+6, 26157.401413114796,
    -8.3130554069472424, 5.1313963093630467E+6, 4.3392272594275726E+6,
    32496.46572461649, -9.7582857754635128, 9.4319335035408E+6,
    5.9805798892859444E+6, 39477.403444828429, -11.13853894796976,
    1.5680420757116506E+7, 7.9370621706043007E+6, 47226.204424717187,
    -12.456736282952006, 2.4292455797688264E+7, 1.0240861716715716E+7,
    55878.436182944868, -13.715667795349189, 3.5721825323358461E+7,
    1.2930212902343482E+7, 65581.986529004964, -14.917998061726189,
    5.0468666195429087E+7, 1.6049902081000803E+7, 76499.8965612237,
    -16.066271859951772, 6.9088172774803713E+7, 1.9651901331315421E+7,
    88813.350823298417, -17.162919555318002, 9.2200031771444857E+7,
    2.3796136469018091E+7, 102724.88984137913, -18.210262244501095,
    1.2049876968853907E+8, 2.8551398101644497E+7, 118461.91055039575,
    -19.210516668251056, 1.547652062039251E+8, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    119176.33760729058, 4880.5572952539878, -1.81898326105613, -0.0,
    475348.10832782066, 9817.5593921391173, -3.5561854895050238,
    171613.92615449845, 1.0676997524213777E+6, 14932.429559100217,
    -5.2152835401245659, 856115.20214656007, 1.9012454609234044E+6,
    20341.075667866306, -6.7997889572211694, 2.3936028456333438E+6,
    2.9864841626234408E+6, 26157.401413114796, -8.3130554069472424,
    5.1313963093630467E+6, 4.3392272594275726E+6, 32496.46572461649,
    -9.7582857754635128, 9.4319335035408E+6, 5.9805798892859444E+6,
    39477.403444828429, -11.13853894796976, 1.5680420757116506E+7,
    7.9370621706043007E+6, 47226.204424717187, -12.456736282952006,
    2.4292455797688264E+7, 1.0240861716715716E+7, 55878.436182944868,
    -13.715667795349189, 3.5721825323358461E+7, 1.2930212902343482E+7,
    65581.986529004964, -14.917998061726189, 5.0468666195429087E+7,
    1.6049902081000803E+7, 76499.8965612237, -16.066271859951772,
    6.9088172774803713E+7, 1.9651901331315421E+7, 88813.350823298417,
    -17.162919555318002, 9.2200031771444857E+7, 2.3796136469018091E+7,
    102724.88984137913, -18.210262244501095, 1.2049876968853907E+8, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 4880.5572952539878,
    -1.81898326105613, -0.0, 475348.10832782066, 9817.5593921391173,
    -3.5561854895050238, 171613.92615449845, 1.0676997524213777E+6,
    14932.429559100217, -5.2152835401245659, 856115.20214656007,
    1.9012454609234044E+6, 20341.075667866306, -6.7997889572211694,
    2.3936028456333438E+6, 2.9864841626234408E+6, 26157.401413114796,
    -8.3130554069472424, 5.1313963093630467E+6, 4.3392272594275726E+6,
    32496.46572461649, -9.7582857754635128, 9.4319335035408E+6,
    5.9805798892859444E+6, 39477.403444828429, -11.13853894796976,
    1.5680420757116506E+7, 7.9370621706043007E+6, 47226.204424717187,
    -12.456736282952006, 2.4292455797688264E+7, 1.0240861716715716E+7,
    55878.436182944868, -13.715667795349189, 3.5721825323358461E+7,
    1.2930212902343482E+7, 65581.986529004964, -14.917998061726189,
    5.0468666195429087E+7, 1.6049902081000803E+7, 76499.8965612237,
    -16.066271859951772, 6.9088172774803713E+7, 1.9651901331315421E+7,
    88813.350823298417, -17.162919555318002, 9.2200031771444857E+7, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058,
    4880.5572952539878, -1.81898326105613, -0.0, 475348.10832782066,
    9817.5593921391173, -3.5561854895050238, 171613.92615449845,
    1.0676997524213777E+6, 14932.429559100217, -5.2152835401245659,
    856115.20214656007, 1.9012454609234044E+6, 20341.075667866306,
    -6.7997889572211694, 2.3936028456333438E+6, 2.9864841626234408E+6,
    26157.401413114796, -8.3130554069472424, 5.1313963093630467E+6,
    4.3392272594275726E+6, 32496.46572461649, -9.7582857754635128,
    9.4319335035408E+6, 5.9805798892859444E+6, 39477.403444828429,
    -11.13853894796976, 1.5680420757116506E+7, 7.9370621706043007E+6,
    47226.204424717187, -12.456736282952006, 2.4292455797688264E+7,
    1.0240861716715716E+7, 55878.436182944868, -13.715667795349189,
    3.5721825323358461E+7, 1.2930212902343482E+7, 65581.986529004964,
    -14.917998061726189, 5.0468666195429087E+7, 1.6049902081000803E+7,
    76499.8965612237, -16.066271859951772, 6.9088172774803713E+7, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    119176.33760729058, 4880.5572952539878, -1.81898326105613, -0.0,
    475348.10832782066, 9817.5593921391173, -3.5561854895050238,
    171613.92615449845, 1.0676997524213777E+6, 14932.429559100217,
    -5.2152835401245659, 856115.20214656007, 1.9012454609234044E+6,
    20341.075667866306, -6.7997889572211694, 2.3936028456333438E+6,
    2.9864841626234408E+6, 26157.401413114796, -8.3130554069472424,
    5.1313963093630467E+6, 4.3392272594275726E+6, 32496.46572461649,
    -9.7582857754635128, 9.4319335035408E+6, 5.9805798892859444E+6,
    39477.403444828429, -11.13853894796976, 1.5680420757116506E+7,
    7.9370621706043007E+6, 47226.204424717187, -12.456736282952006,
    2.4292455797688264E+7, 1.0240861716715716E+7, 55878.436182944868,
    -13.715667795349189, 3.5721825323358461E+7, 1.2930212902343482E+7,
    65581.986529004964, -14.917998061726189, 5.0468666195429087E+7, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, 119176.33760729058, 4880.5572952539878, -1.81898326105613,
    -0.0, 475348.10832782066, 9817.5593921391173, -3.5561854895050238,
    171613.92615449845, 1.0676997524213777E+6, 14932.429559100217,
    -5.2152835401245659, 856115.20214656007, 1.9012454609234044E+6,
    20341.075667866306, -6.7997889572211694, 2.3936028456333438E+6,
    2.9864841626234408E+6, 26157.401413114796, -8.3130554069472424,
    5.1313963093630467E+6, 4.3392272594275726E+6, 32496.46572461649,
    -9.7582857754635128, 9.4319335035408E+6, 5.9805798892859444E+6,
    39477.403444828429, -11.13853894796976, 1.5680420757116506E+7,
    7.9370621706043007E+6, 47226.204424717187, -12.456736282952006,
    2.4292455797688264E+7, 1.0240861716715716E+7, 55878.436182944868,
    -13.715667795349189, 3.5721825323358461E+7, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 119176.33760729058, 4880.5572952539878,
    -1.81898326105613, -0.0, 475348.10832782066, 9817.5593921391173,
    -3.5561854895050238, 171613.92615449845, 1.0676997524213777E+6,
    14932.429559100217, -5.2152835401245659, 856115.20214656007,
    1.9012454609234044E+6, 20341.075667866306, -6.7997889572211694,
    2.3936028456333438E+6, 2.9864841626234408E+6, 26157.401413114796,
    -8.3130554069472424, 5.1313963093630467E+6, 4.3392272594275726E+6,
    32496.46572461649, -9.7582857754635128, 9.4319335035408E+6,
    5.9805798892859444E+6, 39477.403444828429, -11.13853894796976,
    1.5680420757116506E+7, 7.9370621706043007E+6, 47226.204424717187,
    -12.456736282952006, 2.4292455797688264E+7, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 119176.33760729058,
    4880.5572952539878, -1.81898326105613, -0.0, 475348.10832782066,
    9817.5593921391173, -3.5561854895050238, 171613.92615449845,
    1.0676997524213777E+6, 14932.429559100217, -5.2152835401245659,
    856115.20214656007, 1.9012454609234044E+6, 20341.075667866306,
    -6.7997889572211694, 2.3936028456333438E+6, 2.9864841626234408E+6,
    26157.401413114796, -8.3130554069472424, 5.1313963093630467E+6,
    4.3392272594275726E+6, 32496.46572461649, -9.7582857754635128,
    9.4319335035408E+6, 5.9805798892859444E+6, 39477.403444828429,
    -11.13853894796976, 1.5680420757116506E+7, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    119176.33760729058, 4880.5572952539878, -1.81898326105613, -0.0,
    475348.10832782066, 9817.5593921391173, -3.5561854895050238,
    171613.92615449845, 1.0676997524213777E+6, 14932.429559100217,
    -5.2152835401245659, 856115.20214656007, 1.9012454609234044E+6,
    20341.075667866306, -6.7997889572211694, 2.3936028456333438E+6,
    2.9864841626234408E+6, 26157.401413114796, -8.3130554069472424,
    5.1313963093630467E+6, 4.3392272594275726E+6, 32496.46572461649,
    -9.7582857754635128, 9.4319335035408E+6 };

  static const real_T b_Mlim_2[110] = { 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1,
    300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1,
    300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1,
    300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1,
    300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1,
    300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1,
    300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1, 300.0, 0.1,
    300.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0,
    4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0,
    4.0 };

  static const real_T c_a_0[110] = { 0.0047670535042916235, -20.210925122845889,
    0.019013924333112827, -39.513172105611375, 0.042707990096855108,
    -57.947594890272953, 0.076049818436936173, -75.553210635790776,
    0.11945936650493763, -92.3672822994138, 0.17356909037710291,
    -108.42539750515014, 0.23922319557143779, -123.76154386633067,
    0.317482486824172, -138.40818092168897, 0.40963446866862863,
    -152.39630883721321, 0.5172085160937393, -165.75553401917989,
    0.6419960832400321, -178.51413177724191, 0.78607605325261687,
    -190.69910617020003, 0.95184545876072357, -202.33624716112328,
    1.14205592406578, -213.45018520278953, 1.3598563005969111,
    -224.0644433689782, 1.6088420897991329, -234.20148714195321,
    1.893112375397997, -243.88277196151304, 2.2173351228541769,
    -253.12878863624749, 2.5868218506654892, -261.95910671311555,
    3.007612838917848, -270.39241589713794, -0.0047670535042916235,
    20.210925122845889, -0.019013924333112827, 39.513172105611375,
    -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
    75.553210635790776, -0.11945936650493763, 92.3672822994138,
    -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
    123.76154386633067, -0.317482486824172, 138.40818092168897,
    -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
    165.75553401917989, -0.6419960832400321, 178.51413177724191,
    -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
    202.33624716112328, -1.14205592406578, 213.45018520278953,
    -1.3598563005969111, 224.0644433689782, -1.6088420897991329,
    234.20148714195321, -1.893112375397997, 243.88277196151304,
    -2.2173351228541769, 253.12878863624749, -2.5868218506654892,
    261.95910671311555, -3.007612838917848, 270.39241589713794, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

  static const real_T b_a_0[770] = { -0.98615263436656475, -0.0,
    -0.99942002301347388, -0.0, -1.0378387905461661, -0.0, -1.1002744255838741,
    -0.0, -1.1863207617797207, -0.0, -1.2962271849089555, -0.0,
    -1.43084928730111, -0.0, -1.5916196723905174, -0.0, -1.7805364232478644,
    -0.0, -2.0001674254954458, -0.0, -2.2536693062662012, -0.0,
    -2.5448202408426392, -0.0, -2.8780663071232788, -0.0, -3.2585814516218368,
    -0.0, -3.6923414832284154, -0.0, -4.1862128443695985, -0.0,
    -4.7480572338937677, -0.0, -5.3868534812612943, -0.0, -6.1128384059420107,
    -0.0, -6.93766874733306, -0.0, 0.98615263436656475, 0.0, 0.99942002301347388,
    0.0, 1.0378387905461661, 0.0, 1.1002744255838741, 0.0, 1.1863207617797207,
    0.0, 1.2962271849089555, 0.0, 1.43084928730111, 0.0, 1.5916196723905174, 0.0,
    1.7805364232478644, 0.0, 2.0001674254954458, 0.0, 2.2536693062662012, 0.0,
    2.5448202408426392, 0.0, 2.8780663071232788, 0.0, 3.2585814516218368, 0.0,
    3.6923414832284154, 0.0, 4.1862128443695985, 0.0, 4.7480572338937677, 0.0,
    5.3868534812612943, 0.0, 6.1128384059420107, 0.0, 6.93766874733306, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.048980249871033235, -0.0, -0.095071665238666947, -0.0,
    -0.13973271303714727, -0.0, -0.18425986974283584, -0.0, -0.22983553032857923,
    -0.0, -0.27756883153618794, -0.0, -0.32853106728927578, -0.0,
    -0.38378708877189704, -0.0, -0.44442385735173262, -0.0, -0.51157714403245669,
    -0.0, -0.58645723563819907, -0.0, -0.670374408455958, -0.0,
    -0.76476485907352743, -0.0, -0.87121773535467084, -0.0, -0.991503884596186,
    -0.0, -1.1276069284499322, -0.0, -1.2817572833984563, -0.0,
    -1.4564697702663292, -0.0, -1.6545854957592905, -0.0, -1.879318743125328,
    -0.0, 0.048980249871033235, 0.0, 0.095071665238666947, 0.0,
    0.13973271303714727, 0.0, 0.18425986974283584, 0.0, 0.22983553032857923, 0.0,
    0.27756883153618794, 0.0, 0.32853106728927578, 0.0, 0.38378708877189704, 0.0,
    0.44442385735173262, 0.0, 0.51157714403245669, 0.0, 0.58645723563819907, 0.0,
    0.670374408455958, 0.0, 0.76476485907352743, 0.0, 0.87121773535467084, 0.0,
    0.991503884596186, 0.0, 1.1276069284499322, 0.0, 1.2817572833984563, 0.0,
    1.4564697702663292, 0.0, 1.6545854957592905, 0.0, 1.879318743125328, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0286617582746761E-5, -0.9550402500352021, 3.9813675118921535E-5,
    -0.91210187918730135, 8.6824575005253177E-5, -0.871094006756618,
    0.0001502124275274879, -0.83192983801700648, 0.00022943373256239266,
    -0.79452648051150709, 0.00032444431943717171, -0.75880476860729884,
    0.00043565395852127471, -0.72468909593861841, 0.00056389685516130389,
    -0.69210725538300266, 0.00071041589227329989, -0.66099028623216038,
    0.000876859031574618, -0.63127232823400226, 0.0010652867389217549,
    -0.60289048219690566, 0.0012781896860195963, -0.57578467686117629,
    0.0015185163149112715, -0.54989754175593586, 0.0017897101464240484,
    -0.52517428577233194, 0.0020957569802455486, -0.50156258119606656,
    0.0024412423819552107, -0.47901245295379274, 0.0028314200892587032,
    -0.45747617283896569, 0.0032722922030135517, -0.43690815849327314,
    0.0037707022648347031, -0.41726487692983527, 0.0043344425680970381,
    -0.3985047523939777, -1.0286617582746761E-5, 0.9550402500352021,
    -3.9813675118921535E-5, 0.91210187918730135, -8.6824575005253177E-5,
    0.871094006756618, -0.0001502124275274879, 0.83192983801700648,
    -0.00022943373256239266, 0.79452648051150709, -0.00032444431943717171,
    0.75880476860729884, -0.00043565395852127471, 0.72468909593861841,
    -0.00056389685516130389, 0.69210725538300266, -0.00071041589227329989,
    0.66099028623216038, -0.000876859031574618, 0.63127232823400226,
    -0.0010652867389217549, 0.60289048219690566, -0.0012781896860195963,
    0.57578467686117629, -0.0015185163149112715, 0.54989754175593586,
    -0.0017897101464240484, 0.52517428577233194, -0.0020957569802455486,
    0.50156258119606656, -0.0024412423819552107, 0.47901245295379274,
    -0.0028314200892587032, 0.45747617283896569, -0.0032722922030135517,
    0.43690815849327314, -0.0037707022648347031, 0.41726487692983527,
    -0.0043344425680970381, 0.3985047523939777, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
    -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
    -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
    -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -1.0,
    -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
    -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
    -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T b_C_1[28] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 };

  static const real_T b_Bu_0[7] = { -0.0047670535042916235, -0.19064676934585889,
    20.210925122845889, 0.0, 0.0, 0.0, 0.0 };

  static const real_T c_A_2[49] = { 0.98615263436656475, 0.54967062879931416,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.048980249871033235, 0.9548677869051535, 0.0, 0.0,
    0.0, 0.0, 0.0, -1.0286617582746761E-5, -0.00040517078444852746,
    0.9550402500352021, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  /* Reset subsysRan breadcrumbs */
  srClearBC(reaction_pendulum_DW.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(reaction_pendulum_DW.EnabledSubsystem_SubsysRanBC);

  /* Delay: '<S1>/Delay1' */
  reaction_pendulum_B.Delay1[0] = reaction_pendulum_DW.Delay1_DSTATE[0];
  reaction_pendulum_B.Delay1[1] = reaction_pendulum_DW.Delay1_DSTATE[1];

  /* Gain: '<S8>/Minimum sampling to time constant ratio' */
  rtb_Integrator = reaction_pendulum_P.FilteredDerivative1_minRatio *
    reaction_pendulum_B.Probe[0];

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Constant: '<S8>/Time constant'
   */
  if ((!(rtb_Integrator >= reaction_pendulum_P.h)) && (!rtIsNaN
       (reaction_pendulum_P.h))) {
    rtb_Integrator = reaction_pendulum_P.h;
  }

  /* End of MinMax: '<S8>/MinMax' */

  /* Constant: '<S11>/Constant' */
  reaction_pendulum_B.Constant = reaction_pendulum_P.FilteredDerivative1_x0;

  /* DiscreteIntegrator: '<S13>/Integrator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if ((reaction_pendulum_P.Constant_Value != 0.0) ||
      (reaction_pendulum_DW.Integrator_PrevResetState != 0)) {
    reaction_pendulum_DW.Integrator_DSTATE = reaction_pendulum_B.Constant;
    if (reaction_pendulum_DW.Integrator_DSTATE >=
        reaction_pendulum_P.Integrator_UpperSat) {
      reaction_pendulum_DW.Integrator_DSTATE =
        reaction_pendulum_P.Integrator_UpperSat;
    } else if (reaction_pendulum_DW.Integrator_DSTATE <=
               reaction_pendulum_P.Integrator_LowerSat) {
      reaction_pendulum_DW.Integrator_DSTATE =
        reaction_pendulum_P.Integrator_LowerSat;
    }
  }

  if (reaction_pendulum_DW.Integrator_DSTATE >=
      reaction_pendulum_P.Integrator_UpperSat) {
    reaction_pendulum_DW.Integrator_DSTATE =
      reaction_pendulum_P.Integrator_UpperSat;
  } else if (reaction_pendulum_DW.Integrator_DSTATE <=
             reaction_pendulum_P.Integrator_LowerSat) {
    reaction_pendulum_DW.Integrator_DSTATE =
      reaction_pendulum_P.Integrator_LowerSat;
  }

  /* Saturate: '<S13>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S13>/Integrator'
   */
  if (reaction_pendulum_DW.Integrator_DSTATE >
      reaction_pendulum_P.Saturation_UpperSat) {
    /* Saturate: '<S13>/Saturation' */
    rtb_Saturation = reaction_pendulum_P.Saturation_UpperSat;
  } else if (reaction_pendulum_DW.Integrator_DSTATE <
             reaction_pendulum_P.Saturation_LowerSat) {
    /* Saturate: '<S13>/Saturation' */
    rtb_Saturation = reaction_pendulum_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S13>/Saturation' */
    rtb_Saturation = reaction_pendulum_DW.Integrator_DSTATE;
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* Product: '<S7>/1//T' incorporates:
   *  Fcn: '<S8>/Avoid Divide by Zero'
   *  Sum: '<S7>/Sum1'
   */
  rtb_uT = 1.0 / ((real_T)(rtb_Integrator == 0.0) * 2.2204460492503131e-16 +
                  rtb_Integrator) * (reaction_pendulum_B.Delay1[0] -
    rtb_Saturation);

  /* Gain: '<S7>/Gain' */
  rtb_last_mv = reaction_pendulum_P.FilteredDerivative1_K * rtb_uT;

  /* Saturate: '<S7>/[A,B]' */
  if (rtb_last_mv > reaction_pendulum_P.FilteredDerivative1_B) {
    /* Saturate: '<S7>/[A,B]' */
    reaction_pendulum_B.AB = reaction_pendulum_P.FilteredDerivative1_B;
  } else if (rtb_last_mv < reaction_pendulum_P.FilteredDerivative1_A) {
    /* Saturate: '<S7>/[A,B]' */
    reaction_pendulum_B.AB = reaction_pendulum_P.FilteredDerivative1_A;
  } else {
    /* Saturate: '<S7>/[A,B]' */
    reaction_pendulum_B.AB = rtb_last_mv;
  }

  /* End of Saturate: '<S7>/[A,B]' */

  /* UnitDelay: '<S81>/last_mv' */
  rtb_last_mv = reaction_pendulum_DW.last_mv_DSTATE;

  /* MATLAB Function: '<S101>/optimizer' incorporates:
   *  Constant: '<Root>/Ref'
   *  Constant: '<S4>/DisturbanceState'
   *  Memory: '<S81>/Memory'
   *  SignalConversion generated from: '<S102>/ SFunction '
   */
  /* MATLAB Function 'MPC Controller/MPC/optimizer/optimizer': '<S102>:1' */
  /* '<S102>:1:128' */
  /* '<S102>:1:218' */
  /* '<S102>:1:219' */
  /* '<S102>:1:223' */
  /* '<S102>:1:225' */
  /* '<S102>:1:232' */
  /* '<S102>:1:24' */
  /* '<S102>:1:253' */
  /* '<S102>:1:26' */
  /* '<S102>:1:253' */
  /* '<S102>:1:30' */
  /* '<S102>:1:253' */
  /* '<S102>:1:128' */
  for (kidx = 0; kidx < 20; kidx++) {
    rseq[kidx * reaction_pendulum_ny] = reaction_pendulum_P.Ref_Value[0];
    rseq[kidx * reaction_pendulum_ny + 1] = reaction_pendulum_P.Ref_Value[1];
    rseq[kidx * reaction_pendulum_ny + 2] = reaction_pendulum_P.Ref_Value[2];
  }

  /* '<S102>:1:133' */
  /* '<S102>:1:143' */
  rtb_xest_j[0] = reaction_pendulum_B.Delay1[0];
  rtb_xest_j[1] = reaction_pendulum_B.AB;
  rtb_xest_j[2] = reaction_pendulum_B.Delay1[1];
  rtb_xest_j[3] = reaction_pendulum_P.DisturbanceState_Value[0];
  rtb_xest_j[4] = reaction_pendulum_P.DisturbanceState_Value[1];
  rtb_xest_j[5] = reaction_pendulum_P.DisturbanceState_Value[2];

  /* '<S102>:1:216' */
  memset(&f[0], 0, sizeof(real_T) << 4U);
  for (kidx = 0; kidx < 15; kidx++) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      rtb_TmpSignalConversionAtSFun_0 += b_Kx[6 * kidx + i1] * rtb_xest_j[i1];
    }

    rtb_Integrator = 0.0;
    for (i1 = 0; i1 < 60; i1++) {
      rtb_Integrator += b_Kr[60 * kidx + i1] * rseq[i1];
    }

    f[kidx] = (rtb_TmpSignalConversionAtSFun_0 + rtb_Integrator) + b_Ku1[kidx] *
      rtb_last_mv;
  }

  for (kidx = 0; kidx < 80; kidx++) {
    iAnew[kidx] = reaction_pendulum_DW.Memory_PreviousInput_e[kidx];
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      rtb_TmpSignalConversionAtSFun_0 += b_a[80 * i1 + kidx] * rtb_xest_j[i1];
    }

    b_Mlim[kidx] = -((b_Mlim_1[kidx] + rtb_TmpSignalConversionAtSFun_0) +
                     c_a[kidx] * rtb_last_mv);
  }

  reaction_pendulum_qpkwik(b_Linv, b_Hinv, f, b_Ac, b_Mlim, iAnew, 384, 1.0E-6,
    zopt, a__1, &rtb_Integrator);
  for (kidx = 0; kidx < 80; kidx++) {
    reaction_pendulum_B.iAout_f[kidx] = (iAnew[kidx] != 0);
  }

  rtb_TmpSignalConversionAtSFun_0 = rt_roundd_snf(rtb_Integrator);
  if (rtb_TmpSignalConversionAtSFun_0 < 2.147483648E+9) {
    if (rtb_TmpSignalConversionAtSFun_0 >= -2.147483648E+9) {
      i1 = (int32_T)rtb_TmpSignalConversionAtSFun_0;
    } else {
      i1 = MIN_int32_T;
    }

    if (rtb_TmpSignalConversionAtSFun_0 >= -2.147483648E+9) {
      ibcol = (int32_T)rtb_TmpSignalConversionAtSFun_0;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    i1 = MAX_int32_T;
    ibcol = MAX_int32_T;
  }

  if ((i1 < 0) || (ibcol == 0)) {
    memset(&zopt[0], 0, sizeof(real_T) << 4U);
  }

  reaction_pendulum_B.u_g = rtb_last_mv + zopt[0];
  kidx = -1;
  for (ibcol = 0; ibcol < 20; ibcol++) {
    for (i1 = 0; i1 < 20; i1++) {
      a[(kidx + i1) + 1] = b_A[20 * ibcol + i1];
    }

    kidx += 20;
    for (i1 = 0; i1 < 15; i1++) {
      a_0[ibcol + 20 * i1] = 0.0;
    }
  }

  /* '<S102>:1:216' */
  /* '<S102>:1:232' */
  for (kidx = 0; kidx < 20; kidx++) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
    for (i1 = 0; i1 < 15; i1++) {
      for (ibcol = 0; ibcol < 20; ibcol++) {
        a_tmp = 20 * i1 + kidx;
        a_0[a_tmp] += (real_T)(a[20 * ibcol + kidx] * c_b[20 * i1 + ibcol]);
      }

      rtb_TmpSignalConversionAtSFun_0 += a_0[20 * i1 + kidx] * zopt[i1];
    }

    uopt_dim[kidx] = rtb_TmpSignalConversionAtSFun_0 + rtb_last_mv;
  }

  for (kidx = 0; kidx < 21; kidx++) {
    for (i1 = 0; i1 < 3; i1++) {
      rtb_Bkuk[i1] = 0.0;
      for (ibcol = 0; ibcol < 6; ibcol++) {
        rtb_Bkuk[i1] += (real_T)b_C_0[3 * ibcol + i1] * rtb_xest_j[ibcol];
      }

      yseq[kidx + 21 * i1] = rtb_Bkuk[i1];
    }

    if (kidx < reaction_pendulum_p) {
      rtb_last_mv = uopt_dim[kidx];
      for (i1 = 0; i1 < 6; i1++) {
        rtb_TmpSignalConversionAtSFun_0 = 0.0;
        for (ibcol = 0; ibcol < 6; ibcol++) {
          rtb_TmpSignalConversionAtSFun_0 += c_A_1[6 * ibcol + i1] *
            rtb_xest_j[ibcol];
        }

        c_A[i1] = b_Bu[i1] * rtb_last_mv + rtb_TmpSignalConversionAtSFun_0;
      }

      for (i1 = 0; i1 < 6; i1++) {
        rtb_xest_j[i1] = c_A[i1];
      }
    }
  }

  /* DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  /* '<S102>:1:232' */
  /* '<S102>:1:244' */
  /* '<S102>:1:247' */
  reaction_pendulum_B.DiscreteTimeIntegrator =
    reaction_pendulum_DW.DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion generated from: '<S78>/To Workspace2' */
  reaction_pendulum_B.TmpSignalConversionAtToWorkspac[0] =
    reaction_pendulum_B.Delay1[0];
  reaction_pendulum_B.TmpSignalConversionAtToWorkspac[1] =
    reaction_pendulum_B.AB;
  reaction_pendulum_B.TmpSignalConversionAtToWorkspac[2] =
    reaction_pendulum_B.Delay1[1];
  reaction_pendulum_B.TmpSignalConversionAtToWorkspac[3] =
    reaction_pendulum_B.DiscreteTimeIntegrator;

  /* UnitDelay: '<S103>/last_mv' */
  rtb_last_mv = reaction_pendulum_DW.last_mv_DSTATE_p;

  /* SignalConversion generated from: '<S124>/ SFunction ' incorporates:
   *  Constant: '<Root>/Ref'
   *  MATLAB Function: '<S123>/optimizer'
   */
  rtb_TmpSignalConversionAtSFun_0 = reaction_pendulum_P.Ref_Value[0];
  rtb_Integrator = reaction_pendulum_P.Ref_Value[1];
  rtb_TmpSignalConversionAtSFun_1 = reaction_pendulum_P.Ref_Value[2];

  /* MATLAB Function: '<S123>/optimizer' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/DisturbanceState1'
   *  Memory: '<S103>/Memory'
   *  SignalConversion generated from: '<S124>/ SFunction '
   */
  /* MATLAB Function 'MPC Controller/MPC/optimizer/optimizer': '<S124>:1' */
  /* '<S124>:1:128' */
  /* '<S124>:1:218' */
  /* '<S124>:1:219' */
  /* '<S124>:1:223' */
  /* '<S124>:1:225' */
  /* '<S124>:1:232' */
  /* '<S124>:1:24' */
  /* '<S124>:1:253' */
  /* '<S124>:1:26' */
  /* '<S124>:1:253' */
  /* '<S124>:1:30' */
  /* '<S124>:1:253' */
  /* '<S124>:1:128' */
  for (kidx = 0; kidx < 20; kidx++) {
    i1 = kidx << 2;
    a__1[i1] = rtb_TmpSignalConversionAtSFun_0;
    a__1[i1 + 1] = rtb_Integrator;
    a__1[i1 + 2] = rtb_TmpSignalConversionAtSFun_1;
    a__1[i1 + 3] = reaction_pendulum_P.Constant_Value_b;
  }

  /* '<S124>:1:133' */
  /* '<S124>:1:143' */
  rtb_xest[0] = reaction_pendulum_B.Delay1[0];
  rtb_xest[1] = reaction_pendulum_B.AB;
  rtb_xest[2] = reaction_pendulum_B.Delay1[1];
  rtb_xest[3] = reaction_pendulum_B.DiscreteTimeIntegrator;
  rtb_xest[4] = reaction_pendulum_P.DisturbanceState1_Value[0];
  rtb_xest[5] = reaction_pendulum_P.DisturbanceState1_Value[1];
  rtb_xest[6] = reaction_pendulum_P.DisturbanceState1_Value[2];

  /* '<S124>:1:216' */
  memset(&f[0], 0, sizeof(real_T) << 4U);
  for (kidx = 0; kidx < 15; kidx++) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
    for (i1 = 0; i1 < 7; i1++) {
      rtb_TmpSignalConversionAtSFun_0 += b_Kx_0[7 * kidx + i1] * rtb_xest[i1];
    }

    rtb_Integrator = 0.0;
    for (i1 = 0; i1 < 80; i1++) {
      rtb_Integrator += b_Kr_0[80 * kidx + i1] * a__1[i1];
    }

    f[kidx] = (rtb_TmpSignalConversionAtSFun_0 + rtb_Integrator) + b_Ku1_0[kidx]
      * rtb_last_mv;
  }

  for (kidx = 0; kidx < 110; kidx++) {
    iAnew_0[kidx] = reaction_pendulum_DW.Memory_PreviousInput_c[kidx];
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
    for (i1 = 0; i1 < 7; i1++) {
      rtb_TmpSignalConversionAtSFun_0 += b_a_0[110 * i1 + kidx] * rtb_xest[i1];
    }

    b_Mlim_0[kidx] = -((b_Mlim_2[kidx] + rtb_TmpSignalConversionAtSFun_0) +
                       c_a_0[kidx] * rtb_last_mv);
  }

  reaction_pendulum_qpkwik_j(b_Linv_0, b_Hinv_0, f, b_Ac_0, b_Mlim_0, iAnew_0,
    504, 1.0E-6, zopt, a__1_0, &rtb_Integrator);
  for (kidx = 0; kidx < 110; kidx++) {
    reaction_pendulum_B.iAout[kidx] = (iAnew_0[kidx] != 0);
  }

  rtb_Integrator = rt_roundd_snf(rtb_Integrator);
  if (rtb_Integrator < 2.147483648E+9) {
    if (rtb_Integrator >= -2.147483648E+9) {
      i1 = (int32_T)rtb_Integrator;
    } else {
      i1 = MIN_int32_T;
    }
  } else {
    i1 = MAX_int32_T;
  }

  if (rtb_Integrator < 2.147483648E+9) {
    if (rtb_Integrator >= -2.147483648E+9) {
      ibcol = (int32_T)rtb_Integrator;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  if ((i1 < 0) || (ibcol == 0)) {
    memset(&zopt[0], 0, sizeof(real_T) << 4U);
  }

  reaction_pendulum_B.u = rtb_last_mv + zopt[0];
  kidx = -1;
  for (ibcol = 0; ibcol < 20; ibcol++) {
    for (i1 = 0; i1 < 20; i1++) {
      a[(kidx + i1) + 1] = b_A[20 * ibcol + i1];
    }

    kidx += 20;
    for (i1 = 0; i1 < 15; i1++) {
      a_0[ibcol + 20 * i1] = 0.0;
    }
  }

  /* '<S124>:1:216' */
  /* '<S124>:1:232' */
  for (kidx = 0; kidx < 20; kidx++) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
    for (i1 = 0; i1 < 15; i1++) {
      for (ibcol = 0; ibcol < 20; ibcol++) {
        a_tmp = 20 * i1 + kidx;
        a_0[a_tmp] += (real_T)(a[20 * ibcol + kidx] * c_b[20 * i1 + ibcol]);
      }

      rtb_TmpSignalConversionAtSFun_0 += a_0[20 * i1 + kidx] * zopt[i1];
    }

    uopt_dim[kidx] = rtb_TmpSignalConversionAtSFun_0 + rtb_last_mv;
  }

  for (kidx = 0; kidx < 21; kidx++) {
    for (i1 = 0; i1 < 4; i1++) {
      b_C[i1] = 0.0;
      for (ibcol = 0; ibcol < 7; ibcol++) {
        b_C[i1] += (real_T)b_C_1[(ibcol << 2) + i1] * rtb_xest[ibcol];
      }

      yseq_0[kidx + 21 * i1] = b_C[i1];
    }

    if (kidx < reaction_pendulum_p) {
      rtb_last_mv = uopt_dim[kidx];
      for (i1 = 0; i1 < 7; i1++) {
        rtb_TmpSignalConversionAtSFun_0 = 0.0;
        for (ibcol = 0; ibcol < 7; ibcol++) {
          rtb_TmpSignalConversionAtSFun_0 += c_A_2[7 * ibcol + i1] *
            rtb_xest[ibcol];
        }

        c_A_0[i1] = b_Bu_0[i1] * rtb_last_mv + rtb_TmpSignalConversionAtSFun_0;
      }

      for (i1 = 0; i1 < 7; i1++) {
        rtb_xest[i1] = c_A_0[i1];
      }
    }
  }

  /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
   *  Constant: '<Root>/<Controller selection'
   */
  /* '<S124>:1:232' */
  /* '<S124>:1:244' */
  /* '<S124>:1:247' */
  switch ((int32_T)reaction_pendulum_P.Controllerselection_Value) {
   case 1:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Ref'
     *  Gain: '<S4>/LQR STABLE'
     *  Sum: '<S4>/Sum'
     */
    reaction_pendulum_B.Control = ((reaction_pendulum_B.Delay1[0] -
      reaction_pendulum_P.Ref_Value[0]) * -reaction_pendulum_P.K[0] +
      (reaction_pendulum_B.AB - reaction_pendulum_P.Ref_Value[1]) *
      -reaction_pendulum_P.K[1]) + (reaction_pendulum_B.Delay1[1] -
      reaction_pendulum_P.Ref_Value[2]) * -reaction_pendulum_P.K[2];
    break;

   case 2:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Ref'
     *  Gain: '<S4>/LQR UNSTABLE'
     *  Sum: '<S4>/Sum1'
     */
    reaction_pendulum_B.Control = ((reaction_pendulum_B.Delay1[0] -
      reaction_pendulum_P.Ref_Value[0]) * -reaction_pendulum_P.K_Unst[0] +
      (reaction_pendulum_B.AB - reaction_pendulum_P.Ref_Value[1]) *
      -reaction_pendulum_P.K_Unst[1]) + (reaction_pendulum_B.Delay1[1] -
      reaction_pendulum_P.Ref_Value[2]) * -reaction_pendulum_P.K_Unst[2];
    break;

   case 3:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Gain: '<S81>/umin_scale1'
     */
    reaction_pendulum_B.Control = reaction_pendulum_P.umin_scale1_Gain *
      reaction_pendulum_B.u_g;
    break;

   case 4:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Gain: '<S4>/LQI UNSTABLE'
     */
    reaction_pendulum_B.Control = ((reaction_pendulum_P.LQIUNSTABLE_Gain[0] *
      reaction_pendulum_B.TmpSignalConversionAtToWorkspac[0] +
      reaction_pendulum_P.LQIUNSTABLE_Gain[1] *
      reaction_pendulum_B.TmpSignalConversionAtToWorkspac[1]) +
      reaction_pendulum_P.LQIUNSTABLE_Gain[2] *
      reaction_pendulum_B.TmpSignalConversionAtToWorkspac[2]) +
      reaction_pendulum_P.LQIUNSTABLE_Gain[3] *
      reaction_pendulum_B.TmpSignalConversionAtToWorkspac[3];
    break;

   case 5:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Gain: '<S103>/umin_scale1'
     */
    reaction_pendulum_B.Control = reaction_pendulum_P.umin_scale1_Gain_a *
      reaction_pendulum_B.u;
    break;

   default:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Default stop on error'
     */
    reaction_pendulum_B.Control = reaction_pendulum_P.Defaultstoponerror_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch' */

  /* Step: '<Root>/Step3' incorporates:
   *  Step: '<Root>/Step2'
   *  Step: '<Root>/Step4'
   */
  rtb_TmpSignalConversionAtSFun_0 = reaction_pendulum_M->Timing.t[0];
  if (rtb_TmpSignalConversionAtSFun_0 < reaction_pendulum_P.Step3_Time) {
    rtb_Integrator = reaction_pendulum_P.Step3_Y0;
  } else {
    rtb_Integrator = reaction_pendulum_P.Step3_YFinal;
  }

  /* End of Step: '<Root>/Step3' */

  /* Step: '<Root>/Step4' */
  if (rtb_TmpSignalConversionAtSFun_0 < reaction_pendulum_P.Step4_Time) {
    rtb_last_mv = reaction_pendulum_P.Step4_Y0;
  } else {
    rtb_last_mv = reaction_pendulum_P.Step4_YFinal;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum1'
   */
  reaction_pendulum_B.Sum = (rtb_Integrator + rtb_last_mv) *
    reaction_pendulum_P.Gain_Gain + reaction_pendulum_B.Control;

  /* Gain: '<S2>/Gain2' */
  rtb_last_mv = reaction_pendulum_P.Gain2_Gain * reaction_pendulum_B.Sum;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_last_mv > reaction_pendulum_P.Saturation_UpperSat_h) {
    /* Saturate: '<S2>/Saturation' */
    reaction_pendulum_B.Saturation = reaction_pendulum_P.Saturation_UpperSat_h;
  } else if (rtb_last_mv < reaction_pendulum_P.Saturation_LowerSat_f) {
    /* Saturate: '<S2>/Saturation' */
    reaction_pendulum_B.Saturation = reaction_pendulum_P.Saturation_LowerSat_f;
  } else {
    /* Saturate: '<S2>/Saturation' */
    reaction_pendulum_B.Saturation = rtb_last_mv;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Step: '<Root>/Step2' */
  if (rtb_TmpSignalConversionAtSFun_0 < reaction_pendulum_P.h) {
    rtb_Integrator = reaction_pendulum_P.Step2_Y0;
  } else {
    rtb_Integrator = reaction_pendulum_P.Step2_YFinal;
  }

  /* Gain: '<S2>/Gain' */
  reaction_pendulum_B.Gain[0] = reaction_pendulum_P.Gain_Gain_d[0] *
    rtb_Integrator;
  reaction_pendulum_B.Gain[1] = reaction_pendulum_P.Gain_Gain_d[1] *
    rtb_Integrator;

  /* Constant: '<S2>/Prescaler' */
  reaction_pendulum_B.Prescaler = reaction_pendulum_P.Prescaler_Value;

  /* Constant: '<S2>/ThermFlag' */
  reaction_pendulum_B.ThermFlag = reaction_pendulum_P.ThermFlag_Value;

  /* S-Function (rtdacusb2_rpend_dd): '<S2>/S-Function' */

  /* Level2 S-Function Block: '<S2>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = reaction_pendulum_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S2>/Pendulum Convert to rad' */
  reaction_pendulum_B.PendulumAnglerad =
    reaction_pendulum_P.PendulumConverttorad_Gain *
    reaction_pendulum_B.SFunction_o2;

  /* Gain: '<S2>/DC Convert to rad' */
  rtb_DCAnglerad = reaction_pendulum_P.DCConverttorad_Gain *
    reaction_pendulum_B.SFunction_o3;

  /* Gain: '<S2>/Gain1' incorporates:
   *  Memory: '<S2>/Memory'
   *  Sum: '<S2>/Add'
   */
  reaction_pendulum_B.Periodms = (reaction_pendulum_B.SFunction_o6 -
    reaction_pendulum_DW.Memory_PreviousInput) * reaction_pendulum_P.Gain1_Gain;

  /* Product: '<S2>/Divide' incorporates:
   *  Gain: '<S2>/rad2RPM'
   *  Memory: '<S2>/Memory1'
   *  Sum: '<S2>/Add1'
   */
  reaction_pendulum_B.DCVelrads = (rtb_DCAnglerad -
    reaction_pendulum_DW.Memory1_PreviousInput) *
    reaction_pendulum_P.rad2RPM_Gain / reaction_pendulum_B.Periodms;

  /* Gain: '<S2>/DC Convert to [A]1' */
  reaction_pendulum_B.DCConverttoA1 = reaction_pendulum_P.DCConverttoA1_Gain *
    reaction_pendulum_B.SFunction_o4;

  /* ToWorkspace: '<Root>/To Workspace1' */
  {
    double locTime = reaction_pendulum_M->Timing.t[1]
      ;
    rt_UpdateStructLogVar((StructLogVar *)
                          reaction_pendulum_DW.ToWorkspace1_PWORK.LoggedData,
                          &locTime, &reaction_pendulum_B.Sum);
  }

  /* Sum: '<S20>/Sum' incorporates:
   *  Memory: '<S20>/memory'
   */
  rtb_Integrator = reaction_pendulum_B.DCVelrads -
    reaction_pendulum_DW.memory_PreviousInput;

  /* InitialCondition: '<S20>/IC' */
  if (reaction_pendulum_DW.IC_FirstOutputTime) {
    reaction_pendulum_DW.IC_FirstOutputTime = false;

    /* InitialCondition: '<S20>/IC' */
    reaction_pendulum_B.IC = reaction_pendulum_P.IC_Value;
  } else {
    /* InitialCondition: '<S20>/IC' incorporates:
     *  Constant: '<S20>/gradient_val'
     *  DataTypeConversion: '<S20>/conversion'
     *  Gain: '<S20>/expander'
     *  Gain: '<S20>/falling'
     *  Gain: '<S20>/rising'
     *  Logic: '<S20>/conjunction'
     *  RelationalOperator: '<S20>/fall_relop'
     *  RelationalOperator: '<S20>/rise_relop'
     */
    reaction_pendulum_B.IC = ((reaction_pendulum_P.rising_Gain * rtb_Integrator <
      reaction_pendulum_P.expander_Gain[0] *
      reaction_pendulum_P.CheckDiscreteGradient_gradient) &&
      (reaction_pendulum_P.falling_Gain * rtb_Integrator <
       reaction_pendulum_P.expander_Gain[1] *
       reaction_pendulum_P.CheckDiscreteGradient_gradient));
  }

  /* End of InitialCondition: '<S20>/IC' */

  /* Delay: '<S23>/MemoryX' incorporates:
   *  Constant: '<S21>/Constant3'
   */
  if (reaction_pendulum_DW.icLoad) {
    reaction_pendulum_DW.MemoryX_DSTATE[0] =
      reaction_pendulum_P.Constant3_Value[0];
    reaction_pendulum_DW.MemoryX_DSTATE[1] =
      reaction_pendulum_P.Constant3_Value[1];
    reaction_pendulum_DW.MemoryX_DSTATE[2] =
      reaction_pendulum_P.Constant3_Value[2];
  }

  /* Outputs for Enabled SubSystem: '<S51>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S77>/Enable'
   */
  /* Constant: '<S23>/Enable' */
  if (reaction_pendulum_P.Enable_Value) {
    reaction_pendulum_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S77>/Product' incorporates:
     *  Constant: '<S23>/C'
     *  Delay: '<S23>/MemoryX'
     */
    for (i1 = 0; i1 < 3; i1++) {
      rtb_Bkuk[i1] = (reaction_pendulum_P.C_Value[i1 + 3] *
                      reaction_pendulum_DW.MemoryX_DSTATE[1] +
                      reaction_pendulum_P.C_Value[i1] *
                      reaction_pendulum_DW.MemoryX_DSTATE[0]) +
        reaction_pendulum_P.C_Value[i1 + 6] *
        reaction_pendulum_DW.MemoryX_DSTATE[2];
    }

    /* End of Product: '<S77>/Product' */

    /* Sum: '<S77>/Add1' */
    rtb_last_mv = reaction_pendulum_B.Delay1[0] - rtb_Bkuk[0];
    rtb_TmpSignalConversionAtSFun_0 = reaction_pendulum_B.AB - rtb_Bkuk[1];
    rtb_Integrator = reaction_pendulum_B.Delay1[1] - rtb_Bkuk[2];
    for (i1 = 0; i1 < 3; i1++) {
      /* Product: '<S77>/Product2' incorporates:
       *  Constant: '<S24>/KalmanGainM'
       */
      reaction_pendulum_B.Product2[i1] = 0.0;
      reaction_pendulum_B.Product2[i1] +=
        reaction_pendulum_P.KalmanGainM_Value[i1] * rtb_last_mv;
      reaction_pendulum_B.Product2[i1] +=
        reaction_pendulum_P.KalmanGainM_Value[i1 + 3] *
        rtb_TmpSignalConversionAtSFun_0;
      reaction_pendulum_B.Product2[i1] +=
        reaction_pendulum_P.KalmanGainM_Value[i1 + 6] * rtb_Integrator;
    }

    srUpdateBC(reaction_pendulum_DW.EnabledSubsystem_SubsysRanBC);
  } else if (reaction_pendulum_DW.EnabledSubsystem_MODE) {
    /* Disable for Product: '<S77>/Product2' incorporates:
     *  Outport: '<S77>/deltax'
     */
    reaction_pendulum_B.Product2[0] = reaction_pendulum_P.deltax_Y0;
    reaction_pendulum_B.Product2[1] = reaction_pendulum_P.deltax_Y0;
    reaction_pendulum_B.Product2[2] = reaction_pendulum_P.deltax_Y0;
    reaction_pendulum_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S51>/Enabled Subsystem' */

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  Delay: '<S23>/MemoryX'
   *  Delay: '<S3>/Delay'
   *  Sum: '<S51>/Add'
   */
  /* MATLAB Function 'RPM packet drop rejector/MATLAB Function1': '<S22>:1' */
  if (reaction_pendulum_B.IC == 1.0) {
    /* '<S22>:1:3' */
    /* '<S22>:1:4' */
    reaction_pendulum_B.prev_signal = reaction_pendulum_B.DCVelrads;
  } else {
    /* '<S22>:1:6' */
    reaction_pendulum_B.prev_signal = 9.999999E+6;
  }

  if (reaction_pendulum_DW.Delay_DSTATE == reaction_pendulum_B.DCVelrads) {
    /* '<S22>:1:9' */
    /* '<S22>:1:10' */
    reaction_pendulum_B.y = reaction_pendulum_B.Product2[1] +
      reaction_pendulum_DW.MemoryX_DSTATE[1];
  } else {
    /* '<S22>:1:12' */
    reaction_pendulum_B.y = reaction_pendulum_B.DCVelrads;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function1' */

  /* SignalConversion generated from: '<S1>/Delay1' */
  reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[0] =
    reaction_pendulum_B.PendulumAnglerad;
  reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[1] = reaction_pendulum_B.y;

  /* Assertion: '<S20>/Assertion' */
  utAssert(reaction_pendulum_B.IC != 0.0);

  /* Outputs for Enabled SubSystem: '<S44>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S75>/Enable'
   */
  /* Constant: '<S23>/Enable' */
  /* MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S74>:1' */
  if (reaction_pendulum_P.Enable_Value) {
    reaction_pendulum_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S75>/Sum' */
    rtb_Bkuk[0] = reaction_pendulum_B.Delay1[0];
    rtb_Bkuk[1] = reaction_pendulum_B.AB;
    rtb_Bkuk[2] = reaction_pendulum_B.Delay1[1];
    for (i1 = 0; i1 < 3; i1++) {
      /* Sum: '<S75>/Sum' incorporates:
       *  Constant: '<S23>/C'
       *  Constant: '<S23>/D'
       *  Delay: '<S23>/MemoryX'
       *  Product: '<S75>/C[k]*xhat[k|k-1]'
       *  Product: '<S75>/D[k]*u[k]'
       *  Sum: '<S75>/Add1'
       */
      tmp[i1] = rtb_Bkuk[i1] - (((reaction_pendulum_P.C_Value[i1 + 3] *
        reaction_pendulum_DW.MemoryX_DSTATE[1] + reaction_pendulum_P.C_Value[i1]
        * reaction_pendulum_DW.MemoryX_DSTATE[0]) +
        reaction_pendulum_P.C_Value[i1 + 6] *
        reaction_pendulum_DW.MemoryX_DSTATE[2]) + reaction_pendulum_P.D_Value[i1]
        * reaction_pendulum_B.Sum);
    }

    for (i1 = 0; i1 < 3; i1++) {
      /* Product: '<S75>/Product3' incorporates:
       *  Constant: '<S24>/KalmanGainL'
       */
      reaction_pendulum_B.Product3[i1] = 0.0;
      reaction_pendulum_B.Product3[i1] +=
        reaction_pendulum_P.KalmanGainL_Value[i1] * tmp[0];
      reaction_pendulum_B.Product3[i1] +=
        reaction_pendulum_P.KalmanGainL_Value[i1 + 3] * tmp[1];
      reaction_pendulum_B.Product3[i1] +=
        reaction_pendulum_P.KalmanGainL_Value[i1 + 6] * tmp[2];
    }

    srUpdateBC(reaction_pendulum_DW.MeasurementUpdate_SubsysRanBC);
  } else if (reaction_pendulum_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S75>/Product3' incorporates:
     *  Outport: '<S75>/L*(y[k]-yhat[k|k-1])'
     */
    reaction_pendulum_B.Product3[0] = reaction_pendulum_P.Lykyhatkk1_Y0;
    reaction_pendulum_B.Product3[1] = reaction_pendulum_P.Lykyhatkk1_Y0;
    reaction_pendulum_B.Product3[2] = reaction_pendulum_P.Lykyhatkk1_Y0;
    reaction_pendulum_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S44>/MeasurementUpdate' */
  for (i1 = 0; i1 < 3; i1++) {
    /* Sum: '<S44>/Add' incorporates:
     *  Constant: '<S23>/A'
     *  Constant: '<S23>/B'
     *  Delay: '<S23>/MemoryX'
     *  Product: '<S44>/A[k]*xhat[k|k-1]'
     *  Product: '<S44>/B[k]*u[k]'
     *  Product: '<S75>/Product3'
     */
    rtb_Add_i[i1] = (((reaction_pendulum_P.A_Value[i1 + 3] *
                       reaction_pendulum_DW.MemoryX_DSTATE[1] +
                       reaction_pendulum_P.A_Value[i1] *
                       reaction_pendulum_DW.MemoryX_DSTATE[0]) +
                      reaction_pendulum_P.A_Value[i1 + 6] *
                      reaction_pendulum_DW.MemoryX_DSTATE[2]) +
                     reaction_pendulum_P.B_Value[i1] * reaction_pendulum_B.Sum)
      + reaction_pendulum_B.Product3[i1];
  }

  for (i1 = 0; i1 < 4; i1++) {
    for (ibcol = 0; ibcol < 21; ibcol++) {
      /* Gain: '<S103>/umin_scale5' incorporates:
       *  MATLAB Function: '<S123>/optimizer'
       */
      kidx = 21 * i1 + ibcol;

      /* Gain: '<S103>/umin_scale5' incorporates:
       *  MATLAB Function: '<S123>/optimizer'
       */
      reaction_pendulum_B.umin_scale5[kidx] =
        reaction_pendulum_P.umin_scale5_Gain[kidx] * yseq_0[kidx];
    }
  }

  /* ToWorkspace: '<S4>/To Workspace' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (reaction_pendulum_DW.ToWorkspace_PWORK.LoggedData),
                  &reaction_pendulum_B.umin_scale5[0], 0);
  for (i1 = 0; i1 < 3; i1++) {
    for (ibcol = 0; ibcol < 21; ibcol++) {
      /* Gain: '<S81>/umin_scale5' incorporates:
       *  MATLAB Function: '<S101>/optimizer'
       */
      kidx = 21 * i1 + ibcol;

      /* Gain: '<S81>/umin_scale5' incorporates:
       *  MATLAB Function: '<S101>/optimizer'
       */
      reaction_pendulum_B.umin_scale5_g[kidx] =
        reaction_pendulum_P.umin_scale5_Gain_f[kidx] * yseq[kidx];
    }
  }

  /* ToWorkspace: '<S4>/To Workspace1' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (reaction_pendulum_DW.ToWorkspace1_PWORK_i.LoggedData),
                  &reaction_pendulum_B.umin_scale5_g[0], 0);

  /* ToWorkspace: '<S4>/To Workspace2' */
  {
    double locTime = reaction_pendulum_M->Timing.t[1]
      ;
    rt_UpdateStructLogVar((StructLogVar *)
                          reaction_pendulum_DW.ToWorkspace2_PWORK.LoggedData,
                          &locTime, &reaction_pendulum_B.Control);
  }

  /* ToWorkspace: '<S78>/To Workspace2' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (reaction_pendulum_DW.ToWorkspace2_PWORK_i.LoggedData),
                  &reaction_pendulum_B.TmpSignalConversionAtToWorkspac[0], 0);

  /* ToWorkspace: '<Root>/To Workspace' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (reaction_pendulum_DW.ToWorkspace_PWORK_e.LoggedData),
                  &reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[0], 0);

  /* Matfile logging */
  rt_UpdateTXYLogVars(reaction_pendulum_M->rtwLogInfo,
                      (reaction_pendulum_M->Timing.t));

  /* Update for Delay: '<S1>/Delay1' */
  reaction_pendulum_DW.Delay1_DSTATE[0] =
    reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[0];
  reaction_pendulum_DW.Delay1_DSTATE[1] =
    reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[1];

  /* Update for DiscreteIntegrator: '<S13>/Integrator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (reaction_pendulum_P.Constant_Value == 0.0) {
    reaction_pendulum_DW.Integrator_DSTATE +=
      reaction_pendulum_P.Integrator_gainval * rtb_uT;
    if (reaction_pendulum_DW.Integrator_DSTATE >=
        reaction_pendulum_P.Integrator_UpperSat) {
      reaction_pendulum_DW.Integrator_DSTATE =
        reaction_pendulum_P.Integrator_UpperSat;
    } else if (reaction_pendulum_DW.Integrator_DSTATE <=
               reaction_pendulum_P.Integrator_LowerSat) {
      reaction_pendulum_DW.Integrator_DSTATE =
        reaction_pendulum_P.Integrator_LowerSat;
    }
  }

  if (reaction_pendulum_P.Constant_Value > 0.0) {
    reaction_pendulum_DW.Integrator_PrevResetState = 1;
  } else if (reaction_pendulum_P.Constant_Value < 0.0) {
    reaction_pendulum_DW.Integrator_PrevResetState = -1;
  } else if (reaction_pendulum_P.Constant_Value == 0.0) {
    reaction_pendulum_DW.Integrator_PrevResetState = 0;
  } else {
    reaction_pendulum_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S13>/Integrator' */

  /* Update for UnitDelay: '<S81>/last_mv' */
  reaction_pendulum_DW.last_mv_DSTATE = reaction_pendulum_B.u_g;

  /* Update for Memory: '<S81>/Memory' */
  memcpy(&reaction_pendulum_DW.Memory_PreviousInput_e[0],
         &reaction_pendulum_B.iAout_f[0], 80U * sizeof(boolean_T));

  /* Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  reaction_pendulum_DW.DiscreteTimeIntegrator_DSTATE +=
    reaction_pendulum_P.DiscreteTimeIntegrator_gainval *
    reaction_pendulum_B.Delay1[0];
  if (reaction_pendulum_DW.DiscreteTimeIntegrator_DSTATE >=
      reaction_pendulum_P.DiscreteTimeIntegrator_UpperSat) {
    reaction_pendulum_DW.DiscreteTimeIntegrator_DSTATE =
      reaction_pendulum_P.DiscreteTimeIntegrator_UpperSat;
  } else if (reaction_pendulum_DW.DiscreteTimeIntegrator_DSTATE <=
             reaction_pendulum_P.DiscreteTimeIntegrator_LowerSat) {
    reaction_pendulum_DW.DiscreteTimeIntegrator_DSTATE =
      reaction_pendulum_P.DiscreteTimeIntegrator_LowerSat;
  }

  /* End of Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S103>/last_mv' */
  reaction_pendulum_DW.last_mv_DSTATE_p = reaction_pendulum_B.u;

  /* Update for Memory: '<S103>/Memory' */
  memcpy(&reaction_pendulum_DW.Memory_PreviousInput_c[0],
         &reaction_pendulum_B.iAout[0], 110U * sizeof(boolean_T));

  /* Update for Memory: '<S2>/Memory1' */
  reaction_pendulum_DW.Memory1_PreviousInput = rtb_DCAnglerad;

  /* Update for Memory: '<S2>/Memory' */
  reaction_pendulum_DW.Memory_PreviousInput = reaction_pendulum_B.SFunction_o6;

  /* Update for Memory: '<S20>/memory' */
  reaction_pendulum_DW.memory_PreviousInput = reaction_pendulum_B.DCVelrads;

  /* Update for Delay: '<S23>/MemoryX' */
  reaction_pendulum_DW.icLoad = false;
  reaction_pendulum_DW.MemoryX_DSTATE[0] = rtb_Add_i[0];
  reaction_pendulum_DW.MemoryX_DSTATE[1] = rtb_Add_i[1];
  reaction_pendulum_DW.MemoryX_DSTATE[2] = rtb_Add_i[2];

  /* Update for Delay: '<S3>/Delay' */
  reaction_pendulum_DW.Delay_DSTATE = reaction_pendulum_B.prev_signal;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)reaction_pendulum_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(1, (real_T)reaction_pendulum_M->Timing.t[1]);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(reaction_pendulum_M)!=-1) &&
        !((rtmGetTFinal(reaction_pendulum_M)-reaction_pendulum_M->Timing.t[0]) >
          reaction_pendulum_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(reaction_pendulum_M, "Simulation finished");
    }

    if (rtmGetStopRequested(reaction_pendulum_M)) {
      rtmSetErrorStatus(reaction_pendulum_M, "Simulation finished");
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
  if (!(++reaction_pendulum_M->Timing.clockTick0)) {
    ++reaction_pendulum_M->Timing.clockTickH0;
  }

  reaction_pendulum_M->Timing.t[0] = reaction_pendulum_M->Timing.clockTick0 *
    reaction_pendulum_M->Timing.stepSize0 +
    reaction_pendulum_M->Timing.clockTickH0 *
    reaction_pendulum_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++reaction_pendulum_M->Timing.clockTick1)) {
      ++reaction_pendulum_M->Timing.clockTickH1;
    }

    reaction_pendulum_M->Timing.t[1] = reaction_pendulum_M->Timing.clockTick1 *
      reaction_pendulum_M->Timing.stepSize1 +
      reaction_pendulum_M->Timing.clockTickH1 *
      reaction_pendulum_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void reaction_pendulum_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  reaction_pendulum_P.FilteredDerivative1_A = rtMinusInf;
  reaction_pendulum_P.FilteredDerivative1_B = rtInf;
  reaction_pendulum_P.Integrator_UpperSat = rtInf;
  reaction_pendulum_P.Integrator_LowerSat = rtMinusInf;
  reaction_pendulum_P.Saturation_UpperSat = rtInf;
  reaction_pendulum_P.Saturation_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)reaction_pendulum_M, 0,
                sizeof(RT_MODEL_reaction_pendulum_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&reaction_pendulum_M->solverInfo,
                          &reaction_pendulum_M->Timing.simTimeStep);
    rtsiSetTPtr(&reaction_pendulum_M->solverInfo, &rtmGetTPtr
                (reaction_pendulum_M));
    rtsiSetStepSizePtr(&reaction_pendulum_M->solverInfo,
                       &reaction_pendulum_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&reaction_pendulum_M->solverInfo, (&rtmGetErrorStatus
      (reaction_pendulum_M)));
    rtsiSetRTModelPtr(&reaction_pendulum_M->solverInfo, reaction_pendulum_M);
  }

  rtsiSetSimTimeStep(&reaction_pendulum_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&reaction_pendulum_M->solverInfo,"FixedStepDiscrete");
  reaction_pendulum_M->solverInfoPtr = (&reaction_pendulum_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = reaction_pendulum_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "reaction_pendulum_M points to
       static memory which is guaranteed to be non-NULL" */
    reaction_pendulum_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    reaction_pendulum_M->Timing.sampleTimes =
      (&reaction_pendulum_M->Timing.sampleTimesArray[0]);
    reaction_pendulum_M->Timing.offsetTimes =
      (&reaction_pendulum_M->Timing.offsetTimesArray[0]);

    /* task periods */
    reaction_pendulum_M->Timing.sampleTimes[0] = (0.0);
    reaction_pendulum_M->Timing.sampleTimes[1] = (0.05);

    /* task offsets */
    reaction_pendulum_M->Timing.offsetTimes[0] = (0.0);
    reaction_pendulum_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(reaction_pendulum_M, &reaction_pendulum_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = reaction_pendulum_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    reaction_pendulum_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(reaction_pendulum_M, 140.0);
  reaction_pendulum_M->Timing.stepSize0 = 0.05;
  reaction_pendulum_M->Timing.stepSize1 = 0.05;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    reaction_pendulum_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(reaction_pendulum_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(reaction_pendulum_M->rtwLogInfo, (NULL));
    rtliSetLogT(reaction_pendulum_M->rtwLogInfo, "");
    rtliSetLogX(reaction_pendulum_M->rtwLogInfo, "");
    rtliSetLogXFinal(reaction_pendulum_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(reaction_pendulum_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(reaction_pendulum_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(reaction_pendulum_M->rtwLogInfo, 0);
    rtliSetLogDecimation(reaction_pendulum_M->rtwLogInfo, 1);
    rtliSetLogY(reaction_pendulum_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(reaction_pendulum_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(reaction_pendulum_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  reaction_pendulum_M->Sizes.checksums[0] = (2895288125U);
  reaction_pendulum_M->Sizes.checksums[1] = (2409429721U);
  reaction_pendulum_M->Sizes.checksums[2] = (761229482U);
  reaction_pendulum_M->Sizes.checksums[3] = (1195792861U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    reaction_pendulum_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &reaction_pendulum_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &reaction_pendulum_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(reaction_pendulum_M->extModeInfo,
      &reaction_pendulum_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(reaction_pendulum_M->extModeInfo,
                        reaction_pendulum_M->Sizes.checksums);
    rteiSetTPtr(reaction_pendulum_M->extModeInfo, rtmGetTPtr(reaction_pendulum_M));
  }

  reaction_pendulum_M->solverInfoPtr = (&reaction_pendulum_M->solverInfo);
  reaction_pendulum_M->Timing.stepSize = (0.05);
  rtsiSetFixedStepSize(&reaction_pendulum_M->solverInfo, 0.05);
  rtsiSetSolverMode(&reaction_pendulum_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &reaction_pendulum_B), 0,
                sizeof(B_reaction_pendulum_T));

  /* states (dwork) */
  (void) memset((void *)&reaction_pendulum_DW, 0,
                sizeof(DW_reaction_pendulum_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    reaction_pendulum_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &reaction_pendulum_M->NonInlinedSFcns.sfcnInfo;
    reaction_pendulum_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(reaction_pendulum_M)));
    reaction_pendulum_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &reaction_pendulum_M->Sizes.numSampTimes);
    reaction_pendulum_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (reaction_pendulum_M)[0]);
    reaction_pendulum_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (reaction_pendulum_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,reaction_pendulum_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(reaction_pendulum_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(reaction_pendulum_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (reaction_pendulum_M));
    rtssSetStepSizePtr(sfcnInfo, &reaction_pendulum_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(reaction_pendulum_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &reaction_pendulum_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &reaction_pendulum_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &reaction_pendulum_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &reaction_pendulum_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &reaction_pendulum_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &reaction_pendulum_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &reaction_pendulum_M->solverInfoPtr);
  }

  reaction_pendulum_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&reaction_pendulum_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  1*sizeof(SimStruct));
    reaction_pendulum_M->childSfunctions =
      (&reaction_pendulum_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    reaction_pendulum_M->childSfunctions[0] =
      (&reaction_pendulum_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: reaction_pendulum/<S2>/S-Function (rtdacusb2_rpend_dd) */
    {
      SimStruct *rts = reaction_pendulum_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = reaction_pendulum_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = reaction_pendulum_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = reaction_pendulum_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &reaction_pendulum_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &reaction_pendulum_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, reaction_pendulum_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &reaction_pendulum_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &reaction_pendulum_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &reaction_pendulum_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &reaction_pendulum_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &reaction_pendulum_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &reaction_pendulum_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = reaction_pendulum_B.Gain;
          sfcnUPtrs[1] = &reaction_pendulum_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.UPtrs2;
          sfcnUPtrs[0] = &reaction_pendulum_B.Prescaler;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = &reaction_pendulum_B.ThermFlag;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 7);
        _ssSetPortInfo2ForOutputUnits(rts,
          &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        ssSetOutputPortUnit(rts, 6, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
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
            &reaction_pendulum_B.SFunction_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &reaction_pendulum_B.SFunction_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &reaction_pendulum_B.SFunction_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &reaction_pendulum_B.SFunction_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &reaction_pendulum_B.SFunction_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &reaction_pendulum_B.SFunction_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 2);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            reaction_pendulum_B.SFunction_o7));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "reaction_pendulum/RP Driver/S-Function");
      ssSetRTModel(rts,reaction_pendulum_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &reaction_pendulum_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)reaction_pendulum_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)reaction_pendulum_P.SFunction_P2_Size);
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
  rt_StartDataLoggingWithStartTime(reaction_pendulum_M->rtwLogInfo, 0.0,
    rtmGetTFinal(reaction_pendulum_M), reaction_pendulum_M->Timing.stepSize0,
    (&rtmGetErrorStatus(reaction_pendulum_M)));

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

    static const char_T rt_ToWksBlockName[] = "reaction_pendulum/To Workspace1";
    reaction_pendulum_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      reaction_pendulum_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_M),
      reaction_pendulum_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_M)),
      "CtrlInDist",
      1,
      0,
      1,
      0.05,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (reaction_pendulum_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace' */
  {
    int_T dimensions[2] = { 21, 4 };

    reaction_pendulum_DW.ToWorkspace_PWORK.LoggedData = rt_CreateLogVar(
      reaction_pendulum_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_M),
      reaction_pendulum_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_M)),
      "MPCI_prediction",
      SS_DOUBLE,
      0,
      0,
      0,
      84,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.05,
      1);
    if (reaction_pendulum_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace1' */
  {
    int_T dimensions[2] = { 21, 3 };

    reaction_pendulum_DW.ToWorkspace1_PWORK_i.LoggedData = rt_CreateLogVar(
      reaction_pendulum_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_M),
      reaction_pendulum_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_M)),
      "MPC_prediction",
      SS_DOUBLE,
      0,
      0,
      0,
      63,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.05,
      1);
    if (reaction_pendulum_DW.ToWorkspace1_PWORK_i.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace2' */
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
      "reaction_pendulum/State feedback controllers/To Workspace2";
    reaction_pendulum_DW.ToWorkspace2_PWORK.LoggedData = rt_CreateStructLogVar(
      reaction_pendulum_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_M),
      reaction_pendulum_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_M)),
      "CtrlIn",
      1,
      0,
      1,
      0.05,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (reaction_pendulum_DW.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S78>/To Workspace2' */
  {
    int_T dimensions[1] = { 4 };

    reaction_pendulum_DW.ToWorkspace2_PWORK_i.LoggedData = rt_CreateLogVar(
      reaction_pendulum_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_M),
      reaction_pendulum_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_M)),
      "MeasFull",
      SS_DOUBLE,
      0,
      0,
      0,
      4,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.05,
      1);
    if (reaction_pendulum_DW.ToWorkspace2_PWORK_i.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace' */
  {
    int_T dimensions[1] = { 2 };

    reaction_pendulum_DW.ToWorkspace_PWORK_e.LoggedData = rt_CreateLogVar(
      reaction_pendulum_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_M),
      reaction_pendulum_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_M)),
      "Meas",
      SS_DOUBLE,
      0,
      0,
      0,
      2,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.05,
      1);
    if (reaction_pendulum_DW.ToWorkspace_PWORK_e.LoggedData == (NULL))
      return;
  }

  /* Start for Probe: '<S8>/Probe' */
  reaction_pendulum_B.Probe[0] = 0.05;
  reaction_pendulum_B.Probe[1] = 0.0;

  /* Start for Constant: '<S11>/Constant' */
  reaction_pendulum_B.Constant = reaction_pendulum_P.FilteredDerivative1_x0;

  /* Start for Constant: '<S2>/Prescaler' */
  reaction_pendulum_B.Prescaler = reaction_pendulum_P.Prescaler_Value;

  /* Start for Constant: '<S2>/ThermFlag' */
  reaction_pendulum_B.ThermFlag = reaction_pendulum_P.ThermFlag_Value;

  /* Start for S-Function (rtdacusb2_rpend_dd): '<S2>/S-Function' */
  /* Level2 S-Function Block: '<S2>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = reaction_pendulum_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for InitialCondition: '<S20>/IC' */
  reaction_pendulum_B.IC = reaction_pendulum_P.IC_Value;

  /* Start for InitialCondition: '<S20>/IC' */
  reaction_pendulum_DW.IC_FirstOutputTime = true;

  /* Start for Enabled SubSystem: '<S51>/Enabled Subsystem' */
  reaction_pendulum_DW.EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S51>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S44>/MeasurementUpdate' */
  reaction_pendulum_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S44>/MeasurementUpdate' */

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  reaction_pendulum_DW.Delay1_DSTATE[0] =
    reaction_pendulum_P.Delay1_InitialCondition;
  reaction_pendulum_DW.Delay1_DSTATE[1] =
    reaction_pendulum_P.Delay1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Integrator' */
  reaction_pendulum_DW.Integrator_DSTATE = reaction_pendulum_B.Constant;
  if (reaction_pendulum_DW.Integrator_DSTATE >=
      reaction_pendulum_P.Integrator_UpperSat) {
    reaction_pendulum_DW.Integrator_DSTATE =
      reaction_pendulum_P.Integrator_UpperSat;
  } else if (reaction_pendulum_DW.Integrator_DSTATE <=
             reaction_pendulum_P.Integrator_LowerSat) {
    reaction_pendulum_DW.Integrator_DSTATE =
      reaction_pendulum_P.Integrator_LowerSat;
  }

  reaction_pendulum_DW.Integrator_PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S13>/Integrator' */

  /* InitializeConditions for UnitDelay: '<S81>/last_mv' */
  reaction_pendulum_DW.last_mv_DSTATE =
    reaction_pendulum_P.last_mv_InitialCondition;

  /* InitializeConditions for Memory: '<S81>/Memory' */
  memcpy(&reaction_pendulum_DW.Memory_PreviousInput_e[0],
         &reaction_pendulum_P.Memory_InitialCondition_a[0], 80U * sizeof
         (boolean_T));

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  reaction_pendulum_DW.DiscreteTimeIntegrator_DSTATE =
    reaction_pendulum_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S103>/last_mv' */
  reaction_pendulum_DW.last_mv_DSTATE_p =
    reaction_pendulum_P.last_mv_InitialCondition_n;

  /* InitializeConditions for Memory: '<S103>/Memory' */
  memcpy(&reaction_pendulum_DW.Memory_PreviousInput_c[0],
         &reaction_pendulum_P.Memory_InitialCondition_k[0], 110U * sizeof
         (boolean_T));

  /* InitializeConditions for Memory: '<S2>/Memory1' */
  reaction_pendulum_DW.Memory1_PreviousInput =
    reaction_pendulum_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  reaction_pendulum_DW.Memory_PreviousInput =
    reaction_pendulum_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S20>/memory' */
  reaction_pendulum_DW.memory_PreviousInput =
    reaction_pendulum_P.memory_InitialCondition;

  /* InitializeConditions for Delay: '<S23>/MemoryX' */
  reaction_pendulum_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  reaction_pendulum_DW.Delay_DSTATE = reaction_pendulum_P.Delay_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S51>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S77>/Product2' incorporates:
   *  Outport: '<S77>/deltax'
   */
  reaction_pendulum_B.Product2[0] = reaction_pendulum_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S51>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S44>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S75>/Product3' incorporates:
   *  Outport: '<S75>/L*(y[k]-yhat[k|k-1])'
   */
  reaction_pendulum_B.Product3[0] = reaction_pendulum_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S44>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S51>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S77>/Product2' incorporates:
   *  Outport: '<S77>/deltax'
   */
  reaction_pendulum_B.Product2[1] = reaction_pendulum_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S51>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S44>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S75>/Product3' incorporates:
   *  Outport: '<S75>/L*(y[k]-yhat[k|k-1])'
   */
  reaction_pendulum_B.Product3[1] = reaction_pendulum_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S44>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S51>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S77>/Product2' incorporates:
   *  Outport: '<S77>/deltax'
   */
  reaction_pendulum_B.Product2[2] = reaction_pendulum_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S51>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S44>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S75>/Product3' incorporates:
   *  Outport: '<S75>/L*(y[k]-yhat[k|k-1])'
   */
  reaction_pendulum_B.Product3[2] = reaction_pendulum_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S44>/MeasurementUpdate' */
}

/* Model terminate function */
void reaction_pendulum_terminate(void)
{
  /* Terminate for S-Function (rtdacusb2_rpend_dd): '<S2>/S-Function' */
  /* Level2 S-Function Block: '<S2>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = reaction_pendulum_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

#include <stdio.h>

/* Final time from "Simulation Parameters"   */
real_T finaltime = 140.0;
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
