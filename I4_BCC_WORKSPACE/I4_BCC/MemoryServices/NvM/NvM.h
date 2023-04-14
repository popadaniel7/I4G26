/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Non-volatile Memory Managaer	 *
******************************************/
#ifndef NvM_H
#define NvM_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "Std_Types.h"
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
EXTERN uint32 NvM_BswState;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Function declaration for initialization. */
EXTERN StdReturnType NvM_Init();
/* Function declaration for de-initialization. */
EXTERN StdReturnType NvM_DeInit();
/* Function declaration for the main function. */
EXTERN VOID NvM_MainFunction();
/* Function declaration for writing into memory. */
EXTERN StdReturnType NvM_Write(uint16 page, uint16 offset, uint8 *data, uint16 size);
/* Function declaration for reading from memory. */
EXTERN StdReturnType NvM_Read(uint16 page, uint16 offset, uint8 *data, uint16 size);
/* Function declaration for erasing a page from memory. */
EXTERN StdReturnType NvM_PageErase(uint16 page);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* NvM_H */