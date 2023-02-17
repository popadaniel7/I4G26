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

#include "Mcp2515.h"
#include "CanSpi.h"
#include "CenLoc.h"
#include "ExtLights.h"
#include "IntLights.h"
#include "SecAlm.h"
#include "BTC.h"
#include "Std_Types.h"
#include "Project_Definitions.h"
#include "timers.h"

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

uint32 OS_Counter;

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime7,
};
/* Definitions for myTask02 */
osThreadId_t myTask02Handle;
const osThreadAttr_t myTask02_attributes = {
  .name = "myTask02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for PdcFrontDelayTimer */
osTimerId_t PdcFrontDelayTimerHandle;
const osTimerAttr_t PdcFrontDelayTimer_attributes = {
  .name = "PdcFrontDelayTimer"
};
/* Definitions for PdcSecondFrontDelayTimer */
osTimerId_t PdcSecondFrontDelayTimerHandle;
const osTimerAttr_t PdcSecondFrontDelayTimer_attributes = {
  .name = "PdcSecondFrontDelayTimer"
};
/* Definitions for PdcFrontGlobalTimer */
osTimerId_t PdcFrontGlobalTimerHandle;
const osTimerAttr_t PdcFrontGlobalTimer_attributes = {
  .name = "PdcFrontGlobalTimer"
};
/* Definitions for PdcRearGlobalTimer */
osTimerId_t PdcRearGlobalTimerHandle;
const osTimerAttr_t PdcRearGlobalTimer_attributes = {
  .name = "PdcRearGlobalTimer"
};
/* Definitions for PdcRearDelayTimer */
osTimerId_t PdcRearDelayTimerHandle;
const osTimerAttr_t PdcRearDelayTimer_attributes = {
  .name = "PdcRearDelayTimer"
};
/* Definitions for PdcSecondRearDelayTimer */
osTimerId_t PdcSecondRearDelayTimerHandle;
const osTimerAttr_t PdcSecondRearDelayTimer_attributes = {
  .name = "PdcSecondRearDelayTimer"
};
/* Definitions for RLTSHL */
osTimerId_t RLTSHLHandle;
const osTimerAttr_t RLTSHL_attributes = {
  .name = "RLTSHL"
};
/* Definitions for AlarmReset */
osTimerId_t AlarmResetHandle;
const osTimerAttr_t AlarmReset_attributes = {
  .name = "AlarmReset"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartTask02(void *argument);
void PdcFrontDelayCallback(void *argument);
void PdcSecondFrontDelayCallback(void *argument);
void PdcFrontGlobalTimerCallback(void *argument);
void PdcRearGlobalCallback(void *argument);
void PdcRearDelayCallback(void *argument);
void PdcSecondRearDelayCallback(void *argument);
void RLTSHLCallback(void *argument);
void AlarmReset_Callback(void *argument);

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
  /* creation of PdcFrontDelayTimer */
  PdcFrontDelayTimerHandle = osTimerNew(PdcFrontDelayCallback, osTimerPeriodic, NULL, &PdcFrontDelayTimer_attributes);

  /* creation of PdcSecondFrontDelayTimer */
  PdcSecondFrontDelayTimerHandle = osTimerNew(PdcSecondFrontDelayCallback, osTimerPeriodic, NULL, &PdcSecondFrontDelayTimer_attributes);

  /* creation of PdcFrontGlobalTimer */
  PdcFrontGlobalTimerHandle = osTimerNew(PdcFrontGlobalTimerCallback, osTimerPeriodic, NULL, &PdcFrontGlobalTimer_attributes);

  /* creation of PdcRearGlobalTimer */
  PdcRearGlobalTimerHandle = osTimerNew(PdcRearGlobalCallback, osTimerPeriodic, NULL, &PdcRearGlobalTimer_attributes);

  /* creation of PdcRearDelayTimer */
  PdcRearDelayTimerHandle = osTimerNew(PdcRearDelayCallback, osTimerPeriodic, NULL, &PdcRearDelayTimer_attributes);

  /* creation of PdcSecondRearDelayTimer */
  PdcSecondRearDelayTimerHandle = osTimerNew(PdcSecondRearDelayCallback, osTimerPeriodic, NULL, &PdcSecondRearDelayTimer_attributes);

  /* creation of RLTSHL */
  RLTSHLHandle = osTimerNew(RLTSHLCallback, osTimerPeriodic, NULL, &RLTSHL_attributes);

  /* creation of AlarmReset */
  AlarmResetHandle = osTimerNew(AlarmReset_Callback, osTimerPeriodic, NULL, &AlarmReset_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */

  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of myTask02 */
  myTask02Handle = osThreadNew(StartTask02, NULL, &myTask02_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */

  for(;;)
  {

		BtcMainFunction();
		CenLocMainFunction();
		ExtLightsMainFunction();
		IntLightsMainFunction();
		SecAlmMainFunction();
		 MCP2515_Initialize();
		 MCP2515_SetConfigMode();
		 MCP2515_SetNormalMode();
		 MCP2515_Reset();
		 MCP2515_ReadByte (0);
		 MCP2515_ReadRxSequence(0,0,0);
		 MCP2515_WriteByte(0, 0);
		 MCP2515_WriteByteSequence(0,0,0);
		 MCP2515_LoadTxSequence(0,0,0,0);
		 MCP2515_LoadTxBuffer(0,0);
		 MCP2515_RequestToSend(0);
		 MCP2515_ReadStatus();
		 MCP2515_GetRxStatus();
		 MCP2515_BitModify(0,0,0);
		osDelay(1);

  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  for(;;)
  {
//	  lcd_init();
//	  lcd_clear();
	  OS_Counter++;
	  osDelay(1);
  }
  /* USER CODE END StartTask02 */
}

/* PdcFrontDelayCallback function */
void PdcFrontDelayCallback(void *argument)
{
  /* USER CODE BEGIN PdcFrontDelayCallback */

  /* USER CODE END PdcFrontDelayCallback */
}

/* PdcSecondFrontDelayCallback function */
void PdcSecondFrontDelayCallback(void *argument)
{
  /* USER CODE BEGIN PdcSecondFrontDelayCallback */

  /* USER CODE END PdcSecondFrontDelayCallback */
}

/* PdcFrontGlobalTimerCallback function */
void PdcFrontGlobalTimerCallback(void *argument)
{
  /* USER CODE BEGIN PdcFrontGlobalTimerCallback */

  /* USER CODE END PdcFrontGlobalTimerCallback */
}

/* PdcRearGlobalCallback function */
void PdcRearGlobalCallback(void *argument)
{
  /* USER CODE BEGIN PdcRearGlobalCallback */

  /* USER CODE END PdcRearGlobalCallback */
}

/* PdcRearDelayCallback function */
void PdcRearDelayCallback(void *argument)
{
  /* USER CODE BEGIN PdcRearDelayCallback */

  /* USER CODE END PdcRearDelayCallback */
}

/* PdcSecondRearDelayCallback function */
void PdcSecondRearDelayCallback(void *argument)
{
  /* USER CODE BEGIN PdcSecondRearDelayCallback */

  /* USER CODE END PdcSecondRearDelayCallback */
}

/* RLTSHLCallback function */
void RLTSHLCallback(void *argument)
{
  /* USER CODE BEGIN RLTSHLCallback */



  /* USER CODE END RLTSHLCallback */
}

/* AlarmReset_Callback function */
void AlarmReset_Callback(void *argument)
{
  /* USER CODE BEGIN AlarmReset_Callback */

	SecAlm_SensorStatusCounter = STD_LOW;

  /* USER CODE END AlarmReset_Callback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/* USER CODE END Application */

