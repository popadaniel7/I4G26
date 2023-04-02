/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Analog to Digital Converter    *
* 		  Handler                        *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "AdcH.h"
#include "SystemManager_Types.h"
#include "Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store ADC state. */
uint8 Adc_BswState;
/* ADC buffer for channel one. */
uint32 Adc_ChannelOne_Buffer[ADC_BUFFER_LENGTH];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Peripheral initialization function declaration. */
StdReturnType Adc_Init();
/* Peripheral de-initialization function declaration. */
StdReturnType Adc_DeInit();
/* Peripheral main function declaration. */
void Adc_MainFunction();
/* Peripheral error callback function declaration. */
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: HAL_ADC_ErrorCallback										   		   *
* Description: Error callback to process fault in the peripheral.		 		   *
************************************************************************************/
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
	/* Local variable to store error status. */
	uint32 receivedStatus = HAL_ADC_GetError(&hadc1);
	/* Process error status.
	 * Perform re-initialization on each error to prevent faults in the peripheral. */
	switch(receivedStatus)
	{
		case HAL_ADC_ERROR_NONE:
			/* do nothing */
			break;
		case HAL_ADC_ERROR_INTERNAL:
			SystemManager_Fault[ADC_ERROR_INTERNAL] = ADC_ERROR_INTERNAL;
			Adc_DeInit();
			Adc_Init();
			break;
		case HAL_ADC_ERROR_OVR:
			SystemManager_Fault[ADC_ERROR_OVR] = ADC_ERROR_OVR;
			Adc_DeInit();
			Adc_Init();
			break;
		case HAL_ADC_ERROR_DMA:
			SystemManager_Fault[ADC_ERROR_DMA] = ADC_ERROR_DMA;
			Adc_DeInit();
			Adc_Init();
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF HAL_ADC_ErrorCallback										           	   *
************************************************************************************/
/***********************************************************************************
* Function: Adc_MainFunction										   			   *
* Description: Peripheral main function.									       *
************************************************************************************/
void Adc_MainFunction()
{
	/* Local variable to store the error status. */
	uint32 statusValue = STD_LOW;
	/* Get error status. */
	statusValue = HAL_ADC_GetState(&hadc1);
	/* Report to the error callback in case of error. */
	if(statusValue == HAL_ADC_STATE_ERROR)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Keep the ADC conversion on. */
	HAL_ADC_Start_DMA(&hadc1, Adc_ChannelOne_Buffer, ADC_BUFFER_LENGTH);
}
/***********************************************************************************
* END OF Adc_MainFunction										           		   *
************************************************************************************/
/***********************************************************************************
* Function: Adc_DeInit										   					   *
* Description: De-initialize the peripheral.									   *
************************************************************************************/
StdReturnType Adc_DeInit()
{
	/* Call for de-intialization function. */
	HAL_ADC_DeInit(&hadc1);
	return E_OK;
}
/***********************************************************************************
* END OF Adc_DeInit										           				   *
************************************************************************************/
/***********************************************************************************
* Function: Adc_Init										   					   *
* Description: Initialize the protocol.									       	   *
************************************************************************************/
StdReturnType Adc_Init()
{

	/* Local variable for ADC configuration. */
	ADC_ChannelConfTypeDef sConfig = {0};
	/* Set the channel. */
	hadc1.Instance = ADC1;
	/* Set the clock pre-scaler. */
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	/* Set the resolution. */
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	/* Set the scan conversion mode on or off. */
	hadc1.Init.ScanConvMode = ENABLE;
	/* Set the continuos conversion mode. */
	hadc1.Init.ContinuousConvMode = ENABLE;
	/* Set the discontinuous conversion mode. */
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	/* Set the external trigger polarity and enable the trigger of a regular group. */
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	/* Set the external trigger conversion. */
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	/* Set the data alignment. */
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	/* Set the number of inputs. */
	hadc1.Init.NbrOfConversion = 16;
	/* Set the DMA request. */
	hadc1.Init.DMAContinuousRequests = DISABLE;
	/* Set the end of conversion type. */
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_Init(&hadc1) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_1;
	sConfig.Rank = 2;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_4;
	sConfig.Rank = 5;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_5;
	sConfig.Rank = 6;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_6;
	sConfig.Rank = 7;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_7;
	sConfig.Rank = 8;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_8;
	sConfig.Rank = 9;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_9;
	sConfig.Rank = 10;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_10;
	sConfig.Rank = 11;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_11;
	sConfig.Rank = 12;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_12;
	sConfig.Rank = 13;
	/* Call the error callback in case of inadequate initialization. */
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_13;
	sConfig.Rank = 14;
	/* Call the error callback in case of inadequate initialization. */
	if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_14;
	sConfig.Rank = 15;
	/* Call the error callback in case of inadequate initialization. */
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	/* Configure the channel. */
	sConfig.Channel = ADC_CHANNEL_15;
	sConfig.Rank = 16;
	/* Call the error callback in case of inadequate initialization. */
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		HAL_ADC_ErrorCallback(&hadc1);
	}
	else
	{
		/* do nothing */
	}
	return E_OK;
}
/***********************************************************************************
* END OF Adc_Init										           				   *
************************************************************************************/
