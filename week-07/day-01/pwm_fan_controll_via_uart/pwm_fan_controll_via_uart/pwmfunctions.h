//#ifndef PWMFUNCTIONS_H_INCLUDED
//#define PWMFUNCTIONS_H_INCLUDED
#include <stdint.h>

void pwm_init();
void led_flasher();
void duty_cycle_funct(uint8_t duty_cycle);


//#endif