
unsigned char RotateLeft(unsigned char value, unsigned char shift_count)
{
    unsigned char i;
    for (i = 0; i < shift_count; i++)
    {
        // 保存最高位
        unsigned char msb = value & 0x80;
        value <<= 1;
        if (msb)
            value |= 0x01;
    }
    return value;
}

unsigned char RotateRight(unsigned char value, unsigned char shift_count)
{
    unsigned char i;
    for (i = 0; i < shift_count; i++)
    {
        // 保存最低位
        unsigned char lsb = value & 0x01;
        value >>= 1;
        if (lsb)
            value |= 0x80;
    }
    return value;
}