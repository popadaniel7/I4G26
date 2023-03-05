#include "stdint.h"
#include "string.h"

#define E_OK 			0
#define E_NOT_OK 		1
#define NULL_PTR 		0
#define STD_HIGH		0x01
#define STD_LOW			0x00
#define STD_ACTIVE		0x01
#define STD_IDLE		0x00
#define STD_ON			0x03
#define STD_OFF			0x04
#define EXTERN 			extern
#define MIN(_x,_y) 		(((_x) < (_y)) ? (_x) : (_y))
#define MAX(_x,_y) 		(((_x) > (_y)) ? (_x) : (_y))

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint8 StdReturnType;
