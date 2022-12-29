/*
 * IRQ.c
 *
 * Created: 2/2/2013 3:53:40 PM
 *  Author: avm
 */ 
#include "Include/Include.h"
#include "../Include/IOInterface.h"
#ifdef CPU_SAME70_
	#include "FreeRTOS.h"
	#include "timers.h"
#endif

#ifndef CPU_SAME70_
	void Timer_IRQ(xTimerHandle pxTimer)
#else
	void Timer_IRQ(TimerHandle_t pxTimer)
#endif
{
	ENTER_IRQ();
	ops_tAbsolute++;
	EXIT_IRQ();
}

unsigned int Get_ops_tAbsolute(void)
{
	unsigned int ret_ops_tAbsolute = 0;
	ret_ops_tAbsolute = ops_tAbsolute;
	return ret_ops_tAbsolute;
}

#ifndef CPU_SAME70_
void Main_IRQ(xTimerHandle pxTimer)
#else
void Main_IRQ(TimerHandle_t pxTimer)
#endif
{
	ENTER_IRQ();
	
	//Update all the Inputs first
	UpdateIOs(IO_TYPE_INPUT);
		
	//Update all the Outputs last
	UpdateIOs(IO_TYPE_OUTPUT);

	EXIT_IRQ();
}
