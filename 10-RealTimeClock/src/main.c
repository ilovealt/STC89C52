#include <8052.h>
#include "Delay.h"
#include "DS1302.h"

unsigned char read;
int main(void)
{
    // 清除写保护
    DS1302_UnlockWriteProtection();

    DS1302_Init();
    DS1302_Write(0x80, 0x02);
    while (1)
    {
        read = DS1302_Read(0x81);
        P2 = read;
    }
}
