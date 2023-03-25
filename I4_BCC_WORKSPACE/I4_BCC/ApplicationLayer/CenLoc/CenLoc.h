#include "Std_Types.h"

#define CENLOC_DOOR_LED_PORT 	GPIOB
#define CENLOC_DOOR_LED_PIN 	GPIO_PIN_7
#define CENLOC_BUZZER_PORT 		GPIOC
#define CENLOC_BUZZER_PIN		GPIO_PIN_4
#define CENLOC_INIT				0x00
#define CENLOC_RUNNING			0x03
#define CENLOC_ERROR			0x04

EXTERN uint8 CenLoc_CurrentState;
EXTERN uint8 CenLoc_PreviousState;
EXTERN uint8 CenLoc_FollowMeHomeState;
EXTERN uint8 CenLoc_BlinkState;
EXTERN uint8 CenLoc_Tim2IRQFlag;
EXTERN uint8 CenLoc_Tim3IRQFlag;
EXTERN uint8 CenLoc_Tim5IRQFlag;
EXTERN uint8 CenLoc_Tim11IRQFlag;
EXTERN uint8 CenLoc_PreviousStateFlag;

EXTERN void CenLoc_MainFunction();
EXTERN void CenLoc_ToggleDoorLED(uint8 PinState);
EXTERN void CenLoc_ToggleBuzzer(uint8 PinState);
EXTERN void CenLoc_FollowMeHome();
EXTERN void CenLoc_BlinkSignals();
EXTERN void CenLoc_SecAlmStateToOff();
EXTERN void CenLoc_UnlockSequence();
EXTERN void CenLoc_LockSequence();
EXTERN void CenLoc_ControlAlarmLed();
EXTERN StdReturnType CenLoc_Init();
EXTERN void CenLoc_State();
EXTERN void CenLoc_LockUnlockStates();
