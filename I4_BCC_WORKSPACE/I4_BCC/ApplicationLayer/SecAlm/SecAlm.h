/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Security Alarm	     		 *
******************************************/
#ifndef SecAlm_H
#define SecAlm_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
/*****************************************
		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable for security alarm trigger. */
EXTERN uint8 SecAlm_Trigger;
/* Variable for pin state of buzzer and light control. */
EXTERN uint8 SecAlm_PinStateChange;
/* Variable for timer counter of alarm sequence. */
EXTERN uint8 SecAlm_TriggerIRQCounterForTimer4;
/* Variable for vibration sensor activation counter. */
EXTERN uint16 SecAlm_SensorStatusCounter;
/* Variable for vibration sensor status. */
EXTERN uint16 SecAlm_SensorStatus;
/* Variable to get the sensor state. */
EXTERN uint8 SecAlm_SensorState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Vibration sensor status processing function declaration.*/
EXTERN uint32 SecAlm_VibSenReadSensorValue();
/* Vibration sensor status processing function declaration.*/
EXTERN StdReturnType SecAlm_VibSenStatus();
/* Security alarm application initialization function declaration. */
EXTERN StdReturnType SecAlm_Init();
/* Security alarm application de-initialization function declaration. */
EXTERN StdReturnType SecAlm_DeInit();
/* Security alarm application main function declaration. */
EXTERN VOID SecAlm_MainFunction();
/* Alarm buzzer trigger function declaration. */
EXTERN VOID SecAlm_ToggleAlarmBuzzer(uint8 PinState);
/* Alarm LED trigger function declaration. */
EXTERN VOID SecAlm_ToggleAlarmLed(uint8 PinState);
/* Alarm buzzer and light control function declaration. */
EXTERN VOID SecAlm_LightsBuzzerControl();
/* Light control function declaration. */
EXTERN VOID SecAlm_TurnOnExtLights();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* SecAlm_H */
