#include "tim.h"
#include "CenLoc.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "usart.h"
#include "gpio.h"

uint8 CenLoc_CurrentState_Door;
uint8 CenLoc_CurrentState;
uint8 CenLoc_PreviousState;
uint8 CenLoc_LockUnlockFlag;
uint8 CenLoc_ExtLights_UnlockedState;
uint8 CenLoc_ExtLights_LockedState;
uint8 CenLoc_FollowMeHomeState;
uint8 CenLoc_BlinkState;
uint8 CenLoc_LockCounter;
uint8 CenLoc_UnlockCounter;
uint8 Btc_CenLoc;

void CenLocMainFunction();
void CenLocToggleDoorLED(uint8 PinState);
void CenLocRxBtcState();
void CenLocSecAlmStateToOff();
void CenLocFollowMeHome();
void CenLocBlinkSignals();
StdReturnType CenLocInit();
StdReturnType CenLocState();
StdReturnType CenLocLockUnlockStates();

StdReturnType CenLocInit()
{

	CenLoc_CurrentState_Door 		= STD_LOW;
	CenLoc_CurrentState 			= STD_LOW;
	CenLoc_PreviousState 			= STD_LOW;
	CenLoc_LockUnlockFlag 			= STD_LOW;
	CenLoc_ExtLights_UnlockedState 	= STD_LOW;
	CenLoc_ExtLights_LockedState 	= STD_LOW;
	CenLoc_FollowMeHomeState 		= STD_LOW;
	CenLoc_BlinkState 				= STD_LOW;
	CenLoc_LockCounter 				= STD_LOW;
	CenLoc_UnlockCounter			= STD_LOW;
	Btc_CenLoc 						= STD_LOW;

	return E_OK;
}

StdReturnType CenLocState()
{

	uint8 status = E_OK;

	if(CenLoc_PreviousState != CenLoc_CurrentState)
	{

		CenLoc_ExtLights_LockedState 	= CenLoc_PreviousState;
		CenLoc_ExtLights_UnlockedState 	= CenLoc_CurrentState;
		CenLoc_PreviousState 			= CenLoc_CurrentState;
		CenLoc_LockUnlockFlag 			= !CenLoc_CurrentState;
		CenLoc_LockCounter 				= STD_LOW;
		CenLoc_UnlockCounter 			= STD_LOW;
		SecAlmCounter 					= STD_LOW;
		HAL_TIM_Base_Init(&htim2);
		HAL_TIM_Base_Init(&htim3);
		HAL_TIM_Base_Init(&htim5);

	}
	else
	{

		/* do nothing */

	}

	return status;

}

void CenLocSecAlmStateToOff()
{

	if(CenLoc_CurrentState == STD_HIGH)
	{

		SecAlmTrigger = STD_LOW;

	}
	else
	{

		/* do nothing */

	}

}

void CenLocRxBtcState()
{

	if(Btc_CenLoc == STD_HIGH)
	{

		CenLoc_CurrentState = Btc_CenLoc;

	}
	else if(Btc_CenLoc == STD_LOW)
	{

		CenLoc_CurrentState = Btc_CenLoc;

	}
	else
	{

		/* do nothing */

	}

}

void CenLocToggleDoorLED(uint8 PinState)
{

	HAL_GPIO_WritePin(CENLOC_DOOR_LED_PORT, CENLOC_DOOR_LED_PIN, PinState);

}

void CenLocFollowMeHome()
{

	ExtLightsFrontFogLight(CenLoc_FollowMeHomeState);
	ExtLightsLowBeam(CenLoc_FollowMeHomeState);
	ExtLightsRearPositionLight(CenLoc_FollowMeHomeState);

}

void CenLocBlinkSignals()
{

	ExtLightsTurnSignalLeft(CenLoc_BlinkState);
	ExtLightsTurnSignalRight(CenLoc_BlinkState);

}

