/*	Author: david
 *  Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
	unsigned char valForC = 0x00;
	unsigned char valForB = 0x00;
while(1) {
		// 1) Read input
		valForC = PINA & 0x0F;
		valForB = PINA & 0xF0;

		// 2) Perform computation
		PORTB = (valForB >> 4);
		PORTC = (valForC << 4);
	}
	return 0; 
}
