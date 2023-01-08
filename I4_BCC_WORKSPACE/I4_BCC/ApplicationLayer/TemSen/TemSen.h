#include "Std_Types.h"

#define TemSenColdTemp 		3
#define TemSenMinTemp 		-40
#define TemSenMaxTemp 		60
#define TemSenVRefVal 		1.43
#define TemSenVSensVal 		0.00080566406
#define TemSenAvgSlopeVal 	0.0043
#define TemSenMicroMinTemp 	-40
#define TemSenMicroMaxTemp 	125

EXTERN float TemSenAdcRxValue;
EXTERN float TemSenRxTemperature;

EXTERN StdReturnType TemSenInit();
EXTERN float TemSenAdcReceivedValues();
EXTERN float TemSenReturnTemperatureValue(float TemVal);
EXTERN void TemSenTemperatureStatus();
EXTERN void TemSenMainFunction();
