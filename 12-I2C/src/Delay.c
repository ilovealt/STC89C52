
void DelayMS(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 125; j++)
            ;
    }
}

void Delay10US(void)
{
    unsigned char i;
    // 这里的循环次数可能需要根据实际情况调整
    for (i = 0; i < 7; i++)
    {
        // 空操作指令
    }
}
