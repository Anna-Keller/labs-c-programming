#include <msp430fr6989.h>
#include "led.h"

void LED_Init(void)
{
    //LED1 is connected to P1.0
    //LED2 is connected to P1.6

    P1SEL0 &= ~(BIT0 + BIT6);
    P1SEL1 &= ~(BIT0 + BIT6);

    P1DIR |= BIT0 + BIT6;
}

void LED1_on(void)
{
    P1OUT |= BIT0;
}

void LED2_on(void)
{
    P1OUT |= BIT6;
}

void LED1_off(void)
{
    P1OUT &= ~BIT0;
}

void LED2_off(void)
{
    P1OUT &= ~BIT6;
}


