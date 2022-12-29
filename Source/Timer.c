/*
 * Timer.c
 *
 * Created: 1/29/2013 12:04:15 PM
 *  Author: avm
 */ 

#include "../Include/Include.h"

struct tTimer	Timer[MAX_TIMER];
int			TimerIndex = 0;

void InitTimer(void)
{
	memset(&Timer, 0, sizeof(Timer));
}

int TimerInstall(unsigned int Duration, void* pFct, bool bRepeat)
{
	char TimerID = -1;
	if (pFct == NULL)
		return TimerID;
	
	for (TimerIndex = 0; TimerIndex < MAX_TIMER; TimerIndex++)
	{
		if (Timer[TimerIndex].bUsed == false)
		{
			Timer[TimerIndex].ActTime = 0;
			Timer[TimerIndex].bRepeat = bRepeat;
			Timer[TimerIndex].Duration = Duration;
			Timer[TimerIndex].pFct = pFct;
			Timer[TimerIndex].TimeStamp = Get_ops_tAbsolute();
			Timer[TimerIndex].bUsed = true;
			TimerID = TimerIndex;
			break;
		}
	}
	return TimerID;
}

void TimerUninstall(int TimerID)
{
	if ((TimerID < 0) || (TimerID >= MAX_TIMER))
		return;
		
	Timer[TimerID].ActTime = 0;
	Timer[TimerID].bRepeat = false;
	Timer[TimerID].Duration = 0;
	Timer[TimerID].pFct = NULL;
	Timer[TimerID].TimeStamp = 0;
	Timer[TimerID].bUsed = false;
}

unsigned int TimerGetPassedTime(int TimerID)
{
	if ((TimerID < 0) || (TimerID >= MAX_TIMER) || (Timer[TimerID].bUsed == false))
		return 0;
	
	return (Get_ops_tAbsolute() - Timer[TimerID].TimeStamp);
}

unsigned int TimerGetRemainTime(int TimerID)
{
	if ((TimerID < 0) || (TimerID >= MAX_TIMER) || (Timer[TimerID].bUsed == false))
		return 0;
		
	return (Timer[TimerID].Duration -(Get_ops_tAbsolute() - Timer[TimerID].TimeStamp));
}

bool TimerNewDuration(int TimerID, unsigned int NewDuration)
{
	if ((TimerID < 0) || (TimerID >= MAX_TIMER) || (Timer[TimerID].bUsed == false))
		return false;
		
	Timer[TimerID].Duration = NewDuration;
	return true;
}

unsigned int TimerGetTimeStamp(int TimerID)
{
	if ((TimerID < 0) || (TimerID >= MAX_TIMER) || (Timer[TimerID].bUsed == false))
		return 0;
		
	return Timer[TimerID].TimeStamp;	
}

bool RepeatStart(int TimerID)
{
	if ((TimerID < 0) || (TimerID >= MAX_TIMER) || (Timer[TimerID].bUsed == false))
		return false;	
		
	Timer[TimerID].bRepeat = true;
	return true;	
}

void TimerFunc(void)
{
	TimerIndex = 0;
	for (TimerIndex = 0; TimerIndex < MAX_TIMER; TimerIndex++)
	{
		if(Timer[TimerIndex].bUsed == true)
		{
			Timer[TimerIndex].ActTime = Get_ops_tAbsolute() - Timer[TimerIndex].TimeStamp;
			if (Timer[TimerIndex].ActTime >= Timer[TimerIndex].Duration)
			{
				if (Timer[TimerIndex].pFct != NULL)			
					Timer[TimerIndex].pFct();
				if (Timer[TimerIndex].bRepeat == true)
					Timer[TimerIndex].TimeStamp = Get_ops_tAbsolute();
				else
					TimerUninstall(TimerIndex);
			}
		}
	}
}

void TimerStart(unsigned int* pStrtTim)
{
	if (pStrtTim != NULL)
		*pStrtTim = Get_ops_tAbsolute();
}

unsigned int TimerRest(unsigned int* pStrtTim, unsigned int Duration)
{
	if (pStrtTim == NULL)
		return 0;
	
	if ((Get_ops_tAbsolute() - *pStrtTim) >= Duration)
		return 0;
	else
		return (Duration - (Get_ops_tAbsolute() - *pStrtTim));
}

bool IsTimerFinished(unsigned int* pStrtTim, unsigned int Duration)
{
	if (pStrtTim == NULL)
		return false;
	
	if ((Get_ops_tAbsolute() -*pStrtTim) >= Duration)
		return true;
	else
		return false;	
}

unsigned int TimerAct(unsigned int* pStrtTim)
{
	if (pStrtTim == NULL)
		return 0;
	
	return (Get_ops_tAbsolute() - *pStrtTim);
}

bool TmrFixA(unsigned int Duration, unsigned int* pStrtTim, unsigned int* pActTim)
{
	if (pStrtTim == NULL || pActTim == NULL)
		return false;
		
	if (*pStrtTim == 0)	
	{
		*pStrtTim = Get_ops_tAbsolute();
		*pActTim = 0;
	}
	
	*pActTim = Get_ops_tAbsolute() - *pStrtTim;
		
	if (*pActTim >= Duration)
		return true;
	else
		return false;	
}

bool TmrFix(unsigned int Duration, unsigned int* pStrtTim)
{
	if (pStrtTim == NULL)
		return false;
		
	if (*pStrtTim == 0)
		*pStrtTim = Get_ops_tAbsolute();
	
	if ((Get_ops_tAbsolute() - *pStrtTim) >= Duration)
		return true;
	else
		return false;
}

void TmrUp(unsigned int* pStrtTim, unsigned int* pActTim)
{
	if ((pStrtTim == NULL) || (pActTim == NULL))
		return;
	
	if (*pStrtTim == 0)	
		*pStrtTim = Get_ops_tAbsolute();
	
	*pActTim = Get_ops_tAbsolute() - *pStrtTim;	
}