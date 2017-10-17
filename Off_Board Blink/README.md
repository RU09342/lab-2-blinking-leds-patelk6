# Off-Board Blink
 Next, the MSP430G2553 is removed from its rightful place on the development board, and placed onto a breadboard. From here,
 we run a simple blink program (found in the Simple Blink/MSP430G2553 directory). We are able to make the external LED blink.
 To accomplish this, we used CCS to program the chip while it was in the development board. We then removed the chip,
 and attached it to a breadboard, and attached a wire to VCC, Ground, and the pin that was being manipulated.
 
 ## Off-Board programming
 One idea discovered is that it is possible to program the chip, even when it is not on th development board. To do so, we flash
 a program to the board, using any sort of program flasher. TI supports one called MSP430 Flasher. We connect wires to the 
 chip on the breadboard in order to flash the program. Then we are able to blink the LED.

