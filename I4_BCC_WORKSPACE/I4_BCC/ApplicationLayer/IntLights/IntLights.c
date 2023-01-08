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

uint8 IntLights_CurrentState;
uint8 Btc_IntLights;

StdReturnType IntLightsInit();
void IntLightsMainFunction();
void IntLightsToggleIntLights(uint8 PinState);
void IntLightsRxBtcState();

void IntLightsRxBtcState()
{

	if(Btc_IntLights == STD_HIGH)
	{
		IntLights_CurrentState = Btc_IntLights;
	}
	else if(Btc_IntLights == STD_LOW)
	{
		IntLights_CurrentState = Btc_IntLights;
	}
	else
	{
		/* do nothing */
	}

}

void IntLightsMainFunction()
{

	IntLightsToggleIntLights(IntLights_CurrentState);

}

StdReturnType IntLightsInit()
{

	IntLights_CurrentState 	= STD_LOW;
	Btc_IntLights 			= STD_LOW;

	return E_OK;

}

void IntLightsToggleIntLights(uint8 PinState)
{

	HAL_GPIO_WritePin(INTERIOR_LIGHT_PORT, INTERIOR_LIGHT_PIN, PinState);

}
