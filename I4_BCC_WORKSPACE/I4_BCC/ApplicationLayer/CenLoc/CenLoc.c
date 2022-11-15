#include "CenLoc.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

uint8_t CurrentState_Door = 0;
uint8_t CurrentState_CenLoc = 0;
uint8_t BTCenLoc = 0;

void CenLoc_MainFunction()
{
	uint32_t Timer_TimeStamp = 0;
	uint32_t Timer_SecondTimeStamp = 0;
	uint32_t Timer_SpecialTimeStamp = 0;
	uint32_t Timer_SpecialSecondTimeStamp = 0;



	if(BTCenLoc == 1)
	{
		CurrentState_CenLoc = STD_HIGH;
		IntLights_Toggle_IntLights(CurrentState_CenLoc);
		SecAlm_ToggleAlarmLed(!CurrentState_CenLoc);
		CenLoc_Toggle_Door_LED(CurrentState_CenLoc);


		Timer_SecondTimeStamp = __HAL_TIM_GET_COUNTER(&htim11);
		ExtLights_LowBeam(CurrentState_CenLoc);
		ExtLights_HighBeam(CurrentState_CenLoc);
		ExtLights_FogLightFront(CurrentState_CenLoc);
		ExtLights_FogLightRear(CurrentState_CenLoc);
		ExtLights_PositionLightRear(CurrentState_CenLoc);
		ExtLights_BrakeLight(CurrentState_CenLoc);
		ExtLights_ReverseLight(CurrentState_CenLoc);

		if(Timer_SecondTimeStamp - Timer_TimeStamp >= 10000000)
		{
			ExtLights_LowBeam(!CurrentState_CenLoc);
			ExtLights_HighBeam(!CurrentState_CenLoc);
			ExtLights_FogLightFront(!CurrentState_CenLoc);
			ExtLights_FogLightRear(!CurrentState_CenLoc);
			ExtLights_PositionLightRear(!CurrentState_CenLoc);
			ExtLights_BrakeLight(!CurrentState_CenLoc);
			ExtLights_ReverseLight(!CurrentState_CenLoc);
		}
		else
		{
			/* do nothing */
		}

		if(Timer_SecondTimeStamp - Timer_TimeStamp < 250000)
		{
			SecAlm_ToggleAlarmBuzzer(CurrentState_CenLoc);
			ExtLights_TurnSignalLeft(CurrentState_CenLoc);
			ExtLights_TurnSignalRight(CurrentState_CenLoc);
		}
		else if(250000 < (Timer_SecondTimeStamp - Timer_TimeStamp) < 500000)
		{
			SecAlm_ToggleAlarmBuzzer(!CurrentState_CenLoc);
			ExtLights_TurnSignalLeft(!CurrentState_CenLoc);
			ExtLights_TurnSignalRight(!CurrentState_CenLoc);
		}
		else if(500000 < Timer_SecondTimeStamp - Timer_TimeStamp < 750000)
		{
			SecAlm_ToggleAlarmBuzzer(CurrentState_CenLoc);
			ExtLights_TurnSignalLeft(CurrentState_CenLoc);
			ExtLights_TurnSignalRight(CurrentState_CenLoc);

		}
		else if(750000 < Timer_SecondTimeStamp - Timer_TimeStamp < 1000000)
		{
			SecAlm_ToggleAlarmBuzzer(!CurrentState_CenLoc);
			ExtLights_TurnSignalLeft(!CurrentState_CenLoc);
			ExtLights_TurnSignalRight(!CurrentState_CenLoc);
		}
		else if(Timer_SecondTimeStamp - Timer_TimeStamp > 1000000)
		{
			SecAlm_ToggleAlarmBuzzer(!CurrentState_CenLoc);
			ExtLights_TurnSignalLeft(!CurrentState_CenLoc);
			ExtLights_TurnSignalRight(!CurrentState_CenLoc);
			Timer_TimeStamp = __HAL_TIM_GET_COUNTER(&htim11);
		}
		else
		{
			/* do nothing */
		}
	}
	else if(BTCenLoc == 0)
	{
		CurrentState_CenLoc = STD_LOW;
		IntLights_Toggle_IntLights(CurrentState_CenLoc);
		Timer_SecondTimeStamp = __HAL_TIM_GET_COUNTER(&htim11);
		Timer_SpecialTimeStamp = __HAL_TIM_GET_COUNTER(&htim11);
		CenLoc_Toggle_Door_LED(CurrentState_CenLoc);

		ExtLights_LowBeam(CurrentState_CenLoc);
		ExtLights_HighBeam(CurrentState_CenLoc);
		ExtLights_FogLightFront(CurrentState_CenLoc);
		ExtLights_FogLightRear(CurrentState_CenLoc);
		ExtLights_PositionLightRear(CurrentState_CenLoc);
		ExtLights_BrakeLight(CurrentState_CenLoc);
		ExtLights_ReverseLight(CurrentState_CenLoc);

		if(Timer_SpecialTimeStamp % 5000000 == 0)
		{
			Timer_SpecialSecondTimeStamp = __HAL_TIM_GET_COUNTER(&htim11);

			if(Timer_SpecialSecondTimeStamp - Timer_SpecialTimeStamp < 250000)
			{
				SecAlm_ToggleAlarmLed(!CurrentState_CenLoc);
			}
			else if(250000 < Timer_SpecialSecondTimeStamp - Timer_SpecialTimeStamp < 500000)
			{
				SecAlm_ToggleAlarmLed(CurrentState_CenLoc);
			}
			if(500000 < Timer_SpecialSecondTimeStamp - Timer_SpecialTimeStamp < 750000)
			{
				SecAlm_ToggleAlarmLed(!CurrentState_CenLoc);
			}
			else if(750000 < Timer_SpecialSecondTimeStamp - Timer_SpecialTimeStamp < 1000000)
			{
				SecAlm_ToggleAlarmLed(CurrentState_CenLoc);
			}
			else if(Timer_SpecialSecondTimeStamp - Timer_SpecialTimeStamp > 1000000)
			{
				SecAlm_ToggleAlarmLed(CurrentState_CenLoc);
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

		if(Timer_SecondTimeStamp - Timer_TimeStamp < 250000)
		{
			SecAlm_ToggleAlarmBuzzer(!CurrentState_CenLoc);
			ExtLights_TurnSignalLeft(!CurrentState_CenLoc);
			ExtLights_TurnSignalRight(!CurrentState_CenLoc);
		}
		else if(250000 < Timer_SecondTimeStamp - Timer_TimeStamp < 500000)
		{
			SecAlm_ToggleAlarmBuzzer(CurrentState_CenLoc);
			ExtLights_TurnSignalLeft(CurrentState_CenLoc);
			ExtLights_TurnSignalRight(CurrentState_CenLoc);
		}
		else if(Timer_SecondTimeStamp - Timer_TimeStamp > 500000)
		{
			SecAlm_ToggleAlarmBuzzer(CurrentState_CenLoc);
			ExtLights_TurnSignalLeft(CurrentState_CenLoc);
			ExtLights_TurnSignalRight(CurrentState_CenLoc);
			Timer_TimeStamp = __HAL_TIM_GET_COUNTER(&htim11);
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

uint8_t CenLoc_Init()
{
	CurrentState_Door = STD_LOW;
	CurrentState_CenLoc = STD_LOW;
	BTCenLoc = STD_LOW;

	return E_OK;
}

void CenLoc_Toggle_Door_LED(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, PinState);
}

