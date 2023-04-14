/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Inter Integrated Circuit       *
* 		  Liquid Crystal Display Driver  *
******************************************/
#ifndef I2cLcd_H
#define I2cLcd_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
#include "I2cH.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
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
EXTERN StdReturnType I2cLcd_Init();
/* Function declaration for I2C LCD driver de-initialization. */
EXTERN StdReturnType I2cLcd_DeInit();
/* Function declaration for command transmitting. */
EXTERN VOID I2cLcd_SendCommand(char cmd);
/* Function declaration for data transmitting. */
EXTERN VOID I2cLcd_SendData(char data);
/* Function declaration for string transmitting. */
EXTERN VOID I2cLcd_SendString(char *str);
/* Function declaration for setting the position on the LCD. */
EXTERN VOID I2cLcd_SetCursor(int row, int col);
/* Function declaration for clearing the LCD. */
EXTERN VOID I2cLcd_Clear();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* I2cLcd_H */
