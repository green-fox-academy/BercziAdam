/*
 * pwm_fan_controll_via_uart.c
 *
 * Created: 6/12/2017 3:14:33 PM
 * Author : Adam
 */ 

#include "UART_driver.h"
#include "pwmfunctions.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>
int main(void)
{
	char buffer[4];
	pwm_init();
	UART_Init();
	sei();
	
	FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
	stdin = &UART_input;
	
	printf("Startup...\n");
	while (1)
	{
		uint8_t command;
		printf("Please enter the duty cycle in [0-100]%.\n");
		scanf(" %d",&command);
		printf("%d\n", command);

		if (command <=100 && command >=0) 
			duty_cycle_funct(command);
		else
			printf("Invalid number!\n");
	}
}

