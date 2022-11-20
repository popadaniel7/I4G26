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

uint8_t CurrentState_Door;
uint8_t CurrentState_CenLoc;
uint8_t BTCenLoc;
uint8_t BTCenLoc_IrqFlag;
uint8_t CenLoc_PrevState;

void CenLoc_MainFunction()
{
	uint16_t TimeStampAlarm = 0;
	uint16_t TimeStampExtLights = 0;
	uint16_t TimeStampAlarmLed = 0;

	if(CenLoc_PrevState != BTCenLoc)
	{
		AlarmCount1 = 0;
		AlarmCount2 = 0;
	}
	else
	{
		/* do nothing */
	}

	CenLoc_PrevState = BTCenLoc;

	if(BTCenLoc == STD_HIGH)
	{
		TimeStampAlarm = __HAL_TIM_GET_COUNTER(&htim11);
		TimeStampExtLights = __HAL_TIM_GET_COUNTER(&htim11);
		CurrentState_CenLoc = STD_HIGH;

		CenLoc_Toggle_Door_LED(CurrentState_CenLoc);
		SecAlm_ToggleAlarmLed(!CurrentState_CenLoc);
		IntLights_Toggle_IntLights(CurrentState_CenLoc);

		if(AlarmCount1 < 5)
		{
			if(__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm < 5000)
			{
				SecAlm_ToggleAlarmBuzzer(STD_HIGH);
				AlarmCount1 = AlarmCount1 + 1;
			}
			else if((5000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) < 10000))
			{
				SecAlm_ToggleAlarmBuzzer(STD_LOW);
				AlarmCount1 = AlarmCount1 + 1;
			}
			else if((10000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) < 15000))
			{
				SecAlm_ToggleAlarmBuzzer(STD_HIGH);
				AlarmCount1 = AlarmCount1 + 1;
			}
			else if((15000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) < 20000))
			{
				SecAlm_ToggleAlarmBuzzer(STD_LOW);
				AlarmCount1 = AlarmCount1 + 1;
			}
			else if((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) > 20000)
			{
				SecAlm_ToggleAlarmBuzzer(STD_LOW);
				AlarmCount1 = AlarmCount1 + 1;
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

		if(AlarmCount2 < 4)
		{
			if(__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm < 5000)
			{
				ExtLights_TurnSignalLeft(STD_HIGH);
				ExtLights_TurnSignalRight(STD_HIGH);
				AlarmCount2 = AlarmCount2 + 1;
			}
			else if((5000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) < 10000))
			{
				ExtLights_TurnSignalLeft(STD_LOW);
				ExtLights_TurnSignalRight(STD_LOW);
				AlarmCount2 = AlarmCount2 + 1;
			}
			else if((10000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) < 15000))
			{
				ExtLights_TurnSignalLeft(STD_HIGH);
				ExtLights_TurnSignalRight(STD_HIGH);
				AlarmCount2 = AlarmCount2 + 1;
			}
			else if((15000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) < 20000))
			{
				ExtLights_TurnSignalLeft(STD_LOW);
				ExtLights_TurnSignalRight(STD_LOW);
				AlarmCount2 = AlarmCount2 + 1;
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

		if((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampExtLights) < 100000 && BTLowBeam == 0 && BTFogLightFront == 0 && BTPositionLightRear == 0)
		{
			ExtLights_LowBeam(STD_HIGH);
			ExtLights_FogLightFront(STD_HIGH);
			ExtLights_PositionLightRear(STD_HIGH);
			BTLowBeam = STD_HIGH;
			BTFogLightFront = STD_HIGH;
			BTPositionLightRear = STD_HIGH;
		}
		else if((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampExtLights) > 100000 && BTLowBeam == 1 && BTFogLightFront == 1 && BTPositionLightRear == 1)
		{
			ExtLights_LowBeam(STD_LOW);
			ExtLights_FogLightFront(STD_LOW);
			ExtLights_PositionLightRear(STD_LOW);
			BTLowBeam = STD_LOW;
			BTFogLightFront = STD_LOW;
			BTPositionLightRear = STD_LOW;
		}
		else
		{
			/* do nothing */
		}
	}
	else if(BTCenLoc == STD_LOW)
	{
		TimeStampAlarm = __HAL_TIM_GET_COUNTER(&htim11);
		TimeStampExtLights = __HAL_TIM_GET_COUNTER(&htim11);
		CurrentState_CenLoc = STD_LOW;

		CenLoc_Toggle_Door_LED(CurrentState_CenLoc);
		IntLights_Toggle_IntLights(CurrentState_CenLoc);

		if(__HAL_TIM_GET_COUNTER(&htim11) % 50000 == 0)
		{
			TimeStampAlarmLed = __HAL_TIM_GET_COUNTER(&htim11);

			if(__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarmLed < 2500)
			{
				SecAlm_ToggleAlarmLed(STD_HIGH);
			}
			else if((2500 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarmLed)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarmLed) < 5000))
			{
				SecAlm_ToggleAlarmLed(STD_LOW);
			}
			else if((5000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarmLed)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarmLed) < 7500))
			{
				SecAlm_ToggleAlarmLed(STD_HIGH);
			}
			else if((7500 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarmLed)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarmLed) < 10000))
			{
				SecAlm_ToggleAlarmLed(STD_LOW);
			}
			else
			{
				/* do nothing */
			}
		}
		else
		{
			/* do nothng */
		}

		if(AlarmCount1 < 3)
		{
			if(__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm < 5000)
			{
				SecAlm_ToggleAlarmBuzzer(STD_HIGH);
				AlarmCount1 = AlarmCount1 + 1;
			}
			else if((5000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) < 10000))
			{
				SecAlm_ToggleAlarmBuzzer(STD_LOW);
				AlarmCount1 = AlarmCount1 + 1;
			}
			else if((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) > 10000)
			{
				SecAlm_ToggleAlarmBuzzer(STD_LOW);
				AlarmCount1 = AlarmCount1 + 1;
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

		if(AlarmCount2 < 2)
		{
			if(__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm < 5000)
			{
				ExtLights_TurnSignalLeft(STD_HIGH);
				ExtLights_TurnSignalRight(STD_HIGH);
				AlarmCount2 = AlarmCount2 + 1;
			}
			else if((5000 < (__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm)) && ((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampAlarm) < 10000))
			{
				ExtLights_TurnSignalLeft(STD_LOW);
				ExtLights_TurnSignalRight(STD_LOW);
				AlarmCount2 = AlarmCount2 + 1;
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

		if((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampExtLights) < 100000 && BTLowBeam == 0 && BTFogLightFront == 0 && BTPositionLightRear == 0)
		{
			ExtLights_LowBeam(STD_HIGH);
			ExtLights_FogLightFront(STD_HIGH);
			ExtLights_PositionLightRear(STD_HIGH);
			BTLowBeam = STD_HIGH;
			BTFogLightFront = STD_HIGH;
			BTPositionLightRear = STD_HIGH;
		}
		else if((__HAL_TIM_GET_COUNTER(&htim11) - TimeStampExtLights) > 100000 && BTLowBeam == 1 && BTFogLightFront == 1 && BTPositionLightRear == 1)
		{
			ExtLights_LowBeam(STD_LOW);
			ExtLights_FogLightFront(STD_LOW);
			ExtLights_PositionLightRear(STD_LOW);
			BTLowBeam = STD_LOW;
			BTFogLightFront = STD_LOW;
			BTPositionLightRear = STD_LOW;
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

