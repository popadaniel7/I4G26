/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Central Locking	     		 *
******************************************/
#ifndef CenLoc_H
#define CenLoc_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
/*****************************************
		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Central lock current state variable. */
EXTERN uint8 CenLoc_CurrentState;
/* Central lock previous current state variable. */
EXTERN uint8 CenLoc_PreviousState;
/* Follow me home feature current state variable. */
EXTERN uint8 CenLoc_FollowMeHomeState;
/* Central lock lock unlock sequence blink state for turn signals variable. */
EXTERN uint8 CenLoc_BlinkState;
/* Timer cycle counter. */
EXTERN uint8 CenLoc_BlinkCounter;
/* Timer cycle counter. */
EXTERN uint8 CenLoc_CyclicAlarmCounter;
/* Timer cycle counter. */
EXTERN uint8 CenLoc_FollowMeHomeCounter;
/* Timer cycle counter. */
EXTERN uint8 CenLoc_TurnOnLedCounter;
/* Central lock previous state flag variable. */
EXTERN uint8 CenLoc_PreviousStateFlag;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Central lock main function declaration. */
EXTERN VOID CenLoc_MainFunction();
/* Buzzer lock unlock state control function declaration. */
EXTERN VOID CenLoc_ToggleBuzzer(uint8 PinState);
/* Follow me home state processing function declaration. */
EXTERN VOID CenLoc_FollowMeHome();
/* Follow me home state processing function declaration. */
EXTERN VOID CenLoc_BlinkSignals();
/* Security alarm turn off function declaration. */
EXTERN VOID CenLoc_SecAlmStateToOff();
/* Unlock sequence function declaration. */
EXTERN VOID CenLoc_UnlockSequence();
/* Lock sequence function declaration. */
EXTERN VOID CenLoc_LockSequence();
/* Security alarm LED control function declaration. */
EXTERN VOID CenLoc_ControlAlarmLed();
/* Central lock application initialization function declaration. */
EXTERN StdReturnType CenLoc_Init();
/* Current and previous state update function declaration. */
EXTERN VOID CenLoc_State();
/* Trigger for lock / unlock sequence function declaration. */
EXTERN VOID CenLoc_LockUnlockStates();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* CenLoc_H */
