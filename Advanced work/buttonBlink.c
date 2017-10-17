#include <msp430G2553.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  P1DIR |= (BIT0 + BIT6);           // Set P1.0 to output direction

  P1DIR &= ~BIT3;               // button is an input
  P1OUT |= BIT3;                // pull-up resistor
  P1REN |= BIT3;                // resistor enabled



  for (;;)
  {
    // Delay
    while ((P1IN & BIT3) != BIT3) {

		P1OUT |= BIT6;			//Enable Green LED
        P1OUT &= ~BIT0;         //Disable Red LED
    }
	P1OUT &=~BIT6;				//Disable Green LED
    P1OUT |= BIT0;				//Enable Red LED


  }
}


