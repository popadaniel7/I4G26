#include "main.h"
#include <stdbool.h>
#include "Std_Types.h"

#define MCP2515_CanOverSpi_RESET           	0xC0
#define MCP2515_CanOverSpi_READ            	0x03
#define MCP2515_CanOverSpi_READ_RXB0SIDH   	0x90
#define MCP2515_CanOverSpi_READ_RXB0D0     	0x92
#define MCP2515_CanOverSpi_READ_RXB1SIDH   	0x94
#define MCP2515_CanOverSpi_READ_RXB1D0     	0x96
#define MCP2515_CanOverSpi_WRITE           	0x02
#define MCP2515_CanOverSpi_LOAD_TXB0SIDH   	0x40
#define MCP2515_CanOverSpi_LOAD_TXB0D0     	0x41
#define MCP2515_CanOverSpi_LOAD_TXB1SIDH   	0x42
#define MCP2515_CanOverSpi_LOAD_TXB1D0     	0x43
#define MCP2515_CanOverSpi_LOAD_TXB2SIDH   	0x44
#define MCP2515_CanOverSpi_LOAD_TXB2D0     	0x45
#define MCP2515_CanOverSpi_RTS_TX0         	0x81
#define MCP2515_CanOverSpi_RTS_TX1         	0x82
#define MCP2515_CanOverSpi_RTS_TX2         	0x84
#define MCP2515_CanOverSpi_RTS_ALL         	0x87
#define MCP2515_CanOverSpi_READ_STATUS     	0xA0
#define MCP2515_CanOverSpi_RX_STATUS       	0xB0
#define MCP2515_CanOverSpi_BIT_MOD         	0x05
#define MCP2515_CanOverSpi_RXF0SIDH			0x00
#define MCP2515_CanOverSpi_RXF0SIDL			0x01
#define MCP2515_CanOverSpi_RXF0EID8			0x02
#define MCP2515_CanOverSpi_RXF0EID0			0x03
#define MCP2515_CanOverSpi_RXF1SIDH			0x04
#define MCP2515_CanOverSpi_RXF1SIDL			0x05
#define MCP2515_CanOverSpi_RXF1EID8			0x06
#define MCP2515_CanOverSpi_RXF1EID0			0x07
#define MCP2515_CanOverSpi_RXF2SIDH			0x08
#define MCP2515_CanOverSpi_RXF2SIDL			0x09
#define MCP2515_CanOverSpi_RXF2EID8			0x0A
#define MCP2515_CanOverSpi_RXF2EID0			0x0B
#define MCP2515_CanOverSpi_BFPCTRL     		0x0C
#define MCP2515_CanOverSpi_TXRTSCTRL   		0x0D
#define MCP2515_CanOverSpi_CANSTAT			0x0E
#define MCP2515_CanOverSpi_CANCTRL			0x0F
#define MCP2515_CanOverSpi_RXF3SIDH			0x10
#define MCP2515_CanOverSpi_RXF3SIDL			0x11
#define MCP2515_CanOverSpi_RXF3EID8			0x12
#define MCP2515_CanOverSpi_RXF3EID0			0x13
#define MCP2515_CanOverSpi_RXF4SIDH			0x14
#define MCP2515_CanOverSpi_RXF4SIDL			0x15
#define MCP2515_CanOverSpi_RXF4EID8			0x16
#define MCP2515_CanOverSpi_RXF4EID0			0x17
#define MCP2515_CanOverSpi_RXF5SIDH			0x18
#define MCP2515_CanOverSpi_RXF5SIDL			0x19
#define MCP2515_CanOverSpi_RXF5EID8			0x1A
#define MCP2515_CanOverSpi_RXF5EID0			0x1B
#define MCP2515_CanOverSpi_TEC		    	0x1C
#define MCP2515_CanOverSpi_REC		    	0x1D
#define MCP2515_CanOverSpi_RXM0SIDH			0x20
#define MCP2515_CanOverSpi_RXM0SIDL			0x21
#define MCP2515_CanOverSpi_RXM0EID8			0x22
#define MCP2515_CanOverSpi_RXM0EID0			0x23
#define MCP2515_CanOverSpi_RXM1SIDH			0x24
#define MCP2515_CanOverSpi_RXM1SIDL			0x25
#define MCP2515_CanOverSpi_RXM1EID8			0x26
#define MCP2515_CanOverSpi_RXM1EID0			0x27
#define MCP2515_CanOverSpi_CNF3				0x28
#define MCP2515_CanOverSpi_CNF2				0x29
#define MCP2515_CanOverSpi_CNF1				0x2A
#define MCP2515_CanOverSpi_CANINTE			0x2B
#define MCP2515_CanOverSpi_CANINTF			0x2C
#define MCP2515_CanOverSpi_EFLG				0x2D
#define MCP2515_CanOverSpi_TXB0CTRL			0x30
#define MCP2515_CanOverSpi_TXB0SIDH    		0x31
#define MCP2515_CanOverSpi_TXB1CTRL			0x40
#define MCP2515_CanOverSpi_TXB1SIDH    		0x41
#define MCP2515_CanOverSpi_TXB2CTRL			0x50
#define MCP2515_CanOverSpi_TXB2SIDH    		0x51
#define MCP2515_CanOverSpi_RXB0CTRL			0x60
#define MCP2515_CanOverSpi_RXB0SIDH			0x61
#define MCP2515_CanOverSpi_RXB1CTRL			0x70
#define MCP2515_CanOverSpi_RXB1SIDH			0x71
#define MSG_IN_RXB0             			0x01
#define MSG_IN_RXB1             			0x02
#define MSG_IN_BOTH_BUFFERS     			0x03
#define MODE_NORMAL     					0x00
#define MODE_SLEEP     					    0x20
#define MODE_CONFIG     					0x80
#define MODE_MASK       					0xE0

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

