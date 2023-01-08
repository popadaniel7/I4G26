#include "Std_Types.h"

#define BtcRxCenLocOn 				1
#define BtcRxCenLocOff 				2
#define BtcRxHighBeamOn 			3
#define BtcRxHighBeamOff 			4
#define BtcRxFlashHighBeamOn 		5
#define BtcRxFlashHighBeamOff 		6
#define BtcRxTurnSignalLeftOn 		7
#define BtcRxTurnSignalLeftOff 		8
#define BtcRxTurnSignalRightOn 		9
#define BtcRxTurnSignalRightOff 	10
#define BtcRxHazardLightOn 			11
#define BtcRxHazardLightOff 		12
#define BtcRxFogLightFrontOn 		13
#define BtcRxFogLightFrontOff 		14
#define BtcRxFogLightRearOn 		15
#define BtcRxFogLightRearOff 		16
#define BtcRxBrakeLightsOn 			17
#define BtcRxBrakeLightsOff 		18
#define BtcRxInteriorLightsOn 		19
#define BtcRxInteriorLightsOff 		20
#define BtcRxPositionZero			100
#define BtcRxAutomaticLightsOn		101
#define BtcRxPositionLightsOn		102
#define BtcRxNightTimeLightsOn		103

EXTERN uint8 BtcReceivedDataOnBluetooth;
EXTERN uint8 BtcReceivedDataIRQ;

EXTERN void BtcMainFunction();
EXTERN StdReturnType BtcInit();
EXTERN StdReturnType BtcRxVal();
EXTERN StdReturnType BtcEnableUart();
