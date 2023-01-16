#include "Std_Types.h"

#define HVAC_TemSenColdTemp 		3
#define HVAC_TemSenMinTemp 			-40
#define HVAC_TemSenMaxTemp 			60
#define HVAC_TemSenVRefVal 			1.43
#define HVAC_TemSenVSensVal 		0.00080566406
#define HVAC_TemSenAvgSlopeVal 		0.0043
#define HVAC_TemSenMicroMinTemp 	-40
#define HVAC_TemSenMicroMaxTemp 	125

EXTERN uint8 HVAC_CurrentState;
EXTERN uint8 HVAC_TemperatureValue;
EXTERN uint8 HVAC_FanValue;
EXTERN uint8 HVAC_LegVents_CurrentState;
EXTERN uint8 HVAC_MidVents_CurrentState;
EXTERN uint8 HVAC_WindshieldVents_CurrentState;
EXTERN uint8 HVAC_WindshieldDefrost_CurrentState;
EXTERN uint8 HVAC_BackwindowDefrost_CurrentState;
EXTERN uint8 HVAC_AC_CurrentState;
EXTERN uint8 HVAC_AutomaticMode_CurrentState;
EXTERN uint8 HVAC_RecirculationMode_CurrentState;
EXTERN float HVAC_TemSenAdcRxValue;
EXTERN float HVAC_TemSenRxTemperature;
EXTERN uint8 Btc_TemperatureValue;
EXTERN uint8 Btc_FanValue;
EXTERN uint8 Btc_LegVents;
EXTERN uint8 Btc_MidVents;
EXTERN uint8 Btc_WindshieldVents;
EXTERN uint8 Btc_WindshieldDefrost;
EXTERN uint8 Btc_BackwindowDefrost;
EXTERN uint8 Btc_AC;
EXTERN uint8 Btc_AutomaticMode;
EXTERN uint8 Btc_RecirculationMode;
EXTERN uint8 Btc_NormalMode;


EXTERN float HVACTemSenAdcReceivedValues();
EXTERN float HVACTemSenReturnTemperatureValue(float TemVal);
EXTERN void HVACTemSenTemperatureStatus();

EXTERN StdReturnType HVACInit();
EXTERN void HVACMainFunction();
EXTERN void HVACState();
EXTERN void HVACI2cTxToLcd();
