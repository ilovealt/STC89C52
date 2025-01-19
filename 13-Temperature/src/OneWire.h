#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

/**
 * @brief Initialize the OneWire bus, 1070us delay
 * @param  无
 * @return ack_bit 0: initialization succeeded, 1: initialization failed
 */
unsigned char OneWire_Init(void);

/**
 * @brief Send a bit to the OneWire bus, 60us delay
 * @param  bit The bit to be sent
 * @return 无
 */
void OneWire_SendBit(unsigned char bit);

/**
 * @brief Receive a bit from the OneWire bus, 60us delay
 * @param  无
 * @return bit The bit received
 */
unsigned char Onewire_ReceiveBit(void);

/**
 * @brief Send a byte to the OneWire bus
 * @param  byte The byte to be sent
 * @return 无
 */
void OneWire_SendByte(unsigned char byte);

/**
 * @brief Receive a byte from the OneWire bus
 * @param  无
 * @return byte The byte received
 */
unsigned char OneWire_ReceiveByte(void);

#endif // __ONEWIRE_H__