#include "Std_Types.h"

#define INTERIOR_LIGHT_PORT 	GPIOC
#define INTERIOR_LIGHT_PIN 		GPIO_PIN_2

EXTERN uint8 IntLights_CurrentState;
EXTERN uint8 IntLights_StateFlag;
EXTERN uint8 Btc_IntLights;

EXTERN StdReturnType IntLightsInit();
EXTERN void IntLightsMainFunction();
EXTERN void IntLightsToggleIntLights(uint8 PinState);
EXTERN void IntLightsRxBtcState();
