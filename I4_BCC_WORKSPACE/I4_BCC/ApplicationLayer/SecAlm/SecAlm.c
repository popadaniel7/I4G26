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

uint8_t PrevState_UserButton = 0;
uint8_t NextState_UserButton = 0;
uint8_t CurrentState_UserButton = 0;
uint8_t CurrentState_Alarm_Buzzer = 0;
uint8_t CurrentState_Alarm_LED = 0;
uint16_t Event_First_TimeStamp_Alarm = 0;
uint16_t Event_Last_TimeStamp_Alarm = 0;

void SecAlm_MainFunction()
{
	/* TODO: Implement vibration sensor in order
		 * 		 to trigger the ALARM_BUZZER and
		 * 		 ALARM_LED in case of theft.
		 */
}

uint8_t SecAlm_Init()
{
	PrevState_UserButton = STD_LOW;
	NextState_UserButton = STD_LOW;
	CurrentState_UserButton = STD_LOW;
	CurrentState_Alarm_Buzzer = STD_LOW;
	CurrentState_Alarm_LED = STD_LOW;
	Event_First_TimeStamp_Alarm = STD_LOW;
	Event_Last_TimeStamp_Alarm = STD_LOW;

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
