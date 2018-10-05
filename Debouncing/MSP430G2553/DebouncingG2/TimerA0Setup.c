#include <msp430.h>

void TimerA0Setup(){
  TA0CCTL0 = CCIE;                      // TA0CCR0 interrupt enabled
  TA0CCR0 = 2200;                      // Sets TA0CCR0 interrupt to value
  TA0CTL = TASSEL_1 + MC_1;             // ACLK, UP
}
