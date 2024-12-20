/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Cyclic Redundancy Check		 *
* 		  Handler						 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Rte.h"
#include "CrcH.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Module state define. */
#define CRC_VERIFYUARTDATA_STATE 	0x01
/* Module state define. */
#define CRC_INITCRCVALUES_STATE	 	0x02
/* Module state define. */
#define CRC_INIT_STATE				0x00
/* Module state define. */
#define CRC_DEINIT_STATE			0x03
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store the CRC state. */
uint8 Crc_BswState;
/* Variable to store crc calculated value. */
uint32 Crc_CenLoc_On;
/* Variable to store crc calculated value. */
uint32 Crc_CenLoc_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_HighBeam_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_HighBeam_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_FlashHighBeam_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_FlashHighBeam_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_TurnSignalLeft_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_TurnSignalLeft_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_TurnSignalRight_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_TurnSignalRight_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_HazardLight_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_HazardLight_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_FogLightFront_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_FogLightFront_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_BrakeLight_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_BrakeLight_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_ReverseLight_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_ReverseLight_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_PositionZero;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_AutomaticLights;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_PositionLights;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_NightTimeLights;
/* Variable to store crc calculated value. */
uint32 Crc_IntLights_InteriorLight_On;
/* Variable to store crc calculated value. */
uint32 Crc_IntLights_InteriorLights_Off;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_FogLightRear_On;
/* Variable to store crc calculated value. */
uint32 Crc_ExtLights_FogLightRear_Off;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* CRC initialization function declaration. */
StdReturnType Crc_Init();
/* CRC de-initialization function declaration. */
StdReturnType Crc_DeInit();
/* CRC UART data check function declaration. */
StdReturnType Crc_VerifyUartData();
/* CRC main function declaration. */
VOID Crc_MainFunction();
/* CRC error callback function declaration. */
VOID HAL_CRC_ErrorCallback(CRC_HandleTypeDef *hcrc);
/* CRC UART data initialization for CRC check. */
VOID Crc_InitCrcValuesForUart();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Crc_VerifyUartData													   *
* Description: Verifies the UART data received.							 		   *
************************************************************************************/
StdReturnType Crc_VerifyUartData()
{
	/* Local variable to store return value. */
	uint8 returnValue = E_OK;
	/* Local variable to store received value. */
	uint8 receivedValue = STD_LOW;
	/* Local value to calculate CRC. */
	uint32 calculatedCrc = STD_LOW;
	/* Read the received data from UART. */
	Rte_Read_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(&receivedValue);
	Crc_BswState = CRC_VERIFYUARTDATA_STATE;
	/* Calculate the CRC. */
	calculatedCrc = HAL_CRC_Calculate(&hcrc, (uint32*)&receivedValue, 1);
	/* Check the value if it has correct CRC. */
	switch(receivedValue)
	{
		case RTE_P_BTC_RX_EXTLIGHTS_REVERSELIGHT_ON:
			if(calculatedCrc == Crc_ExtLights_ReverseLight_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_REVERSELIGHT_OFF:
			if(calculatedCrc == Crc_ExtLights_ReverseLight_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_POSITIONZERO:
			if(calculatedCrc == Crc_ExtLights_PositionZero)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS:
			if(calculatedCrc == Crc_ExtLights_AutomaticLights)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_POSITIONLIGHTS:
			if(calculatedCrc == Crc_ExtLights_PositionLights)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS:
			if(calculatedCrc == Crc_ExtLights_NightTimeLights)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_CENLOC_ON:
			if(calculatedCrc == Crc_CenLoc_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_CENLOC_OFF:
			if(calculatedCrc == Crc_CenLoc_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_HIGHBEAM_ON:
			if(calculatedCrc == Crc_ExtLights_HighBeam_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_HIGHBEAM_OFF:
			if(calculatedCrc == Crc_ExtLights_HighBeam_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_ON:
			if(calculatedCrc == Crc_ExtLights_TurnSignalLeft_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_OFF:
			if(calculatedCrc == Crc_ExtLights_TurnSignalLeft_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_ON:
			if(calculatedCrc == Crc_ExtLights_TurnSignalRight_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_OFF:
			if(calculatedCrc == Crc_ExtLights_TurnSignalRight_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_HAZARDLIGHT_ON:
			if(calculatedCrc == Crc_ExtLights_HazardLight_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_HAZARDLIGHT_OFF:
			if(calculatedCrc == Crc_ExtLights_HazardLight_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_ON:
			if(calculatedCrc == Crc_ExtLights_FogLightFront_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_OFF:
			if(calculatedCrc == Crc_ExtLights_FogLightFront_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTREAR_ON:
			if(calculatedCrc == Crc_ExtLights_FogLightRear_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTREAR_OFF:
			if(calculatedCrc == Crc_ExtLights_FogLightRear_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_BRAKELIGHTON:
			if(calculatedCrc == Crc_ExtLights_BrakeLight_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_EXTLIGHTS_BRAKELIGHTOFF:
			if(calculatedCrc == Crc_ExtLights_BrakeLight_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_INTLIGHTS_INTERIORLIGHT_ON:
			if(calculatedCrc == Crc_IntLights_InteriorLight_On)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		case RTE_P_BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF:
			if(calculatedCrc == Crc_IntLights_InteriorLights_Off)
			{
				returnValue = E_OK;
			}
			else
			{
				returnValue = E_NOT_OK;
			}
			break;
		default:
			break;
	}
	return returnValue;
}
/***********************************************************************************
* END OF Crc_VerifyUartData											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Crc_InitCrcValuesForUart									   		   *
* Description: Initialize the CRC default values for UART data.			 		   *
************************************************************************************/
VOID Crc_InitCrcValuesForUart()
{
	/* Local variable to store default value of possible
	 * received data from UART. */
	uint32 value = 0;
	/* Calculate CRC for each defined bluetooth command. */
	value = RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTREAR_ON;
	Crc_ExtLights_FogLightRear_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTREAR_OFF;
	Crc_ExtLights_FogLightRear_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_CENLOC_ON;
	Crc_CenLoc_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_CENLOC_OFF;
	Crc_CenLoc_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_HIGHBEAM_ON;
	Crc_ExtLights_HighBeam_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_HIGHBEAM_OFF;
	Crc_ExtLights_HighBeam_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_ON;
	Crc_ExtLights_TurnSignalLeft_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_OFF;
	Crc_ExtLights_TurnSignalLeft_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_ON;
	Crc_ExtLights_TurnSignalRight_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_OFF;
	Crc_ExtLights_TurnSignalRight_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_HAZARDLIGHT_ON;
	Crc_ExtLights_HazardLight_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_HAZARDLIGHT_OFF;
	Crc_ExtLights_HazardLight_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_ON;
	Crc_ExtLights_FogLightFront_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_OFF;
	Crc_ExtLights_FogLightFront_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_BRAKELIGHTON;
	Crc_ExtLights_BrakeLight_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_BRAKELIGHTOFF;
	Crc_ExtLights_BrakeLight_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_REVERSELIGHT_ON;
	Crc_ExtLights_ReverseLight_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_REVERSELIGHT_OFF;
	Crc_ExtLights_ReverseLight_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_POSITIONZERO;
	Crc_ExtLights_PositionZero = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS;
	Crc_ExtLights_AutomaticLights = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_POSITIONLIGHTS;
	Crc_ExtLights_PositionLights = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS;
	Crc_ExtLights_NightTimeLights = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_INTLIGHTS_INTERIORLIGHT_ON;
	Crc_IntLights_InteriorLight_On = HAL_CRC_Calculate(&hcrc, &value, 1);
	value = RTE_P_BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF;
	Crc_IntLights_InteriorLights_Off = HAL_CRC_Calculate(&hcrc, &value, 1);
}
/***********************************************************************************
* END OF Btc_IgnitionState											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: HAL_CRC_ErrorCallback												   *
* Description: Called in case of error. 								 		   *
************************************************************************************/
VOID HAL_CRC_ErrorCallback(CRC_HandleTypeDef *hcrc)
{
	/* Perform re-initialization. */
	Crc_DeInit();
	Crc_Init();
}
/***********************************************************************************
* END OF HAL_CRC_ErrorCallback											  		   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Crc_Init													   		   *
* Description: Initialize the peripheral.								 		   *
************************************************************************************/
StdReturnType Crc_Init()
{
	/* Initialize the CRC.
	 * Call for the error callback in case of faulty initialization. */
	hcrc.Instance = CRC;
	if (HAL_CRC_Init(&hcrc) != HAL_OK)
	{
		HAL_CRC_ErrorCallback(&hcrc);
	}
	else
	{
		/* do nothing */
	}
	/* Initialize the default CRC UART data received values. */
	Crc_InitCrcValuesForUart();
	return E_OK;
}
/***********************************************************************************
* END OF Crc_Init											  			   		   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Crc_DeInit													   		   *
* Description: De-initialize the peripheral.		 		   					   *
************************************************************************************/
StdReturnType Crc_DeInit()
{
	/* De-initialize the CRC. */
	HAL_CRC_DeInit(&hcrc);
	return E_OK;
}
/***********************************************************************************
* END OF Crc_DeInit											  			           *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Crc_MainFunction													   *
* Description: Peripheral main function.		 		   						   *
************************************************************************************/
VOID Crc_MainFunction()
{
	/* Get the error status in the local variable. */
	uint32 returnValue = HAL_CRC_GetState(&hcrc);
	/* Process module state. */
	switch(Crc_BswState)
	{
		case CRC_INIT_STATE:
			Crc_Init();
			Crc_BswState = CRC_INITCRCVALUES_STATE;
			break;
		case CRC_DEINIT_STATE:
			Crc_DeInit();
			break;
		case CRC_VERIFYUARTDATA_STATE:
			break;
		case CRC_INITCRCVALUES_STATE:
			Crc_InitCrcValuesForUart();
			Crc_BswState = CRC_VERIFYUARTDATA_STATE;
			break;
		default:
			break;
	}
	/* Process peripheral state. */
	switch(returnValue)
	{
		case HAL_CRC_STATE_RESET:
			Crc_BswState = CRC_INIT_STATE;
			break;
		case HAL_CRC_STATE_READY:
			Crc_BswState = CRC_VERIFYUARTDATA_STATE;
			break;
		case HAL_CRC_STATE_BUSY:
			break;
		case HAL_CRC_STATE_TIMEOUT:
			HAL_CRC_ErrorCallback(&hcrc);
			break;
		case HAL_CRC_STATE_ERROR:
			HAL_CRC_ErrorCallback(&hcrc);
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF Crc_MainFunction											  			   *													       																	   *
************************************************************************************/
