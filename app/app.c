#include "app.h"

int main()
{

#if TASK==1

    EXE_TASK1(1000);

    while (1)
    {
        LED_Activ_SYSCLK();
        delay(1000); // 1000=1 сек по SysCLK
    }

#elif TASK==2

    EXE_TASK2(8000,500);

    while (1)
    {
        LED_Activ_TIM();
    }

#elif TASK==3

    EXE_TASK3(8000);

    while (1)
    {
        LED_Activ_TIM();
        delay(3000);
    }

#elif TASK==4

    EXE_TASK4();

    while (1)
    {
        
    }

#elif TASK==5

    EXE_TASK5(8000);

    while (1)
    {
        LED_Activ_TIM();
        delay(3000);
    }
#endif

}

