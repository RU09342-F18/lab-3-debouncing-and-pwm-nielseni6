#include <msp430.h>

void TimerB0Setup(){
    TB0CCTL0 = CCIE;                            // TA0CCR0 interrupt enabled
    TB0CCR0 = 6000;                             // Sets TA0CCR0 interrupt with parameter in Hz
    TB0CTL = TBSSEL_1 + MC_1;                   // ACLK, UP
}
