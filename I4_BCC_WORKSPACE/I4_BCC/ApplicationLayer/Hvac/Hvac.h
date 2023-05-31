/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Heating Ventilation Air		 *
* 		  Conditioning	     			 *
******************************************/
#ifndef Hvac_H
#define Hvac_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Main counter variable. */
EXTERN uint32 Hvac_MainCounter;
/* Sensor state variable. */
EXTERN uint8 Hvac_TsState;
/* Sensor state variable. */
EXTERN uint8 Hvac_AqsState;
/* Current state variable. */
EXTERN uint8 Hvac_CurrentState;
/* Fan value variable. */
EXTERN uint8 Hvac_FanValue;
/* Climate control temperature value. */
EXTERN uint8 Hvac_TemperatureValue;
/* Leg vents state. */
EXTERN uint8 Hvac_LegVent;
/* Mid vents state. */
EXTERN uint8 Hvac_MidVent;
/* Windshield vents state. */
EXTERN uint8 Hvac_WindshieldVent;
/* Windshield defrost mode. */
EXTERN uint8 Hvac_WindshieldDefrost;
/* Rear windshield defrost mode. */
EXTERN uint8 Hvac_RearWindshieldDefrost;
/* AC state. */
EXTERN uint8 Hvac_Ac;
/* Manual recirculation. */
EXTERN uint8 Hvac_Recirculation;
/* No recirculation. */
EXTERN uint8 Hvac_NoRecirculation;
/* Automatic mode. */
EXTERN uint8 Hvac_AutomaticMode;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Application main function. */
EXTERN VOID Hvac_MainFunction();
/* Process the received command. */
EXTERN VOID Hvac_ProcessCommand();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* Hvac_H */
