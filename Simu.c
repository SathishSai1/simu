/*
 * Simu.c
 *
 * Created: 22-12-2022 08:52 AM
 *  Author: Sathish
 */ 
#include "../Include/Include.h"

void delay(int);

void sample(void)

{
	
	startbit==_ON
	
	if (DI1_0==_ON)
	{ if (startbit==_ON) {DO1_0=_ON;} else ; }
		else; {DO1_0=_ON;}
			
			
	if (DI1_1==_ON)
		{ 
		if		  (DO1_0==_ON && DI1_0==_ON)  {DO1_1=_ON;} 
		else if	  (DI1_0==_ON)  			  {DO1_0=_ON;}
		else								  {DO1_1=_OFF;}		
		}
	
	
//DO1_2////	
	
	
	if (DI1_2==_ON)
	{
	if		  (DO1_1==_ON && DI1_1==_ON) {DO1_2=_ON;}
	else if	  (DI1_1==_ON)				 {DO1_1=_ON;}     
	else								 {DO1_2=_OFF;}
		
	}
	
		
	
//DO1_3////


if (DI1_3==_ON)
{
	if			(DO1_2==_ON && DI1_2==_ON)  {DO1_3=_ON;}
	else if		(DI1_2==_ON)				{DO1_3=_ON;}							
	else									{DO1_3=_OFF;}
}
	
if (DI1_4==_ON)
{
	if			(DO1_3==_ON && DI1_3==_ON)  {DO1_4=_ON;}
	else if		(DI1_3==_ON)				{DO1_4=_ON;}
	else									{DO1_4=_OFF;}
}

if (DI1_5==_ON)
{
	if			(DO1_4==_ON && DI1_4==_ON)  {DO1_5=_ON;}
	else if		(DI1_4==_ON)				{DO1_5=_ON;}
	else									{DO1_5=_OFF;}
}	

if (DI1_6==_ON)
{
	if			(DO1_5==_ON && DI1_5==_ON)  {DO1_6=_ON;}
	else if		(DI1_5==_ON)				{DO1_6=_ON;}
	else									{DO1_6=_OFF;}
}

if (DI1_6==_ON)
{
	if			(DO1_5==_ON && DI1_5==_ON)  {DO1_6=_ON;}
	else if		(DI1_5==_ON)				{DO1_6=_ON;}
	else									{DO1_6=_OFF;}
}	


if (DI1_7==_ON)
{
	if			(DO1_6==_ON && DI1_6==_ON)  {DO1_7=_ON;}
	else if		(DI1_6==_ON)				{DO1_7=_ON;}
	else									{DO1_7=_OFF;}
}	
	
	
	/***if (DI1_2==_ON)
	{ if ( DO1_1==_ON && DI1_1==_ON   ) {DO1_2=_ON;} else {DO1_2=_OFF;} }
	else {if (DI1_1==_ON) {DO1_1=_ON;} else {DO1_2=_OFF;} }
	
	if (DI1_3==_ON)
	{ if ( DO1_2==_ON && DI1_2==_ON   ) {DO1_3=_ON;} else {DO1_3=_OFF;} }
else {if (DI1_2==_ON) {DO1_2=_ON;} else {DO1_3=_OFF;} }	*/
	
	
	
	
	
	
	
	
	/* STARTBIT=_ON
	if (DI1_0==_ON)
	
	{ if (STARTBIT==_ON DO1_0==_ON  )  {DO1_1=_ON} else DO1_1=_OFF}
	else	{if (DI1_1=_ON) {DO1_1=_ON} else DO1_1=_OFF }
	
}

	 if (DI1_1==_ON)
	 { if (DO1_0==_ON && DI1_1=_ON )  {DO1_1=_ON} else DO1_1=_OFF} 
	   else	{if (DI1_1=_ON) {DO1_1=_ON} else DO1_1=_OFF }     		
	 
		if (DI1_2==_ON)
		 { if (DO1_0==_ON && DI1_1=_ON )  {DO1_1=_ON} else DO1_1=_OFF}
		else { if (DI1_1=_ON) {DO1_1=_ON} else DO1_1=_OFF } */
	 
	 
	 

	
	
		/*if (DI1_0==_ON)										{DO1_1=_ON;}		else DO1_1=_OFF;
		if (DI1_1==_ON && DI1_0==_ON && DI1_2==_OFF)		{DO1_2=_ON;}	    else DO1_2=_OFF; //
		if (DI1_2==_ON && DI1_1==_ON && DI1_3==_OFF)		{DO1_3=_ON;}		else DO1_3=_OFF;//
		if (DI1_3==_ON && DI1_2==_ON && DI1_4==_OFF)		{DO1_4=_ON;}		else DO1_4=_OFF;//
		if (DI1_4==_ON && DI1_3==_ON && DI1_5==_OFF)		{DO1_5=_ON;}	    else DO1_5=_OFF;//
		if (DI1_5==_ON && DI1_4==_ON && DI1_6==_OFF)		{DO1_6=_ON;}		else DO1_6=_OFF;//
		if (DI1_6==_ON && DI1_5==_ON && DI1_7==_OFF)		{DO1_7=_ON;}		else DO1_7=_OFF;//
		if (DI1_7==_ON && DI1_6==_ON && DI1_8==_OFF)		{DO1_8=_ON;}		else DO1_8=_OFF;//
		if (DI1_8==_ON && DI1_7==_ON && DI1_9==_OFF)		{DO1_9=_ON;}		else DO1_9=_OFF;//
		if (DI1_9==_ON && DI1_8==_ON && DI1_A==_OFF)		{DO1_A=_ON;}		else DO1_A=_OFF;//
		if (DI1_A==_ON && DI1_9==_ON && DI1_B==_OFF)		{DO1_B=_ON;}		else DO1_B=_OFF;//
		if (DI1_B==_ON && DI1_A==_ON && DI1_C==_OFF)		{DO1_C=_ON;}		else DO1_C=_OFF;//
		if (DI1_C==_ON && DI1_B==_ON && DI1_D==_OFF)		{DO1_D=_ON;}		else DO1_D=_OFF;//
		if (DI1_D==_ON && DI1_C==_ON && DI1_E==_OFF)		{DO1_E=_ON;}		else DO1_E=_OFF;//
		if (DI1_E==_ON && DI1_D==_ON && DI1_F==_OFF)		{DO1_F=_ON;}		else DO1_F=_OFF;//
		if (DI1_F==_ON && DI1_E==_ON && DI2_0==_OFF)		{DO2_0=_ON;}		else DO2_0=_OFF;
		
		
		
		
		
		
		
		/*DO1_0=_ON;

		if (DI1_0==_ON) {DO1_1=_ON;}		else DO1_1=_OFF;
		if (DI1_1==_ON && DO1_1==_ON) {DO1_2=_ON;}	    else DO1_2=_OFF;
		if (DI1_2==_ON && DO1_2==_ON) {DO1_3=_ON;}		else DO1_3=_OFF;
		if (DI1_3==_ON && DO1_3==_ON) {DO1_4=_ON;}		else DO1_4=_OFF;
		if (DI1_4==_ON && DO1_4==_ON) {DO1_5=_ON;}	    else DO1_5=_OFF;
		if (DI1_5==_ON && DO1_5==_ON) {DO1_6=_ON;}		else DO1_6=_OFF;
		if (DI1_6==_ON && DO1_6==_ON) {DO1_7=_ON;}		else DO1_7=_OFF;
		if (DI1_7==_ON && DO1_7==_ON) {DO1_8=_ON;}		else DO1_8=_OFF;
		if (DI1_8==_ON && DO1_8==_ON) {DO1_9=_ON;}		else DO1_9=_OFF;
		if (DI1_9==_ON && DO1_9==_ON) {DO1_A=_ON;}		else DO1_A=_OFF;
		if (DI1_A==_ON && DO1_A==_ON) {DO1_B=_ON;}		else DO1_B=_OFF;	
		if (DI1_B==_ON && DO1_B==_ON) {DO1_C=_ON;}		else DO1_C=_OFF;	
		if (DI1_C==_ON && DO1_C==_ON) {DO1_D=_ON;}		else DO1_D=_OFF;	
		if (DI1_D==_ON && DO1_D==_ON) {DO1_E=_ON;}		else DO1_E=_OFF;
		if (DI1_E==_ON && DO1_E==_ON) {DO1_F=_ON;}		else DO1_F=_OFF;	
		if (DI1_F==_ON && DO1_F==_ON) {DO2_0=_ON;}		else DO2_0=_OFF;
			
		if (DI1_10==_ON && DO2_0==_ON) {DO2_1=_ON;}	    else DO2_1=_OFF;
		if (DI1_11==_ON && DO2_1==_ON) {DO2_2=_ON;}	    else DO2_2=_OFF;		
		if (DI1_12==_ON && DO2_2==_ON) {DO2_3=_ON;}	    else DO2_3=_OFF;
		if (DI1_13==_ON && DO2_3==_ON) {DO2_4=_ON;}	    else DO2_4=_OFF;	
		if (DI1_14==_ON && DO2_4==_ON) {DO2_5=_ON;}	    else DO2_5=_OFF;
		if (DI1_15==_ON && DO2_5==_ON) {DO2_6=_ON;}	    else DO2_6=_OFF;
		if (DI1_16==_ON && DO2_6==_ON) {DO2_7=_ON;}	    else DO2_7=_OFF;
		if (DI1_17==_ON && DO2_7==_ON) {DO2_8=_ON;}	    else DO2_8=_OFF;
		if (DI1_18==_ON && DO2_8==_ON) {DO2_9=_ON;}	    else DO2_9=_OFF;
		if (DI1_19==_ON && DO2_9==_ON) {DO2_A=_ON;}	    else DO2_A=_OFF;
		if (DI1_1A==_ON && DO2_A==_ON) {DO2_B=_ON;}	    else DO2_B=_OFF;
		if (DI1_1B==_ON && DO2_B==_ON) {DO2_C=_ON;}	    else DO2_C=_OFF;
		if (DI1_1C==_ON && DO2_C==_ON) {DO2_D=_ON;}	    else DO2_D=_OFF;			
		if (DI1_1D==_ON && DO2_D==_ON) {DO2_E=_ON;}	    else DO2_E=_OFF;
		if (DI1_1E==_ON && DO2_E==_ON) {DO2_F=_ON;}	    else DO2_F=_OFF;	
		if (DI1_1F==_ON && DO2_F==_ON) {DO3_0=_ON;}	    else DO3_0=_OFF;	

		if (DI2_0==_ON && DO3_0==_ON) {DO3_1=_ON;}	    else DO3_1=_OFF;
		if (DI2_1==_ON && DO3_0==_ON) {DO3_2=_ON;}	    else DO3_2=_OFF;
		if (DI2_2==_ON && DO3_0==_ON) {DO3_3=_ON;}	    else DO3_3=_OFF;
		if (DI2_3==_ON && DO3_0==_ON) {DO3_4=_ON;}	    else DO3_4=_OFF;
		if (DI2_4==_ON && DO3_0==_ON) {DO3_5=_ON;}	    else DO3_5=_OFF;
		if (DI2_5==_ON && DO3_0==_ON) {DO3_6=_ON;}	    else DO3_6=_OFF;
		if (DI2_6==_ON && DO3_0==_ON) {DO3_7=_ON;}	    else DO3_7=_OFF;
		if (DI2_7==_ON && DO3_0==_ON) {DO3_8=_ON;}	    else DO3_8=_OFF;
		if (DI2_8==_ON && DO3_0==_ON) {DO3_9=_ON;}	    else DO3_9=_OFF;
		if (DI2_9==_ON && DO3_0==_ON) {DO3_A=_ON;}	    else DO3_A=_OFF;
		if (DI2_A==_ON && DO3_0==_ON) {DO3_B=_ON;}	    else DO3_B=_OFF;
		if (DI2_B==_ON && DO3_0==_ON) {DO3_C=_ON;}	    else DO3_C=_OFF;
		if (DI2_C==_ON && DO3_0==_ON) {DO3_D=_ON;}	    else DO3_D=_OFF;
		if (DI2_D==_ON && DO3_0==_ON) {DO3_E=_ON;}	    else DO3_E=_OFF;
		if (DI2_E==_ON && DO3_0==_ON) {DO3_F=_ON;}	    else DO3_F=_OFF;
		if (DI2_F==_ON && DO3_0==_ON) {DO4_0=_ON;}	    else DO4_0=_OFF;
		
		
		if (DI2_10==_ON && DO4_0==_ON) {DO4_1=_ON;}	    else DO4_1=_OFF;
		if (DI2_11==_ON && DO4_1==_ON) {DO4_2=_ON;}	    else DO4_2=_OFF;
		if (DI2_12==_ON && DO4_2==_ON) {DO4_3=_ON;}	    else DO4_3=_OFF;
		if (DI2_13==_ON && DO4_3==_ON) {DO4_4=_ON;}	    else DO4_4=_OFF;
		if (DI2_14==_ON && DO4_4==_ON) {DO4_5=_ON;}	    else DO4_5=_OFF;
		if (DI2_15==_ON && DO4_5==_ON) {DO4_6=_ON;}	    else DO4_6=_OFF;
		if (DI2_16==_ON && DO4_6==_ON) {DO4_7=_ON;}	    else DO4_7=_OFF;
		if (DI2_17==_ON && DO4_7==_ON) {DO4_8=_ON;}	    else DO4_8=_OFF;
		if (DI2_18==_ON && DO4_8==_ON) {DO4_9=_ON;}	    else DO4_9=_OFF;
		if (DI2_19==_ON && DO4_9==_ON) {DO4_A=_ON;}	    else DO4_A=_OFF;
		if (DI2_1A==_ON && DO4_A==_ON) {DO4_B=_ON;}	    else DO4_B=_OFF;
		if (DI2_1B==_ON && DO4_B==_ON) {DO4_C=_ON;}	    else DO4_C=_OFF;
		if (DI2_1C==_ON && DO4_C==_ON) {DO4_D=_ON;}	    else DO4_D=_OFF;
		if (DI2_1D==_ON && DO4_D==_ON) {DO4_E=_ON;}	    else DO4_E=_OFF;
		if (DI2_1E==_ON && DO4_E==_ON) {DO4_F=_ON;}	    else DO4_F=_OFF;
		*/










}

