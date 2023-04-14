/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Serial Peripheral	Interface    *
******************************************/
#ifndef SpiH_H
#define SpiH_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "spi.h"
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
/* Module main function. */
EXTERN VOID Spi_MainFunction();
/* Module initialization. */
EXTERN StdReturnType Spi_Init();
/* Module de-initialization. */
EXTERN StdReturnType Spi_DeInit();
/* Module error callback. */
EXTERN VOID HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* SpiH_H */
