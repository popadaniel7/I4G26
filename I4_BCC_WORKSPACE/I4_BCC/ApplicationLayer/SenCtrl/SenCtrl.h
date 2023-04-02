/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Sensor Control	     		 *
******************************************/
#ifndef SenCtrl_H
#define SenCtrl_H
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
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Application state variable. */
EXTERN uint8 SenCtrl_State;
/* Adc measurements array variable. */
EXTERN uint32 SenCtrl_MeasuredValues[16];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Application main function declaration. */
EXTERN VOID SenCtrl_MainFunction();
/* Application initialization function declaration. */
EXTERN StdReturnType SenCtrl_Init();
/* Application de-initialization function declaration. */
EXTERN StdReturnType SenCtrl_DeInit();
/* Process sensor value function declaration. */
EXTERN VOID SenCtrl_ProcessSensorValue();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* SenCtrl_H */
