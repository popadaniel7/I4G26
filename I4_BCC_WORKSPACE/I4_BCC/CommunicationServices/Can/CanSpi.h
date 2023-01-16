#ifndef CAN_SPI_H
#define	CAN_SPI_H

#include "main.h"
#include <stdbool.h>
#include "Std_Types.h"

typedef union {
  struct {
    uint8_t idType;
    uint32_t id;
    uint8_t dlc;
    uint8_t data0;
    uint8_t data1;
    uint8_t data2;
    uint8_t data3;
    uint8_t data4;
    uint8_t data5;
    uint8_t data6;
    uint8_t data7;
  } frame;
  uint8_t array[14];
} uCAN_MSG;

#define CMD_STANDARD_CAN_MSG_ID 0
#define CMD_EXTENDED_CAN_MSG_ID 1

#define EXTENDED_CAN_MSG_ID_2_0B 2

EXTERN bool CANSPI_Initialize(void);
EXTERN bool CANSPI_Init_Mask(uint8_t num, uint8_t ext, uint32_t id);
EXTERN bool CANSPI_Init_Filter(uint8_t num, uint8_t ext, uint32_t id);
EXTERN uint8_t CANSPI_Transmit(uCAN_MSG *tempCanMsg);
EXTERN uint8_t CANSPI_Receive(uCAN_MSG *tempCanMsg);
EXTERN uint8_t CANSPI_messagesInBuffer(void);
EXTERN uint8_t CANSPI_isBussOff(void);
EXTERN uint8_t CANSPI_isRxErrorPassive(void);
EXTERN uint8_t CANSPI_isTxErrorPassive(void);

#endif	/* CAN_SPI_H */