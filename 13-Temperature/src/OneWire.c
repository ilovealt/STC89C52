#include <8052.h>
#include "Delay.h"

__sbit __at(0xB7) OneWire_DQ;

unsigned char OneWire_Init()
{
    unsigned char ack_bit;
    OneWire_DQ = 1;
    OneWire_DQ = 0; // pull down the DQ
    Delay500us();
    OneWire_DQ = 1; // release the DQ
    Delay70us();
    ack_bit = OneWire_DQ; // read the ack signal
    Delay500us();

    return ack_bit;
}