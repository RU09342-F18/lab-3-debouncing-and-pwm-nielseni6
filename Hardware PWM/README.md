# Hardware PWM

## Boards Used

- MSP430G2553
- MSP430FR2311

## Functionality

An indicator LED turns on for a short amount of timer when button is pressed and the duty cycle of the right LED is increased by 10%. When the program starts the LED is at 0% brightness and when the button is press the LED brightness increases 10%. Once the LED gets to 100% brightness it returns to 0%. The button doesn't bounce on button press or button release.

## Explination

This program uses Timer1 as an interrupt and Timer0 as the PWM timer. The first thing this program does is set up LEDs, buttons and timers. When the button is pressed the indicator LED is turned on for a short amount of time, the PWM timer CCR1 is increased by 10%, the button interrupt is disabled, Timer0 is started and the button flag is cleared. If the PWM timer CCR1 is at 100%, the register is set to zero. The program is now waiting for the Timer0 to hit CCR0, at which point the button interrupt is enabled again and the clock is reset and disabled. The effect of this is that the LED is on until CCR1 is hit every timer cycle.

## Difference Between Boards

There are two difference in the code for these two boards. The first is the pins used for the button and the pins used for the LED, which can be found in the define statements at the top of the code, and the second is that TimerB is used for the MSP430FR2311 and TimerA is used for MSP430G2553.
