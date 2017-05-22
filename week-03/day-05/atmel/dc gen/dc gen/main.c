#include "ADC_driver.h"
#include "UART_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "MCP4821_driver.h"
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

void SystemInit() {
	// Initialize the LED pin as output
	LED_DDR |= 1 << LED_DDR_POS;
	// Set the LED to off as deafault
	LED_PORT &= ~(1 << LED_PORT_POS);

	// Call the DAC driver init function
	ADC_Init();

	// Call the UART driver init function
	// Keep in mind that the UART will run at 115200 baud/sec
	UART_Init();

	// Enable interrupts globally, UART uses interrupts
	sei();
}

int main(void) {
	uint16_t adc_data;

	// Don't forget to call the init function :)
	SystemInit();
	MCP4821_Init();
	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	printf("Startup...\r\n");

	// Infinite loop
	while (1) {
		if(!(rx_buffer.read_ptr == rx_buffer.write_ptr))
		{
			
			char tmp[60];
			gets(tmp);
			printf("%s", tmp);
			int x=atoi(tmp);
			if(x>4095){
				x=4095;
				}else if (x<0){
				x=0;
			}
			MCP4821_Data_t DAC_data;
			DAC_data.start_zero = 0;
			DAC_data.dont_care = 0;
			DAC_data.gain = 0;
			DAC_data.shutdown = 1;
			DAC_data.data=x;
			
			MCP4821_SendData(&DAC_data);
		}
		adc_data = ADC_Read();
		UART_SendCharacter(adc_data >> 2);
	}
}
