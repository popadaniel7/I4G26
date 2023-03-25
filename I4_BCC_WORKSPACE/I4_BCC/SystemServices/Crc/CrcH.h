#include "Std_Types.h"
#include "crc.h"

EXTERN uint32 Crc_CenLoc_On;
EXTERN uint32 Crc_CenLoc_Off;
EXTERN uint32 Crc_ExtLights_HighBeam_On;
EXTERN uint32 Crc_ExtLights_HighBeam_Off;
EXTERN uint32 Crc_ExtLights_FlashHighBeam_On;
EXTERN uint32 Crc_ExtLights_FlashHighBeam_Off;
EXTERN uint32 Crc_ExtLights_TurnSignalLeft_On;
EXTERN uint32 Crc_ExtLights_TurnSignalLeft_Off;
EXTERN uint32 Crc_ExtLights_TurnSignalRight_On;
EXTERN uint32 Crc_ExtLights_TurnSignalRight_Off;
EXTERN uint32 Crc_ExtLights_HazardLight_On;
EXTERN uint32 Crc_ExtLights_HazardLight_Off;
EXTERN uint32 Crc_ExtLights_FogLightFront_On;
EXTERN uint32 Crc_ExtLights_FogLightFront_Off;
EXTERN uint32 Crc_ExtLights_BrakeLight_On;
EXTERN uint32 Crc_ExtLights_BrakeLight_Off;
EXTERN uint32 Crc_ExtLights_ReverseLight_On;
EXTERN uint32 Crc_ExtLights_ReverseLight_Off;
EXTERN uint32 Crc_ExtLights_PositionZero;
EXTERN uint32 Crc_ExtLights_AutomaticLights;
EXTERN uint32 Crc_ExtLights_PositionLights;
EXTERN uint32 Crc_ExtLights_NightTimeLights;
EXTERN uint32 Crc_Ignition_Step_One;
EXTERN uint32 Crc_Ignition_Step_Two;
EXTERN uint32 Crc_Ignition_Turn_Off;
EXTERN uint32 Crc_IntLights_InteriorLight_On;
EXTERN uint32 Crc_IntLights_InteriorLights_Off;
EXTERN uint32 Crc_ExtLights_FogLightRear_On;
EXTERN uint32 Crc_ExtLights_FogLightRear_Off;

EXTERN StdReturnType Crc_Init();
EXTERN StdReturnType Crc_DeInit();
EXTERN StdReturnType Crc_VerifyUartData();
EXTERN void Crc_MainFunction();
EXTERN void HAL_CRC_ErrorCallback(CRC_HandleTypeDef *hcrc);
EXTERN void Crc_InitCrcValuesForUart();
