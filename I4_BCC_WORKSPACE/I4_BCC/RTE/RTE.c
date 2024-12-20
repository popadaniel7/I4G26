/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Run Time Environment	         *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Rte.h"
#include "TimH.h"
#include "UartH.h"
#include "AdcH.h"
#include "WatchdogManager.h"
#include "EcuM.h"
#include "SystemManager.h"
#include "Pdc.h"
#include "DiagCtrl.h"
#include "Btc.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Run time environment interface. */
VOID Rte_Read_Dem_DemPort_Dem_DtcArray(uint8* data, uint8 position);
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim3Ccr1(uint8 data);
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim3Ccr2(uint8 data);
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim3Ccr3(uint8 data);
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim3Ccr4(uint8 data);
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim2Ccr1(uint16 data);
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim2Ccr2(uint16 data);
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim2Ccr3(uint8 data);
/* Run time environment interface. */
VOID Rte_Read_SystemManager_SystemManagerPort_SystemManager_Fault(uint8* data, uint8 position);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_AqsState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_TsState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_ApplState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_ApplState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_DiagCtrl_DiagCtrlPort_DiagCtrl_RequestValue(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_RequestValue(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorState(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorState(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LightSensorState(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightSensorState(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_SenCtrl_SenCtrlPort_SenCtrl_MeasuredValues(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_SenCtrl_SenCtrlPort_SenCtrl_MeasuredValues(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_Os_OsPort_Os_Pdc_Rear_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Os_OsPort_Os_Pdc_Rear_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Os_OsPort_Os_Pdc_Front_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Os_OsPort_Os_Pdc_Front_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Pdc_PdcPort_Pdc_Front_BuzzerOsCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Pdc_PdcPort_Pdc_Front_BuzzerOsCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Pdc_PdcPort_Pdc_Rear_BuzzerOsCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Pdc_PdcPort_Pdc_Rear_BuzzerOsCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_BlinkCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_BlinkCounter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_LockUnlockSequence_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_TurnOnCyclic_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_TurnOnLed_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_FollowMeHome_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_Lts_Counter(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_Rts_Counter(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_HL_Counter(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_Alarm_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_LockUnlockSequence_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_TurnOnCyclic_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_TurnOnLed_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_FollowMeHome_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_Lts_Counter(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_Rts_Counter(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_HL_Counter(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_Alarm_Counter(uint8* data);
/* Run time environment interface. */
VOID Rte_Call_OsTimer_R_OsTimerPort_OsTimerStop(osTimerId_t timer_id);
/* Run time environment interface. */
VOID Rte_Call_Uart_R_UartPort_HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32 Channel);
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32 Channel);
/* Run time environment interface. */
VOID Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
/* Run time environment interface. */
VOID Rte_Call_ADC_R_ADCPort_HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);
/* Run time environment interface. */
VOID Rte_Call_SysTick_R_SysTickPort_HAL_GetTick();
/* Run time environment interface. */
VOID Rte_Call_OsTimer_R_OsTimerPort_OsTimerStart(osTimerId_t timer_id, uint32_t ticks);
/* Run time environment interface. */
VOID Rte_Read_Adc_AdcPort_Adc_ChannelOne_Buffer(uint32* data, uint8 position);
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_PreviousState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_FollowMeHomeState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_BlinkState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_PreviousStateFlag(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_FlashHighBeam_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HL_PrevState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RTSFlag(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LTSFlag(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HLFlag(uint32* data);
/* Run time environment interface. */
VOID Rte_Read_IntLights_IntLightsPort_IntLights_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_IntLights_IntLightsPort_IntLights_StateFlag(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_Trigger(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_PinStateChange(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_TriggerIRQCounterForTimer4(uint8* data);
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorStatusCounter(uint16* data);
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorStatus(uint16* data);
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(uint8 data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_PreviousState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_BlinkState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_PreviousStateFlag(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_FlashHighBeam_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HL_PrevState(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RTSFlag(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LTSFlag(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HLFlag(uint32* data);
/* Run time environment interface. */
VOID Rte_Write_IntLights_IntLightsPort_IntLights_CurrentState(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_IntLights_IntLightsPort_IntLights_StateFlag(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_Trigger(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_PinStateChange(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_TriggerIRQCounterForTimer4(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorStatusCounter(uint16* data);
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorStatus(uint16* data);
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_RxData(uint8 data);
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_RxCount(uint8 data);
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_DataBuffer(uint8 data, uint8 position);
/* Run time environment interface. */
VOID Rte_Runnable_Btc_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_CenLoc_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_ExtLights_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_IntLights_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_SecAlm_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Uart_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Adc_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Tim_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Crc_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Wdg_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Spi_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_EcuM_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_SystemManager_MainFunction();
/* Run time environment interface. */
VOID Rte_Read_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue(uint8 data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_FanValue(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_TemperatureValue(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_LegVent(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_MidVent(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_WindshieldVent(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_WindshieldDefrost(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_RearWindshieldDefrost(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_Ac(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_Recirculation(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_NoRecirculation(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_AutomaticRecirculation(uint8* data);
/* Run time environment interface. */
VOID Rte_Write_Hvac_HvacPort_Hvac_AutomaticMode(uint8* data);
/* Run time environment interface. */
VOID Rte_Runnable_DiagCtrl_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_SenCtrl_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Hvac_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Pdc_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Can_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_I2c_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_Dem_MainFunction();
/* Run time environment interface. */
VOID Rte_Runnable_NvM_MainFunction();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim3Ccr1(uint8 data)
{
	TIM3->CCR1 = data;
}
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim3Ccr2(uint8 data)
{
	TIM3->CCR2 = data;
}
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim3Ccr3(uint8 data)
{
	TIM3->CCR3 = data;
}
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim3Ccr4(uint8 data)
{
	TIM3->CCR4 = data;
}
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim2Ccr1(uint16 data)
{
	TIM2->CCR1 = data;
}
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim2Ccr2(uint16 data)
{
	TIM2->CCR2 = data;
}
/* Run time environment interface. */
VOID Rte_Write_TimH_TimHPort_Tim2Ccr3(uint8 data)
{
	TIM2->CCR3 = data;
}
/* Run time environment interface. */
VOID Rte_Read_SystemManager_SystemManagerPort_SystemManager_Fault(uint8* data, uint8 position)
{
	*data = SystemManager_Fault[position];
}
/* Run time environment interface. */
VOID Rte_Read_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue(uint8* data)
{
	*data = DiagCtrl_FaultValue;
}
/* Run time environment interface. */
VOID Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_FaultValue(uint8 data)
{
	DiagCtrl_FaultValue = data;
}
/* Run time environment interface. */
VOID Rte_Read_DiagCtrl_DiagCtrlPort_DiagCtrl_RequestValue(uint8* data)
{
	*data = DiagCtrl_RequestValue;
}
/* Run time environment interface. */
VOID Rte_Write_DiagCtrl_DiagCtrlPort_DiagCtrl_RequestValue(uint8* data)
{
	DiagCtrl_RequestValue = *data;
}
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorState(uint32* data)
{
	*data = SecAlm_SensorState;
}
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorState(uint32* data)
{
	SecAlm_SensorState = *data;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LightSensorState(uint32* data)
{
	*data = ExtLights_LightSensorState;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightSensorState(uint32* data)
{
	ExtLights_LightSensorState = *data;
}
/* Run time environment interface. */
VOID Rte_Read_SenCtrl_SenCtrlPort_SenCtrl_MeasuredValues(uint32* data)
{
	Adc_ChannelOne_Buffer[0] = SenCtrl_MeasuredValues[0];
	Adc_ChannelOne_Buffer[1] = SenCtrl_MeasuredValues[1];
}
/* Run time environment interface. */
VOID Rte_Write_SenCtrl_SenCtrlPort_SenCtrl_MeasuredValues(uint32* data)
{
	 SenCtrl_MeasuredValues[0] = Adc_ChannelOne_Buffer[0];
	 SenCtrl_MeasuredValues[1] = Adc_ChannelOne_Buffer[1];
}
/* Run time environment interface. */
VOID Rte_Read_Os_OsPort_Os_Pdc_Rear_Counter(uint8* data)
{
	*data = Os_Pdc_Rear_Counter;
}
/* Run time environment interface. */
VOID Rte_Write_Os_OsPort_Os_Pdc_Rear_Counter(uint8* data)
{
	Os_Pdc_Rear_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Read_Os_OsPort_Os_Pdc_Front_Counter(uint8* data)
{
	*data = Os_Pdc_Front_Counter;
}
/* Run time environment interface. */
VOID Rte_Write_Os_OsPort_Os_Pdc_Front_Counter(uint8* data)
{
	Os_Pdc_Front_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Read_Pdc_PdcPort_Pdc_Front_BuzzerOsCounter(uint8* data)
{
	*data = Pdc_Front_BuzzerOsCounter;
}
/* Run time environment interface. */
VOID Rte_Write_Pdc_PdcPort_Pdc_Front_BuzzerOsCounter(uint8* data)
{
	Pdc_Front_BuzzerOsCounter = *data;
}
/* Run time environment interface. */
VOID Rte_Read_Pdc_PdcPort_Pdc_Rear_BuzzerOsCounter(uint8* data)
{
	*data = Pdc_Rear_BuzzerOsCounter;
}
/* Run time environment interface. */
VOID Rte_Write_Pdc_PdcPort_Pdc_Rear_BuzzerOsCounter(uint8* data)
{
	Pdc_Rear_BuzzerOsCounter = *data;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter(uint8* data)
{
	*data = CenLoc_FollowMeHomeCounter;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter(uint8* data)
{
	CenLoc_FollowMeHomeCounter = *data;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter(uint8* data)
{
	*data = CenLoc_TurnOnLedCounter;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter(uint8* data)
{
	CenLoc_TurnOnLedCounter = *data;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter(uint8* data)
{
	*data = CenLoc_CyclicAlarmCounter;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter(uint8* data)
{
	CenLoc_CyclicAlarmCounter = *data;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_BlinkCounter(uint8* data)
{
	*data = CenLoc_BlinkCounter;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_BlinkCounter(uint8* data)
{
	CenLoc_BlinkCounter = *data;
}
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_LockUnlockSequence_Counter(uint8* data)
{
	*data = Os_LockUnlockSequence_Counter;
}
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_TurnOnCyclic_Counter(uint8* data)
{
	*data = Os_TurnOnCyclic_Counter;
}
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_TurnOnLed_Counter(uint8* data)
{
	*data = Os_TurnOnLed_Counter;
}
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_FollowMeHome_Counter(uint8* data)
{
	*data = Os_FollowMeHome_Counter;
}
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_Lts_Counter(uint32* data)
{
	*data = Os_Lts_Counter;
}
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_Rts_Counter(uint32* data)
{
	*data = Os_Rts_Counter;
}
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_HL_Counter(uint32* data)
{
	*data = Os_HL_Counter;
}
/* Run time environment interface. */
VOID Rte_Read_Os_R_OsPort_Os_Alarm_Counter(uint8* data)
{
	*data = Os_Alarm_Counter;
}
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_LockUnlockSequence_Counter(uint8* data)
{
	Os_LockUnlockSequence_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_TurnOnCyclic_Counter(uint8* data)
{
	Os_TurnOnCyclic_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_TurnOnLed_Counter(uint8* data)
{
	Os_TurnOnLed_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_FollowMeHome_Counter(uint8* data)
{
	Os_FollowMeHome_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_Lts_Counter(uint32* data)
{
	Os_Lts_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_Rts_Counter(uint32* data)
{
	Os_Rts_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_HL_Counter(uint32* data)
{
	Os_HL_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Write_Os_R_OsPort_Os_Alarm_Counter(uint8* data)
{
	Os_Alarm_Counter = *data;
}
/* Run time environment interface. */
VOID Rte_Runnable_EcuM_MainFunction()
{
	EcuM_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_SystemManager_MainFunction()
{
	SystemManager_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_Crc_MainFunction()
{
	Crc_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_Wdg_MainFunction()
{
	Watchdog_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_Adc_MainFunction()
{
	Adc_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_Tim_MainFunction()
{
	Tim_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_Uart_MainFunction()
{
	Uart_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32 Channel)
{
	HAL_TIM_PWM_Start_IT(htim, Channel);
}
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32 Channel)
{
	HAL_TIM_PWM_Stop_IT(htim, Channel);
}
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_RxData(uint8 data)
{
	Btc_RxData = data;
}
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_RxCount(uint8 data)
{
	Btc_RxCount = data;
}
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_DataBuffer(uint8 data, uint8 position)
{
	Btc_DataBuffer[position] = data;
}
/* Run time environment interface. */
VOID Rte_Read_Adc_AdcPort_Adc_ChannelOne_Buffer(uint32* data, uint8 position)
{
	*data = Adc_ChannelOne_Buffer[position];
}
/* Run time environment interface. */
VOID Rte_Write_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(uint8 data)
{
	Btc_ReceivedDataOnBluetooth = data;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_CurrentState(uint8* data)
{
	CenLoc_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_PreviousState(uint8* data)
{
	CenLoc_PreviousState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeState(uint8* data)
{
	CenLoc_FollowMeHomeState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_BlinkState(uint8* data)
{
	CenLoc_BlinkState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_CenLoc_CenLocPort_CenLoc_PreviousStateFlag(uint8* data)
{
	CenLoc_PreviousStateFlag = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(uint8* data)
{
	ExtLights_ReverseLight_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(uint8* data)
{
	ExtLights_BrakeLight_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(uint8* data)
{
	ExtLights_LightsSwitch_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(uint8* data)
{
	ExtLights_HighBeam_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(uint8* data)
{
	ExtLights_FrontFogLight_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(uint8* data)
{
	ExtLights_TurnSignalLeft_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(uint8* data)
{
	ExtLights_TurnSignalRight_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(uint8* data)
{
	ExtLights_HazardLight_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(uint8* data)
{
	ExtLights_RearFogLight_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState(uint32* data)
{
	ExtLights_RTS_PrevState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState(uint32* data)
{
	ExtLights_LTS_PrevState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HL_PrevState(uint32* data)
{
	ExtLights_HL_PrevState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_RTSFlag(uint32* data)
{
	ExtLights_RTSFlag = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_LTSFlag(uint32* data)
{
	ExtLights_LTSFlag = *data;
}
/* Run time environment interface. */
VOID Rte_Write_ExtLights_ExtLightsPort_ExtLights_HLFlag(uint32* data)
{
	ExtLights_HLFlag = *data;
}
/* Run time environment interface. */
VOID Rte_Write_IntLights_IntLightsPort_IntLights_CurrentState(uint8* data)
{
	IntLights_CurrentState = *data;
}
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_Trigger(uint8* data)
{
	SecAlm_Trigger = *data;
}
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_PinStateChange(uint8* data)
{
	SecAlm_PinStateChange = *data;
}
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_TriggerIRQCounterForTimer4(uint8* data)
{
	SecAlm_TriggerIRQCounterForTimer4 = *data;
}
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorStatusCounter(uint16* data)
{
	SecAlm_SensorStatusCounter = *data;
}
/* Run time environment interface. */
VOID Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorStatus(uint16* data)
{
	SecAlm_SensorStatus = *data;
}
/* Run time environment interface. */
VOID Rte_Runnable_Btc_MainFunction()
{
	Btc_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_CenLoc_MainFunction()
{
	CenLoc_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_ExtLights_MainFunction()
{
	ExtLights_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_IntLights_MainFunction()
{
	IntLights_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_SecAlm_MainFunction()
{
	SecAlm_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(uint8* data)
{
	*data = Btc_ReceivedDataOnBluetooth;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_CenLoc(uint8* data)
{
	*data = Btc_CenLoc;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_CurrentState(uint8* data)
{
	*data = CenLoc_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_PreviousState(uint8* data)
{
	*data = CenLoc_PreviousState;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_FollowMeHomeState(uint8* data)
{
	*data = CenLoc_FollowMeHomeState;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_BlinkState(uint8* data)
{
	*data = CenLoc_BlinkState;
}
/* Run time environment interface. */
VOID Rte_Read_CenLoc_CenLocPort_CenLoc_PreviousStateFlag(uint8* data)
{
	*data = CenLoc_PreviousStateFlag;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState(uint8* data)
{
	*data = ExtLights_ReverseLight_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_BrakeLight_CurrentState(uint8* data)
{
	*data = ExtLights_BrakeLight_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState(uint8* data)
{
	*data = ExtLights_LightsSwitch_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState(uint8* data)
{
	*data = ExtLights_HighBeam_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState(uint8* data)
{
	*data = ExtLights_FrontFogLight_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState(uint8* data)
{
	*data = ExtLights_TurnSignalLeft_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState(uint8* data)
{
	*data = ExtLights_TurnSignalRight_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState(uint8* data)
{
	*data = ExtLights_HazardLight_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState(uint8* data)
{
	*data = ExtLights_RearFogLight_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_LightSwitch(uint8* data)
{
	*data = Btc_LightSwitch;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_HighBeam(uint8* data)
{
	*data = Btc_HighBeam;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_FlashHighBeam(uint8* data)
{
	*data = Btc_FlashHighBeam;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_FrontFogLight(uint8* data)
{
	*data = Btc_FrontFogLight;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_TurnSignalLeft(uint8* data)
{
	*data = Btc_TurnSignalLeft;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_TurnSignalRight(uint8* data)
{
	*data = Btc_TurnSignalRight;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_HazardLight(uint8* data)
{
	*data = Btc_HazardLight;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_BrakeLight(uint8* data)
{
	*data = Btc_BrakeLight;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_RearFogLight(uint8* data)
{
	*data = Btc_RearFogLight;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_ReverseLight(uint8* data)
{
	*data = Btc_ReverseLight;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState(uint8* data)
{
	*data = ExtLights_RTS_PrevState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState(uint8* data)
{
	*data = ExtLights_LTS_PrevState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HL_PrevState(uint8* data)
{
	*data = ExtLights_HL_PrevState;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_RTSFlag(uint32* data)
{
	*data = ExtLights_RTSFlag;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_LTSFlag(uint32* data)
{
	*data = ExtLights_LTSFlag;
}
/* Run time environment interface. */
VOID Rte_Read_ExtLights_ExtLightsPort_ExtLights_HLFlag(uint32* data)
{
	*data = ExtLights_HLFlag;
}
/* Run time environment interface. */
VOID Rte_Read_IntLights_IntLightsPort_IntLights_CurrentState(uint8* data)
{
	*data = IntLights_CurrentState;
}
/* Run time environment interface. */
VOID Rte_Read_Btc_BtcPort_Btc_IntLights(uint8* data)
{
	*data = Btc_IntLights;
}
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_Trigger(uint8* data)
{
	*data = SecAlm_Trigger;
}
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_PinStateChange(uint8* data)
{
	*data = SecAlm_PinStateChange;
}
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_TriggerIRQCounterForTimer4(uint8* data)
{
	*data = SecAlm_TriggerIRQCounterForTimer4;
}
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorStatusCounter(uint16* data)
{
	*data = SecAlm_SensorStatusCounter;
}
/* Run time environment interface. */
VOID Rte_Read_SecAlm_SecAlmPort_SecAlm_SensorStatus(uint16* data)
{
	*data = SecAlm_SensorStatus;
}
/* Run time environment interface. */
VOID Rte_Call_Uart_R_UartPort_HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
	HAL_UART_Receive_IT(huart, pData, Size);
}
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Init(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Init(htim);
}
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Start_IT(htim);
}
/* Run time environment interface. */
VOID Rte_Call_Tim_R_TimPort_HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Stop_IT(htim);
}
/* Run time environment interface. */
VOID Rte_Call_Gpio_R_GpioPort_HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}
/* Run time environment interface. */
VOID Rte_Call_ADC_R_ADCPort_HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length)
{
	HAL_ADC_Start_DMA(hadc, pData, Length);
}
/* Run time environment interface. */
VOID Rte_Call_SysTick_R_SysTickPort_HAL_GetTick()
{
	HAL_GetTick();
}
/* Run time environment interface. */
VOID Rte_Call_OsTimer_R_OsTimerPort_OsTimerStart(osTimerId_t timer_id, uint32_t ticks)
{
	osTimerStart(timer_id, ticks);
}
/* Run time environment interface. */
VOID Rte_Call_OsTimer_R_OsTimerPort_OsTimerStop(osTimerId_t timer_id)
{
	osTimerStop(timer_id);
}
/* Run time environment interface. */
VOID Rte_Runnable_DiagCtrl_MainFunction()
{
	DiagCtrl_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_Pdc_MainFunction()
{
	Pdc_MainFunction();
}
/* Run time environment interface. */
VOID Rte_Runnable_Dem_MainFunction()
{
	Dem_MainFunction();
}
