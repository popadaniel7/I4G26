/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Diagnostic Event Manager	     *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Dem.h"
#include "Rte.h"
#include "SystemManager.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* DTC array. */
uint8 Dem_DtcArray[24] = {STD_LOW};
/* DTC array. */
uint8 Dem_MemDtcArray[24] = {STD_LOW};
/* Static first run variable. */
static uint8 firstRun = STD_LOW;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Module initialization. */
StdReturnType Dem_Init();
/* Module de-initialization. */
StdReturnType Dem_DeInit();
/* Module main function. */
VOID Dem_MainFunction();
/* Receive fault from application. */
VOID Dem_ReceiveFault(uint8 faultValue);
/* Process fault from application. */
VOID Dem_ProcessFault();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Dem_MainFunction													   *
* Description: Module main function.									 		   *
************************************************************************************/
VOID Dem_MainFunction()
{
	Dem_ProcessFault();
}
/***********************************************************************************
* END OF Dem_MainFunction											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Dem_ProcessFault													   *
* Description: Process fault from application.							 		   *
************************************************************************************/
VOID Dem_ProcessFault()
{
	if(firstRun == STD_LOW)
	{
		firstRun = STD_HIGH;
		for(uint8 idx = STD_LOW; idx < 24; idx++)
		{
			if(Dem_MemDtcArray[idx] >= 254)
			{
				Dem_MemDtcArray[idx] = STD_LOW;
			}
			else
			{
				/* do nothing */
			}
		}
	}
	else
	{
		/* do nothing */
	}
	if(Rte_P_ExtLights_ExtLightsPort_ExtLights_LowBeam_CurrentState == STD_LOW)
	{
		Dem_DtcArray[POSITION_DTC_LOW_BEAM_LEFT_MALFUNCTION] = STD_LOW;
		Dem_DtcArray[POSITION_DTC_LOW_BEAM_RIGHT_MALFUNCTION] = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	if(Rte_P_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState == STD_LOW)
	{
		Dem_DtcArray[POSITION_DTC_BRAKE_LIGHT_LEFT_MALFUNCTION] = STD_LOW;
		Dem_DtcArray[POSITION_DTC_BRAKE_LIGHT_RIGHT_MALFUNCTION] = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	if(Rte_P_ExtLights_ExtLightsPort_ExtLights_RearPositionLights_CurrentState == STD_LOW)
	{
		Dem_DtcArray[POSITION_DTC_REAR_POSITION_LIGHT_LEFT_MALFUNCTION] = STD_LOW;
		Dem_DtcArray[POSITION_DTC_REAR_POSITION_LIGHT_RIGHT_MALFUNCTION] = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	if(Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState == STD_LOW)
	{
		Dem_DtcArray[POSITION_DTC_LEFT_TURN_SIGNAL_FRONT_MALFUNCTION] = STD_LOW;
		Dem_DtcArray[POSITION_DTC_LEFT_TURN_SIGNAL_REAR_MALFUNCTION] = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	if(Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState == STD_LOW)
	{
		Dem_DtcArray[POSITION_DTC_RIGHT_TURN_SIGNAL_FRONT_MALFUNCTION] = STD_LOW;
		Dem_DtcArray[POSITION_DTC_RIGHT_TURN_SIGNAL_REAR_MALFUNCTION] = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	if(Rte_P_Tim_TimPort_Tim5_CalculatedDistance_ChannelFour != STD_LOW || Rte_P_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState == STD_LOW)
	{
		Dem_DtcArray[POSITION_DTC_REAR_PARKING_DISTANCE_SENSOR_MALFUNCTION] = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	if(Rte_P_Tim_TimPort_Tim5_CalculatedDistance_ChannelThree != STD_LOW || Rte_P_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState == STD_LOW)
	{
		Dem_DtcArray[POSITION_DTC_FRONT_PARKING_DISTANCE_SENSOR_MALFUNCTION] = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	for(uint8 index = POSITION_DTC_LOW_BEAM_LEFT_MALFUNCTION; index <= POSITION_DTC_PERIPHERAL_ERROR; index++)
	{
		if(Dem_MemDtcArray[index] != Dem_DtcArray[index] && Dem_DtcArray[index] >= 2)
		{
			Dem_MemDtcArray[index] = Dem_DtcArray[index];
		}
		else
		{
			/* do nothing */
		}
	}
	Rte_Read_Dem_DemPort_Dem_DtcArray(0, 0);
}
/***********************************************************************************
* END OF Dem_ProcessFault											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Dem_ReceiveFault													   *
* Description: Receives fault from application.							 		   *
************************************************************************************/
VOID Dem_ReceiveFault(uint8 faultValue)
{
	switch(faultValue)
	{
		case DTC_LOW_BEAM_LEFT_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_LOW_BEAM_LEFT_MALFUNCTION]++;
			break;
		case DTC_LOW_BEAM_RIGHT_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_LOW_BEAM_RIGHT_MALFUNCTION]++;
			break;
		case DTC_REAR_POSITION_LIGHT_LEFT_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_REAR_POSITION_LIGHT_LEFT_MALFUNCTION]++;
			break;
		case DTC_REAR_POSITION_LIGHT_RIGHT_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_REAR_POSITION_LIGHT_RIGHT_MALFUNCTION]++;
			break;
		case DTC_RIGHT_TURN_SIGNAL_FRONT_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_RIGHT_TURN_SIGNAL_FRONT_MALFUNCTION]++;
			break;
		case DTC_LEFT_TURN_SIGNAL_FRONT_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_LEFT_TURN_SIGNAL_FRONT_MALFUNCTION]++;
			break;
		case DTC_LEFT_TURN_SIGNAL_REAR_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_LEFT_TURN_SIGNAL_REAR_MALFUNCTION]++;
			break;
		case DTC_BRAKE_LIGHT_LEFT_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_BRAKE_LIGHT_LEFT_MALFUNCTION]++;
			break;
		case DTC_BRAKE_LIGHT_RIGHT_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_BRAKE_LIGHT_RIGHT_MALFUNCTION]++;
			break;
		case DTC_LIGHT_SENSOR_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_LIGHT_SENSOR_MALFUNCTION] = DTC_LIGHT_SENSOR_MALFUNCTION;
			break;
		case DTC_VIBRATION_SENSOR_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_VIBRATION_SENSOR_MALFUNCTION] = DTC_VIBRATION_SENSOR_MALFUNCTION;
			break;
		case DTC_TEMPERATURE_SENSOR_MALFUNCTION:
			Dem_DtcArray[POSITION_POSITION_DTC_TEMPERATURE_SENSOR_MALFUNCTION] = DTC_TEMPERATURE_SENSOR_MALFUNCTION;
			break;
		case DTC_REAR_PARKING_DISTANCE_SENSOR_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_REAR_PARKING_DISTANCE_SENSOR_MALFUNCTION] = DTC_REAR_PARKING_DISTANCE_SENSOR_MALFUNCTION;
			break;
		case DTC_FRONT_PARKING_DISTANCE_SENSOR_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_FRONT_PARKING_DISTANCE_SENSOR_MALFUNCTION] = DTC_FRONT_PARKING_DISTANCE_SENSOR_MALFUNCTION;
			break;
		case DTC_BLUETOOTH_MODULE_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_BLUETOOTH_MODULE_MALFUNCTION] = DTC_BLUETOOTH_MODULE_MALFUNCTION;
			break;
		case DTC_EXTERNAL_EEPROM_MODULE_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_EXTERNAL_EEPROM_MODULE_MALFUNCTION] = DTC_EXTERNAL_EEPROM_MODULE_MALFUNCTION;
			break;
		case DTC_CAN_TRANSCEIVER_MODULE_MALFUNCTION:
#if(CAN_SPI_COMMUNICATION_ENABLE == STD_ON)
			Dem_DtcArray[POSITION_DTC_CAN_TRANSCEIVER_MODULE_MALFUNCTION]++;
#endif
			break;
		case DTC_CAN_BUS_OFF:
#if(CAN_SPI_COMMUNICATION_ENABLE == STD_ON)
			Dem_DtcArray[POSITION_DTC_CAN_BUS_OFF]++;
#endif
			break;
		case DTC_LCD_MODULE_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_LCD_MODULE_MALFUNCTION] = DTC_LCD_MODULE_MALFUNCTION;
			break;
		case DTC_SOFTWARE_RESET:
			Dem_DtcArray[POSITION_DTC_SOFTWARE_RESET] = DTC_SOFTWARE_RESET;
			break;
		case DTC_HARDWARE_RESET:
			Dem_DtcArray[POSITION_DTC_HARDWARE_RESET] = DTC_HARDWARE_RESET;
			break;
		case DTC_PERIPHERAL_ERROR:
			Dem_DtcArray[POSITION_DTC_PERIPHERAL_ERROR] = DTC_PERIPHERAL_ERROR;
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF Dem_ReceiveFault											  			   *													       																	   *
************************************************************************************/
