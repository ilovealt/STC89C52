#include <8052.h>

__sbit __at(0xB4) DS1302_IO;
__sbit __at(0xB5) DS1302_CE;
__sbit __at(0xB6) DS1302_SCLK;

void DS1302_Init()
{
    DS1302_CE = 0;
    DS1302_SCLK = 0;
}

void DS1302_Write(unsigned char commond, unsigned char data)
{
    DS1302_CE = 1;
    for (unsigned char i = 0; i < 8; i++)
    {
        DS1302_IO = commond & (0x01 << i);
        // 切换要考虑时钟频率，时钟频率太高可能会导致数据丢失。
        DS1302_SCLK = 1; // 时钟上升沿
        DS1302_SCLK = 0; // 时钟下降沿
    }
    for (unsigned char i = 0; i < 8; i++)
    {
        DS1302_IO = data & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    DS1302_CE = 0;
}

unsigned char DS1302_Read(unsigned char commond)
{
    DS1302_CE = 1;
    for (unsigned char i = 0; i < 8; i++)
    {
        DS1302_IO = commond & (0x01 << i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    // 读取数据
    unsigned char data = 0x00;
    for (unsigned char i = 0; i < 8; i++)
    {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        if (DS1302_IO)
        {
            data |= (0x01 << i);
        }
    }
    DS1302_CE = 0;
    DS1302_IO = 0; // 释放IO
    return data;
}

void DS1302_UnlockWriteProtection(void)
{
    unsigned char control_reg;
    DS1302_Init();
    // 读取当前控制寄存器的值
    control_reg = DS1302_Read(0x8E);
    // 清除WP位（第7位）
    control_reg &= 0x7F;
    // 写回新的控制寄存器值
    DS1302_Write(0x8E, control_reg);
}