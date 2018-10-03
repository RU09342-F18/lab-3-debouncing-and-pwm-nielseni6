#include <msp430.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define BUTTON BIT3
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void ButtonSetup(void)
{
    BTN_INT_EN |=  BUTTON;                  // P1._ (Switch2) interrupt enabled
    BTN_INT_EDGE |= BUTTON;                 // P1._ set to high/low edge
    CLRFLG &= ~BUTTON;                      // P1._ IFG (interrupt flag) cleared
}
