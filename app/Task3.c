#include "Task3.h"

/*Задание 3
Напишите программы для микроконтроллеров STM32/K1986BE92,
 выполняющие задержку светодиода по функции задержки,
 которая построена на основе прерывания от таймера общего назначения (по аналогии с заданием 1).
*/

#if TASK==3

int count=0;
int thisCurrentFreg;

void EXE_TASK3(int currentFreg)
{
    thisCurrentFreg=currentFreg;

    RCC_INIT();

    AHB1_INIT_PERIPHERY(RCC_AHB1ENR_GPIOAEN);

    GPIO_Init();
}

void INIT_TIM(int ms)
{
    APB1_INIT_PERIPHERY(RCC_APB1ENR_TIM2EN);

    TIM2->PSC = thisCurrentFreg - 1; // делим
    TIM2->ARR = ms - 1; // перегружаем
    TIM2->DIER |= TIM_DIER_UIE; // прерывание по переполнению
    NVIC_EnableIRQ(TIM2_IRQn); // старт прерывания
    TIM2->CR1 |= TIM_CR1_CEN; // старт таймера
}

void LED_Activ_TIM()
{
    OdrGPIOA_Xor(GPIO_ODR_OD6);
    OdrGPIOA_Xor(GPIO_ODR_OD7);
}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF; 
				count=1;
    }
}

void delay(int ms)
{
    count = 0;
    INIT_TIM(ms);
    while (!count);
}

#endif

