/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Sensor Control	     		 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "SenCtrl.h"
#include "PortH.h"
#include "Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Application request define. */
#define SENCTRL_PDCR_REQUEST 				0x02
/* Application request define. */
#define SENCTRL_PDCF_REQUEST 				0x03
/* Application request define. */
#define SENCTRL_EXTLIGHTS_LS_REQUEST 		0x04
/* Application request define. */
#define SENCTRL_SECALM_VS_REQUEST    		0x05
/* Application request define. */
#define SENCTRL_HVAC_AQS_REQUEST			0x06
/* Application request define. */
#define SENCTRL_HVAC_TS_REQUEST				0x07
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_L_REQUEST		0x08
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_R_REQUEST		0x09
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_L_REQUEST		0x10
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_R_REQUEST		0x11
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_R_REQUEST		0x12
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_L_REQUEST		0x13
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_F_REQUEST		0x14
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_R_REQUEST		0x15
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_R_REQUEST		0x16
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_F_REQUEST		0x17
/* Application state define. */
#define SENCTRL_INIT_STATE					0x00
/* Application state define. */
#define SENCTRL_DEINIT_STATE				0x02
/* Application state define. */
#define SENCTRL_PROCESS_STATE				0x01
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Application state variable. */
uint8 SenCtrl_ApplState = STD_LOW;
/* Adc measurements array variable. */
uint32 SenCtrl_MeasuredValues[16] = {STD_LOW};
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Application main function declaration. */
VOID SenCtrl_MainFunction();
/* Application initialization function declaration. */
StdReturnType SenCtrl_Init();
/* Application de-initialization function declaration. */
StdReturnType SenCtrl_DeInit();
/* Process sensor value function declaration. */
VOID SenCtrl_ProcessSensorValue(uint8 request);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: SenCtrl_MainFunction										   		   *
* Description: Application main function.				 		                   *
************************************************************************************/
VOID SenCtrl_MainFunction()
{
	/* Process application state. */
	switch(SenCtrl_ApplState)
	{
		case SENCTRL_INIT_STATE:
			SenCtrl_Init();
			break;
		case SENCTRL_DEINIT_STATE:
			SenCtrl_DeInit();
			break;
		case SENCTRL_PROCESS_STATE:
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF SenCtrl_MainFunction											   	       * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SenCtrl_Init													       *
* Description: Initialize application.		   			                           *
************************************************************************************/
StdReturnType SenCtrl_Init()
{
	/* Initialize the variables. */
	for(uint8 idx = 0; idx < 16; idx++)
	{
		SenCtrl_MeasuredValues[idx] = STD_LOW;
	}
	SenCtrl_ApplState = SENCTRL_PROCESS_STATE;
	return E_OK;
}
/***********************************************************************************
* END OF SenCtrl_Init											  	     	       * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SenCtrl_DeInit										     	   	       *
* Description: De-initialize application.		   			                       *
************************************************************************************/
StdReturnType SenCtrl_DeInit()
{
	return E_OK;
}
/***********************************************************************************
* END OF SenCtrl_DeInit											  	    	       * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SenCtrl_ProcessSensorValue									   	       *
* Description: Process the request for the sensor value. 	                       *
************************************************************************************/
VOID SenCtrl_ProcessSensorValue(uint8 request)
{
	/* Store request into local variable. */
	uint8 localRequest = request;
	/* Process sensor request. */
	switch(localRequest)
	{
		case SENCTRL_PDCR_REQUEST:
			Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(PDCR_TRIG_PORT, PDCR_TRIG_PIN, STD_HIGH);
			Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(PDCR_TRIG_PORT, PDCR_TRIG_PIN, STD_LOW);
			Rte_Call_Tim_R_TimPort_HAL_TIM_ENABLE_IT(Rte_P_Tim_TimPort_Htim5, Rte_P_Tim_TimPort_TimChannel4);
			break;
		case SENCTRL_PDCF_REQUEST:
			Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(PDCF_TRIG_PORT, PDCF_TRIG_PIN, STD_HIGH);
			Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(PDCF_TRIG_PORT, PDCF_TRIG_PIN, STD_LOW);
			Rte_Call_Tim_R_TimPort_HAL_TIM_ENABLE_IT(Rte_P_Tim_TimPort_Htim5, Rte_P_Tim_TimPort_TimChannel3);
			break;
		case SENCTRL_EXTLIGHTS_LS_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_EXTLIGHTS_LS_POSITION] >= 4000)
			{
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightSensorState((uint32*)STD_HIGH);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_EXTLIGHTS_LS_POSITION] < 4000)
			{
				Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightSensorState((uint32*)STD_LOW);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_SECALM_VS_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_SECALM_VS_REQUEST] >= 4000)
			{
				Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorState((uint32*)STD_HIGH);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_SECALM_VS_REQUEST] < 4000)
			{
				Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorState((uint32*)STD_LOW);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_HVAC_AQS_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_HVAC_AQS_POSITION] >= 4000)
			{
				Rte_Write_Hvac_HvacPort_Hvac_AqsState((uint8*)STD_HIGH);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_HVAC_AQS_POSITION] < 4000)
			{
				Rte_Write_Hvac_HvacPort_Hvac_AqsState((uint8*)STD_LOW);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_HVAC_TS_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_HVAC_TS_POSITION] >= 4000)
			{
				Rte_Write_Hvac_HvacPort_Hvac_TsState((uint8*)STD_HIGH);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_HVAC_TS_POSITION] < 4000)
			{
				Rte_Write_Hvac_HvacPort_Hvac_TsState((uint8*)STD_LOW);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_LB_L_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LB_L_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LB_L_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LB_L_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_LB_R_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LB_R_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LB_R_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LB_R_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_RPL_L_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RPL_L_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RPL_L_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RPL_L_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_RPL_R_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RPL_R_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RPL_R_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RPL_R_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_BL_R_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_BL_R_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_BL_R_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_BL_R_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_BL_L_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_BL_L_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_BL_L_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_BL_L_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_LTS_F_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LTS_F_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LTS_F_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LTS_F_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_LTS_R_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LTS_R_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LTS_R_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_LTS_R_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_RTS_R_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RTS_R_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RTS_R_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RTS_R_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
			}
			else
			{
				/* do nothing */
			}
			break;
		case SENCTRL_DIAGCTRL_RTS_F_REQUEST:
			if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RTS_F_POSITION] >= SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_OK);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RTS_F_POSITION] < SENCTRL_THRESHOLD_OK)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_UV);
			}
			else if(SenCtrl_MeasuredValues[SENCTRL_DIAGCTRL_RTS_F_POSITION] < SENCTRL_THRESHOLD_SH)
			{
				Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue((uint8*)SENCTRL_DIAGCTRL_LB_L_SH);
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
/***********************************************************************************
* END OF SenCtrl_ProcessSensorValue										   	       * 		   																	       																	   *
************************************************************************************/
