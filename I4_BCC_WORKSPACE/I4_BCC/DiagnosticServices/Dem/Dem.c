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
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
#define DEM_INIT_STATE			0x00
#define DEM_DEINIT_STATE		0x02
#define DEM_PROCESSFAULT_STATE 	0x01
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Module state variable. */
uint8 Dem_BswState = STD_LOW;
/* Dtc array. */
uint8 Dem_DtcArray[93] = {STD_LOW};
/* Dtc count array. */
uint8 Dem_DtcCount[93] = {STD_LOW};
/* Data type used for fault processing in the service. */
typedef struct
{
	uint8 count;
	uint8 value;
}Dem_FaultType;
/* Array used for fault processing. */
Dem_FaultType Dem_ReceivedFaults[93] = {[0 ... 92] = {.count = STD_LOW, .value = STD_LOW}};
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
* Function: Dem_Init													           *
* Description: Initialize the module.			       							   *
************************************************************************************/
StdReturnType Dem_Init()
{
	Rte_Call_NvM_P_NvMPort_NvM_Read(1, 0, Dem_DtcArray, 96);
	Rte_Call_NvM_P_NvMPort_NvM_Read(3, 0, Dem_DtcCount, 96);
	Dem_BswState = DEM_PROCESSFAULT_STATE;
	return E_OK;
}
/***********************************************************************************
* END OF Dem_Init											  			           *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Dem_DeInit													           *
* Description: De-initialize the module. 		   							       *
************************************************************************************/
StdReturnType Dem_DeInit()
{
	Rte_Call_NvM_P_NvMPort_NvM_Write(1, 0, Dem_DtcArray, 96);
	Rte_Call_NvM_P_NvMPort_NvM_Write(3, 0, Dem_DtcCount, 96);
	return E_OK;
}
/***********************************************************************************
* END OF Dem_DeInit											  			           *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Dem_MainFunction													   *
* Description: Module main function.									 		   *
************************************************************************************/
VOID Dem_MainFunction()
{
	switch(Dem_BswState)
	{
		case DEM_INIT_STATE:
			Dem_Init();
			break;
		case DEM_DEINIT_STATE:
			Dem_DeInit();
			break;
		case DEM_PROCESSFAULT_STATE:
			Dem_ProcessFault();
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF Dem_MainFunction											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Dem_ReceiveFault													   *
* Description: Receives fault from application.							 		   *
************************************************************************************/
VOID Dem_ReceiveFault(uint8 faultValue)
{
	if(faultValue != 0)
	{
		if(Dem_ReceivedFaults[faultValue].value != faultValue)
		{
			Dem_ReceivedFaults[faultValue].value = faultValue;
			Dem_ReceivedFaults[faultValue].count = 0;
		}
		else if(Dem_ReceivedFaults[faultValue].value == faultValue)
		{
			Dem_ReceivedFaults[faultValue].count = Dem_ReceivedFaults[faultValue].count + 1;
		}
		else
		{
			/* Do nothing */
		}
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF Dem_ReceiveFault											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Dem_ProcessFault													   *
* Description: Process the fault received from the application.			 		   *
************************************************************************************/
VOID Dem_ProcessFault()
{
	for(uint8 idx = 0; idx < 96; idx++)
	{
		if(Dem_ReceivedFaults[idx].value !=  Dem_DtcArray[idx])
		{
			Dem_DtcArray[idx] = Dem_ReceivedFaults[idx].value;
		}
		else
		{
			/* do nothing */
		}

		if(Dem_DtcArray[idx] != 0)
		{
			if(Dem_DtcCount[idx] != Dem_ReceivedFaults[idx].count)
			{
				Dem_DtcCount[idx] = Dem_ReceivedFaults[idx].count;
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
	}
}
/***********************************************************************************
* END OF Dem_ProcessFault											               *													       																	   *
************************************************************************************/
