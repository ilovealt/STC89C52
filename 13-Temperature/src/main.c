#include <8052.h>
#include "LCD1602.h"
#include "OneWire.h"

unsigned char num = 0;
int main(void)
{
    unsigned char temp;
    LCD_Init();
    LCD_ShowString(1, 1, "Temperature:");
    temp = OneWire_Init();
    LCD_ShowNum(2, 1, temp, 3);
    while (1)
    {
    }
}
