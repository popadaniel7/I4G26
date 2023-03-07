#include "FlsInt.h"
#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"

uint32 FlsInt_Write(uint32 StartSectorAddress, uint32 *Data, uint16 numberofwords);
void FlsInt_Read(uint32 StartSectorAddress, uint32 *RxBuf, uint16 numberofwords);
void FlsInt_ConvertToStr(uint32 *Data, char *Buf);
void FlsInt_WriteNum(uint32 StartSectorAddress, float Num);
float FlsInt_ReadNum(uint32 StartSectorAddress);
static uint32 FlsInt_GetSector(uint32 Address);
float FlsInt_BytesToFloat(uint8* ftoa_bytes_temp);
void FlsInt_FloatToBytes(uint8 * ftoa_bytes_temp, float float_variable);

uint8 FlsInt_Bytes_temp[4];

static uint32 FlsInt_GetSector(uint32 Address)
{

	uint32 sector = 0;

	if((Address < 0x08003FFF) && (Address >= 0x08000000))
	{

	sector = FLASH_SECTOR_0;

	}
	else if((Address < 0x08007FFF) && (Address >= 0x08004000))
	{

	sector = FLASH_SECTOR_1;

	}
	else if((Address < 0x0800BFFF) && (Address >= 0x08008000))
	{

	sector = FLASH_SECTOR_2;

	}
	else if((Address < 0x0800FFFF) && (Address >= 0x0800C000))
	{

	sector = FLASH_SECTOR_3;

	}
	else if((Address < 0x0801FFFF) && (Address >= 0x08010000))
	{

	sector = FLASH_SECTOR_4;

	}
	else if((Address < 0x0803FFFF) && (Address >= 0x08020000))
	{

	sector = FLASH_SECTOR_5;

	}
	else if((Address < 0x0805FFFF) && (Address >= 0x08040000))
	{

	sector = FLASH_SECTOR_6;

	}
	else if((Address < 0x0807FFFF) && (Address >= 0x08060000))
	{

	sector = FLASH_SECTOR_7;

	}
	else
	{

	  /* do nothing */

	}

	return sector;

}

void FlsInt_FloatToBytes(uint8 * ftoa_bytes_temp, float float_variable)
{

	union
	{

	  float a;
	  uint8_t bytes[4];

	}stmem;

	stmem.a = float_variable;

	for (uint8_t i = 0; i < 4; i++)
	{

	  ftoa_bytes_temp[i] = stmem.bytes[i];

	}

}

float FlsInt_BytesToFloat(uint8* ftoa_bytes_temp)
{

	union
	{

	  float a;
	  uint8_t bytes[4];

	}stmem;

	for (uint8 i = 0; i < 4; i++)
	{

		stmem.bytes[i] = ftoa_bytes_temp[i];

	}

	float float_variable =  stmem.a;

	return float_variable;

}


uint32 FlsInt_Write(uint32 StartSectorAddress, uint32 *Data, uint16 numberofwords)
{

	static FLASH_EraseInitTypeDef EraseInitStruct;
	uint32 SECTORError;
	int counter = 0;

	HAL_FLASH_Unlock();

	uint32 StartSector = FlsInt_GetSector(StartSectorAddress);
	uint32 EndSectorAddress = StartSectorAddress + numberofwords*4;
	uint32 EndSector =  FlsInt_GetSector(EndSectorAddress);

	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector        = StartSector;
	EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;


	if(HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
	{

	  return HAL_FLASH_GetError();

	}
	else
	{

	  /* do nothing */

	}

	while (counter < numberofwords)
	{

	 if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, StartSectorAddress, Data[counter]) == HAL_OK)
	 {

		 StartSectorAddress += 4;
		 counter++;

	 }
	 else
	 {

		 return HAL_FLASH_GetError();

	 }

	}


	HAL_FLASH_Lock();

	return 0;

}


void FlsInt_Read(uint32 StartSectorAddress, uint32 *RxBuf, uint16 numberofwords)
{

	while (1)
	{

		*RxBuf = *(__IO uint32 *)StartSectorAddress;
		StartSectorAddress += 4;
		RxBuf++;

		if (!(numberofwords--))
		{

			break;

		}
		else
		{

			/* do nothing */

		}

	}

}

void FlsInt_ConvertToStr(uint32 *Data, char *Buf)
{

	int numberofbytes = ((strlen((char *)Data) / 4) + ((strlen((char *)Data) % 4) != 0)) * 4;

	for (int i=0; i < numberofbytes; i++)
	{

		Buf[i] = Data[i / 4] >> ( 8 * (i % 4));

	}

}

void FlsInt_WriteNum(uint32 StartSectorAddress, float Num)
{

	FlsInt_FloatToBytes(FlsInt_Bytes_temp, Num);

	FlsInt_Write(StartSectorAddress, (uint32*)FlsInt_Bytes_temp, 1);

}

float FlsInt_ReadNum(uint32 StartSectorAddress)
{

	uint8 buffer[4];
	float value;

	FlsInt_Read(StartSectorAddress, (uint32*)buffer, 1);

	value =  FlsInt_BytesToFloat(buffer);

	return value;

}
