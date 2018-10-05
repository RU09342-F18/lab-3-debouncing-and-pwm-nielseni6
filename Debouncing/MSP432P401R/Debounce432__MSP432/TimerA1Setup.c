#include <msp432.h>

void TimerA1Setup(){
  TA1CCTL0 = CCIE;                              // TA0CCR0 interrupt enabled
  TA1CCR0 = 1000;                      // Sets TA0CCR0 interrupt with parameter in Hz
  TA1CTL = TASSEL_1 + MC_1;                     // ACLK, UP
}
