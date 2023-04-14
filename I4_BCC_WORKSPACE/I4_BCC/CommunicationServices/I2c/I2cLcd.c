/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Inter Integrated Circuit       *
* 		  Liquid Crystal Display Driver  *
******************************************/
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "I2cLcd.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Address of the I2C IO expander define. */
#define I2CLCD_SLAVE_ADDRESS 0x4E
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Function declaration for I2C LCD driver initialization. */
StdReturnType I2cLcd_Init();
/* Function declaration for I2C LCD driver de-initialization. */
StdReturnType I2cLcd_DeInit();
/* Function declaration for command transmitting. */
VOID I2cLcd_SendCommand (char cmd);
/* Function declaration for data transmitting. */
VOID I2cLcd_SendData (char data);
/* Function declaration for string transmitting. */
VOID I2cLcd_SendString (char *str);
/* Function declaration for setting the position on the LCD. */
VOID I2cLcd_SetCursor(int row, int col);
/* Function declaration for clearing the LCD. */
VOID I2cLcd_Clear();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
/***********************************************************************************
* Function: I2cLcd_Init										   			           *
* Description: Driver initialization.									           *
************************************************************************************/
StdReturnType I2cLcd_Init()
{
	/* Perform 4-bit initialization. */
	I2cLcd_SendCommand(0x30);
	I2cLcd_SendCommand(0x30);
	I2cLcd_SendCommand(0x30);
	I2cLcd_SendCommand(0x20);
	/* Perform display initialization. */
	I2cLcd_SendCommand(0x28);
	I2cLcd_SendCommand(0x08);
	I2cLcd_SendCommand(0x01);
	I2cLcd_SendCommand(0x06);
	I2cLcd_SendCommand(0x0C);
	return E_OK;
}
/***********************************************************************************
* END OF I2cLcd_Init										           	           *
************************************************************************************/
/***********************************************************************************
* Function: I2cLcd_DeInit										   			       *
* Description: Driver de-initialization.									       *
************************************************************************************/
StdReturnType I2cLcd_DeInit()
{
	return E_OK;
}
/***********************************************************************************
* END OF I2cLcd_DeInit										           	           *
************************************************************************************/
/***********************************************************************************
* Function: I2cLcd_SendCommand										   			   *
* Description: Driver command transmitting.									       *
************************************************************************************/
VOID I2cLcd_SendCommand(char cmd)
{
	if(I2c_BswState_ChannelOne == HAL_I2C_STATE_READY)
	{
		char data_u, data_l;
		uint8 data_t[4];
		data_u = (cmd & 0xf0);
		data_l = ((cmd << 4) & 0xf0);
		data_t[0] = data_u | 0x0C;
		data_t[1] = data_u | 0x08;
		data_t[2] = data_l | 0x0C;
		data_t[3] = data_l | 0x08;
		HAL_I2C_Master_Transmit_IT(&hi2c1, I2CLCD_SLAVE_ADDRESS,(uint8_t *) data_t, 4);
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF I2cLcd_SendCommand										           	       *
************************************************************************************/
/***********************************************************************************
* Function: I2cLcd_SendData										   			       *
* Description: Driver data transmitting.									       *
************************************************************************************/
VOID I2cLcd_SendData(char data)
{
	if(I2c_BswState_ChannelOne == HAL_I2C_STATE_READY)
	{
		char data_u, data_l;
		uint8 data_t[4];
		data_u = (data & 0xf0);
		data_l = ((data << 4) & 0xf0);
		data_t[0] = data_u | 0x0D;
		data_t[1] = data_u | 0x09;
		data_t[2] = data_l | 0x0D;
		data_t[3] = data_l | 0x09;
		HAL_I2C_Master_Transmit_IT(&hi2c1, I2CLCD_SLAVE_ADDRESS,(uint8_t *) data_t, 4);
	}
	else
	{
		/* do nothing */
	}
}
/***********************************************************************************
* END OF I2cLcd_SendData										           	       *
************************************************************************************/
/***********************************************************************************
* Function: I2cLcd_SendString										   			   *
* Description: Driver string transmitting.									       *
************************************************************************************/
VOID I2cLcd_SendString(char *str)
{
	while (*str)
	{
		I2cLcd_SendData(*str++);
	}
}
/***********************************************************************************
* END OF I2cLcd_SendString										           	       *
************************************************************************************/
/***********************************************************************************
* Function: I2cLcd_SetCursor										   			   *
* Description: Driver cursor setting.									           *
************************************************************************************/
VOID I2cLcd_SetCursor(int row, int col)
{
	switch (row)
	{
		case 0:
			col |= 0x80;
			break;
		case 1:
			col |= 0xC0;
			break;
	}
	I2cLcd_SendCommand(col);
}
/***********************************************************************************
* END OF I2cLcd_SetCursor										           	       *
************************************************************************************/
/***********************************************************************************
* Function: I2cLcd_Clear										   			       *
* Description: Driver LCD clearing.									               *
************************************************************************************/
VOID I2cLcd_Clear()
{
	I2cLcd_SendCommand(0x80);
	for (int i=0; i<70; i++)
	{
		I2cLcd_SendData(' ');
	}
}
/***********************************************************************************
* END OF I2cLcd_Clear										           	           *
************************************************************************************/
