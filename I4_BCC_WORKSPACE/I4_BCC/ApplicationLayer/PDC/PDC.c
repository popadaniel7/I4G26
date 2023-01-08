#include "PDC.h"
#include "tim.h"
#include "FreeRTOS.h"
#include "main.h"
#include "timers.h"

uint8 Pdc_FrontRxDelay;
uint8 Pdc_FrontEchoFirstTimeStampValue;
uint8 Pdc_FrontEchoSecondTimeStampValue;
uint8 Pdc_FrontDistanceValue;
uint8 Pdc_TimerValueForFrontBuzzer;
uint8 Pdc_RearRxDelay;
uint8 Pdc_RearEchoFirstTimeStampValue;
uint8 Pdc_RearEchoSecondTimeStampValue;
uint8 Pdc_RearDistanceValue;
uint8 Pdc_TimerValueForRearBuzzer;
uint8 Pdc_RearGenerateDelayFlag;
uint8 Pdc_FrontGenerateDelayFlag;
uint8 Pdc_FrontDelayStatus;
uint8 Pdc_RearDelayStatus;
uint8 Pdc_SecondRearGenerateDelayFlag;
uint8 Pdc_SecondFrontGenerateDelayFlag;
uint8 Pdc_SecondFrontDelayStatus;
uint8 Pdc_SecondRearDelayStatus;

StdReturnType PdcInit();
StdReturnType PdcReadFrontEchoPin();
StdReturnType PdcReadRearEchoPin();
void PdcMainFunction();
void PdcToggleFrontTriggerPin(uint8 PinState);
void PdcToggleRearTriggerPin(uint8 PinState);
void PdcFrontDistance();
void PdcRearDistance();
void PdcFrontGenerateDelay();
void PdcRearGenerateDelay();
void PdcFrontBuzzerControl();
void PdcRearBuzzerControl();
void PdcFrontStatus();
void PdcRearStatus();

void PdcRearGenerateDelay()
{

	Pdc_RearGenerateDelayFlag = STD_LOW;

	if(Pdc_RearGenerateDelayFlag == STD_HIGH)
	{

		Pdc_RearDelayStatus = STD_HIGH;

	}
	else if(Pdc_RearGenerateDelayFlag == STD_LOW)
	{

		Pdc_RearDelayStatus = STD_LOW;

	}
	else
	{

		/* do nothing */

	}

}

void PdcFrontGenerateDelay()
{

	Pdc_FrontGenerateDelayFlag 			= STD_LOW;
	Pdc_SecondFrontGenerateDelayFlag 	= STD_LOW;

	if(Pdc_FrontGenerateDelayFlag == STD_HIGH)
	{

		Pdc_FrontDelayStatus = STD_HIGH;

	}
	else if(Pdc_FrontGenerateDelayFlag == STD_LOW)
	{

		Pdc_FrontDelayStatus = STD_LOW;

	}
	else
	{

		/* do nothing */

	}

	if(Pdc_SecondFrontGenerateDelayFlag == STD_HIGH)
	{

		Pdc_SecondFrontDelayStatus = STD_HIGH;

	}
	else if(Pdc_SecondFrontGenerateDelayFlag == STD_LOW)
	{

		Pdc_SecondFrontDelayStatus = STD_LOW;

	}
	else
	{

		/* do nothing */

	}

}

void PdcFrontStatus()
{

	TickType_t expiry_time 	= 0;
	uint8 echoValue 		= 0;

	osTimerStart(PdcFrontGlobalTimerHandle, 10000);
	xTimerStart(PdcFrontGlobalTimerHandle, 0);
	PdcToggleFrontTriggerPin(STD_LOW);
	PdcToggleFrontTriggerPin(STD_HIGH);
	osTimerStart(PdcFrontDelayTimerHandle, PDC_DELAY_VALUE_TEN);
	PdcFrontGenerateDelay();

	if(Pdc_FrontDelayStatus == STD_HIGH)
	{

		PdcToggleFrontTriggerPin(STD_LOW);
		osTimerStop(PdcFrontDelayTimerHandle);

	}
	else
	{

		/* do nothing */

	}

	echoValue = PdcReadFrontEchoPin();

	if(echoValue == STD_HIGH)
	{

		Pdc_FrontRxDelay = HAL_GetTick();
		osTimerStart(PdcSecondFrontDelayTimerHandle, Pdc_FrontRxDelay + 10);
		PdcFrontGenerateDelay();

		if(Pdc_SecondFrontDelayStatus == STD_HIGH)
		{

			expiry_time = xTimerGetExpiryTime(PdcFrontGlobalTimerHandle);
			Pdc_FrontEchoFirstTimeStampValue = expiry_time;

		}
		else
		{

			/* do nothing */

		}

	}

	echoValue = PdcReadFrontEchoPin();

	if(echoValue == STD_HIGH)
	{

		Pdc_FrontRxDelay = HAL_GetTick();
		osTimerStart(PdcSecondFrontDelayTimerHandle, Pdc_FrontRxDelay + 50);
		PdcFrontGenerateDelay();

		if(Pdc_SecondFrontDelayStatus == STD_HIGH)
		{

			expiry_time = xTimerGetExpiryTime(PdcFrontGlobalTimerHandle);
			Pdc_FrontEchoSecondTimeStampValue = expiry_time;

		}
		else
		{

			/* do nothing */

		}

	}

	PdcFrontDistance();

}

