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

uint8 CurrentState_Door;
uint8 CurrentState_CenLoc;
uint8 BTCenLoc;
uint8 BTCenLoc_LockUnlockFlag;
uint8 PreviousState_CenLoc;
uint8 ExtLights_UnlockedState;
uint8 ExtLights_LockedState;

void CenLoc_MainFunction()
{
	if(CurrentState_CenLoc == STD_HIGH)
	{
		SecAlmTrigger = STD_LOW;
	}
	else
	{
		/* do nothing */
	}

	if(PreviousState_CenLoc != CurrentState_CenLoc)
	{
		ExtLights_LockedState = PreviousState_CenLoc;
		ExtLights_UnlockedState = CurrentState_CenLoc;
		PreviousState_CenLoc = CurrentState_CenLoc;
		BTCenLoc_LockUnlockFlag = !CurrentState_CenLoc;
		LockCounter = STD_LOW;
		UnlockCounter = STD_LOW;
		SecAlmCounter = STD_LOW;

		HAL_TIM_Base_Init(&htim2);
		HAL_TIM_Base_Init(&htim3);
		HAL_TIM_Base_Init(&htim5);
	}
	else
	{
		/* do nothing */
	}

	if(CurrentState_CenLoc == STD_HIGH && SecAlmTrigger == STD_LOW)
	{
		HAL_TIM_Base_Stop(&htim3);
		BTCenLoc = STD_HIGH;

		IntLights_Toggle_IntLights(CurrentState_CenLoc);
		CenLoc_Toggle_Door_LED(CurrentState_CenLoc);
		SecAlm_ToggleAlarmLed(!CurrentState_CenLoc);

		if(ExtLights_UnlockedState == 1 && ExtLights_LockedState == 0)
		{
			HAL_TIM_Base_Start(&htim5);
			if(__HAL_TIM_GET_COUNTER(&htim5) < 100000)
			{
				ExtLights_FogLightFront(CurrentState_CenLoc);
				ExtLights_LowBeam(CurrentState_CenLoc);
				ExtLights_PositionLightRear(CurrentState_CenLoc);
			}
			else
			{
				ExtLights_FogLightFront(!CurrentState_CenLoc);
				ExtLights_LowBeam(!CurrentState_CenLoc);
				ExtLights_PositionLightRear(!CurrentState_CenLoc);

				ExtLights_UnlockedState = 0;
				ExtLights_LockedState = 1;

				HAL_TIM_Base_Stop(&htim5);
			}
		}
		else
		{
			/* do nothing */
		}

		if(LockCounter < 4)
		{
			HAL_TIM_Base_Start(&htim2);

			if(__HAL_TIM_GET_COUNTER(&htim2) < 2500)
			{
				ExtLights_TurnSignalLeft(CurrentState_CenLoc);
				ExtLights_TurnSignalRight(CurrentState_CenLoc);
			}
			else if(2500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 5000)
			{
				ExtLights_TurnSignalLeft(!CurrentState_CenLoc);
				ExtLights_TurnSignalRight(!CurrentState_CenLoc);
			}
			else if(5000 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 7500)
			{
				ExtLights_TurnSignalLeft(CurrentState_CenLoc);
				ExtLights_TurnSignalRight(CurrentState_CenLoc);
			}
			else if(7500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 10000)
			{
				ExtLights_TurnSignalLeft(!CurrentState_CenLoc);
				ExtLights_TurnSignalRight(!CurrentState_CenLoc);

				LockCounter++;
			}
			else
			{
				/* do nothing */
			}
		}
		else if(LockCounter >= 4)
		{
			HAL_TIM_Base_Stop(&htim2);
		}
		else
		{
			/* do nothing */
		}
	}
	else if(CurrentState_CenLoc == STD_LOW && SecAlmTrigger == STD_LOW)
	{
		BTCenLoc = STD_LOW;
		IntLights_Toggle_IntLights(CurrentState_CenLoc);
		CenLoc_Toggle_Door_LED(CurrentState_CenLoc);

		HAL_TIM_Base_Start(&htim3);

		if(ExtLights_UnlockedState == 0 && ExtLights_LockedState == 1)
		{
			HAL_TIM_Base_Start(&htim5);
			if(__HAL_TIM_GET_COUNTER(&htim5) < 100000)
			{
				ExtLights_FogLightFront(!CurrentState_CenLoc);
				ExtLights_LowBeam(!CurrentState_CenLoc);
				ExtLights_PositionLightRear(!CurrentState_CenLoc);
			}
			else if(__HAL_TIM_GET_COUNTER(&htim5) > 100000)
			{
				ExtLights_FogLightFront(CurrentState_CenLoc);
				ExtLights_LowBeam(CurrentState_CenLoc);
				ExtLights_PositionLightRear(CurrentState_CenLoc);

				ExtLights_UnlockedState = 1;
				ExtLights_LockedState = 0;

				HAL_TIM_Base_Stop(&htim5);
			}
		}
		else
		{
			/* do nothing */
		}

		if(40000 < __HAL_TIM_GET_COUNTER(&htim3) && __HAL_TIM_GET_COUNTER(&htim3) < 41250)
		{
			SecAlm_ToggleAlarmLed(!CurrentState_CenLoc);
		}
		else if(41250 < __HAL_TIM_GET_COUNTER(&htim3) && __HAL_TIM_GET_COUNTER(&htim3) < 42500)
		{
			SecAlm_ToggleAlarmLed(CurrentState_CenLoc);
		}
		else if(42500 < __HAL_TIM_GET_COUNTER(&htim3) && __HAL_TIM_GET_COUNTER(&htim3) < 43750)
		{
			SecAlm_ToggleAlarmLed(!CurrentState_CenLoc);
		}
		else if(43750 < __HAL_TIM_GET_COUNTER(&htim3) && __HAL_TIM_GET_COUNTER(&htim3) < 45000)
		{
			SecAlm_ToggleAlarmLed(CurrentState_CenLoc);
		}
		else
		{
			/* do nothing */
		}

		if(UnlockCounter < 2 && BTCenLoc_LockUnlockFlag == STD_HIGH)
		{
			HAL_TIM_Base_Start(&htim2);

			if(__HAL_TIM_GET_COUNTER(&htim2) < 2500)
			{
				ExtLights_TurnSignalLeft(!CurrentState_CenLoc);
				ExtLights_TurnSignalRight(!CurrentState_CenLoc);
			}
			else if(2500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 5000)
			{
				ExtLights_TurnSignalLeft(CurrentState_CenLoc);
				ExtLights_TurnSignalRight(CurrentState_CenLoc);

				UnlockCounter++;
			}
			else
			{
				/* do nothing */
			}
		}
		else if(UnlockCounter >= 2)
		{
			HAL_TIM_Base_Stop(&htim2);
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

StdReturnType CenLoc_Init()
{
	CurrentState_CenLoc = STD_LOW;
	BTCenLoc = STD_LOW;
	BTCenLoc_LockUnlockFlag = STD_LOW;
	PreviousState_CenLoc = STD_LOW;
	ExtLights_UnlockedState = STD_LOW;
	ExtLights_LockedState = STD_LOW;

	return E_OK;
}

void CenLoc_Toggle_Door_LED(uint8 PinState)
{
	HAL_GPIO_WritePin(DOOR_LED_PORT, DOOR_LED_PIN, PinState);
}

