#include "Std_Types.h"

#define DOOR_LED

extern uint8_t CurrentState_Door;
extern uint8_t CurrentState_CenLoc;
extern uint8_t BTCenLoc;
extern uint8_t BTCenLoc_IrqFlag;
extern uint8_t CenLoc_PrevState;

extern void CenLoc_MainFunction();
extern uint8_t CenLoc_Init();
extern uint8_t CenLoc_GetErrorStatus(uint8_t ApplState);
extern void CenLoc_Toggle_Door_LED(uint8_t PinState);





