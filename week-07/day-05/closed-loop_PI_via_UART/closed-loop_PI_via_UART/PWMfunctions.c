#include "pwmfunctions.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void pwm_init()
{
	//intit timer0 :fast pwm TOP=0xFF, non-inverting compare output mode
	TCCR2A |= (1<<WGM20)|(1<<COM2A1)|(1<<WGM21);
	//no prescale
	TCCR2B |= (1<<CS20);
	//OC0A is output pin (Pb3 pin)
	DDRB |= (1 << DDRB3);
	OCR2A = 10; 
	
}

void led_flasher()
{
	uint8_t brightness;
	for (brightness = 0; brightness < 255; ++brightness)
	{
		// set the brightness as duty cycle
		OCR2A = brightness;
				 
		// delay so as to make the user "see" the change in brightness
		_delay_ms(10);
	}
			 
	// decreasing brightness
	for (brightness = 255; brightness > 0; --brightness)
	{
		// set the brightness as duty cycle
		OCR2A = brightness;
				 
		// delay so as to make the user "see" the change in brightness
		_delay_ms(10);
	}
}
void duty_cycle_funct(uint8_t duty_cycle)
{
	uint8_t duty = duty_cycle * 2.55;
	OCR2A = duty;
	
}