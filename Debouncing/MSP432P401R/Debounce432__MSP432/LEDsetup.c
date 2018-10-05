#include <msp432.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define BUTTON BIT1
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void LEDsetup(void)
{
  LED_DIR |= LED0;                        // Set P1.0 to output
  LED_OUT &= ~LED0;                       // P1.0 green LED set to off
}
