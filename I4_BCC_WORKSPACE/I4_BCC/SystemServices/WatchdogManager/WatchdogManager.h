/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Watchdog Manager				 *
******************************************/
#ifndef WatchdogManager_H
#define WatchdogManager_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
#include "wwdg.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Peripheral initialization function declaration. */
EXTERN StdReturnType Watchdog_Init();
/* Peripheral main function declaration. */
EXTERN VOID Watchdog_MainFunction();
/* Peripheral early wake-up callback function declaration. */
EXTERN VOID HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* WatchdogManager_H */
