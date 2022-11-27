#include "Std_Types.h"

#define LOW_BEAM_PORT GPIOA
#define LOW_BEAM_PIN GPIO_PIN_10
#define HIGH_BEAM_PORT GPIOB
#define HIGH_BEAM_PIN GPIO_PIN_5
#define FRONT_FOG_LIGHT_PORT GPIOB
#define FRONT_FOG_LIGHT_PIN GPIO_PIN_4
#define RIGHT_TURN_SIGNAL_PORT GPIOA
#define RIGHT_TURN_SIGNAL_PIN GPIO_PIN_8

#define REAR_POSITION_LIGHT_PORT GPIOA
#define REAR_POSITION_LIGHT_PIN GPIO_PIN_5
#define BRAKE_LIGHT_PORT GPIOB
#define BRAKE_LIGHT_PIN GPIO_PIN_9
#define REAR_FOG_LIGHT_PORT GPIOA
#define REAR_FOG_LIGHT_PIN GPIO_PIN_6
#define LEFT_TURN_SIGNAL_PORT GPIOA
#define LEFT_TURN_SIGNAL_PIN GPIO_PIN_9

#define REVERSE_LIGHT_PORT GPIOC
#define REVERSE_LIGHT_PIN GPIO_PIN_7

EXTERN uint8 CurrentState_LowBeam;
EXTERN uint8 CurrentState_HighBeam;
EXTERN uint8 CurrentState_FogLightFront;
EXTERN uint8 CurrentState_FogLightRear;
EXTERN uint8 CurrentState_TurnSignalRight;
EXTERN uint8 CurrentState_TurnSignalLeft;
EXTERN uint8 CurrentState_PositionLightRear;
EXTERN uint8 CurrentState_BrakeLight;
EXTERN uint8 CurrentState_ReverseLight;
EXTERN uint8 CurrentState_HazardLight;

EXTERN uint8 BTLowBeam;
EXTERN uint8 BTHighBeam;
EXTERN uint8 BTFogLightFront;
EXTERN uint8 BTFogLightRear;
EXTERN uint8 BTPositionLightRear;
EXTERN uint8 BTBrakeLight;
EXTERN uint8 BTReverseLight;
EXTERN uint8 BTTurnSignalRight;
EXTERN uint8 BTTurnSignalLeft;
EXTERN uint8 BTHazardLight;
EXTERN uint8 BTExtLight_IrqFlag;

EXTERN void ExtLights_MainFunction();
EXTERN StdReturnType ExtLights_Init();
EXTERN StdReturnType ExtLights_GetErrorStatus(uint8 ApplState);
EXTERN void ExtLights_LowBeam(uint8 PinState);
EXTERN void ExtLights_HighBeam(uint8 PinState);
EXTERN void ExtLights_FogLightFront(uint8 PinState);
EXTERN void ExtLights_FogLightRear(uint8 PinState);
EXTERN void ExtLights_TurnSignalLeft(uint8 PinState);
EXTERN void ExtLights_TurnSignalRight(uint8 PinState);
EXTERN void ExtLights_PositionLightRear(uint8 PinState);
EXTERN void ExtLights_BrakeLight(uint8 PinState);
EXTERN void ExtLights_ReverseLight(uint8 PinState);
