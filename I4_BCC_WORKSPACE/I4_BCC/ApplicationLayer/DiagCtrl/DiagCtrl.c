/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Diagnostic Control	         *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "DiagCtrl.h"
#include "Rte.h"
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
/* Request value processing variable. */
uint8 DiagCtrl_RequestValue = STD_LOW;
/* Fault value variable. */
uint8 DiagCtrl_FaultValue = STD_LOW;
/* Application state variable. */
uint8 DiagCtrl_ApplState = STD_LOW;
/* Data type used for fault analysis. */
typedef struct
{
	uint8 counterValue;
	uint8 statusValue;
	uint8 processedCounterValue;
}DiagCtrl_ProcessedDataType;
/* Array used for fault analysis. */
DiagCtrl_ProcessedDataType DiagCtrl_ProcessedRequestArray[20] = {STD_LOW};
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Initialization function declaration. */
StdReturnType DiagCtrl_Init();
/* De-initialization function declaration. */
StdReturnType DiagCtrl_DeInit();
/* Main function declaration. */
VOID DiagCtrl_MainFunction();
/* Process requested data function declaration. */
VOID DiagCtrl_ProcessRequestedData();
/* Send processed data function declaration. */
VOID DiagCtrl_SendProcessedData();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: DiagCtrl_Init										   		   		   *
* Description: Application initialization.		 		   						   *
************************************************************************************/
StdReturnType DiagCtrl_Init()
{
	DiagCtrl_RequestValue 	= STD_LOW;
	DiagCtrl_FaultValue 	= STD_LOW;
	DiagCtrl_ApplState 		= DIAGCTRL_PROCESSDATA_STATE;
	return E_OK;
}
/***********************************************************************************
* END OF DiagCtrl_Init										                       *
************************************************************************************/
/***********************************************************************************
* Function: DiagCtrl_DeInit										   		   		   *
* Description: Application de-initialization.		 		   					   *
************************************************************************************/
StdReturnType DiagCtrl_DeInit()
{
	return E_OK;
}
/***********************************************************************************
* END OF DiagCtrl_DeInit										                   *
************************************************************************************/
/***********************************************************************************
* Function: DiagCtrl_MainFunction										   		   *
* Description: Application main function.		 		   						   *
************************************************************************************/
VOID DiagCtrl_MainFunction()
{
	switch(DiagCtrl_ApplState)
	{
		case DIAGCTRL_INIT_STATE:
			DiagCtrl_Init();
			break;
		case DIAGCTRL_DEINIT_STATE:
			DiagCtrl_DeInit();
			break;
		case DIAGCTRL_PROCESSDATA_STATE:
			DiagCtrl_ProcessRequestedData();
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF DiagCtrl_MainFunction										               *
************************************************************************************/
/***********************************************************************************
* Function: DiagCtrl_ProcessRequestedData										   *
* Description: Process the measured requested data.		 		   				   *
************************************************************************************/
VOID DiagCtrl_ProcessRequestedData()
{
	static uint32 localValueOne = 0;
	static uint32 localValueTwo = 0;
	static uint32 localValueThree = 0;
	static uint32 localValueFour = 0;
	Rte_Read_Adc_AdcPort_Adc_ChannelOne_Buffer(&localValueOne, 0x00);
	Rte_Read_Adc_AdcPort_Adc_ChannelOne_Buffer(&localValueTwo, 0x01);
	Rte_Read_Adc_AdcPort_Adc_ChannelOne_Buffer(&localValueThree, 0x02);
	Rte_Read_Adc_AdcPort_Adc_ChannelOne_Buffer(&localValueFour, 0x03);
	/* LS fault. */
	if(localValueOne < 100)
	{
		Rte_Call_Dem_P_DemPort_Dem_ReceiveFault(70);
	}
	else
	{
		/* do nothing */
	}
	/* VS Fault*/
	if(localValueTwo < 100)
	{
		Rte_Call_Dem_P_DemPort_Dem_ReceiveFault(71);
	}
	else
	{
		/* do nothing */
	}
	/* AQS Fault */
	if(localValueThree < 100)
	{
		Rte_Call_Dem_P_DemPort_Dem_ReceiveFault(92);
	}
	else
	{
		/* do nothing */
	}
	/* TS Fault */
	if(localValueFour < 100)
	{
		Rte_Call_Dem_P_DemPort_Dem_ReceiveFault(93);
	}
	else
	{
		/* do nothing */
	}
	/* PDCF Fault */
	if(Rte_P_Tim_TimPort_Tim5_CalculatedDistance_ChannelThree == 0)
	{
		Rte_Call_Dem_P_DemPort_Dem_ReceiveFault(90);
	}
	else
	{
		/* do nothing */
	}
	/* PDCR Fault */
	if(Rte_P_Tim_TimPort_Tim5_CalculatedDistance_ChannelFour == 0)
	{
		Rte_Call_Dem_P_DemPort_Dem_ReceiveFault(91);
	}
	else
	{
		/* do nothing */
	}
	/* Check through all the possible request. */
	for(uint8 index = DIAGCTRL_LB_L_REQUEST; index <= DIAGCTRL_RTS_F_REQUEST; index++)
	{
		/* Call for the request. */
		Rte_Call_SenCtrl_P_SenCtrlPort_SenCtrl_ProcessSensorValue(index);
		/* If the request is set. */
		if(DiagCtrl_RequestValue != 0x00)
		{
			/* Check through all the possible states. */
			for(uint8 idx = DIAGCTRL_LB_L_UV; idx <= DIAGCTRL_RTS_F_SH; idx++)
			{
				/* If a state is set, count how many times it shows up. */
				if(DiagCtrl_ProcessedRequestArray[idx].counterValue != DiagCtrl_FaultValue && DiagCtrl_ProcessedRequestArray[idx].counterValue < 3)
				{
					DiagCtrl_ProcessedRequestArray[idx].counterValue = DiagCtrl_ProcessedRequestArray[idx].counterValue + 1;
				}
				else
				{
					/* do nothing */
				}
				/* If it showed enough times, set the status value with the fault value. */
				if(DiagCtrl_ProcessedRequestArray[idx].counterValue == 3)
				{
					if(DiagCtrl_ProcessedRequestArray[idx].statusValue != DiagCtrl_FaultValue)
					{
						DiagCtrl_ProcessedRequestArray[idx].statusValue = DiagCtrl_FaultValue + 55;
						DiagCtrl_ProcessedRequestArray[idx].counterValue = 0;
						DiagCtrl_ProcessedRequestArray[idx].processedCounterValue = 0;
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
		else
		{
			/* do nothing */
		}
		/* If the functionality checked is not turned on, then set the status value to 0. */
		if(Rte_P_ExtLights_ExtLightsPort_ExtLights_LowBeam_CurrentState == STD_LOW)
		{
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LB_L_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LB_L_SH].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LB_R_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LB_R_SH].statusValue = 0;
		}
		else
		{
			/* do nothing */
		}
		/* If the functionality checked is not turned on, then set the status value to 0. */
		if(Rte_P_ExtLights_ExtLightsPort_ExtLights_RearPositionLights_CurrentState == STD_LOW)
		{
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RPL_L_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RPL_L_SH].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RPL_R_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RPL_R_SH].statusValue = 0;
		}
		else
		{
			/* do nothing */
		}
		/* If the functionality checked is not turned on, then set the status value to 0. */
		if(Rte_P_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState == STD_LOW)
		{
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_BL_R_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_BL_R_SH].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_BL_L_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_BL_L_SH].statusValue = 0;
		}
		else
		{
			/* do nothing */
		}
		/* If the functionality checked is not turned on, then set the status value to 0. */
		if(Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState == STD_LOW)
		{
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LTS_F_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LTS_F_SH].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LTS_R_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LTS_R_SH].statusValue = 0;
		}
		else
		{
			/* do nothing */
		}
		/* If the functionality checked is not turned on, then set the status value to 0. */
		if(Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState == STD_LOW)
		{
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RTS_F_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RTS_F_SH].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RTS_R_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RTS_R_SH].statusValue = 0;
		}
		else
		{
			/* do nothing */
		}
		/* If the functionality checked is not turned on, then set the status value to 0. */
		if(Rte_P_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState == STD_LOW &&
				Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState == STD_LOW &&
				Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState == STD_LOW)
		{
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LTS_F_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LTS_F_SH].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LTS_R_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_LTS_R_SH].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RTS_F_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RTS_F_SH].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RTS_R_UV].statusValue = 0;
			DiagCtrl_ProcessedRequestArray[DIAGCTRL_RTS_R_SH].statusValue = 0;
		}
		else
		{
			/* do nothing */
		}
	}
}
/***********************************************************************************
* END OF DiagCtrl_ProcessRequestedData										       *
************************************************************************************/
/***********************************************************************************
* Function: DiagCtrl_SendProcessedData										   	   *
* Description: Send to diagnostic service the processed data.		 		       *
************************************************************************************/
VOID DiagCtrl_SendProcessedData()
{
	/* Check through all the requests. */
	for(uint8 idx = DIAGCTRL_LB_L_UV; idx <= DIAGCTRL_RTS_F_SH; idx++)
	{
		/* If there is a request processed, send it to Dem. */
		if(DiagCtrl_ProcessedRequestArray[idx].statusValue != 0x00)
		{
			Rte_Call_Dem_P_DemPort_Dem_ReceiveFault(DiagCtrl_ProcessedRequestArray[idx].statusValue);
		}
		else if(DiagCtrl_ProcessedRequestArray[idx].statusValue == 0x00)
		{
			/* Else count up the occurences. */
			if(DiagCtrl_ProcessedRequestArray[idx].processedCounterValue < 3)
			{
				DiagCtrl_ProcessedRequestArray[idx].processedCounterValue = DiagCtrl_ProcessedRequestArray[idx].processedCounterValue + 1;
			}
			else
			{
				/* do nothing */
			}
			/* If the fault did not appear three times set the counter to 0. */
			if(DiagCtrl_ProcessedRequestArray[idx].processedCounterValue == 3)
			{
				DiagCtrl_ProcessedRequestArray[idx].counterValue = 0;
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
* END OF DiagCtrl_SendProcessedData										           *
************************************************************************************/