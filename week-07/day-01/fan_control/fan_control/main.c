/*
 * fan_control.c
 *
 * Created: 6/12/2017 1:33:34 PM
 * Author : Adam
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "pwmfunctions.h"
#include <stdint.h>
#include "ADC_driver.h"


int main(void)
{
	//uint8_t brightness;
	//brightness = 100;
	pwm_init();
	ADC_Init();
	/* Replace with your application code */
	while (1)
	{
		duty_cycle_funct(ADC_Read() / 10.23);
		//led_flasher();
	}
}

