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
#include "Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store the state of the application. */
uint8 Btc_ApplState;
/* Data buffer for bluetooth communication through UART. */
uint8 Btc_DataBuffer[BTC_BUFFER_SIZE] = {STD_LOW};
/* UART data received from bluetooth module. */
uint8 Btc_RxData = STD_LOW;
/* Counter for data length. */
uint8 Btc_RxCount = STD_LOW;
/* Index for positions inside the buffer. */
uint8 Btc_BufferIndex = STD_LOW;
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
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_IgnitionStepOne = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_IgnitionStepTwo;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_IgnitionTurnOff = STD_LOW;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Bluetooth communication main function declaration. */
VOID Btc_MainFunction();
/* Ignition command processing function declaration. */
VOID Btc_IgnitionState();
/* Bluetooth communication initialization for the application function declaration. */
StdReturnType Btc_Init();
/* Bluetooth communication de-initialization for the application function declaration. */
StdReturnType Btc_DeInit();
/* Bluetooth command processing function declaration. */
VOID Btc_RxVal();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Btc_DeInit													   		   *
* Description: De-initialize the bluetooth communication application.		 	   *
************************************************************************************/
StdReturnType Btc_DeInit()
{
	return E_OK;
}
/***********************************************************************************
* END OF Btc_DeInit											  			           *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Btc_IgnitionState													   *
* Description: Process bluetooth command for ignition state and process 		   *
*			   the state of the system on each state of ignition.			       *
************************************************************************************/
VOID Btc_IgnitionState()
{
	/* Check the status of the bluetooth command auxiliary variable.
	 * If the ignition state is 0 or turned off, lights should not be controlled
	 * until the ignition step one is on. */
	if(Btc_IgnitionStepOne == STD_LOW && Btc_IgnitionStepTwo == STD_LOW && Btc_IgnitionTurnOff == STD_LOW)
	{
		/* Set each respective value on off. */
		Btc_LightSwitch 		= STD_LOW;
		Btc_HighBeam 			= STD_LOW;
		Btc_FlashHighBeam 		= STD_LOW;
		Btc_FrontFogLight 		= STD_LOW;
		Btc_TurnSignalLeft 		= STD_LOW;
		Btc_TurnSignalRight 	= STD_LOW;
		Btc_HazardLight 		= STD_LOW;
		Btc_BrakeLight 			= STD_LOW;
		Btc_RearFogLight 		= STD_LOW;
		Btc_ReverseLight 		= STD_LOW;
		Btc_IntLights 			= STD_LOW;
	}
	else if(Btc_IgnitionStepOne == STD_HIGH)
	{
		/* If the ignition step one is on, then set
		 * the light switch on automatic lights
		 * follow me home concept off. */
		Btc_LightSwitch = BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS;
		Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeState(STD_LOW);
		Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF Btc_IgnitionState											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Btc_Init													   		   *
* Description: Initialize the bluetooth communication application.		 		   *
************************************************************************************/
StdReturnType Btc_Init()
{
	Btc_ReceivedDataOnBluetooth 	= STD_LOW;
	Btc_CenLoc						= STD_LOW;
	Btc_LightSwitch					= STD_LOW;
	Btc_HighBeam					= STD_LOW;
	Btc_FlashHighBeam				= STD_LOW;
	Btc_FrontFogLight				= STD_LOW;
	Btc_TurnSignalLeft				= STD_LOW;
	Btc_TurnSignalRight				= STD_LOW;
	Btc_HazardLight					= STD_LOW;
	Btc_BrakeLight					= STD_LOW;
	Btc_RearFogLight				= STD_LOW;
	Btc_ReverseLight				= STD_LOW;
	Btc_IntLights					= STD_LOW;
	Btc_IgnitionStepOne 			= STD_LOW;
	Btc_IgnitionStepTwo 			= STD_LOW;
	Btc_IgnitionTurnOff				= STD_LOW;
	return E_OK;
}
/***********************************************************************************
* END OF Btc_Init											  					   *	   																	       																	   *
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
			case BTC_RX_IGNITION_STEP_ONE:
				Btc_IgnitionStepOne = STD_HIGH;
				Btc_IgnitionStepTwo = STD_LOW;
				Btc_IgnitionTurnOff = STD_LOW;
				break;
			case BTC_RX_IGNITION_STEP_TWO:
				Btc_IgnitionStepTwo = STD_HIGH;
				Btc_IgnitionStepOne = STD_LOW;
				Btc_IgnitionTurnOff = STD_LOW;
				break;
			case BTC_RX_IGNITION_TURN_OFF:
				Btc_IgnitionStepTwo = STD_LOW;
				Btc_IgnitionStepOne = STD_LOW;
				Btc_IgnitionTurnOff = STD_HIGH;
				break;
			case BTC_RX_EXTLIGHTS_REVERSELIGHT_ON:
				Btc_ReverseLight = STD_HIGH;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(&Btc_ReverseLight);
				break;
			case BTC_RX_EXTLIGHTS_REVERSELIGHT_OFF:
				Btc_ReverseLight = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(&Btc_ReverseLight);
				break;
			case BTC_RX_EXTLIGHTS_POSITIONZERO:
				Btc_LightSwitch = BTC_RX_EXTLIGHTS_POSITIONZERO;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
				break;
			case BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS:
				Btc_LightSwitch = BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
				break;
			case BTC_RX_EXTLIGHTS_POSITIONLIGHTS:
				Btc_LightSwitch = BTC_RX_EXTLIGHTS_POSITIONLIGHTS;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
				break;
			case BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS:
				Btc_LightSwitch = BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(&Btc_LightSwitch);
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
				Btc_HighBeam = STD_HIGH;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(&Btc_HighBeam);
				break;
			case BTC_RX_EXTLIGHTS_HIGHBEAM_OFF:
				Btc_HighBeam = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(&Btc_HighBeam);
				break;
			case BTC_RX_EXTLIGHTS_FLASHHIGHBEAM_ON:
				Btc_FlashHighBeam = STD_HIGH;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_FlashHighBeam_CurrentState(&Btc_FlashHighBeam);
				break;
			case BTC_RX_EXTLIGHTS_FLASHHIGHBEAM_OFF:
				Btc_FlashHighBeam = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_FlashHighBeam_CurrentState(&Btc_FlashHighBeam);
				break;
			case BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_ON:
				Btc_TurnSignalLeft = STD_HIGH;
				Btc_TurnSignalRight = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(&Btc_TurnSignalLeft);
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(&Btc_TurnSignalRight);
				break;
			case BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_OFF:
				Btc_TurnSignalLeft = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(&Btc_TurnSignalLeft);
				break;
			case BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_ON:
				Btc_TurnSignalRight = STD_HIGH;
				Btc_TurnSignalLeft = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(&Btc_TurnSignalLeft);
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(&Btc_TurnSignalRight);
				break;
			case BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_OFF:
				Btc_TurnSignalRight = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(&Btc_TurnSignalRight);
				break;
			case BTC_RX_EXTLIGHTS_HAZARDLIGHT_ON:
				Btc_HazardLight = STD_HIGH;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(&Btc_HazardLight);
				break;
			case BTC_RX_EXTLIGHTS_HAZARDLIGHT_OFF:
				Btc_HazardLight = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(&Btc_HazardLight);
				break;
			case BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_ON:
				Btc_FrontFogLight = STD_HIGH;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(&Btc_FrontFogLight);
				break;
			case BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_OFF:
				Btc_FrontFogLight = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(&Btc_FrontFogLight);
				break;
			case BTC_RX_EXTLIGHTS_FOGLIGHTREAR_ON:
				Btc_RearFogLight = STD_HIGH;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(&Btc_RearFogLight);
				break;
			case BTC_RX_EXTLIGHTS_FOGLIGHTREAR_OFF:
				Btc_RearFogLight = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(&Btc_RearFogLight);
				break;
			case BTC_RX_EXTLIGHTS_BRAKELIGHTON:
				Btc_BrakeLight = STD_HIGH;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(&Btc_BrakeLight);
				break;
			case BTC_RX_EXTLIGHTS_BRAKELIGHTOFF:
				Btc_BrakeLight = STD_LOW;
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(&Btc_BrakeLight);
				break;
			case BTC_RX_INTLIGHTS_INTERIORLIGHT_ON:
				Btc_IntLights = STD_HIGH;
				Rte_Write_IntLights_IntLightsPort_IntLights_CurrentState(&Btc_IntLights);
				break;
			case BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF:
				Btc_IntLights = STD_LOW;
				Rte_Write_IntLights_IntLightsPort_IntLights_CurrentState(&Btc_IntLights);
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
	Btc_IgnitionState();
	Btc_RxVal();
}
/***********************************************************************************
* END OF Btc_MainFunction											  			   * 		   																	       																	   *
************************************************************************************/
