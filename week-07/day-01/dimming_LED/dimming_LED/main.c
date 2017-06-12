/*
 * dimming_LED.c
 *
 * Created: 6/12/2017 12:57:34 PM
 * Author : Adam
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "pwmfunctions.h"
#include "ADC_driver.h"
#include <stdint.h>


int main(void)
{
	//uint8_t brightness;
	//brightness = 100;
	ADC_Init();
	pwm_init();
	/* Replace with your application code */
	while (1)
	{
		led_blinker(ADC_Read() / 10.23);
		//led_flasher();
	}
}
