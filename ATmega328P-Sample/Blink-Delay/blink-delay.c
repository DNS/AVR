/*
 * blink.c
 *
 * Created: 1/3/2015 12:37:49 PM
 *  Author: dns
 */ 

#define F_CPU 1000000UL		// run at 1-16 MHz

#include <avr/io.h>
#include <util/delay.h>

int main () {    
	DDRB = 0xff;	// all B ports as output
	
	while(1) {
		PORTB = 0xff;		// turn on all B port
		_delay_ms(1000);	// delay for 200 ms
		PORTB = 0x00;		// turn off all B port
		_delay_ms(1000);	// delay for 200 ms
	}
}