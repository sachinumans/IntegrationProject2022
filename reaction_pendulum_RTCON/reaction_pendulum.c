/*
 * reaction_pendulum.c
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

#include "reaction_pendulum.h"
#include "reaction_pendulum_private.h"
#include "reaction_pendulum_dt.h"

/* Named constants for MATLAB Function: '<S41>/optimizer' */
#define reaction_pendulum_ny           (3)

/* Block signals (default storage) */
B_reaction_pendulum_T reaction_pendulum_B;

/* Block states (default storage) */
DW_reaction_pendulum_T reaction_pendulum_DW;

/* Real-time model */
static RT_MODEL_reaction_pendulum_T reaction_pendulum_M_;
RT_MODEL_reaction_pendulum_T *const reaction_pendulum_M = &reaction_pendulum_M_;

/* Forward declaration for local functions */
static void reaction_pendulum_Unconstrained(const real_T b_Hinv[121], const
  real_T f[11], real_T x[11], int16_T n);
static real_T reaction_pendulum_norm(const real_T x[11]);
static void reaction_pendulum_abs(const real_T x[11], real_T y[11]);
static real_T reaction_pendulum_maximum(const real_T x[11]);
static void reaction_pendulum_abs_l(const real_T x[60], real_T y[60]);
static void reaction_pendulum_maximum2(const real_T x[60], real_T y, real_T ex
  [60]);
static real_T reaction_pendulum_xnrm2(int32_T n, const real_T x[121], int32_T
  ix0);
static void reaction_pendulum_xgemv(int32_T b_m, int32_T n, const real_T b_A[121],
  int32_T ia0, const real_T x[121], int32_T ix0, real_T y[11]);
static void reaction_pendulum_xgerc(int32_T b_m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[11], real_T b_A[121], int32_T ia0);
static void reaction_pendulum_qr(const real_T b_A[121], real_T Q[121], real_T R
  [121]);
static real_T reaction_pendulum_KWIKfactor(const real_T b_Ac[660], const int16_T
  iC[60], int16_T nA, const real_T b_Linv[121], real_T RLinv[121], real_T D[121],
  real_T b_H[121], int16_T n);
static real_T reaction_pendulum_mtimes(const real_T b_A[11], const real_T B[11]);
static void reaction_pendulu_DropConstraint(int16_T kDrop, int16_T iA[60],
  int16_T *nA, int16_T iC[60]);
static void reaction_pendulum_qpkwik(const real_T b_Linv[121], const real_T
  b_Hinv[121], const real_T f[11], const real_T b_Ac[660], const real_T b[60],
  int16_T iA[60], int16_T maxiter, real_T FeasTol, real_T x[11], real_T lambda
  [60], real_T *status);

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulum_Unconstrained(const real_T b_Hinv[121], const
  real_T f[11], real_T x[11], int16_T n)
{
  real_T b_Hinv_0;
  int32_T i;
  int32_T i_0;
  for (i = 1; i - 1 < n; i++) {
    b_Hinv_0 = 0.0;
    for (i_0 = 0; i_0 < 11; i_0++) {
      b_Hinv_0 += -b_Hinv[(11 * i_0 + (int16_T)i) - 1] * f[i_0];
    }

    x[(int16_T)i - 1] = b_Hinv_0;
  }
}

