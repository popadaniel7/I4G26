#include "Std_Types.h"


#define INTERIOR_LIGHT 9 // PA9

extern uint8_t CurrentState_IntLights;

extern uint8_t BTIntLights;

extern void IntLights_MainFunction();
extern uint8_t IntLights_Init();
extern uint8_t IntLights_GetErrorStatus(uint8_t ApplState);
extern void IntLights_Toggle_IntLights(uint8_t PinState);