void PdcRearStatus()
{

	TickType_t expiry_time 	= 0;
	uint8 echoValue 		= 0;

	osTimerStart(PdcRearGlobalTimerHandle, 10000);
	xTimerStart(PdcRearGlobalTimerHandle, 0);
	PdcToggleRearTriggerPin(STD_LOW);
	PdcToggleRearTriggerPin(STD_HIGH);
	osTimerStart(PdcRearDelayTimerHandle, 10);
	PdcRearGenerateDelay();

	if(Pdc_RearDelayStatus == STD_HIGH)
	{

		PdcToggleRearTriggerPin(STD_LOW);
		osTimerStop(PdcRearDelayTimerHandle);

	}
	else
	{

		/* do nothing */

	}

	echoValue = PdcReadRearEchoPin();

	if(echoValue == STD_HIGH)
	{

		Pdc_RearRxDelay = HAL_GetTick();
		osTimerStart(PdcSecondRearDelayTimerHandle, Pdc_RearRxDelay + 10);
		PdcRearGenerateDelay();

		if(Pdc_SecondRearDelayStatus == STD_HIGH)
		{

			expiry_time = xTimerGetExpiryTime(PdcRearGlobalTimerHandle);
			Pdc_RearEchoFirstTimeStampValue = expiry_time;

		}
		else
		{

			/* do nothing */

		}

	}

	echoValue = PdcReadRearEchoPin();

	if(echoValue == STD_HIGH)
	{

		Pdc_RearRxDelay = HAL_GetTick();
		osTimerStart(PdcSecondRearDelayTimerHandle, Pdc_RearRxDelay + 50);
		PdcFrontGenerateDelay();

		if(Pdc_SecondFrontDelayStatus == STD_HIGH)
		{

			expiry_time = xTimerGetExpiryTime(PdcRearGlobalTimerHandle);
			Pdc_RearEchoSecondTimeStampValue = expiry_time;

		}
		else
		{

			/* do nothing */

		}

	}

	PdcRearDistance();

}

void PdcToggleFrontTriggerPin(uint8 PinState)
{

	HAL_GPIO_WritePin(PDC_FRONT_TRIGGER_PORT, PDC_FRONT_TRIGGER_PIN, PinState);

}

void PdcToggleRearTriggerPin(uint8 PinState)
{

	HAL_GPIO_WritePin(PDC_FRONT_TRIGGER_PORT, PDC_FRONT_TRIGGER_PIN, PinState);

}

StdReturnType PdcReadFrontEchoPin()
{

	uint8 pinValue = 0;

	pinValue = HAL_GPIO_ReadPin(PDC_FRONT_ECHO_PORT, PDC_FRONT_ECHO_PIN);

	return pinValue;

}

StdReturnType PdcReadRearEchoPin()
{

	uint8 pinValue = 0;

	pinValue = HAL_GPIO_ReadPin(PDC_REAR_ECHO_PORT, PDC_REAR_ECHO_PIN);

	return pinValue;

}

void PdcFrontDistance()
{

	Pdc_FrontDistanceValue = (Pdc_FrontEchoFirstTimeStampValue + Pdc_FrontEchoSecondTimeStampValue) * 0.034 / 2;

}


void PdcRearDistance()
{

	Pdc_RearDistanceValue = (Pdc_RearEchoFirstTimeStampValue + Pdc_RearEchoSecondTimeStampValue) * 0.034 / 2;

}

void PdcRearBuzzerControl()
{

	HAL_TIM_Base_Start(&htim9);

	if(Pdc_RearDistanceValue <= PDC_SAFETY_DISTANCE_ONE)
	{

		if(__HAL_TIM_GET_COUNTER(&htim9) < 5000)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_HIGH);

		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim9) && __HAL_TIM_GET_COUNTER(&htim9) < 10000)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_LOW);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(Pdc_RearDistanceValue <= PDC_SAFETY_DISTANCE_TWO)
	{

		if(__HAL_TIM_GET_COUNTER(&htim9) < 2500)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_HIGH);

		}
		else if(2500 < __HAL_TIM_GET_COUNTER(&htim9)  && __HAL_TIM_GET_COUNTER(&htim9) < 5000)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_LOW);

		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim9)  && __HAL_TIM_GET_COUNTER(&htim9) < 7500)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_HIGH);

		}
		else if(7500 < __HAL_TIM_GET_COUNTER(&htim9)  && __HAL_TIM_GET_COUNTER(&htim9) < 10000)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_LOW);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(Pdc_RearDistanceValue <= PDC_SAFETY_DISTANCE_THREE)
	{

		if(__HAL_TIM_GET_COUNTER(&htim9) < 1250)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_HIGH);

		}
		else if(1250 < __HAL_TIM_GET_COUNTER(&htim9)  && __HAL_TIM_GET_COUNTER(&htim9) < 2500)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_LOW);

		}
		else if(2500 < __HAL_TIM_GET_COUNTER(&htim9)  && __HAL_TIM_GET_COUNTER(&htim9) < 5000)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_HIGH);

		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim9)  && __HAL_TIM_GET_COUNTER(&htim9) < 7500)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_LOW);

		}
		else if(7500 < __HAL_TIM_GET_COUNTER(&htim9)  && __HAL_TIM_GET_COUNTER(&htim9) < 10000)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_HIGH);

		}
		else if(__HAL_TIM_GET_COUNTER(&htim9) == 10000)
		{

			HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_LOW);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(Pdc_RearDistanceValue <= PDC_SAFETY_DISTANCE_FOUR)
	{

		HAL_GPIO_WritePin(PDC_REAR_BUZZER_PORT, PDC_REAR_BUZZER_PIN, STD_HIGH);

	}
	else
	{

		/* do nothing */

	}

}

