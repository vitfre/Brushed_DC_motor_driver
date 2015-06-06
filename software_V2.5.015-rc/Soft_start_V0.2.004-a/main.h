﻿/*
 * main.h
 *
 * Created: 11.02.2014 17:51:42
 *  Author: Администратор
 */ 



#ifndef MAIN_H_
#define MAIN_H_
//---------------------------------------------------------------------------------------
#define F_CPU 4000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//---------------------------------------------------------------------------------------
#include "init_mcu.h"
//---------------------------------------------------------------------------------------
#define	min_power		0x70//0x88
//---------------------------------------------------------------------------------------
#define PWR_EN		(((PINB)>>(1))&1)   //Напругу брати від лінії
//---------------------------------------------------------------------------------------
#define SPOP_M1 	(PORTB&=~(1<<0));	power=min_power;
//---------------------------------------------------------------------------------------
#define IMP_SEM_SET_M1 	(PORTB|=(1<<0));	TCCR0B=0x00;			TCNT0=min_power;	//  T2
#define IMP_SEM_CLR_M1 	(PORTB&=~(1<<0));	TCCR0B=0x04;			TCNT0=power;		// старт T2
//---------------------------------------------------------------------------------------
unsigned char power=min_power;
//---------------------------------------------------------------------------------------
#endif /* MAIN_H_ */