/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Non-volatile Memory Managaer	 *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "NvM.h"
#include "Rte.h"
#include "I2cExtEeprom.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Module state define. */
#define NVM_INIT_STATE 		0x00
/* Module state define. */
#define NVM_DEINIT_STATE 	0x03
/* Module state define. */
#define NVM_READY_STATE		0x01
/* Module state define. */
#define NVM_BUSY_STATE		0x02
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
uint32 NvM_BswState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Function declaration for initialization. */
StdReturnType NvM_Init();
/* Function declaration for de-initialization. */
StdReturnType NvM_DeInit();
/* Function declaration for the main function. */
VOID NvM_MainFunction();
/* Function declaration for writing into memory. */
StdReturnType NvM_Write(uint16 page, uint16 offset, uint8 *data, uint16 size);
/* Function declaration for reading from memory. */
StdReturnType NvM_Read(uint16 page, uint16 offset, uint8 *data, uint16 size);
/* Function declaration for erasing a page from memory. */
StdReturnType NvM_PageErase(uint16 page);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: NvM_Init										   			           *
* Description: Module initialization.									           *
************************************************************************************/
StdReturnType NvM_Init()
{
	return E_OK;
}
/***********************************************************************************
* END OF NvM_Init										                           *
************************************************************************************/
/***********************************************************************************
* Function: NvM_DeInit										   			           *
* Description: Module de-initialization.									       *
************************************************************************************/
StdReturnType NvM_DeInit()
{
	return E_OK;
}
/***********************************************************************************
* END OF NvM_DeInit										                           *
************************************************************************************/
/***********************************************************************************
* Function: NvM_MainFunction										   			   *
* Description: Module main function.									           *
************************************************************************************/
VOID NvM_MainFunction()
{
	/* Process module state. */
	switch(NvM_BswState)
	{
		case NVM_INIT_STATE:
			NvM_Init();
			break;
		case NVM_DEINIT_STATE:
			NvM_DeInit();
			break;
		case NVM_READY_STATE:
			break;
		case NVM_BUSY_STATE:
			break;
		default:
			break;
	}
}
/***********************************************************************************
* END OF NvM_MainFunction										                   *
************************************************************************************/
/***********************************************************************************
* Function: NvM_Write										   			           *
* Description: Memory writing.									                   *
************************************************************************************/
StdReturnType NvM_Write(uint16 page, uint16 offset, uint8 *data, uint16 size)
{
	Rte_Call_I2cExtEeprom_P_I2cExtEepromPort_I2cExtEeprom_Write(page, offset, data, size);
	return E_OK;
}
/***********************************************************************************
* END OF NvM_Write										                           *
************************************************************************************/
/***********************************************************************************
* Function: NvM_Read										   			           *
* Description: Memory reading.									                   *
************************************************************************************/
StdReturnType NvM_Read(uint16 page, uint16 offset, uint8 *data, uint16 size)
{
	Rte_Call_I2cExtEeprom_P_I2cExtEepromPort_I2cExtEeprom_Read(page, offset, data, size);
	return E_OK;
}
/***********************************************************************************
* END OF NvM_Read										                           *
************************************************************************************/
/***********************************************************************************
* Function: NvM_PageErase										   			       *
* Description: Memory erasing.									                   *
************************************************************************************/
StdReturnType NvM_PageErase(uint16 page)
{
	Rte_Call_I2cExtEeprom_P_I2cExtEepromPort_I2cExtEeprom_PageErase(page);
	return E_OK;
}
/***********************************************************************************
* END OF NvM_PageErase										                       *
************************************************************************************/