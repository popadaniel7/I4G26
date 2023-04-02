/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Interior Lights	     		 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "IntLights.h"
#include "Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Define value to get the central lock on value*/
#define LIGHTSON_CENLOCON BTC_RX_CENLOC_ON
/* Define value to get the central lock off value*/
#define LIGHTSOFF_CENLOCOFF BTC_RX_CENLOC_OFF
/* Define value to get the interior lights command on value*/
#define LIGHTSON_INTLIGHTSON BTC_RX_INTLIGHTS_INTERIORLIGHT_ON
/* Define value to get the interior lights command off value*/
#define LIGHTSOFF_INTLIGHTSOFF BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store application state. */
uint8 IntLights_ApplState;
/* Variable for the interior lights current states. */
uint8 IntLights_CurrentState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Interior lights application initialization function declaration. */
StdReturnType IntLights_DeInit();
/* Interior lights application initialization function declaration. */
StdReturnType IntLights_Init();
/* Interior lights main function. */
void IntLights_MainFunction();
/* Interior lights command processed. */
void IntLights_RxBtcState();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: IntLights_DeInit										               *
* Description: De-initialize the interior lights.							       *
************************************************************************************/
StdReturnType IntLights_DeInit()
{
	return E_OK;
}
/***********************************************************************************
* END OF IntLights_DeInit										                   *
************************************************************************************/
/***********************************************************************************
* Function: IntLights_RxBtcState										   		   *
* Description: Process command. 		   		   						           *
************************************************************************************/
void IntLights_RxBtcState()
{
	uint8 lightsStateFromBtcCommand;
	Rte_Read_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(&lightsStateFromBtcCommand);
	switch(lightsStateFromBtcCommand)
	{
		case LIGHTSON_CENLOCON:
			IntLights_CurrentState = STD_HIGH;
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel3);
			break;
		case LIGHTSOFF_CENLOCOFF:
			IntLights_CurrentState = STD_LOW;
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel3);
			break;
		case LIGHTSON_INTLIGHTSON:
			IntLights_CurrentState = STD_HIGH;
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel3);
			break;
		case LIGHTSOFF_INTLIGHTSOFF:
			IntLights_CurrentState = STD_LOW;
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel3);
			break;
	}
}
/***********************************************************************************
* END OF IntLights_RxBtcState										               *
************************************************************************************/
/***********************************************************************************
* Function: IntLights_MainFunction										           *
* Description: Interior lights main function for the application and state process.*
************************************************************************************/
void IntLights_MainFunction()
{
	IntLights_RxBtcState();
}
/***********************************************************************************
* END OF IntLights_MainFunction										   			   *
************************************************************************************/
/***********************************************************************************
* Function: IntLights_Init										                   *
* Description: Initialize the interior lights.							           *
************************************************************************************/
StdReturnType IntLights_Init()
{
	IntLights_CurrentState 	= STD_LOW;
	return E_OK;
}
/***********************************************************************************
* END OF IntLights_Init										   					   *
************************************************************************************/
