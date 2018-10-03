#include <msp430.h>
/*
 * DutyCycleSetup.c
 *
 *  Created on: Oct 2, 2018
 *      Author: ianni
 */

void DutyCycleSetup(void){

    TB1CCR0 = 1000;                         // PWM Period
    TB1CCTL1 = OUTMOD_7;                    // CCR1 reset/set
    TB1CCR1 = 0;                            // CCR1 PWM duty cycle
    TB1CTL = TBSSEL_2 + MC_1;               // SMCLK, up mode

}


