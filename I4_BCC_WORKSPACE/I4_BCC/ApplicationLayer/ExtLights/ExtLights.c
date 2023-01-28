#include "tim.h"
#include "CenLoc.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "gpio.h"
#include "Project_Definitions.h"

uint8 ExtLights_ReverseLight_CurrentState;
uint8 ExtLights_BrakeLight_CurrentState;
uint8 ExtLights_FlashHighBeam_CurrentState;
uint8 ExtLights_LightsSwitch_CurrentState;
uint8 ExtLights_HighBeam_CurrentState;
uint8 ExtLights_FrontFogLight_CurrentState;
uint8 ExtLights_TurnSignalLeft_CurrentState;
uint8 ExtLights_TurnSignalRight_CurrentState;
uint8 ExtLights_HazardLight_CurrentState;
uint8 ExtLights_RearFogLight_CurrentState;
uint8 Btc_LightSwitch;
uint8 Btc_HighBeam;
uint8 Btc_FlashHighBeam;
uint8 Btc_FrontFogLight;
uint8 Btc_TurnSignalLeft;
uint8 Btc_TurnSignalRight;
uint8 Btc_HazardLight;
uint8 Btc_BrakeLight;
uint8 Btc_RearFogLight;
uint8 Btc_ReverseLight;
uint8 ExtLights_RTSFlag;
uint8 ExtLights_LTSFlag;
uint8 ExtLights_HLFlag;

static uint8 lightSensorState;

void ExtLightsMainFunction();
void ExtLightsLowBeam(uint8 PinState);
void ExtLightsHighBeam(uint8 PinState);
void ExtLightsDayTimeRunningLight(uint8 PinState);
void ExtLightsTurnSignalLeft(uint8 PinState);
void ExtLightsTurnSignalRight(uint8 PinState);
void ExtLightsFrontFogLight(uint8 PinState);
void ExtLightsRearPositionLight(uint8 PinState);
void ExtLightsBrakeLight(uint8 PinState);
void ExtLightsLicensePlateLight(uint8 PinState);
void ExtLightsRearFogLight(uint8 PinState);
void ExtLightsReverseLight(uint8 PinState);
void ExtLightsRxBtcState();
void ExtLightsLightState();
void ExtLightsTurnSignalHazardLight();
void ExtLightsLightSwitchMode();
StdReturnType ExtLightsInit();
uint32 ExtLightsLightReadSensorValue();

