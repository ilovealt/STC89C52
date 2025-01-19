#include <8052.h>
#include "OneWire.h"

#define DS18B20_SKIP_ROM 0xCC
#define DS18B20_CONVERT_T 0x44
#define DS18B20_READ_SCRATCHPAD 0xBE

void DS18B20_CovertT(void)
{
    OneWire_Init();
    OneWire_SendByte(DS18B20_SKIP_ROM);
    OneWire_SendByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadT(void)
{
    unsigned char T_LSB, T_MSB;
    OneWire_Init();
    OneWire_SendByte(DS18B20_SKIP_ROM);
    OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
    T_LSB = OneWire_ReceiveByte();
    T_MSB = OneWire_ReceiveByte();

    int temp = (T_MSB << 8) | T_LSB;
    float temperature = temp / 16.0;
    return temperature;
}