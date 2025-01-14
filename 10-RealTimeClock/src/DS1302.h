#ifndef __DS1302_H__
#define __DS1302_H__

/**
 * @brief  DS1302初始化
 * @param  void 无
 * @retval 无
 */
void DS1302_Init(void);
void DS1302_Write(unsigned char commond, unsigned char dat);
unsigned char DS1302_Read(unsigned char commond);
/**
 * @brief  DS1302解锁写保护
 * @param  void 无
 * @retval 无
 */
void DS1302_UnlockWriteProtection();

#endif // __DS1302_H__