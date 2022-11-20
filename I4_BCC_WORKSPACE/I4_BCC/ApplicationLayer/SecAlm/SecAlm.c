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

uint8_t PrevState_UserButton;
uint8_t NextState_UserButton;
uint8_t CurrentState_UserButton;
uint8_t CurrentState_Alarm_Buzzer;
uint8_t CurrentState_Alarm_LED;
uint8_t AlarmCount1;
uint8_t AlarmCount2;
uint8_t PrevStateBTCenLoc;
uint8_t NextStateBTCenLoc;


void SecAlm_MainFunction()
{
	/* TODO: Implement vibration sensor in order
		 * 		 to trigger the ALARM_BUZZER and
		 * 		 ALARM_LED in case of theft.
		 */

    NextStateBTCenLoc = BTCenLoc;

    if(NextStateBTCenLoc != PrevStateBTCenLoc)
    {
    	PrevStateBTCenLoc = NextStateBTCenLoc;
    	flag_ = STD_LOW;
    	AlarmCount1 = STD_LOW;
    	AlarmCount2 = STD_LOW;
    }

	if(BTCenLoc == STD_HIGH && AlarmCount1 < 2)
	{
		HAL_TIM_Base_Start_IT(&htim2);

		if(BTCenLoc_IrqFlag == STD_LOW)
		{
			CurrentState_Alarm_Buzzer = STD_HIGH;
			SecAlm_ToggleAlarmLed(CurrentState_Alarm_Buzzer);
			AlarmCount1++;
		}
		else if(BTCenLoc_IrqFlag == STD_HIGH)
		{
			CurrentState_Alarm_Buzzer = STD_LOW;
			SecAlm_ToggleAlarmLed(CurrentState_Alarm_Buzzer);
		}
		else
		{
			/* do nothing */
		}

		if(AlarmCount1 == 2)
		{
			HAL_TIM_Base_Stop_IT(&htim2);
		}
		else
		{
			/* do nothing */
		}
	}
	else if(BTCenLoc == STD_LOW && AlarmCount2 < 1)
	{
		HAL_TIM_Base_Start_IT(&htim2);
//		CurrentState_Alarm_LED = STD_LOW;
//		SecAlm_ToggleAlarmLed(CurrentState_Alarm_LED);
		//test with alarm led

		if(BTCenLoc_IrqFlag == STD_LOW)
		{
			CurrentState_Alarm_Buzzer = STD_HIGH;
			SecAlm_ToggleAlarmLed(CurrentState_Alarm_Buzzer);
			AlarmCount2++;
		}
		else if(BTCenLoc_IrqFlag == STD_HIGH)
		{
			CurrentState_Alarm_Buzzer = STD_LOW;
			SecAlm_ToggleAlarmLed(CurrentState_Alarm_Buzzer);
		}
		else
		{
			/* do nothing */
		}

		if(AlarmCount2 == 1)
		{
			HAL_TIM_Base_Stop_IT(&htim2);
		}
		else
		{
			/* do nothing */
		}
	}
}

uint8_t SecAlm_Init()
{
	PrevState_UserButton = STD_LOW;
	NextState_UserButton = STD_LOW;
	CurrentState_UserButton = STD_LOW;
	CurrentState_Alarm_Buzzer = STD_LOW;
	CurrentState_Alarm_LED = STD_LOW;
	AlarmCount1 = STD_LOW;
	AlarmCount2 = STD_LOW;
	PrevStateBTCenLoc = STD_LOW;
	NextStateBTCenLoc = STD_LOW;

	return E_OK;
}

void SecAlm_ToggleAlarmBuzzer(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, PinState);
}

void SecAlm_ToggleAlarmLed(uint8_t PinState)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, PinState);
}
