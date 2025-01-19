#include <8052.h>

__sbit __at(0xB7) OneWire_DQ;

unsigned char OneWire_Init()
{
    unsigned char i, ack_bit;
    OneWire_DQ = 1;
    OneWire_DQ = 0; // pull down the DQ

    i = 227;
    while (--i)
        ; // delay 500us

    OneWire_DQ = 1; // release the DQ

    i = 29;
    while (--i)
        ; // delay 70us

    ack_bit = OneWire_DQ; // read the ack signal

    i = 227;
    while (--i)
        ; // delay 500us

    return ack_bit;
}

void OneWire_SendBit(unsigned char bit)
{
    unsigned char i;
    OneWire_DQ = 0; // pull down the DQ

    i = 2;
    while (--i)
        ; // delay 10us

    OneWire_DQ = bit; // send the bit

    i = 20;
    while (--i)
        ; // delay 50us

    OneWire_DQ = 1; // release the DQ
}

unsigned char Onewire_ReceiveBit(void)
{
    unsigned char i, bit;
    OneWire_DQ = 0; // pull down the DQ

    i = 1;
    while (--i)
        ; // delay 5us

    OneWire_DQ = 1; // release the DQ

    i = 1;
    while (--i)
        ; // delay 5us

    bit = OneWire_DQ; // read the bit

    i = 20;
    while (--i)
        ; // delay 50us

    return bit;
}

void OneWire_SendByte(unsigned char byte)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        OneWire_SendBit(byte & (0x01 << i));
    }
}

unsigned char OneWire_ReceiveByte(void)
{
    unsigned char i, byte;
    for (i = 0; i < 8; i++)
    {
        if (Onewire_ReceiveBit())
        {
            byte |= (0x01 << i);
        }
    }
    return byte;
}