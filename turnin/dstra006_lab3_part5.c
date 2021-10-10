/*	Author: david
 *  Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #5
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
	DDRB = 0xFE; PORTB = 0x01; // Configure port B's 8 pins as outputs, initialize to 0s
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	DDRD = 0x00; PORTD = 0xFF; // Configure port D's 8 pins as outputs, initialize to 0s
	unsigned short weight = 0x00; 
while(1) {
		// 1) Read input
		weight = PIND;
		weight = weight << 1;
		weight = weight | (PINB & 0x01);

		// 2) Perform computation
		if (weight >= 70) {
			PORTB = 0x02;
		}
		else if (weight > 5 && weight < 70) {
			PORTB = 0x04;
		} else {
			PORTB = 0x00;
		}
	}
	return 0;
}
