#include <8052.h>
#include "Delay.h"
#include "UART.h"

unsigned char KeyNum = 0, LCDNum = 0;
int main(void)
{
    UART_Init();
    while (1)
    {
    }
}

void UART_ReceiveByte() __interrupt(4) __using(4)
{
    if (RI == 1)
    {
        P2 = SBUF;
        UART_SendByte(SBUF); // Serial Tool echo the received byte
        RI = 0; // Clear the Receive Interrupt Flag
    }
}