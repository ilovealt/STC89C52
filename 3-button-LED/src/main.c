#include <8052.h>

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 125; j++)
            ;
    }
}

void main()
{
    /**
     * P3_0: K2
     * P3_1: K1
     * P2_0: LED1
     * K1按键或K2按键按下, LED1点亮
     * 否则LED1熄灭

    while(1) {
        if (P3_0 == 0 || P3_1 == 0)
        {
            P2_0 = 0;
        } else {
            P2_0 = 1;
        }
    }
    */

    /**
     * P3_1: K1
     * P2_0: LED1
     * K1按键按下, LED1取反
     * 按键消抖
     * TODO: 不好用

    while(1) {
        if (P3_1 == 0) {
            delay_ms(20);
            while (P3_1 == 0);
            delay_ms(20);
            P2_0=~P2_0;
        }
    }
    */

    /**
     * P3_1: K1
     * P2: LED1-LED8
     * K1按键按下, 依次点亮LED1-LED8
     * 按键消抖

    unsigned char ledNum = 0;
    while(1) {
        if (P3_1 == 0) {
            delay_ms(20);
            while (P3_1 == 0);
            delay_ms(20);

            ledNum++;
            P2=~ledNum;
        }
    }
    */

    /**
     * P3_1: K1
     * P3_0: K2
     * P2: LED1-LED8
     * K1按键按下, 灯从LED1-LED8依次点亮
     * K2按键按下, 灯从LED8-LED1依次点亮
     * 按键消抖
     */
    unsigned char ledNum = 0x01;
    P2 = ~ledNum;
    while (1)
    {
        if (P3_1 == 0)
        {
            delay_ms(20);
            while (P3_1 == 0)
                ;
            delay_ms(20);

            unsigned char temp = ledNum << 1;
            ledNum = temp == 0 ? 0x80 : temp;
            P2 = ~ledNum;
        }
        if (P3_0 == 0)
        {
            delay_ms(20);
            while (P3_0 == 0)
                ;
            delay_ms(20);

            unsigned char temp = ledNum >> 1;
            ledNum = temp == 0 ? 0x01 : temp;
            P2 = ~ledNum;
        }
    }
}