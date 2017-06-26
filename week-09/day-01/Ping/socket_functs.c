#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include<time.h>
#include "socket_functs.h"

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

