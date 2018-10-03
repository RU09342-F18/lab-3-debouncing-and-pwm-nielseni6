#include <msp430.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define BUTTON BIT3
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

int conversion();

void TimerA1Setup(){
  TA1CCTL0 = CCIE;                              // TA0CCR0 interrupt enabled
  TA1CCR0 = conversion(3);                      // Sets TA0CCR0 interrupt with parameter in Hz
  TA1CTL = TASSEL_1 + MC_1;                     // ACLK, UP
}
