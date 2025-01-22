#include <8052.h>
#include "Delay.h"
#include "LCD1602.h"
#include "Time0.h"
#include "IR.h"

unsigned char Address;
unsigned char Command;

int main(void)
{
    LCD_Init();
    LCD_ShowString(1, 1, "Add");
    LCD_ShowString(1, 5, "Com");

    IR_Init();

    while (1)
    {
        if (IR_GetDataFlag())
        {
            Address = IR_GetAddress();
            Command = IR_GetCommand();

            LCD_ShowHexNum(2, 1, Address, 2);
            LCD_ShowHexNum(2, 5, Command, 2);
        }
    }
}
