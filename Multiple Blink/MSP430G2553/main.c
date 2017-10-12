#include <msp430G2553.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  P1DIR |= (BIT0 | BIT6);           // Set P1.0 to output direction





  for (;;)
  {
    volatile unsigned int i;

    i = 50000;


    // Delay



    do (i--);
    while (i != 0);

    P1OUT ^=(BIT0 | BIT6);
   


  }
}


