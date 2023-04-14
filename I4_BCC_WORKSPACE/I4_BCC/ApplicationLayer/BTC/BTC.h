/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Bluetooth Communication	     *
******************************************/
#ifndef Btc_H
#define Btc_H
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
/* Buffer size for the UART data transmission. */
#define BTC_BUFFER_SIZE 						4
/* Bluetooth command for central lock unlocking. */
#define BTC_RX_CENLOC_ON 						1
/* Bluetooth command for central lock locking. */
#define BTC_RX_CENLOC_OFF 						2
/* Bluetooth command for high beam turn on. */
#define BTC_RX_EXTLIGHTS_HIGHBEAM_ON			3
/* Bluetooth command for high beam turn off. */
#define BTC_RX_EXTLIGHTS_HIGHBEAM_OFF 			4
/* Bluetooth command for flashing the high beam on. */
#define BTC_RX_EXTLIGHTS_FLASHHIGHBEAM_ON 		5
/* Bluetooth command for flashing the high beam off. */
#define BTC_RX_EXTLIGHTS_FLASHHIGHBEAM_OFF 		6
/* Bluetooth command for left turn signal on. */
#define BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_ON 		7
/* Bluetooth command for left turn signal off. */
#define BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_OFF 	8
/* Bluetooth command for right turn signal on. */
#define BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_ON 	9
/* Bluetooth command for right turn signal off. */
#define BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_OFF 	10
/* Bluetooth command for hazard light on. */
#define BTC_RX_EXTLIGHTS_HAZARDLIGHT_ON 		11
/* Bluetooth command for hazard light off. */
#define BTC_RX_EXTLIGHTS_HAZARDLIGHT_OFF 		12
/* Bluetooth command for front fog light on. */
#define BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_ON 		13
/* Bluetooth command for front fog light off. */
#define BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_OFF 		14
/* Bluetooth command for rear fog light on. */
#define BTC_RX_EXTLIGHTS_FOGLIGHTREAR_ON 		15
/* Bluetooth command for rear fog light off. */
#define BTC_RX_EXTLIGHTS_FOGLIGHTREAR_OFF 		16
/* Bluetooth command for brake light on. */
#define BTC_RX_EXTLIGHTS_BRAKELIGHTON 			17
/* Bluetooth command for brake light off. */
#define BTC_RX_EXTLIGHTS_BRAKELIGHTOFF 			18
/* Bluetooth command for interior light on. */
#define BTC_RX_INTLIGHTS_INTERIORLIGHT_ON 		19
/* Bluetooth command for interior light off. */
#define BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF 		20
/* Bluetooth command for reverse light on. */
#define BTC_RX_EXTLIGHTS_REVERSELIGHT_ON		21
/* Bluetooth command for reverse light off. */
#define BTC_RX_EXTLIGHTS_REVERSELIGHT_OFF		22
/* Bluetooth command for light switch position zero. */
#define BTC_RX_EXTLIGHTS_POSITIONZERO			23
/* Bluetooth command for light switch position automatic. */
#define BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS		24
/* Bluetooth command for light switch position position lights. */
#define BTC_RX_EXTLIGHTS_POSITIONLIGHTS			25
/* Bluetooth command for light switch position night time lights. */
#define BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS		26
/* Bluetooth command for ignition step one. */
#define BTC_RX_IGNITION_STEP_ONE 				27
/* Bluetooth command for ignition step two. */
#define BTC_RX_IGNITION_STEP_TWO				28
/* Bluetooth command for ignition turn off. */
#define BTC_RX_IGNITION_TURN_OFF				29
/* Bluetooth command. */
#define BTC_RX_HVAC_FANVALUE_MIN				30
/* Bluetooth command. */
#define BTC_RX_HVAC_FANVALUE_MAX				37
/* Bluetooth command. */
#define BTC_RX_HVAC_TEMPERATUREVALUE_MIN		38
/* Bluetooth command. */
#define BTC_RX_HVAC_TEMPERATUREVALUE_MAX		54
/* Bluetooth command. */
#define BTC_RX_HVAC_LEGVENT_ON					55
/* Bluetooth command. */
#define BTC_RX_HVAC_LEGVENT_OFF					56
/* Bluetooth command. */
#define BTC_RX_HVAC_MIDVENT_ON					57
/* Bluetooth command. */
#define BTC_RX_HVAC_MIDVENT_OFF					58
/* Bluetooth command. */
#define BTC_RX_HVAC_WINDSHIELDVENT_ON			59
/* Bluetooth command. */
#define BTC_RX_HVAC_WINDSHIELDVENT_OFF			60
/* Bluetooth command. */
#define BTC_RX_HVAC_WINDSHIELDDEFROST_ON		61
/* Bluetooth command. */
#define BTC_RX_HVAC_WINDSHIELDDEFROST_OFF		62
/* Bluetooth command. */
#define BTC_RX_HVAC_AC_ON						63
/* Bluetooth command. */
#define BTC_RX_HVAC_AC_OFF						64
/* Bluetooth command. */
#define BTC_RX_HVAC_RECIRCULATION				65
/* Bluetooth command. */
#define BTC_RX_HVAC_NORECIRCULATION				66
/* Bluetooth command. */
#define BTC_RX_HVAC_AUTOMATICRECIRCULATION		67
/* Bluetooth command. */
#define BTC_RX_HVAC_AUTOMATICMODE_ON			68
/* Bluetooth command. */
#define BTC_RX_HVAC_AUTOMATICMODE_OFF			69
/* Bluetooth command. */
#define BTC_RX_HVAC_REARWINDSHIELDDEFROST_ON	70
/* Bluetooth command. */
#define BTC_RX_HVAC_REARWINDSHIELDDEFROST_OFF	71
/* Bluetooth command. */
#define BTC_RX_CENLOC_FOLLOWMEHOME				72
/* Application state define  */
#define BTC_INIT_STATE							0x01
/* Application state define  */
#define BTC_DEINIT_STATE						0x04
/* Application state define  */
#define BTC_RX_STATE 							0x02
/* Application state define  */
#define BTC_IGNITION_PROCESSING_STATE 			0x03
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_FollowMeHome;
/* Variable to store the state of the application. */
EXTERN uint8 Btc_ApplState;
/* Data buffer for bluetooth communication through UART. */
EXTERN uint8 Btc_DataBuffer[BTC_BUFFER_SIZE];
/* UART data received from bluetooth module. */
EXTERN uint8 Btc_RxData;
/* Counter for data length. */
EXTERN uint8 Btc_RxCount;
/* Index for positions inside the buffer. */
EXTERN uint8 Btc_BufferIndex;
/* Bluetooth command converted into uint8. */
EXTERN uint8 Btc_ReceivedDataOnBluetooth;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_CenLoc;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_LightSwitch;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_HighBeam;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_FlashHighBeam;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_FrontFogLight;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_TurnSignalLeft;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_TurnSignalRight;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_HazardLight;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_BrakeLight;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_RearFogLight;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_ReverseLight;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_IntLights;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_IgnitionStepOne;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_IgnitionStepTwo;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_IgnitionTurnOff;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_FanValue;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_TemperatureValue;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_LegVent;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_MidVent;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_WindshieldVent;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_WindshieldDefrost;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_RearWindshieldDefrost;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_Ac;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_Recirculation;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_NoRecirculation;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_AutomaticRecirculation;
/* Auxiliary variable used for bluetooth command. */
EXTERN uint8 Btc_AutomaticMode;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Write into memory function declaration. */
EXTERN VOID Btc_MemWrite();
/* Read from memory function declaration. */
EXTERN VOID Btc_MemRead();
/* Bluetooth communication main function declaration. */
EXTERN VOID Btc_MainFunction();
/* Ignition command processing function declaration. */
EXTERN VOID Btc_IgnitionState();
/* Bluetooth communication initialization for the application function declaration. */
EXTERN StdReturnType Btc_Init();
/* Bluetooth communication de-initialization for the application function declaration. */
EXTERN StdReturnType Btc_DeInit();
/* Bluetooth command processing function declaration. */
EXTERN VOID Btc_RxVal();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* Btc_H */
