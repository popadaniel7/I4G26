/*****************************************
* Project: BCM I4						 *
* Developer: Daniel Popa				 *
* Module: MCP SPI Driver	     		 *
******************************************/
#ifndef McpSpi_H
#define McpSpi_H
/*****************************************
*		INCLUDE PATHS					 *
******************************************/
#include "main.h"
#include <stdbool.h>
#include "Std_Types.h"
/*****************************************
*		END OF INCLUDE PATHS		     *
******************************************/
/*****************************************
*		DEFINES					 		 *
******************************************/
/* Driver specific define. */
#define MCP2515_CanOverSpi_RESET           	0xC0
/* Driver specific define. */
#define MCP2515_CanOverSpi_READ            	0x03
/* Driver specific define. */
#define MCP2515_CanOverSpi_READ_RXB0SIDH   	0x90
/* Driver specific define. */
#define MCP2515_CanOverSpi_READ_RXB0D0     	0x92
/* Driver specific define. */
#define MCP2515_CanOverSpi_READ_RXB1SIDH   	0x94
/* Driver specific define. */
#define MCP2515_CanOverSpi_READ_RXB1D0     	0x96
/* Driver specific define. */
#define MCP2515_CanOverSpi_WRITE           	0x02
/* Driver specific define. */
#define MCP2515_CanOverSpi_LOAD_TXB0SIDH   	0x40
/* Driver specific define. */
#define MCP2515_CanOverSpi_LOAD_TXB0D0     	0x41
/* Driver specific define. */
#define MCP2515_CanOverSpi_LOAD_TXB1SIDH   	0x42
/* Driver specific define. */
#define MCP2515_CanOverSpi_LOAD_TXB1D0     	0x43
/* Driver specific define. */
#define MCP2515_CanOverSpi_LOAD_TXB2SIDH   	0x44
/* Driver specific define. */
#define MCP2515_CanOverSpi_LOAD_TXB2D0     	0x45
/* Driver specific define. */
#define MCP2515_CanOverSpi_RTS_TX0         	0x81
/* Driver specific define. */
#define MCP2515_CanOverSpi_RTS_TX1         	0x82
/* Driver specific define. */
#define MCP2515_CanOverSpi_RTS_TX2         	0x84
/* Driver specific define. */
#define MCP2515_CanOverSpi_RTS_ALL         	0x87
/* Driver specific define. */
#define MCP2515_CanOverSpi_READ_STATUS     	0xA0
/* Driver specific define. */
#define MCP2515_CanOverSpi_RX_STATUS       	0xB0
/* Driver specific define. */
#define MCP2515_CanOverSpi_BIT_MOD         	0x05
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF0SIDH			0x00
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF0SIDL			0x01
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF0EID8			0x02
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF0EID0			0x03
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF1SIDH			0x04
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF1SIDL			0x05
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF1EID8			0x06
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF1EID0			0x07
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF2SIDH			0x08
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF2SIDL			0x09
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF2EID8			0x0A
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF2EID0			0x0B
/* Driver specific define. */
#define MCP2515_CanOverSpi_BFPCTRL     		0x0C
/* Driver specific define. */
#define MCP2515_CanOverSpi_TXRTSCTRL   		0x0D
/* Driver specific define. */
#define MCP2515_CanOverSpi_CANSTAT			0x0E
/* Driver specific define. */
#define MCP2515_CanOverSpi_CANCTRL			0x0F
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF3SIDH			0x10
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF3SIDL			0x11
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF3EID8			0x12
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF3EID0			0x13
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF4SIDH			0x14
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF4SIDL			0x15
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF4EID8			0x16
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF4EID0			0x17
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF5SIDH			0x18
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF5SIDL			0x19
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF5EID8			0x1A
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXF5EID0			0x1B
/* Driver specific define. */
#define MCP2515_CanOverSpi_TEC		    	0x1C
/* Driver specific define. */
#define MCP2515_CanOverSpi_REC		    	0x1D
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXM0SIDH			0x20
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXM0SIDL			0x21
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXM0EID8			0x22
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXM0EID0			0x23
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXM1SIDH			0x24
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXM1SIDL			0x25
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXM1EID8			0x26
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXM1EID0			0x27
/* Driver specific define. */
#define MCP2515_CanOverSpi_CNF3				0x28
/* Driver specific define. */
#define MCP2515_CanOverSpi_CNF2				0x29
/* Driver specific define. */
#define MCP2515_CanOverSpi_CNF1				0x2A
/* Driver specific define. */
#define MCP2515_CanOverSpi_CANINTE			0x2B
/* Driver specific define. */
#define MCP2515_CanOverSpi_CANINTF			0x2C
/* Driver specific define. */
#define MCP2515_CanOverSpi_EFLG				0x2D
/* Driver specific define. */
#define MCP2515_CanOverSpi_TXB0CTRL			0x30
/* Driver specific define. */
#define MCP2515_CanOverSpi_TXB0SIDH    		0x31
/* Driver specific define. */
#define MCP2515_CanOverSpi_TXB1CTRL			0x40
/* Driver specific define. */
#define MCP2515_CanOverSpi_TXB1SIDH    		0x41
/* Driver specific define. */
#define MCP2515_CanOverSpi_TXB2CTRL			0x50
/* Driver specific define. */
#define MCP2515_CanOverSpi_TXB2SIDH    		0x51
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXB0CTRL			0x60
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXB0SIDH			0x61
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXB1CTRL			0x70
/* Driver specific define. */
#define MCP2515_CanOverSpi_RXB1SIDH			0x71
/* Driver specific define. */
#define MSG_IN_RXB0             			0x01
/* Driver specific define. */
#define MSG_IN_RXB1             			0x02
/* Driver specific define. */
#define MSG_IN_BOTH_BUFFERS     			0x03
/* Driver specific define. */
#define MODE_NORMAL     					0x00
/* Driver specific define. */
#define MODE_SLEEP     					    0x20
/* Driver specific define. */
#define MODE_CONFIG     					0x80
/* Driver specific define. */
#define MODE_MASK       					0xE0
/*****************************************
* 		END OF DEFINES					 *
******************************************/
/*****************************************
*		VARIABLES					 	 *
******************************************/
/* Register data type used for transceiver control. */
typedef union
{
	struct
	{
		unsigned RX0IF      : 1;
		unsigned RX1IF      : 1;
		unsigned TXB0REQ    : 1;
		unsigned TX0IF      : 1;
		unsigned TXB1REQ    : 1;
		unsigned TX1IF      : 1;
		unsigned TXB2REQ    : 1;
		unsigned TX2IF      : 1;
	};
	uint8 ctrl_status;
}ctrl_status_t;
/* Message data type used for protocol control. */
typedef union
{
	struct
	{
		unsigned filter     : 3;
		unsigned msgType    : 2;
		unsigned unusedBit  : 1;
		unsigned rxBuffer   : 2;
	};
	uint8 ctrl_rx_status;
}ctrl_rx_status_t;
/* Data type used for protocol error. */
typedef union
{
	struct
	{
		unsigned EWARN      :1;
		unsigned RXWAR      :1;
		unsigned TXWAR      :1;
		unsigned RXEP       :1;
		unsigned TXEP       :1;
		unsigned TXBO       :1;
		unsigned RX0OVR     :1;
		unsigned RX1OVR     :1;
	};
	uint8 error_flag_reg;
}ctrl_error_status_t;
/* Register receive data type. */
typedef union
{
	struct
	{
		uint8 RXBnSIDH;
		uint8 RXBnSIDL;
		uint8 RXBnEID8;
		uint8 RXBnEID0;
		uint8 RXBnDLC;
		uint8 RXBnD0;
		uint8 RXBnD1;
		uint8 RXBnD2;
		uint8 RXBnD3;
		uint8 RXBnD4;
		uint8 RXBnD5;
		uint8 RXBnD6;
		uint8 RXBnD7;
	};
	uint8 rx_reg_array[13];
}rx_reg_t;
/* Register data type. */
typedef struct
{
	uint8 RXF0SIDH;
	uint8 RXF0SIDL;
	uint8 RXF0EID8;
	uint8 RXF0EID0;
}RXF0;
/* Register data type. */
typedef struct
{
	uint8 RXF1SIDH;
	uint8 RXF1SIDL;
	uint8 RXF1EID8;
	uint8 RXF1EID0;
}RXF1;
/* Register data type. */
typedef struct
{
	uint8 RXF2SIDH;
	uint8 RXF2SIDL;
	uint8 RXF2EID8;
	uint8 RXF2EID0;
}RXF2;
/* Register data type. */
typedef struct
{
	uint8 RXF3SIDH;
	uint8 RXF3SIDL;
	uint8 RXF3EID8;
	uint8 RXF3EID0;
}RXF3;
/* Register data type. */
typedef struct
{
	uint8 RXF4SIDH;
	uint8 RXF4SIDL;
	uint8 RXF4EID8;
	uint8 RXF4EID0;
}RXF4;
/* Register data type. */
typedef struct
{
	uint8 RXF5SIDH;
	uint8 RXF5SIDL;
	uint8 RXF5EID8;
	uint8 RXF5EID0;
}RXF5;
/* Register data type. */
typedef struct
{
	uint8 RXM0SIDH;
	uint8 RXM0SIDL;
	uint8 RXM0EID8;
	uint8 RXM0EID0;
}RXM0;
/* Register data type. */
typedef struct
{
	uint8 RXM1SIDH;
	uint8 RXM1SIDL;
	uint8 RXM1EID8;
	uint8 RXM1EID0;
}RXM1;
/* Register data type. */
typedef struct
{
	uint8 tempSIDH;
	uint8 tempSIDL;
	uint8 tempEID8;
	uint8 tempEID0;
}id_reg_t;
/*****************************************
*		END OF VARIABLES				 *
******************************************/
/*****************************************
*		FUNCTIONS				 		 *
******************************************/
/* Driver initialization. */
EXTERN StdReturnType MCP2515_CanOverSpi_Initialize();
/* Driver configuration mode.  */
EXTERN StdReturnType MCP2515_CanOverSpi_SetConfigMode();
/* Driver configuration mode. */
EXTERN StdReturnType MCP2515_CanOverSpi_SetNormalMode();
/* Driver read byte from message. */
EXTERN StdReturnType MCP2515_CanOverSpi_ReadByte(uint8 address);
/* Driver read status function. */
EXTERN StdReturnType MCP2515_CanOverSpi_ReadStatus();
/* Driver get rx bus status. */
EXTERN StdReturnType MCP2515_CanOverSpi_GetRxStatus();
/* Driver bus reset. */
EXTERN VOID MCP2515_CanOverSpi_Reset();
/* Driver received message reading sequence. */
EXTERN VOID MCP2515_CanOverSpi_ReadRxSequence(uint8 instruction, uint8 *data, uint8 length);
/* Driver byte message writing. */
EXTERN VOID MCP2515_CanOverSpi_WriteByte(uint8 address, uint8 data);
/* Driver message writing sequence. */
EXTERN VOID MCP2515_CanOverSpi_WriteByteSequence(uint8 startAddress, uint8 endAddress, uint8 *data);
/* Driver message to be transmitted loading sequence. */
EXTERN VOID MCP2515_CanOverSpi_LoadTxSequence(uint8 instruction, uint8 *idReg, uint8 dlc, uint8 *data);
/* Driver message to be transmitted loading sequence. */
EXTERN VOID MCP2515_CanOverSpi_LoadTxBuffer(uint8 instruction, uint8 data);
/* Driver bus request to send message. */
EXTERN VOID MCP2515_CanOverSpi_RequestToSend(uint8 instruction);
/* Driver message characteristic for bus sending. */
EXTERN VOID MCP2515_CanOverSpi_BitModify(uint8 address, uint8 mask, uint8 data);
/*****************************************
*		END OF FUNCTIONS				 *
******************************************/
#endif /* McpSpi_H */
