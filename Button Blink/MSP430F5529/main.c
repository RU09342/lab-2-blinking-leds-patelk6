#include <msp430F5529.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction
		
	   //Initialise button, and set its pull up resistor
       P1DIR &= ~BIT1;						
       P1OUT |= BIT1;
       P1REN |= BIT1;
	   //LED 4.7
       P4OUT &= ~BIT7;
       P4DIR |= BIT7;


       for(;;){
       while((P1IN & BIT1) != BIT1)
       {
           P1OUT &= ~BIT0;                      
           P4OUT &=~BIT7;          
     
       }
       P1OUT |= BIT0;
       P4OUT |= BIT7;
       }
   }




