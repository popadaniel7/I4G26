#include "CenLoc.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "gpio.h"
#include "tim.h"

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
uint8_t flag_;

void ExtLights_MainFunction()
{
	if(BTLowBeam == STD_HIGH)
	{
		CurrentState_LowBeam = STD_HIGH;
		ExtLights_LowBeam(CurrentState_LowBeam);
	}
	else if(BTLowBeam == STD_LOW)
	{
		CurrentState_LowBeam = STD_LOW;
		ExtLights_LowBeam(CurrentState_LowBeam);
	}
	else
	{
		/* do nothing */
	}

	if(BTHighBeam == STD_HIGH)
	{
		CurrentState_HighBeam = STD_HIGH;
		ExtLights_HighBeam(CurrentState_HighBeam);
	}
	else if(BTHighBeam == STD_LOW)
	{
		CurrentState_HighBeam = STD_LOW;
		ExtLights_HighBeam(CurrentState_HighBeam);
	}
	else
	{
		/* do nothing */
	}

	if(BTFogLightFront == STD_HIGH)
	{
		CurrentState_FogLightFront = STD_HIGH;
		ExtLights_FogLightFront(CurrentState_FogLightFront);
	}
	else if(BTFogLightFront == STD_LOW)
	{
		CurrentState_FogLightFront = STD_LOW;
		ExtLights_FogLightFront(CurrentState_FogLightFront);
	}
	else
	{
		/* do nothing */
	}

	if(BTFogLightRear == STD_HIGH)
	{
		CurrentState_FogLightRear = STD_HIGH;
		ExtLights_FogLightRear(CurrentState_FogLightRear);
	}
	else if(BTFogLightRear == STD_LOW)
	{
		CurrentState_FogLightRear = STD_LOW;
		ExtLights_FogLightRear(CurrentState_FogLightRear);
	}
	else
	{
		/* do nothing */
	}



	if(BTBrakeLight == STD_HIGH)
	{
		CurrentState_BrakeLight = STD_HIGH;
		ExtLights_BrakeLight(CurrentState_BrakeLight);
	}
	else if(BTBrakeLight == STD_LOW)
	{
		CurrentState_BrakeLight = STD_LOW;
		ExtLights_BrakeLight(CurrentState_BrakeLight);
	}
	else
	{
		/* do nothing */
	}

	if(BTPositionLightRear == STD_HIGH)
	{
		CurrentState_PositionLightRear = STD_HIGH;
		ExtLights_PositionLightRear(CurrentState_PositionLightRear);
	}
	else if(BTPositionLightRear == STD_LOW)
	{
		CurrentState_PositionLightRear = STD_LOW;
		ExtLights_PositionLightRear(CurrentState_PositionLightRear);
	}
	else
	{
		/* do nothing */
	}

	if(BTReverseLight == STD_HIGH)
	{
		CurrentState_ReverseLight = STD_HIGH;
		ExtLights_ReverseLight(CurrentState_ReverseLight);
	}
	else if(BTReverseLight == STD_LOW)
	{
		CurrentState_ReverseLight = STD_LOW;
		ExtLights_ReverseLight(CurrentState_ReverseLight);
	}
	else
	{
		/* do nothing */
	}

	if(BTTurnSignalLeft == STD_HIGH)
	{
		CurrentState_TurnSignalLeft = STD_HIGH;
		HAL_TIM_Base_Start_IT(&htim10);

		if(__HAL_TIM_GET_COUNTER(&htim10) < 5000)
		{
			ExtLights_TurnSignalLeft(STD_HIGH);
		}
		else if(__HAL_TIM_GET_COUNTER(&htim10) > 5000)
		{
			ExtLights_TurnSignalLeft(STD_LOW);
		}
	}


//	if(BTTurnSignalLeft == STD_HIGH)
//	{
//		CurrentState_TurnSignalLeft = STD_HIGH;
//
//		HAL_TIM_Base_Start_IT(&htim10);
//
//		if(BTExtLight_IrqFlag == STD_HIGH)
//		{
//			ExtLights_TurnSignalLeft(BTExtLight_IrqFlag);
//		}
//		else if(BTExtLight_IrqFlag == STD_LOW)
//		{
//			ExtLights_TurnSignalLeft(BTExtLight_IrqFlag);
//		}
//		else
//		{
//			/* do nothing */
//		}
//	}
//	else if(BTTurnSignalLeft == STD_LOW)
//	{
//		HAL_TIM_Base_Stop_IT(&htim2);
//		CurrentState_TurnSignalLeft = STD_LOW;
//		ExtLights_TurnSignalLeft(CurrentState_TurnSignalLeft);
//	}
//	else
//	{
//		/* do nothing */
//	}
//
//	if(BTTurnSignalRight == STD_HIGH)
//	{
//		CurrentState_TurnSignalRight = STD_HIGH;
//
//		HAL_TIM_Base_Start_IT(&htim10);
//
//		if(BTExtLight_IrqFlag == STD_HIGH)
//		{
//			ExtLights_TurnSignalRight(BTExtLight_IrqFlag);
//		}
//		else if(BTExtLight_IrqFlag == STD_LOW)
//		{
//			ExtLights_TurnSignalRight(BTExtLight_IrqFlag);
//		}
//		else
//		{
//			/* do nothing */
//		}
//	}
//	else if(BTTurnSignalRight == STD_LOW)
//	{
//		HAL_TIM_Base_Stop_IT(&htim2);
//		CurrentState_TurnSignalRight = STD_LOW;
//		ExtLights_TurnSignalLeft(CurrentState_TurnSignalRight);
//	}
//	else
//	{
//		/* do nothing */
//	}
//
//	if(BTHazardLight == STD_HIGH)
//	{
//		CurrentState_HazardLight = STD_HIGH;
//
//		HAL_TIM_Base_Start_IT(&htim10);
//
//		if(BTExtLight_IrqFlag == STD_HIGH)
//		{
//			ExtLights_TurnSignalRight(BTExtLight_IrqFlag);
//			ExtLights_TurnSignalLeft(BTExtLight_IrqFlag);
//		}
//		else if(BTExtLight_IrqFlag == STD_LOW)
//		{
//			ExtLights_TurnSignalRight(BTExtLight_IrqFlag);
//			ExtLights_TurnSignalLeft(BTExtLight_IrqFlag);
//		}
//		else
//		{
//			/* do nothing */
//		}
//	}
//	else if(BTHazardLight == STD_LOW)
//	{
//		HAL_TIM_Base_Stop_IT(&htim2);
//		CurrentState_HazardLight = STD_LOW;
//		ExtLights_TurnSignalLeft(CurrentState_HazardLight);
//		ExtLights_TurnSignalRight(CurrentState_HazardLight);
//	}
//	else
//	{
//		/* do nothing */
//	}

	if(BTCenLoc == STD_HIGH)
	{
		HAL_TIM_Base_Start_IT(&htim11);

		if(__HAL_TIM_GET_COUNTER(&htim11) < 2000000 && BTExtLight_IrqFlag == STD_HIGH && flag_ == STD_LOW)
		{
			ExtLights_LowBeam(CurrentState_CenLoc);
			ExtLights_HighBeam(CurrentState_CenLoc);
			ExtLights_FogLightFront(CurrentState_CenLoc);
			ExtLights_FogLightRear(CurrentState_CenLoc);
			ExtLights_PositionLightRear(CurrentState_CenLoc);
			ExtLights_BrakeLight(CurrentState_CenLoc);
			ExtLights_ReverseLight(CurrentState_CenLoc);
			flag_ = STD_HIGH;
		}
		else if(BTExtLight_IrqFlag == STD_HIGH && flag_ == STD_HIGH)
		{
			ExtLights_LowBeam(!CurrentState_CenLoc);
			ExtLights_HighBeam(!CurrentState_CenLoc);
			ExtLights_FogLightFront(!CurrentState_CenLoc);
			ExtLights_FogLightRear(!CurrentState_CenLoc);
			ExtLights_PositionLightRear(!CurrentState_CenLoc);
			ExtLights_BrakeLight(!CurrentState_CenLoc);
			ExtLights_ReverseLight(!CurrentState_CenLoc);
			HAL_TIM_Base_Stop_IT(&htim11);
		}
		else
		{
			/* do nothing */
		}
	}
	else if(BTCenLoc == STD_LOW)
	{
		HAL_TIM_Base_Start_IT(&htim11);
		if(__HAL_TIM_GET_COUNTER(&htim11) < 2000000 && BTExtLight_IrqFlag == STD_LOW )
		{
			ExtLights_LowBeam(CurrentState_CenLoc);
			ExtLights_HighBeam(CurrentState_CenLoc);
			ExtLights_FogLightFront(CurrentState_CenLoc);
			ExtLights_FogLightRear(CurrentState_CenLoc);
			ExtLights_PositionLightRear(CurrentState_CenLoc);
			ExtLights_BrakeLight(CurrentState_CenLoc);
			ExtLights_ReverseLight(CurrentState_CenLoc);

			//flag_ = 1;
		}
		else if(BTExtLight_IrqFlag == STD_HIGH)
		{
			ExtLights_LowBeam(!CurrentState_CenLoc);
			ExtLights_HighBeam(!CurrentState_CenLoc);
			ExtLights_FogLightFront(!CurrentState_CenLoc);
			ExtLights_FogLightRear(!CurrentState_CenLoc);
			ExtLights_PositionLightRear(!CurrentState_CenLoc);
			ExtLights_BrakeLight(!CurrentState_CenLoc);
			ExtLights_ReverseLight(!CurrentState_CenLoc);
			HAL_TIM_Base_Stop_IT(&htim11);
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		/*  do nothing */
	}

}

uint8_t ExtLights_Init()
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
	flag_ = STD_LOW;

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
