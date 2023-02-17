#include "BTC.h"
#include "CenLoc.h"
#include "IntLights.h"
#include "ExtLights.h"
#include "usart.h"

uint8 BtcReceivedDataOnBluetooth;

void BtcMainFunction();
StdReturnType BtcInit();
StdReturnType BtcRxVal();
StdReturnType BtcEnableUart();

StdReturnType BtcInit()
{

	BtcReceivedDataOnBluetooth 	= STD_LOW;

	return E_OK;

}

StdReturnType BtcRxVal()
{

	switch(BtcReceivedDataOnBluetooth)
	{

		case BTC_RX_EXTLIGHTS_REVERSELIGHT_ON:

			Btc_ReverseLight = STD_HIGH;

			break;

		case BTC_RX_EXTLIGHTS_REVERSELIGHT_OFF:

			Btc_ReverseLight = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_POSITIONZERO:

			Btc_LightSwitch = BTC_RX_EXTLIGHTS_POSITIONZERO;

			break;

		case BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS:

			Btc_LightSwitch = BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS;

			break;

		case BTC_RX_EXTLIGHTS_POSITIONLIGHTS:

			Btc_LightSwitch = BTC_RX_EXTLIGHTS_POSITIONLIGHTS;

			break;

		case BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS:

			Btc_LightSwitch = BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS;

			break;

		case BTC_RX_CENLOC_ON:

			Btc_CenLoc = STD_HIGH;

			break;

		case BTC_RX_CENLOC_OFF:

			Btc_CenLoc = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_HIGBEAM_ON:

			Btc_HighBeam = STD_HIGH;

			break;

		case BTC_RX_EXTLIGHTS_HIGBEAM_OFF:

			Btc_HighBeam = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_FLASHHIGHBEAM_ON:

			Btc_FlashHighBeam = STD_HIGH;

			break;

		case BTC_RX_EXTLIGHTS_FLASHHIGHBEAM_OFF:

			Btc_FlashHighBeam = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_ON:

			Btc_TurnSignalLeft = STD_HIGH;
			Btc_TurnSignalRight = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_OFF:

			Btc_TurnSignalLeft = STD_LOW;

			break;

		case BTC_RX_ESTLIGHTS_TURNSIGNALRIGHT_ON:

			Btc_TurnSignalRight = STD_HIGH;
			Btc_TurnSignalLeft = STD_LOW;

			break;

		case BTC_RX_ESTLIGHTS_TURNSIGNALRIGHT_OFF:

			Btc_TurnSignalRight = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_HAZARDLIGHT_ON:

			Btc_HazardLight = STD_HIGH;

			break;

		case BTC_RX_EXTLIGHTS_HAZARDLIGHT_OFF:

			Btc_HazardLight = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_ON:

			Btc_FrontFogLight = STD_HIGH;

			break;

		case BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_OFF:

			Btc_FrontFogLight = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_FOGLIGHTREAR_ON:

			Btc_RearFogLight = STD_HIGH;

			break;

		case BTC_RX_EXTLIGHTS_FOGLIGHTREAR_OFF:

			Btc_RearFogLight = STD_LOW;

			break;

		case BTC_RX_EXTLIGHTS_BRAKELIGHTON:

			Btc_BrakeLight = STD_HIGH;

			break;

		case BTC_RX_EXTLIGHTS_BRAKELIGHTOFF:

			Btc_BrakeLight = STD_LOW;

			break;

		case BTC_RX_INTLIGHTS_INTERIORLIGHT_ON:

			Btc_IntLights = STD_HIGH;

			break;

		case BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF:

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

}
