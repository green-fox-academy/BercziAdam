/*
 * IncFile1.h
 *
 * Created: 6/7/2017 11:26:45 AM
 *  Author: Adam
 */ 

// Multiple inclusion guard
#ifndef _TC74_DRIVER_H
#define _TC74_DRIVER_H

#include <stdint.h>

#define TC_WRITE	0
#define TC_READ		1
//TODO
//Define the TC74A0 address
#define  ADDRESS	0b1001 000

void TWI_init(void);
void TWI_start(void);
void TWI_write(uint8_t u8data);
void TWI_stop(void);
uint8_t TWI_read_nack(void);
uint8_t TWI_read_ack(void);
uint8_t get_temperature(ADDRESS);

#endif // _TC74_DRIVER_H