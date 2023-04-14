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
/* Diagnostic request define. */
#define DIAGCTRL_NO_REQUEST			0x00
/* Diagnostic request define. */
#define DIAGCTRL_LB_L_REQUEST		0x08
/* Diagnostic request define. */
#define DIAGCTRL_LB_R_REQUEST		0x09
/* Diagnostic request define. */
#define DIAGCTRL_RPL_L_REQUEST		0x10
/* Diagnostic request define. */
#define DIAGCTRL_RPL_R_REQUEST		0x11
/* Diagnostic request define. */
#define DIAGCTRL_BL_R_REQUEST		0x12
/* Diagnostic request define. */
#define DIAGCTRL_BL_L_REQUEST		0x13
/* Diagnostic request define. */
#define DIAGCTRL_LTS_F_REQUEST		0x14
/* Diagnostic request define. */
#define DIAGCTRL_LTS_R_REQUEST		0x15
/* Diagnostic request define. */
#define DIAGCTRL_RTS_R_REQUEST		0x16
/* Diagnostic request define. */
#define DIAGCTRL_RTS_F_REQUEST		0x17
/* Diagnostic request define. */
#define DIAGCTRL_LB_L_UV 			0
/* Diagnostic request define. */
#define DIAGCTRL_LB_L_SH 			1
/* Diagnostic request define. */
#define DIAGCTRL_LB_R_UV 			2
/* Diagnostic request define. */
#define DIAGCTRL_LB_R_SH 			3
/* Diagnostic request define. */
#define DIAGCTRL_RPL_L_UV 			4
/* Diagnostic request define. */
#define DIAGCTRL_RPL_L_SH 			5
/* Diagnostic request define. */
#define DIAGCTRL_RPL_R_UV 			6
/* Diagnostic request define. */
#define DIAGCTRL_RPL_R_SH 			7
/* Diagnostic request define. */
#define DIAGCTRL_BL_R_UV 			8
/* Diagnostic request define. */
#define DIAGCTRL_BL_R_SH 			9
/* Diagnostic request define. */
#define DIAGCTRL_BL_L_UV 			10
/* Diagnostic request define. */
#define DIAGCTRL_BL_L_SH 			11
/* Diagnostic request define. */
#define DIAGCTRL_LTS_F_UV 			12
/* Diagnostic request define. */
#define DIAGCTRL_LTS_F_SH 			13
/* Diagnostic request define. */
#define DIAGCTRL_LTS_R_UV 			14
/* Diagnostic request define. */
#define DIAGCTRL_LTS_R_SH 			15
/* Diagnostic request define. */
#define DIAGCTRL_RTS_R_UV 			16
/* Diagnostic request define. */
#define DIAGCTRL_RTS_R_SH 			17
/* Diagnostic request define. */
#define DIAGCTRL_RTS_F_UV 			18
/* Diagnostic request define. */
#define DIAGCTRL_RTS_F_SH 			19
/* Application state define. */
#define DIAGCTRL_INIT_STATE			0x00
/* Application state define. */
#define DIAGCTRL_DEINIT_STATE		0x02
/* Application state define. */
#define DIAGCTRL_PROCESSDATA_STATE	0x01
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
/* Send processed data function declaration. */
EXTERN VOID DiagCtrl_SendProcessedData();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* DiagCtrl_H */
