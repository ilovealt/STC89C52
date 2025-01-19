#include <8052.h>
#include "Delay.h"
#include "Time0.h"
#include "Key.h"

unsigned char Counter, Compare = 0;
unsigned char Key1, Speed;
int main(void)
{
    Timer0Init();

    while (1)
    {
        Key1 = Key();
        if (Key1 == 1)
        {
            Speed++;
            Speed %= 4;
            if (Speed == 0)
            {
                Compare = 0;
            }
            if (Speed == 1)
            {
                Compare = 50;
            }
            if (Speed == 2)
            {
                Compare = 75;
            }
            if (Speed == 3)
            {
                Compare = 100;
            }
        }
    }
}

void Timer0_PWM() __interrupt(1) __using(1)
{
    // 重新赋初值, 100个计数
    TH0 = 0xFF;
    TL0 = 0x9C;
    Counter++;
    Counter %= 100;
    if (Counter < Compare)
    {
        P1_0 = 1;
    }
    else
    {
        P1_0 = 0;
    }
}