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
uint8 Dem_DtcArray[8] = {STD_LOW};
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
		case DTC_LIGHT_SENSOR_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_LIGHT_SENSOR_MALFUNCTION] = DTC_LIGHT_SENSOR_MALFUNCTION;
			break;
		case DTC_VIBRATION_SENSOR_MALFUNCTION:
			Dem_DtcArray[POSITION_DTC_VIBRATION_SENSOR_MALFUNCTION] = DTC_VIBRATION_SENSOR_MALFUNCTION;
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
