
void DelayMS(unsigned int ms)
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

void Delay10us(void)
{
    unsigned char i;

    i = 2;
    while (--i)
        ;
}

void Delay15us()
{
    unsigned char i;

    i = 4;
    while (--i)
        ;
}

void Delay70us(void)
{
    unsigned char i;

    i = 29;
    while (--i)
        ;
}

void Delay500us(void)
{
    unsigned char i;

    i = 227;
    while (--i)
        ;
}
