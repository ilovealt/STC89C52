#include <8052.h>

/**
 * @brief  定时器0初始化
 * @param  无
 * @retval 无
 */
void Timer0_Init()
{
    // Set Timer0 as 16-bit timer
    TMOD = TMOD & 0xF0; // Clear the lower 4 bits of TMOD
    TMOD = TMOD | 0x01; // Set the lower 4 bits of TMOD to 0001

    // set the initial value of Timer0，the initial value is 0
    TH0 = 0;
    TL0 = 0;

    TF0 = 0; // Clear the Timer0 overflow flag
    TR0 = 0; // Start Timer0
}

/**
 * @brief  定时器0启动停止控制
 * @param  Flag 启动停止标志，1为启动，0为停止
 * @retval 无
 */
void Timer0_Run(unsigned char Flag)
{
    TR0 = Flag;
}

/**
 * @brief  定时器0设置计数器值
 * @param  Value，要设置的计数器值，范围：0~65535
 * @retval 无
 */
void Timer0_SetCounter(unsigned int Value)
{
    TH0 = Value / 256;
    TL0 = Value % 256;
}

/**
 * @brief  定时器0获取计数器值
 * @param  无
 * @retval 计数器值，范围：0~65535
 */
unsigned int Timer0_GetCounter(void)
{
    return (TH0 << 8) | TL0;
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