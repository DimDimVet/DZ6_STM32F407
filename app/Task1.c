#include "Task1.h"

/*Задание 1
Доработайте программы led_blinking для микроконтроллеров STM32/K1986BE92,
выполняющие задержку при помощи функции, которая меняет числовое значение по прерыванию от системного таймера.
*/

#if TASK==1

int count = 0;

void EXE_TASK1(int ticks)
{
    RCC_INIT();
    SysTick_Config(SystemCoreClock / ticks);

    AHB1_INIT_PERIPHERY(RCC_AHB1ENR_GPIOAEN);
    GPIO_Init();
}

void LED_Activ_SYSCLK()
{
    OdrGPIOA_Xor(GPIO_ODR_OD6);
    OdrGPIOA_Xor(GPIO_ODR_OD7);
}

void SysTick_Handler(void)
{
    count++;
}

void delay(int ms)
{
    count = 0;
    if(ms==0)
    {
        ms=1;
    }
    else
    {
        while (count < ms)
        {

        }
    }
}

#endif

