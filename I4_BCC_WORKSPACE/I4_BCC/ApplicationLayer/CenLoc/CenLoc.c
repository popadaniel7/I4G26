#include "tim.h"
#include "CenLoc.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "main.h"
#include "timers.h"

uint8 CenLoc_CurrentState;
uint8 CenLoc_PreviousState;
uint8 CenLoc_LockUnlockFlag;
uint8 CenLoc_ExtLights_UnlockedState;
uint8 CenLoc_ExtLights_LockedState;
uint8 CenLoc_FollowMeHomeState;
uint8 CenLoc_BlinkState;
uint8 CenLoc_LockCounter;
uint8 CenLoc_UnlockCounter;
uint8 CenLoc_AlarmLedChangeState;
uint8 Btc_CenLoc;
static uint8 localPreviousState = STD_LOW;
uint8 CenLoc_Tim2IRQFlag;
uint8 CenLoc_Tim3IRQFlag;
uint8 CenLoc_Tim5IRQFlag;
uint8 CenLoc_Tim11IRQFlag;

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
		CenLoc_Tim2IRQFlag 				= STD_LOW;
		CenLoc_Tim5IRQFlag 				= STD_LOW;
		CenLoc_Tim3IRQFlag				= STD_LOW;
		CenLoc_Tim11IRQFlag				= STD_LOW;

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

		SecAlm_Trigger = STD_LOW;


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

	if(CenLoc_Tim5IRQFlag == 1)
	{

		ExtLightsFrontFogLight(STD_HIGH);
		ExtLightsDayTimeRunningLight(STD_HIGH);
		ExtLightsLowBeam(STD_HIGH);
		ExtLightsRearPositionLight(STD_HIGH);

	}
	else if(CenLoc_Tim5IRQFlag == 2)
	{

		ExtLightsFrontFogLight(STD_LOW);
		ExtLightsDayTimeRunningLight(STD_LOW);
		ExtLightsLowBeam(STD_LOW);
		ExtLightsRearPositionLight(STD_LOW);
		HAL_TIM_Base_Stop_IT(&htim5);

	}
	else
	{

		/* do nothing */

	}

}

void CenLocBlinkSignals()
{

	ExtLightsTurnSignalLeft(CenLoc_BlinkState);
	ExtLightsTurnSignalRight(CenLoc_BlinkState);

}

StdReturnType CenLocLockUnlockStates()
{

	uint8 status = STD_LOW;


	if(CenLoc_CurrentState == STD_HIGH && SecAlm_Trigger == STD_LOW)
	{

		HAL_TIM_Base_Stop_IT(&htim3);
		HAL_TIM_Base_Start_IT(&htim5);
		__HAL_TIM_SET_COUNTER(&htim3, 0);
		CenLocToggleDoorLED(CenLoc_CurrentState);
		SecAlmToggleAlarmLed(!CenLoc_CurrentState);
		CenLocFollowMeHome();
		localPreviousState = STD_HIGH;

		if(CenLoc_Tim2IRQFlag <= 4)
		{

			HAL_TIM_Base_Start_IT(&htim2);

			switch(CenLoc_Tim2IRQFlag)
			{

				case 1:

					CenLoc_BlinkState = STD_HIGH;
					CenLocToggleBuzzer(CenLoc_BlinkState);
					CenLocBlinkSignals();

					break;

				case 2:

					CenLoc_BlinkState = STD_LOW;
					CenLocToggleBuzzer(CenLoc_BlinkState);
					CenLocBlinkSignals();

					break;

				case 3:

					CenLoc_BlinkState = STD_HIGH;
					CenLocToggleBuzzer(CenLoc_BlinkState);
					CenLocBlinkSignals();

					break;

				case 4:

					CenLoc_BlinkState = STD_LOW;
					CenLocToggleBuzzer(CenLoc_BlinkState);
					CenLocBlinkSignals();

					break;

				default:

					break;

			}

		}
		else if(CenLoc_Tim2IRQFlag == 5)
		{

			HAL_TIM_Base_Stop_IT(&htim2);
			__HAL_TIM_SET_COUNTER(&htim2, 0);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(CenLoc_CurrentState == STD_LOW && SecAlm_Trigger == STD_LOW)
	{

		CenLocToggleDoorLED(CenLoc_CurrentState);
		CenLocFollowMeHome();
		HAL_TIM_Base_Start_IT(&htim3);

		if(CenLoc_Tim3IRQFlag == 2)
		{

			HAL_TIM_Base_Start_IT(&htim11);

			if(CenLoc_Tim11IRQFlag == 1)
			{

				SecAlmToggleAlarmLed(1);

			}
			else if(CenLoc_Tim11IRQFlag > 1)
			{

				SecAlmToggleAlarmLed(0);
				CenLoc_Tim11IRQFlag = 0;
				CenLoc_Tim3IRQFlag = 1;
				HAL_TIM_Base_Stop_IT(&htim11);

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

		if(CenLoc_Tim2IRQFlag <= 2 && localPreviousState == STD_HIGH)
		{

			HAL_TIM_Base_Start_IT(&htim2);

			switch(CenLoc_Tim2IRQFlag)
			{

			case 1:

				CenLoc_BlinkState = STD_HIGH;
				CenLocToggleBuzzer(CenLoc_BlinkState);
				CenLocBlinkSignals();

				break;

			case 2:

				CenLoc_BlinkState = STD_LOW;
				CenLocToggleBuzzer(CenLoc_BlinkState);
				CenLocBlinkSignals();
				localPreviousState = STD_LOW;

				break;

			default:

				break;

			}

		}
		else if(CenLoc_Tim2IRQFlag == 3)
		{

			HAL_TIM_Base_Stop_IT(&htim2);
			__HAL_TIM_SET_COUNTER(&htim2, 0);

		}
		else
		{
			/* do nothing */
		}

	}

	return status;

}

void CenLocToggleBuzzer(uint8 PinState)
{

	HAL_GPIO_WritePin(CENLOC_BUZZER_PORT, CENLOC_BUZZER_PIN, PinState);

}

void CenLocMainFunction()
{

	CenLocRxBtcState();
	CenLocState();
	CenLocSecAlmStateToOff();
	CenLocLockUnlockStates();

}
