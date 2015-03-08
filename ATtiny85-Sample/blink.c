/*
 * ATtiny85_Sample.c
 *
 * Created: 7/3/2015 7:11:10 AM
 *  Author: dns
 */ 



#include <avr/io.h>
#include <util/delay.h>


/*
DDRB - Port B Data Direction Register
PORTB – Port B Data Register
PINB – Port B Input Pins Address

// How read input pin?
DDRD = 0b00000000;		// Set all pins as input
uint8_t status;			// Define a 8 bit integer variable
status = PIND;			// Store the current value of PIND in status



*/

int main () {
	DDRB = 0b00010000;		// set PB4 as output, and the other pin as input
	
	while (1) {
		
		if (PINB == 0b00001000) {	// read pin3
			PORTB = 0b00010000;		// turn on PB4
			_delay_ms(100);	// delay for 200 ms
			PORTB = 0b00000000;	// turn off PB4
			_delay_ms(100);	// delay for 200 ms
		}
		
	}
}

