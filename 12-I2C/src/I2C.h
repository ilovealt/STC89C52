/**
 * I2C总线驱动
 * 1.数据和时钟都为高，总线空闲
 * 2.每一个时钟脉冲，发送一位数据
 * 3.SCL为高时，SDA必须保持稳定，否则为起始或停止条件
 * 4.如果使用高频率的时钟芯片，需要加上适当的延时
 */
#ifndef __I2C_H__
#define __I2C_H__

/**
 * @brief I2C_Init 初始化I2C总线
 */
void I2C_Start(void);
/**
 * @brief I2C_Stop 停止I2C总线
 */
void I2C_Stop(void);
/**
 * @brief I2C_SendByte 发送一个字节
 * @param dat 要发送的字节
 */
void I2C_SendByte(unsigned char dat);
/**
 * @brief I2C_ReadByte 读取一个字节
 * @return 读取到的字节
 */
unsigned char I2C_ReadByte(void);
/**
 * @brief I2C_Ack 发送应答信号
 * @param ack 0: 不应答 1: 应答
 */
void I2C_SendAck(unsigned char ack);
/**
 * @brief I2C_ReadAck 读取应答信号
 * @return 0: 不应答 1: 应答
 */
unsigned char I2C_ReadAck(void);

#endif // __I2C_H__