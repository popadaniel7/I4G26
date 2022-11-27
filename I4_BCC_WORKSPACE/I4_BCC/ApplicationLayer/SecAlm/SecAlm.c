#include "CenLoc.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "Std_Types.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

uint8 CurrentState_Alarm_LED;
uint8 LockCounter;
uint8 UnlockCounter;
uint8 SecAlmTrigger;
uint8 SecAlmCounter;
uint8 PreviousState_SecAlm;

void SecAlm_MainFunction()
{
	if(PreviousState_SecAlm != SecAlmTrigger)
	{
		HAL_TIM_Base_Init(&htim5);
		PreviousState_SecAlm = SecAlmTrigger;
	}

	if(SecAlmTrigger == STD_HIGH)
	{
		HAL_TIM_Base_Start(&htim5);
		if(__HAL_TIM_GET_COUNTER(&htim5) < 100000)
		{
			HAL_TIM_Base_Start(&htim4);

			if(__HAL_TIM_GET_COUNTER(&htim4) < 5000)
			{
				ExtLights_LowBeam(SecAlmTrigger);
				ExtLights_PositionLightRear(SecAlmTrigger);
				ExtLights_FogLightFront(SecAlmTrigger);
				ExtLights_FogLightRear(SecAlmTrigger);
				ExtLights_TurnSignalRight(SecAlmTrigger);
				ExtLights_TurnSignalLeft(SecAlmTrigger);

			}
			else if(5000 < __HAL_TIM_GET_COUNTER(&htim4) && __HAL_TIM_GET_COUNTER(&htim4) < 10000)
			{
				ExtLights_LowBeam(!SecAlmTrigger);
				ExtLights_PositionLightRear(!SecAlmTrigger);
				ExtLights_FogLightFront(!SecAlmTrigger);
				ExtLights_FogLightRear(!SecAlmTrigger);
				ExtLights_TurnSignalRight(!SecAlmTrigger);
				ExtLights_TurnSignalLeft(!SecAlmTrigger);
			}
			else
			{
				/* do nothing */
			}
		}
		else if(__HAL_TIM_GET_COUNTER(&htim5) > 100000)
		{
			SecAlmTrigger = STD_LOW;
			HAL_TIM_Base_Stop(&htim5);
		}
		else
		{
			/* do nothing */
		}
	}
	else if(SecAlmTrigger == STD_LOW)
	{
		HAL_TIM_Base_Stop(&htim4);
		ExtLights_LowBeam(SecAlmTrigger);
		ExtLights_PositionLightRear(SecAlmTrigger);
		ExtLights_FogLightFront(SecAlmTrigger);
		ExtLights_FogLightRear(SecAlmTrigger);
		ExtLights_TurnSignalRight(SecAlmTrigger);
		ExtLights_TurnSignalLeft(SecAlmTrigger);
	}
	else
	{
		/* do nothing */
	}
}

StdReturnType SecAlm_Init()
{
	CurrentState_Alarm_LED = STD_LOW;
	LockCounter = STD_LOW;
	UnlockCounter = STD_LOW;
	SecAlmTrigger = STD_LOW;
	SecAlmCounter = STD_LOW;
	PreviousState_SecAlm = STD_LOW;

	return E_OK;
}

void SecAlm_ToggleAlarmBuzzer(uint8 PinState)
{
	HAL_GPIO_WritePin(ALARM_BUZZER_PORT, ALARM_BUZZER_PIN, PinState);
}

void SecAlm_ToggleAlarmLed(uint8 PinState)
{
	HAL_GPIO_WritePin(ALARM_LED_PORT, ALARM_LED_PIN, PinState);
}
