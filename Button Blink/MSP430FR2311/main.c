#include <msp430FR2311.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction



       PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings
	   //Set Pin 1.1 as an input
       P1DIR &= ~BIT1;
	   //Initialise the button to high
       P1OUT |= BIT1;
	   //Enable pull up resistor for button
       P1REN |= BIT1;
       for(;;){
	   //While button is held, turn off LED, else keep it on
       while ((P1IN & BIT1) != BIT1) {


               P1OUT &= ~BIT0;          // Disale RED LED

           }
           P1OUT |= BIT0;
       }

   }




