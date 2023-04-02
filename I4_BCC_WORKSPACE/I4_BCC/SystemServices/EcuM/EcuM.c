/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Electronic Control Unit		 *
* 		  Manager						 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "EcuM.h"
#include "AdcH.h"
#include "TimH.h"
#include "PortH.h"
#include "dma.h"
#include "CrcH.h"
#include "UartH.h"
#include "WatchdogManager.h"
#include "SystemManager.h"
#include "EcuM_Types.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store Electronic Control Unit Manager state. */
uint8 EcuM_BswState;
/* Variable to store wake up source. */
uint8 EcuM_GlobalState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Driver initialization function declaration. */
StdReturnType EcuM_DriverInit();
/* Driver de-initialization function declaration. */
StdReturnType EcuM_DriverDeInit();
/* Electronic control unit main function declaration. */
void EcuM_MainFunction();
/* Electronic control unit wake up source storing function declaration. */
void EcuM_SetWakeupSource(uint32 wakeupSource);
/* Electronic control unit wake up source processing function declaration. */
void EcuM_ProcessWakeupEvent();
/* Electronic control unit wake up source check function declaration. */
void EcuM_CheckForWakeupEvent();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: EcuM_CheckForWakeupEvent									   		   *
* Description: Checks for the wake up event and sends it forward for processing.   *
************************************************************************************/
void EcuM_CheckForWakeupEvent()
{
	/* Check if power-on reset wake-up event occurred. */
	if((PWR->CSR & RCC_CSR_PORRSTF) != 0)
	{
		/* Set the wake-up event. */
		EcuM_SetWakeupSource(ECUM_WAKEUPSOURCE_POR);
		/* Reset the flag. */
		RCC->CSR |= RCC_CSR_RMVF;
		RCC->CSR |= RCC_CSR_PORRSTF;
	}/* Check if brown-out reset wake-up event occurred.*/
	else if((PWR->CSR & RCC_CSR_BORRSTF) != 0)
	{
		/* Set the wake-up event. */
		EcuM_SetWakeupSource(ECUM_WAKEUPSOURCE_BOR);
		/* Reset the flag. */
		RCC->CSR |= RCC_CSR_RMVF;
		RCC->CSR |= RCC_CSR_BORRSTF;
	}/* Check if a software reset wake-up event occurred. */
	else if((RCC->CSR & RCC_CSR_SFTRSTF) != 0)
	{
		/* Set the wake-up event. */
		EcuM_SetWakeupSource(ECUM_WAKEUPSOURCE_SOFTWARE_RESET);
		/* Reset the flag. */
		RCC->CSR |= RCC_CSR_RMVF;
		RCC->CSR |= RCC_CSR_SFTRSTF;
	}/* Check if a windowed watchdog reset wake-up event occurred. */
	else if((RCC->CSR & RCC_CSR_WWDGRSTF) != 0)
	{
		/* Set the wake-up event. */
		EcuM_SetWakeupSource(ECUM_WAKEUPSOURCE_WINDOWED_WATCHDOG_RESET);
		/* Reset the flag. */
		RCC->CSR |= RCC_CSR_RMVF;
		RCC->CSR |= RCC_CSR_WWDGRSTF;
	}/* Check if a low power reset wake-up event occurred. */
	else if((RCC->CSR & RCC_CSR_LPWRRSTF) != 0)
	{
		/* Set the wake-up event. */
		EcuM_SetWakeupSource(ECUM_WAKEUPSOURCE_LOWPOWER_RESET);
		/* Reset the flag. */
		RCC->CSR |= RCC_CSR_RMVF;
		RCC->CSR |= RCC_CSR_LPWRRSTF;
	}/* Check if a button reset wake-up event occurred. */
	else if((RCC->CSR & RCC_CSR_PADRSTF) != 0)
	{
		/* Set the wake-up event. */
		EcuM_SetWakeupSource(ECUM_WAKEUPSOURCE_BUTTON_RESET);
		/* Reset the flag. */
		RCC->CSR |= RCC_CSR_RMVF;
		RCC->CSR |= RCC_CSR_PADRSTF;
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF EcuM_CheckForWakeupEvent											  	   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: EcuM_SetWakeupSource									   		   	   *
* Description: Sets the wake up source received.			 		   			   *
************************************************************************************/
void EcuM_SetWakeupSource(uint32 wakeupSource)
{
	/* If wake-up source is valid. */
	if(wakeupSource != NULL_PTR)
	{
		/* Store the wake-up event. */
		EcuM_GlobalState = wakeupSource;
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF EcuM_SetWakeupSource											  		   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: EcuM_ProcessWakeupEvent									   		       *
* Description: Sends forward the wake up event.							 		   *
************************************************************************************/
void EcuM_ProcessWakeupEvent()
{
	/* Store the wake-up event into local variable. */
	uint8 localWakeupEvent = EcuM_GlobalState;
	/* Set the system fault for the respective wake-up event. */
	switch(localWakeupEvent)
	{
		case ECUM_WAKEUPSOURCE_POR:
			SystemManager_SetFault(ECUM_WAKEUPSOURCE_POR);
			break;
		case ECUM_WAKEUPSOURCE_BOR:
			SystemManager_SetFault(ECUM_WAKEUPSOURCE_BOR);
			break;
		case ECUM_WAKEUPSOURCE_SOFTWARE_RESET:
			SystemManager_SetFault(ECUM_WAKEUPSOURCE_SOFTWARE_RESET);
			break;
		case ECUM_WAKEUPSOURCE_WINDOWED_WATCHDOG_RESET:
			SystemManager_SetFault(ECUM_WAKEUPSOURCE_WINDOWED_WATCHDOG_RESET);
			break;
		case ECUM_WAKEUPSOURCE_LOWPOWER_RESET:
			SystemManager_SetFault(ECUM_WAKEUPSOURCE_LOWPOWER_RESET);
			break;
		case ECUM_WAKEUPSOURCE_BUTTON_RESET:
			SystemManager_SetFault(ECUM_WAKEUPSOURCE_BUTTON_RESET);
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF EcuM_ProcessWakeupEvent											  	   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: EcuM_DriverInit									   		               *
* Description: Initialize the drivers.			 		   						   *
************************************************************************************/
StdReturnType EcuM_DriverInit()
{
	Watchdog_Init();
	Port_Init();
	MX_DMA_Init();
	Adc_Init();
	Crc_Init();
	Uart_Init();
	Tim_Init(TIMER_TWO);
	Tim_Init(TIMER_THREE);
	Tim_Init(TIMER_FOUR);
	Tim_Init(TIMER_FIVE);
	return E_OK;
}
/***********************************************************************************
* END OF EcuM_DriverInit											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: EcuM_DriverDeInit									   		           *
* Description: De-initialize the drivers.			 		                       *
************************************************************************************/
StdReturnType EcuM_DriverDeInit()
{
	Crc_DeInit();
	Uart_DeInit();
	Tim_DeInit(2);
	Tim_DeInit(3);
	Tim_DeInit(4);
	Tim_DeInit(5);
	return E_OK;
}
/***********************************************************************************
* END OF EcuM_DriverDeInit											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: EcuM_MainFunction									   		           *
* Description: Electronic control unit manager main function.			 		   *
************************************************************************************/
void EcuM_MainFunction()
{
	EcuM_CheckForWakeupEvent();
	EcuM_ProcessWakeupEvent();
}
/***********************************************************************************
* END OF EcuM_MainFunction											  			   *													       																	   *
************************************************************************************/
