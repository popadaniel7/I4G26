/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Heating Ventilation Air		 *
* 		  Conditioning	     			 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Hvac.h"
#include "Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Application request define. */
#define HVAC_AQS_REQUEST			0x06
/* Application request define. */
#define HVAC_TS_REQUEST				0x07
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Sensor state variable. */
uint8 Hvac_TsState;
/* Sensor state variable. */
uint8 Hvac_AqsState;
/* Application state variable. */
uint8 Hvac_ApplState = STD_LOW;
/* Current state variable. */
uint8 Hvac_CurrentState = STD_LOW;
/* Fan value variable. */
uint8 Hvac_FanValue = STD_LOW;
/* Climate control temperature value. */
uint8 Hvac_TemperatureValue = STD_LOW;
/* Leg vents state. */
uint8 Hvac_LegVent = STD_LOW;
/* Mid vents state. */
uint8 Hvac_MidVent = STD_LOW;
/* Windshield vents state. */
uint8 Hvac_WindshieldVent = STD_LOW;
/* Windshield defrost mode. */
uint8 Hvac_WindshiedlDefrost = STD_LOW;
/* Rear windshield defrost mode. */
uint8 Hvac_RearWindshieldDefrost = STD_LOW;
/* AC state. */
uint8 Hvac_Ac = STD_LOW;
/* Manual recirculation. */
uint8 Hvac_Recirculation = STD_LOW;
/* No recirculation. */
uint8 Hvac_NoRecirculation = STD_LOW;
/* Automatic recirculation. */
uint8 Hvac_AutomaticRecirculation = STD_LOW;
/* Automatic mode. */
uint8 Hvac_AutomaticMode = STD_LOW;
/* Static variable for the clearing of the lcd. */
STATIC uint8 Hvac_IsCleared = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousFanValue = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousTemperatureValue = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousLegVent = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousMidVent = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousWindshieldVent = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousWindshiedlDefrost = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousRearWindshieldDefrost = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousAc = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousNoRecirculation = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousRecirculation = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousAutomaticRecirculation = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PreviousAutomaticMode = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_IsFirstAutomaticSequence = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PrevAutoAc = STD_LOW;
/* Static variable for previous value. */
STATIC uint8 Hvac_PrevAutoRec = STD_LOW;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Application memory read. */
VOID Hvac_MemRead();
/* Application memory write. */
VOID Hvac_MemWrite();
/* Application initialization. */
StdReturnType Hvac_Init();
/* Application de-initialization. */
StdReturnType Hvac_DeInit();
/* Application main function. */
VOID Hvac_MainFunction();
/* Process the received command. */
VOID Hvac_ProcessCommand();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: Hvac_MemRead											 		   	   *
* Description: Read from memory..					           			   		   *
************************************************************************************/
VOID Hvac_MemRead()
{
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 37, &Hvac_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 38, &Hvac_FanValue, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 39, &Hvac_TemperatureValue, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 40, &Hvac_LegVent, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 41, &Hvac_MidVent, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 42, &Hvac_WindshieldVent, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 43, &Hvac_WindshiedlDefrost, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 44, &Hvac_RearWindshieldDefrost, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 45, &Hvac_Ac, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 46, &Hvac_Recirculation, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 47, &Hvac_NoRecirculation, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 48, &Hvac_AutomaticRecirculation, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Read(0, 49, &Hvac_AutomaticMode, 1);
}
/***********************************************************************************
* END OF Hvac_MemRead											  				   * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Hvac_MemWrite											 		       *
* Description: Write into memory.					           			   		   *
************************************************************************************/
VOID Hvac_MemWrite()
{
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 37, &Hvac_CurrentState, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 38, &Hvac_FanValue, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 39, &Hvac_TemperatureValue, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 40, &Hvac_LegVent, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 41, &Hvac_MidVent, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 42, &Hvac_WindshieldVent, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 43, &Hvac_WindshiedlDefrost, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 44, &Hvac_RearWindshieldDefrost, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 45, &Hvac_Ac, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 46, &Hvac_Recirculation, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 47, &Hvac_NoRecirculation, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 48, &Hvac_AutomaticRecirculation, 1);
	Rte_Call_NvM_P_NvMPort_NvM_Write(0, 49, &Hvac_AutomaticMode, 1);
}
/***********************************************************************************
* END OF Hvac_MemWrite											  				   * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Hvac_Init											 		   		   *
* Description: Application initialization.					           			   *
************************************************************************************/
StdReturnType Hvac_Init()
{
	Hvac_CurrentState 				= STD_LOW;
	Hvac_FanValue 					= STD_LOW;
	Hvac_TemperatureValue 			= STD_LOW;
	Hvac_LegVent 					= STD_LOW;
	Hvac_MidVent 					= STD_LOW;
	Hvac_WindshieldVent 			= STD_LOW;
	Hvac_WindshiedlDefrost 			= STD_LOW;
	Hvac_RearWindshieldDefrost 		= STD_LOW;
	Hvac_Ac 						= STD_LOW;
	Hvac_Recirculation 				= STD_LOW;
	Hvac_NoRecirculation 			= STD_LOW;
	Hvac_AutomaticRecirculation 	= STD_LOW;
	Hvac_AutomaticMode 				= STD_LOW;
	Hvac_ApplState 					= HVAC_PROCESSCOMMAND_STATE;
	return E_OK;
}
/***********************************************************************************
* END OF Hvac_Init											  					   * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Hvac_DeInit											 		  		   *
* Description: Application de-initialization.					           		   *
************************************************************************************/
StdReturnType Hvac_DeInit()
{
	/* Perform write all in memory. */
	return E_OK;
}
/***********************************************************************************
* END OF Hvac_DeInit											  				   * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Hvac_MainFunction											 		   *
* Description: Application main function.					                       *
************************************************************************************/
VOID Hvac_MainFunction()
{
	/* Process application state. */
	switch(Hvac_ApplState)
	{
		case HVAC_INIT_STATE:
			Hvac_Init();
			break;
		case HVAC_DEINIT_STATE:
			Hvac_DeInit();
			break;
		case HVAC_PROCESSCOMMAND_STATE:
			Hvac_ProcessCommand();
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF Hvac_MainFunction											  		       * 		   																	       																	   *
************************************************************************************/
/***********************************************************************************
* Function: Hvac_ProcessCommand											 		   *
* Description: Process HVAC states.					                               *
************************************************************************************/
VOID Hvac_ProcessCommand()
{
	static uint8 sensorValueAqs = 0;
	static uint8 sensorValueTs = 0;
	Rte_Call_SenCtrl_P_SenCtrlPort_SenCtrl_ProcessSensorValue(HVAC_AQS_REQUEST);
	Rte_Call_SenCtrl_P_SenCtrlPort_SenCtrl_ProcessSensorValue(HVAC_TS_REQUEST);
	sensorValueAqs = Hvac_AqsState;
	sensorValueTs = Hvac_TsState;
	/* Clear the LCD if the HVAC is off. */
	if(Hvac_CurrentState == STD_LOW && Hvac_IsCleared)
	{
		Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_Clear();
		Hvac_IsCleared = STD_HIGH;
	}/* Else process HVAC states. */
	else if(Hvac_CurrentState == STD_HIGH)
	{
		/* Change state of the clearing of the LCD. */
		Hvac_IsCleared = STD_LOW;
		/* Update the fan value each time it is modified. */
		if(Hvac_FanValue != Hvac_PreviousFanValue)
		{
			Hvac_PreviousFanValue = Hvac_FanValue;
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 0);
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("F=");
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 2);
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendData(Hvac_FanValue);
		}
		else
		{
			/* do nothing */
		}
		/* Update the temperature value each time it is modified. */
		if(Hvac_TemperatureValue != Hvac_PreviousTemperatureValue)
		{
			Hvac_PreviousTemperatureValue = Hvac_TemperatureValue;
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 0);
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("T=");
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 2);
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendData(Hvac_TemperatureValue);
		}
		else
		{
			/* do nothing */
		}
		/* If Automatic mode is on, take control as such. */
		if(Hvac_AutomaticMode == STD_HIGH)
		{
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_AutomaticMode !=  Hvac_PreviousAutomaticMode)
			{
				Hvac_PreviousLegVent = Hvac_LegVent;
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 6);
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("AUTO");
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_IsFirstAutomaticSequence == STD_LOW)
			{
				Hvac_IsFirstAutomaticSequence = STD_HIGH;
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 4);
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString(" ");
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 5);
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString(" ");
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 6);
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString(" ");
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 7);
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("  ");
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 9);
				Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("   ");
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(sensorValueTs >= 22)
			{
				if(Hvac_PrevAutoAc != sensorValueTs)
				{
					Hvac_PrevAutoAc = sensorValueTs;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 12);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("AC"); /* to activate from TS*/
				}
				else
				{
					/* do nothing */
				}
			}
			else if(sensorValueTs < 22)
			{
				if(Hvac_PrevAutoAc != sensorValueTs)
				{
					Hvac_PrevAutoAc = sensorValueTs;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 12);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("  "); /* to activate from TS*/
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(sensorValueAqs >= 4000)
			{
				if(Hvac_PrevAutoRec != sensorValueAqs)
				{
					Hvac_PrevAutoRec = sensorValueAqs;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 3);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("(A)"); /* to activate from AQS*/
				}
				else
				{
					/* do nothing */
				}
			}
			else if(sensorValueAqs < 4000)
			{
				if(Hvac_PrevAutoRec != sensorValueAqs)
				{
					Hvac_PrevAutoRec = sensorValueAqs;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 3);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("   "); /* to activate from AQS*/
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
		}
		else if(Hvac_AutomaticMode == STD_LOW)
		{
			/* Set the values accordingly. */
			Hvac_PreviousAutomaticMode = Hvac_AutomaticMode;
			Hvac_IsFirstAutomaticSequence = Hvac_AutomaticMode;
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 6);
			Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("    ");
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_LegVent == STD_HIGH)
			{
				if(Hvac_LegVent != Hvac_PreviousLegVent)
				{
					Hvac_PreviousLegVent = Hvac_LegVent;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 4);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("L");
				}
				else
				{
					/* do nothing */
				}
			}
			else if(Hvac_LegVent == STD_LOW)
			{
				if(Hvac_LegVent != Hvac_PreviousLegVent)
				{
					Hvac_PreviousLegVent = Hvac_LegVent;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 4);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString(" ");
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_MidVent == STD_HIGH)
			{
				if(Hvac_MidVent != Hvac_PreviousMidVent)
				{
					Hvac_PreviousMidVent = Hvac_MidVent;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 5);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("M");
				}
				else
				{
					/* do nothing */
				}
			}
			else if(Hvac_MidVent == STD_LOW)
			{
				if(Hvac_MidVent != Hvac_PreviousMidVent)
				{
					Hvac_PreviousMidVent = Hvac_MidVent;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 5);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString(" ");
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_WindshieldVent == STD_HIGH)
			{
				if(Hvac_WindshieldVent != Hvac_PreviousWindshieldVent)
				{
					Hvac_PreviousWindshieldVent = Hvac_WindshieldVent;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 6);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("W");
				}
				else
				{
					/* do nothing */
				}
			}
			else if(Hvac_WindshieldVent == STD_LOW)
			{
				if(Hvac_WindshieldVent != Hvac_PreviousWindshieldVent)
				{
					Hvac_PreviousWindshieldVent = Hvac_WindshieldVent;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 6);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString(" ");
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_WindshiedlDefrost == STD_HIGH)
			{
				if(Hvac_WindshiedlDefrost != Hvac_PreviousWindshiedlDefrost)
				{
					Hvac_PreviousWindshiedlDefrost = Hvac_WindshiedlDefrost;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 7);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("WD");
				}
				else
				{
					/* do nothing */
				}
			}
			else if(Hvac_WindshiedlDefrost == STD_LOW)
			{
				if(Hvac_WindshiedlDefrost != Hvac_PreviousWindshiedlDefrost)
				{
					Hvac_PreviousWindshiedlDefrost = Hvac_WindshiedlDefrost;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 7);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("  ");
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_RearWindshieldDefrost == STD_HIGH)
			{
				if(Hvac_RearWindshieldDefrost != Hvac_PreviousRearWindshieldDefrost)
				{
					Hvac_PreviousRearWindshieldDefrost = Hvac_RearWindshieldDefrost;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 9);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("RWD");
				}
				else
				{
					/* do nothing */
				}
			}
			else if(Hvac_RearWindshieldDefrost == STD_LOW)
			{
				if(Hvac_RearWindshieldDefrost != Hvac_PreviousRearWindshieldDefrost)
				{
					Hvac_PreviousRearWindshieldDefrost = Hvac_RearWindshieldDefrost;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 9);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("   ");
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_Ac == STD_HIGH)
			{
				if(Hvac_Ac != Hvac_PreviousAc)
				{
					Hvac_PreviousRearWindshieldDefrost = Hvac_Ac;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 12);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("AC");
				}
				else
				{
					/* do nothing */
				}
			}
			else if(Hvac_Ac == STD_LOW)
			{
				if(Hvac_Ac != Hvac_PreviousAc)
				{
					Hvac_PreviousAc = Hvac_Ac;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(0, 12);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("  ");
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
			/* Write on the LCD the status each time it is modified. */
			if(Hvac_NoRecirculation == STD_HIGH && Hvac_Recirculation == STD_LOW && Hvac_AutomaticRecirculation == STD_LOW)
			{
				if(Hvac_NoRecirculation != Hvac_PreviousNoRecirculation)
				{
					Hvac_PreviousNoRecirculation = Hvac_NoRecirculation;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 3);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("(N)");
				}
				else
				{
					/* do nothing */
				}
			}
			else if(Hvac_NoRecirculation == STD_LOW && Hvac_Recirculation == STD_HIGH && Hvac_AutomaticRecirculation == STD_LOW)
			{
				if(Hvac_Recirculation != Hvac_PreviousRecirculation)
				{
					Hvac_PreviousRecirculation = Hvac_Recirculation;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 3);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("(C)");
				}
				else
				{
					/* do nothing */
				}
			}
			else if(Hvac_NoRecirculation == STD_LOW && Hvac_Recirculation == STD_LOW && Hvac_AutomaticRecirculation == STD_HIGH)
			{
				if(Hvac_AutomaticRecirculation != Hvac_PreviousAutomaticRecirculation)
				{
					Hvac_PreviousAutomaticRecirculation = Hvac_AutomaticRecirculation;
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SetCursor(1, 3);
					Rte_Call_I2cLcd_P_I2cLcdPort_I2cLcd_SendString("(A)"); /* to activate from AQS */
				}
				else
				{
					/* do nothing */
				}
			}
			else
			{
				/* do nothing */
			}
		}
	}
}
/***********************************************************************************
* END OF Hvac_ProcessCommand											 		   * 		   																	       																	   *
************************************************************************************/