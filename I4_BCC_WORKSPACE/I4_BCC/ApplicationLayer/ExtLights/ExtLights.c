#include "tim.h"
#include "CenLoc.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "gpio.h"

uint8_t CurrentState_LowBeam;
uint8_t CurrentState_HighBeam;
uint8_t CurrentState_FogLightFront;
uint8_t CurrentState_FogLightRear;
uint8_t CurrentState_TurnSignalRight;
uint8_t CurrentState_TurnSignalLeft;
uint8_t CurrentState_PositionLightRear;
uint8_t CurrentState_BrakeLight;
uint8_t CurrentState_ReverseLight;
uint8_t CurrentState_HazardLight;
uint8_t BTLowBeam;
uint8_t BTHighBeam;
uint8_t BTFogLightFront;
uint8_t BTFogLightRear;
uint8_t BTPositionLightRear;
uint8_t BTBrakeLight;
uint8_t BTReverseLight;
uint8_t BTTurnSignalRight;
uint8_t BTTurnSignalLeft;
uint8_t BTHazardLight;
uint8_t BTExtLight_IrqFlag;


void ExtLights_MainFunction()
{
	if(BTLowBeam == STD_HIGH)
	{
		CurrentState_LowBeam = BTLowBeam;
	}
	else if(BTLowBeam == STD_LOW)
	{
		CurrentState_LowBeam = BTLowBeam;
	}
	else
	{
		/* do nothing */
	}

	if(BTHighBeam == STD_HIGH)
	{
		CurrentState_HighBeam = BTLowBeam;
	}
	else if(BTHighBeam == STD_LOW)
	{
		CurrentState_HighBeam = BTLowBeam;
	}
	else
	{
		/* do nothing */
	}

	if(BTHighBeam == STD_HIGH)
	{
		CurrentState_HighBeam = BTHighBeam;
	}
	else if(BTHighBeam == STD_LOW)
	{
		CurrentState_HighBeam = BTHighBeam;
	}
	else
	{
		/* do nothing */
	}

	if(BTFogLightFront == STD_HIGH)
	{
		CurrentState_FogLightFront = BTFogLightFront;
	}
	else if(BTFogLightFront == STD_LOW)
	{
		CurrentState_FogLightFront = BTFogLightFront;
	}
	else
	{
		/* do nothing */
	}

	if(BTFogLightRear == STD_HIGH)
	{
		CurrentState_FogLightRear = BTFogLightRear;
	}
	else if(BTFogLightRear == STD_LOW)
	{
		CurrentState_FogLightRear = BTFogLightRear;
	}
	else
	{
		/* do nothing */
	}

	if(BTPositionLightRear == STD_HIGH)
	{
		CurrentState_PositionLightRear = BTPositionLightRear;
	}
	else if(BTPositionLightRear == STD_LOW)
	{
		CurrentState_PositionLightRear = BTPositionLightRear;
	}
	else
	{
		/* do nothing */
	}

	if(BTPositionLightRear == STD_HIGH)
	{
		CurrentState_PositionLightRear = BTPositionLightRear;
	}
	else if(BTPositionLightRear == STD_LOW)
	{
		CurrentState_PositionLightRear = BTPositionLightRear;
	}
	else
	{
		/* do nothing */
	}

	if(BTBrakeLight == STD_HIGH)
	{
		CurrentState_BrakeLight = BTBrakeLight;
	}
	else if(BTBrakeLight == STD_LOW)
	{
		CurrentState_BrakeLight = BTBrakeLight;
	}
	else
	{
		/* do nothing */
	}

	if(BTReverseLight == STD_HIGH)
	{
		CurrentState_ReverseLight = BTReverseLight;
	}
	else if(BTReverseLight == STD_LOW)
	{
		CurrentState_ReverseLight = BTReverseLight;
	}
	else
	{
		/* do nothing */
	}

	if(BTTurnSignalLeft == STD_HIGH)
	{
		CurrentState_TurnSignalLeft = BTTurnSignalLeft;
	}
	else if(BTTurnSignalLeft == STD_LOW)
	{
		CurrentState_TurnSignalLeft = BTTurnSignalLeft;
	}
	else
	{
		/* do nothing */
	}

	if(BTTurnSignalRight == STD_HIGH)
	{
		CurrentState_TurnSignalRight = BTTurnSignalRight;
	}
	else if(BTTurnSignalRight == STD_LOW)
	{
		CurrentState_TurnSignalRight = BTTurnSignalRight;
	}
	else
	{
		/* do nothing */
	}

	if(BTHazardLight == STD_HIGH)
	{
		CurrentState_HazardLight = BTHazardLight;
	}
	else if(BTHazardLight == STD_LOW)
	{
		CurrentState_HazardLight = BTHazardLight;
	}
	else
	{
		/* do nothing */
	}

	if(CurrentState_TurnSignalLeft == STD_HIGH)
	{
		HAL_TIM_Base_Start(&htim2);
		if(__HAL_TIM_GET_COUNTER(&htim2) < 2500)
		{
			ExtLights_TurnSignalLeft(CurrentState_TurnSignalLeft);
		}
		else if(2500 < __HAL_TIM_GET_COUNTER(&htim2)  && __HAL_TIM_GET_COUNTER(&htim2) < 5000)
		{
			ExtLights_TurnSignalLeft(!CurrentState_TurnSignalLeft);
		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 7500)
		{
			ExtLights_TurnSignalLeft(CurrentState_TurnSignalLeft);
		}
		else if(7500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 10000)
		{
			ExtLights_TurnSignalLeft(!CurrentState_TurnSignalLeft);
		}
		else
		{
			/* do nothing */
		}
	}
	else if(CurrentState_TurnSignalLeft == STD_LOW)
	{
		ExtLights_TurnSignalLeft(CurrentState_TurnSignalLeft);
	}
	else
	{
		/* do nothing */
	}

	if(CurrentState_TurnSignalRight == STD_HIGH)
	{
		HAL_TIM_Base_Start(&htim2);
		if(__HAL_TIM_GET_COUNTER(&htim2)< 2500)
		{
			ExtLights_TurnSignalRight(CurrentState_TurnSignalRight);
		}
		else if(2500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 5000)
		{
			ExtLights_TurnSignalRight(!CurrentState_TurnSignalRight);
		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 7500)
		{
			ExtLights_TurnSignalRight(CurrentState_TurnSignalRight);
		}
		else if(7500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 10000)
		{
			ExtLights_TurnSignalRight(!CurrentState_TurnSignalRight);
		}
		else
		{
			/* do nothing */
		}
	}
	else if(CurrentState_TurnSignalRight == STD_LOW)
	{
		ExtLights_TurnSignalRight(CurrentState_TurnSignalRight);
	}
	else
	{
		/* do nothing */
	}

	if(CurrentState_HazardLight == STD_HIGH)
	{
		HAL_TIM_Base_Start(&htim2);
		if(__HAL_TIM_GET_COUNTER(&htim2)< 2500)
		{
			ExtLights_TurnSignalRight(CurrentState_HazardLight);
			ExtLights_TurnSignalLeft(CurrentState_HazardLight);
		}
		else if(2500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 5000)
		{
			ExtLights_TurnSignalRight(!CurrentState_HazardLight);
			ExtLights_TurnSignalLeft(!CurrentState_HazardLight);
		}
		else if(5000 < __HAL_TIM_GET_COUNTER(&htim2)&& __HAL_TIM_GET_COUNTER(&htim2) < 7500)
		{
			ExtLights_TurnSignalRight(CurrentState_HazardLight);
			ExtLights_TurnSignalLeft(CurrentState_HazardLight);
		}
		else if(7500 < __HAL_TIM_GET_COUNTER(&htim2) && __HAL_TIM_GET_COUNTER(&htim2) < 10000)
		{
			ExtLights_TurnSignalRight(!CurrentState_HazardLight);
			ExtLights_TurnSignalLeft(!CurrentState_HazardLight);
		}
		else
		{
			/* do nothing */
		}
	}
	else if(CurrentState_HazardLight == STD_LOW)
	{
		ExtLights_TurnSignalRight(CurrentState_HazardLight);
		ExtLights_TurnSignalLeft(CurrentState_HazardLight);
	}
	else
	{
		/* do nothing */
	}

	ExtLights_LowBeam(CurrentState_LowBeam);
	ExtLights_HighBeam(CurrentState_HighBeam);
	ExtLights_FogLightFront(CurrentState_FogLightFront);
	ExtLights_FogLightRear(CurrentState_FogLightRear);
	ExtLights_PositionLightRear(CurrentState_PositionLightRear);
	ExtLights_BrakeLight(CurrentState_BrakeLight);
	ExtLights_ReverseLight(CurrentState_ReverseLight);
}

