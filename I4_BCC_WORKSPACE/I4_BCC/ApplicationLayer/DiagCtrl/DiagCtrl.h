/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Diagnostic Control	         *
******************************************/
#ifndef DiagCtrl_H
#define DiagCtrl_H
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
/* Application request define. */
#define DIAGCTRL_LIGHT_SENSOR_MALFUNCTION 					0x03
/* Application request define. */
#define DIAGCTRL_VIBRATION_SENSOR_MALFUNCTION 				0x13
/* Application state define. */
#define DIAGCTRL_REAR_PARKING_DISTANCE_SENSOR_MALFUNCTION 	0x02
/* Application state define. */
#define DIAGCTRL_FRONT_PARKING_DISTANCE_SENSOR_MALFUNCTION 	0x12
/* Application state define. */
#define DIAGCTRL_BLUETOOTH_MODULE_MALFUNCTION 				0x22
/* Application state define. */
#define DIAGCTRL_LCD_MODULE_MALFUNCTION 					0x62
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Request value processing variable. */
EXTERN uint8 DiagCtrl_RequestValue;
/* Fault value variable. */
EXTERN uint8 DiagCtrl_FaultValue;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Main function declaration. */
EXTERN VOID DiagCtrl_MainFunction();
/* Process requested data function declaration. */
EXTERN VOID DiagCtrl_ProcessRequestedData();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* DiagCtrl_H */
