#ifndef RTW_HEADER_simulink_model_h_
#define RTW_HEADER_simulink_model_h_
#ifndef simulink_model_COMMON_INCLUDES_
#define simulink_model_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "simulink_model_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME simulink_model
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (114) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (22)   
#elif NCSTATES != 22
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { int32_T my1gf01od4 ; uint8_T a4zusecje2 ; boolean_T
hfwirb0gp3 ; } cbogeonl3h ; typedef struct { real_T nqywse5ut4 ; real_T
jbstlwmhap ; real_T if1iz101fk ; real_T oeyj5uhp3i ; real_T mi1km3oyut ;
real_T mpdf5tqidb ; real_T nxse5y1hxs ; real_T iavp3z1f0w ; real_T bfleczw4f3
; real_T a1lifoil3y ; real_T dsztqe2vkx ; real_T my2vvqja3k ; real_T
idyjdp421i ; real_T dmnzfxvk0s ; real_T nmkvhgkd2p ; real_T mizkhlpjef ;
real_T dxphwwoqpi ; real_T ef1lv21ood ; real_T oqhznzhmir ; real_T mxr2jetlva
; real_T n1i0g2quyr ; real_T acfxwsko33 ; real_T nrriu35a3f ; real_T
bx3ajp1ok2 ; real_T hojc3htffq ; real_T edpbkcvi15 ; real_T cvk1wcfm3n ;
real_T nmiwadwpyh ; real_T al0xpzoz2z ; real_T nqcjokfxxg ; real_T nygvtqvltq
; real_T i2ji13hv35 ; real_T idounap34d ; real_T pgqq0hod5c ; real_T
g1n4mdep1v ; real_T oyadxno0tg ; real_T axppsfv11x ; real_T jvw1mdfihi ;
real_T ogev4jucip ; real_T nk24qgc3td ; real_T bmgs2of0v4 ; real_T olm4t4rcyo
; real_T hwgjqfxchd ; real_T er2q4gcfwf ; real_T h3px4j43ml ; real_T
l5fwabq3kt ; real_T hatuktxq5n ; real_T b5qmw2w2an ; real_T moe2m40xs1 ;
real_T ofk3gtywup ; real_T fqbabctd00 ; real_T pca4x342k4 ; real_T mrycz1krbe
; real_T npzhihrtw4 ; real_T eercnseb5a ; real_T d4xsowxqum ; real_T
dakxuanftu ; real_T o5kecny1zt ; real_T nq1h44zzd1 ; real_T mf32z31xd3 ;
real_T gqx21pyhi1 ; real_T paa1m0mnsc ; real_T gxfy4s1rme ; real_T ly5x5ptd5f
; real_T o41kp2eiqn ; real_T cp03e3zuli ; real_T pwfs0cxkha ; real_T
fmkkt4a3af ; real_T ov0ybomziy ; real_T bstcht5uj5 ; real_T pynedc5gep ;
real_T auew1negjx ; real_T kvvhdsb4ap ; real_T jjeppmnf5s ; real_T h55bc35fac
; real_T iq5fixgwb0 ; real_T lwnxwhawyc ; real_T ggwtgd1omn ; real_T
m212hqnj5y ; real_T gu2wqtcrpg ; real_T h0tyi3ahxq ; real_T nb1txnf124 ;
real_T cgknn01qbh ; real_T amyrq22pmo ; real_T fgbngwqnd5 ; real_T apfjfvxnbo
; real_T nq0ycmxp1p ; real_T duonk1hgtb ; real_T cxqjgsd4x5 ; real_T
mb0qn1wsho ; real_T mfnuqnf2if ; real_T glruen4axf ; real_T gjyfhfbbrb ;
real_T hgu1yymjsw ; real_T osoak53vuu ; real_T ozrfmyckp0 ; real_T ag311bmkkx
; real_T cfmho4ajea ; real_T jjvzfhgfci ; real_T fo1hseqjoo ; real_T
dolzgkocov ; real_T cx434fb0ek ; real_T ikle3qa1kc ; real_T ptfymszom1 ;
real_T mr3bonhsk2 ; real_T heh3e0vd2n ; real_T mc2mnuakhz ; real_T iuicad1o5e
; } B ; typedef struct { real_T kqp3jjg4co ; real_T hlguwifben ; real_T
mwnsgljmku ; real_T olbnwgatth ; real_T h42oy3cyks ; struct { void *
AQHandles ; } hxvxyhqwfc ; struct { void * AQHandles ; } i21byq1hgv ; struct
{ void * AQHandles ; } nqm15m4wuk ; struct { void * AQHandles ; } pykudpzq5m
; struct { void * AQHandles ; } n4yoasy2fq ; struct { void * AQHandles ; }
bwe3frmqyw ; struct { void * AQHandles ; } kdewiatuma ; struct { void *
AQHandles ; } g3zcewv4mo ; struct { void * AQHandles ; } nqcqcrisqu ; int32_T
niqimejvuy ; int32_T f1iht1hiua ; uint32_T btjmvwwnmg ; int_T cm1r3v42mo ;
int_T avhpt1ir2w ; int_T djssvv0v25 ; int_T a2x5ne2yuh ; int_T hxtyjdui5q ;
int_T jnd3boi5ry ; int_T mylxuoshim ; int_T nsk1euskhj ; int_T lh5pqvixkq ;
int_T oo2z0xqarv ; uint8_T kfziacnvmc ; uint8_T lkdtqr0oce ; boolean_T
kfnv5bckyc ; boolean_T axq5whh23g ; cbogeonl3h ouxv4le1ru ; cbogeonl3h
m1hymrzrx0 ; cbogeonl3h h5vy20de5m ; cbogeonl3h dsug4vvosa ; } DW ; typedef
struct { real_T gvxadtagwl ; real_T jly13lpslx ; real_T bz2jwqhlko ; real_T
e1wo5gexnz ; real_T nm2msxuufe ; real_T ftfaoaja4y ; real_T mjj2cerpbm ;
real_T jr1rtvzctg ; real_T ek2ch4vurj ; real_T dk1omijay1 ; real_T hynfsl50fu
; real_T jmxvtu0m2y ; real_T gt5wzenovv ; real_T mrkdqe0eoh ; real_T
cdkommuqrc ; real_T m554necusl ; real_T fk23ijwckh ; real_T ms3hp32jr2 ;
real_T gx1liw1z0z ; real_T kds1emu2rh ; real_T nmtygsfoyt ; real_T bxpqdmdwpp
; } X ; typedef struct { real_T gvxadtagwl ; real_T jly13lpslx ; real_T
bz2jwqhlko ; real_T e1wo5gexnz ; real_T nm2msxuufe ; real_T ftfaoaja4y ;
real_T mjj2cerpbm ; real_T jr1rtvzctg ; real_T ek2ch4vurj ; real_T dk1omijay1
; real_T hynfsl50fu ; real_T jmxvtu0m2y ; real_T gt5wzenovv ; real_T
mrkdqe0eoh ; real_T cdkommuqrc ; real_T m554necusl ; real_T fk23ijwckh ;
real_T ms3hp32jr2 ; real_T gx1liw1z0z ; real_T kds1emu2rh ; real_T nmtygsfoyt
; real_T bxpqdmdwpp ; } XDot ; typedef struct { boolean_T gvxadtagwl ;
boolean_T jly13lpslx ; boolean_T bz2jwqhlko ; boolean_T e1wo5gexnz ;
boolean_T nm2msxuufe ; boolean_T ftfaoaja4y ; boolean_T mjj2cerpbm ;
boolean_T jr1rtvzctg ; boolean_T ek2ch4vurj ; boolean_T dk1omijay1 ;
boolean_T hynfsl50fu ; boolean_T jmxvtu0m2y ; boolean_T gt5wzenovv ;
boolean_T mrkdqe0eoh ; boolean_T cdkommuqrc ; boolean_T m554necusl ;
boolean_T fk23ijwckh ; boolean_T ms3hp32jr2 ; boolean_T gx1liw1z0z ;
boolean_T kds1emu2rh ; boolean_T nmtygsfoyt ; boolean_T bxpqdmdwpp ; } XDis ;
typedef struct { real_T gvxadtagwl ; real_T jly13lpslx ; real_T bz2jwqhlko ;
real_T e1wo5gexnz ; real_T nm2msxuufe ; real_T ftfaoaja4y ; real_T mjj2cerpbm
; real_T jr1rtvzctg ; real_T ek2ch4vurj ; real_T dk1omijay1 ; real_T
hynfsl50fu ; real_T jmxvtu0m2y ; real_T gt5wzenovv ; real_T mrkdqe0eoh ;
real_T cdkommuqrc ; real_T m554necusl ; real_T fk23ijwckh ; real_T ms3hp32jr2
; real_T gx1liw1z0z ; real_T kds1emu2rh ; real_T nmtygsfoyt ; real_T
bxpqdmdwpp ; } CStateAbsTol ; typedef struct { real_T gvxadtagwl ; real_T
jly13lpslx ; real_T bz2jwqhlko ; real_T e1wo5gexnz ; real_T nm2msxuufe ;
real_T ftfaoaja4y ; real_T mjj2cerpbm ; real_T jr1rtvzctg ; real_T ek2ch4vurj
; real_T dk1omijay1 ; real_T hynfsl50fu ; real_T jmxvtu0m2y ; real_T
gt5wzenovv ; real_T mrkdqe0eoh ; real_T cdkommuqrc ; real_T m554necusl ;
real_T fk23ijwckh ; real_T ms3hp32jr2 ; real_T gx1liw1z0z ; real_T kds1emu2rh
; real_T nmtygsfoyt ; real_T bxpqdmdwpp ; } CXPtMin ; typedef struct { real_T
gvxadtagwl ; real_T jly13lpslx ; real_T bz2jwqhlko ; real_T e1wo5gexnz ;
real_T nm2msxuufe ; real_T ftfaoaja4y ; real_T mjj2cerpbm ; real_T jr1rtvzctg
; real_T ek2ch4vurj ; real_T dk1omijay1 ; real_T hynfsl50fu ; real_T
jmxvtu0m2y ; real_T gt5wzenovv ; real_T mrkdqe0eoh ; real_T cdkommuqrc ;
real_T m554necusl ; real_T fk23ijwckh ; real_T ms3hp32jr2 ; real_T gx1liw1z0z
; real_T kds1emu2rh ; real_T nmtygsfoyt ; real_T bxpqdmdwpp ; } CXPtMax ;
typedef struct { real_T ou3qy5fi14 ; real_T b4ut14lxda ; real_T g44iucpq23 ;
real_T pizvrw23lj ; real_T cv1srbrtef ; real_T hk0ikpoypi ; real_T echid3gkwp
; real_T islikvvzx5 ; real_T grn5kwyacq ; real_T fpkdsw13sc ; real_T
hbkkastf5m ; real_T eql42dn21o ; real_T nmusc4quyi ; real_T o4yledqaiy ;
real_T il54w1vatn ; real_T gkzxzmemuh ; real_T awgnovmp4t ; real_T ev0ofnghc2
; real_T jxkfe23gc0 ; real_T ewst3nqtts ; real_T kp5qtzaivg ; real_T
mkkixitadk ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T Ax ; real_T Ay ; real_T Az ; real_T Ixx ;
real_T Iyy ; real_T Izz ; real_T Jr ; real_T Phi_D ; real_T Phi_I ; real_T
Phi_P ; real_T Psi_dot_D ; real_T Psi_dot_I ; real_T Psi_dot_P ; real_T
Theta_D ; real_T Theta_I ; real_T Theta_P ; real_T Z_D ; real_T Z_I ; real_T
Z_P ; real_T d ; real_T g ; real_T l ; real_T m ; real_T Integrator3_IC ;
real_T Integrator4_IC ; real_T Integrator5_IC ; real_T Integrator8_IC ;
real_T Integrator7_IC ; real_T Integrator6_IC ; real_T Integrator6_UpperSat ;
real_T Integrator6_LowerSat ; real_T Integrator1_IC ; real_T
Integrator1_UpperSat ; real_T Integrator1_LowerSat ; real_T Integrator_IC ;
real_T Integrator2_IC ; real_T Integrator1_IC_irkesqhxjc ; real_T
Integrator_IC_atrldbhoby ; real_T Integrator1_IC_pvc43f4wjv ; real_T
Integrator_IC_of2tsl4pem ; real_T Integrator_IC_i2vfa00yuw ; real_T
Integrator1_IC_i2bjhakqq4 ; real_T Integrator_IC_ba024q11w2 ; real_T
Integrator1_IC_jcknyc0a5u ; real_T Integrator2_IC_owzkbh1yyf ; real_T
Integrator_IC_ccb2sgg2ag ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T Saturation_UpperSat_gzuimzge4h ; real_T
Saturation_LowerSat_hxfynrebf2 ; real_T Saturation1_UpperSat ; real_T
Saturation1_LowerSat ; real_T Saturation1_UpperSat_lmk2qb1doa ; real_T
Saturation1_LowerSat_cg1ign3p35 ; real_T Saturation2_UpperSat ; real_T
Saturation2_LowerSat ; real_T Saturation2_UpperSat_frujop4uxv ; real_T
Saturation2_LowerSat_efiqybc0ah ; real_T Saturation3_UpperSat ; real_T
Saturation3_LowerSat ; real_T Saturation3_UpperSat_na5k5rtqcg ; real_T
Saturation3_LowerSat_cniur41mc3 ; real_T Integrator9_IC ; real_T
Integrator11_IC ; real_T Integrator10_IC ; real_T RandomNumber_Mean ; real_T
RandomNumber_StdDev ; real_T RandomNumber_Seed ; real_T ALWAYSNEGATIVE_Value
; real_T Constant1_Value ; real_T Constant2_Value ; real_T Constant3_Value ;
real_T Constant4_Value ; real_T Gain_Gain ; real_T Gain2_Gain ; real_T
Gain_Gain_fb0j4u0hjn ; real_T Gain_Gain_of3jgnpx3n ; } ; extern const char_T
* RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_simulink_model_GetDWork ( ) ; extern void
mr_simulink_model_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_simulink_model_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * simulink_model_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
