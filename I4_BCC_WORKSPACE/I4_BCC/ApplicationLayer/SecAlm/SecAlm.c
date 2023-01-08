#include "tim.h"
#include "CenLoc.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "Std_Types.h"
#include "usart.h"
#include "gpio.h"

uint8 SecAlmTrigger;
uint8 SecAlmCounter;
uint8 SecAlm_PreviousState;
uint8 SecAlmVibSenStatusFlag;
uint8 SecAlmVibSenStateSetToOff;
uint8 SecAlmPinStateChange;

StdReturnType SecAlmVibSenStatus();
StdReturnType SecAlmVibeSenReadPin();
StdReturnType SecAlmInit();
void SecAlmMainFunction();
void SecAlmToggleAlarmBuzzer(uint8 PinState);
void SecAlmToggleAlarmLed(uint8 PinState);
void SecAlmState();
void SecAlmLightsBuzzerControl();
void SecAlmTurnOnExtLights();

StdReturnType SecAlmVibeSenReadPin()
{

	uint8 PinState = 0;

	PinState = HAL_GPIO_ReadPin(SECALM_VIBSEN_PORT, SECALM_VIBSEN_PIN);

	return PinState;

}

StdReturnType SecAlmVibSenStatus()
{

	SecAlmVibSenStatusFlag = SecAlmVibeSenReadPin();

	if(CenLoc_CurrentState == STD_HIGH)
	{

		SecAlmVibSenStateSetToOff = STD_HIGH;

	}
	else if(CenLoc_CurrentState == STD_LOW)
	{

		SecAlmVibSenStateSetToOff = STD_LOW;

	}
	else
	{

		/* do nothing */

	}

	if(SecAlmVibSenStateSetToOff == STD_LOW && SecAlmVibSenStatusFlag == STD_LOW)
	{

		return STD_HIGH;

	}
	else
	{

		/* do nothing */

	}

	return STD_LOW;

}

void SecAlmState()
{

	if(SecAlm_PreviousState != SecAlmTrigger)
	{

		HAL_TIM_Base_Init(&htim5);
		SecAlm_PreviousState = SecAlmTrigger;

	}
	else
	{

		/* do nothing */

	}

	if(SecAlmVibSenStatus() == STD_HIGH)
	{

		SecAlmTrigger = SecAlmVibSenStatus();

	}
	else if(SecAlmVibSenStatus() == STD_LOW)
	{

		SecAlmTrigger = SecAlmVibSenStatus();

	}
	else
	{

		/* do nothing */

	}

}

void SecAlmTurnOnExtLights()
{

	ExtLightsLowBeam(SecAlmPinStateChange);
	ExtLightsRearPositionLight(SecAlmPinStateChange);
	ExtLightsFrontFogLight(SecAlmPinStateChange);
	ExtLightsRearFogLight(SecAlmPinStateChange);
	ExtLightsTurnSignalRight(SecAlmPinStateChange);
	ExtLightsTurnSignalLeft(SecAlmPinStateChange);

}

void SecAlmLightsBuzzerControl()
{

	SecAlmState();

	if(SecAlmTrigger == STD_HIGH)
	{

		HAL_TIM_Base_Start(&htim5);

		if(__HAL_TIM_GET_COUNTER(&htim5) < 100000)
		{

			HAL_TIM_Base_Start(&htim4);

			if(__HAL_TIM_GET_COUNTER(&htim4) < 5000)
			{

				SecAlmPinStateChange = STD_HIGH;
				SecAlmTurnOnExtLights();

			}
			else if(5000 < __HAL_TIM_GET_COUNTER(&htim4) && __HAL_TIM_GET_COUNTER(&htim4) < 10000)
			{
				SecAlmPinStateChange = STD_LOW;
				SecAlmTurnOnExtLights();
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
		SecAlmPinStateChange = STD_LOW;
		SecAlmTurnOnExtLights();

	}
	else
	{

		/* do nothing */

	}

}

void SecAlmMainFunction()
{

	SecAlmLightsBuzzerControl();

}

StdReturnType SecAlmInit()
{

	SecAlmTrigger 				= STD_LOW;
	SecAlmCounter 				= STD_LOW;
	SecAlm_PreviousState 		= STD_LOW;
	SecAlmVibSenStatusFlag 		= STD_LOW;
	SecAlmVibSenStateSetToOff 	= STD_LOW;
	SecAlmPinStateChange 		= STD_LOW;

	return E_OK;

}

void SecAlmToggleAlarmBuzzer(uint8 PinState)
{

	HAL_GPIO_WritePin(SECALM_BUZZER_PORT, SECALM_BUZZER_PIN, PinState);

}

void SecAlmToggleAlarmLed(uint8 PinState)
{

	HAL_GPIO_WritePin(SECALM_LED_PORT, SECALM_LED_PIN, PinState);

}
