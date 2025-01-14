#include <8052.h>

void Timer0Init()
{
    // Set Timer0 as 16-bit timer
    TMOD = TMOD & 0xF0; // Clear the lower 4 bits of TMOD
    TMOD = TMOD | 0x01; // Set the lower 4 bits of TMOD to 0001

    // set the initial value of Timer0，the initial value of Timer0 is 65535-1000=64535
    TH0 = 0xFC; // Set the initial value of TH0, 64535/256=252.34, 252=0xFC
    TL0 = 0x18; // Set the initial value of TL0, 64535%256=23, 23=0x17, There is still 1 gap to overflow.

    TF0 = 0; // Clear the Timer0 overflow flag
    TR0 = 1; // Start Timer0

    ET0 = 1; // Enable Timer0 interrupt
    EA = 1;  // Enable global interrupt
    // PT0 = 0; // Set the priority of Timer0 interrupt to low, default is low
    // PT0H = 0; // Set the priority of Timer0 interrupt to low, default is low
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