#include "Task2.h"

/*Задание 2
Напишите программы для микроконтроллеров STM32/K1986BE92,
которые переключают светодиод по переполнению таймера общего назначения.
*/

#if TASK==2

int isIteration=0;

void EXE_TASK2(int currentFreg, int autoReload)
{
    RCC_INIT();

    AHB1_INIT_PERIPHERY(RCC_AHB1ENR_GPIOAEN);
    APB1_INIT_PERIPHERY(RCC_APB1ENR_TIM2EN);

    TIM2->PSC = currentFreg - 1; // делим
    TIM2->ARR = autoReload - 1; // перегружаем
    TIM2->DIER |= TIM_DIER_UIE; // прерывание по переполнению
    NVIC_EnableIRQ(TIM2_IRQn); // старт прерывания
    TIM2->CR1 |= TIM_CR1_CEN; // старт таймера

    GPIO_Init();
}

void LED_Activ_TIM()
{
    if (isIteration)
    {
        OdrGPIOA_Xor(GPIO_ODR_OD6);
        OdrGPIOA_Xor(GPIO_ODR_OD7);
        isIteration=!isIteration;
    }
}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)// Проверка флага переполнения
    {
        TIM2->SR &= ~TIM_SR_UIF; // Сброс флага переполнения
        isIteration=!isIteration;
    }
}

#endif

