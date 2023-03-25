#include "PortH.h"

StdReturnType Port_Init();
StdReturnType Port_DeInit();

StdReturnType Port_Init()
{

	MX_GPIO_Init();

	return E_OK;

}

StdReturnType Port_DeInit()
{

	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_All);
	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_All);
	HAL_GPIO_DeInit(GPIOC, GPIO_PIN_All);

	return E_OK;

}
