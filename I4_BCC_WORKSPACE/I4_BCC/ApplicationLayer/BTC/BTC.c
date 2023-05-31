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
#include "SystemManager.h"
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
uint8 Btc_AutomaticMode = STD_LOW;
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
		if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
		{
			if(Btc_ReceivedDataOnBluetooth >= BTC_RX_HVAC_FANVALUE_MIN &&
				Btc_ReceivedDataOnBluetooth <= BTC_RX_HVAC_FANVALUE_MAX)
			{
				Btc_FanValue = Btc_ReceivedDataOnBluetooth;
				Rte_Write_Hvac_HvacPort_Hvac_FanValue(&Btc_FanValue);
			}
			else
			{
				/* do nothing */
			}

			if(Btc_ReceivedDataOnBluetooth >= BTC_RX_HVAC_TEMPERATUREVALUE_MIN &&
					Btc_ReceivedDataOnBluetooth <= BTC_RX_HVAC_TEMPERATUREVALUE_MAX)
			{
				Btc_TemperatureValue = Btc_ReceivedDataOnBluetooth;
				Rte_Write_Hvac_HvacPort_Hvac_TemperatureValue(&Btc_TemperatureValue);
			}
			else
			{
				/* do nothing */
			}
		}
		else
		{
			/* do nothing */
		}

		/* Process the command on each case and update the respective variable. */
		switch(Btc_ReceivedDataOnBluetooth)
		{
			case BTC_RX_HVAC_LEGVENT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_LegVent = STD_HIGH;
					Rte_Write_Hvac_HvacPort_Hvac_LegVent(&Btc_LegVent);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_LEGVENT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_LegVent = STD_LOW;
					Rte_Write_Hvac_HvacPort_Hvac_LegVent(&Btc_LegVent);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_MIDVENT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_MidVent = STD_HIGH;
					Rte_Write_Hvac_HvacPort_Hvac_MidVent(&Btc_MidVent);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_MIDVENT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_MidVent = STD_LOW;
					Rte_Write_Hvac_HvacPort_Hvac_MidVent(&Btc_MidVent);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_WINDSHIELDVENT_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_WindshieldVent = STD_HIGH;
					Rte_Write_Hvac_HvacPort_Hvac_WindshieldVent(&Btc_WindshieldVent);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_WINDSHIELDVENT_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_WindshieldVent = STD_LOW;
					Rte_Write_Hvac_HvacPort_Hvac_WindshieldVent(&Btc_WindshieldVent);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_WINDSHIELDDEFROST_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_WindshieldDefrost = STD_HIGH;
					Rte_Write_Hvac_HvacPort_Hvac_WindshieldDefrost(&Btc_WindshieldDefrost);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_WINDSHIELDDEFROST_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_WindshieldDefrost = STD_LOW;
					Rte_Write_Hvac_HvacPort_Hvac_WindshieldDefrost(&Btc_WindshieldDefrost);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_REARWINDSHIELDDEFROST_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_RearWindshieldDefrost = STD_HIGH;
					Rte_Write_Hvac_HvacPort_Hvac_RearWindshieldDefrost(&Btc_RearWindshieldDefrost);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_REARWINDSHIELDDEFROST_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_RearWindshieldDefrost = STD_LOW;
					Rte_Write_Hvac_HvacPort_Hvac_RearWindshieldDefrost(&Btc_RearWindshieldDefrost);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_AC_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_Ac = STD_HIGH;
					Rte_Write_Hvac_HvacPort_Hvac_Ac(&Btc_Ac);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_AC_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_Ac = STD_LOW;
					Rte_Write_Hvac_HvacPort_Hvac_Ac(&Btc_Ac);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_RECIRCULATION:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_Recirculation = STD_HIGH;
					Btc_NoRecirculation = STD_LOW;
					Rte_Write_Hvac_HvacPort_Hvac_Recirculation(&Btc_Recirculation);
					Rte_Write_Hvac_HvacPort_Hvac_NoRecirculation(&Btc_NoRecirculation);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_NORECIRCULATION:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_Recirculation = STD_LOW;
					Btc_NoRecirculation = STD_HIGH;
					Rte_Write_Hvac_HvacPort_Hvac_Recirculation(&Btc_Recirculation);
					Rte_Write_Hvac_HvacPort_Hvac_NoRecirculation(&Btc_NoRecirculation);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_AUTOMATICMODE_ON:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_AutomaticMode = STD_HIGH;
					Rte_Write_Hvac_HvacPort_Hvac_AutomaticMode(&Btc_AutomaticMode);
				}
				else
				{
					/* do nothing */
				}
				break;
			case BTC_RX_HVAC_AUTOMATICMODE_OFF:
				if(Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH)
				{
					Btc_AutomaticMode = STD_LOW;
					Rte_Write_Hvac_HvacPort_Hvac_AutomaticMode(&Btc_AutomaticMode);
				}
				else
				{
					/* do nothing */
				}
				break;
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
