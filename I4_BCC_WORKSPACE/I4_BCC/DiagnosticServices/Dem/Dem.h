/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Diagnostic Event Manager	     *
******************************************/
#ifndef Dem_H
#define Dem_H
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
/* DTC code */
#define DTC_LIGHT_SENSOR_MALFUNCTION 							0x03
/* DTC code */
#define DTC_VIBRATION_SENSOR_MALFUNCTION 						0x13
/* DTC code */
#define DTC_REAR_PARKING_DISTANCE_SENSOR_MALFUNCTION 			0x02
/* DTC code */
#define DTC_FRONT_PARKING_DISTANCE_SENSOR_MALFUNCTION 			0x12
/* DTC code */
#define DTC_BLUETOOTH_MODULE_MALFUNCTION 						0x22
/* DTC code */
#define DTC_SOFTWARE_RESET 										0x35
/* DTC code */
#define DTC_HARDWARE_RESET 										0x56
/* DTC code */
#define DTC_PERIPHERAL_ERROR 									0x99
/* DTC code */
#define POSITION_DTC_LIGHT_SENSOR_MALFUNCTION 					0
/* DTC code */
#define POSITION_DTC_VIBRATION_SENSOR_MALFUNCTION 				1
/* DTC code */
#define POSITION_DTC_REAR_PARKING_DISTANCE_SENSOR_MALFUNCTION 	2
/* DTC code */
#define POSITION_DTC_FRONT_PARKING_DISTANCE_SENSOR_MALFUNCTION 	3
/* DTC code */
#define POSITION_DTC_BLUETOOTH_MODULE_MALFUNCTION 				4
/* DTC code */
#define POSITION_DTC_SOFTWARE_RESET 							5
/* DTC code */
#define POSITION_DTC_HARDWARE_RESET 							6
/* DTC code */
#define POSITION_DTC_PERIPHERAL_ERROR 							7
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* DTC array. */
EXTERN uint8 Dem_DtcArray[8];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Module main function. */
EXTERN VOID Dem_MainFunction();
/* Receive fault from application. */
EXTERN VOID Dem_ReceiveFault(uint8 faultValue);
/* Process fault from application. */
EXTERN VOID Dem_ProcessFault();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* Dem_H */
