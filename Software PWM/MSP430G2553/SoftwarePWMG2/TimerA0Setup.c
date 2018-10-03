#include <msp430.h>

void TimerA0Setup(){
    TA0CCTL1 = CCIE;                    //Enable interrupt in compare mode
    TA0CCTL0 = CCIE;                    //Enable interrupt in compare mode
    TA0CCR0 = 1000;                     //Set the period in the Timer A0 Capture/Compare 0 register to 1000 Microseconds.
    TA0CCR1 = 0;                      //The period in microseconds that the power is ON. It's half the time, which translates to a 50% duty cycle.
    TA0CTL = TASSEL_2 + MC_1;           //TASSEL_2 selects SMCLK as the clock source, and MC_1 tells it to count up to the value in TA0CCR0.
}
