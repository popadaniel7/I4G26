#include "BTC.h"
#include "CenLoc.h"
#include "IntLights.h"
#include "ExtLights.h"
#include "usart.h"

uint8 BtcReceivedDataOnBluetooth;
uint8 BtcReceivedDataIRQ;

void BtcMainFunction();
StdReturnType BtcInit();
StdReturnType BtcRxVal();
StdReturnType BtcEnableUart();

StdReturnType BtcInit()
{

	BtcReceivedDataOnBluetooth 	= STD_LOW;
	BtcReceivedDataIRQ 			= STD_LOW;

	return E_OK;

}

StdReturnType BtcRxVal()
{

	switch(BtcReceivedDataOnBluetooth)
	{
		case BtcRxPositionZero:

			Btc_LightSwitch = BtcRxPositionZero;

			break;

		case BtcRxAutomaticLightsOn:

			Btc_LightSwitch = BtcRxAutomaticLightsOn;

			break;

		case BtcRxPositionLightsOn:

			Btc_LightSwitch = BtcRxPositionLightsOn;

			break;

		case BtcRxNightTimeLightsOn:

			Btc_LightSwitch = BtcRxNightTimeLightsOn;

			break;

		case BtcRxCenLocOn:

			Btc_CenLoc = STD_HIGH;

			break;

		case BtcRxCenLocOff:

			Btc_CenLoc = STD_LOW;

			break;

		case BtcRxHighBeamOn:

			Btc_HighBeam = STD_HIGH;

			break;

		case BtcRxHighBeamOff:

			Btc_HighBeam = STD_LOW;

			break;

		case BtcRxFlashHighBeamOn:

			Btc_FlashHighBeam = STD_HIGH;

			break;

		case BtcRxFlashHighBeamOff:

			Btc_FlashHighBeam = STD_LOW;

			break;

		case BtcRxTurnSignalLeftOn:

			Btc_TurnSignalLeft = STD_HIGH;

			break;

		case BtcRxTurnSignalLeftOff:

			Btc_TurnSignalLeft = STD_LOW;

			break;

		case BtcRxTurnSignalRightOn:

			Btc_TurnSignalRight = STD_HIGH;

			break;

		case BtcRxTurnSignalRightOff:

			Btc_TurnSignalRight = STD_LOW;

			break;

		case BtcRxHazardLightOn:

			Btc_HazardLight = STD_HIGH;

			break;

		case BtcRxHazardLightOff:

			Btc_HazardLight = STD_LOW;

			break;

		case BtcRxFogLightFrontOn:

			Btc_FrontFogLight = STD_HIGH;

			break;

		case BtcRxFogLightFrontOff:

			Btc_FrontFogLight = STD_LOW;

			break;

		case BtcRxFogLightRearOn:

			Btc_RearFogLight = STD_HIGH;

			break;

		case BtcRxFogLightRearOff:

			Btc_RearFogLight = STD_LOW;

			break;

		case BtcRxBrakeLightsOn:

			ExtLights_BrakeLight_CurrentState = STD_HIGH;

			break;

		case BtcRxBrakeLightsOff:

			ExtLights_BrakeLight_CurrentState = STD_LOW;

			break;

		case BtcRxInteriorLightsOn:

			Btc_IntLights = STD_HIGH;

			break;

		case BtcRxInteriorLightsOff:

			Btc_IntLights = STD_LOW;

			break;

		default:

			break;

	}

	return 1;

}

StdReturnType BtcEnableUart()
{

	uint8 status = STD_LOW;

	if(HAL_UART_Receive_IT(&huart1, &BtcReceivedDataOnBluetooth, 1) != E_NOT_OK)
	{
		HAL_UART_Receive_IT(&huart1, &BtcReceivedDataOnBluetooth, 1);
		status = E_OK;
	}
	else if(HAL_UART_Receive_IT(&huart1, &BtcReceivedDataOnBluetooth, 1) == E_NOT_OK)
	{
		status = E_NOT_OK;
	}
	else
	{
		/* do nothing */
	}

	return status;

}

void BtcMainFunction()
{

	BtcEnableUart();
	BtcRxVal();

//	uint8 status;
//
//	if(BtcEnableUart() == E_NOT_OK)
//	{
//
//		status = E_NOT_OK;
//
//	}
//	else if(BtcEnableUart() == E_OK)
//	{
//		BtcEnableUart();
//		status = E_OK;
//
//	}
//	else
//	{
//
//		/* do nothing */
//
//	}
//
//	if(status == E_OK)
//	{
//
//		if(BtcRxVal() == E_NOT_OK)
//		{
//
//			/* set dtc */
//
//		}
//		else if(BtcRxVal() == E_OK)
//		{
//
//			BtcRxVal();
//
//		}
//		else
//		{
//			/* do nothing */
//		}
//
//	}
//	else if(status == E_NOT_OK)
//	{
//
//		/* set dtc */
//
//	}
//	else
//	{
//
//		/* do nothing */
//
//	}

}
