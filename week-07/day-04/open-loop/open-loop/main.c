/*
 * open-loop.c
 *
 * Created: 6/15/2017 12:50:47 PM
 * Author : Adam
 */ 

#include "freq_meas.h"
#include "UART_driver.h"
#include "AC_driver.h"
#include "pwmfunctions.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdlib.h>

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
		// Generating an about 1Hz signal on the LED pin.
		// The printf call will also take some time, so this won't be exactly 1Hz.
		duty_cycle_funct(ADC_Read() / 10.23);
		printf("%f\n", ADC_Read() / 10.23);
		LED_PORT |= 1 << LED_PORT_POS;
		_delay_ms(50);
		LED_PORT &= ~(1 << LED_PORT_POS);
		_delay_ms(50);
		printf("%f Hz\n", get_freq());
		printf("%f RPM\n", get_rpm());
		/*uint8_t command;
		printf("Please enter the duty cycle in [0-100]%.\n");
		scanf(" %d",&command);
		printf("%d\n", command);

		if (command <=100 && command >=0) 
			duty_cycle_funct(command);
		else
			printf("Invalid number!\n");*/
	}
}