void PdcFrontBuzzerControl()
{

	HAL_TIM_Base_Start(&htim9);

	if(Pdc_FrontDistanceValue <= PDC_SAFETY_DISTANCE_ONE)
	{

		if(__HAL_TIM_GET_COUNTER(&htim10) < 5000)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_HIGH);

		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim10)  && __HAL_TIM_GET_COUNTER(&htim10) < 10000)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_LOW);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(Pdc_FrontDistanceValue <= PDC_SAFETY_DISTANCE_TWO)
	{

		if(__HAL_TIM_GET_COUNTER(&htim10) < 2500)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_HIGH);

		}
		else if(2500 < __HAL_TIM_GET_COUNTER(&htim10)  && __HAL_TIM_GET_COUNTER(&htim10) < 5000)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_LOW);

		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim10)  && __HAL_TIM_GET_COUNTER(&htim10) < 7500)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_HIGH);

		}
		else if(7500 < __HAL_TIM_GET_COUNTER(&htim10)  && __HAL_TIM_GET_COUNTER(&htim10) < 10000)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_LOW);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(Pdc_FrontDistanceValue <= PDC_SAFETY_DISTANCE_THREE)
	{

		if(__HAL_TIM_GET_COUNTER(&htim10) < 1250)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_HIGH);

		}
		else if(1250 < __HAL_TIM_GET_COUNTER(&htim10)  && __HAL_TIM_GET_COUNTER(&htim10) < 2500)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_LOW);

		}
		else if(2500 < __HAL_TIM_GET_COUNTER(&htim10)  && __HAL_TIM_GET_COUNTER(&htim10) < 5000)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_HIGH);

		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim10)  && __HAL_TIM_GET_COUNTER(&htim10) < 7500)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_LOW);

		}
		else if(7500 < __HAL_TIM_GET_COUNTER(&htim10)  && __HAL_TIM_GET_COUNTER(&htim10) < 10000)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_HIGH);

		}
		else if(__HAL_TIM_GET_COUNTER(&htim10) == 10000)
		{

			HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_LOW);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(Pdc_FrontDistanceValue <= PDC_SAFETY_DISTANCE_FOUR)
	{

		HAL_GPIO_WritePin(PDC_FRONT_BUZZER_PORT, PDC_FRONT_BUZZER_PIN, STD_HIGH);

	}
	else
	{

		/* do nothing */

	}

}

void PdcMainFunction()
{

	PdcFrontStatus();
	PdcRearStatus();

}

StdReturnType PdcInit()
{

	Pdc_FrontRxDelay 					= STD_LOW;
	Pdc_FrontEchoFirstTimeStampValue 	= STD_LOW;
	Pdc_FrontEchoSecondTimeStampValue 	= STD_LOW;
	Pdc_FrontDistanceValue 				= STD_LOW;
	Pdc_TimerValueForFrontBuzzer 		= STD_LOW;
	Pdc_RearRxDelay 					= STD_LOW;
	Pdc_RearEchoFirstTimeStampValue 	= STD_LOW;
	Pdc_RearEchoSecondTimeStampValue 	= STD_LOW;
	Pdc_RearDistanceValue 				= STD_LOW;
	Pdc_TimerValueForRearBuzzer 		= STD_LOW;
	Pdc_RearGenerateDelayFlag			= STD_LOW;
	Pdc_FrontGenerateDelayFlag 			= STD_LOW;
	Pdc_FrontDelayStatus 				= STD_LOW;
	Pdc_SecondRearGenerateDelayFlag 	= STD_LOW;
	Pdc_SecondFrontGenerateDelayFlag 	= STD_LOW;
	Pdc_SecondFrontDelayStatus 			= STD_LOW;
	Pdc_SecondRearDelayStatus 			= STD_LOW;
	HAL_TIM_Base_Init(&htim9);
	HAL_TIM_Base_Init(&htim10);

	return E_OK;

}