typedef struct
{

	uint8 RXF0SIDH;
	uint8 RXF0SIDL;
	uint8 RXF0EID8;
	uint8 RXF0EID0;

}RXF0;

typedef struct
{

	uint8 RXF1SIDH;
	uint8 RXF1SIDL;
	uint8 RXF1EID8;
	uint8 RXF1EID0;

}RXF1;

typedef struct
{

	uint8 RXF2SIDH;
	uint8 RXF2SIDL;
	uint8 RXF2EID8;
	uint8 RXF2EID0;

}RXF2;

typedef struct
{

	uint8 RXF3SIDH;
	uint8 RXF3SIDL;
	uint8 RXF3EID8;
	uint8 RXF3EID0;

}RXF3;

typedef struct
{

	uint8 RXF4SIDH;
	uint8 RXF4SIDL;
	uint8 RXF4EID8;
	uint8 RXF4EID0;

}RXF4;

typedef struct
{

	uint8 RXF5SIDH;
	uint8 RXF5SIDL;
	uint8 RXF5EID8;
	uint8 RXF5EID0;

}RXF5;

typedef struct
{

	uint8 RXM0SIDH;
	uint8 RXM0SIDL;
	uint8 RXM0EID8;
	uint8 RXM0EID0;

}RXM0;

typedef struct
{

	uint8 RXM1SIDH;
	uint8 RXM1SIDL;
	uint8 RXM1EID8;
	uint8 RXM1EID0;

}RXM1;

typedef struct
{

	uint8 tempSIDH;
	uint8 tempSIDL;
	uint8 tempEID8;
	uint8 tempEID0;

}id_reg_t;

EXTERN StdReturnType MCP2515_CanOverSpi_Initialize();
EXTERN StdReturnType MCP2515_CanOverSpi_SetConfigMode();
EXTERN StdReturnType MCP2515_CanOverSpi_SetNormalMode();
EXTERN StdReturnType MCP2515_CanOverSpi_ReadByte(uint8 address);
EXTERN StdReturnType MCP2515_CanOverSpi_ReadStatus();
EXTERN StdReturnType MCP2515_CanOverSpi_GetRxStatus();
EXTERN void MCP2515_CanOverSpi_Reset();
EXTERN void MCP2515_CanOverSpi_ReadRxSequence(uint8 instruction, uint8 *data, uint8 length);
EXTERN void MCP2515_CanOverSpi_WriteByte(uint8 address, uint8 data);
EXTERN void MCP2515_CanOverSpi_WriteByteSequence(uint8 startAddress, uint8 endAddress, uint8 *data);
EXTERN void MCP2515_CanOverSpi_LoadTxSequence(uint8 instruction, uint8 *idReg, uint8 dlc, uint8 *data);
EXTERN void MCP2515_CanOverSpi_LoadTxBuffer(uint8 instruction, uint8 data);
EXTERN void MCP2515_CanOverSpi_RequestToSend(uint8 instruction);
EXTERN void MCP2515_CanOverSpi_BitModify(uint8 address, uint8 mask, uint8 data);
