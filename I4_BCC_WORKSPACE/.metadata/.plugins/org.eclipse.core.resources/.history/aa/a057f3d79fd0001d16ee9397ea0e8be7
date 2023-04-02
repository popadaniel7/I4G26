#include "Std_Types.h"
#include "adc.h"

#define ADC_BUFFER_LENGTH 						16
#define ADC_BUFFER_VIBSEN 						1
#define ADC_BUFFER_LIGHTSEN 					0

EXTERN uint32 Adc_ChannelOne_Buffer[ADC_BUFFER_LENGTH];
EXTERN DMA_HandleTypeDef hdma_adc1;

EXTERN StdReturnType Adc_Init();
EXTERN StdReturnType Adc_DeInit();
EXTERN void Adc_MainFunction();
EXTERN void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
