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
#define LS_Pin GPIO_PIN_1
#define LS_GPIO_Port GPIOA
#define HB_Pin GPIO_PIN_4
#define HB_GPIO_Port GPIOA
#define LB_Pin GPIO_PIN_5
#define LB_GPIO_Port GPIOA
#define DL_Pin GPIO_PIN_6
#define DL_GPIO_Port GPIOA
#define BL_Pin GPIO_PIN_7
#define BL_GPIO_Port GPIOA
#define AL_Pin GPIO_PIN_4
#define AL_GPIO_Port GPIOC
#define RL_Pin GPIO_PIN_5
#define RL_GPIO_Port GPIOC
#define FFL_Pin GPIO_PIN_0
#define FFL_GPIO_Port GPIOB
#define RFL_Pin GPIO_PIN_1
#define RFL_GPIO_Port GPIOB
#define BUZZ1_Pin GPIO_PIN_2
#define BUZZ1_GPIO_Port GPIOB
#define POSL_Pin GPIO_PIN_10
#define POSL_GPIO_Port GPIOB
#define BUZZ2_Pin GPIO_PIN_12
#define BUZZ2_GPIO_Port GPIOB
#define IL_Pin GPIO_PIN_3
#define IL_GPIO_Port GPIOB
#define LTS_Pin GPIO_PIN_6
#define LTS_GPIO_Port GPIOB
#define RTS_Pin GPIO_PIN_7
#define RTS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
