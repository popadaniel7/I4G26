/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Bluetooth Communication	     *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Btc.h"
#include "UartH.h"
#include "SystemManager.h"
#include "Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Data buffer for bluetooth communication through UART. */
uint8 Btc_DataBuffer[BTC_BUFFER_SIZE] = {STD_LOW};
/* UART data received from bluetooth module. */
uint8 Btc_RxData = STD_LOW;
/* Counter for data length. */
uint8 Btc_RxCount = STD_LOW;
/* Bluetooth command converted into uint8. */
uint8 Btc_ReceivedDataOnBluetooth = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_CenLoc = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_LightSwitch = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_HighBeam = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_FlashHighBeam = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_FrontFogLight = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_TurnSignalLeft = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_TurnSignalRight = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_HazardLight = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_BrakeLight = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_RearFogLight = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_ReverseLight = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_IntLights = STD_LOW;
/* Diagnostic messages through HC-05. */
STATIC char* Btc_DtcMessage = "Present DTC in the system:\n";
/* Diagnostic messages through HC-05. */
STATIC uint16 Btc_DtcMessageLength = STD_LOW;
/* Diagnostic messages through HC-05. */
STATIC char* Btc_DtcLightSensor = "Light sensor fault.\n";
/* Diagnostic messages through HC-05. */
STATIC char* Btc_DtcVibrationSensor = "Vibration sensor fault.\n";
/* Diagnostic messages through HC-05. */
STATIC char* Btc_DtcRearParkingSensor = "Rear parking sensor fault.\n";
/* Diagnostic messages through HC-05. */
STATIC char* Btc_DtcFrontParkingSensor = "Front parking sensor fault.\n";
/* Diagnostic messages through HC-05. */
STATIC char* Btc_DtcHardware = "Hardware fault.\n";
/* Diagnostic messages through HC-05. */
STATIC char* Btc_DtcBtc = "HC-05 fault.\n";
/* Diagnostic messages through HC-05. */
STATIC uint16 Btc_DtcDescriptionLength1 = STD_LOW;
/* Diagnostic messages through HC-05. */
STATIC uint16 Btc_DtcDescriptionLength2 = STD_LOW;
/* Diagnostic messages through HC-05. */
STATIC uint16 Btc_DtcDescriptionLength3 = STD_LOW;
/* Diagnostic messages through HC-05. */
STATIC uint16 Btc_DtcDescriptionLength4 = STD_LOW;
/* Diagnostic messages through HC-05. */
STATIC uint16 Btc_DtcDescriptionLength5 = STD_LOW;
/* Diagnostic messages through HC-05. */
STATIC uint16 Btc_DtcDescriptionLength6 = STD_LOW;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Bluetooth communication main function declaration. */
VOID Btc_MainFunction();
/* Request command processing function declaration. */
VOID Btc_RequestState();
/* Bluetooth command processing function declaration. */
VOID Btc_RxVal();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Btc_RequestState													   *
* Description: Process bluetooth command for request state 					       *
************************************************************************************/
VOID Btc_RequestState()
{
	if(Btc_ReceivedDataOnBluetooth == 99)
	{
		SystemManager_PerformReset();
	}
	else
	{
		/* do nothing */
	}
	if(Btc_ReceivedDataOnBluetooth == 90)
	{
		Btc_DtcMessageLength = strlen(Btc_DtcMessage);
		HAL_UART_Transmit_IT(&huart1, (uint8*)Btc_DtcMessage, Btc_DtcMessageLength);
		Btc_DtcDescriptionLength1 = strlen(Btc_DtcLightSensor);
		Btc_DtcDescriptionLength2 = strlen(Btc_DtcVibrationSensor);
		Btc_DtcDescriptionLength3 = strlen(Btc_DtcRearParkingSensor);
		Btc_DtcDescriptionLength4 = strlen(Btc_DtcFrontParkingSensor);
		Btc_DtcDescriptionLength5 = strlen(Btc_DtcHardware);
		Btc_DtcDescriptionLength6 = strlen(Btc_DtcBtc);
		if(Dem_DtcArray[4] != 0)
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Btc_DtcBtc, Btc_DtcDescriptionLength6) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}
		else
		{
			/* do nothing */
		}


		if(Dem_DtcArray[0] != 0)
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Btc_DtcLightSensor, Btc_DtcDescriptionLength1) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}
		else
		{
			/* do nothing */
		}
		if(Dem_DtcArray[1] != 0)
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Btc_DtcVibrationSensor, Btc_DtcDescriptionLength2) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}
		else
		{
			/* do nothing */
		}

		if(Dem_DtcArray[2] != 0)
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Btc_DtcRearParkingSensor, Btc_DtcDescriptionLength3) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}
		else
		{
			/* do nothing */
		}
		if(Dem_DtcArray[3] != 0)
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Btc_DtcFrontParkingSensor, Btc_DtcDescriptionLength4) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}
		else
		{
			/* do nothing */
		}

		if(Dem_DtcArray[5] != 0 || Dem_DtcArray[6] != 0 || Dem_DtcArray[7] != 0)
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Btc_DtcHardware, Btc_DtcDescriptionLength5) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}
		else
		{
			/* do nothing */
		}
		Rte_Runnable_Wdg_MainFunction();
		Btc_ReceivedDataOnBluetooth = 0;
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF Btc_RequestState											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Btc_RxVal													   		   *
* Description: Process bluetooth commands.	 		   							   *
************************************************************************************/
VOID Btc_RxVal()
{
	if(Rte_Call_Crc_R_CrcPort_Crc_VerifyUartData() == E_OK)
	{

		/* Process the command on each case and update the respective variable. */
		switch(Btc_ReceivedDataOnBluetooth)
		{
			case BTC_RX_EXTLIGHTS_REVERSELIGHT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_ReverseLight = STD_HIGH;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(&Btc_ReverseLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_REVERSELIGHT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_ReverseLight = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(&Btc_ReverseLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_POSITIONZERO:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_LightSwitch = BTC_RX_EXTLIGHTS_POSITIONZERO;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_LightSwitch = BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_POSITIONLIGHTS:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_LightSwitch = BTC_RX_EXTLIGHTS_POSITIONLIGHTS;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_LightSwitch = BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_CENLOC_ON:
				Btc_CenLoc = STD_HIGH;
				Rte_Write_CenLoc_CenLocPort_CenLoc_CurrentState(&Btc_CenLoc);
				break;
			case BTC_RX_CENLOC_OFF:
				Btc_CenLoc = STD_LOW;
				Rte_Write_CenLoc_CenLocPort_CenLoc_CurrentState(&Btc_CenLoc);
				break;
			case BTC_RX_EXTLIGHTS_HIGHBEAM_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_HighBeam = STD_HIGH;
					Btc_FlashHighBeam = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(&Btc_HighBeam);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_HIGHBEAM_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_HighBeam = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(&Btc_HighBeam);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_TurnSignalLeft = STD_HIGH;
					Btc_TurnSignalRight = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(&Btc_TurnSignalLeft);
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(&Btc_TurnSignalRight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_TurnSignalLeft = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(&Btc_TurnSignalLeft);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_TurnSignalRight = STD_HIGH;
					Btc_TurnSignalLeft = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(&Btc_TurnSignalLeft);
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(&Btc_TurnSignalRight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_TurnSignalRight = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(&Btc_TurnSignalRight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_HAZARDLIGHT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_HazardLight = STD_HIGH;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(&Btc_HazardLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_HAZARDLIGHT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_HazardLight = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(&Btc_HazardLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_FrontFogLight = STD_HIGH;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(&Btc_FrontFogLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_FrontFogLight = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(&Btc_FrontFogLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_FOGLIGHTREAR_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_RearFogLight = STD_HIGH;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(&Btc_RearFogLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_FOGLIGHTREAR_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_RearFogLight = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(&Btc_RearFogLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_BRAKELIGHTON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_BrakeLight = STD_HIGH;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(&Btc_BrakeLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_EXTLIGHTS_BRAKELIGHTOFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_BrakeLight = STD_LOW;
					Rte_Write_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(&Btc_BrakeLight);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_INTLIGHTS_INTERIORLIGHT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_IntLights = STD_HIGH;
					Rte_Write_IntLights_IntLightsPort_IntLights_CurrentState(&Btc_IntLights);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_IntLights = STD_LOW;
					Rte_Write_IntLights_IntLightsPort_IntLights_CurrentState(&Btc_IntLights);
				}
				else
				{
					/* do nothing */
				}
				break;
			default:
				break;
		}
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF Btc_RxVal											  					   * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Btc_MainFunction											 		   *
* Description: Process bluetooth communication states.					           *
************************************************************************************/
VOID Btc_MainFunction()
{
	Btc_RxVal();
	Btc_RequestState();
}
/***********************************************************************************
* END OF Btc_MainFunction											  			   * 		   																	       																	   *
************************************************************************************/
