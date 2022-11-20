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

uint8_t CurrentState_IntLights;
uint8_t BTIntLights;

void IntLights_MainFunction()
{
	if(BTIntLights == STD_HIGH)
	{
		CurrentState_IntLights = STD_HIGH;
	}
	else if(BTIntLights == STD_LOW)
	{
		CurrentState_IntLights = STD_LOW;
	}
	else
	{
		/* do nothing */
	}

	IntLights_Toggle_IntLights(CurrentState_IntLights);
}

uint8_t IntLights_Init()
{
	CurrentState_IntLights = STD_LOW;
	BTIntLights = STD_LOW;

	return E_OK;
}

void IntLights_Toggle_IntLights(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, PinState);
}
