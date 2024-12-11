#include "RCC_F407.h"
#include "GPIO_F407.h"
#include "TaskSwitch.h"

#ifndef TASK1_H_
#define TASK1_H_

void EXE_TASK1(int ticks);
void delay(int ms);
void LED_Activ_SYSCLK(void);

#endif