void ExtLightsTurnSignalHazardLight()
{
	if(ExtLights_TurnSignalLeft_CurrentState == STD_HIGH)
	{

		HAL_TIM_Base_Start_IT(&htim2);

		if(ExtLights_LTSFlag % 2 == 1)
		{

			ExtLightsTurnSignalLeft(ExtLights_TurnSignalLeft_CurrentState);

		}
		else if(ExtLights_LTSFlag % 2 == 0)
		{

			ExtLightsTurnSignalLeft(!ExtLights_TurnSignalLeft_CurrentState);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(ExtLights_TurnSignalLeft_CurrentState == STD_LOW)
	{

		ExtLightsTurnSignalLeft(ExtLights_TurnSignalLeft_CurrentState);
		ExtLights_LTSFlag = STD_LOW;

	}
	else
	{

		/* do nothing */

	}

	if(ExtLights_TurnSignalRight_CurrentState == STD_HIGH)
	{

		HAL_TIM_Base_Start_IT(&htim2);

		if(ExtLights_RTSFlag % 2 == 1)
		{

			ExtLightsTurnSignalRight(ExtLights_TurnSignalRight_CurrentState);

		}
		else if(ExtLights_RTSFlag % 2 == 0)
		{

			ExtLightsTurnSignalRight(!ExtLights_TurnSignalRight_CurrentState);

		}
		else
		{

			/* do nothing */

		}

	}
	else if(ExtLights_TurnSignalRight_CurrentState == STD_LOW)
	{

		ExtLights_RTSFlag = STD_LOW;
		ExtLightsTurnSignalRight(ExtLights_TurnSignalRight_CurrentState);

	}
	else
	{

		/* do nothing */

	}

	if(ExtLights_HazardLight_CurrentState == STD_HIGH)
	{

		HAL_TIM_Base_Start_IT(&htim2);

		if(ExtLights_HLFlag % 2 == 1)
		{

			ExtLightsTurnSignalRight(ExtLights_HazardLight_CurrentState);
			ExtLightsTurnSignalLeft(ExtLights_HazardLight_CurrentState);

		}
		else if(ExtLights_HLFlag % 2 == 0)
		{

			ExtLightsTurnSignalRight(!ExtLights_HazardLight_CurrentState);
			ExtLightsTurnSignalLeft(!ExtLights_HazardLight_CurrentState);

		}
		else
		{

			/* do nothing */

		}


	}
	else if(ExtLights_HazardLight_CurrentState == STD_LOW)
	{

		ExtLightsTurnSignalRight(ExtLights_HazardLight_CurrentState);
		ExtLightsTurnSignalLeft(ExtLights_HazardLight_CurrentState);
		ExtLights_HLFlag = 0;

	}
	else
	{

		/* do nothing */

	}
}

void ExtLightsMainFunction()
{

	ExtLightsRxBtcState();
	ExtLightsLightState();

}

StdReturnType ExtLightsInit()
{

	ExtLights_ReverseLight_CurrentState 		= STD_LOW;
	ExtLights_BrakeLight_CurrentState 			= STD_LOW;
	ExtLights_FlashHighBeam_CurrentState 		= STD_LOW;
	ExtLights_LightsSwitch_CurrentState 		= STD_LOW;
	ExtLights_HighBeam_CurrentState 			= STD_LOW;
	ExtLights_FrontFogLight_CurrentState 		= STD_LOW;
	ExtLights_TurnSignalLeft_CurrentState 		= STD_LOW;
	ExtLights_TurnSignalRight_CurrentState 		= STD_LOW;
	ExtLights_HazardLight_CurrentState 			= STD_LOW;
	ExtLights_RearFogLight_CurrentState 		= STD_LOW;
	Btc_LightSwitch 							= STD_LOW;
	Btc_HighBeam 								= STD_LOW;
	Btc_FlashHighBeam 							= STD_LOW;
	Btc_FrontFogLight 							= STD_LOW;
	Btc_TurnSignalLeft 							= STD_LOW;
	Btc_TurnSignalRight 						= STD_LOW;
	Btc_HazardLight 							= STD_LOW;
	Btc_BrakeLight								= STD_LOW;
	Btc_RearFogLight 							= STD_LOW;
	Btc_ReverseLight							= STD_LOW;
	ExtLights_RTSFlag 							= STD_LOW;
	ExtLights_LTSFlag 							= STD_LOW;
	ExtLights_HLFlag 							= STD_LOW;

	return E_OK;

}

void ExtLightsLightSwitchMode()
{

	switch(ExtLights_LightsSwitch_CurrentState)
	{
		case EXTLIGHTS_LIGHTSWITCH_STATEZERO:

			ExtLightsLowBeam(STD_LOW);
			ExtLightsDayTimeRunningLight(STD_LOW);
			ExtLightsRearPositionLight(STD_LOW);
			ExtLightsLicensePlateLight(STD_LOW);

			break;

		case EXTLIGHTS_LIGHTSWITCH_STATEONE:

			lightSensorState = ExtLightsLightReadSensorValue();

			if(lightSensorState < EXTLIGHTS_LIGHTSENSOR_DAYNIGHTVALUE)
			{

				ExtLightsLowBeam(STD_HIGH);
				ExtLightsDayTimeRunningLight(STD_HIGH);
				ExtLightsRearPositionLight(STD_HIGH);
				ExtLightsLicensePlateLight(STD_HIGH);

			}
			else if(lightSensorState > EXTLIGHTS_LIGHTSENSOR_DAYNIGHTVALUE)
			{

				ExtLightsLowBeam(STD_LOW);
				ExtLightsDayTimeRunningLight(STD_HIGH);
				ExtLightsRearPositionLight(STD_LOW);
				ExtLightsLicensePlateLight(STD_LOW);

			}

			break;

		case EXTLIGHTS_LIGHTSWITCH_STATETWO:

			ExtLightsLowBeam(STD_LOW);
			ExtLightsDayTimeRunningLight(STD_HIGH);
			ExtLightsRearPositionLight(STD_HIGH);
			ExtLightsLicensePlateLight(STD_HIGH);

			break;

		case EXTLIGHTS_LIGHTSWITCH_STATETHREE:

			ExtLightsLowBeam(STD_HIGH);
			ExtLightsDayTimeRunningLight(STD_HIGH);
			ExtLightsRearPositionLight(STD_HIGH);
			ExtLightsLicensePlateLight(STD_HIGH);

			break;

		default:

			break;

	}

}

void ExtLightsLightState()
{

	if(SecAlm_Trigger == STD_HIGH)
	{

		ExtLightsReverseLight(STD_LOW);
		ExtLightsDayTimeRunningLight(STD_LOW);

	}
	else
	{

		/* do nothing */

	}

	ExtLightsTurnSignalHazardLight();
	ExtLightsLightSwitchMode();
	ExtLightsHighBeam(ExtLights_HighBeam_CurrentState);
	ExtLightsFrontFogLight(ExtLights_FrontFogLight_CurrentState);
	ExtLightsRearFogLight(ExtLights_RearFogLight_CurrentState);


	if(Btc_ReverseLight == STD_HIGH)
	{

		ExtLights_ReverseLight_CurrentState = Btc_ReverseLight;

	}
	else if(Btc_ReverseLight == STD_HIGH)
	{

		ExtLights_ReverseLight_CurrentState = Btc_ReverseLight;

	}
	else
	{

		/* do nothing */

	}

}

void ExtLightsRxBtcState()
{
	switch(Btc_LightSwitch)
	{

		case EXTLIGHTS_LIGHTSWITCH_STATEZERO:

			ExtLights_LightsSwitch_CurrentState = EXTLIGHTS_LIGHTSWITCH_STATEZERO;

			break;

		case EXTLIGHTS_LIGHTSWITCH_STATEONE:

			ExtLights_LightsSwitch_CurrentState = EXTLIGHTS_LIGHTSWITCH_STATEONE;

			break;

		case EXTLIGHTS_LIGHTSWITCH_STATETWO:

			ExtLights_LightsSwitch_CurrentState = EXTLIGHTS_LIGHTSWITCH_STATETWO;


			break;

		case EXTLIGHTS_LIGHTSWITCH_STATETHREE:

			ExtLights_LightsSwitch_CurrentState = EXTLIGHTS_LIGHTSWITCH_STATETHREE;

			break;

		default:

			break;

	}

	if(Btc_HighBeam == STD_HIGH)
	{

		ExtLights_HighBeam_CurrentState = Btc_HighBeam;

	}
	else if(Btc_HighBeam == STD_LOW)
	{

		ExtLights_HighBeam_CurrentState = Btc_HighBeam;

	}
	else
	{

		/* do nothing */

	}

	if(Btc_FrontFogLight == STD_HIGH)
	{

		ExtLights_FrontFogLight_CurrentState = Btc_FrontFogLight;

	}
	else if(Btc_FrontFogLight == STD_LOW)
	{

		ExtLights_FrontFogLight_CurrentState = Btc_FrontFogLight;

	}
	else
	{

		/* do nothing */

	}

	if(Btc_RearFogLight == STD_HIGH)
	{

		ExtLights_RearFogLight_CurrentState = Btc_RearFogLight;

	}
	else if(Btc_RearFogLight == STD_LOW)
	{

		ExtLights_RearFogLight_CurrentState = Btc_RearFogLight;

	}
	else
	{

		/* do nothing */

	}

	if(Btc_BrakeLight == STD_HIGH)
	{

		ExtLights_BrakeLight_CurrentState = Btc_BrakeLight;

	}
	else if(Btc_BrakeLight == STD_LOW)
	{

		ExtLights_BrakeLight_CurrentState = Btc_BrakeLight;

	}
	else
	{

		/* do nothing */

	}

	if(Btc_TurnSignalLeft == STD_HIGH)
	{

		ExtLights_TurnSignalLeft_CurrentState = Btc_TurnSignalLeft;

	}
	else if(Btc_TurnSignalLeft == STD_LOW)
	{

		ExtLights_TurnSignalLeft_CurrentState = Btc_TurnSignalLeft;

	}
	else
	{

		/* do nothing */

	}

	if(Btc_TurnSignalRight == STD_HIGH)
	{

		ExtLights_TurnSignalRight_CurrentState = Btc_TurnSignalRight;

	}
	else if(Btc_TurnSignalRight == STD_LOW)
	{

		ExtLights_TurnSignalRight_CurrentState = Btc_TurnSignalRight;

	}
	else
	{

		/* do nothing */

	}

	if(Btc_HazardLight == STD_HIGH)
	{

		ExtLights_HazardLight_CurrentState = Btc_HazardLight;

	}
	else if(Btc_HazardLight == STD_LOW)
	{

		ExtLights_HazardLight_CurrentState = Btc_HazardLight;

	}
	else
	{

		/* do nothing */

	}

}

uint32 ExtLightsLightReadSensorValue()
{

	uint8 sensorValue = 0;

	sensorValue = ADC_BUFFER[2];

	return sensorValue;

}

void ExtLightsLowBeam(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_LOWBEAM_PORT, EXTLIGHTS_LOWBEAM_PIN, PinState);

}

void ExtLightsHighBeam(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_HIGHBEAM_PORT, EXTLIGHTS_HIGHBEAM_PIN, PinState);

}

