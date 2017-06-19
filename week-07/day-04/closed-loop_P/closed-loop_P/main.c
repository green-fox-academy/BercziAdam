/*
 * closed-loop_P.c
 *
 * Created: 6/15/2017 1:52:31 PM
 * Author : Adam
 */ 

#include "freq_meas.h"
#include "UART_driver.h"
#include "AC_driver.h"
#include "pwmfunctions.h"
#include "ADC_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init()
{
	LED_DDR |= 1 << LED_DDR_POS;
	AC_driver_init();
	freq_meas_init();
	UART_init();
	ADC_Init();
	pwm_init();
	sei();
}

int main(void)
{

	// Don't forget to call the init function :)
	system_init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM((void *)UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, (void *)UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	printf("Startup...\r\n");

	// Infinite loop
	while (1) {
		uint8_t duty;
		/*if (!UART_is_buffer_empty()) {
			char command[64];
			gets(command);
			duty = atoi(command);
			duty_cycle_funct(duty);
		}*/

		//duty_cycle_funct(ADC_Read() / 10.23);
		duty = ADC_Read() / 10.23;
		printf("%d\t",duty);		
		LED_PORT |= 1 << LED_PORT_POS;
		_delay_ms(5);
		LED_PORT &= ~(1 << LED_PORT_POS);
		_delay_ms(5);
		printf("%.0f Hz\t", get_freq());
		
		
		
		float P = 0.1;
		float ref = duty * 50;
		float err = ref -get_rpm();
		float ctrler_out = P * err;
		float ctrler_out_min = 0;
		float ctrler_out_max = 100;
		
		if (ctrler_out < ctrler_out_min)
			ctrler_out = ctrler_out_min;
		else if (ctrler_out > ctrler_out_max)
			ctrler_out = ctrler_out_max;
			
		duty_cycle_funct(ctrler_out);
		printf("%.0f\t\n", ctrler_out);
		printf("%.0f RPM\t %.0f refRPM\t", get_rpm(), ref);
	}
}
