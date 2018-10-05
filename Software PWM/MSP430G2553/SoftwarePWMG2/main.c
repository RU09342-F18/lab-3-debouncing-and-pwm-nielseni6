#include <msp430.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define PULL_UP P1REN
#define LED_SEL P1SEL
#define LED_SEL2 P1SEL2
#define BUTTON BIT3
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void ButtonSetup();
void LEDsetup();
void TimerA0Setup();
void TimerA1Setup();

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WatchDogTimer
  BCSCTL3 = LFXT1S_2;                       // Makes ACKL use internal oscillator
  ButtonSetup();                            // Setup buttons
  LEDsetup();                               // Setup LEDs
  TimerA0Setup();                           // Setup TimerA0
  TimerA1Setup();                           // Setup TimerA1

  __enable_interrupt();                     // enable interrupts
  while(1);
}
#pragma vector=PORT1_VECTOR                 // Interrupt when button is pressed and released
__interrupt void Port_1(void)
{
    TA1CTL = TASSEL_1 | MC_1;               // AClock, Up mode
    BTN_INT_EN &= ~BUTTON;                  // Disables interrupt on P1.3
    CLRFLG &= ~BUTTON;                      // clears interrupt flag on P1.3
    LED_OUT |= LED0;                        // LED0 on
    TA0CCR1 = TA0CCR1 + 100;                // Increase duty cycle by 10%
    if (TA0CCR1 >= 1000) TA0CCR1 = 0;       // Set duty cycle back to 0% if its greater than 100%
}
#pragma vector=TIMER1_A0_VECTOR             // Interrupt when Timer hits TA0CCR0
__interrupt void Timer1_A0(void)
{
    BTN_INT_EN |=  BUTTON;                  // P1.3 (Switch2) interrupt enabled
    LED_OUT &= ~LED0;                       // Disable LED0
    TA1CTL = 0x0000;                        // Disable Clock and Reset
    CLRFLG &= ~BUTTON;                      // Disables interrupt flag
}
#pragma vector = TIMER0_A1_VECTOR           // Disables LED once time has reached duty cycle
__interrupt void Timer0_A1 (void)
{
    LED_OUT &= ~(LED1);                     // turns off red led
    TA0CCTL1 &= ~LED0;                      // clears flag
}
#pragma vector = TIMER0_A0_VECTOR           //enables LED at end of the cycle
__interrupt void Timer0_A0 (void)
{
    if(TA0CCR1 != 0)LED_OUT |= (LED1);      //turns on red LED
    TA0CCTL0 &= ~LED0;                      //clears flag
}
