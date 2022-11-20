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

uint8_t PrevState_UserButton;
uint8_t NextState_UserButton;
uint8_t CurrentState_UserButton;
uint8_t CurrentState_Alarm_Buzzer;
uint8_t CurrentState_Alarm_LED;
uint8_t AlarmCount1;
uint8_t AlarmCount2;
uint8_t SecAlmTrigger;

void SecAlm_MainFunction()
{
	uint16_t TimeStampSecAlm = 0;

	if(SecAlmTrigger == STD_HIGH)
	{
		TimeStampSecAlm = __HAL_TIM_GET_COUNTER(&htim11);

		if(__HAL_TIM_GET_COUNTER(&htim11) - TimeStampSecAlm < 5000)
		{
			SecAlm_ToggleAlarmBuzzer(SecAlmTrigger);
			SecAlm_ToggleAlarmLed(SecAlmTrigger);
			ExtLights_LowBeam(SecAlmTrigger);
			ExtLights_PositionLightRear(SecAlmTrigger);
			ExtLights_FogLightFront(SecAlmTrigger);
			ExtLights_FogLightRear(SecAlmTrigger);
			ExtLights_TurnSignalRight(SecAlmTrigger);
			ExtLights_TurnSignalLeft(SecAlmTrigger);
		}
		else if((5000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampSecAlm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampSecAlm) < 10000))
		{
			SecAlm_ToggleAlarmBuzzer(!SecAlmTrigger);
			SecAlm_ToggleAlarmLed(!SecAlmTrigger);
			ExtLights_LowBeam(!SecAlmTrigger);
			ExtLights_PositionLightRear(!SecAlmTrigger);
			ExtLights_FogLightFront(!SecAlmTrigger);
			ExtLights_FogLightRear(!SecAlmTrigger);
			ExtLights_TurnSignalRight(!SecAlmTrigger);
			ExtLights_TurnSignalLeft(!SecAlmTrigger);
		}
		else if((10000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampSecAlm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampSecAlm) < 15000))
		{
			SecAlm_ToggleAlarmBuzzer(SecAlmTrigger);
			SecAlm_ToggleAlarmLed(SecAlmTrigger);
			ExtLights_LowBeam(SecAlmTrigger);
			ExtLights_PositionLightRear(SecAlmTrigger);
			ExtLights_FogLightFront(SecAlmTrigger);
			ExtLights_FogLightRear(SecAlmTrigger);
			ExtLights_TurnSignalRight(SecAlmTrigger);
			ExtLights_TurnSignalLeft(SecAlmTrigger);
		}
		else if((15000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampSecAlm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampSecAlm) < 20000))
		{
			SecAlm_ToggleAlarmBuzzer(!SecAlmTrigger);
			SecAlm_ToggleAlarmLed(!SecAlmTrigger);
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
	else if(SecAlmTrigger == STD_LOW)
	{
		SecAlm_ToggleAlarmBuzzer(SecAlmTrigger);
		SecAlm_ToggleAlarmLed(SecAlmTrigger);
		ExtLights_LowBeam(SecAlmTrigger);
		ExtLights_PositionLightRear(SecAlmTrigger);
		ExtLights_FogLightFront(SecAlmTrigger);
		ExtLights_FogLightRear(SecAlmTrigger);
		ExtLights_TurnSignalRight(SecAlmTrigger);
		ExtLights_TurnSignalLeft(SecAlmTrigger);
	}
}

uint8_t SecAlm_Init()
{
	PrevState_UserButton = STD_LOW;
	NextState_UserButton = STD_LOW;
	CurrentState_UserButton = STD_LOW;
	CurrentState_Alarm_Buzzer = STD_LOW;
	CurrentState_Alarm_LED = STD_LOW;
	AlarmCount1 = STD_LOW;
	AlarmCount2 = STD_LOW;
	SecAlmTrigger = STD_LOW;

	return E_OK;
}

void SecAlm_ToggleAlarmBuzzer(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, PinState);
}

void SecAlm_ToggleAlarmLed(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, PinState);
}
