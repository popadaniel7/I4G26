#include "HVAC.h"

uint8 HVAC_TemperatureValue;
uint8 HVAC_FanValue;
uint8 HVAC_LegVents_CurrentState;
uint8 HVAC_MidVents_CurrentState;
uint8 HVAC_WindshieldVents_CurrentState;
uint8 HVAC_WindshieldDefrost_CurrentState;
uint8 HVAC_AC_CurrentState;
uint8 HVAC_AutomaticMode_CurrentState;
uint8 HVAC_RecirculationMode_CurrentState;
uint8 HVAC_BackwindowDefrost_CurrentState;

StdReturnType HVACInit();
void HVACMainFunction();
void HVACState();
void HVACRecirculationMode(uint8 RecirculationState);
void HVACAutomaticMode(uint8 AutomaticState);
void HVACI2cTxToLcd();

void HVACI2cTxToLcd()
{

	/*
	 * 		Character to be displayed on LCD list:
	 * 		L 	= leg vent
	 * 		M 	= mid vent
	 * 		W 	= windshield vent
	 * 		AC 	= AC on
	 * 		WD 	= windshield defrost
	 *      (A)	= automatic recirculation mode
	 *      (C) = manual recirculation mode
	 *      show nothing = no recirculation
	 *      F=x = fan value
	 *      T=x = temperature value
	 *      AUTO = automatic mode
	 *      BD = backwindow defrost
	 *
	 */

}

void HVACMainFunction()
{



}

void HVACState()
{



}

void HVACRecirculationMode(uint8 RecirculationState)
{



}

void HVACAutomaticMode(uint8 AutomaticState)
{



}

StdReturnType HVACInit()
{

	HVAC_TemperatureValue 					= STD_LOW;
	HVAC_FanValue 							= STD_LOW;
	HVAC_LegVents_CurrentState 				= STD_LOW;
	HVAC_MidVents_CurrentState 				= STD_LOW;
	HVAC_WindshieldVents_CurrentState 		= STD_LOW;
	HVAC_WindshieldDefrost_CurrentState 	= STD_LOW;
	HVAC_AC_CurrentState 					= STD_LOW;
	HVAC_AutomaticMode_CurrentState 		= STD_LOW;
	HVAC_RecirculationMode_CurrentState 	= STD_LOW;
	HVAC_BackwindowDefrost_CurrentState     = STD_LOW;

	return E_OK;

}
