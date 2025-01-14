#ifndef __ROTATE_H__
#define __ROTATE_H__

/**
 * @brief  循环左移
 * @param  value: 待移位的值
 * @param  shift_count: 移位的位数
 * @retval 移位后的值
 */
unsigned char RotateLeft(unsigned char value, unsigned char shift_count);

/**
 * @brief  循环右移
 * @param  value: 待移位的值
 * @param  shift_count: 移位的位数
 * @retval 移位后的值
 */
unsigned char RotateRight(unsigned char value, unsigned char shift_count);

#endif