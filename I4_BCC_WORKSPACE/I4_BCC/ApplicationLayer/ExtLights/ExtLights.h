#include "Std_Types.h"

#define EXTLIGHTS_LOWBEAM_PORT 					GPIOA //default value
#define EXTLIGHTS_LOWBEAM_PIN 					GPIO_PIN_5 // to be changed
#define EXTLIGHTS_HIGHBEAM_PORT 				GPIOA
#define EXTLIGHTS_HIGHBEAM_PIN 					GPIO_PIN_5
#define EXTLIGHTS_DAYTIMERUNNINGLIGHT_PORT 		GPIOA
#define EXTLIGHTS_DAYTIMERUNNINGLIGHT_PIN 		GPIO_PIN_5
#define EXTLIGHTS_FRONTFOGLIGHT_PORT 			GPIOA
#define EXTLIGHTS_FRONTFOGLIGHT_PIN 			GPIO_PIN_5
#define EXTLIGHTS_TURNSIGNALLEFT_PORT 			GPIOA
#define EXTLIGHTS_TURNSIGNALLEFT_PIN 			GPIO_PIN_5
#define EXTLIGHTS_TURNSIGNALRIGHT_PORT 			GPIOA
#define EXTLIGHTS_TURNSIGNALRIGHT_PIN 			GPIO_PIN_5
#define EXTLIGHTS_REARPOSITIONLIGHT_PORT 		GPIOA
#define EXTLIGHTS_REARPOSITIONLIGHT_PIN 		GPIO_PIN_5
#define EXTLIGHTS_REARFOGLIGHT_PORT 			GPIOA
#define EXTLIGHTS_REARFOGLIGHT_PIN 				GPIO_PIN_5
#define EXTLIGHTS_BRAKELIGHT_PORT 				GPIOA
#define EXTLIGHTS_BRAKELIGHT_PIN 				GPIO_PIN_5
#define EXTLIGHTS_REVERSELIGHT_PORT 			GPIOA
#define EXTLIGHTS_REVERSELIGHT_PIN 				GPIO_PIN_5
#define EXTLIGHTS_LICENSEPLATELIGHT_PORT 		GPIOA
#define EXTLIGHTS_LICENSEPLATELIGHT_PIN 		GPIO_PIN_5
#define EXTLIGHTS_LIGHTSWITCH_STATEZERO			100
#define EXTLIGHTS_LIGHTSWITCH_STATEONE			101
#define EXTLIGHTS_LIGHTSWITCH_STATETWO			102
#define EXTLIGHTS_LIGHTSWITCH_STATETHREE		103
#define EXTLIGHTS_LIGHTSENSOR_DAYNIGHTVALUE 	150

EXTERN uint8 ExtLights_ReverseLight_CurrentState;
EXTERN uint8 ExtLights_FlashHighBeam_CurrentState;
EXTERN uint8 ExtLights_BrakeLight_CurrentState;
EXTERN uint8 ExtLights_LightsSwitch_CurrentState;
EXTERN uint8 ExtLights_HighBeam_CurrentState;
EXTERN uint8 ExtLights_FrontFogLight_CurrentState;
EXTERN uint8 ExtLights_TurnSignalLeft_CurrentState;
EXTERN uint8 ExtLights_TurnSignalRight_CurrentState;
EXTERN uint8 ExtLights_HazardLight_CurrentState;
EXTERN uint8 ExtLights_RearFogLight_CurrentState;
EXTERN uint8 Btc_LightSwitch;
EXTERN uint8 Btc_HighBeam;
EXTERN uint8 Btc_FlashHighBeam;
EXTERN uint8 Btc_FrontFogLight;
EXTERN uint8 Btc_TurnSignalLeft;
EXTERN uint8 Btc_TurnSignalRight;
EXTERN uint8 Btc_HazardLight;
EXTERN uint8 Btc_BrakeLight;
EXTERN uint8 Btc_RearFogLight;

EXTERN void ExtLightsMainFunction();
EXTERN void ExtLightsLowBeam(uint8 PinState);
EXTERN void ExtLightsHighBeam(uint8 PinState);
EXTERN void ExtLightsDayTimeRunningLight(uint8 PinState);
EXTERN void ExtLightsTurnSignalLeft(uint8 PinState);
EXTERN void ExtLightsTurnSignalRight(uint8 PinState);
EXTERN void ExtLightsFrontFogLight(uint8 PinState);
EXTERN void ExtLightsRearPositionLight(uint8 PinState);
EXTERN void ExtLightsBrakeLight(uint8 PinState);
EXTERN void ExtLightsLicensePlateLight(uint8 PinState);
EXTERN void ExtLightsRearFogLight(uint8 PinState);
EXTERN void ExtLightsReverseLight(uint8 PinState);
EXTERN void ExtLightsRxBtcState();
EXTERN void ExtLightsLightState();
EXTERN StdReturnType ExtLightsInit();
EXTERN uint32 ExtLightsLightReadSensorValue();
