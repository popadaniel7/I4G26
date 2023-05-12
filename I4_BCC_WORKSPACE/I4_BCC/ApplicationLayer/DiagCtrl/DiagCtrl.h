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
#define DIAGCTRL_LB_L_REQUEST								4
/* Application request define. */
#define DIAGCTRL_LB_R_REQUEST								5
/* Application request define. */
#define DIAGCTRL_RPL_L_REQUEST								6
/* Application request define. */
#define DIAGCTRL_RPL_R_REQUEST								7
/* Application request define. */
#define DIAGCTRL_BL_R_REQUEST								8
/* Application request define. */
#define DIAGCTRL_BL_L_REQUEST								9
/* Application request define. */
#define DIAGCTRL_LTS_F_REQUEST								10
/* Application request define. */
#define DIAGCTRL_LTS_R_REQUEST								11
/* Application request define. */
#define DIAGCTRL_RTS_R_REQUEST								12
/* Application request define. */
#define DIAGCTRL_RTS_F_REQUEST								13
/* Application request define. */
#define DIAGCTRL_LOW_BEAM_LEFT_MALFUNCTION 					0x04
/* Application request define. */
#define DIAGCTRL_LOW_BEAM_RIGHT_MALFUNCTION 				0x05
/* Application request define. */
#define DIAGCTRL_REAR_POSITION_LIGHT_LEFT_MALFUNCTION		0x44
/* Application request define. */
#define DIAGCTRL_REAR_POSITION_LIGHT_RIGHT_MALFUNCTION		0x45
/* Application request define. */
#define DIAGCTRL_RIGHT_TURN_SIGNAL_FRONT_MALFUNCTION 		0x54
/* Application request define. */
#define DIAGCTRL_RIGHT_TURN_SIGNAL_REAR_MALFUNCTION 		0x55
/* Application request define. */
#define DIAGCTRL_LEFT_TURN_SIGNAL_FRONT_MALFUNCTION 		0x64
/* Application request define. */
#define DIAGCTRL_LEFT_TURN_SIGNAL_REAR_MALFUNCTION 			0x65
/* Application request define. */
#define DIAGCTRL_BRAKE_LIGHT_LEFT_MALFUNCTION 				0x74
/* Application request define. */
#define DIAGCTRL_BRAKE_LIGHT_RIGHT_MALFUNCTION 				0x74
/* Application request define. */
#define DIAGCTRL_LIGHT_SENSOR_MALFUNCTION 					0x03
/* Application request define. */
#define DIAGCTRL_VIBRATION_SENSOR_MALFUNCTION 				0x13
/* Application request define. */
#define DIAGCTRL_AIR_QUALITY_SENSOR_MALFUNCTION 			0x23
/* Application request define. */
#define DIAGCTRL_TEMPERATURE_SENSOR_MALFUNCTION 			0x33
/* Application state define. */
#define DIAGCTRL_REAR_PARKING_DISTANCE_SENSOR_MALFUNCTION 	0x02
/* Application state define. */
#define DIAGCTRL_FRONT_PARKING_DISTANCE_SENSOR_MALFUNCTION 	0x12
/* Application state define. */
#define DIAGCTRL_BLUETOOTH_MODULE_MALFUNCTION 				0x22
/* Application state define. */
#define DIAGCTRL_EXTERNAL_EEPROM_MODULE_MALFUNCTION 		0x32
/* Application state define. */
#define DIAGCTRL_CAN_TRANSCEIVER_MODULE_MALFUNCTION 		0x42
/* Application state define. */
#define DIAGCTRL_CAN_BUS_OFF 								0x52
/* Application state define. */
#define DIAGCTRL_LCD_MODULE_MALFUNCTION 					0x62
/* Application state define. */
#define DIAGCTRL_INIT_STATE									0x00
/* Application state define. */
#define DIAGCTRL_DEINIT_STATE								0x02
/* Application state define. */
#define DIAGCTRL_PROCESSDATA_STATE							0x01
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
/* Application state variable. */
EXTERN uint8 DiagCtrl_ApplState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Initialization function declaration. */
EXTERN StdReturnType DiagCtrl_Init();
/* De-initialization function declaration. */
EXTERN StdReturnType DiagCtrl_DeInit();
/* Main function declaration. */
EXTERN VOID DiagCtrl_MainFunction();
/* Process requested data function declaration. */
EXTERN VOID DiagCtrl_ProcessRequestedData();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* DiagCtrl_H */
