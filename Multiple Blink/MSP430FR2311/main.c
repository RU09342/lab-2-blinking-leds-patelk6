#include <msp430FR2311.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction
	   //Initialise LED2 to off
       P2OUT &= ~BIT0;
	   //Set LED2 as an output
       P2DIR |= BIT0;

       PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings

       while(1)
       {
           P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
           __delay_cycles(100000);             // Delay for 100000*(1/MCLK)=0.1s
           P2OUT ^= BIT0;
       }
   }




