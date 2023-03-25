#include "Std_Types.h"

#define SECALM_BUZZER_PORT 		GPIOB
#define SECALM_BUZZER_PIN 		GPIO_PIN_13
#define SECALM_LED_PORT 		GPIOA
#define SECALM_LED_PIN 			GPIO_PIN_15

EXTERN uint8 SecAlm_Trigger;
EXTERN uint8 SecAlm_PinStateChange;
EXTERN uint8 SecAlm_TriggerIRQCounterForTimer4;
EXTERN uint16 SecAlm_SensorStatusCounter;
EXTERN uint16 SecAlm_SensorStatus;

EXTERN uint32 SecAlm_VibSenReadSensorValue();
EXTERN StdReturnType SecAlm_VibSenStatus();
EXTERN StdReturnType SecAlm_Init();
EXTERN void SecAlm_MainFunction();
EXTERN void SecAlm_ToggleAlarmBuzzer(uint8 PinState);
EXTERN void SecAlm_ToggleAlarmLed(uint8 PinState);
EXTERN void SecAlm_LightsBuzzerControl();
EXTERN void SecAlm_LightsBuzzerControl();
