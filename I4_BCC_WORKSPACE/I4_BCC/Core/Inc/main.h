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
#define VS_Pin GPIO_PIN_0
#define VS_GPIO_Port GPIOA
#define BUZZ1_Pin GPIO_PIN_2
#define BUZZ1_GPIO_Port GPIOB
#define IL_PWM_Pin GPIO_PIN_10
#define IL_PWM_GPIO_Port GPIOB
#define BUZZ2_Pin GPIO_PIN_12
#define BUZZ2_GPIO_Port GPIOB
#define HB_Pin GPIO_PIN_13
#define HB_GPIO_Port GPIOB
#define AL_Pin GPIO_PIN_14
#define AL_GPIO_Port GPIOB
#define RL_Pin GPIO_PIN_15
#define RL_GPIO_Port GPIOB
#define DL_PWM_Pin GPIO_PIN_6
#define DL_PWM_GPIO_Port GPIOC
#define BL_PWM_Pin GPIO_PIN_7
#define BL_PWM_GPIO_Port GPIOC
#define FFL_PWM_Pin GPIO_PIN_8
#define FFL_PWM_GPIO_Port GPIOC
#define RFL_PWM_Pin GPIO_PIN_9
#define RFL_PWM_GPIO_Port GPIOC
#define LB_PWM_Pin GPIO_PIN_15
#define LB_PWM_GPIO_Port GPIOA
#define RPL_PWM_Pin GPIO_PIN_3
#define RPL_PWM_GPIO_Port GPIOB
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
