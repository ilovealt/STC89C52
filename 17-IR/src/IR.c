#include <8052.h>
#include "Time0.h"
#include "Int0.h"

/**
 * @brief  红外初始化
 * @param  无
 * @retval 无
 */
void IR_Init(void)
{
    Int0_Init();
    Timer0_Init();
}

/**
 * @brief  获取红外数据标志，外部中断0中断函数，下降沿触发执行
 * @param  无
 * @retval 红外数据标志
 */
void Int0_Routine(void) __interrupt(0) __using(0)
{
}