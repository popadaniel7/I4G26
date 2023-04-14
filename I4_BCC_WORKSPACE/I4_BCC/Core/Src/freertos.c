/* USER CODE BEGIN Header */
/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Real Time Operating System     *
******************************************/
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
#include "timers.h"
#include "Rte.h"
#include "WatchdogManager.h"
#include "AdcH.h"
#include "CrcH.h"
#include "dma.h"
#include "TimH.h"
#include "UartH.h"
#include "PortH.h"
#include "SystemManager.h"
#include "EcuM.h"
#include "Pdc.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
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
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Os counter variable used for software runtime check. */
unsigned long Os_Counter;
/* Os counter variable for lock unlock sequence. */
uint8 Os_LockUnlockSequence_Counter;
/* Os counter variable for alarm led. */
uint8 Os_TurnOnCyclic_Counter;
/* Os counter variable for alarm led. */
uint8 Os_TurnOnLed_Counter;
/* Os counter variable for follow me home. */
uint8 Os_FollowMeHome_Counter;
/* Os counter variable for turn signal. */
uint32 Os_Lts_Counter;
/* Os counter variable for turn signal. */
uint32 Os_Rts_Counter;
/* Os counter variable for turn signal. */
uint32 Os_HL_Counter;
/* Os counter variable for alarm sequence. */
uint8 Os_Alarm_Counter;
/* Os counter variable for rear pdc counter. */
uint8 Os_Pdc_Rear_Counter;
/* Os counter variable for front pdc counter. */
uint8 Os_Pdc_Front_Counter;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/* USER CODE END Variables */
/* Definitions for OS_Init */
osThreadId_t OS_InitHandle;
const osThreadAttr_t OS_Init_attributes = {
  .name = "OS_Init",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityRealtime6,
};
/* Definitions for OS_Run */
osThreadId_t OS_RunHandle;
const osThreadAttr_t OS_Run_attributes = {
  .name = "OS_Run",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for ASIL_APPL_Task */
osThreadId_t ASIL_APPL_TaskHandle;
const osThreadAttr_t ASIL_APPL_Task_attributes = {
  .name = "ASIL_APPL_Task",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityHigh7,
};
/* Definitions for QM_APPL_Task */
osThreadId_t QM_APPL_TaskHandle;
const osThreadAttr_t QM_APPL_Task_attributes = {
  .name = "QM_APPL_Task",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Os_SecAlm_AlarmReset */
osTimerId_t Os_SecAlm_AlarmResetHandle;
const osTimerAttr_t Os_SecAlm_AlarmReset_attributes = {
  .name = "Os_SecAlm_AlarmReset"
};
/* Definitions for Os_CenLoc_LockUnlockSequence_Timer */
osTimerId_t Os_CenLoc_LockUnlockSequence_TimerHandle;
const osTimerAttr_t Os_CenLoc_LockUnlockSequence_Timer_attributes = {
  .name = "Os_CenLoc_LockUnlockSequence_Timer"
};
/* Definitions for Os_SecAlmLed_TurnOnCyclic_Timer */
osTimerId_t Os_SecAlmLed_TurnOnCyclic_TimerHandle;
const osTimerAttr_t Os_SecAlmLed_TurnOnCyclic_Timer_attributes = {
  .name = "Os_SecAlmLed_TurnOnCyclic_Timer"
};
/* Definitions for Os_SecAlmLedTurnOn_Timer */
osTimerId_t Os_SecAlmLedTurnOn_TimerHandle;
const osTimerAttr_t Os_SecAlmLedTurnOn_Timer_attributes = {
  .name = "Os_SecAlmLedTurnOn_Timer"
};
/* Definitions for Os_FollowMeHome_Timer */
osTimerId_t Os_FollowMeHome_TimerHandle;
const osTimerAttr_t Os_FollowMeHome_Timer_attributes = {
  .name = "Os_FollowMeHome_Timer"
};
/* Definitions for Os_TurnSignals_Timer */
osTimerId_t Os_TurnSignals_TimerHandle;
const osTimerAttr_t Os_TurnSignals_Timer_attributes = {
  .name = "Os_TurnSignals_Timer"
};
/* Definitions for Os_SecAlmAlarm_Timer */
osTimerId_t Os_SecAlmAlarm_TimerHandle;
const osTimerAttr_t Os_SecAlmAlarm_Timer_attributes = {
  .name = "Os_SecAlmAlarm_Timer"
};
/* Definitions for Os_PdcR_Buzzer_Timer */
osTimerId_t Os_PdcR_Buzzer_TimerHandle;
const osTimerAttr_t Os_PdcR_Buzzer_Timer_attributes = {
  .name = "Os_PdcR_Buzzer_Timer"
};
/* Definitions for Os_PdcF_Buzzer_Timer */
osTimerId_t Os_PdcF_Buzzer_TimerHandle;
const osTimerAttr_t Os_PdcF_Buzzer_Timer_attributes = {
  .name = "Os_PdcF_Buzzer_Timer"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
/* USER CODE END FunctionPrototypes */

void OS_TASK_OS_INIT(void *argument);
void OS_TASK_OS_RUN(void *argument);
void OS_TASK_ASIL_APPL_Task(void *argument);
void OS_TASK_QM_APPL_Task(void *argument);
void Os_SecAlm_AlarmReset_Callback(void *argument);
void Os_CenLoc_LockUnlockSequence_Timer_Callback(void *argument);
void Os_SecAlmLed_TurnOnCyclic_Timer_Callback(void *argument);
void Os_SecAlmLedTurnOn_Timer_Callback(void *argument);
void Os_FollowMeHome_Timer_Callback(void *argument);
void Os_TurnSignals_Timer_Callback(void *argument);
void Os_SecAlmAlarm_Timer_Callback(void *argument);
void Os_PdcR_Buzzer_Timer_Callback(void *argument);
void Os_PdcF_Buzzer_Timer_Callback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */
void vApplicationTickHook( void )
{
	/* Increment the OS counter at each OS tick (1 ms). */
	Os_Counter++;
}
/* USER CODE END 3 */

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
	/* In case of stack overflow, set fault and perform reset of the system. */
	SystemManager_SetFault(STACK_OVERFLOW_RESET);
	SystemManager_PerformReset();
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
void vApplicationMallocFailedHook(void)
{
	/* In case of malloc failed, set fault and perform reset of the system. */
	SystemManager_SetFault(MALLOC_FAILED_RESET);
	SystemManager_PerformReset();
}
/* USER CODE END 5 */

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
  /* creation of Os_SecAlm_AlarmReset */
  Os_SecAlm_AlarmResetHandle = osTimerNew(Os_SecAlm_AlarmReset_Callback, osTimerPeriodic, NULL, &Os_SecAlm_AlarmReset_attributes);

  /* creation of Os_CenLoc_LockUnlockSequence_Timer */
  Os_CenLoc_LockUnlockSequence_TimerHandle = osTimerNew(Os_CenLoc_LockUnlockSequence_Timer_Callback, osTimerPeriodic, NULL, &Os_CenLoc_LockUnlockSequence_Timer_attributes);

  /* creation of Os_SecAlmLed_TurnOnCyclic_Timer */
  Os_SecAlmLed_TurnOnCyclic_TimerHandle = osTimerNew(Os_SecAlmLed_TurnOnCyclic_Timer_Callback, osTimerPeriodic, NULL, &Os_SecAlmLed_TurnOnCyclic_Timer_attributes);

  /* creation of Os_SecAlmLedTurnOn_Timer */
  Os_SecAlmLedTurnOn_TimerHandle = osTimerNew(Os_SecAlmLedTurnOn_Timer_Callback, osTimerPeriodic, NULL, &Os_SecAlmLedTurnOn_Timer_attributes);

  /* creation of Os_FollowMeHome_Timer */
  Os_FollowMeHome_TimerHandle = osTimerNew(Os_FollowMeHome_Timer_Callback, osTimerPeriodic, NULL, &Os_FollowMeHome_Timer_attributes);

  /* creation of Os_TurnSignals_Timer */
  Os_TurnSignals_TimerHandle = osTimerNew(Os_TurnSignals_Timer_Callback, osTimerPeriodic, NULL, &Os_TurnSignals_Timer_attributes);

  /* creation of Os_SecAlmAlarm_Timer */
  Os_SecAlmAlarm_TimerHandle = osTimerNew(Os_SecAlmAlarm_Timer_Callback, osTimerPeriodic, NULL, &Os_SecAlmAlarm_Timer_attributes);

  /* creation of Os_PdcR_Buzzer_Timer */
  Os_PdcR_Buzzer_TimerHandle = osTimerNew(Os_PdcR_Buzzer_Timer_Callback, osTimerPeriodic, NULL, &Os_PdcR_Buzzer_Timer_attributes);

  /* creation of Os_PdcF_Buzzer_Timer */
  Os_PdcF_Buzzer_TimerHandle = osTimerNew(Os_PdcF_Buzzer_Timer_Callback, osTimerPeriodic, NULL, &Os_PdcF_Buzzer_Timer_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of OS_Init */
  OS_InitHandle = osThreadNew(OS_TASK_OS_INIT, NULL, &OS_Init_attributes);

  /* creation of OS_Run */
  OS_RunHandle = osThreadNew(OS_TASK_OS_RUN, NULL, &OS_Run_attributes);

  /* creation of ASIL_APPL_Task */
  ASIL_APPL_TaskHandle = osThreadNew(OS_TASK_ASIL_APPL_Task, NULL, &ASIL_APPL_Task_attributes);

  /* creation of QM_APPL_Task */
  QM_APPL_TaskHandle = osThreadNew(OS_TASK_QM_APPL_Task, NULL, &QM_APPL_Task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_OS_TASK_OS_INIT */
/**
  * @brief  OS task used for initialization at start-up.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_OS_TASK_OS_INIT */
void OS_TASK_OS_INIT(void *argument)
{
  /* USER CODE BEGIN OS_TASK_OS_INIT */
	for(;;)
	{
		/* Perform driver initialization. */
		EcuM_DriverInit();
		/* Suspend the task to only execute once at start-up. */
		vTaskSuspend(NULL);
	}
  /* USER CODE END OS_TASK_OS_INIT */
}

/* USER CODE BEGIN Header_OS_TASK_OS_RUN */
/**
* @brief OS Task used for runtime to do cyclic activity outside ASIL or QM Rte runnables.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_OS_TASK_OS_RUN */
void OS_TASK_OS_RUN(void *argument)
{
  /* USER CODE BEGIN OS_TASK_OS_RUN */
	for(;;)
	{
		/* Refresh the windowed watchdog counter. */
		Rte_Runnable_Wdg_MainFunction();
	}
  /* USER CODE END OS_TASK_OS_RUN */
}

/* USER CODE BEGIN Header_OS_TASK_ASIL_APPL_Task */
/**
* @brief OS Task used to do cyclic activity in ASIL context.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_OS_TASK_ASIL_APPL_Task */
void OS_TASK_ASIL_APPL_Task(void *argument)
{
  /* USER CODE BEGIN OS_TASK_ASIL_APPL_Task */
	for(;;)
	{
		Rte_Runnable_EcuM_MainFunction();
		Rte_Runnable_SystemManager_MainFunction();
		Rte_Runnable_Can_MainFunction();
		Rte_Runnable_I2c_MainFunction();
		Rte_Runnable_NvM_MainFunction();
		Rte_Runnable_Uart_MainFunction();
		Rte_Runnable_Crc_MainFunction();
		Rte_Runnable_Btc_MainFunction();
		Rte_Runnable_Adc_MainFunction();
		Rte_Runnable_Tim_MainFunction();
		Rte_Runnable_ExtLights_MainFunction();
		Rte_Runnable_Pdc_MainFunction();
		Rte_Runnable_SecAlm_MainFunction();
		osDelay(1);
	}
  /* USER CODE END OS_TASK_ASIL_APPL_Task */
}

/* USER CODE BEGIN Header_OS_TASK_QM_APPL_Task */
/**
* @brief OS Task used to do cyclic activity in QM context.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_OS_TASK_QM_APPL_Task */
void OS_TASK_QM_APPL_Task(void *argument)
{
  /* USER CODE BEGIN OS_TASK_QM_APPL_Task */
	for(;;)
	{
		Rte_Runnable_Dem_MainFunction();
		Rte_Runnable_DiagCtrl_MainFunction();
		Rte_Runnable_SenCtrl_MainFunction();
		Rte_Runnable_CenLoc_MainFunction();
		Rte_Runnable_IntLights_MainFunction();
		Rte_Runnable_Hvac_MainFunction();
		osDelay(1);
	}
  /* USER CODE END OS_TASK_QM_APPL_Task */
}

/* Os_SecAlm_AlarmReset_Callback function */
void Os_SecAlm_AlarmReset_Callback(void *argument)
{
  /* USER CODE BEGIN Os_SecAlm_AlarmReset_Callback */
	/* Reset the security alarm counter trigger. */
	Rte_Write_SecAlm_SecAlmPort_SecAlm_SensorStatusCounter((uint16*)0);
  /* USER CODE END Os_SecAlm_AlarmReset_Callback */
}

/* Os_CenLoc_LockUnlockSequence_Timer_Callback function */
void Os_CenLoc_LockUnlockSequence_Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Os_CenLoc_LockUnlockSequence_Timer_Callback */
	/* If the counter variable for the lock unlock turn signals sequence is less than or equal to 6
	 * Then if there is either a lock or an unlock sequence increase the counter to process the states
	 * in the application. */
	if(Os_LockUnlockSequence_Counter <= 6
		&& ((Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_LOW && Rte_P_CenLoc_CenLocPort_CenLoc_PreviousStateFlag == STD_HIGH)
		|| (Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState == STD_HIGH && Rte_P_CenLoc_CenLocPort_CenLoc_PreviousStateFlag == STD_LOW)))
	{
		Os_LockUnlockSequence_Counter = Os_LockUnlockSequence_Counter + 1;
		Rte_Write_CenLoc_CenLocPort_CenLoc_BlinkCounter(&Os_LockUnlockSequence_Counter);
	}
	else
	{
		/* Update the counter with out of bounds value to prevent unexpected triggering. */
		Os_LockUnlockSequence_Counter = 7;
		Rte_Write_CenLoc_CenLocPort_CenLoc_BlinkCounter(&Os_LockUnlockSequence_Counter);
	}

  /* USER CODE END Os_CenLoc_LockUnlockSequence_Timer_Callback */
}

/* Os_SecAlmLed_TurnOnCyclic_Timer_Callback function */
void Os_SecAlmLed_TurnOnCyclic_Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Os_SecAlmLed_TurnOnCyclic_Timer_Callback */
	/* Increase the counter variable used in the timer for the alarm LED
	 * that expires every 3,75 seconds. */
	Os_TurnOnCyclic_Counter = Os_TurnOnCyclic_Counter + 1;
	Rte_Write_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter(&Os_TurnOnCyclic_Counter);
  /* USER CODE END Os_SecAlmLed_TurnOnCyclic_Timer_Callback */
}

/* Os_SecAlmLedTurnOn_Timer_Callback function */
void Os_SecAlmLedTurnOn_Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Os_SecAlmLedTurnOn_Timer_Callback */
	/* Increase the counter variable used in the turning on the alarm LED for 0,25 seconds. */
	Os_TurnOnLed_Counter = Os_TurnOnLed_Counter + 1;
	Rte_Write_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter(&Os_TurnOnLed_Counter);
  /* USER CODE END Os_SecAlmLedTurnOn_Timer_Callback */
}

/* Os_FollowMeHome_Timer_Callback function */
void Os_FollowMeHome_Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Os_FollowMeHome_Timer_Callback */
	/* Increase the counter variable used in the follow me home concept when the timer
	 * period expires for the lights to go off. */
	Os_FollowMeHome_Counter = Os_FollowMeHome_Counter + 1;
	Rte_Write_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter(&Os_FollowMeHome_Counter);
  /* USER CODE END Os_FollowMeHome_Timer_Callback */
}

/* Os_TurnSignals_Timer_Callback function */
void Os_TurnSignals_Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Os_TurnSignals_Timer_Callback */
	/* Increase the respective counter on request from the specific light in turn signals. */
	if(Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState == STD_HIGH)
	{
		Os_Lts_Counter = Os_Lts_Counter + 1;
		Rte_Write_ExtLights_ExtLightsPort_ExtLights_LTSFlag(&Os_Lts_Counter);
	}
	else
	{
		/* do nothing */
	}

	if(Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState == STD_HIGH)
	{
		Os_Rts_Counter = Os_Rts_Counter + 1;
		Rte_Write_ExtLights_ExtLightsPort_ExtLights_RTSFlag(&Os_Rts_Counter);
	}
	else
	{
		/* do nothing */
	}

	if(Rte_P_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState == STD_HIGH)
	{
		Os_HL_Counter = Os_HL_Counter + 1;
		Rte_Write_ExtLights_ExtLightsPort_ExtLights_HLFlag(&Os_HL_Counter);
	}
	else
	{
		/* do nothing */
	}
  /* USER CODE END Os_TurnSignals_Timer_Callback */
}

