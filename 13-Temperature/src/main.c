#include <8052.h>
#include "LCD1602.h"
#include "Delay.h"
#include "DS18B20.h"

unsigned char num = 0;
int main(void)
{
    LCD_Init();
    LCD_ShowString(1, 1, "Temperature:");
    DS18B20_CovertT();
    Delayms(1000);

    float temperture;
    while (1)
    {
        DS18B20_CovertT();
        temperture = DS18B20_ReadT();
        LCD_ShowNum(2, 1, temperture, 3);
        // 如果温度小于0,如果温度大于等于0
        if (temperture < 0)
        {
            LCD_ShowChar(2, 1, '-');
            temperture = -temperture; // 将温度变为正数
        }
        else
        {
            LCD_ShowChar(2, 1, '+');
        }
        LCD_ShowNum(2, 2, temperture, 3);                                  // 显示温度整数部分
        LCD_ShowChar(2, 5, '.');                                           // 显示小数点
        LCD_ShowNum(2, 6, (unsigned long)(temperture * 10000) % 10000, 4); // 显示温度小数部分
    }
}
