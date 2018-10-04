#include <msp430.h>

#define LED0 BIT0
#define LED1 BIT0
#define LED_OUT P2OUT
#define BUTTON_OUT P1OUT
#define LED_DIR P2DIR
#define BUTTON_DIR P1DIR
#define PULL_UP P1REN
#define LED_SEL P2SEL0
#define LED_SEL2 P2SEL1
#define BUTTON BIT1
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void ButtonSetup(void)
{
    BUTTON_DIR &= ~(BUTTON);
    BUTTON_OUT |= BUTTON;                   // Set P1.1 as a high
    PULL_UP |= BUTTON;                      // Enable pull up resistor on P1.1
    BTN_INT_EN |=  BUTTON;                  // P1.1 (Switch2) interrupt enabled
    BTN_INT_EDGE |= BUTTON;                 // P1.1 set to high/low edge
    CLRFLG &= ~BUTTON;                      // P1.1 IFG (interrupt flag) cleared
}
