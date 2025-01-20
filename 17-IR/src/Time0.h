#ifndef __TIME0_H__
#define __TIME0_H__

void Timer0_Init(void);
void Timer0_Run(unsigned char Flag);
void Timer0_SetCounter(unsigned int Value);
unsigned int Timer0_GetCounter(void);

#endif