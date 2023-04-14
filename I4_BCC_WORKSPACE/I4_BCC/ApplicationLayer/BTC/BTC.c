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
uint8 Btc_ApplState = STD_LOW;
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
uint8 Btc_IgnitionStepTwo = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_IgnitionTurnOff = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_FanValue = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_TemperatureValue = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_LegVent = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_MidVent = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_WindshieldVent = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_WindshieldDefrost = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_RearWindshieldDefrost = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_Ac = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_Recirculation = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_NoRecirculation = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_AutomaticRecirculation = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_AutomaticMode = STD_LOW;
/* Auxiliary variable used for bluetooth command. */
uint8 Btc_FollowMeHome = STD_LOW;
/* Static variable for first run of main function. */
STATIC uint8 firstCall = STD_LOW;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Write into memory function declaration. */
VOID Btc_MemWrite();
/* Read from memory function declaration. */
VOID Btc_MemRead();
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
* Function: Btc_MemWrite													   	   *
* Description: Write into memory.		 	  									   *
************************************************************************************/
VOID Btc_MemWrite()
{
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 0, &Btc_CenLoc, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 1, &Btc_LightSwitch, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 2, &Btc_HighBeam, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 3, &Btc_FrontFogLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 4, &Btc_TurnSignalLeft, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 5, &Btc_TurnSignalRight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 6, &Btc_HazardLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 7, &Btc_BrakeLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 8, &Btc_RearFogLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 9, &Btc_ReverseLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 10, &Btc_IntLights, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 11, &Btc_IgnitionStepOne, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 12, &Btc_IgnitionStepTwo, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 13, &Btc_IgnitionTurnOff, 1);
}
/***********************************************************************************
* END OF Btc_MemWrite											  			       *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Btc_MemRead													   		   *
* Description: Read from memory.		 	   										   *
************************************************************************************/
VOID Btc_MemRead()
{
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 0, &Btc_CenLoc, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 1, &Btc_LightSwitch, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 2, &Btc_HighBeam, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 3, &Btc_FrontFogLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 4, &Btc_TurnSignalLeft, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 5, &Btc_TurnSignalRight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 6, &Btc_HazardLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 7, &Btc_BrakeLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 8, &Btc_RearFogLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 9, &Btc_ReverseLight, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 10, &Btc_IntLights, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 11, &Btc_IgnitionStepOne, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 12, &Btc_IgnitionStepTwo, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 13, &Btc_IgnitionTurnOff, 1);
}
/***********************************************************************************
* END OF Btc_MemRead											  			       *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Btc_DeInit													   		   *
* Description: De-initialize the bluetooth communication application.		 	   *
************************************************************************************/
StdReturnType Btc_DeInit()
{
	/* Perform write all in memory for all the important variables in this appl. */
	Btc_MemWrite();
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
	if(Btc_IgnitionStepOne == STD_LOW
			&& Btc_IgnitionStepTwo == STD_LOW
			&& Btc_IgnitionTurnOff == STD_LOW
			&& Btc_CenLoc == STD_LOW)
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
	Btc_ApplState = BTC_RX_STATE;
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
		if(Btc_ReceivedDataOnBluetooth >= BTC_RX_HVAC_FANVALUE_MIN &&
			Btc_ReceivedDataOnBluetooth <= BTC_RX_HVAC_FANVALUE_MAX)
		{
			Btc_FanValue = Btc_ReceivedDataOnBluetooth - 30;
			Rte_Write_Hvac_HvacPort_Hvac_FanValue(&Btc_FanValue);
		}
		else
		{
			/* do nothing */
		}

		if(Btc_ReceivedDataOnBluetooth >= BTC_RX_HVAC_TEMPERATUREVALUE_MIN &&
				Btc_ReceivedDataOnBluetooth <= BTC_RX_HVAC_TEMPERATUREVALUE_MAX)
		{
			Btc_TemperatureValue = Btc_ReceivedDataOnBluetooth - 22;
			Rte_Write_Hvac_HvacPort_Hvac_TemperatureValue(&Btc_TemperatureValue);
		}
		else
		{
			/* do nothing */
		}
		/* Process the command on each case and update the respective variable. */
		switch(Btc_ReceivedDataOnBluetooth)
		{
			case BTC_RX_CENLOC_FOLLOWMEHOME:
				Btc_FollowMeHome = STD_HIGH;
				Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeState((uint8*)STD_HIGH);
				break;
			case BTC_RX_HVAC_LEGVENT_ON:
				Btc_LegVent = STD_HIGH;
				Rte_Write_Hvac_HvacPort_Hvac_LegVent(&Btc_LegVent);
				break;
			case BTC_RX_HVAC_LEGVENT_OFF:
				Btc_LegVent = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_LegVent(&Btc_LegVent);
				break;
			case BTC_RX_HVAC_MIDVENT_ON:
				Btc_MidVent = STD_HIGH;
				Rte_Write_Hvac_HvacPort_Hvac_MidVent(&Btc_MidVent);
				break;
			case BTC_RX_HVAC_MIDVENT_OFF:
				Btc_MidVent = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_MidVent(&Btc_MidVent);
				break;
			case BTC_RX_HVAC_WINDSHIELDVENT_ON:
				Btc_WindshieldVent = STD_HIGH;
				Rte_Write_Hvac_HvacPort_Hvac_WindshieldVent(&Btc_WindshieldVent);
				break;
			case BTC_RX_HVAC_WINDSHIELDVENT_OFF:
				Btc_WindshieldVent = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_WindshieldVent(&Btc_WindshieldVent);
				break;
			case BTC_RX_HVAC_WINDSHIELDDEFROST_ON:
				Btc_WindshieldDefrost = STD_HIGH;
				Rte_Write_Hvac_HvacPort_Hvac_WindshieldDefrost(&Btc_WindshieldDefrost);
				break;
			case BTC_RX_HVAC_WINDSHIELDDEFROST_OFF:
				Btc_WindshieldDefrost = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_WindshieldDefrost(&Btc_WindshieldDefrost);
				break;
			case BTC_RX_HVAC_REARWINDSHIELDDEFROST_ON:
				Btc_RearWindshieldDefrost = STD_HIGH;
				Rte_Write_Hvac_HvacPort_Hvac_RearWindshieldDefrost(&Btc_RearWindshieldDefrost);
				break;
			case BTC_RX_HVAC_REARWINDSHIELDDEFROST_OFF:
				Btc_RearWindshieldDefrost = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_RearWindshieldDefrost(&Btc_RearWindshieldDefrost);
				break;
			case BTC_RX_HVAC_AC_ON:
				Btc_Ac = STD_HIGH;
				Rte_Write_Hvac_HvacPort_Hvac_Ac(&Btc_Ac);
				break;
			case BTC_RX_HVAC_AC_OFF:
				Btc_Ac = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_Ac(&Btc_Ac);
				break;
			case BTC_RX_HVAC_RECIRCULATION:
				Btc_Recirculation = STD_HIGH;
				Btc_NoRecirculation = STD_LOW;
				Btc_AutomaticRecirculation = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_Recirculation(&Btc_Recirculation);
				Rte_Write_Hvac_HvacPort_Hvac_NoRecirculation(&Btc_NoRecirculation);
				Rte_Write_Hvac_HvacPort_Hvac_AutomaticRecirculation(&Btc_AutomaticRecirculation);
				break;
			case BTC_RX_HVAC_NORECIRCULATION:
				Btc_Recirculation = STD_LOW;
				Btc_NoRecirculation = STD_HIGH;
				Btc_AutomaticRecirculation = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_Recirculation(&Btc_Recirculation);
				Rte_Write_Hvac_HvacPort_Hvac_NoRecirculation(&Btc_NoRecirculation);
				Rte_Write_Hvac_HvacPort_Hvac_AutomaticRecirculation(&Btc_AutomaticRecirculation);
				break;
			case BTC_RX_HVAC_AUTOMATICRECIRCULATION:
				Btc_Recirculation = STD_LOW;
				Btc_NoRecirculation = STD_LOW;
				Btc_AutomaticRecirculation = STD_HIGH;
				Rte_Write_Hvac_HvacPort_Hvac_Recirculation(&Btc_Recirculation);
				Rte_Write_Hvac_HvacPort_Hvac_NoRecirculation(&Btc_NoRecirculation);
				Rte_Write_Hvac_HvacPort_Hvac_AutomaticRecirculation(&Btc_AutomaticRecirculation);
				break;
			case BTC_RX_HVAC_AUTOMATICMODE_ON:
				Btc_AutomaticMode = STD_HIGH;
				Rte_Write_Hvac_HvacPort_Hvac_AutomaticMode(&Btc_AutomaticMode);
				break;
			case BTC_RX_HVAC_AUTOMATICMODE_OFF:
				Btc_AutomaticMode = STD_LOW;
				Rte_Write_Hvac_HvacPort_Hvac_AutomaticMode(&Btc_AutomaticMode);
				break;
			case BTC_RX_IGNITION_STEP_ONE:
				Btc_ApplState = BTC_IGNITION_PROCESSING_STATE;
				Btc_IgnitionStepOne = STD_HIGH;
				Btc_IgnitionStepTwo = STD_LOW;
				Btc_IgnitionTurnOff = STD_LOW;
				break;
			case BTC_RX_IGNITION_STEP_TWO:
				Btc_ApplState = BTC_IGNITION_PROCESSING_STATE;
				Btc_IgnitionStepTwo = STD_HIGH;
				Btc_IgnitionStepOne = STD_LOW;
				Btc_IgnitionTurnOff = STD_LOW;
				break;
			case BTC_RX_IGNITION_TURN_OFF:
				Btc_ApplState = BTC_IGNITION_PROCESSING_STATE;
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
	/* Process given state. */
	switch(Btc_ApplState)
	{
		case BTC_INIT_STATE:
			Btc_Init();
			if(firstCall == STD_LOW)
			{
				firstCall = STD_HIGH;
				Btc_MemRead();
			}
			else
			{
				/* do nothing */
			}
			Btc_ApplState = BTC_RX_STATE;
			break;
		case BTC_DEINIT_STATE:
			Btc_DeInit();
			break;
		case BTC_RX_STATE:
			Btc_RxVal();
			break;
		case BTC_IGNITION_PROCESSING_STATE:
			Btc_IgnitionState();
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF Btc_MainFunction											  			   * 		   																	       																	   *
************************************************************************************/
