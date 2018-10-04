#include <msp430.h>

void TimerA0Setup(){
  TA1CCTL0 = CCIE;                      // TA0CCR0 interrupt enabled
  TA1CCR0 = 18000;                      // Sets TA0CCR0 interrupt to value
  TA1CTL = TASSEL_1 + MC_1;             // ACLK, UP
}
