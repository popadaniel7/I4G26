#include "Pdc.h"
#include "TimH.h"
#include "time.h"
#include "SystemManager.h"

StdReturnType Pdc_ReadSensorValue()
{

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_RESET);  // pull the TRIG pin low
	__HAL_TIM_ENABLE_IT(&htim5, TIM_IT_CC3);
	__HAL_TIM_ENABLE_IT(&htim5, TIM_IT_CC4);

	return E_OK;

}

uint8 firstCall = 0;

StdReturnType Pdc_MainFunction()
{



	if(firstCall == 0)
	{

		HAL_TIM_IC_Start_IT(&htim5, TIM_CHANNEL_3);
		HAL_TIM_IC_Start_IT(&htim5, TIM_CHANNEL_4);

		firstCall = 1;

	}

	Pdc_ReadSensorValue();


	return E_OK;

}
