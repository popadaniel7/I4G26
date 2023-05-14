/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: System Manager 			     *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "SystemManager.h"
#include "Dem.h"
#include "I2cExtEeprom.h"
/*****************************************
		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable used to store system faults. */
uint32 SystemManager_Fault[49] = {STD_LOW};
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Third-party function declaration. */
VOID SystemClock_Config(VOID);
/* Third-party function declaration. */
VOID Error_Handler(VOID);
/* Third-party function declaration. */
VOID MX_NVIC_Init(VOID);
/* Fault storing function declaration. */
StdReturnType SystemManager_SetFault(uint8 faultType);
/* System de-initialization function declaration. */
VOID SystemManager_DeInit();
/* System initialization function declaration. */
VOID SystemManager_Init();
/* System main function declaration. */
VOID SystemManager_MainFunction();
/* System reset performing function declaration. */
VOID SystemManager_PerformReset();
/* System processing fault function declaration. */
VOID SystemManager_ProcessFault();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: SystemManager_ProcessFault										       *
* Description: Initialize the system.  		   									   *
************************************************************************************/
VOID SystemManager_ProcessFault()
{
	for(uint8 idx = STD_LOW ; idx < 49; idx++)
	{
		if(SystemManager_Fault[idx] != STD_LOW)
		{
			if(idx == POWER_ON_RESET)
			{
				/* do nothing */
			}
			else if(idx == BROWN_OUT_RESET ||
					idx == LOW_POWER_RESET ||
					idx == HARDWARE_RESET ||
					idx == FLASH_FAULT_RESET ||
					idx == NMI_RESET ||
					idx == MEMORY_FAULT_RESET ||
					idx == USAGE_FAULT_RESET ||
					idx == BUS_FAULT_RESET)
			{
				if(SystemManager_Fault[idx] >= 2)
				{
					Dem_ReceiveFault(HARDWARE_RESET_DTC_CODE);
				}
				else
				{
					/* do nothing */
				}
			}
			else if(idx == SOFTWARE_RESET ||
					idx == WATCHDOG_RESET ||
					idx == STACK_OVERFLOW_RESET ||
					idx == MALLOC_FAILED_RESET)
			{
				if(SystemManager_Fault[idx] >= 2)
				{
					Dem_ReceiveFault(SOFTWARE_RESET_DTC_CODE);
				}
				else
				{
					/* do nothing */
				}
			}
			else if(idx == ADC_ERROR_INTERNAL ||
					idx == ADC_ERROR_OVR ||
					idx == ADC_ERROR_DMA ||
					idx == UART_ERROR_PE ||
					idx == UART_ERROR_NE ||
					idx == UART_ERROR_FE ||
					idx == UART_ERROR_ORE ||
					idx == UART_ERROR_DMA ||
					idx == TIMER2_ERROR ||
					idx == TIMER3_ERROR ||
					idx == TIMER4_ERROR ||
					idx == TIMER5_ERROR ||
#if(CAN_SPI_COMMUNICATION_ENABLE == STD_ON)
					idx == SPI_ERROR_MODF ||
					idx == SPI_ERROR_FRE ||
					idx == SPI_ERROR_CRC ||
					idx == SPI_ERROR_OVR ||
					idx == SPI_ERROR_DMA ||
					idx == SPI_ERROR_FLAG ||
					idx == SPI_ERROR_ABORT ||
#endif
					idx == I2C_ERROR_BERR_ONE ||
					idx == I2C_ERROR_ARLO_ONE ||
					idx == I2C_ERROR_AF_ONE ||
					idx == I2C_ERROR_OVR_ONE ||
					idx == I2C_ERROR_DMA_ONE ||
					idx == I2C_ERROR_TIMEOUT_ONE ||
					idx == I2C_ERROR_SIZE_ONE ||
					idx == I2C_ERROR_DMA_PARAM_ONE ||
					idx == I2C_ERROR_BERR_THREE ||
					idx == I2C_ERROR_ARLO_THREE ||
					idx == I2C_ERROR_AF_THREE ||
					idx == I2C_ERROR_OVR_THREE ||
					idx == I2C_ERROR_DMA_THREE ||
					idx == I2C_ERROR_TIMEOUT_THREE ||
					idx == I2C_ERROR_SIZE_THREE ||
					idx == I2C_ERROR_DMA_PARAM_THREE)
			{
				if(SystemManager_Fault[idx] >= 2)
				{
					Dem_ReceiveFault(PERIPHERAL_ERROR_DTC_CODE);
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
		}
		else
		{
			/* do nothing */
		}
	}
}
/***********************************************************************************
* END OF SystemManager_ProcessFault											  	   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SystemManager_Init													   *
* Description: Initialize the system.  		   									   *
************************************************************************************/
VOID SystemManager_Init()
{
	/* Perform system initialization sequence. */
	HAL_Init();
	SystemClock_Config();
}
/***********************************************************************************
* END OF SystemManager_Init											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SystemManager_DeInit												   *
* Description: De-initialize the system.  		   								   *
************************************************************************************/
VOID SystemManager_DeInit()
{
	HAL_DeInit();
}
/***********************************************************************************
* END OF SystemManager_DeInit											  		   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SystemManager_SetFault										   		   *
* Description: Set the fault in the system.		 		   						   *
************************************************************************************/
StdReturnType SystemManager_SetFault(uint8 faultType)
{
	/* Store the fault into the data type. */
	for(uint8 index = 0; index < 14; index++)
	{
		if(faultType == index)
		{
			SystemManager_Fault[index]++;
		}
		else
		{
			/* do nothing */
		}
	}
	return E_OK;
}
/***********************************************************************************
* END OF SystemManager_SetFault											  		   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SystemManager_MainFunction									   		   *
* Description: System main function.									 		   *
************************************************************************************/
VOID SystemManager_MainFunction()
{
	SystemManager_ProcessFault();
}
/***********************************************************************************
* END OF SystemManager_MainFunction											  	   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SystemManager_PerformReset									   		   *
* Description: Perform system reset.		 		   							   *
************************************************************************************/
VOID SystemManager_PerformReset()
{
	HAL_NVIC_SystemReset();
}
/***********************************************************************************
* END OF SystemManager_PerformReset											  	   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: MX_NVIC_Init													   	   *
* Description: Initialize the nested vector interrupt controller with configured   *
* 			   values.		 		   											   *
************************************************************************************/
VOID MX_NVIC_Init(VOID)
{
	/* TIM5_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(TIM5_IRQn, 10, 0);
	HAL_NVIC_EnableIRQ(TIM5_IRQn);
	/* WWDG_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(WWDG_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(WWDG_IRQn);
	/* FLASH_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(FLASH_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(FLASH_IRQn);
	/* RCC_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(RCC_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(RCC_IRQn);
	/* PVD_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(PVD_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(PVD_IRQn);
	/* ADC_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(ADC_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(ADC_IRQn);
	/* TIM2_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(TIM2_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	/* TIM3_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(TIM3_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
	/* TIM4_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(TIM4_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(TIM4_IRQn);
	/* USART1_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
	/* SPI3_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(SPI3_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(SPI3_IRQn);
	/* I2C3_EV_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(I2C3_EV_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(I2C3_EV_IRQn);
	/* I2C3_ER_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(I2C3_ER_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(I2C3_ER_IRQn);
	/* FPU_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(FPU_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(FPU_IRQn);
	/* TIM1_TRG_COM_TIM11_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn, 10, 0);
	HAL_NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);
	/* DMA2_Stream0_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 10, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
	/* DMA1_Stream2_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream2_IRQn, 10, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream2_IRQn);
	/* DMA1_Stream4_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 10, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
	/* I2C1_ER_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(I2C1_ER_IRQn, 10, 0);
	HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
	/* I2C1_EV_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(I2C1_EV_IRQn, 10, 0);
	HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
}
/***********************************************************************************
* END OF MX_NVIC_Init											  			   	   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: SystemClock_Config													   *
* Description: Initialize the system clock.		 		   						   *
************************************************************************************/
VOID SystemClock_Config(VOID)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 4;
	RCC_OscInitStruct.PLL.PLLN = 100;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 4;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	else
	{
		/* do nothing */
	}
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
	{
		Error_Handler();
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF SystemClock_Config											  			   *													       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Error_Handler													   	   *
* Description: Perform system reset in case of system fault.			 		   *
************************************************************************************/
VOID Error_Handler(VOID)
{
	__disable_irq();
	SystemManager_PerformReset();
	while (1)
	{
	}
}
/***********************************************************************************
* END OF Error_Handler											  			   	   *													       																	   *
************************************************************************************/
