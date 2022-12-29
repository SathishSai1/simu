/*
 * IOInterface.c
 *
 * Created: 1/4/2013 3:14:46 PM
 *  Author: MSMANI
 */ 
#include "../Include/Include.h"

char CountAISlot = 0, CountAOSlot = 0;
short TotSlots = 0;
char ByteVal[4];

void UpdateIOs(char IOType)
{
	short			SlotNo, IoNo, Offset, BitShift;
	struct tIoTable *pIoTable = GiveIoTablePtr();
	
	for (SlotNo = 0; SlotNo < TotSlots; SlotNo++)
	{
		if ((IOType == IO_TYPE_INPUT  && (pIoTable[SlotNo].IoType == IO_TYPE_DI_32  || pIoTable[SlotNo].IoType == IO_TYPE_DM_16 || pIoTable[SlotNo].IoType == IO_TYPE_DI_64_1 || pIoTable[SlotNo].IoType == IO_TYPE_DI_64_2)) ||
		    (IOType == IO_TYPE_OUTPUT && (pIoTable[SlotNo].IoType == IO_TYPE_DO_16  || pIoTable[SlotNo].IoType == IO_TYPE_DM_16)))
		{
			ByteVal[0] = ByteVal[1] = ByteVal[2] = ByteVal[3] = 0;
			switch (pIoTable[SlotNo].IoType)
			{
				case IO_TYPE_DI_32	:
				case IO_TYPE_DI_64_1:   
									ByteVal[0] = *(pIoTable[SlotNo].SlotAddr + 0);
									ByteVal[1] = *(pIoTable[SlotNo].SlotAddr + 1);
									ByteVal[2] = *(pIoTable[SlotNo].SlotAddr + 2);
									ByteVal[3] = *(pIoTable[SlotNo].SlotAddr + 3);
									for (IoNo = 0; IoNo < 32; IoNo++)
									{
										Offset	 = IoNo/8;
										BitShift = IoNo - 8*Offset;
										if (pIoTable[SlotNo].Io[IoNo] != NULL)
											*pIoTable[SlotNo].Io[IoNo] = (ByteVal[Offset] & (0b00000001 << BitShift)) >> BitShift;
									}	
									break;
									
				case IO_TYPE_DI_64_2:   
									ByteVal[0] = *(pIoTable[SlotNo].SlotAddr + 4);
									ByteVal[1] = *(pIoTable[SlotNo].SlotAddr + 5);
									ByteVal[2] = *(pIoTable[SlotNo].SlotAddr + 6);
									ByteVal[3] = *(pIoTable[SlotNo].SlotAddr + 7);
									for (IoNo = 0; IoNo < 32; IoNo++)
									{
										Offset	 = IoNo/8;
										BitShift = IoNo - 8*Offset;
										if (pIoTable[SlotNo].Io[IoNo] != NULL)
											*pIoTable[SlotNo].Io[IoNo] = (ByteVal[Offset] & (0b00000001 << BitShift)) >> BitShift;
									}
									break;
									
				case IO_TYPE_DO_16	:
									for (IoNo = 0; IoNo < 16; IoNo++)
									{
										Offset	 = IoNo/8;
										BitShift = IoNo - 8*Offset;
										if (pIoTable[SlotNo].Io[IoNo] != NULL)
											ByteVal[Offset] += ((*pIoTable[SlotNo].Io[IoNo]) << BitShift);
									}
									*(pIoTable[SlotNo].SlotAddr + 0) = ByteVal[0];
									*(pIoTable[SlotNo].SlotAddr + 1) = ByteVal[1];
									break;
									
				case IO_TYPE_DM_16	:
									switch (IOType)
									{
										case IO_TYPE_INPUT	:
															ByteVal[0] = *(pIoTable[SlotNo].SlotAddr + 0);
															for (IoNo = 0; IoNo < 8; IoNo++)
																if (pIoTable[SlotNo].Io[IoNo] != NULL)
																	*pIoTable[SlotNo].Io[IoNo] = (ByteVal[0] & (0b00000001 << IoNo)) >> IoNo;
															break;
										case IO_TYPE_OUTPUT	: 	
															for (IoNo = 8; IoNo < 16; IoNo++)
																if (pIoTable[SlotNo].Io[IoNo] != NULL)
																	ByteVal[0] += ((*pIoTable[SlotNo].Io[IoNo]) << (IoNo-8));
															*(pIoTable[SlotNo].SlotAddr + 1) = ByteVal[0];
															break;
									}
									break;
			}			
		}
	}
}

void SwOFFOuputs(void)
{
	short			SlotNo, IoNo;
	struct tIoTable *pIoTable = GiveIoTablePtr();
	
	for (SlotNo = 0; SlotNo < TotSlots; SlotNo++)
	{
		switch (pIoTable[SlotNo].IoType)
		{
			case IO_TYPE_DO_16	:
				*(pIoTable[SlotNo].SlotAddr + 0) = 0;
				*(pIoTable[SlotNo].SlotAddr + 1) = 0;
				break;

			case IO_TYPE_DM_16	:
				*(pIoTable[SlotNo].SlotAddr + 1) = 0;
				break;
		}
	}
}

void InitIOs(void)
{
	struct tIoTable *pIoTable = GiveIoTablePtr();
	int Slot, Channel;

	TotSlots = GetTotSlot();
	for (Slot = 0; Slot < TotSlots; Slot++)
	{
		for (Channel = 0; Channel < 32; Channel++)
		{
			if (pIoTable[Slot].Io[Channel] != NULL)
				*pIoTable[Slot].Io[Channel] = 0;
		}
	}	
	
}
