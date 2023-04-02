/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: System Manager			     *
******************************************/
#ifndef SystemManager_H
#define SystemManager_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
#include "cmsis_os.h"
#include "wwdg.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Define value for reset / fault */
#define POWER_ON_RESET  					0
/* Define value for reset / fault */
#define BROWN_OUT_RESET 					1
/* Define value for reset / fault */
#define SOFTWARE_RESET 						2
/* Define value for reset / fault */
#define WATCHDOG_RESET						3
/* Define value for reset / fault */
#define LOW_POWER_RESET 					4
/* Define value for reset / fault */
#define BUTTON_RESET						5
/* Define value for reset / fault */
#define HARDWARE_RESET						6
/* Define value for reset / fault */
#define FLASH_FAULT_RESET 					7
/* Define value for reset / fault */
#define NMI_RESET							8
/* Define value for reset / fault */
#define MEMORY_FAULT_RESET  				9
/* Define value for reset / fault */
#define USAGE_FAULT_RESET					10
/* Define value for reset / fault */
#define BUS_FAULT_RESET						11
/* Define value for reset / fault */
#define STACK_OVERFLOW_RESET				12
/* Define value for reset / fault */
#define	MALLOC_FAILED_RESET					13
/* Define value for reset / fault */
#define ADC_ERROR_INTERNAL					14
/* Define value for reset / fault */
#define ADC_ERROR_OVR 						15
/* Define value for reset / fault */
#define ADC_ERROR_DMA 						16
/* Define value for reset / fault */
#define UART_ERROR_PE 						24
/* Define value for reset / fault */
#define UART_ERROR_NE 						25
/* Define value for reset / fault */
#define UART_ERROR_FE 						26
/* Define value for reset / fault */
#define UART_ERROR_ORE 						27
/* Define value for reset / fault */
#define UART_ERROR_DMA 						28
/* Define value for reset / fault */
#define TIMER2_ERROR 						29
/* Define value for reset / fault */
#define TIMER3_ERROR 						30
/* Define value for reset / fault */
#define TIMER4_ERROR 						31
/* Define value for reset / fault */
#define TIMER5_ERROR 						32
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store the System Manager state. */
EXTERN uint8 SystemManager_BswState;
/* Variable declared in header file for external access. */
EXTERN unsigned long Os_Counter;
/* Variable declared in header file for external access. */
EXTERN uint8 Os_LockUnlockSequence_Counter;
/* Variable declared in header file for external access. */
EXTERN uint8 Os_TurnOnCyclic_Counter;
/* Variable declared in header file for external access. */
EXTERN uint8 Os_TurnOnLed_Counter;
/* Variable declared in header file for external access. */
EXTERN uint8 Os_FollowMeHome_Counter;
/* Variable declared in header file for external access. */
EXTERN uint32 Os_Lts_Counter;
/* Variable declared in header file for external access. */
EXTERN uint32 Os_Rts_Counter;
/* Variable declared in header file for external access. */
EXTERN uint32 Os_HL_Counter;
/* Variable declared in header file for external access. */
EXTERN uint8 Os_Alarm_Counter;
/* Variable declared in header file for external access. */
EXTERN uint8 SystemManager_TriggerResetFlag;
/* Variable declared in header file for external access. */
EXTERN uint8 SystemManager_WriteFlashFlag;
/* Variable declared in header file for external access. */
EXTERN osTimerId_t Os_SecAlm_AlarmResetHandle;
/* Variable declared in header file for external access. */
EXTERN osTimerId_t Os_CenLoc_LockUnlockSequence_TimerHandle;
/* Variable declared in header file for external access. */
EXTERN osTimerId_t Os_SecAlmLed_TurnOnCyclic_TimerHandle;
/* Variable declared in header file for external access. */
EXTERN osTimerId_t Os_SecAlmLedTurnOn_TimerHandle;
/* Variable declared in header file for external access. */
EXTERN osTimerId_t Os_FollowMeHome_TimerHandle;
/* Variable declared in header file for external access. */
EXTERN osTimerId_t Os_TurnSignals_TimerHandle;
/* Variable declared in header file for external access. */
EXTERN osTimerId_t Os_SecAlmAlarm_TimerHandle;
/* Variable declared in header file for external access. */
EXTERN osTimerId_t Os_PdcTrigDelay_TimerHandle;
/* Variable used to store system faults. */
EXTERN uint8 SystemManager_Fault[34];
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
#endif /* SystemManager_H */
