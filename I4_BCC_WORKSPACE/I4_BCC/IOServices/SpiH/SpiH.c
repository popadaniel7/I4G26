/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Serial Peripheral Interface    *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "SpiH.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Module state variable. */
uint32 Spi_BswState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Module main function. */
VOID Spi_MainFunction();
/* Module initialization. */
StdReturnType Spi_Init();
/* Module de-initialization. */
StdReturnType Spi_DeInit();
/* Module error callback. */
//VOID HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Spi_MainFunction											 		   *
* Description: Module main function.					           				   *
************************************************************************************/
VOID Spi_MainFunction()
{
	/* Store state in local variable. */
	//uint32 localState = HAL_SPI_GetState(&hspi3);
	/* Process state. */
//	switch(localState)
//	{
//		case HAL_SPI_STATE_RESET:
//			Spi_BswState = localState;
//			Spi_Init();
//			break;
//		case HAL_SPI_STATE_READY:
//			Spi_BswState = localState;
//			break;
//		case HAL_SPI_STATE_BUSY:
//			Spi_BswState = localState;
//			break;
//		case HAL_SPI_STATE_BUSY_TX:
//			Spi_BswState = localState;
//			break;
//		case HAL_SPI_STATE_BUSY_RX:
//			Spi_BswState = localState;
//			break;
//		case HAL_SPI_STATE_BUSY_TX_RX:
//			Spi_BswState = localState;
//			break;
//		case HAL_SPI_STATE_ERROR:
//			Spi_BswState = localState;
//			HAL_SPI_ErrorCallback(&hspi3);
//			break;
//		default:
//			break;
//	}
}
/***********************************************************************************
* END OF Spi_MainFunction											  	     	   * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Spi_Init											 		 		   *
* Description: Module initialization.					           				   *
************************************************************************************/
StdReturnType Spi_Init()
{
	/* Initialize the peripheral parameters. */
//	hspi3.Instance = SPI1;
//	hspi3.Init.Mode = SPI_MODE_MASTER;
//	hspi3.Init.Direction = SPI_DIRECTION_2LINES;
//	hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
//	hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
//	hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
//	hspi3.Init.NSS = SPI_NSS_SOFT;
//	hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
//	hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
//	hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
//	hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_ENABLE;
//	hspi3.Init.CRCPolynomial = 10;
//	if (HAL_SPI_Init(&hspi3) != HAL_OK)
//	{
//		HAL_SPI_ErrorCallback(&hspi3);
//	}
//	else
//	{
//		/* do nothing */
//	}
	return E_OK;
}
/***********************************************************************************
* END OF Spi_Init											  					   * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Spi_DeInit											 		  		   *
* Description: Module de-initialization.					           			   *
************************************************************************************/
StdReturnType Spi_DeInit()
{
	//HAL_SPI_DeInit(&hspi3);
	return E_OK;
}
/***********************************************************************************
* END OF Spi_DeInit											  					   * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: HAL_SPI_ErrorCallback												   *
* Description: Module error callback.					           				   *
************************************************************************************/
//VOID HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
//{
//	/* Store the error locally. */
//	uint32 receivedStatus = HAL_SPI_GetError(hspi);
//	/* Process the error. */
//	switch(receivedStatus)
//	{
//		case HAL_SPI_ERROR_NONE:
//			/* do nothing */
//			break;
//		case HAL_SPI_ERROR_MODF:
//			SystemManager_Fault[SPI_ERROR_MODF]++;
//			Spi_DeInit();
//			Spi_Init();
//			break;
//		case HAL_SPI_ERROR_FRE:
//			SystemManager_Fault[SPI_ERROR_FRE]++;
//			HAL_SPI_Abort_IT(&hspi3);
//			break;
//		case HAL_SPI_ERROR_CRC:
//			SystemManager_Fault[SPI_ERROR_CRC]++;
//			HAL_SPI_Abort_IT(&hspi3);
//			break;
//		case HAL_SPI_ERROR_OVR:
//			SystemManager_Fault[SPI_ERROR_OVR]++;
//			HAL_SPI_Abort_IT(&hspi3);
//			break;
//		case HAL_SPI_ERROR_DMA:
//			SystemManager_Fault[SPI_ERROR_DMA]++;
//			HAL_SPI_Abort_IT(&hspi3);
//			break;
//		case HAL_SPI_ERROR_FLAG:
//			SystemManager_Fault[SPI_ERROR_FLAG]++;
//			HAL_SPI_Abort_IT(&hspi3);
//			break;
//		case HAL_SPI_ERROR_ABORT:
//			SystemManager_Fault[SPI_ERROR_ABORT]++;
//			Spi_DeInit();
//			Spi_Init();
//			break;
//		default:
//			break;
//	}
//}
/***********************************************************************************
* END OF HAL_SPI_ErrorCallback													   * 		   																	       																	   *
************************************************************************************/