#include <8052.h>

/**
 * @brief  外部中断0初始化
 * @param  无
 * @retval 无
 */
void Int0_Init(void)
{
    IT0 = 1; // 触发方式选择
    IE0 = 0; // 清除中断标志
    EX0 = 1; // 开启中断
    EA = 1;  // 开启总中断
    PX0 = 1; // 设置中断优先级
}

/*外部中断0中断函数模板
void Int0_Routine(void) __interrupt(0) __using(0)
{

}
*/