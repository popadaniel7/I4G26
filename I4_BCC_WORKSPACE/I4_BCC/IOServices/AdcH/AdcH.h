/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Analog to Digital Converter    *
* 		  Handler                        *
******************************************/
#ifndef AdcH_H
#define AdcH_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
#include "adc.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Buffer size for ADC. */
#define ADC_BUFFER_LENGTH 3
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store ADC state. */
EXTERN uint8 Adc_BswState;
/* ADC buffer for channel one. */
EXTERN uint32 Adc_ChannelOne_Buffer[ADC_BUFFER_LENGTH];
/* ADC through DMA handler. */
EXTERN DMA_HandleTypeDef hdma_adc1;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Peripheral initialization function declaration. */
EXTERN StdReturnType Adc_Init();
/* Peripheral de-initialization function declaration. */
EXTERN StdReturnType Adc_DeInit();
/* Peripheral main function declaration. */
EXTERN VOID Adc_MainFunction();
/* Peripheral error callback function declaration. */
EXTERN VOID HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
/* Peripheral conversion complete callback function declaration. */
EXTERN VOID HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* AdcH_H */
