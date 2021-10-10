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
	//unsigned char inputA = 0x00; // Temporary variable to hold the value of A
	//unsigned char inputB = 0x00; // Temporary variable to hold the value of B
	unsigned char valForC = 0x00;
	unsigned char outputC = 0x00;
	unsigned char info = 0x00;
while(1) {
		// 1) Read input
		valForC = PINA & 0x0F;
		info = PINA & 0xF0;
		//inputB = PINB;
		// 2) Perform computation
		//valForC = (inputA & 0x01) + ((inputA & 0x02) >> 1) + ((inputA & 0x04) >> 2) + ((inputA & 0x08) >> 3) + ((inputA & 0x10) >> 4) + ((inputA & 0x20) >> 5) + ((inputA & 0x40) >> 6) + ((inputA & 0x80) >> 7);
		//valForC = valForC + (inputB & 0x01) + ((inputB & 0x02) >> 1) + ((inputB & 0x04) >> 2) + ((inputB & 0x08) >> 3) + ((inputB & 0x10) >> 4) + ((inputB & 0x20) >> 5) + ((inputB & 0x40) >> 6) + ((inputB & 0x80) >> 7);
		// take counter and set PORT C to equal that value.
		if (valForC == 1 || valForC == 2) {
			outputC = 0x20;
		}
		if (valForC >= 3 && valForC <= 4) {
			outputC = 0x30;
		}
		if (valForC >= 5 && valForC <= 6) {
			outputC = 0x38;
		}
		if (valForC >= 7 && valForC <= 9) {
			outputC = 0x3C;
		}
		if (valForC >= 10 && valForC <= 12) {
			outputC = 0x3E;
		}
		if (valForC >= 13 && valForC <= 15) {
			outputC = 0x3F;
		}
		if (valForC <= 4) {
			outputC = outputC | 0x40;
		}
		if (((info & 0x10) == 0x10) && ((info & 0x20) == 0x20) && ((info & 0x40) == 0)) {
			outputC = outputC | 0x80;
		}
		PORTC = outputC;
	}
	return 0;
}
