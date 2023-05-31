#include "simulink_model.h"
#include "rtwtypes.h"
#include "simulink_model_private.h"
#include "mwmathutil.h"
#include "rt_logging_mmi.h"
#include "simulink_model_capi.h"
#include "simulink_model_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "10.7 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define llmyy3vvli (-1)
#define ox0wtsf5t5 (-1)
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void oe5sivhttw ( cbogeonl3h * localDW ) { localDW -> my1gf01od4
= llmyy3vvli ; localDW -> a4zusecje2 = 0U ; } void fn2qzj3ivf ( cbogeonl3h *
localDW ) { localDW -> my1gf01od4 = llmyy3vvli ; } real_T
rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T hi ; uint32_T lo ; lo
= * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi ) { * u
= 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return ( real_T ) *
u * 4.6566128752457969E-10 ; } real_T rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T *
u ) { real_T si ; real_T sr ; real_T y ; do { sr = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void MdlInitialize ( void ) { real_T tmp ; int32_T r ;
int32_T t ; uint32_T tseed ; rtX . gvxadtagwl = rtP . Integrator3_IC ; rtX .
jly13lpslx = rtP . Integrator4_IC ; rtX . bz2jwqhlko = rtP . Integrator5_IC ;
rtX . e1wo5gexnz = rtP . Integrator8_IC ; rtX . nm2msxuufe = rtP .
Integrator7_IC ; rtX . ftfaoaja4y = rtP . Integrator6_IC ; rtX . mjj2cerpbm =
rtP . Integrator1_IC ; rtX . jr1rtvzctg = rtP . Integrator_IC ; rtX .
ek2ch4vurj = rtP . Integrator2_IC ; rtX . dk1omijay1 = rtP .
Integrator1_IC_irkesqhxjc ; rtX . hynfsl50fu = rtP . Integrator_IC_atrldbhoby
; rtX . jmxvtu0m2y = rtP . Integrator1_IC_pvc43f4wjv ; rtX . gt5wzenovv = rtP
. Integrator_IC_of2tsl4pem ; rtX . mrkdqe0eoh = rtP .
Integrator_IC_i2vfa00yuw ; rtX . cdkommuqrc = rtP . Integrator1_IC_i2bjhakqq4
; rtX . m554necusl = rtP . Integrator_IC_ba024q11w2 ; rtX . fk23ijwckh = rtP
. Integrator1_IC_jcknyc0a5u ; rtX . ms3hp32jr2 = rtP .
Integrator2_IC_owzkbh1yyf ; rtX . gx1liw1z0z = rtP . Integrator_IC_ccb2sgg2ag
; rtDW . kqp3jjg4co = ( rtInf ) ; rtDW . mwnsgljmku = ( rtInf ) ; rtX .
kds1emu2rh = rtP . Integrator9_IC ; rtX . nmtygsfoyt = rtP . Integrator11_IC
; rtX . bxpqdmdwpp = rtP . Integrator10_IC ; tmp = muDoubleScalarFloor ( rtP
. RandomNumber_Seed ) ; if ( muDoubleScalarIsNaN ( tmp ) ||
muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem
( tmp , 4.294967296E+9 ) ; } tseed = tmp < 0.0 ? ( uint32_T ) - ( int32_T ) (
uint32_T ) - tmp : ( uint32_T ) tmp ; r = ( int32_T ) ( tseed >> 16U ) ; t =
( int32_T ) ( tseed & 32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r <<
16U ) ) + ( uint32_T ) t ) << 16U ) + ( uint32_T ) t ) + ( uint32_T ) r ; if
( tseed < 1U ) { tseed = 1144108930U ; } else if ( tseed > 2147483646U ) {
tseed = 2147483646U ; } rtDW . btjmvwwnmg = tseed ; rtDW . h42oy3cyks =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . btjmvwwnmg ) * rtP .
RandomNumber_StdDev + rtP . RandomNumber_Mean ; rtDW . niqimejvuy =
ox0wtsf5t5 ; rtDW . kfziacnvmc = 0U ; oe5sivhttw ( & rtDW . dsug4vvosa ) ;
oe5sivhttw ( & rtDW . h5vy20de5m ) ; oe5sivhttw ( & rtDW . m1hymrzrx0 ) ;
oe5sivhttw ( & rtDW . ouxv4le1ru ) ; rtDW . f1iht1hiua = ox0wtsf5t5 ; rtDW .
lkdtqr0oce = 0U ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Phi" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "Phi" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"simulink_model/Plant" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ;
sdiLabelU subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU
sigName = sdiGetLabelFromChars ( "Phi" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. hxvxyhqwfc . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"0e49d880-a44b-4239-8d06-c8a6e7897d21" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . hxvxyhqwfc . AQHandles , hDT , & srcInfo ) ; if ( rtDW . hxvxyhqwfc .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . hxvxyhqwfc . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
hxvxyhqwfc . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . hxvxyhqwfc .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . hxvxyhqwfc . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . hxvxyhqwfc . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Theta" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "Theta" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"simulink_model/Plant" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ;
sdiLabelU subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU
sigName = sdiGetLabelFromChars ( "Theta" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 1 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. i21byq1hgv . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"114cf1f9-a63d-49ad-bfc9-77dff1c593d2" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . i21byq1hgv . AQHandles , hDT , & srcInfo ) ; if ( rtDW . i21byq1hgv .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . i21byq1hgv . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
i21byq1hgv . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . i21byq1hgv .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . i21byq1hgv . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . i21byq1hgv . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Psi" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "Psi" ) ; sdiLabelU propName = sdiGetLabelFromChars
( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "simulink_model/Plant"
) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Psi" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 2 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. nqm15m4wuk . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"aca2097e-d712-45bb-8f53-71be11c7b59f" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . nqm15m4wuk . AQHandles , hDT , & srcInfo ) ; if ( rtDW . nqm15m4wuk .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . nqm15m4wuk . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
nqm15m4wuk . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . nqm15m4wuk .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . nqm15m4wuk . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . nqm15m4wuk . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "X" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "X" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "simulink_model/Plant" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "X" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 3 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. pykudpzq5m . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"b2acd832-0281-4ecd-a718-391bdea626e2" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . pykudpzq5m . AQHandles , hDT , & srcInfo ) ; if ( rtDW . pykudpzq5m .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . pykudpzq5m . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
pykudpzq5m . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . pykudpzq5m .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . pykudpzq5m . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . pykudpzq5m . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Y" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "Y" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "simulink_model/Plant" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Y" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 4 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. n4yoasy2fq . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"4aa7ecc5-53ba-4041-892b-f3008a2d3989" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . n4yoasy2fq . AQHandles , hDT , & srcInfo ) ; if ( rtDW . n4yoasy2fq .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . n4yoasy2fq . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
n4yoasy2fq . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . n4yoasy2fq .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . n4yoasy2fq . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . n4yoasy2fq . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Z" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "Z" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "simulink_model/Plant" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Z" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 5 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. bwe3frmqyw . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"26d7c360-44ce-40e6-ad0e-381cb0e0139f" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . bwe3frmqyw . AQHandles , hDT , & srcInfo ) ; if ( rtDW . bwe3frmqyw .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . bwe3frmqyw . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
bwe3frmqyw . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bwe3frmqyw .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . bwe3frmqyw . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . bwe3frmqyw . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "simulink_model/Plant" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 6 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. kdewiatuma . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"ae7acbb6-6e41-435c-96b3-c2c47782dd12" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . kdewiatuma . AQHandles , hDT , & srcInfo ) ; if ( rtDW . kdewiatuma .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . kdewiatuma . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
kdewiatuma . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . kdewiatuma .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . kdewiatuma . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . kdewiatuma . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "simulink_model/Saturation"
) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. g3zcewv4mo . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"5f3704ce-0477-4444-960a-824d3e5030b4" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . g3zcewv4mo . AQHandles , hDT , & srcInfo ) ; if ( rtDW . g3zcewv4mo .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . g3zcewv4mo . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
g3zcewv4mo . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . g3zcewv4mo .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . g3zcewv4mo . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . g3zcewv4mo . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"simulink_model/Plant/Integrator9" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . nqcqcrisqu . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "fca0378f-f396-4002-8aae-b978a1a9a9c0" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . nqcqcrisqu . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . nqcqcrisqu . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . nqcqcrisqu . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . nqcqcrisqu .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . nqcqcrisqu . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
nqcqcrisqu . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
nqcqcrisqu . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T fzi2depjzz ; real_T im0atkftmt ; real_T
lastTime ; real_T * lastU ; rtB . nqywse5ut4 = rtX . gvxadtagwl ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . hxvxyhqwfc . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . hxvxyhqwfc . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . nqywse5ut4 + 0 ) ; } } } rtB .
jbstlwmhap = rtX . jly13lpslx ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if (
rtDW . i21byq1hgv . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . i21byq1hgv . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. jbstlwmhap + 0 ) ; } } } rtB . if1iz101fk = rtX . bz2jwqhlko ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . nqm15m4wuk . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . nqm15m4wuk . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . if1iz101fk + 0 ) ; } } } rtB .
oeyj5uhp3i = rtX . e1wo5gexnz ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if (
rtDW . pykudpzq5m . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . pykudpzq5m . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. oeyj5uhp3i + 0 ) ; } } } rtB . mi1km3oyut = rtX . nm2msxuufe ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . n4yoasy2fq . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . n4yoasy2fq . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . mi1km3oyut + 0 ) ; } } } if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtX . ftfaoaja4y >= rtP .
Integrator6_UpperSat ) { if ( rtX . ftfaoaja4y != rtP . Integrator6_UpperSat
) { rtX . ftfaoaja4y = rtP . Integrator6_UpperSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . cm1r3v42mo = 3
; } else if ( rtX . ftfaoaja4y <= rtP . Integrator6_LowerSat ) { if ( rtX .
ftfaoaja4y != rtP . Integrator6_LowerSat ) { rtX . ftfaoaja4y = rtP .
Integrator6_LowerSat ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; }
rtDW . cm1r3v42mo = 4 ; } else { if ( rtDW . cm1r3v42mo != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . cm1r3v42mo = 0
; } rtB . mpdf5tqidb = rtX . ftfaoaja4y ; } else { rtB . mpdf5tqidb = rtX .
ftfaoaja4y ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW .
bwe3frmqyw . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
bwe3frmqyw . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB .
mpdf5tqidb + 0 ) ; } } } fzi2depjzz = muDoubleScalarCos ( rtB . nqywse5ut4 )
; im0atkftmt = muDoubleScalarCos ( rtB . jbstlwmhap ) ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtX . mjj2cerpbm >= rtP .
Integrator1_UpperSat ) { if ( rtX . mjj2cerpbm != rtP . Integrator1_UpperSat
) { rtX . mjj2cerpbm = rtP . Integrator1_UpperSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . avhpt1ir2w = 3
; } else if ( rtX . mjj2cerpbm <= rtP . Integrator1_LowerSat ) { if ( rtX .
mjj2cerpbm != rtP . Integrator1_LowerSat ) { rtX . mjj2cerpbm = rtP .
Integrator1_LowerSat ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; }
rtDW . avhpt1ir2w = 4 ; } else { if ( rtDW . avhpt1ir2w != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . avhpt1ir2w = 0
; } rtB . nxse5y1hxs = rtX . mjj2cerpbm ; } else { rtB . nxse5y1hxs = rtX .
mjj2cerpbm ; } rtB . iavp3z1f0w = rtP . ALWAYSNEGATIVE_Value - rtB .
nxse5y1hxs ; rtB . bfleczw4f3 = rtP . Z_P * rtB . iavp3z1f0w ; rtB .
a1lifoil3y = rtX . jr1rtvzctg ; rtB . dsztqe2vkx = rtP . Z_I * rtB .
a1lifoil3y ; rtB . my2vvqja3k = rtX . ek2ch4vurj ; rtB . idyjdp421i = rtP .
Z_D * rtB . my2vvqja3k ; rtB . dmnzfxvk0s = ( rtB . bfleczw4f3 + rtB .
dsztqe2vkx ) - rtB . idyjdp421i ; rtB . nmkvhgkd2p = rtX . dk1omijay1 ; rtB .
mizkhlpjef = rtX . hynfsl50fu ; rtB . dxphwwoqpi = muDoubleScalarCos ( rtB .
nmkvhgkd2p ) * muDoubleScalarCos ( rtB . mizkhlpjef ) ; rtB . ef1lv21ood =
rtB . dmnzfxvk0s / rtB . dxphwwoqpi ; rtB . oqhznzhmir = rtB . ef1lv21ood /
rtB . mr3bonhsk2 ; rtB . mxr2jetlva = rtX . jmxvtu0m2y ; rtB . n1i0g2quyr =
rtP . Constant1_Value - rtB . mxr2jetlva ; rtB . acfxwsko33 = rtP . Phi_P *
rtB . n1i0g2quyr ; rtB . nrriu35a3f = rtX . gt5wzenovv ; rtB . bx3ajp1ok2 =
rtP . Phi_I * rtB . nrriu35a3f ; rtB . hojc3htffq = rtX . mrkdqe0eoh ; rtB .
edpbkcvi15 = rtP . Phi_D * rtB . hojc3htffq ; rtB . cvk1wcfm3n = ( rtB .
acfxwsko33 + rtB . bx3ajp1ok2 ) - rtB . edpbkcvi15 ; rtB . nmiwadwpyh = rtB .
cvk1wcfm3n / rtB . ptfymszom1 ; rtB . al0xpzoz2z = rtX . cdkommuqrc ; rtB .
nqcjokfxxg = rtP . Constant2_Value - rtB . al0xpzoz2z ; rtB . nygvtqvltq =
rtP . Theta_P * rtB . nqcjokfxxg ; rtB . i2ji13hv35 = rtX . m554necusl ; rtB
. idounap34d = rtP . Theta_I * rtB . i2ji13hv35 ; rtB . pgqq0hod5c = rtX .
fk23ijwckh ; rtB . g1n4mdep1v = rtP . Theta_D * rtB . pgqq0hod5c ; rtB .
oyadxno0tg = ( rtB . nygvtqvltq + rtB . idounap34d ) - rtB . g1n4mdep1v ; rtB
. axppsfv11x = rtB . oyadxno0tg / rtB . ptfymszom1 ; rtB . jvw1mdfihi = rtX .
ms3hp32jr2 ; rtB . ogev4jucip = rtP . Constant3_Value - rtB . jvw1mdfihi ;
rtB . nk24qgc3td = rtP . Psi_dot_P * rtB . ogev4jucip ; rtB . bmgs2of0v4 =
rtX . gx1liw1z0z ; rtB . olm4t4rcyo = rtP . Psi_dot_I * rtB . bmgs2of0v4 ; if
( ( rtDW . kqp3jjg4co >= ssGetT ( rtS ) ) && ( rtDW . mwnsgljmku >= ssGetT (
rtS ) ) ) { rtB . hwgjqfxchd = 0.0 ; } else { lastTime = rtDW . kqp3jjg4co ;
lastU = & rtDW . hlguwifben ; if ( rtDW . kqp3jjg4co < rtDW . mwnsgljmku ) {
if ( rtDW . mwnsgljmku < ssGetT ( rtS ) ) { lastTime = rtDW . mwnsgljmku ;
lastU = & rtDW . olbnwgatth ; } } else if ( rtDW . kqp3jjg4co >= ssGetT ( rtS
) ) { lastTime = rtDW . mwnsgljmku ; lastU = & rtDW . olbnwgatth ; } rtB .
hwgjqfxchd = ( rtB . ogev4jucip - * lastU ) / ( ssGetT ( rtS ) - lastTime ) ;
} rtB . er2q4gcfwf = rtP . Psi_dot_D * rtB . hwgjqfxchd ; rtB . h3px4j43ml =
( rtB . nk24qgc3td + rtB . olm4t4rcyo ) + rtB . er2q4gcfwf ; rtB . l5fwabq3kt
= rtB . h3px4j43ml / ( 4.0 * rtP . d ) ; rtB . hatuktxq5n = ( ( rtB .
oqhznzhmir + rtB . nmiwadwpyh ) + rtB . axppsfv11x ) + rtB . l5fwabq3kt ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . djssvv0v25 = rtB . hatuktxq5n >=
rtP . Saturation_UpperSat ? 1 : rtB . hatuktxq5n > rtP . Saturation_LowerSat
? 0 : - 1 ; } rtB . b5qmw2w2an = rtDW . djssvv0v25 == 1 ? rtP .
Saturation_UpperSat : rtDW . djssvv0v25 == - 1 ? rtP . Saturation_LowerSat :
rtB . hatuktxq5n ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . a2x5ne2yuh
= rtB . b5qmw2w2an >= rtP . Saturation_UpperSat_gzuimzge4h ? 1 : rtB .
b5qmw2w2an > rtP . Saturation_LowerSat_hxfynrebf2 ? 0 : - 1 ; } rtB .
moe2m40xs1 = rtDW . a2x5ne2yuh == 1 ? rtP . Saturation_UpperSat_gzuimzge4h :
rtDW . a2x5ne2yuh == - 1 ? rtP . Saturation_LowerSat_hxfynrebf2 : rtB .
b5qmw2w2an ; rtB . ofk3gtywup = ( ( rtB . oqhznzhmir - rtB . nmiwadwpyh ) +
rtB . axppsfv11x ) - rtB . l5fwabq3kt ; if ( ssIsModeUpdateTimeStep ( rtS ) )
{ rtDW . hxtyjdui5q = rtB . ofk3gtywup >= rtP . Saturation1_UpperSat ? 1 :
rtB . ofk3gtywup > rtP . Saturation1_LowerSat ? 0 : - 1 ; } rtB . fqbabctd00
= rtDW . hxtyjdui5q == 1 ? rtP . Saturation1_UpperSat : rtDW . hxtyjdui5q ==
- 1 ? rtP . Saturation1_LowerSat : rtB . ofk3gtywup ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . jnd3boi5ry = rtB . fqbabctd00 >=
rtP . Saturation1_UpperSat_lmk2qb1doa ? 1 : rtB . fqbabctd00 > rtP .
Saturation1_LowerSat_cg1ign3p35 ? 0 : - 1 ; } rtB . pca4x342k4 = rtDW .
jnd3boi5ry == 1 ? rtP . Saturation1_UpperSat_lmk2qb1doa : rtDW . jnd3boi5ry
== - 1 ? rtP . Saturation1_LowerSat_cg1ign3p35 : rtB . fqbabctd00 ; rtB .
mrycz1krbe = ( ( rtB . oqhznzhmir - rtB . nmiwadwpyh ) - rtB . axppsfv11x ) +
rtB . l5fwabq3kt ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . mylxuoshim
= rtB . mrycz1krbe >= rtP . Saturation2_UpperSat ? 1 : rtB . mrycz1krbe > rtP
. Saturation2_LowerSat ? 0 : - 1 ; } rtB . npzhihrtw4 = rtDW . mylxuoshim ==
1 ? rtP . Saturation2_UpperSat : rtDW . mylxuoshim == - 1 ? rtP .
Saturation2_LowerSat : rtB . mrycz1krbe ; if ( ssIsModeUpdateTimeStep ( rtS )
) { rtDW . nsk1euskhj = rtB . npzhihrtw4 >= rtP .
Saturation2_UpperSat_frujop4uxv ? 1 : rtB . npzhihrtw4 > rtP .
Saturation2_LowerSat_efiqybc0ah ? 0 : - 1 ; } rtB . eercnseb5a = rtDW .
nsk1euskhj == 1 ? rtP . Saturation2_UpperSat_frujop4uxv : rtDW . nsk1euskhj
== - 1 ? rtP . Saturation2_LowerSat_efiqybc0ah : rtB . npzhihrtw4 ; rtB .
d4xsowxqum = ( ( rtB . oqhznzhmir + rtB . nmiwadwpyh ) - rtB . axppsfv11x ) -
rtB . l5fwabq3kt ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . lh5pqvixkq
= rtB . d4xsowxqum >= rtP . Saturation3_UpperSat ? 1 : rtB . d4xsowxqum > rtP
. Saturation3_LowerSat ? 0 : - 1 ; } rtB . dakxuanftu = rtDW . lh5pqvixkq ==
1 ? rtP . Saturation3_UpperSat : rtDW . lh5pqvixkq == - 1 ? rtP .
Saturation3_LowerSat : rtB . d4xsowxqum ; if ( ssIsModeUpdateTimeStep ( rtS )
) { rtDW . oo2z0xqarv = rtB . dakxuanftu >= rtP .
Saturation3_UpperSat_na5k5rtqcg ? 1 : rtB . dakxuanftu > rtP .
Saturation3_LowerSat_cniur41mc3 ? 0 : - 1 ; } rtB . o5kecny1zt = rtDW .
oo2z0xqarv == 1 ? rtP . Saturation3_UpperSat_na5k5rtqcg : rtDW . oo2z0xqarv
== - 1 ? rtP . Saturation3_LowerSat_cniur41mc3 : rtB . dakxuanftu ; rtB .
nq1h44zzd1 = ( ( rtB . moe2m40xs1 + rtB . pca4x342k4 ) + rtB . eercnseb5a ) +
rtB . o5kecny1zt ; rtB . mf32z31xd3 = rtP . Constant4_Value * rtB .
nq1h44zzd1 ; rtB . gqx21pyhi1 = fzi2depjzz * im0atkftmt * rtB . mf32z31xd3 ;
rtB . paa1m0mnsc = rtX . kds1emu2rh ; rtB . gxfy4s1rme = rtB . paa1m0mnsc *
rtP . Az ; rtB . ly5x5ptd5f = ( rtB . mc2mnuakhz - rtB . gqx21pyhi1 ) - rtB .
gxfy4s1rme ; rtB . o41kp2eiqn = rtB . ly5x5ptd5f / rtP . m ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . kdewiatuma . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . kdewiatuma . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . o41kp2eiqn + 0 ) ; } } { if (
rtDW . g3zcewv4mo . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . g3zcewv4mo . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. b5qmw2w2an + 0 ) ; } } rtDW . niqimejvuy = ox0wtsf5t5 ; { if ( rtDW .
nqcqcrisqu . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
nqcqcrisqu . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB .
paa1m0mnsc + 0 ) ; } } } rtB . cp03e3zuli = ( ( rtB . moe2m40xs1 - rtB .
pca4x342k4 ) - rtB . eercnseb5a ) + rtB . o5kecny1zt ; rtB . pwfs0cxkha = rtB
. heh3e0vd2n * rtB . cp03e3zuli ; rtB . fmkkt4a3af = rtP . l * rtB .
pwfs0cxkha ; rtB . ov0ybomziy = ( ( rtB . eercnseb5a - rtB . o5kecny1zt ) -
rtB . pca4x342k4 ) + rtB . moe2m40xs1 ; rtB . bstcht5uj5 = rtP . Jr * rtB .
ov0ybomziy * rtB . pgqq0hod5c ; rtB . pynedc5gep = rtB . pgqq0hod5c * rtB .
jvw1mdfihi * ( rtP . Iyy - rtP . Izz ) ; rtB . auew1negjx = ( rtB .
fmkkt4a3af + rtB . bstcht5uj5 ) + rtB . pynedc5gep ; rtB . kvvhdsb4ap = rtB .
auew1negjx / rtP . Ixx ; rtB . jjeppmnf5s = ( ( rtB . moe2m40xs1 + rtB .
pca4x342k4 ) - rtB . eercnseb5a ) - rtB . o5kecny1zt ; rtB . h55bc35fac = rtB
. heh3e0vd2n * rtB . jjeppmnf5s ; rtB . iq5fixgwb0 = rtP . l * rtB .
h55bc35fac ; rtB . lwnxwhawyc = rtP . Jr * rtB . ov0ybomziy * rtB .
hojc3htffq ; rtB . ggwtgd1omn = rtB . hojc3htffq * rtB . jvw1mdfihi * ( rtP .
Izz - rtP . Ixx ) ; rtB . m212hqnj5y = ( rtB . iq5fixgwb0 - rtB . lwnxwhawyc
) + rtB . ggwtgd1omn ; rtB . gu2wqtcrpg = rtB . m212hqnj5y / rtP . Iyy ; rtB
. h0tyi3ahxq = ( ( rtB . moe2m40xs1 - rtB . pca4x342k4 ) + rtB . eercnseb5a )
- rtB . o5kecny1zt ; rtB . nb1txnf124 = rtB . h0tyi3ahxq * rtP . d ; rtB .
cgknn01qbh = rtB . pgqq0hod5c * rtB . hojc3htffq * ( rtP . Ixx - rtP . Iyy )
; rtB . amyrq22pmo = rtB . nb1txnf124 + rtB . cgknn01qbh ; rtB . fgbngwqnd5 =
rtB . amyrq22pmo / rtP . Izz ; rtB . apfjfvxnbo = muDoubleScalarSin ( rtB .
nqywse5ut4 ) * muDoubleScalarSin ( rtB . if1iz101fk ) ; rtB . nq0ycmxp1p =
muDoubleScalarCos ( rtB . nqywse5ut4 ) * muDoubleScalarCos ( rtB . if1iz101fk
) * muDoubleScalarSin ( rtB . jbstlwmhap ) ; rtB . duonk1hgtb = rtB .
apfjfvxnbo - rtB . nq0ycmxp1p ; rtB . cxqjgsd4x5 = rtB . mf32z31xd3 * rtB .
duonk1hgtb ; rtB . mb0qn1wsho = rtX . nmtygsfoyt ; rtB . mfnuqnf2if = rtB .
mb0qn1wsho * rtP . Ax ; rtB . glruen4axf = rtB . cxqjgsd4x5 - rtB .
mfnuqnf2if ; rtB . gjyfhfbbrb = rtB . glruen4axf / rtP . m ; rtB . hgu1yymjsw
= muDoubleScalarSin ( rtB . nqywse5ut4 ) * muDoubleScalarCos ( rtB .
if1iz101fk ) ; rtB . osoak53vuu = muDoubleScalarCos ( rtB . nqywse5ut4 ) *
muDoubleScalarSin ( rtB . if1iz101fk ) * muDoubleScalarSin ( rtB . jbstlwmhap
) ; rtB . ozrfmyckp0 = rtB . hgu1yymjsw + rtB . osoak53vuu ; rtB . ag311bmkkx
= rtB . mf32z31xd3 * rtB . ozrfmyckp0 ; rtB . cfmho4ajea = rtX . bxpqdmdwpp ;
rtB . jjvzfhgfci = rtB . cfmho4ajea * rtP . Ay ; rtB . fo1hseqjoo = rtB .
ag311bmkkx - rtB . jjvzfhgfci ; rtB . dolzgkocov = rtB . fo1hseqjoo / rtP . m
; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . cx434fb0ek = rtDW . h42oy3cyks
; } rtB . ikle3qa1kc = rtB . o41kp2eiqn + rtB . cx434fb0ek ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { fn2qzj3ivf ( & rtDW . dsug4vvosa ) ;
fn2qzj3ivf ( & rtDW . h5vy20de5m ) ; fn2qzj3ivf ( & rtDW . m1hymrzrx0 ) ;
fn2qzj3ivf ( & rtDW . ouxv4le1ru ) ; rtDW . f1iht1hiua = ox0wtsf5t5 ; }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID3 ( int_T tid ) { real_T
aznhbkg3hi ; aznhbkg3hi = rtP . Gain_Gain * rtP . Constant4_Value ; rtB .
ptfymszom1 = 0.70710678118654746 * rtP . l * aznhbkg3hi ; rtB . mr3bonhsk2 =
rtP . Gain2_Gain * aznhbkg3hi ; rtB . heh3e0vd2n = rtP . Gain_Gain_fb0j4u0hjn
* rtP . Constant4_Value ; rtB . mc2mnuakhz = rtP . m * rtP . g ; rtB .
iuicad1o5e = rtP . Gain_Gain_of3jgnpx3n * 0.0 ; UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { XDis * _rtXdis ; real_T * lastU ; _rtXdis = (
( XDis * ) ssGetContStateDisabled ( rtS ) ) ; switch ( rtDW . cm1r3v42mo ) {
case 3 : if ( rtB . paa1m0mnsc < 0.0 ) { rtDW . cm1r3v42mo = 1 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; case 4 : if (
rtB . paa1m0mnsc > 0.0 ) { rtDW . cm1r3v42mo = 2 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; } _rtXdis ->
ftfaoaja4y = ( ( rtDW . cm1r3v42mo == 3 ) || ( rtDW . cm1r3v42mo == 4 ) ) ;
switch ( rtDW . avhpt1ir2w ) { case 3 : if ( rtB . my2vvqja3k < 0.0 ) { rtDW
. avhpt1ir2w = 1 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; }
break ; case 4 : if ( rtB . my2vvqja3k > 0.0 ) { rtDW . avhpt1ir2w = 2 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; } _rtXdis ->
mjj2cerpbm = ( ( rtDW . avhpt1ir2w == 3 ) || ( rtDW . avhpt1ir2w == 4 ) ) ;
if ( rtDW . kqp3jjg4co == ( rtInf ) ) { rtDW . kqp3jjg4co = ssGetT ( rtS ) ;
lastU = & rtDW . hlguwifben ; } else if ( rtDW . mwnsgljmku == ( rtInf ) ) {
rtDW . mwnsgljmku = ssGetT ( rtS ) ; lastU = & rtDW . olbnwgatth ; } else if
( rtDW . kqp3jjg4co < rtDW . mwnsgljmku ) { rtDW . kqp3jjg4co = ssGetT ( rtS
) ; lastU = & rtDW . hlguwifben ; } else { rtDW . mwnsgljmku = ssGetT ( rtS )
; lastU = & rtDW . olbnwgatth ; } * lastU = rtB . ogev4jucip ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . h42oy3cyks =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . btjmvwwnmg ) * rtP .
RandomNumber_StdDev + rtP . RandomNumber_Mean ; } UNUSED_PARAMETER ( tid ) ;
} void MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDis * _rtXdis ; XDot * _rtXdot ; _rtXdis = ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> gvxadtagwl = rtB . hojc3htffq ; _rtXdot -> jly13lpslx =
rtB . pgqq0hod5c ; _rtXdot -> bz2jwqhlko = rtB . jvw1mdfihi ; _rtXdot ->
e1wo5gexnz = rtB . mb0qn1wsho ; _rtXdot -> nm2msxuufe = rtB . cfmho4ajea ; if
( _rtXdis -> ftfaoaja4y ) { _rtXdot -> ftfaoaja4y = 0.0 ; } else { _rtXdot ->
ftfaoaja4y = rtB . paa1m0mnsc ; } if ( _rtXdis -> mjj2cerpbm ) { _rtXdot ->
mjj2cerpbm = 0.0 ; } else { _rtXdot -> mjj2cerpbm = rtB . my2vvqja3k ; }
_rtXdot -> jr1rtvzctg = rtB . iavp3z1f0w ; _rtXdot -> ek2ch4vurj = rtB .
ikle3qa1kc ; _rtXdot -> dk1omijay1 = rtB . hojc3htffq ; _rtXdot -> hynfsl50fu
= rtB . pgqq0hod5c ; _rtXdot -> jmxvtu0m2y = rtB . hojc3htffq ; _rtXdot ->
gt5wzenovv = rtB . n1i0g2quyr ; _rtXdot -> mrkdqe0eoh = rtB . kvvhdsb4ap ;
_rtXdot -> cdkommuqrc = rtB . pgqq0hod5c ; _rtXdot -> m554necusl = rtB .
nqcjokfxxg ; _rtXdot -> fk23ijwckh = rtB . gu2wqtcrpg ; _rtXdot -> ms3hp32jr2
= rtB . fgbngwqnd5 ; _rtXdot -> gx1liw1z0z = rtB . ogev4jucip ; _rtXdot ->
kds1emu2rh = rtB . o41kp2eiqn ; _rtXdot -> nmtygsfoyt = rtB . gjyfhfbbrb ;
_rtXdot -> bxpqdmdwpp = rtB . dolzgkocov ; } void MdlProjection ( void ) { }
void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; switch ( rtDW . cm1r3v42mo ) { case 1 :
_rtZCSV -> ou3qy5fi14 = 0.0 ; _rtZCSV -> b4ut14lxda = rtP .
Integrator6_UpperSat - rtP . Integrator6_LowerSat ; break ; case 2 : _rtZCSV
-> ou3qy5fi14 = rtP . Integrator6_LowerSat - rtP . Integrator6_UpperSat ;
_rtZCSV -> b4ut14lxda = 0.0 ; break ; default : _rtZCSV -> ou3qy5fi14 = rtX .
ftfaoaja4y - rtP . Integrator6_UpperSat ; _rtZCSV -> b4ut14lxda = rtX .
ftfaoaja4y - rtP . Integrator6_LowerSat ; break ; } if ( ( rtDW . cm1r3v42mo
== 3 ) || ( rtDW . cm1r3v42mo == 4 ) ) { _rtZCSV -> g44iucpq23 = rtB .
paa1m0mnsc ; } else { _rtZCSV -> g44iucpq23 = 0.0 ; } switch ( rtDW .
avhpt1ir2w ) { case 1 : _rtZCSV -> pizvrw23lj = 0.0 ; _rtZCSV -> cv1srbrtef =
rtP . Integrator1_UpperSat - rtP . Integrator1_LowerSat ; break ; case 2 :
_rtZCSV -> pizvrw23lj = rtP . Integrator1_LowerSat - rtP .
Integrator1_UpperSat ; _rtZCSV -> cv1srbrtef = 0.0 ; break ; default :
_rtZCSV -> pizvrw23lj = rtX . mjj2cerpbm - rtP . Integrator1_UpperSat ;
_rtZCSV -> cv1srbrtef = rtX . mjj2cerpbm - rtP . Integrator1_LowerSat ; break
; } if ( ( rtDW . avhpt1ir2w == 3 ) || ( rtDW . avhpt1ir2w == 4 ) ) { _rtZCSV
-> hk0ikpoypi = rtB . my2vvqja3k ; } else { _rtZCSV -> hk0ikpoypi = 0.0 ; }
_rtZCSV -> echid3gkwp = rtB . hatuktxq5n - rtP . Saturation_UpperSat ;
_rtZCSV -> islikvvzx5 = rtB . hatuktxq5n - rtP . Saturation_LowerSat ;
_rtZCSV -> grn5kwyacq = rtB . b5qmw2w2an - rtP .
Saturation_UpperSat_gzuimzge4h ; _rtZCSV -> fpkdsw13sc = rtB . b5qmw2w2an -
rtP . Saturation_LowerSat_hxfynrebf2 ; _rtZCSV -> hbkkastf5m = rtB .
ofk3gtywup - rtP . Saturation1_UpperSat ; _rtZCSV -> eql42dn21o = rtB .
ofk3gtywup - rtP . Saturation1_LowerSat ; _rtZCSV -> nmusc4quyi = rtB .
fqbabctd00 - rtP . Saturation1_UpperSat_lmk2qb1doa ; _rtZCSV -> o4yledqaiy =
rtB . fqbabctd00 - rtP . Saturation1_LowerSat_cg1ign3p35 ; _rtZCSV ->
il54w1vatn = rtB . mrycz1krbe - rtP . Saturation2_UpperSat ; _rtZCSV ->
gkzxzmemuh = rtB . mrycz1krbe - rtP . Saturation2_LowerSat ; _rtZCSV ->
awgnovmp4t = rtB . npzhihrtw4 - rtP . Saturation2_UpperSat_frujop4uxv ;
_rtZCSV -> ev0ofnghc2 = rtB . npzhihrtw4 - rtP .
Saturation2_LowerSat_efiqybc0ah ; _rtZCSV -> jxkfe23gc0 = rtB . d4xsowxqum -
rtP . Saturation3_UpperSat ; _rtZCSV -> ewst3nqtts = rtB . d4xsowxqum - rtP .
Saturation3_LowerSat ; _rtZCSV -> kp5qtzaivg = rtB . dakxuanftu - rtP .
Saturation3_UpperSat_na5k5rtqcg ; _rtZCSV -> mkkixitadk = rtB . dakxuanftu -
rtP . Saturation3_LowerSat_cniur41mc3 ; } void MdlTerminate ( void ) { { if (
rtDW . hxvxyhqwfc . AQHandles ) { sdiTerminateStreaming ( & rtDW . hxvxyhqwfc
. AQHandles ) ; } } { if ( rtDW . i21byq1hgv . AQHandles ) {
sdiTerminateStreaming ( & rtDW . i21byq1hgv . AQHandles ) ; } } { if ( rtDW .
nqm15m4wuk . AQHandles ) { sdiTerminateStreaming ( & rtDW . nqm15m4wuk .
AQHandles ) ; } } { if ( rtDW . pykudpzq5m . AQHandles ) {
sdiTerminateStreaming ( & rtDW . pykudpzq5m . AQHandles ) ; } } { if ( rtDW .
n4yoasy2fq . AQHandles ) { sdiTerminateStreaming ( & rtDW . n4yoasy2fq .
AQHandles ) ; } } { if ( rtDW . bwe3frmqyw . AQHandles ) {
sdiTerminateStreaming ( & rtDW . bwe3frmqyw . AQHandles ) ; } } { if ( rtDW .
kdewiatuma . AQHandles ) { sdiTerminateStreaming ( & rtDW . kdewiatuma .
AQHandles ) ; } } { if ( rtDW . g3zcewv4mo . AQHandles ) {
sdiTerminateStreaming ( & rtDW . g3zcewv4mo . AQHandles ) ; } } { if ( rtDW .
nqcqcrisqu . AQHandles ) { sdiTerminateStreaming ( & rtDW . nqcqcrisqu .
AQHandles ) ; } } } static void mr_simulink_model_cacheDataAsMxArray (
mxArray * destArray , mwIndex i , int j , const void * srcData , size_t
numBytes ) ; static void mr_simulink_model_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) {
mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_simulink_model_restoreDataFromMxArray (
void * destData , const mxArray * srcArray , mwIndex i , int j , size_t
numBytes ) ; static void mr_simulink_model_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) {
memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void
mr_simulink_model_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void
mr_simulink_model_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_simulink_model_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_simulink_model_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_simulink_model_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_simulink_model_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_simulink_model_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_simulink_model_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_simulink_model_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void mr_simulink_model_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_simulink_model_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_simulink_model_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_simulink_model_GetDWork ( ) { static
const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ;
mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_simulink_model_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & (
rtB ) , sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 34 ]
= { "rtDW.kqp3jjg4co" , "rtDW.hlguwifben" , "rtDW.mwnsgljmku" ,
"rtDW.olbnwgatth" , "rtDW.h42oy3cyks" , "rtDW.niqimejvuy" , "rtDW.f1iht1hiua"
, "rtDW.btjmvwwnmg" , "rtDW.cm1r3v42mo" , "rtDW.avhpt1ir2w" ,
"rtDW.djssvv0v25" , "rtDW.a2x5ne2yuh" , "rtDW.hxtyjdui5q" , "rtDW.jnd3boi5ry"
, "rtDW.mylxuoshim" , "rtDW.nsk1euskhj" , "rtDW.lh5pqvixkq" ,
"rtDW.oo2z0xqarv" , "rtDW.kfziacnvmc" , "rtDW.lkdtqr0oce" , "rtDW.kfnv5bckyc"
, "rtDW.axq5whh23g" , "rtDW.ouxv4le1ru.my1gf01od4" ,
"rtDW.ouxv4le1ru.a4zusecje2" , "rtDW.ouxv4le1ru.hfwirb0gp3" ,
"rtDW.m1hymrzrx0.my1gf01od4" , "rtDW.m1hymrzrx0.a4zusecje2" ,
"rtDW.m1hymrzrx0.hfwirb0gp3" , "rtDW.h5vy20de5m.my1gf01od4" ,
"rtDW.h5vy20de5m.a4zusecje2" , "rtDW.h5vy20de5m.hfwirb0gp3" ,
"rtDW.dsug4vvosa.my1gf01od4" , "rtDW.dsug4vvosa.a4zusecje2" ,
"rtDW.dsug4vvosa.hfwirb0gp3" , } ; mxArray * rtdwData = mxCreateStructMatrix
( 1 , 1 , 34 , rtdwDataFieldNames ) ; mr_simulink_model_cacheDataAsMxArray (
rtdwData , 0 , 0 , ( const void * ) & ( rtDW . kqp3jjg4co ) , sizeof ( rtDW .
kqp3jjg4co ) ) ; mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 1 , (
const void * ) & ( rtDW . hlguwifben ) , sizeof ( rtDW . hlguwifben ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) &
( rtDW . mwnsgljmku ) , sizeof ( rtDW . mwnsgljmku ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) &
( rtDW . olbnwgatth ) , sizeof ( rtDW . olbnwgatth ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) &
( rtDW . h42oy3cyks ) , sizeof ( rtDW . h42oy3cyks ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) &
( rtDW . niqimejvuy ) , sizeof ( rtDW . niqimejvuy ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) &
( rtDW . f1iht1hiua ) , sizeof ( rtDW . f1iht1hiua ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) &
( rtDW . btjmvwwnmg ) , sizeof ( rtDW . btjmvwwnmg ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) &
( rtDW . cm1r3v42mo ) , sizeof ( rtDW . cm1r3v42mo ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) &
( rtDW . avhpt1ir2w ) , sizeof ( rtDW . avhpt1ir2w ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) &
( rtDW . djssvv0v25 ) , sizeof ( rtDW . djssvv0v25 ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) &
( rtDW . a2x5ne2yuh ) , sizeof ( rtDW . a2x5ne2yuh ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) &
( rtDW . hxtyjdui5q ) , sizeof ( rtDW . hxtyjdui5q ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) &
( rtDW . jnd3boi5ry ) , sizeof ( rtDW . jnd3boi5ry ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) &
( rtDW . mylxuoshim ) , sizeof ( rtDW . mylxuoshim ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) &
( rtDW . nsk1euskhj ) , sizeof ( rtDW . nsk1euskhj ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) &
( rtDW . lh5pqvixkq ) , sizeof ( rtDW . lh5pqvixkq ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) &
( rtDW . oo2z0xqarv ) , sizeof ( rtDW . oo2z0xqarv ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) &
( rtDW . kfziacnvmc ) , sizeof ( rtDW . kfziacnvmc ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) &
( rtDW . lkdtqr0oce ) , sizeof ( rtDW . lkdtqr0oce ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) &
( rtDW . kfnv5bckyc ) , sizeof ( rtDW . kfnv5bckyc ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) &
( rtDW . axq5whh23g ) , sizeof ( rtDW . axq5whh23g ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) &
( rtDW . ouxv4le1ru . my1gf01od4 ) , sizeof ( rtDW . ouxv4le1ru . my1gf01od4
) ) ; mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void
* ) & ( rtDW . ouxv4le1ru . a4zusecje2 ) , sizeof ( rtDW . ouxv4le1ru .
a4zusecje2 ) ) ; mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 24 , (
const void * ) & ( rtDW . ouxv4le1ru . hfwirb0gp3 ) , sizeof ( rtDW .
ouxv4le1ru . hfwirb0gp3 ) ) ; mr_simulink_model_cacheDataAsMxArray ( rtdwData
, 0 , 25 , ( const void * ) & ( rtDW . m1hymrzrx0 . my1gf01od4 ) , sizeof (
rtDW . m1hymrzrx0 . my1gf01od4 ) ) ; mr_simulink_model_cacheDataAsMxArray (
rtdwData , 0 , 26 , ( const void * ) & ( rtDW . m1hymrzrx0 . a4zusecje2 ) ,
sizeof ( rtDW . m1hymrzrx0 . a4zusecje2 ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) &
( rtDW . m1hymrzrx0 . hfwirb0gp3 ) , sizeof ( rtDW . m1hymrzrx0 . hfwirb0gp3
) ) ; mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void
* ) & ( rtDW . h5vy20de5m . my1gf01od4 ) , sizeof ( rtDW . h5vy20de5m .
my1gf01od4 ) ) ; mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 29 , (
const void * ) & ( rtDW . h5vy20de5m . a4zusecje2 ) , sizeof ( rtDW .
h5vy20de5m . a4zusecje2 ) ) ; mr_simulink_model_cacheDataAsMxArray ( rtdwData
, 0 , 30 , ( const void * ) & ( rtDW . h5vy20de5m . hfwirb0gp3 ) , sizeof (
rtDW . h5vy20de5m . hfwirb0gp3 ) ) ; mr_simulink_model_cacheDataAsMxArray (
rtdwData , 0 , 31 , ( const void * ) & ( rtDW . dsug4vvosa . my1gf01od4 ) ,
sizeof ( rtDW . dsug4vvosa . my1gf01od4 ) ) ;
mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) &
( rtDW . dsug4vvosa . a4zusecje2 ) , sizeof ( rtDW . dsug4vvosa . a4zusecje2
) ) ; mr_simulink_model_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void
* ) & ( rtDW . dsug4vvosa . hfwirb0gp3 ) , sizeof ( rtDW . dsug4vvosa .
hfwirb0gp3 ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return
ssDW ; } void mr_simulink_model_SetDWork ( const mxArray * ssDW ) { ( void )
ssDW ; mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW
, 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber
( ssDW , 0 , 1 ) ; mr_simulink_model_restoreDataFromMxArray ( ( void * ) & (
rtDW . kqp3jjg4co ) , rtdwData , 0 , 0 , sizeof ( rtDW . kqp3jjg4co ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . hlguwifben )
, rtdwData , 0 , 1 , sizeof ( rtDW . hlguwifben ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . mwnsgljmku )
, rtdwData , 0 , 2 , sizeof ( rtDW . mwnsgljmku ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . olbnwgatth )
, rtdwData , 0 , 3 , sizeof ( rtDW . olbnwgatth ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . h42oy3cyks )
, rtdwData , 0 , 4 , sizeof ( rtDW . h42oy3cyks ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . niqimejvuy )
, rtdwData , 0 , 5 , sizeof ( rtDW . niqimejvuy ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . f1iht1hiua )
, rtdwData , 0 , 6 , sizeof ( rtDW . f1iht1hiua ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . btjmvwwnmg )
, rtdwData , 0 , 7 , sizeof ( rtDW . btjmvwwnmg ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . cm1r3v42mo )
, rtdwData , 0 , 8 , sizeof ( rtDW . cm1r3v42mo ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . avhpt1ir2w )
, rtdwData , 0 , 9 , sizeof ( rtDW . avhpt1ir2w ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . djssvv0v25 )
, rtdwData , 0 , 10 , sizeof ( rtDW . djssvv0v25 ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . a2x5ne2yuh )
, rtdwData , 0 , 11 , sizeof ( rtDW . a2x5ne2yuh ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . hxtyjdui5q )
, rtdwData , 0 , 12 , sizeof ( rtDW . hxtyjdui5q ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . jnd3boi5ry )
, rtdwData , 0 , 13 , sizeof ( rtDW . jnd3boi5ry ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . mylxuoshim )
, rtdwData , 0 , 14 , sizeof ( rtDW . mylxuoshim ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . nsk1euskhj )
, rtdwData , 0 , 15 , sizeof ( rtDW . nsk1euskhj ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . lh5pqvixkq )
, rtdwData , 0 , 16 , sizeof ( rtDW . lh5pqvixkq ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . oo2z0xqarv )
, rtdwData , 0 , 17 , sizeof ( rtDW . oo2z0xqarv ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . kfziacnvmc )
, rtdwData , 0 , 18 , sizeof ( rtDW . kfziacnvmc ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . lkdtqr0oce )
, rtdwData , 0 , 19 , sizeof ( rtDW . lkdtqr0oce ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . kfnv5bckyc )
, rtdwData , 0 , 20 , sizeof ( rtDW . kfnv5bckyc ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . axq5whh23g )
, rtdwData , 0 , 21 , sizeof ( rtDW . axq5whh23g ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . ouxv4le1ru .
my1gf01od4 ) , rtdwData , 0 , 22 , sizeof ( rtDW . ouxv4le1ru . my1gf01od4 )
) ; mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ouxv4le1ru . a4zusecje2 ) , rtdwData , 0 , 23 , sizeof ( rtDW . ouxv4le1ru .
a4zusecje2 ) ) ; mr_simulink_model_restoreDataFromMxArray ( ( void * ) & (
rtDW . ouxv4le1ru . hfwirb0gp3 ) , rtdwData , 0 , 24 , sizeof ( rtDW .
ouxv4le1ru . hfwirb0gp3 ) ) ; mr_simulink_model_restoreDataFromMxArray ( (
void * ) & ( rtDW . m1hymrzrx0 . my1gf01od4 ) , rtdwData , 0 , 25 , sizeof (
rtDW . m1hymrzrx0 . my1gf01od4 ) ) ; mr_simulink_model_restoreDataFromMxArray
( ( void * ) & ( rtDW . m1hymrzrx0 . a4zusecje2 ) , rtdwData , 0 , 26 ,
sizeof ( rtDW . m1hymrzrx0 . a4zusecje2 ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . m1hymrzrx0 .
hfwirb0gp3 ) , rtdwData , 0 , 27 , sizeof ( rtDW . m1hymrzrx0 . hfwirb0gp3 )
) ; mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW .
h5vy20de5m . my1gf01od4 ) , rtdwData , 0 , 28 , sizeof ( rtDW . h5vy20de5m .
my1gf01od4 ) ) ; mr_simulink_model_restoreDataFromMxArray ( ( void * ) & (
rtDW . h5vy20de5m . a4zusecje2 ) , rtdwData , 0 , 29 , sizeof ( rtDW .
h5vy20de5m . a4zusecje2 ) ) ; mr_simulink_model_restoreDataFromMxArray ( (
void * ) & ( rtDW . h5vy20de5m . hfwirb0gp3 ) , rtdwData , 0 , 30 , sizeof (
rtDW . h5vy20de5m . hfwirb0gp3 ) ) ; mr_simulink_model_restoreDataFromMxArray
( ( void * ) & ( rtDW . dsug4vvosa . my1gf01od4 ) , rtdwData , 0 , 31 ,
sizeof ( rtDW . dsug4vvosa . my1gf01od4 ) ) ;
mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW . dsug4vvosa .
a4zusecje2 ) , rtdwData , 0 , 32 , sizeof ( rtDW . dsug4vvosa . a4zusecje2 )
) ; mr_simulink_model_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dsug4vvosa . hfwirb0gp3 ) , rtdwData , 0 , 33 , sizeof ( rtDW . dsug4vvosa .
hfwirb0gp3 ) ) ; } } mxArray * mr_simulink_model_GetSimStateDisallowedBlocks
( ) { return ( NULL ) ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 22 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 166 ) ;
ssSetNumBlockIO ( rtS , 114 ) ; ssSetNumBlockParams ( rtS , 77 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 0.001 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2139584242U ) ; ssSetChecksumVal ( rtS , 1 ,
464569197U ) ; ssSetChecksumVal ( rtS , 2 , 1281492073U ) ; ssSetChecksumVal
( rtS , 3 , 849087122U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { real_T * x
= ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void
* ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
simulink_model_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "simulink_model" ) ;
ssSetPath ( rtS , "simulink_model" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 100.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" }
; static const char_T * rt_LoggedStateBlockNames [ ] = {
"simulink_model/Plant/Integrator3" , "simulink_model/Plant/Integrator4" ,
"simulink_model/Plant/Integrator5" , "simulink_model/Plant/Integrator8" ,
"simulink_model/Plant/Integrator7" , "simulink_model/Plant/Integrator6" ,
"simulink_model/Controller/Z PID/Integrator1" ,
"simulink_model/Controller/Z PID/Integrator" ,
"simulink_model/Controller/Z PID/Integrator2" ,
"simulink_model/Controller/Integrator1" ,
"simulink_model/Controller/Integrator" ,
"simulink_model/Controller/Phi PID/Integrator1" ,
"simulink_model/Controller/Phi PID/Integrator" ,
"simulink_model/Plant/Integrator" ,
"simulink_model/Controller/Theta PID/Integrator1" ,
"simulink_model/Controller/Theta PID/Integrator" ,
"simulink_model/Plant/Integrator1" , "simulink_model/Plant/Integrator2" ,
"simulink_model/Controller/Psi' PID/Integrator" ,
"simulink_model/Plant/Integrator9" , "simulink_model/Plant/Integrator11" ,
"simulink_model/Plant/Integrator10" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 ,
2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 ,
19 , 20 , 21 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 22 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 22 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . gvxadtagwl ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . jly13lpslx ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . bz2jwqhlko ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . e1wo5gexnz ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . nm2msxuufe ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . ftfaoaja4y ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . mjj2cerpbm ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . jr1rtvzctg ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . ek2ch4vurj ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . dk1omijay1 ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . hynfsl50fu ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . jmxvtu0m2y ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . gt5wzenovv ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . mrkdqe0eoh ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . cdkommuqrc ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . m554necusl ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . fk23ijwckh ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . ms3hp32jr2 ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . gx1liw1z0z ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . kds1emu2rh ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtX . nmtygsfoyt ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtX . bxpqdmdwpp ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 22 ] ;
static real_T absTol [ 22 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 22 ] = { 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U } ; static real_T contStateJacPerturbBoundMinVec [ 22 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 22 ] ; static uint8_T zcAttributes [ 22 ] =
{ ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 1 ] = { { 1 * sizeof ( real_T ) ,
( char * ) ( & rtB . cx434fb0ek ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i
< 22 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 0.1 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.001 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
1 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 22 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 22 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2139584242U ) ; ssSetChecksumVal ( rtS , 1 ,
464569197U ) ; ssSetChecksumVal ( rtS , 2 , 1281492073U ) ; ssSetChecksumVal
( rtS , 3 , 849087122U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 7 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_simulink_model_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_simulink_model_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_simulink_model_SetDWork ) ; rtP .
Integrator6_LowerSat = rtMinusInf ; rtP . Integrator1_LowerSat = rtMinusInf ;
rtP . Saturation_UpperSat_gzuimzge4h = rtInf ; rtP .
Saturation1_UpperSat_lmk2qb1doa = rtInf ; rtP .
Saturation2_UpperSat_frujop4uxv = rtInf ; rtP .
Saturation3_UpperSat_na5k5rtqcg = rtInf ; rt_RapidReadMatFileAndUpdateParams
( rtS ) ; if ( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
