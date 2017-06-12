#include "pwmfunctions.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void pwm_init()
{
	//intit timer0 :fast pwm TOP=0xFF, non-inverting compare output mode
	TCCR0A |= (1<<WGM00)|(1<<COM0A1)|(1<<WGM01);
	//no prescale
	TCCR0B |= (1<<CS00);
	//OC0A is output pin (PD6 pin)
	DDRD |= (1 << DDRD6);
	
}

void led_flasher()
{
	uint8_t brightness;
	for (brightness = 0; brightness < 255; ++brightness)
	{
		// set the brightness as duty cycle
		OCR0A = brightness;
				 
		// delay so as to make the user "see" the change in brightness
		_delay_ms(10);
	}
			 
	// decreasing brightness
	for (brightness = 255; brightness > 0; --brightness)
	{
		// set the brightness as duty cycle
		OCR0A = brightness;
				 
		// delay so as to make the user "see" the change in brightness
		_delay_ms(10);
	}
}
void led_blinker(uint8_t duty_cycle)
{
	uint8_t duty = duty_cycle * 2.55;
	OCR0A = duty;
	
}