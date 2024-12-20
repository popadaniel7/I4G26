/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Exterior Lights	     		 *
******************************************/
#ifndef ExtLights_H
#define ExtLights_H
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
/* Value for the light switch position zero. */
#define EXTLIGHTS_LIGHTSWITCH_STATEZERO		23
/* Value for the light switch position one. */
#define EXTLIGHTS_LIGHTSWITCH_STATEONE		24
/* Value for the light switch position two. */
#define EXTLIGHTS_LIGHTSWITCH_STATETWO		25
/* Value for the light switch position three. */
#define EXTLIGHTS_LIGHTSWITCH_STATETHREE	26
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable for the current state of reverse light. */
EXTERN uint8 ExtLights_ReverseLight_CurrentState;
/* Variable for the current state of brake light. */
EXTERN uint8 ExtLights_BrakeLight_CurrentState;
/* Variable for the current state of light switch. */
EXTERN uint8 ExtLights_LightsSwitch_CurrentState;
/* Variable for the current state of high beam. */
EXTERN uint8 ExtLights_HighBeam_CurrentState;
/* Variable for the current state of front fog light. */
EXTERN uint8 ExtLights_FrontFogLight_CurrentState;
/* Variable for the current state of left turn signals. */
EXTERN uint8 ExtLights_TurnSignalLeft_CurrentState;
/* Variable for the current state of right turn signals. */
EXTERN uint8 ExtLights_TurnSignalRight_CurrentState;
/* Variable for the current state of the low beam */
EXTERN uint8 ExtLights_LowBeam_CurrentState;
/* Variable for the current state of the rear position lights. */
EXTERN uint8 ExtLights_RearPositionLights_CurrentState;
/* Variable for the current state of hazard lights. */
EXTERN uint8 ExtLights_HazardLight_CurrentState;
/* Variable for the current state of rear fog lights. */
EXTERN uint8 ExtLights_RearFogLight_CurrentState;
/* Variable for the right turn signal previous state. */
EXTERN uint8 ExtLights_RTS_PrevState;
/* Variable for the left turn signal previous state. */
EXTERN uint8 ExtLights_LTS_PrevState;
/* Variable for the hazard light previous state. */
EXTERN uint8 ExtLights_HL_PrevState;
/* Variable for the right turn signal counter flag. */
EXTERN uint32 ExtLights_RTSFlag;
/* Variable for the left turn signal counter flag. */
EXTERN uint32 ExtLights_LTSFlag;
/* Variable for the hazard light counter flag. */
EXTERN uint32 ExtLights_HLFlag;
/* Variable for sensor state. */
EXTERN uint32 ExtLights_LightSensorState;
/* DTC array for lights. */
EXTERN uint8 ExtLights_DtcArray[10];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Exterior lights main function declaration. */
EXTERN VOID ExtLights_MainFunction();
/* High beam trigger function declaration. */
EXTERN VOID ExtLights_HighBeam(uint8 PinState);
/* Reverse light trigger function declaration. */
EXTERN VOID ExtLights_ReverseLight(uint8 PinState);
/* Lights states processing function declaration. */
EXTERN VOID ExtLights_LightState();
/* Turn signals and hazard lights control function declaration. */
EXTERN VOID ExtLights_TurnSignalHazardLight();
/* Light switch control function declaration. */
EXTERN VOID ExtLights_LightSwitchMode();
/* Turn signals and hazard lights current and previous state processing function declaration. */
EXTERN VOID ExtLights_PrevStateTSHL();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* ExtLights_H */
