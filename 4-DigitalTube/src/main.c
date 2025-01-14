#include <8052.h>
#include "delay.h"

//数码管段码表
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void location(unsigned char loc)
{
    switch (loc)
    {
    case 1:
        P2_2 = 0;
        P2_3 = 0;
        P2_4 = 0;
        break;
    case 2:
        P2_2 = 1;
        P2_3 = 0;
        P2_4 = 0;
        break;
    case 3:
        P2_2 = 0;
        P2_3 = 1;
        P2_4 = 0;
        break;
    case 4: 
        P2_2 = 1;
        P2_3 = 1;
        P2_4 = 0;
        break;
    case 5:
        P2_2 = 0;
        P2_3 = 0;
        P2_4 = 1;
        break;
    case 6:
        P2_2 = 1;
        P2_3 = 0;
        P2_4 = 1;
        break;
    case 7: 
        P2_2 = 0;
        P2_3 = 1;
        P2_4 = 1;
        break;  
    case 8:
        P2_2 = 1;
        P2_3 = 1;
        P2_4 = 1;
        break;
    default:
        break;
    }
}

void zeroToNine()
{
    unsigned char i;
    for (i = 0; i < 10; i++)
    {
        P0 = NixieTable[i];
        delay_ms(1000);
        P0 = 0x00;
    }
}

void leftToRight()
{
    unsigned char i;
    for (i = 8; i >= 1; i--)
    {
        location(i);
        zeroToNine();
    }
}


void main()
{
    while (1)
    {
        leftToRight();
        delay_ms(2000);
    }
}