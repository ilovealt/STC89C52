
void Delayms(unsigned int ms)
{
    unsigned int i;
    for (i = 0; i < ms; i++)
    {
        Delay1ms();
    }
}

void Delay1ms(void)
{
    unsigned char i, j;

    i = 2;
    j = 199;
    do
    {
        while (--j)
            ;
    } while (--i);
}
