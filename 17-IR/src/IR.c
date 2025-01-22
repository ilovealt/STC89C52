#include <8052.h>
#include "Time0.h"
#include "Int0.h"

unsigned int IR_Time;
unsigned char IR_State;

unsigned char IR_Data[4];
unsigned char IR_pData;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;

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
 * @brief  获取红外数据标志
 * @param  无
 * @retval 红外数据标志
 */
unsigned char IR_GetDataFlag(void)
{
    if (IR_DataFlag)
    {
        IR_DataFlag = 0;
        return 1;
    }
    return 0;
}

/**
 * @brief  获取红外连发标志
 * @param  无
 * @retval 红外连发标志
 */
unsigned char IR_GetRepeatFlag(void)
{
    if (IR_RepeatFlag)
    {
        IR_RepeatFlag = 0;
        return 1;
    }
    return 0;
}

/**
 * @brief  获取红外地址
 * @param  无
 * @retval 红外地址
 */
unsigned char IR_GetAddress(void)
{
    return IR_Address;
}

/**
 * @brief  获取红外命令
 * @param  无
 * @retval 红外命令
 */
unsigned char IR_GetCommand(void)
{
    return IR_Command;
}

/**
 * @brief  字节取反
 * @param  num: 待取反的字节
 * @retval 取反后的字节
 */
unsigned char charXor(unsigned char num)
{
    return (num ^ 0xFF);
}

/**
 * @brief  获取红外数据标志，外部中断0中断函数，下降沿触发执行
 * @param  无
 * @retval 红外数据标志
 */
void Int0_Routine(void) __interrupt(0) __using(0)
{
    if (IR_State == 0) // 空闲状态
    {
        Timer0_SetCounter(0);
        Timer0_Run(1);
        IR_State = 1;
    }
    else if (IR_State == 1) // 状态1，等待Start信号或Repeat信号
    {
        IR_Time = Timer0_GetCounter(); // 获取上一次中断到此次中断的时间
        Timer0_SetCounter(0);
        // 如果计时为13.5ms，则接收到了Start信号
        if (IR_Time > 12442 - 500 && IR_Time < 12442 + 500)
        {
            IR_State = 2;
        }
        // 如果计时为11.25ms，则接收到了Repeat信号
        else if (IR_Time > 10368 - 500 && IR_Time < 10368 + 500)
        {
            IR_RepeatFlag = 1;
            Timer0_Run(0);
            IR_State = 0;
        }
        else
        {
            IR_State = 1;
        }
    }
    else if (IR_State == 2) // 接收状态
    {
        IR_Time = Timer0_GetCounter(); // 获取上一次中断到此次中断的时间
        Timer0_SetCounter(0);
        // 如果计时为1120us，则接收到了数据0
        if (IR_Time > 1032 - 500 && IR_Time < 1032 + 500)
        {
            IR_Data[IR_pData / 8] &= charXor(0x01 << (IR_pData % 8)); // 数据对应位清0
            IR_pData++;                                               // 数据位置指针自增
        }
        // 如果计时为2250us，则接收到了数据1
        else if (IR_Time > 2074 - 500 && IR_Time < 2074 + 500)
        {
            IR_Data[IR_pData / 8] |= (0x01 << (IR_pData % 8)); // 数据对应位置1
            IR_pData++;                                        // 数据位置指针自增
        }
        else
        {
            IR_pData = 0; // 数据位置指针清0
            IR_State = 1; // 置状态为1
        }
        // 如果接收到了32位数据
        if (IR_pData >= 32)
        {
            IR_pData = 0;                                                                   // 数据位置指针清0
            if ((IR_Data[0] == charXor(IR_Data[1])) && (IR_Data[2] == charXor(IR_Data[3]))) // 数据验证
            {
                IR_Address = IR_Data[0]; // 转存数据
                IR_Command = IR_Data[2];
                IR_DataFlag = 1; // 置收到连发帧标志位为1
            }
            Timer0_Run(0); // 定时器停止
            IR_State = 0;  // 置状态为0
        }
    }
}