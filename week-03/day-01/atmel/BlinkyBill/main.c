#include <avr/io.h>			// This header contains the definitions for the io registers

#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function

int main(void)
{
	
	DDRB |=(1 << DDRB5);
	DDRB |=(1 << DDRB4);
	DDRB |=(1 << DDRB3);
	DDRB |=(1 << DDRB2);
	DDRB |=(1 << DDRB1);
	DDRB |=(1 << DDRB0);

	while (1) {
		int x=5;
		int i=50;
		for (x=0; x<=5; x++)
		{
		PORTB |=(1 << x);
		_delay_ms(i);
		PORTB &= ~(1 << x);
		_delay_ms(i);
		}
		for (x=5; x>=0; x--)
		{
			PORTB |=(1 << x);
			_delay_ms(i);
			PORTB &= ~(1 << x);
			_delay_ms(i);
			
		}
	}
}