/* Function for MATLAB Function: '<S41>/optimizer' */
static real_T reaction_pendulum_norm(const real_T x[11])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 11; k++) {
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

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulum_abs(const real_T x[11], real_T y[11])
{
  int32_T k;
  for (k = 0; k < 11; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Function for MATLAB Function: '<S41>/optimizer' */
static real_T reaction_pendulum_maximum(const real_T x[11])
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
    while ((!exitg1) && (k < 12)) {
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
    while (idx + 1 <= 11) {
      if (ex < x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulum_abs_l(const real_T x[60], real_T y[60])
{
  int32_T k;
  for (k = 0; k < 60; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulum_maximum2(const real_T x[60], real_T y, real_T ex
  [60])
{
  real_T u0;
  int32_T k;
  for (k = 0; k < 60; k++) {
    u0 = x[k];
    if ((u0 >= y) || rtIsNaN(y)) {
      ex[k] = u0;
    } else {
      ex[k] = y;
    }
  }
}

/* Function for MATLAB Function: '<S41>/optimizer' */
static real_T reaction_pendulum_xnrm2(int32_T n, const real_T x[121], int32_T
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

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulum_xgemv(int32_T b_m, int32_T n, const real_T b_A[121],
  int32_T ia0, const real_T x[121], int32_T ix0, real_T y[11])
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
    b = (n - 1) * 11 + ia0;
    for (iac = ia0; iac <= b; iac += 11) {
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

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulum_xgerc(int32_T b_m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[11], real_T b_A[121], int32_T ia0)
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
      jA += 11;
    }
  }
}

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulum_qr(const real_T b_A[121], real_T Q[121], real_T R
  [121])
{
  real_T c_A[121];
  real_T tau[11];
  real_T work[11];
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
  memcpy(&c_A[0], &b_A[0], 121U * sizeof(real_T));
  memset(&tau[0], 0, 11U * sizeof(real_T));
  memset(&work[0], 0, 11U * sizeof(real_T));
  for (itau = 0; itau < 11; itau++) {
    i = itau * 11 + itau;
    if (itau + 1 < 11) {
      atmp = c_A[i];
      tau[itau] = 0.0;
      beta1 = reaction_pendulum_xnrm2(10 - itau, c_A, i + 2);
      if (beta1 != 0.0) {
        beta1 = rt_hypotd_snf(c_A[i], beta1);
        if (c_A[i] >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = -1;
          c_lastc = (i - itau) + 11;
          do {
            knt++;
            for (b_coltop = i + 1; b_coltop < c_lastc; b_coltop++) {
              c_A[b_coltop] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            atmp *= 9.9792015476736E+291;
          } while (!(fabs(beta1) >= 1.0020841800044864E-292));

          beta1 = rt_hypotd_snf(atmp, reaction_pendulum_xnrm2(10 - itau, c_A, i
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
          knt = (i - itau) + 11;
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
        knt = 11 - itau;
        c_lastc = (i - itau) + 10;
        while ((knt > 0) && (c_A[c_lastc] == 0.0)) {
          knt--;
          c_lastc--;
        }

        c_lastc = 10 - itau;
        exitg2 = false;
        while ((!exitg2) && (c_lastc > 0)) {
          b_coltop = ((c_lastc - 1) * 11 + i) + 11;
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
        reaction_pendulum_xgemv(knt, c_lastc, c_A, i + 12, c_A, i + 1, work);
        reaction_pendulum_xgerc(knt, c_lastc, -tau[itau], i + 1, work, c_A, i +
          12);
      }

      c_A[i] = beta1;
    } else {
      tau[10] = 0.0;
    }
  }

  for (itau = 0; itau < 11; itau++) {
    for (i = 0; i <= itau; i++) {
      R[i + 11 * itau] = c_A[11 * itau + i];
    }

    for (i = itau + 1; i + 1 < 12; i++) {
      R[i + 11 * itau] = 0.0;
    }

    work[itau] = 0.0;
  }

  for (i = 10; i >= 0; i--) {
    knt = (i * 11 + i) + 12;
    if (i + 1 < 11) {
      c_A[knt - 12] = 1.0;
      if (tau[i] != 0.0) {
        c_lastc = 11 - i;
        b_coltop = knt - i;
        while ((c_lastc > 0) && (c_A[b_coltop - 2] == 0.0)) {
          c_lastc--;
          b_coltop--;
        }

        b_coltop = 10 - i;
        exitg2 = false;
        while ((!exitg2) && (b_coltop > 0)) {
          coltop = (b_coltop - 1) * 11 + knt;
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
        reaction_pendulum_xgemv(c_lastc, b_coltop, c_A, knt, c_A, knt - 11, work);
        reaction_pendulum_xgerc(c_lastc, b_coltop, -tau[i], knt - 11, work, c_A,
          knt);
      }

      c_lastc = (knt - i) - 1;
      for (b_coltop = knt - 11; b_coltop < c_lastc; b_coltop++) {
        c_A[b_coltop] *= -tau[i];
      }
    }

    c_A[knt - 12] = 1.0 - tau[i];
    for (c_lastc = 0; c_lastc < i; c_lastc++) {
      c_A[(knt - c_lastc) - 13] = 0.0;
    }
  }

  for (itau = 0; itau < 11; itau++) {
    memcpy(&Q[itau * 11], &c_A[itau * 11], 11U * sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<S41>/optimizer' */
static real_T reaction_pendulum_KWIKfactor(const real_T b_Ac[660], const int16_T
  iC[60], int16_T nA, const real_T b_Linv[121], real_T RLinv[121], real_T D[121],
  real_T b_H[121], int16_T n)
{
  real_T QQ[121];
  real_T RR[121];
  real_T TL[121];
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
  memset(&RLinv[0], 0, 121U * sizeof(real_T));
  for (i = 1; i - 1 < nA; i++) {
    iC_0 = iC[(int16_T)i - 1];
    for (i_0 = 0; i_0 < 11; i_0++) {
      tmp = ((int16_T)i - 1) * 11 + i_0;
      RLinv[tmp] = 0.0;
      for (f_i = 0; f_i < 11; f_i++) {
        RLinv[tmp] += b_Ac[(60 * f_i + iC_0) - 1] * b_Linv[11 * f_i + i_0];
      }
    }
  }

  reaction_pendulum_qr(RLinv, QQ, RR);
  i = 1;
  do {
    exitg1 = 0;
    if (i - 1 <= nA - 1) {
      if (fabs(RR[(((int16_T)i - 1) * 11 + (int16_T)i) - 1]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      for (i = 1; i - 1 < n; i++) {
        for (f_i = 1; f_i - 1 < n; f_i++) {
          b_Linv_0 = 0.0;
          for (i_0 = 0; i_0 < 11; i_0++) {
            b_Linv_0 += b_Linv[((int16_T)i - 1) * 11 + i_0] * QQ[((int16_T)f_i -
              1) * 11 + i_0];
          }

          TL[((int16_T)i + 11 * ((int16_T)f_i - 1)) - 1] = b_Linv_0;
        }
      }

      memset(&RLinv[0], 0, 121U * sizeof(real_T));
      for (b_j = nA; b_j > 0; b_j--) {
        i_0 = (b_j - 1) * 11;
        tmp = (b_j + i_0) - 1;
        RLinv[tmp] = 1.0;
        for (c_k = b_j; c_k <= nA; c_k++) {
          f_i = ((c_k - 1) * 11 + b_j) - 1;
          RLinv[f_i] /= RR[tmp];
        }

        if (b_j > 1) {
          for (i = 1; i - 1 <= b_j - 2; i++) {
            for (c_k = b_j; c_k <= nA; c_k++) {
              tmp = (c_k - 1) * 11;
              f_i = (tmp + (int16_T)i) - 1;
              RLinv[f_i] -= RR[(i_0 + (int16_T)i) - 1] * RLinv[(tmp + b_j) - 1];
            }
          }
        }
      }

      for (i = 1; i - 1 < n; i++) {
        for (b_j = (int16_T)i; b_j <= n; b_j++) {
          i_0 = ((b_j - 1) * 11 + (int16_T)i) - 1;
          b_H[i_0] = 0.0;
          tmp = nA + 1;
          if (nA + 1 > 32767) {
            tmp = 32767;
          }

          for (c_k = (int16_T)tmp; c_k <= n; c_k++) {
            tmp = (c_k - 1) * 11;
            b_H[i_0] -= TL[(tmp + (int16_T)i) - 1] * TL[(tmp + b_j) - 1];
          }

          b_H[(b_j + 11 * ((int16_T)i - 1)) - 1] = b_H[i_0];
        }
      }

      for (i = 1; i - 1 < nA; i++) {
        for (f_i = 1; f_i - 1 < n; f_i++) {
          i_0 = (((int16_T)i - 1) * 11 + (int16_T)f_i) - 1;
          D[i_0] = 0.0;
          for (b_j = (int16_T)i; b_j <= nA; b_j++) {
            tmp = (b_j - 1) * 11;
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

/* Function for MATLAB Function: '<S41>/optimizer' */
static real_T reaction_pendulum_mtimes(const real_T b_A[11], const real_T B[11])
{
  real_T b_C;
  int32_T k;
  b_C = 0.0;
  for (k = 0; k < 11; k++) {
    b_C += b_A[k] * B[k];
  }

  return b_C;
}

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulu_DropConstraint(int16_T kDrop, int16_T iA[60],
  int16_T *nA, int16_T iC[60])
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

/* Function for MATLAB Function: '<S41>/optimizer' */
static void reaction_pendulum_qpkwik(const real_T b_Linv[121], const real_T
  b_Hinv[121], const real_T f[11], const real_T b_Ac[660], const real_T b[60],
  int16_T iA[60], int16_T maxiter, real_T FeasTol, real_T x[11], real_T lambda
  [60], real_T *status)
{
  real_T D[121];
  real_T RLinv[121];
  real_T U[121];
  real_T b_H[121];
  real_T cTol[60];
  real_T tmp_2[60];
  real_T Opt[22];
  real_T Rhs[22];
  real_T b_Ac_0[11];
  real_T r[11];
  real_T z[11];
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
  int16_T iC[60];
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
  memset(&lambda[0], 0, 60U * sizeof(real_T));
  memset(&x[0], 0, 11U * sizeof(real_T));
  memset(&r[0], 0, 11U * sizeof(real_T));
  rMin = 0.0;
  cTolComputed = false;
  for (i = 0; i < 60; i++) {
    cTol[i] = 1.0;
    iC[i] = 0;
  }

  nA = 0;
  for (i = 0; i < 60; i++) {
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
    memset(&Opt[0], 0, 22U * sizeof(real_T));
    for (i = 0; i < 11; i++) {
      Rhs[i] = f[i];
      Rhs[i + 11] = 0.0;
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
          b_H, 11);
        if (Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            memset(&iA[0], 0, 60U * sizeof(int16_T));
            memset(&iC[0], 0, 60U * sizeof(int16_T));
            ColdReset = true;
          }
        } else {
          for (i = 1; i - 1 < nA; i++) {
            U_tmp = (int16_T)i + 11;
            if ((int16_T)i + 11 > 32767) {
              U_tmp = 32767;
            }

            Rhs[U_tmp - 1] = b[iC[(int16_T)i - 1] - 1];
            for (kNext = (int16_T)i; kNext <= nA; kNext++) {
              U_tmp = (((int16_T)i - 1) * 11 + kNext) - 1;
              U[U_tmp] = 0.0;
              for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
              {
                U_tmp_0 = ((int16_T)lambda_tmp_tmp - 1) * 11;
                U[U_tmp] += RLinv[(U_tmp_0 + kNext) - 1] * RLinv[(U_tmp_0 +
                  (int16_T)i) - 1];
              }

              U[((int16_T)i + 11 * (kNext - 1)) - 1] = U[U_tmp];
            }
          }

          for (i = 0; i < 11; i++) {
            Xnorm0 = 0.0;
            for (U_tmp = 0; U_tmp < 11; U_tmp++) {
              Xnorm0 += b_H[11 * U_tmp + i] * Rhs[U_tmp];
            }

            Opt[i] = Xnorm0;
            for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
            {
              U_tmp = (int16_T)lambda_tmp_tmp + 11;
              if ((int16_T)lambda_tmp_tmp + 11 > 32767) {
                U_tmp = 32767;
              }

              Opt[i] += D[((int16_T)lambda_tmp_tmp - 1) * 11 + i] * Rhs[U_tmp -
                1];
            }
          }

          for (i = 1; i - 1 < nA; i++) {
            Xnorm0 = 0.0;
            for (U_tmp = 0; U_tmp < 11; U_tmp++) {
              Xnorm0 += D[((int16_T)i - 1) * 11 + U_tmp] * Rhs[U_tmp];
            }

            U_tmp = (int16_T)i + 11;
            if ((int16_T)i + 11 > 32767) {
              U_tmp = 32767;
            }

            Opt[U_tmp - 1] = Xnorm0;
            for (lambda_tmp_tmp = 1; lambda_tmp_tmp - 1 < nA; lambda_tmp_tmp++)
            {
              U_tmp = (int16_T)i + 11;
              if ((int16_T)i + 11 > 32767) {
                U_tmp = 32767;
              }

              U_tmp_0 = (int16_T)i + 11;
              if ((int16_T)i + 11 > 32767) {
                U_tmp_0 = 32767;
              }

              tmp = (int16_T)lambda_tmp_tmp + 11;
              if ((int16_T)lambda_tmp_tmp + 11 > 32767) {
                tmp = 32767;
              }

              Opt[U_tmp - 1] = U[(((int16_T)lambda_tmp_tmp - 1) * 11 + (int16_T)
                                  i) - 1] * Rhs[tmp - 1] + Opt[U_tmp_0 - 1];
            }
          }

          Xnorm0 = -1.0E-12;
          kDrop = 0;
          for (i = 1; i - 1 < nA; i++) {
            U_tmp = (int16_T)i + 11;
            if ((int16_T)i + 11 > 32767) {
              U_tmp = 32767;
            }

            lambda[iC[(int16_T)i - 1] - 1] = Opt[U_tmp - 1];
            U_tmp = (int16_T)i + 11;
            if ((int16_T)i + 11 > 32767) {
              U_tmp = 32767;
            }

            if ((Opt[U_tmp - 1] < Xnorm0) && ((int16_T)i <= nA)) {
              kDrop = (int16_T)i;
              U_tmp = (int16_T)i + 11;
              if ((int16_T)i + 11 > 32767) {
                U_tmp = 32767;
              }

              Xnorm0 = Opt[U_tmp - 1];
            }
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            memcpy(&x[0], &Opt[0], 11U * sizeof(real_T));
          } else {
            (*status)++;
            if ((int32_T)*status > q) {
              nA = 0;
              memset(&iA[0], 0, 60U * sizeof(int16_T));
              memset(&iC[0], 0, 60U * sizeof(int16_T));
              ColdReset = true;
            } else {
              lambda[iC[kDrop - 1] - 1] = 0.0;
              reaction_pendulu_DropConstraint(kDrop, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          memset(&lambda[0], 0, 60U * sizeof(real_T));
          reaction_pendulum_Unconstrained(b_Hinv, f, x, 11);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    reaction_pendulum_Unconstrained(b_Hinv, f, x, 11);
    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = reaction_pendulum_norm(x);
    exitg2 = false;
    while ((!exitg2) && ((int32_T)*status <= maxiter)) {
      cMin = -FeasTol;
      kNext = 0;
      for (i = 0; i < 60; i++) {
        t = cTol[i];
        if (!cTolComputed) {
          for (U_tmp = 0; U_tmp < 11; U_tmp++) {
            b_Ac_0[U_tmp] = b_Ac[60 * U_tmp + i] * x[U_tmp];
          }

          reaction_pendulum_abs(b_Ac_0, z);
          cVal = reaction_pendulum_maximum(z);
          if ((!(t >= cVal)) && (!rtIsNaN(cVal))) {
            t = cVal;
          }
        }

        if (iA[i] == 0) {
          b_Ac_1 = 0.0;
          for (U_tmp = 0; U_tmp < 11; U_tmp++) {
            b_Ac_1 += b_Ac[60 * U_tmp + i] * x[U_tmp];
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
              for (U_tmp = 0; U_tmp < 11; U_tmp++) {
                z[U_tmp] = 0.0;
                for (U_tmp_0 = 0; U_tmp_0 < 11; U_tmp_0++) {
                  z[U_tmp] += b_Ac[(60 * U_tmp_0 + kNext) - 1] * b_Hinv[11 *
                    U_tmp_0 + U_tmp];
                }
              }

              guard2 = true;
            } else {
              cMin = reaction_pendulum_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D,
                b_H, 11);
              if (cMin <= 0.0) {
                *status = -2.0;
                exitg1 = 1;
              } else {
                for (U_tmp = 0; U_tmp < 121; U_tmp++) {
                  U[U_tmp] = -b_H[U_tmp];
                }

                for (U_tmp = 0; U_tmp < 11; U_tmp++) {
                  z[U_tmp] = 0.0;
                  for (U_tmp_0 = 0; U_tmp_0 < 11; U_tmp_0++) {
                    z[U_tmp] += b_Ac[(60 * U_tmp_0 + kNext) - 1] * U[11 *
                      U_tmp_0 + U_tmp];
                  }
                }

                for (i = 1; i - 1 < nA; i++) {
                  b_Ac_1 = 0.0;
                  for (U_tmp = 0; U_tmp < 11; U_tmp++) {
                    b_Ac_1 += b_Ac[(60 * U_tmp + kNext) - 1] * D[((int16_T)i - 1)
                      * 11 + U_tmp];
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

              for (U_tmp = 0; U_tmp < 11; U_tmp++) {
                b_Ac_0[U_tmp] = b_Ac[(60 * U_tmp + kNext) - 1];
              }

              cVal = reaction_pendulum_mtimes(z, b_Ac_0);
              if (cVal <= 0.0) {
                cVal = 0.0;
                ColdReset = true;
              } else {
                b_Ac_1 = 0.0;
                for (U_tmp = 0; U_tmp < 11; U_tmp++) {
                  b_Ac_1 += b_Ac[(60 * U_tmp + kNext) - 1] * x[U_tmp];
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
                  if ((lambda_tmp_tmp <= 60) && (lambda[lambda_tmp_tmp - 1] <
                       0.0)) {
                    lambda[lambda_tmp_tmp - 1] = 0.0;
                  }
                }

                lambda[kNext - 1] += t;
                if (t == cMin) {
                  reaction_pendulu_DropConstraint(kDrop, iA, &nA, iC);
                }

                if (!ColdReset) {
                  for (U_tmp = 0; U_tmp < 11; U_tmp++) {
                    x[U_tmp] += t * z[U_tmp];
                  }

                  if (t == cVal) {
                    if (nA == 11) {
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
              reaction_pendulum_abs_l(b, tmp_2);
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

/* Model step function */
void reaction_pendulum_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;
  real_T rtb_uT;
  real_T rtb_DCAnglerad;
  real_T rtb_Saturation_h;
  real_T rtb_uT_a;

  {
    real_T a__1[60];
    real_T b_Mlim[60];
    real_T rseq[45];
    real_T f[11];
    real_T zopt[11];
    real_T rtb_xest_i[6];
    real_T xk[6];
    real_T tmp[3];
    real_T y_innov[3];
    real_T b_Kr;
    real_T rtb_Integrator;
    real_T rtb_last_mv;
    int32_T i;
    int32_T i_0;
    int16_T iAnew[60];
    static const int8_T a[18] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0,
      1, 0 };

    static const real_T b_a[18] = { 4.1883368170400539E-6, 4.1288553374434273E-6,
      -0.00029761964677087676, 0.048765464764217524, 7.2777568797646188E-5,
      -4.1234430919049665E-6, -4.1488028546203055E-6, 0.00012717886562692605,
      -0.0089283865455875, 4.1542151006232131E-6, -2.0976474542413025E-5,
      0.048762439408270464, -0.00023272469835304723, -0.0094092485635289009,
      0.99501150628584667, 7.88262037982679E-6, 0.0024678189085429948,
      0.00045988554339899127 };

    static const real_T b_Kx[60] = { 626031.835721289, -932012.22466347984,
      4344.83877973787, -4.4554019608928012E+6, 1983.4032638838307, 0.0,
      689187.28837482654, -788054.35596959852, 3802.8719874586932,
      -3.7832902254359424E+6, 1759.3388205148526, 0.0, 703974.31140845828,
      -652616.15090320411, 3275.2244442162478, -3.1594504335975191E+6,
      1545.8886353120631, 0.0, 679078.76538865315, -528221.20000876242,
      2770.060669890061, -2.5889684533725609E+6, 1343.5523881509398, 0.0,
      623723.24377404526, -416735.6902584288, 2295.1105817468747,
      -2.0758160566857033E+6, 1152.8532819807397, 0.0, 547207.91529849381,
      -319357.17177862406, 1857.2924341783482, -1.6227130260299752E+6,
      974.33915020349775, 0.0, 458472.30030177603, -236629.67684147198,
      1462.3816668640593, -1.2310209237226446E+6, 808.58361618431786, 0.0,
      365694.84599459736, -168483.40817838162, 1114.7377605533204,
      -900672.59756836947, 656.18730734710459, 0.0, 275945.37336789892,
      -114296.3745046507, 817.09895779281271, -630140.61367929238,
      517.7791264254156, 0.0, 194903.16151320119, -72974.624986224866,
      570.45213487938, -416446.804809041, 394.017582559085, 0.0 };

    static const real_T b_Linv[121] = { 0.00064756724452186179,
      -0.010144352002754804, 0.036898791436627429, -0.0088493145989061491,
      -0.0054695487027757155, -0.0033815282168629056, -0.002103336101080639,
      -0.0013170214045082698, -0.00083401766628959061, -0.00053729659502239847,
      0.0, 0.0, 0.011440032067765334, -0.082660160253572812,
      0.057059311786225517, 0.0048037675952015916, 0.0029060936945329865,
      0.0018219368334529478, 0.0011587084646059922, 0.00075286010856210467,
      0.00050324812496084308, 0.0, 0.0, 0.0, 0.047103288425444388,
      -0.0963611988407509, 0.046779497872182232, -0.00055609502430030021,
      -0.00041306339414708018, -0.00025397395999228527, -0.00015567210943752359,
      -9.53606872200102E-5, 0.0, 0.0, 0.0, 0.0, 0.049531164091279556,
      -0.095620051238150275, 0.045817452202562461, -0.00040251513684267992,
      -0.00031277115146393812, -0.00018861084536762613, -0.00011232539545980411,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.051083389242319616, -0.095301689471505052,
      0.044783768800223486, -0.00030593639725944315, -0.00024668966334754136,
      -0.00014418829750780017, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.052404466894742652, -0.09513205793051159, 0.043611719234898171,
      -0.00023618516782781819, -0.00019673855394551813, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.053765408198887005, -0.09498868403829408, 0.042250827001834024,
      -0.00017740728758878891, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.055315674023039427, -0.094804892753352563, 0.040633757551808196, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.057185664680453635,
      -0.094521487031106535, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.059545440992741415, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.003162277660168379 };

    static const real_T b_Hinv[121] = { 0.0015916519365723398,
      -0.0037134054864740025, 0.0023381870589243734, -6.8775125983187524E-5,
      -5.0646910758849491E-5, -3.4247369841027933E-5, -2.3127209792870898E-5,
      -1.5615350861711191E-5, 3.0922185362563275E-6, -3.1993562694507109E-5, 0.0,
      -0.0037134054864740025, 0.010256345168195027, -0.0091699793333096941,
      0.0024987331475144169, 4.9417512571584472E-5, 2.9224135956419845E-5,
      1.9612667644835912E-5, 1.3168780163434852E-5, -4.5149553973925708E-6,
      2.9966131529563639E-5, 0.0, 0.0023381870589243734, -0.0091699793333096941,
      0.01369309953697315, -0.0092711334195710263, 0.0024242834106178723,
      -8.67005019460699E-7, -4.64422744266707E-6, -3.1651261858328295E-6,
      1.1142090995049519E-7, -5.6782941738863872E-6, 0.0, -6.8775125983187524E-5,
      0.0024987331475144169, -0.0092711334195710263, 0.013696077376631871,
      -0.0092689446313473315, 0.0024257574086442844, 1.1929258956251241E-7,
      -3.9841189770175889E-6, -1.686731480721734E-7, -6.68846520733811E-6, 0.0,
      -5.0646910758849491E-5, 4.9417512571584472E-5, 0.0024242834106178723,
      -0.0092689446313473315, 0.013697685863691692, -0.009267862099196356,
      0.0024264808437692124, 6.0539673169791656E-7, -4.7822007540562937E-7,
      -8.5857557610945585E-6, 0.0, -3.4247369841027933E-5, 2.9224135956419845E-5,
      -8.67005019460699E-7, 0.0024257574086442844, -0.009267862099196356,
      0.013698413140732089, -0.0092673778620177283, 0.0024268089275856788,
      5.0896148653816692E-6, -1.1714883954960124E-5, 0.0, -2.3127209792870898E-5,
      1.9612667644835912E-5, -4.64422744266707E-6, 1.1929258956251241E-7,
      0.0024264808437692124, -0.0092673778620177283, 0.013698733069804408,
      -0.0092671569295008967, 0.0024329104260317844, -1.0563795174800536E-5, 0.0,
      -1.5615350861711191E-5, 1.3168780163434852E-5, -3.1651261858328295E-6,
      -3.9841189770175889E-6, 6.0539673169791656E-7, 0.0024268089275856788,
      -0.0092671569295008967, 0.01369889373537697, -0.009262243994517954,
      0.002419555012614556, 0.0, 3.0922185362563275E-6, -4.5149553973925708E-6,
      1.1142090995049519E-7, -1.686731480721734E-7, -4.7822007540562937E-7,
      5.0896148653816692E-6, 0.0024329104260317844, -0.009262243994517954,
      0.012204511755516923, -0.0056283236285569272, 0.0, -3.1993562694507109E-5,
      2.9966131529563639E-5, -5.6782941738863872E-6, -6.68846520733811E-6,
      -8.5857557610945585E-6, -1.1714883954960124E-5, -1.0563795174800536E-5,
      0.002419555012614556, -0.0056283236285569272, 0.0035456595430200495, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.9999999999999974E-6 };

    static const real_T b_Ac[660] = { 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042451303288620262,
      -57.947594890272953, 0.074527760150184724, -75.553210635790776,
      0.11445398417604566, -92.3672822994138, 0.16123277935678587,
      -108.42539750515014, 0.21369380887025144, -123.76154386633067,
      0.27053198388907707, -138.40818092168897, 0.33034832615427506,
      -152.39630883721321, 0.39169210230733059, -165.75553401917989,
      0.45310303065572821, -178.51413177724191, 0.51315239668685753,
      -190.69910617020003, 0.57048198022495844, -202.33624716112328,
      0.62383979183842342, -213.45018520278953, 0.67211173545685909,
      -224.0644433689782, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042451303288620262,
      57.947594890272953, -0.074527760150184724, 75.553210635790776,
      -0.11445398417604566, 92.3672822994138, -0.16123277935678587,
      108.42539750515014, -0.21369380887025144, 123.76154386633067,
      -0.27053198388907707, 138.40818092168897, -0.33034832615427506,
      152.39630883721321, -0.39169210230733059, 165.75553401917989,
      -0.45310303065572821, 178.51413177724191, -0.51315239668685753,
      190.69910617020003, -0.57048198022495844, 202.33624716112328,
      -0.62383979183842342, 213.45018520278953, -0.67211173545685909,
      224.0644433689782, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042451303288620262,
      -57.947594890272953, 0.074527760150184724, -75.553210635790776,
      0.11445398417604566, -92.3672822994138, 0.16123277935678587,
      -108.42539750515014, 0.21369380887025144, -123.76154386633067,
      0.27053198388907707, -138.40818092168897, 0.33034832615427506,
      -152.39630883721321, 0.39169210230733059, -165.75553401917989,
      0.45310303065572821, -178.51413177724191, 0.51315239668685753,
      -190.69910617020003, 0.57048198022495844, -202.33624716112328,
      0.62383979183842342, -213.45018520278953, 0.0, 0.0, -0.0047670535042916235,
      20.210925122845889, -0.019013924333112827, 39.513172105611375,
      -0.042451303288620262, 57.947594890272953, -0.074527760150184724,
      75.553210635790776, -0.11445398417604566, 92.3672822994138,
      -0.16123277935678587, 108.42539750515014, -0.21369380887025144,
      123.76154386633067, -0.27053198388907707, 138.40818092168897,
      -0.33034832615427506, 152.39630883721321, -0.39169210230733059,
      165.75553401917989, -0.45310303065572821, 178.51413177724191,
      -0.51315239668685753, 190.69910617020003, -0.57048198022495844,
      202.33624716112328, -0.62383979183842342, 213.45018520278953, -0.0, -0.0,
      -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042451303288620262,
      -57.947594890272953, 0.074527760150184724, -75.553210635790776,
      0.11445398417604566, -92.3672822994138, 0.16123277935678587,
      -108.42539750515014, 0.21369380887025144, -123.76154386633067,
      0.27053198388907707, -138.40818092168897, 0.33034832615427506,
      -152.39630883721321, 0.39169210230733059, -165.75553401917989,
      0.45310303065572821, -178.51413177724191, 0.51315239668685753,
      -190.69910617020003, 0.57048198022495844, -202.33624716112328, 0.0, 0.0,
      0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042451303288620262,
      57.947594890272953, -0.074527760150184724, 75.553210635790776,
      -0.11445398417604566, 92.3672822994138, -0.16123277935678587,
      108.42539750515014, -0.21369380887025144, 123.76154386633067,
      -0.27053198388907707, 138.40818092168897, -0.33034832615427506,
      152.39630883721321, -0.39169210230733059, 165.75553401917989,
      -0.45310303065572821, 178.51413177724191, -0.51315239668685753,
      190.69910617020003, -0.57048198022495844, 202.33624716112328, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042451303288620262,
      -57.947594890272953, 0.074527760150184724, -75.553210635790776,
      0.11445398417604566, -92.3672822994138, 0.16123277935678587,
      -108.42539750515014, 0.21369380887025144, -123.76154386633067,
      0.27053198388907707, -138.40818092168897, 0.33034832615427506,
      -152.39630883721321, 0.39169210230733059, -165.75553401917989,
      0.45310303065572821, -178.51413177724191, 0.51315239668685753,
      -190.69910617020003, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
      20.210925122845889, -0.019013924333112827, 39.513172105611375,
      -0.042451303288620262, 57.947594890272953, -0.074527760150184724,
      75.553210635790776, -0.11445398417604566, 92.3672822994138,
      -0.16123277935678587, 108.42539750515014, -0.21369380887025144,
      123.76154386633067, -0.27053198388907707, 138.40818092168897,
      -0.33034832615427506, 152.39630883721321, -0.39169210230733059,
      165.75553401917989, -0.45310303065572821, 178.51413177724191,
      -0.51315239668685753, 190.69910617020003, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042451303288620262,
      -57.947594890272953, 0.074527760150184724, -75.553210635790776,
      0.11445398417604566, -92.3672822994138, 0.16123277935678587,
      -108.42539750515014, 0.21369380887025144, -123.76154386633067,
      0.27053198388907707, -138.40818092168897, 0.33034832615427506,
      -152.39630883721321, 0.39169210230733059, -165.75553401917989,
      0.45310303065572821, -178.51413177724191, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042451303288620262,
      57.947594890272953, -0.074527760150184724, 75.553210635790776,
      -0.11445398417604566, 92.3672822994138, -0.16123277935678587,
      108.42539750515014, -0.21369380887025144, 123.76154386633067,
      -0.27053198388907707, 138.40818092168897, -0.33034832615427506,
      152.39630883721321, -0.39169210230733059, 165.75553401917989,
      -0.45310303065572821, 178.51413177724191, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042451303288620262,
      -57.947594890272953, 0.074527760150184724, -75.553210635790776,
      0.11445398417604566, -92.3672822994138, 0.16123277935678587,
      -108.42539750515014, 0.21369380887025144, -123.76154386633067,
      0.27053198388907707, -138.40818092168897, 0.33034832615427506,
      -152.39630883721321, 0.39169210230733059, -165.75553401917989, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
      20.210925122845889, -0.019013924333112827, 39.513172105611375,
      -0.042451303288620262, 57.947594890272953, -0.074527760150184724,
      75.553210635790776, -0.11445398417604566, 92.3672822994138,
      -0.16123277935678587, 108.42539750515014, -0.21369380887025144,
      123.76154386633067, -0.27053198388907707, 138.40818092168897,
      -0.33034832615427506, 152.39630883721321, -0.39169210230733059,
      165.75553401917989, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042451303288620262,
      -57.947594890272953, 0.074527760150184724, -75.553210635790776,
      0.11445398417604566, -92.3672822994138, 0.16123277935678587,
      -108.42539750515014, 0.21369380887025144, -123.76154386633067,
      0.27053198388907707, -138.40818092168897, 0.33034832615427506,
      -152.39630883721321, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
      39.513172105611375, -0.042451303288620262, 57.947594890272953,
      -0.074527760150184724, 75.553210635790776, -0.11445398417604566,
      92.3672822994138, -0.16123277935678587, 108.42539750515014,
      -0.21369380887025144, 123.76154386633067, -0.27053198388907707,
      138.40818092168897, -0.33034832615427506, 152.39630883721321, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042451303288620262, -57.947594890272953,
      0.074527760150184724, -75.553210635790776, 0.11445398417604566,
      -92.3672822994138, 0.16123277935678587, -108.42539750515014,
      0.21369380887025144, -123.76154386633067, 0.27053198388907707,
      -138.40818092168897, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042451303288620262,
      57.947594890272953, -0.074527760150184724, 75.553210635790776,
      -0.11445398417604566, 92.3672822994138, -0.16123277935678587,
      108.42539750515014, -0.21369380887025144, 123.76154386633067,
      -0.27053198388907707, 138.40818092168897, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042451303288620262, -57.947594890272953,
      0.074527760150184724, -75.553210635790776, 0.11445398417604566,
      -92.3672822994138, 0.16123277935678587, -108.42539750515014,
      0.21369380887025144, -123.76154386633067, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
      20.210925122845889, -0.019013924333112827, 39.513172105611375,
      -0.042451303288620262, 57.947594890272953, -0.074527760150184724,
      75.553210635790776, -0.11445398417604566, 92.3672822994138,
      -0.16123277935678587, 108.42539750515014, -0.21369380887025144,
      123.76154386633067, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042451303288620262, -57.947594890272953,
      0.074527760150184724, -75.553210635790776, 0.11445398417604566,
      -92.3672822994138, 0.16123277935678587, -108.42539750515014, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
      39.513172105611375, -0.042451303288620262, 57.947594890272953,
      -0.074527760150184724, 75.553210635790776, -0.11445398417604566,
      92.3672822994138, -0.16123277935678587, 108.42539750515014, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

    static const real_T b_Ku1[10] = { 2.3846807941988106E+6,
      2.1145955927640572E+6, 1.8427794364081917E+6, 1.5751266593495891E+6,
      1.3173459730622491E+6, 1.0747255474936946E+6, 851913.14913855866,
      652720.09868104383, 479957.00437514088, 335308.13877843315 };

    static const real_T b_Kr_0[450] = { 4767.0535042916235, 0.0,
      -20.210925122845889, 19013.924333112827, 0.0, -39.513172105611375,
      42451.303288620264, 0.0, -57.947594890272953, 74527.760150184724, 0.0,
      -75.553210635790776, 114453.98417604566, 0.0, -92.3672822994138,
      161232.77935678588, 0.0, -108.42539750515014, 213693.80887025144, 0.0,
      -123.76154386633067, 270531.98388907709, 0.0, -138.40818092168897,
      330348.32615427504, 0.0, -152.39630883721321, 391692.10230733058, 0.0,
      -165.75553401917989, 453103.03065572819, 0.0, -178.51413177724191,
      513152.39668685751, 0.0, -190.69910617020003, 570481.98022495839, 0.0,
      -202.33624716112328, 623839.79183842347, 0.0, -213.45018520278953,
      672111.73545685911, 0.0, -224.0644433689782, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42451.303288620264, 0.0, -57.947594890272953,
      74527.760150184724, 0.0, -75.553210635790776, 114453.98417604566, 0.0,
      -92.3672822994138, 161232.77935678588, 0.0, -108.42539750515014,
      213693.80887025144, 0.0, -123.76154386633067, 270531.98388907709, 0.0,
      -138.40818092168897, 330348.32615427504, 0.0, -152.39630883721321,
      391692.10230733058, 0.0, -165.75553401917989, 453103.03065572819, 0.0,
      -178.51413177724191, 513152.39668685751, 0.0, -190.69910617020003,
      570481.98022495839, 0.0, -202.33624716112328, 623839.79183842347, 0.0,
      -213.45018520278953, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42451.303288620264, 0.0, -57.947594890272953,
      74527.760150184724, 0.0, -75.553210635790776, 114453.98417604566, 0.0,
      -92.3672822994138, 161232.77935678588, 0.0, -108.42539750515014,
      213693.80887025144, 0.0, -123.76154386633067, 270531.98388907709, 0.0,
      -138.40818092168897, 330348.32615427504, 0.0, -152.39630883721321,
      391692.10230733058, 0.0, -165.75553401917989, 453103.03065572819, 0.0,
      -178.51413177724191, 513152.39668685751, 0.0, -190.69910617020003,
      570481.98022495839, 0.0, -202.33624716112328, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, 4767.0535042916235, 0.0, -20.210925122845889,
      19013.924333112827, 0.0, -39.513172105611375, 42451.303288620264, 0.0,
      -57.947594890272953, 74527.760150184724, 0.0, -75.553210635790776,
      114453.98417604566, 0.0, -92.3672822994138, 161232.77935678588, 0.0,
      -108.42539750515014, 213693.80887025144, 0.0, -123.76154386633067,
      270531.98388907709, 0.0, -138.40818092168897, 330348.32615427504, 0.0,
      -152.39630883721321, 391692.10230733058, 0.0, -165.75553401917989,
      453103.03065572819, 0.0, -178.51413177724191, 513152.39668685751, 0.0,
      -190.69910617020003, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, 4767.0535042916235, 0.0, -20.210925122845889,
      19013.924333112827, 0.0, -39.513172105611375, 42451.303288620264, 0.0,
      -57.947594890272953, 74527.760150184724, 0.0, -75.553210635790776,
      114453.98417604566, 0.0, -92.3672822994138, 161232.77935678588, 0.0,
      -108.42539750515014, 213693.80887025144, 0.0, -123.76154386633067,
      270531.98388907709, 0.0, -138.40818092168897, 330348.32615427504, 0.0,
      -152.39630883721321, 391692.10230733058, 0.0, -165.75553401917989,
      453103.03065572819, 0.0, -178.51413177724191, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42451.303288620264, 0.0, -57.947594890272953,
      74527.760150184724, 0.0, -75.553210635790776, 114453.98417604566, 0.0,
      -92.3672822994138, 161232.77935678588, 0.0, -108.42539750515014,
      213693.80887025144, 0.0, -123.76154386633067, 270531.98388907709, 0.0,
      -138.40818092168897, 330348.32615427504, 0.0, -152.39630883721321,
      391692.10230733058, 0.0, -165.75553401917989, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, 4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827,
      0.0, -39.513172105611375, 42451.303288620264, 0.0, -57.947594890272953,
      74527.760150184724, 0.0, -75.553210635790776, 114453.98417604566, 0.0,
      -92.3672822994138, 161232.77935678588, 0.0, -108.42539750515014,
      213693.80887025144, 0.0, -123.76154386633067, 270531.98388907709, 0.0,
      -138.40818092168897, 330348.32615427504, 0.0, -152.39630883721321, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 4767.0535042916235, 0.0,
      -20.210925122845889, 19013.924333112827, 0.0, -39.513172105611375,
      42451.303288620264, 0.0, -57.947594890272953, 74527.760150184724, 0.0,
      -75.553210635790776, 114453.98417604566, 0.0, -92.3672822994138,
      161232.77935678588, 0.0, -108.42539750515014, 213693.80887025144, 0.0,
      -123.76154386633067, 270531.98388907709, 0.0, -138.40818092168897, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42451.303288620264, 0.0, -57.947594890272953,
      74527.760150184724, 0.0, -75.553210635790776, 114453.98417604566, 0.0,
      -92.3672822994138, 161232.77935678588, 0.0, -108.42539750515014,
      213693.80887025144, 0.0, -123.76154386633067, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42451.303288620264, 0.0, -57.947594890272953,
      74527.760150184724, 0.0, -75.553210635790776, 114453.98417604566, 0.0,
      -92.3672822994138, 161232.77935678588, 0.0, -108.42539750515014 };

    static const real_T b_Mlim_0[60] = { 0.025, 400.0, 0.025, 400.0, 0.025,
      400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025,
      400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025,
      400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025,
      400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025,
      400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025, 400.0, 0.025,
      400.0, 0.025, 400.0, 0.025, 400.0 };

    static const real_T d_a[60] = { 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042451303288620262,
      -57.947594890272953, 0.074527760150184724, -75.553210635790776,
      0.11445398417604566, -92.3672822994138, 0.16123277935678587,
      -108.42539750515014, 0.21369380887025144, -123.76154386633067,
      0.27053198388907707, -138.40818092168897, 0.33034832615427506,
      -152.39630883721321, 0.39169210230733059, -165.75553401917989,
      0.45310303065572821, -178.51413177724191, 0.51315239668685753,
      -190.69910617020003, 0.57048198022495844, -202.33624716112328,
      0.62383979183842342, -213.45018520278953, 0.67211173545685909,
      -224.0644433689782, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042451303288620262,
      57.947594890272953, -0.074527760150184724, 75.553210635790776,
      -0.11445398417604566, 92.3672822994138, -0.16123277935678587,
      108.42539750515014, -0.21369380887025144, 123.76154386633067,
      -0.27053198388907707, 138.40818092168897, -0.33034832615427506,
      152.39630883721321, -0.39169210230733059, 165.75553401917989,
      -0.45310303065572821, 178.51413177724191, -0.51315239668685753,
      190.69910617020003, -0.57048198022495844, 202.33624716112328,
      -0.62383979183842342, 213.45018520278953, -0.67211173545685909,
      224.0644433689782 };

    static const real_T c_a[360] = { -0.98615263436656475, -0.0,
      -0.94557401352275716, -0.0, -0.88022220241129678, -0.0,
      -0.79267617186591421, -0.0, -0.68604523713504006, -0.0,
      -0.56386673298821832, -0.0, -0.42999511399120127, -0.0,
      -0.28848580453245642, -0.0, -0.14347716332049817, -0.0,
      0.00092612674460315625, -0.0, 0.14076507575537039, -0.0,
      0.27233086955467695, -0.0, 0.39225917659871545, -0.0, 0.49761200080760176,
      -0.0, 0.58594521697366808, -0.0, 0.98615263436656475, 0.0,
      0.94557401352275716, 0.0, 0.88022220241129678, 0.0, 0.79267617186591421,
      0.0, 0.68604523713504006, 0.0, 0.56386673298821832, 0.0,
      0.42999511399120127, 0.0, 0.28848580453245642, 0.0, 0.14347716332049817,
      0.0, -0.00092612674460315625, 0.0, -0.14076507575537039, 0.0,
      -0.27233086955467695, 0.0, -0.39225917659871545, 0.0, -0.49761200080760176,
      0.0, -0.58594521697366808, 0.0, -0.048980249871033235, -0.0,
      -0.095071665238666947, -0.0, -0.13709532203773392, -0.0,
      -0.17402141016535683, -0.0, -0.20499291576351483, -0.0,
      -0.22934379894404847, -0.0, -0.24661133921385017, -0.0,
      -0.25654249182745764, -0.0, -0.25909426820866366, -0.0,
      -0.25442831779444197, -0.0, -0.24290004281901698, -0.0,
      -0.22504271774214879, -0.0, -0.2015472078111829, -0.0,
      -0.17323798379556646, -0.0, -0.14104621005640228, -0.0,
      0.048980249871033235, 0.0, 0.095071665238666947, 0.0, 0.13709532203773392,
      0.0, 0.17402141016535683, 0.0, 0.20499291576351483, 0.0,
      0.22934379894404847, 0.0, 0.24661133921385017, 0.0, 0.25654249182745764,
      0.0, 0.25909426820866366, 0.0, 0.25442831779444197, 0.0,
      0.24290004281901698, 0.0, 0.22504271774214879, 0.0, 0.2015472078111829,
      0.0, 0.17323798379556646, 0.0, 0.14104621005640228, 0.0,
      1.0286617582746761E-5, -0.9550402500352021, 3.9813675118921535E-5,
      -0.91210187918730135, 8.6270681697265232E-5, -0.871094006756618,
      0.00014699350177716379, -0.83192983801700648, 0.00021904705860528929,
      -0.79452648051150709, 0.00029931298310503828, -0.75880476860729884,
      0.00038457963459986606, -0.72468909593861841, 0.00047163193544995738,
      -0.69210725538300266, 0.000557338547364101, -0.66099028623216038,
      0.000638734068236024, -0.63127232823400226, 0.00071309413862917254,
      -0.60289048219690566, 0.00077800160884330222, -0.57578467686117629,
      0.00083140222200842593, -0.54989754175593586, 0.00087164860613602292,
      -0.52517428577233194, 0.00089753172818082035, -0.50156258119606656,
      -1.0286617582746761E-5, 0.9550402500352021, -3.9813675118921535E-5,
      0.91210187918730135, -8.6270681697265232E-5, 0.871094006756618,
      -0.00014699350177716379, 0.83192983801700648, -0.00021904705860528929,
      0.79452648051150709, -0.00029931298310503828, 0.75880476860729884,
      -0.00038457963459986606, 0.72468909593861841, -0.00047163193544995738,
      0.69210725538300266, -0.000557338547364101, 0.66099028623216038,
      -0.000638734068236024, 0.63127232823400226, -0.00071309413862917254,
      0.60289048219690566, -0.00077800160884330222, 0.57578467686117629,
      -0.00083140222200842593, 0.54989754175593586, -0.00087164860613602292,
      0.52517428577233194, -0.00089753172818082035, 0.50156258119606656, -1.0,
      -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
      -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
      -0.0, -1.0, -0.0, -1.0, -0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
      0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
      1.0, 0.0, 1.0, 0.0, 1.0, 0.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
      -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
      -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, 0.0, 1.0,
      0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
      1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

    static const real_T f_a[6] = { -0.0047670535042916235, -0.19064676934585889,
      20.210925122845889, 0.0, 0.0, 0.0 };

    static const real_T g_a[18] = { 4.3356332513175807E-6, 1.7608920124147914E-6,
      -0.00028423874186795652, 0.048765464764217309, 7.27775687997265E-5,
      -4.1234430917274792E-6, 2.229742650218423E-6, 0.00012733699841676216,
      -0.0085269685189099768, 4.1542151007225285E-6, -2.0976474542262375E-5,
      0.048762439408270304, -0.00070060472295892186, -0.0092598160135536275,
      0.95027603775113778, 7.88262037983429E-6, 0.0024678189085428665,
      0.00045988554339899452 };

    static const real_T e_a[36] = { 0.98615263436656475, -0.54967062879931416,
      0.0, 0.0, 0.0, 0.0, 0.048980249871033235, 0.9548677869051535, 0.0, 0.0,
      0.0, 0.0, -1.0286617582746761E-5, -0.00040517078444852746,
      0.9550402500352021, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

    static const real_T b_a_0[18] = { 0.029677008248826228, 0.09038679047543112,
      0.00041418002824874633, 0.039840733342102037, -3.8152249701846131E-5,
      -0.027183085865885241, 0.090385679623878459, 0.2753627737852421,
      -0.0071759677024493713, -0.027181975014332966, 5.5648579823810472E-5,
      -0.034026404670016018, 0.00061900823323476624, -0.0067953144688093613,
      0.99502819500418316, -0.00024298045468786251, 0.0024685138110849486,
      -0.00032500465381618532 };

    static const real_T b_Kx_0[60] = { -1.8059161690498497E+7,
      -4.7194251596073993E+6, 10423.72900036076, -6.8009457303272784E+6,
      1983.4032638838307, 0.0, -1.4710571358533828E+7, -3.8575859234314552E+6,
      8625.95314201922, -5.4410894297303669E+6, 1759.3388205148526, 0.0,
      -1.1846381200122859E+7, -3.1162218217362557E+6, 7062.1549610194033,
      -4.299033505664587E+6, 1545.8886353120631, 0.0, -9.4106079511246011E+6,
      -2.4825110115641761E+6, 5708.4964158605217, -3.3471880469038631E+6,
      1343.5523881509398, 0.0, -7.3541775399427032E+6, -1.9450189205281455E+6,
      4544.1386802373745, -2.5611119936512462E+6, 1152.8532819807397, 0.0,
      -5.6339290779927922E+6, -1.4935261341365154E+6, 3550.7712555508238,
      -1.919115910411214E+6, 974.33915020349775, 0.0, -4.2117165180870583E+6,
      -1.1188633421831022E+6, 2712.1863822577716, -1.4019073943174747E+6,
      808.58361618431786, 0.0, -3.0535845821178863E+6, -812750.82583889214,
      2013.8854601442833, -992272.9256488462, 656.18730734710459, 0.0,
      -2.1289964732069541E+6, -567639.46640413674, 1442.7046753017289,
      -674790.43882467411, 517.7791264254156, 0.0, -1.4100910090675389E+6,
      -376549.68750527909, 986.447009784409, -435567.24325323629,
      394.017582559085, 0.0 };

    static const real_T b_Linv_0[121] = { 0.00040633110476561048,
      -0.0091158447247947274, 0.036795438781306818, -0.0067704556952588937,
      -0.0037333803840953685, -0.0019993994650960262, -0.0010377996258356507,
      -0.0005061761388585901, -0.00021530643583287745, -5.9701166925133644E-5,
      0.0, 0.0, 0.011013876368568484, -0.085162543729240148,
      0.052560446284275926, 0.0026809331768223, 0.0013512270581254595,
      0.00067424552952229111, 0.00029808112119808516, 9.1474245832455641E-5,
      -1.8523258736832512E-5, 0.0, 0.0, 0.0, 0.049703422707120394,
      -0.095703255792165237, 0.0454496178784557, -0.00061246500414277128,
      -0.0003874058342292657, -0.00020166359987728474, -0.00010022002031029187,
      -4.5734153273352004E-5, 0.0, 0.0, 0.0, 0.0, 0.051334318032839346,
      -0.095199796186613325, 0.04473867901524075, -0.000499890783067535,
      -0.00032238538705864583, -0.00016571625021791469, -8.134047729661505E-5,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.052433791298519862, -0.095009500356724091,
      0.04388048122866077, -0.00042901902160691715, -0.00027908641401993504,
      -0.00014073953418533271, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.053473204062494895, -0.094900880391266526, 0.042856991926834863,
      -0.00037003843747839183, -0.00024109833171863677, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.05463769851401494, -0.094784436093136581, 0.041631595143178435,
      -0.00031183101104205468, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.056034607614111068, -0.094612232967326224, 0.040141464567655522, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.057774334242598785,
      -0.094334764634969079, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.060017546149158676, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.003162277660168379 };

    static const real_T b_Hinv_0[121] = { 0.0015023260061945813,
      -0.0036034319123678937, 0.0023088861863535984, -8.08676589721856E-5,
      -5.1046840098592816E-5, -3.0025318625769792E-5, -1.767029688192556E-5,
      -1.0389250934954956E-5, -6.8072904580758263E-6, -3.583117541087834E-6, 0.0,
      -0.0036034319123678937, 0.010146130227997964, -0.00914238557509299,
      0.0025029356889100904, 4.1627496584089333E-5, 2.1013423006876543E-5,
      1.2399767878714969E-5, 7.3047252720361453E-6, 7.03225090652567E-6,
      -1.1117205360706519E-6, 0.0, 0.0023088861863535984, -0.00914238557509299,
      0.013695789163855398, -0.0092667776015026779, 0.0024244071421990585,
      -4.5798949946936237E-6, -6.2104505618535151E-6, -3.6539366727392322E-6,
      -1.4758243663855791E-6, -2.7448516546761004E-6, 0.0, -8.08676589721856E-5,
      0.0025029356889100904, -0.0092667776015026779, 0.013700150703179771,
      -0.0092640252264529245, 0.0024260250523861866, -3.6294321326013362E-6,
      -5.65108007958373E-6, -1.9009112484477097E-6, -4.8818558499441877E-6, 0.0,
      -5.1046840098592816E-5, 4.1627496584089333E-5, 0.0024244071421990585,
      -0.0092640252264529245, 0.013701886014993817, -0.0092630079610211431,
      0.0024266179044104986, -3.2844147382325632E-6, -2.8474009339474885E-6,
      -8.4468414879793018E-6, 0.0, -3.0025318625769792E-5, 2.1013423006876543E-5,
      -4.5798949946936237E-6, 0.0024260250523861866, -0.0092630079610211431,
      0.013702477465614253, -0.0092626716124457366, 0.0024268068488548841,
      1.3652300070756978E-6, -1.4470130250408449E-5, 0.0, -1.767029688192556E-5,
      1.2399767878714969E-5, -6.2104505618535151E-6, -3.6294321326013362E-6,
      0.0024266179044104986, -0.0092626716124457366, 0.013702654377147247,
      -0.00926258421637234, 0.0024346541978870796, -1.8715332095955326E-5, 0.0,
      -1.0389250934954956E-5, 7.3047252720361453E-6, -3.6539366727392322E-6,
      -5.65108007958373E-6, -3.2844147382325632E-6, 0.0024268068488548841,
      -0.00926258421637234, 0.013702689055167349, -0.0092528943829856634,
      0.0024091922021840829, 0.0, -6.8072904580758263E-6, 7.03225090652567E-6,
      -1.4758243663855791E-6, -1.9009112484477097E-6, -2.8474009339474885E-6,
      1.3652300070756978E-6, 0.0024346541978870796, -0.0092528943829856634,
      0.012236921515910536, -0.0056617410899492786, 0.0, -3.583117541087834E-6,
      -1.1117205360706519E-6, -2.7448516546761004E-6, -4.8818558499441877E-6,
      -8.4468414879793018E-6, -1.4470130250408449E-5, -1.8715332095955326E-5,
      0.0024091922021840829, -0.0056617410899492786, 0.0036021058457663914, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.9999999999999974E-6 };

    static const real_T b_Ac_0[660] = { 0.0047670535042916235,
      -20.210925122845889, 0.019013924333112827, -39.513172105611375,
      0.042707990096855108, -57.947594890272953, 0.076049818436936173,
      -75.553210635790776, 0.11945936650493763, -92.3672822994138,
      0.17356909037710291, -108.42539750515014, 0.23922319557143779,
      -123.76154386633067, 0.317482486824172, -138.40818092168897,
      0.40963446866862863, -152.39630883721321, 0.5172085160937393,
      -165.75553401917989, 0.6419960832400321, -178.51413177724191,
      0.78607605325261687, -190.69910617020003, 0.95184545876072357,
      -202.33624716112328, 1.14205592406578, -213.45018520278953,
      1.3598563005969111, -224.0644433689782, -0.0047670535042916235,
      20.210925122845889, -0.019013924333112827, 39.513172105611375,
      -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
      75.553210635790776, -0.11945936650493763, 92.3672822994138,
      -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
      123.76154386633067, -0.317482486824172, 138.40818092168897,
      -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
      165.75553401917989, -0.6419960832400321, 178.51413177724191,
      -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
      202.33624716112328, -1.14205592406578, 213.45018520278953,
      -1.3598563005969111, 224.0644433689782, -0.0, -0.0, 0.0047670535042916235,
      -20.210925122845889, 0.019013924333112827, -39.513172105611375,
      0.042707990096855108, -57.947594890272953, 0.076049818436936173,
      -75.553210635790776, 0.11945936650493763, -92.3672822994138,
      0.17356909037710291, -108.42539750515014, 0.23922319557143779,
      -123.76154386633067, 0.317482486824172, -138.40818092168897,
      0.40963446866862863, -152.39630883721321, 0.5172085160937393,
      -165.75553401917989, 0.6419960832400321, -178.51413177724191,
      0.78607605325261687, -190.69910617020003, 0.95184545876072357,
      -202.33624716112328, 1.14205592406578, -213.45018520278953, 0.0, 0.0,
      -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
      39.513172105611375, -0.042707990096855108, 57.947594890272953,
      -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
      92.3672822994138, -0.17356909037710291, 108.42539750515014,
      -0.23922319557143779, 123.76154386633067, -0.317482486824172,
      138.40818092168897, -0.40963446866862863, 152.39630883721321,
      -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
      178.51413177724191, -0.78607605325261687, 190.69910617020003,
      -0.95184545876072357, 202.33624716112328, -1.14205592406578,
      213.45018520278953, -0.0, -0.0, -0.0, -0.0, 0.0047670535042916235,
      -20.210925122845889, 0.019013924333112827, -39.513172105611375,
      0.042707990096855108, -57.947594890272953, 0.076049818436936173,
      -75.553210635790776, 0.11945936650493763, -92.3672822994138,
      0.17356909037710291, -108.42539750515014, 0.23922319557143779,
      -123.76154386633067, 0.317482486824172, -138.40818092168897,
      0.40963446866862863, -152.39630883721321, 0.5172085160937393,
      -165.75553401917989, 0.6419960832400321, -178.51413177724191,
      0.78607605325261687, -190.69910617020003, 0.95184545876072357,
      -202.33624716112328, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
      20.210925122845889, -0.019013924333112827, 39.513172105611375,
      -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
      75.553210635790776, -0.11945936650493763, 92.3672822994138,
      -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
      123.76154386633067, -0.317482486824172, 138.40818092168897,
      -0.40963446866862863, 152.39630883721321, -0.5172085160937393,
      165.75553401917989, -0.6419960832400321, 178.51413177724191,
      -0.78607605325261687, 190.69910617020003, -0.95184545876072357,
      202.33624716112328, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042707990096855108, -57.947594890272953,
      0.076049818436936173, -75.553210635790776, 0.11945936650493763,
      -92.3672822994138, 0.17356909037710291, -108.42539750515014,
      0.23922319557143779, -123.76154386633067, 0.317482486824172,
      -138.40818092168897, 0.40963446866862863, -152.39630883721321,
      0.5172085160937393, -165.75553401917989, 0.6419960832400321,
      -178.51413177724191, 0.78607605325261687, -190.69910617020003, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
      57.947594890272953, -0.076049818436936173, 75.553210635790776,
      -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
      108.42539750515014, -0.23922319557143779, 123.76154386633067,
      -0.317482486824172, 138.40818092168897, -0.40963446866862863,
      152.39630883721321, -0.5172085160937393, 165.75553401917989,
      -0.6419960832400321, 178.51413177724191, -0.78607605325261687,
      190.69910617020003, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042707990096855108, -57.947594890272953,
      0.076049818436936173, -75.553210635790776, 0.11945936650493763,
      -92.3672822994138, 0.17356909037710291, -108.42539750515014,
      0.23922319557143779, -123.76154386633067, 0.317482486824172,
      -138.40818092168897, 0.40963446866862863, -152.39630883721321,
      0.5172085160937393, -165.75553401917989, 0.6419960832400321,
      -178.51413177724191, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
      39.513172105611375, -0.042707990096855108, 57.947594890272953,
      -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
      92.3672822994138, -0.17356909037710291, 108.42539750515014,
      -0.23922319557143779, 123.76154386633067, -0.317482486824172,
      138.40818092168897, -0.40963446866862863, 152.39630883721321,
      -0.5172085160937393, 165.75553401917989, -0.6419960832400321,
      178.51413177724191, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, 0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042707990096855108, -57.947594890272953,
      0.076049818436936173, -75.553210635790776, 0.11945936650493763,
      -92.3672822994138, 0.17356909037710291, -108.42539750515014,
      0.23922319557143779, -123.76154386633067, 0.317482486824172,
      -138.40818092168897, 0.40963446866862863, -152.39630883721321,
      0.5172085160937393, -165.75553401917989, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
      57.947594890272953, -0.076049818436936173, 75.553210635790776,
      -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
      108.42539750515014, -0.23922319557143779, 123.76154386633067,
      -0.317482486824172, 138.40818092168897, -0.40963446866862863,
      152.39630883721321, -0.5172085160937393, 165.75553401917989, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042707990096855108, -57.947594890272953,
      0.076049818436936173, -75.553210635790776, 0.11945936650493763,
      -92.3672822994138, 0.17356909037710291, -108.42539750515014,
      0.23922319557143779, -123.76154386633067, 0.317482486824172,
      -138.40818092168897, 0.40963446866862863, -152.39630883721321, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
      20.210925122845889, -0.019013924333112827, 39.513172105611375,
      -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
      75.553210635790776, -0.11945936650493763, 92.3672822994138,
      -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
      123.76154386633067, -0.317482486824172, 138.40818092168897,
      -0.40963446866862863, 152.39630883721321, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042707990096855108, -57.947594890272953,
      0.076049818436936173, -75.553210635790776, 0.11945936650493763,
      -92.3672822994138, 0.17356909037710291, -108.42539750515014,
      0.23922319557143779, -123.76154386633067, 0.317482486824172,
      -138.40818092168897, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
      57.947594890272953, -0.076049818436936173, 75.553210635790776,
      -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
      108.42539750515014, -0.23922319557143779, 123.76154386633067,
      -0.317482486824172, 138.40818092168897, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042707990096855108, -57.947594890272953,
      0.076049818436936173, -75.553210635790776, 0.11945936650493763,
      -92.3672822994138, 0.17356909037710291, -108.42539750515014,
      0.23922319557143779, -123.76154386633067, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0047670535042916235,
      20.210925122845889, -0.019013924333112827, 39.513172105611375,
      -0.042707990096855108, 57.947594890272953, -0.076049818436936173,
      75.553210635790776, -0.11945936650493763, 92.3672822994138,
      -0.17356909037710291, 108.42539750515014, -0.23922319557143779,
      123.76154386633067, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      0.0047670535042916235, -20.210925122845889, 0.019013924333112827,
      -39.513172105611375, 0.042707990096855108, -57.947594890272953,
      0.076049818436936173, -75.553210635790776, 0.11945936650493763,
      -92.3672822994138, 0.17356909037710291, -108.42539750515014, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -0.0047670535042916235, 20.210925122845889, -0.019013924333112827,
      39.513172105611375, -0.042707990096855108, 57.947594890272953,
      -0.076049818436936173, 75.553210635790776, -0.11945936650493763,
      92.3672822994138, -0.17356909037710291, 108.42539750515014, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

    static const real_T b_Ku1_0[10] = { 6.05675298551293E+6,
      5.0129870633785333E+6, 4.1055089406194724E+6, 3.3200540946086003E+6,
      2.6442364095470486E+6, 2.0672673921485455E+6, 1.5796969154202887E+6,
      1.1731682540334375E+6, 840180.07320530259, 573847.65637752973 };

    static const real_T b_Kr_1[450] = { 4767.0535042916235, 0.0,
      -20.210925122845889, 19013.924333112827, 0.0, -39.513172105611375,
      42707.990096855108, 0.0, -57.947594890272953, 76049.81843693617, 0.0,
      -75.553210635790776, 119459.36650493763, 0.0, -92.3672822994138,
      173569.09037710293, 0.0, -108.42539750515014, 239223.1955714378, 0.0,
      -123.76154386633067, 317482.486824172, 0.0, -138.40818092168897,
      409634.4686686286, 0.0, -152.39630883721321, 517208.51609373931, 0.0,
      -165.75553401917989, 641996.08324003208, 0.0, -178.51413177724191,
      786076.0532526169, 0.0, -190.69910617020003, 951845.45876072359, 0.0,
      -202.33624716112328, 1.14205592406578E+6, 0.0, -213.45018520278953,
      1.359856300596911E+6, 0.0, -224.0644433689782, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42707.990096855108, 0.0, -57.947594890272953,
      76049.81843693617, 0.0, -75.553210635790776, 119459.36650493763, 0.0,
      -92.3672822994138, 173569.09037710293, 0.0, -108.42539750515014,
      239223.1955714378, 0.0, -123.76154386633067, 317482.486824172, 0.0,
      -138.40818092168897, 409634.4686686286, 0.0, -152.39630883721321,
      517208.51609373931, 0.0, -165.75553401917989, 641996.08324003208, 0.0,
      -178.51413177724191, 786076.0532526169, 0.0, -190.69910617020003,
      951845.45876072359, 0.0, -202.33624716112328, 1.14205592406578E+6, 0.0,
      -213.45018520278953, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42707.990096855108, 0.0, -57.947594890272953,
      76049.81843693617, 0.0, -75.553210635790776, 119459.36650493763, 0.0,
      -92.3672822994138, 173569.09037710293, 0.0, -108.42539750515014,
      239223.1955714378, 0.0, -123.76154386633067, 317482.486824172, 0.0,
      -138.40818092168897, 409634.4686686286, 0.0, -152.39630883721321,
      517208.51609373931, 0.0, -165.75553401917989, 641996.08324003208, 0.0,
      -178.51413177724191, 786076.0532526169, 0.0, -190.69910617020003,
      951845.45876072359, 0.0, -202.33624716112328, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, 4767.0535042916235, 0.0, -20.210925122845889,
      19013.924333112827, 0.0, -39.513172105611375, 42707.990096855108, 0.0,
      -57.947594890272953, 76049.81843693617, 0.0, -75.553210635790776,
      119459.36650493763, 0.0, -92.3672822994138, 173569.09037710293, 0.0,
      -108.42539750515014, 239223.1955714378, 0.0, -123.76154386633067,
      317482.486824172, 0.0, -138.40818092168897, 409634.4686686286, 0.0,
      -152.39630883721321, 517208.51609373931, 0.0, -165.75553401917989,
      641996.08324003208, 0.0, -178.51413177724191, 786076.0532526169, 0.0,
      -190.69910617020003, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, 4767.0535042916235, 0.0, -20.210925122845889,
      19013.924333112827, 0.0, -39.513172105611375, 42707.990096855108, 0.0,
      -57.947594890272953, 76049.81843693617, 0.0, -75.553210635790776,
      119459.36650493763, 0.0, -92.3672822994138, 173569.09037710293, 0.0,
      -108.42539750515014, 239223.1955714378, 0.0, -123.76154386633067,
      317482.486824172, 0.0, -138.40818092168897, 409634.4686686286, 0.0,
      -152.39630883721321, 517208.51609373931, 0.0, -165.75553401917989,
      641996.08324003208, 0.0, -178.51413177724191, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42707.990096855108, 0.0, -57.947594890272953,
      76049.81843693617, 0.0, -75.553210635790776, 119459.36650493763, 0.0,
      -92.3672822994138, 173569.09037710293, 0.0, -108.42539750515014,
      239223.1955714378, 0.0, -123.76154386633067, 317482.486824172, 0.0,
      -138.40818092168897, 409634.4686686286, 0.0, -152.39630883721321,
      517208.51609373931, 0.0, -165.75553401917989, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, 4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827,
      0.0, -39.513172105611375, 42707.990096855108, 0.0, -57.947594890272953,
      76049.81843693617, 0.0, -75.553210635790776, 119459.36650493763, 0.0,
      -92.3672822994138, 173569.09037710293, 0.0, -108.42539750515014,
      239223.1955714378, 0.0, -123.76154386633067, 317482.486824172, 0.0,
      -138.40818092168897, 409634.4686686286, 0.0, -152.39630883721321, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 4767.0535042916235, 0.0,
      -20.210925122845889, 19013.924333112827, 0.0, -39.513172105611375,
      42707.990096855108, 0.0, -57.947594890272953, 76049.81843693617, 0.0,
      -75.553210635790776, 119459.36650493763, 0.0, -92.3672822994138,
      173569.09037710293, 0.0, -108.42539750515014, 239223.1955714378, 0.0,
      -123.76154386633067, 317482.486824172, 0.0, -138.40818092168897, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42707.990096855108, 0.0, -57.947594890272953,
      76049.81843693617, 0.0, -75.553210635790776, 119459.36650493763, 0.0,
      -92.3672822994138, 173569.09037710293, 0.0, -108.42539750515014,
      239223.1955714378, 0.0, -123.76154386633067, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      4767.0535042916235, 0.0, -20.210925122845889, 19013.924333112827, 0.0,
      -39.513172105611375, 42707.990096855108, 0.0, -57.947594890272953,
      76049.81843693617, 0.0, -75.553210635790776, 119459.36650493763, 0.0,
      -92.3672822994138, 173569.09037710293, 0.0, -108.42539750515014 };

    static const real_T d_a_0[60] = { 0.0047670535042916235, -20.210925122845889,
      0.019013924333112827, -39.513172105611375, 0.042707990096855108,
      -57.947594890272953, 0.076049818436936173, -75.553210635790776,
      0.11945936650493763, -92.3672822994138, 0.17356909037710291,
      -108.42539750515014, 0.23922319557143779, -123.76154386633067,
      0.317482486824172, -138.40818092168897, 0.40963446866862863,
      -152.39630883721321, 0.5172085160937393, -165.75553401917989,
      0.6419960832400321, -178.51413177724191, 0.78607605325261687,
      -190.69910617020003, 0.95184545876072357, -202.33624716112328,
      1.14205592406578, -213.45018520278953, 1.3598563005969111,
      -224.0644433689782, -0.0047670535042916235, 20.210925122845889,
      -0.019013924333112827, 39.513172105611375, -0.042707990096855108,
      57.947594890272953, -0.076049818436936173, 75.553210635790776,
      -0.11945936650493763, 92.3672822994138, -0.17356909037710291,
      108.42539750515014, -0.23922319557143779, 123.76154386633067,
      -0.317482486824172, 138.40818092168897, -0.40963446866862863,
      152.39630883721321, -0.5172085160937393, 165.75553401917989,
      -0.6419960832400321, 178.51413177724191, -0.78607605325261687,
      190.69910617020003, -0.95184545876072357, 202.33624716112328,
      -1.14205592406578, 213.45018520278953, -1.3598563005969111,
      224.0644433689782 };

    static const real_T c_a_0[360] = { -0.98615263436656475, -0.0,
      -0.99942002301347388, -0.0, -1.0378387905461661, -0.0, -1.1002744255838741,
      -0.0, -1.1863207617797207, -0.0, -1.2962271849089555, -0.0,
      -1.43084928730111, -0.0, -1.5916196723905174, -0.0, -1.7805364232478644,
      -0.0, -2.0001674254954458, -0.0, -2.2536693062662012, -0.0,
      -2.5448202408426392, -0.0, -2.8780663071232788, -0.0, -3.2585814516218368,
      -0.0, -3.6923414832284154, -0.0, 0.98615263436656475, 0.0,
      0.99942002301347388, 0.0, 1.0378387905461661, 0.0, 1.1002744255838741, 0.0,
      1.1863207617797207, 0.0, 1.2962271849089555, 0.0, 1.43084928730111, 0.0,
      1.5916196723905174, 0.0, 1.7805364232478644, 0.0, 2.0001674254954458, 0.0,
      2.2536693062662012, 0.0, 2.5448202408426392, 0.0, 2.8780663071232788, 0.0,
      3.2585814516218368, 0.0, 3.6923414832284154, 0.0, -0.048980249871033235,
      -0.0, -0.095071665238666947, -0.0, -0.13973271303714727, -0.0,
      -0.18425986974283584, -0.0, -0.22983553032857923, -0.0,
      -0.27756883153618794, -0.0, -0.32853106728927578, -0.0,
      -0.38378708877189704, -0.0, -0.44442385735173262, -0.0,
      -0.51157714403245669, -0.0, -0.58645723563819907, -0.0, -0.670374408455958,
      -0.0, -0.76476485907352743, -0.0, -0.87121773535467084, -0.0,
      -0.991503884596186, -0.0, 0.048980249871033235, 0.0, 0.095071665238666947,
      0.0, 0.13973271303714727, 0.0, 0.18425986974283584, 0.0,
      0.22983553032857923, 0.0, 0.27756883153618794, 0.0, 0.32853106728927578,
      0.0, 0.38378708877189704, 0.0, 0.44442385735173262, 0.0,
      0.51157714403245669, 0.0, 0.58645723563819907, 0.0, 0.670374408455958, 0.0,
      0.76476485907352743, 0.0, 0.87121773535467084, 0.0, 0.991503884596186, 0.0,
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
      -1.0286617582746761E-5, 0.9550402500352021, -3.9813675118921535E-5,
      0.91210187918730135, -8.6824575005253177E-5, 0.871094006756618,
      -0.0001502124275274879, 0.83192983801700648, -0.00022943373256239266,
      0.79452648051150709, -0.00032444431943717171, 0.75880476860729884,
      -0.00043565395852127471, 0.72468909593861841, -0.00056389685516130389,
      0.69210725538300266, -0.00071041589227329989, 0.66099028623216038,
      -0.000876859031574618, 0.63127232823400226, -0.0010652867389217549,
      0.60289048219690566, -0.0012781896860195963, 0.57578467686117629,
      -0.0015185163149112715, 0.54989754175593586, -0.0017897101464240484,
      0.52517428577233194, -0.0020957569802455486, 0.50156258119606656, -1.0,
      -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
      -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
      -0.0, -1.0, -0.0, -1.0, -0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
      0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
      1.0, 0.0, 1.0, 0.0, 1.0, 0.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
      -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0,
      -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, 0.0, 1.0,
      0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
      1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
      -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

    static const real_T g_a_0[18] = { 0.033693223186713923, 0.10261984655810226,
      0.00039555859774347208, 0.039840733342101975, -3.8152249700735976E-5,
      -0.027183085865884984, 0.10262148735171715, 0.31262030324615114,
      -0.0068533379887818144, -0.027181975014332747, 5.56485798268152E-5,
      -0.034026404670016143, 0.000267364924738465, -0.0065515325976807171,
      0.95029197614887151, -0.0002429804546878517, 0.0024685138110849478,
      -0.00032500465381618337 };

    static const real_T e_a_0[36] = { 0.98615263436656475, 0.54967062879931416,
      0.0, 0.0, 0.0, 0.0, 0.048980249871033235, 0.9548677869051535, 0.0, 0.0,
      0.0, 0.0, -1.0286617582746761E-5, -0.00040517078444852746,
      0.9550402500352021, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

    /* Delay: '<S1>/Delay1' */
    reaction_pendulum_B.Delay1[0] = reaction_pendulum_DW.Delay1_DSTATE[0];
    reaction_pendulum_B.Delay1[1] = reaction_pendulum_DW.Delay1_DSTATE[1];

    /* Gain: '<S7>/Minimum sampling to time constant ratio' */
    rtb_Integrator = reaction_pendulum_P.FilteredDerivative1_minRatio *
      reaction_pendulum_B.Probe[0];

    /* MinMax: '<S7>/MinMax' incorporates:
     *  Constant: '<S7>/Time constant'
     */
    if ((!(rtb_Integrator >= reaction_pendulum_P.h)) && (!rtIsNaN
         (reaction_pendulum_P.h))) {
      rtb_Integrator = reaction_pendulum_P.h;
    }

    /* End of MinMax: '<S7>/MinMax' */

    /* Constant: '<S10>/Constant' */
    reaction_pendulum_B.Constant = reaction_pendulum_P.FilteredDerivative1_x0;

    /* DiscreteIntegrator: '<S12>/Integrator' incorporates:
     *  Constant: '<S6>/Constant'
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

    /* Saturate: '<S12>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S12>/Integrator'
     */
    if (reaction_pendulum_DW.Integrator_DSTATE >
        reaction_pendulum_P.Saturation_UpperSat) {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation = reaction_pendulum_P.Saturation_UpperSat;
    } else if (reaction_pendulum_DW.Integrator_DSTATE <
               reaction_pendulum_P.Saturation_LowerSat) {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation = reaction_pendulum_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation = reaction_pendulum_DW.Integrator_DSTATE;
    }

    /* End of Saturate: '<S12>/Saturation' */

    /* Product: '<S6>/1//T' incorporates:
     *  Fcn: '<S7>/Avoid Divide by Zero'
     *  Sum: '<S6>/Sum1'
     */
    rtb_uT = 1.0 / ((real_T)(rtb_Integrator == 0.0) * 2.2204460492503131e-16 +
                    rtb_Integrator) * (reaction_pendulum_B.Delay1[0] -
      rtb_Saturation);

    /* Gain: '<S6>/Gain' */
    rtb_last_mv = reaction_pendulum_P.FilteredDerivative1_K * rtb_uT;

    /* Saturate: '<S6>/[A,B]' */
    if (rtb_last_mv > reaction_pendulum_P.FilteredDerivative1_B) {
      /* Saturate: '<S6>/[A,B]' */
      reaction_pendulum_B.AB = reaction_pendulum_P.FilteredDerivative1_B;
    } else if (rtb_last_mv < reaction_pendulum_P.FilteredDerivative1_A) {
      /* Saturate: '<S6>/[A,B]' */
      reaction_pendulum_B.AB = reaction_pendulum_P.FilteredDerivative1_A;
    } else {
      /* Saturate: '<S6>/[A,B]' */
      reaction_pendulum_B.AB = rtb_last_mv;
    }

    /* End of Saturate: '<S6>/[A,B]' */

    /* UnitDelay: '<S21>/last_mv' */
    rtb_last_mv = reaction_pendulum_DW.last_mv_DSTATE;

    /* MATLAB Function: '<S41>/optimizer' incorporates:
     *  Constant: '<S3>/Ref'
     *  Memory: '<S21>/last_x'
     */
    /* MATLAB Function 'MPC Controller/MPC/optimizer/optimizer': '<S42>:1' */
    /* '<S42>:1:128' */
    /* '<S42>:1:153' */
    /* '<S42>:1:155' */
    /* '<S42>:1:157' */
    /* '<S42>:1:218' */
    /* '<S42>:1:219' */
    /* '<S42>:1:223' */
    /* '<S42>:1:216' */
    /* '<S42>:1:242' */
    /* '<S42>:1:24' */
    /* '<S42>:1:253' */
    /* '<S42>:1:26' */
    /* '<S42>:1:253' */
    /* '<S42>:1:28' */
    /* '<S42>:1:253' */
    /* '<S42>:1:30' */
    /* '<S42>:1:253' */
    /* '<S42>:1:128' */
    for (i = 0; i < 15; i++) {
      rseq[i * reaction_pendulum_ny] = reaction_pendulum_P.Ref_Value[0];
      rseq[i * reaction_pendulum_ny + 1] = reaction_pendulum_P.Ref_Value[1];
      rseq[i * reaction_pendulum_ny + 2] = reaction_pendulum_P.Ref_Value[2];
    }

    /* '<S42>:1:133' */
    /* '<S42>:1:143' */
    /* '<S42>:1:150' */
    /* '<S42>:1:153' */
    for (i = 0; i < 6; i++) {
      xk[i] = reaction_pendulum_DW.last_x_PreviousInput[i];
    }

    /* SignalConversion generated from: '<S42>/ SFunction ' incorporates:
     *  MATLAB Function: '<S41>/optimizer'
     */
    /* '<S42>:1:155' */
    /* '<S42>:1:156' */
    tmp[0] = reaction_pendulum_B.Delay1[0];
    tmp[1] = reaction_pendulum_B.AB;
    tmp[2] = reaction_pendulum_B.Delay1[1];

    /* MATLAB Function: '<S41>/optimizer' incorporates:
     *  Memory: '<S21>/Memory'
     */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Integrator = 0.0;
      for (i = 0; i < 6; i++) {
        rtb_Integrator += (real_T)a[3 * i + i_0] * xk[i];
      }

      y_innov[i_0] = tmp[i_0] - rtb_Integrator;
    }

    /* '<S42>:1:157' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_xest_i[i_0] = ((b_a[i_0 + 6] * y_innov[1] + b_a[i_0] * y_innov[0]) +
                         b_a[i_0 + 12] * y_innov[2]) + xk[i_0];
    }

    /* '<S42>:1:216' */
    memset(&f[0], 0, 11U * sizeof(real_T));
    for (i = 0; i < 10; i++) {
      rtb_Integrator = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        rtb_Integrator += b_Kx[6 * i + i_0] * rtb_xest_i[i_0];
      }

      b_Kr = 0.0;
      for (i_0 = 0; i_0 < 45; i_0++) {
        b_Kr += b_Kr_0[45 * i + i_0] * rseq[i_0];
      }

      f[i] = (rtb_Integrator + b_Kr) + b_Ku1[i] * rtb_last_mv;
    }

    for (i = 0; i < 60; i++) {
      iAnew[i] = reaction_pendulum_DW.Memory_PreviousInput_h[i];
      b_Kr = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        b_Kr += c_a[60 * i_0 + i] * rtb_xest_i[i_0];
      }

      b_Mlim[i] = -((b_Mlim_0[i] + b_Kr) + d_a[i] * rtb_last_mv);
    }

    reaction_pendulum_qpkwik(b_Linv, b_Hinv, f, b_Ac, b_Mlim, iAnew, 284, 1.0E-6,
      zopt, a__1, &rtb_Integrator);
    for (i = 0; i < 60; i++) {
      reaction_pendulum_B.iAout_m[i] = (iAnew[i] != 0);
    }

    b_Kr = rt_roundd_snf(rtb_Integrator);
    if (b_Kr < 2.147483648E+9) {
      if (b_Kr >= -2.147483648E+9) {
        i_0 = (int32_T)b_Kr;
      } else {
        i_0 = MIN_int32_T;
      }

      if (b_Kr >= -2.147483648E+9) {
        i = (int32_T)b_Kr;
      } else {
        i = MIN_int32_T;
      }
    } else {
      i_0 = MAX_int32_T;
      i = MAX_int32_T;
    }

    if ((i_0 < 0) || (i == 0)) {
      memset(&zopt[0], 0, 11U * sizeof(real_T));
    }

    rtb_Integrator = rtb_last_mv + zopt[0];

    /* '<S42>:1:216' */
    reaction_pendulum_B.u_f = rtb_Integrator;

    /* '<S42>:1:216' */
    /* '<S42>:1:234' */
    /* '<S42>:1:235' */
    /* '<S42>:1:242' */
    /* '<S42>:1:244' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      b_Kr = 0.0;
      for (i = 0; i < 6; i++) {
        b_Kr += e_a[6 * i + i_0] * xk[i];
      }

      reaction_pendulum_B.xk1_a[i_0] = ((g_a[i_0 + 6] * y_innov[1] + g_a[i_0] *
        y_innov[0]) + g_a[i_0 + 12] * y_innov[2]) + (f_a[i_0] * rtb_Integrator +
        b_Kr);
    }

    /* UnitDelay: '<S43>/last_mv' */
    /* '<S42>:1:247' */
    rtb_last_mv = reaction_pendulum_DW.last_mv_DSTATE_d;

    /* MATLAB Function: '<S63>/optimizer' incorporates:
     *  Constant: '<S3>/Ref1'
     *  Memory: '<S43>/last_x'
     */
    /* MATLAB Function 'MPC Controller/MPC/optimizer/optimizer': '<S64>:1' */
    /* '<S64>:1:128' */
    /* '<S64>:1:153' */
    /* '<S64>:1:155' */
    /* '<S64>:1:157' */
    /* '<S64>:1:218' */
    /* '<S64>:1:219' */
    /* '<S64>:1:223' */
    /* '<S64>:1:216' */
    /* '<S64>:1:242' */
    /* '<S64>:1:24' */
    /* '<S64>:1:253' */
    /* '<S64>:1:26' */
    /* '<S64>:1:253' */
    /* '<S64>:1:28' */
    /* '<S64>:1:253' */
    /* '<S64>:1:30' */
    /* '<S64>:1:253' */
    /* '<S64>:1:128' */
    for (i = 0; i < 15; i++) {
      rseq[i * reaction_pendulum_ny] = reaction_pendulum_P.Ref1_Value[0];
      rseq[i * reaction_pendulum_ny + 1] = reaction_pendulum_P.Ref1_Value[1];
      rseq[i * reaction_pendulum_ny + 2] = reaction_pendulum_P.Ref1_Value[2];
    }

    /* '<S64>:1:133' */
    /* '<S64>:1:143' */
    /* '<S64>:1:150' */
    /* '<S64>:1:153' */
    for (i = 0; i < 6; i++) {
      xk[i] = reaction_pendulum_DW.last_x_PreviousInput_b[i];
    }

    /* SignalConversion generated from: '<S64>/ SFunction ' incorporates:
     *  MATLAB Function: '<S63>/optimizer'
     */
    /* '<S64>:1:155' */
    /* '<S64>:1:156' */
    tmp[0] = reaction_pendulum_B.Delay1[0];
    tmp[1] = reaction_pendulum_B.AB;
    tmp[2] = reaction_pendulum_B.Delay1[1];

    /* MATLAB Function: '<S63>/optimizer' incorporates:
     *  Memory: '<S43>/Memory'
     */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Integrator = 0.0;
      for (i = 0; i < 6; i++) {
        rtb_Integrator += (real_T)a[3 * i + i_0] * xk[i];
      }

      y_innov[i_0] = tmp[i_0] - rtb_Integrator;
    }

    /* '<S64>:1:157' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_xest_i[i_0] = ((b_a_0[i_0 + 6] * y_innov[1] + b_a_0[i_0] * y_innov[0])
                         + b_a_0[i_0 + 12] * y_innov[2]) + xk[i_0];
    }

    /* '<S64>:1:216' */
    memset(&f[0], 0, 11U * sizeof(real_T));
    for (i = 0; i < 10; i++) {
      rtb_Integrator = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        rtb_Integrator += b_Kx_0[6 * i + i_0] * rtb_xest_i[i_0];
      }

      b_Kr = 0.0;
      for (i_0 = 0; i_0 < 45; i_0++) {
        b_Kr += b_Kr_1[45 * i + i_0] * rseq[i_0];
      }

      f[i] = (rtb_Integrator + b_Kr) + b_Ku1_0[i] * rtb_last_mv;
    }

    for (i = 0; i < 60; i++) {
      iAnew[i] = reaction_pendulum_DW.Memory_PreviousInput_e[i];
      b_Kr = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        b_Kr += c_a_0[60 * i_0 + i] * rtb_xest_i[i_0];
      }

      b_Mlim[i] = -((b_Mlim_0[i] + b_Kr) + d_a_0[i] * rtb_last_mv);
    }

    reaction_pendulum_qpkwik(b_Linv_0, b_Hinv_0, f, b_Ac_0, b_Mlim, iAnew, 284,
      1.0E-6, zopt, a__1, &rtb_Integrator);
    for (i = 0; i < 60; i++) {
      reaction_pendulum_B.iAout[i] = (iAnew[i] != 0);
    }

    b_Kr = rt_roundd_snf(rtb_Integrator);
    if (b_Kr < 2.147483648E+9) {
      if (b_Kr >= -2.147483648E+9) {
        i_0 = (int32_T)b_Kr;
      } else {
        i_0 = MIN_int32_T;
      }

      if (b_Kr >= -2.147483648E+9) {
        i = (int32_T)b_Kr;
      } else {
        i = MIN_int32_T;
      }
    } else {
      i_0 = MAX_int32_T;
      i = MAX_int32_T;
    }

    if ((i_0 < 0) || (i == 0)) {
      memset(&zopt[0], 0, 11U * sizeof(real_T));
    }

    rtb_Integrator = rtb_last_mv + zopt[0];

    /* '<S64>:1:216' */
    reaction_pendulum_B.u = rtb_Integrator;

    /* '<S64>:1:216' */
    /* '<S64>:1:234' */
    /* '<S64>:1:235' */
    /* '<S64>:1:242' */
    /* '<S64>:1:244' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      b_Kr = 0.0;
      for (i = 0; i < 6; i++) {
        b_Kr += e_a_0[6 * i + i_0] * xk[i];
      }

      reaction_pendulum_B.xk1[i_0] = ((g_a_0[i_0 + 6] * y_innov[1] + g_a_0[i_0] *
        y_innov[0]) + g_a_0[i_0 + 12] * y_innov[2]) + (f_a[i_0] * rtb_Integrator
        + b_Kr);
    }

    /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
     *  Constant: '<Root>/<Controller selection'
     */
    /* '<S64>:1:247' */
    switch ((int32_T)reaction_pendulum_P.Controllerselection_Value) {
     case 1:
      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Gain: '<S3>/LQR STABLE'
       *  SignalConversion generated from: '<S3>/LQR STABLE'
       */
      reaction_pendulum_B.Control = (-reaction_pendulum_P.K[0] *
        reaction_pendulum_B.Delay1[0] + -reaction_pendulum_P.K[1] *
        reaction_pendulum_B.AB) + -reaction_pendulum_P.K[2] *
        reaction_pendulum_B.Delay1[1];
      break;

     case 2:
      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Gain: '<S3>/LQR UNSTABLE'
       *  SignalConversion generated from: '<S3>/LQR STABLE'
       */
      reaction_pendulum_B.Control = (-reaction_pendulum_P.K_Unst[0] *
        reaction_pendulum_B.Delay1[0] + -reaction_pendulum_P.K_Unst[1] *
        reaction_pendulum_B.AB) + -reaction_pendulum_P.K_Unst[2] *
        reaction_pendulum_B.Delay1[1];
      break;

     case 3:
      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Gain: '<S21>/umin_scale1'
       */
      reaction_pendulum_B.Control = reaction_pendulum_P.umin_scale1_Gain *
        reaction_pendulum_B.u_f;
      break;

     case 4:
      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Gain: '<S43>/umin_scale1'
       */
      reaction_pendulum_B.Control = reaction_pendulum_P.umin_scale1_Gain_g *
        reaction_pendulum_B.u;
      break;

     default:
      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Default stop on error'
       */
      reaction_pendulum_B.Control = reaction_pendulum_P.Defaultstoponerror_Value;
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

    /* Gain: '<S2>/Gain2' */
    rtb_last_mv = reaction_pendulum_P.Gain2_Gain * reaction_pendulum_B.Control;

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
    if (reaction_pendulum_M->Timing.t[0] < reaction_pendulum_P.h) {
      rtb_Integrator = reaction_pendulum_P.Step2_Y0;
    } else {
      rtb_Integrator = reaction_pendulum_P.Step2_YFinal;
    }

    /* End of Step: '<Root>/Step2' */

    /* Gain: '<S2>/Gain' */
    reaction_pendulum_B.Gain[0] = reaction_pendulum_P.Gain_Gain[0] *
      rtb_Integrator;
    reaction_pendulum_B.Gain[1] = reaction_pendulum_P.Gain_Gain[1] *
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
      reaction_pendulum_DW.Memory_PreviousInput) *
      reaction_pendulum_P.Gain1_Gain;

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
                            &locTime, &reaction_pendulum_B.Control);
    }

    /* Gain: '<S13>/Minimum sampling to time constant ratio' */
    rtb_Integrator = reaction_pendulum_P.FilteredDerivative_minRatio *
      reaction_pendulum_B.Probe_f[0];

    /* MinMax: '<S13>/MinMax' incorporates:
     *  Constant: '<S13>/Time constant'
     */
    if ((!(rtb_Integrator >= reaction_pendulum_P.h)) && (!rtIsNaN
         (reaction_pendulum_P.h))) {
      rtb_Integrator = reaction_pendulum_P.h;
    }

    /* End of MinMax: '<S13>/MinMax' */

    /* Constant: '<S16>/Constant' */
    reaction_pendulum_B.Constant_a = reaction_pendulum_P.FilteredDerivative_x0;

    /* DiscreteIntegrator: '<S18>/Integrator' incorporates:
     *  Constant: '<S5>/Constant'
     */
    if ((reaction_pendulum_P.Constant_Value_p != 0.0) ||
        (reaction_pendulum_DW.Integrator_PrevResetState_l != 0)) {
      reaction_pendulum_DW.Integrator_DSTATE_g = reaction_pendulum_B.Constant_a;
      if (reaction_pendulum_DW.Integrator_DSTATE_g >=
          reaction_pendulum_P.Integrator_UpperSat_o) {
        reaction_pendulum_DW.Integrator_DSTATE_g =
          reaction_pendulum_P.Integrator_UpperSat_o;
      } else if (reaction_pendulum_DW.Integrator_DSTATE_g <=
                 reaction_pendulum_P.Integrator_LowerSat_h) {
        reaction_pendulum_DW.Integrator_DSTATE_g =
          reaction_pendulum_P.Integrator_LowerSat_h;
      }
    }

    if (reaction_pendulum_DW.Integrator_DSTATE_g >=
        reaction_pendulum_P.Integrator_UpperSat_o) {
      reaction_pendulum_DW.Integrator_DSTATE_g =
        reaction_pendulum_P.Integrator_UpperSat_o;
    } else if (reaction_pendulum_DW.Integrator_DSTATE_g <=
               reaction_pendulum_P.Integrator_LowerSat_h) {
      reaction_pendulum_DW.Integrator_DSTATE_g =
        reaction_pendulum_P.Integrator_LowerSat_h;
    }

    /* Saturate: '<S18>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S18>/Integrator'
     */
    if (reaction_pendulum_DW.Integrator_DSTATE_g >
        reaction_pendulum_P.Saturation_UpperSat_b) {
      /* Saturate: '<S18>/Saturation' */
      rtb_Saturation_h = reaction_pendulum_P.Saturation_UpperSat_b;
    } else if (reaction_pendulum_DW.Integrator_DSTATE_g <
               reaction_pendulum_P.Saturation_LowerSat_k) {
      /* Saturate: '<S18>/Saturation' */
      rtb_Saturation_h = reaction_pendulum_P.Saturation_LowerSat_k;
    } else {
      /* Saturate: '<S18>/Saturation' */
      rtb_Saturation_h = reaction_pendulum_DW.Integrator_DSTATE_g;
    }

    /* End of Saturate: '<S18>/Saturation' */

    /* Product: '<S5>/1//T' incorporates:
     *  Fcn: '<S13>/Avoid Divide by Zero'
     *  Sum: '<S5>/Sum1'
     */
    rtb_uT_a = 1.0 / ((real_T)(rtb_Integrator == 0.0) * 2.2204460492503131e-16 +
                      rtb_Integrator) * (reaction_pendulum_B.PendulumAnglerad -
      rtb_Saturation_h);

    /* Gain: '<S5>/Gain' */
    rtb_last_mv = reaction_pendulum_P.FilteredDerivative_K * rtb_uT_a;

    /* Saturate: '<S5>/[A,B]' */
    if (rtb_last_mv > reaction_pendulum_P.FilteredDerivative_B) {
      /* Saturate: '<S5>/[A,B]' */
      reaction_pendulum_B.AB_o = reaction_pendulum_P.FilteredDerivative_B;
    } else if (rtb_last_mv < reaction_pendulum_P.FilteredDerivative_A) {
      /* Saturate: '<S5>/[A,B]' */
      reaction_pendulum_B.AB_o = reaction_pendulum_P.FilteredDerivative_A;
    } else {
      /* Saturate: '<S5>/[A,B]' */
      reaction_pendulum_B.AB_o = rtb_last_mv;
    }

    /* End of Saturate: '<S5>/[A,B]' */
    /* SignalConversion generated from: '<S1>/Delay1' */
    reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[0] =
      reaction_pendulum_B.PendulumAnglerad;
    reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[1] =
      reaction_pendulum_B.DCVelrads;

    /* ToWorkspace: '<Root>/To Workspace' */
    {
      double locTime = reaction_pendulum_M->Timing.t[1]
        ;
      rt_UpdateStructLogVar((StructLogVar *)
                            reaction_pendulum_DW.ToWorkspace_PWORK.LoggedData,
                            &locTime,
                            &reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[
                            0]);
    }
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(reaction_pendulum_M->rtwLogInfo,
                      (reaction_pendulum_M->Timing.t));

  {
    int32_T i;

    /* Update for Delay: '<S1>/Delay1' */
    reaction_pendulum_DW.Delay1_DSTATE[0] =
      reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[0];
    reaction_pendulum_DW.Delay1_DSTATE[1] =
      reaction_pendulum_B.TmpSignalConversionAtDelay1Inpo[1];

    /* Update for DiscreteIntegrator: '<S12>/Integrator' incorporates:
     *  Constant: '<S6>/Constant'
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

    /* End of Update for DiscreteIntegrator: '<S12>/Integrator' */

    /* Update for Memory: '<S21>/last_x' */
    for (i = 0; i < 6; i++) {
      reaction_pendulum_DW.last_x_PreviousInput[i] = reaction_pendulum_B.xk1_a[i];
    }

    /* End of Update for Memory: '<S21>/last_x' */

    /* Update for UnitDelay: '<S21>/last_mv' */
    reaction_pendulum_DW.last_mv_DSTATE = reaction_pendulum_B.u_f;

    /* Update for Memory: '<S21>/Memory' */
    for (i = 0; i < 60; i++) {
      reaction_pendulum_DW.Memory_PreviousInput_h[i] =
        reaction_pendulum_B.iAout_m[i];
    }

    /* End of Update for Memory: '<S21>/Memory' */

    /* Update for Memory: '<S43>/last_x' */
    for (i = 0; i < 6; i++) {
      reaction_pendulum_DW.last_x_PreviousInput_b[i] = reaction_pendulum_B.xk1[i];
    }

    /* End of Update for Memory: '<S43>/last_x' */

    /* Update for UnitDelay: '<S43>/last_mv' */
    reaction_pendulum_DW.last_mv_DSTATE_d = reaction_pendulum_B.u;

    /* Update for Memory: '<S43>/Memory' */
    for (i = 0; i < 60; i++) {
      reaction_pendulum_DW.Memory_PreviousInput_e[i] =
        reaction_pendulum_B.iAout[i];
    }

    /* End of Update for Memory: '<S43>/Memory' */

    /* Update for Memory: '<S2>/Memory1' */
    reaction_pendulum_DW.Memory1_PreviousInput = rtb_DCAnglerad;

    /* Update for Memory: '<S2>/Memory' */
    reaction_pendulum_DW.Memory_PreviousInput = reaction_pendulum_B.SFunction_o6;

    /* Update for DiscreteIntegrator: '<S18>/Integrator' incorporates:
     *  Constant: '<S5>/Constant'
     */
    if (reaction_pendulum_P.Constant_Value_p == 0.0) {
      reaction_pendulum_DW.Integrator_DSTATE_g +=
        reaction_pendulum_P.Integrator_gainval_n * rtb_uT_a;
      if (reaction_pendulum_DW.Integrator_DSTATE_g >=
          reaction_pendulum_P.Integrator_UpperSat_o) {
        reaction_pendulum_DW.Integrator_DSTATE_g =
          reaction_pendulum_P.Integrator_UpperSat_o;
      } else if (reaction_pendulum_DW.Integrator_DSTATE_g <=
                 reaction_pendulum_P.Integrator_LowerSat_h) {
        reaction_pendulum_DW.Integrator_DSTATE_g =
          reaction_pendulum_P.Integrator_LowerSat_h;
      }
    }

    if (reaction_pendulum_P.Constant_Value_p > 0.0) {
      reaction_pendulum_DW.Integrator_PrevResetState_l = 1;
    } else if (reaction_pendulum_P.Constant_Value_p < 0.0) {
      reaction_pendulum_DW.Integrator_PrevResetState_l = -1;
    } else if (reaction_pendulum_P.Constant_Value_p == 0.0) {
      reaction_pendulum_DW.Integrator_PrevResetState_l = 0;
    } else {
      reaction_pendulum_DW.Integrator_PrevResetState_l = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S18>/Integrator' */
  }

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
  reaction_pendulum_P.FilteredDerivative_A = rtMinusInf;
  reaction_pendulum_P.FilteredDerivative1_B = rtInf;
  reaction_pendulum_P.FilteredDerivative_B = rtInf;
  reaction_pendulum_P.Integrator_UpperSat = rtInf;
  reaction_pendulum_P.Integrator_LowerSat = rtMinusInf;
  reaction_pendulum_P.Saturation_UpperSat = rtInf;
  reaction_pendulum_P.Saturation_LowerSat = rtMinusInf;
  reaction_pendulum_P.Integrator_UpperSat_o = rtInf;
  reaction_pendulum_P.Integrator_LowerSat_h = rtMinusInf;
  reaction_pendulum_P.Saturation_UpperSat_b = rtInf;
  reaction_pendulum_P.Saturation_LowerSat_k = rtMinusInf;

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
  reaction_pendulum_M->Sizes.checksums[0] = (737472710U);
  reaction_pendulum_M->Sizes.checksums[1] = (1053608817U);
  reaction_pendulum_M->Sizes.checksums[2] = (1229746792U);
  reaction_pendulum_M->Sizes.checksums[3] = (4284285695U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    reaction_pendulum_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
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
      "CtrlIn",
      1,
      0,
      1,
      0.05,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (reaction_pendulum_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

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

    static const char_T rt_ToWksBlockName[] = "reaction_pendulum/To Workspace";
    reaction_pendulum_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      reaction_pendulum_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(reaction_pendulum_M),
      reaction_pendulum_M->Timing.stepSize0,
      (&rtmGetErrorStatus(reaction_pendulum_M)),
      "Meas",
      1,
      0,
      1,
      0.05,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (reaction_pendulum_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Probe: '<S7>/Probe' */
  reaction_pendulum_B.Probe[0] = 0.05;
  reaction_pendulum_B.Probe[1] = 0.0;

  /* Start for Constant: '<S10>/Constant' */
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

  /* Start for Probe: '<S13>/Probe' */
  reaction_pendulum_B.Probe_f[0] = 0.05;
  reaction_pendulum_B.Probe_f[1] = 0.0;

  /* Start for Constant: '<S16>/Constant' */
  reaction_pendulum_B.Constant_a = reaction_pendulum_P.FilteredDerivative_x0;

  {
    int32_T i;

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    reaction_pendulum_DW.Delay1_DSTATE[0] =
      reaction_pendulum_P.Delay1_InitialCondition;
    reaction_pendulum_DW.Delay1_DSTATE[1] =
      reaction_pendulum_P.Delay1_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S12>/Integrator' */
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

    /* End of InitializeConditions for DiscreteIntegrator: '<S12>/Integrator' */

    /* InitializeConditions for Memory: '<S21>/last_x' */
    for (i = 0; i < 6; i++) {
      reaction_pendulum_DW.last_x_PreviousInput[i] =
        reaction_pendulum_P.last_x_InitialCondition[i];
    }

    /* End of InitializeConditions for Memory: '<S21>/last_x' */

    /* InitializeConditions for UnitDelay: '<S21>/last_mv' */
    reaction_pendulum_DW.last_mv_DSTATE =
      reaction_pendulum_P.last_mv_InitialCondition;

    /* InitializeConditions for Memory: '<S21>/Memory' */
    for (i = 0; i < 60; i++) {
      reaction_pendulum_DW.Memory_PreviousInput_h[i] =
        reaction_pendulum_P.Memory_InitialCondition_p[i];
    }

    /* End of InitializeConditions for Memory: '<S21>/Memory' */

    /* InitializeConditions for Memory: '<S43>/last_x' */
    for (i = 0; i < 6; i++) {
      reaction_pendulum_DW.last_x_PreviousInput_b[i] =
        reaction_pendulum_P.last_x_InitialCondition_e[i];
    }

    /* End of InitializeConditions for Memory: '<S43>/last_x' */

    /* InitializeConditions for UnitDelay: '<S43>/last_mv' */
    reaction_pendulum_DW.last_mv_DSTATE_d =
      reaction_pendulum_P.last_mv_InitialCondition_g;

    /* InitializeConditions for Memory: '<S43>/Memory' */
    for (i = 0; i < 60; i++) {
      reaction_pendulum_DW.Memory_PreviousInput_e[i] =
        reaction_pendulum_P.Memory_InitialCondition_a[i];
    }

    /* End of InitializeConditions for Memory: '<S43>/Memory' */

    /* InitializeConditions for Memory: '<S2>/Memory1' */
    reaction_pendulum_DW.Memory1_PreviousInput =
      reaction_pendulum_P.Memory1_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    reaction_pendulum_DW.Memory_PreviousInput =
      reaction_pendulum_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Integrator' */
    reaction_pendulum_DW.Integrator_DSTATE_g = reaction_pendulum_B.Constant_a;
    if (reaction_pendulum_DW.Integrator_DSTATE_g >=
        reaction_pendulum_P.Integrator_UpperSat_o) {
      reaction_pendulum_DW.Integrator_DSTATE_g =
        reaction_pendulum_P.Integrator_UpperSat_o;
    } else if (reaction_pendulum_DW.Integrator_DSTATE_g <=
               reaction_pendulum_P.Integrator_LowerSat_h) {
      reaction_pendulum_DW.Integrator_DSTATE_g =
        reaction_pendulum_P.Integrator_LowerSat_h;
    }

    reaction_pendulum_DW.Integrator_PrevResetState_l = 0;

    /* End of InitializeConditions for DiscreteIntegrator: '<S18>/Integrator' */
  }
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
