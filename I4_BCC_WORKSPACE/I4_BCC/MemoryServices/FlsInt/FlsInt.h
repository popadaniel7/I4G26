#include "stdint.h"
#include "Std_Types.h"

EXTERN uint32 FlsInt_Write(uint32 StartSectorAddress, uint32 *Data, uint16 numberofwords);
EXTERN void FlsInt_Read(uint32 StartSectorAddress, uint32 *RxBuf, uint16 numberofwords);
EXTERN void FlsInt_ConvertToStr(uint32 *Data, char *Buf);
EXTERN void FlsInt_WriteNum(uint32 StartSectorAddress, float Num);
EXTERN float FlsInt_ReadNum(uint32 StartSectorAddress);
