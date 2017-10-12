#include <msp430FR5994.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction

       //Enable Pin 5.6 as an input
       P5DIR &= ~BIT6;
       //Initialise the button to high
       P5OUT |= BIT6;
       //Enable Pull up resistor for Pin 5.6
       P5REN |= BIT6;

       PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings
       for(;;){
           //While the button is held, turn off the LED
       while((P5IN & BIT6) != BIT6)
       {
           P1OUT &= ~BIT0;                      // Flip status of LED

       }
       //When the button is not held, keep it on
       P1OUT |= BIT0;
       }
   }