/* Os_SecAlmAlarm_Timer_Callback function */
void Os_SecAlmAlarm_Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Os_SecAlmAlarm_Timer_Callback */
	/* Increase the security alarm trigger counter when the alarm is on. */
	Os_Alarm_Counter = Os_Alarm_Counter + 1;
	Rte_Write_SecAlm_SecAlmPort_SecAlm_TriggerIRQCounterForTimer4(&Os_Alarm_Counter);
  /* USER CODE END Os_SecAlmAlarm_Timer_Callback */
}

/* Os_PdcR_Buzzer_Timer_Callback function */
void Os_PdcR_Buzzer_Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Os_PdcR_Buzzer_Timer_Callback */
	Os_Pdc_Rear_Counter = Os_Pdc_Rear_Counter + 1;
	Rte_Write_Pdc_PdcPort_Pdc_Rear_BuzzerOsCounter(&Os_Pdc_Rear_Counter);
  /* USER CODE END Os_PdcR_Buzzer_Timer_Callback */
}

/* Os_PdcF_Buzzer_Timer_Callback function */
void Os_PdcF_Buzzer_Timer_Callback(void *argument)
{
  /* USER CODE BEGIN Os_PdcF_Buzzer_Timer_Callback */
	Os_Pdc_Front_Counter = Os_Pdc_Front_Counter + 1;
	Rte_Write_Pdc_PdcPort_Pdc_Front_BuzzerOsCounter(&Os_Pdc_Front_Counter);
  /* USER CODE END Os_PdcF_Buzzer_Timer_Callback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/* USER CODE END Application */

