#include "Std_Types.h"

#define HVAC_MIN_TEMP_VALUE 				16
#define HVAC_MAX_TEMP_VALUE 				32
#define HVAC_MIN_FAN_VALUE  				1
#define HVAC_MAX_FAN_VALUE 					7
#define HVAC_NORMAL_MODE					0
#define HVAC_RECIRCULATION_MODE 			1
#define HVAC_AUTOMATIC_RECIRCULATION_MODE	2
#define HVAC_AUTOMATIC_MODE					4

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

EXTERN StdReturnType HVACInit();
EXTERN void HVACMainFunction();
EXTERN void HVACState();
EXTERN void HVACRecirculationMode(uint8 RecirculationState);
EXTERN void HVACAutomaticMode(uint8 AutomaticState);
EXTERN void HVACI2cTxToLcd();
