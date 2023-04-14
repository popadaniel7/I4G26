/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: Standard Types	     		 *
******************************************/
#ifndef Std_Types_H
#define Std_Types_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "stdint.h"
#include "string.h"
/*****************************************
		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Standard define */
#define E_NOT_OK 		1
/* Standard define */
#define E_OK 			0
/* Standard define */
#define NULL_PTR 		0
/* Standard define */
#define STD_HIGH		0x01
/* Standard define */
#define STD_LOW			0x00
/* Standard define */
#define STD_ACTIVE		0x01
/* Standard define */
#define STD_IDLE		0x00
/* Standard define */
#define STD_ON			0x01
/* Standard define */
#define STD_OFF			0x00
/* Standard define */
#define EXTERN 			extern
/* Standard define */
#define STATIC			static
/* Standard define */
#define FLOAT			float
/* Standard define */
#define VOID			void
/* Standard define */
#define MIN(_x,_y) 		(((_x) < (_y)) ? (_x) : (_y))
/* Standard define */
#define MAX(_x,_y) 		(((_x) > (_y)) ? (_x) : (_y))
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Standard data type */
typedef uint8_t uint8;
/* Standard data type */
typedef uint16_t uint16;
/* Standard data type */
typedef uint32_t uint32;
/* Standard data type */
typedef uint8 StdReturnType;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
#endif /* Std_Types_H */
