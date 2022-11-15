#include "CenLoc.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "gpio.h"

uint8_t CurrentState_LowBeam = 0;
uint8_t CurrentState_HighBeam = 0;
uint8_t CurrentState_FogLightFront = 0;
uint8_t CurrentState_FogLightRear = 0;
uint8_t CurrentState_TurnSignalFront = 0;
uint8_t CurrentState_TurnSignalRear = 0;
uint8_t CurrentState_PositionLightRear = 0;
uint8_t CurrentState_BrakeLight = 0;
uint8_t CurrentState_ReverseLight = 0;
uint8_t BTLowBeam = 0;
uint8_t BTHighBeam = 0;
uint8_t BTFogLightFront = 0;
uint8_t BTFogLightRear = 0;
uint8_t BTPositionLightRear = 0;
uint8_t BTBrakeLight = 0;
uint8_t BTReverseLight = 0;
uint8_t BTTurnSignalRight = 0;
uint8_t BTTurnSignalLeft = 0;

void ExtLights_MainFunction()
{

}

uint8_t ExtLights_Init()
{
	CurrentState_LowBeam = STD_LOW;
	CurrentState_HighBeam = STD_LOW;
	CurrentState_FogLightFront = STD_LOW;
	CurrentState_FogLightRear = STD_LOW;
	CurrentState_TurnSignalFront = STD_LOW;
	CurrentState_TurnSignalRear = STD_LOW;
	CurrentState_PositionLightRear = STD_LOW;
	CurrentState_BrakeLight = STD_LOW;
	CurrentState_ReverseLight = STD_LOW;
	BTLowBeam = STD_LOW;
	BTHighBeam = STD_LOW;
	BTFogLightFront = STD_LOW;
	BTFogLightRear = STD_LOW;
	BTPositionLightRear = STD_LOW;
	BTBrakeLight = STD_LOW;
	BTReverseLight = STD_LOW;
	BTTurnSignalRight = STD_LOW;
	BTTurnSignalLeft = STD_LOW;

	return E_OK;
}


void ExtLights_LowBeam(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, PinState);
}

void ExtLights_HighBeam(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, PinState);
}

void ExtLights_FogLightFront(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, PinState);

}

void ExtLights_FogLightRear(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, PinState);
}


void ExtLights_TurnSignalLeft(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, PinState);
}

void ExtLights_TurnSignalRight(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, PinState);
}

void ExtLights_PositionLightRear(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, PinState);
}

void ExtLights_BrakeLight(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, PinState);
}

void ExtLights_ReverseLight(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, PinState);
}
