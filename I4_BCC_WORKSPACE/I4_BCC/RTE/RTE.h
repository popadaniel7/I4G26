/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Run Time Environment	         *
******************************************/
#ifndef Rte_H
#define Rte_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Btc.h"
#include "CenLoc.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "SenCtrl.h"
#include "CrcH.h"
#include "TimH.h"
#include "AdcH.h"
#include "Dem.h"
#include "Pdc.h"
#include "DiagCtrl.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Run time environment define standard value. */
#define RTE_E_OK 		0x00
/* Run time environment define standard value. */
#define RTE_E_NOT_OK 	0x01
/* Run time environment define standard value. */
#define RTE_E_INVALID 	0x02
/* Run time environment interface. */
#define RTE_P_ADC_BUFFER_VIBSEN 					ADC_BUFFER_VIBSEN
/* Run time environment interface. */
#define RTE_P_ADC_BUFFER_LIGHTSEN 					ADC_BUFFER_LIGHTSEN
/* Run time environment interface. */
#define RTE_P_BTC_RX_CENLOC_ON 						BTC_RX_CENLOC_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_CENLOC_OFF 					BTC_RX_CENLOC_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_CENLOC_FOLLOWMEHOME			BTC_RX_CENLOC_FOLLOWMEHOME
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_REVERSELIGHT_ON 		BTC_RX_EXTLIGHTS_REVERSELIGHT_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_REVERSELIGHT_OFF 	BTC_RX_EXTLIGHTS_REVERSELIGHT_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_HIGHBEAM_ON 			BTC_RX_EXTLIGHTS_HIGHBEAM_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_HIGHBEAM_OFF 		BTC_RX_EXTLIGHTS_HIGHBEAM_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_ON 	BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_OFF 	BTC_RX_EXTLIGHTS_TURNSIGNALLEFT_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_ON 	BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_OFF 	BTC_RX_EXTLIGHTS_TURNSIGNALRIGHT_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_HAZARDLIGHT_ON 		BTC_RX_EXTLIGHTS_HAZARDLIGHT_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_HAZARDLIGHT_OFF 		BTC_RX_EXTLIGHTS_HAZARDLIGHT_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_ON 	BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_OFF 	BTC_RX_EXTLIGHTS_FOGLIGHTFRONT_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTREAR_ON 		BTC_RX_EXTLIGHTS_FOGLIGHTREAR_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_FOGLIGHTREAR_OFF 	BTC_RX_EXTLIGHTS_FOGLIGHTREAR_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_BRAKELIGHTON 		BTC_RX_EXTLIGHTS_BRAKELIGHTON
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_BRAKELIGHTOFF 		BTC_RX_EXTLIGHTS_BRAKELIGHTOFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_POSITIONZERO 		BTC_RX_EXTLIGHTS_POSITIONZERO
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS		BTC_RX_EXTLIGHTS_AUTOMATICLIGHTS
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_POSITIONLIGHTS 		BTC_RX_EXTLIGHTS_POSITIONLIGHTS
/* Run time environment interface. */
#define RTE_P_BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS 		BTC_RX_EXTLIGHTS_NIGHTTIMELIGHTS
/* Run time environment interface. */
#define RTE_P_BTC_RX_INTLIGHTS_INTERIORLIGHT_ON 	BTC_RX_INTLIGHTS_INTERIORLIGHT_ON
/* Run time environment interface. */
#define RTE_P_BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF 	BTC_RX_INTLIGHTS_INTERIORLIGHT_OFF
/* Run time environment interface. */
#define RTE_P_BTC_RX_CENLOC_FOLLOWMEHOME			BTC_RX_CENLOC_FOLLOWMEHOME
/* Run time environment interface. */
#define RTE_P_CENLOC_DOOR_LED_PORT 					CENLOC_DOOR_LED_PORT
/* Run time environment interface. */
#define RTE_P_CENLOC_DOOR_LED_PIN 					CENLOC_DOOR_LED_PIN
/* Run time environment interface. */
#define RTE_P_CENLOC_BUZZER_PORT 					CENLOC_BUZZER_PORT
/* Run time environment interface. */
#define RTE_P_CENLOC_BUZZER_PIN						CENLOC_BUZZER_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LOWBEAM_PORT  				EXTLIGHTS_LOWBEAM_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LOWBEAM_PIN 	 			EXTLIGHTS_LOWBEAM_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_HIGHBEAM_PORT 	 			EXTLIGHTS_HIGHBEAM_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_HIGHBEAM_PIN 				EXTLIGHTS_HIGHBEAM_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_DAYTIMERUNNINGLIGHT_PORT  	EXTLIGHTS_DAYTIMERUNNINGLIGHT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_DAYTIMERUNNINGLIGHT_PIN 	EXTLIGHTS_DAYTIMERUNNINGLIGHT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_FRONTFOGLIGHT_PORT 			EXTLIGHTS_FRONTFOGLIGHT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_FRONTFOGLIGHT_PIN			EXTLIGHTS_FRONTFOGLIGHT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_TURNSIGNALLEFT_PORT			EXTLIGHTS_TURNSIGNALLEFT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_TURNSIGNALLEFT_PIN			EXTLIGHTS_TURNSIGNALLEFT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_TURNSIGNALRIGHT_PORT		EXTLIGHTS_TURNSIGNALRIGHT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_TURNSIGNALRIGHT_PIN			EXTLIGHTS_TURNSIGNALRIGHT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_REARPOSITIONLIGHT_PORT		EXTLIGHTS_REARPOSITIONLIGHT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_REARPOSITIONLIGHT_PIN 		EXTLIGHTS_REARPOSITIONLIGHT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_REARFOGLIGHT_PORT 			EXTLIGHTS_REARFOGLIGHT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_REARFOGLIGHT_PIN 			EXTLIGHTS_REARFOGLIGHT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_BRAKELIGHT_PORT 			EXTLIGHTS_BRAKELIGHT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_BRAKELIGHT_PIN 				EXTLIGHTS_BRAKELIGHT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_REVERSELIGHT_PORT 			EXTLIGHTS_REVERSELIGHT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_REVERSELIGHT_PIN 			EXTLIGHTS_REVERSELIGHT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LICENSEPLATELIGHT_PORT 		EXTLIGHTS_LICENSEPLATELIGHT_PORT
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LICENSEPLATELIGHT_PIN 		EXTLIGHTS_LICENSEPLATELIGHT_PIN
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LIGHTSWITCH_STATEZERO 		EXTLIGHTS_LIGHTSWITCH_STATEZERO
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LIGHTSWITCH_STATEONE 		EXTLIGHTS_LIGHTSWITCH_STATEONE
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LIGHTSWITCH_STATETWO 		EXTLIGHTS_LIGHTSWITCH_STATETWO
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LIGHTSWITCH_STATETHREE 		EXTLIGHTS_LIGHTSWITCH_STATETHREE
/* Run time environment interface. */
#define RTE_P_EXTLIGHTS_LIGHTSENSOR_DAYNIGHTVALUE 	EXTLIGHTS_LIGHTSENSOR_DAYNIGHTVALUE
/* Run time environment interface. */
#define RTE_P_SECALM_BUZZER_PORT 					SECALM_BUZZER_PORT
/* Run time environment interface. */
#define RTE_P_SECALM_BUZZER_PIN 					SECALM_BUZZER_PIN
/* Run time environment interface. */
#define RTE_P_SECALM_LED_PORT 						SECALM_LED_PORT
/* Run time environment interface. */
#define RTE_P_SECALM_LED_PIN 						SECALM_LED_PIN
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_Htim2 													&htim2
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_Htim3 													&htim3
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_Htim4 													&htim4
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_Htim5 													&htim5
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_TimChannel1 												TIM_CHANNEL_1
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_TimChannel2 												TIM_CHANNEL_2
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_TimChannel3 												TIM_CHANNEL_3
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_TimChannel4 												TIM_CHANNEL_4
/* Run time environment interface. */
#define Rte_P_Os_OsPort_Os_Counter													Os_Counter
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_Tim5_CalculatedDistance_ChannelThree  					Tim5_CalculatedDistance_ChannelThree
/* Run time environment interface. */
#define Rte_P_Tim_TimPort_Tim5_CalculatedDistance_ChannelFour                       Tim5_CalculatedDistance_ChannelFour
/* Run time environment interface. */
#define Rte_P_Pdc_PdcPort_Pdc_Rear_Distance											Pdc_Rear_Distance
/* Run time environment interface. */
#define Rte_P_Pdc_PdcPort_Pdc_Front_Distance										Pdc_Front_Distance
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_ReceivedDataOnBluetooth 								Btc_ReceivedDataOnBluetooth
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_CenLoc 												Btc_CenLoc
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_LightSwitch 											Btc_LightSwitch
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_HighBeam 												Btc_HighBeam
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_FlashHighBeam 										Btc_FlashHighBeam
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_FrontFogLight 										Btc_FrontFogLight
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_TurnSignalLeft 										Btc_TurnSignalLeft
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_TurnSignalRight 										Btc_TurnSignalRight
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_HazardLight 											Btc_HazardLight
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_BrakeLight 											Btc_BrakeLight
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_RearFogLight 											Btc_RearFogLight
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_ReverseLight 											Btc_ReverseLight
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_IntLights 											Btc_IntLights
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_RxData												Btc_RxData
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_RxCount 												Btc_RxCount
/* Run time environment interface. */
#define Rte_P_Btc_BtcPort_Btc_DataBuffer 											Btc_DataBuffer
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState 								CenLoc_CurrentState
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_PreviousState 								CenLoc_PreviousState
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_FollowMeHomeState 							CenLoc_FollowMeHomeState
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_BlinkState		 							CenLoc_BlinkState
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_BlinkCounter 								CenLoc_BlinkCounter
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter 							CenLoc_CyclicAlarmCounter
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter 							CenLoc_FollowMeHomeCounter
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter 							CenLoc_TurnOnLedCounter
/* Run time environment interface. */
#define Rte_P_CenLoc_CenLocPort_CenLoc_PreviousStateFlag 							CenLoc_PreviousStateFlag
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_LowBeam_CurrentState				ExtLights_LowBeam_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_RearPositionLights_CurrentState		ExtLights_RearPositionLights_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState 			ExtLights_ReverseLight_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_FlashHighBeam_CurrentState 			ExtLights_FlashHighBeam_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState 			ExtLights_BrakeLight_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState 			ExtLights_LightsSwitch_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState 				ExtLights_HighBeam_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState 			ExtLights_FrontFogLight_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState 		ExtLights_TurnSignalLeft_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState 		ExtLights_TurnSignalRight_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState 			ExtLights_HazardLight_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState 			ExtLights_RearFogLight_CurrentState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState 						ExtLights_RTS_PrevState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState 						ExtLights_LTS_PrevState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_HL_PrevState 						ExtLights_HL_PrevState
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_RTSFlag 							ExtLights_RTSFlag
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_LTSFlag	 							ExtLights_LTSFlag
/* Run time environment interface. */
#define Rte_P_ExtLights_ExtLightsPort_ExtLights_HLFlag 								ExtLights_HLFlag
/* Run time environment interface. */
#define Rte_P_IntLights_IntLightsPort_IntLights_CurrentState 						IntLights_CurrentState
/* Run time environment interface. */
#define Rte_P_IntLights_IntLightsPort_IntLights_StateFlag 							IntLights_StateFlag
/* Run time environment interface. */
#define Rte_P_SecAlm_SecAlmPort_SecAlm_Trigger 										SecAlm_Trigger
/* Run time environment interface. */
#define Rte_P_SecAlm_SecAlmPort_SecAlm_PinStateChange 								SecAlm_PinStateChange
/* Run time environment interface. */
#define Rte_P_SecAlm_SecAlmPort_SecAlm_TriggerIRQCounterForTimer4 					SecAlm_TriggerIRQCounterForTimer4
/* Run time environment interface. */
#define Rte_P_SecAlm_SecAlmPort_SecAlm_SensorStatusCounter 							SecAlm_SensorStatusCounter
/* Run time environment interface. */
#define Rte_P_SecAlm_SecAlmPort_SecAlm_SensorStatus 								SecAlm_SensorStatus
/* Run time environment interface. */
#define Rte_Call_Btc_R_BtcPort_Btc_Enable_Uart() 									Btc_EnableUart()
/* Run time environment interface. */
#define Rte_Call_CenLoc_R_CenLocPort_CenLoc_BlinkSignals() 							CenLoc_BlinkSignals()
/* Run time environment interface. */
#define Rte_Call_CenLoc_R_CenLocPort_CenLoc_ControlAlarmLed() 						CenLoc_ControlAlarmLed()
/* Run time environment interface. */
#define Rte_Call_CenLoc_R_CenLocPort_CenLoc_Init() 									CenLoc_Init()
/* Run time environment interface. */
#define Rte_Call_CenLoc_R_CenLocPort_CenLoc_FollowMeHome() 							CenLoc_FollowMeHome()
/* Run time environment interface. */
#define Rte_Call_CenLoc_R_CenLocPort_CenLoc_LockSequence() 							CenLoc_LockSequence()
/* Run time environment interface. */
#define Rte_Call_CenLoc_R_CenLocPort_CenLoc_UnlockSequence() 						CenLoc_UnlockSequence()
/* Run time environment interface. */
#define Rte_Call_CenLoc_R_CenLocPort_CenLoc_State() 								CenLoc_State()
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_BrakeLight(data) 				ExtLights_BrakeLight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_DayTimeRunningLight(data) 		ExtLights_DayTimeRunningLight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_FrontFogLight(data) 			ExtLights_FrontFogLight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_RearFogLight(data) 			ExtLights_RearFogLight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_LicensePlateLight(data) 		ExtLights_LicensePlateLight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_TurnSignalLeft(data) 			ExtLights_TurnSignalLeft(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_TurnSignalRight(data) 			ExtLights_TurnSignalRight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_TurnSignalHazardLight(data) 	ExtLights_TurnSignalHazardLight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_RearPositionLight(data) 		ExtLights_RearPositionLight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_ReverseLight(data) 			ExtLights_ReverseLight(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_LowBeam(data) 					ExtLights_LowBeam(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_HighBeam(data) 				ExtLights_HighBeam(data)
/* Run time environment interface. */
#define Rte_Read_ExtLights_R_ExtLightsPort_ExtLights_LightReadSensorValue(data) 	ExtLights_LightReadSensorValue(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_LightSwitchMode(data) 			ExtLights_LightSwitchMode(data)
/* Run time environment interface. */
#define Rte_Call_ExtLights_R_ExtLightsPort_ExtLights_Init() 						ExtLights_Init()
/* Run time environment interface. */
#define Rte_Call_IntLights_R_IntLightsPort_IntLights_Init() 						IntLights_Init()
/* Run time environment interface. */
#define Rte_Call_IntLights_R_IntLightsPort_IntLights_ToggleIntLights() 				IntLights_ToggleIntLights()
/* Run time environment interface. */
#define Rte_Call_SecAlm_R_SecAlmPort_SecAlm_Init() 									SecAlm_Init()
/* Run time environment interface. */
#define Rte_Call_SecAlm_R_SecAlmPort_SecAlm_ToggleAlarmBuzzer(data) 				SecAlm_ToggleAlarmBuzzer(data)
/* Run time environment interface. */
#define Rte_Call_SecAlm_R_SecAlmPort_SecAlm_ToggleAlarmLed(data) 					SecAlm_ToggleAlarmLed(data)
/* Run time environment interface. */
#define Rte_Read_SecAlm_R_SecAlmPort_SecAlm_VibSenReadSensorValue() 				SecAlm_VibSenReadSensorValue()
/* Run time environment interface. */
#define Rte_Read_SecAlm_R_SecAlmPort_SecAlm_VibSenStatus() 							SecAlm_VibSenStatus()
/* Run time environment interface. */
#define Rte_Call_Tim_R_TimPort_HAL_TIM_SET_COUNTER(handle, counter) 				__HAL_TIM_SET_COUNTER(handle, counter)
/* Run time environment interface. */
#define Rte_Call_Tim_R_TimPort_HAL_TIM_ENABLE_IT(handle, interrupt)					__HAL_TIM_ENABLE_IT(handle, interrupt)
/* Run time environment interface. */
#define Rte_Call_Crc_R_CrcPort_Crc_VerifyUartData()									Crc_VerifyUartData()
/* Run time environment interface. */
#define Rte_Call_Os_R_OsPort_OsTimerIsRunning(timer_id)								osTimerIsRunning(timer_id)
/* Run time environment interface. */
#define Rte_Call_SenCtrl_P_SenCtrlPort_SenCtrl_ProcessSensorValue(request)			SenCtrl_ProcessSensorValue(request)
/* Run time environment interface. */
#define Rte_Call_Dem_P_DemPort_Dem_ReceiveFault(faultValue) 						Dem_ReceiveFault(faultValue)
/* Run time environment interface. */
#define Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_Clear()			I2cLcd_Clear()
/* Run time environment interface. */
#define Rte_Call_I2cExtEeprom_P_I2cExtEepromPort_I2cExtEeprom_Write(page, offset, data, size) I2cExtEeprom_Write(page, offset, data, size)
/* Run time environment interface. */
#define Rte_Call_I2cExtEeprom_P_I2cExtEepromPort_I2cExtEeprom_Read(page, offset, data, size) I2cExtEeprom_Read(page, offset, data, size)
/* Run time environment interface. */
#define Rte_Call_I2cExtEeprom_P_I2cExtEepromPort_I2cExtEeprom_PageErase(page) I2cExtEeprom_PageErase(page)
/* Run time environment interface. */
#define Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendCommand(cmd)	I2cLcd_SendCommand(cmd)
/* Run time environment interface. */
#define Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendData(cmd) 		I2cLcd_SendData(cmd)
/* Run time environment interface. */
#define Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString(str)		I2cLcd_SendString(str)
/* Run time environment interface. */
#define Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_ClearCell(row, col) I2cLcd_ClearCell(row, col)
/* Run time environment interface. */
#define Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(row, col) I2cLcd_SetCursor(row, col)
/* Run time environment interface. */
#define Rte_Call_NvM_P_NvMPort_NvM_Read(page, offset, data, size) NvM_Read(page, offset, data, size)
/* Run time environment interface. */
#define Rte_Call_NvM_P_NvMPort_NvM_Write(page, offset, data, size) NvM_Write(page, offset, data, size)
/* Run time environment interface. */
#define Rte_Call_NvM_P_NvMPort_NvM_PageErase(page) NvM_PageErase(page)
/* Run time environment interface. */
#define Rte_Call_SenCtrl_P_SenCtrlPort_SenCtrl_Init() SenCtrl_Init()
/* Run time environment interface. */
#define Rte_Call_DiagCtrl_P_DiagCtrlPort_DiagCtrl_Init() DiagCtrl_Init()
/* Run time environment interface. */
#define Rte_Call_CenLoc_P_CenLocPort_CenLoc_Init() CenLoc_Init()
/* Run time environment interface. */
#define Rte_Call_ExtLights_P_ExtLightsPort_ExtLights_Init() ExtLights_Init()
/* Run time environment interface. */
#define Rte_Call_Hvac_P_HvacPort_Hvac_Init() Hvac_Init()
/* Run time environment interface. */
#define Rte_Call_IntLights_P_IntLightsPort_IntLights_Init() IntLights_Init()
/* Run time environment interface. */
#define Rte_Call_Pdc_P_PdcPort_Pdc_Init() Pdc_Init()
/* Run time environment interface. */
#define Rte_Call_SecAlm_P_SecAlmPort_SecAlm_Init() SecAlm_Init()
/* Run time environment interface. */
#define Rte_Call_SenCtrl_P_SenCtrlPort_SenCtrl_DeInit() SenCtrl_DeInit()
/* Run time environment interface. */
#define Rte_Call_DiagCtrl_P_DiagCtrlPort_DiagCtrl_DeInit() DiagCtrl_DeInit()
/* Run time environment interface. */
#define Rte_Call_CenLoc_P_CenLocPort_CenLoc_DeInit() CenLoc_DeInit()
/* Run time environment interface. */
#define Rte_Call_ExtLights_P_ExtLightsPort_ExtLights_DeInit() ExtLights_DeInit()
/* Run time environment interface. */
#define Rte_Call_Hvac_P_HvacPort_Hvac_DeInit() Hvac_DeInit()
/* Run time environment interface. */
#define Rte_Call_IntLights_P_IntLightsPort_IntLights_DeInit() IntLights_DeInit()
/* Run time environment interface. */
#define Rte_Call_Pdc_P_PdcPort_Pdc_DeInit() Pdc_DeInit()
/* Run time environment interface. */
#define Rte_Call_SecAlm_P_SecAlmPort_SecAlm_DeInit() SecAlm_DeInit()
/* Run time environment interface. */
#define Rte_Call_Can_P_CanPort_CanOverSpi_isRxErrorPassive() CanOverSpi_isRxErrorPassive()
/* Run time environment interface. */
#define Rte_Call_Can_P_CanPort_CanOverSpi_isTxErrorPassive() CanOverSpi_isTxErrorPassive()
/* Run time environment interface. */
#define Rte_Call_Can_P_CanPort_Can_BusState() Can_BusState()
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_CurrentState Hvac_CurrentState
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_FanValue Hvac_FanValue
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_TemperatureValue Hvac_TemperatureValue
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_LegVent Hvac_LegVent
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_MidVent Hvac_MidVent
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_WindshieldVent Hvac_WindshieldVent
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_WindshieldDefrost Hvac_WindshieldDefrost
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_Ac Hvac_Ac
/* Run time environment interface. */
#define Rte_P_Hvac_HvacPort_Hvac_AutomaticMode Hvac_AutomaticMode
/* Run time environment interface. */
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Run time environment interface. */
EXTERN VOID Rte_Read_Dem_DemPort_Dem_DtcArray(uint8* data, uint8 position);
/* Run time environment interface. */
EXTERN VOID Rte_Read_SystemManager_SystemManagerPort_SystemManager_Fault(uint8* data, uint8 position);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_FanValue(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_TemperatureValue(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_LegVent(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_MidVent(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_WindshieldVent(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_WindshieldDefrost(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_RearWindshieldDefrost(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_Ac(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_Recirculation(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_NoRecirculation(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_AutomaticRecirculation(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_AutomaticMode(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_AqsState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Hvac_HvacPort_Hvac_TsState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Btc_BtcPort_Btc_ApplState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Btc_BtcPort_Btc_ApplState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue(uint8 data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_DiagCtrl_DiagCtrlPort_DiagCtrl_RequestValue(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_RequestValue(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorState(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorState(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LightSensorState(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightSensorState(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_SenCtrl_SenCtrlPort_SenCtrl_MeasuredValues(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_SenCtrl_SenCtrlPort_SenCtrl_MeasuredValues(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_OsPort_Os_Pdc_Rear_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_OsPort_Os_Pdc_Rear_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_OsPort_Os_Pdc_Front_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_OsPort_Os_Pdc_Front_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Pdc_PdcPort_Pdc_Front_BuzzerOsCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Pdc_PdcPort_Pdc_Front_BuzzerOsCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Pdc_PdcPort_Pdc_Rear_BuzzerOsCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Pdc_PdcPort_Pdc_Rear_BuzzerOsCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_BlinkCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_BlinkCounter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_R_OsPort_Os_LockUnlockSequence_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_R_OsPort_Os_TurnOnCyclic_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_R_OsPort_Os_TurnOnLed_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_R_OsPort_Os_FollowMeHome_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_R_OsPort_Os_Lts_Counter(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_R_OsPort_Os_Rts_Counter(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_R_OsPort_Os_HL_Counter(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Os_R_OsPort_Os_Alarm_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_R_OsPort_Os_LockUnlockSequence_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_R_OsPort_Os_TurnOnCyclic_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_R_OsPort_Os_TurnOnLed_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_R_OsPort_Os_FollowMeHome_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_R_OsPort_Os_Lts_Counter(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_R_OsPort_Os_Rts_Counter(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_R_OsPort_Os_HL_Counter(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Os_R_OsPort_Os_Alarm_Counter(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Call_OsTimer_R_OsTimerPort_OsTimerStop(osTimerId_t timer_id);
/* Run time environment interface. */
EXTERN VOID Rte_Call_Uart_R_UartPort_HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* Run time environment interface. */
EXTERN VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
/* Run time environment interface. */
EXTERN VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
/* Run time environment interface. */
EXTERN VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);
/* Run time environment interface. */
EXTERN VOID Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32 Channel);
/* Run time environment interface. */
EXTERN VOID Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32 Channel);
/* Run time environment interface. */
EXTERN VOID Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
/* Run time environment interface. */
EXTERN VOID Rte_Call_ADC_R_ADCPort_HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);
/* Run time environment interface. */
EXTERN VOID Rte_Call_SysTick_R_SysTickPort_HAL_GetTick();
/* Run time environment interface. */
EXTERN VOID Rte_Call_OsTimer_R_OsTimerPort_OsTimerStart(osTimerId_t timer_id, uint32_t ticks);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Adc_AdcPort_Adc_ChannelOne_Buffer(uint32* data, uint8 position);
/* Run time environment interface. */
EXTERN VOID Rte_Read_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_PreviousState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_FollowMeHomeState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_BlinkState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_CenLoc_CenLocPort_CenLoc_PreviousStateFlag(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_FlashHighBeam_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HL_PrevState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RTSFlag(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LTSFlag(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HLFlag(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_IntLights_IntLightsPort_IntLights_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_IntLights_IntLightsPort_IntLights_StateFlag(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_Trigger(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_PinStateChange(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_TriggerIRQCounterForTimer4(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorStatusCounter(uint16* data);
/* Run time environment interface. */
EXTERN VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorStatus(uint16* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(uint8 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_PreviousState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_BlinkState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_CenLoc_CenLocPort_CenLoc_PreviousStateFlag(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_FlashHighBeam_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HL_PrevState(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RTSFlag(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LTSFlag(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HLFlag(uint32* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_IntLights_IntLightsPort_IntLights_CurrentState(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_IntLights_IntLightsPort_IntLights_StateFlag(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_Trigger(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_PinStateChange(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_TriggerIRQCounterForTimer4(uint8* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorStatusCounter(uint16* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorStatus(uint16* data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Btc_BtcPort_Btc_RxData(uint8 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Btc_BtcPort_Btc_RxCount(uint8 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_Btc_BtcPort_Btc_DataBuffer(uint8 data, uint8 position);
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Btc_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_CenLoc_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_ExtLights_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_IntLights_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_SecAlm_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Uart_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Adc_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Tim_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Crc_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Wdg_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_EcuM_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_SystemManager_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_DiagCtrl_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_SenCtrl_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Hvac_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Pdc_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Can_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_I2c_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Dem_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_NvM_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Runnable_Spi_MainFunction();
/* Run time environment interface. */
EXTERN VOID Rte_Write_TimH_TimHPort_Tim3Ccr1(uint8 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_TimH_TimHPort_Tim3Ccr2(uint8 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_TimH_TimHPort_Tim3Ccr3(uint8 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_TimH_TimHPort_Tim3Ccr4(uint8 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_TimH_TimHPort_Tim2Ccr1(uint16 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_TimH_TimHPort_Tim2Ccr2(uint16 data);
/* Run time environment interface. */
EXTERN VOID Rte_Write_TimH_TimHPort_Tim2Ccr3(uint8 data);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* Rte_H */
