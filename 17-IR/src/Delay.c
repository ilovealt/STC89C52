
/**
 * @brief  延时函数，11.0592MHz调用可延时ms，5～20之间比较准确
 * @param  ms 要延时的毫秒数
 * @retval 无
 */
void Delayms(unsigned int ms)
{
    unsigned int k, i, j;
    for (k = 0; k < ms; k++)
    {
        i = 2;
        j = 102;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}
