#include "Std_Types.h"

#define DOOR_LED_PORT GPIOB
#define DOOR_LED_PIN GPIO_PIN_6

EXTERN uint8 CurrentState_Door;
EXTERN uint8 CurrentState_CenLoc;
EXTERN uint8 PreviousState_CenLoc;
EXTERN uint8 BTCenLoc;
EXTERN uint8 BTCenLoc_LockUnlockFlag;
EXTERN uint8 ExtLights_UnlockedState;
EXTERN uint8 ExtLights_LockedState;

EXTERN void CenLoc_MainFunction();
EXTERN StdReturnType CenLoc_Init();
EXTERN StdReturnType CenLoc_GetErrorStatus(uint8 ApplState);
EXTERN void CenLoc_Toggle_Door_LED(uint8 PinState);





