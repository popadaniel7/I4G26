#include "Std_Types.h"
#include "tim.h"

#define TIMER_TWO 		2
#define TIMER_THREE		3
#define TIMER_FOUR		4
#define TIMER_FIVE		5
#define TIMER_NINE		9
#define TIMER_TEN		10
#define TIMER_ELEVEN	11

EXTERN uint32 Timer2Counter_ExtLights_LTSFlag;
EXTERN uint32 Timer2Counter_ExtLights_RTSFlag;
EXTERN uint32 Timer2Counter_ExtLights_HLFlag;
EXTERN uint8  Timer2Counter_CenLoc_Tim2IRQFlag;
EXTERN uint8  Timer3Counter_CenLoc_Tim3IRQFlag;
EXTERN uint8  Timer5Counter_CenLoc_Tim5IRQFlag;
EXTERN uint8  Timer11Counter_CenLoc_Tim11IRQFlag;

EXTERN StdReturnType Tim_Init(uint8 TimerChannel);
EXTERN StdReturnType Tim_DeInit(uint8 TimerChannel);
EXTERN void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim);
EXTERN void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
EXTERN void Tim_MainFunction();
