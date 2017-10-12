#include <msp430FR6989.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

       P1OUT &= ~BIT0;                         // Initialise LED1 to off
       P1DIR |= BIT0;                          //Set the direction of the LED1 to output



       PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings

       P1DIR &= ~BIT1;                         //Set the direction of Pin 1.1 (button) to input
       P1OUT |= BIT1;                          //Initialise the button to high (not pressed)
       P1REN |= BIT1;                          //Enable the pull up resistor for Pin 1.1
       for(;;){
       while ((P1IN & BIT1) != BIT1) {
           //While the Button is pressed, disable LED

               P1OUT &= ~BIT0;          // Disale RED LED

           }
       //When button is not pressed, just LED on
           P1OUT |= BIT0;
       }

   }




