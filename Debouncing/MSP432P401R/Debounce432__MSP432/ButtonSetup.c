#include <msp432.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define BUTTON BIT1
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void ButtonSetup(void)
{
    P1DIR &= ~BIT1;                         // Set P1.1 (Button) to input direction
    P1REN |= BIT1;                          // Enable internal resistor
    P1OUT |= BIT1;                          // Set resistor to pull-up
    BTN_INT_EN |=  BUTTON;                  // P1.3 (Switch2) interrupt enabled
    BTN_INT_EDGE |= BUTTON;                 // P1.3 set to high/low edge
    CLRFLG &= ~BUTTON;                      // P1.3 IFG (interrupt flag) cleared
}
