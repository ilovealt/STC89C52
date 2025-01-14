#ifndef __AT24C02_H__
#define __AT24C02_H__

/**
 * @brief AT24C02_Write 向I2C设备写入一个字节
 * @param addr 设备地址
 * @param dat 要写入的字节
 */
void AT24C02_Write(unsigned char addr, unsigned char dat);
/**
 * @brief AT24C02_Read 从I2C设备读取一个字节
 * @param addr 设备地址
 * @return unsigned char 读取到的字节
 */
unsigned char AT24C02_Read(unsigned char addr);

#endif // __AT24C02_H__