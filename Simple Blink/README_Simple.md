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

### Implementing this code on your Processor
Each of the main.c files found in the folders can be implemented directly on the processors denoted by the folder name.
The main differences lie in the specific processor dependent implementations. Each processor has its own pre-defined
registers, which would need to be changed based on the specific processor used.