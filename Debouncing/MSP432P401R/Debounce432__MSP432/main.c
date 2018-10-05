#include <msp432.h>

#define LED0 BIT0
#define LED1 BIT6
#define LED_OUT P1OUT
#define LED_DIR P1DIR
#define BUTTON BIT1
#define BTN_INT_EN P1IE
#define BTN_INT_EDGE P1IES
#define CLRFLG P1IFG

void LEDsetup();
void ButtonSetup();
void TimerA0Setup();

int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    LEDsetup();                             // Sets up LED output
    ButtonSetup();                          // Sets up button input & interrupts
    TimerA0Setup();                         // Sets up TimerA0 & interrupts

    NVIC->ISER[1] = 1 << ((PORT1_IRQn) & 31);   // Interrupt enable P1
    NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);   // Interrupt enable TimerA0

    __enable_irq();                         // Enable the interrupt to be used
    while(1);
}
void PORT1_IRQHandler(void)                 // Button press interrupt
{
    TA0CTL = TASSEL_1 + MC_1;               // AClock, Up mode
    BTN_INT_EN &= ~BUTTON;                  // Disables interrupt on P1.3
    CLRFLG &= ~BUTTON;                      // Disables interrupt flag
    LED_OUT ^= LED0;                        // P1.0 red LED toggle
    TA0CCR0 = 10000;                        // Sets TA0CCR0 interrupt to value
}
void TA0_0_IRQHandler(void)                 // Interrupt when Timer hits TA0CCR0
{
    TA0CTL = MC_0 + TACLR;                  // Disable Clock and Reset
    BTN_INT_EN |=  BUTTON;                  // P1.3 (Switch2) interrupt enabled
    CLRFLG &= ~BUTTON;                      // Clear interrupt flags on button
}


