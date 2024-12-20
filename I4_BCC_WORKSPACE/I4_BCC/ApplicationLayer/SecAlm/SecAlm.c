/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Security Alarm	     		 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "SecAlm.h"
#include "PortH.h"

#include "../../Rte/Rte.h"
/*****************************************
		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Sensor request define. */
#define SECALM_VS_REQUEST    		1
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable for security alarm trigger. */
uint8 SecAlm_Trigger = STD_LOW;
/* Variable for pin state of buzzer and light control. */
uint8 SecAlm_PinStateChange = STD_LOW;
/* Variable for timer counter of alarm sequence. */
uint8 SecAlm_TriggerIRQCounterForTimer4 = STD_LOW;
/* Variable for vibration sensor activation counter. */
uint16 SecAlm_SensorStatusCounter = STD_LOW;
/* Variable for vibration sensor status. */
uint16 SecAlm_SensorStatus = STD_LOW;
/* Variable to get the sensor state. */
uint8 SecAlm_SensorState = STD_LOW;
/* Variable for the previous state of the security alarm trigger. */
uint8 SecAlm_TriggerPreviousState = STD_LOW;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Vibration sensor status processing function declaration.*/
uint32 SecAlm_VibSenReadSensorValue();
/* Vibration sensor status processing function declaration.*/
StdReturnType SecAlm_VibSenStatus();
/* Security alarm application initialization function declaration. */
StdReturnType SecAlm_Init();
/* Security alarm application main function declaration. */
VOID SecAlm_MainFunction();
/* Alarm buzzer trigger function declaration. */
VOID SecAlm_ToggleAlarmBuzzer(uint8 PinState);
/* Alarm LED trigger function declaration. */
VOID SecAlm_ToggleAlarmLed(uint8 PinState);
/* Alarm buzzer and light control function declaration. */
VOID SecAlm_LightsBuzzerControl();
/* Light control function declaration. */
VOID SecAlm_TurnOnExtLights();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: SecAlm_LightsBuzzerControl										       *
* Description: Controls the lights and buzzer in case of alarm trigger. 		   *
************************************************************************************/
VOID SecAlm_LightsBuzzerControl()
{
	/* Local variable for sensor status. */
	uint32 sensorStatus = STD_LOW;
	/* Get the sensor status. */
	sensorStatus = SecAlm_VibSenStatus();
	/* If the trigger was previously on and now it is off. */
	if(SecAlm_TriggerPreviousState != SecAlm_Trigger && !SecAlm_Trigger)
	{
		/* Reset the counter. */
		SecAlm_TriggerIRQCounterForTimer4 = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	/* If the counter exceeded the maximum value, reset the variables. */
	if(SecAlm_TriggerIRQCounterForTimer4 >= 20)
	{
		SecAlm_TriggerPreviousState 						= SecAlm_Trigger;
		Rte_P_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter	= STD_HIGH;
		Rte_P_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter 	= STD_LOW;
		SecAlm_Trigger 										= STD_LOW;
		SecAlm_PinStateChange 								= STD_LOW;
		SecAlm_TriggerIRQCounterForTimer4 					= STD_LOW;
		SecAlm_SensorStatusCounter 							= STD_LOW;
		SecAlm_SensorStatus 								= STD_LOW;
		SecAlm_SensorStatusCounter 							= STD_LOW;
		/* Stop the os timer assigned to security alarm trigger. */
		Rte_Call_OsTimer_R_OsTimerPort_OsTimerStop(Os_SecAlmAlarm_TimerHandle);
		/* Turn off the lights to make sure their state is off before any other action. */
		SecAlm_TurnOnExtLights();
	}
	else
	{
		/* do nothing */
	}
	/* The counter resets every 10 seconds, if a reset of the timer
	 * occurs, then reset the variables related to the security
	 * alarm trigger. */
	if(SecAlm_SensorStatusCounter == STD_LOW)
	{
		sensorStatus 	= STD_LOW;
		SecAlm_Trigger 	= STD_LOW;
		SecAlm_PinStateChange = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	/* If the sensor status is high, trigger the alarm. */
	if(sensorStatus == STD_HIGH)
	{
		SecAlm_Trigger = STD_HIGH;
	}
	else
	{
		/* do nothing */
	}
	/* If the trigger is set to high, perform alarm triggering. */
	if(SecAlm_Trigger == STD_HIGH)
	{
		SecAlm_ToggleAlarmLed(STD_LOW);
		/* One alarm cycle is performed consisting of 10 seconds. */
		if(Rte_Call_Os_R_OsPort_OsTimerIsRunning(Os_SecAlmAlarm_TimerHandle) == 0)
		{
			Rte_Call_OsTimer_R_OsTimerPort_OsTimerStart(Os_SecAlmAlarm_TimerHandle, 500);
		}
		else
		{
			/* do nothing */
		}
		/* Cycle between on and off states of buzzer and lights. */
		if(SecAlm_TriggerIRQCounterForTimer4 % 2 == 1)
		{
			SecAlm_PinStateChange = STD_HIGH;
			SecAlm_TurnOnExtLights();
		}
		else if(SecAlm_TriggerIRQCounterForTimer4 % 2 == 0)
		{
			SecAlm_PinStateChange = STD_LOW;
			SecAlm_TurnOnExtLights();
		}
		else
		{
			/* do nothing */
		}
	}
	else if(SecAlm_Trigger == STD_LOW)
	{
		/* Turn off the buzzer to make sure is set to low before any other action in the system. */
		SecAlm_ToggleAlarmBuzzer(STD_LOW);
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF SecAlm_LightsBuzzerControl										           *
************************************************************************************/
/***********************************************************************************
* Function: SecAlm_VibSenStatus										               *
* Description: Updates the vibration sensor status based on measurements.		   *
************************************************************************************/
StdReturnType SecAlm_VibSenStatus()
{
	/* Local variable for sensor status. */
	uint16 sensorStatus = STD_LOW;
	/* Read the sensor value. */
	Rte_Call_SenCtrl_P_SenCtrlPort_SenCtrl_ProcessSensorValue(SECALM_VS_REQUEST);
	/* If the sensor was triggered. */
	if(SecAlm_SensorState == STD_HIGH)
	{
		/* Count for how long it has been triggered. */
		SecAlm_SensorStatusCounter = SecAlm_SensorStatusCounter + 1;
		/* Start the reset timer for the counter variable. */
		Rte_Call_OsTimer_R_OsTimerPort_OsTimerStart(Os_SecAlm_AlarmResetHandle, 10000);
	}
	else
	{
		/* do nothing */
	}
	/* If the sensor was triggered enough times. */
	if(SecAlm_SensorStatusCounter >= 300)
	{
		/* Set the sensor status to high. */
		sensorStatus = STD_HIGH;
	}
	else if(SecAlm_SensorStatusCounter < 300)
	{
		/* Set the sensor status to low. */
		sensorStatus = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	/* Return sensor status. */
	return sensorStatus;
}
/***********************************************************************************
* END OF SecAlm_VibSenStatus										               *
************************************************************************************/
/***********************************************************************************
* Function: SecAlm_TurnOnExtLights										           *
* Description: Trigger the exterior lights and buzzer.							   *
************************************************************************************/
VOID SecAlm_TurnOnExtLights()
{
	/* Turn on the lights and the buzzer. */
	if(SecAlm_PinStateChange == STD_HIGH)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel3);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel4);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
	}
	else if(SecAlm_PinStateChange == STD_LOW)
	{
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel1);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim2, Rte_P_Tim_TimPort_TimChannel2);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel3);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim3, Rte_P_Tim_TimPort_TimChannel4);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel3);
		Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(Rte_P_Tim_TimPort_Htim4, Rte_P_Tim_TimPort_TimChannel4);
	}
	SecAlm_ToggleAlarmBuzzer(SecAlm_PinStateChange);
}
/***********************************************************************************
* END OF SecAlm_TurnOnExtLights										               *
************************************************************************************/
/***********************************************************************************
* Function: SecAlm_MainFunction										           	   *
* Description: Process application states.										   *
************************************************************************************/
VOID SecAlm_MainFunction()
{
	SecAlm_LightsBuzzerControl();
}
/***********************************************************************************
* END OF SecAlm_MainFunction										               *
************************************************************************************/
/***********************************************************************************
* Function: SecAlm_Init										                       *
* Description: Initialize the application.										   *
************************************************************************************/
StdReturnType SecAlm_Init()
{
	/* Set the variables to 0. */
	SecAlm_Trigger 						= STD_LOW;
	SecAlm_PinStateChange 				= STD_LOW;
	SecAlm_TriggerIRQCounterForTimer4 	= STD_LOW;
	SecAlm_SensorStatusCounter 			= STD_LOW;
	SecAlm_SensorStatus 				= STD_LOW;
	SecAlm_TriggerPreviousState 		= STD_LOW;
	SecAlm_ToggleAlarmLed(STD_LOW);
	return E_OK;
}
/***********************************************************************************
* END OF SecAlm_Init										                       *
************************************************************************************/
/***********************************************************************************
* Function: SecAlm_ToggleAlarmBuzzer										       *
* Description: Alarm buzzer trigger.                                               *
************************************************************************************/
VOID SecAlm_ToggleAlarmBuzzer(uint8 PinState)
{
	Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(SECALM_BUZZER_PORT, SECALM_BUZZER_PIN, PinState);
}
/***********************************************************************************
* END OF SecAlm_ToggleAlarmBuzzer										           *
************************************************************************************/
/***********************************************************************************
* Function: SecAlm_ToggleAlarmLed										           *
* Description: Alarm LED trigger.												   *
************************************************************************************/
VOID SecAlm_ToggleAlarmLed(uint8 PinState)
{
	Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(SECALM_LED_PORT, SECALM_LED_PIN, PinState);
}
/***********************************************************************************
* END OF SecAlm_ToggleAlarmLed										               *
************************************************************************************/
