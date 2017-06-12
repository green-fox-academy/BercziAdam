/*
 * fastPWM.c
 *
 * Created: 6/12/2017 9:56:59 AM
 * Author : Adam
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "pwmfunctions.h"
#include <stdint.h>


int main(void)
{
	//uint8_t brightness;
	//brightness = 100;
	pwm_init();
    /* Replace with your application code */
    while (1) 
    {
		//led_blinker(55);
		led_flasher();
	}
}

