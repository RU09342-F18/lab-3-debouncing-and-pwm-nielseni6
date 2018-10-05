# Software Debouncing

## Boards Used

- MSP430G2553
- MSP432P401R

## Functionality

LED toggles when button is pressed. The button doesn't bounce on button press or button release.

## Explination

This program uses Timer0 as an interrupt. The first thing this program does is set up LEDs, buttons and timers. When the button is pressed the LED is toggled, the button interrupt is disabled, Timer0 is started and the button flag is cleared. The program is now waiting for the Timer0 to hit CCR0, at which point the button interrupt is enabled again and the clock is reset and disabled. The effect of this is that the button will not be detected within a short amount of time after it is pressed.
