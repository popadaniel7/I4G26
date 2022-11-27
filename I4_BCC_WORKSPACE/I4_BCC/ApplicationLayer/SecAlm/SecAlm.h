#include "Std_Types.h"

#define ALARM_BUZZER_PORT GPIOB
#define ALARM_BUZZER_PIN GPIO_PIN_8
#define ALARM_LED_PORT GPIOA
#define ALARM_LED_PIN GPIO_PIN_7

EXTERN uint8 CurrentState_Alarm_LED;
EXTERN uint8 LockCounter;
EXTERN uint8 UnlockCounter;
EXTERN uint8 SecAlmTrigger;
EXTERN uint8 SecAlmCounter;
EXTERN uint8 PreviousState_SecAlm;

void SecAlm_MainFunction();
StdReturnType SecAlm_Init();
StdReturnType SecAlm_GetErrorStatus(uint8 ApplState);

void SecAlm_ToggleAlarmBuzzer(uint8 PinState);
void SecAlm_ToggleAlarmLed(uint8 PinState);
