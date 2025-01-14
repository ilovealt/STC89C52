#include <8052.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNumber;
void main()
{
    LCD_Init();
    LCD_ShowChar(1, 1, 'H');

    while (1)
    {
        KeyNumber = MatrixKey();
        if (KeyNumber)
        {
            LCD_ShowNum(2, 1, KeyNumber, 2);
        }
    }
}