void ExtLightsDayTimeRunningLight(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_DAYTIMERUNNINGLIGHT_PORT, EXTLIGHTS_DAYTIMERUNNINGLIGHT_PIN, PinState);

}

void ExtLightsFrontFogLight(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_FRONTFOGLIGHT_PORT, EXTLIGHTS_FRONTFOGLIGHT_PIN, PinState);

}

void ExtLightsTurnSignalLeft(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_TURNSIGNALLEFT_PORT, EXTLIGHTS_TURNSIGNALLEFT_PIN, PinState);

}

void ExtLightsTurnSignalRight(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_TURNSIGNALRIGHT_PORT, EXTLIGHTS_TURNSIGNALRIGHT_PIN, PinState);

}

void ExtLightsRearPositionLight(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_REARPOSITIONLIGHT_PORT, EXTLIGHTS_REARPOSITIONLIGHT_PIN, PinState);

}

void ExtLightsRearFogLight(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_REARFOGLIGHT_PORT, EXTLIGHTS_REARFOGLIGHT_PIN, PinState);

}

void ExtLightsBrakeLight(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_BRAKELIGHT_PORT, EXTLIGHTS_BRAKELIGHT_PIN, PinState);

}

void ExtLightsReverseLight(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_REVERSELIGHT_PORT, EXTLIGHTS_REVERSELIGHT_PIN, PinState);

}

void ExtLightsLicensePlateLight(uint8 PinState)
{

	HAL_GPIO_WritePin(EXTLIGHTS_LICENSEPLATELIGHT_PORT, EXTLIGHTS_LICENSEPLATELIGHT_PIN, PinState);

}
