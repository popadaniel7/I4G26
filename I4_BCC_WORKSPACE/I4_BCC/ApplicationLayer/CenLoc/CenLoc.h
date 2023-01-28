#include "Std_Types.h"

#define CENLOC_DOOR_LED_PORT 	GPIOB
#define CENLOC_DOOR_LED_PIN 	GPIO_PIN_7
#define CENLOC_BUZZER_PORT 		GPIOC
#define CENLOC_BUZZER_PIN		GPIO_PIN_4

EXTERN uint8 CenLoc_CurrentState;
EXTERN uint8 CenLoc_PreviousState;
EXTERN uint8 CenLoc_LockUnlockFlag;
EXTERN uint8 CenLoc_ExtLights_UnlockedState;
EXTERN uint8 CenLoc_ExtLights_LockedState;
EXTERN uint8 CenLoc_FollowMeHomeState;
EXTERN uint8 CenLoc_BlinkState;
EXTERN uint8 CenLoc_LockCounter;
EXTERN uint8 CenLoc_UnlockCounter;
EXTERN uint8 CenLoc_AlarmLedChangeState;
EXTERN uint8 Btc_CenLoc;

EXTERN uint8 CenLoc_Tim2IRQFlag;
EXTERN uint8 CenLoc_Tim3IRQFlag;
EXTERN uint8 CenLoc_Tim5IRQFlag;
EXTERN uint8 CenLoc_Tim11IRQFlag;

EXTERN void CenLocMainFunction();
EXTERN void CenLocToggleDoorLED(uint8 PinState);
EXTERN void CenLocToggleBuzzer(uint8 PinState);
EXTERN void CenLocFollowMeHome();
EXTERN void CenLocBlinkSignals();
EXTERN void CenLocRxBtcState();
EXTERN void CenLocSecAlmStateToOff();
EXTERN StdReturnType CenLocInit();
EXTERN StdReturnType CenLocState();
EXTERN StdReturnType CenLocLockUnlockStates();
