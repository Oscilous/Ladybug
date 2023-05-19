/*
 * quadcopter_sim.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "quadcopter_sim".
 *
 * Model version              : 2.35
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri May 19 10:25:36 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "quadcopter_sim.h"
#include "rtwtypes.h"
#include "quadcopter_sim_private.h"

/* Block signals (default storage) */
B_quadcopter_sim_T quadcopter_sim_B;

/* Continuous states */
X_quadcopter_sim_T quadcopter_sim_X;

/* Real-time model */
static RT_MODEL_quadcopter_sim_T quadcopter_sim_M_;
RT_MODEL_quadcopter_sim_T *const quadcopter_sim_M = &quadcopter_sim_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  quadcopter_sim_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  quadcopter_sim_step();
  quadcopter_sim_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  quadcopter_sim_step();
  quadcopter_sim_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void quadcopter_sim_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;
  real_T rtb_Saturation1;
  real_T rtb_Saturation2;
  real_T rtb_Saturation3;
  real_T rtb_Add3;
  real_T rtb_Divide1;
  real_T rtb_Divide2;
  real_T rtb_Divide3;
  real_T u0;
  real_T u0_tmp;
  if (rtmIsMajorTimeStep(quadcopter_sim_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&quadcopter_sim_M->solverInfo,
                          ((quadcopter_sim_M->Timing.clockTick0+1)*
      quadcopter_sim_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(quadcopter_sim_M)) {
    quadcopter_sim_M->Timing.t[0] = rtsiGetT(&quadcopter_sim_M->solverInfo);
  }

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Integrator: '<S34>/Filter'
   *  Sum: '<S34>/SumD'
   */
  quadcopter_sim_B.FilterCoefficient = (-0.42374999999999996 -
    quadcopter_sim_X.Filter_CSTATE) * 100.0;

  /* Product: '<S1>/Divide4' incorporates:
   *  Integrator: '<S39>/Integrator'
   *  Sum: '<S48>/Sum'
   */
  rtb_Add3 = ((quadcopter_sim_X.Integrator_CSTATE - 1.53) +
              quadcopter_sim_B.FilterCoefficient) / -0.00016;

  /* Gain: '<S90>/Filter Coefficient' incorporates:
   *  Integrator: '<S82>/Filter'
   *  Sum: '<S82>/SumD'
   */
  quadcopter_sim_B.FilterCoefficient_k = (-0.0 -
    quadcopter_sim_X.Filter_CSTATE_h) * 1008.51334195282;

  /* Product: '<S1>/Divide3' incorporates:
   *  Integrator: '<S87>/Integrator'
   *  Sum: '<S96>/Sum'
   */
  rtb_Divide3 = (quadcopter_sim_X.Integrator_CSTATE_g +
                 quadcopter_sim_B.FilterCoefficient_k) / 6.5619509294111619E-6;

  /* Gain: '<S138>/Filter Coefficient' incorporates:
   *  Integrator: '<S130>/Filter'
   *  Sum: '<S130>/SumD'
   */
  quadcopter_sim_B.FilterCoefficient_e = (-0.0 -
    quadcopter_sim_X.Filter_CSTATE_hc) * 1008.51334195282;

  /* Product: '<S1>/Divide2' incorporates:
   *  Integrator: '<S135>/Integrator'
   *  Sum: '<S144>/Sum'
   */
  rtb_Divide2 = (quadcopter_sim_X.Integrator_CSTATE_o +
                 quadcopter_sim_B.FilterCoefficient_e) / 6.5619509294111619E-6;

  /* Gain: '<S186>/Filter Coefficient' incorporates:
   *  Integrator: '<S178>/Filter'
   *  Sum: '<S178>/SumD'
   */
  quadcopter_sim_B.FilterCoefficient_m = (0.0 - quadcopter_sim_X.Filter_CSTATE_f)
    * 100.0;

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Integrator: '<S183>/Integrator'
   *  Sum: '<S192>/Sum'
   */
  rtb_Divide1 = (quadcopter_sim_X.Integrator_CSTATE_n +
                 quadcopter_sim_B.FilterCoefficient_m) / 0.00464;

  /* Sum: '<S1>/Add' incorporates:
   *  Sum: '<S1>/Add3'
   */
  u0_tmp = rtb_Add3 + rtb_Divide3;
  u0 = (u0_tmp + rtb_Divide2) + rtb_Divide1;

  /* Saturate: '<S1>/Saturation' */
  if (u0 > 3500.0) {
    /* Saturate: '<S1>/Saturation' */
    rtb_Saturation = 3500.0;
  } else if (u0 < 0.0) {
    /* Saturate: '<S1>/Saturation' */
    rtb_Saturation = 0.0;
  } else {
    /* Saturate: '<S1>/Saturation' */
    rtb_Saturation = u0;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Sum: '<S1>/Add1' incorporates:
   *  Sum: '<S1>/Add2'
   */
  rtb_Add3 -= rtb_Divide3;
  u0 = (rtb_Add3 + rtb_Divide2) - rtb_Divide1;

  /* Saturate: '<S1>/Saturation1' */
  if (u0 > 3500.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Saturation1 = 3500.0;
  } else if (u0 < 0.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Saturation1 = 0.0;
  } else {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Saturation1 = u0;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Sum: '<S1>/Add2' */
  u0 = (rtb_Add3 - rtb_Divide2) + rtb_Divide1;

  /* Saturate: '<S1>/Saturation2' */
  if (u0 > 3500.0) {
    /* Saturate: '<S1>/Saturation2' */
    rtb_Saturation2 = 3500.0;
  } else if (u0 < 0.0) {
    /* Saturate: '<S1>/Saturation2' */
    rtb_Saturation2 = 0.0;
  } else {
    /* Saturate: '<S1>/Saturation2' */
    rtb_Saturation2 = u0;
  }

  /* End of Saturate: '<S1>/Saturation2' */

  /* Sum: '<S1>/Add3' */
  u0 = (u0_tmp - rtb_Divide2) - rtb_Divide1;

  /* Saturate: '<S1>/Saturation3' */
  if (u0 > 3500.0) {
    /* Saturate: '<S1>/Saturation3' */
    rtb_Saturation3 = 3500.0;
  } else if (u0 < 0.0) {
    /* Saturate: '<S1>/Saturation3' */
    rtb_Saturation3 = 0.0;
  } else {
    /* Saturate: '<S1>/Saturation3' */
    rtb_Saturation3 = u0;
  }

  /* End of Saturate: '<S1>/Saturation3' */
  if (rtmIsMajorTimeStep(quadcopter_sim_M)) {
    rt_ertODEUpdateContinuousStates(&quadcopter_sim_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++quadcopter_sim_M->Timing.clockTick0;
    quadcopter_sim_M->Timing.t[0] = rtsiGetSolverStopTime
      (&quadcopter_sim_M->solverInfo);

    {
      /* Update absolute timer for sample time: [2.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 2.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      quadcopter_sim_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void quadcopter_sim_derivatives(void)
{
  XDot_quadcopter_sim_T *_rtXdot;
  _rtXdot = ((XDot_quadcopter_sim_T *) quadcopter_sim_M->derivs);

  /* Derivatives for Integrator: '<S39>/Integrator' */
  _rtXdot->Integrator_CSTATE = -0.57000000000000006;

  /* Derivatives for Integrator: '<S34>/Filter' */
  _rtXdot->Filter_CSTATE = quadcopter_sim_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S87>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = -0.0;

  /* Derivatives for Integrator: '<S82>/Filter' */
  _rtXdot->Filter_CSTATE_h = quadcopter_sim_B.FilterCoefficient_k;

  /* Derivatives for Integrator: '<S135>/Integrator' */
  _rtXdot->Integrator_CSTATE_o = -0.0;

  /* Derivatives for Integrator: '<S130>/Filter' */
  _rtXdot->Filter_CSTATE_hc = quadcopter_sim_B.FilterCoefficient_e;

  /* Derivatives for Integrator: '<S183>/Integrator' */
  _rtXdot->Integrator_CSTATE_n = 0.0;

  /* Derivatives for Integrator: '<S178>/Filter' */
  _rtXdot->Filter_CSTATE_f = quadcopter_sim_B.FilterCoefficient_m;
}

/* Model initialize function */
void quadcopter_sim_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)quadcopter_sim_M, 0,
                sizeof(RT_MODEL_quadcopter_sim_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&quadcopter_sim_M->solverInfo,
                          &quadcopter_sim_M->Timing.simTimeStep);
    rtsiSetTPtr(&quadcopter_sim_M->solverInfo, &rtmGetTPtr(quadcopter_sim_M));
    rtsiSetStepSizePtr(&quadcopter_sim_M->solverInfo,
                       &quadcopter_sim_M->Timing.stepSize0);
    rtsiSetdXPtr(&quadcopter_sim_M->solverInfo, &quadcopter_sim_M->derivs);
    rtsiSetContStatesPtr(&quadcopter_sim_M->solverInfo, (real_T **)
                         &quadcopter_sim_M->contStates);
    rtsiSetNumContStatesPtr(&quadcopter_sim_M->solverInfo,
      &quadcopter_sim_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&quadcopter_sim_M->solverInfo,
      &quadcopter_sim_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&quadcopter_sim_M->solverInfo,
      &quadcopter_sim_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&quadcopter_sim_M->solverInfo,
      &quadcopter_sim_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&quadcopter_sim_M->solverInfo, (&rtmGetErrorStatus
      (quadcopter_sim_M)));
    rtsiSetRTModelPtr(&quadcopter_sim_M->solverInfo, quadcopter_sim_M);
  }

  rtsiSetSimTimeStep(&quadcopter_sim_M->solverInfo, MAJOR_TIME_STEP);
  quadcopter_sim_M->intgData.y = quadcopter_sim_M->odeY;
  quadcopter_sim_M->intgData.f[0] = quadcopter_sim_M->odeF[0];
  quadcopter_sim_M->intgData.f[1] = quadcopter_sim_M->odeF[1];
  quadcopter_sim_M->intgData.f[2] = quadcopter_sim_M->odeF[2];
  quadcopter_sim_M->contStates = ((X_quadcopter_sim_T *) &quadcopter_sim_X);
  rtsiSetSolverData(&quadcopter_sim_M->solverInfo, (void *)
                    &quadcopter_sim_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&quadcopter_sim_M->solverInfo, false);
  rtsiSetSolverName(&quadcopter_sim_M->solverInfo,"ode3");
  rtmSetTPtr(quadcopter_sim_M, &quadcopter_sim_M->Timing.tArray[0]);
  quadcopter_sim_M->Timing.stepSize0 = 2.0;

  /* block I/O */
  (void) memset(((void *) &quadcopter_sim_B), 0,
                sizeof(B_quadcopter_sim_T));

  /* states (continuous) */
  {
    (void) memset((void *)&quadcopter_sim_X, 0,
                  sizeof(X_quadcopter_sim_T));
  }

  /* InitializeConditions for Integrator: '<S39>/Integrator' */
  quadcopter_sim_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  quadcopter_sim_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S87>/Integrator' */
  quadcopter_sim_X.Integrator_CSTATE_g = 0.0;

  /* InitializeConditions for Integrator: '<S82>/Filter' */
  quadcopter_sim_X.Filter_CSTATE_h = 0.0;

  /* InitializeConditions for Integrator: '<S135>/Integrator' */
  quadcopter_sim_X.Integrator_CSTATE_o = 0.0;

  /* InitializeConditions for Integrator: '<S130>/Filter' */
  quadcopter_sim_X.Filter_CSTATE_hc = 0.0;

  /* InitializeConditions for Integrator: '<S183>/Integrator' */
  quadcopter_sim_X.Integrator_CSTATE_n = 0.0;

  /* InitializeConditions for Integrator: '<S178>/Filter' */
  quadcopter_sim_X.Filter_CSTATE_f = 0.0;
}

/* Model terminate function */
void quadcopter_sim_terminate(void)
{
  /* (no terminate code required) */
}
