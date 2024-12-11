#include "RCC_F407.h"
#include "GPIO_F407.h"
#include "TaskSwitch.h"

#ifndef TASK3_H_
#define TASK3_H_

void EXE_TASK3(int currentFreg);
void LED_Activ_TIM(void);
void INIT_TIM(int ms);

#endif
