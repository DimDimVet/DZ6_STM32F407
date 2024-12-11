#include "stm32f4xx.h" // Device header

#ifndef GPIO_F407_H_
#define GPIO_F407_H_

void GPIO_Init(void);
void OutPin(void);
void LedConfigOutPin(void);
//
void AFRH_GPIOA(int resetBit,int setBit, int AFx, int PAx);
void AFRL_GPIOB(int resetBit,int setBit, int AFx, int PBx);
//
void OdrGPIOA_Xor(int PAx);
void OdrGPIOA_Or(int PAx);

#endif
