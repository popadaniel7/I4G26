#include "Std_Types.h"

#define SECALM_BUZZER_PORT 		GPIOB
#define SECALM_BUZZER_PIN 		GPIO_PIN_8
#define SECALM_LED_PORT 		GPIOA
#define SECALM_LED_PIN 			GPIO_PIN_7
#define SECALM_VIBSEN_PORT		GPIOB // random value
#define SECALM_VIBSEN_PIN		GPIO_PIN_9 // random value

EXTERN uint8 SecAlm_Trigger;
EXTERN uint8 SecAlm_Counter;
EXTERN uint8 SecAlm_PreviousState;
EXTERN uint8 SecAlm_VibSenStatusFlag;
EXTERN uint8 SecAlm_VibSenStateSetToOff;
EXTERN uint8 SecAlm_PinStateChange;

EXTERN StdReturnType SecAlmVibSenStatus();
EXTERN StdReturnType SecAlmVibeSenReadPin();
EXTERN StdReturnType SecAlmInit();
EXTERN void SecAlmMainFunction();
EXTERN void SecAlmToggleAlarmBuzzer(uint8 PinState);
EXTERN void SecAlmToggleAlarmLed(uint8 PinState);
EXTERN void SecAlmState();
EXTERN void SecAlmLightsBuzzerControl();
EXTERN void SecAlmTurnOnExtLights();
