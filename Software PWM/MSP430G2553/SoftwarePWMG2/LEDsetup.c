#include <msp430.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define PULL_UP P1REN
#define LED_SEL P1SEL
#define LED_SEL2 P1SEL2
#define BUTTON BIT3
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void LEDsetup(void)
{
    P1DIR |= BIT6 + BIT0; //Set pin 1.6  and 1.0 to the output direction.
    //LED_SEL |= LED1 + LED0;                            // P1.6 for TA0.1 output
    //LED_SEL2 &= ~(LED1 + LED0);                          // Select default function for P1.6
}
