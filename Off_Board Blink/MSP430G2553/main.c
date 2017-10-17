#include <msp430G2553.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  P1DIR |= (BIT0);           // Set P1.0 to output direction
  for (;;)
  {
    volatile unsigned int i;
	//Set i to 50000 (to be used for the delay)
    i = 50000;
	//do while loop, will decrement while i is not equal to 0
    do (i--);
    while (i != 0);
	//Once it is done decrementing (we flip the value of the LED (on -> off, and vice versa)
    P1OUT ^=(BIT0);


  }
}


