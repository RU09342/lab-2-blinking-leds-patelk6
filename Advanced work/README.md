# Advanced Work Lab 1

## Button Blink
Essentially what I did here was use the button to toggle which color LED was lit up.
This was a relatively straightforward task, as I was able to just check whenever the button was pressed down.
Thus, whenever the button is held down, the green LED will light up, else the red LED will be forever lit.
There were no issues encountered, with the exception of the button debounce. This is combatted slightly by the fact
that I am checking for the button being held down.
### Implementation
Implementing this code is as simple as any other of my main.c files. You simply put this file into your project, and
ensure that the MSP430G2553 is the processor that is selected.

## Multiple Blink
This was also fairly straightforward. Doing these labs, it became obvious how I could access the various LED's. An interesting
development came when I attempted to use the GPIO pins to output to an external set of LED's, which I was ultimately 
able to do. Each of these LED's will blink at the same rate, as they are set at the same time, after an arbitrary delay.
### Implementation
Implementing this code is still simple, but will require additional materials. You will need 3 LED's, 3 resistors, and
enough breadboard jumper cables to connect all of them. We simply attach female cables to the headers on the 
development board(in this case, the FR5994) and then connect ground to the GND header on the board. This will produce
the desired effect.