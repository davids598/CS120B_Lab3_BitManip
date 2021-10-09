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
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
	unsigned char inputA = 0x00; // Temporary variable to hold the value of B
	unsigned char inputB = 0x00; // Temporary variable to hold the value of B
	unsigned char counterC = 0x00;
while(1) {
		// 1) Read input
		inputA = PINA;
		inputB = PINB;
		// 2) Perform computation
		counterC = (inputA & 0x01) + ((inputA & 0x02) >> 1) + ((inputA & 0x04) >> 2) + ((inputA & 0x08) >> 3) + ((inputA & 0x10) >> 4) + ((inputA & 0x20) >> 5) + ((inputA & 0x40) >> 6) + ((inputA & 0x80) >> 7);
		counterC = counterC + (inputB & 0x01) + ((inputB & 0x02) >> 1) + ((inputB & 0x04) >> 2) + ((inputB & 0x08) >> 3) + ((inputB & 0x10) >> 4) + ((inputB & 0x20) >> 5) + ((inputB & 0x40) >> 6) + ((inputB & 0x80) >> 7);
		// take counter and set PORT C to equal that value.
		PORTC = counterC;
	}
	return 0;
}
