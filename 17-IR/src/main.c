#include <8052.h>
#include "LCD1602.h"
#include "Int0.h"

unsigned char Num = 0;
int main(void)
{
    LCD_Init();
    LCD_ShowString(1, 1, "Num:");

    Int0_Init();

    while (1)
    {
        LCD_ShowNum(2, 1, Num, 3);
    }
}

void Int0_Routine(void) __interrupt(0) __using(0)
{
    Num++;
}