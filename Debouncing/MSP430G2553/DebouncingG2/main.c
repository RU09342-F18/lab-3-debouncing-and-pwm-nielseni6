#include <msp430.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define BUTTON BIT3
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void LEDsetup();
void ButtonSetup();
void TimerA0Setup();

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer
    LEDsetup();                             // Sets up LED output
    ButtonSetup();                          // Sets up button input & interrupts
    TimerA0Setup();                         // Sets up TimerA0 & interrupts

  __enable_interrupt();                     // Enable the interrupt to be used
  while(1);
}
#pragma vector=PORT1_VECTOR                 // Interrupt when button is pressed and released
__interrupt void Port_1(void)
{
    TA0CTL = TASSEL_1 | MC_1;               // AClock, Up mode
    BTN_INT_EN &= ~BUTTON;                  // Disables interrupt on P1.3
    CLRFLG &= ~BUTTON;                      // Disables interrupt flag
    LED_OUT ^= LED0;                        // P1.0 green LED toggle
}

#pragma vector=TIMER0_A0_VECTOR             // Interrupt when Timer hits TA0CCR0
__interrupt void Timer_A(void)
{
    BTN_INT_EN |=  BUTTON;                  // P1.3 (Switch2) interrupt enabled
    TA0CTL = 0x0000;                        // Disable Clock and Reset

}


