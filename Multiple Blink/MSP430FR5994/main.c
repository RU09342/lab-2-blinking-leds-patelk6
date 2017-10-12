#include <msp430FR5994.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction

       P1OUT &= ~BIT1;			      // Initialise LED2 to off	
       P1DIR |= BIT1;			      //Set LED2 as an output

       PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings

       while(1)
       {
           P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
           __delay_cycles(100000);             // Delay for 100000 clock cycles
           P1OUT ^= BIT1;
       }
   }




