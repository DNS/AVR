/*
 * Blink_Interrupt.c
 *
 * Created: 6/3/2015 5:30:45 AM
 *  Author: dns
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

int main () {
	DDRB = 0xFF;			// Set LED as output
	TCCR1B |= (1 << WGM12);	// Configure timer 1 for CTC mode
	TIMSK |= (1 << OCIE1A);	// Enable CTC interrupt
	sei();					//  Enable global interrupts
	OCR1A   = 10000;		// Set CTC compare value, about 50ms.
	TCCR1B |= ((1 << CS10) | (1 << CS11));	// Start timer at Fcpu/64

	while(1) {
		// Do nothing, the interrupt is taking care of it.
	}
}

ISR (TIMER1_COMPA_vect) {
	PORTB ^= 0xFF;		// Toggle the LED
}
