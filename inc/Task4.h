#include "RCC_F407.h"
#include "GPIO_F407.h"
#include "TaskSwitch.h"

#ifndef TASK4_H_
#define TASK4_H_

void EXE_TASK4(void);
void INIT_TIM_PWR(int fillFactor);
void INIT_EXTI(void);

#endif
