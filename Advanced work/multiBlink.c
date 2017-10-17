#include <msp430FR5994.h>
unsigned int totalBytes = 0;
unsigned int byteCount = 0;
int main(void)
{
    P3SEL0 |= BIT4 + BIT5 +BIT6;
    P3DIR|= BIT4 + BIT5 +BIT6;

    WDTCTL = WDTPW | WDTHOLD;               // Stop Watchdog

	while(1){
		P3OUT ^= (BIT4 + BIT5 +BIT6);			//Blink LED 3.4, 3.5, 3.6 (From GPIO)
	}

	

    
}



