/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Interior Lights	     		 *
******************************************/
#ifndef IntLights_H
#define IntLights_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
/*****************************************
		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable for the interior lights current states. */
EXTERN uint8 IntLights_CurrentState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Interior lights main function. */
EXTERN VOID IntLights_MainFunction();
/* Interior lights command processed. */
EXTERN VOID IntLights_RxBtcState();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* IntLights_H */
