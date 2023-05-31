/*
 * quadcopter_sim.h
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

#ifndef RTW_HEADER_quadcopter_sim_h_
#define RTW_HEADER_quadcopter_sim_h_
#ifndef quadcopter_sim_COMMON_INCLUDES_
#define quadcopter_sim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* quadcopter_sim_COMMON_INCLUDES_ */

#include "quadcopter_sim_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

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

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T FilterCoefficient;            /* '<S42>/Filter Coefficient' */
  real_T FilterCoefficient_k;          /* '<S90>/Filter Coefficient' */
  real_T FilterCoefficient_e;          /* '<S138>/Filter Coefficient' */
  real_T FilterCoefficient_m;          /* '<S186>/Filter Coefficient' */
} B_quadcopter_sim_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S39>/Integrator' */
  real_T Filter_CSTATE;                /* '<S34>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<S87>/Integrator' */
  real_T Filter_CSTATE_h;              /* '<S82>/Filter' */
  real_T Integrator_CSTATE_o;          /* '<S135>/Integrator' */
  real_T Filter_CSTATE_hc;             /* '<S130>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S183>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S178>/Filter' */
} X_quadcopter_sim_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S39>/Integrator' */
  real_T Filter_CSTATE;                /* '<S34>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<S87>/Integrator' */
  real_T Filter_CSTATE_h;              /* '<S82>/Filter' */
  real_T Integrator_CSTATE_o;          /* '<S135>/Integrator' */
  real_T Filter_CSTATE_hc;             /* '<S130>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S183>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S178>/Filter' */
} XDot_quadcopter_sim_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S39>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S34>/Filter' */
  boolean_T Integrator_CSTATE_g;       /* '<S87>/Integrator' */
  boolean_T Filter_CSTATE_h;           /* '<S82>/Filter' */
  boolean_T Integrator_CSTATE_o;       /* '<S135>/Integrator' */
  boolean_T Filter_CSTATE_hc;          /* '<S130>/Filter' */
  boolean_T Integrator_CSTATE_n;       /* '<S183>/Integrator' */
  boolean_T Filter_CSTATE_f;           /* '<S178>/Filter' */
} XDis_quadcopter_sim_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Real-time Model Data Structure */
struct tag_RTM_quadcopter_sim_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_quadcopter_sim_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_quadcopter_sim_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint16_T clockTick0;
    time_T stepSize0;
    uint16_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_quadcopter_sim_T quadcopter_sim_B;

/* Continuous states (default storage) */
extern X_quadcopter_sim_T quadcopter_sim_X;

/* Model entry point functions */
extern void quadcopter_sim_initialize(void);
extern void quadcopter_sim_step(void);
extern void quadcopter_sim_terminate(void);

