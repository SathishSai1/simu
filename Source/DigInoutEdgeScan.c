/*
 * DigInEdgeScan.c
 *
 * Created: 1/29/2013 2:36:06 PM
 *  Author: avm
 */ 

#include "Include/Include.h"

int	TotEdgeScans = 0;
struct tDigInOutEdgeScan DigInOutEdgeScan[] = 
{

};

void InitEdgeScan(void)
{
	TotEdgeScans = sizeof(DigInOutEdgeScan) / sizeof(struct tDigInOutEdgeScan);
}

void ScanDigInOut(void)
{
	int i;
	for (i = 0; i < TotEdgeScans; i++)
	{
		if (DigInOutEdgeScan[i].pDigIn != NULL)
		{
			if (*DigInOutEdgeScan[i].pDigIn != DigInOutEdgeScan[i].OldValue)
			{
				DigInOutEdgeScan[i].OldValue = *DigInOutEdgeScan[i].pDigIn;
				if (DigInOutEdgeScan[i].pDigInOutFunc != NULL)
					DigInOutEdgeScan[i].pDigInOutFunc(*DigInOutEdgeScan[i].pDigIn);
			}
		}			
	}
}
