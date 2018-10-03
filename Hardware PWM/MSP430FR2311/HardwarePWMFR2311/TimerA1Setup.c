#include <msp430.h>

int conversion();

void TimerA1Setup(){
  TB1CCTL0 = CCIE;                              // TA0CCR0 interrupt enabled
  TB1CCR0 = 6000;                      // Sets TA0CCR0 interrupt with parameter in Hz
  TB1CTL = TBSSEL_1 + MC_1;                     // ACLK, UP
}
