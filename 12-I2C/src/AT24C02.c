#include <8052.h>
#include "I2C.h"

#define AT24C02_ADDR 0xA0 // 1010 0000

void AT24C02_Write(unsigned char addr, unsigned char dat)
{
    I2C_Start();
    I2C_SendByte(AT24C02_ADDR);
    I2C_ReadAck();
    I2C_SendByte(addr);
    I2C_ReadAck();
    I2C_SendByte(dat);
    I2C_ReadAck();
    I2C_Stop();
}

unsigned char AT24C02_Read(unsigned char addr)
{
    unsigned char dat;
    I2C_Start();
    // 发送设备地址
    I2C_SendByte(AT24C02_ADDR);
    I2C_ReadAck();
    I2C_SendByte(addr);
    I2C_ReadAck();
    // 重新启动
    I2C_Start();
    I2C_SendByte(AT24C02_ADDR | 0x01);
    I2C_ReadAck();
    dat = I2C_ReadByte();
    I2C_SendAck(1);
    I2C_Stop();

    return dat;
}