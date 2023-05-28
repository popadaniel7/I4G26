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
/* Application request define. */
#define SENCTRL_EXTLIGHTS_LS_POSITION 					0
/* Application request define. */
#define SENCTRL_SECALM_VS_POSITION 						1
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Adc measurements array variable. */
EXTERN uint32 SenCtrl_MeasuredValues[2];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Process sensor value function declaration. */
EXTERN VOID SenCtrl_ProcessSensorValue(uint8 request);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* SenCtrl_H */
