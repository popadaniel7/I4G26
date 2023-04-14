/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Diagnostic Event Manager	     *
******************************************/
#ifndef Dem_H
#define Dem_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Define value for reset / fault */
#define POWER_ON_RESET  						0
/* Define value for reset / fault */
#define BROWN_OUT_RESET 						1
/* Define value for reset / fault */
#define SOFTWARE_RESET 							2
/* Define value for reset / fault */
#define WATCHDOG_RESET							3
/* Define value for reset / fault */
#define LOW_POWER_RESET 						4
/* Define value for reset / fault */
#define BUTTON_RESET							5
/* Define value for reset / fault */
#define HARDWARE_RESET							6
/* Define value for reset / fault */
#define FLASH_FAULT_RESET 						7
/* Define value for reset / fault */
#define NMI_RESET								8
/* Define value for reset / fault */
#define MEMORY_FAULT_RESET  					9
/* Define value for reset / fault */
#define USAGE_FAULT_RESET						10
/* Define value for reset / fault */
#define BUS_FAULT_RESET							11
/* Define value for reset / fault */
#define STACK_OVERFLOW_RESET					12
/* Define value for reset / fault */
#define	MALLOC_FAILED_RESET						13
/* Define value for reset / fault */
#define ADC_ERROR_INTERNAL						14
/* Define value for reset / fault */
#define ADC_ERROR_OVR 							15
/* Define value for reset / fault */
#define ADC_ERROR_DMA 							16
/* Define value for reset / fault */
#define UART_ERROR_PE 							24
/* Define value for reset / fault */
#define UART_ERROR_NE 							25
/* Define value for reset / fault */
#define UART_ERROR_FE 							26
/* Define value for reset / fault */
#define UART_ERROR_ORE 							27
/* Define value for reset / fault */
#define UART_ERROR_DMA 							28
/* Define value for reset / fault */
#define TIMER2_ERROR 							29
/* Define value for reset / fault */
#define TIMER3_ERROR 							30
/* Define value for reset / fault */
#define TIMER4_ERROR 							31
/* Define value for reset / fault */
#define TIMER5_ERROR 							32
/* Define value for reset / fault */
#define SPI_ERROR_MODF							33
/* Define value for reset / fault */
#define SPI_ERROR_FRE							34
/* Define value for reset / fault */
#define SPI_ERROR_CRC							35
/* Define value for reset / fault */
#define SPI_ERROR_OVR							36
/* Define value for reset / fault */
#define SPI_ERROR_DMA							37
/* Define value for reset / fault */
#define SPI_ERROR_FLAG							38
/* Define value for reset / fault */
#define SPI_ERROR_ABORT							39
/* Define value for reset / fault */
#define I2C_ERROR_BERR_ONE						40
/* Define value for reset / fault */
#define I2C_ERROR_ARLO_ONE						41
/* Define value for reset / fault */
#define I2C_ERROR_AF_ONE						42
/* Define value for reset / fault */
#define I2C_ERROR_OVR_ONE						43
/* Define value for reset / fault */
#define I2C_ERROR_DMA_ONE						44
/* Define value for reset / fault */
#define I2C_ERROR_TIMEOUT_ONE					45
/* Define value for reset / fault */
#define I2C_ERROR_SIZE_ONE						46
/* Define value for reset / fault */
#define I2C_ERROR_DMA_PARAM_ONE					47
/* Define value for reset / fault */
#define I2C_ERROR_BERR_THREE					48
/* Define value for reset / fault */
#define I2C_ERROR_ARLO_THREE					49
/* Define value for reset / fault */
#define I2C_ERROR_AF_THREE						50
/* Define value for reset / fault */
#define I2C_ERROR_OVR_THREE						51
/* Define value for reset / fault */
#define I2C_ERROR_DMA_THREE						52
/* Define value for reset / fault */
#define I2C_ERROR_TIMEOUT_THREE					53
/* Define value for reset / fault */
#define I2C_ERROR_SIZE_THREE					54
/* Define value for reset / fault */
#define I2C_ERROR_DMA_PARAM_THREE				55
/* DTC ID define. */
#define DTC_LBUV 								56
/* DTC ID define. */
#define DTC_HBUV 								57
/* DTC ID define. */
#define DTC_DRLUV 								58
/* DTC ID define. */
#define DTC_FFLUV 								59
/* DTC ID define. */
#define DTC_RFLUV 								60
/* DTC ID define. */
#define DTC_RPLUV 								61
/* DTC ID define. */
#define DTC_RTSUV 								62
/* DTC ID define. */
#define DTC_LTSUV 								63
/* DTC ID define. */
#define DTC_RLUV 								64
/* DTC ID define. */
#define DTC_ILUV 								65
/* DTC ID define. */
#define DTC_DLUV 								66
/* DTC ID define. */
#define DTC_LPLUV 								67
/* DTC ID define. */
#define DTC_VS 									70
/* DTC ID define. */
#define DTC_LS 									71
/* DTC ID define. */
#define DTC_ALUV 								72
/* DTC ID define. */
#define DTC_CLBUV 								73
/* DTC ID define. */
#define DTC_ALBUV 								74
/* DTC ID define. */
#define DTC_LBS 								75
/* DTC ID define. */
#define DTC_HBS 								76
/* DTC ID define. */
#define DTC_DRLS 								77
/* DTC ID define. */
#define DTC_FFLS 								78
/* DTC ID define. */
#define DTC_RFLS 								79
/* DTC ID define. */
#define DTC_RPLS 								80
/* DTC ID define. */
#define DTC_RTSS 								81
/* DTC ID define. */
#define DTC_LTSS 								82
/* DTC ID define. */
#define DTC_RLS 								83
/* DTC ID define. */
#define DTC_ILS 								84
/* DTC ID define. */
#define DTC_DLS 								85
/* DTC ID define. */
#define DTC_LPLS 								86
/* DTC ID define. */
#define DTC_ALS 								87
/* DTC ID define. */
#define DTC_CLBS 								88
/* DTC ID define. */
#define DTC_ALBS 								89
/* DTC ID define. */
#define DTC_PDCR								90
/* DTC ID define. */
#define DTC_PDCF								91
/* DTC ID define. */
#define DTC_TS									92
/* DTC ID define. */
#define DTC_AQS									93
/* DTC ID define. */
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Module state variable. */
EXTERN uint8 Dem_BswState;
/* Dtc array. */
EXTERN uint8 Dem_DtcArray[93];
/* Dtc count array. */
EXTERN uint8 Dem_DtcCount[93];
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Module initialization. */
EXTERN StdReturnType Dem_Init();
/* Module de-initialization. */
EXTERN StdReturnType Dem_DeInit();
/* Module main function. */
EXTERN VOID Dem_MainFunction();
/* Receive fault from application. */
EXTERN VOID Dem_ReceiveFault(uint8 faultValue);
/* Process fault from application. */
EXTERN VOID Dem_ProcessFault();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* Dem_H */
