#include <8052.h>

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 125; j++);
    }
}

int main() {
    /*
    灯光闪烁
    while (1) {
        P2 = 0xFE;
        delay_ms(500);
        P2 = 0xFF;
        delay_ms(500);
    }
    */

    /*
    跑马灯
    */
    while (1) {
        P2 = 0xFE;
        delay_ms(500);
        P2 = 0xFD;
        delay_ms(500);
        P2 = 0xFB;
        delay_ms(500);
        P2 = 0xF7;
        delay_ms(500);
        P2 = 0xEF;
        delay_ms(500);
        P2 = 0xDF;
        delay_ms(500);
        P2 = 0xBF;
        delay_ms(500);
        P2 = 0x7F;
        delay_ms(500);
    }

    return 0;
}