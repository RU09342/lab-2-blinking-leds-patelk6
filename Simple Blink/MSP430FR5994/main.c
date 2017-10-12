#include <msp430FR5994.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

       P1OUT &= ~BIT0;                         // Initialise LED1 to off
       P1DIR |= BIT0;                          // Set P1.0 to output direction


       PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings

       while(1)
       {
           P1OUT ^= BIT0;                      // Flip status of LED (on -> off)
           __delay_cycles(100000);             // Delay for 1000000 clock cycles

       }
   }




