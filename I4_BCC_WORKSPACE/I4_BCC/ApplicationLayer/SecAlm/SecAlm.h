#include "Std_Types.h"

#define SECALM_BUZZER_PORT 		GPIOB
#define SECALM_BUZZER_PIN 		GPIO_PIN_13
#define SECALM_LED_PORT 		GPIOA
#define SECALM_LED_PIN 			GPIO_PIN_15
#define SECALM_VIBSEN_PORT		GPIOA
#define SECALM_VIBSEN_PIN		GPIO_PIN_12

EXTERN uint8 SecAlm_Trigger;
EXTERN uint32 SecAlm_VibSenStatusFlag;
EXTERN uint8 SecAlm_PinStateChange;
EXTERN uint8 SecAlm_TriggerIRQCounterForTimer4;
EXTERN uint8 SecAlm_IsAlmOnFlag;

EXTERN StdReturnType SecAlmVibSenStatus();
EXTERN StdReturnType SecAlmVibeSenReadPin();
EXTERN StdReturnType SecAlmInit();
EXTERN void SecAlmMainFunction();
EXTERN void SecAlmToggleAlarmBuzzer(uint8 PinState);
EXTERN void SecAlmToggleAlarmLed(uint8 PinState);
EXTERN void SecAlmState();
EXTERN void SecAlmLightsBuzzerControl();
EXTERN void SecAlmTurnOnExtLights();
