#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "simulink_model_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "simulink_model.h"
#include "simulink_model_capi.h"
#include "simulink_model_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"simulink_model/Random Number" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 1 , 0 , TARGET_STRING ( "simulink_model/Saturation" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"simulink_model/Saturation1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 3 , 0 , TARGET_STRING ( "simulink_model/Saturation2" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"simulink_model/Saturation3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 5 , 0 , TARGET_STRING ( "simulink_model/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"simulink_model/Acutator/MATLAB Function/is_active_c2_simulink_model" ) ,
TARGET_STRING ( "is_active_c2_simulink_model" ) , 0 , 1 , 0 , 0 , 2 } , { 7 ,
0 , TARGET_STRING (
"simulink_model/Acutator/MATLAB Function1/is_active_c2_simulink_model" ) ,
TARGET_STRING ( "is_active_c2_simulink_model" ) , 0 , 1 , 0 , 0 , 2 } , { 8 ,
0 , TARGET_STRING (
"simulink_model/Acutator/MATLAB Function2/is_active_c2_simulink_model" ) ,
TARGET_STRING ( "is_active_c2_simulink_model" ) , 0 , 1 , 0 , 0 , 2 } , { 9 ,
0 , TARGET_STRING (
"simulink_model/Acutator/MATLAB Function3/is_active_c2_simulink_model" ) ,
TARGET_STRING ( "is_active_c2_simulink_model" ) , 0 , 1 , 0 , 0 , 2 } , { 10
, 0 , TARGET_STRING ( "simulink_model/Acutator/Gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 3 } , { 11 , 0 , TARGET_STRING (
"simulink_model/Controller/MATLAB Function1/is_active_c6_simulink_model" ) ,
TARGET_STRING ( "is_active_c6_simulink_model" ) , 0 , 1 , 0 , 0 , 2 } , { 12
, 0 , TARGET_STRING ( "simulink_model/Controller/Gain1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 13 , 0 , TARGET_STRING (
"simulink_model/Controller/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
3 } , { 14 , 0 , TARGET_STRING ( "simulink_model/Controller/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"simulink_model/Controller/Integrator1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 16 , 0 , TARGET_STRING ( "simulink_model/Controller/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"simulink_model/Controller/Divide1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 18 , 0 , TARGET_STRING ( "simulink_model/Controller/Divide2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"simulink_model/Controller/Divide3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 20 , 0 , TARGET_STRING ( "simulink_model/Controller/Divide4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 21 , 0 , TARGET_STRING (
"simulink_model/Controller/Divide5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 22 , 0 , TARGET_STRING ( "simulink_model/Controller/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 23 , 0 , TARGET_STRING (
"simulink_model/Controller/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 24 , 0 , TARGET_STRING ( "simulink_model/Controller/Add2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"simulink_model/Controller/Add3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 26 , 0 , TARGET_STRING ( "simulink_model/Plant/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"simulink_model/Plant/Integrator1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 28 , 0 , TARGET_STRING ( "simulink_model/Plant/Integrator10" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"simulink_model/Plant/Integrator11" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 30 , 0 , TARGET_STRING ( "simulink_model/Plant/Integrator2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"simulink_model/Plant/Integrator3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 32 , 0 , TARGET_STRING ( "simulink_model/Plant/Integrator4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"simulink_model/Plant/Integrator5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 34 , 0 , TARGET_STRING ( "simulink_model/Plant/Integrator6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
"simulink_model/Plant/Integrator7" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 36 , 0 , TARGET_STRING ( "simulink_model/Plant/Integrator8" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 37 , 0 , TARGET_STRING (
"simulink_model/Plant/Integrator9" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 38 , 0 , TARGET_STRING (
"simulink_model/Acutator/Subsystem1/MATLAB Function/is_active_c5_simulink_model"
) , TARGET_STRING ( "is_active_c5_simulink_model" ) , 0 , 1 , 0 , 0 , 2 } , {
39 , 0 , TARGET_STRING ( "simulink_model/Controller/Phi PID/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 40 , 0 , TARGET_STRING (
"simulink_model/Controller/Phi PID/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"simulink_model/Controller/Phi PID/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 42 , 0 , TARGET_STRING (
"simulink_model/Controller/Phi PID/Integrator" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 43 , 0 , TARGET_STRING (
"simulink_model/Controller/Phi PID/Integrator1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 44 , 0 , TARGET_STRING (
"simulink_model/Controller/Phi PID/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 45 , 0 , TARGET_STRING (
"simulink_model/Controller/Phi PID/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 46 , 0 , TARGET_STRING (
"simulink_model/Controller/Psi' PID/Derivative" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 47 , 0 , TARGET_STRING (
"simulink_model/Controller/Psi' PID/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 48 , 0 , TARGET_STRING (
"simulink_model/Controller/Psi' PID/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 49 , 0 , TARGET_STRING (
"simulink_model/Controller/Psi' PID/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 50 , 0 , TARGET_STRING (
"simulink_model/Controller/Psi' PID/Integrator" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 51 , 0 , TARGET_STRING (
"simulink_model/Controller/Psi' PID/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 52 , 0 , TARGET_STRING (
"simulink_model/Controller/Psi' PID/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 53 , 0 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 54 , 0 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 55 , 0 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 56 , 0 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Integrator" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 57 , 0 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Integrator1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 58 , 0 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Add" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 60 , 0 , TARGET_STRING (
"simulink_model/Controller/Z PID/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 61 , 0 , TARGET_STRING ( "simulink_model/Controller/Z PID/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 62 , 0 , TARGET_STRING (
"simulink_model/Controller/Z PID/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 63 , 0 , TARGET_STRING (
"simulink_model/Controller/Z PID/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 64 , 0 , TARGET_STRING (
"simulink_model/Controller/Z PID/Integrator1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 65 , 0 , TARGET_STRING (
"simulink_model/Controller/Z PID/Integrator2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 66 , 0 , TARGET_STRING (
"simulink_model/Controller/Z PID/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 67 , 0 , TARGET_STRING ( "simulink_model/Controller/Z PID/Add1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 68 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 69 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 70 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 71 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Product2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 72 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Product3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 73 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 74 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 75 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 76 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 77 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 78 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Add1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 79 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Add2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 80 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Add3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 81 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Add4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 82 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Phi angular accelration/Divide" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 83 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Phi angular accelration/Product" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 84 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Phi angular accelration/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 85 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Phi angular accelration/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 86 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Phi angular accelration/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 87 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Subsystem1/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 88 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Subsystem1/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 89 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Subsystem1/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 90 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Subsystem1/Product2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 91 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Subsystem1/Add" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 92 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Subsystem2/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 93 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Subsystem2/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 94 , 0 , TARGET_STRING (
"simulink_model/Plant/Angular accelaration/Subsystem2/Add" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 95 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/X axis accelaration/Divide1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 96 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/X axis accelaration/Product" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 97 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/X axis accelaration/Product1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 98 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/X axis accelaration/Product2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 99 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/X axis accelaration/Product3" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 100 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/X axis accelaration/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 101 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/X axis accelaration/Add1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 102 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Y axis accelaration/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 103 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Y axis accelaration/Product" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 104 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Y axis accelaration/Product1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 105 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Y axis accelaration/Product2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 106 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Y axis accelaration/Product3" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 107 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Y axis accelaration/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 108 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Y axis accelaration/Add1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 109 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Z axis accelaration/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 110 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Z axis accelaration/Product" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 111 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Z axis accelaration/Product1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 112 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Z axis accelaration/Product3" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 113 , 0 , TARGET_STRING (
"simulink_model/Plant/Coordinate accelaration/Z axis accelaration/Add1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 114 , TARGET_STRING (
"simulink_model/ALWAYS NEGATIVE" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 115 , TARGET_STRING ( "simulink_model/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 116 , TARGET_STRING ( "simulink_model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 117 , TARGET_STRING (
"simulink_model/Constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
118 , TARGET_STRING ( "simulink_model/Constant4" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 119 , TARGET_STRING ( "simulink_model/Random Number" ) ,
TARGET_STRING ( "Mean" ) , 0 , 0 , 0 } , { 120 , TARGET_STRING (
"simulink_model/Random Number" ) , TARGET_STRING ( "StdDev" ) , 0 , 0 , 0 } ,
{ 121 , TARGET_STRING ( "simulink_model/Random Number" ) , TARGET_STRING (
"Seed" ) , 0 , 0 , 0 } , { 122 , TARGET_STRING ( "simulink_model/Saturation"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 123 , TARGET_STRING (
"simulink_model/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 124 , TARGET_STRING ( "simulink_model/Saturation1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 125 , TARGET_STRING (
"simulink_model/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 126 , TARGET_STRING ( "simulink_model/Saturation2" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 127 , TARGET_STRING (
"simulink_model/Saturation2" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 128 , TARGET_STRING ( "simulink_model/Saturation3" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 129 , TARGET_STRING (
"simulink_model/Saturation3" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 130 , TARGET_STRING ( "simulink_model/Acutator/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 131 , TARGET_STRING (
"simulink_model/Controller/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 132 , TARGET_STRING ( "simulink_model/Controller/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 133 , TARGET_STRING (
"simulink_model/Controller/Integrator" ) , TARGET_STRING ( "InitialCondition"
) , 0 , 0 , 0 } , { 134 , TARGET_STRING (
"simulink_model/Controller/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 135 , TARGET_STRING (
"simulink_model/Plant/Integrator" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 136 , TARGET_STRING ( "simulink_model/Plant/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
"simulink_model/Plant/Integrator10" ) , TARGET_STRING ( "InitialCondition" )
, 0 , 0 , 0 } , { 138 , TARGET_STRING ( "simulink_model/Plant/Integrator11" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 139 , TARGET_STRING
( "simulink_model/Plant/Integrator2" ) , TARGET_STRING ( "InitialCondition" )
, 0 , 0 , 0 } , { 140 , TARGET_STRING ( "simulink_model/Plant/Integrator3" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING
( "simulink_model/Plant/Integrator4" ) , TARGET_STRING ( "InitialCondition" )
, 0 , 0 , 0 } , { 142 , TARGET_STRING ( "simulink_model/Plant/Integrator5" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING
( "simulink_model/Plant/Integrator6" ) , TARGET_STRING ( "InitialCondition" )
, 0 , 0 , 0 } , { 144 , TARGET_STRING ( "simulink_model/Plant/Integrator6" )
, TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 145 ,
TARGET_STRING ( "simulink_model/Plant/Integrator6" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 146 , TARGET_STRING (
"simulink_model/Plant/Integrator7" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 147 , TARGET_STRING ( "simulink_model/Plant/Integrator8" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
"simulink_model/Plant/Integrator9" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 149 , TARGET_STRING (
"simulink_model/Controller/Phi PID/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 150 , TARGET_STRING (
"simulink_model/Controller/Phi PID/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 151 , TARGET_STRING (
"simulink_model/Controller/Psi' PID/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 152 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 153 , TARGET_STRING (
"simulink_model/Controller/Theta PID/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 154 , TARGET_STRING (
"simulink_model/Controller/Z PID/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 155 , TARGET_STRING (
"simulink_model/Controller/Z PID/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 156 , TARGET_STRING (
"simulink_model/Controller/Z PID/Integrator1" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 157 , TARGET_STRING (
"simulink_model/Controller/Z PID/Integrator1" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 158 , TARGET_STRING (
"simulink_model/Controller/Z PID/Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 159 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 161 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 162 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation1" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 163 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation1" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation2" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 165 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation2" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation3" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 167 , TARGET_STRING (
"simulink_model/Plant/Angular velocity and thrust equations/Saturation3" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 168 , TARGET_STRING (
"Ax" ) , 0 , 0 , 0 } , { 169 , TARGET_STRING ( "Ay" ) , 0 , 0 , 0 } , { 170 ,
TARGET_STRING ( "Az" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING ( "Ixx" ) , 0 ,
0 , 0 } , { 172 , TARGET_STRING ( "Iyy" ) , 0 , 0 , 0 } , { 173 ,
TARGET_STRING ( "Izz" ) , 0 , 0 , 0 } , { 174 , TARGET_STRING ( "Jr" ) , 0 ,
0 , 0 } , { 175 , TARGET_STRING ( "Phi_D" ) , 0 , 0 , 0 } , { 176 ,
TARGET_STRING ( "Phi_I" ) , 0 , 0 , 0 } , { 177 , TARGET_STRING ( "Phi_P" ) ,
0 , 0 , 0 } , { 178 , TARGET_STRING ( "Psi_dot_D" ) , 0 , 0 , 0 } , { 179 ,
TARGET_STRING ( "Psi_dot_I" ) , 0 , 0 , 0 } , { 180 , TARGET_STRING (
"Psi_dot_P" ) , 0 , 0 , 0 } , { 181 , TARGET_STRING ( "Theta_D" ) , 0 , 0 , 0
} , { 182 , TARGET_STRING ( "Theta_I" ) , 0 , 0 , 0 } , { 183 , TARGET_STRING
( "Theta_P" ) , 0 , 0 , 0 } , { 184 , TARGET_STRING ( "Z_D" ) , 0 , 0 , 0 } ,
{ 185 , TARGET_STRING ( "Z_I" ) , 0 , 0 , 0 } , { 186 , TARGET_STRING ( "Z_P"
) , 0 , 0 , 0 } , { 187 , TARGET_STRING ( "d" ) , 0 , 0 , 0 } , { 188 ,
TARGET_STRING ( "g" ) , 0 , 0 , 0 } , { 189 , TARGET_STRING ( "l" ) , 0 , 0 ,
0 } , { 190 , TARGET_STRING ( "m" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 ,
0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . cx434fb0ek , & rtB . b5qmw2w2an ,
& rtB . fqbabctd00 , & rtB . npzhihrtw4 , & rtB . dakxuanftu , & rtB .
ikle3qa1kc , & rtDW . dsug4vvosa . a4zusecje2 , & rtDW . h5vy20de5m .
a4zusecje2 , & rtDW . m1hymrzrx0 . a4zusecje2 , & rtDW . ouxv4le1ru .
a4zusecje2 , & rtB . iuicad1o5e , & rtDW . kfziacnvmc , & rtB . ptfymszom1 ,
& rtB . mr3bonhsk2 , & rtB . mizkhlpjef , & rtB . nmkvhgkd2p , & rtB .
ef1lv21ood , & rtB . l5fwabq3kt , & rtB . axppsfv11x , & rtB . nmiwadwpyh , &
rtB . oqhznzhmir , & rtB . dxphwwoqpi , & rtB . hatuktxq5n , & rtB .
ofk3gtywup , & rtB . mrycz1krbe , & rtB . d4xsowxqum , & rtB . hojc3htffq , &
rtB . pgqq0hod5c , & rtB . cfmho4ajea , & rtB . mb0qn1wsho , & rtB .
jvw1mdfihi , & rtB . nqywse5ut4 , & rtB . jbstlwmhap , & rtB . if1iz101fk , &
rtB . mpdf5tqidb , & rtB . mi1km3oyut , & rtB . oeyj5uhp3i , & rtB .
paa1m0mnsc , & rtDW . lkdtqr0oce , & rtB . acfxwsko33 , & rtB . bx3ajp1ok2 ,
& rtB . edpbkcvi15 , & rtB . nrriu35a3f , & rtB . mxr2jetlva , & rtB .
n1i0g2quyr , & rtB . cvk1wcfm3n , & rtB . hwgjqfxchd , & rtB . nk24qgc3td , &
rtB . olm4t4rcyo , & rtB . er2q4gcfwf , & rtB . bmgs2of0v4 , & rtB .
ogev4jucip , & rtB . h3px4j43ml , & rtB . nygvtqvltq , & rtB . idounap34d , &
rtB . g1n4mdep1v , & rtB . i2ji13hv35 , & rtB . al0xpzoz2z , & rtB .
nqcjokfxxg , & rtB . oyadxno0tg , & rtB . bfleczw4f3 , & rtB . dsztqe2vkx , &
rtB . idyjdp421i , & rtB . a1lifoil3y , & rtB . nxse5y1hxs , & rtB .
my2vvqja3k , & rtB . iavp3z1f0w , & rtB . dmnzfxvk0s , & rtB . heh3e0vd2n , &
rtB . mf32z31xd3 , & rtB . pwfs0cxkha , & rtB . h55bc35fac , & rtB .
nb1txnf124 , & rtB . moe2m40xs1 , & rtB . pca4x342k4 , & rtB . eercnseb5a , &
rtB . o5kecny1zt , & rtB . ov0ybomziy , & rtB . nq1h44zzd1 , & rtB .
cp03e3zuli , & rtB . jjeppmnf5s , & rtB . h0tyi3ahxq , & rtB . kvvhdsb4ap , &
rtB . fmkkt4a3af , & rtB . bstcht5uj5 , & rtB . pynedc5gep , & rtB .
auew1negjx , & rtB . gu2wqtcrpg , & rtB . iq5fixgwb0 , & rtB . lwnxwhawyc , &
rtB . ggwtgd1omn , & rtB . m212hqnj5y , & rtB . fgbngwqnd5 , & rtB .
cgknn01qbh , & rtB . amyrq22pmo , & rtB . gjyfhfbbrb , & rtB . mfnuqnf2if , &
rtB . cxqjgsd4x5 , & rtB . apfjfvxnbo , & rtB . nq0ycmxp1p , & rtB .
glruen4axf , & rtB . duonk1hgtb , & rtB . dolzgkocov , & rtB . jjvzfhgfci , &
rtB . ag311bmkkx , & rtB . hgu1yymjsw , & rtB . osoak53vuu , & rtB .
fo1hseqjoo , & rtB . ozrfmyckp0 , & rtB . o41kp2eiqn , & rtB . gxfy4s1rme , &
rtB . mc2mnuakhz , & rtB . gqx21pyhi1 , & rtB . ly5x5ptd5f , & rtP .
ALWAYSNEGATIVE_Value , & rtP . Constant1_Value , & rtP . Constant2_Value , &
rtP . Constant3_Value , & rtP . Constant4_Value , & rtP . RandomNumber_Mean ,
& rtP . RandomNumber_StdDev , & rtP . RandomNumber_Seed , & rtP .
Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP .
Saturation1_UpperSat , & rtP . Saturation1_LowerSat , & rtP .
Saturation2_UpperSat , & rtP . Saturation2_LowerSat , & rtP .
Saturation3_UpperSat , & rtP . Saturation3_LowerSat , & rtP .
Gain_Gain_of3jgnpx3n , & rtP . Gain_Gain , & rtP . Gain2_Gain , & rtP .
Integrator_IC_atrldbhoby , & rtP . Integrator1_IC_irkesqhxjc , & rtP .
Integrator_IC_i2vfa00yuw , & rtP . Integrator1_IC_jcknyc0a5u , & rtP .
Integrator10_IC , & rtP . Integrator11_IC , & rtP . Integrator2_IC_owzkbh1yyf
, & rtP . Integrator3_IC , & rtP . Integrator4_IC , & rtP . Integrator5_IC ,
& rtP . Integrator6_IC , & rtP . Integrator6_UpperSat , & rtP .
Integrator6_LowerSat , & rtP . Integrator7_IC , & rtP . Integrator8_IC , &
rtP . Integrator9_IC , & rtP . Integrator_IC_of2tsl4pem , & rtP .
Integrator1_IC_pvc43f4wjv , & rtP . Integrator_IC_ccb2sgg2ag , & rtP .
Integrator_IC_ba024q11w2 , & rtP . Integrator1_IC_i2bjhakqq4 , & rtP .
Integrator_IC , & rtP . Integrator1_IC , & rtP . Integrator1_UpperSat , & rtP
. Integrator1_LowerSat , & rtP . Integrator2_IC , & rtP .
Gain_Gain_fb0j4u0hjn , & rtP . Saturation_UpperSat_gzuimzge4h , & rtP .
Saturation_LowerSat_hxfynrebf2 , & rtP . Saturation1_UpperSat_lmk2qb1doa , &
rtP . Saturation1_LowerSat_cg1ign3p35 , & rtP .
Saturation2_UpperSat_frujop4uxv , & rtP . Saturation2_LowerSat_efiqybc0ah , &
rtP . Saturation3_UpperSat_na5k5rtqcg , & rtP .
Saturation3_LowerSat_cniur41mc3 , & rtP . Ax , & rtP . Ay , & rtP . Az , &
rtP . Ixx , & rtP . Iyy , & rtP . Izz , & rtP . Jr , & rtP . Phi_D , & rtP .
Phi_I , & rtP . Phi_P , & rtP . Psi_dot_D , & rtP . Psi_dot_I , & rtP .
Psi_dot_P , & rtP . Theta_D , & rtP . Theta_I , & rtP . Theta_P , & rtP . Z_D
, & rtP . Z_I , & rtP . Z_P , & rtP . d , & rtP . g , & rtP . l , & rtP . m ,
} ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.001 , 0.0 , 1.0 }
; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T ) 0
} , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 2 ] , ( int8_T ) 1 , ( uint8_T ) 0 } , { ( NULL ) , (
NULL ) , 3 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 114 , rtRootInputs , 0 , rtRootOutputs , 0 } , {
rtBlockParameters , 54 , rtModelParameters , 23 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2139584242U , 464569197U , 1281492073U ,
849087122U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * simulink_model_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void simulink_model_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void simulink_model_host_InitializeDataMapInfo (
simulink_model_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
