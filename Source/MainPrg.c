/*
 * MainPrg.c
 *
 * Created: 1/29/2013 10:42:20 AM
 *  Author: avm
 */ 
#include "Include/Include.h"
#include "../Include/IOInterface.h"
#ifndef CPU_SAME70_
	#include "../plccommon/nvram.h"
#endif	

void sample(void);

#define MAINAPP_PRIORITY 1

#ifndef CPU_SAME70_
	xTimerHandle xTimCntMS, xTimAxisIrq;
	portTickType xLastWakeTim;
	xTaskHandle CycTsk;
#else
	TimerHandle_t xTimCntMS, xTimAxisIrq;
	TickType_t xLastWakeTim;
	TaskHandle_t CycTsk;
#endif	

unsigned int	RunLEDTim = 0;
enum tCPUSts	CPUSts = _STRT_CPU;
unsigned int	ops_tAbsolute = 0;

void MainFunction(void*);
void RunLEDControl(void);


void MainApp(void)
{
	xTaskCreate(MainFunction, ((const signed portCHAR*)"Cyclic"), 1024, NULL, (tskIDLE_PRIORITY+MAINAPP_PRIORITY), CycTsk);
}

void MainInit()
{
	InitEdgeScan();
}

void MainFunction(void* pvPARAM)
{
	InitIOs();
	SwOFFOuputs();
	#ifndef CPU_SAME70_
		LED_Off(LED_ALL);
	#endif	
	
	while(1)
	{
		RunLEDControl();
		xLastWakeTim = xTaskGetTickCount();
		switch (CPUSts)
		{
			case _STRT_CPU:
				xTimCntMS = xTimerCreate("TimerIRQ", IRQ_MIN_TICK_CNT, pdTRUE, (void *)5, Timer_IRQ);
				xTimerStart(xTimCntMS, 0);
				CPUSts = _DO_INIT_;
				break;

			case _DO_INIT_:
				MainInit(); //User INIT functions...
				CPUSts = _STRT_IRQ;
			break;
			
			case _STRT_IRQ:
				xTimAxisIrq = xTimerCreate("AxisIRQ", IRQ_FUNC_FREQ, pdTRUE, (void *)6, Main_IRQ);
				//Starts the software timer
				xTimerStart(xTimAxisIrq, 0);
				CPUSts = _RUN_PROG;
				break;

			case _RUN_PROG:	
				sample();			 
				break;
		}
		vTaskDelayUntil(&xLastWakeTim, MAIN_FUNC_FREQ);
	}
}

void RunLEDControl(void)
{
	if ((Get_ops_tAbsolute() - RunLEDTim) >= CPU_RUN_LED_TICK_CNT)
	{
		#ifndef CPU_SAME70_
			LED_Toggle(LED_APP_RUN);
		#else
			LED_Toggle(LED1);
		#endif	
		RunLEDTim = Get_ops_tAbsolute();
		PLC_WDT_RESET();
	}
}

