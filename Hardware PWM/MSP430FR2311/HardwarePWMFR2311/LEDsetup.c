#include <msp430.h>

#define LED0 BIT0
#define LED1 BIT0
#define LED_OUT P2OUT
#define LED_DIR P2DIR
#define PULL_UP P2REN
#define LED_SEL P2SEL0
#define LED_SEL2 P2SEL1
#define BUTTON BIT1
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void LEDsetup(void)
{
    LED_DIR |= LED1;                            // P1.6 output
    LED_SEL |= LED1;                            // P1.6 for TA0.1 output
    LED_SEL2 &= ~LED1;                          // Select default function for P1.6
}
