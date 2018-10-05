#include <msp432.h>

void TimerA0Setup(){
  TA0CCTL0 = CCIE;                      // TA0CCR0 interrupt enabled
}
