#include <8052.h>
#include "Delay.h"
#include "Time0.h"
#include "LCD1602.h"

unsigned char num = 0;
int main(void)
{
    LCD_Init();
    LCD_ShowString(1, 1, "Temperature:");
    while (1)
    {
        TimerDelay1ms();
        LCD_ShowNum(2, 1, num++, 3);
    }
}
