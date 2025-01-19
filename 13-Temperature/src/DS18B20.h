#ifndef __DS18B20_H__
#define __DS18B20_H__

/**
 * @brief Convert temperature
 * @param None
 * @retval None
 */
void DS18B20_CovertT(void);

/**
 * @brief Read temperature
 * @param None
 * @retval Temperature
 */
float DS18B20_ReadT(void);

#endif // __DS18B20_H__