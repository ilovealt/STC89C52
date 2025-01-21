#include <8052.h>
#include "Delay.h"
#include "LCD1602.h"
#include "Time0.h"

unsigned int num;
int main(void)
{
    LCD_Init();
    LCD_ShowString(1, 1, "Num:");

    Timer0_Init();

    while (1)
    {
        Timer0_SetCounter(0);
        Timer0_Run(1);

        Delayms(5);

        num = Timer0_GetCounter();
        LCD_ShowNum(2, 1, num, 6);
    }
}
