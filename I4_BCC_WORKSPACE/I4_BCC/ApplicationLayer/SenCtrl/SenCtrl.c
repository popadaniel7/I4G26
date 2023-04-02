/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Sensor Control	     		 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "SenCtrl.h"
#include "Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Application state variable. */
uint8 SenCtrl_State;
/* Adc measurements array variable. */
uint32 SenCtrl_MeasuredValues[16];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Application main function declaration. */
VOID SenCtrl_MainFunction();
/* Application initialization function declaration. */
StdReturnType SenCtrl_Init();
/* Application de-initialization function declaration. */
StdReturnType SenCtrl_DeInit();
/* Process sensor value function declaration. */
VOID SenCtrl_ProcessSensorValue();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/

VOID SenCtrl_MainFunction()
{

}
StdReturnType SenCtrl_Init()
{
	return E_OK;
}
StdReturnType SenCtrl_DeInit()
{
	return E_OK;
}
VOID SenCtrl_ProcessSensorValue()
{

}
