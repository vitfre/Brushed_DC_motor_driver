﻿/*
 * song.h
 *
 * Created: 04.01.2014 22:01:02
 *  Author: Администратор
 */ 


#ifndef SONG_H_
#define SONG_H_
//---------------------------------------------------------------------------------------
#define F_CPU 16000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
//---------------------------------------------------------------------------------------
#define BUZZ_INIT				(DDRD|=(1<<5)); (PORTD&=~(1<<5));
#define BUZZ_OFF				(PORTD&=~(1<<5));
#define BUZZ_ON					(PORTD|=(1<<5));
//---------------------------------------------------------------------------------------


/**************************************************************************
*   Function name : Beep_tone
*   Returns :       нет
*   Parameters :    довжина піка
*   Purpose :       пикаем
****************************************************************************/
void beep_tone(unsigned int i)
{
	//---------------------------------------------------------------------------------------
	BUZZ_ON
	for (;1<i;i--)
	{
		_delay_ms(1);
	};
	BUZZ_OFF
	//---------------------------------------------------------------------------------------
};




#endif /* SONG_H_ */