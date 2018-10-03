#include <msp430.h>

#define LED0 BIT0
#define LED1 BIT0
#define LED_OUT P2OUT
#define LED_DIR P2DIR
#define PULL_UP P2REN
#define LED_SEL P2SEL0
#define LED_SEL2 P2SEL1
#define BUTTON BIT1
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void ButtonSetup();
void LEDsetup();
void TimerA0Setup();
void DutyCycleSetup();

volatile unsigned int i;

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WatchDogTimer
  PM5CTL0 &= ~LOCKLPM5;
  ButtonSetup();
  LEDsetup();
  TimerA0Setup();
  DutyCycleSetup();

  __enable_interrupt();                     // enable interrupts
}
#pragma vector=PORT1_VECTOR                 // Interrupt when button is pressed and released
__interrupt void Port_1(void)
{
    TB0CTL = TBSSEL_1 | MC_1;               // AClock, Up mode
    BTN_INT_EN &= ~BUTTON;                          //Disables interrupt on P1.3
    CLRFLG &= ~BUTTON;                         // clears interrupt flag on P1.3
    TB1CCR1 = TB1CCR1 + 100;
    if (TB1CCR1 > 1000) TB1CCR1 = 0;
}
#pragma vector=TIMER0_B0_VECTOR             // Interrupt when Timer hits TA0CCR0
__interrupt void Timer_B(void)
{
    P1IFG &= ~BIT1; //Disables interrupt flag
    BTN_INT_EN |=  BUTTON;                          // P1.3 (Switch2) interrupt enabled
    TB0CTL = 0x0000;                        // Disable Clock and Reset

}
