#include "Std_Types.h"

#define ALARM_BUZZER 6 // PA 6
#define ALARM_LED 4 // PA 4


extern uint8_t PrevState_UserButton;
extern uint8_t NextState_UserButton;
extern uint8_t CurrentState_UserButton;
extern uint8_t CurrentState_Alarm_Buzzer;
extern uint8_t CurrentState_Alarm_LED;
extern uint16_t Event_First_TimeStamp_Alarm;
extern uint16_t Event_Last_TimeStamp_Alarm;

void SecAlm_MainFunction();
uint8_t SecAlm_Init();
uint8_t SecAlm_GetErrorStatus(uint8_t ApplState);

void SecAlm_ToggleAlarmBuzzer(uint8_t PinState);
void SecAlm_ToggleAlarmLed(uint8_t PinState);
