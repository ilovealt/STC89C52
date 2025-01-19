#include <8052.h>

void Timer0Init()
{
    // Set Timer0 as 16-bit timer
    TMOD = TMOD & 0xF0; // Clear the lower 4 bits of TMOD
    TMOD = TMOD | 0x01; // Set the lower 4 bits of TMOD to 0001

    // set the initial value of Timer0，the initial value of Timer0 is 65535-100=65435
    TH0 = 0xFF;
    TL0 = 0x9C;

    TF0 = 0; // Clear the Timer0 overflow flag
    TR0 = 1; // Start Timer0

    ET0 = 1; // Enable Timer0 interrupt
    EA = 1;  // Enable global interrupt
}

/*定时器中断函数模板
void Timer0_Routine() __interrupt(1) __using(1)
{

    static unsigned int T0Count;
    TH0 = 0xFC; // 设置定时初值
    TL0 = 0x18; // 设置定时初值

    T0Count++;
    if (T0Count >= 2000)
    {
        T0Count = 0;
        Switch_P2_0();
    }
}
*/