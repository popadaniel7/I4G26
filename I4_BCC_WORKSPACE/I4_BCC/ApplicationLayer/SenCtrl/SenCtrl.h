/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Sensor Control	     		 *
******************************************/
#ifndef SenCtrl_H
#define SenCtrl_H
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
#define SENCTRL_EXTLIGHTS_LS_POSITION 				0x00
/* Application request define. */
#define SENCTRL_SECALM_VS_POSITION 					0x01
/* Application request define. */
#define SENCTRL_HVAC_AQS_POSITION 					0x02
/* Application request define. */
#define SENCTRL_HVAC_TS_POSITION 					0x03
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_L_POSITION 				0x04
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_R_POSITION 				0x05
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_L_POSITION 			0x06
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_R_POSITION 			0x07
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_R_POSITION 				0x08
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_L_POSITION 				0x09
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_F_POSITION 			0x10
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_R_POSITION 			0x11
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_R_POSITION 			0x12
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_F_POSITION 			0x13
/* Application request define. */
#define SENCTRL_ADC_VREFINT_POSITION 				0x14
/* Application request define. */
#define SENCTRL_ADC_TEMPERATURE_SENSOR_POSITION 	0x15
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_L_OK 					1
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_L_UV 					2
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_L_SH 					3
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_R_OK 					4
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_R_UV 					5
/* Application request define. */
#define SENCTRL_DIAGCTRL_LB_R_SH 					6
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_L_OK 					7
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_L_UV 					8
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_L_SH 					9
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_R_OK 					10
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_R_UV 					11
/* Application request define. */
#define SENCTRL_DIAGCTRL_RPL_R_SH 					12
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_R_OK 					13
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_R_UV 					14
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_R_SH 					15
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_L_OK 					16
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_L_UV 					17
/* Application request define. */
#define SENCTRL_DIAGCTRL_BL_L_SH 					18
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_F_OK 					19
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_F_UV 					20
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_F_SH 					21
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_R_OK 					22
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_R_UV 					23
/* Application request define. */
#define SENCTRL_DIAGCTRL_LTS_R_SH 					24
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_R_OK 					25
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_R_UV 					26
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_R_SH 					27
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_F_OK 					28
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_F_UV 					29
/* Application request define. */
#define SENCTRL_DIAGCTRL_RTS_F_SH 					30
/* Application request define. */
#define SENCTRL_THRESHOLD_OK						2000
/* Application request define. */
#define SENCTRL_THRESHOLD_SH						100
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Application state variable. */
EXTERN uint8 SenCtrl_ApplState;
/* Adc measurements array variable. */
EXTERN uint32 SenCtrl_MeasuredValues[16];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Application main function declaration. */
EXTERN VOID SenCtrl_MainFunction();
/* Application initialization function declaration. */
EXTERN StdReturnType SenCtrl_Init();
/* Application de-initialization function declaration. */
EXTERN StdReturnType SenCtrl_DeInit();
/* Process sensor value function declaration. */
EXTERN VOID SenCtrl_ProcessSensorValue(uint8 request);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* SenCtrl_H */
