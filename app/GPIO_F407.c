#include "GPIO_F407.h"

void GPIO_Init()
{
    OutPin();
}

//Out
void OutPin()
{
    LedConfigOutPin();
}

// LED2 PA6 31pin
// LED3 PA7 32pin
void LedConfigOutPin()
{
    GPIOA->MODER &= ~ (GPIO_MODER_MODER6|GPIO_MODER_MODER7); // сброс
    GPIOA->MODER |= (GPIO_MODER_MODER6_0|GPIO_MODER_MODER7_0);//режим на выход
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED6|GPIO_OSPEEDR_OSPEED7); // сброс скорости
    GPIOA->OSPEEDR |= (GPIO_OSPEEDR_OSPEED6_0|GPIO_OSPEEDR_OSPEED7_0); // установка средней скорости
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD6|GPIO_PUPDR_PUPD7); // сброс режим подтяжки
    GPIOA->PUPDR |= (GPIO_PUPDR_PUPD6_0|GPIO_PUPDR_PUPD7_0); // установка подтяжки к + (1)  РА0
    GPIOA->OTYPER &= ~ (GPIO_OTYPER_OT6|GPIO_OTYPER_OT7); // сброс режима нагрузки
    GPIOA->OTYPER |= (GPIO_OTYPER_OT6|GPIO_OTYPER_OT7); // установка в режим с открытым коллектором
}


//Altern
void AFRH_GPIOA(int resetBit,int setBit, int AFx, int PAx)
{
    GPIOA->MODER &= ~resetBit;//сброс
    GPIOA->MODER |= setBit;//установка
    GPIOA->AFR[1] |= (AFx << ((PAx-8) * 4));//выбор функции
}

void AFRL_GPIOB(int resetBit,int setBit, int AFx, int PBx)
{
    GPIOB->MODER &= ~resetBit;//сброс
    GPIOB->MODER |= setBit;//установка
    GPIOB->AFR[0] |= (AFx << (PBx * 4));//выбор функции
}

//побитовые выполнители
void OdrGPIOA_Xor(int PAx)
{
    GPIOA->ODR ^= PAx;
}

void OdrGPIOA_Or(int PAx)
{
    GPIOA->ODR |= PAx;
}
