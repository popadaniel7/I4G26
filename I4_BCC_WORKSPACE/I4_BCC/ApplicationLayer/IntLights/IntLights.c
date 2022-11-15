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

uint8_t CurrentState_IntLights = 0;
uint8_t BTIntLights = 0;

void IntLights_MainFunction()
{
	// check the current state of the central locking
	// if the car is locked interior lights are OFF
	// if the car is unlocked interior lights are ON
	// interior lights should be turned ON / OFF on external signal

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
