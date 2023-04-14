/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Exterior Lights	     		 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "ExtLights.h"
#include "PortH.h"
#include "Rte.h"
/*****************************************
		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
#define EXTLIGHTS_LS_REQUEST 		0x04
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store the application state. */
uint8 ExtLights_ApplState = STD_LOW;
/* Variable for the current state of reverse light. */
uint8 ExtLights_ReverseLight_CurrentState = STD_LOW;
/* Variable for the current state of flashing the high beam. */
uint8 ExtLights_FlashHighBeam_CurrentState = STD_LOW;
/* Variable for the current state of brake light. */
uint8 ExtLights_BrakeLight_CurrentState = STD_LOW;
/* Variable for the current state of light switch. */
uint8 ExtLights_LightsSwitch_CurrentState = STD_LOW;
/* Variable for the current state of high beam. */
uint8 ExtLights_HighBeam_CurrentState = STD_LOW;
/* Variable for the current state of front fog light. */
uint8 ExtLights_FrontFogLight_CurrentState = STD_LOW;
/* Variable for the current state of left turn signals. */
uint8 ExtLights_TurnSignalLeft_CurrentState = STD_LOW;
/* Variable for the current state of right turn signals. */
uint8 ExtLights_TurnSignalRight_CurrentState = STD_LOW;
/* Variable for the current state of the low beam */
uint8 ExtLights_LowBeam_CurrentState = STD_LOW;
/* Variable for the current state of the rear position lights. */
uint8 ExtLights_RearPositionLights_CurrentState = STD_LOW;
/* Variable for the current state of hazard lights. */
uint8 ExtLights_HazardLight_CurrentState = STD_LOW;
/* Variable for the current state of rear fog lights. */
uint8 ExtLights_RearFogLight_CurrentState = STD_LOW;
/* Variable for the right turn signal previous state. */
uint8 ExtLights_RTS_PrevState = STD_LOW;
/* Variable for the left turn signal previous state. */
uint8 ExtLights_LTS_PrevState = STD_LOW;
/* Variable for the hazard light previous state. */
uint8 ExtLights_HL_PrevState = STD_LOW;
/* Variable for the right turn signal counter flag. */
uint32 ExtLights_RTSFlag = STD_LOW;
/* Variable for the left turn signal counter flag. */
uint32 ExtLights_LTSFlag = STD_LOW;
/* Variable for the hazard light counter flag. */
uint32 ExtLights_HLFlag = STD_LOW;
/* Variable for sensor state. */
uint8 ExtLights_LightSensorState = STD_LOW;
/* Static variable to store first call of main. */
STATIC uint8 firstCall = STD_LOW;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Exterior lights memroy read function declaration. */
VOID ExtLights_MemRead();
/* Exterior lights memory write function declaration. */
VOID ExtLights_MemWrite();
/* Exterior lights main function declaration. */
VOID ExtLights_MainFunction();
/* High beam trigger function declaration. */
VOID ExtLights_HighBeam(uint8 PinState);
/* Reverse light trigger function declaration. */
VOID ExtLights_ReverseLight(uint8 PinState);
/* Lights states processing function declaration. */
VOID ExtLights_LightState();
/* Turn signals and hazard lights control function declaration. */
VOID ExtLights_TurnSignalHazardLight();
/* Light switch control function declaration. */
VOID ExtLights_LightSwitchMode();
/* Turn signals and hazard lights current and previous state processing function declaration. */
VOID ExtLights_PrevStateTSHL();
/* Exterior lights application initialization function declaration .*/
StdReturnType ExtLights_Init();
/* Exterior lights application de-initialization function declaration .*/
StdReturnType ExtLights_DeInit();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: ExtLights_MemRead										           	   *
* Description: Read from memory.											       *
************************************************************************************/
VOID ExtLights_MemRead()
{
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 23, &ExtLights_ReverseLight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 24, &ExtLights_LightsSwitch_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 25, &ExtLights_HighBeam_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 26, &ExtLights_FrontFogLight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 27, &ExtLights_TurnSignalLeft_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 28, &ExtLights_TurnSignalRight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 29, &ExtLights_HazardLight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 30, &ExtLights_RearFogLight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 31, &ExtLights_RTS_PrevState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 32, &ExtLights_LTS_PrevState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 33, &ExtLights_HL_PrevState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 34, (uint8*)&ExtLights_RTSFlag, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 35, (uint8*)&ExtLights_LTSFlag, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 36, (uint8*)&ExtLights_HLFlag, 1);
}
/***********************************************************************************
* END OF ExtLights_MemRead										   				   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_MemWrite										           	   *
* Description: Write into memory.											       *
************************************************************************************/
VOID ExtLights_MemWrite()
{
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 23, &ExtLights_ReverseLight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 24, &ExtLights_LightsSwitch_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 25, &ExtLights_HighBeam_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 26, &ExtLights_FrontFogLight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 27, &ExtLights_TurnSignalLeft_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 28, &ExtLights_TurnSignalRight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 29, &ExtLights_HazardLight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 30, &ExtLights_RearFogLight_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 31, &ExtLights_RTS_PrevState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 32, &ExtLights_LTS_PrevState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 33, &ExtLights_HL_PrevState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 34, (uint8*)&ExtLights_RTSFlag, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 35, (uint8*)&ExtLights_LTSFlag, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 36, (uint8*)&ExtLights_HLFlag, 1);
}
/***********************************************************************************
* END OF ExtLights_MemWrite										  				   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_TurnSignalHazardLight										   *
* Description: Process the turn signals and hazard lights states. 		   		   *
************************************************************************************/
VOID ExtLights_TurnSignalHazardLight()
{
	/* If the turn signal left is set on. */
	if(ExtLights_TurnSignalLeft_CurrentState == STD_HIGH)
	{
		/* Check if the timer related to the turn signals is off. */
		if(Rte_Call_Os_R_OsPort_OsTimerIsRunning(Os_TurnSignals_TimerHandle) == 0)
		{
			/* Start the timer with the designated period counter value. */
			Rte_Call_OsTimer_R_OsTimerPort_OsTimerStart(Os_TurnSignals_TimerHandle, 500);
		}
		else
		{
			/* do nothing */
		}
		/* Turn on and off the turn signal. */
		if(ExtLights_LTSFlag % 2 == 0)
		{
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
		}
		else if(ExtLights_LTSFlag % 2 == STD_HIGH)
		{
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
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
	/* If the turn signal right is set on. */
	if(ExtLights_TurnSignalRight_CurrentState == STD_HIGH)
	{
		/* Check if the timer related to the turn signals is off. */
		if(Rte_Call_Os_R_OsPort_OsTimerIsRunning(Os_TurnSignals_TimerHandle) == 0)
		{
			/* Start the timer with the designated period counter value. */
			Rte_Call_OsTimer_R_OsTimerPort_OsTimerStart(Os_TurnSignals_TimerHandle, 500);
		}
		else
		{
			/* do nothing */
		}
		/* Turn on and off the turn signal. */
		if(ExtLights_RTSFlag % 2 == STD_LOW)
		{
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
		}
		else if(ExtLights_RTSFlag % 2 == STD_HIGH)
		{
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
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
	/* If the hazard light is set on. */
	if(ExtLights_HazardLight_CurrentState == STD_HIGH)
	{
		/* Check if the timer related to the turn signals is off. */
		if(Rte_Call_Os_R_OsPort_OsTimerIsRunning(Os_TurnSignals_TimerHandle) == 0)
		{
			/* Start the timer with the designated period counter value. */
			Rte_Call_OsTimer_R_OsTimerPort_OsTimerStart(Os_TurnSignals_TimerHandle, 500);
		}
		else
		{
			/* do nothing */
		}
		/* Turn on and off the turn signal. */
		if(ExtLights_HLFlag % 2 == STD_LOW)
		{
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
		}
		else if(ExtLights_HLFlag % 2 == STD_HIGH)
		{
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
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
	/* Only one pair of turn signals can be on at a time. Set on one pair and the other off. */
	if(ExtLights_TurnSignalRight_CurrentState == STD_LOW && ExtLights_HazardLight_CurrentState == STD_LOW)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
	}
	else
	{
		/* do nothing */
	}
	/* Only one pair of turn signals can be on at a time. Set on one pair and the other off. */
	if(ExtLights_TurnSignalLeft_CurrentState == STD_LOW && ExtLights_HazardLight_CurrentState == STD_LOW)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF ExtLights_TurnSignalHazardLight										   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_PrevStateTSHL										           *
* Description: Checks the current state and previous state of turn signals and     *
* 			   hazard lights. 		   											   *
************************************************************************************/
VOID ExtLights_PrevStateTSHL()
{
	/* Change the variables related to states. */
	if(ExtLights_TurnSignalLeft_CurrentState != ExtLights_LTS_PrevState)
	{
		ExtLights_LTS_PrevState = ExtLights_TurnSignalLeft_CurrentState;
		ExtLights_LTSFlag = 0;
		Rte_Write_Os_R_OsPort_Os_Lts_Counter(&ExtLights_LTSFlag);
	}
	else
	{
		/* do nothing */
	}
	/* Change the variables related to states. */
	if(ExtLights_TurnSignalRight_CurrentState != ExtLights_RTS_PrevState)
	{
		ExtLights_RTS_PrevState = ExtLights_TurnSignalRight_CurrentState;
		ExtLights_RTSFlag = 0;
		Rte_Write_Os_R_OsPort_Os_Rts_Counter(&ExtLights_RTSFlag);
	}
	else
	{
		/* do nothing */
	}
	/* Change the variables related to states. */
	if(ExtLights_HazardLight_CurrentState != ExtLights_HL_PrevState)
	{
		ExtLights_HL_PrevState = ExtLights_HazardLight_CurrentState;
		ExtLights_HLFlag = 0;
		Rte_Write_Os_R_OsPort_Os_HL_Counter(&ExtLights_HLFlag);
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF ExtLights_PrevStateTSHL										   		   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_LightState										   		   *
* Description: Controls the lights states.								 		   *
************************************************************************************/
VOID ExtLights_LightState()
{
	/* Process turn signals state. */
	ExtLights_PrevStateTSHL();
	/* Follow me home is on, then turn on the respective lights. */
	if(Rte_P_CenLoc_CenLocPort_CenLoc_FollowMeHomeState == STD_HIGH)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel3);
		ExtLights_LowBeam_CurrentState = STD_HIGH;
		ExtLights_RearPositionLights_CurrentState = STD_HIGH;
	}/* Follow me home is off, turn off the lights.*/
	else if(Rte_P_CenLoc_CenLocPort_CenLoc_FollowMeHomeState == STD_LOW)
	{
		if(Rte_P_IntLights_IntLightsPort_IntLights_CurrentState == STD_LOW && ExtLights_LightsSwitch_CurrentState == STD_LOW)
		{
			Rte_Write_Btc_BtcPort_Btc_FollowMeHome(&CenLoc_FollowMeHomeState);
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel3);
			ExtLights_LowBeam_CurrentState = STD_LOW;
			ExtLights_RearPositionLights_CurrentState = STD_LOW;
		}
		else
		{
			/* do nothing */
		}
		/* Stop the OS timer for follow me home. */
		Rte_Call_OsTimer_R_OsTimerPort_OsTimerStop(Os_FollowMeHome_TimerHandle);
	}
	else
	{
		/* do nothing */
	}
	/* If any light state is set to on, then stop the follow me home. */
	if( ExtLights_ReverseLight_CurrentState == STD_HIGH ||
		ExtLights_BrakeLight_CurrentState == STD_HIGH ||
		ExtLights_FlashHighBeam_CurrentState == STD_HIGH ||
		ExtLights_LightsSwitch_CurrentState != STD_LOW ||
		ExtLights_HighBeam_CurrentState == STD_HIGH ||
		ExtLights_FrontFogLight_CurrentState == STD_HIGH ||
		ExtLights_TurnSignalLeft_CurrentState == STD_HIGH ||
		ExtLights_TurnSignalRight_CurrentState == STD_HIGH ||
		ExtLights_HazardLight_CurrentState == STD_HIGH ||
		ExtLights_RearFogLight_CurrentState == STD_HIGH)
	{
		Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeState(STD_LOW);
		Rte_Write_Os_R_OsPort_Os_FollowMeHome_Counter((uint8*)2);
	}
	else
	{
		/* do nothing */
	}
	/* Control the turn signals for the central lock lock unlock sequence when requested. */
	if(Rte_P_CenLoc_CenLocPort_CenLoc_BlinkState == STD_HIGH)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
	}
	else if(Rte_P_CenLoc_CenLocPort_CenLoc_BlinkState == STD_LOW)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
	}/* Allows for turning on the hazard lights or turn signals independently of other states in the system. */
	else if(Rte_P_CenLoc_CenLocPort_CenLoc_BlinkState == 2 || Rte_P_CenLoc_CenLocPort_CenLoc_BlinkState == 4)
	{
		ExtLights_TurnSignalHazardLight();
	}
	else
	{
		/* do nothing */
	}
	/* The light switch can be controlled after the follow me home is set to off. */
	if(Rte_P_CenLoc_CenLocPort_CenLoc_FollowMeHomeState == STD_LOW)
	{
		ExtLights_LightSwitchMode();
	}
	else
	{
		/* do nothing */
	}
	/* If the high beam is not on, allow for flashing the high beam. */
	if(ExtLights_HighBeam_CurrentState != STD_HIGH)
	{
		ExtLights_HighBeam(ExtLights_FlashHighBeam_CurrentState);
	}
	else
	{
		/* do nothing */
	}
	/* Turn on or off the brake lights. */
	if(ExtLights_BrakeLight_CurrentState == STD_HIGH)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel2);
	}
	else if(ExtLights_BrakeLight_CurrentState == STD_LOW)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel2);
	}
	else
	{
		/* do nothing */
	}
	/* Turn on or off the rear fog lights. */
	if(ExtLights_RearFogLight_CurrentState == STD_HIGH)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel4);
	}
	else if(ExtLights_RearFogLight_CurrentState == STD_LOW)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel4);
	}
	else
	{
		/* do nothing */
	}
	/* Turn on or off the front fog lights. */
	if(ExtLights_FrontFogLight_CurrentState == STD_HIGH)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel3);
	}
	else if(ExtLights_FrontFogLight_CurrentState == STD_LOW)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel3);
	}
	else
	{
		/* do nothing */
	}
	/* Turn on the reverse light. */
	ExtLights_ReverseLight(ExtLights_ReverseLight_CurrentState);
	/* Turn on the high beam. */
	ExtLights_HighBeam(ExtLights_HighBeam_CurrentState);
}
/***********************************************************************************
* END OF ExtLights_LightState										   			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_DeInit										   		       *
* Description: Exterior lights de-initialization.	   							   *
************************************************************************************/
StdReturnType ExtLights_DeInit()
{
	ExtLights_MemWrite();
	return E_OK;
}
/***********************************************************************************
* END OF ExtLights_DeInit										   			       *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_MainFunction										   		   *
* Description: Exterior lights application main function. Controls application	   *
* 			   states. 		   													   *
************************************************************************************/
VOID ExtLights_MainFunction()
{
	/* Process application state. */
	switch(ExtLights_ApplState)
	{
		case EXTLIGHTS_INIT_STATE:
			ExtLights_Init();
			if(firstCall == STD_LOW)
			{
				firstCall = STD_HIGH;
				ExtLights_MemRead();
			}
			else
			{
				/* do nothing */
			}
			ExtLights_ApplState = EXTLIGHTS_PROCESSLIGHT_STATE;
			break;
		case EXTLIGHTS_DEINIT_STATE:
			ExtLights_DeInit();
			break;
		case EXTLIGHTS_PROCESSLIGHT_STATE:
			ExtLights_LightState();
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF ExtLights_MainFunction										   			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_LightSwitchMode										   	   *
* Description: Control the light switch.								 		   *
************************************************************************************/
VOID ExtLights_LightSwitchMode()
{
	/* Switch through the light switch states. */
	switch(ExtLights_LightsSwitch_CurrentState)
	{
		/* Switch is on position zero, turn off the lights. */
		case EXTLIGHTS_LIGHTSWITCH_STATEZERO:
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
			ExtLights_LowBeam_CurrentState = STD_LOW;
			ExtLights_RearPositionLights_CurrentState = STD_LOW;
			break;
		/* Switch is on position one, turn automatic lights controlled by sensor's input. */
		case EXTLIGHTS_LIGHTSWITCH_STATEONE:
			/* Read the sensor status. */
			Rte_Call_SenCtrl_P_SenCtrlPort_SenCtrl_ProcessSensorValue(EXTLIGHTS_LS_REQUEST);
			/* If the sensor status is on, turn on the lights to on. */
			if(ExtLights_LightSensorState == STD_HIGH)
			{
				ExtLights_LowBeam_CurrentState = STD_HIGH;
				ExtLights_RearPositionLights_CurrentState = STD_HIGH;
				Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
				Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
			}/* Else turn them off. */
			else if(ExtLights_LightSensorState == STD_LOW)
			{
				ExtLights_LowBeam_CurrentState = STD_LOW;
				ExtLights_RearPositionLights_CurrentState = STD_LOW;
				Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
				Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
			}
			break;
		/* Switch is on position three, turn on position lights. */
		case EXTLIGHTS_LIGHTSWITCH_STATETWO:
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
			ExtLights_LowBeam_CurrentState = STD_HIGH;
			ExtLights_RearPositionLights_CurrentState = STD_HIGH;
			break;
		/* Switch is on position four, turn on night time lights. */
		case EXTLIGHTS_LIGHTSWITCH_STATETHREE:
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
			Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
			ExtLights_LowBeam_CurrentState = STD_HIGH;
			ExtLights_RearPositionLights_CurrentState = STD_HIGH;
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF ExtLights_LightSwitchMode										   		   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_Init										   				   *
* Description: Initialize the application variables to 0. 		   				   *
************************************************************************************/
StdReturnType ExtLights_Init()
{
	/* Set all the exterior lights variables to 0. */
	ExtLights_ReverseLight_CurrentState 		= STD_LOW;
	ExtLights_BrakeLight_CurrentState 			= STD_LOW;
	ExtLights_FlashHighBeam_CurrentState 		= STD_LOW;
	ExtLights_LightsSwitch_CurrentState 		= STD_LOW;
	ExtLights_HighBeam_CurrentState 			= STD_LOW;
	ExtLights_FrontFogLight_CurrentState 		= STD_LOW;
	ExtLights_TurnSignalLeft_CurrentState 		= STD_LOW;
	ExtLights_TurnSignalRight_CurrentState 		= STD_LOW;
	ExtLights_HazardLight_CurrentState 			= STD_LOW;
	ExtLights_RearFogLight_CurrentState 		= STD_LOW;
	ExtLights_RTSFlag 							= STD_LOW;
	ExtLights_LTSFlag 							= STD_LOW;
	ExtLights_HLFlag 							= STD_LOW;
	ExtLights_LowBeam_CurrentState 				= STD_LOW;
	ExtLights_RearPositionLights_CurrentState 	= STD_LOW;
	return E_OK;
}
/***********************************************************************************
* END OF ExtLights_Init										   					   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_HighBeam										   			   *
* Description: High beam trigger. 		  										   *
************************************************************************************/
VOID ExtLights_HighBeam(uint8 PinState)
{
	Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(EXTLIGHTS_HIGHBEAM_PORT, EXTLIGHTS_HIGHBEAM_PIN, PinState);
}
/***********************************************************************************
* END OF ExtLights_HighBeam										   				   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: ExtLights_ReverseLight										   		   *
* Description: Reverse light trigger. 		   									   *
************************************************************************************/
VOID ExtLights_ReverseLight(uint8 PinState)
{
	Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(EXTLIGHTS_REVERSELIGHT_PORT, EXTLIGHTS_REVERSELIGHT_PIN, PinState);
}
/***********************************************************************************
* END OF ExtLights_ReverseLight										   			   *													       																	   *
************************************************************************************/
