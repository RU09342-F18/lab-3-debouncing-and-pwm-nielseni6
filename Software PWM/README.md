# Software PWM

## Boards Used

- MSP430G2553
- MSP430F5529

## Functionality

An indicator LED turns on for a short amount of timer when button is pressed and the duty cycle of the right LED is increased by 10%. When the program starts the LED is at 0% brightness and when the button is press the LED brightness increases 10%. Once the LED gets to 100% brightness it returns to 0%. The button doesn't bounce on button press or button release.

## Explination

This program uses Timer1 as an interrupt and Timer0 as the PWM timer. The first thing this program does is set up LEDs, buttons and timers.
```c
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WatchDogTimer
  BCSCTL3 = LFXT1S_2;                       // Makes ACKL use internal oscillator
  ButtonSetup();                            // Setup buttons
  LEDsetup();                               // Setup LEDs
  TimerA1Setup();                           // Setup TimerA1
  DutyCycleSetup();                         // Setup DutyCycle with TimerA0

  TA1CCTL0 = CCIE;
  __enable_interrupt();                     // enable interrupts
  while(1);
}
```
When the button is pressed the indicator LED is turned on for a short amount of time, the PWM timer CCR1 is increased by 10%, the button interrupt is disabled, Timer0 is started and the button flag is cleared. If the PWM timer CCR1 is at 100%, the register is set to zero. The program is now waiting for the Timer0 to hit CCR0, at which point the button interrupt is enabled again and the clock is reset and disabled.
```c
#pragma vector=PORT1_VECTOR                 // Interrupt when button is pressed and released
__interrupt void Port_1(void)
{
    TA1CTL = TASSEL_1 | MC_1;               // AClock, Up mode
    BTN_INT_EN &= ~BUTTON;                  // Disables interrupt on P1.3
    CLRFLG &= ~BUTTON;                      // clears interrupt flag on P1.3

    TA0CCR1 = TA0CCR1 + 100;                // Increase duty cycle by 10%
    if (TA0CCR1 > 1000) TA0CCR1 = 0;        // Set duty cycle back to 0% if its greater than 100%

    LED_OUT |= LED0;
}
#pragma vector=TIMER1_A0_VECTOR             // Interrupt when Timer hits TA0CCR0
__interrupt void Timer_A(void)
{
    BTN_INT_EN |=  BUTTON;                  // P1.3 (Switch2) interrupt enabled
    TA1CTL = 0x0000;                        // Disable Clock and Reset

    LED_OUT &= ~LED0;
}
```
