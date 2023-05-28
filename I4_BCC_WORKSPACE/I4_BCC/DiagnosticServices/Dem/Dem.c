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
#include "UartH.h"
#include <math.h>
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
STATIC char* Dem_DtcMessage = "Present DTC in the system:\n";
STATIC char* Dem_DtcLs = "Light sensor fault.\n";
STATIC char* Dem_DtcVs = "Vibration sensor fault.\n";
STATIC char* Dem_DtcPdcr = "Rear parking sensor fault.\n";
STATIC char* Dem_DtcPdcf = "Front parking sensor fault.\n";
STATIC char* Dem_DtcBt = "HC05 fault.\n";
STATIC char* Dem_DtcHw = "Hardware fault.\n";
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
	uint8 local = 0;
	uint16 msg_length = strlen(Dem_DtcMessage);
	uint16 ls_length = strlen(Dem_DtcLs);
	uint16 vs_length = strlen(Dem_DtcVs);
	uint16 pdcr_length = strlen(Dem_DtcPdcr);
	uint16 pdcf_length = strlen(Dem_DtcPdcf);
	uint16 bt_length = strlen(Dem_DtcBt);
	uint16 hw_length = strlen(Dem_DtcHw);

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

	if(Rte_P_Btc_BtcPort_Btc_ReceivedDataOnBluetooth == 90)
	{
		while(HAL_UART_Transmit_IT(&huart1, (uint8*)Dem_DtcMessage, msg_length) == HAL_BUSY);
		Rte_Runnable_Wdg_MainFunction();
		if(Dem_DtcArray[0])
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Dem_DtcLs, ls_length) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}

		if(Dem_DtcArray[1])
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Dem_DtcVs, vs_length) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}

		if(Dem_DtcArray[2])
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Dem_DtcPdcr, pdcr_length) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}

		if(Dem_DtcArray[3])
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Dem_DtcPdcf, pdcf_length) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}

		if(Dem_DtcArray[4])
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Dem_DtcBt, bt_length) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}

		if(Dem_DtcArray[5] != 0 || Dem_DtcArray[6] != 0 || Dem_DtcArray[7] != 0)
		{
			while(HAL_UART_Transmit_IT(&huart1, (uint8*)Dem_DtcHw, hw_length) == HAL_BUSY);
			Rte_Runnable_Wdg_MainFunction();
		}
		Rte_Write_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(&local);
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
