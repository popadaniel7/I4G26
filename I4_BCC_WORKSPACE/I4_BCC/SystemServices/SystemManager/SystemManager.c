/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: System Manager 			     *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "SystemManager.h"
#include "SystemManager_Types.h"
/*****************************************
		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store the System Manager state. */
EXTERN uint8 SystemManager_BswState;
/* Variable used to store system faults. */
uint8 SystemManager_Fault[34];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Third-party function declaration. */
EXTERN VOID SystemClock_Config(VOID);
/* Third-party function declaration. */
EXTERN VOID Error_Handler(VOID);
/* Third-party function declaration. */
EXTERN VOID MX_NVIC_Init(VOID);
/* Fault storing function declaration. */
EXTERN StdReturnType SystemManager_SetFault(uint8 faultType);
/* System de-initialization function declaration. */
EXTERN VOID SystemManager_DeInit();
/* System initialization function declaration. */
EXTERN VOID SystemManager_Init();
/* System main function declaration. */
EXTERN VOID SystemManager_MainFunction();
/* System reset performing function declaration. */
EXTERN VOID SystemManager_PerformReset();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: SystemManager_Init													   *
* Description: Initialize the system.  		   									   *
************************************************************************************/
VOID SystemManager_Init()
{
	/* Perform system initialization sequence. */
	HAL_Init();
	SystemClock_Config();
	MX_NVIC_Init();
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
	for(uint8 index = 0; index <= 34; index++)
	{
		if(faultType == index)
		{
			SystemManager_Fault[index] = index + 1;
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
	/* WWDG_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(WWDG_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(WWDG_IRQn);
	/* PVD_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(PVD_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(PVD_IRQn);
	/* FLASH_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(FLASH_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(FLASH_IRQn);
	/* RCC_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(RCC_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(RCC_IRQn);
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
	HAL_NVIC_SetPriority(USART1_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
	/* DMA2_Stream0_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
	/* FPU_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(FPU_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(FPU_IRQn);
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
	/* Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	/* Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure. */
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
	/* Initializes the CPU, AHB and APB buses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
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
