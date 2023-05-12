/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Parking Distance Control 	     *
******************************************/
#ifndef Pdc_H
#define Pdc_H
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
/* Sensor request define */
#define PDCR_REQUEST 				0x02
/* Sensor request define */
#define PDCF_REQUEST 				0x03
/* Application state define. */
#define PDC_INIT_STATE				0x00
/* Application state define. */
#define PDC_DEINIT_STATE			0x02
/* Application state define. */
#define PDC_PROCESS_DATA			0x01
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
EXTERN uint8 Pdc_ApplState;
/* Variable to store rear distance. */
EXTERN uint8 Pdc_Rear_Distance;
/* Variable to store front distance. */
EXTERN uint8 Pdc_Front_Distance;
/* Variable to store the rear buzzer counter. */
EXTERN uint32 Pdc_Rear_BuzzerOsCounter;
/* Variable to store the front buzzer counter. */
EXTERN uint32 Pdc_Front_BuzzerOsCounter;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Initialization function declaration. */
EXTERN StdReturnType Pdc_Init();
/* De-initialization function declaration. */
EXTERN StdReturnType Pdc_DeInit();
/* Main function declaration. */
EXTERN VOID Pdc_MainFunction();
/* Distance process data function declaration. */
EXTERN VOID Pdc_Rear_ProcessData();
/* Distance process data function declaration. */
EXTERN VOID Pdc_Front_ProcessData();
/* Buzzer control function declaration. */
EXTERN VOID Pdc_Rear_TriggerBuzzer();
/* Buzzer control function declaration. */
EXTERN VOID Pdc_Front_TriggerBuzzer();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* Pdc_H */
