#include <8052.h>
#include "Delay.h"
#include "AT24C02.h"

int main(void)
{
    unsigned char i, dat, led;
    AT24C02_Write(0, 1);
    dat = AT24C02_Read(0);
    // 由于P2_0和P2_1被I2C占用，所以只能用其他引脚
    for (i = 0; i < 8; i++)
    {
        P2_7 = dat & (0x01 << i);
        DelayMS(500);
    }
    while (1)
    {
    }
}
