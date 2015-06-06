/*
 * init_mcu.h
 *
 * Created: 03.10.2013 16:10:53
 *  Author: vmk
 */

#ifndef INIT_MCU_H_
#define INIT_MCU_H_
//---------------------------------------------------------------------------------------
#define F_CPU 16000000UL // or whatever may be your frequency
#define ADC_VREF_TYPE 0x40
//---------------------------------------------------------------------------------------
#include <avr/io.h>
//***************************************************************************************
void init_mcu(void)
{
	// Input/Output Ports initialization
	// Port A initialization
	// Func7=In Func6=In Func5=In Func4=Out Func3=Out Func2=In Func1=In Func0=In
	// State7=T State6=T State5=P State4=1 State3=1 State2=P State1=T State0=T
	PORTA=0x3C;
	DDRA=0x18;

	// Port B initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=Out Func2=Out Func1=Out Func0=Out
	// State7=T State6=T State5=T State4=T State3=0 State2=0 State1=0 State0=0
	PORTB=0x00;
	DDRB=0x0F;

	// Port C initialization
	// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out
	// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0
	PORTC=0x00;
	DDRC=0xFF;

	// Port D initialization
	// Func7=Out Func6=Out Func5=Out Func4=Out Func3=In Func2=In Func1=In Func0=In
	// State7=0 State6=1 State5=0 State4=0 State3=P State2=P State1=T State0=T
	PORTD=0x4C;
	DDRD=0xF0;

	// Timer/Counter 0 initialization
	// Clock source: System Clock
	// Clock value: 62,500 kHz
	// Mode: Normal top=0xFF
	// OC0 output: Disconnected
	TCCR0=0x04;
	TCNT0=0x06;
	OCR0=0x00;

	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: 250,000 kHz
	// Mode: Normal top=0xFFFF
	// OC1A output: Discon.
	// OC1B output: Discon.
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer1 Overflow Interrupt: On
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	TCCR1A=0x00;
	TCCR1B=0x03;
	TCNT1H=0xC2;
	TCNT1L=0xF7;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x00;
	OCR1BH=0x00;
	OCR1BL=0x00;

	// Timer/Counter 2 initialization
	// Clock source: System Clock
	// Clock value: 15,625 kHz
	// Mode: Normal top=0xFF
	// OC2 output: Disconnected
	ASSR=0x00;
	TCCR2=0x00;
	//TCCR2=0x07;
	TCNT2=0x88;
	OCR2=0x00;

	// External Interrupt(s) initialization
	// INT0: On
	// INT0 Mode: Rising Edge
	// INT1: On
	// INT1 Mode: Rising Edge
	// INT2: Off
	GICR|=0xC0;
	MCUCR=0x0F;
	MCUCSR=0x00;
	GIFR=0xC0;

	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK=0x45;

	// USART initialization
	// USART disabled
	UCSRB=0x00;

	// Analog Comparator initialization
	// Analog Comparator: Off
	// Analog Comparator Input Capture by Timer/Counter 1: Off
	ACSR=0x80;
	SFIOR=0x00;

	// ADC initialization
	// ADC Clock frequency: 250,000 kHz
	// ADC Voltage Reference: AVCC pin
	ADMUX=ADC_VREF_TYPE & 0xff;
	ADCSRA=0x86;

	// SPI initialization
	// SPI disabled
	SPCR=0x00;

	// TWI initialization
	// TWI disabled
	TWCR=0x00;
	
	// Watchdog Timer initialization
	// Watchdog Timer Prescaler: stop
	WDTCR=0x00;
};
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
#endif /* INIT_MCU_H_ */