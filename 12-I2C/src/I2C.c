#include <8052.h>

__sbit __at(0xA0) I2C_SDA;
__sbit __at(0xA1) I2C_SCL;

void I2C_Start(void)
{
    I2C_SDA = 1;
    I2C_SCL = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;
}

void I2C_Stop(void)
{
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}

void I2C_SendByte(unsigned char dat)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        I2C_SDA = dat & (0x80 >> i);
        I2C_SCL = 1;
        I2C_SCL = 0;
    }
}

unsigned char I2C_ReadByte(void)
{
    unsigned char i, dat = 0x00;
    I2C_SDA = 1; // 释放总线
    for (i = 0; i < 8; i++)
    {
        I2C_SCL = 1;
        if (I2C_SDA)
        {
            dat |= (0x80 >> i);
        }
        I2C_SCL = 0;
    }
    return dat;
}

void I2C_SendAck(unsigned char ack)
{
    I2C_SDA = ack;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

unsigned char I2C_ReadAck(void)
{
    unsigned char ack;
    I2C_SDA = 1;
    I2C_SCL = 1;
    ack = I2C_SDA;
    I2C_SCL = 0;
    return ack;
}