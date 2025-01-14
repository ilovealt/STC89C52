#include <8052.h>
#include "Delay.h"

/**
 * @brief  矩阵键盘读取按键键码
 * @param  无
 * @retval KeyNumber 按下按键的键码值
 *             如果按键按下不放，程序会停留在此函数，松手的一瞬间，返回按键键码，没有按键按下时，返回0
 */
unsigned char Key()
{
    unsigned char KeyNumber = 0;

    if (P3_1 == 0)
    {
        DelayMS(20);
        while (P3_1 == 0)
            ;
        DelayMS(20);
        KeyNumber = 1;
    }
    if (P3_0 == 0)
    {
        DelayMS(20);
        while (P3_0 == 0)
            ;
        DelayMS(20);
        KeyNumber = 2;
    }
    if (P3_2 == 0)
    {
        DelayMS(20);
        while (P3_2 == 0)
            ;
        DelayMS(20);
        KeyNumber = 3;
    }
    if (P3_3 == 0)
    {
        DelayMS(20);
        while (P3_3 == 0)
            ;
        DelayMS(20);
        KeyNumber = 4;
    }

    return KeyNumber;
}