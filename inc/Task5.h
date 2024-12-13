#include "RCC_F407.h"
#include "GPIO_F407.h"
#include "TaskSwitch.h"

#ifndef TASK5_H_
#define TASK5_H_

void EXE_TASK5(int currentFreg);
void INIT_TIM_PWR(int fillFactor);
void INIT_EXTI(void);

#endif
