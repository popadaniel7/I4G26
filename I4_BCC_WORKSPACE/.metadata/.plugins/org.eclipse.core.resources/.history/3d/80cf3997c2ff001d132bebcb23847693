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
#include "Rte.h"
#include "TimH.h"
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
STATIC uint8 init1;
STATIC uint8 init2;
STATIC uint8 init3;
STATIC uint8 init4;
STATIC uint8 init5;
STATIC uint8 init6;
STATIC uint8 init7;
STATIC uint8 init8;
STATIC uint8 init9;
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
	if(Rte_P_Btc_BtcPort_Btc_ReceivedDataOnBluetooth == 92)
	{
		uint8 local = 93;
		Rte_Write_Btc_BtcPort_Btc_ReceivedDataOnBluetooth(&local);
		init1 = STD_LOW;
		init2 = STD_LOW;
		init3 = STD_LOW;
		init4 = STD_LOW;
		init5 = STD_LOW;
		init6 = STD_LOW;
		init7 = STD_LOW;
		init8 = STD_LOW;
		init9 = STD_LOW;
		I2c_Lcd_Init_Flag = STD_LOW;
	}
	else
	{
		/* do nothing */
	}
	if(init1 == STD_LOW)
	{
		init1 = STD_HIGH;
		I2cLcd_SendCommand(0x30);
	}
	else
	{
		/* do nothing */
	}
	if(init2 == STD_LOW)
	{
		init2 = STD_HIGH;
		I2cLcd_SendCommand(0x30);
	}
	else
	{
		/* do nothing */
	}
	if(init3 == STD_LOW)
	{
		init3 = STD_HIGH;
		I2cLcd_SendCommand(0x30);
	}
	else
	{
		/* do nothing */
	}
	if(init4 == STD_LOW)
	{
		init4 = STD_HIGH;
		I2cLcd_SendCommand(0x20);
	}
	else
	{
		/* do nothing */
	}
	if(init5 == STD_LOW)
	{
		init5 = STD_HIGH;
		I2cLcd_SendCommand(0x28);
	}
	else
	{
		/* do nothing */
	}
	if(init6 == STD_LOW)
	{
		init6 = STD_HIGH;
		I2cLcd_SendCommand(0x08);
	}
	else
	{
		/* do nothing */
	}
	if(init7 == STD_LOW)
	{
		init7 = STD_HIGH;
		I2cLcd_SendCommand(0x01);
	}
	else
	{
		/* do nothing */
	}
	if(init8 == STD_LOW)
	{
		init8 = STD_HIGH;
		I2cLcd_SendCommand(0x06);
	}
	else
	{
		/* do nothing */
	}
	if(init9 == STD_LOW)
	{
		init9 = STD_HIGH;
		I2cLcd_SendCommand(0x0C);
	}
	else
	{
		/* do nothing */
	}
	if(init1 == STD_HIGH && init2 == STD_HIGH && init3 == STD_HIGH
			&& init4 == STD_HIGH && init5 == STD_HIGH && init6 == STD_HIGH
			&& init7 == STD_HIGH && init8 == STD_HIGH && init9 == STD_HIGH)
	{
		I2cLcd_Clear();
		I2c_Lcd_Init_Flag = STD_HIGH;
	}
	else
	{
		/* do nothing */
	}
	return E_OK;
}
/***********************************************************************************
* END OF I2cLcd_Init										           	           *
************************************************************************************/
/***********************************************************************************
* Function: I2cLcd_SendCommand										   			   *
* Description: Driver command transmitting.									       *
************************************************************************************/
VOID I2cLcd_SendCommand(char cmd)
{
	char data_u, data_l;
	uint8 data_t[4];
	data_u = (cmd & 0xf0);
	data_l = ((cmd << 4) & 0xf0);
	data_t[0] = data_u | 0x0C;
	data_t[1] = data_u | 0x08;
	data_t[2] = data_l | 0x0C;
	data_t[3] = data_l | 0x08;
	HAL_I2C_Master_Transmit_IT(&hi2c1, I2CLCD_SLAVE_ADDRESS, (uint8 *) data_t, 4);
	vTaskSuspend(I2C_ISRHandle);
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
	char data_u, data_l;
	uint8 data_t[4];
	data_u = (data & 0xf0);
	data_l = ((data << 4) & 0xf0);
	data_t[0] = data_u | 0x0D;
	data_t[1] = data_u | 0x09;
	data_t[2] = data_l | 0x0D;
	data_t[3] = data_l | 0x09;
	HAL_I2C_Master_Transmit_IT(&hi2c1, I2CLCD_SLAVE_ADDRESS, (uint8 *) data_t, 4);
	vTaskSuspend(I2C_ISRHandle);
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
	for (uint8 i=0; i < 70; i++)
	{
		I2cLcd_SendData(' ');
	}
}
/***********************************************************************************
* END OF I2cLcd_Clear										           	           *
************************************************************************************/
