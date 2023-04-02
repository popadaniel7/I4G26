/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Timer Handler		 			 *
******************************************/
#ifndef TimH_H
#define TimH_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
#include "tim.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Value for timer two. */
#define TIMER_TWO 		2
/* Value for timer three. */
#define TIMER_THREE		3
/* Value for timer four. */
#define TIMER_FOUR		4
/* Value for timer five. */
#define TIMER_FIVE		5
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Variable to store module state. */
EXTERN uint8 TimH_BswState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Peripheral initialization function declaration. */
EXTERN StdReturnType Tim_Init(uint8 TimerChannel);
/* Peripheral de-initialization function declaration. */
EXTERN StdReturnType Tim_DeInit(uint8 TimerChannel);
/* Peripheral error callback function declaration. */
EXTERN VOID HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim);
/* Peripheral period elapsed callback function declaration. */
EXTERN VOID HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
/* Peripheral main function declaration. */
EXTERN VOID Tim_MainFunction();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* TimH_H */
