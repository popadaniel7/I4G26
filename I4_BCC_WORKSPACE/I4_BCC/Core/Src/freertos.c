/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Os_Init */
osThreadId_t Os_InitHandle;
const osThreadAttr_t Os_Init_attributes = {
  .name = "Os_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime7,
};
/* Definitions for EcuM_Init */
osThreadId_t EcuM_InitHandle;
const osThreadAttr_t EcuM_Init_attributes = {
  .name = "EcuM_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for EcuM_MainFunction */
osThreadId_t EcuM_MainFunctionHandle;
const osThreadAttr_t EcuM_MainFunction_attributes = {
  .name = "EcuM_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for BswM_Init */
osThreadId_t BswM_InitHandle;
const osThreadAttr_t BswM_Init_attributes = {
  .name = "BswM_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for BswM_MainFunction */
osThreadId_t BswM_MainFunctionHandle;
const osThreadAttr_t BswM_MainFunction_attributes = {
  .name = "BswM_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for WatchdogManager_Init */
osThreadId_t WatchdogManager_InitHandle;
const osThreadAttr_t WatchdogManager_Init_attributes = {
  .name = "WatchdogManager_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for WatchdogManager_MainFunction */
osThreadId_t WatchdogManager_MainFunctionHandle;
const osThreadAttr_t WatchdogManager_MainFunction_attributes = {
  .name = "WatchdogManager_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for ErrorManager_Init */
osThreadId_t ErrorManager_InitHandle;
const osThreadAttr_t ErrorManager_Init_attributes = {
  .name = "ErrorManager_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for ErrorManager_MainFunction */
osThreadId_t ErrorManager_MainFunctionHandle;
const osThreadAttr_t ErrorManager_MainFunction_attributes = {
  .name = "ErrorManager_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for SystemManager_Init */
osThreadId_t SystemManager_InitHandle;
const osThreadAttr_t SystemManager_Init_attributes = {
  .name = "SystemManager_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for SystemManager_MainFunction */
osThreadId_t SystemManager_MainFunctionHandle;
const osThreadAttr_t SystemManager_MainFunction_attributes = {
  .name = "SystemManager_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for ModeManager_Init */
osThreadId_t ModeManager_InitHandle;
const osThreadAttr_t ModeManager_Init_attributes = {
  .name = "ModeManager_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime4,
};
/* Definitions for ModeManager_MainFunction */
osThreadId_t ModeManager_MainFunctionHandle;
const osThreadAttr_t ModeManager_MainFunction_attributes = {
  .name = "ModeManager_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime4,
};
/* Definitions for Os_Start */
osThreadId_t Os_StartHandle;
const osThreadAttr_t Os_Start_attributes = {
  .name = "Os_Start",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime7,
};
/* Definitions for Crc_Init */
osThreadId_t Crc_InitHandle;
const osThreadAttr_t Crc_Init_attributes = {
  .name = "Crc_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for Crc_MainFunction */
osThreadId_t Crc_MainFunctionHandle;
const osThreadAttr_t Crc_MainFunction_attributes = {
  .name = "Crc_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for Rte_Init */
osThreadId_t Rte_InitHandle;
const osThreadAttr_t Rte_Init_attributes = {
  .name = "Rte_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for Rte_MainFunction */
osThreadId_t Rte_MainFunctionHandle;
const osThreadAttr_t Rte_MainFunction_attributes = {
  .name = "Rte_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for Os_StartUpHook */
osThreadId_t Os_StartUpHookHandle;
const osThreadAttr_t Os_StartUpHook_attributes = {
  .name = "Os_StartUpHook",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime7,
};
/* Definitions for Os_ShutdownHook */
osThreadId_t Os_ShutdownHookHandle;
const osThreadAttr_t Os_ShutdownHook_attributes = {
  .name = "Os_ShutdownHook",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime7,
};
/* Definitions for NvM_Init */
osThreadId_t NvM_InitHandle;
const osThreadAttr_t NvM_Init_attributes = {
  .name = "NvM_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for NvM_MainFunction */
osThreadId_t NvM_MainFunctionHandle;
const osThreadAttr_t NvM_MainFunction_attributes = {
  .name = "NvM_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for MemIf_Status */
osThreadId_t MemIf_StatusHandle;
const osThreadAttr_t MemIf_Status_attributes = {
  .name = "MemIf_Status",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Fee_Init */
osThreadId_t Fee_InitHandle;
const osThreadAttr_t Fee_Init_attributes = {
  .name = "Fee_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for Fee_MainFunction */
osThreadId_t Fee_MainFunctionHandle;
const osThreadAttr_t Fee_MainFunction_attributes = {
  .name = "Fee_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for Ea_Init */
osThreadId_t Ea_InitHandle;
const osThreadAttr_t Ea_Init_attributes = {
  .name = "Ea_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for Ea_MainFunction */
osThreadId_t Ea_MainFunctionHandle;
const osThreadAttr_t Ea_MainFunction_attributes = {
  .name = "Ea_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for VibSen_Init */
osThreadId_t VibSen_InitHandle;
const osThreadAttr_t VibSen_Init_attributes = {
  .name = "VibSen_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for VibSen_MainFunction */
osThreadId_t VibSen_MainFunctionHandle;
const osThreadAttr_t VibSen_MainFunction_attributes = {
  .name = "VibSen_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for TemSen_Init */
osThreadId_t TemSen_InitHandle;
const osThreadAttr_t TemSen_Init_attributes = {
  .name = "TemSen_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for TemSen_MainFunction */
osThreadId_t TemSen_MainFunctionHandle;
const osThreadAttr_t TemSen_MainFunction_attributes = {
  .name = "TemSen_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for SecAlm_Init */
osThreadId_t SecAlm_InitHandle;
const osThreadAttr_t SecAlm_Init_attributes = {
  .name = "SecAlm_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for SecAlm_MainFunction */
osThreadId_t SecAlm_MainFunctionHandle;
const osThreadAttr_t SecAlm_MainFunction_attributes = {
  .name = "SecAlm_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for PDC_Init */
osThreadId_t PDC_InitHandle;
const osThreadAttr_t PDC_Init_attributes = {
  .name = "PDC_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for PDC_MainFunction */
osThreadId_t PDC_MainFunctionHandle;
const osThreadAttr_t PDC_MainFunction_attributes = {
  .name = "PDC_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for LightSen_Init */
osThreadId_t LightSen_InitHandle;
const osThreadAttr_t LightSen_Init_attributes = {
  .name = "LightSen_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for LightSen_MainFunction */
osThreadId_t LightSen_MainFunctionHandle;
const osThreadAttr_t LightSen_MainFunction_attributes = {
  .name = "LightSen_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for IoH_MainFunction */
osThreadId_t IoH_MainFunctionHandle;
const osThreadAttr_t IoH_MainFunction_attributes = {
  .name = "IoH_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for IntLights_Init */
osThreadId_t IntLights_InitHandle;
const osThreadAttr_t IntLights_Init_attributes = {
  .name = "IntLights_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for IntLights_MainFunction */
osThreadId_t IntLights_MainFunctionHandle;
const osThreadAttr_t IntLights_MainFunction_attributes = {
  .name = "IntLights_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for HVAC_Init */
osThreadId_t HVAC_InitHandle;
const osThreadAttr_t HVAC_Init_attributes = {
  .name = "HVAC_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for HVAC_MainFunction */
osThreadId_t HVAC_MainFunctionHandle;
const osThreadAttr_t HVAC_MainFunction_attributes = {
  .name = "HVAC_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for ExtLights_Init */
osThreadId_t ExtLights_InitHandle;
const osThreadAttr_t ExtLights_Init_attributes = {
  .name = "ExtLights_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for ExtLights_MainFunction */
osThreadId_t ExtLights_MainFunctionHandle;
const osThreadAttr_t ExtLights_MainFunction_attributes = {
  .name = "ExtLights_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for DiagMonH_MainFunction */
osThreadId_t DiagMonH_MainFunctionHandle;
const osThreadAttr_t DiagMonH_MainFunction_attributes = {
  .name = "DiagMonH_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for ComMon_MainFunction */
osThreadId_t ComMon_MainFunctionHandle;
const osThreadAttr_t ComMon_MainFunction_attributes = {
  .name = "ComMon_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for CenLoc_Init */
osThreadId_t CenLoc_InitHandle;
const osThreadAttr_t CenLoc_Init_attributes = {
  .name = "CenLoc_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for CenLoc_MainFunction */
osThreadId_t CenLoc_MainFunctionHandle;
const osThreadAttr_t CenLoc_MainFunction_attributes = {
  .name = "CenLoc_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for BTC_Init */
osThreadId_t BTC_InitHandle;
const osThreadAttr_t BTC_Init_attributes = {
  .name = "BTC_Init",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for BTC_MainFunction */
osThreadId_t BTC_MainFunctionHandle;
const osThreadAttr_t BTC_MainFunction_attributes = {
  .name = "BTC_MainFunction",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for OsTimerCounter */
osTimerId_t OsTimerCounterHandle;
const osTimerAttr_t OsTimerCounter_attributes = {
  .name = "OsTimerCounter"
};
/* Definitions for SystemManagerCounter */
osTimerId_t SystemManagerCounterHandle;
const osTimerAttr_t SystemManagerCounter_attributes = {
  .name = "SystemManagerCounter"
};
/* Definitions for eventPOR */
osEventFlagsId_t eventPORHandle;
const osEventFlagsAttr_t eventPOR_attributes = {
  .name = "eventPOR"
};
/* Definitions for eventHWR */
osEventFlagsId_t eventHWRHandle;
const osEventFlagsAttr_t eventHWR_attributes = {
  .name = "eventHWR"
};
/* Definitions for eventSWR */
osEventFlagsId_t eventSWRHandle;
const osEventFlagsAttr_t eventSWR_attributes = {
  .name = "eventSWR"
};
/* Definitions for eventCoreReset */
osEventFlagsId_t eventCoreResetHandle;
const osEventFlagsAttr_t eventCoreReset_attributes = {
  .name = "eventCoreReset"
};
/* Definitions for eventMemManage */
osEventFlagsId_t eventMemManageHandle;
const osEventFlagsAttr_t eventMemManage_attributes = {
  .name = "eventMemManage"
};
/* Definitions for eventNMI */
osEventFlagsId_t eventNMIHandle;
const osEventFlagsAttr_t eventNMI_attributes = {
  .name = "eventNMI"
};
/* Definitions for eventHardFault */
osEventFlagsId_t eventHardFaultHandle;
const osEventFlagsAttr_t eventHardFault_attributes = {
  .name = "eventHardFault"
};
/* Definitions for eventBusFault */
osEventFlagsId_t eventBusFaultHandle;
const osEventFlagsAttr_t eventBusFault_attributes = {
  .name = "eventBusFault"
};
/* Definitions for eventUsageFault */
osEventFlagsId_t eventUsageFaultHandle;
const osEventFlagsAttr_t eventUsageFault_attributes = {
  .name = "eventUsageFault"
};
/* Definitions for eventDebugMon */
osEventFlagsId_t eventDebugMonHandle;
const osEventFlagsAttr_t eventDebugMon_attributes = {
  .name = "eventDebugMon"
};
/* Definitions for eventPVD_IRQ */
osEventFlagsId_t eventPVD_IRQHandle;
const osEventFlagsAttr_t eventPVD_IRQ_attributes = {
  .name = "eventPVD_IRQ"
};
/* Definitions for eventFlash_IRQ */
osEventFlagsId_t eventFlash_IRQHandle;
const osEventFlagsAttr_t eventFlash_IRQ_attributes = {
  .name = "eventFlash_IRQ"
};
/* Definitions for eventRCC_IRQ */
osEventFlagsId_t eventRCC_IRQHandle;
const osEventFlagsAttr_t eventRCC_IRQ_attributes = {
  .name = "eventRCC_IRQ"
};
/* Definitions for eventTIM1_IRQ */
osEventFlagsId_t eventTIM1_IRQHandle;
const osEventFlagsAttr_t eventTIM1_IRQ_attributes = {
  .name = "eventTIM1_IRQ"
};
/* Definitions for eventTIM10_IRQ */
osEventFlagsId_t eventTIM10_IRQHandle;
const osEventFlagsAttr_t eventTIM10_IRQ_attributes = {
  .name = "eventTIM10_IRQ"
};
/* Definitions for eventTIM2_IRQ */
osEventFlagsId_t eventTIM2_IRQHandle;
const osEventFlagsAttr_t eventTIM2_IRQ_attributes = {
  .name = "eventTIM2_IRQ"
};
/* Definitions for eventTIM3_IRQ */
osEventFlagsId_t eventTIM3_IRQHandle;
const osEventFlagsAttr_t eventTIM3_IRQ_attributes = {
  .name = "eventTIM3_IRQ"
};
/* Definitions for eventTIM4_IRQ */
osEventFlagsId_t eventTIM4_IRQHandle;
const osEventFlagsAttr_t eventTIM4_IRQ_attributes = {
  .name = "eventTIM4_IRQ"
};
/* Definitions for eventSPI2_IRQ */
osEventFlagsId_t eventSPI2_IRQHandle;
const osEventFlagsAttr_t eventSPI2_IRQ_attributes = {
  .name = "eventSPI2_IRQ"
};
/* Definitions for eventSPI3_IRQ */
osEventFlagsId_t eventSPI3_IRQHandle;
const osEventFlagsAttr_t eventSPI3_IRQ_attributes = {
  .name = "eventSPI3_IRQ"
};
/* Definitions for eventUSART1_IRQ */
osEventFlagsId_t eventUSART1_IRQHandle;
const osEventFlagsAttr_t eventUSART1_IRQ_attributes = {
  .name = "eventUSART1_IRQ"
};
/* Definitions for eventWDGR */
osEventFlagsId_t eventWDGRHandle;
const osEventFlagsAttr_t eventWDGR_attributes = {
  .name = "eventWDGR"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Task_Os_Init(void *argument);
void Task_EcuM_Init(void *argument);
void Task_EcuMMainFunction(void *argument);
void Task_BswM_Init(void *argument);
void Task_BswMMainFunction(void *argument);
void Task_WatchdogManager_Init(void *argument);
void Task_WatchdogManager_MainFunction(void *argument);
void Task_ErrorManager_Init(void *argument);
void Task_ErrorManager_MainFunction(void *argument);
void Task_SystemManager_Init(void *argument);
void Task_SystemManager_MainFunction(void *argument);
void Task_ModeManager_Init(void *argument);
void Task_ModeManager_MainFunction(void *argument);
void Task_Os_Start(void *argument);
void Task_Crc_Init(void *argument);
void Task_Crc_MainFunction(void *argument);
void Task_Rte_Init(void *argument);
void Task_Rte_MainFunction(void *argument);
void Task_Os_StartUpHook(void *argument);
void Task_Os_ShutdownHook(void *argument);
void Task_NvM_Init(void *argument);
void Task_NvM_MainFunction(void *argument);
void Task_MemIf_Status(void *argument);
void Task_Fee_Init(void *argument);
void Task_Fee_MainFunction(void *argument);
void Task_Ea_Init(void *argument);
void Task_Ea_MainFunction(void *argument);
void Task_VibSen_Init(void *argument);
void Task_VibSen_MainFunction(void *argument);
void Task_TemSen_Init(void *argument);
void Task_TemSen_MainFunction(void *argument);
void Task_SecAlm_Init(void *argument);
void Task_SecAlm_MainFunction(void *argument);
void Task_PDC_Init(void *argument);
void Task_PDC_MainFunction(void *argument);
void Task_LightSen_Init(void *argument);
void Task_LightSen_MainFunction(void *argument);
void Task_IoH_MainFunction(void *argument);
void Task_IntLights_Init(void *argument);
void Task_IntLights_MainFunction(void *argument);
void Task_HVAC_Init(void *argument);
void Task_HVAC_MainFunction(void *argument);
void Task_ExtLights_Init(void *argument);
void Task_ExtLights_MainFunction(void *argument);
void Task_DiagMonH_MainFunction(void *argument);
void Task_ComMon_MainFunction(void *argument);
void Task_CenLoc_Init(void *argument);
void Task_CenLoc_MainFunction(void *argument);
void Task_BTC_Init(void *argument);
void Task_BTC_MainFunction(void *argument);
void OsTimerCounter_Callback(void *argument);
void SystemManagerCounter_Callback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);
void vApplicationDaemonTaskStartupHook(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
return 0;
}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */
void vApplicationTickHook( void )
{
   /* This function will be called by each tick interrupt if
   configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
   added here, but the tick hook is called from an interrupt context, so
   code must not attempt to block, and only the interrupt safe FreeRTOS API
   functions can be used (those that end in FromISR()). */
}
/* USER CODE END 3 */

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
}
/* USER CODE END 5 */

/* USER CODE BEGIN DAEMON_TASK_STARTUP_HOOK */
void vApplicationDaemonTaskStartupHook(void)
{
}
/* USER CODE END DAEMON_TASK_STARTUP_HOOK */

/* USER CODE BEGIN PREPOSTSLEEP */
__weak void PreSleepProcessing(uint32_t ulExpectedIdleTime)
{
/* place for user code */
}

__weak void PostSleepProcessing(uint32_t ulExpectedIdleTime)
{
/* place for user code */
}
/* USER CODE END PREPOSTSLEEP */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of OsTimerCounter */
  OsTimerCounterHandle = osTimerNew(OsTimerCounter_Callback, osTimerPeriodic, NULL, &OsTimerCounter_attributes);

  /* creation of SystemManagerCounter */
  SystemManagerCounterHandle = osTimerNew(SystemManagerCounter_Callback, osTimerPeriodic, NULL, &SystemManagerCounter_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Os_Init */
  Os_InitHandle = osThreadNew(Task_Os_Init, NULL, &Os_Init_attributes);

  /* creation of EcuM_Init */
  EcuM_InitHandle = osThreadNew(Task_EcuM_Init, NULL, &EcuM_Init_attributes);

  /* creation of EcuM_MainFunction */
  EcuM_MainFunctionHandle = osThreadNew(Task_EcuMMainFunction, NULL, &EcuM_MainFunction_attributes);

  /* creation of BswM_Init */
  BswM_InitHandle = osThreadNew(Task_BswM_Init, NULL, &BswM_Init_attributes);

  /* creation of BswM_MainFunction */
  BswM_MainFunctionHandle = osThreadNew(Task_BswMMainFunction, NULL, &BswM_MainFunction_attributes);

  /* creation of WatchdogManager_Init */
  WatchdogManager_InitHandle = osThreadNew(Task_WatchdogManager_Init, NULL, &WatchdogManager_Init_attributes);

  /* creation of WatchdogManager_MainFunction */
  WatchdogManager_MainFunctionHandle = osThreadNew(Task_WatchdogManager_MainFunction, NULL, &WatchdogManager_MainFunction_attributes);

  /* creation of ErrorManager_Init */
  ErrorManager_InitHandle = osThreadNew(Task_ErrorManager_Init, NULL, &ErrorManager_Init_attributes);

  /* creation of ErrorManager_MainFunction */
  ErrorManager_MainFunctionHandle = osThreadNew(Task_ErrorManager_MainFunction, NULL, &ErrorManager_MainFunction_attributes);

  /* creation of SystemManager_Init */
  SystemManager_InitHandle = osThreadNew(Task_SystemManager_Init, NULL, &SystemManager_Init_attributes);

  /* creation of SystemManager_MainFunction */
  SystemManager_MainFunctionHandle = osThreadNew(Task_SystemManager_MainFunction, NULL, &SystemManager_MainFunction_attributes);

  /* creation of ModeManager_Init */
  ModeManager_InitHandle = osThreadNew(Task_ModeManager_Init, NULL, &ModeManager_Init_attributes);

  /* creation of ModeManager_MainFunction */
  ModeManager_MainFunctionHandle = osThreadNew(Task_ModeManager_MainFunction, NULL, &ModeManager_MainFunction_attributes);

  /* creation of Os_Start */
  Os_StartHandle = osThreadNew(Task_Os_Start, NULL, &Os_Start_attributes);

  /* creation of Crc_Init */
  Crc_InitHandle = osThreadNew(Task_Crc_Init, NULL, &Crc_Init_attributes);

  /* creation of Crc_MainFunction */
  Crc_MainFunctionHandle = osThreadNew(Task_Crc_MainFunction, NULL, &Crc_MainFunction_attributes);

  /* creation of Rte_Init */
  Rte_InitHandle = osThreadNew(Task_Rte_Init, NULL, &Rte_Init_attributes);

  /* creation of Rte_MainFunction */
  Rte_MainFunctionHandle = osThreadNew(Task_Rte_MainFunction, NULL, &Rte_MainFunction_attributes);

  /* creation of Os_StartUpHook */
  Os_StartUpHookHandle = osThreadNew(Task_Os_StartUpHook, NULL, &Os_StartUpHook_attributes);

  /* creation of Os_ShutdownHook */
  Os_ShutdownHookHandle = osThreadNew(Task_Os_ShutdownHook, NULL, &Os_ShutdownHook_attributes);

  /* creation of NvM_Init */
  NvM_InitHandle = osThreadNew(Task_NvM_Init, NULL, &NvM_Init_attributes);

  /* creation of NvM_MainFunction */
  NvM_MainFunctionHandle = osThreadNew(Task_NvM_MainFunction, NULL, &NvM_MainFunction_attributes);

  /* creation of MemIf_Status */
  MemIf_StatusHandle = osThreadNew(Task_MemIf_Status, NULL, &MemIf_Status_attributes);

  /* creation of Fee_Init */
  Fee_InitHandle = osThreadNew(Task_Fee_Init, NULL, &Fee_Init_attributes);

  /* creation of Fee_MainFunction */
  Fee_MainFunctionHandle = osThreadNew(Task_Fee_MainFunction, NULL, &Fee_MainFunction_attributes);

  /* creation of Ea_Init */
  Ea_InitHandle = osThreadNew(Task_Ea_Init, NULL, &Ea_Init_attributes);

  /* creation of Ea_MainFunction */
  Ea_MainFunctionHandle = osThreadNew(Task_Ea_MainFunction, NULL, &Ea_MainFunction_attributes);

  /* creation of VibSen_Init */
  VibSen_InitHandle = osThreadNew(Task_VibSen_Init, NULL, &VibSen_Init_attributes);

  /* creation of VibSen_MainFunction */
  VibSen_MainFunctionHandle = osThreadNew(Task_VibSen_MainFunction, NULL, &VibSen_MainFunction_attributes);

  /* creation of TemSen_Init */
  TemSen_InitHandle = osThreadNew(Task_TemSen_Init, NULL, &TemSen_Init_attributes);

  /* creation of TemSen_MainFunction */
  TemSen_MainFunctionHandle = osThreadNew(Task_TemSen_MainFunction, NULL, &TemSen_MainFunction_attributes);

  /* creation of SecAlm_Init */
  SecAlm_InitHandle = osThreadNew(Task_SecAlm_Init, NULL, &SecAlm_Init_attributes);

  /* creation of SecAlm_MainFunction */
  SecAlm_MainFunctionHandle = osThreadNew(Task_SecAlm_MainFunction, NULL, &SecAlm_MainFunction_attributes);

  /* creation of PDC_Init */
  PDC_InitHandle = osThreadNew(Task_PDC_Init, NULL, &PDC_Init_attributes);

  /* creation of PDC_MainFunction */
  PDC_MainFunctionHandle = osThreadNew(Task_PDC_MainFunction, NULL, &PDC_MainFunction_attributes);

  /* creation of LightSen_Init */
  LightSen_InitHandle = osThreadNew(Task_LightSen_Init, NULL, &LightSen_Init_attributes);

  /* creation of LightSen_MainFunction */
  LightSen_MainFunctionHandle = osThreadNew(Task_LightSen_MainFunction, NULL, &LightSen_MainFunction_attributes);

  /* creation of IoH_MainFunction */
  IoH_MainFunctionHandle = osThreadNew(Task_IoH_MainFunction, NULL, &IoH_MainFunction_attributes);

  /* creation of IntLights_Init */
  IntLights_InitHandle = osThreadNew(Task_IntLights_Init, NULL, &IntLights_Init_attributes);

  /* creation of IntLights_MainFunction */
  IntLights_MainFunctionHandle = osThreadNew(Task_IntLights_MainFunction, NULL, &IntLights_MainFunction_attributes);

  /* creation of HVAC_Init */
  HVAC_InitHandle = osThreadNew(Task_HVAC_Init, NULL, &HVAC_Init_attributes);

  /* creation of HVAC_MainFunction */
  HVAC_MainFunctionHandle = osThreadNew(Task_HVAC_MainFunction, NULL, &HVAC_MainFunction_attributes);

  /* creation of ExtLights_Init */
  ExtLights_InitHandle = osThreadNew(Task_ExtLights_Init, NULL, &ExtLights_Init_attributes);

  /* creation of ExtLights_MainFunction */
  ExtLights_MainFunctionHandle = osThreadNew(Task_ExtLights_MainFunction, NULL, &ExtLights_MainFunction_attributes);

  /* creation of DiagMonH_MainFunction */
  DiagMonH_MainFunctionHandle = osThreadNew(Task_DiagMonH_MainFunction, NULL, &DiagMonH_MainFunction_attributes);

  /* creation of ComMon_MainFunction */
  ComMon_MainFunctionHandle = osThreadNew(Task_ComMon_MainFunction, NULL, &ComMon_MainFunction_attributes);

  /* creation of CenLoc_Init */
  CenLoc_InitHandle = osThreadNew(Task_CenLoc_Init, NULL, &CenLoc_Init_attributes);

  /* creation of CenLoc_MainFunction */
  CenLoc_MainFunctionHandle = osThreadNew(Task_CenLoc_MainFunction, NULL, &CenLoc_MainFunction_attributes);

  /* creation of BTC_Init */
  BTC_InitHandle = osThreadNew(Task_BTC_Init, NULL, &BTC_Init_attributes);

  /* creation of BTC_MainFunction */
  BTC_MainFunctionHandle = osThreadNew(Task_BTC_MainFunction, NULL, &BTC_MainFunction_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Create the event(s) */
  /* creation of eventPOR */
  eventPORHandle = osEventFlagsNew(&eventPOR_attributes);

  /* creation of eventHWR */
  eventHWRHandle = osEventFlagsNew(&eventHWR_attributes);

  /* creation of eventSWR */
  eventSWRHandle = osEventFlagsNew(&eventSWR_attributes);

  /* creation of eventCoreReset */
  eventCoreResetHandle = osEventFlagsNew(&eventCoreReset_attributes);

  /* creation of eventMemManage */
  eventMemManageHandle = osEventFlagsNew(&eventMemManage_attributes);

  /* creation of eventNMI */
  eventNMIHandle = osEventFlagsNew(&eventNMI_attributes);

  /* creation of eventHardFault */
  eventHardFaultHandle = osEventFlagsNew(&eventHardFault_attributes);

  /* creation of eventBusFault */
  eventBusFaultHandle = osEventFlagsNew(&eventBusFault_attributes);

  /* creation of eventUsageFault */
  eventUsageFaultHandle = osEventFlagsNew(&eventUsageFault_attributes);

  /* creation of eventDebugMon */
  eventDebugMonHandle = osEventFlagsNew(&eventDebugMon_attributes);

  /* creation of eventPVD_IRQ */
  eventPVD_IRQHandle = osEventFlagsNew(&eventPVD_IRQ_attributes);

  /* creation of eventFlash_IRQ */
  eventFlash_IRQHandle = osEventFlagsNew(&eventFlash_IRQ_attributes);

  /* creation of eventRCC_IRQ */
  eventRCC_IRQHandle = osEventFlagsNew(&eventRCC_IRQ_attributes);

  /* creation of eventTIM1_IRQ */
  eventTIM1_IRQHandle = osEventFlagsNew(&eventTIM1_IRQ_attributes);

  /* creation of eventTIM10_IRQ */
  eventTIM10_IRQHandle = osEventFlagsNew(&eventTIM10_IRQ_attributes);

  /* creation of eventTIM2_IRQ */
  eventTIM2_IRQHandle = osEventFlagsNew(&eventTIM2_IRQ_attributes);

  /* creation of eventTIM3_IRQ */
  eventTIM3_IRQHandle = osEventFlagsNew(&eventTIM3_IRQ_attributes);

  /* creation of eventTIM4_IRQ */
  eventTIM4_IRQHandle = osEventFlagsNew(&eventTIM4_IRQ_attributes);

  /* creation of eventSPI2_IRQ */
  eventSPI2_IRQHandle = osEventFlagsNew(&eventSPI2_IRQ_attributes);

  /* creation of eventSPI3_IRQ */
  eventSPI3_IRQHandle = osEventFlagsNew(&eventSPI3_IRQ_attributes);

  /* creation of eventUSART1_IRQ */
  eventUSART1_IRQHandle = osEventFlagsNew(&eventUSART1_IRQ_attributes);

  /* creation of eventWDGR */
  eventWDGRHandle = osEventFlagsNew(&eventWDGR_attributes);

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Task_Os_Init */
/**
  * @brief  Function implementing the Os_Init thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Task_Os_Init */
void Task_Os_Init(void *argument)
{
  /* USER CODE BEGIN Task_Os_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Os_Init */
}

/* USER CODE BEGIN Header_Task_EcuM_Init */
/**
* @brief Function implementing the EcuM_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_EcuM_Init */
void Task_EcuM_Init(void *argument)
{
  /* USER CODE BEGIN Task_EcuM_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_EcuM_Init */
}

/* USER CODE BEGIN Header_Task_EcuMMainFunction */
/**
* @brief Function implementing the EcuM_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_EcuMMainFunction */
void Task_EcuMMainFunction(void *argument)
{
  /* USER CODE BEGIN Task_EcuMMainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_EcuMMainFunction */
}

/* USER CODE BEGIN Header_Task_BswM_Init */
/**
* @brief Function implementing the BswM_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_BswM_Init */
void Task_BswM_Init(void *argument)
{
  /* USER CODE BEGIN Task_BswM_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_BswM_Init */
}

/* USER CODE BEGIN Header_Task_BswMMainFunction */
/**
* @brief Function implementing the BswM_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_BswMMainFunction */
void Task_BswMMainFunction(void *argument)
{
  /* USER CODE BEGIN Task_BswMMainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_BswMMainFunction */
}

/* USER CODE BEGIN Header_Task_WatchdogManager_Init */
/**
* @brief Function implementing the WatchdogManager_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_WatchdogManager_Init */
void Task_WatchdogManager_Init(void *argument)
{
  /* USER CODE BEGIN Task_WatchdogManager_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_WatchdogManager_Init */
}

/* USER CODE BEGIN Header_Task_WatchdogManager_MainFunction */
/**
* @brief Function implementing the WatchdogManager_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_WatchdogManager_MainFunction */
void Task_WatchdogManager_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_WatchdogManager_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_WatchdogManager_MainFunction */
}

/* USER CODE BEGIN Header_Task_ErrorManager_Init */
/**
* @brief Function implementing the ErrorManager_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_ErrorManager_Init */
void Task_ErrorManager_Init(void *argument)
{
  /* USER CODE BEGIN Task_ErrorManager_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_ErrorManager_Init */
}

/* USER CODE BEGIN Header_Task_ErrorManager_MainFunction */
/**
* @brief Function implementing the ErrorManager_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_ErrorManager_MainFunction */
void Task_ErrorManager_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_ErrorManager_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_ErrorManager_MainFunction */
}

/* USER CODE BEGIN Header_Task_SystemManager_Init */
/**
* @brief Function implementing the SystemManager_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_SystemManager_Init */
void Task_SystemManager_Init(void *argument)
{
  /* USER CODE BEGIN Task_SystemManager_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_SystemManager_Init */
}

/* USER CODE BEGIN Header_Task_SystemManager_MainFunction */
/**
* @brief Function implementing the SystemManager_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_SystemManager_MainFunction */
void Task_SystemManager_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_SystemManager_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_SystemManager_MainFunction */
}

/* USER CODE BEGIN Header_Task_ModeManager_Init */
/**
* @brief Function implementing the ModeManager_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_ModeManager_Init */
void Task_ModeManager_Init(void *argument)
{
  /* USER CODE BEGIN Task_ModeManager_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_ModeManager_Init */
}

/* USER CODE BEGIN Header_Task_ModeManager_MainFunction */
/**
* @brief Function implementing the ModeManager_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_ModeManager_MainFunction */
void Task_ModeManager_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_ModeManager_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_ModeManager_MainFunction */
}

/* USER CODE BEGIN Header_Task_Os_Start */
/**
* @brief Function implementing the Os_Start thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Os_Start */
void Task_Os_Start(void *argument)
{
  /* USER CODE BEGIN Task_Os_Start */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Os_Start */
}

/* USER CODE BEGIN Header_Task_Crc_Init */
/**
* @brief Function implementing the Crc_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Crc_Init */
void Task_Crc_Init(void *argument)
{
  /* USER CODE BEGIN Task_Crc_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Crc_Init */
}

/* USER CODE BEGIN Header_Task_Crc_MainFunction */
/**
* @brief Function implementing the Crc_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Crc_MainFunction */
void Task_Crc_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_Crc_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Crc_MainFunction */
}

/* USER CODE BEGIN Header_Task_Rte_Init */
/**
* @brief Function implementing the Rte_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Rte_Init */
void Task_Rte_Init(void *argument)
{
  /* USER CODE BEGIN Task_Rte_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Rte_Init */
}

/* USER CODE BEGIN Header_Task_Rte_MainFunction */
/**
* @brief Function implementing the Rte_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Rte_MainFunction */
void Task_Rte_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_Rte_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Rte_MainFunction */
}

/* USER CODE BEGIN Header_Task_Os_StartUpHook */
/**
* @brief Function implementing the Os_StartUpHook thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Os_StartUpHook */
void Task_Os_StartUpHook(void *argument)
{
  /* USER CODE BEGIN Task_Os_StartUpHook */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Os_StartUpHook */
}

/* USER CODE BEGIN Header_Task_Os_ShutdownHook */
/**
* @brief Function implementing the Os_ShutdownHook thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Os_ShutdownHook */
void Task_Os_ShutdownHook(void *argument)
{
  /* USER CODE BEGIN Task_Os_ShutdownHook */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Os_ShutdownHook */
}

/* USER CODE BEGIN Header_Task_NvM_Init */
/**
* @brief Function implementing the NvM_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_NvM_Init */
void Task_NvM_Init(void *argument)
{
  /* USER CODE BEGIN Task_NvM_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_NvM_Init */
}

/* USER CODE BEGIN Header_Task_NvM_MainFunction */
/**
* @brief Function implementing the NvM_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_NvM_MainFunction */
void Task_NvM_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_NvM_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_NvM_MainFunction */
}

/* USER CODE BEGIN Header_Task_MemIf_Status */
/**
* @brief Function implementing the MemIf_Status thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_MemIf_Status */
void Task_MemIf_Status(void *argument)
{
  /* USER CODE BEGIN Task_MemIf_Status */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_MemIf_Status */
}

/* USER CODE BEGIN Header_Task_Fee_Init */
/**
* @brief Function implementing the Fee_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Fee_Init */
void Task_Fee_Init(void *argument)
{
  /* USER CODE BEGIN Task_Fee_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Fee_Init */
}

/* USER CODE BEGIN Header_Task_Fee_MainFunction */
/**
* @brief Function implementing the Fee_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Fee_MainFunction */
void Task_Fee_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_Fee_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Fee_MainFunction */
}

/* USER CODE BEGIN Header_Task_Ea_Init */
/**
* @brief Function implementing the Ea_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Ea_Init */
void Task_Ea_Init(void *argument)
{
  /* USER CODE BEGIN Task_Ea_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Ea_Init */
}

/* USER CODE BEGIN Header_Task_Ea_MainFunction */
/**
* @brief Function implementing the Ea_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Ea_MainFunction */
void Task_Ea_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_Ea_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Ea_MainFunction */
}

/* USER CODE BEGIN Header_Task_VibSen_Init */
/**
* @brief Function implementing the VibSen_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_VibSen_Init */
void Task_VibSen_Init(void *argument)
{
  /* USER CODE BEGIN Task_VibSen_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_VibSen_Init */
}

/* USER CODE BEGIN Header_Task_VibSen_MainFunction */
/**
* @brief Function implementing the VibSen_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_VibSen_MainFunction */
void Task_VibSen_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_VibSen_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_VibSen_MainFunction */
}

/* USER CODE BEGIN Header_Task_TemSen_Init */
/**
* @brief Function implementing the TemSen_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_TemSen_Init */
void Task_TemSen_Init(void *argument)
{
  /* USER CODE BEGIN Task_TemSen_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_TemSen_Init */
}

/* USER CODE BEGIN Header_Task_TemSen_MainFunction */
/**
* @brief Function implementing the TemSen_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_TemSen_MainFunction */
void Task_TemSen_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_TemSen_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_TemSen_MainFunction */
}

/* USER CODE BEGIN Header_Task_SecAlm_Init */
/**
* @brief Function implementing the SecAlm_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_SecAlm_Init */
void Task_SecAlm_Init(void *argument)
{
  /* USER CODE BEGIN Task_SecAlm_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_SecAlm_Init */
}

/* USER CODE BEGIN Header_Task_SecAlm_MainFunction */
/**
* @brief Function implementing the SecAlm_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_SecAlm_MainFunction */
void Task_SecAlm_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_SecAlm_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_SecAlm_MainFunction */
}

/* USER CODE BEGIN Header_Task_PDC_Init */
/**
* @brief Function implementing the PDC_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_PDC_Init */
void Task_PDC_Init(void *argument)
{
  /* USER CODE BEGIN Task_PDC_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_PDC_Init */
}

/* USER CODE BEGIN Header_Task_PDC_MainFunction */
/**
* @brief Function implementing the PDC_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_PDC_MainFunction */
void Task_PDC_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_PDC_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_PDC_MainFunction */
}

/* USER CODE BEGIN Header_Task_LightSen_Init */
/**
* @brief Function implementing the LightSen_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_LightSen_Init */
void Task_LightSen_Init(void *argument)
{
  /* USER CODE BEGIN Task_LightSen_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_LightSen_Init */
}

/* USER CODE BEGIN Header_Task_LightSen_MainFunction */
/**
* @brief Function implementing the LightSen_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_LightSen_MainFunction */
void Task_LightSen_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_LightSen_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_LightSen_MainFunction */
}

/* USER CODE BEGIN Header_Task_IoH_MainFunction */
/**
* @brief Function implementing the IoH_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_IoH_MainFunction */
void Task_IoH_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_IoH_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_IoH_MainFunction */
}

/* USER CODE BEGIN Header_Task_IntLights_Init */
/**
* @brief Function implementing the IntLights_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_IntLights_Init */
void Task_IntLights_Init(void *argument)
{
  /* USER CODE BEGIN Task_IntLights_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_IntLights_Init */
}

/* USER CODE BEGIN Header_Task_IntLights_MainFunction */
/**
* @brief Function implementing the IntLights_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_IntLights_MainFunction */
void Task_IntLights_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_IntLights_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_IntLights_MainFunction */
}

/* USER CODE BEGIN Header_Task_HVAC_Init */
/**
* @brief Function implementing the HVAC_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_HVAC_Init */
void Task_HVAC_Init(void *argument)
{
  /* USER CODE BEGIN Task_HVAC_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_HVAC_Init */
}

/* USER CODE BEGIN Header_Task_HVAC_MainFunction */
/**
* @brief Function implementing the HVAC_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_HVAC_MainFunction */
void Task_HVAC_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_HVAC_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_HVAC_MainFunction */
}

/* USER CODE BEGIN Header_Task_ExtLights_Init */
/**
* @brief Function implementing the ExtLights_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_ExtLights_Init */
void Task_ExtLights_Init(void *argument)
{
  /* USER CODE BEGIN Task_ExtLights_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_ExtLights_Init */
}

/* USER CODE BEGIN Header_Task_ExtLights_MainFunction */
/**
* @brief Function implementing the ExtLights_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_ExtLights_MainFunction */
void Task_ExtLights_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_ExtLights_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_ExtLights_MainFunction */
}

/* USER CODE BEGIN Header_Task_DiagMonH_MainFunction */
/**
* @brief Function implementing the DiagMonH_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_DiagMonH_MainFunction */
void Task_DiagMonH_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_DiagMonH_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_DiagMonH_MainFunction */
}

/* USER CODE BEGIN Header_Task_ComMon_MainFunction */
/**
* @brief Function implementing the ComMon_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_ComMon_MainFunction */
void Task_ComMon_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_ComMon_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_ComMon_MainFunction */
}

/* USER CODE BEGIN Header_Task_CenLoc_Init */
/**
* @brief Function implementing the CenLoc_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_CenLoc_Init */
void Task_CenLoc_Init(void *argument)
{
  /* USER CODE BEGIN Task_CenLoc_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_CenLoc_Init */
}

/* USER CODE BEGIN Header_Task_CenLoc_MainFunction */
/**
* @brief Function implementing the CenLoc_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_CenLoc_MainFunction */
void Task_CenLoc_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_CenLoc_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_CenLoc_MainFunction */
}

/* USER CODE BEGIN Header_Task_BTC_Init */
/**
* @brief Function implementing the BTC_Init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_BTC_Init */
void Task_BTC_Init(void *argument)
{
  /* USER CODE BEGIN Task_BTC_Init */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_BTC_Init */
}

/* USER CODE BEGIN Header_Task_BTC_MainFunction */
/**
* @brief Function implementing the BTC_MainFunction thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_BTC_MainFunction */
void Task_BTC_MainFunction(void *argument)
{
  /* USER CODE BEGIN Task_BTC_MainFunction */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_BTC_MainFunction */
}

/* OsTimerCounter_Callback function */
void OsTimerCounter_Callback(void *argument)
{
  /* USER CODE BEGIN OsTimerCounter_Callback */

  /* USER CODE END OsTimerCounter_Callback */
}

/* SystemManagerCounter_Callback function */
void SystemManagerCounter_Callback(void *argument)
{
  /* USER CODE BEGIN SystemManagerCounter_Callback */

  /* USER CODE END SystemManagerCounter_Callback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

