# Simple Blink
Implemented on the following processors:
1. MSP430G2553
2. MSP430F5529
3. MSP430FR2311
4. MSP430FR5994
5. MSP430FR6989

## Overall structure of code
The following image gives an idea of how the code is structured on each development Board
![alt text](https://i.imgur.com/QpQ45Cc.png "High-Level Overview of how the code is structured")

1. Stop WatchDog Timer
2. Initialise Registers
3. Delay
4. Flip the status of the LED
5. Repeat

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