StdReturnType ExtLights_Init()
{
	CurrentState_LowBeam = STD_LOW;
	CurrentState_HighBeam = STD_LOW;
	CurrentState_FogLightFront = STD_LOW;
	CurrentState_FogLightRear = STD_LOW;
	CurrentState_TurnSignalLeft = STD_LOW;
	CurrentState_TurnSignalRight = STD_LOW;
	CurrentState_PositionLightRear = STD_LOW;
	CurrentState_BrakeLight = STD_LOW;
	CurrentState_ReverseLight = STD_LOW;
	CurrentState_HazardLight = STD_LOW;
	BTLowBeam = STD_LOW;
	BTHighBeam = STD_LOW;
	BTFogLightFront = STD_LOW;
	BTFogLightRear = STD_LOW;
	BTPositionLightRear = STD_LOW;
	BTBrakeLight = STD_LOW;
	BTReverseLight = STD_LOW;
	BTTurnSignalRight = STD_LOW;
	BTTurnSignalLeft = STD_LOW;
	BTHazardLight = STD_LOW;
	BTExtLight_IrqFlag = STD_LOW;

	return E_OK;
}


void ExtLights_LowBeam(uint8 PinState)
{
	HAL_GPIO_WritePin(LOW_BEAM_PORT, LOW_BEAM_PIN, PinState);
}