/* Real-time Model object */
extern RT_MODEL_quadcopter_sim_T *const quadcopter_sim_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Saturation1' : Unused code path elimination
 * Block '<S2>/Saturation2' : Unused code path elimination
 * Block '<S2>/Saturation3' : Unused code path elimination
 * Block '<S2>/Saturation4' : Unused code path elimination
 */

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
 * '<Root>' : 'quadcopter_sim'
 * '<S1>'   : 'quadcopter_sim/Controller'
 * '<S2>'   : 'quadcopter_sim/Convert to PWM for MCU'
 * '<S3>'   : 'quadcopter_sim/Controller/MATLAB Function1'
 * '<S4>'   : 'quadcopter_sim/Controller/PID Controller'
 * '<S5>'   : 'quadcopter_sim/Controller/PID Controller1'
 * '<S6>'   : 'quadcopter_sim/Controller/PID Controller2'
 * '<S7>'   : 'quadcopter_sim/Controller/PID Controller3'
 * '<S8>'   : 'quadcopter_sim/Controller/PID Controller/Anti-windup'
 * '<S9>'   : 'quadcopter_sim/Controller/PID Controller/D Gain'
 * '<S10>'  : 'quadcopter_sim/Controller/PID Controller/Filter'
 * '<S11>'  : 'quadcopter_sim/Controller/PID Controller/Filter ICs'
 * '<S12>'  : 'quadcopter_sim/Controller/PID Controller/I Gain'
 * '<S13>'  : 'quadcopter_sim/Controller/PID Controller/Ideal P Gain'
 * '<S14>'  : 'quadcopter_sim/Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'quadcopter_sim/Controller/PID Controller/Integrator'
 * '<S16>'  : 'quadcopter_sim/Controller/PID Controller/Integrator ICs'
 * '<S17>'  : 'quadcopter_sim/Controller/PID Controller/N Copy'
 * '<S18>'  : 'quadcopter_sim/Controller/PID Controller/N Gain'
 * '<S19>'  : 'quadcopter_sim/Controller/PID Controller/P Copy'
 * '<S20>'  : 'quadcopter_sim/Controller/PID Controller/Parallel P Gain'
 * '<S21>'  : 'quadcopter_sim/Controller/PID Controller/Reset Signal'
 * '<S22>'  : 'quadcopter_sim/Controller/PID Controller/Saturation'
 * '<S23>'  : 'quadcopter_sim/Controller/PID Controller/Saturation Fdbk'
 * '<S24>'  : 'quadcopter_sim/Controller/PID Controller/Sum'
 * '<S25>'  : 'quadcopter_sim/Controller/PID Controller/Sum Fdbk'
 * '<S26>'  : 'quadcopter_sim/Controller/PID Controller/Tracking Mode'
 * '<S27>'  : 'quadcopter_sim/Controller/PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'quadcopter_sim/Controller/PID Controller/Tsamp - Integral'
 * '<S29>'  : 'quadcopter_sim/Controller/PID Controller/Tsamp - Ngain'
 * '<S30>'  : 'quadcopter_sim/Controller/PID Controller/postSat Signal'
 * '<S31>'  : 'quadcopter_sim/Controller/PID Controller/preSat Signal'
 * '<S32>'  : 'quadcopter_sim/Controller/PID Controller/Anti-windup/Passthrough'
 * '<S33>'  : 'quadcopter_sim/Controller/PID Controller/D Gain/Internal Parameters'
 * '<S34>'  : 'quadcopter_sim/Controller/PID Controller/Filter/Cont. Filter'
 * '<S35>'  : 'quadcopter_sim/Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S36>'  : 'quadcopter_sim/Controller/PID Controller/I Gain/Internal Parameters'
 * '<S37>'  : 'quadcopter_sim/Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S38>'  : 'quadcopter_sim/Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'quadcopter_sim/Controller/PID Controller/Integrator/Continuous'
 * '<S40>'  : 'quadcopter_sim/Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S41>'  : 'quadcopter_sim/Controller/PID Controller/N Copy/Disabled'
 * '<S42>'  : 'quadcopter_sim/Controller/PID Controller/N Gain/Internal Parameters'
 * '<S43>'  : 'quadcopter_sim/Controller/PID Controller/P Copy/Disabled'
 * '<S44>'  : 'quadcopter_sim/Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'quadcopter_sim/Controller/PID Controller/Reset Signal/Disabled'
 * '<S46>'  : 'quadcopter_sim/Controller/PID Controller/Saturation/Passthrough'
 * '<S47>'  : 'quadcopter_sim/Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S48>'  : 'quadcopter_sim/Controller/PID Controller/Sum/Sum_PID'
 * '<S49>'  : 'quadcopter_sim/Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S50>'  : 'quadcopter_sim/Controller/PID Controller/Tracking Mode/Disabled'
 * '<S51>'  : 'quadcopter_sim/Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'quadcopter_sim/Controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S53>'  : 'quadcopter_sim/Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'quadcopter_sim/Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S55>'  : 'quadcopter_sim/Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S56>'  : 'quadcopter_sim/Controller/PID Controller1/Anti-windup'
 * '<S57>'  : 'quadcopter_sim/Controller/PID Controller1/D Gain'
 * '<S58>'  : 'quadcopter_sim/Controller/PID Controller1/Filter'
 * '<S59>'  : 'quadcopter_sim/Controller/PID Controller1/Filter ICs'
 * '<S60>'  : 'quadcopter_sim/Controller/PID Controller1/I Gain'
 * '<S61>'  : 'quadcopter_sim/Controller/PID Controller1/Ideal P Gain'
 * '<S62>'  : 'quadcopter_sim/Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S63>'  : 'quadcopter_sim/Controller/PID Controller1/Integrator'
 * '<S64>'  : 'quadcopter_sim/Controller/PID Controller1/Integrator ICs'
 * '<S65>'  : 'quadcopter_sim/Controller/PID Controller1/N Copy'
 * '<S66>'  : 'quadcopter_sim/Controller/PID Controller1/N Gain'
 * '<S67>'  : 'quadcopter_sim/Controller/PID Controller1/P Copy'
 * '<S68>'  : 'quadcopter_sim/Controller/PID Controller1/Parallel P Gain'
 * '<S69>'  : 'quadcopter_sim/Controller/PID Controller1/Reset Signal'
 * '<S70>'  : 'quadcopter_sim/Controller/PID Controller1/Saturation'
 * '<S71>'  : 'quadcopter_sim/Controller/PID Controller1/Saturation Fdbk'
 * '<S72>'  : 'quadcopter_sim/Controller/PID Controller1/Sum'
 * '<S73>'  : 'quadcopter_sim/Controller/PID Controller1/Sum Fdbk'
 * '<S74>'  : 'quadcopter_sim/Controller/PID Controller1/Tracking Mode'
 * '<S75>'  : 'quadcopter_sim/Controller/PID Controller1/Tracking Mode Sum'
 * '<S76>'  : 'quadcopter_sim/Controller/PID Controller1/Tsamp - Integral'
 * '<S77>'  : 'quadcopter_sim/Controller/PID Controller1/Tsamp - Ngain'
 * '<S78>'  : 'quadcopter_sim/Controller/PID Controller1/postSat Signal'
 * '<S79>'  : 'quadcopter_sim/Controller/PID Controller1/preSat Signal'
 * '<S80>'  : 'quadcopter_sim/Controller/PID Controller1/Anti-windup/Passthrough'
 * '<S81>'  : 'quadcopter_sim/Controller/PID Controller1/D Gain/Internal Parameters'
 * '<S82>'  : 'quadcopter_sim/Controller/PID Controller1/Filter/Cont. Filter'
 * '<S83>'  : 'quadcopter_sim/Controller/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S84>'  : 'quadcopter_sim/Controller/PID Controller1/I Gain/Internal Parameters'
 * '<S85>'  : 'quadcopter_sim/Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S86>'  : 'quadcopter_sim/Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S87>'  : 'quadcopter_sim/Controller/PID Controller1/Integrator/Continuous'
 * '<S88>'  : 'quadcopter_sim/Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S89>'  : 'quadcopter_sim/Controller/PID Controller1/N Copy/Disabled'
 * '<S90>'  : 'quadcopter_sim/Controller/PID Controller1/N Gain/Internal Parameters'
 * '<S91>'  : 'quadcopter_sim/Controller/PID Controller1/P Copy/Disabled'
 * '<S92>'  : 'quadcopter_sim/Controller/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S93>'  : 'quadcopter_sim/Controller/PID Controller1/Reset Signal/Disabled'
 * '<S94>'  : 'quadcopter_sim/Controller/PID Controller1/Saturation/Passthrough'
 * '<S95>'  : 'quadcopter_sim/Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S96>'  : 'quadcopter_sim/Controller/PID Controller1/Sum/Sum_PID'
 * '<S97>'  : 'quadcopter_sim/Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S98>'  : 'quadcopter_sim/Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S99>'  : 'quadcopter_sim/Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S100>' : 'quadcopter_sim/Controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S101>' : 'quadcopter_sim/Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S102>' : 'quadcopter_sim/Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S103>' : 'quadcopter_sim/Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S104>' : 'quadcopter_sim/Controller/PID Controller2/Anti-windup'
 * '<S105>' : 'quadcopter_sim/Controller/PID Controller2/D Gain'
 * '<S106>' : 'quadcopter_sim/Controller/PID Controller2/Filter'
 * '<S107>' : 'quadcopter_sim/Controller/PID Controller2/Filter ICs'
 * '<S108>' : 'quadcopter_sim/Controller/PID Controller2/I Gain'
 * '<S109>' : 'quadcopter_sim/Controller/PID Controller2/Ideal P Gain'
 * '<S110>' : 'quadcopter_sim/Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S111>' : 'quadcopter_sim/Controller/PID Controller2/Integrator'
 * '<S112>' : 'quadcopter_sim/Controller/PID Controller2/Integrator ICs'
 * '<S113>' : 'quadcopter_sim/Controller/PID Controller2/N Copy'
 * '<S114>' : 'quadcopter_sim/Controller/PID Controller2/N Gain'
 * '<S115>' : 'quadcopter_sim/Controller/PID Controller2/P Copy'
 * '<S116>' : 'quadcopter_sim/Controller/PID Controller2/Parallel P Gain'
 * '<S117>' : 'quadcopter_sim/Controller/PID Controller2/Reset Signal'
 * '<S118>' : 'quadcopter_sim/Controller/PID Controller2/Saturation'
 * '<S119>' : 'quadcopter_sim/Controller/PID Controller2/Saturation Fdbk'
 * '<S120>' : 'quadcopter_sim/Controller/PID Controller2/Sum'
 * '<S121>' : 'quadcopter_sim/Controller/PID Controller2/Sum Fdbk'
 * '<S122>' : 'quadcopter_sim/Controller/PID Controller2/Tracking Mode'
 * '<S123>' : 'quadcopter_sim/Controller/PID Controller2/Tracking Mode Sum'
 * '<S124>' : 'quadcopter_sim/Controller/PID Controller2/Tsamp - Integral'
 * '<S125>' : 'quadcopter_sim/Controller/PID Controller2/Tsamp - Ngain'
 * '<S126>' : 'quadcopter_sim/Controller/PID Controller2/postSat Signal'
 * '<S127>' : 'quadcopter_sim/Controller/PID Controller2/preSat Signal'
 * '<S128>' : 'quadcopter_sim/Controller/PID Controller2/Anti-windup/Passthrough'
 * '<S129>' : 'quadcopter_sim/Controller/PID Controller2/D Gain/Internal Parameters'
 * '<S130>' : 'quadcopter_sim/Controller/PID Controller2/Filter/Cont. Filter'
 * '<S131>' : 'quadcopter_sim/Controller/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S132>' : 'quadcopter_sim/Controller/PID Controller2/I Gain/Internal Parameters'
 * '<S133>' : 'quadcopter_sim/Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S134>' : 'quadcopter_sim/Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S135>' : 'quadcopter_sim/Controller/PID Controller2/Integrator/Continuous'
 * '<S136>' : 'quadcopter_sim/Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S137>' : 'quadcopter_sim/Controller/PID Controller2/N Copy/Disabled'
 * '<S138>' : 'quadcopter_sim/Controller/PID Controller2/N Gain/Internal Parameters'
 * '<S139>' : 'quadcopter_sim/Controller/PID Controller2/P Copy/Disabled'
 * '<S140>' : 'quadcopter_sim/Controller/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S141>' : 'quadcopter_sim/Controller/PID Controller2/Reset Signal/Disabled'
 * '<S142>' : 'quadcopter_sim/Controller/PID Controller2/Saturation/Passthrough'
 * '<S143>' : 'quadcopter_sim/Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S144>' : 'quadcopter_sim/Controller/PID Controller2/Sum/Sum_PID'
 * '<S145>' : 'quadcopter_sim/Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S146>' : 'quadcopter_sim/Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S147>' : 'quadcopter_sim/Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S148>' : 'quadcopter_sim/Controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S149>' : 'quadcopter_sim/Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S150>' : 'quadcopter_sim/Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S151>' : 'quadcopter_sim/Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S152>' : 'quadcopter_sim/Controller/PID Controller3/Anti-windup'
 * '<S153>' : 'quadcopter_sim/Controller/PID Controller3/D Gain'
 * '<S154>' : 'quadcopter_sim/Controller/PID Controller3/Filter'
 * '<S155>' : 'quadcopter_sim/Controller/PID Controller3/Filter ICs'
 * '<S156>' : 'quadcopter_sim/Controller/PID Controller3/I Gain'
 * '<S157>' : 'quadcopter_sim/Controller/PID Controller3/Ideal P Gain'
 * '<S158>' : 'quadcopter_sim/Controller/PID Controller3/Ideal P Gain Fdbk'
 * '<S159>' : 'quadcopter_sim/Controller/PID Controller3/Integrator'
 * '<S160>' : 'quadcopter_sim/Controller/PID Controller3/Integrator ICs'
 * '<S161>' : 'quadcopter_sim/Controller/PID Controller3/N Copy'
 * '<S162>' : 'quadcopter_sim/Controller/PID Controller3/N Gain'
 * '<S163>' : 'quadcopter_sim/Controller/PID Controller3/P Copy'
 * '<S164>' : 'quadcopter_sim/Controller/PID Controller3/Parallel P Gain'
 * '<S165>' : 'quadcopter_sim/Controller/PID Controller3/Reset Signal'
 * '<S166>' : 'quadcopter_sim/Controller/PID Controller3/Saturation'
 * '<S167>' : 'quadcopter_sim/Controller/PID Controller3/Saturation Fdbk'
 * '<S168>' : 'quadcopter_sim/Controller/PID Controller3/Sum'
 * '<S169>' : 'quadcopter_sim/Controller/PID Controller3/Sum Fdbk'
 * '<S170>' : 'quadcopter_sim/Controller/PID Controller3/Tracking Mode'
 * '<S171>' : 'quadcopter_sim/Controller/PID Controller3/Tracking Mode Sum'
 * '<S172>' : 'quadcopter_sim/Controller/PID Controller3/Tsamp - Integral'
 * '<S173>' : 'quadcopter_sim/Controller/PID Controller3/Tsamp - Ngain'
 * '<S174>' : 'quadcopter_sim/Controller/PID Controller3/postSat Signal'
 * '<S175>' : 'quadcopter_sim/Controller/PID Controller3/preSat Signal'
 * '<S176>' : 'quadcopter_sim/Controller/PID Controller3/Anti-windup/Passthrough'
 * '<S177>' : 'quadcopter_sim/Controller/PID Controller3/D Gain/Internal Parameters'
 * '<S178>' : 'quadcopter_sim/Controller/PID Controller3/Filter/Cont. Filter'
 * '<S179>' : 'quadcopter_sim/Controller/PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S180>' : 'quadcopter_sim/Controller/PID Controller3/I Gain/Internal Parameters'
 * '<S181>' : 'quadcopter_sim/Controller/PID Controller3/Ideal P Gain/Passthrough'
 * '<S182>' : 'quadcopter_sim/Controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S183>' : 'quadcopter_sim/Controller/PID Controller3/Integrator/Continuous'
 * '<S184>' : 'quadcopter_sim/Controller/PID Controller3/Integrator ICs/Internal IC'
 * '<S185>' : 'quadcopter_sim/Controller/PID Controller3/N Copy/Disabled'
 * '<S186>' : 'quadcopter_sim/Controller/PID Controller3/N Gain/Internal Parameters'
 * '<S187>' : 'quadcopter_sim/Controller/PID Controller3/P Copy/Disabled'
 * '<S188>' : 'quadcopter_sim/Controller/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S189>' : 'quadcopter_sim/Controller/PID Controller3/Reset Signal/Disabled'
 * '<S190>' : 'quadcopter_sim/Controller/PID Controller3/Saturation/Passthrough'
 * '<S191>' : 'quadcopter_sim/Controller/PID Controller3/Saturation Fdbk/Disabled'
 * '<S192>' : 'quadcopter_sim/Controller/PID Controller3/Sum/Sum_PID'
 * '<S193>' : 'quadcopter_sim/Controller/PID Controller3/Sum Fdbk/Disabled'
 * '<S194>' : 'quadcopter_sim/Controller/PID Controller3/Tracking Mode/Disabled'
 * '<S195>' : 'quadcopter_sim/Controller/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S196>' : 'quadcopter_sim/Controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S197>' : 'quadcopter_sim/Controller/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S198>' : 'quadcopter_sim/Controller/PID Controller3/postSat Signal/Forward_Path'
 * '<S199>' : 'quadcopter_sim/Controller/PID Controller3/preSat Signal/Forward_Path'
 * '<S200>' : 'quadcopter_sim/Convert to PWM for MCU/MATLAB Function'
 * '<S201>' : 'quadcopter_sim/Convert to PWM for MCU/MATLAB Function1'
 * '<S202>' : 'quadcopter_sim/Convert to PWM for MCU/MATLAB Function2'
 * '<S203>' : 'quadcopter_sim/Convert to PWM for MCU/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_quadcopter_sim_h_ */
