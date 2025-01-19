#include <8052.h>

void TimerDelay1ms(void)
{
    // Set Timer0 as 16-bit timer
    TMOD = TMOD & 0xF0; // Clear the lower 4 bits of TMOD
    TMOD = TMOD | 0x01; // Set the lower 4 bits of TMOD to 0001

    // set the initial value of Timer0，the initial value of Timer0 is 65535-1000=64535
    TH0 = 0xFC; // Set the initial value of TH0, 64535/256=252.34, 252=0xFC
    TL0 = 0x18; // Set the initial value of TL0, 64535%256=23, 23=0x17, There is still 1 gap to overflow.

    TF0 = 0; // Clear the Timer0 overflow flag
    TR0 = 1; // Start Timer0
    while (!TF0)
        ;    // Wait for Timer0 to overflow
    TR0 = 0; // Stop Timer0
}