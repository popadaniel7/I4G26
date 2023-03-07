#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "Std_Types.h"

EXTERN I2C_HandleTypeDef hi2c1;

EXTERN void FlsEeprom_Write(uint16 page, uint16 offset, uint8 *data, uint16 size);
EXTERN void FlsEeprom_Read(uint16 page, uint16 offset, uint8 *data, uint16 size);
EXTERN void FlsEeprom_PageErase(uint16 page);
EXTERN void FlsEeprom_Write_Num(uint16 page, uint16 offset, float  fdata);
EXTERN float FlsEeprom_Read_Num(uint16 page, uint16 offset);
