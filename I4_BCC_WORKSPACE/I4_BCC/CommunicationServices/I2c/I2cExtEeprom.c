/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Inter Integrated Circuit       *
* 		  External Eeprom Driver         *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "I2cExtEeprom.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
#include "Rte.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Memory page size. */
#define I2C_EXTEEPROM_PAGE_SIZE 	64
/* Memory number of pages. */
#define I2C_EXTEEPROM_PAGE_NUM  	512
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
STATIC uint8 firstRun = STD_LOW;
STATIC uint8 ArrayReadAll[50] = {STD_LOW};
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Function declaration for initialization. */
StdReturnType I2cExtEeprom_Init();
/* Function declaration for de-initialization. */
StdReturnType I2cExtEeprom_DeInit();
/* Function declaration for writing into memory. */
VOID I2cExtEeprom_Write(uint16 page, uint16 offset, uint8 *data, uint16 size);
/* Function declaration for reading from memory. */
VOID I2cExtEeprom_Read(uint16 page, uint16 offset, uint8 *data, uint16 size);
/* Function declaration for erasing a page from memory. */
VOID I2cExtEeprom_PageErase(uint16 page);
/* Function declaration for returning the bytes that need to be written.  */
STATIC uint16 I2cExtEeprom_BytesToWrite(uint16 size, uint16 offset);
/* Function declaration for read all. */
VOID I2cExtEeprom_ReadAll();
/* Function declaration for write all. */
VOID I2cExtEeprom_WriteAll();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: I2cExtEeprom_ReadAll						    		               *
* Description: Returns the bytes that need to be written.					       *
************************************************************************************/
VOID I2cExtEeprom_ReadAll()
{
	if(firstRun == STD_LOW)
	{
		I2cExtEeprom_Read(0, 0, ArrayReadAll, 50);
		for(uint8 idx = 0; idx < 50; idx++)
		{
			if(ArrayReadAll[idx] > 254)
			{
				ArrayReadAll[idx] = 0;
			}
			else
			{
				/* do nothing */
			}
		}
		Btc_IgnitionStepOne = ArrayReadAll[0];
		Btc_IgnitionStepTwo = ArrayReadAll[1];
		Btc_IgnitionTurnOff = ArrayReadAll[2];
		CenLoc_CurrentState = ArrayReadAll[3];
		CenLoc_PreviousState = ArrayReadAll[4];
		CenLoc_FollowMeHomeState = ArrayReadAll[5];
		CenLoc_BlinkState = ArrayReadAll[6];
		CenLoc_BlinkCounter = ArrayReadAll[7];
		CenLoc_CyclicAlarmCounter = ArrayReadAll[8];
		CenLoc_FollowMeHomeCounter = ArrayReadAll[9];
		CenLoc_TurnOnLedCounter = ArrayReadAll[10];
		CenLoc_PreviousStateFlag = ArrayReadAll[11];
		ExtLights_ReverseLight_CurrentState = ArrayReadAll[12];
		ExtLights_LightsSwitch_CurrentState = ArrayReadAll[13];
		ExtLights_HighBeam_CurrentState = ArrayReadAll[14];
		ExtLights_FrontFogLight_CurrentState = ArrayReadAll[15];
		ExtLights_TurnSignalLeft_CurrentState = ArrayReadAll[16];
		ExtLights_TurnSignalRight_CurrentState = ArrayReadAll[17];
		ExtLights_HazardLight_CurrentState = ArrayReadAll[18];
		ExtLights_RearFogLight_CurrentState = ArrayReadAll[19];
		ExtLights_RTS_PrevState = ArrayReadAll[20];
		ExtLights_LTS_PrevState = ArrayReadAll[21];
		ExtLights_HL_PrevState = ArrayReadAll[22];
		ExtLights_RTSFlag = ArrayReadAll[23];
		ExtLights_LTSFlag = ArrayReadAll[24];
		ExtLights_HLFlag = ArrayReadAll[25];
		Hvac_CurrentState = ArrayReadAll[26];
		Hvac_FanValue = ArrayReadAll[27];
		Hvac_TemperatureValue = ArrayReadAll[28];
		Hvac_LegVent = ArrayReadAll[29];
		Hvac_MidVent = ArrayReadAll[30];
		Hvac_WindshieldVent = ArrayReadAll[31];
		Hvac_WindshieldDefrost = ArrayReadAll[32];
		Hvac_Ac = ArrayReadAll[33];
		Hvac_AutomaticMode = ArrayReadAll[34];
		firstRun = STD_HIGH;
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF I2cExtEeprom_ReadAll										               *
************************************************************************************/
/***********************************************************************************
* Function: I2cExtEeprom_WriteAll										   	       *
* Description: Driver initialization.									           *
************************************************************************************/
VOID I2cExtEeprom_WriteAll()
{
	if(ArrayReadAll[0] != Rte_P_Btc_BtcPort_Btc_IgnitionStepOne)
	{
		I2cExtEeprom_Write(0, 0, &ArrayReadAll[0], 1);
		ArrayReadAll[0] = Rte_P_Btc_BtcPort_Btc_IgnitionStepOne;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[1] != Rte_P_Btc_BtcPort_Btc_IgnitionStepTwo)
	{
		I2cExtEeprom_Write(0, 1, &ArrayReadAll[1], 1);
		ArrayReadAll[1] = Rte_P_Btc_BtcPort_Btc_IgnitionStepTwo;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[2] != Rte_P_Btc_BtcPort_Btc_IgnitionTurnOff)
	{
		I2cExtEeprom_Write(0, 2, &ArrayReadAll[2], 1);
		ArrayReadAll[2] = Rte_P_Btc_BtcPort_Btc_IgnitionTurnOff;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[3] != Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState)
	{
		I2cExtEeprom_Write(0, 3, &ArrayReadAll[3], 1);
		ArrayReadAll[3] = Rte_P_CenLoc_CenLocPort_CenLoc_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[4] != Rte_P_CenLoc_CenLocPort_CenLoc_BlinkState)
	{
		I2cExtEeprom_Write(0, 4, &ArrayReadAll[4], 1);
		ArrayReadAll[4] = Rte_P_CenLoc_CenLocPort_CenLoc_BlinkState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[5] != Rte_P_CenLoc_CenLocPort_CenLoc_BlinkCounter)
	{
		I2cExtEeprom_Write(0, 5, &ArrayReadAll[5], 1);
		ArrayReadAll[5] = Rte_P_CenLoc_CenLocPort_CenLoc_BlinkCounter;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[6] != Rte_P_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter)
	{
		//I2cExtEeprom_Write(0, 6, &ArrayReadAll[6], 1);
		//ArrayReadAll[6] = Rte_P_CenLoc_CenLocPort_CenLoc_CyclicAlarmCounter;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[7] != Rte_P_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter)
	{
		I2cExtEeprom_Write(0, 7, &ArrayReadAll[7], 1);
		ArrayReadAll[7] = Rte_P_CenLoc_CenLocPort_CenLoc_FollowMeHomeCounter;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[8] != Rte_P_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter)
	{
		//I2cExtEeprom_Write(0, 8, &ArrayReadAll[8], 1);
		//ArrayReadAll[8] = Rte_P_CenLoc_CenLocPort_CenLoc_TurnOnLedCounter;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[9] != Rte_P_CenLoc_CenLocPort_CenLoc_PreviousStateFlag)
	{
		I2cExtEeprom_Write(0, 9, &ArrayReadAll[9], 1);
		ArrayReadAll[9] = Rte_P_CenLoc_CenLocPort_CenLoc_PreviousStateFlag;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[10] != Rte_P_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState)
	{
		I2cExtEeprom_Write(0, 10, &ArrayReadAll[10], 1);
		ArrayReadAll[10] = Rte_P_ExtLights_ExtLightsPort_ExtLights_ReverseLight_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[11] != Rte_P_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState)
	{
		I2cExtEeprom_Write(0, 11, &ArrayReadAll[11], 1);
		ArrayReadAll[11] = Rte_P_ExtLights_ExtLightsPort_ExtLights_LightsSwitch_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[12] != Rte_P_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState)
	{
		I2cExtEeprom_Write(0, 12, &ArrayReadAll[12], 1);
		ArrayReadAll[12] = Rte_P_ExtLights_ExtLightsPort_ExtLights_HighBeam_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[13] != Rte_P_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState)
	{
		I2cExtEeprom_Write(0, 13, &ArrayReadAll[13], 1);
		ArrayReadAll[13] = Rte_P_ExtLights_ExtLightsPort_ExtLights_FrontFogLight_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[14] != Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState)
	{
		I2cExtEeprom_Write(0, 14, &ArrayReadAll[14], 1);
		ArrayReadAll[14] = Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalLeft_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[15] != Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState)
	{
		I2cExtEeprom_Write(0, 15, &ArrayReadAll[15], 1);
		ArrayReadAll[15] = Rte_P_ExtLights_ExtLightsPort_ExtLights_TurnSignalRight_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[16] != Rte_P_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState)
	{
		I2cExtEeprom_Write(0, 16, &ArrayReadAll[16], 1);
		ArrayReadAll[16] = Rte_P_ExtLights_ExtLightsPort_ExtLights_HazardLight_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[17] != Rte_P_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState)
	{
		I2cExtEeprom_Write(0, 17, &ArrayReadAll[17], 1);
		ArrayReadAll[17] = Rte_P_ExtLights_ExtLightsPort_ExtLights_RearFogLight_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[18] != Rte_P_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState)
	{
		I2cExtEeprom_Write(0, 18, &ArrayReadAll[18], 1);
		ArrayReadAll[18] = Rte_P_ExtLights_ExtLightsPort_ExtLights_RTS_PrevState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[19] != Rte_P_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState)
	{
		I2cExtEeprom_Write(0, 19, &ArrayReadAll[19], 1);
		ArrayReadAll[19] = Rte_P_ExtLights_ExtLightsPort_ExtLights_LTS_PrevState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[20] != Rte_P_ExtLights_ExtLightsPort_ExtLights_HL_PrevState)
	{
		I2cExtEeprom_Write(0, 20, &ArrayReadAll[20], 1);
		ArrayReadAll[20] = Rte_P_ExtLights_ExtLightsPort_ExtLights_HL_PrevState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[21] != Rte_P_ExtLights_ExtLightsPort_ExtLights_RTSFlag)
	{
		I2cExtEeprom_Write(0, 21, &ArrayReadAll[21], 1);
		ArrayReadAll[21] = Rte_P_ExtLights_ExtLightsPort_ExtLights_RTSFlag;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[22] != Rte_P_ExtLights_ExtLightsPort_ExtLights_LTSFlag)
	{
		I2cExtEeprom_Write(0, 22, &ArrayReadAll[22], 1);
		ArrayReadAll[22] = Rte_P_ExtLights_ExtLightsPort_ExtLights_LTSFlag;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[23] != Rte_P_ExtLights_ExtLightsPort_ExtLights_HLFlag)
	{
		I2cExtEeprom_Write(0, 23, &ArrayReadAll[23], 1);
		ArrayReadAll[23] = Rte_P_ExtLights_ExtLightsPort_ExtLights_HLFlag;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[24] != Rte_P_Hvac_HvacPort_Hvac_CurrentState)
	{
		I2cExtEeprom_Write(0, 24, &ArrayReadAll[24], 1);
		ArrayReadAll[24] = Rte_P_Hvac_HvacPort_Hvac_CurrentState;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[25] != Rte_P_Hvac_HvacPort_Hvac_FanValue)
	{
		I2cExtEeprom_Write(0, 25, &ArrayReadAll[25], 1);
		ArrayReadAll[25] = Rte_P_Hvac_HvacPort_Hvac_FanValue;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[26] != Rte_P_Hvac_HvacPort_Hvac_TemperatureValue)
	{
		I2cExtEeprom_Write(0, 26, &ArrayReadAll[26], 1);
		ArrayReadAll[26] = Rte_P_Hvac_HvacPort_Hvac_TemperatureValue;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[27] != Rte_P_Hvac_HvacPort_Hvac_LegVent)
	{
		I2cExtEeprom_Write(0, 27, &ArrayReadAll[27], 1);
		ArrayReadAll[27] = Rte_P_Hvac_HvacPort_Hvac_LegVent;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[28] != Rte_P_Hvac_HvacPort_Hvac_MidVent)
	{
		I2cExtEeprom_Write(0, 28, &ArrayReadAll[28], 1);
		ArrayReadAll[28] = Rte_P_Hvac_HvacPort_Hvac_MidVent;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[29] != Rte_P_Hvac_HvacPort_Hvac_WindshieldVent)
	{
		I2cExtEeprom_Write(0, 29, &ArrayReadAll[29], 1);
		ArrayReadAll[29] = Rte_P_Hvac_HvacPort_Hvac_WindshieldVent;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[30] != Rte_P_Hvac_HvacPort_Hvac_WindshieldDefrost)
	{
		I2cExtEeprom_Write(0, 30, &ArrayReadAll[30], 1);
		ArrayReadAll[30] = Rte_P_Hvac_HvacPort_Hvac_WindshieldDefrost;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[31] != Rte_P_Hvac_HvacPort_Hvac_Ac)
	{
		I2cExtEeprom_Write(0, 31, &ArrayReadAll[31], 1);
		ArrayReadAll[31] = Rte_P_Hvac_HvacPort_Hvac_Ac;
	}
	else
	{
		/* do nothing */
	}

	if(ArrayReadAll[32] != Rte_P_Hvac_HvacPort_Hvac_AutomaticMode)
	{
		I2cExtEeprom_Write(0, 32, &ArrayReadAll[32], 1);
		ArrayReadAll[32] = Rte_P_Hvac_HvacPort_Hvac_AutomaticMode;
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF I2cExtEeprom_WriteAll										               *
************************************************************************************/
/***********************************************************************************
* Function: I2cExtEeprom_BytesToWrite						    		           *
* Description: Returns the bytes that need to be written.					       *
************************************************************************************/
uint16 I2cExtEeprom_BytesToWrite(uint16 size, uint16 offset)
{
	/* Returns the number of bytes to write into memory. */
	if((size + offset) < I2C_EXTEEPROM_PAGE_SIZE)
	{
		return size;
	}
	else
	{
		return I2C_EXTEEPROM_PAGE_SIZE - offset;
	}
}
/***********************************************************************************
* END OF I2cExtEeprom_BytesToWrite										           *
************************************************************************************/
/***********************************************************************************
* Function: I2cExtEeprom_Init										   			   *
* Description: Driver initialization.									           *
************************************************************************************/
StdReturnType I2cExtEeprom_Init()
{
	/* Initialize the driver. */
	return E_OK;
}
/***********************************************************************************
* END OF I2cExtEeprom_Init										           	       *
************************************************************************************/
/***********************************************************************************
* Function: I2cExtEeprom_DeInit										   			   *
* Description: Driver de-initialization.									       *
************************************************************************************/
StdReturnType I2cExtEeprom_DeInit()
{
	/* De-initialize the driver. */
	return E_OK;
}
/***********************************************************************************
* END OF I2cExtEeprom_DeInit										           	   *
************************************************************************************/
/***********************************************************************************
* Function: I2cExtEeprom_Write										   			   *
* Description: Driver write to memory function.									   *
************************************************************************************/
VOID I2cExtEeprom_Write(uint16 page, uint16 offset, uint8 *data, uint16 size)
{
	uint32 paddrposition = log(I2C_EXTEEPROM_PAGE_SIZE) / log(2);
	uint16 startPage = page;
	uint16 endPage = page + ((size + offset) / I2C_EXTEEPROM_PAGE_SIZE);
	uint16 numofpages = (endPage - startPage) + 1;
	uint16 pos = 0;
	for (uint8 i = 0; i < numofpages; i++)
	{
		uint16 MemAddress = startPage << paddrposition | offset;
		uint16 bytesremaining = I2cExtEeprom_BytesToWrite(size, offset);
		HAL_I2C_Mem_Write_IT(&hi2c3, I2C_EXTEEPROM_ADDR, MemAddress, 2, &data[pos], bytesremaining);
		startPage = startPage + 1;
		offset = 0;
		size = size - bytesremaining;
		pos = pos+ bytesremaining;
		HAL_Delay(5);
	}
}
/***********************************************************************************
* END OF I2cExtEeprom_Write										           	       *
************************************************************************************/
/***********************************************************************************
* Function: I2cExtEeprom_Read										   			   *
* Description: Driver read from memory function.								   *
************************************************************************************/
VOID I2cExtEeprom_Read(uint16 page, uint16 offset, uint8 *data, uint16 size)
{
	uint32 paddrposition = log(I2C_EXTEEPROM_PAGE_SIZE) / log(2);
	uint16 startPage = page;
	uint16 endPage = page + ((size + offset) / I2C_EXTEEPROM_PAGE_SIZE);
	uint16 numofpages = (endPage - startPage) + 1;
	uint16 pos = 0;
	for (uint8 i = 0; i < numofpages; i++)
	{
		uint16 MemAddress = startPage << paddrposition | offset;
		uint16 bytesremaining = I2cExtEeprom_BytesToWrite(size, offset);
		HAL_I2C_Mem_Read_IT(&hi2c3, I2C_EXTEEPROM_ADDR, MemAddress, 2, &data[pos], bytesremaining);
		startPage = startPage + 1;
		offset = 0;
		size = size - bytesremaining;
		pos = pos + bytesremaining;
		HAL_Delay(5);
	}
}
/***********************************************************************************
* END OF I2cExtEeprom_Read										           	       *
************************************************************************************/
/***********************************************************************************
* Function: I2cExtEeprom_PageErase										   		   *
* Description: Driver memory page erasing.									       *
************************************************************************************/
VOID I2cExtEeprom_PageErase(uint16 page)
{
	uint32 paddrposition = log(I2C_EXTEEPROM_PAGE_SIZE) / log(2);
	uint16 MemAddress = page << paddrposition;
	uint8 data[I2C_EXTEEPROM_PAGE_SIZE];
	memset(data, 0xff, I2C_EXTEEPROM_PAGE_SIZE);
	HAL_I2C_Mem_Read_IT(&hi2c3, I2C_EXTEEPROM_ADDR, MemAddress, 2, data, I2C_EXTEEPROM_PAGE_SIZE);
	HAL_Delay(5);
}
/***********************************************************************************
* END OF I2cExtEeprom_PageErase										           	   *
************************************************************************************/
