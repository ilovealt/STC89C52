#ifndef __DELAY_H__
#define __DELAY_H__

/**
 * @brief  延时函数，11.0592MHz调用可延时ms
 * @param  ms 要延时的毫秒数
 * @retval 无
 */
void Delayms(unsigned int ms);

/**
 * @brief  延时函数，11.0592MHz调用可延时1ms
 * @param  无
 * @retval 无
 */
void Delay1ms(void);

#endif // __DELAY_H__