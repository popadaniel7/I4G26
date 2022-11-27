#include "Std_Types.h"


#define INTERIOR_LIGHT_PORT GPIOB
#define INTERIOR_LIGHT_PIN GPIO_PIN_10

EXTERN uint8 CurrentState_IntLights;

EXTERN uint8 BTIntLights;

EXTERN void IntLights_MainFunction();
EXTERN StdReturnType IntLights_Init();
EXTERN StdReturnType IntLights_GetErrorStatus(uint8 ApplState);
EXTERN void IntLights_Toggle_IntLights(uint8 PinState);
