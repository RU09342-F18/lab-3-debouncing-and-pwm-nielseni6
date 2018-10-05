#include <msp432.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define BUTTON BIT1
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void DutyCyleSetup(void){
    TA0CCR0 = 512-1;                             // PWM Period
    TA0CCTL1 = OUTMOD_7;                         // CCR1 reset/set
    TA0CCR1 = 0;                                 // CCR1 PWM duty cycle
    TA0CTL = TASSEL_2 + MC_1 + ID_1;           // SMCLK, up mode
}
