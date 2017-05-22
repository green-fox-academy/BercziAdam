#include "UART_driver.h"

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>


#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

void SystemInit() {
    // Call the UART driver init function
    // Keep in mind that the UART will run at 115200 baud/sec
    UART_Init();

    // Enable interrupts globally, UART uses interrupts
    sei();
}

int main(void) {
    // Don't forget to call the init function :)
    SystemInit();

    // Setting up STDIO input and output buffer
    // You don't have to understand this!
    //----- START OF STDIO IO BUFFER SETUP
    FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
    stdout = &UART_output;
    FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
    stdin = &UART_input;
    //----- END OF STDIO IO BUFFER SETUP

    printf("Startup...\r\n");

    // Infinite loop
    while (1) {

    }
}
