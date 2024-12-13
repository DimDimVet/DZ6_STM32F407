#include "Task4.h"

/*Задание 4
Напишите программы для микроконтроллеров STM32/K1986BE92, которые меняют яркость светодиода с помощью ШИМ.
 Изменение коэффициента заполнения 0%, 20%, 40%, 60%, 80%, 100% происходит по нажатию кнопки.
*/

#if TASK==4

int countFillFactor=0;

void EXE_TASK4()
{
    RCC_INIT();

    APB2_INIT_PERIPHERY(RCC_APB2ENR_SYSCFGEN);

    APB1_INIT_PERIPHERY(RCC_APB1ENR_TIM3EN);
    AHB1_INIT_PERIPHERY(RCC_AHB1ENR_GPIOAEN);
    AHB1_INIT_PERIPHERY(RCC_AHB1ENR_GPIOEEN);

    GPIO_Init();
		OdrGPIOA_Or(GPIO_ODR_OD7);
		
    AFRL_GPIOA(GPIO_MODER_MODER6,GPIO_MODER_MODER6_1, 2, 6);
    //INIT_TIM_PWR();
    INIT_EXTI();

}

void INIT_TIM_PWR(int fillFactor)
{
    // Устанавливаем предделитель и авто-перезагрузку
    TIM3->PSC = 8400 - 1; // делитель
    TIM3->ARR = 100 - 1; // автосброс

    //ШИМ TIM3_CH1 PA6
    TIM3->CCR1 = fillFactor; // Коэффициент заполнения
    TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // режим ШИМ

    TIM3->CCMR1 |= TIM_CCMR1_OC1PE; // включен регистр предварительной загрузки
    TIM3->CCER |= TIM_CCER_CC1E; // включаем TIM3_CH1

    // Запуск таймера
    TIM3->CR1 |= TIM_CR1_CEN;
}

void INIT_EXTI()
{
    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI4_PE; // cвязка PE4 с EXTI
    EXTI->IMR |= EXTI_IMR_MR4; // Разрешение irq
    EXTI->FTSR |= EXTI_FTSR_TR4; // Прерывание на спад

    NVIC_EnableIRQ(EXTI4_IRQn);
}

void EXTI4_IRQHandler()
{

if (EXTI->PR & EXTI_PR_PR4)   // проверим флаг irq
    {
        EXTI->PR |= EXTI_PR_PR4; // reset флага

        //OdrGPIOA_Xor(GPIO_ODR_OD7);
        countFillFactor+=15;
        if(countFillFactor<=100)
        {
            INIT_TIM_PWR(countFillFactor);
        }
        else
        {
            countFillFactor=0;
            INIT_TIM_PWR(countFillFactor);
        }
    }

}
#endif
