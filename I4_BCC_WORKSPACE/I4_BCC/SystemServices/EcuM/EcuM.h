#include "Std_Types.h"
#include "EcuM_Types.h"

#define ECUM_WAKEUPSOURCE_POR 						0
#define ECUM_WAKEUPSOURCE_BOR 						1
#define ECUM_WAKEUPSOURCE_SOFTWARE_RESET			2
#define ECUM_WAKEUPSOURCE_WINDOWED_WATCHDOG_RESET	3
#define ECUM_WAKEUPSOURCE_LOWPOWER_RESET			4
#define ECUM_WAKEUPSOURCE_BUTTON_RESET				5
#define ECUM_CLEARED_STATE							6

EXTERN EcuM_StateType EcuM_GlobalState;

EXTERN StdReturnType EcuM_DriverInit();
EXTERN StdReturnType EcuM_DriverDeInit();
EXTERN void EcuM_MainFunction();
EXTERN void EcuM_SetWakeupSource(uint32 wakeupSource);
EXTERN void EcuM_ProcessWakeupEvent();
EXTERN void EcuM_CheckForWakeupEvent();
