#include "Std_Types.h"

#define LOW_BEAM
#define HIGH_BEAM
#define FRONT_FOG_LIGHT
#define FRONT_TURN_SIGNAL

#define REAR_POSITION_LIGHT
#define BRAKE_LIGHT
#define REAR_FOG_LIGHT
#define REAR_TURN_SIGNAL

#define REVERSE_LIGHT

extern uint8_t CurrentState_LowBeam;
extern uint8_t CurrentState_HighBeam;
extern uint8_t CurrentState_FogLightFront;
extern uint8_t CurrentState_FogLightRear;
extern uint8_t CurrentState_TurnSignalFront;
extern uint8_t CurrentState_TurnSignalRear;
extern uint8_t CurrentState_PositionLightRear;
extern uint8_t CurrentState_BrakeLight;
extern uint8_t CurrentState_ReverseLight;

extern uint8_t BTLowBeam;
extern uint8_t BTHighBeam;
extern uint8_t BTFogLightFront;
extern uint8_t BTFogLightRear;
extern uint8_t BTPositionLightRear;
extern uint8_t BTBrakeLight;
extern uint8_t BTReverseLight;
extern uint8_t BTTurnSignalRight;
extern uint8_t BTTurnSignalLeft;

extern void ExtLights_MainFunction();
extern uint8_t ExtLights_Init();
extern uint8_t ExtLights_GetErrorStatus(uint8_t ApplState);
extern void ExtLights_LowBeam(uint8_t PinState);
extern void ExtLights_HighBeam(uint8_t PinState);
extern void ExtLights_FogLightFront(uint8_t PinState);
extern void ExtLights_FogLightRear(uint8_t PinState);
extern void ExtLights_TurnSignalLeft(uint8_t PinState);
extern void ExtLights_TurnSignalRight(uint8_t PinState);
extern void ExtLights_PositionLightRear(uint8_t PinState);
extern void ExtLights_BrakeLight(uint8_t PinState);
extern void ExtLights_ReverseLight(uint8_t PinState);
