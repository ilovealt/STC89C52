#include <8052.h>
#include "Delay.h"
#include "Time0.h"
#include "Key.h"
#include "Rotate.h"

unsigned char KeyNum = 0, LCDNum = 0;
int main(void)
{
    // P2_0 = 0;
    P2 = 0xFE;
    Timer0Init(); // 初始化定时器0
    while (1)
    {
        KeyNum = Key();
        if (KeyNum)
        {
            LCDNum = KeyNum;
        }
    }
}

void Switch_P2_0()
{
    if (P2_0)
    {
        P2_0 = 0;
    }
    else
    {
        P2_0 = 1;
    }
}

void Timer0_Routine() __interrupt(1) __using(1)
{

    static unsigned int T0Count;
    TH0 = 0xFC; // 设置定时初值
    TL0 = 0x18; // 设置定时初值

    T0Count++;
    if (T0Count >= 1000)
    {
        T0Count = 0;
        // Switch_P2_0(); // P2_0 翻转
        if (LCDNum) // 如果LCDNum不为0, 则进行左移或右移
        {
            if (LCDNum % 2 == 0)
            {
                P2 = RotateRight(P2, 1);
            }
            else
            {
                P2 = RotateLeft(P2, 1);
            }
        }
    }
}
