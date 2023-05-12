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
EXTERN uint8 TimH_BswState_TimerTwo;
/* Variable to store module state. */
EXTERN uint8 TimH_BswState_TimerThree;
/* Variable to store module state. */
EXTERN uint8 TimH_BswState_TimerFour;
/* Variable to store module state. */
EXTERN uint8 TimH_BswState_TimerFive;
/* First time stamp of the input compare value for channel three. */
EXTERN uint32 Tim5_InputCompare_ValueOne_ChannelThree;
/* Second time stamp of the input compare value for channel three. */
EXTERN uint32 Tim5_InputCompare_ValueTwo_ChannelThree;
/* Variable for the difference between the two time stamps for channel three. */
EXTERN uint32 Tim5_Difference_ChannelThree;
/* Input capture flag variable for channel three. */
EXTERN uint8 Tim5_InputCaptureFlag_ChannelThree;
/* Distance calculated for the distance traveled by the sound waves between the two input captures time stamps for channel three. */
EXTERN uint8 Tim5_CalculatedDistance_ChannelThree;
/* First time stamp of the input compare value for channel four. */
EXTERN uint32 Tim5_InputCompare_ValueOne_ChannelFour;
/* Second time stamp of the input compare value for channel four. */
EXTERN uint32 Tim5_InputCompare_ValueTwo_ChannelFour;
/* Variable for the difference between the two time stamps for channel four. */
EXTERN uint32 Tim5_Difference_ChannelFour;
/* Input capture flag variable for channel four. */
EXTERN uint8 Tim5_InputCaptureFlag_ChannelFour;
/* Distance calculated for the distance traveled by the sound waves between the two input captures time stamps for channel four. */
EXTERN uint8 Tim5_CalculatedDistance_ChannelFour;
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
/* Peripheral input capture callback function declaration. */
EXTERN VOID HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
/* Peripheral main function declaration. */
EXTERN VOID Tim_MainFunction();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* TimH_H */
