/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Electronic Control Unit		 *
* 		  Manager						 *
******************************************/
#ifndef EcuM_H
#define EcuM_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Define value for wake up source */
#define ECUM_WAKEUPSOURCE_POR 						0
/* Define value for wake up source */
#define ECUM_WAKEUPSOURCE_BOR 						1
/* Define value for wake up source */
#define ECUM_WAKEUPSOURCE_SOFTWARE_RESET			2
/* Define value for wake p source */
#define ECUM_WAKEUPSOURCE_WINDOWED_WATCHDOG_RESET	3
/* Define value for wake up source */
#define ECUM_WAKEUPSOURCE_LOWPOWER_RESET			4
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store Electronic Control Unit Manager state. */
EXTERN uint8 EcuM_BswState;
/* Variable to store wake up source. */
EXTERN uint8 EcuM_GlobalState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Driver initialization function declaration. */
EXTERN StdReturnType EcuM_DriverInit();
/* Driver de-initialization function declaration. */
EXTERN StdReturnType EcuM_DriverDeInit();
/* Electronic control unit main function declaration. */
EXTERN VOID EcuM_MainFunction();
/* Electronic control unit wake up source storing function declaration. */
EXTERN VOID EcuM_SetWakeupSource(uint32 wakeupSource);
/* Electronic control unit wake up source processing function declaration. */
EXTERN VOID EcuM_ProcessWakeupEvent();
/* Electronic control unit wake up source check function declaration. */
EXTERN VOID EcuM_CheckForWakeupEvent();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif
