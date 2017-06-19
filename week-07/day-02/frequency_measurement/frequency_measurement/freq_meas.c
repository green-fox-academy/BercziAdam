#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

volatile overflow_count = 0;
volatile freq_start = 0;
volatile freq_end = 0;
volatile over_flow_temp;

ISR(TIMER1_CAPT_vect)
{
	freq_start = freq_end;
	freq_end = ICR1;
	over_flow_temp = overflow_count;
	overflow_count = 0;
}
ISR(TIMER1_OVF_vect)
{	
	overflow_count++;
}

void freq_meas_init()
{
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the TC1 timer properly :)
	TCCR1B |=(1 << CS11) | (1 << CS10);//prescale 64
	
	TIMSK1 |= (1 << ICIE1) | (1 << TOIE1);//enable input capture interrupt and overflow interrupt
	

}

// TODO:
// Write this function. It returns the measured frequency in Hz
float get_freq()
{
	cli();
	uint16_t stemp_start = freq_start;
	uint16_t stemp_end = freq_end;
	uint8_t overflow = over_flow_temp;
	over_flow_temp = 0;
	sei();
	
	
	uint32_t steps = ((uint32_t)overflow) * 65535 + stemp_start - stemp_end;
	float period =  (1/(float)16000000) *  64 * (float)steps;
	float frequency = 1 / period;

	return frequency;
}