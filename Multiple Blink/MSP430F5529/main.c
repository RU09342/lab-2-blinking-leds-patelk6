#include <msp430F5529.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction

     

       P4OUT &= ~BIT7;
       P4DIR |= BIT7;


       for(;;){
   
           __delay_cycles(100000);             // Delay for 100000*(1/MCLK)=0.1s
           P1OUT ^= BIT0;
           P4OUT ^= BIT7;

       }
   }




