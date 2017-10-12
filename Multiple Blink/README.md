# Multiple Blink
Implemented on the following processors:
1. MSP430G2553
2. MSP430F5529
3. MSP430FR2311
4. MSP430FR5994
5. MSP430FR6989

## Key Notes:
Note, the that is used to implement this function is nearly identical to the code that is used to implement simple blink,
with the only difference being that we are blinking 2 LED's as opposed to 1, which is mindnumbingly simple once
you are able to blink a single LED. As a result, this README is nearly identical to the one that is present for Simple Blink.

## Overall structure of code
The following image gives an idea of how the code is structured on each development Board
![alt text](https://i.imgur.com/QpQ45Cc.png "High-Level Overview of how the code is structured")

1. Stop WatchDog Timer
2. Initialise Registers (2 LEDs) 
3. Flip the status of LED1
4. Delay
5. Flip the status of LED2
6. Repeat

### Required Materials
In order to implement each of these pieces of software, you will require 3 things:

1. Physical MicroController with appropriate USB connector cable, or some equivalent emulator software
2. Code Composer Studio(CCS), or program to flash code to the MCU.
3. Main.c file for corresponding processor
4. Header file for corresponding processor (CCS has them built in, or they can be found online) 

### Implementing this code on your Processor
Each of the main.c files found in the folders can be implemented directly on the processors denoted by the folder name.
The main differences lie in the specific processor dependent implementations. Each processor has its own pre-defined
registers, which would need to be changed based on the specific processor used. For example, Pin 1.0 is the red LED on the MSP430G2553,
while the same pin on the MSP430F5529 is not even accessible.

### Key differences
We have 5 different implementations of the same code, for 5 different processors. The code for all 5 is nearly identical,
and for some processors, is even 100% identical. However, one important aspect to understand is that the 2311, 5994, and 
6989 processors all require an additional piece of code in order to function, else nothing will happen. For these boards,
we need to disable the pin high-impedance mode, which is enabled by default in these boards. This high-impedance mode
essentially forces all registers regarding pins to be set to their default values, and blocks the ability to change the pins.
As a result, we need to run the line, PM5CTL0 &= ~LOCKLPM5 in order to actually implement our code.


