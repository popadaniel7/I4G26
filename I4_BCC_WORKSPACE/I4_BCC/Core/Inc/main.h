/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "SystemManager.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
//EXTERN void SystemClock_Config(void);
EXTERN void MX_FREERTOS_Init(void);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PDCF_BUZZER_Pin GPIO_PIN_13
#define PDCF_BUZZER_GPIO_Port GPIOC
#define VS_Pin GPIO_PIN_2
#define VS_GPIO_Port GPIOC
#define LS_Pin GPIO_PIN_3
#define LS_GPIO_Port GPIOC
#define PDCF_IC_Pin GPIO_PIN_0
#define PDCF_IC_GPIO_Port GPIOA
#define PDCR_IC_Pin GPIO_PIN_1
#define PDCR_IC_GPIO_Port GPIOA
#define CENLOC_BUZZER_Pin GPIO_PIN_2
#define CENLOC_BUZZER_GPIO_Port GPIOB
#define IL_PWM_Pin GPIO_PIN_10
#define IL_PWM_GPIO_Port GPIOB
#define SECALM_BUZZER_Pin GPIO_PIN_12
#define SECALM_BUZZER_GPIO_Port GPIOB
#define PDCR_TRIG_Pin GPIO_PIN_13
#define PDCR_TRIG_GPIO_Port GPIOB
#define AL_Pin GPIO_PIN_14
#define AL_GPIO_Port GPIOB
#define RL_Pin GPIO_PIN_15
#define RL_GPIO_Port GPIOB
#define BL_PWM_Pin GPIO_PIN_7
#define BL_PWM_GPIO_Port GPIOC
#define FFL_PWM_Pin GPIO_PIN_8
#define FFL_PWM_GPIO_Port GPIOC
#define RFL_PWM_Pin GPIO_PIN_9
#define RFL_PWM_GPIO_Port GPIOC
#define PDCF_TRIG_Pin GPIO_PIN_11
#define PDCF_TRIG_GPIO_Port GPIOA
#define HB_Pin GPIO_PIN_12
#define HB_GPIO_Port GPIOA
#define LB_PWM_Pin GPIO_PIN_15
#define LB_PWM_GPIO_Port GPIOA
#define RPL_PWM_Pin GPIO_PIN_3
#define RPL_PWM_GPIO_Port GPIOB
#define PDCR_BUZZER_Pin GPIO_PIN_5
#define PDCR_BUZZER_GPIO_Port GPIOB
#define LTS_PWM_Pin GPIO_PIN_8
#define LTS_PWM_GPIO_Port GPIOB
#define RTS_PWM_Pin GPIO_PIN_9
#define RTS_PWM_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
