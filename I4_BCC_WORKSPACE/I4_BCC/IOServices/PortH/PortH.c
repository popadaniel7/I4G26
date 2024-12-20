/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Port Handler 		 			 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "PortH.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Initialization function declaration. */
StdReturnType Port_Init();
/* De-initialization function declaration. */
StdReturnType Port_DeInit();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Port_Init										       				   *
* Description: Initialize the peripheral.									 	   *
************************************************************************************/
StdReturnType Port_Init()
{
	MX_GPIO_Init();
	return E_OK;
}
/***********************************************************************************
* END OF Port_Init										           				   *
************************************************************************************/
/***********************************************************************************
* Function: Port_DeInit										   					   *
* Description: De-initialize the peripheral.									   *
************************************************************************************/
StdReturnType Port_DeInit()
{
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_All);
	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_All);
	HAL_GPIO_DeInit(GPIOC, GPIO_PIN_All);
	return E_OK;
}
/***********************************************************************************
* END OF Port_DeInit										           				   *
************************************************************************************/
