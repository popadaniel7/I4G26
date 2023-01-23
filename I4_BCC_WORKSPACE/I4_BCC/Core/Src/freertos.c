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
#include "PDC.h"
#include "HVAC.h"
#include "Std_Types.h"
#include "Project_Definitions.h"

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
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myTask02 */
osThreadId_t myTask02Handle;
const osThreadAttr_t myTask02_attributes = {
  .name = "myTask02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
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

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

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
	  CenLocMainFunction();
	  BtcMainFunction();
	  ExtLightsMainFunction();
	  IntLightsMainFunction();
	  SecAlmMainFunction();
	  HVACMainFunction();
	  PdcMainFunction();
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
	  OS_Counter++;
    osDelay(1);
  }
  /* USER CODE END StartTask02 */
}

/* PdcFrontDelayCallback function */
void PdcFrontDelayCallback(void *argument)
{
  /* USER CODE BEGIN PdcFrontDelayCallback */
	Pdc_FrontGenerateDelayFlag = STD_HIGH;
  /* USER CODE END PdcFrontDelayCallback */
}

/* PdcSecondFrontDelayCallback function */
void PdcSecondFrontDelayCallback(void *argument)
{
  /* USER CODE BEGIN PdcSecondFrontDelayCallback */
	Pdc_SecondFrontGenerateDelayFlag = STD_HIGH;
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
	Pdc_RearGenerateDelayFlag = STD_HIGH;
  /* USER CODE END PdcRearDelayCallback */
}

/* PdcSecondRearDelayCallback function */
void PdcSecondRearDelayCallback(void *argument)
{
  /* USER CODE BEGIN PdcSecondRearDelayCallback */
	Pdc_SecondRearGenerateDelayFlag = STD_HIGH;
  /* USER CODE END PdcSecondRearDelayCallback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

