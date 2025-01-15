#include <8052.h>
#include "Delay.h"
#include "AT24C02.h"
#include "LCD1602.h"

int main(void)
{
    unsigned char i, dat = 0;
    // 初始化LCD
    LCD_Init();
    LCD_ShowString(1, 1, "I2C: AT24C02");
    AT24C02_Write(0x01, 0x01);
    dat = AT24C02_Read(0x01);
    LCD_ShowNum(2, 1, dat, 3);

    while (1)
    {
    }
}
