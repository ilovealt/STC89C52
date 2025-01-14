#include <8052.h>

void UART_Init(void)
{
    SCON = 0x50; // 8-bit UART mode, `REN` is set to 1
    PCON = 0x80; // Set SMOD bit
    TMOD = TMOD & 0x0F; // Clear the higher 4 bits of TMOD
    TMOD = TMOD | 0x20; // Set the higher 4 bits of TMOD to 0010

    TH1 = 0xFA;  // TL1重装值，波特率为9600
    TL1 = 0xFA;  // 9600 baud rate

    ET1 =  0;    // Disable Timer 1 interrupt
    TR1 = 1;     // Start timer 1

    EA=1;       //开总中断
	ES=1;      //开串口中断
}

/**
  * @brief  串口发送一个字节数据
  * @param  Byte 要发送的一个字节数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte) 
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

/*
void UART_ReceiveByte() __interrupt(4) __using(4)
{
    if (RI == 1)
    {
        // TODO
        RI = 0;
    }
}
*/