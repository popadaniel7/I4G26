/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Watchdog Manager				 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "WatchdogManager.h"
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
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Watchdog_Init									   		       		   *
* Description: Peripheral initialization.							 		   	   *
************************************************************************************/
StdReturnType Watchdog_Init()
{
	hiwdg.Instance = IWDG;
	hiwdg.Init.Prescaler = IWDG_PRESCALER_128;
	hiwdg.Init.Reload = 50;
	if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
	{
		Error_Handler();
	}
	return E_OK;
}
/***********************************************************************************
* END OF Watchdog_Init											  		           *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Watchdog_MainFunction									   		       *
* Description: Peripheral main function.							 		       *
************************************************************************************/
VOID Watchdog_MainFunction()
{
	HAL_IWDG_Refresh(&hiwdg);
}
/***********************************************************************************
* END OF Watchdog_MainFunction											  		   *													       																	   *
************************************************************************************/
