#include "Std_Types.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "timers.h"
#include "wwdg.h"

#define POWER_ON_RESET  					0
#define BROWN_OUT_RESET 					1
#define SOFTWARE_RESET 						2
#define WATCHDOG_RESET						3
#define LOW_POWER_RESET 					4
#define BUTTON_RESET						5
#define HARDWARE_RESET						6
#define FLASH_FAULT_RESET 					7
#define NMI_RESET							8
#define MEMORY_FAULT_RESET  				9
#define USAGE_FAULT_RESET					10
#define BUS_FAULT_RESET						11
#define STACK_OVERFLOW_RESET				12
#define	MALLOC_FAILED_RESET					13
#define ADC_ERROR_INTERNAL					14
#define ADC_ERROR_OVR 						15
#define ADC_ERROR_DMA 						16
#define SPI_ERROR_MODF 						17
#define SPI_ERROR_FRE 						18
#define SPI_ERROR_CRC 						19
#define SPI_ERROR_OVR 						20
#define SPI_ERROR_DMA 						21
#define SPI_ERROR_FLAG 						22
#define SPI_ERROR_ABORT 					23
#define UART_ERROR_PE 						24
#define UART_ERROR_NE 						25
#define UART_ERROR_FE 						26
#define UART_ERROR_ORE 						27
#define UART_ERROR_DMA 						28
#define TIMER2_ERROR 						29
#define TIMER3_ERROR 						30
#define TIMER4_ERROR 						31
#define TIMER5_ERROR 						32
#define TIMER9_ERROR 						33
#define TIMER11_ERROR 						34

EXTERN unsigned long Os_Counter;
EXTERN WWDG_HandleTypeDef hwwdg;
EXTERN uint8 SystemManager_TriggerResetFlag;
EXTERN uint8 SystemManager_WriteFlashFlag;
EXTERN osTimerId_t Os_SecAlm_AlarmResetHandle;
EXTERN osTimerId_t Os_CenLoc_LockUnlockSequence_TimerHandle;

EXTERN StdReturnType SystemManager_SetFault(uint8 faultType);
EXTERN void SystemClock_Config(void);
EXTERN void Error_Handler(void);
EXTERN void MX_NVIC_Init(void);
EXTERN void SystemManager_Init();
EXTERN void SystemManager_MainFunction();
EXTERN void SystemManager_PerformReset();