StdReturnType CenLocLockUnlockStates()
{

	uint8 status = 0;

	if(CenLoc_CurrentState == STD_HIGH && SecAlmTrigger == STD_LOW)
	{

		HAL_TIM_Base_Stop(&htim3);
		Btc_CenLoc = STD_HIGH;
		IntLightsToggleIntLights(CenLoc_CurrentState);
		CenLocToggleDoorLED(CenLoc_CurrentState);
		SecAlmToggleAlarmLed(!CenLoc_CurrentState);

		if(CenLoc_ExtLights_UnlockedState == STD_HIGH && CenLoc_ExtLights_LockedState == STD_LOW)
		{

			HAL_TIM_Base_Start(&htim5);

			if(__HAL_TIM_GET_COUNTER(&htim5) < 100000)
			{

				CenLoc_FollowMeHomeState = STD_HIGH;
				CenLocFollowMeHome();

			}
			else
			{

				CenLoc_FollowMeHomeState 		= STD_LOW;
				CenLoc_ExtLights_UnlockedState 	= STD_LOW;
				CenLoc_ExtLights_LockedState 	= STD_HIGH;
				CenLocFollowMeHome();
				HAL_TIM_Base_Stop(&htim5);

			}

		}
		else
		{

			/* do nothing */

		}

		if(CenLoc_LockCounter < 4)
		{

			HAL_TIM_Base_Start(&htim2);

			if(__HAL_TIM_GET_COUNTER(&htim2) < 2500)
			{

				CenLoc_BlinkState = STD_HIGH;
				CenLocBlinkSignals();

			}
			else if(2500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 5000)
			{

				CenLoc_BlinkState = STD_LOW;
				CenLocBlinkSignals();

			}
			else if(5000 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 7500)
			{

				CenLoc_BlinkState = STD_HIGH;
				CenLocBlinkSignals();

			}
			else if(7500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 10000)
			{

				CenLoc_BlinkState = STD_LOW;
				CenLocBlinkSignals();
				CenLoc_LockCounter = CenLoc_LockCounter + 1;

			}
			else
			{

				/* do nothing */

			}
		}
		else if(CenLoc_LockCounter >= 4)
		{

			HAL_TIM_Base_Stop(&htim5);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(CenLoc_CurrentState == STD_LOW && SecAlmTrigger == STD_LOW)
	{

		Btc_CenLoc = STD_LOW;
		IntLightsToggleIntLights(CenLoc_CurrentState);
		CenLocToggleDoorLED(CenLoc_CurrentState);

		HAL_TIM_Base_Start(&htim3);

		if(CenLoc_ExtLights_UnlockedState == STD_LOW && CenLoc_ExtLights_LockedState == STD_HIGH)
		{

			HAL_TIM_Base_Start(&htim5);

			if(__HAL_TIM_GET_COUNTER(&htim5) < 100000)
			{

				CenLoc_FollowMeHomeState = STD_HIGH;
				CenLocFollowMeHome();

			}
			else if(__HAL_TIM_GET_COUNTER(&htim5) > 100000)
			{

				CenLoc_FollowMeHomeState 		= STD_LOW;
				CenLoc_ExtLights_UnlockedState 	= STD_HIGH;
				CenLoc_ExtLights_LockedState 	= STD_LOW;
				CenLocFollowMeHome();
				HAL_TIM_Base_Stop(&htim5);

			}

		}
		else
		{

			/* do nothing */

		}

		if(40000 < __HAL_TIM_GET_COUNTER(&htim3) && __HAL_TIM_GET_COUNTER(&htim3) < 41250)
		{

			SecAlmToggleAlarmLed(!CenLoc_CurrentState);

		}
		else if(41250 < __HAL_TIM_GET_COUNTER(&htim3) && __HAL_TIM_GET_COUNTER(&htim3) < 42500)
		{

			SecAlmToggleAlarmLed(CenLoc_CurrentState);

		}
		else if(42500 < __HAL_TIM_GET_COUNTER(&htim3) && __HAL_TIM_GET_COUNTER(&htim3) < 43750)
		{

			SecAlmToggleAlarmLed(!CenLoc_CurrentState);

		}
		else if(43750 < __HAL_TIM_GET_COUNTER(&htim3) && __HAL_TIM_GET_COUNTER(&htim3) < 45000)
		{

			SecAlmToggleAlarmLed(CenLoc_CurrentState);

		}
		else
		{

			/* do nothing */

		}

		if(CenLoc_UnlockCounter < 2 && CenLoc_LockUnlockFlag == STD_HIGH)
		{

			HAL_TIM_Base_Start(&htim2);

			if(__HAL_TIM_GET_COUNTER(&htim2) < 2500)
			{

				CenLoc_BlinkState = STD_HIGH;
				CenLocBlinkSignals();

			}
			else if(2500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 5000)
			{

				CenLoc_BlinkState = STD_LOW;
				CenLocBlinkSignals();
				CenLoc_UnlockCounter = CenLoc_UnlockCounter + 1;

			}
			else
			{

				/* do nothing */

			}

		}
		else if(CenLoc_UnlockCounter >= 2)
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

	return status;
}

void CenLocMainFunction()
{

	CenLocRxBtcState();
	CenLocSecAlmStateToOff();
	CenLocState();
	CenLocLockUnlockStates();

}
