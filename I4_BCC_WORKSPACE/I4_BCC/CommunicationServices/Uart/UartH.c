/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Universal Asynchronous 		 *
* 		  Receiver Transmitter 			 *
* 		  Communication Protocol Handler *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "UartH.h"
#include "stdlib.h"

#include "../../Rte/Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store UART state. */
uint32 Uart_BswState = STD_LOW;
/* Variable for the bluetooth buffer size counter. */
uint8 UartCounter_Btc_RxCount = STD_LOW;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Initialization function declaration. */
StdReturnType Uart_Init();
/* De-initialization function declaration. */
StdReturnType Uart_DeInit();
/* Protocol main function declaration .*/
VOID Uart_MainFunction();
/* Error register callback function declaration. */
VOID HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
/* Received data complete callback function declaration. */
VOID HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Uart_Init										       				   *
* Description: Initialize the protocol.									 		   *
************************************************************************************/
StdReturnType Uart_Init()
{
	/* Set the instance. */
	huart1.Instance = USART1;
	/* Set the baud rate for the protocol. */
	huart1.Init.BaudRate = 9600;
	/* Set the number of data bits transmitted or received. */
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	/* Set the number of stop bits transmitted. */
	huart1.Init.StopBits = UART_STOPBITS_1;
	/* Set the parity mode. */
	huart1.Init.Parity = UART_PARITY_NONE;
	/* Set the protocol mode. */
	huart1.Init.Mode = UART_MODE_TX_RX;
	/* Set the hardware flow control. */
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	/* Set the over sampling value. */
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	/* Call for error callback if the initialization is not performed accordingly. */
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		HAL_UART_ErrorCallback(&huart1);
	}
	else
	{
		/* do nothing */
	}
	return E_OK;
}
/***********************************************************************************
* END OF Uart_Init										           				   *
************************************************************************************/
/***********************************************************************************
* Function: Uart_DeInit										   					   *
* Description: De-initialize the protocol.									       *
************************************************************************************/
StdReturnType Uart_DeInit()
{
	/* Call for protocol de-init function. */
	HAL_UART_DeInit(&huart1);
	return E_OK;
}
/***********************************************************************************
* END OF Uart_Init										           				   *
************************************************************************************/
/***********************************************************************************
* Function: Uart_MainFunction										   			   *
* Description: Protocol main function.									           *
************************************************************************************/
VOID Uart_MainFunction()
{
	/* Get the error status in local variable. */
	uint32 localState = HAL_UART_GetState(&huart1);
	switch(localState)
	{
		case HAL_UART_STATE_RESET:
			Uart_BswState = localState;
			break;
		case HAL_UART_STATE_READY:
			/* Call for receiving data through uart for bluetooth communication. */
			HAL_UART_Receive_IT(&huart1, &Rte_P_Btc_BtcPort_Btc_RxData, 1);
			Uart_BswState = localState;
			break;
		case HAL_UART_STATE_BUSY:
			Uart_BswState = localState;
			break;
		case HAL_UART_STATE_BUSY_TX:
			Uart_BswState = localState;
			break;
		case HAL_UART_STATE_BUSY_RX:
			Uart_BswState = localState;
			break;
		case HAL_UART_STATE_BUSY_TX_RX:
			Uart_BswState = localState;
			break;
		case HAL_UART_STATE_TIMEOUT:
			Uart_BswState = localState;
			HAL_UART_ErrorCallback(&huart1);
			break;
		case HAL_UART_STATE_ERROR:
			Uart_BswState = localState;
			HAL_UART_ErrorCallback(&huart1);
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF Uart_MainFunction										                   *
************************************************************************************/
/***********************************************************************************
* Function: HAL_UART_ErrorCallback										   		   *
* Description: Process error callback.								               *
************************************************************************************/
VOID HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	/* Get error status in local variable. */
	uint32 receivedValue = HAL_UART_GetError(huart);
	/* Process each error.
	 * Store each in error in the system manager fault array.
	 * In case of DMA error re-initialize the protocol. */
	switch(receivedValue)
	{
		case HAL_UART_ERROR_NONE:
			/* do nothing */
			break;
		case HAL_UART_ERROR_PE:
			SystemManager_Fault[UART_ERROR_PE]++;
			break;
		case HAL_UART_ERROR_NE:
			SystemManager_Fault[UART_ERROR_NE]++;
			break;
		case HAL_UART_ERROR_FE:
			SystemManager_Fault[UART_ERROR_FE]++;
			break;
		case HAL_UART_ERROR_ORE:
			SystemManager_Fault[UART_ERROR_ORE]++;
			break;
		case HAL_UART_ERROR_DMA:
			SystemManager_Fault[UART_ERROR_ORE]++;
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF HAL_UART_ErrorCallback										               *
************************************************************************************/
/***********************************************************************************
* Function: HAL_UART_RxCpltCallback										           *
* Description: Process received data.									   		   *
************************************************************************************/
VOID HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/* If the UART 1 is calling the callback. */
	if(huart->Instance == USART1)
	{
		/* If the data received is not nullptr. */
		if(Rte_P_Btc_BtcPort_Btc_RxData == '\n')
		{
			/* If the buffer length counter is less than maximum value. */
			if(Rte_P_Btc_BtcPort_Btc_RxCount <= 3)
			{
				/* Convert the data received to uint8.*/
				uint8 asciiToUint = 0;
				asciiToUint = atoi((char*)Rte_P_Btc_BtcPort_Btc_DataBuffer);
				Rte_Write_Btc_BtcPort_Btc_RxData(asciiToUint);
				Rte_Write_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(Rte_P_Btc_BtcPort_Btc_RxData);
			}
			else
			{
				/* do nothing */
			}
			/* Set the counter to 0 if it is more than maximum value. */
			UartCounter_Btc_RxCount = 0;
			Rte_Write_Btc_BtcPort_Btc_RxCount(UartCounter_Btc_RxCount);
		}/* If the message was not fully processed, continue with the processing into the buffer. */
		else if(Rte_P_Btc_BtcPort_Btc_RxCount < 3)
		{
			Rte_Write_Btc_BtcPort_Btc_DataBuffer(Rte_P_Btc_BtcPort_Btc_RxData, UartCounter_Btc_RxCount);
			UartCounter_Btc_RxCount++;
		}
		else
		{
			/* Set the counter to 0 otherwise. */
			UartCounter_Btc_RxCount = 0;
			Rte_Write_Btc_BtcPort_Btc_RxCount(UartCounter_Btc_RxCount);
		}
		/* Re-enable data transmission throuhg the protocol in interrupt mode. */
		HAL_UART_Receive_IT(&huart1, &Btc_RxData, 1);
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF HAL_UART_RxCpltCallback										           *
************************************************************************************/
