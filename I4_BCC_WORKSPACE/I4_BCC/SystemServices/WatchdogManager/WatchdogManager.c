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
/* Peripheral early wake-up callback function declaration. */
EXTERN VOID HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: HAL_WWDG_EarlyWakeupCallback									   	   *
* Description: Early waek-up callback.							 		   		   *
************************************************************************************/
VOID HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
	SystemManager_SetFault(WATCHDOG_RESET);
}
/***********************************************************************************
* END OF HAL_WWDG_EarlyWakeupCallback											   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Watchdog_Init									   		       		   *
* Description: Peripheral initialization.							 		   	   *
************************************************************************************/
StdReturnType Watchdog_Init()
{
	hwwdg.Instance = WWDG;
	hwwdg.Init.Window = 127;
	hwwdg.Init.Prescaler = WWDG_PRESCALER_8;
	hwwdg.Init.Counter = 127;
	hwwdg.Init.EWIMode = WWDG_EWI_ENABLE;
	if (HAL_WWDG_Init(&hwwdg) != HAL_OK)
	{
		SystemManager_SetFault(WATCHDOG_RESET);
		Error_Handler();
	}
	else
	{
		/* do nothing */
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
	HAL_WWDG_Refresh(&hwwdg);
}
/***********************************************************************************
* END OF Watchdog_MainFunction											  		   *													       																	   *
************************************************************************************/