void ExtLights_HighBeam(uint8 PinState)
{
	HAL_GPIO_WritePin(HIGH_BEAM_PORT, HIGH_BEAM_PIN, PinState);
}

void ExtLights_FogLightFront(uint8 PinState)
{
	HAL_GPIO_WritePin(FRONT_FOG_LIGHT_PORT, FRONT_FOG_LIGHT_PIN, PinState);
}

void ExtLights_FogLightRear(uint8 PinState)
{
	HAL_GPIO_WritePin(REAR_FOG_LIGHT_PORT, REAR_FOG_LIGHT_PIN, PinState);
}

void ExtLights_TurnSignalLeft(uint8 PinState)
{
	HAL_GPIO_WritePin(LEFT_TURN_SIGNAL_PORT, LEFT_TURN_SIGNAL_PIN, PinState);
}

void ExtLights_TurnSignalRight(uint8 PinState)
{
	HAL_GPIO_WritePin(RIGHT_TURN_SIGNAL_PORT, RIGHT_TURN_SIGNAL_PIN, PinState);
}

void ExtLights_PositionLightRear(uint8 PinState)
{
	HAL_GPIO_WritePin(REAR_POSITION_LIGHT_PORT, REAR_POSITION_LIGHT_PIN, PinState);
}

void ExtLights_BrakeLight(uint8 PinState)
{
	HAL_GPIO_WritePin(BRAKE_LIGHT_PORT, BRAKE_LIGHT_PIN, PinState);
}

void ExtLights_ReverseLight(uint8 PinState)
{
	HAL_GPIO_WritePin(REVERSE_LIGHT_PORT, REVERSE_LIGHT_PIN, PinState);
}
