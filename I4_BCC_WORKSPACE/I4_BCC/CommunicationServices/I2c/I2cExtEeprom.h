/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Inter Integrated Circuit       *
* 		  External Eeprom Driver         *
******************************************/
#ifndef I2cExtEeprom_H
#define I2cExtEeprom_H
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
/* Memory address peripheral. */
#define I2C_EXTEEPROM_ADDR 			0xA0
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
/* Function declaration for initialization. */
EXTERN StdReturnType I2cExtEeprom_Init();
/* Function declaration for de-initialization. */
EXTERN StdReturnType I2cExtEeprom_DeInit();
/* Function declaration for writing into memory. */
EXTERN VOID I2cExtEeprom_Write(uint16 page, uint16 offset, uint8 *data, uint16 size);
/* Function declaration for reading from memory. */
EXTERN VOID I2cExtEeprom_Read(uint16 page, uint16 offset, uint8 *data, uint16 size);
/* Function declaration for erasing a page from memory. */
EXTERN VOID I2cExtEeprom_PageErase(uint16 page);
/* Function declaration for read all. */
EXTERN VOID I2cExtEeprom_ReadAll();
/* Function declaration for write all. */
EXTERN VOID I2cExtEeprom_WriteAll();
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* I2cExtEeprom_H */
